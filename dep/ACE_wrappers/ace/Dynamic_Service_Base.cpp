#include "ace/Dynamic_Service_Base.h"
#include "ace/ACE.h"
#include "ace/Service_Config.h"
#include "ace/Service_Repository.h"
#include "ace/Service_Types.h"
#include "ace/Log_Msg.h"

ACE_RCSID (ace,
           Dynamic_Service_Base,
           "$Id: Dynamic_Service_Base.cpp 80826 2008-03-04 14:51:23Z wotte $")
  ACE_BEGIN_VERSIONED_NAMESPACE_DECL

void
ACE_Dynamic_Service_Base::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Dynamic_Service_Base::dump");
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\n")));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}
// Get the instance using <name> for the current global
// service configuration repository.
void *
ACE_Dynamic_Service_Base::instance (const ACE_TCHAR *name, bool no_global)
{
  ACE_TRACE ("ACE_Dynamic_Service_Base::instance");
  return instance (ACE_Service_Config::current (), name, no_global);
}
// Find a service registration
const ACE_Service_Type *
ACE_Dynamic_Service_Base::find_i (const ACE_Service_Gestalt* &repo,
                                  const ACE_TCHAR *name,
                                  bool no_global)
{
  ACE_TRACE ("ACE_Dynamic_Service_Base::find_i");
  const ACE_Service_Type *svc_rec = 0;
  ACE_Service_Gestalt* global = ACE_Service_Config::global ();
  for ( ; (repo->find (name, &svc_rec) == -1) && !no_global; repo = global)
    {
      // Check the static repo, too if different
      if (repo == global)
        break;
    }
  return svc_rec;
}

// Get the instance using <name> for specific configuration repository.
void *
ACE_Dynamic_Service_Base::instance (const ACE_Service_Gestalt* repo,
                                    const ACE_TCHAR *name,
                                    bool no_global)
{
  ACE_TRACE ("ACE_Dynamic_Service_Base::instance");
  void *obj = 0;
  const ACE_Service_Type_Impl *type = 0;
  const ACE_Service_Gestalt* repo_found = repo;
  const ACE_Service_Type *svc_rec = find_i (repo_found, name, no_global);
  if (svc_rec != 0)
    {
      type = svc_rec->type ();
      if (type != 0)
        obj = type->object ();
    }
  if (ACE::debug ())
    {
      ACE_Guard <ACE_Log_Msg> log_guard (*ACE_Log_Msg::instance ());
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("ACE (%P|%t) DSB::instance, repo=%@, name=%s")
                  ACE_TEXT (" type=%@ => %@"),
                  repo->repo_, name, type, obj));
      if (repo->repo_ != repo_found->repo_)
        ACE_DEBUG ((LM_DEBUG,
                    ACE_TEXT (" [in repo=%@]\n"),
                    repo_found->repo_));
      else
        ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\n")));
    }
  return obj;
}
ACE_END_VERSIONED_NAMESPACE_DECL

