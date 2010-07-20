// -*- C++ -*-

#include "SSL_Asynch_BIO.h"

#if OPENSSL_VERSION_NUMBER > 0x0090581fL && ((defined (ACE_WIN32) && !defined (ACE_HAS_WINCE)) || (defined (ACE_HAS_AIO_CALLS)))

#include "SSL_Asynch_Stream.h"
#include "ace/OS_NS_string.h"
#include "ace/Truncate.h"

ACE_RCSID (ACE_SSL,
           SSL_Asynch_BIO,
           "$Id: SSL_Asynch_BIO.cpp 82574 2008-08-08 19:35:06Z parsons $")

#if (defined (ACE_HAS_VERSIONED_NAMESPACE) && ACE_HAS_VERSIONED_NAMESPACE == 1)
# define ACE_ASYNCH_BIO_WRITE_NAME ACE_PREPROC_CONCATENATE(ACE_VERSIONED_NAMESPACE_NAME, _ACE_Asynch_BIO_write)
# define ACE_ASYNCH_BIO_READ_NAME  ACE_PREPROC_CONCATENATE(ACE_VERSIONED_NAMESPACE_NAME, _ACE_Asynch_BIO_read)
# define ACE_ASYNCH_BIO_PUTS_NAME  ACE_PREPROC_CONCATENATE(ACE_VERSIONED_NAMESPACE_NAME, _ACE_Asynch_BIO_puts)
# define ACE_ASYNCH_BIO_CTRL_NAME  ACE_PREPROC_CONCATENATE(ACE_VERSIONED_NAMESPACE_NAME, _ACE_Asynch_BIO_ctrl)
# define ACE_ASYNCH_BIO_NEW_NAME   ACE_PREPROC_CONCATENATE(ACE_VERSIONED_NAMESPACE_NAME, _ACE_Asynch_BIO_new)
# define ACE_ASYNCH_BIO_FREE_NAME  ACE_PREPROC_CONCATENATE(ACE_VERSIONED_NAMESPACE_NAME, _ACE_Asynch_BIO_free)
#else
# define ACE_ASYNCH_BIO_WRITE_NAME ACE_Asynch_BIO_write
# define ACE_ASYNCH_BIO_READ_NAME  ACE_Asynch_BIO_read
# define ACE_ASYNCH_BIO_PUTS_NAME  ACE_Asynch_BIO_puts
# define ACE_ASYNCH_BIO_CTRL_NAME  ACE_Asynch_BIO_ctrl
# define ACE_ASYNCH_BIO_NEW_NAME   ACE_Asynch_BIO_new
# define ACE_ASYNCH_BIO_FREE_NAME  ACE_Asynch_BIO_free
#endif  /* ACE_HAS_VERSIONED_NAMESPACE == 1 */

/**
 * @name OpenSSL BIO Helper Methods for use with ACE's Asynchronous
 *       SSL I/O support.
 */
//@{
extern "C"
{
  int  ACE_ASYNCH_BIO_WRITE_NAME (BIO *pBIO, const char *buf, int len);
  int  ACE_ASYNCH_BIO_READ_NAME  (BIO *pBIO, char *buf, int len);
  int  ACE_ASYNCH_BIO_PUTS_NAME  (BIO *pBIO, const char *str);
  long ACE_ASYNCH_BIO_CTRL_NAME  (BIO *pBIO, int cmd, long arg1, void *arg2);
  int  ACE_ASYNCH_BIO_NEW_NAME   (BIO *pBIO);
  int  ACE_ASYNCH_BIO_FREE_NAME  (BIO *pBIO);
}
//@}

#define BIO_TYPE_ACE  ( 21 | BIO_TYPE_SOURCE_SINK )

static BIO_METHOD methods_ACE =
  {
    BIO_TYPE_ACE, // BIO_TYPE_PROXY_SERVER,
    "ACE_Asynch_BIO",
    ACE_ASYNCH_BIO_WRITE_NAME,
    ACE_ASYNCH_BIO_READ_NAME,
    ACE_ASYNCH_BIO_PUTS_NAME,
    0, /* ACE_ASYNCH_BIO_GETS_NAME, */
    ACE_ASYNCH_BIO_CTRL_NAME,
    ACE_ASYNCH_BIO_NEW_NAME,
    ACE_ASYNCH_BIO_FREE_NAME,
    0
  };

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

BIO *
ACE_SSL_make_BIO (void * ssl_asynch_stream)
{
  BIO * const pBIO = BIO_new (&methods_ACE);

  if (pBIO)
    BIO_ctrl (pBIO,
              BIO_C_SET_FILE_PTR,
              0,
              ssl_asynch_stream);

  return pBIO;
}

/**
 * @struct @c ACE_SSL_Asynch_Stream_Accessor
 *
 * @brief Privileged @c ACE_SSL_Asynch_Stream accessor.
 *
 * This structure is a @c friend to the @c ACE_SSL_Asynch_Stream
 * class so that it can gain access to the protected
 * ssl_bio_{read,write}() methods in that class.  It is full declared
 * in this implementation file to hide its interface from users to
 * prevent potential abuse of the friend relationship between it and
 * the @c ACE_SSL_Asynch_Stream class.
 */
struct ACE_SSL_Asynch_Stream_Accessor
{
  static int read (ACE_SSL_Asynch_Stream * stream,
               char * buf,
               size_t len,
               int & errval)
  {
    return stream->ssl_bio_read (buf, len, errval);
  }

  static int write (ACE_SSL_Asynch_Stream * stream,
                    const char * buf,
                    size_t len,
                    int & errval)
  {
    return stream->ssl_bio_write (buf, len, errval);
  }
};

ACE_END_VERSIONED_NAMESPACE_DECL

int
ACE_ASYNCH_BIO_NEW_NAME (BIO * pBIO)
{
  pBIO->init  = 0;    // not initialized
  pBIO->num   = 0;    // still zero ( we can use it )
  pBIO->ptr   = 0;    // will be pointer to ACE_SSL_Asynch_Stream
  pBIO->flags = 0;    //

  return 1;
}

int
ACE_ASYNCH_BIO_FREE_NAME (BIO * pBIO)
{
  if (pBIO && pBIO->shutdown)
    {
      pBIO->ptr   = 0;
      pBIO->init  = 0;
      pBIO->num   = 0;
      pBIO->flags = 0;

      return 1;
    }

  return 0;
}

int
ACE_ASYNCH_BIO_READ_NAME (BIO * pBIO, char * buf, int len)
{
  BIO_clear_retry_flags (pBIO);

  ACE_SSL_Asynch_Stream * const p_stream =
    static_cast<ACE_SSL_Asynch_Stream *> (pBIO->ptr);

  if (pBIO->init == 0 || p_stream == 0 || buf == 0 || len <= 0)
    return -1;

  BIO_clear_retry_flags (pBIO);

  int errval = 0;

  int retval =
    ACE_SSL_Asynch_Stream_Accessor::read (p_stream,
                                          buf,
                                          len,
                                          errval);

  if (retval >= 0)
    return retval;

  if (errval == EINPROGRESS)
    BIO_set_retry_read (pBIO);

  return -1;
}

int
ACE_ASYNCH_BIO_WRITE_NAME (BIO * pBIO, const char * buf, int len)
{
  BIO_clear_retry_flags (pBIO);

  ACE_SSL_Asynch_Stream * p_stream =
    static_cast<ACE_SSL_Asynch_Stream *> (pBIO->ptr);

  if (pBIO->init == 0 || p_stream == 0 || buf == 0 || len <= 0)
    return -1;

  BIO_clear_retry_flags (pBIO);

  int errval = 0;

  int retval =
    ACE_SSL_Asynch_Stream_Accessor::write (p_stream,
                                           buf,
                                           len,
                                           errval);

  if (retval >= 0)
    return retval;

  if (errval == EINPROGRESS)
    BIO_set_retry_write (pBIO);

  return -1;
}

long
ACE_ASYNCH_BIO_CTRL_NAME (BIO * pBIO, int cmd, long num, void *ptr)
{
  long ret = 1;

  switch (cmd)
    {
    case BIO_C_SET_FILE_PTR:
      pBIO->shutdown = static_cast<int> (num);
      pBIO->ptr = ptr;
      pBIO->init = 1;
      break;

    case BIO_CTRL_INFO:
      ret = 0;
      break;

    case BIO_CTRL_GET_CLOSE:
      ret = pBIO->shutdown;
      break;

    case BIO_CTRL_SET_CLOSE:
      pBIO->shutdown = static_cast<int> (num);
      break;

    case BIO_CTRL_PENDING:
    case BIO_CTRL_WPENDING:
      ret = 0;
      break;

    case BIO_CTRL_DUP:
    case BIO_CTRL_FLUSH:
      ret = 1;
      break;

    default:
      ret = 0;
      break;
  }

  return ret;
}

int
ACE_ASYNCH_BIO_PUTS_NAME (BIO *pBIO, const char *str)
{
  size_t const n = ACE_OS::strlen (str);

  return ACE_ASYNCH_BIO_WRITE_NAME (pBIO,
                                    str,
                                    ACE_Utils::truncate_cast<int> (n));
}

#endif  /* OPENSSL_VERSION_NUMBER > 0x0090581fL && (ACE_WIN32 ||
           ACE_HAS_AIO_CALLS) */
