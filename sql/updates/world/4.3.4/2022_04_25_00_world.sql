DELETE FROM `creature_text` WHERE `CreatureID` IN (55624);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(55624, 0, 0, 'I see you\'ve arrived. This is the eve of the sundering, when the collapse of the Well of Eternity fractured the continents of the world.', 12, 0, 100, 0, 0, 25961, 55271, 'Nozdormu to Player'),
(55624, 1, 0, 'Here, we will snatch up the Dragon Soul before it is lost to the mists of time.', 12, 0, 100, 0, 0, 25962, 55304, 'Nozdormu to Player'),
(55624, 2, 0, 'But first, you must bring down the protective wards of Azshara\'s Highborne lackeys. You will find them within the palace. I will scout on ahead.', 12, 0, 100, 0, 0, 25963, 55305, 'Nozdormu to Player'),
(55624, 3, 0, 'Good luck, heroes!', 12, 0, 100, 0, 0, 25964, 55306, 'Nozdormu to Player');

 -- Clientside area trigger 7387
SET @ENTRY := 7387;
DELETE FROM `areatrigger_scripts` WHERE `entry` = @ENTRY;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(@ENTRY, "SmartTrigger");

DELETE FROM `smart_scripts` WHERE `entryOrGuid` = @ENTRY AND `source_type` = 2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 2, 0, 0, 46, 0, 100, 0, 0, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 10, 358721, 0, 0, 0, 0, 0, 0, "On trigger - Creature with guid 358721: Set creature data #0 to 1");

 -- Nozdormu
SET @ENTRY := 55624;
DELETE FROM `smart_scripts` WHERE `entryOrGuid` = @ENTRY AND `source_type` = 0;
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 38, 0, 100, 1, 0, 1, 0, 0, 80, 5562400, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On data[0] set to 1 - Self: Start timed action list id #5562400 (update out of combat)");

 -- Timed list 5562400
SET @ENTRY := 5562400;
DELETE FROM `smart_scripts` WHERE `entryOrGuid` = @ENTRY AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "After 0 seconds - Self: Talk 0 to invoker"),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 12500, 12500, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "After 12.5 seconds - Self: Talk 1 to invoker"),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 6200, 6200, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "After 6.2 seconds - Self: Talk 2 to invoker"),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 12000, 12000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "After 12 seconds - Self: Talk 3 to invoker");
