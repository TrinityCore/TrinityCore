DELETE FROM `spell_proc_event` WHERE `entry` IN (45444,46364);
INSERT INTO `spell_proc_event` VALUES
(45444,0,0,0,0,0x0000000000000000,0x00100402,0),
(46364,0,0,0,0,0x0000000000000000,0x00100402,0);

DELETE FROM `spell_proc_event` WHERE `entry` IN (34827);
INSERT INTO `spell_proc_event` VALUES
(34827,0,0,0,0,0x0000000000000000,0x00100402,0);

-- Creature's Earth Shield proc on melee attacks
DELETE FROM `spell_proc_event` WHERE `entry` IN (32734);
INSERT INTO `spell_proc_event` VALUES
(32734,0,0,0,0,0x0000000000000000,0x00000002,0);

