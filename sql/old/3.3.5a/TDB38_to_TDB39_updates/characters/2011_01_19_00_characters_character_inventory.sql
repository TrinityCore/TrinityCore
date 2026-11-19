ALTER TABLE `character_inventory`
ROW_FORMAT=DEFAULT,
CHANGE `guid` `guid` INT(10) UNSIGNED DEFAULT '0' NOT NULL COMMENT 'Global Unique Identifier',
CHANGE `bag` `bag` INT(10) UNSIGNED DEFAULT '0' NOT NULL,
CHANGE `item` `item` INT(10) UNSIGNED DEFAULT '0' NOT NULL COMMENT 'Item Global Unique Identifier';