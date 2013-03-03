-- [Q] [A/H] Enchanted Azsharite Fel Weaponry
-- [Q] [A/H] Expert Blacksmith!
-- Galvan the Ancient SAI
SET @ENTRY := 7802;
SET @QUEST_ENCHANTED := 3625;
SET @QUEST_EXPERT_BS := 2765;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
UPDATE `quest_template` SET `StartScript`=0,`CompleteScript`=0 WHERE `id` IN (@QUEST_ENCHANTED,@QUEST_EXPERT_BS);
UPDATE `creature` SET `position_x`=-12033.400391,`position_y`=-1003.859985,`position_z`=49.779499,`orientation`=3.910880 WHERE `guid`=384 AND `id`=@ENTRY; -- Galvan the Ancient should be at a different position..
DELETE FROM `creature` WHERE `guid`=1864 AND `id`=684; -- Flying panther in the middle of our event spot..
DELETE FROM `creature_addon` WHERE `guid`=1864;
DELETE FROM `quest_start_scripts` WHERE `id` IN (@QUEST_ENCHANTED,@QUEST_EXPERT_BS);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY,@ENTRY*100,@ENTRY*100+1);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,@QUEST_ENCHANTED,0,0,0,80,@ENTRY*100,0,2,0,0,0,1,0,0,0,0,0,0,0,"Galvan the Ancient - On Quest Accept - Run Script"),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-12040.5,-1008.7,49.4,3.66,"Galvan the Ancient - On Script - Move To Anvil"),
(@ENTRY*100,9,1,0,0,0,100,0,4000,4000,0,0,5,28,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galvan the Ancient - On Script - Emote STATE_WORK_SHEATHED"),
(@ENTRY*100,9,2,0,0,0,100,0,1500,1500,0,0,5,28,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galvan the Ancient - On Script - Emote STATE_WORK_SHEATHED"),
(@ENTRY*100,9,3,0,0,0,100,0,1500,1500,0,0,5,28,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galvan the Ancient - On Script - Emote STATE_WORK_SHEATHED"),
(@ENTRY*100,9,4,0,0,0,100,0,1500,1500,0,0,5,28,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galvan the Ancient - On Script - Emote STATE_WORK_SHEATHED"),
(@ENTRY*100,9,5,0,0,0,100,0,2000,2000,0,0,69,0,0,0,0,0,0,8,0,0,0,-12040.988281,-1007.649170,49.481323,2.364430,"Galvan the Ancient - On Script - Move To Forge"),
(@ENTRY*100,9,6,0,0,0,100,0,1000,1000,0,0,5,28,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galvan the Ancient - On Script - Emote STATE_WORK_SHEATHED"),
(@ENTRY*100,9,7,0,0,0,100,0,1500,1500,0,0,5,28,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galvan the Ancient - On Script - Emote STATE_WORK_SHEATHED"),
(@ENTRY*100,9,8,0,0,0,100,0,1500,1500,0,0,5,28,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galvan the Ancient - On Script - Emote STATE_WORK_SHEATHED"),
(@ENTRY*100,9,9,0,0,0,100,0,2000,2000,0,0,15,@QUEST_ENCHANTED,0,0,0,0,0,7,0,0,0,0,0,0,0,"Galvan the Ancient - On Script - Quest Credit"),
(@ENTRY*100,9,10,0,0,0,100,0,5000,5000,0,0,69,0,0,0,0,0,0,8,0,0,0,-12033.400391,-1003.859985,49.779499,3.910880,"Galvan the Ancient - On Script - Move To Homeposition"),

(@ENTRY,0,1,0,19,0,100,0,@QUEST_EXPERT_BS,0,0,0,80,@ENTRY*100+1,0,2,0,0,0,1,0,0,0,0,0,0,0,"Galvan the Ancient - On Quest Accept - Run Script"),
(@ENTRY*100+1,9,0,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-12040.5,-1008.7,49.4,3.66,"Galvan the Ancient - On Script - Move To Anvil"),
(@ENTRY*100+1,9,1,0,0,0,100,0,4000,4000,0,0,5,28,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galvan the Ancient - On Script - Emote STATE_WORK_SHEATHED"),
(@ENTRY*100+1,9,2,0,0,0,100,0,1500,1500,0,0,5,28,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galvan the Ancient - On Script - Emote STATE_WORK_SHEATHED"),
(@ENTRY*100+1,9,3,0,0,0,100,0,1500,1500,0,0,5,28,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galvan the Ancient - On Script - Emote STATE_WORK_SHEATHED"),
(@ENTRY*100+1,9,4,0,0,0,100,0,1500,1500,0,0,5,28,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galvan the Ancient - On Script - Emote STATE_WORK_SHEATHED"),
(@ENTRY*100+1,9,5,0,0,0,100,0,2000,2000,0,0,69,0,0,0,0,0,0,8,0,0,0,-12040.988281,-1007.649170,49.481323,2.364430,"Galvan the Ancient - On Script - Move To Forge"),
(@ENTRY*100+1,9,6,0,0,0,100,0,1000,1000,0,0,5,28,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galvan the Ancient - On Script - Emote STATE_WORK_SHEATHED"),
(@ENTRY*100+1,9,7,0,0,0,100,0,1500,1500,0,0,5,28,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galvan the Ancient - On Script - Emote STATE_WORK_SHEATHED"),
(@ENTRY*100+1,9,8,0,0,0,100,0,1500,1500,0,0,5,28,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galvan the Ancient - On Script - Emote STATE_WORK_SHEATHED"),
(@ENTRY*100+1,9,9,0,0,0,100,0,2000,2000,0,0,15,@QUEST_EXPERT_BS,0,0,0,0,0,7,0,0,0,0,0,0,0,"Galvan the Ancient - On Script - Quest Credit"),
(@ENTRY*100+1,9,10,0,0,0,100,0,5000,5000,0,0,69,0,0,0,0,0,0,8,0,0,0,-12033.400391,-1003.859985,49.779499,3.910880,"Galvan the Ancient - On Script - Move To Homeposition");
