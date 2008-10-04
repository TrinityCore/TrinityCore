// $Id: TLI.cpp 80826 2008-03-04 14:51:23Z wotte $

// Defines the member functions for the base class of the ACE_TLI
// abstraction.

#include "ace/TLI.h"
#include "ace/Log_Msg.h"
#include "ace/OS_Memory.h"
#include "ace/OS_TLI.h"
#include "ace/OS_NS_string.h"
#include "ace/OS_NS_sys_socket.h"
#include "ace/Auto_Ptr.h"

ACE_RCSID(ace, TLI, "$Id: TLI.cpp 80826 2008-03-04 14:51:23Z wotte $")

#if defined (ACE_HAS_TLI)

#if !defined (__ACE_INLINE__)
#include "ace/TLI.inl"
#endif /* __ACE_INLINE__ */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_TLI)

void
ACE_TLI::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_TLI::dump");
#endif /* ACE_HAS_DUMP */
}

ACE_TLI::ACE_TLI (void)
{
  ACE_TRACE ("ACE_TLI::ACE_TLI");
#if defined (ACE_HAS_SVR4_TLI)
// Solaris 2.4 ACE_TLI option handling is broken.  Thus, we must do
// the memory allocation ourselves...  Thanks to John P. Hearn
// (jph@ccrl.nj.nec.com) for the help.

  this->so_opt_req.opt.maxlen = sizeof (opthdr) + sizeof (long);
  ACE_NEW (this->so_opt_req.opt.buf,
           char[this->so_opt_req.opt.maxlen]);

  this->so_opt_ret.opt.maxlen = sizeof (opthdr) + sizeof (long);
  ACE_NEW (this->so_opt_ret.opt.buf,
           char[this->so_opt_ret.opt.maxlen]);

  if (this->so_opt_ret.opt.buf == 0)
    {
      delete [] this->so_opt_req.opt.buf;
      this->so_opt_req.opt.buf = 0;
      return;
    }
#endif /* ACE_HAS_SVR4_TLI */
}

ACE_HANDLE
ACE_TLI::open (const char device[], int oflag, struct t_info *info)
{
  ACE_TRACE ("ACE_TLI::open");
  if (oflag == 0)
    oflag = O_RDWR;
  this->set_handle (ACE_OS::t_open ((char *) device, oflag, info));

  return this->get_handle ();
}

ACE_TLI::~ACE_TLI (void)
{
  ACE_TRACE ("ACE_TLI::~ACE_TLI");
#if defined (ACE_HAS_SVR4_TLI)
  if (this->so_opt_req.opt.buf)
    {
      delete [] this->so_opt_req.opt.buf;
      delete [] this->so_opt_ret.opt.buf;
      this->so_opt_req.opt.buf = 0;
      this->so_opt_ret.opt.buf = 0;
    }
#endif /* ACE_HAS_SVR4_TLI */
}

ACE_TLI::ACE_TLI (const char device[], int oflag, struct t_info *info)
{
  ACE_TRACE ("ACE_TLI::ACE_TLI");
  if (this->open (device, oflag, info) == ACE_INVALID_HANDLE)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                ACE_TEXT ("ACE_TLI::ACE_TLI")));
}

int
ACE_TLI::get_local_addr (ACE_Addr &sa) const
{
  ACE_TRACE ("ACE_TLI::get_local_addr");
  struct netbuf name;

  name.maxlen = sa.get_size ();
  name.buf    = (char *) sa.get_addr ();

  if (ACE_OS::t_getname (this->get_handle (), &name, LOCALNAME) == -1)
    return -1;
  else
    return 0;
}

int
ACE_TLI::close (void)
{
  ACE_TRACE ("ACE_TLI::close");
  int result = 0; // Geisler: result must be int

  if (this->get_handle () != ACE_INVALID_HANDLE)
    {
      result = ACE_OS::t_close (this->get_handle ());
      this->set_handle (ACE_INVALID_HANDLE);
    }
  return result;
}

int
ACE_TLI::set_option (int level, int option, void *optval, int optlen)
{
  /* Set up options for ACE_TLI */
  ACE_TRACE ("ACE_TLI::set_option");

#if defined (ACE_HAS_XTI)
  // ret will get the negotiated option back after attempting to set it.
  // Assume this will fit in the requested size.
  struct t_optmgmt req, ret;
  ACE_NEW_RETURN (req.opt.buf, char[sizeof (struct t_opthdr) + optlen], -1);
#  if (_XOPEN_SOURCE - 0 >= 500)
  auto_ptr<char> req_opt_buf_p (reinterpret_cast<char*> (req.opt.buf));
#  else
  ACE_Auto_Array_Ptr<char> req_opt_buf_p (req.opt.buf);
#  endif /* XPG5 vs XPG4 */
  struct t_opthdr *opthdr =
    reinterpret_cast<struct t_opthdr *> (req.opt.buf);
  ACE_NEW_RETURN (ret.opt.buf, char[sizeof (struct t_opthdr) + optlen], -1);
#  if (_XOPEN_SOURCE - 0 >= 500)
  auto_ptr<char> ret_opt_buf_p (reinterpret_cast<char*> (ret.opt.buf));
#  else
  ACE_Auto_Array_Ptr<char> ret_opt_buf_p (ret.opt.buf);
#  endif /* XPG5 vs XPG4 */

  req.flags = T_NEGOTIATE;
  req.opt.len = sizeof *opthdr + optlen;
  ret.opt.maxlen = req.opt.len;
  opthdr->level = level;
  opthdr->name  = option;
  opthdr->len   = req.opt.len;   // We only request one option at a time.
  ACE_OS::memcpy (&opthdr[1], optval, optlen);
  return ACE_OS::t_optmgmt (this->get_handle (), &req, &ret);

#elif defined (ACE_HAS_SVR4_TLI)
  struct opthdr *opthdr = 0; /* See <sys/socket.h> for info on this format */

  this->so_opt_req.flags = T_NEGOTIATE;
  this->so_opt_req.opt.len = sizeof *opthdr + OPTLEN (optlen);

  if (this->so_opt_req.opt.len > this->so_opt_req.opt.maxlen)
    {
#  if !defined (ACE_HAS_SET_T_ERRNO)
      t_errno = TBUFOVFLW;
#  else
      set_t_errno (TBUFOVFLW);
#  endif /* ACE_HAS_SET_T_ERRNO */
      return -1;
    }

  opthdr = reinterpret_cast<struct opthdr *> (this->so_opt_req.opt.buf);
  opthdr->level = level;
  opthdr->name  = option;
  opthdr->len   = OPTLEN (optlen);
  ACE_OS::memcpy (OPTVAL (opthdr), optval, optlen);

  return ACE_OS::t_optmgmt (this->get_handle (),
                            &this->so_opt_req,
                            &this->so_opt_ret);
#else
  ACE_UNUSED_ARG (level);
  ACE_UNUSED_ARG (option);
  ACE_UNUSED_ARG (optval);
  ACE_UNUSED_ARG (optlen);
  return -1;
#endif /* ACE_HAS_XTI, else ACE_HAS_SVR4_TLI */
}

int
ACE_TLI::get_option (int level, int option, void *optval, int &optlen)
{
  ACE_TRACE ("ACE_TLI::get_option");
#if defined (ACE_HAS_XTI)
  // ret will get the option requested in req.
  struct t_optmgmt req, ret;
  ACE_NEW_RETURN (req.opt.buf, char[sizeof (struct t_opthdr)], -1);
#  if (_XOPEN_SOURCE - 0 >= 500)
  auto_ptr<char> req_opt_buf_p (reinterpret_cast<char*> (req.opt.buf));
#  else
  ACE_Auto_Array_Ptr<char> req_opt_buf_p (req.opt.buf);
#  endif /* XPG5 vs XPG4 */
  struct t_opthdr *opthdr =
    reinterpret_cast<struct t_opthdr *> (req.opt.buf);
  ACE_NEW_RETURN (ret.opt.buf, char[sizeof (struct t_opthdr) + optlen], -1);
#  if (_XOPEN_SOURCE - 0 >= 500)
  auto_ptr<char> ret_opt_buf_p (reinterpret_cast<char*> (ret.opt.buf));
#  else
  ACE_Auto_Array_Ptr<char> ret_opt_buf_p (ret.opt.buf);
#  endif /* XPG5 vs XPG4 */

  req.flags = T_CURRENT;
  req.opt.len = sizeof *opthdr;
  ret.opt.maxlen = sizeof (struct t_opthdr) + optlen;
  opthdr->level = level;
  opthdr->name  = option;
  opthdr->len   = sizeof (*opthdr);    // Just the header on the request
  if (ACE_OS::t_optmgmt (this->get_handle (), &req, &ret) == -1)
    return -1;
  else
    {
      opthdr = reinterpret_cast<struct t_opthdr *> (ret.opt.buf);
      if (opthdr->status == T_NOTSUPPORT)
        {
          errno = ENOTSUP;
          return -1;
        }
      else
        {
          ACE_OS::memcpy (optval, &opthdr[1], optlen);
          return 0;
        }
    }

#elif defined (ACE_HAS_SVR4_TLI)
  struct opthdr *opthdr = 0; /* See <sys/socket.h> for details on this format */

  this->so_opt_req.flags = T_CHECK;
  this->so_opt_ret.opt.len = sizeof *opthdr + OPTLEN (optlen);

  if (this->so_opt_ret.opt.len > this->so_opt_ret.opt.maxlen)
    {
#if !defined (ACE_HAS_SET_T_ERRNO)
      t_errno = TBUFOVFLW;
#else
      set_t_errno (TBUFOVFLW);
#endif /* ACE_HAS_SET_T_ERRNO */
      return -1;
    }

  opthdr        = (struct opthdr *) this->so_opt_req.opt.buf;
  opthdr->level = level;
  opthdr->name  = option;
  opthdr->len   = OPTLEN (optlen);
  if (ACE_OS::t_optmgmt (this->get_handle (), &this->so_opt_req, &this->so_opt_ret) == -1)
    return -1;
  else
    {
      ACE_OS::memcpy (optval, OPTVAL (opthdr), optlen);
      return 0;
    }
#else
  ACE_UNUSED_ARG (level);
  ACE_UNUSED_ARG (option);
  ACE_UNUSED_ARG (optval);
  ACE_UNUSED_ARG (optlen);
  return -1;
#endif /* ACE_HAS_SVR4_TLI */
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_TLI */
