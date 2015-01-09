-- The Last Line Of Defense (13086)
SET @NEXT := 4091; -- 4.x changed
SET @PATH := @NEXT * 10;

DELETE FROM `spell_script_names` WHERE `spell_id` IN (57412,57385);
INSERT INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES
(57412,'spell_q13086_cannons_target'),
(57385,'spell_q13086_cannons_target');

-- Forgotten Depths Slayer SAI ID: 30593
UPDATE `creature_template` SET `speed_walk`=5,`movementtype`=1,`faction_A`=2068, `faction_H`=2068,`AIName`= 'SmartAI' WHERE `entry`= 30593;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=30593;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(30593,0,1,0,0,0,100,0,1000,5000,2500,6500,11,54185,0,0,0,0,0,2,0,0,0,0,0,0,0,'Combat - Claw Slash');

-- Adds 70 Forgotten Depths Slayers for phase 64 ID: 30593
DELETE FROM `creature` WHERE `id`=30593;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `MovementType`) VALUES
(@NEXT+1, 30593, 571, 1, 64, 6442.551758, 222.894867, 397.353943, 2.7317, 5, 60, 0, 1), 
(@NEXT+2, 30593, 571, 1, 64, 6437.940430, 215.351151, 397.798889, 0.929563, 5, 60, 0, 1), 
(@NEXT+3, 30593, 571, 1, 64, 6419.338379, 239.908859, 396.095978, 2.1122, 5, 60, 0, 1), 
(@NEXT+4, 30593, 571, 1, 64, 6428.831055, 239.908859, 396.763702, 3.5549, 5, 60, 0, 1), 
(@NEXT+5, 30593, 571, 1, 64, 6400.702148, 236.755035, 395.685333, 1.32629, 5, 60, 0, 1),
(@NEXT+6, 30593, 571, 1, 64, 6410.955078, 249.759094, 396.454742, 2.77181, 5, 60, 0, 1),
(@NEXT+7, 30593, 571, 1, 64, 6367.340820, 183.807068, 391.614655, 0.501217, 5, 60, 0, 1),
(@NEXT+8, 30593, 571, 1, 64, 6382.062500, 176.836975, 393.132507, 1.22528, 5, 60, 0, 1), 
(@NEXT+9, 30593, 571, 1, 64, 6357.964355, 158.979782, 391.124756, 2.99677, 5, 60, 0, 1),
(@NEXT+10, 30593, 571, 1, 64, 6373.327537, 146.681412, 392.788330, 3.35221, 5, 60, 0, 1),
(@NEXT+11, 30593, 571, 1, 64, 6343.335938, 173.300323, 389.862518, 4.18409, 5, 60, 0, 1),
(@NEXT+12, 30593, 571, 1, 64, 6335.788086, 148.828232, 389.702972, 3.19711, 5, 60, 0, 1),
(@NEXT+13, 30593, 571, 1, 64, 6347.954590, 129.882919, 3391.126984, 2.81552, 5, 60, 0, 1),
(@NEXT+14, 30593, 571, 1, 64, 6333.287109, 88.245689, 391.002228, 5.84132, 5, 60, 0, 1),
(@NEXT+15, 30593, 571, 1, 64, 6336.879395, 71.525627, 390.192871, 0.785398, 5, 60, 0, 1),
(@NEXT+16, 30593, 571, 1, 64, 6318.244629, 32.249405, 391.493988, 2.1325, 5, 60, 0, 1),
(@NEXT+17, 30593, 571, 1, 64, 6312.728320, 8.393217, 392.626587, 0.291176, 5, 60, 0, 1),
(@NEXT+18, 30593, 571, 1, 64, 6326.704590, 107.359123, 391.002045, 0.919091, 5, 60, 0, 1),
(@NEXT+19, 30593, 571, 1, 64, 6301.972656, 119.744209, 389.925903, 1.55615, 5, 60, 0, 1),
(@NEXT+20, 30593, 571, 1, 64, 6266.120117, 148.388809, 383.515961, 1.84373, 5, 60, 0, 1),
(@NEXT+21, 30593, 571, 1, 64, 6251.726074, 153.168182, 381.629669, 1.80125, 5, 60, 0, 1),
(@NEXT+22, 30593, 571, 1, 64, 6229.003418, 145.614822, 379.721741, 5.84095, 5, 60, 0, 1),
(@NEXT+23, 30593, 571, 1, 64, 6284.683082, 214.294250, 388.699188, 2.78648, 5, 60, 0, 1),
(@NEXT+24, 30593, 571, 1, 64, 6302.265625, 212.301346, 390.488556, 3.48219, 5, 60, 0, 1),
(@NEXT+25, 30593, 571, 1, 64, 6299.725098, 226.082626, 391.288788, 5.13205, 5, 60, 0, 1),
(@NEXT+26, 30593, 571, 1, 64, 6200.917969,  220.434753, 383.776184, 2.88047, 5, 60, 0, 1),
(@NEXT+27, 30593, 571, 1, 64, 6200.930664, 234.127823, 384.630798, 1.50529, 5, 60, 0, 1),
(@NEXT+28, 30593, 571, 1, 64, 6190.595703, 225.242371, 382.554016, 4.4761, 5, 60, 0, 1),
(@NEXT+29, 30593, 571, 1, 64, 6189.209961, 210.502823, 381.877960, 2.11574, 5, 60, 0, 1),
(@NEXT+30, 30593, 571, 1, 64, 6176.683594, 213.375336, 380.395172, 0.763302, 5, 60, 0, 1),
(@NEXT+31, 30593, 571, 1, 64, 6113.089844, 156.401672, 369.398804, 5.60417, 5, 60, 0, 1),
(@NEXT+32, 30593, 571, 1, 64, 6103.571289, 140.684174, 367.524414, 0.430917, 5, 60, 0, 1),
(@NEXT+33, 30593, 571, 1, 64, 6093.838867, 143.838867, 367.781097, 6.10437, 5, 60, 0, 1),
(@NEXT+34, 30593, 571, 1, 64, 6090.764160, 141.764160, 365.786255, 5.91518, 5, 60, 0, 1),
(@NEXT+35, 30593, 571, 1, 64, 6079.681641, 141.840958, 366.456573, 5.91108, 5, 60, 0, 1),
(@NEXT+36, 30593, 571, 1, 64, 6062.076660, 155.683197, 363.868896, 2.05191, 5, 60, 0, 1),
(@NEXT+37, 30593, 571, 1, 64, 6076.666016, 163.742477, 362.454651, 3.57468, 5, 60, 0, 1),
(@NEXT+38, 30593, 571, 1, 64, 6088.131348, 179.086304, 360.483307, 5.6035, 5, 60, 0, 1),
(@NEXT+39, 30593, 571, 1, 64, 6098.503418, 176.307312, 364.942688, 5.6035, 5, 60, 0, 1),
(@NEXT+40, 30593, 571, 1, 64, 6090.764160, 155.876968, 365.786255, 5.6035, 5, 60, 0, 1),
(@NEXT+41, 30593, 571, 1, 64, 6338.830566, 70.974663, 390.432343, 5.6035, 5, 60, 0, 1),
(@NEXT+42, 30593, 571, 1, 64, 6339.270508, 63.711479, 389.662994, 5.6035, 5, 60, 0, 1),
(@NEXT+43, 30593, 571, 1, 64, 6282.305176, 128.449188, 386.556244, 5.6035, 5, 60, 0, 1),
(@NEXT+44, 30593, 571, 1, 64, 6267.317383, 130.918854, 384.601959, 5.6035, 5, 60, 0, 1),
(@NEXT+45, 30593, 571, 1, 64, 6182.309082, 94.777863, 377.689959, 5.6035, 5, 60, 0, 1),
(@NEXT+46, 30593, 571, 1, 64, 6157.960383, 89.072354, 371.833959, 5.6035, 5, 60, 0, 1),
(@NEXT+47, 30593, 571, 1, 64, 6236.617383, 113.980854, 380.351959, 5.6035, 5, 60, 0, 1),
(@NEXT+48, 30593, 571, 1, 64, 6295.647383, 137.418854, 387.451959, 5.6035, 5, 60, 0, 1),
(@NEXT+49, 30593, 571, 1, 64, 6200.917969,  220.434753, 383.776184, 2.88047, 5, 60, 0, 1),
(@NEXT+50, 30593, 571, 1, 64, 6200.930664, 234.127823, 384.630798, 1.50529, 5, 60, 0, 1),
(@NEXT+51, 30593, 571, 1, 64, 6190.595703, 225.242371, 382.554016, 4.4761, 5, 60, 0, 1),
(@NEXT+52, 30593, 571, 1, 64, 6189.209961, 210.502823, 381.877960, 2.11574, 5, 60, 0, 1),
(@NEXT+53, 30593, 571, 1, 64, 6176.683594, 213.375336, 380.395172, 0.763302, 5, 60, 0, 1),
(@NEXT+54, 30593, 571, 1, 64, 6113.089844, 156.401672, 369.398804, 5.60417, 5, 60, 0, 1),
(@NEXT+55, 30593, 571, 1, 64, 6103.571289, 140.684174, 367.524414, 0.430917, 5, 60, 0, 1),
(@NEXT+56, 30593, 571, 1, 64, 6093.838867, 143.838867, 367.781097, 6.10437, 5, 60, 0, 1),
(@NEXT+57, 30593, 571, 1, 64, 6090.764160, 141.764160, 365.786255, 5.91518, 5, 60, 0, 1),
(@NEXT+58, 30593, 571, 1, 64, 6079.681641, 141.840958, 366.456573, 5.91108, 5, 60, 0, 1),
(@NEXT+59, 30593, 571, 1, 64, 6062.076660, 155.683197, 363.868896, 2.05191, 5, 60, 0, 1),
(@NEXT+60, 30593, 571, 1, 64, 6076.666016, 163.742477, 362.454651, 3.57468, 5, 60, 0, 1),
(@NEXT+61, 30593, 571, 1, 64, 6088.131348, 179.086304, 360.483307, 5.6035, 5, 60, 0, 1),
(@NEXT+62, 30593, 571, 1, 64, 6098.503418, 176.307312, 364.942688, 5.6035, 5, 60, 0, 1),
(@NEXT+63, 30593, 571, 1, 64, 6090.764160, 155.876968, 365.786255, 5.6035, 5, 60, 0, 1),
(@NEXT+64, 30593, 571, 1, 64, 6338.830566, 70.974663, 390.432343, 5.6035, 5, 60, 0, 1),
(@NEXT+65, 30593, 571, 1, 64, 6339.270508, 63.711479, 389.662994, 5.6035, 5, 60, 0, 1),
(@NEXT+66, 30593, 571, 1, 64, 6282.305176, 128.449188, 386.556244, 5.6035, 5, 60, 0, 1),
(@NEXT+67, 30593, 571, 1, 64, 6267.317383, 130.918854, 384.601959, 5.6035, 5, 60, 0, 1),
(@NEXT+68, 30593, 571, 1, 64, 6182.309082, 94.777863, 377.689959, 5.6035, 5, 60, 0, 1),
(@NEXT+69, 30593, 571, 1, 64, 6157.960383, 89.072354, 371.833959, 5.6035, 5, 60, 0, 1),
(@NEXT+70, 30593, 571, 1, 64, 6236.617383, 113.980854, 380.351959, 5.6035, 5, 60, 0, 1);

-- Frostbrood Destroyers 5
UPDATE `creature_template` SET `maxlevel`=80,`minlevel`=80,`exp`=2,`InhabitType`=7,`speed_walk`=3,`mindmg` = 1170,`dmg_multiplier` = 2,`attackpower` = 342,`maxdmg` = 3470,`movementtype`=1,`faction_A`=2068, `faction_H`=2068 WHERE `entry`= 30575;
DELETE FROM `creature` WHERE `id`=30575;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@NEXT+71, 30575,571,1,64,6097.870117, 58.331299, 380.506012, 0.138359, 75,20,1),
(@NEXT+72, 30575,571,1,64,6243.700195, 183.362000, 392.515015, 4.594332, 75,20,1),
(@NEXT+73, 30575,571,1,64,6313.589844, 154.557999, 397.022003, 4.739780, 75,20,1),
(@NEXT+74, 30575,571,1,64,6331.450195, 53.939301, 399.138000, 2.973792, 75,20,1),
(@NEXT+75, 30575,571,1,64,6187.290039, 131.792999, 386.451996, 3.173792, 75,20,1);

-- Hover mode for Frostbroods
DELETE FROM `creature_template_addon` WHERE `entry`=30575;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(30575,0,0,33554432,0,0,'');

-- Pathing
-- Slayers reinforcements left on main path
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NEXT+1;
DELETE FROM `creature_addon` WHERE `guid`=@NEXT+1;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES 
(@NEXT+1,@PATH+1,1,0, '');

DELETE FROM `waypoint_data` WHERE `id`=@PATH+1;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH+1,1,6442.551758, 222.894867, 397.353943,0,2,0,100,0),
(@PATH+1,2,6337.383789,113.591568,391.210876,6000,2,0,100,0),
(@PATH+1,3,6299.144531,126.174286,391.081909,6000,2,0,100,0);

UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NEXT+2;
DELETE FROM `creature_addon` WHERE `guid`=@NEXT+2;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES 
(@NEXT+2,@PATH+2,1,0, '');

DELETE FROM `waypoint_data` WHERE `id`=@PATH+2;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH+2,1,6437.940430,215.351151,397.798889,0,2,0,100,0),
(@PATH+2,2,6327.383789,143.591568,391.210876,6000,2,0,100,0),
(@PATH+2,3,6296.544531,76.174286,391.081909,6000,2,0,100,0);

UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NEXT+3;
DELETE FROM `creature_addon` WHERE `guid`=@NEXT+3;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES 
(@NEXT+3,@PATH+3,1,0, '');

DELETE FROM `waypoint_data` WHERE `id`=@PATH+3;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH+3,1,6419.338379,239.908859,396.095978,0,2,0,100,0),
(@PATH+3,2,6317.383789,115.591568,391.210876,6000,2,0,100,0),
(@PATH+3,3,6294.144531,126.174286,391.081909,6000,2,0,100,0);

-- Slayers reinforcements right on main path
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NEXT+4;
DELETE FROM `creature_addon` WHERE `guid`=@NEXT+4;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES 
(@NEXT+4,@PATH+4,1,0, '');

DELETE FROM `waypoint_data` WHERE `id`=@PATH+4;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH+4,1, 6428.831055, 239.908859, 396.763702,0,2,0,100,0),
(@PATH+4,2,6346.144531,126.174286,391.081909,6000,2,0,100,0),
(@PATH+4,3,6297.353789,80.591568,391.210876,6000,2,0,100,0);

UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NEXT+5;
DELETE FROM `creature_addon` WHERE `guid`=@NEXT+5;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES 
(@NEXT+5,@PATH+5,1,0, '');

DELETE FROM `waypoint_data` WHERE `id`=@PATH+5;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH+5,1, 6400.702148, 236.755035, 395.685333,0,2,0,100,0),
(@PATH+5,2,6356.144531,106.174286,391.081909,6000,2,0,100,0),
(@PATH+5,3,6398.383789,70.591568,391.210876,6000,2,0,100,0);

UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NEXT+6;
DELETE FROM `creature_addon` WHERE `guid`=@NEXT+6;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES 
(@NEXT+6,@PATH+6,1,0, '');

DELETE FROM `waypoint_data` WHERE `id`=@PATH+6;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH+6,1, 6410.955078, 249.759094, 396.454742,0,2,0,100,0),
(@PATH+6,2,6376.144531,116.174286,391.081909,6000,2,0,100,0),
(@PATH+6,3,6295.383789,65.591568,391.210876,6000,2,0,100,0);

-- Slayers reinforcements on the rear
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NEXT+31;
DELETE FROM `creature_addon` WHERE `guid`=@NEXT+31;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES 
(@NEXT+31,@PATH+7,1,0, '');

DELETE FROM `waypoint_data` WHERE `id`=@PATH+7;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH+7,1, 6113.089844, 156.401672, 369.398804,0,2,0,100,0),
(@PATH+7,2,6175.009766,125.577263,369.434753,6000,2,0,100,0),
(@PATH+7,3,6109.930176,49.710854,369.404419,6000,2,0,100,0);

UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NEXT+32;
DELETE FROM `creature_addon` WHERE `guid`=@NEXT+32;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NEXT+32,@PATH+8,1,0, '');

DELETE FROM `waypoint_data` WHERE `id`=@PATH+8;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH+8,1, 6103.571289, 140.684174, 368.524414,0,2,0,100,0),
(@PATH+8,2,6165.009766,119.577263,369.434753,6000,2,0,100,0),
(@PATH+8,3,6118.930176,64.710854,369.404419,6000,2,0,100,0);

UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NEXT+33;
DELETE FROM `creature_addon` WHERE `guid`=@NEXT+33;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NEXT+33,@PATH+9,1,0, '');

DELETE FROM `waypoint_data` WHERE `id`=@PATH+9;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH+9,1, 6093.838867, 143.838867, 368.781097,0,2,0,100,0),
(@PATH+9,2,6171.009766,114.577263,369.434753,6000,2,0,100,0),
(@PATH+9,3,6114.930176,61.710854,369.404419,6000,2,0,100,0);

UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NEXT+34;
DELETE FROM `creature_addon` WHERE `guid`=@NEXT+34;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NEXT+34,@PATH+10,1,0, '');

DELETE FROM `waypoint_data` WHERE `id`=@PATH+10;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH+10,1, 6090.764160, 141.764160, 369.786255,0,2,0,100,0),
(@PATH+10,2,6183.009766,109.577263,369.434753,6000,2,0,100,0),
(@PATH+10,3,6109.930176,57.710854,369.404419,6000,2,0,100,0);

UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NEXT+35;
DELETE FROM `creature_addon` WHERE `guid`=@NEXT+35;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NEXT+35,@PATH+11,1,0, '');

DELETE FROM `waypoint_data` WHERE `id`=@PATH+11;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH+11,1, 6079.681641, 141.840958, 369.456573,0,2,0,100,0),
(@PATH+11,2,6180.009766,121.577263,369.434753,6000,2,0,100,0),
(@PATH+11,3,6124.930176,70.710854,369.404419,6000,2,0,100,0);

UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NEXT+36;
DELETE FROM `creature_addon` WHERE `guid`=@NEXT+36;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NEXT+36,@PATH+12,1,0, '');

DELETE FROM `waypoint_data` WHERE `id`=@PATH+12;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH+12,1, 6062.076660, 155.683197, 369.868896,0,2,0,100,0),
(@PATH+12,2,6114.930176,74.710854,368.404419,6000,2,0,100,0),
(@PATH+12,3,6187.009766,111.577263,369.434753,6000,2,0,100,0);

UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NEXT+37;
DELETE FROM `creature_addon` WHERE `guid`=@NEXT+37;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NEXT+37,@PATH+13,1,0, '');

DELETE FROM `waypoint_data` WHERE `id`=@PATH+13;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH+13,1, 6076.666016, 163.742477, 369.454651,0,2,0,100,0),
(@PATH+13,2,6117.930176,55.710854,369.404419,6000,2,0,100,0),
(@PATH+13,3,6178.009766,112.577263,369.434753,6000,2,0,100,0);

UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NEXT+38;
DELETE FROM `creature_addon` WHERE `guid`=@NEXT+38;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NEXT+38,@PATH+14,1,0, '');

DELETE FROM `waypoint_data` WHERE `id`=@PATH+14;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH+14,1, 6088.131348, 179.086304, 372.483307,0,2,0,100,0),
(@PATH+14,2,6115.930176,73.710854,369.404419,6000,2,0,100,0),
(@PATH+14,3,6185.009766,119.577263,369.434753,6000,2,0,100,0);

UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NEXT+39;
DELETE FROM `creature_addon` WHERE `guid`=@NEXT+39;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NEXT+39,@PATH+15,1,0, '');

DELETE FROM `waypoint_data` WHERE `id`=@PATH+15;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH+15,1, 6098.503418, 176.307312, 369.942688,0,2,0,100,0),
(@PATH+15,2,6115.930176,51.710854,369.404419,6000,2,0,100,0),
(@PATH+15,3,6185.009766,110.577263,369.434753,6000,2,0,100,0);

UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NEXT+40;
DELETE FROM `creature_addon` WHERE `guid`=@NEXT+40;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NEXT+40,@PATH+16,1,0, '');

DELETE FROM `waypoint_data` WHERE `id`=@PATH+16;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH+16,1, 6090.764160, 155.876968, 368.786255,0,2,0,100,0),
(@PATH+16,2,6112.930176,61.710854,369.404419,6000,2,0,100,0),
(@PATH+16,3,6176.009766,114.577263,370.434753,6000,2,0,100,0);

-- Slayers from West to both parts
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NEXT+26;
DELETE FROM `creature_addon` WHERE `guid`=@NEXT+26;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NEXT+26,@PATH+17,1,0, '');

DELETE FROM `waypoint_data` WHERE `id`=@PATH+17;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH+17,1, 6200.917969,  220.434753, 372.776184,0,2,0,100,0),
(@PATH+17,2,6346.144531,126.174286,372.081909,6000,2,0,100,0),
(@PATH+17,3,6287.383789,80.591568,372.210876,6000,2,0,100,0);

UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NEXT+27;
DELETE FROM `creature_addon` WHERE `guid`=@NEXT+27;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NEXT+27,@PATH+19,1,0, '');

DELETE FROM `waypoint_data` WHERE `id`=@PATH+19;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH+19,1, 6200.917969,  220.434753, 372.776184,0,2,0,100,0),
(@PATH+19,2,6356.144531,106.174286,372.081909,6000,2,0,100,0),
(@PATH+19,3,6395.383789,70.591568,372.210876,6000,2,0,100,0);

UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NEXT+28;
DELETE FROM `creature_addon` WHERE `guid`=@NEXT+28;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NEXT+28,@PATH+20,1,0, '');

DELETE FROM `waypoint_data` WHERE `id`=@PATH+20;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH+20,1, 6190.595703, 225.242371, 372.554016,0,2,0,100,0),
(@PATH+20,2,6175.009766,125.577263,372.434753,6000,2,0,100,0),
(@PATH+20,3,6104.930176,59.710854,372.404419,6000,2,0,100,0);

UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NEXT+29;
DELETE FROM `creature_addon` WHERE `guid`=@NEXT+29;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES 
(@NEXT+29,@PATH+21,1,0, '');

DELETE FROM `waypoint_data` WHERE `id`=@PATH+21;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH+21,1, 6189.209961, 210.502823, 372.877960,0,2,0,100,0),
(@PATH+21,2,6171.009766,119.577263,372.434753,6000,2,0,100,0),
(@PATH+21,3,6118.930176,64.710854,372.404419,6000,2,0,100,0);

UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NEXT+29;
DELETE FROM `creature_addon` WHERE `guid`=@NEXT+29;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES 
(@NEXT+29,@PATH+22,1,0, '');

DELETE FROM `waypoint_data` WHERE `id`=@PATH+22;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH+22,1, 6176.683594, 213.375336, 372.395172,0,2,0,100,0),
(@PATH+22,2,6173.009766,117.577263,372.434753,6000,2,0,100,0),
(@PATH+22,3,6118.930176,63.710854,372.404419,6000,2,0,100,0);

-- Turrets
UPDATE `creature_template` SET `faction_A`=2231,`faction_H`=2231,`unit_flags`=16777220,`npcflag`=16777216,`vehicleid`=292 WHERE `entry`=30236;
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=30236;
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`cast_flags`,`user_type`) VALUES
(30236,57573,1,0);
