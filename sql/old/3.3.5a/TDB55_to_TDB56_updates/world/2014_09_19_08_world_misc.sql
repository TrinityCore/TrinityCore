-- Fixups for Dun Neffelem

-- Pathing for Son of Hodir Entry: 29809
SET @NPC := 106320;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7344.558,`position_y`=-2907.763,`position_z`=823.1275 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7344.558,-2907.763,823.1275,0,0,0,0,100,0),
(@PATH,2,7312.182,-2896.888,823.4388,0,0,0,0,100,0),
(@PATH,3,7272.284,-2896.83,824.0884,0,0,0,0,100,0),
(@PATH,4,7312.182,-2896.888,823.4388,0,0,0,0,100,0),
(@PATH,5,7344.558,-2907.763,823.1275,0,0,0,0,100,0),
(@PATH,6,7377.579,-2916.997,823.7962,0,0,0,0,100,0),
(@PATH,7,7406.458,-2907.756,825.6242,0,0,0,0,100,0),
(@PATH,8,7377.579,-2916.997,823.7962,0,0,0,0,100,0);

-- Pathing for Son of Hodir Entry: 29809
SET @NPC := 106332;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7368.463,`position_y`=-2842.755,`position_z`=800.5325 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7368.463,-2842.755,800.5325,0,0,0,0,100,0),
(@PATH,2,7400.792,-2857.594,800.4119,0,0,0,0,100,0),
(@PATH,3,7445.252,-2857.651,799.9712,0,4000,0,0,100,0),
(@PATH,4,7400.792,-2857.594,800.4119,0,0,0,0,100,0),
(@PATH,5,7368.463,-2842.755,800.5325,0,0,0,0,100,0),
(@PATH,6,7333.749,-2849.251,800.5008,0,0,0,0,100,0),
(@PATH,7,7297.994,-2845.033,792.8625,0,4000,0,0,100,0),
(@PATH,8,7333.461,-2849.232,800.5008,0,0,0,0,100,0);

-- Pathing for Son of Hodir Entry: 29809
SET @NPC := 106334;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7406.458,`position_y`=-2907.756,`position_z`=825.6242 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7406.458,-2907.756,825.6242,0,0,0,0,100,0),
(@PATH,2,7377.579,-2916.997,823.7962,0,0,0,0,100,0),
(@PATH,3,7344.558,-2907.763,823.1275,0,0,0,0,100,0),
(@PATH,4,7312.182,-2896.888,823.4388,0,0,0,0,100,0),
(@PATH,5,7272.284,-2896.83,824.0884,0,0,0,0,100,0),
(@PATH,6,7312.182,-2896.888,823.4388,0,0,0,0,100,0),
(@PATH,7,7344.558,-2907.763,823.1275,0,0,0,0,100,0),
(@PATH,8,7377.579,-2916.997,823.7962,0,0,0,0,100,0);

-- Pathing for Frostworg Entry: 29358
SET @NPC := 112393;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7440.885,`position_y`=-2710.991,`position_z`=808.2947 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7440.885,-2710.991,808.2947,0,0,0,0,100,0),
(@PATH,2,7416.691,-2667.639,809.0078,0,0,0,0,100,0),
(@PATH,3,7440.885,-2710.991,808.2947,0,0,0,0,100,0),
(@PATH,4,7457.135,-2748.122,798.2523,0,0,0,0,100,0),
(@PATH,5,7458.822,-2784.053,787.1277,0,0,0,0,100,0),
(@PATH,6,7457.135,-2748.122,798.2523,0,0,0,0,100,0);

-- Pathing for Frostworg Entry: 29358
SET @NPC := 112514;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7257.337,`position_y`=-2621.496,`position_z`=814.8495 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7257.337,-2621.496,814.8495,0,0,0,0,100,0),
(@PATH,2,7306.544,-2622.633,814.8911,0,0,0,0,100,0),
(@PATH,3,7353.797,-2608.551,814.8893,0,0,0,0,100,0),
(@PATH,4,7306.544,-2622.633,814.8911,0,0,0,0,100,0);

-- Pathing for Frostworg Entry: 29358
SET @NPC := 112392;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7327.009,`position_y`=-2631.48,`position_z`=747.7151 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7327.009,-2631.48,747.7151,0,0,0,0,100,0),
(@PATH,2,7346.908,-2653.571,747.9738,0,0,0,0,100,0),
(@PATH,3,7368.78,-2655.305,748.0898,0,0,0,0,100,0),
(@PATH,4,7368.78,-2655.305,748.0898,4.171337,20000,0,0,100,0),
(@PATH,5,7328.656,-2648.171,747.0898,0,0,0,0,100,0),
(@PATH,6,7317.717,-2612.781,747.0901,0,0,0,0,100,0),
(@PATH,7,7341.498,-2597.444,749.4114,0,0,0,0,100,0),
(@PATH,8,7341.498,-2597.444,749.4114,3.246312,20000,0,0,100,0);

-- Pathing for Frostworg Entry: 29358
SET @NPC := 112515;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7253.167,`position_y`=-2730.059,`position_z`=747.0898 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7253.167,-2730.059,747.0898,0,0,0,0,100,0),
(@PATH,2,7235.487,-2711.358,748.4982,0,0,0,0,100,0),
(@PATH,3,7202.864,-2711.527,762.0225,0,0,0,0,100,0),
(@PATH,4,7177.577,-2716.251,773.6584,0,0,0,0,100,0),
(@PATH,5,7170.178,-2744.835,776.9741,0,0,0,0,100,0),
(@PATH,6,7200.037,-2774.302,776.9871,0,0,0,0,100,0),
(@PATH,7,7232.467,-2806.691,777.7,0,0,0,0,100,0),
(@PATH,8,7274.858,-2803.938,776.7856,0,0,0,0,100,0),
(@PATH,9,7296.991,-2780.158,776.1025,0,0,0,0,100,0),
(@PATH,10,7298.799,-2748.659,775.0818,0,0,0,0,100,0),
(@PATH,11,7304.38,-2728.39,746.965,0,0,0,0,100,0),
(@PATH,12,7264.486,-2745.654,748.08,0,0,0,0,100,0),
(@PATH,13,7261.873,-2751.083,748.8501,0,0,0,0,100,0),
(@PATH,14,7261.873,-2751.083,748.8501,1.570796,15000,0,0,100,0);

-- Captive Proto Drake Beam Bunny SAI
SET @ENTRY := 29805;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,11,55244,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captive Proto Drake Beam Bunny - OCC - Cast 'Proto Drake Chain Channel'");

-- Add spell target condition for Proto Drake Chain Channel
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (55244);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 55244, 0, 1, 31, 3, 30442, 0, 0, '', 'Proto Drake Chain Channel targets Phase 1 Generic Bunny');

DELETE FROM `creature` WHERE `id`=29805;
DELETE FROM `creature` WHERE `guid` IN (97557,97558,97560,97561,97562,97563,97564);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(97557,29708,571,1,1,7152.347,-2669.387,849.6174,5.760307,120,0,0), -- Captive Proto-Drake
(97558,29708,571,1,1,7227.964,-2659.802,866.7960,2.988974,120,0,0), -- Captive Proto-Drake
(97560,29708,571,1,1,7242.648,-2660.197,899.8528,5.542587,120,0,0), -- Captive Proto-Drake
(97561,29708,571,1,1,7277.569,-2735.515,872.2152,5.635166,120,0,0), -- Captive Proto-Drake
(97562,29708,571,1,1,7339.314,-2827.775,886.0789,2.190141,120,0,0), -- Captive Proto-Drake
(97563,29708,571,1,1,7353.549,-2895.788,896.9881,1.938608,120,0,0), -- Captive Proto-Drake
(97564,29708,571,1,1,7388.962,-2785.868,869.0148,3.480815,120,0,0); -- Captive Proto-Drake

DELETE FROM `vehicle_template_accessory` WHERE `entry`=29708;
INSERT INTO `vehicle_template_accessory` (`entry`,`accessory_entry`,`seat_id`,`minion`,`description`,`summontype`,`summontimer`) VALUES
(29708,29805,0,0, 'Captive Proto-Drake',8,0);
