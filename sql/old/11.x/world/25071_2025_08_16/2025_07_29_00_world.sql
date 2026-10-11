-- Areatrigger
DELETE FROM `areatrigger_template` WHERE (`Id`=39879 AND `IsCustom`=0);
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES
(39879, 0, 0, 61967);

DELETE FROM `areatrigger_create_properties` WHERE (`Id`=38187 AND `IsCustom`=0);
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `VerifiedBuild`) VALUES
(38187, 0, 39879, 0, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 30000, /*UNKNOWN*/ 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 61967); -- Spell: 1231411 (Recuperate)
