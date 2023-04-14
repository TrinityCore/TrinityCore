
AC_ADD_SCRIPT("${CMAKE_CURRENT_LIST_DIR}/src/mod-double-xp-weekend.cpp")

AC_ADD_SCRIPT_LOADER("doublexp" "${CMAKE_CURRENT_LIST_DIR}/src/loader.h")


CU_ADD_HOOK(AFTER_WORLDSERVER_CMAKE "${CMAKE_CURRENT_LIST_DIR}/src/cmake/after_ws_install.cmake")
