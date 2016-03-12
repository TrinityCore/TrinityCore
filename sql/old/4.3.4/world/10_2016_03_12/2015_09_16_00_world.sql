-- Heroic Spawn - Earthrager Ptah
UPDATE `creature_template` SET `difficulty_entry_1`=48714 WHERE `entry`=39428;
UPDATE `creature_template` SET `minlevel`=87,`maxlevel`=87,`exp`=3,`faction`=16,`speed_walk`=2,`speed_run`=1.42857,`unit_flags`=32832,`mechanic_immune_mask`=536941137,`flags_extra`=1 WHERE `entry`=48714;

-- Heroic Spawn - Temple Guardian Anhuur
UPDATE `creature_template` SET `difficulty_entry_1`=49262 WHERE `entry`=39425;
UPDATE `creature_template` SET `minlevel`=87,`maxlevel`=87,`exp`=3,`faction`=16,`speed_walk`=2,`speed_run`=1.42857,`unit_class`=2,`unit_flags`=32832,`mechanic_immune_mask`=536941137,`flags_extra`=1 WHERE `entry`=49262;

-- Conditions -- Kilyana
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=89396;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 89396, 0, 0, 31, 0, 4, 0, 0, 0, 0, 0, '', 'Quicksand'),
(13, 2, 89396, 0, 0, 31, 0, 4, 0, 0, 0, 0, 0, '', 'Quicksand');
