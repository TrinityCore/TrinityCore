ALTER TABLE db_version CHANGE COLUMN required_7056_01_mangos_spell_proc_event required_7060_01_mangos_spell_proc_event bit;

-- (51556) Ancestral Awakening (Rank 1)
DELETE FROM `spell_proc_event` WHERE `entry` IN (51556);
INSERT INTO `spell_proc_event` VALUES (51556, 0x00, 11, 0x000000C0, 0x00000000, 0x00000010, 0x00000000, 0x00000002, 0.000000, 0.000000, 0);

-- (51557) Ancestral Awakening (Rank 2)
DELETE FROM `spell_proc_event` WHERE `entry` IN (51557);
INSERT INTO `spell_proc_event` VALUES (51557, 0x00, 11, 0x000000C0, 0x00000000, 0x00000010, 0x00000000, 0x00000002, 0.000000, 0.000000, 0);

-- (51558) Ancestral Awakening (Rank 3)
DELETE FROM `spell_proc_event` WHERE `entry` IN (51558);
INSERT INTO `spell_proc_event` VALUES (51558, 0x00, 11, 0x000000C0, 0x00000000, 0x00000010, 0x00000000, 0x00000002, 0.000000, 0.000000, 0);

-- (47555) Serendipity (Rank 1)
DELETE FROM `spell_proc_event` WHERE `entry` IN (47555);
INSERT INTO `spell_proc_event` VALUES (47555, 0x00, 6, 0x00001800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);

-- (47556) Serendipity (Rank 2)
DELETE FROM `spell_proc_event` WHERE `entry` IN (47556);
INSERT INTO `spell_proc_event` VALUES (47556, 0x00, 6, 0x00001800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);

-- (47557) Serendipity (Rank 3)
DELETE FROM `spell_proc_event` WHERE `entry` IN (47557);
INSERT INTO `spell_proc_event` VALUES (47557, 0x00, 6, 0x00001800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);

-- (32409) Shadow Word: Death ()
DELETE FROM `spell_proc_event` WHERE `entry` IN (32409);
INSERT INTO `spell_proc_event` VALUES (32409, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);


