# ACE_FUNC_STRCASECMP
# + Defines ACE_LACKS_STRCASECMP to 1 if platform lacks strcasecmp()
# + Defines ACE_STRCASECMP_EQUIVALENT to identifier name if platform
#   has a equivalent function that differs in name only.
# + Defines ACE_LACKS_STRCASECMP_PROTOTYPE to 1 if platform lacks
#   declaration for strcasecmp().
#---------------------------------------------------------------------------
AC_DEFUN([ACE_FUNC_STRCASECMP],
[ACE_CHECK_LACKS_FUNCS(strcasecmp)
if test "$ac_cv_func_strcasecmp" = yes; then
    AC_CHECK_DECL([strcasecmp],
		  [],
		  [AC_DEFINE([ACE_LACKS_STRCASECMP_PROTOTYPE], 1,
			     [Define to 1 if platform lacks a declaration for strcasecmp()])],
		  [
#if !defined(ACE_LACKS_STRINGS_H)
#include <strings.h>
#endif
#if !defined(ACE_LACKS_STRING_H)
#include <string.h>
#endif
		  ])
else
    AC_CHECK_FUNC(stricmp)
    if test "$ac_cv_func_stricmp" = yes; then
        AC_DEFINE(ACE_STRCASECMP_EQUIVALENT, [::stricmp],
		  [Define to function that is equivalent to strcasecmp()])
    else
	AC_CHECK_FUNC(_stricmp)
	if test "$ac_cv_func__stricmp" = yes; then
	    AC_DEFINE(ACE_STRCASECMP_EQUIVALENT, [::_stricmp])
	fi
    fi
fi
])

# ACE_FUNC_STRNCASECMP
# + Defines ACE_LACKS_STRCASECMP to 1 if platform lacks strcasecmp()
# + Defines ACE_STRCASECMP_EQUIVALENT to identifier name if platform
#   has a equivalent function that differs in name only.
# + Defines ACE_LACKS_STRNCASECMP_PROTOTYPE to 1 if platform lacks
#   declaration for strncasecmp().
#---------------------------------------------------------------------------
AC_DEFUN([ACE_FUNC_STRNCASECMP],
[ACE_CHECK_LACKS_FUNCS(strncasecmp)
if test "$ac_cv_func_strncasecmp" = yes; then
    AC_CHECK_DECL([strncasecmp],
		  [],
		  [AC_DEFINE([ACE_LACKS_STRNCASECMP_PROTOTYPE], 1,
			     [Define to 1 if platform lacks a declaration for strncasecmp()])],
		  [
#if !defined(ACE_LACKS_STRINGS_H)
#include <strings.h>
#endif
#if !defined(ACE_LACKS_STRING_H)
#include <string.h>
#endif
		  ])
else
    AC_CHECK_FUNC(strnicmp)
    if test "$ac_cv_func_strnicmp" = yes; then
        AC_DEFINE(ACE_STRNCASECMP_EQUIVALENT, [::strnicmp],
		  [Define to function that is equivalent to strncasecmp()])
    else
	AC_CHECK_FUNC(_strnicmp)
	if test "$ac_cv_func__strnicmp" = yes; then
	    AC_DEFINE(ACE_STRNCASECMP_EQUIVALENT, [::_strnicmp])
	fi
    fi
fi
])

# ACE_FUNC_STRDUP
# + Defines ACE_LACKS_STRDUP to 1 if platform lacks strdup()
# + Defines ACE_STRDUP_EQUIVALENT to identifier name if platform
#   has a equivalent function that differs in name only.
# + Defines ACE_HAS_NONCONST_STRDUP if argument is char*. (TODO)
#---------------------------------------------------------------------------
AC_DEFUN([ACE_FUNC_STRDUP],
[ACE_CHECK_LACKS_FUNCS(strdup)
if test "$ac_cv_func_strdup" = no; then
    AC_CHECK_FUNC(_strdup)
    if test "$ac_cv_func__strdup" = yes; then
        AC_DEFINE(ACE_STRDUP_EQUIVALENT, [::_strdup],
		  [Define to function that is equivalent to strdup()])
    fi
fi
])


# ACE_FUNC_WCSCASECMP
# + Defines ACE_LACKS_WCSCASECMP to 1 if platform lacks strcasecmp()
# + Defines ACE_WCSCASECMP_EQUIVALENT to identifier name if platform
#   has a equivalent function that differs in name only.
#---------------------------------------------------------------------------
AC_DEFUN([ACE_FUNC_WCSCASECMP],
[ACE_CHECK_LACKS_FUNCS(wcscasecmp)
if test "$ac_cv_func_wcscasecmp" = no; then
    AC_CHECK_FUNC(wcsicmp)
    if test "$ac_cv_func_wcsicmp" = yes; then
        AC_DEFINE(ACE_WCSCASECMP_EQUIVALENT, [::wcsicmp],
		  [Define to function that is equivalent to wcscasecmp()])
    else
	AC_CHECK_FUNC(_wcsicmp)
	if test "$ac_cv_func__wcsicmp" = yes; then
	    AC_DEFINE(ACE_WCSCASECMP_EQUIVALENT, [::_wcsicmp])
	fi
    fi
fi
])

# ACE_FUNC_WCSNCASECMP
# + Defines ACE_LACKS_WCSNCASECMP to 1 if platform lacks strcasecmp()
# + Defines ACE_WCSNCASECMP_EQUIVALENT to identifier name if platform
#   has a equivalent function that differs in name only.
#---------------------------------------------------------------------------
AC_DEFUN([ACE_FUNC_WCSNCASECMP],
[ACE_CHECK_LACKS_FUNCS(wcsncasecmp)
if test "$ac_cv_func_wcsncasecmp" = no; then
    AC_CHECK_FUNC(wcsnicmp)
    if test "$ac_cv_func_wcsnicmp" = yes; then
        AC_DEFINE(ACE_WCSNCASECMP_EQUIVALENT, [::wcsnicmp],
		  [Define to function that is equivalent to wcsncasecmp()])
    else
	AC_CHECK_FUNC(_wcsnicmp)
	if test "$ac_cv_func__wcsnicmp" = yes; then
	    AC_DEFINE(ACE_WCSNCASECMP_EQUIVALENT, [::_wcsnicmp])
	fi
    fi
fi
])

# ACE_FUNC_WCSDUP
# + Defines ACE_LACKS_WCSDUP to 1 if platform lacks wcsdup()
# + Defines ACE_WCSDUP_EQUIVALENT to identifier name if platform
#   has a equivalent function that differs in name only.
# + Defines ACE_HAS_NONCONST_WCSDUP if argument is char*. (TODO)
#---------------------------------------------------------------------------
AC_DEFUN([ACE_FUNC_WCSDUP],
[ACE_CHECK_LACKS_FUNCS(wcsdup)
if test "$ac_cv_func_wcsdup" = no; then
    AC_CHECK_FUNC(_wcsdup)
    if test "$ac_cv_func__wcsdup" = yes; then
        AC_DEFINE(ACE_WCSDUP_EQUIVALENT, [::_wcsdup],
		  [Define to function that is equivalent to wcsdup()])
    fi
fi
])
