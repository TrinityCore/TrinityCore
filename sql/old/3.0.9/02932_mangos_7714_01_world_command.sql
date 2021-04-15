/*ALTER TABLE db_version CHANGE COLUMN required_7706_01_mangos_command required_7714_01_mangos_command bit;*/

DELETE FROM `command` WHERE `name` IN ('character level');
INSERT INTO `command` VALUES
('character level',3,'Syntax: .character level [$playername] [#level]\r\n\r\nSet the level of character with $playername (or the selected if not name provided) by #numberoflevels Or +1 if no #numberoflevels provided). If #numberoflevels is omitted, the level will be increase by 1. If #numberoflevels is 0, the same level will be restarted. If no character is selected and name not provided, increase your level. Command can be used for offline character. All stats and dependent values recalculated. At level decrease talents can be reset if need. Also at level decrease equipped items with greater level requirement can be lost.');
