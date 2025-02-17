-- Add 23 missing Battered Chest ID: 106318 with pooling in Teldrassil
SET @OGUID := 20592; -- 23 required
SET @POOLID := 844; -- 6 required

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+22;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID, 106318, 1, 141, 258, 1, 1, 10134.7548828125, 1183.4837646484375, 1323.5435791015625, 5.375615119934082031, 0, 0, -0.4383707046508789, 0.898794233798980712, 360, 255, 1, 41510), -- Fel Rock
(@OGUID+1, 106318, 1, 141, 258, 1, 1, 10128.7626953125, 1114.3878173828125, 1323.858154296875, 5.270895957946777343, 0, 0, -0.48480892181396484, 0.87462007999420166, 360, 255, 1, 41510), -- Fel Rock
(@OGUID+2, 106318, 1, 141, 258, 1, 1, 10182.3330078125, 1174.6905517578125, 1326.032958984375, 5.829400539398193359, 0, 0, -0.22495079040527343, 0.974370121955871582, 360, 255, 1, 41510), -- Fel Rock
(@OGUID+3, 106318, 1, 141, 262, 1, 1, 9749.2099609375, 1586.384765625, 1299.9820556640625, 1.919861555099487304, 0, 0, 0.819151878356933593, 0.573576688766479492, 360, 255, 1, 41510), -- Ban'ethil Barrow Den
(@OGUID+4, 106318, 1, 141, 262, 1, 1, 9703.41015625, 1543.0289306640625, 1254.1004638671875, 2.495818138122558593, 0, 0, 0.948323249816894531, 0.317305892705917358, 360, 255, 1, 41510), -- Ban'ethil Barrow Den
(@OGUID+5, 106318, 1, 141, 262, 1, 1, 9800.5625, 1581.1583251953125, 1291.1978759765625, 5.654868602752685546, 0, 0, -0.30901622772216796, 0.95105677843093872, 360, 255, 1, 41510), -- Ban'ethil Barrow Den
(@OGUID+6, 106318, 1, 141, 262, 1, 1, 9776.05078125, 1547.3790283203125, 1299.4854736328125, 0.715584874153137207, 0, 0, 0.350207328796386718, 0.936672210693359375, 360, 255, 1, 41510), -- Ban'ethil Barrow Den
(@OGUID+7, 106318, 1, 141, 264, 1, 1, 10511.2021484375, 2002.39306640625, 1327.3753662109375, 0.27925160527229309, 0, 0, 0.139172554016113281, 0.990268170833587646, 360, 255, 1, 41510), -- The Oracle Glade South
(@OGUID+8, 106318, 1, 141, 264, 1, 1, 10863.521484375, 2125.578857421875, 1327.0626220703125, 2.635444164276123046, 0, 0, 0.96814727783203125, 0.250381410121917724, 360, 255, 1, 41510), -- The Oracle Glade North
(@OGUID+9, 106318, 1, 141, 264, 1, 1, 10620.2724609375, 2089.35205078125, 1336.537841796875, 4.782202720642089843, 0, 0, -0.68199825286865234, 0.731353819370269775, 360, 255, 1, 41510), -- The Oracle Glade South
(@OGUID+10, 106318, 1, 141, 141, 1, 1, 9673.74609375, 454.109161376953125, 1309.8837890625, 1.640606880187988281, 0, 0, 0.731352806091308593, 0.6819993257522583, 360, 255, 1, 41446), -- South of Starbreeze Village
(@OGUID+11, 106318, 1, 141, 141, 1, 1, 9631.6015625, 463.320098876953125, 1312.8011474609375, 2.67034769058227539, 0, 0, 0.972369194030761718, 0.233448356389999389, 360, 255, 1, 41446), -- South of Starbreeze Village
(@OGUID+12, 106318, 1, 141, 141, 1, 1, 10027.5283203125, 273.2647705078125, 1323.5810546875, 2.478367090225219726, 0, 0, 0.94551849365234375, 0.325568377971649169, 360, 255, 1, 41446), -- North of Starbreeze Village
(@OGUID+13, 106318, 1, 141, 141, 1, 1, 9183.7001953125, 1372.7894287109375, 1315.068359375, 3.595378875732421875, 0, 0, -0.97437000274658203, 0.224951311945915222, 360, 255, 1, 41446), -- South
(@OGUID+14, 106318, 1, 141, 141, 1, 1, 9264.998046875, 949.08831787109375, 1312.4244384765625, 5.95157480239868164, 0, 0, -0.16504669189453125, 0.986285746097564697, 360, 255, 1, 41510), -- South
(@OGUID+15, 106318, 1, 141, 141, 1, 1, 10419.6533203125, 1908.990234375, 1321.2657470703125, 2.617989301681518554, 0, 0, 0.965925216674804687, 0.258821308612823486, 360, 255, 1, 41510), -- Below The Oracle Glade
(@OGUID+16, 106318, 1, 141, 141, 1, 1, 10371.857421875, 1923.328125, 1319.966552734375, 0.977383077144622802, 0, 0, 0.469470977783203125, 0.882947921752929687, 360, 255, 1, 41510), -- Below The Oracle Glade
-- 6 from Mangos DB
(@OGUID+17, 106318, 1, 141, 262, 1, 1, 9730.49, 1576.73, 1269.44, 3.07177, 0, 0, 0.999391, 0.0349061, 360, 255, 1, 0), -- Ban'ethil Barrow Den
(@OGUID+18, 106318, 1, 141, 262, 1, 1, 9831.43, 1533.49, 1257.51, 1.36136, 0, 0, 0.62932, 0.777146, 360, 255, 1, 0), -- Ban'ethil Barrow Den
(@OGUID+19, 106318, 1, 141, 262, 1, 1, 9800.56, 1581.16, 1291.2, 5.65487, 0, 0, -0.309016, 0.951057, 360, 255, 1, 0), -- Ban'ethil Barrow Den
(@OGUID+20, 106318, 1, 141, 262, 1, 1, 9730.49, 1576.73, 1269.44, 3.07177, 0, 0, 0.999391, 0.0349061, 360, 255, 1, 0), -- Ban'ethil Barrow Den
(@OGUID+21, 106318, 1, 141, 264, 1, 1, 10751.3, 2214.47, 1331.51, 4.69494, 0, 0, -0.71325, 0.70091, 360, 255, 1, 0), -- The Oracle Glade
(@OGUID+22, 106318, 1, 141, 264, 1, 1, 10890.4, 1968.21, 1321.79, 4.95674, 0, 0, -0.615661, 0.788011, 360, 255, 1, 0); -- The Oracle Glade

-- Update existing spawns to match new ones.
UPDATE `gameobject` SET `spawntimesecs`=360, `animprogress`=225, `state`=1 WHERE `guid` IN
(49622,49624,49626,49628,49627,49621,49623,49625);

DELETE FROM `pool_template` WHERE `entry` BETWEEN @POOLID AND @POOLID+5;
INSERT INTO `pool_template` (`entry`,`max_limit`,`description`) VALUES
(@POOLID,1,'Battered Chest (106318), Teldassil, Chest Pool Fel Rock'),
(@POOLID+1,1,'Battered Chest (106318), Teldassil, Chest Pool Ban''ethil Barrow Den'),
(@POOLID+2,1,'Battered Chest (106318), Teldassil, Chest Pool The Oracle Glade North'),
(@POOLID+3,1,'Battered Chest (106318), Teldassil, Chest Pool The Oracle Glade South'),
(@POOLID+4,1,'Battered Chest (106318), Teldassil, Chest Pool Starbreeze Village'),
(@POOLID+5,1,'Battered Chest (106318), Teldassil, Chest Pool Southern Teldrassil');

DELETE FROM `pool_members` WHERE `poolSpawnId` BETWEEN @POOLID AND @POOLID+5;
INSERT INTO `pool_members` (`type`,`spawnId`,`poolSpawnId`,`chance`,`description`) VALUES
(1,49628,@POOLID,0,'Battered Chest (106318), Fel Rock'),
(1,@OGUID,@POOLID,0,'Battered Chest (106318), Fel Rock'),
(1,@OGUID+1,@POOLID,0,'Battered Chest (106318), Fel Rock'),
(1,@OGUID+2,@POOLID,0,'Battered Chest (106318), Fel Rock'),
(1,49627,@POOLID+1,0,'Battered Chest (106318), Ban''ethil Barrow Den'),
(1,@OGUID+3,@POOLID+1,0,'Battered Chest (106318), Ban''ethil Barrow Den'),
(1,@OGUID+4,@POOLID+1,0,'Battered Chest (106318), Ban''ethil Barrow Den'),
(1,@OGUID+5,@POOLID+1,0,'Battered Chest (106318), Ban''ethil Barrow Den'),
(1,@OGUID+6,@POOLID+1,0,'Battered Chest (106318), Ban''ethil Barrow Den'),
(1,@OGUID+17,@POOLID+1,0,'Battered Chest (106318), Ban''ethil Barrow Den'),
(1,@OGUID+18,@POOLID+1,0,'Battered Chest (106318), Ban''ethil Barrow Den'),
(1,@OGUID+19,@POOLID+1,0,'Battered Chest (106318), Ban''ethil Barrow Den'),
(1,@OGUID+20,@POOLID+1,0,'Battered Chest (106318), Ban''ethil Barrow Den'),
(1,49621,@POOLID+2,0,'Battered Chest (106318), The Oracle Glade North'),
(1,@OGUID+8,@POOLID+2,0,'Battered Chest (106318), The Oracle Glade North'),
(1,@OGUID+21,@POOLID+2,0,'Battered Chest (106318), The Oracle Glade North'),
(1,@OGUID+22,@POOLID+2,0,'Battered Chest (106318), The Oracle Glade North'),
(1,49623,@POOLID+3,0,'Battered Chest (106318), The Oracle Glade South'),
(1,49625,@POOLID+3,0,'Battered Chest (106318), The Oracle Glade South'),
(1,@OGUID+7,@POOLID+3,0,'Battered Chest (106318), The Oracle Glade South'),
(1,@OGUID+9,@POOLID+3,0,'Battered Chest (106318), The Oracle Glade South'),
(1,@OGUID+15,@POOLID+3,0,'Battered Chest (106318), The Oracle Glade South'),
(1,@OGUID+16,@POOLID+3,0,'Battered Chest (106318), The Oracle Glade South'),
(1,49622,@POOLID+4,0,'Battered Chest (106318), Starbreeze Village'),
(1,@OGUID+10,@POOLID+4,0,'Battered Chest (106318), Starbreeze Village'),
(1,@OGUID+11,@POOLID+4,0,'Battered Chest (106318), Starbreeze Village'),
(1,@OGUID+12,@POOLID+4,0,'Battered Chest (106318), Starbreeze Village'),
(1,49624,@POOLID+5,0,'Battered Chest (106318), Southern Teldrassil'),
(1,49626,@POOLID+5,0,'Battered Chest (106318), Southern Teldrassil'),
(1,@OGUID+13,@POOLID+5,0,'Battered Chest (106318), Southern Teldrassil'),
(1,@OGUID+14,@POOLID+5,0,'Battered Chest (106318), Southern Teldrassil');
