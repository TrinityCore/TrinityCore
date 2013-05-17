ALTER TABLE `rbac_roles` MODIFY COLUMN `name` varchar(100) NOT NULL COMMENT 'Role name';
ALTER TABLE `rbac_groups` MODIFY COLUMN `name` varchar(100) NOT NULL COMMENT 'Group name';

-- Add new permission
DELETE FROM `rbac_permissions` WHERE `id` = 11;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES (11, 'Log GM trades');

-- Add new role
DELETE FROM `rbac_roles` WHERE `id` = 8;
INSERT INTO `rbac_roles` (`id`, `name`) VALUES (8, 'Log GM trades');

-- Add the permission to the role
DELETE FROM `rbac_role_permissions` WHERE `roleId` = 8;
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES (8, 11);

-- Add it to all GM+ groups
DELETE FROM `rbac_group_roles` WHERE `roleId` = 8;
INSERT INTO `rbac_group_roles` (`groupId`, `roleId`) VALUES
(2, 8),
(3, 8),
(4, 8);
-- Add new permission
DELETE FROM `rbac_permissions` WHERE `id` = 13;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES (13, 'Skip Instance required bosses check');

-- Add new role
DELETE FROM `rbac_roles` WHERE `id` = 9;
INSERT INTO `rbac_roles` (`id`, `name`) VALUES (9, 'Skip Instance required bosses check');

-- Add the permission to the role
DELETE FROM `rbac_role_permissions` WHERE `roleId` = 9;
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES (9, 13);

-- Add it to all GM+ groups
DELETE FROM `rbac_group_roles` WHERE `roleId` = 9;
INSERT INTO `rbac_group_roles` (`groupId`, `roleId`) VALUES
(2, 9),
(3, 9),
(4, 9);
-- Add new permission
DELETE FROM `rbac_permissions` WHERE `id` = 32;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES (32, 'Can be assigned tickets with .assign ticket command');

-- Add new role
DELETE FROM `rbac_roles` WHERE `id` = 10;
INSERT INTO `rbac_roles` (`id`, `name`) VALUES (10, 'Ticket management');

-- Add the permission to the role
DELETE FROM `rbac_role_permissions` WHERE `roleId` = 10;
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES (10, 32);

-- Add it to all GM+ groups
DELETE FROM `rbac_group_roles` WHERE `roleId` = 10;
INSERT INTO `rbac_group_roles` (`groupId`, `roleId`) VALUES
(2, 10),
(3, 10),
(4, 10);
-- Add new permissions
DELETE FROM `rbac_permissions` WHERE `id` IN (30, 31, 38);
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(30, 'Save character without delay with .save command'),
(31, 'Use params with .unstuck command'),
(38, 'Resurrect with full Health Points');

-- Add new role
DELETE FROM `rbac_roles` WHERE `id` IN (11, 12, 13);
INSERT INTO `rbac_roles` (`id`, `name`) VALUES
(11, 'Instant .save'),
(12, 'Allow params with .unstuck'),
(13, 'Full HP after resurrect');

-- Add the permission to the role
DELETE FROM `rbac_role_permissions` WHERE `roleId` IN (11, 12, 13);
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES
(11, 30),
(12, 31),
(13, 38);

-- Add it to all GM+ groups
DELETE FROM `rbac_group_roles` WHERE `roleId` IN (11, 12, 13);
INSERT INTO `rbac_group_roles` (`groupId`, `roleId`) VALUES
(2, 11),
(3, 11),
(4, 11),
(2, 12),
(3, 12),
(4, 12),
(2, 13),
(3, 13),
(4, 13);
-- Add new permissions
DELETE FROM `rbac_permissions` WHERE `id` IN (34, 37);
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(34, 'Check if should appear in list using .gm ingame command'),
(37, 'Use staff badge in chat');

-- Add new role
DELETE FROM `rbac_roles` WHERE `id` IN (14, 15);
INSERT INTO `rbac_roles` (`id`, `name`) VALUES
(14, 'Appear in GM ingame list'),
(15, 'Use staff badge in chat');

-- Add the permission to the role
DELETE FROM `rbac_role_permissions` WHERE `roleId` IN (14, 15);
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES
(14, 34),
(15, 37);

-- Add it to all GM+ groups
DELETE FROM `rbac_group_roles` WHERE `roleId` IN (14, 15);
INSERT INTO `rbac_group_roles` (`groupId`, `roleId`) VALUES
(2, 14),
(3, 14),
(4, 14),
(2, 15),
(3, 15),
(4, 15);
-- Add new permission
DELETE FROM `rbac_permissions` WHERE `id` = 44;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES (44, 'Receive global GM messages/texts');

-- Add new role
DELETE FROM `rbac_roles` WHERE `id` = 16;
INSERT INTO `rbac_roles` (`id`, `name`) VALUES (16, 'Receive global GM messages/texts');

-- Add the permission to the role
DELETE FROM `rbac_role_permissions` WHERE `roleId` = 16;
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES (16, 44);

-- Add it to all GM+ groups
DELETE FROM `rbac_group_roles` WHERE `roleId` = 16;
INSERT INTO `rbac_group_roles` (`groupId`, `roleId`) VALUES
(2, 16),
(3, 16),
(4, 16);
-- Add new permission
DELETE FROM `rbac_permissions` WHERE `id` = 23;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES (23, 'Skip over-speed ping check');

-- Add new role
DELETE FROM `rbac_roles` WHERE `id` = 17;
INSERT INTO `rbac_roles` (`id`, `name`) VALUES (17, 'Skip over-speed ping check');

-- Add the permission to the role
DELETE FROM `rbac_role_permissions` WHERE `roleId` = 17;
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES (17, 23);

-- Add it to all GM+ groups
DELETE FROM `rbac_group_roles` WHERE `roleId` = 17;
INSERT INTO `rbac_group_roles` (`groupId`, `roleId`) VALUES
(2, 17),
(3, 17),
(4, 17);
-- Add new permissions
DELETE FROM `rbac_permissions` WHERE `id` IN (42, 43);
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(42, 'Allows to use CMSG_WORLD_TELEPORT opcode'),
(43, 'Allows to use CMSG_WHOIS opcode');

-- Add new role
DELETE FROM `rbac_roles` WHERE `id` = 18;
INSERT INTO `rbac_roles` (`id`, `name`) VALUES
(18, 'Allows Admin Opcodes');

-- Add the permission to the role
DELETE FROM `rbac_role_permissions` WHERE `roleId` = 18;
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES
(18, 42),
(18, 43);

-- Add it to admins groups
DELETE FROM `rbac_group_roles` WHERE `roleId` = 18;
INSERT INTO `rbac_group_roles` (`groupId`, `roleId`) VALUES
(4, 18);
-- Add new permission
DELETE FROM `rbac_permissions` WHERE `id` = 27;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES (27, 'Two side mail interaction');

-- Add new role
DELETE FROM `rbac_roles` WHERE `id` = 19;
INSERT INTO `rbac_roles` (`id`, `name`) VALUES (19, 'Two side mail interaction');

-- Add the permission to the role
DELETE FROM `rbac_role_permissions` WHERE `roleId` = 19;
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES (19, 27);

-- Add it to all GM+ groups
DELETE FROM `rbac_group_roles` WHERE `roleId` = 19;
INSERT INTO `rbac_group_roles` (`groupId`, `roleId`) VALUES
(1, 19),
(2, 19),
(3, 19),
(4, 19);
-- Add new permissions
DELETE FROM `rbac_permissions` WHERE `id` IN (33, 47);
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(33, 'Notify if a command was not found'),
(47, 'Enables lower security than target check');

-- Add new role
DELETE FROM `rbac_roles` WHERE `id` IN (20, 21);
INSERT INTO `rbac_roles` (`id`, `name`) VALUES
(20, 'Notify if a command was not found'),
(21, 'Enables lower security than target check');

-- Add the permission to the role
DELETE FROM `rbac_role_permissions` WHERE `roleId` IN (20, 21);
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES
(20, 33),
(21, 47);

-- Add it to all GM+ groups
DELETE FROM `rbac_group_roles` WHERE `roleId` IN (20, 21);
INSERT INTO `rbac_group_roles` (`groupId`, `roleId`) VALUES
(2, 20),
(3, 20),
(4, 20),
(2, 21),
(3, 21),
(4, 21);
-- Add new permissions
DELETE FROM `rbac_permissions` WHERE `id` IN (20, 21, 22, 39, 41);
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(20, 'Skip disable map check'),
(21, 'Skip reset talents when used more than allowed check'),
(22, 'Skip spam chat check'),
(39, 'Restore saved gm setting states'),
(41, 'Use Config option START_GM_LEVEL to assign new character level');

-- Add new role
DELETE FROM `rbac_roles` WHERE `id` IN (22, 23, 24, 25, 26);
INSERT INTO `rbac_roles` (`id`, `name`) VALUES
(22, 'Skip disable map check'),
(23, 'Skip reset talents when used more than allowed check'),
(24, 'Skip spam chat check'),
(25, 'Restore saved gm setting states'),
(26, 'Use Config option START_GM_LEVEL to assign new character level');

-- Add the permission to the role
DELETE FROM `rbac_role_permissions` WHERE `roleId` IN (22, 23, 24, 25, 26);
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES
(22, 20),
(23, 21),
(24, 22),
(25, 39),
(26, 41);

-- Add it to all GM+ groups
DELETE FROM `rbac_group_roles` WHERE `roleId` IN (22, 23, 24, 25, 26);
INSERT INTO `rbac_group_roles` (`groupId`, `roleId`) VALUES
(2, 22),
(3, 22),
(4, 22),
(4, 23),
(2, 24),
(3, 24),
(4, 24),
(2, 25),
(3, 25),
(4, 25),
(2, 26),
(3, 26),
(4, 26);
-- Add new permissions
DELETE FROM `rbac_permissions` WHERE `id` IN (19, 25, 36);
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(19, 'Skip needed requirements to use channel check'),
(25, 'Allow say chat between factions'),
(36, 'Filter whispers');

-- Add new role
DELETE FROM `rbac_roles` WHERE `id` IN (27, 28, 29);
INSERT INTO `rbac_roles` (`id`, `name`) VALUES
(27, 'Skip needed requirements to use channel check'),
(28, 'Allow say chat between factions'),
(29, 'Filter whispers');

-- Add the permission to the role
DELETE FROM `rbac_role_permissions` WHERE `roleId` IN (27, 28, 29);
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES
(27, 19),
(28, 25),
(29, 36);

-- Add it to all GM+ groups
DELETE FROM `rbac_group_roles` WHERE `roleId` IN (27, 28, 29);
INSERT INTO `rbac_group_roles` (`groupId`, `roleId`) VALUES
(2, 27),
(3, 27),
(4, 27),
(1, 28),
(2, 28),
(3, 28),
(4, 28),
(2, 29),
(3, 29),
(4, 29);
-- Add new permissions
DELETE FROM `rbac_permissions` WHERE `id` IN (26, 45, 46);
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(26, 'Allow channel chat between factions'),
(45, 'Join channels without announce'),
(46, 'Change channel settings without being channel moderator');

-- Add new role
DELETE FROM `rbac_roles` WHERE `id` IN (30, 31, 32);
INSERT INTO `rbac_roles` (`id`, `name`) VALUES
(30, 'Allow channel chat between factions'),
(31, 'Join channels without announce'),
(32, 'Change channel settings without being channel moderator');

-- Add the permission to the role
DELETE FROM `rbac_role_permissions` WHERE `roleId` IN (30, 31, 32);
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES
(30, 26),
(31, 45),
(32, 46);

-- Add it to all GM+ groups
DELETE FROM `rbac_group_roles` WHERE `roleId` IN (30, 31, 32);
INSERT INTO `rbac_group_roles` (`groupId`, `roleId`) VALUES
(1, 30),
(2, 30),
(3, 30),
(4, 30),
(2, 31),
(3, 31),
(4, 31),
(2, 32),
(3, 32),
(4, 32);
-- Add new permissions
DELETE FROM `rbac_permissions` WHERE `id` IN (14, 15, 16, 17, 18, 24);
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(14, 'Skip character creation team mask check'),
(15, 'Skip character creation class mask check'),
(16, 'Skip character creation race mask check'),
(17, 'Skip character creation reserved name check'),
(18, 'Skip character creation heroic min level check'),
(24, 'Two side faction characters on the same account');

-- Add new role
DELETE FROM `rbac_roles` WHERE `id` IN (33, 34);
INSERT INTO `rbac_roles` (`id`, `name`) VALUES
(33, 'Skip character creation checks'),
(34, 'Two side faction characters on the same account');

-- Add the permission to the role
DELETE FROM `rbac_role_permissions` WHERE `roleId` IN (33, 34);
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES
(33, 14),
(33, 15),
(33, 16),
(33, 17),
(33, 18),
(34, 24);

-- Add it to all groups
DELETE FROM `rbac_group_roles` WHERE `roleId` IN (33, 34);
INSERT INTO `rbac_group_roles` (`groupId`, `roleId`) VALUES
(2, 33),
(3, 33),
(4, 33),
(2, 34),
(3, 34),
(4, 34);

-- Add new permissions
DELETE FROM `rbac_permissions` WHERE `id` IN (28, 29, 35, 40);
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(28, 'See two side who list'),
(29, 'Add friends of other faction'),
(35, 'See all security levels with who command'),
(40, 'Allows to add a gm to friend list');

-- Add new role
DELETE FROM `rbac_roles` WHERE `id` IN (35, 36, 37, 38);
INSERT INTO `rbac_roles` (`id`, `name`) VALUES
(35, 'See two side who list'),
(36, 'Add friends of other faction'),
(37, 'See all security levels with who command'),
(38, 'Allows to add a gm to friend list');

-- Add the permission to the role
DELETE FROM `rbac_role_permissions` WHERE `roleId` IN (35, 36, 37, 38);
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES
(35, 28),
(36, 29),
(37, 35),
(38, 40);

-- Add it to all groups
DELETE FROM `rbac_group_roles` WHERE `roleId` IN (35, 36, 37, 38);
INSERT INTO `rbac_group_roles` (`groupId`, `roleId`) VALUES
(2, 35),
(3, 35),
(4, 35),
(2, 36),
(3, 36),
(4, 36),
(2, 37),
(3, 37),
(4, 37),
(2, 38),
(3, 38),
(4, 38);
-- Delete 'Two side mail interaction', 'Allow say chat between factions' and 'Allow channel chat between factions' from Player group
DELETE FROM `rbac_group_roles` WHERE `groupId` = 1 AND `roleId` IN (19, 28, 30);

-- Delete 'Join channels without announce' from Moderators+ group
DELETE FROM `rbac_group_roles` WHERE `roleId` = 31;

-- Add 'Allow two side charater accounts'
DELETE FROM `rbac_group_roles` WHERE `roleId` = 34;
INSERT INTO `rbac_group_roles` (`groupId`, `roleId`) VALUES (1, 34);
--  change secId from int(10)u to tinyint(3)u
ALTER TABLE `rbac_security_level_groups` CHANGE `secId` `secId` tinyint(3) unsigned NOT NULL COMMENT 'Security Level id';
ALTER TABLE `account` ADD COLUMN `lock_country` VARCHAR(2) NOT NULL DEFAULT '00' AFTER `locked`;

DROP TABLE IF EXISTS ip2nation;
CREATE TABLE ip2nation (
  ip int(11) unsigned NOT NULL default '0',
  country char(2) NOT NULL default '',
  KEY ip (ip)
);

DROP TABLE IF EXISTS ip2nationCountries;
CREATE TABLE ip2nationCountries (
  code varchar(4) NOT NULL default '',
  iso_code_2 varchar(2) NOT NULL default '',
  iso_code_3 varchar(3) default '',
  iso_country varchar(255) NOT NULL default '',
  country varchar(255) NOT NULL default '',
  lat float NOT NULL default '0',
  lon float NOT NULL default '0',  
  PRIMARY KEY  (code),
  KEY code (code)
);
DROP TABLE IF EXISTS `autobroadcast`;
CREATE TABLE `autobroadcast` (
  `realmid` int(10) NOT NULL,
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `weight` tinyint(3) DEFAULT 1,
  `text` longtext NOT NULL,
  PRIMARY KEY (`id`, `realmid`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
