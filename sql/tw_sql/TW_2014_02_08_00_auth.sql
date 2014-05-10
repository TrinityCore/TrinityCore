/* drop then create account_muted table */
DROP TABLE IF EXISTS `account_muted`;

CREATE TABLE `account_muted` (
	`guid` INT(10) UNSIGNED NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier',
	`mutedate` INT(10) UNSIGNED NOT NULL DEFAULT '0',
	`mutetime` INT(10) UNSIGNED NOT NULL DEFAULT '0',
	`mutedby` VARCHAR(50) NOT NULL,
	`mutereason` VARCHAR(255) NOT NULL,
	PRIMARY KEY (`guid`, `mutedate`)
)
COMMENT='mute List'
COLLATE='utf8_general_ci'
ENGINE=InnoDB;

/* add rbac permissions to new commands */
DELETE FROM `rbac_permissions` WHERE `id` IN (1012);
INSERT INTO `rbac_permissions` (`id`,`name`) VALUES
(1012,'Command: mutehistory');
 
/* adds qc to players */
DELETE FROM `rbac_linked_permissions` WHERE `id` IN (1012);
INSERT INTO `rbac_linked_permissions` (`id`,`linkedId`) VALUES
/* add mutehistory to gms */
(194, 1012);
