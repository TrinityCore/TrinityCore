-- Update arena_team table
ALTER TABLE `arena_team`
CHANGE `arenateamid` `arenaTeamId` INT(10) UNSIGNED DEFAULT '0' NOT NULL,
CHANGE `captainguid` `captainGuid` INT(10) UNSIGNED DEFAULT '0' NOT NULL,
CHANGE `BackgroundColor` `backgroundColor` INT(10) UNSIGNED DEFAULT '0' NOT NULL,
CHANGE `EmblemStyle` `emblemStyle` TINYINT(3) UNSIGNED DEFAULT '0' NOT NULL,
CHANGE `EmblemColor` `emblemColor` INT(10) UNSIGNED DEFAULT '0' NOT NULL,
CHANGE `BorderStyle` `borderStyle` TINYINT(3) UNSIGNED DEFAULT '0' NOT NULL,
CHANGE `BorderColor` `borderColor` INT(10) UNSIGNED DEFAULT '0' NOT NULL,
ADD COLUMN `rating` SMALLINT(5) UNSIGNED NOT NULL AFTER `type`,
ADD COLUMN `seasonGames` SMALLINT(5) UNSIGNED DEFAULT '0' NOT NULL AFTER `rating`,
ADD COLUMN `seasonWins` SMALLINT(5) UNSIGNED DEFAULT '0' NOT NULL AFTER `seasonGames`,
ADD COLUMN `weekGames` SMALLINT(5) UNSIGNED DEFAULT '0' NOT NULL AFTER `seasonWins`,
ADD COLUMN `weekWins` SMALLINT(5) UNSIGNED DEFAULT '0' NOT NULL AFTER `weekGames`,
ADD COLUMN `rank` INT(10) UNSIGNED NOT NULL AFTER `weekWins`;

-- Move data from arena_team_stats to new columns in arena_team
UPDATE `arena_team` a, `arena_team_stats` s SET
`a`.`rating` = `s`.`rating`,
`a`.`seasonGames` = `s`.`played`,
`a`.`seasonWins` = `s`.`wins2`,
`a`.`weekGames` = `s`.`games`,
`a`.`weekWins` = `s`.`wins`,
`a`.`rank` = `s`.`rank`
WHERE `a`.`arenaTeamId` = `s`.`arenateamid`;

-- Remove arena_team_stats table
DROP TABLE `arena_team_stats`;

-- Update arena_team_member table
ALTER TABLE `arena_team_member`
CHANGE `arenateamid` `arenaTeamId` INT(10) UNSIGNED DEFAULT '0' NOT NULL,
CHANGE `played_week` `weekGames` SMALLINT(5) UNSIGNED DEFAULT '0' NOT NULL,
CHANGE `wons_week` `weekWins` SMALLINT(5) UNSIGNED DEFAULT '0' NOT NULL,
CHANGE `played_season` `seasonGames` SMALLINT(5) UNSIGNED DEFAULT '0' NOT NULL,
CHANGE `wons_season` `seasonWins` SMALLINT(5) UNSIGNED DEFAULT '0' NOT NULL,
ADD COLUMN `personalRating` SMALLINT(5) UNSIGNED DEFAULT '0' NOT NULL AFTER `seasonWins`;

-- Update character_arena_stats table
ALTER TABLE `character_arena_stats`
CHANGE `personal_rating` `personalRating` SMALLINT(5) NOT NULL,
CHANGE `matchmaker_rating` `matchMakerRating` SMALLINT(5) NOT NULL;
