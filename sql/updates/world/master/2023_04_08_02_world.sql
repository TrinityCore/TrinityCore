UPDATE `creature_template` SET `AIName`='' WHERE `entry`=4262;

DELETE FROM `creature_template_gossip` WHERE `CreatureID`=4262 AND `MenuID`=10265;
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(4262, 10265, 48676);

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=4262;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceId`=0 AND `SourceEntry`=4262;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup` IN (2352, 10265) AND `SourceEntry`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 2352, 0, 0, 0, 23, 1, 702, 0, 0, 1, 0, 0, '', 'Show gossip menu if creature is not located in Rut''theran Village'),
(14, 10265, 0, 0, 0, 23, 1, 702, 0, 0, 0, 0, 0, '', 'Show gossip menu if creature is located in Rut''theran Village');
