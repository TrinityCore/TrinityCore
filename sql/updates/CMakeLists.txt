add_subdirectory(2.4.3_updates)
add_subdirectory(Obsolete_updates)
add_subdirectory(3.0.9_old)

FILE(GLOB _SQL_UPDATES *.sql)

INSTALL(FILES
${_SQL_UPDATES}
DESTINATION share/trinity/sql/updates)