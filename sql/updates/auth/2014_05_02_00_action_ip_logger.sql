ALTER TABLE `account`
	ADD COLUMN `last_attempt_ip` VARCHAR(15) NOT NULL DEFAULT '127.0.0.1' AFTER `last_ip`;
	
CREATE TABLE `logs_ip_actions` (
`id` INT(10) UNSIGNED NOT NULL AUTO_INCREMENT COMMENT 'Unique Identifier',
`account_id` INT(10) UNSIGNED NOT NULL COMMENT 'Account ID',
`character_guid` INT(10) UNSIGNED NOT NULL COMMENT 'Character Guid',
`type` TINYINT(3) UNSIGNED NOT NULL,
`ip` VARCHAR(15) NOT NULL DEFAULT '127.0.0.1',
`systemnote` TEXT NULL COMMENT 'Notes inserted by system',
`unixtime` INT(10) UNSIGNED NOT NULL COMMENT 'Unixtime',
`time` TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT 'Timestamp',
`comment` TEXT NULL COMMENT 'Allows users to add a comment',
PRIMARY KEY (`id`)
)
COMMENT='Used to log ips of individual actions'
COLLATE='utf8_general_ci'
ENGINE=InnoDB;
