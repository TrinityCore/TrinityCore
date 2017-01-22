-- Bailey + Bellinger Event
UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE  `guid` IN (114937, 114958);
DELETE FROM `creature_formations` WHERE `leaderGUID`=114937;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(114937, 114937, 0, 0, 4, 0, 0),
(114937, 114958, 2, 270, 4, 0, 0);

-- Bailey SAI
SET @ENTRY := 29643;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,900000,900000,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bailey - Out of Combat - Run Script"),
(@ENTRY,0,1,0,40,0,100,0,4,29643,0,0,80,@ENTRY*100+01,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bailey - On Waypoint 4 Reached - Run Script"),
(@ENTRY,0,2,0,40,0,100,0,8,29643,0,0,80,@ENTRY*100+02,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bailey - On Waypoint 8 Reached - Run Script"),
(@ENTRY,0,3,0,40,0,100,0,15,29643,0,0,80,@ENTRY*100+03,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bailey - On Waypoint 15 Reached - Run Script");

-- Actionlist SAI
SET @ENTRY := 2964300;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,1,0,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Bailey - On Script - Say Line 0"),
(@ENTRY,9,1,0,0,0,100,0,6000,6000,0,0,1,0,6000,0,0,0,0,10,114958,29644,0,0,0,0,0,"Bailey - On Script - Say Line 0"),
(@ENTRY,9,2,0,0,0,100,0,6000,6000,0,0,1,1,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Bailey - On Script - Say Line 1"),
(@ENTRY,9,3,0,0,0,100,0,6000,6000,0,0,1,1,6000,0,0,0,0,10,114958,29644,0,0,0,0,0,"Bailey - On Script - Say Line 1"),
(@ENTRY,9,4,0,0,0,100,0,6000,6000,0,0,1,2,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Bailey - On Script - Say Line 2"),
(@ENTRY,9,5,0,0,0,100,0,6000,6000,0,0,1,2,0,0,0,0,0,10,114958,29644,0,0,0,0,0,"Bailey - On Script - Say Line 2"),
(@ENTRY,9,6,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,10,114958,29644,0,0,0,0,0,"Bailey - On Script - Set Orientation Closest Creature 'Bellinger'"),
(@ENTRY,9,7,0,0,0,100,0,6000,6000,0,0,1,3,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Bailey - On Script - Say Line 3"),
(@ENTRY,9,8,0,0,0,100,0,3000,3000,0,0,5,60,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bailey - On Script - Play Emote 60"),
(@ENTRY,9,9,0,0,0,100,0,0,0,0,0,86,54899,0,10,114958,29644,0,1,0,0,0,0,0,0,0,"Bailey - On Script - Cross Cast 'Knockback 15'"),
(@ENTRY,9,10,0,0,0,100,0,5000,5000,0,0,1,3,5000,0,0,0,0,10,114958,29644,0,0,0,0,0,"Bailey - On Script - Say Line 3"),
(@ENTRY,9,11,0,0,0,100,0,0,0,0,0,45,4,4,0,0,0,0,10,114958,29644,0,0,0,0,0,"Bailey - On Script - Set Data 4 4"),
(@ENTRY,9,12,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.58825,"Bailey - On Script - Set Orientation 1.58825"),
(@ENTRY,9,13,0,0,0,100,0,3000,3000,0,0,1,4,3000,0,0,0,0,10,114958,29644,0,0,0,0,0,"Bailey - On Script - Say Line 4"),
(@ENTRY,9,14,0,0,0,100,0,5000,5000,0,0,45,1,1,0,0,0,0,10,114958,29644,0,0,0,0,0,"Bailey - On Script - Set Data 1 1"),
(@ENTRY,9,15,0,0,0,100,0,300000,300000,0,0,1,5,6000,0,0,0,0,10,114958,29644,0,0,0,0,0,"Bailey - On Script - Say Line 5"), -- 5min
(@ENTRY,9,16,0,0,0,100,0,6000,6000,0,0,1,4,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Bailey - On Script - Say Line 4"),
(@ENTRY,9,17,0,0,0,100,0,6000,6000,0,0,1,6,6000,0,0,0,0,10,114958,29644,0,0,0,0,0,"Bailey - On Script - Say Line 6"),
(@ENTRY,9,18,0,0,0,100,0,6000,6000,0,0,1,7,6000,0,0,0,0,10,114958,29644,0,0,0,0,0,"Bailey - On Script - Say Line 7"),
(@ENTRY,9,19,0,0,0,100,0,6000,6000,0,0,1,8,6000,0,0,0,0,10,114958,29644,0,0,0,0,0,"Bailey - On Script - Say Line 8"),
(@ENTRY,9,20,0,0,0,100,0,6000,6000,0,0,1,5,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Bailey - On Script - Say Line 5"),
(@ENTRY,9,21,0,0,0,100,0,6000,6000,0,0,1,6,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Bailey - On Script - Say Line 6"),
(@ENTRY,9,22,0,0,0,100,0,300000,300000,0,0,53,0,29643,0,0,0,1,1,0,0,0,0,0,0,0,"Bailey - On Script - Start Waypoint"); -- 5min 300000

-- Actionlist SAI
SET @ENTRY := 2964301;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,13000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bailey - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.085985,"Bailey - On Script - Set Orientation 2,085985"),
(@ENTRY,9,2,0,0,0,100,0,1000,1000,0,0,45,2,2,0,0,0,0,10,114958,29644,0,0,0,0,0,"Bailey - On Script - Set Data 2 2"),
(@ENTRY,9,3,0,0,0,100,0,1000,1000,0,0,1,7,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Bailey - On Script - Say Line 7"),
(@ENTRY,9,4,0,0,0,100,0,6000,6000,0,0,1,9,5000,0,0,0,0,10,114958,29644,0,0,0,0,0,"Bailey - On Script - Say Line 9");

-- Actionlist SAI
SET @ENTRY := 2964302;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,33000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bailey - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.50084,"Bailey - On Script - Set Orientation 2.50084"),
(@ENTRY,9,2,0,0,0,100,0,1000,1000,0,0,45,3,3,0,0,0,0,10,114958,29644,0,0,0,0,0,"Bailey - On Script - Set Data 3 3"),
(@ENTRY,9,3,0,0,0,100,0,3000,3000,0,0,1,8,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Bailey - On Script - Say Line 8"),
(@ENTRY,9,4,0,0,0,100,0,6000,6000,0,0,1,10,6000,0,0,0,0,10,114958,29644,0,0,0,0,0,"Bailey - On Script - Say Line 10"),
(@ENTRY,9,5,0,0,0,100,0,6000,6000,0,0,1,9,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Bailey - On Script - Say Line 9"),
(@ENTRY,9,6,0,0,0,100,0,6000,6000,0,0,1,11,6000,0,0,0,0,10,114958,29644,0,0,0,0,0,"Bailey - On Script - Say Line 11"),
(@ENTRY,9,7,0,0,0,100,0,6000,6000,0,0,1,10,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Bailey - On Script - Say Line 10");

-- Actionlist SAI
SET @ENTRY := 2964303;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,4000,4000,0,0,45,5,5,0,0,0,0,10,114958,29644,0,0,0,0,0,"Bailey - On Script - Set Data 5 5"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,48,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bailey - On Script - Set Active Off");

-- Bellinger SAI
SET @ENTRY := 29644;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,38,0,100,0,1,1,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.50098,"Bellinger - On Data Set 1 1 - Set Orientation 1.50098"),
(@ENTRY,0,1,0,38,0,100,0,2,2,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.08598,"Bellinger - On Data Set 2 2 - Set Orientation 2.08598"),
(@ENTRY,0,2,0,38,0,100,0,3,3,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.50084,"Bellinger - On Data Set 3 3 - Set Orientation 2.50084"),
(@ENTRY,0,3,0,38,0,100,0,4,4,0,0,69,0,0,0,0,0,0,8,0,0,0,6034.820,-750.8344,369.8008,1.4146,"Bellinger - On Data Set 4 4 - Move To Position"),
(@ENTRY,0,4,0,38,0,100,0,5,5,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.269333,"Bellinger - On Data Set 3 3 - Set Orientation 1.269333");

DELETE FROM `creature_text` WHERE `entry` IN (29643, 29644);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
-- Bailey
(29643, 0, 0, 'This doesn''t look pretty, lad.', 12, 0, 100, 1, 0, 0, 30286, 'Bailey'),
(29643, 1, 0, 'That right? Well why don''t you go prance your merry little self over and grab them, eh?', 12, 0, 100, 6, 0, 0, 30289, 'Bailey'),
(29643, 2, 0, 'That''s strange... for a moment there, I could have swore you called me short.', 12, 0, 100, 1, 0, 0, 30288, 'Bailey'),
(29643, 3, 0, 'Toss me?! Okay, that''s it punk.', 12, 0, 100, 5, 0, 0, 30290, 'Bailey'),
(29643, 4, 0, 'Keep it to yourself.', 12, 0, 100, 1, 0, 0, 30291, 'Bailey'),
(29643, 5, 0, 'You better hope they don''t survive it, lad.', 12, 0, 100, 1, 0, 0, 30292, 'Bailey'),
(29643, 6, 0, 'Cause I''m just going to watch and laugh as they toss you in.', 12, 0, 100, 1, 0, 0, 30293, 'Bailey'),
(29643, 7, 0, 'There''s got to be a way in somewhere.', 12, 0, 100, 1, 0, 0, 30294, 'Bailey'),
(29643, 8, 0, 'How''d the goblin leave his tools there then?', 12, 0, 100, 1, 0, 0, 30295, 'Bailey'),
(29643, 9, 0, 'That''s it, lad! It looks totally safe. Go for it, I''ll be right behind ya!', 12, 0, 100, 5, 0, 0, 30296, 'Bailey'),
(29643, 10, 0, 'Pansy.', 12, 0, 100, 5, 0, 0, 30312, 'Bailey'),
-- Bellinger
(29644, 0, 0, 'I don''t know, Bailey... it''s not so bad. We could throw a rock at the tools from here.', 12, 0, 100, 1, 0, 0, 30287, 'Bellinger'),
(29644, 1, 0, 'Well... I was just thinking... you''re a bit smaller, so you''re less likely to set off any of those mines.', 12, 0, 100, 1, 0, 0, 30297, 'Bellinger'),
(29644, 2, 0, 'No, no, no! Not short... it''s just... well... maybe I could toss you across most of it?', 12, 0, 100, 1, 0, 0, 30298, 'Bellinger'),
(29644, 3, 0, 'Ahhh!', 12, 0, 100, 0, 0, 0, 30306, 'Bellinger'),
(29644, 4, 0, 'That was close! You scared me.', 12, 0, 100, 5, 0, 0, 30311, 'Bellinger'),
(29644, 5, 0, 'I''ve got an idea, Bailey...', 12, 0, 100, 5, 0, 0, 30299, 'Bellinger'),
(29644, 6, 0, 'No, no - this might work!', 12, 0, 100, 5, 0, 0, 30300, 'Bellinger'),
(29644, 7, 0, 'There''s a path right there... only a few mines at the end in between us and the tools.', 12, 0, 100, 1, 0, 0, 30301, 'Bellinger'),
(29644, 8, 0, 'We wait for the next adventurer to come through and we tell him that''s the way to go... then after they set off the mines, we just walk in and grab the tools!', 12, 0, 100, 1, 0, 0, 30302, 'Bellinger'),
(29644, 9, 0, 'It really doesn''t look like it, Bailey.', 12, 0, 100, 1, 0, 0, 30303, 'Bellinger'),
(29644, 10, 0, 'Oh... good point. How about right there? That looks clear... kind of.', 12, 0, 100, 1, 0, 0, 30304, 'Bellinger'),
(29644, 11, 0, 'Uh... that''s okay. It still kind of hurts from last time.', 12, 0, 100, 1, 0, 0, 30305, 'Bellinger');

DELETE FROM `waypoints` WHERE `entry`=29643;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(29643, 1, 6043.27, -752.358, 371.289, 'Bailey'),
(29643, 2, 6057.13, -750.684, 374.297, 'Bailey'),
(29643, 3, 6075.11, -746.512, 378.785, 'Bailey'),
(29643, 4, 6074.88, -746.098, 378.744, 'Bailey'),
(29643, 5, 6082.66, -744.527, 380.612, 'Bailey'),
(29643, 6, 6094.52, -739.821, 383.156, 'Bailey'),
(29643, 7, 6108.06, -728.91, 385.165, 'Bailey'),
(29643, 8, 6106.12, -727.415, 384.716, 'Bailey'),
(29643, 9, 6103.38, -731.758, 384.439, 'Bailey'),
(29643, 10, 6094.78, -740.08, 383.232, 'Bailey'),
(29643, 11, 6081.35, -743.988, 380.304, 'Bailey'),
(29643, 12, 6064.46, -748.543, 376.139, 'Bailey'),
(29643, 13, 6047.42, -752.5, 372.131, 'Bailey'),
(29643, 14, 6036.15, -753.071, 369.981, 'Bailey'),
(29643, 15, 6036.69, -751.232, 370.083, 'Bailey');
