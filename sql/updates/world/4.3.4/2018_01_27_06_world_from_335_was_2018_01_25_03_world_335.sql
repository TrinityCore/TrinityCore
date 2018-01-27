/*
-- Master Smith Burninate --> Fix gossip conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=5962;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,5962,7121,0,0,8,0,7722,0,0,0,0,0,"","Show gossip text 7121 if player has quest 'What the Flux?' rewarded"),
(14,5962,7121,0,0,5,0,59,128,0,0,0,0,"","Show gossip text 7121 if player is exalted with Thorium Brotherhood");
*/
