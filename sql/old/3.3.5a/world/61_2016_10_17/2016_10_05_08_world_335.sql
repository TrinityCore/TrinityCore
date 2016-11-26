--
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (3692, 369200, 369201);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3692, 0, 0, 1, 19, 0, 100, 0, 994, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Volcor - On Quest 'Escape Through Force' Taken - Store Targetlist"),
(3692, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 80, 369200, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Volcor - On Quest 'Escape Through Force' Taken - Run Script"),
(3692, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 91, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Volcor - On Script - Remove Sit state"),
(3692, 0, 3, 4, 19, 0, 100, 0, 995, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Volcor - On Quest 'Escape Through Stealth' Taken - Store Targetlist"),
(3692, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 369201, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Volcor - On Quest 'Escape Through Stealth' Taken - Run Script"),
(3692, 0, 5, 6, 40, 0, 100, 0, 15, 3692, 0, 0, 41, 10000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Volcor - On Waypoint 15 Reached (Path 3692) - Despawn 10 Seconds"),
(3692, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 1, 5, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, "Volcor - On Waypoint 15 Reached (Path 3692) - Say Line 5"),
(3692, 0, 7, 0, 61, 0, 100, 0, 0, 0, 0, 0, 15, 994, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, "Volcor - On Waypoint 15 Reached (Path 3692) - Quest Credit 'Escape Through Force'"),
(3692, 0, 8, 9, 40, 0, 100, 0, 2, 369200, 0, 0, 41, 5000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Volcor - On Waypoint 2 Reached (Path 369200) - Despawn 10 Seconds"),
(3692, 0, 9, 10, 61, 0, 100, 0, 0, 0, 0, 0, 15, 995, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, "Volcor - On Waypoint 15 Reached (Path 3692) - Quest Credit 'Escape Through Force'"),
(3692, 0, 10, 11, 61, 0, 100, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Volcor - On Waypoint 2 Reached (Path 369200) - Talk 2"),
(3692, 0, 11, 12, 61, 0, 100, 0, 0, 0, 0, 0, 11, 6298, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Volcor - On Waypoint 2 Reached (Path 369200) - Cast Spell 'Form of the Moonstalker'"),
(3692, 0, 12, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Volcor - On Aggro - Talk 4'"),

(369200, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Volcor - On Script - Set Unit Flags"),
(369200, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 83, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Volcor - On Script - Remove Gossip+Questgiver npcflag"),
(369200, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Volcor - On Script - Say Line 3"),
(369200, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, 3692, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, "Volcor - On Script - Start Waypoint"),

(369201, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Volcor - On Script - Set Unit Flags"),
(369201, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 83, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Volcor - On Script - Remove Gossip+Questgiver npcflag"),
(369201, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 0, "Volcor - On Script - Say Line 1"),
(369201, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, 369200, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Volcor - On Script - Start Waypoint");

DELETE FROM `creature_addon` WHERE `guid`=37096;
DELETE FROM `creature_template_addon` WHERE `entry`=3692;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(3692, 0, 0, 1, 4097, 0, "");

DELETE FROM `creature_text` WHERE `entry`=3692 AND `groupid` BETWEEN 1 AND 5;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3692, 1, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=1236), 12, 7, 100, 0, 0, 0, 1236, 0, "Volcor"),
(3692, 2, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=1238), 16, 7, 100, 0, 0, 0, 1238, 0, "Volcor"),
(3692, 3, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=1237), 12, 7, 100, 0, 0, 0, 1237, 0, "Volcor"),
(3692, 4, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=3744), 12, 7, 100, 0, 0, 0, 3744, 0, "Volcor"),
(3692, 5, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=1243), 12, 7, 100, 0, 0, 0, 1243, 0, "Volcor");

DELETE FROM `waypoints` WHERE `entry`=369200;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(369200, 1, 4606.61, 2.96905, 69.909, "Volcor"),
(369200, 2, 4612.4858, 14.2943, 69.8441, "Volcor");
