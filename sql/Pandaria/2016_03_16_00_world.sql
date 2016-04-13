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







