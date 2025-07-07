DELETE FROM `rbac_permissions` WHERE `id`=841;
DELETE FROM `rbac_linked_permissions` WHERE `id`=196 AND `linkedId` IN (460,880);
INSERT INTO `rbac_linked_permissions` (`id`,`linkedId`) VALUES
(196,460),
(196,880);
