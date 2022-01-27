-- Defender Grashna SAI (Source: https://www.youtube.com/watch?v=yszVj621cig)
SET @ID := 22373;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID*100+0 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,19,0,100,0,10879,0,0,0,0,80,@ID*100+0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Defender Grashna - On Quest 'The Skettis Offensive' Taken - Run Script"),
(@ID,0,1,2,82,0,100,0,22375,0,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Defender Grashna - On Summoned Unit 'Avatar of Terokk' Dies - Say Line 4"),
(@ID,0,2,0,61,0,100,0,0,0,0,0,0,15,10879,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Defender Grashna - On Link - Quest Credit 'The Skettis Offensive'"),

(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,0,64,1,0,0,0,0,0,16,0,0,0,0,0,0,0,0,"Defender Grashna - On Script - Store Targetlist"),
(@ID*100+0,9,1,0,0,0,100,0,0,0,0,0,0,107,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Defender Grashna - On Script - Summon Group 0"),
(@ID*100+0,9,2,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Defender Grashna - On Script - Say Line 0"),
(@ID*100+0,9,3,0,0,0,100,0,20000,20000,0,0,0,107,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Defender Grashna - On Script - Summon Group 1"),
(@ID*100+0,9,4,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Defender Grashna - On Script - Say Line 1"),
(@ID*100+0,9,5,0,0,0,100,0,20000,20000,0,0,0,107,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Defender Grashna - On Script - Summon Group 2"),
(@ID*100+0,9,6,0,0,0,100,0,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Defender Grashna - On Script - Say Line 2"),
(@ID*100+0,9,7,0,0,0,100,0,20000,20000,0,0,0,107,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Defender Grashna - On Script - Summon Group 3"),
(@ID*100+0,9,8,0,0,0,100,0,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Defender Grashna - On Script - Say Line 3");

DELETE FROM `creature_summon_groups` WHERE `summonerId` = 22373 AND `summonerType` = 0;
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`,`summonTime`,`Comment`) VALUES
(22373,0,0,22376,-1626.12,5402.47,-42.31,2.08131,4,60000,"Defender Grashna - Group 0 - Minion of Terokk"),
(22373,0,0,22376,-1626.12,5402.47,-42.31,2.08131,4,60000,"Defender Grashna - Group 0 - Minion of Terokk"),
(22373,0,1,22376,-1626.12,5402.47,-42.31,2.08131,4,60000,"Defender Grashna - Group 1 - Minion of Terokk"),
(22373,0,1,22376,-1626.12,5402.47,-42.31,2.08131,4,60000,"Defender Grashna - Group 1 - Minion of Terokk"),
(22373,0,2,22376,-1626.12,5402.47,-42.31,2.08131,4,60000,"Defender Grashna - Group 2 - Minion of Terokk"),
(22373,0,2,22376,-1626.12,5402.47,-42.31,2.08131,4,60000,"Defender Grashna - Group 2 - Minion of Terokk"),
(22373,0,2,22376,-1626.12,5402.47,-42.31,2.08131,4,60000,"Defender Grashna - Group 2 - Minion of Terokk"),
(22373,0,3,22375,-1626.12,5402.47,-42.31,2.08131,4,60000,"Defender Grashna - Group 3 - Avatar of Terokk");

-- Text 'We have taken too long. Terokk reigns victorious.' 20269 probably used when nobody killed birds in given time
DELETE FROM `creature_text` WHERE `CreatureID` = 22373;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(22373,0,0,"%s points to the sky above.",16,0,100,0,0,0,20157,0,"Defender Grashna"),
(22373,1,0,"More Minions of Terokk are coming!",12,0,100,0,0,0,20266,0,"Defender Grashna"),
(22373,2,0,"The invaders persist! Hold them off!",12,0,100,0,0,0,20267,0,"Defender Grashna"),
(22373,3,0,"An Avatar of Terokk!! To arms!",12,0,100,0,0,0,20268,0,"Defender Grashna"),
(22373,4,0,"The Avatar of Terokk has been defeated! Death to Terokk! Death to Skettis!",12,0,100,0,0,0,20270,0,"Defender Grashna");

DELETE FROM `smart_scripts` WHERE `entryorguid` = 22375 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(22375,0,0,0,54,0,100,0,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,0,-1641.12,5436.65,-43.3445,0.803601,"Avatar of Terokk - On Just Summoned - Move To Position"),
(22375,0,1,0,4,0,100,0,0,0,0,0,0,11,24193,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Avatar of Terokk - On Aggro - Cast 'Charge'"),
(22375,0,2,0,0,0,100,0,6000,9000,11000,14000,0,11,39068,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Avatar of Terokk - In Combat - Cast 'Feather Burst'");
