-- SAI for Amani'shi Guardian
SET @ENTRY := 23597;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY AND `id`>1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,2,0,38,0,100,2,0,1,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Amani''shi Guardian - On data set 1 - Set Phase 1'),
(@ENTRY,0,3,0,38,0,100,2,0,2,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Amani''shi Guardian - On data set 2 - Set Phase 2'),
-- Script 0
(@ENTRY,0,4,0,1,1,100,3,0,0,0,0,45,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Amani''shi Guardian - Script - Set data 0'),
(@ENTRY,0,5,0,1,1,100,3,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Amani''shi Guardian - Script - Set Run on'),
(@ENTRY,0,6,0,1,1,100,3,2000,2000,2000,2000,69,0,0,0,0,0,0,8,0,0,0,138.2242,1586.994,43.5488,0, 'Amani''shi Guardian - Script - Move to'),
(@ENTRY,0,7,0,1,1,100,3,3000,3000,3000,3000,69,0,0,0,0,0,0,8,0,0,0,131.8407,1590.247,43.61384,0, 'Amani''shi Guardian - Script - Move to'),
(@ENTRY,0,8,0,1,1,100,3,4000,4000,4000,4000,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.024582, 'Amani''shi Guardian - Script - Turn to'),
(@ENTRY,0,9,0,1,1,100,3,5000,5000,5000,5000,11,43647,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Amani''shi Guardian - Script - Cast'),
(@ENTRY,0,10,0,1,1,100,3,5200,5200,5200,5200,71,0,1,33979,0,0,0,1,0,0,0,0,0,0,0, 'Amani''shi Guardian - Script - Change equipment'),
(@ENTRY,0,11,0,1,1,100,3,6000,6000,6000,6000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Amani''shi Guardian - Script - Say 0'),
(@ENTRY,0,12,0,1,1,100,3,6200,6200,6200,6200,19,256,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Amani''shi Guardian - Script - Remove Unit Flag'),
(@ENTRY,0,13,0,1,1,100,3,7000,7000,7000,7000,49,0,0,0,0,0,0,21,50,0,0,0,0,0,0, 'Amani''shi Guardian - Script - Attack Cloest player'),
-- Script 1
(@ENTRY,0,14,0,1,2,100,3,0,0,0,0,45,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Amani''shi Guardian - Script - Set data 0'),
(@ENTRY,0,15,0,1,2,100,3,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Amani''shi Guardian - Script - Set Run on'),
(@ENTRY,0,16,0,1,2,100,3,6000,6000,6000,6000,69,0,0,0,0,0,0,8,0,0,0,107.7912,1586.498,43.61609,0, 'Amani''shi Guardian - Script - Move to'),
(@ENTRY,0,17,0,1,2,100,3,6800,6800,6800,6800,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.047198, 'Amani''shi Guardian - Script - Turn to'),
(@ENTRY,0,18,0,1,2,100,3,7600,7600,7600,7600,19,256,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Amani''shi Guardian - Script - Remove Unit Flag'),
(@ENTRY,0,19,0,1,2,100,3,7800,7800,7800,7800,49,0,0,0,0,0,0,21,50,0,0,0,0,0,0, 'Amani''shi Guardian - Script - Attack Cloest player');
