/* cs_pet.cpp */

SET @id = 479;

-- Add new permissions
DELETE FROM `rbac_permissions` WHERE `id` BETWEEN @id AND @id+3;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(@id+0 , 'pet'),
(@id+1 , 'pet create'),
(@id+2 , 'pet learn'),
(@id+3 , 'pet unlearn');

-- Add permissions to "corresponding Commands Role"
DELETE FROM `rbac_role_permissions` WHERE `permissionId` BETWEEN @id AND @id+3;
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES
(3, @id+0),
(3, @id+1),
(3, @id+2),
(3, @id+3);
