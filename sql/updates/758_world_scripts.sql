delete from creature_template_addon where entry = 17225;
update creature_template set scriptname = 'boss_nightbane', unit_flags=0 where entry = 17225;
delete from event_scripts where id = 10951;
insert into event_scripts values
(10951,0,10,17651,180000,0,-11159,-1907.22,91.48,0);

