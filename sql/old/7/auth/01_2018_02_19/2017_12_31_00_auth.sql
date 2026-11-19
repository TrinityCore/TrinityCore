DELETE FROM `rbac_permissions` WHERE `id`=869;
INSERT INTO `rbac_permissions` (`id`,`name`) VALUES
(869,'Command: debug send playerchoice');

DELETE FROM `rbac_linked_permissions` WHERE `linkedId`=869;
INSERT INTO `rbac_linked_permissions` (`id`,`linkedId`) VALUES
(196,869);
