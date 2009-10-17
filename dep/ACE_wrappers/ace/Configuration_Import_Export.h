/* -*- C++ -*- */
//=============================================================================
/**
 * @file Configuration_Import_Export.h
 *
 *  $Id: Configuration_Import_Export.h 80826 2008-03-04 14:51:23Z wotte $
 *
 * @author Jerry D. Odenwelder Jr. <jerry.o@mindspring.com>
 *         Chris Hafey <chris@stentorsoft.com>
 *
 * Classes defined in this file provide the ability to import and export
 * ACE Configuration objects to/from disk files.  The base class
 * ACE_Config_ImpExp_Base provides the common functionality and the derived
 * classes implement the import/export functionality for the specific format.
 *
 * @todo
 *  - Add locking for thread safety.
 *  - Provide ability to read file in one format and write in another.
 *  - See todo's in each class
 */
//=============================================================================
#ifndef ACE_CONFIGURATION_IMPORT_EXPORT_H
#define ACE_CONFIGURATION_IMPORT_EXPORT_H
#include /**/ "ace/pre.h"
#include "ace/Configuration.h"
#include "ace/SString.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
/**
 * @class ACE_Config_ImpExp_Base
 *
 * @brief Base class for file import/export configuration.
 *
 * This class provides base functionality for configuration objects
 * that are persisted in files.  It takes an ACE_Configuration
 * object that it populates with the data read.
 *
 */
class ACE_Export ACE_Config_ImpExp_Base
{
public:
  /// Constructor taking the ACE_Configuration to import/export to
  ACE_Config_ImpExp_Base (ACE_Configuration& config);
  /**
   * Destructor
   */
  virtual ~ACE_Config_ImpExp_Base (void);
   /**
   * Imports the configuration database from @a filename.
   * No existing data is removed.
   */
  virtual int import_config (const ACE_TCHAR* filename) = 0;
  /**
   * This method exports the entire configuration database to @a filename.
   * Once the file is opened this method calls 'export_section' passing
   * the root section.
   */
  virtual int export_config (const ACE_TCHAR* filename) = 0;
protected:
  ACE_Configuration &config_;
private:
  ACE_Config_ImpExp_Base (const ACE_Config_ImpExp_Base&);
  ACE_Config_ImpExp_Base& operator= (const ACE_Config_ImpExp_Base&);
};
/**
 * @class ACE_Registry_ImpExp
 *
 * @brief Configuration object that imports/exports data to a file formatted
 *        using the Win32 Registry file export format.  This format looks like
 *        [Section]
 *        "key"="String Data"
 *        "key"=dword: numeric data in hexidecimal format
 *        "key"=hex: binary data
 *
 * @todo
 *  - Add dynamic buffer when importing.  currently it will not allow
 *    importing of values greater than a fixed ammount (4096 bytes)
 *
 */
class ACE_Export ACE_Registry_ImpExp : public ACE_Config_ImpExp_Base
{
public:
  /// Construction
  ACE_Registry_ImpExp (ACE_Configuration&);
  /// Destruction.
  virtual ~ACE_Registry_ImpExp (void);
  /**
   * Imports the configuration database from filename.
   * No existing data is removed.
   */
  virtual int import_config (const ACE_TCHAR* filename);
  /**
   * This method exports the entire configuration database to @a filename.
   * Once the file is opened this method calls export_section() passing
   * the root section.
   */
  virtual int export_config (const ACE_TCHAR* filename);
private:
  int export_section (const ACE_Configuration_Section_Key& section,
                      const ACE_TString& path,
                      FILE* out);
  int process_previous_line_format (ACE_TCHAR* buffer,
                                    ACE_Configuration_Section_Key& section);
  ACE_Registry_ImpExp ( const ACE_Registry_ImpExp&);
  ACE_Registry_ImpExp& operator= ( const ACE_Registry_ImpExp&);
};
/**
 * @class ACE_Ini_ImpExp
 *
 * @brief Imports the configuration database from filename as strings.
 *        Allows non-typed values. (no #, dword: hex:, etc. prefixes) and
 *        skips whitespace (tabs and spaces) as in standard .ini and .conf
 *        files. Values (to right of equal sign) can be double quote
 *        delimited to embed tabs and spaces in the string.
 *        Caller must convert string to type.
 *
 *        This method allows for lines in the .ini or .conf file like this:
 *
 *        TimeToLive     =    100
 *        Delay          =    FALSE
 *        Flags          =    FF34
 *        Heading        =    "ACE - Adaptive Communication Environment"
 *
 * (note leading whitespace (tabs) in examples below)
 *
 *        SeekIndex  =  14
 *        TraceLevel = 6      # Can comment lines like this
 *              Justification = left_justified
 *
 *        The caller can then retrieve the string with the regular
 *        <get_string_value> function and convert the string to the
 *        desired data type.
 *
 * @todo
 *  - Strings with embedded newlines cause the import to fail
 *  - Strings with embedded quotes " cause the import to fail
 *  - Importing/exporting for values in the root section does not work
 *  - Add dynamic buffer when importing.  currently it will not allow
 *    importing of values greater than a fixed ammount (4096 bytes)
*/
class ACE_Export ACE_Ini_ImpExp  : public ACE_Config_ImpExp_Base
{
public:
  /**
   * Construction
   */
  ACE_Ini_ImpExp (ACE_Configuration&);
  /**
   * Destructor
   */
  virtual ~ACE_Ini_ImpExp (void);
  /**
   * Imports the configuration database from filename.
   * No existing data is removed.
   */
  virtual int import_config (const ACE_TCHAR* filename);
  /**
   * This method exports the entire configuration database to @a filename.
   * Once the file is opened this method calls export_section() passing
   * the root section.
   */
  virtual int export_config (const ACE_TCHAR* filename);
private:
  /**
   * Method provided by derived classes in order to write one section
   * to the file specified.  Called by export_config() when exporting
   * the entire configuration object.
   */
  int export_section (const ACE_Configuration_Section_Key& section,
                      const ACE_TString& path,
                      FILE* out);
  /**
   * Method to squish leading and trailing whitespaces in a string.
   * Whitespace is defined as: spaces (' '), tabs ('\\t') or cr/lf.
   * Returns a pointer to the first non-whitespace character in the
   * buffer provided, or a pointer to the terminating null if the string
   * is all whitespace. The terminating null is moved forward to the
   * first character past the last non-whitespace.
   */
  ACE_TCHAR *squish (ACE_TCHAR *src);
  ACE_Ini_ImpExp (const ACE_Ini_ImpExp&);
  ACE_Ini_ImpExp& operator= (const ACE_Ini_ImpExp&);
};
ACE_END_VERSIONED_NAMESPACE_DECL
#include /**/ "ace/post.h"
#endif /* ACE_CONFIGURATION_IMPORT_EXPORT_H */

