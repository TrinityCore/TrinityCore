DELETE FROM `creature` WHERE `guid` IN (340413, 340414, 340415);
DELETE FROM `creature_addon` WHERE `guid` IN (340413, 340414, 340415);
SET @CGUID := 254727;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+11;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 46766, 754, 5638, 5638, 15, 169, 0, 0, 0, -50.7691, 864.094, 191.2083, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Ice Storm Trigger (Area: Throne of the Four Winds - Difficulty: 6) (Auras: )
(@CGUID+1, 46766, 754, 5638, 5638, 15, 169, 0, 0, 0, -95.9913, 814.078, 191.2083, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Ice Storm Trigger (Area: Throne of the Four Winds - Difficulty: 6) (Auras: )
(@CGUID+2, 46766, 754, 5638, 5638, 15, 169, 0, 0, 0, -26.2274, 860.302, 191.2083, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Ice Storm Trigger (Area: Throne of the Four Winds - Difficulty: 6) (Auras: )
(@CGUID+3, 46766, 754, 5638, 5638, 15, 169, 0, 0, 0, -24.9896, 772.418, 191.2083, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Ice Storm Trigger (Area: Throne of the Four Winds - Difficulty: 6) (Auras: )
(@CGUID+4, 46766, 754, 5638, 5638, 15, 169, 0, 0, 0, -52.5764, 766.026, 191.2083, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Ice Storm Trigger (Area: Throne of the Four Winds - Difficulty: 6) (Auras: )
(@CGUID+5, 46766, 754, 5638, 5638, 15, 169, 0, 0, 0, -92.0469, 791.96, 191.2083, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Ice Storm Trigger (Area: Throne of the Four Winds - Difficulty: 6) (Auras: )
(@CGUID+6, 46766, 754, 5638, 5638, 15, 169, 0, 0, 0, -73.5833, 855.875, 191.2083, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Ice Storm Trigger (Area: Throne of the Four Winds - Difficulty: 6) (Auras: )
(@CGUID+7, 46766, 754, 5638, 5638, 15, 169, 0, 0, 0, -88.4149, 839.203, 191.2083, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Ice Storm Trigger (Area: Throne of the Four Winds - Difficulty: 6) (Auras: )
(@CGUID+8, 46766, 754, 5638, 5638, 15, 169, 0, 0, 0, -77.276, 775.408, 191.2083, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Ice Storm Trigger (Area: Throne of the Four Winds - Difficulty: 6) (Auras: )
(@CGUID+9, 46766, 754, 5638, 5638, 15, 169, 0, 0, 0, -6.08681, 790.281, 191.2083, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Ice Storm Trigger (Area: Throne of the Four Winds - Difficulty: 6) (Auras: )
(@CGUID+10, 46766, 754, 5638, 5638, 15, 169, 0, 0, 0, -6.0625, 842.55, 191.2083, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Ice Storm Trigger (Area: Throne of the Four Winds - Difficulty: 6) (Auras: )
(@CGUID+11, 46766, 754, 5638, 5638, 15, 169, 0, 0, 0, 0.385417, 816.236, 191.2083, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654); -- Ice Storm Trigger (Area: Throne of the Four Winds - Difficulty: 6) (Auras: )
