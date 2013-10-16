SET @id = 400;

-- Add new permissions
DELETE FROM `rbac_permissions` WHERE `id`=@id;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(@id, 'debug transport');

-- Add permissions to "corresponding Commands Role"
DELETE FROM `rbac_role_permissions` WHERE `permissionId`=@id;
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES
(3, @id);
