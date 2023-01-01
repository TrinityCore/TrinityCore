--
DELETE FROM `creature_text` WHERE `CreatureID`=19255 AND `GroupID`=0 AND `ID`=4;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(19255, 0, 4, "The warchief's put a price on Arazzius's head! As of right now, that no-good piece of demon refuse is enemy number one.", 12, 1, 100, 1, 0, 0, 16391, 0, "General Krakork");
