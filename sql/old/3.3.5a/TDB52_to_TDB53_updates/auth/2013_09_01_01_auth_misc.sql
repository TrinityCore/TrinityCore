ALTER TABLE `account`
	ADD COLUMN `reg_mail` VARCHAR(255) NOT NULL DEFAULT '' AFTER `s`;

UPDATE `account` SET reg_mail = email;

DELETE FROM `rbac_permissions` WHERE `id` = 49;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES (49, 'Forces to enter the email for confirmation on password change');

DELETE FROM `rbac_roles` WHERE `id` = 40;
INSERT INTO `rbac_roles` (`id`, `name`) VALUES (40, 'Forces to enter the email for confirmation on password change');

DELETE FROM `rbac_role_permissions` WHERE `roleId` = 40 AND `permissionId` = 49;
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES (40, 49);

DELETE FROM `rbac_group_roles` WHERE `groupId` = 1 AND `roleId` = 40;
INSERT INTO `rbac_group_roles` (`groupId`, `roleId`) VALUES (1, 40);

DELETE FROM `rbac_group_roles` WHERE `groupId` = 2 AND `roleId` = 40;
INSERT INTO `rbac_group_roles` (`groupId`, `roleId`) VALUES (2, 40);

DELETE FROM `rbac_group_roles` WHERE `groupId` = 3 AND `roleId` = 40;
INSERT INTO `rbac_group_roles` (`groupId`, `roleId`) VALUES (3, 40);

DELETE FROM `rbac_group_roles` WHERE `groupId` = 4 AND `roleId` = 40;
INSERT INTO `rbac_group_roles` (`groupId`, `roleId`) VALUES (4, 40);

DELETE FROM `rbac_permissions` WHERE `id` = 50;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES (50, 'Allow user to check his own email with .account');

DELETE FROM `rbac_roles` WHERE `id` = 41;
INSERT INTO `rbac_roles` (`id`, `name`) VALUES (41, 'Allow user to check his own email with .account');

DELETE FROM `rbac_role_permissions` WHERE `roleId` = 41 AND `permissionId` = 50;
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES (41, 50);

