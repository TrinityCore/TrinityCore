SET @ATID := 100000;
SEt @ATCP := 100000;
SET @ATIDSPAWN := 100000;

-- AreaTrigger Alliance Garrison V1
DELETE FROM `areatrigger_template` WHERE `Id` = @ATID+0 AND `IsCustom` = 1;
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES 
(@ATID+0, 1, 1, 0);

DELETE FROM `areatrigger` WHERE `SpawnId` BETWEEN @ATIDSPAWN+0 AND @ATIDSPAWN+1;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerCreatePropertiesId`, `IsCustom`, `MapId`, `SpawnDifficulties`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `SpellForVisuals`, `ScriptName`, `Comment`, `VerifiedBuild`) VALUES 
(@ATIDSPAWN+0, @ATCP+0, 1, 1116, '0', 1900.9937, 221.3306, 76.9551, 0, 0, 0, 0, NULL, 'at_garrison_enter', 'Enter Garrison Alliance V1', 0),
(@ATIDSPAWN+1, @ATCP+0, 1, 1158, '1', 1900.9937, 221.3306, 76.9551, 0, 0, 0, 0, NULL, 'at_garrison_exit', 'Leave Garrison Alliance V1', 0);

DELETE FROM `areatrigger_create_properties` WHERE `Id`=@ATCP+0 AND `IsCustom`=1;
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES 
(@ATCP+0, 1, @ATID+0, 1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 3, 1000, 1000, 0, 0, 0, 0, 0, 0, '', 0);

DELETE FROM `areatrigger_create_properties_polygon_vertex` WHERE `AreaTriggerCreatePropertiesId`=@ATCP+0 AND `IsCustom`=1;
INSERT INTO `areatrigger_create_properties_polygon_vertex` (`AreaTriggerCreatePropertiesId`, `IsCustom`, `Idx`, `VerticeX`, `VerticeY`, `VerticeTargetX`, `VerticeTargetY`, `VerifiedBuild`) VALUES
(@ATCP+0, 1, 5, 80.74610000000007, 218.2616, NULL, NULL, 0),
(@ATCP+0, 1, 4, -195.68599999999992, 173.7912, NULL, NULL, 0),
(@ATCP+0, 1, 3, -176.72000000000003, -182.52249999999998, NULL, NULL, 0),
(@ATCP+0, 1, 2, 47.75040000000013, -222.8499, NULL, NULL, 0),
(@ATCP+0, 1, 1, 153.72890000000007, -139.58939999999998, NULL, NULL, 0),
(@ATCP+0, 1, 0, 193.42909999999983, -26.468999999999994, NULL, NULL, 0);
