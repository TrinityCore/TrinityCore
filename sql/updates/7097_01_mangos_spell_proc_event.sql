ALTER TABLE db_version CHANGE COLUMN required_7092_01_mangos_player_xp_for_level required_7097_01_mangos_spell_proc_event bit;

-- (35100) Concussive Barrage (Rank 1)
DELETE FROM `spell_proc_event` WHERE `entry` IN (35100);
INSERT INTO `spell_proc_event` VALUES (35100, 0x00, 9, 0x00003001, 0x00000000, 0x00000000, 0x00010140, 0x00000000, 0.000000, 0.000000, 0);

-- (35102) Concussive Barrage (Rank 2)
DELETE FROM `spell_proc_event` WHERE `entry` IN (35102);
INSERT INTO `spell_proc_event` VALUES (35102, 0x00, 9, 0x00003001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);

-- (35103) Concussive Barrage (Rank 3)
DELETE FROM `spell_proc_event` WHERE `entry` IN (35103);
INSERT INTO `spell_proc_event` VALUES (35103, 0x00, 9, 0x00003001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);

-- (16164) Elemental Focus ()
DELETE FROM `spell_proc_event` WHERE `entry` IN (16164);
INSERT INTO `spell_proc_event` VALUES (16164, 0x00, 11, 0x901000C3, 0x00000000, 0x00000000, 0x00000000, 0x00000002, 0.000000, 0.000000, 0);

-- (42770) Second Wind (Rank 2)
DELETE FROM `spell_proc_event` WHERE `entry` IN (42770);
INSERT INTO `spell_proc_event` VALUES (42770, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010000, 0.000000, 0.000000, 0);

-- (47580) Pain and Suffering (Rank 1)
DELETE FROM `spell_proc_event` WHERE `entry` IN (47580);
INSERT INTO `spell_proc_event` VALUES (47580, 0x00, 6, 0x00000000, 0x00000000, 0x00000040, 0x00000000, 0x00010000, 0.000000, 0.000000, 0);

-- (47581) Pain and Suffering (Rank 2)
DELETE FROM `spell_proc_event` WHERE `entry` IN (47581);
INSERT INTO `spell_proc_event` VALUES (47581, 0x00, 6, 0x00000000, 0x00000000, 0x00000040, 0x00000000, 0x00010000, 0.000000, 0.000000, 0);

-- (47582) Pain and Suffering (Rank 3)
DELETE FROM `spell_proc_event` WHERE `entry` IN (47582);
INSERT INTO `spell_proc_event` VALUES (47582, 0x00, 6, 0x00000000, 0x00000000, 0x00000040, 0x00000000, 0x00010000, 0.000000, 0.000000, 0);

-- (47535) Rapture (Rank 1)
DELETE FROM `spell_proc_event` WHERE `entry` IN (47535);
INSERT INTO `spell_proc_event` VALUES (47535, 0x00, 6, 0x00001800, 0x00800000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);

-- (47536) Rapture (Rank 2)
DELETE FROM `spell_proc_event` WHERE `entry` IN (47536);
INSERT INTO `spell_proc_event` VALUES (47536, 0x00, 6, 0x00001800, 0x00800000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);

-- (47537) Rapture (Rank 3)
DELETE FROM `spell_proc_event` WHERE `entry` IN (47537);
INSERT INTO `spell_proc_event` VALUES (47537, 0x00, 6, 0x00001800, 0x00800000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);

-- (47538) Rapture (Rank 4)
DELETE FROM `spell_proc_event` WHERE `entry` IN (47538);
INSERT INTO `spell_proc_event` VALUES (47538, 0x00, 6, 0x00001800, 0x00800000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);

-- (47539) Rapture (Rank 5)
DELETE FROM `spell_proc_event` WHERE `entry` IN (47539);
INSERT INTO `spell_proc_event` VALUES (47539, 0x00, 6, 0x00001800, 0x00800000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);

-- (61257) Runic Power Back on Snare/Root (Rank 5)
DELETE FROM `spell_proc_event` WHERE `entry` IN (61257);
INSERT INTO `spell_proc_event` VALUES (61257, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x000202A8, 0x00010000, 0.000000, 0.000000, 0);

