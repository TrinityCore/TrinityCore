DELETE FROM `class_expansion_requirement` WHERE `RaceID` IN (84, 85) AND `ClassID` IN (1, 2, 3, 4, 5, 7, 8, 9, 10);
INSERT INTO `class_expansion_requirement` (`ClassID`, `RaceID`, `ActiveExpansionLevel`, `AccountExpansionLevel`) VALUES
(1, 84, 10, 10),
(2, 84, 10, 10),
(3, 84, 10, 10),
(4, 84, 10, 10),
(5, 84, 10, 10),
(7, 84, 10, 10),
(8, 84, 10, 10),
(9, 84, 10, 10),
(10, 84, 10, 10),
(1, 85, 10, 10),
(2, 85, 10, 10),
(3, 85, 10, 10),
(4, 85, 10, 10),
(5, 85, 10, 10),
(7, 85, 10, 10),
(8, 85, 10, 10),
(9, 85, 10, 10),
(10, 85, 10, 10);

DELETE FROM `player_racestats` WHERE `race` IN (84, 85);
INSERT INTO `player_racestats` (`race`, `str`, `agi`, `sta`, `inte`) VALUES 
(84, 0, 0, 0, 0),
(85, 0, 0, 0, 0);

DELETE FROM `race_unlock_requirement` WHERE `raceID` IN (84, 85);
INSERT INTO `race_unlock_requirement` (`raceID`, `expansion`, `achievementId`) VALUES
(84, 10, 40307),
(85, 10, 40307);
