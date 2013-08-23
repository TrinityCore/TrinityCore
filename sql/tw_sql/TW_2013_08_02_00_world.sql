SET @CGUID := 210018;

-- Spawn the Infinite Corruptor
DELETE FROM `creature` WHERE `guid`=@CGUID AND `id`=32273;
INSERT INTO `creature`(`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`,`orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID, 32273, 595, 2, 1, 2331.642, 1273.273, 132.9524, 3.717551, 7200, 0, 0);

-- Spawn the Guardian of time
DELETE FROM `creature` WHERE `guid` = @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+1, 32281, 595, 2, 1, 2321.489, 1268.383, 132.8507, 0.418879, 120, 0, 0);

-- Add Corruption of Time aura to the Guardian
DELETE FROM `creature_addon` WHERE `guid` = @CGUID+1;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(@CGUID+1, 0, 0, 0, 0, 0, 60451);

-- Spawn Time-Rift
DELETE FROM `creature` WHERE `guid` = @CGUID+2 AND `id` = 28409;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(@CGUID+2, 28409, 595, 2, 1, 0, 0, 2340.55, 1278.6, 133.312, 3.4767, 86400, 0, 0, 1, 0, 0, 0, 0, 0);

-- Guardian of Time's creature_text
DELETE FROM `creature_text` WHERE `entry` = 32281;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(32281, 0, 0, 'You have my thanks for saving my existence in this timeline. Now I must report back to my superiors. They must know immediately of what I just experienced.', 12, 0, 100, 0, 0, 0, 'Guardian of Time - SAY_SUCCESS');

-- Chromie's creature_text
DELETE FROM `creature_text` WHERE `entry` = '26527';
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(26527, 0, 0, 'Oh, no! Adventurers, something awful has happened! A colleague of mine has been captured by the Infinite Dragonflight, and they''re doing something horrible to him!$B$BKeeping Arthas is still your highest priority, but if you act fast you could help save a Guardian of Time!', 15, 0, 100, 0, 0, 0, 'Chromie'),
(26527, 1, 0, 'Adventurers, you must hurry! The Guardian of Time cannot last for much longer!', 15, 0, 100, 0, 0, 0, 'Chromie'),
(26527, 2, 0, 'I can barely sense the Guardian of Time! His timeline is fading quickly!', 15, 0, 100, 0, 0, 0, 'Chromie');

-- Corruption of Time implicit target conditions
DELETE FROM `conditions` WHERE`SourceEntry` = 60422 AND `SourceTypeOrReferenceId` = 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`)VALUES
(13, 1, 60422, 0, 0, 31, 0, 3, 32281, 0, 0, 0, 0,'','Infinite Corruptor - Corruption of Time');

-- Remove The Culling of Time achievement criteria from disables
DELETE FROM `disables` WHERE `entry` = 7494 AND `sourceType` = 4;

-- Adds immunites to the Infinite Corruptor
UPDATE `creature_template` SET `mechanic_immune_mask` = `mechanic_immune_mask` |1|2|4|16|32|64|256|512|1024|2048|4096|8192|65536|131072|8388608|33554432|67108864 WHERE `entry` = 32273;
