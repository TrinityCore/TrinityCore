-- smashspite the hateful
update creature_template set scriptname='boss_smashspite_the_hateful' where entry=98949;
update creature_template set scriptname='npc_smashspite_fel_bat' where entry=100759;
update creature_template set scriptname='npc_brh_fel_bat' where entry=102781;

replace into spell_script_names values (198114,'spell_smashpite_brutality_proc');

-- lord kurtalos ravencrest
update creature_template set scriptname='npc_kurtalos_stinging_swarm' where entry=101008;
update creature_template set scriptname='npc_kurtalos_ravencrest' where entry=98965;
update creature_template set scriptname='npc_kurtalos_trigger' where entry in (101054,100861,101028);
update creature_template set scriptname='boss_latosius' where entry=98970;

replace into spell_script_names values (201733,'spell_kurtalos_stinging_swarm');
replace into spell_script_names values (198835,'spell_latosius_random_teleport');

-- illysanna ravencrest
update creature_template set scriptname='boss_illysanna_ravencrest' where entry=98696;
update creature_template set scriptname='npc_illysanna_eye_beam_stalker' where entry=100436;
update creature_template set scriptname='npc_illysanna_commandir' where entry=98706;
update creature_template set scriptname='npc_illysanna_trash_generic' where entry=100486;
update creature_template set scriptname='npc_brh_boulder' where entry=111706;
update creature_template set scriptname='npc_brh_wyrmtongue_scavenger' where entry=98792;

replace into spell_script_names values (197394,'spell_illysanna_periodic_energize');
replace into spell_script_names values (197696,'spell_illysanna_eye_beams');
replace into spell_script_names values (197484,'spell_illysanna_dark_rush');

replace into criteria_data values (32384,0,0,0,'achievement_adds_more_like_bads');

-- amalgam of souls
update creature_template set scriptname='boss_the_amalgam_of_souls' where entry=98542;
update creature_template set scriptname='npc_soul_echoes_stalker' where entry=99090;
update creature_template set scriptname='npc_amalgam_restless_soul' where entry in (99663,99664);

replace into criteria_data values (32385,0,0,0,'achievement_black_rook_moan');