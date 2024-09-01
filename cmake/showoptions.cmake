# output generic information about the core and buildtype chosen
message("")
message("* TrinityCore revision   : ${rev_hash} ${rev_date} (${rev_branch} branch)")
get_property(IS_MULTI_CONFIG GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)
if(NOT IS_MULTI_CONFIG)
  message("* TrinityCore buildtype  : ${CMAKE_BUILD_TYPE}")
endif()
message("")

# output information about installation-directories and locations

message("* Install core to        : ${CMAKE_INSTALL_PREFIX}")
if(COPY_CONF)
  if(UNIX)
    message("* Install configs to     : ${CONF_DIR}")
  else()
    message("* Install configs to     : ${CMAKE_INSTALL_PREFIX}")
  endif()
endif()

message("")

# Show infomation about the options selected during configuration

if(SERVERS)
  message("* Build world/auth       : Yes (default)")
else()
  message("* Build world/bnetserver : No")
endif()

if(SCRIPTS AND (NOT SCRIPTS STREQUAL "none"))
  message("* Build with scripts     : Yes (${SCRIPTS})")
else()
  message("* Build with scripts     : No")
endif()

if(TOOLS)
  message("* Build map/vmap tools   : Yes (default)")
else()
  message("* Build map/vmap tools   : No")
endif()

if(BUILD_TESTING)
  message("* Build unit tests       : Yes")
else()
  message("* Build unit tests       : No (default)")
endif()

if(USE_COREPCH)
  message("* Build core w/PCH       : Yes (default)")
else()
  message("* Build core w/PCH       : No")
endif()

if(USE_SCRIPTPCH)
  message("* Build scripts w/PCH    : Yes (default)")
else()
  message("* Build scripts w/PCH    : No")
endif()

if(WITH_WARNINGS)
  message("* Show all warnings      : Yes")
else()
  message("* Show compile-warnings  : No  (default)")
endif()

if(WITH_COREDEBUG)
  message("")
  message(" *** WITH_COREDEBUG - WARNING!")
  message(" *** additional core debug logs have been enabled!")
  message(" *** this setting doesn't help to get better crash logs!")
  message(" *** in case you are searching for better crash logs use")
  message(" *** -DCMAKE_BUILD_TYPE=RelWithDebInfo")
  message(" *** DO NOT ENABLE IT UNLESS YOU KNOW WHAT YOU'RE DOING!")
  message("* Use coreside debug     : Yes")
  target_compile_definitions(trinity-compile-option-interface
    INTERFACE
      TRINITY_DEBUG)
else()
  message("* Use coreside debug     : No  (default)")
endif()

if(NOT WITH_SOURCE_TREE STREQUAL "no")
  message("* Show source tree       : Yes (${WITH_SOURCE_TREE})")
else()
  message("* Show source tree       : No")
endif()

if(WITHOUT_GIT)
  message("* Use GIT revision hash  : No")
  message("")
  message(" *** WITHOUT_GIT - WARNING!")
  message(" *** By choosing the WITHOUT_GIT option you have waived all rights for support,")
  message(" *** and accept that or all requests for support or assistance sent to the core")
  message(" *** developers will be rejected. This due to that we will be unable to detect")
  message(" *** what revision of the codebase you are using in a proper way.")
  message(" *** We remind you that you need to use the repository codebase and a supported")
  message(" *** version of git for the revision-hash to work, and be allowede to ask for")
  message(" *** support if needed.")
else()
  message("* Use GIT revision hash  : Yes (default)")
endif()

if(NOJEM)
  message("")
  message(" *** NOJEM - WARNING!")
  message(" *** jemalloc linking has been disabled!")
  message(" *** Please note that this is for DEBUGGING WITH VALGRIND only!")
  message(" *** DO NOT DISABLE IT UNLESS YOU KNOW WHAT YOU'RE DOING!")
endif()

if(HELGRIND)
  message("")
  message(" *** HELGRIND - WARNING!")
  message(" *** Please specify the valgrind include directory in VALGRIND_INCLUDE_DIR option if you get build errors")
  message(" *** Please note that this is for DEBUGGING WITH HELGRIND only!")
  target_compile_definitions(trinity-compile-option-interface
    INTERFACE
      HELGRIND)
endif()

if(ASAN)
  message("")
  message(" *** ASAN - WARNING!")
  message(" *** Please note that this is for DEBUGGING WITH ADDRESS SANITIZER only!")
  target_compile_definitions(trinity-compile-option-interface
    INTERFACE
      ASAN)
endif()

if(MSAN)
  message("")
  message(" *** MSAN - WARNING!")
  message(" *** Please note that this is for DEBUGGING WITH MEMORY SANITIZER only!")
  target_compile_definitions(trinity-compile-option-interface
    INTERFACE
      MSAN)
endif()

if(UBSAN)
  message("")
  message(" *** UBSAN - WARNING!")
  message(" *** Please note that this is for DEBUGGING WITH UNDEFINED BEHAVIOR SANITIZER only!")
  target_compile_definitions(trinity-compile-option-interface
    INTERFACE
      UBSAN)
endif()

if(TSAN)
  message("")
  message(" *** TSAN - WARNING!")
  message(" *** Please note that this is for DEBUGGING WITH THREAD SANITIZER only!")
  target_compile_definitions(trinity-compile-option-interface
    INTERFACE
      TSAN)
endif()

if(PERFORMANCE_PROFILING)
  message("")
  message(" *** PERFORMANCE_PROFILING - WARNING!")
  message(" *** Please note that this is for PERFORMANCE PROFILING only! Do NOT report any issue when enabling this configuration!")
  target_compile_definitions(trinity-compile-option-interface
    INTERFACE
      PERFORMANCE_PROFILING)
endif()

if(WITHOUT_METRICS)
  message("")
  message(" *** WITHOUT_METRICS - WARNING!")
  message(" *** Please note that this will disable all metrics output (i.e. InfluxDB and Grafana)")
  target_compile_definitions(trinity-compile-option-interface
    INTERFACE
      WITHOUT_METRICS)
elseif (WITH_DETAILED_METRICS)
  message("")
  message(" *** WITH_DETAILED_METRICS - WARNING!")
  message(" *** Please note that this will enable detailed metrics output (i.e. time each session takes to update)")
  target_compile_definitions(trinity-compile-option-interface
    INTERFACE
      WITH_DETAILED_METRICS)
endif()

if(BUILD_SHARED_LIBS)
  message("")
  message(" *** WITH_DYNAMIC_LINKING - INFO!")
  message(" *** Will link against shared libraries!")
  message(" *** Please note that this is an experimental feature!")
  if(WITH_DYNAMIC_LINKING_FORCED)
    message("")
    message(" *** Dynamic linking was enforced through a dynamic script module!")
  endif()
  target_compile_definitions(trinity-compile-option-interface
    INTERFACE
      TRINITY_API_USE_DYNAMIC_LINKING)

  WarnAboutSpacesInBuildPath()
endif()

message("")
