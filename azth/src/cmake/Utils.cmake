
#
# AZTH_SUBDIRLIST
#
FUNCTION(AZTH_SUBDIRLIST result curdir recursive)
  # glob recurse seem's doesn't work
  FILE(GLOB children RELATIVE ${curdir} "${curdir}/[^\\.]*")
  SET(dirlist "")
  FOREACH(child ${children})
    IF(IS_DIRECTORY "${curdir}/${child}")
        if (recursive)
          AZTH_SUBDIRLIST(sub_Dirs "${curdir}/${child}" TRUE)
          SET(dirlist "${curdir}/${child}" ${sub_Dirs} ${dirlist})
        else()
          SET(dirlist "${curdir}/${child}" ${dirlist}) 
        endif()
    ENDIF()
  ENDFOREACH()
  SET(${result} ${dirlist} PARENT_SCOPE)
ENDFUNCTION(AZTH_SUBDIRLIST curdir recursive)

#
# AZTH_SET_GLOBAL
#
MACRO(AZTH_SET_GLOBAL name val)
  set_property ( GLOBAL PROPERTY ${name} ${val})
  # after set , create the variable for current scope
  AZTH_GET_GLOBAL(${name})
ENDMACRO()

#
# AZTH_GET_GLOBAL
#
MACRO(AZTH_GET_GLOBAL name)
  get_property(${name} GLOBAL PROPERTY ${name})
ENDMACRO()

#
# AZTH_SET_CACHE
#
MACRO(AZTH_SET_CACHE name val)
  set(${name} ${val} CACHE INTERNAL "AZTH Var")
ENDMACRO()


#
# AZTH_SET_PATH
#
MACRO(AZTH_SET_PATH name val)
  AZTH_SET_CACHE(${name} ${val})

  AZTH_ADD_INC_PATH(${val})
ENDMACRO()

#
# AZTH_ADD_INC_PATH
#
MACRO(AZTH_ADD_INC_PATH val)
    set(AZTH_INC_PATHS
        ${AZTH_INC_PATHS}
        ${val}
    )
    #update cache
    AZTH_SET_CACHE("AZTH_INC_PATHS" ${AZTH_INC_PATHS})
    include_directories(${val})
ENDMACRO()


#
# AZTH_LOAD_INC_PATHS
#
MACRO(AZTH_LOAD_INC_PATHS)
  include_directories(${AZTH_INC_PATHS})
ENDMACRO()

#
# AZTH_SET_PARENT
#
MACRO(AZTH_SET_PARENT name val)
  set(${name} ${val} PARENT_SCOPE)
ENDMACRO()

#
# AZTH_ADD_CORE_TG
#
MACRO(AZTH_ADD_CORE_TG val)
    AZTH_GET_GLOBAL("AZTH_CORE_TGS")

    set(AZTH_CORE_TGS
        ${AZTH_CORE_TGS}
        ${val}
    )
    #update cache
    AZTH_SET_GLOBAL("AZTH_CORE_TGS" "${AZTH_CORE_TGS}")
ENDMACRO()

