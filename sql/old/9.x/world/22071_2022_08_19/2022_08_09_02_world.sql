SET @CGUID := 1051266;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+5;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 175031, 2175, 10424, 10452, '0', 16752, 0, 0, 0, -245.40972900390625, -2492.088623046875, 18.32131385803222656, 2.475400209426879882, 7200, 0, 0, 124, 0, 0, 0, 0, 0, 44908), -- Alaria (Area: -Unknown- - Difficulty: 0)
(@CGUID+1, 154327, 2175, 10424, 10503, '0', 13846, 0, 0, 0, -141.626739501953125, -2639.453125, 48.77923583984375, 5.737590789794921875, 7200, 0, 0, 124, 0, 0, 0, 0, 0, 44908), -- Austin Huxworth (Area: -Unknown- - Difficulty: 0)
(@CGUID+2, 156662, 2175, 10424, 10503, '0', 13762, 0, 0, 1, -142.621536254882812, -2641.036376953125, 48.91431045532226562, 6.067211627960205078, 7200, 0, 0, 372, 0, 0, 0, 0, 0, 44908), -- Captain Garrick (Area: -Unknown- - Difficulty: 0)
(@CGUID+3, 175030, 2175, 10424, 10452, '0', 15293, 0, 0, 0, -245.40972900390625, -2492.088623046875, 18.32131385803222656, 2.475400209426879882, 7200, 0, 0, 124, 0, 0, 0, 0, 0, 44908), -- Won'sa (Area: -Unknown- - Difficulty: 0)
(@CGUID+4, 166996, 2175, 10424, 10503, '0', 15312, 0, 0, 0, -141.493057250976562, -2639.48779296875, 48.86454391479492187, 0, 7200, 0, 0, 124, 0, 0, 0, 0, 0, 44908), -- Mithdran Dawntracker (Area: -Unknown- - Difficulty: 0)
(@CGUID+5, 166997, 2175, 10424, 10503, '0', 15313, 0, 0, 1, -142.560760498046875, -2640.991455078125, 48.98059844970703125, 5.897685050964355468, 7200, 0, 0, 124, 0, 0, 0, 0, 0, 44908); -- Warlord Breka Grimaxe (Area: -Unknown- - Difficulty: 0)

-- Creature Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (156662 /*156662 (Captain Garrick)*/, 154327 /*154327 (Austin Huxworth)*/, 166997 /*166997 (Warlord Breka Grimaxe)*/, 166996 /*166996 (Mithdran Dawntracker)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(156662, 0, 0, 8, 1, 0, 0, 0, 0, 0, ''), -- 156662 (Captain Garrick)
(154327, 0, 0, 8, 1, 0, 0, 0, 0, 0, ''), -- 154327 (Austin Huxworth)
(166997, 0, 0, 8, 1, 0, 0, 0, 0, 0, ''), -- 166997 (Warlord Breka Grimaxe)
(166996, 0, 0, 8, 1, 0, 0, 0, 0, 0, ''); -- 166996 (Mithdran Dawntracker)

-- Creature Template
UPDATE `creature_template` SET `minlevel`=10, `maxlevel`=10, `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=175031; -- Alaria
UPDATE `creature_template` SET `gossip_menu_id`=24240, `minlevel`=10, `maxlevel`=10, `faction`=35, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=33589248 WHERE `entry`=154327; -- Austin Huxworth
UPDATE `creature_template` SET `minlevel`=10, `maxlevel`=10, `faction`=35, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags2`=34816 WHERE `entry`=156662; -- Captain Garrick
UPDATE `creature_template` SET `npcflag`=2 WHERE `entry`=175030; -- Won'sa

-- Gossip
DELETE FROM `gossip_menu` WHERE (`MenuID`=25542 AND `TextID`=40339);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(25542, 40339, 44908); -- 166996 (Mithdran Dawntracker)

-- Phasing
DELETE FROM `phase_area` WHERE (`AreaId` = 10452 AND `PhaseId` IN (16752, 15293)) OR (`AreaId` = 10424 AND `PhaseId` IN (13846, 13762, 15312, 15313));
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(10452, 16752, 'Cosmetic - NPE - Alaria after Quest 55174 is rewarded'),
(10424, 13846, 'Cosmetic - NPE - Austin Huxworth scout at Quilboar Briarpatch'),
(10424, 13762, 'Cosmetic - NPE - Captain Garrick scout at Quilboar Briarpatch'),
(10452, 15293, 'Cosmetic - NPE - Won''sa after Quest 59932 is rewarded'),
(10424, 15312, 'Cosmetic - NPE - Mithdran Dawntracker scout at Quilboar Briarpatch'),
(10424, 15313, 'Cosmetic - NPE - Warlord Breka scout at Quilboar Briarpatch');

-- Phase Names
DELETE FROM `phase_name` WHERE `ID` IN (16752, 13846, 13762, 15293, 15312, 15313);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(16752, 'Cosmetic - NPE - Alaria after Quest 55174 is rewarded'),
(13846, 'Cosmetic - NPE - Austin Huxworth scout at Quilboar Briarpatch'),
(13762, 'Cosmetic - NPE - Captain Garrick scout at Quilboar Briarpatch'),
(15293, 'Cosmetic - NPE - Won''sa after Quest 59932 is rewarded'),
(15312, 'Cosmetic - NPE - Mithdran Dawntracker scout at Quilboar Briarpatch'),
(15313, 'Cosmetic - NPE - Warlord Breka scout at Quilboar Briarpatch');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 16752 AND `SourceEntry` = 10452) OR (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 13762 AND `SourceEntry` = 10424) OR (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 13846 AND `SourceEntry` = 10424) OR (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 15293 AND `SourceEntry` = 10452) OR (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 15312 AND `SourceEntry` = 10424) OR (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 15313 AND `SourceEntry` = 10424);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
-- Allaria
(26, 16752, 10452, 0, 0, 47, 0, 55174, 64, 0, 0, 'Apply Phase 16752 If Quest 55174 IS rewarded'),
-- Captain Garrick
(26, 13762, 10424, 0, 0, 47, 0, 55173, 2 | 64, 0, 0, 'Apply Phase 13762 If Quest 55173 IS complete | rewarded'),
(26, 13762, 10424, 0, 0, 47, 0, 55186, 2 | 8 | 64, 0, 1, 'Apply Phase 13762 If Quest 55186 IS NOT in Progress | complete | rewarded'),
(26, 13762, 10424, 0, 1, 47, 0, 55173, 2 | 64, 0, 0, 'Apply Phase 13762 If Quest 55173 IS complete | rewarded'),
(26, 13762, 10424, 0, 1, 47, 0, 55184, 2 | 8 | 64, 0, 1, 'Apply Phase 13762 If Quest 55184 IS NOT in Progress | complete | rewarded'),
-- Austin Huxworth
(26, 13846, 10424, 0, 0, 47, 0, 55173, 2 | 64, 0, 0, 'Apply Phase 13846 If Quest 55173 IS complete | rewarded'),
(26, 13846, 10424, 0, 0, 47, 0, 55186, 2 | 8 | 64, 0, 1, 'Apply Phase 13846 If Quest 55186 IS NOT in Progress | complete | rewarded'),
(26, 13846, 10424, 0, 1, 47, 0, 55173, 2 | 64, 0, 0, 'Apply Phase 13846 If Quest 55173 IS complete | rewarded'),
(26, 13846, 10424, 0, 1, 47, 0, 55184, 2 | 8 | 64, 0, 1, 'Apply Phase 13846 If Quest 55184 IS NOT in Progress | complete | rewarded'),
-- Won''sa
(26, 15293, 10452, 0, 0, 47, 0, 59932, 64, 0, 0, 'Apply Phase 15293 If Quest 59932 IS rewarded'),
-- Mithdran Dawntracker
(26, 15312, 10424, 0, 0, 47, 0, 59935, 2 | 64, 0, 0, 'Apply Phase 15312 If Quest 59935 IS complete | rewarded'),
(26, 15312, 10424, 0, 0, 47, 0, 59938, 2 | 8 | 64, 0, 1, 'Apply Phase 15312 If Quest 59938 IS NOT in Progress | complete | rewarded'),
(26, 15312, 10424, 0, 1, 47, 0, 59935, 2 | 64, 0, 0, 'Apply Phase 15312 If Quest 59935 IS complete | rewarded'),
(26, 15312, 10424, 0, 1, 47, 0, 59939, 2 | 8 | 64, 0, 1, 'Apply Phase 15312 If Quest 59939 IS NOT in Progress | complete | rewarded'),
-- Warlord Breka
(26, 15313, 10424, 0, 0, 47, 0, 59935, 2 | 64, 0, 0, 'Apply Phase 15313 If Quest 59935 IS complete | rewarded'),
(26, 15313, 10424, 0, 0, 47, 0, 59938, 2 | 8 | 64, 0, 1, 'Apply Phase 15313 If Quest 59938 IS NOT in Progress | complete | rewarded'),
(26, 15313, 10424, 0, 1, 47, 0, 59935, 2 | 64, 0, 0, 'Apply Phase 15313 If Quest 59935 IS complete | rewarded'),
(26, 15313, 10424, 0, 1, 47, 0, 59939, 2 | 8 | 64, 0, 1, 'Apply Phase 15313 If Quest 59939 IS NOT in Progress | complete | rewarded');
