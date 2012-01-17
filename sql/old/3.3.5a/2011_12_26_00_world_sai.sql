-- [Q] [A/H] Therylune's Escape
-- Therylune SAI
SET @ENTRY := 3584;
SET @QUEST := 945;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
UPDATE `quest_template` SET `StartScript`=0,`CompleteScript`=0 WHERE `id`=@QUEST;
DELETE FROM `quest_start_scripts` WHERE `id`=@QUEST;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,19,0,100,0,@QUEST,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Therylune - On Quest Accept - Say Line 0"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,53,0,@ENTRY,0,0,0,2,1,0,0,0,0,0,0,0,"Therylune - On Quest Accept - Start WP"),
(@ENTRY,0,2,3,40,0,100,0,20,@ENTRY,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Therylune - On WP 20 - Say Line 1"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,15,@QUEST,0,0,0,0,7,0,0,0,0,0,0,0,0,"Therylune - On WP 20 - Quest Credit"),
(@ENTRY,0,4,0,40,0,100,0,21,@ENTRY,0,0,41,5000,0,0,0,0,1,0,0,0,0,0,0,0,0,"Therylune - On WP 21 - Forced Despawn");
-- Texts
DELETE FROM `db_script_string` WHERE `entry` IN (2000000017,2000000018);
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Ok, let's go!",12,0,100,0,0,0,"Therylune"),
(@ENTRY,1,0,"I can make it the rest of the way, $N. Thanks!",12,0,100,0,0,0,"Therylune");
-- Waypoints
DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY,1,4520.4,420.235,33.5284,"Therylune"),
(@ENTRY,2,4512.26,408.881,32.9308,"Therylune"),
(@ENTRY,3,4507.94,396.47,32.9476,"Therylune"),
(@ENTRY,4,4507.53,383.781,32.995,"Therylune"),
(@ENTRY,5,4512.1,374.02,33.166,"Therylune"),
(@ENTRY,6,4519.75,373.241,33.1574,"Therylune"),
(@ENTRY,7,4592.41,369.127,31.4893,"Therylune"),
(@ENTRY,8,4598.55,364.801,31.4947,"Therylune"),
(@ENTRY,9,4602.76,357.649,32.9265,"Therylune"),
(@ENTRY,10,4597.88,352.629,34.0317,"Therylune"),
(@ENTRY,11,4590.23,350.9,36.2977,"Therylune"),
(@ENTRY,12,4581.5,348.254,38.3878,"Therylune"),
(@ENTRY,13,4572.05,348.059,42.3539,"Therylune"),
(@ENTRY,14,4564.75,344.041,44.2463,"Therylune"),
(@ENTRY,15,4556.63,341.003,47.6755,"Therylune"),
(@ENTRY,16,4554.38,334.968,48.8003,"Therylune"),
(@ENTRY,17,4557.63,329.783,49.9532,"Therylune"),
(@ENTRY,18,4563.32,316.829,53.2409,"Therylune"),
(@ENTRY,19,4566.09,303.127,55.0396,"Therylune"),
(@ENTRY,20,4561.65,295.456,57.0984,"Therylune"),
(@ENTRY,21,4551.03,293.333,57.1534,"Therylune");
