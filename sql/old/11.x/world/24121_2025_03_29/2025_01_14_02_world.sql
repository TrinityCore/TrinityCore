DELETE FROM `areatrigger_template` WHERE (`Id`=27633 AND `IsCustom`=0);
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES
(27633, 0, 0, 58187);

DELETE FROM `areatrigger_create_properties` WHERE (`Id`=23318 AND `IsCustom`=0);
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(23318, 0, 27633, 0, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 1500, 0, 3, 3, 0, 0, 0, 0, 0, 0, 'at_evo_emerald_blossom', 58187); -- Spell: 355913 (Emerald Blossom)

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_evo_emerald_blossom_heal';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(355916, 'spell_evo_emerald_blossom_heal');
