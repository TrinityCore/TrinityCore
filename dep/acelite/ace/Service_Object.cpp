// $Id: Service_Object.cpp 91286 2010-08-05 09:04:31Z johnnyw $

#include "ace/config-all.h"

#include "ace/Service_Object.h"

#if !defined (__ACE_INLINE__)
#include "ace/Service_Object.inl"
#endif /* __ACE_INLINE__ */

#include "ace/OS_NS_stdio.h"
#include "ace/Service_Types.h"
#include "ace/DLL.h"
#include "ace/ACE.h"
#include "ace/Log_Msg.h"
#if defined (ACE_OPENVMS)
# include "ace/Lib_Find.h"
#endif

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_Service_Object)
ACE_ALLOC_HOOK_DEFINE(ACE_Service_Type)

void
ACE_Service_Type::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Service_Type::dump");
#endif /* ACE_HAS_DUMP */


  // Using printf, since the log facility may not have been
  // initialized yet. Using a "//" prefix, in case the executable
  // happens to be a code generator and the output gets embedded in
  // the generated C++ code.
  ACE_OS::fprintf(stderr,
                  "// [ST] dump, this=%p, name=%s, type=%p, so=%p, active=%d\n",
                  this,
                  this->name_,
                  this->type_,
                  (this->type_ != 0) ? this->type_->object () : 0,
                  this->active_);

}

ACE_Service_Type::ACE_Service_Type (const ACE_TCHAR *n,
                                    ACE_Service_Type_Impl *t,
                                    const ACE_DLL &dll,
                                    bool active)
  : name_ (0),
    type_ (t),
    dll_ (dll),
    active_ (active),
    fini_already_called_ (false)
{
  ACE_TRACE ("ACE_Service_Type::ACE_Service_Type");
  this->name (n);
}

ACE_Service_Type::ACE_Service_Type (const ACE_TCHAR *n,
                                    ACE_Service_Type_Impl *t,
                                    ACE_SHLIB_HANDLE handle,
                                    bool active)
  : name_ (0),
    type_ (t),
    active_ (active),
    fini_already_called_ (false)
{
  ACE_TRACE ("ACE_Service_Type::ACE_Service_Type");
  this->dll_.set_handle (handle);
  this->name (n);
}

ACE_Service_Type::~ACE_Service_Type (void)
{
  ACE_TRACE ("ACE_Service_Type::~ACE_Service_Type");
  this->fini ();

  delete [] const_cast <ACE_TCHAR *> (this->name_);
}

int
ACE_Service_Type::fini (void)
{
  if (ACE::debug ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("ACE (%P|%t) ST::fini - destroying name=%s, dll=%s\n"),
                this->name_,
                this->dll_.dll_name_));

  if (this->fini_already_called_)
    return 0;

  this->fini_already_called_ = true;

  if (this->type_ == 0)
    {
      // Returning 1 currently only makes sense for dummy instances, used
      // to "reserve" a spot (kind of like forward-declarations) for a
      // dynamic service. This is necessary to help enforce the correct
      // finalization order, when such service also has any (dependent)
      // static services

      return 1; // No implementation was found.
    }

  int ret = this->type_->fini ();

  // Ensure type is 0 to prevent invalid access after call to fini.
  this->type_ = 0;

  // Ensure that closing the DLL is done after type_->fini() as it may
  // require access to the code for the service object destructor,
  // which resides in the DLL

  return (ret | this->dll_.close ());
}

int
ACE_Service_Type::suspend (void) const
{
  ACE_TRACE ("ACE_Service_Type::suspend");
  (const_cast<ACE_Service_Type *> (this))->active_ = false;
  return this->type_->suspend ();
}

int
ACE_Service_Type::resume (void) const
{
  ACE_TRACE ("ACE_Service_Type::resume");
  (const_cast<ACE_Service_Type *> (this))->active_ = true;
  return this->type_->resume ();
}

ACE_Service_Object::ACE_Service_Object (ACE_Reactor *r)
  : ACE_Event_Handler (r)
{
  ACE_TRACE ("ACE_Service_Object::ACE_Service_Object");
}

ACE_Service_Object::~ACE_Service_Object (void)
{
  ACE_TRACE ("ACE_Service_Object::~ACE_Service_Object");
}

int
ACE_Service_Object::suspend (void)
{
  ACE_TRACE ("ACE_Service_Object::suspend");
  return 0;
}

int
ACE_Service_Object::resume (void)
{
  ACE_TRACE ("ACE_Service_Object::resume");
  return 0;
}

void
ACE_Service_Type::name (const ACE_TCHAR *n)
{
  ACE_TRACE ("ACE_Service_Type::name");

  delete [] const_cast <ACE_TCHAR *> (this->name_);
  this->name_ = ACE::strnew (n);
}

#if defined (ACE_OPENVMS)
ACE_Dynamic_Svc_Registrar::ACE_Dynamic_Svc_Registrar (const ACE_TCHAR* alloc_name,
                                                      void* svc_allocator)
{
  // register service allocator function by full name in ACE singleton registry
  ACE::ldregister (alloc_name, svc_allocator);
}
#endif

ACE_END_VERSIONED_NAMESPACE_DECL
