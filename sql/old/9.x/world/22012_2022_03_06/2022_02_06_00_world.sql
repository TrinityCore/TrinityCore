DELETE FROM `areatrigger_template` WHERE (`IsServerSide`=0 AND `Id`=23072);
INSERT INTO `areatrigger_template` (`Id`, `IsServerSide`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `VerifiedBuild`) VALUES
(23072, 0, 4, 0, 20, 20, 16, 16, 8, 8, 41488);

DELETE FROM `areatrigger_create_properties` WHERE `Id`=19042;
INSERT INTO `areatrigger_create_properties` (`Id`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ScriptName`, `VerifiedBuild`) VALUES 
(19042, 23072, 0, 0, 0, 0, -1, 0, 0, 0, 30000, 4, 20, 20, 16, 16, 8, 8, 'areatrigger_pal_ashen_hallow', 41488);
