/*
-- Vizzklick
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=1301;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,1301,1934,0,0,7,0,197,230,0,0,0,0,"","Show gossip text 1934 if player has Tailoring with skill level 230"),
(14,1301,1934,0,0,14,0,3379,0,0,0,0,0,"","Show gossip text 1934 if quest 'Shadoweaver' is not taken");
*/
