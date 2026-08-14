-- _addon
DELETE FROM `creature_addon` WHERE `guid` IN (276261,276238);
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(276261, 0, 0, 8, 0, 1, 1, 0, 0, 0, 0, 0, 0, '79488'), -- Stormwind Investigator - 79488 - Apply Quest Invis Zone 0
(276238, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, '79488'); -- Stormwind Investigator - 79488 - Apply Quest Invis Zone 0

-- Difficulty
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x100, `VerifiedBuild`=63906 WHERE (`Entry`=237 AND `DifficultyID`=0); -- 237 (Farmer Furlbrow) - Sessile
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63906 WHERE (`Entry`=42309 AND `DifficultyID`=0); -- 42309 (Stormwind Investigator) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x100, `VerifiedBuild`=63906 WHERE (`Entry`=582 AND `DifficultyID`=0); -- 582 (Old Blanchy) - Sessile
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x100, `VerifiedBuild`=63906 WHERE (`Entry`=238 AND `DifficultyID`=0); -- 238 (Verna Furlbrow) - Sessile

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID`=42309 AND `GroupID` IN (0, 1, 2);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(42309, 0, 0, 'It\'s a bloodbath, lieutenant. They\'ve been murdered.', 12, 7, 100, 1, 0, 0, 42224, 'Stormwind Investigator to Player'),
(42309, 1, 0, 'Given the body temperature, I\'d say they\'ve been dead no more than 6 hours.', 12, 7, 100, 0, 0, 0, 42225, 'Stormwind Investigator to Player'),
(42309, 2, 0, 'Damn shame what they did to Old Blanchy...', 12, 7, 100, 0, 0, 0, 42226, 'Stormwind Investigator to Player');

DELETE FROM `creature_text` WHERE `CreatureID`=42308 AND `GroupID` IN (0, 1, 2);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(42308, 0, 0, 'No kidding, rookie...', 12, 7, 100, 273, 0, 0, 42227, 'Lieutenant Horatio Laine to Player'),
(42308, 1, 0, 'Looks like they really put the cart...', 12, 7, 100, 0, 0, 0, 42228, 'Lieutenant Horatio Laine to Player'),
(42308, 2, 0, '...before the horse.', 12, 7, 100, 0, 0, 0, 42229, 'Lieutenant Horatio Laine to Player');

-- Clientside area trigger 5983 smart ai
SET @ENTRY := 5983;
DELETE FROM `areatrigger_scripts` WHERE `entry` = @ENTRY;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES (@ENTRY, 'SmartTrigger');
DELETE FROM `smart_scripts` WHERE `source_type` = 2 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 2, 0, 0, 46, 0, 100, 0, 5983, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 0, 10, 276258, 42308, 0, 0, 0, 0, 0, 'On trigger - Creature Lieutenant Horatio Laine (42308) with guid 276258 (fetching): Set creature data #1 to 1', '');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 5983 AND `SourceId` = 2;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 1, 5983, 2, 0, 14, 0, 26209, 0, 0, '', 0, 'Action invoker has never finished nor has active quest Murder Was The Case That They Gave Me (26209)');

-- Lieutenant Horatio Laine smart ai
SET @ENTRY := 42308;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 1, 38, 0, 100, 0, 1, 1, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On data[1] set to 1 - Self: Set walk', ''),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 80, 4230800, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On data[1] set to 1 - Self: Start timed action list id #Lieutenant Horatio Laine #0 (4230800) (update out of combat)', ''),
(@ENTRY, 0, 2, 0, 34, 0, 100, 0, 8, 1, 0, 0, 0, 90, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type POINT_MOTION_TYPE inform, point 1 - Self: Set stand state to KNEEL', ''),
(@ENTRY, 0, 3, 0, 34, 0, 100, 0, 8, 2, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type POINT_MOTION_TYPE inform, point 2 - Self: Set orientation to home position orientation', '');

-- Timed list 4230800 smart ai
SET @ENTRY := 4230800;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 0, 10, 276261, 42309, 0, 0, 0, 0, 0, 'After 0 seconds - Creature Stormwind Investigator (42309) with guid 276261 (fetching): Set creature data #0 to 1', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 0, 10, 276261, 42309, 0, 0, 0, 0, 0, 'After 7 seconds - Creature Stormwind Investigator (42309) with guid 276261 (fetching): Set creature data #1 to 1', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 0, 45, 2, 1, 0, 0, 0, 0, 0, 10, 276238, 42309, 0, 0, 0, 0, 0, 'After 7 seconds - Creature Stormwind Investigator (42309) with guid 276238 (fetching): Set creature data #2 to 1', ''),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 0, 69, 1, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -9851.94, 910.24, 29.9428, 0, 'After 6 seconds - Self: Move to position (-9851.94, 910.24, 29.9428, 0) (point id 1)', ''),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 150, 150, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0.15 seconds - Self: Talk 0 to invoker', ''),
(@ENTRY, 9, 5, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'After 5 seconds - Self: Talk 1 to invoker', ''),
(@ENTRY, 9, 6, 0, 0, 0, 100, 0, 1500, 1500, 0, 0, 0, 85, 78935, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'After 1.5 seconds - None: Cast spell 78935 on self', ''),
(@ENTRY, 9, 7, 0, 0, 0, 100, 0, 2300, 2300, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'After 2.3 seconds - Self: Talk 2 to invoker', ''),
(@ENTRY, 9, 8, 0, 0, 0, 100, 0, 10500, 10500, 0, 0, 0, 69, 2, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -9849.86, 914.962, 30.2703, 0, 'After 10.5 seconds - Self: Move to position (-9849.86, 914.962, 30.2703, 0) (point id 2)', ''),
(@ENTRY, 9, 9, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 91, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Remove stand state KNEEL', ''),
(@ENTRY, 9, 10, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 28, 78935, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Remove aura due to spell  78935', '');

-- Stormwind Investigator smart ai
SET @ENTRY := 42309;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 38, 0, 100, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'On data[0] set to 1 - Self: Talk 0 to invoker', ''),
(@ENTRY, 0, 1, 0, 38, 0, 100, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'On data[1] set to 1 - Self: Talk 1 to invoker', ''),
(@ENTRY, 0, 2, 0, 38, 0, 100, 0, 2, 1, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'On data[2] set to 1 - Self: Talk 2 to invoker', '');
