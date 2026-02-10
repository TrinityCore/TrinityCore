DELETE FROM `areatrigger_create_properties` WHERE (`IsCustom`=0 AND `Id` IN (36671));
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(36671, 0, 38618, 0, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 20000, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 'at_dh_shattered_souls_devourer', 65727); -- Spell: 1223412 (Soul Fragment)

DELETE FROM `areatrigger_template` WHERE (`IsCustom`=0 AND `Id` IN (38618));
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `VerifiedBuild`) VALUES
(38618, 0, 65727);

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dh_shattered_souls_devourer', 'spell_dh_shattered_souls_devourer_missile', 'spell_dh_shattered_souls_devourer_dummy');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(1227619, 'spell_dh_shattered_souls_devourer'),
(1223445, 'spell_dh_shattered_souls_devourer_missile'),
(1223450, 'spell_dh_shattered_souls_devourer_dummy'),
(1223448, 'spell_dh_shattered_souls_devourer_missile');
