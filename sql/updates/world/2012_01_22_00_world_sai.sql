-- Munci SAI
SET @ENTRY := 18788;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,4,0,100,0,0,0,0,0,12,9527,1,30000,0,0,0,1,0,0,0,0,0,0,0,"Munci - On Aggro - Summon Enraged Hippogryphs"),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,12,9527,1,30000,0,0,0,1,0,0,0,0,0,0,0,"Munci - On Aggro - Summon Enraged Hippogryphs"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Munci - On Aggro - Say Line 0");

-- Text for Munci
SET @ENTRY := 18788;
DELETE FROM `creature_ai_texts` WHERE `npc_entry`=@ENTRY;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Guards!",14,7,100,0,0,0,"Munci");

-- Amish Wildhammer SAI
SET @ENTRY := 18931;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,4,0,100,0,0,0,0,0,12,9526,1,30000,0,0,0,1,0,0,0,0,0,0,0,"Amish Wildhammer - On Aggro - Summon Enraged Gryphons"),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,12,9526,1,30000,0,0,0,1,0,0,0,0,0,0,0,"Amish Wildhammer - On Aggro - Summon Enraged Gryphons"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Amish Wildhammer - On Aggro - Say Line 0");

-- Text for Amish Wildhammer
SET @ENTRY := 18931;
DELETE FROM `creature_ai_texts` WHERE `npc_entry`=@ENTRY;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Guards!",14,7,100,0,0,0,"Amish Wildhammer");

-- Lemla Hopewing SAI
SET @ENTRY := 19181;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,4,0,100,0,0,0,0,0,12,9526,1,30000,0,0,0,1,0,0,0,0,0,0,0,"Lemla Hopewing - On Aggro - Summon Enraged Gryphons"),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,12,9526,1,30000,0,0,0,1,0,0,0,0,0,0,0,"Lemla Hopewing - On Aggro - Summon Enraged Gryphons"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lemla Hopewing - On Aggro - Say Line 0");

-- Text for Lemla Hopewing
SET @ENTRY := 19181;
DELETE FROM `creature_ai_texts` WHERE `npc_entry`=@ENTRY;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Guards!",14,7,100,0,0,0,"Lemla Hopewing");

-- Auhula SAI
SET @ENTRY := 22936;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,4,0,100,0,0,0,0,0,12,9527,1,30000,0,0,0,1,0,0,0,0,0,0,0,"Auhula - On Aggro - Summon Enraged Hippogryphs"),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,12,9527,1,30000,0,0,0,1,0,0,0,0,0,0,0,"Auhula - On Aggro - Summon Enraged Hippogryphs"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Auhula - On Aggro - Say Line 0");

-- Text for Auhula
SET @ENTRY := 22936;
DELETE FROM `creature_ai_texts` WHERE `npc_entry`=@ENTRY;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Guards!",14,7,100,0,0,0,"Auhula");

-- Hyeyoung Parka SAI
SET @ENTRY := 29762;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,4,0,100,0,0,0,0,0,12,9297,1,30000,0,0,0,1,0,0,0,0,0,0,0,"Hyeyoung Parka - On Aggro - Summon Enraged Wyverns"),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,12,9297,1,30000,0,0,0,1,0,0,0,0,0,0,0,"Hyeyoung Parka - On Aggro - Summon Enraged Wyverns"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hyeyoung Parka - On Aggro - Say Line 0");

-- Text for Hyeyoung Parka
SET @ENTRY := 29762;
DELETE FROM `creature_ai_texts` WHERE `npc_entry`=@ENTRY;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Guards!",14,1,100,0,0,0,"Hyeyoung Parka");