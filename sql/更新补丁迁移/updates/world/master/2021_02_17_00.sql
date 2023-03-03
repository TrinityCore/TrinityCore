-- DB update 2021_02_16_01 -> 2021_02_17_00
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_02_16_01';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_02_16_01 2021_02_17_00 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1612897779919534400'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1612897779919534400');
/* NEW GUIDS: EVENT 85, CREATURE 300000 - 300006*/

/*------------------------------------------- Event ---------------------------------------------------------------------------------------------------*/

-- Stitches Event 
SET @STITCHESEVENT := 85; -- EVENT NEW GUID
SET @GUID := 300000; -- Stitches NEW GUID
DELETE FROM `game_event` WHERE `eventEntry`=@STITCHESEVENT;
INSERT INTO `game_event` (`eventEntry`,`start_time`,`end_time`,`occurence`,`length`,`holiday`,`holidayStage`,`description`,`world_event`,`announce`) VALUES
(@STITCHESEVENT,"2011-03-22 01:00:00","2030-12-31 07:00:00",5184000,35,0,0,"Stitches Event",0,2);

-- Stitches and Watchers - Spawn during event only
DELETE FROM `game_event_creature` WHERE `eventEntry`=@STITCHESEVENT;
INSERT INTO `game_event_creature` (`eventEntry`,`guid`) VALUES
(@STITCHESEVENT,@GUID),
(@STITCHESEVENT,300001),
(@STITCHESEVENT,300002),
(@STITCHESEVENT,300003),
(@STITCHESEVENT,300004),
(@STITCHESEVENT,300005),
(@STITCHESEVENT,300006),
(@STITCHESEVENT,6127),
(@STITCHESEVENT,6133);

/*------------------------------------------- Stitches ---------------------------------------------------------------------------------------------------*/

-- Stitches
UPDATE `creature_template` SET `faction` = 7 WHERE `entry` = 412;
DELETE FROM `creature` WHERE `guid` IN (@GUID);
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`wander_distance`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES 
(@GUID,412,0,0,0,1,1,0,0,-10613.308,-1055.62,38.46,0.33,300,0,0,12200,0,0,0,0,0,'',0);


DELETE FROM `creature_addon` WHERE `guid` = @GUID;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`isLarge`,`auras`) VALUES
(@GUID,0,0,0,0,0,1,NULL);


DELETE FROM `smart_scripts` WHERE `entryorguid` = 412 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(412,0,0,0,0,0,100,0,6000,12000,6000,12000,0,11,3106,0,0,0,0,0,2,0,0,0,0,0,0,0,0,'Stitches - In Combat - Cast \'Aura of Rot\''),
(412,0,1,2,11,0,100,0,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Stitches - On Respawn - Set Active On'),
(412,0,2,0,61,0,100,0,0,0,0,0,0,62,0,0,0,0,0,2,1,0,0,0,0,-10290.2,72.7811,38.8811,4.8015,'Stitches - On Respawn - Teleport'),
(412,0,3,0,1,0,100,0,5000,5000,0,0,0,53,1,412,0,0,0,2,1,0,0,0,0,0,0,0,0,'Stitches - OOC - Start Waypoint'),
(412,0,4,5,40,0,100,0,36,412,0,0,0,2,93,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Stitches - On Waypoint 36 Reached - Set Faction 93'),
(412,0,5,0,61,0,100,0,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Stitches - On Waypoint 36 Reached - Set Walk'),
(412,0,6,0,40,0,100,0,36,412,0,0,0,45,2,1,0,0,0,0,10,4185,468,1,0,0,0,0,0,'Stitches - On Waypoint 36 Reached - Say Line 1 (Town Crier)'),
(412,0,7,0,40,0,100,0,51,412,0,0,0,45,2,2,0,0,0,0,10,4185,468,1,0,0,0,0,0,'Stitches - On Waypoint 51 Reached - Say Line 2 (Town Crier)'),
(412,0,8,0,40,0,100,0,68,412,0,0,0,45,2,3,0,0,0,0,10,4185,468,1,0,0,0,0,0,'Stitches - On Waypoint 68 Reached - Say Line 3 (Town Crier)'),
(412,0,9,0,40,0,100,0,85,412,0,0,0,45,2,4,0,0,0,0,10,4185,468,1,0,0,0,0,0,'Stitches - On Waypoint 85 Reached - Say Line 4 (Town Crier)'),
(412,0,10,0,40,0,100,0,68,412,0,0,0,45,1,1,0,0,0,0,10,4180,826,1,0,0,0,0,0,'Stitches - On Waypoint 68 Reached - Move Watcher Jan'),
(412,0,11,0,40,0,100,0,72,412,0,0,0,45,1,3,0,0,0,0,10,4180,826,1,0,0,0,0,0,'Stitches - On Waypoint 72 Reached - Set Orientation Watcher Jan'),
(412,0,12,0,40,0,100,0,68,412,0,0,0,45,1,1,0,0,0,0,10,4182,494,1,0,0,0,0,0,'Stitches - On Waypoint 68 Reached - Move Watcher Bukouris'),
(412,0,13,0,40,0,100,0,68,412,0,0,0,45,1,1,0,0,0,0,10,5960,2470,1,0,0,0,0,0,'Stitches - On Waypoint 68 Reached - Move Watcher Frazier'),
(412,0,14,0,40,0,100,0,70,412,0,0,0,45,1,3,0,0,0,0,10,5960,2470,1,0,0,0,0,0,'Stitches - On Waypoint 70 Reached - Set Orientation Watcher Frazier'),
(412,0,15,0,40,0,100,0,68,412,0,0,0,45,1,1,0,0,0,0,10,6133,1204,1,0,0,0,0,0,'Stitches - On Waypoint 68 Reached - Move Watcher Corwin'),
(412,0,16,0,40,0,100,0,68,412,0,0,0,45,1,1,0,0,0,0,10,6127,1203,1,0,0,0,0,0,'Stitches - On Waypoint 68 Reached - Move Watcher Sarys'),
(412,0,17,0,40,0,100,0,90,412,0,0,0,89,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Stitches - On Waypoint 90 Reached - Start Random Movement'),
(412,0,18,0,6,0,100,0,0,0,0,0,0,45,2,5,0,0,0,0,10,4185,468,1,0,0,0,0,0,'Stitches - On Just Died - Say Line 5 (Town Crier)'),
(412,0,19,0,6,0,100,0,0,0,0,0,0,45,1,2,0,0,0,0,10,4180,826,1,0,0,0,0,0,'Stitches - On Just Died - Move Watcher Jan back '),
(412,0,20,0,6,0,100,0,0,0,0,0,0,45,1,2,0,0,0,0,10,4182,494,1,0,0,0,0,0,'Stitches - On Just Died - Move Watcher Bukouris back'),
(412,0,21,0,6,0,100,0,0,0,0,0,0,45,1,2,0,0,0,0,10,5960,2470,1,0,0,0,0,0,'Stitches - On Just Died - Move Watcher Frazier back'),
(412,0,22,0,6,0,100,0,0,0,0,0,0,45,1,2,0,0,0,0,10,6133,1204,1,0,0,0,0,0,'Stitches - On Just Died - Move Watcher Corwin back'),
(412,0,23,0,6,0,100,0,0,0,0,0,0,45,1,2,0,0,0,0,10,6127,1203,1,0,0,0,0,0,'Stitches - On Just Died - Move Watcher Sarys back'),
(412,0,24,0,6,0,100,0,0,0,0,0,0,45,1,2,0,0,0,0,10,300002,1001,1,0,0,0,0,0,'Stitches - On Just Died - Move Watcher Hutchins back'),
(412,0,25,0,6,0,100,0,0,0,0,0,0,45,1,2,0,0,0,0,10,300001,28987,1,0,0,0,0,0,'Stitches - On Just Died - Move Watcher Blomberg back'),
(412,0,26,0,6,0,100,0,0,0,0,0,0,45,1,2,0,0,0,0,10,300003,1098,1,0,0,0,0,0,'Stitches - On Just Died - Make Watcher Merant invisible'),
(412,0,27,0,6,0,100,0,0,0,0,0,0,45,1,2,0,0,0,0,10,300004,1099,1,0,0,0,0,0,'Stitches - On Just Died - Make Watcher Gelwin invisible'),
(412,0,28,0,6,0,100,0,0,0,0,0,0,45,1,2,0,0,0,0,10,300006,1101,1,0,0,0,0,0,'Stitches - On Just Died - Make Watcher Thayer invisible'),
(412,0,29,0,6,0,100,0,0,0,0,0,0,45,1,2,0,0,0,0,10,300005,1100,1,0,0,0,0,0,'Stitches - On Just Died - Make Watcher Selkin invisible'),
(412,0,30,0,6,0,100,0,0,0,0,0,0,45,1,2,0,0,0,0,10,5938,499,1,0,0,0,0,0,'Stitches - On Just Died - Move Watcher Paige back'),
(412,0,31,0,6,0,100,0,0,0,0,0,0,45,1,2,0,0,0,0,10,5937,888,1,0,0,0,0,0,'Stitches - On Just Died - Move Watcher Dodds back'),
(412,0,32,0,1,0,100,0,30000,40000,90000,120000,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Stitches - Update - Say Line 0'),
(412,0,33,0,69,0,100,0,85,0,0,0,0,70,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Stitches - - On Game Event \'Stitches\' End - Respawn In 2 secs'),
(412,0,34,0,40,0,100,0,36,412,0,0,0,45,1,1,0,0,0,0,10,5938,499,1,0,0,0,0,0,'Stitches - On Waypoint 36 Reached - Set Data (Watcher Paige)'),
(412,0,35,0,40,0,100,0,36,412,0,0,0,45,1,1,0,0,0,0,10,5937,888,1,0,0,0,0,0,'Stitches - On Waypoint 36 Reached - Set Data (Watcher Dodds)'),
(412,0,36,0,40,0,100,0,51,412,0,0,0,45,1,1,0,0,0,0,10,300003,1098,1,0,0,0,0,0,'Stitches - On Waypoint 51 Reached - Set Data (Watcher Merant)'),
(412,0,37,0,40,0,100,0,51,412,0,0,0,45,1,1,0,0,0,0,10,300004,1099,1,0,0,0,0,0,'Stitches - On Waypoint 51 Reached - Set Data (Watcher Gelwin)'),
(412,0,38,0,40,0,100,0,51,412,0,0,0,45,1,1,0,0,0,0,10,300006,1101,1,0,0,0,0,0,'Stitches - On Waypoint 51 Reached - Set Data (Watcher Thayer)'),
(412,0,39,0,40,0,100,0,51,412,0,0,0,45,1,1,0,0,0,0,10,300005,1100,1,0,0,0,0,0,'Stitches - On Waypoint 51 Reached - Set Data (Watcher Selkin)'),
(412,0,40,0,40,0,100,0,66,412,0,0,0,49,0,0,0,0,0,0,10,300003,1098,1,0,0,0,0,0,'Stitches - On Waypoint 66 Reached - Set Data (Watcher Merant)'),
(412,0,41,0,40,0,100,0,36,412,0,0,0,45,1,1,0,0,0,0,10,300001,28987,1,0,0,0,0,0,'Stitches - On Waypoint 36 Reached - Set Data (Watcher Blomberg)'),
(412,0,42,0,40,0,100,0,36,412,0,0,0,45,1,1,0,0,0,0,10,300002,1001,1,0,0,0,0,0,'Stitches - On Waypoint 36 Reached - Set Data (Watcher Hutchins)'),
(412,0,43,0,40,0,100,0,85,412,0,0,0,45,1,2,0,0,0,0,10,4194,264,1,0,0,0,0,0,'Stitches - On Waypoint 85 Reached - Say Line 42(Commander Althea)');

-- Stitches Waypoints 
DELETE FROM `waypoints` WHERE entry = 412;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(412,1,-10290.1,73.7148,38.849,'Stitches Event'),
(412,2,-10290.4,81.547,38.7702,'Stitches Event'),
(412,3,-10283.2,86.6661,38.7694,'Stitches Event'),
(412,4,-10271.1,83.5772,39.1122,'Stitches Event'),
(412,5,-10266,76.0585,39.4047,'Stitches Event'),
(412,6,-10272.4,65.7703,39.524,'Stitches Event'),
(412,7,-10283.4,59.1681,40.6902,'Stitches Event'),
(412,8,-10300.2,45.8306,47.3053,'Stitches Event'),
(412,9,-10315.3,45.1015,48.0097,'Stitches Event'),
(412,10,-10324.4,38.7441,47.3935,'Stitches Event'),
(412,11,-10330.2,27.0829,50.5753,'Stitches Event'),
(412,12,-10335.3,13.4164,50.1259,'Stitches Event'),
(412,13,-10342.2,3.3501,51.1675,'Stitches Event'),
(412,14,-10354.6,-13.0266,47.1154,'Stitches Event'),
(412,15,-10379.4,-27.1456,49.2841,'Stitches Event'),
(412,16,-10401,-30.8108,48.1353,'Stitches Event'),
(412,17,-10416.5,-28.4794,48.4772,'Stitches Event'),
(412,18,-10436.4,-34.2376,46.5064,'Stitches Event'),
(412,19,-10468.7,-38.8985,48.7035,'Stitches Event'),
(412,20,-10500.2,-44.6662,45.882,'Stitches Event'),
(412,21,-10539.1,-39.3422,43.0622,'Stitches Event'),
(412,22,-10568,-35.1434,37.2048,'Stitches Event'),
(412,23,-10585.6,-37.5056,37.4296,'Stitches Event'),
(412,24,-10606.3,-51.7202,36.0713,'Stitches Event'),
(412,25,-10629.2,-64.211,32.6163,'Stitches Event'),
(412,26,-10645.9,-73.4561,32.7337,'Stitches Event'),
(412,27,-10671,-81.8316,35.6535,'Stitches Event'),
(412,28,-10687.6,-85.57,34.1549,'Stitches Event'),
(412,29,-10702.8,-89.2772,37.9242,'Stitches Event'),
(412,30,-10709.1,-97.5837,37.892,'Stitches Event'),
(412,31,-10725.6,-101.348,34.5892,'Stitches Event'),
(412,32,-10748,-99.1517,38.2323,'Stitches Event'),
(412,33,-10759.9,-93.0657,38.5876,'Stitches Event'),
(412,34,-10774.9,-89.8001,34.8007,'Stitches Event'),
(412,35,-10788.6,-86.7376,33.4988,'Stitches Event'),
(412,36,-10802.7,-88.6347,29.0679,'Stitches Event'),
(412,37,-10811.5,-97.1736,29.2451,'Stitches Event'),
(412,38,-10821.4,-121.335,30.142,'Stitches Event'),
(412,39,-10826.2,-134.391,31.7845,'Stitches Event'),
(412,40,-10830.6,-148.284,31.7985,'Stitches Event'),
(412,41,-10835.3,-164.201,33.8299,'Stitches Event'),
(412,42,-10840.4,-182.63,34.0254,'Stitches Event'),
(412,43,-10843.3,-193.104,35.8227,'Stitches Event'),
(412,44,-10848.7,-215.175,37.7986,'Stitches Event'),
(412,45,-10851.7,-235.779,38.6853,'Stitches Event'),
(412,46,-10857.4,-264.019,38.0974,'Stitches Event'),
(412,47,-10866.6,-293.454,37.9429,'Stitches Event'),
(412,48,-10882.9,-332.562,37.9688,'Stitches Event'),
(412,49,-10900,-365.26,39.4542,'Stitches Event'),
(412,50,-10904.1,-393.833,41.0451,'Stitches Event'),
(412,51,-10905.7,-431.964,42.7237,'Stitches Event'),
(412,52,-10908,-461.901,46.7191,'Stitches Event'),
(412,53,-10911.2,-510.492,52.0594,'Stitches Event'),
(412,54,-10915.1,-533.78,53.8047,'Stitches Event'),
(412,55,-10927,-565.685,54.042,'Stitches Event'),
(412,56,-10936.5,-581.62,53.8887,'Stitches Event'),
(412,57,-10950.1,-597.371,55.177,'Stitches Event'),
(412,58,-10957.9,-619.554,55.0689,'Stitches Event'),
(412,59,-10958.8,-637.183,55.2047,'Stitches Event'),
(412,60,-10954.3,-652.46,55.4423,'Stitches Event'),
(412,61,-10931.8,-681.568,55.3955,'Stitches Event'),
(412,62,-10916.9,-710.733,55.6988,'Stitches Event'),
(412,63,-10902.9,-734.1,55.1313,'Stitches Event'),
(412,64,-10878.3,-760.091,55.5638,'Stitches Event'),
(412,65,-10851.1,-787.76,56.1885,'Stitches Event'),
(412,66,-10831.9,-818.655,56.2795,'Stitches Event'),
(412,67,-10825.2,-833.223,55.5758,'Stitches Event'),
(412,68,-10808.3,-873.497,55.9567,'Stitches Event'),
(412,69,-10796.7,-912.719,55.8731,'Stitches Event'),
(412,70,-10796.1,-934.562,56.2303,'Stitches Event'),
(412,71,-10800.5,-949.721,56.5614,'Stitches Event'),
(412,72,-10807.1,-969.027,56.2941,'Stitches Event'),
(412,73,-10806.8,-992.166,53.8349,'Stitches Event'),
(412,74,-10804.6,-1030.41,47.0768,'Stitches Event'),
(412,75,-10801.3,-1047.26,44.0233,'Stitches Event'),
(412,76,-10787.8,-1074.49,37.7652,'Stitches Event'),
(412,77,-10783.3,-1095.07,33.6488,'Stitches Event'),
(412,78,-10781.2,-1112.66,30.3863,'Stitches Event'),
(412,79,-10763.6,-1138.91,27.0977,'Stitches Event'),
(412,80,-10738,-1158.02,26.4475,'Stitches Event'),
(412,81,-10705.3,-1179.29,26.3723,'Stitches Event'),
(412,82,-10682.3,-1190.45,27.2793,'Stitches Event'),
(412,83,-10662.5,-1193.06,28.2884,'Stitches Event'),
(412,84,-10641.6,-1189.92,28.5594,'Stitches Event'),
(412,85,-10615.7,-1182.78,28.5022,'Stitches Event'),
(412,86,-10586.8,-1177.32,28.3931,'Stitches Event'),
(412,87,-10576.4,-1179.26,28.1946,'Stitches Event'),
(412,88,-10566.7,-1189.27,27.8756,'Stitches Event'),
(412,89,-10557,-1192.38,28.0606,'Stitches Event'),
(412,90,-10550.4,-1185.71,27.8428,'Stitches Event'),
(412,91,-10554.4,-1167.97,27.5984,'Stitches Event');

/* Texts Stitches */
DELETE FROM `creature_text` WHERE `CreatureID` = 412;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(412,0,0,"ROARRRRR!!",14,0,100,0,0,0,278,2,"Stitches"),
(412,0,1,"DARKSHIRE... I HUNGER!!",14,0,100,0,0,0,277,2,"Stitches");


/*------------------------------------------- City Leadership ---------------------------------------------------------------------------------------------------*/


/* Lord Ello Ebonlocke */
DELETE FROM `smart_scripts` WHERE `entryorguid` = 263 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (26300,26301) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(263,0,0,0,25,0,100,0,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Lord Ello Ebonlocke - On Reset - Set Event Phase 1'),
(263,0,1,0,1,1,100,0,20000,30000,110000,130000,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Lord Ello Ebonlocke - Out of Combat - Say Line 0 (Phase 1)'),
(263,0,2,0,20,1,100,0,252,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Lord Ello Ebonlocke - On Quest \'Translation to Ello\' Finished - Set Active On (Phase 1)'),
(263,0,3,0,20,1,100,0,252,0,0,0,0,80,26300,2,0,0,0,0,1,0,0,0,0,0,0,0,0,'Lord Ello Ebonlocke - On Quest \'Translation to Ello\' Finished - Run Script 1 (Phase 1)'),
(263,0,4,0,20,0,100,0,252,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,'Lord Ello Ebonlocke - On Quest \'Translation to Ello\' Finished - Store Target'),
(263,0,5,0,38,0,100,0,1,1,0,0,0,80,26301,2,0,0,0,0,1,0,0,0,0,0,0,0,0,'Lord Ello Ebonlocke - On Data Set - Run Script 2'),
(263,0,6,0,69,0,100,0,85,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Lord Ello Ebonlocke - On Game Event \'Stitches\' End - Set Event Phase 1'),
(263,0,7,0,69,0,100,0,85,0,0,0,0,48,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Lord Ello Ebonlocke - On Game Event \'Stitches\' End - Set Active Off'),
(26300,9,0,0,0,0,100,0,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Lord Ello Ebonlocke - On Script 1 - Set Event Phase 0'),
(26300,9,1,0,0,0,100,0,0,0,0,0,0,12,1436,8,0,0,0,0,8,0,0,0,0,-10604.2,-1179.31,27.995,0.16,'Lord Ello Ebonlocke - On Script 1 - Summon Creature \'Watcher Cutford\''),
(26301,9,0,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,19,1436,0,0,0,0,0,0,0,'Lord Ello Ebonlocke - On Script 2 - Set Orientation'),
(26301,9,1,0,0,0,100,0,500,500,0,0,0,45,3,1,0,0,0,0,19,1436,0,0,0,0,0,0,0,'Lord Ello Ebonlocke - On Script 2 - Say Line 1 (Watcher Cutford)'),
(26301,9,2,0,0,0,100,0,5000,5000,0,0,0,45,3,2,0,0,0,0,19,1436,0,0,0,0,0,0,0,'Lord Ello Ebonlocke - On Script 2 - Say Line 2 (Watcher Cutford)'),
(26301,9,3,0,0,0,100,0,5000,5000,0,0,0,45,3,3,0,0,0,0,19,1436,0,0,0,0,0,0,0,'Lord Ello Ebonlocke - On Script 2 - Say Line 3 (Watcher Cutford)'),
(26301,9,4,0,0,0,100,0,4000,4000,0,0,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0,0,'Lord Ello Ebonlocke - On Script 2 - Say Line 1'),
(26301,9,5,0,0,0,100,0,5000,5000,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Lord Ello Ebonlocke - On Script 2 - Say Line 2'),
(26301,9,6,0,0,0,100,0,5500,5500,0,0,0,45,3,4,0,0,0,0,19,1436,0,0,0,0,0,0,0,'Lord Ello Ebonlocke - On Script 2 - Say Line 4 (Watcher Cutford)'),
(26301,9,7,0,0,0,100,0,3000,3000,0,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Lord Ello Ebonlocke - On Script - Set Orientation');


/* Commander Althea Ebonlocke */
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 264;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 264 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 26400 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(264,0,0,0,25,0,100,0,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Commander Althea Ebonlocke - On Reset - Set Event Phase 1'),
(264,0,1,0,1,1,100,0,1000,15000,150000,180000,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Commander Althea Ebonlocke - Out of Combat - Say Line 0 (Phase 1)'),
(264,0,2,0,38,0,100,0,1,1,0,0,0,80,26400,2,0,0,0,0,1,0,0,0,0,0,0,0,0,'Commander Althea Ebonlocke - On Data Set - Run Script'),
(264,0,3,0,38,0,100,0,1,1,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Commander Althea Ebonlocke - On Data Set - Set Active On'),
(264,0,4,0,69,0,100,0,85,0,0,0,0,48,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Commander Althea Ebonlocke - On Game Event \'Stitches\' End - Set Active Off'),
(264,0,5,0,38,1,100,0,1,2,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Commander Althea Ebonlocke - On Data Set - Say Line 2 (Phase 1)'),
(26400,9,0,0,0,0,100,0,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Commander Althea Ebonlocke - On Script - Set Event Phase 0'),
(26400,9,1,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,19,1436,0,0,0,0,0,0,0,'Commander Althea Ebonlocke - On Script - Set Orientation'),
(26400,9,2,0,0,0,100,0,500,500,0,0,0,45,3,5,0,0,0,0,19,1436,0,0,0,0,0,0,0,'Commander Althea Ebonlocke - On Script - Say Line 5 (Watcher Cutford)'),
(26400,9,3,0,0,0,100,0,7000,7000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Commander Althea Ebonlocke - On Script - Say Line 1'),
(26400,9,4,0,0,0,100,0,6500,6500,0,0,0,45,3,6,0,0,0,0,19,1436,0,0,0,0,0,0,0,'Commander Althea Ebonlocke - On Script - Say Line 6 (Watcher Cutford)'),
(26400,9,5,0,0,0,100,0,5000,5000,0,0,0,45,3,9,0,0,0,0,19,1436,0,0,0,0,0,0,0,'Commander Althea Ebonlocke - On Script - Say Line 7 (Watcher Cutford)'),
(26400,9,6,0,0,0,100,0,0,0,0,0,0,112,85,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'Commander Althea Ebonlocke - On Script - Start Game Event \'Stitches\''),
(26400,9,7,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Commander Althea Ebonlocke - On Script - Set Orientation'),
(26400,9,8,0,0,0,100,0,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Commander Althea Ebonlocke - On Script - Event Phase 1');


/* Town Crier */
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 468;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 468 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(468,0,0,0,68,0,100,0,85,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Town Crier - On Game Event \'Stitches\' Start - Set Active On'),
(468,0,1,2,69,0,100,0,85,0,0,0,0,48,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Town Crier - On Game Event \'Stitches\' End - Set Active Off'),
(468,0,2,0,61,0,100,0,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Town Crier - On Game Event \'Stitches\' End - Set Phase 0'),
(468,0,3,0,38,0,100,0,2,1,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Town Crier - On Data Set - Say Line 1'),
(468,0,4,0,38,0,100,0,2,2,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Town Crier - On Data Set - Say Line 2'),
(468,0,5,0,38,0,100,0,2,3,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Town Crier - On Data Set - Say Line 3'),
(468,0,6,0,38,0,100,0,2,4,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Town Crier - On Data Set - Say Line 4'),
(468,0,7,8,38,0,100,0,2,5,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Town Crier - On Data Set - Say Line 5'),
(468,0,8,0,61,0,100,0,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Town Crier - On Data Set - Set Phase 2'),
(468,0,9,10,1,2,100,0,300000,300000,300000,300000,0,111,85,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Town Crier - OOC (Phase 2) - Stop Event'),
(468,0,10,0,61,0,100,0,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Town Crier - OOC (Phase 2) - Set Phase 0'),
(468,0,11,0,11,0,100,0,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Town Crier - Spawn - Set Active');

/* Texts Town Crier, Mayor, Althea*/
DELETE FROM `creature_text` WHERE `CreatureID` = 468;
DELETE FROM `creature_text` WHERE `CreatureID` = 263 AND `GroupID` > 0; -- Mayor Ello
DELETE FROM `creature_text` WHERE `CreatureID` = 264 AND `GroupID` IN (1,2); -- Commander Althea
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(263,1,0,"This is grim news, and I fear it is linked to the dealings $n had with the Embalmer.",12,7,100,1,0,0,270,0,"Lord Ello Ebonlocke"),
(263,2,0,"Watcher, inform Althea that a dire threat is marshalling against our town.  We must prepare!",12,7,100,25,0,0,271,0,"Lord Ello Ebonlocke"),
(264,1,0,"This doesn't bode well.  Send scouts to gather more intelligence,and stay on alert.",12,7,100,1,0,0,273,0,"Commander Althea"),
(264,2,0,"It'll take more than a rotting corpse to stop us!",12,7,100,1,0,0,107,0,"Commander Althea"),
(468,1,0,"Rouse and to arms, citizens of Darkshire! An abomination of the undead approaches along the road!",14,7,100,22,0,0,89,2,"Town Crier"),
(468,2,0,"The abomination has overrun the Night Watch camp! Quickly, we must intercept it before it reaches town!",14,7,100,22,0,0,90,2,"Town Crier"),
(468,3,0,"It isn't enough! Defenders, gather in the center of town. Together we will stand against the undead monster!",14,7,100,22,0,0,91,2,"Town Crier"),
(468,4,0,"The abomination has come! Forward!",14,7,100,22,0,0,92,2,"Town Crier"),
(468,5,0,"The beast is slain! All's well in Darkshire!",14,7,100,22,0,0,93,2,"Town Crier");


/*------------------------------------------- Night Watchers ---------------------------------------------------------------------------------------------------*/

/* Remove Level 65 Watchers from Darkshire - Not in classic - Recycling GUIDS */
DELETE FROM `creature` WHERE `guid` IN (6127,6133);


/* Watcher Faction Fixes - Remove Stormwind 11 and 12 faction convert to Night Watcher factions */
UPDATE `creature_template` SET `faction` = 53 WHERE `entry` IN (494,495,826,827,885,886,999,8310);
UPDATE `creature_template` SET `faction` = 56 WHERE `entry` IN (576,2142,11040);

DELETE FROM `creature` WHERE `guid` IN (300001,300002,300003,300004,300005,300006); -- Reusing 6127 and 6133
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`wander_distance`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES 
(300001,28987,0,0,0,1,1,0,1,-10895.8,-381.028,40.125,2.669,300,0,0,0,0,0,0,0,0,'',0), -- Watcher Blomberg - New GUID 300001
(300002,1001,0,0,0,1,1,0,1,-10912,-388,40.632,0.812,300,0,0,0,0,0,0,0,0,'',0), -- Watcher Hutchins  - New GUID 300002
(300003,1098,0,0,0,1,1,0,1,-10776.7,-975.54,56.4,1.915,300,0,0,0,0,0,0,0,0,'',0), -- Watcher Merant - New GUID 300003
(300004,1099,0,0,0,1,1,0,1,-10777.7,-975.9,56.09,1.915,300,0,0,0,0,0,0,0,0,'',0), -- Watcher Gelwin - New GUID 300004
(300005,1100,0,0,0,1,1,0,1,-10775.7,-975.187,56.72,1.915,300,0,0,0,0,0,0,0,0,'',0), -- Watch Selkin - New GUID 300005
(300006,1101,0,0,0,1,1,0,1,-10778.6,-976.131,55.73,1.915,300,0,0,0,0,0,0,0,0,'',0), -- Watcher Thayer - New GUID 300006
(6127,1203,0,0,0,1,1,0,1,-10531.8,-1155.32,28.102,4.723,300,0,0,0,0,0,0,0,0,'',0), -- Watcher Sarys - Reused GUID 6127
(6133,1204,0,0,0,1,1,0,1,-10585.8,-1158.41,30.059,4.059,300,0,0,0,0,0,0,0,0,'',0); -- Watcher Corwin - Reused GUID 6133


/* Watcher Re-Positioning*/
UPDATE `creature` SET `position_x` = -10558.4,`position_y` = -1242.58,`position_z` = 30.2119,`orientation` = 4.9233 WHERE `guid` = 4180; -- Watcher Jan
UPDATE `creature` SET `position_x` = -10629.4,`position_y` = -1156.63,`position_z` = 26.0944,`orientation` = 3.6647 WHERE `guid` = 4244; -- Watcher Mocarski
UPDATE `creature` SET `position_x` = -10552.771,`position_y` = -1235.21,`position_z` = 28.572,`orientation` = 4.24204 WHERE `guid` = 4247; -- Watcher Petras
UPDATE `creature` SET `position_x` = -10583.7,`position_y` = -1184.22,`position_z` = 27.2057,`orientation` = 2.8019 WHERE `guid` = 5960; -- Watcher Frazier
UPDATE `creature` SET `position_x` = -10611.14,`position_y` = -1181.46,`position_z` = 28.446,`orientation` = 3.43 WHERE `guid` = 5941; -- Watcher Jordan
UPDATE `creature` SET `orientation` = 4.09 WHERE `guid` = 4181; -- Watcher Keller


-- Watcher Cutford
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 1436;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1436 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(1436,0,0,0,54,0,100,0,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Watcher Cutford - Just Summoned - Set Active On'),
(1436,0,1,0,54,0,100,0,0,0,0,0,0,53,1,1436,0,0,0,0,1,0,0,0,0,0,0,0,0,'Watcher Cutford - Just Summoned - Start Waypoint (No Repeat)'),
(1436,0,2,0,40,0,100,0,1,1436,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Watcher Cutford - On Waypoint 1 Reached - Say Line 0 (No Repeat)'),
(1436,0,3,0,40,0,100,0,12,1436,0,0,0,66,0,0,0,0,0,0,19,263,0,0,0,0,0,0,0,'Watcher Cutford - On Waypoint 12 Reached - Set Orientation'),
(1436,0,4,0,40,0,100,0,12,1436,0,0,0,54,28000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Watcher Cutford - On Waypoint 12 Reached - Pause Waypoint'),
(1436,0,5,0,40,0,100,0,12,1436,0,0,0,45,1,1,0,0,0,0,19,263,0,0,0,0,0,0,0,'Watcher Cutford - On Waypoint 12 Reached - Set Data'),
(1436,0,6,0,40,0,100,0,22,1436,0,0,0,66,0,0,0,0,0,0,19,264,0,0,0,0,0,0,0,'Watcher Cutford - On Waypoint 22 Reached - Set Orientation'),
(1436,0,7,0,40,0,100,0,22,1436,0,0,0,54,17000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Watcher Cutford - On Waypoint 22 Reached - Pause Waypoint'),
(1436,0,8,0,40,0,100,0,22,1436,0,0,0,45,1,1,0,0,0,0,19,264,0,0,0,0,0,0,0,'Watcher Cutford - On Waypoint 22 Reached - Set Data'),
(1436,0,9,0,40,0,100,0,61,1436,0,0,0,66,0.87,0,0,0,0,0,8,0,0,0,0,0,0,0,0,'Watcher Cutford - On Waypoint 61 Reached - Set Orientation'),
(1436,0,10,0,69,0,100,0,85,0,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Watcher Cutford - On Game Event \'Stitches\' End - Despawn In 1000 ms'),
(1436,0,11,0,38,0,100,0,3,1,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Watcher Cutford - On Data Set - Say line 1'),
(1436,0,12,0,38,0,100,0,3,2,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Watcher Cutford - On Data Set - Say line 2'),
(1436,0,13,0,38,0,100,0,3,3,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Watcher Cutford - On Data Set - Say line 3'),
(1436,0,14,0,38,0,100,0,3,4,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Watcher Cutford - On Data Set - Say line 4'),
(1436,0,15,0,38,0,100,0,3,5,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Watcher Cutford - On Data Set - Say line 5'),
(1436,0,16,0,38,0,100,0,3,6,0,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Watcher Cutford - On Data Set - Say line 6'),
(1436,0,17,0,38,0,100,0,3,9,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Watcher Cutford - On Data Set - Say line 0'),
(1436,0,18,0,40,0,100,0,39,1436,0,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Watcher Cutford - On Waypoint 39 Reached - Say Line 7 (No Repeat)'),
(1436,0,19,0,40,0,100,0,58,1436,0,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Watcher Cutford - On Waypoint 58 Reached - Say Line 7 (No Repeat)'),
(1436,0,20,0,40,0,100,0,0,0,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Watcher Cutford - On Reached WP - Set Home Position');


DELETE FROM `waypoints` WHERE `entry` = 1436;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(1436,1,-10584.2,-1174.31,28.662,'Watcher Cutford'),
(1436,2,-10557.4,-1149.16,28.033,'Watcher Cutford'),
(1436,3,-10559.6,-1132.51,30.067,'Watcher Cutford'),
(1436,4,-10565,-1124.78,30.067,'Watcher Cutford'),
(1436,5,-10569.2,-1125.4,29.2035,'Watcher Cutford'),
(1436,6,-10575,-1125.57,29.167,'Watcher Cutford'),
(1436,7,-10576.6,-1111.12,30.07,'Watcher Cutford'),
(1436,8,-10572.9,-1107.8,30.069,'Watcher Cutford'),
(1436,9,-10558.3,-1105.98,30.069,'Watcher Cutford'),
(1436,10,-10556,-1106.37,31.0298,'Watcher Cutford'),
(1436,11,-10555,-1106.46,31.429,'Watcher Cutford'),
(1436,12,-10553.4,-1106.64,31.428,'Watcher Cutford'),
(1436,13,-10558.3,-1105.98,30.069,'Watcher Cutford'),
(1436,14,-10572.8,-1107,30.071,'Watcher Cutford'),
(1436,15,-10576.6,-1111.12,30.07,'Watcher Cutford'),
(1436,16,-10575.7,-1116.16,30.0691,'Watcher Cutford'),
(1436,17,-10575.8,-1121.12,29.9733,'Watcher Cutford'),
(1436,18,-10575,-1125.57,29.167,'Watcher Cutford'),
(1436,19,-10565,-1124.78,30.067,'Watcher Cutford'),
(1436,20,-10559.6,-1132.51,30.067,'Watcher Cutford'),
(1436,21,-10557.5,-1146.89,28.034,'Watcher Cutford'),
(1436,22,-10559.3,-1151.77,28.034,'Watcher Cutford'),
(1436,23,-10568.3,-1154.32,27.412,'Watcher Cutford'),
(1436,24,-10582.2,-1173.28,28.53,'Watcher Cutford'),
(1436,25,-10623,-1183.54,28.819,'Watcher Cutford'),
(1436,26,-10641.6,-1188.92,28.5594,'Watcher Cutford'),
(1436,27,-10662.5,-1192.06,28.2884,'Watcher Cutford'),
(1436,28,-10682.3,-1189.45,27.2793,'Watcher Cutford'),
(1436,29,-10705.3,-1176.29,26.3723,'Watcher Cutford'),
(1436,30,-10738,-1155.52,26.4475,'Watcher Cutford'),
(1436,31,-10764.6,-1138.91,27.0977,'Watcher Cutford'),
(1436,32,-10780.2,-1112.66,30.3863,'Watcher Cutford'),
(1436,33,-10782.3,-1095.07,33.6488,'Watcher Cutford'),
(1436,34,-10786.8,-1074.49,37.7652,'Watcher Cutford'),
(1436,35,-10801.3,-1047.26,44.0233,'Watcher Cutford'),
(1436,36,-10804.6,-1030.41,47.0768,'Watcher Cutford'),
(1436,37,-10806.8,-992.166,53.8349,'Watcher Cutford'),
(1436,38,-10807.1,-969.027,56.2941,'Watcher Cutford'),
(1436,39,-10800.5,-949.721,56.5614,'Watcher Cutford'),
(1436,40,-10796.1,-934.562,56.2303,'Watcher Cutford'),
(1436,41,-10796.7,-912.719,55.8731,'Watcher Cutford'),
(1436,42,-10808.3,-873.497,55.9567,'Watcher Cutford'),
(1436,43,-10825.2,-833.223,55.5758,'Watcher Cutford'),
(1436,44,-10831.9,-818.655,56.2795,'Watcher Cutford'),
(1436,45,-10851.1,-787.76,56.1885,'Watcher Cutford'),
(1436,46,-10878.3,-760.091,55.5638,'Watcher Cutford'),
(1436,47,-10902.9,-734.1,55.1313,'Watcher Cutford'),
(1436,48,-10916.9,-710.733,55.6988,'Watcher Cutford'),
(1436,49,-10931.8,-681.568,55.3955,'Watcher Cutford'),
(1436,50,-10954.3,-652.46,55.4423,'Watcher Cutford'),
(1436,51,-10958.8,-637.183,55.2047,'Watcher Cutford'),
(1436,52,-10957.9,-619.554,55.0689,'Watcher Cutford'),
(1436,53,-10950.1,-597.371,55.177,'Watcher Cutford'),
(1436,54,-10936.5,-581.62,53.8887,'Watcher Cutford'),
(1436,55,-10927,-565.685,54.042,'Watcher Cutford'),
(1436,56,-10915.1,-533.78,53.8047,'Watcher Cutford'),
(1436,57,-10911.2,-510.492,52.0594,'Watcher Cutford'),
(1436,58,-10908,-461.901,46.7191,'Watcher Cutford'),
(1436,59,-10905.7,-431.964,42.7237,'Watcher Cutford'),
(1436,60,-10904.1,-393.833,41.0451,'Watcher Cutford'),
(1436,61,-10931.5,-385.877,40.085,'Watcher Cutford');

/* Texts Watcher Cutford */
DELETE FROM `creature_text` WHERE `CreatureID` = 1436;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(1436,0,0,"Make Way!  Make Way!",14,7,100,0,0,0,549,1,"Watcher Cutford"),
(1436,1,0,"Lord Mayor!  Our scouts report strange activity to the west.",12,7,100,5,0,0,265,0,"Watcher Cutford"),
(1436,1,1,"Mayor Ello!  Our graveyard scouts return with ominous reports...",12,7,100,5,0,0,266,0,"Watcher Cutford"),
(1436,2,0,"Hideous bellows and growls are heard coming from that old hermit's shack!",12,7,100,1,0,0,267,0,"Watcher Cutford"),
(1436,3,0,"Wolves head this way, as if fleeing from... something.",12,7,100,1,0,0,268,0,"Watcher Cutford"),
(1436,4,0,"Yes, Lord Mayor.",12,7,100,66,0,0,269,0,"Watcher Cutford"),
(1436,5,0,"Althea, there are reports of strange happenings at the graveyard.  Ello believes it portends an attack on Darkshire.",12,7,100,1,0,0,272,0,"Watcher Cutford"),
(1436,6,0,"Yes, commander!",12,7,100,66,0,0,275,0,"Watcher Cutford"),
(1436,7,0,"Beware!  Beware!  A threat lurks in the wild!  Night Watchers, be on the alert!",14,7,100,0,0,0,276,2,"Watcher Cutford");


-- Watcher Brownell - extra_flags
UPDATE `creature_template` SET `flags_extra` = 32768 WHERE `entry` = 11040; -- Changed from civilian to guard - Watchers should react to faction
 
 
-- Watcher Petras
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 828;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 828 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(828,0,1,0,1,0,100,0,2000,2000,0,0,0,53,0,828,1,0,0,2,1,0,0,0,0,0,0,0,0,'Watcher Petras - OOC - Start Waypoint (Repeat)');

DELETE FROM `waypoints` WHERE `entry` = 828;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(828,1,-10552.771,-1235.21,28.572,'Watcher Petras'),
(828,2,-10551.01,-1259.55,33.033,'Watcher Petras'),
(828,3,-10547.153,-1270.14,34.751,'Watcher Petras'),
(828,4,-10537.10,-1278.2,37.51,'Watcher Petras'),
(828,5,-10532.41,-1282.53,38.812,'Watcher Petras'),
(828,6,-10531.03,-1285.52,39.327,'Watcher Petras'),
(828,7,-10531.954,-1303.83,41.6253,'Watcher Petras'),
(828,8,-10541.782,-1327.909,45.989,'Watcher Petras'),
(828,9,-10531.954,-1303.83,41.6253,'Watcher Petras'),
(828,10,-10531.03,-1285.52,39.327,'Watcher Petras'),
(828,11,-10532.41,-1282.53,38.812,'Watcher Petras'),
(828,12,-10537.10,-1278.2,37.51,'Watcher Petras'),
(828,13,-10547.153,-1270.14,34.751,'Watcher Petras'),
(828,14,-10551.01,-1259.55,33.033,'Watcher Petras'),
(828,15,-10552.771,-1235.21,28.572,'Watcher Petras');


-- Watcher Jordan
DELETE FROM `waypoint_data` WHERE `id` = 59410;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES 
(59410,1,-10611.14,-1181.46,28.446,0,0,0,0,100,0),
(59410,2,-10623,-1184.54,28.819,0,0,0,0,100,0),
(59410,3,-10641.6,-1189.92,28.5594,0,0,0,0,100,0),
(59410,4,-10662.5,-1193.06,28.2884,0,0,0,0,100,0),
(59410,5,-10682.3,-1190.45,27.2793,0,0,0,0,100,0),
(59410,6,-10705.3,-1179.29,26.3723,0,0,0,0,100,0),
(59410,7,-10738,-1158.02,26.4475,0,0,0,0,100,0),
(59410,8,-10763.6,-1138.91,27.0977,0,0,0,0,100,0),
(59410,9,-10781.2,-1112.66,30.3863,0,0,0,0,100,0),
(59410,10,-10783.3,-1095.07,33.6488,0,0,0,0,100,0),
(59410,11,-10787.8,-1074.49,37.7652,0,0,0,0,100,0),
(59410,12,-10789.49,-1067.8,39.138,0,0,0,0,100,0),
(59410,13,-10787.8,-1074.49,37.7652,0,0,0,0,100,0),
(59410,14,-10783.3,-1095.07,33.6488,0,0,0,0,100,0),
(59410,15,-10781.2,-1112.66,30.3863,0,0,0,0,100,0),
(59410,16,-10763.6,-1138.91,27.0977,0,0,0,0,100,0),
(59410,17,-10738,-1158.02,26.4475,0,0,0,0,100,0),
(59410,18,-10705.3,-1179.29,26.3723,0,0,0,0,100,0),
(59410,19,-10682.3,-1190.45,27.2793,0,0,0,0,100,0),
(59410,20,-10662.5,-1193.06,28.2884,0,0,0,0,100,0),
(59410,21,-10641.6,-1189.92,28.5594,0,0,0,0,100,0),
(59410,22,-10623,-1184.54,28.819,0,0,0,0,100,0);


/*Night Watch Camp Defenders*/
-- Watcher Paige 
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 499;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 499 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(499,0,0,1,38,0,100,0,1,1,0,0,0,53,1,499,0,0,0,2,1,0,0,0,0,0,0,0,0,'Watcher Paige - On Data Set - Start Waypoint (No Repeat)'),
(499,0,1,0,61,0,100,0,0,0,0,0,0,17,333,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Watcher Paige - On Data Set - Continuous Attack Emote"),
(499,0,2,3,38,0,100,0,1,2,0,0,0,101,1,0,0,0,0,0,8,0,0,0,0,-10934.5,-381.812988,40.197601,0.174533,"Watcher Paige - On Data Set - Set Home POS"),
(499,0,3,4,61,0,100,0,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Watcher Paige - On Data Set - Evade"),
(499,0,4,0,61,0,100,0,0,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Watcher Paige - On Data Set - Normal Emote"),
(499,0,5,0,69,0,100,0,85,0,0,0,0,70,2,0,0,0,0,0,19,499,0,1,0,0,0,0,0,"Watcher Paige - On Game Event \'Stitches\' End - Respawn"),
(499,0,6,0,68,0,100,0,85,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Watcher Paige - On Game Event \'Stitches\' Start - React State Aggressive');

DELETE FROM `waypoints` WHERE `entry` = 499;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(499,1,-10907.58,-387.349,40.778,'Watcher Paige'),
(499,2,-10901.78,-376.94,40.07,'Watcher Paige');


-- Watcher Dodds
UPDATE `creature_template` SET `AIName` = "SmartAI",`unit_flags` = 4096,`flags_extra` = 0 WHERE `entry` = 888;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 888 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(888,0,0,1,38,0,100,0,1,1,0,0,0,53,1,888,0,0,0,2,1,0,0,0,0,0,0,0,0,'Watcher Dodds - On Data Set - Start Waypoint (No Repeat)'),
(888,0,1,0,61,0,100,0,0,0,0,0,0,17,333,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Watcher Dodds - On Data Set - Continuous Attack Emote"),
(888,0,2,3,38,0,100,0,1,2,0,0,0,101,1,0,0,0,0,0,8,0,0,0,0,-10923.200195,-384.928009,39.434399,0.942478,"Watcher Dodds - On Data Set - Set Home POS"),
(888,0,3,4,61,0,100,0,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Watcher Dodds - On Data Set - Evade"),
(888,0,4,0,61,0,100,0,0,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Watcher Dodds - On Data Set - Normal Emote"),
(888,0,5,0,69,0,100,0,85,0,0,0,0,70,2,0,0,0,0,0,19,888,0,1,0,0,0,0,0,"Watcher Dodds - On Game Event \'Stitches\' End - Respawn");

DELETE FROM `waypoints` WHERE `entry` = 888;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(888,1,-10907.58,-387.349,40.778,'Watcher Dodds'),
(888,2,-10900.63,-373.55,39.92,'Watcher Dodds');


-- Watcher Hutchins
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 1001;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1001 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(1001,0,0,1,38,0,100,0,1,1,0,0,0,53,1,1001,0,0,0,2,1,0,0,0,0,0,0,0,0,'Watcher Hutchins - On Data Set - Start Waypoint (No Repeat)'),
(1001,0,1,0,61,0,100,0,0,0,0,0,0,17,333,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Watcher Hutchins - On Data Set - Continuous Attack Emote"),
(1001,0,2,3,38,0,100,0,1,2,0,0,0,101,1,0,0,0,0,0,8,0,0,0,0,-10912,-388,40.632,0.812,"Watcher Hutchins - On Data Set - Set Home POS"),
(1001,0,3,4,61,0,100,0,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Watcher Hutchins - On Data Set - Evade"),
(1001,0,4,0,61,0,100,0,0,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Watcher Hutchins - On Data Set - Normal Emote"),
(1001,0,5,0,69,0,100,0,85,0,0,0,0,70,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Watcher Hutchins - On Game Event \'Stitches\' End - Respawn"),
(1001,0,6,0,11,0,100,0,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Watcher Hutchins - On Spawn - React State Aggressive');

DELETE FROM `creature_addon` WHERE `guid` = 300002;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`isLarge`,`auras`) VALUES
(300002,0,0,0,4097,0,0,NULL);

DELETE FROM `waypoints` WHERE `entry` = 1001;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(1001,1,-10912,-388,40.632,'Watcher Hutchins'),
(1001,2,-10905.447,-382.46,40.407,'Watcher Hutchins'),
(1001,3,-10902.4,-374.68,39.9529,'Watcher Hutchins');


-- Watcher Blomberg
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 28987;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 28987 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(28987,0,0,1,38,0,100,0,1,1,0,0,0,53,1,28987,0,0,0,2,1,0,0,0,0,0,0,0,0,'Watcher Blomberg - On Data Set - Start Waypoint (No Repeat)'),
(28987,0,1,0,61,0,100,0,0,0,0,0,0,17,333,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Watcher Blomberg - On Data Set - Continuous Attack Emote"),
(28987,0,2,3,38,0,100,0,1,2,0,0,0,101,1,0,0,0,0,0,8,0,0,0,0,-10895.825,-381.028,40.125,2.669,"Watcher Blomberg - On Data Set - Set Home POS"),
(28987,0,3,4,61,0,100,0,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Watcher Blomberg - On Data Set - Evade"),
(28987,0,4,0,61,0,100,0,0,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Watcher Blomberg - On Data Set - Normal Emote"),
(28987,0,5,0,69,0,100,0,85,0,0,0,0,70,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Watcher Blomberg - On Game Event \'Stitches\' End - Respawn"),
(28987,0,6,0,11,0,100,0,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Watcher Blomberg - On Spawn - React State Aggressive');

DELETE FROM `creature_addon` WHERE `guid` = 300001;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`isLarge`,`auras`) VALUES
(300001,0,0,0,4097,0,0,NULL);

DELETE FROM `waypoints` WHERE `entry` = 28987;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(28987,1,-10895.825,-381.028,40.125,'Watcher Blomberg'),
(28987,2,-10901.901,-380.05,40.123,'Watcher Blomberg'),
(28987,3,-10900.4,-375.921,40.0489,'Watcher Blomberg');


/* -- The Rotting Orchard Crossroads Defenders */
-- Watcher Merant
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 1098;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1098 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(1098,0,0,1,11,0,100,0,0,0,0,0,0,11,16380,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Watcher Merant - On Spawn - Invisible'),
(1098,0,1,0,61,0,100,0,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Watcher Merant - On Respawn - Set Active On'),
(1098,0,2,3,38,0,100,0,1,1,0,0,0,53,1,1098,0,0,0,2,1,0,0,0,0,0,0,0,0,'Watcher Merant - On Data Set - Start Waypoint (No Repeat)'),
(1098,0,3,4,61,0,100,0,0,0,0,0,0,28,16380,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Watcher Merant - On move - Remove Invisiblility'),
(1098,0,4,0,61,0,100,0,0,0,0,0,0,17,333,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Watcher Merant - On Data Set - Continuous Attack Emote"),
(1098,0,5,0,69,0,100,0,85,0,0,0,0,70,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Watcher Merant - On Game Event \'Stitches\' End - Respawn"),
(1098,0,6,0,6,0,100,0,0,0,0,0,0,48,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Watcher Merant - On Death - Set Active Off'),
(1098,0,7,0,11,0,100,0,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Watcher Merant - On Spawn - React State Aggressive'),
(1098,0,8,9,38,0,100,0,1,2,0,0,0,48,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Watcher Merant - On Data Set - Active Off'),
(1098,0,9,10,61,0,100,0,0,0,0,0,0,11,16380,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Watcher Merant - On Data Set - Invisible'),
(1098,0,10,0,61,0,100,0,0,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Watcher Merant - On Data Set - Normal Emote");

DELETE FROM `creature_addon` WHERE `guid` = 300003;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`isLarge`,`auras`) VALUES
(300003,0,0,0,4097,0,0,NULL);

DELETE FROM `waypoints` WHERE `entry` = 1098;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(1098,1,-10776.661,-975.54,56.4,'Watcher Merant'),
(1098,2,-10805.693,-878.18,55.87,'Watcher Merant'),
(1098,3,-10827.266,-828.594,55.547,'Watcher Merant');


-- Watcher Gelwin
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 1099;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1099 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(1099,0,0,0,69,0,100,0,85,0,0,0,0,70,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Watcher Gelwin - On Game Event \'Stitches\' End - Respawn"),
(1099,0,1,0,11,0,100,0,0,0,0,0,0,11,16380,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Watcher Gelwin - On Spawn - Invisible'),
(1099,0,2,3,38,0,100,0,1,1,0,0,0,53,1,1099,0,0,0,2,1,0,0,0,0,0,0,0,0,'Watcher Gelwin - On Data Set - Start Waypoint (No Repeat)'),
(1099,0,3,4,61,0,100,0,0,0,0,0,0,28,16380,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Watcher Gelwin - On move - Remove Invisiblility'),
(1099,0,4,0,61,0,100,0,0,0,0,0,0,17,333,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Watcher Gelwin - On Data Set - Continuous Attack Emote"),
(1099,0,5,0,11,0,100,0,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Watcher Gelwin - On Spawn - React State Aggressive'),
(1099,0,6,7,38,0,100,0,1,2,0,0,0,11,16380,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Watcher Gelwin - On Data Set - Invisible'),
(1099,0,7,0,61,0,100,0,0,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Watcher Gelwin - On Data Set - Normal Emote");

DELETE FROM `creature_addon` WHERE `guid` = 300004;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`isLarge`,`auras`) VALUES
(300004,0,0,0,4097,0,0,NULL);

DELETE FROM `waypoints` WHERE `entry` = 1099;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(1099,1,-10777.65,-975.9,56.09,'Watcher Gelwin'),
(1099,2,-10806.98,-878.849,55.75,'Watcher Gelwin'),
(1099,3,-10827.5996,-831.325,55.638,'Watcher Gelwin');


-- Watcher Selkin
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 1100;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1100 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(1100,0,0,0,69,0,100,0,85,0,0,0,0,70,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Watcher Selkin - On Game Event \'Stitches\' End - Respawn"),
(1100,0,1,0,11,0,100,0,0,0,0,0,0,11,16380,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Watcher Selkin - On Spawn - Invisible'),
(1100,0,2,3,38,0,100,0,1,1,0,0,0,53,1,1100,0,0,0,2,1,0,0,0,0,0,0,0,0,'Watcher Selkin - On Data Set - Start Waypoint (No Repeat)'),
(1100,0,3,4,61,0,100,0,0,0,0,0,0,28,16380,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Watcher Selkin - On move - Remove Invisiblility'),
(1100,0,4,0,61,0,100,0,0,0,0,0,0,17,333,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Watcher Selkins - On Data Set - Continuous Attack Emote"),
(1100,0,5,0,11,0,100,0,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Watcher Selkin - On Spawn - React State Aggressive'),
(1100,0,6,7,38,0,100,0,1,2,0,0,0,11,16380,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Watcher Selkin - On Data Set - Invisible'),
(1100,0,7,0,61,0,100,0,0,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Watcher Selkin - On Data Set - Normal Emote");

DELETE FROM `creature_addon` WHERE `guid` = 300005;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`isLarge`,`auras`) VALUES
(300005,0,0,0,4097,0,0,NULL);

DELETE FROM `waypoints` WHERE `entry` = 1100;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(1100,1,-10775.67,-975.187,56.72,'Watcher Selkin'),
(1100,2,-10804.816,-877.659,55.896,'Watcher Selkin'),
(1100,3,-10825.556,-830.715,55.539,'Watcher Selkin');


-- Watcher Thayer
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 1101;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1101 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(1101,0,0,0,69,0,100,0,85,0,0,0,0,70,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Watcher Thayer - On Game Event \'Stitches\' End - Respawn"),
(1101,0,1,0,11,0,100,0,0,0,0,0,0,11,16380,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Watcher Thayer - On Spawn - Invisible'),
(1101,0,2,3,38,0,100,0,1,1,0,0,0,53,1,1101,0,0,0,2,1,0,0,0,0,0,0,0,0,'Watcher Thayer - On Data Set - Start Waypoint (No Repeat)'),
(1101,0,3,4,61,0,100,0,0,0,0,0,0,28,16380,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Watcher Thayer - On Move - Remove Invisiblility'),
(1101,0,4,0,61,0,100,0,0,0,0,0,0,17,333,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Watcher Thayer - On Data Set - Continuous Attack Emote"),
(1101,0,5,0,11,0,100,0,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Watcher Thayer - On Spawn - React State Aggressive'),
(1101,0,6,7,38,0,100,0,1,2,0,0,0,11,16380,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Watcher Thayer - On Data Set - Invisible'),
(1101,0,7,0,61,0,100,0,0,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Watcher Thayer - On Data Set - Normal Emote");

DELETE FROM `creature_addon` WHERE `guid` = 300006;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`isLarge`,`auras`) VALUES
(300006,0,0,0,4097,0,0,NULL);

DELETE FROM `waypoints` WHERE `entry` = 1101;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(1101,1,-10778.641,-976.131,55.73,'Watcher Thayer'),
(1101,2,-10808.76,-879.42,55.75,'Watcher Thayer'),
(1101,3,-10829.408,-829.255,55.609,'Watcher Thayer');


/*-- Watchers Defending Darkshire */
-- Watcher Frazier
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 2470; 
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2470 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(2470,0,0,1,38,0,100,0,1,1,0,0,0,69,0,0,0,0,0,0,1,0,0,0,0,-10591.564,-1177.667,28.381,3.38,"Watcher Frazier - On Data Set - Move to POS"),
(2470,0,1,0,61,0,100,0,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Watcher Frazier - On Data Set - Set Phase 2'),
(2470,0,2,3,1,2,100,0,2000,2000,2000,2000,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,3.4,'Watcher Frazier - OOC (Phase 2) - Set Orientation'),
(2470,0,3,4,61,0,100,0,0,0,0,0,0,17,333,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Watcher Frazier - OOC (Phase 2) - Continuous Attack Emote"),
(2470,0,4,0,61,0,100,0,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Watcher Frazier - OOC (Phase 2) - Set Phase 0'),
(2470,0,5,6,38,0,100,0,1,2,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Watcher Frazier - On Data Set - Evade"),
(2470,0,6,0,61,0,100,0,0,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Watcher Frazier - On Data Set - Normal Emote"),
(2470,0,7,0,69,0,100,0,85,0,0,0,0,70,2,0,0,0,0,0,19,2470,0,1,0,0,0,0,0,"Watcher Frazier- On Game Event \'Stitches\' End - Respawn");


-- Watcher Sarys
UPDATE `creature_template` SET `AIName` = "SmartAI", `DamageModifier` = 3.5 WHERE `entry` = 1203;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1203 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(1203,0,0,0,11,0,100,0,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Watcher Sarys - On Spawn - React State Aggressive'),
(1203,0,1,2,38,0,100,0,1,1,0,0,0,53,1,1203,0,0,0,2,1,0,0,0,0,0,0,0,0,'Watcher Sarys - On Data Set - Start Waypoint (No Repeat)'),
(1203,0,2,0,61,0,100,0,0,0,0,0,0,17,333,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Watcher Sarys - On Data Set - Continuous Attack Emote"),
(1203,0,3,4,38,0,100,0,1,2,0,0,0,101,1,0,0,0,0,0,8,0,0,0,0,-10536.224,-1159.281,28.088,0.083,"Watcher Sarys - On Data Set - Set Home POS"),
(1203,0,4,5,61,0,100,0,0,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Watcher Sarys - On Data Set - Normal Emote"),
(1203,0,5,0,61,0,100,0,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Watcher Sarys - On Data Set - Evade"),
(1203,0,6,0,69,0,100,0,85,0,0,0,0,70,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Watcher Sarys - On Game Event \'Stitches\' End - Respawn");

DELETE FROM `creature_addon` WHERE `guid` = 6127;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`isLarge`,`auras`) VALUES
(6127,0,0,0,4097,0,0,NULL);

DELETE FROM `waypoints` WHERE `entry` = 1203;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(1203,1,-10531.201,-1166.305,28.102,'Watcher Sarys'),
(1203,2,-10535.651,-1167.243,28.102,'Watcher Sarys'),
(1203,3,-10536.224,-1159.281,28.088,'Watcher Sarys'),
(1203,4,-10564.808,-1161.135,27.475,'Watcher Sarys'),
(1203,5,-10577.798,-1174.569,28.353,'Watcher Sarys'),
(1203,6,-10592.168,-1175.163,28.566,'Watcher Sarys');


-- Watcher Corwin
UPDATE `creature_template` SET `AIName` = "SmartAI", `DamageModifier` = 4 WHERE `entry` = 1204;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1204 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(1204,0,0,0,11,0,100,0,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Watcher Corwin - On Spawn - React State Aggressive'),
(1204,0,1,2,38,0,100,0,1,1,0,0,0,53,1,1204,0,0,0,2,1,0,0,0,0,0,0,0,0,'Watcher Corwin - On Data Set - Start Waypoint (No Repeat)'),
(1204,0,2,0,61,0,100,0,0,0,0,0,0,17,333,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Watcher Corwin - On Data Set - Continuous Attack Emote"),
(1204,0,3,4,38,0,100,0,1,2,0,0,0,101,1,0,0,0,0,0,8,0,0,0,0,-10585.755,-1158.408,30.059,4.059,"Watcher Corwin - On Data Set - Set Home POS"),
(1204,0,4,5,61,0,100,0,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Watcher Corwin - On Data Set - Evade"),
(1204,0,5,0,61,0,100,0,0,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Watcher Corwin - On Data Set - Normal Emote"),
(1204,0,6,0,69,0,100,0,85,0,0,0,0,70,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Watcher Corwin - On Game Event \'Stitches\' End - Respawn");

DELETE FROM `creature_addon` WHERE `guid` = 6133;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`isLarge`,`auras`) VALUES
(6133,0,0,0,4097,0,0,NULL);

DELETE FROM `waypoints` WHERE `entry` = 1204;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(1204,1,-10585.852,-1164.043,30.017,'Watcher Corwin'),
(1204,2,-10580.443,-1170.46,28.386,'Watcher Corwin'),
(1204,3,-10581.109,-1173.567,28.497,'Watcher Corwin'),
(1204,4,-10594.054,-1176.725,28.432,'Watcher Corwin');

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
