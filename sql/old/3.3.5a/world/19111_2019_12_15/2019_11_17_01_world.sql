-- 
UPDATE `smart_scripts` SET `target_type`=12, `target_param1`=1 WHERE  `entryorguid`=2453901 AND `source_type`=9 AND `id`=0 AND `link`=0;
UPDATE `smart_scripts` SET `target_type`=12, `target_param1`=1 WHERE  `entryorguid`=2453901 AND `source_type`=9 AND `id`=1 AND `link`=0;
UPDATE `smart_scripts` SET `link`=9, `action_type`=72, `action_param1`=0, `target_type`=7 WHERE  `entryorguid`=24539 AND `source_type`=0 AND `id`=6;
UPDATE `smart_scripts` SET `event_param3`=2000, `event_param4`=2000, `action_param3`=1 WHERE  `entryorguid`=24539 AND `source_type`=0 AND `id`=4;
UPDATE `smart_scripts` SET `link`=14 WHERE  `entryorguid`=24539 AND `source_type`=0 AND `id`=3;

DELETE FROM `smart_scripts` WHERE `entryorguid`=2453900 AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2453901 AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`=24539 AND `source_type`=0 AND `id`>8;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(24539, 0, 9, 10, 61, 0, 100, 0, 0, 0, 0, 0, 0, 134, 44421, 2, 0, 0, 0, 0,7, 0, 0, 0, 0, 0, 0, 0, 0, 'Silvermoon Harry - On Gossip Select - Cast Harry\'s Debt'),
(24539, 0, 10, 11, 61, 0, 100, 0, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Silvermoon Harry - On Gossip Select - Set event phase 0'),
(24539, 0, 11, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 102, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Silvermoon Harry - On Gossip Select - Turn HP Regen on'),
(24539, 0, 12, 13, 7, 0, 100, 0, 0, 0, 0, 0, 0, 2, 1888, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Silvermoon Harry - On Evade - Set Faction 1888'),
(24539, 0, 13, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 71, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Silvermoon Harry - On Gossip Select - Remove Equip'),
(24539, 0, 14, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 71, 0, 0, 20977, 20984, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Silvermoon Harry - On Gossip Select - SET Equip'),
(2453900, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 102, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, '\'Silvermoon\' Harry - On Script - Turn HP Regen off'),
(2453900, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, '\'Silvermoon\' Harry - On Script - Say Line 1'),
(2453900, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 2, 1888, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, '\'Silvermoon\' Harry - On Script - Set Faction 1888'),
(2453900, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, '\'Silvermoon\' Harry - On Script - Set event Phase 1'),
(2453900, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, '\'Silvermoon\' Harry - On Script - Evade'),
(2453900, 9, 5, 0, 0, 0, 100, 0, 30000, 30000, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, '\'Silvermoon\' Harry - On Script - Set event Phase 0'),
(2453900, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 102, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, '\'Silvermoon\' Harry - On Script - Turn HP Regen on');

DELETE FROM `spell_dbc` WHERE `Id`=44421;
INSERT INTO `spell_dbc` (`Id`, `Dispel`, `Mechanic`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `AttributesEx7`, `Stances`, `StancesNot`, `Targets`, `CastingTimeIndex`, `AuraInterruptFlags`, `ProcFlags`, `ProcChance`, `ProcCharges`, `MaxLevel`, `BaseLevel`, `SpellLevel`, `DurationIndex`, `RangeIndex`, `StackAmount`, `EquippedItemClass`, `EquippedItemSubClassMask`, `EquippedItemInventoryTypeMask`, `Effect1`, `Effect2`, `Effect3`, `EffectDieSides1`, `EffectDieSides2`, `EffectDieSides3`, `EffectRealPointsPerLevel1`, `EffectRealPointsPerLevel2`, `EffectRealPointsPerLevel3`, `EffectBasePoints1`, `EffectBasePoints2`, `EffectBasePoints3`, `EffectMechanic1`, `EffectMechanic2`, `EffectMechanic3`, `EffectImplicitTargetA1`, `EffectImplicitTargetA2`, `EffectImplicitTargetA3`, `EffectImplicitTargetB1`, `EffectImplicitTargetB2`, `EffectImplicitTargetB3`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectRadiusIndex3`, `EffectApplyAuraName1`, `EffectApplyAuraName2`, `EffectApplyAuraName3`, `EffectAmplitude1`, `EffectAmplitude2`, `EffectAmplitude3`, `EffectMultipleValue1`, `EffectMultipleValue2`, `EffectMultipleValue3`, `EffectItemType1`, `EffectItemType2`, `EffectItemType3`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectMiscValue3`, `EffectMiscValueB1`, `EffectMiscValueB2`, `EffectMiscValueB3`, `EffectTriggerSpell1`, `EffectTriggerSpell2`, `EffectTriggerSpell3`, `EffectSpellClassMaskA1`, `EffectSpellClassMaskA2`, `EffectSpellClassMaskA3`, `EffectSpellClassMaskB1`, `EffectSpellClassMaskB2`, `EffectSpellClassMaskB3`, `EffectSpellClassMaskC1`, `EffectSpellClassMaskC2`, `EffectSpellClassMaskC3`, `MaxTargetLevel`, `SpellFamilyName`, `SpellFamilyFlags1`, `SpellFamilyFlags2`, `SpellFamilyFlags3`, `MaxAffectedTargets`, `DmgClass`, `PreventionType`, `DmgMultiplier1`, `DmgMultiplier2`, `DmgMultiplier3`, `AreaGroupId`, `SchoolMask`, `SpellName`) VALUES 
(44421, 0, 0, 384, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 101, 0, 0, 0, 0, 0, 7, 0, -1, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34115, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 'Harry\'s Debt');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (9010);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,9010,0,0,9,0,11464,0,0,0,'','Only show second gossip (option 0) if player is on quest Gambling Debt');
