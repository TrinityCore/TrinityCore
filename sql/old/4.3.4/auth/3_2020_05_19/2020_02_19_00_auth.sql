DELETE FROM `rbac_permissions` WHERE `id`=830;
INSERT INTO `rbac_permissions` (`id`,`name`) VALUES
(830,'Command: bnetaccount listgameaccounts');

DELETE FROM `rbac_linked_permissions` WHERE `id`=196 AND `linkedId`=830;
INSERT INTO `rbac_linked_permissions` (`id`, `linkedId`) VALUES
(196, 830);
