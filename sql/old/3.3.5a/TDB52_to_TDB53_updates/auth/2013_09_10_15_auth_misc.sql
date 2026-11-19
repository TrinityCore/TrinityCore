/* account email */
SET @amail = 263;

-- Add new permissions for account mail
DELETE FROM `rbac_permissions` WHERE `id` = @amail;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(@amail, 'account email');

-- Add permissions to "corresponding Commands Role"
DELETE FROM `rbac_role_permissions` WHERE `permissionId` = @amail;
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES
(1, @amail),
(2, @amail),
(3, @amail),
(4, @amail);


/* account set sec email
   account set sec regmail */
SET @setsec = 264;

-- Add new permissions for account set sec
DELETE FROM `rbac_permissions` WHERE `id` BETWEEN @setsec AND @setsec+2;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(@setsec+0, 'account set sec'),
(@setsec+1, 'account set sec email'),
(@setsec+2, 'account set sec regmail');

-- Add permissions to "corresponding Commands Role"
DELETE FROM `rbac_role_permissions` WHERE `permissionId` BETWEEN @setsec AND @setsec+2;
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES
(4, @setsec+0),
(4, @setsec+1),
(4, @setsec+2);

/* cs_cast.cpp */

SET @id = 267;

-- Add new permissions
DELETE FROM `rbac_permissions` WHERE `id` BETWEEN @id AND @id+5;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(@id+0, 'cast'),
(@id+1, 'cast back'),
(@id+2, 'cast dist'),
(@id+3, 'cast self'),
(@id+4, 'cast target'),
(@id+5, 'cast dest');

-- Add permissions to "corresponding Commands Role"
DELETE FROM `rbac_role_permissions` WHERE `permissionId` BETWEEN @id AND @id+5;
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES
(4, @id+0),
(4, @id+1),
(4, @id+2),
(4, @id+3),
(4, @id+4),
(4, @id+5);

/* cs_go.cpp */

SET @id = 377;

-- Add new permissions
DELETE FROM `rbac_permissions` WHERE `id` BETWEEN @id AND @id+9;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(@id+0, 'go'),
(@id+1, 'go creature'),
(@id+2, 'go graveyard'),
(@id+3, 'go grid'),
(@id+4, 'go object'),
(@id+5, 'go taxinode'),
(@id+6, 'go ticket'),
(@id+7, 'go trigger'),
(@id+8, 'go xyz'),
(@id+9, 'go zonexy');

-- Add permissions to "corresponding Commands Role"
DELETE FROM `rbac_role_permissions` WHERE `permissionId` BETWEEN @id AND @id+9;
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES
(2, @id+0),
(2, @id+1),
(2, @id+2),
(2, @id+3),
(2, @id+4),
(2, @id+5),
(2, @id+6),
(2, @id+7),
(2, @id+8),
(2, @id+9);

UPDATE `rbac_permissions` SET `name`='bf enable' WHERE `id`=262;
