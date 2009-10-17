// -*- C++ -*-

//=============================================================================
/**
 *  @file    IOStream.h
 *
 *  $Id: IOStream.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author James CE Johnson <jcej@lads.com>
 *  @author Jim Crossley <jim@lads.com>
 */
//=============================================================================

#ifndef ACE_IOSTREAM_H
#define ACE_IOSTREAM_H
#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

// Needed on Windows for streambuf
// FUZZ: disable check_for_streams_include
#include "ace/streams.h"

// This is a temporary restriction - ACE_IOStream is only enabled if the
// compiler does not supply the standard C++ library (and standard iostreams)
// or, if it does, the platform is explicitly set to use old iostreams
// by its config.h file.
// This restriction is recorded in Bugzilla entry 857.
#if defined (ACE_HAS_STANDARD_CPP_LIBRARY) && (ACE_HAS_STANDARD_CPP_LIBRARY == 1)
#  if !defined (ACE_USES_OLD_IOSTREAMS) && !defined (ACE_LACKS_ACE_IOSTREAM)
#    define ACE_LACKS_ACE_IOSTREAM
#  endif /* !ACE_USES_OLD_IOSTREAMS && !ACE_LACKS_ACE_IOSTREAM */
#endif /* ACE_HAS_STANDARD_CPP_LIBRARY */

#if !defined (ACE_LACKS_ACE_IOSTREAM)

#  if defined (ACE_HAS_STRING_CLASS)
#    if defined (ACE_WIN32) && defined (_MSC_VER)
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
typedef CString ACE_IOStream_String;
ACE_END_VERSIONED_NAMESPACE_DECL
#    else
#      if !defined (ACE_HAS_STDCPP_STL_INCLUDES)
#include /**/ <String.h>
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
typedef String ACE_IOStream_String;
ACE_END_VERSIONED_NAMESPACE_DECL
#      else
#        include /**/ <string>

#        if defined(ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB)
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
typedef std::string ACE_IOStream_String;
ACE_END_VERSIONED_NAMESPACE_DECL
#        else
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
typedef string ACE_IOStream_String;
ACE_END_VERSIONED_NAMESPACE_DECL
#        endif /* ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB */
#      endif /* ! ACE_HAS_STDCPP_STL_INCLUDES */
#    endif /* ACE_WIN32 && defined (_MSC_VER) */

#    if defined (__DECCXX_VER)
#      if __DECCXX_VER < 50700000
#        include /**/ <stl_macros>
#      else
#        include /**/ <stdcomp>
#      endif /* __DECCXX_VER < 50700000 */
#    endif /* __DECCXX_VER */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

class ACE_Export ACE_Quoted_String : public ACE_IOStream_String
{
public:
  inline ACE_Quoted_String (void) { *this = ""; }
  inline ACE_Quoted_String (const char *c) { *this = ACE_IOStream_String (c); }
  inline ACE_Quoted_String (const ACE_IOStream_String &s) { *this = s; }
  inline ACE_Quoted_String &operator= (const ACE_IOStream_String& s)
  {
    return (ACE_Quoted_String &) ACE_IOStream_String::operator= (s);
  }
  inline ACE_Quoted_String &operator = (const char c) {
    return (ACE_Quoted_String &) ACE_IOStream_String::operator= (c);
  }
  inline ACE_Quoted_String &operator = (const char *c) {
    return (ACE_Quoted_String &) ACE_IOStream_String::operator= (c);
  }
  inline bool operator < (const ACE_Quoted_String &s) const {
    return *(ACE_IOStream_String *) this < (ACE_IOStream_String) s;
  }
#    if defined (ACE_WIN32) && defined (_MSC_VER)
  inline int length (void) { return this->GetLength (); }
#    endif /* ACE_WIN32 && defined (_MSC_VER) */
};

ACE_END_VERSIONED_NAMESPACE_DECL

#  endif /* ACE_HAS_STRING_CLASS */

#  include "ace/Time_Value.h"
#  include "ace/os_include/sys/os_types.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Streambuf
 *
 * @brief Create your custom streambuf by providing and ACE_*_Stream
 * object to this template.  I have tested it with
 * ACE_SOCK_Stream and it should work fine for others as well.
 *
 * For any iostream object, the real work is done by the
 * underlying streambuf class.  That is what we create here.
 * A streambuf has an internal buffer area into which data is
 * read and written as the iostream requests and provides data.
 * At some point during the read process, the iostream will
 * realize that the streambuf has no more data.  The underflow
 * function of the streambuf is then called.
 * Likewise, during the write process, the iostream will
 * eventually notice that the streabuf's buffer has become full
 * and will invoke the overflow function.
 * The empty/full state of the read/write "buffers" are
 * controled by two sets pointers.  One set is dedicated to
 * read, the other to write.  These pointers, in turn, reference
 * a common buffer that is to be shared by both read and write
 * operations.  It is this common buffer to which data is
 * written and from which it is read.
 * The common buffer is used by functions of the streambuf as
 * well as the iostream.  Because of this and the fact that it
 * is "shared" by both read and write operators, there is a
 * danger of data corruption if read and write operations are
 * allowed to take place "at the same time".
 * To prevent data corruption, we manipulate the read and write
 * pointer sets so that the streambuf is in either a read-mode
 * or write-mode at all times and can never be in both modes at
 * the same time.
 * In the constructor: set the read and write sets to NULL This
 * causes the underflow or overflow operators to be invoked at
 * the first IO activity of the iostream.
 * In the underflow function we arrange for the common buffer to
 * reference our read buffer and for the write pointer set to be
 * disabled.  If a write operation is performed by the iostream
 * this will cause the overflow function to be invoked.
 * In the overflow function we arrange for the common buffer to
 * reference our write buffer and for the read pointer set to be
 * disabled.  This causes the underflow function to be invoked
 * when the iostream "changes our mode".
 * The overflow function will also invoke the send_n function to
 * flush the buffered data to our peer.  Similarly, the sync and
 * syncout functions will cause send_n to be invoked to send the
 * data.
 * Since socket's and the like do not support seeking, there can
 * be no method for "syncing" the input.  However, since we
 * maintain separate read/write buffers, no data is lost by
 * "syncing" the input.  It simply remains buffered.
 */
class ACE_Export ACE_Streambuf : public streambuf
{
public:

  /**
   * If the default allocation strategey were used the common buffer
   * would be deleted when the object destructs.  Since we are
   * providing separate read/write buffers, it is up to us to manage
   * their memory.
   */
  virtual ~ACE_Streambuf (void);

  /// Get the current Time_Value pointer and provide a new one.
  ACE_Time_Value *recv_timeout (ACE_Time_Value *tv = 0);

  /**
   * Use this to allocate a new/different buffer for put operations.
   * If you do not provide a buffer pointer, one will be allocated.
   * That is the preferred method.  If you do provide a buffer, the
   * size must match that being used by the get buffer.  If
   * successful, you will receive a pointer to the current put buffer.
   * It is your responsibility to delete this memory when you are done
   * with it.
   */
  char *reset_put_buffer (char *newBuffer = 0,
                          u_int _streambuf_size = 0,
                          u_int _pptr = 0 );

  /// Return the number of bytes to be 'put' onto the stream media.
  ///    pbase + put_avail = pptr
  u_int put_avail (void);

  /**
   * Use this to allocate a new/different buffer for get operations.
   * If you do not provide a buffer pointer, one will be allocated.
   * That is the preferred method.  If you do provide a buffer, the
   * size must match that being used by the put buffer.  If
   * successful, you will receive a pointer to the current get buffer.
   * It is your responsibility to delete this memory when you are done
   * with it.
   */
  char *reset_get_buffer (char *newBuffer = 0,
                          u_int _streambuf_size = 0,
                          u_int _gptr = 0,
                          u_int _egptr = 0);

  /// Return the number of bytes not yet gotten.  eback + get_waiting =
  /// gptr
  u_int get_waiting (void);

  /// Return the number of bytes in the get area (includes some already
  /// gotten); eback + get_avail = egptr
  u_int get_avail (void);

  /// Query the streambuf for the size of its buffers.
  u_int streambuf_size (void);

  /// Did we take an error because of an IO operation timeout?
  /// @note Invoking this resets the flag.
  u_char timeout (void);

protected:
  ACE_Streambuf (u_int streambuf_size,
                 int io_mode);

  /// Sync both input and output. See syncin/syncout below for
  /// descriptions.
  virtual int sync (void);

  // = Signatures for the underflow/overflow discussed above.
  virtual int underflow (void);

  /// The overflow function receives the character which caused the
  /// overflow.
  virtual int overflow (int c = EOF);

  /// Resets the <base> pointer and streambuf mode.  This is used
  /// internally when get/put buffers are allocatd.
  void reset_base (void);

protected:
  // = Two pointer sets for manipulating the read/write areas.
  char *eback_saved_;
  char *gptr_saved_;
  char *egptr_saved_;
  char *pbase_saved_;
  char *pptr_saved_;
  char *epptr_saved_;

  // = With cur_mode_ we keep track of our current IO mode.

  // This helps us to optimize the underflow/overflow functions.
  u_char cur_mode_;
  const u_char get_mode_;
  const u_char put_mode_;

  /// mode tells us if we're working for an istream, ostream, or
  /// iostream.
  int mode_;

  /// This defines the size of the input and output buffers.  It can be
  /// set by the object constructor.
  const u_int streambuf_size_;

  /// Did we take an error because of an IO operation timeout?
  u_char timeout_;

  /// We want to allow the user to provide Time_Value pointers to
  /// prevent infinite blocking while waiting to receive data.
  ACE_Time_Value recv_timeout_value_;
  ACE_Time_Value *recv_timeout_;

  /**
   * syncin is called when the input needs to be synced with the
   * source file.  In a filebuf, this results in the <seek> system
   * call being used.  We can't do that on socket-like connections, so
   * this does basically nothing.  That's safe because we have a
   * separate read buffer to maintain the already-read data.  In a
   * filebuf, the single common buffer is used forcing the <seek>
   * call.
   */
  int syncin (void);

  /// syncout is called when the output needs to be flushed.  This is
  /// easily done by calling the peer's send_n function.
  int syncout (void);

  /// flushbuf is the worker of syncout.  It is a separate function
  /// because it gets used sometimes in different context.
  int flushbuf (void);

  /**
   * fillbuf is called in a couple of places.  This is the worker of
   * underflow.  It will attempt to fill the read buffer from the
   * peer.
   */
  int fillbuf (void);

  /**
   * Used by fillbuf and others to get exactly one byte from the peer.
   * recv_n is used to be sure we block until something is available.
   * It is virtual because we really need to override it for
   * datagram-derived objects.
   */
  virtual int get_one_byte (void);

  /**
   * Stream connections and "unconnected connections" (ie --
   * datagrams) need to work just a little differently.  We derive
   * custom Streambuf objects for them and provide these functions at
   * that time.
   */
  virtual ssize_t send (char *buf,
                        ssize_t len) = 0;
  virtual ssize_t recv (char *buf,
                        ssize_t len,
                        ACE_Time_Value *tv = 0) = 0;
  virtual ssize_t recv (char *buf,
                        ssize_t len,
                        int flags,
                        ACE_Time_Value *tv = 0) = 0;
  virtual ssize_t recv_n (char *buf,
                          ssize_t len,
                          int flags = 0,
                          ACE_Time_Value *tv = 0) = 0;

  virtual ACE_HANDLE get_handle (void);

#  if defined (ACE_HAS_STANDARD_CPP_LIBRARY) && (ACE_HAS_STANDARD_CPP_LIBRARY != 0) && !defined (ACE_USES_OLD_IOSTREAMS)
  char *base (void) const
    {
      return cur_mode_ == get_mode_ ? eback_saved_
        : cur_mode_ == put_mode_ ? pbase_saved_
        : 0;
    }
  char *ebuf (void) const
    {
      return cur_mode_ == 0 ? 0 : base () + streambuf_size_;
    }

  int blen (void) const
    {
      return streambuf_size_;
    }

  void setb (char* b, char* eb, int /* a */=0)
    {
      setbuf (b, (eb - b));
    }

  int out_waiting (void)
    {
      return pptr () - pbase ();
    }
#  endif /* ACE_HAS_STANDARD_CPP_LIBRARY */
};

ACE_END_VERSIONED_NAMESPACE_DECL

///////////////////////////////////////////////////////////////////////////

// These typedefs are provided by G++ (on some systems?) without the
// trailing '_'.  Since we can't count on 'em, I've defined them to
// what GNU wants here.
//
typedef ios& (*__manip_)(ios&);
typedef istream& (*__imanip_)(istream&);
typedef ostream& (*__omanip_)(ostream&);

// Trying to do something like is shown below instead of using the
// __*manip typedefs causes Linux do segfault when "<<endl" is done.
//
//        virtual MT& operator<<(ios& (*func)(ios&))  { (*func)(*this); return *this; }

// This macro defines the get operator for class MT into datatype DT.
// We will use it below to quickly override most (all?)  iostream get
// operators.  Notice how the <ipfx> and <isfx> functions are used.

#define GET_SIG(MT,DT)          inline virtual MT& operator>> (DT v)
#  if (defined (__SUNPRO_CC) && __SUNPRO_CC > 0x510)
#define GET_CODE {                      \
        if (ipfx (0))                                   \
        {                                               \
                (*((istream*)this)) >> (v);             \
        }                                               \
        isfx ();                                        \
        return *this;                                   \
        }
#  else
#define GET_CODE {                      \
        if (ipfx (0))                                   \
        {                                               \
                iostream::operator>> (v);               \
        }                                               \
        isfx ();                                        \
        return *this;                                   \
        }
#  endif
#define GET_PROT(MT,DT,CODE)    GET_SIG(MT,DT)  CODE
#define GET_FUNC(MT,DT)         GET_PROT(MT,DT,GET_CODE)

// This macro defines the put operator for class MT into datatype DT.
// We will use it below to quickly override most (all?)  iostream put
// operators.  Notice how the <opfx> and <osfx> functions are used.

#define PUT_SIG(MT,DT)          inline virtual MT& operator<< (DT v)
#  if (defined (__SUNPRO_CC) && __SUNPRO_CC > 0x510)
#define PUT_CODE {                      \
        if (opfx ())                                    \
        {                                               \
                (*((ostream *) this)) << (v);            \
        }                                               \
        osfx ();                                        \
        return *this;                                   \
        }
#  else
#define PUT_CODE {                      \
        if (opfx ())                                    \
        {                                               \
                iostream::operator<< (v);               \
        }                                               \
        osfx ();                                        \
        return *this;                                   \
        }
#  endif
#define PUT_PROT(MT,DT,CODE)    PUT_SIG(MT,DT)  CODE
#define PUT_FUNC(MT,DT)         PUT_PROT(MT,DT,PUT_CODE)

// These are necessary in case somebody wants to derive from us and
// override one of these with a custom approach.

#  if defined (ACE_LACKS_CHAR_RIGHT_SHIFTS)
#define GET_FUNC_SET0(MT,CODE,CODE2) \
        GET_PROT(MT,short &,CODE) \
        GET_PROT(MT,u_short &,CODE) \
        GET_PROT(MT,int &,CODE) \
        GET_PROT(MT,u_int &,CODE) \
        GET_PROT(MT,long &,CODE) \
        GET_PROT(MT,u_long &,CODE) \
        GET_PROT(MT,float &,CODE) \
        GET_PROT(MT,double &,CODE) \
        inline virtual MT& operator>>(__omanip_ func) CODE2 \
        inline virtual MT& operator>>(__manip_ func)  CODE2
#  else
#define GET_FUNC_SET0(MT,CODE,CODE2) \
        GET_PROT(MT,short &,CODE) \
        GET_PROT(MT,u_short &,CODE) \
        GET_PROT(MT,int &,CODE) \
        GET_PROT(MT,u_int &,CODE) \
        GET_PROT(MT,long &,CODE) \
        GET_PROT(MT,u_long &,CODE) \
        GET_PROT(MT,float &,CODE) \
        GET_PROT(MT,double &,CODE) \
        GET_PROT(MT,char &,CODE) \
        GET_PROT(MT,u_char &,CODE) \
        GET_PROT(MT,char *,CODE) \
        GET_PROT(MT,u_char *,CODE) \
        inline virtual MT& operator>>(__omanip_ func) CODE2 \
        inline virtual MT& operator>>(__manip_ func)  CODE2
#  endif

#define PUT_FUNC_SET0(MT,CODE,CODE2) \
        PUT_PROT(MT,short,CODE) \
        PUT_PROT(MT,u_short,CODE) \
        PUT_PROT(MT,int,CODE) \
        PUT_PROT(MT,u_int,CODE) \
        PUT_PROT(MT,long,CODE) \
        PUT_PROT(MT,u_long,CODE) \
        PUT_PROT(MT,float,CODE) \
        PUT_PROT(MT,double,CODE) \
        PUT_PROT(MT,char,CODE) \
        PUT_PROT(MT,u_char,CODE) \
        PUT_PROT(MT,const char *,CODE) \
        PUT_PROT(MT,u_char *,CODE) \
        PUT_PROT(MT,void *,CODE) \
        inline virtual MT& operator<<(__omanip_ func) CODE2 \
        inline virtual MT& operator<<(__manip_ func)  CODE2

#  if defined (ACE_LACKS_SIGNED_CHAR)
  #define GET_FUNC_SET1(MT,CODE,CODE2) GET_FUNC_SET0(MT,CODE,CODE2)
  #define PUT_FUNC_SET1(MT,CODE,CODE2) PUT_FUNC_SET0(MT,CODE,CODE2)
#  else
  #define GET_FUNC_SET1(MT,CODE,CODE2) \
          GET_PROT(MT,signed char &,CODE) \
          GET_PROT(MT,signed char *,CODE) \
          GET_FUNC_SET0(MT,CODE,CODE2)

  #define PUT_FUNC_SET1(MT,CODE,CODE2) \
          PUT_FUNC(MT,signed char) \
          PUT_FUNC(MT,const signed char *) \
          PUT_FUNC_SET0(MT,CODE,CODE2)
#  endif /* ACE_LACKS_SIGNED_CHAR */

#define GET_MANIP_CODE  { if (ipfx ()) { (*func) (*this); } isfx (); return *this; }
#define PUT_MANIP_CODE  { if (opfx ()) { (*func) (*this); } osfx (); return *this; }

#define GET_FUNC_SET(MT)        GET_FUNC_SET1(MT,GET_CODE,GET_MANIP_CODE)
#define PUT_FUNC_SET(MT)        PUT_FUNC_SET1(MT,PUT_CODE,PUT_MANIP_CODE)
#define GETPUT_FUNC_SET(MT)     GET_FUNC_SET(MT) PUT_FUNC_SET(MT)

#define GET_SIG_SET(MT)         GET_FUNC_SET1(MT,= 0;,= 0;)
#define PUT_SIG_SET(MT)         PUT_FUNC_SET1(MT,= 0;,= 0;)
#define GETPUT_SIG_SET(MT)      GET_SIG_SET(MT) PUT_SIG_SET(MT)

// Include the templates here.
#  include "ace/IOStream_T.h"
#endif /* !ACE_LACKS_ACE_IOSTREAM && ACE_USES_OLD_IOSTREAMS */

#include /**/ "ace/post.h"
#endif /* ACE_IOSTREAM_H */

