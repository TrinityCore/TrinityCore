DELETE FROM `mangos_string` WHERE `entry` in (101,152,160,168,288,290,423,524,539,542);
INSERT INTO `mangos_string` VALUES
(101,'Map: %u (%s) Zone: %u (%s) Area: %u (%s)\nX: %f Y: %f Z: %f Orientation: %f\ngrid[%u,%u]cell[%u,%u] InstanceID: %u\n ZoneX: %f ZoneY: %f\nGroundZ: %f FloorZ: %f Have height data (Map: %u VMap: %u)',NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(152,'USER1: %i, ADD: %i, DIF: %i\n',NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(160,'USER2: %i, ADD: %i, RESULT: %i\n',NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(168,'Locations found are:\n',NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(288,'Tickets count: %i show new tickets: %s\n',NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(290,'Ticket of %s (Category: %i):\n%s\n',NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(423,'IP: %s\nBan Date: %s\nUnban Date: %s\nRemaining: %s\nReason: %s\nSet by: %s',NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(524,'Selected object:\n%s\nGUID: %u ID: %u\nX: %f Y: %f Z: %f MapId: %u\nOrientation: %f',NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(539,'Player selected NPC\nGUID: %u.\nFaction: %u.\nnpcFlags: %u.\nEntry: %u.\nDisplayID: %u (Native: %u).',NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(542,'Field Flags: %u.\nDynamic Flags: %u.\nFaction Template: %u.',NULL,NULL,NULL,NULL,NULL,NULL,NULL);
