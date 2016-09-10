DELETE FROM `rbac_permissions` WHERE `id` BETWEEN 842 AND 846;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(842, 'Command: npc spawngroup'),
(843, 'Command: npc despawngroup'),
(844, 'Command: gobject spawngroup'),
(845, 'Command: gobject despawngroup'),
(846, 'Command: list respawns');

DELETE FROM `rbac_linked_permissions` WHERE `id` = 197 AND `linkedId` BETWEEN 842 AND 846;
INSERT INTO `rbac_linked_permissions` (`id`, `linkedId`) VALUES
(197, 842),
(197, 843),
(197, 844),
(197, 845),
(197, 846);
