-- Gate of the Setting Sun
UPDATE instance_template SET script='instance_gate_setting_sun' WHERE map=962;
UPDATE creature_template SET ScriptName='mob_serpent_spine_defender' WHERE entry=58146;
UPDATE creature_template SET ScriptName='npc_krikthik_bombarder' WHERE entry=56706;
UPDATE gameobject_template SET ScriptName='at_first_door' WHERE entry=8359;
UPDATE gameobject_template SET ScriptName='go_setting_sun_brasier' WHERE entry=213507;
INSERT INTO gamobject_template (entry,ScriptName) VALUES (400001,'go_setting_sun_temp_portal');
INSERT INTO gamobject_template (entry,ScriptName) VALUES (400002,'go_setting_sun_temp_portal');
UPDATE creature_template SET ScriptName='vehicle_artillery_to_wall' WHERE entry=66904;
INSERT INTO areatrigger_scripts values (8359,'at_first_door');

-- Rimok
UPDATE creature_template SET ScriptName='boss_commander_rimok' WHERE entry=56636;
UPDATE creature_template SET ScriptName='npc_krikthik_swarmer' WHERE entry=59835;
UPDATE creature_template SET ScriptName='npc_krikthik_saboteur' WHERE entry=60447;
UPDATE creature_template SET ScriptName='npc_add_generator' WHERE entry=59834;
INSERT INTO spell_script_names (spell_id,ScriptName) values (120559,'spell_rimok_saboteur_bombard');
-- Raigonn
UPDATE creature_template SET ScriptName='boss_raigonn' WHERE entry=56877;
UPDATE creature_template SET ScriptName='npc_raigonn_weak_spot' WHERE entry=56895;
UPDATE creature_template SET ScriptName='npc_krikthik_protectorat' WHERE entry=56929;
UPDATE creature_template SET ScriptName='npc_krikthik_engulfer' WHERE entry=56912;
UPDATE creature_template SET ScriptName='npc_krikthik_swarm_bringer' WHERE entry=56930;
UPDATE creature_template SET ScriptName='vehicle_artillery' WHERE entry=59819;
-- Kiptilak
UPDATE creature_template SET ScriptName='boss_saboteur_kiptilak' WHERE entry=56906;
UPDATE creature_template SET ScriptName='npc_instable_munition' WHERE entry=56917;
UPDATE creature_template SET ScriptName='npc_munition_explosion_bunny' WHERE entry=56911;
UPDATE creature_template SET ScriptName='npc_munition_explosion_bunny' WHERE entry=56918;
UPDATE creature_template SET ScriptName='npc_munition_explosion_bunny' WHERE entry=56919;
UPDATE creature_template SET ScriptName='npc_munition_explosion_bunny' WHERE entry=56920;
UPDATE creature_template SET ScriptName='npc_munition_explosion_bunny' WHERE entry=59205;
UPDATE creature_template SET ScriptName='npc_munition_explosion_bunny' WHERE entry=59206;
UPDATE creature_template SET ScriptName='npc_munition_explosion_bunny' WHERE entry=59207;
UPDATE creature_template SET ScriptName='npc_munition_explosion_bunny' WHERE entry=59208;
INSERT INTO spell_script_names (spell_id,ScriptName) values (107268,'spell_kiptilak_sabotage');
-- Gadok
UPDATE creature_template SET ScriptName='boss_striker_gadok' WHERE entry=56589;
UPDATE creature_template SET ScriptName='npc_krikthik_striker' WHERE entry=59778;
UPDATE creature_template SET ScriptName='npc_krikthik_disruptor' WHERE entry=59794;
UPDATE creature_template SET ScriptName='npc_flak_cannon' WHERE entry=60421;
INSERT INTO spell_script_names (spell_id,ScriptName) values (116298,'spell_gadok_strafing');
INSERT INTO spell_script_names (spell_id,ScriptName) values (106933,'spell_prey_time');
