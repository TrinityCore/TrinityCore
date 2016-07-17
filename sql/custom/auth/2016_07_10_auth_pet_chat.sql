DELETE FROM `rbac_permissions` WHERE `id`=1011;
DELETE FROM `rbac_linked_permissions` WHERE `linkedId`=1011;

INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(1011, 'Command: psay');
 
INSERT INTO `rbac_linked_permissions` (`id`,`linkedId`) VALUES
(195, 1011);