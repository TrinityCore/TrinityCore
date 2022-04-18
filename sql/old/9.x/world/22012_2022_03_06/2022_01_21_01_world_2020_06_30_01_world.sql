-- 
UPDATE `creature_addon` SET `emote`=0 WHERE `guid`=6460;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3191;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3191 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (319100, 319101, 319102) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3191, 0, 0, 0, 1, 0, 100, 0, 5000, 5000, 80000, 120000, 0, 80, 319100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Cook Torka - OOC - Run Script"),
(3191, 0, 1, 0, 40, 0, 100, 0, 1, 3191, 0, 0, 0, 80, 319101, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Cook Torka - On WP 1 Reached - Run Script"),
(3191, 0, 2, 0, 40, 0, 100, 0, 2, 3191, 0, 0, 0, 80, 319102, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Cook Torka - On WP 2 Reached - Run Script"),
(319100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 20, 18075, 20, 0, 0, 0, 0, 0, 0, "Cook Torka - On Script - Face Cooking Table"),
(319100, 9, 1, 0, 0, 0, 100, 0, 200, 200, 0, 0, 0, 5, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Cook Torka - On Script - Play Emote Point"),
(319100, 9, 2, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 20, 18079, 20, 0, 0, 0, 0, 0, 0, "Cook Torka - On Script - Face Bubbling Cauldron"),
(319100, 9, 3, 0, 0, 0, 100, 0, 200, 200, 0, 0, 0, 5, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Cook Torka - On Script - Play Emote Point"),
(319100, 9, 4, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 53, 0, 3191, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Cook Torka - On Script - Start WP"),
(319101, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 54, 60000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Cook Torka - On Script - Pause WP"),
(319101, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Cook Torka - On Script - Set Emote State STATE_USESTANDING"),
(319101, 9, 2, 0, 0, 0, 100, 0, 20000, 50000, 0, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Cook Torka - On Script - Remove Emote State"),
(319101, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 65, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Cook Torka - On Script - Resume WP"),
(319102, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 4.171340, "Cook Torka - On Script - Reset Orientation");

DELETE FROM `waypoints` WHERE `entry`=3191;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(3191, 1, 310.098022, -4663.778809, 16.389601, "Cook Torka"),
(3191, 2, 312.098999, -4664.950195, 16.4254, "Cook Torka");
