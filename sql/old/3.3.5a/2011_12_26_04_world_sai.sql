-- [Q] [A] The Touch of Zanzil
-- Doc Mixilpixil SAI
SET @ENTRY := 7207;
SET @QUEST := 2608;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
UPDATE `quest_template` SET `StartScript`=0,`CompleteScript`=0 WHERE `id`=@QUEST;
DELETE FROM `quest_start_scripts` WHERE `id`=@QUEST;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY,@ENTRY*100);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,@QUEST,0,0,0,80,@ENTRY*100,0,2,0,0,0,1,0,0,0,0,0,0,0,"Doc Mixilpixil - On Quest Accept - Run Script"),
(@ENTRY*100,9,0,0,0,0,100,0,1000,1000,0,0,5,353,0,0,0,0,0,1,0,0,0,0,0,0,0,"Doc Mixilpixil - On Script - Emote STATE_SPELLKNEELSTART"),
(@ENTRY*100,9,1,0,0,0,100,0,2000,2000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Doc Mixilpixil - On Script - Say Line 0"),
(@ENTRY*100,9,2,0,0,0,100,0,3000,3000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Doc Mixilpixil - On Script - Say Line 1"),
(@ENTRY*100,9,3,0,0,0,100,0,3000,3000,0,0,53,0,@ENTRY,0,0,0,2,1,0,0,0,0,0,0,0,"Doc Mixilpixil - On Script - Start WP"),
(@ENTRY,0,1,2,40,0,100,0,3,@ENTRY,0,0,41,5000,0,0,0,0,1,0,0,0,0,0,0,0,0,"Doc Mixilpixil - On WP 3 - Make Ready To Despawn"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,15,@QUEST,0,0,0,0,7,0,0,0,0,0,0,0,0,"Doc Mixilpixil - On WP 3 - Quest Credit");
-- Text
DELETE FROM `db_script_string` WHERE `entry` IN (2000000020,2000000021);
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"That's interesting...",12,0,100,0,0,0,"Doc Mixilpixil"),
(@ENTRY,1,0,"I need to consult Noram and Horatio.",12,0,100,0,0,0,"Doc Mixilpixil");
-- Waypoints
DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY,1,-8805.29,338.5,95.09,"Doc Mixilpixil"),
(@ENTRY,2,-8804.15,325.58,95.09,"Doc Mixilpixil"),
(@ENTRY,3,-8805.56,331.96,95.09,"Doc Mixilpixil");
