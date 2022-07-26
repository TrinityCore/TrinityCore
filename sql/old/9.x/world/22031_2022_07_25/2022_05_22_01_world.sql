SET @CGUID := 1051030;

-- Creature Spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 166323, 2222, 10534, 13307, '0', 14081, 0, 0, 0, -4056.005126953125, -4330.54345703125, 6514.421875, 5.471034049987792968, 7200, 0, 0, 6100, 0, 0, 0, 0, 0, 43345), -- Pelagos (Area: -Unknown- - Difficulty: 0) (Auras: 312726 - -Unknown-)
(@CGUID+1, 165112, 2222, 10534, 11473, '0', 14082, 0, 0, 0, -4086.84375, -4632.76220703125, 6536.0849609375, 3.678891420364379882, 7200, 0, 0, 6100, 0, 0, 0, 0, 0, 43345); -- Pelagos (Area: -Unknown- - Difficulty: 0)

-- Creature Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` = 166323;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(166323, 0, 0, 50331648, 1, 0, 19033, 0, 0, 0, '312726'); -- 166323 (Pelagos) - -Unknown-

-- Creature Template Movement
DELETE FROM `creature_template_movement` WHERE `CreatureId` = 166323;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(166323, 0, 0, 1, 0, 0, 0, NULL);

-- Phase
DELETE FROM `phase_area` WHERE (`AreaId` = 13307 AND `PhaseId` = 14081) OR (`AreaId` = 11473 AND `PhaseId` = 14082);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(13307, 14081, 'Cosmetic: Pelagos Spawn for Quest: 57677 is taken'),
(11473, 14082, 'Cosmetic: Pelagos Spawn for Quest: 57677 is complete/rewarded');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 14081 AND `SourceEntry` = 13307) OR (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 14082 AND `SourceEntry` = 11473);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 14081, 13307, 0, 0, 9, 0, 57677, 0, 0, 0, 'Allow Phase 14081 if Quest (57677) is taken'),
(26, 14082, 11473, 0, 0, 47, 0, 57677, 66, 0, 0, 'Allow Phase 14082 if Quest (57677) is complete/rewarded');

DELETE FROM `phase_name` WHERE `ID` IN (14081, 14082);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(14081, 'Pelagos for Quest: A Soulbind in need'),
(14082, 'Pelagos after Quest: A Soulbind in need');
