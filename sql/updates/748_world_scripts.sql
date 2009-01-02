update creature_template set scriptname='npc_infused_crystal', flags_extra=0 where entry=16364;
update quest_template set specialflags=2, reqcreatureorgoid1=0, reqcreatureorgocount1=0 where entry=8490;
delete from creature where id=17086;