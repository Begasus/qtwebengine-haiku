// GENERATED FILE - DO NOT EDIT.
// Generated by generate_entry_points.py using data from gl.xml.
//
// Copyright 2020 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// entry_points_gl_1_3_autogen.h:
//   Defines the GL 1.3 entry points.

#ifndef LIBGL_ENTRY_POINTS_GL_1_3_AUTOGEN_H_
#define LIBGL_ENTRY_POINTS_GL_1_3_AUTOGEN_H_

#include <export.h>
#include "angle_gl.h"

namespace gl
{
ANGLE_EXPORT void GL_APIENTRY ActiveTexture(GLenum texture);
ANGLE_EXPORT void GL_APIENTRY ClientActiveTexture(GLenum texture);
ANGLE_EXPORT void GL_APIENTRY CompressedTexImage1D(GLenum target,
                                                   GLint level,
                                                   GLenum internalformat,
                                                   GLsizei width,
                                                   GLint border,
                                                   GLsizei imageSize,
                                                   const void *data);
ANGLE_EXPORT void GL_APIENTRY CompressedTexImage2D(GLenum target,
                                                   GLint level,
                                                   GLenum internalformat,
                                                   GLsizei width,
                                                   GLsizei height,
                                                   GLint border,
                                                   GLsizei imageSize,
                                                   const void *data);
ANGLE_EXPORT void GL_APIENTRY CompressedTexImage3D(GLenum target,
                                                   GLint level,
                                                   GLenum internalformat,
                                                   GLsizei width,
                                                   GLsizei height,
                                                   GLsizei depth,
                                                   GLint border,
                                                   GLsizei imageSize,
                                                   const void *data);
ANGLE_EXPORT void GL_APIENTRY CompressedTexSubImage1D(GLenum target,
                                                      GLint level,
                                                      GLint xoffset,
                                                      GLsizei width,
                                                      GLenum format,
                                                      GLsizei imageSize,
                                                      const void *data);
ANGLE_EXPORT void GL_APIENTRY CompressedTexSubImage2D(GLenum target,
                                                      GLint level,
                                                      GLint xoffset,
                                                      GLint yoffset,
                                                      GLsizei width,
                                                      GLsizei height,
                                                      GLenum format,
                                                      GLsizei imageSize,
                                                      const void *data);
ANGLE_EXPORT void GL_APIENTRY CompressedTexSubImage3D(GLenum target,
                                                      GLint level,
                                                      GLint xoffset,
                                                      GLint yoffset,
                                                      GLint zoffset,
                                                      GLsizei width,
                                                      GLsizei height,
                                                      GLsizei depth,
                                                      GLenum format,
                                                      GLsizei imageSize,
                                                      const void *data);
ANGLE_EXPORT void GL_APIENTRY GetCompressedTexImage(GLenum target, GLint level, void *img);
ANGLE_EXPORT void GL_APIENTRY LoadTransposeMatrixd(const GLdouble *m);
ANGLE_EXPORT void GL_APIENTRY LoadTransposeMatrixf(const GLfloat *m);
ANGLE_EXPORT void GL_APIENTRY MultTransposeMatrixd(const GLdouble *m);
ANGLE_EXPORT void GL_APIENTRY MultTransposeMatrixf(const GLfloat *m);
ANGLE_EXPORT void GL_APIENTRY MultiTexCoord1d(GLenum target, GLdouble s);
ANGLE_EXPORT void GL_APIENTRY MultiTexCoord1dv(GLenum target, const GLdouble *v);
ANGLE_EXPORT void GL_APIENTRY MultiTexCoord1f(GLenum target, GLfloat s);
ANGLE_EXPORT void GL_APIENTRY MultiTexCoord1fv(GLenum target, const GLfloat *v);
ANGLE_EXPORT void GL_APIENTRY MultiTexCoord1i(GLenum target, GLint s);
ANGLE_EXPORT void GL_APIENTRY MultiTexCoord1iv(GLenum target, const GLint *v);
ANGLE_EXPORT void GL_APIENTRY MultiTexCoord1s(GLenum target, GLshort s);
ANGLE_EXPORT void GL_APIENTRY MultiTexCoord1sv(GLenum target, const GLshort *v);
ANGLE_EXPORT void GL_APIENTRY MultiTexCoord2d(GLenum target, GLdouble s, GLdouble t);
ANGLE_EXPORT void GL_APIENTRY MultiTexCoord2dv(GLenum target, const GLdouble *v);
ANGLE_EXPORT void GL_APIENTRY MultiTexCoord2f(GLenum target, GLfloat s, GLfloat t);
ANGLE_EXPORT void GL_APIENTRY MultiTexCoord2fv(GLenum target, const GLfloat *v);
ANGLE_EXPORT void GL_APIENTRY MultiTexCoord2i(GLenum target, GLint s, GLint t);
ANGLE_EXPORT void GL_APIENTRY MultiTexCoord2iv(GLenum target, const GLint *v);
ANGLE_EXPORT void GL_APIENTRY MultiTexCoord2s(GLenum target, GLshort s, GLshort t);
ANGLE_EXPORT void GL_APIENTRY MultiTexCoord2sv(GLenum target, const GLshort *v);
ANGLE_EXPORT void GL_APIENTRY MultiTexCoord3d(GLenum target, GLdouble s, GLdouble t, GLdouble r);
ANGLE_EXPORT void GL_APIENTRY MultiTexCoord3dv(GLenum target, const GLdouble *v);
ANGLE_EXPORT void GL_APIENTRY MultiTexCoord3f(GLenum target, GLfloat s, GLfloat t, GLfloat r);
ANGLE_EXPORT void GL_APIENTRY MultiTexCoord3fv(GLenum target, const GLfloat *v);
ANGLE_EXPORT void GL_APIENTRY MultiTexCoord3i(GLenum target, GLint s, GLint t, GLint r);
ANGLE_EXPORT void GL_APIENTRY MultiTexCoord3iv(GLenum target, const GLint *v);
ANGLE_EXPORT void GL_APIENTRY MultiTexCoord3s(GLenum target, GLshort s, GLshort t, GLshort r);
ANGLE_EXPORT void GL_APIENTRY MultiTexCoord3sv(GLenum target, const GLshort *v);
ANGLE_EXPORT void GL_APIENTRY
MultiTexCoord4d(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
ANGLE_EXPORT void GL_APIENTRY MultiTexCoord4dv(GLenum target, const GLdouble *v);
ANGLE_EXPORT void GL_APIENTRY
MultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
ANGLE_EXPORT void GL_APIENTRY MultiTexCoord4fv(GLenum target, const GLfloat *v);
ANGLE_EXPORT void GL_APIENTRY MultiTexCoord4i(GLenum target, GLint s, GLint t, GLint r, GLint q);
ANGLE_EXPORT void GL_APIENTRY MultiTexCoord4iv(GLenum target, const GLint *v);
ANGLE_EXPORT void GL_APIENTRY
MultiTexCoord4s(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
ANGLE_EXPORT void GL_APIENTRY MultiTexCoord4sv(GLenum target, const GLshort *v);
ANGLE_EXPORT void GL_APIENTRY SampleCoverage(GLfloat value, GLboolean invert);
}  // namespace gl

#endif  // LIBGL_ENTRY_POINTS_GL_1_3_AUTOGEN_H_