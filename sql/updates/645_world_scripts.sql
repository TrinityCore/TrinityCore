delete from creature where id=17318;
update creature_template set scriptname='npc_geezle' where entry=17318;
delete from event_scripts where id=10675;
insert into event_scripts () VALUES (10675, 0, 10, 17318, 120000, 0, -5134.3, -11250.3, 5.29568, 6.23554), 
(10675, 72, 7, 9531, 0, 0, 0, 0, 0, 0);