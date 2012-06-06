-- Witch Doctor Mau'ari SAI
SET @ENTRY  := 10307;
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `quest_start_scripts` WHERE `id`=975;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@ENTRY*100;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,975,0,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Witch Doctor Mau''ari - On Quest Accept - Run Script'),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Witch Doctor Mau''ari - Script - Remove npc flags'),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,'Witch Doctor Mau''ari - Script - Set emote state use standing'),
(@ENTRY*100,9,2,0,0,0,100,0,9000,9000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Witch Doctor Mau''ari - Script - Set emote state use standing'),
(@ENTRY*100,9,3,0,0,0,100,0,1000,1000,0,0,81,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Witch Doctor Mau''ari - Script - add npc flags'),
(@ENTRY*100,9,4,0,0,0,100,0,0,0,0,0,15,975,0,0,0,0,0,7,0,0,0,0,0,0,0,'Witch Doctor Mau''ari - Script - Complete quest 975');
