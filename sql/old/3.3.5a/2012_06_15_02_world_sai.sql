-- Fix up quest 9312 "The Emitter"
-- Technician Zhanaa SAI
SET @ENTRY  := 17071;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,20,0,100,0,9312,0,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Technician Zhanaa - Quest Completed - Run Script'),
-- Script
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Technician Zhanaa - Script - Remove npc flags'),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,0,0,9,0,0,0,0,0,0,20,181286,0,0,0,0,0,0,'Technician Zhanaa - Script - Activate go'),
(@ENTRY*100,9,2,0,0,0,100,0,0,0,0,0,12,16550,1,39000,0,0,0,8,0,0,0,-4187.708,-13738.72,75.65491,1.850049,'Technician Zhanaa - Script - Spawn '),
(@ENTRY*100,9,3,0,0,0,100,0,0,0,0,0,64,2,0,0,0,0,0,7,0,0,0,0,0,0,0,'Technician Zhanaa - Script - store invoker'), -- Send target
(@ENTRY*100,9,4,0,0,0,100,0,1000,1000,0,0,100,2,0,0,0,0,0,19,16550,10,0,0,0,0,0,'Technician Zhanaa - Script - send target'), -- Send target
(@ENTRY*100,9,5,0,0,0,100,0,1000,1000,0,0,45,0,1,0,0,0,0,19,16550,10,0,0,0,0,0,'Technician Zhanaa - Script - set data'),
(@ENTRY*100,9,6,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,19,16550,10,0,0,0,0,0,'Technician Zhanaa - Script - turn to Image of Technician Dyvuun'),
(@ENTRY*100,9,7,0,0,0,100,0,2000,2000,0,0,5,70,0,0,0,0,0,1,0,0,0,0,0,0,0,'Technician Zhanaa - Script - emote'),
(@ENTRY*100,9,8,0,0,0,100,0,39000,39000,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Technician Zhanaa - Script - turn to invoker'),
(@ENTRY*100,9,9,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Technician Zhanaa - Script - Say 0'),
(@ENTRY*100,9,10,0,0,0,100,0,6000,6000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.919862,'Technician Zhanaa - Script - turn to'),
(@ENTRY*100,9,11,0,0,0,100,0,1000,1000,0,0,81,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Technician Zhanaa - Script - add npc flags');
-- NPC talk text insert from sniff
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'This is great news!  Your efforts have indeed saved us, $N!',12,0,100,0,0,0, 'Technician Zhanaa');
-- Image of Technician Dyvuun SAI
SET @ENTRY  := 16550;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`='',`InhabitType`=4 WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,38,0,100,0,0,1,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Image of Technician Dyvuun - On data set - Run Script'),
-- Script
(@ENTRY*100,9,0,0,0,0,100,0,2000,2000,0,0,66,0,0,0,0,0,0,19,17071,10,0,0,0,0,0,'Image of Technician Dyvuun - Script - turn to Technician Zhanaa'),
(@ENTRY*100,9,1,0,0,0,100,0,2000,2000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Image of Technician Dyvuun - Script - Say 0'),
(@ENTRY*100,9,2,0,0,0,100,0,10000,10000,0,0,66,0,0,0,0,0,0,12,2,0,0,0,0,0,0,'Image of Technician Dyvuun - Script - turn to Stored target'), -- use target
(@ENTRY*100,9,3,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Image of Technician Dyvuun - Script - Say 1'),
(@ENTRY*100,9,4,0,0,0,100,0,5000,5000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Image of Technician Dyvuun - Script - Say 2');
-- NPC talk text insert from sniff
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'By the seven Ata''mal crystals!  Others have survived the crash!  Zhanaa, is that you?  It is so good to see you again!',12,0,100,0,0,0, 'Image of Technician Dyvuun'),
(@ENTRY,1,0, 'And who do we have here?  No doubt th... crzzzk ...ade this communication possible?  I give you greetings fro... psshzzzk... Azure Watch.',12,0,100,0,0,0, 'Image of Technician Dyvuun'),
(@ENTRY,2,0, 'Judging by your signal, we put you... ust southeast of the larger part of the island we crashed onto.  Cross the Crystalbrook River to ge... kshhhhk zzzt. Sorry, there''s a lot of stat...',12,0,100,0,0,0, 'Image of Technician Dyvuun');
