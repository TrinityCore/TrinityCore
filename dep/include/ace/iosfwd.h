// -*- C++ -*-

//=============================================================================
/**
 *  @file    iosfwd.h
 *
 *  $Id: iosfwd.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Irfan Pyarali
 *
 *  This file contains the portability ugliness for the Standard C++
 *  Library.  As implementations of the "standard" emerge, this file
 *  will need to be updated.
 *
 *  This files deals with forward declaration for the stream
 *  classes.  Remember that since the new Standard C++ Library code
 *  for streams uses templates, simple forward declaration will not
 *  work.
 */
//=============================================================================

#ifndef ACE_IOSFWD_H
#define ACE_IOSFWD_H

#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if !defined (ACE_LACKS_IOSTREAM_TOTALLY)

#if defined (__APPLE_CC__)
// Should this really be here?  dhinton
// FUZZ: disable check_for_streams_include
# include "ace/streams.h"
#endif

#if defined (ACE_HAS_STANDARD_CPP_LIBRARY)  && \
    (ACE_HAS_STANDARD_CPP_LIBRARY != 0)

# if !defined (ACE_USES_OLD_IOSTREAMS)
#   include /**/ <iosfwd>
# else
  // @note If these forward declarations don't work (e.g. aren't
  //       portable), we may have to include "ace/streams.h" as a last
  //       resort.  Doing so would defeat the purpose of this header,
  //       unfortunately.
  class ios;
  class streambuf;
  class istream;
  class ostream;
  class iostream;
  class filebuf;
  class ifstream;
  class ofstream;
  class fstream;
# endif /* ! ACE_USES_OLD_IOSTREAMS */

# if defined (ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB) && \
             (ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB != 0)

#   if !defined (ACE_USES_OLD_IOSTREAMS)
      // Make these available in the global name space
      using std::ios;
      using std::streambuf;
      using std::istream;
      using std::ostream;
      using std::iostream;
      using std::filebuf;
      using std::ifstream;
      using std::ofstream;
      using std::fstream;
#   endif /* ! ACE_USES_OLD_IOSTREAMS */

# endif /* ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB */

#else /* ! ACE_HAS_STANDARD_CPP_LIBRARY */

  class ios;
  class streambuf;
  class istream;
  class ostream;
  class iostream;
  class filebuf;
  class ifstream;
  class ofstream;
  class fstream;

# endif /* ! ACE_HAS_STANDARD_CPP_LIBRARY */

#include /**/ "ace/post.h"

#endif /* ACE_LACKS_IOSTREAM_TOTALLY */

#endif /* ACE_IOSFWD_H */

