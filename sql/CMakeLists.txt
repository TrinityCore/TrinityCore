add_subdirectory(updates)
add_subdirectory(tools)


########### install files ###############

install(FILES  world.sql      realmd.sql      characters.sql      create_mysql.sql      world_scripts_full.sql      world_scripts_structure.sql      drop_mysql.sql DESTINATION share/trinity/sql)
