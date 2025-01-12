// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ui/gl/init/gl_initializer.h"

#include "base/command_line.h"
#include "base/logging.h"
#include "base/path_service.h"
#include "base/threading/thread_restrictions.h"
#include "build/build_config.h"
#include "ui/gfx/switches.h"
#include "ui/gl/buildflags.h"
#include "ui/gl/gl_bindings.h"
#include "ui/gl/gl_egl_api_implementation.h"
#include "ui/gl/gl_gl_api_implementation.h"
#include "ui/gl/gl_surface_egl.h"
#include "ui/gl/gl_switches.h"

namespace gl {
namespace init {

namespace {

#if defined(OS_OPENBSD) || defined(OS_HAIKU)
const char kGLLibraryName[] = "libGL.so";
#else
const char kGLLibraryName[] = "libGL.so.1";
#endif

const char kGLESv2LibraryName[] = "libGLESv2.so.2";
const char kEGLLibraryName[] = "libEGL.so.1";

const char kGLESv2ANGLELibraryName[] = "libGLESv2.so";
const char kEGLANGLELibraryName[] = "libEGL.so";

#if BUILDFLAG(ENABLE_SWIFTSHADER)
const char kGLESv2SwiftShaderLibraryName[] = "libGLESv2.so";
const char kEGLSwiftShaderLibraryName[] = "libEGL.so";
#endif

bool InitializeStaticEGLInternal(GLImplementation implementation) {
  base::FilePath glesv2_path(kGLESv2LibraryName);
  base::FilePath egl_path(kEGLLibraryName);

  const base::CommandLine* cmd = base::CommandLine::ForCurrentProcess();

  if (implementation == kGLImplementationSwiftShaderGL) {
#if BUILDFLAG(ENABLE_SWIFTSHADER)
    base::FilePath module_path;
    if (!base::PathService::Get(base::DIR_MODULE, &module_path))
      return false;
    module_path = module_path.Append("swiftshader/");

    glesv2_path = module_path.Append(kGLESv2SwiftShaderLibraryName);
    egl_path = module_path.Append(kEGLSwiftShaderLibraryName);
#else
    return false;
#endif
  } else if (cmd->GetSwitchValueASCII(switches::kUseGL) ==
             kGLImplementationANGLEName) {
    base::FilePath module_path;
    if (!base::PathService::Get(base::DIR_MODULE, &module_path))
      return false;

    glesv2_path = module_path.Append(kGLESv2ANGLELibraryName);
    egl_path = module_path.Append(kEGLANGLELibraryName);
  }

  base::NativeLibrary gles_library = LoadLibraryAndPrintError(glesv2_path);
  if (!gles_library)
    return false;
  base::NativeLibrary egl_library = LoadLibraryAndPrintError(egl_path);
  if (!egl_library) {
    base::UnloadNativeLibrary(gles_library);
    return false;
  }

  GLGetProcAddressProc get_proc_address =
      reinterpret_cast<GLGetProcAddressProc>(
          base::GetFunctionPointerFromNativeLibrary(egl_library,
                                                    "eglGetProcAddress"));
  if (!get_proc_address) {
    LOG(ERROR) << "eglGetProcAddress not found.";
    base::UnloadNativeLibrary(egl_library);
    base::UnloadNativeLibrary(gles_library);
    return false;
  }

  SetGLGetProcAddressProc(get_proc_address);
  AddGLNativeLibrary(egl_library);
  AddGLNativeLibrary(gles_library);
  SetGLImplementation(kGLImplementationEGLGLES2);

  InitializeStaticGLBindingsGL();
  InitializeStaticGLBindingsEGL();

  return true;
}

}  // namespace

bool InitializeGLOneOffPlatform() {
  switch (GetGLImplementation()) {
    case kGLImplementationDesktopGL:
      return true;
    case kGLImplementationSwiftShaderGL:
    case kGLImplementationEGLGLES2:
      /*if (!GLSurfaceEGL::InitializeOneOff(gfx::GetXDisplay())) {
        LOG(ERROR) << "GLSurfaceEGL::InitializeOneOff failed.";
        return false;
      }*/
      return true;
    default:
      return true;
  }
}

bool InitializeStaticGLBindings(GLImplementation implementation) {
  // Prevent reinitialization with a different implementation. Once the gpu
  // unit tests have initialized with kGLImplementationMock, we don't want to
  // later switch to another GL implementation.
  DCHECK_EQ(kGLImplementationNone, GetGLImplementation());

  // Allow the main thread or another to initialize these bindings
  // after instituting restrictions on I/O. Going forward they will
  // likely be used in the browser process on most platforms. The
  // one-time initialization cost is small, between 2 and 5 ms.
  base::ThreadRestrictions::ScopedAllowIO allow_io;

  switch (implementation) {
    case kGLImplementationDesktopGL:
    case kGLImplementationSwiftShaderGL:
    case kGLImplementationEGLGLES2:
      return InitializeStaticEGLInternal(implementation);
    case kGLImplementationMockGL:
    case kGLImplementationStubGL:
      SetGLImplementation(implementation);
      InitializeStaticGLBindingsGL();
      return true;
    default:
      NOTREACHED();
  }

  return false;
}

void ShutdownGLPlatform() {
  GLSurfaceEGL::ShutdownOneOff();
  ClearBindingsEGL();
  ClearBindingsGL();
}

}  // namespace init
}  // namespace gl
