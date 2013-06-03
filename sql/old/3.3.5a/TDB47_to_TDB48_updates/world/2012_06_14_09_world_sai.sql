-- Fix up quest 9539 "Totem of Coo"
-- Totem of Akida SAI
SET @ENTRY  := 17360;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,9539,0,0,0,85,30437,0,0,0,0,0,7,0,0,0,0,0,0,0,'Totem of Akida - Quest accepted - Cast Spell on player');
-- Stillpine Ancestor Akida SAI
SET @ENTRY  := 17379;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY*100) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,1,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stillpine Ancestor Akida - Just Summoned - Run Script'),
-- Script
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,3,0,16995,0,0,0,0,1,0,0,0,0,0,0,0,'Stillpine Ancestor Akida - Script - set model'),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Stillpine Ancestor Akida - Script - turn to player'),
(@ENTRY*100,9,2,0,0,0,100,0,0,0,0,0,11,25035,0,0,0,0,0,1,0,0,0,0,0,0,0.01745319,'Stillpine Ancestor Akida - Script - Cast Spell'),
(@ENTRY*100,9,3,0,0,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stillpine Ancestor Akida - Script - Set run on'),
(@ENTRY*100,9,4,0,0,0,100,0,4000,4000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stillpine Ancestor Akida - Script - say 0'),
(@ENTRY*100,9,5,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,-4154.224,-12514.75,45.35527,0,'Stillpine Ancestor Akida - Script - move to'),
(@ENTRY*100,9,6,0,0,0,100,0,2000,2000,0,0,69,0,0,0,0,0,0,8,0,0,0,-4123.563,-12517.23,44.9127,0,'Stillpine Ancestor Akida - Script - move to'),
(@ENTRY*100,9,7,0,0,0,100,0,3500,3500,0,0,69,0,0,0,0,0,0,8,0,0,0,-4091.881,-12524,42.37354,0,'Stillpine Ancestor Akida - Script - move to'),
(@ENTRY*100,9,8,0,0,0,100,0,5500,5500,0,0,69,0,0,0,0,0,0,8,0,0,0,-4058.039,-12538.57,43.96096,0,'Stillpine Ancestor Akida - Script - move to'),
(@ENTRY*100,9,9,0,0,0,100,0,4500,4500,0,0,69,0,0,0,0,0,0,8,0,0,0,-4026.534,-12568.4,45.82222,0,'Stillpine Ancestor Akida - Script - move to'),
(@ENTRY*100,9,10,0,0,0,100,0,3000,3000,0,0,69,0,0,0,0,0,0,8,0,0,0,-4000.155,-12598.55,54.19722,0,'Stillpine Ancestor Akida - Script - move to'), --
(@ENTRY*100,9,11,0,0,0,100,0,7500,7500,0,0,69,0,0,0,0,0,0,8,0,0,0,-3977.5,-12627.22,63.1442,0,'Stillpine Ancestor Akida - Script - move to'),
(@ENTRY*100,9,12,0,0,0,100,0,3500,3500,0,0,69,0,0,0,0,0,0,8,0,0,0,-3952.254,-12660.37,74.23783,0,'Stillpine Ancestor Akida - Script - move to'),
(@ENTRY*100,9,13,0,0,0,100,0,6500,6500,0,0,69,0,0,0,0,0,0,8,0,0,0,-3933.183,-12698.27,85.65151,0,'Stillpine Ancestor Akida - Script - move to'),
(@ENTRY*100,9,14,0,0,0,100,0,4500,4500,0,0,69,0,0,0,0,0,0,8,0,0,0,-3925.843,-12718.81,89.94553,0,'Stillpine Ancestor Akida - Script - move to'), --
(@ENTRY*100,9,15,0,0,0,100,0,3500,3500,0,0,69,0,0,0,0,0,0,8,0,0,0,-3915.914,-12743.41,98.56779,0,'Stillpine Ancestor Akida - Script - move to'),
(@ENTRY*100,9,16,0,0,0,100,0,4500,4500,0,0,66,0,0,0,0,0,0,19,17361,10,0,0,0,0,0,'Stillpine Ancestor Akida - Script - turn to Totem of Coo'),
(@ENTRY*100,9,17,0,0,0,100,0,2000,2000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stillpine Ancestor Akida - Script - say 1'),
(@ENTRY*100,9,18,0,0,0,100,0,3000,3000,0,0,11,30428,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stillpine Ancestor Akida - Script - cast spell'),
(@ENTRY*100,9,19,0,0,0,100,0,1000,1000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stillpine Ancestor Akida - Script - despawn');
-- NPC talk text insert from sniff
DELETE FROM `creature_text` WHERE `entry`=17379;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(17379,0,0, '%s urges you to follow him.',16,0,100,0,0,0, 'Stillpine Ancestor Akida'),
(17379,1,0, '%s points to the totem of Coo.',16,0,100,25,0,0, 'Stillpine Ancestor Akida');
-- add missing spells to db
DELETE FROM `spell_dbc` WHERE `Id` IN (30426,30437);
INSERT INTO `spell_dbc` (`Id`,`SchoolMask`,`Dispel`,`Mechanic`,`Attributes`,`AttributesEx`,`AttributesEx2`,`AttributesEx3`,`AttributesEx4`,`AttributesEx5`,`Stances`,`StancesNot`,`Targets`,`CastingTimeIndex`,`AuraInterruptFlags`,`ProcFlags`,`ProcChance`,`ProcCharges`,`MaxLevel`,`BaseLevel`,`SpellLevel`,`DurationIndex`,`RangeIndex`,`StackAmount`,`EquippedItemClass`,`EquippedItemSubClassMask`,`EquippedItemInventoryTypeMask`,`Effect1`,`Effect2`,`Effect3`,`EffectDieSides1`,`EffectDieSides2`,`EffectDieSides3`,`EffectRealPointsPerLevel1`,`EffectRealPointsPerLevel2`,`EffectRealPointsPerLevel3`,`EffectBasePoints1`,`EffectBasePoints2`,`EffectBasePoints3`,`EffectMechanic1`,`EffectMechanic2`,`EffectMechanic3`,`EffectImplicitTargetA1`,`EffectImplicitTargetA2`,`EffectImplicitTargetA3`,`EffectImplicitTargetB1`,`EffectImplicitTargetB2`,`EffectImplicitTargetB3`,`EffectRadiusIndex1`,`EffectRadiusIndex2`,`EffectRadiusIndex3`,`EffectApplyAuraName1`,`EffectApplyAuraName2`,`EffectApplyAuraName3`,`EffectAmplitude1`,`EffectAmplitude2`,`EffectAmplitude3`,`EffectMultipleValue1`,`EffectMultipleValue2`,`EffectMultipleValue3`,`EffectMiscValue1`,`EffectMiscValue2`,`EffectMiscValue3`,`EffectTriggerSpell1`,`EffectTriggerSpell2`,`EffectTriggerSpell3`,`Comment`,`MaxTargetLevel`,`SpellFamilyName`,`SpellFamilyFlags1`,`SpellFamilyFlags2`,`MaxAffectedTargets`,`DmgClass`,`PreventionType`,`DmgMultiplier1`,`DmgMultiplier2`,`AreaGroupId`,`EffectMiscValueB1`) VALUES
(30426,0,0,0,256,268435456,0,0,0,0,0,0,0,1,0,0,101,0,0,0,0,40,12,0,-1,0,0,28,6,0,0,0,0,0,0,0,0,0,0,0,0,0,32,1,0,0,0,0,15,0,0,0,4,0,0,0,0,0,0,0,17379,0,0,0,0,0,'Stillpine Ancestor Akida',0,0,0,0,0,0,0,1,1,0,64),
(30437,0,0,0,2304,268435456,0,0,0,0,0,0,0,1,0,0,101,0,0,0,0,36,3,0,-1,0,0,6,0,0,1,0,0,0,0,0,0,0,0,0,0,0,21,0,0,0,0,0,0,0,0,23,0,0,1000,0,0,0,0,0,0,0,0,30426,0,0,'Stillpine Ancestor Akida TRIGGER',0,0,0,0,0,0,0,1,0,0,0);
