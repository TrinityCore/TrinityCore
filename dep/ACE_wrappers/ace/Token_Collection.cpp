#include "ace/Token_Collection.h"

#if defined (ACE_HAS_TOKENS_LIBRARY)

#if !defined (__ACE_INLINE__)
#include "ace/Token_Collection.inl"
#endif /* __ACE_INLINE__ */


ACE_RCSID (ace,
           Token_Collection,
           "$Id: Token_Collection.cpp 80826 2008-03-04 14:51:23Z wotte $")

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_Token_Collection::ACE_Token_Collection (bool debug,
                                            const ACE_TCHAR *name)
: debug_ (debug)
{
  ACE_TRACE ("ACE_Token_Collection::ACE_Token_Collection");

  if (name == 0)
    name = ACE_TEXT ("no name");

  ACE_OS::strsncpy (this->name_,
                    const_cast<ACE_TCHAR *> (name),
                    ACE_MAXTOKENNAMELEN);
}

int
ACE_Token_Collection::insert (ACE_Token_Proxy &new_token)
{
  ACE_TRACE ("ACE_Token_Collection::insert");

  TOKEN_NAME name (new_token.name ());

  // Check if the new_proxy is already in the list.
  if (collection_.find (name) == 1)
    // One already exists, so fail.
    return -1;

  // Clone the new token.
  ACE_Token_Proxy *temp = new_token.clone ();

  if (collection_.bind (name, temp) == -1)
    ACE_ERROR_RETURN ((LM_ERROR, ACE_TEXT ("bind failed\n")), -1);
  return 0;
}

int
ACE_Token_Collection::extract (const ACE_TCHAR *token_name, ACE_Token_Proxy *&proxy)
{
  ACE_TRACE ("ACE_Token_Collection::extract");
  TOKEN_NAME name (token_name);
  return collection_.unbind (token_name, proxy);
}

ACE_Token_Proxy *
ACE_Token_Collection::is_member (const ACE_TCHAR *token_name)
{
  ACE_TRACE ("ACE_Token_Collection::is_member");
  TOKEN_NAME name (token_name);
  ACE_Token_Proxy *temp;
  // Get the token from the collection.
  return collection_.find (name, temp) == -1 ? 0 : temp;
}

int
ACE_Token_Collection::is_member (const ACE_Token_Proxy &token)
{
  ACE_TRACE ("ACE_Token_Collection::is_member");
  TOKEN_NAME token_name (token.name ());
  return collection_.find (token_name) == 0;
}

int
ACE_Token_Collection::acquire (int notify,
                               void (*sleep_hook)(void *),
                               ACE_Synch_Options &options)
{
  ACE_TRACE ("ACE_Token_Collection::acquire");

  COLLECTION::ITERATOR iterator (collection_);

  for (COLLECTION::ENTRY *temp = 0;
       iterator.next (temp) != 0;
       iterator.advance ())
    {
      if (debug_)
        ACE_DEBUG ((LM_DEBUG,
                    ACE_TEXT ("collection acquiring %s\n"),
                    temp->int_id_->name ()));
      if (temp->int_id_->acquire (notify,
                                  sleep_hook,
                                  options) == -1)
        {
          // Save/restore errno.
          ACE_Errno_Guard error (errno);
          this->release ();
          ACE_RETURN (-1);
        }
    }

  return 0;
}

int
ACE_Token_Collection::acquire (const ACE_TCHAR *token_name,
                               int notify,
                               void (*sleep_hook)(void *),
                               ACE_Synch_Options &options)
{
  ACE_TRACE ("ACE_Token_Collection::acquire");
  TOKEN_NAME name (token_name);
  ACE_Token_Proxy *temp;
  // Get the token from the collection.
  int result = collection_.find (name, temp);
  // did we find it?
  if (result == -1)
    return result;
  // perform the operation
  return temp->acquire (notify, sleep_hook, options);
}


int
ACE_Token_Collection::tryacquire (const ACE_TCHAR *token_name,
                                  void (*sleep_hook)(void *))
{
  ACE_TRACE ("ACE_Token_Collection::tryacquire");
  TOKEN_NAME name (token_name);
  ACE_Token_Proxy *temp;
  // Get the token from the collection.
  int result = collection_.find (name, temp);
  // did we find it?
  if (result == -1)
    return result;

  // perform the operation
  return temp->tryacquire (sleep_hook);
}

int
ACE_Token_Collection::tryacquire (void (*sleep_hook)(void *))
{
  ACE_TRACE ("ACE_Token_Collection::tryacquire");

  COLLECTION::ITERATOR iterator (collection_);

  for (COLLECTION::ENTRY *temp = 0;
       iterator.next (temp) != 0;
       iterator.advance ())
    {
      if (debug_)
        ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("collection acquiring %s\n"),
                    temp->int_id_->name ()));
      // We will fail if _any_ token is not free.
      if (temp->int_id_->tryacquire (sleep_hook) == -1)
        return -1;
    }

  return 0;
}

int
ACE_Token_Collection::renew (int requeue_position,
                             ACE_Synch_Options &options)
{
  ACE_TRACE ("ACE_Token_Collection::renew");

  COLLECTION::ITERATOR iterator (collection_);

  for (COLLECTION::ENTRY *temp = 0;
       iterator.next (temp) != 0;
       iterator.advance ())
    {
      if (debug_)
        ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("collection renewing %s\n"),
                    temp->int_id_->name ()));
      if (temp->int_id_->renew (requeue_position, options) == -1)
        return -1;
    }

  return 0;
}

int
ACE_Token_Collection::renew (const ACE_TCHAR *token_name,
                             int requeue_position,
                             ACE_Synch_Options &options)
{
  ACE_TRACE ("ACE_Token_Collection::renew");
  TOKEN_NAME name (token_name);
  ACE_Token_Proxy *temp;

  // Get the token from the collection.
  int result = collection_.find (name, temp);

  // Did we find it?
  if (result == -1)
    ACE_ERROR_RETURN ((LM_DEBUG, ACE_TEXT ("%p %s\n"),
                       ACE_TEXT ("not in collection "),
                       token_name), -1);
  // perform the operation
  return temp->renew (requeue_position, options);
}

int
ACE_Token_Collection::release (ACE_Synch_Options &)

{
  ACE_TRACE ("ACE_Token_Collection::release");
  COLLECTION::ITERATOR iterator (collection_);

  for (COLLECTION::ENTRY *temp = 0;
       iterator.next (temp) != 0;
       iterator.advance ())
    {
      if (debug_)
        ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("collection releasing %s\n"),
                    temp->int_id_->name ()));
      temp->int_id_->release ();
    }

  return 0;
}

int
ACE_Token_Collection::release (const ACE_TCHAR *token_name,
                               ACE_Synch_Options &options)
{
  ACE_TRACE ("ACE_Token_Collection::release");
  TOKEN_NAME name (token_name);
  ACE_Token_Proxy *temp;
  // get the token from the collection
  int result = collection_.find (name, temp);
  // did we find it?
  if (result != 0)
    return result;
  // perform the operation
  return temp->release (options);
}

ACE_Token_Collection::~ACE_Token_Collection (void)
{
  ACE_TRACE ("ACE_Token_Collection::~ACE_Token_Collection");
  COLLECTION::ITERATOR iterator (collection_);

  for (COLLECTION::ENTRY *temp = 0;
       iterator.next (temp) != 0;
       iterator.advance ())
    {
      delete temp->int_id_;
      // The ext_id_'s delete themselves when the array of
      // COLLECTION::ENTRYs goes away.
    }
}


// This method doesn't mean anything for a collection.
ACE_Token_Proxy *
ACE_Token_Collection::clone (void) const
{
  ACE_TRACE ("ACE_Token_Collection::clone");
  return (ACE_Token_Proxy *) 0;
}

// This method doesn't mean anything for a collection.
ACE_Tokens *
ACE_Token_Collection::create_token (const ACE_TCHAR *)
{
  ACE_TRACE ("ACE_Token_Collection::create_token");
  return (ACE_Tokens *) 0;
}

void
ACE_Token_Collection::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Token_Collection::dump");
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("ACE_Token_Collection::dump:\n")
              ACE_TEXT (" debug_ = %d\n"), debug_));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("collection_\n")));
  collection_.dump ();
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("base:\n")));
  ACE_Token_Proxy::dump ();
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_TOKENS_LIBRARY */
