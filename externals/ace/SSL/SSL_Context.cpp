#include "SSL_Context.h"

#include "sslconf.h"

#if !defined(__ACE_INLINE__)
#include "SSL_Context.inl"
#endif /* __ACE_INLINE__ */

#include "ace/Guard_T.h"
#include "ace/Object_Manager.h"
#include "ace/Log_Msg.h"
#include "ace/Singleton.h"
#include "ace/Synch_Traits.h"
#include "ace/Truncate.h"
#include "ace/ACE.h"
#include "ace/OS_NS_errno.h"
#include "ace/OS_NS_string.h"

#ifdef ACE_HAS_THREADS
# include "ace/Thread_Mutex.h"
# include "ace/OS_NS_Thread.h"
#endif  /* ACE_HAS_THREADS */

#include <openssl/x509.h>
#include <openssl/err.h>
#include <openssl/rand.h>
#include <openssl/safestack.h>

ACE_RCSID (ACE_SSL,
           SSL_Context,
           "$Id: SSL_Context.cpp 82574 2008-08-08 19:35:06Z parsons $")


namespace
{
  /// Reference count of the number of times the ACE_SSL_Context was
  /// initialized.
  int ssl_library_init_count = 0;

  // @@ This should also be done with a singleton, otherwise it is not
  //    thread safe and/or portable to some weird platforms...

#ifdef ACE_HAS_THREADS
  /// Array of mutexes used internally by OpenSSL when the SSL
  /// application is multithreaded.
  ACE_SSL_Context::lock_type * ssl_locks = 0;

  // @@ This should also be managed by a singleton.
#endif
}

#ifdef ACE_HAS_THREADS

# if (defined (ACE_HAS_VERSIONED_NAMESPACE) && ACE_HAS_VERSIONED_NAMESPACE == 1)
#  define ACE_SSL_LOCKING_CALLBACK_NAME ACE_PREPROC_CONCATENATE(ACE_VERSIONED_NAMESPACE_NAME, _ACE_SSL_locking_callback)
#  define ACE_SSL_THREAD_ID_NAME ACE_PREPROC_CONCATENATE(ACE_VERSIONED_NAMESPACE_NAME, _ACE_SSL_thread_id)
# else
#  define ACE_SSL_LOCKING_CALLBACK_NAME ACE_SSL_locking_callback
#  define ACE_SSL_THREAD_ID_NAME ACE_SSL_thread_id
# endif  /* ACE_HAS_VERSIONED_NAMESPACE == 1 */



extern "C"
{
  void
  ACE_SSL_LOCKING_CALLBACK_NAME (int mode,
                                 int type,
                                 const char * /* file */,
                                 int /* line */)
  {
    // #ifdef undef
    //   fprintf(stderr,"thread=%4d mode=%s lock=%s %s:%d\n",
    //           CRYPTO_thread_id(),
    //           (mode&CRYPTO_LOCK)?"l":"u",
    //           (type&CRYPTO_READ)?"r":"w",file,line);
    // #endif
    //   /*
    //     if (CRYPTO_LOCK_SSL_CERT == type)
    //     fprintf(stderr,"(t,m,f,l) %ld %d %s %d\n",
    //     CRYPTO_thread_id(),
    //     mode,file,line);
    //   */
    if (mode & CRYPTO_LOCK)
      (void) ssl_locks[type].acquire ();
    else
      (void) ssl_locks[type].release ();
  }

  // -------------------------------

  // Return the current thread ID.  OpenSSL uses this on platforms
  // that need it.
  unsigned long
  ACE_SSL_THREAD_ID_NAME (void)
  {
    return (unsigned long) ACE_VERSIONED_NAMESPACE_NAME::ACE_OS::thr_self ();
  }
}
#endif  /* ACE_HAS_THREADS */


// ****************************************************************

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

#ifdef ACE_HAS_THREADS
ACE_SSL_Context::lock_type * ACE_SSL_Context::locks_ = 0;
#endif  /* ACE_HAS_THREADS */

ACE_SSL_Context::ACE_SSL_Context (void)
  : context_ (0),
    mode_ (-1),
    default_verify_mode_ (SSL_VERIFY_NONE),
    have_ca_ (0)
{
  ACE_SSL_Context::ssl_library_init ();
}

ACE_SSL_Context::~ACE_SSL_Context (void)
{
  if (this->context_)
    {
      ::SSL_CTX_free (this->context_);
      this->context_ = 0;
    }

  ACE_SSL_Context::ssl_library_fini ();
}

ACE_SSL_Context *
ACE_SSL_Context::instance (void)
{
  return ACE_Singleton<ACE_SSL_Context, ACE_SYNCH_MUTEX>::instance ();
}

void
ACE_SSL_Context::ssl_library_init (void)
{
  ACE_MT (ACE_GUARD (ACE_Recursive_Thread_Mutex,
                     ace_ssl_mon,
                     *ACE_Static_Object_Lock::instance ()));

  if (ssl_library_init_count == 0)
    {
      // Initialize the locking callbacks before initializing anything
      // else.
#ifdef ACE_HAS_THREADS
      int const num_locks = ::CRYPTO_num_locks ();

      this->locks_ = new lock_type[num_locks];
      ssl_locks    = this->locks_;

# if !defined (WIN32)
      // This call isn't necessary on some platforms.  See the CRYPTO
      // library's threads(3) man page for details.
      ::CRYPTO_set_id_callback (ACE_SSL_THREAD_ID_NAME);
# endif  /* !WIN32 */
      ::CRYPTO_set_locking_callback (ACE_SSL_LOCKING_CALLBACK_NAME);
#endif  /* ACE_HAS_THREADS */

      ::SSLeay_add_ssl_algorithms ();
      ::SSL_load_error_strings ();

      // Seed the random number generator.  Note that the random
      // number generator can be seeded more than once to "stir" its
      // state.

#ifdef WIN32
      // Seed the random number generator by sampling the screen.
      ::RAND_screen ();
#endif  /* WIN32 */

#if OPENSSL_VERSION_NUMBER >= 0x00905100L
      // OpenSSL < 0.9.5 doesn't have EGD support.

      const char *egd_socket_file =
        ACE_OS::getenv (ACE_SSL_EGD_FILE_ENV);

      if (egd_socket_file != 0)
        (void) this->egd_file (egd_socket_file);
#endif  /* OPENSSL_VERSION_NUMBER */

      const char *rand_file =
        ACE_OS::getenv (ACE_SSL_RAND_FILE_ENV);

      if (rand_file != 0)
        (void) this->seed_file (rand_file);

      // Initialize the mutexes that will be used by the SSL and
      // crypto library.

    }

  ++ssl_library_init_count;
}

void
ACE_SSL_Context::ssl_library_fini (void)
{
  ACE_MT (ACE_GUARD (ACE_Recursive_Thread_Mutex,
                     ace_ssl_mon,
                     *ACE_Static_Object_Lock::instance ()));

  --ssl_library_init_count;
  if (ssl_library_init_count == 0)
    {
      ::ERR_free_strings ();
      ::EVP_cleanup ();

      // Clean up the locking callbacks after everything else has been
      // cleaned up.
#ifdef ACE_HAS_THREADS
      ::CRYPTO_set_locking_callback (0);
      ssl_locks = 0;

      delete [] this->locks_;
      this->locks_ = 0;

#endif  /* ACE_HAS_THREADS */
    }
}

int
ACE_SSL_Context::set_mode (int mode)
{
  ACE_MT (ACE_GUARD_RETURN (ACE_Recursive_Thread_Mutex,
                            ace_ssl_mon,
                            *ACE_Static_Object_Lock::instance (),
                            -1));

  if (this->context_ != 0)
    return -1;

  SSL_METHOD *method = 0;

  switch (mode)
    {
    case ACE_SSL_Context::SSLv2_client:
      method = ::SSLv2_client_method ();
      break;
    case ACE_SSL_Context::SSLv2_server:
      method = ::SSLv2_server_method ();
      break;
    case ACE_SSL_Context::SSLv2:
      method = ::SSLv2_method ();
      break;
    case ACE_SSL_Context::SSLv3_client:
      method = ::SSLv3_client_method ();
      break;
    case ACE_SSL_Context::SSLv3_server:
      method = ::SSLv3_server_method ();
      break;
    case ACE_SSL_Context::SSLv3:
      method = ::SSLv3_method ();
      break;
    case ACE_SSL_Context::SSLv23_client:
      method = ::SSLv23_client_method ();
      break;
    case ACE_SSL_Context::SSLv23_server:
      method = ::SSLv23_server_method ();
      break;
    case ACE_SSL_Context::SSLv23:
      method = ::SSLv23_method ();
      break;
    case ACE_SSL_Context::TLSv1_client:
      method = ::TLSv1_client_method ();
      break;
    case ACE_SSL_Context::TLSv1_server:
      method = ::TLSv1_server_method ();
      break;
    case ACE_SSL_Context::TLSv1:
      method = ::TLSv1_method ();
      break;
    default:
      method = ::SSLv3_method ();
      break;
    }

  this->context_ = ::SSL_CTX_new (method);
  if (this->context_ == 0)
    return -1;

  this->mode_ = mode;

  // Load the trusted certificate authority (default) certificate
  // locations. But do not return -1 on error, doing so confuses CTX
  // allocation (severe error) with the less important loading of CA
  // certificate location error.  If it is important for your
  // application then call ACE_SSL_Context::have_trusted_ca(),
  // immediately following this call to set_mode().
  (void) this->load_trusted_ca ();

  return 0;
}

int
ACE_SSL_Context::load_trusted_ca (const char* ca_file,
                                  const char* ca_dir,
                                  bool use_env_defaults)
{
  this->check_context ();

  if (ca_file == 0 && use_env_defaults)
    {
      // Use the default environment settings.
      ca_file = ACE_OS::getenv (ACE_SSL_CERT_FILE_ENV);
      if (ca_file == 0)
        ca_file = ACE_DEFAULT_SSL_CERT_FILE;
    }

  if (ca_dir == 0 && use_env_defaults)
    {
      // Use the default environment settings.
      ca_dir = ACE_OS::getenv (ACE_SSL_CERT_DIR_ENV);
      if (ca_dir == 0)
        ca_dir = ACE_DEFAULT_SSL_CERT_DIR;
    }

  // NOTE: SSL_CTX_load_verify_locations() returns 0 on error.
  if (::SSL_CTX_load_verify_locations (this->context_,
                                       ca_file,
                                       ca_dir) <= 0)
    {
      if (ACE::debug ())
        ACE_SSL_Context::report_error ();
      return -1;
    }

  ++this->have_ca_;

  // For TLS/SSL servers scan all certificates in ca_file and ca_dir and
  // list them as acceptable CAs when requesting a client certificate.
  if (mode_ == SSLv23
      || mode_ == SSLv23_server
      || mode_ == TLSv1
      || mode_ == TLSv1_server
      || mode_ == SSLv3
      || mode_ == SSLv3_server
      || mode_ == SSLv2
      || mode_ == SSLv2_server)
    {
      // Note: The STACK_OF(X509_NAME) pointer is a copy of the pointer in
      // the CTX; any changes to it by way of these function calls will
      // change the CTX directly.
      STACK_OF (X509_NAME) * cert_names = 0;
      cert_names = ::SSL_CTX_get_client_CA_list (this->context_);
      bool error = false;

      // Add CAs from both the file and dir, if specified. There should
      // already be a STACK_OF(X509_NAME) in the CTX, but if not, we create
      // one.
      if (ca_file)
        {
          if (cert_names == 0)
            {
              if ((cert_names = ::SSL_load_client_CA_file (ca_file)) != 0)
                ::SSL_CTX_set_client_CA_list (this->context_, cert_names);
              else
                error = true;
            }
          else
            {
              // Add new certificate names to the list.
              error = (0 == ::SSL_add_file_cert_subjects_to_stack (cert_names,
                                                                   ca_file));
            }

          if (error)
            {
              if (ACE::debug ())
                ACE_SSL_Context::report_error ();
              return -1;
            }
        }

      // SSL_add_dir_cert_subjects_to_stack is defined at 0.9.8a (but not
      // on OpenVMS or Mac Classic); it may be available earlier. Change
      // this comparison if so.
#if defined (OPENSSL_VERSION_NUMBER) && (OPENSSL_VERSION_NUMBER >= 0x0090801fL)
#  if !defined (OPENSSL_SYS_VMS) && !defined (OPENSSL_SYS_MACINTOSH_CLASSIC)
#    if !defined (OPENSSL_SYS_WIN32) || (OPENSSL_VERSION_NUMBER > 0x0090807fL)

      if (ca_dir != 0)
        {
          if (cert_names == 0)
            {
              if ((cert_names = sk_X509_NAME_new_null ()) == 0)
                {
                  if (ACE::debug ())
                    ACE_SSL_Context::report_error ();
                  return -1;
                }
              ::SSL_CTX_set_client_CA_list (this->context_, cert_names);
            }
          if (0 == ::SSL_add_dir_cert_subjects_to_stack (cert_names, ca_dir))
            {
              if (ACE::debug ())
                ACE_SSL_Context::report_error ();
              return -1;
            }
        }
#    endif /* !OPENSSL_SYS_WIN32 || OPENSSL_VERSION_NUMBER >= 0x0090807fL */
#  endif /* !OPENSSL_SYS_VMS && !OPENSSL_SYS_MACINTOSH_CLASSIC */
#endif /* OPENSSL_VERSION_NUMBER >= 0.9.8a release */

    }

  return 0;
}


int
ACE_SSL_Context::private_key (const char *file_name,
                              int type)
{
  if (this->private_key_.type () != -1)
    return 0;

  this->check_context ();

  this->private_key_ = ACE_SSL_Data_File (file_name, type);

  if (::SSL_CTX_use_PrivateKey_file (this->context_,
                                     this->private_key_.file_name (),
                                     this->private_key_.type ()) <= 0)
    {
      this->private_key_ = ACE_SSL_Data_File ();
      return -1;
    }
  else
    return this->verify_private_key ();
}

int
ACE_SSL_Context::verify_private_key (void)
{
  this->check_context ();

  return (::SSL_CTX_check_private_key (this->context_) <= 0 ? -1 : 0);
}

int
ACE_SSL_Context::certificate (const char *file_name,
                              int type)
{
  if (this->certificate_.type () != -1)
    return 0;

  this->certificate_ = ACE_SSL_Data_File (file_name, type);

  this->check_context ();

  if (::SSL_CTX_use_certificate_file (this->context_,
                                      this->certificate_.file_name (),
                                      this->certificate_.type ()) <= 0)
    {
      this->certificate_ = ACE_SSL_Data_File ();
      return -1;
    }
  else
    return 0;
}

int
ACE_SSL_Context::certificate (X509* cert)
{
  // Is it really a good idea to return 0 if we're not setting the
  // certificate?
  if (this->certificate_.type () != -1)
      return 0;

  this->check_context();

  if (::SSL_CTX_use_certificate (this->context_, cert) <= 0)
    {
      return -1;
    }
  else
    {
      // No file is associated with the certificate, set this to a fictional
      // value so we don't reset it later.
      this->certificate_ = ACE_SSL_Data_File ("MEMORY CERTIFICATE");

      return 0;
    }
}

void
ACE_SSL_Context::set_verify_peer (int strict, int once, int depth)
{
  this->check_context ();

  // Setup the peer verififcation mode.

  int verify_mode = SSL_VERIFY_PEER;
  if (once)
    verify_mode |= SSL_VERIFY_CLIENT_ONCE;
  if (strict)
    verify_mode |= SSL_VERIFY_FAIL_IF_NO_PEER_CERT;

  // set the default verify mode
  this->default_verify_mode (verify_mode);

  // Set the max certificate depth but later let the verify_callback
  // catch the depth error by adding one to the required depth.
  if (depth > 0)
    ::SSL_CTX_set_verify_depth (this->context_, depth + 1);
}


int
ACE_SSL_Context::random_seed (const char * seed)
{
  int len = ACE_Utils::truncate_cast<int> (ACE_OS::strlen (seed));
  ::RAND_seed (seed, len);

#if OPENSSL_VERSION_NUMBER >= 0x00905100L
  // RAND_status() returns 1 if the PRNG has enough entropy.
  return (::RAND_status () == 1 ? 0 : -1);
#else
  return 0;  // Ugly, but OpenSSL <= 0.9.4 doesn't have RAND_status().
#endif  /* OPENSSL_VERSION_NUMBER >= 0x00905100L */
}

int
ACE_SSL_Context::egd_file (const char * socket_file)
{
#if OPENSSL_VERSION_NUMBER < 0x00905100L
  // OpenSSL < 0.9.5 doesn't have EGD support.
  ACE_UNUSED_ARG (socket_file);
  ACE_NOTSUP_RETURN (-1);
#else
  // RAND_egd() returns the amount of entropy used to seed the random
  // number generator.  The actual value should be greater than 16,
  // i.e. 128 bits.
  if (::RAND_egd (socket_file) > 0)
    return 0;
  else
    return -1;
#endif  /* OPENSSL_VERSION_NUMBER >= 0x00905100L */
}

int
ACE_SSL_Context::seed_file (const char * seed_file, long bytes)
{
  // RAND_load_file() returns the number of bytes used to seed the
  // random number generator. If the file reads ok, check RAND_status to
  // see if it got enough entropy.
  if (::RAND_load_file (seed_file, bytes) > 0)
#if OPENSSL_VERSION_NUMBER >= 0x00905100L
    // RAND_status() returns 1 if the PRNG has enough entropy.
    return (::RAND_status () == 1 ? 0 : -1);
#else
    return 0;  // Ugly, but OpenSSL <= 0.9.4 doesn't have RAND_status().
#endif  /* OPENSSL_VERSION_NUMBER >= 0x00905100L */
  else
    return -1;
}

void
ACE_SSL_Context::report_error (unsigned long error_code)
{
  if (error_code == 0)
    return;

  char error_string[256];

  (void) ::ERR_error_string (error_code, error_string);

  ACE_ERROR ((LM_ERROR,
              ACE_TEXT ("ACE_SSL (%P|%t) error code: %u - %C\n"),
              error_code,
              error_string));
}

void
ACE_SSL_Context::report_error (void)
{
  unsigned long err = ::ERR_get_error ();
  ACE_SSL_Context::report_error (err);
  ACE_OS::last_error (err);
}

int
ACE_SSL_Context::dh_params (const char *file_name,
                            int type)
{
  if (this->dh_params_.type () != -1)
    return 0;

  // For now we only support PEM encodings
  if (type != SSL_FILETYPE_PEM)
    return -1;

  this->dh_params_ = ACE_SSL_Data_File (file_name, type);

  this->check_context ();

  {
    // Swiped from Rescorla's examples and the OpenSSL s_server.c app
    DH * ret=0;
    BIO * bio = 0;

    if ((bio = ::BIO_new_file (this->dh_params_.file_name (), "r")) == 0)
      {
        this->dh_params_ = ACE_SSL_Data_File ();
        return -1;
      }

    ret = PEM_read_bio_DHparams (bio, 0, 0, 0);
    BIO_free (bio);

    if (ret == 0)
      {
        this->dh_params_ = ACE_SSL_Data_File ();
        return -1;
      }

    if (::SSL_CTX_set_tmp_dh (this->context_, ret) < 0)
      {
        this->dh_params_ = ACE_SSL_Data_File ();
        return -1;
      }
    DH_free (ret);
  }

  return 0;
}

// ****************************************************************

#if defined (ACE_HAS_EXPLICIT_STATIC_TEMPLATE_MEMBER_INSTANTIATION)

template ACE_Singleton<ACE_SSL_Context, ACE_SYNCH_MUTEX> *
  ACE_Singleton<ACE_SSL_Context, ACE_SYNCH_MUTEX>::singleton_;

#endif /* ACE_HAS_EXPLICIT_STATIC_TEMPLATE_MEMBER_INSTANTIATION */

ACE_END_VERSIONED_NAMESPACE_DECL
