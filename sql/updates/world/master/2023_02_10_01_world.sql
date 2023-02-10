SET @CGUID := 9002559;

SET @GGUID := 100009;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+41;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 196371, 2444, 13645, 13645, '0', 0, 0, 0, 0, 333.217010498046875, 439.89410400390625, 358.18536376953125, 2.368857860565185546, 120, 0, 0, 53729, 0, 0, 0, 0, 0, 48001), -- Spirit Ohuna (Area: Ohn'ahran Plains - Difficulty: 0) (Auras: 9036 - Ghost, 10848 - Shroud of Death)
(@CGUID+1, 196371, 2444, 13645, 13645, '0', 0, 0, 0, 0, 340.451385498046875, 456.84027099609375, 356.701446533203125, 3.384361028671264648, 120, 0, 0, 53729, 0, 0, 0, 0, 0, 48001), -- Spirit Ohuna (Area: Ohn'ahran Plains - Difficulty: 0) (Auras: 9036 - Ghost, 10848 - Shroud of Death)
(@CGUID+2, 196371, 2444, 13645, 13645, '0', 0, 0, 0, 0, 306.944610595703125, 473.757568359375, 362.458251953125, 3.7519989013671875, 120, 0, 0, 53729, 0, 0, 0, 0, 0, 48001), -- Spirit Ohuna (Area: Ohn'ahran Plains - Difficulty: 0) (Auras: 9036 - Ghost, 10848 - Shroud of Death)
(@CGUID+3, 6491, 2444, 13645, 13645, '0', 0, 0, 0, 0, 329.314239501953125, 452.3125, 351.61395263671875, 5.596318721771240234, 120, 0, 0, 152441, 0, 0, 0, 0, 0, 48001), -- Spirit Healer (Area: Ohn'ahran Plains - Difficulty: 0) (Auras: 9036 - Ghost; 10848 - Shroud of Death)
(@CGUID+4, 6491, 2444, 13645, 13645, '0', 0, 0, 0, 0, -942.77777099609375, 1071.890625, 426.5098876953125, 0.672579169273376464, 120, 0, 0, 152441, 0, 0, 0, 0, 0, 48001), -- Spirit Healer (Area: Ohn'ahran Plains - Difficulty: 0) (Auras: 9036 - Ghost, 10848 - Shroud of Death)
(@CGUID+5, 196371, 2444, 13645, 13645, '0', 0, 0, 0, 0, -931.73785400390625, 1070.7742919921875, 432.681182861328125, 3.425750732421875, 120, 0, 0, 53729, 0, 0, 0, 0, 0, 48001), -- Spirit Ohuna (Area: Ohn'ahran Plains - Difficulty: 0) (Auras: 9036 - Ghost, 10848 - Shroud of Death)
(@CGUID+6, 196371, 2444, 13645, 13645, '0', 0, 0, 0, 0, -941.72918701171875, 1080.501708984375, 435.9376220703125, 3.831830739974975585, 120, 0, 0, 53729, 0, 0, 0, 0, 0, 48001), -- Spirit Ohuna (Area: Ohn'ahran Plains - Difficulty: 0) (Auras: 9036 - Ghost, 10848 - Shroud of Death)
(@CGUID+7, 196371, 2444, 13645, 13645, '0', 0, 0, 0, 0, -935.90374755859375, 1047.9063720703125, 443.14471435546875, 4.184734344482421875, 120, 0, 0, 53729, 0, 0, 0, 0, 0, 48001), -- Spirit Ohuna (Area: Ohn'ahran Plains - Difficulty: 0) (Auras: 9036 - Ghost; 10848 - Shroud of Death)
(@CGUID+8, 196371, 2444, 13645, 13645, '0', 0, 0, 0, 0, -2730.595458984375, 1182.9583740234375, 562.53656005859375, 4.99560546875, 120, 0, 0, 53729, 0, 0, 0, 0, 0, 48001), -- Spirit Ohuna (Area: Ohn'ahran Plains - Difficulty: 0) (Auras: 9036 - Ghost, 10848 - Shroud of Death)
(@CGUID+9, 6491, 2444, 13645, 13645, '0', 0, 0, 0, 0, -2727.625, 1167.8055419921875, 555.73187255859375, 2.518459796905517578, 120, 0, 0, 152441, 0, 0, 0, 0, 0, 48001), -- Spirit Healer (Area: Ohn'ahran Plains - Difficulty: 0) (Auras: 9036 - Ghost, 10848 - Shroud of Death)
(@CGUID+10, 196371, 2444, 13645, 13645, '0', 0, 0, 0, 0, -2738.359375, 1169.142333984375, 567.14007568359375, 5.917953968048095703, 120, 0, 0, 53729, 0, 0, 0, 0, 0, 48001), -- Spirit Ohuna (Area: Ohn'ahran Plains - Difficulty: 0) (Auras: 9036 - Ghost, 10848 - Shroud of Death)
(@CGUID+11, 196371, 2444, 13645, 13645, '0', 0, 0, 0, 0, -2701.684326171875, 1175.1541748046875, 568.5289306640625, 5.391199588775634765, 120, 0, 0, 53729, 0, 0, 0, 0, 0, 48001), -- Spirit Ohuna (Area: Ohn'ahran Plains - Difficulty: 0) (Auras: 9036 - Ghost; 10848 - Shroud of Death)
(@CGUID+12, 196371, 2444, 13645, 13645, '0', 0, 0, 0, 0, -2005.7100830078125, 1835.3072509765625, 529.4154052734375, 0.006444317288696765, 120, 0, 0, 53729, 0, 0, 0, 0, 0, 48001), -- Spirit Ohuna (Area: Ohn'ahran Plains - Difficulty: 0) (Auras: 9036 - Ghost, 10848 - Shroud of Death)
(@CGUID+13, 196371, 2444, 13645, 13645, '0', 0, 0, 0, 0, -1990.52783203125, 1816.96875, 528.8441162109375, 1.086918115615844726, 120, 0, 0, 53729, 0, 0, 0, 0, 0, 48001), -- Spirit Ohuna (Area: Ohn'ahran Plains - Difficulty: 0) (Auras: 9036 - Ghost, 10848 - Shroud of Death)
(@CGUID+14, 196371, 2444, 13645, 13645, '0', 0, 0, 0, 0, -1964.012451171875, 1849.076904296875, 536.155029296875, 2.168022871017456054, 120, 0, 0, 53729, 0, 0, 0, 0, 0, 48001), -- Spirit Ohuna (Area: Ohn'ahran Plains - Difficulty: 0) (Auras: 9036 - Ghost, 10848 - Shroud of Death)
(@CGUID+15, 6491, 2444, 13645, 13645, '0', 0, 0, 0, 0, -1990.3785400390625, 1827.763916015625, 521.57110595703125, 3.90951085090637207, 120, 0, 0, 152441, 0, 0, 0, 0, 0, 48001), -- Spirit Healer (Area: Ohn'ahran Plains - Difficulty: 0) (Auras: 9036 - Ghost; 10848 - Shroud of Death)
(@CGUID+16, 196371, 2444, 13645, 13645, '0', 0, 0, 0, 0, -1690.611083984375, 2719.861083984375, 563.3074951171875, 0.976638674736022949, 120, 0, 0, 53729, 0, 0, 0, 0, 0, 48001), -- Spirit Ohuna (Area: Ohn'ahran Plains - Difficulty: 0) (Auras: 9036 - Ghost, 10848 - Shroud of Death)
(@CGUID+17, 6491, 2444, 13645, 13645, '0', 0, 0, 0, 0, -1688.7222900390625, 2728.459228515625, 556.73577880859375, 3.792127132415771484, 120, 0, 0, 152441, 0, 0, 0, 0, 0, 48001), -- Spirit Healer (Area: Ohn'ahran Plains - Difficulty: 0) (Auras: 9036 - Ghost, 10848 - Shroud of Death)
(@CGUID+18, 196371, 2444, 13645, 13645, '0', 0, 0, 0, 0, -1725.2191162109375, 2697.70263671875, 562.2828369140625, 3.039181709289550781, 120, 0, 0, 53729, 0, 0, 0, 0, 0, 48001), -- Spirit Ohuna (Area: Ohn'ahran Plains - Difficulty: 0) (Auras: 9036 - Ghost, 10848 - Shroud of Death)
(@CGUID+19, 196371, 2444, 13645, 13645, '0', 0, 0, 0, 0, -1685.2591552734375, 2760.2890625, 572.210693359375, 3.637117862701416015, 120, 0, 0, 53729, 0, 0, 0, 0, 0, 48001), -- Spirit Ohuna (Area: Ohn'ahran Plains - Difficulty: 0) (Auras: 9036 - Ghost, 10848 - Shroud of Death)
(@CGUID+20, 196371, 2444, 13645, 13645, '0', 0, 0, 0, 0, -1703.4063720703125, 2778.1572265625, 575.49676513671875, 3.637031078338623046, 120, 0, 0, 53729, 0, 0, 0, 0, 0, 48001), -- Spirit Ohuna (Area: Ohn'ahran Plains - Difficulty: 0) (Auras: 9036 - Ghost, 10848 - Shroud of Death)
(@CGUID+21, 196371, 2444, 13645, 13645, '0', 0, 0, 0, 0, -1708.7952880859375, 2692.35498046875, 577.46038818359375, 3.039164304733276367, 120, 0, 0, 53729, 0, 0, 0, 0, 0, 48001), -- Spirit Ohuna (Area: Ohn'ahran Plains - Difficulty: 0) (Auras: 9036 - Ghost, 10848 - Shroud of Death)
(@CGUID+22, 196371, 2444, 13645, 13645, '0', 0, 0, 0, 0, -1701.03125, 2735.173583984375, 562.75537109375, 0.236438125371932983, 120, 0, 0, 53729, 0, 0, 0, 0, 0, 48001), -- Spirit Ohuna (Area: Ohn'ahran Plains - Difficulty: 0) (Auras: 9036 - Ghost; 10848 - Shroud of Death)
(@CGUID+23, 196371, 2444, 13645, 13645, '0', 0, 0, 0, 0, -1745.3131103515625, 3935.115478515625, 526.520751953125, 3.823246955871582031, 120, 0, 0, 53729, 0, 0, 0, 0, 0, 48001), -- Spirit Ohuna (Area: Ohn'ahran Plains - Difficulty: 0) (Auras: 9036 - Ghost, 10848 - Shroud of Death)
(@CGUID+24, 6491, 2444, 13645, 13645, '0', 0, 0, 0, 0, -1749.921875, 3913.90966796875, 513.8048095703125, 3.379526376724243164, 120, 0, 0, 152441, 0, 0, 0, 0, 0, 48001), -- Spirit Healer (Area: Ohn'ahran Plains - Difficulty: 0) (Auras: 9036 - Ghost, 10848 - Shroud of Death)
(@CGUID+25, 196371, 2444, 13645, 13645, '0', 0, 0, 0, 0, -1758.19970703125, 3906.612060546875, 520.5093994140625, 0.624623119831085205, 120, 0, 0, 53729, 0, 0, 0, 0, 0, 48001), -- Spirit Ohuna (Area: Ohn'ahran Plains - Difficulty: 0) (Auras: 9036 - Ghost, 10848 - Shroud of Death)
(@CGUID+26, 196371, 2444, 13645, 13645, '0', 0, 0, 0, 0, -1762.8629150390625, 3919.819580078125, 519.76043701171875, 5.919104576110839843, 120, 0, 0, 53729, 0, 0, 0, 0, 0, 48001), -- Spirit Ohuna (Area: Ohn'ahran Plains - Difficulty: 0) (Auras: 9036 - Ghost; 10848 - Shroud of Death)
(@CGUID+27, 196371, 2444, 13645, 13669, '0', 0, 0, 0, 0, -1332.9931640625, 4664.6201171875, 105.0249252319335937, 3.433891057968139648, 120, 0, 0, 53729, 0, 0, 0, 0, 0, 48001), -- Spirit Ohuna (Area: Emerald Gardens - Difficulty: 0) (Auras: 9036 - Ghost, 10848 - Shroud of Death)
(@CGUID+28, 196371, 2444, 13645, 13669, '0', 0, 0, 0, 0, -1330.2135009765625, 4697.322265625, 100.9406280517578125, 1.841632843017578125, 120, 0, 0, 53729, 0, 0, 0, 0, 0, 48001), -- Spirit Ohuna (Area: Emerald Gardens - Difficulty: 0) (Auras: 9036 - Ghost, 10848 - Shroud of Death)
(@CGUID+29, 196371, 2444, 13645, 13669, '0', 0, 0, 0, 0, -1347.4739990234375, 4699.37353515625, 98.819122314453125, 0.618799865245819091, 120, 0, 0, 53729, 0, 0, 0, 0, 0, 48001), -- Spirit Ohuna (Area: Emerald Gardens - Difficulty: 0) (Auras: 9036 - Ghost, 10848 - Shroud of Death)
(@CGUID+30, 6491, 2444, 13645, 13669, '0', 0, 0, 0, 0, -1336.845458984375, 4713.1103515625, 97.3589324951171875, 4.63675546646118164, 120, 0, 0, 152441, 0, 0, 0, 0, 0, 48001), -- Spirit Healer (Area: Emerald Gardens - Difficulty: 0) (Auras: 9036 - Ghost; 10848 - Shroud of Death)
(@CGUID+31, 196371, 2444, 13645, 13645, '0', 0, 0, 0, 0, -463.140625, 3449.537353515625, 363.993988037109375, 5.310307979583740234, 120, 0, 0, 53729, 0, 0, 0, 0, 0, 48001), -- Spirit Ohuna (Area: Ohn'ahran Plains - Difficulty: 0) (Auras: 9036 - Ghost, 10848 - Shroud of Death)
(@CGUID+32, 6491, 2444, 13645, 13645, '0', 0, 0, 0, 0, -458.369781494140625, 3439.77685546875, 359.6009521484375, 2.559528350830078125, 120, 0, 0, 152441, 0, 0, 0, 0, 0, 48001), -- Spirit Healer (Area: Ohn'ahran Plains - Difficulty: 0) (Auras: 9036 - Ghost, 10848 - Shroud of Death)
(@CGUID+33, 196371, 2444, 13645, 13645, '0', 0, 0, 0, 0, -470.34027099609375, 3438.65966796875, 364.931396484375, 0.135353028774261474, 120, 0, 0, 53729, 0, 0, 0, 0, 0, 48001), -- Spirit Ohuna (Area: Ohn'ahran Plains - Difficulty: 0) (Auras: 9036 - Ghost, 10848 - Shroud of Death)
(@CGUID+34, 196371, 2444, 13645, 13645, '0', 0, 0, 0, 0, -425.850982666015625, 3443.1220703125, 372.236724853515625, 1.802985429763793945, 120, 0, 0, 53729, 0, 0, 0, 0, 0, 48001), -- Spirit Ohuna (Area: Ohn'ahran Plains - Difficulty: 0) (Auras: 9036 - Ghost; 10848 - Shroud of Death)
(@CGUID+35, 196371, 2444, 13645, 13645, '0', 0, 0, 0, 0, -533.06427001953125, 2530.02783203125, 444.8853759765625, 4.727198123931884765, 120, 0, 0, 53729, 0, 0, 0, 0, 0, 48001), -- Spirit Ohuna (Area: Ohn'ahran Plains - Difficulty: 0) (Auras: 9036 - Ghost, 10848 - Shroud of Death)
(@CGUID+36, 196371, 2444, 13645, 13645, '0', 0, 0, 0, 0, -541.77410888671875, 2497.800048828125, 455.912322998046875, 5.508421897888183593, 120, 0, 0, 53729, 0, 0, 0, 0, 0, 48001), -- Spirit Ohuna (Area: Ohn'ahran Plains - Difficulty: 0) (Auras: 9036 - Ghost, 10848 - Shroud of Death)
(@CGUID+37, 6491, 2444, 13645, 13645, '0', 0, 0, 0, 0, -537.80206298828125, 2523.8681640625, 442.819000244140625, 1.936972975730895996, 120, 0, 0, 152441, 0, 0, 0, 0, 0, 48001), -- Spirit Healer (Area: Ohn'ahran Plains - Difficulty: 0) (Auras: 9036 - Ghost, 10848 - Shroud of Death)
(@CGUID+38, 196371, 2444, 13645, 13645, '0', 0, 0, 0, 0, -550.92706298828125, 2512.28125, 446.3868408203125, 0.408767521381378173, 120, 0, 0, 53729, 0, 0, 0, 0, 0, 48001), -- Spirit Ohuna (Area: Ohn'ahran Plains - Difficulty: 0) (Auras: 9036 - Ghost, 10848 - Shroud of Death)
(@CGUID+39, 196371, 2444, 13645, 13645, '0', 0, 0, 0, 0, -574.108154296875, 2534.517578125, 450.57427978515625, 1.421832442283630371, 120, 0, 0, 53729, 0, 0, 0, 0, 0, 48001), -- Spirit Ohuna (Area: Ohn'ahran Plains - Difficulty: 0) (Auras: 9036 - Ghost, 10848 - Shroud of Death)
(@CGUID+40, 196371, 2444, 13645, 13645, '0', 0, 0, 0, 0, -550.0086669921875, 2526.05908203125, 445.403350830078125, 5.379051685333251953, 120, 0, 0, 53729, 0, 0, 0, 0, 0, 48001), -- Spirit Ohuna (Area: Ohn'ahran Plains - Difficulty: 0) (Auras: 9036 - Ghost, 10848 - Shroud of Death)
(@CGUID+41, 196371, 2444, 13645, 13645, '0', 0, 0, 0, 0, -559.90606689453125, 2537.881591796875, 441.405517578125, 5.508413314819335937, 120, 0, 0, 53729, 0, 0, 0, 0, 0, 48001); -- Spirit Ohuna (Area: Ohn'ahran Plains - Difficulty: 0) (Auras: 9036 - Ghost; 10848 - Shroud of Death)

DELETE FROM `creature_template_addon` WHERE `entry`=196371;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(196371, 0, 0, 0, 3, 1, 1, 0, 0, 0, 0, 0, 0, '9036 10848'); -- 196371 (Spirit Ohuna) - Ghost; Shroud of Death

UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=65, `faction`=35, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=16777216, `flags_extra`= 1024 WHERE `entry`=196371; -- Spirit Ohuna

DELETE FROM `creature_template_movement` WHERE `CreatureId` = 196371;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(196371, 0, 0, 1, 0, 0, 0, NULL);

-- Graveyard
DELETE FROM `graveyard_zone` WHERE `ID` BETWEEN @GGUID+0 AND @GGUID+8;
INSERT INTO `graveyard_zone` (`ID`, `GhostZone`, `Faction`, `Comment`) VALUES
(@GGUID+0, 13645, 0, 'Ohn´ahran Plains - Timberstep Outpost'),
(@GGUID+1, 13645, 0, 'Ohn´ahran Plains - The Watering Hole'),
(@GGUID+2, 13645, 0, 'Ohn´ahran Plains - Forkriver Crossing'),
(@GGUID+3, 13645, 0, 'Ohn´ahran Plains - Windsong Rise'),
(@GGUID+4, 13645, 0, 'Ohn´ahran Plains - Mirror of the Sky'),
(@GGUID+5, 13645, 0, 'Ohn´ahran Plains - Terrakai'),
(@GGUID+6, 13645, 0, 'Ohn´ahran Plains - Emerald Gardens'),
(@GGUID+7, 13645, 0, 'Ohn´ahran Plains - The Nokhud Approach'),
(@GGUID+8, 13645, 0, 'Ohn´ahran Plains - Maruukai');

DELETE FROM `world_safe_locs` WHERE `ID` BETWEEN @GGUID+0 AND @GGUID+8;
INSERT INTO `world_safe_locs` (`ID`, `MapID`, `LocX`, `LocY`, `LocZ`, `Facing`, `Comment`) VALUES
(@GGUID+0, 2444, 338.174, 447.85, 351.324, 2.66051, 'Ohn´ahran Plains - Timberstep Outpost - GY'),
(@GGUID+1, 2444, -937.77954, 1071.8317, 426.13962, 3.425949, 'Ohn´ahran Plains - The Watering Hole - GY'),
(@GGUID+2, 2444, -2738.67, 1173.05, 556.763, 5.9147987, 'Ohn´ahran Plains - Forkriver Crossing - GY'),
(@GGUID+3, 2444, -2000.6771, 1831.6337, 522.2361, 6.0211473, 'Ohn´ahran Plains - Windsong Rise - GY'),
(@GGUID+4, 2444, -1694.0903, 2729.434, 556.29785, 6.197409, 'Ohn´ahran Plains - Mirror of the Sky - GY'),
(@GGUID+5, 2444, -1754.1649, 3913.5034, 513.5921, 0.037202228, 'Ohn´ahran Plains - Terrakai - GY'),
(@GGUID+6, 2444, -1336.8802, 4707.508, 95.21991, 1.5740986, 'Ohn´ahran Plains - Emerald Gardens - GY'),
(@GGUID+7, 2444, -460.56772, 3442.1284, 359.38348, 5.8171844, 'Ohn´ahran Plains - The Nokhud Approach - GY'),
(@GGUID+8, 2444, -539.2518, 2527.6165, 440.60355, 5.0837946, 'Ohn´ahran Plains - Maruukai - GY');
