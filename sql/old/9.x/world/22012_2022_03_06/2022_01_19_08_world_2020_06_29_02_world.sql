-- Source: CMaNGOS & http://youtube.com/watch?v=1eREORqoCr4 no longer available but some parts are based on it
-- Classic https://www.youtube.com/watch?v=4Mj5tH2goIc
-- Deathstalker Faerleia SAI
SET @ID := 2058;
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN @ID*100+0 AND @ID*100+4 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,19,0,100,0,452,0,0,0,0,80,@ID*100+0,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathstalker Faerleia - On Quest 'Pyrewood Ambush' Taken - Run Script"),

(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,0,64,1,0,0,0,0,0,16,0,0,0,0,0,0,0,0,"Deathstalker Faerleia - On Script - Store Targetlist"),
(@ID*100+0,9,1,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Deathstalker Faerleia - On Script - Say Line 0"),
(@ID*100+0,9,2,0,0,0,100,0,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathstalker Faerleia - On Script - Remove Npc Flag Questgiver"),
(@ID*100+0,9,3,0,0,0,100,0,0,0,0,0,0,2,232,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathstalker Faerleia - On Script - Set Faction 232"),
(@ID*100+0,9,4,0,0,0,100,0,10000,10000,0,0,0,107,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Deathstalker Faerleia - On Script - Summon Group 0"),

(@ID,0,1,0,82,0,100,0,0,0,0,0,0,63,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathstalker Faerleia - On Summoned Unit Dies - Set Counter 1 1"),
(@ID,0,2,0,77,0,100,0,1,1,0,0,0,80,@ID*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathstalker Faerleia - On Counter Set 1 1 - Run Script"),
(@ID,0,3,0,77,0,100,0,1,3,0,0,0,80,@ID*100+2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathstalker Faerleia - On Counter Set 1 3 - Run Script"),
(@ID,0,4,0,77,0,100,0,1,6,0,0,0,80,@ID*100+3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathstalker Faerleia - On Counter Set 1 6 - Run Script"),
(@ID,0,5,0,77,0,100,0,1,9,0,0,0,80,@ID*100+4,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathstalker Faerleia - On Counter Set 1 9 - Run Script"),

(@ID*100+1,9,1,0,0,0,100,0,10000,10000,0,0,0,107,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Deathstalker Faerleia - On Script - Summon Group 1"),
(@ID*100+2,9,1,0,0,0,100,0,10000,10000,0,0,0,107,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Deathstalker Faerleia - On Script - Summon Group 2"),
(@ID*100+3,9,1,0,0,0,100,0,8000,8000,0,0,0,107,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Deathstalker Faerleia - On Script - Summon Group 3"),

(@ID*100+4,9,0,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathstalker Faerleia - On Script - Say Line 1"),
(@ID*100+4,9,1,0,0,0,100,0,0,0,0,0,0,15,452,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Deathstalker Faerleia - On Script - Quest Credit 'Pyrewood Ambush'"),
(@ID*100+4,9,2,0,0,0,100,0,0,0,0,0,0,2,68,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathstalker Faerleia - On Script - Set Faction 68"),
(@ID*100+4,9,3,0,0,0,100,0,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathstalker Faerleia - On Script - Add Npc Flag Questgiver"),
(@ID*100+4,9,5,0,0,0,100,0,0,0,0,0,0,63,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,"Deathstalker Faerleia - On Script - Reset Counter"),
(@ID*100+4,9,6,0,0,0,100,0,0,0,0,0,0,78,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathstalker Faerleia - On Script - Reset All Scripts"),

(@ID,0,6,0,2,0,100,0,0,20,10000,15000,0,11,3359,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathstalker Faerleia - On Health pct - Cast 'Drink Potion'"),
(@ID,0,7,0,6,0,100,0,0,0,0,0,0,6,452,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Deathstalker Faerleia - On Death - Fail Quest 'Pyrewood Ambush'");

UPDATE `creature_text` SET `comment` = "Deathstalker Faerleia" WHERE `CreatureID` = @ID;
-- 548 "All is lost!" - probably used on death

DELETE FROM `creature_summon_groups` WHERE `summonerId` = 2058 AND `summonerType` = 0;
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`,`summonTime`,`Comment`) VALUES
(2058,0,0,2060,-398.35,1510.75,18.87,4.76,4,60000,"Deathstalker Faerleia - Group 0 - Councilman Smithers"),

(2058,0,1,2061,-396.41,1511.06,18.87,4.74,4,60000,"Deathstalker Faerleia - Group 1 - Councilman Thatcher"),
(2058,0,1,2062,-398.35,1510.75,18.87,4.76,4,60000,"Deathstalker Faerleia - Group 1 - Councilman Hendricks"),
-- Not ordered by entry
(2058,0,2,2063,-398.35,1510.75,18.87,4.76,4,60000,"Deathstalker Faerleia - Group 2 - Councilman Wilhelm"),
(2058,0,2,2064,-397.45,1509.56,18.87,4.73,4,60000,"Deathstalker Faerleia - Group 2 - Councilman Hartin"),
(2058,0,2,2066,-396.41,1511.06,18.87,4.74,4,60000,"Deathstalker Faerleia - Group 2 - Councilman Higarth"),

(2058,0,3,2065,-398.35,1510.75,18.87,4.76,4,60000,"Deathstalker Faerleia - Group 3 - Councilman Cooper"),
(2058,0,3,2067,-396.41,1511.06,18.87,4.74,4,60000,"Deathstalker Faerleia - Group 3 - Councilman Brunswick"),
(2058,0,3,2068,-397.45,1509.56,18.87,4.73,4,60000,"Deathstalker Faerleia - Group 3 - Councilman Morrison");
