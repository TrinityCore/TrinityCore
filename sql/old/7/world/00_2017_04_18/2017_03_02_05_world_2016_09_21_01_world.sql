UPDATE `smart_scripts` SET `event_flags`=512 WHERE  `entryorguid`=27409 AND `source_type`=0;
UPDATE `smart_scripts` SET `event_flags`=512 WHERE  `entryorguid`=2740900 AND `source_type`=9;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=48682;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 2, 48682, 0, 0, 31, 0, 3, 27417, 0, 0, 0, 0, '', 'Escape from Silverbrook - Periodic Dummy targets Silverbrook Worgen');
