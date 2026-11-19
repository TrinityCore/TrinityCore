SET @OGUID := 10001191;

SET @ATID := 33862;
SET @ATCP := 90;
SET @ATIDSPAWN := 103;

-- GameObject
DELETE FROM `gameobject` WHERE `guid` = @OGUID+0;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 453062, 2552, 14717, 14788, '0', 0, 0, 1628.1944580078125, -2381.8369140625, 80.79339599609375, 4.770765304565429687, 0.388990402221679687, 0.376737594604492187, -0.58820533752441406, 0.600641131401062011, 120, 255, 0, 57689); -- Parachute (Area: The Opalcreg - Difficulty: 0) CreateObject1

DELETE FROM `gameobject_addon` WHERE `guid` = @OGUID+0;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, 0, 1, 569, 0); -- Parachute

-- Template Addon
DELETE FROM `gameobject_template_addon` WHERE `entry` = 453062;
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(453062, 0, 0x40001, 569, 0); -- Parachute

-- Serverside AT
DELETE FROM `areatrigger_template` WHERE (`Id` = @ATID+0 AND `IsCustom` = 0);
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES 
(@ATID+0, 0, 1, 0);

DELETE FROM `areatrigger_create_properties` WHERE (`Id`= @ATCP+0 AND `IsCustom`=1);
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES 
(@ATCP+0, 1, @ATID+0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 4, 60, 60, 7, 7, 0, 0, 0, 0, '', 0);

DELETE FROM `areatrigger` WHERE `SpawnId` = @ATIDSPAWN+0;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerCreatePropertiesId`, `IsCustom`, `MapId`, `SpawnDifficulties`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `ScriptName`, `Comment`, `VerifiedBuild`) VALUES 
(@ATIDSPAWN+0, @ATCP+0, 1, 2552, '0', 1622.472, -2412.862, -42.118, 5.41855, 0, 0, 0, '', 'Isle of Dorn - The Opalcreg - Killcredit for Quest: "Hit Rock Bottom"', 0);
