-- 
DELETE FROM `quest_template_addon` WHERE `id` = 4321;
SET @ID := 9117;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ID AND `source_type`=0 AND `id` =0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ID*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,20,0,100,0,4321,0,0,0,0,80,@ID*100+0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"J.D. Collie - On Quest \Making Sense of It\ Rewarded - Run Script"),
(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"J.D. Collie - On Script - Remove Npc Flag Questgiver+Gossip"),
(@ID*100+0,9,1,0,0,0,100,0,1000,1000,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,3.08,"J.D. Collie - Set Orientation 3.08"),
(@ID*100+0,9,2,0,0,0,100,0,2000,2000,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"J.D. Collie - On Script - Say Line 0"),
(@ID*100+0,9,3,0,0,0,100,0,1000,1000,0,0,0,50,174683,15,0,0,0,0,8,0,0,0,0,-6037.161,-1016.886,-216.920,5.958,"J.D. Collie - Summon Gameobject Book"),
(@ID*100+0,9,4,0,0,0,100,0,2000,2000,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"J.D. Collie - On Script - Say Line 1"),
(@ID*100+0,9,5,0,0,0,100,0,3000,3000,0,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"J.D. Collie - On Script - Say Line 2"),
(@ID*100+0,9,6,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0.87,"J.D. Collie - Set Orientation 0.87"),
(@ID*100+0,9,7,0,0,0,100,0,0,0,0,0,0,82,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"J.D. Collie - On Script - Add Npc Flag Questgiver+Gossip");
