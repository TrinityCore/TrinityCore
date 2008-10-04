// $Id: IOStream_T.cpp 80826 2008-03-04 14:51:23Z wotte $

#ifndef ACE_IOSTREAM_T_CPP
#define ACE_IOSTREAM_T_CPP

#include "ace/IOStream_T.h"
#include "ace/OS_Memory.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if !defined (ACE_LACKS_ACE_IOSTREAM)

#if !defined (__ACE_INLINE__)
#include "ace/IOStream_T.inl"
#endif /* !__ACE_INLINE__ */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// We will be given a STREAM by the iostream object which creates us.
// See the ACE_IOStream template for how that works.  Like other
// streambuf objects, we can be input-only, output-only or both.

template <class STREAM>
ACE_Streambuf_T<STREAM>::ACE_Streambuf_T (STREAM *peer,
                                          u_int streambuf_size,
                                          int io_mode)
  : ACE_Streambuf (streambuf_size, io_mode),
    peer_ (peer)
{
  // A streambuf allows for unbuffered IO where every character is
  // read as requested and written as provided.  To me, this seems
  // terribly inefficient for socket-type operations, so I've disabled
  // it.  All of the work would be done by the underflow/overflow
  // functions anyway and I haven't implemented anything there to
  // support unbuffered IO.

#if !defined (ACE_LACKS_UNBUFFERED_STREAMBUF)
  this->unbuffered (0);
#endif /* ! ACE_LACKS_UNBUFFERED_STREAMBUF */

  // Linebuffered is similar to unbuffered.  Again, I don't have any
  // need for this and I don't see the advantage.  I believe this
  // would have to be supported by underflow/overflow to be effective.
#if !defined (ACE_LACKS_LINEBUFFERED_STREAMBUF)
  this->linebuffered (0);
#endif /* ! ACE_LACKS_LINEBUFFERED_STREAMBUF */
}

template <class STREAM> ssize_t
ACE_Streambuf_T<STREAM>::send (char *buf, ssize_t len)
{
  return peer_->send_n (buf,len);
}

template <class STREAM> ssize_t
ACE_Streambuf_T<STREAM>::recv (char *buf,
                               ssize_t len,
                               ACE_Time_Value *tv)
{
  return this->recv (buf, len, 0, tv);
}

template <class STREAM> ssize_t
ACE_Streambuf_T<STREAM>::recv (char *buf,
                               ssize_t len,
                               int flags,
                               ACE_Time_Value * tv)
{
  this->timeout_ = 0;
  errno = ESUCCESS;
  ssize_t rval = peer_->recv (buf, len, flags, tv);
  if (errno == ETIME)
    this->timeout_ = 1;
  return rval;
}

template <class STREAM> ssize_t
ACE_Streambuf_T<STREAM>::recv_n (char *buf,
                                 ssize_t len,
                                 int flags,
                                 ACE_Time_Value *tv)
{
  this->timeout_ = 0;
  errno = ESUCCESS;
  ssize_t rval = peer_->recv_n (buf, len, flags, tv);
  if (errno == ETIME)
    this->timeout_ = 1;
  return rval;
}

template <class STREAM> ACE_HANDLE
ACE_Streambuf_T<STREAM>::get_handle (void)
{
  return peer_ ? peer_->get_handle () : 0;
}

// The typical constructor.  This will initiailze your STREAM and then
// setup the iostream baseclass to use a custom streambuf based on
// STREAM.

template <class STREAM>
ACE_IOStream<STREAM>::ACE_IOStream (STREAM &stream,
                                    u_int streambuf_size)
  : iostream (0),
    STREAM (stream)
{
  ACE_NEW (streambuf_,
           ACE_Streambuf_T<STREAM> ((STREAM *) this,
                                    streambuf_size));
  iostream::init (this->streambuf_);
}

template <class STREAM>
ACE_IOStream<STREAM>::ACE_IOStream (u_int streambuf_size)
  : iostream (0)
{
  ACE_NEW (this->streambuf_,
           ACE_Streambuf_T<STREAM> ((STREAM *) this,
                                    streambuf_size));
  iostream::init (this->streambuf_);
}

// We have to get rid of the streambuf_ ourselves since we gave it to
// iostream ()

template <class STREAM>
ACE_IOStream<STREAM>::~ACE_IOStream (void)
{
  delete this->streambuf_;
}

// The only ambituity in the multiple inheritance is the close ()
// function.

template <class STREAM> int
ACE_IOStream<STREAM>::close (void)
{
  return STREAM::close ();
}

template <class STREAM> ACE_IOStream<STREAM> &
ACE_IOStream<STREAM>::operator>> (ACE_Time_Value *&tv)
{
  ACE_Time_Value *old_tv = this->streambuf_->recv_timeout (tv);
  tv = old_tv;
  return *this;
}

#if defined (ACE_HAS_STRING_CLASS)

// A simple string operator.  The base iostream has 'em for char* but
// that isn't always the best thing for a String.  If we don't provide
// our own here, we may not get what we want.

template <class STREAM> ACE_IOStream<STREAM> &
ACE_IOStream<STREAM>::operator>> (ACE_IOStream_String &v)
{
  if (ipfx0 ())
    {
      char c;
      this->get (c);

      for (v = c;
           this->get (c) && !isspace (c);
           v += c)
        continue;
    }

  isfx ();

  return *this;
}

template <class STREAM> ACE_IOStream<STREAM> &
ACE_IOStream<STREAM>::operator<< (ACE_IOStream_String &v)
{
  if (opfx ())
    {
#if defined (ACE_WIN32) && defined (_MSC_VER)
      for (int i = 0; i < v.GetLength (); ++i)
#else
      for (u_int i = 0; i < (u_int) v.length (); ++i)
#endif /* ACE_WIN32 && defined (_MSC_VER) */
        this->put (v[i]);
    }

  osfx ();

  return *this;
}

// A more clever put operator for strings that knows how to deal with
// quoted strings containing back-quoted quotes.

template <class STREAM> STREAM &
operator>> (STREAM &stream,
            ACE_Quoted_String &str)
{
  char c;

  if (!(stream >> c)) // eat space up to the first char
    // stream.set (ios::eofbit|ios::failbit);
    return stream;

  str = "";     // Initialize the string

  // if we don't have a quote, append until we see space
  if (c != '"')
    for (str = c; stream.get (c) && !isspace (c); str += c)
      continue;
  else
    for (; stream.get (c) && c != '"'; str += c)
      if (c == '\\')
        {
          stream.get (c);
          if (c != '"')
            str += '\\';
        }

  return stream;
}

template <class STREAM> STREAM &
operator<< (STREAM &stream,
            ACE_Quoted_String &str)
{
  stream.put ('"');

  for (u_int i = 0; i < str.length (); ++i)
    {
      if (str[i] == '"')
        stream.put ('\\');
      stream.put (str[i]);
    }

  stream.put ('"');

  return stream;
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_STRING_CLASS */
#endif /* ACE_LACKS_ACE_IOSTREAM */
#endif /* ACE_IOSTREAM_T_CPP */
