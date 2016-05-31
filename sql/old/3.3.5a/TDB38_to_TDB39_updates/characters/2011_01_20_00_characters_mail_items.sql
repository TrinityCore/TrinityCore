ALTER TABLE `mail_items`
CHANGE `mail_id` `mail_id` INT(10) UNSIGNED DEFAULT '0' NOT NULL,
CHANGE `item_guid` `item_guid` INT(10) UNSIGNED DEFAULT '0' NOT NULL,
CHANGE `receiver` `receiver` INT(10) UNSIGNED DEFAULT '0' NOT NULL COMMENT 'Character Global Unique Identifier';