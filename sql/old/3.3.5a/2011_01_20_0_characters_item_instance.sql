ALTER TABLE `item_instance`
ROW_FORMAT=DEFAULT,
CHANGE `guid` `guid` INT(10) UNSIGNED DEFAULT '0' NOT NULL,
CHANGE `owner_guid` `owner_guid` INT(10) UNSIGNED DEFAULT '0' NOT NULL,
CHANGE `charges` `charges` TINYTEXT,
CHANGE `duration` `duration` INT(10) DEFAULT '0' NOT NULL,
CHANGE `flags` `flags` MEDIUMINT(8) UNSIGNED DEFAULT '0' NOT NULL,
CHANGE `randomPropertyId` `randomPropertyId` SMALLINT(5) DEFAULT '0' NOT NULL,
CHANGE `durability` `durability` SMALLINT(5) UNSIGNED DEFAULT '0' NOT NULL,
CHANGE `text` `text` TEXT NULL;
