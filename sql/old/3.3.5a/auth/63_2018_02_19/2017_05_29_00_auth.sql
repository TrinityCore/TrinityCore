DELETE FROM `rbac_permissions` WHERE `id` = 855;
INSERT INTO `rbac_permissions` (`id`,`name`) VALUES
(855, 'Command: debug play music');

DELETE FROM `rbac_linked_permissions` WHERE `linkedId` = 855;
INSERT INTO `rbac_linked_permissions` (`id`,`linkedId`) VALUES
(198, 855);
