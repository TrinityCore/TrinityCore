--
DELETE FROM `rbac_permissions` WHERE `id` IN (884, 885);
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(884, "Command: bg start"),
(885, "Command: bg stop");

DELETE FROM `rbac_linked_permissions` WHERE `linkedId` IN (884, 885);
INSERT INTO `rbac_linked_permissions` (`id`, `linkedId`) VALUES
(197, 884),
(197, 885);
