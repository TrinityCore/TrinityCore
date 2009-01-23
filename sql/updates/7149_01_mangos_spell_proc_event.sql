ALTER TABLE db_version CHANGE COLUMN required_7147_01_mangos_creature_template required_7149_01_mangos_spell_proc_event bit;

-- (53501) Sheath of Light (Rank 1)
DELETE FROM `spell_proc_event` WHERE `entry` IN (53501);
INSERT INTO `spell_proc_event` VALUES (53501, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002, 0.000000, 0.000000, 0);

-- (53502) Sheath of Light (Rank 2)
DELETE FROM `spell_proc_event` WHERE `entry` IN (53502);
INSERT INTO `spell_proc_event` VALUES (53502, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002, 0.000000, 0.000000, 0);

-- (53503) Sheath of Light (Rank 3)
DELETE FROM `spell_proc_event` WHERE `entry` IN (53503);
INSERT INTO `spell_proc_event` VALUES (53503, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002, 0.000000, 0.000000, 0);

-- (53228) Rapid Recuperation (Rank 1)
DELETE FROM `spell_proc_event` WHERE `entry` IN (53228);
INSERT INTO `spell_proc_event` VALUES (53228, 0x00, 9, 0x00000020, 0x01000000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);

-- (53232) Rapid Recuperation (Rank 2)
DELETE FROM `spell_proc_event` WHERE `entry` IN (53232);
INSERT INTO `spell_proc_event` VALUES (53232, 0x00, 9, 0x00000020, 0x01000000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);
