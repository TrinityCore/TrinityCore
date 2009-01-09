ALTER TABLE db_version CHANGE COLUMN required_7051_01_mangos_spell_proc_event required_7052_01_mangos_spell_proc_event bit;

-- (47549) Improved Holy Concentration (Rank 1)
DELETE FROM `spell_proc_event` WHERE `entry` IN (47549);
INSERT INTO `spell_proc_event` VALUES (47549, 0x00, 6, 0x00000000, 0x00020000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);

-- (47551) Improved Holy Concentration (Rank 2)
DELETE FROM `spell_proc_event` WHERE `entry` IN (47551);
INSERT INTO `spell_proc_event` VALUES (47551, 0x00, 6, 0x00000000, 0x00020000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);

-- (47552) Improved Holy Concentration (Rank 3)
DELETE FROM `spell_proc_event` WHERE `entry` IN (47552);
INSERT INTO `spell_proc_event` VALUES (47552, 0x00, 6, 0x00000000, 0x00020000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);