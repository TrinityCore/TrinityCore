-- Wounded Blood Elf Pilgrim SAI (Source: Sniffs & https://www.youtube.com/watch?v=SyF2WkO_qv0)
SET @ID := 16993;
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN @ID*100+0 AND @ID*100+3 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,19,0,100,0,9375,0,0,0,0,80,@ID*100+0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wounded Blood Elf Pilgrim - On Quest 'The Road to Falcon Watch' Taken - Run Script"),
(@ID,0,1,0,40,0,100,0,12,0,0,0,0,80,@ID*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wounded Blood Elf Pilgrim - On Waypoint 12 Reached - Run Script"),
(@ID,0,2,0,40,0,100,0,18,0,0,0,0,80,@ID*100+2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wounded Blood Elf Pilgrim - On Waypoint 18 Reached - Run Script"),
(@ID,0,3,0,40,0,100,0,36,0,0,0,0,80,@ID*100+3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wounded Blood Elf Pilgrim - On Waypoint 36 Reached - Run Script"),
-- New discovery. Recently noticed in another quest that pause before ambush is permanent or really long but creature resumes
-- waypoint if creatures are killed. Creature even should not be in combat to resume waypoint. Probably valid for mostly
-- all quests where creature resumes waypoint instantly if ambush is killed but in retail probably done in a different way
(@ID,0,4,0,82,0,100,0,0,0,0,0,0,63,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wounded Blood Elf Pilgrim - On Summoned Unit Dies - Set Counter 1 1"),
(@ID,0,5,0,77,0,100,0,1,2,0,0,0,65,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wounded Blood Elf Pilgrim - On Counter Set 1 2 - Resume Waypoint"),
(@ID,0,6,0,77,0,100,0,1,3,0,0,0,65,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wounded Blood Elf Pilgrim - On Counter Set 1 3 - Resume Waypoint"),
(@ID,0,7,0,7,0,100,0,0,0,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wounded Blood Elf Pilgrim - On Evade - Say Line 5"),
(@ID,0,8,0,6,0,100,0,0,0,0,0,0,6,9375,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Wounded Blood Elf Pilgrim - On Death - Fail Quest 'The Road to Falcon Watch'"),

(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,0,64,1,0,0,0,0,0,16,0,0,0,0,0,0,0,0,"Wounded Blood Elf Pilgrim - On Script - Store Targetlist"),
(@ID*100+0,9,1,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Wounded Blood Elf Pilgrim - On Script - Say Line 0"),
(@ID*100+0,9,2,0,0,0,100,0,0,0,0,0,0,2,33,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wounded Blood Elf Pilgrim - On Script - Set Faction 33"),
(@ID*100+0,9,3,0,0,0,100,0,0,0,0,0,0,19,512,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wounded Blood Elf Pilgrim - On Script - Remove Flag Immune To NPC's"),
(@ID*100+0,9,4,0,0,0,100,0,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wounded Blood Elf Pilgrim - On Script - Remove NPC Flag Questgiver"),
(@ID*100+0,9,5,0,0,0,100,0,0,0,0,0,0,9,0,0,0,0,0,0,20,181664,5,0,0,0,0,0,0,"Wounded Blood Elf Pilgrim - On Script - Activate Closest Gameobject (Arakkoa Cage)"),
(@ID*100+0,9,6,0,0,0,100,0,4000,4000,0,0,0,53,0,16993,0,0,0,2,1,0,0,0,0,0,0,0,0,"Wounded Blood Elf Pilgrim - On Script - Start Waypoint"),

(@ID*100+1,9,0,0,0,0,100,0,0,0,0,0,0,54,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wounded Blood Elf Pilgrim - On Script - Pause Waypoint"),
(@ID*100+1,9,1,0,0,0,100,0,1000,1000,0,0,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Wounded Blood Elf Pilgrim - On Script - Say Line 1"),
(@ID*100+1,9,2,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,2.792526721954345703,"Wounded Blood Elf Pilgrim - On Script - Set Orientation"),
(@ID*100+1,9,3,0,0,0,100,0,0,0,0,0,0,107,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wounded Blood Elf Pilgrim - On Script - Summon Group 0"),

(@ID*100+2,9,0,0,0,0,100,0,0,0,0,0,0,54,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wounded Blood Elf Pilgrim - On Script - Pause Waypoint"),
(@ID*100+2,9,1,0,0,0,100,0,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wounded Blood Elf Pilgrim - On Script - Set Flag Standstate Kneel"),
(@ID*100+2,9,2,0,0,0,100,0,2000,2000,0,0,0,1,2,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Wounded Blood Elf Pilgrim - On Script - Say Line 2"),
(@ID*100+2,9,3,0,0,0,100,0,6000,6000,0,0,0,1,3,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Wounded Blood Elf Pilgrim - On Script - Say Line 3"),
(@ID*100+2,9,4,0,0,0,100,0,0,0,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wounded Blood Elf Pilgrim - On Script - Remove Flag Standstate Kneel"),
(@ID*100+2,9,5,0,0,0,100,0,0,0,0,0,0,107,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wounded Blood Elf Pilgrim - On Script - Summon Group 1"),

(@ID*100+3,9,0,0,0,0,100,0,3000,3000,0,0,0,1,4,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Wounded Blood Elf Pilgrim - On Script - Say Line 4"),
(@ID*100+3,9,1,0,0,0,100,0,3000,3000,0,0,0,90,7,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wounded Blood Elf Pilgrim - On Script - Set Flag Standstate Dead"),
(@ID*100+3,9,2,0,0,0,100,0,2000,2000,0,0,0,15,9375,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Wounded Blood Elf Pilgrim - On Script - Quest Credit 'The Road to Falcon Watch'"),
(@ID*100+3,9,3,0,0,0,100,0,1000,1000,0,0,0,90,8,0,0,0,0,0,19,17015,5,0,0,0,0,0,0,"Wounded Blood Elf Pilgrim - On Script - Set Flag Standstate Kneel (Taleris Dawngazer)"),
-- Despawn timer is static
(@ID*100+3,9,4,0,0,0,100,0,0,0,0,0,0,41,15000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wounded Blood Elf Pilgrim - On Script - Delayed Despawn"),
-- But this is random
(@ID*100+3,9,5,0,0,0,100,0,3000,10000,0,0,0,1,4,0,0,0,0,0,19,17015,5,0,0,0,0,0,0,"Wounded Blood Elf Pilgrim - On Script - Say Line 4 (Taleris Dawngazer)"),
-- Probably after 90 sec after stand state was changed
-- Actually he started waypoint after stand state was changed back
-- But quest event and waypoint are not linked together https://www.wowhead.com/quest=9375/the-road-to-falcon-watch#comments:id=22108
(@ID*100+3,9,6,0,0,0,100,0,0,0,0,0,0,91,8,0,0,0,0,0,19,17015,5,0,0,0,0,0,0,"Wounded Blood Elf Pilgrim - On Script - Remove Flag Standstate Kneel (Taleris Dawngazer)");

DELETE FROM `script_waypoint` WHERE `entry` = 16993;
DELETE FROM `waypoints` WHERE `entry` = 16993;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`point_comment`) VALUES
(16993,1,-1142.8721,4251.584,13.990844,0,0,"Wounded Blood Elf Pilgrim"),
(16993,2,-1142.6654,4225.873,14.302933,0,0,"Wounded Blood Elf Pilgrim"),
(16993,3,-1127.3457,4213.2686,13.681648,0,0,"Wounded Blood Elf Pilgrim"),
(16993,4,-1123.6473,4205.012,15.306648,0,0,"Wounded Blood Elf Pilgrim"),
(16993,5,-1106.3356,4201.886,15.931648,0,0,"Wounded Blood Elf Pilgrim"),
(16993,6,-1091.4635,4200.8296,16.861633,0,0,"Wounded Blood Elf Pilgrim"),
(16993,7,-1079.5902,4201.017,16.736633,0,0,"Wounded Blood Elf Pilgrim"),
(16993,8,-1054.9625,4198.346,15.23947,0,0,"Wounded Blood Elf Pilgrim"),
(16993,9,-1021.05664,4189.698,16.392853,0,0,"Wounded Blood Elf Pilgrim"),
(16993,10,-1005.4488,4188.329,17.892853,0,0,"Wounded Blood Elf Pilgrim"),
(16993,11,-973.96027,4187.1616,24.189821,0,0,"Wounded Blood Elf Pilgrim"),
(16993,12,-958.1148,4185.9824,28.001001,0,0,"Wounded Blood Elf Pilgrim"), --
(16993,13,-951.4898,4203.8813,28.501001,0,0,"Wounded Blood Elf Pilgrim"),
(16993,14,-930.9221,4216.787,33.69973,0,0,"Wounded Blood Elf Pilgrim"),
(16993,15,-909.8672,4210.449,40.57473,0,0,"Wounded Blood Elf Pilgrim"),
(16993,16,-888.7264,4206.29,43.77959,0,0,"Wounded Blood Elf Pilgrim"),
(16993,17,-872.3288,4210.7935,44.02959,0,0,"Wounded Blood Elf Pilgrim"),
(16993,18,-859.8309,4218.6274,44.585133,0,0,"Wounded Blood Elf Pilgrim"), --
(16993,19,-846.1649,4213.6157,45.960133,0,0,"Wounded Blood Elf Pilgrim"),
(16993,20,-834.0745,4207.8003,46.210133,0,0,"Wounded Blood Elf Pilgrim"),
(16993,21,-821.51074,4205.953,45.865707,0,0,"Wounded Blood Elf Pilgrim"),
(16993,22,-808.36456,4201.5107,45.240707,0,0,"Wounded Blood Elf Pilgrim"),
(16993,23,-786.70386,4204.6836,44.56842,0,0,"Wounded Blood Elf Pilgrim"),
(16993,24,-766.7725,4208.3335,48.06842,0,0,"Wounded Blood Elf Pilgrim"),
(16993,25,-745.2652,4203.632,48.975666,0,0,"Wounded Blood Elf Pilgrim"),
(16993,26,-724.6917,4197.739,51.617035,0,0,"Wounded Blood Elf Pilgrim"),
(16993,27,-711.9199,4195.3516,54.742035,0,0,"Wounded Blood Elf Pilgrim"),
(16993,28,-698.2872,4191.03,57.38979,0,0,"Wounded Blood Elf Pilgrim"),
(16993,29,-694.41364,4183.7905,57.26479,0,0,"Wounded Blood Elf Pilgrim"),
(16993,30,-690.7885,4173.938,57.88979,0,0,"Wounded Blood Elf Pilgrim"),
(16993,31,-687.70654,4163.2285,59.4882,0,0,"Wounded Blood Elf Pilgrim"),
(16993,32,-683.4334,4152.9424,62.7382,0,0,"Wounded Blood Elf Pilgrim"),
(16993,33,-679.3591,4146.8306,64.363205,0,0,"Wounded Blood Elf Pilgrim"),
(16993,34,-668.8233,4148.17,64.238205,0,0,"Wounded Blood Elf Pilgrim"),
(16993,35,-654.0193,4146.348,64.160675,0,0,"Wounded Blood Elf Pilgrim"),
(16993,36,-650.8255,4138.0034,64.660675,0,0,"Wounded Blood Elf Pilgrim"); --

DELETE FROM `creature_summon_groups` WHERE `summonerId` = 16993 AND `summonerType` = 0;
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`,`summonTime`,`Comment`) VALUES
(16993,0,0,16967,-983.54694,4163.5835,38.25633,0.722505450248718261,4,60000,"Wounded Blood Elf Pilgrim - Group 0 - Haal'eshi Talonguard"),
(16993,0,0,16967,-984.50037,4158.814,41.82977,0.799889922142028808,4,60000,"Wounded Blood Elf Pilgrim - Group 0 - Haal'eshi Talonguard"),
(16993,0,1,16966,-864.00085,4253.1914,43.8939,5.270894527435302734,4,60000,"Wounded Blood Elf Pilgrim - Group 1 - Haal'eshi Windwalker");

DELETE FROM `creature_text` WHERE `CreatureID` = 17015 AND `GroupID` = 4;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(17015,4,0,"Another pilgrim has arrived! Bring water quickly, or we may lose her!",12,1,100,0,0,0,13388,0,"Taleris Dawngazer");
UPDATE `creature_text` SET `comment` = "Wounded Blood Elf Pilgrim" WHERE `CreatureID` = 16993;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 16966 AND `source_type` = 0 AND `id` = 3;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 16967 AND `source_type` = 0 AND `id` = 2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(16966,0,3,0,54,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,19,16993,0,0,0,0,0,0,0,"Haal'eshi Windwalker - On Just Summoned - Start Attack Closest Creature 'Wounded Blood Elf Pilgrim'"),
(16967,0,2,0,54,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,19,16993,0,0,0,0,0,0,0,"Haal'eshi Talonguard - On Just Summoned - Start Attack Closest Creature 'Wounded Blood Elf Pilgrim'");
