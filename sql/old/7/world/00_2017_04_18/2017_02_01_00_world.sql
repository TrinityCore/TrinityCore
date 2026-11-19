-- Fix level and faction for Laera Dubois
UPDATE `creature_template` SET `minlevel`=25,`maxlevel`=25,`faction`=2163 WHERE `entry`=49963;
-- Random Movement for some misc creatures
UPDATE `creature` SET `spawndist`=5,`MovementType`=1 WHERE `id` IN (2165,2233,32890,32999,34302,34304);
-- Remove permanent aura from Corrupted Duskrat
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=33884;
-- Lor'danel Sentinel should ignore aggro from creatures
UPDATE `creature_template` SET `flags_extra`=2 WHERE `entry`=33115;
-- Script Cast Summon Vile Spray
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=63843;
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(63843,63842,1,'Script Cast Summon Vile Spray - Summon Vile Spray');
-- Malfurion Stormrage SAI
SET @ENTRY := 33091;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,11,51835,0,0,0,0,0,1,0,0,0,0,0,0,0,"Malfurion Stormrage - On Reset - Cast Aura");
-- Cloudtamer Wildmane SAI
SET @ENTRY := 32988;
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,3,0,1,0,100,1,1000,1000,1000,1000,11,62164,2,0,0,0,0,1,0,0,0,0,0,0,0,"Cloudtamer Wildmane - OOC - Cast Aura");
-- Windmaster Tzu-Tzu SAI
SET @ENTRY := 32989;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`=4;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,4,0,1,0,100,1,1000,1000,1000,1000,11,62164,2,0,0,0,0,1,0,0,0,0,0,0,0,"Windmaster Tzu-Tzu - OOC - Cast Aura");
-- Skylord Braax SAI
SET @ENTRY := 32990;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,1000,1000,11,62164,2,0,0,0,0,1,0,0,0,0,0,0,0,"Skylord Braax - OOC - Cast Aura");
-- Vile Terror SAI
SET @ENTRY := 33864;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,6,0,100,0,0,0,0,0,11,63843,2,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Terror - On Death - Cast 'Script Cast Summon Vile Spray'"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,41,12000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Terror - On Death - Set Despawn 12 sec");
--
