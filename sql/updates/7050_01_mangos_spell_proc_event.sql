ALTER TABLE db_version CHANGE COLUMN required_7047_03_mangos_playercreateinfo_spell required_7050_01_mangos_spell_proc_event bit;

-- (34753) Holy Concentration (Rank 1)
DELETE FROM `spell_proc_event` WHERE `entry` IN (34753);
INSERT INTO `spell_proc_event` VALUES (34753, 0x00, 6, 0x00001800, 0x00000004, 0x00000000, 0x00000000, 0x00000002, 0.000000, 0.000000, 0);

-- (34859) Holy Concentration (Rank 2)
DELETE FROM `spell_proc_event` WHERE `entry` IN (34859);
INSERT INTO `spell_proc_event` VALUES (34859, 0x00, 6, 0x00001800, 0x00000004, 0x00000000, 0x00000000, 0x00000002, 0.000000, 0.000000, 0);

-- (34860) Holy Concentration (Rank 3)
DELETE FROM `spell_proc_event` WHERE `entry` IN (34860);
INSERT INTO `spell_proc_event` VALUES (34860, 0x00, 6, 0x00001800, 0x00000004, 0x00000000, 0x00000000, 0x00000002, 0.000000, 0.000000, 0);