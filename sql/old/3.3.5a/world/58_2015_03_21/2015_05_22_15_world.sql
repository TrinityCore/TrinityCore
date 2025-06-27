-- Quest 11343 "The Echo of Ymiron"

SET @OGUID := 5603; -- One required
SET @CGUID := 48229; -- 16 required 
SET @NPC := @CGUID+5;
SET @PATH := @NPC * 10;

-- Object Spawn from sniff
DELETE FROM `gameobject` WHERE `id`=186664;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID,186664,571,1,2,1073.001,-5033.952,9.771218,1.518436,0,0,0.6883545,0.7253745,300,0,1); -- Baby in Crib

-- Creature Spawns from sniff
DELETE FROM `creature` WHERE `id` IN (24314,24315,24248,24327,23935);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES 
(@CGUID+0,24314,571,1,2,0,0,1073.562,-5029.705,9.805857,4.660029,300,0,0,5158,0,0,0,0,0), -- Ancient Male Vrykul
(@CGUID+1,24315,571,1,2,0,0,1074.889,-5033.892,9.711858,3.036873,300,0,0,5158,0,0,0,0,0), -- Ancient Female Vrykul
(@CGUID+2,24248,571,1,2,0,0,1054.514,-4918.391,10.14754,3.263766,300,0,0,1,0,0,0,0,0),    -- The Lich King
(@CGUID+3,24327,571,1,2,0,0,1055.667,-4924.913,16.54569,3.281219,300,0,0,1,0,0,0,0,0),    -- Val'kyr Soulclaimer
(@CGUID+4,24327,571,1,2,0,0,1054.277,-4909.997,16.50003,3.263766,300,0,0,1,0,0,0,0,0),    -- Val'kyr Soulclaimer
(@CGUID+5,23935,571,1,2,0,0,927.0462,-4925.752,4.78267,0.1288379,300,0,0,1,0,2,0,0,0),    -- Val'kyr Watcher
(@CGUID+6,23935,571,1,2,0,0,1036.007,-4926.114,12.45767,5.548763,300,0,0,1,0,2,0,0,0),    -- Val'kyr Watcher
(@CGUID+7,23935,571,1,2,0,0,1026.868,-4944.088,12.0571,0.7522717,300,0,0,1,0,2,0,0,0),    -- Val'kyr Watcher
(@CGUID+8,23935,571,1,2,0,0,1028.676,-5012.598,13.78496,0.2954222,300,0,0,1,0,2,0,0,0),   -- Val'kyr Watcher
(@CGUID+9,23935,571,1,2,0,0,910.7372,-4961.667,33.09615,0.2954222,300,0,0,1,0,2,0,0,0),   -- Val'kyr Watcher
(@CGUID+10,23935,571,1,2,0,0,934.7177,-4890.745,34.57682,0.2954222,300,0,0,1,0,2,0,0,0),  -- Val'kyr Watcher
(@CGUID+11,23935,571,1,2,0,0,970.6052,-4993.673,29.27757,0.2954222,300,0,0,1,0,2,0,0,0),  -- Val'kyr Watcher
(@CGUID+12,23935,571,1,2,0,0,1006.246,-4868.183,47.70948,0.2954222,300,0,0,1,0,2,0,0,0),  -- Val'kyr Watcher
(@CGUID+13,23935,571,1,2,0,0,1046.627,-4824.385,47.09693,0.2954222,300,0,0,1,0,2,0,0,0),  -- Val'kyr Watcher
(@CGUID+14,23935,571,1,2,0,0,1068.264,-4965.238,47.55685,0.2954222,300,0,0,1,0,2,0,0,0),  -- Val'kyr Watcher
(@CGUID+15,23935,571,1,2,0,0,1037.688,-4934.398,31.88609,0.2954222,300,0,0,1,0,2,0,0,0);  -- Val'kyr Watcher

DELETE FROM `creature_template_addon` WHERE `entry` IN (24315,24248,24327);
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(24315,0,0,1,0,0, ''),
(24248,0,0,0,1,0, '41408'),
(24327,0,0,33554432,0 ,0, '');

UPDATE `creature_template` SET `AIName`='SmartAI', `unit_flags`=768 WHERE `entry` IN (24314, 24315, 24327);
UPDATE `creature_template` SET `unit_flags`=164352, `AIName`='SmartAI' WHERE `entry`=24248;  -- 131072
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry` IN (24327, 23935);

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (24314,24315, 24327, 24248);
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid` IN (2431400,2431500,2431501, 2424800, 2424801);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES  
(24314,0,0,0,10,0,100,0,0,15,50000,50000,80,2431400,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Male Vrykul - OOC_LOS - Start Script'),
(2431400,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Anchient Male Speach 1'),
(2431400,9,1,0,0,0,100,0,2000,2000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Anchient Male Speach 2'),
(2431400,9,2,0,0,0,100,0,3000,3000,0,0,1,0,0,0,0,0,0,10,@CGUID+1,24315,0,0,0,0,0, 'Anchient Female Speach 1'),
(2431400,9,3,0,0,0,100,0,3000,3000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Anchient Male Speach 2'),
(2431400,9,4,0,0,0,100,0,3000,3000,0,0,5,25,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Anchient Male emote ONESHOT_POINT'),
(2431400,9,5,0,0,0,100,0,6000,6000,0,0,45,0,1,0,0,0,0,10,@CGUID+1,24315,0,0,0,0,0, 'Anchient Female start path'),
(2431400,9,6,0,0,0,100,0,5000,5000,0,0,1,1,0,0,0,0,0,10,@CGUID+1,24315,0,0,0,0,0, 'Anchient Female Speach 2'), -- check timing
(2431400,9,7,0,0,0,100,0,4000,4000,0,0,5,18,0,0,0,0,0,10,@CGUID+1,24315,0,0,0,0,0, 'Anchient Female emote ONESHOT_CRY'),
(2431400,9,8,0,0,0,100,0,4000,4000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Anchient Male Speach 3'),
(2431400,9,9,0,0,0,100,0,6000,6000,0,0,1,2,0,0,0,0,0,10,@CGUID+1,24315,0,0,0,0,0, 'Anchient Female Speach 2'),
(2431400,9,10,0,0,0,100,0,3000,3000,0,0,11,43458,2,0,0,0,0,7,0,0,0,0,0,0,0, 'Quest Credit'),
(2431400,9,11,0,0,0,100,0,3000,3000,0,0,45,0,2,0,0,0,0,10,@CGUID+1,24315,0,0,0,0,0, 'Anchient Female resume path'),
(24315,0,0,0,11,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Female Vrykul - Set Passive'),
(24315,0,1,0,38,0,100,0,0,1,0,0,80,2431500,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Female Vrykul - On data set 0 1 run script'),
(24315,0,2,0,38,0,100,0,0,2,0,0,80,2431501,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Female Vrykul - On data set 0 2 run script'),
(24315,0,3,4,40,0,100,0,1,24315,0,0,54,40000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Female Vrykul - Pause at wp talk'),
(24315,0,4,5,61,0,100,0,0,0,0,0,66,0,0,0,0,0,0,9,24315,0,15,0,0,0,0, 'Ancient Female Vrykul - turn to Ancient Male Vrykul'),
(24315,0,5,0,61,0,100,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Female Vrykul - kneel'),
(24315,0,6,7,40,0,100,0,2,24315,0,0,55,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Female Vrykul - Stop at wp home'),
(24315,0,7,8,61,0,100,0,0,0,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Female Vrykul - turn to pos'),
(24315,0,8,0,61,0,100,0,0,0,0,0,90,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Female Vrykul - kneel'),
(2431500,9,0,0,0,0,100,0,0,0,0,0,91,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Female Vrykul - stand'),
(2431500,9,1,0,0,0,100,0,0,0,0,0,53,0,24315,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Female Vrykul - wp start'),
(2431501,9,0,0,0,0,100,0,0,0,0,0,65,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Female Vrykul - wp resume'),
(2431501,9,1,0,0,0,100,0,0,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Female Vrykul - stand'),
(24327,0,0,0,11,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Male Vrykul - Set Passive'),

(24248,0,0,0,10,0,100,0,0,15,3000,3000,80,2424800,2,0,0,0,0,1,0,0,0,0,0,0,0, 'The Lich King - OOC_LOS - Start Script'),
(2424800,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'The Lich King - Action list - Talk0'),
(2424800,9,1,0,0,0,100,0,0,0,0,0,11,29661,0,0,0,0,0,7,0,0,0,0,0,0,0, 'The Lich King - Action list - Cast Magnetic Pull'),
(2424800,9,2,0,0,0,100,0,1000,1000,0,0,11,43489,0,0,0,0,0,7,0,0,0,0,0,0,0, 'The Lich King - Action list - Cast Grasp of the Lich King'),
(2424800,9,3,0,0,0,100,0,1000,1000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'The Lich King - Action list - Talk1'),
(2424800,9,4,0,0,0,100,0,3000,3000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'The Lich King - Action list - Talk2'),
(2424800,9,5,0,0,0,100,0,15000,15000,0,0,1,0,0,0,0,0,0,19,24327,10,0,0,0,0,0, 'The Lich King - Action list - Talk0'),
(2424800,9,6,0,0,0,100,0,3000,3000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'The Lich King - Action list - Talk3'),
(2424800,9,7,0,0,0,100,0,7000,7000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0, 'The Lich King - Action list - Talk4'),
(2424800,9,8,0,0,0,100,0,19000,19000,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0, 'The Lich King - Action list - Talk5'),
(2424800,9,9,0,0,0,100,0,20000,20000,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0, 'The Lich King - Action list - Talk6'),
(2424800,9,10,0,0,0,100,0,17000,17000,0,0,11,43488,64,0,0,0,0,7,0,0,0,0,0,0,0, 'The Lich King - Action list - Cast'),
(2424800,9,11,0,0,0,100,0,500,500,0,0,51,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'The Lich King - Action list - kill'),

(24248,0,1,0,10,0,100,0,0,15,3000,3000,80,2424801,2,0,0,0,0,1,0,0,0,0,0,0,0, 'The Lich King - OOC_LOS - Start Script'),
(2424801,9,0,0,0,0,100,0,0,0,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0, 'The Lich King - Action list - Talk7'),
(2424801,9,1,0,0,0,100,0,0,0,0,0,11,29661,0,0,0,0,0,7,0,0,0,0,0,0,0, 'The Lich King - Action list - Cast Magnetic Pull'),
(2424801,9,2,0,0,0,100,0,1000,1000,0,0,11,43489,0,0,0,0,0,7,0,0,0,0,0,0,0, 'The Lich King - Action list - Cast Grasp of the Lich King'),
(2424801,9,3,0,0,0,100,0,8000,8000,0,0,11,50156,0,0,0,0,0,7,0,0,0,0,0,0,0, 'The Lich King - Action list - Cast'),
(2424801,9,4,0,0,0,100,0,500,500,0,0,51,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'The Lich King - Action list - kill');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup` IN (1,2) AND `SourceEntry` IN (24248, 24314);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`, `ErrorTextId`,`ScriptName`,`Comment`, `NegativeCondition`) VALUES
(22,1,24248,0,8,12485,0,0,0,'','event require quest 12485 not rewarded', 1),
(22,2,24248,0,8,12485,0,0,0,'','event require quest 12485 rewarded', 0),
(22,1,24314,0,9,11343,0,0,0,'','event require quest 11344 Taken', 0);

DELETE FROM `disables` WHERE `sourceType` = 1 AND `entry` = 12485;

-- NPC Text from sniff
DELETE FROM `creature_text` WHERE `entry` IN (24314,24315, 24248, 24327);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES 
(24314,0,0, 'So then we too are cursed?',12,0,100,1,0,0, 'Ancient Male Vrykul',23116),
(24314,1,0, '%s points to the infant.',16,0,100,0,0,0, 'Ancient Male Vrykul',23117),
(24315,0,0, '%s sobs.',16,0,100,0,0,0, 'Ancient Female Vrykul',23118),
(24314,2,0, 'The gods have forsaken us! We must dispose of it before Ymiron is notified!',12,0,100,53,0,0, 'Ancient Male Vrykul',23119),
(24315,1,0, 'NO! You cannot! I beg of you! It is our child!',12,0,100,0,0,0, 'Ancient Female Vrykul',23120),
(24314,3,0, 'Then what are we to do, wife? The others cannot find out. Should they learn of this aberration, we will all be executed.',12,0,100,1,0,0, 'Ancient Male Vrykul',23121),
(24315,2,0, 'I... I will hide it. I will hide it until I find it a home, far away from here...',12,0,100,0,0,0, 'Ancient Female Vrykul',23122),
(24248,0,0, '%s turns to face you.',16,0,100,0,0,0, 'The Lich King',23102),
(24248,1,0, '%s grins. ',16,0,100,11,0,14820, 'The Lich King',23146),
(24248,2,0, 'Shamanism has brought you here... Its scent permeates the air. *The Lich King laughs* I was once a shaman.',12,0,100,0,0,14742, 'The Lich King',23147),
(24327,0,0, 'Shall we prepare it for you, my lord?',12,0,100,0,0,0, 'Val''kyr Soulclaimer',23152),
(24248,3,0, 'No, minion. This one is not ready.',12,0,100,274,0,14743, 'The Lich King',23148), 
(24248,4,0, 'Do you feel it, mortal? Death seeps through me, enveloping all that I touch. With just a snap of my finger your soul will languish in damnation for all eternity.',12,0,100,1,0,14744, 'The Lich King',23149),
(24248,5,0, 'But... It is not yet your time to serve the Lich King. Yes, a greater destiny awaits you. Power... You must become more powerful before you are to serve me.',12,0,100,1,0,14745, 'The Lich King',23150),
(24248,6,0, 'Now watch, val''kyr. Observe as I apply pressure. Can you see that it is not yet ripe? Watch as it pops and falls lifeless to the floor.',12,0,100,1,0,14746, 'The Lich King',23151),
(24248,7,0, 'Persistence or stupidity? It matters not. Let this be a lesson learned, mortal!',12,0,100,1,0,14747, 'The Lich King',27351);

-- Waypoints for Ancient Female Vrykul from sniff
DELETE FROM `waypoints` WHERE `entry`=24315;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(24315,1,1074.016,-5031.822,9.726947,'talk point'),
(24315,2,1074.889,-5033.892,9.711858,'home point');

-- Pathing for Val'kyr Watcher Entry: 23935
DELETE FROM `creature_addon` WHERE `guid` IN (@NPC,@NPC+1,@NPC+2,@NPC+3,@NPC+4,@NPC+5,@NPC+6,@NPC+7,@NPC+8,@NPC+9,@NPC+10);
INSERT INTO `creature_addon` (`guid`,`path_id`) VALUES 
(@NPC,@PATH),
(@NPC+1,@PATH+10),
(@NPC+2,@PATH+20),
(@NPC+3,@PATH+30),
(@NPC+4,@PATH+40),
(@NPC+5,@PATH+50),
(@NPC+6,@PATH+60),
(@NPC+7,@PATH+70),
(@NPC+8,@PATH+80),
(@NPC+9,@PATH+90),
(@NPC+10,@PATH+100);

DELETE FROM `waypoint_data` WHERE `id` IN (@PATH,@PATH+10,@PATH+20,@PATH+30,@PATH+40,@PATH+50,@PATH+60,@PATH+70,@PATH+80,@PATH+90,@PATH+100);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,946.877,-4950.67,8.72458,0,0,0,100,0),
(@PATH,2,927.046,-4925.75,8.09321,0,0,0,100,0),
(@PATH,3,929.734,-4899.67,9.95518,0,0,0,100,0),
(@PATH,4,939.552,-4878.05,10.4938,0,0,0,100,0),
(@PATH,5,929.734,-4899.67,9.95518,0,0,0,100,0),
(@PATH,6,927.046,-4925.75,8.09321,0,0,0,100,0),
(@PATH+10,1,1036.835,-4931.16,12.83267,0,0,0,100,0),
(@PATH+10,2,1036.007,-4926.114,12.45767,0,0,0,100,0),
(@PATH+10,3,1023.932,-4912.754,10.5369,0,0,0,100,0),
(@PATH+10,4,1000.253,-4901.448,7.911896,0,0,0,100,0),
(@PATH+10,5,1023.932,-4912.754,10.5369,0,0,0,100,0),
(@PATH+10,6,1036.007,-4926.114,12.45767,0,0,0,100,0),
(@PATH+20,1,1026.697,-4942.586,11.8071,0,0,0,100,0),
(@PATH+20,2,1030.085,-4970.878,12.77823,0,0,0,100,0),
(@PATH+20,3,1034.023,-4972.842,13.0493,0,0,0,100,0),
(@PATH+20,4,1030.085,-4970.878,12.77823,0,0,0,100,0),
(@PATH+20,5,1026.868,-4944.088,12.0571,0,0,0,100,0),
(@PATH+30,1,1045.199,-5071.371,13.72586,0,0,0,100,0),
(@PATH+30,2,1069.113,-5069.303,13.34213,0,0,0,100,0),
(@PATH+30,3,1091.871,-5063.042,13.38427,0,0,0,100,0),
(@PATH+30,4,1103.122,-5055.239,13.92861,0,0,0,100,0),
(@PATH+30,5,1099.777,-5030.915,13.25463,0,0,0,100,0),
(@PATH+30,6,1088.535,-5001.179,13.00463,0,0,0,100,0),
(@PATH+30,7,1062.886,-4976.348,13.6743,0,0,0,100,0),
(@PATH+30,8,1044.221,-4979.022,13.7993,0,0,0,100,0),
(@PATH+30,9,1030.879,-4997.25,13.52823,0,0,0,100,0),
(@PATH+30,10,1028.676,-5012.598,13.78496,0,0,0,100,0),
(@PATH+30,11,1034.265,-5039.136,13.73875,0,0,0,100,0),
(@PATH+40,1,919.0841,-4946.079,33.09615,0,0,0,100,0),
(@PATH+40,2,937.5836,-4953.232,30.76281,0,0,0,100,0),
(@PATH+40,3,936.755,-4970.46,30.76281,0,0,0,100,0),
(@PATH+40,4,929.6907,-4992.461,30.76281,0,0,0,100,0),
(@PATH+40,5,919.143,-5002.606,30.76281,0,0,0,100,0),
(@PATH+40,6,899.7684,-4997.275,30.76281,0,0,0,100,0),
(@PATH+40,7,894.8842,-4973.352,31.20726,0,0,0,100,0),
(@PATH+40,8,910.7372,-4961.667,33.09615,0,0,0,100,0),
(@PATH+50,1,955.5239,-4883.864,28.91015,0,0,0,100,0),
(@PATH+50,2,975.0622,-4876.539,34.57682,0,0,0,100,0),
(@PATH+50,3,998.4828,-4882.556,34.57682,0,0,0,100,0),
(@PATH+50,4,1007.136,-4897.439,34.57682,0,0,0,100,0),
(@PATH+50,5,999.5431,-4915.003,34.57682,0,0,0,100,0),
(@PATH+50,6,977.8502,-4931.425,34.57682,0,0,0,100,0),
(@PATH+50,7,955.9329,-4951.924,34.57682,0,0,0,100,0),
(@PATH+50,8,932.5357,-4941.676,34.57682,0,0,0,100,0),
(@PATH+50,9,928.3145,-4926.969,35.49352,0,0,0,100,0),
(@PATH+50,10,934.7177,-4890.745,34.57682,0,0,0,100,0),
(@PATH+60,1,985.4891,-4985.466,29.27757,0,0,0,100,0),
(@PATH+60,2,1003.236,-5007.198,29.27757,0,0,0,100,0),
(@PATH+60,3,1001.194,-5018.937,29.27757,0,0,0,100,0),
(@PATH+60,4,983.9544,-5038.578,29.27757,0,0,0,100,0),
(@PATH+60,5,965.2218,-5035.844,29.27757,0,0,0,100,0),
(@PATH+60,6,955.2875,-5023.462,29.27757,0,0,0,100,0),
(@PATH+60,7,964.6006,-5006.362,29.27757,0,0,0,100,0),
(@PATH+60,8,970.6052,-4993.673,29.27757,0,0,0,100,0),
(@PATH+70,1,997.6531,-4837.691,50.98726,0,0,0,100,0),
(@PATH+70,2,978.2066,-4826.199,50.98726,0,0,0,100,0),
(@PATH+70,3,954.6121,-4846.288,50.98726,0,0,0,100,0),
(@PATH+70,4,915.1261,-4847.07,50.98726,0,0,0,100,0),
(@PATH+70,5,906.7595,-4877.092,50.98726,0,0,0,100,0),
(@PATH+70,6,911.5735,-4919.276,50.98726,0,0,0,100,0),
(@PATH+70,7,942.1261,-4946.08,42.51503,0,0,0,100,0),
(@PATH+70,8,978.0408,-4936.854,40.5428,0,0,0,100,0),
(@PATH+70,9,1002.55,-4900.139,38.45948,0,0,0,100,0),
(@PATH+70,10,1006.246,-4868.183,47.70948,0,0,0,100,0),
(@PATH+80,1,1022.976,-4810.128,38.31916,0,0,0,100,0),
(@PATH+80,2,996.8618,-4813.854,38.31916,0,0,0,100,0),
(@PATH+80,3,964.6756,-4838.639,38.31916,0,0,0,100,0),
(@PATH+80,4,940.3589,-4846.21,38.31916,0,0,0,100,0),
(@PATH+80,5,907.9418,-4846.479,34.20804,0,0,0,100,0),
(@PATH+80,6,887.7231,-4873.045,34.59694,0,0,0,100,0),
(@PATH+80,7,891.8184,-4898.238,30.04136,0,0,0,100,0),
(@PATH+80,8,912.4337,-4902.996,30.04136,0,0,0,100,0),
(@PATH+80,9,939.5068,-4887.826,30.04136,0,0,0,100,0),
(@PATH+80,10,961.7159,-4869.482,30.04136,0,0,0,100,0),
(@PATH+80,11,1005.307,-4881.67,30.04136,0,0,0,100,0),
(@PATH+80,12,1029.752,-4892.972,31.93025,0,0,0,100,0),
(@PATH+80,13,1067.775,-4894.65,39.06914,0,0,0,100,0),
(@PATH+80,14,1059.698,-4864.968,47.09693,0,0,0,100,0),
(@PATH+80,15,1060.522,-4845.491,47.09693,0,0,0,100,0),
(@PATH+80,16,1046.627,-4824.385,47.09693,0,0,0,100,0),
(@PATH+90,1,1044.91,-4980.383,47.55685,0,0,0,100,0),
(@PATH+90,2,1040.873,-5016.178,52.69574,0,0,0,100,0),
(@PATH+90,3,1054.767,-5042.476,52.69574,0,0,0,100,0),
(@PATH+90,4,1084.064,-5042.998,39.22352,0,0,0,100,0),
(@PATH+90,5,1106.236,-5031.327,39.22352,0,0,0,100,0),
(@PATH+90,6,1106.77,-4995.738,45.02908,0,0,0,100,0),
(@PATH+90,7,1086.711,-4972.376,47.55685,0,0,0,100,0),
(@PATH+90,8,1068.264,-4965.238,47.55685,0,0,0,100,0),
(@PATH+100,1,1066.911,-4940.557,48.88609,0,0,0,100,0),
(@PATH+100,2,1069.896,-4920.431,40.85831,0,0,0,100,0),
(@PATH+100,3,1057.342,-4903.877,40.85831,0,0,0,100,0),
(@PATH+100,4,1044.138,-4900.038,31.74721,0,0,0,100,0),
(@PATH+100,5,1023.748,-4899.741,28.21942,0,0,0,100,0),
(@PATH+100,6,1017.973,-4921.141,28.21942,0,0,0,100,0),
(@PATH+100,7,1037.688,-4934.398,31.88609,0,0,0,100,0);
