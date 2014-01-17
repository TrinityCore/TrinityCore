-- [Q] [A] The Legend of Stalvan
-- Sealed Crate SAI
SET @ENTRY := 1561;
SET @QUEST := 74;
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=@ENTRY;
UPDATE `quest_template` SET `StartScript`=0,`CompleteScript`=0 WHERE `id`=@QUEST;
DELETE FROM `quest_start_scripts` WHERE `id`=@QUEST;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,1,0,0,19,0,100,0,@QUEST,0,0,0,12,2044,1,30000,0,0,0,8,0,0,0,-10953.3,988.509,98.984,5.349,"Sealed Crate - On Quest Accept - Summon Forlorn Spirit"); -- What's wrong with those stupid co-ords? ..
