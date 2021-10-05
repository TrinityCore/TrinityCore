-- add missing EmoteState (GUID: 650005)
DELETE FROM `creature_addon` WHERE `guid` = 650005;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(650005, 0, 0, 0, 257, 415, 0, 0, 0, 0, '');

-- add missing EmoteState (GUID: 650017)
DELETE FROM `creature_addon` WHERE `guid` = 650017;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(650017, 0, 0, 0, 1, 613, 0, 0, 0, 0, '');

-- add missing EmoteState (GUID: 650051)
DELETE FROM `creature_addon` WHERE `guid` = 650051;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(650051, 0, 0, 0, 257, 641, 0, 0, 0, 0, '');

-- add missing EmoteState (GUID: 650065)
DELETE FROM `creature_addon` WHERE `guid` = 650065;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(650065, 0, 0, 0, 257, 641, 0, 0, 0, 0, '');

-- SAI Script for locus-researcher & rift-warden
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (132385, 132386);

-- SAI for GUID: 650030
SET @ENTRY := -650030;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ENTRY AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, 1, 0, 100, 1, 1000, 1000, 0, 0, 0, '', 11, 260888, 1, 0, 0, 0, 0, 10, 650039, 132397, 0, 0, 0, 0, 0, 'Cast Void Suppression on Bunny');

-- SAI for GUID: 650002
SET @ENTRY := -650002;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ENTRY AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, 1, 0, 100, 1, 1000, 1000, 0, 0, 0, '', 11, 260888, 1, 0, 0, 0, 0, 10, 650039, 132397, 0, 0, 0, 0, 0, 'Cast Void Suppression on Bunny');

-- SAI for GUID: 650003
SET @ENTRY := -650003;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ENTRY AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, 1, 0, 100, 1, 1000, 1000, 0, 0, 0, '', 11, 260888, 1, 0, 0, 0, 0, 10, 650039, 132397, 0, 0, 0, 0, 0, 'Cast Void Suppression on Bunny');

-- Condition for Spell_Target
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 260888;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 260888, 0, 0, 31, 0, 3, 132397, 0, 0, 0, 0, '', 'Spell target hit Bunny 132397');

-- SAI for GUID: 560056
SET @ENTRY := -650056;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ENTRY AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 2000, 5000, 2000, 5000, 0, '', 10, 1, 6, 274, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 5000ms and 5000ms repeat - play Random Emote');
