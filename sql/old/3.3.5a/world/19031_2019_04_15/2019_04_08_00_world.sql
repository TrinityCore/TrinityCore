-- 
DELETE FROM `creature_text` WHERE `CreatureID` = 14459;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `comment`, `BroadcastTextId`) VALUES 
(14459, 0, 0, '%s flee as the controlling power of the orb is drained.', 16, 0, 100, 0, 0, 0, 'Nefarian''s Troops ', 9592);
