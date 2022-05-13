ALTER TABLE `creature`
	ADD COLUMN `teamId` TINYINT(3) UNSIGNED NULL DEFAULT NULL COMMENT 'Team Identifier for Faction splitted Maps' AFTER `terrainSwapMap`;

ALTER TABLE `gameobject`
	ADD COLUMN `teamId` TINYINT(3) UNSIGNED NULL DEFAULT NULL COMMENT 'Team Identifier for Faction splitted Maps' AFTER `terrainSwapMap`;

ALTER TABLE `transports`
	ADD COLUMN `teamId` TINYINT(3) UNSIGNED NULL DEFAULT NULL COMMENT 'Team Identifier for Faction splitted Maps' AFTER `phasegroup`;