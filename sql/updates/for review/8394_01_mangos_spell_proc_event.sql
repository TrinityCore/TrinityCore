ALTER TABLE db_version CHANGE COLUMN required_8392_02_mangos_spell_chain required_8394_01_mangos_spell_proc_event bit;

DELETE FROM `spell_proc_event` WHERE `entry` IN (54646); 
INSERT INTO `spell_proc_event` VALUES 
(54646, 0x00000000,  0, 0x00000000, 0x00000000, 0x00000000, 0x00015400, 0x00000002, 0.000000, 0.000000, 0); 
