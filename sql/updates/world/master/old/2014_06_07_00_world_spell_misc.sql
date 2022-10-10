INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `option`, `aura`, `comment`) VALUES ('33763', '-8936', '5', '-121840', 'Lifebloom - RefreshTimers');
INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `option`, `aura`, `comment`) VALUES ('33763', '-5185', '5', '-121840', 'Lifebloom - RefreshTimers');
INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `option`, `aura`, `comment`) VALUES ('33763', '-50464', '5', '-121840', 'Lifebloom - RefreshTimers');

DELETE FROM `spell_script_names` WHERE (`spell_id`='50464') AND (`ScriptName`='spell_dru_lifebloom_refresh');
DELETE FROM `spell_script_names` WHERE (`spell_id`='5185') AND (`ScriptName`='spell_dru_lifebloom_refresh');
DELETE FROM `spell_script_names` WHERE (`spell_id`='8936') AND (`ScriptName`='spell_dru_lifebloom_refresh');

DELETE FROM `spell_proc_event` WHERE `entry` IN (33763);
INSERT INTO `spell_proc_event` VALUES (33763, 0, 7, 32+64, 33554432, 0, 0, 0x00008000, 0, 0, 100, 0, 7);