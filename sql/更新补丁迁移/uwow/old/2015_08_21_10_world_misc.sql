INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `option`, `effectmask`, `aura`, `comment`) VALUES ('123738', '132365', '24', '32', '5487', 'Heart of the Wild VENGEANCE');

DELETE FROM `spell_proc_event` WHERE `entry` IN (123738);
INSERT INTO `spell_proc_event` VALUES (123738, 0, 0, 0, 0, 0, 0, 0, 1147, 0, 0, 0, 7);