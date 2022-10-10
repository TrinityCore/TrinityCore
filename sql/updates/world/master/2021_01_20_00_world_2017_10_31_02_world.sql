-- master only
UPDATE `creature` SET `guid`= 2499 WHERE `guid`= 311219;
DELETE FROM `creature_addon` WHERE `guid`=2499;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES (2499, 0, 0, 0, 4097, 0, 0, NULL);


-- Add script to Sethir the Ancient
SET @ENTRY := 6909;
SET @ACTIONLIST_0 := @ENTRY * 100;
SET @ACTIONLIST_1 := @ENTRY * 100 + 1;
SET @ACTIONLIST_2 := @ENTRY * 100 + 2;
SET @ACTIONLIST_3 := @ENTRY * 100 + 3;

-- Fix spawn loaction and respawn timer
UPDATE `creature` SET `position_x`=11052.97, `position_y`=1921.79, `position_z`=1332.839, `orientation`=3.7522, `spawntimesecs`=60 WHERE `guid`=2499;

-- Add waypoints to Sethir the Ancient
DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(@ENTRY,  1, 11034.78, 1915.12, 1329.071, 'Sethir the Ancient'),
(@ENTRY,  2, 11018.08, 1909.81, 1326.689, 'Sethir the Ancient'),
(@ENTRY,  3, 11013.61, 1908.09, 1329.723, 'Sethir the Ancient'),
(@ENTRY,  4, 11008.81, 1905.00, 1332.812, 'Sethir the Ancient'),
(@ENTRY,  5, 11004.28, 1901.83, 1333.868, 'Sethir the Ancient - Say Text'), 
(@ENTRY,  6, 11008.81, 1905.00, 1332.812, 'Sethir the Ancient'),
(@ENTRY,  7, 11013.61, 1908.09, 1329.723, 'Sethir the Ancient'),
(@ENTRY,  8, 11018.08, 1909.81, 1326.689, 'Sethir the Ancient'),
(@ENTRY,  9, 11034.78, 1915.12, 1329.071, 'Sethir the Ancient'),
(@ENTRY, 10, 11052.97, 1921.79, 1332.839, 'Sethir the Ancient'),
(@ENTRY, 11, 11062.44, 1915.84, 1333.774, 'Sethir the Ancient'),
(@ENTRY, 12, 11071.45, 1909.21, 1337.327, 'Sethir the Ancient'),
(@ENTRY, 13, 11076.20, 1904.69, 1340.876, 'Sethir the Ancient'),
(@ENTRY, 14, 11080.32, 1899.27, 1344.996, 'Sethir the Ancient - Say Text'),
(@ENTRY, 15, 11091.49, 1902.53, 1344.222, 'Sethir the Ancient - Run'),
(@ENTRY, 16, 11098.34, 1905.78, 1345.527, 'Sethir the Ancient - Run'),
(@ENTRY, 17, 11102.24, 1910.42, 1347.384, 'Sethir the Ancient - Run'), 
(@ENTRY, 18, 11109.10, 1908.49, 1353.008, 'Sethir the Ancient - Run'),
(@ENTRY, 19, 11115.28, 1910.62, 1352.932, 'Sethir the Ancient - Despawn');

-- Add NPCs summoned via script
DELETE FROM `creature_summon_groups` WHERE `summonerId`=@ENTRY;
INSERT INTO `creature_summon_groups` (`summonerId`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`) VALUES
(@ENTRY, 0, 6911, 11009.33, 1898.94, 1335.194, 0.3919, 3, 80000),
(@ENTRY, 0, 6911, 11007.34, 1902.23, 1333.569, 0.2843, 3, 80000),
(@ENTRY, 0, 6911, 11007.49, 1907.11, 1333.883, 0.0801, 3, 80000),
(@ENTRY, 0, 6911, 11057.91, 1915.54, 1332.819, 2.5737, 3, 80000),
(@ENTRY, 0, 6911, 11063.38, 1918.78, 1333.376, 2.5942, 3, 80000),
(@ENTRY, 0, 6911, 11064.35, 1927.73, 1336.835, 3.6026, 3, 80000);

-- Add text to Sethir the Ancient
DELETE FROM `creature_text` WHERE `CreatureID` IN (@ENTRY,6911);
INSERT INTO `creature_text` (`CreatureID`, `groupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `BroadcastTextId`, `comment`) VALUES
(@ENTRY, 0, 0, "I know you are there, rogue. Leave my home or join the others at the bottom of the world tree.", 12, 0, 100, 2981, "Sethir the Ancient - Near player"),
(@ENTRY, 1, 0, "The end of days is upon us! May the earth embrace my flesh and bones.", 12, 0, 100, 2982, "Sethir the Ancient - On Waypoint 14"),
(@ENTRY, 2, 0, "Filth! Filth everywhere! The forests must be cleansed!", 12, 0, 100, 3001, "Sethir the Ancient - On Waypoint 5"),
(@ENTRY, 3, 0, "It is hopeless. Cutting one down results in two new growths.", 12, 0, 100, 3002, "Sethir the Ancient - On Waypoint 14"),
(6911, 0, 0, "We live only to serve the ancient one. DIE INTERLOPER!", 12, 0, 100, 2983, "Minion of Sethir - Oggro");

-- Add SAI to Sethir the Ancient + Actionlist 00/01/02/03
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (6911, @ENTRY, @ACTIONLIST_0, @ACTIONLIST_1, @ACTIONLIST_2, @ACTIONLIST_3) AND `source_type` IN (0, 9);
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (6911, @ENTRY);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,30000,30000,200000,200000,53,0,@ENTRY,0,0,10000,2,1,0,0,0,0,0,0,0,"Sethir the Ancient - Out of Combat - Start Waypoint"), -- SAI NPC ID=6909
(@ENTRY,0,1,0,40,0,100,0,5,@ENTRY,0,0,80,@ACTIONLIST_0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sethir the Ancient - On Waypoint 5 Reached - Run Script"),
(@ENTRY,0,2,0,40,0,100,0,14,@ENTRY,0,0,80,@ACTIONLIST_1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sethir the Ancient - On Waypoint 14 Reached - Run Script"),
(@ENTRY,0,3,0,40,0,100,0,19,@ENTRY,0,0,80,@ACTIONLIST_3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sethir the Ancient - On Waypoint 19 Reached - Run Script"),
(@ENTRY,0,4,0,4,0,100,0,0,0,0,0,80,@ACTIONLIST_2,2,0,0,0,0,1,0,0,0,0,0,0,0,"Sethir the Ancient - On Aggro - Run Script"),
(@ENTRY,0,5,0,10,0,100,0,0,10,80000,120000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sethir the Ancient - Within 0-10 Range Out of Combat LoS - Say Line 0"),
(@ACTIONLIST_0,9,0,0,0,0,100,0,0,0,0,0,54,40000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sethir the Ancient - On Script - Pause Waypoint"), -- Actionlist 00
(@ACTIONLIST_0,9,1,0,0,0,100,0,15000,15000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sethir the Ancient - On Script - Say Line 2"),
(@ACTIONLIST_1,9,0,0,0,0,100,0,0,0,0,0,54,60000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sethir the Ancient - On Script - Pause Waypoint"), -- Actionlist 01
(@ACTIONLIST_1,9,1,0,0,0,100,0,5000,5000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sethir the Ancient - On Script - Say Line 3"),
(@ACTIONLIST_1,9,2,0,0,0,100,0,55000,55000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sethir the Ancient - On Script - Say Line 1"),
(@ACTIONLIST_1,9,3,0,0,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sethir the Ancient - On Script - Set Run On"),
(@ACTIONLIST_2,9,0,0,0,0,100,0,0,0,0,0,107,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Summon Creature Group 0"), -- Actionlist 02
(@ACTIONLIST_3,9,0,0,0,0,100,0,10000,10000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sethir the Ancient - On Script - Despawn"), -- Actionlist 03
(6911,0,0,0,4,0,40,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Minion of Sethir - On aggro - Say text 0");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=@ENTRY;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 6, @ENTRY, 0, 0, 9, 0, 2242, 0, 0, 0, 0, '','Sethir the Ancient Only execute SAI if the quest 2242 is taken');
