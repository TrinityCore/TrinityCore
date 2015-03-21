-- Scourge Reanimator SAI
SET @GUID := -127410;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=26626;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,1,6,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,127435,26635,0,0,0,0,0,"Scourge Reanimator - On Just Died - Set Data 1 1"),
(@GUID,0,1,0,61,0,100,0,0,0,0,0,45,1,2,0,0,0,0,10,127426,26635,0,0,0,0,0,"Scourge Reanimator - On Just Died - Set Data 1 2");


-- Risen Drakkari Warrior SAI
SET @ENTRY := 26635;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,1000,3000,5000,9500,11,36093,0,0,0,0,0,2,0,0,0,0,0,0,0,"Risen Drakkari Warrior - In Combat - Cast 'Ghost Strike' (Dungeon)"),
(@ENTRY,0,1,0,0,0,100,6,1000,3000,7250,10000,11,33661,0,0,0,0,0,2,0,0,0,0,0,0,0,"Risen Drakkari Warrior - In Combat - Cast 'Crush Armor' (Dungeon)"),
(@ENTRY,0,2,0,54,0,100,0,0,0,0,0,89,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Drakkari Warrior - On Just Summoned - Start Random Movement"),
(@ENTRY,0,3,7,38,0,100,0,1,1,0,0,53,1,@ENTRY*100+00,0,0,0,2,1,0,0,0,0,0,0,0,"Risen Drakkari Warrior - On Data Set 1 1 - Start Waypoint"),
(@ENTRY,0,4,8,38,0,100,0,1,2,0,0,53,1,@ENTRY*100+01,0,0,0,2,1,0,0,0,0,0,0,0,"Risen Drakkari Warrior - On Data Set 1 2 - Start Waypoint"),
(@ENTRY,0,5,0,40,0,100,0,9,@ENTRY*100+00,0,0,12,26635,3,600000,0,0,0,8,0,0,0,-358.38,-592.396,4.37907,3.71398,"Risen Drakkari Warrior - On Waypoint 9 Reached - Summon Creature 'Risen Drakkari Warrior'"),
(@ENTRY,0,6,0,40,0,100,0,9,@ENTRY*100+01,0,0,12,26636,3,600000,0,0,0,8,0,0,0,-362.385162,-609.420288,2.467764,2.788083,"Risen Drakkari Warrior - On Waypoint 9 Reached - Summon Creature 'Risen Drakkari Soulmage'"),
(@ENTRY,0,7,0,61,0,100,0,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Risen Drakkari Warrior - On Data Set 1 1 - Say Line 0"),
(@ENTRY,0,8,0,61,0,100,0,1,2,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Drakkari Warrior - On Data Set 1 2 - Say Line 1");

DELETE FROM `waypoints` WHERE `entry`=2663500;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(2663500, 1, -358.149, -591.396, 4.8929, 'Risen Drakkari Warrior'),
(2663500, 2, -355.111, -588.661, 7.43521, 'Risen Drakkari Warrior'),
(2663500, 3, -351.322, -585.026, 10.995, 'Risen Drakkari Warrior'),
(2663500, 4, -345.376, -579.253, 11.012, 'Risen Drakkari Warrior'),
(2663500, 5, -343.792, -579.642, 11.012, 'Risen Drakkari Warrior'),
(2663500, 6, -346.169, -582.965, 11.012, 'Risen Drakkari Warrior'),
(2663500, 7, -350.619, -586.543, 10.6995, 'Risen Drakkari Warrior'),
(2663500, 8, -356.449, -591.583, 5.55874, 'Risen Drakkari Warrior'),
(2663500, 9, -363.399, -595.822, 2.26113, 'Risen Drakkari Warrior');

DELETE FROM `waypoints` WHERE `entry`=2663501;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(2663501, 1, -361.498, -611.317, 2.82481, 'Risen Drakkari Warrior'),
(2663501, 2, -358.749, -613.483, 4.91993, 'Risen Drakkari Warrior'),
(2663501, 3, -351.531, -619.59, 11.0096, 'Risen Drakkari Warrior'),
(2663501, 4, -349.112, -623.42, 11.0119, 'Risen Drakkari Warrior'),
(2663501, 5, -347.686, -624.43, 11.0119, 'Risen Drakkari Warrior'),
(2663501, 6, -346.433, -620.963, 11.0119, 'Risen Drakkari Warrior'),
(2663501, 7, -350.655, -617.858, 10.8491, 'Risen Drakkari Warrior'),
(2663501, 8, -356.367, -613.813, 6.09785, 'Risen Drakkari Warrior'),
(2663501, 9, -366.529, -607.86, 2.26056, 'Risen Drakkari Warrior');

DELETE FROM `creature_text` WHERE `entry`=26635;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(26635, 0, 0, 'Help mon! There''s too many of dem!', 14, 0, 100, 0, 0, 0, 26538, 0, 'Risen Drakkari Warrior'),
(26635, 1, 0, 'Backup! We need backup!', 14, 0, 100, 0, 0, 0, 26537, 0, 'Risen Drakkari Warrior');
