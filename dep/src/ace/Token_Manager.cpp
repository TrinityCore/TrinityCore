#include "ace/Token_Manager.h"

#if defined (ACE_HAS_TOKENS_LIBRARY)

#include "ace/Object_Manager.h"

#if !defined (__ACE_INLINE__)
#include "ace/Token_Manager.inl"
#endif /* __ACE_INLINE__ */

ACE_RCSID (ace,
           Token_Manager,
           "$Id: Token_Manager.cpp 80826 2008-03-04 14:51:23Z wotte $")

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// singleton token manager
ACE_Token_Manager *ACE_Token_Manager::token_manager_ = 0;

ACE_Token_Manager::ACE_Token_Manager ()
{
  ACE_TRACE ("ACE_Token_Manager::ACE_Token_Manager");
}

ACE_Token_Manager::~ACE_Token_Manager ()
{
  ACE_TRACE ("ACE_Token_Manager::~ACE_Token_Manager");

  COLLECTION::ITERATOR iterator (collection_);

  for (COLLECTION::ENTRY *temp = 0;
       iterator.next (temp) != 0;
       iterator.advance ())
    {
      // @ should I be doing an unbind here?
      delete temp->int_id_;
      // The ext_id_'s delete themselves when the array of
      // COLLECTION::ENTRYs goes away.
    }
}

ACE_Token_Manager *
ACE_Token_Manager::instance (void)
{
  ACE_TRACE ("ACE_Token_Manager::instance");

  // This first check is to avoid acquiring the mutex in the common
  // case.  Double-Check pattern rules.
  if (token_manager_ == 0)
    {
#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
      ACE_TOKEN_CONST::MUTEX *lock =
        ACE_Managed_Object<ACE_TOKEN_CONST::MUTEX>::get_preallocated_object
          (ACE_Object_Manager::ACE_TOKEN_MANAGER_CREATION_LOCK);
      ACE_GUARD_RETURN (ACE_TOKEN_CONST::MUTEX, ace_mon, *lock, 0);
#endif /* ACE_MT_SAFE */

      if (token_manager_ == 0)
        {
          ACE_NEW_RETURN (token_manager_,
                          ACE_Token_Manager,
                          0);
          // Register for destruction with ACE_Object_Manager.
          ACE_Object_Manager::at_exit (token_manager_);
        }
    }

  return token_manager_;
}

void
ACE_Token_Manager::get_token (ACE_Token_Proxy *proxy,
                              const ACE_TCHAR *token_name)
{
  ACE_TRACE ("ACE_Token_Manager::get_token");
  // Hmm.  I think this makes sense.  We perform our own locking here
  // (see safe_acquire.)  We have to make sure that only one thread
  // uses the collection at a time.

  ACE_GUARD (ACE_TOKEN_CONST::MUTEX, ace_mon, this->lock_);

  TOKEN_NAME name (token_name);

  if (collection_.find (name, proxy->token_) == -1)
    // We did not find one in the collection.
    {
      // Make one.
      proxy->token_ = proxy->create_token (token_name);

      // Put it in the collection.
      if (collection_.bind (name, proxy->token_) == -1)
        {
          delete proxy->token_;
          proxy->token_ = 0;
        }
    }

  if (proxy->token_ != 0)
    proxy->token_->inc_reference ();

  // We may be returning proxy->token_ == 0 if new failed, caller must
  // check.
}

// 0. check_deadlock (TOKEN)
// 1. if TOKEN->visited (), return 0.
// 2. mark TOKEN visited.
// 3. get ALL_OWNERS
// 4. if CLIENT in ALL_OWNERS, return *DEADLOCK*.
// 5. for each OWNER in ALL_OWNERS,
// 6.    if OWNER is not waiting for a NEW_TOKEN, continue.
// 7.    else, if check_deadlock (NEW_TOKEN) == 1, return *DEADLOCK*
// 8. return 0.

int
ACE_Token_Manager::check_deadlock (ACE_Token_Proxy *proxy)
{
  ACE_TRACE ("ACE_Token_Manager::check_deadlock");

  // Start the recursive deadlock detection algorithm.
  int result = this->check_deadlock (proxy->token_, proxy);

  // Whether or not we detect deadlock, we have to unmark all tokens
  // for the next time.
  COLLECTION::ITERATOR iterator (collection_);
  for (COLLECTION::ENTRY *temp = 0;
       iterator.next (temp) != 0;
       iterator.advance ())
      temp->int_id_->visit (0);

  return result;
}

int
ACE_Token_Manager::check_deadlock (ACE_Tokens *token, ACE_Token_Proxy *proxy)
{
  ACE_TRACE ("ACE_Token_Manager::check_deadlock");

  if (token->visited ())
    return 0;

  token->visit (1);

  ACE_Tokens::OWNER_STACK owners;

  int is_owner = token->owners (owners, proxy->client_id ());

  switch (is_owner)
    {
    case -1:
      // Error.
      return -1;
    case 1:
      // The caller is an owner, so we have a deadlock situation.
      if (debug_)
        {
          ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("(%t) Deadlock detected.\n")));
          ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("%s owns %s and is waiting for %s.\n"),
                      proxy->client_id (),
                      token->name (),
                      proxy->token_->name ()));
        }

      return 1;
    case 0:
    default:
      // Recurse on each owner.
      while (!owners.is_empty ())
        {
          ACE_TPQ_Entry *e;
          owners.pop (e);
          // If the owner is waiting on another token, recurse.
          ACE_Tokens *twf = this->token_waiting_for (e->client_id ());
          if ((twf != 0) &&
              (this->check_deadlock (twf, proxy) == 1))
            {
              if (debug_)
                {
                  ACE_DEBUG ((LM_DEBUG,
                              ACE_TEXT ("%s owns %s and is waiting for %s.\n"),
                              e->client_id (),
                              token->name (),
                              twf->name ()));
                }
              return 1;
            }
          // else, check the next owner.
        }

      // We've checked all the owners and found no deadlock.
      return 0;
    }
}

ACE_Tokens *
ACE_Token_Manager::token_waiting_for (const ACE_TCHAR *client_id)
{
  COLLECTION::ITERATOR iterator (collection_);
  for (COLLECTION::ENTRY *temp = 0;
       iterator.next (temp) != 0;
       iterator.advance ())
    {
      if (temp->int_id_->is_waiting_for (client_id))
        return temp->int_id_;
    }

  // nothing was found, return NULL.
  return 0;
}

// Notify the token manager that a token is has been released.  If
// as a result, there is no owner of the token, the token is
// deleted.
void
ACE_Token_Manager::release_token (ACE_Tokens *&token)
{
  ACE_TRACE ("ACE_Token_Manager::release_token");
  // again, let's perform our own locking here.

  ACE_GUARD (ACE_TOKEN_CONST::MUTEX, ace_mon, this->lock_);

  if (token->dec_reference () == 0)
    {
      // No one has the token, so we can delete it and remove it from
      // our collection.  First, let's get it from the collection.
      TOKEN_NAME token_name (token->name ());

      ACE_Tokens *temp;

      if (collection_.unbind (token_name, temp) == -1)
        // we did not find one in the collection
        {
          errno = ENOENT;
          ACE_ERROR ((LM_ERROR, ACE_TEXT ("Token Manager could not release %s:%d\n"),
                      token->name (), token->type ()));
          // @@ bad
        }
      else
        // we found it
        {
          // sanity pointer comparison.  The token referenced by the
          // proxy better be the one we found in the list.
          ACE_ASSERT (token == temp);
          delete token;  // or delete temp
          // we set their token to zero.  if the calling proxy is
          // still going to be used, it had better check it's token
          // value before calling a method on it!
          token = 0;
        }
    }
  // else
  // someone is still interested in the token, so keep it around.
}

void
ACE_Token_Manager::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Token_Manager::dump");
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("ACE_Token_Manager::dump:\n")));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("lock_\n")));
  lock_.dump ();
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("collection_\n")));
  collection_.dump ();
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_TOKENS_LIBRARY */

