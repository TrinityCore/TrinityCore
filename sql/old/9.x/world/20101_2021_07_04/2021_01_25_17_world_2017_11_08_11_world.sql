-- 
DELETE FROM `creature_text` WHERE `CreatureID`=28557 AND `ID` BETWEEN 5 AND 7;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(28557, 0, 5, "Please, no! Spare me!", 12, 0, 100, 0, 0, 0, 29009, 0, "Scarlet Peasant"),
(28557, 0, 6, "Don't kill me! I only took this job for the benefits!", 12, 0, 100, 0, 0, 0, 29010, 0, "Scarlet Peasant"),
(28557, 0, 7, "Let me live! I'll do whatever you say!", 12, 0, 100, 0, 0, 0, 29011, 0, "Scarlet Peasant");
