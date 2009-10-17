// $Id: FILE_Addr.cpp 80826 2008-03-04 14:51:23Z wotte $
#include "ace/FILE_Addr.h"
#include "ace/Lib_Find.h"
#include "ace/Log_Msg.h"
#include "ace/OS_NS_stdlib.h"
#include "ace/OS_NS_string.h"
#include "ace/os_include/sys/os_socket.h"
#if !defined (__ACE_INLINE__)
#include "ace/FILE_Addr.inl"
#endif /* __ACE_INLINE__ */
ACE_RCSID(ace, FILE_Addr, "$Id: FILE_Addr.cpp 80826 2008-03-04 14:51:23Z wotte $")
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_ALLOC_HOOK_DEFINE(ACE_FILE_Addr)
ACE_FILE_Addr::ACE_FILE_Addr (void)
  : ACE_Addr (AF_FILE, sizeof this->filename_ / sizeof (ACE_TCHAR))
{
  this->filename_[0] = '\0';
}
int
ACE_FILE_Addr::set (const ACE_FILE_Addr &sa)
{
  if (sa.get_type () == AF_ANY)
    {
#if defined (ACE_DEFAULT_TEMP_FILE)
      // Create a temporary file.
      ACE_OS::strcpy (this->filename_,
                      ACE_DEFAULT_TEMP_FILE);
#else /* ACE_DEFAULT_TEMP_FILE */
      if (ACE::get_temp_dir (this->filename_, MAXPATHLEN - 15) == -1)
        // -15 for ace-file-XXXXXX
        {
          ACE_ERROR ((LM_ERROR,
                      ACE_TEXT ("Temporary path too long, ")
                      ACE_TEXT ("defaulting to current directory\n")));
          this->filename_[0] = 0;
        }
      // Add the filename to the end
      ACE_OS::strcat (this->filename_, ACE_TEXT ("ace-fileXXXXXX"));
#endif /* ACE_DEFAULT_TEMP_FILE */
      if (ACE_OS::mktemp (this->filename_) == 0)
        return -1;
      this->base_set (AF_FILE,
                      static_cast<int> (ACE_OS::strlen (this->filename_) + 1));
    }
  else
    {
      (void)ACE_OS::strsncpy (this->filename_, sa.filename_, sa.get_size ());
      this->base_set (sa.get_type (), sa.get_size ());
    }
  return 0;
}
// Copy constructor.
ACE_FILE_Addr::ACE_FILE_Addr (const ACE_FILE_Addr &sa)
  : ACE_Addr (AF_FILE, sizeof this->filename_)
{
  this->set (sa);
}
int
ACE_FILE_Addr::set (const ACE_TCHAR *filename)
{
  this->ACE_Addr::base_set (AF_FILE,
                            static_cast<int> (ACE_OS::strlen (filename) + 1));
  (void) ACE_OS::strsncpy (this->filename_,
                           filename,
                           sizeof this->filename_ / sizeof (ACE_TCHAR));
  return 0;
}
ACE_FILE_Addr &
ACE_FILE_Addr::operator= (const ACE_FILE_Addr &sa)
{
  if (this != &sa)
    this->set (sa);
  return *this;
}
// Create a ACE_Addr from a ACE_FILE pathname.
ACE_FILE_Addr::ACE_FILE_Addr (const ACE_TCHAR *filename)
{
  this->set (filename);
}
int
ACE_FILE_Addr::addr_to_string (ACE_TCHAR *s, size_t len) const
{
  ACE_OS::strsncpy (s, this->filename_, len);
  return 0;
}
// Return the address.
void *
ACE_FILE_Addr::get_addr (void) const
{
  return (void *)&this->filename_;
}
void
ACE_FILE_Addr::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_FILE_Addr::dump");
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("filename_ = %s"), this->filename_));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}
ACE_END_VERSIONED_NAMESPACE_DECL

