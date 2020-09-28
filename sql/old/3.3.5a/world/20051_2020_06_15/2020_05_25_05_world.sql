-- Bessy SAI (Sources: CMaNGOS & https://www.youtube.com/watch?v=pdLK5HrLwqE)
SET @ID := 20415;
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ID*100+0,@ID*100+1,@ID*100+2,@ID*100+3) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,19,0,100,0,10337,0,0,0,0,80,@ID*100+0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bessy - On Quest 'When the Cows Come Home' Taken - Run Script"),
(@ID,0,1,0,40,0,100,0,4,0,0,0,0,80,@ID*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bessy - On Waypoint 4 Reached - Run Script"),
(@ID,0,2,0,40,0,100,0,8,0,0,0,0,80,@ID*100+2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bessy - On Waypoint 8 Reached - Run Script"),
(@ID,0,3,0,40,0,100,0,13,0,0,0,0,80,@ID*100+3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bessy - On Waypoint 13 Reached - Run Script"),
(@ID,0,4,0,6,0,100,0,0,0,0,0,0,6,10337,0,0,0,0,0,16,0,0,0,0,0,0,0,0,"Bessy - On Death - Fail Quest 'When the Cows Come Home'"),

(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Bessy - On Script - Store Targetlist"),
(@ID*100+0,9,1,0,0,0,100,0,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bessy - On Script - Remove NPC Flag Questgiver"),
(@ID*100+0,9,2,0,0,0,100,0,0,0,0,0,0,19,256,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bessy - On Script - Remove Flag Immune To Players"),
(@ID*100+0,9,3,0,0,0,100,0,0,0,0,0,0,2,250,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bessy - On Script - Set Faction 250"),
(@ID*100+0,9,4,0,0,0,100,0,3000,3000,0,0,0,53,0,20415,0,0,0,1,1,0,0,0,0,0,0,0,0,"Bessy - On Script - Start Waypoint"),
(@ID*100+0,9,5,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Bessy - On Script - Say Line 0"),

(@ID*100+1,9,0,0,0,0,100,0,0,0,0,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bessy - On Script - Pause Waypoint"),
(@ID*100+1,9,1,0,0,0,100,0,2000,2000,0,0,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Bessy - On Script - Say Line 1"),
(@ID*100+1,9,2,0,0,0,100,0,0,0,0,0,0,107,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Bessy - On Script - Summon Group 0"),

(@ID*100+2,9,0,0,0,0,100,0,0,0,0,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bessy - On Script - Pause Waypoint"),
(@ID*100+2,9,1,0,0,0,100,0,2000,2000,0,0,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Bessy - On Script - Say Line 1"),
(@ID*100+2,9,2,0,0,0,100,0,0,0,0,0,0,107,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Bessy - On Script - Summon Group 1"),

(@ID*100+3,9,0,0,0,0,100,0,1000,1000,0,0,0,15,10337,0,0,0,0,0,16,0,0,0,0,0,0,0,0,"Bessy - On Script - Quest Credit 'When the Cows Come Home'"),
(@ID*100+3,9,1,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,19,20464,0,0,0,0,0,0,0,"Bessy - On Script - Say Line 1 (Thadell)"),
(@ID*100+3,9,2,0,0,0,100,0,4000,4000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bessy - On Script - Despawn (0)");

DELETE FROM `creature_text` WHERE `CreatureID` IN (@ID,20464);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"Mooooo...",12,0,100,0,0,0,18179,0,"Bessy"),
(@ID,1,0,"Moooooooooo!",12,0,100,0,0,0,18180,0,"Bessy"),
(20464,0,0,"Bessy, you're home. Thank the Light!",12,0,100,0,0,0,18181,0,"Thadell");

DELETE FROM `creature_summon_groups` WHERE `summonerId` = 20415;
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`,`summonTime`) VALUES
(20415,0,0,19881,2438.142,2200.449,101.5952,0,4,25000),
(20415,0,1,19881,2279.846,2188.402,91.61183,0,4,25000);

DELETE FROM `script_waypoint` WHERE `entry` = 20415;
DELETE FROM `waypoints` WHERE `entry` IN (20415);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(20415,1,2488.77,2184.89,104.64,"Bessy"),
(20415,2,2478.72,2184.77,98.58,"Bessy"),
(20415,3,2473.52,2184.71,99,"Bessy"),
(20415,4,2453.15,2184.96,97.09,"Bessy"),
(20415,5,2424.18,2184.15,94.11,"Bessy"),
(20415,6,2413.18,2184.15,93.42,"Bessy"),
(20415,7,2402.02,2183.9,87.59,"Bessy"),
(20415,8,2333.31,2181.63,90.03,"Bessy"),
(20415,9,2308.73,2184.34,92.04,"Bessy"),
(20415,10,2303.1,2196.89,94.94,"Bessy"),
(20415,11,2304.58,2272.23,96.67,"Bessy"),
(20415,12,2297.09,2271.4,95.16,"Bessy"),
(20415,13,2297.68,2266.79,95.07,"Bessy");

DELETE FROM `smart_scripts` WHERE `entryorguid` = 19881 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(19881,0,0,0,25,0,100,0,0,0,0,0,0,11,33900,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Severed Spirit - On Reset - Cast 'Shroud of Death'"),
(19881,0,1,0,0,0,100,0,0,0,3400,4800,0,11,20822,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Severed Spirit - In Combat CMC - Cast 'Frostbolt'"),
(19881,0,2,0,0,0,100,0,12000,15000,12000,15000,0,11,11831,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Severed Spirit - In Combat - Cast 'Frost Nova'"),
(19881,0,3,0,54,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Severed Spirit - On Just Summoned - Start Attacking Invoker");
