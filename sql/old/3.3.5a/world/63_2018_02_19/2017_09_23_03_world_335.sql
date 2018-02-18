-- 
DELETE FROM `creature_text` WHERE `CreatureID`=16521 AND `ID`=3;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(16521, 0, 3, "None of you are to leave this valley alive.", 12, 0, 100, 0, 0, 0, 13429, 0, "Blood Elf Scout");
