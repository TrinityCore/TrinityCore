-- https://www.youtube.com/watch?v=8hRSpbomSbE
-- https://www.youtube.com/watch?v=gZpebVIy9yk
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (10638,10720) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1063800 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(10638,0,0,0,19,0,100,0,4966,0,0,0,0,80,1063800,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kanati Greycloud - On Quest 'Protect Kanati Greycloud' Taken - Run Script"),

(1063800,9,0,0,0,0,100,0,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kanati Greycloud - On Script - Remove NPC Flag Questgiver"),
(1063800,9,1,0,0,0,100,0,0,0,0,0,0,19,512,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kanati Greycloud - On Script - Remove Flag Immune To NPC's"),
(1063800,9,2,0,0,0,100,0,0,0,0,0,0,2,250,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kanati Greycloud - On Script - Set Faction 250"),
(1063800,9,3,0,0,0,100,0,0,0,0,0,0,64,1,0,0,0,0,0,16,0,0,0,0,0,0,0,0,"Kanati Greycloud - On Script - Store Targetlist"),
(1063800,9,4,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kanati Greycloud - On Script - Say Line 0"),
(1063800,9,5,0,0,0,100,0,1000,1000,0,0,0,107,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kanati Greycloud - On Script - Summon Group 0"),
(1063800,9,6,0,0,0,100,0,2000,2000,0,0,0,5,15,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kanati Greycloud - On Script - Play Emote 15"),

(10638,0,1,0,82,0,100,0,0,0,0,0,0,63,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kanati Greycloud - On Summoned Unit Dies - Set Counter 1 1"),
(10638,0,2,4,77,0,100,0,1,3,0,0,0,15,4966,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Kanati Greycloud - On Counter Set 1 3 - Quest Credit 'Protect Kanati Greycloud'"),

(10638,0,3,5,7,0,100,0,0,0,0,0,0,18,512,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kanati Greycloud - On Evade - Add Flag Immune To NPC's"),
(10638,0,4,5,61,0,100,0,0,0,0,0,0,18,512,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kanati Greycloud - On Link - Add Flag Immune To NPC's"),
(10638,0,5,6,61,0,100,0,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kanati Greycloud - On Link - Add NPC Flag Questgiver"),
(10638,0,6,7,61,0,100,0,0,0,0,0,0,63,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,"Kanati Greycloud - On Link - Reset Counter"),
(10638,0,7,8,61,0,100,0,0,0,0,0,0,2,104,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kanati Greycloud - On Link - Set Faction 104"),
(10638,0,8,0,61,0,100,0,0,0,0,0,0,78,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kanati Greycloud - On Link - Reset All Scripts"),

(10720,0,0,0,54,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Galak Assassin - On Just Summoned - Start Attacking Owner"),
(10720,0,1,0,0,0,100,0,2000,7000,8000,12000,0,11,6533,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Galak Assassin - In Combat - Cast 'Net'"),
(10720,0,2,0,21,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Galak Assassin - On Reached Home - Despawn (0)");

UPDATE `creature_text` SET `Emote` = 5, `comment` = "Kanati Greycloud" WHERE `CreatureID` = 10638 AND `GroupID` = 0;

DELETE FROM `creature_summon_groups` WHERE `summonerId` = 10638 AND `summonerType` = 0;
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`,`summonTime`,`Comment`) VALUES
(10638,0,0,10720,-4883.433594,-1375.058594,-53.032574,3.471452,4,60000,"Kanati Greycloud - Group 0 - Galak Assassin"),
(10638,0,0,10720,-4883.169434,-1370.379883,-52.236671,2.216390,4,60000,"Kanati Greycloud - Group 0 - Galak Assassin"),
(10638,0,0,10720,-4883.626953,-1383.141357,-53.151230,2.306709,4,60000,"Kanati Greycloud - Group 0 - Galak Assassin");
