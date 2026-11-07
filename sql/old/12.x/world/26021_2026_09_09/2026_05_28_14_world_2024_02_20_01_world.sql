-- Anchorite Fateema outro script for quest "Medicinal Purpose" (9463)
DELETE FROM `smart_scripts` WHERE `entryorguid`=17214 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1721400 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(17214,0,1,0,20,0,100,0,9463,0,0,0,0,80,1721400,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Anchorite Fateema - On Quest 'Medicinal Purposes' Rewarded - Run Script"),
(1721400,9,0,0,0,0,100,0,0,0,0,0,0,83,19,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Daedal - On Script - Remove Npc Flag Questgiver+Trainer"),
(1721400,9,1,0,0,0,100,0,1000,1000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Anchorite Fateema - On Script - Say Line 1"),
(1721400,9,2,0,0,0,100,0,4000,4000,0,0,0,5,16,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Anchorite Fateema - On Script - Play Emote"),
(1721400,9,3,0,0,0,100,0,6000,6000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Anchorite Fateema - On Script - Say Line 2"),
(1721400,9,4,0,0,0,100,0,2000,2000,0,0,0,82,19,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Daedal - On Script - Add Npc Flag Questgiver+Trainer"),
(1721400,9,5,0,0,0,100,0,2000,2000,0,0,0,1,0,0,0,0,0,0,19,17215,0,0,0,0,0,0,0,"Anchorite Fateema - On Script - Say Line 1 (Daedal)");
