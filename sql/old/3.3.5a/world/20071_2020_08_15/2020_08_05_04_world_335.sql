-- Add BroadcastTextId to Glutton's texts, confirmed by https://www.youtube.com/watch?v=rCZU9MRtQ8s
UPDATE `creature_text` SET `BroadcastTextId` = 4515 WHERE `CreatureID` = 8567 AND `GroupID` = 2 AND `ID` = 0;
UPDATE `creature_text` SET `BroadcastTextId` = 4516 WHERE `CreatureID` = 8567 AND `GroupID` = 3 AND `ID` = 0;
-- Mismatches
UPDATE `creature_text` a LEFT JOIN `broadcast_text` b ON a.`BroadcastTextId` = b.`ID` SET a.`Text` = b.`Text` WHERE b.`Text1` = '' AND a.`Text` != b.`Text`;
