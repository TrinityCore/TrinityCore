ALTER TABLE `character_achievement`
CHANGE `guid` `guid` INT(10) UNSIGNED NOT NULL,
CHANGE `achievement` `achievement` SMALLINT(5) UNSIGNED NOT NULL,
CHANGE `date` `date` INT(10) UNSIGNED DEFAULT '0' NOT NULL;