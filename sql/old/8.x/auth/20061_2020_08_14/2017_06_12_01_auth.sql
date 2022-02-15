-- 
DELETE FROM `rbac_permissions` WHERE `id` BETWEEN 856 AND 860;
INSERT INTO `rbac_permissions` (`id`,`name`) VALUES
(856, 'Command: npc spawngroup'),
(857, 'Command: npc despawngroup'),
(858, 'Command: gobject spawngroup'),
(859, 'Command: gobject despawngroup'),
(860, 'Command: list respawns');

DELETE FROM `rbac_linked_permissions` WHERE `linkedId` BETWEEN 856 AND 860;
INSERT INTO `rbac_linked_permissions` (`id`,`linkedId`) VALUES
(197,856),(197,857),(197,858),(197,859),(197,860);
