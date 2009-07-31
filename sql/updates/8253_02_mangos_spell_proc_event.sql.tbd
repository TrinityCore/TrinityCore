ALTER TABLE db_version CHANGE COLUMN required_8253_01_mangos_spell_chain required_8253_02_mangos_spell_proc_event bit;

/*Bandit's Insignia*/
DELETE FROM `spell_proc_event` WHERE entry IN (60442);
INSERT INTO spell_proc_event VALUES
(60442, 0x00000000,  0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 45);

/*Seal of wisdom*/
DELETE FROM `spell_proc_event` WHERE `entry` IN (20166); 
INSERT INTO `spell_proc_event` VALUES
(20166, 0x00000000,  0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,15.000000, 0.000000,  0); 

/*Shadow embrace*/
DELETE FROM `spell_proc_event` WHERE `entry` IN (32385); 
INSERT INTO `spell_proc_event` VALUES
(32385, 0x00000000,  5, 0x00000001, 0x00040000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000,  0); 

/*Maelstrom Weapon*/
DELETE FROM `spell_proc_event` WHERE `entry` IN (51528); 
INSERT INTO `spell_proc_event` VALUES
(51528, 0x00000000,  0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,12.500000, 0.000000, 0); 
