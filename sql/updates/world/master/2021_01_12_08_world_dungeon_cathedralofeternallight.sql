-- thrashbite the scornful
update creature_template set scriptname='boss_thrashbite_the_scornful' where entry=117194;

replace into spell_script_names values (238484,'spell_coen_beguiling_bio');
replace into spell_script_names values (237726,'spell_coen_scornful_gaze');

-- mephistroth
update creature_template set scriptname='boss_mephistroth' where entry=116944;
update creature_template set scriptname='npc_mephistroth_illidan' where entry=117855;

replace into spell_script_names values (233155,'spell_mephistroth_carrion_swarm');
replace into spell_script_names values (234114,'spell_mephistroth_egida');

replace into areatrigger_scripts values (15295,'areatrigger_mephistroth_shadow_blast');

-- domatrax
update creature_template set scriptname='boss_domatrax' where entry=118804;
update creature_template set scriptname='npc_coen_egida' where entry=118884;

replace into spell_script_names values (235881,'spell_domatrax_portals');
replace into spell_script_names values (235827,'spell_domatrax_portals');

replace into areatrigger_scripts values (14825,'areatrigger_domatrax_egida_shield');

-- agronox
update creature_template set scriptname='boss_agronox' where entry=117193;

replace into spell_script_names values (238598,'spell_agronox_choking_vines');