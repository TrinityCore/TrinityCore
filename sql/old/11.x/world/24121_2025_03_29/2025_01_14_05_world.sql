DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_dh_inner_demon';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(162264, 'spell_dh_inner_demon');

DELETE FROM `spell_proc` WHERE `SpellId` IN (390145);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(390145,0x00,107,0x00000000,0x00300000,0x00000000,0x00000000,0x0,0x0,0x4,0x2,0x0,0x0,0x0,0,0,0,0); -- Inner Demon

DELETE FROM `areatrigger_create_properties` WHERE (`IsCustom`=0 AND `Id` = 26749);
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(26749, 0, 30886, 0, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 1250, 10.4, 0, 3, 3, 0, 0, 0, 0, 0, 0, 'at_dh_inner_demon', 58187); -- Spell: 390139 (Inner Demon)

DELETE FROM `areatrigger_template` WHERE (`IsCustom`=0 AND `Id` = 30886);
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES
(30886, 0, 0, 58187);
