// $Id: MEM_SAP.cpp 80826 2008-03-04 14:51:23Z wotte $

#include "ace/MEM_SAP.h"

#if (ACE_HAS_POSITION_INDEPENDENT_POINTERS == 1)

#if !defined (__ACE_INLINE__)
#include "ace/MEM_SAP.inl"
#endif /* __ACE_INLINE__ */

ACE_RCSID(ace, MEM_SAP, "$Id: MEM_SAP.cpp 80826 2008-03-04 14:51:23Z wotte $")

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_IPC_SAP)

void
ACE_MEM_SAP::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_MEM_SAP::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  if (this->shm_malloc_ != 0)
    this->shm_malloc_->dump ();
  else
    ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("ACE_MEM_SAP uninitialized.\n")));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

ACE_MEM_SAP::ACE_MEM_SAP (void)
  : handle_ (ACE_INVALID_HANDLE),
    shm_malloc_ (0)
{
  // ACE_TRACE ("ACE_MEM_SAP::ACE_MEM_SAP");
}

ACE_MEM_SAP::~ACE_MEM_SAP (void)
{
  // ACE_TRACE ("ACE_MEM_SAP::~ACE_MEM_SAP");
  delete this->shm_malloc_;
}

int
ACE_MEM_SAP::fini ()
{
  ACE_TRACE ("ACE_MEM_SAP::fini");

  return this->close_shm_malloc ();
}

int
ACE_MEM_SAP::create_shm_malloc (const ACE_TCHAR *name,
                                MALLOC_OPTIONS *options)
{
  ACE_TRACE ("ACE_MEM_SAP::create_shm_malloc");

  if (this->shm_malloc_ != 0)
    return -1;                  // already initialized.

  ACE_NEW_RETURN (this->shm_malloc_,
                  MALLOC_TYPE (name,
                               0,
                               options),
                  -1);

  if (this->shm_malloc_->bad () != 0)
    {
      this->shm_malloc_->remove (); // Cleanup OS resources
      delete this->shm_malloc_;
      this->shm_malloc_ = 0;
      return -1;
    }

  return 0;
}

int
ACE_MEM_SAP::close_shm_malloc (void)
{
  ACE_TRACE ("ACE_MEM_SAP::close_shm_malloc");

  int retv = -1;

  if (this->shm_malloc_ != 0)
    this->shm_malloc_->release (1);

  delete this->shm_malloc_;
  this->shm_malloc_ = 0;

  return retv;
}

#endif /* ACE_HAS_POSITION_INDEPENDENT_POINTERS == 1 */

ACE_END_VERSIONED_NAMESPACE_DECL
