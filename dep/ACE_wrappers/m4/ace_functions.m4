# ACE_CHECK_HAS_FUNCS(FUNCTION..., [ACTION-IF-FOUND], [ACTION-IF-NOT-FOUND])
#---------------------------------------------------------------------------
AC_DEFUN([ACE_CHECK_HAS_FUNCS],
[AC_FOREACH([ACE_Func], [$1],
  [AH_TEMPLATE(AS_TR_CPP(ACE_HAS_[]ACE_Func),
               [Define to 1 if platform has ]ACE_Func[().])])dnl
for ace_func in $1
do
AC_CHECK_FUNC($ace_func,
              [AC_DEFINE_UNQUOTED([AS_TR_CPP([ACE_HAS_$ace_func])]) $2],
              [$3])dnl
done
])

# ACE_CHECK_LACKS_FUNCS(FUNCTION..., [ACTION-IF-FOUND], [ACTION-IF-NOT-FOUND])
#-----------------------------------------------------------------------------
AC_DEFUN([ACE_CHECK_LACKS_FUNCS],
[AC_FOREACH([ACE_Func], [$1],
  [AH_TEMPLATE(AS_TR_CPP(ACE_LACKS_[]ACE_Func),
               [Define to 1 if platform lacks ]ACE_Func[().])])dnl
for ace_func in $1
do
AC_CHECK_FUNC($ace_func,
              [$2],
              [AC_DEFINE_UNQUOTED([AS_TR_CPP([ACE_LACKS_$ace_func])]) $3])dnl
done
])
