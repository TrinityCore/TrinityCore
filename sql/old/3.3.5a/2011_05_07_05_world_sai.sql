-- SAI for Restless Apparition
SET @ENTRY := 23861;

UPDATE `creature_template` SET `ScriptName`='',`AIName`= 'SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY; 
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@ENTRY*100;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Restless Apparition - On spawn - Run script'),
(@ENTRY*100,9,0,0,0,0,100,0,2000,2000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Restless Apparition - Script - Say text 0'),
(@ENTRY*100,9,1,0,0,0,100,0,8000,8000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Restless Apparition - Script - Despawn');

DELETE FROM `creature_text` WHERE `entry`=@ENTRY; 
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'The darkness... the corruption... they came too quickly for anyone to know...',0,0,15,25,0,0, 'Restless Apparition'),
(@ENTRY,0,1, 'It is too late for us, living one. Take yourself and your friend away from here before you both are... claimed...',0,0,15,25,0,0, 'Restless Apparition'),
(@ENTRY,0,2, 'Go away, whoever you are! Witch Hill is mine... mine!',0,0,15,25,0,0, 'Restless Apparition'),
(@ENTRY,0,3, 'The darkness will consume all... all the living...',0,0,15,25,0,0, 'Restless Apparition'),
(@ENTRY,0,4, 'The manor... someone else... will soon be consumed...',0,0,15,25,0,0, 'Restless Apparition'),
(@ENTRY,0,5, 'Why have you come here, outsider? You will only find pain! Our fate will be yours...',0,0,15,25,0,0, 'Restless Apparition'),
(@ENTRY,0,6, 'It was... terrible... the demon...',0,0,15,25,0,0, 'Restless Apparition');
