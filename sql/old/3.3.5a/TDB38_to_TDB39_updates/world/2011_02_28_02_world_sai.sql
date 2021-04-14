-- Quest 11314 "The Fallen Sisters"
-- Chill Nymph SAI
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=23678;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (23678,2367800);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(23678,0,0,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Do text emote on health 30%'),
(23678,0,1,0,0,0,75,0,2000,3000,2000,2000,11,9739,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wrath on victim'),
(23678,0,2,3,8,0,100,0,43340,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'On Spell hit 43340 face player'),
(23678,0,3,4,61,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'stop combat movement'),
(23678,0,4,5,61,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'evade'),
(23678,0,5,6,61,0,100,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,'set faction 35'),
(23678,0,6,7,61,0,100,0,0,0,0,0,33,24117,0,0,0,0,0,7,0,0,0,0,0,0,0,'quest credit'),
(23678,0,7,0,61,0,100,0,0,0,0,0,80,2367800,0,0,0,0,0,1,0,0,0,0,0,0,0,'load script'),
(23678,0,8,0,40,0,100,0,1,23678,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'On reach waypoint 1 despawn'),
(2367800,9,0,0,0,0,100,0,2000,2000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say text 1'),
(2367800,9,1,0,0,0,100,0,1000,1000,0,0,53,1,23678,0,0,0,0,1,0,0,0,0,0,0,0, 'start waypoint movement');
-- NPC talk text insert
DELETE FROM `creature_text` WHERE `entry`=23678;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(23678,0,0, 'Chill Nymph appears weak!',2,0,100,0,0,0, 'Chill Nymph'),
(23678,1,0, 'I knew Lurielle would send help! Thank you friend, and give Lurielle my thanks as well!',0,7,100,1,0,0, 'Chill Nymph'),
(23678,1,1, 'Where am I? What happened to me? You... you freed me?',0,7,100,1,0,0, 'Chill Nymph'),
(23678,1,2, 'Thank you. I thought I would die without seeing my sisters again!',0,7,100,1,0,0, 'Chill Nymph');
-- Chill Nymph Path
DELETE FROM `waypoints` WHERE `entry`=23678;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(23678,1,2063,-4666,217,'Chill Nymph point 1');
-- Add condition for Item 33606 "Lurielle''s Pendant" to only target Chill Nymph 23678
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceEntry`=33606;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(18,0,33606,0,24,1,23678,0,63,'','Item 33606 Lurielle''s Pendant targets Chill Nymph 23678');
