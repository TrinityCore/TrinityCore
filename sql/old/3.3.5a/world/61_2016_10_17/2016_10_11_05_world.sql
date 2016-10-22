--
SET @CGUID := 12571;
DELETE FROM `creature` WHERE `guid`=@CGUID;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID, 24900, 571, 0, 0, 1, 1, 0, 0, 529.2123, -3530.377, 12.97082, 0, 60, 0, 0, 1, 0, 2, 0, 0, 0, 0);

DELETE FROM `creature_template_addon` WHERE `entry`=24900;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(24900, 24900, 0, 0, 0, 0, "");

DELETE FROM `waypoint_data` WHERE `id`=24900;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(24900, 1, 529.2123, -3530.377, 12.97082, 0, 0, 0, 0, 100, 0),
(24900, 2, 520.7833, -3528.544, 12.92207, 0, 0, 0, 0, 100, 0),
(24900, 3, 508.5591, -3526.409, 17.6906, 0, 0, 0, 0, 100, 0),
(24900, 4, 493.6954, -3522.943, 19.64948, 0, 0, 0, 0, 100, 0),
(24900, 5, 491.2342, -3526.773, 19.97676, 0, 0, 0, 0, 100, 0),
(24900, 6, 491.6969, -3530.882, 19.5777, 0, 0, 0, 0, 100, 0),
(24900, 7, 506.2397, -3536.302, 17.54548, 0, 0, 0, 0, 100, 0),
(24900, 8, 508.6644, -3526.426, 17.6785, 0, 0, 0, 0, 100, 0),
(24900, 9, 515.7313, -3527.45, 12.96216, 0, 0, 0, 0, 100, 0),
(24900, 10, 516.2963, -3534.765, 13.07965, 0, 0, 0, 0, 100, 0),
(24900, 11, 515.4622, -3539.267, 12.93611, 0, 0, 0, 0, 100, 0),
(24900, 12, 525.4114, -3542.12, 13.04245, 0, 0, 0, 0, 100, 0),
(24900, 13, 534.911, -3545.435, 13.23027, 0, 0, 0, 0, 100, 0),
(24900, 14, 538.83, -3540.197, 13.44585, 0, 0, 0, 0, 100, 0),
(24900, 15, 536.6614, -3533.317, 13.13511, 0, 0, 0, 0, 100, 0);

DELETE FROM `creature_text` WHERE `entry`=24900;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(24900, 0, 0, "Its power courses through me! I AM A GOD!", 12, 0, 100, 0, 0, 0, 23977, 0, "Abdul the Insane"),
(24900, 0, 1, "ABDUL IS STRONG LIKE BULL!", 12, 0, 100, 0, 0, 0, 23978, 0, "Abdul the Insane"),
(24900, 1, 0, "The fury of the Vrykul will consume you!", 12, 0, 100, 0, 0, 0, 23976, 0, "Abdul the Insane"),
(24900, 1, 1, "ARE YOU CHALLENGING ME? I HAVE THE STRENGTH OF TEN MEN!", 12, 0, 100, 0, 0, 0, 23979, 0, "Abdul the Insane");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=24900;
DELETE FROM `smart_scripts` WHERE entryorguid=24900;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24900, 0, 0, 0, 1, 0, 100, 0, 2000, 2000, 10000, 10000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Abdul the Insane - Out of Combat - Talk 0"),
(24900, 0, 1, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Abdul the Insane - On Aggro - Talk 1");
