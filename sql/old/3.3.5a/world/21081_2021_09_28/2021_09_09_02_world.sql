--
DELETE FROM `smart_scripts` WHERE `entryorguid` = 7917 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 791700 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(7917,0,0,0,38,0,100,0,0,1,60000,60000,0,80,791700,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Brother Sarno - On Data Set 0 1 - Run Script"),

(791700,9,0,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Brother Sarno - On Script - Set Orientation Stored Target"),
(791700,9,1,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Brother Sarno - On Script - Say Line 0"),
(791700,9,2,0,0,0,100,0,3000,3000,0,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Brother Sarno - On Script - Set Orientation Home Position");
