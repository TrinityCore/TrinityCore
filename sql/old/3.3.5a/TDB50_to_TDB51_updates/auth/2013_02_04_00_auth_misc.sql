-- Explicitly set the account-table to use INNODB-engine (to allow foreign keys and transactions)
ALTER TABLE account ENGINE=InnoDB;

-- Delete bad data from the DB before adding foreign keys
DELETE FROM `account_access` WHERE `id` NOT IN (SELECT `id` FROM `account`);

-- Need them first in case of re-execute due to foreign keys
DROP TABLE IF EXISTS `rbac_account_permissions`;
DROP TABLE IF EXISTS `rbac_account_roles`;
DROP TABLE IF EXISTS `rbac_account_groups`;
DROP TABLE IF EXISTS `rbac_role_permissions`;
DROP TABLE IF EXISTS `rbac_group_roles`;
DROP TABLE IF EXISTS `rbac_security_level_groups`;
DROP TABLE IF EXISTS `rbac_permissions`;
DROP TABLE IF EXISTS `rbac_roles`;
DROP TABLE IF EXISTS `rbac_groups`;

CREATE TABLE IF NOT EXISTS `rbac_groups` (
  `id` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Group id',
  `name` varchar(50) NOT NULL COMMENT 'Group name',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Group List';

CREATE TABLE IF NOT EXISTS `rbac_roles` (
  `id` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Role id',
  `name` varchar(50) NOT NULL COMMENT 'Role name',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Roles List';

CREATE TABLE IF NOT EXISTS `rbac_permissions` (
  `id` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Permission id',
  `name` varchar(100) NOT NULL COMMENT 'Permission name',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Permission List';

CREATE TABLE IF NOT EXISTS `rbac_group_roles` (
  `groupId` int(10) unsigned NOT NULL COMMENT 'group id',
  `roleId` int(10) unsigned NOT NULL COMMENT 'Role id',
  PRIMARY KEY (`groupId`, `roleId`),
  CONSTRAINT `fk__rbac_group_roles__rbac_roles`
    FOREIGN KEY (`roleId`) REFERENCES `rbac_roles`(`id`)
    ON DELETE CASCADE ON UPDATE RESTRICT,
  CONSTRAINT `fk__rbac_group_roles__rbac_groups`
    FOREIGN KEY (`groupId`) REFERENCES `rbac_groups`(`id`)
    ON DELETE CASCADE ON UPDATE RESTRICT
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Group Role relation';

CREATE TABLE IF NOT EXISTS `rbac_role_permissions` (
  `roleId` int(10) unsigned NOT NULL COMMENT 'Role id',
  `permissionId` int(10) unsigned NOT NULL COMMENT 'Permission id',
  PRIMARY KEY (`roleId`, `permissionId`),
  CONSTRAINT `fk__role_permissions__rbac_roles`
    FOREIGN KEY (`roleId`) REFERENCES `rbac_roles`(`id`)
    ON DELETE CASCADE ON UPDATE RESTRICT,
  CONSTRAINT `fk__role_permissions__rbac_permissions`
    FOREIGN KEY (`permissionId`) REFERENCES `rbac_permissions`(`id`)
    ON DELETE CASCADE ON UPDATE RESTRICT
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Role Permission relation';

CREATE TABLE IF NOT EXISTS `rbac_security_level_groups` (
  `secId` int(10) unsigned NOT NULL COMMENT 'Security Level id',
  `groupId` int(10) unsigned NOT NULL COMMENT 'group id',
  PRIMARY KEY (`secId`, `groupId`),
  CONSTRAINT `fk__rbac_security_level_groups__rbac_groups`
    FOREIGN KEY (`groupId`) REFERENCES `rbac_groups`(`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Default groups to assign when an account is set gm level';

CREATE TABLE IF NOT EXISTS `rbac_account_groups` (
  `accountId` int(10) unsigned NOT NULL COMMENT 'Account id',
  `groupId` int(10) unsigned NOT NULL COMMENT 'Group id',
  `realmId` int(11) NOT NULL DEFAULT '-1' COMMENT 'Realm Id, -1 means all',
  PRIMARY KEY (`accountId`, `groupId`, `realmId`),
  CONSTRAINT `fk__rbac_account_groups__account`
    FOREIGN KEY (`accountId`) REFERENCES `account`(`id`)
    ON DELETE CASCADE ON UPDATE RESTRICT,
  CONSTRAINT `fk__rbac_account_groups__rbac_groups`
    FOREIGN KEY (`groupId`) REFERENCES `rbac_groups`(`id`)
    ON DELETE CASCADE ON UPDATE RESTRICT
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Account-Group relation';

CREATE TABLE IF NOT EXISTS `rbac_account_roles` (
  `accountId` int(10) unsigned NOT NULL COMMENT 'Account id',
  `roleId` int(10) unsigned NOT NULL COMMENT 'Role id',
  `granted` tinyint(1) NOT NULL default 1 COMMENT 'Granted = 1, Denied = 0',
  `realmId` int(11) NOT NULL DEFAULT '-1' COMMENT 'Realm Id, -1 means all',
  PRIMARY KEY (`accountId`, `roleId`, `realmId`),
  CONSTRAINT `fk__rbac_account_roles__account`
    FOREIGN KEY (`accountId`) REFERENCES `account`(`id`)
    ON DELETE CASCADE ON UPDATE RESTRICT,
  CONSTRAINT `fk__rbac_account_roles__rbac_roles`
    FOREIGN KEY (`roleId`) REFERENCES `rbac_roles`(`id`)
    ON DELETE CASCADE ON UPDATE RESTRICT
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Account-Role relation';

CREATE TABLE IF NOT EXISTS `rbac_account_permissions` (
  `accountId` int(10) unsigned NOT NULL COMMENT 'Account id',
  `permissionId` int(10) unsigned NOT NULL COMMENT 'Permission id',
  `granted` tinyint(1) NOT NULL default 1 COMMENT 'Granted = 1, Denied = 0',
  `realmId` int(11) NOT NULL DEFAULT '-1' COMMENT 'Realm Id, -1 means all',
  PRIMARY KEY (`accountId`, `permissionId`, `realmId`),
  CONSTRAINT `fk__rbac_account_permissions__account`
    FOREIGN KEY (`accountId`) REFERENCES `account`(`id`)
    ON DELETE CASCADE ON UPDATE RESTRICT,
  CONSTRAINT `fk__rbac_account_roles__rbac_permissions`
    FOREIGN KEY (`permissionId`) REFERENCES `rbac_permissions`(`id`)
    ON DELETE CASCADE ON UPDATE RESTRICT
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Account-Permission relation';

DELETE FROM `rbac_permissions` WHERE `id` BETWEEN 1 AND 10;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(1, 'Instant logout'),
(2, 'Skip Queue'),
(3, 'Join Normal Battleground'),
(4, 'Join Random Battleground'),
(5, 'Join Arenas'),
(6, 'Join Dungeon Finder'),
(7, 'Player Commands (Temporal till commands moved to rbac)'),
(8, 'Moderator Commands (Temporal till commands moved to rbac)'),
(9, 'GameMaster Commands (Temporal till commands moved to rbac)'),
(10, 'Administrator Commands (Temporal till commands moved to rbac)');

DELETE FROM `rbac_roles` WHERE `id` BETWEEN 1 AND 7;
INSERT INTO `rbac_roles` (`id`, `name`) VALUES
(1, 'Player Commands'),
(2, 'Moderator Commands'),
(3, 'GameMaster Commands'),
(4, 'Administrator Commands'),
(5, 'Quick Login/Logout'),
(6, 'Use Battleground/Arenas'),
(7, 'Use Dungeon Finder');

DELETE FROM `rbac_groups` WHERE `id` BETWEEN 1 AND 4;
INSERT INTO `rbac_groups` (`id`, `name`) VALUES
(1, 'Player'),
(2, 'Moderator'),
(3, 'GameMaster'),
(4, 'Administrator');

DELETE FROM `rbac_role_permissions` WHERE `roleId` BETWEEN 1 AND 7;
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES
(5, 1),
(5, 2),
(6, 3),
(6, 4),
(6, 5),
(7, 6),
(1, 7),
(2, 8),
(3, 9),
(4, 10);

DELETE FROM `rbac_group_roles` WHERE `groupId` BETWEEN 1 AND 4;
INSERT INTO `rbac_group_roles` (`groupId`, `roleId`) VALUES
(1, 1),
(1, 6),
(1, 7),
(2, 2),
(2, 5),
(3, 3),
(4, 4);

TRUNCATE `rbac_account_groups`;
INSERT INTO `rbac_account_groups` (`accountId`, `groupId`, `realmId`) SELECT `id`, 1, -1 FROM `account`; -- Add Player group to all accounts
INSERT INTO `rbac_account_groups` (`accountId`, `groupId`, `realmId`) SELECT `id`, 2, `RealmID` FROM `account_access` WHERE `gmlevel` > 0; -- Add Moderator group to all Moderator or higher GM level
INSERT INTO `rbac_account_groups` (`accountId`, `groupId`, `realmId`) SELECT `id`, 3, `RealmID` FROM `account_access` WHERE `gmlevel` > 1; -- Add GameMaster group to all GameMasters or higher GM level
INSERT INTO `rbac_account_groups` (`accountId`, `groupId`, `realmId`) SELECT `id`, 4, `RealmID` FROM `account_access` WHERE `gmlevel` > 2; -- Add Administrator group to all Administrators

TRUNCATE `rbac_security_level_groups`;
INSERT INTO `rbac_security_level_groups` (`secId`, `groupId`) VALUES
(0, 1),
(1, 1),
(1, 2),
(2, 1),
(2, 2),
(2, 3),
(3, 1),
(3, 2),
(3, 3),
(3, 4);
