DELETE FROM `areatrigger_create_properties` WHERE (`IsCustom`=0 AND `Id` = 5994);
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(5994, 0, 10682, 0, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 8500, 0, 4, 8, 8, 30, 30, 1, 1, 0, 0, 'at_dru_lunar_beam', 59679); -- Spell: 204066 (Lunar Beam)

UPDATE `areatrigger_template` SET `VerifiedBuild`=59679 WHERE (`Id`=10682 AND `IsCustom`=0);
