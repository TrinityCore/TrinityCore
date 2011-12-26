-- [Q] [A/H] The Summoning
-- Bath'rah the Windwatcher SAI
SET @ENTRY := 6176;
SET @QUEST := 1713;
SET @SPELL_SUMMON := 8606;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
UPDATE `quest_template` SET `StartScript`=0,`CompleteScript`=0 WHERE `id`=@QUEST;
DELETE FROM `quest_start_scripts` WHERE `id`=@QUEST;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY,@ENTRY*100,@ENTRY*100+1);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,@QUEST,0,0,0,80,@ENTRY*100,0,2,0,0,0,1,0,0,0,0,0,0,0,"Bath'rah the Windwatcher - On Quest Accept - Run Script"),
(@ENTRY*100,9,0,0,0,0,100,0,1000,1000,0,0,53,0,@ENTRY,0,0,0,2,1,0,0,0,0,0,0,0,"Bath'rah the Windwatcher - On Script - Start WP"),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Bath'rah the Windwatcher - On Script - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,7,@ENTRY,0,0,80,@ENTRY*100+1,0,2,0,0,0,1,0,0,0,0,0,0,0,"Bath'rah the Windwatcher - On WP 7 - Run Script"),
(@ENTRY*100+1,9,0,0,0,0,100,0,0,0,0,0,11,@SPELL_SUMMON,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bath'rah the Windwatcher - On Script - Cast Summon Cyclonian"),
(@ENTRY*100+1,9,1,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bath'rah the Windwatcher - On Script - Say Line 1"),
(@ENTRY*100+1,9,2,0,0,0,100,0,15000,15000,0,0,53,0,@ENTRY*10,0,0,0,2,1,0,0,0,0,0,0,0,"Bath'rah the Windwatcher - On Script - Start WP");
-- Waypoints
DELETE FROM `waypoints` WHERE `entry` IN (@ENTRY,@ENTRY*10);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY,1,253.05,-1459.09,52.09,"Bath'rah the Windwatcher"),
(@ENTRY,2,256.87,-1440.35,50.09,"Bath'rah the Windwatcher"),
(@ENTRY,3,273.74,-1433.18,50.29,"Bath'rah the Windwatcher"),
(@ENTRY,4,297.77,-1436.7,46.96,"Bath'rah the Windwatcher"),
(@ENTRY,5,329.59,-1442.08,40.31,"Bath'rah the Windwatcher"),
(@ENTRY,6,332.73,-1455.6,42.24,"Bath'rah the Windwatcher"),
(@ENTRY,7,323.83,-1468.92,42.24,"Bath'rah the Windwatcher"),

(@ENTRY*10,1,332.73,-1455.6,42.24,"Bath'rah the Windwatcher"),
(@ENTRY*10,2,329.59,-1442.08,40.31,"Bath'rah the Windwatcher"),
(@ENTRY*10,3,297.77,-1436.7,46.96,"Bath'rah the Windwatcher"),
(@ENTRY*10,4,273.74,-1433.18,50.29,"Bath'rah the Windwatcher"),
(@ENTRY*10,5,256.87,-1440.35,50.09,"Bath'rah the Windwatcher"),
(@ENTRY*10,6,253.05,-1459.09,52.09,"Bath'rah the Windwatcher"),
(@ENTRY*10,7,250.84,-1470.58,55.4491,"Bath'rah the Windwatcher");
-- Texts
DELETE FROM `db_script_string` WHERE `entry` IN (2000000029,2000000043);
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Follow me, $N. I will soon begin the summoning.",12,0,100,0,0,0,"Bath'rah the Windwatcher"),
(@ENTRY,1,0,"%s begins a spell of summoning...",41,0,100,0,0,0,"Bath'rah the Windwatcher");
-- Waypoints
DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY,1,253.05,-1459.09,52.09,"Bath'rah the Windwatcher"),
(@ENTRY,2,256.87,-1440.35,50.09,"Bath'rah the Windwatcher"),
(@ENTRY,3,273.74,-1433.18,50.29,"Bath'rah the Windwatcher"),
(@ENTRY,4,297.77,-1436.7,46.96,"Bath'rah the Windwatcher"),
(@ENTRY,5,329.59,-1442.08,40.31,"Bath'rah the Windwatcher"),
(@ENTRY,6,332.73,-1455.6,42.24,"Bath'rah the Windwatcher"),
(@ENTRY,7,323.83,-1468.92,42.24,"Bath'rah the Windwatcher"),
(@ENTRY,8,332.73,-1455.6,42.24,"Bath'rah the Windwatcher"),
(@ENTRY,9,329.59,-1442.08,40.31,"Bath'rah the Windwatcher"),
(@ENTRY,10,297.77,-1436.7,46.96,"Bath'rah the Windwatcher"),
(@ENTRY,11,273.74,-1433.18,50.29,"Bath'rah the Windwatcher"),
(@ENTRY,12,256.87,-1440.35,50.09,"Bath'rah the Windwatcher"),
(@ENTRY,13,253.05,-1459.09,52.09,"Bath'rah the Windwatcher"),
(@ENTRY,14,250.84,-1470.58,55.4491,"Bath'rah the Windwatcher");
