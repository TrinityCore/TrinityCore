DROP TABLE IF EXISTS `battleground_player_score_template`;
CREATE TABLE `battleground_player_score_template` (
  `MapID` int NOT NULL,
  `BattlemasterListID` int unsigned NOT NULL DEFAULT '0',
  `PvpStatID` int unsigned NOT NULL DEFAULT '0',
  `OrderIndex` tinyint unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`MapID`,`BattlemasterListID`,`PvpStatID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

INSERT INTO `battleground_player_score_template` (`MapID`, `BattlemasterListID`, `PvpStatID`, `OrderIndex`) VALUES
-- Arathi Basin
(2107, 0, 926, 0), -- Assault Base
(2107, 0, 927, 1), -- Defend Base
-- Alterac Valley
(30, 0, 61, 0), -- Assault Tower
(30, 0, 63, 1), -- Assault Graveyard
(30, 0, 64, 2), -- Defend Tower
(30, 0, 65, 3), -- Defend Graveyard
(30, 0, 82, 4), -- Secondary Objective
-- Eye of the Storm
(566, 0, 186, 0), -- Capture flag
-- Isle of Conquest
(628, 0, 245, 0), -- assault base
(628, 0, 246, 1), -- defend base
-- Warsong Gulch
(2106, 0, 928, 0), -- Capture Flag
(2106, 0, 929, 1), -- Return Flag
-- Strand of the Ancients
(607, 0, 231, 0), -- Gates Destroyed
(607, 0, 232, 0); -- Demolishers Destroyed
