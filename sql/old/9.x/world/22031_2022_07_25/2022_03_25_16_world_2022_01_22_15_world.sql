--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14, 15) AND `SourceGroup`=9262;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 9262, 12577, 0, 0, 8, 0, 11946, 0, 0, 1, 0, 0, "", "Show gossip text if quest 'Keristrasza' is not rewarded"),
(14, 9262, 12576, 0, 0, 8, 0, 11946, 0, 0, 0, 0, 0, "", "Show gossip text if quest 'Keristrasza' is rewarded"),
(15, 9262, 0, 0, 0, 47, 0, 11957, 10, 0, 0, 0, 0, "", "Show gossip option if player has quest 'Saragosa's End' in progress or completed"),
(15, 9262, 1, 0, 0, 47, 0, 11967, 10, 0, 0, 0, 0, "", "Show gossip option if player has quest 'Mustering the Reds' in progress or completed");
