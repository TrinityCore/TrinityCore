/*
-- Show Bodley's gossip menu option 57006 id 2 only if quest 8996 is not rewarded
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 15 AND `SourceGroup`= 57006 AND `ConditionValue1`= 8996 AND `NegativeCondition`= 1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15, 57006, 2, 0, 0, 8, 0, 8996, 0, 0, 1, 0, '', 'Requires Quest 8996 Not Rewarded');
*/
