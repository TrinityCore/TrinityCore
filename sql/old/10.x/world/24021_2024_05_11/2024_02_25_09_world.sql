 -- Father Gavin smart ai
SET @ENTRY := 1253;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (125300);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, '', 1, 0, 100, 0, 0, 0, 120000, 130000, 80, 125300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 120 - 130 seconds (0 - 0s initially) (OOC) - Self: Start timed action list id #Father Gavin #0 (125300) (update out of combat) // -inline'),
(@ENTRY * 100, 9, 0, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Play emote ONESHOT_TALK(DNR) (1)'),
(@ENTRY * 100, 9, 1, 0, '', 0, 0, 100, 0, 4000, 4000, 0, 0, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 4 seconds - Self: Play emote ONESHOT_TALK(DNR) (1)');

 -- Kelaan smart ai
SET @ENTRY := 43354;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (4335400);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, '', 1, 0, 100, 0, 0, 0, 120000, 130000, 80, 125300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 120 - 130 seconds (0 - 0s initially) (OOC) - Self: Start timed action list id #Father Gavin #0 (125300) (update out of combat) // -inline');

 -- Lowan Featherbreeze smart ai
SET @ENTRY := 43355;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=43355;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (4335500);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, '', 1, 0, 100, 0, 0, 0, 120000, 130000, 5, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 120 - 130 seconds (0 - 0s initially) (OOC) - Self: Play emote ONESHOT_QUESTION(DNR) (6)'),
(@ENTRY, 0, 1, 0, '', 1, 0, 100, 0, 10000, 10000, 120000, 130000, 5, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 120 - 130 seconds (10 - 10s initially) (OOC) - Self: Play emote ONESHOT_EXCLAMATION(DNR) (5)'),
(@ENTRY, 0, 2, 0, '', 1, 0, 100, 0, 20000, 20000, 180000, 190000, 5, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 180 - 190 seconds (20 - 20s initially) (OOC) - Self: Play emote ONESHOT_EXCLAMATION(DNR) (5)'),
(@ENTRY, 0, 3, 0, '', 1, 0, 100, 0, 30000, 30000, 120000, 130000, 5, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 120 - 130 seconds (30 - 30s initially) (OOC) - Self: Play emote ONESHOT_POINT(DNR) (25)'),
(@ENTRY, 0, 4, 0, '', 10, 0, 100, 0, 1, 20, 300000, 300000, 80, 4335500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On only non hostile unit in line of sight (OOC) - Self: Start timed action list id #Lowan Featherbreeze #0 (4335500) (update out of combat) // -inline'),
(@ENTRY * 100, 9, 0, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 10, 306713, 1253, 0, 0, 0, 0, 0, 'After 0 seconds - Creature Father Gavin (1253) with guid 306713 (fetching): Talk 0 to invoker'),
(@ENTRY * 100, 9, 1, 0, '', 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 8 seconds - Self: Talk 0 to invoker');

DELETE FROM `creature_text` WHERE `CreatureID` IN (1253,43355);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1253, 0, 0, 'I have sent to Light\'s Hope Chapel for a grant of gold for the care of the refugees. Carry out your mission, but help as you can.', 12, 0, 100, 1, 0, 0, 43423, 0, 'Father Gavin to Lowan Featherbreeze'),
(43355, 0, 0, 'Thank you, Father Gavin. The world needs more like you and Buin in these dark times.', 12, 0, 100, 5, 0, 0, 43424, 0, 'Lowan Featherbreeze to Lowan Featherbreeze');

-- This Refugee should be sitting
DELETE FROM `creature_addon` WHERE `guid`=306707;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(306707,0,0,1,0,0,1,0,0,0,0,0,0,'');
