-- Zeppelin: <The Zephyr> "Durotar to Thunder Bluff"
SET @GUID := 43468;
DELETE FROM `creature` WHERE `guid` BETWEEN @GUID AND @GUID+11;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@GUID,3084,647,1,1,0,0,-4.83257,-4.312334,-17.63218,1.623156,180,0,0,1,0,0), -- Bluffwatcher
(@GUID+1,3084,647,1,1,0,0,-5.206744,-11.34318,-17.61012,4.712389,180,0,0,1,0,0), -- Bluffwatcher
(@GUID+2,24934,647,1,1,0,0,10.32099,-3.573514,-23.49413,3.176499,180,0,0,1,0,0), -- Snack-O-Matic IV
(@GUID+3,24935,647,1,1,0,0,10.2871,-12.02722,-23.49424,3.106686,180,0,0,1,0,0), -- Vend-O-Tron D-Luxe
(@GUID+4,25075,647,1,1,0,0,-3.396398,-7.905448,-23.69672,6.248279,180,0,0,1,0,0), -- Zeppelin Controls
(@GUID+5,34715,647,1,1,0,0,-9.183155,-7.775729,-17.21699,3.281219,180,0,0,1,0,0), -- Sky-Captain "Dusty" Blastnut <The Zephyr>
(@GUID+6,34717,647,1,1,0,0,-13.67017,-12.40177,-15.98756,4.590216,180,0,0,1,0,2), -- Crewman Pipewrench <The Zephyr>
(@GUID+7,34718,647,1,1,0,0,13.74505,-5.128461,-24.04518,0.1396263,180,0,0,1,0,0), -- Crewman Deadbolt <The Zephyr>
(@GUID+8,34719,647,1,1,0,0,7.623085,-5.025319,-17.67015,4.921828,180,0,0,1,0,0), -- Crewman Grit <The Zephyr>
(@GUID+9,34721,647,1,1,0,0,-0.919197,-6.164221,-23.67286,3.577925,180,0,0,1,0,0), -- Chief Officer Ograh <The Zephyr>
(@GUID+10,34723,647,1,1,0,0,-17.47968,-5.606984,-14.92807,3.228859,180,0,0,1,0,0), -- Watcher Tolwe <The Zephyr>
(@GUID+11,34730,647,1,1,0,0,-2.166869,-7.854215,-23.6919,3.385939,180,0,0,1,0,0); -- Navigator Zippik <The Zephyr>
DELETE FROM `creature_template_addon` WHERE `entry` IN (34718,34719);
INSERT INTO `creature_template_addon` (`entry`,`bytes1`,`bytes2`,`emote`) VALUES
(34718,3,1,0),(34719,0,1,133);
-- Pathing for Crewman Pipewrench <The Zephyr> Entry: 34717
SET @NPC := @GUID+6;
SET @PATH := @NPC * 10;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,1,69, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-13.66992,-12.40186,-16.09792,4.590216,26000,0,0,100,0),
(@PATH,2,-14.49512,-9.873911,-15.99125,0,0,0,0,100,0),
(@PATH,3,-14.49512,-6.373911,-15.99125,0,0,0,0,100,0),
(@PATH,4,-14.31525,-3.41333,-15.88589,0,24000,0,0,100,0);
-- Zeppelin: <The Zephyr> SAI
SET @ENTRY  := 190549;
UPDATE `gameobject_template` SET `AIName`= 'SmartGameObjectAI',`ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY*100,@ENTRY*100+1,@ENTRY*100+2,@ENTRY*100+3) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,1,0,0,71,0,100,0,21868,0,0,0,80,@ENTRY*100  ,0,0,0,0,0,1,0,0,0,0,0,0,0,'Zeppelin: <The Zephyr> - Event Dock Orgrimmar - Run Script'),
(@ENTRY,1,1,0,71,0,100,0,21869,0,0,0,80,@ENTRY*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Zeppelin: <The Zephyr> - Event Leave Orgrimmar - Run Script'),
(@ENTRY,1,2,0,71,0,100,0,21870,0,0,0,80,@ENTRY*100+2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Zeppelin: <The Zephyr> - Event Dock Thunder Bluff - Run Script'),
(@ENTRY,1,3,0,71,0,100,0,21871,0,0,0,80,@ENTRY*100+3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Zeppelin: <The Zephyr> - Event Leave Thunder Bluff - Run Script'),
-- Script 0
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,19,34715,100,0,0,0,0,0,'Zeppelin: <The Zephyr> - Script Dock Orgrimmar - Sky-Captain Blastnut Say 0'),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,19,34721,100,0,0,0,0,0,'Zeppelin: <The Zephyr> - Script Dock Orgrimmar - Chief Officer Ograh Say 1'),
(@ENTRY*100,9,2,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,19,34765,100,0,0,0,0,0,'Zeppelin: <The Zephyr> - Script Dock Orgrimmar - Zelli Hotnozzle Say 0'),
(@ENTRY*100,9,3,0,0,0,100,0,3000,3000,0,0,5,5,0,0,0,0,0,19,34715,100,0,0,0,0,0,'Zeppelin: <The Zephyr> - Script Dock Orgrimmar - Sky-Captain Blastnut emote'),
(@ENTRY*100,9,4,0,0,0,100,0,1000,1000,0,0,5,25,0,0,0,0,0,19,34721,100,0,0,0,0,0,'Zeppelin: <The Zephyr> - Script Dock Orgrimmar - Chief Officer Ograh emote'),
-- Script 1
(@ENTRY*100+1,9,0,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,19,34715,100,0,0,0,0,0,'Zeppelin: <The Zephyr> - Script Leave Orgrimmar - Sky-Captain Blastnut Say 1'),
(@ENTRY*100+1,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,19,34721,100,0,0,0,0,0,'Zeppelin: <The Zephyr> - Script Leave Orgrimmar - Chief Officer Ograh Say 0'),
(@ENTRY*100+1,9,2,0,0,0,100,0,4000,4000,0,0,5,25,0,0,0,0,0,19,34721,100,0,0,0,0,0,'Zeppelin: <The Zephyr> - Script Leave Orgrimmar - Chief Officer Ograh emote'),
-- Script 2
(@ENTRY*100+2,9,0,0,0,0,100,0,0,0,0,0,1,2,0,0,0,0,0,19,34715,100,0,0,0,0,0,'Zeppelin: <The Zephyr> - Script Dock Thunder Bluff - Sky-Captain Blastnut Say 2'),
(@ENTRY*100+2,9,1,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,19,34721,100,0,0,0,0,0,'Zeppelin: <The Zephyr> - Script Dock Thunder Bluff - Chief Officer Ograh Say 1'),
(@ENTRY*100+2,9,2,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,19,34766,100,0,0,0,0,0,'Zeppelin: <The Zephyr> - Script Dock Thunder Bluff - Krendle Bigpockets Say 0'),
(@ENTRY*100+2,9,3,0,0,0,100,0,3000,3000,0,0,5,5,0,0,0,0,0,19,34715,100,0,0,0,0,0,'Zeppelin: <The Zephyr> - Script Dock Thunder Bluff - Sky-Captain Blastnut emote'),
(@ENTRY*100+2,9,4,0,0,0,100,0,1000,1000,0,0,5,25,0,0,0,0,0,19,34721,100,0,0,0,0,0,'Zeppelin: <The Zephyr> - Script Dock Thunder Bluff - Chief Officer Ograh emote'),
-- Script 3
(@ENTRY*100+3,9,0,0,0,0,100,0,0,0,0,0,1,3,0,0,0,0,0,19,34715,100,0,0,0,0,0,'Zeppelin: <The Zephyr> - Script Leave Thunder Bluff - Sky-Captain Blastnut Say 3'),
(@ENTRY*100+3,9,1,0,0,0,100,0,0,0,0,0,1,2,0,0,0,0,0,19,34721,100,0,0,0,0,0,'Zeppelin: <The Zephyr> - Script Leave Thunder Bluff - Chief Officer Ograh Say 2'),
(@ENTRY*100+3,9,2,0,0,0,100,0,4000,4000,0,0,5,25,0,0,0,0,0,19,34721,100,0,0,0,0,0,'Zeppelin: <The Zephyr> - Script Leave Thunder Bluff - Chief Officer Ograh emote');
-- Watcher Tolwe <The Zephyr> SAI
SET @ENTRY  := 34723;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,60000,120000,60000,120000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Watcher Tolwe <The Zephyr> - OOC - Say Random');
-- Text for Watcher Tolwe, Sky-Captain Blastnut, Chief Officer Ograh, Krendle Bigpockets, & Zelli Hotnozzle
DELETE FROM `creature_text` WHERE `entry` IN (34723,34715,34721,34766,34765);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(34723,0,0,'Dat cloud look like da Warchief.',12,1,100,25,0,0,'Watcher Tolwe - Random'),
(34723,0,1,'Dere be a bug.',12,1,100,25,0,0,'Watcher Tolwe - Random'),
(34723,0,2,'Ware da ship! A harpy! ...wait, dat be another bird.',12,1,100,25,0,0,'Watcher Tolwe - Random'),
(34723,0,3,'Dere be a bird!',12,1,100,25,0,0,'Watcher Tolwe - Random'),
(34715,0,0,'And there''s Orgrimmar, huge and menacing like always. Take a quick break, boys, then it''s back to the Bluff!',12,1,100,1,0,0,'Sky-Captain Blastnut - Dock at Orgrimmar'), -- wait 3 sec do emote 5
(34715,1,0,'Next stop, Thunder Bluff',12,1,100,5,0,0,'Sky-Captain Blastnut - Leave for Thunder Bluff'),
(34715,2,0,'Watch your step! Don''t want you becoming a smudge down there. Welcome to Thunder Bluff!',12,1,100,1,0,0,'Sky-Captain Blastnut - Dock at Thunder Bluff'), -- wait 3 sec do emote 5
(34715,3,0,'Okay, boys, let''s get this baby over to Orgrimmar!',12,1,100,25,0,0,'Sky-Captain Blastnut - Leave for Orgrimmar'),
(34721,0,0,'Move it, Zippik! We don''t have all day!',12,1,100,5,0,0,'Chief Officer Ograh - Leave for Thunder Bluff'),
(34721,1,0,'Careful. CAREFUL! Did I feel a shudder? You''re going to knock that tower down, oaf!',12,1,100,5,0,0,'Chief Officer Ograh - Dock at Orgrimmar & Thunder Bluff'),
(34721,2,0,'We''re behind schedule! Turn this tub east! EAST!',12,1,100,5,0,0,'Chief Officer Ograh - Leave for Orgrimmar'),
(34766,0,0,'Step right up! The zeppelin to Orgrimmar has arrived! All aboard to Durotar!',14,0,100,22,0,11804,'Krendle Bigpockets - Dock at Thunder Bluff'),
(34765,0,0,'The zeppelin to Thunder Bluff has arrived! All aboard for a smooth ride across the Barrens!',14,0,100,22,0,11804,'Zelli Hotnozzle - Dock at Orgrimmar');
