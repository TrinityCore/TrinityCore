SET @OGUID := 239699;
SET @CGUID := 396189;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+45;
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+45;
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+56;

-- Ancient Protectors
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 52547, 861, 5733, 5738, 1, 169, 0, 0, 0, 1046.238, 307.3142, 41.71205, 2.216568, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Ancient Hyjal Protector (Area: Malfurion's Breach - Difficulty: 0) (Auras: 84667 - Generic Quest Invisibility 16)
(@CGUID+1, 52547, 861, 5733, 5738, 1, 169, 0, 0, 0, 976.632, 291.658, 45.80193, 0.9075712, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Ancient Hyjal Protector (Area: Malfurion's Breach - Difficulty: 0) (Auras: 84667 - Generic Quest Invisibility 16)
(@CGUID+2, 52547, 861, 5733, 5738, 1, 169, 0, 0, 0, 1002.93, 334.9688, 41.60677, 0.9424778, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Ancient Hyjal Protector (Area: Malfurion's Breach - Difficulty: 0) (Auras: 84667 - Generic Quest Invisibility 16)
(@CGUID+3, 52547, 861, 5733, 5738, 1, 169, 0, 0, 0, 1027.422, 300.882, 41.39303, 1.396263, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Ancient Hyjal Protector (Area: Malfurion's Breach - Difficulty: 0) (Auras: 84667 - Generic Quest Invisibility 16)
(@CGUID+4, 52547, 861, 5733, 5738, 1, 169, 0, 0, 0, 1002.779, 322.7587, 41.4849, 6.143559, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Ancient Hyjal Protector (Area: Malfurion's Breach - Difficulty: 0) (Auras: 84667 - Generic Quest Invisibility 16)
(@CGUID+5, 52547, 861, 5733, 5738, 1, 169, 0, 0, 0, 989.3577, 402.8941, 40.45579, 5.969026, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Ancient Hyjal Protector (Area: Malfurion's Breach - Difficulty: 0) (Auras: 84667 - Generic Quest Invisibility 16)
(@CGUID+6, 52547, 861, 5733, 5738, 1, 169, 0, 0, 0, 1010.448, 420.4288, 41.91743, 6.038839, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Ancient Hyjal Protector (Area: Malfurion's Breach - Difficulty: 0) (Auras: 84667 - Generic Quest Invisibility 16)
(@CGUID+7, 52547, 861, 5733, 5738, 1, 169, 0, 0, 0, 1029.269, 427.4549, 41.34233, 4.694936, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Ancient Hyjal Protector (Area: Malfurion's Breach - Difficulty: 0) (Auras: 84667 - Generic Quest Invisibility 16)
(@CGUID+8, 52547, 861, 5733, 5738, 1, 169, 0, 0, 0, 1004.21, 417.059, 42.06302, 5.445427, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Ancient Hyjal Protector (Area: Malfurion's Breach - Difficulty: 0) (Auras: 84667 - Generic Quest Invisibility 16)
(@CGUID+9, 52488, 861, 5733, 5738, 1, 169, 0, 0, 0, 995.6805, 412.4462, 40.90314, 5.637414, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595); -- Elderlimb (Area: Malfurion's Breach - Difficulty: 0) (Auras: 84667 - Generic Quest Invisibility 16)

DELETE FROM `creature_template_addon` WHERE `entry` IN (52547, 52488);
INSERT INTO `creature_template_addon` (`entry`, `bytes1`, `bytes2`, `auras`) VALUES
(52547, 65545, 1, '84667'),
(52488, 65545, 1, '84667');

-- Druids of the Talon
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+10, 53327, 861, 5733, 5738, 1, 169, 0, 0, 0, 1046.342, 340.1111, 43.53313, 6.161012, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Druid of the Talon (Area: Malfurion's Breach - Difficulty: 0) (Auras: 49414 - Generic Quest Invisibility 1)
(@CGUID+11, 53327, 861, 5733, 5738, 1, 169, 0, 0, 0, 997.408, 364.4618, 54.60411, 6.178465, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Druid of the Talon (Area: Malfurion's Breach - Difficulty: 0) (Auras: 49414 - Generic Quest Invisibility 1)
(@CGUID+12, 53327, 861, 5733, 5738, 1, 169, 0, 0, 0, 983.6979, 337.0712, 46.43773, 0.6283185, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Druid of the Talon (Area: Malfurion's Breach - Difficulty: 0) (Auras: 49414 - Generic Quest Invisibility 1)
(@CGUID+13, 53327, 861, 5733, 5738, 1, 169, 0, 0, 0, 1066.144, 390.1823, 43.59721, 6.178465, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Druid of the Talon (Area: Malfurion's Breach - Difficulty: 0) (Auras: 49414 - Generic Quest Invisibility 1)
(@CGUID+14, 53327, 861, 5733, 5738, 1, 169, 0, 0, 0, 1058.007, 429.4445, 50.11224, 0.5934119, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Druid of the Talon (Area: Malfurion's Breach - Difficulty: 0) (Auras: 49414 - Generic Quest Invisibility 1)
(@CGUID+15, 52341, 861, 5733, 5738, 1, 169, 0, 0, 0, 1054.778, 415.4618, 41.15133, 0.5235988, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Druid of the Talon (Area: Malfurion's Breach - Difficulty: 0) (Auras: 49414 - Generic Quest Invisibility 1)
(@CGUID+16, 52341, 861, 5733, 5738, 1, 169, 0, 0, 0, 1054.556, 422.6945, 41.76312, 0.3141593, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Druid of the Talon (Area: Malfurion's Breach - Difficulty: 0) (Auras: 49414 - Generic Quest Invisibility 1)
(@CGUID+17, 52341, 861, 5733, 5745, 1, 169, 0, 0, 0, 1154.993, 534.7656, 54.58353, 6.248279, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Druid of the Talon (Area: The Furnace - Difficulty: 0) (Auras: 83080 - Generic Quest Invisibility 15)
(@CGUID+18, 52341, 861, 5733, 5745, 1, 169, 0, 0, 0, 1240.542, 509.908, 59.27489, 4.066617, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Druid of the Talon (Area: The Furnace - Difficulty: 0) (Auras: 83080 - Generic Quest Invisibility 15)
(@CGUID+19, 52341, 861, 5733, 5745, 1, 169, 0, 0, 0, 1196.033, 479.7264, 59.19762, 3.236079, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Druid of the Talon (Area: The Furnace - Difficulty: 0) (Auras: 83080 - Generic Quest Invisibility 15) (possible waypoints or random movement)
(@CGUID+20, 52341, 861, 5733, 5745, 1, 169, 0, 0, 0, 1119.897, 484.053, 57.96739, 1.15168, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Druid of the Talon (Area: The Furnace - Difficulty: 0) (Auras: 83080 - Generic Quest Invisibility 15) (possible waypoints or random movement)
(@CGUID+21, 52341, 861, 5733, 5745, 1, 169, 0, 0, 0, 1252.313, 497.717, 60.74032, 3.473205, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Druid of the Talon (Area: The Furnace - Difficulty: 0) (Auras: 83080 - Generic Quest Invisibility 15)
(@CGUID+22, 52341, 861, 5733, 5745, 1, 169, 0, 0, 0, 1250.686, 534.8368, 60.64278, 1.448623, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Druid of the Talon (Area: The Furnace - Difficulty: 0) (Auras: 83080 - Generic Quest Invisibility 15)
(@CGUID+23, 53243, 861, 5733, 5745, 1, 169, 0, 0, 0, 1331.74, 597.5434, 101.0889, 2.600541, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Injured Druid of the Talon (Area: The Furnace - Difficulty: 0) (Auras: 49414 - Generic Quest Invisibility 1, 51329 - Feign Death)
(@CGUID+24, 53243, 861, 5733, 5745, 1, 169, 0, 0, 0, 1303.618, 621.0139, 79.84866, 6.195919, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595); -- Injured Druid of the Talon (Area: The Furnace - Difficulty: 0) (Auras: 49414 - Generic Quest Invisibility 1, 51329 - Feign Death)

INSERT INTO `creature_addon` (`guid`, `bytes1`, `bytes2`, `auras`) VALUES
(@CGUID+17, 65544, 1, '83080'),
(@CGUID+18, 65544, 1, '83080'),
(@CGUID+19, 65544, 1, '83080'),
(@CGUID+20, 65544, 1, '83080'),
(@CGUID+21, 65544, 1, '83080'),
(@CGUID+22, 65544, 1, '83080');

UPDATE `creature_template_addon` SET `bytes1`= 65536, `bytes2`= 1, `auras`= '49414' WHERE `entry`= 53327;
UPDATE `creature_template_addon` SET `bytes1`= 65545, `bytes2`= 1, `auras`= '49414' WHERE `entry`= 52341;
UPDATE `creature_template_addon` SET `bytes1`= 65536, `bytes2`= 1, `auras`= '49414 51329' WHERE `entry`= 53243;

-- Unique Spawns
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+25, 52495, 861, 5733, 5738, 1, 169, 0, 0, 0, 1054.106, 318.1371, 45.56224, 5.916666, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Shalis Darkhunter (Area: Malfurion's Breach - Difficulty: 0) (Auras: 49415 - Generic Quest Invisibility 2)
(@CGUID+26, 52477, 861, 5733, 5738, 1, 169, 0, 0, 0, 1023.457, 320.0087, 41.10047, 2.251475, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Tholo Whitehoof (Area: Malfurion's Breach - Difficulty: 0) (Auras: 85096 - Generic Quest Invisibility 7)
(@CGUID+27, 52134, 861, 5733, 5738, 1, 169, 0, 0, 0, 1023.188, 342.707, 42.57563, 5.043716, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Commander Jarod Shadowsong (Area: Malfurion's Breach - Difficulty: 0) (Auras: 82358 - Generic Quest Invisibility 6, 84886 - Generic Quest Invisibility 9) (possible waypoints or random movement)
(@CGUID+28, 52478, 861, 5733, 5738, 1, 169, 0, 0, 0, 1020.979, 323.1007, 41.10823, 5.445427, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Anren Shadowseeker (Area: Malfurion's Breach - Difficulty: 0) (Auras: 85096 - Generic Quest Invisibility 7)
(@CGUID+29, 53013, 861, 5733, 5738, 1, 169, 0, 0, 0, 1008.649, 333.6389, 41.47517, 5.916666, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Crimson Lasher (Area: Malfurion's Breach - Difficulty: 0) (Auras: 94222 - Generic Quest Invisibility 26) (possible waypoints or random movement)
(@CGUID+30, 52493, 861, 5733, 5738, 1, 169, 0, 0, 0, 983.2986, 367.3073, 38.21302, 1.518436, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Captain Saynna Stormrunner (Area: Malfurion's Breach - Difficulty: 0) (Auras: 49415 - Generic Quest Invisibility 2)
(@CGUID+31, 53214, 861, 5733, 5738, 1, 169, 0, 0, 0, 987.7587, 375.2344, 38.7087, 2.373648, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Damek Bloombeard (Area: Malfurion's Breach - Difficulty: 0) (Auras: 83305 - Generic Quest Invisibility 11)
(@CGUID+32, 53882, 861, 5733, 5738, 1, 169, 0, 0, 0, 997.3386, 404.7708, 40.5319, 5.689773, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Varlan Highbough (Area: Malfurion's Breach - Difficulty: 0) (Auras: 83305 - Generic Quest Invisibility 11)
(@CGUID+33, 53881, 861, 5733, 5738, 1, 169, 0, 0, 0, 1016.866, 408.9167, 41.62072, 4.921828, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Ayla Shadowstorm (Area: Malfurion's Breach - Difficulty: 0) (Auras: 83305 - Generic Quest Invisibility 11)
(@CGUID+34, 52477, 861, 5733, 5746, 1, 169, 0, 0, 0, 1215.052, 438.8993, -55.50074, 4.34587, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Tholo Whitehoof (Area: The Molten Flow - Difficulty: 0) (Auras: 83080 - Generic Quest Invisibility 15, 85096 - Generic Quest Invisibility 7)
(@CGUID+35, 52478, 861, 5733, 5746, 1, 169, 0, 0, 0, 1213.771, 434.8733, -54.65317, 1.134464, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Anren Shadowseeker (Area: The Molten Flow - Difficulty: 0) (Auras: 83080 - Generic Quest Invisibility 15, 85096 - Generic Quest Invisibility 7)
(@CGUID+36, 53233, 861, 5733, 5749, 1, 169, 0, 0, 0, 1456.585, 315.941, -93.22358, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Anren Shadowseeker (Area: Ragnaros' Reach - Difficulty: 0) (Auras: 49414 - Generic Quest Invisibility 1)
(@CGUID+37, 53481, 861, 5733, 5749, 1, 169, 0, 0, 0, 1480.615, 340.8993, 63.15188, 6.038839, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595); -- Thisalee Crow (Area: Ragnaros' Reach - Difficulty: 0) (Auras: 49414 - Generic Quest Invisibility 1, 102046 - Mark of the Wild, 83458 - No Mana Cost, Mana Regen) (possible waypoints or random movement)

INSERT INTO `creature_addon` (`guid`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(@CGUID+34, 0, 65536, 1, '83080 85096'),
(@CGUID+35, 14332, 65536, 1, '83080 85096'),
(@CGUID+36, 0, 65539, 1, '49414'),
(@CGUID+37, 0, 65536, 1, '49414');

UPDATE `creature_template_addon` SET `auras`= '49415' WHERE `entry`= 52495;
UPDATE `creature_template_addon` SET `auras`= '85096' WHERE `entry`= 52477;
UPDATE `creature_template_addon` SET `auras`= '82358 84886' WHERE `entry`= 52134;
UPDATE `creature_template_addon` SET `auras`= '85096' WHERE `entry`= 52478;
UPDATE `creature_template_addon` SET `auras`= '49414' WHERE `entry`= 53327;
UPDATE `creature_template_addon` SET `auras`= '94222' WHERE `entry`= 53013;
UPDATE `creature_template_addon` SET `auras`= '49415' WHERE `entry`= 52493;
UPDATE `creature_template_addon` SET `auras`= '83305' WHERE `entry`= 53214;
UPDATE `creature_template_addon` SET `auras`= '83305' WHERE `entry`= 53882;
UPDATE `creature_template_addon` SET `auras`= '83305' WHERE `entry`= 53881;
UPDATE `creature_template_addon` SET `auras`= '49414' WHERE `entry`= 52490;

-- Druids of the talon daily quest spawns
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+38, 53217, 861, 5733, 5738, 1, 445, 0, 0, 0, 1065.528, 421.75, 41.50949, 0.8726646, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Windcaller Voramus (Area: Malfurion's Breach - Difficulty: 0)
(@CGUID+39, 53355, 861, 5733, 5738, 1, 445, 0, 0, 0, 1066.361, 420.4028, 41.39631, 0.7504916, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Windcaller Nordrala (Area: Malfurion's Breach - Difficulty: 0) (Auras: 98566 - Enveloping Winds) (possible waypoints or random movement)
(@CGUID+40, 53329, 861, 5733, 5745, 1, 445, 0, 0, 0, 1211.379, 558.0903, 96.95512, 3.577925, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Druid of the Talon (Area: The Furnace - Difficulty: 0) (Auras: 96563 - Swift Flight Form) (possible waypoints or random movement)
(@CGUID+41, 53329, 861, 5733, 5745, 1, 445, 0, 0, 0, 1128.026, 543.4844, 89.10545, 6.108652, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Druid of the Talon (Area: The Furnace - Difficulty: 0) (Auras: 96563 - Swift Flight Form) (possible waypoints or random movement)
(@CGUID+42, 53329, 861, 5733, 5745, 1, 445, 0, 0, 0, 1144.845, 569.7552, 98.86571, 5.183628, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Druid of the Talon (Area: The Furnace - Difficulty: 0) (Auras: 96563 - Swift Flight Form) (possible waypoints or random movement)
(@CGUID+43, 53329, 861, 5733, 5745, 1, 445, 0, 0, 0, 1207.083, 523.4479, 94.79816, 2.897247, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Druid of the Talon (Area: The Furnace - Difficulty: 0) (Auras: 96563 - Swift Flight Form) (possible waypoints or random movement)
(@CGUID+44, 53329, 861, 5733, 5745, 1, 445, 0, 0, 0, 1182.547, 577.9879, 105.0961, 4.449283, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Druid of the Talon (Area: The Furnace - Difficulty: 0) (Auras: 96563 - Swift Flight Form) (possible waypoints or random movement)
(@CGUID+45, 52490, 861, 5733, 5738, 1, 169, 0, 0, 0, 1062.342, 421.4271, 41.51215, 0.8377581, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32750); -- Skylord Omnuron (Area: Malfurion's Breach - Difficulty: 0) (Auras: 49414 - Generic Quest Invisibility 1)

UPDATE `creature_template_addon` SET `auras`= '96563' WHERE `entry`= 53329;

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+649;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
-- Tree Progression spawns
(@OGUID+0, 208585, 861, 5733, 5738, 1, 169, 0, 983.3386, 373.2708, 39.01751, 2.696529, 0, 0, 0.9753418, 0.2206997, 120, 255, 1, 32750), -- Sentinel Tree (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+1, 208584, 861, 5733, 5738, 1, 169, 0, 983.4531, 373.2691, 39.03386, 2.696529, 0, 0, 0.9753418, 0.2206997, 120, 255, 1, 32750), -- Sentinel Tree (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+2, 208536, 861, 5733, 5738, 1, 169, 0, 983.4531, 373.2691, 39.03386, 2.69652, 0, 0, 0.9753408, 0.2207039, 120, 255, 1, 15595), -- Doodad_firelands_druidtree_supports01 (Area: Malfurion's Breach - Difficulty: 0)
-- Missing spawns
(@OGUID+3, 208590, 861, 5733, 5739, 1, 169, 0, 1179.615, 212.8837, 4.993687, 5.585054, 0, 0, -0.34202, 0.9396927, 120, 255, 1, 15595), -- Flame Druid Spellbook (Area: Ashen Fields - Difficulty: 0)
(@OGUID+4, 208592, 861, 5733, 5739, 1, 169, 0, 1193.398, 213.0486, 3.349515, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Flame Druid Reagent Pouch (Area: Ashen Fields - Difficulty: 0)
(@OGUID+5, 208588, 861, 5733, 5739, 1, 169, 0, 1274.785, 217.2847, 4.567804, 1.012289, 0, 0, 0.4848089, 0.8746201, 120, 255, 1, 15595), -- Flame Druid Staff (Area: Ashen Fields - Difficulty: 0)
(@OGUID+6, 208588, 861, 5733, 5739, 1, 169, 0, 1218.729, 211.7101, 4.142214, 1.588249, 0, 0, 0.7132502, 0.7009096, 120, 255, 1, 15595), -- Flame Druid Staff (Area: Ashen Fields - Difficulty: 0)
(@OGUID+7, 208593, 861, 5733, 5739, 1, 169, 0, 1284.66, 217.0694, 8.134904, 2.44346, 0, 0, 0.9396925, 0.3420205, 120, 255, 1, 15595), -- Flame Druid Idol (Area: Ashen Fields - Difficulty: 0)
(@OGUID+8, 208589, 861, 5733, 5739, 1, 169, 0, 1187.142, 182.6754, 4.421265, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Flame Druid Spellbook (Area: Ashen Fields - Difficulty: 0)
(@OGUID+9, 208570, 861, 5733, 5745, 1, 169, 0, 1176.41, 524.1354, 54.63543, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Rappelling Rope (Area: The Furnace - Difficulty: 0)
(@OGUID+10, 208592, 861, 5733, 5742, 1, 169, 0, 1165.41, 182.2483, 4.256154, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Flame Druid Reagent Pouch (Area: Forlorn Spire - Difficulty: 0)
-- Moonwell spawns
(@OGUID+11, 177281, 861, 5733, 5738, 1, 169, 0, 1020.952, 417.3433, 40.40356, 0.01064115, 0, 0, 0.005320549, 0.9999858, 120, 255, 1, 15595), -- Moonwell (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+12, 208991, 861, 5733, 5738, 1, 169, 0, 1013.805, 410.5538, 41.5762, 4.468043, 0, 0, -0.7880106, 0.6156617, 120, 255, 1, 15595), -- Firelands Apple Tree (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+13, 208993, 861, 5733, 5738, 1, 169, 0, 1012.741, 404.5573, 41.63772, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Firelands Bush (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+14, 208993, 861, 5733, 5738, 1, 169, 0, 1021.719, 408.1059, 41.67749, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Firelands Bush (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+15, 208997, 861, 5733, 5738, 1, 169, 0, 1011.896, 404.816, 42.80453, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Eternal Sunfruit (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+16, 208997, 861, 5733, 5738, 1, 169, 0, 1012.233, 403.8004, 42.5139, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Eternal Sunfruit (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+17, 208997, 861, 5733, 5738, 1, 169, 0, 1013.271, 403.9583, 43.04181, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Eternal Sunfruit (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+18, 208997, 861, 5733, 5738, 1, 169, 0, 1013.59, 405.0625, 43.33479, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Eternal Sunfruit (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+19, 208999, 861, 5733, 5738, 1, 169, 0, 1020.59, 408.5816, 42.58459, 2.670348, 0, 0, 0.9723692, 0.2334484, 120, 255, 1, 15595), -- Eternal Lunar Pear (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+20, 208999, 861, 5733, 5738, 1, 169, 0, 1021.127, 407.092, 42.93381, 2.583081, 0, 0, 0.9612608, 0.2756405, 120, 255, 1, 15595), -- Eternal Lunar Pear (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+21, 208999, 861, 5733, 5738, 1, 169, 0, 1021.741, 407.9809, 43.53746, 5.67232, 0, 0, -0.3007059, 0.9537169, 120, 255, 1, 15595), -- Eternal Lunar Pear (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+22, 208999, 861, 5733, 5738, 1, 169, 0, 1022.509, 408.8976, 42.63402, 2.583081, 0, 0, 0.9612608, 0.2756405, 120, 255, 1, 15595), -- Eternal Lunar Pear (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+23, 208999, 861, 5733, 5738, 1, 169, 0, 1022.793, 407.7708, 43.01414, 2.583081, 0, 0, 0.9612608, 0.2756405, 120, 255, 1, 15595), -- Eternal Lunar Pear (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+24, 209000, 861, 5733, 5738, 1, 169, 0, 1018.602, 410.724, 42.73047, 2.408554, 0, 0, 0.9335804, 0.358368, 120, 255, 1, 15595), -- Eternal Moonberry (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+25, 209000, 861, 5733, 5738, 1, 169, 0, 1018.641, 410.9358, 42.71748, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Eternal Moonberry (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+26, 209000, 861, 5733, 5738, 1, 169, 0, 1018.759, 410.6979, 42.74369, 1.937312, 0, 0, 0.8241253, 0.5664076, 120, 255, 1, 15595), -- Eternal Moonberry (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+27, 209001, 861, 5733, 5738, 1, 169, 0, 1018.7, 410.8073, 42.68285, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Fruit Bowl (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+28, 209002, 861, 5733, 5738, 1, 169, 0, 1011.156, 410.8142, 45.84139, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Eternal Eye of Elune (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+29, 209002, 861, 5733, 5738, 1, 169, 0, 1012.023, 413.7795, 47.02884, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Eternal Eye of Elune (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+30, 209002, 861, 5733, 5738, 1, 169, 0, 1012.521, 407.1111, 46.59412, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Eternal Eye of Elune (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+31, 209002, 861, 5733, 5738, 1, 169, 0, 1014.082, 414.5799, 43.68146, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Eternal Eye of Elune (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+32, 209002, 861, 5733, 5738, 1, 169, 0, 1016.201, 413.7465, 46.62057, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Eternal Eye of Elune (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+33, 209002, 861, 5733, 5738, 1, 169, 0, 1016.703, 411.5729, 46.00603, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Eternal Eye of Elune (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+34, 209002, 861, 5733, 5738, 1, 169, 0, 1017.484, 413.5556, 41.3039, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Eternal Eye of Elune (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+35, 209022, 861, 5733, 5738, 1, 169, 0, 1018.826, 426.0365, 41.82338, 1.433122, -0.01199436, -0.0004692078, 0.6568012, 0.7539682, 120, 255, 1, 15595), -- Moonwell Bush 08 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+36, 209023, 861, 5733, 5738, 1, 169, 0, 1021.57, 425.6736, 42.18648, 1.564023, -0.02163076, 0.0960741, 0.6981621, 0.7091344, 120, 255, 1, 15595), -- Moonwell Bush 07 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+37, 209024, 861, 5733, 5738, 1, 169, 0, 1013.846, 411.1129, 41.80089, 3.230839, 0.02772236, 0.006811142, -0.9985905, 0.04474572, 120, 255, 1, 15595), -- Moonwell Bush 06 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+38, 209025, 861, 5733, 5738, 1, 169, 0, 1030.868, 418.2465, 41.45313, 0.01068, -0.02476645, -0.01215839, 0.005039215, 0.9996066, 120, 255, 1, 15595), -- Moonwell Bush 10 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+39, 209026, 861, 5733, 5738, 1, 169, 0, 1030.276, 415.8611, 41.68923, 5.648094, -0.0273447, -0.003671646, -0.3124008, 0.9495496, 120, 255, 1, 15595), -- Moonwell Bush 09 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+40, 209027, 861, 5733, 5738, 1, 169, 0, 1026.675, 408.4965, 41.53472, 4.12966, 0, 0, -0.8804274, 0.4741811, 120, 255, 1, 15595), -- Moonwell Bush 04 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+41, 209028, 861, 5733, 5738, 1, 169, 0, 1034.924, 403.9132, 41.60938, 4.12267, 0, 0, -0.8820791, 0.4711013, 120, 255, 1, 15595), -- Moonwell Bush 01 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+42, 209029, 861, 5733, 5738, 1, 169, 0, 1032.747, 406.5608, 41.6315, 0.5644373, 0, 0, 0.2784872, 0.9604399, 120, 255, 1, 15595), -- Moonwell Bush 02 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+43, 209030, 861, 5733, 5738, 1, 169, 0, 1022.898, 408.4601, 41.63195, 4.9186, 0, 0, -0.6305742, 0.7761289, 120, 255, 1, 15595), -- Moonwell Bush 05 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+44, 209031, 861, 5733, 5738, 1, 169, 0, 1034.095, 409.4826, 41.80031, 3.799956, 0, 0, -0.9463072, 0.3232688, 120, 255, 1, 15595), -- Moonwell Bush 03 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+45, 209082, 861, 5733, 5738, 1, 169, 0, 1022.83, 407.5851, 41.48661, 4.882043, 0.1761937, 0.1188335, -0.6391706, 0.7391179, 120, 255, 1, 15595), -- Moonwell Flower 00 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+46, 209083, 861, 5733, 5738, 1, 169, 0, 1022.665, 407.533, 41.49181, 4.157733, 0.2068667, 0.04870129, -0.8595734, 0.4647235, 120, 255, 1, 15595), -- Moonwell Flower 00 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+47, 209084, 861, 5733, 5738, 1, 169, 0, 1027.873, 408.9688, 41.43092, 5.300922, 0.1476364, 0.1528692, -0.4715319, 0.8558576, 120, 255, 1, 15595), -- Moonwell Flower 00 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+48, 209085, 861, 5733, 5738, 1, 169, 0, 1030.033, 419.6684, 41.09643, 0.7281561, -0.01851368, 0.2117138, 0.3365698, 0.9173632, 120, 255, 1, 15595), -- Moonwell Flower 00 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+49, 209086, 861, 5733, 5738, 1, 169, 0, 1029.629, 420.1806, 40.88925, 1.051042, 0.007647038, 0.04052544, 0.5005083, 0.8647489, 120, 255, 1, 15595), -- Moonwell Flower 00 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+50, 209087, 861, 5733, 5738, 1, 169, 0, 1034.264, 403.8351, 41.48473, 3.607957, 0.003283024, 0.05074883, -0.971509, 0.2314823, 120, 255, 1, 15595), -- Moonwell Flower 00 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+51, 209088, 861, 5733, 5738, 1, 169, 0, 1036.054, 406.1892, 41.48473, 3.180431, -0.009962559, 0.06027031, -0.9979544, 0.01884949, 120, 255, 1, 15595), -- Moonwell Flower 00 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+52, 209089, 861, 5733, 5738, 1, 169, 0, 1032.807, 409.6927, 41.56633, 3.372342, 0.2097573, -0.0341692, -0.9719839, 0.1004074, 120, 255, 1, 15595), -- Moonwell Flower 00 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+53, 209090, 861, 5733, 5738, 1, 169, 0, 1032.352, 409.9375, 41.55592, 2.892353, -0.1956244, 0.08304691, 0.9679928, 0.1335077, 120, 255, 1, 15595), -- Moonwell Flower 00 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+54, 209091, 861, 5733, 5738, 1, 169, 0, 1032.474, 410.026, 41.56112, 2.342585, -0.1657372, 0.133029, 0.8954124, 0.3912429, 120, 255, 1, 15595), -- Moonwell Flower 00 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+55, 209092, 861, 5733, 5738, 1, 169, 0, 1022.554, 408.5434, 41.52294, 4.375896, 0.200335, 0.07093334, -0.8038721, 0.5555394, 120, 255, 1, 15595), -- Moonwell Flower 00 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+56, 208955, 861, 5733, 5738, 1, 169, 0, 1023.075, 415.6441, 42.217, 0.01064305, 0, 0, 0.005321503, 0.9999858, 120, 255, 1, 15595); -- Moonwell (Area: Malfurion's Breach - Difficulty: 0)

DELETE FROM `gameobject_addon` WHERE `guid`= 239698;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation3`, `invisibilityType`, `invisibilityValue`) VALUES
(239698, 1, 19, 100);

INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `invisibilityType`, `invisibilityValue`) VALUES
(@OGUID+0, 0, 0, 0, 1, 20, 1000),
(@OGUID+1, 0, 0, 0, 1, 19, 100),
(@OGUID+2, 0, 0, 0.9753417, 0.2206998, 19, 100), -- Doodad_firelands_druidtree_supports01
(@OGUID+11, 0, 0, 0.005321502, 0.9999858, 18, 1000), -- Moonwell
(@OGUID+12, 0, 0, 0, 1, 18, 1000),
(@OGUID+13, 0, 0, 0, 1, 18, 1000),
(@OGUID+14, 0, 0, 0, 1, 18, 1000),
(@OGUID+15, 0, 0, 0, 1, 18, 1000),
(@OGUID+16, 0, 0, 0, 1, 18, 1000),
(@OGUID+17, 0, 0, 0, 1, 18, 1000),
(@OGUID+18, 0, 0, 0, 1, 18, 1000),
(@OGUID+19, 0, 0, 0, 1, 18, 1000),
(@OGUID+20, 0, 0, 0, 1, 18, 1000),
(@OGUID+21, 0, 0, 0, 1, 18, 1000),
(@OGUID+22, 0, 0, 0, 1, 18, 1000),
(@OGUID+23, 0, 0, 0, 1, 18, 1000),
(@OGUID+24, 0, 0, 0, 1, 18, 1000),
(@OGUID+25, 0, 0, 0, 1, 18, 1000),
(@OGUID+26, 0, 0, 0, 1, 18, 1000),
(@OGUID+27, 0, 0, 0, 1, 18, 1000),
(@OGUID+28, 0, 0, 0, 1, 18, 1000),
(@OGUID+29, 0, 0, 0, 1, 18, 1000),
(@OGUID+30, 0, 0, 0, 1, 18, 1000),
(@OGUID+31, 0, 0, 0, 1, 18, 1000),
(@OGUID+32, 0, 0, 0, 1, 18, 1000),
(@OGUID+33, 0, 0, 0, 1, 18, 1000),
(@OGUID+34, 0, 0, 0, 1, 18, 1000),
(@OGUID+35, 0, 0, 0, 1, 18, 1000),
(@OGUID+36, 0, 0, 0, 1, 18, 1000),
(@OGUID+37, 0, 0, 0, 1, 18, 1000),
(@OGUID+38, 0, 0, 0, 1, 18, 1000),
(@OGUID+39, 0, 0, 0, 1, 18, 1000),
(@OGUID+40, 0, 0, 0, 1, 18, 1000),
(@OGUID+41, 0, 0, 0, 1, 18, 1000),
(@OGUID+42, 0, 0, 0, 1, 18, 1000),
(@OGUID+43, 0, 0, 0, 1, 18, 1000),
(@OGUID+44, 0, 0, 0, 1, 18, 1000),
(@OGUID+45, 0, 0, 0, 1, 18, 1000),
(@OGUID+46, 0, 0, 0, 1, 18, 1000),
(@OGUID+47, 0, 0, 0, 1, 18, 1000),
(@OGUID+48, 0, 0, 0, 1, 18, 1000),
(@OGUID+49, 0, 0, 0, 1, 18, 1000),
(@OGUID+50, 0, 0, 0, 1, 18, 1000),
(@OGUID+51, 0, 0, 0, 1, 18, 1000),
(@OGUID+52, 0, 0, 0, 1, 18, 1000),
(@OGUID+53, 0, 0, 0, 1, 18, 1000),
(@OGUID+54, 0, 0, 0, 1, 18, 1000),
(@OGUID+55, 0, 0, 0, 1, 18, 1000),
(@OGUID+56, 0, 0, 0, 1, 18, 1000);

-- Malfurion's Breach Spell Area Data
DELETE FROM `spell_area` WHERE `spell` IN (98549, 98071, 98541, 99040, 97745, 97746, 98413);
INSERT INTO `spell_area` (`spell`, `area`, `gender`, `flags`) VALUES
-- Active by Default
-- Malfurion's Breach
(99040, 5738, 2, 3), -- See Quest Invis 9
(99040, 5745, 2, 3), -- See Quest Invis 9
(98541, 5738, 2, 3), -- See Quest Invis 6
(98549, 5733, 2, 3), -- See Quest Invis 14
(98071, 5733, 2, 3), -- See Quest Invis 18
(98413, 5738, 2, 3), -- (Serverside/Non-DB2) See Quest Invis 22
-- Igneous Depths
(97745, 5741, 2, 3), -- See Quest Invis 5
(97746, 5741, 2, 3); -- See Quest Invis 6

DELETE FROM `spell_area` WHERE `spell` IN (98536, 98537, 98513, 98512, 98510, 100554);
INSERT INTO `spell_area` (`spell`, `area`, `gender`, `flags`, `aura_spell`, `quest_start`, `quest_start_status`, `quest_end`, `quest_end_status`) VALUES
-- Tree Progression
(98513, 5733, 2, 3, 0, 0, 0, 0, 0), -- See Quest Invis 13 (no tree) (removed after rewarding either "Druids of the Talon" or "The Shadow Wardens")
(98512, 5733, 2, 3, -98510, 0, 0, 0, 0), -- See Quest Invis 12 (half grown tree) (applied after rewarding either "Druids of the Talon" or "The Shadow Wardens", and removed when both are rewarded)
(98510, 5733, 2, 3, 0, 0, 0, 0, 0), -- See Quest Invis 11 (fully grown tree) (applied after rewarding "Druids of the Talon" and "The Shadow Wardens")
-- Druids of the Talon cases
(98536, 5738, 2, 3, 0, 29181, 64, 0, 0), -- See Quest Invis 1 (Druids of the Talon)
(98536, 5745, 2, 3, 0, 29181, 64, 0, 0), -- See Quest Invis 1 (Druids of the Talon)
-- The Shadow Wardens
(98537, 5738, 2, 3, 0, 29214, 64, 0, 0), -- See Quest Invis 2 (The Shadow Wardens)
(100554, 5741, 2, 3, 0, 29214, 64, 0, 0), -- See Quest Invis 29 (The Shadow Wardens)
(100554, 5740, 2, 3, 0, 29214, 64, 0, 0); -- See Quest Invis 29 (The Shadow Wardens)

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 28 AND `SourceGroup` IN (98513, 98512, 98510);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `NegativeCondition`, `ScriptName`, `Comment`) VALUES
-- Block See Quest Invis 13 after rewarding either "Druids of the Talon" or "The Shadow Wardens"
(28, 98513, 5733, 0, 0, 8, 0, 29181, 1, '', ''),
(28, 98513, 5733, 0, 0, 8, 0, 29214, 1, '', ''),
-- Block See Quest Invis 12 when until rewarding either "Druids of the Talon" or "The Shadow Wardens"
(28, 98512, 5733, 0, 0, 8, 0, 29181, 0, '', ''),
(28, 98512, 5733, 0, 1, 8, 0, 29214, 0, '', ''),
-- Block See Quest Invis 11 until rewarding "Druids of the Talon" and "The Shadow Wardens"
(28, 98510, 5733, 0, 0, 8, 0, 29181, 0, '', ''),
(28, 98510, 5733, 0, 0, 8, 0, 29214, 0, '', '');
