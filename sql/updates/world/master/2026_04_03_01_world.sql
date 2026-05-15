SET @ATIDSPAWN := 285;
SET @ATCP := 175;
SET @ATID := 184;

DELETE FROM `areatrigger` WHERE `SpawnId`=888888;
DELETE FROM `areatrigger_create_properties` WHERE `Id`=888888 AND `IsCustom`=1;
DELETE FROM `areatrigger_template` WHERE `Id`=888888 AND `IsCustom`=1;

DELETE FROM `areatrigger` WHERE `SpawnId`=@ATIDSPAWN;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerCreatePropertiesId`, `IsCustom`, `MapId`, `SpawnDifficulties`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `ScriptName`, `Comment`, `VerifiedBuild`) VALUES
(@ATIDSPAWN, @ATCP, 1, 2651, '1,2,8,23', 119.2231, -154.7091, 73.8308, 3.152349, 0, 0, 0, '', 'Darkflame Cleft - The Candle King encounter - Candlelight', 66192);

DELETE FROM `areatrigger_create_properties` WHERE `Id`=@ATCP AND `IsCustom`=1;
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `SpeedIsTime`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(@ATCP, 1, @ATID, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 0, 1, 32, 50, 5, 32, 50, 5, 0, 0, 'at_the_candle_king_candlelight', 0);

DELETE FROM `areatrigger_template` WHERE `Id`=@ATID AND `IsCustom`=1;
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `ActionSetId`, `ActionSetFlags`, `VerifiedBuild`) VALUES
(@ATID, 1, 1, 0, 0, 0);
