SET @CGUID := 10004653;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+51;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 224150, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1711.138916015625, -2173.8369140625, 14.35614013671875, 3.724487781524658203, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Nerubian Skirmisher (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+1, 222757, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1714.7083740234375, -2172.013916015625, 22.04101181030273437, 2.975986480712890625, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Shalewing Devourer (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+2, 221681, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1804.98095703125, -2187.536376953125, 13.35955142974853515, 1.996882319450378417, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Slithering Shalescale (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+3, 224149, 2552, 14717, 14788, '0', 0, 0, 0, 1, 1767.736083984375, -2241.890625, 13.70032119750976562, 4.762797355651855468, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Nerubian Webspinner (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+4, 224150, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1820.8489990234375, -2207.454833984375, 13.41629695892333984, 3.849431991577148437, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Nerubian Skirmisher (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+5, 221681, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1784.0625, -2242.536376953125, 12.62041187286376953, 5.570622920989990234, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Slithering Shalescale (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+6, 222057, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1799.21875, -2129.632080078125, 33.86891555786132812, 4.908735275268554687, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Isle Gull (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+7, 224149, 2552, 14717, 14788, '0', 0, 0, 0, 1, 1736.8472900390625, -2177.928955078125, 14.47124385833740234, 1.280963420867919921, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Nerubian Webspinner (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+8, 224150, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1749.6666259765625, -2198.005126953125, 12.66548633575439453, 2.087843656539916992, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Nerubian Skirmisher (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+9, 224149, 2552, 14717, 14788, '0', 0, 0, 0, 1, 1804.7569580078125, -2184.928955078125, 15.04805183410644531, 2.462465763092041015, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Nerubian Webspinner (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+10, 224150, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1777.4149169921875, -2208.390625, 13.52799129486083984, 3.111586332321166992, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Nerubian Skirmisher (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+11, 225702, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1758.6441650390625, -2190.057373046875, 14.68305397033691406, 3.81226348876953125, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Nerubian Swarmite (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+12, 225702, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1759.3680419921875, -2195.366455078125, 14.18864631652832031, 4.245685577392578125, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Nerubian Swarmite (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+13, 225702, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1762.66845703125, -2192.07470703125, 14.77129459381103515, 0.20508924126625061, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Nerubian Swarmite (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+14, 222035, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1786.35595703125, -2117.390625, -2.35906600952148437, 5.754299640655517578, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Softshell Pincher (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+15, 222057, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1666.79345703125, -2130.755126953125, 46.84708023071289062, 1.374449968338012695, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Isle Gull (Area: The Opalcreg - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+16, 222037, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1658.0660400390625, -2096.61279296875, 1.4975510835647583, 1.744527339935302734, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Opalshell Scuttler (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+17, 222057, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1626.3350830078125, -2147.80029296875, 41.19805526733398437, 1.178097367286682128, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Isle Gull (Area: The Opalcreg - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+18, 222037, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1706.40625, -2141.703125, 7.975809097290039062, 1.191920995712280273, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Opalshell Scuttler (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+19, 222020, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1744.7882080078125, -2117.052001953125, -0.49463799595832824, 3.459854364395141601, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Condensed Droplet (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+20, 222037, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1725.4791259765625, -2091.91845703125, -6.15951776504516601, 1.673431158065795898, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Opalshell Scuttler (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+21, 221681, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1653.517333984375, -2220.279541015625, 18.52383613586425781, 0.965128183364868164, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Slithering Shalescale (Area: The Opalcreg - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+22, 225702, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1663.4271240234375, -2234.647705078125, 18.38194465637207031, 1.325521588325500488, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Nerubian Swarmite (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+23, 225702, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1666.7274169921875, -2231.357666015625, 17.47916793823242187, 1.451243758201599121, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Nerubian Swarmite (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+24, 225702, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1662.703125, -2229.338623046875, 18.13715362548828125, 1.206099152565002441, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Nerubian Swarmite (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+25, 224150, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1680.4271240234375, -2212.79345703125, 14.35614013671875, 3.849431991577148437, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Nerubian Skirmisher (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+26, 224149, 2552, 14717, 14788, '0', 0, 0, 0, 1, 1672.6771240234375, -2238.55908203125, 16.51857376098632812, 1.280963420867919921, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Nerubian Webspinner (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+27, 224150, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1605.3541259765625, -2205.27783203125, 24.61671638488769531, 0.851092994213104248, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Nerubian Skirmisher (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+28, 224150, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1600.13720703125, -2220.203125, 25.75853919982910156, 1.099920988082885742, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Nerubian Skirmisher (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+29, 224149, 2552, 14717, 14788, '0', 0, 0, 0, 1, 1514.1927490234375, -2229.973876953125, 23.81095123291015625, 2.605558395385742187, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Nerubian Webspinner (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+30, 224150, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1585.52783203125, -2198.005126953125, 26.0393218994140625, 0.851092994213104248, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Nerubian Skirmisher (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+31, 225702, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1531.404541015625, -2218.56591796875, 21.310272216796875, 3.85068511962890625, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Nerubian Swarmite (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+32, 225702, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1532.1285400390625, -2223.875, 21.17665672302246093, 1.10791325569152832, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Nerubian Swarmite (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+33, 225702, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1535.4288330078125, -2220.585205078125, 21.76707839965820312, 3.334431886672973632, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Nerubian Swarmite (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+34, 225702, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1523.7569580078125, -2201.40625, 22.34103965759277343, 5.903026580810546875, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Nerubian Swarmite (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+35, 225702, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1528.8367919921875, -2204.451416015625, 22.68164634704589843, 1.792635321617126464, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Nerubian Swarmite (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+36, 224150, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1530.1875, -2197.4619140625, 22.87115478515625, 0.872664630413055419, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Nerubian Skirmisher (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+37, 224149, 2552, 14717, 14788, '0', 0, 0, 0, 1, 1584.6614990234375, -2249.486083984375, 25.64519691467285156, 0.740212440490722656, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Nerubian Webspinner (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+38, 225702, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1522.7447509765625, -2154.666748046875, 26.6631927490234375, 5.753058433532714843, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Nerubian Swarmite (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+39, 225702, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1523.467041015625, -2162.763916015625, 27.75173187255859375, 0.688203632831573486, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Nerubian Swarmite (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+40, 225702, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1526.7691650390625, -2156.68408203125, 26.8194427490234375, 0.624653518199920654, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Nerubian Swarmite (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+41, 224150, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1555.142333984375, -2170.210205078125, 18.87413978576660156, 1.755015134811401367, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Nerubian Skirmisher (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+42, 224149, 2552, 14717, 14788, '0', 0, 0, 0, 1, 1568.7535400390625, -2206.8525390625, 25.42358207702636718, 0.909680008888244628, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Nerubian Webspinner (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+43, 221681, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1525.2916259765625, -2196.520751953125, 22.41799163818359375, 3.021297693252563476, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Slithering Shalescale (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+44, 224150, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1485.43408203125, -2166.569580078125, 21.016143798828125, 3.374113798141479492, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Nerubian Skirmisher (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+45, 224150, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1555.7603759765625, -2177.307373046875, 20.26731109619140625, 4.054271697998046875, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Nerubian Skirmisher (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+46, 224149, 2552, 14717, 14788, '0', 0, 0, 0, 1, 1494.157958984375, -2174.34375, 21.42830085754394531, 4.544912338256835937, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Nerubian Webspinner (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+47, 224150, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1476.60595703125, -2175.1962890625, 20.59891319274902343, 1.54922795295715332, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Nerubian Skirmisher (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+48, 225702, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1462.8038330078125, -2227.8837890625, 23.67787742614746093, 0.985251367092132568, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Nerubian Swarmite (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+49, 225702, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1463.52783203125, -2235.98095703125, 24.2897796630859375, 3.60272979736328125, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Nerubian Swarmite (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+50, 225702, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1466.828125, -2229.90283203125, 23.67787742614746093, 4.901484012603759765, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Nerubian Swarmite (Area: The Opalcreg - Difficulty: 0) CreateObject2
(@CGUID+51, 224150, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1469.111083984375, -2196.236083984375, 22.56288909912109375, 3.93996596336364746, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689); -- Nerubian Skirmisher (Area: The Opalcreg - Difficulty: 0) CreateObject2
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+51;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+3, 0, 0, 0, 0, 0, 0, 0, 567, 0, 0, 0, 0, ''), -- Nerubian Webspinner
(@CGUID+8, 0, 0, 0, 0, 0, 1, 0, 567, 0, 0, 0, 0, ''), -- Nerubian Skirmisher
(@CGUID+25, 0, 0, 0, 0, 0, 1, 0, 567, 0, 0, 0, 0, ''), -- Nerubian Skirmisher
(@CGUID+26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Nerubian Webspinner
(@CGUID+27, 0, 0, 0, 0, 0, 1, 0, 596, 0, 0, 0, 0, ''), -- Nerubian Skirmisher
(@CGUID+29, 0, 0, 0, 0, 0, 0, 0, 537, 0, 0, 0, 0, ''), -- Nerubian Webspinner
(@CGUID+30, 0, 0, 0, 0, 0, 1, 0, 537, 0, 0, 0, 0, ''), -- Nerubian Skirmisher
(@CGUID+51, 0, 0, 0, 0, 0, 1, 0, 567, 0, 0, 0, 0, ''); -- Nerubian Skirmisher

-- Path for Nerubian Skirmisher
SET @MOVERGUID := @CGUID+10;
SET @ENTRY := 224150;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Nerubian Skirmisher - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1758.4375, -2206.2795, 12.498931, NULL, 0),
(@PATH, 1, 1750.5173, -2206.0435, 12.498681, NULL, 0),
(@PATH, 2, 1744.1754, -2206.0105, 12.498681, NULL, 0),
(@PATH, 3, 1740.967, -2206.0452, 12.426781, NULL, 0),
(@PATH, 4, 1739.5851, -2203.4739, 12.207017, NULL, 0),
(@PATH, 5, 1769.9236, -2204.1667, 12.505574, NULL, 0),
(@PATH, 6, 1776.0139, -2205.125, 12.926725, NULL, 0),
(@PATH, 7, 1784.5382, -2207.6807, 12.884159, NULL, 0),
(@PATH, 8, 1791.1267, -2201.9895, 13.058727, NULL, 0),
(@PATH, 9, 1770.25, -2206.8508, 12.436472, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Nerubian Skirmisher
SET @MOVERGUID := @CGUID+45;
SET @ENTRY := 224150;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Nerubian Skirmisher - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1546.4062, -2188.1025, 22.726852, NULL, 0),
(@PATH, 1, 1541.1354, -2191.9722, 22.923365, NULL, 0),
(@PATH, 2, 1537.6077, -2193.2656, 22.968088, NULL, 0),
(@PATH, 3, 1531.2882, -2193.6423, 22.608765, NULL, 0),
(@PATH, 4, 1529.158, -2189.3176, 22.425041, NULL, 0),
(@PATH, 5, 1531.2327, -2193.6614, 22.609026, NULL, 0),
(@PATH, 6, 1537.9115, -2193.0903, 22.963964, NULL, 0),
(@PATH, 7, 1541.3021, -2192.073, 22.931204, NULL, 0),
(@PATH, 8, 1546.1007, -2188.1406, 22.729809, NULL, 0),
(@PATH, 9, 1550.6979, -2183.4028, 22.116074, NULL, 0),
(@PATH, 10, 1554.092, -2177.7327, 20.508095, NULL, 0),
(@PATH, 11, 1550.9948, -2183.4688, 22.124826, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Nerubian Skirmisher
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+36;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+36, @CGUID+36, 0, 0, 515, 0, 0),
(@CGUID+36, @CGUID+34, 5, 270, 515, 1, 4),
(@CGUID+36, @CGUID+35, 5, 90, 515, 1, 4);

SET @MOVERGUID := @CGUID+36;
SET @ENTRY := 224150;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Nerubian Skirmisher - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1487.5226, -2206.9514, 21.750145, NULL, 0),
(@PATH, 1, 1476.1945, -2220.0486, 21.385803, NULL, 0),
(@PATH, 2, 1487.5226, -2206.9514, 21.750145, NULL, 0),
(@PATH, 3, 1497.2535, -2200.7622, 21.366089, NULL, 0),
(@PATH, 4, 1514.875, -2200.5347, 21.900452, NULL, 0),
(@PATH, 5, 1497.2535, -2200.7622, 21.366089, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Isle Gull
SET @MOVERGUID := @CGUID+6;
SET @ENTRY := 222057;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.6714, 'Isle Gull - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1801.5023, -2141.1125, 33.868916, NULL, 0),
(@PATH, 1, 1808.0055, -2150.8452, 33.868916, NULL, 0),
(@PATH, 2, 1817.7383, -2157.3484, 33.868916, NULL, 0),
(@PATH, 3, 1829.2188, -2159.632, 33.868916, NULL, 0),
(@PATH, 4, 1840.6992, -2157.3484, 33.868916, NULL, 0),
(@PATH, 5, 1850.432, -2150.8452, 33.868916, NULL, 0),
(@PATH, 6, 1856.9352, -2141.1125, 33.868916, NULL, 0),
(@PATH, 7, 1859.2188, -2129.632, 33.868916, NULL, 0),
(@PATH, 8, 1856.9352, -2118.1516, 33.868916, NULL, 0),
(@PATH, 9, 1850.4319, -2108.419, 33.868916, NULL, 0),
(@PATH, 10, 1840.6992, -2101.9158, 33.868916, NULL, 0),
(@PATH, 11, 1829.2188, -2099.632, 33.868916, NULL, 0),
(@PATH, 12, 1817.7383, -2101.9158, 33.868916, NULL, 0),
(@PATH, 13, 1808.0055, -2108.419, 33.868916, NULL, 0),
(@PATH, 14, 1801.5023, -2118.1516, 33.868916, NULL, 0),
(@PATH, 15, 1799.2188, -2129.632, 33.868916, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Isle Gull
SET @MOVERGUID := @CGUID+15;
SET @ENTRY := 222057;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.6714, 'Isle Gull - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1669.077, -2119.2747, 46.84708, NULL, 0),
(@PATH, 1, 1675.5802, -2109.542, 46.84708, NULL, 0),
(@PATH, 2, 1685.313, -2103.0388, 46.84708, NULL, 0),
(@PATH, 3, 1696.7935, -2100.7551, 46.84708, NULL, 0),
(@PATH, 4, 1708.2739, -2103.0388, 46.84708, NULL, 0),
(@PATH, 5, 1718.0067, -2109.542, 46.84708, NULL, 0),
(@PATH, 6, 1724.5099, -2119.2747, 46.84708, NULL, 0),
(@PATH, 7, 1726.7935, -2130.7551, 46.84708, NULL, 0),
(@PATH, 8, 1724.5099, -2142.2356, 46.84708, NULL, 0),
(@PATH, 9, 1718.0067, -2151.9683, 46.84708, NULL, 0),
(@PATH, 10, 1708.2739, -2158.4714, 46.84708, NULL, 0),
(@PATH, 11, 1696.7935, -2160.7551, 46.84708, NULL, 0),
(@PATH, 12, 1685.313, -2158.4714, 46.84708, NULL, 0),
(@PATH, 13, 1675.5802, -2151.9683, 46.84708, NULL, 0),
(@PATH, 14, 1669.077, -2142.2356, 46.84708, NULL, 0),
(@PATH, 15, 1666.7935, -2130.7551, 46.84708, NULL, 0),
(@PATH, 16, 1669.077, -2119.2747, 46.84708, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Isle Gull
SET @MOVERGUID := @CGUID+17;
SET @ENTRY := 222057;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.8683, 'Isle Gull - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1630.7285, -2137.1936, 41.198055, NULL, 0),
(@PATH, 1, 1641.3351, -2132.8003, 41.198055, NULL, 0),
(@PATH, 2, 1651.9417, -2137.1936, 41.198055, NULL, 0),
(@PATH, 3, 1656.3351, -2147.8003, 41.198055, NULL, 0),
(@PATH, 4, 1651.9417, -2158.407, 41.198055, NULL, 0),
(@PATH, 5, 1641.3351, -2162.8003, 41.198055, NULL, 0),
(@PATH, 6, 1630.7285, -2158.407, 41.198055, NULL, 0),
(@PATH, 7, 1626.3351, -2147.8003, 41.198055, NULL, 0),
(@PATH, 8, 1630.7285, -2137.1936, 41.198055, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);
