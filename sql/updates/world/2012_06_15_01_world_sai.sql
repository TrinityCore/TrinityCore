-- Fix up quest 9544 "The Prophecy of Akida"
-- Totem of Vark SAI
SET @ENTRY  := 17364;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`='' WHERE `entry`=@ENTRY;
UPDATE `creature_template_addon` SET `bytes2`=1,`auras`='18950' WHERE `entry`=17364;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,9544,0,0,0,85,30453,0,0,0,0,0,7,0,0,0,0,0,0,0,'Totem of Vark - Quest accepted - Cast Spell on player');
-- Stillpine Ancestor Vark SAI
SET @ENTRY  := 17410;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY*100) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,1,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stillpine Ancestor Vark - Just Summoned - Run Script'),
-- Script
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,3,0,17109,0,0,0,0,1,0,0,0,0,0,0,0,'Stillpine Ancestor Vark - Script - set model'),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,0,0,11,25035,0,0,0,0,0,1,0,0,0,0,0,0,0.01745319,'Stillpine Ancestor Vark - Script - Cast Spell'),
(@ENTRY*100,9,2,0,0,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stillpine Ancestor Vark - Script - Set run on'),
(@ENTRY*100,9,3,0,0,0,100,0,2000,2000,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Stillpine Ancestor Vark - Script - turn to player'),
(@ENTRY*100,9,4,0,0,0,100,0,2000,2000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stillpine Ancestor Vark - Script - say 0'),
(@ENTRY*100,9,5,0,0,0,100,0,8000,8000,0,0,11,30428,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stillpine Ancestor Vark - Script - cast spell'),
(@ENTRY*100,9,6,0,0,0,100,0,3000,3000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stillpine Ancestor Vark - Script - despawn');
-- NPC talk text insert from sniff
DELETE FROM `creature_text` WHERE `entry`=17410;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(17410,0,0, '[Furbolg] Bear witness to the savage acts of our adversaries, $N. They steal our young... our weak... Imprisoned here, they are left to the devices of the Bristlelimb. Set them free, Promised One!',12,0,100,0,0,0, 'Stillpine Ancestor Vark');
-- add missing spells to db
DELETE FROM `spell_dbc` WHERE `Id` IN (30453,30454);
INSERT INTO `spell_dbc` (`Id`,`SchoolMask`,`Dispel`,`Mechanic`,`Attributes`,`AttributesEx`,`AttributesEx2`,`AttributesEx3`,`AttributesEx4`,`AttributesEx5`,`Stances`,`StancesNot`,`Targets`,`CastingTimeIndex`,`AuraInterruptFlags`,`ProcFlags`,`ProcChance`,`ProcCharges`,`MaxLevel`,`BaseLevel`,`SpellLevel`,`DurationIndex`,`RangeIndex`,`StackAmount`,`EquippedItemClass`,`EquippedItemSubClassMask`,`EquippedItemInventoryTypeMask`,`Effect1`,`Effect2`,`Effect3`,`EffectDieSides1`,`EffectDieSides2`,`EffectDieSides3`,`EffectRealPointsPerLevel1`,`EffectRealPointsPerLevel2`,`EffectRealPointsPerLevel3`,`EffectBasePoints1`,`EffectBasePoints2`,`EffectBasePoints3`,`EffectMechanic1`,`EffectMechanic2`,`EffectMechanic3`,`EffectImplicitTargetA1`,`EffectImplicitTargetA2`,`EffectImplicitTargetA3`,`EffectImplicitTargetB1`,`EffectImplicitTargetB2`,`EffectImplicitTargetB3`,`EffectRadiusIndex1`,`EffectRadiusIndex2`,`EffectRadiusIndex3`,`EffectApplyAuraName1`,`EffectApplyAuraName2`,`EffectApplyAuraName3`,`EffectAmplitude1`,`EffectAmplitude2`,`EffectAmplitude3`,`EffectMultipleValue1`,`EffectMultipleValue2`,`EffectMultipleValue3`,`EffectMiscValue1`,`EffectMiscValue2`,`EffectMiscValue3`,`EffectTriggerSpell1`,`EffectTriggerSpell2`,`EffectTriggerSpell3`,`Comment`,`MaxTargetLevel`,`SpellFamilyName`,`SpellFamilyFlags1`,`SpellFamilyFlags2`,`MaxAffectedTargets`,`DmgClass`,`PreventionType`,`DmgMultiplier1`,`DmgMultiplier2`,`AreaGroupId`,`EffectMiscValueB1`) VALUES
(30454,0,0,0,256,268435456,0,0,0,0,0,0,0,1,0,0,101,0,0,0,0,40,12,0,-1,0,0,28,6,0,0,0,0,0,0,0,0,0,0,0,0,0,32,1,0,0,0,0,7,0,0,0,4,0,0,0,0,0,0,0,17410,0,0,0,0,0,'Stillpine Ancestor Vark',0,0,0,0,0,0,0,1,1,0,64),
(30453,0,0,0,2304,268435456,0,0,0,0,0,0,0,1,0,0,101,0,0,0,0,36,3,0,-1,0,0,6,0,0,1,0,0,0,0,0,0,0,0,0,0,0,21,0,0,0,0,0,0,0,0,23,0,0,1000,0,0,0,0,0,0,0,0,30454,0,0,'Stillpine Ancestor Vark TRIGGER',0,0,0,0,0,0,0,1,0,0,0);
