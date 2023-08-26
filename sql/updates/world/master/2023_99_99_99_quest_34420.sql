SET @CGUID := 500000000;

-- Creatures
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+10;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `VerifiedBuild`) VALUES
(@CGUID+0, 78558, 1265, 7025, 7037, '0', 3569, 0, 0, 1, 4066.50439453125, -2372.154541015625, 94.665191650390625, 1.596214056015014648, 120, 0, 0, 640000, 9573, 0, 0, 0, 50791), -- Archmage Khadgar (Area: The Dark Portal - Difficulty: 0) CreateObject1
(@CGUID+1, 78553, 1265, 7025, 7041, '0', 3395, 0, 0, 1, 3956.76123046875, -2523.6806640625, 69.74970245361328125, 5.858800411224365234, 120, 0, 0, 4800000, 320750, 0, 0, 0, 50791), -- Thrall (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+2, 78569, 1265, 7025, 7041, '0', 3264, 0, 0, 1, 3931.802978515625, -2510.703125, 69.73077392578125, 4.66814422607421875, 120, 0, 0, 20000, 0, 0, 0, 0, 50791), -- Hansel Heavyhands (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+3, 78568, 1265, 7025, 7041, '0', 3264, 0, 0, 1, 3940.8994140625, -2510.875, 69.37921142578125, 5.61804819107055664, 120, 0, 0, 20000, 0, 0, 0, 0, 50791), -- Thaelin Darkanvil (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+4, 79315, 1265, 7025, 7041, '0', 3264, 0, 0, 1, 3943.55126953125, -2505.182373046875, 69.37921142578125, 5.88816070556640625, 120, 0, 0, 20000, 0, 0, 0, 0, 50791), -- Olin Umberhide (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+5, 78559, 1265, 7025, 7041, '0', 3394, 0, 0, 1, 3936.718017578125, -2505.223876953125, 69.73077392578125, 5.608281135559082031, 120, 0, 0, 640000, 9573, 0, 0, 0, 50791), -- Archmage Khadgar (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+6, 78556, 1265, 7025, 7041, '0', 3264, 0, 0, 1, 3936.046875, -2520.348876953125, 69.73077392578125, 3.980798721313476562, 120, 0, 0, 20000, 0, 0, 0, 0, 50791), -- Ariok (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+7, 79316, 1265, 7025, 7041, '0', 3264, 0, 0, 1, 3972.09033203125, -2524.10595703125, 65.6986236572265625, 1.900716662406921386, 120, 0, 0, 20000, 1283, 0, 0, 0, 50791), -- Qiana Moonshadow (Area: Heartblood - Difficulty: 0) CreateObject1 (Auras: 32356 - Cat Form, 132653 - Stealth)
(@CGUID+8, 79675, 1265, 7025, 7041, '0', 3264, 0, 0, 1, 3951.240478515625, -2501.229248046875, 69.73077392578125, 0.763182044029235839, 120, 0, 0, 400000, 0, 0, 0, 0, 50791), -- Lady Liadrin (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+9, 78430, 1265, 7025, 7041, '0', 3264, 0, 0, 1, 3936.319580078125, -2503.619873046875, 69.73077392578125, 5.626811981201171875, 120, 0, 0, 400000, 100, 0, 0, 0, 50791), -- Cordana Felsong (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+10, 78554, 1265, 7025, 7041, '0', 3396, 0, 0, 1, 3958.908935546875, -2520.145751953125, 69.7492828369140625, 5.844482421875, 120, 0, 0, 4800000, 128300, 0, 0, 0, 50791); -- Vindicator Maraad (Area: Heartblood - Difficulty: 0) CreateObject1 (Auras: 165746 - Retribution Aura)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+10;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- Archmage Khadgar
(@CGUID+1, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Thrall
(@CGUID+3, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Thaelin Darkanvil
(@CGUID+4, 0, 0, 0, 0, 0, 1, 0, 0, 6411, 0, 0, 0, ''), -- Olin Umberhide
(@CGUID+6, 0, 0, 0, 0, 0, 1, 0, 0, 6413, 0, 0, 0, ''), -- Ariok
(@CGUID+7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '32356 132653'), -- Qiana Moonshadow - 32356 - Cat Form, 132653 - Stealth
(@CGUID+8, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Lady Liadrin
(@CGUID+10, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, '165746'); -- Vindicator Maraad - 165746 - Retribution Aura

UPDATE `creature_template` SET `unit_flags2`=4196352, `ScriptName` = 'npc_assault_archmage_khadgar' WHERE `entry`=78558; -- Archmage Khadgar
UPDATE `creature_template` SET `unit_flags3`=1048576 WHERE `entry`=78430; -- Cordana Felsong
UPDATE `creature_template` SET `unit_flags3`=1048576 WHERE `entry`=78553; -- Thrall
UPDATE `creature_template` SET `unit_flags3`=1048576 WHERE `entry`=78569; -- Hansel Heavyhands
UPDATE `creature_template` SET `unit_flags3`=1048576 WHERE `entry`=78568; -- Thaelin Darkanvil

-- Scene
UPDATE `scene_template` SET `ScriptName` = 'scene_dark_portal_run_away' WHERE `SceneId`=621; -- Archmage Khadgar

-- Phase
DELETE FROM `phase_area` WHERE `AreaId`IN (7025, 7041) AND `PhaseId` IN (3569, 3264, 3394, 3395, 3396);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7025, 3569, 'See Questgivers at Bleeding Hollow Building'),
(7041, 3264, 'See Questgivers at Bleeding Hollow Building'),
(7041, 3394, 'See Khadgar at Bleeding Hollow Building'),
(7041, 3395, 'See Thrall at Bleeding Hollow Building'),
(7041, 3396, 'See Maraad at Bleeding Hollow Building');

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=3569 AND `SourceEntry`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26, 3569, 0, 0, 0, 47, 0, 34393, 66, 0, 0, 0, 0, '', 'Apply Phase 3569 if Quest 34393 is complete | rewarded'),
(26, 3569, 0, 0, 0, 47, 0, 34420, 66, 0, 0, 0, 1, '', 'Apply Phase 3569 if Quest 34420 is not complete | rewarded');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=3264 AND `SourceEntry`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26, 3264, 0, 0, 0, 1, 0, 158985, 0, 0, 1, 0, 0, '', 'Apply Phase 3264 if has no aura 158985'),
(26, 3264, 0, 0, 0, 47, 0, 34420, 66, 0, 0, 0, 0, '', 'Apply Phase 3264 if Quest 34420 is complete | rewarded');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=3394 AND `SourceEntry`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26, 3394, 0, 0, 0, 1, 0, 158985, 0, 0, 1, 0, 0, '', 'Apply Phase 3394 if has no aura 158985'),
(26, 3394, 0, 0, 0, 47, 0, 34420, 66, 0, 0, 0, 0, '', 'Apply Phase 3394 if Quest 34420 is complete | rewarded');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=3395 AND `SourceEntry`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26, 3395, 0, 0, 0, 1, 0, 158985, 0, 0, 1, 0, 0, '', 'Apply Phase 3395 if has no aura 158985'),
(26, 3395, 0, 0, 0, 47, 0, 34420, 66, 0, 0, 0, 0, '', 'Apply Phase 3395 if Quest 34420 is complete | rewarded');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=3396 AND `SourceEntry`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26, 3396, 0, 0, 0, 1, 0, 158985, 0, 0, 1, 0, 0, '', 'Apply Phase 3396 if has no aura 158985'),
(26, 3396, 0, 0, 0, 47, 0, 34420, 66, 0, 0, 0, 0, '', 'Apply Phase 3396 if Quest 34420 is complete | rewarded');
