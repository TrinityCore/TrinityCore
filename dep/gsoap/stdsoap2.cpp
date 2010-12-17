/*
	stdsoap2.c[pp] 2.8.0

	gSOAP runtime engine

gSOAP XML Web services tools
Copyright (C) 2000-2010, Robert van Engelen, Genivia Inc., All Rights Reserved.
This part of the software is released under ONE of the following licenses:
GPL, or the gSOAP public license, or Genivia's license for commercial use.
--------------------------------------------------------------------------------
Contributors:

Wind River Systems Inc., for the following additions under gSOAP public license:
  - vxWorks compatible
--------------------------------------------------------------------------------
gSOAP public license.

The contents of this file are subject to the gSOAP Public License Version 1.3
(the "License"); you may not use this file except in compliance with the
License. You may obtain a copy of the License at
http://www.cs.fsu.edu/~engelen/soaplicense.html
Software distributed under the License is distributed on an "AS IS" basis,
WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
for the specific language governing rights and limitations under the License.

The Initial Developer of the Original Code is Robert A. van Engelen.
Copyright (C) 2000-2010, Robert van Engelen, Genivia Inc., All Rights Reserved.
--------------------------------------------------------------------------------
GPL license.

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program; if not, write to the Free Software Foundation, Inc., 59 Temple
Place, Suite 330, Boston, MA 02111-1307 USA

Author contact information:
engelen@genivia.com / engelen@acm.org

This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
--------------------------------------------------------------------------------
A commercial use license is available from Genivia, Inc., contact@genivia.com
--------------------------------------------------------------------------------

Installation note:

Win32 build needs winsock.dll (Visual C++ "wsock32.lib")
To do this in Visual C++ 6.0, go to "Project", "settings", select the "Link"
tab (the project file needs to be selected in the file view) and add
"wsock32.lib" to the "Object/library modules" entry

On Mac OS X with gcc (GCC) 3.1 20020420 (prerelease) you MUST compile with
-fstack_check when using -O2 because gcc 3.1 has a bug that smashes the stack
when locally allocated data exceeds 64K.

*/

#ifdef AS400
# pragma convert(819)	/* EBCDIC to ASCII */
#endif

#include "stdsoap2.h"

#ifdef __BORLANDC__
# pragma warn -8060
#else
# ifdef WIN32
#  ifdef UNDER_CE
#   pragma comment(lib, "winsock.lib")
#  else
#   pragma comment(lib, "wsock32.lib")
#  endif
#  pragma warning(disable : 4996) /* disable deprecation warnings */
# endif
#endif

#ifdef __cplusplus
SOAP_SOURCE_STAMP("@(#) stdsoap2.cpp ver 2.8.0 2010-09-20 00:00:00 GMT")
extern "C" {
#else
SOAP_SOURCE_STAMP("@(#) stdsoap2.c ver 2.8.0 2010-09-20 00:00:00 GMT")
#endif

/* 8bit character representing unknown/nonrepresentable character data (e.g. not supported by current locale with multibyte support enabled) */
#ifndef SOAP_UNKNOWN_CHAR
#define SOAP_UNKNOWN_CHAR (127)
#endif

/*      EOF=-1 */
#define SOAP_LT (soap_wchar)(-2) /* XML character '<' */
#define SOAP_TT (soap_wchar)(-3) /* XML character '</' */
#define SOAP_GT (soap_wchar)(-4) /* XML character '>' */
#define SOAP_QT (soap_wchar)(-5) /* XML character '"' */
#define SOAP_AP (soap_wchar)(-6) /* XML character ''' */

#define soap_blank(c)		((c) >= 0 && (c) <= 32)
#define soap_notblank(c)	((c) > 32)

#if defined(WIN32) && !defined(UNDER_CE)
#define soap_hash_ptr(p)	((PtrToUlong(p) >> 3) & (SOAP_PTRHASH - 1))
#else
#define soap_hash_ptr(p)	((size_t)(((unsigned long)(p) >> 3) & (SOAP_PTRHASH-1)))
#endif

#if !defined(WITH_LEAN) || defined(SOAP_DEBUG)
static void soap_init_logs(struct soap*);
#endif
#ifdef SOAP_DEBUG
static void soap_close_logfile(struct soap*, int);
static void soap_set_logfile(struct soap*, int, const char*);
#endif

#ifdef SOAP_MEM_DEBUG
static void soap_init_mht(struct soap*);
static void soap_free_mht(struct soap*);
static void soap_track_unlink(struct soap*, const void*);
#endif

#ifndef PALM_2
static int soap_set_error(struct soap*, const char*, const char*, const char*, const char*, int);
static int soap_copy_fault(struct soap*, const char*, const char*, const char*, const char*);
static int soap_getattrval(struct soap*, char*, size_t, soap_wchar);
#endif

#ifndef PALM_1
static void soap_free_ns(struct soap *soap);
static soap_wchar soap_char(struct soap*);
static soap_wchar soap_get_pi(struct soap*);
static int soap_isxdigit(int);
static void *fplugin(struct soap*, const char*);
static size_t soap_count_attachments(struct soap *soap);
static int soap_try_connect_command(struct soap*, int http_command, const char *endpoint, const char *action);
#ifndef WITH_NOIDREF
static void soap_update_ptrs(struct soap*, char*, char*, char*, char*);
static int soap_has_copies(struct soap*, const char*, const char*);
static void soap_init_iht(struct soap*);
static void soap_free_iht(struct soap*);
static void soap_init_pht(struct soap*);
static void soap_free_pht(struct soap*);
#endif
#endif

#ifndef WITH_LEAN
static const char *soap_set_validation_fault(struct soap*, const char*, const char*);
static int soap_isnumeric(struct soap*, const char*);
static struct soap_nlist *soap_push_ns(struct soap *soap, const char *id, const char *ns, short utilized);
static void soap_utilize_ns(struct soap *soap, const char *tag, size_t n);
#endif

#ifndef WITH_LEANER
#ifndef PALM_1
static struct soap_multipart *soap_new_multipart(struct soap*, struct soap_multipart**, struct soap_multipart**, char*, size_t);
static int soap_putdimefield(struct soap*, const char*, size_t);
static char *soap_getdimefield(struct soap*, size_t);
static void soap_select_mime_boundary(struct soap*);
static int soap_valid_mime_boundary(struct soap*);
static void soap_resolve_attachment(struct soap*, struct soap_multipart*);
#endif
#endif

#ifdef WITH_GZIP
static int soap_getgziphdr(struct soap*);
#endif

#ifdef WITH_OPENSSL
# ifndef SOAP_SSL_RSA_BITS
#  define SOAP_SSL_RSA_BITS 2048
# endif
static int soap_ssl_init_done = 0;
static int ssl_auth_init(struct soap*);
static int ssl_verify_callback(int, X509_STORE_CTX*);
static int ssl_verify_callback_allow_expired_certificate(int, X509_STORE_CTX*);
static int ssl_password(char*, int, int, void *);
#endif

#ifdef WITH_GNUTLS
# ifndef SOAP_SSL_RSA_BITS
#  define SOAP_SSL_RSA_BITS 2048
# endif
static int soap_ssl_init_done = 0;
static const char *ssl_verify(struct soap *soap, const char *host);
# if defined(HAVE_PTHREAD_H)
#  include <pthread.h>
   /* make GNUTLS thread safe with pthreads */
   GCRY_THREAD_OPTION_PTHREAD_IMPL;
# elif defined(HAVE_PTH_H)
   #include <pth.h>
   /* make GNUTLS thread safe with PTH */
   GCRY_THREAD_OPTION_PTH_IMPL;
# endif
#endif

#if !defined(WITH_NOHTTP) || !defined(WITH_LEANER)
#ifndef PALM_1
static const char *soap_decode(char*, size_t, const char*, const char*);
#endif
#endif

#ifndef WITH_NOHTTP
#ifndef PALM_1
static soap_wchar soap_getchunkchar(struct soap*);
static const char *http_error(struct soap*, int);
static int http_put(struct soap*);
static int http_get(struct soap*);
static int http_405(struct soap*);
static int http_post(struct soap*, const char*, const char*, int, const char*, const char*, size_t);
static int http_send_header(struct soap*, const char*);
static int http_post_header(struct soap*, const char*, const char*);
static int http_response(struct soap*, int, size_t);
static int http_parse(struct soap*);
static int http_parse_header(struct soap*, const char*, const char*);
#endif
#endif

#ifndef WITH_NOIO

#ifndef PALM_1
static int fsend(struct soap*, const char*, size_t);
static size_t frecv(struct soap*, char*, size_t);
static int tcp_init(struct soap*);
static const char *tcp_error(struct soap*);
#ifndef WITH_IPV6
static int tcp_gethost(struct soap*, const char *addr, struct in_addr *inaddr);
#endif
static SOAP_SOCKET tcp_connect(struct soap*, const char *endpoint, const char *host, int port);
static SOAP_SOCKET tcp_accept(struct soap*, SOAP_SOCKET, struct sockaddr*, int*);
static int tcp_select(struct soap*, SOAP_SOCKET, int, int);
static int tcp_disconnect(struct soap*);
static int tcp_closesocket(struct soap*, SOAP_SOCKET);
static int tcp_shutdownsocket(struct soap*, SOAP_SOCKET, int);
static const char *soap_strerror(struct soap*);
#endif

#define SOAP_TCP_SELECT_RCV 0x1
#define SOAP_TCP_SELECT_SND 0x2
#define SOAP_TCP_SELECT_ERR 0x4
#define SOAP_TCP_SELECT_ALL 0x7

#if defined(WIN32)
  #define SOAP_SOCKBLOCK(fd) \
  { u_long blocking = 0; \
    ioctlsocket(fd, FIONBIO, &blocking); \
  }
  #define SOAP_SOCKNONBLOCK(fd) \
  { u_long nonblocking = 1; \
    ioctlsocket(fd, FIONBIO, &nonblocking); \
  }
#elif defined(VXWORKS)
  #define SOAP_SOCKBLOCK(fd) \
  { u_long blocking = 0; \
    ioctl(fd, FIONBIO, (int)(&blocking)); \
  }
  #define SOAP_SOCKNONBLOCK(fd) \
  { u_long nonblocking = 1; \
    ioctl(fd, FIONBIO, (int)(&nonblocking)); \
  }
#elif defined(PALM)
  #define SOAP_SOCKBLOCK(fd) fcntl(fd, F_SETFL, fcntl(fd, F_GETFL, 0)&~O_NONBLOCK);
  #define SOAP_SOCKNONBLOCK(fd) fcntl(fd, F_SETFL, fcntl(fd, F_GETFL, 0)|O_NONBLOCK);
#elif defined(SYMBIAN)
  #define SOAP_SOCKBLOCK(fd) \
  { long blocking = 0; \
    ioctl(fd, 0/*FIONBIO*/, &blocking); \
  }
  #define SOAP_SOCKNONBLOCK(fd) \
  { long nonblocking = 1; \
    ioctl(fd, 0/*FIONBIO*/, &nonblocking); \
  }
#else
  #define SOAP_SOCKBLOCK(fd) fcntl(fd, F_SETFL, fcntl(fd, F_GETFL)&~O_NONBLOCK);
  #define SOAP_SOCKNONBLOCK(fd) fcntl(fd, F_SETFL, fcntl(fd, F_GETFL)|O_NONBLOCK);
#endif

#endif

#if defined(PALM) && !defined(PALM_2)
unsigned short errno;
#endif

#ifndef PALM_1
static const char soap_env1[42] = "http://schemas.xmlsoap.org/soap/envelope/";
static const char soap_enc1[42] = "http://schemas.xmlsoap.org/soap/encoding/";
static const char soap_env2[40] = "http://www.w3.org/2003/05/soap-envelope";
static const char soap_enc2[40] = "http://www.w3.org/2003/05/soap-encoding";
static const char soap_rpc[35] = "http://www.w3.org/2003/05/soap-rpc";
#endif

#ifndef PALM_1
const struct soap_double_nan soap_double_nan = {0xFFFFFFFF, 0xFFFFFFFF};
static const char soap_base64o[65] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
static const char soap_base64i[81] = "\76XXX\77\64\65\66\67\70\71\72\73\74\75XXXXXXX\00\01\02\03\04\05\06\07\10\11\12\13\14\15\16\17\20\21\22\23\24\25\26\27\30\31XXXXXX\32\33\34\35\36\37\40\41\42\43\44\45\46\47\50\51\52\53\54\55\56\57\60\61\62\63";
#endif

#ifndef WITH_LEAN
static const char soap_indent[11] = "\n\t\t\t\t\t\t\t\t\t";
/* Alternative indentation form for SOAP_XML_INDENT:
static const char soap_indent[21] = "\n                   ";
*/
#endif

#ifndef SOAP_CANARY
# define SOAP_CANARY (0xC0DE)
#endif

static const char soap_padding[4] = "\0\0\0";
#define SOAP_STR_PADDING (soap_padding)
#define SOAP_STR_EOS (soap_padding)
#define SOAP_NON_NULL (soap_padding)

#ifndef WITH_LEAN
static const struct soap_code_map html_entity_codes[] = /* entities for XHTML parsing */
{ { 160, "nbsp" },
  { 161, "iexcl" },
  { 162, "cent" },
  { 163, "pound" },
  { 164, "curren" },
  { 165, "yen" },
  { 166, "brvbar" },
  { 167, "sect" },
  { 168, "uml" },
  { 169, "copy" },
  { 170, "ordf" },
  { 171, "laquo" },
  { 172, "not" },
  { 173, "shy" },
  { 174, "reg" },
  { 175, "macr" },
  { 176, "deg" },
  { 177, "plusmn" },
  { 178, "sup2" },
  { 179, "sup3" },
  { 180, "acute" },
  { 181, "micro" },
  { 182, "para" },
  { 183, "middot" },
  { 184, "cedil" },
  { 185, "sup1" },
  { 186, "ordm" },
  { 187, "raquo" },
  { 188, "frac14" },
  { 189, "frac12" },
  { 190, "frac34" },
  { 191, "iquest" },
  { 192, "Agrave" },
  { 193, "Aacute" },
  { 194, "Acirc" },
  { 195, "Atilde" },
  { 196, "Auml" },
  { 197, "Aring" },
  { 198, "AElig" },
  { 199, "Ccedil" },
  { 200, "Egrave" },
  { 201, "Eacute" },
  { 202, "Ecirc" },
  { 203, "Euml" },
  { 204, "Igrave" },
  { 205, "Iacute" },
  { 206, "Icirc" },
  { 207, "Iuml" },
  { 208, "ETH" },
  { 209, "Ntilde" },
  { 210, "Ograve" },
  { 211, "Oacute" },
  { 212, "Ocirc" },
  { 213, "Otilde" },
  { 214, "Ouml" },
  { 215, "times" },
  { 216, "Oslash" },
  { 217, "Ugrave" },
  { 218, "Uacute" },
  { 219, "Ucirc" },
  { 220, "Uuml" },
  { 221, "Yacute" },
  { 222, "THORN" },
  { 223, "szlig" },
  { 224, "agrave" },
  { 225, "aacute" },
  { 226, "acirc" },
  { 227, "atilde" },
  { 228, "auml" },
  { 229, "aring" },
  { 230, "aelig" },
  { 231, "ccedil" },
  { 232, "egrave" },
  { 233, "eacute" },
  { 234, "ecirc" },
  { 235, "euml" },
  { 236, "igrave" },
  { 237, "iacute" },
  { 238, "icirc" },
  { 239, "iuml" },
  { 240, "eth" },
  { 241, "ntilde" },
  { 242, "ograve" },
  { 243, "oacute" },
  { 244, "ocirc" },
  { 245, "otilde" },
  { 246, "ouml" },
  { 247, "divide" },
  { 248, "oslash" },
  { 249, "ugrave" },
  { 250, "uacute" },
  { 251, "ucirc" },
  { 252, "uuml" },
  { 253, "yacute" },
  { 254, "thorn" },
  { 255, "yuml" },
  {   0, NULL }
};
#endif

#ifndef WITH_NOIO
#ifndef WITH_LEAN
static const struct soap_code_map h_error_codes[] =
{
#ifdef HOST_NOT_FOUND   
  { HOST_NOT_FOUND, "Host not found" },
#endif
#ifdef TRY_AGAIN
  { TRY_AGAIN, "Try Again" },
#endif
#ifdef NO_RECOVERY  
  { NO_RECOVERY, "No Recovery" },
#endif
#ifdef NO_DATA
  { NO_DATA, "No Data" },
#endif
#ifdef NO_ADDRESS
  { NO_ADDRESS, "No Address" },
#endif
  { 0, NULL }
};
#endif
#endif

#ifndef WITH_NOHTTP
#ifndef WITH_LEAN
static const struct soap_code_map h_http_error_codes[] =
{ { 200, "OK" },
  { 201, "Created" },
  { 202, "Accepted" },
  { 203, "Non-Authoritative Information" },
  { 204, "No Content" },
  { 205, "Reset Content" },
  { 206, "Partial Content" },
  { 300, "Multiple Choices" },
  { 301, "Moved Permanently" },
  { 302, "Found" },
  { 303, "See Other" },
  { 304, "Not Modified" },
  { 305, "Use Proxy" },
  { 307, "Temporary Redirect" },
  { 400, "Bad Request" },
  { 401, "Unauthorized" },
  { 402, "Payment Required" },
  { 403, "Forbidden" },
  { 404, "Not Found" },
  { 405, "Method Not Allowed" },
  { 406, "Not Acceptable" },
  { 407, "Proxy Authentication Required" },
  { 408, "Request Time-out" },
  { 409, "Conflict" },
  { 410, "Gone" },
  { 411, "Length Required" },
  { 412, "Precondition Failed" },
  { 413, "Request Entity Too Large" },
  { 414, "Request-URI Too Large" },
  { 415, "Unsupported Media Type" },
  { 416, "Requested range not satisfiable" },
  { 417, "Expectation Failed" },
  { 500, "Internal Server Error" },
  { 501, "Not Implemented" },
  { 502, "Bad Gateway" },
  { 503, "Service Unavailable" },
  { 504, "Gateway Time-out" },
  { 505, "HTTP Version not supported" },
  {   0, NULL }
};
#endif
#endif

#ifdef WITH_OPENSSL
static const struct soap_code_map h_ssl_error_codes[] =
{
#define _SSL_ERROR(e) { e, #e }
  _SSL_ERROR(SSL_ERROR_SSL),
  _SSL_ERROR(SSL_ERROR_ZERO_RETURN),
  _SSL_ERROR(SSL_ERROR_WANT_READ),
  _SSL_ERROR(SSL_ERROR_WANT_WRITE),
  _SSL_ERROR(SSL_ERROR_WANT_CONNECT),
  _SSL_ERROR(SSL_ERROR_WANT_X509_LOOKUP),
  _SSL_ERROR(SSL_ERROR_SYSCALL),
  { 0, NULL }
};
#endif

#ifndef WITH_LEANER
static const struct soap_code_map mime_codes[] =
{ { SOAP_MIME_7BIT,		"7bit" },
  { SOAP_MIME_8BIT,		"8bit" },
  { SOAP_MIME_BINARY,		"binary" },
  { SOAP_MIME_QUOTED_PRINTABLE, "quoted-printable" },
  { SOAP_MIME_BASE64,		"base64" },
  { SOAP_MIME_IETF_TOKEN,	"ietf-token" },
  { SOAP_MIME_X_TOKEN,		"x-token" },
  { 0,				NULL }
};
#endif

#ifdef WIN32
static int tcp_done = 0;
#endif

#if defined(HP_UX) && defined(HAVE_GETHOSTBYNAME_R)
extern int h_errno;
#endif

/******************************************************************************/
#ifndef WITH_NOIO
#ifndef PALM_1
static int
fsend(struct soap *soap, const char *s, size_t n)
{ register int nwritten, err;
#if defined(__cplusplus) && !defined(WITH_LEAN) && !defined(WITH_COMPAT)
  if (soap->os)
  { soap->os->write(s, (std::streamsize)n);
    if (soap->os->good())
      return SOAP_OK;
    soap->errnum = 0;
    return SOAP_EOF;
  }
#endif
  while (n)
  { if (soap_valid_socket(soap->socket))
    { 
      if (soap->send_timeout)
      { for (;;)
        { register int r;
#ifdef WITH_OPENSSL
          if (soap->ssl)
            r = tcp_select(soap, soap->socket, SOAP_TCP_SELECT_ALL, soap->send_timeout);
          else
#endif
#ifdef WITH_GNUTLS
          if (soap->session)
            r = tcp_select(soap, soap->socket, SOAP_TCP_SELECT_ALL, soap->send_timeout);
          else
#endif
            r = tcp_select(soap, soap->socket, SOAP_TCP_SELECT_SND | SOAP_TCP_SELECT_ERR, soap->send_timeout);
          if (r > 0)
            break;
          if (!r)
            return SOAP_EOF;
	  err = soap->errnum;
	  if (!err)
            return soap->error;
          if (err != SOAP_EINTR && err != SOAP_EAGAIN && err != SOAP_EWOULDBLOCK)
            return SOAP_EOF;
        }
      }
#ifdef WITH_OPENSSL
      if (soap->ssl)
        nwritten = SSL_write(soap->ssl, s, (int)n);
      else if (soap->bio)
        nwritten = BIO_write(soap->bio, s, (int)n);
      else
#endif
#ifdef WITH_GNUTLS
      if (soap->session)
        nwritten = gnutls_record_send(soap->session, s, n);
      else
#endif
#ifndef WITH_LEAN
      if ((soap->omode & SOAP_IO_UDP))
      { if (soap->peerlen)
          nwritten = sendto(soap->socket, (char*)s, (SOAP_WINSOCKINT)n, soap->socket_flags, (struct sockaddr*)&soap->peer, (SOAP_WINSOCKINT)soap->peerlen);
        else
          nwritten = send(soap->socket, s, (SOAP_WINSOCKINT)n, soap->socket_flags);
        /* retry and back-off algorithm */
        /* TODO: this is not very clear from specs so verify and limit conditions under which we should loop (e.g. ENOBUFS) */
        if (nwritten < 0)
        { int udp_repeat;
          int udp_delay;
          if ((soap->connect_flags & SO_BROADCAST))
            udp_repeat = 3; /* SOAP-over-UDP MULTICAST_UDP_REPEAT - 1 */
          else
            udp_repeat = 1; /* SOAP-over-UDP UNICAST_UDP_REPEAT - 1 */
          udp_delay = (soap_random % 201) + 50; /* UDP_MIN_DELAY .. UDP_MAX_DELAY */
          do
          { tcp_select(soap, soap->socket, SOAP_TCP_SELECT_ERR, -1000 * udp_delay);
            if (soap->peerlen)
              nwritten = sendto(soap->socket, (char*)s, (SOAP_WINSOCKINT)n, soap->socket_flags, (struct sockaddr*)&soap->peer, (SOAP_WINSOCKINT)soap->peerlen);
            else
              nwritten = send(soap->socket, s, (SOAP_WINSOCKINT)n, soap->socket_flags);
            udp_delay <<= 1;
            if (udp_delay > 500) /* UDP_UPPER_DELAY */
              udp_delay = 500;
          }
          while (nwritten < 0 && --udp_repeat > 0);
        }
      }
      else
#endif
#if !defined(PALM) && !defined(AS400)
        nwritten = send(soap->socket, s, (int)n, soap->socket_flags);
#else
        nwritten = send(soap->socket, (void*)s, n, soap->socket_flags);
#endif
      if (nwritten <= 0)
      {
        register int r = 0;
        err = soap_socket_errno(soap->socket);
#ifdef WITH_OPENSSL
        if (soap->ssl && (r = SSL_get_error(soap->ssl, nwritten)) != SSL_ERROR_NONE && r != SSL_ERROR_WANT_READ && r != SSL_ERROR_WANT_WRITE)
        { soap->errnum = err;
          return SOAP_EOF;
        }
#endif
#ifdef WITH_GNUTLS
	if (soap->session)
        { if (nwritten == GNUTLS_E_INTERRUPTED)
	    err = SOAP_EINTR;
	  else if (nwritten == GNUTLS_E_AGAIN)
	    err = SOAP_EAGAIN;
	}
#endif
        if (err == SOAP_EWOULDBLOCK || err == SOAP_EAGAIN)
        {
#if defined(WITH_OPENSSL)
          if (soap->ssl && r == SSL_ERROR_WANT_READ)
            r = tcp_select(soap, soap->socket, SOAP_TCP_SELECT_RCV | SOAP_TCP_SELECT_ERR, soap->send_timeout ? soap->send_timeout : -10000);
          else
#elif defined(WITH_GNUTLS)
          if (soap->session && !gnutls_record_get_direction(soap->session))
            r = tcp_select(soap, soap->socket, SOAP_TCP_SELECT_RCV | SOAP_TCP_SELECT_ERR, soap->send_timeout ? soap->send_timeout : -10000);
          else
#endif
            r = tcp_select(soap, soap->socket, SOAP_TCP_SELECT_SND | SOAP_TCP_SELECT_ERR, soap->send_timeout ? soap->send_timeout : -10000);
	  if (!r && soap->send_timeout)
            return SOAP_EOF;
	  if (r < 0 && soap->errnum != SOAP_EINTR)
            return SOAP_EOF;
        }
        else if (err && err != SOAP_EINTR)
        { soap->errnum = err;
          return SOAP_EOF;
        }
        nwritten = 0; /* and call write() again */
      }
    }
    else
    {
#ifdef WITH_FASTCGI
      nwritten = fwrite((void*)s, 1, n, stdout);
      fflush(stdout);
#else
#ifdef UNDER_CE
      nwritten = fwrite(s, 1, n, soap->sendfd);
#else
#ifdef VXWORKS
#ifdef WMW_RPM_IO
      if (soap->rpmreqid)
        nwritten = (httpBlockPut(soap->rpmreqid, (char*)s, n) == 0) ? n : -1; 
      else
#endif
        nwritten = fwrite(s, sizeof(char), n, fdopen(soap->sendfd, "w"));
#else
#ifdef WIN32
      nwritten = _write(soap->sendfd, s, (unsigned int)n);
#else
      nwritten = write(soap->sendfd, s, (unsigned int)n);
#endif
#endif
#endif
#endif
      if (nwritten <= 0)
      { 
#ifndef WITH_FASTCGI
        err = soap_errno;
#else
        err = EOF;
#endif
        if (err && err != SOAP_EINTR && err != SOAP_EWOULDBLOCK && err != SOAP_EAGAIN)
        { soap->errnum = err;
          return SOAP_EOF;
        }
        nwritten = 0; /* and call write() again */
      }
    }
    n -= nwritten;
    s += nwritten;
  }
  return SOAP_OK;
}
#endif
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_send_raw(struct soap *soap, const char *s, size_t n)
{ if (!n)
    return SOAP_OK;
  if (soap->mode & SOAP_IO_LENGTH)
  { soap->count += n;
#ifndef WITH_LEANER
    if (soap->fpreparesend && (soap->mode & SOAP_IO) != SOAP_IO_STORE)
      return soap->error = soap->fpreparesend(soap, s, n);
#endif
    return SOAP_OK;
  }
  if (soap->mode & SOAP_IO)
  { register size_t i = SOAP_BUFLEN - soap->bufidx;
    while (n >= i)
    { memcpy(soap->buf + soap->bufidx, s, i);
      soap->bufidx = SOAP_BUFLEN;
      if (soap_flush(soap))
        return soap->error;
      s += i;
      n -= i;
      i = SOAP_BUFLEN;
    }
    memcpy(soap->buf + soap->bufidx, s, n);
    soap->bufidx += n;
    return SOAP_OK;
  }
  return soap_flush_raw(soap, s, n);
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_flush(struct soap *soap)
{ register size_t n = soap->bufidx;
  if (n)
  {
#ifndef WITH_LEANER
    if ((soap->mode & SOAP_IO) == SOAP_IO_STORE)
    { register int r;
      if (soap->fpreparesend && (r = soap->fpreparesend(soap, soap->buf, n)))
        return soap->error = r;
    }
#endif
    soap->bufidx = 0;
#ifdef WITH_ZLIB
    if (soap->mode & SOAP_ENC_ZLIB)
    { soap->d_stream->next_in = (Byte*)soap->buf;
      soap->d_stream->avail_in = (unsigned int)n;
#ifdef WITH_GZIP
      soap->z_crc = crc32(soap->z_crc, (Byte*)soap->buf, (unsigned int)n);
#endif
      do
      { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Deflating %u bytes\n", soap->d_stream->avail_in));
        if (deflate(soap->d_stream, Z_NO_FLUSH) != Z_OK)
        { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Unable to deflate: %s\n", soap->d_stream->msg?soap->d_stream->msg:SOAP_STR_EOS));
          return soap->error = SOAP_ZLIB_ERROR;
        }
        if (!soap->d_stream->avail_out)
        { if (soap_flush_raw(soap, soap->z_buf, SOAP_BUFLEN))
            return soap->error;
          soap->d_stream->next_out = (Byte*)soap->z_buf;
          soap->d_stream->avail_out = SOAP_BUFLEN;
        }
      } while (soap->d_stream->avail_in);
    }
    else
#endif
      return soap_flush_raw(soap, soap->buf, n);
  }
  return SOAP_OK;
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_flush_raw(struct soap *soap, const char *s, size_t n)
{ if ((soap->mode & SOAP_IO) == SOAP_IO_STORE)
  { register char *t;
    if (!(t = (char*)soap_push_block(soap, NULL, n)))
      return soap->error = SOAP_EOM;
    memcpy(t, s, n);
    return SOAP_OK;
  }
#ifndef WITH_LEANER
  if ((soap->mode & SOAP_IO) == SOAP_IO_CHUNK)
  { char t[16];
    sprintf(t, "\r\n%lX\r\n" + (soap->chunksize ? 0 : 2), (unsigned long)n);
    DBGMSG(SENT, t, strlen(t));
    if ((soap->error = soap->fsend(soap, t, strlen(t))))
      return soap->error;
    soap->chunksize += n;
  }
  DBGMSG(SENT, s, n);
#endif
  return soap->error = soap->fsend(soap, s, n);
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_send(struct soap *soap, const char *s)
{ if (s)
    return soap_send_raw(soap, s, strlen(s));
  return SOAP_OK;
}
#endif

/******************************************************************************/
#ifndef WITH_LEANER
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_send2(struct soap *soap, const char *s1, const char *s2)
{ if (soap_send(soap, s1))
    return soap->error;
  return soap_send(soap, s2);
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_LEANER
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_send3(struct soap *soap, const char *s1, const char *s2, const char *s3)
{ if (soap_send(soap, s1)
   || soap_send(soap, s2))
    return soap->error;
  return soap_send(soap, s3);
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_NOIO
#ifndef PALM_1
static size_t
frecv(struct soap *soap, char *s, size_t n)
{ register int r;
  register int retries = 100; /* max 100 retries with non-blocking sockets */
  soap->errnum = 0;
#if defined(__cplusplus) && !defined(WITH_LEAN) && !defined(WITH_COMPAT)
  if (soap->is)
  { if (soap->is->good())
      return soap->is->read(s, (std::streamsize)n).gcount();
    return 0;
  }
#endif
  if (soap_valid_socket(soap->socket))
  { for (;;)
    { 
#ifdef WITH_OPENSSL
      register int err = 0;
#endif
#ifdef WITH_OPENSSL
      if (soap->recv_timeout && !soap->ssl) /* SSL: sockets are nonblocking */
#else
      if (soap->recv_timeout)
#endif
      { for (;;)
        { r = tcp_select(soap, soap->socket, SOAP_TCP_SELECT_RCV | SOAP_TCP_SELECT_ERR, soap->recv_timeout);
          if (r > 0)
            break;
          if (!r)
            return 0;
	  r = soap->errnum;
          if (r != SOAP_EINTR && r != SOAP_EAGAIN && r != SOAP_EWOULDBLOCK)
            return 0;
        }
      }
#ifdef WITH_OPENSSL
      if (soap->ssl)
      { r = SSL_read(soap->ssl, s, (int)n);
        if (r > 0)
          return (size_t)r;
        err = SSL_get_error(soap->ssl, r);
        if (err != SSL_ERROR_NONE && err != SSL_ERROR_WANT_READ && err != SSL_ERROR_WANT_WRITE)
          return 0;
      }
      else if (soap->bio)
      { r = BIO_read(soap->bio, s, (int)n);
        if (r > 0)
          return (size_t)r;
        return 0;
      }
      else
#endif
#ifdef WITH_GNUTLS
      if (soap->session)
      { r = (int)gnutls_record_recv(soap->session, s, n);
        if (r >= 0)
	  return (size_t)r;
      }
      else
#endif
      { 
#ifndef WITH_LEAN
        if ((soap->omode & SOAP_IO_UDP))
        { SOAP_SOCKLEN_T k = (SOAP_SOCKLEN_T)sizeof(soap->peer);
          memset((void*)&soap->peer, 0, sizeof(soap->peer));
          r = recvfrom(soap->socket, s, (SOAP_WINSOCKINT)n, soap->socket_flags, (struct sockaddr*)&soap->peer, &k);	/* portability note: see SOAP_SOCKLEN_T definition in stdsoap2.h */
          soap->peerlen = (size_t)k;
#ifndef WITH_IPV6
          soap->ip = ntohl(soap->peer.sin_addr.s_addr);
#endif
        }
        else
#endif
          r = recv(soap->socket, s, (int)n, soap->socket_flags);
#ifdef PALM
        /* CycleSyncDisplay(curStatusMsg); */
#endif
        if (r >= 0)
          return (size_t)r;
        r = soap_socket_errno(soap->socket);
        if (r != SOAP_EINTR && r != SOAP_EAGAIN && r != SOAP_EWOULDBLOCK)
        { soap->errnum = r;
          return 0;
        }
      }
#if defined(WITH_OPENSSL)
      if (soap->ssl && err == SSL_ERROR_WANT_WRITE)
         r = tcp_select(soap, soap->socket, SOAP_TCP_SELECT_SND | SOAP_TCP_SELECT_ERR, soap->recv_timeout ? soap->recv_timeout : 5);
      else
#elif defined(WITH_GNUTLS)
      if (soap->session && gnutls_record_get_direction(soap->session))
         r = tcp_select(soap, soap->socket, SOAP_TCP_SELECT_SND | SOAP_TCP_SELECT_ERR, soap->recv_timeout ? soap->recv_timeout : 5);
      else
#endif
        r = tcp_select(soap, soap->socket, SOAP_TCP_SELECT_RCV | SOAP_TCP_SELECT_ERR, soap->recv_timeout ? soap->recv_timeout : 5);
      if (!r && soap->recv_timeout)
        return 0;
      if (r < 0)
      { r = soap->errnum;
        if (r != SOAP_EINTR && r != SOAP_EAGAIN && r != SOAP_EWOULDBLOCK)
          return 0;
      }
      if (retries-- <= 0)
        return 0;
#ifdef PALM
      r = soap_socket_errno(soap->socket);
      if (r != SOAP_EINTR && retries-- <= 0)
      { soap->errnum = r;
        return 0;
      }
#endif
    }
  }
#ifdef WITH_FASTCGI
  return fread(s, 1, n, stdin);
#else
#ifdef UNDER_CE
  return fread(s, 1, n, soap->recvfd);
#else
#ifdef WMW_RPM_IO
  if (soap->rpmreqid)
    r = httpBlockRead(soap->rpmreqid, s, n);
  else
#endif
#ifdef WIN32
    r = _read(soap->recvfd, s, (unsigned int)n);
#else
    r = read(soap->recvfd, s, (unsigned int)n);
#endif
  if (r >= 0)
    return (size_t)r;
  soap->errnum = soap_errno;
  return 0;
#endif
#endif
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_NOHTTP
#ifndef PALM_1
static soap_wchar
soap_getchunkchar(struct soap *soap)
{ if (soap->bufidx < soap->buflen)
    return soap->buf[soap->bufidx++];
  soap->bufidx = 0;
  soap->buflen = soap->chunkbuflen = soap->frecv(soap, soap->buf, SOAP_BUFLEN);
  DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Read %u bytes from socket %d\n", (unsigned int)soap->buflen, soap->socket));
  DBGMSG(RECV, soap->buf, soap->buflen);
  if (soap->buflen)
    return soap->buf[soap->bufidx++];
  return EOF;
}
#endif
#endif

/******************************************************************************/
#ifndef PALM_1
static int
soap_isxdigit(int c)
{ return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f');
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_recv_raw(struct soap *soap)
{ register size_t ret;
#if !defined(WITH_LEANER) || defined(WITH_ZLIB)
  register int r;
#endif
#ifdef WITH_ZLIB
  if (soap->mode & SOAP_ENC_ZLIB)
  { if (soap->d_stream->next_out == Z_NULL)
      return EOF;
    if (soap->d_stream->avail_in || !soap->d_stream->avail_out)
    { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Inflating\n"));
      soap->d_stream->next_out = (Byte*)soap->buf;
      soap->d_stream->avail_out = SOAP_BUFLEN;
      r = inflate(soap->d_stream, Z_NO_FLUSH);
      if (r == Z_NEED_DICT && soap->z_dict)
	r = inflateSetDictionary(soap->d_stream, (const Bytef*)soap->z_dict, soap->z_dict_len);
      if (r == Z_OK || r == Z_STREAM_END)
      { soap->bufidx = 0;
        ret = soap->buflen = SOAP_BUFLEN - soap->d_stream->avail_out;
        if (soap->zlib_in == SOAP_ZLIB_GZIP)
          soap->z_crc = crc32(soap->z_crc, (Byte*)soap->buf, (unsigned int)ret);
        if (r == Z_STREAM_END)
        { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Inflated %lu->%lu bytes\n", soap->d_stream->total_in, soap->d_stream->total_out));
          soap->z_ratio_in = (float)soap->d_stream->total_in / (float)soap->d_stream->total_out;
          soap->d_stream->next_out = Z_NULL;
        }
        if (ret)
        { soap->count += ret;
          DBGLOG(RECV, SOAP_MESSAGE(fdebug, "\n---- decompressed ----\n"));
          DBGMSG(RECV, soap->buf, ret);
          DBGLOG(RECV, SOAP_MESSAGE(fdebug, "\n----\n"));
#ifndef WITH_LEANER
          if (soap->fpreparerecv && (r = soap->fpreparerecv(soap, soap->buf, ret)))
            return soap->error = r;
#endif
          return SOAP_OK;
        }
      }
      else if (r != Z_BUF_ERROR)
      { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Inflate error: %s\n", soap->d_stream->msg?soap->d_stream->msg:SOAP_STR_EOS));
        soap->d_stream->next_out = Z_NULL;
        soap->error = SOAP_ZLIB_ERROR;
        return EOF;
      }
    }
zlib_again:
    if ((soap->mode & SOAP_IO) == SOAP_IO_CHUNK && !soap->chunksize)
    { memcpy(soap->buf, soap->z_buf, SOAP_BUFLEN);
      soap->buflen = soap->z_buflen;
    }
    DBGLOG(RECV, SOAP_MESSAGE(fdebug, "\n---- compressed ----\n"));
  }
#endif
#ifndef WITH_NOHTTP
  if ((soap->mode & SOAP_IO) == SOAP_IO_CHUNK) /* read HTTP chunked transfer */
  { for (;;)
    { register soap_wchar c;
      char *t, tmp[8];
      if (soap->chunksize)
      { soap->buflen = ret = soap->frecv(soap, soap->buf, soap->chunksize > SOAP_BUFLEN ? SOAP_BUFLEN : soap->chunksize);
        DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Getting chunk: read %u bytes\n", (unsigned int)ret));
        DBGMSG(RECV, soap->buf, ret);
        soap->bufidx = 0;
        soap->chunksize -= ret;
        break;
      }
      t = tmp;
      if (!soap->chunkbuflen)
      { soap->chunkbuflen = ret = soap->frecv(soap, soap->buf, SOAP_BUFLEN);
        DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Read %u bytes (chunked) from socket %d\n", (unsigned int)ret, soap->socket));
        DBGMSG(RECV, soap->buf, ret);
        soap->bufidx = 0;
        if (!ret)
          return soap->ahead = EOF;
      }
      else
        soap->bufidx = soap->buflen;
      soap->buflen = soap->chunkbuflen;
      DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Getting chunk size (idx=%u len=%u)\n", (unsigned int)soap->bufidx, (unsigned int)soap->buflen));
      while (!soap_isxdigit((int)(c = soap_getchunkchar(soap))))
      { if ((int)c == EOF)
          return soap->ahead = EOF;
      }
      do
        *t++ = (char)c;
      while (soap_isxdigit((int)(c = soap_getchunkchar(soap))) && t - tmp < 7);
      while ((int)c != EOF && c != '\n')
        c = soap_getchunkchar(soap);
      if ((int)c == EOF)
        return soap->ahead = EOF;
      *t = '\0';
      DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Chunk size = %s (hex)\n", tmp));
      soap->chunksize = soap_strtoul(tmp, &t, 16);
      if (!soap->chunksize)
      { soap->chunkbuflen = 0;
        DBGLOG(TEST, SOAP_MESSAGE(fdebug, "End of chunked message\n"));
        while ((int)c != EOF && c != '\n')
          c = soap_getchunkchar(soap);
        ret = 0;
        soap->ahead = EOF;
	break;
      }
      soap->buflen = soap->bufidx + soap->chunksize;
      DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Moving buf len to idx=%u len=%u (%s)\n", (unsigned int)soap->bufidx, (unsigned int)soap->buflen, tmp));
      if (soap->buflen > soap->chunkbuflen)
      { soap->buflen = soap->chunkbuflen;
        soap->chunksize -= soap->buflen - soap->bufidx;
        soap->chunkbuflen = 0;
        DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Passed end of buffer for chunked HTTP (%u bytes left)\n", (unsigned int)(soap->buflen - soap->bufidx)));
      }
      else if (soap->chunkbuflen)
        soap->chunksize = 0;
      ret = soap->buflen - soap->bufidx;
      if (ret)
        break;
    }
  }
  else
#endif
  { soap->bufidx = 0;
    soap->buflen = ret = soap->frecv(soap, soap->buf, SOAP_BUFLEN);
    DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Read %u bytes from socket %d\n", (unsigned int)ret, soap->socket));
    DBGMSG(RECV, soap->buf, ret);
  }
#ifdef WITH_ZLIB
  if (soap->mode & SOAP_ENC_ZLIB)
  { memcpy(soap->z_buf, soap->buf, SOAP_BUFLEN);
    soap->d_stream->next_in = (Byte*)(soap->z_buf + soap->bufidx);
    soap->d_stream->avail_in = (unsigned int)ret;
    soap->d_stream->next_out = (Byte*)soap->buf;
    soap->d_stream->avail_out = SOAP_BUFLEN;
    r = inflate(soap->d_stream, Z_NO_FLUSH);
    if (r == Z_NEED_DICT && soap->z_dict)
      r = inflateSetDictionary(soap->d_stream, (const Bytef*)soap->z_dict, soap->z_dict_len);
    if (r == Z_OK || r == Z_STREAM_END)
    { soap->bufidx = 0;
      soap->z_buflen = soap->buflen;
      soap->buflen = SOAP_BUFLEN - soap->d_stream->avail_out;
      if (soap->zlib_in == SOAP_ZLIB_GZIP)
        soap->z_crc = crc32(soap->z_crc, (Byte*)soap->buf, (unsigned int)soap->buflen);
      DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Inflated %u bytes\n", (unsigned int)soap->buflen));
      if (ret && !soap->buflen && r != Z_STREAM_END)
        goto zlib_again;
      ret = soap->buflen;
      if (r == Z_STREAM_END)
      { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Inflated total %lu->%lu bytes\n", soap->d_stream->total_in, soap->d_stream->total_out));
        soap->z_ratio_in = (float)soap->d_stream->total_in / (float)soap->d_stream->total_out;
        soap->d_stream->next_out = Z_NULL;
      }
      DBGLOG(RECV, SOAP_MESSAGE(fdebug, "\n---- decompressed ----\n"));
      DBGMSG(RECV, soap->buf, ret);
#ifndef WITH_LEANER
      if (soap->fpreparerecv && (r = soap->fpreparerecv(soap, soap->buf, ret)))
        return soap->error = r;
#endif
    }
    else
    { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Unable to inflate: (%d) %s\n", r, soap->d_stream->msg?soap->d_stream->msg:SOAP_STR_EOS));
      soap->d_stream->next_out = Z_NULL;
      soap->error = SOAP_ZLIB_ERROR;
      return EOF;
    }
  }
#endif
#ifndef WITH_LEANER
  if (soap->fpreparerecv
#ifdef WITH_ZLIB
   && soap->zlib_in == SOAP_ZLIB_NONE
#endif
   && (r = soap->fpreparerecv(soap, soap->buf + soap->bufidx, ret)))
    return soap->error = r;
#endif
  soap->count += ret;
  return !ret;
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_recv(struct soap *soap)
{ 
#ifndef WITH_LEANER
  if (soap->mode & SOAP_ENC_DIME)
  { if (soap->dime.buflen)
    { char *s;
      int i;
      unsigned char tmp[12];
      DBGLOG(TEST, SOAP_MESSAGE(fdebug, "DIME hdr for chunked DIME is in buffer\n"));
      soap->count += soap->dime.buflen - soap->buflen;
      soap->buflen = soap->dime.buflen;
      DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Skip padding (%ld bytes)\n", -(long)soap->dime.size&3));
      for (i = -(long)soap->dime.size&3; i > 0; i--)
      { soap->bufidx++;
        if (soap->bufidx >= soap->buflen)
          if (soap_recv_raw(soap))
            return EOF;
      }
      DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Get DIME hdr for next chunk\n"));
      s = (char*)tmp;
      for (i = 12; i > 0; i--)
      { *s++ = soap->buf[soap->bufidx++];
        if (soap->bufidx >= soap->buflen)
          if (soap_recv_raw(soap))
            return EOF;
      }
      soap->dime.flags = tmp[0] & 0x7;
      soap->dime.size = ((size_t)tmp[8] << 24) | ((size_t)tmp[9] << 16) | ((size_t)tmp[10] << 8) | ((size_t)tmp[11]);
      DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Get DIME chunk (%u bytes)\n", (unsigned int)soap->dime.size));
      if (soap->dime.flags & SOAP_DIME_CF)
      { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "More chunking\n"));
        soap->dime.chunksize = soap->dime.size;
        if (soap->buflen - soap->bufidx >= soap->dime.size)
        { soap->dime.buflen = soap->buflen;
          soap->buflen = soap->bufidx + soap->dime.chunksize;
        }
        else
          soap->dime.chunksize -= soap->buflen - soap->bufidx;
      }
      else
      { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Last chunk\n"));
        soap->dime.buflen = 0;
        soap->dime.chunksize = 0;
      }
      soap->count = soap->buflen - soap->bufidx;
      DBGLOG(TEST, SOAP_MESSAGE(fdebug, "%u bytes remaining\n", (unsigned int)soap->count));
      return SOAP_OK;
    }
    if (soap->dime.chunksize)
    { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Get next DIME hdr for chunked DIME (%u bytes chunk)\n", (unsigned int)soap->dime.chunksize));
      if (soap_recv_raw(soap))
        return EOF;
      if (soap->buflen - soap->bufidx >= soap->dime.chunksize)
      { soap->dime.buflen = soap->buflen;
        soap->count -= soap->buflen - soap->bufidx - soap->dime.chunksize;
        soap->buflen = soap->bufidx + soap->dime.chunksize;
      }
      else
        soap->dime.chunksize -= soap->buflen - soap->bufidx;
      DBGLOG(TEST, SOAP_MESSAGE(fdebug, "%lu bytes remaining, count=%u\n", (unsigned long)(soap->buflen-soap->bufidx), (unsigned int)soap->count));
      return SOAP_OK;
    }
  }
#endif
  return soap_recv_raw(soap);
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
soap_wchar
SOAP_FMAC2
soap_getchar(struct soap *soap)
{ register soap_wchar c;
  c = soap->ahead;
  if (c)
  { if (c != EOF)
      soap->ahead = 0;
    return c;
  }
  return soap_get1(soap);
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
const struct soap_code_map*
SOAP_FMAC2
soap_code(const struct soap_code_map *code_map, const char *str)
{ if (code_map && str)
  { while (code_map->string)
    { if (!strcmp(str, code_map->string)) /* case sensitive */
        return code_map;
      code_map++;
    }
  }
  return NULL;
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
long
SOAP_FMAC2
soap_code_int(const struct soap_code_map *code_map, const char *str, long other)
{ if (code_map)
  { while (code_map->string)
    { if (!soap_tag_cmp(str, code_map->string)) /* case insensitive */
        return code_map->code;
      code_map++;
    }
  }
  return other;
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
const char*
SOAP_FMAC2
soap_code_str(const struct soap_code_map *code_map, long code)
{ if (!code_map)
    return NULL;
  while (code_map->code != code && code_map->string)
    code_map++;
  return code_map->string;
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
long
SOAP_FMAC2
soap_code_bits(const struct soap_code_map *code_map, const char *str)
{ register long bits = 0;
  if (code_map)
  { while (str && *str)
    { const struct soap_code_map *p;
      for (p = code_map; p->string; p++)
      { register size_t n = strlen(p->string);
        if (!strncmp(p->string, str, n) && soap_blank((soap_wchar)str[n]))
        { bits |= p->code;
          str += n;
          while (*str > 0 && *str <= 32)
            str++;
          break;
        }
      }
      if (!p->string)
        return 0;
    }
  }
  return bits;
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
const char*
SOAP_FMAC2
soap_code_list(struct soap *soap, const struct soap_code_map *code_map, long code)
{ register char *t = soap->tmpbuf;
  if (code_map)
  { while (code_map->string)
    { if (code_map->code & code)
      { register const char *s = code_map->string;
        if (t != soap->tmpbuf)
          *t++ = ' ';
        while (*s && t < soap->tmpbuf + sizeof(soap->tmpbuf) - 1)
          *t++ = *s++;
        if (t == soap->tmpbuf + sizeof(soap->tmpbuf) - 1)
          break;
      }
      code_map++;
    }
  }
  *t = '\0';
  return soap->tmpbuf;
}
#endif

/******************************************************************************/
#ifndef PALM_1
static soap_wchar
soap_char(struct soap *soap)
{ char tmp[8];
  register int i;
  register soap_wchar c;
  register char *s = tmp;
  for (i = 0; i < 7; i++)
  { c = soap_get1(soap);
    if (c == ';' || (int)c == EOF)
      break;
    *s++ = (char)c;
  }
  *s = '\0';
  if (*tmp == '#')
  { if (tmp[1] == 'x' || tmp[1] == 'X')
      return (soap_wchar)soap_strtol(tmp + 2, NULL, 16);
    return (soap_wchar)soap_strtol(tmp + 1, NULL, 10);
  }
  if (!strcmp(tmp, "lt"))
    return '<';
  if (!strcmp(tmp, "gt"))
    return '>';
  if (!strcmp(tmp, "amp"))
    return '&';
  if (!strcmp(tmp, "quot"))
    return '"';
  if (!strcmp(tmp, "apos"))
    return '\'';
#ifndef WITH_LEAN
  return (soap_wchar)soap_code_int(html_entity_codes, tmp, SOAP_UNKNOWN_CHAR);
#else
  return SOAP_UNKNOWN_CHAR; /* use this to represent unknown code */
#endif
}
#endif

/******************************************************************************/
#ifdef WITH_LEAN
#ifndef PALM_1
soap_wchar
soap_get0(struct soap *soap)
{ if (soap->bufidx >= soap->buflen && soap_recv(soap))
    return EOF;
  return (unsigned char)soap->buf[soap->bufidx];
}
#endif
#endif

/******************************************************************************/
#ifdef WITH_LEAN
#ifndef PALM_1
soap_wchar
soap_get1(struct soap *soap)
{ if (soap->bufidx >= soap->buflen && soap_recv(soap))
    return EOF;
  return (unsigned char)soap->buf[soap->bufidx++];
}
#endif
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
soap_wchar
SOAP_FMAC2
soap_get(struct soap *soap)
{ register soap_wchar c;
  c = soap->ahead;
  if (c)
  { if ((int)c != EOF)
      soap->ahead = 0;
  }
  else
    c = soap_get1(soap);
  while ((int)c != EOF)
  { if (soap->cdata)
    { if (c == ']')
      { c = soap_get1(soap);
        if (c == ']')
        { c = soap_get0(soap);
          if (c == '>')
          { soap->cdata = 0;
            soap_get1(soap);
            c = soap_get1(soap);
          }
          else
          { soap_unget(soap, ']');
            return ']';
          }
        }
        else
        { soap_revget1(soap);
          return ']';
        }
      }
      else
        return c;
    }
    switch (c)
    { case '<':
        do c = soap_get1(soap);
        while (soap_blank(c));
        if (c == '!' || c == '?' || c == '%')
        { register int k = 1;
          if (c == '!')
          { c = soap_get1(soap);
            if (c == '[')
            { do c = soap_get1(soap);
              while ((int)c != EOF && c != '[');
              if ((int)c == EOF)
                break;
              soap->cdata = 1;
              c = soap_get1(soap);
              continue;
            }
            if (c == '-' && (c = soap_get1(soap)) == '-')
            { do
              { c = soap_get1(soap);
                if (c == '-' && (c = soap_get1(soap)) == '-')
                  break;
              } while ((int)c != EOF);
            }
          }
          else if (c == '?')
            c = soap_get_pi(soap);
          while ((int)c != EOF)
          { if (c == '<')
              k++;
            else if (c == '>')
            { if (--k <= 0)
                break;
            }
            c = soap_get1(soap);
          }
          if ((int)c == EOF)
            break;
          c = soap_get1(soap);
          continue;
        }
        if (c == '/')
          return SOAP_TT;
        soap_revget1(soap);
        return SOAP_LT;
      case '>':
        return SOAP_GT;
      case '"':
        return SOAP_QT;
      case '\'':
        return SOAP_AP;
      case '&':
        return soap_char(soap) | 0x80000000;
    }
    break;
  }
  return c;
}
#endif

/******************************************************************************/
#ifndef PALM_1
static soap_wchar
soap_get_pi(struct soap *soap)
{ char buf[64];
  register char *s = buf;
  register int i = sizeof(buf);
  register soap_wchar c = soap_getchar(soap);
  /* This is a quick way to parse XML PI and we could use a callback instead to
   * enable applications to intercept processing instructions */
  while ((int)c != EOF && c != '?')
  { if (--i > 0)
    { if (soap_blank(c))
        c = ' ';
      *s++ = (char)c;
    }
    c = soap_getchar(soap);
  }
  *s = '\0';
  DBGLOG(TEST, SOAP_MESSAGE(fdebug, "XML PI <?%s?>\n", buf));
  if (!strncmp(buf, "xml ", 4))
  { s = strstr(buf, " encoding=");
    if (s && s[10])
    { if (!soap_tag_cmp(s + 11, "iso-8859-1*")
       || !soap_tag_cmp(s + 11, "latin1*"))
      { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Switching to latin1 encoding\n"));
        soap->mode |= SOAP_ENC_LATIN;
      }
      else if (!soap_tag_cmp(s + 11, "utf-8*"))
      { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Switching to utf-8 encoding\n"));
        soap->mode &= ~SOAP_ENC_LATIN;
      }
    }
  }
  if ((int)c != EOF)
    c = soap_getchar(soap);
  return c;
}
#endif

/******************************************************************************/
#ifndef WITH_LEANER
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_move(struct soap *soap, long n)
{ DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Moving %ld bytes forward\n", (long)n));
  for (; n > 0; n--)
    if ((int)soap_getchar(soap) == EOF)
      return SOAP_EOF;
  return SOAP_OK;
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_LEANER
#ifndef PALM_1
SOAP_FMAC1
size_t
SOAP_FMAC2
soap_tell(struct soap *soap)
{ return soap->count - soap->buflen + soap->bufidx - (soap->ahead != 0);
}
#endif
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_pututf8(struct soap *soap, register unsigned long c)
{ char tmp[16];
  if (c < 0x80 && c > 0)
  { *tmp = (char)c;
    return soap_send_raw(soap, tmp, 1);
  }
#ifndef WITH_LEAN
  if (c >= 0x80)
  { register char *t = tmp;
    if (c < 0x0800)
      *t++ = (char)(0xC0 | ((c >> 6) & 0x1F));
    else
    { if (c < 0x010000)
        *t++ = (char)(0xE0 | ((c >> 12) & 0x0F));
      else
      { if (c < 0x200000)
          *t++ = (char)(0xF0 | ((c >> 18) & 0x07));
        else
        { if (c < 0x04000000)
            *t++ = (char)(0xF8 | ((c >> 24) & 0x03));
          else
          { *t++ = (char)(0xFC | ((c >> 30) & 0x01));
            *t++ = (char)(0x80 | ((c >> 24) & 0x3F));
          }
          *t++ = (char)(0x80 | ((c >> 18) & 0x3F));
        }     
        *t++ = (char)(0x80 | ((c >> 12) & 0x3F));
      }
      *t++ = (char)(0x80 | ((c >> 6) & 0x3F));
    }
    *t++ = (char)(0x80 | (c & 0x3F));
    *t = '\0';
  }
#else
  sprintf(tmp, "&#%lu;", c);
#endif
  return soap_send(soap, tmp);
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
soap_wchar
SOAP_FMAC2
soap_getutf8(struct soap *soap)
{ register soap_wchar c, c1, c2, c3, c4;
  c = soap->ahead;
  if (c > 0x7F)
  { soap->ahead = 0;
    return c;
  }
  c = soap_get(soap);
  if (c < 0x80 || (soap->mode & SOAP_ENC_LATIN))
    return c;
  c1 = soap_get1(soap);
  if (c1 < 0x80)
  { soap_revget1(soap); /* doesn't look like this is UTF8 */
    return c;
  }
  c1 &= 0x3F;
  if (c < 0xE0)
    return ((soap_wchar)(c & 0x1F) << 6) | c1;
  c2 = (soap_wchar)soap_get1(soap) & 0x3F;
  if (c < 0xF0)
    return ((soap_wchar)(c & 0x0F) << 12) | (c1 << 6) | c2;
  c3 = (soap_wchar)soap_get1(soap) & 0x3F;
  if (c < 0xF8)
    return ((soap_wchar)(c & 0x07) << 18) | (c1 << 12) | (c2 << 6) | c3;
  c4 = (soap_wchar)soap_get1(soap) & 0x3F;
  if (c < 0xFC)
    return ((soap_wchar)(c & 0x03) << 24) | (c1 << 18) | (c2 << 12) | (c3 << 6) | c4;
  return ((soap_wchar)(c & 0x01) << 30) | (c1 << 24) | (c2 << 18) | (c3 << 12) | (c4 << 6) | (soap_wchar)(soap_get1(soap) & 0x3F);
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_puthex(struct soap *soap, const unsigned char *s, int n)
{ char d[2];
  register int i;
#ifdef WITH_DOM
  if ((soap->mode & SOAP_XML_DOM) && soap->dom)
  { if (!(soap->dom->data = soap_s2hex(soap, s, NULL, n)))
      return soap->error;
    return SOAP_OK;
  }
#endif
  for (i = 0; i < n; i++)
  { register int m = *s++;
    d[0] = (char)((m >> 4) + (m > 159 ? '7' : '0'));
    m &= 0x0F;
    d[1] = (char)(m + (m > 9 ? '7' : '0'));
    if (soap_send_raw(soap, d, 2))
      return soap->error;
  }
  return SOAP_OK;
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
unsigned char*
SOAP_FMAC2
soap_gethex(struct soap *soap, int *n)
{
#ifdef WITH_DOM
  if ((soap->mode & SOAP_XML_DOM) && soap->dom)
  { soap->dom->data = soap_string_in(soap, 0, -1, -1);
    return (unsigned char*)soap_hex2s(soap, soap->dom->data, NULL, 0, n);
  }
#endif
#ifdef WITH_FAST
  soap->labidx = 0;
  for (;;)
  { register char *s;
    register size_t i, k;
    if (soap_append_lab(soap, NULL, 0))
      return NULL;
    s = soap->labbuf + soap->labidx;
    k = soap->lablen - soap->labidx;
    soap->labidx = soap->lablen;
    for (i = 0; i < k; i++)
    { register char d1, d2;
      register soap_wchar c;
      c = soap_get(soap);
      if (soap_isxdigit(c))
      { d1 = (char)c;
        c = soap_get(soap); 
        if (soap_isxdigit(c))
          d2 = (char)c;
        else 
        { soap->error = SOAP_TYPE;
          return NULL;
        }
      }
      else
      { unsigned char *p;
        soap_unget(soap, c);
        if (n)
          *n = (int)(soap->lablen + i - k);
        p = (unsigned char*)soap_malloc(soap, soap->lablen + i - k);
        if (p)
          memcpy(p, soap->labbuf, soap->lablen + i - k);
        return p;
      }
      *s++ = ((d1 >= 'A' ? (d1 & 0x7) + 9 : d1 - '0') << 4) + (d2 >= 'A' ? (d2 & 0x7) + 9 : d2 - '0');
    }
  }
#else
  if (soap_new_block(soap) == NULL)
    return NULL;
  for (;;)
  { register int i;
    register char *s = (char*)soap_push_block(soap, NULL, SOAP_BLKLEN);
    if (!s)
    { soap_end_block(soap, NULL);
      return NULL;
    }
    for (i = 0; i < SOAP_BLKLEN; i++)
    { register char d1, d2;
      register soap_wchar c = soap_get(soap);
      if (soap_isxdigit(c))
      { d1 = (char)c;
        c = soap_get(soap); 
        if (soap_isxdigit(c))
          d2 = (char)c;
        else 
        { soap_end_block(soap, NULL);
          soap->error = SOAP_TYPE;
          return NULL;
        }
      }
      else
      { unsigned char *p;
        soap_unget(soap, c);
        if (n)
          *n = (int)soap_size_block(soap, NULL, i);
        p = (unsigned char*)soap_save_block(soap, NULL, 0);
        return p;
      }
      *s++ = ((d1 >= 'A' ? (d1 & 0x7) + 9 : d1 - '0') << 4) + (d2 >= 'A' ? (d2 & 0x7) + 9 : d2 - '0');
    }
  }
#endif
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_putbase64(struct soap *soap, const unsigned char *s, int n)
{ register int i;
  register unsigned long m;
  char d[4];
  if (!s)
    return SOAP_OK;
#ifdef WITH_DOM
  if ((soap->mode & SOAP_XML_DOM) && soap->dom)
  { if (!(soap->dom->data = soap_s2base64(soap, s, NULL, n)))
      return soap->error;
    return SOAP_OK;
  }
#endif
  for (; n > 2; n -= 3, s += 3)
  { m = s[0];
    m = (m << 8) | s[1];
    m = (m << 8) | s[2];
    for (i = 4; i > 0; m >>= 6)
      d[--i] = soap_base64o[m & 0x3F];
    if (soap_send_raw(soap, d, 4))
      return soap->error;
  }
  if (n > 0)
  { m = 0;
    for (i = 0; i < n; i++)
      m = (m << 8) | *s++;
    for (; i < 3; i++)
      m <<= 8;
    for (i++; i > 0; m >>= 6)
      d[--i] = soap_base64o[m & 0x3F];
    for (i = 3; i > n; i--)
      d[i] = '=';
    if (soap_send_raw(soap, d, 4))
      return soap->error;
  }
  return SOAP_OK;
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
unsigned char*
SOAP_FMAC2
soap_getbase64(struct soap *soap, int *n, int malloc_flag)
{ 
#ifdef WITH_DOM
  if ((soap->mode & SOAP_XML_DOM) && soap->dom)
  { soap->dom->data = soap_string_in(soap, 0, -1, -1);
    return (unsigned char*)soap_base642s(soap, soap->dom->data, NULL, 0, n);
  }
#endif
#ifdef WITH_FAST
  soap->labidx = 0;
  for (;;)
  { register size_t i, k;
    register char *s;
    if (soap_append_lab(soap, NULL, 2))
      return NULL;
    s = soap->labbuf + soap->labidx;
    k = soap->lablen - soap->labidx;
    soap->labidx = 3 * (soap->lablen / 3);
    if (!s)
      return NULL;
    if (k > 2)
    { for (i = 0; i < k - 2; i += 3)
      { register unsigned long m = 0;
        register int j = 0;
        do
        { register soap_wchar c = soap_get(soap);
          if (c == '=' || c < 0)
          { unsigned char *p;
            switch (j)
            { case 2:
                *s++ = (char)((m >> 4) & 0xFF);
                i++;
                break;
              case 3:
                *s++ = (char)((m >> 10) & 0xFF);
                *s++ = (char)((m >> 2) & 0xFF);
                i += 2;
            }
            if (n)
              *n = (int)(soap->lablen + i - k);
            p = (unsigned char*)soap_malloc(soap, soap->lablen + i - k);
            if (p)
              memcpy(p, soap->labbuf, soap->lablen + i - k);
            if (c >= 0)
            { while ((int)((c = soap_get(soap)) != EOF) && c != SOAP_LT && c != SOAP_TT)
                ;
            }
            soap_unget(soap, c);
            return p;
          }
          c -= '+';
          if (c >= 0 && c <= 79)
          { register int b = soap_base64i[c];
            if (b >= 64)
            { soap->error = SOAP_TYPE;
              return NULL;  
            }
            m = (m << 6) + b;
            j++;
          }
          else if (!soap_blank(c + '+'))
          { soap->error = SOAP_TYPE;
            return NULL;  
          }
        } while (j < 4);
        *s++ = (char)((m >> 16) & 0xFF);
        *s++ = (char)((m >> 8) & 0xFF);
        *s++ = (char)(m & 0xFF);
      }
    }
  }
#else
  if (soap_new_block(soap) == NULL)
    return NULL;
  for (;;)
  { register int i;
    register char *s = (char*)soap_push_block(soap, NULL, 3 * SOAP_BLKLEN); /* must be multiple of 3 */
    if (!s)
    { soap_end_block(soap, NULL);
      return NULL;
    }
    for (i = 0; i < SOAP_BLKLEN; i++)
    { register unsigned long m = 0;
      register int j = 0;
      do
      { register soap_wchar c = soap_get(soap);
        if (c == '=' || c < 0)
        { unsigned char *p;
          i *= 3;
          switch (j)
          { case 2:
              *s++ = (char)((m >> 4) & 0xFF);
              i++;
              break;
            case 3:
              *s++ = (char)((m >> 10) & 0xFF);
              *s++ = (char)((m >> 2) & 0xFF);
              i += 2;
          }
          if (n)
            *n = (int)soap_size_block(soap, NULL, i);
          p = (unsigned char*)soap_save_block(soap, NULL, 0);
          if (c >= 0)
          { while ((int)((c = soap_get(soap)) != EOF) && c != SOAP_LT && c != SOAP_TT)
              ;
          }
          soap_unget(soap, c);
          return p;
        }
        c -= '+';
        if (c >= 0 && c <= 79)
        { int b = soap_base64i[c];
          if (b >= 64)
          { soap->error = SOAP_TYPE;
            return NULL;  
          }
          m = (m << 6) + b;
          j++;
        }
        else if (!soap_blank(c))
        { soap->error = SOAP_TYPE;
          return NULL;  
        }
      } while (j < 4);
      *s++ = (char)((m >> 16) & 0xFF);
      *s++ = (char)((m >> 8) & 0xFF);
      *s++ = (char)(m & 0xFF);
    }
  }
#endif
}
#endif

/******************************************************************************/
#ifndef WITH_LEANER
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_xop_forward(struct soap *soap, unsigned char **ptr, int *size, char **id, char **type, char **options)
{ /* Check MTOM xop:Include element (within hex/base64Binary) */
  /* TODO: this code to be obsoleted with new import/xop.h conventions */
  int body = soap->body; /* should save type too? */
  if (!soap_peek_element(soap))
  { if (!soap_element_begin_in(soap, "xop:Include", 0, NULL) && *soap->href)
    { if (soap_dime_forward(soap, ptr, size, id, type, options))
        return soap->error;
    }
    if (soap->body && soap_element_end_in(soap, NULL))
      return soap->error;
  }
  soap->body = body;
  return SOAP_OK;
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_LEANER
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_dime_forward(struct soap *soap, unsigned char **ptr, int *size, char **id, char **type, char **options)
{ struct soap_xlist *xp;
  *ptr = NULL;
  *size = 0;
  *id = NULL;
  *type = NULL;
  *options = NULL;
  if (!*soap->href)
    return SOAP_OK;
  *id = soap_strdup(soap, soap->href);
  xp = (struct soap_xlist*)SOAP_MALLOC(soap, sizeof(struct soap_xlist));
  if (!xp)
    return soap->error = SOAP_EOM;
  xp->next = soap->xlist;
  xp->ptr = ptr;
  xp->size = size;
  xp->id = *id;
  xp->type = type;
  xp->options = options;
  soap->xlist = xp;
  return SOAP_OK;
}
#endif
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
char *
SOAP_FMAC2
soap_strdup(struct soap *soap, const char *s)
{ char *t = NULL;
  if (s && (t = (char*)soap_malloc(soap, strlen(s) + 1)))
    strcpy(t, s);
  return t;
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
wchar_t *
SOAP_FMAC2
soap_wstrdup(struct soap *soap, const wchar_t *s)
{ wchar_t *t = NULL;
  if (s)
  { size_t n = 0;
    while (s[n])
      n++;
    if ((t = (wchar_t*)soap_malloc(soap, sizeof(wchar_t)*(n+1))))
      memcpy(t, s, sizeof(wchar_t)*(n+1));
  }
  return t;
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
struct soap_blist*
SOAP_FMAC2
soap_new_block(struct soap *soap)
{ struct soap_blist *p;
  DBGLOG(TEST, SOAP_MESSAGE(fdebug, "New block sequence (prev=%p)\n", soap->blist));
  if (!(p = (struct soap_blist*)SOAP_MALLOC(soap, sizeof(struct soap_blist))))
  { soap->error = SOAP_EOM;   
    return NULL;
  }
  p->next = soap->blist; 
  p->ptr = NULL;
  p->size = 0;
  soap->blist = p;
  return p;
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
void*
SOAP_FMAC2
soap_push_block(struct soap *soap, struct soap_blist *b, size_t n)
{ char *p;
  if (!b)
    b = soap->blist;
  DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Push block of %u bytes (%u bytes total)\n", (unsigned int)n, (unsigned int)b->size + (unsigned int)n));
  if (!(p = (char*)SOAP_MALLOC(soap, n + sizeof(char*) + sizeof(size_t))))
  { soap->error = SOAP_EOM;
    return NULL;
  }
  *(char**)p = b->ptr;
  *(size_t*)(p + sizeof(char*)) = n;
  b->ptr = p;
  b->size += n;
  return p + sizeof(char*) + sizeof(size_t);
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
void
SOAP_FMAC2
soap_pop_block(struct soap *soap, struct soap_blist *b)
{ char *p;
  if (!b)
    b = soap->blist;
  if (!b->ptr)
    return;
  DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Pop block\n"));
  p = b->ptr;
  b->size -= *(size_t*)(p + sizeof(char*));
  b->ptr = *(char**)p;
  SOAP_FREE(soap, p);
}
#endif

/******************************************************************************/
#ifndef WITH_NOIDREF
#ifndef PALM_1
static void
soap_update_ptrs(struct soap *soap, char *start, char *end, char *p1, char *p2)
{ int i;
  register struct soap_ilist *ip = NULL;
  register struct soap_flist *fp = NULL;
#ifndef WITH_LEANER
  register struct soap_xlist *xp = NULL;
#endif
  register void *p, **q;
  for (i = 0; i < SOAP_IDHASH; i++)
  { for (ip = soap->iht[i]; ip; ip = ip->next)
    { if (ip->ptr && (char*)ip->ptr >= start && (char*)ip->ptr < end)
      { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Update id='%s' %p -> %p\n", ip->id, ip->ptr, (char*)ip->ptr + (p1-p2)));
        ip->ptr = (char*)ip->ptr + (p1-p2);
      }
      for (q = &ip->link; q; q = (void**)p)
      { p = *q;
        if (p && (char*)p >= start && (char*)p < end)
        { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Link update id='%s' %p\n", ip->id, p));
          *q = (char*)p + (p1-p2);
        }
      }
      for (q = &ip->copy; q; q = (void**)p)
      { p = *q;
        if (p && (char*)p >= start && (char*)p < end)
        { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Copy chain update id='%s' %p\n", ip->id, p));
          *q = (char*)p + (p1-p2);
        }
      }
      for (fp = ip->flist; fp; fp = fp->next)
      { if ((char*)fp->ptr >= start && (char*)fp->ptr < end)
        { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Copy list update id='%s' %p\n", ip->id, fp));
          fp->ptr = (char*)fp->ptr + (p1-p2);
        }
      }
    }
  }
#ifndef WITH_LEANER
  for (xp = soap->xlist; xp; xp = xp->next)
  { if (xp->ptr && (char*)xp->ptr >= start && (char*)xp->ptr < end)
    { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Update id='%s' %p -> %p\n", xp->id?xp->id:SOAP_STR_EOS, xp->ptr, (char*)xp->ptr + (p1-p2)));
      xp->ptr = (unsigned char**)((char*)xp->ptr + (p1-p2));
      xp->size = (int*)((char*)xp->size + (p1-p2));
      xp->type = (char**)((char*)xp->type + (p1-p2));
      xp->options = (char**)((char*)xp->options + (p1-p2));
    }
  }
#endif
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_NOIDREF
#ifndef PALM_1
static int
soap_has_copies(struct soap *soap, register const char *start, register const char *end)
{ register int i;
  register struct soap_ilist *ip = NULL;
  register struct soap_flist *fp = NULL;
  register const char *p;
  for (i = 0; i < SOAP_IDHASH; i++)
  { for (ip = soap->iht[i]; ip; ip = ip->next)
    { for (p = (const char*)ip->copy; p; p = *(const char**)p)
        if (p >= start && p < end)
          return SOAP_ERR;
      for (fp = ip->flist; fp; fp = fp->next)
        if ((const char*)fp->ptr >= start && (const char*)fp->ptr < end)
          return SOAP_ERR;
    }
  }
  return SOAP_OK;
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_NOIDREF
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_resolve(struct soap *soap)
{ register int i;
  register struct soap_ilist *ip = NULL;
  register struct soap_flist *fp = NULL;
  short flag;
  DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Resolving forwarded data\n"));
  for (i = 0; i < SOAP_IDHASH; i++)
  { for (ip = soap->iht[i]; ip; ip = ip->next)
    { if (ip->ptr)
      { register void *p, **q, *r;
        q = (void**)ip->link;
        ip->link = NULL;
        r = ip->ptr;
        DBGLOG(TEST, if (q) SOAP_MESSAGE(fdebug, "Traversing link chain to resolve id='%s'\n", ip->id));
        while (q)
        { p = *q;
          *q = r;
          DBGLOG(TEST,SOAP_MESSAGE(fdebug, "... link %p -> %p\n", q, r));
          q = (void**)p;
        }
      }
      else if (*ip->id == '#')
      { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Missing data for id='%s'\n", ip->id));
        strcpy(soap->id, ip->id + 1);
        return soap->error = SOAP_MISSING_ID;
      }
    }
  }
  do
  { flag = 0;
    DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Resolution phase\n"));
    for (i = 0; i < SOAP_IDHASH; i++)
    { for (ip = soap->iht[i]; ip; ip = ip->next)
      { if (ip->ptr && !soap_has_copies(soap, (const char*)ip->ptr, (const char*)ip->ptr + ip->size))
        { if (ip->copy)
          { register void *p, **q = (void**)ip->copy;
            DBGLOG(TEST, if (q) SOAP_MESSAGE(fdebug, "Traversing copy chain to resolve id='%s'\n", ip->id));
            ip->copy = NULL;
            do
            { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "... copy %p -> %p (%u bytes)\n", ip->ptr, q, (unsigned int)ip->size));
              p = *q;
              memcpy(q, ip->ptr, ip->size);
              q = (void**)p;
            } while (q);
            flag = 1;
          }
          for (fp = ip->flist; fp; fp = ip->flist)
          { register unsigned int k = fp->level;
            register void *p = ip->ptr;
            DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Resolving forwarded data type=%d location=%p level=%u,%u id='%s'\n", ip->type, p, ip->level, fp->level, ip->id));
            while (ip->level < k)
            { register void **q = (void**)soap_malloc(soap, sizeof(void*));  
              if (!q)
                return soap->error;
              *q = p;
              DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Descending one level, new location=%p holds=%p...\n", q, *q));
              p = (void*)q;
              k--;
            }
            if (fp->fcopy)
              fp->fcopy(soap, ip->type, fp->type, fp->ptr, fp->len, p, ip->size);
            else
              soap_fcopy(soap, ip->type, fp->type, fp->ptr, fp->len, p, ip->size);
            ip->flist = fp->next;
            SOAP_FREE(soap, fp);
            flag = 1;
          }
        }
      }
    }
  } while (flag);
#ifdef SOAP_DEBUG
  for (i = 0; i < SOAP_IDHASH; i++)
  { for (ip = soap->iht[i]; ip; ip = ip->next)
    { if (ip->copy || ip->flist)
      { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Resolution error: forwarded data for id='%s' could not be propagated, please report this problem to the developers\n", ip->id));
      }
    }
  }
#endif
  DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Resolution done\n"));
  return SOAP_OK;
}
#endif
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
size_t
SOAP_FMAC2
soap_size_block(struct soap *soap, struct soap_blist *b, size_t n)
{ if (!b)
    b = soap->blist;
  if (b->ptr)
  { b->size -= *(size_t*)(b->ptr + sizeof(char*)) - n;
    *(size_t*)(b->ptr + sizeof(char*)) = n;
  }
  return b->size;
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
char*
SOAP_FMAC2
soap_first_block(struct soap *soap, struct soap_blist *b)
{ char *p, *q, *r;
  if (!b)
    b = soap->blist;
  p = b->ptr;
  if (!p)
    return NULL;
  DBGLOG(TEST, SOAP_MESSAGE(fdebug, "First block\n"));
  r = NULL;
  do
  { q = *(char**)p;
    *(char**)p = r;
    r = p;
    p = q;
  } while (p);
  b->ptr = r;
  return r + sizeof(char*) + sizeof(size_t);
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
char*
SOAP_FMAC2
soap_next_block(struct soap *soap, struct soap_blist *b)
{ char *p;
  if (!b)
    b = soap->blist;
  p = b->ptr;
  if (p)
  { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Next block\n"));
    b->ptr = *(char**)p;
    SOAP_FREE(soap, p);
    if (b->ptr)
      return b->ptr + sizeof(char*) + sizeof(size_t);
  }
  return NULL;
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
size_t
SOAP_FMAC2
soap_block_size(struct soap *soap, struct soap_blist *b)
{ if (!b)
    b = soap->blist;
  return *(size_t*)(b->ptr + sizeof(char*));
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
void
SOAP_FMAC2
soap_end_block(struct soap *soap, struct soap_blist *b)
{ char *p, *q;
  if (!b)
    b = soap->blist;
  if (b)
  { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "End of block sequence, free all remaining blocks\n"));
    for (p = b->ptr; p; p = q)
    { q = *(char**)p;
      SOAP_FREE(soap, p);
    }
    if (soap->blist == b)
      soap->blist = b->next;
    else
    { struct soap_blist *bp;
      for (bp = soap->blist; bp; bp = bp->next)
      { if (bp->next == b)
        { bp->next = b->next;
	  break;
        }
      }
    }
    SOAP_FREE(soap, b);
  }
  DBGLOG(TEST, if (soap->blist) SOAP_MESSAGE(fdebug, "Restore previous block sequence\n"));
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
char*
SOAP_FMAC2
soap_save_block(struct soap *soap, struct soap_blist *b, char *p, int flag)
{ register size_t n;
  register char *q, *s;
  if (!b)
    b = soap->blist;
  DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Save all blocks in contiguous memory space of %u bytes (%p->%p)\n", (unsigned int)b->size, b->ptr, p));
  if (b->size)
  { if (!p)
      p = (char*)soap_malloc(soap, b->size);
    if (p)
    { for (s = p, q = soap_first_block(soap, b); q; q = soap_next_block(soap, b))
      { n = soap_block_size(soap, b);
#ifndef WITH_NOIDREF
        if (flag)
          soap_update_ptrs(soap, q, q + n, s, q);
#endif
        DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Copy %u bytes from %p to %p\n", (unsigned int)n, q, s));
        memcpy(s, q, n);
        s += n;
      }
    }
    else
      soap->error = SOAP_EOM;
  }
  soap_end_block(soap, b);
  return p;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
char *
SOAP_FMAC2
soap_putsize(struct soap *soap, const char *type, int size)
{ return soap_putsizes(soap, type, &size, 1);
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
char *
SOAP_FMAC2
soap_putsizes(struct soap *soap, const char *type, const int *size, int dim)
{ return soap_putsizesoffsets(soap, type, size, NULL, dim);
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
char *
SOAP_FMAC2
soap_putsizesoffsets(struct soap *soap, const char *type, const int *size, const int *offset, int dim)
{ int i;
  if (!type)
    return NULL;
  if (soap->version == 2)
  { sprintf(soap->type, "%s[%d", type, size[0]);
    for (i = 1; i < dim; i++)
      sprintf(soap->type + strlen(soap->type), " %d", size[i]);
  }
  else
  { if (offset)
    { sprintf(soap->type, "%s[%d", type, size[0] + offset[0]);
      for (i = 1; i < dim; i++)
        sprintf(soap->type + strlen(soap->type), ",%d", size[i] + offset[i]);
    }
    else
    { sprintf(soap->type, "%s[%d", type, size[0]);
      for (i = 1; i < dim; i++)
        sprintf(soap->type + strlen(soap->type), ",%d", size[i]);
    }
    strcat(soap->type, "]");
  }
  return soap->type;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
char *
SOAP_FMAC2
soap_putoffset(struct soap *soap, int offset)
{ return soap_putoffsets(soap, &offset, 1);
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
char *
SOAP_FMAC2
soap_putoffsets(struct soap *soap, const int *offset, int dim)
{ register int i;
  sprintf(soap->arrayOffset, "[%d", offset[0]);
  for (i = 1; i < dim; i++)
    sprintf(soap->arrayOffset + strlen(soap->arrayOffset), ",%d", offset[i]);
  strcat(soap->arrayOffset, "]");
  return soap->arrayOffset;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_size(const int *size, int dim)
{ register int i, n = size[0];
  for (i = 1; i < dim; i++)
    n *= size[i];
  return n;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_getoffsets(const char *attr, const int *size, int *offset, int dim)
{ register int i, j = 0;
  if (offset)
    for (i = 0; i < dim && attr && *attr; i++)
    { attr++;
      j *= size[i];
      j += offset[i] = (int)soap_strtol(attr, NULL, 10);
      attr = strchr(attr, ',');
    }
  else
    for (i = 0; i < dim && attr && *attr; i++)
    { attr++;
      j *= size[i];
      j += (int)soap_strtol(attr, NULL, 10);
      attr = strchr(attr, ',');
    }
  return j;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_getsize(const char *attr1, const char *attr2, int *j)
{ register int n, k;
  char *s;
  *j = 0;
  if (!*attr1)
    return -1;
  if (*attr1 == '[')
    attr1++;
  n = 1;
  for (;;)
  { k = (int)soap_strtol(attr1, &s, 10);
    n *= k;
    if (k < 0 || n > SOAP_MAXARRAYSIZE || s == attr1)
      return -1;
    attr1 = strchr(s, ',');
    if (!attr1)
      attr1 = strchr(s, ' ');
    if (attr2 && *attr2)
    { attr2++;
      *j *= k;
      k = (int)soap_strtol(attr2, &s, 10);
      *j += k;
      if (k < 0)
        return -1;
      attr2 = s;
    }
    if (!attr1)
      break;
    attr1++;
  }
  return n - *j;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_getsizes(const char *attr, int *size, int dim)
{ register int i, k, n;
  if (!*attr)
    return -1;
  i = (int)strlen(attr);
  n = 1;
  do
  { for (i = i-1; i >= 0; i--)
      if (attr[i] == '[' || attr[i] == ',' || attr[i] == ' ')
        break;
    k = (int)soap_strtol(attr + i + 1, NULL, 10);
    n *= size[--dim] = k;
    if (k < 0 || n > SOAP_MAXARRAYSIZE)
      return -1;
  } while (i >= 0 && attr[i] != '[');
  return n;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_getposition(const char *attr, int *pos)
{ register int i, n;
  if (!*attr)
    return -1;
  n = 0;
  i = 1;
  do
  { pos[n++] = (int)soap_strtol(attr + i, NULL, 10);
    while (attr[i] && attr[i] != ',' && attr[i] != ']')
      i++;
    if (attr[i] == ',')
      i++;
  } while (n < SOAP_MAXDIMS && attr[i] && attr[i] != ']');
  return n;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
struct soap_nlist *
SOAP_FMAC2
soap_push_namespace(struct soap *soap, const char *id, const char *ns)
{ register struct soap_nlist *np;
  register struct Namespace *p;
  register short i = -1;
  register size_t n, k;
  n = strlen(id);
  k = strlen(ns) + 1;
  p = soap->local_namespaces;
  if (p)
  { for (i = 0; p->id; p++, i++)
    { if (p->ns && !strcmp(ns, p->ns))
      { if (p->out)
        { SOAP_FREE(soap, p->out);
          p->out = NULL;
        }
        break;
      }
      if (p->out)
      { if (!strcmp(ns, p->out))
          break;
      }
      else if (p->in)
      { if (!soap_tag_cmp(ns, p->in))
        { if ((p->out = (char*)SOAP_MALLOC(soap, k)))
            strcpy(p->out, ns);
          break;
        }
      }
    }
    if (!p || !p->id)
      i = -1;
  }
  if (i >= 0)
    k = 0;
  np = (struct soap_nlist*)SOAP_MALLOC(soap, sizeof(struct soap_nlist) + n + k);
  if (!np)
  { soap->error = SOAP_EOM;
    return NULL;
  }
  np->next = soap->nlist;
  soap->nlist = np;
  np->level = soap->level;
  np->index = i;
  strcpy(np->id, id);
  DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Push namespace binding (level=%u) '%s' '%s'\n", soap->level, id, ns));
  if (i < 0)
  { np->ns = strcpy(np->id + n + 1, ns);
    DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Push NOT OK: no match found for '%s' in namespace mapping table (added to stack anyway)\n", ns));
  }
  else
  { np->ns = NULL;
    DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Push OK ('%s' matches '%s' in namespace table)\n", id, p->id));
  }
  return np;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
void
SOAP_FMAC2
soap_pop_namespace(struct soap *soap)
{ register struct soap_nlist *np, *nq;
  for (np = soap->nlist; np && np->level >= soap->level; np = nq)
  { nq = np->next;
    DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Pop namespace binding (level=%u) '%s'\n", soap->level, np->id));
    SOAP_FREE(soap, np);
  }
  soap->nlist = np;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_match_namespace(struct soap *soap, const char *id1, const char *id2, size_t n1, size_t n2) 
{ register struct soap_nlist *np = soap->nlist;
  const char *s;
  while (np && (strncmp(np->id, id1, n1) || np->id[n1]))
    np = np->next;
  if (np)
  { if (!(soap->mode & SOAP_XML_IGNORENS))
      if (np->index < 0
       || ((s = soap->local_namespaces[np->index].id) && (strncmp(s, id2, n2) || (s[n2] && s[n2] != '_'))))
        return SOAP_NAMESPACE;
    return SOAP_OK;
  }
  if (n1 == 0)
    return (soap->mode & SOAP_XML_IGNORENS) ? SOAP_OK : SOAP_NAMESPACE;
  if ((n1 == 3 && n1 == n2 && !strncmp(id1, "xml", 3) && !strncmp(id1, id2, 3))
   || (soap->mode & SOAP_XML_IGNORENS))
    return SOAP_OK;
  return soap->error = SOAP_SYNTAX_ERROR; 
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
const char*
SOAP_FMAC2
soap_current_namespace(struct soap *soap, const char *tag)
{ register struct soap_nlist *np;
  register const char *s;
  if (!tag || !strncmp(tag, "xml", 3))
    return NULL;
  np = soap->nlist;
  if (!(s = strchr(tag, ':')))
  { while (np && *np->id) /* find default namespace, if present */
      np = np->next;
  }
  else
  { while (np && (strncmp(np->id, tag, s - tag) || np->id[s - tag]))
      np = np->next;
    if (!np)
      soap->error = SOAP_NAMESPACE;
  }
  if (np)
  { if (np->index >= 0)
      return soap->namespaces[np->index].ns;
    if (np->ns)
      return soap_strdup(soap, np->ns);
  }
  return NULL;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_tag_cmp(const char *s, const char *t)
{ for (;;)
  { register int c1 = *s;
    register int c2 = *t;
    if (!c1 || c1 == '"')
      break;
    if (c2 != '-')
    { if (c1 != c2)
      { if (c1 >= 'A' && c1 <= 'Z')
          c1 += 'a' - 'A';
        if (c2 >= 'A' && c2 <= 'Z')
          c2 += 'a' - 'A';
      }
      if (c1 != c2)
      { if (c2 != '*')
          return 1;
        c2 = *++t;
        if (!c2)
          return 0;
        if (c2 >= 'A' && c2 <= 'Z')
          c2 += 'a' - 'A';
        for (;;)
        { c1 = *s;
          if (!c1 || c1 == '"')
            break;
          if (c1 >= 'A' && c1 <= 'Z')
            c1 += 'a' - 'A';
          if (c1 == c2 && !soap_tag_cmp(s + 1, t + 1))
            return 0;
          s++;
        }
        break;
      }
    }
    s++;
    t++;
  }
  if (*t == '*' && !t[1])
    return 0;
  return *t;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_match_tag(struct soap *soap, const char *tag1, const char *tag2)
{ register const char *s, *t;
  register int err;
  if (!tag1 || !tag2 || !*tag2)
    return SOAP_OK;
  s = strchr(tag1, ':');
  t = strchr(tag2, ':');
  if (t)
  { if (s)
    { if (t[1] && SOAP_STRCMP(s + 1, t + 1))
        return SOAP_TAG_MISMATCH;
      if (t != tag2 && (err = soap_match_namespace(soap, tag1, tag2, s - tag1, t - tag2)))
      { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Tags '%s' and '%s' match but namespaces differ\n", tag1, tag2));
        if (err == SOAP_NAMESPACE)
          return SOAP_TAG_MISMATCH;
        return err;
      }
    } 
    else if (SOAP_STRCMP(tag1, t + 1))
    { return SOAP_TAG_MISMATCH;
    }
    else if (t != tag2 && (err = soap_match_namespace(soap, tag1, tag2, 0, t - tag2)))
    { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Tags '%s' and '%s' match but namespaces differ\n", tag1, tag2));
      if (err == SOAP_NAMESPACE)
        return SOAP_TAG_MISMATCH;
      return err;
    }
    DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Tags and (default) namespaces match: '%s' '%s'\n", tag1, tag2));
    return SOAP_OK;
  }
  if (s)
  { if (SOAP_STRCMP(s + 1, tag2))
      return SOAP_TAG_MISMATCH;
  }
  else if (SOAP_STRCMP(tag1, tag2))
    return SOAP_TAG_MISMATCH;
  DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Tags match: '%s' '%s'\n", tag1, tag2));
  return SOAP_OK;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_match_array(struct soap *soap, const char *type)
{ if (*soap->arrayType)
    if (soap_match_tag(soap, soap->arrayType, type)
     && soap_match_tag(soap, soap->arrayType, "xsd:anyType")
     && soap_match_tag(soap, soap->arrayType, "xsd:ur-type")
    )
    { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Array type mismatch: '%s' '%s'\n", soap->arrayType, type));
      return SOAP_TAG_MISMATCH;
    }
  return SOAP_OK;
}
#endif

/******************************************************************************\
 *
 *	SSL/TLS
 *
\******************************************************************************/

/******************************************************************************/
#ifdef WITH_OPENSSL
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_rand()
{ unsigned char buf[4];
  if (!soap_ssl_init_done)
    soap_ssl_init();
  RAND_pseudo_bytes(buf, 4);
  return *(int*)buf;
}
#endif
#endif

/******************************************************************************/
#if defined(WITH_OPENSSL) || defined(WITH_GNUTLS)
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_ssl_server_context(struct soap *soap, unsigned short flags, const char *keyfile, const char *password, const char *cafile, const char *capath, const char *dhfile, const char *randfile, const char *sid)
{ int err;
  soap->keyfile = keyfile;
  soap->password = password;
  soap->cafile = cafile;
  soap->capath = capath;
  soap->crlfile = NULL;
#ifdef WITH_OPENSSL
  soap->dhfile = dhfile;
  soap->randfile = randfile;
#endif
  soap->ssl_flags = flags | (dhfile == NULL ? SOAP_SSL_RSA : 0);
#ifdef WITH_GNUTLS
  if (dhfile)
  { char *s;
    int n = (int)soap_strtoul(dhfile, &s, 10);
    if (!soap->dh_params)
      gnutls_dh_params_init(&soap->dh_params);
    /* if dhfile is numeric, treat it as a key length to generate DH params which can take a while */
    if (n >= 512 && s && *s == '\0')
      gnutls_dh_params_generate2(soap->dh_params, (unsigned int)n);
    else
    { unsigned int dparams_len;
      unsigned char dparams_buf[1024];
      FILE *fd = fopen(dhfile, "r");
      if (!fd)
        return soap_set_receiver_error(soap, "SSL/TLS error", "Invalid DH file", SOAP_SSL_ERROR);
      dparams_len = (unsigned int)fread(dparams_buf, 1, sizeof(dparams_buf), fd);
      fclose(fd);
      gnutls_datum_t dparams = { dparams_buf, dparams_len };
      if (gnutls_dh_params_import_pkcs3(soap->dh_params, &dparams, GNUTLS_X509_FMT_PEM))
        return soap_set_receiver_error(soap, "SSL/TLS error", "Invalid DH file", SOAP_SSL_ERROR);
    }
  }
  else
  { if (!soap->rsa_params)
      gnutls_rsa_params_init(&soap->rsa_params);
    gnutls_rsa_params_generate2(soap->rsa_params, SOAP_SSL_RSA_BITS);
  }
  if (soap->session)
  { gnutls_deinit(soap->session);
    soap->session = NULL;
  }
  if (soap->xcred)
  { gnutls_certificate_free_credentials(soap->xcred);
    soap->xcred = NULL;
  }
#endif
  err = soap->fsslauth(soap);
#ifdef WITH_OPENSSL
  if (!err)
  { if (sid)
      SSL_CTX_set_session_id_context(soap->ctx, (unsigned char*)sid, (unsigned int)strlen(sid));
    else
      SSL_CTX_set_session_cache_mode(soap->ctx, SSL_SESS_CACHE_OFF);
  }
#endif
  return err; 
}
#endif
#endif

/******************************************************************************/
#if defined(WITH_OPENSSL) || defined(WITH_GNUTLS)
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_ssl_client_context(struct soap *soap, unsigned short flags, const char *keyfile, const char *password, const char *cafile, const char *capath, const char *randfile)
{ soap->keyfile = keyfile;
  soap->password = password;
  soap->cafile = cafile;
  soap->capath = capath;
  soap->ssl_flags = SOAP_SSL_CLIENT | flags;
#ifdef WITH_OPENSSL
  soap->dhfile = NULL;
  soap->randfile = randfile;
  soap->fsslverify = (flags & SOAP_SSL_ALLOW_EXPIRED_CERTIFICATE) == 0 ? ssl_verify_callback : ssl_verify_callback_allow_expired_certificate;
#endif
#ifdef WITH_GNUTLS
  if (soap->session)
  { gnutls_deinit(soap->session);
    soap->session = NULL;
  }
  if (soap->xcred)
  { gnutls_certificate_free_credentials(soap->xcred);
    soap->xcred = NULL;
  }
#endif
  return soap->fsslauth(soap);
}
#endif
#endif

/******************************************************************************/
#if defined(WITH_OPENSSL) || defined(WITH_GNUTLS)
#ifndef PALM_2
SOAP_FMAC1
void
SOAP_FMAC2
soap_ssl_init()
{ /* Note: for MT systems, the main program MUST call soap_ssl_init() before any threads are started */
  if (!soap_ssl_init_done)
  { soap_ssl_init_done = 1;
#ifdef WITH_OPENSSL
    SSL_library_init();
#ifndef WITH_LEAN
    SSL_load_error_strings();
#endif
    if (!RAND_load_file("/dev/urandom", 1024))
    { char buf[1024];
      RAND_seed(buf, sizeof(buf));
      while (!RAND_status())
      { int r = rand();
        RAND_seed(&r, sizeof(int));
      }
    }
#endif
#ifdef WITH_GNUTLS
# if defined(HAVE_PTHREAD_H)
    gcry_control(GCRYCTL_SET_THREAD_CBS, &gcry_threads_pthread);
# elif defined(HAVE_PTH_H)
    gcry_control(GCRYCTL_SET_THREAD_CBS, &gcry_threads_pth);
# endif
    gcry_control(GCRYCTL_ENABLE_QUICK_RANDOM, 0);
    gcry_control(GCRYCTL_DISABLE_SECMEM, 0);
    gcry_control(GCRYCTL_INITIALIZATION_FINISHED, 0); /* libgcrypt init done */
    gnutls_global_init();
#endif
  }
}
#endif
#endif

/******************************************************************************/
#if defined(WITH_OPENSSL) || defined(WITH_GNUTLS)
#ifndef PALM_1
SOAP_FMAC1
const char *
SOAP_FMAC2
soap_ssl_error(struct soap *soap, int ret)
{
#ifdef WITH_OPENSSL
  int err = SSL_get_error(soap->ssl, ret);
  const char *msg = soap_code_str(h_ssl_error_codes, err);
  if (msg)
    strcpy(soap->msgbuf, msg);
  else
    return ERR_error_string(err, soap->msgbuf);
  if (ERR_peek_error())
  { unsigned long r;
    strcat(soap->msgbuf, "\n");
    while ((r = ERR_get_error()))
      ERR_error_string_n(r, soap->msgbuf + strlen(soap->msgbuf), sizeof(soap->msgbuf) - strlen(soap->msgbuf));
  } 
  else
  { switch (ret)
    { case 0:
        strcpy(soap->msgbuf, "EOF was observed that violates the protocol. The client probably provided invalid authentication information.");
        break;
      case -1:
        sprintf(soap->msgbuf, "Error observed by underlying BIO: %s", strerror(errno));  
        break;
    }
  }
  return soap->msgbuf;
#endif
#ifdef WITH_GNUTLS
  return gnutls_strerror(ret);
#endif
}
#endif
#endif

/******************************************************************************/
#if defined(WITH_OPENSSL) || defined(WITH_GNUTLS)
#ifndef PALM_1
static int
ssl_auth_init(struct soap *soap)
{
#ifdef WITH_OPENSSL
  long flags;
  int mode;
  if (!soap_ssl_init_done)
    soap_ssl_init();
  ERR_clear_error();
  if (!soap->ctx)
  { if (!(soap->ctx = SSL_CTX_new(SSLv23_method())))
      return soap_set_receiver_error(soap, "SSL/TLS error", "Can't setup context", SOAP_SSL_ERROR);
    /* The following alters the behavior of SSL read/write: */
#if 0
    SSL_CTX_set_mode(soap->ctx, SSL_MODE_ENABLE_PARTIAL_WRITE | SSL_MODE_AUTO_RETRY);
#endif
  }
  if (soap->randfile)
  { if (!RAND_load_file(soap->randfile, -1))
      return soap_set_receiver_error(soap, "SSL/TLS error", "Can't load randomness", SOAP_SSL_ERROR);
  }
  if (soap->cafile || soap->capath)
  { if (!SSL_CTX_load_verify_locations(soap->ctx, soap->cafile, soap->capath))
      return soap_set_receiver_error(soap, "SSL/TLS error", "Can't read CA file", SOAP_SSL_ERROR);
    if (soap->cafile && (soap->ssl_flags & SOAP_SSL_REQUIRE_CLIENT_AUTHENTICATION))
      SSL_CTX_set_client_CA_list(soap->ctx, SSL_load_client_CA_file(soap->cafile));
  }
  if (!(soap->ssl_flags & SOAP_SSL_NO_DEFAULT_CA_PATH))
  { if (!SSL_CTX_set_default_verify_paths(soap->ctx))
      return soap_set_receiver_error(soap, "SSL/TLS error", "Can't read default CA file and/or directory", SOAP_SSL_ERROR);
  }
/* This code assumes a typical scenario, see alternative code below */
  if (soap->keyfile)
  { if (!SSL_CTX_use_certificate_chain_file(soap->ctx, soap->keyfile))
      return soap_set_receiver_error(soap, "SSL/TLS error", "Can't read certificate key file", SOAP_SSL_ERROR);
    if (soap->password)
    { SSL_CTX_set_default_passwd_cb_userdata(soap->ctx, (void*)soap->password);
      SSL_CTX_set_default_passwd_cb(soap->ctx, ssl_password);
    }
    if (!SSL_CTX_use_PrivateKey_file(soap->ctx, soap->keyfile, SSL_FILETYPE_PEM))
      return soap_set_receiver_error(soap, "SSL/TLS error", "Can't read key file", SOAP_SSL_ERROR);
  }
/* Suggested alternative approach to check the key file for certs (cafile=NULL):*/
#if 0
  if (soap->password)
  { SSL_CTX_set_default_passwd_cb_userdata(soap->ctx, (void*)soap->password);
    SSL_CTX_set_default_passwd_cb(soap->ctx, ssl_password);
  }
  if (!soap->cafile || !SSL_CTX_use_certificate_chain_file(soap->ctx, soap->cafile))
  { if (soap->keyfile)
    { if (!SSL_CTX_use_certificate_chain_file(soap->ctx, soap->keyfile))
        return soap_set_receiver_error(soap, "SSL/TLS error", "Can't read certificate or key file", SOAP_SSL_ERROR);
      if (!SSL_CTX_use_PrivateKey_file(soap->ctx, soap->keyfile, SSL_FILETYPE_PEM))
        return soap_set_receiver_error(soap, "SSL/TLS error", "Can't read key file", SOAP_SSL_ERROR);
    }
  }
#endif
  if ((soap->ssl_flags & SOAP_SSL_RSA))
  { RSA *rsa = RSA_generate_key(SOAP_SSL_RSA_BITS, RSA_F4, NULL, NULL);
    if (!SSL_CTX_set_tmp_rsa(soap->ctx, rsa))
    { if (rsa)
        RSA_free(rsa);
      return soap_set_receiver_error(soap, "SSL/TLS error", "Can't set RSA key", SOAP_SSL_ERROR);
    }
    RSA_free(rsa);
  }
  else if (soap->dhfile)
  { DH *dh = 0;
    char *s;
    int n = (int)soap_strtoul(soap->dhfile, &s, 10);
    /* if dhfile is numeric, treat it as a key length to generate DH params which can take a while */
    if (n >= 512 && s && *s == '\0')
      dh = DH_generate_parameters(n, 2/*or 5*/, NULL, NULL);
    else
    { BIO *bio;
      bio = BIO_new_file(soap->dhfile, "r");
      if (!bio)
        return soap_set_receiver_error(soap, "SSL/TLS error", "Can't read DH file", SOAP_SSL_ERROR);
      dh = PEM_read_bio_DHparams(bio, NULL, NULL, NULL);
      BIO_free(bio);
    }
    if (!dh || DH_check(dh, &n) != 1 || SSL_CTX_set_tmp_dh(soap->ctx, dh) < 0)
    { if (dh)
        DH_free(dh);
      return soap_set_receiver_error(soap, "SSL/TLS error", "Can't set DH parameters", SOAP_SSL_ERROR);
    }
    DH_free(dh);
  }
  flags = (SSL_OP_ALL | SSL_OP_NO_SSLv2);
  if ((soap->ssl_flags & SOAP_SSLv3))
    flags |= SSL_OP_NO_TLSv1;
  if ((soap->ssl_flags & SOAP_TLSv1))
    flags |= SSL_OP_NO_SSLv3;
#ifdef SSL_OP_NO_TICKET
  /* TLS extension is enabled by default in OPENSSL v0.9.8k
     Disable it by adding SSL_OP_NO_TICKET */
  flags |= SSL_OP_NO_TICKET;
#endif
  SSL_CTX_set_options(soap->ctx, flags);
  if ((soap->ssl_flags & SOAP_SSL_REQUIRE_CLIENT_AUTHENTICATION))
    mode = (SSL_VERIFY_PEER | SSL_VERIFY_FAIL_IF_NO_PEER_CERT);
  else if ((soap->ssl_flags & SOAP_SSL_REQUIRE_SERVER_AUTHENTICATION))
    mode = SSL_VERIFY_PEER;
  else
    mode = SSL_VERIFY_NONE;
  SSL_CTX_set_verify(soap->ctx, mode, soap->fsslverify);
#if (OPENSSL_VERSION_NUMBER < 0x00905100L)
  SSL_CTX_set_verify_depth(soap->ctx, 1); 
#else
  SSL_CTX_set_verify_depth(soap->ctx, 9); 
#endif  
#endif
#ifdef WITH_GNUTLS
  int ret;
  if (!soap_ssl_init_done)
    soap_ssl_init();
  if (!soap->xcred)
  { gnutls_certificate_allocate_credentials(&soap->xcred);
    if (soap->cafile)
    { if (gnutls_certificate_set_x509_trust_file(soap->xcred, soap->cafile, GNUTLS_X509_FMT_PEM) < 0)
        return soap_set_receiver_error(soap, "SSL/TLS error", "Can't read CA file", SOAP_SSL_ERROR);
    }
    if (soap->crlfile)
    { if (gnutls_certificate_set_x509_crl_file(soap->xcred, soap->crlfile, GNUTLS_X509_FMT_PEM) < 0)
        return soap_set_receiver_error(soap, "SSL/TLS error", "Can't read CRL file", SOAP_SSL_ERROR);
    }
    if (soap->keyfile)
    { if (gnutls_certificate_set_x509_key_file(soap->xcred, soap->keyfile, soap->keyfile, GNUTLS_X509_FMT_PEM) < 0) /* TODO: GNUTLS need to concat cert and key in single key file */
        return soap_set_receiver_error(soap, "SSL/TLS error", "Can't read key file", SOAP_SSL_ERROR);
    }
  }
  if ((soap->ssl_flags & SOAP_SSL_CLIENT))
  { gnutls_init(&soap->session, GNUTLS_CLIENT);
    if (soap->cafile || soap->crlfile || soap->keyfile)
    { ret = gnutls_priority_set_direct(soap->session, "PERFORMANCE", NULL);
      if (ret < 0)
        return soap_set_receiver_error(soap, soap_ssl_error(soap, ret), "SSL/TLS set priority error", SOAP_SSL_ERROR);
      gnutls_credentials_set(soap->session, GNUTLS_CRD_CERTIFICATE, soap->xcred);
    }
    else
    { if (!soap->acred)
        gnutls_anon_allocate_client_credentials(&soap->acred);
      gnutls_init(&soap->session, GNUTLS_CLIENT);
      gnutls_priority_set_direct(soap->session, "PERFORMANCE:+ANON-DH:!ARCFOUR-128", NULL);
      gnutls_credentials_set(soap->session, GNUTLS_CRD_ANON, soap->acred);
    }
  }
  else
  { if (!soap->keyfile)
      return soap_set_receiver_error(soap, "SSL/TLS error", "No key file: anonymous server authentication not supported in this release", SOAP_SSL_ERROR);
    if ((soap->ssl_flags & SOAP_SSL_RSA) && soap->rsa_params)
      gnutls_certificate_set_rsa_export_params(soap->xcred, soap->rsa_params);
    else if (soap->dh_params)
      gnutls_certificate_set_dh_params(soap->xcred, soap->dh_params);
    if (!soap->cache)
      gnutls_priority_init(&soap->cache, "NORMAL", NULL);
    gnutls_init(&soap->session, GNUTLS_SERVER);
    gnutls_priority_set(soap->session, soap->cache);
    gnutls_credentials_set(soap->session, GNUTLS_CRD_CERTIFICATE, soap->xcred);
    if ((soap->ssl_flags & SOAP_SSL_REQUIRE_CLIENT_AUTHENTICATION))
      gnutls_certificate_server_set_request(soap->session, GNUTLS_CERT_REQUEST);
    gnutls_session_enable_compatibility_mode(soap->session);
    if ((soap->ssl_flags & SOAP_TLSv1))
    { int protocol_priority[] = { GNUTLS_TLS1_0, 0 };
      if (gnutls_protocol_set_priority(soap->session, protocol_priority) != GNUTLS_E_SUCCESS)
        return soap_set_receiver_error(soap, "SSL/TLS error", "Can't set TLS v1.0 protocol", SOAP_SSL_ERROR);
    }
  }
#endif
  return SOAP_OK;
}
#endif
#endif

/******************************************************************************/
#ifdef WITH_OPENSSL
#ifndef PALM_1
static int
ssl_password(char *buf, int num, int rwflag, void *userdata)
{ if (num < (int)strlen((char*)userdata) + 1)
    return 0;
  return (int)strlen(strcpy(buf, (char*)userdata));
}
#endif
#endif

/******************************************************************************/
#ifdef WITH_OPENSSL
#ifndef PALM_1
static int
ssl_verify_callback(int ok, X509_STORE_CTX *store)
{
#ifdef SOAP_DEBUG
  if (!ok) 
  { char data[256];
    X509 *cert = X509_STORE_CTX_get_current_cert(store);
    fprintf(stderr, "SSL verify error or warning with certificate at depth %d: %s\n", X509_STORE_CTX_get_error_depth(store), X509_verify_cert_error_string(X509_STORE_CTX_get_error(store)));
    X509_NAME_oneline(X509_get_issuer_name(cert), data, sizeof(data));
    fprintf(stderr, "certificate issuer %s\n", data);
    X509_NAME_oneline(X509_get_subject_name(cert), data, sizeof(data));
    fprintf(stderr, "certificate subject %s\n", data);
  }
#endif
  /* Note: return 1 to continue, but unsafe progress will be terminated by OpenSSL */
  return ok;
}
#endif
#endif

/******************************************************************************/
#ifdef WITH_OPENSSL
#ifndef PALM_1
static int
ssl_verify_callback_allow_expired_certificate(int ok, X509_STORE_CTX *store)
{ ok = ssl_verify_callback(ok, store);
  if (ok == 0 && X509_STORE_CTX_get_error(store) == X509_V_ERR_CERT_HAS_EXPIRED)
  {
#ifdef SOAP_DEBUG
    fprintf(stderr, "ignoring certificate expiration\n");
#endif
    X509_STORE_CTX_set_error(store, X509_V_OK);
    ok = 1;
  }
  /* Note: return 1 to continue, but unsafe progress will be terminated by SSL */
  return ok;
}
#endif
#endif

/******************************************************************************/
#ifdef WITH_GNUTLS
static const char *
ssl_verify(struct soap *soap, const char *host)
{ unsigned int status;
  const char *err = NULL;
  int r = gnutls_certificate_verify_peers2(soap->session, &status); 
  if (r < 0)
    err = "Certificate verify error";
  else if ((status & GNUTLS_CERT_INVALID))
    err = "The certificate is not trusted";
  else if ((status & GNUTLS_CERT_SIGNER_NOT_FOUND))
    err = "The certificate hasn't got a known issuer";
  else if ((status & GNUTLS_CERT_REVOKED))
    err = "The certificate has been revoked";
  else if (gnutls_certificate_type_get(soap->session) == GNUTLS_CRT_X509)
  { gnutls_x509_crt_t cert;
    const gnutls_datum_t *cert_list;
    unsigned int cert_list_size;
    if (gnutls_x509_crt_init(&cert) < 0)
      err = "Could not get X509 certificates";
    else if ((cert_list = gnutls_certificate_get_peers(soap->session, &cert_list_size)) == NULL)
      err = "Could not get X509 certificates";
    else if (gnutls_x509_crt_import(cert, &cert_list[0], GNUTLS_X509_FMT_DER) < 0)
      err = "Error parsing X509 certificate";
    else if (!(soap->ssl_flags & SOAP_SSL_ALLOW_EXPIRED_CERTIFICATE) && gnutls_x509_crt_get_expiration_time(cert) < time(NULL))
      err = "The certificate has expired";
    else if (!(soap->ssl_flags & SOAP_SSL_ALLOW_EXPIRED_CERTIFICATE) && gnutls_x509_crt_get_activation_time(cert) > time(NULL))
      err = "The certificate is not yet activated";
    else if (host && !(soap->ssl_flags & SOAP_SSL_SKIP_HOST_CHECK))
    { if (!gnutls_x509_crt_check_hostname(cert, host))
        err = "Certificate host name mismatch";
    }
    gnutls_x509_crt_deinit(cert);
  }
  return err;
}
#endif

/******************************************************************************/
#if defined(WITH_OPENSSL) || defined(WITH_GNUTLS)
#ifndef WITH_NOIO
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_ssl_accept(struct soap *soap)
{ SOAP_SOCKET fd = soap->socket;
#ifdef WITH_OPENSSL
  BIO *bio;
  int retries, r, s;
  if (!soap_valid_socket(fd))
    return soap_set_receiver_error(soap, "SSL/TLS error", "No socket in soap_ssl_accept()", SOAP_SSL_ERROR);
  soap->ssl_flags &= ~SOAP_SSL_CLIENT;
  if (!soap->ctx && (soap->error = soap->fsslauth(soap)))
    return soap->error;
  if (!soap->ssl)
  { soap->ssl = SSL_new(soap->ctx);
    if (!soap->ssl)
      return soap_set_receiver_error(soap, "SSL/TLS error", "SSL_new() failed in soap_ssl_accept()", SOAP_SSL_ERROR);
  }
  else
    SSL_clear(soap->ssl);
  bio = BIO_new_socket((int)fd, BIO_NOCLOSE);
  SSL_set_bio(soap->ssl, bio, bio);
  /* Set SSL sockets to non-blocking */
  retries = 0;
  if (soap->accept_timeout)
  { SOAP_SOCKNONBLOCK(fd)
    retries = 10*soap->accept_timeout;
  }
  if (retries <= 0)
    retries = 100; /* timeout: 10 sec retries, 100 times 0.1 sec */
  while ((r = SSL_accept(soap->ssl)) <= 0)
  { int err;
    if (retries-- <= 0)
      break;
    err = SSL_get_error(soap->ssl, r);
    if (err == SSL_ERROR_WANT_ACCEPT || err == SSL_ERROR_WANT_READ || err == SSL_ERROR_WANT_WRITE)
    { if (err == SSL_ERROR_WANT_READ)
        s = tcp_select(soap, fd, SOAP_TCP_SELECT_RCV | SOAP_TCP_SELECT_ERR, -100000);
      else
        s = tcp_select(soap, fd, SOAP_TCP_SELECT_SND | SOAP_TCP_SELECT_ERR, -100000);
      if (s < 0 && soap->errnum != SOAP_EINTR)
        break;
    }
    else
    { soap->errnum = soap_socket_errno(fd);
      break;
    }
  }
  if (r <= 0)
  { soap_set_receiver_error(soap, soap_ssl_error(soap, r), "SSL_accept() failed in soap_ssl_accept()", SOAP_SSL_ERROR);
    soap_closesock(soap);
    return SOAP_SSL_ERROR;
  }
  if ((soap->ssl_flags & SOAP_SSL_REQUIRE_CLIENT_AUTHENTICATION))
  { X509 *peer;
    int err;
    if ((err = SSL_get_verify_result(soap->ssl)) != X509_V_OK)
    { soap_closesock(soap);
      return soap_set_sender_error(soap, X509_verify_cert_error_string(err), "SSL certificate presented by peer cannot be verified in soap_ssl_accept()", SOAP_SSL_ERROR);
    }
    peer = SSL_get_peer_certificate(soap->ssl);
    if (!peer)
    { soap_closesock(soap);
      return soap_set_sender_error(soap, "SSL/TLS error", "No SSL certificate was presented by the peer in soap_ssl_accept()", SOAP_SSL_ERROR);
    }
    X509_free(peer);
  }
#endif
#ifdef WITH_GNUTLS
  int retries = 0, r;
  if (!soap_valid_socket(fd))
    return soap_set_receiver_error(soap, "SSL/TLS error", "No socket in soap_ssl_accept()", SOAP_SSL_ERROR);
  soap->ssl_flags &= ~SOAP_SSL_CLIENT;
  if (!soap->session && (soap->error = soap->fsslauth(soap)))
  { soap_closesock(soap);
    return soap->error;
  }
  gnutls_transport_set_ptr(soap->session, (gnutls_transport_ptr_t)(long)fd);
  /* Set SSL sockets to non-blocking */
  if (soap->accept_timeout)
  { SOAP_SOCKNONBLOCK(fd)
    retries = 10*soap->accept_timeout;
  }
  if (retries <= 0)
    retries = 100; /* timeout: 10 sec retries, 100 times 0.1 sec */
  while ((r = gnutls_handshake(soap->session)))
  { int s;
    /* GNUTLS repeat handhake when GNUTLS_E_AGAIN */
    if (retries-- <= 0)
      break;
    if (r == GNUTLS_E_AGAIN || r == GNUTLS_E_INTERRUPTED)
    { if (!gnutls_record_get_direction(soap->session))
        s = tcp_select(soap, fd, SOAP_TCP_SELECT_RCV | SOAP_TCP_SELECT_ERR, -100000);
      else
        s = tcp_select(soap, fd, SOAP_TCP_SELECT_SND | SOAP_TCP_SELECT_ERR, -100000);
      if (s < 0 && soap->errnum != SOAP_EINTR)
        break;
    }
    else
    { soap->errnum = soap_socket_errno(fd);
      break;
    }
  }
  if (r)
  { soap_closesock(soap);
    return soap_set_receiver_error(soap, soap_ssl_error(soap, r), "SSL/TLS handshake failed", SOAP_SSL_ERROR);
  }
  if ((soap->ssl_flags & SOAP_SSL_REQUIRE_CLIENT_AUTHENTICATION))
  { const char *err = ssl_verify(soap, NULL);
    if (err)
    { soap_closesock(soap);
      return soap_set_receiver_error(soap, "SSL/TLS error", err, SOAP_SSL_ERROR);
    }
  }
#endif
  if (soap->recv_timeout || soap->send_timeout)
    SOAP_SOCKNONBLOCK(fd)
  else
    SOAP_SOCKBLOCK(fd)
  soap->imode |= SOAP_ENC_SSL;
  soap->omode |= SOAP_ENC_SSL;
  return SOAP_OK;
}
#endif
#endif
#endif

/******************************************************************************\
 *
 *	TCP/UDP [SSL/TLS] IPv4 and IPv6
 *
\******************************************************************************/

/******************************************************************************/
#ifndef WITH_NOIO
#ifndef PALM_1
static int
tcp_init(struct soap *soap)
{ soap->errmode = 1;
#ifdef WIN32
  if (tcp_done)
    return 0;
  else
  { WSADATA w;
    if (WSAStartup(MAKEWORD(1, 1), &w))
      return -1;
    tcp_done = 1;
  }
#endif
  return 0;
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_NOIO
#ifndef PALM_1
static const char*
tcp_error(struct soap *soap)
{ register const char *msg = NULL;
  switch (soap->errmode)
  { case 0:
      msg = soap_strerror(soap);
      break;
    case 1:
      msg = "WSAStartup failed";
      break;
    case 2:
    {
#ifndef WITH_LEAN
      msg = soap_code_str(h_error_codes, soap->errnum);
      if (!msg)
#endif
      { sprintf(soap->msgbuf, "TCP/UDP IP error %d", soap->errnum);
        msg = soap->msgbuf;
      }
    }
  }
  return msg;
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_IPV6
#ifndef WITH_NOIO
#ifndef PALM_1
static int
tcp_gethost(struct soap *soap, const char *addr, struct in_addr *inaddr)
{ soap_int32 iadd = -1;
  struct hostent hostent, *host = &hostent;
#ifdef VXWORKS
  int hostint;
  /* inet_addr(), and hostGetByName() expect "char *"; addr is a "const char *". */
  iadd = inet_addr((char*)addr);
#else
#if defined(_AIX43) || ((defined(TRU64) || defined(HP_UX)) && defined(HAVE_GETHOSTBYNAME_R))
  struct hostent_data ht_data;
#endif
#ifdef AS400
  iadd = inet_addr((void*)addr);
#else
  iadd = inet_addr(addr);
#endif
#endif
  if (iadd != -1)
  { memcpy(inaddr, &iadd, sizeof(iadd));
    return SOAP_OK;
  }
#if defined(__GLIBC__) || (defined(HAVE_GETHOSTBYNAME_R) && (defined(FREEBSD) || defined(__FreeBSD__)))
  if (gethostbyname_r(addr, &hostent, soap->buf, SOAP_BUFLEN, &host, &soap->errnum) < 0)
    host = NULL;
#elif defined(_AIX43) || ((defined(TRU64) || defined(HP_UX)) && defined(HAVE_GETHOSTBYNAME_R))
  memset((void*)&ht_data, 0, sizeof(ht_data));
  if (gethostbyname_r(addr, &hostent, &ht_data) < 0)
  { host = NULL;
    soap->errnum = h_errno;
  }
#elif defined(HAVE_GETHOSTBYNAME_R)
  host = gethostbyname_r(addr, &hostent, soap->buf, SOAP_BUFLEN, &soap->errnum);
#elif defined(VXWORKS)
  /* If the DNS resolver library resolvLib has been configured in the vxWorks
   * image, a query for the host IP address is sent to the DNS server, if the
   * name was not found in the local host table. */
  hostint = hostGetByName((char*)addr);
  if (hostint == ERROR)
  { host = NULL;
    soap->errnum = soap_errno; 
  }
#else
#ifdef AS400
  if (!(host = gethostbyname((void*)addr)))
    soap->errnum = h_errno;
#else
  if (!(host = gethostbyname(addr)))
    soap->errnum = h_errno;
#endif
#endif
  if (!host)
  { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Host name not found\n"));
    return SOAP_ERR;
  }
#ifdef VXWORKS
  inaddr->s_addr = hostint;
#else
  memcpy(inaddr, host->h_addr, host->h_length);
#endif
  return SOAP_OK;
}
#endif
#endif
#endif

/******************************************************************************/
#ifndef WITH_NOIO
#ifndef PALM_1
static SOAP_SOCKET
tcp_connect(struct soap *soap, const char *endpoint, const char *host, int port)
{
#ifdef WITH_IPV6
  struct addrinfo hints, *res, *ressave;
#endif
  SOAP_SOCKET fd;
  int err = 0;
#ifndef WITH_LEAN
#ifndef WITH_WIN32
  int len = SOAP_BUFLEN;
#else
  int len = SOAP_BUFLEN + 1; /* speeds up windows xfer */
#endif
  int set = 1;
#endif
#if !defined(WITH_LEAN) || defined(WITH_OPENSSL) || defined(WITH_GNUTLS)
  int retries;
#endif
  if (soap_valid_socket(soap->socket))
    soap->fclosesocket(soap, soap->socket);
  soap->socket = SOAP_INVALID_SOCKET;
  if (tcp_init(soap))
  { soap->errnum = 0;
    soap_set_sender_error(soap, tcp_error(soap), "TCP init failed in tcp_connect()", SOAP_TCP_ERROR);
    return SOAP_INVALID_SOCKET;
  }
  soap->errmode = 0;
#ifdef WITH_IPV6
  memset((void*)&hints, 0, sizeof(hints));
  hints.ai_family = PF_UNSPEC;
#ifndef WITH_LEAN
  if ((soap->omode & SOAP_IO_UDP))
    hints.ai_socktype = SOCK_DGRAM;
  else
#endif
    hints.ai_socktype = SOCK_STREAM;
  soap->errmode = 2;
  if (soap->proxy_host)
    err = getaddrinfo(soap->proxy_host, soap_int2s(soap, soap->proxy_port), &hints, &res);
  else
    err = getaddrinfo(host, soap_int2s(soap, port), &hints, &res);
  if (err)
  { soap_set_sender_error(soap, SOAP_GAI_STRERROR(err), "getaddrinfo failed in tcp_connect()", SOAP_TCP_ERROR);
    return SOAP_INVALID_SOCKET;
  }
  ressave = res;
again:
  fd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
  soap->errmode = 0;
#else
#ifndef WITH_LEAN
again:
#endif
#ifndef WITH_LEAN
  if ((soap->omode & SOAP_IO_UDP))
    fd = socket(AF_INET, SOCK_DGRAM, 0);
  else
#endif
    fd = socket(AF_INET, SOCK_STREAM, 0);
#endif
  if (!soap_valid_socket(fd))
  {
#ifdef WITH_IPV6
    if (res->ai_next)
    { res = res->ai_next;
      goto again;
    }
#endif
    soap->errnum = soap_socket_errno(fd);
    soap_set_sender_error(soap, tcp_error(soap), "socket failed in tcp_connect()", SOAP_TCP_ERROR);
#ifdef WITH_IPV6
    freeaddrinfo(ressave);
#endif
    return SOAP_INVALID_SOCKET;
  }
#ifdef SOCKET_CLOSE_ON_EXEC
#ifdef WIN32
#ifndef UNDER_CE
  SetHandleInformation((HANDLE)fd, HANDLE_FLAG_INHERIT, 0);
#endif
#else
  fcntl(fd, F_SETFD, 1);
#endif
#endif
#ifndef WITH_LEAN
  if (soap->connect_flags == SO_LINGER)
  { struct linger linger;
    memset((void*)&linger, 0, sizeof(linger));
    linger.l_onoff = 1;
    linger.l_linger = soap->linger_time;
    if (setsockopt(fd, SOL_SOCKET, SO_LINGER, (char*)&linger, sizeof(struct linger)))
    { soap->errnum = soap_socket_errno(fd);
      soap_set_sender_error(soap, tcp_error(soap), "setsockopt SO_LINGER failed in tcp_connect()", SOAP_TCP_ERROR);
      soap->fclosesocket(soap, fd);
#ifdef WITH_IPV6
      freeaddrinfo(ressave);
#endif
      return SOAP_INVALID_SOCKET;
    }
  }
  else if (soap->connect_flags && setsockopt(fd, SOL_SOCKET, soap->connect_flags, (char*)&set, sizeof(int)))
  { soap->errnum = soap_socket_errno(fd);
    soap_set_sender_error(soap, tcp_error(soap), "setsockopt failed in tcp_connect()", SOAP_TCP_ERROR);
    soap->fclosesocket(soap, fd);
#ifdef WITH_IPV6
    freeaddrinfo(ressave);
#endif
    return SOAP_INVALID_SOCKET;
  }
  if ((soap->keep_alive || soap->tcp_keep_alive) && setsockopt(fd, SOL_SOCKET, SO_KEEPALIVE, (char*)&set, sizeof(int)))
  { soap->errnum = soap_socket_errno(fd);
    soap_set_sender_error(soap, tcp_error(soap), "setsockopt SO_KEEPALIVE failed in tcp_connect()", SOAP_TCP_ERROR);
    soap->fclosesocket(soap, fd);
#ifdef WITH_IPV6
    freeaddrinfo(ressave);
#endif
    return SOAP_INVALID_SOCKET;
  }
  if (setsockopt(fd, SOL_SOCKET, SO_SNDBUF, (char*)&len, sizeof(int)))
  { soap->errnum = soap_socket_errno(fd);
    soap_set_sender_error(soap, tcp_error(soap), "setsockopt SO_SNDBUF failed in tcp_connect()", SOAP_TCP_ERROR);
    soap->fclosesocket(soap, fd);
#ifdef WITH_IPV6
    freeaddrinfo(ressave);
#endif
    return SOAP_INVALID_SOCKET;
  }
  if (setsockopt(fd, SOL_SOCKET, SO_RCVBUF, (char*)&len, sizeof(int)))
  { soap->errnum = soap_socket_errno(fd);
    soap_set_sender_error(soap, tcp_error(soap), "setsockopt SO_RCVBUF failed in tcp_connect()", SOAP_TCP_ERROR);
    soap->fclosesocket(soap, fd);
#ifdef WITH_IPV6
    freeaddrinfo(ressave);
#endif
    return SOAP_INVALID_SOCKET;
  }
#ifdef TCP_KEEPIDLE
  if (soap->tcp_keep_idle && setsockopt((SOAP_SOCKET)fd, IPPROTO_TCP, TCP_KEEPIDLE, (char*)&(soap->tcp_keep_idle), sizeof(int)))
  { soap->errnum = soap_socket_errno(fd);
    soap_set_sender_error(soap, tcp_error(soap), "setsockopt TCP_KEEPIDLE failed in tcp_connect()", SOAP_TCP_ERROR);
    soap->fclosesocket(soap, (SOAP_SOCKET)fd);
#ifdef WITH_IPV6
    freeaddrinfo(ressave);
#endif
    return SOAP_INVALID_SOCKET;
  }
#endif
#ifdef TCP_KEEPINTVL
  if (soap->tcp_keep_intvl && setsockopt((SOAP_SOCKET)fd, IPPROTO_TCP, TCP_KEEPINTVL, (char*)&(soap->tcp_keep_intvl), sizeof(int)))
  { soap->errnum = soap_socket_errno(fd);
    soap_set_sender_error(soap, tcp_error(soap), "setsockopt TCP_KEEPINTVL failed in tcp_connect()", SOAP_TCP_ERROR);
    soap->fclosesocket(soap, (SOAP_SOCKET)fd);
#ifdef WITH_IPV6
    freeaddrinfo(ressave);
#endif
    return SOAP_INVALID_SOCKET;
  }
#endif
#ifdef TCP_KEEPCNT
  if (soap->tcp_keep_cnt && setsockopt((SOAP_SOCKET)fd, IPPROTO_TCP, TCP_KEEPCNT, (char*)&(soap->tcp_keep_cnt), sizeof(int)))
  { soap->errnum = soap_socket_errno(fd);
    soap_set_sender_error(soap, tcp_error(soap), "setsockopt TCP_KEEPCNT failed in tcp_connect()", SOAP_TCP_ERROR);
    soap->fclosesocket(soap, (SOAP_SOCKET)fd);
#ifdef WITH_IPV6
    freeaddrinfo(ressave);
#endif
    return SOAP_INVALID_SOCKET;
  }
#endif
#ifdef TCP_NODELAY
  if (!(soap->omode & SOAP_IO_UDP) && setsockopt(fd, IPPROTO_TCP, TCP_NODELAY, (char*)&set, sizeof(int)))
  { soap->errnum = soap_socket_errno(fd);
    soap_set_sender_error(soap, tcp_error(soap), "setsockopt TCP_NODELAY failed in tcp_connect()", SOAP_TCP_ERROR);
    soap->fclosesocket(soap, fd);
#ifdef WITH_IPV6
    freeaddrinfo(ressave);
#endif
    return SOAP_INVALID_SOCKET;
  }
#endif
#ifdef WITH_IPV6
  if ((soap->omode & SOAP_IO_UDP) && soap->ipv6_multicast_if)
  { struct sockaddr_in6 *in6addr = (struct sockaddr_in6*)res->ai_addr;
    in6addr->sin6_scope_id = soap->ipv6_multicast_if;
  }
#endif
#ifdef IP_MULTICAST_TTL
  if ((soap->omode & SOAP_IO_UDP) && soap->ipv4_multicast_if && !soap->ipv6_multicast_if)
  { if (soap->ipv4_multicast_ttl > 0)
    { char ttl = (char)(soap->ipv4_multicast_ttl);
      if (setsockopt(fd, IPPROTO_IP, IP_MULTICAST_TTL, (char*)&ttl, sizeof(ttl)))
      { soap->errnum = soap_socket_errno(fd);
        soap_set_sender_error(soap, tcp_error(soap), "setsockopt IP_MULTICAST_TTL failed in tcp_connect()", SOAP_TCP_ERROR);
        soap->fclosesocket(soap, fd);
        return SOAP_INVALID_SOCKET;
      }
    }
#ifndef WINDOWS
    if (setsockopt(fd, IPPROTO_IP, IP_MULTICAST_IF, (char*)soap->ipv4_multicast_if, sizeof(struct in_addr))) 
    { soap->errnum = soap_socket_errno(fd);
      soap_set_sender_error(soap, tcp_error(soap), "setsockopt IP_MULTICAST_IF failed in tcp_connect()", SOAP_TCP_ERROR);
      soap->fclosesocket(soap, fd);
      return SOAP_INVALID_SOCKET;
    }
#else
#ifndef IP_MULTICAST_IF
#define IP_MULTICAST_IF 2
#endif
    if (setsockopt(fd, IPPROTO_IP, IP_MULTICAST_IF, (char*)soap->ipv4_multicast_if, sizeof(struct in_addr))) 
    { soap->errnum = soap_socket_errno(fd);
      soap_set_sender_error(soap, tcp_error(soap), "setsockopt IP_MULTICAST_IF failed in tcp_connect()", SOAP_TCP_ERROR);
      soap->fclosesocket(soap, fd);
      return SOAP_INVALID_SOCKET;
    }
#endif
  }
#endif
#endif
  DBGLOG(TEST,SOAP_MESSAGE(fdebug, "Opening socket %d to host='%s' port=%d\n", fd, host, port));
#ifndef WITH_IPV6
  soap->peerlen = sizeof(soap->peer);
  memset((void*)&soap->peer, 0, sizeof(soap->peer));
  soap->peer.sin_family = AF_INET;
  soap->errmode = 2;
  if (soap->proxy_host)
  { if (soap->fresolve(soap, soap->proxy_host, &soap->peer.sin_addr))
    { soap_set_sender_error(soap, tcp_error(soap), "get proxy host by name failed in tcp_connect()", SOAP_TCP_ERROR);
      soap->fclosesocket(soap, fd);
      return SOAP_INVALID_SOCKET;
    }
    soap->peer.sin_port = htons((short)soap->proxy_port);
  }
  else
  { if (soap->fresolve(soap, host, &soap->peer.sin_addr))
    { soap_set_sender_error(soap, tcp_error(soap), "get host by name failed in tcp_connect()", SOAP_TCP_ERROR);
      soap->fclosesocket(soap, fd);
      return SOAP_INVALID_SOCKET;
    }
    soap->peer.sin_port = htons((short)port);
  }
  soap->errmode = 0;
#ifndef WITH_LEAN
  if ((soap->omode & SOAP_IO_UDP))
    return fd;
#endif
#else
  if ((soap->omode & SOAP_IO_UDP))
  { memcpy(&soap->peer, res->ai_addr, res->ai_addrlen);
    soap->peerlen = res->ai_addrlen;
    freeaddrinfo(ressave);
    return fd;
  }
#endif
#ifndef WITH_LEAN
  if (soap->connect_timeout)
    SOAP_SOCKNONBLOCK(fd)
  else
    SOAP_SOCKBLOCK(fd)
  retries = 10;
#endif
  for (;;)
  { 
#ifdef WITH_IPV6
    if (connect(fd, res->ai_addr, (int)res->ai_addrlen))
#else
    if (connect(fd, (struct sockaddr*)&soap->peer, sizeof(soap->peer)))
#endif
    { err = soap_socket_errno(fd);
#ifndef WITH_LEAN
      if (err == SOAP_EADDRINUSE)
      { soap->fclosesocket(soap, fd);
        if (retries-- > 0)
          goto again;
      }
      else if (soap->connect_timeout && (err == SOAP_EINPROGRESS || err == SOAP_EAGAIN || err == SOAP_EWOULDBLOCK))
      {
        SOAP_SOCKLEN_T k;
        for (;;)
        { register int r;
          r = tcp_select(soap, fd, SOAP_TCP_SELECT_SND, soap->connect_timeout);
          if (r > 0)
            break;
          if (!r)
          { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Connect timeout\n"));
            soap_set_sender_error(soap, "Timeout", "connect failed in tcp_connect()", SOAP_TCP_ERROR);
            soap->fclosesocket(soap, fd);
#ifdef WITH_IPV6
            freeaddrinfo(ressave);
#endif
            return SOAP_INVALID_SOCKET;
          }
	  r = soap->errnum;
          if (r != SOAP_EINTR)
          { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Could not connect to host\n"));
            soap_set_sender_error(soap, tcp_error(soap), "connect failed in tcp_connect()", SOAP_TCP_ERROR);
            soap->fclosesocket(soap, fd);
#ifdef WITH_IPV6
            freeaddrinfo(ressave);
#endif
            return SOAP_INVALID_SOCKET;
          }
        }
        k = (SOAP_SOCKLEN_T)sizeof(soap->errnum);
        if (!getsockopt(fd, SOL_SOCKET, SO_ERROR, (char*)&soap->errnum, &k) && !soap->errnum)	/* portability note: see SOAP_SOCKLEN_T definition in stdsoap2.h */
          break;
        DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Could not connect to host\n"));
        if (!soap->errnum)
          soap->errnum = soap_socket_errno(fd);
        soap_set_sender_error(soap, tcp_error(soap), "connect failed in tcp_connect()", SOAP_TCP_ERROR);
        soap->fclosesocket(soap, fd);
#ifdef WITH_IPV6
        freeaddrinfo(ressave);
#endif
        return SOAP_INVALID_SOCKET;
      }
#endif
#ifdef WITH_IPV6
      if (res->ai_next)
      { res = res->ai_next;
        soap->fclosesocket(soap, fd);
        goto again;
      }
#endif
      if (err && err != SOAP_EINTR)
      { soap->errnum = err;
        DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Could not connect to host\n"));
        soap_set_sender_error(soap, tcp_error(soap), "connect failed in tcp_connect()", SOAP_TCP_ERROR);
        soap->fclosesocket(soap, fd);
#ifdef WITH_IPV6
        freeaddrinfo(ressave);
#endif
        return SOAP_INVALID_SOCKET;
      }
    }  
    else
      break;
  }
#ifdef WITH_IPV6
  soap->peerlen = 0; /* IPv6: already connected so use send() */
  freeaddrinfo(ressave);
#endif
  soap->socket = fd;
  soap->imode &= ~SOAP_ENC_SSL;
  soap->omode &= ~SOAP_ENC_SSL;
  if (!soap_tag_cmp(endpoint, "https:*"))
  {
#if defined(WITH_OPENSSL) || defined(WITH_GNUTLS)
#ifdef WITH_OPENSSL
    BIO *bio;
#endif
    int r;
    if (soap->proxy_host)
    { soap_mode m = soap->mode; /* preserve settings */
      soap_mode om = soap->omode; /* make sure we only parse HTTP */
      size_t n = soap->count; /* save the content length */
      const char *userid, *passwd;
      soap->omode &= ~SOAP_ENC; /* mask IO and ENC */
      soap->omode |= SOAP_IO_BUFFER;
      DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Connecting to %s proxy server\n", soap->proxy_http_version));
      sprintf(soap->tmpbuf, "CONNECT %s:%d HTTP/%s", host, port, soap->proxy_http_version);
      if (soap_begin_send(soap)
       || (soap->error = soap->fposthdr(soap, soap->tmpbuf, NULL)))
      { soap->fclosesocket(soap, fd);
        return SOAP_INVALID_SOCKET;
      }
#ifndef WITH_LEAN
      if (soap->proxy_userid && soap->proxy_passwd && strlen(soap->proxy_userid) + strlen(soap->proxy_passwd) < 761)
      { sprintf(soap->tmpbuf + 262, "%s:%s", soap->proxy_userid, soap->proxy_passwd);
        strcpy(soap->tmpbuf, "Basic ");
        soap_s2base64(soap, (const unsigned char*)(soap->tmpbuf + 262), soap->tmpbuf + 6, (int)strlen(soap->tmpbuf + 262));
        if ((soap->error = soap->fposthdr(soap, "Proxy-Authorization", soap->tmpbuf)))
        { soap->fclosesocket(soap, fd);
          return soap->error;
        }
      }
#endif
      if ((soap->error = soap->fposthdr(soap, NULL, NULL))
       || soap_flush(soap))
      { soap->fclosesocket(soap, fd);
        return SOAP_INVALID_SOCKET;
      }
      soap->omode = om;
      om = soap->imode;
      soap->imode &= ~SOAP_ENC; /* mask IO and ENC */
      userid = soap->userid; /* preserve */
      passwd = soap->passwd; /* preserve */
      if ((soap->error = soap->fparse(soap)))
      { soap->fclosesocket(soap, fd);
        return SOAP_INVALID_SOCKET;
      }
      soap->userid = userid; /* restore */
      soap->passwd = passwd; /* restore */
      soap->imode = om; /* restore */
      soap->count = n; /* restore */
      if (soap_begin_send(soap))
      { soap->fclosesocket(soap, fd);
        return SOAP_INVALID_SOCKET;
      }
      if (endpoint)
        strncpy(soap->endpoint, endpoint, sizeof(soap->endpoint)-1); /* restore */
      soap->mode = m;
    }
#ifdef WITH_OPENSSL
    soap->ssl_flags |= SOAP_SSL_CLIENT;
    if (!soap->ctx && (soap->error = soap->fsslauth(soap)))
    { soap->fclosesocket(soap, fd);
      return SOAP_INVALID_SOCKET;
    }
    if (!soap->ssl)
    { soap->ssl = SSL_new(soap->ctx);
      if (!soap->ssl)
      { soap->fclosesocket(soap, fd);
        soap->error = SOAP_SSL_ERROR;
        return SOAP_INVALID_SOCKET;
      }
    }
    else
      SSL_clear(soap->ssl);
    if (soap->session)
    { if (!strcmp(soap->session_host, host) && soap->session_port == port)
        SSL_set_session(soap->ssl, soap->session);
      SSL_SESSION_free(soap->session);
      soap->session = NULL;
    }
    soap->imode |= SOAP_ENC_SSL;
    soap->omode |= SOAP_ENC_SSL;
    bio = BIO_new_socket((int)fd, BIO_NOCLOSE);
    SSL_set_bio(soap->ssl, bio, bio);
    /* Connect timeout: set SSL sockets to non-blocking */
    retries = 0;
    if (soap->connect_timeout)
    { SOAP_SOCKNONBLOCK(fd)
      retries = 10*soap->connect_timeout;
    }
    else
      SOAP_SOCKBLOCK(fd)
    if (retries <= 0)
      retries = 100; /* timeout: 10 sec retries, 100 times 0.1 sec */
    /* Try connecting until success or timeout (when nonblocking) */
    do
    { if ((r = SSL_connect(soap->ssl)) <= 0)
      { int err = SSL_get_error(soap->ssl, r);
        if (err == SSL_ERROR_WANT_CONNECT || err == SSL_ERROR_WANT_READ || err == SSL_ERROR_WANT_WRITE)
        { register int s;
	  if (err == SSL_ERROR_WANT_READ)
            s = tcp_select(soap, fd, SOAP_TCP_SELECT_RCV | SOAP_TCP_SELECT_ERR, -100000);
          else
            s = tcp_select(soap, fd, SOAP_TCP_SELECT_SND | SOAP_TCP_SELECT_ERR, -100000);
          if (s < 0 && soap->errnum != SOAP_EINTR)
          { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "SSL_connect/select error in tcp_connect\n"));
            soap_set_sender_error(soap, soap_ssl_error(soap, r), "SSL_connect failed in tcp_connect()", SOAP_TCP_ERROR);
            soap->fclosesocket(soap, fd);
            return SOAP_INVALID_SOCKET;
          }
	  if (s == 0 && retries-- <= 0)
          { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "SSL/TLS connect timeout\n"));
            soap_set_sender_error(soap, "Timeout", "SSL_connect failed in tcp_connect()", SOAP_TCP_ERROR);
            soap->fclosesocket(soap, fd);
            return SOAP_INVALID_SOCKET;
          }
        }
	else
        { soap_set_sender_error(soap, soap_ssl_error(soap, r), "SSL_connect error in tcp_connect()", SOAP_SSL_ERROR);
          soap->fclosesocket(soap, fd);
          return SOAP_INVALID_SOCKET;
        }
      }
    } while (!SSL_is_init_finished(soap->ssl));
    /* Set SSL sockets to nonblocking */
    SOAP_SOCKNONBLOCK(fd)
    /* Check server credentials when required */
    if ((soap->ssl_flags & SOAP_SSL_REQUIRE_SERVER_AUTHENTICATION))
    { int err;
      if ((err = SSL_get_verify_result(soap->ssl)) != X509_V_OK)
      { soap_set_sender_error(soap, X509_verify_cert_error_string(err), "SSL/TLS certificate presented by peer cannot be verified in tcp_connect()", SOAP_SSL_ERROR);
        soap->fclosesocket(soap, fd);
        return SOAP_INVALID_SOCKET;
      }
      if (!(soap->ssl_flags & SOAP_SSL_SKIP_HOST_CHECK))
      { X509_NAME *subj;
        int ext_count;
        int ok = 0;
        X509 *peer;
        peer = SSL_get_peer_certificate(soap->ssl);
        if (!peer)
        { soap_set_sender_error(soap, "SSL/TLS error", "No SSL/TLS certificate was presented by the peer in tcp_connect()", SOAP_SSL_ERROR);
          soap->fclosesocket(soap, fd);
          return SOAP_INVALID_SOCKET;
        }
        ext_count = X509_get_ext_count(peer);
        if (ext_count > 0)
        { int i;
          for (i = 0; i < ext_count; i++)
          { X509_EXTENSION *ext = X509_get_ext(peer, i);
            const char *ext_str = OBJ_nid2sn(OBJ_obj2nid(X509_EXTENSION_get_object(ext)));
            if (ext_str && !strcmp(ext_str, "subjectAltName"))
            { X509V3_EXT_METHOD *meth = (X509V3_EXT_METHOD*)X509V3_EXT_get(ext);
              void *ext_data;
#if (OPENSSL_VERSION_NUMBER >= 0x0090800fL)
              const unsigned char *data;
#else
              unsigned char *data;
#endif
              STACK_OF(CONF_VALUE) *val;
              int j;
              if (!meth)
                break;
              data = ext->value->data;
#if (OPENSSL_VERSION_NUMBER > 0x00907000L)
              if (meth->it) 
                ext_data = ASN1_item_d2i(NULL, &data, ext->value->length, ASN1_ITEM_ptr(meth->it));
              else
              { /* OpenSSL not perfectly portable at this point (?):
                   Some compilers appear to prefer
                     meth->d2i(NULL, (const unsigned char**)&data, ...
                   and others prefer
                     meth->d2i(NULL, &data, ext->value->length);
                */
                ext_data = meth->d2i(NULL, &data, ext->value->length);
              }
#else
              ext_data = meth->d2i(NULL, &data, ext->value->length);
#endif
              if (ext_data)
              { val = meth->i2v(meth, ext_data, NULL);
		if (val)
                { for (j = 0; j < sk_CONF_VALUE_num(val); j++)
                  { CONF_VALUE *nval = sk_CONF_VALUE_value(val, j);
                    if (nval && !strcmp(nval->name, "DNS") && !strcmp(nval->value, host))
                    { ok = 1;
                      break;
                    }
                  }
                  sk_CONF_VALUE_pop_free(val, X509V3_conf_free);
                }
#if (OPENSSL_VERSION_NUMBER > 0x00907000L)
                if (meth->it)
                  ASN1_item_free((ASN1_VALUE*)ext_data, ASN1_ITEM_ptr(meth->it));
                else
                  meth->ext_free(ext_data);
#else
                meth->ext_free(ext_data);
#endif
	      }
            }
            if (ok)
              break;
          }
        }
        if (!ok && (subj = X509_get_subject_name(peer)))
        { int i = -1;
          do
          { ASN1_STRING *name;
            i = X509_NAME_get_index_by_NID(subj, NID_commonName, i);
            if (i == -1)
              break;
            name = X509_NAME_ENTRY_get_data(X509_NAME_get_entry(subj, i));
            if (name)
            { if (!soap_tag_cmp(host, (const char*)M_ASN1_STRING_data(name)))
                ok = 1;
              else
              { unsigned char *tmp = NULL;
                ASN1_STRING_to_UTF8(&tmp, name);
                if (tmp)
                { if (!soap_tag_cmp(host, (const char*)tmp))
                    ok = 1;
                  OPENSSL_free(tmp);
                }
              }
            }
          } while (!ok);
        }
        X509_free(peer);
        if (!ok)
        { soap_set_sender_error(soap, "SSL/TLS error", "SSL/TLS certificate host name mismatch in tcp_connect()", SOAP_SSL_ERROR);
          soap->fclosesocket(soap, fd);
          return SOAP_INVALID_SOCKET;
        }
      }
    }
#endif
#ifdef WITH_GNUTLS
    soap->ssl_flags |= SOAP_SSL_CLIENT;
    if (!soap->session && (soap->error = soap->fsslauth(soap)))
    { soap->fclosesocket(soap, fd);
      return SOAP_INVALID_SOCKET;
    }
    gnutls_transport_set_ptr(soap->session, (gnutls_transport_ptr_t)(long)fd);
    /* Set SSL sockets to non-blocking */
    if (soap->connect_timeout)
    { SOAP_SOCKNONBLOCK(fd)
      retries = 10*soap->connect_timeout;
    }
    else
      SOAP_SOCKBLOCK(fd)
    if (retries <= 0)
      retries = 100; /* timeout: 10 sec retries, 100 times 0.1 sec */
    while ((r = gnutls_handshake(soap->session)))
    { int s;
      /* GNUTLS repeat handhake when GNUTLS_E_AGAIN */
      if (retries-- <= 0)
        break;
      if (r == GNUTLS_E_AGAIN || r == GNUTLS_E_INTERRUPTED)
      { if (!gnutls_record_get_direction(soap->session))
          s = tcp_select(soap, fd, SOAP_TCP_SELECT_RCV | SOAP_TCP_SELECT_ERR, -100000);
        else
          s = tcp_select(soap, fd, SOAP_TCP_SELECT_SND | SOAP_TCP_SELECT_ERR, -100000);
        if (s < 0 && soap->errnum != SOAP_EINTR)
          break;
      }
      else
      { soap->errnum = soap_socket_errno(fd);
        break;
      }
    }
    if (r)
    { soap_set_sender_error(soap, soap_ssl_error(soap, r), "SSL/TLS handshake failed", SOAP_SSL_ERROR);
      soap->fclosesocket(soap, fd);
      return SOAP_INVALID_SOCKET;
    }
    if ((soap->ssl_flags & SOAP_SSL_REQUIRE_SERVER_AUTHENTICATION))
    { const char *err = ssl_verify(soap, host);
      if (err)
      { soap->fclosesocket(soap, fd);
        soap->error = soap_set_sender_error(soap, "SSL/TLS error", err, SOAP_SSL_ERROR);
        return SOAP_INVALID_SOCKET;
      }
    }
#endif
#else
    soap->fclosesocket(soap, fd);
    soap->error = SOAP_SSL_ERROR;
    return SOAP_INVALID_SOCKET;
#endif
  }
  if (soap->recv_timeout || soap->send_timeout)
    SOAP_SOCKNONBLOCK(fd)
  else
    SOAP_SOCKBLOCK(fd)
  return fd;
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_NOIO
#ifndef PALM_1
static int
tcp_select(struct soap *soap, SOAP_SOCKET s, int flags, int timeout)
{ register int r;
  struct timeval tv;
  fd_set fd[3], *rfd, *sfd, *efd;
  soap->errnum = 0;
#ifndef WIN32
  /* if fd max set size exceeded, use poll() when available */
#if defined(__QNX__) || defined(QNX) /* select() is not MT safe on some QNX */
  if (1)
#else
  if ((int)s >= (int)FD_SETSIZE)
#endif
#ifdef HAVE_POLL
  { struct pollfd pollfd;
    int retries = 0;
    pollfd.fd = (int)s;
    pollfd.events = 0;
    if (flags & SOAP_TCP_SELECT_RCV)
      pollfd.events |= POLLIN;
    if (flags & SOAP_TCP_SELECT_SND)
      pollfd.events |= POLLOUT;
    if (flags & SOAP_TCP_SELECT_ERR)
      pollfd.events |= POLLERR;
    if (timeout < 0)
      timeout /= -1000; /* -usec -> ms */
    else if (timeout <= 1000000) /* avoid overflow */
      timeout *= 1000; /* sec -> ms */
    else
    { retries = timeout / 1000000;
      timeout = 1000000000;
    }
    do r = poll(&pollfd, 1, timeout);
    while (r == 0 && retries--);
    if (r > 0)
    { r = 0;
      if ((flags & SOAP_TCP_SELECT_RCV) && (pollfd.revents & POLLIN))
        r |= SOAP_TCP_SELECT_RCV;
      if ((flags & SOAP_TCP_SELECT_SND) && (pollfd.revents & POLLOUT))
        r |= SOAP_TCP_SELECT_SND;
      if ((flags & SOAP_TCP_SELECT_ERR) && (pollfd.revents & POLLERR))
        r |= SOAP_TCP_SELECT_ERR;
    }
    else if (r < 0)
      soap->errnum = soap_socket_errno(s);
    return r;
  }
#else
  { soap->error = SOAP_FD_EXCEEDED;
    return -1;
  }
#endif
#endif
  rfd = sfd = efd = NULL;
  if (flags & SOAP_TCP_SELECT_RCV)
  { rfd = &fd[0];
    FD_ZERO(rfd);
    FD_SET(s, rfd);
  }
  if (flags & SOAP_TCP_SELECT_SND)
  { sfd = &fd[1];
    FD_ZERO(sfd);
    FD_SET(s, sfd);
  }
  if (flags & SOAP_TCP_SELECT_ERR)
  { efd = &fd[2];
    FD_ZERO(efd);
    FD_SET(s, efd);
  }
  if (timeout >= 0)
  { tv.tv_sec = timeout;
    tv.tv_usec = 0;
  }
  else
  { tv.tv_sec = -timeout / 1000000;
    tv.tv_usec = -timeout % 1000000;
  }
  r = select((int)s + 1, rfd, sfd, efd, &tv);
  if (r > 0)
  { r = 0;
    if ((flags & SOAP_TCP_SELECT_RCV) && FD_ISSET(s, rfd))
      r |= SOAP_TCP_SELECT_RCV;
    if ((flags & SOAP_TCP_SELECT_SND) && FD_ISSET(s, sfd))
      r |= SOAP_TCP_SELECT_SND;
    if ((flags & SOAP_TCP_SELECT_ERR) && FD_ISSET(s, efd))
      r |= SOAP_TCP_SELECT_ERR;
  }
  else if (r < 0)
    soap->errnum = soap_socket_errno(s);
  return r;
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_NOIO
#ifndef PALM_1
static SOAP_SOCKET
tcp_accept(struct soap *soap, SOAP_SOCKET s, struct sockaddr *a, int *n)
{ SOAP_SOCKET fd;
  fd = accept(s, a, (SOAP_SOCKLEN_T*)n); /* portability note: see SOAP_SOCKLEN_T definition in stdsoap2.h */
#ifdef SOCKET_CLOSE_ON_EXEC
#ifdef WIN32
#ifndef UNDER_CE
  SetHandleInformation((HANDLE)fd, HANDLE_FLAG_INHERIT, 0);
#endif
#else
  fcntl(fd, F_SETFD, FD_CLOEXEC);
#endif
#endif
  return fd;
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_NOIO
#ifndef PALM_1
static int
tcp_disconnect(struct soap *soap)
{
#ifdef WITH_OPENSSL
  if (soap->ssl)
  { int r, s = 0;
    if (soap->session)
    { SSL_SESSION_free(soap->session);
      soap->session = NULL;
    }
    if (*soap->host)
    { soap->session = SSL_get1_session(soap->ssl);
      if (soap->session)
      { strcpy(soap->session_host, soap->host);
        soap->session_port = soap->port;
      }
    }
    r = SSL_shutdown(soap->ssl);
    /* SSL shutdown does not work when reads are pending */
    while (SSL_want_read(soap->ssl))
    { SSL_read(soap->ssl, NULL, 0);
      if (soap_socket_errno(soap->socket) != SOAP_EAGAIN)
      { r = SSL_shutdown(soap->ssl);
	break;
      }
    }
    if (r == 0)
    { if (soap_valid_socket(soap->socket))
      { if (!soap->fshutdownsocket(soap, soap->socket, SOAP_SHUT_WR))
        {
#ifndef WITH_LEAN
	  /*
          wait up to 10 seconds for close_notify to be sent by peer (if peer not
          present, this avoids calling SSL_shutdown() which has a lengthy return
          timeout)
          */
          r = tcp_select(soap, soap->socket, SOAP_TCP_SELECT_RCV | SOAP_TCP_SELECT_ERR, 10);
          if (r <= 0 && soap->errnum != SOAP_EINTR)
          { soap->errnum = 0;
            DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Connection lost...\n"));
            soap->fclosesocket(soap, soap->socket);
            soap->socket = SOAP_INVALID_SOCKET;
            ERR_remove_state(0);
            return SOAP_OK;
          }
#else
          r = SSL_shutdown(soap->ssl);
#endif
        }
      }
    }
    if (r != 1)
    { s = ERR_get_error();
      if (s)
      { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Shutdown failed: %d\n", SSL_get_error(soap->ssl, r)));
        if (soap_valid_socket(soap->socket) && !(soap->omode & SOAP_IO_UDP))
        { soap->fclosesocket(soap, soap->socket);
          soap->socket = SOAP_INVALID_SOCKET;
        }
      }
    }
    SSL_free(soap->ssl);
    soap->ssl = NULL;
    if (s)
      return SOAP_SSL_ERROR;
    ERR_remove_state(0);
  }
#endif
#ifdef WITH_GNUTLS
  if (soap->session)
  { gnutls_bye(soap->session, GNUTLS_SHUT_RDWR);
    gnutls_deinit(soap->session);
    soap->session = NULL;
  }
#endif
  if (soap_valid_socket(soap->socket) && !(soap->omode & SOAP_IO_UDP))
  { soap->fshutdownsocket(soap, soap->socket, SOAP_SHUT_RDWR);
    soap->fclosesocket(soap, soap->socket);
    soap->socket = SOAP_INVALID_SOCKET;
  }
  return SOAP_OK;
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_NOIO
#ifndef PALM_1
static int
tcp_closesocket(struct soap *soap, SOAP_SOCKET fd)
{ DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Close socket %d\n", (int)fd));
  return soap_closesocket(fd);
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_NOIO
#ifndef PALM_1
static int
tcp_shutdownsocket(struct soap *soap, SOAP_SOCKET fd, int how)
{ DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Shutdown socket %d how=%d\n", (int)fd, how));
  return shutdown(fd, how);
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_NOIO
#ifndef PALM_1
SOAP_FMAC1
SOAP_SOCKET
SOAP_FMAC2
soap_bind(struct soap *soap, const char *host, int port, int backlog)
{
#ifdef WITH_IPV6
  struct addrinfo *addrinfo = NULL;
  struct addrinfo hints;
  struct addrinfo res;
  int err;
#ifdef WITH_NO_IPV6_V6ONLY
  int unset = 0;
#endif
#endif
#ifndef WITH_LEAN
#ifndef WITH_WIN32
  int len = SOAP_BUFLEN;
#else
  int len = SOAP_BUFLEN + 1; /* speeds up windows xfer */
#endif
  int set = 1;
#endif
  if (soap_valid_socket(soap->master))
  { soap->fclosesocket(soap, soap->master);
    soap->master = SOAP_INVALID_SOCKET;
  }
  soap->socket = SOAP_INVALID_SOCKET;
  soap->errmode = 1;
  if (tcp_init(soap))
  { soap_set_receiver_error(soap, tcp_error(soap), "TCP init failed in soap_bind()", SOAP_TCP_ERROR);
    return SOAP_INVALID_SOCKET;
  }
#ifdef WITH_IPV6
  memset((void*)&hints, 0, sizeof(hints));
  hints.ai_family = PF_UNSPEC;
#ifndef WITH_LEAN
  if ((soap->omode & SOAP_IO_UDP))
    hints.ai_socktype = SOCK_DGRAM;
  else
#endif
    hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE;
  soap->errmode = 2;
  err = getaddrinfo(host, soap_int2s(soap, port), &hints, &addrinfo);
  if (err || !addrinfo)
  { soap_set_receiver_error(soap, SOAP_GAI_STRERROR(err), "getaddrinfo failed in soap_bind()", SOAP_TCP_ERROR);
    return SOAP_INVALID_SOCKET;
  }
  res = *addrinfo;
  memcpy(&soap->peer, addrinfo->ai_addr, addrinfo->ai_addrlen);
  soap->peerlen = addrinfo->ai_addrlen;
  res.ai_addr = (struct sockaddr*)&soap->peer;
  res.ai_addrlen = soap->peerlen;
  freeaddrinfo(addrinfo);
  soap->master = (int)socket(res.ai_family, res.ai_socktype, res.ai_protocol);
#else
#ifndef WITH_LEAN
  if ((soap->omode & SOAP_IO_UDP))
    soap->master = (int)socket(AF_INET, SOCK_DGRAM, 0);
  else
#endif
    soap->master = (int)socket(AF_INET, SOCK_STREAM, 0);
#endif
  soap->errmode = 0;
  if (!soap_valid_socket(soap->master))
  { soap->errnum = soap_socket_errno(soap->master);
    soap_set_receiver_error(soap, tcp_error(soap), "socket failed in soap_bind()", SOAP_TCP_ERROR);
    return SOAP_INVALID_SOCKET;
  }
#ifndef WITH_LEAN
  if ((soap->omode & SOAP_IO_UDP))
    soap->socket = soap->master;
#endif
#ifdef SOCKET_CLOSE_ON_EXEC
#ifdef WIN32
#ifndef UNDER_CE
  SetHandleInformation((HANDLE)soap->master, HANDLE_FLAG_INHERIT, 0);
#endif
#else
  fcntl(soap->master, F_SETFD, 1);
#endif
#endif
#ifndef WITH_LEAN
  if (soap->bind_flags && setsockopt(soap->master, SOL_SOCKET, soap->bind_flags, (char*)&set, sizeof(int)))
  { soap->errnum = soap_socket_errno(soap->master);
    soap_set_receiver_error(soap, tcp_error(soap), "setsockopt failed in soap_bind()", SOAP_TCP_ERROR);
    return SOAP_INVALID_SOCKET;
  }
  if (((soap->imode | soap->omode) & SOAP_IO_KEEPALIVE) && setsockopt(soap->master, SOL_SOCKET, SO_KEEPALIVE, (char*)&set, sizeof(int)))
  { soap->errnum = soap_socket_errno(soap->master);
    soap_set_receiver_error(soap, tcp_error(soap), "setsockopt SO_KEEPALIVE failed in soap_bind()", SOAP_TCP_ERROR);
    return SOAP_INVALID_SOCKET;
  }
  if (setsockopt(soap->master, SOL_SOCKET, SO_SNDBUF, (char*)&len, sizeof(int)))
  { soap->errnum = soap_socket_errno(soap->master);
    soap_set_receiver_error(soap, tcp_error(soap), "setsockopt SO_SNDBUF failed in soap_bind()", SOAP_TCP_ERROR);
    return SOAP_INVALID_SOCKET;
  }
  if (setsockopt(soap->master, SOL_SOCKET, SO_RCVBUF, (char*)&len, sizeof(int)))
  { soap->errnum = soap_socket_errno(soap->master);
    soap_set_receiver_error(soap, tcp_error(soap), "setsockopt SO_RCVBUF failed in soap_bind()", SOAP_TCP_ERROR);
    return SOAP_INVALID_SOCKET;
  }
#ifdef TCP_NODELAY
  if (!(soap->omode & SOAP_IO_UDP) && setsockopt(soap->master, IPPROTO_TCP, TCP_NODELAY, (char*)&set, sizeof(int)))
  { soap->errnum = soap_socket_errno(soap->master);
    soap_set_receiver_error(soap, tcp_error(soap), "setsockopt TCP_NODELAY failed in soap_bind()", SOAP_TCP_ERROR);
    return SOAP_INVALID_SOCKET;
  }
#endif
#endif
#ifdef WITH_IPV6
#ifdef WITH_IPV6_V6ONLY
  if (setsockopt(soap->master, IPPROTO_IPV6, IPV6_V6ONLY, (char*)&set, sizeof(int)))
  { soap->errnum = soap_socket_errno(soap->master);
    soap_set_receiver_error(soap, tcp_error(soap), "setsockopt IPV6_V6ONLY failed in soap_bind()", SOAP_TCP_ERROR);
    return SOAP_INVALID_SOCKET;
  }
#endif
#ifdef WITH_NO_IPV6_V6ONLY
  if (setsockopt(soap->master, IPPROTO_IPV6, IPV6_V6ONLY, (char*)&unset, sizeof(int)))
  { soap->errnum = soap_socket_errno(soap->master);
    soap_set_receiver_error(soap, tcp_error(soap), "setsockopt IPV6_V6ONLY failed in soap_bind()", SOAP_TCP_ERROR);
    return SOAP_INVALID_SOCKET;
  }
#endif
  soap->errmode = 0;
  if (bind(soap->master, res.ai_addr, (int)res.ai_addrlen))
  { soap->errnum = soap_socket_errno(soap->master);
    DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Could not bind to host\n"));
    soap_closesock(soap);
    soap_set_receiver_error(soap, tcp_error(soap), "bind failed in soap_bind()", SOAP_TCP_ERROR);
    return SOAP_INVALID_SOCKET;
  }  
#else
  soap->peerlen = sizeof(soap->peer);
  memset((void*)&soap->peer, 0, sizeof(soap->peer));
  soap->peer.sin_family = AF_INET;
  soap->errmode = 2;
  if (host)
  { if (soap->fresolve(soap, host, &soap->peer.sin_addr))
    { soap_set_receiver_error(soap, tcp_error(soap), "get host by name failed in soap_bind()", SOAP_TCP_ERROR);
      return SOAP_INVALID_SOCKET;
    }
  }
  else
    soap->peer.sin_addr.s_addr = htonl(INADDR_ANY);
  soap->peer.sin_port = htons((short)port);
  soap->errmode = 0;
  if (bind(soap->master, (struct sockaddr*)&soap->peer, (int)soap->peerlen))
  { soap->errnum = soap_socket_errno(soap->master);
    DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Could not bind to host\n"));
    soap_closesock(soap);
    soap_set_receiver_error(soap, tcp_error(soap), "bind failed in soap_bind()", SOAP_TCP_ERROR);
    return SOAP_INVALID_SOCKET;
  }
#endif
  if (!(soap->omode & SOAP_IO_UDP) && listen(soap->master, backlog))
  { soap->errnum = soap_socket_errno(soap->master);
    DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Could not bind to host\n"));
    soap_closesock(soap);
    soap_set_receiver_error(soap, tcp_error(soap), "listen failed in soap_bind()", SOAP_TCP_ERROR);
    return SOAP_INVALID_SOCKET;
  }  
  return soap->master;
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_NOIO
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_poll(struct soap *soap)
{ 
#ifndef WITH_LEAN
  register int r;
  if (soap_valid_socket(soap->socket))
  { r = tcp_select(soap, soap->socket, SOAP_TCP_SELECT_ALL, 0);
    if (r > 0 && (r & SOAP_TCP_SELECT_ERR))
      r = -1;
  }
  else if (soap_valid_socket(soap->master))
    r = tcp_select(soap, soap->master, SOAP_TCP_SELECT_SND, 0);
  else
    return SOAP_OK; /* OK when no socket! */
  if (r > 0)
  {
#ifdef WITH_OPENSSL
    if (soap->imode & SOAP_ENC_SSL)
    {
      if (soap_valid_socket(soap->socket)
       && (r & SOAP_TCP_SELECT_SND)
       && (!(r & SOAP_TCP_SELECT_RCV)
        || SSL_peek(soap->ssl, soap->tmpbuf, 1) > 0))
        return SOAP_OK;
    }
    else
#endif
      if (soap_valid_socket(soap->socket)
       && (r & SOAP_TCP_SELECT_SND)
       && (!(r & SOAP_TCP_SELECT_RCV)
        || recv(soap->socket, soap->tmpbuf, 1, MSG_PEEK) > 0))
        return SOAP_OK;
  }
  else if (r < 0)
  { if ((soap_valid_socket(soap->master) || soap_valid_socket(soap->socket)) && soap_socket_errno(soap->master) != SOAP_EINTR)
    { soap_set_receiver_error(soap, tcp_error(soap), "select failed in soap_poll()", SOAP_TCP_ERROR);
      return soap->error = SOAP_TCP_ERROR;
    }
  }
  DBGLOG(TEST,SOAP_MESSAGE(fdebug, "Polling: other end down on socket=%d select=%d\n", soap->socket, r));
  return SOAP_EOF;
#else
  return SOAP_OK;
#endif
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_NOIO
#ifndef PALM_1
SOAP_FMAC1
SOAP_SOCKET
SOAP_FMAC2
soap_accept(struct soap *soap)
{ int n = (int)sizeof(soap->peer);
#ifndef WITH_LEAN
#ifndef WITH_WIN32
  int len = SOAP_BUFLEN;
#else
  int len = SOAP_BUFLEN + 1; /* speeds up windows xfer */
#endif
  int set = 1;
#endif
  soap->error = SOAP_OK;
#ifndef WITH_LEAN
  if ((soap->omode & SOAP_IO_UDP))
    return soap->socket = soap->master;
#endif
  memset((void*)&soap->peer, 0, sizeof(soap->peer));
  soap->socket = SOAP_INVALID_SOCKET;
  soap->errmode = 0;
  soap->keep_alive = 0;
  if (soap_valid_socket(soap->master))
  { register int err;
    for (;;)
    { if (soap->accept_timeout || soap->send_timeout || soap->recv_timeout)
      { for (;;)
        { register int r;
          r = tcp_select(soap, soap->master, SOAP_TCP_SELECT_ALL, soap->accept_timeout ? soap->accept_timeout : 60);
          if (r > 0)
            break;
          if (!r && soap->accept_timeout)
          { soap_set_receiver_error(soap, "Timeout", "accept failed in soap_accept()", SOAP_TCP_ERROR);
            return SOAP_INVALID_SOCKET;
          }
	  if (r < 0)
          { r = soap->errnum;
            if (r != SOAP_EINTR)
            { soap_closesock(soap);
              soap_set_sender_error(soap, tcp_error(soap), "accept failed in soap_accept()", SOAP_TCP_ERROR);
              return SOAP_INVALID_SOCKET;
            }
	  }
        }
      }
      if (soap->accept_timeout)
        SOAP_SOCKNONBLOCK(soap->master)
      else
        SOAP_SOCKBLOCK(soap->master)
      soap->socket = soap->faccept(soap, soap->master, (struct sockaddr*)&soap->peer, &n);
      soap->peerlen = (size_t)n;
      if (soap_valid_socket(soap->socket))
      {
#ifdef WITH_IPV6
/* Use soap->host to store the numeric form of the remote host */
        getnameinfo((struct sockaddr*)&soap->peer, n, soap->host, sizeof(soap->host), NULL, 0, NI_NUMERICHOST | NI_NUMERICSERV); 
        DBGLOG(TEST,SOAP_MESSAGE(fdebug, "Accept socket %d from %s\n", soap->socket, soap->host));
        soap->ip = 0; /* info stored in soap->peer and soap->host */
        soap->port = 0; /* info stored in soap->peer and soap->host */
#else
        soap->ip = ntohl(soap->peer.sin_addr.s_addr);
        soap->port = (int)ntohs(soap->peer.sin_port); /* does not return port number on some systems */
        DBGLOG(TEST,SOAP_MESSAGE(fdebug, "Accept socket %d at port %d from IP %d.%d.%d.%d\n", soap->socket, soap->port, (int)(soap->ip>>24)&0xFF, (int)(soap->ip>>16)&0xFF, (int)(soap->ip>>8)&0xFF, (int)soap->ip&0xFF));
#endif
#ifndef WITH_LEAN
        if (soap->accept_flags == SO_LINGER)
        { struct linger linger;
          memset((void*)&linger, 0, sizeof(linger));
          linger.l_onoff = 1;
          linger.l_linger = soap->linger_time;
          if (setsockopt(soap->socket, SOL_SOCKET, SO_LINGER, (char*)&linger, sizeof(struct linger)))
          { soap->errnum = soap_socket_errno(soap->socket);
            soap_set_receiver_error(soap, tcp_error(soap), "setsockopt SO_LINGER failed in soap_accept()", SOAP_TCP_ERROR);
            soap_closesock(soap);
            return SOAP_INVALID_SOCKET;
          }
        }
        else if (soap->accept_flags && setsockopt(soap->socket, SOL_SOCKET, soap->accept_flags, (char*)&set, sizeof(int)))
        { soap->errnum = soap_socket_errno(soap->socket);
          soap_set_receiver_error(soap, tcp_error(soap), "setsockopt failed in soap_accept()", SOAP_TCP_ERROR);
          soap_closesock(soap);
          return SOAP_INVALID_SOCKET;
        }
        if (((soap->imode | soap->omode) & SOAP_IO_KEEPALIVE) && setsockopt(soap->socket, SOL_SOCKET, SO_KEEPALIVE, (char*)&set, sizeof(int)))
        { soap->errnum = soap_socket_errno(soap->socket);
          soap_set_receiver_error(soap, tcp_error(soap), "setsockopt SO_KEEPALIVE failed in soap_accept()", SOAP_TCP_ERROR);
          soap_closesock(soap);
          return SOAP_INVALID_SOCKET;
        }
        if (setsockopt(soap->socket, SOL_SOCKET, SO_SNDBUF, (char*)&len, sizeof(int)))
        { soap->errnum = soap_socket_errno(soap->socket);
          soap_set_receiver_error(soap, tcp_error(soap), "setsockopt SO_SNDBUF failed in soap_accept()", SOAP_TCP_ERROR);
          soap_closesock(soap);
          return SOAP_INVALID_SOCKET;
        }
        if (setsockopt(soap->socket, SOL_SOCKET, SO_RCVBUF, (char*)&len, sizeof(int)))
        { soap->errnum = soap_socket_errno(soap->socket);
          soap_set_receiver_error(soap, tcp_error(soap), "setsockopt SO_RCVBUF failed in soap_accept()", SOAP_TCP_ERROR);
          soap_closesock(soap);
          return SOAP_INVALID_SOCKET;
        }
#ifdef TCP_NODELAY
        if (!(soap->omode & SOAP_IO_UDP) && setsockopt(soap->socket, IPPROTO_TCP, TCP_NODELAY, (char*)&set, sizeof(int)))
        { soap->errnum = soap_socket_errno(soap->socket);
          soap_set_receiver_error(soap, tcp_error(soap), "setsockopt TCP_NODELAY failed in soap_accept()", SOAP_TCP_ERROR);
          soap_closesock(soap);
          return SOAP_INVALID_SOCKET;
        }
#endif
#endif
        soap->keep_alive = (((soap->imode | soap->omode) & SOAP_IO_KEEPALIVE) != 0);
        if (soap->send_timeout || soap->recv_timeout)
          SOAP_SOCKNONBLOCK(soap->socket)
        else
          SOAP_SOCKBLOCK(soap->socket)
        return soap->socket;
      }
      err = soap_socket_errno(soap->socket);
      if (err != 0 && err != SOAP_EINTR && err != SOAP_EAGAIN && err != SOAP_EWOULDBLOCK)
      { DBGLOG(TEST,SOAP_MESSAGE(fdebug, "Accept failed from %s\n", soap->host));
        soap->errnum = err;
        soap_set_receiver_error(soap, tcp_error(soap), "accept failed in soap_accept()", SOAP_TCP_ERROR);
        soap_closesock(soap);
        return SOAP_INVALID_SOCKET;
      }
    }
  }
  else
  { soap->errnum = 0;
    soap_set_receiver_error(soap, tcp_error(soap), "no master socket in soap_accept()", SOAP_TCP_ERROR);
    return SOAP_INVALID_SOCKET;
  }
}
#endif
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_closesock(struct soap *soap)
{ register int status = soap->error;
#ifndef WITH_LEANER
  if (status) /* close on error: attachment state is not to be trusted */
  { soap->mime.first = NULL;
    soap->mime.last = NULL;
    soap->dime.first = NULL;
    soap->dime.last = NULL;
  }
#endif
  if (soap->fdisconnect && (soap->error = soap->fdisconnect(soap)))
    return soap->error;
  if (status == SOAP_EOF || status == SOAP_TCP_ERROR || status == SOAP_SSL_ERROR || !soap->keep_alive)
  { if (soap->fclose && (soap->error = soap->fclose(soap)))
      return soap->error;
    soap->keep_alive = 0;
  }
#ifdef WITH_ZLIB
  if (soap->zlib_state == SOAP_ZLIB_DEFLATE)
    deflateEnd(soap->d_stream);
  else if (soap->zlib_state == SOAP_ZLIB_INFLATE)
    inflateEnd(soap->d_stream);
  soap->zlib_state = SOAP_ZLIB_NONE;
#endif
  return soap->error = status;
}
#endif

/******************************************************************************/
#ifndef WITH_NOIO
#ifndef PALM_2
SOAP_FMAC1
void
SOAP_FMAC2
soap_cleanup(struct soap *soap)
{ soap_done(soap);
#ifdef WIN32
  if (!tcp_done)
    return;
  tcp_done = 0;
  WSACleanup();
#endif
}
#endif
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
void
SOAP_FMAC2
soap_done(struct soap *soap)
{ 
#ifdef SOAP_DEBUG
  int i;
#endif
  if (soap_check_state(soap))
    return;
  DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Done with context\n"));
  soap_free_temp(soap);
  while (soap->clist)
  { struct soap_clist *p = soap->clist->next;
    SOAP_FREE(soap, soap->clist);
    soap->clist = p;
  }
  if (soap->state == SOAP_INIT)
    soap->omode &= ~SOAP_IO_UDP; /* to force close the socket */
  soap->keep_alive = 0; /* to force close the socket */
  soap_closesock(soap);
#ifdef WITH_COOKIES
  soap_free_cookies(soap);
#endif
  while (soap->plugins)
  { register struct soap_plugin *p = soap->plugins->next;
    DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Removing plugin '%s'\n", soap->plugins->id));
    if (soap->plugins->fcopy || soap->state == SOAP_INIT)
      soap->plugins->fdelete(soap, soap->plugins);
    SOAP_FREE(soap, soap->plugins);
    soap->plugins = p;
  }
  soap->fplugin = fplugin;
  soap->fmalloc = NULL;
#ifndef WITH_NOHTTP
  soap->fpost = http_post;
  soap->fput = http_put;
  soap->fget = http_get;
  soap->fdel = http_405;
  soap->fopt = http_405;
  soap->fhead = http_405;
  soap->fform = NULL;
  soap->fposthdr = http_post_header;
  soap->fresponse = http_response;
  soap->fparse = http_parse;
  soap->fparsehdr = http_parse_header;
#endif
  soap->fheader = NULL;
#ifndef WITH_NOIO
#ifndef WITH_IPV6
  soap->fresolve = tcp_gethost;
#else
  soap->fresolve = NULL;
#endif
  soap->faccept = tcp_accept;
  soap->fopen = tcp_connect;
  soap->fclose = tcp_disconnect;
  soap->fclosesocket = tcp_closesocket;
  soap->fshutdownsocket = tcp_shutdownsocket;
  soap->fsend = fsend;
  soap->frecv = frecv;
  soap->fpoll = soap_poll;
#else
  soap->fopen = NULL;
  soap->fclose = NULL;
  soap->fpoll = NULL;
#endif
#ifndef WITH_LEANER
  soap->fprepareinitsend = NULL;
  soap->fprepareinitrecv = NULL;
  soap->fpreparesend = NULL;
  soap->fpreparerecv = NULL;
  soap->fpreparefinalsend = NULL;
  soap->fpreparefinalrecv = NULL;
#endif
  soap->fseterror = NULL;
  soap->fignore = NULL;
  soap->fserveloop = NULL;
#ifdef WITH_OPENSSL
  if (soap->session)
  { SSL_SESSION_free(soap->session);
    soap->session = NULL;
  }
#endif
  if (soap->state == SOAP_INIT)
  { if (soap_valid_socket(soap->master))
    { soap->fclosesocket(soap, soap->master);
      soap->master = SOAP_INVALID_SOCKET;
    }
  }
#ifdef WITH_OPENSSL
  if (soap->ssl)
  { SSL_free(soap->ssl);
    soap->ssl = NULL;
  }
  if (soap->state == SOAP_INIT)
  { if (soap->ctx)
    { SSL_CTX_free(soap->ctx);
      soap->ctx = NULL;
    }
  }
  ERR_remove_state(0);
#endif
#ifdef WITH_GNUTLS
  if (soap->state == SOAP_INIT)
  { if (soap->xcred)
    { gnutls_certificate_free_credentials(soap->xcred);
      soap->xcred = NULL;
    }
    if (soap->acred)
    { gnutls_anon_free_client_credentials(soap->acred);
      soap->acred = NULL;
    }
    if (soap->cache)
    { gnutls_priority_deinit(soap->cache);
      soap->cache = NULL;
    }
    if (soap->dh_params)
    { gnutls_dh_params_deinit(soap->dh_params);
      soap->dh_params = NULL;
    }
    if (soap->rsa_params)
    { gnutls_rsa_params_deinit(soap->rsa_params);
      soap->rsa_params = NULL;
    }
  }
  if (soap->session)
  { gnutls_deinit(soap->session);
    soap->session = NULL;
  }
#endif
#ifdef WITH_C_LOCALE
  freelocale(soap->c_locale);
#endif
#ifdef WITH_ZLIB
  if (soap->d_stream)
  { SOAP_FREE(soap, (void*)soap->d_stream);
    soap->d_stream = NULL;
  }
  if (soap->z_buf)
  { SOAP_FREE(soap, (void*)soap->z_buf);
    soap->z_buf = NULL;
  }
#endif
#ifdef SOAP_DEBUG
  DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Free logfiles\n"));
  for (i = 0; i < SOAP_MAXLOGS; i++)
  { if (soap->logfile[i])
    { SOAP_FREE(soap, (void*)soap->logfile[i]);
      soap->logfile[i] = NULL;
    }
    soap_close_logfile(soap, i);
  }
  soap->state = SOAP_NONE;
#endif
#ifdef SOAP_MEM_DEBUG
  soap_free_mht(soap);
#endif
}
#endif

/******************************************************************************\
 *
 *	HTTP
 *
\******************************************************************************/

/******************************************************************************/
#ifndef WITH_NOHTTP
#ifndef PALM_1
int
http_parse(struct soap *soap)
{ char header[SOAP_HDRLEN], *s;
  unsigned short httpcmd = 0, status = 0;
  DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Waiting for HTTP request/response...\n"));
  *soap->endpoint = '\0';
  soap->length = 0;
  soap->userid = NULL;
  soap->passwd = NULL;
  soap->action = NULL;
  soap->authrealm = NULL;
  soap->proxy_from = NULL;
  soap->http_content = NULL;
  soap->status = 0;
  do
  { if (soap_getline(soap, soap->msgbuf, sizeof(soap->msgbuf)))
    { if (soap->error == SOAP_EOF)
        return SOAP_EOF;
      return soap->error = 414;
    }
    if ((s = strchr(soap->msgbuf, ' ')))
    { soap->status = (unsigned short)soap_strtoul(s, &s, 10);
      if (!soap_blank((soap_wchar)*s))
        soap->status = 0;
    }
    else
      soap->status = 0;
    DBGLOG(TEST,SOAP_MESSAGE(fdebug, "HTTP status: %s\n", soap->msgbuf));
    for (;;)
    { if (soap_getline(soap, header, SOAP_HDRLEN))
      { if (soap->error == SOAP_EOF)
        { soap->error = SOAP_OK;
          DBGLOG(TEST,SOAP_MESSAGE(fdebug, "EOF in HTTP header, continue anyway\n"));
          break;
        }
        return soap->error;
      }
      if (!*header)
        break;
      DBGLOG(TEST,SOAP_MESSAGE(fdebug, "HTTP header: %s\n", header));
      s = strchr(header, ':');
      if (s)
      { char *t;
        *s = '\0';
        do s++;
        while (*s && *s <= 32);
        if (*s == '"')
          s++;
        t = s + strlen(s) - 1;
        while (t > s && *t <= 32)
          t--;
        if (t >= s && *t == '"')
          t--;
        t[1] = '\0';
        if ((soap->error = soap->fparsehdr(soap, header, s)))
        { if (soap->error < SOAP_STOP)
            return soap->error;
          status = soap->error;
          soap->error = SOAP_OK;
        }
      }
    }
  } while (soap->status == 100);
  DBGLOG(TEST,SOAP_MESSAGE(fdebug, "Finished HTTP header parsing, status = %d\n", soap->status));
  s = strstr(soap->msgbuf, "HTTP/");
  if (s && s[7] != '1')
  { if (soap->keep_alive == 1)
      soap->keep_alive = 0;
    if (soap->status == 0 && (soap->omode & SOAP_IO) == SOAP_IO_CHUNK) /* soap->status == 0 for HTTP request */
    { soap->imode |= SOAP_IO_CHUNK;
      soap->omode = (soap->omode & ~SOAP_IO) | SOAP_IO_STORE;
    }
  }
  if (soap->keep_alive < 0)
    soap->keep_alive = 1;
  DBGLOG(TEST,SOAP_MESSAGE(fdebug, "Keep alive connection = %d\n", soap->keep_alive));
  if (soap->status == 0)
  { size_t l = 0;
    if (s)
    { if (!strncmp(soap->msgbuf, "POST ", l = 5))
        httpcmd = 1;
      else if (!strncmp(soap->msgbuf, "PUT ", l = 4))
        httpcmd = 2;
      else if (!strncmp(soap->msgbuf, "GET ", l = 4))
        httpcmd = 3;
      else if (!strncmp(soap->msgbuf, "DELETE ", l = 7))
        httpcmd = 4;
      else if (!strncmp(soap->msgbuf, "OPTIONS ", l = 8))
        httpcmd = 5;
      else if (!strncmp(soap->msgbuf, "HEAD ", l = 5))
        httpcmd = 6;
    }
    if (s && httpcmd) 
    { size_t m = strlen(soap->endpoint);
      size_t n = m + (s - soap->msgbuf) - l - 1;
      if (m > n)
        m = n;
      if (n >= sizeof(soap->endpoint))
        n = sizeof(soap->endpoint) - 1;
      strncpy(soap->path, soap->msgbuf + l, n - m);
      soap->path[n - m] = '\0';
      strcat(soap->endpoint, soap->path);
      DBGLOG(TEST,SOAP_MESSAGE(fdebug, "Target endpoint='%s'\n", soap->endpoint));
      if (httpcmd > 1)
      { DBGLOG(TEST,SOAP_MESSAGE(fdebug, "HTTP %s handler\n", soap->msgbuf));
        switch (httpcmd)
        { case  2: soap->error = soap->fput(soap); break;
          case  3: soap->error = soap->fget(soap); break;
          case  4: soap->error = soap->fdel(soap); break;
          case  5: soap->error = soap->fopt(soap); break;
          case  6: soap->error = soap->fhead(soap); break;
	  default: soap->error = 405; break;
	}
        DBGLOG(TEST,SOAP_MESSAGE(fdebug, "HTTP handler return = %d\n", soap->error));
        if (soap->error == SOAP_OK)
          soap->error = SOAP_STOP; /* prevents further processing */
        return soap->error;
      }
      if (status)
        return soap->error = status;
    }
    else if (status)
      return soap->error = status;
    else if (s)
      return soap->error = 405;
  }
  /* Status OK (HTTP 200) */
  if (soap->status == 0 || soap->status == 200)
    return SOAP_OK;
  /* Status 201 (Created), 202 (Accepted), ... and HTTP 400 and 500 errors
     may not have a body. When content length, content type, or chunking is
     used assume there is a message to parse, either XML or HTTP.
  */
  if (soap->length > 0 || (soap->http_content && soap->recv_timeout) || (soap->imode & SOAP_IO) == SOAP_IO_CHUNK)
  { if (((soap->status > 200 && soap->status <= 299) || soap->status == 400 || soap->status == 500))
      return SOAP_OK;
    /* force close afterwards in soap_closesock() */
    soap->keep_alive = 0;
#ifndef WITH_LEAN
    /* read HTTP body for error details */
    s = soap_get_http_body(soap);
    if (s)
      return soap_set_receiver_error(soap, soap->msgbuf, s, soap->status);
#endif
  }
  DBGLOG(TEST,SOAP_MESSAGE(fdebug, "HTTP error %d\n", soap->status));
  return soap_set_receiver_error(soap, "HTTP Error", soap->msgbuf, soap->status);
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_NOHTTP
#ifndef PALM_1
static int
http_parse_header(struct soap *soap, const char *key, const char *val)
{ if (!soap_tag_cmp(key, "Host"))
  { 
#if defined(WITH_OPENSSL) || defined(WITH_GNUTLS)
    if (soap->imode & SOAP_ENC_SSL)
      strcpy(soap->endpoint, "https://");
    else
#endif
      strcpy(soap->endpoint, "http://");
    strncat(soap->endpoint, val, sizeof(soap->endpoint) - 8);
    soap->endpoint[sizeof(soap->endpoint) - 1] = '\0';
  }
#ifndef WITH_LEANER
  else if (!soap_tag_cmp(key, "Content-Type"))
  { const char *action;
    soap->http_content = soap_strdup(soap, val);
    if (soap_get_header_attribute(soap, val, "application/dime"))
      soap->imode |= SOAP_ENC_DIME;
    else if (soap_get_header_attribute(soap, val, "multipart/related")
          || soap_get_header_attribute(soap, val, "multipart/form-data"))
    { soap->mime.boundary = soap_strdup(soap, soap_get_header_attribute(soap, val, "boundary"));
      soap->mime.start = soap_strdup(soap, soap_get_header_attribute(soap, val, "start"));
      soap->imode |= SOAP_ENC_MIME;
    }
    action = soap_get_header_attribute(soap, val, "action");
    if (action)
    { if (*action == '"')
      { soap->action = soap_strdup(soap, action + 1);
        soap->action[strlen(soap->action) - 1] = '\0';
      }
      else
        soap->action = soap_strdup(soap, action);
    }
  }
#endif
  else if (!soap_tag_cmp(key, "Content-Length"))
  { soap->length = soap_strtoul(val, NULL, 10);
  }
  else if (!soap_tag_cmp(key, "Content-Encoding"))
  { if (!soap_tag_cmp(val, "deflate"))
#ifdef WITH_ZLIB
      soap->zlib_in = SOAP_ZLIB_DEFLATE;
#else
      return SOAP_ZLIB_ERROR;
#endif
    else if (!soap_tag_cmp(val, "gzip"))
#ifdef WITH_GZIP
      soap->zlib_in = SOAP_ZLIB_GZIP;
#else
      return SOAP_ZLIB_ERROR;
#endif
  }
#ifdef WITH_ZLIB
  else if (!soap_tag_cmp(key, "Accept-Encoding"))
  {
#ifdef WITH_GZIP
    if (strchr(val, '*') || soap_get_header_attribute(soap, val, "gzip"))
      soap->zlib_out = SOAP_ZLIB_GZIP;
    else
#endif
    if (strchr(val, '*') || soap_get_header_attribute(soap, val, "deflate"))
      soap->zlib_out = SOAP_ZLIB_DEFLATE;
    else
      soap->zlib_out = SOAP_ZLIB_NONE;
  }
#endif
  else if (!soap_tag_cmp(key, "Transfer-Encoding"))
  { soap->imode &= ~SOAP_IO;
    if (!soap_tag_cmp(val, "chunked"))
      soap->imode |= SOAP_IO_CHUNK;
  }
  else if (!soap_tag_cmp(key, "Connection"))
  { if (!soap_tag_cmp(val, "keep-alive"))
      soap->keep_alive = -soap->keep_alive;
    else if (!soap_tag_cmp(val, "close"))
      soap->keep_alive = 0;
  }
#ifndef WITH_LEAN
  else if (!soap_tag_cmp(key, "Authorization"))
  { if (!soap_tag_cmp(val, "Basic *"))
    { int n;
      char *s;
      soap_base642s(soap, val + 6, soap->tmpbuf, sizeof(soap->tmpbuf) - 1, &n);
      soap->tmpbuf[n] = '\0';
      if ((s = strchr(soap->tmpbuf, ':')))
      { *s = '\0';
        soap->userid = soap_strdup(soap, soap->tmpbuf);
        soap->passwd = soap_strdup(soap, s + 1);
      }
    }
  }
  else if (!soap_tag_cmp(key, "WWW-Authenticate"))
  { soap->authrealm = soap_strdup(soap, soap_get_header_attribute(soap, val + 6, "realm"));
  }
  else if (!soap_tag_cmp(key, "Expect"))
  { if (!soap_tag_cmp(val, "100-continue"))
    { if ((soap->error = soap->fposthdr(soap, "HTTP/1.1 100 Continue", NULL))
       || (soap->error = soap->fposthdr(soap, NULL, NULL)))
        return soap->error;
    }
  }
#endif
  else if (!soap_tag_cmp(key, "SOAPAction"))
  { if (*val == '"')
    { soap->action = soap_strdup(soap, val + 1);
      soap->action[strlen(soap->action) - 1] = '\0';
    }
    else
      soap->action = soap_strdup(soap, val);
  }
  else if (!soap_tag_cmp(key, "Location"))
  { strncpy(soap->endpoint, val, sizeof(soap->endpoint));
    soap->endpoint[sizeof(soap->endpoint) - 1] = '\0';
  }
  else if (!soap_tag_cmp(key, "X-Forwarded-For"))
  { soap->proxy_from = soap_strdup(soap, val);
  }
#ifdef WITH_COOKIES
  else if (!soap_tag_cmp(key, "Cookie")
   || !soap_tag_cmp(key, "Cookie2")
   || !soap_tag_cmp(key, "Set-Cookie")
   || !soap_tag_cmp(key, "Set-Cookie2"))
  { soap_getcookies(soap, val);
  }
#endif
  return SOAP_OK;
}
#endif
#endif

/******************************************************************************/
#if !defined(WITH_NOHTTP) || !defined(WITH_LEANER)
#ifndef PALM_1
SOAP_FMAC1
const char*
SOAP_FMAC2
soap_get_header_attribute(struct soap *soap, const char *line, const char *key)
{ register const char *s = line;
  if (s)
  { while (*s)
    { register short flag;
      s = soap_decode_key(soap->tmpbuf, sizeof(soap->tmpbuf), s);
      flag = soap_tag_cmp(soap->tmpbuf, key);
      s = soap_decode_val(soap->tmpbuf, sizeof(soap->tmpbuf), s);
      if (!flag)
        return soap->tmpbuf;
    }
  }
  return NULL;
}
#endif
#endif

/******************************************************************************/
#if !defined(WITH_NOHTTP) || !defined(WITH_LEANER)
#ifndef PALM_1
SOAP_FMAC1
const char*
SOAP_FMAC2
soap_decode_key(char *buf, size_t len, const char *val)
{ return soap_decode(buf, len, val, "=,;");
}
#endif
#endif

/******************************************************************************/
#if !defined(WITH_NOHTTP) || !defined(WITH_LEANER)
#ifndef PALM_1
SOAP_FMAC1
const char*
SOAP_FMAC2
soap_decode_val(char *buf, size_t len, const char *val)
{ if (*val != '=')
  { *buf = '\0';
    return val;
  }
  return soap_decode(buf, len, val + 1, ",;");
}
#endif
#endif

/******************************************************************************/
#if !defined(WITH_NOHTTP) || !defined(WITH_LEANER)
#ifndef PALM_1
static const char*
soap_decode(char *buf, size_t len, const char *val, const char *sep)
{ const char *s;
  char *t = buf;
  for (s = val; *s; s++)
    if (*s != ' ' && *s != '\t' && !strchr(sep, *s))
      break;
  if (*s == '"')
  { s++;
    while (*s && *s != '"' && --len)
      *t++ = *s++;
  }
  else
  { while (*s && !soap_blank((soap_wchar)*s) && !strchr(sep, *s) && --len)
    { if (*s == '%')
      { *t++ = ((s[1] >= 'A' ? (s[1] & 0x7) + 9 : s[1] - '0') << 4)
              + (s[2] >= 'A' ? (s[2] & 0x7) + 9 : s[2] - '0');
        s += 3;
      }
      else
        *t++ = *s++;
    }
  }
  *t = '\0';
  while (*s && !strchr(sep, *s))
    s++;
  return s;
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_NOHTTP
#ifndef PALM_1
static const char*
http_error(struct soap *soap, int status)
{ register const char *msg = SOAP_STR_EOS;
#ifndef WITH_LEAN
  msg = soap_code_str(h_http_error_codes, status);
  if (!msg)
    msg = SOAP_STR_EOS;
#endif
  return msg;
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_NOHTTP
#ifndef PALM_1
static int
http_put(struct soap *soap)
{ return http_parse(soap);
}
#endif
#endif
/******************************************************************************/

#ifndef WITH_NOHTTP
#ifndef PALM_1
static int
http_get(struct soap *soap)
{ return SOAP_GET_METHOD;
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_NOHTTP
#ifndef PALM_1
static int
http_405(struct soap *soap)
{ return 405;
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_NOHTTP
#ifndef PALM_1
static int
http_post(struct soap *soap, const char *endpoint, const char *host, int port, const char *path, const char *action, size_t count)
{ register const char *s;
  register int err;
  if (soap->status == SOAP_GET)
    s = "GET";
  else
    s = "POST";
#ifdef PALM
  if (!endpoint || (soap_tag_cmp(endpoint, "http:*") && soap_tag_cmp(endpoint, "https:*") && strncmp(endpoint, "httpg:", 6)) && strncmp(endpoint, "_beam:", 6) && strncmp(endpoint, "_local:", 7) && strncmp(endpoint, "_btobex:", 8))
#else
  if (!endpoint || (soap_tag_cmp(endpoint, "http:*") && soap_tag_cmp(endpoint, "https:*") && strncmp(endpoint, "httpg:", 6)))
#endif
    return SOAP_OK;
  if (strlen(endpoint) + strlen(soap->http_version) > sizeof(soap->tmpbuf) - 80)
    return soap->error = SOAP_EOM;
  if (soap->proxy_host && soap_tag_cmp(endpoint, "https:*"))
    sprintf(soap->tmpbuf, "%s %s HTTP/%s", s, endpoint, soap->http_version);
  else
    sprintf(soap->tmpbuf, "%s /%s HTTP/%s", s, (*path == '/' ? path + 1 : path), soap->http_version);
  if ((err = soap->fposthdr(soap, soap->tmpbuf, NULL)))
    return err;
#ifdef WITH_OPENSSL
  if ((soap->ssl && soap->port != 443) || (!soap->ssl && soap->port != 80))
    sprintf(soap->tmpbuf, "%s:%d", host, port);
  else
    strcpy(soap->tmpbuf, host); 
#else
  if (port != 80)
    sprintf(soap->tmpbuf, "%s:%d", host, port);
  else
    strcpy(soap->tmpbuf, host); 
#endif
  if ((err = soap->fposthdr(soap, "Host", soap->tmpbuf))
   || (err = soap->fposthdr(soap, "User-Agent", "gSOAP/2.7"))
   || (err = soap_puthttphdr(soap, SOAP_OK, count)))
    return err;
#ifdef WITH_ZLIB
#ifdef WITH_GZIP
  if ((err = soap->fposthdr(soap, "Accept-Encoding", "gzip, deflate")))
#else
  if ((err = soap->fposthdr(soap, "Accept-Encoding", "deflate")))
#endif
    return err;
#endif
#ifndef WITH_LEAN
  if (soap->userid && soap->passwd && strlen(soap->userid) + strlen(soap->passwd) < 761)
  { sprintf(soap->tmpbuf + 262, "%s:%s", soap->userid, soap->passwd);
    strcpy(soap->tmpbuf, "Basic ");
    soap_s2base64(soap, (const unsigned char*)(soap->tmpbuf + 262), soap->tmpbuf + 6, (int)strlen(soap->tmpbuf + 262));
    if ((err = soap->fposthdr(soap, "Authorization", soap->tmpbuf)))
      return err;
  }
  if (soap->proxy_userid && soap->proxy_passwd && strlen(soap->proxy_userid) + strlen(soap->proxy_passwd) < 761)
  { sprintf(soap->tmpbuf + 262, "%s:%s", soap->proxy_userid, soap->proxy_passwd);
    strcpy(soap->tmpbuf, "Basic ");
    soap_s2base64(soap, (const unsigned char*)(soap->tmpbuf + 262), soap->tmpbuf + 6, (int)strlen(soap->tmpbuf + 262));
    if ((err = soap->fposthdr(soap, "Proxy-Authorization", soap->tmpbuf)))
      return err;
  }
#endif
#ifdef WITH_COOKIES
#ifdef WITH_OPENSSL
  if (soap_putcookies(soap, host, path, soap->ssl != NULL))
    return soap->error;
#else
  if (soap_putcookies(soap, host, path, 0))
    return soap->error;
#endif
#endif
  if (soap->status != SOAP_GET && (soap->version == 1 || (action && *action)))
  { sprintf(soap->tmpbuf, "\"%s\"", action && strlen(action) < sizeof(soap->tmpbuf) - 3 ? action : SOAP_STR_EOS);
    if ((err = soap->fposthdr(soap, "SOAPAction", soap->tmpbuf)))
      return err;
  }
  return soap->fposthdr(soap, NULL, NULL);
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_NOHTTP
#ifndef PALM_1
static int
http_send_header(struct soap *soap, const char *s)
{ register const char *t;
  do
  { t = strchr(s, '\n'); /* disallow \n in HTTP headers */
    if (!t)
      t = s + strlen(s);
    if (soap_send_raw(soap, s, t - s))
      return soap->error;
    s = t + 1;
  } while (*t);
  return SOAP_OK;
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_NOHTTP
#ifndef PALM_1
static int
http_post_header(struct soap *soap, const char *key, const char *val)
{ if (key)
  { if (http_send_header(soap, key))
      return soap->error;
    if (val && (soap_send_raw(soap, ": ", 2) || http_send_header(soap, val)))
      return soap->error;
  }
  return soap_send_raw(soap, "\r\n", 2);
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_NOHTTP
#ifndef PALM_1
static int
http_response(struct soap *soap, int status, size_t count)
{ register int err;
#ifdef WMW_RPM_IO
  if (soap->rpmreqid)
    httpOutputEnable(soap->rpmreqid);
#endif
  if (strlen(soap->http_version) > 4)
    return soap->error = SOAP_EOM;
  if (!status || status == SOAP_HTML || status == SOAP_FILE)
  { const char *s;
    if (count || ((soap->omode & SOAP_IO) == SOAP_IO_CHUNK))
      s = "200 OK";
    else
      s = "202 ACCEPTED";
    DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Status = %s\n", s));
#ifdef WMW_RPM_IO
    if (soap->rpmreqid || soap_valid_socket(soap->master) || soap_valid_socket(soap->socket)) /* RPM behaves as if standalone */
#else
    if (soap_valid_socket(soap->master) || soap_valid_socket(soap->socket)) /* standalone application (socket) or CGI (stdin/out)? */
#endif
    { sprintf(soap->tmpbuf, "HTTP/%s %s", soap->http_version, s);
      if ((err = soap->fposthdr(soap, soap->tmpbuf, NULL)))
        return err;
    }
    else if ((err = soap->fposthdr(soap, "Status", s))) /* CGI header */
      return err;
  }
  else if (status >= 200 && status < 600)
  { sprintf(soap->tmpbuf, "HTTP/%s %d %s", soap->http_version, status, http_error(soap, status));
    if ((err = soap->fposthdr(soap, soap->tmpbuf, NULL)))
      return err;
#ifndef WITH_LEAN 
    if (status == 401)
    { sprintf(soap->tmpbuf, "Basic realm=\"%s\"", (soap->authrealm && strlen(soap->authrealm) < sizeof(soap->tmpbuf) - 14) ? soap->authrealm : "gSOAP Web Service");
      if ((err = soap->fposthdr(soap, "WWW-Authenticate", soap->tmpbuf)))
        return err;
    }
    else if ((status >= 301 && status <= 303) || status == 307)
    { if ((err = soap->fposthdr(soap, "Location", soap->endpoint)))
        return err;
    }
#endif
  }
  else
  { const char *s = *soap_faultcode(soap);
    if (status >= SOAP_GET_METHOD && status <= SOAP_HTTP_METHOD)
      s = "405 Method Not Allowed";
    else if (soap->version == 2 && (!s || !strcmp(s, "SOAP-ENV:Sender")))
      s = "400 Bad Request";
    else
      s = "500 Internal Server Error";
    DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Error %s (status=%d)\n", s, status));
#ifdef WMW_RPM_IO
    if (soap->rpmreqid || soap_valid_socket(soap->master) || soap_valid_socket(soap->socket)) /* RPM behaves as if standalone */
#else
    if (soap_valid_socket(soap->master) || soap_valid_socket(soap->socket)) /* standalone application */
#endif
    { sprintf(soap->tmpbuf, "HTTP/%s %s", soap->http_version, s);
      if ((err = soap->fposthdr(soap, soap->tmpbuf, NULL)))
        return err;
    }
    else if ((err = soap->fposthdr(soap, "Status", s)))	/* CGI */
      return err;
  }
  if ((err = soap->fposthdr(soap, "Server", "gSOAP/2.7"))
   || (err = soap_puthttphdr(soap, status, count)))
    return err;
#ifdef WITH_COOKIES
  if (soap_putsetcookies(soap))
    return soap->error;
#endif
  return soap->fposthdr(soap, NULL, NULL);
}
#endif
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_response(struct soap *soap, int status)
{ register size_t count;
  if (!(soap->omode & (SOAP_ENC_XML | SOAP_IO_STORE /* this tests for chunking too */))
   && (status == SOAP_HTML || status == SOAP_FILE))
    soap->omode = (soap->omode & ~SOAP_IO) | SOAP_IO_STORE;
  soap->status = status;
  count = soap_count_attachments(soap);
  if (soap_begin_send(soap))
    return soap->error;
#ifndef WITH_NOHTTP
  if ((soap->mode & SOAP_IO) != SOAP_IO_STORE && !(soap->mode & SOAP_ENC_XML))
  { register int n = soap->mode;
    soap->mode &= ~(SOAP_IO | SOAP_ENC_ZLIB);
    if ((n & SOAP_IO) != SOAP_IO_FLUSH)
      soap->mode |= SOAP_IO_BUFFER;
    if ((soap->error = soap->fresponse(soap, status, count)))
      return soap->error;
#ifndef WITH_LEANER
    if ((n & SOAP_IO) == SOAP_IO_CHUNK)
    { if (soap_flush(soap))
        return soap->error;
    }
#endif
    soap->mode = n;
  }
#endif
  return SOAP_OK;
}
#endif

/******************************************************************************\
 *
 *	HTTP Cookies
 *
\******************************************************************************/

#ifdef WITH_COOKIES
/******************************************************************************/
SOAP_FMAC1
size_t
SOAP_FMAC2
soap_encode_cookie(const char *s, char *t, size_t len)
{ register int c;
  register size_t n = len;
  while ((c = *s++) && --n > 0)
  { if (c > ' ' && c < 128 && !strchr("()<>@,;:\\\"/[]?={}#!$&'*+", c))
      *t++ = c;
    else if (n > 2)
    { *t++ = '%';
      *t++ = (c >> 4) + (c > 159 ? '7' : '0');
      c &= 0xF;
      *t++ = c + (c > 9 ? '7' : '0');
      n -= 2;
    }
    else
      break;
  }
  *t = '\0';
  return len - n;
}

/******************************************************************************/
SOAP_FMAC1
struct soap_cookie*
SOAP_FMAC2
soap_cookie(struct soap *soap, const char *name, const char *domain, const char *path)
{ struct soap_cookie *p;
  if (!domain)
    domain = soap->cookie_domain;
  if (!path)
    path = soap->cookie_path;
  if (!path)
    path = SOAP_STR_EOS;
  else if (*path == '/')
    path++;
  DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Search cookie %s domain=%s path=%s\n", name, domain?domain:"(null)", path?path:"(null)"));
  for (p = soap->cookies; p; p = p->next)
  { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Cookie in database: %s=%s domain=%s path=%s env=%hd\n", p->name, p->value?p->value:"(null)", p->domain?p->domain:"(null)", p->path?p->path:"(null)", p->env));
    if (!strcmp(p->name, name)
     && p->domain
     && p->path
     && !strcmp(p->domain, domain)
     && (!*p->path || !strncmp(p->path, path, strlen(p->path))))
      break;
  }
  return p;
}

/******************************************************************************/
SOAP_FMAC1
struct soap_cookie*
SOAP_FMAC2
soap_set_cookie(struct soap *soap, const char *name, const char *value, const char *domain, const char *path)
{ struct soap_cookie **p, *q;
  int n;
  if (!domain)
    domain = soap->cookie_domain;
  if (!path)
    path = soap->cookie_path;
  if (!path)
    path = SOAP_STR_EOS;
  else if (*path == '/')
    path++;
  q = soap_cookie(soap, name, domain, path);
  DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Set %scookie: %s=%s domain=%s path=%s\n", q ? SOAP_STR_EOS : "new ", name, value?value:"(null)", domain?domain:"(null)", path?path:"(null)"));
  if (!q)
  { if ((q = (struct soap_cookie*)SOAP_MALLOC(soap, sizeof(struct soap_cookie))))
    { if ((q->name = (char*)SOAP_MALLOC(soap, strlen(name)+1)))
        strcpy(q->name, name);
      q->value = NULL;
      q->domain = NULL;
      q->path = NULL;
      q->expire = 0;
      q->maxage = -1;
      q->version = 1;
      q->secure = 0;
      q->modified = 0;
      for (p = &soap->cookies, n = soap->cookie_max; *p && n; p = &(*p)->next, n--)
        if (!strcmp((*p)->name, name) && (*p)->path && path && strcmp((*p)->path, path) < 0)
          break;
      if (n)
      { q->next = *p;
        *p = q;
      }
      else
      { SOAP_FREE(soap, q->name);
        SOAP_FREE(soap, q);
        q = NULL;
      }
    }
  }
  else
    q->modified = 1;
  if (q)
  { if (q->value)
    { if (!value || strcmp(value, q->value))
      { SOAP_FREE(soap, q->value);
        q->value = NULL;
      }
    }
    if (value && *value && !q->value && (q->value = (char*)SOAP_MALLOC(soap, strlen(value)+1)))
      strcpy(q->value, value);
    if (q->domain)
    { if (!domain || strcmp(domain, q->domain))
      { SOAP_FREE(soap, q->domain);
        q->domain = NULL;
      }
    }
    if (domain && !q->domain && (q->domain = (char*)SOAP_MALLOC(soap, strlen(domain)+1)))
      strcpy(q->domain, domain);
    if (q->path)
    { if (!path || strncmp(path, q->path, strlen(q->path)))
      { SOAP_FREE(soap, q->path);
        q->path = NULL;
      }
    }
    if (path && !q->path && (q->path = (char*)SOAP_MALLOC(soap, strlen(path)+1)))
      strcpy(q->path, path);
    q->session = 1;
    q->env = 0;
  }
  return q;
}

/******************************************************************************/
SOAP_FMAC1
void
SOAP_FMAC2
soap_clr_cookie(struct soap *soap, const char *name, const char *domain, const char *path)
{ struct soap_cookie **p, *q;
  if (!domain)
    domain = soap->cookie_domain;
  if (!domain)
  { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Error in clear cookie %s: cookie domain not set\n", name?name:"(null)"));
    return;
  }
  if (!path)
    path = soap->cookie_path;
  if (!path)
  { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Error in clear cookie %s: cookie path not set\n", name?name:"(null)"));
    return;
  }
  if (*path == '/')
    path++;
  for (p = &soap->cookies, q = *p; q; q = *p)
  { if (!strcmp(q->name, name) && !strcmp(q->domain, domain) && !strncmp(q->path, path, strlen(q->path)))
    { if (q->value)
        SOAP_FREE(soap, q->value);
      if (q->domain)
        SOAP_FREE(soap, q->domain);
      if (q->path)
        SOAP_FREE(soap, q->path);
      *p = q->next;
      SOAP_FREE(soap, q);
    }
    else
      p = &q->next;
  }
}

/******************************************************************************/
SOAP_FMAC1
char *
SOAP_FMAC2
soap_cookie_value(struct soap *soap, const char *name, const char *domain, const char *path)
{ struct soap_cookie *p;
  if ((p = soap_cookie(soap, name, domain, path)))
    return p->value;
  return NULL;
}

/******************************************************************************/
SOAP_FMAC1
char *
SOAP_FMAC2
soap_env_cookie_value(struct soap *soap, const char *name, const char *domain, const char *path)
{ struct soap_cookie *p;
  if ((p = soap_cookie(soap, name, domain, path)) && p->env)
    return p->value;
  return NULL;
}

/******************************************************************************/
SOAP_FMAC1
time_t
SOAP_FMAC2
soap_cookie_expire(struct soap *soap, const char *name, const char *domain, const char *path)
{ struct soap_cookie *p;
  if ((p = soap_cookie(soap, name, domain, path)))
    return p->expire;
  return -1;
}

/******************************************************************************/
SOAP_FMAC1
int
SOAP_FMAC2
soap_set_cookie_expire(struct soap *soap, const char *name, long expire, const char *domain, const char *path)
{ struct soap_cookie *p;
  DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Set cookie expiration max-age %ld: %s domain=%s path=%s\n", expire, name, domain?domain:"(null)", path?path:"(null)"));
  if ((p = soap_cookie(soap, name, domain, path)))
  { p->maxage = expire;
    p->modified = 1;
    return SOAP_OK;
  }
  return SOAP_ERR;
}

/******************************************************************************/
SOAP_FMAC1
int
SOAP_FMAC2
soap_set_cookie_session(struct soap *soap, const char *name, const char *domain, const char *path)
{ struct soap_cookie *p;
  if ((p = soap_cookie(soap, name, domain, path)))
  { p->session = 1;
    p->modified = 1;
    return SOAP_OK;
  }
  return SOAP_ERR;
}

/******************************************************************************/
SOAP_FMAC1
int
SOAP_FMAC2
soap_clr_cookie_session(struct soap *soap, const char *name, const char *domain, const char *path)
{ struct soap_cookie *p;
  if ((p = soap_cookie(soap, name, domain, path)))
  { p->session = 0;
    p->modified = 1;
    return SOAP_OK;
  }
  return SOAP_ERR;
}

/******************************************************************************/
SOAP_FMAC1
int
SOAP_FMAC2
soap_putsetcookies(struct soap *soap)
{ struct soap_cookie *p;
  char *s, tmp[4096];
  const char *t;
  for (p = soap->cookies; p; p = p->next)
  {
    if (p->modified
#ifdef WITH_OPENSSL
     || (!p->env && !soap->ssl == !p->secure)
#endif
       )
    { s = tmp;
      if (p->name)
        s += soap_encode_cookie(p->name, s, tmp-s+4064);
      if (p->value && *p->value)
      { *s++ = '=';
        s += soap_encode_cookie(p->value, s, tmp-s+4064);
      }
      if (p->domain && (int)strlen(p->domain) < tmp-s+4064)
      { strcpy(s, ";Domain=");
        strcat(s, p->domain);
      }
      else if (soap->cookie_domain && (int)strlen(soap->cookie_domain) < tmp-s+4064)
      { strcpy(s, ";Domain=");
        strcat(s, soap->cookie_domain);
      }
      strcat(s, ";Path=/");
      s += strlen(s);
      if (p->path)
        t = p->path;
      else
        t = soap->cookie_path;
      if (t)
      { if (*t == '/')
          t++;
        if ((int)strlen(t) < tmp-s+4064)
        { if (strchr(t, '%'))	/* already URL encoded? */
          { strcpy(s, t);
            s += strlen(s);
          }
          else
            s += soap_encode_cookie(t, s, tmp-s+4064);
        }
      }
      if (p->version > 0 && s-tmp < 4060)
      { sprintf(s, ";Version=%u", p->version);
        s += strlen(s);
      }
      if (p->maxage >= 0 && s-tmp < 4060)
      { sprintf(s, ";Max-Age=%ld", p->maxage);
        s += strlen(s);
      }
      if (s-tmp < 4073
       && (p->secure
#ifdef WITH_OPENSSL
       || soap->ssl
#endif
         ))
        strcpy(s, ";Secure");
      DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Set-Cookie: %s\n", tmp));
      if ((soap->error = soap->fposthdr(soap, "Set-Cookie", tmp)))
        return soap->error;
    }
  }
  return SOAP_OK;
}

/******************************************************************************/
SOAP_FMAC1
int
SOAP_FMAC2
soap_putcookies(struct soap *soap, const char *domain, const char *path, int secure)
{ struct soap_cookie **p, *q;
  unsigned int version = 0;
  time_t now = time(NULL);
  char *s, tmp[4096];
  p = &soap->cookies;
  DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Sending cookies for domain=%s path=%s\n", domain, path));
  if (*path == '/')
    path++;
  while ((q = *p))
  { if (q->expire && now > q->expire)
    { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Cookie %s expired\n", q->name));
      SOAP_FREE(soap, q->name);
      if (q->value)
        SOAP_FREE(soap, q->value);
      if (q->domain)
        SOAP_FREE(soap, q->domain);
      if (q->path)
        SOAP_FREE(soap, q->path);
      *p = q->next;
      SOAP_FREE(soap, q);
    }
    else
    { int flag;
      char *t = q->domain;
      size_t n = 0;
      if (!t)
        flag = 1;
      else
      { const char *r = strchr(t, ':');
        if (r)
          n = r - t;
        else
          n = strlen(t);
        flag = !strncmp(t, domain, n);
      }
      /* domain-level cookies, cannot compile when WITH_NOIO set */
#ifndef WITH_NOIO
      if (!flag)
      { struct hostent *hostent = gethostbyname((char*)domain);
        if (hostent)
        { const char *r = strchr(hostent->h_name, '.');
          if (!r)
            r = hostent->h_name;
          flag = !strncmp(t, r, n);
        }
      }
#endif
      if (flag
          && (!q->path || !strncmp(q->path, path, strlen(q->path)))
          && (!q->secure || secure))
      { s = tmp;
        if (q->version != version)
        { sprintf(s, "$Version=%u;", q->version);
          version = q->version;
        }
        if (q->name)
          s += soap_encode_cookie(q->name, s, tmp-s+4080);
        if (q->value && *q->value)
        { *s++ = '=';
          s += soap_encode_cookie(q->value, s, tmp-s+4080);
        }
        if (q->path && *q->path && (int)strlen(q->path) < tmp-s+4080)
        { sprintf(s, ";$Path=\"/%s\"", (*q->path == '/' ? q->path + 1 : q->path));
          s += strlen(s);
        }
        if (q->domain && (int)strlen(q->domain) < tmp-s+4080)
          sprintf(s, ";$Domain=\"%s\"", q->domain);
        DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Cookie: %s\n", tmp));
        if ((soap->error = soap->fposthdr(soap, "Cookie", tmp)))
          return soap->error;
      }
      p = &q->next;
    }
  }
  return SOAP_OK;
}

/******************************************************************************/
SOAP_FMAC1
void
SOAP_FMAC2
soap_getcookies(struct soap *soap, const char *val)
{ struct soap_cookie *p = NULL, *q;
  const char *s;
  char *t, tmp[4096]; /* cookie size is up to 4096 bytes [RFC2109] */
  char *domain = NULL;
  char *path = NULL;
  unsigned int version = 0;
  time_t now = time(NULL);
  if (!val)
    return;
  s = val;
  while (*s)
  { s = soap_decode_key(tmp, sizeof(tmp), s);
    if (!soap_tag_cmp(tmp, "$Version"))
    { if ((s = soap_decode_val(tmp, sizeof(tmp), s)))
      { if (p)
	  p->version = (int)soap_strtol(tmp, NULL, 10);
	else
	  version = (int)soap_strtol(tmp, NULL, 10);
      }
    }
    else if (!soap_tag_cmp(tmp, "$Path"))
    { s = soap_decode_val(tmp, sizeof(tmp), s);
      if (*tmp)
      { if ((t = (char*)SOAP_MALLOC(soap, strlen(tmp)+1)))
          strcpy(t, tmp);
      }
      else
        t = NULL;
      if (p)
      { if (p->path)
          SOAP_FREE(soap, p->path);
        p->path = t;
      }
      else
      { if (path)
          SOAP_FREE(soap, path);
        path = t;
      }
    }
    else if (!soap_tag_cmp(tmp, "$Domain"))
    { s = soap_decode_val(tmp, sizeof(tmp), s);
      if (*tmp)
      { if ((t = (char*)SOAP_MALLOC(soap, strlen(tmp)+1)))
          strcpy(t, tmp);
      }
      else
        t = NULL;
      if (p)
      { if (p->domain)
          SOAP_FREE(soap, p->domain);
        p->domain = t;
      }
      else
      { if (domain)
          SOAP_FREE(soap, domain);
        domain = t;
      }
    }
    else if (p && !soap_tag_cmp(tmp, "Path"))
    { if (p->path)
        SOAP_FREE(soap, p->path);
      s = soap_decode_val(tmp, sizeof(tmp), s);
      if (*tmp)
      { if ((p->path = (char*)SOAP_MALLOC(soap, strlen(tmp)+1)))
          strcpy(p->path, tmp);
      }
      else
        p->path = NULL;
    }
    else if (p && !soap_tag_cmp(tmp, "Domain"))
    { if (p->domain)
        SOAP_FREE(soap, p->domain);
      s = soap_decode_val(tmp, sizeof(tmp), s);
      if (*tmp)
      { if ((p->domain = (char*)SOAP_MALLOC(soap, strlen(tmp)+1)))
          strcpy(p->domain, tmp);
      }
      else
        p->domain = NULL;
    }
    else if (p && !soap_tag_cmp(tmp, "Version"))
    { s = soap_decode_val(tmp, sizeof(tmp), s);
      p->version = (unsigned int)soap_strtoul(tmp, NULL, 10);
    }
    else if (p && !soap_tag_cmp(tmp, "Max-Age"))
    { s = soap_decode_val(tmp, sizeof(tmp), s);
      p->expire = now + soap_strtol(tmp, NULL, 10);
    }
    else if (p && !soap_tag_cmp(tmp, "Expires"))
    { struct tm T;
      char a[3]; 
      static const char mns[] = "anebarprayunulugepctovec";
      s = soap_decode_val(tmp, sizeof(tmp), s);
      if (strlen(tmp) > 20)
      { memset((void*)&T, 0, sizeof(T));
        a[0] = tmp[4];
        a[1] = tmp[5];
        a[2] = '\0';
        T.tm_mday = (int)soap_strtol(a, NULL, 10);
        a[0] = tmp[8];
        a[1] = tmp[9];
        T.tm_mon = (int)(strstr(mns, a) - mns) / 2;
        a[0] = tmp[11];
        a[1] = tmp[12];
        T.tm_year = 100 + (int)soap_strtol(a, NULL, 10);
        a[0] = tmp[13];
        a[1] = tmp[14];
        T.tm_hour = (int)soap_strtol(a, NULL, 10);
        a[0] = tmp[16];
        a[1] = tmp[17];
        T.tm_min = (int)soap_strtol(a, NULL, 10);
        a[0] = tmp[19];
        a[1] = tmp[20];
        T.tm_sec = (int)soap_strtol(a, NULL, 10);
        p->expire = soap_timegm(&T);
      }
    }
    else if (p && !soap_tag_cmp(tmp, "Secure"))
      p->secure = 1;
    else
    { if (p)
      { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Got environment cookie %s=%s domain=%s path=%s expire=%ld secure=%d\n", p->name, p->value?p->value:"(null)", p->domain?p->domain:"(null)", p->path?p->path:"(null)", p->expire, p->secure));
        if ((q = soap_set_cookie(soap, p->name, p->value, p->domain, p->path)))
        { q->version = p->version;
          q->expire = p->expire;
          q->secure = p->secure;
          q->env = 1;
        }
        if (p->name)
          SOAP_FREE(soap, p->name);
        if (p->value)
          SOAP_FREE(soap, p->value);
        if (p->domain)
          SOAP_FREE(soap, p->domain);
        if (p->path)
          SOAP_FREE(soap, p->path);
        SOAP_FREE(soap, p);
      }
      if ((p = (struct soap_cookie*)SOAP_MALLOC(soap, sizeof(struct soap_cookie))))
      { p->name = (char*)SOAP_MALLOC(soap, strlen(tmp)+1);
        strcpy(p->name, tmp);
        s = soap_decode_val(tmp, sizeof(tmp), s);
        if (*tmp)
        { p->value = (char*)SOAP_MALLOC(soap, strlen(tmp)+1);
          strcpy(p->value, tmp);
        }
        else
          p->value = NULL;
        if (domain)
          p->domain = domain;
        else if (*soap->host)
        { p->domain = (char*)SOAP_MALLOC(soap, strlen(soap->host)+1);
          strcpy(p->domain, soap->host);
        }
        else
          p->domain = NULL;
        if (path)
          p->path = path;
        else if (soap->path && *soap->path)
        { p->path = (char*)SOAP_MALLOC(soap, strlen(soap->path)+1);
          strcpy(p->path, soap->path);
        }
        else
        { p->path = (char*)SOAP_MALLOC(soap, 2);
          strcpy(p->path, "/");
        }
        p->expire = 0;
        p->secure = 0;
        p->version = version;
      }
    }
  }
  if (p)
  { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Got environment cookie %s=%s domain=%s path=%s expire=%ld secure=%d\n", p->name, p->value?p->value:"(null)", p->domain?p->domain:"(null)", p->path?p->path:"(null)", p->expire, p->secure));
    if ((q = soap_set_cookie(soap, p->name, p->value, p->domain, p->path)))
    { q->version = p->version;
      q->expire = p->expire;
      q->secure = p->secure;
      q->env = 1;
    }
    if (p->name)
      SOAP_FREE(soap, p->name);
    if (p->value)
      SOAP_FREE(soap, p->value);
    if (p->domain)
      SOAP_FREE(soap, p->domain);
    if (p->path)
      SOAP_FREE(soap, p->path);
    SOAP_FREE(soap, p);
  }
  if (domain)
    SOAP_FREE(soap, domain);
  if (path)
    SOAP_FREE(soap, path);
}

/******************************************************************************/
SOAP_FMAC1
int
SOAP_FMAC2
soap_getenv_cookies(struct soap *soap)
{ struct soap_cookie *p;
  const char *s;
  char key[4096], val[4096]; /* cookie size is up to 4096 bytes [RFC2109] */
  if (!(s = getenv("HTTP_COOKIE")))
    return SOAP_ERR;
  do
  { s = soap_decode_key(key, sizeof(key), s);
    s = soap_decode_val(val, sizeof(val), s);
    p = soap_set_cookie(soap, key, val, NULL, NULL);
    if (p)
      p->env = 1;
  } while (*s);
  return SOAP_OK;
}

/******************************************************************************/
SOAP_FMAC1
struct soap_cookie*
SOAP_FMAC2
soap_copy_cookies(struct soap *copy, const struct soap *soap)
{ struct soap_cookie *p, **q, *r;
  q = &r;
  for (p = soap->cookies; p; p = p->next)
  { if (!(*q = (struct soap_cookie*)SOAP_MALLOC(copy, sizeof(struct soap_cookie))))
      return r;
    **q = *p;
    if (p->name)
    { if (((*q)->name = (char*)SOAP_MALLOC(copy, strlen(p->name)+1)))
        strcpy((*q)->name, p->name);
    }
    if (p->value)
    { if (((*q)->value = (char*)SOAP_MALLOC(copy, strlen(p->value)+1)))
        strcpy((*q)->value, p->value);
    }
    if (p->domain)
    { if (((*q)->domain = (char*)SOAP_MALLOC(copy, strlen(p->domain)+1)))
        strcpy((*q)->domain, p->domain);
    }
    if (p->path)
    { if (((*q)->path = (char*)SOAP_MALLOC(copy, strlen(p->path)+1)))
        strcpy((*q)->path, p->path);
    }
    q = &(*q)->next;
  }
  *q = NULL;
  return r;
}

/******************************************************************************/
SOAP_FMAC1
void
SOAP_FMAC2
soap_free_cookies(struct soap *soap)
{ struct soap_cookie *p;
  for (p = soap->cookies; p; p = soap->cookies)
  { soap->cookies = p->next;
    SOAP_FREE(soap, p->name);
    if (p->value)
      SOAP_FREE(soap, p->value);
    if (p->domain)
      SOAP_FREE(soap, p->domain);
    if (p->path)
      SOAP_FREE(soap, p->path);
    SOAP_FREE(soap, p);
  }
}

/******************************************************************************/
#endif /* WITH_COOKIES */

/******************************************************************************/
#ifndef WITH_NOIDREF
#ifndef PALM_2
SOAP_FMAC1
size_t
SOAP_FMAC2
soap_hash(register const char *s)
{ register size_t h = 0;
  while (*s)
    h = 65599*h + *s++;
  return h % SOAP_IDHASH;
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_NOIDREF
#ifndef PALM_1
static void
soap_init_pht(struct soap *soap)
{ register int i;
  soap->pblk = NULL;
  soap->pidx = 0;
  for (i = 0; i < (int)SOAP_PTRHASH; i++)
    soap->pht[i] = NULL;
}
#endif
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
struct soap*
SOAP_FMAC2
soap_new1(soap_mode mode)
{ return soap_new2(mode, mode);
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
struct soap*
SOAP_FMAC2
soap_new()
{ return soap_new2(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
struct soap*
SOAP_FMAC2
soap_new2(soap_mode imode, soap_mode omode)
{ struct soap *soap = (struct soap*)malloc(sizeof(struct soap));
  if (soap)
    soap_init2(soap, imode, omode);
  return soap;
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
void
SOAP_FMAC2
soap_free(struct soap *soap)
{ soap_done(soap);
  free(soap);
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
void
SOAP_FMAC2
soap_del(struct soap *soap)
{ free(soap);
}
#endif

/******************************************************************************/
#ifndef WITH_NOIDREF
#ifndef PALM_1
static void
soap_free_pht(struct soap *soap)
{ register struct soap_pblk *pb, *next;
  register int i;
  DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Free pointer hashtable\n"));
  for (pb = soap->pblk; pb; pb = next)
  { next = pb->next;
    SOAP_FREE(soap, pb);
  }
  soap->pblk = NULL;
  soap->pidx = 0;
  for (i = 0; i < (int)SOAP_PTRHASH; i++)
    soap->pht[i] = NULL;
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_NOIDREF
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_embed(struct soap *soap, const void *p, const struct soap_array *a, int n, const char *tag, int type)
{ register int i;
  struct soap_plist *pp;
  if (soap->version == 2)
    soap->encoding = 1;
  if (a)
    i = soap_array_pointer_lookup(soap, p, a, n, type, &pp);
  else
    i = soap_pointer_lookup(soap, p, type, &pp);
  if (i)
  { if (soap_is_embedded(soap, pp)
     || soap_is_single(soap, pp))
      return 0;
    soap_set_embedded(soap, pp);
  }
  return i;
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_NOIDREF
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_pointer_lookup(struct soap *soap, const void *p, int type, struct soap_plist **ppp)
{ register struct soap_plist *pp;
  *ppp = NULL;
  if (p)
  { for (pp = soap->pht[soap_hash_ptr(p)]; pp; pp = pp->next)
    { if (pp->ptr == p && pp->type == type)
      { *ppp = pp;
        DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Lookup location=%p type=%d id=%d\n", p, type, pp->id));
        return pp->id;
      }
    }
  }
  DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Lookup location=%p type=%d: not found\n", p, type));
  return 0;
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_NOIDREF
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_pointer_enter(struct soap *soap, const void *p, const struct soap_array *a, int n, int type, struct soap_plist **ppp)
{ register size_t h;
  register struct soap_plist *pp;
  if (!soap->pblk || soap->pidx >= SOAP_PTRBLK)
  { register struct soap_pblk *pb = (struct soap_pblk*)SOAP_MALLOC(soap, sizeof(struct soap_pblk));
    if (!pb)
    { soap->error = SOAP_EOM;
      return 0;
    }
    pb->next = soap->pblk;
    soap->pblk = pb;
    soap->pidx = 0;
  }
  *ppp = pp = &soap->pblk->plist[soap->pidx++];
  if (a)
    h = soap_hash_ptr(a->__ptr);
  else
    h = soap_hash_ptr(p);
  DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Pointer enter location=%p array=%p size=%d dim=%d type=%d id=%d\n", p, a?a->__ptr:NULL, a?a->__size:0, n, type, soap->idnum+1));
  pp->next = soap->pht[h];
  pp->type = type;
  pp->mark1 = 0;
  pp->mark2 = 0;
  pp->ptr = p;
  pp->array = a;
  soap->pht[h] = pp;
  pp->id = ++soap->idnum;
  return pp->id;
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_NOIDREF
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_array_pointer_lookup(struct soap *soap, const void *p, const struct soap_array *a, int n, int type, struct soap_plist **ppp)
{ register struct soap_plist *pp;
  *ppp = NULL;
  if (!p || !a->__ptr)
    return 0;
  for (pp = soap->pht[soap_hash_ptr(a->__ptr)]; pp; pp = pp->next)
  { if (pp->type == type && pp->array && pp->array->__ptr == a->__ptr)
    { register int i;
      for (i = 0; i < n; i++)
        if (((const int*)&pp->array->__size)[i] != ((const int*)&a->__size)[i])
          break;
      if (i == n)
      { *ppp = pp;
        DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Array lookup location=%p type=%d id=%d\n", a->__ptr, type, pp->id));
        return pp->id;
      }
    }
  }
  DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Array lookup location=%p type=%d: not found\n", a->__ptr, type));
  return 0;
}
#endif
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_begin_count(struct soap *soap)
{ soap_free_ns(soap);
#ifndef WITH_LEANER
  if ((soap->mode & SOAP_ENC_DIME) || (soap->omode & SOAP_ENC_DIME))
    soap->mode = soap->omode | SOAP_IO_LENGTH | SOAP_ENC_DIME;
  else
#endif
  { soap->mode = soap->omode;
    if ((soap->mode & SOAP_IO_UDP))
      soap->mode |= SOAP_ENC_XML;
    if ((soap->mode & SOAP_IO) == SOAP_IO_STORE
     || (((soap->mode & SOAP_IO) == SOAP_IO_CHUNK || (soap->mode & SOAP_ENC_XML))
#ifndef WITH_LEANER
      && !soap->fpreparesend
#endif
      ))
      soap->mode &= ~SOAP_IO_LENGTH;
    else
      soap->mode |= SOAP_IO_LENGTH;
  }
#ifdef WITH_ZLIB
  if ((soap->mode & SOAP_ENC_ZLIB) && (soap->mode & SOAP_IO) == SOAP_IO_FLUSH)
  { if (!(soap->mode & SOAP_ENC_DIME))
      soap->mode &= ~SOAP_IO_LENGTH;
    if (soap->mode & SOAP_ENC_XML)
      soap->mode |= SOAP_IO_BUFFER;
    else
      soap->mode |= SOAP_IO_STORE;
  }
#endif
  if (!soap->encodingStyle && !(soap->mode & SOAP_XML_GRAPH))
    soap->mode |= SOAP_XML_TREE;
#ifndef WITH_LEANER
  if ((soap->mode & SOAP_ENC_MTOM) && (soap->mode & SOAP_ENC_DIME))
    soap->mode |= SOAP_ENC_MIME;
  else if (!(soap->mode & SOAP_ENC_MIME))
    soap->mode &= ~SOAP_ENC_MTOM;
  if (soap->mode & SOAP_ENC_MIME)
    soap_select_mime_boundary(soap);
  soap->dime.list = soap->dime.last;	/* keep track of last DIME attachment */
#endif
  soap->count = 0;
  soap->ns = 0;
  soap->null = 0;
  soap->position = 0;
  soap->mustUnderstand = 0;
  soap->encoding = 0;
  soap->part = SOAP_BEGIN;
  soap->idnum = 0;
  soap_clr_attr(soap);
  soap_set_local_namespaces(soap);
  DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Begin count phase (socket=%d mode=0x%x count=%lu)\n", soap->socket, (unsigned int)soap->mode, (unsigned long)soap->count));
#ifndef WITH_LEANER
  soap->dime.count = 0; /* count # of attachments */
  soap->dime.size = 0; /* accumulate total size of attachments */
  if (soap->fprepareinitsend && (soap->mode & SOAP_IO) != SOAP_IO_STORE)
    return soap->error = soap->fprepareinitsend(soap);   
#endif
  return SOAP_OK;
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_end_count(struct soap *soap)
{ DBGLOG(TEST, SOAP_MESSAGE(fdebug, "End of count phase\n"));
#ifndef WITH_LEANER
  if (soap->fpreparefinalsend && (soap->mode & SOAP_IO_LENGTH))
    return soap->error = soap->fpreparefinalsend(soap);
#endif
  return SOAP_OK;
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_begin_send(struct soap *soap)
{ DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Initializing for output\n"));
  soap_free_ns(soap);
  soap->error = SOAP_OK;
  soap->mode = soap->omode | (soap->mode & (SOAP_IO_LENGTH | SOAP_ENC_DIME));
#ifdef WITH_ZLIB
  if ((soap->mode & SOAP_ENC_ZLIB) && (soap->mode & SOAP_IO) == SOAP_IO_FLUSH)
  { if (soap->mode & SOAP_ENC_XML)
      soap->mode |= SOAP_IO_BUFFER;
    else
      soap->mode |= SOAP_IO_STORE;
  }
#endif
#ifndef WITH_LEAN
  if ((soap->mode & SOAP_IO_UDP))
  { soap->mode |= SOAP_ENC_XML;
    if (soap->count > SOAP_BUFLEN)
      return soap->error = SOAP_UDP_ERROR;
  }
#endif
  if ((soap->mode & SOAP_IO) == SOAP_IO_FLUSH && soap_valid_socket(soap->socket))
  { if (soap->count || (soap->mode & SOAP_IO_LENGTH) || (soap->mode & SOAP_ENC_XML))
      soap->mode |= SOAP_IO_BUFFER;
    else
      soap->mode |= SOAP_IO_STORE;
  }
  soap->mode &= ~SOAP_IO_LENGTH;
  if ((soap->mode & SOAP_IO) == SOAP_IO_STORE)
    if (soap_new_block(soap) == NULL)
      return soap->error;
  if (!(soap->mode & SOAP_IO_KEEPALIVE))
    soap->keep_alive = 0;
  if (!soap->encodingStyle && !(soap->mode & SOAP_XML_GRAPH))
    soap->mode |= SOAP_XML_TREE;
#ifndef WITH_LEANER
  if ((soap->mode & SOAP_ENC_MTOM) && (soap->mode & SOAP_ENC_DIME))
  { soap->mode |= SOAP_ENC_MIME;
    soap->mode &= ~SOAP_ENC_DIME;
  }
  else if (!(soap->mode & SOAP_ENC_MIME))
    soap->mode &= ~SOAP_ENC_MTOM;
  if (soap->mode & SOAP_ENC_MIME)
    soap_select_mime_boundary(soap);
#ifdef WIN32
#ifndef UNDER_CE
#ifndef WITH_FASTCGI
  if (!soap_valid_socket(soap->socket)) /* Set win32 stdout or soap->sendfd to BINARY, e.g. to support DIME */
#ifdef __BORLANDC__
    setmode(soap->sendfd, _O_BINARY);
#else
    _setmode(soap->sendfd, _O_BINARY);
#endif
#endif
#endif
#endif
#endif
  if (soap->mode & SOAP_IO)
  { soap->bufidx = 0;
    soap->buflen = 0;
  }
  soap->chunksize = 0;
  soap->ns = 0;
  soap->null = 0;
  soap->position = 0;
  soap->mustUnderstand = 0;
  soap->encoding = 0;
  soap->idnum = 0;
  soap->level = 0;
  soap_clr_attr(soap);
  soap_set_local_namespaces(soap);
#ifdef WITH_ZLIB
  soap->z_ratio_out = 1.0;
  if ((soap->mode & SOAP_ENC_ZLIB) && soap->zlib_state != SOAP_ZLIB_DEFLATE)
  { if (!soap->z_buf)
      soap->z_buf = (char*)SOAP_MALLOC(soap, SOAP_BUFLEN);
    soap->d_stream->next_out = (Byte*)soap->z_buf;
    soap->d_stream->avail_out = SOAP_BUFLEN;
#ifdef WITH_GZIP
    if (soap->zlib_out != SOAP_ZLIB_DEFLATE)
    { memcpy(soap->z_buf, "\37\213\10\0\0\0\0\0\0\377", 10);
      soap->d_stream->next_out = (Byte*)soap->z_buf + 10;
      soap->d_stream->avail_out = SOAP_BUFLEN - 10;
      soap->z_crc = crc32(0L, NULL, 0);
      soap->zlib_out = SOAP_ZLIB_GZIP;
      if (soap->z_dict)
        *((Byte*)soap->z_buf + 2) = 0xff;
      if (deflateInit2(soap->d_stream, soap->z_level, Z_DEFLATED, -MAX_WBITS, 8, Z_DEFAULT_STRATEGY) != Z_OK)
        return soap->error = SOAP_ZLIB_ERROR;
    }
    else
#endif
    if (deflateInit(soap->d_stream, soap->z_level) != Z_OK)
      return soap->error = SOAP_ZLIB_ERROR;
    if (soap->z_dict)
    { if (deflateSetDictionary(soap->d_stream, (const Bytef*)soap->z_dict, soap->z_dict_len) != Z_OK)
        return soap->error = SOAP_ZLIB_ERROR;
    }
    DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Deflate initialized\n"));
    soap->zlib_state = SOAP_ZLIB_DEFLATE;
  }
#endif
#ifdef WITH_OPENSSL
  if (soap->ssl)
    ERR_clear_error();
#endif
  DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Begin send phase (socket=%d mode=0x%x count=%lu)\n", soap->socket, soap->mode, (unsigned long)soap->count));
  soap->part = SOAP_BEGIN;
#ifndef WITH_LEANER
  if (soap->fprepareinitsend && (soap->mode & SOAP_IO) == SOAP_IO_STORE)
    soap->fprepareinitsend(soap);   
#endif
  return SOAP_OK;
}
#endif

/******************************************************************************/
#ifndef WITH_NOIDREF
#ifndef PALM_2
SOAP_FMAC1
void
SOAP_FMAC2
soap_embedded(struct soap *soap, const void *p, int t)
{ struct soap_plist *pp;
  if (soap_pointer_lookup(soap, p, t, &pp))
  { pp->mark1 = 1;
    pp->mark2 = 1;
    DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Embedded %p type=%d mark set to 1\n", p, t));
  }
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_NOIDREF
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_reference(struct soap *soap, const void *p, int t)
{ struct soap_plist *pp;
  if (!p || (soap->mode & SOAP_XML_TREE))
    return 1;
  if (soap_pointer_lookup(soap, p, t, &pp))
  { if (pp->mark1 == 0)
    { pp->mark1 = 2;
      pp->mark2 = 2;
    }
  }
  else if (soap_pointer_enter(soap, p, NULL, 0, t, &pp))
  { pp->mark1 = 0;
    pp->mark2 = 0;
  }
  else
    return 1;
  DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Reference %p type=%d (%d %d)\n", p, t, (int)pp->mark1, (int)pp->mark2));
  return pp->mark1;
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_NOIDREF
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_array_reference(struct soap *soap, const void *p, const struct soap_array *a, int n, int t)
{ register int i;
  struct soap_plist *pp;
  if (!p || !a->__ptr)
    return 1;
  i = soap_array_pointer_lookup(soap, p, a, n, t, &pp);
  if (i)
  { if (pp->mark1 == 0)
    { pp->mark1 = 2;
      pp->mark2 = 2;
    }
  }
  else if (!soap_pointer_enter(soap, p, a, n, t, &pp))
    return 1;
  else
  { pp->mark1 = 0;
    pp->mark2 = 0;
  }
  DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Array reference %p ptr=%p dim=%d type=%d (%d %d)\n", p, a->__ptr, n, t, (int)pp->mark1, (int)pp->mark2));
  return pp->mark1;
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_NOIDREF
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_embedded_id(struct soap *soap, int id, const void *p, int t)
{ struct soap_plist *pp = NULL;
  if (soap->mode & SOAP_XML_TREE)
    return id;
  DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Embedded_id %p type=%d id=%d\n", p, t, id));
  if (soap->version == 1 && soap->encodingStyle && !(soap->mode & SOAP_XML_GRAPH) && soap->part != SOAP_IN_HEADER)
  { if (id < 0)
    { id = soap_pointer_lookup(soap, p, t, &pp);
      if (id)
      { if (soap->mode & SOAP_IO_LENGTH)
          pp->mark1 = 2;
        else
          pp->mark2 = 2;
        DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Embedded_id multiref id=%d %p type=%d = (%d %d)\n", id, p, t, (int)pp->mark1, (int)pp->mark2));
      }
      return -1;
    }
    return id;
  }
  if (id < 0)
    id = soap_pointer_lookup(soap, p, t, &pp);
  else if (id && !soap_pointer_lookup(soap, p, t, &pp))
    return 0;
  if (id && pp)
  { if (soap->mode & SOAP_IO_LENGTH)
      pp->mark1 = 1;
    else
      pp->mark2 = 1;
    DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Embedded_id embedded ref id=%d %p type=%d = (%d %d)\n", id, p, t, (int)pp->mark1, (int)pp->mark2));
  }
  return id;
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_NOIDREF
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_is_embedded(struct soap *soap, struct soap_plist *pp)
{ if (!pp)
    return 0;
  DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Is embedded? %d %d\n", (int)pp->mark1, (int)pp->mark2));
  if (soap->version == 1 && soap->encodingStyle && !(soap->mode & SOAP_XML_GRAPH) && soap->part != SOAP_IN_HEADER)
  { if (soap->mode & SOAP_IO_LENGTH)
      return pp->mark1 != 0;
    return pp->mark2 != 0;
  }
  if (soap->mode & SOAP_IO_LENGTH)
    return pp->mark1 == 1;
  return pp->mark2 == 1;
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_NOIDREF
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_is_single(struct soap *soap, struct soap_plist *pp)
{ if (soap->part == SOAP_IN_HEADER)
    return 1;
  if (!pp)
    return 0;
  if (soap->mode & SOAP_IO_LENGTH)
    return pp->mark1 == 0;
  return pp->mark2 == 0;
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_NOIDREF
#ifndef PALM_2
SOAP_FMAC1
void
SOAP_FMAC2
soap_set_embedded(struct soap *soap, struct soap_plist *pp)
{ if (!pp)
    return;
  if (soap->mode & SOAP_IO_LENGTH)
    pp->mark1 = 1;
  else
    pp->mark2 = 1;
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_LEANER
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_attachment(struct soap *soap, const char *tag, int id, const void *p, const struct soap_array *a, const char *aid, const char *atype, const char *aoptions, int n, const char *type, int t) 
{
#ifndef WITH_NOIDREF
  struct soap_plist *pp;
  int i;
  if (!p || !a->__ptr || (!aid && !atype))
    return soap_element_id(soap, tag, id, p, a, n, type, t);
  DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Attachment tag='%s' id='%s' (%d) type='%s'\n", tag, aid?aid:SOAP_STR_EOS, id, atype?atype:SOAP_STR_EOS));
  i = soap_array_pointer_lookup(soap, p, a, n, t, &pp);
  if (!i)
  { i = soap_pointer_enter(soap, p, a, n, t, &pp);
    if (!i)
    { soap->error = SOAP_EOM;
      return -1;
    }
  }
  if (id <= 0)
    id = i;
  if (!aid)
  { sprintf(soap->tmpbuf, soap->dime_id_format, id);
    aid = soap_strdup(soap, soap->tmpbuf);
  }
  /* Add MTOM xop:Include element when necessary */
  /* TODO: this code to be obsoleted with new import/xop.h conventions */
  if ((soap->mode & SOAP_ENC_MTOM) && strcmp(tag, "xop:Include"))
  { if (soap_element_begin_out(soap, tag, 0, type)
     || soap_element_href(soap, "xop:Include", 0, "xmlns:xop=\"http://www.w3.org/2004/08/xop/include\" href", aid)
     || soap_element_end_out(soap, tag))
      return soap->error;
  }
  else if (soap_element_href(soap, tag, 0, "href", aid))
    return soap->error;
  if (soap->mode & SOAP_IO_LENGTH)
  { if (pp->mark1 != 3)
    { struct soap_multipart *content;
      if (soap->mode & SOAP_ENC_MTOM)
        content = soap_new_multipart(soap, &soap->mime.first, &soap->mime.last, (char*)a->__ptr, a->__size);
      else
        content = soap_new_multipart(soap, &soap->dime.first, &soap->dime.last, (char*)a->__ptr, a->__size);
      if (!content)
      { soap->error = SOAP_EOM;
        return -1;
      }
      if (!strncmp(aid, "cid:", 4)) /* RFC 2111 */
      { if (soap->mode & SOAP_ENC_MTOM)
        { char *s = (char*)soap_malloc(soap, strlen(aid) - 1);
          if (s)
          { *s = '<';
            strcpy(s + 1, aid + 4);
            strcat(s, ">");
            content->id = s;
          }
        }
        else
          content->id = aid + 4;
      }
      else
        content->id = aid;
      content->type = atype;
      content->options = aoptions;
      content->encoding = SOAP_MIME_BINARY;
      pp->mark1 = 3;
    }
  }
  else
    pp->mark2 = 3;
#endif
  return -1;
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_NOIDREF
#ifndef PALM_1
static void
soap_init_iht(struct soap *soap)
{ register int i;
  for (i = 0; i < SOAP_IDHASH; i++)
    soap->iht[i] = NULL;
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_NOIDREF
#ifndef PALM_1
static void
soap_free_iht(struct soap *soap)
{ register int i;
  register struct soap_ilist *ip = NULL, *p = NULL;
  register struct soap_flist *fp = NULL, *fq = NULL;
  DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Free ID hashtable\n"));
  for (i = 0; i < SOAP_IDHASH; i++)
  { for (ip = soap->iht[i]; ip; ip = p)
    { for (fp = ip->flist; fp; fp = fq)
      { fq = fp->next;
        SOAP_FREE(soap, fp);
      }
      p = ip->next;
      SOAP_FREE(soap, ip);
    }
    soap->iht[i] = NULL;
  }
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_NOIDREF
#ifndef PALM_2
SOAP_FMAC1
struct soap_ilist *
SOAP_FMAC2
soap_lookup(struct soap *soap, const char *id)
{ register struct soap_ilist *ip = NULL;
  for (ip = soap->iht[soap_hash(id)]; ip; ip = ip->next)
    if (!strcmp(ip->id, id))
      return ip;
  return NULL;
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_NOIDREF
#ifndef PALM_2
SOAP_FMAC1
struct soap_ilist *
SOAP_FMAC2
soap_enter(struct soap *soap, const char *id)
{ register size_t h;
  register struct soap_ilist *ip;
  ip = (struct soap_ilist*)SOAP_MALLOC(soap, sizeof(struct soap_ilist) + strlen(id));
  if (ip)
  { h = soap_hash(id);
    strcpy(ip->id, id);
    ip->next = soap->iht[h];
    soap->iht[h] = ip;
  }
  return ip;
}
#endif
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
void*
SOAP_FMAC2
soap_malloc(struct soap *soap, size_t n)
{ register char *p;
  if (!n)
    return (void*)SOAP_NON_NULL;
  if (!soap)
    return SOAP_MALLOC(soap, n);
  if (soap->fmalloc)
    p = (char*)soap->fmalloc(soap, n);
  else
  { n += sizeof(short);
    n += (-(long)n) & (sizeof(void*)-1); /* align at 4-, 8- or 16-byte boundary */
    if (!(p = (char*)SOAP_MALLOC(soap, n + sizeof(void*) + sizeof(size_t))))
    { soap->error = SOAP_EOM;
      return NULL;
    }
    /* set the canary to detect corruption */
    *(unsigned short*)(p + n - sizeof(unsigned short)) = (unsigned short)SOAP_CANARY;
    /* keep chain of alloced cells for destruction */
    *(void**)(p + n) = soap->alist;
    *(size_t*)(p + n + sizeof(void*)) = n;
    soap->alist = p + n;
  }
  soap->alloced = 1;
  return p;
}
#endif

/******************************************************************************/
#ifdef SOAP_MEM_DEBUG
static void
soap_init_mht(struct soap *soap)
{ register int i;
  for (i = 0; i < (int)SOAP_PTRHASH; i++)
    soap->mht[i] = NULL;
}
#endif

/******************************************************************************/
#ifdef SOAP_MEM_DEBUG
static void
soap_free_mht(struct soap *soap)
{ register int i;
  register struct soap_mlist *mp, *mq;
  for (i = 0; i < (int)SOAP_PTRHASH; i++)
  { for (mp = soap->mht[i]; mp; mp = mq)
    { mq = mp->next;
      if (mp->live)
        fprintf(stderr, "%s(%d): malloc() = %p not freed (memory leak or forgot to call soap_end()?)\n", mp->file, mp->line, mp->ptr);
      free(mp);
    }
    soap->mht[i] = NULL;
  }
}
#endif

/******************************************************************************/
#ifdef SOAP_MEM_DEBUG
SOAP_FMAC1
void*
SOAP_FMAC2
soap_track_malloc(struct soap *soap, const char *file, int line, size_t size)
{ register void *p = malloc(size);
  if (soap)
  { register size_t h = soap_hash_ptr(p);
    register struct soap_mlist *mp = (struct soap_mlist*)malloc(sizeof(struct soap_mlist));
    DBGLOG(TEST, SOAP_MESSAGE(fdebug, "%s(%d): malloc(%lu) = %p\n", file, line, (unsigned long)size, p));
    mp->next = soap->mht[h];
    mp->ptr = p;
    mp->file = file;
    mp->line = line;
    mp->live = 1;
    soap->mht[h] = mp;
  }
  return p;
}
#endif

/******************************************************************************/
#ifdef SOAP_MEM_DEBUG
SOAP_FMAC1
void
SOAP_FMAC2
soap_track_free(struct soap *soap, const char *file, int line, void *p)
{ register size_t h = soap_hash_ptr(p);
  register struct soap_mlist *mp;
  for (mp = soap->mht[h]; mp; mp = mp->next)
    if (mp->ptr == p)
      break;
  if (mp)
  { if (mp->live)
    { free(p);
      if (soap->fdebug[SOAP_INDEX_TEST])
      { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "%s(%d): free(%p)\n", file, line, p));
      }
      mp->live = 0;
    }
    else
      fprintf(stderr, "%s(%d): free(%p) double free of pointer malloced at %s(%d)\n", file, line, p, mp->file, mp->line);
  }
  else
    fprintf(stderr, "%s(%d): free(%p) pointer not malloced\n", file, line, p);
}
#endif

/******************************************************************************/
#ifdef SOAP_MEM_DEBUG
static void
soap_track_unlink(struct soap *soap, const void *p)
{ register size_t h = soap_hash_ptr(p);
  register struct soap_mlist *mp;
  for (mp = soap->mht[h]; mp; mp = mp->next)
    if (mp->ptr == p)
      break;
  if (mp)
    mp->live = 0;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
void
SOAP_FMAC2
soap_dealloc(struct soap *soap, void *p)
{ if (soap_check_state(soap))
    return;
  if (p)
  { register char **q;
    for (q = (char**)&soap->alist; *q; q = *(char***)q)
    { 
      if (*(unsigned short*)(char*)(*q - sizeof(unsigned short)) != (unsigned short)SOAP_CANARY)
      {
#ifdef SOAP_MEM_DEBUG
        fprintf(stderr, "Data corruption in dynamic allocation (see logs)\n");
#endif
        DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Data corruption:\n"));
        DBGHEX(TEST, *q - 200, 200);
        DBGLOG(TEST, SOAP_MESSAGE(fdebug, "\n"));
        soap->error = SOAP_MOE;
        return;
      }
      if (p == (void*)(*q - *(size_t*)(*q + sizeof(void*))))
      { *q = **(char***)q;
        DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Freed data at %p\n", p));
        SOAP_FREE(soap, p);
        return;
      }
    }
    soap_delete(soap, p);
  }
  else
  { register char *q;
    DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Free all soap_malloc() data\n"));
    while (soap->alist)
    { q = (char*)soap->alist;
      if (*(unsigned short*)(char*)(q - sizeof(unsigned short)) != (unsigned short)SOAP_CANARY)
      {
#ifdef SOAP_MEM_DEBUG
        fprintf(stderr, "Data corruption in dynamic allocation (see logs)\n");
#endif
        DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Data corruption:\n"));
        DBGHEX(TEST, q - 200, 200);
        DBGLOG(TEST, SOAP_MESSAGE(fdebug, "\n"));
        soap->error = SOAP_MOE;
        return;
      }
      soap->alist = *(void**)q;
      q -= *(size_t*)(q + sizeof(void*));
      SOAP_FREE(soap, q);
    }
    /* we must assume these were deallocated: */
    soap->action = NULL;
    soap->fault = NULL;
    soap->header = NULL;
    soap->userid = NULL;
    soap->passwd = NULL;
    soap->authrealm = NULL;
    soap->http_content = NULL;
#ifndef WITH_LEANER
    soap_clr_mime(soap);
#endif
  }
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
void
SOAP_FMAC2
soap_delete(struct soap *soap, void *p)
{ register struct soap_clist **cp;
  if (soap_check_state(soap))
    return;
  cp = &soap->clist;
  if (p)
  { while (*cp)
    { if (p == (*cp)->ptr)
      { register struct soap_clist *q = *cp;
        *cp = q->next;
        if (q->fdelete(q))
        { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Could not dealloc data %p: deletion callback failed for object type %d\n", q->ptr, q->type));
#ifdef SOAP_MEM_DEBUG
          fprintf(stderr, "new(object type = %d) = %p not freed: deletion callback failed\n", q->type, q->ptr);
#endif
        }
        SOAP_FREE(soap, q);
        return;
      }
      cp = &(*cp)->next;
    }
    DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Could not dealloc data %p: address not in list\n", p));
  }
  else
  { while (*cp)
    { register struct soap_clist *q = *cp;
      *cp = q->next;
      if (q->fdelete(q))
      { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Could not dealloc data %p: deletion callback failed for object type %d\n", q->ptr, q->type));
#ifdef SOAP_MEM_DEBUG
        fprintf(stderr, "new(object type = %d) = %p not freed: deletion callback failed\n", q->type, q->ptr);
#endif
      }
      SOAP_FREE(soap, q);
    }
  }
  soap->fault = NULL; /* this was possibly deallocated */
  soap->header = NULL; /* this was possibly deallocated */
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
void
SOAP_FMAC2
soap_delegate_deletion(struct soap *soap, struct soap *soap_to)
{ register struct soap_clist *cp;
  register char **q;
#ifdef SOAP_MEM_DEBUG
  register void *p;
  register struct soap_mlist **mp, *mq;
  size_t h;
#endif
  for (q = (char**)&soap->alist; *q; q = *(char***)q)
  {
    if (*(unsigned short*)(char*)(*q - sizeof(unsigned short)) != (unsigned short)SOAP_CANARY)
    {
#ifdef SOAP_MEM_DEBUG
      fprintf(stderr, "Data corruption in dynamic allocation (see logs)\n");
#endif
      DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Data corruption:\n"));
      DBGHEX(TEST, *q - 200, 200);
      DBGLOG(TEST, SOAP_MESSAGE(fdebug, "\n"));
      soap->error = SOAP_MOE;
      return;
    }
#ifdef SOAP_MEM_DEBUG
    p = (void*)(*q - *(size_t*)(*q + sizeof(void*)));
    h = soap_hash_ptr(p);
    for (mp = &soap->mht[h]; *mp; mp = &(*mp)->next)
    { if ((*mp)->ptr == p)
      { mq = *mp;
        *mp = mq->next;
	mq->next = soap_to->mht[h];
        soap_to->mht[h] = mq;
        break;
      }
    }
#endif
  }
  *q = (char*)soap_to->alist;
  soap_to->alist = soap->alist;
  soap->alist = NULL;
  cp = soap_to->clist;
  if (cp)
  { while (cp->next)
      cp = cp->next;
    cp->next = soap->clist;
  }
  else
    soap_to->clist = soap->clist;
  soap->clist = NULL;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
struct soap_clist *
SOAP_FMAC2
soap_link(struct soap *soap, void *p, int t, int n, int (*fdelete)(struct soap_clist*))
{ register struct soap_clist *cp;
  if ((cp = (struct soap_clist*)SOAP_MALLOC(soap, sizeof(struct soap_clist))))
  { cp->next = soap->clist;
    cp->type = t;
    cp->size = n; 
    cp->ptr = p;
    cp->fdelete = fdelete;
    soap->clist = cp;
  }
  return cp;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
void
SOAP_FMAC2
soap_unlink(struct soap *soap, const void *p)
{ register char **q;
  register struct soap_clist **cp;
  if (!soap || !p)
    return;
  for (q = (char**)&soap->alist; *q; q = *(char***)q)
  { if (p == (void*)(*q - *(size_t*)(*q + sizeof(void*))))
    { *q = **(char***)q;
      DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Unlinked data %p\n", p));
#ifdef SOAP_MEM_DEBUG
      soap_track_unlink(soap, p);
#endif
      return;
    }
  }
  for (cp = &soap->clist; *cp; cp = &(*cp)->next)
  { if (p == (*cp)->ptr)
    { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Unlinked class instance %p\n", p));
      q = (char**)*cp;
      *cp = (*cp)->next;
      SOAP_FREE(soap, q);
      return;
    }
  }
}
#endif

/******************************************************************************/
#ifndef WITH_NOIDREF
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_lookup_type(struct soap *soap, const char *id)
{ register struct soap_ilist *ip;
  if (id && *id)
  { ip = soap_lookup(soap, id);
    if (ip)
    { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Lookup id='%s' type=%d\n", id, ip->type));
      return ip->type;
    }
  }
  DBGLOG(TEST, SOAP_MESSAGE(fdebug, "lookup type id='%s' NOT FOUND! Need to get it from xsi:type\n", id));
  return 0;
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_NOIDREF
#ifndef PALM_2
SOAP_FMAC1
void*
SOAP_FMAC2
soap_id_lookup(struct soap *soap, const char *id, void **p, int t, size_t n, unsigned int k)
{ struct soap_ilist *ip;
  void **q;
  if (!p || !id || !*id)
    return p;
  ip = soap_lookup(soap, id); /* lookup pointer to hash table entry for string id */
  if (!ip)
  { if (!(ip = soap_enter(soap, id))) /* new hash table entry for string id */
      return NULL;
    DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Forwarding first href='%s' type=%d %p (%u bytes)\n", id, t, p, (unsigned int)n));
    ip->type = t;
    ip->size = n; 
    ip->link = p;
    ip->copy = NULL;
    ip->flist = NULL;
    ip->ptr = NULL;
    ip->level = k;
    *p = NULL;
  }
  else if (ip->ptr)
  { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Resolved href='%s' type=%d location=%p (%u bytes)\n", id, t, ip->ptr, (unsigned int)n));
    if (ip->type != t)
    { strcpy(soap->id, id);
      soap->error = SOAP_HREF;
      DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Type incompatibility: href='%s' id-type=%d href-type=%d\n", id, ip->type, t));
      return NULL;
    }
    while (ip->level < k)
    { q = (void**)soap_malloc(soap, sizeof(void*));  
      if (!q)
        return NULL;
      *p = (void*)q;
      p = q;
      k--;
      DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Descending one level...\n"));
    }
    *p = ip->ptr;
  }
  else if (ip->level > k)
  { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Resolving level %u pointers to href='%s'\n", ip->level, id));
    while (ip->level > k)
    { void *s, **r = &ip->link;
      q = (void**)ip->link;
      while (q)
      { *r = (void*)soap_malloc(soap, sizeof(void*));
        if (!*r)
	  return NULL;
        s = *q;
        *q = *r;
        r = (void**)*r;
        q = (void**)s;
      }
      *r = NULL;
      ip->size = n; 
      ip->copy = NULL;
      ip->level = ip->level - 1;
      DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Descending one level...\n"));
    }
    q = (void**)ip->link;
    ip->link = p;
    *p = (void*)q;
  }
  else
  { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Forwarded href='%s' type=%d location=%p (%u bytes)\n", id, t, p, (unsigned int)n));
    while (ip->level < k)
    { q = (void**)soap_malloc(soap, sizeof(void*));  
      if (!q)
        return NULL;
      *p = q;
      p = q;
      k--;
      DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Descending one level...\n"));
    }
    q = (void**)ip->link;
    ip->link = p;
    *p = (void*)q;
  }
  return p;
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_NOIDREF
#ifndef PALM_2
SOAP_FMAC1
void*
SOAP_FMAC2
soap_id_forward(struct soap *soap, const char *href, void *p, size_t len, int st, int tt, size_t n, unsigned int k, void (*fcopy)(struct soap*, int, int, void*, size_t, const void*, size_t))
{ struct soap_ilist *ip;
  if (!p || !href || !*href)
    return p;
  ip = soap_lookup(soap, href); /* lookup pointer to hash table entry for string id */
  if (!ip)
  { if (!(ip = soap_enter(soap, href))) /* new hash table entry for string id */
      return NULL;
    ip->type = st;
    ip->size = n;
    ip->link = NULL;
    ip->copy = NULL;
    ip->ptr = NULL;
    ip->level = 0;
    ip->flist = NULL;
    DBGLOG(TEST,SOAP_MESSAGE(fdebug, "New entry href='%s' type=%d size=%lu level=%d location=%p\n", href, st, (unsigned long)n, k, p));
  }
  else if (ip->type != st || (ip->level == k && ip->size != n))
  { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Type incompatibility id='%s' expect type=%d size=%lu level=%u got type=%d size=%lu\n", href, ip->type, (unsigned long)ip->size, k, st, (unsigned long)n));
    strcpy(soap->id, href);
    soap->error = SOAP_HREF;
    return NULL;
  }
  if (fcopy || n < sizeof(void*) || *href != '#')
  { register struct soap_flist *fp = (struct soap_flist*)SOAP_MALLOC(soap, sizeof(struct soap_flist));
    if (!fp)
    { soap->error = SOAP_EOM;
      return NULL;
    }
    fp->next = ip->flist;
    fp->type = tt;
    fp->ptr = p;
    fp->level = k;
    fp->len = len;
    if (fcopy)
      fp->fcopy = fcopy;
    else
      fp->fcopy = soap_fcopy;
    ip->flist = fp;
    DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Forwarding type=%d (target type=%d) size=%lu location=%p level=%u len=%lu href='%s'\n", st, tt, (unsigned long)n, p, k, (unsigned long)len, href));
  }
  else
  { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Forwarding copying address %p for type=%d href='%s'\n", p, st, href));
    *(void**)p = ip->copy;
    ip->copy = p;
  }
  return p;
}
#endif
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
void*
SOAP_FMAC2
soap_id_enter(struct soap *soap, const char *id, void *p, int t, size_t n, unsigned int k, const char *type, const char *arrayType, void *(*finstantiate)(struct soap*, int, const char*, const char*, size_t*))
{
#ifndef WITH_NOIDREF
  struct soap_ilist *ip;
#endif
  DBGLOG(TEST,SOAP_MESSAGE(fdebug, "Enter id='%s' type=%d loc=%p size=%lu level=%u\n", id, t, p, (unsigned long)n, k));
  soap->alloced = 0;
  if (!p)
  { if (finstantiate)
      p = finstantiate(soap, t, type, arrayType, &n);
    else
      p = soap_malloc(soap, n);
    if (p)
      soap->alloced = 1;
  }
#ifndef WITH_NOIDREF
  if (!id || !*id)
#endif
    return p;
#ifndef WITH_NOIDREF
  ip = soap_lookup(soap, id); /* lookup pointer to hash table entry for string id */
  DBGLOG(TEST,SOAP_MESSAGE(fdebug, "Lookup entry id='%s for location=%p'\n", id, p));
  if (!ip)
  { if (!(ip = soap_enter(soap, id))) /* new hash table entry for string id */
      return NULL;
    ip->type = t;
    ip->link = NULL;
    ip->copy = NULL;
    ip->flist = NULL;
    ip->size = n;
    ip->ptr = p;
    ip->level = k;
    DBGLOG(TEST,SOAP_MESSAGE(fdebug, "New entry id='%s' type=%d size=%lu level=%u location=%p\n", id, t, (unsigned long)n, k, p));
  }
  else if ((ip->type != t || (ip->level == k && ip->size != n)) && (ip->copy || ip->flist))
  { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Type incompatibility id='%s' expect type=%d size=%lu level=%u got type=%d size=%lu\n", id, ip->type, (unsigned long)ip->size, k, t, (unsigned long)n));
    strcpy(soap->id, id);
    soap->error = SOAP_HREF;
    return NULL;
  }
  else if (ip->ptr)
  { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Multiply defined id='%s'\n", id));
    strcpy(soap->id, id);
    soap->error = SOAP_DUPLICATE_ID;
    return NULL;
  }
  else 
  { ip->size = n;
    ip->ptr = p;
    ip->level = k;
    DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Update entry id='%s' type=%d location=%p size=%lu level=%u\n", id, t, p, (unsigned long)n, k));
  }
  return ip->ptr;
#endif
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
void
SOAP_FMAC2
soap_fcopy(struct soap *soap, int st, int tt, void *p, size_t len, const void *q, size_t n)
{ DBGLOG(TEST,SOAP_MESSAGE(fdebug, "Copying data type=%d (target type=%d) %p -> %p (%lu bytes)\n", st, tt, q, p, (unsigned long)n));
  memcpy(p, q, n);
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_end_send(struct soap *soap)
{ 
#ifndef WITH_LEANER
  int err;
  if (soap->dime.list)
  { /* SOAP body referenced attachments must appear first */
    soap->dime.last->next = soap->dime.first;
    soap->dime.first = soap->dime.list->next;
    soap->dime.list->next = NULL;
    soap->dime.last = soap->dime.list;
  }
  if (!(err = soap_putdime(soap)))
    err = soap_putmime(soap);
  soap->mime.list = NULL;
  soap->mime.first = NULL;
  soap->mime.last = NULL;
  soap->dime.list = NULL;
  soap->dime.first = NULL;
  soap->dime.last = NULL;
  if (err)
    return err;
#endif
  DBGLOG(TEST, SOAP_MESSAGE(fdebug, "End send\n"));
  if (soap->mode & SOAP_IO) /* need to flush the remaining data in buffer */
  { if (soap_flush(soap))
#ifdef WITH_ZLIB
    { if (soap->mode & SOAP_ENC_ZLIB && soap->zlib_state == SOAP_ZLIB_DEFLATE)
      { soap->zlib_state = SOAP_ZLIB_NONE;
        deflateEnd(soap->d_stream);
      }
      return soap->error;
    }
#else
      return soap->error;
#endif
#ifdef WITH_ZLIB
    if (soap->mode & SOAP_ENC_ZLIB)
    { int r;
      soap->d_stream->avail_in = 0;
      do
      { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Deflating remainder\n"));
        r = deflate(soap->d_stream, Z_FINISH);
        if (soap->d_stream->avail_out != SOAP_BUFLEN)
        { if (soap_flush_raw(soap, soap->z_buf, SOAP_BUFLEN - soap->d_stream->avail_out))
          { soap->zlib_state = SOAP_ZLIB_NONE;
            deflateEnd(soap->d_stream);
            return soap->error;
          }
          soap->d_stream->next_out = (Byte*)soap->z_buf;
          soap->d_stream->avail_out = SOAP_BUFLEN;
        }
      } while (r == Z_OK);
      DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Deflated total %lu->%lu bytes\n", soap->d_stream->total_in, soap->d_stream->total_out));
      soap->z_ratio_out = (float)soap->d_stream->total_out / (float)soap->d_stream->total_in;
      soap->mode &= ~SOAP_ENC_ZLIB;
      soap->zlib_state = SOAP_ZLIB_NONE;
      if (deflateEnd(soap->d_stream) != Z_OK || r != Z_STREAM_END)
      { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Unable to end deflate: %s\n", soap->d_stream->msg?soap->d_stream->msg:SOAP_STR_EOS));
        return soap->error = SOAP_ZLIB_ERROR;
      }
#ifdef WITH_GZIP
      if (soap->zlib_out != SOAP_ZLIB_DEFLATE)
      { soap->z_buf[0] = soap->z_crc & 0xFF;
        soap->z_buf[1] = (soap->z_crc >> 8) & 0xFF;
        soap->z_buf[2] = (soap->z_crc >> 16) & 0xFF;
        soap->z_buf[3] = (soap->z_crc >> 24) & 0xFF;
        soap->z_buf[4] = soap->d_stream->total_in & 0xFF;
        soap->z_buf[5] = (soap->d_stream->total_in >> 8) & 0xFF;
        soap->z_buf[6] = (soap->d_stream->total_in >> 16) & 0xFF;
        soap->z_buf[7] = (soap->d_stream->total_in >> 24) & 0xFF;
        if (soap_flush_raw(soap, soap->z_buf, 8))
          return soap->error;
        DBGLOG(TEST, SOAP_MESSAGE(fdebug, "gzip crc32=%lu\n", (unsigned long)soap->z_crc));
      }
#endif
    }
#endif
    if ((soap->mode & SOAP_IO) == SOAP_IO_STORE)
    { char *p;
#ifndef WITH_NOHTTP
      if (!(soap->mode & SOAP_ENC_XML))
      { soap->mode--;
        DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Sending buffered message of length %u\n", (unsigned int)soap->blist->size));
        if (soap->status >= SOAP_POST)
          soap->error = soap->fpost(soap, soap->endpoint, soap->host, soap->port, soap->path, soap->action, soap->blist->size);
        else if (soap->status != SOAP_STOP)
          soap->error = soap->fresponse(soap, soap->status, soap->blist->size);
        if (soap->error || soap_flush(soap))
          return soap->error;
        soap->mode++;
      }
#endif
      for (p = soap_first_block(soap, NULL); p; p = soap_next_block(soap, NULL))
      { DBGMSG(SENT, p, soap_block_size(soap, NULL));
        if ((soap->error = soap->fsend(soap, p, soap_block_size(soap, NULL))))
        { soap_end_block(soap, NULL);
          return soap->error;
        }
      }
      soap_end_block(soap, NULL);
    }
#ifndef WITH_LEANER
    else if ((soap->mode & SOAP_IO) == SOAP_IO_CHUNK)
    { DBGMSG(SENT, "\r\n0\r\n\r\n", 7);
      if ((soap->error = soap->fsend(soap, "\r\n0\r\n\r\n", 7)))
        return soap->error;
    }
#endif
  }
#ifdef WITH_TCPFIN
#ifdef WITH_OPENSSL
  if (!soap->ssl && soap_valid_socket(soap->socket) && !soap->keep_alive && !(soap->omode & SOAP_IO_UDP))
    soap->fshutdownsocket(soap, soap->socket, SOAP_SHUT_WR); /* Send TCP FIN */
#else
  if (soap_valid_socket(soap->socket) && !soap->keep_alive && !(soap->omode & SOAP_IO_UDP))
    soap->fshutdownsocket(soap, soap->socket, SOAP_SHUT_WR); /* Send TCP FIN */
#endif
#endif
  DBGLOG(TEST, SOAP_MESSAGE(fdebug, "End of send phase\n"));
  soap->omode &= ~SOAP_XML_SEC;
  soap->count = 0;
  soap->part = SOAP_END;
  return SOAP_OK;
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_end_recv(struct soap *soap)
{ soap->part = SOAP_END;
#ifndef WITH_LEAN
  soap->wsuid = NULL;		/* reset before next send */
  soap->c14nexclude = NULL;	/* reset before next send */
#endif
#ifndef WITH_LEANER
  if ((soap->mode & SOAP_ENC_DIME) && soap_getdime(soap))
  { soap->dime.first = NULL;
    soap->dime.last = NULL;
    return soap->error;
  }
  soap->dime.list = soap->dime.first;
  soap->dime.first = NULL;
  soap->dime.last = NULL;
  /* Check if MIME attachments and mime-post-check flag is set, if so call soap_resolve() and return */
  if (soap->mode & SOAP_ENC_MIME)
  { 
    if (soap->mode & SOAP_MIME_POSTCHECK)
    { DBGLOG(TEST,SOAP_MESSAGE(fdebug, "Post checking MIME attachments\n"));
      if (!soap->keep_alive)
        soap->keep_alive = -1;
#ifndef WITH_NOIDREF
      soap_resolve(soap);
#endif
      return SOAP_OK;
    }
    if (soap_getmime(soap))
      return soap->error;
  }
  soap->mime.list = soap->mime.first;
  soap->mime.first = NULL;
  soap->mime.last = NULL;
  soap->mime.boundary = NULL;
  if (soap->xlist)
  { struct soap_multipart *content;
    for (content = soap->mime.list; content; content = content->next)
      soap_resolve_attachment(soap, content);
  }
#endif
  DBGLOG(TEST,SOAP_MESSAGE(fdebug, "End of receive message ok\n"));
#ifdef WITH_ZLIB
  if (soap->mode & SOAP_ENC_ZLIB)
  { /* Make sure end of compressed content is reached */
    while (soap->d_stream->next_out != Z_NULL)
      if ((int)soap_get1(soap) == EOF)
        break;
    soap->mode &= ~SOAP_ENC_ZLIB;
    memcpy(soap->buf, soap->z_buf, SOAP_BUFLEN);
    soap->bufidx = (char*)soap->d_stream->next_in - soap->z_buf;
    soap->buflen = soap->z_buflen;
    soap->zlib_state = SOAP_ZLIB_NONE;
    if (inflateEnd(soap->d_stream) != Z_OK)
      return soap->error = SOAP_ZLIB_ERROR;
    DBGLOG(TEST,SOAP_MESSAGE(fdebug, "Inflate end ok\n"));
#ifdef WITH_GZIP
    if (soap->zlib_in == SOAP_ZLIB_GZIP)
    { soap_wchar c;
      short i;
      DBGLOG(TEST,SOAP_MESSAGE(fdebug, "Inflate gzip crc check\n"));
      for (i = 0; i < 8; i++)
      { if ((int)(c = soap_get1(soap)) == EOF)
          return soap->error = SOAP_EOF;
        soap->z_buf[i] = (char)c;
      }
      if (soap->z_crc != ((uLong)(unsigned char)soap->z_buf[0] | ((uLong)(unsigned char)soap->z_buf[1] << 8) | ((uLong)(unsigned char)soap->z_buf[2] << 16) | ((uLong)(unsigned char)soap->z_buf[3] << 24)))
      { DBGLOG(TEST,SOAP_MESSAGE(fdebug, "Gzip error: crc check failed, message corrupted? (crc32=%lu)\n", (unsigned long)soap->z_crc));
        return soap->error = SOAP_ZLIB_ERROR;
      }
      if (soap->d_stream->total_out != ((uLong)(unsigned char)soap->z_buf[4] | ((uLong)(unsigned char)soap->z_buf[5] << 8) | ((uLong)(unsigned char)soap->z_buf[6] << 16) | ((uLong)(unsigned char)soap->z_buf[7] << 24)))
      { DBGLOG(TEST,SOAP_MESSAGE(fdebug, "Gzip error: incorrect message length\n"));
        return soap->error = SOAP_ZLIB_ERROR;
      }
    }
    soap->zlib_in = SOAP_ZLIB_NONE;
#endif
  }
#endif
  if ((soap->mode & SOAP_IO) == SOAP_IO_CHUNK)
    while ((int)soap_getchar(soap) != EOF) /* advance to last chunk */
      ;
#ifndef WITH_NOIDREF
  if (soap_resolve(soap))
    return soap->error;
#endif
#ifndef WITH_LEANER
  if (soap->xlist)
  { if (soap->mode & SOAP_ENC_MTOM)
      return soap->error = SOAP_MIME_HREF;
    return soap->error = SOAP_DIME_HREF;
  }
#endif
  soap_free_ns(soap);
#ifndef WITH_LEANER
  if (soap->fpreparefinalrecv)
    return soap->error = soap->fpreparefinalrecv(soap);
#endif
  return SOAP_OK;
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
void
SOAP_FMAC2
soap_free_temp(struct soap *soap)
{ register struct soap_attribute *tp, *tq;
  register struct Namespace *ns;
  soap_free_ns(soap);
  DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Free any remaining temp blocks\n"));
  while (soap->blist)
    soap_end_block(soap, NULL);
  DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Free attribute storage\n"));
  for (tp = soap->attributes; tp; tp = tq)
  { tq = tp->next;
    if (tp->value)
      SOAP_FREE(soap, tp->value);
    SOAP_FREE(soap, tp);
  }
  soap->attributes = NULL;
#ifdef WITH_FAST
  if (soap->labbuf)
    SOAP_FREE(soap, soap->labbuf);
  soap->labbuf = NULL;
  soap->lablen = 0;
  soap->labidx = 0;
#endif
  ns = soap->local_namespaces;
  if (ns)
  { for (; ns->id; ns++)
    { if (ns->out)
      { if (soap->encodingStyle == ns->out)
          soap->encodingStyle = SOAP_STR_EOS;
        SOAP_FREE(soap, ns->out);
        ns->out = NULL;
      }
      if (soap->encodingStyle == ns->ns)
        soap->encodingStyle = SOAP_STR_EOS;
    }
    SOAP_FREE(soap, soap->local_namespaces);
    soap->local_namespaces = NULL;
  }
#ifndef WITH_LEANER
  while (soap->xlist)
  { struct soap_xlist *xp = soap->xlist->next;
    SOAP_FREE(soap, soap->xlist);
    soap->xlist = xp;
  }
#endif
#ifndef WITH_NOIDREF
  soap_free_pht(soap);
  soap_free_iht(soap);
#endif
}
#endif

/******************************************************************************/
#ifndef PALM_1
static void
soap_free_ns(struct soap *soap)
{ register struct soap_nlist *np, *nq;
  DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Free namespace stack\n"));
  for (np = soap->nlist; np; np = nq)
  { nq = np->next;
    SOAP_FREE(soap, np);
  }
  soap->nlist = NULL;
}
#endif

/******************************************************************************/
#ifndef PALM_1
#if !defined(WITH_LEAN) || defined(SOAP_DEBUG)
static void
soap_init_logs(struct soap *soap)
{ int i;
  for (i = 0; i < SOAP_MAXLOGS; i++)
  { soap->logfile[i] = NULL;
    soap->fdebug[i] = NULL;
  }
}
#endif
#endif

/******************************************************************************/
#if !defined(WITH_LEAN) || defined(SOAP_DEBUG)
SOAP_FMAC1
void
SOAP_FMAC2
soap_open_logfile(struct soap *soap, int i)
{ if (soap->logfile[i])
    soap->fdebug[i] = fopen(soap->logfile[i], i < 2 ? "ab" : "a");
}
#endif

/******************************************************************************/
#ifdef SOAP_DEBUG
static void
soap_close_logfile(struct soap *soap, int i)
{ if (soap->fdebug[i])
  { fclose(soap->fdebug[i]);
    soap->fdebug[i] = NULL;
  }
}
#endif

/******************************************************************************/
#ifdef SOAP_DEBUG
SOAP_FMAC1
void
SOAP_FMAC2
soap_close_logfiles(struct soap *soap)
{ int i;
  for (i = 0; i < SOAP_MAXLOGS; i++)
    soap_close_logfile(soap, i);
}
#endif

/******************************************************************************/
#ifdef SOAP_DEBUG
static void
soap_set_logfile(struct soap *soap, int i, const char *logfile)
{ const char *s;
  char *t = NULL;
  soap_close_logfile(soap, i);
  s = soap->logfile[i];
  soap->logfile[i] = logfile;
  if (s)
    SOAP_FREE(soap, (void*)s);
  if (logfile)
    if ((t = (char*)SOAP_MALLOC(soap, strlen(logfile) + 1)))
      strcpy(t, logfile);
  soap->logfile[i] = t;
}
#endif

/******************************************************************************/
#ifdef SOAP_DEBUG
SOAP_FMAC1
void
SOAP_FMAC2
soap_set_recv_logfile(struct soap *soap, const char *logfile)
{ soap_set_logfile(soap, SOAP_INDEX_RECV, logfile);
}
#endif

/******************************************************************************/
#ifdef SOAP_DEBUG
SOAP_FMAC1
void
SOAP_FMAC2
soap_set_sent_logfile(struct soap *soap, const char *logfile)
{ soap_set_logfile(soap, SOAP_INDEX_SENT, logfile);
}
#endif

/******************************************************************************/
#ifdef SOAP_DEBUG
SOAP_FMAC1
void
SOAP_FMAC2
soap_set_test_logfile(struct soap *soap, const char *logfile)
{ soap_set_logfile(soap, SOAP_INDEX_TEST, logfile);
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
struct soap*
SOAP_FMAC2
soap_copy(const struct soap *soap)
{ return soap_copy_context((struct soap*)malloc(sizeof(struct soap)), soap);
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
struct soap*
SOAP_FMAC2
soap_copy_context(struct soap *copy, const struct soap *soap)
{ if (soap_check_state(soap))
    return NULL;
  if (copy)
  { register struct soap_plugin *p = NULL;
#ifdef __cplusplus
    *copy = *soap;
#else
    memcpy(copy, soap, sizeof(struct soap));
#endif
    copy->state = SOAP_COPY;
    copy->error = SOAP_OK;
    copy->userid = NULL;
    copy->passwd = NULL;
    copy->nlist = NULL;
    copy->blist = NULL;
    copy->clist = NULL;
    copy->alist = NULL;
    copy->attributes = NULL;
    copy->labbuf = NULL;
    copy->lablen = 0;
    copy->labidx = 0;
#ifdef SOAP_MEM_DEBUG
    soap_init_mht(copy);
#endif
#if !defined(WITH_LEAN) || defined(SOAP_DEBUG)
    soap_init_logs(copy);
#endif
#ifdef SOAP_DEBUG
    soap_set_test_logfile(copy, soap->logfile[SOAP_INDEX_TEST]);
    soap_set_sent_logfile(copy, soap->logfile[SOAP_INDEX_SENT]);
    soap_set_recv_logfile(copy, soap->logfile[SOAP_INDEX_RECV]);
#endif
#ifdef WITH_C_LOCALE
    copy->c_locale = duplocale(soap->c_locale);
#else
    copy->c_locale = NULL;
#endif
#ifdef WITH_OPENSSL
    copy->bio = NULL;
    copy->ssl = NULL;
    copy->session = NULL;
#endif
#ifdef WITH_GNUTLS
    copy->session = NULL;
#endif
#ifdef WITH_ZLIB
    copy->d_stream = (z_stream*)SOAP_MALLOC(copy, sizeof(z_stream));
    copy->d_stream->zalloc = Z_NULL;
    copy->d_stream->zfree = Z_NULL;
    copy->d_stream->opaque = Z_NULL;
    copy->z_buf = NULL;
#endif
    copy->local_namespaces = NULL;
#ifndef WITH_NOIDREF
    soap_init_iht(copy);
    soap_init_pht(copy);
#endif
    copy->header = NULL;
    copy->fault = NULL;
    copy->action = NULL;
#ifndef WITH_LEAN
#ifdef WITH_COOKIES
    copy->cookies = soap_copy_cookies(copy, soap);
#else
    copy->cookies = NULL;
#endif
#endif
    copy->plugins = NULL;
    for (p = soap->plugins; p; p = p->next)
    { register struct soap_plugin *q = (struct soap_plugin*)SOAP_MALLOC(copy, sizeof(struct soap_plugin));
      if (!q)
        return NULL;
      DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Copying plugin '%s'\n", p->id));
      *q = *p;
      if (p->fcopy && p->fcopy(copy, q, p))
      { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Could not copy plugin '%s'\n", p->id));
        SOAP_FREE(copy, q);
        return NULL;
      }
      q->next = copy->plugins;
      copy->plugins = q;
    }
  }
  return copy;
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
void
SOAP_FMAC2
soap_copy_stream(struct soap *copy, struct soap *soap)
{ copy->mode = soap->mode;
  copy->imode = soap->imode;
  copy->omode = soap->omode;
  copy->socket = soap->socket;
  copy->recv_timeout = soap->recv_timeout;
  copy->send_timeout = soap->send_timeout;
#if defined(__cplusplus) && !defined(WITH_LEAN)
  copy->os = soap->os;
  copy->is = soap->is;
#endif
  copy->sendfd = soap->sendfd;
  copy->recvfd = soap->recvfd;
  copy->bufidx = soap->bufidx;
  copy->buflen = soap->buflen;
  copy->ahead = soap->ahead;
  copy->cdata = soap->cdata;
  copy->chunksize = soap->chunksize;
  copy->chunkbuflen = soap->chunkbuflen;
  copy->keep_alive = soap->keep_alive;
  copy->tcp_keep_alive = soap->tcp_keep_alive;
  copy->tcp_keep_idle = soap->tcp_keep_idle;
  copy->tcp_keep_intvl = soap->tcp_keep_intvl;
  copy->tcp_keep_cnt = soap->tcp_keep_cnt;
  copy->max_keep_alive = soap->max_keep_alive;
#ifndef WITH_NOIO
  copy->peer = soap->peer;
  copy->peerlen = soap->peerlen;
#endif
#ifdef WITH_OPENSSL
  copy->bio = soap->bio;
  copy->ssl = soap->ssl;
  copy->ctx = soap->ctx;
#endif
#ifdef WITH_GNUTLS
  copy->session = soap->session; /* TODO: GNUTLS provides a dup? */
#endif
#ifdef WITH_ZLIB
  copy->zlib_state = soap->zlib_state;
  copy->zlib_in = soap->zlib_in;
  copy->zlib_out = soap->zlib_out;
  copy->d_stream = (z_stream*)SOAP_MALLOC(copy, sizeof(z_stream));
  memcpy(copy->d_stream, soap->d_stream, sizeof(z_stream));
  copy->z_crc = soap->z_crc;
  copy->z_ratio_in = soap->z_ratio_in;
  copy->z_ratio_out = soap->z_ratio_out;
  copy->z_buf = NULL;
  copy->z_buflen = soap->z_buflen;
  copy->z_level = soap->z_level;
  if (soap->z_buf && soap->zlib_state != SOAP_ZLIB_NONE)
  { copy->z_buf = (char*)SOAP_MALLOC(copy, SOAP_BUFLEN);
    memcpy(copy->z_buf, soap->z_buf, sizeof(soap->z_buf));
  }
  copy->z_dict = soap->z_dict;
  copy->z_dict_len = soap->z_dict_len;
#endif
  memcpy(copy->buf, soap->buf, sizeof(soap->buf));
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
void
SOAP_FMAC2
soap_free_stream(struct soap *soap)
{ soap->socket = SOAP_INVALID_SOCKET;
#ifdef WITH_OPENSSL
  soap->bio = NULL;
  soap->ssl = NULL;
#endif
#ifdef WITH_GNUTLS
  soap->xcred = NULL;
  soap->acred = NULL;
  soap->cache = NULL;
  soap->session = NULL; /* TODO: GNUTLS free (when dupped)? */
  soap->dh_params = NULL;
  soap->rsa_params = NULL;
#endif
#ifdef WITH_ZLIB
  if (soap->d_stream)
    SOAP_FREE(soap, soap->d_stream);
  soap->d_stream = NULL;
  if (soap->z_buf)
    SOAP_FREE(soap, soap->z_buf);
  soap->z_buf = NULL;
#endif
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
void
SOAP_FMAC2
soap_init(struct soap *soap)
{ soap->state = SOAP_INIT;
#ifdef SOAP_MEM_DEBUG
  soap_init_mht(soap);
#endif
#if !defined(WITH_LEAN) || defined(SOAP_DEBUG)
  soap_init_logs(soap);
#endif
#ifdef SOAP_DEBUG
  soap_set_test_logfile(soap, "TEST.log");
  soap_set_sent_logfile(soap, "SENT.log");
  soap_set_recv_logfile(soap, "RECV.log");
#endif
  soap->version = 0;
  soap_imode(soap, SOAP_IO_DEFAULT);
  soap_omode(soap, SOAP_IO_DEFAULT);
  soap->plugins = NULL;
  soap->user = NULL;
  soap->userid = NULL;
  soap->passwd = NULL;
#ifndef WITH_NOHTTP
  soap->fpost = http_post;
  soap->fput = http_put;
  soap->fget = http_get;
  soap->fdel = http_405;
  soap->fopt = http_405;
  soap->fhead = http_405;
  soap->fform = NULL;
  soap->fposthdr = http_post_header;
  soap->fresponse = http_response;
  soap->fparse = http_parse;
  soap->fparsehdr = http_parse_header;
#endif
  soap->fheader = NULL;
  soap->fconnect = NULL;
  soap->fdisconnect = NULL;
#ifndef WITH_NOIO
  soap->ipv6_multicast_if = 0;
  soap->ipv4_multicast_if = NULL;
#ifndef WITH_IPV6
  soap->fresolve = tcp_gethost;
#else
  soap->fresolve = NULL;
#endif
  soap->faccept = tcp_accept;
  soap->fopen = tcp_connect;
  soap->fclose = tcp_disconnect;
  soap->fclosesocket = tcp_closesocket;
  soap->fshutdownsocket = tcp_shutdownsocket;
  soap->fsend = fsend;
  soap->frecv = frecv;
  soap->fpoll = soap_poll;
#else
  soap->fopen = NULL;
  soap->fclose = NULL;
  soap->fpoll = NULL;
#endif
  soap->fseterror = NULL;
  soap->fignore = NULL;
  soap->fserveloop = NULL;
  soap->fplugin = fplugin;
  soap->fmalloc = NULL;
#ifndef WITH_LEANER
  soap->fprepareinitsend = NULL;
  soap->fprepareinitrecv = NULL;
  soap->fpreparesend = NULL;
  soap->fpreparerecv = NULL;
  soap->fpreparefinalsend = NULL;
  soap->fpreparefinalrecv = NULL;
  soap->fdimereadopen = NULL;
  soap->fdimewriteopen = NULL;
  soap->fdimereadclose = NULL;
  soap->fdimewriteclose = NULL;
  soap->fdimeread = NULL;
  soap->fdimewrite = NULL;
  soap->fmimereadopen = NULL;
  soap->fmimewriteopen = NULL;
  soap->fmimereadclose = NULL;
  soap->fmimewriteclose = NULL;
  soap->fmimeread = NULL;
  soap->fmimewrite = NULL;
#endif
  soap->float_format = "%.9G"; /* Alternative: use "%G" */
  soap->double_format = "%.17lG"; /* Alternative: use "%lG" */
  soap->dime_id_format = "cid:id%d"; /* default DIME id format */
  soap->http_version = "1.1";
  soap->proxy_http_version = "1.0";
  soap->http_content = NULL;
  soap->actor = NULL;
  soap->lang = "en";
  soap->keep_alive = 0;
  soap->tcp_keep_alive = 0;
  soap->tcp_keep_idle = 0;
  soap->tcp_keep_intvl = 0;
  soap->tcp_keep_cnt = 0;
  soap->max_keep_alive = SOAP_MAXKEEPALIVE;
  soap->recv_timeout = 0;
  soap->send_timeout = 0;
  soap->connect_timeout = 0;
  soap->accept_timeout = 0;
  soap->socket_flags = 0;
  soap->connect_flags = 0;
  soap->bind_flags = 0;
  soap->accept_flags = 0;
  soap->linger_time = 0;
  soap->ip = 0;
  soap->labbuf = NULL;
  soap->lablen = 0;
  soap->labidx = 0;
  soap->encodingStyle = SOAP_STR_EOS;
#ifndef WITH_NONAMESPACES
  soap->namespaces = namespaces;
#else
  soap->namespaces = NULL;
#endif
  soap->local_namespaces = NULL;
  soap->nlist = NULL;
  soap->blist = NULL;
  soap->clist = NULL;
  soap->alist = NULL;
  soap->attributes = NULL;
  soap->header = NULL;
  soap->fault = NULL;
  soap->master = SOAP_INVALID_SOCKET;
  soap->socket = SOAP_INVALID_SOCKET;
  soap->os = NULL;
  soap->is = NULL;
#ifndef WITH_LEANER
  soap->dom = NULL;
  soap->dime.list = NULL;
  soap->dime.first = NULL;
  soap->dime.last = NULL;
  soap->mime.list = NULL;
  soap->mime.first = NULL;
  soap->mime.last = NULL;
  soap->mime.boundary = NULL;
  soap->mime.start = NULL;
  soap->xlist = NULL;
#endif
#ifndef UNDER_CE
  soap->recvfd = 0;
  soap->sendfd = 1;
#else
  soap->recvfd = stdin;
  soap->sendfd = stdout;
#endif 
  soap->host[0] = '\0';
  soap->port = 0;
  soap->action = NULL;
  soap->proxy_host = NULL;
  soap->proxy_port = 8080;
  soap->proxy_userid = NULL;
  soap->proxy_passwd = NULL;
  soap->authrealm = NULL;
  soap->prolog = NULL;
#ifdef WITH_ZLIB
  soap->zlib_state = SOAP_ZLIB_NONE;
  soap->zlib_in = SOAP_ZLIB_NONE;
  soap->zlib_out = SOAP_ZLIB_NONE;
  soap->d_stream = (z_stream*)SOAP_MALLOC(soap, sizeof(z_stream));
  soap->d_stream->zalloc = Z_NULL;
  soap->d_stream->zfree = Z_NULL;
  soap->d_stream->opaque = Z_NULL;
  soap->z_buf = NULL;
  soap->z_level = 6;
  soap->z_dict = NULL;
  soap->z_dict_len = 0;
#endif
#ifndef WITH_LEAN
  soap->wsuid = NULL;
  soap->c14nexclude = NULL;
  soap->cookies = NULL;
  soap->cookie_domain = NULL;
  soap->cookie_path = NULL;
  soap->cookie_max = 32;
#endif
#ifdef WMW_RPM_IO
  soap->rpmreqid = NULL;
#endif
#ifdef PALM
  palmNetLibOpen();
#endif
#ifndef WITH_NOIDREF
  soap_init_iht(soap);
  soap_init_pht(soap);
#endif
#ifdef WITH_OPENSSL
  if (!soap_ssl_init_done)
    soap_ssl_init();
  soap->fsslauth = ssl_auth_init;
  soap->fsslverify = ssl_verify_callback;
  soap->bio = NULL;
  soap->ssl = NULL;
  soap->ctx = NULL;
  soap->session = NULL;
  soap->ssl_flags = SOAP_SSL_DEFAULT;
  soap->keyfile = NULL;
  soap->password = NULL;
  soap->cafile = NULL;
  soap->capath = NULL;
  soap->crlfile = NULL;
  soap->dhfile = NULL;
  soap->randfile = NULL;
#endif
#ifdef WITH_GNUTLS
  if (!soap_ssl_init_done)
    soap_ssl_init();
  soap->fsslauth = ssl_auth_init;
  soap->fsslverify = NULL;
  soap->xcred = NULL;
  soap->acred = NULL;
  soap->cache = NULL;
  soap->session = NULL;
  soap->ssl_flags = SOAP_SSL_DEFAULT;
  soap->keyfile = NULL;
  soap->password = NULL;
  soap->cafile = NULL;
  soap->capath = NULL;
  soap->crlfile = NULL;
  soap->dh_params = NULL;
  soap->rsa_params = NULL;
#endif
#ifdef WITH_C_LOCALE
  soap->c_locale = newlocale(LC_ALL_MASK, "C", NULL);
#else
  soap->c_locale = NULL;
#endif
  soap->buflen = 0;
  soap->bufidx = 0;
#ifndef WITH_LEANER
  soap->dime.chunksize = 0;
  soap->dime.buflen = 0;
#endif
  soap->null = 0;
  soap->position = 0;
  soap->encoding = 0;
  soap->mustUnderstand = 0;
  soap->ns = 0;
  soap->part = SOAP_END;
  soap->alloced = 0;
  soap->count = 0;
  soap->length = 0;
  soap->cdata = 0;
  soap->peeked = 0;
  soap->ahead = 0;
  soap->idnum = 0;
  soap->level = 0;
  soap->endpoint[0] = '\0';
  soap->error = SOAP_OK;
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
void
SOAP_FMAC2
soap_init1(struct soap *soap, soap_mode mode)
{ soap_init2(soap, mode, mode);
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
void
SOAP_FMAC2
soap_init2(struct soap *soap, soap_mode imode, soap_mode omode)
{ soap_init(soap);
  soap_imode(soap, imode);
  soap_omode(soap, omode);
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
void
SOAP_FMAC2
soap_begin(struct soap *soap)
{ DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Reinitializing context\n"));
  if (!soap->keep_alive)
  { soap->buflen = 0;
    soap->bufidx = 0;
  }
  soap->keep_alive = (((soap->imode | soap->omode) & SOAP_IO_KEEPALIVE) != 0);
  soap->null = 0;
  soap->position = 0;
  soap->encoding = 0;
  soap->mustUnderstand = 0;
  soap->mode = 0;
  soap->ns = 0;
  soap->part = SOAP_END;
  soap->alloced = 0;
  soap->count = 0;
  soap->length = 0;
  soap->cdata = 0;
  soap->error = SOAP_OK;
  soap->peeked = 0;
  soap->ahead = 0;
  soap->idnum = 0;
  soap->level = 0;
  soap->endpoint[0] = '\0';
#ifndef WITH_LEANER
  soap->dime.chunksize = 0;
  soap->dime.buflen = 0;
#endif
  soap_free_temp(soap);
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
void
SOAP_FMAC2
soap_end(struct soap *soap)
{ if (soap_check_state(soap))
    return;
  soap_free_temp(soap);
  soap_dealloc(soap, NULL);
  while (soap->clist)
  { register struct soap_clist *cp = soap->clist->next;
    SOAP_FREE(soap, soap->clist);
    soap->clist = cp;
  }
  soap_closesock(soap);
#ifdef SOAP_DEBUG
  soap_close_logfiles(soap);
#endif
#ifdef PALM
  palmNetLibClose();
#endif
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_set_namespaces(struct soap *soap, const struct Namespace *p)
{ register struct Namespace *ns = soap->local_namespaces;
  register struct soap_nlist *np, *nq, *nr;
  register unsigned int level = soap->level;
  soap->namespaces = p;
  soap->local_namespaces = NULL;
  soap_set_local_namespaces(soap);
  /* reverse the namespace list */
  np = soap->nlist;
  soap->nlist = NULL;
  if (np)
  { nq = np->next;
    np->next = NULL;
    while (nq)
    { nr = nq->next;
      nq->next = np;
      np = nq;
      nq = nr;
    }
  }
  /* then push on new stack */
  while (np)
  { register const char *s;
    soap->level = np->level; /* preserve element nesting level */
    s = np->ns;
    if (!s && np->index >= 0 && ns)
    { s = ns[np->index].out;
      if (!s)
        s = ns[np->index].ns;
    }
    if (s && soap_push_namespace(soap, np->id, s) == NULL)
      return soap->error;
    nq = np;
    np = np->next;
    SOAP_FREE(soap, nq);
  }
  if (ns)
  { register int i;
    for (i = 0; ns[i].id; i++)
    { if (ns[i].out)
      { SOAP_FREE(soap, ns[i].out);
        ns[i].out = NULL;
      }
    }
    SOAP_FREE(soap, ns);
  }
  soap->level = level; /* restore level */
  return SOAP_OK;
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
void
SOAP_FMAC2
soap_set_local_namespaces(struct soap *soap)
{ if (soap->namespaces && !soap->local_namespaces)
  { register const struct Namespace *ns1;
    register struct Namespace *ns2;
    register size_t n = 1;
    for (ns1 = soap->namespaces; ns1->id; ns1++)
      n++;
    n *= sizeof(struct Namespace);
    ns2 = (struct Namespace*)SOAP_MALLOC(soap, n);
    if (ns2)
    { memcpy(ns2, soap->namespaces, n);
      if (ns2[0].ns)
      { if (!strcmp(ns2[0].ns, soap_env1))
          soap->version = 1;
        else
          soap->version = 2;
      }
      soap->local_namespaces = ns2;
    }
  }
}
#endif

/******************************************************************************/
#ifndef WITH_LEAN
#ifndef PALM_1
SOAP_FMAC1
const char *
SOAP_FMAC2
soap_tagsearch(const char *big, const char *little)
{ if (little)
  { register size_t n = strlen(little);
    register const char *s = big;
    while (s) 
    { register const char *t = s;
      register size_t i;
      for (i = 0; i < n; i++, t++)
      { if (*t != little[i])
          break;
      }
      if (*t == '\0' || *t == ' ')
      { if (i == n || (i && little[i-1] == ':'))
          return s;
      }
      s = strchr(t, ' ');
      if (s)
        s++;
    }
  }
  return NULL;
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_LEAN
#ifndef PALM_1
SOAP_FMAC1
struct soap_nlist *
SOAP_FMAC2
soap_lookup_ns(struct soap *soap, const char *tag, size_t n)
{ register struct soap_nlist *np;
  for (np = soap->nlist; np; np = np->next)
  { if (!strncmp(np->id, tag, n) && !np->id[n])
      return np;
  }
  return NULL;
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_LEAN
static struct soap_nlist *
soap_push_ns(struct soap *soap, const char *id, const char *ns, short utilized)
{ register struct soap_nlist *np;
  size_t n, k;
  if (soap_tagsearch(soap->c14nexclude, id))
    return NULL;
  if (!utilized)
  { for (np = soap->nlist; np; np = np->next)
    { if (!strcmp(np->id, id) && (!np->ns || !strcmp(np->ns, ns)))
        break;
    }
    if (np)
    { if ((np->level < soap->level || !np->ns) && np->index == 1)
        utilized = 1;
      else
        return NULL;
    }
  }
  DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Adding namespace binding (level=%u) '%s' '%s' utilized=%d\n", soap->level, id, ns?ns:"(null)", utilized));
  n = strlen(id);
  if (ns)
    k = strlen(ns);
  else
    k = 0;
  np = (struct soap_nlist*)SOAP_MALLOC(soap, sizeof(struct soap_nlist) + n + k + 1);
  if (!np)
  { soap->error = SOAP_EOM;
    return NULL;
  }
  np->next = soap->nlist;
  soap->nlist = np;
  strcpy(np->id, id);
  if (ns)
    np->ns = strcpy(np->id + n + 1, ns);
  else
    np->ns = NULL;
  np->level = soap->level;
  np->index = utilized;
  return np;
}
#endif

/******************************************************************************/
#ifndef WITH_LEAN
static void
soap_utilize_ns(struct soap *soap, const char *tag, size_t n)
{ register struct soap_nlist *np = soap_lookup_ns(soap, tag, n);
  DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Utilizing namespace of '%s'\n", tag));
  if (np)
  { if (np->index == 0)
      soap_push_ns(soap, np->id, np->ns, 1);
  }
  else if (strncmp(tag, "xml", 3))
  { strncpy(soap->tmpbuf, tag, n);
    soap->tmpbuf[n] = '\0';
    soap_push_ns(soap, soap->tmpbuf, NULL, 1);
  }
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_element(struct soap *soap, const char *tag, int id, const char *type)
{
#ifndef WITH_LEAN
  register const char *s;
#endif
  DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Element begin tag='%s' id='%d' type='%s'\n", tag, id, type?type:SOAP_STR_EOS));
#ifdef WITH_DOM
#ifndef WITH_LEAN
  if (soap->wsuid && soap_tagsearch(soap->wsuid, tag))
  { size_t i;
    for (s = tag, i = 0; *s && i < sizeof(soap->tag); s++, i++)
      soap->tag[i] = *s == ':' ? '-' : *s;
    soap->tag[sizeof(soap->tag) - 1] = '\0';
    if (soap_set_attr(soap, "wsu:Id", soap->tag, 1))
      return soap->error;
  }
#endif 
  if (soap->part == SOAP_BEGIN_SECURITY && (soap->mode & SOAP_XML_CANONICAL) && !(soap->mode & SOAP_DOM_ASIS))
  { register struct soap_nlist *np;
    /* wsu:Id found: clear xmlns renderings, so re-emit them for exc-c14n */
    for (np = soap->nlist; np; np = np->next)
    { if (np->index == 2)
        np->index = 0;
    }
  }
  if (soap->mode & SOAP_XML_DOM)
  { register struct soap_dom_element *elt = (struct soap_dom_element*)soap_malloc(soap, sizeof(struct soap_dom_element));
    if (!elt)
      return soap->error;
    elt->soap = soap;
    elt->next = NULL;
    elt->prnt = soap->dom;
    elt->name = soap_strdup(soap, tag);
    elt->elts = NULL;
    elt->atts = NULL;
    elt->nstr = NULL;
    elt->data = NULL;
    elt->wide = NULL;
    elt->node = NULL;
    elt->type = 0;
    elt->head = NULL;
    elt->tail = NULL;
    if (soap->dom)
    { struct soap_dom_element *p = soap->dom->elts;
      if (p)
      { while (p->next)
          p = p->next;
        p->next = elt;
      }
      else
        soap->dom->elts = elt;
    }
    soap->dom = elt;
  }
  else
  {
#endif
    soap->level++;
#ifndef WITH_LEAN
    if (!soap->ns)
    { if (!(soap->mode & SOAP_XML_CANONICAL)
       && soap_send(soap, soap->prolog ? soap->prolog : "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"))
        return soap->error;
    }
    else if (soap->mode & SOAP_XML_INDENT)
    { if (soap->ns == 1 && soap_send_raw(soap, soap_indent, soap->level < sizeof(soap_indent) ? soap->level : sizeof(soap_indent) - 1))
        return soap->error;
      soap->body = 1;
    }
    if ((soap->mode & SOAP_XML_DEFAULTNS) && (s = strchr(tag, ':')))
    { struct Namespace *ns = soap->local_namespaces;
      size_t n = s - tag;
      if (soap_send_raw(soap, "<", 1)
       || soap_send(soap, s + 1))
        return soap->error;
      if (soap->nlist && !strncmp(soap->nlist->id, tag, n) && !soap->nlist->id[n])
        ns = NULL;
      for (; ns && ns->id; ns++)
      { if (*ns->id && (ns->out || ns->ns) && !strncmp(ns->id, tag, n) && !ns->id[n])
        { soap_push_ns(soap, ns->id, ns->out ? ns->out : ns->ns, 0);
          if (soap_attribute(soap, "xmlns", ns->out ? ns->out : ns->ns))
            return soap->error;
          break;
        }
      }   
    }
    else
#endif
    if (soap_send_raw(soap, "<", 1)
     || soap_send(soap, tag))
      return soap->error;
#ifdef WITH_DOM
  }
#endif
  if (!soap->ns)
  { struct Namespace *ns;
    int k = -1;
#ifndef WITH_LEAN
    if ((soap->mode & SOAP_XML_DEFAULTNS))
      k = 4; /* only produce the first four required entries */
#endif
    for (ns = soap->local_namespaces; ns && ns->id && k; ns++, k--)
    { if (*ns->id && (ns->out || ns->ns))
      { sprintf(soap->tmpbuf, "xmlns:%s", ns->id);
        if (soap_attribute(soap, soap->tmpbuf, ns->out ? ns->out : ns->ns))
          return soap->error;
      }
    }   
  }
  soap->ns = 1; /* namespace table control: ns = 0 or 2 to start, then 1 to stop dumping the table  */
#ifndef WITH_LEAN
  if (soap->mode & SOAP_XML_CANONICAL)
  { const char *t = strchr(tag, ':');
    if (t)
      soap_utilize_ns(soap, tag, t - tag);
  }
#endif
  if (id > 0)
  { sprintf(soap->tmpbuf, "_%d", id);
    if (soap_attribute(soap, "id", soap->tmpbuf))
      return soap->error;
  }
  if (type && *type && (!(soap->mode & SOAP_XML_SEC) || soap->part == SOAP_IN_BODY))
  { if (soap_attribute(soap, "xsi:type", type))
      return soap->error;
#ifndef WITH_LEAN
    if (soap->mode & SOAP_XML_CANONICAL)
    { const char *t = strchr(type, ':');
      if (t)
        soap_utilize_ns(soap, type, t - type);
    }
#endif
  }
  if (soap->null && soap->position > 0)
  { register int i;
    sprintf(soap->tmpbuf, "[%d", soap->positions[0]);
    for (i = 1; i < soap->position; i++)
      sprintf(soap->tmpbuf + strlen(soap->tmpbuf), ",%d", soap->positions[i]);
    strcat(soap->tmpbuf, "]");
    if (soap_attribute(soap, "SOAP-ENC:position", soap->tmpbuf))
      return soap->error;
  }
  if (soap->mustUnderstand)
  { if (soap->actor && *soap->actor)
    { if (soap_attribute(soap, soap->version == 2 ? "SOAP-ENV:role" : "SOAP-ENV:actor", soap->actor))
        return soap->error;
    }
    if (soap_attribute(soap, "SOAP-ENV:mustUnderstand", soap->version == 2 ? "true" : "1"))
      return soap->error;
    soap->mustUnderstand = 0;
  }
  if (soap->encoding)
  { if (soap->encodingStyle && soap->local_namespaces)
    { if (!*soap->encodingStyle)
      { if (soap->local_namespaces[1].out)
          soap->encodingStyle = soap->local_namespaces[1].out;
        else
          soap->encodingStyle = soap->local_namespaces[1].ns;
      }
      if (soap->encodingStyle && soap_attribute(soap, "SOAP-ENV:encodingStyle", soap->encodingStyle))
        return soap->error;
    }
    soap->encoding = 0;
  }
  soap->null = 0;
  soap->position = 0;
  if (soap->part == SOAP_BEGIN_SECURITY && (soap->mode & SOAP_XML_CANONICAL))
    soap->part = SOAP_IN_SECURITY;
  return SOAP_OK;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_element_begin_out(struct soap *soap, const char *tag, int id, const char *type)
{ if (*tag == '-')
    return SOAP_OK;
  if (soap_element(soap, tag, id, type))
    return soap->error;
  return soap_element_start_end_out(soap, NULL);
}
#endif

/******************************************************************************/
#ifndef PALM_2
#ifndef HAVE_STRRCHR
SOAP_FMAC1
char*
SOAP_FMAC2
soap_strrchr(const char *s, int t)
{ register char *r = NULL;
  while (*s)
    if (*s++ == t)
      r = (char*)s - 1;
  return r;
}
#endif
#endif

/******************************************************************************/
#ifndef PALM_2
#ifndef HAVE_STRTOL
SOAP_FMAC1
long
SOAP_FMAC2
soap_strtol(const char *s, char **t, int b)
{ register long n = 0;
  register int c;
  while (*s > 0 && *s <= 32)
    s++;
  if (b == 10)
  { short neg = 0;
    if (*s == '-')
    { s++;
      neg = 1;
    }
    else if (*s == '+')
      s++;
    while ((c = *s) && c >= '0' && c <= '9')
    { if (n >= 214748364 && (n > 214748364 || c >= '8'))
        break;
      n *= 10;
      n += c - '0';
      s++;
    }
    if (neg)
      n = -n;
  }
  else /* assume b == 16 and value is always positive */
  { while ((c = *s))
    { if (c >= '0' && c <= '9')
        c -= '0';
      else if (c >= 'A' && c <= 'F')
        c -= 'A' - 10;
      else if (c >= 'a' && c <= 'f')
        c -= 'a' - 10;
      if (n > 0x07FFFFFF)
        break;
      n <<= 4;
      n += c;
      s++;
    }
  }
  if (t)
    *t = (char*)s;
  return n;
}
#endif
#endif

/******************************************************************************/
#ifndef PALM_2
#ifndef HAVE_STRTOUL
SOAP_FMAC1
unsigned long
SOAP_FMAC2
soap_strtoul(const char *s, char **t, int b)
{ unsigned long n = 0;
  register int c;
  while (*s > 0 && *s <= 32)
    s++;
  if (b == 10)
  { if (*s == '+')
      s++;
    while ((c = *s) && c >= '0' && c <= '9')
    { if (n >= 429496729 && (n > 429496729 || c >= '6'))
        break;
      n *= 10;
      n += c - '0';
      s++;
    }
  }
  else /* b == 16 */
  { while ((c = *s))
    { if (c >= '0' && c <= '9')
        c -= '0';
      else if (c >= 'A' && c <= 'F')
        c -= 'A' - 10;
      else if (c >= 'a' && c <= 'f')
        c -= 'a' - 10;
      if (n > 0x0FFFFFFF)
        break;
      n <<= 4;
      n += c;
      s++;
    }
  }
  if (t)
    *t = (char*)s;
  return n;
}
#endif
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_array_begin_out(struct soap *soap, const char *tag, int id, const char *type, const char *offset)
{ if (!type || !*type)
    return soap_element_begin_out(soap, tag, id, NULL);
  if (soap_element(soap, tag, id, "SOAP-ENC:Array"))
    return soap->error;
  if (soap->version == 2)
  { const char *s;
    s = soap_strrchr(type, '[');
    if ((size_t)(s - type) < sizeof(soap->tmpbuf))
    { strncpy(soap->tmpbuf, type, s - type);
      soap->tmpbuf[s - type] = '\0';
      if (soap_attribute(soap, "SOAP-ENC:itemType", soap->tmpbuf))
        return soap->error;
      if (s && (soap_attribute(soap, "SOAP-ENC:arraySize", s + 1)))
        return soap->error;
    }
  }
  else
  { if (offset && soap_attribute(soap, "SOAP-ENC:offset", offset))
      return soap->error;
    if (soap_attribute(soap, "SOAP-ENC:arrayType", type))
      return soap->error;
  }
#ifndef WITH_LEAN
  if ((soap->mode & SOAP_XML_CANONICAL))
  { const char *s = strchr(type, ':');
    if (s)
      soap_utilize_ns(soap, type, s - type);
  }
#endif
  return soap_element_start_end_out(soap, NULL);
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_element_start_end_out(struct soap *soap, const char *tag)
{ register struct soap_attribute *tp;
#ifndef WITH_LEAN
  if (soap->mode & SOAP_XML_CANONICAL)
  { struct soap_nlist *np;
    for (tp = soap->attributes; tp; tp = tp->next)
    { if (tp->visible && tp->name)
      { const char *s = strchr(tp->name, ':');
        if (s)
          soap_utilize_ns(soap, tp->name, s - tp->name);
      }
    }
    for (np = soap->nlist; np; np = np->next)
    { if (np->index == 1 && np->ns)
      { sprintf(soap->tmpbuf, "xmlns:%s", np->id);
        DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Enabling utilized binding (level=%u) %s='%s'\n", np->level, soap->tmpbuf, np->ns));
        soap_set_attr(soap, soap->tmpbuf, np->ns, 1);
        np->index = 2;
      }
    }
  }
#endif
#ifdef WITH_DOM
  if ((soap->mode & SOAP_XML_DOM) && soap->dom)
  { register struct soap_dom_attribute **att;
    att = &soap->dom->atts;
    for (tp = soap->attributes; tp; tp = tp->next)
    { if (tp->visible)
      { *att = (struct soap_dom_attribute*)soap_malloc(soap, sizeof(struct soap_dom_attribute));
        if (!*att)
          return soap->error;
        (*att)->next = NULL;
        (*att)->nstr = NULL;
        (*att)->name = soap_strdup(soap, tp->name);
        (*att)->data = soap_strdup(soap, tp->value);
        (*att)->wide = NULL;
        (*att)->soap = soap;
        att = &(*att)->next;
        tp->visible = 0;
      }
    }
    return SOAP_OK;
  }
#endif
  for (tp = soap->attributes; tp; tp = tp->next)
  { if (tp->visible)
    {
#ifndef WITH_LEAN
      const char *s;
      if ((soap->mode & SOAP_XML_DEFAULTNS) && (s = strchr(tp->name, ':')))
      { size_t n = s - tp->name;
        if (soap->nlist && !strncmp(soap->nlist->id, tp->name, n) && !soap->nlist->id[n])
          s++;
        else
          s = tp->name;
        if (soap_send(soap, " ") || soap_send(soap, s))
          return soap->error;
      }
      else
#endif
      if (soap_send(soap, " ") || soap_send(soap, tp->name))
        return soap->error;
      if (tp->visible == 2 && tp->value)
        if (soap_send_raw(soap, "=\"", 2)
         || soap_string_out(soap, tp->value, tp->flag)
         || soap_send_raw(soap, "\"", 1))
          return soap->error;
      tp->visible = 0;
    }
  }
  if (tag)
  { 
#ifndef WITH_LEAN
    if (soap->mode & SOAP_XML_CANONICAL)
    { if (soap_send_raw(soap, ">", 1)
       || soap_element_end_out(soap, tag))
        return soap->error;
      return SOAP_OK;
    }
#endif
    soap->level--;	/* decrement level just before /> */
    return soap_send_raw(soap, "/>", 2);
  }
  return soap_send_raw(soap, ">", 1);
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_element_end_out(struct soap *soap, const char *tag)
{
#ifndef WITH_LEAN
  const char *s;
#endif
  if (*tag == '-')
    return SOAP_OK;
  DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Element ending tag='%s'\n", tag));
#ifdef WITH_DOM
  if ((soap->mode & SOAP_XML_DOM) && soap->dom)
  { if (soap->dom->prnt)
      soap->dom = soap->dom->prnt;
    return SOAP_OK;
  }
#endif
#ifndef WITH_LEAN
  if (soap->mode & SOAP_XML_CANONICAL)
    soap_pop_namespace(soap);
  if (soap->mode & SOAP_XML_INDENT)
  { if (!soap->body)
    { if (soap_send_raw(soap, soap_indent, soap->level < sizeof(soap_indent) ? soap->level : sizeof(soap_indent) - 1))
        return soap->error;
    }
    soap->body = 0;
  }
  if ((soap->mode & SOAP_XML_DEFAULTNS) && (s = strchr(tag, ':')))
  { soap_pop_namespace(soap);
    tag = s + 1;
  }
#endif
  if (soap_send_raw(soap, "</", 2)
   || soap_send(soap, tag))
    return soap->error;
  soap->level--;	/* decrement level just before > */
  return soap_send_raw(soap, ">", 1);
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_element_ref(struct soap *soap, const char *tag, int id, int href)
{ register int n = 0;
  const char *s = "href";
  if (soap->version == 2)
  { s = "SOAP-ENC:ref";
    n = 1;
  }
  sprintf(soap->href, "#_%d", href);
  return soap_element_href(soap, tag, id, s, soap->href + n);
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_element_href(struct soap *soap, const char *tag, int id, const char *ref, const char *val)
{ DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Element '%s' reference %s='%s'\n", tag, ref, val));
  if (soap_element(soap, tag, id, NULL)
   || soap_attribute(soap, ref, val)
   || soap_element_start_end_out(soap, tag))
    return soap->error;
  return SOAP_OK;
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_element_null(struct soap *soap, const char *tag, int id, const char *type)
{ struct soap_attribute *tp = NULL;
  for (tp = soap->attributes; tp; tp = tp->next)
    if (tp->visible)
      break;
  if (tp || (soap->version == 2 && soap->position > 0) || id > 0 || (soap->mode & SOAP_XML_NIL))
  { if (soap_element(soap, tag, id, type)
     || (!tp && soap_attribute(soap, "xsi:nil", "true")))
      return soap->error;
    return soap_element_start_end_out(soap, tag);
  }
  soap->null = 1;
  soap->position = 0;
  soap->mustUnderstand = 0;
  return SOAP_OK;
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_element_nil(struct soap *soap, const char *tag)
{ if (soap_element(soap, tag, -1, NULL)
   || soap_attribute(soap, "xsi:nil", "true"))
    return soap->error;
  return soap_element_start_end_out(soap, tag);
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_element_id(struct soap *soap, const char *tag, int id, const void *p, const struct soap_array *a, int n, const char *type, int t) 
{ if (!p)
  { soap_element_null(soap, tag, id, type);
    return -1;
  }
#ifndef WITH_NOIDREF
  if (soap->mode & SOAP_XML_TREE)
    return 0;
  if (id < 0)
  { struct soap_plist *pp;
    if (a)
      id = soap_array_pointer_lookup(soap, p, a, n, t, &pp);
    else
      id = soap_pointer_lookup(soap, p, t, &pp);
    if (id)
    { if (soap_is_embedded(soap, pp))
      { soap_element_ref(soap, tag, 0, id);
        return -1;
      }
      if (soap_is_single(soap, pp))
        return 0;
      soap_set_embedded(soap, pp);
    }
  }
  return id;
#else
  return 0;
#endif
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_element_result(struct soap *soap, const char *tag)
{ if (soap->version == 2 && soap->encodingStyle)
  { if (soap_element(soap, "SOAP-RPC:result", 0, NULL)
     || soap_attribute(soap, "xmlns:SOAP-RPC", soap_rpc)
     || soap_element_start_end_out(soap, NULL)
     || soap_string_out(soap, tag, 0)
     || soap_element_end_out(soap, "SOAP-RPC:result"))
      return soap->error;
  }
  return SOAP_OK;
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
void
SOAP_FMAC2
soap_check_result(struct soap *soap, const char *tag)
{ if (soap->version == 2 && soap->encodingStyle)
  { soap_instring(soap, ":result", NULL, NULL, 0, 2, -1, -1);
    /* just ignore content for compliance reasons, but should compare tag to element's QName value? */
  }
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_attribute(struct soap *soap, const char *name, const char *value)
{ 
  DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Attribute '%s'='%s'\n", name, value));
#ifdef WITH_DOM
  if ((soap->mode & SOAP_XML_DOM) && !(soap->mode & SOAP_XML_CANONICAL) && soap->dom)
  { register struct soap_dom_attribute *a = (struct soap_dom_attribute*)soap_malloc(soap, sizeof(struct soap_dom_attribute));
    if (!a)
      return soap->error;
    a->next = soap->dom->atts;
    a->nstr = NULL;
    a->name = soap_strdup(soap, name);
    a->data = soap_strdup(soap, value);
    a->wide = NULL;
    a->soap = soap;
    soap->dom->atts = a;
    return SOAP_OK;
  }
#endif
#ifndef WITH_LEAN
  if (soap->mode & SOAP_XML_CANONICAL)
  { /* TODO: consider using this code to handle default namespace bindings
    if (!strncmp(name, "xmlns", 5) && (name[5] == ':' || name[5] == '\0'))
    { if (name[5] == ':')
        soap_push_ns(soap, name + 6, value, 0);
      else
        soap_push_ns(soap, "", value, 0);
    }
    */
    if (!strncmp(name, "xmlns:", 6))
      soap_push_ns(soap, name + 6, value, 0);
    else if (soap_set_attr(soap, name, value, 1))
      return soap->error;
  }
  else
#endif
  { if (soap_send(soap, " ") || soap_send(soap, name))
      return soap->error;
    if (value)
      if (soap_send_raw(soap, "=\"", 2)
       || soap_string_out(soap, value, 1)
       || soap_send_raw(soap, "\"", 1))
        return soap->error;
  }
  return SOAP_OK;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_element_begin_in(struct soap *soap, const char *tag, int nillable, const char *type)
{ if (!soap_peek_element(soap))
  { if (soap->other)
      return soap->error = SOAP_TAG_MISMATCH;
    if (tag && *tag == '-')
      return SOAP_OK;
    if (!(soap->error = soap_match_tag(soap, soap->tag, tag)))
    { soap->peeked = 0;
      if (type && *soap->type && soap_match_tag(soap, soap->type, type))
        return soap->error = SOAP_TYPE;
      if (!nillable && soap->null && (soap->mode & SOAP_XML_STRICT))
        return soap->error = SOAP_NULL;
      if (soap->body)
        soap->level++;
      DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Begin element found (level=%u) '%s'='%s'\n", soap->level, soap->tag, tag?tag:SOAP_STR_EOS ));
    }
  }
  else if (soap->error == SOAP_NO_TAG && tag && *tag == '-')
    soap->error = SOAP_OK;
  return soap->error;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_element_end_in(struct soap *soap, const char *tag)  
{ register soap_wchar c;
  register char *s;
  register int n = 0;
  if (tag && *tag == '-')
    return SOAP_OK;
  if (soap->error == SOAP_NO_TAG)
    soap->error = SOAP_OK;
#ifdef WITH_DOM
  /* this whitespace or mixed content is significant for DOM */
  if ((soap->mode & SOAP_XML_DOM) && soap->dom)
  { if (!soap->peeked && !soap_string_in(soap, 3, -1, -1))
      return soap->error;
    if (soap->dom->prnt)
      soap->dom = soap->dom->prnt;
  }
#endif
  if (soap->peeked)
  { if (*soap->tag)
      n++;
    soap->peeked = 0;
  }
  do
  { while (((c = soap_get(soap)) != SOAP_TT))
    { if ((int)c == EOF)
        return soap->error = SOAP_EOF;
      if (c == SOAP_LT)
        n++;
      else if (c == '/')
      { c = soap_get(soap);
        if (c == SOAP_GT)
          n--;
        else
          soap_unget(soap, c);
      }
    }
  } while (n--);
  s = soap->tag;
  n = sizeof(soap->tag);
  while (soap_notblank(c = soap_get(soap)))
  { if (--n > 0)
      *s++ = (char)c;
  }
  *s = '\0';
  if ((int)c == EOF)
    return soap->error = SOAP_EOF;
  while (soap_blank(c))
    c = soap_get(soap);
  if (c != SOAP_GT)
    return soap->error = SOAP_SYNTAX_ERROR;
  DBGLOG(TEST, SOAP_MESSAGE(fdebug, "End element found (level=%u) '%s'='%s'\n", soap->level, soap->tag, tag?tag:SOAP_STR_EOS));
#ifndef WITH_LEAN
  if (tag && (soap->mode & SOAP_XML_STRICT))
  { soap_pop_namespace(soap);
    if (soap_match_tag(soap, soap->tag, tag))
    { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "End element tag name does not match\n"));
      return soap->error = SOAP_SYNTAX_ERROR;
    }
  }
#endif
  soap->level--;
  return SOAP_OK;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
const char *
SOAP_FMAC2
soap_attr_value(struct soap *soap, const char *name, int flag)
{ register struct soap_attribute *tp;
  if (*name == '-')
    return SOAP_STR_EOS;
  for (tp = soap->attributes; tp; tp = tp->next)
  { if (tp->visible && !soap_match_tag(soap, tp->name, name))
      break;
  }
  if (tp)
  { if (flag == 2 && (soap->mode & SOAP_XML_STRICT))
      soap->error = SOAP_PROHIBITED;
    else
      return tp->value;
  }
  else if (flag == 1 && (soap->mode & SOAP_XML_STRICT))
    soap->error = SOAP_REQUIRED;
  else
    soap->error = SOAP_OK;
  return NULL;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_set_attr(struct soap *soap, const char *name, const char *value, int flag)
{ register struct soap_attribute *tp;
  if (*name == '-')
    return SOAP_OK;
  DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Set attribute %s='%s'\n", name, value?value:SOAP_STR_EOS));
  for (tp = soap->attributes; tp; tp = tp->next)
  { if (!strcmp(tp->name, name))
      break;
  }
  if (!tp)
  { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Allocate attribute %s\n", name));
    if (!(tp = (struct soap_attribute*)SOAP_MALLOC(soap, sizeof(struct soap_attribute) + strlen(name))))
      return soap->error = SOAP_EOM;
    tp->ns = NULL;
#ifndef WITH_LEAN
    if ((soap->mode & SOAP_XML_CANONICAL))
    { struct soap_attribute **tpp = &soap->attributes;
      const char *s = strchr(name, ':');
      DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Inserting attribute %s for c14n\n", name))
      if (!strncmp(name, "xmlns", 5))
      { for (; *tpp; tpp = &(*tpp)->next)
          if (strncmp((*tpp)->name, "xmlns", 5) || strcmp((*tpp)->name + 5, name + 5) > 0)
            break;
      }
      else if (!s)
      { for (; *tpp; tpp = &(*tpp)->next)
          if (strncmp((*tpp)->name, "xmlns", 5) && ((*tpp)->ns || strcmp((*tpp)->name, name) > 0))
            break;
      }
      else
      { int k;
        for (; *tpp; tpp = &(*tpp)->next)
        { if (!strncmp((*tpp)->name, "xmlns:", 6) && !strncmp((*tpp)->name + 6, name, s - name) && !(*tpp)->name[6 + s - name])
          { if (!tp->ns)
            { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Canonicalization: prefix %s=%p (%s)\n", name, (*tpp)->ns, (*tpp)->ns));
              tp->ns = (*tpp)->ns;
            }
          }
          else if (strncmp((*tpp)->name, "xmlns", 5) && (*tpp)->ns && tp->ns && ((k = strcmp((*tpp)->ns, tp->ns)) > 0 || (!k && strcmp((*tpp)->name, name) > 0)))
            break;
        }
      }
      tp->next = *tpp;
      *tpp = tp;
    }
    else
#endif
    { tp->next = soap->attributes;
      soap->attributes = tp;
    }
    strcpy(tp->name, name);
    tp->value = NULL;
  }
  else if (tp->visible)
  { return SOAP_OK;
  }
  else if (value && tp->value && tp->size <= strlen(value))
  { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Free attribute value of %s (free %p)\n", name, tp->value));
    SOAP_FREE(soap, tp->value);
    tp->value = NULL;
    tp->ns = NULL;
  }
  if (value)
  { if (!tp->value)
    { tp->size = strlen(value) + 1;
      if (!(tp->value = (char*)SOAP_MALLOC(soap, tp->size)))
        return soap->error = SOAP_EOM;
      DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Allocate attribute value for %s (%p)\n", tp->name, tp->value));
    }
    strcpy(tp->value, value);
    if (!strncmp(tp->name, "xmlns:", 6))
      tp->ns = tp->value;
    tp->visible = 2;
    tp->flag = flag;
#ifndef WITH_LEAN
    if (soap->part != SOAP_IN_SECURITY && !strcmp(name, "wsu:Id"))
    { soap->part = SOAP_BEGIN_SECURITY;
      strncpy(soap->id, value, sizeof(soap->id));
      soap->id[sizeof(soap->id)-1] = '\0';
    }
#endif
  }
  else
    tp->visible = 1;
  return SOAP_OK;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
void
SOAP_FMAC2
soap_clr_attr(struct soap *soap)
{ register struct soap_attribute *tp;
#ifndef WITH_LEAN
  if ((soap->mode & SOAP_XML_CANONICAL))
  { while (soap->attributes)
    { tp = soap->attributes->next;
      if (soap->attributes->value)
        SOAP_FREE(soap, soap->attributes->value);
      SOAP_FREE(soap, soap->attributes);
      soap->attributes = tp;
    }
  }
  else
#endif
  { for (tp = soap->attributes; tp; tp = tp->next)
      tp->visible = 0;
  }
}
#endif

/******************************************************************************/
#ifndef PALM_2
static int
soap_getattrval(struct soap *soap, char *s, size_t n, soap_wchar d)
{ register size_t i;
  for (i = 0; i < n; i++)
  { register soap_wchar c = soap_get(soap);
    switch (c)
    {
    case SOAP_TT:
      *s++ = '<';
      soap_unget(soap, '/');
      break;
    case SOAP_LT:
      *s++ = '<';
      break;
    case SOAP_GT:
      if (d == ' ')
      { soap_unget(soap, c);
        *s = '\0';
        return SOAP_OK;
      }
      *s++ = '>';
      break;
    case SOAP_QT:
      if (c == d)
      { *s = '\0';
        return SOAP_OK;
      }
      *s++ = '"';
      break;
    case SOAP_AP:
      if (c == d)
      { *s = '\0';
        return SOAP_OK;
      }
      *s++ = '\'';
      break;
    case '\t':
    case '\n':
    case '\r':
    case ' ':
    case '/':
      if (d == ' ')
      { soap_unget(soap, c);
        *s = '\0';
        return SOAP_OK;
      }
    default:
      if ((int)c == EOF)
        return soap->error = SOAP_EOF;
      *s++ = (char)c;
    }
  }
  return soap->error = SOAP_EOM;
}
#endif

/******************************************************************************/
#ifdef WITH_FAST
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_store_lab(struct soap *soap, const char *s, size_t n)
{ soap->labidx = 0;
  return soap_append_lab(soap, s, n);
}
#endif
#endif

/******************************************************************************/
#ifdef WITH_FAST
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_append_lab(struct soap *soap, const char *s, size_t n)
{ if (soap->labidx + n >= soap->lablen)
  { register char *t = soap->labbuf;
    DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Enlarging look-aside buffer to append data, old size=%lu", (unsigned long)soap->lablen));
    if (soap->lablen == 0)
      soap->lablen = SOAP_LABLEN;
    while (soap->labidx + n >= soap->lablen)
      soap->lablen <<= 1;
    DBGLOG(TEST, SOAP_MESSAGE(fdebug, ", new size=%lu\n", (unsigned long)soap->lablen));
    soap->labbuf = (char*)SOAP_MALLOC(soap, soap->lablen);
    if (!soap->labbuf)
    { if (t)
        SOAP_FREE(soap, t);
      return soap->error = SOAP_EOM;
    }
    if (t)
    { memcpy(soap->labbuf, t, soap->labidx);
      SOAP_FREE(soap, t);
    }
  }
  if (s)
  { memcpy(soap->labbuf + soap->labidx, s, n);
    soap->labidx += n;
  }
  return SOAP_OK;
}
#endif
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_peek_element(struct soap *soap)
{
#ifdef WITH_DOM
  register struct soap_dom_attribute **att = NULL;
  register char *lead = NULL;
#endif
  register struct soap_attribute *tp, *tq = NULL;
  register const char *t;
  register char *s;
  register soap_wchar c;
  register int i;
  if (soap->peeked)
  { if (!*soap->tag)
      return soap->error = SOAP_NO_TAG;
    return SOAP_OK;
  }
  soap->peeked = 1;
  soap->id[0] = '\0';
  soap->href[0] = '\0';
  soap->type[0] = '\0';
  soap->arrayType[0] = '\0';
  soap->arraySize[0] = '\0';
  soap->arrayOffset[0] = '\0';
  soap->other = 0;
  soap->root = -1;
  soap->position = 0;
  soap->null = 0;
  soap->mustUnderstand = 0;
  /* skip BOM */
  if ((c = soap_getchar(soap)) != 0xEF || (c = soap_get1(soap)) != 0xBB || (c = soap_get1(soap)) != 0xBF)
    soap_unget(soap, c);
  c = soap_get(soap);
#ifdef WITH_DOM
  /* whitespace leading to tag is not insignificant for DOM */
  if (soap_blank(c))
  { soap->labidx = 0;
    do
    { if (soap_append_lab(soap, NULL, 0))
        return soap->error;
      s = soap->labbuf + soap->labidx;
      i = soap->lablen - soap->labidx;
      soap->labidx = soap->lablen;
      while (soap_blank(c) && i--)
      { *s++ = c;
        c = soap_get(soap);
      }
    }
    while (soap_blank(c));
    *s = '\0';
    lead = soap->labbuf;
  }
#else
  /* skip space */
  while (soap_blank(c))
    c = soap_get(soap);
#endif
  if (c != SOAP_LT)
  { *soap->tag = '\0';
    if ((int)c == EOF)
      return soap->error = SOAP_EOF;
    soap_unget(soap, c);
#ifdef WITH_DOM
    /* whitespace leading to end tag is significant for DOM */
    if ((soap->mode & SOAP_XML_DOM) && soap->dom)
    { if (lead && *lead)
        soap->dom->tail = soap_strdup(soap, lead);
      else
        soap->dom->tail = (char*)SOAP_STR_EOS;
    }
#endif
    return soap->error = SOAP_NO_TAG;
  }
  s = soap->tag;
  do c = soap_get1(soap);
  while (soap_blank(c));
  i = sizeof(soap->tag);
  while (c != '>' && c != '/' && soap_notblank(c) && (int)c != EOF)
  { if (--i > 0)
      *s++ = (char)c;
    c = soap_get1(soap);
  }
  while (soap_blank(c))
    c = soap_get1(soap);
  *s = '\0';
#ifdef WITH_DOM
  if (soap->mode & SOAP_XML_DOM)
  { register struct soap_dom_element *elt;
    elt = (struct soap_dom_element*)soap_malloc(soap, sizeof(struct soap_dom_element));
    if (!elt)
      return soap->error;
    elt->next = NULL;
    elt->nstr = NULL;
    elt->name = soap_strdup(soap, soap->tag);
    elt->prnt = soap->dom;
    elt->elts = NULL;
    elt->atts = NULL;
    elt->data = NULL;
    elt->wide = NULL;
    elt->type = 0;
    elt->node = NULL;
    elt->head = soap_strdup(soap, lead);
    elt->tail = NULL;
    elt->soap = soap;
    if (soap->dom)
    { struct soap_dom_element *p = soap->dom->elts;
      if (p)
      { while (p->next)
          p = p->next;
        p->next = elt;
      }
      else
        soap->dom->elts = elt;
    }
    soap->dom = elt;
    att = &elt->atts;
  }
#endif
  soap_pop_namespace(soap);
  for (tp = soap->attributes; tp; tp = tp->next)
    tp->visible = 0;
  while ((int)c != EOF && c != '>' && c != '/')
  { s = soap->tmpbuf;
    i = sizeof(soap->tmpbuf);
    while (c != '=' && c != '>' && c != '/' && soap_notblank(c) && (int)c != EOF)
    { if (--i > 0)
        *s++ = (char)c;
      c = soap_get1(soap);
    }
    *s = '\0';
    if (i == sizeof(soap->tmpbuf))
      return soap->error = SOAP_SYNTAX_ERROR;
#ifdef WITH_DOM
    /* add attribute name to dom */
    if (att)
    { *att = (struct soap_dom_attribute*)soap_malloc(soap, sizeof(struct soap_dom_attribute));
       if (!*att)
         return soap->error;
       (*att)->next = NULL;
       (*att)->nstr = NULL;
       (*att)->name = soap_strdup(soap, soap->tmpbuf);
       (*att)->data = NULL;
       (*att)->wide = NULL;
       (*att)->soap = soap;
    }
#endif
    if (!strncmp(soap->tmpbuf, "xmlns", 5))
    { if (soap->tmpbuf[5] == ':')
        t = soap->tmpbuf + 6;
      else if (soap->tmpbuf[5])
        t = NULL;
      else
        t = SOAP_STR_EOS;
    }
    else
      t = NULL;
    tq = NULL;
    for (tp = soap->attributes; tp; tq = tp, tp = tp->next)
    { if (!SOAP_STRCMP(tp->name, soap->tmpbuf))
        break;
    }
    if (!tp)
    { tp = (struct soap_attribute*)SOAP_MALLOC(soap, sizeof(struct soap_attribute) + strlen(soap->tmpbuf));
      if (!tp)
        return soap->error = SOAP_EOM;
      strcpy(tp->name, soap->tmpbuf);
      tp->value = NULL;
      tp->size = 0;
      /* if attribute name is qualified, append it to the end of the list */
      if (tq && strchr(soap->tmpbuf, ':'))
      { tq->next = tp;
        tp->next = NULL;
      }
      else
      { tp->next = soap->attributes;
        soap->attributes = tp;
      }
    }
    while (soap_blank(c))
      c = soap_get1(soap);
    if (c == '=')
    { do c = soap_getutf8(soap);
      while (soap_blank(c));
      if (c != SOAP_QT && c != SOAP_AP)
      { soap_unget(soap, c);
        c = ' '; /* blank delimiter */
      }
      if (soap_getattrval(soap, tp->value, tp->size, c))
      {
#ifdef WITH_FAST
        if (soap->error != SOAP_EOM)
          return soap->error;
        soap->error = SOAP_OK;
        if (soap_store_lab(soap, tp->value, tp->size))
          return soap->error;
        if (tp->value)
          SOAP_FREE(soap, tp->value);
        for (;;)
        { if (soap_getattrval(soap, soap->labbuf + soap->labidx, soap->lablen - soap->labidx, c))
          { if (soap->error != SOAP_EOM)
              return soap->error;
            soap->error = SOAP_OK;
            soap->labidx = soap->lablen;
            if (soap_append_lab(soap, NULL, 0))
              return soap->error;
          }
          else
            break;
        }
        if (soap->labidx)
          tp->size = soap->lablen;
        else
        { tp->size = strlen(soap->labbuf) + 1;
          if (tp->size < SOAP_LABLEN)
            tp->size = SOAP_LABLEN;
        }
        if (!(tp->value = (char*)SOAP_MALLOC(soap, tp->size)))
          return soap->error = SOAP_EOM;
        strcpy(tp->value, soap->labbuf);
#else
        size_t n;
        if (soap->error != SOAP_EOM)
          return soap->error;
        soap->error = SOAP_OK;
        if (soap_new_block(soap) == NULL)
          return soap->error;
        for (;;)
        { if (!(s = (char*)soap_push_block(soap, NULL, SOAP_BLKLEN)))
            return soap->error;
          if (soap_getattrval(soap, s, SOAP_BLKLEN, c))
          { if (soap->error != SOAP_EOM)
              return soap->error;
            soap->error = SOAP_OK;
          }
          else
            break;
        }
        n = tp->size + soap->blist->size;
        if (!(s = (char*)SOAP_MALLOC(soap, n)))
          return soap->error = SOAP_EOM;
        if (tp->value)
        { memcpy(s, tp->value, tp->size);
          SOAP_FREE(soap, tp->value);
        }
        soap_save_block(soap, NULL, s + tp->size, 0);
        tp->value = s;
        tp->size = n;
#endif
      }
      do c = soap_get1(soap);
      while (soap_blank(c));
      tp->visible = 2; /* seen this attribute w/ value */
#ifdef WITH_DOM
      if (att)
        (*att)->data = soap_strdup(soap, tp->value);
#endif
    }
    else
      tp->visible = 1; /* seen this attribute w/o value */
#ifdef WITH_DOM
    if (att)
      att = &(*att)->next;
#endif
    if (t && tp->value)
    { if (soap_push_namespace(soap, t, tp->value) == NULL)
        return soap->error;
    }
  }
#ifdef WITH_DOM
  if (att)
  { soap->dom->nstr = soap_current_namespace(soap, soap->tag);
    for (att = &soap->dom->atts; *att; att = &(*att)->next)
      (*att)->nstr = soap_current_namespace(soap, (*att)->name);
  }
#endif
  if ((int)c == EOF)
    return soap->error = SOAP_EOF;
  if (!(soap->body = (c != '/')))
    do c = soap_get1(soap);
    while (soap_blank(c));
#ifdef WITH_DOM
  if (soap->mode & SOAP_XML_DOM)
  { if (!soap->body && soap->dom->prnt)
      soap->dom = soap->dom->prnt;
  }
#endif
  for (tp = soap->attributes; tp; tp = tp->next)
  { if (tp->visible && tp->value)
    { 
#ifndef WITH_NOIDREF
      if (!strcmp(tp->name, "id"))
      { if ((soap->version > 0 && !(soap->mode & SOAP_XML_TREE))
         || (soap->mode & SOAP_XML_GRAPH))
        { *soap->id = '#';
          strncpy(soap->id + 1, tp->value, sizeof(soap->id) - 2);
          soap->id[sizeof(soap->id)-1] = '\0';
        }
      }
      else if (!strcmp(tp->name, "href"))
      { if (soap->version == 1
         || (soap->mode & SOAP_XML_GRAPH)
         || (soap->mode & SOAP_ENC_MTOM)
         || (soap->mode & SOAP_ENC_DIME))
        { strncpy(soap->href, tp->value, sizeof(soap->href) - 1);
          soap->href[sizeof(soap->href)-1] = '\0';
        }
      }
      else
#endif
      if (!soap_match_tag(soap, tp->name, "xsi:type"))
      { strncpy(soap->type, tp->value, sizeof(soap->type) - 1);
        soap->type[sizeof(soap->type)-1] = '\0';
      }
      else if ((!soap_match_tag(soap, tp->name, "xsi:null")
             || !soap_match_tag(soap, tp->name, "xsi:nil"))
            && (!strcmp(tp->value, "1")
             || !strcmp(tp->value, "true")))
      { soap->null = 1;
      }
      else if (soap->version == 1)
      { if (!soap_match_tag(soap, tp->name, "SOAP-ENC:arrayType"))
        { s = soap_strrchr(tp->value, '[');
          if (s && (size_t)(s - tp->value) < sizeof(soap->arrayType))
          { strncpy(soap->arrayType, tp->value, s - tp->value);
            soap->arrayType[s - tp->value] = '\0';
            strncpy(soap->arraySize, s, sizeof(soap->arraySize) - 1);
          }
          else
            strncpy(soap->arrayType, tp->value, sizeof(soap->arrayType) - 1);
          soap->arraySize[sizeof(soap->arrayType)-1] = '\0';
          soap->arrayType[sizeof(soap->arrayType)-1] = '\0';
        }
        else if (!soap_match_tag(soap, tp->name, "SOAP-ENC:offset"))
          strncpy(soap->arrayOffset, tp->value, sizeof(soap->arrayOffset));
        else if (!soap_match_tag(soap, tp->name, "SOAP-ENC:position"))
          soap->position = soap_getposition(tp->value, soap->positions);
        else if (!soap_match_tag(soap, tp->name, "SOAP-ENC:root"))
          soap->root = ((!strcmp(tp->value, "1") || !strcmp(tp->value, "true")));
        else if (!soap_match_tag(soap, tp->name, "SOAP-ENV:mustUnderstand")
              && (!strcmp(tp->value, "1") || !strcmp(tp->value, "true")))
          soap->mustUnderstand = 1;
        else if (!soap_match_tag(soap, tp->name, "SOAP-ENV:actor"))
        { if ((!soap->actor || strcmp(soap->actor, tp->value))
           && strcmp(tp->value, "http://schemas.xmlsoap.org/soap/actor/next"))
            soap->other = 1;
        }
      }
      else if (soap->version == 2)
      {
#ifndef WITH_NOIDREF
        if (!strcmp(tp->name, "ref")
         || !soap_match_tag(soap, tp->name, "SOAP-ENC:ref"))
        { *soap->href = '#';
          strncpy(soap->href + 1, tp->value, sizeof(soap->href) - 2);
          soap->href[sizeof(soap->href)-1] = '\0';
        }
        else
#endif
	if (!soap_match_tag(soap, tp->name, "SOAP-ENC:itemType"))
          strncpy(soap->arrayType, tp->value, sizeof(soap->arrayType) - 1);
        else if (!soap_match_tag(soap, tp->name, "SOAP-ENC:arraySize"))
          strncpy(soap->arraySize, tp->value, sizeof(soap->arraySize) - 1);
        else if (!soap_match_tag(soap, tp->name, "SOAP-ENV:mustUnderstand")
              && (!strcmp(tp->value, "1") || !strcmp(tp->value, "true")))
          soap->mustUnderstand = 1;
        else if (!soap_match_tag(soap, tp->name, "SOAP-ENV:role"))
        { if ((!soap->actor || strcmp(soap->actor, tp->value))
           && strcmp(tp->value, "http://www.w3.org/2003/05/soap-envelope/role/next"))
            soap->other = 1;
        }
      }
      else
      { if (!soap_match_tag(soap, tp->name, "wsdl:required") && !strcmp(tp->value, "true"))
          soap->mustUnderstand = 1;
      }
    }
  }
  return soap->error = SOAP_OK;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
void
SOAP_FMAC2
soap_retry(struct soap *soap)
{ soap->error = SOAP_OK;
  soap_revert(soap);
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
void
SOAP_FMAC2
soap_revert(struct soap *soap)
{ if (!soap->peeked)
  { soap->peeked = 1;
    if (soap->body)
      soap->level--;
  }
  DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Reverting to last element '%s' (level=%u)\n", soap->tag, soap->level));
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_string_out(struct soap *soap, const char *s, int flag)
{ register const char *t;
  register soap_wchar c;
  register soap_wchar mask = (soap_wchar)0xFFFFFF80UL;
#ifdef WITH_DOM
  if ((soap->mode & SOAP_XML_DOM) && soap->dom)
  { soap->dom->data = soap_strdup(soap, s);
    return SOAP_OK;
  }
#endif
  if (flag == 2 || soap->mode & SOAP_C_UTFSTRING)
    mask = 0;
  t = s;
  while ((c = *t++))
  { switch (c)
    { 
    case 0x09:
      if (flag)
      { if (soap_send_raw(soap, s, t - s - 1) || soap_send_raw(soap, "&#x9;", 5))
          return soap->error;
        s = t;
      }
      break;
    case 0x0A:
      if (flag || !(soap->mode & SOAP_XML_CANONICAL))
      { if (soap_send_raw(soap, s, t - s - 1) || soap_send_raw(soap, "&#xA;", 5))
          return soap->error;
        s = t;
      }
      break;
    case 0x0D:
      if (soap_send_raw(soap, s, t - s - 1) || soap_send_raw(soap, "&#xD;", 5))
        return soap->error;
      s = t;
      break;
    case '&':
      if (soap_send_raw(soap, s, t - s - 1) || soap_send_raw(soap, "&amp;", 5))
        return soap->error;
      s = t;
      break;
    case '<':
      if (soap_send_raw(soap, s, t - s - 1) || soap_send_raw(soap, "&lt;", 4))
        return soap->error;
      s = t;
      break;
    case '>':
      if (!flag)
      { if (soap_send_raw(soap, s, t - s - 1) || soap_send_raw(soap, "&gt;", 4))
          return soap->error;
        s = t;
      }
      break;
    case '"':
      if (flag)
      { if (soap_send_raw(soap, s, t - s - 1) || soap_send_raw(soap, "&quot;", 6))
          return soap->error;
        s = t;
      }
      break;
    default:
#ifndef WITH_LEANER
#ifdef HAVE_MBTOWC
      if (soap->mode & SOAP_C_MBSTRING)
      { wchar_t wc;
        register int m = mbtowc(&wc, t - 1, MB_CUR_MAX);
        if (m > 0 && wc != c)
        { if (soap_send_raw(soap, s, t - s - 1) || soap_pututf8(soap, wc))
            return soap->error;
          s = t += m - 1;
          continue;
        }
      }
#endif
#endif
#ifndef WITH_NOSTRINGTOUTF8
      if ((c & mask) || !(c & 0xFFFFFFE0UL))
      { if (soap_send_raw(soap, s, t - s - 1) || soap_pututf8(soap, (unsigned char)c))
          return soap->error;
        s = t;
      }
#endif
    }
  }
  return soap_send_raw(soap, s, t - s - 1);
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
char *
SOAP_FMAC2
soap_string_in(struct soap *soap, int flag, long minlen, long maxlen)
{ register char *s;
  char *t = NULL;
  register size_t i;
  register long l = 0;
  register int n = 0, f = 0, m = 0;
  register soap_wchar c;
#if !defined(WITH_LEANER) && defined(HAVE_WCTOMB)
  char buf[MB_LEN_MAX > 8 ? MB_LEN_MAX : 8];
#else
  char buf[8];
#endif
  DBGLOG(TEST,SOAP_MESSAGE(fdebug, "Reading string content, flag=%d\n", flag));
  if (soap->peeked && *soap->tag)
  {
#ifndef WITH_LEAN
    struct soap_attribute *tp;
    DBGLOG(TEST,SOAP_MESSAGE(fdebug, "String content includes tag '%s' and attributes\n", soap->tag));
    t = soap->tmpbuf;
    *t = '<';
    t[sizeof(soap->tmpbuf)-1] = '\0';
    strncpy(t + 1, soap->tag, sizeof(soap->tmpbuf) - 2);
    t += strlen(t);
    for (tp = soap->attributes; tp; tp = tp->next)
    { if (tp->visible)
      { if (t >= soap->tmpbuf + sizeof(soap->tmpbuf) - 2)
          break;
        *t++ = ' ';
        strcpy(t, tp->name);
        t += strlen(t);
        if (t >= soap->tmpbuf + sizeof(soap->tmpbuf) - 2)
          break; /* too many or large attribute values */
        if (tp->value)
        { *t++ = '=';
          *t++ = '"';
          strcpy(t, tp->value);
          t += strlen(t);
          *t++ = '"';
        }
      }
    }
    if (!soap->body)
      *t++ = '/';
    *t++ = '>';
    *t = '\0';
    t = soap->tmpbuf;
    m = (int)strlen(soap->tmpbuf);
#endif
    if (soap->body)
      n = 1;
    f = 1;
    soap->peeked = 0;
  }
#ifdef WITH_CDATA
  if (!flag)
  { register int state = 0;
#ifdef WITH_FAST
    soap->labidx = 0;			/* use look-aside buffer */
#else
    if (soap_new_block(soap) == NULL)
      return NULL;
#endif
    for (;;)
    { 
#ifdef WITH_FAST
      register size_t k;
      if (soap_append_lab(soap, NULL, 0))	/* allocate more space in look-aside buffer if necessary */
        return NULL;
      s = soap->labbuf + soap->labidx;	/* space to populate */
      k = soap->lablen - soap->labidx;	/* number of bytes available */
      soap->labidx = soap->lablen;	/* claim this space */
#else
      register size_t k = SOAP_BLKLEN;
      if (!(s = (char*)soap_push_block(soap, NULL, k)))
        return NULL;
#endif
      for (i = 0; i < k; i++)
      { if (m > 0)
        { *s++ = *t++;	/* copy multibyte characters */
          m--;
          continue;
        }
        c = soap_getchar(soap);
        if ((int)c == EOF)
          goto end;
        if (c >= 0x80 && state != 1 && !(soap->mode & SOAP_ENC_LATIN))
        { soap_unget(soap, c);
          c = soap_getutf8(soap);
          if (soap->mode & SOAP_C_UTFSTRING)
          { c &= 0x7FFFFFFF;
            t = buf;
            if (c < 0x0800)
              *t++ = (char)(0xC0 | ((c >> 6) & 0x1F));
            else
            { if (c < 0x010000)
                *t++ = (char)(0xE0 | ((c >> 12) & 0x0F));
              else
              { if (c < 0x200000)
                  *t++ = (char)(0xF0 | ((c >> 18) & 0x07));
                else
                { if (c < 0x04000000)
                    *t++ = (char)(0xF8 | ((c >> 24) & 0x03));
                  else
                  { *t++ = (char)(0xFC | ((c >> 30) & 0x01));
                    *t++ = (char)(0x80 | ((c >> 24) & 0x3F));
                  }
                  *t++ = (char)(0x80 | ((c >> 18) & 0x3F));
                }     
                *t++ = (char)(0x80 | ((c >> 12) & 0x3F));
              }
              *t++ = (char)(0x80 | ((c >> 6) & 0x3F));
            }
            *t++ = (char)(0x80 | (c & 0x3F));
            m = (int)(t - buf) - 1;
            t = buf;
            *s++ = *t++;
            continue;
          }
        }
        switch (state)
        { case 1:
            if (c == ']')
              state = 4;
            *s++ = c;
            continue;
          case 2:
            if (c == '-')
              state = 6;
            *s++ = c;
            continue;
          case 3:
            if (c == '?')
              state = 8;
            *s++ = c;
            continue;
          /* CDATA */
          case 4:
            if (c == ']')
              state = 5;
            else
              state = 1;
            *s++ = c;
            continue;
          case 5:
            if (c == '>')
              state = 0;
            else
              state = 1;
            *s++ = c;
            continue;
          /* comment */
          case 6:
            if (c == '-')
              state = 7;
            else
              state = 2;
            *s++ = c;
            continue;
          case 7:
            if (c == '>')
              state = 0;
            else
              state = 2;
            *s++ = c;
            continue;
          /* PI */
          case 8:
            if (c == '>')
              state = 0;
            else
              state = 3;
            *s++ = c;
            continue;
        }
        switch (c)
        {
        case SOAP_TT:
          if (n == 0)
            goto end;
          n--;
          *s++ = '<';
          t = (char*)"/";
          m = 1;
          break;
        case SOAP_LT:
	  if (f && n == 0)
	    goto end;
          n++;
          *s++ = '<';
          break;
        case '/':
          if (n > 0)
          { c = soap_getchar(soap);
            if (c == '>')
              n--;
            soap_unget(soap, c);
          }
          *s++ = '/';
          break;
        case '<':
          c = soap_getchar(soap);
          if (c == '/')
          { if (n == 0)
            { c = SOAP_TT;
              goto end;
            }
            n--;
          }
          else if (c == '!')
          { c = soap_getchar(soap);
            if (c == '[')
            { do c = soap_getchar(soap);
              while ((int)c != EOF && c != '[');
              if ((int)c == EOF)
                 goto end;
              t = (char*)"![CDATA[";
              m = 8;
              state = 1;
            }
            else if (c == '-')
            { if ((c = soap_getchar(soap)) == '-')
                state = 2;
              t = (char*)"!-";
              m = 2;
              soap_unget(soap, c);
            }
            else
            { t = (char*)"!";
              m = 1;
              soap_unget(soap, c);
            }
            *s++ = '<';
            break;
          }
          else if (c == '?')
            state = 3;
          else if (f && n == 0)
	  { soap_revget1(soap);
	    c = '<';
	    goto end;
	  }
	  else
            n++;
          soap_unget(soap, c);
          *s++ = '<';
          break;
        case '>':
          *s++ = '>';
          break;
        case '"':
          *s++ = '"';
          break;
        default:
#ifndef WITH_LEANER
#ifdef HAVE_WCTOMB
          if (soap->mode & SOAP_C_MBSTRING)
          { m = wctomb(buf, c & 0x7FFFFFFF);
            if (m >= 1 && m <= (int)MB_CUR_MAX)
            { t = buf;
              *s++ = *t++;
              m--;
            }
            else
            { *s++ = SOAP_UNKNOWN_CHAR;
              m = 0;
            }
          }
          else
#endif
#endif
            *s++ = (char)(c & 0xFF);
        }
        l++;
        if (maxlen >= 0 && l > maxlen)
        { DBGLOG(TEST,SOAP_MESSAGE(fdebug, "String too long: maxlen=%ld\n", maxlen));
          soap->error = SOAP_LENGTH;
          return NULL;
        }
      }
    }
  }
#endif
#ifdef WITH_FAST
  soap->labidx = 0;			/* use look-aside buffer */
#else
  if (soap_new_block(soap) == NULL)
    return NULL;
#endif
  for (;;)
  { 
#ifdef WITH_FAST
    register size_t k;
    if (soap_append_lab(soap, NULL, 0))	/* allocate more space in look-aside buffer if necessary */
      return NULL;
    s = soap->labbuf + soap->labidx;	/* space to populate */
    k = soap->lablen - soap->labidx;	/* number of bytes available */
    soap->labidx = soap->lablen;	/* claim this space */
#else
    register size_t k = SOAP_BLKLEN;
    if (!(s = (char*)soap_push_block(soap, NULL, k)))
      return NULL;
#endif
    for (i = 0; i < k; i++)
    { if (m > 0)
      { *s++ = *t++;	/* copy multibyte characters */
        m--;
        continue;
      }
      if (soap->mode & SOAP_C_UTFSTRING)
      { if (((c = soap_get(soap)) & 0x80000000) && c >= -0x7FFFFF80 && c < SOAP_AP)
        { c &= 0x7FFFFFFF;
          t = buf;
          if (c < 0x0800)
            *t++ = (char)(0xC0 | ((c >> 6) & 0x1F));
          else
          { if (c < 0x010000)
              *t++ = (char)(0xE0 | ((c >> 12) & 0x0F));
            else
            { if (c < 0x200000)
                *t++ = (char)(0xF0 | ((c >> 18) & 0x07));
              else
              { if (c < 0x04000000)
                  *t++ = (char)(0xF8 | ((c >> 24) & 0x03));
                else
                { *t++ = (char)(0xFC | ((c >> 30) & 0x01));
                  *t++ = (char)(0x80 | ((c >> 24) & 0x3F));
                }
                *t++ = (char)(0x80 | ((c >> 18) & 0x3F));
              }     
              *t++ = (char)(0x80 | ((c >> 12) & 0x3F));
            }
            *t++ = (char)(0x80 | ((c >> 6) & 0x3F));
          }
          *t++ = (char)(0x80 | (c & 0x3F));
          m = (int)(t - buf) - 1;
          t = buf;
          *s++ = *t++;
          continue;
        }
      }
      else
        c = soap_getutf8(soap);
      switch (c)
      {
      case SOAP_TT:
        if (n == 0)
          goto end;
        n--;
        *s++ = '<';
        t = (char*)"/";
        m = 1;
        break;
      case SOAP_LT:
	if (f && n == 0)
	  goto end;
        n++;
        *s++ = '<';
        break;
      case SOAP_GT:
        *s++ = '>';
        break;
      case SOAP_QT:
        *s++ = '"';
        break;
      case SOAP_AP:
        *s++ = '\'';
        break;
      case '/':
        if (n > 0)
        { c = soap_get(soap);
          if (c == SOAP_GT)
            n--;
          soap_unget(soap, c);
        }
        *s++ = '/';
        break;
      case (soap_wchar)('<' | 0x80000000):
        if (flag)
          *s++ = '<';
        else
        { *s++ = '&';
          t = (char*)"lt;";
          m = 3;
        }
        break;
      case (soap_wchar)('>' | 0x80000000):
        if (flag)
          *s++ = '>';
        else
        { *s++ = '&';
          t = (char*)"gt;";
          m = 3;
        }
        break;
      case (soap_wchar)('&' | 0x80000000):
        if (flag)
          *s++ = '&';
        else
        { *s++ = '&';
          t = (char*)"amp;";
          m = 4;
        }
        break;
      case (soap_wchar)('"' | 0x80000000):
        if (flag)
          *s++ = '"';
        else
        { *s++ = '&';
          t = (char*)"quot;";
          m = 5;
        }
        break;
      case (soap_wchar)('\'' | 0x80000000):
        if (flag)
          *s++ = '\'';
        else
        { *s++ = '&';
          t = (char*)"apos;";
          m = 5;
        }
        break;
      default:
        if ((int)c == EOF)
          goto end;
#ifndef WITH_LEANER
#ifdef HAVE_WCTOMB
        if (soap->mode & SOAP_C_MBSTRING)
        { m = wctomb(buf, c & 0x7FFFFFFF);
          if (m >= 1 && m <= (int)MB_CUR_MAX)
          { t = buf;
            *s++ = *t++;
            m--;
          }
          else
          { *s++ = SOAP_UNKNOWN_CHAR;
            m = 0;
          }
        }
        else
#endif
#endif
          *s++ = (char)(c & 0xFF);
      }
      l++;
      if (maxlen >= 0 && l > maxlen)
      { DBGLOG(TEST,SOAP_MESSAGE(fdebug, "String too long: maxlen=%ld\n", maxlen));
        soap->error = SOAP_LENGTH;
        return NULL;
      }
    }
  }
end:
  soap_unget(soap, c);
  *s = '\0';
#ifdef WITH_FAST
  t = soap_strdup(soap, soap->labbuf);
#else
  soap_size_block(soap, NULL, i+1);
  t = soap_save_block(soap, NULL, 0);
#endif
  if (l < minlen)
  { DBGLOG(TEST,SOAP_MESSAGE(fdebug, "String too short: %ld chars, minlen=%ld\n", l, minlen));
    soap->error = SOAP_LENGTH;
    return NULL;
  }
#ifdef WITH_DOM
  if ((soap->mode & SOAP_XML_DOM) && soap->dom)
  { if (flag == 3)
      soap->dom->tail = t;
    else
      soap->dom->data = t;
  }
#endif
  if (flag == 2)
    if (soap_s2QName(soap, t, &t, minlen, maxlen))
      return NULL;
  return t;
}
#endif

/******************************************************************************/
#ifndef WITH_LEANER
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_wstring_out(struct soap *soap, const wchar_t *s, int flag)
{ const char *t;
  char tmp;
  register soap_wchar c;
#ifdef WITH_DOM
  if ((soap->mode & SOAP_XML_DOM) && soap->dom)
  { wchar_t *r = (wchar_t*)s;
    int n = 1;
    while (*r++)
      n++;
    soap->dom->wide = r = (wchar_t*)soap_malloc(soap, n * sizeof(wchar_t));
    while (n--)
      *r++ = *s++;
    return SOAP_OK;
  }
#endif
  while ((c = *s++))
  { switch (c)
    { 
    case 0x09:
      if (flag)
        t = "&#x9;";
      else
        t = "\t";
      break;
    case 0x0A:
      if (flag || !(soap->mode & SOAP_XML_CANONICAL))
        t = "&#xA;";
      else
        t = "\n";
      break;
    case 0x0D:
      t = "&#xD;";
      break;
    case '&':
      t = "&amp;";
      break;
    case '<':
      t = "&lt;";
      break;
    case '>':
      if (flag)
        t = ">";
      else
        t = "&gt;";
      break;
    case '"':
      if (flag)
        t = "&quot;";
      else
        t = "\"";
      break;
    default:
      if (c >= 0x20 && c < 0x80)
      { tmp = (char)c;
        if (soap_send_raw(soap, &tmp, 1))
          return soap->error;
      }
      else /* check UTF16 encoding when wchar_t is too small to hold UCS */
      { if (sizeof(wchar_t) < 4 && (c & 0xD800) == 0xD800)
	{ /* http://unicode.org/faq/utf_bom.html#utf16-2 */
          if ((*s & 0xD800) == 0xD800)
	    c = (c << 10) + *s++ + 0x10000 - (0xD800 << 10) - 0xDC00;
	  else
	    c = 0xFFFD; /* Malformed */
        }
        if (soap_pututf8(soap, (unsigned long)c))
          return soap->error;
      }
      continue;
    }
    if (soap_send(soap, t))
      return soap->error;
  }
  return SOAP_OK;
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_LEANER
#ifndef PALM_2
SOAP_FMAC1
wchar_t *
SOAP_FMAC2
soap_wstring_in(struct soap *soap, int flag, long minlen, long maxlen)
{ wchar_t *s;
  register int i, n = 0, f = 0;
  register long l = 0;
  register soap_wchar c;
  char *t = NULL;
  DBGLOG(TEST,SOAP_MESSAGE(fdebug, "Reading wide string content\n"));
  if (soap->peeked)
  { if (*soap->tag)
    {
#ifndef WITH_LEAN
      struct soap_attribute *tp;
      t = soap->tmpbuf;
      *t = '<';
      t[sizeof(soap->tmpbuf)-1] = '\0';
      strncpy(t + 1, soap->tag, sizeof(soap->tmpbuf) - 2);
      t += strlen(t);
      for (tp = soap->attributes; tp; tp = tp->next)
      { if (tp->visible)
        { if (t >= soap->tmpbuf + sizeof(soap->tmpbuf) - 2)
            break;
          *t++ = ' ';
          strcpy(t, tp->name);
          t += strlen(t);
          if (t >= soap->tmpbuf + sizeof(soap->tmpbuf) - 2)
            break;
          if (tp->value)
          { *t++ = '=';
            *t++ = '"';
            strcpy(t, tp->value);
            t += strlen(t);
            *t++ = '"';
          }
        }
      }
      if (!soap->body)
        *t++ = '/';
      *t++ = '>';
      *t = '\0';
      t = soap->tmpbuf;
#endif
      if (soap->body)
        n = 1;
      f = 1;
      soap->peeked = 0;
    }
  }
  if (soap_new_block(soap) == NULL)
    return NULL;
  for (;;)
  { if (!(s = (wchar_t*)soap_push_block(soap, NULL, sizeof(wchar_t)*SOAP_BLKLEN)))
      return NULL;
    for (i = 0; i < SOAP_BLKLEN; i++)
    { if (t)
      { *s++ = (wchar_t)*t++;
        if (!*t)
          t = NULL;
        continue;
      }
      c = soap_getutf8(soap);
      switch (c)
      {
      case SOAP_TT:
        if (n == 0)
          goto end;
        n--;
        *s++ = '<';
        soap_unget(soap, '/');
        break;
      case SOAP_LT:
        if (f && n == 0)
	  goto end;
        n++;
        *s++ = '<';
        break;
      case SOAP_GT:
        *s++ = '>';
        break;
      case SOAP_QT:
        *s++ = '"';
        break;
      case SOAP_AP:
        *s++ = '\'';
        break;
      case '/':
        if (n > 0)
        { c = soap_getutf8(soap);
          if (c == SOAP_GT)
            n--;
          soap_unget(soap, c);
        }
        *s++ = '/';
        break;
      case '<':
        if (flag)
          *s++ = (soap_wchar)'<';
        else
        { *s++ = (soap_wchar)'&';
          t = (char*)"lt;";
        }
        break;
      case '>':
        if (flag)
          *s++ = (soap_wchar)'>';
        else
        { *s++ = (soap_wchar)'&';
          t = (char*)"gt;";
        }
        break;
      case '"':
        if (flag)
          *s++ = (soap_wchar)'"';
        else
        { *s++ = (soap_wchar)'&';
          t = (char*)"quot;";
        }
        break;
      default:
        if ((int)c == EOF)
          goto end;
	if (sizeof(wchar_t) < 4 && c > 0xFFFF)
	{ wchar_t c1, c2;
	  /* http://unicode.org/faq/utf_bom.html#utf16-2 */
	  c1 = 0xD800 - (0x10000 >> 10) + (c >> 10);
	  c2 = 0xDC00 + (c & 0x3FF);
	  c = c1;
	  soap_unget(soap, c2);
	}
        *s++ = (wchar_t)c & 0x7FFFFFFF;
      }
      l++;
      if (maxlen >= 0 && l > maxlen)
      { DBGLOG(TEST,SOAP_MESSAGE(fdebug, "String too long: maxlen=%ld\n", maxlen));
        soap->error = SOAP_LENGTH;
        return NULL;
      }
    }
  }
end:
  soap_unget(soap, c);
  *s = '\0';
  soap_size_block(soap, NULL, sizeof(wchar_t) * (i + 1));
  if (l < minlen)
  { DBGLOG(TEST,SOAP_MESSAGE(fdebug, "String too short: %ld chars, minlen=%ld\n", l, minlen));
    soap->error = SOAP_LENGTH;
    return NULL;
  }
  s = (wchar_t*)soap_save_block(soap, NULL, NULL, 0);
#ifdef WITH_DOM
  if ((soap->mode & SOAP_XML_DOM) && soap->dom)
    soap->dom->wide = s;
#endif
  return s;
}
#endif
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
const char*
SOAP_FMAC2
soap_int2s(struct soap *soap, int n)
{ return soap_long2s(soap, (long)n);
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_outint(struct soap *soap, const char *tag, int id, const int *p, const char *type, int n)
{ if (soap_element_begin_out(soap, tag, soap_embedded_id(soap, id, p, n), type)
   || soap_string_out(soap, soap_long2s(soap, (long)*p), 0))
    return soap->error;
  return soap_element_end_out(soap, tag);
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_s2int(struct soap *soap, const char *s, int *p)
{ if (s)
  { char *r;
#ifndef WITH_NOIO
#ifndef WITH_LEAN
    soap_reset_errno;
#endif
#endif
    *p = (int)soap_strtol(s, &r, 10);
    if ((s == r && (soap->mode & SOAP_XML_STRICT)) || *r
#ifndef WITH_NOIO
#ifndef WITH_LEAN
     || soap_errno == SOAP_ERANGE
#endif
#endif
    )
      soap->error = SOAP_TYPE;
  }
  return soap->error;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
int *
SOAP_FMAC2
soap_inint(struct soap *soap, const char *tag, int *p, const char *type, int t)
{ if (soap_element_begin_in(soap, tag, 0, NULL))
    return NULL;
#ifndef WITH_LEAN
  if (*soap->type
   && soap_match_tag(soap, soap->type, type)
   && soap_match_tag(soap, soap->type, ":int")
   && soap_match_tag(soap, soap->type, ":short")
   && soap_match_tag(soap, soap->type, ":byte"))
  { soap->error = SOAP_TYPE;
    soap_revert(soap);
    return NULL;
  }
#endif
  p = (int*)soap_id_enter(soap, soap->id, p, t, sizeof(int), 0, NULL, NULL, NULL);
  if (*soap->href)
    p = (int*)soap_id_forward(soap, soap->href, p, 0, t, 0, sizeof(int), 0, NULL);
  else if (p)
  { if (soap_s2int(soap, soap_value(soap), p))
      return NULL;
  }
  if (soap->body && soap_element_end_in(soap, tag))
    return NULL;
  return p;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
const char*
SOAP_FMAC2
soap_long2s(struct soap *soap, long n)
{ sprintf(soap->tmpbuf, "%ld", n);
  return soap->tmpbuf;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_outlong(struct soap *soap, const char *tag, int id, const long *p, const char *type, int n)
{ if (soap_element_begin_out(soap, tag, soap_embedded_id(soap, id, p, n), type)
   || soap_string_out(soap, soap_long2s(soap, *p), 0))
    return soap->error;
  return soap_element_end_out(soap, tag);
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_s2long(struct soap *soap, const char *s, long *p)
{ if (s)
  { char *r;
#ifndef WITH_NOIO
#ifndef WITH_LEAN
    soap_reset_errno;
#endif
#endif
    *p = soap_strtol(s, &r, 10);
    if ((s == r && (soap->mode & SOAP_XML_STRICT)) || *r
#ifndef WITH_NOIO
#ifndef WITH_LEAN
     || soap_errno == SOAP_ERANGE
#endif
#endif
    )
      soap->error = SOAP_TYPE;
  }
  return soap->error;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
long *
SOAP_FMAC2
soap_inlong(struct soap *soap, const char *tag, long *p, const char *type, int t)
{ if (soap_element_begin_in(soap, tag, 0, NULL))
    return NULL;
#ifndef WITH_LEAN
  if (*soap->type
   && soap_match_tag(soap, soap->type, type)
   && soap_match_tag(soap, soap->type, ":int")
   && soap_match_tag(soap, soap->type, ":short")
   && soap_match_tag(soap, soap->type, ":byte"))
  { soap->error = SOAP_TYPE;
    soap_revert(soap);
    return NULL;
  }
#endif
  p = (long*)soap_id_enter(soap, soap->id, p, t, sizeof(long), 0, NULL, NULL, NULL);
  if (*soap->href)
    p = (long*)soap_id_forward(soap, soap->href, p, 0, t, 0, sizeof(long), 0, NULL);
  else if (p)
  { if (soap_s2long(soap, soap_value(soap), p))
      return NULL;
  }
  if (soap->body && soap_element_end_in(soap, tag))
    return NULL;
  return p;
}
#endif

/******************************************************************************/
#ifndef WITH_LEAN
SOAP_FMAC1
const char*
SOAP_FMAC2
soap_LONG642s(struct soap *soap, LONG64 n)
{ sprintf(soap->tmpbuf, SOAP_LONG_FORMAT, n);
  return soap->tmpbuf;
}
#endif

/******************************************************************************/
#ifndef WITH_LEAN
SOAP_FMAC1
int
SOAP_FMAC2
soap_outLONG64(struct soap *soap, const char *tag, int id, const LONG64 *p, const char *type, int n)
{ if (soap_element_begin_out(soap, tag, soap_embedded_id(soap, id, p, n), type)
   || soap_string_out(soap, soap_LONG642s(soap, *p), 0))
    return soap->error;
  return soap_element_end_out(soap, tag);
}
#endif

/******************************************************************************/
#ifndef WITH_LEAN
SOAP_FMAC1
int
SOAP_FMAC2
soap_s2LONG64(struct soap *soap, const char *s, LONG64 *p)
{ if (s)
  {
#ifdef HAVE_STRTOLL
    char *r;
#ifndef WITH_NOIO
#ifndef WITH_LEAN
    soap_reset_errno;
#endif
#endif
    *p = strtoll(s, &r, 10);
    if ((s == r && (soap->mode & SOAP_XML_STRICT)) || *r
#ifndef WITH_NOIO
#ifndef WITH_LEAN
       || soap_errno == SOAP_ERANGE
#endif
#endif
      )
#else
# ifdef HAVE_SSCANF
    if (sscanf(s, SOAP_LONG_FORMAT, p) != 1)
# endif
#endif
      soap->error = SOAP_TYPE;
  }
  return soap->error;
}
#endif

/******************************************************************************/
#ifndef WITH_LEAN
SOAP_FMAC1
LONG64 *
SOAP_FMAC2
soap_inLONG64(struct soap *soap, const char *tag, LONG64 *p, const char *type, int t)
{ if (soap_element_begin_in(soap, tag, 0, NULL))
    return NULL;
#ifndef WITH_LEAN
  if (*soap->type
   && soap_match_tag(soap, soap->type, type)
   && soap_match_tag(soap, soap->type, ":integer")
   && soap_match_tag(soap, soap->type, ":positiveInteger")
   && soap_match_tag(soap, soap->type, ":negativeInteger")
   && soap_match_tag(soap, soap->type, ":nonPositiveInteger")
   && soap_match_tag(soap, soap->type, ":nonNegativeInteger")
   && soap_match_tag(soap, soap->type, ":long")
   && soap_match_tag(soap, soap->type, ":int")
   && soap_match_tag(soap, soap->type, ":short")
   && soap_match_tag(soap, soap->type, ":byte"))
  { soap->error = SOAP_TYPE;
    soap_revert(soap);
    return NULL;
  }
#endif
  p = (LONG64*)soap_id_enter(soap, soap->id, p, t, sizeof(LONG64), 0, NULL, NULL, NULL);
  if (*soap->href)
    p = (LONG64*)soap_id_forward(soap, soap->href, p, 0, t, 0, sizeof(LONG64), 0, NULL);
  else if (p)
  { if (soap_s2LONG64(soap, soap_value(soap), p))
      return NULL;
  }
  if (soap->body && soap_element_end_in(soap, tag))
    return NULL;
  return p;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
const char*
SOAP_FMAC2
soap_byte2s(struct soap *soap, char n)
{ return soap_long2s(soap, (long)n);
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_outbyte(struct soap *soap, const char *tag, int id, const char *p, const char *type, int n)
{ if (soap_element_begin_out(soap, tag, soap_embedded_id(soap, id, p, n), type)
   || soap_string_out(soap, soap_long2s(soap, (long)*p), 0))
    return soap->error;
  return soap_element_end_out(soap, tag);
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_s2byte(struct soap *soap, const char *s, char *p)
{ if (s)
  { long n;
    char *r;
    n = soap_strtol(s, &r, 10);
    if (s == r || *r || n < -128 || n > 127)
      soap->error = SOAP_TYPE;
    *p = (char)n;
  }
  return soap->error;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
char *
SOAP_FMAC2
soap_inbyte(struct soap *soap, const char *tag, char *p, const char *type, int t)
{ if (soap_element_begin_in(soap, tag, 0, NULL))
    return NULL;
#ifndef WITH_LEAN
  if (*soap->type
   && soap_match_tag(soap, soap->type, type)
   && soap_match_tag(soap, soap->type, ":byte"))
  { soap->error = SOAP_TYPE;
    soap_revert(soap);
    return NULL;
  }
#endif
  p = (char*)soap_id_enter(soap, soap->id, p, t, sizeof(char), 0, NULL, NULL, NULL);
  if (*soap->href)
    p = (char*)soap_id_forward(soap, soap->href, p, 0, t, 0, sizeof(char), 0, NULL);
  else if (p)
  { if (soap_s2byte(soap, soap_value(soap), p))
      return NULL;
  }
  if (soap->body && soap_element_end_in(soap, tag))
    return NULL;
  return p;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
const char*
SOAP_FMAC2
soap_short2s(struct soap *soap, short n)
{ return soap_long2s(soap, (long)n);
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_outshort(struct soap *soap, const char *tag, int id, const short *p, const char *type, int n)
{ if (soap_element_begin_out(soap, tag, soap_embedded_id(soap, id, p, n), type)
   || soap_string_out(soap, soap_long2s(soap, (long)*p), 0))
    return soap->error;
  return soap_element_end_out(soap, tag);
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_s2short(struct soap *soap, const char *s, short *p)
{ if (s)
  { long n;
    char *r;
    n = soap_strtol(s, &r, 10);
    if (s == r || *r || n < -32768 || n > 32767)
      soap->error = SOAP_TYPE;
    *p = (short)n;
  }
  return soap->error;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
short *
SOAP_FMAC2
soap_inshort(struct soap *soap, const char *tag, short *p, const char *type, int t)
{ if (soap_element_begin_in(soap, tag, 0, NULL))
    return NULL;
#ifndef WITH_LEAN
  if (*soap->type
   && soap_match_tag(soap, soap->type, type)
   && soap_match_tag(soap, soap->type, ":short")
   && soap_match_tag(soap, soap->type, ":byte"))
  { soap->error = SOAP_TYPE;
    soap_revert(soap);
    return NULL;
  }
#endif
  p = (short*)soap_id_enter(soap, soap->id, p, t, sizeof(short), 0, NULL, NULL, NULL);
  if (*soap->href)
    p = (short*)soap_id_forward(soap, soap->href, p, 0, t, 0, sizeof(short), 0, NULL);
  else if (p)
  { if (soap_s2short(soap, soap_value(soap), p))
      return NULL;
  }
  if (soap->body && soap_element_end_in(soap, tag))
    return NULL;
  return p;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
const char*
SOAP_FMAC2
soap_float2s(struct soap *soap, float n)
{ char *s;
  if (soap_isnan((double)n))
    return "NaN";
  if (soap_ispinff(n))
    return "INF";
  if (soap_isninff(n))
    return "-INF";
  s = soap->tmpbuf;
#if defined(HAVE_SPRINTF_L)
  sprintf_l(s, soap->c_locale, soap->float_format, n);
#else
  sprintf(s, soap->float_format, n);
  s = strchr(s, ',');	/* convert decimal comma to DP */
  if (s)
    *s = '.';
#endif
  return soap->tmpbuf;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_outfloat(struct soap *soap, const char *tag, int id, const float *p, const char *type, int n)
{ if (soap_element_begin_out(soap, tag, soap_embedded_id(soap, id, p, n), type)
   || soap_string_out(soap, soap_float2s(soap, *p), 0))
    return soap->error;
  return soap_element_end_out(soap, tag);
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_s2float(struct soap *soap, const char *s, float *p)
{ if (s)
  { if (!*s)
      return soap->error = SOAP_TYPE;
    if (!soap_tag_cmp(s, "INF"))
      *p = FLT_PINFTY;
    else if (!soap_tag_cmp(s, "+INF"))
      *p = FLT_PINFTY;
    else if (!soap_tag_cmp(s, "-INF"))
      *p = FLT_NINFTY;
    else if (!soap_tag_cmp(s, "NaN"))
      *p = FLT_NAN;
    else
    {
/* On some systems strtof requires -std=c99 or does not even link: so we try to use strtod first */
#if defined(HAVE_STRTOD_L)
      char *r;
      *p = (float)strtod_l(s, &r, soap->c_locale);
      if (*r)
#elif defined(HAVE_STRTOD)
      char *r;
      *p = (float)strtod(s, &r);
      if (*r)
#elif defined(HAVE_STRTOF_L)
      char *r;
      *p = strtof_l((char*)s, &r, soap->c_locale);
      if (*r)
#elif defined(HAVE_STRTOF)
      char *r;
      *p = strtof((char*)s, &r);
      if (*r)
#endif
      {
#if defined(HAVE_SSCANF_L) && !defined(HAVE_STRTOF_L) && !defined(HAVE_STRTOD_L)
        if (sscanf_l(s, soap->c_locale, "%g", p) != 1)
          soap->error = SOAP_TYPE;
#elif defined(HAVE_SSCANF)
        if (sscanf(s, "%g", p) != 1)
          soap->error = SOAP_TYPE;
#else
        soap->error = SOAP_TYPE;
#endif
      }
    }
  }
  return soap->error;
}
#endif

/******************************************************************************/
#ifndef WITH_LEAN
static int soap_isnumeric(struct soap *soap, const char *type)
{ if (soap_match_tag(soap, soap->type, type)
   && soap_match_tag(soap, soap->type, ":float")
   && soap_match_tag(soap, soap->type, ":double")
   && soap_match_tag(soap, soap->type, ":decimal")
   && soap_match_tag(soap, soap->type, ":integer")
   && soap_match_tag(soap, soap->type, ":positiveInteger")
   && soap_match_tag(soap, soap->type, ":negativeInteger")
   && soap_match_tag(soap, soap->type, ":nonPositiveInteger")
   && soap_match_tag(soap, soap->type, ":nonNegativeInteger")
   && soap_match_tag(soap, soap->type, ":long")
   && soap_match_tag(soap, soap->type, ":int")
   && soap_match_tag(soap, soap->type, ":short")
   && soap_match_tag(soap, soap->type, ":byte")
   && soap_match_tag(soap, soap->type, ":unsignedLong")
   && soap_match_tag(soap, soap->type, ":unsignedInt")
   && soap_match_tag(soap, soap->type, ":unsignedShort")
   && soap_match_tag(soap, soap->type, ":unsignedByte"))
  { soap->error = SOAP_TYPE;
    soap_revert(soap);
    return SOAP_ERR;
  }
  return SOAP_OK;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
float *
SOAP_FMAC2
soap_infloat(struct soap *soap, const char *tag, float *p, const char *type, int t)
{ if (soap_element_begin_in(soap, tag, 0, NULL))
    return NULL;
#ifndef WITH_LEAN
  if (*soap->type != '\0' && soap_isnumeric(soap, type))
    return NULL;
#endif
  p = (float*)soap_id_enter(soap, soap->id, p, t, sizeof(float), 0, NULL, NULL, NULL);
  if (*soap->href)
    p = (float*)soap_id_forward(soap, soap->href, p, 0, t, 0, sizeof(float), 0, NULL);
  else if (p)
  { if (soap_s2float(soap, soap_value(soap), p))
      return NULL;
  }
  if (soap->body && soap_element_end_in(soap, tag))
    return NULL;
  return p;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
const char*
SOAP_FMAC2
soap_double2s(struct soap *soap, double n)
{ char *s;
  if (soap_isnan(n))
    return "NaN";
  if (soap_ispinfd(n))
    return "INF";
  if (soap_isninfd(n))
    return "-INF";
  s = soap->tmpbuf;
#if defined(HAVE_SPRINTF_L)
  sprintf_l(s, soap->c_locale, soap->double_format, n);
#else
  sprintf(s, soap->double_format, n);
  s = strchr(s, ',');	/* convert decimal comma to DP */
  if (s)
    *s = '.';
#endif
  return soap->tmpbuf;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_outdouble(struct soap *soap, const char *tag, int id, const double *p, const char *type, int n)
{ if (soap_element_begin_out(soap, tag, soap_embedded_id(soap, id, p, n), type)
   || soap_string_out(soap, soap_double2s(soap, *p), 0))
    return soap->error;
  return soap_element_end_out(soap, tag);
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_s2double(struct soap *soap, const char *s, double *p)
{ if (s)
  { if (!*s)
      return soap->error = SOAP_TYPE;
    if (!soap_tag_cmp(s, "INF"))
      *p = DBL_PINFTY;
    else if (!soap_tag_cmp(s, "+INF"))
      *p = DBL_PINFTY;
    else if (!soap_tag_cmp(s, "-INF"))
      *p = DBL_NINFTY;
    else if (!soap_tag_cmp(s, "NaN"))
      *p = DBL_NAN;
    else
    {
#if defined(HAVE_STRTOD_L)
      char *r;
      *p = strtod_l(s, &r, soap->c_locale);
      if (*r)
#elif defined(HAVE_STRTOD)
      char *r;
      *p = strtod(s, &r);
      if (*r)
#endif
      {
#if defined(HAVE_SSCANF_L) && !defined(HAVE_STRTOF_L) && !defined(HAVE_STRTOD_L)
        if (sscanf_l(s, soap->c_locale, "%lg", p) != 1)
          soap->error = SOAP_TYPE;
#elif defined(HAVE_SSCANF)
        if (sscanf(s, "%lg", p) != 1)
          soap->error = SOAP_TYPE;
#else
        soap->error = SOAP_TYPE;
#endif
      }
    }
  }
  return soap->error;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
double *
SOAP_FMAC2
soap_indouble(struct soap *soap, const char *tag, double *p, const char *type, int t)
{ if (soap_element_begin_in(soap, tag, 0, NULL))
    return NULL;
#ifndef WITH_LEAN
  if (*soap->type != '\0' && soap_isnumeric(soap, type))
    return NULL;
#endif
  p = (double*)soap_id_enter(soap, soap->id, p, t, sizeof(double), 0, NULL, NULL, NULL);
  if (*soap->href)
    p = (double*)soap_id_forward(soap, soap->href, p, 0, t, 0, sizeof(double), 0, NULL);
  else if (p)
  { if (soap_s2double(soap, soap_value(soap), p))
      return NULL;
  }
  if (soap->body && soap_element_end_in(soap, tag))
    return NULL;
  return p;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
const char*
SOAP_FMAC2
soap_unsignedByte2s(struct soap *soap, unsigned char n)
{ return soap_unsignedLong2s(soap, (unsigned long)n);
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_outunsignedByte(struct soap *soap, const char *tag, int id, const unsigned char *p, const char *type, int n)
{ if (soap_element_begin_out(soap, tag, soap_embedded_id(soap, id, p, n), type)
   || soap_string_out(soap, soap_unsignedLong2s(soap, (unsigned long)*p), 0))
    return soap->error;
  return soap_element_end_out(soap, tag);
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_s2unsignedByte(struct soap *soap, const char *s, unsigned char *p)
{ if (s)
  { unsigned long n;
    char *r;
    n = soap_strtoul(s, &r, 10);
    if (s == r || *r || n > 255)
      soap->error = SOAP_TYPE;
    *p = (unsigned char)n;
  }
  return soap->error;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
unsigned char *
SOAP_FMAC2
soap_inunsignedByte(struct soap *soap, const char *tag, unsigned char *p, const char *type, int t)
{ if (soap_element_begin_in(soap, tag, 0, NULL))
    return NULL;
#ifndef WITH_LEAN
  if (*soap->type
   && soap_match_tag(soap, soap->type, type)
   && soap_match_tag(soap, soap->type, ":unsignedByte"))
  { soap->error = SOAP_TYPE;
    soap_revert(soap);
    return NULL;
  }
#endif
  p = (unsigned char*)soap_id_enter(soap, soap->id, p, t, sizeof(unsigned char), 0, NULL, NULL, NULL);
  if (*soap->href)
    p = (unsigned char*)soap_id_forward(soap, soap->href, p, 0, t, 0, sizeof(unsigned char), 0, NULL);
  else if (p)
  { if (soap_s2unsignedByte(soap, soap_value(soap), p))
      return NULL;
  }
  if (soap->body && soap_element_end_in(soap, tag))
    return NULL;
  return p;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
const char*
SOAP_FMAC2
soap_unsignedShort2s(struct soap *soap, unsigned short n)
{ return soap_unsignedLong2s(soap, (unsigned long)n);
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_outunsignedShort(struct soap *soap, const char *tag, int id, const unsigned short *p, const char *type, int n)
{ if (soap_element_begin_out(soap, tag, soap_embedded_id(soap, id, p, n), type)
   || soap_string_out(soap, soap_unsignedLong2s(soap, (unsigned long)*p), 0))
    return soap->error;
  return soap_element_end_out(soap, tag);
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_s2unsignedShort(struct soap *soap, const char *s, unsigned short *p)
{ if (s)
  { unsigned long n;
    char *r;
    n = soap_strtoul(s, &r, 10);
    if (s == r || *r || n > 65535)
      soap->error = SOAP_TYPE;
    *p = (unsigned short)n;
  }
  return soap->error;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
unsigned short *
SOAP_FMAC2
soap_inunsignedShort(struct soap *soap, const char *tag, unsigned short *p, const char *type, int t)
{ if (soap_element_begin_in(soap, tag, 0, NULL))
    return NULL;
#ifndef WITH_LEAN
  if (*soap->type
   && soap_match_tag(soap, soap->type, type)
   && soap_match_tag(soap, soap->type, ":unsignedShort")
   && soap_match_tag(soap, soap->type, ":unsignedByte"))
  { soap->error = SOAP_TYPE;
    soap_revert(soap);
    return NULL;
  }
#endif
  p = (unsigned short*)soap_id_enter(soap, soap->id, p, t, sizeof(unsigned short), 0, NULL, NULL, NULL);
  if (*soap->href)
    p = (unsigned short*)soap_id_forward(soap, soap->href, p, 0, t, 0, sizeof(unsigned short), 0, NULL);
  else if (p)
  { if (soap_s2unsignedShort(soap, soap_value(soap), p))
      return NULL;
  }
  if (soap->body && soap_element_end_in(soap, tag))
    return NULL;
  return p;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
const char*
SOAP_FMAC2
soap_unsignedInt2s(struct soap *soap, unsigned int n)
{ return soap_unsignedLong2s(soap, (unsigned long)n);
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_outunsignedInt(struct soap *soap, const char *tag, int id, const unsigned int *p, const char *type, int n)
{ if (soap_element_begin_out(soap, tag, soap_embedded_id(soap, id, p, n), type)
   || soap_string_out(soap, soap_unsignedLong2s(soap, (unsigned long)*p), 0))
    return soap->error;
  return soap_element_end_out(soap, tag);
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_s2unsignedInt(struct soap *soap, const char *s, unsigned int *p)
{ if (s)
  { char *r;
#ifndef WITH_NOIO
#ifndef WITH_LEAN
    soap_reset_errno;
#endif
#endif
    *p = (unsigned int)soap_strtoul(s, &r, 10);
    if ((s == r && (soap->mode & SOAP_XML_STRICT)) || *r
#ifndef WITH_NOIO
#ifndef WITH_LEAN
     || soap_errno == SOAP_ERANGE
#endif
#endif
    )
      soap->error = SOAP_TYPE;
  }
  return soap->error;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
unsigned int *
SOAP_FMAC2
soap_inunsignedInt(struct soap *soap, const char *tag, unsigned int *p, const char *type, int t)
{ if (soap_element_begin_in(soap, tag, 0, NULL))
    return NULL;
#ifndef WITH_LEAN
  if (*soap->type
   && soap_match_tag(soap, soap->type, type)
   && soap_match_tag(soap, soap->type, ":unsignedInt")
   && soap_match_tag(soap, soap->type, ":unsignedShort")
   && soap_match_tag(soap, soap->type, ":unsignedByte"))
  { soap->error = SOAP_TYPE;
    soap_revert(soap);
    return NULL;
  }
#endif
  p = (unsigned int*)soap_id_enter(soap, soap->id, p, t, sizeof(unsigned int), 0, NULL, NULL, NULL);
  if (*soap->href)
    p = (unsigned int*)soap_id_forward(soap, soap->href, p, 0, t, 0, sizeof(unsigned int), 0, NULL);
  else if (p)
  { if (soap_s2unsignedInt(soap, soap_value(soap), p))
      return NULL;
  }
  if (soap->body && soap_element_end_in(soap, tag))
    return NULL;
  return p;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
const char*
SOAP_FMAC2
soap_unsignedLong2s(struct soap *soap, unsigned long n)
{ sprintf(soap->tmpbuf, "%lu", n);
  return soap->tmpbuf;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_outunsignedLong(struct soap *soap, const char *tag, int id, const unsigned long *p, const char *type, int n)
{ if (soap_element_begin_out(soap, tag, soap_embedded_id(soap, id, p, n), type)
   || soap_string_out(soap, soap_unsignedLong2s(soap, *p), 0))
    return soap->error;
  return soap_element_end_out(soap, tag);
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_s2unsignedLong(struct soap *soap, const char *s, unsigned long *p)
{ if (s)
  { char *r;
#ifndef WITH_NOIO
#ifndef WITH_LEAN
    soap_reset_errno;
#endif
#endif
    *p = soap_strtoul(s, &r, 10);
    if ((s == r && (soap->mode & SOAP_XML_STRICT)) || *r
#ifndef WITH_NOIO
#ifndef WITH_LEAN
     || soap_errno == SOAP_ERANGE
#endif
#endif
    )
      soap->error = SOAP_TYPE;
  }
  return soap->error;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
unsigned long *
SOAP_FMAC2
soap_inunsignedLong(struct soap *soap, const char *tag, unsigned long *p, const char *type, int t)
{ if (soap_element_begin_in(soap, tag, 0, NULL))
    return NULL;
#ifndef WITH_LEAN
  if (*soap->type
   && soap_match_tag(soap, soap->type, type)
   && soap_match_tag(soap, soap->type, ":unsignedInt")
   && soap_match_tag(soap, soap->type, ":unsignedShort")
   && soap_match_tag(soap, soap->type, ":unsignedByte"))
  { soap->error = SOAP_TYPE;
    soap_revert(soap);
    return NULL;
  }
#endif
  p = (unsigned long*)soap_id_enter(soap, soap->id, p, t, sizeof(unsigned long), 0, NULL, NULL, NULL);
  if (*soap->href)
    p = (unsigned long*)soap_id_forward(soap, soap->href, p, 0, t, 0, sizeof(unsigned long), 0, NULL);
  else if (p)
  { if (soap_s2unsignedLong(soap, soap_value(soap), p))
      return NULL;
  }
  if (soap->body && soap_element_end_in(soap, tag))
    return NULL;
  return p;
}
#endif

/******************************************************************************/
#ifndef WITH_LEAN
SOAP_FMAC1
const char*
SOAP_FMAC2
soap_ULONG642s(struct soap *soap, ULONG64 n)
{ sprintf(soap->tmpbuf, SOAP_ULONG_FORMAT, n);
  return soap->tmpbuf;
}
#endif

/******************************************************************************/
#ifndef WITH_LEAN
SOAP_FMAC1
int
SOAP_FMAC2
soap_outULONG64(struct soap *soap, const char *tag, int id, const ULONG64 *p, const char *type, int n)
{ if (soap_element_begin_out(soap, tag, soap_embedded_id(soap, id, p, n), type)
   || soap_string_out(soap, soap_ULONG642s(soap, *p), 0))
    return soap->error;
  return soap_element_end_out(soap, tag);
}
#endif

/******************************************************************************/
#ifndef WITH_LEAN
SOAP_FMAC1
int
SOAP_FMAC2
soap_s2ULONG64(struct soap *soap, const char *s, ULONG64 *p)
{ if (s)
  {
#ifdef HAVE_STRTOULL
    char *r;
#ifndef WITH_NOIO
#ifndef WITH_LEAN
    soap_reset_errno;
#endif
#endif
    *p = strtoull(s, &r, 10);
    if ((s == r && (soap->mode & SOAP_XML_STRICT)) || *r
#ifndef WITH_NOIO
#ifndef WITH_LEAN
       || soap_errno == SOAP_ERANGE
#endif
#endif
      )
#else
#ifdef HAVE_SSCANF
    if (sscanf(s, SOAP_ULONG_FORMAT, p) != 1)
#endif
#endif
      soap->error = SOAP_TYPE;
  }
  return soap->error;
}
#endif

/******************************************************************************/
#ifndef WITH_LEAN
SOAP_FMAC1
ULONG64 *
SOAP_FMAC2
soap_inULONG64(struct soap *soap, const char *tag, ULONG64 *p, const char *type, int t)
{ if (soap_element_begin_in(soap, tag, 0, NULL))
    return NULL;
  if (*soap->type
   && soap_match_tag(soap, soap->type, type)
   && soap_match_tag(soap, soap->type, ":positiveInteger")
   && soap_match_tag(soap, soap->type, ":nonNegativeInteger")
   && soap_match_tag(soap, soap->type, ":unsignedLong")
   && soap_match_tag(soap, soap->type, ":unsignedInt")
   && soap_match_tag(soap, soap->type, ":unsignedShort")
   && soap_match_tag(soap, soap->type, ":unsignedByte"))
  { soap->error = SOAP_TYPE;
    soap_revert(soap);
    return NULL;
  }
  p = (ULONG64*)soap_id_enter(soap, soap->id, p, t, sizeof(ULONG64), 0, NULL, NULL, NULL);
  if (*soap->href)
    p = (ULONG64*)soap_id_forward(soap, soap->href, p, 0, t, 0, sizeof(ULONG64), 0, NULL);
  else if (p)
  { if (soap_s2ULONG64(soap, soap_value(soap), p))
      return NULL;
  }
  if (soap->body && soap_element_end_in(soap, tag))
    return NULL;
  return p;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_s2string(struct soap *soap, const char *s, char **t, long minlen, long maxlen)
{ if (s)
  { long l = (long)strlen(s);
    if ((maxlen >= 0 && l > maxlen) || l < minlen)
      return soap->error = SOAP_LENGTH;
    if (!(*t = soap_strdup(soap, s)))
      return soap->error = SOAP_EOM;
    if (!(soap->mode & (SOAP_ENC_LATIN | SOAP_C_UTFSTRING)))
    { char *r = *t;
      /* remove non-ASCII chars */
      for (s = *t; *s; s++)
        if (!(*s & 0x80))
	  *r++ = *s;
      *r = '\0';
    }
  }
  return soap->error;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_s2QName(struct soap *soap, const char *s, char **t, long minlen, long maxlen)
{ if (s)
  { long l = (long)strlen(s);
    if ((maxlen >= 0 && l > maxlen) || l < minlen)
      return soap->error = SOAP_LENGTH;
    soap->labidx = 0;
    DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Normalized namespace(s) of QNames '%s'", s));
    /* convert (by prefix normalize prefix) all QNames in s */
    for (;;)
    { size_t n;
      struct soap_nlist *np;
      register const char *p;
      /* skip blanks */
      while (*s && soap_blank((soap_wchar)*s))
        s++;
      if (!*s)
        break;
      /* find next QName */
      n = 1;
      while (s[n] && !soap_blank(s[n]))
        n++;
      np = soap->nlist;
      /* if there is no namespace stack, or prefix is "xml" then copy string */
      if (!np || !strncmp(s, "xml:", 4))
      { soap_append_lab(soap, s, n);
      }
      else /* we normalize the QName by replacing its prefix */
      { const char *q;
        for (p = s; *p && p < s + n; p++)
          if (*p == ':')
	    break;
        if (*p == ':')
        { size_t k = p - s;
          while (np && (strncmp(np->id, s, k) || np->id[k]))
            np = np->next;
          p++;
        }
        else
        { while (np && *np->id)
            np = np->next;
          p = s;
        }
        /* replace prefix */
        if (np)
        { if (np->index >= 0 && soap->local_namespaces && (q = soap->local_namespaces[np->index].id))
          { size_t k = strlen(q);
	    if (q[k-1] != '_')
	      soap_append_lab(soap, q, k);
	    else
            { soap_append_lab(soap, "\"", 1);
              soap_append_lab(soap, soap->local_namespaces[np->index].ns, strlen(soap->local_namespaces[np->index].ns));
              soap_append_lab(soap, "\"", 1);
	    }
	  }
          else if (np->ns)
          { soap_append_lab(soap, "\"", 1);
            soap_append_lab(soap, np->ns, strlen(np->ns));
            soap_append_lab(soap, "\"", 1);
          }
          else
          { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "\nNamespace prefix of '%s' not defined (index=%d, URI=%s)\n", s, np->index, np->ns?np->ns:SOAP_STR_EOS));
            return soap->error = SOAP_NAMESPACE; 
          }
        }
        else if (s[n]) /* no namespace, part of string */
        { soap_append_lab(soap, s, n);
        } 
	else /* no namespace: assume "" namespace */
        { soap_append_lab(soap, "\"\"", 2);
	}
        soap_append_lab(soap, ":", 1);
        soap_append_lab(soap, p, n - (p-s));
      }
      /* advance to next and add spacing */
      s += n;
      if (*s)
        soap_append_lab(soap, " ", 1);
    }
    soap_append_lab(soap, SOAP_STR_EOS, 1);
    *t = soap_strdup(soap, soap->labbuf);
    DBGLOG(TEST, SOAP_MESSAGE(fdebug, " into '%s'\n", *t));
  }
  return soap->error;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
const char*
SOAP_FMAC2
soap_QName2s(struct soap *soap, const char *s)
{ const char *t = NULL;
  if (s)
  { soap->labidx = 0;
    for (;;)
    { size_t n;
      /* skip blanks */
      while (*s && soap_blank((soap_wchar)*s))
        s++;
      if (!*s)
        break;
      /* find next QName */
      n = 1;
      while (s[n] && !soap_blank((soap_wchar)s[n]))
        n++;
      /* normal prefix: pass string as is */
      if (*s != '"')
      { soap_append_lab(soap, s, n);
#ifndef WITH_LEAN
        if ((soap->mode & SOAP_XML_CANONICAL))
        { const char *r = strchr(s, ':');
          if (r)
            soap_utilize_ns(soap, s, r - s);
        }
#endif
      }
      else /* URL-based string prefix */
      { const char *q;
        s++;
        q = strchr(s, '"');
        if (q)
        { struct Namespace *p = soap->local_namespaces;
          if (p)
          { for (; p->id; p++)
            { if (p->ns)
                if (!soap_tag_cmp(s, p->ns))
                  break;
              if (p->in)
                if (!soap_tag_cmp(s, p->in))
                  break;
            }
          }
          /* URL is in the namespace table? */
          if (p && p->id)
          { soap_append_lab(soap, p->id, strlen(p->id));
          }
          else /* not in namespace table: create xmlns binding */
          { char *r = soap_strdup(soap, s);
            r[q-s] = '\0';
            sprintf(soap->tmpbuf, "xmlns:_%d", soap->idnum++);
            soap_set_attr(soap, soap->tmpbuf, r, 1);
            soap_append_lab(soap, soap->tmpbuf + 6, strlen(soap->tmpbuf + 6));
          }
          soap_append_lab(soap, q + 1, n - (q-s) - 1);
        }
      }
      /* advance to next and add spacing */
      s += n;
      if (*s)
        soap_append_lab(soap, " ", 1);
    }
    soap_append_lab(soap, SOAP_STR_EOS, 1);
    t = soap_strdup(soap, soap->labbuf);
  }
  return t;
}
#endif

/******************************************************************************/
#ifndef WITH_LEAN
SOAP_FMAC1
int
SOAP_FMAC2
soap_s2wchar(struct soap *soap, const char *s, wchar_t **t, long minlen, long maxlen)
{ if (s)
  { long l;
    wchar_t *r;
    *t = r = (wchar_t*)soap_malloc(soap, sizeof(wchar_t) * (strlen(s) + 1));
    if (!r)
      return soap->error = SOAP_EOM;
    if (soap->mode & SOAP_ENC_LATIN)
    { while (*s)
        *r++ = (wchar_t)*s++;
    }
    else
    { /* Convert UTF8 to wchar */
      while (*s)
      { register soap_wchar c, c1, c2, c3, c4;
        c = (unsigned char)*s++;
        if (c < 0x80)
          *r++ = (wchar_t)c;
        else
        { c1 = (soap_wchar)*s++ & 0x3F;
          if (c < 0xE0)
            *r++ = (wchar_t)(((soap_wchar)(c & 0x1F) << 6) | c1);
          else
          { c2 = (soap_wchar)*s++ & 0x3F;
            if (c < 0xF0)
              *r++ = (wchar_t)(((soap_wchar)(c & 0x0F) << 12) | (c1 << 6) | c2);
            else
            { c3 = (soap_wchar)*s++ & 0x3F;
              if (c < 0xF8)
                *r++ = (wchar_t)(((soap_wchar)(c & 0x07) << 18) | (c1 << 12) | (c2 << 6) | c3);
              else
              { c4 = (soap_wchar)*s++ & 0x3F;
                if (c < 0xFC)
                  *r++ = (wchar_t)(((soap_wchar)(c & 0x03) << 24) | (c1 << 18) | (c2 << 12) | (c3 << 6) | c4);
                else
                  *r++ = (wchar_t)(((soap_wchar)(c & 0x01) << 30) | (c1 << 24) | (c2 << 18) | (c3 << 12) | (c4 << 6) | (soap_wchar)(*s++ & 0x3F));
              }
            }
          }
        }
      }
    }
    *r = L'\0';
    l = (long)(r - *t);
    if ((maxlen >= 0 && l > maxlen) || l < minlen)
      return soap->error = SOAP_LENGTH;
  }
  return soap->error;
}
#endif

/******************************************************************************/
#ifndef WITH_LEAN
SOAP_FMAC1
const char*
SOAP_FMAC2
soap_wchar2s(struct soap *soap, const wchar_t *s)
{ register soap_wchar c;
  register char *r, *t;
  const wchar_t *q = s;
  size_t n = 0;
  while ((c = *q++))
  { if (c > 0 && c < 0x80)
      n++;
    else
      n += 6;
  }
  r = t = (char*)soap_malloc(soap, n + 1);
  if (r)
  { /* Convert wchar to UTF8 */
    while ((c = *s++))
    { if (c > 0 && c < 0x80)
        *t++ = (char)c;
      else
      { if (c < 0x0800)
          *t++ = (char)(0xC0 | ((c >> 6) & 0x1F));
        else
        { if (c < 0x010000)
            *t++ = (char)(0xE0 | ((c >> 12) & 0x0F));
          else
          { if (c < 0x200000)
              *t++ = (char)(0xF0 | ((c >> 18) & 0x07));
            else
            { if (c < 0x04000000)
                *t++ = (char)(0xF8 | ((c >> 24) & 0x03));
              else
              { *t++ = (char)(0xFC | ((c >> 30) & 0x01));
                *t++ = (char)(0x80 | ((c >> 24) & 0x3F));
              }
              *t++ = (char)(0x80 | ((c >> 18) & 0x3F));
            }     
            *t++ = (char)(0x80 | ((c >> 12) & 0x3F));
          }
          *t++ = (char)(0x80 | ((c >> 6) & 0x3F));
        }
        *t++ = (char)(0x80 | (c & 0x3F));
      }
    }
    *t = '\0';
  }
  return r;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_outstring(struct soap *soap, const char *tag, int id, char *const*p, const char *type, int n) 
{ id = soap_element_id(soap, tag, id, *p, NULL, 0, type, n);
  if (id < 0)
    return soap->error;
  if (!**p && (soap->mode & SOAP_C_NILSTRING))
    return soap_element_null(soap, tag, id, type);
  if (soap_element_begin_out(soap, tag, id, type)
   || soap_string_out(soap, *p, 0)
   || soap_element_end_out(soap, tag))
    return soap->error;
  return SOAP_OK;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
char **
SOAP_FMAC2
soap_instring(struct soap *soap, const char *tag, char **p, const char *type, int t, int flag, long minlen, long maxlen)
{ if (soap_element_begin_in(soap, tag, 1, NULL))
  { if (!tag || *tag != '-' || soap->error != SOAP_NO_TAG)
      return NULL;
    soap->error = SOAP_OK;
  }
  if (!p)
  { if (!(p = (char**)soap_malloc(soap, sizeof(char*))))
      return NULL;
  }
  if (soap->null)
    *p = NULL;
  else if (soap->body)
  { *p = soap_string_in(soap, flag, minlen, maxlen);
    if (!*p || !(char*)soap_id_enter(soap, soap->id, *p, t, sizeof(char*), 0, NULL, NULL, NULL))
      return NULL;
    if (!**p && tag && *tag == '-')
    { soap->error = SOAP_NO_TAG;
      return NULL;
    }
  }
  else if (tag && *tag == '-')
  { soap->error = SOAP_NO_TAG;
    return NULL;
  }
  else if (!*soap->href && minlen > 0)
  { soap->error = SOAP_LENGTH;
    return NULL;
  }
  else
    *p = soap_strdup(soap, SOAP_STR_EOS);
  if (*soap->href)
    p = (char**)soap_id_lookup(soap, soap->href, (void**)p, t, sizeof(char**), 0);
  if (soap->body && soap_element_end_in(soap, tag))
    return NULL;
  return p;
}
#endif

/******************************************************************************/
#ifndef WITH_LEANER
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_outwstring(struct soap *soap, const char *tag, int id, wchar_t *const*p, const char *type, int n) 
{ id = soap_element_id(soap, tag, id, *p, NULL, 0, type, n);
  if (id < 0)
    return soap->error;
  if (!**p && (soap->mode & SOAP_C_NILSTRING))
    return soap_element_null(soap, tag, id, type);
  if (soap_element_begin_out(soap, tag, id, type)
   || soap_wstring_out(soap, *p, 0)
   || soap_element_end_out(soap, tag))
    return soap->error;
  return SOAP_OK;
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_LEANER
#ifndef PALM_2
SOAP_FMAC1
wchar_t **
SOAP_FMAC2
soap_inwstring(struct soap *soap, const char *tag, wchar_t **p, const char *type, int t, long minlen, long maxlen)
{ if (soap_element_begin_in(soap, tag, 1, NULL))
  { if (!tag || *tag != '-' || soap->error != SOAP_NO_TAG)
      return NULL;
    soap->error = SOAP_OK;
  }
  if (!p)
  { if (!(p = (wchar_t**)soap_malloc(soap, sizeof(wchar_t*))))
      return NULL;
  }
  if (soap->body)
  { *p = soap_wstring_in(soap, 1, minlen, maxlen);
    if (!*p || !(wchar_t*)soap_id_enter(soap, soap->id, *p, t, sizeof(wchar_t*), 0, NULL, NULL, NULL))
      return NULL;
    if (!**p && tag && *tag == '-')
    { soap->error = SOAP_NO_TAG;
      return NULL;
    }
  }
  else if (tag && *tag == '-')
  { soap->error = SOAP_NO_TAG;
    return NULL;
  }
  else if (soap->null)
    *p = NULL;
  else
    *p = soap_wstrdup(soap, (wchar_t*)SOAP_STR_EOS);
  if (*soap->href)
    p = (wchar_t**)soap_id_lookup(soap, soap->href, (void**)p, t, sizeof(wchar_t**), 0);
  if (soap->body && soap_element_end_in(soap, tag))
    return NULL;
  return p;
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_LEAN
SOAP_FMAC1
time_t
SOAP_FMAC2
soap_timegm(struct tm *T)
{
#if defined(HAVE_TIMEGM)
  return timegm(T);
#else
  time_t t, g, z;
  struct tm tm;
  t = mktime(T);
  if (t == (time_t)-1)
    return (time_t)-1;
#ifdef HAVE_GMTIME_R
  gmtime_r(&t, &tm);
#else
  tm = *gmtime(&t);
#endif
  tm.tm_isdst = 0;
  g = mktime(&tm);
  if (g == (time_t)-1)
    return (time_t)-1;
  z = g - t;
  return t - z;
#endif
}
#endif

/******************************************************************************/
#ifndef WITH_LEAN
SOAP_FMAC1
const char*
SOAP_FMAC2
soap_dateTime2s(struct soap *soap, time_t n)
{ struct tm T, *pT = &T;
#if defined(HAVE_GMTIME_R)
  if (gmtime_r(&n, pT))
    strftime(soap->tmpbuf, sizeof(soap->tmpbuf), "%Y-%m-%dT%H:%M:%SZ", pT);
#elif defined(HAVE_GMTIME)
  if ((pT = gmtime(&n)))
    strftime(soap->tmpbuf, sizeof(soap->tmpbuf), "%Y-%m-%dT%H:%M:%SZ", pT);
#elif defined(HAVE_GETTIMEOFDAY)
  struct timezone tz;
  memset((void*)&tz, 0, sizeof(tz));
#if defined(HAVE_LOCALTIME_R)
  if (localtime_r(&n, pT))
  { struct timeval tv;
    gettimeofday(&tv, &tz);
    strftime(soap->tmpbuf, sizeof(soap->tmpbuf), "%Y-%m-%dT%H:%M:%S", pT);
    sprintf(soap->tmpbuf + strlen(soap->tmpbuf), "%+03d:%02d", -tz.tz_minuteswest/60+(pT->tm_isdst!=0), abs(tz.tz_minuteswest)%60);
  }
#else
  if ((pT = localtime(&n)))
  { struct timeval tv;
    gettimeofday(&tv, &tz);
    strftime(soap->tmpbuf, sizeof(soap->tmpbuf), "%Y-%m-%dT%H:%M:%S", pT);
    sprintf(soap->tmpbuf + strlen(soap->tmpbuf), "%+03d:%02d", -tz.tz_minuteswest/60+(pT->tm_isdst!=0), abs(tz.tz_minuteswest)%60);
  }
#endif
#elif defined(HAVE_FTIME)
  struct timeb t;
  memset((void*)&t, 0, sizeof(t));
#if defined(HAVE_LOCALTIME_R)
  if (localtime_r(&n, pT))
  {
#ifdef __BORLANDC__
    ::ftime(&t);
#else
    ftime(&t);
#endif
    strftime(soap->tmpbuf, sizeof(soap->tmpbuf), "%Y-%m-%dT%H:%M:%S", pT);
    sprintf(soap->tmpbuf + strlen(soap->tmpbuf), "%+03d:%02d", -t.timezone/60+(pT->tm_isdst!=0), abs(t.timezone)%60);
  }
#else
  if ((pT = localtime(&n)))
  {
#ifdef __BORLANDC__
    ::ftime(&t);
#else
    ftime(&t);
#endif
    strftime(soap->tmpbuf, sizeof(soap->tmpbuf), "%Y-%m-%dT%H:%M:%S", pT);
    sprintf(soap->tmpbuf + strlen(soap->tmpbuf), "%+03d:%02d", -t.timezone/60+(pT->tm_isdst!=0), abs(t.timezone)%60);
  }
#endif
#elif defined(HAVE_LOCALTIME_R)
  if (localtime_r(&n, pT))
    strftime(soap->tmpbuf, sizeof(soap->tmpbuf), "%Y-%m-%dT%H:%M:%S", pT);
#else
  if ((pT = localtime(&n)))
    strftime(soap->tmpbuf, sizeof(soap->tmpbuf), "%Y-%m-%dT%H:%M:%S", pT);
#endif
  else
    strcpy(soap->tmpbuf, "1969-12-31T23:59:59Z");
  return soap->tmpbuf;
}
#endif

/******************************************************************************/
#ifndef WITH_LEAN
SOAP_FMAC1
int
SOAP_FMAC2
soap_outdateTime(struct soap *soap, const char *tag, int id, const time_t *p, const char *type, int n)
{ if (soap_element_begin_out(soap, tag, soap_embedded_id(soap, id, p, n), type)
   || soap_string_out(soap, soap_dateTime2s(soap, *p), 0))
    return soap->error;
  return soap_element_end_out(soap, tag);
}
#endif

/******************************************************************************/
#ifndef WITH_LEAN
SOAP_FMAC1
int
SOAP_FMAC2
soap_s2dateTime(struct soap *soap, const char *s, time_t *p)
{ if (s)
  { char zone[32];
    struct tm T;
    const char *t;
    *zone = '\0';
    memset((void*)&T, 0, sizeof(T));
    if (strchr(s, '-'))
      t = "%d-%d-%dT%d:%d:%d%31s";
    else if (strchr(s, ':'))
      t = "%4d%2d%2dT%d:%d:%d%31s";
    else /* parse non-XSD-standard alternative ISO 8601 format */
      t = "%4d%2d%2dT%2d%2d%2d%31s";
    if (sscanf(s, t, &T.tm_year, &T.tm_mon, &T.tm_mday, &T.tm_hour, &T.tm_min, &T.tm_sec, zone) < 6)
      return soap->error = SOAP_TYPE;
    if (T.tm_year == 1)
      T.tm_year = 70;
    else
      T.tm_year -= 1900;
    T.tm_mon--;
    if (*zone == '.')
    { for (s = zone + 1; *s; s++)
        if (*s < '0' || *s > '9')
          break;
    }
    else
      s = zone;
    if (*s)
    {
#ifndef WITH_NOZONE
      if (*s == '+' || *s == '-')
      { int h = 0, m = 0;
        if (s[3] == ':')
        { /* +hh:mm */
	  sscanf(s, "%d:%d", &h, &m);
          if (h < 0)
            m = -m;
        }
        else /* +hhmm */
        { m = (int)soap_strtol(s, NULL, 10);
          h = m / 100;
          m = m % 100;
        }
	T.tm_min -= m;
	T.tm_hour -= h;
	/* put hour and min in range */
        T.tm_hour += T.tm_min / 60;
        T.tm_min %= 60;
        if (T.tm_min < 0)
        { T.tm_min += 60;
	  T.tm_hour--;
	}
        T.tm_mday += T.tm_hour / 24;
        T.tm_hour %= 24;
        if (T.tm_hour < 0)
        { T.tm_hour += 24;
          T.tm_mday--;
	}
	/* note: day of the month may be out of range, timegm() handles it */
      }
#endif
      *p = soap_timegm(&T);
    }
    else /* no UTC or timezone, so assume we got a localtime */
    { T.tm_isdst = -1;
      *p = mktime(&T);
    }
  }
  return soap->error;
}
#endif

/******************************************************************************/
#ifndef WITH_LEAN
SOAP_FMAC1
time_t *
SOAP_FMAC2
soap_indateTime(struct soap *soap, const char *tag, time_t *p, const char *type, int t)
{ if (soap_element_begin_in(soap, tag, 0, NULL))
    return NULL;
  if (*soap->type
   && soap_match_tag(soap, soap->type, type)
   && soap_match_tag(soap, soap->type, ":dateTime"))
  { soap->error = SOAP_TYPE;
    soap_revert(soap);
    return NULL;
  }
  p = (time_t*)soap_id_enter(soap, soap->id, p, t, sizeof(time_t), 0, NULL, NULL, NULL);
  if (*soap->href)
    p = (time_t*)soap_id_forward(soap, soap->href, p, 0, t, 0, sizeof(time_t), 0, NULL);
  else if (p)
  { if (soap_s2dateTime(soap, soap_value(soap), p))
      return NULL;
  }
  if (soap->body && soap_element_end_in(soap, tag))
    return NULL;
  return p;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_outliteral(struct soap *soap, const char *tag, char *const*p, const char *type)
{ int i;
  const char *t = NULL;
  if (tag && *tag != '-')
  { if (soap->local_namespaces && (t = strchr(tag, ':')))
    { strncpy(soap->tmpbuf, tag, t-tag);
      soap->tmpbuf[t-tag] = '\0';
      for (i = 0; soap->local_namespaces[i].id; i++)
        if (!strcmp(soap->tmpbuf, soap->local_namespaces[i].id))
          break;
      t++;
      if (soap_element(soap, t, 0, type)
       || soap_attribute(soap, "xmlns", soap->local_namespaces[i].ns ? soap->local_namespaces[i].ns : SOAP_STR_EOS)
       || soap_element_start_end_out(soap, NULL))
        return soap->error;
    }
    else
    { t = tag;
      if (soap_element_begin_out(soap, t, 0, type))
        return soap->error;
    }
  }
  if (p && *p)
  { if (soap_send(soap, *p))
      return soap->error;
  }
  if (t)
    return soap_element_end_out(soap, t);
  return SOAP_OK;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
char **
SOAP_FMAC2
soap_inliteral(struct soap *soap, const char *tag, char **p)
{ if (soap_element_begin_in(soap, tag, 1, NULL))
  { if (soap->error != SOAP_NO_TAG || soap_unget(soap, soap_get(soap)) == SOAP_TT)
      return NULL;
    soap->error = SOAP_OK;
  }
  if (!p)
  { if (!(p = (char**)soap_malloc(soap, sizeof(char*))))
      return NULL;
  }
  if (soap->body || (tag && *tag == '-'))
  { *p = soap_string_in(soap, 0, -1, -1);
    if (!*p)
      return NULL;
    if (!**p && tag && *tag == '-')
    { soap->error = SOAP_NO_TAG;
      return NULL;
    }
  }
  else if (soap->null)
    *p = NULL;
  else
    *p = soap_strdup(soap, SOAP_STR_EOS);
  if (soap->body && soap_element_end_in(soap, tag))
    return NULL;
  return p;
}
#endif

/******************************************************************************/
#ifndef WITH_LEANER
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_outwliteral(struct soap *soap, const char *tag, wchar_t *const*p, const char *type)
{ int i;
  const char *t = NULL;
  if (tag && *tag != '-')
  { if (soap->local_namespaces && (t = strchr(tag, ':')))
    { strncpy(soap->tmpbuf, tag, t-tag);
      soap->tmpbuf[t-tag] = '\0';
      for (i = 0; soap->local_namespaces[i].id; i++)
        if (!strcmp(soap->tmpbuf, soap->local_namespaces[i].id))
          break;
      t++;
      if (soap_element(soap, t, 0, type)
       || soap_attribute(soap, "xmlns", soap->local_namespaces[i].ns ? soap->local_namespaces[i].ns : SOAP_STR_EOS)
       || soap_element_start_end_out(soap, NULL))
        return soap->error;
    }
    else
    { t = tag;
      if (soap_element_begin_out(soap, t, 0, type))
        return soap->error;
    }
    if (soap_send(soap, soap->tmpbuf))
      return soap->error;
  }
  if (p)
  { wchar_t c;
    const wchar_t *s = *p;
    while ((c = *s++))
    { if (soap_pututf8(soap, (unsigned long)c))
        return soap->error;
    }
  }
  if (t)
    return soap_element_end_out(soap, t);
  return SOAP_OK;
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_LEANER
#ifndef PALM_2
SOAP_FMAC1
wchar_t **
SOAP_FMAC2
soap_inwliteral(struct soap *soap, const char *tag, wchar_t **p)
{ if (soap_element_begin_in(soap, tag, 1, NULL))
  { if (soap->error != SOAP_NO_TAG || soap_unget(soap, soap_get(soap)) == SOAP_TT)
      return NULL;
    soap->error = SOAP_OK;
  }
  if (!p)
  { if (!(p = (wchar_t**)soap_malloc(soap, sizeof(wchar_t*))))
      return NULL;
  }
  if (soap->body)
  { *p = soap_wstring_in(soap, 0, -1, -1);
    if (!*p)
      return NULL;
    if (!**p && tag && *tag == '-')
    { soap->error = SOAP_NO_TAG;
      return NULL;
    }
  }
  else if (tag && *tag == '-')
  { soap->error = SOAP_NO_TAG;
    return NULL;
  }
  else if (soap->null)
    *p = NULL;
  else
    *p = soap_wstrdup(soap, (wchar_t*)SOAP_STR_EOS);
  if (soap->body && soap_element_end_in(soap, tag))
    return NULL;
  return p;
}
#endif
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
const char *
SOAP_FMAC2
soap_value(struct soap *soap)
{ register size_t i;
  register soap_wchar c = 0;
  register char *s = soap->tmpbuf;
  if (!soap->body)
    return SOAP_STR_EOS;
  do c = soap_get(soap);
  while (soap_blank(c));
  for (i = 0; i < sizeof(soap->tmpbuf) - 1; i++)
  { if (c == SOAP_TT || c == SOAP_LT || (int)c == EOF)
      break;
    *s++ = (char)c;
    c = soap_get(soap);
  }
  for (s--; i > 0; i--, s--)
  { if (!soap_blank((soap_wchar)*s))
      break;
  }
  s[1] = '\0';
  DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Element content value='%s'\n", soap->tmpbuf));
  if (c == SOAP_TT || c == SOAP_LT || (int)c == EOF)
    soap_unget(soap, c);
  else if (soap->mode & SOAP_XML_STRICT)
  { soap->error = SOAP_LENGTH;
    return NULL;
  }
#ifdef WITH_DOM
  if ((soap->mode & SOAP_XML_DOM) && soap->dom)
    soap->dom->data = soap_strdup(soap, soap->tmpbuf);
#endif
  return soap->tmpbuf; /* return non-null pointer */
}
#endif

/******************************************************************************/
#if !defined(WITH_LEANER) || !defined(WITH_NOHTTP)
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_getline(struct soap *soap, char *s, int len)
{ int i = len;
  soap_wchar c = 0;
  for (;;)
  { while (--i > 0)
    { c = soap_getchar(soap);
      if (c == '\r' || c == '\n')
        break;
      if ((int)c == EOF)
        return soap->error = SOAP_EOF;
      *s++ = (char)c;
    }
    if (c != '\n')
      c = soap_getchar(soap); /* got \r or something else, now get \n */
    if (c == '\n')
    { *s = '\0';
      if (i+1 == len) /* empty line: end of HTTP/MIME header */
        break;
      c = soap_get0(soap);
      if (c != ' ' && c != '\t') /* HTTP line continuation? */
        break;
    }
    else if ((int)c == EOF)
      return soap->error = SOAP_EOF;
    if (i < 0)
      return soap->error = SOAP_HDR;
  }
  return SOAP_OK;
}
#endif
#endif

/******************************************************************************/
#ifndef PALM_1
static size_t
soap_count_attachments(struct soap *soap)
{ 
#ifndef WITH_LEANER
  register struct soap_multipart *content;
  register size_t count = soap->count;
  DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Calculating the message size with attachments, current count=%lu\n", (unsigned long)count));
  if ((soap->mode & SOAP_ENC_DIME) && !(soap->mode & SOAP_ENC_MTOM))
  { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Calculating the size of DIME attachments\n"));
    for (content = soap->dime.first; content; content = content->next)
    { count += 12 + ((content->size+3)&(~3));
      if (content->id)
        count += ((strlen(content->id)+3)&(~3));
      if (content->type)
        count += ((strlen(content->type)+3)&(~3));
      if (content->options)
        count += ((((unsigned char)content->options[2] << 8) | ((unsigned char)content->options[3]))+7)&(~3);
      DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Size of DIME attachment content is %lu bytes\n", (unsigned long)content->size));
    }
  }
  if ((soap->mode & SOAP_ENC_MIME) && soap->mime.boundary)
  { register size_t n = strlen(soap->mime.boundary);
    DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Calculating the size of MIME attachments\n"));
    for (content = soap->mime.first; content; content = content->next)
    { register const char *s;
      /* count \r\n--boundary\r\n */
      count += 6 + n;
      /* count Content-Type: ...\r\n */
      if (content->type)
        count += 16 + strlen(content->type);
      /* count Content-Transfer-Encoding: ...\r\n */
      s = soap_code_str(mime_codes, content->encoding);
      if (s)
        count += 29 + strlen(s);
      /* count Content-ID: ...\r\n */
      if (content->id)
        count += 14 + strlen(content->id);
      /* count Content-Location: ...\r\n */
      if (content->location)
        count += 20 + strlen(content->location);
      /* count Content-Description: ...\r\n */
      if (content->description)
        count += 23 + strlen(content->description);
      /* count \r\n...content */
      count += 2 + content->size;
      DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Size of MIME attachment content is %lu bytes\n", (unsigned long)content->size));
    }
    /* count \r\n--boundary-- */
    count += 6 + n;
  }
  DBGLOG(TEST, SOAP_MESSAGE(fdebug, "New count is %lu bytes\n", (unsigned long)count));
  return count;
#else
  return soap->count;
#endif
}
#endif

/******************************************************************************/
#ifndef WITH_LEANER
#ifndef PALM_1
static int
soap_putdimefield(struct soap *soap, const char *s, size_t n)
{ if (soap_send_raw(soap, s, n))
    return soap->error;
  return soap_send_raw(soap, SOAP_STR_PADDING, -(long)n&3);
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_LEANER
#ifndef PALM_1
SOAP_FMAC1
char *
SOAP_FMAC2
soap_dime_option(struct soap *soap, unsigned short optype, const char *option)
{ size_t n;
  char *s = NULL;
  if (option)
  { n = strlen(option);
    s = (char*)soap_malloc(soap, n + 5);
    if (s)
    { s[0] = (char)(optype >> 8);
      s[1] = (char)(optype & 0xFF);
      s[2] = (char)(n >> 8);
      s[3] = (char)(n & 0xFF);
      strcpy(s + 4, option);
    }
  }
  return s;
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_LEANER
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_putdimehdr(struct soap *soap)
{ unsigned char tmp[12];
  size_t optlen = 0, idlen = 0, typelen = 0;
  DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Put DIME header id='%s'\n", soap->dime.id?soap->dime.id:SOAP_STR_EOS));
  if (soap->dime.options)
    optlen = (((unsigned char)soap->dime.options[2] << 8) | ((unsigned char)soap->dime.options[3])) + 4;
  if (soap->dime.id)
  { idlen = strlen(soap->dime.id);
    if (idlen > 0x0000FFFF)
      idlen = 0x0000FFFF;
  }
  if (soap->dime.type)
  { typelen = strlen(soap->dime.type);
    if (typelen > 0x0000FFFF)
      typelen = 0x0000FFFF;
  }
  tmp[0] = SOAP_DIME_VERSION | (soap->dime.flags & 0x7);
  tmp[1] = soap->dime.flags & 0xF0;
  tmp[2] = (char)(optlen >> 8);
  tmp[3] = (char)(optlen & 0xFF);
  tmp[4] = (char)(idlen >> 8);
  tmp[5] = (char)(idlen & 0xFF);
  tmp[6] = (char)(typelen >> 8);
  tmp[7] = (char)(typelen & 0xFF);
  tmp[8] = (char)(soap->dime.size >> 24);
  tmp[9] = (char)((soap->dime.size >> 16) & 0xFF);
  tmp[10] = (char)((soap->dime.size >> 8) & 0xFF);
  tmp[11] = (char)(soap->dime.size & 0xFF);
  if (soap_send_raw(soap, (char*)tmp, 12)
   || soap_putdimefield(soap, soap->dime.options, optlen)
   || soap_putdimefield(soap, soap->dime.id, idlen)
   || soap_putdimefield(soap, soap->dime.type, typelen))
    return soap->error;
  return SOAP_OK;
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_LEANER
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_putdime(struct soap *soap)
{ struct soap_multipart *content;
  if (!(soap->mode & SOAP_ENC_DIME))
    return SOAP_OK;
  for (content = soap->dime.first; content; content = content->next)
  { void *handle;
    soap->dime.size = content->size;
    soap->dime.id = content->id;
    soap->dime.type = content->type;
    soap->dime.options = content->options;
    soap->dime.flags = SOAP_DIME_VERSION | SOAP_DIME_MEDIA;
    if (soap->fdimereadopen && ((handle = soap->fdimereadopen(soap, (void*)content->ptr, content->id, content->type, content->options)) || soap->error))
    { size_t size = content->size;
      if (!handle)
      { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "fdimereadopen failed\n"));
        return soap->error;
      }
      if (!size && ((soap->mode & SOAP_ENC_XML) || (soap->mode & SOAP_IO) == SOAP_IO_CHUNK || (soap->mode & SOAP_IO) == SOAP_IO_STORE))
      { size_t chunksize = sizeof(soap->tmpbuf);
        DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Chunked streaming DIME\n"));
        do 
        { size = soap->fdimeread(soap, handle, soap->tmpbuf, chunksize);
          DBGLOG(TEST, SOAP_MESSAGE(fdebug, "fdimeread returned %lu bytes\n", (unsigned long)size));
          if (size < chunksize)
          { soap->dime.flags &= ~SOAP_DIME_CF;
            if (!content->next)
              soap->dime.flags |= SOAP_DIME_ME;
          }
          else
            soap->dime.flags |= SOAP_DIME_CF;
          soap->dime.size = size;
          if (soap_putdimehdr(soap)
           || soap_putdimefield(soap, soap->tmpbuf, size))
            break;
          if (soap->dime.id)
          { soap->dime.flags &= ~(SOAP_DIME_MB | SOAP_DIME_MEDIA);
            soap->dime.id = NULL;
            soap->dime.type = NULL;
            soap->dime.options = NULL;
          }  
        } while (size >= chunksize);
      }
      else
      { if (!content->next)
          soap->dime.flags |= SOAP_DIME_ME;
        if (soap_putdimehdr(soap))
          return soap->error;
        do
        { size_t bufsize;
          if (size < sizeof(soap->tmpbuf))
            bufsize = size;
          else
            bufsize = sizeof(soap->tmpbuf);
          if (!(bufsize = soap->fdimeread(soap, handle, soap->tmpbuf, bufsize)))
          { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "fdimeread failed: insufficient data (%lu bytes remaining from %lu bytes)\n", (unsigned long)size, (unsigned long)content->size));
            soap->error = SOAP_EOF;
            break;
          }
          if (soap_send_raw(soap, soap->tmpbuf, bufsize))
            break;
          size -= bufsize;
        } while (size);
        DBGLOG(TEST, SOAP_MESSAGE(fdebug, "fdimereadclose\n"));
        soap_send_raw(soap, SOAP_STR_PADDING, -(long)soap->dime.size&3);
      }
      DBGLOG(TEST, SOAP_MESSAGE(fdebug, "fdimereadclose\n"));
      if (soap->fdimereadclose)
        soap->fdimereadclose(soap, handle);
    }
    else
    { if (!content->next)
        soap->dime.flags |= SOAP_DIME_ME;
      if (soap_putdimehdr(soap)
       || soap_putdimefield(soap, (char*)content->ptr, content->size))
        return soap->error;
    }
  }
  return SOAP_OK;
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_LEANER
#ifndef PALM_1
static char *
soap_getdimefield(struct soap *soap, size_t n)
{ register soap_wchar c;
  register size_t i;
  register char *s;
  register char *p = NULL;
  if (n)
  { p = (char*)soap_malloc(soap, n + 1);
    if (p)
    { s = p;
      for (i = n; i > 0; i--)
      { if ((int)(c = soap_get1(soap)) == EOF)
        { soap->error = SOAP_EOF;
          return NULL;
        }
        *s++ = (char)c;
      }
      *s = '\0';
      if ((soap->error = soap_move(soap, -(long)n&3)))
        return NULL;
    }
    else
      soap->error = SOAP_EOM;
  }
  return p;
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_LEANER
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_getdimehdr(struct soap *soap)
{ register soap_wchar c;
  register char *s;
  register int i;
  unsigned char tmp[12];
  size_t optlen, idlen, typelen;
  if (!(soap->mode & SOAP_ENC_DIME))
    return soap->error = SOAP_DIME_END;
  DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Get DIME header\n"));
  if (soap->dime.buflen || soap->dime.chunksize)
  { if (soap_move(soap, (long)(soap->dime.size - soap_tell(soap))))
      return soap->error = SOAP_EOF;
    soap_unget(soap, soap_getchar(soap)); /* skip padding and get hdr */
    DBGLOG(TEST, SOAP_MESSAGE(fdebug, "... From chunked\n"));
    return SOAP_OK;
  }
  s = (char*)tmp;
  for (i = 12; i > 0; i--)
  { if ((int)(c = soap_getchar(soap)) == EOF)
      return soap->error = SOAP_EOF;
    *s++ = (char)c;
  }
  if ((tmp[0] & 0xF8) != SOAP_DIME_VERSION)
    return soap->error = SOAP_DIME_MISMATCH;
  soap->dime.flags = (tmp[0] & 0x7) | (tmp[1] & 0xF0);
  optlen = (tmp[2] << 8) | tmp[3];
  idlen = (tmp[4] << 8) | tmp[5];
  typelen = (tmp[6] << 8) | tmp[7];
  soap->dime.size = (tmp[8] << 24) | (tmp[9] << 16) | (tmp[10] << 8) | tmp[11];
  DBGLOG(TEST, SOAP_MESSAGE(fdebug, "DIME size=%lu flags=0x%X\n", (unsigned long)soap->dime.size, soap->dime.flags));
  if (!(soap->dime.options = soap_getdimefield(soap, optlen)) && soap->error)
    return soap->error;
  if (!(soap->dime.id = soap_getdimefield(soap, idlen)) && soap->error)
    return soap->error;
  if (!(soap->dime.type = soap_getdimefield(soap, typelen)) && soap->error)
    return soap->error;
  DBGLOG(TEST, SOAP_MESSAGE(fdebug, "DIME id=%s, type=%s, options=%s\n", soap->dime.id?soap->dime.id:SOAP_STR_EOS, soap->dime.type?soap->dime.type:"", soap->dime.options?soap->dime.options+4:SOAP_STR_EOS));
  if (soap->dime.flags & SOAP_DIME_ME)
    soap->mode &= ~SOAP_ENC_DIME;
  return SOAP_OK;
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_LEANER
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_getdime(struct soap *soap)
{ while (soap->dime.flags & SOAP_DIME_CF)
  { if (soap_getdimehdr(soap))
      return soap->error;
    if (soap_move(soap, (long)soap->dime.size))
      return soap->error = SOAP_EOF;
  }
  if (soap_move(soap, (long)(((soap->dime.size+3)&(~3))-soap_tell(soap))))
    return soap->error = SOAP_EOF;
  for (;;)
  { register struct soap_multipart *content;
    if (soap_getdimehdr(soap))
      break;
    if (soap->fdimewriteopen && ((soap->dime.ptr = (char*)soap->fdimewriteopen(soap, soap->dime.id, soap->dime.type, soap->dime.options)) || soap->error))
    { const char *id, *type, *options;
      size_t size, n;
      if (!soap->dime.ptr)
        return soap->error;
      id = soap->dime.id;
      type = soap->dime.type;
      options = soap->dime.options;
      for (;;)
      { size = soap->dime.size;
        for (;;)
        { n = soap->buflen - soap->bufidx;
          if (size < n)
            n = size;
          if ((soap->error = soap->fdimewrite(soap, (void*)soap->dime.ptr, soap->buf + soap->bufidx, n)))
            break;
          size -= n;
          if (!size)
          { soap->bufidx += n;
            break;
          }
          if (soap_recv(soap))
          { soap->error = SOAP_EOF;
            goto end;
          }
        }
        if (soap_move(soap, -(long)soap->dime.size&3))
        { soap->error = SOAP_EOF;
          break;
        }
        if (!(soap->dime.flags & SOAP_DIME_CF))
          break;
        if (soap_getdimehdr(soap))
          break;
      }
end:
      if (soap->fdimewriteclose)
        soap->fdimewriteclose(soap, (void*)soap->dime.ptr);
      soap->dime.size = 0;
      soap->dime.id = id;
      soap->dime.type = type;
      soap->dime.options = options;
    }
    else if (soap->dime.flags & SOAP_DIME_CF)
    { const char *id, *type, *options;
      id = soap->dime.id;
      type = soap->dime.type;
      options = soap->dime.options;
      if (soap_new_block(soap) == NULL)
        return SOAP_EOM;
      for (;;)
      { register soap_wchar c;
        register size_t i;
        register char *s;
        s = (char*)soap_push_block(soap, NULL, soap->dime.size);
        if (!s)
          return soap->error = SOAP_EOM;
        for (i = soap->dime.size; i > 0; i--)
        { if ((int)(c = soap_get1(soap)) == EOF)
            return soap->error = SOAP_EOF;
          *s++ = (char)c;
        }
        if (soap_move(soap, -(long)soap->dime.size&3))
          return soap->error = SOAP_EOF;
        if (!(soap->dime.flags & SOAP_DIME_CF))
          break;
        if (soap_getdimehdr(soap))
          return soap->error;
      }
      soap->dime.size = soap->blist->size++; /* allocate one more for '\0' */
      if (!(soap->dime.ptr = soap_save_block(soap, NULL, NULL, 0)))
        return soap->error;
      soap->dime.ptr[soap->dime.size] = '\0'; /* force 0-terminated */
      soap->dime.id = id;
      soap->dime.type = type;
      soap->dime.options = options;
    }
    else
      soap->dime.ptr = soap_getdimefield(soap, soap->dime.size);
    content = soap_new_multipart(soap, &soap->dime.first, &soap->dime.last, soap->dime.ptr, soap->dime.size);
    if (!content)
      return soap->error = SOAP_EOM;
    content->id = soap->dime.id;
    content->type = soap->dime.type;
    content->options = soap->dime.options;
    if (soap->error)
      return soap->error;
    soap_resolve_attachment(soap, content);
  }
  if (soap->error != SOAP_DIME_END)
    return soap->error;
  return soap->error = SOAP_OK;
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_LEANER
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_getmimehdr(struct soap *soap)
{ struct soap_multipart *content;
  do
  { if (soap_getline(soap, soap->msgbuf, sizeof(soap->msgbuf)))
      return soap->error;
  }
  while (!*soap->msgbuf);
  if (soap->msgbuf[0] == '-' && soap->msgbuf[1] == '-')
  { char *s = soap->msgbuf + strlen(soap->msgbuf) - 1;
    /* remove white space */
    while (soap_blank((soap_wchar)*s))
      s--;
    s[1] = '\0';
    if (soap->mime.boundary)
    { if (strcmp(soap->msgbuf + 2, soap->mime.boundary))
        return soap->error = SOAP_MIME_ERROR;
    }
    else
      soap->mime.boundary = soap_strdup(soap, soap->msgbuf + 2);
    if (soap_getline(soap, soap->msgbuf, sizeof(soap->msgbuf)))
      return soap->error;
  }
  if (soap_set_mime_attachment(soap, NULL, 0, SOAP_MIME_NONE, NULL, NULL, NULL, NULL))
    return soap->error = SOAP_EOM;
  content = soap->mime.last;
  for (;;)
  { register char *key = soap->msgbuf;
    register char *val;
    if (!*key)
      break;
    DBGLOG(TEST,SOAP_MESSAGE(fdebug, "MIME header: %s\n", key));
    val = strchr(soap->msgbuf, ':');
    if (val)
    { *val = '\0';
      do val++;
      while (*val && *val <= 32);
      if (!soap_tag_cmp(key, "Content-ID"))
        content->id = soap_strdup(soap, val);
      else if (!soap_tag_cmp(key, "Content-Location"))
        content->location = soap_strdup(soap, val);
      else if (!soap_tag_cmp(key, "Content-Disposition"))
        content->id = soap_strdup(soap, soap_get_header_attribute(soap, val, "name"));
      else if (!soap_tag_cmp(key, "Content-Type"))
        content->type = soap_strdup(soap, val);
      else if (!soap_tag_cmp(key, "Content-Description"))
        content->description = soap_strdup(soap, val);
      else if (!soap_tag_cmp(key, "Content-Transfer-Encoding"))
        content->encoding = (enum soap_mime_encoding)soap_code_int(mime_codes, val, (long)SOAP_MIME_NONE);
    }
    if (soap_getline(soap, key, sizeof(soap->msgbuf)))
      return soap->error;
  }
  return SOAP_OK;
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_LEANER
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_getmime(struct soap *soap)
{ while (soap_get_mime_attachment(soap, NULL))
    ;
  return soap->error;
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_LEANER
#ifndef PALM_1
SOAP_FMAC1
void
SOAP_FMAC2
soap_post_check_mime_attachments(struct soap *soap)
{ soap->imode |= SOAP_MIME_POSTCHECK;
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_LEANER
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_check_mime_attachments(struct soap *soap)
{ if (soap->mode & SOAP_MIME_POSTCHECK)
    return soap_get_mime_attachment(soap, NULL) != NULL;
  return SOAP_OK;
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_LEANER
#ifndef PALM_1
SOAP_FMAC1
struct soap_multipart *
SOAP_FMAC2
soap_get_mime_attachment(struct soap *soap, void *handle)
{ register soap_wchar c = 0;
  register size_t i, m = 0;
  register char *s, *t = NULL;
  register struct soap_multipart *content;
  register short flag = 0;
  if (!(soap->mode & SOAP_ENC_MIME))
    return NULL;
  content = soap->mime.last;
  if (!content)
  { if (soap_getmimehdr(soap))
      return NULL;
    content = soap->mime.last;
  }
  else if (content != soap->mime.first)
  { if (soap->fmimewriteopen && ((content->ptr = (char*)soap->fmimewriteopen(soap, (void*)handle, content->id, content->type, content->description, content->encoding)) || soap->error))
    { if (!content->ptr)
        return NULL;
    }
  }
  DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Parsing MIME content id=%s type=%s\n", content->id?content->id:SOAP_STR_EOS, content->type?content->type:SOAP_STR_EOS));
  if (!content->ptr && soap_new_block(soap) == NULL)
  { soap->error = SOAP_EOM;
    return NULL;
  }
  for (;;)
  { if (content->ptr)
      s = soap->tmpbuf;
    else if (!(s = (char*)soap_push_block(soap, NULL, sizeof(soap->tmpbuf))))
    { soap->error = SOAP_EOM;
      return NULL;
    }
    for (i = 0; i < sizeof(soap->tmpbuf); i++)
    { if (m > 0)
      { *s++ = *t++;
        m--;
      }
      else
      { if (!flag)
        { c = soap_get1(soap);
          if ((int)c == EOF)
          { soap->error = SOAP_EOF;
            return NULL;
          }
        }
        if (flag || c == '\r')
        { t = soap->msgbuf;
          memset(t, 0, sizeof(soap->msgbuf));
          strcpy(t, "\n--");
          if (soap->mime.boundary)
            strncat(t, soap->mime.boundary, sizeof(soap->msgbuf)-4);
          do c = soap_getchar(soap);
          while (c == *t++);
          if ((int)c == EOF)
          { soap->error = SOAP_EOF;
            return NULL;
          }
          if (!*--t)
            goto end;
          *t = (char)c;
          flag = (c == '\r');
          m = t - soap->msgbuf + 1 - flag;
          t = soap->msgbuf;
          c = '\r';
        }
        *s++ = (char)c;
      }
    }
    if (content->ptr && soap->fmimewrite)
    { if ((soap->error = soap->fmimewrite(soap, (void*)content->ptr, soap->tmpbuf, i)))
        break;
    }
  }
end:
  *s = '\0'; /* force 0-terminated */
  if (content->ptr)
  { if (!soap->error && soap->fmimewrite)
      soap->error = soap->fmimewrite(soap, (void*)content->ptr, soap->tmpbuf, i);
    if (soap->fmimewriteclose)
      soap->fmimewriteclose(soap, (void*)content->ptr);
    if (soap->error)
      return NULL;
  }
  else
  { content->size = soap_size_block(soap, NULL, i+1)-1;
    content->ptr = soap_save_block(soap, NULL, NULL, 0);
  }
  soap_resolve_attachment(soap, content);
  if (c == '-' && soap_getchar(soap) == '-')
  { soap->mode &= ~SOAP_ENC_MIME;
    if ((soap->mode & SOAP_MIME_POSTCHECK) && soap_end_recv(soap))
    { if (soap->keep_alive < 0)
        soap->keep_alive = 0;
      soap_closesock(soap);
      return NULL;
    }
  }
  else
  { while (c != '\r' && (int)c != EOF && soap_blank(c))
      c = soap_getchar(soap);
    if (c != '\r' || soap_getchar(soap) != '\n')
    { soap->error = SOAP_MIME_ERROR;
      return NULL;
    }
    if (soap_getmimehdr(soap))
      return NULL;
  }
  return content;
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_LEANER
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_match_cid(struct soap *soap, const char *s, const char *t)
{ register size_t n;
  if (!s)
    return 1;
  if (!strcmp(s, t))
    return 0;
  if (!strncmp(s, "cid:", 4))
    s += 4;
  n = strlen(t);
  if (*t == '<')
  { t++;
    n -= 2;
  }
  if (!strncmp(s, t, n) && !s[n])
    return 0;
  soap_decode(soap->tmpbuf, sizeof(soap->tmpbuf), s, SOAP_STR_EOS);
  if (!strncmp(soap->tmpbuf, t, n) && !soap->tmpbuf[n])
    return 0;
  return 1;
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_LEANER
#ifndef PALM_1
static void
soap_resolve_attachment(struct soap *soap, struct soap_multipart *content)
{ if (content->id)
  { register struct soap_xlist **xp = &soap->xlist;
    DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Resolving attachment data for id=%s\n", content->id));
    while (*xp)
    { register struct soap_xlist *xq = *xp;
      if (!soap_match_cid(soap, xq->id, content->id))
      { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Found matching attachment %s for content id=%s\n", xq->id, content->id));
        *xp = xq->next;
        *xq->ptr = (unsigned char*)content->ptr;
        *xq->size = (int)content->size;
        *xq->type = (char*)content->type;
        if (content->options)
          *xq->options = (char*)content->options;
        else
          *xq->options = (char*)content->description;
        SOAP_FREE(soap, xq);
      }
      else
        xp = &(*xp)->next;
    }
  }
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_LEANER
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_putmimehdr(struct soap *soap, struct soap_multipart *content)
{ const char *s;
  DBGLOG(TEST, SOAP_MESSAGE(fdebug, "MIME attachment type=%s\n", content->type?content->type:SOAP_STR_EOS));
  if (soap_send3(soap, "\r\n--", soap->mime.boundary, "\r\n"))
    return soap->error;
  if (content->type && soap_send3(soap, "Content-Type: ", content->type, "\r\n"))
    return soap->error;
  s = soap_code_str(mime_codes, content->encoding);
  if (s && soap_send3(soap, "Content-Transfer-Encoding: ", s, "\r\n"))
    return soap->error;
  if (content->id && soap_send3(soap, "Content-ID: ", content->id, "\r\n"))
    return soap->error;
  if (content->location && soap_send3(soap, "Content-Location: ", content->location, "\r\n"))
    return soap->error;
  if (content->description && soap_send3(soap, "Content-Description: ", content->description, "\r\n"))
    return soap->error;
  return soap_send_raw(soap, "\r\n", 2);
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_LEANER
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_putmime(struct soap *soap)
{ struct soap_multipart *content;
  if (!(soap->mode & SOAP_ENC_MIME) || !soap->mime.boundary)
    return SOAP_OK;
  DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Sending MIME attachments\n"));
  for (content = soap->mime.first; content; content = content->next)
  { void *handle;
    if (soap->fmimereadopen && ((handle = soap->fmimereadopen(soap, (void*)content->ptr, content->id, content->type, content->description)) || soap->error))
    { size_t size = content->size;
      if (!handle)
      { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "fmimereadopen failed\n"));
        return soap->error;
      }
      if (soap_putmimehdr(soap, content))
        return soap->error;
      if (!size)
      { if ((soap->mode & SOAP_ENC_XML) || (soap->mode & SOAP_IO) == SOAP_IO_CHUNK || (soap->mode & SOAP_IO) == SOAP_IO_STORE)
        { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Chunked streaming MIME\n"));
          do 
          { size = soap->fmimeread(soap, handle, soap->tmpbuf, sizeof(soap->tmpbuf));
            DBGLOG(TEST, SOAP_MESSAGE(fdebug, "fmimeread returned %lu bytes\n", (unsigned long)size));
            if (soap_send_raw(soap, soap->tmpbuf, size))
              break;
          } while (size); 
        }
        else
        { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Error: cannot chunk streaming MIME (no HTTP chunking)\n"));
        }
      }
      else
      { do
        { size_t bufsize;
          if (size < sizeof(soap->tmpbuf))
            bufsize = size;
          else
            bufsize = sizeof(soap->tmpbuf);
          if (!(bufsize = soap->fmimeread(soap, handle, soap->tmpbuf, bufsize)))
          { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "fmimeread failed: insufficient data (%lu bytes remaining from %lu bytes)\n", (unsigned long)size, (unsigned long)content->size));
            soap->error = SOAP_EOF;
            break;
          }
          if (soap_send_raw(soap, soap->tmpbuf, bufsize))
            break;
          size -= bufsize;
        } while (size);
      }
      if (soap->fmimereadclose)
        soap->fmimereadclose(soap, handle);
    }
    else
    { if (soap_putmimehdr(soap, content)
       || soap_send_raw(soap, content->ptr, content->size))
        return soap->error;
    }
  }
  return soap_send3(soap, "\r\n--", soap->mime.boundary, "--");
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_LEANER
#ifndef PALM_1
SOAP_FMAC1
void
SOAP_FMAC2
soap_set_dime(struct soap *soap)
{ soap->omode |= SOAP_ENC_DIME;
  soap->dime.first = NULL;
  soap->dime.last = NULL;
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_LEANER
#ifndef PALM_1
SOAP_FMAC1
void
SOAP_FMAC2
soap_set_mime(struct soap *soap, const char *boundary, const char *start)
{ soap->omode |= SOAP_ENC_MIME;
  soap->mime.first = NULL;
  soap->mime.last = NULL;
  soap->mime.boundary = soap_strdup(soap, boundary);
  soap->mime.start = soap_strdup(soap, start);
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_LEANER
#ifndef PALM_1
SOAP_FMAC1
void
SOAP_FMAC2
soap_clr_dime(struct soap *soap)
{ soap->omode &= ~SOAP_ENC_DIME;
  soap->dime.first = NULL;
  soap->dime.last = NULL;
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_LEANER
#ifndef PALM_1
SOAP_FMAC1
void
SOAP_FMAC2
soap_clr_mime(struct soap *soap)
{ soap->omode &= ~SOAP_ENC_MIME;
  soap->mime.first = NULL;
  soap->mime.last = NULL;
  soap->mime.boundary = NULL;
  soap->mime.start = NULL;
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_LEANER
#ifndef PALM_1
static struct soap_multipart*
soap_new_multipart(struct soap *soap, struct soap_multipart **first, struct soap_multipart **last, char *ptr, size_t size)
{ struct soap_multipart *content;
  content = (struct soap_multipart*)soap_malloc(soap, sizeof(struct soap_multipart));
  if (content)
  { content->next = NULL;
    content->ptr = ptr;
    content->size = size;
    content->id = NULL;
    content->type = NULL;
    content->options = NULL;
    content->encoding = SOAP_MIME_NONE;
    content->location = NULL;
    content->description = NULL;
    if (!*first)
      *first = content;
    if (*last)
      (*last)->next = content;
    *last = content;
  }
  return content;
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_LEANER
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_set_dime_attachment(struct soap *soap, char *ptr, size_t size, const char *type, const char *id, unsigned short optype, const char *option)
{ struct soap_multipart *content = soap_new_multipart(soap, &soap->dime.first, &soap->dime.last, ptr, size);
  if (!content)
    return SOAP_EOM;
  content->id = soap_strdup(soap, id);
  content->type = soap_strdup(soap, type);
  content->options = soap_dime_option(soap, optype, option);
  return SOAP_OK;
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_LEANER
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_set_mime_attachment(struct soap *soap, char *ptr, size_t size, enum soap_mime_encoding encoding, const char *type, const char *id, const char *location, const char *description)
{ struct soap_multipart *content = soap_new_multipart(soap, &soap->mime.first, &soap->mime.last, ptr, size);
  if (!content)
    return SOAP_EOM;
  content->id = soap_strdup(soap, id);
  content->type = soap_strdup(soap, type);
  content->encoding = encoding;
  content->location = soap_strdup(soap, location);
  content->description = soap_strdup(soap, description);
  return SOAP_OK;
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_LEANER
#ifndef PALM_1
SOAP_FMAC1
struct soap_multipart*
SOAP_FMAC2
soap_next_multipart(struct soap_multipart *content)
{ if (content)
    return content->next;
  return NULL;
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_LEANER
#ifndef PALM_1
static void
soap_select_mime_boundary(struct soap *soap)
{ while (!soap->mime.boundary || soap_valid_mime_boundary(soap))
  { register char *s = soap->mime.boundary;
    register size_t n = 0;
    if (s)
      n = strlen(s);
    if (n < 16)
    { n = 64;
      s = soap->mime.boundary = (char*)soap_malloc(soap, n + 1);
      if (!s)
        return;
    }
    strcpy(s, "==");
    s += 2;
    n -= 4;
    while (n)
    { *s++ = soap_base64o[soap_random & 0x3F];
      n--;
    }
    strcpy(s, "==");
  }
  if (!soap->mime.start)
    soap->mime.start = "<SOAP-ENV:Envelope>";
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_LEANER
#ifndef PALM_1
static int
soap_valid_mime_boundary(struct soap *soap)
{ register struct soap_multipart *content;
  register size_t k;
  if (soap->fmimeread)
    return SOAP_OK;
  k = strlen(soap->mime.boundary);
  for (content = soap->mime.first; content; content = content->next)
  { if (content->ptr && content->size >= k)
    { register const char *p = (const char*)content->ptr; 
      register size_t i;
      for (i = 0; i < content->size - k; i++, p++)
      { if (!strncmp(p, soap->mime.boundary, k))
          return SOAP_ERR;
      }
    }
  }
  return SOAP_OK;
}
#endif
#endif

/******************************************************************************/
#ifdef WITH_GZIP
#ifndef PALM_1
static int
soap_getgziphdr(struct soap *soap)
{ int i;
  soap_wchar c = 0, f = 0;
  DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Get gzip header\n"));
  for (i = 0; i < 9; i++)
  { if ((int)(c = soap_get1(soap) == EOF))
      return soap->error = SOAP_EOF;
    if (i == 1 && c == 8)
      soap->z_dict = 0;
    if (i == 2)
      f = c;
  }
  if (f & 0x04) /* FEXTRA */
  { for (i = soap_get1(soap) | (soap_get1(soap) << 8); i; i--)
    { if ((int)soap_get1(soap) == EOF)
        return soap->error = SOAP_EOF;
    }
  }
  if (f & 0x08) /* skip FNAME */
  { do
      c = soap_get1(soap);
    while (c && (int)c != EOF);
  }
  if ((int)c != EOF && (f & 0x10)) /* skip FCOMMENT */
  { do
      c = soap_get1(soap);
    while (c && (int)c != EOF);
  }
  if ((int)c != EOF && (f & 0x02)) /* skip FHCRC (CRC32 is used) */
  { if ((int)(c = soap_get1(soap)) != EOF)
      c = soap_get1(soap);
  }
  if ((int)c == EOF)
    return soap->error = SOAP_EOF;
  return SOAP_OK;
}
#endif
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_begin_recv(struct soap *soap)
{ soap_wchar c;
  DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Initializing for input\n"));
  soap->error = SOAP_OK;
  soap_free_temp(soap);
  soap_set_local_namespaces(soap);
  soap->version = 0;	/* don't assume we're parsing SOAP content by default */
#ifndef WITH_NOIDREF
  soap_free_iht(soap);
#endif
  if ((soap->imode & SOAP_IO) == SOAP_IO_CHUNK)
    soap->omode |= SOAP_IO_CHUNK;
  soap->imode &= ~(SOAP_IO | SOAP_ENC_MIME);
  soap->mode = soap->imode;
  if (!soap->keep_alive)
  { soap->buflen = 0;
    soap->bufidx = 0;
  }
  if (!(soap->mode & SOAP_IO_KEEPALIVE))
    soap->keep_alive = 0;
  soap->ahead = 0;
  soap->peeked = 0;
  soap->level = 0;
  soap->part = SOAP_BEGIN;
  soap->alloced = 0;
  soap->count = 0;
  soap->length = 0;
  soap->cdata = 0;
  *soap->endpoint = '\0';
  soap->action = NULL;
  soap->header = NULL;
  soap->fault = NULL;
  soap->status = 0;
#ifndef WITH_LEANER
  soap->dom = NULL;
  soap->dime.chunksize = 0;
  soap->dime.buflen = 0;
  soap->dime.list = NULL;
  soap->dime.first = NULL;
  soap->dime.last = NULL;
  soap->mime.list = NULL;
  soap->mime.first = NULL;
  soap->mime.last = NULL;
  soap->mime.boundary = NULL;
  soap->mime.start = NULL;
#endif
#ifdef WIN32
#ifndef UNDER_CE
#ifndef WITH_FASTCGI
  if (!soap_valid_socket(soap->socket))
#ifdef __BORLANDC__
    setmode(soap->recvfd, _O_BINARY);
#else
    _setmode(soap->recvfd, _O_BINARY);
#endif
#endif
#endif
#endif
#ifdef WITH_ZLIB
  soap->mode &= ~SOAP_ENC_ZLIB;
  soap->zlib_in = SOAP_ZLIB_NONE;
  soap->zlib_out = SOAP_ZLIB_NONE;
  soap->d_stream->next_in = Z_NULL;
  soap->d_stream->avail_in = 0;
  soap->d_stream->next_out = (Byte*)soap->buf;
  soap->d_stream->avail_out = SOAP_BUFLEN;
  soap->z_ratio_in = 1.0;
#endif
#ifdef WITH_OPENSSL
  if (soap->ssl)
    ERR_clear_error();
#endif
#ifndef WITH_LEANER
  if (soap->fprepareinitrecv && (soap->error = soap->fprepareinitrecv(soap)))
    return soap->error;
#endif
  c = soap_getchar(soap);
#ifdef WITH_GZIP
  if (c == 0x1F)
  { if (soap_getgziphdr(soap))
      return soap->error;
    if (inflateInit2(soap->d_stream, -MAX_WBITS) != Z_OK)
      return soap->error = SOAP_ZLIB_ERROR;
    if (soap->z_dict)
    { if (inflateSetDictionary(soap->d_stream, (const Bytef*)soap->z_dict, soap->z_dict_len) != Z_OK)
        return soap->error = SOAP_ZLIB_ERROR;
    }
    soap->zlib_state = SOAP_ZLIB_INFLATE;
    soap->mode |= SOAP_ENC_ZLIB;
    soap->zlib_in = SOAP_ZLIB_GZIP;
    soap->z_crc = crc32(0L, NULL, 0);
    DBGLOG(TEST, SOAP_MESSAGE(fdebug, "gzip initialized\n"));
    if (!soap->z_buf)
      soap->z_buf = (char*)SOAP_MALLOC(soap, SOAP_BUFLEN);
    memcpy(soap->z_buf, soap->buf, SOAP_BUFLEN);
    /* should not chunk over plain transport, so why bother to check? */
    /* if ((soap->mode & SOAP_IO) == SOAP_IO_CHUNK) */
    /*   soap->z_buflen = soap->bufidx; */
    /* else */
    soap->d_stream->next_in = (Byte*)(soap->z_buf + soap->bufidx);
    soap->d_stream->avail_in = soap->buflen - soap->bufidx;
    soap->z_buflen = soap->buflen;
    soap->buflen = soap->bufidx;
    c = ' ';
  }
#endif
  while (soap_blank(c))
    c = soap_getchar(soap);
#ifndef WITH_LEANER
  if (c == '-' && soap_get0(soap) == '-')
    soap->mode |= SOAP_ENC_MIME;
  else if ((c & 0xFFFC) == (SOAP_DIME_VERSION | SOAP_DIME_MB) && (soap_get0(soap) & 0xFFF0) == 0x20)
    soap->mode |= SOAP_ENC_DIME;
  else
#endif
  { /* skip BOM */
    if (c == 0xEF && (c = soap_getchar(soap)) == 0xBB && (c = soap_getchar(soap)) == 0xBF)
      c = soap_getchar(soap);
    /* skip space */
    while (soap_blank(c))
      c = soap_getchar(soap);
  }
  if ((int)c == EOF)
    return soap->error = SOAP_EOF;
  soap_unget(soap, c);
#ifndef WITH_NOHTTP
  /* if not XML or MIME/DIME/ZLIB, assume HTTP header */
  if (c != '<' && !(soap->mode & (SOAP_ENC_MIME | SOAP_ENC_DIME | SOAP_ENC_ZLIB)))
  { soap_mode m = soap->imode;
    soap->mode &= ~SOAP_IO;
    soap->error = soap->fparse(soap);
    if (soap->error && soap->error < SOAP_STOP)
    { soap->keep_alive = 0; /* force close later */
      return soap->error;
    }
    if (soap->error == SOAP_STOP)
      return soap->error;
    soap->mode = soap->imode; /* if imode is changed, effectuate */
    soap->imode = m; /* restore imode */
#ifdef WITH_ZLIB
    soap->mode &= ~SOAP_ENC_ZLIB;
#endif
    if ((soap->mode & SOAP_IO) == SOAP_IO_CHUNK)
    { soap->chunkbuflen = soap->buflen;
      soap->buflen = soap->bufidx;
      soap->chunksize = 0;
    }
    /* Note: fparse should not use soap_unget to push back last char */
    if (soap_get0(soap) == (int)EOF)
    { if (soap->status == 200)
        return soap->error = SOAP_NO_DATA; /* HTTP OK: always expect data */
      return soap->error = soap->status;
    }
#ifdef WITH_ZLIB
    if (soap->zlib_in != SOAP_ZLIB_NONE)
    {
#ifdef WITH_GZIP
      if (soap->zlib_in != SOAP_ZLIB_DEFLATE)
      { c = soap_get1(soap);
        if (c == 0x1F)
        { if (soap_getgziphdr(soap))
            return soap->error;
          if (inflateInit2(soap->d_stream, -MAX_WBITS) != Z_OK)
            return soap->error = SOAP_ZLIB_ERROR;
          soap->z_crc = crc32(0L, NULL, 0);
          DBGLOG(TEST, SOAP_MESSAGE(fdebug, "gzip initialized\n"));
        }
        else
        { soap_revget1(soap);
          if (inflateInit(soap->d_stream) != Z_OK)
            return soap->error = SOAP_ZLIB_ERROR;
          soap->zlib_in = SOAP_ZLIB_DEFLATE;
        }
      }
      else
#endif
      if (inflateInit(soap->d_stream) != Z_OK)
        return soap->error = SOAP_ZLIB_ERROR;
      if (soap->z_dict)
      { if (inflateSetDictionary(soap->d_stream, (const Bytef*)soap->z_dict, soap->z_dict_len) != Z_OK)
          return soap->error = SOAP_ZLIB_ERROR;
      }
      soap->zlib_state = SOAP_ZLIB_INFLATE;
      DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Inflate initialized\n"));
      soap->mode |= SOAP_ENC_ZLIB;
      if (!soap->z_buf)
        soap->z_buf = (char*)SOAP_MALLOC(soap, SOAP_BUFLEN);
      memcpy(soap->z_buf, soap->buf, SOAP_BUFLEN);
      soap->d_stream->next_in = (Byte*)(soap->z_buf + soap->bufidx);
      soap->d_stream->avail_in = soap->buflen - soap->bufidx;
      soap->z_buflen = soap->buflen;
      soap->buflen = soap->bufidx;
    }
#endif
#ifndef WITH_LEANER
    if (soap->fpreparerecv && (soap->mode & SOAP_IO) != SOAP_IO_CHUNK && soap->buflen > soap->bufidx)
    { int r;
      if ((r = soap->fpreparerecv(soap, soap->buf + soap->bufidx, soap->buflen - soap->bufidx)))
        return soap->error = r;
    }
#endif
    if (soap->error)
    { if (soap->error == SOAP_FORM && soap->fform)
      { soap->error = soap->fform(soap);
        if (soap->error == SOAP_OK)
          soap->error = SOAP_STOP; /* prevents further processing */
      }
      return soap->error;
    }
  }
#endif
#ifndef WITH_LEANER
  if (soap->mode & SOAP_ENC_MIME)
  { do /* skip preamble */
    { if ((int)(c = soap_getchar(soap)) == EOF)
        return soap->error = SOAP_EOF;
    } while (c != '-' || soap_get0(soap) != '-');
    soap_unget(soap, c);
    if (soap_getmimehdr(soap))
      return soap->error;
    if (soap->mime.start)
    { do
      { if (!soap->mime.last->id)
          break;
        if (!soap_match_cid(soap, soap->mime.start, soap->mime.last->id))
          break;
      } while (soap_get_mime_attachment(soap, NULL));
    }
    if (soap_get_header_attribute(soap, soap->mime.first->type, "application/dime"))
      soap->mode |= SOAP_ENC_DIME;
  }
  if (soap->mode & SOAP_ENC_DIME)
  { if (soap_getdimehdr(soap))
      return soap->error;
    if (soap->dime.flags & SOAP_DIME_CF)
    { DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Chunked DIME SOAP message\n"));
      soap->dime.chunksize = soap->dime.size;
      if (soap->buflen - soap->bufidx >= soap->dime.chunksize)
      { soap->dime.buflen = soap->buflen;
        soap->buflen = soap->bufidx + soap->dime.chunksize;
      }
      else
        soap->dime.chunksize -= soap->buflen - soap->bufidx;
    }
    soap->count = soap->buflen - soap->bufidx;
  }
#endif
  return SOAP_OK;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_envelope_begin_out(struct soap *soap)
{
#ifndef WITH_LEANER
  size_t n = 0;
  if ((soap->mode & SOAP_ENC_MIME) && soap->mime.boundary && soap->mime.start && strlen(soap->mime.boundary) + strlen(soap->mime.start) < sizeof(soap->tmpbuf) - 80 )
  { const char *s;
    if ((soap->mode & SOAP_ENC_DIME) && !(soap->mode & SOAP_ENC_MTOM))
      s = "application/dime";
    else if (soap->version == 2)
    { if (soap->mode & SOAP_ENC_MTOM)
        s = "application/xop+xml; charset=utf-8; type=\"application/soap+xml\"";
      else
        s = "application/soap+xml; charset=utf-8";
    }
    else if (soap->mode & SOAP_ENC_MTOM)
      s = "application/xop+xml; charset=utf-8; type=\"text/xml\"";
    else
      s = "text/xml; charset=utf-8";
    sprintf(soap->tmpbuf, "--%s\r\nContent-Type: %s\r\nContent-Transfer-Encoding: binary\r\nContent-ID: %s\r\n\r\n", soap->mime.boundary, s, soap->mime.start);
    n = strlen(soap->tmpbuf);
    if (soap_send_raw(soap, soap->tmpbuf, n))
      return soap->error;
  }
  if (soap->mode & SOAP_IO_LENGTH)
    soap->dime.size = soap->count;	/* DIME in MIME correction */
  if (!(soap->mode & SOAP_IO_LENGTH) && (soap->mode & SOAP_ENC_DIME))
  { if (soap_putdimehdr(soap))
      return soap->error;
  }
#endif
  soap->part = SOAP_IN_ENVELOPE;
  return soap_element_begin_out(soap, "SOAP-ENV:Envelope", 0, NULL);
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_envelope_end_out(struct soap *soap)
{ if (soap_element_end_out(soap, "SOAP-ENV:Envelope") || ((soap->mode & SOAP_XML_INDENT) && soap_send_raw(soap, "\r\n", 2)))
    return soap->error;
#ifndef WITH_LEANER
  if ((soap->mode & SOAP_IO_LENGTH) && (soap->mode & SOAP_ENC_DIME) && !(soap->mode & SOAP_ENC_MTOM))
  { soap->dime.size = soap->count - soap->dime.size;	/* DIME in MIME correction */
    sprintf(soap->id, soap->dime_id_format, 0);
    soap->dime.id = soap->id;
    if (soap->local_namespaces)
    { if (soap->local_namespaces[0].out)
        soap->dime.type = (char*)soap->local_namespaces[0].out;
      else
        soap->dime.type = (char*)soap->local_namespaces[0].ns;
    }
    soap->dime.options = NULL;
    soap->dime.flags = SOAP_DIME_MB | SOAP_DIME_ABSURI;
    if (!soap->dime.first)
      soap->dime.flags |= SOAP_DIME_ME;
    soap->count += 12 + ((strlen(soap->dime.id)+3)&(~3)) + (soap->dime.type ? ((strlen(soap->dime.type)+3)&(~3)) : 0);
  }
  if ((soap->mode & SOAP_ENC_DIME) && !(soap->mode & SOAP_ENC_MTOM))
    return soap_send_raw(soap, SOAP_STR_PADDING, -(long)soap->dime.size&3);
#endif
  soap->part = SOAP_END_ENVELOPE;
  return SOAP_OK;
} 
#endif

/******************************************************************************/
#ifndef WITH_LEAN
#ifndef PALM_1
SOAP_FMAC1
char*
SOAP_FMAC2
soap_get_http_body(struct soap *soap)
{
#ifndef WITH_LEAN
  register size_t l = 0, n = 0;
  register char *s;
  /* get HTML body of HTTP error content */
  if (!(soap->mode & SOAP_ENC_ZLIB) && (soap->mode & SOAP_IO) != SOAP_IO_CHUNK)
  { n = soap->length;
    if (!n)
      return NULL;
  }
#ifdef WITH_FAST
  soap->labidx = 0;			/* use look-aside buffer */
#else
  if (soap_new_block(soap) == NULL)
    return NULL;
#endif
  for (;;)
  { 
#ifdef WITH_FAST
    register size_t i, k;
    if (soap_append_lab(soap, NULL, 0))	/* allocate more space in look-aside buffer if necessary */
      return NULL;
    s = soap->labbuf + soap->labidx;	/* space to populate */
    k = soap->lablen - soap->labidx;	/* number of bytes available */
    soap->labidx = soap->lablen;	/* claim this space */
#else
    register size_t i, k = SOAP_BLKLEN;
    if (!(s = (char*)soap_push_block(soap, NULL, k)))
      return NULL;
#endif
    for (i = 0; i < k; i++)
    { register soap_wchar c = soap_getchar(soap);
      if ((int)c == EOF)
        goto end;
      *s++ = (char)(c & 0xFF);
      l++;
      if (n > 0 && l >= n)
        goto end;
    }
  }
end:
  *s = '\0';
#ifdef WITH_FAST
  s = soap_strdup(soap, soap->labbuf);
#else
  soap_size_block(soap, NULL, i+1);
  s = soap_save_block(soap, NULL, 0);
#endif
  return s;
#else
  return NULL;
#endif
}
#endif
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_envelope_begin_in(struct soap *soap)
{ register struct Namespace *p;
  soap->part = SOAP_IN_ENVELOPE;
  if (soap_element_begin_in(soap, "SOAP-ENV:Envelope", 0, NULL))
  { if (soap->error == SOAP_TAG_MISMATCH
     && !soap_element_begin_in(soap, "Envelope", 0, NULL))
      soap->error = SOAP_VERSIONMISMATCH;
    else if (soap->status)
      soap->error = soap->status;
    return soap->error;
  }
  p = soap->local_namespaces;
  if (p)
  { const char *ns = p[0].out;
    if (!ns)
      ns = p[0].ns;
    if (!strcmp(ns, soap_env1))
    { soap->version = 1; /* make sure we use SOAP 1.1 */
      if (p[1].out)
        SOAP_FREE(soap, p[1].out);
      if ((p[1].out = (char*)SOAP_MALLOC(soap, sizeof(soap_enc1))))
        strcpy(p[1].out, soap_enc1);
    }
    else if (!strcmp(ns, soap_env2))
    { soap->version = 2; /* make sure we use SOAP 1.2 */
      if (p[1].out)
        SOAP_FREE(soap, p[1].out);
      if ((p[1].out = (char*)SOAP_MALLOC(soap, sizeof(soap_enc2))))
        strcpy(p[1].out, soap_enc2);
    }
  }
  return SOAP_OK;
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_envelope_end_in(struct soap *soap)
{ soap->part = SOAP_END_ENVELOPE;
  return soap_element_end_in(soap, "SOAP-ENV:Envelope");
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_body_begin_out(struct soap *soap)
{ soap->part = SOAP_IN_BODY;
  if (soap->version == 1)
    soap->encoding = 1;
#ifndef WITH_LEAN
  if ((soap->mode & SOAP_XML_SEC) && soap_set_attr(soap, "wsu:Id", "Body", 1))
    return soap->error;
#endif
  if (soap_element(soap, "SOAP-ENV:Body", 0, NULL))
    return soap->error;
  return soap_element_start_end_out(soap, NULL);
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_body_end_out(struct soap *soap)
{ if (soap_element_end_out(soap, "SOAP-ENV:Body"))
    return soap->error;
  soap->part = SOAP_END_BODY;
  return SOAP_OK;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_body_begin_in(struct soap *soap)
{ soap->part = SOAP_IN_BODY;
  if (soap_element_begin_in(soap, "SOAP-ENV:Body", 0, NULL))
    return soap->error;
  if (!soap->body)
    soap->part = SOAP_NO_BODY;
  return SOAP_OK;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_body_end_in(struct soap *soap)
{ if (soap->part == SOAP_NO_BODY)
    return soap->error = SOAP_OK;
  soap->part = SOAP_END_BODY;
  return soap_element_end_in(soap, "SOAP-ENV:Body");
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_recv_header(struct soap *soap)
{ if (soap_getheader(soap) && soap->error == SOAP_TAG_MISMATCH)
    soap->error = SOAP_OK;
  if (soap->error == SOAP_OK && soap->fheader)
    soap->error = soap->fheader(soap);
  return soap->error;
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
void
SOAP_FMAC2
soap_set_endpoint(struct soap *soap, const char *endpoint)
{ register const char *s;
  register size_t i, n;
  soap->endpoint[0] = '\0';
  soap->host[0] = '\0';
  soap->path[0] = '/';
  soap->path[1] = '\0';
  soap->port = 80;
  if (!endpoint || !*endpoint)
    return;
#ifdef WITH_OPENSSL
  if (!soap_tag_cmp(endpoint, "https:*"))
    soap->port = 443;
#endif
  strncpy(soap->endpoint, endpoint, sizeof(soap->endpoint) - 1);
  soap->endpoint[sizeof(soap->endpoint) - 1] = '\0';
  s = strchr(endpoint, ':');
  if (s && s[1] == '/' && s[2] == '/')
    s += 3;
  else
    s = endpoint;
  n = strlen(s);
  if (n >= sizeof(soap->host))
    n = sizeof(soap->host) - 1;
#ifdef WITH_IPV6
  if (s[0] == '[')
  { s++;
    for (i = 0; i < n; i++)
    { if (s[i] == ']')
      { s++;
        --n;
        break; 
      }
      soap->host[i] = s[i];
    }
  }
  else
  { for (i = 0; i < n; i++)
    { soap->host[i] = s[i];
      if (s[i] == '/' || s[i] == ':')
        break; 
    }
  }
#else
  for (i = 0; i < n; i++)
  { soap->host[i] = s[i];
    if (s[i] == '/' || s[i] == ':')
      break; 
  }
#endif
  soap->host[i] = '\0';
  if (s[i] == ':')
  { soap->port = (int)soap_strtol(s + i + 1, NULL, 10);
    for (i++; i < n; i++)
      if (s[i] == '/')
        break;
  }
  if (i < n && s[i])
  { strncpy(soap->path, s + i, sizeof(soap->path));
    soap->path[sizeof(soap->path) - 1] = '\0';
  }
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_connect(struct soap *soap, const char *endpoint, const char *action)
{ return soap_connect_command(soap, SOAP_POST, endpoint, action);
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_connect_command(struct soap *soap, int http_command, const char *endpoints, const char *action)
{ char *endpoint;
  const char *s;
  if (endpoints && (s = strchr(endpoints, ' ')))
  { endpoint = (char*)SOAP_MALLOC(soap, strlen(endpoints) + 1);
    for (;;)
    { strncpy(endpoint, endpoints, s - endpoints);
      endpoint[s - endpoints] = '\0';
      if (soap_try_connect_command(soap, http_command, endpoint, action) != SOAP_TCP_ERROR)
        break;
      if (!*s)
        break;
      soap->error = SOAP_OK;
      while (*s == ' ')
        s++;
      endpoints = s;
      s = strchr(endpoints, ' ');
      if (!s)
        s = endpoints + strlen(endpoints);
    }
    SOAP_FREE(soap, endpoint);
  }
  else
    soap_try_connect_command(soap, http_command, endpoints, action);
  return soap->error;
}
#endif

/******************************************************************************/
#ifndef PALM_1
static int
soap_try_connect_command(struct soap *soap, int http_command, const char *endpoint, const char *action)
{ char host[sizeof(soap->host)];
  int port;
  size_t count;
  soap->error = SOAP_OK;
  strcpy(host, soap->host); /* save previous host name: if != then reconnect */
  port = soap->port; /* save previous port to compare */
  soap->status = http_command;
  soap_set_endpoint(soap, endpoint);
#ifndef WITH_LEANER
  if (soap->fconnect)
  { if ((soap->error = soap->fconnect(soap, endpoint, soap->host, soap->port)))
      return soap->error;
  }
  else
#endif
  if (soap->fopen && *soap->host)
  { if (!soap->keep_alive || !soap_valid_socket(soap->socket) || strcmp(soap->host, host) || soap->port != port || !soap->fpoll || soap->fpoll(soap))
    { soap->keep_alive = 0; /* to force close */
      soap->omode &= ~SOAP_IO_UDP; /* to force close */
      soap_closesock(soap);
      DBGLOG(TEST,SOAP_MESSAGE(fdebug, "Connect/reconnect to host='%s' path='%s' port=%d\n", soap->host, soap->path, soap->port));
#ifndef WITH_LEAN
      if (!strncmp(endpoint, "soap.udp:", 9))
        soap->omode |= SOAP_IO_UDP;
#endif
      soap->socket = soap->fopen(soap, endpoint, soap->host, soap->port);
      if (soap->error)
        return soap->error;
      soap->keep_alive = ((soap->omode & SOAP_IO_KEEPALIVE) != 0);
    }
  }
  count = soap_count_attachments(soap);
  if (soap_begin_send(soap))
    return soap->error;
  if (http_command == SOAP_GET)
  { soap->mode &= ~SOAP_IO;
    soap->mode |= SOAP_IO_BUFFER;
  }
#ifndef WITH_NOHTTP
  soap->action = soap_strdup(soap, action);
  if ((soap->mode & SOAP_IO) != SOAP_IO_STORE && !(soap->mode & SOAP_ENC_XML) && endpoint)
  { unsigned int k = soap->mode;
    soap->mode &= ~(SOAP_IO | SOAP_ENC_ZLIB);
    if ((k & SOAP_IO) != SOAP_IO_FLUSH)
      soap->mode |= SOAP_IO_BUFFER;
    if ((soap->error = soap->fpost(soap, endpoint, soap->host, soap->port, soap->path, action, count)))
      return soap->error;
#ifndef WITH_LEANER
    if ((k & SOAP_IO) == SOAP_IO_CHUNK)
    { if (soap_flush(soap))
        return soap->error;
    }
#endif
    soap->mode = k;
  }
  if (http_command == SOAP_GET)
    return soap_end_send(soap);
#endif
  return SOAP_OK;
}
#endif

/******************************************************************************/
#ifndef WITH_LEAN
SOAP_FMAC1
char*
SOAP_FMAC2
soap_s2base64(struct soap *soap, const unsigned char *s, char *t, int n)
{ register int i;
  register unsigned long m;
  register char *p;
  if (!t)
    t = (char*)soap_malloc(soap, (n + 2) / 3 * 4 + 1);
  if (!t)
    return NULL;
  p = t;
  t[0] = '\0';
  if (!s)
    return p;
  for (; n > 2; n -= 3, s += 3)
  { m = s[0];
    m = (m << 8) | s[1];
    m = (m << 8) | s[2];
    for (i = 4; i > 0; m >>= 6)
      t[--i] = soap_base64o[m & 0x3F];
    t += 4;
  }
  t[0] = '\0';
  if (n > 0)
  { m = 0;
    for (i = 0; i < n; i++)
      m = (m << 8) | *s++;
    for (; i < 3; i++)
      m <<= 8;
    for (i++; i > 0; m >>= 6)
      t[--i] = soap_base64o[m & 0x3F];
    for (i = 3; i > n; i--)
      t[i] = '=';
    t[4] = '\0';
  }
  return p;
}
#endif

/******************************************************************************/
#ifndef WITH_LEAN
SOAP_FMAC1
const char*
SOAP_FMAC2
soap_base642s(struct soap *soap, const char *s, char *t, size_t l, int *n)
{ register int i, j, c;
  register unsigned long m;
  register const char *p;
  if (!s || !*s)
  { if (n)
      *n = 0;
    if (soap->error)
      return NULL;
    return SOAP_NON_NULL;
  }
  if (!t)
  { l = (strlen(s) + 3) / 4 * 3;
    t = (char*)soap_malloc(soap, l);
  }
  if (!t)
    return NULL;
  p = t;
  if (n)
    *n = 0;
  for (;;)
  { for (i = 0; i < SOAP_BLKLEN; i++)
    { m = 0;
      j = 0;
      while (j < 4)
      { c = *s++;
        if (c == '=' || !c)
        { i *= 3;
          switch (j)
          { case 2:
              *t++ = (char)((m >> 4) & 0xFF);
              i++;
              break;
            case 3:
              *t++ = (char)((m >> 10) & 0xFF);
              *t++ = (char)((m >> 2) & 0xFF);
              i += 2;
          }
          if (n)
            *n += i;
          return p;
        }
        c -= '+';
        if (c >= 0 && c <= 79)
        { int b = soap_base64i[c];
          if (b >= 64)
          { soap->error = SOAP_TYPE;
            return NULL;  
          }
          m = (m << 6) + b;
          j++;
        }
        else if (!soap_blank(c + '+'))
        { soap->error = SOAP_TYPE;
          return NULL;  
        }
      }
      *t++ = (char)((m >> 16) & 0xFF);
      *t++ = (char)((m >> 8) & 0xFF);
      *t++ = (char)(m & 0xFF);
      if (l < 3)
      { if (n)
          *n += i;
        return p;
      }
      l -= 3;
    }
    if (n)
      *n += 3 * SOAP_BLKLEN;
  }
}
#endif

/******************************************************************************/
#ifndef WITH_LEAN
SOAP_FMAC1
char*
SOAP_FMAC2
soap_s2hex(struct soap *soap, const unsigned char *s, char *t, int n)
{ register char *p;
  if (!t)
    t = (char*)soap_malloc(soap, 2 * n + 1);
  if (!t)
    return NULL;
  p = t;
  t[0] = '\0';
  if (s)
  { for (; n > 0; n--)
    { register int m = *s++;
      *t++ = (char)((m >> 4) + (m > 159 ? 'a' - 10 : '0'));
      m &= 0x0F;
      *t++ = (char)(m + (m > 9 ? 'a' - 10 : '0'));
    }
  }
  *t++ = '\0';
  return p;
}
#endif

/******************************************************************************/
#ifndef WITH_LEAN
SOAP_FMAC1
const char*
SOAP_FMAC2
soap_hex2s(struct soap *soap, const char *s, char *t, size_t l, int *n)
{ register const char *p;
  if (!s || !*s)
  { if (n)
      *n = 0;
    if (soap->error)
      return NULL;
    return SOAP_NON_NULL;
  }
  if (!t)
  { l = strlen(s) / 2;
    t = (char*)soap_malloc(soap, l);
  }
  if (!t)
    return NULL;
  p = t;
  while (l)
  { register int d1, d2;
    d1 = *s++;
    if (!d1)
      break;
    d2 = *s++;
    if (!d2)
      break;
    *t++ = ((d1 >= 'A' ? (d1 & 0x7) + 9 : d1 - '0') << 4) + (d2 >= 'A' ? (d2 & 0x7) + 9 : d2 - '0');
    l--;
  }
  if (n)
    *n = (int)(t - p);
  return p;
}
#endif

/******************************************************************************/
#ifndef WITH_NOHTTP
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_puthttphdr(struct soap *soap, int status, size_t count)
{ if (soap->status != SOAP_GET)
  { register const char *s = "text/xml; charset=utf-8";
    register int err = SOAP_OK;
#ifndef WITH_LEANER
    register const char *r = NULL;
#endif
    if ((status == SOAP_FILE || soap->status == SOAP_POST_FILE) && soap->http_content)
      s = soap->http_content;
    else if (status == SOAP_HTML)
      s = "text/html; charset=utf-8";
    else if (count || ((soap->omode & SOAP_IO) == SOAP_IO_CHUNK))
    { if (soap->version == 2)
        s = "application/soap+xml; charset=utf-8";
    }
#ifndef WITH_LEANER
    if (soap->mode & (SOAP_ENC_DIME | SOAP_ENC_MTOM))
    { if (soap->mode & SOAP_ENC_MTOM)
      { if (soap->version == 2)
          r = "application/soap+xml";
	else
          r = "text/xml";
        s = "application/xop+xml";
      }
      else
        s = "application/dime";
    }
    if ((soap->mode & SOAP_ENC_MIME) && soap->mime.boundary && strlen(soap->mime.boundary) + strlen(soap->mime.start ? soap->mime.start : SOAP_STR_EOS) < sizeof(soap->tmpbuf) - 80)
    { register const char *t = strchr(s, ';');
      sprintf(soap->tmpbuf, "multipart/related; charset=utf-8; boundary=\"%s\"; type=\"", soap->mime.boundary);
      if (t)
      { strncat(soap->tmpbuf, s, t - s);
        soap->tmpbuf[sizeof(soap->tmpbuf)-1] = '\0';
      }
      else
        strcat(soap->tmpbuf, s);
      if (soap->mime.start)
      { strcat(soap->tmpbuf, "\"; start=\"");
        strcat(soap->tmpbuf, soap->mime.start);
      }
      strcat(soap->tmpbuf, "\"");
      if (r)
      { strcat(soap->tmpbuf, "; start-info=\"");
        strcat(soap->tmpbuf, r);
        strcat(soap->tmpbuf, "\"");
      }
      s = soap->tmpbuf;
    }
    else if (status == SOAP_OK && soap->action && strlen(soap->action) < sizeof(soap->tmpbuf) - 80)
    { sprintf(soap->tmpbuf, "%s; action=\"%s\"", s, soap->action);
      s = soap->tmpbuf;
    }
#endif
    if (s && (err = soap->fposthdr(soap, "Content-Type", s)))
      return err;
#ifdef WITH_ZLIB
    if ((soap->omode & SOAP_ENC_ZLIB))
    { 
#ifdef WITH_GZIP
      err = soap->fposthdr(soap, "Content-Encoding", soap->zlib_out == SOAP_ZLIB_DEFLATE ? "deflate" : "gzip");
#else
      err = soap->fposthdr(soap, "Content-Encoding", "deflate");
#endif
      if (err)
        return err;
    }
#endif
#ifndef WITH_LEANER
    if ((soap->omode & SOAP_IO) == SOAP_IO_CHUNK)
      err = soap->fposthdr(soap, "Transfer-Encoding", "chunked");
    else
#endif
    if (s)
    { sprintf(soap->tmpbuf, "%lu", (unsigned long)count);
      err = soap->fposthdr(soap, "Content-Length", soap->tmpbuf);
    }
    if (err)
      return err;
  }
  return soap->fposthdr(soap, "Connection", soap->keep_alive ? "keep-alive" : "close");
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_LEAN
static const char*
soap_set_validation_fault(struct soap *soap, const char *s, const char *t)
{ if (*soap->tag)
    sprintf(soap->msgbuf, "Validation constraint violation: %s%s in element '%s'", s, t?t:SOAP_STR_EOS, soap->tag);
  else
    sprintf(soap->msgbuf, "Validation constraint violation: %s%s", s, t?t:SOAP_STR_EOS);
  return soap->msgbuf;
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
void
SOAP_FMAC2
soap_set_fault(struct soap *soap)
{ const char **c = soap_faultcode(soap);
  const char **s = soap_faultstring(soap);
  if (soap->fseterror)
    soap->fseterror(soap, c, s);
  if (!*c)
  { if (soap->version == 2)
      *c = "SOAP-ENV:Sender";
    else
      *c = "SOAP-ENV:Client";
  }
  if (*s)
    return;
  switch (soap->error)
  {
#ifndef WITH_LEAN
    case SOAP_CLI_FAULT:
      *s = "Client fault";
      break;
    case SOAP_SVR_FAULT:
      *s = "Server fault";
      break;
    case SOAP_TAG_MISMATCH:
      *s = soap_set_validation_fault(soap, "tag name or namespace mismatch", NULL);
      break;
    case SOAP_TYPE:
      *s = soap_set_validation_fault(soap, "data type mismatch ", soap->type);
      break;
    case SOAP_SYNTAX_ERROR:
      *s = "Well-formedness violation";
      break;
    case SOAP_NO_TAG:
      *s = "No XML root element";
      break;
    case SOAP_MUSTUNDERSTAND:
      *c = "SOAP-ENV:MustUnderstand";
      sprintf(soap->msgbuf, "The data in element '%s' must be understood but cannot be handled", soap->tag);
      *s = soap->msgbuf;
      break;
    case SOAP_VERSIONMISMATCH:
      *c = "SOAP-ENV:VersionMismatch";
      *s = "Invalid SOAP message or SOAP version mismatch";
      break;
    case SOAP_DATAENCODINGUNKNOWN:
      *c = "SOAP-ENV:DataEncodingUnknown";
      *s = "Unsupported SOAP data encoding";
      break;
    case SOAP_NAMESPACE:
      *s = soap_set_validation_fault(soap, "namespace error", NULL);
      break;
    case SOAP_USER_ERROR:
      *s = "User error";
      break;
    case SOAP_FATAL_ERROR:
      *s = "Fatal error";
      break;
    case SOAP_NO_METHOD:
      sprintf(soap->msgbuf, "Method '%s' not implemented: method name or namespace not recognized", soap->tag);
      *s = soap->msgbuf;
      break;
    case SOAP_NO_DATA:
      *s = "Data required for operation";
      break;
    case SOAP_GET_METHOD:
      *s = "HTTP GET method not implemented";
      break;
    case SOAP_PUT_METHOD:
      *s = "HTTP PUT method not implemented";
      break;
    case SOAP_HTTP_METHOD:
      *s = "HTTP method not implemented";
      break;
    case SOAP_EOM:
      *s = "Out of memory";
      break;
    case SOAP_MOE:
      *s = "Memory overflow or memory corruption error";
      break;
    case SOAP_HDR:
      *s = "Header line too long";
      break;
    case SOAP_IOB:
      *s = "Array index out of bounds";
      break;
    case SOAP_NULL:
      *s = soap_set_validation_fault(soap, "nil not allowed", NULL);
      break;
    case SOAP_DUPLICATE_ID:
      *s = soap_set_validation_fault(soap, "multiple definitions of id ", soap->id);
      if (soap->version == 2)
        *soap_faultsubcode(soap) = "SOAP-ENC:DuplicateID";
      break;
    case SOAP_MISSING_ID:
      *s = soap_set_validation_fault(soap, "missing id for ref ", soap->id);
      if (soap->version == 2)
        *soap_faultsubcode(soap) = "SOAP-ENC:MissingID";
      break;
    case SOAP_HREF:
      *s = soap_set_validation_fault(soap, "incompatible object type ref/id pair ", soap->id);
      break;
    case SOAP_FAULT:
      break;
#ifndef WITH_NOIO
    case SOAP_UDP_ERROR:
      *s = "Message too large for UDP packet";
      break;
    case SOAP_TCP_ERROR:
      *s = tcp_error(soap);
      break;
#endif
    case SOAP_HTTP_ERROR:
      *s = "An HTTP processing error occurred";
      break;
    case SOAP_SSL_ERROR:
#ifdef WITH_OPENSSL
      *s = "SSL/TLS error";
#else
      *s = "OpenSSL not installed: recompile with -DWITH_OPENSSL";
#endif
      break;
    case SOAP_PLUGIN_ERROR:
      *s = "Plugin registry error";
      break;
    case SOAP_DIME_ERROR:
      *s = "DIME format error";
      break;
    case SOAP_DIME_HREF:
      *s = "DIME href to missing attachment";
      break;
    case SOAP_DIME_MISMATCH:
      *s = "DIME version/transmission error";
      break;
    case SOAP_DIME_END:
      *s = "End of DIME error";
      break;
    case SOAP_MIME_ERROR:
      *s = "MIME format error";
      break;
    case SOAP_MIME_HREF:
      *s = "MIME href to missing attachment";
      break;
    case SOAP_MIME_END:
      *s = "End of MIME error";
      break;
    case SOAP_ZLIB_ERROR:
#ifdef WITH_ZLIB
      sprintf(soap->msgbuf, "Zlib/gzip error: '%s'", soap->d_stream->msg?soap->d_stream->msg:SOAP_STR_EOS);
      *s = soap->msgbuf;
#else
      *s = "Zlib/gzip not installed for (de)compression: recompile with -DWITH_GZIP";
#endif
      break;
    case SOAP_REQUIRED:
      *s = soap_set_validation_fault(soap, "missing required attribute", NULL);
      break;
    case SOAP_PROHIBITED:
      *s = soap_set_validation_fault(soap, "prohibited attribute present", NULL);
      break;
    case SOAP_OCCURS:
      *s = soap_set_validation_fault(soap, "occurrence violation", NULL);
      break;
    case SOAP_LENGTH:
      *s = soap_set_validation_fault(soap, "content range or length violation", NULL);
      break;
    case SOAP_FD_EXCEEDED:
      *s = "Maximum number of open connections was reached (no define HAVE_POLL): increase FD_SETSIZE";
      break;
    case SOAP_STOP:
      *s = "Stopped: no response to be sent or received (informative)";
      break;
#endif
    case SOAP_EOF:
#ifndef WITH_NOIO
      strcpy(soap->msgbuf, soap_strerror(soap));
#ifndef WITH_LEAN
      if (strlen(soap->msgbuf) + 25 < sizeof(soap->msgbuf))
      { memmove(soap->msgbuf + 25, soap->msgbuf, strlen(soap->msgbuf) + 1);
        memcpy(soap->msgbuf, "End of file or no input: ", 25);
      }
#endif
      *s = soap->msgbuf;
      break;
#else
      *s = "End of file or no input";
      break;
#endif
    default:
#ifndef WITH_NOHTTP
#ifndef WITH_LEAN
      if (soap->error > 200 && soap->error < 600)
      { sprintf(soap->msgbuf, "HTTP Error: %d %s", soap->error, http_error(soap, soap->error));
        *s = soap->msgbuf;
      }
      else
#endif
#endif
      { sprintf(soap->msgbuf, "Error %d", soap->error);
        *s = soap->msgbuf;
      }
    }
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_send_fault(struct soap *soap)
{ register int status = soap->error;
  if (status == SOAP_STOP)
    return soap_closesock(soap);
  DBGLOG(TEST,SOAP_MESSAGE(fdebug, "Sending back fault struct for error code %d\n", soap->error));
  soap->keep_alive = 0; /* to terminate connection */
  soap_set_fault(soap);
  if (soap->error < 200 && soap->error != SOAP_FAULT)
    soap->header = NULL;
  if (status != SOAP_EOF || (!soap->recv_timeout && !soap->send_timeout))
  { int r = 1;
#ifndef WITH_NOIO
    if (soap->fpoll && soap->fpoll(soap))
      r = 0;
#ifndef WITH_LEAN
    else if (soap_valid_socket(soap->socket))
    { r = tcp_select(soap, soap->socket, SOAP_TCP_SELECT_RCV | SOAP_TCP_SELECT_SND, 0);
      if (r > 0)
      { if (!(r & SOAP_TCP_SELECT_SND)
	 || ((r & SOAP_TCP_SELECT_RCV)
          && recv(soap->socket, soap->tmpbuf, 1, MSG_PEEK) < 0))
          r = 0;
      }
    }
#endif
#endif
    if (r > 0)
    { soap->error = SOAP_OK;
      soap_serializeheader(soap);
      soap_serializefault(soap);
      soap_begin_count(soap);
      if (soap->mode & SOAP_IO_LENGTH)
      { soap_envelope_begin_out(soap);
        soap_putheader(soap);
        soap_body_begin_out(soap);
        soap_putfault(soap);
        soap_body_end_out(soap);
        soap_envelope_end_out(soap);
      }
      soap_end_count(soap);
      if (soap_response(soap, status)
       || soap_envelope_begin_out(soap)
       || soap_putheader(soap)
       || soap_body_begin_out(soap)
       || soap_putfault(soap)
       || soap_body_end_out(soap)
       || soap_envelope_end_out(soap))
        return soap_closesock(soap);
      soap_end_send(soap);
    }
  } 
  soap->error = status;
  return soap_closesock(soap);
}
#endif

/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_recv_fault(struct soap *soap, int check)
{ register int status = soap->error;
  DBGLOG(TEST,SOAP_MESSAGE(fdebug, "Check if receiving SOAP Fault\n"));
  if (!check)
  { /* try getfault when no tag or tag mismatched at level 2, otherwise ret */
    if (soap->error != SOAP_NO_TAG
     && (soap->error != SOAP_TAG_MISMATCH || soap->level != 2))
      return soap->error;
  }
  soap->error = SOAP_OK;
  if (soap_getfault(soap))
  { /* check flag set: check if SOAP Fault is present, if not just return */
    if (check && soap->error == SOAP_TAG_MISMATCH && soap->level == 2)
      return soap->error = SOAP_OK;
    DBGLOG(TEST,SOAP_MESSAGE(fdebug, "Error: soap_get_soapfault() failed. Is this a SOAP message at all?\n"));
    *soap_faultcode(soap) = (soap->version == 2 ? "SOAP-ENV:Sender" : "SOAP-ENV:Client");
    soap->error = status;
    soap_set_fault(soap);
  }
  else
  { register const char *s = *soap_faultcode(soap);
    if (!soap_match_tag(soap, s, "SOAP-ENV:Server") || !soap_match_tag(soap, s, "SOAP-ENV:Receiver"))
      status = SOAP_SVR_FAULT; 
    else if (!soap_match_tag(soap, s, "SOAP-ENV:Client") || !soap_match_tag(soap, s, "SOAP-ENV:Sender"))
      status = SOAP_CLI_FAULT;
    else if (!soap_match_tag(soap, s, "SOAP-ENV:MustUnderstand"))
      status = SOAP_MUSTUNDERSTAND;
    else if (!soap_match_tag(soap, s, "SOAP-ENV:VersionMismatch"))
      status = SOAP_VERSIONMISMATCH;
    else
    { DBGLOG(TEST,SOAP_MESSAGE(fdebug, "Received SOAP Fault code %s\n", s));
      status = SOAP_FAULT;
    }
    if (!soap_body_end_in(soap))
      soap_envelope_end_in(soap);
  }
  soap_end_recv(soap);
  soap->error = status;
  return soap_closesock(soap);
}
#endif

/******************************************************************************/
#ifndef WITH_NOHTTP
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_send_empty_response(struct soap *soap, int httpstatuscode)
{ register soap_mode m = soap->omode;
  soap->count = 0;
  if ((m & SOAP_IO) == SOAP_IO_CHUNK)
    soap->omode = (m & ~SOAP_IO) | SOAP_IO_BUFFER;
  if (soap_response(soap, httpstatuscode) || soap_end_send(soap))
  { soap->omode = m;
    return soap_closesock(soap);
  }
  soap->omode = m;
  return soap->error = SOAP_STOP; /* stops the server's response */
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_NOHTTP
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_recv_empty_response(struct soap *soap)
{ if (!soap_begin_recv(soap))
    soap_end_recv(soap);
  else if (soap->error == SOAP_NO_DATA || soap->error == 202)
    soap->error = SOAP_OK;
  return soap_closesock(soap);
}
#endif
#endif

/******************************************************************************/
#ifndef WITH_NOIO
#ifndef PALM_1
static const char*
soap_strerror(struct soap *soap)
{ register int err = soap->errnum;
  if (err)
  {
#ifndef WIN32
# ifdef HAVE_STRERROR_R
    strerror_r(err, soap->msgbuf, sizeof(soap->msgbuf));
# else
    return strerror(err);
# endif
#else
#ifndef UNDER_CE
    DWORD len;
    *soap->msgbuf = '\0';
    len = FormatMessageA(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, NULL, err, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)soap->msgbuf, (DWORD)sizeof(soap->msgbuf), NULL);
#else
    DWORD i, len;
    *soap->msgbuf = '\0';
    len = FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, NULL, err, 0, (LPTSTR)soap->msgbuf, (DWORD)(sizeof(soap->msgbuf)/sizeof(TCHAR)), NULL);
    for (i = 0; i <= len; i++)
    { if (((TCHAR*)soap->msgbuf)[i] < 0x80)
        soap->msgbuf[i] = (char)((TCHAR*)soap->msgbuf)[i];
      else
        soap->msgbuf[i] = '?';
    }
#endif
#endif
  }
  else
  { char *s = soap->msgbuf;
#ifndef WITH_LEAN
    int rt = soap->recv_timeout, st = soap->send_timeout;
    int ru = ' ', su = ' ';
#endif
    strcpy(s, "Operation interrupted or timed out");
#ifndef WITH_LEAN
    if (rt < 0)
    { rt = -rt;
      ru = 'u';
    }
    if (st < 0)
    { st = -st;
      su = 'u';
    }
    if (rt)
      sprintf(s + strlen(s), " (%d%cs receive delay)", rt, ru);
    if (st)
      sprintf(s + strlen(s), " (%d%cs send delay)", st, su);
#endif
  }
  return soap->msgbuf;
}
#endif
#endif 

/******************************************************************************/
#ifndef PALM_2
static int
soap_set_error(struct soap *soap, const char *faultcode, const char *faultsubcodeQName, const char *faultstring, const char *faultdetailXML, int soaperror)
{ *soap_faultcode(soap) = faultcode;
  if (faultsubcodeQName)
    *soap_faultsubcode(soap) = faultsubcodeQName;
  *soap_faultstring(soap) = faultstring;
  if (faultdetailXML && *faultdetailXML)
  { register const char **s = soap_faultdetail(soap);
    if (s)
      *s = faultdetailXML;
  }
  return soap->error = soaperror;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_set_sender_error(struct soap *soap, const char *faultstring, const char *faultdetailXML, int soaperror)
{ return soap_set_error(soap, soap->version == 2 ? "SOAP-ENV:Sender" : "SOAP-ENV:Client", NULL, faultstring, faultdetailXML, soaperror);
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_set_receiver_error(struct soap *soap, const char *faultstring, const char *faultdetailXML, int soaperror)
{ return soap_set_error(soap, soap->version == 2 ? "SOAP-ENV:Receiver" : "SOAP-ENV:Server", NULL, faultstring, faultdetailXML, soaperror);
}
#endif

/******************************************************************************/
#ifndef PALM_2
static int
soap_copy_fault(struct soap *soap, const char *faultcode, const char *faultsubcodeQName, const char *faultstring, const char *faultdetailXML)
{ char *r = NULL, *s = NULL, *t = NULL;
  if (faultsubcodeQName)
    r = soap_strdup(soap, faultsubcodeQName);
  if (faultstring)
    s = soap_strdup(soap, faultstring);
  if (faultdetailXML)
    t = soap_strdup(soap, faultdetailXML);
  return soap_set_error(soap, faultcode, r, s, t, SOAP_FAULT);
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_sender_fault(struct soap *soap, const char *faultstring, const char *faultdetailXML)
{ return soap_sender_fault_subcode(soap, NULL, faultstring, faultdetailXML);
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_sender_fault_subcode(struct soap *soap, const char *faultsubcodeQName, const char *faultstring, const char *faultdetailXML)
{ return soap_copy_fault(soap, soap->version == 2 ? "SOAP-ENV:Sender" : "SOAP-ENV:Client", faultsubcodeQName, faultstring, faultdetailXML);
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_receiver_fault(struct soap *soap, const char *faultstring, const char *faultdetailXML)
{ return soap_receiver_fault_subcode(soap, NULL, faultstring, faultdetailXML);
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
int
SOAP_FMAC2
soap_receiver_fault_subcode(struct soap *soap, const char *faultsubcodeQName, const char *faultstring, const char *faultdetailXML)
{ return soap_copy_fault(soap, soap->version == 2 ? "SOAP-ENV:Receiver" : "SOAP-ENV:Server", faultsubcodeQName, faultstring, faultdetailXML);
}
#endif

/******************************************************************************/
#ifndef PALM_2
#ifndef WITH_NOSTDLIB
SOAP_FMAC1
void
SOAP_FMAC2
soap_print_fault(struct soap *soap, FILE *fd)
{ if (soap_check_state(soap))
    fprintf(fd, "Error: soap struct state not initialized\n");
  else if (soap->error)
  { const char *c, *v = NULL, *s, **d;
    d = soap_faultcode(soap);
    if (!*d)
      soap_set_fault(soap);
    c = *d;
    if (soap->version == 2)
      v = *soap_faultsubcode(soap);
    s = *soap_faultstring(soap);
    d = soap_faultdetail(soap);
    fprintf(fd, "%s%d fault: %s [%s]\n\"%s\"\nDetail: %s\n", soap->version ? "SOAP 1." : "Error ", soap->version ? (int)soap->version : soap->error, c, v ? v : "no subcode", s ? s : "[no reason]", d && *d ? *d : "[no detail]");
  }
}
#endif
#endif
 
/******************************************************************************/
#ifdef __cplusplus
#ifndef WITH_LEAN
#ifndef WITH_NOSTDLIB
SOAP_FMAC1
void
SOAP_FMAC2
soap_stream_fault(struct soap *soap, std::ostream& os)
{ if (soap_check_state(soap))
    os << "Error: soap struct state not initialized\n";
  else if (soap->error)
  { const char *c, *v = NULL, *s, **d;
    d = soap_faultcode(soap);
    if (!*d)
      soap_set_fault(soap);
    c = *d;
    if (soap->version == 2)
      v = *soap_faultsubcode(soap);
    s = *soap_faultstring(soap);
    d = soap_faultdetail(soap);
    os << (soap->version ? "SOAP 1." : "Error ")
       << (soap->version ? (int)soap->version : soap->error)
       << " fault: " << c
       << "[" << (v ? v : "no subcode") << "]"
       << std::endl
       << "\"" << (s ? s : "[no reason]") << "\""
       << std::endl
       << "Detail: " << (d && *d ? *d : "[no detail]")
       << std::endl;
  }
}
#endif
#endif
#endif
 
/******************************************************************************/
#ifndef WITH_LEAN
#ifndef WITH_NOSTDLIB
SOAP_FMAC1
char*
SOAP_FMAC2
soap_sprint_fault(struct soap *soap, char *buf, size_t len)
{ if (soap_check_state(soap))
    strncpy(buf, "Error: soap struct not initialized", len);
  else if (soap->error)
  { const char *c, *v = NULL, *s, **d;
    d = soap_faultcode(soap);
    if (!*d)
      soap_set_fault(soap);
    c = *d;
    if (soap->version == 2)
      v = *soap_faultsubcode(soap);
    s = *soap_faultstring(soap);
    d = soap_faultdetail(soap);
#ifdef HAVE_SNPRINTF
# ifdef WIN32
    _snprintf
# else
    snprintf
# endif
      (buf, len, "%s%d fault: %s [%s]\n\"%s\"\nDetail: %s\n", soap->version ? "SOAP 1." : "Error ", soap->version ? (int)soap->version : soap->error, c, v ? v : "no subcode", s ? s : "[no reason]", d && *d ? *d : "[no detail]");
#else
    if (len > 40 + (v ? strlen(v) : 0) + (s ? strlen(s) : 0) + (d && *d ? strlen(*d) : 0))
      sprintf(buf, "%s%d fault: %s [%s]\n\"%s\"\nDetail: %s\n", soap->version ? "SOAP 1." : "Error ", soap->version ? (int)soap->version : soap->error, c, v ? v : "no subcode", s ? s : "[no reason]", d && *d ? *d : "[no detail]");
    else if (len > 40)
      sprintf(buf, "%s%d fault: %s\n", soap->version ? "SOAP 1." : "Error ", soap->version ? (int)soap->version : soap->error, c);
    else
      buf[0] = '\0';
#endif
  }
  return buf;
}
#endif
#endif
 
/******************************************************************************/
#ifndef PALM_1
#ifndef WITH_NOSTDLIB
SOAP_FMAC1
void
SOAP_FMAC2
soap_print_fault_location(struct soap *soap, FILE *fd)
{ 
#ifndef WITH_LEAN
  int i, j, c1, c2;
  if (soap->error && soap->error != SOAP_STOP && soap->bufidx <= soap->buflen && soap->buflen > 0 && soap->buflen <= SOAP_BUFLEN)
  { i = (int)soap->bufidx - 1;
    if (i <= 0)
      i = 0;
    c1 = soap->buf[i];
    soap->buf[i] = '\0';
    if ((int)soap->buflen >= i + 1024)
      j = i + 1023;
    else
      j = (int)soap->buflen - 1;
    c2 = soap->buf[j];
    soap->buf[j] = '\0';
    fprintf(fd, "%s%c\n<!-- ** HERE ** -->\n", soap->buf, c1);
    if (soap->bufidx < soap->buflen)
      fprintf(fd, "%s\n", soap->buf + soap->bufidx);
    soap->buf[i] = c1;
    soap->buf[j] = c2;
  }
#endif
}
#endif
#endif
 
/******************************************************************************/
#ifndef PALM_1
SOAP_FMAC1
int
SOAP_FMAC2
soap_register_plugin_arg(struct soap *soap, int (*fcreate)(struct soap*, struct soap_plugin*, void*), void *arg)
{ register struct soap_plugin *p;
  register int r;
  if (!(p = (struct soap_plugin*)SOAP_MALLOC(soap, sizeof(struct soap_plugin))))
    return soap->error = SOAP_EOM;
  p->id = NULL;
  p->data = NULL;
  p->fcopy = NULL;
  p->fdelete = NULL;
  r = fcreate(soap, p, arg);
  if (!r && p->fdelete)
  { p->next = soap->plugins;
    soap->plugins = p;
    DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Registered '%s' plugin\n", p->id));
    return SOAP_OK;
  }
  DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Could not register plugin '%s': plugin returned error %d (or fdelete callback not set)\n", p->id?p->id:"?", r));
  SOAP_FREE(soap, p);
  return r;
}
#endif

/******************************************************************************/
#ifndef PALM_1
static void *
fplugin(struct soap *soap, const char *id)
{ register struct soap_plugin *p;
  for (p = soap->plugins; p; p = p->next)
    if (p->id == id || !strcmp(p->id, id))
      return p->data;
  return NULL;
}
#endif

/******************************************************************************/
#ifndef PALM_2
SOAP_FMAC1
void *
SOAP_FMAC2
soap_lookup_plugin(struct soap *soap, const char *id)
{ return soap->fplugin(soap, id);
}
#endif

/******************************************************************************/
#ifdef __cplusplus
}
#endif

/******************************************************************************\
 *
 *	C++ soap struct methods
 *
\******************************************************************************/

#ifdef __cplusplus
soap::soap()
{ soap_init(this);
}
#endif

/******************************************************************************/
#ifdef __cplusplus
soap::soap(soap_mode m)
{ soap_init1(this, m);
}
#endif

/******************************************************************************/
#ifdef __cplusplus
soap::soap(soap_mode im, soap_mode om)
{ soap_init2(this, im, om);
}
#endif

/******************************************************************************/
#ifdef __cplusplus
soap::soap(const struct soap& soap)
{ soap_copy_context(this, &soap);
}
#endif

/******************************************************************************/
#ifdef __cplusplus
soap::~soap()
{ soap_destroy(this);
  soap_end(this);
  soap_done(this);
}
#endif

/******************************************************************************/
