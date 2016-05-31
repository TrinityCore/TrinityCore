-- Grovestalker Lynx SAI "Missing AI"
SET @ENTRY := 21022;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
UPDATE `creature` SET `curhealth`=1 WHERE `id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,11,36589,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grovestalker Lynx - On Aggro - Cast Dash");

-- Fey Drake SAI "Missing AI"
SET @ENTRY := 20713;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
UPDATE `creature` SET `curhealth`=1, `curmana`=0 WHERE `id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,12000,12000,12000,15000,11,11981,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fey Drake - In Combat - Cast Mana Burn"),
(@ENTRY,0,1,0,0,0,100,0,5000,6000,5000,7000,11,36718,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fey Drake - In Combat - Cast Blink");

-- Pathing for High Commander Halford Wyrmbane Entry: 27136
SET @NPC := 131105;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3767.499,`position_y`=-775.0477,`position_z`=196.087 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3767.499,-775.0477,196.087,0,0,0,100,0),
(@PATH,2,3776.538,-783.3422,196.087,0,0,0,100,0);

-- Pathing for Stronglimb Deeproot Entry: 21023
SET @NPC := 73833;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1562.740,`position_y`=6815.711,`position_z`=126.20748 WHERE `guid`=@NPC;
UPDATE `creature_template_addon` SET `path_id`=@PATH WHERE `entry`=21023;
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1562.740,6815.711,126.20748,0,0,0,0,100,0),
(@PATH,2,1579.44,6823.31,128.221,0,0,0,0,100,0),
(@PATH,3,1596.410,6824.691,129.57422,0,0,0,0,100,0),
(@PATH,4,1613.536,6820.844,130.43893,0,0,0,0,100,0),
(@PATH,5,1626.575,6815.952,131.11913,0,0,0,0,100,0),
(@PATH,6,1647.335,6811.267,132.32887,0,0,0,0,100,0),
(@PATH,7,1666.315,6811.949,134.0304,0,0,0,0,100,0),
(@PATH,8,1682.469,6819.250,135.48557,0,0,0,0,100,0),
(@PATH,9,1704.364,6826.659,135.97731,0,0,0,0,100,0),
(@PATH,10,1723.946,6822.768,136.24043,0,0,0,0,100,0),
(@PATH,11,1744.097,6815.729,136.71513,0,0,0,0,100,0),
(@PATH,12,1767.085,6807.892,137.25296,0,0,0,0,100,0),
(@PATH,13,1794.797,6805.661,137.31673,0,0,0,0,100,0),
(@PATH,14,1824.876,6814.818,138.48926,0,0,0,0,100,0),
(@PATH,15,1851.305,6823.799,141.24908,0,0,0,0,100,0),
(@PATH,16,1877.366,6829.852,144.43327,0,0,0,0,100,0),
(@PATH,17,1897.890,6833.999,146.215,0,0,0,0,100,0),
(@PATH,18,1907.787,6835.113,147.04056,3.015979,30000,0,0,100,0),
(@PATH,19,1897.890,6833.999,146.215,0,0,0,0,100,0),
(@PATH,20,1877.366,6829.852,144.43327,0,0,0,0,100,0),
(@PATH,21,1851.305,6823.799,141.24908,0,0,0,0,100,0),
(@PATH,22,1824.876,6814.818,138.48926,0,0,0,0,100,0),
(@PATH,23,1794.797,6805.661,137.31673,0,0,0,0,100,0),
(@PATH,24,1767.085,6807.892,137.25296,0,0,0,0,100,0),
(@PATH,25,1744.097,6815.729,136.71513,0,0,0,0,100,0),
(@PATH,26,1723.946,6822.768,136.24043,0,0,0,0,100,0),
(@PATH,27,1704.364,6826.659,135.97731,0,0,0,0,100,0),
(@PATH,28,1682.469,6819.250,135.48557,0,0,0,0,100,0),
(@PATH,29,1666.315,6811.949,134.03040,0,0,0,0,100,0),
(@PATH,30,1647.335,6811.267,132.32887,0,0,0,0,100,0),
(@PATH,31,1626.575,6815.952,131.11913,0,0,0,0,100,0),
(@PATH,32,1613.536,6820.844,130.43893,0,0,0,0,100,0),
(@PATH,33,1596.410,6824.691,129.57422,0,0,0,0,100,0),
(@PATH,34,1579.440,6823.310,128.22100,0,0,0,0,100,0),
(@PATH,35,1562.740,6815.711,126.20748,0,0,0,0,100,0),
(@PATH,36,1548.781,6810.126,124.27861,2.58955,30000,0,0,100,0);
