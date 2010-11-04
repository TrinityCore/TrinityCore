// -*- C++ -*-
//
// $Id: Local_Tokens.inl 92069 2010-09-28 11:38:59Z johnnyw $

#if defined (ACE_HAS_TOKENS_LIBRARY)

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// ************************************************************

ACE_INLINE int
ACE_Token_Proxy_Queue::size (void)
{
  ACE_TRACE ("ACE_Token_Proxy_Queue::size");
  return this->size_;
}

// ************************************************************

ACE_INLINE int
ACE_TPQ_Entry::waiting (void) const
{
  ACE_TRACE ("ACE_TPQ_Entry::waiting");
  return waiting_;
}

ACE_INLINE void
ACE_TPQ_Entry::waiting (int v)
{
  ACE_TRACE ("ACE_TPQ_Entry::waiting");
  waiting_ = v;
}

ACE_INLINE const ACE_TCHAR *
ACE_TPQ_Entry::client_id (void) const
{
  ACE_TRACE ("ACE_TPQ_Entry::client_id");
  return this->client_id_;
}

ACE_INLINE ACE_Token_Proxy *
ACE_TPQ_Entry::proxy (void) const
{
  ACE_TRACE ("ACE_TPQ_Entry::proxy");
  return this->proxy_;
}

ACE_INLINE void
ACE_TPQ_Entry::proxy (ACE_Token_Proxy *proxy)
{
  ACE_TRACE ("ACE_TPQ_Entry::proxy");
  this->proxy_ = proxy;
}

ACE_INLINE
ACE_TPQ_Iterator::~ACE_TPQ_Iterator (void)
{
}

ACE_INLINE
ACE_Token_Proxy_Queue::~ACE_Token_Proxy_Queue (void)
{
}

ACE_INLINE void
ACE_Tokens::remove (ACE_TPQ_Entry *caller)
{
  this->waiters_.remove (caller);
}

ACE_INLINE int
ACE_Tokens::dec_reference (void)
{
  ACE_TRACE ("ACE_Tokens::dec_reference");
  if (this->reference_count_ == 0)
    {
      ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("dec_reference already zero")));
      return 0;
    }

  return --this->reference_count_;
}

ACE_INLINE void
ACE_Tokens::inc_reference (void)
{
  ACE_TRACE ("ACE_Tokens::inc_reference");
  ++this->reference_count_;
}

ACE_INLINE const ACE_TPQ_Entry *
ACE_Token_Proxy_Queue::head (void)
{
  ACE_TRACE ("ACE_Token_Proxy_Queue::head");
  if (this->head_ == 0)
    return 0;
  else
    return this->head_;
}

// **************************************************
// **************************************************
// **************************************************

ACE_INLINE void
ACE_Tokens::visit (int v)
{
  ACE_TRACE ("ACE_Tokens::visit");
  visited_ = v;
}

ACE_INLINE int
ACE_Tokens::visited (void)
{
  ACE_TRACE ("ACE_Tokens::visited");
  return visited_;
}

ACE_INLINE ACE_TPQ_Entry *
ACE_Tokens::owner (void)
{
  ACE_TRACE ("ACE_Tokens::owner");
  return (ACE_TPQ_Entry *) this->waiters_.head ();
}

ACE_INLINE const ACE_TCHAR*
ACE_Tokens::owner_id ()
{
  ACE_TRACE ("ACE_Tokens::owner_id");
  if (this->owner () == 0)
    return ACE_TEXT ("no owner");
  else
    return this->owner ()->client_id ();
}

ACE_INLINE const ACE_TCHAR*
ACE_Tokens::name (void)
{
  ACE_TRACE ("ACE_Tokens::name");
  return this->token_name_;
}

// ************************************************************

ACE_INLINE int
ACE_TPQ_Entry::nesting_level (void) const
{
  ACE_TRACE ("ACE_TPQ_Entry::nesting_level");
  return this->nesting_level_;
}

ACE_INLINE void
ACE_TPQ_Entry::nesting_level (int delta)
{
  ACE_TRACE ("ACE_TPQ_Entry::nesting_level");
  this->nesting_level_ += delta;
}

ACE_INLINE ACE_TPQ_Entry::PTVF
ACE_TPQ_Entry::sleep_hook (void) const
{
  ACE_TRACE ("ACE_TPQ_Entry::sleep_hook");
  return this->sleep_hook_;
}

ACE_INLINE void
ACE_TPQ_Entry::sleep_hook (void (*sh)(void *))
{
  ACE_TRACE ("ACE_TPQ_Entry::sleep_hook");
  this->sleep_hook_ = sh;
}

ACE_INLINE void
ACE_TPQ_Entry::call_sleep_hook (void)
{
  ACE_TRACE ("ACE_TPQ_Entry::call_sleep_hook");

  // if a function has been registered, call it.
  if (this->sleep_hook () != 0)
    this->sleep_hook () ((void *) this->proxy ());
  else
    // otherwise, call back the sleep_hook method
    this->proxy ()->sleep_hook ();
}

ACE_INLINE int
ACE_TPQ_Entry::equal_client_id (const ACE_TCHAR *id)
{
  ACE_TRACE ("ACE_TPQ_Entry::equal_client_id");
  return (ACE_OS::strcmp (this->client_id (), id) == 0);
}

// ************************************************************
// ************************************************************
// ************************************************************

ACE_INLINE
ACE_Local_Mutex::ACE_Local_Mutex (const ACE_TCHAR *token_name,
                                  int ignore_deadlock,
                                  int debug)
{
  ACE_TRACE ("ACE_Local_Mutex::ACE_Local_Mutex");
  this->open (token_name, ignore_deadlock, debug);
}

ACE_INLINE void
ACE_Token_Name::name (const ACE_TCHAR *new_name)
{
  ACE_TRACE ("ACE_Token_Name::name");

  if (new_name == 0)
    new_name = ACE_TEXT ("no name");

  size_t n = ACE_OS::strlen (new_name) + 1;

  if (n >= ACE_MAXTOKENNAMELEN)
    n = ACE_MAXTOKENNAMELEN - 1;

  ACE_OS::strsncpy (this->token_name_, (ACE_TCHAR *) new_name, n);
}

ACE_INLINE const ACE_TCHAR*
ACE_Token_Name::name (void) const
{
  ACE_TRACE ("ACE_Token_Name::name");
  return this->token_name_;
}

// ************************************************************

ACE_INLINE
ACE_Local_RLock::ACE_Local_RLock (const ACE_TCHAR *token_name,
                                  int ignore_deadlock,
                                  int debug)
{
  ACE_TRACE ("ACE_Local_RLock::ACE_Local_RLock");
  this->open (token_name, ignore_deadlock, debug);
}

// ************************************************************

ACE_INLINE
ACE_Local_WLock::ACE_Local_WLock (const ACE_TCHAR *token_name,
                                  int ignore_deadlock,
                                  int debug)
{
  ACE_TRACE ("ACE_Local_WLock::ACE_Local_WLock");
  this->open (token_name, ignore_deadlock, debug);
}

// ************************************************************


ACE_INLINE void
ACE_Token_Name::operator= (const ACE_Token_Name &rhs)
{
  ACE_TRACE ("ACE_Token_Name::operator=");
  if (&rhs == this)
    return;
  else
    this->name (rhs.name ());
}

ACE_INLINE bool
ACE_Token_Name::operator== (const ACE_Token_Name &rhs) const
{
  ACE_TRACE ("ACE_Token_Name::operator==");

  // the name and type must be the same
  return (ACE_OS::strcmp (this->token_name_, rhs.name ()) == 0);
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_TOKENS_LIBRARY */
