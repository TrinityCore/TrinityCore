ALTER TABLE db_version CHANGE COLUMN required_7052_01_mangos_spell_proc_event required_7053_01_mangos_spell_proc_event bit;

-- (60493) Dying Curse ()
DELETE FROM `spell_proc_event` WHERE `entry` IN (60493);
INSERT INTO `spell_proc_event` VALUES (60493, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 45);

-- (60503) Taste for Blood ()
DELETE FROM `spell_proc_event` WHERE `entry` IN (60503);
INSERT INTO `spell_proc_event` VALUES (60503, 0x00, 4, 0x00000004, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);

-- (61188) Chaotic Mind ()
DELETE FROM `spell_proc_event` WHERE `entry` IN (61188);
INSERT INTO `spell_proc_event` VALUES (61188, 0x00, 5, 0x00000004, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);

-- (60170) Corruption Triggers Crit ()
DELETE FROM `spell_proc_event` WHERE `entry` IN (60170);
INSERT INTO `spell_proc_event` VALUES (60170, 0x00, 5, 0x00000006, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);

-- (36541) Curse of Burning Shadows ()
DELETE FROM `spell_proc_event` WHERE `entry` IN (36541);
INSERT INTO `spell_proc_event` VALUES (36541, 0x04, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);

-- (54278) Empowered Imp ()
DELETE FROM `spell_proc_event` WHERE `entry` IN (54278);
INSERT INTO `spell_proc_event` VALUES (54278, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002, 0.000000, 0.000000, 0);

-- (37379) Flameshadow ()
DELETE FROM `spell_proc_event` WHERE `entry` IN (37379);
INSERT INTO `spell_proc_event` VALUES (37379, 0x20, 5, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);

-- (53671) Judgements of the Pure (Rank 1)
DELETE FROM `spell_proc_event` WHERE `entry` IN (53671);
INSERT INTO `spell_proc_event` VALUES (53671, 0x00, 10, 0x00800000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);

-- (53673) Judgements of the Pure (Rank 2)
DELETE FROM `spell_proc_event` WHERE `entry` IN (53673);
INSERT INTO `spell_proc_event` VALUES (53673, 0x00, 10, 0x00800000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);

-- (54151) Judgements of the Pure (Rank 3)
DELETE FROM `spell_proc_event` WHERE `entry` IN (54151);
INSERT INTO `spell_proc_event` VALUES (54151, 0x00, 10, 0x00800000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);

-- (54154) Judgements of the Pure (Rank 4)
DELETE FROM `spell_proc_event` WHERE `entry` IN (54154);
INSERT INTO `spell_proc_event` VALUES (54154, 0x00, 10, 0x00800000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);

-- (54155) Judgements of the Pure (Rank 5)
DELETE FROM `spell_proc_event` WHERE `entry` IN (54155);
INSERT INTO `spell_proc_event` VALUES (54155, 0x00, 10, 0x00800000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);

-- (31876) Judgements of the Wise (Rank 1)
DELETE FROM `spell_proc_event` WHERE `entry` IN (31876);
INSERT INTO `spell_proc_event` VALUES (31876, 0x00, 10, 0x00800000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);

-- (31877) Judgements of the Wise (Rank 2)
DELETE FROM `spell_proc_event` WHERE `entry` IN (31877);
INSERT INTO `spell_proc_event` VALUES (31877, 0x00, 10, 0x00800000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);

-- (31878) Judgements of the Wise (Rank 3)
DELETE FROM `spell_proc_event` WHERE `entry` IN (31878);
INSERT INTO `spell_proc_event` VALUES (31878, 0x00, 10, 0x00800000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);

