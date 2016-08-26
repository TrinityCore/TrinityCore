-- Add required permissions
DELETE FROM `rbac_permissions` WHERE `id`=842;
INSERT INTO `rbac_permissions` (`id`,`name`) VALUES (842,"Command: .character masquerade");

DELETE FROM `rbac_linked_permissions` WHERE `linkedId`=842;
INSERT INTO `rbac_linked_permissions` (`id`,`linkedId`) VALUES (196,842);
