-- Fix up quest 9540 "Totem of Tikti"
-- Totem of Coo SAI
SET @ENTRY  := 17361;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,9540,0,0,0,85,30442,0,0,0,0,0,7,0,0,0,0,0,0,0,'Totem of Coo - Quest accepted - Cast Spell on player');
-- Stillpine Ancestor Coo SAI
SET @ENTRY  := 17391;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY*100) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,1,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stillpine Ancestor Coo - Just Summoned - Run Script'),
-- Script
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,3,0,16995,0,0,0,0,1,0,0,0,0,0,0,0,'Stillpine Ancestor Coo - Script - set model'),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Stillpine Ancestor Coo - Script - turn to player'),
(@ENTRY*100,9,2,0,0,0,100,0,0,0,0,0,11,25035,0,0,0,0,0,1,0,0,0,0,0,0,0.01745319,'Stillpine Ancestor Coo - Script - Cast Spell'),
(@ENTRY*100,9,3,0,0,0,100,0,3000,3000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stillpine Ancestor Coo - Script - say 0'),
(@ENTRY*100,9,4,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,-3926.039,-12746.71,96.06779,0,'Stillpine Ancestor Coo - Script - move to'),
(@ENTRY*100,9,5,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,-3926.326,-12753.71,98.44279,0,'Stillpine Ancestor Coo - Script - move to'),
(@ENTRY*100,9,6,0,0,0,100,0,2000,2000,0,0,69,0,0,0,0,0,0,8,0,0,0,-3924.268,-12761.45,101.6928,0,'Stillpine Ancestor Coo - Script - move to'),
(@ENTRY*100,9,7,0,0,0,100,0,6000,6000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stillpine Ancestor Coo - Script - say 1'),
(@ENTRY*100,9,8,0,0,0,100,0,4000,4000,0,0,11,30424,0,0,0,0,0,7,0,0,0,0,0,0,0.01745319,'Stillpine Ancestor Coo - Script - Cast Spell'),
(@ENTRY*100,9,9,0,0,0,100,0,1000,1000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stillpine Ancestor Coo - Script - say 2'),
(@ENTRY*100,9,10,0,0,0,100,0,4000,4000,0,0,11,30473,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stillpine Ancestor Coo - Script - cast spell'),
(@ENTRY*100,9,11,0,0,0,100,0,0,0,0,0,3,0,17019,0,0,0,0,1,0,0,0,0,0,0,0,'Stillpine Ancestor Coo - Script - set model'),
(@ENTRY*100,9,12,0,0,0,100,0,3000,3000,0,0,60,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stillpine Ancestor Coo - Script - Fly on'),
(@ENTRY*100,9,13,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-3926.068,-12767.33,104.3799,0,'Stillpine Ancestor Coo - Script - move to'),
(@ENTRY*100,9,14,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,-3923.497,-12794.98,98.46323,0,'Stillpine Ancestor Coo - Script - move to'),
(@ENTRY*100,9,15,0,0,0,100,0,4000,4000,0,0,69,0,0,0,0,0,0,8,0,0,0,-3922.687,-12832.4,89.24097,0,'Stillpine Ancestor Coo - Script - move to'),
(@ENTRY*100,9,16,0,0,0,100,0,8000,8000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stillpine Ancestor Coo - Script - despawn');
-- NPC talk text insert from sniff
DELETE FROM `creature_text` WHERE `entry`=17391;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(17391,0,0, '%s motions for you to follow him.',16,0,100,0,0,0, 'Stillpine Ancestor Coo'),
(17391,1,0, '[Furbolg] Ritk kin''chikx azul azure summit...',12,0,100,0,0,0, 'Stillpine Ancestor Coo'),
(17391,2,0, '[Furbolg] Coo xip fly... Jump ilos river. Find Tikti.',12,0,100,0,0,0, 'Stillpine Ancestor Coo');
-- add missing spells to db
DELETE FROM `spell_dbc` WHERE `Id` IN (30429,30442);
INSERT INTO `spell_dbc` (`Id`,`SchoolMask`,`Dispel`,`Mechanic`,`Attributes`,`AttributesEx`,`AttributesEx2`,`AttributesEx3`,`AttributesEx4`,`AttributesEx5`,`Stances`,`StancesNot`,`Targets`,`CastingTimeIndex`,`AuraInterruptFlags`,`ProcFlags`,`ProcChance`,`ProcCharges`,`MaxLevel`,`BaseLevel`,`SpellLevel`,`DurationIndex`,`RangeIndex`,`StackAmount`,`EquippedItemClass`,`EquippedItemSubClassMask`,`EquippedItemInventoryTypeMask`,`Effect1`,`Effect2`,`Effect3`,`EffectDieSides1`,`EffectDieSides2`,`EffectDieSides3`,`EffectRealPointsPerLevel1`,`EffectRealPointsPerLevel2`,`EffectRealPointsPerLevel3`,`EffectBasePoints1`,`EffectBasePoints2`,`EffectBasePoints3`,`EffectMechanic1`,`EffectMechanic2`,`EffectMechanic3`,`EffectImplicitTargetA1`,`EffectImplicitTargetA2`,`EffectImplicitTargetA3`,`EffectImplicitTargetB1`,`EffectImplicitTargetB2`,`EffectImplicitTargetB3`,`EffectRadiusIndex1`,`EffectRadiusIndex2`,`EffectRadiusIndex3`,`EffectApplyAuraName1`,`EffectApplyAuraName2`,`EffectApplyAuraName3`,`EffectAmplitude1`,`EffectAmplitude2`,`EffectAmplitude3`,`EffectMultipleValue1`,`EffectMultipleValue2`,`EffectMultipleValue3`,`EffectMiscValue1`,`EffectMiscValue2`,`EffectMiscValue3`,`EffectTriggerSpell1`,`EffectTriggerSpell2`,`EffectTriggerSpell3`,`Comment`,`MaxTargetLevel`,`SpellFamilyName`,`SpellFamilyFlags1`,`SpellFamilyFlags2`,`MaxAffectedTargets`,`DmgClass`,`PreventionType`,`DmgMultiplier1`,`DmgMultiplier2`,`AreaGroupId`,`EffectMiscValueB1`) VALUES
(30429,0,0,0,256,268435456,0,0,0,0,0,0,0,1,0,0,101,0,0,0,0,40,12,0,-1,0,0,28,6,0,0,0,0,0,0,0,0,0,0,0,0,0,32,1,0,0,0,0,7,0,0,0,4,0,0,0,0,0,0,0,17391,0,0,0,0,0,'Stillpine Ancestor Coo',0,0,0,0,0,0,0,1,1,0,64),
(30442,0,0,0,2304,268435456,0,0,0,0,0,0,0,1,0,0,101,0,0,0,0,36,3,0,-1,0,0,6,0,0,1,0,0,0,0,0,0,0,0,0,0,0,21,0,0,0,0,0,0,0,0,23,0,0,1000,0,0,0,0,0,0,0,0,30429,0,0,'Stillpine Ancestor Coo TRIGGER',0,0,0,0,0,0,0,1,0,0,0);
-- Delete bad spawn of Stillpine Ancestor Coo
DELETE FROM `creature` WHERE `guid`=86512;
DELETE FROM `creature_addon` WHERE `guid`=86512;
-- Remove Stillpine Ancestor Akida EAI
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=17391;
