ALTER TABLE db_version CHANGE COLUMN required_7026_01_mangos_battleground_template required_7031_01_mangos_spell_proc_event bit;

-- (44445) Hot Streak (Rank 1)
DELETE FROM `spell_proc_event` WHERE `entry` IN (44445);
INSERT INTO `spell_proc_event` VALUES (44445, 0x00, 3, 0x0000100000000013, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);

-- (44446) Hot Streak (Rank 2)
DELETE FROM `spell_proc_event` WHERE `entry` IN (44446);
INSERT INTO `spell_proc_event` VALUES (44446, 0x00, 3, 0x0000100000000013, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);

-- (44448) Hot Streak (Rank 3)
DELETE FROM `spell_proc_event` WHERE `entry` IN (44448);
INSERT INTO `spell_proc_event` VALUES (44448, 0x00, 3, 0x0000100000000013, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);

-- (54939) Glyph of Divinity ()
DELETE FROM `spell_proc_event` WHERE `entry` IN (54939);
INSERT INTO `spell_proc_event` VALUES (54939, 0x00, 10, 0x0000000000008000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);

-- (54936) Glyph of Flash of Light ()
DELETE FROM `spell_proc_event` WHERE `entry` IN (54936);
INSERT INTO `spell_proc_event` VALUES (54936, 0x00, 10, 0x0000000040000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);

-- (54937) Glyph of Holy Light ()
DELETE FROM `spell_proc_event` WHERE `entry` IN (54937);
INSERT INTO `spell_proc_event` VALUES (54937, 0x00, 10, 0x0000000080000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);