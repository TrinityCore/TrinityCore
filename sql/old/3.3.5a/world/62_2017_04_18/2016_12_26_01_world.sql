-- 
-- "Swamp Eye" Jarl - Creepy Event -- https://ironyca.wordpress.com/2010/09/15/the-10-most-creepy-things-in-wow/ 
-- Mordant Grimsby SAI
SET @ENTRY := 23843;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,53,0,23843,1,0,0,0,1,0,0,0,0,0,0,0,"Mordant Grimsby - On Reset - Start Waypoint"),
(@ENTRY,0,1,0,40,0,100,0,1,23843,0,0,54,15000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mordant Grimsby - On Waypoint 1 Reached - Pause Waypoint"),
(@ENTRY,0,2,0,40,0,100,0,2,23843,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mordant Grimsby - On Waypoint 2 Reached - Remove Npc Flag Questgiver"),
(@ENTRY,0,3,0,40,0,100,0,6,23843,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Mordant Grimsby - On Waypoint 6 Reached - Run Script"),
(@ENTRY,0,4,0,40,0,100,0,10,23843,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mordant Grimsby - On Waypoint 10 Reached - Add Npc Flag Questgiver"),
(@ENTRY,0,5,0,40,0,100,0,11,23843,0,0,54,300000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mordant Grimsby - On Waypoint 11 Reached - Pause Waypoint");

-- Actionlist SAI
SET @ENTRY := 2384300;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,54000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mordant Grimsby - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,3000,3000,0,0,5,381,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mordant Grimsby - On Script - Play Emote 381"),
(@ENTRY,9,2,0,0,0,100,0,1000,1000,0,0,50,186418,45,0,0,0,0,8,0,0,0,-2954.89,-3883.94,32.9969,2.60053,"Mordant Grimsby - On Script - Summon Gameobject 'Mordant's Gift'"),
(@ENTRY,9,3,0,0,0,100,0,2000,2000,0,0,5,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mordant Grimsby - On Script - Play Emote 0"),
(@ENTRY,9,4,0,0,0,100,0,2000,2000,0,0,1,0,4000,0,0,0,0,1,0,0,0,0,0,0,0,"Mordant Grimsby - On Script - Say Line 0"),
(@ENTRY,9,5,0,0,0,100,0,4000,4000,0,0,1,1,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Mordant Grimsby - On Script - Say Line 1"),
(@ENTRY,9,6,0,0,0,100,0,5000,5000,0,0,1,2,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Mordant Grimsby - On Script - Say Line 2"),
(@ENTRY,9,7,0,0,0,100,0,6000,6000,0,0,1,0,5000,0,0,0,0,19,4792,20,0,0,0,0,0,"Mordant Grimsby - On Script - Say Line 0"),
(@ENTRY,9,8,0,0,0,100,0,5000,5000,0,0,1,3,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Mordant Grimsby - On Script - Say Line 3"),
(@ENTRY,9,9,0,0,0,100,0,6000,6000,0,0,1,1,5000,0,0,0,0,19,4792,20,0,0,0,0,0,"Mordant Grimsby - On Script - Say Line 1"),
(@ENTRY,9,10,0,0,0,100,0,5000,5000,0,0,1,4,8000,0,0,0,0,1,0,0,0,0,0,0,0,"Mordant Grimsby - On Script - Say Line 4"),
(@ENTRY,9,11,0,0,0,100,0,8000,8000,0,0,5,381,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mordant Grimsby - On Script - Play Emote 381");

DELETE FROM `waypoints` WHERE `entry`=23843;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(23843, 1, -2948.36, -3893.17, 35.0324,  'Mordant Grimsby'),
(23843, 2, -2954, -3888.35, 34.991,      'Mordant Grimsby'),
(23843, 3, -2955.8, -3887.22, 33.729,    'Mordant Grimsby'),
(23843, 4, -2957.36, -3885.06, 33.0995,  'Mordant Grimsby'),
(23843, 5, -2957.23, -3882.92, 32.7325,  'Mordant Grimsby'),
(23843, 6, -2955.98, -3882.95, 32.8433,  'Mordant Grimsby'),
(23843, 7, -2955.55, -3885.08, 33.1672,  'Mordant Grimsby'),
(23843, 8, -2953.84, -3885.88, 33.9242,  'Mordant Grimsby'),
(23843, 9, -2952.99, -3887.91, 35.0223,  'Mordant Grimsby'),
(23843, 10, -2947.74, -3893.74, 35.0308, 'Mordant Grimsby'),
(23843, 11, -2948.36, -3893.17, 35.0324, 'Mordant Grimsby');

-- Texts
DELETE FROM `creature_text` WHERE `entry` IN(23843, 4792);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES 
-- Mordant Grimsby
(23843, 0, 0, 'I brought you a housewarming gift, Jarl.', 12, 0, 100, 1, 0, 0, 22348, 'Mordant Grimsby'),
(23843, 1, 0, 'Go on, open it. I think you\'ll like it.', 12, 0, 100, 25, 0, 0, 22349, 'Mordant Grimsby'),
(23843, 2, 0, 'Jarl?', 12, 0, 100, 0, 0, 0, 22350, 'Mordant Grimsby'),
(23843, 3, 0, 'Jarl, you haven\'t been yourself ever since I arrived. What\'s going on?', 12, 0, 100, 1, 0, 0, 22352, 'Mordant Grimsby'),
(23843, 4, 0, 'I came out here to visit you, Jarl! And I find you living in an empty cabin in the middle of nowhere, babbling about frogs? You\'re hopeless!', 12, 0, 100, 5, 0, 0, 22354, 'Mordant Grimsby'),
-- "Swamp Eye" Jarl
(4792, 0, 0, 'Unless it\'s something I can eat, I don\'t want it.', 12, 0, 100, 6, 0, 0, 22351, '"Swamp Eye" Jarl'),
(4792, 1, 0, 'Nothing. Wanna help me whip up some frog leg stew?', 12, 0, 100, 1, 0, 0, 22353, '"Swamp Eye" Jarl');
