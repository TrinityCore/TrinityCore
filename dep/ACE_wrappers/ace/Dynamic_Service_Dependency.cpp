#include "ace/ACE.h"
#include "ace/DLL_Manager.h"
#include "ace/Dynamic_Service_Dependency.h"
#include "ace/Service_Config.h"
#include "ace/Log_Msg.h"

ACE_RCSID (ace,
           Dynamic_Service_Dependency,
           "$Id: Dynamic_Service_Dependency.cpp 80826 2008-03-04 14:51:23Z wotte $")


  ACE_BEGIN_VERSIONED_NAMESPACE_DECL


ACE_Dynamic_Service_Dependency::ACE_Dynamic_Service_Dependency (const ACE_TCHAR *principal)
{
  this->init (ACE_Service_Config::current (), principal);
}

ACE_Dynamic_Service_Dependency::ACE_Dynamic_Service_Dependency (const ACE_Service_Gestalt *cfg,
                                                                const ACE_TCHAR *principal)
{
  this->init (cfg, principal);
}


ACE_Dynamic_Service_Dependency::~ACE_Dynamic_Service_Dependency (void)
{
  if (ACE::debug ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("(%P|%t) DSD, this=%@ - destroying\n"),
                this));
}

void
ACE_Dynamic_Service_Dependency::init (const ACE_Service_Gestalt *cfg,
                                      const ACE_TCHAR *principal)
{
  const ACE_Service_Type* st =
    ACE_Dynamic_Service_Base::find_i (cfg, principal,false);
  if (ACE::debug ())
    {
      ACE_DEBUG ((LM_DEBUG,
      ACE_TEXT ("(%P|%t) DSD, this=%@ - creating dependency on "), this));
      st->dump ();
    }
  this->tracker_ = st->dll ();
}


ACE_END_VERSIONED_NAMESPACE_DECL

