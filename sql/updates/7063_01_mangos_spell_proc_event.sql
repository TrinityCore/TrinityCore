ALTER TABLE db_version CHANGE COLUMN required_7061_01_mangos_spell_proc_event required_7063_01_mangos_spell_proc_event bit;

-- (51474) Astral Shift (Rank 1)
DELETE FROM `spell_proc_event` WHERE `entry` IN (51474);
INSERT INTO `spell_proc_event` VALUES (51474, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010000, 0.000000, 0.000000, 0);

-- (51478) Astral Shift (Rank 2)
DELETE FROM `spell_proc_event` WHERE `entry` IN (51478);
INSERT INTO `spell_proc_event` VALUES (51478, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010000, 0.000000, 0.000000, 0);

-- (53601) Sacred Shield (Rank 1)
DELETE FROM `spell_proc_event` WHERE `entry` IN (53601);
INSERT INTO `spell_proc_event` VALUES (53601, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 6);