// -*- C++ -*-
//
// $Id: OS_NS_dirent.inl 80826 2008-03-04 14:51:23Z wotte $

#include "ace/OS_Memory.h"

#if defined (ACE_LACKS_ALPHASORT)
# include "ace/OS_NS_string.h"
#endif /* ACE_LACKS_ALPHASORT */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE_OS
{

ACE_INLINE void
closedir (ACE_DIR *d)
{
#if defined (ACE_HAS_DIRENT)
# if defined (ACE_WIN32) && defined (ACE_LACKS_CLOSEDIR)
  ACE_OS::closedir_emulation (d);
  delete [] d->directory_name_;
  delete d;
# elif defined (ACE_HAS_WCLOSEDIR) && defined (ACE_USES_WCHAR)
  ::wclosedir (d);
# else /* ACE_WIN32 && ACE_LACKS_CLOSEDIR */
  ::closedir (d);
# endif /* ACE_WIN32 && ACE_LACKS_CLOSEDIR */

#else /* ACE_HAS_DIRENT */
  ACE_UNUSED_ARG (d);
#endif /* ACE_HAS_DIRENT */
}

ACE_INLINE ACE_DIR *
opendir (const ACE_TCHAR *filename)
{
#if defined (ACE_HAS_DIRENT)
#    if defined (ACE_WIN32) && defined (ACE_LACKS_OPENDIR)
  return ::ACE_OS::opendir_emulation (filename);
#  elif defined (ACE_HAS_WOPENDIR) && defined (ACE_USES_WCHAR)
  return ::wopendir (filename);
#    elif defined (ACE_HAS_NONCONST_OPENDIR)
  return ::opendir (const_cast<char *> (filename));
#    else /* ! ACE_WIN32 && ACE_LACKS_OPENDIR */
  return ::opendir (ACE_TEXT_ALWAYS_CHAR (filename));
#    endif /* ACE_WIN32 && ACE_LACKS_OPENDIR */
#else
  ACE_UNUSED_ARG (filename);
  ACE_NOTSUP_RETURN (0);
#endif /* ACE_HAS_DIRENT */
}

ACE_INLINE struct ACE_DIRENT *
readdir (ACE_DIR *d)
{
#if defined (ACE_HAS_DIRENT)
#  if defined (ACE_WIN32) && defined (ACE_LACKS_READDIR)
     return ACE_OS::readdir_emulation (d);
#  elif defined (ACE_HAS_WREADDIR) && defined (ACE_USES_WCHAR)
     return ::wreaddir (d);
#  else /* ACE_WIN32 && ACE_LACKS_READDIR */
     return ::readdir (d);
#  endif /* ACE_WIN32 && ACE_LACKS_READDIR */
#else
  ACE_UNUSED_ARG (d);
  ACE_NOTSUP_RETURN (0);
#endif /* ACE_HAS_DIRENT */
}

ACE_INLINE int
readdir_r (ACE_DIR *dirp,
           struct ACE_DIRENT *entry,
           struct ACE_DIRENT **result)
{
#if !defined (ACE_HAS_REENTRANT_FUNCTIONS)
  ACE_UNUSED_ARG (entry);
  // <result> has better not be 0!
  *result = ACE_OS::readdir (dirp);
  if (*result)
    return 0; // Keep iterating
  else
    return 1; // Oops, some type of error!
#elif defined (ACE_HAS_DIRENT) && !defined (ACE_LACKS_READDIR_R)
#  if defined (ACE_HAS_3_PARAM_READDIR_R)
       return ::readdir_r (dirp, entry, result);
#  else
       // <result> had better not be 0!
       *result = ::readdir_r (dirp, entry);
       return 0;
#  endif /* sun */
#else  /* ! ACE_HAS_DIRENT  ||  ACE_LACKS_READDIR_R */
  ACE_UNUSED_ARG (dirp);
  ACE_UNUSED_ARG (entry);
  ACE_UNUSED_ARG (result);
  ACE_NOTSUP_RETURN (0);

#endif /* ACE_HAS_REENTRANT_FUNCTIONS */
}

ACE_INLINE void
rewinddir (ACE_DIR *d)
{
#if defined (ACE_HAS_DIRENT)
#  if defined (ACE_HAS_WREWINDDIR) && defined (ACE_USES_WCHAR)
  ::wrewinddir (d);
#  elif !defined (ACE_LACKS_REWINDDIR)
  ace_rewinddir_helper (d);
#  else
  ACE_UNUSED_ARG (d);
#  endif /* !defined (ACE_LACKS_REWINDDIR) */
#endif /* ACE_HAS_DIRENT */
}

ACE_INLINE int
scandir (const ACE_TCHAR *dirname,
         struct ACE_DIRENT **namelist[],
         ACE_SCANDIR_SELECTOR selector,
         ACE_SCANDIR_COMPARATOR comparator)
{
#if defined (ACE_HAS_SCANDIR)
  return ::scandir (ACE_TEXT_ALWAYS_CHAR (dirname),
                    namelist,
#  if defined (ACE_SCANDIR_SEL_LACKS_CONST)
                    reinterpret_cast<ACE_SCANDIR_OS_SELECTOR> (selector),
#  else
                    selector,
#  endif /* ACE_SCANDIR_SEL_LACKS_CONST */
#  if defined (ACE_SCANDIR_CMP_USES_VOIDPTR) || \
      defined (ACE_SCANDIR_CMP_USES_CONST_VOIDPTR)
                    reinterpret_cast<ACE_SCANDIR_OS_COMPARATOR> (comparator));
#  else
                    comparator);
#  endif /* ACE_SCANDIR_CMP_USES_VOIDPTR */

#else /* ! defined ( ACE_HAS_SCANDIR) */
  return ACE_OS::scandir_emulation (dirname, namelist, selector, comparator);
#endif /* ACE_HAS_SCANDIR */
}

ACE_INLINE int
alphasort (const void *a, const void *b)
{
#if defined (ACE_LACKS_ALPHASORT)
  return ACE_OS::strcmp ((*static_cast<const struct ACE_DIRENT * const *>(a))->d_name,
                          (*static_cast<const struct ACE_DIRENT * const *>(b))->d_name);
#else
#  if defined (ACE_SCANDIR_CMP_USES_VOIDPTR)
  return ::alphasort (const_cast<void *>(a),
                      const_cast<void *>(b));
#  elif defined (ACE_SCANDIR_CMP_USES_CONST_VOIDPTR)
  return ::alphasort (a, b);
#  else
  return ::alphasort ((const struct ACE_DIRENT **)a,
                      (const struct ACE_DIRENT **)b);
#  endif
#endif
}

ACE_INLINE void
seekdir (ACE_DIR *d, long loc)
{
#if defined (ACE_HAS_DIRENT) && !defined (ACE_LACKS_SEEKDIR)
  ::seekdir (d, loc);
#else  /* ! ACE_HAS_DIRENT  ||  ACE_LACKS_SEEKDIR */
  ACE_UNUSED_ARG (d);
  ACE_UNUSED_ARG (loc);
#endif /* ! ACE_HAS_DIRENT  ||  ACE_LACKS_SEEKDIR */
}

ACE_INLINE long
telldir (ACE_DIR *d)
{
#if defined (ACE_HAS_DIRENT) && !defined (ACE_LACKS_TELLDIR)
  return ::telldir (d);
#else  /* ! ACE_HAS_DIRENT  ||  ACE_LACKS_TELLDIR */
  ACE_UNUSED_ARG (d);
  ACE_NOTSUP_RETURN (-1);
#endif /* ! ACE_HAS_DIRENT  ||  ACE_LACKS_TELLDIR */
}

}

ACE_END_VERSIONED_NAMESPACE_DECL
