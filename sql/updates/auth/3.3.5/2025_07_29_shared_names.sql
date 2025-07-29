DROP TABLE IF EXISTS `shared_names`;

CREATE TABLE `shared_names` (
	`type` ENUM('PlayerName','Guild') NOT NULL COLLATE 'utf8mb3_bin',
	`guid` INT(10) UNSIGNED NOT NULL,
	`realmId` INT(10) UNSIGNED NOT NULL,
	`name` VARCHAR(12) NOT NULL COLLATE 'utf8mb3_bin',
	`realmGroupId` INT(10) UNSIGNED NOT NULL,
	PRIMARY KEY (`guid`, `realmId`, `type`) USING BTREE
)
COLLATE='utf8mb3_bin'
ENGINE=InnoDB
;
