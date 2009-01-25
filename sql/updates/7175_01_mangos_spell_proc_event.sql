ALTER TABLE db_version CHANGE COLUMN required_7168_01_mangos_command required_7175_01_mangos_spell_proc_event bit;

-- (56333) T.N.T. (Rank 1)
DELETE FROM `spell_proc_event` WHERE `entry` IN (56333);
INSERT INTO `spell_proc_event` VALUES (56333, 0x00, 9, 0x00000004, 0x00000000, 0x00000200, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);

-- (56336) T.N.T. (Rank 2)
DELETE FROM `spell_proc_event` WHERE `entry` IN (56336);
INSERT INTO `spell_proc_event` VALUES (56336, 0x00, 9, 0x00000004, 0x00000000, 0x00000200, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);

-- (56337) T.N.T. (Rank 3)
DELETE FROM `spell_proc_event` WHERE `entry` IN (56337);
INSERT INTO `spell_proc_event` VALUES (56337, 0x00, 9, 0x00000004, 0x00000000, 0x00000200, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);