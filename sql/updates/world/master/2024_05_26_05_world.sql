SET @CGUID := 7000562;

DELETE FROM `phase_name` WHERE `ID`=12646;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(12646, 'Cosmetic: Kul Tiran Unlock Questline - FX Stalker Dread Vessel in Ulfars Den');

DELETE FROM `phase_area` WHERE `PhaseId`=12646;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(9965, 12646, 'Cosmetic: Kul Tiran Unlock Questline - FX Stalker Dread Vessel - Ulfars Den');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26) AND (`SourceGroup` IN (12646));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(26, 12646, 0, 0, 0, 48, 0, 388256, 0, 1, '', 0, 'Player have quest objective 388256 == 1');

DELETE FROM `creature` WHERE `guid`=@CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 149374, 1643, 8721, 9965, '0', 12646, 0, 0, 0, -488.498260498046875, 2723.901123046875, 280.91302490234375, 0, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847); -- FX Stalker (Area: Ulfar's Den - Difficulty: 0) CreateObject1 (Auras: 289631 - [DNT] Drust Vessel FX)

DELETE FROM `creature_addon` WHERE `guid`=@CGUID+0;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '289631'); -- FX Stalker - 289631 - [DNT] Drust Vessel FX
