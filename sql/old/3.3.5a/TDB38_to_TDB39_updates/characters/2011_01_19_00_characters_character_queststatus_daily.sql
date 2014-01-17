ALTER TABLE `character_queststatus_daily`
ROW_FORMAT=DEFAULT,
CHANGE `guid` `guid` INT(10) UNSIGNED DEFAULT '0' NOT NULL COMMENT 'Global Unique Identifier',
CHANGE `quest` `quest` INT(10) UNSIGNED DEFAULT '0' NOT NULL COMMENT 'Quest Identifier',
CHANGE `time` `time` INT(10) UNSIGNED DEFAULT '0' NOT NULL;