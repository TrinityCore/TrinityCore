INSERT INTO `rbac_permissions` (`id`, `name`) VALUES (1398, 'Command: gobject set scale');
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES (1589, 'Command: npc set scale');

INSERT INTO `rbac_linked_permissions` (`id`, `linkedId`) VALUES (197, 1398);
INSERT INTO `rbac_linked_permissions` (`id`, `linkedId`) VALUES (197, 1589);
