INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(48077, 48075, 0, 'Holy Nova (rank8)'),
(48078, 48076, 0, 'Holy Nova (rank9)'),
(47585, 60069, 0, 'Dispersion (transform/regen)');

DELETE FROM `spell_proc_event` WHERE `entry` IN (47549);
INSERT INTO `spell_proc_event` VALUES (47549, 0x00, 6, 0x00000000, 0x00000200, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);
DELETE FROM `spell_proc_event` WHERE `entry` IN (47551);
INSERT INTO `spell_proc_event` VALUES (47551, 0x00, 6, 0x00000000, 0x00000200, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);
DELETE FROM `spell_proc_event` WHERE `entry` IN (47552);
INSERT INTO `spell_proc_event` VALUES (47552, 0x00, 6, 0x00000000, 0x00000200, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);
