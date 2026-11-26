DELETE FROM `areatrigger_template` WHERE (`IsCustom`=0 AND `Id` IN (29625,27842));
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `VerifiedBuild`) VALUES
(29625, 0, 70783),
(27842, 0, 70783);

DELETE FROM `areatrigger_create_properties` WHERE (`IsCustom`=0 AND `Id` IN (25144,23578));
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `PositionalSoundKitId`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `Roll`, `Pitch`, `Yaw`, `TargetRoll`, `TargetPitch`, `TargetYaw`, `ScriptName`, `VerifiedBuild`) VALUES
(25144, 0, 29625, 0, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 15000, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, NULL, '', 70783), -- Spell: 355689 (Landslide)
(23578, 0, 27842, 0, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 5000, 35, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, NULL, 'at_evo_landslide', 70783); -- Spell: 363800 (Landslide)

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_evo_landslide';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(358385, 'spell_evo_landslide');
