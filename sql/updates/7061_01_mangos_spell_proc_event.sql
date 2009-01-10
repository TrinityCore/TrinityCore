ALTER TABLE db_version CHANGE COLUMN required_7060_01_mangos_spell_proc_event required_7061_01_mangos_spell_proc_event bit;

-- (47516) Grace (Rank 1)
DELETE FROM `spell_proc_event` WHERE `entry` IN (47516);
INSERT INTO `spell_proc_event` VALUES (47516, 0x00, 6, 0x00001800, 0x00010000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);

-- (47517) Grace (Rank 2)
DELETE FROM `spell_proc_event` WHERE `entry` IN (47517);
INSERT INTO `spell_proc_event` VALUES (47517, 0x00, 6, 0x00001800, 0x00010000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);

-- (14892) Inspiration (Rank 1)
DELETE FROM `spell_proc_event` WHERE `entry` IN (14892);
INSERT INTO `spell_proc_event` VALUES (14892, 0x00, 6, 0x10001E00, 0x00010004, 0x00000000, 0x00000000, 0x00000002, 0.000000, 0.000000, 0);

-- (15362) Inspiration (Rank 2)
DELETE FROM `spell_proc_event` WHERE `entry` IN (15362);
INSERT INTO `spell_proc_event` VALUES (15362, 0x00, 6, 0x10001E00, 0x00010004, 0x00000000, 0x00000000, 0x00000002, 0.000000, 0.000000, 0);

-- (15363) Inspiration (Rank 3)
DELETE FROM `spell_proc_event` WHERE `entry` IN (15363);
INSERT INTO `spell_proc_event` VALUES (15363, 0x00, 6, 0x10001E00, 0x00010004, 0x00000000, 0x00000000, 0x00000002, 0.000000, 0.000000, 0);

-- (47535) Rapture (Rank 1)
DELETE FROM `spell_proc_event` WHERE `entry` IN (47535);
INSERT INTO `spell_proc_event` VALUES (47535, 0x00, 6, 0x00001800, 0x00800000, 0x00000000, 0x00000000, 0x00010000, 0.000000, 0.000000, 0);

-- (47536) Rapture (Rank 2)
DELETE FROM `spell_proc_event` WHERE `entry` IN (47536);
INSERT INTO `spell_proc_event` VALUES (47536, 0x00, 6, 0x00001800, 0x00800000, 0x00000000, 0x00000000, 0x00010000, 0.000000, 0.000000, 0);

-- (47537) Rapture (Rank 3)
DELETE FROM `spell_proc_event` WHERE `entry` IN (47537);
INSERT INTO `spell_proc_event` VALUES (47537, 0x00, 6, 0x00001800, 0x00800000, 0x00000000, 0x00000000, 0x00010000, 0.000000, 0.000000, 0);

-- (47538) Rapture (Rank 4)
DELETE FROM `spell_proc_event` WHERE `entry` IN (47538);
INSERT INTO `spell_proc_event` VALUES (47538, 0x00, 6, 0x00001800, 0x00800000, 0x00000000, 0x00000000, 0x00010000, 0.000000, 0.000000, 0);

-- (47539) Rapture (Rank 5)
DELETE FROM `spell_proc_event` WHERE `entry` IN (47539);
INSERT INTO `spell_proc_event` VALUES (47539, 0x00, 6, 0x00001800, 0x00800000, 0x00000000, 0x00000000, 0x00010000, 0.000000, 0.000000, 0);
