#include "ace/Name_Request_Reply.h"
#include "ace/Basic_Types.h"
#include "ace/CDR_Base.h"
#include "ace/Log_Msg.h"
#include "ace/Time_Value.h"
#include "ace/Truncate.h"
#include "ace/OS_NS_string.h"
#include "ace/os_include/arpa/os_inet.h"
ACE_RCSID (ace,
           Name_Request_Reply,
           "$Id: Name_Request_Reply.cpp 80826 2008-03-04 14:51:23Z wotte $")
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
// Default "do nothing" constructor.
ACE_Name_Request::ACE_Name_Request (void)
{
  ACE_TRACE ("ACE_Name_Request::ACE_Name_Request");
}
// Create a ACE_Name_Request message.
ACE_Name_Request::ACE_Name_Request (
  ACE_INT32 t, // Type of request.
  const ACE_WCHAR_T name[], // Name
  const ACE_UINT32 name_length, // size in bytes
  const ACE_WCHAR_T value[], //
  const ACE_UINT32 value_length, // size in bytes
  const char type[], //
  const ACE_UINT32 type_length, // size in bytes
  ACE_Time_Value *timeout) // Max time waiting for request.
{
  ACE_TRACE ("ACE_Name_Request::ACE_Name_Request");
  this->msg_type (t);
  this->name_len (name_length);
  this->value_len (value_length);
  this->type_len (type_length);
  // If timeout is a NULL pointer, then block forever...
  if (timeout == 0)
    {
      this->transfer_.block_forever_ = 1;
      this->transfer_.sec_timeout_   = 0;
      this->transfer_.usec_timeout_  = 0;
    }
  else // Do a "timed wait."
    {
      this->block_forever (0);
      // Keep track of how long client is willing to wait.
      this->transfer_.sec_timeout_ = timeout->sec ();
      this->transfer_.usec_timeout_ = timeout->usec ();
    }
  // Set up pointers and copy name value and type into request.
  this->name_ = this->transfer_.data_;
  this->value_  = &this->name_[name_length / sizeof (ACE_WCHAR_T) ];
  this->type_  = (char *)(&this->value_[value_length / sizeof (ACE_WCHAR_T)]); //
  (void) ACE_OS::memcpy (this->name_,
                         name,
                         name_length);
  (void) ACE_OS::memcpy (this->value_,
                         value,
                         value_length);
  (void) ACE_OS::memcpy (this->type_,
                         type,
                         type_length);
  // Compute size of the fixed portion of the message...
  size_t len = sizeof this->transfer_ - sizeof this->transfer_.data_;
  // ... then add in the amount of the variable-sized portion.
  len += name_length + value_length + type_length ;
  this->length (static_cast<ACE_UINT32> (len));
}
// Initialize length_ in order to avoid problems with byte-ordering.
void
ACE_Name_Request::init (void)
{
  ACE_TRACE ("ACE_Name_Request::init");
  this->length (sizeof this->transfer_);
}
// = Set/get the length of the encoded/decoded message.
ACE_UINT32
ACE_Name_Request::length (void) const
{
  ACE_TRACE ("ACE_Name_Request::length");
  return this->transfer_.length_;
}
void
ACE_Name_Request::length (ACE_UINT32 l)
{
  ACE_TRACE ("ACE_Name_Request::length");
  this->transfer_.length_ = l;
}
// = Set/get the type of the message.
ACE_INT32
ACE_Name_Request::msg_type (void) const
{
  ACE_TRACE ("ACE_Name_Request::msg_type");
  return this->transfer_.msg_type_;
}
void
ACE_Name_Request::msg_type (ACE_INT32 t)
{
  ACE_TRACE ("ACE_Name_Request::msg_type");
  this->transfer_.msg_type_ = t;
}
// = Set/get the len of the name
ACE_UINT32
ACE_Name_Request::name_len (void) const
{
  ACE_TRACE ("ACE_Name_Request::name_len");
  return this->transfer_.name_len_;
}
void
ACE_Name_Request::name_len (ACE_UINT32 t)
{
  ACE_TRACE ("ACE_Name_Request::name_len");
  this->transfer_.name_len_ = t;
}
// = Set/get the len of the value
ACE_UINT32
ACE_Name_Request::value_len (void) const
{
  ACE_TRACE ("ACE_Name_Request::value_len");
  return this->transfer_.value_len_;
}
void
ACE_Name_Request::value_len (ACE_UINT32 t)
{
  ACE_TRACE ("ACE_Name_Request::value_len");
  this->transfer_.value_len_ = t;
}
// = Set/get the len of the type
ACE_UINT32
ACE_Name_Request::type_len (void) const
{
  ACE_TRACE ("ACE_Name_Request::type_len");
  return this->transfer_.type_len_;
}
void
ACE_Name_Request::type_len (ACE_UINT32 t)
{
  ACE_TRACE ("ACE_Name_Request::type_len");
  this->transfer_.type_len_ = t;
}
// = Set/get the blocking semantics.
ACE_UINT32
ACE_Name_Request::block_forever (void) const
{
  ACE_TRACE ("ACE_Name_Request::block_forever");
  return this->transfer_.block_forever_;
}
void
ACE_Name_Request::block_forever (ACE_UINT32 bs)
{
  ACE_TRACE ("ACE_Name_Request::block_forever");
  this->transfer_.block_forever_ = bs;
}
// = Set/get the timeout.
ACE_Time_Value
ACE_Name_Request::timeout (void) const
{
  ACE_TRACE ("ACE_Name_Request::timeout");
  time_t sec = ACE_Utils::truncate_cast<time_t> (this->transfer_.sec_timeout_);
  return ACE_Time_Value (sec, this->transfer_.usec_timeout_);
}
void
ACE_Name_Request::timeout (const ACE_Time_Value timeout)
{
  ACE_TRACE ("ACE_Name_Request::timeout");
  this->transfer_.sec_timeout_ = timeout.sec ();
  this->transfer_.usec_timeout_ = timeout.usec ();
}
// = Set/get the name
const ACE_WCHAR_T *
ACE_Name_Request::name (void) const
{
  ACE_TRACE ("ACE_Name_Request::name");
  return this->name_;
}
void
ACE_Name_Request::name (const ACE_WCHAR_T *t)
{
  ACE_TRACE ("ACE_Name_Request::name");
  (void) ACE_OS::memcpy (this->name_,
                         t,
                         this->name_len ());
}
// = Set/get the value
const ACE_WCHAR_T *
ACE_Name_Request::value (void) const
{
  ACE_TRACE ("ACE_Name_Request::value");
  return this->value_;
}
void
ACE_Name_Request::value (const ACE_WCHAR_T *c)
{
  ACE_TRACE ("ACE_Name_Request::value");
  (void) ACE_OS::memcpy (this->value_,
                         c,
                         this->value_len());
}
// = Set/get the type
const char *
ACE_Name_Request::type (void) const
{
  ACE_TRACE ("ACE_Name_Request::type");
  return this->type_;
}
void
ACE_Name_Request::type (const char *c)
{
  ACE_TRACE ("ACE_Name_Request::type");
  ACE_OS::strsncpy (this->type_,
                    c,
                    sizeof this->type_);
}
// Encode the transfer buffer into network byte order so that it can
// be sent to the server.
int
ACE_Name_Request::encode (void *&buf)
{
  ACE_TRACE ("ACE_Name_Request::encode");
  // Compute the length *before* doing the marshaling.
  ACE_UINT32 len = this->length ();
  size_t nv_data_len =
    (this->transfer_.name_len_ + this->transfer_.value_len_)
    / sizeof (ACE_WCHAR_T);
  for (size_t i = 0; i < nv_data_len; i++)
    this->transfer_.data_[i] =
      ACE_HTONS (this->transfer_.data_[i]);
  buf = (void *) &this->transfer_;
  this->transfer_.block_forever_ = ACE_HTONL (this->transfer_.block_forever_);
  this->transfer_.usec_timeout_  = ACE_HTONL (this->transfer_.usec_timeout_);
#if defined (ACE_LITTLE_ENDIAN)
  ACE_UINT64 secs = this->transfer_.sec_timeout_;
  ACE_CDR::swap_8 ((const char *)&secs, (char *)&this->transfer_.sec_timeout_);
#endif
  this->transfer_.length_ = ACE_HTONL (this->transfer_.length_);
  this->transfer_.msg_type_ = ACE_HTONL (this->transfer_.msg_type_);
  this->transfer_.name_len_ = ACE_HTONL (this->transfer_.name_len_);
  this->transfer_.value_len_ = ACE_HTONL (this->transfer_.value_len_);
  this->transfer_.type_len_ = ACE_HTONL (this->transfer_.type_len_);
  return len;
}
// Decode the transfer buffer into host byte byte order so that it can
// be used by the server.
int
ACE_Name_Request::decode (void)
{
  ACE_TRACE ("ACE_Name_Request::decode");
  // Decode the fixed-sized portion first.
  this->transfer_.block_forever_ = ACE_NTOHL (this->transfer_.block_forever_);
  this->transfer_.usec_timeout_  = ACE_NTOHL (this->transfer_.usec_timeout_);
#if defined (ACE_LITTLE_ENDIAN)
  ACE_UINT64 secs = this->transfer_.sec_timeout_;
  ACE_CDR::swap_8 ((const char *)&secs, (char *)&this->transfer_.sec_timeout_);
#endif
  this->transfer_.length_ = ACE_NTOHL (this->transfer_.length_);
  this->transfer_.msg_type_ = ACE_NTOHL (this->transfer_.msg_type_);
  this->transfer_.name_len_ = ACE_NTOHL (this->transfer_.name_len_);
  this->transfer_.value_len_ = ACE_NTOHL (this->transfer_.value_len_);
  this->transfer_.type_len_ = ACE_NTOHL (this->transfer_.type_len_);
  size_t nv_data_len =
    (this->transfer_.name_len_ + this->transfer_.value_len_)
    / sizeof (ACE_WCHAR_T);
  for (size_t i = 0; i < nv_data_len; i++)
    this->transfer_.data_[i] =
      ACE_NTOHS (this->transfer_.data_[i]);
  this->name_ = this->transfer_.data_;
  this->value_ = &this->name_[this->transfer_.name_len_ / sizeof (ACE_WCHAR_T)];
  this->type_ = (char *)(&this->value_[this->transfer_.value_len_ / sizeof (ACE_WCHAR_T)]);
  this->type_[this->transfer_.type_len_] = '\0';
  // Decode the variable-sized portion.
  return 0;
}
// Print out the current values of the ACE_Name_Request.
void
ACE_Name_Request::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Name_Request::dump");
  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("*******\nlength = %d\n"),
              this->length ()));
  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("message-type = ")));
  switch (this->msg_type ())
    {
    case ACE_Name_Request::BIND:
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("BIND\n")));
      break;
    case ACE_Name_Request::REBIND:
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("REBIND\n")));
      break;
    case ACE_Name_Request::RESOLVE:
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("RESOLVE\n")));
      break;
    case ACE_Name_Request::UNBIND:
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("UNBIND\n")));
      break;
    case ACE_Name_Request::LIST_NAMES:
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("LIST_NAMES\n")));
      break;
    case ACE_Name_Request::LIST_VALUES:
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("LIST_VALUES\n")));
      break;
    case ACE_Name_Request::LIST_TYPES:
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("LIST_TYPES\n")));
      break;
    case ACE_Name_Request::LIST_NAME_ENTRIES:
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("LIST_NAME_ENTRIES\n")));
      break;
    case ACE_Name_Request::LIST_VALUE_ENTRIES:
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("LIST_VALUE_ENTRIES\n")));
      break;
    case ACE_Name_Request::LIST_TYPE_ENTRIES:
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("LIST_TYPE_ENTRIES\n")));
      break;
    default:
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("<unknown type> = %d\n"),
                  this->msg_type ()));
      break;
    }
  if (this->block_forever ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("blocking forever\n")));
  else
    {
#if !defined (ACE_NLOGGING)
      ACE_Time_Value tv = this->timeout ();
#endif /* ! ACE_NLOGGING */
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("waiting for %d secs and %d usecs\n"),
                  tv.sec (),
                  tv.usec ()));
    }
  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("*******\nname_len = %d\n"),
              this->name_len ()));
  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("*******\nvalue_len = %d\n"),
              this->value_len ()));
  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("+++++++\n")));
#endif /* ACE_HAS_DUMP */
}
// Default constructor.
ACE_Name_Reply::ACE_Name_Reply (void)
{
  ACE_TRACE ("ACE_Name_Reply::ACE_Name_Reply");
  // Initialize to a known quantity.
  this->msg_type (0);
  this->errnum (0);
  this->length (sizeof this->transfer_);
}
// Create a ACE_Name_Reply message.
ACE_Name_Reply::ACE_Name_Reply (ACE_UINT32 t, ACE_UINT32 err) // Type of reply.
{
  ACE_TRACE ("ACE_Name_Reply::ACE_Name_Reply");
  this->msg_type (t);
  this->errnum (err);
  this->length (sizeof this->transfer_);
}
// Initialize length_ to avoid problems with byte-ordering.
void
ACE_Name_Reply::init (void)
{
  ACE_TRACE ("ACE_Name_Reply::init");
  this->length (sizeof this->transfer_);
}
// = Set/get the length of the encoded/decoded message.
ACE_UINT32
ACE_Name_Reply::length (void) const
{
  ACE_TRACE ("ACE_Name_Reply::length");
  return this->transfer_.length_;
}
void
ACE_Name_Reply::length (ACE_UINT32 l)
{
  ACE_TRACE ("ACE_Name_Reply::length");
  this->transfer_.length_ = l;
}
// = Set/get the type of the message.
ACE_INT32
ACE_Name_Reply::msg_type (void) const
{
  ACE_TRACE ("ACE_Name_Reply::msg_type");
  return this->transfer_.type_;
}
void
ACE_Name_Reply::msg_type (ACE_INT32 t)
{
  ACE_TRACE ("ACE_Name_Reply::msg_type");
  this->transfer_.type_ = t;
}
// Get the status of the reply (0 == success, -1 == failure).
ACE_INT32
ACE_Name_Reply::status (void) const
{
  ACE_TRACE ("ACE_Name_Reply::status");
  return this->transfer_.type_;
}
// Set the status of the reply (0 == success, -1 == failure).
void
ACE_Name_Reply::status (ACE_INT32 s)
{
  ACE_TRACE ("ACE_Name_Reply::status");
  if (s == -1)
    this->transfer_.type_ = -1;
  else
    this->transfer_.type_ = 0;
}
// = Set/get the errno of a failed reply.
ACE_UINT32
ACE_Name_Reply::errnum (void) const
{
  ACE_TRACE ("ACE_Name_Reply::errnum");
  return this->transfer_.errno_;
}
void
ACE_Name_Reply::errnum (ACE_UINT32 e)
{
  ACE_TRACE ("ACE_Name_Reply::errnum");
  this->transfer_.errno_ = e;
}
// Encode the transfer buffer into network byte order
// so that it can be sent to the client.
int
ACE_Name_Reply::encode (void *&buf)
{
  ACE_TRACE ("ACE_Name_Reply::encode");
  int len = this->length (); // Get length *before* marshaling.
  this->transfer_.length_ = ACE_HTONL (this->transfer_.length_);
  this->transfer_.type_ = ACE_HTONL (this->transfer_.type_);
  this->transfer_.errno_ = ACE_HTONL (this->transfer_.errno_);
  buf = (void *) &this->transfer_;
  return len;
}
// Decode the transfer buffer into host byte order so that it can be
// used by the client.
int
ACE_Name_Reply::decode (void)
{
  ACE_TRACE ("ACE_Name_Reply::decode");
  this->transfer_.length_ = ACE_NTOHL (this->transfer_.length_);
  this->transfer_.type_ = ACE_NTOHL (this->transfer_.type_);
  this->transfer_.errno_ = ACE_NTOHL (this->transfer_.errno_);
  return 0;
}
// Print out current values of the ACE_Name_Reply object.
void
ACE_Name_Reply::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Name_Reply::dump");
  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("*******\nlength = %d\nerrnum = %d"),
              this->length (),
              this->errnum ()));
  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("type = ")));
  switch (this->msg_type ())
    {
    case 0:
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("SUCCESS\n")));
      break;
    case -1:
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("FAILURE\n")));
      break;
    default:
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("<unknown type> = %d\n"),
                  this->msg_type ()));
      break;
    }
#endif /* ACE_HAS_DUMP */
}
ACE_END_VERSIONED_NAMESPACE_DECL

