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

-- Mogu Shan Palace
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























