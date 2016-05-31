-- 
-- DB/Misc: Elwynn Forest - Movement Update
-- Marshal McBride SAI
SET @ENTRY := 197;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,54,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Marshal McBride - On Quest 'Report to Goldshire' Taken - Say Line 0 (No Repeat)");

DELETE FROM `creature_addon` WHERE `guid` IN (279887,279888,280006,280008,280004,280002,280000,279999,279999,280003,280001,279945,279928,280020,279891, 280016, 280019, 280013, 279998, 279956, 279947, 279938, 279929, 279914, 279916, 279906, 279905, 279894, 279889, 279893);
insert into `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) values 
(280016,0,0,0,0,36,0),(280019,0,0,0,0,36,0),(280013,0,0,0,0,36,0),
(279998,0,0,0,0,36,0),(279956,0,0,0,0,36,0),(279947,0,0,0,0,36,0),
(279938,0,0,0,0,36,0),(279929,0,0,0,0,36,0),(279914,0,0,0,0,36,0),
(279916,0,0,0,0,36,0),(279906,0,0,0,0,36,0),(279905,0,0,0,0,36,0),
(279894,0,0,0,0,36,0),(279889,0,0,0,0,36,0),(279893,0,0,0,0,36,0),
(279891,0,0,0,0,36,0),(280020,0,0,0,0,36,0),(279928,0,0,0,0,36,0),
(279945,0,0,0,0,36,0),(280001,0,0,0,0,36,0),(280003,0,0,0,0,36,0),
(279999,0,0,0,0,36,0),(280000,0,0,0,0,36,0),
(280002,0,0,0,0,36,0),(280004,0,0,0,0,36,0),(280008,0,0,0,0,36,0),
(280006,0,0,0,0,36,0),(279888,0,0,0,0,36,0),(279887,0,0,0,0,36,0);

DELETE FROM `creature_text` WHERE `entry`=49869;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(49869, 0, 0, 'I need a heal!', 12, 0, 100, 0, 0, 0, 49898, 0, 'Infanterist'),
(49869, 0, 1,'HELP!', 12, 0, 100, 0, 0, 0, 49897, 0, 'Infanterist'), 
(49869, 0, 2,'Make yourself useful and heal me!', 12, 0, 100, 0, 0, 0, 49896, 0, 'Infanterist'),
(49869, 0, 3,'I could use a heal, brother!', 12, 0, 100, 0, 0, 0, 49895, 0, 'Infanterist');

-- Stormwind Infantry SAI
SET @GUID := -280020;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=49869;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,10,0,15000,20000,15000,20000,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Stormwind Infantry - Out of Combat - Say Line 0");
 
-- Stormwind Infantry SAI
SET @GUID := -280019;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=49869;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,10,0,15000,20000,15000,20000,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Stormwind Infantry - Out of Combat - Say Line 0");
 
 
-- Stormwind Infantry SAI
SET @GUID := -280001;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=49869;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,10,0,15000,20000,15000,20000,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Stormwind Infantry - Out of Combat - Say Line 0");
 
 
-- Stormwind Infantry SAI
SET @GUID := -280003;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=49869;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,10,0,15000,20000,15000,20000,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Stormwind Infantry - Out of Combat - Say Line 0");
 
 
-- Stormwind Infantry SAI
SET @GUID := -279956;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=49869;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,10,0,15000,20000,15000,20000,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Stormwind Infantry - Out of Combat - Say Line 0");
 
 
-- Stormwind Infantry SAI
SET @GUID := -279945;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=49869;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,10,0,15000,20000,15000,20000,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Stormwind Infantry - Out of Combat - Say Line 0");
 
 
-- Stormwind Infantry SAI
SET @GUID := -279928;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=49869;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,10,0,15000,20000,15000,20000,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Stormwind Infantry - Out of Combat - Say Line 0");
 
 
-- Stormwind Infantry SAI
SET @GUID := -279914;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=49869;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,10,0,15000,20000,15000,20000,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Stormwind Infantry - Out of Combat - Say Line 0");
 
 
-- Stormwind Infantry SAI
SET @GUID := -279906;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=49869;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,10,0,15000,20000,15000,20000,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Stormwind Infantry - Out of Combat - Say Line 0");
 
 
-- Stormwind Infantry SAI
SET @GUID := -279894;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=49869;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,10,0,15000,20000,15000,20000,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Stormwind Infantry - Out of Combat - Say Line 0");
 
 
-- Stormwind Infantry SAI
SET @GUID := -279893;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=49869;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,10,0,15000,20000,15000,20000,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Stormwind Infantry - Out of Combat - Say Line 0");
 
-- Stormwind Infantry SAI
SET @GUID := -279888;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=49869;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,10,0,15000,20000,15000,20000,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Stormwind Infantry - Out of Combat - Say Line 0");
 
 
-- Stormwind Infantry SAI
SET @GUID := -280008;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=49869;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,10,0,15000,20000,15000,20000,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Stormwind Infantry - Out of Combat - Say Line 0");
 
 
-- Stormwind Infantry SAI
SET @GUID := -280002;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=49869;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,10,0,15000,20000,15000,20000,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Stormwind Infantry - Out of Combat - Say Line 0");
 
-- Stormwind Infantry SAI
SET @GUID := -280018;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=49869;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,10,0,15000,20000,15000,20000,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Stormwind Infantry - Out of Combat - Say Line 0");

DELETE FROM `creature_text` WHERE `entry`=50039;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `Textrange`,`comment`) VALUES 
(50039, 0, 0, 'Die!', 12, 0, 100, 0, 0, 0, 72512, 0, 'Goblinischer Auftragsmörder to Player');

-- Goblin Assassin SAI
SET @ENTRY := 50039;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,20,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Goblin Assassin - On Aggro - Say Line 0");

DELETE FROM `creature_addon` WHERE `guid` IN (280023, 280024, 280025, 280010);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(280023, 0, 28912, 0, 0, 0, NULL), 
(280024, 0, 28912, 0, 0, 0, NULL), 
(280025, 0, 28912, 0, 0, 0, NULL),
(280010, 0, 28912, 0, 0, 0, NULL);

-- rndmmovement
UPDATE `creature` SET `spawndist` = 5, `MovementType` = 1 WHERE id =49874;
UPDATE `creature` SET `spawndist` = 5, `MovementType` = 1 WHERE id =49871;
UPDATE `creature` SET `spawndist` = 5, `MovementType` = 1 WHERE id =50039;
UPDATE `creature` SET `spawndist` = 5, `MovementType` = 1 WHERE id =721;
UPDATE `creature` SET `spawndist` = 5, `MovementType` = 1 WHERE id =42937;
UPDATE `creature` SET `spawndist` = 5, `MovementType` = 1 WHERE id =6368;
UPDATE `creature` SET `spawndist` = 5, `MovementType` = 1 WHERE id =2442;
UPDATE `creature` SET `spawndist` = 10, `MovementType` = 1 WHERE id =94;
UPDATE `creature` SET `spawndist`= 5, `MovementType`= 1 WHERE `guid` IN (280094,280095,280099);
UPDATE `creature` SET `spawndist`= 0, `MovementType` = 0 WHERE `guid` IN (280091,280093,280092,280568,280567);
UPDATE `creature` SET `spawndist` = 10, `MovementType` = 1 WHERE id =525;
UPDATE `creature` SET `spawndist`= 0, `MovementType` = 0 WHERE `guid` IN (281592);
UPDATE `creature` SET `spawndist` = 10, `MovementType` = 1 WHERE id =299;
UPDATE `creature` SET `spawndist` = 3, `MovementType` = 1 WHERE id =7384;
UPDATE `creature` SET `spawndist` = 3, `MovementType` = 1 WHERE id =7381;
UPDATE `creature` SET `spawndist` = 3, `MovementType` = 1 WHERE id =7382;
UPDATE `creature` SET `spawndist` = 3, `MovementType` = 1 WHERE id =7385;
UPDATE `creature` SET `spawndist` = 10, `MovementType` = 1 WHERE id =13321;
UPDATE `creature` SET `spawndist` = 10, `MovementType` = 1 WHERE id =113;
UPDATE `creature` SET `spawndist` = 10, `MovementType` = 1 WHERE id =30;
UPDATE `creature` SET `spawndist` = 3, `MovementType` = 1 WHERE id =475;
UPDATE `creature` SET `spawndist` = 5, `MovementType` = 1 WHERE id =49540;
UPDATE `creature` SET `spawndist` = 15, `MovementType` = 1 WHERE id =330;
UPDATE `creature` SET `spawndist` = 3, `MovementType` = 1 WHERE id =40;
UPDATE `creature` SET `spawndist` = 15, `MovementType` = 1 WHERE id =822;
UPDATE `creature` SET `spawndist` = 10, `MovementType` = 1 WHERE id =97;
UPDATE `creature` SET `spawndist` = 20, `MovementType` = 1 WHERE id =1412;
UPDATE `creature` SET `spawndist` = 3, `MovementType` = 1 WHERE id =476;
UPDATE `creature` SET `spawndist` = 3, `MovementType` = 1 WHERE id =43;
UPDATE `creature` SET `spawndist` = 3, `MovementType` = 1 WHERE id =14881;
UPDATE `creature` SET `spawndist` = 10, `MovementType` = 1 WHERE id =116;
UPDATE `creature` SET `spawndist`= 3, `MovementType`= 1 WHERE `guid` IN (281611,281606,280445,280435,280948,280589);
UPDATE `creature` SET `spawndist`= 0, `MovementType` = 0 WHERE `guid` IN (281610,281609,280434,280442,280444,280451,280443,280816,280816,280815,280932,280946,281081);
UPDATE `creature` SET `spawndist` = 10, `MovementType` = 1 WHERE id =1933;
UPDATE `creature` SET `spawndist` = 15, `MovementType` = 1 WHERE id =524;
UPDATE `creature` SET `spawndist` = 10, `MovementType` = 1 WHERE id =735;
UPDATE `creature` SET `spawndist` = 5, `MovementType` = 1 WHERE id =285;
UPDATE `creature` SET `spawndist`= 0, `MovementType` = 0 WHERE `guid` IN (281731,281730,281711,281709,281707,281665,281679,281681,281674);
UPDATE `creature` SET `spawndist` = 10, `MovementType` = 1 WHERE id =1922;
UPDATE `creature` SET `spawndist`= 0, `MovementType` = 0 WHERE `guid` IN (281648,281649,281647,281651);
UPDATE `creature` SET `spawndist` = 10, `MovementType` = 1 WHERE id =478;
UPDATE `creature` SET `spawndist`= 0, `MovementType` = 0 WHERE `guid` IN (280379,280388,280370,280314,281315,281315,281318,281327,281328,281340,281341,281354,281353);
UPDATE `creature` SET `spawndist` = 10, `MovementType` = 1 WHERE id =118;
UPDATE `creature` SET `spawndist` = 0, `MovementType` = 0 WHERE `guid` IN (281458);
UPDATE `creature` SET `spawndist` = 10, `MovementType` = 1 WHERE id =97;
UPDATE `creature` SET `spawndist`= 0, `MovementType` = 0 WHERE `guid` IN (280384,280394,280389,280371,280360,280353,281317,281329,281324,281333,281356,281355);
UPDATE `creature` SET `spawndist` = 3, `MovementType` = 1 WHERE id =46;
UPDATE `creature` SET `spawndist`= 0, `MovementType` = 0 WHERE `guid` IN (280982,280984,280996,280995,280999,280993,280992,281211,281222,281221,281230,281227,281224, 281244,281247,281255,281252,281265,281264,281257,281272,281275,281276);
UPDATE `creature` SET `spawndist` = 3, `MovementType` = 1 WHERE id =732;
UPDATE `creature` SET `spawndist`= 0, `MovementType` = 0 WHERE `guid` IN (280983,280986,280994,280998,280985,280981,280978,281212,281204,281209,281229,281225,281232,281250,281263,281262,281274);
UPDATE `creature` SET `spawndist` = 3, `MovementType` = 1 WHERE id =474;
UPDATE `creature` SET `spawndist`= 0, `MovementType` = 0 WHERE `guid` IN (280581, 280582,280586,280814,281183,281178,281186,281180,281185);
UPDATE `creature` SET `spawndist` = 5, `MovementType` = 1 WHERE id =795;
UPDATE `creature` SET `spawndist` = 5, `MovementType` = 1 WHERE id =796;
UPDATE `creature` SET `spawndist` = 5, `MovementType` = 1 WHERE id =395;
UPDATE `creature` SET `spawndist` = 5, `MovementType` = 1 WHERE id =22985;
UPDATE `creature` SET `spawndist` = 5, `MovementType` = 1 WHERE id =11996;
UPDATE `creature` SET `spawndist` = 10, `MovementType` = 1 WHERE id =119;
UPDATE `creature` SET `MovementType` = 0 WHERE `guid` IN (280016,280013,279998,279999,279947,279938,279929,279916,279905,279889,279891,280000,280004,280006,279887);

-- Pathing for Entry: 1642 'TDB FORMAT'
SET @NPC := 280026;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9051.287,`position_y`=-86.44528,`position_z`=88.10067 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9051.287,-86.44528,88.10067,0,0,0,0,100,0),
(@PATH,2,-9047.261,-96.01211,88.22417,0,0,0,0,100,0),
(@PATH,3,-9037.188,-101.4486,88.13179,0,0,0,0,100,0),
(@PATH,4,-9016.595,-93.06065,87.04225,0,0,0,0,100,0),
(@PATH,5,-9013.705,-90.6391,86.69225,0,0,0,0,100,0),
(@PATH,6,-9021.59,-96.39242,86.98774,0,0,0,0,100,0),
(@PATH,7,-9031.627,-100.3129,87.85693,0,0,0,0,100,0),
(@PATH,8,-9035.828,-101.8916,87.93728,0,0,0,0,100,0),
(@PATH,9,-9046.912,-96.52116,88.25846,0,0,0,0,100,0),
(@PATH,10,-9051.926,-86.24432,88.08818,0,0,0,0,100,0),
(@PATH,11,-9047.582,-67.47964,88.23709,0,0,0,0,100,0),
(@PATH,12,-9046.426,-51.01303,88.61902,0,0,0,0,100,0),
(@PATH,13,-9047.811,-66.24648,88.17001,0,0,0,0,100,0),
(@PATH,14,-9047.791,-66.20093,88.3699,0,0,0,0,100,0),
(@PATH,15,-9051.288,-86.4539,88.10061,0,0,0,0,100,0),
(@PATH,16,-9047.262,-96.00841,88.22412,0,0,0,0,100,0),
(@PATH,17,-9037.172,-101.4573,88.13132,0,0,0,0,100,0),
(@PATH,18,-9016.652,-93.07053,87.04451,0,0,0,0,100,0),
(@PATH,19,-9013.564,-90.72569,86.70216,0,0,0,0,100,0),
(@PATH,20,-9021.59,-96.39242,86.98774,0,0,0,0,100,0),
(@PATH,21,-9031.641,-100.3266,87.85727,0,0,0,0,100,0),
(@PATH,22,-9035.831,-101.893,87.93734,0,0,0,0,100,0),
(@PATH,23,-9047.584,-67.48804,88.23699,0,0,0,0,100,0),
(@PATH,24,-9046.429,-51.03921,88.61877,0,0,0,0,100,0),
(@PATH,25,-9047.811,-66.24648,88.17001,0,0,0,0,100,0),
(@PATH,26,-9047.789,-66.17477,88.37022,0,0,0,0,100,0),
(@PATH,27,-9051.287,-86.45163,88.10062,0,0,0,0,100,0),
(@PATH,28,-9047.262,-96.01085,88.22415,0,0,0,0,100,0),
(@PATH,29,-9037.188,-101.448,88.13183,0,0,0,0,100,0),
(@PATH,30,-9016.657,-93.07131,87.04469,0,0,0,0,100,0),
(@PATH,31,-9013.59,-90.74597,86.70449,0,0,0,0,100,0),
(@PATH,32,-9021.59,-96.39242,86.98774,0,0,0,0,100,0),
(@PATH,33,-9031.615,-100.3,87.85663,0,0,0,0,100,0),
(@PATH,34,-9035.891,-101.9166,87.93845,0,0,0,0,100,0),
(@PATH,35,-9046.97,-96.49335,88.26044,0,0,0,0,100,0),
(@PATH,36,-9051.951,-86.19553,88.08726,0,0,0,0,100,0),
(@PATH,37,-9047.548,-67.57985,88.23885,0,0,0,0,100,0);
-- 0x1C39AC0000019A8000002F00005AED8A .go -9051.287 -86.44528 88.10067

-- Pathing for Entry: 1642 'TDB FORMAT'
SET @NPC := 280011;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9020.053,`position_y`=3.060442,`position_z`=88.74442 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9020.053,3.060442,88.74442,0,0,0,0,100,0),
(@PATH,2,-9011.907,-14.6955,88.55376,0,0,0,0,100,0),
(@PATH,3,-9010.091,-43.59723,87.76579,0,0,0,0,100,0),
(@PATH,4,-9007.952,-67.3993,87.10921,0,0,0,0,100,0),
(@PATH,5,-9007.348,-70.33701,86.96077,0,0,0,0,100,0),
(@PATH,6,-9008.723,-63.47173,87.17122,0,0,0,0,100,0),
(@PATH,7,-9009.347,-39.19754,87.98459,0,0,0,0,100,0),
(@PATH,8,-9009.511,-31.43742,88.43657,0,0,0,0,100,0),
(@PATH,9,-9023.479,3.32865,88.58792,0,0,0,0,100,0),
(@PATH,10,-9024.754,4.297367,88.62678,0,0,0,0,100,0),
(@PATH,11,-9041.181,-21.45232,88.54501,0,0,0,0,100,0),
(@PATH,12,-9043.264,-34.89104,88.35751,0,0,0,0,100,0),
(@PATH,13,-9043.856,-30.38905,88.33578,0,0,0,0,100,0),
(@PATH,14,-9043.569,-30.13401,88.57721,0,0,0,0,100,0),
(@PATH,15,-9007.957,-67.47951,87.11135,0,0,0,0,100,0),
(@PATH,16,-9007.363,-70.47048,86.9617,0,0,0,0,100,0),
(@PATH,17,-9008.723,-63.47173,87.17122,0,0,0,0,100,0),
(@PATH,18,-9009.346,-39.20993,87.9843,0,0,0,0,100,0),
(@PATH,19,-9009.511,-31.43253,88.43684,0,0,0,0,100,0),
(@PATH,20,-9023.475,3.551373,88.58736,0,0,0,0,100,0),
(@PATH,21,-9024.744,4.290416,88.62727,0,0,0,0,100,0),
(@PATH,22,-9035.115,2.4027,88.56686,0,0,0,0,100,0),
(@PATH,23,-9039.956,-7.595201,88.55138,0,0,0,0,100,0),
(@PATH,24,-9041.176,-21.63602,88.54501,0,0,0,0,100,0),
(@PATH,25,-9043.266,-34.90955,88.35751,0,0,0,0,100,0),
(@PATH,26,-9043.856,-30.38905,88.33578,0,0,0,0,100,0),
(@PATH,27,-9043.57,-30.14145,88.57726,0,0,0,0,100,0),
(@PATH,28,-9040.069,-11.13287,88.36223,0,0,0,0,100,0);
-- 0x1C39AC0000019A8000002F0001DAED8A .go -9020.053 3.060442 88.74442
