/*ALTER TABLE db_version CHANGE COLUMN required_7493_01_mangos_command required_7495_01_mangos_mangos_string bit;*/

DELETE FROM `trinity_string` WHERE `entry` IN (276,277,524);
INSERT INTO `trinity_string` VALUES
(276,'Game Object |cffffffff|Hgameobject:%d|h[%s]|h|r (GUID: %u) turned',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(277,'Game Object |cffffffff|Hgameobject:%d|h[%s]|h|r (GUID: %u) moved',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(524,'Selected object:\n|cffffffff|Hgameobject:%d|h[%s]|h|r GUID: %u ID: %u\nX: %f Y: %f Z: %f MapId: %u\nOrientation: %f',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
