SET @ATID := 137;
SET @ATCREATEID := 132;
SET @ATSPAWNID := 231;

DELETE FROM `areatrigger_template` WHERE `Id` BETWEEN @ATID+0 AND @ATID+26;
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `ActionSetId`, `ActionSetFlags`, `VerifiedBuild`) VALUES
(@ATID+0, 1, 1, 0, 0x0, 0);

DELETE FROM `areatrigger_create_properties` WHERE `Id` BETWEEN @ATCREATEID+0 AND @ATCREATEID+26;
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(@ATCREATEID+0, 1, @ATID+0, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 4, 15, 15, 25, 25, 0, 0, 0, 0, '', 0);

DELETE FROM `areatrigger` WHERE `SpawnId` BETWEEN @ATSPAWNID+0 AND @ATSPAWNID+26;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerCreatePropertiesId`, `IsCustom`, `MapId`, `SpawnDifficulties`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `Comment`) VALUES
(@ATSPAWNID+0, @ATCREATEID+0, 1, 1220, '0', -62.13, 7000.73, 19.81, 4.45, 0, 'Illidari Stand - Tavern');

DELETE FROM `areatrigger_template_actions` WHERE `AreaTriggerId` BETWEEN @ATID+0 AND @ATID+26;
INSERT INTO `areatrigger_template_actions` (`AreaTriggerId`, `IsCustom`, `ActionType`, `ActionParam`, `TargetType`) VALUES
(@ATID+0, 1, 3, 0, 5);
