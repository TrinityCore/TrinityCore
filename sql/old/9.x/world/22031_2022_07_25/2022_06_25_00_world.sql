SET @CGUID := 460117;

-- Creature
DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 79242, 1116, 7078, 7078, '0', 3695, 0, 0, 1, 1943.904541015625, 339.1944580078125, 89.0157623291015625, 4.354201793670654296, 7200, 0, 0, 5913, 9573, 0, 0, 0, 0, 44232); -- Archmage Khadgar (Area: -Unknown- - Difficulty: 0)

-- Creature Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (79242 /*79242 (Archmage Khadgar)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(79242, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''); -- 79242 (Archmage Khadgar)

UPDATE `creature_template` SET `gossip_menu_id`=16411 WHERE `entry`=79242; -- Archmage Khadgar

-- Phasing
DELETE FROM `phase_area` WHERE `AreaId` = 7078 AND `PhaseId` = 3695;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7078, 3695, 'Cosmetic - See Khadgar at Lunarfall Pre-Garrison');

DELETE FROM `phase_name` WHERE `ID` = 3695;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(3695, 'Cosmetic - See Khadgar at Lunarfall Pre-Garrison');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 3695 AND `SourceEntry` = 7078);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 3695, 7078, 0, 0, 47, 0, 34583, 66, 0, 1, 'Apply Phase 3695 if Quest 34583 IS NOT Complete/Rewarded');
