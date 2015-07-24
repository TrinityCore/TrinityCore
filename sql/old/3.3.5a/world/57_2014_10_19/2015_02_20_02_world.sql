-- 
-- Keritose Bloodblade SAI
SET @ENTRY := 30946;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,62,0,100,0,10110,0,0,0,85,58698,0,0,0,0,0,7,0,0,0,0,0,0,0,"Keritose Bloodblade - On Gossip Option 0 Selected - Invoker Cast 'Possessed Skeletal Assault Gryphon'");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceID`=15 AND `SourceEntry`=0 AND `SourceGroup`=10110;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ConditionTypeOrReference`,`elseGroup`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`Comment`) VALUES
(15,10110,0,9,0,13172,0,0,0,'show gossip on quest 13172 taken');

-- Restless Lookout SAI
SET @ENTRY := 30951;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,0,45254,0,0,0,33,30951,0,0,0,0,0,21,50,0,0,0,0,0,0,"Restless Lookout - On Spellhit 'Suicide' - Quest Credit 'Honor is for the Weak'"),
(@ENTRY,0,2,0,8,0,100,0,59234,0,0,0,33,31555,0,0,0,0,0,7,0,0,0,0,0,0,0,"Restless Lookout - On Spellhit 'Firebomb' - Quest Credit 'Seeds of Chaos'");

-- Risen Laborer SAI
SET @ENTRY := 30949;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,0,59234,0,0,0,33,31555,0,0,0,0,0,7,0,0,0,0,0,0,0,"Risen Laborer - On Spellhit 'Firebomb' - Quest Credit 'Seeds of Chaos'");

/* gryphon */
DELETE FROM `creature_template_addon` WHERE `entry`=31157;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(31157, 0, 0, 33554432, 0, 0, '55971');
UPDATE `creature_template` SET `InhabitType`=4, `spell1`= 59234 WHERE `entry`=31157;

-- Skeletal Assault Gryphon SAI
SET @ENTRY := 31157;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,53,1,31157,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Assault Gryphon - On Just Summoned - Start Waypoint"),
(@ENTRY,0,1,2,40,0,100,0,35,31157,0,0,11,50630,2,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Assault Gryphon - On Waypoint 35 Reached - Cast 'Eject All Passengers'"),
(@ENTRY,0,2,0,61,0,100,0,36,31157,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Assault Gryphon - On Waypoint 36 Reached - Despawn In 1000 ms");

DELETE FROM `waypoints` WHERE `entry`=31157;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(31157, 1, 8397.621, 2683.953, 657.3679, 'Skeletal Assault Gryphon'),
(31157, 2, 8370.314, 2727.218, 664.7281, 'Skeletal Assault Gryphon'),
(31157, 3, 8335.474, 2760.751, 670.5891, 'Skeletal Assault Gryphon'),
(31157, 4, 8289.219, 2785.704, 674.7277, 'Skeletal Assault Gryphon'),
(31157, 5, 8212.881, 2826.851, 661.2293, 'Skeletal Assault Gryphon'),
(31157, 6, 8070.518, 2879.992, 614.7838, 'Skeletal Assault Gryphon'),
(31157, 7, 7950.946, 2893.043, 570.5617, 'Skeletal Assault Gryphon'),
(31157, 8, 7859.049, 2925.734, 547.0621, 'Skeletal Assault Gryphon'),
(31157, 9, 7804.694, 2973.792, 558.8955, 'Skeletal Assault Gryphon'),
(31157, 10, 7725.221, 3051.099, 570.2289, 'Skeletal Assault Gryphon'),
(31157, 11, 7658.346, 3084.103, 576.8101, 'Skeletal Assault Gryphon'),
(31157, 12, 7591.941, 3146.263, 587.5597, 'Skeletal Assault Gryphon'),
(31157, 13, 7576.145, 3203.526, 598.5592, 'Skeletal Assault Gryphon'),
(31157, 14, 7622.536, 3240.809, 611.8931, 'Skeletal Assault Gryphon'),
(31157, 15, 7703.133, 3210.107, 613.2822, 'Skeletal Assault Gryphon'),
(31157, 16, 7796.588, 3149.966, 615.9203, 'Skeletal Assault Gryphon'),
(31157, 17, 7889.656, 3088.229, 614.7259, 'Skeletal Assault Gryphon'),
(31157, 18, 7983.687, 3018.498, 597.3369, 'Skeletal Assault Gryphon'),
(31157, 19, 8053.703, 2943.441, 588.1163, 'Skeletal Assault Gryphon'),
(31157, 20, 8076.742, 2864.08, 582.1427, 'Skeletal Assault Gryphon'),
(31157, 21, 8005.022, 2790.798, 556.4193, 'Skeletal Assault Gryphon'),
(31157, 22, 7897.278, 2831.605, 550.6705, 'Skeletal Assault Gryphon'),
(31157, 23, 7847.702, 2963.348, 561.8926, 'Skeletal Assault Gryphon'),
(31157, 24, 7792.906, 3089.349, 590.8646, 'Skeletal Assault Gryphon'),
(31157, 25, 7735.124, 3173.07, 604.7814, 'Skeletal Assault Gryphon'),
(31157, 26, 7620.355, 3179.519, 599.2814, 'Skeletal Assault Gryphon'),
(31157, 27, 7590.6, 3106.805, 591.0317, 'Skeletal Assault Gryphon'),
(31157, 28, 7650.019, 3055.191, 581.8378, 'Skeletal Assault Gryphon'),
(31157, 29, 7734.892, 3021.323, 573.1149, 'Skeletal Assault Gryphon'),
(31157, 30, 7862.496, 2979.27, 572.5039, 'Skeletal Assault Gryphon'),
(31157, 31, 7956.528, 2972.131, 575.9482, 'Skeletal Assault Gryphon'),
(31157, 32, 8039.022, 2947.35, 576.0869, 'Skeletal Assault Gryphon'),
(31157, 33, 8155.893, 2883.776, 606.1532, 'Skeletal Assault Gryphon'),
(31157, 34, 8239.198, 2805.797, 654.0699, 'Skeletal Assault Gryphon'),
(31157, 35, 8290.536, 2766.505, 682.2192, 'Skeletal Assault Gryphon'),
(31157, 36, 8353.981, 2708.914, 714.5253, 'Skeletal Assault Gryphon');
