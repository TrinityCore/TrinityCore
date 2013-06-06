ALTER TABLE `character_achievement_progress`
CHANGE `guid` `guid` INT(10) UNSIGNED NOT NULL,
CHANGE `criteria` `criteria` SMALLINT(5) UNSIGNED NOT NULL,
CHANGE `counter` `counter` INT(10) UNSIGNED NOT NULL,
CHANGE `date` `date` INT(10) UNSIGNED DEFAULT '0' NOT NULL;