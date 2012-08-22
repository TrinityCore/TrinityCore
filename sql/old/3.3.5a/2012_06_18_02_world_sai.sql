-- Fix quest 11895 "Master the Storm"
-- Storm Totem SAI
SET @ENTRY  := 26048;
UPDATE `creature_template` SET `npcflag`=`npcflag`&~16777216,`AIName`= 'SmartAI',`ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,81,16777216,0,0,0,0,0,1,0,0,0,0,0,0,0,'Storm Totem - On spawn - set npcflag'),
(@ENTRY,0,1,2,73,0,100,0,0,0,0,0,12,26045,2,300000,0,0,0,8,0,0,0,3403.829,4133.074,18.13754,5.759586,'Storm Totem - On Spellclick - Spawn Storm Tempest'),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Storm Totem - On spawn - remove npcflag');
-- Storm Tempest SAI
SET @ENTRY  := 26045;
UPDATE `creature_template` SET `unit_flags`=0,`AIName`= 'SmartAI',`ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=26045;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,63,0,100,0,0,0,0,0,11,8609,2,0,0,0,0,1,0,0,0,0,0,0,0,'Storm Totem - On spawn - cast aura'),
(@ENTRY,0,1,0,1,0,100,1,1000,1000,1000,1000,12,23837,2,120000,0,0,0,8,0,0,0,3403.871,4133.031,18.13754,5.67232,'Storm Totem - OOC - Spawn ELM General Purpose Bunny'),
(@ENTRY,0,2,0,60,0,100,1,1000,1000,7000,8000,11,40136,2,0,0,0,0,19,23837,5,0,0,0,0,0,'Storm Totem - Update Event - cast aura'),
(@ENTRY,0,3,4,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,'Storm Totem - On Aggro - Say 0'),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Storm Totem - On Aggro - Prevent combat movement'),
(@ENTRY,0,5,0,0,0,100,0,0,30,6000,7500,11,15659,0,0,0,0,0,2,0,0,0,0,0,0,0,'Storm Totem - Combat - Cast Chain Lightning'),
(@ENTRY,0,6,0,0,0,100,0,8000,11000,9000,14000,11,31272,0,0,0,0,0,2,0,0,0,0,0,0,0,'Storm Totem - Combat - Cast Wind Shock'),
(@ENTRY,0,7,8,6,0,100,0,0,0,0,0,51,0,0,0,0,0,0,9,23837,0,10,0,0,0,0,'Storm Totem - On death - despawn trigger'),
(@ENTRY,0,8,9,61,0,100,0,0,0,0,0,81,16777216,0,0,0,0,0,19,26048,10,0,0,0,0,0,'Storm Totem - On death - set npc flags on totem'),
(@ENTRY,0,9,0,61,0,100,0,0,0,0,0,85,46424,2,0,0,0,0,16,0,0,0,0,0,0,0,'Storm Totem - Combat - Cast Power of the Storm');
-- Sage Earth and Sky SAI
SET @ENTRY  := 25982;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,20,0,100,0,11895,0,0,0,28,46424,0,0,0,0,0,7,0,0,0,0,0,0,0,'Sage Earth and Sky - On Quest reward - remove aura from player');
-- NPC talk text insert from sniff
DELETE FROM `creature_text` WHERE `entry`=26045;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(26045,0,0, 'You will not master me, puny $r!',12,0,100,0,0,0, 'Storm Tempest');
-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=26048;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,2,26048,0,0,9,0,11895,0,0,0,0, '', 'Storm Totem - Allow sai action only if quest has been taken'),
(22,2,26048,0,0,28,0,11895,0,0,1,0, '', 'Storm Totem - Allow sai action only if quest has not been completed');
