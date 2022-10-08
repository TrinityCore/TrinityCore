DELETE FROM `spell_proc_event` WHERE `entry` IN (137384);
INSERT INTO `spell_proc_event` VALUES (137384, 0, 0, 4, 0, 0, 0, 0x00000010, 0, 0, 100, 0, 7);

DELETE FROM `spell_proc_event` WHERE `entry` IN (116768);
INSERT INTO `spell_proc_event` VALUES (116768, 0, 0, 16, 0, 0, 0, 0x00000010, 0, 0, 100, 0, 7);

DELETE FROM `spell_proc_event` WHERE `entry` IN (118864);
INSERT INTO `spell_proc_event` VALUES (118864, 0, 0, 1024, 0, 0, 0, 0x00000010, 0, 0, 100, 0, 7);

INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `option`, `chance`, `comment`) VALUES ('137384', '116768', '20', '101', 'Combo Breaker: Blackout Kick');
INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `option`, `chance`, `comment`) VALUES ('137384', '118864', '20', '101', 'Combo Breaker: Tiger Palm');