-- Update command permissions with wrong name
UPDATE `rbac_permissions` SET `name` = CONCAT('Command: ', `name`) WHERE `name` NOT LIKE 'Command: %' AND id BETWEEN 230 AND 774;

-- Reorder some permissions and delete obsolete permissions
SET FOREIGN_KEY_CHECKS = 0;

DELETE FROM `rbac_account_permissions` WHERE `permissionId` IN (202, 203, 204, 205, 206, 207, 208, 214, 215, 216);
DELETE FROM `rbac_role_permissions` WHERE `permissionId` IN (202, 203, 204, 205, 206, 207, 208, 214, 215, 216);
DELETE FROM `rbac_permissions` WHERE `id` IN (202, 203, 204, 205, 206, 207, 208, 214, 215, 216);

UPDATE `rbac_account_permissions` SET `permissionId` = `permissionId` - 7 WHERE `permissionId` BETWEEN 209 AND 213;
UPDATE `rbac_role_permissions` SET `permissionId` = `permissionId` - 7 WHERE `permissionId` BETWEEN 209 AND 213;
UPDATE `rbac_permissions` SET `id` = `id` - 7 WHERE `id` BETWEEN 209 AND 213;

SET FOREIGN_KEY_CHECKS = 1;

-- Create new table for permissions inherited from other permissions (roles)
DROP TABLE IF EXISTS `rbac_linked_permissions`;
CREATE TABLE `rbac_linked_permissions` (
  `id` int(10) unsigned NOT NULL COMMENT 'Permission id',
  `linkedId` int(10) unsigned NOT NULL COMMENT 'Linked Permission id',
  PRIMARY KEY (`id`,`linkedId`),
  KEY `fk__rbac_linked_permissions__rbac_permissions1` (`id`),
  KEY `fk__rbac_linked_permissions__rbac_permissions2` (`linkedId`),
  CONSTRAINT `fk__rbac_linked_permissions__rbac_permissions1` FOREIGN KEY (`id`) REFERENCES `rbac_permissions` (`id`) ON DELETE CASCADE,
  CONSTRAINT `fk__rbac_linked_permissions__rbac_permissions2` FOREIGN KEY (`linkedId`) REFERENCES `rbac_permissions` (`id`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Permission - Linked Permission relation';

-- Create new table for permissions inherited by security level
DROP TABLE IF EXISTS `rbac_default_permissions`;
CREATE TABLE `rbac_default_permissions` (
  `secId` int(10) unsigned NOT NULL COMMENT 'Security Level id',
  `permissionId` int(10) unsigned NOT NULL COMMENT 'permission id',
  PRIMARY KEY (`secId`,`permissionId`),
  KEY `fk__rbac_default_permissions__rbac_permissions` (`permissionId`),
  CONSTRAINT `fk__rbac_default_permissions__rbac_permissions` FOREIGN KEY (`permissionId`) REFERENCES `rbac_permissions` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Default permission to assign to different account security levels';

DELETE FROM `rbac_permissions` WHERE `id` BETWEEN 192 AND 199;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(199, 'Role: Player Commands'),
(198, 'Role: Moderator Commands'),
(197, 'Role: Gamemaster Commands'),
(196, 'Role: Administrator Commands'),
(195, 'Role: Sec Level Player'),
(194, 'Role: Sec Level Moderator'),
(193, 'Role: Sec Level Gamemaster'),
(192, 'Role: Sec Level Administrator');

INSERT INTO `rbac_default_permissions` (secId, `permissionId`) VALUES
(0, 195),
(1, 194),
(2, 193),
(3, 192);

-- Delete duplicate role assignment
DELETE FROM `rbac_group_roles` WHERE `roleId` = 39 AND `groupId` > 3;
DELETE FROM `rbac_group_roles` WHERE `roleId` = 40 AND `groupId` > 1;
DELETE FROM `rbac_group_roles` WHERE `roleId` IN (8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 19, 20, 21, 22, 24, 25, 26, 27, 28, 29, 30, 32, 33, 35, 36, 37, 38) AND `groupId` > 2;
DELETE FROM `rbac_role_permissions` WHERE `permissionId` = 263 AND `roleId` > 1;

-- Add All linked permissions
TRUNCATE `rbac_linked_permissions`;

INSERT INTO `rbac_linked_permissions` (`id`, `linkedId`) VALUES
(192, 193), -- Administrator has granted all permissions from Gamemaster
(192, 196), -- Grant Admin commands to Administrators
(193, 194), -- Gamemaster has granted all permissions from Moderator
(193, 197), -- Grant Gamemaster commands to Gamemasters
(194, 195), -- Moderator has granted all permissions from Player
(194, 198), -- Grant Moderator commands to Moderators
(195, 199); -- Grant Player commands to Players

-- Add all permissions to the Role "Sec Level XXX"
INSERT INTO `rbac_linked_permissions` (`id`, `linkedId`)
SELECT (196 - g.id), p.id
FROM `rbac_groups` g
    JOIN `rbac_group_roles` gr ON g.id = gr.groupId
    JOIN `rbac_roles` r ON gr.roleId = r.id
    JOIN `rbac_role_permissions` rp ON r.id = rp.roleId
    JOIN `rbac_permissions` p ON rp.permissionId = p.id
WHERE r.id > 4;

-- Add all permissions to the Role "XXX Commands"
INSERT INTO `rbac_linked_permissions` (`id`, `linkedId`)
SELECT (200 - r.id), p.id
FROM `rbac_roles` r
    JOIN `rbac_role_permissions` rp ON r.id = rp.roleId
    JOIN `rbac_permissions` p ON rp.permissionId = p.id
WHERE r.id BETWEEN 1 and 4;

-- Delete obsolete tables
DROP TABLE IF EXISTS `rbac_account_roles`;
DROP TABLE IF EXISTS `rbac_account_groups`;
DROP TABLE IF EXISTS `rbac_security_level_groups`;
DROP TABLE IF EXISTS `rbac_group_roles`;
DROP TABLE IF EXISTS `rbac_role_permissions`;
DROP TABLE IF EXISTS `rbac_groups`;
DROP TABLE IF EXISTS `rbac_roles`;