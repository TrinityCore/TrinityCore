-- Tower of the Damned revamp
SET @CGUID := 85740;
SET @POOLENTRY := 1117;

-- Move wrong spawns
UPDATE `creature` SET `position_x`=6455.98, `position_y`=-6347.05, `position_z`=55.178, `orientation`=1.3107, `spawndist`=0, `MovementType`=0 WHERE `guid`=82854;
UPDATE `creature` SET `position_x`=6440.71, `position_y`=-6404.61, `position_z`=48.678, `orientation`=1.2039, `spawndist`=0, `MovementType`=2 WHERE `guid`=82937;
UPDATE `creature` SET `position_x`=6437.28, `position_y`=-6360.66, `position_z`=41.276, `orientation`=1.2629, `spawndist`=0, `MovementType`=2 WHERE `guid`=82897;
UPDATE `creature` SET `position_x`=6448.90, `position_y`=-6382.36, `position_z`=41.282, `orientation`=2.7828 WHERE `guid`=82871;

-- Delete wrong spawns
DELETE FROM `creature` WHERE `guid` IN (82879, 82899, 82870, 82841, 82823, 82864, 82915);
DELETE FROM `creature_addon` WHERE `guid` IN (82879, 82899, 82870, 82841, 82823, 82864, 82915); 
DELETE FROM `spawn_group` WHERE `groupId`=2 AND `spawnType`=0 AND `spawnId`=82870;

-- Add 3 Deatholme Necromancer and 3 Eyes of Dar'Khan
DELETE FROM `creature` where `guid` BETWEEN @CGUID AND @CGUID + 5;
INSERT INTO `creature` (`guid`, `id`, `map`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `curhealth`, `curmana`, `MovementType`) VALUES
(@CGUID    , 16317, 530, 1, 6461.42, -6345.30, 41.233, 2.8408, 300, 377, 408, 0),
(@CGUID + 1, 16317, 530, 1, 6476.68, -6362.99, 27.201, 3.8813, 300, 377, 408, 0),
(@CGUID + 2, 16317, 530, 1, 6470.83, -6380.51, 27.202, 1.8361, 300, 377, 408, 0),
(@CGUID + 3, 16320, 530, 0, 6461.81, -6349.33, 55.178, 1.2652, 300, 404, 456, 0),
(@CGUID + 4, 16320, 530, 0, 6437.28, -6360.66, 41.276, 1.2629, 300, 404, 456, 2),
(@CGUID + 5, 16320, 530, 0, 6440.71, -6404.61, 48.678, 1.2039, 300, 404, 456, 2);

-- Add pathing of two Wailers and two Eyes of Dar'Khan
SET @PATHID_1 := 829370;
SET @PATHID_2 := 828970;
SET @PATHID_3 := (@CGUID + 4) * 10;
SET @PATHID_4 := (@CGUID + 5) * 10;

DELETE FROM `creature_addon` WHERE `guid` IN (82937, 82897, @CGUID + 4, @CGUID + 5);
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES 
(82937, @PATHID_1, 1),
(82897, @PATHID_2, 1),
(@CGUID + 4, @PATHID_3, 1),
(@CGUID + 5, @PATHID_4, 1);

DELETE FROM `waypoint_data` WHERE `id` IN (@PATHID_1, @PATHID_2, @PATHID_3, @PATHID_4);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`) VALUES
(@PATHID_1, 1, 6445.87, -6388.29, 55.178),
(@PATHID_1, 2, 6462.24, -6385.64, 55.178),
(@PATHID_1, 3, 6477.23, -6373.64, 55.178),
(@PATHID_1, 4, 6472.75, -6355.57, 55.178),
(@PATHID_1, 5, 6460.20, -6343.13, 55.178),
(@PATHID_1, 6, 6465.87, -6326.58, 48.679),
(@PATHID_1, 7, 6460.20, -6343.13, 55.178),
(@PATHID_1, 8, 6443.27, -6346.17, 55.179),
(@PATHID_1, 9, 6430.45, -6358.61, 55.179),
(@PATHID_1, 10, 6433.99, -6376.20, 55.178),
(@PATHID_1, 11, 6445.87, -6388.29, 55.178),
(@PATHID_1, 12, 6440.46, -6404.84, 48.678),
(@PATHID_2, 1, 6443.78, -6340.43, 41.291),
(@PATHID_2, 2, 6459.56, -6345.86, 41.208),
(@PATHID_2, 3, 6453.16, -6365.24, 33.735),
(@PATHID_2, 4, 6446.68, -6384.37, 41.203),
(@PATHID_2, 5, 6430.96, -6379.17, 41.291),
(@PATHID_2, 6, 6437.28, -6360.66, 41.276),
(@PATHID_3, 1, 6443.78, -6340.43, 41.291),
(@PATHID_3, 2, 6459.56, -6345.86, 41.208),
(@PATHID_3, 3, 6453.16, -6365.24, 33.735),
(@PATHID_3, 4, 6446.68, -6384.37, 41.203),
(@PATHID_3, 5, 6430.96, -6379.17, 41.291),
(@PATHID_3, 6, 6437.28, -6360.66, 41.276),
(@PATHID_4, 1, 6445.87, -6388.29, 55.178),
(@PATHID_4, 2, 6462.24, -6385.64, 55.178),
(@PATHID_4, 3, 6477.23, -6373.64, 55.178),
(@PATHID_4, 4, 6472.75, -6355.57, 55.178),
(@PATHID_4, 5, 6460.20, -6343.13, 55.178),
(@PATHID_4, 6, 6465.87, -6326.58, 48.679),
(@PATHID_4, 7, 6460.20, -6343.13, 55.178),
(@PATHID_4, 8, 6443.27, -6346.17, 55.179),
(@PATHID_4, 9, 6430.45, -6358.61, 55.179),
(@PATHID_4, 10, 6433.99, -6376.20, 55.178),
(@PATHID_4, 11, 6445.87, -6388.29, 55.178),
(@PATHID_4, 12, 6440.46, -6404.84, 48.678);

-- Eyes of Dar'Khan/Wailers shared spawns
SET @POOL_1 := @POOLENTRY;
SET @POOL_2 := @POOLENTRY + 1;

DELETE FROM `pool_template` WHERE `entry` IN (@POOL_1, @POOL_2);
INSERT INTO `pool_template` VALUES 
(@POOL_1, 1, "Eye of DarKhan/Wailer Spawn 1"),
(@POOL_2, 1, "Eye of DarKhan/Wailer Spawn 2");

DELETE FROM `pool_creature` WHERE `guid` IN (82897, 82937, @CGUID + 4, @CGUID + 5);
INSERT INTO `pool_creature` VALUES 
(82897, @POOL_1, 0, "Wailer Spawn 1"),
(82937, @POOL_2, 0, "Wailer Spawn 2"),
(@CGUID + 4, @POOL_1, 0, "Eye of DarKhan Spawn 1"),
(@CGUID + 5, @POOL_2, 0, "Eye of DarKhan Spawn 2");

-- Rescript Dar'Khan Drathir and fix speech
-- by Teppic
SET @ENTRY := 16329;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dar'Khan Drathir - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,0,0,6000,12000,11,20791,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dar'Khan Drathir - In Combat CMC - Cast 'Shadow Bolt'"),
(@ENTRY,0,2,0,0,0,100,0,7000,9000,15000,15000,11,21068,0,0,0,0,0,5,0,0,0,0,0,0,0,"Dar'Khan Drathir - In Combat CMC - Cast 'Corruption'"),
(@ENTRY,0,3,0,0,0,100,0,15000,20000,16000,20000,11,38660,0,0,0,0,0,5,0,0,0,0,0,0,0,"Dar'Khan Drathir - In Combat CMC - Cast 'Fear'");

DELETE FROM `creature_text` WHERE `CreatureID`=@ENTRY;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(@ENTRY, 0, 0, 'Mortal fools!  The ghouls of Deatholme will feast on your remains!', 12, 0, 100, 0, 0, 0, 12224, 0, "Dar'Khan Drathir");
