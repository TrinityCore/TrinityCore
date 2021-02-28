-- Creature Tainted Sentry 40925 SAI
SET @ENTRY := 40925;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 6, 0, 100, 0, 0, 0, 0, 0, 11, 76625, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On death - Self: Cast spell Summon Unstable Corruptions (76625) on Self // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 18000, 20000, 18000, 20000, 11, 76634, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 18000 min and 20000 max ms (repeat 18000 min 20000 max ms) - Self: Cast spell Swell (76634) on Self // ");

UPDATE `creature_template` SET `mechanic_immune_mask`= 0x1 | 0x2 | 0x4 | 0x8 | 0x10 | 0x20 | 0x40 | 0x200 | 0x800 | 0x1000 | 0x2000 | 0x10000 | 0x400000 | 0x800000, `flags_extra`= `flags_extra` | 0x40000000 WHERE `entry` IN (40925, 49102);

-- Creature Unstable Corruption 40923 SAI
SET @ENTRY := 40923;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On AI initialize - Self: Set react state to REACT_PASSIVE // "),
(@ENTRY, 0, 1, 0, 63, 0, 100, 0, 0, 0, 0, 0, 80, 4092300, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Start timed action list id #4092300 // "),
(@ENTRY, 0, 2, 0, 6, 2, 100, 0, 0, 0, 0, 0, 11, 76363, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On death - Self: Cast spell Wave of Corruption (76363) on Self // "),
(@ENTRY, 0, 3, 0, 60, 0, 100, 1, 2000, 2000, 0, 0, 11, 76362, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 2000 and 2000 ms) - Self: Cast spell Unstable Corruption Growth (76362) on Self // "),
(@ENTRY, 0, 4, 0, 8, 0, 100, 0, 3617, 0, 0, 0, 41, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell 3617 hit  - Self: Despawn in 3000 ms // ");

-- TimedActionList  4092300 SAI
SET @ENTRY := 4092300;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 89, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 5000 min and 5000 max ms (repeat 0 min 0 max ms) - Self: Move in radius 7 yards // "),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 0 min and 0 max ms (repeat 0 min 0 max ms) - Self: Set react state to REACT_AGGRESSIVE // "),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 0 min and 0 max ms (repeat 0 min 0 max ms) - Self: Set event phase to 2 // ");

SET @CGUID := 396637;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+22;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 40923, 643, 5004, 0, 3, 169, 0, 0, 0, -300.79901123046875, 951.61102294921875, 235.7513275146484375, 0, 30, 0, 0, 3095, 0, 0, 0, 0, 0, 15595), -- Unstable Corruption (Area: 0 - Difficulty: 0) (Auras: 76362 - Unstable Corruption Growth) (possible waypoints or random movement)
(@CGUID+1, 40923, 643, 5004, 0, 3, 169, 0, 0, 0, -304.45098876953125, 955.91497802734375, 235.412322998046875, 0, 30, 0, 0, 3095, 0, 0, 0, 0, 0, 15595), -- Unstable Corruption (Area: 0 - Difficulty: 0) (Auras: 76362 - Unstable Corruption Growth) (possible waypoints or random movement)
(@CGUID+2, 40923, 643, 5004, 0, 3, 169, 0, 0, 0, -306.3389892578125, 951.5469970703125, 235.443328857421875, 0, 30, 0, 0, 3095, 0, 0, 0, 0, 0, 15595), -- Unstable Corruption (Area: 0 - Difficulty: 0) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+3, 40923, 643, 5004, 0, 3, 169, 0, 0, 0, -308.239990234375, 946.11798095703125, 235.71832275390625, 0, 30, 0, 0, 3095, 0, 0, 0, 0, 0, 15595), -- Unstable Corruption (Area: 0 - Difficulty: 0) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+4, 40923, 643, 5004, 0, 3, 169, 0, 0, 0, -291.816009521484375, 972.72900390625, 235.97833251953125, 0, 30, 0, 0, 3095, 0, 0, 0, 0, 0, 15595), -- Unstable Corruption (Area: 0 - Difficulty: 0) (Auras: 76362 - Unstable Corruption Growth) (possible waypoints or random movement)
(@CGUID+5, 40923, 643, 5004, 0, 3, 169, 0, 0, 0, -295.2030029296875, 961.8699951171875, 235.8903350830078125, 0, 30, 0, 0, 3095, 0, 0, 0, 0, 0, 15595), -- Unstable Corruption (Area: 0 - Difficulty: 0) (Auras: 76362 - Unstable Corruption Growth) (possible waypoints or random movement)
(@CGUID+6, 40923, 643, 5004, 0, 3, 169, 0, 0, 0, -301.6610107421875, 955.98101806640625, 235.4143218994140625, 0, 30, 0, 0, 3095, 0, 0, 0, 0, 0, 15595), -- Unstable Corruption (Area: 0 - Difficulty: 0) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+7, 40923, 643, 5004, 0, 3, 169, 0, 0, 0, -304.983001708984375, 951.6199951171875, 235.25732421875, 0, 30, 0, 0, 3095, 0, 0, 0, 0, 0, 15595), -- Unstable Corruption (Area: 0 - Difficulty: 0) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+8, 40923, 643, 5004, 0, 3, 169, 0, 0, 0, -299.322998046875, 957.38201904296875, 235.628326416015625, 0, 30, 0, 0, 3095, 0, 0, 0, 0, 0, 15595), -- Unstable Corruption (Area: 0 - Difficulty: 0) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+9, 40923, 643, 5004, 0, 3, 169, 0, 0, 0, -306.303985595703125, 948.01397705078125, 235.451324462890625, 0, 30, 0, 0, 3095, 0, 0, 0, 0, 0, 15595), -- Unstable Corruption (Area: 0 - Difficulty: 0) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+10, 40923, 643, 5004, 0, 3, 169, 0, 0, 0, -307.571014404296875, 947.8800048828125, 235.6393280029296875, 0, 30, 0, 0, 3095, 0, 0, 0, 0, 0, 15595), -- Unstable Corruption (Area: 0 - Difficulty: 0) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+11, 40923, 643, 5004, 0, 3, 169, 0, 0, 0, -297.77301025390625, 961.75897216796875, 235.5713348388671875, 0, 30, 0, 0, 3095, 0, 0, 0, 0, 0, 15595), -- Unstable Corruption (Area: 0 - Difficulty: 0) (Auras: 76362 - Unstable Corruption Growth) (possible waypoints or random movement)
(@CGUID+12, 40923, 643, 5004, 0, 3, 169, 0, 0, 0, -290.519012451171875, 966.53302001953125, 235.8633270263671875, 0, 30, 0, 0, 3095, 0, 0, 0, 0, 0, 15595), -- Unstable Corruption (Area: 0 - Difficulty: 0) (Auras: 76362 - Unstable Corruption Growth) (possible waypoints or random movement)
(@CGUID+13, 40923, 643, 5004, 0, 3, 169, 0, 0, 0, -295.54998779296875, 957.9320068359375, 236.0663299560546875, 0, 30, 0, 0, 3095, 0, 0, 0, 0, 0, 15595), -- Unstable Corruption (Area: 0 - Difficulty: 0) (Auras: 76362 - Unstable Corruption Growth) (possible waypoints or random movement)
(@CGUID+14, 40923, 643, 5004, 0, 3, 169, 0, 0, 0, -302.89898681640625, 948.0469970703125, 235.771331787109375, 0, 30, 0, 0, 3095, 0, 0, 0, 0, 0, 15595), -- Unstable Corruption (Area: 0 - Difficulty: 0) (Auras: 76362 - Unstable Corruption Growth) (possible waypoints or random movement)
(@CGUID+15, 40923, 643, 5004, 0, 3, 169, 0, 0, 0, -308.2239990234375, 941.32098388671875, 235.9063262939453125, 0, 30, 0, 0, 3095, 0, 0, 0, 0, 0, 15595), -- Unstable Corruption (Area: 0 - Difficulty: 0) (Auras: 76362 - Unstable Corruption Growth) (possible waypoints or random movement)
(@CGUID+16, 40923, 643, 5004, 0, 3, 169, 0, 0, 0, -301.572998046875, 959.4010009765625, 235.4883270263671875, 0, 30, 0, 0, 3095, 0, 0, 0, 0, 0, 15595), -- Unstable Corruption (Area: 0 - Difficulty: 0) (Auras: 76362 - Unstable Corruption Growth) (possible waypoints or random movement)
(@CGUID+17, 40923, 643, 5004, 0, 3, 169, 0, 0, 0, -297.735992431640625, 952.08197021484375, 236.1343231201171875, 0, 30, 0, 0, 3095, 0, 0, 0, 0, 0, 15595), -- Unstable Corruption (Area: 0 - Difficulty: 0) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+18, 40923, 643, 5004, 0, 3, 169, 0, 0, 0, -282.6719970703125, 973.60198974609375, 236.0653228759765625, 0, 30, 0, 0, 3095, 0, 0, 0, 0, 0, 15595), -- Unstable Corruption (Area: 0 - Difficulty: 0) (Auras: 76362 - Unstable Corruption Growth) (possible waypoints or random movement)
(@CGUID+19, 40923, 643, 5004, 0, 3, 169, 0, 0, 0, -301.917999267578125, 948.36297607421875, 235.8583221435546875, 0, 30, 0, 0, 3095, 0, 0, 0, 0, 0, 15595), -- Unstable Corruption (Area: 0 - Difficulty: 0) (Auras: 76362 - Unstable Corruption Growth) (possible waypoints or random movement)
(@CGUID+20, 40923, 643, 5004, 0, 3, 169, 0, 0, 0, -290.704986572265625, 969.60797119140625, 235.7383270263671875, 0, 30, 0, 0, 3095, 0, 0, 0, 0, 0, 15595), -- Unstable Corruption (Area: 0 - Difficulty: 0) (Auras: 76362 - Unstable Corruption Growth) (possible waypoints or random movement)
(@CGUID+21, 40923, 643, 5004, 0, 3, 169, 0, 0, 0, -292.420013427734375, 970.99798583984375, 235.925323486328125, 0, 30, 0, 0, 3095, 0, 0, 0, 0, 0, 15595), -- Unstable Corruption (Area: 0 - Difficulty: 0) (Auras: 76362 - Unstable Corruption Growth) (possible waypoints or random movement)
(@CGUID+22, 40923, 643, 5004, 0, 3, 169, 0, 0, 0, -300.197998046875, 962.08502197265625, 235.5273284912109375, 0, 30, 0, 0, 3095, 0, 0, 0, 0, 0, 15595); -- Unstable Corruption (Area: 0 - Difficulty: 0) (Auras: 76362 - Unstable Corruption Growth) (possible waypoints or random movement)

DELETE FROM `spawn_group_template` WHERE `groupId` IN (455);
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(455, 'Throne of the Tides - Ozumat Wing Event', 4);

DELETE FROM `spawn_group` WHERE `groupId` IN (455);
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(455, 0, @CGUID+0),
(455, 0, @CGUID+1),
(455, 0, @CGUID+2),
(455, 0, @CGUID+3),
(455, 0, @CGUID+4),
(455, 0, @CGUID+5),
(455, 0, @CGUID+6),
(455, 0, @CGUID+7),
(455, 0, @CGUID+8),
(455, 0, @CGUID+9),
(455, 0, @CGUID+10),
(455, 0, @CGUID+11),
(455, 0, @CGUID+12),
(455, 0, @CGUID+13),
(455, 0, @CGUID+14),
(455, 0, @CGUID+15),
(455, 0, @CGUID+16),
(455, 0, @CGUID+17),
(455, 0, @CGUID+18),
(455, 0, @CGUID+19),
(455, 0, @CGUID+20),
(455, 0, @CGUID+21),
(455, 0, @CGUID+22),
(455, 0, 255115),
(455, 0, 255117),
(455, 0, 255119),
(455, 0, 255120);
