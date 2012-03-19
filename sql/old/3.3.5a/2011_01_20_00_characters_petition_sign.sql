ALTER TABLE `petition_sign`
ROW_FORMAT=DEFAULT,
CHANGE `petitionguid` `petitionguid` INT(10) UNSIGNED DEFAULT '0' NOT NULL,
CHANGE `playerguid` `playerguid` INT(10) UNSIGNED DEFAULT '0' NOT NULL,
CHANGE `player_account` `player_account` INT(10) UNSIGNED DEFAULT '0' NOT NULL,
CHANGE `type` `type` TINYINT(3) UNSIGNED DEFAULT '0' NOT NULL;