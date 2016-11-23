-- "Plucky" Johnson (Magus Tirth's assistant) in quest 1950 "Get the Scoop":
UPDATE `creature_template` SET `gossip_menu_id`= 231, `AIName`= 'SmartAI', `ScriptName`= '' WHERE `entry`= 6626;
UPDATE `creature_template` SET `gossip_menu_id`= 0, `AIName`= '' WHERE `entry`= 6666;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (6626,6666) AND `source_type`= 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(6626,0,0,1,22,0,100,0, 22,0,0,0,11, 9192, 2,0,0,0,0,1,0,0,0,0,0,0,0,'"Plucky" Johnson - Received Emote 22 - Cast "Plucky" Resumes Human Form'),
(6626,0,1,2,61,0,100,0,  0,0,0,0, 5,    3, 0,0,0,0,0,1,0,0,0,0,0,0,0,'"Plucky" Johnson - Received Emote 22 - Play Emote 3'),
(6626,0,2,0,61,0,100,0,  0,0,0,0,11, 9220, 2,0,0,0,0,1,0,0,0,0,0,0,0,'"Plucky" Johnson - Received Emote 22 - Cast "Plucky" Resumes Chicken Form'),
(6626,0,3,4,22,0,100,0,  7,0,0,0,11, 9192, 2,0,0,0,0,1,0,0,0,0,0,0,0,'"Plucky" Johnson - Received Emote 7 - Cast "Plucky" Resumes Human Form'),
(6626,0,4,5,61,0,100,0,  0,0,0,0,82,    1, 0,0,0,0,0,1,0,0,0,0,0,0,0,'"Plucky" Johnson - Received Emote 7 - Add npcflags Gossip'),
(6626,0,5,0,61,0,100,0,  0,0,0,0,69,    0, 0,0,0,0,0,7,0,0,0,0,0,0,0,'"Plucky" Johnson - Received Emote 7 - Move To Invoker'),
(6626,0,6,7,62,0,100,0,231,0,0,0,72,    0, 0,0,0,0,0,7,0,0,0,0,0,0,0,'"Plucky" Johnson\'s Human Form - On Gossip Option 0 Selected - Close Gossip'),
(6626,0,7,0,61,0,100,0,  0,0,0,0,15, 1950, 0,0,0,0,0,7,0,0,0,0,0,0,0,'"Plucky" Johnson\'s Human Form - On Gossip Option 0 Selected - Credit Quest 1950');
