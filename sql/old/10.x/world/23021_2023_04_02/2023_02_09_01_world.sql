SET @CGUID := 9002551;

SET @GGUID := 100001;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+7;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 6491, 2444, 13644, 13722, '0', 0, 0, 0, 0, 3661.780517578125, -1480.4271240234375, 71.65735626220703125, 4.627596378326416015, 120, 0, 0, 152441, 0, 0, 0, 0, 0, 47967), -- Spirit Healer (Area: Wild Coast - Difficulty: 0) (Auras: 9036 - Ghost; 10848 - Shroud of Death)
(@CGUID+1, 6491, 2444, 13644, 13644, '0', 0, 0, 0, 0, 3191.882080078125, -1166.5989990234375, 42.04803085327148437, 2.803713083267211914, 120, 0, 0, 152441, 0, 0, 0, 0, 0, 47967), -- Spirit Healer (Area: The Waking Shores - Difficulty: 0) (Auras: 9036 - Ghost; 10848 - Shroud of Death)
(@CGUID+2, 6491, 2444, 13644, 13644, '0', 0, 0, 0, 0, 2395.2587890625, -448.677093505859375, 59.30726242065429687, 4.419765472412109375, 120, 0, 0, 152441, 0, 0, 0, 0, 0, 47967), -- Spirit Healer (Area: The Waking Shores - Difficulty: 0) (Auras: 9036 - Ghost; 10848 - Shroud of Death)
(@CGUID+3, 6491, 2444, 13644, 13727, '0', 0, 0, 0, 0, 1664.2291259765625, -165.289932250976562, 334.43145751953125, 3.424554347991943359, 120, 0, 0, 152441, 0, 0, 0, 0, 0, 47967), -- Spirit Healer (Area: Ruby Lifeshrine - Difficulty: 0) (Auras: 9036 - Ghost; 10848 - Shroud of Death)
(@CGUID+4, 6491, 2444, 13644, 13732, '0', 0, 0, 0, 0, 865.8194580078125, 953.39239501953125, 109.1649246215820312, 0.786303639411926269, 120, 0, 0, 152441, 0, 0, 0, 0, 0, 47967), -- Spirit Healer (Area: Dragonscale Basecamp - Difficulty: 0) (Auras: 9036 - Ghost; 10848 - Shroud of Death)
(@CGUID+5, 6491, 2444, 13644, 13738, '0', 0, 0, 0, 0, 2049.6494140625, 1101.579833984375, 336.843536376953125, 4.135297775268554687, 120, 0, 0, 152441, 0, 0, 0, 0, 0, 47967), -- Spirit Healer (Area: Obsidian Observatory - Difficulty: 0) (Auras: 9036 - Ghost; 10848 - Shroud of Death)
(@CGUID+6, 6491, 2444, 13644, 13720, '0', 0, 0, 0, 0, 1823.095458984375, 2206.944580078125, 108.0606689453125, 3.782532930374145507, 120, 0, 0, 152441, 0, 0, 0, 0, 0, 47967), -- Spirit Healer (Area: Dragonbane Keep - Difficulty: 0) (Auras: 9036 - Ghost; 10848 - Shroud of Death)
(@CGUID+7, 6491, 2444, 13644, 13710, '0', 0, 0, 0, 0, 3276.62158203125, 197.890625, 81.462188720703125, 2.375572681427001953, 120, 0, 0, 152441, 0, 0, 0, 0, 0, 47967); -- Spirit Healer (Area: Uktulut Backwater - Difficulty: 0) (Auras: 9036 - Ghost; 10848 - Shroud of Death)

-- Graveyard
DELETE FROM `graveyard_zone` WHERE `ID` BETWEEN @GGUID+0 AND @GGUID+7;
INSERT INTO `graveyard_zone` (`ID`, `GhostZone`, `Faction`, `Comment`) VALUES
(@GGUID+0, 13644, 0, 'Waking Shores - Wild Coast'),
(@GGUID+1, 13644, 0, 'Waking Shores - Restless Wetlands'),
(@GGUID+2, 13644, 0, 'Waking Shores - Life Vault Ruins'),
(@GGUID+3, 13644, 0, 'Waking Shores - Ruby Lifeshrine'),
(@GGUID+4, 13644, 0, 'Waking Shores - Dragonscale Basecamp'),
(@GGUID+5, 13644, 0, 'Waking Shores - Obsidian Obversatory'),
(@GGUID+6, 13644, 0, 'Waking Shores - Dragonbane Keep'),
(@GGUID+7, 13644, 0, 'Waking Shores - Uktulut Backwater');

DELETE FROM `world_safe_locs` WHERE `ID` BETWEEN @GGUID+0 AND @GGUID+7;
INSERT INTO `world_safe_locs` (`ID`, `MapID`, `LocX`, `LocY`, `LocZ`, `Facing`, `Comment`) VALUES
(@GGUID+0, 2444, 3661.49, -1483.7, 70.4014, 1.4552468, 'Waking Shores - Wild Coast - GY'),
(@GGUID+1, 2444, 3189.202, -1165.277, 42.4406, 5.9955325, 'Waking Shores - Restless Wetlands - GY'),
(@GGUID+2, 2444, 2393.16, -454.778, 57.8724, 1.2887284, 'Waking Shores - Life Vault Ruins - GY'),
(@GGUID+3, 2444, 1659.79, -167.873, 332.225, 0.44770837, 'Waking Shores - Ruby Lifeshrine - GY'),
(@GGUID+4, 2444, 871.0035, 957.6719, 108.657, 3.795967, 'Waking Shores - Dragonscale Basecamp - GY'),
(@GGUID+5, 2444, 2048.6077, 1099.9896, 335.45532, 4.403522, 'Waking Shores - Obsidian Obversatory - GY'),
(@GGUID+6, 2444, 1818.6512, 2200.478, 105.340454, 3.8847609, 'Waking Shores - Dragonbane Keep - GY'),
(@GGUID+7, 2444, 3273.75, 201.943, 78.8308, 5.4467363, 'Waking Shores - Uktulut Backwater - GY');
