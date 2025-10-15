DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dh_shattered_souls', 'spell_dh_shattered_souls_trigger');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(178940, 'spell_dh_shattered_souls'),
(209651, 'spell_dh_shattered_souls_trigger');

DELETE FROM `areatrigger_create_properties` WHERE (`IsCustom`=0 AND `Id` IN (3680, 6659));
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(3680, 0, 8352, 0, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 30000, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 'at_dh_shattered_souls_shattered', 60822), -- Spell: 209693 (Shattered Souls)
(6659, 0, 11231, 0, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 30000, 0, 0, 10, 10, 0, 0, 0, 0, 0, 0, 'at_dh_shattered_souls_demon', 60822); -- Spell: 209788 (Shattered Souls)

UPDATE `areatrigger_template` SET `VerifiedBuild`=60822 WHERE (`Id`=11231 AND `IsCustom`=0);
UPDATE `areatrigger_template` SET `VerifiedBuild`=60822 WHERE (`Id`=8352 AND `IsCustom`=0);
