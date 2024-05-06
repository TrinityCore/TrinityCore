
#
# CU_SUBDIRLIST
#
FUNCTION(CU_SUBDIRLIST result curdir recursive includeRoot)
  # glob recurse seem's doesn't work
  FILE(GLOB children RELATIVE ${curdir} "${curdir}/[^\\.]*")
  if (${includeRoot})
    SET(dirlist "${curdir}")
  else()
    SET(dirlist "")
  endif()

  FOREACH(child ${children})
    IF(IS_DIRECTORY "${curdir}/${child}")
        if (${recursive})
          CU_SUBDIRLIST(sub_Dirs "${curdir}/${child}" TRUE FALSE)
          SET(dirlist "${curdir}/${child}" ${sub_Dirs} ${dirlist})
        else()
          SET(dirlist "${curdir}/${child}" ${dirlist})
        endif()
    ENDIF()
  ENDFOREACH()
  SET(${result} ${dirlist} PARENT_SCOPE)
ENDFUNCTION(CU_SUBDIRLIST result curdir recursive)

#
# CU_SET_GLOBAL
#
MACRO(CU_SET_GLOBAL name val)
  set_property ( GLOBAL PROPERTY ${name} ${val})
  # after set , create the variable for current scope
  CU_GET_GLOBAL(${name})
ENDMACRO()

MACRO(CU_ADD_GLOBAL name val)
  CU_GET_GLOBAL(${name})

  set_property ( GLOBAL PROPERTY ${name}
      ${${name}}
      ${val}
  )
  # after set , create the variable for current scope
  CU_GET_GLOBAL(${name})
ENDMACRO()

#
# CU_GET_GLOBAL
#
MACRO(CU_GET_GLOBAL name)
  get_property(${name} GLOBAL PROPERTY ${name})
ENDMACRO()

#
# CU_SET_CACHE
#
MACRO(CU_SET_CACHE name val)
  set(${name} ${val} CACHE INTERNAL "CU Var")
ENDMACRO()

#
# CU_LIST_ADD_CACHE
#
MACRO(CU_LIST_ADD_CACHE name val)

    # avoid duplicates
    if (";${${name}};" MATCHES ";${val};")
      # nothing to do for now
    else()
        set(${name} ${val} ${${name}} CACHE INTERNAL "CU Var")
    endif()
ENDMACRO()


#
# CU_SET_PATH
#
MACRO(CU_SET_PATH name val)
  CU_SET_CACHE(${name} ${val})

  CU_ADD_INC_PATH(${val})
ENDMACRO()

#
# CU_ADD_INC_PATH
#
MACRO(CU_ADD_INC_PATH val)

    if (";${CU_INC_PATHS};" MATCHES ";${val};")
      # nothing to do for now
    else()
        set(CU_INC_PATHS
            ${CU_INC_PATHS}
            ${val}
        )

        #update cache
        CU_SET_CACHE("CU_INC_PATHS" "${CU_INC_PATHS}")
        include_directories(${val})
    endif()
ENDMACRO()


#
# CU_LOAD_INC_PATHS
#
MACRO(CU_LOAD_INC_PATHS)
  include_directories(${CU_INC_PATHS})
ENDMACRO()

#
# CU_SET_PARENT
#
MACRO(CU_SET_PARENT name val)
  set(${name} ${val} PARENT_SCOPE)
ENDMACRO()


MACRO(CU_ADD_HOOK hook_name value)
  CU_ADD_GLOBAL(${hook_name} "${value}")
ENDMACRO()

MACRO(CU_RUN_HOOK hook_name)
  CU_GET_GLOBAL(${hook_name})
  message(STATUS "Running cmake hook: ${hook_name}")
  if (${hook_name})
      set(HOOK_ARRAY ${${hook_name}})
      FOREACH (hook_file ${HOOK_ARRAY})
          message("Including ${hook_file}")
          include("${hook_file}")
      ENDFOREACH()
  else()
      message(STATUS "No hooks registered for ${hook_name}")
  endif()
ENDMACRO()


