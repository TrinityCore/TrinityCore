--  DB/Gossip: fix gossip conditions for NPC Librarian Serrah
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14, 15) AND `SourceGroup`=9495;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 9495, 12780, 0, 0, 8, 0, 11912, 0, 0, 1, 0, 0, "", "Gossip text 12780 requires quest Nuts for Berries NOT rewarded"),
(14, 9495, 12781, 0, 0, 8, 0, 11912, 0, 0, 0, 0, 0, "", "Gossip text 12781 requires quest Nuts for Berries rewarded"),
(15, 9495, 0, 0, 0, 8, 0, 11912, 0, 0, 0, 0, 0, "", "Gossip option 0 requires quest Nuts for Berries rewarded");
