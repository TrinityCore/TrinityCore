UPDATE `creature_template` SET `scriptname`='' WHERE `entry`=3052;
/*
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=24 AND `SourceEntry`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,24,0,0,0,8,0,770,0,0,1,0,0,'','Show gossip menu option if player has no quest ''The Demon Scarred Cloak'' rewarded');
*/
