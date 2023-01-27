INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('50274', 'spell_hunt_spore_cloud');

DELETE FROM `spell_proc_event` WHERE `entry` IN (144767);
INSERT INTO `spell_proc_event` VALUES (144767, 0, 0x07, 0, 0, 0, 0, 65536, 0, 0, 0, 0, 7);