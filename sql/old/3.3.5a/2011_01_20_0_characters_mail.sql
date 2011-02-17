ALTER TABLE `mail`
ROW_FORMAT=DEFAULT,
CHANGE `id` `id` INT(10) UNSIGNED DEFAULT '0' NOT NULL COMMENT 'Identifier',
CHANGE `mailTemplateId` `mailTemplateId` SMALLINT(5) UNSIGNED DEFAULT '0' NOT NULL,
CHANGE `sender` `sender` INT(10) UNSIGNED DEFAULT '0' NOT NULL COMMENT 'Character Global Unique Identifier',
CHANGE `receiver` `receiver` INT(10) UNSIGNED DEFAULT '0' NOT NULL COMMENT 'Character Global Unique Identifier',
CHANGE `expire_time` `expire_time` INT(10) UNSIGNED DEFAULT '0' NOT NULL,
CHANGE `deliver_time` `deliver_time` INT(10) UNSIGNED DEFAULT '0' NOT NULL,
CHANGE `money` `money` INT(10) UNSIGNED DEFAULT '0' NOT NULL,
CHANGE `cod` `cod` INT(10) UNSIGNED DEFAULT '0' NOT NULL;

