// $Id: OS_NS_stdio.cpp 82586 2008-08-11 12:46:00Z johnnyw $
#include "ace/OS_NS_stdio.h"
#include "ace/OS_NS_Thread.h"
ACE_RCSID (ace,
           OS_NS_stdio,
           "$Id: OS_NS_stdio.cpp 82586 2008-08-11 12:46:00Z johnnyw $")

#if !defined (ACE_HAS_INLINED_OSCALLS)
# include "ace/OS_NS_stdio.inl"
#endif /* ACE_HAS_INLINED_OSCALLS */
# if defined (ACE_WIN32)
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_TEXT_OSVERSIONINFO ACE_OS::win32_versioninfo_;
HINSTANCE ACE_OS::win32_resource_module_;
ACE_END_VERSIONED_NAMESPACE_DECL
#   if defined (ACE_HAS_DLL) && (ACE_HAS_DLL == 1) && !defined (ACE_HAS_WINCE)
// This function is called by the OS when the ACE DLL is loaded. We
// use it to determine the default module containing ACE's resources.
extern "C" BOOL WINAPI DllMain(HINSTANCE instance, DWORD reason, LPVOID)
{
  if (reason == DLL_PROCESS_ATTACH)
    {
#     if defined (ACE_DISABLES_THREAD_LIBRARY_CALLS) && (ACE_DISABLES_THREAD_LIBRARY_CALLS == 1)
      ::DisableThreadLibraryCalls (instance);
#     endif /* ACE_DISABLES_THREAD_LIBRARY_CALLS */
      ACE_OS::set_win32_resource_module(instance);
    }
  else if (reason == DLL_THREAD_DETACH)
    {
      ACE_OS::cleanup_tss (0);
    }
  return TRUE;
}
#   endif /* ACE_HAS_DLL && ACE_HAS_DLL == 1 */
# endif /* ACE_WIN32 */
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
void
ACE_OS::ace_flock_t::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_OS_TRACE ("ACE_OS::ace_flock_t::dump");
# if 0
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("handle_ = %u"), this->handle_));
#   if defined (ACE_WIN32)
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\nInternal = %d"),
              this->overlapped_.Internal));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\nInternalHigh = %d"),
              this->overlapped_.InternalHigh));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\nOffsetHigh = %d"),
              this->overlapped_.OffsetHigh));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\nhEvent = %d"),
              this->overlapped_.hEvent));
#   else
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\nl_whence = %d"),
              this->lock_.l_whence));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\nl_start = %d"), this->lock_.l_start));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\nl_len = %d"), this->lock_.l_len));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\nl_type = %d"), this->lock_.l_type));
#   endif /* ACE_WIN32 */
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
# endif /* 0 */
#endif /* ACE_HAS_DUMP */
}
/*****************************************************************************/
#if defined (ACE_USES_WCHAR)
void ACE_OS::checkUnicodeFormat (FILE* fp)
{
  if (fp != 0)
    {
      // Due to the ACE_TCHAR definition, all default input files, such as
      // svc.conf, have to be in Unicode format (small endian) on WinCE
      // because ACE has all 'char' converted into ACE_TCHAR.
      // However, for TAO, ASCII files, such as IOR file, can still be read
      // and be written without any error since given buffers are all in 'char'
      // type instead of ACE_TCHAR.  Therefore, it is user's reponsibility to
      // select correct buffer type.
      // At this point, check if the file is Unicode or not.
      ACE_UINT16 first_two_bytes;
      size_t numRead =
        ACE_OS::fread(&first_two_bytes, sizeof (first_two_bytes), 1, fp);
      if (numRead == 1)
        {
          if ((first_two_bytes != 0xFFFE) && // not a small endian Unicode file
              (first_two_bytes != 0xFEFF))   // not a big endian Unicode file
            {
              // set file pointer back to the beginning
#if defined (ACE_WIN32)
              ACE_OS::fseek(fp, 0, FILE_BEGIN);
#else
              ACE_OS::fseek(fp, 0, SEEK_SET);
#endif /* ACE_WIN32 */
            }
        }
      // if it is a Unicode file, file pointer will be right next to the first
      // two-bytes
    }
}
#endif  // ACE_USES_WCHAR
#if defined (ACE_WIN32) && !defined (ACE_HAS_WINCE)
namespace
{
  /// Translate fopen's mode char to open's mode.  This helper function
  /// is here to avoid maintaining several pieces of identical code.
  void
  fopen_mode_to_open_mode_converter (ACE_TCHAR x, int & hmode)
  {
    switch (x)
      {
      case ACE_TEXT ('r'):
        if (ACE_BIT_DISABLED (hmode, _O_RDWR))
          {
            ACE_CLR_BITS (hmode, _O_WRONLY);
            ACE_SET_BITS (hmode, _O_RDONLY);
          }
        break;
      case ACE_TEXT ('w'):
        if (ACE_BIT_DISABLED (hmode, _O_RDWR))
          {
            ACE_CLR_BITS (hmode, _O_RDONLY);
            ACE_SET_BITS (hmode, _O_WRONLY);
          }
        ACE_SET_BITS (hmode, _O_CREAT | _O_TRUNC);
        break;
      case ACE_TEXT ('a'):
        if (ACE_BIT_DISABLED (hmode, _O_RDWR))
          {
            ACE_CLR_BITS (hmode, _O_RDONLY);
            ACE_SET_BITS (hmode, _O_WRONLY);
          }
        ACE_SET_BITS (hmode, _O_CREAT | _O_APPEND);
        break;
      case ACE_TEXT ('+'):
        ACE_CLR_BITS (hmode, _O_RDONLY | _O_WRONLY);
        ACE_SET_BITS (hmode, _O_RDWR);
        break;
      case ACE_TEXT ('t'):
        ACE_CLR_BITS (hmode, _O_BINARY);
        ACE_SET_BITS (hmode, _O_TEXT);
        break;
      case ACE_TEXT ('b'):
        ACE_CLR_BITS (hmode, _O_TEXT);
        ACE_SET_BITS (hmode, _O_BINARY);
        break;
      }
  }
}  // Close anonymous namespace
FILE *
ACE_OS::fopen (const char *filename,
               const ACE_TCHAR *mode)
{
  ACE_OS_TRACE ("ACE_OS::fopen");
  int hmode = _O_TEXT;
  // Let the chips fall where they may if the user passes in a NULL
  // mode string.  Convert to an empty mode string to prevent a
  // crash.
  ACE_TCHAR const empty_mode[] = ACE_TEXT ("");
  if (!mode)
    mode = empty_mode;
  for (ACE_TCHAR const* mode_ptr = mode; *mode_ptr != 0; ++mode_ptr)
    fopen_mode_to_open_mode_converter (*mode_ptr, hmode);
  ACE_HANDLE const handle = ACE_OS::open (filename, hmode);
  if (handle != ACE_INVALID_HANDLE)
    {
      hmode &= _O_TEXT | _O_RDONLY | _O_APPEND;
      int const fd = ::_open_osfhandle (intptr_t (handle), hmode);
      if (fd != -1)
        {
#   if defined (ACE_HAS_NONCONST_FDOPEN) && !defined (ACE_USES_WCHAR)
          FILE * const fp = ::_fdopen (fd, const_cast<ACE_TCHAR *> (mode));
#   elif defined (ACE_HAS_NONCONST_FDOPEN) && defined (ACE_USES_WCHAR)
          FILE * const fp = ::_wfdopen (fd, const_cast<ACE_TCHAR *> (mode));
#   elif defined (ACE_USES_WCHAR)
          FILE * const fp = ::_wfdopen (fd, mode);
#   else
          FILE * const fp = ::fdopen (fd, mode);
#   endif /* defined(ACE_HAS_NONCONST_FDOPEN) && !defined (ACE_USES_WCHAR)) */
          if (fp != 0)
          {
#   if defined (ACE_USES_WCHAR)
            checkUnicodeFormat(fp);
#   endif  // ACE_USES_WCHAR
            return fp;
          }
          ::_close (fd);
        }
      ACE_OS::close (handle);
    }
  return 0;
}
#if defined (ACE_HAS_WCHAR)
FILE *
ACE_OS::fopen (const char *filename,
               const ACE_ANTI_TCHAR *mode)
{
  return ACE_OS::fopen (filename, ACE_TEXT_ANTI_TO_TCHAR (mode));
}
FILE *
ACE_OS::fopen (const wchar_t *filename,
               const ACE_ANTI_TCHAR *mode)
{
  return ACE_OS::fopen (filename, ACE_TEXT_ANTI_TO_TCHAR (mode));
}
FILE *
ACE_OS::fopen (const wchar_t *filename,
               const ACE_TCHAR *mode)
{
  ACE_OS_TRACE ("ACE_OS::fopen");
  int hmode = _O_TEXT;
  for (const ACE_TCHAR *mode_ptr = mode; *mode_ptr != 0; mode_ptr++)
    fopen_mode_to_open_mode_converter (*mode_ptr, hmode);
  ACE_HANDLE handle = ACE_OS::open (filename, hmode);
  if (handle != ACE_INVALID_HANDLE)
    {
      hmode &= _O_TEXT | _O_RDONLY | _O_APPEND;
      int const fd = ::_open_osfhandle (intptr_t (handle), hmode);
      if (fd != -1)
        {
#   if defined (ACE_HAS_NONCONST_FDOPEN) && !defined (ACE_USES_WCHAR)
          FILE *fp = ::_fdopen (fd, const_cast<char *> (mode));
#   elif defined (ACE_HAS_NONCONST_FDOPEN) && defined (ACE_USES_WCHAR)
          FILE *fp = ::_wfdopen (fd, const_cast<wchar_t *> (mode));
#   elif defined (ACE_USES_WCHAR)
          FILE *fp = ::_wfdopen (fd, mode);
#   else
          FILE *fp = ::fdopen (fd, mode);
#   endif /* defined(ACE_HAS_NONCONST_FDOPEN) && !defined (ACE_USES_WCHAR)) */
          if (fp != 0)
          {
#   if defined (ACE_USES_WCHAR)
            checkUnicodeFormat(fp);
#   endif  // ACE_USES_WCHAR
            return fp;
          }
          ::_close (fd);
        }
      ACE_OS::close (handle);
    }
  return 0;
}
#endif /* ACE_HAS_WCHAR */
#endif /* ACE_WIN32 */
// The following *printf functions aren't inline because
// they use varargs.
int
ACE_OS::fprintf (FILE *fp, const char *format, ...)
{
  // ACE_OS_TRACE ("ACE_OS::fprintf");
  int result = 0;
  va_list ap;
  va_start (ap, format);
  result = ACE_OS::vfprintf (fp, format, ap);
  va_end (ap);
  return result;
}
#if defined (ACE_HAS_WCHAR)
int
ACE_OS::fprintf (FILE *fp, const wchar_t *format, ...)
{
  // ACE_OS_TRACE ("ACE_OS::fprintf");
  int result = 0;
  va_list ap;
  va_start (ap, format);
  result = ACE_OS::vfprintf (fp, format, ap);
  va_end (ap);
  return result;
}
#endif /* ACE_HAS_WCHAR */
int
ACE_OS::asprintf (char **bufp, const char *format, ...)
{
  // ACE_OS_TRACE ("ACE_OS::asprintf");
  int result;
  va_list ap;
  va_start (ap, format);
  result = ACE_OS::vasprintf (bufp, format, ap);
  va_end (ap);
  return result;
}
#if defined (ACE_HAS_WCHAR)
int
ACE_OS::asprintf (wchar_t **bufp, const wchar_t *format, ...)
{
  // ACE_OS_TRACE ("ACE_OS::asprintf");
  int result;
  va_list ap;
  va_start (ap, format);
  result = ACE_OS::vasprintf (bufp, format, ap);
  va_end (ap);
  return result;
}
#endif /* ACE_HAS_WCHAR */
int
ACE_OS::printf (const char *format, ...)
{
  // ACE_OS_TRACE ("ACE_OS::printf");
  int result;
  va_list ap;
  va_start (ap, format);
  result = ACE_OS::vprintf (format, ap);
  va_end (ap);
  return result;
}
#if defined (ACE_HAS_WCHAR)
int
ACE_OS::printf (const wchar_t *format, ...)
{
  // ACE_OS_TRACE ("ACE_OS::printf");
  int result;
  va_list ap;
  va_start (ap, format);
  result = ACE_OS::vprintf (format, ap);
  va_end (ap);
  return result;
}
#endif /* ACE_HAS_WCHAR */
int
ACE_OS::snprintf (char *buf, size_t maxlen, const char *format, ...)
{
  // ACE_OS_TRACE ("ACE_OS::snprintf");
  va_list ap;
  va_start (ap, format);
  int result = ACE_OS::vsnprintf (buf, maxlen, format, ap);
  va_end (ap);
  return result;
}
#if defined (ACE_HAS_WCHAR)
int
ACE_OS::snprintf (wchar_t *buf, size_t maxlen, const wchar_t *format, ...)
{
  // ACE_OS_TRACE ("ACE_OS::snprintf");
  va_list ap;
  va_start (ap, format);
  int result = ACE_OS::vsnprintf (buf, maxlen, format, ap);
  va_end (ap);
  return result;
}
#endif /* ACE_HAS_WCHAR */
int
ACE_OS::sprintf (char *buf, const char *format, ...)
{
  // ACE_OS_TRACE ("ACE_OS::sprintf");
  va_list ap;
  va_start (ap, format);
  int result = ACE_OS::vsprintf (buf, format, ap);
  va_end (ap);
  return result;
}
#if defined (ACE_HAS_WCHAR)
int
ACE_OS::sprintf (wchar_t *buf, const wchar_t *format, ...)
{
  // ACE_OS_TRACE ("ACE_OS::sprintf");
  va_list ap;
  va_start (ap, format);
  int result = ACE_OS::vsprintf (buf, format, ap);
  va_end (ap);
  return result;
}
#endif /* ACE_HAS_WCHAR */
#if !defined (ACE_HAS_VASPRINTF)
int
ACE_OS::vasprintf_emulation(char **bufp, const char *format, va_list argptr)
{
  va_list ap;
  va_copy (ap, argptr);
  int size = ACE_OS::vsnprintf(0, 0, format, ap);
  va_end (ap);
  if (size != -1)
    {
      char *buf = reinterpret_cast<char*>(ACE_OS::malloc(size + 1));
      if (!buf)
        return -1;
      va_list aq;
      va_copy (aq, argptr);
      size = ACE_OS::vsnprintf(buf, size + 1, format, aq);
      va_end (aq);
      if (size != -1)
        *bufp = buf;
    }
  return size;
}
#endif /* !ACE_HAS_VASPRINTF */
#if defined (ACE_HAS_WCHAR)
#if !defined (ACE_HAS_VASWPRINTF)
int
ACE_OS::vaswprintf_emulation(wchar_t **bufp, const wchar_t *format, va_list argptr)
{
  va_list ap;
  va_copy (ap, argptr);
  int size = ACE_OS::vsnprintf(0, 0, format, ap);
  va_end (ap);
  if (size != -1)
    {
      wchar_t *buf = reinterpret_cast<wchar_t*>
        (ACE_OS::malloc((size + 1) * sizeof(wchar_t)));
      if (!buf)
        return -1;
      va_list aq;
      va_copy (aq, argptr);
      size = ACE_OS::vsnprintf(buf, size + 1, format, aq);
      va_end (aq);
      if (size != -1)
        *bufp = buf;
    }
  return size;
}
#endif /* !ACE_HAS_VASWPRINTF */
#endif /* ACE_HAS_WCHAR */
ACE_END_VERSIONED_NAMESPACE_DECL

