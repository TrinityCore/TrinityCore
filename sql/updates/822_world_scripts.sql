update creature_template set scriptname='npc_kayra_longmane' where entry=17969;
delete from creature_template_addon where entry=17969;
update quest_template set specialflags=2 where entry=9752;
