--
UPDATE `creature_template` SET `npcflag`=`npcflag`|1 WHERE `entry`=29344; 

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9806;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,9806,0,0,0,9,0,12807,0,0,0,0,0,'','Show gossip menu option only if player has quest(12807) ''The Story Thus Far...''');
