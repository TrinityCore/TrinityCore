SET @CGUID := 460987;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+2;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 79470, 1116, 7078, 7078, '0', 4318, 0, 0, 1, 1935.3177490234375, 339.6163330078125, 89.04918670654296875, 4.966650962829589843, 7200, 0, 0, 9852, 1283, 0, 0, 0, 0, 44232), -- Vindicator Maraad (Area: -Unknown- - Difficulty: 0)
(@CGUID+1, 79241, 1116, 7078, 7078, '0', 4318, 0, 0, 1, 1929.1805419921875, 334.369781494140625, 89.06130218505859375, 5.631825923919677734, 7200, 0, 0, 2955600, 19245, 0, 0, 0, 0, 44232), -- Prophet Velen (Area: -Unknown- - Difficulty: 0)
(@CGUID+2, 79567, 1116, 7078, 7078, '0', 4318, 0, 0, 1, 1928.1666259765625, 331.390625, 89.19445037841796875, 6.268841266632080078, 7200, 0, 0, 2463, 1283, 0, 0, 0, 0, 44232); -- Yrel (Area: -Unknown- - Difficulty: 0) (Auras: 73299 - Crazy Mana Regen, 150626 - Righteous Fury)
