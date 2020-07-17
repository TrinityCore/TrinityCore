-- 

DELETE FROM `creature_text` WHERE `CreatureID` IN (1124, 1397);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1124, 0, 0, "Have a taste of Frostmane magics.", 12, 14, 100, 0, 0, 0, 1910, 0, "Frostmane Shadowcaster"),
(1397, 0, 0, "Have a taste of Frostmane magics.", 12, 14, 100, 0, 0, 0, 1910, 0, "Frostmane Seer"),
(1397, 0, 1, "All you $R want is my weed.", 12, 14, 100, 0, 0, 0, 1911, 0, "Frostmane Seer");
