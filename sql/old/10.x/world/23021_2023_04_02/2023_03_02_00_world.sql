SET @CGUID := 9003383;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+7;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 197843, 2444, 13646, 13646, '0', '0', 0, 0, 0, -2978.19677734375, 2288.617431640625, 550.2774658203125, 1.98538219928741455, 120, 10, 0, 191962, 0, 1, 0, 0, 0, 48069), -- Seeing Eye Proto-Drake (Area: The Azure Span - Difficulty: 0)
(@CGUID+1, 197843, 2444, 13646, 13646, '0', '0', 0, 0, 0, -3072.926025390625, 2281.953857421875, 543.7161865234375, 3.934587001800537109, 120, 10, 0, 191962, 0, 1, 0, 0, 0, 48069), -- Seeing Eye Proto-Drake (Area: The Azure Span - Difficulty: 0) (Auras: )
(@CGUID+2, 197843, 2444, 13646, 13646, '0', '0', 0, 0, 0, -3057.12060546875, 2323.4765625, 542.23028564453125, 1.135687232017517089, 120, 10, 0, 191962, 0, 1, 0, 0, 0, 48069), -- Seeing Eye Proto-Drake (Area: The Azure Span - Difficulty: 0)
(@CGUID+3, 197843, 2444, 13646, 13646, '0', '0', 0, 0, 0, -3000.149169921875, 2189.061767578125, 563.601318359375, 2.386743068695068359, 120, 10, 0, 191962, 0, 1, 0, 0, 0, 48069), -- Seeing Eye Proto-Drake (Area: The Azure Span - Difficulty: 0)
(@CGUID+4, 197843, 2444, 13646, 13646, '0', '0', 0, 0, 0, -2981.812744140625, 2212.837890625, 561.82232666015625, 3.760783672332763671, 120, 10, 0, 191962, 0, 1, 0, 0, 0, 48069), -- Seeing Eye Proto-Drake (Area: The Azure Span - Difficulty: 0)
(@CGUID+5, 197843, 2444, 13646, 13646, '0', '0', 0, 0, 0, -2953.303955078125, 2343.05029296875, 539.59490966796875, 3.410241365432739257, 120, 10, 0, 191962, 0, 1, 0, 0, 0, 48069), -- Seeing Eye Proto-Drake (Area: The Azure Span - Difficulty: 0)
(@CGUID+6, 197843, 2444, 13646, 13646, '0', '0', 0, 0, 0, -3129.409912109375, 2247.2890625, 552.92474365234375, 4.720201492309570312, 120, 10, 0, 191962, 0, 1, 0, 0, 0, 48069), -- Seeing Eye Proto-Drake (Area: The Azure Span - Difficulty: 0)
(@CGUID+7, 197843, 2444, 13646, 13646, '0', '0', 0, 0, 0, -3021.3505859375, 2400.363525390625, 530.75634765625, 6.231372833251953125, 120, 10, 0, 191962, 0, 1, 0, 0, 0, 48069); -- Seeing Eye Proto-Drake (Area: The Azure Span - Difficulty: 0)

UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=16, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=197843; -- Seeing Eye Proto-Drake
