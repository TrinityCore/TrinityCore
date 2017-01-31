-- Issue 9250
-- A Worthy Weapon (thx Durotar)
UPDATE `creature_template` SET `InhabitType`=4, `hoverheight`=1065353216, `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=33273;
-- Set visual effect: sitting
DELETE FROM `creature_template_addon` WHERE `entry`=33273;
INSERT INTO `creature_template_addon` (`entry`,`bytes1`,`bytes2`,`emote`) VALUES (33273,1,1,0);
-- Winter Hyacinth (item 45000) Send Script Event (20990) by right-click
DELETE FROM `event_scripts` WHERE `id`=20990;
INSERT INTO `event_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `x`, `y`, `z`, `o`) VALUES
(20990, 0, 10, 33273, 42000, 4602.977, -1600.141, 156.7834, 0.7504916);
-- TEMP Drak'Mar Offering Ring
SET @ObjectGuid := 547; -- 4.x
DELETE FROM `gameobject` WHERE `id`=300009;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(@ObjectGuid+0,300009,571,1,1, 4606.72, -1606.91, 156.659, 1.62734,0.0,0.0, 0.726811, 0.686837,300,0,1),
(@ObjectGuid+1,300009,571,1,1, 4596.78, -1606.69, 156.659, 1.5488,0.0,0.0, 0.699286, 0.714842,300,0,1),
(@ObjectGuid+2,300009,571,1,1, 4597.1, -1594.08, 156.658, 1.53702,0.0,0.0, 0.695063, 0.718949,300,0,1),
(@ObjectGuid+3,300009,571,1,1, 4608.33, -1592.98, 156.658, 0.162569,0.0,0.0, 0.0811951, 0.996698,300,0,1),
(@ObjectGuid+4,300009,571,1,1, 4602.78, -1600.05, 156.658, 4.08564,0.0,0.0, 0.890651, -0.454688,300,0,1);
-- creature_text
DELETE FROM `creature_text` WHERE `entry`=33273 AND `groupid` BETWEEN 0 AND 3;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(33273,0,0, 'Are those winter hyacinths? For me?',12,0,100,6,0,0, 'Maiden of Drak''Mar'),
(33273,1,0, 'It''s been so long since a traveler has come here bearing flowers.',12,0,100,1,0,0, 'Maiden of Drak''Mar'),
(33273,2,0, 'The lake has been too lonely these past years. The travelers stopped coming and evil came to these waters.',12,0,100,1,0,0, 'Maiden of Drak''Mar'),
(33273,3,0, 'Your gift is a rare kindness, traveler. Please take this blade with my gratitude. Long ago, another traveler left it here, but I have little use for it.',12,0,100,1,0,0, 'Maiden of Drak''Mar');
-- SAI
DELETE FROM `smart_scripts` WHERE `entryorguid`=33273 AND `source_type`=0 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=33273*100 AND `source_type`=9 AND `id` BETWEEN 0 AND 6;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(33273,0,0,0,54,0,100,0,0,0,0,0,80,33273*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Maiden of DrakMar - On spawn - Run script'),
(33273*100,9,0,0,0,0,100,0,0,0,0,0,50,194239,42000,0,0,0,0,8,0,0,0,4602.977,-1600.141,156.7834,0, 'Maiden of DrakMar - On script - Summon GO DrakMar Lily Pad'),
(33273*100,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Maiden of DrakMar - On script - Say 0'),
(33273*100,9,2,0,0,0,100,0,5000,5000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Maiden of DrakMar - On script - Say 1'),
(33273*100,9,3,0,0,0,100,0,6000,6000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Maiden of DrakMar - On script - Say 2'),
(33273*100,9,4,0,0,0,100,0,7000,7000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Maiden of DrakMar - On script - Say 3'),
(33273*100,9,5,0,0,0,100,0,0,0,0,0,50,194238,20000,0,0,0,0,8,0,0,0,4603.351,-1599.288,156.8822,2.234018, 'Maiden of DrakMar - On script - Summon GO Blade of DrakMar');
