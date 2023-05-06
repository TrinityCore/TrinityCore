--
UPDATE `graveyard_zone` SET `Faction` = 67 WHERE `ID` = 97 AND `GhostZone` = 209;
UPDATE `graveyard_zone` SET `Faction` = 469 WHERE `ID` = 149 AND `GhostZone` = 209;


DELETE FROM `graveyard_zone` WHERE `ID`= 1256 AND `GhostZone` = 209;
INSERT INTO `graveyard_zone` VALUES
(1256, 209, 0, 'Silverpine Forest, South GY - Silverpine Forest');

UPDATE `command` SET `help` = 'Syntax: .neargrave [alliance horde]\r\n\r\nFind nearest graveyard linked to zone (or only nearest from accepts alliance or horde faction ghosts).' WHERE `name` = 'neargrave';
