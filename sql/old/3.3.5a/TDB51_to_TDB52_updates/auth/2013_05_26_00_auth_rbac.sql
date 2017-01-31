DELETE FROM `rbac_permissions` WHERE `id` = 48;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES (48, 'Enable IP, Last Login and EMail output in pinfo');

DELETE FROM `rbac_roles` WHERE `id` = 39;
INSERT INTO `rbac_roles` (`id`, `name`) VALUES (39, 'Enable IP, Last Login and EMail output in pinfo');

DELETE FROM `rbac_role_permissions` WHERE `roleId` = 39 AND `permissionId` = 48;
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES (39, 48);

DELETE FROM `rbac_group_roles` WHERE `groupId` = 3 AND `roleId` = 39;
INSERT INTO `rbac_group_roles` (`groupId`, `roleId`) VALUES (3, 39);

DELETE FROM `rbac_group_roles` WHERE `groupId` = 4 AND `roleId` = 39;
INSERT INTO `rbac_group_roles` (`groupId`, `roleId`) VALUES (4, 39);
