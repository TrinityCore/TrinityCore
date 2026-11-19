DELETE FROM `creature_text` WHERE `CreatureID` IN (14509, 11347, 11348) AND `GroupId`=2;
DELETE FROM `creature_text` WHERE `CreatureID`=14509 AND `GroupId`=3;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(14509, 2, 0, "%s dies.", 16, 0, 100, 0, 0, 0, 12195, 0, "High Priest Thekal"),
(14509, 3, 0, "%s goes into a frenzy!", 16, 0, 100, 0, 0, 0, 1191, 0, "High Priest Thekal"),
(11347, 2, 0, "%s dies.", 16, 0, 100, 0, 0, 0, 10453, 0, "Zealoth Lor'khan"),
(11348, 2, 0, "%s dies.", 16, 0, 100, 0, 0, 0, 12195, 0, "Zealot Zath");
