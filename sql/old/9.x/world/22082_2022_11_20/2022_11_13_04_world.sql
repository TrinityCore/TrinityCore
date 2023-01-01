SET @CGUID := 651636;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 89669, 1220, 7334, 7358, '0', 4374, 0, 61748, 0, 54.71701431274414062, 6308.99853515625, -15.1583423614501953, 3.195667505264282226, 120, 0, 0, 3923, 0, 0, 16777216, 0, 0, 46455), -- Drowned Student (Area: Nar'thalas Academy - Difficulty: 0) (Auras: 120703 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+1, 89669, 1220, 7334, 7358, '0', 4375, 0, 61750, 0, 54.71701431274414062, 6308.99853515625, -15.1583423614501953, 3.195667505264282226, 120, 0, 0, 3923, 0, 0, 0, 0, 0, 46455); -- Drowned Student (Area: Nar'thalas Academy - Difficulty: 0) (Auras: 120703 - Cosmetic - Sleep Zzz Breakable)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 1, 0, 0, 0, 0, 0, '120703'), -- Drowned Student - 120703 - Cosmetic - Sleep Zzz Breakable
(@CGUID+1, 0, 0, 0, 1, 0, 0, 0, 0, 0, '120703'); -- Drowned Student - 120703 - Cosmetic - Sleep Zzz Breakable

UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `unit_flags3`=512, `VerifiedBuild`=46455 WHERE `entry`=89669; -- Drowned Student

-- Phase
DELETE FROM `phase_name` WHERE `ID` IN (4374, 4375);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(4374, 'Cosmetic - See Drowned Student (dressed) at Nar\'thalas Academy'),
(4375, 'Cosmetic - See Drowned Student (undressed) at Nar\'thalas Academy');

DELETE FROM `phase_area` WHERE `AreaId` = 7358 AND `PhaseId` IN (4374, 4375);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7358, 4374, 'See Drowned Student (dressed) at Nar\'thalas Academy'),
(7358, 4375, 'See Drowned Student (undressed) at Nar\'thalas Academy');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (4374, 4375) AND `SourceEntry` = 7358);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 4374, 7358, 0, 0, 47, 0, 37736, 2 | 64, 0, 1, 'Apply Phase 4374 if Quest 37486 is not completed | rewarded'),
(26, 4374, 7358, 0, 0, 48, 0, 276814, 0, 1, 1, 'Apply Phase 4374 if player has not quest objective done: Get Nar\'thalas Academy Robes'),
(26, 4375, 7358, 0, 0, 47, 0, 37736, 2 | 64, 0, 0, 'Apply Phase 4375 if Quest 37486 is completed | rewarded'),
(26, 4375, 7358, 0, 1, 48, 0, 276814, 0, 1, 0, 'Apply Phase 4375 if player has quest objective done: Get Nar\'thalas Academy Robes');
