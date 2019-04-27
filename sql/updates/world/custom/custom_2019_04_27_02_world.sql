-- Creature Arch Druid of Hyjal 40150 SAI
SET @ENTRY := 40150;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 75026, 0, 0, 0, 0, 0, 10, 384466, 0, 0, 0, 0, 0, 0, "On reset (e.g. after reaching home) - Self: Cast spell Lifeforce (75026) on Creature Baron Geddon 40147 (384466) // ");

DELETE FROM `conditions` WHERE `SourceEntry`= 75072 AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 75072, 0, 0, 31, 0, 3, 40149, 0, 0, 0, '', 'Inferno Ping - Target Telessra'),
(13, 1, 75072, 0, 1, 31, 0, 3, 40148, 0, 0, 0, '', 'Inferno Ping - Target Galrond of the Claw');

-- Creature Baron Geddon 40147 SAI
SET @ENTRY := 40147;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 63, 0, 100, 0, 0, 0, 0, 0, 103, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Self: Set rooted // "),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 42, 0, 100, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Set invible at 0 health or 100 percent health  // "),
(@ENTRY, 0, 2, 3, 60, 0, 100, 0, 17000, 21000, 17000, 21000, 11, 74813, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 17000 and 21000 ms (for the first time, timer between 17000 and 21000 ms) - Self: Cast spell Inferno (74813) on Self // "),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 75072, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Cast spell Inferno Ping (75072) on Self // ");

-- Creature Telessra 40149 SAI
SET @ENTRY := 40149;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 42, 0, 100, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Set invible at 0 health or 100 percent health  // "),
(@ENTRY, 0, 1, 2, 8, 0, 100, 0, 75072, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Inferno Ping (75072) hit  - Self: Set react state to REACT_PASSIVE // "),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 67, 0, 5000, 5000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Trigger timed event #0 in 5000 - 5000 ms // "),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: stop attacking // "),
(@ENTRY, 0, 4, 5, 59, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On timed event 0 triggered - Self: Set react state to REACT_AGGRESSIVE // "),
(@ENTRY, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 10, 384466, 0, 0, 0, 0, 0, 0, " Linked - Self: Attack Creature Baron Geddon 40147 (384466) // ");

-- Creature Galrond of the Claw 40148 SAI
SET @ENTRY := 40148;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 42, 0, 100, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Set invible at 0 health or 100 percent health  // "),
(@ENTRY, 0, 1, 0, 25, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 10, 384466, 0, 0, 0, 0, 0, 0, "On reset (e.g. after reaching home) - Self: Attack Creature Baron Geddon 40147 (384466) // "),
(@ENTRY, 0, 2, 3, 8, 0, 100, 0, 75072, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Inferno Ping (75072) hit  - Self: Talk 0 // "),
(@ENTRY, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: stop attacking // "),
(@ENTRY, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Set react state to REACT_PASSIVE // "),
(@ENTRY, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 5467.64, -2794.14, 1517.74, 0, " Linked - Self: Move to position (5467.64, -2794.14, 1517.74, 0) (point id 0) // "),
(@ENTRY, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 67, 0, 7000, 7000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Trigger timed event #0 in 7000 - 7000 ms // "),
(@ENTRY, 0, 7, 8, 59, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On timed event 0 triggered - Self: Set react state to REACT_AGGRESSIVE // "),
(@ENTRY, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 10, 384466, 0, 0, 0, 0, 0, 0, " Linked - Self: Attack Creature Baron Geddon 40147 (384466) // ");

DELETE FROM `creature_text` WHERE `CreatureID`= 40148;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(40148, 0, 0, 'Look out!', 14, 0, 100, 0, 0, 0, 40269, 'Galrond of the Claw to Baron Geddon'),
(40148, 0, 1, 'Here it comes, fall back!', 14, 0, 100, 0, 0, 0, 40286, 'Galrond of the Claw to Baron Geddon'),
(40148, 0, 2, 'Get away from him until the fire dies down!', 14, 0, 100, 0, 0, 0, 40287, 'Galrond of the Claw to Baron Geddon'),
(40148, 0, 3, 'Fall back!!!', 14, 0, 100, 0, 0, 0, 40267, 'Galrond of the Claw to Baron Geddon');

DELETE FROM `creature_addon` WHERE `guid`= 384466;
DELETE FROM `creature_template_movement` WHERE `CreatureId`= 40147;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Rooted`) VALUES
(40147, 1, 1);
