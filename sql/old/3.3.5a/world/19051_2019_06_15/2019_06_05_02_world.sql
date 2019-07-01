-- 
DELETE FROM `smart_scripts` WHERE `entryorguid`=2125700 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(2125700,9,0,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Apothecary Zelana - Script - Say'),
(2125700,9,1,0,0,0,100,0,2000,2000,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,6.04,'Apothecary Zelana - Script - Set Orientation'),
(2125700,9,2,0,0,0,100,0,1000,1000,0,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Apothecary Zelana - Script - Set Emote State'),
(2125700,9,3,0,0,0,100,0,4000,4000,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,'Apothecary Zelana - Script - Say'),
(2125700,9,4,0,0,0,100,0,3000,3000,0,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0,0,'Apothecary Zelana - Script - Say'),
(2125700,9,5,0,0,0,100,0,1000,1000,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Apothecary Zelana - Script - Set Emote State'),
(2125700,9,6,0,0,0,100,0,1000,1000,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,3.1765,'Apothecary Zelana - Script - Set Orientation'),
(2125700,9,7,0,0,0,100,0,1000,1000,0,0,0,1,3,0,0,0,0,0,7,0,0,0,0,0,0,0,0,'Apothecary Zelana - Script - Say');
