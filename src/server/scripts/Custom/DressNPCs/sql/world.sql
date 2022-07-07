CREATE TABLE `creature_template_outfits` (
	`entry` INT(10) UNSIGNED NOT NULL,
	`npcsoundsid` INT(10) UNSIGNED NOT NULL DEFAULT '0' COMMENT 'entry from NPCSounds.dbc/db2',
	`race` TINYINT(3) UNSIGNED NOT NULL DEFAULT '1',
	`class` TINYINT(3) UNSIGNED NOT NULL DEFAULT '1',
	`gender` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0' COMMENT '0 for male, 1 for female',
	`spellvisualkitid` INT(10) NOT NULL DEFAULT 0,
	`customizations` TEXT NULL DEFAULT NULL,
	`head` BIGINT(20) NOT NULL DEFAULT '0',
	`head_appearance` INT(10) UNSIGNED NOT NULL DEFAULT '0',
	`shoulders` BIGINT(20) NOT NULL DEFAULT '0',
	`shoulders_appearance` INT(10) UNSIGNED NOT NULL DEFAULT '0',
	`body` BIGINT(20) NOT NULL DEFAULT '0',
	`body_appearance` INT(10) UNSIGNED NOT NULL DEFAULT '0',
	`chest` BIGINT(20) NOT NULL DEFAULT '0',
	`chest_appearance` INT(10) UNSIGNED NOT NULL DEFAULT '0',
	`waist` BIGINT(20) NOT NULL DEFAULT '0',
	`waist_appearance` INT(10) UNSIGNED NOT NULL DEFAULT '0',
	`legs` BIGINT(20) NOT NULL DEFAULT '0',
	`legs_appearance` INT(10) UNSIGNED NOT NULL DEFAULT '0',
	`feet` BIGINT(20) NOT NULL DEFAULT '0',
	`feet_appearance` INT(10) UNSIGNED NOT NULL DEFAULT '0',
	`wrists` BIGINT(20) NOT NULL DEFAULT '0',
	`wrists_appearance` INT(10) UNSIGNED NOT NULL DEFAULT '0',
	`hands` BIGINT(20) NOT NULL DEFAULT '0',
	`hands_appearance` INT(10) UNSIGNED NOT NULL DEFAULT '0',
	`back` BIGINT(20) NOT NULL DEFAULT '0',
	`back_appearance` INT(10) UNSIGNED NOT NULL DEFAULT '0',
	`tabard` BIGINT(20) NOT NULL DEFAULT '0',
	`tabard_appearance` INT(10) UNSIGNED NOT NULL DEFAULT '0',
	`guildid` BIGINT(20) UNSIGNED NOT NULL DEFAULT '0',
	`description` TEXT NULL DEFAULT NULL COLLATE 'utf8_general_ci',
	PRIMARY KEY (`entry`) USING BTREE
)
COMMENT='Use positive values for item entries and negative to use item displayid for head, shoulders etc.'
COLLATE='utf8_general_ci'
ENGINE=InnoDB
;

ALTER TABLE `creature` CHANGE COLUMN `modelid` `modelid` INT(10) UNSIGNED NOT NULL DEFAULT '0';
ALTER TABLE `game_event_model_equip` CHANGE COLUMN `modelid` `modelid` INT(10) UNSIGNED NOT NULL DEFAULT '0';
ALTER TABLE `creature_model_info` CHANGE COLUMN `DisplayID` `DisplayID` INT(10) UNSIGNED NOT NULL DEFAULT '0';
