-- Entry 550 (Defias Messenger)
DELETE FROM `creature_text` WHERE `CreatureID`=550 AND `BroadcastTextId` IN (36,37);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(550, 1, 0, 'Stonemasons. . .errr. . Defias be warned:  The rusty anchor sinks tonight.', 14, 0, 100, 0, 0, 0, 36, 0, 'Defias Messenger'),
(550, 2, 0, 'The boss wants all hands on high alert.  The rusty anchor sinks tonight.', 14, 0, 100, 0, 0, 0, 37, 0, 'Defias Messenger');
DELETE FROM `smart_scripts` WHERE `entryorguid`=550 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (3642000);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(550, 0, 2, 0, 40, 0, 100, 0, 43, 3642000, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 43 of path 3642000 - Talk (BroadcastText 37)'),
(550, 0, 3, 0, 40, 0, 100, 0, 94, 3642000, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 94 of path 3642000 - Talk (BroadcastText 36)');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=3642000 AND `point` IN (43,94);

-- Entry 842 (Lumberjack)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=842 AND `AIName`='';
DELETE FROM `smart_scripts` WHERE `entryorguid`=84200 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(84200, 9, 0, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 5, 234, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 3s - Play emote 234'),
(84200, 9, 1, 0, 0, 0, 100, 0, 94000, 94000, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 94s - Play emote 0'),
(84200, 9, 2, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 3, 0, 89, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 3s - Morph to model 89');
DELETE FROM `smart_scripts` WHERE `entryorguid`=84201 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(84201, 9, 0, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 5, 234, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 3s - Play emote 234'),
(84201, 9, 1, 0, 0, 0, 100, 0, 94000, 94000, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 94s - Play emote 0');
DELETE FROM `smart_scripts` WHERE `entryorguid`=842 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (3543680,3641920,7188880);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(842, 0, 0, 0, 40, 0, 100, 0, 1, 3543680, 0, 0, 0, 3, 0, 89, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 3543680 - Morph to model 89'),
(842, 0, 1, 0, 40, 0, 100, 0, 14, 3543680, 0, 0, 0, 3, 0, 308, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 14 of path 3543680 - Morph to model 308'),
(842, 0, 2, 0, 40, 0, 100, 0, 28, 3543680, 0, 0, 0, 80, 84201, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 28 of path 3543680 - Start timed actionlist 84201'),
(842, 0, 3, 0, 40, 0, 100, 0, 5, 3641920, 0, 0, 0, 80, 84200, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 5 of path 3641920 - Start timed actionlist 84200'),
(842, 0, 4, 0, 40, 0, 100, 0, 16, 3641920, 0, 0, 0, 3, 0, 308, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 16 of path 3641920 - Morph to model 308'),
(842, 0, 5, 0, 40, 0, 100, 0, 1, 7188880, 0, 0, 0, 80, 84200, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 7188880 - Start timed actionlist 84200'),
(842, 0, 6, 0, 40, 0, 100, 0, 11, 7188880, 0, 0, 0, 3, 0, 308, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 11 of path 7188880 - Morph to model 308');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=3543680 AND `point` IN (1,14,28);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=3641920 AND `point` IN (5,16);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=7188880 AND `point` IN (1,11);

-- Entry 1008 (Mosshide Mongrel)
DELETE FROM `smart_scripts` WHERE `entryorguid`=1008 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (10720);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1008, 0, 4, 0, 40, 0, 100, 0, 1, 10720, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 2.19912, 'On WP 1 of path 10720 - Set orientation 2.19912');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10720 AND `point` IN (1);

-- Entry 1277 (Mountaineer Ganin)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1277 AND `AIName`='';
DELETE FROM `smart_scripts` WHERE `entryorguid`=1277 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (661360);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1277, 0, 0, 0, 40, 0, 100, 0, 11, 661360, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 1.39626, 'On WP 11 of path 661360 - Set orientation 1.39626');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=661360 AND `point` IN (11);

-- Entry 1278 (Mountaineer Stenn)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1278 AND `AIName`='';
DELETE FROM `smart_scripts` WHERE `entryorguid`=1278 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (670080);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1278, 0, 0, 0, 40, 0, 100, 0, 20, 670080, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 1.5708, 'On WP 20 of path 670080 - Set orientation 1.5708');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=670080 AND `point` IN (20);

-- Entry 1280 (Mountaineer Droken)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1280 AND `AIName`='';
DELETE FROM `smart_scripts` WHERE `entryorguid`=1280 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (707200);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1280, 0, 0, 0, 40, 0, 100, 0, 29, 707200, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 3.9968, 'On WP 29 of path 707200 - Set orientation 3.9968');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=707200 AND `point` IN (29);

-- Entry 1282 (Mountaineer Veek)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1282 AND `AIName`='';
DELETE FROM `smart_scripts` WHERE `entryorguid`=1282 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (708400);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1282, 0, 0, 0, 40, 0, 100, 0, 10, 708400, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0.331613, 'On WP 10 of path 708400 - Set orientation 0.331613');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=708400 AND `point` IN (10);

-- Entry 1283 (Mountaineer Kalmir)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1283 AND `AIName`='';
DELETE FROM `smart_scripts` WHERE `entryorguid`=1283 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (661280);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1283, 0, 0, 0, 40, 0, 100, 0, 22, 661280, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 2.33874, 'On WP 22 of path 661280 - Set orientation 2.33874');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=661280 AND `point` IN (22);

-- Entry 1368 (Justin)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1368 AND `AIName`='';
DELETE FROM `creature_text` WHERE `CreatureID`=1368 AND `BroadcastTextId` IN (149,151,152,154,155,177);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(1368, 0, 0, 'They say he can turn into a raven sometimes.', 12, 0, 100, 0, 0, 0, 151, 0, 'Justin'),
(1368, 1, 0, 'And then the rabbit just bit his head off... I swear.', 12, 0, 100, 0, 0, 0, 155, 0, 'Justin'),
(1368, 2, 0, 'I swear, people have actually seen them. Pandaren really do exist!', 12, 0, 100, 0, 0, 0, 154, 0, 'Justin'),
(1368, 3, 0, 'You know why orc eyes glow red? It''s because they drink blood!', 12, 0, 100, 0, 0, 0, 152, 0, 'Justin'),
(1368, 4, 0, 'I don''t think there''s any fish in these canals.', 12, 0, 100, 0, 0, 0, 177, 0, 'Justin'),
(1368, 5, 0, 'And that''s how Lothar killed thirty six orcs with his bare hands!', 12, 0, 100, 0, 0, 0, 149, 0, 'Justin');
DELETE FROM `smart_scripts` WHERE `entryorguid`=1368 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (6385200);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1368, 0, 0, 0, 40, 0, 100, 0, 3, 6385200, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 3 of path 6385200 - Talk (BroadcastText 151)'),
(1368, 0, 1, 0, 40, 0, 100, 0, 7, 6385200, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 7 of path 6385200 - Talk (BroadcastText 151)'),
(1368, 0, 2, 0, 40, 0, 100, 0, 10, 6385200, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 10 of path 6385200 - Talk (BroadcastText 155)'),
(1368, 0, 3, 0, 40, 0, 100, 0, 13, 6385200, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 13 of path 6385200 - Talk (BroadcastText 154)'),
(1368, 0, 4, 0, 40, 0, 100, 0, 16, 6385200, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 16 of path 6385200 - Talk (BroadcastText 152)'),
(1368, 0, 5, 0, 40, 0, 100, 0, 18, 6385200, 0, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 18 of path 6385200 - Talk (BroadcastText 177)'),
(1368, 0, 6, 0, 40, 0, 100, 0, 19, 6385200, 0, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 19 of path 6385200 - Talk (BroadcastText 149)');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6385200 AND `point` IN (3,7,10,13,16,18,19);

-- Entry 1370 (Brandon)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1370 AND `AIName`='';
DELETE FROM `creature_text` WHERE `CreatureID`=1370 AND `BroadcastTextId` IN (147,157,167,168,169);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(1370, 0, 0, 'Can you imagine?', 12, 0, 100, 0, 0, 0, 169, 0, 'Brandon'),
(1370, 1, 0, 'Really?', 12, 0, 100, 0, 0, 0, 147, 0, 'Brandon'),
(1370, 2, 0, 'Wow.', 12, 0, 100, 0, 0, 0, 157, 0, 'Brandon'),
(1370, 3, 0, 'My father says that''s just a story.', 12, 0, 100, 0, 0, 0, 168, 0, 'Brandon'),
(1370, 4, 0, 'That''s neat.', 12, 0, 100, 0, 0, 0, 167, 0, 'Brandon');
DELETE FROM `smart_scripts` WHERE `entryorguid`=1370 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (6385360);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1370, 0, 0, 0, 40, 0, 100, 0, 1, 6385360, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 6385360 - Talk (BroadcastText 169)'),
(1370, 0, 1, 0, 40, 0, 100, 0, 4, 6385360, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 4 of path 6385360 - Talk (BroadcastText 147)'),
(1370, 0, 2, 0, 40, 0, 100, 0, 7, 6385360, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 7 of path 6385360 - Talk (BroadcastText 157)'),
(1370, 0, 3, 0, 40, 0, 100, 0, 10, 6385360, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 10 of path 6385360 - Talk (BroadcastText 168)'),
(1370, 0, 4, 0, 40, 0, 100, 0, 13, 6385360, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 13 of path 6385360 - Talk (BroadcastText 147)'),
(1370, 0, 5, 0, 40, 0, 100, 0, 16, 6385360, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 16 of path 6385360 - Talk (BroadcastText 157)'),
(1370, 0, 6, 0, 40, 0, 100, 0, 17, 6385360, 0, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 17 of path 6385360 - Talk (BroadcastText 167)'),
(1370, 0, 7, 0, 40, 0, 100, 0, 19, 6385360, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 19 of path 6385360 - Talk (BroadcastText 157)'),
(1370, 0, 8, 0, 40, 0, 100, 0, 20, 6385360, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 20 of path 6385360 - Talk (BroadcastText 147)');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6385360 AND `point` IN (1,4,7,10,13,16,17,19,20);

-- Entry 1371 (Roman)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1371 AND `AIName`='';
DELETE FROM `creature_text` WHERE `CreatureID`=1371 AND `BroadcastTextId` IN (172,173,174,176,178);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(1371, 0, 0, 'Eww... that''s not a fish!', 12, 0, 100, 0, 0, 0, 173, 0, 'Roman'),
(1371, 1, 0, 'I got worm guts on my shoes.', 12, 0, 100, 0, 0, 0, 174, 0, 'Roman'),
(1371, 2, 0, 'I think I see something.', 12, 0, 100, 0, 0, 0, 172, 0, 'Roman'),
(1371, 3, 0, 'I hope that was a fish!', 12, 0, 100, 0, 0, 0, 176, 0, 'Roman'),
(1371, 4, 0, 'Worm goes on the hook, hook goes in the water. Fish is in the water, our fish.', 12, 0, 100, 0, 0, 0, 178, 0, 'Roman');
DELETE FROM `smart_scripts` WHERE `entryorguid`=1371 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (6385280);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1371, 0, 0, 0, 40, 0, 100, 0, 2, 6385280, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 2 of path 6385280 - Talk (BroadcastText 173)'),
(1371, 0, 1, 0, 40, 0, 100, 0, 5, 6385280, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 5 of path 6385280 - Talk (BroadcastText 174)'),
(1371, 0, 2, 0, 40, 0, 100, 0, 8, 6385280, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 8 of path 6385280 - Talk (BroadcastText 172)'),
(1371, 0, 3, 0, 40, 0, 100, 0, 11, 6385280, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 11 of path 6385280 - Talk (BroadcastText 173)'),
(1371, 0, 4, 0, 40, 0, 100, 0, 14, 6385280, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 14 of path 6385280 - Talk (BroadcastText 172)'),
(1371, 0, 5, 0, 40, 0, 100, 0, 17, 6385280, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 17 of path 6385280 - Talk (BroadcastText 176)'),
(1371, 0, 6, 0, 40, 0, 100, 0, 20, 6385280, 0, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 20 of path 6385280 - Talk (BroadcastText 178)');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6385280 AND `point` IN (2,5,8,11,14,17,20);

-- Entry 1400 (Wetlands Crocolisk)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1400 AND `AIName`='';
DELETE FROM `smart_scripts` WHERE `entryorguid`=1400 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (9680);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1400, 0, 0, 0, 40, 0, 100, 0, 1, 9680, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 2.30383, 'On WP 1 of path 9680 - Set orientation 2.30383');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=9680 AND `point` IN (1);

-- Entry 1413 (Janey Anship)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1413 AND `AIName`='';
DELETE FROM `creature_text` WHERE `CreatureID`=1413 AND `BroadcastTextId` IN (209,213,224,225);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(1413, 0, 0, 'Putting in twelve centers of focus might allow the magical energies to form more solidly, adding the necessary stability.', 12, 0, 100, 0, 0, 0, 209, 0, 'Janey Anship'),
(1413, 1, 0, 'At least we wouldn''t be around to have to clean it up.', 12, 0, 100, 0, 0, 0, 224, 0, 'Janey Anship'),
(1413, 2, 0, 'Only if we didn''t follow the proper initialization procedures.', 12, 0, 100, 0, 0, 0, 225, 0, 'Janey Anship'),
(1413, 3, 0, 'The resultant energies could collapse though, and that could cause an energy flux that would give you a migraine for weeks.', 12, 0, 100, 0, 0, 0, 213, 0, 'Janey Anship');
DELETE FROM `smart_scripts` WHERE `entryorguid`=141300 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(141300, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Talk (BroadcastText 209)'),
(141300, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 17, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Set emote state 1');
DELETE FROM `smart_scripts` WHERE `entryorguid`=141301 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(141301, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Talk (BroadcastText 224)'),
(141301, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 17, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Set emote state 1');
DELETE FROM `smart_scripts` WHERE `entryorguid`=141302 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(141302, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Talk (BroadcastText 225)'),
(141302, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 17, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Set emote state 1');
DELETE FROM `smart_scripts` WHERE `entryorguid`=141303 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(141303, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Talk (BroadcastText 213)'),
(141303, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 17, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Set emote state 1');
DELETE FROM `smart_scripts` WHERE `entryorguid`=141304 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(141304, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Talk (BroadcastText 225)'),
(141304, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 17, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Set emote state 1');
DELETE FROM `smart_scripts` WHERE `entryorguid`=141305 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(141305, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Talk (BroadcastText 225)'),
(141305, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 17, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Set emote state 1');
DELETE FROM `smart_scripts` WHERE `entryorguid`=141306 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(141306, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Talk (BroadcastText 224)'),
(141306, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 17, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Set emote state 1');
DELETE FROM `smart_scripts` WHERE `entryorguid`=1413 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (6927680);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1413, 0, 0, 0, 40, 0, 100, 0, 6, 6927680, 0, 0, 0, 80, 141300, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 6 of path 6927680 - Start timed actionlist 141300'),
(1413, 0, 1, 0, 40, 0, 100, 0, 11, 6927680, 0, 0, 0, 80, 141301, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 11 of path 6927680 - Start timed actionlist 141301'),
(1413, 0, 2, 0, 40, 0, 100, 0, 25, 6927680, 0, 0, 0, 80, 141302, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 25 of path 6927680 - Start timed actionlist 141302'),
(1413, 0, 3, 0, 40, 0, 100, 0, 30, 6927680, 0, 0, 0, 80, 141303, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 30 of path 6927680 - Start timed actionlist 141303'),
(1413, 0, 4, 0, 40, 0, 100, 0, 46, 6927680, 0, 0, 0, 80, 141304, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 46 of path 6927680 - Start timed actionlist 141304'),
(1413, 0, 5, 0, 40, 0, 100, 0, 55, 6927680, 0, 0, 0, 80, 141305, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 55 of path 6927680 - Start timed actionlist 141305'),
(1413, 0, 6, 0, 40, 0, 100, 0, 59, 6927680, 0, 0, 0, 80, 141306, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 59 of path 6927680 - Start timed actionlist 141306');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6927680 AND `point` IN (6,11,25,30,46,55,59);

-- Entry 1414 (Lisan Pierce)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1414 AND `AIName`='';
DELETE FROM `creature_text` WHERE `CreatureID`=1414 AND `BroadcastTextId` IN (205,206,208,210,212,214,215,216,217);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(1414, 0, 0, 'But isn''t that what caused the initial problems with Adept Syleria''s magical formulae?', 12, 0, 100, 0, 0, 0, 214, 0, 'Lisan Pierce'),
(1414, 1, 0, 'I suppose that could work, if we had twenty people to cast it with.', 12, 0, 100, 0, 0, 0, 217, 0, 'Lisan Pierce'),
(1414, 2, 0, 'But what if the resulting frequency shift were to send magical feedback up the flows?', 12, 0, 100, 0, 0, 0, 210, 0, 'Lisan Pierce'),
(1414, 3, 0, 'When the positively aligned energies collide with the negatively charged energies, they don''t negate one another.', 12, 0, 100, 0, 0, 0, 205, 0, 'Lisan Pierce'),
(1414, 4, 0, 'That will unbalance the magical focus, though, and cause a reverse vibration in the ether.', 12, 0, 100, 0, 0, 0, 216, 0, 'Lisan Pierce'),
(1414, 5, 0, 'But wouldn''t that mean crossing the streams? Isn''t that really bad?', 12, 0, 100, 0, 0, 0, 212, 0, 'Lisan Pierce'),
(1414, 6, 0, 'Why can''t we just shift the array to compensate for the variance in the flux?', 12, 0, 100, 0, 0, 0, 208, 0, 'Lisan Pierce'),
(1414, 7, 0, 'I think not, I don''t need to be blown up again.', 12, 0, 100, 0, 0, 0, 215, 0, 'Lisan Pierce'),
(1414, 8, 0, 'Maginor says that twisting alternating flows of positive energy actually creates a much more stable flow.', 12, 0, 100, 0, 0, 0, 206, 0, 'Lisan Pierce');
DELETE FROM `smart_scripts` WHERE `entryorguid`=141400 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(141400, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Talk (BroadcastText 214)'),
(141400, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 17, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Set emote state 1');
DELETE FROM `smart_scripts` WHERE `entryorguid`=141401 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(141401, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Talk (BroadcastText 217)'),
(141401, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 17, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Set emote state 1');
DELETE FROM `smart_scripts` WHERE `entryorguid`=141402 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(141402, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Talk (BroadcastText 210)'),
(141402, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 17, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Set emote state 1');
DELETE FROM `smart_scripts` WHERE `entryorguid`=1414 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (6927760);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1414, 0, 0, 0, 40, 0, 100, 0, 3, 6927760, 0, 0, 0, 80, 141400, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 3 of path 6927760 - Start timed actionlist 141400'),
(1414, 0, 1, 0, 40, 0, 100, 0, 8, 6927760, 0, 0, 0, 80, 141401, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 8 of path 6927760 - Start timed actionlist 141401'),
(1414, 0, 2, 0, 40, 0, 100, 0, 9, 6927760, 0, 0, 0, 80, 141402, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 9 of path 6927760 - Start timed actionlist 141402'),
(1414, 0, 3, 0, 40, 0, 100, 0, 18, 6927760, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 18 of path 6927760 - Talk (BroadcastText 205)'),
(1414, 0, 4, 0, 40, 0, 100, 0, 19, 6927760, 0, 0, 0, 17, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 19 of path 6927760 - Set emote state 1'),
(1414, 0, 5, 0, 40, 0, 100, 0, 28, 6927760, 0, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 28 of path 6927760 - Talk (BroadcastText 216)'),
(1414, 0, 6, 0, 40, 0, 100, 0, 29, 6927760, 0, 0, 0, 17, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 29 of path 6927760 - Set emote state 1'),
(1414, 0, 7, 0, 40, 0, 100, 0, 31, 6927760, 0, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 31 of path 6927760 - Talk (BroadcastText 212)'),
(1414, 0, 8, 0, 40, 0, 100, 0, 32, 6927760, 0, 0, 0, 17, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 32 of path 6927760 - Set emote state 1'),
(1414, 0, 9, 0, 40, 0, 100, 0, 34, 6927760, 0, 0, 0, 1, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 34 of path 6927760 - Talk (BroadcastText 208)'),
(1414, 0, 10, 0, 40, 0, 100, 0, 35, 6927760, 0, 0, 0, 17, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 35 of path 6927760 - Set emote state 1'),
(1414, 0, 11, 0, 40, 0, 100, 0, 39, 6927760, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 39 of path 6927760 - Talk (BroadcastText 214)'),
(1414, 0, 12, 0, 40, 0, 100, 0, 40, 6927760, 0, 0, 0, 17, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 40 of path 6927760 - Set emote state 1'),
(1414, 0, 13, 0, 40, 0, 100, 0, 45, 6927760, 0, 0, 0, 1, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 45 of path 6927760 - Talk (BroadcastText 215)'),
(1414, 0, 14, 0, 40, 0, 100, 0, 46, 6927760, 0, 0, 0, 17, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 46 of path 6927760 - Set emote state 1'),
(1414, 0, 15, 0, 40, 0, 100, 0, 50, 6927760, 0, 0, 0, 1, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 50 of path 6927760 - Talk (BroadcastText 206)'),
(1414, 0, 16, 0, 40, 0, 100, 0, 51, 6927760, 0, 0, 0, 17, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 51 of path 6927760 - Set emote state 1'),
(1414, 0, 17, 0, 40, 0, 100, 0, 52, 6927760, 0, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 52 of path 6927760 - Talk (BroadcastText 212)'),
(1414, 0, 18, 0, 40, 0, 100, 0, 53, 6927760, 0, 0, 0, 17, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 53 of path 6927760 - Set emote state 1'),
(1414, 0, 19, 0, 40, 0, 100, 0, 55, 6927760, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 55 of path 6927760 - Talk (BroadcastText 214)'),
(1414, 0, 20, 0, 40, 0, 100, 0, 56, 6927760, 0, 0, 0, 17, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 56 of path 6927760 - Set emote state 1');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6927760 AND `point` IN (3,8,9,18,19,28,29,31,32,34,35,39,40,45,46,50,51,52,53,55,56);

-- Entry 1415 (Suzanne)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1415 AND `AIName`='';
DELETE FROM `creature_text` WHERE `CreatureID`=1415 AND `BroadcastTextId` IN (201,204,218,219,221,222);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(1415, 0, 0, 'If we reverse the Essence flows perhaps we can alter the polarity.', 12, 0, 100, 0, 0, 0, 201, 0, 'Suzanne'),
(1415, 1, 0, 'What if we used three focuses in Tyrean pattern? That should solve it.', 12, 0, 100, 0, 0, 0, 218, 0, 'Suzanne'),
(1415, 2, 0, 'Wow, all of this for a love potion. Hope he''s worth it.', 12, 0, 100, 0, 0, 0, 222, 0, 'Suzanne'),
(1415, 3, 0, 'If we use the appropriate sequence we should be ok. Will just take some serious studying before we start.', 12, 0, 100, 0, 0, 0, 221, 0, 'Suzanne'),
(1415, 4, 0, 'The portal will shift slightly, at this point if you cast a binding cantrip you will solidify it in place.', 12, 0, 100, 0, 0, 0, 204, 0, 'Suzanne'),
(1415, 5, 0, 'But if we stabilize it with an anchor thread at the appropriate energy crux then it should work.', 12, 0, 100, 0, 0, 0, 219, 0, 'Suzanne');
DELETE FROM `smart_scripts` WHERE `entryorguid`=141500 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(141500, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Talk (BroadcastText 201)'),
(141500, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 17, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Set emote state 1');
DELETE FROM `smart_scripts` WHERE `entryorguid`=141501 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(141501, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Talk (BroadcastText 218)'),
(141501, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 17, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Set emote state 1');
DELETE FROM `smart_scripts` WHERE `entryorguid`=141502 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(141502, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Talk (BroadcastText 222)'),
(141502, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 17, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Set emote state 1');
DELETE FROM `smart_scripts` WHERE `entryorguid`=141503 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(141503, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Talk (BroadcastText 221)'),
(141503, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 17, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Set emote state 1');
DELETE FROM `smart_scripts` WHERE `entryorguid`=141504 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(141504, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Talk (BroadcastText 204)'),
(141504, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 17, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Set emote state 1');
DELETE FROM `smart_scripts` WHERE `entryorguid`=141505 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(141505, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Talk (BroadcastText 222)'),
(141505, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 17, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Set emote state 1');
DELETE FROM `smart_scripts` WHERE `entryorguid`=141506 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(141506, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Talk (BroadcastText 219)'),
(141506, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 17, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Set emote state 1');
DELETE FROM `smart_scripts` WHERE `entryorguid`=141507 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(141507, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Talk (BroadcastText 218)'),
(141507, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 17, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Set emote state 1');
DELETE FROM `smart_scripts` WHERE `entryorguid`=141508 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(141508, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Talk (BroadcastText 221)'),
(141508, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 17, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Set emote state 1');
DELETE FROM `smart_scripts` WHERE `entryorguid`=141509 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(141509, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Talk (BroadcastText 219)'),
(141509, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 17, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Set emote state 1');
DELETE FROM `smart_scripts` WHERE `entryorguid`=141510 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(141510, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Talk (BroadcastText 222)'),
(141510, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 17, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Set emote state 1');
DELETE FROM `smart_scripts` WHERE `entryorguid`=1415 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (7143520);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1415, 0, 0, 0, 40, 0, 100, 0, 1, 7143520, 0, 0, 0, 80, 141500, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 7143520 - Start timed actionlist 141500'),
(1415, 0, 1, 0, 40, 0, 100, 0, 14, 7143520, 0, 0, 0, 80, 141501, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 14 of path 7143520 - Start timed actionlist 141501'),
(1415, 0, 2, 0, 40, 0, 100, 0, 16, 7143520, 0, 0, 0, 80, 141502, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 16 of path 7143520 - Start timed actionlist 141502'),
(1415, 0, 3, 0, 40, 0, 100, 0, 21, 7143520, 0, 0, 0, 80, 141503, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 21 of path 7143520 - Start timed actionlist 141503'),
(1415, 0, 4, 0, 40, 0, 100, 0, 27, 7143520, 0, 0, 0, 80, 141504, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 27 of path 7143520 - Start timed actionlist 141504'),
(1415, 0, 5, 0, 40, 0, 100, 0, 37, 7143520, 0, 0, 0, 80, 141505, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 37 of path 7143520 - Start timed actionlist 141505'),
(1415, 0, 6, 0, 40, 0, 100, 0, 43, 7143520, 0, 0, 0, 80, 141506, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 43 of path 7143520 - Start timed actionlist 141506'),
(1415, 0, 7, 0, 40, 0, 100, 0, 51, 7143520, 0, 0, 0, 80, 141507, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 51 of path 7143520 - Start timed actionlist 141507'),
(1415, 0, 8, 0, 40, 0, 100, 0, 57, 7143520, 0, 0, 0, 80, 141508, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 57 of path 7143520 - Start timed actionlist 141508'),
(1415, 0, 9, 0, 40, 0, 100, 0, 59, 7143520, 0, 0, 0, 80, 141509, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 59 of path 7143520 - Start timed actionlist 141509'),
(1415, 0, 10, 0, 40, 0, 100, 0, 62, 7143520, 0, 0, 0, 80, 141510, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 62 of path 7143520 - Start timed actionlist 141510');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=7143520 AND `point` IN (1,14,16,21,27,37,43,51,57,59,62);

-- Entry 1420 (Toad)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1420 AND `AIName`='';
DELETE FROM `creature_text` WHERE `CreatureID`=1420 AND `BroadcastTextId` IN (2401,2402,2403,2404);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(1420, 0, 0, 'Give to the charities who seek to help the victims of these hard times! Please.', 12, 0, 100, 0, 0, 0, 2403, 0, 'Toad'),
(1420, 1, 0, 'Don''t forget the orphans of Stormwind!', 12, 0, 100, 0, 0, 0, 2401, 0, 'Toad'),
(1420, 2, 0, 'Give of your hearts and your purses! Give to the children of Stormwind who have lost their parents.', 12, 0, 100, 0, 0, 0, 2404, 0, 'Toad'),
(1420, 3, 0, 'Help the children of Stormwind... victims of the war and plague!', 12, 0, 100, 0, 0, 0, 2402, 0, 'Toad');
DELETE FROM `smart_scripts` WHERE `entryorguid`=1420 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (8640);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1420, 0, 0, 0, 40, 0, 100, 0, 1, 8640, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 8640 - Talk (BroadcastText 2403)'),
(1420, 0, 1, 0, 40, 0, 100, 0, 4, 8640, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 4 of path 8640 - Talk (BroadcastText 2401)'),
(1420, 0, 2, 0, 40, 0, 100, 0, 7, 8640, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 7 of path 8640 - Talk (BroadcastText 2404)'),
(1420, 0, 3, 0, 40, 0, 100, 0, 12, 8640, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 12 of path 8640 - Talk (BroadcastText 2402)'),
(1420, 0, 4, 0, 40, 0, 100, 0, 16, 8640, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 16 of path 8640 - Talk (BroadcastText 2403)');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8640 AND `point` IN (1,4,7,12,16);

-- Entry 1451 (Camerick Jongleur)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1451 AND `AIName`='';
DELETE FROM `smart_scripts` WHERE `entryorguid`=1451 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (762000);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1451, 0, 0, 0, 40, 0, 100, 0, 9, 762000, 0, 0, 0, 17, 29, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 9 of path 762000 - Set emote state 29');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=762000 AND `point` IN (9);

-- Entry 1721 (Nikova Raskol)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1721 AND `AIName`='';
DELETE FROM `smart_scripts` WHERE `entryorguid`=1721 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (6381600);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1721, 0, 0, 0, 40, 0, 100, 0, 4, 6381600, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 2.86234, 'On WP 4 of path 6381600 - Set orientation 2.86234'),
(1721, 0, 1, 0, 40, 0, 100, 0, 14, 6381600, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 1.64061, 'On WP 14 of path 6381600 - Set orientation 1.64061'),
(1721, 0, 2, 0, 40, 0, 100, 0, 25, 6381600, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 3.50811, 'On WP 25 of path 6381600 - Set orientation 3.50811');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6381600 AND `point` IN (4,14,25);

-- Entry 1738 (Deathguard Terrence)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1738 AND `AIName`='';
DELETE FROM `smart_scripts` WHERE `entryorguid`=1738 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (2382320);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1738, 0, 0, 0, 40, 0, 100, 0, 13, 2382320, 0, 0, 0, 17, 11, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 13 of path 2382320 - Set emote state 11');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=2382320 AND `point` IN (13);

-- Entry 1742 (Deathguard Bartholomew)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1742 AND `AIName`='';
DELETE FROM `creature_text` WHERE `CreatureID`=1742 AND `BroadcastTextId` IN (327,328);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(1742, 0, 0, 'We really should fix this fence soon.', 12, 0, 100, 0, 0, 0, 328, 0, 'Deathguard Bartholomew'),
(1742, 1, 0, '*sigh* It''s about time to check on the cemetery again-- I''ll be back in a few minutes.', 12, 0, 100, 0, 0, 0, 327, 0, 'Deathguard Bartholomew');
DELETE FROM `smart_scripts` WHERE `entryorguid`=1742 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (2728880);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1742, 0, 0, 0, 40, 0, 100, 0, 1, 2728880, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 2728880 - Talk (BroadcastText 327)'),
(1742, 0, 1, 0, 40, 0, 100, 0, 8, 2728880, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 8 of path 2728880 - Talk (BroadcastText 328)');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=2728880 AND `point` IN (1,8);

-- Entry 1885 (Scarlet Smith)
DELETE FROM `smart_scripts` WHERE `entryorguid`=188500 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(188500, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 5, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 1s - Play emote 69'),
(188500, 9, 1, 0, 0, 0, 100, 0, 17000, 17000, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 17s - Play emote 0');
DELETE FROM `smart_scripts` WHERE `entryorguid`=1885 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (4930720);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1885, 0, 3, 0, 40, 0, 100, 0, 9, 4930720, 0, 0, 0, 80, 188500, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 9 of path 4930720 - Start timed actionlist 188500'),
(1885, 0, 4, 0, 40, 0, 100, 0, 10, 4930720, 0, 0, 0, 80, 188500, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 10 of path 4930720 - Start timed actionlist 188500');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=4930720 AND `point` IN (9,10);

-- Entry 2330 (Karlee Chaddis)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=2330 AND `AIName`='';
DELETE FROM `creature_text` WHERE `CreatureID`=2330 AND `BroadcastTextId` IN (587,589,590);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(2330, 0, 0, 'Hello, Charys. I have my list, could you get me all of that, especially the last ingredient.', 12, 0, 100, 0, 0, 0, 587, 0, 'Karlee Chaddis'),
(2330, 1, 0, 'Sure, Paige. Just be gentle.', 12, 0, 100, 0, 0, 0, 589, 0, 'Karlee Chaddis'),
(2330, 2, 0, 'Thanks, Charys. C''mon Paige, sweetie.', 12, 0, 100, 0, 0, 0, 590, 0, 'Karlee Chaddis');
DELETE FROM `smart_scripts` WHERE `entryorguid`=2330 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (7235120);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(2330, 0, 0, 0, 40, 0, 100, 0, 28, 7235120, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 28 of path 7235120 - Talk (BroadcastText 587)'),
(2330, 0, 1, 0, 40, 0, 100, 0, 29, 7235120, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 29 of path 7235120 - Talk (BroadcastText 589)'),
(2330, 0, 2, 0, 40, 0, 100, 0, 30, 7235120, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 30 of path 7235120 - Talk (BroadcastText 590)');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=7235120 AND `point` IN (28,29,30);

-- Entry 2331 (Paige Chaddis)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=2331 AND `AIName`='';
DELETE FROM `creature_text` WHERE `CreatureID`=2331 AND `BroadcastTextId` IN (588);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(2331, 0, 0, 'Mommy? Can I pet Fizzles?', 12, 0, 100, 0, 0, 0, 588, 0, 'Paige Chaddis');
DELETE FROM `smart_scripts` WHERE `entryorguid`=2331 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (7235200);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(2331, 0, 0, 0, 40, 0, 100, 0, 29, 7235200, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 29 of path 7235200 - Talk (BroadcastText 588)');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=7235200 AND `point` IN (29);

-- Entry 3291 (Greishan Ironstove)
DELETE FROM `smart_scripts` WHERE `entryorguid`=3291 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (706960);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(3291, 0, 1, 0, 40, 0, 100, 0, 129, 706960, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 3.82227, 'On WP 129 of path 706960 - Set orientation 3.82227'),
(3291, 0, 2, 0, 40, 0, 100, 0, 197, 706960, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 3.9968, 'On WP 197 of path 706960 - Set orientation 3.9968');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=706960 AND `point` IN (129,197);

-- Entry 3504 (Gil)
DELETE FROM `creature_text` WHERE `CreatureID`=3504 AND `BroadcastTextId` IN (1091);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(3504, 2, 0, 'Billy says Fizzles used to be a great wizard. But he got turned into a rabbit when one of his spells went bad.', 12, 0, 100, 0, 0, 0, 1091, 0, 'Gil');
DELETE FROM `smart_scripts` WHERE `entryorguid`=3504 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (7235440);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(3504, 0, 2, 0, 40, 0, 100, 0, 29, 7235440, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 29 of path 7235440 - Talk (BroadcastText 1091)');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=7235440 AND `point` IN (29);

-- Entry 3513 (Miss Danna)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=3513 AND `AIName`='';
DELETE FROM `creature_text` WHERE `CreatureID`=3513 AND `BroadcastTextId` IN (1129,1140,1154,1155,1161,1162,1163,1165,1166);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(3513, 0, 0, 'Here we have the Cathedral of Light, the center of spiritual enlightenment here in Stormwind.', 12, 0, 100, 0, 0, 0, 1129, 0, 'Miss Danna'),
(3513, 1, 0, 'Yes, that is true. Paladins and priests alike train their skills and research great truths behind the walls of the Cathedral.', 12, 0, 100, 0, 0, 0, 1154, 0, 'Miss Danna'),
(3513, 2, 0, 'Children if you would please follow me, we will now be going to see the keep where King Varian Wrynn himself sits on his throne.', 12, 0, 100, 0, 0, 0, 1155, 0, 'Miss Danna'),
(3513, 3, 0, 'Here we have Stormwind Keep. Built upon the ruins of Stormwind Castle, which was destroyed by the Horde in the first Great War.', 12, 0, 100, 0, 0, 0, 1140, 0, 'Miss Danna'),
(3513, 4, 0, 'When the Horde was shattered, men returned here and began to rebuild the once great city as a testament to our own survival.', 12, 0, 100, 0, 0, 0, 1161, 0, 'Miss Danna'),
(3513, 5, 0, 'Yes, well...let''s head on to the monument dedicated to the heroes of the two Great Wars, the Valley of Heroes. Follow me.', 12, 0, 100, 0, 0, 0, 1162, 0, 'Miss Danna'),
(3513, 6, 0, 'Isn''t it amazing, children? All who enter the city must walk beneath the watchful eyes of the greatest heroes of our lands.', 12, 0, 100, 0, 0, 0, 1163, 0, 'Miss Danna'),
(3513, 7, 0, 'Breathtaking. Children, when we return to the school, you will each give an oral report on one of these legendary people.', 12, 0, 100, 0, 0, 0, 1165, 0, 'Miss Danna'),
(3513, 8, 0, 'Now, take another long look before we make our way to the Holy District and the great Cathedral of Light.', 12, 0, 100, 0, 0, 0, 1166, 0, 'Miss Danna');
DELETE FROM `smart_scripts` WHERE `entryorguid`=351300 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(351300, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Talk (BroadcastText 1129)'),
(351300, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 17, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Set emote state 1');
DELETE FROM `smart_scripts` WHERE `entryorguid`=351301 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(351301, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Talk (BroadcastText 1154)'),
(351301, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 17, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Set emote state 1');
DELETE FROM `smart_scripts` WHERE `entryorguid`=351302 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(351302, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Talk (BroadcastText 1155)'),
(351302, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 17, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Set emote state 1');
DELETE FROM `smart_scripts` WHERE `entryorguid`=351303 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(351303, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Talk (BroadcastText 1162)'),
(351303, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 17, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Set emote state 1');
DELETE FROM `smart_scripts` WHERE `entryorguid`=351304 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(351304, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Talk (BroadcastText 1166)'),
(351304, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 17, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Set emote state 1');
DELETE FROM `smart_scripts` WHERE `entryorguid`=3513 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (6722240);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(3513, 0, 0, 0, 40, 0, 100, 0, 21, 6722240, 0, 0, 0, 80, 351300, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 21 of path 6722240 - Start timed actionlist 351300'),
(3513, 0, 1, 0, 40, 0, 100, 0, 22, 6722240, 0, 0, 0, 17, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 22 of path 6722240 - Set emote state 1'),
(3513, 0, 2, 0, 40, 0, 100, 0, 24, 6722240, 0, 0, 0, 80, 351301, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 24 of path 6722240 - Start timed actionlist 351301'),
(3513, 0, 3, 0, 40, 0, 100, 0, 25, 6722240, 0, 0, 0, 80, 351302, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 25 of path 6722240 - Start timed actionlist 351302'),
(3513, 0, 4, 0, 40, 0, 100, 0, 39, 6722240, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 39 of path 6722240 - Talk (BroadcastText 1140)'),
(3513, 0, 5, 0, 40, 0, 100, 0, 40, 6722240, 0, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 40 of path 6722240 - Talk (BroadcastText 1161)'),
(3513, 0, 6, 0, 40, 0, 100, 0, 41, 6722240, 0, 0, 0, 17, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 41 of path 6722240 - Set emote state 1'),
(3513, 0, 7, 0, 40, 0, 100, 0, 42, 6722240, 0, 0, 0, 80, 351303, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 42 of path 6722240 - Start timed actionlist 351303'),
(3513, 0, 8, 0, 40, 0, 100, 0, 44, 6722240, 0, 0, 0, 17, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 44 of path 6722240 - Set emote state 1'),
(3513, 0, 9, 0, 40, 0, 100, 0, 58, 6722240, 0, 0, 0, 1, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 58 of path 6722240 - Talk (BroadcastText 1163)'),
(3513, 0, 10, 0, 40, 0, 100, 0, 59, 6722240, 0, 0, 0, 1, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 59 of path 6722240 - Talk (BroadcastText 1165)'),
(3513, 0, 11, 0, 40, 0, 100, 0, 60, 6722240, 0, 0, 0, 80, 351304, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 60 of path 6722240 - Start timed actionlist 351304'),
(3513, 0, 12, 0, 40, 0, 100, 0, 61, 6722240, 0, 0, 0, 17, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 61 of path 6722240 - Set emote state 1'),
(3513, 0, 13, 0, 40, 0, 100, 0, 62, 6722240, 0, 0, 0, 17, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 62 of path 6722240 - Set emote state 1');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6722240 AND `point` IN (21,22,24,25,39,40,41,42,44,58,59,60,61,62);

-- Entry 3518 (Thomas Miller)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=3518 AND `AIName`='';
DELETE FROM `smart_scripts` WHERE `entryorguid`=3518 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (6377840);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(3518, 0, 0, 0, 40, 0, 100, 0, 1, 6377840, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 6377840 - Talk (BroadcastText 1101)'),
(3518, 0, 1, 0, 40, 0, 100, 0, 2, 6377840, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 2 of path 6377840 - Talk (BroadcastText 1103)'),
(3518, 0, 2, 0, 40, 0, 100, 0, 22, 6377840, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 22 of path 6377840 - Talk (BroadcastText 1102)'),
(3518, 0, 3, 0, 40, 0, 100, 0, 23, 6377840, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 23 of path 6377840 - Talk (BroadcastText 1104)');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6377840 AND `point` IN (1,2,22,23);

-- Entry 3520 (Ol' Emma)
DELETE FROM `smart_scripts` WHERE `entryorguid`=3520 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (6383680);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(3520, 0, 2, 0, 40, 0, 100, 0, 7, 6383680, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 7 of path 6383680 - Talk (BroadcastText 1110)'),
(3520, 0, 3, 0, 40, 0, 100, 0, 10, 6383680, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 10 of path 6383680 - Talk (BroadcastText 1105)'),
(3520, 0, 4, 0, 40, 0, 100, 0, 13, 6383680, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 13 of path 6383680 - Talk (BroadcastText 1108)'),
(3520, 0, 5, 0, 40, 0, 100, 0, 16, 6383680, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 16 of path 6383680 - Talk (BroadcastText 1106)'),
(3520, 0, 6, 0, 40, 0, 100, 0, 22, 6383680, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 22 of path 6383680 - Talk (BroadcastText 1107)'),
(3520, 0, 7, 0, 40, 0, 100, 0, 27, 6383680, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 27 of path 6383680 - Talk (BroadcastText 1112)');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6383680 AND `point` IN (7,10,13,16,22,27);

-- Entry 3562 (Alaindia)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=3562 AND `AIName`='';
DELETE FROM `smart_scripts` WHERE `entryorguid`=3562 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (3962000);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(3562, 0, 0, 0, 40, 0, 100, 0, 3, 3962000, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0.0349066, 'On WP 3 of path 3962000 - Set orientation 0.0349066'),
(3562, 0, 1, 0, 40, 0, 100, 0, 13, 3962000, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 4.69494, 'On WP 13 of path 3962000 - Set orientation 4.69494'),
(3562, 0, 2, 0, 40, 0, 100, 0, 31, 3962000, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 2.53073, 'On WP 31 of path 3962000 - Set orientation 2.53073'),
(3562, 0, 3, 0, 40, 0, 100, 0, 52, 3962000, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 3.19395, 'On WP 52 of path 3962000 - Set orientation 3.19395');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=3962000 AND `point` IN (3,13,31,52);

-- Entry 5595 (Ironforge Guard)
DELETE FROM `smart_scripts` WHERE `entryorguid`=5595 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (9680,10720);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(5595, 0, 11, 0, 40, 0, 100, 0, 1, 9680, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 2.30383, 'On WP 1 of path 9680 - Set orientation 2.30383'),
(5595, 0, 12, 0, 40, 0, 100, 0, 1, 10720, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 2.19912, 'On WP 1 of path 10720 - Set orientation 2.19912');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=9680 AND `point` IN (1);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10720 AND `point` IN (1);

-- Entry 5782 (Crildor)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=5782 AND `AIName`='';
DELETE FROM `smart_scripts` WHERE `entryorguid`=5782 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (3745280);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(5782, 0, 0, 0, 40, 0, 100, 0, 1, 3745280, 0, 0, 0, 17, 13, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 3745280 - Set emote state 13'),
(5782, 0, 1, 0, 40, 0, 100, 0, 22, 3745280, 0, 0, 0, 17, 13, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 22 of path 3745280 - Set emote state 13'),
(5782, 0, 2, 0, 40, 0, 100, 0, 53, 3745280, 0, 0, 0, 17, 13, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 53 of path 3745280 - Set emote state 13');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=3745280 AND `point` IN (1,22,53);

-- Entry 6090 (Bartleby)
DELETE FROM `smart_scripts` WHERE `entryorguid`=6090 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (6380000);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(6090, 0, 7, 0, 40, 0, 100, 0, 1, 6380000, 0, 0, 0, 17, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 6380000 - Set emote state 7'),
(6090, 0, 8, 0, 40, 0, 100, 0, 3, 6380000, 0, 0, 0, 17, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 3 of path 6380000 - Set emote state 7'),
(6090, 0, 9, 0, 40, 0, 100, 0, 6, 6380000, 0, 0, 0, 17, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 6 of path 6380000 - Set emote state 7'),
(6090, 0, 10, 0, 40, 0, 100, 0, 9, 6380000, 0, 0, 0, 17, 39, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 9 of path 6380000 - Set emote state 39');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6380000 AND `point` IN (1,3,6,9);

-- Entry 6175 (John Turner)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=6175 AND `AIName`='';
DELETE FROM `smart_scripts` WHERE `entryorguid`=6175 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (8640);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(6175, 0, 0, 0, 40, 0, 100, 0, 1, 8640, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 8640 - Talk (BroadcastText 2403)'),
(6175, 0, 1, 0, 40, 0, 100, 0, 4, 8640, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 4 of path 8640 - Talk (BroadcastText 2401)'),
(6175, 0, 2, 0, 40, 0, 100, 0, 7, 8640, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 7 of path 8640 - Talk (BroadcastText 2404)'),
(6175, 0, 3, 0, 40, 0, 100, 0, 12, 8640, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 12 of path 8640 - Talk (BroadcastText 2402)'),
(6175, 0, 4, 0, 40, 0, 100, 0, 16, 8640, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 16 of path 8640 - Talk (BroadcastText 2403)');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8640 AND `point` IN (1,4,7,12,16);

-- Entry 6670 (Westfall Woodworker)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=6670 AND `AIName`='';
DELETE FROM `smart_scripts` WHERE `entryorguid`=667000 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(667000, 9, 0, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 5, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 3s - Play emote 69'),
(667000, 9, 1, 0, 0, 0, 100, 0, 84000, 84000, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 84s - Play emote 0');
DELETE FROM `smart_scripts` WHERE `entryorguid`=6670 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (3544240,3637760,3641680,7188800);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(6670, 0, 0, 0, 40, 0, 100, 0, 2, 3544240, 0, 0, 0, 80, 667000, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 2 of path 3544240 - Start timed actionlist 667000'),
(6670, 0, 1, 0, 40, 0, 100, 0, 3, 3544240, 0, 0, 0, 80, 667000, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 3 of path 3544240 - Start timed actionlist 667000'),
(6670, 0, 2, 0, 40, 0, 100, 0, 1, 3637760, 0, 0, 0, 80, 667000, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 3637760 - Start timed actionlist 667000'),
(6670, 0, 3, 0, 40, 0, 100, 0, 3, 3637760, 0, 0, 0, 80, 667000, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 3 of path 3637760 - Start timed actionlist 667000'),
(6670, 0, 4, 0, 40, 0, 100, 0, 1, 3641680, 0, 0, 0, 17, 16, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 3641680 - Set emote state 16'),
(6670, 0, 5, 0, 40, 0, 100, 0, 2, 3641680, 0, 0, 0, 80, 667000, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 2 of path 3641680 - Start timed actionlist 667000'),
(6670, 0, 6, 0, 40, 0, 100, 0, 1, 7188800, 0, 0, 0, 80, 667000, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 7188800 - Start timed actionlist 667000'),
(6670, 0, 7, 0, 40, 0, 100, 0, 2, 7188800, 0, 0, 0, 80, 667000, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 2 of path 7188800 - Start timed actionlist 667000');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=3544240 AND `point` IN (2,3);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=3637760 AND `point` IN (1,3);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=3641680 AND `point` IN (1,2);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=7188800 AND `point` IN (1,2);

-- Entry 6846 (Defias Dockmaster)
DELETE FROM `creature_text` WHERE `CreatureID`=6846 AND `BroadcastTextId` IN (2874);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(6846, 1, 0, 'Look alive, dogs! We got an operation to run here!', 12, 0, 100, 0, 0, 0, 2874, 0, 'Defias Dockmaster');
DELETE FROM `smart_scripts` WHERE `entryorguid`=6846 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (6458960);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(6846, 0, 4, 0, 40, 0, 100, 0, 6, 6458960, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 6 of path 6458960 - Talk (BroadcastText 2874)');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6458960 AND `point` IN (6);

-- Entry 8256 (Curator Thorius)
DELETE FROM `creature_text` WHERE `CreatureID`=8256 AND `BroadcastTextId` IN (4285,4286);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(8256, 4, 0, '%s dusts the base of the artifact.', 16, 0, 100, 0, 0, 0, 4285, 0, 'Curator Thorius'),
(8256, 5, 0, '%s meticulously examines the large vase.', 16, 0, 100, 0, 0, 0, 4286, 0, 'Curator Thorius');
DELETE FROM `smart_scripts` WHERE `entryorguid`=825602 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(825602, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 2s - Talk (BroadcastText 4285)'),
(825602, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 17, 16, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Set emote state 16');
DELETE FROM `smart_scripts` WHERE `entryorguid`=825603 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(825603, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 5, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 2s - Play emote 69'),
(825603, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Talk (BroadcastText 4286)'),
(825603, 9, 2, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 5, 26, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 3s - Play emote 26');
DELETE FROM `smart_scripts` WHERE `entryorguid`=8256 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (150960);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(8256, 0, 4, 0, 40, 0, 100, 0, 8, 150960, 0, 0, 0, 80, 825602, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 8 of path 150960 - Start timed actionlist 825602'),
(8256, 0, 5, 0, 40, 0, 100, 0, 12, 150960, 0, 0, 0, 80, 825603, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 12 of path 150960 - Start timed actionlist 825603');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=150960 AND `point` IN (8,12);

-- Entry 10428 (Motega Firemane)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=10428 AND `AIName`='';
DELETE FROM `smart_scripts` WHERE `entryorguid`=10428 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (1735440);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(10428, 0, 0, 0, 40, 0, 100, 0, 1, 1735440, 0, 0, 0, 17, 23, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 1735440 - Set emote state 23');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=1735440 AND `point` IN (1);

-- Entry 10919 (Shatterspear Troll)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=10919 AND `AIName`='';
DELETE FROM `smart_scripts` WHERE `entryorguid`=10919 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (6830000,6830240,6830320,6830400,6842320,6842400,6843600,6843680,6843760,6843840,6843920,6844000,6844080,6844160,6844240,6844320,6844400,6844960);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(10919, 0, 0, 0, 40, 0, 100, 0, 1, 6830000, 0, 0, 0, 17, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 6830000 - Set emote state 10'),
(10919, 0, 1, 0, 40, 0, 100, 0, 2, 6830000, 0, 0, 0, 17, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 2 of path 6830000 - Set emote state 10'),
(10919, 0, 2, 0, 40, 0, 100, 0, 1, 6830240, 0, 0, 0, 17, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 6830240 - Set emote state 10'),
(10919, 0, 3, 0, 40, 0, 100, 0, 2, 6830240, 0, 0, 0, 17, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 2 of path 6830240 - Set emote state 10'),
(10919, 0, 4, 0, 40, 0, 100, 0, 1, 6830320, 0, 0, 0, 17, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 6830320 - Set emote state 10'),
(10919, 0, 5, 0, 40, 0, 100, 0, 2, 6830320, 0, 0, 0, 17, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 2 of path 6830320 - Set emote state 10'),
(10919, 0, 6, 0, 40, 0, 100, 0, 1, 6830400, 0, 0, 0, 17, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 6830400 - Set emote state 10'),
(10919, 0, 7, 0, 40, 0, 100, 0, 2, 6830400, 0, 0, 0, 17, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 2 of path 6830400 - Set emote state 10'),
(10919, 0, 8, 0, 40, 0, 100, 0, 1, 6842320, 0, 0, 0, 17, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 6842320 - Set emote state 10'),
(10919, 0, 9, 0, 40, 0, 100, 0, 2, 6842320, 0, 0, 0, 17, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 2 of path 6842320 - Set emote state 10'),
(10919, 0, 10, 0, 40, 0, 100, 0, 1, 6842400, 0, 0, 0, 17, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 6842400 - Set emote state 10'),
(10919, 0, 11, 0, 40, 0, 100, 0, 2, 6842400, 0, 0, 0, 17, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 2 of path 6842400 - Set emote state 10'),
(10919, 0, 12, 0, 40, 0, 100, 0, 1, 6843600, 0, 0, 0, 17, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 6843600 - Set emote state 10'),
(10919, 0, 13, 0, 40, 0, 100, 0, 2, 6843600, 0, 0, 0, 17, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 2 of path 6843600 - Set emote state 10'),
(10919, 0, 14, 0, 40, 0, 100, 0, 1, 6843680, 0, 0, 0, 17, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 6843680 - Set emote state 10'),
(10919, 0, 15, 0, 40, 0, 100, 0, 2, 6843680, 0, 0, 0, 17, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 2 of path 6843680 - Set emote state 10'),
(10919, 0, 16, 0, 40, 0, 100, 0, 1, 6843760, 0, 0, 0, 17, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 6843760 - Set emote state 10'),
(10919, 0, 17, 0, 40, 0, 100, 0, 2, 6843760, 0, 0, 0, 17, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 2 of path 6843760 - Set emote state 10'),
(10919, 0, 18, 0, 40, 0, 100, 0, 1, 6843840, 0, 0, 0, 17, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 6843840 - Set emote state 10'),
(10919, 0, 19, 0, 40, 0, 100, 0, 2, 6843840, 0, 0, 0, 17, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 2 of path 6843840 - Set emote state 10'),
(10919, 0, 20, 0, 40, 0, 100, 0, 1, 6843920, 0, 0, 0, 17, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 6843920 - Set emote state 10'),
(10919, 0, 21, 0, 40, 0, 100, 0, 2, 6843920, 0, 0, 0, 17, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 2 of path 6843920 - Set emote state 10'),
(10919, 0, 22, 0, 40, 0, 100, 0, 1, 6844000, 0, 0, 0, 17, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 6844000 - Set emote state 10'),
(10919, 0, 23, 0, 40, 0, 100, 0, 2, 6844000, 0, 0, 0, 17, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 2 of path 6844000 - Set emote state 10'),
(10919, 0, 24, 0, 40, 0, 100, 0, 1, 6844080, 0, 0, 0, 17, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 6844080 - Set emote state 10'),
(10919, 0, 25, 0, 40, 0, 100, 0, 2, 6844080, 0, 0, 0, 17, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 2 of path 6844080 - Set emote state 10'),
(10919, 0, 26, 0, 40, 0, 100, 0, 1, 6844160, 0, 0, 0, 17, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 6844160 - Set emote state 10'),
(10919, 0, 27, 0, 40, 0, 100, 0, 2, 6844160, 0, 0, 0, 17, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 2 of path 6844160 - Set emote state 10'),
(10919, 0, 28, 0, 40, 0, 100, 0, 1, 6844240, 0, 0, 0, 17, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 6844240 - Set emote state 10'),
(10919, 0, 29, 0, 40, 0, 100, 0, 2, 6844240, 0, 0, 0, 17, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 2 of path 6844240 - Set emote state 10'),
(10919, 0, 30, 0, 40, 0, 100, 0, 1, 6844320, 0, 0, 0, 17, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 6844320 - Set emote state 10'),
(10919, 0, 31, 0, 40, 0, 100, 0, 2, 6844320, 0, 0, 0, 17, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 2 of path 6844320 - Set emote state 10'),
(10919, 0, 32, 0, 40, 0, 100, 0, 1, 6844400, 0, 0, 0, 17, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 6844400 - Set emote state 10'),
(10919, 0, 33, 0, 40, 0, 100, 0, 2, 6844400, 0, 0, 0, 17, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 2 of path 6844400 - Set emote state 10'),
(10919, 0, 34, 0, 40, 0, 100, 0, 1, 6844960, 0, 0, 0, 17, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 6844960 - Set emote state 10'),
(10919, 0, 35, 0, 40, 0, 100, 0, 2, 6844960, 0, 0, 0, 17, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 2 of path 6844960 - Set emote state 10');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6830000 AND `point` IN (1,2);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6830240 AND `point` IN (1,2);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6830320 AND `point` IN (1,2);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6830400 AND `point` IN (1,2);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6842320 AND `point` IN (1,2);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6842400 AND `point` IN (1,2);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6843600 AND `point` IN (1,2);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6843680 AND `point` IN (1,2);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6843760 AND `point` IN (1,2);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6843840 AND `point` IN (1,2);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6843920 AND `point` IN (1,2);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6844000 AND `point` IN (1,2);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6844080 AND `point` IN (1,2);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6844160 AND `point` IN (1,2);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6844240 AND `point` IN (1,2);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6844320 AND `point` IN (1,2);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6844400 AND `point` IN (1,2);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6844960 AND `point` IN (1,2);

-- Entry 11038 (Caretaker Alen)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=11038 AND `AIName`='';
DELETE FROM `creature_text` WHERE `CreatureID`=11038 AND `BroadcastTextId` IN (6405,6406);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(11038, 0, 0, 'I come from the land down under... where women plague and men sunder.', 12, 0, 100, 0, 0, 0, 6406, 0, 'Caretaker Alen'),
(11038, 1, 0, 'And then the Tauren said, ''13 INCHES!''', 12, 0, 100, 0, 0, 0, 6405, 0, 'Caretaker Alen');
DELETE FROM `smart_scripts` WHERE `entryorguid`=11038 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (4379920);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(11038, 0, 0, 0, 40, 0, 100, 0, 2, 4379920, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 2 of path 4379920 - Talk (BroadcastText 6406)'),
(11038, 0, 1, 0, 40, 0, 100, 0, 6, 4379920, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 6 of path 4379920 - Talk (BroadcastText 6405)');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=4379920 AND `point` IN (2,6);

-- Entry 11196 (Shatterspear Drummer)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=11196 AND `AIName`='';
DELETE FROM `smart_scripts` WHERE `entryorguid`=11196 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (6844640,6844720,6844800);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(11196, 0, 0, 0, 40, 0, 100, 0, 1, 6844640, 0, 0, 0, 17, 36, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 6844640 - Set emote state 36'),
(11196, 0, 1, 0, 40, 0, 100, 0, 3, 6844640, 0, 0, 0, 17, 36, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 3 of path 6844640 - Set emote state 36'),
(11196, 0, 2, 0, 40, 0, 100, 0, 1, 6844720, 0, 0, 0, 17, 36, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 6844720 - Set emote state 36'),
(11196, 0, 3, 0, 40, 0, 100, 0, 3, 6844720, 0, 0, 0, 17, 36, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 3 of path 6844720 - Set emote state 36'),
(11196, 0, 4, 0, 40, 0, 100, 0, 1, 6844800, 0, 0, 0, 17, 36, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 6844800 - Set emote state 36'),
(11196, 0, 5, 0, 40, 0, 100, 0, 3, 6844800, 0, 0, 0, 17, 36, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 3 of path 6844800 - Set emote state 36');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6844640 AND `point` IN (1,3);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6844720 AND `point` IN (1,3);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6844800 AND `point` IN (1,3);

-- Entry 11260 (Northshire Peasant)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=11260 AND `AIName`='';
DELETE FROM `smart_scripts` WHERE `entryorguid`=11260 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (6409520,6410160,6410960,6411600,6420960);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(11260, 0, 0, 0, 40, 0, 100, 0, 1, 6409520, 0, 0, 0, 17, 234, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 6409520 - Set emote state 234'),
(11260, 0, 1, 0, 40, 0, 100, 0, 1, 6410160, 0, 0, 0, 3, 0, 89, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 6410160 - Morph to model 89'),
(11260, 0, 2, 0, 40, 0, 100, 0, 4, 6410160, 0, 0, 0, 3, 0, 308, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 4 of path 6410160 - Morph to model 308'),
(11260, 0, 3, 0, 40, 0, 100, 0, 7, 6410160, 0, 0, 0, 17, 234, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 7 of path 6410160 - Set emote state 234'),
(11260, 0, 4, 0, 40, 0, 100, 0, 1, 6410960, 0, 0, 0, 3, 0, 89, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 6410960 - Morph to model 89'),
(11260, 0, 5, 0, 40, 0, 100, 0, 3, 6410960, 0, 0, 0, 3, 0, 308, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 3 of path 6410960 - Morph to model 308'),
(11260, 0, 6, 0, 40, 0, 100, 0, 5, 6410960, 0, 0, 0, 17, 234, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 5 of path 6410960 - Set emote state 234'),
(11260, 0, 7, 0, 40, 0, 100, 0, 4, 6411600, 0, 0, 0, 17, 234, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 4 of path 6411600 - Set emote state 234'),
(11260, 0, 8, 0, 40, 0, 100, 0, 5, 6411600, 0, 0, 0, 3, 0, 89, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 5 of path 6411600 - Morph to model 89'),
(11260, 0, 9, 0, 40, 0, 100, 0, 8, 6411600, 0, 0, 0, 3, 0, 308, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 8 of path 6411600 - Morph to model 308'),
(11260, 0, 10, 0, 40, 0, 100, 0, 1, 6420960, 0, 0, 0, 3, 0, 89, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 6420960 - Morph to model 89'),
(11260, 0, 11, 0, 40, 0, 100, 0, 5, 6420960, 0, 0, 0, 3, 0, 308, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 5 of path 6420960 - Morph to model 308'),
(11260, 0, 12, 0, 40, 0, 100, 0, 9, 6420960, 0, 0, 0, 17, 234, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 9 of path 6420960 - Set emote state 234');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6409520 AND `point` IN (1);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6410160 AND `point` IN (1,4,7);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6410960 AND `point` IN (1,3,5);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6411600 AND `point` IN (4,5,8);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6420960 AND `point` IN (1,5,9);

-- Entry 11328 (Eastvale Peasant)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=11328 AND `AIName`='';
DELETE FROM `smart_scripts` WHERE `entryorguid`=11328 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (6499920,6500000,6500160,6507840,6507920);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(11328, 0, 0, 0, 40, 0, 100, 0, 1, 6499920, 0, 0, 0, 3, 0, 308, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 6499920 - Morph to model 308'),
(11328, 0, 1, 0, 40, 0, 100, 0, 4, 6499920, 0, 0, 0, 5, 234, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 4 of path 6499920 - Play emote 234'),
(11328, 0, 2, 0, 40, 0, 100, 0, 5, 6499920, 0, 0, 0, 3, 0, 89, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 5 of path 6499920 - Morph to model 89'),
(11328, 0, 3, 0, 40, 0, 100, 0, 1, 6500000, 0, 0, 0, 3, 0, 308, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 6500000 - Morph to model 308'),
(11328, 0, 4, 0, 40, 0, 100, 0, 2, 6500000, 0, 0, 0, 5, 234, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 2 of path 6500000 - Play emote 234'),
(11328, 0, 5, 0, 40, 0, 100, 0, 3, 6500000, 0, 0, 0, 3, 0, 89, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 3 of path 6500000 - Morph to model 89'),
(11328, 0, 6, 0, 40, 0, 100, 0, 4, 6500160, 0, 0, 0, 3, 0, 308, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 4 of path 6500160 - Morph to model 308'),
(11328, 0, 7, 0, 40, 0, 100, 0, 8, 6500160, 0, 0, 0, 5, 234, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 8 of path 6500160 - Play emote 234'),
(11328, 0, 8, 0, 40, 0, 100, 0, 9, 6500160, 0, 0, 0, 3, 0, 89, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 9 of path 6500160 - Morph to model 89'),
(11328, 0, 9, 0, 40, 0, 100, 0, 5, 6507840, 0, 0, 0, 3, 0, 308, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 5 of path 6507840 - Morph to model 308'),
(11328, 0, 10, 0, 40, 0, 100, 0, 10, 6507840, 0, 0, 0, 5, 234, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 10 of path 6507840 - Play emote 234'),
(11328, 0, 11, 0, 40, 0, 100, 0, 11, 6507840, 0, 0, 0, 3, 0, 89, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 11 of path 6507840 - Morph to model 89'),
(11328, 0, 12, 0, 40, 0, 100, 0, 2, 6507920, 0, 0, 0, 3, 0, 308, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 2 of path 6507920 - Morph to model 308'),
(11328, 0, 13, 0, 40, 0, 100, 0, 6, 6507920, 0, 0, 0, 5, 234, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 6 of path 6507920 - Play emote 234'),
(11328, 0, 14, 0, 40, 0, 100, 0, 7, 6507920, 0, 0, 0, 3, 0, 89, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 7 of path 6507920 - Morph to model 89');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6499920 AND `point` IN (1,4,5);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6500000 AND `point` IN (1,2,3);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6500160 AND `point` IN (4,8,9);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6507840 AND `point` IN (5,10,11);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6507920 AND `point` IN (2,6,7);

-- Entry 11815 (Voriya)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=11815 AND `AIName`='';
DELETE FROM `smart_scripts` WHERE `entryorguid`=11815 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (6844880);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(11815, 0, 0, 0, 40, 0, 100, 0, 1, 6844880, 0, 0, 0, 17, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 6844880 - Set emote state 10'),
(11815, 0, 1, 0, 40, 0, 100, 0, 2, 6844880, 0, 0, 0, 17, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 2 of path 6844880 - Set emote state 10');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6844880 AND `point` IN (1,2);

-- Entry 14730 (Revantusk Watcher)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=14730 AND `AIName`='';
DELETE FROM `smart_scripts` WHERE `entryorguid`=14730 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (7431840,7431920);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(14730, 0, 0, 0, 40, 0, 100, 0, 4, 7431840, 0, 0, 0, 62, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, -621.969, -4670.08, 5.06115, 1.09835, 'On WP 4 of path 7431840 - Teleport to (-621.969,-4670.08,5.06115,1.09835) map 0'),
(14730, 0, 1, 0, 40, 0, 100, 0, 13, 7431920, 0, 0, 0, 62, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, -619.393, -4664.69, 5.05786, 1.12032, 'On WP 13 of path 7431920 - Teleport to (-619.393,-4664.69,5.05786,1.12032) map 0');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=7431840 AND `point` IN (4);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=7431920 AND `point` IN (13);

-- Entry 14737 (Smith Slagtree)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=14737 AND `AIName`='';
DELETE FROM `smart_scripts` WHERE `entryorguid`=1473700 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1473700, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 3.22886, 'After 1s - Set orientation 3.22886'),
(1473700, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 1s - Set UNIT_FIELD_BYTES_1 8 (standstate)'),
(1473700, 9, 2, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 90, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 3s - Set UNIT_FIELD_BYTES_1 0 (standstate)');
DELETE FROM `smart_scripts` WHERE `entryorguid`=1473701 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1473701, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0.610865, 'After 1s - Set orientation 0.610865'),
(1473701, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 11, 23488, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 1s - Cast spell 23488 on self'),
(1473701, 9, 2, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 17, 233, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 3s - Set emote state 233'),
(1473701, 9, 3, 0, 0, 0, 100, 0, 19000, 19000, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 19s - Set emote state 69');
DELETE FROM `smart_scripts` WHERE `entryorguid`=14737 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (7432720);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(14737, 0, 0, 0, 40, 0, 100, 0, 2, 7432720, 0, 0, 0, 80, 1473700, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 2 of path 7432720 - Start timed actionlist 1473700'),
(14737, 0, 1, 0, 40, 0, 100, 0, 3, 7432720, 0, 0, 0, 80, 1473701, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 3 of path 7432720 - Start timed actionlist 1473701');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=7432720 AND `point` IN (2,3);

-- Entry 14739 (Mystic Yayo'jin)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=14739 AND `AIName`='';
DELETE FROM `smart_scripts` WHERE `entryorguid`=1473900 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1473900, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 90, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 2s - Set UNIT_FIELD_BYTES_1 1 (standstate)'),
(1473900, 9, 1, 0, 0, 0, 100, 0, 37000, 37000, 0, 0, 0, 90, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 37s - Set UNIT_FIELD_BYTES_1 0 (standstate)'),
(1473900, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 17, 133, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 2s - Set emote state 133');
DELETE FROM `smart_scripts` WHERE `entryorguid`=14739 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (7432880);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(14739, 0, 0, 0, 40, 0, 100, 0, 11, 7432880, 0, 0, 0, 80, 1473900, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 11 of path 7432880 - Start timed actionlist 1473900');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=7432880 AND `point` IN (11);

-- Entry 14823 (Silas Darkmoon)
DELETE FROM `smart_scripts` WHERE `entryorguid`=14823 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (4507840);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(14823, 0, 0, 0, 40, 0, 100, 0, 2, 4507840, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 2 of path 4507840 - Talk (BroadcastText 10158)'),
(14823, 0, 1, 0, 40, 0, 100, 0, 6, 4507840, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 6 of path 4507840 - Talk (BroadcastText 22544)');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=4507840 AND `point` IN (2,6);

-- Entry 14901 (Peon)
DELETE FROM `smart_scripts` WHERE `entryorguid`=1490100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1490100, 9, 0, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 5, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 3s - Play emote 69'),
(1490100, 9, 1, 0, 0, 0, 100, 0, 232000, 232000, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 232s - Play emote 0');
DELETE FROM `smart_scripts` WHERE `entryorguid`=14901 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (1102000);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(14901, 0, 0, 0, 40, 0, 100, 0, 4, 1102000, 0, 0, 0, 80, 1490100, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 4 of path 1102000 - Start timed actionlist 1490100');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=1102000 AND `point` IN (4);

-- Entry 16591 (Thrallmar Peon)
DELETE FROM `smart_scripts` WHERE `entryorguid`=1659100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1659100, 9, 0, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 5, 233, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 3s - Play emote 233'),
(1659100, 9, 1, 0, 0, 0, 100, 0, 54000, 54000, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 54s - Play emote 0');
DELETE FROM `smart_scripts` WHERE `entryorguid`=1659101 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1659101, 9, 0, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 5, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 3s - Play emote 69'),
(1659101, 9, 1, 0, 0, 0, 100, 0, 54000, 54000, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 54s - Play emote 0');
DELETE FROM `smart_scripts` WHERE `entryorguid`=16591 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (4606080);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(16591, 0, 1, 0, 40, 0, 100, 0, 7, 4606080, 0, 0, 0, 80, 1659100, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 7 of path 4606080 - Start timed actionlist 1659100'),
(16591, 0, 2, 0, 40, 0, 100, 0, 16, 4606080, 0, 0, 0, 80, 1659101, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 16 of path 4606080 - Start timed actionlist 1659101'),
(16591, 0, 3, 0, 40, 0, 100, 0, 23, 4606080, 0, 0, 0, 80, 1659101, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 23 of path 4606080 - Start timed actionlist 1659101');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=4606080 AND `point` IN (7,16,23);

-- Entry 17994 (Bloodwarder Falconer)
DELETE FROM `smart_scripts` WHERE `entryorguid`=17994 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (6640560);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(17994, 0, 1, 0, 40, 0, 100, 0, 10, 6640560, 0, 0, 0, 17, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 10 of path 6640560 - Set emote state 25'),
(17994, 0, 2, 0, 40, 0, 100, 0, 17, 6640560, 0, 0, 0, 17, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 17 of path 6640560 - Set emote state 25'),
(17994, 0, 3, 0, 40, 0, 100, 0, 21, 6640560, 0, 0, 0, 17, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 21 of path 6640560 - Set emote state 25');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6640560 AND `point` IN (10,17,21);

-- Entry 18298 (Gava'xi)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=18298 AND `AIName`='';
DELETE FROM `smart_scripts` WHERE `entryorguid`=18298 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (6928640);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(18298, 0, 0, 0, 40, 0, 100, 0, 13, 6928640, 0, 0, 0, 17, 11, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 13 of path 6928640 - Set emote state 11');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6928640 AND `point` IN (13);

-- Entry 18497 (Auchenai Monk)
DELETE FROM `smart_scripts` WHERE `entryorguid`=1849700 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1849700, 9, 0, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 8s - Set UNIT_FIELD_BYTES_1 8 (standstate)'),
(1849700, 9, 1, 0, 0, 0, 100, 0, 22000, 22000, 0, 0, 0, 90, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 22s - Set UNIT_FIELD_BYTES_1 0 (standstate)');
DELETE FROM `smart_scripts` WHERE `entryorguid`=1849701 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1849701, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 1s - Set UNIT_FIELD_BYTES_1 8 (standstate)'),
(1849701, 9, 1, 0, 0, 0, 100, 0, 32000, 32000, 0, 0, 0, 90, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 32s - Set UNIT_FIELD_BYTES_1 0 (standstate)');
DELETE FROM `smart_scripts` WHERE `entryorguid`=18497 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (6671200);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(18497, 0, 7, 0, 40, 0, 100, 0, 1, 6671200, 0, 0, 0, 80, 1849700, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 6671200 - Start timed actionlist 1849700'),
(18497, 0, 8, 0, 40, 0, 100, 0, 16, 6671200, 0, 0, 0, 80, 1849701, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 16 of path 6671200 - Start timed actionlist 1849701');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6671200 AND `point` IN (1,16);

-- Entry 18547 (Scryer Arcanist)
DELETE FROM `smart_scripts` WHERE `entryorguid`=18547 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (5336480,5336640,5336720,5336800,5336880,5336960,5337040,5337120,5337200);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(18547, 0, 3, 0, 40, 0, 100, 0, 1, 5336480, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 5336480 - Set emote state 69'),
(18547, 0, 4, 0, 40, 0, 100, 0, 3, 5336480, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 3 of path 5336480 - Set emote state 69'),
(18547, 0, 5, 0, 40, 0, 100, 0, 6, 5336480, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 6 of path 5336480 - Set emote state 69'),
(18547, 0, 6, 0, 40, 0, 100, 0, 1, 5336640, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 5336640 - Set emote state 69'),
(18547, 0, 7, 0, 40, 0, 100, 0, 5, 5336640, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 5 of path 5336640 - Set emote state 69'),
(18547, 0, 8, 0, 40, 0, 100, 0, 1, 5336720, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 5336720 - Set emote state 69'),
(18547, 0, 9, 0, 40, 0, 100, 0, 6, 5336720, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 6 of path 5336720 - Set emote state 69'),
(18547, 0, 10, 0, 40, 0, 100, 0, 12, 5336720, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 12 of path 5336720 - Set emote state 69'),
(18547, 0, 11, 0, 40, 0, 100, 0, 1, 5336800, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 5336800 - Set emote state 69'),
(18547, 0, 12, 0, 40, 0, 100, 0, 5, 5336800, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 5 of path 5336800 - Set emote state 69'),
(18547, 0, 13, 0, 40, 0, 100, 0, 10, 5336800, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 10 of path 5336800 - Set emote state 69'),
(18547, 0, 14, 0, 40, 0, 100, 0, 1, 5336880, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 5336880 - Set emote state 69'),
(18547, 0, 15, 0, 40, 0, 100, 0, 4, 5336880, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 4 of path 5336880 - Set emote state 69'),
(18547, 0, 16, 0, 40, 0, 100, 0, 6, 5336880, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 6 of path 5336880 - Set emote state 69'),
(18547, 0, 17, 0, 40, 0, 100, 0, 8, 5336880, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 8 of path 5336880 - Set emote state 69'),
(18547, 0, 18, 0, 40, 0, 100, 0, 12, 5336880, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 12 of path 5336880 - Set emote state 69'),
(18547, 0, 19, 0, 40, 0, 100, 0, 1, 5336960, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 5336960 - Set emote state 69'),
(18547, 0, 20, 0, 40, 0, 100, 0, 7, 5336960, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 7 of path 5336960 - Set emote state 69'),
(18547, 0, 21, 0, 40, 0, 100, 0, 8, 5336960, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 8 of path 5336960 - Set emote state 69'),
(18547, 0, 22, 0, 40, 0, 100, 0, 9, 5336960, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 9 of path 5336960 - Set emote state 69'),
(18547, 0, 23, 0, 40, 0, 100, 0, 1, 5337040, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 5337040 - Set emote state 69'),
(18547, 0, 24, 0, 40, 0, 100, 0, 4, 5337040, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 4 of path 5337040 - Set emote state 69'),
(18547, 0, 25, 0, 40, 0, 100, 0, 8, 5337040, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 8 of path 5337040 - Set emote state 69'),
(18547, 0, 26, 0, 40, 0, 100, 0, 1, 5337120, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 5337120 - Set emote state 69'),
(18547, 0, 27, 0, 40, 0, 100, 0, 2, 5337120, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 2 of path 5337120 - Set emote state 69'),
(18547, 0, 28, 0, 40, 0, 100, 0, 12, 5337120, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 12 of path 5337120 - Set emote state 69'),
(18547, 0, 29, 0, 40, 0, 100, 0, 14, 5337120, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 14 of path 5337120 - Set emote state 69'),
(18547, 0, 30, 0, 40, 0, 100, 0, 9, 5337200, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 9 of path 5337200 - Set emote state 69'),
(18547, 0, 31, 0, 40, 0, 100, 0, 10, 5337200, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 10 of path 5337200 - Set emote state 69');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5336480 AND `point` IN (1,3,6);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5336640 AND `point` IN (1,5);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5336720 AND `point` IN (1,6,12);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5336800 AND `point` IN (1,5,10);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5336880 AND `point` IN (1,4,6,8,12);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5336960 AND `point` IN (1,7,8,9);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5337040 AND `point` IN (1,4,8);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5337120 AND `point` IN (1,2,12,14);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5337200 AND `point` IN (9,10);

-- Entry 18907 (Innkeeper Coryth Stoktron)
DELETE FROM `smart_scripts` WHERE `entryorguid`=18907 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (5430400);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(18907, 0, 2, 0, 40, 0, 100, 0, 2, 5430400, 0, 0, 0, 17, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 2 of path 5430400 - Set emote state 1'),
(18907, 0, 3, 0, 40, 0, 100, 0, 4, 5430400, 0, 0, 0, 17, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 4 of path 5430400 - Set emote state 6'),
(18907, 0, 4, 0, 40, 0, 100, 0, 6, 5430400, 0, 0, 0, 17, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 6 of path 5430400 - Set emote state 1');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5430400 AND `point` IN (2,4,6);

-- Entry 18973 (Stonebreaker Grunt)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=18973 AND `AIName`='';
DELETE FROM `smart_scripts` WHERE `entryorguid`=18973 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (5450720,5450800,5450880,5450960,5451040,5451200);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(18973, 0, 0, 0, 40, 0, 100, 0, 1, 5450720, 0, 0, 0, 17, 36, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 5450720 - Set emote state 36'),
(18973, 0, 1, 0, 40, 0, 100, 0, 1, 5450800, 0, 0, 0, 17, 36, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 5450800 - Set emote state 36'),
(18973, 0, 2, 0, 40, 0, 100, 0, 1, 5450880, 0, 0, 0, 17, 36, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 5450880 - Set emote state 36'),
(18973, 0, 3, 0, 40, 0, 100, 0, 1, 5450960, 0, 0, 0, 17, 36, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 5450960 - Set emote state 36'),
(18973, 0, 4, 0, 40, 0, 100, 0, 1, 5451040, 0, 0, 0, 17, 36, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 5451040 - Set emote state 36'),
(18973, 0, 5, 0, 40, 0, 100, 0, 1, 5451200, 0, 0, 0, 17, 36, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 5451200 - Set emote state 36');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5450720 AND `point` IN (1);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5450800 AND `point` IN (1);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5450880 AND `point` IN (1);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5450960 AND `point` IN (1);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5451040 AND `point` IN (1);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5451200 AND `point` IN (1);

-- Entry 18993 (Naka)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=18993 AND `AIName`='';
DELETE FROM `smart_scripts` WHERE `entryorguid`=18993 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (5461840);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(18993, 0, 0, 0, 40, 0, 100, 0, 1, 5461840, 0, 0, 0, 17, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 5461840 - Set emote state 1'),
(18993, 0, 1, 0, 40, 0, 100, 0, 3, 5461840, 0, 0, 0, 17, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 3 of path 5461840 - Set emote state 1'),
(18993, 0, 2, 0, 40, 0, 100, 0, 5, 5461840, 0, 0, 0, 17, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 5 of path 5461840 - Set emote state 6');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5461840 AND `point` IN (1,3,5);

-- Entry 19002 (Gardok Ripjaw)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=19002 AND `AIName`='';
DELETE FROM `smart_scripts` WHERE `entryorguid`=19002 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (5464560);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(19002, 0, 0, 0, 40, 0, 100, 0, 1, 5464560, 0, 0, 0, 17, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 5464560 - Set emote state 5'),
(19002, 0, 1, 0, 40, 0, 100, 0, 3, 5464560, 0, 0, 0, 17, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 3 of path 5464560 - Set emote state 5'),
(19002, 0, 2, 0, 40, 0, 100, 0, 5, 5464560, 0, 0, 0, 17, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 5 of path 5464560 - Set emote state 5'),
(19002, 0, 3, 0, 40, 0, 100, 0, 7, 5464560, 0, 0, 0, 17, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 7 of path 5464560 - Set emote state 5'),
(19002, 0, 4, 0, 40, 0, 100, 0, 9, 5464560, 0, 0, 0, 17, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 9 of path 5464560 - Set emote state 5'),
(19002, 0, 5, 0, 40, 0, 100, 0, 11, 5464560, 0, 0, 0, 17, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 11 of path 5464560 - Set emote state 5'),
(19002, 0, 6, 0, 40, 0, 100, 0, 13, 5464560, 0, 0, 0, 17, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 13 of path 5464560 - Set emote state 5'),
(19002, 0, 7, 0, 40, 0, 100, 0, 15, 5464560, 0, 0, 0, 17, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 15 of path 5464560 - Set emote state 5'),
(19002, 0, 8, 0, 40, 0, 100, 0, 17, 5464560, 0, 0, 0, 17, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 17 of path 5464560 - Set emote state 5'),
(19002, 0, 9, 0, 40, 0, 100, 0, 19, 5464560, 0, 0, 0, 17, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 19 of path 5464560 - Set emote state 5'),
(19002, 0, 10, 0, 40, 0, 100, 0, 21, 5464560, 0, 0, 0, 17, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 21 of path 5464560 - Set emote state 5'),
(19002, 0, 11, 0, 40, 0, 100, 0, 23, 5464560, 0, 0, 0, 17, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 23 of path 5464560 - Set emote state 5');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5464560 AND `point` IN (1,3,5,7,9,11,13,15,17,19,21,23);

-- Entry 19147 (Allerian Peasant)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=19147 AND `AIName`='';
DELETE FROM `smart_scripts` WHERE `entryorguid`=1914700 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1914700, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 3.83972, 'After 0s - Set orientation 3.83972'),
(1914700, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 17, 381, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 1s - Set emote state 381');
DELETE FROM `smart_scripts` WHERE `entryorguid`=1914701 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1914701, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 1.5708, 'After 0s - Set orientation 1.5708'),
(1914701, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 17, 381, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 1s - Set emote state 381');
DELETE FROM `smart_scripts` WHERE `entryorguid`=1914702 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1914702, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 1.41372, 'After 0s - Set orientation 1.41372'),
(1914702, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 17, 381, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 1s - Set emote state 381');
DELETE FROM `smart_scripts` WHERE `entryorguid`=19147 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (5477440,5477520,5477600);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(19147, 0, 0, 0, 40, 0, 100, 0, 6, 5477440, 0, 0, 0, 80, 1914700, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 6 of path 5477440 - Start timed actionlist 1914700'),
(19147, 0, 1, 0, 40, 0, 100, 0, 12, 5477440, 0, 0, 0, 17, 381, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 12 of path 5477440 - Set emote state 381'),
(19147, 0, 2, 0, 40, 0, 100, 0, 11, 5477520, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 11 of path 5477520 - Set emote state 69'),
(19147, 0, 3, 0, 40, 0, 100, 0, 22, 5477520, 0, 0, 0, 80, 1914701, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 22 of path 5477520 - Start timed actionlist 1914701'),
(19147, 0, 4, 0, 40, 0, 100, 0, 6, 5477600, 0, 0, 0, 80, 1914702, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 6 of path 5477600 - Start timed actionlist 1914702'),
(19147, 0, 5, 0, 40, 0, 100, 0, 11, 5477600, 0, 0, 0, 17, 381, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 11 of path 5477600 - Set emote state 381');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5477440 AND `point` IN (6,12);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5477520 AND `point` IN (11,22);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5477600 AND `point` IN (6,11);

-- Entry 19181 (Lemla Hopewing)
DELETE FROM `smart_scripts` WHERE `entryorguid`=19181 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (5490080);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(19181, 0, 3, 0, 40, 0, 100, 0, 1, 5490080, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 1.27409, 'On WP 1 of path 5490080 - Set orientation 1.27409');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5490080 AND `point` IN (1);

-- Entry 21197 (Bronwyn Stouthammer)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=21197 AND `AIName`='';
DELETE FROM `smart_scripts` WHERE `entryorguid`=21197 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (5946560);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(21197, 0, 0, 0, 40, 0, 100, 0, 1, 5946560, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 5946560 - Set emote state 69'),
(21197, 0, 1, 0, 40, 0, 100, 0, 2, 5946560, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 2 of path 5946560 - Set emote state 69');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5946560 AND `point` IN (1,2);

-- Entry 23602 (Deserter Agitator)
DELETE FROM `smart_scripts` WHERE `entryorguid`=2360202 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(2360202, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Talk (BroadcastText 22050)'),
(2360202, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 17, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Set emote state 1');
DELETE FROM `smart_scripts` WHERE `entryorguid`=2360203 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(2360203, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Talk (BroadcastText 22051)'),
(2360203, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 17, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Set emote state 1');
DELETE FROM `smart_scripts` WHERE `entryorguid`=2360204 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(2360204, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Talk (BroadcastText 22052)'),
(2360204, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 17, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Set emote state 1');
DELETE FROM `smart_scripts` WHERE `entryorguid`=23602 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (2483680);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(23602, 0, 8, 0, 40, 0, 100, 0, 2, 2483680, 0, 0, 0, 80, 2360202, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 2 of path 2483680 - Start timed actionlist 2360202'),
(23602, 0, 9, 0, 40, 0, 100, 0, 3, 2483680, 0, 0, 0, 80, 2360203, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 3 of path 2483680 - Start timed actionlist 2360203'),
(23602, 0, 10, 0, 40, 0, 100, 0, 4, 2483680, 0, 0, 0, 80, 2360204, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 4 of path 2483680 - Start timed actionlist 2360204');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=2483680 AND `point` IN (2,3,4);

-- Entry 23776 (Dark Ranger)
DELETE FROM `smart_scripts` WHERE `entryorguid`=2377600 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(2377600, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 5, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Play emote 10'),
(2377600, 9, 1, 0, 0, 0, 100, 0, 30000, 30000, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 30s - Play emote 0');
DELETE FROM `smart_scripts` WHERE `entryorguid`=23776 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (7132560);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(23776, 0, 3, 0, 40, 0, 100, 0, 1, 7132560, 0, 0, 0, 80, 2377600, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 7132560 - Start timed actionlist 2377600');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=7132560 AND `point` IN (1);

-- Entry 23858 (Donna Brascoe)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=23858 AND `AIName`='';
DELETE FROM `smart_scripts` WHERE `entryorguid`=23858 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (165600);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(23858, 0, 0, 0, 40, 0, 100, 0, 2, 165600, 0, 0, 0, 17, 28, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 2 of path 165600 - Set emote state 28'),
(23858, 0, 1, 0, 40, 0, 100, 0, 4, 165600, 0, 0, 0, 17, 28, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 4 of path 165600 - Set emote state 28');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=165600 AND `point` IN (2,4);

-- Entry 23896 ("Dirty" Michael Crowe)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=23896 AND `AIName`='';
DELETE FROM `creature_text` WHERE `CreatureID`=23896 AND `BroadcastTextId` IN (22392);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(23896, 0, 0, 'You might wanna stand back. Fish guttin'' is a dirty job.', 12, 0, 100, 0, 0, 0, 22392, 0, '"Dirty" Michael Crowe');
DELETE FROM `smart_scripts` WHERE `entryorguid`=2389600 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(2389600, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Talk (BroadcastText 22392)'),
(2389600, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 17, 15, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Set emote state 15');
DELETE FROM `smart_scripts` WHERE `entryorguid`=23896 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (2451920);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(23896, 0, 0, 0, 40, 0, 100, 0, 2, 2451920, 0, 0, 0, 80, 2389600, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 2 of path 2451920 - Start timed actionlist 2389600');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=2451920 AND `point` IN (2);

-- Entry 24689 (Wretched Bruiser)
DELETE FROM `smart_scripts` WHERE `entryorguid`=24689 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (7746400);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(24689, 0, 2, 0, 40, 0, 100, 0, 1, 7746400, 0, 0, 0, 17, 398, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 7746400 - Set emote state 398'),
(24689, 0, 3, 0, 40, 0, 100, 0, 2, 7746400, 0, 0, 0, 17, 398, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 2 of path 7746400 - Set emote state 398');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=7746400 AND `point` IN (1,2);

-- Entry 24787 (Fjord Hawk Matriarch)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=24787 AND `AIName`='';
DELETE FROM `smart_scripts` WHERE `entryorguid`=24787 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (9266880);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(24787, 0, 0, 0, 40, 0, 100, 0, 9, 9266880, 0, 0, 0, 17, 11, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 9 of path 9266880 - Set emote state 11');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=9266880 AND `point` IN (9);

-- Entry 25138 (Captain Dranarus)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=25138 AND `AIName`='';
DELETE FROM `smart_scripts` WHERE `entryorguid`=2513800 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(2513800, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 17, 22, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Set emote state 22'),
(2513800, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 4, 9739, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Play sound 9739');
DELETE FROM `smart_scripts` WHERE `entryorguid`=25138 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (7729520);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25138, 0, 0, 0, 40, 0, 100, 0, 2, 7729520, 0, 0, 0, 17, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 2 of path 7729520 - Set emote state 25'),
(25138, 0, 1, 0, 40, 0, 100, 0, 4, 7729520, 0, 0, 0, 80, 2513800, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 4 of path 7729520 - Start timed actionlist 2513800'),
(25138, 0, 2, 0, 40, 0, 100, 0, 5, 7729520, 0, 0, 0, 17, 18, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 5 of path 7729520 - Set emote state 18'),
(25138, 0, 3, 0, 40, 0, 100, 0, 11, 7729520, 0, 0, 0, 17, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 11 of path 7729520 - Set emote state 25'),
(25138, 0, 4, 0, 40, 0, 100, 0, 12, 7729520, 0, 0, 0, 17, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 12 of path 7729520 - Set emote state 5'),
(25138, 0, 5, 0, 40, 0, 100, 0, 13, 7729520, 0, 0, 0, 17, 21, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 13 of path 7729520 - Set emote state 21'),
(25138, 0, 6, 0, 40, 0, 100, 0, 17, 7729520, 0, 0, 0, 80, 2513800, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 17 of path 7729520 - Start timed actionlist 2513800'),
(25138, 0, 7, 0, 40, 0, 100, 0, 20, 7729520, 0, 0, 0, 17, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 20 of path 7729520 - Set emote state 25'),
(25138, 0, 8, 0, 40, 0, 100, 0, 21, 7729520, 0, 0, 0, 17, 274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 21 of path 7729520 - Set emote state 274'),
(25138, 0, 9, 0, 40, 0, 100, 0, 22, 7729520, 0, 0, 0, 17, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 22 of path 7729520 - Set emote state 25'),
(25138, 0, 10, 0, 40, 0, 100, 0, 23, 7729520, 0, 0, 0, 17, 11, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 23 of path 7729520 - Set emote state 11'),
(25138, 0, 11, 0, 40, 0, 100, 0, 27, 7729520, 0, 0, 0, 80, 2513800, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 27 of path 7729520 - Start timed actionlist 2513800'),
(25138, 0, 12, 0, 40, 0, 100, 0, 30, 7729520, 0, 0, 0, 17, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 30 of path 7729520 - Set emote state 25'),
(25138, 0, 13, 0, 40, 0, 100, 0, 31, 7729520, 0, 0, 0, 17, 273, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 31 of path 7729520 - Set emote state 273'),
(25138, 0, 14, 0, 40, 0, 100, 0, 32, 7729520, 0, 0, 0, 17, 21, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 32 of path 7729520 - Set emote state 21'),
(25138, 0, 15, 0, 40, 0, 100, 0, 35, 7729520, 0, 0, 0, 80, 2513800, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 35 of path 7729520 - Start timed actionlist 2513800');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=7729520 AND `point` IN (2,3,4,5,11,12,13,17,20,21,22,23,27,30,31,32,35);

-- Entry 26222 (Twilight Cryomancer)
DELETE FROM `smart_scripts` WHERE `entryorguid`=26222 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (165600);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(26222, 0, 4, 0, 40, 0, 100, 0, 2, 165600, 0, 0, 0, 17, 28, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 2 of path 165600 - Set emote state 28'),
(26222, 0, 5, 0, 40, 0, 100, 0, 4, 165600, 0, 0, 0, 17, 28, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 4 of path 165600 - Set emote state 28');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=165600 AND `point` IN (2,4);

-- Entry 26291 (Crystalline Ice Giant)
DELETE FROM `smart_scripts` WHERE `entryorguid`=26291 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (9029200,9029280);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(26291, 0, 2, 0, 40, 0, 100, 0, 1, 9029200, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 2.9147, 'On WP 1 of path 9029200 - Set orientation 2.9147'),
(26291, 0, 3, 0, 40, 0, 100, 0, 2, 9029200, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 5.20108, 'On WP 2 of path 9029200 - Set orientation 5.20108'),
(26291, 0, 4, 0, 40, 0, 100, 0, 1, 9029280, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0.855211, 'On WP 1 of path 9029280 - Set orientation 0.855211'),
(26291, 0, 5, 0, 40, 0, 100, 0, 3, 9029280, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0.890118, 'On WP 3 of path 9029280 - Set orientation 0.890118'),
(26291, 0, 6, 0, 40, 0, 100, 0, 5, 9029280, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0.0698132, 'On WP 5 of path 9029280 - Set orientation 0.0698132');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=9029200 AND `point` IN (1,2);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=9029280 AND `point` IN (1,3,5);

-- Entry 26978 (Duane)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=26978 AND `AIName`='';
DELETE FROM `smart_scripts` WHERE `entryorguid`=26978 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (7053600);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(26978, 0, 0, 0, 40, 0, 100, 0, 3, 7053600, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 5.18363, 'On WP 3 of path 7053600 - Set orientation 5.18363'),
(26978, 0, 1, 0, 40, 0, 100, 0, 6, 7053600, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 4.10152, 'On WP 6 of path 7053600 - Set orientation 4.10152');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=7053600 AND `point` IN (3,6);

-- Entry 27044 (Ordal McLumpkins)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=27044 AND `AIName`='';
DELETE FROM `smart_scripts` WHERE `entryorguid`=2704400 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(2704400, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 1.46608, 'After 0s - Set orientation 1.46608'),
(2704400, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 1s - Set emote state 69');
DELETE FROM `smart_scripts` WHERE `entryorguid`=2704401 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(2704401, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 4.63913, 'After 0s - Set orientation 4.63913'),
(2704401, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 1s - Set emote state 69');
DELETE FROM `smart_scripts` WHERE `entryorguid`=27044 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (10689520);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(27044, 0, 0, 0, 40, 0, 100, 0, 2, 10689520, 0, 0, 0, 80, 2704400, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 2 of path 10689520 - Start timed actionlist 2704400'),
(27044, 0, 1, 0, 40, 0, 100, 0, 4, 10689520, 0, 0, 0, 80, 2704401, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 4 of path 10689520 - Start timed actionlist 2704401'),
(27044, 0, 2, 0, 40, 0, 100, 0, 6, 10689520, 0, 0, 0, 80, 2704401, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 6 of path 10689520 - Start timed actionlist 2704401');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10689520 AND `point` IN (2,4,6);

-- Entry 28052 (Dread Crew)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=28052 AND `AIName`='';
DELETE FROM `smart_scripts` WHERE `entryorguid`=2805200 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(2805200, 9, 0, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 5, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 3s - Play emote 69'),
(2805200, 9, 1, 0, 0, 0, 100, 0, 14000, 14000, 0, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 14s - Set emote state 0');
DELETE FROM `smart_scripts` WHERE `entryorguid`=28052 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (12012800,12012880,12012960,12013200,12013600,12013680,12013760,12014160,12014320);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(28052, 0, 0, 0, 40, 0, 100, 0, 1, 12012800, 0, 0, 0, 17, 71, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 12012800 - Set emote state 71'),
(28052, 0, 1, 0, 40, 0, 100, 0, 1, 12012880, 0, 0, 0, 17, 71, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 12012880 - Set emote state 71'),
(28052, 0, 2, 0, 40, 0, 100, 0, 1, 12012960, 0, 0, 0, 17, 71, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 12012960 - Set emote state 71'),
(28052, 0, 3, 0, 40, 0, 100, 0, 1, 12013200, 0, 0, 0, 17, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 12013200 - Set emote state 1'),
(28052, 0, 4, 0, 40, 0, 100, 0, 2, 12013200, 0, 0, 0, 17, 92, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 2 of path 12013200 - Set emote state 92'),
(28052, 0, 5, 0, 40, 0, 100, 0, 3, 12013200, 0, 0, 0, 17, 11, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 3 of path 12013200 - Set emote state 11'),
(28052, 0, 6, 0, 40, 0, 100, 0, 1, 12013600, 0, 0, 0, 17, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 12013600 - Set emote state 1'),
(28052, 0, 7, 0, 40, 0, 100, 0, 2, 12013600, 0, 0, 0, 11, 6668, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 2 of path 12013600 - Cast spell 6668 on self'),
(28052, 0, 8, 0, 40, 0, 100, 0, 3, 12013600, 0, 0, 0, 80, 2805200, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 3 of path 12013600 - Start timed actionlist 2805200'),
(28052, 0, 9, 0, 40, 0, 100, 0, 1, 12013680, 0, 0, 0, 4, 12845, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 12013680 - Play sound 12845'),
(28052, 0, 10, 0, 40, 0, 100, 0, 1, 12013760, 0, 0, 0, 17, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 12013760 - Set emote state 1'),
(28052, 0, 11, 0, 40, 0, 100, 0, 2, 12013760, 0, 0, 0, 17, 92, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 2 of path 12013760 - Set emote state 92'),
(28052, 0, 12, 0, 40, 0, 100, 0, 1, 12014160, 0, 0, 0, 17, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 12014160 - Set emote state 1'),
(28052, 0, 13, 0, 40, 0, 100, 0, 2, 12014160, 0, 0, 0, 17, 92, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 2 of path 12014160 - Set emote state 92'),
(28052, 0, 14, 0, 40, 0, 100, 0, 3, 12014160, 0, 0, 0, 17, 11, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 3 of path 12014160 - Set emote state 11'),
(28052, 0, 15, 0, 40, 0, 100, 0, 3, 12014320, 0, 0, 0, 17, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 3 of path 12014320 - Set emote state 1'),
(28052, 0, 16, 0, 40, 0, 100, 0, 5, 12014320, 0, 0, 0, 11, 11542, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 5 of path 12014320 - Cast spell 11542 on self');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=12012800 AND `point` IN (1);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=12012880 AND `point` IN (1);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=12012960 AND `point` IN (1);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=12013200 AND `point` IN (1,2,3);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=12013600 AND `point` IN (1,2,3);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=12013680 AND `point` IN (1);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=12013760 AND `point` IN (1,2);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=12014160 AND `point` IN (1,2,3);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=12014320 AND `point` IN (3,5);

-- Entry 28058 (Dread Cannon)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=28058 AND `AIName`='';
DELETE FROM `smart_scripts` WHERE `entryorguid`=28058 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (12014480,12014560,12014640);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(28058, 0, 0, 0, 40, 0, 100, 0, 1, 12014480, 0, 0, 0, 11, 50558, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 12014480 - Cast spell 50558 on self'),
(28058, 0, 1, 0, 40, 0, 100, 0, 1, 12014560, 0, 0, 0, 11, 50558, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 12014560 - Cast spell 50558 on self'),
(28058, 0, 2, 0, 40, 0, 100, 0, 1, 12014640, 0, 0, 0, 11, 50558, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 12014640 - Cast spell 50558 on self');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=12014480 AND `point` IN (1);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=12014560 AND `point` IN (1);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=12014640 AND `point` IN (1);

-- Entry 28573 (Underwater Construction Worker)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=28573 AND `AIName`='';
DELETE FROM `smart_scripts` WHERE `entryorguid`=28573 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (6814240);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(28573, 0, 0, 0, 40, 0, 100, 0, 1, 6814240, 0, 0, 0, 17, 233, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 6814240 - Set emote state 233'),
(28573, 0, 1, 0, 40, 0, 100, 0, 6, 6814240, 0, 0, 0, 17, 233, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 6 of path 6814240 - Set emote state 233');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6814240 AND `point` IN (1,6);

-- Entry 28605 (Havenshire Stallion)
DELETE FROM `smart_scripts` WHERE `entryorguid`=28605 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (10337360);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(28605, 0, 0, 0, 40, 0, 100, 0, 15, 10337360, 0, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 15 of path 10337360 - Force despawn (timer 1000)');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10337360 AND `point` IN (15);

-- Entry 28691 (Susana Averoy)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=28691 AND `AIName`='';
DELETE FROM `smart_scripts` WHERE `entryorguid`=28691 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (7834480);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(28691, 0, 0, 0, 40, 0, 100, 0, 12, 7834480, 0, 0, 0, 17, 28, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 12 of path 7834480 - Set emote state 28'),
(28691, 0, 1, 0, 40, 0, 100, 0, 16, 7834480, 0, 0, 0, 17, 28, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 16 of path 7834480 - Set emote state 28');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=7834480 AND `point` IN (12,16);

-- Entry 29016 (Steam Tank Engineer)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=29016 AND `AIName`='';
DELETE FROM `smart_scripts` WHERE `entryorguid`=29016 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (9656400,9656560,9656800,9657120,9657200);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(29016, 0, 0, 0, 40, 0, 100, 0, 3, 9656400, 0, 0, 0, 17, 233, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 3 of path 9656400 - Set emote state 233'),
(29016, 0, 1, 0, 40, 0, 100, 0, 5, 9656400, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 5 of path 9656400 - Set emote state 69'),
(29016, 0, 2, 0, 40, 0, 100, 0, 7, 9656400, 0, 0, 0, 17, 233, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 7 of path 9656400 - Set emote state 233'),
(29016, 0, 3, 0, 40, 0, 100, 0, 9, 9656400, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 9 of path 9656400 - Set emote state 69'),
(29016, 0, 4, 0, 40, 0, 100, 0, 12, 9656400, 0, 0, 0, 17, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 12 of path 9656400 - Set emote state 3'),
(29016, 0, 5, 0, 40, 0, 100, 0, 14, 9656400, 0, 0, 0, 17, 233, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 14 of path 9656400 - Set emote state 233'),
(29016, 0, 6, 0, 40, 0, 100, 0, 16, 9656400, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 16 of path 9656400 - Set emote state 69'),
(29016, 0, 7, 0, 40, 0, 100, 0, 18, 9656400, 0, 0, 0, 17, 233, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 18 of path 9656400 - Set emote state 233'),
(29016, 0, 8, 0, 40, 0, 100, 0, 20, 9656400, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 20 of path 9656400 - Set emote state 69'),
(29016, 0, 9, 0, 40, 0, 100, 0, 22, 9656400, 0, 0, 0, 17, 233, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 22 of path 9656400 - Set emote state 233'),
(29016, 0, 10, 0, 40, 0, 100, 0, 24, 9656400, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 24 of path 9656400 - Set emote state 69'),
(29016, 0, 11, 0, 40, 0, 100, 0, 26, 9656400, 0, 0, 0, 17, 233, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 26 of path 9656400 - Set emote state 233'),
(29016, 0, 12, 0, 40, 0, 100, 0, 28, 9656400, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 28 of path 9656400 - Set emote state 69'),
(29016, 0, 13, 0, 40, 0, 100, 0, 3, 9656560, 0, 0, 0, 17, 233, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 3 of path 9656560 - Set emote state 233'),
(29016, 0, 14, 0, 40, 0, 100, 0, 10, 9656560, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 10 of path 9656560 - Set emote state 69'),
(29016, 0, 15, 0, 40, 0, 100, 0, 17, 9656560, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 17 of path 9656560 - Set emote state 69'),
(29016, 0, 16, 0, 40, 0, 100, 0, 25, 9656560, 0, 0, 0, 17, 233, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 25 of path 9656560 - Set emote state 233'),
(29016, 0, 17, 0, 40, 0, 100, 0, 4, 9656800, 0, 0, 0, 17, 233, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 4 of path 9656800 - Set emote state 233'),
(29016, 0, 18, 0, 40, 0, 100, 0, 11, 9656800, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 11 of path 9656800 - Set emote state 69'),
(29016, 0, 19, 0, 40, 0, 100, 0, 2, 9657120, 0, 0, 0, 17, 233, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 2 of path 9657120 - Set emote state 233'),
(29016, 0, 20, 0, 40, 0, 100, 0, 6, 9657120, 0, 0, 0, 17, 233, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 6 of path 9657120 - Set emote state 233'),
(29016, 0, 21, 0, 40, 0, 100, 0, 12, 9657120, 0, 0, 0, 17, 233, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 12 of path 9657120 - Set emote state 233'),
(29016, 0, 22, 0, 40, 0, 100, 0, 5, 9657200, 0, 0, 0, 17, 233, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 5 of path 9657200 - Set emote state 233'),
(29016, 0, 23, 0, 40, 0, 100, 0, 12, 9657200, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 12 of path 9657200 - Set emote state 69'),
(29016, 0, 24, 0, 40, 0, 100, 0, 16, 9657200, 0, 0, 0, 17, 233, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 16 of path 9657200 - Set emote state 233');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=9656400 AND `point` IN (3,5,7,9,12,14,16,18,20,22,24,26,28);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=9656560 AND `point` IN (3,10,17,25);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=9656800 AND `point` IN (4,11);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=9657120 AND `point` IN (2,6,12);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=9657200 AND `point` IN (5,12,16);

-- Entry 29152 (Stormwind Dock Worker)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=29152 AND `AIName`='';
DELETE FROM `smart_scripts` WHERE `entryorguid`=29152 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (9663760,9663840,9663920);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(29152, 0, 0, 0, 40, 0, 100, 0, 8, 9663760, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 8 of path 9663760 - Set emote state 69'),
(29152, 0, 1, 0, 40, 0, 100, 0, 17, 9663760, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 17 of path 9663760 - Set emote state 69'),
(29152, 0, 2, 0, 40, 0, 100, 0, 5, 9663840, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 5 of path 9663840 - Set emote state 69'),
(29152, 0, 3, 0, 40, 0, 100, 0, 12, 9663840, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 12 of path 9663840 - Set emote state 69'),
(29152, 0, 4, 0, 40, 0, 100, 0, 8, 9663920, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 8 of path 9663920 - Set emote state 69'),
(29152, 0, 5, 0, 40, 0, 100, 0, 17, 9663920, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 17 of path 9663920 - Set emote state 69');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=9663760 AND `point` IN (8,17);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=9663840 AND `point` IN (5,12);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=9663920 AND `point` IN (8,17);

-- Entry 29239 (Vigilant Gargoyle)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=29239 AND `AIName`='';
DELETE FROM `smart_scripts` WHERE `entryorguid`=29239 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (10066080,10066160,10066240,10066480,10066560);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(29239, 0, 0, 0, 40, 0, 100, 0, 1, 10066080, 0, 0, 0, 5, 429, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 10066080 - Play emote 429'),
(29239, 0, 1, 0, 40, 0, 100, 0, 2, 10066080, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 2 of path 10066080 - Play emote 0'),
(29239, 0, 2, 0, 40, 0, 100, 0, 7, 10066080, 0, 0, 0, 5, 429, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 7 of path 10066080 - Play emote 429'),
(29239, 0, 3, 0, 40, 0, 100, 0, 8, 10066080, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 8 of path 10066080 - Play emote 0'),
(29239, 0, 4, 0, 40, 0, 100, 0, 13, 10066080, 0, 0, 0, 5, 429, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 13 of path 10066080 - Play emote 429'),
(29239, 0, 5, 0, 40, 0, 100, 0, 1, 10066160, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 10066160 - Play emote 0'),
(29239, 0, 6, 0, 40, 0, 100, 0, 5, 10066160, 0, 0, 0, 5, 429, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 5 of path 10066160 - Play emote 429'),
(29239, 0, 7, 0, 40, 0, 100, 0, 6, 10066160, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 6 of path 10066160 - Play emote 0'),
(29239, 0, 8, 0, 40, 0, 100, 0, 10, 10066160, 0, 0, 0, 5, 429, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 10 of path 10066160 - Play emote 429'),
(29239, 0, 9, 0, 40, 0, 100, 0, 1, 10066240, 0, 0, 0, 5, 429, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 10066240 - Play emote 429'),
(29239, 0, 10, 0, 40, 0, 100, 0, 2, 10066240, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 2 of path 10066240 - Play emote 0'),
(29239, 0, 11, 0, 40, 0, 100, 0, 6, 10066240, 0, 0, 0, 5, 429, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 6 of path 10066240 - Play emote 429'),
(29239, 0, 12, 0, 40, 0, 100, 0, 7, 10066240, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 7 of path 10066240 - Play emote 0'),
(29239, 0, 13, 0, 40, 0, 100, 0, 1, 10066480, 0, 0, 0, 5, 429, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 10066480 - Play emote 429'),
(29239, 0, 14, 0, 40, 0, 100, 0, 2, 10066480, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 2 of path 10066480 - Play emote 0'),
(29239, 0, 15, 0, 40, 0, 100, 0, 6, 10066480, 0, 0, 0, 5, 429, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 6 of path 10066480 - Play emote 429'),
(29239, 0, 16, 0, 40, 0, 100, 0, 7, 10066480, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 7 of path 10066480 - Play emote 0'),
(29239, 0, 17, 0, 40, 0, 100, 0, 1, 10066560, 0, 0, 0, 5, 429, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 10066560 - Play emote 429'),
(29239, 0, 18, 0, 40, 0, 100, 0, 2, 10066560, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 2 of path 10066560 - Play emote 0'),
(29239, 0, 19, 0, 40, 0, 100, 0, 5, 10066560, 0, 0, 0, 5, 429, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 5 of path 10066560 - Play emote 429'),
(29239, 0, 20, 0, 40, 0, 100, 0, 6, 10066560, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 6 of path 10066560 - Play emote 0');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10066080 AND `point` IN (1,2,7,8,13);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10066160 AND `point` IN (1,5,6,10);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10066240 AND `point` IN (1,2,6,7);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10066480 AND `point` IN (1,2,6,7);
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10066560 AND `point` IN (1,2,5,6);

-- Entry 29288 (Engineer Kurtis Paddock)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=29288 AND `AIName`='';
DELETE FROM `smart_scripts` WHERE `entryorguid`=29288 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (3966400);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(29288, 0, 0, 0, 40, 0, 100, 0, 2, 3966400, 0, 0, 0, 17, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 2 of path 3966400 - Set emote state 1'),
(29288, 0, 1, 0, 40, 0, 100, 0, 4, 3966400, 0, 0, 0, 17, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 4 of path 3966400 - Set emote state 6'),
(29288, 0, 2, 0, 40, 0, 100, 0, 6, 3966400, 0, 0, 0, 17, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 6 of path 3966400 - Set emote state 1'),
(29288, 0, 3, 0, 40, 0, 100, 0, 12, 3966400, 0, 0, 0, 17, 274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 12 of path 3966400 - Set emote state 274');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=3966400 AND `point` IN (2,4,6,12);

-- Entry 29296 (Justin Boehm)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=29296 AND `AIName`='';
DELETE FROM `smart_scripts` WHERE `entryorguid`=29296 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (3971920);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(29296, 0, 0, 0, 40, 0, 100, 0, 8, 3971920, 0, 0, 0, 17, 379, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 8 of path 3971920 - Set emote state 379'),
(29296, 0, 1, 0, 40, 0, 100, 0, 17, 3971920, 0, 0, 0, 17, 379, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 17 of path 3971920 - Set emote state 379');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=3971920 AND `point` IN (8,17);

-- Entry 29297 (Michael Corpora)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=29297 AND `AIName`='';
DELETE FROM `smart_scripts` WHERE `entryorguid`=29297 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (3966720);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(29297, 0, 0, 0, 40, 0, 100, 0, 2, 3966720, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 2 of path 3966720 - Set emote state 69'),
(29297, 0, 1, 0, 40, 0, 100, 0, 8, 3966720, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 8 of path 3966720 - Set emote state 69'),
(29297, 0, 2, 0, 40, 0, 100, 0, 12, 3966720, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 12 of path 3966720 - Set emote state 69'),
(29297, 0, 3, 0, 40, 0, 100, 0, 13, 3966720, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 13 of path 3966720 - Set emote state 69');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=3966720 AND `point` IN (2,8,12,13);

-- Entry 29300 (Robert Richardson)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=29300 AND `AIName`='';
DELETE FROM `smart_scripts` WHERE `entryorguid`=29300 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (3967040);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(29300, 0, 0, 0, 40, 0, 100, 0, 2, 3967040, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 2 of path 3967040 - Set emote state 69'),
(29300, 0, 1, 0, 40, 0, 100, 0, 7, 3967040, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 7 of path 3967040 - Set emote state 69'),
(29300, 0, 2, 0, 40, 0, 100, 0, 14, 3967040, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 14 of path 3967040 - Set emote state 69'),
(29300, 0, 3, 0, 40, 0, 100, 0, 17, 3967040, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 17 of path 3967040 - Set emote state 69');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=3967040 AND `point` IN (2,7,14,17);

-- Entry 29586 (Stormforged Pillager)
DELETE FROM `smart_scripts` WHERE `entryorguid`=2958600 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(2958600, 9, 0, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 6s - Set UNIT_FIELD_BYTES_1 8 (standstate)'),
(2958600, 9, 1, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 0, 90, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 4s - Set UNIT_FIELD_BYTES_1 0 (standstate)');
DELETE FROM `smart_scripts` WHERE `entryorguid`=29586 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (8517360);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(29586, 0, 1, 0, 40, 0, 100, 0, 14, 8517360, 0, 0, 0, 80, 2958600, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 14 of path 8517360 - Start timed actionlist 2958600');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8517360 AND `point` IN (14);

-- Entry 29843 (Stormforged Loreseeker)
DELETE FROM `smart_scripts` WHERE `entryorguid`=2984300 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(2984300, 9, 0, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 6s - Set UNIT_FIELD_BYTES_1 8 (standstate)'),
(2984300, 9, 1, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 0, 90, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 4s - Set UNIT_FIELD_BYTES_1 0 (standstate)');
DELETE FROM `smart_scripts` WHERE `entryorguid`=29843 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (8518400);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(29843, 0, 2, 0, 40, 0, 100, 0, 1, 8518400, 0, 0, 0, 80, 2984300, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 of path 8518400 - Start timed actionlist 2984300'),
(29843, 0, 3, 0, 40, 0, 100, 0, 5, 8518400, 0, 0, 0, 80, 2984300, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 5 of path 8518400 - Start timed actionlist 2984300');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8518400 AND `point` IN (1,5);

-- Entry 36830 (Wrathbone Laborer)
DELETE FROM `smart_scripts` WHERE `entryorguid`=36830 AND `source_type`=0 AND `event_type`=40 AND `event_param2` IN (16144000);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(36830, 0, 4, 0, 40, 0, 100, 0, 2, 16144000, 0, 0, 0, 17, 38, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 2 of path 16144000 - Set emote state 38'),
(36830, 0, 5, 0, 40, 0, 100, 0, 3, 16144000, 0, 0, 0, 17, 38, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 3 of path 16144000 - Set emote state 38'),
(36830, 0, 6, 0, 40, 0, 100, 0, 4, 16144000, 0, 0, 0, 17, 38, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 4 of path 16144000 - Set emote state 38'),
(36830, 0, 7, 0, 40, 0, 100, 0, 5, 16144000, 0, 0, 0, 17, 38, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 5 of path 16144000 - Set emote state 38'),
(36830, 0, 8, 0, 40, 0, 100, 0, 9, 16144000, 0, 0, 0, 17, 38, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 9 of path 16144000 - Set emote state 38'),
(36830, 0, 9, 0, 40, 0, 100, 0, 10, 16144000, 0, 0, 0, 17, 38, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On WP 10 of path 16144000 - Set emote state 38');
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=16144000 AND `point` IN (2,3,4,5,9,10);

-- Waypoint_scripts cleanup
DELETE FROM `waypoint_scripts` WHERE `id` NOT IN (SELECT `action` FROM `waypoint_data` WHERE `action` <> 0);
