-- Doctor Razorgrin SAI
SET @ENTRY := 25678;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `creature_ai_texts` WHERE `entry`=-767;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'Doctor Razorgin - On Aggro - Say Line 0 (random)');
-- Texts
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,'Ah, good... more parts!',14,0,100,0,0,0,'Part of the Doctor Razorgin on aggro lines'),
(@ENTRY,0,1,'Clear!',14,0,100,0,0,0,'Part of the Doctor Razorgin on aggro lines'),
(@ENTRY,0,2,'Fresh meat!',14,0,100,0,0,0,'Part of the Doctor Razorgin on aggro lines'),
(@ENTRY,0,3,'I recommened evisceration!',14,0,100,0,0,0,'Part of the Doctor Razorgin on aggro lines'),
(@ENTRY,0,4,'It''s no good... you need more work first.',14,0,100,0,0,0,'Part of the Doctor Razorgin on aggro lines'),
(@ENTRY,0,5,'Live, damn you!',14,0,100,0,0,0,'Part of the Doctor Razorgin on aggro lines'),
(@ENTRY,0,6,'The doctor is in!',14,0,100,0,0,0,'Part of the Doctor Razorgin on aggro lines');
