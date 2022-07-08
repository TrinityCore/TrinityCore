DELETE FROM `rbac_permissions` WHERE `id` IN (8, 9);
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(8, "Cannot earn achievements"),
(9, "Cannot earn realm first achievements");

INSERT INTO `rbac_linked_permissions` (`id`, `linkedId`) VALUES
(194, 9);
