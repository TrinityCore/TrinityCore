// -*- C++ -*-

//=============================================================================
/**
 *  @file    CE_Screen_Output.h
 *
 *  $Id: CE_Screen_Output.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Si Mong Park  <spark@ociweb.com>
 */
//=============================================================================

#ifndef ACE_CE_SCREEN_OUTPUT_H
#define ACE_CE_SCREEN_OUTPUT_H

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_HAS_WINCE)

#include "ace/Log_Msg_Callback.h"
#include "ace/Log_Record.h"

namespace
{
  const ACE_TCHAR endl[] = ACE_TEXT("\r\n");
  const ACE_TCHAR tab[]  = ACE_TEXT("\t");
}

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_CE_Screen_Output
 *
 * @brief Replacement of text output for Windows CE.
 *
 * This class allows standard text output to be displayed on
 * text window for Windows CE.  Generally, all ACE output will
 * go through under CE if and only if user uses WindozeCE
 * implementation by using main_ce instead of main.
 * Also, for the easier debugging purpose, object pointer of
 * this class can be gotten from ACE_Log_Msg::msg_callback()
 * and then can be used directly by user just like cout stream.
 */
class ACE_Export ACE_CE_Screen_Output : public ACE_Log_Msg_Callback
{
public:

  ACE_CE_Screen_Output (HWND hEdit);

  ACE_CE_Screen_Output (void);

  virtual ~ACE_CE_Screen_Output();

  /// Implementation of pure virtual function from ACE_Log_Msg_Callback.
  virtual void log (ACE_Log_Record &log_record);

  /// Interface to specify active window handle.
  void SetOutputWindow (HWND hWnd);

  void clear (void);

  /// Stream insertion operator that performs actual print out.
  /**
   * @note This is the only one operator that performs output.  All
   *       other perators convert the type and use this operator
   *       underneath.
   */
  ACE_CE_Screen_Output& operator << (ACE_TCHAR*);
  ACE_CE_Screen_Output& operator << (const ACE_TCHAR*);

  ACE_CE_Screen_Output& operator << (ACE_ANTI_TCHAR* output);
  ACE_CE_Screen_Output& operator << (const ACE_ANTI_TCHAR* output);

  ACE_CE_Screen_Output& operator << (char output);
  ACE_CE_Screen_Output& operator << (unsigned char output);

  ACE_CE_Screen_Output& operator << (unsigned short output);

  ACE_CE_Screen_Output& operator << (int output);
  ACE_CE_Screen_Output& operator << (unsigned int output);

  ACE_CE_Screen_Output& operator << (float output);

  ACE_CE_Screen_Output& operator << (long output);
  ACE_CE_Screen_Output& operator << (unsigned long output);

  ACE_CE_Screen_Output& operator << (FILE* pFile);

private:

  ACE_CE_Screen_Output (ACE_CE_Screen_Output&);

private:

  HWND handler_;

  /// FILE pointer that used to save output to file.  This class does
  /// not own the file handler pointer.
  FILE* pFile_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#endif  // ACE_HAS_WINCE
#endif  // ACE_CE_SCREEN_OUTPUT_H
