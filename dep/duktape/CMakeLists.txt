set(DUKTAPEDIR ${CMAKE_CURRENT_LIST_DIR})

include_directories(
  ${DUKTAPEDIR}/duktape
  ${DUKTAPEDIR}/dukglue
)

add_library(duktape STATIC ${DUKTAPEDIR}/duktape/duktape.c)

if("${CMAKE_SYSTEM_NAME}" MATCHES "Linux")
  target_link_libraries(duktape
    m dl rt
  )
endif()

add_library(dukglue INTERFACE)

set(DUKGLUE_HEADERS
  ${DUKTAPEDIR}/duktape/duktape.h
  ${DUKTAPEDIR}/duktape/duk_config.h

  ${DUKTAPEDIR}/dukglue/dukglue.h
  ${DUKTAPEDIR}/dukglue/detail_class_proto.h
  ${DUKTAPEDIR}/dukglue/detail_constructor.h
  ${DUKTAPEDIR}/dukglue/detail_function.h
  ${DUKTAPEDIR}/dukglue/detail_method.h
  ${DUKTAPEDIR}/dukglue/detail_primitive_types.h
  ${DUKTAPEDIR}/dukglue/detail_refs.h
  ${DUKTAPEDIR}/dukglue/detail_stack.h
  ${DUKTAPEDIR}/dukglue/detail_traits.h
  ${DUKTAPEDIR}/dukglue/detail_typeinfo.h
  ${DUKTAPEDIR}/dukglue/detail_types.h
  ${DUKTAPEDIR}/dukglue/dukvalue.h
  ${DUKTAPEDIR}/dukglue/dukexception.h
  ${DUKTAPEDIR}/dukglue/register_class.h
  ${DUKTAPEDIR}/dukglue/register_function.h
  ${DUKTAPEDIR}/dukglue/register_property.h
  ${DUKTAPEDIR}/dukglue/public_util.h
  CACHE INTERNAL ""
)

target_include_directories(dukglue INTERFACE ${DUKTAPEDIR})
