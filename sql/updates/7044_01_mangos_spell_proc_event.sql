ALTER TABLE db_version CHANGE COLUMN required_7040_01_mangos_achievement_reward required_7044_01_mangos_spell_proc_event bit;

-- (48110) Prayer of Mending (Rank 2)
DELETE FROM `spell_proc_event` WHERE `entry` IN (48110);
INSERT INTO `spell_proc_event` VALUES (48110, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x000A02A8, 0x00000000, 0.000000, 0.000000, 0);

-- (48112) Prayer of Mending (Rank 2)
DELETE FROM `spell_proc_event` WHERE `entry` IN (48112);
INSERT INTO `spell_proc_event` VALUES (48112, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x000A02A8, 0x00000000, 0.000000, 0.000000, 0);

-- (48111) Prayer of Mending (Rank 3)
DELETE FROM `spell_proc_event` WHERE `entry` IN (48111);
INSERT INTO `spell_proc_event` VALUES (48111, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x000A02A8, 0x00000000, 0.000000, 0.000000, 0);

-- (48113) Prayer of Mending (Rank 3)
DELETE FROM `spell_proc_event` WHERE `entry` IN (48113);
INSERT INTO `spell_proc_event` VALUES (48113, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x000A02A8, 0x00000000, 0.000000, 0.000000, 0);
