add_subdirectory(2.4.3_updates)

FILE(GLOB _SQL_UPDATES *.sql)

INSTALL(FILES
${_SQL_UPDATES}
DESTINATION share/trinity/sql/updates)
