--
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (20748);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES  
(20748,0,0,0,25,0,100,0,0,0,0,0,11,37691,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Thunderlord Dire Wolf - On Reset - Cast Stealth Detection'),
(20748,0,1,0,0,0,100,0,4000,6000,10000,11000,11,5781,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Thunderlord Dire Wolf - IC - Cast Threatening Growl'),
(20748,0,2,0,8,0,100,0,32578,0,120000,120000,33,21142,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Thunderlord Dire Wolf - on spell hit - Credit quest');
