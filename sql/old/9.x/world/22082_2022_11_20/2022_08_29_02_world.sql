SET @CGUID := 1051407;
SET @OGUID := 600230;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+5;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 157114, 2175, 10424, 10588, '0', 13878, 0, 0, 0, 301.390625, -2486.314208984375, 115.1827926635742187, 1.608367085456848144, 7200, 0, 0, 124, 0, 0, 0, 0, 0, 45114), -- Lightspawn (Area: -Unknown- - Difficulty: 0) (Auras: 319104 - -Unknown-)
(@CGUID+1, 164026, 2175, 10424, 10588, '0', 13878, 0, 0, 0, 279.567718505859375, -2473.83154296875, 117.5749664306640625, 0, 7200, 0, 0, 124, 0, 0, 0, 0, 0, 45114), -- InvisBunny (Area: -Unknown- - Difficulty: 0)
(@CGUID+2, 157104, 2175, 10424, 10588, '0', 13878, 0, 0, 0, 301.22222900390625, -2486.2587890625, 115.1819534301757812, 0, 7200, 0, 0, 124, 0, 0, 0, 0, 0, 45114), -- Invisible Stalker (Area: -Unknown- - Difficulty: 0)
(@CGUID+3, 155572, 2175, 10424, 10588, '0', 13878, 0, 0, 0, 313.5850830078125, -2460.123291015625, 118.3092422485351562, 6.224598884582519531, 7200, 0, 0, 124, 0, 0, 0, 0, 0, 45114), -- InvisBunny (Area: -Unknown- - Difficulty: 0)
(@CGUID+4, 164022, 2175, 10424, 10588, '0', 13878, 0, 0, 0, 325.213531494140625, -2496.65283203125, 117.8692550659179687, 0, 7200, 0, 0, 124, 0, 0, 0, 0, 0, 45114), -- InvisBunny (Area: -Unknown- - Difficulty: 0)
(@CGUID+5, 164025, 2175, 10424, 10588, '0', 13878, 0, 0, 0, 290.63714599609375, -2513.760498046875, 117.9789657592773437, 0, 7200, 0, 0, 124, 0, 0, 0, 0, 0, 45114); -- InvisBunny (Area: -Unknown- - Difficulty: 0)

-- Creature Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` = 157114 /*157114 (Lightspawn) - -Unknown-*/;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(157114, 0, 0, 0, 1, 0, 0, 0, 0, 3, '319104'); -- 157114 (Lightspawn) - -Unknown-

UPDATE `creature_template` SET `minlevel`=10, `unit_flags3`=16777216 WHERE `entry`=157104; -- Invisible Stalker
UPDATE `creature_template` SET `minlevel`=10 WHERE `entry`=157114; -- Lightspawn
UPDATE `creature_template` SET `minlevel`=10, `maxlevel`=10, `faction`=14, `BaseAttackTime`=2000, `unit_flags`=33554944, `unit_flags2`=2048, `unit_flags3`=16777216, `dynamicflags`=128 WHERE `entry`=164025; -- InvisBunny

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+3;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 326716, 2175, 10424, 10588, '0', 0, 0, 313.48785400390625, -2460.15283203125, 116.8345108032226562, 1.7185899019241333, 0, 0, 0.757382392883300781, 0.652971625328063964, 7200, 255, 1, 45114), -- Ritual Pedestal (Area: -Unknown- - Difficulty: 0)
(@OGUID+1, 326719, 2175, 10424, 10588, '0', 0, 0, 279.508697509765625, -2473.833251953125, 116.2229385375976562, 1.7185899019241333, 0, 0, 0.757382392883300781, 0.652971625328063964, 7200, 255, 1, 45114), -- Ritual Pedestal (Area: -Unknown- - Difficulty: 0)
(@OGUID+2, 326717, 2175, 10424, 10588, '0', 0, 0, 325.182281494140625, -2496.579833984375, 116.5211029052734375, 1.7185899019241333, 0, 0, 0.757382392883300781, 0.652971625328063964, 7200, 255, 1, 45114), -- Ritual Pedestal (Area: -Unknown- - Difficulty: 0)
(@OGUID+3, 326718, 2175, 10424, 10588, '0', 0, 0, 290.677093505859375, -2513.736083984375, 116.6146011352539062, 1.7185899019241333, 0, 0, 0.757382392883300781, 0.652971625328063964, 7200, 255, 1, 45114); -- Ritual Pedestal (Area: -Unknown- - Difficulty: 0)

-- Phasing
DELETE FROM `phase_area` WHERE (`AreaId` = 10424 AND `PhaseId` = 13878);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(10424, 13878, 'Cosmetic - See bound Lightspawn');

DELETE FROM `phase_name` WHERE `ID` = 13878;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(13878, 'Cosmetic - See bound Lightspawn');

-- Condition
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 13878 AND `SourceEntry` = 10424);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 13878, 10424, 0, 0, 47, 0, 54933, 64, 0, 1, 'Apply Phase 13878 If Quest 54933 IS NOT rewarded');
