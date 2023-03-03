-- by canewadar
-- fix gameobject giving quest trigger after interaction
-- Voice of Vol'jamba SAI
SET @ENTRY := 278536;
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,1,0,0,70,0,100,0,2,0,0,0,33,130209,0,0,0,0,0,7,0,0,0,0,0,0,0,"Voice of Vol'jamba - On Gameobject State Changed - Quest Credit ''");

-- Add missing quest to the quest npc
Delete from `creature_queststarter` where `id` = 129907 AND `quest` = 51663;
Insert INTO `creature_queststarter` (`id`, `quest`) VALUES (129907, 51663);