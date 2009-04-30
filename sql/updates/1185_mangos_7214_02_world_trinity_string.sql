/*ALTER TABLE db_version CHANGE COLUMN required_7214_01_mangos_command required_7214_02_mangos_mangos_string bit;*/

DELETE FROM `trinity_string` WHERE entry = 101;
INSERT INTO `trinity_string` VALUES
(101,'Map: %u (%s) Zone: %u (%s) Area: %u (%s) Phase: %u\nX: %f Y: %f Z: %f Orientation: %f\ngrid[%u,%u]cell[%u,%u] InstanceID: %u\n ZoneX: %f ZoneY: %f\nGroundZ: %f FloorZ: %f Have height data (Map: %u VMap: %u)',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);