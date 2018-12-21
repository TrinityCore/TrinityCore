-- Add flying inhabit type to some flying creatures
UPDATE `creature_template` SET `InhabitType`= 4 WHERE `entry` IN (29239, 44880, 44475, 45166, 47943, 47790);

-- Change Sea Gulls to sit mode 
UPDATE `creature_template_addon` SET `bytes1`= 1 WHERE `entry`= 44880;

-- Add some creature addon datas
DELETE FROM `creature_addon` WHERE `guid` IN (334690, 334572, 334610, 334613);
INSERT INTO `creature_addon` (`guid`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
-- Dire Condor sitting state
(334690, 1, 1, 0, ''),
(334572, 1, 1, 0, ''),
(334610, 1, 1, 0, ''),
(334613, 1, 1, 0, '');

-- Removing some duplicate spawns
DELETE FROM `creature` WHERE `guid` IN (334607, 334694, 334855, 328324, 328052);
DELETE FROM `creature_addon` WHERE `guid` IN (334607, 334694, 334855, 328324);

-- Add random movement to some creature
UPDATE `creature` SET `MovementType`= 1, `spawndist`= 10 WHERE `id` IN (442, 423, 547, 426, 712, 1083, 548, 1186, 1195, 2098, 1172, 1176, 1174, 44627, 44620, 2729, 2732) AND `guid` NOT IN (334582, 334587, 334592, 334851, 334848, 334850, 334894, 334893, 334784, 334792, 334835) AND `MovementType`= 0;
UPDATE `creature` SET `MovementType`= 1, `spawndist`= 10 WHERE `guid` IN (335046, 335051, 335039);

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry`= 89160 AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 89160, 0, 0, 31, 0, 3, 47943, 0, 0, 0, '', 'Arcane Storm - Target Generic Camera Target');

-- Add trigger flag to some creatures
UPDATE `creature_template` SET `flags_extra`= 128 WHERE `entry` IN (47943, 48009);
