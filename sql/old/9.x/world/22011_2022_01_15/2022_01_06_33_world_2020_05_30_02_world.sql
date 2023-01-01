-- Deathforge Mine SAI (Source: e-0tiidk0Ck)
SET @ID := 22315;
DELETE FROM `creature` WHERE `guid` = 78495 AND `id` = 22315;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 19754 AND `source_type` = 0 AND `id` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,54,0,100,0,0,0,0,0,0,80,@ID*100+0,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathforge Mine - On Just Summoned - Run Script");

-- Actionlist SAI
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID*100+0 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,0,11,38773,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathforge Mine - On Script - Cast 'Deathforge Mine'"),
(@ID*100+0,9,1,0,0,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathforge Mine - On Script - Set Reactstate Passive"),
-- It appears that the first emote is not used immediately after spawn
(@ID*100+0,9,2,0,0,0,100,0,1000,1000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathforge Mine - On Script - Say Line 0"),
(@ID*100+0,9,3,0,0,0,100,0,2000,2000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathforge Mine - On Script - Say Line 1"),
(@ID*100+0,9,4,0,0,0,100,0,3000,3000,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathforge Mine - On Script - Say Line 2"),
(@ID*100+0,9,5,0,0,0,100,0,0,0,0,0,0,11,38108,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathforge Mine - On Script - Cast 'Deathforge Mine Explosion'"),
(@ID*100+0,9,6,0,0,0,100,0,1000,1000,0,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathforge Mine - On Script - Kill Self");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextID`,`TextRange`,`comment`) VALUES
(@ID,0,0,"%s will detonate in 5 seconds!",16,0,100,0,0,0,20104,0,"Deathforge Mine"),
(@ID,1,0,"Deathforge Mine will detonate in 3 seconds!",16,0,100,0,0,0,20106,0,"Deathforge Mine"),
(@ID,2,0,"Deathforge Mine: Detonating!",16,0,100,0,0,0,20108,0,"Deathforge Mine");

DELETE FROM `creature_template_movement` WHERE `CreatureId` = 22315;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`) VALUES
(22315,1,1,0,1,0,0);
