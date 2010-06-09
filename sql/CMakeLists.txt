add_subdirectory(updates)
add_subdirectory(scripts)
add_subdirectory(base)

########### install files ###############

FILE(GLOB _SQL *.sql)

install(FILES ${_SQL} DESTINATION share/trinity/sql)
