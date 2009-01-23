ALTER TABLE db_version CHANGE COLUMN required_7075_02_mangos_spell_learn_spell required_7078_01_mangos_spell_proc_event bit;

-- (31871) Divine Purpose (Rank 1)
DELETE FROM `spell_proc_event` WHERE `entry` IN (31871);
INSERT INTO `spell_proc_event` VALUES (31871, 0x00, 10, 0x00000010, 0x00000000, 0x00000000, 0x00004000, 0x00000000, 0.000000, 0.000000, 0);

-- (31872) Divine Purpose (Rank 2)
DELETE FROM `spell_proc_event` WHERE `entry` IN (31872);
INSERT INTO `spell_proc_event` VALUES (31872, 0x00, 10, 0x00000010, 0x00000000, 0x00000000, 0x00004000, 0x00000000, 0.000000, 0.000000, 0);

-- (44394) Incanter's Absorption (Rank 1)
DELETE FROM `spell_proc_event` WHERE `entry` IN (44394);
INSERT INTO `spell_proc_event` VALUES (44394, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000400, 0.000000, 0.000000, 0);

-- (44395) Incanter's Absorption (Rank 2)
DELETE FROM `spell_proc_event` WHERE `entry` IN (44395);
INSERT INTO `spell_proc_event` VALUES (44395, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000400, 0.000000, 0.000000, 0);

-- (44396) Incanter's Absorption (Rank 3)
DELETE FROM `spell_proc_event` WHERE `entry` IN (44396);
INSERT INTO `spell_proc_event` VALUES (44396, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000400, 0.000000, 0.000000, 0);


