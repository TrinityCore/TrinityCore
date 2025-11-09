UPDATE `areatrigger_template` SET `VerifiedBuild`=61265 WHERE (`Id`=5972 AND `IsCustom`=0);

DELETE FROM `areatrigger_create_properties` WHERE (`IsCustom`=0 AND `Id` IN (1524));
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(1524, 0, 5972, 0, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 10000, 0, 4, 5, 5, 2, 2, 0.3, 0.3, 0, 0, 'at_hun_binding_shot', 61265); -- Spell: 109248 (Binding Shot)

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_hun_binding_shot';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(109248, 'spell_hun_binding_shot');
