DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dh_shattered_souls_havoc', 'spell_dh_shattered_souls_havoc_trigger');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(178940, 'spell_dh_shattered_souls_havoc'),
(209651, 'spell_dh_shattered_souls_havoc_trigger');

DELETE FROM `areatrigger_create_properties` WHERE (`IsCustom`=0 AND `Id` IN (3680, 6659));
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(3680, 0, 8352, 0, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 30000, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 'at_dh_shattered_souls_havoc_shattered', 60822), -- Spell: 209693 (Shattered Souls)
(6659, 0, 11231, 0, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 30000, 0, 0, 10, 10, 0, 0, 0, 0, 0, 0, 'at_dh_shattered_souls_havoc_demon', 60822); -- Spell: 209788 (Shattered Souls)

UPDATE `areatrigger_template` SET `ActionSetFlags`=1,`VerifiedBuild`=60822 WHERE `Id` IN (8352,11231) AND `IsCustom`=0;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=28 AND `SourceGroup` IN (8352,11231) AND `SourceEntry`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(28,  8352, 0, 0, 0, 1, 0, 221461, 0, 0, '', 1, 0, 0, '', 'Only trigger Consume Soul without aura 221461'),
(28, 11231, 0, 0, 0, 1, 0, 221461, 0, 0, '', 1, 0, 0, '', 'Only trigger Consume Soul without aura 221461');
