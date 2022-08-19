SET @CGUID := 1051209;

-- Creature Spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+3;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 156607, 2175, 10424, 10452, '0', 16770, 0, 0, 0, -245.40972900390625, -2492.088623046875, 18.32131385803222656, 2.475400209426879882, 7200, 0, 0, 124, 0, 0, 0, 0, 0, 44908), -- Alaria (Area: -Unknown- - Difficulty: 0) (Auras: 313662 - -Unknown-)
(@CGUID+1, 156651, 2175, 10424, 10452, '0', 13758, 0, 0, 1, -249.059036254882812, -2492.522705078125, 18.07423973083496093, 0.659374177455902099, 7200, 0, 0, 372, 0, 0, 0, 0, 0, 44908), -- Captain Garrick (Area: -Unknown- - Difficulty: 0)
(@CGUID+2, 166854, 2175, 10424, 10452, '0', 16769, 0, 0, 0, -245.40972900390625, -2492.088623046875, 18.32131385803222656, 2.475400209426879882, 7200, 0, 0, 124, 0, 0, 0, 0, 0, 44908), -- Won'sa (Area: -Unknown- - Difficulty: 0) (Auras: 313662 - -Unknown-)
(@CGUID+3, 166906, 2175, 10424, 10452, '0', 15298, 0, 0, 1, -249.083328247070312, -2492.600830078125, 18.08970069885253906, 0.582385361194610595, 7200, 0, 0, 124, 0, 0, 0, 0, 0, 44908); -- Warlord Breka Grimaxe (Area: -Unknown- - Difficulty: 0)

-- Creature Template Data
DELETE FROM `creature_template_addon` WHERE `entry` IN (156607, 166854);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(156607, 0, 0, 0, 1, 0, 0, 0, 0, 0, '313662'), -- 156607 (Alaria) - -Unknown-
(166854, 0, 0, 0, 1, 0, 0, 0, 0, 0, '313662'); -- 166854 (Won'sa) - -Unknown-

-- Creature Template
UPDATE `creature_template` SET `minlevel`=10, `maxlevel`=10, `faction`=35, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags2`=34816 WHERE `entry`=156607; -- Alaria
UPDATE `creature_template` SET `minlevel`=10, `maxlevel`=10, `faction`=35, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=156651; -- Captain Garrick

-- Phasing
DELETE FROM `phase_area` WHERE (`AreaId` = 10452 AND `PhaseId` = 16770) OR (`AreaId` = 10452 AND `PhaseId` = 13758) OR (`AreaId` = 10452 AND `PhaseId` = 16769) OR (`AreaId` = 10452 AND `PhaseId` = 15298);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(10452, 16770, 'Cosmetic - NPE - Alaria injured'),
(10452, 13758, 'Cosmetic - NPE - Captain Garrick in Abandoned Camp'),
(10452, 16769, 'Cosmetic - NPE - Won''sa injured'),
(10452, 15298, 'Cosmetic - NPE - Warlord Breka in Abandoned Camp');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 16770 AND `SourceEntry` = 10452) OR (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 13758 AND `SourceEntry` = 10452) OR (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 16769 AND `SourceEntry` = 10452) OR (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 15298 AND `SourceEntry` = 10452);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
-- Allaria
(26, 16770, 10452, 0, 0, 6, 0, 469, 0, 0, 0, 'Apply Phase 16770 If Player is Alliance'),
(26, 16770, 10452, 0, 0, 47, 0, 55174, 64, 0, 1, 'Apply Phase 16770 If Quest 55174 IS NOT rewarded'),
-- Captain Garrick
(26, 13758, 10452, 0, 0, 47, 0, 54952, 66, 0, 0, 'Apply Phase 13758 If Quest 54952 IS complete | rewarded'),
-- Won'sa
(26, 16769, 10452, 0, 0, 47, 0, 59931, 2 | 8 | 64, 0, 0, 'Apply Phase 16770 If Quest 59931 IS complete | in progress | rewarded'),
(26, 16769, 10452, 0, 0, 47, 0, 59932, 64, 0, 1, 'Apply Phase 16770 If Quest 59932 IS NOT rewarded'),
-- Warlord Breka
(26, 15298, 10452, 0, 0, 47, 0, 59931, 66, 0, 0, 'Apply Phase 15298 If Quest 59931 IS complete | rewarded');
