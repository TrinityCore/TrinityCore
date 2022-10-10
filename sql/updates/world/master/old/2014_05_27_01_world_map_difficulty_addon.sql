CREATE TABLE `map_difficulty_addon` (
  `mapId` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `difficulty` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `resetTime` int(11) unsigned NOT NULL DEFAULT '0',
  `maxPlayers` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `hasErrorMessage` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `comment` char(64) NOT NULL DEFAULT '',
  PRIMARY KEY (`mapId`, `difficulty`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Map Difficulty Addon';

INSERT INTO `map_difficulty_addon` (`mapId`, `difficulty`, `resetTime`, `maxPlayers`, `hasErrorMessage`) VALUE(0, 0, 0, 0, 0); -- Eastern Kingdoms
-- no 10 or 25 difficulties for 169 (Emerald Dream)
INSERT INTO `map_difficulty_addon` (`mapId`, `difficulty`, `resetTime`, `maxPlayers`, `hasErrorMessage`) VALUE(169, 3, 604800, 10, 0); -- Emerald Dream

-- no regular difficulty for 637 (Abyssal Maw Exterior)
INSERT INTO `map_difficulty_addon` (`mapId`, `difficulty`, `resetTime`, `maxPlayers`, `hasErrorMessage`) VALUE(637, 1, 0, 5, 0); -- Abyssal Maw Exterior
-- no heroic difficulty for 637 (Abyssal Maw Exterior)
INSERT INTO `map_difficulty_addon` (`mapId`, `difficulty`, `resetTime`, `maxPlayers`, `hasErrorMessage`) VALUE(637, 2, 86400, 5, 0); -- Abyssal Maw Exterior

-- no normal scenario difficulty difficulty for 999 (Theramore''s Fall (H))
INSERT INTO `map_difficulty_addon` (`mapId`, `difficulty`, `resetTime`, `maxPlayers`, `hasErrorMessage`) VALUE(999, 12, 0, 5, 0); -- Theramore''s Fall (H)
-- no normal scenario difficulty difficulty for 1000 (Theramore''s Fall (A))
INSERT INTO `map_difficulty_addon` (`mapId`, `difficulty`, `resetTime`, `maxPlayers`, `hasErrorMessage`) VALUE(1000, 12, 0, 5, 0); -- Theramore''s Fall (A)

-- no normal scenario difficulty difficulty for 1005 (A Brewing Storm)
INSERT INTO `map_difficulty_addon` (`mapId`, `difficulty`, `resetTime`, `maxPlayers`, `hasErrorMessage`) VALUE(1005, 12, 0, 5, 0); -- A Brewing Storm
-- no heroic scenario difficulty difficulty for 1005 (A Brewing Storm)
INSERT INTO `map_difficulty_addon` (`mapId`, `difficulty`, `resetTime`, `maxPlayers`, `hasErrorMessage`) VALUE(1005, 11, 0, 3, 0); -- A Brewing Storm

-- no normal scenario difficulty difficulty for 1030 (Crypt of Forgotten Kings)
INSERT INTO `map_difficulty_addon` (`mapId`, `difficulty`, `resetTime`, `maxPlayers`, `hasErrorMessage`) VALUE(1030, 12, 0, 5, 0); -- Crypt of Forgotten Kings
-- no heroic scenario difficulty difficulty for 1030 (Crypt of Forgotten Kings)
INSERT INTO `map_difficulty_addon` (`mapId`, `difficulty`, `resetTime`, `maxPlayers`, `hasErrorMessage`) VALUE(1030, 11, 0, 3, 0); -- Crypt of Forgotten Kings

-- no normal scenario difficulty difficulty for 1031 (Arena of Annihilation)
INSERT INTO `map_difficulty_addon` (`mapId`, `difficulty`, `resetTime`, `maxPlayers`, `hasErrorMessage`) VALUE(1031, 12, 0, 5, 0); -- Arena of Annihilation

-- no normal scenario difficulty difficulty for 1035 (Temple of Kotmogu)
INSERT INTO `map_difficulty_addon` (`mapId`, `difficulty`, `resetTime`, `maxPlayers`, `hasErrorMessage`) VALUE(1035, 12, 0, 5, 0); -- Temple of Kotmogu

-- no normal scenario difficulty difficulty for 1048 (Unga Ingoo)
INSERT INTO `map_difficulty_addon` (`mapId`, `difficulty`, `resetTime`, `maxPlayers`, `hasErrorMessage`) VALUE(1048, 12, 0, 5, 0); -- Unga Ingoo

-- no normal scenario difficulty difficulty for 1050 (Assault on Zan'vess)
INSERT INTO `map_difficulty_addon` (`mapId`, `difficulty`, `resetTime`, `maxPlayers`, `hasErrorMessage`) VALUE(1050, 12, 0, 5, 0); -- Assault on Zan''vess
-- no heroic scenario difficulty difficulty for 1050 (Assault on Zan'vess)
INSERT INTO `map_difficulty_addon` (`mapId`, `difficulty`, `resetTime`, `maxPlayers`, `hasErrorMessage`) VALUE(1050, 11, 0, 3, 0); -- Assault on Zan''vess

-- no normal scenario difficulty difficulty for 1051 (Brewmoon Festival)
INSERT INTO `map_difficulty_addon` (`mapId`, `difficulty`, `resetTime`, `maxPlayers`, `hasErrorMessage`) VALUE(1051, 12, 0, 5, 0); -- Brewmoon Festival

-- no normal scenario difficulty difficulty for 1095 (Dagger in the Dark)
INSERT INTO `map_difficulty_addon` (`mapId`, `difficulty`, `resetTime`, `maxPlayers`, `hasErrorMessage`) VALUE(1095, 12, 0, 5, 0); -- Dagger in the Dark
-- no heroic scenario difficulty difficulty for 1095 (Dagger in the Dark)
INSERT INTO `map_difficulty_addon` (`mapId`, `difficulty`, `resetTime`, `maxPlayers`, `hasErrorMessage`) VALUE(1095, 11, 0, 3, 0); -- Dagger in the Dark

-- no normal scenario difficulty difficulty for 1099 (Naval Battle Scenario)
INSERT INTO `map_difficulty_addon` (`mapId`, `difficulty`, `resetTime`, `maxPlayers`, `hasErrorMessage`) VALUE(1099, 12, 0, 5, 0); -- Naval Battle Scenario
-- no heroic scenario difficulty difficulty for 1099 (Naval Battle Scenario)
INSERT INTO `map_difficulty_addon` (`mapId`, `difficulty`, `resetTime`, `maxPlayers`, `hasErrorMessage`) VALUE(1099, 11, 0, 3, 0); -- Naval Battle Scenario

-- no normal scenario difficulty difficulty for 1102 (Domination Point)
INSERT INTO `map_difficulty_addon` (`mapId`, `difficulty`, `resetTime`, `maxPlayers`, `hasErrorMessage`) VALUE(1102, 12, 0, 5, 0); -- Domination Point

-- no normal scenario difficulty difficulty for 1103 (Lion''s Landing)
INSERT INTO `map_difficulty_addon` (`mapId`, `difficulty`, `resetTime`, `maxPlayers`, `hasErrorMessage`) VALUE(1103, 12, 0, 5, 0); -- Lion''s Landing

-- no normal scenario difficulty difficulty for 1104 (A Little Patience)
INSERT INTO `map_difficulty_addon` (`mapId`, `difficulty`, `resetTime`, `maxPlayers`, `hasErrorMessage`) VALUE(1104, 12, 0, 5, 0); -- A Little Patience

-- no normal scenario difficulty difficulty for 1112 (Pursuing the Black Harvest)
INSERT INTO `map_difficulty_addon` (`mapId`, `difficulty`, `resetTime`, `maxPlayers`, `hasErrorMessage`) VALUE(1112, 12, 0, 5, 0); -- Pursuing the Black Harvest

-- no normal scenario difficulty difficulty for 1122 (City Siege - Mogu Island Progression Scenario)
INSERT INTO `map_difficulty_addon` (`mapId`, `difficulty`, `resetTime`, `maxPlayers`, `hasErrorMessage`) VALUE(1122, 12, 0, 5, 0); -- City Siege - Mogu Island Progression Scenario

-- no normal scenario difficulty difficulty for 1123 (Lightning Forge - Mogu Island Progression Scenario)
INSERT INTO `map_difficulty_addon` (`mapId`, `difficulty`, `resetTime`, `maxPlayers`, `hasErrorMessage`) VALUE(1123, 12, 0, 5, 0); -- Lightning Forge - Mogu Island Progression Scenario

-- no normal scenario difficulty difficulty for 1124 (Shipyard - Mogu Island Progression Scenario)
INSERT INTO `map_difficulty_addon` (`mapId`, `difficulty`, `resetTime`, `maxPlayers`, `hasErrorMessage`) VALUE(1124, 12, 0, 5, 0); -- Shipyard - Mogu Island Progression Scenario

-- no normal scenario difficulty difficulty for 1125 (Alliance Hub - Mogu Island Progression Scenario)
INSERT INTO `map_difficulty_addon` (`mapId`, `difficulty`, `resetTime`, `maxPlayers`, `hasErrorMessage`) VALUE(1125, 12, 0, 5, 0); -- Alliance Hub - Mogu Island Progression Scenario

-- no normal scenario difficulty difficulty for 1126 (Mogu Island Progression Events)
INSERT INTO `map_difficulty_addon` (`mapId`, `difficulty`, `resetTime`, `maxPlayers`, `hasErrorMessage`) VALUE(1126, 12, 0, 5, 0); -- Mogu Island Progression Events

-- no normal scenario difficulty difficulty for 1127 (Final Gate - Mogu Island Progression Scenario)
INSERT INTO `map_difficulty_addon` (`mapId`, `difficulty`, `resetTime`, `maxPlayers`, `hasErrorMessage`) VALUE(1127, 12, 0, 5, 0); -- Final Gate - Mogu Island Progression Scenario

-- no normal scenario difficulty difficulty for 1130 (Blood in the Snow)
INSERT INTO `map_difficulty_addon` (`mapId`, `difficulty`, `resetTime`, `maxPlayers`, `hasErrorMessage`) VALUE(1130, 12, 0, 5, 0); -- Blood in the Snow
-- no heroic scenario difficulty difficulty for 1130 (Blood in the Snow)
INSERT INTO `map_difficulty_addon` (`mapId`, `difficulty`, `resetTime`, `maxPlayers`, `hasErrorMessage`) VALUE(1130, 11, 0, 3, 0); -- Blood in the Snow

-- no normal scenario difficulty difficulty for 1131 (The Secrets of Ragefire)
INSERT INTO `map_difficulty_addon` (`mapId`, `difficulty`, `resetTime`, `maxPlayers`, `hasErrorMessage`) VALUE(1131, 12, 0, 5, 0); -- The Secrets of Ragefire
-- no heroic scenario difficulty difficulty for 1131 (The Secrets of Ragefire)
INSERT INTO `map_difficulty_addon` (`mapId`, `difficulty`, `resetTime`, `maxPlayers`, `hasErrorMessage`) VALUE(1131, 11, 0, 3, 0); -- The Secrets of Ragefire

-- no normal scenario difficulty difficulty for 1135 (Mogu Island Loot Room)
INSERT INTO `map_difficulty_addon` (`mapId`, `difficulty`, `resetTime`, `maxPlayers`, `hasErrorMessage`) VALUE(1135, 12, 0, 5, 0); -- Mogu Island Loot Room

-- no normal scenario difficulty difficulty for 1144 (Heart of the Old God Scenario)
INSERT INTO `map_difficulty_addon` (`mapId`, `difficulty`, `resetTime`, `maxPlayers`, `hasErrorMessage`) VALUE(1144, 12, 0, 5, 0); -- Heart of the Old God Scenario
-- no heroic scenario difficulty difficulty for 1144 (Heart of the Old God Scenario)
INSERT INTO `map_difficulty_addon` (`mapId`, `difficulty`, `resetTime`, `maxPlayers`, `hasErrorMessage`) VALUE(1144, 11, 0, 3, 0); -- Heart of the Old God Scenario

-- no normal scenario difficulty difficulty for 1148 (Proving Grounds)
INSERT INTO `map_difficulty_addon` (`mapId`, `difficulty`, `resetTime`, `maxPlayers`, `hasErrorMessage`) VALUE(1148, 12, 0, 5, 0); -- Proving Grounds
--
INSERT INTO `map_difficulty_addon` (`mapId`, `difficulty`, `resetTime`, `maxPlayers`, `hasErrorMessage`) VALUE(1148, 1, 0, 5, 0); -- Proving Grounds
