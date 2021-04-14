-- dargrul the underking
update creature_template set scriptname='boss_dargrul_the_underking' where entry=91007;
update creature_template set scriptname='npc_dargrul_molten_charskin' where entry=101476;
update creature_template set scriptname='npc_dargrul_crystal_wall' where entry=101593;
update creature_template set scriptname='npc_dargrul_lava_geyser' where entry=108926;
update creature_template set scriptname='npc_nl_understone_demolisher' where entry=102253;
update creature_template set scriptname='npc_emberhusk_dominator' where entry=102295;

replace into spell_script_names values (201444,'spell_dargrul_gain_energy');
replace into spell_script_names values (200404,'spell_dargrul_magma_wave_filter');
replace into spell_script_names values (217090,'spell_dargrul_magma_wave_filter');
replace into spell_script_names values (209920,'spell_dargrul_magma_breaker');
replace into spell_script_names values (216368,'spell_dargrul_magma_breaker');
replace into spell_script_names values (200721,'spell_dargrul_landslide_filter');

-- naraxas 
update creature_template set scriptname='boss_naraxas' where entry=91005;
update creature_template set scriptname='npc_naraxas_wormspeaker_devout' where entry=101075;

replace into spell_script_names values (200086,'spell_naraxas_gain_energy');

-- rokmora
update creature_template set scriptname='boss_rokmora' where entry=91003;
update creature_template set scriptname='npc_rokmora_blightshard_skitter' where entry=97720;
update creature_template set scriptname='npc_nl_tarspitter_lurker' where entry=91001;
update creature_template set scriptname='npc_nl_vileshard_hulk' where entry=91000;

replace into spell_script_names values (200247,'spell_rokmora_shatter_kill');
replace into spell_script_names values (193245,'spell_rokmora_gain_energy');
replace into spell_script_names values (215898,'spell_rokmora_crystalline_ground');
replace into spell_script_names values (183433,'spell_nl_submerge');
replace into spell_script_names values (209888,'spell_entrance_run_plr_move');

-- ulraogg crahshaper
update creature_template set scriptname='boss_ularogg_cragshaper' where entry=91004;
update creature_template set scriptname='npc_ularogg_bellowing_idols' where entry in (100818,98081);
update creature_template set scriptname='npc_stonedark_slave' where entry=102228;
update creature_template set scriptname='npc_ularogg_empty_barrel' where entry=92473;
update creature_template set scriptname='npc_nl_understone_drummer' where entry=92610;

replace into spell_script_names values (183213,'spell_barrel_ride_plr_move');
replace into spell_script_names values (198719,'spell_ularogg_falling_debris');
replace into spell_script_names values (183088,'spell_nl_avalanche');
replace into spell_script_names values (198475,'spell_ularogg_strike_mountain');