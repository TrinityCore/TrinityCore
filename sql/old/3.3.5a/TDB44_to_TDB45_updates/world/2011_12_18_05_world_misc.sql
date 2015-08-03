-- Quest: The Black Knight's Orders (13663) SQL fix
-- Black Knights Camp Spawns
SET @OGUID=100489; -- Need 10
SET @CGUID=152277; -- Need 3
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+9;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(@OGUID+0,194357,571,1,1,9070.324,2050.733,67.21755,0,0,0,0,1,0,0,0), -- Poison Vial
(@OGUID+1,194357,571,1,1,9073.764,2050.120,68.15718,0,0,0,0,1,0,0,0), -- Poison Vial
(@OGUID+2,194357,571,1,1,9074.699,2050.709,68.17049,0,0,0,0,1,0,0,0), -- Poison Vial
(@OGUID+3,194357,571,1,1,9069.595,2050.349,67.21755,0,0,0,0,1,0,0,0), -- Poison Vial
(@OGUID+4,194357,571,1,1,9069.961,2050.538,67.21755,0,0,0,0,1,0,0,0), -- Poison Vial
(@OGUID+5,194357,571,1,1,9072.077,2049.292,67.78963,0,0,0,0,1,0,0,0), -- Poison Vial
(@OGUID+6,194357,571,1,1,9065.680,2052.618,67.28638,0,0,0,0,1,0,0,0), -- Poison Vial
(@OGUID+7,194394,571,1,1,9083.578,2041.696,67.81812,0,0,0,0,1,0,0,0), -- Cult Rune Circle
(@OGUID+8,195011,571,1,1,9078.471,2057.547,67.21606,0,0,0,0.9981346,0.06105176,0,0,0), -- Bonfire
(@OGUID+9,300007,571,1,1,8523.51,566.994,552.841,2.1518,0,0,0.880019,0.474938,300,0,1); -- Spell Focus GO?

DELETE FROM `creature` WHERE `id`=33537;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(@CGUID+0,33537,571,1,1,0,0,9071.043,2075.388,67.21542,4.935980,120,0,0,1,0,0,0,0,0),
(@CGUID+1,33537,571,1,1,0,0,9074.414,2049.259,67.34636,2.181662,120,0,0,1,0,0,0,0,0),
(@CGUID+2,33537,571,1,1,0,0,9081.280,2058.925,67.38979,3.612832,120,0,0,1,0,0,0,0,0);

-- Template updates
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|8,`speed_run`=4, `InhabitType`=5 WHERE `entry`=33519; -- Black Knight''s Gryphon
UPDATE `creature_template` SET `faction_A`=2080,`faction_H`=2080,`unit_flags`=`unit_flags`|32768,`equipment_id`=823 WHERE `entry`=33537; -- Cult Conspirator

-- See black knight's invisibility while on quest The Black Knight's Orders
DELETE FROM `spell_area` WHERE `spell`=67471 AND `area` IN (4658);
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_start_active`,`quest_end`,`aura_spell`,`racemask`,`gender`,`autocast`) VALUES
(67471,4658,13663,1,13663,0,0,2,1); -- See Black Knight Invis

-- Addon data
DELETE FROM `creature_template_addon` WHERE `entry` IN (33519,33537);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(33519,0,0,2049,0,NULL),-- Black Knight''s Gryphon
(33537,0,1,1,0,NULL); -- Cult Conspirator

-- SAI for Black Knight''s Gryphon
SET @entry :=33519;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@entry;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@entry;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@entry,0,0,0,27,0,100,0,0,0,0,0,53,0,@entry,0,13663,0,0,1,0,0,0,0,0,0,0,'Black Knight''s Gryphon - On passenger - Start WP movement'),
(@entry,0,1,0,40,0,100,0,40,@entry,0,0,33,33519,0,0,0,0,0,7,0,0,0,0,0,0,0,'Black Knight''s Gryphon - On WP 40 - Quest Credit'),
(@entry,0,2,0,40,0,100,0,43,@entry,0,0,11,50630,0,0,0,0,0,7,0,0,0,0,0,0,0,'Black Knight''s Gryphon - On WP 43 - Dismount Spell'),
(@entry,0,3,0,40,0,100,0,44,@entry,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Black Knight''s Gryphon - On WP 44 - Despawn');

DELETE FROM `waypoints` WHERE `entry`=33519;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(33519, 1,8521.271,569.5960,552.8375,'Black Knight''s Gryphon'),
(33519, 2,8517.864,579.1095,553.2125,'Black Knight''s Gryphon'),
(33519, 3,8513.146,594.6724,551.2125,'Black Knight''s Gryphon'),
(33519, 4,8505.263,606.5569,550.4177,'Black Knight''s Gryphon'),
(33519, 5,8503.017,628.4188,547.4177,'Black Knight''s Gryphon'),
(33519, 6,8480.271,652.7083,547.4177,'Black Knight''s Gryphon'),
(33519, 7,8459.121,686.1427,547.4177,'Black Knight''s Gryphon'),
(33519, 8,8436.802,713.8687,547.3428,'Black Knight''s Gryphon'),
(33519, 9,8405.380,740.0045,547.4177,'Black Knight''s Gryphon'),
(33519,10,8386.139,770.6009,547.5881,'Black Knight''s Gryphon'),
(33519,11,8374.297,802.2525,547.9304,'Black Knight''s Gryphon'),
(33519,12,8374.271,847.0363,548.0427,'Black Knight''s Gryphon'),
(33519,13,8385.988,868.9881,548.0491,'Black Knight''s Gryphon'),
(33519,14,8413.027,867.8573,547.2991,'Black Knight''s Gryphon'),
(33519,15,8452.552,869.0339,547.2991,'Black Knight''s Gryphon'),
(33519,16,8473.058,875.2012,547.2955,'Black Knight''s Gryphon'),
(33519,17,8472.278,912.3134,547.4169,'Black Knight''s Gryphon'),
(33519,18,8479.666,954.1650,547.3298,'Black Knight''s Gryphon'),
(33519,19,8477.349,1001.368,547.3372,'Black Knight''s Gryphon'),
(33519,20,8484.538,1025.797,547.4622,'Black Knight''s Gryphon'),
(33519,21,8525.363,1029.284,547.4177,'Black Knight''s Gryphon'),
(33519,22,8532.808,1052.904,548.1677,'Black Knight''s Gryphon'),
(33519,23,8537.356,1077.927,554.5791,'Black Knight''s Gryphon'),
(33519,24,8540.528,1083.379,569.6827,'Black Knight''s Gryphon'),
(33519,25,8563.641,1140.965,569.6827,'Black Knight''s Gryphon'),
(33519,26,8594.897,1205.458,569.6827,'Black Knight''s Gryphon'),
(33519,27,8617.104,1257.399,566.1833,'Black Knight''s Gryphon'),
(33519,28,8648.496,1329.349,558.0187,'Black Knight''s Gryphon'),
(33519,29,8667.723,1388.411,546.1880,'Black Knight''s Gryphon'),
(33519,30,8699.145,1474.898,528.2197,'Black Knight''s Gryphon'),
(33519,31,8726.869,1546.006,501.7741,'Black Knight''s Gryphon'),
(33519,32,8739.058,1592.157,478.5511,'Black Knight''s Gryphon'),
(33519,33,8750.799,1636.771,455.0797,'Black Knight''s Gryphon'),
(33519,34,8760.006,1669.482,423.2208,'Black Knight''s Gryphon'),
(33519,35,8783.310,1701.852,375.8872,'Black Knight''s Gryphon'),
(33519,36,8817.336,1735.731,343.3323,'Black Knight''s Gryphon'),
(33519,37,8882.320,1789.754,301.5807,'Black Knight''s Gryphon'),
(33519,38,8958.597,1841.807,259.9141,'Black Knight''s Gryphon'),
(33519,39,9045.891,1908.076,233.4143,'Black Knight''s Gryphon'),
(33519,40,9107.177,1964.594,215.9704,'Black Knight''s Gryphon'),
(33519,41,9134.763,2036.925,175.1925,'Black Knight''s Gryphon'),
(33519,42,9128.608,2089.091,141.3593,'Black Knight''s Gryphon'),
(33519,43,9093.364,2128.384,99.38685,'Black Knight''s Gryphon'),
(33519,44,9050.709,2123.656,60.24802,'Black Knight''s Gryphon');
