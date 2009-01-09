ALTER TABLE db_version CHANGE COLUMN required_7053_01_mangos_spell_proc_event required_7056_01_mangos_spell_proc_event bit;

-- (20210) Illumination (Rank 1)
DELETE FROM `spell_proc_event` WHERE `entry` IN (20210);
INSERT INTO `spell_proc_event` VALUES (20210, 0x00, 10, 0xC0000000, 0x00010000, 0x00000000, 0x00000000, 0x00000002, 0.000000, 0.000000, 0);

-- (20212) Illumination (Rank 2)
DELETE FROM `spell_proc_event` WHERE `entry` IN (20212);
INSERT INTO `spell_proc_event` VALUES (20212, 0x00, 10, 0xC0000000, 0x00010000, 0x00000000, 0x00000000, 0x00000002, 0.000000, 0.000000, 0);

-- (20213) Illumination (Rank 3)
DELETE FROM `spell_proc_event` WHERE `entry` IN (20213);
INSERT INTO `spell_proc_event` VALUES (20213, 0x00, 10, 0xC0000000, 0x00010000, 0x00000000, 0x00000000, 0x00000002, 0.000000, 0.000000, 0);

-- (20214) Illumination (Rank 4)
DELETE FROM `spell_proc_event` WHERE `entry` IN (20214);
INSERT INTO `spell_proc_event` VALUES (20214, 0x00, 10, 0xC0000000, 0x00010000, 0x00000000, 0x00000000, 0x00000002, 0.000000, 0.000000, 0);

-- (20215) Illumination (Rank 5)
DELETE FROM `spell_proc_event` WHERE `entry` IN (20215);
INSERT INTO `spell_proc_event` VALUES (20215, 0x00, 10, 0xC0000000, 0x00010000, 0x00000000, 0x00000000, 0x00000002, 0.000000, 0.000000, 0);

-- (33953) Essence of Life ()
DELETE FROM `spell_proc_event` WHERE `entry` IN (33953);
INSERT INTO `spell_proc_event` VALUES (33953, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00004000, 0x00000000, 0.000000, 0.000000, 45);