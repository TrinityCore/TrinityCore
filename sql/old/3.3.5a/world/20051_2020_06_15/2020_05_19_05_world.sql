-- Panther Cage SAI (Source: https://www.youtube.com/watch?v=BObxNsbRWsc)
SET @ID := 176195;
UPDATE `gameobject_template` SET `AIName` = "SmartGameObjectAI", `ScriptName` = "" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,1,0,1,70,0,100,0,2,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Panther Cage - On Gameobject State Changed - Store Targetlist"),
(@ID,1,1,2,61,0,100,0,0,0,0,0,0,19,2,0,0,0,0,0,19,10992,5,0,0,0,0,0,0,"Panther Cage - On Link - Remove Flag Not Attackable (Enraged Panther)"),
(@ID,1,2,3,61,0,100,0,0,0,0,0,0,8,2,0,0,0,0,0,19,10992,5,0,0,0,0,0,0,"Panther Cage - On Link - Set Reactstate Aggressive (Enraged Panther)"),
(@ID,1,3,4,61,0,100,0,0,0,0,0,0,100,1,0,0,0,0,0,19,10992,5,0,0,0,0,0,0,"Panther Cage - On Link - Send Target 1 (Enraged Panther)"),
(@ID,1,4,0,61,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,19,10992,5,0,0,0,0,0,0,"Panther Cage - On Link - Set Data 0 1 (Enraged Panther)");

-- Enraged Panther SAI (Source: https://www.youtube.com/watch?v=BObxNsbRWsc)
SET @ID := 10992;
UPDATE `creature` SET `spawntimesecs` = 300 where `guid` = 21705 AND `id` = 10992;
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,1,11,0,100,0,0,0,0,0,0,18,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Enraged Panther - On Respawn - Set Flag Not Attackable"),
(@ID,0,1,0,61,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Enraged Panther - On Link - Set Reactstate Passive"),
(@ID,0,2,0,38,0,100,0,0,1,0,0,0,49,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Enraged Panther - On Data Set 0 1 - Start Attacking");
