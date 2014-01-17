-- [Q] [A] Escape Through Force
-- [Q] [A] Escape Through Stealth
-- Volcor SAI
SET @ENTRY := 3692;
SET @QUEST_FORCE := 994;
SET @QUEST_STEALTH := 995;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
UPDATE `quest_template` SET `StartScript`=0,`CompleteScript`=0 WHERE `id` IN (@QUEST_FORCE,@QUEST_STEALTH);
DELETE FROM `quest_start_scripts` WHERE `id` IN (@QUEST_FORCE,@QUEST_STEALTH);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY,@ENTRY*100,@ENTRY*100+1);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,@QUEST_FORCE,0,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Volcor - On Quest Accept - Run Script"),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Volcor - On Script - Say Line 0"),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,0,0,53,0,@ENTRY,0,0,0,2,1,0,0,0,0,0,0,0,"Volcor - On Script - Start WP"),
(@ENTRY*100,9,2,0,0,0,100,0,135000,135000,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0,"Volcor - On Script - Say Line 2"),
(@ENTRY*100,9,3,0,0,0,100,0,0,0,0,0,15,@QUEST_FORCE,0,0,0,0,7,0,0,0,0,0,0,0,0,"Volcor - On Script - Quest Credit"),

(@ENTRY,0,1,0,19,0,100,0,@QUEST_STEALTH,0,0,0,80,@ENTRY*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Volcor - On Quest Accept - Run Script"),
(@ENTRY*100+1,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,3,0,0,0,0,0,0,"Volcor - On Script - Say Line 0"),
(@ENTRY*100+1,9,1,0,0,0,100,0,0,0,0,0,53,0,@ENTRY,0,0,0,2,1,0,0,0,0,0,0,0,"Volcor - On Script  - Start WP"),
(@ENTRY*100+1,9,2,0,0,0,100,0,135000,135000,0,0,1,3,0,0,0,0,0,7,0,0,0,0,0,0,0,"Volcor - On Script - Say Line 3"),
(@ENTRY*100+1,9,3,0,0,0,100,0,0,0,0,0,15,@QUEST_STEALTH,0,0,0,0,7,0,0,0,0,0,0,0,0,"Volcor - On Script - Quest Credit"),

(@ENTRY,0,2,0,40,0,100,0,15,@ENTRY*100,0,0,41,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Volcor - On WP 15 - Forced Despawn"),
(@ENTRY,0,3,0,4,0,100,0,0,0,0,0,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Volcor - On Aggro - Say Line 1");
-- Texts
DELETE FROM `db_script_string` WHERE `entry` BETWEEN 2000000012 AND 2000000016;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"All right, let's go.",12,0,100,0,0,0,"Volcor"),
(@ENTRY,1,0,"Oh no! They are here!",12,0,100,0,0,0,"Volcor"),
(@ENTRY,2,0,"OK, $N. Now I can get to the Auberdine alone. Go to Terenthis, he's waiting for you. Thanks for the help!",12,0,100,0,0,0,"Volcor"),
(@ENTRY,3,0,"OK, good luck friend. Thanks for the help.",12,0,100,0,0,0,"Volcor");

-- Waypoints
DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY,1,4606.61,2.96905,69.909,"Volcor"),
(@ENTRY,2,4615.56,19.7957,70.7951,"Volcor"),
(@ENTRY,3,4626.26,38.1105,69.0281,"Volcor"),
(@ENTRY,4,4633.11,48.379,67.5631,"Volcor"),
(@ENTRY,5,4637.2,71.7156,63.3412,"Volcor"),
(@ENTRY,6,4645.39,88.5048,60.3851,"Volcor"),
(@ENTRY,7,4660.2,104.218,58.4603,"Volcor"),
(@ENTRY,8,4675.33,115.93,56.8969,"Volcor"),
(@ENTRY,9,4688.21,131.397,55.5033,"Volcor"),
(@ENTRY,10,4701.45,145.562,53.2203,"Volcor"),
(@ENTRY,11,4709.21,155.279,52.0846,"Volcor"),
(@ENTRY,12,4716.9,169.528,53.5005,"Volcor"),
(@ENTRY,13,4725.44,180.07,54.7346,"Volcor"),
(@ENTRY,14,4734.01,194.431,55.3888,"Volcor"),
(@ENTRY,15,4747.92,209.436,53.1076,"Volcor");
