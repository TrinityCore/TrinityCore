// $Id: OS_NS_dirent.cpp 80826 2008-03-04 14:51:23Z wotte $

#include "ace/OS_NS_dirent.h"

ACE_RCSID(ace, OS_NS_dirent, "$Id: OS_NS_dirent.cpp 80826 2008-03-04 14:51:23Z wotte $")

#if !defined (ACE_HAS_INLINED_OSCALLS)
# include "ace/OS_NS_dirent.inl"
#endif /* ACE_HAS_INLINED_OSCALLS */

#include "ace/OS_NS_errno.h"
#include "ace/OS_NS_string.h"
#include "ace/Log_Msg.h"
#include "ace/OS_NS_stdlib.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

#if defined (ACE_LACKS_CLOSEDIR)
void
ACE_OS::closedir_emulation (ACE_DIR *d)
{
#if defined (ACE_WIN32)
  if (d->current_handle_ != INVALID_HANDLE_VALUE)
    ::FindClose (d->current_handle_);

  d->current_handle_ = INVALID_HANDLE_VALUE;
  d->started_reading_ = 0;
  if (d->dirent_ != 0)
    {
      ACE_OS::free (d->dirent_->d_name);
      ACE_OS::free (d->dirent_);
    }
#else /* ACE_WIN32 */
  ACE_UNUSED_ARG (d);
#endif /* ACE_WIN32 */
}
#endif /* ACE_LACKS_CLOSEDIR */

#if defined (ACE_LACKS_OPENDIR)
ACE_DIR *
ACE_OS::opendir_emulation (const ACE_TCHAR *filename)
{
#if defined (ACE_WIN32)
#  if defined (ACE_HAS_WINCE) && !defined (INVALID_FILE_ATTRIBUTES)
#    define INVALID_FILE_ATTRIBUTES 0xFFFFFFFF
#  endif

  ACE_DIR *dir;
  ACE_TCHAR extra[3] = {0,0,0};

   // Check if filename is a directory.
   DWORD fileAttribute = ACE_TEXT_GetFileAttributes (filename);
   if (fileAttribute == INVALID_FILE_ATTRIBUTES
       || !(fileAttribute & FILE_ATTRIBUTE_DIRECTORY))
     return 0;

/*
  Note: the semantics of the win32 function FindFirstFile take the
  basename(filename) as a pattern to be matched within the dirname(filename).
  This is contrary to the behavior of the posix function readdir which treats
  basename(filename) as a directory to be opened and read.

  For this reason, we append a slash-star or backslash-star to the supplied
  filename so the result is that FindFirstFile will do what we need.

  According to the documentation for FindFirstFile, either a '/' or a '\' may
  be used as a directory name separator.

  Of course, it is necessary to ensure that this is only done if the trailing
  filespec is not already there.

  Phil Mesnier
*/

  size_t lastchar = ACE_OS::strlen (filename);
  if (lastchar > 0)
    {
      if (filename[lastchar-1] != '*')
        {
          if (filename[lastchar-1] != '/' && filename[lastchar-1] != '\\')
            ACE_OS::strcpy (extra, ACE_TEXT ("/*"));
          else
            ACE_OS::strcpy (extra, ACE_TEXT ("*"));
        }
    }

  ACE_NEW_RETURN (dir, ACE_DIR, 0);
  ACE_NEW_RETURN (dir->directory_name_,
                  ACE_TCHAR[lastchar + ACE_OS::strlen (extra) + 1],
                  0);
  ACE_OS::strcpy (dir->directory_name_, filename);
  if (extra[0])
    ACE_OS::strcat (dir->directory_name_, extra);
  dir->current_handle_ = INVALID_HANDLE_VALUE;
  dir->started_reading_ = 0;
  dir->dirent_ = 0;
  return dir;
#else /* WIN32 */
  ACE_UNUSED_ARG (filename);
  ACE_NOTSUP_RETURN (0);
#endif /* WIN32 */
}
#endif /* ACE_LACKS_CLOSEDIR */

#if defined (ACE_LACKS_READDIR)
struct ACE_DIRENT *
ACE_OS::readdir_emulation (ACE_DIR *d)
{
#if defined (ACE_WIN32)
  if (d->dirent_ != 0)
    {
      ACE_OS::free (d->dirent_->d_name);
      ACE_OS::free (d->dirent_);
      d->dirent_ = 0;
    }

  if (!d->started_reading_)
    {
      d->current_handle_ = ACE_TEXT_FindFirstFile (d->directory_name_,
                                                   &d->fdata_);
      d->started_reading_ = 1;
    }
  else
    {
      int retval = ACE_TEXT_FindNextFile (d->current_handle_,
                                          &d->fdata_);
      if (retval == 0)
        {
          // Make sure to close the handle explicitly to avoid a leak!
          ::FindClose (d->current_handle_);
          d->current_handle_ = INVALID_HANDLE_VALUE;
        }
    }

  if (d->current_handle_ != INVALID_HANDLE_VALUE)
    {
      d->dirent_ = (ACE_DIRENT *)
        ACE_OS::malloc (sizeof (ACE_DIRENT));

      if (d->dirent_ != 0)
        {
          d->dirent_->d_name = (ACE_TCHAR*)
            ACE_OS::malloc ((ACE_OS::strlen (d->fdata_.cFileName) + 1)
                            * sizeof (ACE_TCHAR));
          ACE_OS::strcpy (d->dirent_->d_name, d->fdata_.cFileName);
          d->dirent_->d_reclen = sizeof (ACE_DIRENT);
        }

      return d->dirent_;
    }
  else
    return 0;
#else /* ACE_WIN32 */
  ACE_UNUSED_ARG (d);
  ACE_NOTSUP_RETURN (0);
#endif /* ACE_WIN32 */
}
#endif /* ACE_LACKS_READDIR */

#if !defined (ACE_HAS_SCANDIR)
int
ACE_OS::scandir_emulation (const ACE_TCHAR *dirname,
                           ACE_DIRENT **namelist[],
                           ACE_SCANDIR_SELECTOR selector,
                           ACE_SCANDIR_COMPARATOR comparator)
{
  ACE_DIR *dirp = ACE_OS::opendir (dirname);

  if (dirp == 0)
    return -1;
  // A sanity check here.  "namelist" had better not be zero.
  else if (namelist == 0)
    return -1;

  ACE_DIRENT **vector = 0;
  ACE_DIRENT *dp = 0;
  int arena_size = 0;

  int nfiles = 0;
  int fail = 0;

  // @@ This code shoulduse readdir_r() rather than readdir().
  for (dp = ACE_OS::readdir (dirp);
       dp != 0;
       dp = ACE_OS::readdir (dirp))
    {
      if (selector && (*selector)(dp) == 0)
        continue;

      // If we get here, we have a dirent that the user likes.
      if (nfiles == arena_size)
        {
          ACE_DIRENT **newv = 0;
          if (arena_size == 0)
            arena_size = 10;
          else
            arena_size *= 2;

          newv = (ACE_DIRENT **) ACE_OS::realloc (vector,
                                              arena_size * sizeof (ACE_DIRENT *));
          if (newv == 0)
            {
              fail = 1;
              break;
            }
          vector = newv;
        }

#if defined (ACE_LACKS_STRUCT_DIR)
      ACE_DIRENT *newdp = (ACE_DIRENT *) ACE_OS::malloc (sizeof (ACE_DIRENT));
#else
      size_t dsize =
        sizeof (ACE_DIRENT) +
        ((ACE_OS::strlen (dp->d_name) + 1) * sizeof (ACE_TCHAR));
      ACE_DIRENT *newdp = (ACE_DIRENT *) ACE_OS::malloc (dsize);
#endif /* ACE_LACKS_STRUCT_DIR */

      if (newdp == 0)
        {
          fail = 1;
          break;
        }

#if defined (ACE_LACKS_STRUCT_DIR)
      newdp->d_name = (ACE_TCHAR*) ACE_OS::malloc (
        (ACE_OS::strlen (dp->d_name) + 1) * sizeof (ACE_TCHAR));

      if (newdp->d_name == 0)
        {
          fail = 1;
          ACE_OS::free (newdp);
          break;
        }

      // Don't use memcpy here since d_name is now a pointer
      newdp->d_ino = dp->d_ino;
      newdp->d_off = dp->d_off;
      newdp->d_reclen = dp->d_reclen;
      ACE_OS::strcpy (newdp->d_name, dp->d_name);
      vector[nfiles++] = newdp;
#else
      vector[nfiles++] = (ACE_DIRENT *) ACE_OS::memcpy (newdp, dp, dsize);
#endif /* ACE_LACKS_STRUCT_DIR */
    }

  if (fail)
    {
      ACE_OS::closedir (dirp);
      while (vector && nfiles-- > 0)
        {
#if defined (ACE_LACKS_STRUCT_DIR)
          ACE_OS::free (vector[nfiles]->d_name);
#endif /* ACE_LACKS_STRUCT_DIR */
          ACE_OS::free (vector[nfiles]);
        }
      ACE_OS::free (vector);
      return -1;
    }

  ACE_OS::closedir (dirp);

  *namelist = vector;

  if (comparator)
    ACE_OS::qsort (*namelist,
                   nfiles,
                   sizeof (ACE_DIRENT *),
                   (ACE_COMPARE_FUNC) comparator);

  return nfiles;
}
#endif /* !ACE_HAS_SCANDIR */

ACE_END_VERSIONED_NAMESPACE_DECL

