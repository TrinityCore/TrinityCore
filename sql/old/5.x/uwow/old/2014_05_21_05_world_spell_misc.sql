DELETE FROM `spell_script_names` WHERE (`spell_id`='114163') AND (`ScriptName`='spell_pal_eternal_flame');
DELETE FROM `spell_script_names` WHERE (`spell_id`='84963') AND (`ScriptName`='spell_pal_inquisition');

DELETE FROM `spell_proc_event` WHERE `entry` IN (54936);
INSERT INTO `spell_proc_event` VALUES (54936, 0, 0, 0, 0, 33554432+16384, 0, 0x00004000, 0, 0, 100, 0, 7);