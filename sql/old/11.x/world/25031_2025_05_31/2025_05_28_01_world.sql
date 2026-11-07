DELETE FROM `areatrigger_create_properties` WHERE (`Id`=5484 AND `IsCustom`=0);
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(5484, 0, 10191, 0, 24, 1656, 0, 0, 0, -1, 0, 0, NULL, 5000, 7, 0, 5, 5, 0, 0, 0, 0, 0, 0, 'at_monk_song_of_chi_ji', 60822); -- Spell: 198898 (Song of Chi-Ji)

UPDATE `areatrigger_template` SET `VerifiedBuild`=60822 WHERE (`Id`=10191 AND `IsCustom`=0);
