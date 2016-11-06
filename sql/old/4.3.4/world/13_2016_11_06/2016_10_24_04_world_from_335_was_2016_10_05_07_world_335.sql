--
/*
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=3695 AND `SourceGroup`=5;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 5, 3695, 0, 0, 28, 0, 993, 0, 0, 0, 0, 0, "", "Grimclaw - Execute SAI 4 only if player has quest A Lost Master (Part 2) complete AND"),
(22, 5, 3695, 0, 0, 29, 1, 3693, 100, 0, 1, 0, 0, "", "Grimclaw - Execute SAI 4 only if not within 100 yards of Terenthis");

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (3695, 369501, 369502);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3695, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 53, 1, 3695, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Grimclaw - On Respawn - Start Waypoint"),
(3695, 0, 1, 0, 40, 0, 100, 0, 1, 3695, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 3693, 0, 0, 0, 0, 0, 0, "Grimclaw - On WP 1 Reached (Path 3695) - Talk 0 (Terenthis)"),
(3695, 0, 2, 0, 40, 0, 100, 0, 5, 3695, 0, 0, 80, 369500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Grimclaw - On WP 5 Reached (Path 3695) - Run Actionlist"),
(3695, 0, 3, 0, 40, 0, 100, 0, 9, 3695, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Grimclaw - On WP 9 Reached (Path 3695) - Despawn"),
(3695, 0, 4, 0, 22, 0, 100, 0, 101, 50000, 50000, 0, 80, 369501, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Grimclaw - Received Emote 101 - Run Actionlist"),
(3695, 0, 5, 0, 40, 0, 100, 0, 3, 369500, 0, 0, 80, 369502, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Grimclaw - On WP 3 Reached (Path 369500) - Run Actionlist"),

(369501, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Grimclaw - On Script - Talk 4"),
(369501, 9, 1, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Grimclaw - On Script - Talk 5"),
(369501, 9, 2, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 53, 1, 369500, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Grimclaw - On Script - Start Waypoint"),

(369502, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Grimclaw - On Script - Talk 6"),
(369502, 9, 1, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 3692, 0, 0, 0, 0, 0, 0, "Grimclaw - On Script - Talk 0 (Volcor)"),
(369502, 9, 2, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Grimclaw - On Script - Despawn");

DELETE FROM `creature_text` WHERE `entry` IN (3692, 3695);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3692, 0, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=1244), 12, 7, 100, 0, 0, 0, 1244, 0, "Volcor"),
(3695, 4, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=1234), 16, 7, 100, 0, 0, 0, 1234, 0, "Grimclaw"),
(3695, 5, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=1225), 16, 7, 100, 0, 0, 0, 1225, 0, "Grimclaw"),
(3695, 6, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=1241), 16, 7, 100, 0, 0, 0, 1241, 0, "Grimclaw");

DELETE FROM `waypoints` WHERE `entry`=369500;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(369500, 1, 4685.8560, 140.07, 55.7441, "Grimclaw"),
(369500, 2, 4605.8462, 1.4452, 69.5886, "Grimclaw"),
(369500, 3, 4607.4199, -3.3206, 69.8902, "Grimclaw");
*/
