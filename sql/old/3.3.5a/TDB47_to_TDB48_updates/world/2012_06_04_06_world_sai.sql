-- Mok'rash SAI
SET @ENTRY := 1493;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO smart_scripts (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,5000,10000,300000,600000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Mok''Rash - OOC - Random Yell'),
(@ENTRY,0,1,0,0,0,85,0,8000,8000,15000,15000,11,40505,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Mok''Rash - Combat - Cast Cleave');
-- Mok'rash Text
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO creature_text (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY, 0, 0, 'SMOTTS, I HAVE YOUR LITTLE BELT....COME GET IT!', 14, 0, 100, 0, 0, 0, 'Mok''rash Yell'),
(@ENTRY, 0, 1, 'SMOTTS! HEY, SMOTTS! COME OUT AND PLAY!', 14, 0, 100, 0, 0, 0, 'Mok''rash Yell'),
(@ENTRY, 0, 2, 'DON''T LET THIS STATUE BE MY ONLY COMPANY, COME OUT AND PLAY!', 14, 0, 100, 0, 0, 0, 'Mok''rash Yell'),
(@ENTRY, 0, 3, 'COME OUT TO JANEIRO''S POINT. I''M WAITING FOR YOU, SMOTTS...', 14, 0, 100, 0, 0, 0, 'Mok''rash Yell'),
(@ENTRY, 0, 4, 'I PROMISE I WON''T KILL YOUR CREW THIS TIME. HAH! BUT MY BROTHER MIGHT EAT THEM!', 14, 0, 100, 0, 0, 0, 'Mok''rash Yell'),
(@ENTRY, 0, 5, 'HAVE YOU RUN OUT OF SHIPS TO SEND? WHERE IS YOUR COURAGE?', 14, 0, 100, 0, 0, 0, 'Mok''rash Yell'),
(@ENTRY, 0, 6, 'I HAVE YOUR LITTLE BELT TIED AROUND MY FINGER, SMOTTS. DON''T YOU WANT IT BACK?', 14, 0, 100, 0, 0, 0, 'Mok''rash Yell');
