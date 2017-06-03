-- Experimental Pilot -- http://wotlk.openwow.com/npc=19776

-- Experimental Pilot SAI
SET @ENTRY := 19776;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,53,0,19776,1,0,0,0,1,0,0,0,0,0,0,0,"Experimental Pilot - On Reset - Start Waypoint"),
(@ENTRY,0,1,0,64,0,100,0,0,0,0,0,54,180000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Experimental Pilot - On Gossip Hello - Pause Waypoint"),
(@ENTRY,0,2,0,40,0,100,0,8,19776,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Experimental Pilot - On Waypoint 8 Reached - Run Script"),
(@ENTRY,0,3,4,40,0,100,0,15,19776,0,0,54,300000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Experimental Pilot - On Waypoint 15 Reached - Pause Waypoint"),
(@ENTRY,0,4,0,61,0,100,0,15,19776,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.0689,"Experimental Pilot - On Waypoint 15 Reached - Set Orientation 5,0689");

-- Actionlist SAI
SET @ENTRY := 1977600;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,140000,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.111339,"On Script - Set Orientation 2.111339"),
(@ENTRY,9,2,0,0,0,100,0,4000,4000,0,0,45,1,1,0,0,0,0,10,70614,19737,0,0,0,0,0,"On Script - Set Data 1 1"),
(@ENTRY,9,3,0,0,0,100,0,1000,1000,0,0,1,0,15000,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 0"),
(@ENTRY,9,4,0,0,0,100,0,15000,15000,0,0,1,0,20000,0,0,0,0,10,70614,19737,0,0,0,0,0,"On Script - Say Line 0"),
(@ENTRY,9,5,0,0,0,100,0,20000,20000,0,0,1,1,20000,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 1"),
(@ENTRY,9,6,0,0,0,100,0,0,0,0,0,5,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Play Emote 6"),
(@ENTRY,9,7,0,0,0,100,0,20000,20000,0,0,1,1,15000,0,0,0,0,10,70614,19737,0,0,0,0,0,"On Script - Say Line 1"),
(@ENTRY,9,8,0,0,0,100,0,15000,15000,0,0,5,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Play Emote 6"),
(@ENTRY,9,9,0,0,0,100,0,0,0,0,0,1,2,15000,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 2"),
(@ENTRY,9,10,0,0,0,100,0,15000,15000,0,0,1,2,10000,0,0,0,0,10,70614,19737,0,0,0,0,0,"On Script - Say Line 2"),
(@ENTRY,9,11,0,0,0,100,0,10000,10000,0,0,1,3,15000,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 3"),
(@ENTRY,9,12,0,0,0,100,0,0,0,0,0,5,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Play Emote 6"),
(@ENTRY,9,13,0,0,0,100,0,15000,15000,0,0,1,3,10000,0,0,0,0,10,70614,19737,0,0,0,0,0,"On Script - Say Line 3"),
(@ENTRY,9,14,0,0,0,100,0,10000,10000,0,0,1,4,15000,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 4"),
(@ENTRY,9,15,0,0,0,100,0,15000,15000,0,0,1,4,0,0,0,0,0,10,70614,19737,0,0,0,0,0,"On Script - Say Line 4"),
(@ENTRY,9,16,0,0,0,100,0,0,0,0,0,45,2,2,0,0,0,0,10,70614,19737,0,0,0,0,0,"On Script - Set Data 2 2");

-- Buddy AI
-- Engineering Crewmember SAI
SET @GUID := -70614;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=19737;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,38,0,100,0,1,1,0,0,66,0,0,0,0,0,0,10,70731,19776,0,0,0,0,0,"Engineering Crewmember - On Data Set 1 1 - Set Orientation Closest Creature 'Experimental Pilot'"),
(@GUID,0,1,0,38,0,100,0,2,2,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.199120,"Engineering Crewmember - On Data Set 2 2 - Set Orientation 2,199120");

DELETE FROM `creature_text` WHERE `entry` IN (19737, 19776);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES 
(19776, 0, 0, 'All my bags are packed, I''m ready to go.', 12, 0, 100, 0, 0, 0, 17413, 'Experimental Pilot'),
(19776, 1, 0, 'You need to do what? All this science, I don''t understand... Look, this is just my job, five days a week.', 12, 0, 100, 0, 0, 0, 17416, 'Experimental Pilot'),
(19776, 2, 0, 'I can''t. I''m not the man they think I am at home.  Besides, I didn''t bring them out here.', 12, 0, 100, 0, 0, 0, 17419, 'Experimental Pilot'),
(19776, 3, 0, 'This isn''t the kind of place to raise your kids. It''s cold, and there''d be no one to raise them.', 12, 0, 100, 0, 0, 0, 17421, 'Experimental Pilot'),
(19776, 4, 0, 'Oh no, no, no... I''m a rocket man.', 12, 0, 100, 0, 0, 0, 17423, 'Experimental Pilot'),
-- 
(19737, 0, 0, 'The ship''s not ready yet.  We still need to calibrate the fuse length to make sure that it doesn''t burn out and leave you up there alone.', 12, 0, 100, 0, 0, 0, 17414, 'Engineering Crewmember'),
(19737, 1, 0, 'Essentially, it''s going to be a long, long time till we are ready to launch.  Maybe you should just head back home to your family.', 12, 0, 100, 0, 0, 0, 17417, 'Engineering Crewmember'),
(19737, 2, 0, 'Why not? A family can give you strength.', 12, 0, 100, 0, 0, 0, 17420, 'Engineering Crewmember'),
(19737, 3, 0, 'Couldn''t you raise them?', 12, 0, 100, 0, 0, 0, 17422, 'Engineering Crewmember'),
(19737, 4, 0, 'Well, it''s like I said; it''s going to be a while before we get this ship ready for flight.  We''ll keep you informed.', 12, 0, 100, 0, 0, 0, 17424, 'Engineering Crewmember');

DELETE FROM `waypoints` WHERE `entry`=19776;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(19776, 1, 2976.31, 3709.67,  142.398, 'Experimental Pilot'),
(19776, 2, 2987.82, 3686.2,   142.681, 'Experimental Pilot'),
(19776, 3, 2987.82, 3652.62,  143.244, 'Experimental Pilot'),
(19776, 4, 2999.17, 3645.03,  143.849, 'Experimental Pilot'),
(19776, 5, 3006.7, 3648.63,   143.771, 'Experimental Pilot'),
(19776, 6, 3042.1, 3645.08,   142.808, 'Experimental Pilot'),
(19776, 7, 3047.12, 3648.91,  142.832, 'Experimental Pilot'),
(19776, 8, 3043.87, 3652.34,  142.88,  'Experimental Pilot'),
(19776, 9, 3026.43, 3641.43,  143.507, 'Experimental Pilot'),
(19776, 10, 2989.67, 3650.38, 143.486, 'Experimental Pilot'),
(19776, 11, 2988.99, 3685.32, 142.73,  'Experimental Pilot'),
(19776, 12, 2975.27, 3712.82, 142.309, 'Experimental Pilot'),
(19776, 13, 2975.12, 3725.84, 142.688, 'Experimental Pilot'),
(19776, 14, 2965.31, 3733.57, 143.503, 'Experimental Pilot'),
(19776, 15, 2966.14, 3733,    143.472, 'Experimental Pilot');
