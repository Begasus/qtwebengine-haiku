// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file was generated by:
//   tools/json_schema_compiler/compiler.py.

/** @fileoverview Interface for languageSettingsPrivate that can be overriden. */

/** @interface */
function LanguageSettingsPrivate() {}

LanguageSettingsPrivate.prototype = {
  /**
   * Gets languages available for translate, spell checking, input and locale.
   * @param {function(!Array<!chrome.languageSettingsPrivate.Language>):void}
   *     callback
   */
  getLanguageList: function(callback) {},

  /**
   * Enables a language, adding it to the Accept-Language list (used to decide
   * which languages to translate, generate the Accept-Language header, etc.).
   * @param {string} languageCode
   */
  enableLanguage: function(languageCode) {},

  /**
   * Disables a language, removing it from the Accept-Language list.
   * @param {string} languageCode
   */
  disableLanguage: function(languageCode) {},

  /**
   * Enables or disables translation for a given language.
   * @param {string} languageCode
   * @param {boolean} enable
   */
  setEnableTranslationForLanguage: function(languageCode, enable) {},

  /**
   * Moves a language inside the language list.
   * @param {string} languageCode
   * @param {!chrome.languageSettingsPrivate.MoveType} moveType
   */
  moveLanguage: function(languageCode, moveType) {},

  /**
   * Gets the current status of the chosen spell check dictionaries.
   * @param {function(!Array<!chrome.languageSettingsPrivate.SpellcheckDictionaryStatus>):void}
   *     callback
   */
  getSpellcheckDictionaryStatuses: function(callback) {},

  /**
   * Gets the custom spell check words, in sorted order.
   * @param {function(!Array<string>):void} callback
   */
  getSpellcheckWords: function(callback) {},

  /**
   * Adds a word to the custom dictionary.
   * @param {string} word
   */
  addSpellcheckWord: function(word) {},

  /**
   * Removes a word from the custom dictionary.
   * @param {string} word
   */
  removeSpellcheckWord: function(word) {},

  /**
   * Gets the translate target language (in most cases, the display locale).
   * @param {function(string):void} callback
   */
  getTranslateTargetLanguage: function(callback) {},

  /**
   * Gets all supported input methods, including third-party IMEs. Chrome OS
   * only.
   * @param {function(!chrome.languageSettingsPrivate.InputMethodLists):void}
   *     callback
   */
  getInputMethodLists: function(callback) {},

  /**
   * Adds the input method to the current user's list of enabled input methods,
   * enabling the input method for the current user. Chrome OS only.
   * @param {string} inputMethodId
   */
  addInputMethod: function(inputMethodId) {},

  /**
   * Removes the input method from the current user's list of enabled input
   * methods, disabling the input method for the current user. Chrome OS only.
   * @param {string} inputMethodId
   */
  removeInputMethod: function(inputMethodId) {},

  /**
   * Tries to download the dictionary after a failed download.
   * @param {string} languageCode
   */
  retryDownloadDictionary: function(languageCode) {},
};

/**
 * Called when the pref for the dictionaries used for spell checking changes or
 * the status of one of the spell check dictionaries changes.
 * @type {!ChromeEvent}
 */
LanguageSettingsPrivate.prototype.onSpellcheckDictionariesChanged;

/**
 * Called when words are added to and/or removed from the custom spell check
 * dictionary.
 * @type {!ChromeEvent}
 */
LanguageSettingsPrivate.prototype.onCustomDictionaryChanged;

/**
 * Called when an input method is added.
 * @type {!ChromeEvent}
 */
LanguageSettingsPrivate.prototype.onInputMethodAdded;

/**
 * Called when an input method is removed.
 * @type {!ChromeEvent}
 */
LanguageSettingsPrivate.prototype.onInputMethodRemoved;