DELETE FROM `spell_proc_event` WHERE `entry` IN (146631);
INSERT INTO `spell_proc_event` VALUES (146631, 0, 0, 0, 0, 16, 0, 0x00000010, 0, 0, 100, 0, 7);

INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `option`, `aura`, `comment`) VALUES ('146631', '124271', '20', '79147', 'Glyph of Hemorrhaging Veins');

DELETE FROM `spell_proc_event` WHERE `entry` IN (79147);
INSERT INTO `spell_proc_event` VALUES (79147, 0, 0, 1048832, 0, 131072, 0, 0, 0, 0, 100, 0, 7);