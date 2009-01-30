ALTER TABLE db_version CHANGE COLUMN required_7199_01_mangos_spell_bonus_data required_7199_02_mangos_spell_proc_event bit;

-- (51479) Astral Shift (Rank 3)
DELETE FROM `spell_proc_event` WHERE `entry` IN (51479);
INSERT INTO `spell_proc_event` VALUES (51479, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010000, 0.000000, 0.000000, 0);

-- (61846) Aspect of the Dragonhawk (Rank 1)
DELETE FROM `spell_proc_event` WHERE `entry` IN (61846);
INSERT INTO `spell_proc_event` VALUES (61846, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000010, 0.000000, 0.000000, 0);

-- (61847) Aspect of the Dragonhawk (Rank 2)
DELETE FROM `spell_proc_event` WHERE `entry` IN (61847);
INSERT INTO `spell_proc_event` VALUES (61847, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000010, 0.000000, 0.000000, 0);

-- (13163) Aspect of the Monkey ()
DELETE FROM `spell_proc_event` WHERE `entry` IN (13163);
INSERT INTO `spell_proc_event` VALUES (13163, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000010, 0.000000, 0.000000, 0);

-- (51940) Earthliving Weapon (Passive) (Rank 1)
DELETE FROM `spell_proc_event` WHERE `entry` IN (51940);
INSERT INTO `spell_proc_event` VALUES (51940, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 20.000000, 0);

-- (51989) Earthliving Weapon (Passive) (Rank 2)
DELETE FROM `spell_proc_event` WHERE `entry` IN (51989);
INSERT INTO `spell_proc_event` VALUES (51989, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 20.000000, 0);

-- (52004) Earthliving Weapon (Passive) (Rank 3)
DELETE FROM `spell_proc_event` WHERE `entry` IN (52004);
INSERT INTO `spell_proc_event` VALUES (52004, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 20.000000, 0);

-- (52005) Earthliving Weapon (Passive) (Rank 4)
DELETE FROM `spell_proc_event` WHERE `entry` IN (52005);
INSERT INTO `spell_proc_event` VALUES (52005, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 20.000000, 0);

-- (52007) Earthliving Weapon (Passive) (Rank 5)
DELETE FROM `spell_proc_event` WHERE `entry` IN (52007);
INSERT INTO `spell_proc_event` VALUES (52007, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 20.000000, 0);

-- (52008) Earthliving Weapon (Passive) (Rank 6)
DELETE FROM `spell_proc_event` WHERE `entry` IN (52008);
INSERT INTO `spell_proc_event` VALUES (52008, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 20.000000, 0);

-- (44442) Firestarter (Rank 1)
DELETE FROM `spell_proc_event` WHERE `entry` IN (44442);
INSERT INTO `spell_proc_event` VALUES (44442, 0x00, 3, 0x00800000, 0x00000040, 0x00000000, 0x00000000, 0x00010000, 0.000000, 0.000000, 1);

-- (44443) Firestarter (Rank 2)
DELETE FROM `spell_proc_event` WHERE `entry` IN (44443);
INSERT INTO `spell_proc_event` VALUES (44443, 0x00, 3, 0x00800000, 0x00000040, 0x00000000, 0x00000000, 0x00010000, 0.000000, 0.000000, 1);