ALTER TABLE db_version CHANGE COLUMN required_7565_01_mangos_mangos_string required_7568_01_mangos_spell_proc_event bit;

-- (53569) Infusion of Light (Rank 1)
DELETE FROM `spell_proc_event` WHERE `entry` IN (53569);
INSERT INTO `spell_proc_event` VALUES (53569, 0x00, 10, 0x00200000, 0x00010000, 0x00000000, 0x00000000, 0x00000002, 0.000000, 0.000000, 0);

-- (53576) Infusion of Light (Rank 2)
DELETE FROM `spell_proc_event` WHERE `entry` IN (53576);
INSERT INTO `spell_proc_event` VALUES (53576, 0x00, 10, 0x00200000, 0x00010000, 0x00000000, 0x00000000, 0x00000002, 0.000000, 0.000000, 0);

-- (54149) Infusion of Light (Rank 2)
DELETE FROM `spell_proc_event` WHERE `entry` IN (54149);
INSERT INTO `spell_proc_event` VALUES (54149, 0x00, 10, 0x00200000, 0x00010000, 0x00000000, 0x00000000, 0x00000002, 0.000000, 0.000000, 0);

-- (55776) Swordguard Embroidery ()
DELETE FROM `spell_proc_event` WHERE `entry` IN (55776);
INSERT INTO `spell_proc_event` VALUES (55776, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 45);

-- (55768) Darkglow Embroidery ()
DELETE FROM `spell_proc_event` WHERE `entry` IN (55768);
INSERT INTO `spell_proc_event` VALUES (55768, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 45);

-- (55640) Lightweave Embroidery ()
DELETE FROM `spell_proc_event` WHERE `entry` IN (55640);
INSERT INTO `spell_proc_event` VALUES (55640, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 45);

-- (55380) Skyflare Swiftness ()
DELETE FROM `spell_proc_event` WHERE `entry` IN (55380);
INSERT INTO `spell_proc_event` VALUES (55380, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 45);

-- (56355) Titanium Shield Spike ()
DELETE FROM `spell_proc_event` WHERE `entry` IN (56355);
INSERT INTO `spell_proc_event` VALUES (56355, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000040, 0.000000, 0.000000, 0);

-- (61345) Natures Grace ()
DELETE FROM `spell_proc_event` WHERE `entry` IN (61345);
INSERT INTO `spell_proc_event` VALUES (61345, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002, 0.000000, 0.000000, 0);

-- (61346) Natures Grace ()
DELETE FROM `spell_proc_event` WHERE `entry` IN (61346);
INSERT INTO `spell_proc_event` VALUES (61346, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002, 0.000000, 0.000000, 0);

-- (61356) Invigorating Earthsiege Diamond Passive ()
DELETE FROM `spell_proc_event` WHERE `entry` IN (61356);
INSERT INTO `spell_proc_event` VALUES (61356, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002, 0.000000, 0.000000, 0);

-- (24905) Moonkin Form (Passive) (Passive)
DELETE FROM `spell_proc_event` WHERE `entry` IN (24905);
INSERT INTO `spell_proc_event` VALUES (24905, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002, 15.000000, 0.000000, 0);