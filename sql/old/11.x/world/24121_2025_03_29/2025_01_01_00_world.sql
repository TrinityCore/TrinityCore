DELETE FROM `spell_script_names` WHERE `spell_id` = 267211;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(267211, 'spell_warl_bilescourge_bombers');

DELETE FROM `areatrigger_create_properties` WHERE (`IsCustom`=0 AND `Id` IN (13045,15141));
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTarget`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `VerifiedBuild`) VALUES
(13045, 0, 17676, 0, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 5760, 4, 8, 8, 10, 10, 0.300000011920928955, 0.300000011920928955, 0, 0, 58238), -- Spell: 267211 (Bilescourge Bombers)
(15141, 0, 19764, 0, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 5760, 0, 1, 1, 0, 0, 0, 0, 0, 0, 58238); -- Spell: 282248 (Bilescourge Bombers)

DELETE FROM `areatrigger_template` WHERE (`IsCustom`=0 AND `Id` IN (17676, 19764));
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES
(17676, 0, 0, 58238),
(19764, 0, 0, 58238);

UPDATE `areatrigger_create_properties` SET `ScriptName`='at_warl_bilescourge_bombers' WHERE `Id`=15141 AND `IsCustom`=0;
