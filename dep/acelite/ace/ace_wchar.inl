// -*- C++ -*-
//
// $Id: ace_wchar.inl 80826 2008-03-04 14:51:23Z wotte $

// These are always inlined
// FUZZ: disable check_for_inline

#if defined (ACE_HAS_WCHAR)

#if !defined (ACE_WIN32)
#  include /**/ <string.h>             // Need to see strlen()
#endif /* ACE_WIN32 */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

inline
ACE_Wide_To_Ascii::~ACE_Wide_To_Ascii (void)
{
  delete [] this->s_;
}

inline char *
ACE_Wide_To_Ascii::char_rep (void)
{
  return this->s_;
}

inline char *
ACE_Wide_To_Ascii::convert (const wchar_t *wstr)
{
  // Short circuit null pointer case
  if (wstr == 0)
    return 0;

# if defined (ACE_WIN32)
  UINT const cp = GetACP ();  // Codepage
  int const len = ::WideCharToMultiByte (cp,
                                         0,
                                         wstr,
                                         -1,
                                         0,
                                         0,
                                         0,
                                         0);
# elif defined (ACE_LACKS_WCSLEN)
  const wchar_t * wtemp = wstr;
  while ((*wtemp) != 0) // Hopefully the string is null terminated!
    ++wtemp;

  int const len = wtemp - wstr + 1;
# else  /* ACE_WIN32 */
  size_t const len = ::wcslen (wstr) + 1;
# endif /* ACE_WIN32 */

#if !defined (ACE_HAS_ICONV)
  char *str = new char[len];
#endif

# if defined (ACE_WIN32)
  ::WideCharToMultiByte (cp, 0, wstr, -1, str, len, 0, 0);
# elif defined (ACE_VXWORKS)
  ::wcstombs (str, wstr, len);
# elif defined (ACE_HAS_ICONV)
  wchar_t * wstri = const_cast<wchar_t*> (wstr);
  size_t lensi = ACE_MAX_ICONV_BUFFER;
  size_t lenwi = len * sizeof(wchar_t);
  char buf[ACE_MAX_ICONV_BUFFER];
  char *stri = buf;

  size_t hr = iconv (ACE_Wide_To_Ascii_iconv_env, (char**)&wstri, &lenwi, &stri, &lensi);
  if ((hr==size_t(-1))||(lensi==ACE_MAX_ICONV_BUFFER))
    {
      char *str=new char[len];
      for (size_t i = 0; i < len; i++)
        {
          wchar_t *t = const_cast <wchar_t *> (wstr);
          str[i] = static_cast<char> (*(t + i));
        }

      return str;
    }
  char *str = new char[ACE_MAX_ICONV_BUFFER-lensi];
  ::memcpy(str, buf, ACE_MAX_ICONV_BUFFER-lensi);
# else /* ACE_HAS_ICONV */
  for (size_t i = 0; i < len; ++i)
    {
      wchar_t *t = const_cast <wchar_t *> (wstr);
      str[i] = static_cast<char> (*(t + i));
    }
# endif /* ACE_WIN32 */
  return str;
}

inline
ACE_Wide_To_Ascii::ACE_Wide_To_Ascii (const wchar_t *s)
{
#if defined(ACE_HAS_ICONV)
  if (ACE_Wide_To_Ascii_iconv_env == 0)
    {
      ACE_Wide_To_Ascii_iconv_env = iconv_open("", "WCHAR_T");
    }
#endif
  s_ = ACE_Wide_To_Ascii::convert (s);
}

inline
ACE_Ascii_To_Wide::~ACE_Ascii_To_Wide (void)
{
  delete [] this->s_;
}

inline wchar_t *
ACE_Ascii_To_Wide::wchar_rep (void)
{
  return this->s_;
}

inline wchar_t *
ACE_Ascii_To_Wide::convert (const char *str)
{
  // Short circuit null pointer case
  if (str == 0)
    return 0;

# if defined (ACE_WIN32)
  UINT const cp = GetACP ();  // Codepage
  int const len = ::MultiByteToWideChar (cp, 0, str, -1, 0, 0);
# else /* ACE_WIN32 */
  size_t const len = strlen (str) + 1;
# endif /* ACE_WIN32 */

#if !defined (ACE_HAS_ICONV)
  wchar_t *wstr = new wchar_t[len];
#endif

# if defined (ACE_WIN32)
  ::MultiByteToWideChar (cp, 0, str, -1, wstr, len);
# elif defined (ACE_VXWORKS)
  ::mbstowcs (wstr, str, len);
# elif defined (ACE_HAS_ICONV) /* ACE_VXWORKS */
  char *stri = const_cast<char*>(str);
  size_t lensi = len;
  size_t lenwi = ACE_MAX_ICONV_BUFFER;
  wchar_t buf[ACE_MAX_ICONV_BUFFER/sizeof(wchar_t)];
  wchar_t *wstri=buf;

  size_t hr=iconv(ACE_Ascii_To_Wide_iconv_env, &stri, &lensi, (char**)&wstri, &lenwi);
  if((hr==size_t(-1))||(lenwi==ACE_MAX_ICONV_BUFFER)){
  wchar_t *wstr=new wchar_t[len*sizeof(wchar_t)];
  for (size_t i = 0; i < len; i++){
    char *t = const_cast<char *> (str);
    wstr[i] = static_cast<wchar_t> (*((unsigned char*)t + i));
  }

  return wstr;
  }
  wchar_t *wstr=new wchar_t[(ACE_MAX_ICONV_BUFFER-lenwi)/sizeof(wchar_t)];
  ::memcpy(wstr,buf,ACE_MAX_ICONV_BUFFER-lenwi);
# else /* ACE_HAS_ICONV */
  for (size_t i = 0; i < len; ++i)
    {
      char *t = const_cast<char *> (str);
      wstr[i] = static_cast<wchar_t> (*((unsigned char*)(t + i)));
    }
# endif /* ACE_WIN32 */
  return wstr;
}

inline
ACE_Ascii_To_Wide::ACE_Ascii_To_Wide (const char *s)
{
#if defined(ACE_HAS_ICONV)
  if (ACE_Ascii_To_Wide_iconv_env == 0)
    {
      ACE_Ascii_To_Wide_iconv_env = iconv_open("WCHAR_T", "");
    }
#endif
  s_ = ACE_Ascii_To_Wide::convert (s);
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_WCHAR */
