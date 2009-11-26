FILE(GLOB _SQL_OU *.sql)

INSTALL(FILES
${_SQL_OU}
DESTINATION share/trinity/sql/updates/Obsolete_updates)