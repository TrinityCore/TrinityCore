/* -*- C++ -*- */

//=============================================================================
/**
 *  @file    IOStream_T.h
 *
 *  $Id: IOStream_T.h 93359 2011-02-11 11:33:12Z mcorino $
 *
 *  @author James CE Johnson <jcej@lads.com>
 *  @author Jim Crossley <jim@lads.com>
 *
 * This file should not be included directly by application
 * code. Instead, it should include "ace/IOStream.h".  That's because
 * we only put some conditional compilations in that file.
 */
//=============================================================================

#ifndef ACE_IOSTREAM_T_H
#define ACE_IOSTREAM_T_H
#include /**/ "ace/pre.h"

#include "ace/IOStream.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if !defined (ACE_LACKS_ACE_IOSTREAM)

#  include "ace/INET_Addr.h"
#  include "ace/Global_Macros.h"

#  if defined (ACE_LACKS_IOSTREAM_FX)
#   include "ace/os_include/os_ctype.h"
#  endif /**/

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

#  if defined (ACE_HAS_STRING_CLASS)
template <class STREAM> STREAM & operator>> (STREAM &stream, ACE_Quoted_String &str);
template <class STREAM> STREAM & operator<< (STREAM &stream, ACE_Quoted_String &str);
#  endif /* defined (ACE_HAS_STRING_CLASS) */

template <class STREAM>
class ACE_Streambuf_T : public ACE_Streambuf
{
public:
  /**
   * We will be given a STREAM by the iostream object which creates
   * us.  See the ACE_IOStream template for how that works.  Like
   * other streambuf objects, we can be input-only, output-only or
   * both.
   */
  ACE_Streambuf_T (STREAM *peer,
                   u_int streambuf_size = ACE_STREAMBUF_SIZE,
                   int io_mode = ios::in | ios::out);

  virtual ssize_t send (char *buf, ssize_t len);

  virtual ssize_t recv (char *buf,
                        ssize_t len,
                        ACE_Time_Value *tv = 0);

  virtual ssize_t recv (char *buf,
                        ssize_t len,
                        int flags,
                        ACE_Time_Value * tv = 0);

  virtual ssize_t recv_n (char *buf,
                          ssize_t len,
                          int flags = 0,
                          ACE_Time_Value *tv = 0);

protected:
  virtual ACE_HANDLE get_handle (void);

  /// This will be our ACE_SOCK_Stream or similar object.
  STREAM *peer_;
};

/**
 * @class ACE_IOStream
 *
 * @brief A template adapter for creating an iostream-like object using
 * an ACE IPC Stream for the actual I/O.  Iostreams use an
 * underlying streambuf object for the IO interface.  The
 * iostream class and derivatives provide you with a host of
 * convenient operators that access the streambuf.
 *
 * We inherit all characteristics of iostream and your <STREAM>
 * class.  When you create a new class from this template, you
 * can use it anywhere you would have used your original
 * <STREAM> class.
 * To create an iostream for your favorite ACE IPC class (e.g.,
 * ACE_SOCK_Stream), feed that class to this template's
 * <STREAM> parameter, e.g.,
 * typedef ACE_Svc_Handler<ACE_SOCK_iostream,
 * ACE_INET_Addr, ACE_NULL_SYNCH>
 * Service_Handler;
 * Because the operators in the iostream class are not virtual,
 * you cannot easily provide overloads in your custom
 * ACE_IOStream classes.  To make these things work correctly,
 * you need to overload ALL operators of the ACE_IOStream you
 * create. I've attempted to do that here to make things easier
 * for you but there are no guarantees.
 * In the iostream.cpp file is an example of why it is necessary
 * to overload all of the get/put operators when you want to
 * customize only one or two.
 */
template <class STREAM>
class ACE_IOStream : public iostream, public STREAM
{
public:
  // = Initialization and termination methods.
  ACE_IOStream (STREAM &stream,
                  u_int streambuf_size = ACE_STREAMBUF_SIZE);

  /**
   * The default constructor.  This will initialize your STREAM and
   * then setup the iostream baseclass to use a custom streambuf based
   * on STREAM.
   */
  ACE_IOStream (u_int streambuf_size = ACE_STREAMBUF_SIZE);

  /// We have to get rid of the <streambuf_> ourselves since we gave it
  /// to the <iostream> base class;
  virtual ~ACE_IOStream (void);

  /// The only ambiguity in the multiple inheritance is the <close>
  /// function.
  virtual int close (void);

  /**
   * Returns 1 if we're at the end of the <STREAM>, i.e., if the
   * connection has closed down or an error has occurred, else 0.
   * Under the covers, <eof> calls the streambuf's @a timeout function
   * which will reset the timeout flag.  As as result, you should save
   * the return of <eof> and check it instead of calling <eof>
   * successively.
   */
  int eof (void) const;

#  if defined (ACE_HAS_STRING_CLASS)
  /**
   * A simple string operator.  The base <iostream> has them for char*
   * but that isn't always the best thing for a <String>.  If we don't
   * provide our own here, we may not get what we want.
   */
  virtual ACE_IOStream<STREAM> &operator>> (ACE_IOStream_String &v);

  /// The converse of the <String::put> operator.
  virtual ACE_IOStream<STREAM> &operator<< (ACE_IOStream_String &v);

#  endif /* ACE_HAS_STRING_CLASS */
  // = Using the macros to provide get/set operators.
  GETPUT_FUNC_SET (ACE_IOStream<STREAM>)

#  if defined (ACE_LACKS_IOSTREAM_FX)
  virtual int ipfx (int noskip = 0)
    {
      if (good ())
        {
          if (tie () != 0)
             tie ()->flush ();
          if (!noskip && flags () & skipws)
            {
              int ch;
              while (isspace (ch = rdbuf ()->sbumpc ()))
                continue;
              if (ch != EOF)
                  rdbuf ()->sputbackc (ch);
            }
          if (good ())
              return 1;
        }
#    if !defined (ACE_WIN32)
      // MS VC++ 5.0 doesn't declare setstate.
      setstate (failbit);
#    endif /* !ACE_WIN32 */
      return (0);
    }
  virtual int ipfx0 (void)         {  return ipfx (0); }  // Optimized ipfx(0)
  virtual int ipfx1 (void)                                // Optimized ipfx(1)
    {
      if (good ())
        {
          if (tie () != 0)
             tie ()->flush ();
          if (good ())
              return 1;
        }
#    if !defined (ACE_WIN32)
      // MS VC++ 5.0 doesn't declare setstate.
      setstate (failbit);
#    endif /* !ACE_WIN32 */
      return (0);
    }
  virtual void isfx (void) {  return; }
  virtual int opfx (void)
    {
      if (good () && tie () != 0)
        tie ()->flush ();
      return good ();
    }
  virtual void osfx (void) {  if (flags () & unitbuf) flush (); }
#  else
#    if defined (__GNUC__)
  virtual int ipfx0 (void) { return iostream::ipfx0 (); }  // Optimized ipfx(0)
  virtual int ipfx1 (void) { return iostream::ipfx1 (); }  // Optimized ipfx(1)
#    else
  virtual int ipfx0 (void) { return iostream::ipfx (0); }
  virtual int ipfx1 (void) { return iostream::ipfx (1); }
#    endif /* __GNUC__ */
  virtual int ipfx (int need = 0) {  return iostream::ipfx (need); }
  virtual void isfx (void)        {  iostream::isfx (); }
  virtual int opfx (void)         {  return iostream::opfx (); }
  virtual void osfx (void)        {  iostream::osfx (); }
#  endif /* ACE_LACKS_IOSTREAM_FX */

  /// Allow the programmer to provide a timeout for read operations.
  /// Give it a pointer to NULL to block forever.
  ACE_IOStream<STREAM> & operator>> (ACE_Time_Value *&tv);

protected:
  /// This is where all of the action takes place.  The streambuf_ is
  /// the interface to the underlying STREAM.
  ACE_Streambuf_T<STREAM> *streambuf_;

private:
  // = Private methods.

  // We move these into the private section so that they cannot be
  // used by the application programmer.  This is necessary because
  // streambuf_ will be buffering IO on the STREAM object.  If these
  // functions were used in your program, there is a danger of getting
  // the datastream out of sync.
  ACE_UNIMPLEMENTED_FUNC (ssize_t send (...))
  ACE_UNIMPLEMENTED_FUNC (ssize_t recv (...))
  ACE_UNIMPLEMENTED_FUNC (ssize_t send_n (...))
  ACE_UNIMPLEMENTED_FUNC (ssize_t recv_n (...))
};

/**
 * @class ACE_SOCK_Dgram_SC
 *
 * @brief "Dgram_SC" is short for "Datagram Self-Contained."
 *
 * Datagrams don't have the notion of a "peer".  Each send and
 * receive on a datagram can go to a different peer if you want.
 * If you're using datagrams for stream activity, you probably
 * want 'em all to go to (and come from) the same place.  That's
 * what this class is for.  Here, we keep an address object so
 * that we can remember who last sent us data.  When we write
 * back, we're then able to write back to that same address.
 */
template <class STREAM>
class ACE_SOCK_Dgram_SC : public STREAM
{
public:
  ACE_SOCK_Dgram_SC (void);
  ACE_SOCK_Dgram_SC (STREAM &source,
                     ACE_INET_Addr &dest);
  ssize_t send_n (char *buf, ssize_t len);
  ssize_t recv  (char *buf,
                 ssize_t len,
                 ACE_Time_Value *tv = 0);
  ssize_t recv (char *buf,
                ssize_t len,
                int flags,
                ACE_Time_Value *tv = 0);
  ssize_t recv_n (char *buf,
                  ssize_t len,
                  int flags = 0,
                  ACE_Time_Value *tv = 0);
  int get_remote_addr (ACE_INET_Addr &addr) const;

protected:
  ACE_INET_Addr peer_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#  if defined (__ACE_INLINE__)
#    include "ace/IOStream_T.inl"
#  endif /* __ACE_INLINE__ */

#  if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#    include "ace/IOStream_T.cpp"
#  endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#  if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#    pragma implementation ("IOStream_T.cpp")
#  endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */
#endif /* ACE_LACKS_ACE_IOSTREAM */

#include /**/ "ace/post.h"
#endif /* ACE_IOSTREAM_T_H */
