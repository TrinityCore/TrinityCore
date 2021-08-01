DELETE FROM `conditions` WHERE `SourceEntry`= 71725 AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 71725, 0, 0, 31, 0, 3, 38345, 0, 0, 0, '', 'Unlocking - Target Captured Brave');

UPDATE `creature_template` SET `ScriptName`= 'npc_mulgore_captured_brave' WHERE `entry`= 38345;

-- Quilboar Cage
SET @ENTRY := 202112;
DELETE FROM `smart_scripts` WHERE `entryOrGuid` = @ENTRY AND `source_type` = 1;
UPDATE `gameobject_template` SET `AIName` = "SmartGameObjectAI" WHERE `entry` = @ENTRY;

-- Quilboar Cage
SET @ENTRY := -214745;
DELETE FROM `smart_scripts` WHERE `entryOrGuid` = @ENTRY AND `source_type` = 1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 1, 0, 0, 70, 0, 100, 1, 2, 0, 0, 0, 41, 5000, 60, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On loot state changed to GO_ACTIVATED - Self: Despawn in 5 s respawn in 60 seconds"),
(@ENTRY, 1, 1, 0, 11, 0, 100, 0, 0, 0, 0, 0, 133, 0, 295349, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "When just created - Respawn NPC with guid 295349");

SET @ENTRY := -214746;
DELETE FROM `smart_scripts` WHERE `entryOrGuid` = @ENTRY AND `source_type` = 1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 1, 0, 0, 70, 0, 100, 1, 2, 0, 0, 0, 41, 5000, 60, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On loot state changed to GO_ACTIVATED - Self: Despawn in 5 s respawn in 60 seconds"),
(@ENTRY, 1, 1, 0, 11, 0, 100, 0, 0, 0, 0, 0, 133, 0, 295350, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "When just created - Respawn NPC with guid 295349");

SET @ENTRY := -214748;
DELETE FROM `smart_scripts` WHERE `entryOrGuid` = @ENTRY AND `source_type` = 1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 1, 0, 0, 70, 0, 100, 1, 2, 0, 0, 0, 41, 5000, 60, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On loot state changed to GO_ACTIVATED - Self: Despawn in 5 s respawn in 60 seconds"),
(@ENTRY, 1, 1, 0, 11, 0, 100, 0, 0, 0, 0, 0, 133, 0, 295363, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "When just created - Respawn NPC with guid 295349");

SET @ENTRY := -214749;
DELETE FROM `smart_scripts` WHERE `entryOrGuid` = @ENTRY AND `source_type` = 1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 1, 0, 0, 70, 0, 100, 1, 2, 0, 0, 0, 41, 5000, 60, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On loot state changed to GO_ACTIVATED - Self: Despawn in 5 s respawn in 60 seconds"),
(@ENTRY, 1, 1, 0, 11, 0, 100, 0, 0, 0, 0, 0, 133, 0, 295410, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "When just created - Respawn NPC with guid 295349");

SET @ENTRY := -214757;
DELETE FROM `smart_scripts` WHERE `entryOrGuid` = @ENTRY AND `source_type` = 1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 1, 0, 0, 70, 0, 100, 1, 2, 0, 0, 0, 41, 5000, 60, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On loot state changed to GO_ACTIVATED - Self: Despawn in 5 s respawn in 60 seconds"),
(@ENTRY, 1, 1, 0, 11, 0, 100, 0, 0, 0, 0, 0, 133, 0, 295537, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "When just created - Respawn NPC with guid 295349");

SET @ENTRY := -214758;
DELETE FROM `smart_scripts` WHERE `entryOrGuid` = @ENTRY AND `source_type` = 1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 1, 0, 0, 70, 0, 100, 1, 2, 0, 0, 0, 41, 5000, 60, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On loot state changed to GO_ACTIVATED - Self: Despawn in 5 s respawn in 60 seconds"),
(@ENTRY, 1, 1, 0, 11, 0, 100, 0, 0, 0, 0, 0, 133, 0, 295538, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "When just created - Respawn NPC with guid 295349");

SET @ENTRY := -214759;
DELETE FROM `smart_scripts` WHERE `entryOrGuid` = @ENTRY AND `source_type` = 1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 1, 0, 0, 70, 0, 100, 1, 2, 0, 0, 0, 41, 5000, 60, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On loot state changed to GO_ACTIVATED - Self: Despawn in 5 s respawn in 60 seconds"),
(@ENTRY, 1, 1, 0, 11, 0, 100, 0, 0, 0, 0, 0, 133, 0, 295544, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "When just created - Respawn NPC with guid 295349");

SET @ENTRY := -214764;
DELETE FROM `smart_scripts` WHERE `entryOrGuid` = @ENTRY AND `source_type` = 1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 1, 0, 0, 70, 0, 100, 1, 2, 0, 0, 0, 41, 5000, 60, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On loot state changed to GO_ACTIVATED - Self: Despawn in 5 s respawn in 60 seconds"),
(@ENTRY, 1, 1, 0, 11, 0, 100, 0, 0, 0, 0, 0, 133, 0, 295701, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "When just created - Respawn NPC with guid 295349");

SET @ENTRY := -214765;
DELETE FROM `smart_scripts` WHERE `entryOrGuid` = @ENTRY AND `source_type` = 1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 1, 0, 0, 70, 0, 100, 1, 2, 0, 0, 0, 41, 5000, 60, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On loot state changed to GO_ACTIVATED - Self: Despawn in 5 s respawn in 60 seconds"),
(@ENTRY, 1, 1, 0, 11, 0, 100, 0, 0, 0, 0, 0, 133, 0, 295747, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "When just created - Respawn NPC with guid 295349");

SET @ENTRY := -214766;
DELETE FROM `smart_scripts` WHERE `entryOrGuid` = @ENTRY AND `source_type` = 1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 1, 0, 0, 70, 0, 100, 1, 2, 0, 0, 0, 41, 5000, 60, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On loot state changed to GO_ACTIVATED - Self: Despawn in 5 s respawn in 60 seconds"),
(@ENTRY, 1, 1, 0, 11, 0, 100, 0, 0, 0, 0, 0, 133, 0, 295749, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "When just created - Respawn NPC with guid 295349");


DELETE FROM `creature_text` WHERE `CreatureID`= 38345;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(38345, 0, 0, 'The quilboar will pay!', 12, 0, 100, 4, 0, 0, 38280, 'Captured Brave'),
(38345, 0, 1, 'Thank the Earth Mother!', 12, 0, 100, 4, 0, 0, 38278, 'Captured Brave'),
(38345, 0, 2, 'I can move again!', 12, 0, 100, 4, 0, 0, 38279, 'Captured Brave');

UPDATE `creature` SET `spawndist`= 10, `MovementType`= 1 WHERE `guid` IN (296026, 295998, 295977);
UPDATE `gameobject` SET `spawntimesecs`= 60 WHERE `guid` IN (214745, 214746, 214748, 214749, 214757, 214758, 214759, 214764, 214765, 214766);

SET @CGUID := 296017;
SET @PATH := @CGUID * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `smoothTransition`) VALUES
(@PATH, 0, -2931.391, -252.7051, 59.46798, NULL, 1),
(@PATH, 1, -2932.56, -261.01, 58.96798, NULL, 1),
(@PATH, 2, -2931.23, -273.128, 59.00479, NULL, 1),
(@PATH, 3, -2930.8, -289.241, 59.18985, NULL, 1),
(@PATH, 4, -2930.68, -302.472, 58.8884, NULL, 1),
(@PATH, 5, -2932.27, -318.439, 58.63254, NULL, 1),
(@PATH, 6, -2938.28, -335.476, 57.98273, NULL, 1),
(@PATH, 7, -2949.51, -348.207, 56.50665, NULL, 1),
(@PATH, 8, -2966.47, -362.797, 54.09552, NULL, 1),
(@PATH, 9, -2979.69, -376.811, 51.45162, NULL, 1),
(@PATH, 10, -2992.68, -392.806, 49.03243, NULL, 1),
(@PATH, 11, -2996.55, -412.488, 48.07489, NULL, 1),
(@PATH, 12, -3000.19, -438.071, 45.79768, NULL, 1),
(@PATH, 13, -3000.51, -446.528, 45.5091, NULL, 0),
(@PATH, 14, -3000.19, -438.071, 45.79768, NULL, 1),
(@PATH, 15, -2996.55, -412.488, 48.07489, NULL, 1),
(@PATH, 16, -2992.68, -392.806, 49.03243, NULL, 1),
(@PATH, 17, -2979.69, -376.811, 51.45162, NULL, 1),
(@PATH, 18, -2966.47, -362.797, 54.09552, NULL, 1),
(@PATH, 19, -2949.51, -348.207, 56.50665, NULL, 1),
(@PATH, 20, -2938.28, -335.476, 57.98273, NULL, 1),
(@PATH, 21, -2932.27, -318.439, 58.63254, NULL, 1),
(@PATH, 22, -2930.68, -302.472, 58.8884, NULL, 1),
(@PATH, 23, -2930.8, -289.241, 59.18985, NULL, 1),
(@PATH, 24, -2931.23, -273.128, 59.00479, NULL, 1),
(@PATH, 25, -2932.56, -261.01, 58.96798, NULL, 1),
(@PATH, 26, -2931.39, -252.705, 59.46798, NULL, 1),
(@PATH, 27, -2934.297, -247.4551, 59.91055, NULL, 0);

UPDATE `creature` SET `position_x`= -2931.391, `position_y`= -252.7051, `position_z`= 59.46798, `orientation`= 0, `spawndist`= 0, `MovementType`= 2 WHERE `guid`= @CGUID;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID;
INSERT INTO `creature_addon` (`guid`, `waypointPathId`, `bytes2`) VALUES
(@CGUID, @PATH, 1);

 -- Armored Battleboar
SET @ENTRY := 36696;
DELETE FROM `smart_scripts` WHERE `entryOrGuid` = @ENTRY AND `source_type` = 0;
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 8, 0, 100, 1, 69228, 0, 0, 0, 11, 42726, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Throw Torch (69228) hit - Self: Cast spell Cosmetic - Immolation (Whole Body) (42726) on Self"),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 11, 70113, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Throw Torch (69228) hit - Self: Cast spell Sprint - No Visual (70113) on Self"),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Throw Torch (69228) hit - Self: Set react state to Passive"),
(@ENTRY, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 122, 10000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Throw Torch (69228) hit - Self: Flee for 10000 ms"),
(@ENTRY, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 67, 1, 7000, 7000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "On spell Throw Torch (69228) hit - Trigger timed event timedEvent[1] in 7000 - 7000 ms // -meta_wait"),
(@ENTRY, 0, 5, 0, 59, 0, 100, 0, 1, 0, 0, 0, 11, 43388, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On timed event timedEvent[1] triggered - Self: Cast spell 43388 on Self"),
(@ENTRY, 0, 6, 0, 0, 0, 100, 1, 2000, 2000, 0, 0, 11, 3385, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Time = 2 seconds - Self: Cast spell Boar Charge (3385) on Self");

DELETE FROM `conditions` WHERE `SourceEntry`= 69228 AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 0x1 | 0x2, 69228, 0, 0, 31, 0, 3, 36727, 0, 0, 0, '', 'Throw Torch - Target First Trough'),
(13, 0x1 | 0x2, 69228, 0, 1, 31, 0, 3, 37155, 0, 0, 0, '', 'Throw Torch - Target Second Trough'),
(13, 0x1 | 0x2, 69228, 0, 2, 31, 0, 3, 37156, 0, 0, 0, '', 'Throw Torch - Target Third Trough'),
(13, 0x4, 69228, 0, 0, 31, 0, 3, 36696, 0, 0, 0, '', 'Throw Torch - Target Armored Battleboar');


-- Chaining corrections
-- Stop the Thorncallers and Rite of Courage must be rewarded before being able to accept The Battleboars and Feed of Evil
UPDATE `quest_template_addon` SET `PrevQuestID`= 14458, `NextQuestID`= 0, `ExclusiveGroup`= -14455 WHERE `ID` IN (14455, 14456);
-- The Battleboars and Feed Of Evil must be rewarded before being able to accept Rite of Honor
UPDATE `quest_template_addon` SET `PrevQuestID`= 14455, `NextQuestID`= 14460, `ExclusiveGroup`= -14461 WHERE `ID` IN (14461, 14459);
UPDATE `quest_template_addon` SET `PrevQuestID`= 0, `NextQuestID`= 0 WHERE `ID`= 14460;


DELETE FROM `creature` WHERE `guid` IN (294783, 294784, 294786, 294790, 294791, 294796, 294797, 294798, 294799, 294800, 294805, 294806, 294807, 294808, 294811, 294812, 294813, 294815, 294824, 294829, 294835, 294836, 294839, 294841, 294843, 294844, 294849, 295882, 295883, 295884, 295885, 295886, 295887, 295888, 295889, 295890, 295894, 295895, 295896, 295898, 295899, 295901, 295902, 295903, 295904, 295905, 295906, 295907, 295909, 295910, 295911, 295913, 295914, 295915, 295916, 295917, 295918, 295919, 295920, 295921, 295923, 295924, 295925, 295928, 295929, 295930, 295932);
DELETE FROM `creature_addon` WHERE `guid` IN (294783, 294784, 294786, 294790, 294791, 294796, 294797, 294798, 294799, 294800, 294805, 294806, 294807, 294808, 294811, 294812, 294813, 294815, 294824, 294829, 294835, 294836, 294839, 294841, 294843, 294844, 294849, 295882, 295883, 295884, 295885, 295886, 295887, 295888, 295889, 295890, 295894, 295895, 295896, 295898, 295899, 295901, 295902, 295903, 295904, 295905, 295906, 295907, 295909, 295910, 295911, 295913, 295914, 295915, 295916, 295917, 295918, 295919, 295920, 295921, 295923, 295924, 295925, 295928, 295929, 295930, 295932);
DELETE FROM `spawn_group` WHERE `spawnType`= 0 AND `spawnId` IN (294783, 294784, 294786, 294790, 294791, 294796, 294797, 294798, 294799, 294800, 294805, 294806, 294807, 294808, 294811, 294812, 294813, 294815, 294824, 294829, 294835, 294836, 294839, 294841, 294843, 294844, 294849, 295882, 295883, 295884, 295885, 295886, 295887, 295888, 295889, 295890, 295894, 295895, 295896, 295898, 295899, 295901, 295902, 295903, 295904, 295905, 295906, 295907, 295909, 295910, 295911, 295913, 295914, 295915, 295916, 295917, 295918, 295919, 295920, 295921, 295923, 295924, 295925, 295928, 295929, 295930, 295932);

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(294783, 36696, 1, 215, 4879, 1, 169, 0, 0, 0, -3387.712646484375, -289.5716552734375, 61.12799835205078125, 3.459283351898193359, 120, 0, 0, 71, 0, 0, 0, 0, 0, 15595), -- Armored Battleboar (Area: Red Cloud Mesa - Difficulty: 0) (possible waypoints or random movement)
(294784, 36696, 1, 215, 4879, 1, 169, 0, 0, 0, -3361.364501953125, -233.743057250976562, 61.4824066162109375, 0.157079637050628662, 120, 0, 0, 71, 0, 0, 0, 0, 0, 15595), -- Armored Battleboar (Area: Red Cloud Mesa - Difficulty: 0)
(294786, 36696, 1, 215, 4879, 1, 169, 0, 0, 0, -3357.05126953125, -247.99200439453125, 61.77496337890625, 4.891559123992919921, 120, 0, 0, 71, 0, 0, 0, 0, 0, 15595), -- Armored Battleboar (Area: Red Cloud Mesa - Difficulty: 0) (possible waypoints or random movement)
(294790, 36696, 1, 215, 4879, 1, 169, 0, 0, 0, -3373.84912109375, -286.59185791015625, 61.30696868896484375, 4.390797615051269531, 120, 0, 0, 71, 0, 0, 0, 0, 0, 15595), -- Armored Battleboar (Area: Red Cloud Mesa - Difficulty: 0) (possible waypoints or random movement)
(294791, 36696, 1, 215, 4879, 1, 169, 0, 0, 0, -3373.256103515625, -269.69927978515625, 60.5075531005859375, 5.589087963104248046, 120, 0, 0, 71, 0, 0, 0, 0, 0, 15595), -- Armored Battleboar (Area: The Thornsnarl - Difficulty: 0) (possible waypoints or random movement)
(294796, 36696, 1, 215, 4879, 1, 169, 0, 0, 0, -3356.41845703125, -261.7041015625, 60.23343658447265625, 4.243979454040527343, 120, 0, 0, 71, 0, 0, 0, 0, 0, 15595), -- Armored Battleboar (Area: The Thornsnarl - Difficulty: 0) (possible waypoints or random movement)
(294797, 36696, 1, 215, 4879, 1, 169, 0, 0, 0, -3370.57177734375, -260.585968017578125, 60.7913818359375, 1.434647083282470703, 120, 0, 0, 86, 0, 0, 0, 0, 0, 15595), -- Armored Battleboar (Area: The Thornsnarl - Difficulty: 0) (possible waypoints or random movement)
(294798, 36696, 1, 215, 4879, 1, 169, 0, 0, 0, -3398.889892578125, -282.37298583984375, 61.12799835205078125, 2.353209972381591796, 120, 0, 0, 86, 0, 0, 0, 0, 0, 15595), -- Armored Battleboar (Area: The Thornsnarl - Difficulty: 0) (possible waypoints or random movement)
(294799, 36696, 1, 215, 4879, 1, 169, 0, 0, 0, -3415.6953125, -275.961029052734375, 62.58871841430664062, 5.15131378173828125, 120, 0, 0, 86, 0, 0, 0, 0, 0, 15595), -- Armored Battleboar (Area: The Thornsnarl - Difficulty: 0) (possible waypoints or random movement)
(294800, 36696, 1, 215, 4879, 1, 169, 0, 0, 0, -3399.0244140625, -264.404510498046875, 61.2974700927734375, 4.677482128143310546, 120, 0, 0, 71, 0, 0, 0, 0, 0, 15595), -- Armored Battleboar (Area: The Thornsnarl - Difficulty: 0) (possible waypoints or random movement)
(294805, 36696, 1, 215, 4879, 1, 169, 0, 0, 0, -3385.738525390625, -271.448883056640625, 60.35504913330078125, 0.200376644730567932, 120, 0, 0, 86, 0, 0, 0, 0, 0, 15595), -- Armored Battleboar (Area: The Thornsnarl - Difficulty: 0) (Auras: 3385 - Boar Charge) (possible waypoints or random movement)
(294806, 36696, 1, 215, 4879, 1, 169, 0, 0, 0, -3391.90625, -206.989578247070312, 61.89710617065429687, 4.694935798645019531, 120, 0, 0, 71, 0, 0, 0, 0, 0, 15595), -- Armored Battleboar (Area: Red Cloud Mesa - Difficulty: 0) (possible waypoints or random movement)
(294807, 36696, 1, 215, 4879, 1, 169, 0, 0, 0, -3395.382080078125, -224.66949462890625, 60.50627517700195312, 0.182526633143424987, 120, 0, 0, 86, 0, 0, 0, 0, 0, 15595), -- Armored Battleboar (Area: Red Cloud Mesa - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(294808, 36696, 1, 215, 4879, 1, 169, 0, 0, 0, -3390.096923828125, -241.6046142578125, 61.44142913818359375, 0.142375916242599487, 120, 0, 0, 86, 0, 0, 0, 0, 0, 15595), -- Armored Battleboar (Area: Red Cloud Mesa - Difficulty: 0) (possible waypoints or random movement)
(294811, 36696, 1, 215, 4879, 1, 169, 0, 0, 0, -3386.19580078125, -230.814971923828125, 60.54582595825195312, 1.94512331485748291, 120, 0, 0, 71, 0, 0, 0, 0, 0, 15595), -- Armored Battleboar (Area: Red Cloud Mesa - Difficulty: 0) (possible waypoints or random movement)
(294812, 36696, 1, 215, 4879, 1, 169, 0, 0, 0, -3421.875, -230.208984375, 62.00777816772460937, 1.570796370506286621, 120, 0, 0, 86, 0, 0, 0, 0, 0, 15595), -- Armored Battleboar (Area: Red Cloud Mesa - Difficulty: 0) (possible waypoints or random movement)
(294813, 36696, 1, 215, 4879, 1, 169, 0, 0, 0, -3405.185791015625, -261.84027099609375, 61.72217941284179687, 4.171336650848388671, 120, 0, 0, 86, 0, 0, 0, 0, 0, 15595), -- Armored Battleboar (Area: Red Cloud Mesa - Difficulty: 0) (Auras: 42726 - Cosmetic - Immolation (Whole Body)) (possible waypoints or random movement)
(294815, 36696, 1, 215, 4879, 1, 169, 0, 0, 0, -3405.92578125, -230.443466186523437, 60.31563949584960937, 1.658210039138793945, 120, 0, 0, 71, 0, 0, 0, 0, 0, 15595), -- Armored Battleboar (Area: Red Cloud Mesa - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(294824, 36696, 1, 215, 4879, 1, 169, 0, 0, 0, -3394.3046875, -256.769744873046875, 59.74762725830078125, 4.969597339630126953, 120, 0, 0, 86, 0, 0, 0, 0, 0, 15595), -- Armored Battleboar (Area: Red Cloud Mesa - Difficulty: 0) (possible waypoints or random movement)
(294829, 36696, 1, 215, 4879, 1, 169, 0, 0, 0, -3402.674560546875, -246.27508544921875, 60.74570846557617187, 6.00153207778930664, 120, 0, 0, 71, 0, 0, 0, 0, 0, 15595), -- Armored Battleboar (Area: Red Cloud Mesa - Difficulty: 0) (possible waypoints or random movement)
(294835, 36696, 1, 215, 4879, 1, 169, 0, 0, 0, -3408.322998046875, -267.28472900390625, 61.84445571899414062, 0.715584993362426757, 120, 0, 0, 86, 0, 0, 0, 0, 0, 15595), -- Armored Battleboar (Area: Red Cloud Mesa - Difficulty: 0) (Auras: 42726 - Cosmetic - Immolation (Whole Body)) (possible waypoints or random movement)
(294836, 36696, 1, 215, 4879, 1, 169, 0, 0, 0, -3412.921142578125, -241.939041137695312, 61.33726119995117187, 3.18827366828918457, 120, 0, 0, 86, 0, 0, 0, 0, 0, 15595), -- Armored Battleboar (Area: Red Cloud Mesa - Difficulty: 0) (possible waypoints or random movement)
(294839, 36696, 1, 215, 4879, 1, 169, 0, 0, 0, -3355.3056640625, -231.28472900390625, 61.87128448486328125, 3.368485450744628906, 120, 0, 0, 71, 0, 0, 0, 0, 0, 15595), -- Armored Battleboar (Area: The Battleboar Pen - Difficulty: 0) (Auras: 42726 - Cosmetic - Immolation (Whole Body)) (possible waypoints or random movement)
(294841, 36696, 1, 215, 4879, 1, 169, 0, 0, 0, -3355.397705078125, -217.038192749023437, 61.8046112060546875, 4.834216117858886718, 120, 0, 0, 86, 0, 0, 0, 0, 0, 15595), -- Armored Battleboar (Area: The Battleboar Pen - Difficulty: 0) (possible waypoints or random movement)
(294843, 36696, 1, 215, 4879, 1, 169, 0, 0, 0, -3374.940185546875, -223.072540283203125, 60.76482009887695312, 2.929447889328002929, 120, 0, 0, 86, 0, 0, 0, 0, 0, 15595), -- Armored Battleboar (Area: The Battleboar Pen - Difficulty: 0) (possible waypoints or random movement)
(294844, 36696, 1, 215, 4879, 1, 169, 0, 0, 0, -3368.5, -239.621994018554687, 61.23113250732421875, 3.119886636734008789, 120, 0, 0, 71, 0, 0, 0, 0, 0, 15595), -- Armored Battleboar (Area: The Battleboar Pen - Difficulty: 0) (possible waypoints or random movement)
(294849, 36696, 1, 215, 4879, 1, 169, 0, 0, 0, -3368.41845703125, -211.65972900390625, 61.7491302490234375, 2.91170048713684082, 120, 0, 0, 86, 0, 0, 0, 0, 0, 15595), -- Armored Battleboar (Area: The Battleboar Pen - Difficulty: 0) (possible waypoints or random movement)
(295882, 36696, 1, 215, 4879, 1, 169, 0, 0, 0, -3391.61279296875, -213.697921752929687, 61.73238754272460937, 1.65806281566619873, 120, 0, 0, 86, 0, 0, 0, 0, 0, 15595), -- Armored Battleboar (Area: The Battleboar Pen - Difficulty: 0)
(295883, 36696, 1, 215, 4879, 1, 169, 0, 0, 0, -3380.579833984375, -257.463531494140625, 61.25440597534179687, 3.351032257080078125, 120, 0, 0, 71, 0, 0, 0, 0, 0, 15595); -- Armored Battleboar (Area: The Battleboar Pen - Difficulty: 0) (possible waypoints or random movement)

UPDATE `creature` SET `spawndist`= 8, `MovementType`= 1 WHERE `guid` IN (294783, 294786, 294790, 294791, 294796, 294797, 294798, 294799, 294805, 294807, 294808, 294811, 294812, 294815, 294824, 294829, 294836, 294841, 294843, 294844, 294849);

SET @ENTRY := -294806;
DELETE FROM `smart_scripts` WHERE `entryOrGuid` = @ENTRY AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 8, 0, 100, 1, 69228, 0, 0, 0, 11, 42726, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Throw Torch (69228) hit - Self: Cast spell Cosmetic - Immolation (Whole Body) (42726) on Self"),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 11, 70113, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Throw Torch (69228) hit - Self: Cast spell Sprint - No Visual (70113) on Self"),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Throw Torch (69228) hit - Self: Set react state to Passive"),
(@ENTRY, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 122, 10000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Throw Torch (69228) hit - Self: Flee for 10000 ms"),
(@ENTRY, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 67, 1, 7000, 7000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "On spell Throw Torch (69228) hit - Trigger timed event timedEvent[1] in 7000 - 7000 ms // -meta_wait"),
(@ENTRY, 0, 5, 0, 59, 0, 100, 0, 1, 0, 0, 0, 11, 43388, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On timed event timedEvent[1] triggered - Self: Cast spell 43388 on Self"),
(@ENTRY, 0, 6, 0, 0, 0, 100, 1, 2000, 2000, 0, 0, 11, 3385, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Time = 2 seconds - Self: Cast spell Boar Charge (3385) on Self"),
(@ENTRY, 0, 7, 0, 60, 0, 100, 0, 3600, 3600, 3600, 3600, 5, 35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 3.6 seconds - Self: Play emote ONESHOT_ATTACKUNARMED (35)");

SET @ENTRY := -295882;
DELETE FROM `smart_scripts` WHERE `entryOrGuid` = @ENTRY AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 8, 0, 100, 1, 69228, 0, 0, 0, 11, 42726, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Throw Torch (69228) hit - Self: Cast spell Cosmetic - Immolation (Whole Body) (42726) on Self"),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 11, 70113, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Throw Torch (69228) hit - Self: Cast spell Sprint - No Visual (70113) on Self"),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Throw Torch (69228) hit - Self: Set react state to Passive"),
(@ENTRY, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 122, 10000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Throw Torch (69228) hit - Self: Flee for 10000 ms"),
(@ENTRY, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 67, 1, 7000, 7000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "On spell Throw Torch (69228) hit - Trigger timed event timedEvent[1] in 7000 - 7000 ms // -meta_wait"),
(@ENTRY, 0, 5, 0, 59, 0, 100, 0, 1, 0, 0, 0, 11, 43388, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On timed event timedEvent[1] triggered - Self: Cast spell 43388 on Self"),
(@ENTRY, 0, 6, 0, 0, 0, 100, 1, 2000, 2000, 0, 0, 11, 3385, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Time = 2 seconds - Self: Cast spell Boar Charge (3385) on Self"),
(@ENTRY, 0, 7, 0, 60, 0, 100, 0, 3600, 3600, 3600, 3600, 5, 35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 3.6 seconds - Self: Play emote ONESHOT_ATTACKUNARMED (35)");

SET @ENTRY := -294835;
DELETE FROM `smart_scripts` WHERE `entryOrGuid` = @ENTRY AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 8, 0, 100, 1, 69228, 0, 0, 0, 11, 42726, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Throw Torch (69228) hit - Self: Cast spell Cosmetic - Immolation (Whole Body) (42726) on Self"),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 11, 70113, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Throw Torch (69228) hit - Self: Cast spell Sprint - No Visual (70113) on Self"),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Throw Torch (69228) hit - Self: Set react state to Passive"),
(@ENTRY, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 122, 10000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Throw Torch (69228) hit - Self: Flee for 10000 ms"),
(@ENTRY, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 67, 1, 7000, 7000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "On spell Throw Torch (69228) hit - Trigger timed event timedEvent[1] in 7000 - 7000 ms // -meta_wait"),
(@ENTRY, 0, 5, 0, 59, 0, 100, 0, 1, 0, 0, 0, 11, 43388, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On timed event timedEvent[1] triggered - Self: Cast spell 43388 on Self"),
(@ENTRY, 0, 6, 0, 0, 0, 100, 1, 2000, 2000, 0, 0, 11, 3385, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Time = 2 seconds - Self: Cast spell Boar Charge (3385) on Self"),
(@ENTRY, 0, 7, 0, 60, 0, 100, 0, 3600, 3600, 3600, 3600, 5, 35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 3.6 seconds - Self: Play emote ONESHOT_ATTACKUNARMED (35)");

SET @ENTRY := -294813;
DELETE FROM `smart_scripts` WHERE `entryOrGuid` = @ENTRY AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 8, 0, 100, 1, 69228, 0, 0, 0, 11, 42726, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Throw Torch (69228) hit - Self: Cast spell Cosmetic - Immolation (Whole Body) (42726) on Self"),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 11, 70113, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Throw Torch (69228) hit - Self: Cast spell Sprint - No Visual (70113) on Self"),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Throw Torch (69228) hit - Self: Set react state to Passive"),
(@ENTRY, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 122, 10000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Throw Torch (69228) hit - Self: Flee for 10000 ms"),
(@ENTRY, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 67, 1, 7000, 7000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "On spell Throw Torch (69228) hit - Trigger timed event timedEvent[1] in 7000 - 7000 ms // -meta_wait"),
(@ENTRY, 0, 5, 0, 59, 0, 100, 0, 1, 0, 0, 0, 11, 43388, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On timed event timedEvent[1] triggered - Self: Cast spell 43388 on Self"),
(@ENTRY, 0, 6, 0, 0, 0, 100, 1, 2000, 2000, 0, 0, 11, 3385, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Time = 2 seconds - Self: Cast spell Boar Charge (3385) on Self"),
(@ENTRY, 0, 7, 0, 60, 0, 100, 0, 3600, 3600, 3600, 3600, 5, 35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 3.6 seconds - Self: Play emote ONESHOT_ATTACKUNARMED (35)");

SET @ENTRY := -294839;
DELETE FROM `smart_scripts` WHERE `entryOrGuid` = @ENTRY AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 8, 0, 100, 1, 69228, 0, 0, 0, 11, 42726, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Throw Torch (69228) hit - Self: Cast spell Cosmetic - Immolation (Whole Body) (42726) on Self"),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 11, 70113, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Throw Torch (69228) hit - Self: Cast spell Sprint - No Visual (70113) on Self"),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Throw Torch (69228) hit - Self: Set react state to Passive"),
(@ENTRY, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 122, 10000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Throw Torch (69228) hit - Self: Flee for 10000 ms"),
(@ENTRY, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 67, 1, 7000, 7000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "On spell Throw Torch (69228) hit - Trigger timed event timedEvent[1] in 7000 - 7000 ms // -meta_wait"),
(@ENTRY, 0, 5, 0, 59, 0, 100, 0, 1, 0, 0, 0, 11, 43388, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On timed event timedEvent[1] triggered - Self: Cast spell 43388 on Self"),
(@ENTRY, 0, 6, 0, 0, 0, 100, 1, 2000, 2000, 0, 0, 11, 3385, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Time = 2 seconds - Self: Cast spell Boar Charge (3385) on Self"),
(@ENTRY, 0, 7, 0, 60, 0, 100, 0, 3600, 3600, 3600, 3600, 5, 35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 3.6 seconds - Self: Play emote ONESHOT_ATTACKUNARMED (35)");

SET @ENTRY := -294784;
DELETE FROM `smart_scripts` WHERE `entryOrGuid` = @ENTRY AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 8, 0, 100, 1, 69228, 0, 0, 0, 11, 42726, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Throw Torch (69228) hit - Self: Cast spell Cosmetic - Immolation (Whole Body) (42726) on Self"),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 11, 70113, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Throw Torch (69228) hit - Self: Cast spell Sprint - No Visual (70113) on Self"),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Throw Torch (69228) hit - Self: Set react state to Passive"),
(@ENTRY, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 122, 10000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Throw Torch (69228) hit - Self: Flee for 10000 ms"),
(@ENTRY, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 67, 1, 7000, 7000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "On spell Throw Torch (69228) hit - Trigger timed event timedEvent[1] in 7000 - 7000 ms // -meta_wait"),
(@ENTRY, 0, 5, 0, 59, 0, 100, 0, 1, 0, 0, 0, 11, 43388, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On timed event timedEvent[1] triggered - Self: Cast spell 43388 on Self"),
(@ENTRY, 0, 6, 0, 0, 0, 100, 1, 2000, 2000, 0, 0, 11, 3385, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Time = 2 seconds - Self: Cast spell Boar Charge (3385) on Self"),
(@ENTRY, 0, 7, 0, 60, 0, 100, 0, 3600, 3600, 3600, 3600, 5, 35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 3.6 seconds - Self: Play emote ONESHOT_ATTACKUNARMED (35)");

SET @ENTRY := -295883;
DELETE FROM `smart_scripts` WHERE `entryOrGuid` = @ENTRY AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 8, 0, 100, 1, 69228, 0, 0, 0, 11, 42726, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Throw Torch (69228) hit - Self: Cast spell Cosmetic - Immolation (Whole Body) (42726) on Self"),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 11, 70113, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Throw Torch (69228) hit - Self: Cast spell Sprint - No Visual (70113) on Self"),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Throw Torch (69228) hit - Self: Set react state to Passive"),
(@ENTRY, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 122, 10000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Throw Torch (69228) hit - Self: Flee for 10000 ms"),
(@ENTRY, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 67, 1, 7000, 7000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "On spell Throw Torch (69228) hit - Trigger timed event timedEvent[1] in 7000 - 7000 ms // -meta_wait"),
(@ENTRY, 0, 5, 0, 59, 0, 100, 0, 1, 0, 0, 0, 11, 43388, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On timed event timedEvent[1] triggered - Self: Cast spell 43388 on Self"),
(@ENTRY, 0, 6, 0, 0, 0, 100, 1, 2000, 2000, 0, 0, 11, 3385, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Time = 2 seconds - Self: Cast spell Boar Charge (3385) on Self"),
(@ENTRY, 0, 7, 0, 60, 0, 100, 0, 3600, 3600, 3600, 3600, 5, 35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 3.6 seconds - Self: Play emote ONESHOT_ATTACKUNARMED (35)");

SET @ENTRY := -294800;
DELETE FROM `smart_scripts` WHERE `entryOrGuid` = @ENTRY AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 8, 0, 100, 1, 69228, 0, 0, 0, 11, 42726, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Throw Torch (69228) hit - Self: Cast spell Cosmetic - Immolation (Whole Body) (42726) on Self"),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 11, 70113, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Throw Torch (69228) hit - Self: Cast spell Sprint - No Visual (70113) on Self"),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Throw Torch (69228) hit - Self: Set react state to Passive"),
(@ENTRY, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 122, 10000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Throw Torch (69228) hit - Self: Flee for 10000 ms"),
(@ENTRY, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 67, 1, 7000, 7000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "On spell Throw Torch (69228) hit - Trigger timed event timedEvent[1] in 7000 - 7000 ms // -meta_wait"),
(@ENTRY, 0, 5, 0, 59, 0, 100, 0, 1, 0, 0, 0, 11, 43388, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On timed event timedEvent[1] triggered - Self: Cast spell 43388 on Self"),
(@ENTRY, 0, 6, 0, 0, 0, 100, 1, 2000, 2000, 0, 0, 11, 3385, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Time = 2 seconds - Self: Cast spell Boar Charge (3385) on Self"),
(@ENTRY, 0, 7, 0, 60, 0, 100, 0, 3600, 3600, 3600, 3600, 5, 35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 3.6 seconds - Self: Play emote ONESHOT_ATTACKUNARMED (35)");

DELETE FROM `creature_text` WHERE `CreatureID`= 36712;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(36712, 0, 0, 'Squealer take this land! Tauren will burn!', 12, 0, 100, 0, 0, 0, 38323, 'Chief Squealer Thornmantle');

-- Chief Squealer Thornmantle
SET @ENTRY := 36712;
DELETE FROM `smart_scripts` WHERE `entryOrGuid` = @ENTRY AND `source_type` = 0;
UPDATE `creature_template` SET `AIName` = "", `ScriptName` = "npc_mulgore_chief_squealer_thornmantle" WHERE `entry` = @ENTRY;

DELETE FROM `creature_addon` WHERE `guid` IN (295945, 295948, 295940, 295947, 295946, 295939, 295952);
INSERT INTO `creature_addon` (`guid`, `bytes2`, `auras`) VALUES
(295945, 1, '69316 29266'),
(295948, 1, '69316 29266'),
(295940, 1, '69316 29266'),
(295947, 1, '69316 29266'),
(295946, 1, '69316 29266'),
(295939, 1, '69316 29266'),
(295952, 1, '69316 29266');

DELETE FROM `creature_text` WHERE `CreatureID`= 2981;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(2981, 1, 0, 'Earth Mother, into your arms we give one of our own. She is Unaya Hawkwind, my mother, and Greatmother to us all; the wisest of our tribe.', 12, 0, 100, 1, 0, 0, 38303, 'Chief Hawkwind'),
(2981, 2, 0, 'May her spirit fly to you swiftly; may the winds carry her gently, and the grass whisper her name.', 12, 0, 100, 1, 0, 0, 38304, 'Chief Hawkwind'),
(2981, 3, 0, 'Watch over her as she has watched over us; let her look down on us with joy, through the eternal gaze of An\'she and Mu\'sha, until we too join her in death.', 12, 0, 100, 1, 0, 0, 38305, 'Chief Hawkwind '),
(2981, 4, 0, 'For we are all born of you, and shall all return to you.', 12, 0, 100, 1, 0, 0, 38306, 'Chief Hawkwind');

 -- Timed list 298100
SET @ENTRY := 298100;
DELETE FROM `smart_scripts` WHERE `entryOrGuid` = @ENTRY AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 2400, 2400, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "After 2.4 seconds - Self: Talk 0 to invoker"),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 7200, 7200, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "After 7.2 seconds - Self: Talk 1 to invoker"),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 7200, 7200, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "After 7.2 seconds - Self: Talk 2 to invoker"),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 7200, 7200, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "After 7.2 seconds - Self: Talk 3 to invoker"),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 5, 66, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "After 7 seconds - Self: Play emote ONESHOT_SALUTE (66)");

 -- Sunwalker Helaku
SET @ENTRY := 37737;
DELETE FROM `smart_scripts` WHERE `entryOrGuid` = @ENTRY AND `source_type` = 0;
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 100000, 150000, 100000, 150000, 5, 18, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 100 - 150 seconds - Self: Play emote ONESHOT_CRY (18)");

 -- Seer Ravenfeather
SET @ENTRY := 37724;
DELETE FROM `smart_scripts` WHERE `entryOrGuid` = @ENTRY AND `source_type` = 0;
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 100000, 150000, 100000, 150000, 5, 18, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 100 - 150 seconds - Self: Play emote ONESHOT_CRY (18)");

 -- Gart Mistrunner
SET @ENTRY := 3060;
DELETE FROM `smart_scripts` WHERE `entryOrGuid` = @ENTRY AND `source_type` = 0;
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 100000, 150000, 100000, 150000, 5, 18, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 100 - 150 seconds - Self: Play emote ONESHOT_CRY (18)");

 -- Harutt Thunderhorn
SET @ENTRY := 3059;
DELETE FROM `smart_scripts` WHERE `entryOrGuid` = @ENTRY AND `source_type` = 0;
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 100000, 150000, 100000, 150000, 5, 18, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 100 - 150 seconds - Self: Play emote ONESHOT_CRY (18)");
 
 -- Mela Dawnstrider
SET @ENTRY := 3062;
DELETE FROM `smart_scripts` WHERE `entryOrGuid` = @ENTRY AND `source_type` = 0;
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 100000, 150000, 100000, 150000, 5, 18, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 100 - 150 seconds - Self: Play emote ONESHOT_CRY (18)");

UPDATE `creature_template` SET `flags_extra`= 128 WHERE `entry`= 38438;
 -- Mulgore Offering Credit Bunny
SET @ENTRY := 38438;
DELETE FROM `smart_scripts` WHERE `entryOrGuid` = @ENTRY AND `source_type` = 0;
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 8, 0, 100, 0, 71898, 0, 0, 0, 33, 38438, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On spell Funeral Offering (71898) hit - Caster: Give kill credit Mulgore Offering Credit Bunny (38438)");

DELETE FROM `conditions` WHERE `SourceEntry`= 71898 AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 0x2, 71898, 0, 0, 31, 0, 3, 38438, 0, 0, 0, '', 'Funeral Offering - Target Mulgore Offering Credit Bunny');

-- Missing spell focus spawn
DELETE FROM `gameobject` WHERE `guid`= 239777;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `phaseId`, `position_x`, `position_y`, `position_z`) VALUES
(239777, 202139, 1, 169, -2905.05, -254.58, 60);

DELETE FROM `gameobject` WHERE `guid` IN (214751, 239777, 214741);
DELETE FROM `gameobject_addon` WHERE `guid` IN (214751, 239777, 214741);

UPDATE `creature_template` SET `ScriptName`= 'npc_mulgore_eagle_spirit' WHERE `entry`= 36790;
