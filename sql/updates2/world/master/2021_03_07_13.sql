-- DB update 2021_03_07_12 -> 2021_03_07_13
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_03_07_12';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_03_07_12 2021_03_07_13 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1614921496929991300'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1614921496929991300');
-- ----------------------------------------Missing Diplomat Part 11 ---------------------------------------------------

-- The Missing Diplomat Part 11 fixes
UPDATE `quest_template_addon` SET `NextQuestID` = 1250 WHERE `id`=1249;
UPDATE `quest_template_addon` SET `PrevQuestID` = 1250 WHERE `id`=1264;


-- Mikhail
UPDATE `creature_template` SET `AIName`="SmartAI", `ScriptName`="" WHERE `entry`=4963;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4963 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=496300 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(4963,0,0,0,11,0,100,0,0,0,0,0,0,81,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mikhail - On Respawn - Set Npc Flag Questgiver"),
(4963,0,1,0,19,0,100,0,1249,0,0,0,0,81,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mikhail - On Quest 'The Missing Diplomat (Part 11)' Taken - Set Npc Flag Gossip"),
(4963,0,2,0,19,0,100,0,1249,0,0,0,0,45,1,1,0,0,0,0,10,10873,0,0,0,0,0,0,0,"Mikhail - On Quest 'The Missing Diplomat (Part 11)' Taken - Set Data to Tapoke \"Slim\" Jahn"),
(4963,0,3,0,19,0,100,0,1249,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Mikhail - On Quest 'The Missing Diplomat (Part 11)' Taken - Store Target"),
(4963,0,4,0,19,0,100,0,1249,0,0,0,0,100,1,0,0,0,0,0,10,10873,0,0,0,0,0,0,0,"Mikhail - On Quest 'The Missing Diplomat (Part 11)' Taken - Send Target to Tapoke \"Slim\" Jahn"),
(4963,0,5,0,38,0,100,0,1,1,0,0,0,80,496300,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mikhail - On Data Set - Run Script"),
(496300,9,0,0,0,0,100,0,10000,10000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mikhail - On Script - Say Line 0"),
(496300,9,1,0,0,0,100,0,0,0,0,0,0,81,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mikhail - On Script - Set Npc Flag Questgiver");

DELETE FROM `creature_text` WHERE `CreatureID` = 4963;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES 
(4963,0,0,'I\'m glad the commotions died down some around here. The last thing this place needs is another brawl.',12,7,100,0,0,0,4169,0,'Mikhail');


-- Tapoke "Slim" Jahn
UPDATE `creature` SET `spawntimesecs`=10 WHERE `guid`=10873;
UPDATE `creature_template` SET `AIName`="SmartAI", `ScriptName`="" WHERE `entry`=4962;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4962 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=496200 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(4962,0,0,0,38,0,100,1,1,1,0,0,0,11,1785,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tapoke \"Slim\" Jahn - On Data Set - Cast 'Stealth'"),
(4962,0,1,0,38,0,100,1,1,1,0,0,0,53,0,4962,0,0,0,2,1,0,0,0,0,0,0,0,0,"Tapoke \"Slim\" Jahn - On Data Set - Start Waypoint"),
(4962,0,2,0,38,0,100,1,1,1,0,0,0,42,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tapoke \"Slim\" Jahn - On Data Set - Set Invincibility at 1 HP"),
(4962,0,3,0,40,0,100,0,3,4962,0,0,0,28,1785,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tapoke \"Slim\" Jahn - On Waypoint 3 Reached - Remove Aura 'Stealth'"),
(4962,0,4,0,40,0,100,0,3,4962,0,0,0,2,168,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tapoke \"Slim\" Jahn - On Waypoint 3 Reached - Set Faction 168"),
(4962,0,5,0,40,0,100,0,7,4962,0,0,0,6,1249,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Tapoke \"Slim\" Jahn - On Waypoint 7 Reached - Fail Quest 'The Missing Diplomat (Part 11)'"),
(4962,0,6,0,40,0,100,0,7,4962,0,0,0,45,1,1,0,0,0,0,10,9432,0,0,0,0,0,0,0,"Tapoke \"Slim\" Jahn - On Waypoint 7 Reached - Set Data to Mikhail"),
(4962,0,7,0,40,0,100,0,7,4962,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tapoke \"Slim\" Jahn - On Waypoint 7 Reached - Despawn"),
(4962,0,8,0,4,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tapoke \"Slim\" Jahn - On Aggro - Say Line 0"),
(4962,0,9,0,4,0,100,0,0,0,0,0,0,11,16457,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tapoke \"Slim\" Jahn - On Aggro - Cast 'Call Friends'"),
(4962,0,10,0,2,0,100,1,0,20,0,0,0,80,496200,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tapoke \"Slim\" Jahn - Between 0-20% Health - Run Script"),
(496200,9,0,0,0,0,100,0,0,0,0,0,0,45,1,1,0,0,0,0,19,4971,0,0,0,0,0,0,0,"Tapoke \"Slim\" Jahn - On Script - Set Data to Slim's Friend"),
(496200,9,1,0,0,0,100,0,0,0,0,0,0,2,123,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tapoke \"Slim\" Jahn - On Script - Set Faction 123"),
(496200,9,2,0,0,0,100,0,0,0,0,0,0,27,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tapoke \"Slim\" Jahn - On Script - Stop Combat"),
(496200,9,3,0,0,0,100,0,0,0,0,0,0,55,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tapoke \"Slim\" Jahn - On Script - Stop Waypoint Movement"),
(496200,9,4,0,0,0,100,0,0,0,0,0,0,5,20,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tapoke \"Slim\" Jahn - On Script - Play Emote 20"),
(496200,9,5,0,0,0,100,0,5000,5000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tapoke \"Slim\" Jahn - On Script - Say Line 1"),
(496200,9,6,0,0,0,100,0,5000,5000,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tapoke \"Slim\" Jahn - On Script - Say Line 2"),
(496200,9,7,0,0,0,100,0,6000,6000,0,0,0,15,1249,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Tapoke \"Slim\" Jahn - On Script - Complete Quest 'The Missing Diplomat (Part 11)'"),
(496200,9,8,0,0,0,100,0,1000,1000,0,0,0,45,1,1,0,0,0,0,10,9432,0,0,0,0,0,0,0,"Tapoke \"Slim\" Jahn - On Script - Set Data to Mikhail"),
(496200,9,9,0,0,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tapoke \"Slim\" Jahn - On Script - Despawn");

-- Waypoint
DELETE FROM `script_waypoint` WHERE `entry`=4962;
DELETE FROM `waypoints` WHERE `entry`=4962;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(4962,1,-3804.44,-828.048,10.0931,"Tapoke \"Slim\" Jahn"),
(4962,2,-3803.93,-835.772,10.0777,"Tapoke \"Slim\" Jahn"),
(4962,3,-3792.63,-835.671,9.65566,"Tapoke \"Slim\" Jahn"),
(4962,4,-3772.43,-835.346,10.869,"Tapoke \"Slim\" Jahn"),
(4962,5,-3765.94,-840.129,10.8856,"Tapoke \"Slim\" Jahn"),
(4962,6,-3738.63,-830.997,11.0574,"Tapoke \"Slim\" Jahn"),
(4962,7,-3690.22,-862.262,9.96045,"Tapoke \"Slim\" Jahn");

DELETE FROM `creature_text` WHERE `CreatureID` = 4962;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES 
(4962,0,0,'Oh, it\'s on now! Bet you thought I\'d be alone too, huh?!',12,7,100,0,0,0,5827,0,'Tapoke \"Slim\" Jahn'),
(4962,1,0,'Okay, okay! No need to get all violent. I\'ll talk. I\'ll talk!',12,7,100,0,0,0,1743,0,'Tapoke \"Slim\" Jahn'),
(4962,2,0,'I have a few notes from the job back at my place. I\'ll get them and then meet you back in the inn.',12,7,100,0,0,0,1744,0,'Tapoke \"Slim\" Jahn');


-- Slim's Friend
DELETE FROM `smart_scripts` WHERE `entryorguid`=4971 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=497100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(4971,0,0,0,25,0,100,0,0,0,0,0,0,11,3616,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Slim's Friend - On Reset - Cast 'Poison Proc'"),
(4971,0,1,0,25,0,100,0,0,0,0,0,0,11,8601,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Slim's Friend - On Reset - Cast 'Slowing Poison'"),
(4971,0,2,0,67,0,100,0,3000,6000,0,0,0,11,2589,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Slim's Friend - On Behind Target - Cast Backstab"),
(4971,0,3,0,38,0,100,1,1,1,0,0,0,80,497100,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Slim's Friend - On Data Set - Run Script"),
(497100,9,0,0,0,0,100,0,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Slim's Friend - On Script - Evade"),
(497100,9,1,0,0,0,100,0,0,0,0,0,0,2,123,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Slim's Friend - On Script - Set Faction 123"),
(497100,9,2,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Slim's Friend - On Script - Say Line 0"),
(497100,9,3,0,0,0,100,0,6000,6000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Slim's Friend - On Script - Despawn");

DELETE FROM `creature_text` WHERE `CreatureID` = 4971;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES 
(4971,0,0,'Whoa! This is way more than what I bargained for, you\'re on your own, Slim!',12,7,100,0,0,0,5828,0,'Slim\'s Friend');


-- --------------------------------------------Missing Diplomat Part 14 - 16 ------------------------------------------
-- The Missing Diplomat Part 16 Quest DB Error fix
UPDATE `quest_template_addon` SET `SpecialFlags` = 2 WHERE `ID` = 1324;


-- Quest emotes fix
UPDATE `quest_offer_reward` SET `Emote3` = 0,`Emote4` = 0 WHERE `ID` = 1266;
DELETE FROM `quest_details` WHERE `ID` = 1324;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES 
(1324,5,14,0,0,0,0,0,0,12340);


-- Private Hendel
UPDATE `creature_template` SET `AIName` = "SmartAI",`ScriptName` = "" WHERE `entry` = 4966;
DELETE FROM `creature_text` WHERE `CreatureID` = 4966;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES 
(4966,0,0,'%s obviously beaten, tries to run.',16,0,100,0,0,0,8225,0,'Private Hendel'),
(4966,1,0,'%s, too injured, gives up the chase.',16,0,100,0,0,0,8224,0,'Private Hendel'),
(4966,2,0,'Please... please... Miss Proudmore. I didn\'t mean to...',12,7,100,0,0,0,1759,0,'Private Hendel');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (4966,496600,496601,496602);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(4966,0,0,1,11,0,100,0,0,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Private Hendel - On Spawn - Normal Emote'),
(4966,0,1,2,61,0,100,0,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Private Hendel - Linked - Add NPC Flag Questgiver'),
(4966,0,2,0,61,0,100,0,0,0,0,0,0,42,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Private Hendel - Linked - Reset Invincibility HP'),
(4966,0,3,0,19,0,100,0,1324,0,0,0,0,80,496600,2,0,0,0,0,1,0,0,0,0,0,0,0,0,'Private Hendel - On Quest \'The Missing Diplomat (Part 16)\' Taken - Run Script'),
(4966,0,4,0,2,1,100,1,0,20,0,0,0,80,496601,2,0,0,0,0,1,0,0,0,0,0,0,0,0,'Private Hendel - Between 0-20% Health - Run Script (Phase 1) (No Repeat)'),
(4966,0,5,0,40,2,100,0,1,496600,0,0,0,80,496602,2,0,0,0,0,1,0,0,0,0,0,0,0,0,'Private Hendel - On Waypoint 1 Reached - Run Script (Phase 2)'),
(496600,9,0,0,0,0,100,0,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Private Hendel - On Script - Remove NPC Flag Questgiver'),
(496600,9,1,0,0,0,100,0,0,0,0,0,0,42,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Private Hendel - On Script - Set Invincibility 1 HP'),
(496600,9,2,0,0,0,100,0,0,0,0,0,0,2,168,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Private Hendel - On Script - Set Faction 168'),
(496600,9,3,0,0,0,100,0,0,0,0,0,0,45,1,1,0,0,0,0,11,5184,50,0,0,0,0,0,0,'Private Hendel - On Script - Set Data 1 to Theramore Sentry'),
(496600,9,4,0,0,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,'Private Hendel - On Script - Start Attacking'),
(496600,9,5,0,0,0,100,0,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,'Private Hendel - On Script - Store Targetlist'),
(496600,9,6,0,0,0,100,0,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Private Hendel - On Script - Set Event Phase 1'),
(496601,9,0,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Private Hendel - On Script - Say Line 0'),
(496601,9,1,0,0,0,100,0,0,0,0,0,0,27,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Private Hendel - On Script - Stop Attack'),
(496601,9,2,0,0,0,100,0,0,0,0,0,0,2,1077,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Private Hendel - On Script - Set Faction 1077'),
(496601,9,3,0,0,0,100,0,0,0,0,0,0,53,1,496600,0,0,0,2,1,0,0,0,0,0,0,0,0,'Private Hendel - On Script - Start Waypoint'),
(496601,9,4,0,0,0,100,0,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Private Hendel - On Script - Set Event Phase 2'),
(496602,9,0,0,0,0,100,0,2000,2000,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0.277231,'Private Hendel - On Script - Set Orientation'),
(496602,9,1,0,0,0,100,0,0,0,0,0,0,89,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Private Hendel - On Script - Stop Random Movement'),
(496602,9,2,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Private Hendel - On Script - Say Line 1'),
(496602,9,3,0,0,0,100,0,0,0,0,0,0,17,64,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Private Hendel - On Script - Set Emote State 64'),
(496602,9,4,0,0,0,100,0,0,0,0,0,0,45,2,2,0,0,0,0,11,5184,50,0,0,0,0,0,0,'Private Hendel - On Script - Set Data 2 to Theramore Sentry'),
(496602,9,5,0,0,0,100,0,0,0,0,0,0,107,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Private Hendel - On Script - Summon Group 1'),
(496602,9,6,0,0,0,100,0,0,0,0,0,0,45,1,1,0,0,0,0,19,4967,0,0,0,0,0,0,0,'Private Hendel - On Script - Set Data 1 1 (Archmage Tervosh)'),
(496602,9,7,0,0,0,100,0,0,0,0,0,0,100,1,0,0,0,0,0,19,4967,0,0,0,0,0,0,0,'Private Hendel - On Script - Send Target (Archmage Tervosh)');

DELETE FROM `waypoints` WHERE `entry` = 496600;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(496600,1,-2895.49,-3350.66,31.2543,'Private Hendel');

DELETE FROM `creature_summon_groups` WHERE `summonerId` = 4966;
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`,`summonTime`) VALUES
(4966,0,1,4967,-2882.55,-3345.43,33.7722,3.39919,3,90000),
(4966,0,1,4968,-2880.52,-3346.8,34.5063,3.36777,3,90000),
(4966,0,1,4965,-2881.22,-3343.22,34.1732,3.52487,3,90000);


-- Archmage Tervosh
UPDATE `creature_template` SET `ScriptName` = "" WHERE `entry` = 4967;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (4967,496700);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(4967,0,0,0,0,0,100,0,0,0,3000,5000,0,11,20822,64,0,0,0,0,2,0,0,0,0,0,0,0,0,'Archmage Tervosh - In Combat - Cast \'Frostbolt\''),
(4967,0,1,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'Archmage Tervosh - Between 0-15% Health - Flee For Assist'),
(4967,0,2,3,20,0,100,0,1265,0,0,0,0,11,7120,0,0,0,0,0,7,0,0,0,0,0,0,0,0,'Archmage Tervosh - On Quest \'The Missing Diplomat\' Finished - Cast Proudmoore\'s Defense'),
(4967,0,3,0,61,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,'Archmage Tervosh - On Quest \'The Missing Diplomat\' Finished - Say Line 0'),
(4967,0,4,0,0,0,100,0,6000,8000,12000,14000,0,11,20823,0,0,0,0,0,2,0,0,0,0,0,0,0,0,'Archmage Tervosh - In Combat - Cast \'Fireball\''),
(4967,0,5,0,38,0,100,1,1,1,0,0,0,80,496700,2,0,0,0,0,1,0,0,0,0,0,0,0,0,'Archmage Tervosh - On Data Set - Run Script'),
(496700,9,0,0,0,0,100,0,0,0,0,0,0,11,51347,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Archmage Tervosh - On Script - Cast \'Teleport Visual Only\''),
(496700,9,1,0,0,0,100,0,0,0,0,0,0,86,51347,0,19,4965,0,0,1,0,0,0,0,0,0,0,0,'Archmage Tervosh - On Script - Cross Cast \'Teleport Visual Only\''),
(496700,9,2,0,0,0,100,0,0,0,0,0,0,86,51347,0,19,4968,0,0,1,0,0,0,0,0,0,0,0,'Archmage Tervosh - On Script - Cross Cast \'Teleport Visual Only\''),
(496700,9,3,0,0,0,100,0,4000,4000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Archmage Tervosh - On Script - Say Line 1'),
(496700,9,4,0,0,0,100,0,3000,3000,0,0,0,11,7081,0,0,0,0,0,19,4966,0,0,0,0,0,0,0,'Archmage Tervosh - On Script - Cast \'Encage\''),
(496700,9,5,0,0,0,100,0,4000,4000,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Archmage Tervosh - On Script - Say Line 2'),
(496700,9,6,0,0,0,100,0,5000,5000,0,0,0,1,2,0,0,0,0,0,19,4966,0,0,0,0,0,0,0,'Archmage Tervosh - On Script - Say Line 2 (Private Hendel)'),
(496700,9,7,0,0,0,100,0,3000,3000,0,0,0,11,7079,0,0,0,0,0,19,4966,0,0,0,0,0,0,0,'Archmage Tervosh - On Script - Cast \'Simple Teleport Other\''),
(496700,9,8,0,0,0,100,0,2000,2000,0,0,0,41,0,0,0,0,0,0,19,4966,0,0,0,0,0,0,0,'Archmage Tervosh - On Script - Despawn (Private Hendel)'),
(496700,9,9,0,0,0,100,0,2000,2000,0,0,0,15,1324,0,0,0,0,0,12,1,0,0,0,0,0,0,0,'Archmage Tervosh - On Script - Complete Quest \'The Missing Diplomat (Part 16)\''),
(496700,9,10,0,0,0,100,0,1000,1000,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Archmage Tervosh - On Script - Say Line 2'),
(496700,9,11,0,0,0,100,0,6000,6000,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Archmage Tervosh - On Script - Say Line 3');

DELETE FROM `creature_text` WHERE `CreatureID` = 4967;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES 
(4967,0,0,'Go with grace, and may the Lady\'s magic protect you.',12,0,100,0,0,0,1751,0,'Archmage Tervosh - On Quest \'The Missing Diplomat\' Finished'),
(4967,1,0,'Ah, Private Hendel. A pleasure to meet one of the men who would betray his kingdom for pride.',12,7,100,0,0,0,1657,0,'Archmage Tervosh'),
(4967,2,0,'Why don\'t we deal with you now, Hendel? Lady Proudmoore will speak to you back in the tower.',12,7,100,0,0,0,1663,0,'Archmage Tervosh'),
(4967,3,0,'I apologize for taking so long to get here. I wanted Lady Proudmoore to be present also.',12,7,100,0,0,0,1761,0,'Archmage Tervosh'),
(4967,4,0,'We can only stay a few moments before returning to the tower. If you wish to speak to us more you may find us there.',12,7,100,0,0,0,1808,0,'Archmage Tervosh');


-- Theramore Sentry
UPDATE `creature` SET `modelid` = 0,`wander_distance` = 5,`MovementType` = 1 WHERE `guid` IN (31271,31268);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-31271,-31268,518400,518401);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(-31271,0,0,0,38,0,100,1,1,1,0,0,0,2,168,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Theramore Sentry - On Data 1 Set - Set Faction 168'),
(-31271,0,1,0,38,0,100,1,1,1,0,0,0,49,0,0,0,0,0,0,21,50,0,0,0,0,0,0,0,'Theramore Sentry - On Data 1 Set - Start Attacking'),
(-31271,0,2,0,38,0,100,1,2,2,0,0,0,80,518400,2,0,0,0,0,1,0,0,0,0,0,0,0,0,'Theramore Sentry - On Data 2 Set - Run Script'),
(-31271,0,3,0,40,0,100,0,2,518400,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Theramore Sentry - On Waypoint 2 Reached - Despawn'),
(-31268,0,0,0,38,0,100,1,1,1,0,0,0,2,168,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Theramore Sentry - On Data Set - Set Faction 168'),
(-31268,0,1,0,38,0,100,1,1,1,0,0,0,49,0,0,0,0,0,0,21,50,0,0,0,0,0,0,0,'Theramore Sentry - On Data Set - Start Attacking'),
(-31268,0,2,0,38,0,100,1,2,2,0,0,0,80,518401,2,0,0,0,0,1,0,0,0,0,0,0,0,0,'Theramore Sentry - On Data 2 Set - Run Script'),
(-31268,0,3,0,40,0,100,0,3,518401,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Theramore Sentry - On Waypoint 3 Reached - Despawn'),
(518400,9,0,0,0,0,100,0,1000,1000,0,0,0,2,150,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Theramore Sentry - On Script - Set Faction 150'),
(518400,9,1,0,0,0,100,0,0,0,0,0,0,27,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Theramore Sentry - On Script - Stop Attack'),
(518400,9,2,0,0,0,100,0,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Theramore Sentry - On Script - Evade'),
(518400,9,3,0,0,0,100,0,0,0,0,0,0,53,1,518400,0,0,0,2,1,0,0,0,0,0,0,0,0,'Theramore Sentry - On Script - Start Waypoint'),
(518400,9,4,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Theramore Sentry - On Script - Say Line 0'),
(518401,9,0,0,0,0,100,0,1000,1000,0,0,0,2,150,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Theramore Sentry - On Script - Set Faction 150'),
(518401,9,1,0,0,0,100,0,0,0,0,0,0,27,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Theramore Sentry - On Script - Stop Attack'),
(518401,9,2,0,0,0,100,0,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Theramore Sentry - On Script - Evade'),
(518401,9,3,0,0,0,100,0,0,0,0,0,0,53,1,518401,0,0,0,2,1,0,0,0,0,0,0,0,0,'Theramore Sentry - On Script - Start Waypoint'),
(518401,9,4,0,0,0,100,0,1000,1000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Theramore Sentry - On Script - Say Line 1');

DELETE FROM `waypoints` WHERE `entry` IN (518400,518401);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(518400,1,-2906.15,-3345.12,31.3324,'Theramore Sentry'),
(518400,2,-2910.64,-3353.77,30.4347,'Theramore Sentry'),
(518401,1,-2897.26,-3330.35,33.442,'Theramore Sentry'),
(518401,2,-2908.55,-3336.71,32.0493,'Theramore Sentry'),
(518401,3,-2914.51,-3346.08,30.843,'Theramore Sentry');

DELETE FROM `creature_text` WHERE `CreatureID` = 5184;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES 
(5184,0,0,'It\'s Proudmoore! Get out of here!',12,7,100,0,0,0,7325,0,'Theramore Sentry'),
(5184,1,0,'Run!',12,7,100,0,0,0,7324,0,'Theramore Sentry'),
(5184,1,1,'Get out of here!',12,7,100,0,0,0,7340,0,'Theramore Sentry'),
(5184,1,2,'Don\'t let them catch you!',12,7,100,0,0,0,7341,0,'Theramore Sentry'),
(5184,1,3,'She\'ll have our heads if we\'re caught!',12,7,100,0,0,0,7342,0,'Theramore Sentry');


-- Sentry Point Guard
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 5085;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (5085,508500,-8459);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(5085,0,0,0,25,0,100,0,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Sentry Point Guard - On Reset  - Set Event Phase 1'),
(5085,0,1,0,75,1,100,0,0,4967,10,7000,0,80,508500,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Sentry Point Guard - On Creature  - Run Script'),
(508500,9,0,0,1,0,100,0,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Sentry Point Guard - On Script - Set Event Phase 1'),
(508500,9,1,0,1,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,19,4967,10,0,0,0,0,0,0,'Sentry Point Guard - On Script - Set Orientation'),
(508500,9,2,0,1,0,100,0,2000,2000,0,0,0,5,66,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Sentry Point Guard - On Script - Set Emote 66'),
(508500,9,3,0,1,0,100,0,6000,6000,0,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Sentry Point Guard - On Script - Set Orientation'),
(508500,9,4,0,1,0,100,0,48000,48000,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Sentry Point Guard - On Script - Set Event Phase 0');


-- Sentry Point Guard Waypoints and fixes
UPDATE `creature` SET `MovementType` = 2 WHERE `guid` = 30810;

DELETE FROM `creature_addon` WHERE `guid` = 30810;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`isLarge`,`auras`) VALUES
(30810,308100,0,0,4097,0,0,NULL);

DELETE FROM `waypoint_data` WHERE `id` = 308100;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES 
(308100,1,-3456.43,-4108.1,16.9424,0,0,0,0,100,0),
(308100,2,-3458.7,-4098.34,16.9646,0,0,0,0,100,0),
(308100,3,-3465.68,-4090.36,16.9788,0,0,0,0,100,0),
(308100,4,-3478.25,-4088.28,16.9719,0,0,0,0,100,0),
(308100,5,-3490.27,-4094.47,16.8542,0,0,0,0,100,0),
(308100,6,-3495.15,-4109.32,16.8756,0,0,0,0,100,0),
(308100,7,-3489.86,-4121.28,17.0226,0,0,0,0,100,0),
(308100,8,-3477.16,-4127.29,16.9396,0,0,0,0,100,0),
(308100,9,-3462.6,-4124.12,16.9646,0,0,0,0,100,0),
(308100,10,-3455.44,-4131.08,15.0387,0,0,0,0,100,0),
(308100,11,-3462.6,-4124.12,16.9646,0,0,0,0,100,0),
(308100,12,-3477.16,-4127.29,16.9396,0,0,0,0,100,0),
(308100,13,-3489.86,-4121.28,17.0226,0,0,0,0,100,0),
(308100,14,-3495.15,-4109.32,16.8756,0,0,0,0,100,0),
(308100,15,-3490.27,-4094.47,16.8542,0,0,0,0,100,0),
(308100,16,-3478.25,-4088.28,16.9719,0,0,0,0,100,0),
(308100,17,-3465.68,-4090.36,16.9788,0,0,0,0,100,0),
(308100,18,-3458.7,-4098.34,16.9646,0,0,0,0,100,0),
(308100,19,-3456.43,-4108.1,16.9424,0,0,0,0,100,0),
(308100,20,-3459.41,-4117.53,16.9646,0,0,0,0,100,0);

-- Guard POS Update
UPDATE `creature` SET `position_x` = -3468.0843,`position_y` = -4104.929,`position_z` = 41.107,`orientation` = 3.492 WHERE guid = 30816;

-- Captain Waymor
UPDATE `creature` SET `orientation` = 4.88 WHERE `guid` = 8457;


-- North Point Tower - Theramore Guards Waypoints
UPDATE `creature` SET `MovementType` = 2,`wander_distance` = 0 WHERE `guid` = 33893;

DELETE FROM `creature_addon` WHERE `guid` = 33893;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`isLarge`,`auras`) VALUES
(33893,338930,0,0,4097,0,0,NULL);

DELETE FROM `waypoint_data` WHERE `id` = 338930;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES 
(338930,1,-2905.33,-3435.32,39.9603,0,0,0,0,100,0),
(338930,2,-2899.78,-3442.42,40.0815,0,0,0,0,100,0),
(338930,3,-2893.39,-3445.42,39.9894,0,0,0,0,100,0),
(338930,4,-2885.39,-3445.89,40.0582,0,0,0,0,100,0),
(338930,5,-2876.09,-3441.79,39.9866,0,0,0,0,100,0),
(338930,6,-2870.97,-3435.44,40.0388,0,0,0,0,100,0),
(338930,7,-2869.72,-3429.29,40.048,0,0,0,0,100,0),
(338930,8,-2871.23,-3419.87,40.048,0,0,0,0,100,0),
(338930,9,-2877.86,-3412.21,40.0421,0,0,0,0,100,0),
(338930,10,-2888.74,-3410.04,40.0411,0,0,0,0,100,0),
(338930,11,-2897.26,-3412.51,40.0645,0,0,0,0,100,0),
(338930,12,-2903.72,-3418.18,40.017,0,0,0,0,100,0),
(338930,13,-2906.33,-3425.31,40.0162,0,0,0,0,100,0);

UPDATE `creature` SET `orientation` = 0.039 WHERE `guid` = 33895;

UPDATE `creature` SET `MovementType` = 2 WHERE `guid` = 33988;

DELETE FROM `creature_addon` WHERE `guid` = 33988;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`isLarge`,`auras`) VALUES
(33988,339880,0,0,4097,0,0,NULL);

DELETE FROM `waypoint_data` WHERE `id` = 339880;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES 
(339880,1,-2890.87,-3421.01,74.4463,0,10000,0,0,100,0),
(339880,2,-2889.81,-3424,74.4304,0,0,0,0,100,0),
(339880,3,-2886.89,-3431.63,68.8635,0,0,0,0,100,0),
(339880,4,-2883.69,-3432.35,68.8632,0,0,0,0,100,0),
(339880,5,-2881.05,-3427.56,66.8511,0,0,0,0,100,0),
(339880,6,-2882.24,-3422.5,64.44,0,0,0,0,100,0),
(339880,7,-2884.42,-3421.01,63.4094,0,0,0,0,100,0),
(339880,8,-2891.6,-3420.3,63.1928,0,0,0,0,100,0),
(339880,9,-2894.5,-3422.34,61.3742,0,0,0,0,100,0),
(339880,10,-2896.25,-3427.01,58.6742,0,0,0,0,100,0),
(339880,11,-2894.06,-3434.03,58.6045,0,0,0,0,100,0),
(339880,12,-2889.64,-3436.63,55.9873,0,0,0,0,100,0),
(339880,13,-2883.76,-3435.69,53.067,0,0,0,0,100,0),
(339880,14,-2879.35,-3430.94,52.9223,0,0,0,0,100,0),
(339880,15,-2878.35,-3427.05,50.965,0,0,0,0,100,0),
(339880,16,-2879.3,-3423.19,49.2916,0,0,0,0,100,0),
(339880,17,-2881.97,-3420.16,47.2928,0,0,0,0,100,0),
(339880,18,-2889.17,-3417.8,46.7486,0,0,0,0,100,0),
(339880,19,-2894.42,-3420.39,44.1282,0,0,0,0,100,0),
(339880,20,-2896.7,-3424.19,44.1198,0,0,0,0,100,0),
(339880,21,-2897.57,-3428.99,42.1217,0,0,0,0,100,0),
(339880,22,-2894.54,-3434.74,39.3619,0,0,0,0,100,0),
(339880,23,-2888.88,-3434.01,39.3582,0,0,0,0,100,0),
(339880,24,-2880.31,-3425.55,39.3549,0,0,0,0,100,0),
(339880,25,-2872.39,-3424.52,39.3517,0,10000,0,0,100,0),
(339880,26,-2880.4,-3426.19,39.3532,0,0,0,0,100,0),
(339880,27,-2887.3,-3433.28,39.3555,0,0,0,0,100,0),
(339880,28,-2892.93,-3432.99,39.4073,0,0,0,0,100,0),
(339880,29,-2897.05,-3431.31,41.1585,0,0,0,0,100,0),
(339880,30,-2897.92,-3426.75,42.9612,0,0,0,0,100,0),
(339880,31,-2896.77,-3423.87,44.1282,0,0,0,0,100,0),
(339880,32,-2894.23,-3420.42,44.1284,0,0,0,0,100,0),
(339880,33,-2892.68,-3418.86,45.4239,0,0,0,0,100,0),
(339880,34,-2888.74,-3417.84,46.788,0,0,0,0,100,0),
(339880,35,-2882.41,-3419.79,47.2422,0,0,0,0,100,0),
(339880,36,-2879.51,-3422.97,49.158,0,0,0,0,100,0),
(339880,37,-2878.85,-3428.03,51.3309,0,0,0,0,100,0),
(339880,38,-2880.01,-3431.39,53.0185,0,0,0,0,100,0),
(339880,39,-2883.93,-3435.23,53.0676,0,0,0,0,100,0),
(339880,40,-2887.65,-3437.12,54.9482,0,0,0,0,100,0),
(339880,41,-2891.7,-3436.23,57.023,0,0,0,0,100,0),
(339880,42,-2893.96,-3433.69,58.6146,0,0,0,0,100,0),
(339880,43,-2896.18,-3426.95,58.6731,0,0,0,0,100,0),
(339880,44,-2895.73,-3423.92,60.3482,0,0,0,0,100,0),
(339880,45,-2891.62,-3420.81,63.1991,0,0,0,0,100,0),
(339880,46,-2889.61,-3420.21,63.3588,0,0,0,0,100,0),
(339880,47,-2884.92,-3421.07,63.3588,0,0,0,0,100,0),
(339880,48,-2881.79,-3423.6,65.1294,0,0,0,0,100,0),
(339880,49,-2880.99,-3427.01,66.6605,0,0,0,0,100,0),
(339880,50,-2881.9,-3430.48,68.0874,0,0,0,0,100,0),
(339880,51,-2883.9,-3432.35,68.8631,0,0,0,0,100,0),
(339880,52,-2885.51,-3433.05,68.8631,0,0,0,0,100,0),
(339880,53,-2887.05,-3431.72,68.8636,0,0,0,0,100,0),
(339880,54,-2889.99,-3423.89,74.4466,0,0,0,0,100,0),
(339880,55,-2890.92,-3421.04,74.4466,0,0,0,0,100,0);


-- Orientation fixes
UPDATE `creature` SET `orientation` = 2.44 WHERE `guid` = 31323;
UPDATE `creature` SET `orientation` = 0.181 WHERE `guid` = 31324;

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
