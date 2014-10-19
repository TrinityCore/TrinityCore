UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=19354;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=19354;
DELETE FROM `smart_scripts` WHERE `entryorguid`=19354 AND `source_type`=0;
INSERT INTO `smart_scripts`(`entryorguid`,`id`,`event_type`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`target_type`,`comment`) VALUES
(19354,0,0,0,8000,12000,8000,14000,11,16856,0,2,'Arzeth the Merciless - Cast Mortal Strike'),
(19354,1,9,0,0,30,12000,14000,11,15245,1,2,'Arzeth the Merciless - Cast Shadow Bolt Volley'),
(19354,2,8,1,35460,0,0,0,36,20680,1,1,'Arzeth the Merciless - Change Template to Arzeth the Powerless after using Staff of the Dreghood Elders');
