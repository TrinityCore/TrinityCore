SET @CGUID := 259501;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+20;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 55014, 585, 4131, 0, "1,2", 169, 0, 0, 0, 46.6875, -8.72743, -2.745695, 0.4537856, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Shattered Sun Marksman (Area: 0 - Difficulty: 0) (Auras: 58506 - Stealth)
(@CGUID+1, 55012, 585, 4131, 0, "1,2", 169, 0, 0, 0, 13.47049, 6.173611, -2.709095, 4.694936, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Shattered Sun Warrior (Area: 0 - Difficulty: 0) (Auras: )
(@CGUID+2, 55012, 585, 4131, 0, "1,2", 169, 0, 0, 0, 0.2725694, -5.894097, -2.72833, 1.623156, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Shattered Sun Warrior (Area: 0 - Difficulty: 0) (Auras: )
(@CGUID+3, 55013, 585, 4131, 0, "1,2", 169, 0, 0, 0, 43.15278, -5.890625, -2.740964, 0.2792527, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Shattered Sun Marksman (Area: 0 - Difficulty: 0) (Auras: 58506 - Stealth)
(@CGUID+4, 55011, 585, 4131, 0, "1,2", 169, 0, 0, 0, 50.57986, -2.822917, -2.732662, 6.213372, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Shattered Sun Warrior (Area: 0 - Difficulty: 0) (Auras: 58506 - Stealth)
(@CGUID+5, 55014, 585, 4131, 0, "1,2", 169, 0, 0, 0, 46.77951, 8.99132, -2.738889, 5.72468, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Shattered Sun Marksman (Area: 0 - Difficulty: 0) (Auras: 58506 - Stealth)
(@CGUID+6, 55013, 585, 4131, 0, "1,2", 169, 0, 0, 0, 42.99479, 6.149306, -2.729624, 5.951573, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Shattered Sun Marksman (Area: 0 - Difficulty: 0) (Auras: 58506 - Stealth)
(@CGUID+7, 55011, 585, 4131, 0, "1,2", 169, 0, 0, 0, 0.08506945, 6.458333, -2.715962, 4.660029, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Shattered Sun Warrior (Area: 0 - Difficulty: 0) (Auras: )
(@CGUID+8, 55012, 585, 4131, 0, "1,2", 169, 0, 0, 0, 50.30729, 3.039931, -2.726843, 0.03490658, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Shattered Sun Warrior (Area: 0 - Difficulty: 0) (Auras: 58506 - Stealth)
(@CGUID+9, 55014, 585, 4131, 0, "1,2", 169, 0, 0, 0, 14.04688, -5.9375, -2.72026, 1.58825, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Shattered Sun Marksman (Area: 0 - Difficulty: 0) (Auras: )
(@CGUID+10, 55011, 585, 4131, 0, "1,2", 169, 0, 0, 0, 5.130208, -5.951389, -2.725587, 1.658063, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Shattered Sun Warrior (Area: 0 - Difficulty: 0) (Auras: )
(@CGUID+11, 55013, 585, 4131, 0, "1,2", 169, 0, 0, 0, 9.677083, -5.901042, -2.722767, 1.58825, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Shattered Sun Marksman (Area: 0 - Difficulty: 0) (Auras: )
(@CGUID+12, 55011, 585, 4131, 0, "1,2", 169, 0, 0, 0, 9.067708, 6.24132, -2.711256, 4.642576, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Shattered Sun Warrior (Area: 0 - Difficulty: 0) (Auras: )
(@CGUID+13, 55018, 585, 4131, 0, "1,2", 169, 0, 0, 0, 22.20313, 0.3125, -2.734227, 4.794769, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Shattered Sun Sentry (Area: 0 - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+14, 55013, 585, 4131, 0, "1,2", 169, 0, 0, 0, 4.619792, 6.265625, -2.713269, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Shattered Sun Marksman (Area: 0 - Difficulty: 0) (Auras: )
(@CGUID+15, 55007, 585, 4131, 0, "1,2", 169, 0, 0, 0, 17.20486, 0.001736111, -2.712097, 3.106686, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595); -- Exarch Larethor (Area: 0 - Difficulty: 0)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+15;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 2, 0, '58506'), -- Shattered Sun Marksman - 58506 - Stealth
(@CGUID+1, 0, 0, 0, 1, 0, ''), -- Shattered Sun Warrior
(@CGUID+2, 0, 0, 0, 1, 0, ''), -- Shattered Sun Warrior
(@CGUID+3, 0, 0, 0, 2, 0, '58506'), -- Shattered Sun Marksman - 58506 - Stealth
(@CGUID+4, 0, 0, 0, 1, 0, '58506'), -- Shattered Sun Warrior - 58506 - Stealth
(@CGUID+5, 0, 0, 0, 2, 0, '58506'), -- Shattered Sun Marksman - 58506 - Stealth
(@CGUID+6, 0, 0, 0, 2, 0, '58506'), -- Shattered Sun Marksman - 58506 - Stealth
(@CGUID+7, 0, 0, 0, 1, 0, ''), -- Shattered Sun Warrior
(@CGUID+8, 0, 0, 0, 1, 0, '58506'), -- Shattered Sun Warrior - 58506 - Stealth
(@CGUID+9, 0, 0, 0, 2, 0, ''), -- Shattered Sun Marksman
(@CGUID+10, 0, 0, 0, 1, 0, ''), -- Shattered Sun Warrior
(@CGUID+11, 0, 0, 0, 2, 0, ''), -- Shattered Sun Marksman
(@CGUID+12, 0, 0, 0, 1, 0, ''), -- Shattered Sun Warrior
(@CGUID+14, 0, 0, 0, 2, 0, ''), -- Shattered Sun Marksman
(@CGUID+15, 0, 0, 0, 1, 0, ''); -- Exarch Larethor
