DELETE FROM `areatrigger_create_properties` WHERE (`Id`=35958 AND `IsCustom`=0);
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `PositionalSoundKitId`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(35958, 0, 3678, 0, 0, 0, 0, 0, 0, -1, 0, 0, 132950, 0, 20000, 0, 4, 15, 15, 7, 7, 3, 3, 0, 0, 'at_hun_legion_flare', 69875); -- SpellForVisuals: 132950 (Flare)

UPDATE `areatrigger_create_properties` SET `ScriptName`='at_hun_legion_flare' WHERE `Id`=510;

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_hun_kindling_flare';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(132950, 'spell_hun_kindling_flare');
