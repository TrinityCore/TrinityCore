# ACE_CHECK_HAS_HEADERS(HEADER-FILE...,
#		        [ACTION-IF-FOUND],
#                       [ACTION-IF-NOT-FOUND],
#			[INCLUDES = 'default-includes'])
#-----------------------------------------------------------------------------
AC_DEFUN([ACE_CHECK_HAS_HEADERS],
[AC_FOREACH([ACE_Header], [$1],
  [AH_TEMPLATE(AS_TR_CPP([ACE_HAS_]ACE_Header),
               [Define to 1 if platform has the <]ACE_Header[> header file.])])dnl
for ace_header in $1
do
AC_CHECK_HEADER($ace_header,
                [AC_DEFINE_UNQUOTED(AS_TR_CPP([ACE_HAS_$ace_header])) $2],
                [$3],
	        [$4])dnl
done
])

# ACE_CHECK_LACKS_HEADERS(HEADER-FILE...,
#		          [ACTION-IF-FOUND],
#                         [ACTION-IF-NOT-FOUND],
#			  [INCLUDES = 'default-includes'])
#-----------------------------------------------------------------------------
AC_DEFUN([ACE_CHECK_LACKS_HEADERS],
[AC_FOREACH([ACE_Header], [$1],
  [AH_TEMPLATE(AS_TR_CPP([ACE_LACKS_]ACE_Header),
               [Define to 1 if platform lacks the <]ACE_Header[> header file.])])dnl
for ace_header in $1
do
AC_CHECK_HEADER($ace_header,
                [$2],
                [AC_DEFINE_UNQUOTED(AS_TR_CPP([ACE_LACKS_$ace_header])) $3],
                [$4])dnl
done
])
