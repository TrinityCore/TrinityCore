DELETE FROM `areatrigger_create_properties` WHERE (`IsCustom`=0 AND `Id` IN (43227));
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `MaxSummons`, `MaxUnits`, `PositionalSoundKitId`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `Roll`, `Pitch`, `Yaw`, `TargetRoll`, `TargetPitch`, `TargetYaw`, `ScriptName`, `VerifiedBuild`) VALUES
(43227, 0, 43923, 0, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 1, NULL, 0, 18000, 0, 4, 11, 11, 7, 7, 3, 3, 0, 0, 0, 0, 0, NULL, NULL, NULL, '', 70391); -- Spell: 1298679 (Healing Rain)

DELETE FROM `areatrigger_template` WHERE (`IsCustom`=0 AND `Id` IN (43923));
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `VerifiedBuild`) VALUES
(43923, 0, 70391);

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_sha_deluge_healing_rain';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_sha_healing_rain_areatrigger';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(1298679, 'spell_sha_healing_rain_areatrigger');
