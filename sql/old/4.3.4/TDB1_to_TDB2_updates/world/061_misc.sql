SET @OGUID = 119;

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+2;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0, 207465, 0, 1, 1, 1332.377, 334.507, -63.70291, 3.42085, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: -Unknown-)
(@OGUID+1, 207465, 0, 1, 1, 1262.533, 353.8299, -63.69088, 5.480334, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Lordamere Lake)
(@OGUID+2, 2045, 0, 1, 1, 1286.95, 225.642, -6.62013, 0.8552105, 0, 0, 0, 1, 120, 255, 1); -- Stranglekelp (Area: Lordamere Lake)


DELETE FROM `creature_template_addon` WHERE `entry` IN (13839, 34983, 50676, 4076, 16030, 49965, 6033, 36517, 36273, 44004, 16287, 20406, 34985, 2227, 34281);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(13839, 0, 0x0, 0x101, ''), -- Royal Dreadguard
(34983, 0, 0x0, 0x101, ''), -- Deathstalker Fane
(50676, 0, 0x0, 0x100, ''), -- Hans Crump
(4076, 0, 0x0, 0x1, ''), -- Roach
(16030, 0, 0x0, 0x1, ''), -- Maggot
(49965, 0, 0x0, 0x1, ''), -- Undercity Rat
(6033, 0, 0x0, 0x1, ''), -- Lake Frenzy
(36517, 0, 0x0, 0x101, ''), -- Aleric Hawkins
(36273, 0, 0x0, 0x101, ''), -- Bragor Bloodfist
(44004, 0, 0x0, 0x101, ''), -- Gilnean Envoy
(16287, 0, 0x0, 0x101, ''), -- Ambassador Sunsorrow
(20406, 0, 0x0, 0x100, ''), -- Champion Cyssa Dawnrose
(34985, 0, 0x0, 0x101, '12544'), -- Misery - Frost Armor
(2227, 0, 0x0, 0x101, ''), -- Sharlindra
(34281, 0, 0x0, 0x1, ''); -- [DND]Azeroth Children's Week Trigger



UPDATE `creature_model_info` SET `bounding_radius`=0.4213, `combat_reach`=1.65, `gender`=0 WHERE `modelid`=37090;

SET @CGUID = 385;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+22;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 13839, 0, 1, 1, 1281.101, 370.935, -63.57857, 4.939282, 120, 0, 0), -- Royal Dreadguard (Area: -Unknown-)
(@CGUID+1, 34983, 0, 1, 1, 1329.953, 341.6042, -63.6265, 3.525565, 120, 0, 0), -- Deathstalker Fane (Area: -Unknown-)
(@CGUID+2, 50676, 0, 1, 1, 1331.262, 334.0868, -63.63684, 3.403392, 120, 0, 0), -- Hans Crump (Area: -Unknown-) - Gilneas BG
(@CGUID+3, 4076, 0, 1, 1, 1310.228, 353.3649, -64.42487, 2.595487, 120, 0, 0), -- Roach (Area: -Unknown-)
(@CGUID+4, 16030, 0, 1, 1, 1307.566, 343.0593, -65.02709, 6.063225, 120, 0, 0), -- Maggot (Area: -Unknown-)
(@CGUID+5, 49965, 0, 1, 1, 1276.475, 350.8702, -65.02737, 3.944469, 120, 0, 0), -- Undercity Rat (Area: -Unknown-)
(@CGUID+6, 6033, 0, 1, 1, 1314.068, 313.4127, -12.10303, 1.43117, 120, 0, 0), -- Lake Frenzy (Area: Lordamere Lake)
(@CGUID+7, 36517, 0, 1, 1, 1283.84, 338.9167, -59.9998, 0.2443461, 120, 0, 0), -- Aleric Hawkins (Area: Lordamere Lake)
(@CGUID+8, 36273, 0, 1, 1, 1287.698, 333.5885, -59.9998, 0.9599311, 120, 0, 0), -- Bragor Bloodfist (Area: Lordamere Lake)
(@CGUID+9, 44004, 0, 1, 1, 1265.314, 353.7483, -63.63676, 4.153883, 120, 0, 0), -- Gilnean Envoy (Area: Lordamere Lake) - Gilneas BG
(@CGUID+10, 16287, 0, 1, 1, 1298.247, 319.007, -58.66997, 1.58825, 120, 0, 0), -- Ambassador Sunsorrow (Area: Lordamere Lake)
(@CGUID+11, 44004, 0, 1, 1, 1263.184, 350.7778, -63.64588, 0.9773844, 120, 0, 0), -- Gilnean Envoy (Area: Lordamere Lake) - Gilneas BG
(@CGUID+12, 20406, 0, 1, 1, 1298.995, 316.802, -58.44917, 6.091199, 120, 0, 0), -- Champion Cyssa Dawnrose (Area: Lordamere Lake)
(@CGUID+13, 34985, 0, 1, 1, 1333.509, 326.4167, -63.63265, 3.333579, 120, 0, 0), -- Misery (Area: Lordamere Lake)
(@CGUID+14, 2227, 0, 1, 1, 1277.51, 320.3199, -59.99975, 1.466077, 120, 0, 0), -- Sharlindra (Area: Lordamere Lake)
(@CGUID+15, 34281, 0, 1, 1, 1293.111, 325.9792, -58.80117, 4.433136, 120, 0, 0), -- [DND]Azeroth Children's Week Trigger (Area: Lordamere Lake)
(@CGUID+16, 16030, 0, 1, 1, 1312.322, 309.3196, -65.02728, 5.244617, 120, 0, 0), -- Maggot (Area: Lordamere Lake)
(@CGUID+17, 49965, 0, 1, 1, 1254.394, 307.8, -63.71021, 0.5068001, 120, 0, 0), -- Undercity Rat (Area: Lordamere Lake)
(@CGUID+18, 13839, 0, 1, 1, 1258.26, 289.543, -63.5786, 0.7853982, 120, 0, 0), -- Royal Dreadguard (Area: Lordamere Lake)
(@CGUID+19, 13839, 0, 1, 1, 1306.302, 276.6052, -63.57735, 1.867502, 120, 0, 0), -- Royal Dreadguard (Area: Lordamere Lake)
(@CGUID+20, 4076, 0, 1, 1, 1276.305, 283.0632, -62.65993, 3.334034, 120, 0, 0), -- Roach (Area: Lordamere Lake)
(@CGUID+21, 49965, 0, 1, 1, 1308.361, 277.5474, -62.83587, 6.041068, 120, 0, 0), -- Undercity Rat (Area: Lordamere Lake)
(@CGUID+22, 6033, 0, 1, 1, 1273.186, 262.8698, -6.450799, 3.682645, 120, 0, 0); -- Lake Frenzy (Area: Lordamere Lake)

DELETE FROM `creature_equip_template` WHERE `entry` IN (13839, 34983, 50676, 36517, 36273, 16287, 20406, 34985);
INSERT INTO `creature_equip_template` (`entry`, `itemEntry1`, `itemEntry2`, `itemEntry3`) VALUES
(13839, 18167, 18166, 15460), -- Royal Dreadguard
(34983, 46981, 0, 0), -- Deathstalker Fane
(50676, 40004, 0, 0), -- Hans Crump
(36517, 22215, 22215, 0), -- Aleric Hawkins
(36273, 33276, 0, 5258), -- Bragor Bloodfist
(16287, 24321, 0, 0), -- Ambassador Sunsorrow
(20406, 27405, 27406, 0), -- Champion Cyssa Dawnrose
(34985, 46984, 0, 0); -- Misery
