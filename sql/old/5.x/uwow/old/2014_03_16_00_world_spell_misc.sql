DELETE FROM `spell_proc_event` WHERE `entry` IN (108869);
INSERT INTO `spell_proc_event` VALUES (108869, 0, 0, 1, 128, 0, 0, 0x00010000, 0, 0, 100, 0, 7);

DELETE FROM `spell_script_names` WHERE (`spell_id`='686') AND (`ScriptName`='spell_warl_decimate');
DELETE FROM `spell_script_names` WHERE (`spell_id`='6353') AND (`ScriptName`='spell_warl_decimate');