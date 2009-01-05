ALTER TABLE db_version CHANGE COLUMN required_7031_01_mangos_spell_proc_event required_7033_01_mangos_spell_proc_event bit;

-- (48516) Eclipse (Rank 1)
DELETE FROM `spell_proc_event` WHERE `entry` IN (48516);
INSERT INTO `spell_proc_event` VALUES (48516, 0x00, 7, 0x0000000000000005, 0x00000000, 0x00000002, 0.000000, 0.000000, 30);

-- (48521) Eclipse (Rank 2)
DELETE FROM `spell_proc_event` WHERE `entry` IN (48521);
INSERT INTO `spell_proc_event` VALUES (48521, 0x00, 7, 0x0000000000000005, 0x00000000, 0x00000002, 0.000000, 0.000000, 30);

-- (48525) Eclipse (Rank 3)
DELETE FROM `spell_proc_event` WHERE `entry` IN (48525);
INSERT INTO `spell_proc_event` VALUES (48525, 0x00, 7, 0x0000000000000005, 0x00000000, 0x00000002, 0.000000, 0.000000, 30);

-- (48496) Living Seed (Rank 1)
DELETE FROM `spell_proc_event` WHERE `entry` IN (48496);
INSERT INTO `spell_proc_event` VALUES (48496, 0x00, 7, 0x0200000200000060, 0x00000000, 0x00000002, 0.000000, 0.000000, 0);

-- (48499) Living Seed (Rank 2)
DELETE FROM `spell_proc_event` WHERE `entry` IN (48499);
INSERT INTO `spell_proc_event` VALUES (48499, 0x00, 7, 0x0200000200000060, 0x00000000, 0x00000002, 0.000000, 0.000000, 0);

-- (48500) Living Seed (Rank 3)
DELETE FROM `spell_proc_event` WHERE `entry` IN (48500);
INSERT INTO `spell_proc_event` VALUES (48500, 0x00, 7, 0x0200000200000060, 0x00000000, 0x00000002, 0.000000, 0.000000, 0);

-- (53228) Rapid Recuperation (Rank 1)
DELETE FROM `spell_proc_event` WHERE `entry` IN (53228);
INSERT INTO `spell_proc_event` VALUES (53228, 0x00, 9, 0x0000000000000020, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);

-- (53232) Rapid Recuperation (Rank 2)
DELETE FROM `spell_proc_event` WHERE `entry` IN (53232);
INSERT INTO `spell_proc_event` VALUES (53232, 0x00, 9, 0x0000000000000020, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);

-- (55440) Glyph of Healing Wave ()
DELETE FROM `spell_proc_event` WHERE `entry` IN (55440);
INSERT INTO `spell_proc_event` VALUES (55440, 0x00, 11, 0x0000000000000040, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);

-- (52795) Borrowed Time (Rank 1)
DELETE FROM `spell_proc_event` WHERE `entry` IN (52795);
INSERT INTO `spell_proc_event` VALUES (52795, 0x00, 6, 0x0000000000000001, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);

-- (52797) Borrowed Time (Rank 2)
DELETE FROM `spell_proc_event` WHERE `entry` IN (52797);
INSERT INTO `spell_proc_event` VALUES (52797, 0x00, 6, 0x0000000000000001, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);

-- (52798) Borrowed Time (Rank 3)
DELETE FROM `spell_proc_event` WHERE `entry` IN (52798);
INSERT INTO `spell_proc_event` VALUES (52798, 0x00, 6, 0x0000000000000001, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);

-- (52799) Borrowed Time (Rank 4)
DELETE FROM `spell_proc_event` WHERE `entry` IN (52799);
INSERT INTO `spell_proc_event` VALUES (52799, 0x00, 6, 0x0000000000000001, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);

-- (52800) Borrowed Time (Rank 5)
DELETE FROM `spell_proc_event` WHERE `entry` IN (52800);
INSERT INTO `spell_proc_event` VALUES (52800, 0x00, 6, 0x0000000000000001, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);

-- (55677) Glyph of Dispel Magic ()
DELETE FROM `spell_proc_event` WHERE `entry` IN (55677);
INSERT INTO `spell_proc_event` VALUES (55677, 0x00, 6, 0x0000000100000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);

-- (55680) Glyph of Prayer of Healing ()
DELETE FROM `spell_proc_event` WHERE `entry` IN (55680);
INSERT INTO `spell_proc_event` VALUES (55680, 0x00, 6, 0x0000000000000200, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);

-- (47572) Psychic Horror (Rank 2)
DELETE FROM `spell_proc_event` WHERE `entry` IN (47572);
INSERT INTO `spell_proc_event` VALUES (47572, 0x00, 6, 0x0000000000010000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);

-- (48159) Vampiric Touch (Rank 4)
DELETE FROM `spell_proc_event` WHERE `entry` IN (48159);
INSERT INTO `spell_proc_event` VALUES (48159, 0x20, 6, 0x0000000000000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);

-- (48160) Vampiric Touch (Rank 5)
DELETE FROM `spell_proc_event` WHERE `entry` IN (48160);
INSERT INTO `spell_proc_event` VALUES (48160, 0x20, 6, 0x0000000000000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);

