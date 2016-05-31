-- 
SET @obj     := 191840; 
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=@obj;
DELETE FROM `smart_scripts` WHERE `source_type`=1 AND `entryorguid`=@obj;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@obj,1,0,0,70,0,100,1,2,0,0,0,41,500,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Plagued Proto-Drake Egg - In GO_STATE_CHANGED - despawn');
