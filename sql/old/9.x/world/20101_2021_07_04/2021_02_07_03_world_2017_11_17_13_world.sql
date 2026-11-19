DELETE FROM `spell_script_names` WhERE `ScriptName` IN
('spell_midsummer_torch_target_picker',
'spell_midsummer_torch_toss_land',
'spell_midsummer_test_ribbon_pole_channel',
'spell_gen_ribbon_pole_dancer_check',
'spell_midsummer_ribbon_pole_periodic_visual');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(45907,'spell_midsummer_torch_target_picker'),
(46054,'spell_midsummer_torch_toss_land'),
(29705,'spell_midsummer_test_ribbon_pole_channel'),
(29726,'spell_midsummer_test_ribbon_pole_channel'),
(29727,'spell_midsummer_test_ribbon_pole_channel'),
(45406,'spell_midsummer_ribbon_pole_periodic_visual');

-- UPDATE `spell_dbc` SET `Effect1`=3, `EffectImplicitTargetA1`=1 WHERE `Id`=58934;
DELETE FROM `spelleffect_dbc` WHERE `Id`=155919;
INSERT INTO `spelleffect_dbc` (`Id`, `Effect`, `EffectValueMultiplier`, `EffectApplyAuraName`, `EffectAmplitude`, `EffectBasePoints`, `EffectBonusMultiplier`, `EffectDamageMultiplier`, `EffectChainTarget`, `EffectDieSides`, `EffectItemType`, `EffectMechanic`, `EffectMiscValue`, `EffectMiscValueB`, `EffectRadiusIndex`, `EffectRadiusIndexMax`, `EffectRealPointsPerLevel`, `EffectSpellClassMaskA`, `EffectSpellClassMaskB`, `EffectSpellClassMaskC`, `EffectTriggerSpell`, `EffectImplicitTargetA`, `EffectImplicitTargetB`, `EffectSpellId`, `EffectIndex`) VALUES
(155919, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 58934, 0);

UPDATE `creature_template` SET `AIName`='' WHERE `entry`=25535;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=25535;

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=29726;
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=45723 AND `spell_effect`=43313;
DELETE FROM `disables` WHERE `sourceType`=0 AND `entry` IN(45724);
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES
(0,45724,64,0,0,'Disable LoS for spell Braziers Hit');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (45907,46054,45732,29705,29727);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition` ,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,45907,0,0,31,0,3,25535,0,0,0,'','Spell \'Torch Target Picker\' targets [DNT] Torch Tossing Target Bunny'),
(13,1,45907,0,0,1,0,45723,0,0,1,0,'','Spell \'Torch Target Picker\' can not hit targets with Aura \'Target Indicator (Rank 1)\''),
(13,1,45732,0,0,1,0,45723,0,0,0,0,'','Spell \'Torch Toss\' can only hit targets with Aura \'Target Indicator\''),
(13,1,46054,0,0,1,0,45723,0,0,0,0,'','Spell \'Torch Toss\' can only hit targets with Aura \'Target Indicator\''),
(13,1,46054,0,0,31,0,3,25535,0,0,0,'','Spell \'Torch Target Picker\' targets [DNT] Torch Tossing Target Bunny'),
(13,1,45732,0,0,31,0,3,25535,0,0,0,'','Spell \'Torch Target Picker\' targets [DNT] Torch Tossing Target Bunny'),
(13,1,29705,0,0,31,0,3,17066,0,0,0,'','Spell \'Test Ribbon Pole Channel\' targets Ribbon Pole Debug Target'),
(13,1,29727,0,0,31,0,3,17066,0,0,0,'','Spell \'Test Ribbon Pole Channel\' targets Ribbon Pole Debug Target');
