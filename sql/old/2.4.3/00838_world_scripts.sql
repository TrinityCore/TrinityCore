UPDATE `creature_template` SET `ScriptName`='npc_kyle_frenzied' WHERE `entry`='23616';
DELETE FROM `spell_script_target` WHERE `entry`=42222;
INSERT INTO `spell_script_target` VALUES
('42222','1','23616');
