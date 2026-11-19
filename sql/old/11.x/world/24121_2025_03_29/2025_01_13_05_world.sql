DELETE FROM `areatrigger_template` WHERE (`Id`=28714 AND `IsCustom`=0);
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES
(28714, 0, 0, 58187);

DELETE FROM `areatrigger_create_properties` WHERE (`Id`=24713 AND `IsCustom`=0);
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(24713, 0, 28714, 0, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 10000, 0, 10, 10, 0, 0, 0, 0, 0, 0, 'at_evo_firestorm', 58187); -- Spell: 369372 (Firestorm)
