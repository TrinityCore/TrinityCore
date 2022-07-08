DELETE FROM `rbac_permissions` WHERE `id` IN (875, 876, 877);
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(875, "Command: lookup map id"),
(876, "Command: lookup item id"),
(877, "Command: lookup quest id");

INSERT INTO `rbac_linked_permissions` (`id`, `linkedId`) VALUES
(196, 875),
(196, 876),
(196, 877);
