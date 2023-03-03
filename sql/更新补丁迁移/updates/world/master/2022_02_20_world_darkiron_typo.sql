/*
**************************
*    BfaCore Reforged    *
**************************
*/

-- Fix Dark iron dwarf achievement
DELETE FROM `race_unlock_requirement` WHERE `RaceID`=34;
INSERT INTO `race_unlock_requirement` (`RaceID`, `expansion`, `achievementId`) VALUES
(34,7,12516);