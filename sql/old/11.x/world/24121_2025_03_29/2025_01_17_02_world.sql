DELETE FROM `areatrigger_template` WHERE (`Id`=26042 AND `IsCustom`=0);
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES
(26042, 0, 0, 58187);

DELETE FROM `areatrigger_create_properties` WHERE (`Id`=21832 AND `IsCustom`=0);
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(21832, 0, 26042, 0, 0, 21753, 0, 0, 0, -1, 0, 0, NULL, 2452, 4, 6, 6, 4, 4, 0.3, 0.3, 0, 0, 'at_dh_glaive_tempest', 58187); -- Spell: 342817 (Glaive Tempest)
