add_subdirectory(updates)
add_subdirectory(full)

########### install files ###############

FILE(GLOB _SQL *.sql)

install(FILES ${_SQL} DESTINATION share/trinity/sql)
