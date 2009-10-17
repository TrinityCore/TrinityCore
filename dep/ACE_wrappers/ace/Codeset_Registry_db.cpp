/* $Id: Codeset_Registry_db.cpp 81756 2008-05-22 09:47:33Z johnnyw $
 * Codeset registry DB, generated Fri Feb 28 21:01:30 2003
 * source: code_set_registry1.2g.txt
 *
 * To populate the registry_db, construct a codeset registry text file based
 * on the OSF's Character and Code Set Registry. See DCE RFC 40.1 for details
 * on obtaining the full text for the current registry. Once you have composed
 * a text file containing all the desired codeset information, build and run
 * mkcsregdb. The source is in $ACE_ROOT/apps/mkcsregdb. It will generate a new
 * copy of this file, with the registry_db_ array properly initialized.
 */
#include "ace/Codeset_Registry.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_Codeset_Registry::registry_entry const
ACE_Codeset_Registry::registry_db_[] =
{
  {"ISO/IEC 10646-1:1993; UCS-2, Level 1","UCS-2",0x00010100,1,{0x1000},2},
  {"ISO 8859-1:1987; Latin Alphabet No. 1","ISO8859_1",0x00010001,1,{0x0011},1},
  {"IBM-1047 (CCSID 01047); Latin-1 Open System","EBCDIC",0x10020417,1,{0x0011},1},
  {"ISO/IEC 10646-1:1993; UCS-4, Level 1","UCS-4",0x00010104,1,{0x1000},4},
  {"ISO/IEC 10646-1:1993; UTF-16, UCS Transformation Format 16-bit form","UTF-16",0x00010109,1,{0x1000},2},
  {"X/Open UTF-8; UCS Transformation Format 8 (UTF-8)","UTF-8",0x05010001,1,{0x1000},6},
  {"ISO/IEC 8859-5:1988; Latin-Cyrillic Alphabet","ISO-8859-5",0x00010005,1,{0x0015},1},
  {"IBM-1251 (CCSID 01251); MS Windows Cyrillic","CP1251",0x100204e3,1,{0x0015},1},
  {"IBM-855 (CCSID 04951); Cyrillic Personal Computer","CP855",0x10021357,1,{0x0015},1}
};
size_t const ACE_Codeset_Registry::num_registry_entries_ = 9;
ACE_END_VERSIONED_NAMESPACE_DECL

