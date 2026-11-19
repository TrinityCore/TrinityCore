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
