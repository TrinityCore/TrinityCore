ALTER TABLE db_version CHANGE COLUMN required_7044_01_mangos_spell_proc_event required_7047_02_mangos_playercreateinfo_action bit;

DELETE FROM `playercreateinfo_action` WHERE `action` IN ('28880', 59542, 59543, 59544, 59545, 59547, 59548);
INSERT INTO `playercreateinfo_action` VALUES
(11,1,74,28880,0,0),
(11,2,3,59542,0,0),
(11,3,3,59543,0,0),
(11,5,3,59544,0,0),
(11,6,6,59545,0,0),
(11,7,3,59547,0,0),
(11,8,3,59548,0,0);