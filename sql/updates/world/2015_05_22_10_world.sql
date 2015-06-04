--
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (3984) AND `source_type`=0 AND `id` IN (1, 2, 3) ;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (398400) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(3984, 0, 1, 0, 1, 0, 100, 0, 20000, 20000, 180000, 180000, 80, 398400, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'Nancy Vishas - ooc - Action list'),
(398400, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'Nancy Vishas - Action list - talk 1'),
(398400, 9, 1, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 3985, 15, 0, 0, 0, 0,0,'Nancy Vishas - Action list - talk 1'),
(398400, 9, 2, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'Nancy Vishas - Action list - talk 2'),
(398400, 9, 3, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 3985, 15, 0, 0, 0, 0,0,'Nancy Vishas - Action list - talk 2'),
(398400, 9, 4, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'Nancy Vishas - Action list - talk 3'),
(398400, 9, 5, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 53, 0, 3984, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'Nancy Vishas - Action list - start wp'),
(3984, 0, 2, 0, 40, 0, 100, 0, 1, 3984, 0, 0, 54, 30000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'Nancy Vishas - on WP1 - pause wp'),
(3984, 0, 3, 0, 40, 0, 100, 0, 2, 3984, 0, 0, 66, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'Nancy Vishas - on wp2- set home orientation');

DELETE FROM `waypoints` WHERE `entry`=3984;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(3984, 1, 908.933, -90.985, 33.783, 'Nancy Vishas'),
(3984, 2, 888.142, -121.849, 38.388, 'Nancy Vishas');  

DELETE FROM `creature_text` WHERE `entry` IN (3984, 3985);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextId`) VALUES
(3984,0,0,'Sidney is late. I thought he would be home by now.',12,7,100,0,0,0,'Nancy Vishas', 1365),
(3985,0,0,'He''s your husband, woman. How am I to know where he is?',12,7,100,0,0,0,'Grandpa Vishas', 1366),
(3984,1,0,'He must be overwhelmed with work at the Monastery. But still, he should have returned by now.',12,7,100,0,0,0,'Nancy Vishas', 1367),
(3985,1,0,'Cleansing the world of impure scum isn''t an easy job, Nancy. Someone''s got to do it.',12,7,100,0,0,0,'Grandpa Vishas', 1368),
(3984,2,0,'Well, I''m going outside to check. Something is amiss.',12,7,100,0,0,0,'Nancy Vishas', 1369);
