add_subdirectory(TBC-WLK_converter)
add_subdirectory(updates)
add_subdirectory(tools)

########### install files ###############

FILE(GLOB _SQL *.sql)

install(FILES ${_SQL} DESTINATION share/trinity/sql)
