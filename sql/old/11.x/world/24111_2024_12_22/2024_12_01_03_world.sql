UPDATE `areatrigger_template` SET `VerifiedBuild`=57689 WHERE (`Id`=11203 AND `IsCustom`=0);

DELETE FROM `areatrigger_create_properties` WHERE (`Id`=6615 AND `IsCustom`=0);
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTarget`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(6615, 0, 11203, 0, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 8000, 0, 8, 8, 0, 0, 0, 0, 0, 0, 'areatrigger_dh_darkness', 57689); -- Spell: 196718 (Darkness)

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_dh_darkness';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(209426, 'spell_dh_darkness');
