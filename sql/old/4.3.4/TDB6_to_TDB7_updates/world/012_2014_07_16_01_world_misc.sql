--
DELETE FROM `creature_template_addon` WHERE `entry`=23322;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(23322, 0, 0, 0, 4097, 0, '40849 40857');

UPDATE `creature_template` SET `AIName`='' WHERE  `entry`=23322;

DELETE FROM `smart_scripts` WHERE `entryorguid`=23322;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN(40825,40830);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 40825, 0, 0, 31, 0, 4, 0, 0, 1, 0, 0, '', 'Banishment Does not hit Player'),
(13, 1, 40830, 0, 0, 31, 0, 4, 0, 0, 1, 0, 0, '', 'Banishment Does not hit Player');
