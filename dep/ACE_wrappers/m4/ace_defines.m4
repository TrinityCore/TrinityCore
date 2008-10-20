# ACE_CHECK_DEFINE(DEFINE, [ACTION-IF-FOUND], [ACTION-IF-NOT-FOUND],
#		   [INCLUDES = 'default-includes'])
#-----------------------------------------------------------------------------
AC_DEFUN([ACE_CHECK_DEFINE],[
AS_VAR_PUSHDEF([ac_var],[ace_cv_defined_$1])dnl
AC_CACHE_CHECK([for $1], ac_var,
AC_COMPILE_IFELSE([AC_LANG_SOURCE([AC_INCLUDES_DEFAULT([$4])
#ifdef $1
int ok;
#else
choke me
#endif
])],AS_VAR_SET(ac_var, yes),AS_VAR_SET(ac_var, no)))
AS_IF([test AS_VAR_GET(ac_var) != "no"], [$2], [$3])dnl
AS_VAR_POPDEF([ac_var])dnl
])

# ACE_CHECK_HAS_DEFINES(DEFINE..., [ACTION-IF-FOUND], [ACTION-IF-NOT-FOUND],
#                       [INCLUDES = 'default-includes'])
#-----------------------------------------------------------------------------
AC_DEFUN([ACE_CHECK_HAS_DEFINES],
[AC_FOREACH([ACE_Def], [$1],
  [AH_TEMPLATE(AS_TR_CPP(ACE_HAS_[]ACE_Def),
               [Define to 1 if platform has ]ACE_Def[().])])dnl
for ace_def in $1
do
ACE_CHECK_DEFINE($ace_def,
                 [AC_DEFINE_UNQUOTED([AS_TR_CPP([ACE_HAS_$ace_def])]) $2],
                 [$3],
                 [$4])dnl
done
])

# ACE_CHECK_LACKS_DEFINES(DEFINE..., [ACTION-IF-FOUND], [ACTION-IF-NOT-FOUND])
#                         [INCLUDES = 'default-includes'])
#-----------------------------------------------------------------------------
AC_DEFUN([ACE_CHECK_LACKS_DEFINES],
[AC_FOREACH([ACE_Def], [$1],
  [AH_TEMPLATE(AS_TR_CPP(ACE_LACKS_[]ACE_Def),
               [Define to 1 if platform lacks ]ACE_Def[().])])dnl
for ace_def in $1
do
ACE_CHECK_DEFINE($ace_def,
                 [$2],
                 [AC_DEFINE_UNQUOTED([AS_TR_CPP([ACE_LACKS_$ace_def])]) $3],
                 [$4])dnl
done
])
