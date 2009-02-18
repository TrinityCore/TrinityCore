-- event script for Medivh's Journal
delete from event_scripts where id = 10951;
insert into event_scripts values
(10951,0,10,17651, 300000, 0,-11159,-1907.22,91.48,0);

-- remove every Image from Medivh (should not be spawned by db)
delete from creature where id = 17651;
-- add script
update creature_template set scriptname = 'npc_image_of_medivh' where entry = 17651;

