-- harlan
update creature_template set scriptname='boss_armsmaster_harlan' where entry=58632;
update creature_template set scriptname='npc_scarlet_defender' where entry=58998;

replace into spell_script_names values (111394,'spell_blades_of_light');
replace into spell_script_names values (113959,'spell_heavy_armor');

-- flameweaver koegler
update creature_template set scriptname='boss_flameweaver_koegler' where entry=59150;
update creature_template set scriptname='npc_dragon_breath_target' where entry=59198;

-- braun
update creature_template set scriptname='boss_houndmaster_braun' where entry=59303;
update creature_template set scriptname='npc_obedient_hound' where entry=59309;

replace into criteria_data values (20983,0,0,0,'achievement_humane_society');
