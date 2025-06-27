-- Sapta Sight
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (8202,8898,8899);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,4,8202,0,0,31,0,5,101749,0,0,0,0,"","Group 0: Spell 'Sapta Sight' (Effect 2) targets object 'Shaman Shrine'"),
(13,4,8202,0,1,31,0,5,100028,0,0,0,0,"","Group 1: Spell 'Sapta Sight' (Effect 2) targets object 'Shaman Shrine'"),
(13,4,8898,0,0,31,0,5,101748,0,0,0,0,"","Group 0: Spell 'Sapta Sight' (Effect 2) targets object 'Shaman Shrine'"),
(13,4,8899,0,0,31,0,5,101750,0,0,0,0,"","Group 0: Spell 'Sapta Sight' (Effect 2) targets object 'Shaman Shrine'");

-- Anuniaq's Net
DELETE FROM `spell_scripts` WHERE `id` = 21014;

DELETE FROM `spell_script_names` WHERE `spell_id` = 21014 AND `ScriptName` = 'spell_the_way_to_his_heart_anuniaq_net';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(21014,'spell_the_way_to_his_heart_anuniaq_net');

DELETE FROM `spell_dbc` WHERE `Id` = 20713;
INSERT INTO `spell_dbc` (`Id`, `Dispel`, `Mechanic`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `AttributesEx7`, `Stances`, `StancesNot`, `Targets`, `CastingTimeIndex`, `AuraInterruptFlags`, `ProcFlags`, `ProcChance`, `ProcCharges`, `MaxLevel`, `BaseLevel`, `SpellLevel`, `DurationIndex`, `RangeIndex`, `StackAmount`, `EquippedItemClass`, `EquippedItemSubClassMask`, `EquippedItemInventoryTypeMask`, `Effect1`, `Effect2`, `Effect3`, `EffectDieSides1`, `EffectDieSides2`, `EffectDieSides3`, `EffectRealPointsPerLevel1`, `EffectRealPointsPerLevel2`, `EffectRealPointsPerLevel3`, `EffectBasePoints1`, `EffectBasePoints2`, `EffectBasePoints3`, `EffectMechanic1`, `EffectMechanic2`, `EffectMechanic3`, `EffectImplicitTargetA1`, `EffectImplicitTargetA2`, `EffectImplicitTargetA3`, `EffectImplicitTargetB1`, `EffectImplicitTargetB2`, `EffectImplicitTargetB3`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectRadiusIndex3`, `EffectApplyAuraName1`, `EffectApplyAuraName2`, `EffectApplyAuraName3`, `EffectAmplitude1`, `EffectAmplitude2`, `EffectAmplitude3`, `EffectMultipleValue1`, `EffectMultipleValue2`, `EffectMultipleValue3`, `EffectItemType1`, `EffectItemType2`, `EffectItemType3`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectMiscValue3`, `EffectMiscValueB1`, `EffectMiscValueB2`, `EffectMiscValueB3`, `EffectTriggerSpell1`, `EffectTriggerSpell2`, `EffectTriggerSpell3`, `EffectSpellClassMaskA1`, `EffectSpellClassMaskA2`, `EffectSpellClassMaskA3`, `EffectSpellClassMaskB1`, `EffectSpellClassMaskB2`, `EffectSpellClassMaskB3`, `EffectSpellClassMaskC1`, `EffectSpellClassMaskC2`, `EffectSpellClassMaskC3`, `SpellName`, `MaxTargetLevel`, `SpellFamilyName`, `SpellFamilyFlags1`, `SpellFamilyFlags2`, `SpellFamilyFlags3`, `MaxAffectedTargets`, `DmgClass`, `PreventionType`, `DmgMultiplier1`, `DmgMultiplier2`, `DmgMultiplier3`, `AreaGroupId`, `SchoolMask`) VALUES
(20713,0,0,384,0,0,0,0,0,0,0,0,0,0,1,0,0,101,0,0,0,0,4,12,0,-1,0,0,28,0,0,0,0,0,0,0,0,0,0,0,0,0,0,40,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,24637,0,0,64,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'The Way to His Heart...: Fished up Reef Shark',0,0,0,0,0,0,0,0,1,0,0,0,1);
-- 'Empty' spell first was added from MoP(?), then was filled with TBC(?) data
-- In some cases it failed because spell was reused (as result this is 3.3.5 spell but with old TBC data)
-- Count 3 - 5 (sniff & video)
UPDATE `spell_dbc` SET `SpellLevel`=0, `EquippedItemSubClassMask`=0, `Effect1`=24, `EffectDieSides1`=3, `EffectBasePoints1`=2, `EffectApplyAuraName1`=0, `EffectItemType1`=34127, `EffectMiscValue1`=0, `SpellFamilyName`=0 WHERE `Id`=12602;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 20713;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,20713,0,0,31,0,5,186949,0,0,0,0,"","Group 0: Spell 'The Way to His Heart...: Fished up Reef Shark' (Effect 0) targets object 'School of Tasty Reef Fish'");

UPDATE `creature_loot_template` SET `Chance` = 20 WHERE `Entry` = 24637 AND `Item` = 34127 AND `Reference` = 0;

-- Light Lamp
UPDATE `gameobject` SET `state` = 1 WHERE `id` = 192068;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (60535,54047);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,60535,0,0,31,0,5,191440,0,0,0,0,"","Group 0: Spell 'Light Lamp' (Effect 0) targets object 'Lamp Post'"),
(13,1,60535,0,1,31,0,5,191444,0,0,0,0,"","Group 1: Spell 'Light Lamp' (Effect 0) targets object 'Lamp Post'"),
(13,1,60535,0,2,31,0,5,191445,0,0,0,0,"","Group 2: Spell 'Light Lamp' (Effect 0) targets object 'Lamp Post'"),
(13,1,60535,0,3,31,0,5,191665,0,0,0,0,"","Group 3: Spell 'Light Lamp' (Effect 0) targets object 'Lamp Post'"),
(13,1,60535,0,4,31,0,5,192067,0,0,0,0,"","Group 4: Spell 'Light Lamp' (Effect 0) targets object 'Lamp Post'"),
(13,1,60535,0,5,31,0,5,192068,0,0,0,0,"","Group 5: Spell 'Light Lamp' (Effect 0) targets object 'Lamp Post'"),
(13,1,60535,0,6,31,0,5,192069,0,0,0,0,"","Group 6: Spell 'Light Lamp' (Effect 0) targets object 'Lamp Post'"),
(13,1,60535,0,7,31,0,5,192070,0,0,0,0,"","Group 7: Spell 'Light Lamp' (Effect 0) targets object 'Lamp Post'"),
(13,1,60535,0,8,31,0,5,192083,0,0,0,0,"","Group 8: Spell 'Light Lamp' (Effect 0) targets object 'Lamp Post'"),
(13,1,60535,0,9,31,0,5,192084,0,0,0,0,"","Group 9: Spell 'Light Lamp' (Effect 0) targets object 'Lamp Post'"),
(13,1,60535,0,10,31,0,5,192085,0,0,0,0,"","Group 10: Spell 'Light Lamp' (Effect 0) targets object 'Lamp Post'"),
(13,1,60535,0,11,31,0,5,192086,0,0,0,0,"","Group 11: Spell 'Light Lamp' (Effect 0) targets object 'Lamp Post'"),
(13,1,60535,0,12,31,0,5,192087,0,0,0,0,"","Group 12: Spell 'Light Lamp' (Effect 0) targets object 'Lamp Post'"),
(13,1,60535,0,13,31,0,5,192088,0,0,0,0,"","Group 13: Spell 'Light Lamp' (Effect 0) targets object 'Lamp Post'"),
(13,1,60535,0,14,31,0,5,192089,0,0,0,0,"","Group 14: Spell 'Light Lamp' (Effect 0) targets object 'Lamp Post'"),
(13,1,60535,0,15,31,0,5,192116,0,0,0,0,"","Group 15: Spell 'Light Lamp' (Effect 0) targets object 'Lamp Post'"),
(13,1,60535,0,16,31,0,5,192117,0,0,0,0,"","Group 16: Spell 'Light Lamp' (Effect 0) targets object 'Lamp Post'"),
(13,1,60535,0,17,31,0,5,192119,0,0,0,0,"","Group 17: Spell 'Light Lamp' (Effect 0) targets object 'Lamp Post'"),
(13,1,60535,0,18,31,0,5,192850,0,0,0,0,"","Group 18: Spell 'Light Lamp' (Effect 0) targets object 'Lamp Post'"),
(13,1,60535,0,19,31,0,5,192852,0,0,0,0,"","Group 19: Spell 'Light Lamp' (Effect 0) targets object 'Lamp Post'"),
(13,1,60535,0,20,31,0,5,192853,0,0,0,0,"","Group 20: Spell 'Light Lamp' (Effect 0) targets object 'Lamp Post'"),
(13,1,60535,0,21,31,0,5,192854,0,0,0,0,"","Group 21: Spell 'Light Lamp' (Effect 0) targets object 'Lamp Post'"),
(13,1,54047,0,0,31,0,5,191440,0,0,0,0,"","Group 0: Spell 'Light Lamp' (Effect 0) targets object 'Lamp Post'"),
(13,1,54047,0,1,31,0,5,191444,0,0,0,0,"","Group 1: Spell 'Light Lamp' (Effect 0) targets object 'Lamp Post'"),
(13,1,54047,0,2,31,0,5,191445,0,0,0,0,"","Group 2: Spell 'Light Lamp' (Effect 0) targets object 'Lamp Post'"),
(13,1,54047,0,3,31,0,5,191665,0,0,0,0,"","Group 3: Spell 'Light Lamp' (Effect 0) targets object 'Lamp Post'"),
(13,1,54047,0,4,31,0,5,192067,0,0,0,0,"","Group 4: Spell 'Light Lamp' (Effect 0) targets object 'Lamp Post'"),
(13,1,54047,0,5,31,0,5,192068,0,0,0,0,"","Group 5: Spell 'Light Lamp' (Effect 0) targets object 'Lamp Post'"),
(13,1,54047,0,6,31,0,5,192069,0,0,0,0,"","Group 6: Spell 'Light Lamp' (Effect 0) targets object 'Lamp Post'"),
(13,1,54047,0,7,31,0,5,192070,0,0,0,0,"","Group 7: Spell 'Light Lamp' (Effect 0) targets object 'Lamp Post'"),
(13,1,54047,0,8,31,0,5,192083,0,0,0,0,"","Group 8: Spell 'Light Lamp' (Effect 0) targets object 'Lamp Post'"),
(13,1,54047,0,9,31,0,5,192084,0,0,0,0,"","Group 9: Spell 'Light Lamp' (Effect 0) targets object 'Lamp Post'"),
(13,1,54047,0,10,31,0,5,192085,0,0,0,0,"","Group 10: Spell 'Light Lamp' (Effect 0) targets object 'Lamp Post'"),
(13,1,54047,0,11,31,0,5,192086,0,0,0,0,"","Group 11: Spell 'Light Lamp' (Effect 0) targets object 'Lamp Post'"),
(13,1,54047,0,12,31,0,5,192087,0,0,0,0,"","Group 12: Spell 'Light Lamp' (Effect 0) targets object 'Lamp Post'"),
(13,1,54047,0,13,31,0,5,192088,0,0,0,0,"","Group 13: Spell 'Light Lamp' (Effect 0) targets object 'Lamp Post'"),
(13,1,54047,0,14,31,0,5,192089,0,0,0,0,"","Group 14: Spell 'Light Lamp' (Effect 0) targets object 'Lamp Post'"),
(13,1,54047,0,15,31,0,5,192116,0,0,0,0,"","Group 15: Spell 'Light Lamp' (Effect 0) targets object 'Lamp Post'"),
(13,1,54047,0,16,31,0,5,192117,0,0,0,0,"","Group 16: Spell 'Light Lamp' (Effect 0) targets object 'Lamp Post'"),
(13,1,54047,0,17,31,0,5,192119,0,0,0,0,"","Group 17: Spell 'Light Lamp' (Effect 0) targets object 'Lamp Post'"),
(13,1,54047,0,18,31,0,5,192850,0,0,0,0,"","Group 18: Spell 'Light Lamp' (Effect 0) targets object 'Lamp Post'"),
(13,1,54047,0,19,31,0,5,192852,0,0,0,0,"","Group 19: Spell 'Light Lamp' (Effect 0) targets object 'Lamp Post'"),
(13,1,54047,0,20,31,0,5,192853,0,0,0,0,"","Group 20: Spell 'Light Lamp' (Effect 0) targets object 'Lamp Post'"),
(13,1,54047,0,21,31,0,5,192854,0,0,0,0,"","Group 21: Spell 'Light Lamp' (Effect 0) targets object 'Lamp Post'");

UPDATE `smart_scripts` SET `action_param1` = 54047 WHERE `entryorguid` = 2926100 AND `source_type` = 9 AND `action_type` = 11;

-- Power Feedback
DELETE FROM `spelldifficulty_dbc` WHERE `id` IN (44233);
INSERT INTO `spelldifficulty_dbc` (`id`, `spellid0`, `spellid1`, `spellid2`, `spellid3`) VALUES
(44233,44233,47109,0,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (44233,47109);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,4,44233,0,0,31,0,5,188165,0,0,0,0,"","Group 0: Spell 'Power Feedback' (Effect 2) targets object 'Doodad_Kael_Explode_FX_Left01'"),
(13,4,44233,0,1,31,0,5,188166,0,0,0,0,"","Group 1: Spell 'Power Feedback' (Effect 2) targets object 'Doodad_Kael_Explode_FX_Right01'"),
(13,4,47109,0,0,31,0,5,188165,0,0,0,0,"","Group 0: Spell 'Power Feedback' (Effect 2) targets object 'Doodad_Kael_Explode_FX_Left01'"),
(13,4,47109,0,1,31,0,5,188166,0,0,0,0,"","Group 1: Spell 'Power Feedback' (Effect 2) targets object 'Doodad_Kael_Explode_FX_Right01'");
