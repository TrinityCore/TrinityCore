ALTER TABLE db_version CHANGE COLUMN required_7050_01_mangos_spell_proc_event required_7051_01_mangos_spell_proc_event bit;

-- (44546) Brain Freeze (Rank 1)
DELETE FROM `spell_proc_event` WHERE `entry` IN (44546);
INSERT INTO `spell_proc_event` VALUES (44546, 0x00, 3, 0x020002A0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);

-- (44548) Brain Freeze (Rank 2)
DELETE FROM `spell_proc_event` WHERE `entry` IN (44548);
INSERT INTO `spell_proc_event` VALUES (44548, 0x00, 3, 0x020002A0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);

-- (44549) Brain Freeze (Rank 3)
DELETE FROM `spell_proc_event` WHERE `entry` IN (44549);
INSERT INTO `spell_proc_event` VALUES (44549, 0x00, 3, 0x020002A0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);

-- (44449) Burnout (Rank 1)
DELETE FROM `spell_proc_event` WHERE `entry` IN (44449);
INSERT INTO `spell_proc_event` VALUES (44449, 0x00, 3, 0x20E21277, 0x00019048, 0x00000000, 0x00000000, 0x00000002, 0.000000, 0.000000, 0);

-- (44469) Burnout (Rank 2)
DELETE FROM `spell_proc_event` WHERE `entry` IN (44469);
INSERT INTO `spell_proc_event` VALUES (44469, 0x00, 3, 0x20E21277, 0x00019048, 0x00000000, 0x00000000, 0x00000002, 0.000000, 0.000000, 0);

-- (44470) Burnout (Rank 3)
DELETE FROM `spell_proc_event` WHERE `entry` IN (44470);
INSERT INTO `spell_proc_event` VALUES (44470, 0x00, 3, 0x20E21277, 0x00019048, 0x00000000, 0x00000000, 0x00000002, 0.000000, 0.000000, 0);

-- (44471) Burnout (Rank 4)
DELETE FROM `spell_proc_event` WHERE `entry` IN (44471);
INSERT INTO `spell_proc_event` VALUES (44471, 0x00, 3, 0x20E21277, 0x00019048, 0x00000000, 0x00000000, 0x00000002, 0.000000, 0.000000, 0);

-- (44472) Burnout (Rank 5)
DELETE FROM `spell_proc_event` WHERE `entry` IN (44472);
INSERT INTO `spell_proc_event` VALUES (44472, 0x00, 3, 0x20E21277, 0x00019048, 0x00000000, 0x00000000, 0x00000002, 0.000000, 0.000000, 0);

-- (54747) Burning Determination (Rank 1)
DELETE FROM `spell_proc_event` WHERE `entry` IN (54747);
INSERT INTO `spell_proc_event` VALUES (54747, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010000, 0.000000, 0.000000, 0);

-- (54749) Burning Determination (Rank 2)
DELETE FROM `spell_proc_event` WHERE `entry` IN (54749);
INSERT INTO `spell_proc_event` VALUES (54749, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010000, 0.000000, 0.000000, 0);
