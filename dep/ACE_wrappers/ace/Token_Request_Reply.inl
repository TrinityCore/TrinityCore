// -*- C++ -*-
//
// $Id: Token_Request_Reply.inl 80826 2008-03-04 14:51:23Z wotte $

#if defined (ACE_HAS_TOKENS_LIBRARY)

#include "ace/Truncate.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// = Set/get the length of the encoded/decoded message.

ACE_INLINE ACE_UINT32
ACE_Token_Request::length (void) const
{
  return ntohl (this->transfer_.length_);
}

ACE_INLINE void
ACE_Token_Request::length (ACE_UINT32 l)
{
  this->transfer_.length_ = htonl (l);
}

// = Set/get the type of the message.
ACE_INLINE int
ACE_Token_Request::token_type (void) const
{
  return (int) ntohl (this->transfer_.token_type_);
}

ACE_INLINE void
ACE_Token_Request::token_type (int t)
{
  this->transfer_.token_type_ = htonl ((ACE_UINT32) t);
}

// = Set/get the type of the message.
ACE_INLINE int
ACE_Token_Request::proxy_type (void) const
{
  return (int) ntohl (this->transfer_.proxy_type_);
}

ACE_INLINE void
ACE_Token_Request::proxy_type (int t)
{
  this->transfer_.proxy_type_ = htonl ((ACE_UINT32) t);
}

// = Set/get the type of the message.
ACE_INLINE ACE_UINT32
ACE_Token_Request::operation_type (void) const
{
  return ntohl (this->transfer_.operation_type_);
}

ACE_INLINE void
ACE_Token_Request::operation_type (ACE_UINT32 t)
{
  this->transfer_.operation_type_ = htonl (t);
}

// = Set/get the requeue position
ACE_INLINE ACE_UINT32
ACE_Token_Request::requeue_position (void) const
{
  return ntohl (this->transfer_.requeue_position_);
}

ACE_INLINE void
ACE_Token_Request::requeue_position (ACE_UINT32 rq)
{
  this->transfer_.requeue_position_ = htonl (rq);
}

// = Set/get the requeue position
ACE_INLINE ACE_UINT32
ACE_Token_Request::notify (void) const
{
  return ntohl (this->transfer_.notify_);
}

ACE_INLINE void
ACE_Token_Request::notify (ACE_UINT32 rq)
{
  this->transfer_.notify_ = htonl (rq);
}

// = Set/get the blocking semantics.
ACE_INLINE ACE_Synch_Options &
ACE_Token_Request::options (void) const
{
  return (ACE_Synch_Options &) options_;
}

ACE_INLINE void
ACE_Token_Request::options (const ACE_Synch_Options &opt)
{
  // fight the friggin const from hell
  ACE_Synch_Options *options = (ACE_Synch_Options *) &opt;

  transfer_.use_timeout_ = options->operator[](ACE_Synch_Options::USE_TIMEOUT);
  if (transfer_.use_timeout_ == 1)
    {
      transfer_.usec_ = options->timeout ().usec ();
      if (options->timeout ().sec () > (time_t) ACE_UINT32_MAX)
        transfer_.sec_ = ACE_UINT32_MAX;
      else
        transfer_.sec_ = static_cast<ACE_UINT32> (options->timeout ().sec ());
    }
  else
    {
      transfer_.usec_ = 0;
      transfer_.sec_ = 0;
    }
}

// = Set/get the name of the token.
ACE_INLINE ACE_TCHAR *
ACE_Token_Request::token_name (void) const
{
  return token_name_;
}

ACE_INLINE void
ACE_Token_Request::token_name (const ACE_TCHAR *token_name,
                               const ACE_TCHAR *client_id)
{
  size_t token_name_length = ACE_OS::strlen (token_name) + 1; // Add 1 for '\0'.
  size_t client_id_length = ACE_OS::strlen (client_id) + 1; // Add 1 for '\0'.

  // Set up pointers and copy token_name and client_id into request.
  token_name_ = this->transfer_.data_;
  client_id_  = &this->token_name_[token_name_length + 1]; // Add 1 for ':';
  client_id_[-1] = ACE_TEXT (':'); // Insert the ':' before this->clientId_.

  (void) ACE_OS::memcpy (this->token_name_,
                         token_name,
                         token_name_length * sizeof (ACE_TCHAR));
  (void) ACE_OS::memcpy (this->client_id_,
                         client_id,
                         client_id_length * sizeof (ACE_TCHAR));

  // Fixed length header size
  size_t len = ACE_TOKEN_REQUEST_HEADER_SIZE;

  // ... then add in the amount of the variable-sized portion.
  len += token_name_length + client_id_length + 1;
  this->length (ACE_Utils::truncate_cast<ACE_UINT32> (len));
}

// = Set/get the id of the client.
ACE_INLINE ACE_TCHAR *
ACE_Token_Request::client_id (void) const
{
  return this->client_id_;
}

// ************************************************************
// ************************************************************
// ************************************************************

// = Set/get the length of the encoded/decoded message.
ACE_INLINE ACE_UINT32
ACE_Token_Reply::length (void) const
{
  return ntohl (this->transfer_.length_);
}

ACE_INLINE void
ACE_Token_Reply::length (ACE_UINT32 l)
{
  this->transfer_.length_ = htonl (l);
}

// = Set/get the errno of a failed reply.
ACE_INLINE ACE_UINT32
ACE_Token_Reply::errnum (void) const
{
  return ntohl (this->transfer_.errno_);
}

ACE_INLINE void
ACE_Token_Reply::errnum (ACE_UINT32 e)
{
  this->transfer_.errno_ = htonl (e);
}

// = Set/get the length of the encoded/decoded message.
ACE_INLINE ACE_UINT32
ACE_Token_Reply::arg (void) const
{
  return ntohl (this->transfer_.arg_);
}

ACE_INLINE void
ACE_Token_Reply::arg (ACE_UINT32 arg)
{
  this->transfer_.arg_ = htonl (arg);
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_TOKENS_LIBRARY */
