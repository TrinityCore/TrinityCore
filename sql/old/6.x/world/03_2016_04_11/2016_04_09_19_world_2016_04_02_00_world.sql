DELETE FROM `creature_addon` WHERE `guid` IN(106613,106612,106611,106879,106509);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(106613, 0, 0, 0, 4097, 0, '29266'),
(106612, 0, 0, 0, 4097, 0, '29266'),
(106611, 0, 0, 0, 4097, 0, '29266'),
(106879, 0, 0, 0, 4097, 0, '29266'),
(106509, 0, 0, 0, 4097, 0, '29266');


UPDATE `creature` SET `unit_flags`=570721024 WHERE  `guid` IN(106613,106612,106611,106879,106509);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=23666;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 4, 23666, 0, 0, 1, 1, 29266, 0, 0, 1, 0, 0, '', 'Winterskorn Berserker only run SAI if Winterskorn Berserker does not have aura Permanent Feign Death');
