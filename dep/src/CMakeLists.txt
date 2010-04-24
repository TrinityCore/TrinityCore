add_subdirectory(g3dlite)
if (NOT MACOSX)
add_subdirectory(jmalloc)
endif(NOT MACOSX)
add_subdirectory(sockets)
add_subdirectory(zlib)


########### install files ###############