UPDATE creature_template SET ScriptName='npc_shadron' WHERE entry=30451; -- shadron in obsidsanct
UPDATE creature SET ScriptName='npc_shadron' WHERE id=30451; -- shadron in obsidsanct
UPDATE creature SET ScriptName='npc_tenebron' WHERE id=30452; -- tenebron in obsidsanct
UPDATE creature_template SET ScriptName='npc_tenebron' WHERE entry=30452; -- tenebron in obsidsanct
UPDATE creature_template SET ScriptName='npc_acolyte_of_shadron' WHERE entry=31218; -- acolyte of shadron
UPDATE creature_template SET ScriptName='npc_acolyte_of_vesperon' WHERE entry=31219; -- acolyte of vesperon
UPDATE creature_template SET ScriptName='npc_twilight_eggs' WHERE entry=30882; -- twilight eggs in OS
UPDATE creature_template SET ScriptName='npc_twilight_whelp' WHERE entry=31214; -- twilight whelps
UPDATE creature_template SET ScriptName='npc_calamir_wrathful_flames' WHERE entry=109456;
UPDATE creature_template SET ScriptName='boss_calamir' WHERE entry=109331;
UPDATE creature_template SET ScriptName='boss_nithogg' WHERE entry=107544;
UPDATE creature_template SET ScriptName='boss_flotsam' WHERE entry=99929;
UPDATE creature_template SET ScriptName='npc_flotsam_regurgitated_marshstomper' WHERE entry=112128;
DELETE FROM spell_script_names WHERE spell_id=217893;
INSERT INTO spell_script_names (spell_id, ScriptName) VALUES (217893,'spell_calamir_wf_target_picker');
DELETE FROM spell_script_names WHERE spell_id=217986;
INSERT INTO spell_script_names (spell_id, ScriptName) VALUES (217986,'spell_calamir_arcane_desolation_target');
DELETE FROM areatrigger_scripts WHERE entry IN (7625,7630,7650,7640);
INSERT INTO areatrigger_scripts (entry,ScriptName) VALUES 
(7625,'at_calamir_wrathful_flames'),
(7630,'at_calamir_icy_comet'),
(7650,'at_calamir_arcanopulse'),
(7640,'at_calamir_howling_gale');
DELETE FROM spell_script_names WHERE spell_id IN (220377,220340,220295,223357);
INSERT INTO spell_script_names (spell_id, ScriptName) VALUES 
(220377,'spell_flotsam_getsam_damage'),
(220340,'spell_flotsam_getsam_target'),
(220295,'spell_flotsam_jetsam_target'),
(223357,'spell_flotsam_oozing_bile_aura');
UPDATE creature_template SET ScriptName='boss_humongris' WHERE entry=108879;
DELETE FROM spell_script_names WHERE spell_id=216427;
INSERT INTO spell_script_names (spell_id, ScriptName) VALUES (216427,'spell_humongris_fire_boom_target');
DELETE FROM spell_script_names WHERE spell_id=216817;
INSERT INTO spell_script_names (spell_id, ScriptName) VALUES (216817,'spell_humongris_you_go_bang');
DELETE FROM areatrigger_scripts WHERE entry IN (7053);
INSERT INTO areatrigger_scripts (entry,ScriptName) VALUES 
(7053,'at_nithogg_electrical_storm');
