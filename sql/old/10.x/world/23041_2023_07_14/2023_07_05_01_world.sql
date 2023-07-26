SET @CGUID := 652131;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 88797, 1220, 7334, 7352, '0', 4332, 0, 0, 1, 201.0520782470703125, 6424.34716796875, -22.1320743560791015, 3.902812719345092773, 120, 0, 0, 3138, 3801, 0, 16777216, 0, 512, 46455), -- Elder Aldryth (Area: El'dranil Shallows - Difficulty: 0)
(@CGUID+1, 88797, 1220, 7334, 7355, '0', 4331, 0, 0, 1, -15.3784723281860351, 6738.9599609375, 55.67095184326171875, 5.669478893280029296, 120, 0, 0, 3138, 3801, 0, 0, 0, 0, 46455); -- Elder Aldryth (Area: Crumbled Palace - Difficulty: 0)

DELETE FROM `creature_addon` WHERE `guid` = @CGUID+0;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 0, 1, 0,  0, 7624, 0, 0, 0, ''); -- Elder Aldryth

-- Phase
DELETE FROM `phase_name` WHERE `ID` IN (4331, 4332);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(4331, 'Cosmetic - See Elder Aldryth at Crumbled Palace'),
(4332, 'Cosmetic - See Elder Aldryth at El\'dranil Shallows');

DELETE FROM `phase_area` WHERE `AreaId` IN (7357, 7352, 7355, 7366, 7358) AND `PhaseId` IN (4331, 4332);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7352, 4331, 'See Elder Aldryth at Crumbled Palace'), -- El'dranil Shallows Zone
(7355, 4331, 'See Elder Aldryth at Crumbled Palace'), -- Crumble Palace Zone
(7357, 4331, 'See Elder Aldryth at Crumbled Palace'), -- Drowned Gardens
(7366, 4331, 'See Elder Aldryth at Crumbled Palace'), -- Ruins of Nar'thalas
(7358, 4331, 'See Elder Aldryth at Crumbled Palace'), -- Nar'thalas Academy
(7352, 4332, 'See Elder Aldryth at El\'dranil Shallows'), -- El'dranil Shallows Zone
(7355, 4332, 'See Elder Aldryth at El\'dranil Shallows'), -- Crumble Palace Zone
(7357, 4332, 'See Elder Aldryth at El\'dranil Shallows'), -- Drowned Gardens
(7366, 4332, 'See Elder Aldryth at El\'dranil Shallows'), -- Ruins of Nar'thalas
(7358, 4332, 'See Elder Aldryth at El\'dranil Shallows'); -- Nar'thalas Academy

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (4331, 4332) AND `SourceEntry` IN (7357, 7352, 7355, 7366, 7358);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 4331, 7352, 0, 0, 47, 0, 37492, 2 | 64, 0, 0, 'Apply Phase 4331 if Quest 37492 is completed | rewarded'),
(26, 4331, 7355, 0, 0, 47, 0, 37492, 2 | 64, 0, 0, 'Apply Phase 4331 if Quest 37492 is completed | rewarded'),
(26, 4331, 7357, 0, 0, 47, 0, 37492, 2 | 64, 0, 0, 'Apply Phase 4331 if Quest 37492 is completed | rewarded'),
(26, 4331, 7358, 0, 0, 47, 0, 37492, 2 | 64, 0, 0, 'Apply Phase 4331 if Quest 37492 is completed | rewarded'),
(26, 4331, 7366, 0, 0, 47, 0, 37492, 2 | 64, 0, 0, 'Apply Phase 4331 if Quest 37492 is completed | rewarded'),
(26, 4332, 7352, 0, 0, 47, 0, 37492, 2 | 64, 0, 1, 'Apply Phase 4332 if Quest 37492 is not completed | rewarded'),
(26, 4332, 7355, 0, 0, 47, 0, 37492, 2 | 64, 0, 1, 'Apply Phase 4332 if Quest 37492 is not completed | rewarded'),
(26, 4332, 7357, 0, 0, 47, 0, 37492, 2 | 64, 0, 1, 'Apply Phase 4332 if Quest 37492 is not completed | rewarded'),
(26, 4332, 7358, 0, 0, 47, 0, 37492, 2 | 64, 0, 1, 'Apply Phase 4332 if Quest 37492 is not completed | rewarded'),
(26, 4332, 7366, 0, 0, 47, 0, 37492, 2 | 64, 0, 1, 'Apply Phase 4332 if Quest 37492 is not completed | rewarded');
