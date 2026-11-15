DELETE FROM `areatrigger_create_properties` WHERE (`IsCustom`=0 AND `Id` = 6122);
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(6122, 0, 10801, 0, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 8000, 0, 4, 8, 8, 4, 4, 0.300000011920928955, 0.300000011920928955, 0, 0, 'at_mage_flame_patch', 61559); -- Spell: 205470 (Flame Patch)

UPDATE `areatrigger_template` SET `VerifiedBuild`=61559 WHERE (`Id`=10801 AND `IsCustom`=0);

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_mage_flame_patch';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(2120, 'spell_mage_flame_patch');
