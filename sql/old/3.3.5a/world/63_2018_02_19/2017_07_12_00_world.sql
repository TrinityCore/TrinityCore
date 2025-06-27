-- 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=10040 AND `SourceEntry`=3;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,10040,3,0,0,28,0,13231,0,0,0,0,0,'','Only show gossip option 3 if player has quest 13231 Complete'),
(15,10040,3,0,0,14,0,13232,0,0,0,0,0,'','Only show gossip option 3 if player has quest 13232 Not Taken'),
(15,10040,3,0,1,8,0,13231,0,0,0,0,0,'','Only show gossip option 3 if player has quest 13231 Rewarded'),
(15,10040,3,0,1,14,0,13232,0,0,0,0,0,'','Only show gossip option 3 if player has quest 13232 Not Taken');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceEntry`=13232;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19,0,13232,0,0,28,0,13231,0,0,0,0,0,'','Quest 13232 Finish Me! Requires Quest 13231 The Broken Front to be complete'),
(19,0,13232,0,1,8,0,13231,0,0,0,0,0,'','Quest 13232 Finish Me! Requires Quest 13231 The Broken Front to be rewarded');
