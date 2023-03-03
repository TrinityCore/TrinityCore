-- DB update 2021_03_20_00 -> 2021_03_20_01
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_03_20_00';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_03_20_00 2021_03_20_01 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1615704736281325400'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1615704736281325400');
-- --------------------------------------------------------------------- Stranglethorn Fever ------------------------------------------------------
-- Witch Doctor Unbagwa
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1449 AND `source_type` = 0 AND `id` BETWEEN 1 AND 6;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 144900 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1449,0,1,2,38,0,100,0,1,1,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witch Doctor Unbagwa - On Data 1 1 Set - Restore Faction"),
(1449,0,2,3,61,0,100,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witch Doctor Unbagwa - On Data 1 1 Set - Add Questgiver Flag"),
(1449,0,3,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witch Doctor Unbagwa - On Data 1 1 Set - Set Phase 1"),
(1449,0,4,5,25,1,100,0,0,0,0,0,5,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witch Doctor Unbagwa - On Reset - Play Emote 'Cheer' (Phase 1)"),
(1449,0,5,6,61,1,100,0,0,0,0,0,4,2859,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witch Doctor Unbagwa - On Reset - Play Sound (Phase 1)"),
(1449,0,6,0,61,1,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witch Doctor Unbagwa - On Reset - Set Phase 0 (Phase 1)"),
(144900,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witch Doctor Unbagwa - On Script - Say Line 0"),
(144900,9,1,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witch Doctor Unbagwa - On Script - Remove Questgiver Flag"),
(144900,9,2,0,0,0,100,0,0,0,0,0,2,495,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witch Doctor Unbagwa - On Script - Change Faction"),
(144900,9,3,0,0,0,100,0,5000,5000,0,0,11,12380,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witch Doctor Unbagwa - On Script - Cast 'Shadow Channeling'"),
(144900,9,4,0,0,0,100,0,15000,15000,0,0,12,1511,3,300000,1,0,0,8,0,0,0,-13813.45,8.700467,27.33867,6.063402,"Witch Doctor Unbagwa - On Script - Summon Creature 'Enraged Silverback Gorilla'"),
(144900,9,5,0,0,0,100,0,20000,20000,0,0,12,1516,3,300000,1,0,0,8,0,0,0,-13813.45,8.700467,27.33867,6.063402,"Witch Doctor Unbagwa - On Script - Summon Creature 'Konda'"),
(144900,9,6,0,0,0,100,0,20000,20000,0,0,12,1514,3,300000,1,0,0,8,0,0,0,-13813.45,8.700467,27.33867,6.063402,"Witch Doctor Unbagwa - On Script - Summon Creature 'Mokk the Savage'"),
(144900,9,7,0,0,0,100,0,60000,60000,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witch Doctor Unbagwa - On Script - Add Questgiver Flag"),
(144900,9,8,0,0,0,100,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witch Doctor Unbagwa - On Script - Restore Faction");

UPDATE `creature_template` SET `AIName`="SmartAI",`flags_extra` = 64 WHERE `entry` IN (1511,1516,1514);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1511,1516,1514) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1511,0,0,1,11,0,100,0,0,0,0,0,53,1,1511,0,0,0,0,1,0,0,0,0,0,0,0,"Enraged Silverback Gorilla - On Spawn - Start Waypoint"),
(1511,0,1,0,61,0,100,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Enraged Silverback Gorilla - On Spawn - Set Reactstate Aggressive"),
(1511,0,2,3,2,0,100,1,0,30,0,0,11,8269,1,0,0,0,0,1,0,0,0,0,0,0,0,"Enraged Silverback Gorilla - Between 0-30% Health - Cast 'Frenzy' (No Repeat)"),
(1511,0,3,0,61,0,100,0,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Enraged Silverback Gorilla - Between 0-30% Health - Say Line 0"),
(1516,0,0,1,11,0,100,0,0,0,0,0,53,1,1516,0,0,0,0,1,0,0,0,0,0,0,0,"Konda - On Spawn - Start Waypoint"),
(1516,0,1,0,61,0,100,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Konda - On Spawn - Set Reactstate Aggressive"),
(1516,0,2,3,2,0,100,1,0,30,0,0,11,8269,1,0,0,0,0,1,0,0,0,0,0,0,0,"Konda - Between 0-30% Health - Cast 'Frenzy' (No Repeat)"),
(1516,0,3,0,61,0,100,0,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Konda - Between 0-30% Health - Say Line 0"),
(1514,0,0,1,11,0,100,0,0,0,0,0,53,1,1514,0,0,0,0,1,0,0,0,0,0,0,0,"Mokk the Savage - On Spawn - Start Waypoint"),
(1514,0,1,0,61,0,100,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mokk the Savage - On Spawn - Set Reactstate Aggressive"),
(1514,0,2,3,2,0,100,1,0,30,0,0,11,8269,1,0,0,0,0,1,0,0,0,0,0,0,0,"Mokk the Savage - Between 0-30% Health - Cast 'Frenzy' (No Repeat)"),
(1514,0,3,0,61,0,100,0,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mokk the Savage - Between 0-30% Health - Say Line 0"),
(1514,0,4,0,6,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,1449,0,0,0,0,0,0,"Mokk the Savage - On Death - Set Data 1 1 (Witch Doctor Unbagwa)");

DELETE FROM `creature_text` WHERE `CreatureID` = 1449;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(1449,0,0,"Get ready everyone! Here come de apes!",14,0,100,0,0,0,43550,0,"Witch Doctor Unbagwa");

-- Gorillas Waypoints
DELETE FROM `waypoints` WHERE `entry` IN (1511,1516,1514);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(1511,1,-13789.04,3.232422,34.39908,"Enraged Silverback Gorilla"),
(1511,2,-13777.5,-2.928819,39.94799,"Enraged Silverback Gorilla"),
(1511,3,-13771.6,-6.586046,42.69799,"Enraged Silverback Gorilla"),
(1511,4,-13763.38,-11.97613,44.95544,"Enraged Silverback Gorilla"),
(1511,5,-13743.7,-23.97,45.14,"Enraged Silverback Gorilla"),
(1516,1,-13789.04,3.232422,34.39908,"Konda"),
(1516,2,-13777.5,-2.928819,39.94799,"Konda"),
(1516,3,-13771.6,-6.586046,42.69799,"Konda"),
(1516,4,-13763.38,-11.97613,44.95544,"Konda"),
(1516,5,-13743.7,-23.97,45.14,"Konda"),
(1514,1,-13789.04,3.232422,34.39908,"Mokk the Savage"),
(1514,2,-13777.5,-2.928819,39.94799,"Mokk the Savage"),
(1514,3,-13771.6,-6.586046,42.69799,"Mokk the Savage"),
(1514,4,-13763.38,-11.97613,44.95544,"Mokk the Savage"),
(1514,5,-13743.7,-23.97,45.14,"Mokk the Savage");


-- -------------------------------------------------------- Perry Gatner Event --------------------------------------------------------------------
-- Event
DELETE FROM `game_event` WHERE `eventEntry` = 86;
INSERT INTO `game_event` (`eventEntry`,`start_time`,`end_time`,`occurence`,`length`,`holiday`,`description`,`world_event`,`announce`) VALUES 
(86,'2008-01-02 11:55:00','2030-12-31 06:00:00',240,15,0,'Perry Gatner',0,2);

-- Perry Gatner,Shattrath Saul, and Albert Quarksprocket
-- Smart Scripts - Scripts
DELETE FROM smart_scripts WHERE `entryorguid` IN (1922800,1922801,1922802,1927000,1927100,1927101,1927102,1927103,1927104,1927105,1927106,1927107,1927108,1927109,1927110,1927111,1927112,1927113,1927114,1927115,1927116,1927117,1927118,1927119) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(1922800,9,0,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Perry Gatner - Script - Say Line 0'),
(1922800,9,1,0,0,0,100,0,7000,7000,0,0,0,45,4,4,0,0,0,0,19,19271,0,0,0,0,0,0,0,'Perry Gatner - Script - Set Data 4 4 on Albert Quarksprocket'),
(1922800,9,2,0,0,0,100,0,14000,14000,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Perry Gatner - Script - Say Line 3'),
(1922800,9,3,0,0,0,100,0,7000,7000,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Perry Gatner - Script - Say Line 4'),
(1922800,9,4,0,0,0,100,0,7000,7000,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Perry Gatner - Script - Say Line 5'),
(1922800,9,5,0,0,0,100,0,0,0,0,0,0,45,1,1,0,0,0,0,19,19186,0,0,0,0,0,0,0,'Perry Gatner - - Script - Set Data 1 1 on Kylene Barmaid'),
(1922800,9,6,0,0,0,100,0,7000,7000,0,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Perry Gatner - Script - Say Line 6'),
(1922800,9,7,0,0,0,100,0,7000,7000,0,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Perry Gatner - Script - Say Line 7'),
(1922800,9,8,0,0,0,100,0,5000,5000,0,0,0,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Perry Gatner - Script - Say Line 8'),
(1922800,9,9,0,0,0,100,0,4000,4000,0,0,0,45,1,1,0,0,0,0,19,19186,0,0,0,0,0,0,0,'Perry Gatner - - Script - Set Data 1 1 on Kylene Barmaid'),
(1922800,9,10,0,0,0,100,0,14000,14000,0,0,0,45,2,2,0,0,0,0,19,19271,0,0,0,0,0,0,0,'Perry Gatner - Script - Set Data 2 2 on Albert Quarksprocket'),
(1922800,9,11,0,0,0,100,0,14000,14000,0,0,0,1,11,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Perry Gatner - Script - Say Line 11'),
(1922800,9,12,0,0,0,100,0,7000,7000,0,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Perry Gatner - Script - Say Line 7'),
(1922800,9,13,0,0,0,100,0,7000,7000,0,0,0,1,12,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Perry Gatner - Script - Say Line 12'),
(1922800,9,14,0,0,0,100,0,4000,4000,0,0,0,45,1,1,0,0,0,0,19,19186,0,0,0,0,0,0,0,'Perry Gatner - - Script - Set Data 1 1 on Kylene Barmaid'),
(1922800,9,15,0,0,0,100,0,10000,10000,0,0,0,1,13,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Perry Gatner - Script - Say Line 13'),
(1922800,9,16,0,0,0,100,0,7000,7000,0,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Perry Gatner - Script - Say Line 7'),
(1922800,9,17,0,0,0,100,0,5000,5000,0,0,0,1,14,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Perry Gatner - Script - Say Line 14'),
(1922800,9,18,0,0,0,100,0,4000,4000,0,0,0,45,1,1,0,0,0,0,19,19186,0,0,0,0,0,0,0,'Perry Gatner - - Script - Set Data 1 1 on Kylene Barmaid'),
(1922800,9,19,0,0,0,100,0,10000,10000,0,0,0,45,3,3,0,0,0,0,19,19271,0,0,0,0,0,0,0,'Perry Gatner - Script - Set Data 3 3 on Albert Quarksprocket'),
(1922800,9,20,0,0,0,100,0,12000,12000,0,0,0,1,0,0,0,0,0,0,19,18756,0,0,0,0,0,0,0,'Perry Gatner - Script - Say Line 1 on Hilton Paris'),
(1922800,9,21,0,0,0,100,0,2000,2000,0,0,0,1,17,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Perry Gatner - Script - Say Line 17'),
(1922800,9,22,0,0,0,100,0,0,0,0,0,0,45,1,1,0,0,0,0,19,19186,0,0,0,0,0,0,0,'Perry Gatner - - Script - Set Data 1 1 on Kylene Barmaid'),
(1922800,9,23,0,0,0,100,0,8000,8000,0,0,0,45,6,6,0,0,0,0,19,19271,0,0,0,0,0,0,0,'Perry Gatner - Script - Set Data 6 6 on Albert Quarksprocket'),
(1922800,9,24,0,0,0,100,0,14000,14000,0,0,0,1,20,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Perry Gatner - Script - Say Line 20'),
(1922800,9,25,0,0,0,100,0,7000,7000,0,0,0,1,21,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Perry Gatner - Script - Say Line 21'),
(1922800,9,26,0,0,0,100,0,2000,2000,0,0,0,45,1,1,0,0,0,0,19,19186,0,0,0,0,0,0,0,'Perry Gatner - - Script - Set Data 1 1 on Kylene Barmaid'),
(1922800,9,27,0,0,0,100,0,5000,5000,0,0,0,1,22,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Perry Gatner - Script - Say Line 22'),
(1922800,9,28,0,0,0,100,0,7000,7000,0,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Perry Gatner - Script - Say Line 7'),
(1922800,9,29,0,0,0,100,0,5000,5000,0,0,0,1,23,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Perry Gatner - Script - Say Line 23'),
(1922800,9,30,0,0,0,100,0,4000,4000,0,0,0,45,1,1,0,0,0,0,19,19186,0,0,0,0,0,0,0,'Perry Gatner - - Script - Set Data 1 1 on Kylene Barmaid'),
(1922800,9,31,0,0,0,100,0,14000,14000,0,0,0,45,5,5,0,0,0,0,19,19271,0,0,0,0,0,0,0,'Perry Gatner - Script - Set Data 5 5 on Albert Quarksprocket'),
(1922800,9,32,0,0,0,100,0,14000,14000,0,0,0,1,26,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Perry Gatner - Script - Say Line 26'),
(1922800,9,33,0,0,0,100,0,7000,7000,0,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Perry Gatner - Script - Say Line 7'),
(1922800,9,34,0,0,0,100,0,5000,5000,0,0,0,1,27,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Perry Gatner - Script - Say Line 27'),
(1922800,9,35,0,0,0,100,0,2000,2000,0,0,0,45,1,1,0,0,0,0,19,19186,0,0,0,0,0,0,0,'Perry Gatner - - Script - Set Data 1 1 on Kylene Barmaid'),
(1922800,9,36,0,0,0,100,0,8000,8000,0,0,0,1,28,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Perry Gatner - Script - Say Line 28'),
(1922800,9,37,0,0,0,100,0,8000,8000,0,0,0,45,7,7,0,0,0,0,19,19271,0,0,0,0,0,0,0,'Perry Gatner - Script - Set Data 7 7 on Albert Quarksprocket'),
(1922800,9,38,0,0,0,100,0,4000,4000,0,0,0,65,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Perry Gatner - Script - Resume WP'),
(1922801,9,0,0,0,0,100,0,0,0,0,0,0,45,1,1,0,0,0,0,19,15106,0,0,0,0,0,0,0,'Perry Gatner - Script 2 - Set Data 1 1 on Frostwolf Emissary'),
(1922801,9,1,0,0,0,100,0,0,0,0,0,0,45,1,1,0,0,0,0,19,14990,0,0,0,0,0,0,0,'Perry Gatner - Script 2 - Set Data 1 1 on Defilers Emissary'),
(1922801,9,2,0,0,0,100,0,0,0,0,0,0,45,1,1,0,0,0,0,19,22015,0,0,0,0,0,0,0,'Perry Gatner - Script 2 - Set Data 1 1 on Eye of the Storm Envoy'),
(1922801,9,3,0,0,0,100,0,0,0,0,0,0,45,1,1,0,0,0,0,19,30567,0,0,0,0,0,0,0,'Perry Gatner - Script 2 - Set Data 1 1 on Strand of the Ancients Envoy'),
(1922801,9,4,0,0,0,100,0,0,0,0,0,0,45,1,1,0,0,0,0,19,15105,0,0,0,0,0,0,0,'Perry Gatner - Script 2 - Set Data 1 1 on Warsong Emissary'),
(1922801,9,5,0,0,0,100,0,0,0,0,0,0,45,1,1,0,0,0,0,19,34949,0,0,0,0,0,0,0,'Perry Gatner - Script 2 - Set Data 1 1 on Isle of Conquest Envoy'),
(1922802,9,0,0,0,0,100,0,0,0,0,0,0,45,2,2,0,0,0,0,19,15106,0,0,0,0,0,0,0,'Perry Gatner - Script 3 - Set Data 2 2 on Frostwolf Emissary'),
(1922802,9,1,0,0,0,100,0,0,0,0,0,0,45,2,2,0,0,0,0,19,14990,0,0,0,0,0,0,0,'Perry Gatner - Script 3 - Set Data 2 2 on Defilers Emissary'),
(1922802,9,2,0,0,0,100,0,0,0,0,0,0,45,2,2,0,0,0,0,19,22015,0,0,0,0,0,0,0,'Perry Gatner - Script 3 - Set Data 2 2 on Eye of the Storm Envoy'),
(1922802,9,3,0,0,0,100,0,0,0,0,0,0,45,2,2,0,0,0,0,19,30567,0,0,0,0,0,0,0,'Perry Gatner - Script 3 - Set Data 2 2 on Strand of the Ancients Envoy'),
(1922802,9,4,0,0,0,100,0,0,0,0,0,0,45,2,2,0,0,0,0,19,15105,0,0,0,0,0,0,0,'Perry Gatner - Script 3 - Set Data 2 2 on Warsong Emissary'),
(1922802,9,5,0,0,0,100,0,0,0,0,0,0,45,2,2,0,0,0,0,19,34949,0,0,0,0,0,0,0,'Perry Gatner - Script 3 - Set Data 2 2 on Isle of Conquest Envoy'),
(1927000,9,0,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Shattrath Saul - Script - Yell Line 0'),
(1927000,9,1,0,0,0,100,0,120000,120000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Shattrath Saul - Script - Yell Line 0'),
(1927000,9,2,0,0,0,100,0,120000,120000,0,0,0,12,19228,1,900000,0,0,0,8,0,0,0,0,-1747.62,5126.94,-35.788,1.8675,'Shattrath Saul - Script - Spawn Perry Gatner'),
(1927000,9,3,0,0,0,100,0,60000,60000,0,0,0,45,1,1,0,0,0,0,19,19271,0,0,0,0,0,0,0,'Shattrath Saul - Script - Set Data 1 1 on Albert Quarksprocket'),
(1927100,9,0,0,0,0,100,0,0,0,0,0,0,1,15,0,0,0,0,0,19,19228,0,0,0,0,0,0,0,'Albert Quarksprocket - - Script 0 - Say Line 15 (Perry Gatner'),
(1927100,9,1,0,0,0,100,0,7000,7000,0,0,0,1,16,0,0,0,0,0,19,19228,0,0,0,0,0,0,0,'Albert Quarksprocket - - Script 0 - Say Line 16 (Perry Gatner'),
(1927101,9,0,0,0,0,100,0,0,0,0,0,0,1,29,0,0,0,0,0,19,19228,0,0,0,0,0,0,0,'Albert Quarksprocket - - Script 1 - Say Line 29 (Perry Gatner'),
(1927101,9,1,0,0,0,100,0,7000,7000,0,0,0,1,30,0,0,0,0,0,19,19228,0,0,0,0,0,0,0,'Albert Quarksprocket - - Script 1 - Say Line 30 (Perry Gatner'),
(1927102,9,0,0,0,0,100,0,0,0,0,0,0,1,9,0,0,0,0,0,19,19228,0,0,0,0,0,0,0,'Albert Quarksprocket - - Script 2 - Say Line 9 (Perry Gatner'),
(1927102,9,1,0,0,0,100,0,7000,7000,0,0,0,1,10,0,0,0,0,0,19,19228,0,0,0,0,0,0,0,'Albert Quarksprocket - - Script 2 - Say Line 10 (Perry Gatner'),
(1927103,9,0,0,0,0,100,0,0,0,0,0,0,1,31,0,0,0,0,0,19,19228,0,0,0,0,0,0,0,'Albert Quarksprocket - - Script 3 - Say Line 31 (Perry Gatner'),
(1927103,9,1,0,0,0,100,0,7000,7000,0,0,0,1,32,0,0,0,0,0,19,19228,0,0,0,0,0,0,0,'Albert Quarksprocket - - Script 3 - Say Line 32 (Perry Gatner'),
(1927104,9,0,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,19,19228,0,0,0,0,0,0,0,'Albert Quarksprocket - - Script 4 - Set Orientation'),
(1927104,9,1,0,0,0,100,0,1000,1000,0,0,0,45,2,2,0,0,0,0,19,19186,0,0,0,0,0,0,0,'Albert Quarksprocket - - Script 4 - Set Data 2 2 on Kylene Barmaid'),
(1927104,9,2,0,0,0,100,0,0,0,0,0,0,5,21,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Albert Quarksprocket - - Script 4 - Play emote Oneshot_applause'),
(1927104,9,3,0,0,0,100,0,2000,2000,0,0,0,5,25,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Albert Quarksprocket - - Script 4 - Play emote Oneshot_point'),
(1927104,9,4,0,0,0,100,0,2000,2000,0,0,0,5,21,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Albert Quarksprocket - - Script 4 - Play emote Oneshot_applause'),
(1927104,9,5,0,0,0,100,0,1000,1000,0,0,0,45,1,1,0,0,0,0,19,19228,0,0,0,0,0,0,0,'Albert Quarksprocket - - Script 4 - Set Data 1 1 on Perry Gatner'),
(1927105,9,0,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,19,19228,0,0,0,0,0,0,0,'Albert Quarksprocket - - Script 5 - Say Line 1 (Perry Gatner'),
(1927105,9,1,0,0,0,100,0,7000,7000,0,0,0,1,2,0,0,0,0,0,19,19228,0,0,0,0,0,0,0,'Albert Quarksprocket - - Script 5 - Say Line 2 (Perry Gatner'),
(1927106,9,0,0,0,0,100,0,0,0,0,0,0,1,33,0,0,0,0,0,19,19228,0,0,0,0,0,0,0,'Albert Quarksprocket - - Script 6 - Say Line 33 (Perry Gatner'),
(1927106,9,1,0,0,0,100,0,7000,7000,0,0,0,1,34,0,0,0,0,0,19,19228,0,0,0,0,0,0,0,'Albert Quarksprocket - - Script 6 - Say Line 34 (Perry Gatner'),
(1927107,9,0,0,0,0,100,0,0,0,0,0,0,1,24,0,0,0,0,0,19,19228,0,0,0,0,0,0,0,'Albert Quarksprocket - - Script 7 - Say Line 24 (Perry Gatner'),
(1927107,9,1,0,0,0,100,0,7000,7000,0,0,0,1,25,0,0,0,0,0,19,19228,0,0,0,0,0,0,0,'Albert Quarksprocket - - Script 7 - Say Line 25 (Perry Gatner'),
(1927108,9,0,0,0,0,100,0,0,0,0,0,0,1,35,0,0,0,0,0,19,19228,0,0,0,0,0,0,0,'Albert Quarksprocket - - Script 8 - Say Line 35 (Perry Gatner'),
(1927108,9,1,0,0,0,100,0,7000,7000,0,0,0,1,36,0,0,0,0,0,19,19228,0,0,0,0,0,0,0,'Albert Quarksprocket - - Script 8 - Say Line 36 (Perry Gatner'),
(1927109,9,0,0,0,0,100,0,0,0,0,0,0,1,18,0,0,0,0,0,19,19228,0,0,0,0,0,0,0,'Albert Quarksprocket - - Script 9 - Say Line 18 (Perry Gatner'),
(1927109,9,1,0,0,0,100,0,7000,7000,0,0,0,1,19,0,0,0,0,0,19,19228,0,0,0,0,0,0,0,'Albert Quarksprocket - - Script 9 - Say Line 19 (Perry Gatner'),
(1927110,9,0,0,0,0,100,0,0,0,0,0,0,1,37,0,0,0,0,0,19,19228,0,0,0,0,0,0,0,'Albert Quarksprocket - - Script 10 - Say Line 37 (Perry Gatner'),
(1927110,9,1,0,0,0,100,0,7000,7000,0,0,0,1,38,0,0,0,0,0,19,19228,0,0,0,0,0,0,0,'Albert Quarksprocket - - Script 10 - Say Line 38 (Perry Gatner'),
(1927111,9,0,0,0,0,100,0,0,0,0,0,0,1,39,0,0,0,0,0,19,19228,0,0,0,0,0,0,0,'Albert Quarksprocket - - Script 11 - Say Line 39 (Perry Gatner'),
(1927111,9,1,0,0,0,100,0,7000,7000,0,0,0,1,40,0,0,0,0,0,19,19228,0,0,0,0,0,0,0,'Albert Quarksprocket - - Script 11 - Say Line 40 (Perry Gatner'),
(1927112,9,0,0,0,0,100,0,0,0,0,0,0,1,41,0,0,0,0,0,19,19228,0,0,0,0,0,0,0,'Albert Quarksprocket - - Script 12 - Say Line 41 (Perry Gatner'),
(1927112,9,1,0,0,0,100,0,7000,7000,0,0,0,1,42,0,0,0,0,0,19,19228,0,0,0,0,0,0,0,'Albert Quarksprocket - - Script 12 - Say Line 42 (Perry Gatner'),
(1927113,9,0,0,0,0,100,0,0,0,0,0,0,1,43,0,0,0,0,0,19,19228,0,0,0,0,0,0,0,'Albert Quarksprocket - - Script 13 - Say Line 43 (Perry Gatner'),
(1927113,9,1,0,0,0,100,0,7000,7000,0,0,0,1,44,0,0,0,0,0,19,19228,0,0,0,0,0,0,0,'Albert Quarksprocket - - Script 13 - Say Line 44 (Perry Gatner'),
(1927114,9,0,0,0,0,100,0,0,0,0,0,0,1,45,0,0,0,0,0,19,19228,0,0,0,0,0,0,0,'Albert Quarksprocket - - Script 14 - Say Line 45 (Perry Gatner'),
(1927114,9,1,0,0,0,100,0,7000,7000,0,0,0,1,46,0,0,0,0,0,19,19228,0,0,0,0,0,0,0,'Albert Quarksprocket - - Script 14 - Say Line 46 (Perry Gatner'),
(1927115,9,0,0,0,0,100,0,0,0,0,0,0,1,47,0,0,0,0,0,19,19228,0,0,0,0,0,0,0,'Albert Quarksprocket - - Script 15 - Say Line 47 (Perry Gatner'),
(1927115,9,1,0,0,0,100,0,7000,7000,0,0,0,1,48,0,0,0,0,0,19,19228,0,0,0,0,0,0,0,'Albert Quarksprocket - - Script 15 - Say Line 48 (Perry Gatner'),
(1927116,9,0,0,0,0,100,0,0,0,0,0,0,1,47,0,0,0,0,0,19,19228,0,0,0,0,0,0,0,'Albert Quarksprocket - - Script 16 - Say Line 49 (Perry Gatner'),
(1927116,9,1,0,0,0,100,0,7000,7000,0,0,0,1,48,0,0,0,0,0,19,19228,0,0,0,0,0,0,0,'Albert Quarksprocket - - Script 16 - Say Line 50 (Perry Gatner'),
(1927117,9,0,0,0,0,100,0,0,0,0,0,0,1,51,0,0,0,0,0,19,19228,0,0,0,0,0,0,0,'Albert Quarksprocket - - Script 17 - Say Line 51 (Perry Gatner'),
(1927118,9,0,0,0,0,100,0,0,0,0,0,0,54,273000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Albert Quarksprocket - Script 18 - Pause WP'),
(1927118,9,1,0,0,0,100,0,2000,2000,0,0,0,66,0,0,0,0,0,0,19,19228,0,0,0,0,0,0,0,'Albert Quarksprocket - Script 18 - Set Orientation'),
(1927119,9,0,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,1.8675,'Albert Quarksprocket - Script - Set Orientation'),
(1927119,9,1,0,0,0,100,0,1000,1000,0,0,0,5,11,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Albert Quarksprocket - Script - Play emote oneshot laugh'),
(1927119,9,2,0,0,0,100,0,2000,2000,0,0,0,1,1,14000,0,0,0,0,1,0,0,0,0,0,0,0,0,'Albert Quarksprocket - Script - Say line 2'),
(1927119,9,3,0,0,0,100,0,14000,14000,0,0,0,65,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Albert Quarksprocket - Script - Resume WP');

--  Smart Scripts - Rules
DELETE FROM smart_scripts WHERE `entryorguid` IN (19270,19228,19271,15106,14990,22015,30567,15105,34949) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(14990,0,0,0,38,0,100,0,1,1,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Defilers Emissary - On Data Set 1 1 - Set Phase 2'),
(14990,0,1,0,38,0,100,0,2,2,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Defilers Emissary - On Data Set 2 2 - Set Phase 1'),
(14990,0,2,0,1,2,100,0,14000,21000,7000,21000,0,5,11,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Defilers Emissary - OOC (Phase 2) - Play emote oneshot laugh'),
(15105,0,0,0,38,0,100,0,1,1,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Warsong Emissary - On Data Set 1 1 - Set Phase 2'),
(15105,0,1,0,38,0,100,0,2,2,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Warsong Emissary - On Data Set 2 2 - Set Phase 1'),
(15105,0,2,0,1,2,100,0,14000,21000,7000,21000,0,5,11,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Warsong Emissary - OOC (Phase 2) - Play emote oneshot laugh'),
(15106,0,0,0,38,0,100,0,1,1,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Frostwolf Emissary - On Data Set 1 1 - Set Phase 2'),
(15106,0,1,0,38,0,100,0,2,2,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Frostwolf Emissary - On Data Set 2 2 - Set Phase 1'),
(15106,0,2,0,1,2,100,0,14000,21000,7000,21000,0,5,11,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Frostwolf Emissary - OOC (Phase 2) - Play emote oneshot laugh'),
(19228,0,0,0,54,0,100,0,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Perry Gatner - Just Summoned - Set Active On'),
(19228,0,1,0,38,0,100,0,1,1,0,0,0,53,0,19228,0,0,0,0,1,0,0,0,0,0,0,0,0,'Perry Gatner - On Data Set 1 1 - Start WP'),
(19228,0,2,3,40,0,100,0,3,19228,0,0,0,54,265000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Perry Gatner - On Reached WP3 - Pause WP'),
(19228,0,3,0,61,0,100,0,0,0,0,0,0,80,1922800,2,0,0,0,0,1,0,0,0,0,0,0,0,0,'Perry Gatner - On Reached WP3 - Run Script 1'),
(19228,0,4,0,40,0,100,0,6,19228,0,0,0,41,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Perry Gatner - On Reached WP6 - Despawn'),
(19228,0,5,0,40,0,100,0,2,19228,0,0,0,80,1922801,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Perry Gatner - On Reached WP2 - Run Script 2'),
(19228,0,6,0,40,0,100,0,4,19228,0,0,0,80,1922802,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Perry Gatner - On Reached WP6 - Run Script 3'),
(19270,0,0,1,68,0,100,0,86,0,0,0,0,80,1927000,2,0,0,0,0,1,0,0,0,0,0,0,0,0,'Shattrath Saul - On Event Start - Run Timed action list'),
(19270,0,1,0,61,0,100,0,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Shattrath Saul - On Event Start - Set Active'),
(19270,0,2,0,69,0,100,0,86,0,0,0,0,48,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Shattrath Saul - On Event End - Set Active Off'),
(19271,0,0,0,38,0,100,0,1,1,0,0,0,53,0,19271,0,0,0,0,1,0,0,0,0,0,0,0,0,'Albert Quarksprocket - On Data Set 1 1 - Start WP'),
(19271,0,1,2,40,0,100,0,5,19271,0,0,0,54,13000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Albert Quarksprocket - On Reached WP5 - Pause WP'),
(19271,0,2,3,61,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,1.8675,'Albert Quarksprocket - On Reached WP5 - Set Orientation'),
(19271,0,3,0,61,0,100,0,0,0,0,0,0,1,0,5000,0,0,0,0,1,0,0,0,0,0,0,0,0,'Albert Quarksprocket - On Reached WP5 - Say line 1'),
(19271,0,4,0,52,0,100,0,0,19271,0,0,0,80,1927104,2,0,0,0,0,1,0,0,0,0,0,0,0,0,'Albert Quarksprocket - On Text over line 1 - Run Script '),
(19271,0,5,0,40,0,100,0,10,19271,0,0,0,80,1927118,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Albert Quarksprocket - On Reached WP10 - Run Script'),
(19271,0,6,7,38,0,100,0,2,2,0,0,0,87,1927102,1927103,1927113,0,0,0,1,0,0,0,0,0,0,0,2.03774,'Albert Quarksprocket - On Data Set 2 2 - Run Random Script'),
(19271,0,7,0,61,0,100,0,0,0,0,0,0,45,1,1,0,0,0,0,10,68635,19186,0,0,0,0,0,0,'Albert Quarksprocket - Linked - Set Data 1 1 on Kylene Barmaid'),
(19271,0,8,9,40,0,100,0,18,19271,0,0,0,54,19000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Albert Quarksprocket - On Reached WP18 - Pause WP'),
(19271,0,9,0,61,0,100,0,0,0,0,0,0,80,1927119,2,0,0,0,0,1,0,0,0,0,0,0,0,0,'Albert Quarksprocket - Linked - Run Script'),
(19271,0,10,11,40,0,100,0,24,19271,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,2.03774,'Albert Quarksprocket - On Reached WP24 - Set Orientation'),
(19271,0,11,0,61,0,100,0,0,0,0,0,0,111,86,0,0,0,0,0,8,0,0,0,0,0,0,0,2.03774,'Albert Quarksprocket - Linked - Stop Event'),
(19271,0,12,13,38,0,100,0,3,3,0,0,0,87,1927100,1927101,1927111,0,0,0,1,0,0,0,0,0,0,0,0,'Albert Quarksprocket - On Data set 3 3 - Run Random script'),
(19271,0,13,0,61,0,100,0,0,0,0,0,0,45,1,1,0,0,0,0,10,68635,19186,0,0,0,0,0,0,'Albert Quarksprocket - Linked - Set Data 1 1 on Kylene Barmaid'),
(19271,0,14,15,38,0,100,0,4,4,0,0,0,87,1927105,1927106,1927115,0,0,0,1,0,0,0,0,0,0,0,0,'Albert Quarksprocket - On Data set 4 4 - Run Random script'),
(19271,0,15,0,61,0,100,0,0,0,0,0,0,45,1,1,0,0,0,0,10,68635,19186,0,0,0,0,0,0,'Albert Quarksprocket - Linked - Set Data 1 1 on Kylene Barmaid'),
(19271,0,16,17,38,0,100,0,5,5,0,0,0,87,1927107,1927108,1927114,1927117,0,0,1,0,0,0,0,0,0,0,0,'Albert Quarksprocket - On Data set 5 5 - Run Random script'),
(19271,0,17,0,61,0,100,0,0,0,0,0,0,45,1,1,0,0,0,0,10,68635,19186,0,0,0,0,0,0,'Albert Quarksprocket - Linked - Set Data 1 1 on Kylene Barmaid'),
(19271,0,18,19,38,0,100,0,6,6,0,0,0,87,1927109,1927110,1927112,1927116,0,0,1,0,0,0,0,0,0,0,0,'Albert Quarksprocket - On Data set 6 6 - Run Random script'),
(19271,0,19,0,61,0,100,0,0,0,0,0,0,45,1,1,0,0,0,0,10,68635,19186,0,0,0,0,0,0,'Albert Quarksprocket - Linked - Set Data 1 1 on Kylene Barmaid'),
(19271,0,20,0,38,0,100,0,7,7,0,0,0,65,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Albert Quarksprocket - On Data set 7 7 - Resume WP'),
(19271,0,21,0,68,0,100,0,86,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Albert Quarksprocket - On Event Start - Set Active'),
(19271,0,22,0,69,0,100,0,86,0,0,0,0,48,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Albert Quarksprocket - On Event End - Set Active Off'),
(22015,0,0,0,38,0,100,0,1,1,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Eye of the Storm Envoy - On Data Set 1 1 - Set Phase 2'),
(22015,0,1,0,38,0,100,0,2,2,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Eye of the Storm Envoy - On Data Set 2 2 - Set Phase 1'),
(22015,0,2,0,1,2,100,0,14000,21000,7000,21000,0,5,11,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Eye of the Storm Envoy - OOC (Phase 2) - Play emote oneshot laugh'),
(30567,0,0,0,38,0,100,0,1,1,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Strand of the Ancients Envoy - On Data Set 1 1 - Set Phase 2'),
(30567,0,1,0,38,0,100,0,2,2,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Strand of the Ancients Envoy - On Data Set 2 2 - Set Phase 1'),
(30567,0,2,0,1,2,100,0,14000,21000,7000,21000,0,5,11,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Strand of the Ancients Envoy - OOC (Phase 2) - Play emote oneshot laugh'),
(34949,0,0,0,38,0,100,0,1,1,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Isle of Conquest Envoy - On Data Set 1 1 - Set Phase 2'),
(34949,0,1,0,38,0,100,0,2,2,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Isle of Conquest Envoy - On Data Set 2 2 - Set Phase 1'),
(34949,0,2,0,1,2,100,0,14000,21000,7000,21000,0,5,11,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Isle of Conquest Envoy - OOC (Phase 2) - Play emote oneshot laugh');

-- Perry Gatner and Albert Quarksprocket Waypoints
DELETE FROM `waypoints` WHERE `entry` IN (19228,19271);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(19228,1,-1748.807,5131.199,-35.77385,'Perry Gatner WP1'),
(19228,2,-1749.057,5132.199,-36.02385,'Perry Gatner WP2'),
(19228,3,-1752.193,5142.406,-36.2607,'Perry Gatner WP3'),-- Stage
(19228,4,-1748.807,5131.199,-35.77385,'Perry Gatner WP4'),
(19228,5,-1748.3,5129.432,-35.899,'Perry Gatner WP5'),
(19228,6,-1747.62,5126.94,-35.788,'Perry Gatner WP6'),-- back
(19271,1,-1738.782,5139.548,-37.3106,'Albert Quarksprocket WP1'),
(19271,2,-1742.507,5139.548,-36.2804,'Albert Quarksprocket WP2'),
(19271,3,-1746.355,5140.012,-36.253,'Albert Quarksprocket WP3'),
(19271,4,-1751.719,5140.519,-36.26,'Albert Quarksprocket WP4'),
(19271,5,-1752.193,5142.406,-36.2607,'Albert Quarksprocket WP5'),-- Intro
(19271,6,-1749.931,5144.202,-36.48227,'Albert Quarksprocket WP6'),
(19271,7,-1749.181,5144.952,-36.73227,'Albert Quarksprocket WP7'),
(19271,8,-1748.681,5145.452,-36.73227,'Albert Quarksprocket WP8'),
(19271,9,-1747.681,5144.952,-36.73227,'Albert Quarksprocket WP9'),
(19271,10,-1737.287,5138.584,-37.30579,'Albert Quarksprocket WP10'),-- end
(19271,11,-1739.931,5141.971,-37.01586,'Albert Quarksprocket WP11'),
(19271,12,-1740.726,5142.045,-37.01049,'Albert Quarksprocket WP12'),
(19271,13,-1741.726,5142.545,-37.01049,'Albert Quarksprocket WP13'),
(19271,14,-1747.726,5145.545,-37.01049,'Albert Quarksprocket WP14'),
(19271,15,-1748.1,5145.452,-36.73235,'Albert Quarksprocket WP15'),
(19271,16,-1749.35,5144.952,-36.73235,'Albert Quarksprocket WP16'),
(19271,17,-1751.719,5140.519,-36.26,'Albert Quarksprocket WP17'),
(19271,18,-1752.193,5142.406,-36.2607,'Albert Quarksprocket WP18'),-- Outro
(19271,19,-1749.56,5143.69,-35.98226,'Albert Quarksprocket WP19'),
(19271,20,-1748.56,5143.94,-36.48226,'Albert Quarksprocket WP20'),
(19271,21,-1747.31,5144.44,-36.73226,'Albert Quarksprocket WP21'),
(19271,22,-1745.287,5145.255,-36.87066,'Albert Quarksprocket WP22'),
(19271,23,-1741.787,5142.005,-36.87066,'Albert Quarksprocket WP23'),
(19271,24,-1737.287,5138.584,-37.30579,'Albert Quarksprocket WP24');-- end

-- Perry Gatner Missing Text
DELETE FROM `creature_text` WHERE `CreatureID` = 19228 AND `GroupID` = 51;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES 
(19228,51,0,'Hey, it\'s Raliq the drunk... His momma\'s so fat, when she flies to Blade\'s Edge they charged her by the pound!',12,0,100,1,0,0,16661,0,'Perry Gatner');


-- Kylene Barmaid
UPDATE `creature_template` SET `AIName` = "SmartAI",`MovementType` = 0 WHERE `entry` = 19186;

DELETE FROM `creature_template_addon` WHERE `entry` = 19186;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`isLarge`,`auras`) VALUES 
(19186,0,0,0,4097,0,0,NULL);

DELETE FROM smart_scripts WHERE `entryorguid` = 19186 AND `source_type` = 0;
DELETE FROM smart_scripts WHERE `entryorguid` IN (1918600,1918601) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(19186,0,0,0,1,0,100,0,1000,1000,0,0,0,53,0,19186,1,0,0,0,1,0,0,0,0,0,0,0,0,'Kylene Barmaid - OOC - Start Waypoint (Repeat)'),
(19186,0,1,0,40,0,100,0,4,19186,0,0,0,54,30000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Kylene Barmaid - On Reached WP4 - Pause WP'),
(19186,0,2,0,40,0,100,0,9,19186,0,0,0,54,15000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Kylene Barmaid - On Reached WP9 - Pause WP'),
(19186,0,3,0,40,0,100,0,14,19186,0,0,0,54,30000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Kylene Barmaid - On Reached WP14 - Pause WP'),
(19186,0,4,0,40,0,100,0,16,19186,0,0,0,54,15000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Kylene Barmaid - On Reached WP16 - Pause WP'),
(19186,0,5,0,40,0,100,0,20,19186,0,0,0,54,30000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Kylene Barmaid - On Reached WP20 - Pause WP'),
(19186,0,6,0,38,0,10,0,1,1,0,0,0,87,1918600,1918601,0,0,0,0,1,0,0,0,0,0,0,0,0,'Kylene Barmaid - On Data Set 1 1 - Run Random Script'),
(19186,0,7,0,38,0,100,0,2,2,0,0,0,80,1918600,2,0,0,0,0,1,0,0,0,0,0,0,0,0,'Kylene Barmaid - On Data Set 2 2 - Run Timed action list'),
(1918600,9,0,0,0,0,100,0,8000,8000,0,0,0,58,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Kylene Barmaid - On Data Set 1 1 - Stop WP'),
(1918600,9,1,0,0,0,100,0,0,0,0,0,0,5,21,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Kylene Barmaid - On Data Set 1 1 - Play emote Oneshot_applause'),
(1918600,9,2,0,0,0,100,0,5000,5000,0,0,0,65,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Kylene Barmaid - Linked  - Resume WP'),
(1918601,9,0,0,0,0,100,0,8000,8000,0,0,0,58,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Kylene Barmaid - On Data Set 1 1 - Stop WP'),
(1918601,9,1,0,0,0,100,0,0,0,0,0,0,5,11,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Kylene Barmaid - On Data Set 1 1 - Play emote Oneshot_laugh'),
(1918601,9,2,0,0,0,100,0,5000,5000,0,0,0,65,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Kylene Barmaid - Linked  - Resume WP');

DELETE FROM `waypoints` WHERE `entry` = 19186;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(19186,1,-1740.27,5151.92,-37.2048,'Kylene Barmaid'),
(19186,2,-1738.85,5143.98,-37.2048,'Kylene Barmaid'),
(19186,3,-1728.35,5143.06,-36.9564,'Kylene Barmaid'),
(19186,4,-1724.36,5143.64,-37.1995,'Kylene Barmaid'),
(19186,5,-1732.21,5143.6,-37.2047,'Kylene Barmaid'),
(19186,6,-1741.84,5145.78,-37.2047,'Kylene Barmaid'),
(19186,7,-1753.5,5146.53,-37.2047,'Kylene Barmaid'),
(19186,8,-1755.59,5154.44,-37.2047,'Kylene Barmaid'),
(19186,9,-1750.63,5156.48,-37.2047,'Kylene Barmaid'),
(19186,10,-1755.35,5153.93,-37.2047,'Kylene Barmaid'),
(19186,11,-1756.05,5147.66,-37.2047,'Kylene Barmaid'),
(19186,12,-1761.73,5140.08,-37.2047,'Kylene Barmaid'),
(19186,13,-1769.61,5134.25,-37.2047,'Kylene Barmaid'),
(19186,14,-1775.69,5130.56,-37.2044,'Kylene Barmaid'),
(19186,15,-1764.61,5136.27,-37.2042,'Kylene Barmaid'),
(19186,16,-1759.48,5145.59,-37.2042,'Kylene Barmaid'),
(19186,17,-1751.96,5146.53,-37.2042,'Kylene Barmaid'),
(19186,18,-1740.15,5150.33,-37.2042,'Kylene Barmaid'),
(19186,19,-1740.9,5155.06,-37.2042,'Kylene Barmaid'),
(19186,20,-1742.4,5158.5,-37.2042,'Kylene Barmaid');


-- Tinkerbell
UPDATE `creature` SET `wander_distance` = 1,`MovementType` = 1 WHERE `guid` = 67042;

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
