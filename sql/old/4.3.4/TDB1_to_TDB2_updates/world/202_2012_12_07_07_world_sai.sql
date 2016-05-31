-- ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
DELETE FROM `quest_end_scripts` WHERE `id`=13082;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=30562;
DELETE FROM `smart_scripts` WHERE `entryorguid`=30562 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(30562,0,0,0,20,1,100,0,13082,0,0,0,11,57786,0,0,0,0,0,7,0,0,0,0,0,0,0,'Crusader Bridenbrad - On Quest Complete - Cast Spell on action Invoker'),
(30562,0,1,0,20,1,100,0,13082,0,0,0,11,57782,0,0,0,0,0,7,0,0,0,0,0,0,0,'Crusader Bridenbrad - On Quest Complete - Cast Spell on action Invoker'),
(30562,0,2,0,20,1,100,0,13082,0,0,0,11,57746,0,0,0,0,0,7,0,0,0,0,0,0,0,'Crusader Bridenbrad - On Quest Complete - Cast Spell on action Invoker'),
(30562,0,3,0,20,1,100,0,13082,0,0,0,11,57747,0,0,0,0,0,7,0,0,0,0,0,0,0,'Crusader Bridenbrad - On Quest Complete - Cast Spell on action Invoker'),
(30562,0,4,0,20,1,100,0,13082,0,0,0,11,57773,0,0,0,0,0,7,0,0,0,0,0,0,0,'Crusader Bridenbrad - On Quest Complete - Cast Spell on action Invoker');
-- ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
DELETE FROM `quest_end_scripts` WHERE `id`=10919;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=20206;
DELETE FROM `smart_scripts` WHERE `entryorguid`=20206 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(20206,0,0,0,20,1,100,0,13082,0,0,0,53,0,20206,0,0,0,0,1,0,0,0,0,0,0,0,'Fei Fei - On Quest Complete - Start Waypointing');
DELETE FROM `waypoints` WHERE `entry`=20206;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(20206,1,-697.934,2612.59,89.4752,'Fei Fei Treats Quest_End'), 
(20206,2,-688.665,2580.78,86.9841,'Fei Fei Treats Quest_End'), 
(20206,3,-689.199,2588.81,87.4460,'Fei Fei Treats Quest_End'), 
(20206,4,-667.044,2611.74,85.7029,'Fei Fei Treats Quest_End'), 
(20206,5,-649.407,2636.82,86.1539,'Fei Fei Treats Quest_End'), 
(20206,6,-659.047,2651.34,87.0480,'Fei Fei Treats Quest_End'), 
(20206,7,-656.048,2652.06,86.5892,'Fei Fei Treats Quest_End'), 
(20206,8,-656.055,2674.20,88.1354,'Fei Fei Treats Quest_End'), 
(20206,9,-691.042,2652.45,92.1508,'Fei Fei Treats Quest_End'), 
(20206,10,-688.807,2701.25,94.8354,'Fei Fei Treats Quest_End'), 
(20206,11,-667.514,2716.08,94.4471,'Fei Fei Treats Quest_End'), 
(20206,12,-688.593,2723.67,94.4145,'Fei Fei Treats Quest_End'), 
(20206,13,-687.635,2743.10,93.9095,'Fei Fei Treats Quest_End'), 
(20206,14,-697.062,2748.04,93.9380,'Fei Fei Treats Quest_End'), 
(20206,15,-687.635,2743.10,93.9095,'Fei Fei Treats Quest_End'), 
(20206,16,-685.121,2689.01,93.8042,'Fei Fei Treats Quest_End'), 
(20206,17,-688.862,2627.19,89.8591,'Fei Fei Treats Quest_End'), 
(20206,18,-685.494,2626.74,89.2711,'Fei Fei Treats Quest_End');
