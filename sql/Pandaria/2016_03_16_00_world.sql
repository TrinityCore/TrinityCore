-- Gate of the Setting Sun -- falta npc vicuous fluid
UPDATE instance_template SET script='instance_gate_setting_sun' WHERE map=962;
-- Rimok
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='boss_commander_rimok' WHERE entry=56636;
UPDATE creature_template SET minlevel=89, maxlevel=90, faction=1791, ScriptName='npc_krikthik_swarmer' WHERE entry=59835;
UPDATE creature_template SET minlevel=89, maxlevel=90, faction=1791, ScriptName='npc_krikthik_saboteur' WHERE entry=60447;
UPDATE creature_template SET minlevel=89, maxlevel=90, faction=1791, ScriptName='npc_add_generator' WHERE entry=59834;
INSERT INTO spell_script_names (spell_id,ScriptName) values (120559,'spell_rimok_saboteur_bombard');
-- Raigonn
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='boss_raigonn' WHERE entry=56877;
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='npc_raigonn_weak_spot' WHERE entry=56895;
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='npc_krikthik_protectorat' WHERE entry=56929;
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='npc_krikthik_engulfer' WHERE entry=56912;
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='npc_krikthik_swarm_bringer' WHERE entry=56930;
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='vehicle_artillery' WHERE entry=59819;
-- Kiptilak
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='boss_saboteur_kiptilak' WHERE entry=56906;
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='npc_instable_munition' WHERE entry=56917;
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='npc_munition_explosion_bunny' WHERE entry=56911;
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='npc_munition_explosion_bunny' WHERE entry=56918;
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='npc_munition_explosion_bunny' WHERE entry=56919;
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='npc_munition_explosion_bunny' WHERE entry=56920;
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='npc_munition_explosion_bunny' WHERE entry=59205;
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='npc_munition_explosion_bunny' WHERE entry=59206;
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='npc_munition_explosion_bunny' WHERE entry=59207;
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='npc_munition_explosion_bunny' WHERE entry=59208;
INSERT INTO spell_script_names (spell_id,ScriptName) values (107268,'spell_kiptilak_sabotage');
-- Gadok
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='boss_striker_gadok' WHERE entry=56589;
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='npc_krikthik_striker' WHERE entry=59778;
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='npc_krikthik_disruptor' WHERE entry=59794;
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='npc_flak_cannon' WHERE entry=60421;
INSERT INTO spell_script_names (spell_id,ScriptName) values (116298,'spell_gadok_strafing');
INSERT INTO spell_script_names (spell_id,ScriptName) values (106933,'spell_prey_time');

-- Heart of Fear
UPDATE instance_template SET script='instance_heart_of_fear' WHERE map=897;
-- Blade Lord Tayak
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='boss_blade_lord_tayak' WHERE entry=62543;
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='mob_tempest_slash' WHERE entry=62908;
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='mob_tayak_tornado_all' WHERE entry=63567;
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='mob_tayak_tornado' WHERE entry=63299;
INSERT INTO spell_script_names (spell_id,ScriptName) values (122994,'spell_invisible_strike');
-- Garalon
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='boss_garalon' WHERE entry=62164;
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='boss_garalon' WHERE entry=63053;
INSERT INTO spell_script_names (spell_id,ScriptName) values (122754,'spell_garalon_furious_swipe');
INSERT INTO spell_script_names (spell_id,ScriptName) values (122774,'spell_garalon_crush_searcher');
INSERT INTO spell_script_names (spell_id,ScriptName) values (129815,'spell_garalon_pheromones_first_target_selector');
-- Vizier Zorlock
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='boss_vizier_zorlock' WHERE entry=62980;
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='mob_sonic_ring' WHERE entry=62727;
INSERT INTO spell_script_names (spell_id,ScriptName) values (122718,'spell_force_and_verve_damage');
INSERT INTO spell_script_names (spell_id,ScriptName) values (122336,'spell_zorlock_sonic_ring');
INSERT INTO spell_script_names (spell_id,ScriptName) values (122740,'spell_zorlock_convert');

-- MoguShan Palace
UPDATE instance_template SET script='instance_mogu_shan_palace' WHERE map=885;
--UPDATE gameobject_template SET ScriptName='go_mogushan_palace_temp_portal' WHERE entry=;
-- Gekkan
UPDATE creature_template SET minlevel=89, maxlevel=92, faction=1791, ScriptName='boss_gekkan' WHERE entry=61243;
UPDATE creature_template SET minlevel=89, maxlevel=92, faction=1791, ScriptName='mob_glintrok_skulker' WHERE entry=61338;
UPDATE creature_template SET minlevel=89, maxlevel=92, faction=1791, ScriptName='mob_glintrok_ironhide' WHERE entry=61337;
UPDATE creature_template SET minlevel=89, maxlevel=92, faction=1791, ScriptName='mob_glintrok_oracle' WHERE entry=61339;
UPDATE creature_template SET minlevel=89, maxlevel=92, faction=1791, ScriptName='mob_glintrok_hexxer' WHERE entry=61340;
-- Trial of the King
UPDATE creature_template SET minlevel=89, maxlevel=92, faction=1791, ScriptName='mob_xian_the_weaponmaster_trigger' WHERE entry=61884;
UPDATE creature_template SET minlevel=89, maxlevel=92, faction=1791, ScriptName='boss_ming_the_cunning' WHERE entry=61444;
UPDATE creature_template SET minlevel=89, maxlevel=92, faction=1791, ScriptName='mob_whirling_dervish' WHERE entry=61626;
UPDATE creature_template SET minlevel=89, maxlevel=92, faction=1791, ScriptName='mob_adepts' WHERE entry=61449;
UPDATE creature_template SET minlevel=89, maxlevel=92, faction=1791, ScriptName='boss_kuai_the_brute' WHERE entry=61442;
UPDATE creature_template SET minlevel=89, maxlevel=92, faction=1791, ScriptName='mob_mu_shiba' WHERE entry=61453;
UPDATE creature_template SET minlevel=89, maxlevel=92, faction=1791, ScriptName='boss_haiyan_the_unstoppable' WHERE entry=61445;
-- Xin the Weaponmaster
UPDATE creature_template SET minlevel=89, maxlevel=92, faction=1791, ScriptName='boss_xin_the_weaponmaster' WHERE entry=61398;
UPDATE creature_template SET minlevel=89, maxlevel=92, faction=1791, ScriptName='mob_animated_staff' WHERE entry=61433;
INSERT INTO spell_script_names (spell_id,ScriptName) values (119311,'spell_dart');

-- MoguShan Vaults
UPDATE instance_template SET script='instance_mogu_shan_vault' WHERE map=896;
-- Elegon
UPDATE creature_template SET minlevel=89, maxlevel=92, faction=1791, ScriptName='boss_elegon' WHERE entry=60410;
UPDATE creature_template SET minlevel=89, maxlevel=92, faction=1791, ScriptName='mob_empyreal_focus' WHERE entry=60776;
UPDATE creature_template SET minlevel=89, maxlevel=92, faction=1791, ScriptName='mob_celestial_protector' WHERE entry=60793;
UPDATE creature_template SET minlevel=89, maxlevel=92, faction=1791, ScriptName='mob_cosmic_spark' WHERE entry=62618;
UPDATE creature_template SET minlevel=89, maxlevel=92, faction=1791, ScriptName='mob_energy_charge' WHERE entry=60913;
UPDATE creature_template SET minlevel=89, maxlevel=92, faction=1791, ScriptName='mob_infinite_energy' WHERE entry=65293;
UPDATE gameobject_template SET ScriptName='go_celestial_control_console' WHERE entry=211650;
INSERT INTO spell_script_names (spell_id,ScriptName) values (127785,'spell_spawn_flash_1_periodic');
INSERT INTO spell_script_names (spell_id,ScriptName) values (127783,'spell_spawn_flash_2_periodic');
INSERT INTO spell_script_names (spell_id,ScriptName) values (127781,'spell_spawn_flash_3_periodic');
INSERT INTO spell_script_names (spell_id,ScriptName) values (117874,'spell_touch_of_titans');
INSERT INTO spell_script_names (spell_id,ScriptName) values (118313,'spell_radiating_energies');
INSERT INTO spell_script_names (spell_id,ScriptName) values (119360,'spell_draw_power');
INSERT INTO spell_script_names (spell_id,ScriptName) values (124967,'spell_draw_power');
INSERT INTO spell_script_names (spell_id,ScriptName) values (118024,'spell_core_checker');
INSERT INTO spell_script_names (spell_id,ScriptName) values (127362,'spell_grasping_energy_tendrils');
INSERT INTO spell_script_names (spell_id,ScriptName) values (116994,'spell_unstable_energy');
INSERT INTO spell_script_names (spell_id,ScriptName) values (129711,'spell_total_annihilation');
INSERT INTO spell_script_names (spell_id,ScriptName) values (132222,'spell_destabilizing_energies');
-- Feng
UPDATE creature_template SET minlevel=89, maxlevel=92, faction=1791, ScriptName='boss_feng' WHERE entry=60009;
--UPDATE creature_template SET minlevel=89, maxlevel=92, faction=1791, ScriptName='mob_lightning_fist' WHERE entry=;
UPDATE creature_template SET minlevel=89, maxlevel=92, faction=1791, ScriptName='mob_wild_spark' WHERE entry=60438;
UPDATE creature_template SET minlevel=89, maxlevel=92, faction=1791, ScriptName='mob_feng_shield' WHERE entry=60627;
UPDATE creature_template SET minlevel=89, maxlevel=92, faction=1791, ScriptName='mob_soul_fragment' WHERE entry=60781;
INSERT INTO spell_script_names (spell_id,ScriptName) values (116040,'spell_mogu_epicenter');
INSERT INTO spell_script_names (spell_id,ScriptName) values (116583,'spell_mogu_wildfire_spark');
INSERT INTO spell_script_names (spell_id,ScriptName) values (116821,'spell_wildfire_infusion_stacks');
INSERT INTO spell_script_names (spell_id,ScriptName) values (116816,'spell_mogu_wildfire_infusion');
INSERT INTO spell_script_names (spell_id,ScriptName) values (116711,'spell_draw_flame');
INSERT INTO spell_script_names (spell_id,ScriptName) values (116365,'spell_mogu_arcane_velocity');
INSERT INTO spell_script_names (spell_id,ScriptName) values (116434,'spell_mogu_arcane_resonance');
INSERT INTO spell_script_names (spell_id,ScriptName) values (118300,'spell_mogu_inversion');
INSERT INTO spell_script_names (spell_id,ScriptName) values (118302,'spell_mogu_inversion');
INSERT INTO spell_script_names (spell_id,ScriptName) values (118304,'spell_mogu_inversion');
INSERT INTO spell_script_names (spell_id,ScriptName) values (118305,'spell_mogu_inversion');
INSERT INTO spell_script_names (spell_id,ScriptName) values (118307,'spell_mogu_inversion');
INSERT INTO spell_script_names (spell_id,ScriptName) values (118308,'spell_mogu_inversion');
INSERT INTO spell_script_names (spell_id,ScriptName) values (132296,'spell_mogu_inversion');
INSERT INTO spell_script_names (spell_id,ScriptName) values (132297,'spell_mogu_inversion');
INSERT INTO spell_script_names (spell_id,ScriptName) values (132298,'spell_mogu_inversion');
UPDATE gameobject_template SET ScriptName='go_inversion' WHERE entry=211628;
UPDATE gameobject_template SET ScriptName='go_cancel' WHERE entry=211626;
-- Garajal
UPDATE creature_template SET minlevel=89, maxlevel=92, faction=1791, ScriptName='boss_garajal' WHERE entry=60143;
UPDATE creature_template SET minlevel=89, maxlevel=92, faction=1791, ScriptName='mob_garajal_ghost' WHERE entry=61172;
UPDATE creature_template SET minlevel=89, maxlevel=92, faction=1791, ScriptName='mob_spirit_totem' WHERE entry=60240;
UPDATE creature_template SET minlevel=89, maxlevel=92, faction=1791, ScriptName='mob_shadowy_minion' WHERE entry=60940;
UPDATE creature_template SET minlevel=89, maxlevel=92, faction=1791, ScriptName='mob_soul_cutter' WHERE entry=62003;
UPDATE creature_template SET minlevel=89, maxlevel=92, faction=1791, ScriptName='mob_spirit_totem_intro' WHERE entry=60512;
INSERT INTO spell_script_names (spell_id,ScriptName) values (120715,'spell_soul_back');
INSERT INTO spell_script_names (spell_id,ScriptName) values (118469,'spell_final_destination');
-- Spirit Kings
UPDATE creature_template SET minlevel=89, maxlevel=92, faction=1791, ScriptName='boss_spirit_kings_controler' WHERE entry=60984;
UPDATE creature_template SET minlevel=89, maxlevel=92, faction=1791, ScriptName='boss_spirit_kings' WHERE entry=60701;
UPDATE creature_template SET minlevel=89, maxlevel=92, faction=1791, ScriptName='boss_spirit_kings' WHERE entry=60708;
UPDATE creature_template SET minlevel=89, maxlevel=92, faction=1791, ScriptName='boss_spirit_kings' WHERE entry=60709;
UPDATE creature_template SET minlevel=89, maxlevel=92, faction=1791, ScriptName='boss_spirit_kings' WHERE entry=60710;
UPDATE creature_template SET minlevel=89, maxlevel=92, faction=1791, ScriptName='mob_pinning_arrow' WHERE entry=60958;
UPDATE creature_template SET minlevel=89, maxlevel=92, faction=1791, ScriptName='mob_undying_shadow' WHERE entry=60731;
INSERT INTO spell_script_names (spell_id,ScriptName) values (117921,'spell_massive_attacks');
INSERT INTO spell_script_names (spell_id,ScriptName) values (118094,'spell_volley');
INSERT INTO spell_script_names (spell_id,ScriptName) values (118105,'spell_volley');
INSERT INTO spell_script_names (spell_id,ScriptName) values (118106,'spell_volley');
INSERT INTO spell_script_names (spell_id,ScriptName) values (118145,'spell_pinned_down');
INSERT INTO spell_script_names (spell_id,ScriptName) values (117708,'spell_maddening_shout');
INSERT INTO spell_script_names (spell_id,ScriptName) values (117756,'spell_crazed_cowardice');
INSERT INTO spell_script_names (spell_id,ScriptName) values (117737,'spell_crazed_cowardice');
INSERT INTO spell_script_names (spell_id,ScriptName) values (117833,'spell_crazy_thought');
INSERT INTO spell_script_names (spell_id,ScriptName) values (117558,'spell_coalescing_shadow');
-- Stone Guard
UPDATE creature_template SET minlevel=89, maxlevel=92, faction=1791, ScriptName='boss_stone_guard_controler' WHERE entry=60089;
UPDATE creature_template SET minlevel=89, maxlevel=92, faction=1791, ScriptName='boss_generic_guardian' WHERE entry=59915;
UPDATE creature_template SET minlevel=89, maxlevel=92, faction=1791, ScriptName='boss_generic_guardian' WHERE entry=60043;
UPDATE creature_template SET minlevel=89, maxlevel=92, faction=1791, ScriptName='boss_generic_guardian' WHERE entry=60047;
UPDATE creature_template SET minlevel=89, maxlevel=92, faction=1791, ScriptName='boss_generic_guardian' WHERE entry=60051;
UPDATE creature_template SET minlevel=89, maxlevel=92, faction=1791, ScriptName='npc_stone_guard_crystal' WHERE entry=60304;
UPDATE creature_template SET minlevel=89, maxlevel=92, faction=1791, ScriptName='npc_stone_guard_crystal' WHERE entry=60306;
UPDATE creature_template SET minlevel=89, maxlevel=92, faction=1791, ScriptName='npc_stone_guard_crystal' WHERE entry=60307;
UPDATE creature_template SET minlevel=89, maxlevel=92, faction=1791, ScriptName='npc_stone_guard_crystal' WHERE entry=60308;
UPDATE creature_template SET minlevel=89, maxlevel=92, faction=1791, ScriptName='mob_cobalt_mine' WHERE entry=65803;
UPDATE creature_template SET minlevel=89, maxlevel=92, faction=1791, ScriptName='mob_tile' WHERE entry=300000;
INSERT INTO spell_script_names (spell_id,ScriptName) values (115852,'spell_petrification');
INSERT INTO spell_script_names (spell_id,ScriptName) values (116006,'spell_petrification');
INSERT INTO spell_script_names (spell_id,ScriptName) values (116036,'spell_petrification');
INSERT INTO spell_script_names (spell_id,ScriptName) values (116057,'spell_petrification');
INSERT INTO spell_script_names (spell_id,ScriptName) values (130404,'spell_jasper_chains_damage');
-- Will of Emperor
UPDATE creature_template SET minlevel=89, maxlevel=92, faction=1791, ScriptName='boss_jin_qin_xi' WHERE entry=60399;
UPDATE creature_template SET minlevel=89, maxlevel=92, faction=1791, ScriptName='mob_woe_add_generic' WHERE entry=60396;
UPDATE creature_template SET minlevel=89, maxlevel=92, faction=1791, ScriptName='mob_woe_add_generic' WHERE entry=60397;
UPDATE creature_template SET minlevel=89, maxlevel=92, faction=1791, ScriptName='mob_woe_add_generic' WHERE entry=60398;
UPDATE creature_template SET minlevel=89, maxlevel=92, faction=1791, ScriptName='mob_woe_titan_spark' WHERE entry=60480;
UPDATE gameobject_template SET ScriptName='go_ancient_control_console' WHERE entry=211584;
INSERT INTO spell_script_names (spell_id,ScriptName) values (116818,'spell_will_of_emperor_magnetic_armor');
INSERT INTO spell_script_names (spell_id,ScriptName) values (117195,'spell_will_of_emperor_magnetic_armor');
INSERT INTO spell_script_names (spell_id,ScriptName) values (116815,'spell_will_of_emperor_magnetic_armor_grip');
INSERT INTO spell_script_names (spell_id,ScriptName) values (117193,'spell_will_of_emperor_magnetic_armor_grip');
INSERT INTO spell_script_names (spell_id,ScriptName) values (116550,'spell_energizing_smash');














































