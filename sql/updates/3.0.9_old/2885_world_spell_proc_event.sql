DELETE FROM `spell_proc_event` WHERE `entry` IN (34457);
INSERT INTO `spell_proc_event` VALUES
(34457, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000002, 0.000000, 0.000000, 0);
DELETE FROM `spell_proc_event` WHERE `entry` IN (34456);
INSERT INTO `spell_proc_event` VALUES
(19615, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000002, 0.000000, 0.000000, 0);

INSERT INTO trinity_string (entry, content_default)VALUES (6616 , "Pet spells will reset for all players at login. Strongly recommend re-login!");