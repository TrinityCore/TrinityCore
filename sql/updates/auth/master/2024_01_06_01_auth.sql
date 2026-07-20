--
DELETE FROM `rbac_permissions` WHERE `id` = 53;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES (53, "Can be AFK on the battleground");

DELETE FROM `rbac_linked_permissions` WHERE `linkedId` = 53;
INSERT INTO `rbac_linked_permissions` (`id`, `linkedId`) VALUES
(193, 53);
