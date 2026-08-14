-- Sunscorched Shells Outro
DELETE FROM `smart_scripts` WHERE `entryorguid`=6142 AND `source_type`=0 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=614201 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(6142,0,1,0,20,0,100,0,1710,0,0,0,0,80,614201,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mathiel - On Quest 'Sunscorched Shells' Finished - Run Script"),
(614201,9,0,0,0,0,100,0,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mathiel - On Script - Remove Npc Flag Questgiver"),
(614201,9,1,0,0,0,100,0,1000,1000,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,3.3613,"Mathiel - On Script - Set Orientation"),
(614201,9,2,0,0,0,100,0,1000,1000,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mathiel - On Script - Say Line 2"),
(614201,9,3,0,0,0,100,0,0,0,0,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mathiel - On Script - Set Emote State 69"),
(614201,9,4,0,0,0,100,0,12000,12000,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mathiel - On Script - Set Emote State 0"),
(614201,9,5,0,0,0,100,0,1000,1000,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0.166394,"Mathiel - On Script - Set Orientation"),
(614201,9,6,0,0,0,100,0,0,0,0,0,0,17,233,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mathiel - On Script - Set Emote State 233"),
(614201,9,7,0,0,0,100,0,10000,10000,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mathiel - On Script - Set Emote State 0"),
(614201,9,8,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Mathiel - On Script - Set Orientation Invoker"),
(614201,9,9,0,0,0,100,0,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mathiel - On Script - Say Line 3"),
(614201,9,10,0,0,0,100,0,2000,2000,0,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mathiel - On Script - Set Orientation Home Position"),
(614201,9,11,0,0,0,100,0,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mathiel - On Script - Add Npc Flag Questgiver");
