CREATE TABLE IF NOT EXISTS `creature_template_outfits` (
	`entry` INT(10) UNSIGNED NOT NULL,
	`race` TINYINT(3) UNSIGNED NOT NULL DEFAULT '1',
	`gender` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0' COMMENT '0 for male, 1 for female',
	`skin` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0',
	`face` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0',
	`hair` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0',
	`haircolor` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0',
	`facialhair` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0',
	`head` INT(10) NOT NULL DEFAULT '0',
	`shoulders` INT(10) NOT NULL DEFAULT '0',
	`body` INT(10) NOT NULL DEFAULT '0',
	`chest` INT(10) NOT NULL DEFAULT '0',
	`waist` INT(10) NOT NULL DEFAULT '0',
	`legs` INT(10) NOT NULL DEFAULT '0',
	`feet` INT(10) NOT NULL DEFAULT '0',
	`wrists` INT(10) NOT NULL DEFAULT '0',
	`hands` INT(10) NOT NULL DEFAULT '0',
	`back` INT(10) NOT NULL DEFAULT '0',
	`tabard` INT(10) NOT NULL DEFAULT '0',
	PRIMARY KEY (`entry`)
)
COMMENT='Use positive values for item entries and negative to use item displayid for head, shoulders etc.'
COLLATE='utf8_general_ci'
ENGINE=InnoDB;

ALTER TABLE `creature_template`
	CHANGE COLUMN `modelid1` `modelid1` INT NOT NULL DEFAULT '0' AFTER `KillCredit2`,
	CHANGE COLUMN `modelid2` `modelid2` INT NOT NULL DEFAULT '0' AFTER `modelid1`,
	CHANGE COLUMN `modelid3` `modelid3` INT NOT NULL DEFAULT '0' AFTER `modelid2`,
	CHANGE COLUMN `modelid4` `modelid4` INT NOT NULL DEFAULT '0' AFTER `modelid3`;
