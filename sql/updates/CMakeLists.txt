add_subdirectory(2.4.3_old)
add_subdirectory(3.0.9_old)
add_subdirectory(3.1.3_old)
add_subdirectory(3.2.2a_old)
add_subdirectory(3.3.2_old)

FILE(GLOB _SQL_UPDATES *.sql)

INSTALL(FILES
${_SQL_UPDATES}
DESTINATION share/trinity/sql/updates)
