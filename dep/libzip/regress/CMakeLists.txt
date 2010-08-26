# $NiH$

ENABLE_TESTING()

SET(TEST_PROGRAMS
  add_from_buffer
  add_from_file
  add_from_filep
  encrypt
  fread
  get_comment
  name_locate
  open
  set_comment_all
  set_comment_localonly
  set_comment_removeglobal
  set_comment_revert
)

SET(ENV{srcdir} ${CMAKE_CURRENT_SOURCE_DIR})
FOREACH(PROGRAM ${TEST_PROGRAMS})
  ADD_EXECUTABLE(${PROGRAM} ${PROGRAM}.c)
  TARGET_LINK_LIBRARIES(${PROGRAM} zip)
  ADD_TEST(${PROGRAM} ${CMAKE_CURRENT_SOURCE_DIR}/runtest ${CMAKE_CURRENT_SOURCE_DIR}/${PROGRAM})
ENDFOREACH(PROGRAM ${TEST_PROGRAMS})

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/../lib)
