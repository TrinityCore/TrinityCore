DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dru_orbital_strike', 'spell_dru_orbital_strike_damage');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(383410, 'spell_dru_orbital_strike'),
(390414, 'spell_dru_orbital_strike'),
(361237, 'spell_dru_orbital_strike_damage');

DELETE FROM `areatrigger_template` WHERE `Id`=30901 AND `IsCustom`=0;
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `VerifiedBuild`) VALUES
(30901, 0, 70783);

DELETE FROM `areatrigger_create_properties` WHERE `Id`=26768 AND `IsCustom`=0;
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `PositionalSoundKitId`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `Roll`, `Pitch`, `Yaw`, `TargetRoll`, `TargetPitch`, `TargetYaw`, `ScriptName`, `VerifiedBuild`) VALUES
(26768, 0, 30901, 0, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 3000, 45, 4, 3, 3, 10, 10, 0.300000011920928955, 0.300000011920928955, 0, 0, 0, 0, 0, NULL, NULL, NULL, 'at_dru_orbital_strike', 70783); -- Spell: 390381 (Celestial Alignment)
