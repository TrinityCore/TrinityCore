DELETE FROM `creature_addon` WHERE `guid`=95560;
DELETE FROM `waypoint_data` WHERE `id`=955600;
DELETE FROM `waypoints` WHERE `entry`=24576;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(24576, 1, 1904.01, 6088.15, -0.689379, "Riplash Myrmidon"),
(24576, 2, 1903.87, 6078.13, 3.32637, "Riplash Myrmidon"),
(24576, 3, 1894.83, 6048.11, 4.13374, "Riplash Myrmidon"),
(24576, 4, 1893.75, 6027.49, 5.05886, "Riplash Myrmidon"),
(24576, 5, 1903.62, 6023.29, 7.5437, "Riplash Myrmidon");
UPDATE `creature` SET `MovementType`=0, `spawndist`=0, `spawntimesecs`=60 WHERE `guid`=95560;

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (24576, 25521, 25636);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-95560, 25521, 25636, 2563600) AND `source_type` IN (0, 9);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-95560, 0, 0, 1, 11, 0, 100, 0, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Riplash Myrmidon - On Spawn - Set UnitFlag IMMUNE_TO_PC+NPC"),
(-95560, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 53, 1, 24576, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, "Riplash Myrmidon - On Spawn - Start WP"),
(-95560, 0, 2, 3, 40, 0, 100, 0, 4, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Riplash Myrmidon - On WP 4 Reached - Remove UnitFlag IMMUNE_TO_PC+NPC"),
(-95560, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 25521, 0, 0, 0, 0, 0, 0, "Riplash Myrmidon - On WP 4 Reached - Say text (Skadir Longboatsman)"),
(-95560, 0, 4, 0, 61, 0, 100, 0, 00, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 19, 25636, 0, 0, 0, 0, 0, 0, "Riplash Myrmidon - On WP 4 Reached - Attack Captured Tuskarr Prisoner"),
(-95560, 0, 5, 6, 6, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 25521, 0, 0, 0, 0, 0, 0, "Riplash Myrmidon - On Death - Say text (Skadir Longboatsman)"),
(-95560, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 2563600, 2, 0, 0, 0, 0, 19, 25636, 0, 0, 0, 0, 0, 0, "Riplash Myrmidon - On Death - action list (Captured Tuskarr Prisoner)"),
(25636, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 83, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Captured Tuskarr Prisoner - On Spawn - Remove Questgiver Npcflag"),
(2563600, 9, 0, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 82, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Captured Tuskarr Prisoner - On Script - Add Questgiver Npcflag"),
(2563600, 9, 1, 0, 0, 0, 100, 0, 60000, 60000, 0, 0, 83, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Captured Tuskarr Prisoner - On Script - Remove Questgiver Npcflag");

DELETE FROM `creature_text` WHERE `CreatureID`=25521;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(25521, 0, 0, "Send in the next pair of prisoners, let them fight to see who lives!", 14, 0, 100, 0, 0, 0, 24823, 0, "Skadir Longboatsman"),
(25521, 1, 0, "You may have survived for our amusement, but now, you shall die at our hands!", 14, 0, 100, 0, 0, 0, 24819, 0, "Skadir Longboatsman");
