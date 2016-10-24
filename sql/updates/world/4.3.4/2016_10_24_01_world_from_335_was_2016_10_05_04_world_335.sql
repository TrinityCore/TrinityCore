--
/*
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=3695;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 3695, 0, 0, 29, 1, 3693, 100, 0, 0, 0, 0, "", "Grimclaw - Execute SAI 0 only if within 100 yards of Terenthis");

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (3695, 369500);
DELETE FROM `smart_scripts` WHERE `entryorguid`=3693 AND `id` IN (3, 4);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3693, 0, 3, 4, 20, 0, 100, 0, 985, 0, 0, 0, 83, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Terenthis - On Quest How Big a Threat? (Part 2) Rewarded - Remove Questgiver+Gossip npcflag"),
(3693, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 12, 3695, 8, 0, 0, 0, 0, 8, 0, 0, 0, 6402.4761, 368.3005, 16.3091, 1.0602, "Terenthis - On Quest How Big a Threat? (Part 2) Rewarded - Summon Grimclaw"),

(3695, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 53, 1, 3695, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Grimclaw - On Respawn - Start Waypoint"),
(3695, 0, 1, 0, 40, 0, 100, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 3693, 0, 0, 0, 0, 0, 0, "Grimclaw - On WP 1 Reached - Talk 0 (Terenthis)"),
(3695, 0, 2, 0, 40, 0, 100, 0, 5, 0, 0, 0, 80, 369500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Grimclaw - On WP 5 Reached - Run Actionlist"),
(3695, 0, 3, 0, 40, 0, 100, 0, 9, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Grimclaw - On WP 9 Reached - Despawn"),

(369500, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 54, 57000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Grimclaw - On Script - Pause Waypoint for 57 seconds"),
(369500, 9, 1, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Grimclaw - On Script - Talk 0"),
(369500, 9, 2, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 3693, 0, 0, 0, 0, 0, 0, "Grimclaw - On Script - Talk 1 (Terenthis)"),
(369500, 9, 3, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Grimclaw - On Script - Talk 1"),
(369500, 9, 4, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, 3693, 0, 0, 0, 0, 0, 0, "Grimclaw - On Script - Talk 2 (Terenthis)"),
(369500, 9, 5, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 19, 3693, 0, 0, 0, 0, 0, 0, "Grimclaw - On Script - Talk 3 (Terenthis)"),
(369500, 9, 6, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 19, 3693, 0, 0, 0, 0, 0, 0, "Grimclaw - On Script - Talk 4 (Terenthis)"),
(369500, 9, 7, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Grimclaw - On Script - Talk 2"),
(369500, 9, 8, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 5, 0, 0, 0, 0, 0, 19, 3693, 0, 0, 0, 0, 0, 0, "Grimclaw - On Script - Talk 5 (Terenthis)"),
(369500, 9, 9, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Grimclaw - On Script - Talk 3"),
(369500, 9, 10, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 6, 0, 0, 0, 0, 0, 19, 3693, 0, 0, 0, 0, 0, 0, "Grimclaw - On Script - Talk 6 (Terenthis)"),
(369500, 9, 11, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 82, 3, 0, 0, 0, 0, 0, 19, 3693, 0, 0, 0, 0, 0, 0, "Grimclaw - On Script - Add Questgiver+Gossip npcflag (Terenthis)");

DELETE FROM `waypoints` WHERE `entry`=3695;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(3695, 1, 6409.0093, 381.5969, 13.7997, "Grimclaw"),
(3695, 2, 6422.3823, 398.5416, 11.1623, "Grimclaw"),
(3695, 3, 6429.1572, 395.6921, 11.6041, "Grimclaw"),
(3695, 4, 6437.8657, 372.9119, 13.9415, "Grimclaw"),
(3695, 5, 6436.2852, 366.5291, 13.9415, "Grimclaw"),
(3695, 6, 6437.8657, 372.9119, 13.9415, "Grimclaw"),
(3695, 7, 6429.1572, 395.6921, 11.6041, "Grimclaw"),
(3695, 8, 6422.3823, 398.5416, 11.1623, "Grimclaw"),
(3695, 9, 6409.0093, 381.5969, 13.7997, "Grimclaw");

DELETE FROM `creature_text` WHERE `entry` IN (3693, 3695);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3693, 0, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=1245), 12, 7, 100, 0, 0, 0, 1245, 0, "Terenthis"),
(3693, 1, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=1227), 12, 7, 100, 0, 0, 0, 1227, 0, "Terenthis"),
(3693, 2, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=1229), 12, 7, 100, 0, 0, 0, 1229, 0, "Terenthis"),
(3693, 3, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=1246), 16, 7, 100, 0, 0, 0, 1246, 0, "Terenthis"),
(3693, 4, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=1230), 12, 7, 100, 0, 0, 0, 1230, 0, "Terenthis"),
(3693, 5, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=1232), 12, 7, 100, 0, 0, 0, 1232, 0, "Terenthis"),
(3693, 6, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=1384), 12, 7, 100, 0, 0, 0, 1384, 0, "Terenthis"),

(3695, 0, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=1226), 16, 7, 100, 0, 0, 0, 1226, 0, "Grimclaw"),
(3695, 1, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=1228), 16, 7, 100, 0, 0, 0, 1228, 0, "Grimclaw"),
(3695, 2, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=1231), 16, 7, 100, 0, 0, 0, 1231, 0, "Grimclaw"),
(3695, 3, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=1233), 16, 7, 100, 0, 0, 0, 1233, 0, "Grimclaw");
*/
