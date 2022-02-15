-- 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9769;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 9769, 0, 0, 0, 28, 0, 12757, 0, 0, 0, 0, 0, "", "Show gossip option only if player has quest 'Scarlet Armies Approach...' complete AND"),
(15, 9769, 0, 0, 0, 30, 0, 191155, 30, 0, 1, 0, 0, "", "Show gossip option only if gameobject Portal to Acherus is NOT within 30 yards");
