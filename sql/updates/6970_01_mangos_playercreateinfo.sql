ALTER TABLE db_version CHANGE COLUMN required_6961_01_mangos_command required_6970_01_mangos_playercreateinfo bit;

DELETE FROM `playercreateinfo` WHERE `race`=7 AND `class` IN (4,8,9);
INSERT INTO `playercreateinfo` VALUES
(7,4,0,1,-6240,331,383),
(7,8,0,1,-6240,331,383),
(7,9,0,1,-6240,331,383);
