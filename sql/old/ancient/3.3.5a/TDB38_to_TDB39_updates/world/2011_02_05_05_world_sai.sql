-- Scourge Flamespitter SAI
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=25582;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-118407,-118408,-118425,-118421,-118422,-118426,-118427,-118375,-118405,-118409,-118423,-118428,-118429);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-118407,0,0,0,1,0,100,0,1000,1000,8000,8000,11,45863,2,0,0,0,0,1,0,0,0,0,0,0,0,'Fire at random target every 8 sec'),
(-118408,0,0,0,1,0,100,0,1000,1000,8000,8000,11,45863,2,0,0,0,0,1,0,0,0,0,0,0,0,'Fire at random target every 8 sec'),
(-118425,0,0,0,1,0,100,0,1000,1000,8000,8000,11,45863,2,0,0,0,0,1,0,0,0,0,0,0,0,'Fire at random target every 8 sec'),
(-118421,0,0,0,1,0,100,0,7000,7000,8000,8000,11,45863,2,0,0,0,0,1,0,0,0,0,0,0,0,'Fire at random target every 8 sec'),
(-118422,0,0,0,1,0,100,0,7000,7000,8000,8000,11,45863,2,0,0,0,0,1,0,0,0,0,0,0,0,'Fire at random target every 8 sec'),
(-118426,0,0,0,1,0,100,0,4000,4000,8000,8000,11,45863,2,0,0,0,0,1,0,0,0,0,0,0,0,'Fire at random target every 8 sec'),
(-118427,0,0,0,1,0,100,0,4000,4000,8000,8000,11,45863,2,0,0,0,0,1,0,0,0,0,0,0,0,'Fire at random target every 8 sec'),
(-118375,0,0,0,1,0,100,0,2000,2000,8000,8000,11,45863,2,0,0,0,0,1,0,0,0,0,0,0,0,'Fire at random target every 8 sec'),
(-118405,0,0,0,1,0,100,0,2000,2000,8000,8000,11,45863,2,0,0,0,0,1,0,0,0,0,0,0,0,'Fire at random target every 8 sec'),
(-118409,0,0,0,1,0,100,0,2000,2000,8000,8000,11,45863,2,0,0,0,0,1,0,0,0,0,0,0,0,'Fire at random target every 8 sec'),
(-118423,0,0,0,1,0,100,0,8000,8000,8000,8000,11,45863,2,0,0,0,0,1,0,0,0,0,0,0,0,'Fire at random target every 8 sec'),
(-118428,0,0,0,1,0,100,0,8000,8000,8000,8000,11,45863,2,0,0,0,0,1,0,0,0,0,0,0,0,'Fire at random target every 8 sec'),
(-118429,0,0,0,1,0,100,0,8000,8000,8000,8000,11,45863,2,0,0,0,0,1,0,0,0,0,0,0,0,'Fire at random target every 8 sec');
