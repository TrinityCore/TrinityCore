########### install files ###############

FILE(GLOB _SQL *.sql)
FILE(GLOB README readme.txt)

install(FILES ${_SQL} DESTINATION share/trinity/sql/FULL)
install(FILES ${README} DESTINATION share/trinity/sql/FULL)