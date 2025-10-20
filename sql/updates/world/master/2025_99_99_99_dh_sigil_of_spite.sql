DELETE FROM `areatrigger_create_properties` WHERE (`IsCustom`=0 AND `Id` = 26752);
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName` `VerifiedBuild`) VALUES
(26752, 0, 30889, 0, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 1000, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 'areatrigger_dh_sigil_of_spite', 63834); -- Spell: 390163 (Sigil of Spite)

DELETE FROM `areatrigger_template` WHERE (`IsCustom`=0 AND `Id` = 30889);
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `VerifiedBuild`) VALUES
(30889, 0, 63834);
