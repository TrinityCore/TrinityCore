-- 
ALTER TABLE `respawn`
	ADD COLUMN `teamId` TINYINT(3) UNSIGNED NOT NULL COMMENT 'Team Identifier for Faction splitted Maps' AFTER `instanceId`,
    DROP PRIMARY KEY,
	ADD PRIMARY KEY (`type`, `spawnId`, `instanceId`, `teamId`);

ALTER TABLE `corpse`
	ADD COLUMN `mapTeamId` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0' COMMENT 'Team Identifier for Faction splitted Maps' AFTER `instanceId`;
