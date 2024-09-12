SET @CGUID := 7000563;
SET @OGUID := 7000209;

DELETE FROM `phase_name` WHERE `ID`=12862;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(12862, 'Cosmetic: Kul Tiran Unlock Questline - FX Stalker Pretty Plant and Lumber in Ulfars Den');

DELETE FROM `phase_area` WHERE `PhaseId`=12862;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(9965, 12862, 'Cosmetic: Kul Tiran Unlock Questline - FX Stalker Pretty Plant and Lumber - Ulfars Den');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26) AND (`SourceGroup` IN (12862));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(26, 12862, 0, 0, 0, 47, 0, 54731, 66, 0, '', 0, 'Player have Balance in All Things (54731) in state complete, rewarded');

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 149374, 1643, 8721, 9965, '0', 12862, 0, 0, 0, -488.498260498046875, 2723.900146484375, 279.36395263671875, 0, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- FX Stalker (Area: Ulfar's Den - Difficulty: 0) CreateObject1 - !!! already present in database !!!
(@CGUID+1, 149365, 1643, 8721, 9965, '0', 12862, 0, 0, 0, -488.489593505859375, 2723.890625, 280.480316162109375, 0, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847); -- Ancient Seedling (Area: Ulfar's Den - Difficulty: 0) CreateObject1

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '292381'), -- FX Stalker - [DNT] Pretty Plant
(@CGUID+1, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- Ancient Seedling

DELETE FROM `gameobject` WHERE `guid`=@OGUID+0;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 316972, 1643, 8721, 9965, '0', 12862, 0, -488.513885498046875, 2723.861083984375, 279.28173828125, 0, 0, 0, 0, 1, 120, 255, 1, 54847); -- Algerson Lumber Sample (Area: Ulfar's Den - Difficulty: 0) CreateObject1 - !!! already present in database !!!
