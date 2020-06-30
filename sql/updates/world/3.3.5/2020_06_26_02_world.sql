-- Goblin Land Mine SAI (based on a video but I haven't saved the url)
SET @ID := 7527;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,54,0,100,0,0,0,0,0,0,80,@ID*100+0,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Goblin Land Mine - On Just Summoned - Run Script"),
-- Probably 4043 is used only when the mine is summoned by player and 11815 is used if summoned by NPCs
-- Used also by NPC Weegli Blastfuse (7607), Spell 21688
(@ID,0,1,3,10,1,100,1,0,10,0,0,0,11,4043,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Goblin Land Mine - OOC Los - Cast 'Detonation' (Phase 1) (No Repeat)"),
(@ID,0,2,3,26,1,100,1,0,10,0,0,0,11,4043,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Goblin Land Mine - IC Los - Cast 'Detonation' (Phase 1) (No Repeat)"),
(@ID,0,3,0,61,0,100,0,0,0,0,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Goblin Land Mine - On Link - Kill Self");

-- Actionlist SAI
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID*100+0 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Goblin Land Mine - On Script - Set Event Phase 2"),
(@ID*100+0,9,1,0,0,0,100,0,0,0,0,0,0,116,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Goblin Land Mine - On Script - Set Corpse Delay"),
(@ID*100+0,9,2,0,0,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Goblin Land Mine - On Script - Set Reactstate Passive"),
(@ID*100+0,9,3,0,0,0,100,0,0,0,0,0,0,11,11816,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Goblin Land Mine - On Script - Cast 'Land Mine Arming'"),
-- It appears that the first emote is not used immediately after spawn
(@ID*100+0,9,4,0,0,0,100,0,1000,1000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Goblin Land Mine - On Script - Say Line 0"),
(@ID*100+0,9,5,0,0,0,100,0,5000,5000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Goblin Land Mine - On Script - Say Line 1"),
(@ID*100+0,9,6,0,0,0,100,0,5000,5000,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Goblin Land Mine - On Script - Say Line 2"),
-- Now the mine becomes active
(@ID*100+0,9,7,0,0,0,100,0,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Goblin Land Mine - On Script - Set Event Phase 1"),
(@ID*100+0,9,8,0,0,0,100,0,0,0,0,0,0,28,11816,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Goblin Land Mine - On Script - Remove Aura 'Land Mine Arming'");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextID`,`TextRange`,`comment`) VALUES
(@ID,0,0,"%s will be armed in 10 seconds!",16,0,100,0,0,0,3541,0,"Goblin Land Mine"),
(@ID,1,0,"%s will be armed in 5 seconds!",16,0,100,0,0,0,3542,0,"Goblin Land Mine"),
(@ID,2,0,"%s is now armed!",16,0,100,0,0,0,3543,0,"Goblin Land Mine");

DELETE FROM `creature_template_movement` WHERE `CreatureId` = 7527;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`) VALUES
(7527,1,1,0,1,0,0);

-- Dark Iron Land Mine SAI (based on a video but I haven't saved the url)
SET @ID := 8035;
UPDATE `creature_template` SET `AIName` = "SmartAI", `unit_flags` = 0 WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,54,0,100,0,0,0,0,0,0,80,@ID*100+0,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dark Iron Land Mine - On Just Summoned - Run Script"),
-- Probably 11815 is used
(@ID,0,1,3,10,1,100,1,0,10,0,0,0,11,4043,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dark Iron Land Mine - OOC Los - Cast 'Detonation' (Phase 1) (No Repeat)"),
(@ID,0,2,3,26,1,100,1,0,10,0,0,0,11,4043,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dark Iron Land Mine - IC Los - Cast 'Detonation' (Phase 1) (No Repeat)"),
(@ID,0,3,0,61,0,100,0,0,0,0,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dark Iron Land Mine - On Link - Kill Self");

-- Actionlist SAI
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID*100+0 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dark Iron Land Mine - On Script - Set Event Phase 2"),
(@ID*100+0,9,1,0,0,0,100,0,0,0,0,0,0,116,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dark Iron Land Mine - On Script - Set Corpse Delay"),
(@ID*100+0,9,2,0,0,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dark Iron Land Mine - On Script - Set Reactstate Passive"),
(@ID*100+0,9,3,0,0,0,100,0,0,0,0,0,0,11,11816,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dark Iron Land Mine - On Script - Cast 'Land Mine Arming'"),
-- It appears that the first emote is not used immediately after spawn
(@ID*100+0,9,4,0,0,0,100,0,1000,1000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dark Iron Land Mine - On Script - Say Line 0"),
(@ID*100+0,9,5,0,0,0,100,0,5000,5000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dark Iron Land Mine - On Script - Say Line 1"),
(@ID*100+0,9,6,0,0,0,100,0,5000,5000,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dark Iron Land Mine - On Script - Say Line 2"),
-- Now the mine becomes active
(@ID*100+0,9,7,0,0,0,100,0,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dark Iron Land Mine - On Script - Set Event Phase 1"),
(@ID*100+0,9,8,0,0,0,100,0,0,0,0,0,0,28,11816,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dark Iron Land Mine - On Script - Remove Aura 'Land Mine Arming'");

UPDATE `creature_text` SET `Sound` = 0 WHERE `CreatureID` = @ID;
UPDATE `smart_scripts` SET `event_type` = 0 WHERE `entryorguid` = 6212 AND `source_type` = 0  AND `id` = 0;
