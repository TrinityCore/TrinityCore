DELETE FROM `spell_proc_event` WHERE `entry` IN (49194);
INSERT INTO `spell_proc_event` VALUES
(49194, 0x00, 15, 0x00002000, 0x00000000, 0x00000000, 0x00000000,  0x00000000, 0.000000, 0.000000, 0);

DELETE FROM `spell_proc_event` WHERE `entry` IN (31656, 31657, 31658);
INSERT INTO `spell_proc_event` VALUES
(31656, 4, 3, 0x8000000, 0, 0, 0, 0, 0, 0, 0),
(31657, 4, 3, 0x8000000, 0, 0, 0, 0, 0, 0, 0),
(31658, 4, 3, 0x8000000, 0, 0, 0, 0, 0, 0, 0);

DELETE FROM `spell_proc_event` WHERE entry = 67356;
INSERT INTO `spell_proc_event` VALUES (67356, 8, 7, 0x10, 0, 0, 0, 0, 0, 0, 0);

DELETE FROM `spell_proc_event` WHERE `entry` IN (47245,47246,47247);
INSERT INTO `spell_proc_event` VALUES
(47245, 0x00, 5, 0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0.000000, 0.000000, 0),
(47246, 0x00, 5, 0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0.000000, 0.000000, 0),
(47247, 0x00, 5, 0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0.000000, 0.000000, 0);

DELETE FROM `spell_proc_event` WHERE `entry` IN
(58631,55668,55669,55670,63320);

DELETE FROM `spell_proc_event` WHERE `entry` IN (20375,21084,31801);
INSERT INTO `spell_proc_event` VALUES
(20375, 0x00000001,  0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000,  1),
(21084, 0x00000001,  0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000,  0),
(31801, 0x00000001,  0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000,  0);

DELETE FROM `spell_proc_event` WHERE `entry` IN (51524,51523);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES ('51524', '0', '11', '0', '1', '0', '65536', '0', '0', '50', '0');
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES ('51523', '0', '11', '0', '1', '0', '65536', '0', '0', '50', '0');

