-- tables for arena log
CREATE TABLE `arena_log` (`id` INT( 10 ) UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY ,
`identifier` VARCHAR( 32 ) NOT NULL DEFAULT '',
`type` INT( 10 ) UNSIGNED NOT NULL DEFAULT '0',
`winner_team` INT( 10 ) UNSIGNED NOT NULL DEFAULT '0',
`winner_old_rating` INT( 10 ) UNSIGNED NOT NULL DEFAULT '0',
`winner_rating_change` INT( 10 ) NOT NULL DEFAULT '0',
`winner_old_mmr` INT( 10 ) UNSIGNED NOT NULL DEFAULT '0',
`winner_mmr_change` INT( 10 ) NOT NULL DEFAULT '0',
`loser_team` INT( 10 ) UNSIGNED NOT NULL DEFAULT '0',
`loser_old_rating` INT( 10 ) UNSIGNED NOT NULL DEFAULT '0',
`loser_rating_change` INT( 10 ) NOT NULL DEFAULT '0',
`loser_old_mmr` INT( 10 ) UNSIGNED NOT NULL DEFAULT '0',
`loser_mmr_change` INT( 10 ) NOT NULL DEFAULT '0',
`duration` INT( 10 ) UNSIGNED NOT NULL DEFAULT '0'
) ENGINE = InnoDB CHARACTER SET utf8 COLLATE utf8_general_ci;

CREATE TABLE `arena_log_member` (`id` INT( 10 ) UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY ,
`match_identifier` VARCHAR( 32 ) NOT NULL DEFAULT '',
`name` VARCHAR( 16 ) NOT NULL DEFAULT '',
`guid` INT( 10 ) UNSIGNED NOT NULL DEFAULT '0',
`team` INT( 10 ) UNSIGNED NOT NULL DEFAULT '0',
`ip` VARCHAR( 16 ) NOT NULL DEFAULT '',
`damage` INT( 10 ) UNSIGNED NOT NULL DEFAULT '0',
`healing` INT( 10 ) UNSIGNED NOT NULL DEFAULT '0',
`killing_blows` INT( 10 ) UNSIGNED NOT NULL DEFAULT '0'
) ENGINE = InnoDB CHARACTER SET utf8 COLLATE utf8_general_ci;