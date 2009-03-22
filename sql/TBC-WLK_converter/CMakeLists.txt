########### install files ###############

FILE(GLOB _SQL_TBC_WLK *.sql)

install(FILES ${_SQL_TBC_WLK} Readme.txt DESTINATION share/trinity/sql/TBC-WLK_converter)
