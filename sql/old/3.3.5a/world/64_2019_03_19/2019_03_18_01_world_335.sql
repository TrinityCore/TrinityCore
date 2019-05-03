-- 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 4362 AND `ConditionTypeOrReference`=30;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`, `NegativeCondition`) VALUES
(15, 4362, 0, 0, 30, 177491, 10, 0, 0, '', "Hide the gossip option if the gob is alreay spawned",1),
(15, 4362, 0, 2, 30, 177491, 10, 0, 0, '', "Hide the gossip option if the gob is alreay spawned",1),
(15, 4362, 1, 1, 30, 177491, 10, 0, 0, '', "Hide the gossip option if the gob is alreay spawned",1),
(15, 4362, 1, 3, 30, 177491, 10, 0, 0, '', "Hide the gossip option if the gob is alreay spawned",1);
