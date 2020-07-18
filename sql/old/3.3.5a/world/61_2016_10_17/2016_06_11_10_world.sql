-- 
DELETE FROM `conditions` WHERE `SourceEntry` IN (403, 308) AND `SourceTypeOrReferenceId` IN (19, 20);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(19, 0, 403, 0, 0, 28, 0, 310, 0, 0, 0, 0, 0, "", "Show quest 'Guarded Thunderbrew Barrel' if quest 'Bitter Rivals' is completed"),
(20, 0, 403, 0, 0, 28, 0, 310, 0, 0, 0, 0, 0, "", "Show quest 'Guarded Thunderbrew Barrel' if quest 'Bitter Rivals' is completed"),
(19, 0, 308, 0, 0, 8, 0, 403, 0, 0, 0, 0, 0, "", "Show quest 'Distracting Jarven' if quest 'Guarded Thunderbrew Barrel' is rewarded"),
(20, 0, 308, 0, 0, 8, 0, 403, 0, 0, 0, 0, 0, "", "Show quest 'Distracting Jarven' if quest 'Guarded Thunderbrew Barrel' is rewarded"),
(19, 0, 308, 0, 0, 28, 0, 310, 0, 0, 0, 0, 0, "", "Show quest 'Distracting Jarven' if quest 'Bitter Rivals' is completed"),
(20, 0, 308, 0, 0, 28, 0, 310, 0, 0, 0, 0, 0, "", "Show quest 'Distracting Jarven' if quest 'Bitter Rivals' is completed");

DELETE FROM `creature_text` WHERE `entry`=1373 AND `groupid`=0;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(1373, 0, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `id`=127), 12, 7, 100, 1, 0, 0, 127, 0, "Jarven Thunderbrew");

UPDATE `gameobject` SET `position_x`=-5607.24, `position_y`=-547.934, `position_z`=392.985 WHERE `id`=270;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1373, 137300);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1373, 0, 0, 1, 20, 0, 100, 0, 308, 0, 0, 0, 53, 0, 1373, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Jarven Thunderbrew - On Quest Rewarded - Start WP"),
(1373, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 83, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Jarven Thunderbrew - On Quest Rewarded - Remove Questgiver Flag"),
(1373, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Jarven Thunderbrew - On Quest Rewarded - Say Line 0"),
(1373, 0, 3, 4, 40, 0, 100, 0, 2, 0, 0, 0, 41, 44, 0, 0, 0, 0, 0, 14, 1037, 269, 0, 0, 0, 0, 0, "Jarven Thunderbrew - On WP 2 Reached - Despawn Closest Gameobject \'Guarded Thunder Ale Barrel\'"),
(1373, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 70, 45, 0, 0, 0,0, 0, 14, 35875, 270, 0, 0, 0, 0, 0, "Jarven Thunderbrew - On WP 2 Reached - Respawn Closest Gameobject \'Unguarded Thunder Ale Barrel\'"),
(1373, 0, 5, 6, 40, 0, 100, 0, 8, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Jarven Thunderbrew - On WP 8 Reached - Say Line 1"),
(1373, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 5.6724, "Jarven Thunderbrew - On WP 8 Reached - Turn"),
(1373, 0, 7, 0, 61, 0, 100, 0, 0, 0, 0, 0, 54, 10000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Jarven Thunderbrew - On WP 8 Reached - Pause WP for 10 seconds"),
(1373, 0, 8, 0, 40, 0, 100, 0, 15, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Jarven Thunderbrew - On WP 15 Reached - Say Line 2"),
(1373, 0, 9, 10, 58, 0, 100, 0, 0, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Jarven Thunderbrew - On WP Ended - Say Line 3"),
(1373, 0, 10, 11, 61, 0, 100, 0, 0, 0, 0, 0, 82, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Jarven Thunderbrew - On WP Ended - Add Questgiver Flag"),
(1373, 0, 11, 0, 61, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Jarven Thunderbrew - On WP Ended - Reset Orientation");

DELETE FROM `waypoints` WHERE `entry`= 1373;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(1373,  1, -5601.64, -541.38, 392.42, 'Jarven Thunderbrew - Quest 308 Waypoint movement'),
(1373,  2, -5597.94, -542.04, 392.42, 'Jarven Thunderbrew - Quest 308 Waypoint movement'),
(1373,  3, -5597.95, -548.43, 395.48, 'Jarven Thunderbrew - Quest 308 Waypoint movement'),
(1373,  4, -5605.31, -549.33, 399.09, 'Jarven Thunderbrew - Quest 308 Waypoint movement'),
(1373,  5, -5607.55, -546.63, 399.09, 'Jarven Thunderbrew - Quest 308 Waypoint movement'),
(1373,  6, -5597.52, -538.75, 399.09, 'Jarven Thunderbrew - Quest 308 Waypoint movement'),
(1373,  7, -5597.62, -530.24, 399.65, 'Jarven Thunderbrew - Quest 308 Waypoint movement'),
(1373,  8, -5603.67, -529.91, 399.65, 'Jarven Thunderbrew - Quest 308 Waypoint movement'),
(1373,  9, -5603.67, -529.91, 399.65, 'Jarven Thunderbrew - Quest 308 Waypoint movement'),
(1373, 10, -5597.62, -530.24, 399.65, 'Jarven Thunderbrew - Quest 308 Waypoint movement'),
(1373, 11, -5597.52, -538.75, 399.09, 'Jarven Thunderbrew - Quest 308 Waypoint movement'),
(1373, 12, -5607.55, -546.63, 399.09, 'Jarven Thunderbrew - Quest 308 Waypoint movement'),
(1373, 13, -5605.31, -549.33, 399.09, 'Jarven Thunderbrew - Quest 308 Waypoint movement'),
(1373, 14, -5597.95, -548.43, 395.48, 'Jarven Thunderbrew - Quest 308 Waypoint movement'),
(1373, 15, -5597.94, -542.04, 392.42, 'Jarven Thunderbrew - Quest 308 Waypoint movement'),
(1373, 16, -5601.64, -541.38, 392.42, 'Jarven Thunderbrew - Quest 308 Waypoint movement'),
(1373, 17, -5605.96, -544.45, 392.43, 'Jarven Thunderbrew - Quest 308 Waypoint movement');
