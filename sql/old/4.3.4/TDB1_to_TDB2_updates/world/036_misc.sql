DELETE FROM `gameobject_template` WHERE `entry`=202474;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `data24`, `data25`, `data26`, `data27`, `data28`, `data29`, `data30`, `data31`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `unkInt32`, `WDBVerified`) VALUES
(202474, 2, 1387, 'Antediluvean Chest', '', '', '', 0, 14853, 5, 12644, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 15595); -- -Unknown-

SET @OGUID := 3;

DELETE FROM `gameobject` WHERE `guid`=@OGUID+0;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0, 202474, 1, 1, 1, -9814.125, -2790.748, 10.39087, 0.03490625, 0, 0, 0, 1, 120, 255, 1); -- -Unknown- (Area: 0)

SET @CGUID := 59;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+11;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 38916, 1, 1, 1, -9715.104, -2805.5, 10.48627, 1.762783, 120, 0, 0), -- Sandstone Earthen (Area: Ruins of Uldum)
(@CGUID+1, 38916, 1, 1, 1, -9702.332, -2804.821, 10.48628, 1.64061, 120, 0, 0), -- Sandstone Earthen (Area: Ruins of Uldum)
(@CGUID+2, 38916, 1, 1, 1, -9732.212, -2806.392, 10.48627, 1.762783, 120, 0, 0), -- Sandstone Earthen (Area: Ruins of Uldum)
(@CGUID+3, 38916, 1, 1, 1, -9686.688, -2804.899, 10.48627, 1.64061, 120, 0, 0), -- Sandstone Earthen (Area: Ruins of Uldum)
(@CGUID+4, 38916, 1, 1, 1, -9716.528, -2768.405, 10.48628, 4.590216, 120, 0, 0), -- Sandstone Earthen (Area: Ruins of Uldum)
(@CGUID+5, 38916, 1, 1, 1, -9703.538, -2768.986, 10.48627, 5.026548, 120, 0, 0), -- Sandstone Earthen (Area: Ruins of Uldum)
(@CGUID+6, 38916, 1, 1, 1, -9687.903, -2768.425, 10.48628, 4.590216, 120, 0, 0), -- Sandstone Earthen (Area: Ruins of Uldum)
(@CGUID+7, 38916, 1, 1, 1, -9732.163, -2768.964, 10.48628, 5.026548, 120, 0, 0), -- Sandstone Earthen (Area: Ruins of Uldum)
(@CGUID+8, 38916, 1, 1, 1, -9748.317, -2827.802, 10.47396, 1.762783, 120, 0, 0), -- Sandstone Earthen (Area: Ruins of Uldum)
(@CGUID+9, 38916, 1, 1, 1, -9770.007, -2828.538, 10.47398, 1.762783, 120, 0, 0), -- Sandstone Earthen (Area: Ruins of Uldum)
(@CGUID+10, 38916, 1, 1, 1, -9750.641, -2749.778, 11.43321, 4.590216, 120, 0, 0), -- Sandstone Earthen (Area: Ruins of Uldum)
(@CGUID+11, 38916, 1, 1, 1, -9815.073, -2817.913, 10.47402, 0.1919862, 120, 0, 0); -- Sandstone Earthen (Area: 0)
