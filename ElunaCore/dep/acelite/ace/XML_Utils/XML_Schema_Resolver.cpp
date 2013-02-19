// $Id: XML_Schema_Resolver.cpp 95760 2012-05-15 13:46:19Z msmit $
#include "XML_Schema_Resolver.h"

#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/util/XercesDefs.hpp>

#include "XercesString.h"

#include "ace/Env_Value_T.h"

#include <iostream>

namespace XML
{
  Basic_Resolver::Basic_Resolver (const ACE_TCHAR *path)
    : path_ (path)
  {
  }

  XMLCh *
  Basic_Resolver::operator() (const XMLCh *const,
                              const XMLCh *const systemId) const
  {
    XStr path (path_);
    path.append (systemId);
    return path.release ();
  }

  Environment_Resolver::Environment_Resolver (void)
  {
  }

  Environment_Resolver::Environment_Resolver (const ACE_TCHAR *variable,
                                              const ACE_TCHAR *relpath)
  {
    this->add_path (variable, relpath);
  }

  using xercesc::XMLPlatformUtils;

  void
  Environment_Resolver::add_path (const ACE_TCHAR *variable,
                                  const ACE_TCHAR *relpath)
  {
    ACE_Env_Value <const ACE_TCHAR *> path_env (variable,
                                                ACE_TEXT(""));

    XStr xpath (path_env);
    XStr xrelpath (relpath);

    xpath.append (xrelpath);

    paths_.push_back (xpath);
  }

  XMLCh *
  Environment_Resolver::operator() (const XMLCh *const,
                                    const XMLCh *const systemId) const
  {
    for (std::vector<XStr>::const_iterator i = this->paths_.begin ();
          i != this->paths_.end ();
          ++i)
      {
        XStr path (*i);
        path.append(systemId);

        FileHandle file (XMLPlatformUtils::openFile (path));

        if (file != 0)
          {
            XMLPlatformUtils::closeFile (file);
            return path.release ();
          }
      }
    return 0;
  }
}
