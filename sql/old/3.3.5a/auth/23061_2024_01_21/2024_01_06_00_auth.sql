--
DELETE FROM `rbac_permissions` WHERE `id` = 52;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES (52, "No battleground deserter debuff");

DELETE FROM `rbac_linked_permissions` WHERE `linkedId` = 52;
INSERT INTO `rbac_linked_permissions` (`id`, `linkedId`) VALUES
(193, 52);
