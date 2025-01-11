DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_gen_spatial_rift';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(257040, 'spell_gen_spatial_rift');

DELETE FROM `areatrigger_template` WHERE `Id` = 16670;
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `ActionSetId`, `ActionSetFlags`, `VerifiedBuild`) VALUES
(16670, 0, 0, 0, 0, 58238);

DELETE FROM `areatrigger_create_properties` WHERE `Id` = 11983;
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreaTriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES 
(11983, 0, 16670, 0, 0, 0, 0, 0, 0, 0, -1, 0, 256948, 8000, 18, 0, 3, 3, 0, 0, 0, 0, 0, 0, 'at_gen_spatial_rift', 58238); -- SpellForVisuals: 256948
