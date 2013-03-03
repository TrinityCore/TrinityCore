// $Id: SSL_Initializer.cpp 93497 2011-03-07 09:43:36Z vzykov $

#include "SSL_Initializer.h"
#include "SSL_Context.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

int
ACE_SSL_Initializer::static_init (void)
{
  ACE_Service_Config::process_directive (ace_svc_desc_ACE_SSL_Initializer);
  return 0;
}

int
ACE_SSL_Initializer::init (int, ACE_TCHAR *[])
{
  // Initialize ACE_SSL_Context singleton.
  ACE_SSL_Context * ssl_ctx = ACE_SSL_Context::instance ();
  ACE_ASSERT (ssl_ctx != 0);
  ACE_UNUSED_ARG (ssl_ctx);

  return 0;
}

int
ACE_SSL_Initializer::fini (void)
{
  // Explicitly close the ACE_SSL_Context singleton.
  ACE_Unmanaged_Singleton<ACE_SSL_Context, ACE_SYNCH_MUTEX>::close();

  return 0;
}

ACE_END_VERSIONED_NAMESPACE_DECL

ACE_STATIC_SVC_DEFINE (ACE_SSL_Initializer,
                       ACE_TEXT ("ACE_SSL_Initializer"),
                       ACE_SVC_OBJ_T,
                       &ACE_SVC_NAME (ACE_SSL_Initializer),
                       ACE_Service_Type::DELETE_THIS |
                         ACE_Service_Type::DELETE_OBJ,
                       0)
ACE_FACTORY_DEFINE (ACE_SSL, ACE_SSL_Initializer)
