-- Add missing spells to spell_dbc
DELETE FROM `spell_dbc` WHERE `Id` IN (24211,24246,24235,7939);
INSERT INTO `spell_dbc` (`Id`,`SchoolMask`,`Dispel`,`Mechanic`,`Attributes`,`AttributesEx`,`AttributesEx2`,`AttributesEx3`,`AttributesEx4`,`Stances`,`StancesNot`,`Targets`,`CastingTimeIndex`,`AuraInterruptFlags`,`ProcFlags`,`ProcChance`,`ProcCharges`,`MaxLevel`,`BaseLevel`,`SpellLevel`,`DurationIndex`,`RangeIndex`,`StackAmount`,`EquippedItemClass`,`EquippedItemSubClassMask`,`EquippedItemInventoryTypeMask`,`Effect1`,`Effect2`,`Effect3`,`EffectDieSides1`,`EffectDieSides2`,`EffectDieSides3`,`EffectRealPointsPerLevel1`,`EffectRealPointsPerLevel2`,`EffectRealPointsPerLevel3`,`EffectBasePoints1`,`EffectBasePoints2`,`EffectBasePoints3`,`EffectMechanic1`,`EffectMechanic2`,`EffectMechanic3`,`EffectImplicitTargetA1`,`EffectImplicitTargetA2`,`EffectImplicitTargetA3`,`EffectImplicitTargetB1`,`EffectImplicitTargetB2`,`EffectImplicitTargetB3`,`EffectRadiusIndex1`,`EffectRadiusIndex2`,`EffectRadiusIndex3`,`EffectApplyAuraName1`,`EffectApplyAuraName2`,`EffectApplyAuraName3`,`EffectAmplitude1`,`EffectAmplitude2`,`EffectAmplitude3`,`EffectMultipleValue1`,`EffectMultipleValue2`,`EffectMultipleValue3`,`EffectMiscValue1`,`EffectMiscValue2`,`EffectMiscValue3`,`EffectTriggerSpell1`,`EffectTriggerSpell2`,`EffectTriggerSpell3`,`Comment`,`MaxTargetLevel`,`SpellFamilyName`,`SpellFamilyFlags1`,`SpellFamilyFlags2`,`MaxAffectedTargets`,`DmgClass`,`PreventionType`,`DmgMultiplier1`,`DmgMultiplier2`,`DmgMultiplier3`,`EffectMiscValueB1`) VALUES
(24211,0,0,0,256,0,4,0,0,0,0,0,1,0,0,101,0,0,0,0,0,0,0,-1,0,0,63,0,0,1,0,0,0,0,0,4999,0,0,0,0,0,22,0,0,0,0,0,7,0,0,18,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'Mark of Arlokk',0,0,0,0,0,0,0,1,0,0,0),
(24246,0,0,0,256,0,0,0,0,0,0,0,1,0,0,101,0,0,0,0,6,0,0,-1,0,0,28,0,0,1,0,0,0,0,0,0,0,0,0,0,0,18,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,15101,0,0,0,0,0,'Summon Zulian Prowler',0,0,0,0,0,0,0,1,0,0,64),
(24235,0,0,0,272,268435456,0,0,0,0,0,0,1,0,0,101,0,0,0,0,1,0,0,-1,0,0,6,0,0,0,0,0,0,0,0,9999,0,0,0,0,0,1,0,0,0,0,0,0,0,0,18,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'Super Invis',0,0,0,0,0,0,0,1,1,1,0),
(7939,0,5,0,402915728,268435456,0,0,0,0,0,0,1,6147,0,101,0,0,1,1,21,1,0,-1,-1,0,6,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 'Sneak Rank 1',0,0,0,0,0,0,0,-1,1,1,0);

-- Add script name to Zulian Prowler
UPDATE `creature_template` SET `AIName` = '', `ScriptName`='npc_zulian_prowler' WHERE `entry`=15101;

-- Remove SmartAI
DELETE FROM `smart_scripts` WHERE `entryorguid`=15101;

-- Add condition for Mark of Arlokk
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=24211;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,24211,0,0,0,31,3,15101,0,0,0,0, '', 'Mark of Arlokk - Targets Zulian Prowler');
