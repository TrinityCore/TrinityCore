DROP TABLE IF EXISTS `hotfix_optional_data`;
CREATE TABLE `hotfix_optional_data` (
	`TableHash` INT(10) UNSIGNED NOT NULL,
	`RecordId` INT(11) NOT NULL,
	`locale` VARCHAR(4) NOT NULL COLLATE 'utf8mb4_unicode_ci',
	`Data` BLOB NULL DEFAULT NULL,
	`VerifiedBuild` INT(11) NOT NULL DEFAULT '0',
	PRIMARY KEY (`TableHash`, `RecordId`, `locale`) USING BTREE
)
COLLATE='utf8_general_ci'
ENGINE=MyISAM
;
