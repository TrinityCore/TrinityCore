--

/*
-- Add TriggersId, it exists in leaked CreatureMap
ALTER TABLE `creature_template` ADD COLUMN `TriggersId` int unsigned NOT NULL DEFAULT '0' AFTER `StringId`;

DROP TABLE IF EXISTS `action_triggers_name`;
CREATE TABLE `action_triggers_name` (
  `Id` int unsigned NOT NULL,
  `Name` char(128) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '',
  PRIMARY KEY (`Id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

DROP TABLE IF EXISTS `action_triggers`;
CREATE TABLE `action_triggers` (
  `Id` int unsigned NOT NULL,
  `Index` smallint unsigned NOT NULL DEFAULT '0',
  `Chance` tinyint unsigned NOT NULL DEFAULT '100',
  `Flags` int unsigned NOT NULL DEFAULT '0',
  `CombatCondition` int NOT NULL DEFAULT '-1',
  `TriggerId` tinyint unsigned NOT NULL DEFAULT '0',
  `TriggerParam1` int unsigned NOT NULL DEFAULT '0',
  `TriggerParam2` int unsigned NOT NULL DEFAULT '0',
  `ActionSetId` int unsigned NOT NULL,
  `RepeatMin` int unsigned NOT NULL DEFAULT '0',
  `RepeatMax` int unsigned NOT NULL DEFAULT '0',
  `Comment` char(128) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '',
  PRIMARY KEY (`Id`,`Index`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

DROP TABLE IF EXISTS `action_set_name`;
CREATE TABLE `action_set_name` (
  `Id` int unsigned NOT NULL,
  `Flags` int unsigned NOT NULL DEFAULT '0',
  `Priority` tinyint unsigned NOT NULL DEFAULT '0',
  `Name` char(128) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '',
  PRIMARY KEY (`Id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

DROP TABLE IF EXISTS `action_set`;
CREATE TABLE `action_set` (
  `Id` int unsigned NOT NULL,
  `Index` smallint unsigned NOT NULL,
  `Type` smallint unsigned NOT NULL,
  `Unit` tinyint unsigned NOT NULL,
  `Point` int unsigned NOT NULL DEFAULT '0',
  `Path` int unsigned NOT NULL DEFAULT '0',
  `TimeA` int unsigned NOT NULL DEFAULT '0',
  `MoveSpeed` tinyint unsigned NOT NULL DEFAULT '0',
  `StringId` varchar(64) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `TimeB` int unsigned NOT NULL DEFAULT '0',
  `LinearPath` tinyint unsigned NOT NULL DEFAULT '0',
  `CircularPath` tinyint unsigned NOT NULL DEFAULT '0',
  `FlightPath` tinyint unsigned NOT NULL DEFAULT '0',
  `TargetType` tinyint unsigned NOT NULL DEFAULT '0',
  `TargetParam1` int unsigned NOT NULL DEFAULT '0',
  `TargetParam2` int unsigned NOT NULL DEFAULT '0',
  `TargetParam3` int unsigned NOT NULL DEFAULT '0',
  `TargetParam4` int unsigned NOT NULL DEFAULT '0',
  `Extra0` double NOT NULL DEFAULT '0',
  `Extra1` double NOT NULL DEFAULT '0',
  `Extra2` double NOT NULL DEFAULT '0',
  `Extra3` double NOT NULL DEFAULT '0',
  `Extra4` double NOT NULL DEFAULT '0',
  `Comment` char(128) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '',
  PRIMARY KEY (`Id`,`Index`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

DELETE FROM `trinity_string` WHERE `entry` IN (5081,5082);
INSERT INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES
(5081,'Current Active Action Triggers: %s',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(5082,'Current Active Action Set: %s',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
*/
