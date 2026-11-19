DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dh_shattered_souls_havoc_trigger_lesser','spell_dh_shattered_souls_vengeance','spell_dh_shattered_souls_vengeance_trigger','spell_dh_shattered_souls_vengeance_trigger_lesser','spell_dh_consume_soul_vengeance_lesser','spell_dh_soul_fragments_damage_taken_tracker');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(228533, 'spell_dh_shattered_souls_havoc_trigger_lesser'),
(237867, 'spell_dh_shattered_souls_havoc_trigger_lesser'),
(204254, 'spell_dh_shattered_souls_vengeance'),
(210038, 'spell_dh_shattered_souls_vengeance_trigger'),
(209980, 'spell_dh_shattered_souls_vengeance_trigger_lesser'),
(209981, 'spell_dh_shattered_souls_vengeance_trigger_lesser'),
(203794, 'spell_dh_consume_soul_vengeance_lesser'),
(210788, 'spell_dh_soul_fragments_damage_taken_tracker');

DELETE FROM `areatrigger_create_properties` WHERE (`IsCustom`=0 AND `Id` IN (8867,5977,6710,6711));
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(8867, 0, 12929, 0, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 30000, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 'at_dh_shattered_souls_havoc_lesser', 64270), -- Spell: 228537 (Shattered Souls)
(5977, 0, 10665, 0, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 20000, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 'at_dh_shattered_souls_vengeance_lesser', 64270), -- Spell: 204255 (Soul Fragment)
(6710, 0, 11266, 0, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 20000, 0, 0, 4, 6, 0, 0, 0, 0, 0, 0, 'at_dh_shattered_souls_vengeance_shattered', 64270), -- Spell: 203795 (Soul Fragment)
(6711, 0, 10693, 0, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 20000, 0, 0, 6, 6, 0, 0, 0, 0, 0, 0, 'at_dh_shattered_souls_vengeance_demon', 64270); -- Spell: 209788 (Shattered Souls)

UPDATE `areatrigger_template` SET `ActionSetFlags`=1,`VerifiedBuild`=64270 WHERE `Id` IN (12929,10665,11266,10693) AND `IsCustom`=0;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=28 AND `SourceGroup` IN (12929,10665,11266,10693) AND `SourceEntry`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(28, 12929, 0, 0, 0, 1, 0, 221461, 0, 0, '', 1, 0, 0, '', 'Only trigger Consume Soul without aura 221461'),
(28, 10665, 0, 0, 0, 1, 0, 221461, 0, 0, '', 1, 0, 0, '', 'Only trigger Consume Soul without aura 221461'),
(28, 11266, 0, 0, 0, 1, 0, 221461, 0, 0, '', 1, 0, 0, '', 'Only trigger Consume Soul without aura 221461'),
(28, 10693, 0, 0, 0, 1, 0, 221461, 0, 0, '', 1, 0, 0, '', 'Only trigger Consume Soul without aura 221461');

DELETE FROM `spell_proc` WHERE `SpellId` IN (210788);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(210788,0x00,0,0x00000000,0x00000000,0x00000000,0x00000000,0x100000,0x0,0x0,0x2,0x0,0x0,0x0,0,100,0,0); -- Soul Fragments
