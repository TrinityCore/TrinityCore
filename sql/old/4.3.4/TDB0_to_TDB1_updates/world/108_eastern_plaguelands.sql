DELETE FROM `gameobject_template` WHERE `entry` IN (205558, 205873, 206611, 204806, 204807, 205878, 205879, 205880, 205881, 205875);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `data24`, `data25`, `data26`, `data27`, `data28`, `data29`, `data30`, `data31`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `unkInt32`, `WDBVerified`) VALUES
(205558, 3, 8077, 'Flesh Giant Foot', '', 'Scraping', '', 93, 34718, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45886, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 61366, 0, 0, 0, 0, 0, 0, 15595), -- -Unknown-
(205873, 22, 9069, 'Argent Parachutes', '', '', '', 85882, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- -Unknown-
(206611, 8, 4452, '', '', '', '', 0, 10, 2066, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.64, 0, 0, 0, 0, 0, 0, 0, 15595), -- -Unknown-
(204806, 8, 200, 'Bonfire', '', '', '', 4, 10, 2066, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- -Unknown-
(204807, 8, 200, 'Bonfire', '', '', '', 4, 10, 2066, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.49902, 0, 0, 0, 0, 0, 0, 0, 15595), -- -Unknown-
(205878, 3, 10, 'Battered Chest', '', 'Opening', '', 93, 34748, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 21400, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 61959, 0, 0, 0, 0, 0, 0, 15595), -- -Unknown-
(205879, 3, 10, 'Battered Chest', '', 'Opening', '', 93, 34749, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 21400, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 61960, 0, 0, 0, 0, 0, 0, 15595), -- -Unknown-
(205880, 3, 10, 'Battered Chest', '', 'Opening', '', 93, 34750, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 21400, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 61961, 0, 0, 0, 0, 0, 0, 15595), -- -Unknown-
(205881, 3, 10, 'Battered Chest', '', 'Opening', '', 93, 34751, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 21400, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 61962, 0, 0, 0, 0, 0, 0, 15595), -- -Unknown-
(205875, 2, 6543, 'Crusader''s Flare', '', '', '', 0, 15768, 0, 12088, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 15595); -- -Unknown-

UPDATE `gameobject_template` SET `data3`=0, `WDBVerified`=15595 WHERE `entry`=177789; -- Augustus' Receipt Book
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=177667; -- Torn Scroll
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176264; -- Campfire
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176967; -- Stratholme
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176968; -- Terrordale
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176969; -- Quel'Thalas
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176986; -- Darrowshire
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176983; -- Andorhal
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176985; -- Stratholme
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176984; -- Corin's Crossing
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=177544; -- Joseph's Chest
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176116; -- Pamela's Doll's Head
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176143; -- Pamela's Doll's Right Side
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176142; -- Pamela's Doll's Left Side
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176267; -- Campfire
UPDATE `gameobject_template` SET `castBarCaption`='Collecting', `data3`=0, `data14`=19676, `WDBVerified`=15595 WHERE `entry`=176208; -- Horgus' Skull
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176591; -- Horgus' Skull Trap
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176268; -- Campfire
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176266; -- Campfire
UPDATE `gameobject_template` SET `castBarCaption`='Retrieving', `data3`=0, `data14`=23645, `WDBVerified`=15595 WHERE `entry`=176209; -- Shattered Sword of Marduk
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176865; -- Sword of Marduk Trap
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176271; -- Campfire
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=181134; -- Bonfire
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=181135; -- Bonfire
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=182059; -- Campfire
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=20969; -- Scourge Campfire
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=20970; -- Bubbling Cauldron
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=179498; -- Scarlet Footlocker
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=181104; -- Small Dirt Mound
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176389; -- Campfire
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176390; -- Campfire
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176275; -- Bubbling Cauldron
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=151967; -- Wooden Bench
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=151957; -- Wooden Bench
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176273; -- Bubbling Cauldron
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176274; -- Campfire
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=147449; -- Bench
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=147448; -- Bench
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=147450; -- Bench
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=147447; -- Bench
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=160866; -- Pew
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=160867; -- Pew
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=160869; -- Pew
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=160871; -- Pew
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=160868; -- Pew
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=160870; -- Pew

SET @OGUID := 79029;

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+633;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0, 1735, 0, 1, 1, 1827.21, -2801.94, 87.6914, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: 0)
-- (@OGUID+1, 181688, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 120, 255, 1), -- 0 (Area: 0) - !!! transport !!!
-- (@OGUID+1, 175080, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 120, 255, 1), -- 0 (Area: 0) - !!! transport !!!
-- (@OGUID+1, 181689, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 120, 255, 1), -- 0 (Area: 0) - !!! transport !!!
-- (@OGUID+1, 164871, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 120, 255, 1), -- 0 (Area: 0) - !!! transport !!!
-- (@OGUID+1, 190536, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 120, 255, 1), -- 0 (Area: Plaguewood) - !!! transport !!!
(@OGUID+1, 2040, 0, 1, 1, 2912.56, -2730.71, 117.938, 0.5585039, 0, 0, 0, 1, 120, 255, 1), -- Mithril Deposit (Area: Terrordale)
(@OGUID+2, 1735, 0, 1, 1, 2931.76, -2682.95, 95.7751, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: Terrordale)
(@OGUID+3, 1735, 0, 1, 1, 2970.81, -2720.9, 99.899, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: Terrordale)
(@OGUID+4, 1735, 0, 1, 1, 3004.95, -2747.76, 100.294, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: Terrordale)
(@OGUID+5, 1735, 0, 1, 1, 2872.82, -2586.86, 88.6011, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: 0)
(@OGUID+6, 1735, 0, 1, 1, 2816.09, -2518.52, 83.6082, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: 0)
(@OGUID+7, 1735, 0, 1, 1, 2804.77, -2486.04, 85.1964, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: 0)
-- (@OGUID+8, 176231, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 120, 255, 1), -- 0 (Area: 0) - !!! transport !!!
(@OGUID+8, 205423, 0, 1, 1, 2715.16, -2449.59, 65.9118, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+9, 205423, 0, 1, 1, 2772.78, -2419.43, 58.0397, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+10, 205423, 0, 1, 1, 2727.78, -2424.02, 54.2389, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: 0)
-- (@OGUID+11, 20808, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 120, 255, 1), -- 0 (Area: 0) - !!! transport !!!
(@OGUID+11, 205423, 0, 1, 1, 2612.89, -2479.79, 72.6342, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Thondroril River)
(@OGUID+12, 205423, 0, 1, 1, 2704.76, -2414.02, 54.4402, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Thondroril River)
(@OGUID+13, 205423, 0, 1, 1, 2682.68, -2426.13, 63.0347, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Thondroril River)
(@OGUID+14, 205423, 0, 1, 1, 2778.98, -2389.98, 53.4418, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Terrorweb Tunnel)
(@OGUID+15, 205423, 0, 1, 1, 2655.99, -2400.13, 53.7366, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Thondroril River)
(@OGUID+16, 180684, 0, 1, 1, 2660.15, -2386.38, 54.11213, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Greater Sagefish School (Area: Thondroril River)
(@OGUID+17, 205423, 0, 1, 1, 2490.96, -2513.79, 93.554, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Thondroril River)
(@OGUID+18, 205423, 0, 1, 1, 2514.62, -2457.62, 73.6071, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Thondroril River)
(@OGUID+19, 205423, 0, 1, 1, 2589.5, -2400.24, 46.6971, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Thondroril River)
(@OGUID+20, 205423, 0, 1, 1, 2553.08, -2479.52, 74.5691, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Thondroril River)
(@OGUID+21, 205423, 0, 1, 1, 2584.65, -2453.07, 70.5143, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Thondroril River)
-- (@OGUID+22, 176310, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 120, 255, 1), -- 0 (Area: Thondroril River) - !!! transport !!!
(@OGUID+22, 205423, 0, 1, 1, 2469.61, -2455.14, 73.5122, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Thondroril River)
(@OGUID+23, 205423, 0, 1, 1, 2319.07, -2524.32, 50.0193, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Thondroril River)
(@OGUID+24, 205423, 0, 1, 1, 2367.36, -2467.21, 42.775, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Thondroril River)
(@OGUID+25, 205423, 0, 1, 1, 2386.54, -2471.65, 54.9726, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Thondroril River)
(@OGUID+26, 205423, 0, 1, 1, 2413.33, -2482.26, 73.5046, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Thondroril River)
(@OGUID+27, 205423, 0, 1, 1, 2279.67, -2615.4, 73.5277, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Thondroril River)
(@OGUID+28, 205423, 0, 1, 1, 2381.47, -2513.72, 73.5862, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Thondroril River)
(@OGUID+29, 2043, 0, 1, 1, 2020.415, -2898.495, 79.06556, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: 0)
(@OGUID+30, 2043, 0, 1, 1, 1713.59, -2832.34, 75.2752, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: 0)
(@OGUID+31, 142142, 0, 1, 1, 1748.71, -2781.98, 67.4532, 2.391098, 0, 0, 0, 1, 120, 255, 1), -- Sungrass (Area: 0)
(@OGUID+32, 180684, 0, 1, 1, 1636.21, -2771.76, 52.51758, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Greater Sagefish School (Area: 0)
(@OGUID+33, 1735, 0, 1, 1, 1732.44, -2918.27, 97.2459, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: 0)
(@OGUID+34, 2040, 0, 1, 1, 2870.31, -2872.32, 104.316, 0.5585039, 0, 0, 0, 1, 120, 255, 1), -- Mithril Deposit (Area: Plaguewood)
(@OGUID+35, 2043, 0, 1, 1, 2878.11, -2936.08, 102.041, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: Terrordale)
(@OGUID+36, 177789, 0, 1, 1, 2997.614, -2860.274, 107.6299, 1.117009, 0, 0, 0, 1, 120, 255, 1), -- Augustus' Receipt Book (Area: Terrordale)
(@OGUID+37, 142142, 0, 1, 1, 3052.05, -2936.66, 112.456, 2.391098, 0, 0, 0, 1, 120, 255, 1), -- Sungrass (Area: Terrordale)
(@OGUID+38, 2043, 0, 1, 1, 3088.48, -2939.26, 118.808, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: Terrordale)
(@OGUID+39, 142142, 0, 1, 1, 3144.27, -2837.42, 132.959, 2.391098, 0, 0, 0, 1, 120, 255, 1), -- Sungrass (Area: Terrordale)
(@OGUID+40, 2040, 0, 1, 1, 3089.49, -2811.48, 126.778, 0.5585039, 0, 0, 0, 1, 120, 255, 1), -- Mithril Deposit (Area: Terrordale)
(@OGUID+41, 2040, 0, 1, 1, 3187.5, -2875, 147.335, 0.5585039, 0, 0, 0, 1, 120, 255, 1), -- Mithril Deposit (Area: Terrordale)
(@OGUID+42, 2040, 0, 1, 1, 3294.62, -2910.41, 162.588, 0.5585039, 0, 0, 0, 1, 120, 255, 1), -- Mithril Deposit (Area: Plaguewood)
(@OGUID+43, 205560, 0, 1, 1, 3215.69, -2991.81, 127.607, 4.276057, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Plaguewood)
(@OGUID+44, 205559, 0, 1, 1, 3236.08, -3004.99, 126.92, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Plaguewood)
(@OGUID+45, 185563, 0, 1, 1, 3236.08, -3004.99, 126.92, 0, 0, 0, 0, 1, 120, 255, 1), -- Aura Trap Red Short (Area: Plaguewood)
(@OGUID+46, 177464, 0, 1, 1, 3180.04, -3007.34, 125.409, 4.537859, 0, 0, 0, 1, 120, 255, 1), -- Large Termite Mound (Area: Plaguewood)
(@OGUID+47, 205559, 0, 1, 1, 3156.68, -3020.63, 130.025, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Plaguewood)
(@OGUID+48, 185563, 0, 1, 1, 3156.68, -3020.63, 130.025, 0, 0, 0, 0, 1, 120, 255, 1), -- Aura Trap Red Short (Area: Plaguewood)
(@OGUID+49, 177464, 0, 1, 1, 3044.733, -3030.824, 125.7536, 5.619962, 0, 0, 0, 1, 120, 255, 1), -- Large Termite Mound (Area: Plaguewood)
(@OGUID+50, 2047, 0, 1, 1, 2794.11, -2990.65, 108.285, 0.5585039, 0, 0, 0, 1, 120, 255, 1), -- Truesilver Deposit (Area: Plaguewood)
(@OGUID+51, 142142, 0, 1, 1, 2009.58, -2980.24, 77.7199, 2.391098, 0, 0, 0, 1, 120, 255, 1), -- Sungrass (Area: 0)
(@OGUID+52, 2043, 0, 1, 1, 1770.93, -2932.89, 74.8624, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: 0)
(@OGUID+53, 2041, 0, 1, 1, 1617.85, -2856.1, 52.5624, 0, 0, 0, 0, 1, 120, 255, 1), -- Liferoot (Area: 0)
(@OGUID+54, 2041, 0, 1, 1, 1470.94, -2944.86, 52.8104, 0, 0, 0, 0, 1, 120, 255, 1), -- Liferoot (Area: Death's Step)
(@OGUID+55, 142142, 0, 1, 1, 1608.09, -3051.32, 77.6844, 2.391098, 0, 0, 0, 1, 120, 255, 1), -- Sungrass (Area: Death's Step)
(@OGUID+56, 2043, 0, 1, 1, 1584.98, -3091.37, 80.0055, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: Death's Step)
(@OGUID+57, 2043, 0, 1, 1, 1741.32, -3079.58, 78.3206, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: Death's Step)
(@OGUID+58, 177464, 0, 1, 1, 3246.43, -3053.01, 159.172, 4.101525, 0, 0, 0, 1, 120, 255, 1), -- Large Termite Mound (Area: Plaguewood)
(@OGUID+59, 205560, 0, 1, 1, 3280.986, -3027.51, 136.6053, 3.752462, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Plaguewood)
(@OGUID+60, 205559, 0, 1, 1, 3290.94, -3042.34, 143.555, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Plaguewood)
(@OGUID+61, 185563, 0, 1, 1, 3290.94, -3042.34, 143.555, 0, 0, 0, 0, 1, 120, 255, 1), -- Aura Trap Red Short (Area: Plaguewood)
(@OGUID+62, 177464, 0, 1, 1, 3192.659, -3122.594, 158.035, 4.171338, 0, 0, 0, 1, 120, 255, 1), -- Large Termite Mound (Area: Plaguewood)
(@OGUID+63, 205560, 0, 1, 1, 3168.65, -3096.071, 152.0552, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Plaguewood)
(@OGUID+64, 205560, 0, 1, 1, 3282.61, -3136.91, 154.493, 3.839725, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Plaguewood)
(@OGUID+65, 205559, 0, 1, 1, 3188.57, -3064.31, 149.162, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Plaguewood)
(@OGUID+66, 185563, 0, 1, 1, 3188.57, -3064.31, 149.162, 0, 0, 0, 0, 1, 120, 255, 1), -- Aura Trap Red Short (Area: Plaguewood)
(@OGUID+67, 177464, 0, 1, 1, 3127.748, -3135.906, 160.2982, 0.3490652, 0, 0, 0, 1, 120, 255, 1), -- Large Termite Mound (Area: Plaguewood)
(@OGUID+68, 205559, 0, 1, 1, 3128.78, -3125, 157.923, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Plaguewood)
(@OGUID+69, 185563, 0, 1, 1, 3128.78, -3125, 157.923, 0, 0, 0, 0, 1, 120, 255, 1), -- Aura Trap Red Short (Area: Plaguewood)
(@OGUID+70, 177464, 0, 1, 1, 2964.189, -3105.646, 112.5486, 2.129301, 0, 0, 0, 1, 120, 255, 1), -- Large Termite Mound (Area: Plaguewood)
(@OGUID+71, 205560, 0, 1, 1, 3010.62, -3123.82, 116.098, 4.991644, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Plaguewood)
(@OGUID+72, 205560, 0, 1, 1, 3027.339, -3075.649, 121.2909, 0.8726639, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Plaguewood)
(@OGUID+73, 2043, 0, 1, 1, 2846.49, -3092.06, 102.594, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: Plaguewood Tower)
(@OGUID+74, 142142, 0, 1, 1, 2879.73, -3097.87, 106.239, 2.391098, 0, 0, 0, 1, 120, 255, 1), -- Sungrass (Area: Plaguewood Tower)
(@OGUID+75, 142142, 0, 1, 1, 2059.8, -3089.06, 76.3648, 2.391098, 0, 0, 0, 1, 120, 255, 1), -- Sungrass (Area: 0)
(@OGUID+76, 142142, 0, 1, 1, 1915.82, -3100.37, 87.0842, 2.391098, 0, 0, 0, 1, 120, 255, 1), -- Sungrass (Area: 0)
(@OGUID+77, 2041, 0, 1, 1, 1411.81, -3033.59, 52.6422, 0, 0, 0, 0, 1, 120, 255, 1), -- Liferoot (Area: Death's Step)
(@OGUID+78, 1735, 0, 1, 1, 1522.86, -2987.19, 93.9247, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: Death's Step)
(@OGUID+79, 1735, 0, 1, 1, 1659.07, -3155.52, 95.3171, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: Death's Step)
(@OGUID+80, 2043, 0, 1, 1, 1671, -3205.94, 78.6956, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: Death's Step)
(@OGUID+81, 176206, 0, 1, 1, 1865.95, -3186.98, 133.554, 5.637414, 0, 0, 0, 1, 120, 255, 1), -- Davil's Libram (Area: 0)
(@OGUID+82, 177045, 0, 1, 1, 1865.95, -3186.98, 133.554, 5.637414, 0, 0, 0, 1, 120, 255, 1), -- Haunted Trap (Area: 0)
(@OGUID+83, 176207, 0, 1, 1, 1872.34, -3180.18, 129.017, 5.113817, 0, 0, 0, 1, 120, 255, 1), -- Redpath's Shield (Area: 0)
(@OGUID+84, 177045, 0, 1, 1, 1872.34, -3180.18, 129.017, 5.113817, 0, 0, 0, 1, 120, 255, 1), -- Haunted Trap (Area: 0)
(@OGUID+85, 1735, 0, 1, 1, 1873.07, -3129.32, 122.589, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: 0)
(@OGUID+86, 2043, 0, 1, 1, 1923, -3147.14, 103.125, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: 0)
(@OGUID+87, 2043, 0, 1, 1, 2067.27, -3153.38, 75.0128, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: The Marris Stead)
(@OGUID+88, 205069, 0, 1, 1, 1753.977, -1182.723, 59.8408, 5.29176, 0, 0, 0, 1, 120, 255, 0), -- -Unknown- (Area: Plaguewood)
(@OGUID+89, 205559, 0, 1, 1, 2818.35, -3217.63, 125.425, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Plaguewood)
(@OGUID+90, 185563, 0, 1, 1, 2818.35, -3217.63, 125.425, 0, 0, 0, 0, 1, 120, 255, 1), -- Aura Trap Red Short (Area: Plaguewood)
(@OGUID+91, 205559, 0, 1, 1, 2795.34, -3195.73, 110.313, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Plaguewood)
(@OGUID+92, 185563, 0, 1, 1, 2795.34, -3195.73, 110.313, 0, 0, 0, 0, 1, 120, 255, 1), -- Aura Trap Red Short (Area: Plaguewood)
(@OGUID+93, 177464, 0, 1, 1, 2821.557, -3159.566, 114.9759, 6.056293, 0, 0, 0, 1, 120, 255, 1), -- Large Termite Mound (Area: Plaguewood)
(@OGUID+94, 205559, 0, 1, 1, 2832.7, -3145.67, 107.215, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Plaguewood)
(@OGUID+95, 185563, 0, 1, 1, 2832.7, -3145.67, 107.215, 0, 0, 0, 0, 1, 120, 255, 1), -- Aura Trap Red Short (Area: Plaguewood)
(@OGUID+96, 205559, 0, 1, 1, 2912.73, -3209.66, 121.384, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Plaguewood)
(@OGUID+97, 185563, 0, 1, 1, 2912.73, -3209.66, 121.384, 0, 0, 0, 0, 1, 120, 255, 1), -- Aura Trap Red Short (Area: Plaguewood)
(@OGUID+98, 205559, 0, 1, 1, 2885.93, -3192.09, 120.605, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Plaguewood)
(@OGUID+99, 185563, 0, 1, 1, 2885.93, -3192.09, 120.605, 0, 0, 0, 0, 1, 120, 255, 1), -- Aura Trap Red Short (Area: Plaguewood)
(@OGUID+100, 205560, 0, 1, 1, 3025.579, -3197.392, 144.6407, 3.735006, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Plaguewood)
(@OGUID+101, 205559, 0, 1, 1, 3024.34, -3148.52, 120.569, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Plaguewood)
(@OGUID+102, 185563, 0, 1, 1, 3024.34, -3148.52, 120.569, 0, 0, 0, 0, 1, 120, 255, 1), -- Aura Trap Red Short (Area: Plaguewood)
(@OGUID+103, 205560, 0, 1, 1, 3077.04, -3176.19, 140.888, 4.625124, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Plaguewood)
(@OGUID+104, 205560, 0, 1, 1, 3108.858, -3158.675, 145.2459, 3.036838, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Plaguewood)
(@OGUID+105, 205559, 0, 1, 1, 3111.38, -3195.47, 147.199, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Plaguewood)
(@OGUID+106, 185563, 0, 1, 1, 3111.38, -3195.47, 147.199, 0, 0, 0, 0, 1, 120, 255, 1), -- Aura Trap Red Short (Area: Plaguewood)
(@OGUID+107, 177464, 0, 1, 1, 3181.333, -3169.698, 157.3452, 4.81711, 0, 0, 0, 1, 120, 255, 1), -- Large Termite Mound (Area: Plaguewood)
(@OGUID+108, 205069, 0, 1, 1, 1802.753, -1167.844, 59.66285, 0.08142813, 0, 0, 0, 1, 120, 255, 0), -- -Unknown- (Area: Plaguewood)
(@OGUID+109, 205560, 0, 1, 1, 3270.48, -3225.52, 97.2751, 3.560473, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Stratholme)
(@OGUID+110, 180751, 0, 1, 1, 3228.08, -3228.33, 134.0684, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Floating Wreckage (Area: Stratholme)
(@OGUID+111, 205559, 0, 1, 1, 3169.55, -3271.58, 162.409, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Stratholme)
(@OGUID+112, 185563, 0, 1, 1, 3169.55, -3271.58, 162.409, 0, 0, 0, 0, 1, 120, 255, 1), -- Aura Trap Red Short (Area: Stratholme)
(@OGUID+113, 205560, 0, 1, 1, 3148.21, -3272.02, 157.251, 3.665196, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Stratholme)
(@OGUID+114, 205560, 0, 1, 1, 3170.142, -3283.313, 161.6167, 2.408554, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Stratholme)
(@OGUID+115, 205560, 0, 1, 1, 3062.08, -3226.65, 146.501, 4.76475, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Plaguewood)
(@OGUID+116, 205559, 0, 1, 1, 3058.05, -3277.06, 142.847, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Plaguewood)
(@OGUID+117, 185563, 0, 1, 1, 3058.05, -3277.06, 142.847, 0, 0, 0, 0, 1, 120, 255, 1), -- Aura Trap Red Short (Area: Plaguewood)
(@OGUID+118, 205559, 0, 1, 1, 2927.25, -3239.01, 124.483, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Plaguewood)
(@OGUID+119, 185563, 0, 1, 1, 2927.25, -3239.01, 124.483, 0, 0, 0, 0, 1, 120, 255, 1), -- Aura Trap Red Short (Area: Plaguewood)
(@OGUID+120, 177464, 0, 1, 1, 2963.689, -3288.087, 123.3345, 3.804818, 0, 0, 0, 1, 120, 255, 1), -- Large Termite Mound (Area: Plaguewood)
(@OGUID+121, 205559, 0, 1, 1, 3005.61, -3270.57, 134.671, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Plaguewood)
(@OGUID+122, 185563, 0, 1, 1, 3005.61, -3270.57, 134.671, 0, 0, 0, 0, 1, 120, 255, 1), -- Aura Trap Red Short (Area: Plaguewood)
(@OGUID+123, 205559, 0, 1, 1, 2969.72, -3235.23, 120.404, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Plaguewood)
(@OGUID+124, 185563, 0, 1, 1, 2969.72, -3235.23, 120.404, 0, 0, 0, 0, 1, 120, 255, 1), -- Aura Trap Red Short (Area: Plaguewood)
(@OGUID+125, 205559, 0, 1, 1, 2925.81, -3289.55, 123.777, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Plaguewood)
(@OGUID+126, 185563, 0, 1, 1, 2925.81, -3289.55, 123.777, 0, 0, 0, 0, 1, 120, 255, 1), -- Aura Trap Red Short (Area: Plaguewood)
(@OGUID+127, 177464, 0, 1, 1, 2861.421, -3295.476, 112.3822, 5.270896, 0, 0, 0, 1, 120, 255, 1), -- Large Termite Mound (Area: Plaguewood)
(@OGUID+128, 205559, 0, 1, 1, 2808.84, -3298.27, 99.0245, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Plaguewood)
(@OGUID+129, 185563, 0, 1, 1, 2808.84, -3298.27, 99.0245, 0, 0, 0, 0, 1, 120, 255, 1), -- Aura Trap Red Short (Area: Plaguewood)
(@OGUID+130, 205559, 0, 1, 1, 2861.99, -3299.36, 112.327, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Plaguewood)
(@OGUID+131, 185563, 0, 1, 1, 2861.99, -3299.36, 112.327, 0, 0, 0, 0, 1, 120, 255, 1), -- Aura Trap Red Short (Area: Plaguewood)
(@OGUID+132, 205558, 0, 1, 1, 2775.26, -3298.28, 97.63, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Plaguewood)
(@OGUID+133, 205560, 0, 1, 1, 2778.54, -3284.302, 97.01189, 0.6457717, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Plaguewood)
(@OGUID+134, 205069, 0, 1, 1, 1752.16, -1185.961, 60.06108, 0.8118481, 0, 0, 0, 1, 120, 255, 0), -- -Unknown- (Area: Plaguewood)
(@OGUID+135, 1735, 0, 1, 1, 2168.99, -3290.75, 139.621, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: 0)
(@OGUID+136, 142142, 0, 1, 1, 1562.45, -3242.25, 84.8463, 2.391098, 0, 0, 0, 1, 120, 255, 1), -- Sungrass (Area: 0)
(@OGUID+137, 177667, 0, 1, 1, 1600.306, -3241.304, 66.82944, 2.164206, 0, 0, 0, 1, 120, 255, 1), -- Torn Scroll (Area: 0)
(@OGUID+138, 1735, 0, 1, 1, 1520.13, -3286.54, 111.275, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: The Undercroft)
(@OGUID+139, 1735, 0, 1, 1, 1382.62, -3147.05, 126.42, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: The Undercroft)
(@OGUID+140, 205069, 0, 1, 1, 1788.57, -1247.667, 59.98154, 6.087371, 0, 0, 0, 1, 120, 255, 0), -- -Unknown- (Area: The Undercroft)
(@OGUID+141, 2043, 0, 1, 1, 1914.35, -3384.31, 109.316, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: The Marris Stead)
(@OGUID+142, 142142, 0, 1, 1, 2000.29, -3316.65, 105.225, 2.391098, 0, 0, 0, 1, 120, 255, 1), -- Sungrass (Area: The Marris Stead)
(@OGUID+143, 205560, 0, 1, 1, 2715.05, -3354.88, 93.9729, 0.087266, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+144, 2040, 0, 1, 1, 2689.55, -3319.55, 110.463, 0.5585039, 0, 0, 0, 1, 120, 255, 1), -- Mithril Deposit (Area: 0)
(@OGUID+145, 205069, 0, 1, 1, 1805.737, -1222.516, 65.18446, 6.089729, 0, 0, 0, 1, 120, 255, 0), -- -Unknown- (Area: Plaguewood)
(@OGUID+146, 205560, 0, 1, 1, 2734.27, -3312.88, 97.6493, 6.248279, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Plaguewood)
(@OGUID+147, 205560, 0, 1, 1, 2786.63, -3331.78, 96.8919, 0.03490625, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Plaguewood)
(@OGUID+148, 205560, 0, 1, 1, 2774.57, -3386.84, 93.2054, 0.2268925, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Plaguewood)
(@OGUID+149, 205560, 0, 1, 1, 2802.661, -3365.578, 94.89095, 0.2617982, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Plaguewood)
(@OGUID+150, 205560, 0, 1, 1, 2843.31, -3381.22, 95.4682, 0.2617982, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Plaguewood)
(@OGUID+151, 205560, 0, 1, 1, 2912.991, -3361.03, 113.2839, 2.251473, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Plaguewood)
(@OGUID+152, 205560, 0, 1, 1, 2855.774, -3351.583, 95.76959, 5.253442, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Plaguewood)
(@OGUID+153, 205560, 0, 1, 1, 2941.01, -3337.86, 115.32, 0.1396245, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Plaguewood)
(@OGUID+154, 205559, 0, 1, 1, 2912.89, -3315.7, 121.655, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Plaguewood)
(@OGUID+155, 185563, 0, 1, 1, 2912.89, -3315.7, 121.655, 0, 0, 0, 0, 1, 120, 255, 1), -- Aura Trap Red Short (Area: Plaguewood)
(@OGUID+156, 205559, 0, 1, 1, 2929.88, -3387.01, 117.916, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Plaguewood)
(@OGUID+157, 185563, 0, 1, 1, 2929.88, -3387.01, 117.916, 0, 0, 0, 0, 1, 120, 255, 1), -- Aura Trap Red Short (Area: Plaguewood)
(@OGUID+158, 177464, 0, 1, 1, 3009.174, -3350.52, 142.1717, 2.565632, 0, 0, 0, 1, 120, 255, 1), -- Large Termite Mound (Area: Plaguewood)
(@OGUID+159, 205559, 0, 1, 1, 3061.22, -3389.41, 156.484, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Plaguewood)
(@OGUID+160, 185563, 0, 1, 1, 3061.22, -3389.41, 156.484, 0, 0, 0, 0, 1, 120, 255, 1), -- Aura Trap Red Short (Area: Plaguewood)
(@OGUID+161, 176264, 0, 1, 1, 3079.737, -3369.215, 154.3593, 5.192355, 0, 0, 0, 1, 120, 255, 1), -- Campfire (Area: Plaguewood)
(@OGUID+162, 205560, 0, 1, 1, 3083.76, -3366.93, 154.348, 1.902409, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Plaguewood)
(@OGUID+163, 205560, 0, 1, 1, 3087.826, -3356.188, 154.1186, 5.881761, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Plaguewood)
(@OGUID+164, 205560, 0, 1, 1, 3174.96, -3353.59, 162.711, 2.82743, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Plaguewood)
(@OGUID+165, 205560, 0, 1, 1, 3151.195, -3346.726, 159.7918, 2.251473, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Plaguewood)
(@OGUID+166, 205560, 0, 1, 1, 3123.72, -3363.16, 140.745, 2.478367, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Plaguewood)
(@OGUID+167, 177464, 0, 1, 1, 3243.741, -3361.209, 145.9485, 1.954769, 0, 0, 0, 1, 120, 255, 1), -- Large Termite Mound (Area: Plaguewood)
(@OGUID+168, 178831, 0, 1, 1, 3372.45, -3379.63, 144.855, 3.036838, 0, 0, 0, 1, 120, 255, 1), -- Meeting Stone (Area: Plaguewood)
(@OGUID+169, 180684, 0, 1, 1, 3321.81, -3421.521, 134.0684, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Greater Sagefish School (Area: 0)
(@OGUID+170, 176967, 0, 1, 1, 3140.368, -3411.056, 141.1238, 4.991644, 0, 0, 0, 1, 120, 255, 1), -- Stratholme (Area: Stratholme)
(@OGUID+171, 176968, 0, 1, 1, 3140.328, -3410.997, 141.1247, 0.2792516, 0, 0, 0, 1, 120, 255, 1), -- Terrordale (Area: Stratholme)
(@OGUID+172, 176969, 0, 1, 1, 3140.267, -3411.106, 141.1197, 1.850049, 0, 0, 0, 1, 120, 255, 1), -- Quel'Thalas (Area: Stratholme)
(@OGUID+173, 205559, 0, 1, 1, 3094.59, -3407.86, 154.086, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Stratholme)
(@OGUID+174, 185563, 0, 1, 1, 3094.59, -3407.86, 154.086, 0, 0, 0, 0, 1, 120, 255, 1), -- Aura Trap Red Short (Area: Stratholme)
(@OGUID+175, 177464, 0, 1, 1, 3134.347, -3492.038, 156.3668, 6.230826, 0, 0, 0, 1, 120, 255, 1), -- Large Termite Mound (Area: Plaguewood)
(@OGUID+176, 177464, 0, 1, 1, 2938.066, -3422.842, 132.9545, 0.2617982, 0, 0, 0, 1, 120, 255, 1), -- Large Termite Mound (Area: Plaguewood)
(@OGUID+177, 205560, 0, 1, 1, 2903.35, -3447.94, 111.892, 0.6632232, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Plaguewood)
(@OGUID+178, 205560, 0, 1, 1, 2837.88, -3429.49, 98.6768, 0.4363316, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Plaguewood)
(@OGUID+179, 2043, 0, 1, 1, 1846.26, -3428.28, 115.514, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: 0)
(@OGUID+180, 2043, 0, 1, 1, 1666, -3437.26, 135.543, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: 0)
(@OGUID+181, 1735, 0, 1, 1, 1591.76, -3512.26, 148.613, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: The Undercroft)
(@OGUID+182, 176270, 0, 1, 1, 1856.118, -3492.389, 107.931, 2.914696, 0, 0, 0, 1, 120, 255, 1), -- Campfire (Area: 0)
(@OGUID+183, 142142, 0, 1, 1, 1921.86, -3495.51, 109.677, 2.391098, 0, 0, 0, 1, 120, 255, 1), -- Sungrass (Area: 0)
(@OGUID+184, 2040, 0, 1, 1, 2693.72, -3487.24, 118.664, 0.5585039, 0, 0, 0, 1, 120, 255, 1), -- Mithril Deposit (Area: Plaguewood)
(@OGUID+185, 177464, 0, 1, 1, 2926.1, -3489.136, 122.4023, 2.635444, 0, 0, 0, 1, 120, 255, 1), -- Large Termite Mound (Area: Plaguewood)
(@OGUID+186, 205560, 0, 1, 1, 2881.837, -3461.09, 105.6543, 2.897245, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Plaguewood)
(@OGUID+187, 205560, 0, 1, 1, 2993.81, -3489.59, 148.762, 1.151916, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Plaguewood)
(@OGUID+188, 177464, 0, 1, 1, 3186.208, -3561.964, 152.4808, 3.351047, 0, 0, 0, 1, 120, 255, 1), -- Large Termite Mound (Area: Stratholme)
(@OGUID+189, 142142, 0, 1, 1, 1625.62, -3544.52, 121.425, 2.391098, 0, 0, 0, 1, 120, 255, 1), -- Sungrass (Area: 0)
(@OGUID+190, 2043, 0, 1, 1, 1652.31, -3603.38, 115.678, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: 0)
(@OGUID+191, 176986, 0, 1, 1, 1751.618, -3623.342, 119.8351, 1.544616, 0, 0, 0, 1, 120, 255, 1), -- Darrowshire (Area: 0)
(@OGUID+192, 176983, 0, 1, 1, 1751.658, -3623.245, 119.8401, 6.257006, 0, 0, 0, 1, 120, 255, 1), -- Andorhal (Area: 0)
(@OGUID+193, 176985, 0, 1, 1, 1751.658, -3623.401, 118.5018, 3.115388, 0, 0, 0, 1, 120, 255, 1), -- Stratholme (Area: 0)
(@OGUID+194, 176984, 0, 1, 1, 1751.661, -3623.406, 119.8351, 3.115388, 0, 0, 0, 1, 120, 255, 1), -- Corin's Crossing (Area: 0)
(@OGUID+195, 2043, 0, 1, 1, 2044.01, -3583.06, 127.648, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: 0)
(@OGUID+196, 177464, 0, 1, 1, 2796.898, -3648.625, 102.8256, 3.438303, 0, 0, 0, 1, 120, 255, 1), -- Large Termite Mound (Area: Plaguewood)
(@OGUID+197, 177464, 0, 1, 1, 2857.617, -3656.353, 113.8584, 4.852017, 0, 0, 0, 1, 120, 255, 1), -- Large Termite Mound (Area: Plaguewood)
(@OGUID+198, 1735, 0, 1, 1, 2123.13, -3622.75, 164.528, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: 0)
(@OGUID+199, 177544, 0, 1, 1, 1461.955, -3586.533, 87.78445, 2.548179, 0, 0, 0, 1, 120, 255, 1), -- Joseph's Chest (Area: Darrowshire)
(@OGUID+200, 176116, 0, 1, 1, 1420.376, -3659.876, 82.01659, 2.740162, 0, 0, 0, 1, 120, 255, 1), -- Pamela's Doll's Head (Area: Darrowshire)
(@OGUID+201, 176143, 0, 1, 1, 1408.954, -3657.767, 82.01927, 5.742135, 0, 0, 0, 1, 120, 255, 1), -- Pamela's Doll's Right Side (Area: Darrowshire)
(@OGUID+202, 176116, 0, 1, 1, 1411.161, -3657.823, 77.69401, 4.677484, 0, 0, 0, 1, 120, 255, 1), -- Pamela's Doll's Head (Area: Darrowshire)
(@OGUID+203, 176142, 0, 1, 1, 1405.477, -3716.768, 78.17643, 2.583081, 0, 0, 0, 1, 120, 255, 1), -- Pamela's Doll's Left Side (Area: Darrowshire)
(@OGUID+204, 176143, 0, 1, 1, 1411.244, -3712.941, 78.17717, 1.623156, 0, 0, 0, 1, 120, 255, 1), -- Pamela's Doll's Right Side (Area: Darrowshire)
(@OGUID+205, 176142, 0, 1, 1, 1470.399, -3721.009, 80.51619, 2.984498, 0, 0, 0, 1, 120, 255, 1), -- Pamela's Doll's Left Side (Area: Darrowshire)
(@OGUID+206, 142142, 0, 1, 1, 2035.84, -3641.21, 129.008, 2.391098, 0, 0, 0, 1, 120, 255, 1), -- Sungrass (Area: 0)
(@OGUID+207, 176267, 0, 1, 1, 2474.816, -3706.066, 177.9334, 1.701696, 0, 0, 0, 1, 120, 255, 1), -- Campfire (Area: The Fungal Vale)
(@OGUID+208, 2040, 0, 1, 1, 2751.47, -3694.3, 115.519, 0.5585039, 0, 0, 0, 1, 120, 255, 1), -- Mithril Deposit (Area: Plaguewood)
(@OGUID+209, 2040, 0, 1, 1, 3350.45, -3751.22, 165.242, 0.5585039, 0, 0, 0, 1, 120, 255, 1), -- Mithril Deposit (Area: Plaguewood)
(@OGUID+210, 177464, 0, 1, 1, 3203.842, -3721.221, 147.6653, 4.590216, 0, 0, 0, 1, 120, 255, 1), -- Large Termite Mound (Area: Plaguewood)
(@OGUID+211, 177464, 0, 1, 1, 3031.232, -3730.522, 127.5464, 2.530723, 0, 0, 0, 1, 120, 255, 1), -- Large Termite Mound (Area: Plaguewood)
(@OGUID+212, 205873, 0, 1, 1, 1855.3, -3720.83, 195.68, 4.171338, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Crown Guard Tower)
(@OGUID+213, 2043, 0, 1, 1, 1670.66, -3741.62, 127.145, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: 0)
(@OGUID+214, 1735, 0, 1, 1, 1446.94, -3580.75, 94.9623, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: Darrowshire)
(@OGUID+215, 2043, 0, 1, 1, 2026.96, -3764.6, 132.366, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: Crown Guard Tower)
(@OGUID+216, 176208, 0, 1, 1, 2085.1, -3792.66, 133.376, 2.391098, 0, 0, 0, 1, 120, 255, 1), -- Horgus' Skull (Area: 0)
(@OGUID+217, 176591, 0, 1, 1, 2085.1, -3792.66, 133.376, 2.391098, 0, 0, 0, 1, 120, 255, 1), -- Horgus' Skull Trap (Area: 0)
(@OGUID+218, 176268, 0, 1, 1, 2498.448, -3768.597, 177.5054, 3.346658, 0, 0, 0, 1, 120, 255, 1), -- Campfire (Area: The Fungal Vale)
(@OGUID+219, 177464, 0, 1, 1, 2883.592, -3801.832, 110.205, 0.4014249, 0, 0, 0, 1, 120, 255, 1), -- Large Termite Mound (Area: Plaguewood)
(@OGUID+220, 177464, 0, 1, 1, 3266.841, -3792.71, 144.3743, 1.605702, 0, 0, 0, 1, 120, 255, 1), -- Large Termite Mound (Area: Plaguewood)
(@OGUID+221, 176266, 0, 1, 1, 2824.236, -3849.036, 106.1234, 1.509709, 0, 0, 0, 1, 120, 255, 1), -- Campfire (Area: Plaguewood)
(@OGUID+222, 204047, 0, 1, 1, -5520.566, 693.2934, 378.2548, 1.989672, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+223, 142142, 0, 1, 1, 1888.42, -3851.51, 132.899, 2.391098, 0, 0, 0, 1, 120, 255, 1), -- Sungrass (Area: Crown Guard Tower)
(@OGUID+224, 2043, 0, 1, 1, 1705.85, -3820.06, 128.56, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: Crown Guard Tower)
(@OGUID+225, 142142, 0, 1, 1, 1660.22, -3842.03, 132.227, 2.391098, 0, 0, 0, 1, 120, 255, 1), -- Sungrass (Area: 0)
(@OGUID+226, 1735, 0, 1, 1, 1375.49, -3823.97, 144.15, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: Darrowshire Hunting Grounds)
(@OGUID+227, 1735, 0, 1, 1, 1596.78, -3867.84, 137.844, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: Darrowshire Hunting Grounds)
(@OGUID+228, 204047, 0, 1, 1, -5520.566, 693.2934, 378.2548, 1.989672, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Darrowshire Hunting Grounds)
(@OGUID+229, 176209, 0, 1, 1, 1759.41, -3890.4, 130.023, 4.380776, 0, 0, 0, 1, 120, 255, 1), -- Shattered Sword of Marduk (Area: 0)
(@OGUID+230, 176865, 0, 1, 1, 1759.41, -3890.4, 130.023, 4.380776, 0, 0, 0, 1, 120, 255, 1), -- Sword of Marduk Trap (Area: 0)
(@OGUID+231, 142142, 0, 1, 1, 1807.88, -3878.81, 133.169, 2.391098, 0, 0, 0, 1, 120, 255, 1), -- Sungrass (Area: 0)
(@OGUID+232, 2043, 0, 1, 1, 1848.39, -3875.13, 132.698, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: 0)
(@OGUID+233, 176271, 0, 1, 1, 2100.83, -3943.714, 135.2994, 3.140142, 0, 0, 0, 1, 120, 255, 1), -- Campfire (Area: 0)
(@OGUID+234, 2043, 0, 1, 1, 2044.43, -3962.26, 125.631, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: 0)
(@OGUID+235, 1735, 0, 1, 1, 2182.64, -3872.93, 164.314, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: 0)
(@OGUID+236, 2040, 0, 1, 1, 2701.55, -3897.31, 118.449, 0.5585039, 0, 0, 0, 1, 120, 255, 1), -- Mithril Deposit (Area: The Fungal Vale)
(@OGUID+237, 177464, 0, 1, 1, 2767.117, -3909.49, 98.27149, 5.515242, 0, 0, 0, 1, 120, 255, 1), -- Large Termite Mound (Area: Plaguewood)
(@OGUID+238, 142142, 0, 1, 1, 2826.76, -3927.77, 104.877, 2.391098, 0, 0, 0, 1, 120, 255, 1), -- Sungrass (Area: Plaguewood)
(@OGUID+239, 177464, 0, 1, 1, 2921.298, -3961.481, 106.7239, 0.1745321, 0, 0, 0, 1, 120, 255, 1), -- Large Termite Mound (Area: Plaguewood)
(@OGUID+240, 177464, 0, 1, 1, 2947.861, -3876.887, 124.9997, 3.176533, 0, 0, 0, 1, 120, 255, 1), -- Large Termite Mound (Area: Plaguewood)
(@OGUID+241, 177464, 0, 1, 1, 3138.445, -3960.398, 111.758, 3.560473, 0, 0, 0, 1, 120, 255, 1), -- Large Termite Mound (Area: Plaguewood)
(@OGUID+242, 2040, 0, 1, 1, 3191.56, -3914.9, 135.412, 0.5585039, 0, 0, 0, 1, 120, 255, 1), -- Mithril Deposit (Area: Plaguewood)
(@OGUID+243, 175432, 0, 1, 1, 3191.097, -4044.288, 108.4226, 3.124123, 0, 0, 0.9999619, 0.008726474, 120, 255, 1), -- 175432 (Area: Plaguewood)
(@OGUID+244, 2043, 0, 1, 1, 3110.08, -4006.38, 105.785, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: Eastwall Gate)
(@OGUID+245, 2043, 0, 1, 1, 2832.37, -4037.27, 100.449, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: Plaguewood)
(@OGUID+246, 2043, 0, 1, 1, 2748.73, -3966.33, 98.5871, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: Plaguewood)
(@OGUID+247, 181134, 0, 1, 1, 2706.012, -4002.385, 92.13213, 3.450828, 0, 0, 0, 1, 120, 255, 1), -- Bonfire (Area: 0)
(@OGUID+248, 181135, 0, 1, 1, 2687.991, -4029.003, 92.78406, 2.051091, 0, 0, 0, 1, 120, 255, 1), -- Bonfire (Area: 0)
(@OGUID+249, 142142, 0, 1, 1, 2745.19, -4024.13, 96.5443, 2.391098, 0, 0, 0, 1, 120, 255, 1), -- Sungrass (Area: 0)
(@OGUID+250, 1734, 0, 1, 1, 2324.48, -3992.14, 149.376, 0, 0, 0, 0, 1, 120, 255, 1), -- Gold Vein (Area: 0)
(@OGUID+251, 1735, 0, 1, 1, 2011.45, -3996.58, 129.861, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: 0)
(@OGUID+252, 2043, 0, 1, 1, 1744.25, -4035.01, 118.335, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: 0)
(@OGUID+253, 1735, 0, 1, 1, 1559.3, -4095.44, 173.096, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: 0)
(@OGUID+254, 2043, 0, 1, 1, 2211.96, -4053.29, 87.2028, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: 0)
(@OGUID+255, 1735, 0, 1, 1, 2448.31, -4079.13, 84.3646, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: 0)
(@OGUID+256, 142142, 0, 1, 1, 2419.88, -4099.59, 75.2111, 2.391098, 0, 0, 0, 1, 120, 255, 1), -- Sungrass (Area: 0)
(@OGUID+257, 142142, 0, 1, 1, 3125.28, -4059.46, 101.487, 2.391098, 0, 0, 0, 1, 120, 255, 1), -- Sungrass (Area: Plaguewood)
(@OGUID+258, 2040, 0, 1, 1, 3173.81, -4132.43, 107.409, 0.5585039, 0, 0, 0, 1, 120, 255, 1), -- Mithril Deposit (Area: Eastwall Gate)
(@OGUID+259, 2043, 0, 1, 1, 3077.44, -4121.23, 96.8156, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: 0)
(@OGUID+260, 142142, 0, 1, 1, 2955.28, -4143.94, 94.9841, 2.391098, 0, 0, 0, 1, 120, 255, 1), -- Sungrass (Area: 0)
(@OGUID+261, 180751, 0, 1, 1, 2580.93, -4134.521, 72.77732, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Floating Wreckage (Area: Blackwood Lake)
(@OGUID+262, 180684, 0, 1, 1, 2438, -4142.88, 72.77731, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Greater Sagefish School (Area: Blackwood Lake)
(@OGUID+263, 180684, 0, 1, 1, 2008.17, -4118.55, 73.36741, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Greater Sagefish School (Area: 0)
(@OGUID+264, 204047, 0, 1, 1, -5520.566, 693.2934, 378.2548, 1.989672, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+265, 2041, 0, 1, 1, 1981.24, -4133.68, 73.365, 0, 0, 0, 0, 1, 120, 255, 1), -- Liferoot (Area: 0)
(@OGUID+266, 1735, 0, 1, 1, 1709.93, -4166.14, 116.166, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: 0)
(@OGUID+267, 2043, 0, 1, 1, 1783.58, -4150.7, 92.0548, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: 0)
(@OGUID+268, 142142, 0, 1, 1, 1818.41, -4180.37, 91.9427, 2.391098, 0, 0, 0, 1, 120, 255, 1), -- Sungrass (Area: 0)
(@OGUID+269, 180684, 0, 1, 1, 2061.75, -4182.141, 73.36741, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Greater Sagefish School (Area: The Infectis Scar)
(@OGUID+270, 180684, 0, 1, 1, 2070.33, -4230.87, 73.36741, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Greater Sagefish School (Area: The Infectis Scar)
(@OGUID+271, 2041, 0, 1, 1, 2074.28, -4240.97, 73.4336, 0, 0, 0, 0, 1, 120, 255, 1), -- Liferoot (Area: The Infectis Scar)
(@OGUID+272, 142142, 0, 1, 1, 2194.73, -4150.6, 80.698, 2.391098, 0, 0, 0, 1, 120, 255, 1), -- Sungrass (Area: The Infectis Scar)
(@OGUID+273, 2043, 0, 1, 1, 2350.9, -4192.07, 99.6487, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: 0)
(@OGUID+274, 180684, 0, 1, 1, 2506.36, -4212.149, 72.77732, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Greater Sagefish School (Area: Blackwood Lake)
(@OGUID+275, 2041, 0, 1, 1, 2594.73, -4159.68, 72.9891, 0, 0, 0, 0, 1, 120, 255, 1), -- Liferoot (Area: Blackwood Lake)
(@OGUID+276, 2043, 0, 1, 1, 2834.93, -4171.14, 92.8958, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: 0)
(@OGUID+277, 142142, 0, 1, 1, 2813.97, -4190.43, 92.3215, 2.391098, 0, 0, 0, 1, 120, 255, 1), -- Sungrass (Area: 0)
(@OGUID+278, 2043, 0, 1, 1, 3431.58, -4231.36, 160.09, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: Quel'Lithien Lodge)
(@OGUID+279, 2043, 0, 1, 1, 3212.68, -4245.4, 97.1221, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: Quel'Lithien Lodge)
(@OGUID+280, 2043, 0, 1, 1, 3002.48, -4275.97, 97.779, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: 0)
(@OGUID+281, 142142, 0, 1, 1, 2955.89, -4281.78, 89.2306, 2.391098, 0, 0, 0, 1, 120, 255, 1), -- Sungrass (Area: 0)
(@OGUID+282, 207488, 0, 1, 1, 2521.813, -4262.807, 74.98818, 2.35619, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Blackwood Lake)
(@OGUID+283, 1735, 0, 1, 1, 2242.1, -4247.66, 95.6474, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: 0)
(@OGUID+284, 206611, 0, 1, 1, 1892.92, -4267.36, 85.2244, 1.06465, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: The Infectis Scar)
(@OGUID+285, 1734, 0, 1, 1, 1648.66, -4359.17, 106.342, 0, 0, 0, 0, 1, 120, 255, 1), -- Gold Vein (Area: 0)
(@OGUID+286, 142142, 0, 1, 1, 1753.12, -4328.39, 74.6512, 2.391098, 0, 0, 0, 1, 120, 255, 1), -- Sungrass (Area: 0)
(@OGUID+287, 2043, 0, 1, 1, 1869.97, -4324.06, 89.789, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: 0)
(@OGUID+288, 180684, 0, 1, 1, 2572.97, -4305.17, 72.77732, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Greater Sagefish School (Area: Blackwood Lake)
(@OGUID+289, 2041, 0, 1, 1, 2580.44, -4309.24, 73.3113, 0, 0, 0, 0, 1, 120, 255, 1), -- Liferoot (Area: Blackwood Lake)
(@OGUID+290, 2040, 0, 1, 1, 2826.15, -4340.78, 104.969, 0.5585039, 0, 0, 0, 1, 120, 255, 1), -- Mithril Deposit (Area: 0)
(@OGUID+291, 2040, 0, 1, 1, 3333.19, -4422.38, 124.621, 0.5585039, 0, 0, 0, 1, 120, 255, 1), -- Mithril Deposit (Area: Quel'Lithien Lodge)
(@OGUID+292, 182058, 0, 1, 1, 3264.23, -4424.34, 109.3781, 4.677484, 0, 0, 0, 1, 120, 255, 1), -- Scourge Meat Wagon (Area: Quel'Lithien Lodge)
(@OGUID+293, 205873, 0, 1, 1, 3168.63, -4366.47, 173.691, 5.462882, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Quel'Lithien Lodge)
(@OGUID+294, 142142, 0, 1, 1, 2935.94, -4356.9, 92.586, 2.391098, 0, 0, 0, 1, 120, 255, 1), -- Sungrass (Area: 0)
(@OGUID+295, 176972, 0, 1, 1, 2849.628, -4406.452, 88.49287, 5.724679, 0, 0, 0, 1, 120, 255, 1), -- Stratholme (Area: 0)
(@OGUID+296, 176971, 0, 1, 1, 2849.657, -4406.569, 88.55173, 4.153885, 0, 0, 0, 1, 120, 255, 1), -- Quel'Thalas (Area: 0)
(@OGUID+297, 176970, 0, 1, 1, 2849.586, -4406.554, 88.49452, 2.583088, 0, 0, 0, 1, 120, 255, 1), -- Corin's Crossing (Area: 0)
(@OGUID+298, 176973, 0, 1, 1, 2849.58, -4406.559, 87.10559, 2.583088, 0, 0, 0, 1, 120, 255, 1), -- Tyr's Hand (Area: 0)
(@OGUID+299, 180684, 0, 1, 1, 2525.4, -4367.471, 72.77732, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Greater Sagefish School (Area: Blackwood Lake)
(@OGUID+300, 2041, 0, 1, 1, 2520.95, -4383.34, 72.9153, 0, 0, 0, 0, 1, 120, 255, 1), -- Liferoot (Area: Blackwood Lake)
(@OGUID+301, 2043, 0, 1, 1, 2474.77, -4371.58, 77.2548, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: Blackwood Lake)
(@OGUID+302, 180684, 0, 1, 1, 2063.25, -4388.71, 73.36741, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Greater Sagefish School (Area: The Infectis Scar)
(@OGUID+303, 204047, 0, 1, 1, -5520.566, 693.2934, 378.2548, 1.989672, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: The Infectis Scar)
(@OGUID+304, 2041, 0, 1, 1, 2007.3, -4401.33, 72.6852, 0, 0, 0, 0, 1, 120, 255, 1), -- Liferoot (Area: The Infectis Scar)
(@OGUID+305, 2041, 0, 1, 1, 1935.84, -4402.59, 73.0917, 0, 0, 0, 0, 1, 120, 255, 1), -- Liferoot (Area: The Infectis Scar)
(@OGUID+306, 204047, 0, 1, 1, -5520.566, 693.2934, 378.2548, 1.989672, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Lake Mereldar)
(@OGUID+307, 2041, 0, 1, 1, 2110.65, -4420.22, 73.5564, 0, 0, 0, 0, 1, 120, 255, 1), -- Liferoot (Area: The Infectis Scar)
(@OGUID+308, 23013, 0, 1, 1, 2251.938, -4459.084, 114.302, 1.082103, 0, 0, 0.7716247, 0.6360781, 120, 255, 1), -- Wooden Chair (Area: Light's Shield Tower)
(@OGUID+309, 23014, 0, 1, 1, 2254.869, -4460.814, 114.302, 1.719148, 0, 0, 0.7716247, 0.6360781, 120, 255, 1), -- Wooden Chair (Area: Light's Shield Tower)
(@OGUID+310, 205873, 0, 1, 1, 2256.4, -4451.18, 149.385, 0.3141584, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Light's Shield Tower)
(@OGUID+311, 23015, 0, 1, 1, 2267.839, -4450.198, 114.2714, 3.900813, 0, 0, 0.7716247, 0.6360781, 120, 255, 1), -- Wooden Chair (Area: Light's Shield Tower)
(@OGUID+312, 142142, 0, 1, 1, 2428.14, -4432.8, 73.9032, 2.391098, 0, 0, 0, 1, 120, 255, 1), -- Sungrass (Area: Light's Shield Tower)
(@OGUID+313, 180684, 0, 1, 1, 2478.189, -4455.309, 72.77732, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Greater Sagefish School (Area: 0)
(@OGUID+314, 204047, 0, 1, 1, -5520.566, 693.2934, 378.2548, 1.989672, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+315, 182058, 0, 1, 1, 3247.55, -4444.271, 110.8212, 4.991644, 0, 0, 0, 1, 120, 255, 1), -- Scourge Meat Wagon (Area: Northpass Tower)
(@OGUID+316, 182058, 0, 1, 1, 3285.44, -4442.38, 107.5021, 4.433136, 0, 0, 0, 1, 120, 255, 1), -- Scourge Meat Wagon (Area: Northpass Tower)
(@OGUID+317, 182058, 0, 1, 1, 3270.203, -4513.788, 108.1802, 2.321287, 0, 0, 0, 1, 120, 255, 1), -- Scourge Meat Wagon (Area: 0)
(@OGUID+318, 2040, 0, 1, 1, 3249.72, -4503.51, 113.675, 0.5585039, 0, 0, 0, 1, 120, 255, 1), -- Mithril Deposit (Area: 0)
(@OGUID+319, 182059, 0, 1, 1, 3247.726, -4534.92, 107.5839, 4.171338, 0, 0, 0, 1, 120, 255, 1), -- Campfire (Area: Siege Vise)
(@OGUID+320, 182058, 0, 1, 1, 3238.048, -4558.335, 106.2607, 1.221729, 0, 0, 0, 1, 120, 255, 1), -- Scourge Meat Wagon (Area: Siege Vise)
(@OGUID+321, 182058, 0, 1, 1, 3204.198, -4557.83, 107.2911, 0.6108634, 0, 0, 0, 1, 120, 255, 1), -- Scourge Meat Wagon (Area: Siege Vise)
(@OGUID+322, 182058, 0, 1, 1, 3194.654, -4526.075, 109.524, 0.5934101, 0, 0, 0, 1, 120, 255, 1), -- Scourge Meat Wagon (Area: Siege Vise)
(@OGUID+323, 2043, 0, 1, 1, 3179.97, -4482.4, 113.005, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: Siege Vise)
(@OGUID+324, 182058, 0, 1, 1, 3227.123, -4495.474, 111.5535, 0.6283169, 0, 0, 0, 1, 120, 255, 1), -- Scourge Meat Wagon (Area: Siege Vise)
(@OGUID+325, 2040, 0, 1, 1, 2879.14, -4526.51, 99.8327, 0.5585039, 0, 0, 0, 1, 120, 255, 1), -- Mithril Deposit (Area: 0)
(@OGUID+326, 176978, 0, 1, 1, 2046.415, -4509.188, 73.70333, 3.996807, 0, 0, 0, 1, 120, 255, 1), -- Quel'Thalas (Area: Light's Shield Tower)
(@OGUID+327, 176981, 0, 1, 1, 2046.288, -4509.087, 73.71004, 0.8552105, 0, 0, 0, 1, 120, 255, 1), -- Darrowshire (Area: Light's Shield Tower)
(@OGUID+328, 176980, 0, 1, 1, 2046.337, -4509.181, 73.70584, 2.426008, 0, 0, 0, 1, 120, 255, 1), -- Tyr's Hand (Area: Light's Shield Tower)
(@OGUID+329, 176979, 0, 1, 1, 2046.408, -4509.188, 72.37017, 3.996807, 0, 0, 0, 1, 120, 255, 1), -- Stratholme (Area: Light's Shield Tower)
(@OGUID+330, 176982, 0, 1, 1, 2046.281, -4509.087, 72.37688, 0.8552105, 0, 0, 0, 1, 120, 255, 1), -- Andorhal (Area: Light's Shield Tower)
(@OGUID+331, 204047, 0, 1, 1, -5520.566, 693.2934, 378.2548, 1.989672, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Corin's Crossing)
(@OGUID+332, 180684, 0, 1, 1, 1728.21, -4464.87, 73.3674, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Greater Sagefish School (Area: Corin's Crossing)
(@OGUID+333, 2041, 0, 1, 1, 1670.37, -4499.05, 73.502, 0, 0, 0, 0, 1, 120, 255, 1), -- Liferoot (Area: Lake Mereldar)
(@OGUID+334, 2043, 0, 1, 1, 1641.65, -4481.72, 80.4836, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: Lake Mereldar)
(@OGUID+335, 1734, 0, 1, 1, 1572.67, -4547.46, 94.4748, 0, 0, 0, 0, 1, 120, 255, 1), -- Gold Vein (Area: Lake Mereldar)
(@OGUID+336, 2041, 0, 1, 1, 1714.97, -4557.08, 73.9765, 0, 0, 0, 0, 1, 120, 255, 1), -- Liferoot (Area: Lake Mereldar)
(@OGUID+337, 180684, 0, 1, 1, 1824.41, -4533.41, 73.36741, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Greater Sagefish School (Area: Lake Mereldar)
(@OGUID+338, 2043, 0, 1, 1, 2342.57, -4565.73, 75.001, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: Light's Shield Tower)
(@OGUID+339, 2041, 0, 1, 1, 2473.36, -4579.03, 72.7329, 0, 0, 0, 0, 1, 120, 255, 1), -- Liferoot (Area: 0)
(@OGUID+340, 142142, 0, 1, 1, 2743.68, -4579.4, 89.0161, 2.391098, 0, 0, 0, 1, 120, 255, 1), -- Sungrass (Area: 0)
(@OGUID+341, 2040, 0, 1, 1, 2787.76, -4584.12, 109.464, 0.5585039, 0, 0, 0, 1, 120, 255, 1), -- Mithril Deposit (Area: 0)
(@OGUID+342, 2043, 0, 1, 1, 2918.05, -4574.16, 93.7889, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: 0)
(@OGUID+343, 142142, 0, 1, 1, 2949.18, -4573.15, 73.983, 2.391098, 0, 0, 0, 1, 120, 255, 1), -- Sungrass (Area: 0)
(@OGUID+344, 2040, 0, 1, 1, 3040.1, -4595.1, 128.005, 0.5585039, 0, 0, 0, 1, 120, 255, 1), -- Mithril Deposit (Area: 0)
(@OGUID+345, 182059, 0, 1, 1, 3222.391, -4567.55, 109.8067, 2.303831, 0, 0, 0, 1, 120, 255, 1), -- Campfire (Area: 0)
(@OGUID+346, 2040, 0, 1, 1, 3249.76, -4581.43, 113.255, 0.5585039, 0, 0, 0, 1, 120, 255, 1), -- Mithril Deposit (Area: 0)
(@OGUID+347, 2040, 0, 1, 1, 2972.07, -4679.06, 108.134, 0.5585039, 0, 0, 0, 1, 120, 255, 1), -- Mithril Deposit (Area: 0)
(@OGUID+348, 2043, 0, 1, 1, 2806.04, -4615.13, 91.1473, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: 0)
(@OGUID+349, 142142, 0, 1, 1, 2528.96, -4613.38, 78.0534, 2.391098, 0, 0, 0, 1, 120, 255, 1), -- Sungrass (Area: 0)
(@OGUID+350, 142142, 0, 1, 1, 2341.37, -4662.72, 75.9911, 2.391098, 0, 0, 0, 1, 120, 255, 1), -- Sungrass (Area: 0)
(@OGUID+351, 2043, 0, 1, 1, 1964.96, -4654, 86.1204, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: Corin's Crossing)
(@OGUID+352, 180684, 0, 1, 1, 1788.62, -4599.66, 73.36739, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Greater Sagefish School (Area: Corin's Crossing)
(@OGUID+353, 2041, 0, 1, 1, 1784.5, -4631.9, 73.5111, 0, 0, 0, 0, 1, 120, 255, 1), -- Liferoot (Area: Corin's Crossing)
(@OGUID+354, 1735, 0, 1, 1, 1475.63, -4660.53, 119.203, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: Lake Mereldar)
(@OGUID+355, 2043, 0, 1, 1, 1577.2, -4675.95, 82.6708, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: Lake Mereldar)
(@OGUID+356, 2041, 0, 1, 1, 1631.86, -4660.52, 73.3819, 0, 0, 0, 0, 1, 120, 255, 1), -- Liferoot (Area: Lake Mereldar)
(@OGUID+357, 2041, 0, 1, 1, 1752.45, -4720.64, 73.5973, 0, 0, 0, 0, 1, 120, 255, 1), -- Liferoot (Area: Lake Mereldar)
(@OGUID+358, 142142, 0, 1, 1, 1817.55, -4716.2, 87.4794, 2.391098, 0, 0, 0, 1, 120, 255, 1), -- Sungrass (Area: Lake Mereldar)
(@OGUID+359, 142142, 0, 1, 1, 2052.14, -4694.58, 80.4356, 2.391098, 0, 0, 0, 1, 120, 255, 1), -- Sungrass (Area: Corin's Crossing)
(@OGUID+360, 2043, 0, 1, 1, 2123.81, -4748.01, 74.2462, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: Corin's Crossing)
(@OGUID+361, 180684, 0, 1, 1, 2423.979, -4705.2, 72.77732, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Greater Sagefish School (Area: 0)
(@OGUID+362, 2043, 0, 1, 1, 2765.53, -4702.88, 78.2992, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: 0)
(@OGUID+363, 20969, 0, 1, 1, 2821.234, -4738.76, 75.57855, 1.762782, 0, 0, 0, 1, 120, 255, 1), -- Scourge Campfire (Area: Ix'lar's Domain)
(@OGUID+364, 2043, 0, 1, 1, 3111.59, -4711.92, 97.7551, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: 0)
(@OGUID+365, 142142, 0, 1, 1, 3083.26, -4754.84, 97.8077, 2.391098, 0, 0, 0, 1, 120, 255, 1), -- Sungrass (Area: 0)
(@OGUID+366, 2040, 0, 1, 1, 3137.18, -4754.92, 104.57, 0.5585039, 0, 0, 0, 1, 120, 255, 1), -- Mithril Deposit (Area: 0)
(@OGUID+367, 204806, 0, 1, 1, 3221.81, -4726.02, 155.156, 3.141757, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Zul'Mashar)
(@OGUID+368, 177677, 0, 1, 1, 3277.92, -4865.96, 171.5243, 0.4886912, 0, 0, 0, 1, 120, 255, 1), -- Shallow Grave (Area: Zul'Mashar)
(@OGUID+369, 177677, 0, 1, 1, 3278.18, -4860.33, 171.4189, 0.4886912, 0, 0, 0, 1, 120, 255, 1), -- Shallow Grave (Area: Zul'Mashar)
(@OGUID+370, 177677, 0, 1, 1, 3267.63, -4832.601, 173.2034, 1.727875, 0, 0, 0, 1, 120, 255, 1), -- Shallow Grave (Area: Zul'Mashar)
(@OGUID+371, 177677, 0, 1, 1, 3285.78, -4868.87, 171.6172, 0.4886912, 0, 0, 0, 1, 120, 255, 1), -- Shallow Grave (Area: Zul'Mashar)
(@OGUID+372, 177677, 0, 1, 1, 3272.72, -4835.231, 172.0394, 5.270896, 0, 0, 0, 1, 120, 255, 1), -- Shallow Grave (Area: Zul'Mashar)
(@OGUID+373, 177677, 0, 1, 1, 3282.34, -4863.81, 171.325, 5.253442, 0, 0, 0, 1, 120, 255, 1), -- Shallow Grave (Area: Zul'Mashar)
(@OGUID+374, 177677, 0, 1, 1, 3378.92, -4878.1, 159.341, 3.700105, 0, 0, 0, 1, 120, 255, 1), -- Shallow Grave (Area: Zul'Mashar)
(@OGUID+375, 177677, 0, 1, 1, 3373.52, -4875.88, 159.259, 2.897245, 0, 0, 0, 1, 120, 255, 1), -- Shallow Grave (Area: Zul'Mashar)
(@OGUID+376, 177677, 0, 1, 1, 3350.61, -4838.97, 168.145, 0.4886912, 0, 0, 0, 1, 120, 255, 1), -- Shallow Grave (Area: Zul'Mashar)
(@OGUID+377, 177677, 0, 1, 1, 3345.59, -4842.74, 167.2001, 5.270896, 0, 0, 0, 1, 120, 255, 1), -- Shallow Grave (Area: Zul'Mashar)
(@OGUID+378, 177677, 0, 1, 1, 3353.63, -4840.67, 167.818, 0.4886912, 0, 0, 0, 1, 120, 255, 1), -- Shallow Grave (Area: Zul'Mashar)
(@OGUID+379, 177677, 0, 1, 1, 3344.48, -4839.16, 167.7759, 3.298687, 0, 0, 0, 1, 120, 255, 1), -- Shallow Grave (Area: Zul'Mashar)
(@OGUID+380, 177677, 0, 1, 1, 3351, -4844.924, 167.3035, 0.2443456, 0, 0, 0, 1, 120, 255, 1), -- Shallow Grave (Area: Zul'Mashar)
(@OGUID+381, 177677, 0, 1, 1, 3280.43, -4869.08, 171.337, 5.969027, 0, 0, 0, 1, 120, 255, 1), -- Shallow Grave (Area: Zul'Mashar)
(@OGUID+382, 2043, 0, 1, 1, 2958.51, -4781.56, 95.1922, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: 0)
(@OGUID+383, 142142, 0, 1, 1, 2946.38, -4840.93, 103.577, 2.391098, 0, 0, 0, 1, 120, 255, 1), -- Sungrass (Area: 0)
(@OGUID+384, 2040, 0, 1, 1, 2848.59, -4790.26, 102.986, 0.5585039, 0, 0, 0, 1, 120, 255, 1), -- Mithril Deposit (Area: 0)
(@OGUID+385, 20970, 0, 1, 1, 2783.285, -4814.726, 80.58518, 3.141088, 0, 0, 0, 1, 120, 255, 1), -- Bubbling Cauldron (Area: Ix'lar's Domain)
(@OGUID+386, 23013, 0, 1, 1, 2557.164, -4804.887, 108.8308, 1.675514, 0, 0, 0.9238795, 0.3826836, 120, 255, 1), -- Wooden Chair (Area: Eastwall Tower)
(@OGUID+387, 23014, 0, 1, 1, 2560.562, -4804.682, 108.8308, 2.312558, 0, 0, 0.9238795, 0.3826836, 120, 255, 1), -- Wooden Chair (Area: Eastwall Tower)
(@OGUID+388, 23015, 0, 1, 1, 2565.377, -4788.628, 108.8002, 4.494224, 0, 0, 0.9238795, 0.3826836, 120, 255, 1), -- Wooden Chair (Area: Eastwall Tower)
(@OGUID+389, 205873, 0, 1, 1, 2564.89, -4790.05, 143.915, 3.368496, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Eastwall Tower)
(@OGUID+390, 2041, 0, 1, 1, 2395.04, -4815.93, 73.0844, 0, 0, 0, 0, 1, 120, 255, 1), -- Liferoot (Area: Eastwall Tower)
(@OGUID+391, 1735, 0, 1, 1, 1961.45, -4785.07, 105.843, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: 0)
(@OGUID+392, 142142, 0, 1, 1, 1934.16, -4767.19, 97.018, 2.391098, 0, 0, 0, 1, 120, 255, 1), -- Sungrass (Area: 0)
(@OGUID+393, 2043, 0, 1, 1, 1857.79, -4744.17, 102.455, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: 0)
(@OGUID+394, 205485, 0, 1, 1, 1649.46, -4808.43, 84.5487, 1.500983, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Lake Mereldar)
(@OGUID+395, 2043, 0, 1, 1, 1704.29, -4818.3, 89.603, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: Lake Mereldar)
(@OGUID+396, 1735, 0, 1, 1, 1581, -4775.35, 101.311, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: Death Cultist Base Camp)
(@OGUID+397, 1735, 0, 1, 1, 1565.89, -4744.19, 107.195, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: Death Cultist Base Camp)
(@OGUID+398, 142142, 0, 1, 1, 1829.28, -4903.65, 82.6592, 2.391098, 0, 0, 0, 1, 120, 255, 1), -- Sungrass (Area: 0)
(@OGUID+399, 2043, 0, 1, 1, 1920.09, -4897.98, 87.1979, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: 0)
(@OGUID+400, 142142, 0, 1, 1, 2277.17, -4885.15, 103.306, 2.391098, 0, 0, 0, 1, 120, 255, 1), -- Sungrass (Area: 0)
(@OGUID+401, 180684, 0, 1, 1, 2422.91, -4895.601, 72.77731, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Greater Sagefish School (Area: 0)
(@OGUID+402, 2043, 0, 1, 1, 2743.7, -4879.16, 88.6447, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: Eastwall Tower)
(@OGUID+403, 142142, 0, 1, 1, 3019.55, -4863.95, 100.517, 2.391098, 0, 0, 0, 1, 120, 255, 1), -- Sungrass (Area: 0)
(@OGUID+404, 2040, 0, 1, 1, 3128.48, -4883.02, 111.28, 0.5585039, 0, 0, 0, 1, 120, 255, 1), -- Mithril Deposit (Area: 0)
(@OGUID+405, 177677, 0, 1, 1, 3369.511, -4894.123, 159.4749, 0.4886912, 0, 0, 0, 1, 120, 255, 1), -- Shallow Grave (Area: Zul'Mashar)
(@OGUID+406, 177677, 0, 1, 1, 3361.99, -4896.87, 159.2651, 4.084071, 0, 0, 0, 1, 120, 255, 1), -- Shallow Grave (Area: Zul'Mashar)
(@OGUID+407, 177677, 0, 1, 1, 3356.576, -4902.105, 159.2525, 5.846854, 0, 0, 0, 1, 120, 255, 1), -- Shallow Grave (Area: Zul'Mashar)
(@OGUID+408, 204808, 0, 1, 1, 3416.14, -4896.74, 159.436, 3.097919, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Zul'Mashar)
(@OGUID+409, 204809, 0, 1, 1, 3410.01, -4901.96, 159.395, 0.5846839, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Zul'Mashar)
(@OGUID+410, 177677, 0, 1, 1, 3382.57, -4902.557, 159.4351, 4.136433, 0, 0, 0, 1, 120, 255, 1), -- Shallow Grave (Area: Zul'Mashar)
(@OGUID+411, 177677, 0, 1, 1, 3377.681, -4896.83, 159.6269, 2.199115, 0, 0, 0, 1, 120, 255, 1), -- Shallow Grave (Area: Zul'Mashar)
(@OGUID+412, 177677, 0, 1, 1, 3382.555, -4907.502, 159.3051, 5.166176, 0, 0, 0, 1, 120, 255, 1), -- Shallow Grave (Area: Zul'Mashar)
(@OGUID+413, 177677, 0, 1, 1, 3401.87, -4932.51, 162.2298, 1.361356, 0, 0, 0, 1, 120, 255, 1), -- Shallow Grave (Area: Zul'Mashar)
(@OGUID+414, 177677, 0, 1, 1, 3375.494, -4903.446, 159.4044, 4.677484, 0, 0, 0, 1, 120, 255, 1), -- Shallow Grave (Area: Zul'Mashar)
(@OGUID+415, 177677, 0, 1, 1, 3376.406, -4909.342, 159.3565, 4.97419, 0, 0, 0, 1, 120, 255, 1), -- Shallow Grave (Area: Zul'Mashar)
(@OGUID+416, 177677, 0, 1, 1, 3368.923, -4900.827, 159.3568, 0.6806767, 0, 0, 0, 1, 120, 255, 1), -- Shallow Grave (Area: Zul'Mashar)
(@OGUID+417, 177677, 0, 1, 1, 3370.237, -4906.313, 159.3359, 3.38594, 0, 0, 0, 1, 120, 255, 1), -- Shallow Grave (Area: Zul'Mashar)
(@OGUID+418, 177677, 0, 1, 1, 3372.383, -4914.282, 159.5627, 3.68265, 0, 0, 0, 1, 120, 255, 1), -- Shallow Grave (Area: Zul'Mashar)
(@OGUID+419, 177677, 0, 1, 1, 3362.451, -4904.236, 159.2532, 4.276057, 0, 0, 0, 1, 120, 255, 1), -- Shallow Grave (Area: Zul'Mashar)
(@OGUID+420, 177677, 0, 1, 1, 3364.354, -4909.323, 159.3664, 6.126106, 0, 0, 0, 1, 120, 255, 1), -- Shallow Grave (Area: Zul'Mashar)
(@OGUID+421, 177677, 0, 1, 1, 3367.075, -4921.178, 159.6937, 2.775069, 0, 0, 0, 1, 120, 255, 1), -- Shallow Grave (Area: Zul'Mashar)
(@OGUID+422, 177677, 0, 1, 1, 3362.062, -4915.014, 159.4607, 0.4712385, 0, 0, 0, 1, 120, 255, 1), -- Shallow Grave (Area: Zul'Mashar)
(@OGUID+423, 177677, 0, 1, 1, 3358.504, -4910.049, 159.3081, 1.954769, 0, 0, 0, 1, 120, 255, 1), -- Shallow Grave (Area: Zul'Mashar)
(@OGUID+424, 177677, 0, 1, 1, 3359.728, -4920.112, 159.4541, 4.031712, 0, 0, 0, 1, 120, 255, 1), -- Shallow Grave (Area: Zul'Mashar)
(@OGUID+425, 177677, 0, 1, 1, 3355.937, -4915.083, 159.3268, 0.802851, 0, 0, 0, 1, 120, 255, 1), -- Shallow Grave (Area: Zul'Mashar)
(@OGUID+426, 177677, 0, 1, 1, 3352.439, -4907.719, 159.2525, 2.565632, 0, 0, 0, 1, 120, 255, 1), -- Shallow Grave (Area: Zul'Mashar)
(@OGUID+427, 177677, 0, 1, 1, 3334.09, -4913.54, 159.419, 2.984498, 0, 0, 0, 1, 120, 255, 1), -- Shallow Grave (Area: Zul'Mashar)
(@OGUID+428, 177677, 0, 1, 1, 3332.8, -4918.53, 159.713, 2.199115, 0, 0, 0, 1, 120, 255, 1), -- Shallow Grave (Area: Zul'Mashar)
(@OGUID+429, 204810, 0, 1, 1, 3360.29, -4957, 159.652, 3.324856, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Zul'Mashar)
(@OGUID+430, 205537, 0, 1, 1, 3047.88, -4927.22, 102.744, 3.368496, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Northdale)
(@OGUID+431, 180684, 0, 1, 1, 2977.64, -4913.58, 104.6275, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Greater Sagefish School (Area: Northdale)
(@OGUID+432, 2041, 0, 1, 1, 2990.43, -4923.42, 104.636, 0, 0, 0, 0, 1, 120, 255, 1), -- Liferoot (Area: Northdale)
(@OGUID+433, 2041, 0, 1, 1, 2946.88, -4918.52, 105.218, 0, 0, 0, 0, 1, 120, 255, 1), -- Liferoot (Area: Northdale)
(@OGUID+434, 142142, 0, 1, 1, 2566.82, -4913.01, 74.7708, 2.391098, 0, 0, 0, 1, 120, 255, 1), -- Sungrass (Area: Eastwall Tower)
(@OGUID+435, 142142, 0, 1, 1, 1724.58, -4908.92, 90.5346, 2.391098, 0, 0, 0, 1, 120, 255, 1), -- Sungrass (Area: 0)
(@OGUID+436, 142142, 0, 1, 1, 1857.07, -4967.18, 85.3856, 2.391098, 0, 0, 0, 1, 120, 255, 1), -- Sungrass (Area: Death Cultist Base Camp)
(@OGUID+437, 180684, 0, 1, 1, 2236.04, -4987.34, 71.01295, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Greater Sagefish School (Area: 0)
(@OGUID+438, 2041, 0, 1, 1, 2237.47, -4980.34, 71.4211, 0, 0, 0, 0, 1, 120, 255, 1), -- Liferoot (Area: 0)
(@OGUID+439, 176269, 0, 1, 1, 2290.997, -4980.327, 73.80159, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Bonfire (Area: 0)
(@OGUID+440, 2043, 0, 1, 1, 2295.4, -4957.15, 76.918, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: 0)
(@OGUID+441, 2041, 0, 1, 1, 2432.95, -4978.37, 73.2973, 0, 0, 0, 0, 1, 120, 255, 1), -- Liferoot (Area: 0)
(@OGUID+442, 180684, 0, 1, 1, 2446.01, -4987.191, 72.77732, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Greater Sagefish School (Area: Eastwall Tower)
(@OGUID+443, 2043, 0, 1, 1, 2501.86, -4958.11, 82.6011, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: Eastwall Tower)
(@OGUID+444, 2040, 0, 1, 1, 2627.61, -4946.59, 94.2239, 0.5585039, 0, 0, 0, 1, 120, 255, 1), -- Mithril Deposit (Area: Eastwall Tower)
(@OGUID+445, 142142, 0, 1, 1, 2750.97, -4976.83, 92.0545, 2.391098, 0, 0, 0, 1, 120, 255, 1), -- Sungrass (Area: 0)
(@OGUID+446, 177264, 0, 1, 1, 2923.076, -4946.413, 95.16249, 3.281241, 0, 0, 0, 1, 120, 255, 1), -- Symbol of Lost Honor (Area: Northdale)
(@OGUID+447, 2041, 0, 1, 1, 2865.05, -5003.1, 104.657, 0, 0, 0, 0, 1, 120, 255, 1), -- Liferoot (Area: Northdale)
(@OGUID+448, 207488, 0, 1, 1, 3024.362, -4981.207, 106.6561, 1.658062, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Northdale)
(@OGUID+449, 2043, 0, 1, 1, 3063.8, -4964.46, 101.662, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: Northdale)
(@OGUID+450, 204807, 0, 1, 1, 3464.21, -5005.53, 202.479, 2.687807, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Zul'Mashar)
(@OGUID+451, 177677, 0, 1, 1, 3367.57, -4989.38, 159.402, 0.4886912, 0, 0, 0, 1, 120, 255, 1), -- Shallow Grave (Area: Zul'Mashar)
(@OGUID+452, 177677, 0, 1, 1, 3367.17, -4993.85, 159.382, 0.4886912, 0, 0, 0, 1, 120, 255, 1), -- Shallow Grave (Area: Zul'Mashar)
(@OGUID+453, 177677, 0, 1, 1, 3366.2, -4998.53, 159.262, 3.159062, 0, 0, 0, 1, 120, 255, 1), -- Shallow Grave (Area: Zul'Mashar)
(@OGUID+454, 2043, 0, 1, 1, 2792.03, -5004.68, 96.9397, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: Northdale)
(@OGUID+455, 2043, 0, 1, 1, 1693.32, -5044.46, 81.3833, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: 0)
(@OGUID+456, 1735, 0, 1, 1, 1622.44, -5065.17, 81.4554, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: 0)
(@OGUID+457, 2043, 0, 1, 1, 1928.95, -5052.91, 78.8965, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: 0)
(@OGUID+458, 142142, 0, 1, 1, 1953.62, -5034.36, 77.0338, 2.391098, 0, 0, 0, 1, 120, 255, 1), -- Sungrass (Area: 0)
(@OGUID+459, 1735, 0, 1, 1, 2016.51, -5009.97, 82.8314, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: 0)
(@OGUID+460, 2041, 0, 1, 1, 2059.84, -5040.03, 70.9391, 0, 0, 0, 0, 1, 120, 255, 1), -- Liferoot (Area: 0)
(@OGUID+461, 142142, 0, 1, 1, 2399.11, -5028.39, 78.5079, 2.391098, 0, 0, 0, 1, 120, 255, 1), -- Sungrass (Area: 0)
(@OGUID+462, 2043, 0, 1, 1, 2447.2, -5075.98, 78.7151, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: 0)
(@OGUID+463, 2040, 0, 1, 1, 2864.5, -5064.06, 121.203, 0.5585039, 0, 0, 0, 1, 120, 255, 1), -- Mithril Deposit (Area: Northdale)
(@OGUID+464, 2040, 0, 1, 1, 3017.26, -5081.55, 129.163, 0.5585039, 0, 0, 0, 1, 120, 255, 1), -- Mithril Deposit (Area: Northdale)
(@OGUID+465, 2043, 0, 1, 1, 2868.65, -5113.16, 108.045, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: Northdale)
(@OGUID+466, 180684, 0, 1, 1, 2311.71, -5112.681, 71.01295, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Greater Sagefish School (Area: 0)
(@OGUID+467, 175369, 0, 1, 1, 3185.481, -4039.099, 107.7914, 3.124123, 0, 0, 0.9999619, 0.008726474, 120, 255, 1), -- Elders' Square Service Entrance (Area: 0)
(@OGUID+468, 175370, 0, 1, 1, 3271.517, -4064.309, 108.4344, 3.429581, 0, 0, 0.9999619, 0.008726474, 120, 255, 1), -- Doodad_SmallPortcullis05 (Area: 0)
(@OGUID+469, 194934, 0, 1, 1, 3624.908, -3642.165, 138.4453, 3.595379, 0, 0, 1, -4.371139E-08, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+470, 194919, 0, 1, 1, 3555.828, -3434.895, 136.3569, 2.312558, 0, 0, 1, -4.371139E-08, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+471, 194918, 0, 1, 1, 3571.571, -3451.686, 136.3569, 2.312558, 0, 0, 1, -4.371139E-08, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+472, 194923, 0, 1, 1, 3727.291, -3599.084, 142.2197, 3.516848, 0, 0, 1, -4.371139E-08, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+473, 174626, 0, 1, 1, 1267.591, -2567.375, 94.11425, 5.192355, 0, 0, 0.9713421, -0.2376859, 120, 255, 1), -- Scholomance Door (Area: 0)
(@OGUID+474, 194922, 0, 1, 1, 3782.581, -3590.481, 143.9873, 1.946041, 0, 0, 1, -4.371139E-08, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+475, 194917, 0, 1, 1, 3603.04, -3335.242, 125.3545, 3.141593, 0, 0, 1, -4.371139E-08, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+476, 194916, 0, 1, 1, 3621.545, -3335.557, 123.5011, 3.141593, 0, 0, 1, -4.371139E-08, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+477, 194921, 0, 1, 1, 3908.553, -3545.293, 135.9082, 2.949595, 0, 0, 1, -4.371139E-08, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+478, 194920, 0, 1, 1, 3931.202, -3549.387, 133.9609, 2.949595, 0, 0, 1, -4.371139E-08, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+479, 194924, 0, 1, 1, 3960.596, -3392.892, 119.6622, 3.194002, 0, 0, 1, -4.371139E-08, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+480, 194925, 0, 1, 1, 3908.783, -3320.208, 120.9042, 4.424412, 0, 0, 1, -4.371139E-08, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+481, 101851, 0, 1, 1, 2886.309, -827.2612, 160.3354, 1.963495, 0, 0, 0.8314698, 0.55557, 120, 255, 1), -- Armory Door (Area: 0)
(@OGUID+482, 101850, 0, 1, 1, 2908.177, -818.2034, 160.3318, 1.963495, 0, 0, 0.8314698, 0.55557, 120, 255, 1), -- Cathedral Door (Area: 0)
-- (@OGUID+483, 206329, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 120, 255, 1), -- 0 (Area: 0) - !!! transport !!!
(@OGUID+483, 20654, 0, 1, 1, 1595.212, 178.6932, -40.52226, 4.703663, 0, 0, -0.004363197, 0.9999905, 120, 255, 24), -- 0 (Area: 0)
(@OGUID+484, 20652, 0, 1, 1, 1595.261, 188.6444, -40.78354, 1.56207, 0, 0, -0.004363197, 0.9999905, 120, 255, 24), -- 0 (Area: 0)
(@OGUID+485, 20653, 0, 1, 1, 1595.378, 197.7065, 55.39519, 1.56207, 0, 0, -0.004363197, 0.9999905, 120, 255, 24), -- 0 (Area: 0)
(@OGUID+486, 20656, 0, 1, 1, 1553.298, 240.656, 55.39519, 6.274459, 0, 0, -0.004363197, 0.9999905, 120, 255, 24), -- 0 (Area: 0)
(@OGUID+487, 20655, 0, 1, 1, 1544.236, 240.7726, -40.78354, 6.274459, 0, 0, -0.004363197, 0.9999905, 120, 255, 24), -- 0 (Area: 0)
(@OGUID+488, 20657, 0, 1, 1, 1533.878, 240.8255, -32.34733, 3.132858, 0, 0, -0.004363197, 0.9999905, 120, 255, 24), -- 0 (Area: 0)
(@OGUID+489, 20650, 0, 1, 1, 1596.037, 282.7377, 55.3952, 4.703663, 0, 0, -0.004363197, 0.9999905, 120, 255, 24), -- 0 (Area: 0)
(@OGUID+490, 20649, 0, 1, 1, 1596.154, 291.7997, 14.68224, 4.703663, 0, 0, -0.004363197, 0.9999905, 120, 255, 24), -- 0 (Area: 0)
(@OGUID+491, 20651, 0, 1, 1, 1596.209, 302.4006, -40.66451, 1.56207, 0, 0, -0.004363197, 0.9999905, 120, 255, 24), -- 0 (Area: 0)
(@OGUID+492, 176594, 0, 1, 1, 2389.097, 337.9021, 40.01292, 2.242746, 0, 0, 0.9006982, 0.4344453, 120, 255, 1), -- Doors (Area: 0)
-- (@OGUID+493, 206328, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 120, 255, 1), -- 0 (Area: 0) - !!! transport !!!
(@OGUID+493, 190192, 0, 1, 1, -4903.218, -6629.801, 10.95026, 5.410522, 0, 0, -0.4226183, 0.9063078, 120, 255, 0), -- Gate (Area: 0)
(@OGUID+494, 152614, 0, 1, 1, -5067.462, 438.9844, 423.7576, 2.539454, 0, 0, 0.95502, 0.2965415, 120, 255, 24), -- 0 (Area: 0)
(@OGUID+495, 205077, 0, 1, 1, -4917.348, 782.4108, 276.2287, 1.492256, 0, 0, 0.6788008, 0.7343224, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+496, 152614, 0, 1, 1, -5210.476, 499.2994, 401.0719, 0.7679439, 0, 0, 0.3746067, 0.9271838, 120, 255, 24), -- 0 (Area: 0)
(@OGUID+497, 205079, 0, 1, 1, -5177.976, 673.805, 389.5476, 1.492256, 0, 0, 0.6788008, 0.7343224, 120, 255, 24), -- 0 (Area: 0)
(@OGUID+498, 205080, 0, 1, 1, -5178.21, 671.8933, 402.1269, 1.492256, 0, 0, 0.6788008, 0.7343224, 120, 255, 24), -- 0 (Area: 0)
(@OGUID+499, 161536, 0, 1, 1, -6756.729, -1166.696, 187.0422, 1.317723, 0, 0, 0.9969173, -0.07845917, 120, 255, 1), -- Quarry Gate (Area: 0)
(@OGUID+500, 149046, 0, 1, 1, -6900.42, -1339.326, 239.652, 3.394674, 0, 0, 1, -4.371139E-08, 120, 255, 24), -- 0 (Area: 0)
(@OGUID+501, 149045, 0, 1, 1, -6904.813, -1206.778, 178.5117, 2.984498, 0, 0, 1, -4.371139E-08, 120, 255, 24), -- 0 (Area: 0)
(@OGUID+502, 202831, 0, 1, 1, -7427.796, -1169.742, 478.2133, 0.3503397, 0, 0, -0.5730546, 0.8195173, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+503, 195491, 0, 1, 1, -1079.949, 4325.91, -1309.27, 4.459317, 0, 0, -0.7906896, 0.6122173, 120, 255, 1), -- Doodad_ND_WinterOrc_Wall_GateFX_Door01 (Area: 0)
(@OGUID+504, 195437, 0, 1, 1, -1146.486, 4356.482, -1307.615, 0.5845804, 0, 0, 0.2881461, 0.9575865, 120, 255, 1), -- Doodad_VR_Portcullis01 (Area: 0)
(@OGUID+505, 195491, 0, 1, 1, -1171.189, 4416.63, -1309.28, 3.097919, 0, 0, 0.9997621, 0.02181499, 120, 255, 1), -- Doodad_ND_WinterOrc_Wall_GateFX_Door01 (Area: 0)
(@OGUID+506, 195437, 0, 1, 1, -1147.139, 4471.825, -1307.615, 5.471503, 0, 0, -0.3947921, 0.9187705, 120, 255, 1), -- Doodad_VR_Portcullis01 (Area: 0)
(@OGUID+507, 195491, 0, 1, 1, -1086.77, 4513.75, -1309.27, 1.919862, 0, 0, 0.8191521, 0.5735763, 120, 255, 1), -- Doodad_ND_WinterOrc_Wall_GateFX_Door01 (Area: 0)
(@OGUID+508, 195491, 0, 1, 1, -1582.631, 4657.26, -1309.14, 5.358162, 0, 0, -0.4461977, 0.8949344, 120, 255, 1), -- Doodad_ND_WinterOrc_Wall_GateFX_Door01 (Area: 0)
(@OGUID+509, 195437, 0, 1, 1, -1643.74, 4642.156, -1308.775, 1.41361, 0, 0, 0.6494083, 0.7604399, 120, 255, 1), -- Doodad_VR_Portcullis01 (Area: 0)
(@OGUID+510, 195437, 0, 1, 1, -1552.63, 4712.904, -1308.775, 2.809871, 0, 0, 0.9862769, 0.1650993, 120, 255, 1), -- Doodad_VR_Portcullis01 (Area: 0)
(@OGUID+511, 195491, 0, 1, 1, -1713.75, 4664.54, -1309.52, 4.14516, 0, 0, 0.8767267, -0.4809888, 120, 255, 1), -- Doodad_ND_WinterOrc_Wall_GateFX_Door01 (Area: 0)
(@OGUID+512, 195491, 0, 1, 1, -1568.881, 4784.29, -1309.41, 0.4014249, 0, 0, 0.1993681, 0.9799247, 120, 255, 1), -- Doodad_ND_WinterOrc_Wall_GateFX_Door01 (Area: 0)
(@OGUID+513, 204582, 0, 1, 1, -9282.32, -3327.47, 112.287, 6.19592, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+514, 37118, 0, 1, 1, -9896.839, -3723.431, 21.91474, 2.286379, 0, 0, 0, 1, 120, 255, 1), -- Galen's Cage (Area: 0)
(@OGUID+515, 201517, 0, 1, 1, -8765.823, 403.1644, 104.1621, 5.384343, 0, 0, 0.944089, -0.3296907, 120, 255, 0), -- -Unknown- (Area: 0)
(@OGUID+516, 204848, 0, 1, 1, -6327.528, 4167.719, -489.2864, 0.8854322, 0, 0, 0.9885786, 0.1507064, 120, 255, 0), -- -Unknown- (Area: 0)
(@OGUID+517, 204851, 0, 1, 1, -6544.712, 4244.213, -489.2864, 1.325501, 0, 0, 0.9885786, 0.1507064, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+518, 204850, 0, 1, 1, -6612.319, 4228.612, -483.4876, 1.78482, 0, 0, 0.9885786, 0.1507064, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+519, 176580, 0, 1, 1, -11033.63, -1986.337, 126.0721, 4.223697, 0, 0, 0.9006982, 0.4344453, 120, 255, 1), -- Door (Area: 0)
(@OGUID+520, 176694, 0, 1, 1, -11037.91, -1999.855, 92.9915, 2.242746, 0, 0, 0.9006982, 0.4344453, 120, 255, 1), -- Karazhan Side Entrance (Area: 0)
(@OGUID+521, 176577, 0, 1, 1, -11066.05, -1988.069, 231.5188, 2.591811, 0, 0, 0.9006982, 0.4344453, 120, 255, 1), -- Gate (Area: 0)
(@OGUID+522, 176579, 0, 1, 1, -11070.7, -2001.422, 114.8234, 4.677484, 0, 0, 0.9006982, 0.4344453, 120, 255, 1), -- Door (Area: 0)
(@OGUID+523, 207208, 0, 1, 1, -11080.01, -1929.494, 90.90231, 1.80453, 0, 0, 0.9006982, 0.4344453, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+524, 176578, 0, 1, 1, -11098.14, -1990.838, 49.49687, 3.813545, 0, 0, 0.9006982, 0.4344453, 120, 255, 1), -- Door (Area: 0)
(@OGUID+525, 184164, 0, 1, 1, -11111.03, -2004.483, 49.3827, 3.813545, 0, 0, 0.9006982, 0.4344453, 120, 255, 1), -- Karazhan Gatehouse Portcullis (Area: 0)
(@OGUID+526, 177203, 0, 1, 1, -11067.97, -1824.712, 60.19905, 1.596976, 0, 0, 0.01308961, 0.9999143, 120, 255, 1), -- Gate (Area: 0)
(@OGUID+527, 176633, 0, 1, 1, -11105.65, -1966.78, 90.90231, 3.351047, 0, 0, 0.9006982, 0.4344453, 120, 255, 1), -- Door (Area: 0)
(@OGUID+528, 177247, 0, 1, 1, -11030.4, -1633.728, 27.97834, 1.596976, 0, 0, 0.01308961, 0.9999143, 120, 255, 1), -- Doodad_WroughtIronDoor03 (Area: 0)
(@OGUID+529, 177248, 0, 1, 1, -11031.28, -1600.163, 27.97834, 1.596976, 0, 0, 0.01308961, 0.9999143, 120, 255, 1), -- Doodad_WroughtIronDoor04 (Area: 0)
(@OGUID+530, 177256, 0, 1, 1, -11032.87, -1539.138, 29.45629, 1.596976, 0, 0, 0.01308961, 0.9999143, 120, 255, 1), -- Doodad_opendoor_02 (Area: 0)
(@OGUID+531, 177245, 0, 1, 1, -11062.1, -1635.611, 27.99158, 1.596976, 0, 0, 0.01308961, 0.9999143, 120, 255, 1), -- Doodad_WroughtIronDoor01 (Area: 0)
(@OGUID+532, 177255, 0, 1, 1, -11033.78, -1504.649, 27.99158, 1.596976, 0, 0, 0.01308961, 0.9999143, 120, 255, 1), -- Doodad_opendoor_03 (Area: 0)
(@OGUID+533, 177249, 0, 1, 1, -11063.01, -1600.994, 27.97834, 1.596976, 0, 0, 0.01308961, 0.9999143, 120, 255, 1), -- Doodad_WroughtIronDoor05 (Area: 0)
(@OGUID+534, 177250, 0, 1, 1, -11064.62, -1539.476, 27.97834, 1.596976, 0, 0, 0.01308961, 0.9999143, 120, 255, 1), -- Doodad_WroughtIronDoor06 (Area: 0)
(@OGUID+535, 177246, 0, 1, 1, -11093.86, -1635.39, 27.97834, 1.596976, 0, 0, 0.01308961, 0.9999143, 120, 255, 1), -- Doodad_WroughtIronDoor02 (Area: 0)
(@OGUID+536, 177254, 0, 1, 1, -11065.52, -1505.48, 27.99158, 1.596976, 0, 0, 0.01308961, 0.9999143, 120, 255, 1), -- Doodad_opendoor_01 (Area: 0)
(@OGUID+537, 177251, 0, 1, 1, -11094.74, -1601.537, 27.99158, 1.596976, 0, 0, 0.01308961, 0.9999143, 120, 255, 1), -- Doodad_WroughtIronDoor07 (Area: 0)
(@OGUID+538, 177252, 0, 1, 1, -11096.34, -1540.468, 27.99158, 1.596976, 0, 0, 0.01308961, 0.9999143, 120, 255, 1), -- Doodad_WroughtIronDoor08 (Area: 0)
(@OGUID+539, 177253, 0, 1, 1, -11097.23, -1506.311, 27.99158, 1.596976, 0, 0, 0.01308961, 0.9999143, 120, 255, 1), -- Doodad_WroughtIronDoor09 (Area: 0)
(@OGUID+540, 176901, 0, 1, 1, -11206.37, -1755.071, 4.382416, 1.596976, 0, 0, 0.01308961, 0.9999143, 120, 255, 1), -- Doodad_PortcullisActive02 (Area: 0)
(@OGUID+541, 177047, 0, 1, 1, -11206.93, -1733.736, 4.382416, 1.596976, 0, 0, 0.01308961, 0.9999143, 120, 255, 1), -- Doodad_PortcullisActive05 (Area: 0)
(@OGUID+542, 177048, 0, 1, 1, -11226.34, -1755.594, 4.382416, 1.596976, 0, 0, 0.01308961, 0.9999143, 120, 255, 1), -- Doodad_PortcullisActive06 (Area: 0)
(@OGUID+543, 177049, 0, 1, 1, -11226.9, -1734.259, 4.382416, 1.596976, 0, 0, 0.01308961, 0.9999143, 120, 255, 1), -- Doodad_PortcullisActive07 (Area: 0)
(@OGUID+544, 180497, 0, 1, 1, -11505.66, -1609.016, 47.6743, 1.579522, 0, 0, 0.7101853, 0.7040148, 120, 255, 0), -- Forcefield (Area: 0)
(@OGUID+545, 143979, 0, 1, 1, -11600.36, -698.984, 30.97299, 0.01745246, 0, 0, 0.008726574, 0.9999619, 120, 255, 1), -- Cage Door (Area: 0)
(@OGUID+546, 204828, 0, 1, 1, -11571.15, -568.7274, 33.68356, 3.211419, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+547, 207869, 0, 1, 1, -6188.985, 6559.648, -883.7168, 5.240902, 0, 0, 0.4400505, 0.897973, 120, 255, 0), -- -Unknown- (Area: 0)
(@OGUID+548, 207872, 0, 1, 1, -6247.23, 6529.747, -880.4471, 5.240902, 0, 0, 0.4400505, 0.897973, 120, 255, 0), -- -Unknown- (Area: 0)
(@OGUID+549, 207870, 0, 1, 1, -6047.34, 6742.35, -883.7168, 5.852104, 0, 0, 0.4400505, 0.897973, 120, 255, 0), -- -Unknown- (Area: 0)
(@OGUID+550, 207871, 0, 1, 1, -6032.426, 6805.216, -877.9181, 6.140289, 0, 0, 0.4400505, 0.897973, 120, 255, 0), -- -Unknown- (Area: 0)
-- (@OGUID+551, 176495, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 120, 255, 1), -- 0 (Area: 0) - !!! transport !!!
(@OGUID+551, 179498, 0, 1, 1, 1821.821, -5193.614, 148.1905, 5.201083, 0, 0, 0, 1, 120, 255, 1), -- Scarlet Footlocker (Area: 0)
(@OGUID+552, 1735, 0, 1, 1, 1871.49, -5142.01, 90.2989, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: 0)
(@OGUID+553, 142142, 0, 1, 1, 1997.37, -5192.94, 81.4446, 2.391098, 0, 0, 0, 1, 120, 255, 1), -- Sungrass (Area: 0)
(@OGUID+554, 142142, 0, 1, 1, 2089.55, -5153.61, 83.3526, 2.391098, 0, 0, 0, 1, 120, 255, 1), -- Sungrass (Area: 0)
(@OGUID+555, 2041, 0, 1, 1, 2146.32, -5175.38, 71.0414, 0, 0, 0, 0, 1, 120, 255, 1), -- Liferoot (Area: Pestilent Scar)
(@OGUID+556, 2041, 0, 1, 1, 2313.12, -5147.89, 71.0143, 0, 0, 0, 0, 1, 120, 255, 1), -- Liferoot (Area: Pestilent Scar)
(@OGUID+557, 2040, 0, 1, 1, 2871.98, -5156.32, 111.805, 0.5585039, 0, 0, 0, 1, 120, 255, 1), -- Mithril Deposit (Area: 0)
(@OGUID+558, 1735, 0, 1, 1, 2484.62, -5231.61, 88.7196, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: Browman Mill)
(@OGUID+559, 2043, 0, 1, 1, 2125.18, -5242.02, 79.0012, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: Pestilent Scar)
(@OGUID+560, 2043, 0, 1, 1, 1999.36, -5240.44, 80.5722, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: Pestilent Scar)
(@OGUID+561, 205878, 0, 1, 1, 1643.2, -5301.81, 75.8869, 2.670348, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Tyr's Hand)
(@OGUID+562, 205879, 0, 1, 1, 1598.97, -5280.33, 75.8868, 5.881761, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Tyr's Hand)
(@OGUID+563, 205880, 0, 1, 1, 1579.63, -5315.36, 75.8868, 5.532695, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Tyr's Hand)
(@OGUID+564, 1734, 0, 1, 1, 2149.66, -5331.49, 110.168, 0, 0, 0, 0, 1, 120, 255, 1), -- Gold Vein (Area: Light's Hope Chapel)
-- (@OGUID+565, 35591, 0, 1, 1, 2172.076, -5176.953, 71.01295, 0.5458501, 0, 0, 0, 1, 120, 255, 1), -- Fishing Bobber (Area: Light's Hope Chapel) - !!! might be temporary spawn !!!
(@OGUID+565, 176277, 0, 1, 1, 2258.248, -5316.693, 81.69451, 0.9773825, 0, 0, 0, 1, 120, 255, 1), -- Campfire (Area: Light's Hope Chapel)
(@OGUID+566, 181131, 0, 1, 1, 2264.125, -5316.559, 81.92778, 1.90375, 0, 0, 0, 1, 120, 255, 1), -- Anvil (Area: Light's Hope Chapel)
(@OGUID+567, 181130, 0, 1, 1, 2261.361, -5322.45, 81.8427, 5.091958, 0, 0, 0, 1, 120, 255, 1), -- Forge (Area: Light's Hope Chapel)
(@OGUID+568, 176276, 0, 1, 1, 2258.405, -5338.74, 86.56474, 3.14065, 0, 0, 0, 1, 120, 255, 1), -- Campfire (Area: Light's Hope Chapel)
(@OGUID+569, 181236, 0, 1, 1, 2290.66, -5323.351, 90.0145, 2.357862, 0, 0, 0, 1, 120, 255, 1), -- Mailbox (Area: Light's Hope Chapel)
(@OGUID+570, 181103, 0, 1, 1, 2309.39, -5263.72, 82.3791, 5.742135, 0, 0, 0, 1, 120, 255, 1), -- Flower (Area: Light's Hope Chapel)
(@OGUID+571, 181104, 0, 1, 1, 2309.29, -5263.74, 82.3906, 1.675514, 0, 0, 0, 1, 120, 255, 1), -- Small Dirt Mound (Area: Light's Hope Chapel)
(@OGUID+572, 207582, 0, 1, 1, 2400.858, -5563.217, 420.7012, 2.358741, 0, 0, 0.2923717, 0.9563047, 120, 255, 1), -- -Unknown- (Area: Light's Hope Chapel)
(@OGUID+573, 207589, 0, 1, 1, 2404.428, -5559.715, 420.7012, 4.325326, 0, 0, 0.2923717, 0.9563047, 120, 255, 1), -- -Unknown- (Area: Light's Hope Chapel)
(@OGUID+574, 207578, 0, 1, 1, 2427.278, -5544.454, 420.8623, 5.299957, 0, 0, 0.2923717, 0.9563047, 120, 255, 1), -- -Unknown- (Area: Light's Hope Chapel)
(@OGUID+575, 176272, 0, 1, 1, 2792.183, -5406.483, 162.8254, 3.220156, 0, 0, 0, 1, 120, 255, 1), -- Campfire (Area: The Noxious Glade)
(@OGUID+576, 2043, 0, 1, 1, 2845.92, -5421.58, 164.421, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: The Noxious Glade)
(@OGUID+577, 176389, 0, 1, 1, 2684.933, -5402.479, 157.0127, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Campfire (Area: The Noxious Glade)
(@OGUID+578, 207579, 0, 1, 1, 2509.315, -5560.396, 420.8623, 3.729166, 0, 0, 0.2923717, 0.9563047, 120, 255, 1), -- -Unknown- (Area: The Noxious Glade)
(@OGUID+579, 2043, 0, 1, 1, 2586.45, -5414.64, 156.572, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: The Noxious Glade)
(@OGUID+580, 207577, 0, 1, 1, 2493.367, -5642.436, 420.8623, 2.164206, 0, 0, 0.2923717, 0.9563047, 120, 255, 1), -- -Unknown- (Area: The Noxious Glade)
(@OGUID+581, 207583, 0, 1, 1, 2471.899, -5651.719, 420.6134, 2.556905, 0, 0, 0.2923717, 0.9563047, 120, 255, 1), -- -Unknown- (Area: The Noxious Glade)
(@OGUID+582, 207587, 0, 1, 1, 2429.864, -5639.139, 420.6735, 6.041738, 0, 0, 0.2923717, 0.9563047, 120, 255, 1), -- -Unknown- (Area: The Noxious Glade)
(@OGUID+583, 207580, 0, 1, 1, 2390.021, -5640.913, 377.093, 0.593412, 0, 0, 0.2923717, 0.9563047, 120, 255, 0), -- -Unknown- (Area: The Noxious Glade)
(@OGUID+584, 207581, 0, 1, 1, 2383.655, -5645.208, 420.7722, 0.593412, 0, 0, 0.2923717, 0.9563047, 120, 255, 0), -- -Unknown- (Area: The Noxious Glade)
(@OGUID+585, 207585, 0, 1, 1, 2453.396, -5659.122, 420.5659, 4.609313, 0, 0, 0.2923717, 0.9563047, 120, 255, 1), -- -Unknown- (Area: The Noxious Glade)
(@OGUID+586, 207584, 0, 1, 1, 2466.239, -5659.792, 420.5884, 2.46964, 0, 0, 0.2923717, 0.9563047, 120, 255, 1), -- -Unknown- (Area: The Noxious Glade)
(@OGUID+587, 207586, 0, 1, 1, 2428.089, -5648.837, 420.6317, 6.129003, 0, 0, 0.2923717, 0.9563047, 120, 255, 1), -- -Unknown- (Area: The Noxious Glade)
(@OGUID+588, 207588, 0, 1, 1, 2438.341, -5655.61, 420.5422, 4.609313, 0, 0, 0.2923717, 0.9563047, 120, 255, 1), -- -Unknown- (Area: The Noxious Glade)
(@OGUID+589, 191364, 0, 1, 1, 2430.611, -5730.014, 157.3015, 2.555517, 0, 0, 0.9381913, 0.3461172, 120, 255, 0), -- Doodad_Nox_portal_orange_bossroom01 (Area: The Noxious Glade)
(@OGUID+590, 205881, 0, 1, 1, 1621.18, -5346.45, 75.8869, 1.658062, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Tyr's Hand)
(@OGUID+591, 148960, 0, 1, 1, 1548.699, -5387.109, 78.2245, 5.558874, 0, 0, -0.3542911, 0.9351352, 120, 255, 1), -- Forge (Area: Tyr's Hand)
(@OGUID+592, 148959, 0, 1, 1, 1548.994, -5380.496, 80.03245, 4.319691, 0, 0, -0.3542911, 0.9351352, 120, 255, 1), -- Anvil (Area: Tyr's Hand)
(@OGUID+593, 148957, 0, 1, 1, 1548.432, -5393.588, 80.03245, 1.509709, 0, 0, -0.3542911, 0.9351352, 120, 255, 1), -- Anvil (Area: Tyr's Hand)
(@OGUID+594, 148958, 0, 1, 1, 1543.171, -5381.187, 80.03245, 0.06981169, 0, 0, -0.3542911, 0.9351352, 120, 255, 1), -- Anvil (Area: Tyr's Hand)
(@OGUID+595, 148956, 0, 1, 1, 1555.237, -5386.184, 80.03245, 2.993224, 0, 0, -0.3542911, 0.9351352, 120, 255, 1), -- Anvil (Area: Tyr's Hand)
(@OGUID+596, 205875, 0, 1, 1, 1569.99, -5414.07, 76.2357, 2.024579, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Tyr's Hand)
(@OGUID+597, 2043, 0, 1, 1, 2843.83, -5490.85, 160.944, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: The Noxious Glade)
(@OGUID+598, 176390, 0, 1, 1, 2670.269, -5505.132, 162.4014, 2.940878, 0, 0, 0, 1, 120, 255, 1), -- Campfire (Area: The Noxious Glade)
(@OGUID+599, 176275, 0, 1, 1, 2609.157, -5503.625, 158.051, 3.141848, 0, 0, 0, 1, 120, 255, 1), -- Bubbling Cauldron (Area: The Noxious Glade)
(@OGUID+600, 151967, 0, 1, 1, 1804.458, -5428.595, 89.68497, 2.923416, 0, 0, -0.1088669, 0.9940563, 120, 255, 1), -- Wooden Bench (Area: 0)
(@OGUID+601, 151957, 0, 1, 1, 1805.365, -5422.598, 82.29011, 2.923416, 0, 0, -0.1088669, 0.9940563, 120, 255, 1), -- Wooden Bench (Area: 0)
(@OGUID+602, 176273, 0, 1, 1, 2794.817, -5585.491, 161.772, 2.46964, 0, 0, 0, 1, 120, 255, 1), -- Bubbling Cauldron (Area: The Noxious Glade)
(@OGUID+603, 176274, 0, 1, 1, 2796.064, -5581.491, 161.6726, 1.902406, 0, 0, 0, 1, 120, 255, 1), -- Campfire (Area: The Noxious Glade)
(@OGUID+604, 147449, 0, 1, 1, 1555.014, -5592.847, 111.205, 5.803221, 0, 0, 0.5187731, 0.8549119, 120, 255, 1), -- Bench (Area: Ruins of the Scarlet Enclave)
(@OGUID+605, 147448, 0, 1, 1, 1589.264, -5610.676, 111.205, 2.661627, 0, 0, 0.5187731, 0.8549119, 120, 255, 1), -- Bench (Area: Ruins of the Scarlet Enclave)
(@OGUID+606, 147450, 0, 1, 1, 1562.777, -5577.935, 111.205, 5.803221, 0, 0, 0.5187731, 0.8549119, 120, 255, 1), -- Bench (Area: Ruins of the Scarlet Enclave)
(@OGUID+607, 147447, 0, 1, 1, 1597.026, -5595.764, 111.205, 2.661627, 0, 0, 0.5187731, 0.8549119, 120, 255, 1), -- Bench (Area: Ruins of the Scarlet Enclave)
(@OGUID+608, 3798, 0, 1, 1, 1931.969, -5787.342, 100.9644, 2.696529, 0, 0, 0.4186598, 0.9081432, 120, 255, 1), -- Cozy Fire (Area: Ruins of the Scarlet Enclave)
(@OGUID+609, 3797, 0, 1, 1, 1931.335, -5787.974, 100.9644, 3.988076, 0, 0, 0.4186598, 0.9081432, 120, 255, 1), -- Cozy Fire (Area: Ruins of the Scarlet Enclave)
(@OGUID+610, 3798, 0, 1, 1, 1758.253, -5773.46, 117.0643, 0.5061446, 0, 0, -0.6156614, 0.7880108, 120, 255, 1), -- Cozy Fire (Area: Ruins of the Scarlet Enclave)
(@OGUID+611, 3797, 0, 1, 1, 1758.107, -5772.578, 117.0643, 1.797689, 0, 0, -0.6156614, 0.7880108, 120, 255, 1), -- Cozy Fire (Area: Ruins of the Scarlet Enclave)
(@OGUID+612, 3798, 0, 1, 1, 1752.323, -5794.603, 117.179, 1.701696, 0, 0, -0.06540315, 0.9978589, 120, 255, 1), -- Cozy Fire (Area: Ruins of the Scarlet Enclave)
(@OGUID+613, 3797, 0, 1, 1, 1751.449, -5794.415, 117.179, 2.993224, 0, 0, -0.06540315, 0.9978589, 120, 255, 1), -- Cozy Fire (Area: Ruins of the Scarlet Enclave)
(@OGUID+614, 3798, 0, 1, 1, 1639.143, -5804.921, 117.0423, 3.761187, 0, 0, 0.8216469, 0.5699969, 120, 255, 1), -- Cozy Fire (Area: Ruins of the Scarlet Enclave)
(@OGUID+615, 3797, 0, 1, 1, 1639.388, -5805.782, 117.0423, 5.052728, 0, 0, 0.8216469, 0.5699969, 120, 255, 1), -- Cozy Fire (Area: Ruins of the Scarlet Enclave)
(@OGUID+616, 3798, 0, 1, 1, 1511.509, -5813.814, 132.3853, 0.4799661, 0, 0, -0.6259233, 0.7798846, 120, 255, 1), -- Cozy Fire (Area: Ruins of the Scarlet Enclave)
(@OGUID+617, 3797, 0, 1, 1, 1511.387, -5812.928, 132.3853, 1.771508, 0, 0, -0.6259233, 0.7798846, 120, 255, 1), -- Cozy Fire (Area: Ruins of the Scarlet Enclave)
(@OGUID+618, 160866, 0, 1, 1, 1371.523, -5685.289, 137.8526, 3.001947, 0, 0, -0.3090168, 0.9510565, 120, 255, 1), -- Pew (Area: Ruins of the Scarlet Enclave)
(@OGUID+619, 160867, 0, 1, 1, 1369.169, -5683.579, 137.8526, 2.644172, 0, 0, -0.3090168, 0.9510565, 120, 255, 1), -- Pew (Area: Ruins of the Scarlet Enclave)
(@OGUID+620, 160869, 0, 1, 1, 1370.403, -5698.767, 137.8526, 1.308998, 0, 0, -0.3090168, 0.9510565, 120, 255, 1), -- Pew (Area: Ruins of the Scarlet Enclave)
(@OGUID+621, 160871, 0, 1, 1, 1376.408, -5687.803, 137.8526, 3.857183, 0, 0, -0.3090168, 0.9510565, 120, 255, 1), -- Pew (Area: Ruins of the Scarlet Enclave)
(@OGUID+622, 160868, 0, 1, 1, 1363.442, -5691.55, 137.8526, 2.164206, 0, 0, -0.3090168, 0.9510565, 120, 255, 1), -- Pew (Area: Ruins of the Scarlet Enclave)
(@OGUID+623, 160870, 0, 1, 1, 1368.198, -5696.013, 137.8526, 1.125737, 0, 0, -0.3090168, 0.9510565, 120, 255, 1), -- Pew (Area: Ruins of the Scarlet Enclave)
(@OGUID+624, 204047, 0, 1, 1, -5520.566, 693.2934, 378.2548, 1.989672, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Death's Breach)
(@OGUID+625, 3798, 0, 1, 1, 1735.076, -5972.536, 117.0753, 4.441865, 0, 0, 0.9647873, 0.2630313, 120, 255, 1), -- Cozy Fire (Area: Ruins of the Scarlet Enclave)
(@OGUID+626, 3797, 0, 1, 1, 1735.807, -5973.05, 117.0753, 5.733407, 0, 0, 0.9647873, 0.2630313, 120, 255, 1), -- Cozy Fire (Area: Ruins of the Scarlet Enclave)
(@OGUID+627, 38492, 0, 1, 1, 1816.936, -6005.671, 117.658, 2.172932, 0, 0, -0.6977904, 0.716302, 120, 255, 1), -- Anvil (Area: Ruins of the Scarlet Enclave)
(@OGUID+628, 38493, 0, 1, 1, 1806.88, -6005.744, 117.658, 0.6894043, 0, 0, -0.6977904, 0.716302, 120, 255, 1), -- Anvil (Area: Ruins of the Scarlet Enclave)
(@OGUID+629, 38491, 0, 1, 1, 1811.801, -6001.521, 115.8501, 4.73857, 0, 0, -0.6977904, 0.716302, 120, 255, 1), -- Forge (Area: Ruins of the Scarlet Enclave)
(@OGUID+630, 38495, 0, 1, 1, 1816.838, -5997.227, 117.658, 3.49939, 0, 0, -0.6977904, 0.716302, 120, 255, 1), -- Anvil (Area: Ruins of the Scarlet Enclave)
(@OGUID+631, 38494, 0, 1, 1, 1812.362, -5993.439, 117.6496, 5.532695, 0, 0, -0.6977904, 0.716302, 120, 255, 1), -- Anvil (Area: Ruins of the Scarlet Enclave)
(@OGUID+632, 3798, 0, 1, 1, 1527.269, -6116.646, 117.2514, 5.864309, 0, 0, 0.9025853, -0.4305111, 120, 255, 1), -- Cozy Fire (Area: Ruins of the Scarlet Enclave)
(@OGUID+633, 3797, 0, 1, 1, 1527.886, -6115.999, 117.2514, 0.8726639, 0, 0, 0.9025853, -0.4305111, 120, 255, 1); -- Cozy Fire (Area: Ruins of the Scarlet Enclave)

UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=41, `faction_A`=38, `faction_H`=38, `speed_walk`=1.428571, `speed_run`=0.666668, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=8596; -- Plaguehound Runt
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `npcflag`=131, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=2, `unit_flags`=33536 WHERE `entry`=45417; -- Fiona
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=37888; -- Frax Bucketdrop
UPDATE `creature_template` SET `minlevel`=41, `maxlevel`=42, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=8603; -- Carrion Grub
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=41, `speed_walk`=1.428571, `speed_run`=1.4, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=8534; -- Putrid Gargoyle
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=15476; -- Scorpion
UPDATE `creature_template` SET `minlevel`=39, `maxlevel`=40, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=8555; -- Crypt Stalker
UPDATE `creature_template` SET `minlevel`=43, `maxlevel`=44, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=16117; -- Plagued Swine
UPDATE `creature_template` SET `minlevel`=39, `maxlevel`=40, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=4 WHERE `entry`=8557; -- Crypt Horror
UPDATE `creature_template` SET `minlevel`=39, `maxlevel`=39, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=4 WHERE `entry`=8556; -- Crypt Walker
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=11140; -- Egan
UPDATE `creature_template` SET `npcflag`=3, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=12384; -- Augustus the Touched
UPDATE `creature_template` SET `minlevel`=43, `maxlevel`=44, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=8524; -- Cursed Mage
UPDATE `creature_template` SET `minlevel`=43, `maxlevel`=44, `speed_walk`=1.142857, `speed_run`=0.777776, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=8530; -- Cannibal Ghoul
UPDATE `creature_template` SET `minlevel`=39, `maxlevel`=40, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=8558; -- Crypt Slayer
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `npcflag`=2, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=2, `unit_flags`=33536 WHERE `entry`=45428; -- Gidwin Goldbraids
UPDATE `creature_template` SET `minlevel`=88, `maxlevel`=88, `faction_A`=2167, `faction_H`=2167, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=2, `unit_flags`=33587968 WHERE `entry`=53649; -- Thrall
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=41, `faction_A`=2030, `faction_H`=2030, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=8600; -- Plaguebat
UPDATE `creature_template` SET `faction_A`=188, `faction_H`=188, `speed_walk`=2.857143, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=20725; -- Bat
UPDATE `creature_template` SET `minlevel`=43, `maxlevel`=44, `speed_walk`=1.142857, `speed_run`=0.888888, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=8523; -- Scourge Soldier
UPDATE `creature_template` SET `speed_walk`=0.8571429, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=10780; -- Infected Deer
UPDATE `creature_template` SET `minlevel`=41, `maxlevel`=42, `speed_walk`=1.190476, `speed_run`=0.666668, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=8598; -- Frenzied Plaguehound
UPDATE `creature_template` SET `minlevel`=44, `maxlevel`=45, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=8605; -- Carrion Devourer
UPDATE `creature_template` SET `minlevel`=43, `maxlevel`=44, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=8602; -- Monstrous Plaguebat
UPDATE `creature_template` SET `minlevel`=43, `maxlevel`=44, `faction_A`=21, `faction_H`=21, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000 WHERE `entry`=45851; -- Overstuffed Golem
UPDATE `creature_template` SET `minlevel`=47, `maxlevel`=47, `faction_A`=2070, `faction_H`=2070, `npcflag`=3, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=45828; -- Argent Apothecary Judkins
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction_A`=2070, `faction_H`=2070, `npcflag`=4224, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=47106; -- Christine Gade
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=2363, `faction_H`=2363, `speed_walk`=2.285714, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33280 WHERE `entry`=47060; -- Argent Sentry
UPDATE `creature_template` SET `minlevel`=80, `maxlevel`=80, `speed_walk`=1.385714, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000 WHERE `entry`=44240; -- Argent Hippogryph
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=2070, `faction_H`=2070, `npcflag`=8193, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000 WHERE `entry`=44233; -- William Kielar Jr.
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction_A`=2070, `faction_H`=2070, `npcflag`=640, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=47105; -- Marc Daiton
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=974, `faction_H`=974, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=570688256, `dynamicflags`=32 WHERE `entry`=45886; -- Corpsebeast (Giant)
UPDATE `creature_template` SET `minlevel`=39, `maxlevel`=40, `faction_A`=21, `faction_H`=21, `speed_walk`=0.7142857, `speed_run`=1.2, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=2, `unit_flags`=32768 WHERE `entry`=45444; -- Death's Step Miscreation
UPDATE `creature_template` SET `minlevel`=39, `maxlevel`=40, `faction_A`=21, `faction_H`=21, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=2, `unit_flags`=32768 WHERE `entry`=45443; -- Death's Step Putrifier
UPDATE `creature_template` SET `speed_walk`=0.8571429, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=10779; -- Infected Squirrel
UPDATE `creature_template` SET `minlevel`=46, `maxlevel`=46, `npcflag`=2, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=2, `unit_flags`=33024 WHERE `entry`=45429; -- Tarenar Sunstrike
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction_A`=2070, `faction_H`=2070, `npcflag`=128, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=47104; -- Anthony Waler
UPDATE `creature_template` SET `minlevel`=44, `maxlevel`=45, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=8553; -- Necromancer
UPDATE `creature_template` SET `minlevel`=43, `maxlevel`=44, `speed_walk`=1.428571, `speed_run`=1.4, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=8535; -- Putrid Shrieker
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=974, `faction_H`=974, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=570688256, `dynamicflags`=32 WHERE `entry`=45895; -- Corpsebeast (Blob)
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=974, `faction_H`=974, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=570688256, `dynamicflags`=32 WHERE `entry`=45893; -- Corpsebeast (Dog)
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=41, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=11290; -- Mossflayer Zombie
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=41, `faction_A`=974, `faction_H`=974, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=45453; -- Blighthound
UPDATE `creature_template` SET `minlevel`=44, `maxlevel`=45, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=8547; -- Death Cultist
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=41, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=11291; -- Unliving Mossflayer
UPDATE `creature_template` SET `minlevel`=41, `maxlevel`=41, `speed_walk`=1.142857, `speed_run`=0.666668, `rangeattacktime`=2000, `dynamicflags`=4 WHERE `entry`=12250; -- Zaeldarr the Outcast
UPDATE `creature_template` SET `minlevel`=41, `maxlevel`=41, `faction_A`=974, `faction_H`=974, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=768 WHERE `entry`=45475; -- Plague Disseminator
UPDATE `creature_template` SET `minlevel`=44, `maxlevel`=45, `faction_A`=21, `faction_H`=21, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=2, `unit_flags`=32768 WHERE `entry`=45897; -- Plaguewood Reanimator
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction_A`=974, `faction_H`=974, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=2, `unit_flags`=32768 WHERE `entry`=45867; -- Omasum Blighthoof
UPDATE `creature_template` SET `gossip_menu_id`=12061, `minlevel`=63, `maxlevel`=63, `faction_A`=2070, `faction_H`=2070, `npcflag`=3, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=45831; -- Crusader Kevin Frost
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction_A`=974, `faction_H`=974, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=2, `unit_flags`=32768 WHERE `entry`=45868; -- Karthis Darkrune
UPDATE `creature_template` SET `gossip_menu_id`=0, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=16135; -- Rayne
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=41, `speed_walk`=1.142857, `speed_run`=0.888888, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=8529; -- Scourge Champion
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=1812, `faction_H`=1812, `speed_walk`=2.285714, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=51986; -- Argent Sentry
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33555200 WHERE `entry`=35114; -- ELM General Purpose Bunny (All Phases)
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33555200 WHERE `entry`=45485; -- Necropolis Flowers
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=41, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=8550; -- Shadowmage
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33555200 WHERE `entry`=45488; -- Necropolis Flower Controller W
UPDATE `creature_template` SET `minlevel`=39, `maxlevel`=40, `faction_A`=107, `faction_H`=107, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=47064; -- Mossflayer Abducter
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=10926; -- Pamela Redpath
UPDATE `creature_template` SET `gossip_menu_id`=0, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=10667; -- Chromie
UPDATE `creature_template` SET `gossip_menu_id`=12033, `minlevel`=55, `maxlevel`=55, `faction_A`=2070, `faction_H`=2070, `npcflag`=4227, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000 WHERE `entry`=45500; -- Urk Gagbaz
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=2070, `faction_H`=2070, `npcflag`=8193, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000 WHERE `entry`=44232; -- Janice Myers
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=41, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=8546; -- Dark Adept
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction_A`=16, `faction_H`=16, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `unit_class`=2, `unit_flags`=64, `dynamicflags`=0 WHERE `entry`=10819; -- Baron Bloodbane
UPDATE `creature_template` SET `minlevel`=59, `maxlevel`=59, `faction_A`=2070, `faction_H`=2070, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=11063; -- Carlin Redpath
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction_A`=2070, `faction_H`=2070, `npcflag`=640, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=47139; -- Gerald Fairbanks
UPDATE `creature_template` SET `gossip_menu_id`=12034, `minlevel`=61, `maxlevel`=61, `faction_A`=2070, `faction_H`=2070, `npcflag`=4227, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000 WHERE `entry`=45451; -- Argus Highbeacon
UPDATE `creature_template` SET `faction_A`=188, `faction_H`=188, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33555200 WHERE `entry`=46016; -- Spectral Critter
UPDATE `creature_template` SET `minlevel`=41, `maxlevel`=41, `faction_A`=189, `faction_H`=189, `speed_walk`=1.142857, `speed_run`=0.4, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32832, `dynamicflags`=0 WHERE `entry`=10817; -- Duggan Wildhammer
UPDATE `creature_template` SET `speed_walk`=0.8571429, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=11288; -- Spectral Betrayer
UPDATE `creature_template` SET `speed_walk`=0.8571429, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=11289; -- Spectral Defender
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33555200 WHERE `entry`=45486; -- Necropolis Flower Controller SE
UPDATE `creature_template` SET `minlevel`=41, `maxlevel`=41, `faction_A`=16, `faction_H`=16, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `unit_flags`=64, `dynamicflags`=0 WHERE `entry`=10826; -- Lord Darkscythe
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33555200 WHERE `entry`=45487; -- Necropolis Flower Controller NE
UPDATE `creature_template` SET `speed_walk`=0.8571429, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=11621; -- Spectral Corpse
UPDATE `creature_template` SET `minlevel`=41, `maxlevel`=41, `faction_A`=14, `faction_H`=14, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000 WHERE `entry`=45450; -- The Lone Hunter
UPDATE `creature_template` SET `speed_walk`=0.8571429, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=11620; -- Spectral Marauder
UPDATE `creature_template` SET `minlevel`=41, `maxlevel`=42, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=8601; -- Noxious Plaguebat
UPDATE `creature_template` SET `minlevel`=44, `maxlevel`=44, `speed_walk`=1.428571, `speed_run`=2.6, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=11897; -- Duskwing
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=16229; -- Injured Argent Dawn Infantry
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=16228; -- Argent Dawn Infantry
UPDATE `creature_template` SET `maxlevel`=57, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=16284; -- Argent Medic
UPDATE `creature_template` SET `minlevel`=41, `maxlevel`=41, `speed_walk`=1.190476, `speed_run`=0.666668, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=8597; -- Plaguehound
UPDATE `creature_template` SET `minlevel`=41, `maxlevel`=41, `speed_walk`=1.289683, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=8522; -- Plague Monstrosity
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=41, `speed_walk`=1.289683, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=8521; -- Blighted Horror
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=45657; -- Infectis Scuttler
UPDATE `creature_template` SET `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=45650; -- Plague Puffer
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=45655; -- Infectis Incher
UPDATE `creature_template` SET `minlevel`=41, `maxlevel`=42, `faction_A`=14, `faction_H`=14, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=45664; -- Landlocked Grouper
UPDATE `creature_template` SET `minlevel`=44, `maxlevel`=44, `faction_A`=2070, `faction_H`=2070, `npcflag`=2, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=45816; -- Corpseburner Tim
UPDATE `creature_template` SET `minlevel`=57, `maxlevel`=58, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33554432 WHERE `entry`=41177; -- Stitched Horror (Cosmetic)
UPDATE `creature_template` SET `minlevel`=57, `maxlevel`=58, `speed_walk`=1.142857, `speed_run`=0.777776, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33554432 WHERE `entry`=41195; -- Cannibal Ghoul (Cosmetic)
UPDATE `creature_template` SET `minlevel`=43, `maxlevel`=44, `faction_A`=1924, `faction_H`=1924, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=8564; -- Ranger
UPDATE `creature_template` SET `minlevel`=43, `maxlevel`=44, `faction_A`=1924, `faction_H`=1924, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=8563; -- Woodsman
UPDATE `creature_template` SET `minlevel`=43, `maxlevel`=44, `faction_A`=1924, `faction_H`=1924, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=8565; -- Pathstrider
UPDATE `creature_template` SET `minlevel`=44, `maxlevel`=44, `npcflag`=2, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=45826; -- Kirkian Dawnshield
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction_A`=2070, `faction_H`=2070, `npcflag`=128, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=47164; -- James Litman
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction_A`=2070, `faction_H`=2070, `npcflag`=4224, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=47166; -- Dorris Manchester
UPDATE `creature_template` SET `minlevel`=43, `maxlevel`=44, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=17878; -- Scourge Siege Engineer
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction_A`=2070, `faction_H`=2070, `npcflag`=640, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=47165; -- Casey Tipple
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction_A`=2070, `faction_H`=2070, `npcflag`=640, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=47167; -- Brett Nelson
UPDATE `creature_template` SET `minlevel`=47, `maxlevel`=47, `faction_A`=2070, `faction_H`=2070, `npcflag`=2, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000 WHERE `entry`=45482; -- Argent Officer Irizarry
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=2070, `faction_H`=2070, `npcflag`=8193, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=28621; -- Grayson Ironwing
UPDATE `creature_template` SET `gossip_menu_id`=6944, `minlevel`=85, `maxlevel`=85, `faction_A`=2070, `faction_H`=2070, `npcflag`=8193, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000 WHERE `entry`=44231; -- Devon Manning
UPDATE `creature_template` SET `minlevel`=41, `maxlevel`=42, `speed_walk`=1.142857, `speed_run`=0.888888, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=8525; -- Scourge Warder
UPDATE `creature_template` SET `minlevel`=41, `maxlevel`=42, `speed_walk`=1.289683, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=8520; -- Plague Ravager
UPDATE `creature_template` SET `minlevel`=41, `maxlevel`=42, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=8541; -- Hate Shrieker
UPDATE `creature_template` SET `minlevel`=41, `maxlevel`=42, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `unit_class`=2, `dynamicflags`=0 WHERE `entry`=8538; -- Unseen Servant
UPDATE `creature_template` SET `minlevel`=41, `maxlevel`=42, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=8548; -- Vile Tutor
UPDATE `creature_template` SET `minlevel`=41, `maxlevel`=42, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=8543; -- Stitched Horror
UPDATE `creature_template` SET `minlevel`=41, `maxlevel`=42, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=8551; -- Dark Summoner
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=11035; -- Betina Bigglezink
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction_A`=2070, `faction_H`=2070, `npcflag`=128, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=47153; -- Cabe Minewell
UPDATE `creature_template` SET `minlevel`=43, `maxlevel`=43, `npcflag`=2, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=45575; -- Frederick Calston
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction_A`=2070, `faction_H`=2070, `npcflag`=4224, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=47149; -- Kathryn Humphries
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction_A`=2070, `faction_H`=2070, `npcflag`=640, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=47148; -- Donovan Minewell
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=11706; -- Adon
UPDATE `creature_template` SET `minlevel`=41, `maxlevel`=42, `speed_walk`=1.142857, `speed_run`=0.777776, `rangeattacktime`=2000, `unit_flags`=0, `dynamicflags`=0 WHERE `entry`=8531; -- Gibbering Ghoul
UPDATE `creature_template` SET `minlevel`=41, `maxlevel`=42, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=8526; -- Dark Caster
UPDATE `creature_template` SET `minlevel`=43, `maxlevel`=43, `faction_A`=16, `faction_H`=16, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=1500, `rangeattacktime`=2000, `unit_flags`=32832, `dynamicflags`=0 WHERE `entry`=1843; -- Foreman Jerris
UPDATE `creature_template` SET `minlevel`=41, `maxlevel`=42, `speed_walk`=1.289683, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=8519; -- Blighted Surge
UPDATE `creature_template` SET `minlevel`=42, `maxlevel`=43, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=8560; -- Mossflayer Scout
UPDATE `creature_template` SET `minlevel`=42, `maxlevel`=43, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=8561; -- Mossflayer Shadowhunter
UPDATE `creature_template` SET `minlevel`=43, `maxlevel`=43, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `unit_flags`=0, `dynamicflags`=0 WHERE `entry`=11896; -- Borelgore
UPDATE `creature_template` SET `minlevel`=42, `maxlevel`=43, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=8544; -- Gangled Golem
UPDATE `creature_template` SET `minlevel`=42, `maxlevel`=43, `speed_walk`=1.142857, `speed_run`=0.888888, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=8527; -- Scourge Guard
UPDATE `creature_template` SET `minlevel`=43, `maxlevel`=43, `faction_A`=21, `faction_H`=21, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000 WHERE `entry`=45744; -- Ix'lar the Underlord
UPDATE `creature_template` SET `minlevel`=42, `maxlevel`=43, `faction_A`=21, `faction_H`=21, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000 WHERE `entry`=45743; -- Nerubian Sycophant
UPDATE `creature_template` SET `minlevel`=42, `maxlevel`=43, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=8562; -- Mossflayer Cannibal
UPDATE `creature_template` SET `minlevel`=43, `maxlevel`=43, `faction_A`=16, `faction_H`=16, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32832, `dynamicflags`=0 WHERE `entry`=10823; -- Zul'Brin Warpbranch
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction_A`=2070, `faction_H`=2070, `npcflag`=640, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=47142; -- Rahmalaha
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction_A`=2070, `faction_H`=2070, `npcflag`=4224, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=47144; -- Patricia Marshall
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction_A`=2071, `faction_H`=2071, `npcflag`=2, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=2, `unit_flags`=512 WHERE `entry`=45735; -- Gamella Cracklefizz
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=2070, `faction_H`=2070, `npcflag`=8193, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000 WHERE `entry`=44230; -- Richard Trueflight
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction_A`=2071, `faction_H`=2071, `npcflag`=2, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=2, `unit_flags`=512 WHERE `entry`=45736; -- Deacon Andaal
UPDATE `creature_template` SET `minlevel`=42, `maxlevel`=43, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=8540; -- Torn Screamer
UPDATE `creature_template` SET `minlevel`=43, `maxlevel`=43, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=10822; -- Warlord Thresh'jin
UPDATE `creature_template` SET `minlevel`=42, `maxlevel`=43, `faction_A`=21, `faction_H`=21, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `unit_class`=2, `dynamicflags`=0 WHERE `entry`=8537; -- Interloper
UPDATE `creature_template` SET `minlevel`=41, `maxlevel`=42, `speed_walk`=1.142857, `speed_run`=0.777776, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=8532; -- Diseased Flayer
UPDATE `creature_template` SET `minlevel`=41, `maxlevel`=42, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=8528; -- Dread Weaver
UPDATE `creature_template` SET `minlevel`=41, `maxlevel`=42, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=8542; -- Death Singer
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=41, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=537133568, `dynamicflags`=32 WHERE `entry`=45695; -- Slain Scourge Trooper
UPDATE `creature_template` SET `minlevel`=42, `maxlevel`=42, `faction_A`=21, `faction_H`=21, `speed_run`=0.8, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=16384 WHERE `entry`=46167; -- Stephen Browman
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=2363, `faction_H`=2363, `speed_walk`=2.285714, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=16378; -- Argent Sentry
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction_A`=2070, `faction_H`=2070, `npcflag`=640, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=47288; -- Gutcheck
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction_A`=2070, `faction_H`=2070, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=47289; -- Argent Crusade Engineer
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction_A`=2070, `faction_H`=2070, `npcflag`=4224, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=47286; -- Vincent Randolph
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=2072, `faction_H`=2072, `speed_walk`=1.385714, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=11102; -- Argent Rider
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=643, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=11038; -- Caretaker Alen
UPDATE `creature_template` SET `minlevel`=41, `maxlevel`=42, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `unit_flags`=32768, `dynamicflags`=0 WHERE `entry`=9447; -- Scarlet Warder
UPDATE `creature_template` SET `minlevel`=41, `maxlevel`=42, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `unit_flags`=32768, `dynamicflags`=0 WHERE `entry`=9449; -- Scarlet Cleric
UPDATE `creature_template` SET `gossip_menu_id`=7097, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=16115; -- Commander Eligor Dawnbringer
UPDATE `creature_template` SET `gossip_menu_id`=0, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=16116; -- Archmage Angela Dosantos
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `unit_flags`=33280, `dynamicflags`=0 WHERE `entry`=16112; -- Korfax, Champion of the Light
UPDATE `creature_template` SET `minlevel`=41, `maxlevel`=42, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `unit_flags`=32768, `dynamicflags`=0 WHERE `entry`=9452; -- Scarlet Enchanter
UPDATE `creature_template` SET `minlevel`=42, `maxlevel`=43, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `unit_flags`=32768, `dynamicflags`=0 WHERE `entry`=9450; -- Scarlet Curate
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=6547; -- Suffering Victim
UPDATE `creature_template` SET `minlevel`=42, `maxlevel`=43, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `unit_flags`=32768, `dynamicflags`=0 WHERE `entry`=9451; -- Scarlet Archmage
UPDATE `creature_template` SET `speed_walk`=1.385714, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=16212; -- Dispatch Commander Metz
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000 WHERE `entry`=48705; -- Gertrude Nozzlerocket
UPDATE `creature_template` SET `minlevel`=44, `maxlevel`=44, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000 WHERE `entry`=48708; -- The Uncrashable
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=11033; -- Smokey LaRue
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `npcflag`=2, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000 WHERE `entry`=48704; -- Gek Nozzlerocket
UPDATE `creature_template` SET `npcflag`=3, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=16376; -- Craftsman Wilhelm
UPDATE `creature_template` SET `gossip_menu_id`=0, `faction_A`=2071, `faction_H`=2071, `npcflag`=130, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=11536; -- Quartermaster Miranda Breechlock
UPDATE `creature_template` SET `faction_A`=2070, `faction_H`=2070, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=11039; -- Duke Nicholas Zverenhoff
UPDATE `creature_template` SET `gossip_menu_id`=12081, `minlevel`=44, `maxlevel`=44, `faction_A`=474, `faction_H`=474, `npcflag`=1, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33536 WHERE `entry`=46022; -- Beezil Linkspanner
UPDATE `creature_template` SET `gossip_menu_id`=12236, `minlevel`=85, `maxlevel`=85, `faction_A`=2070, `faction_H`=2070, `npcflag`=8193, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=12617; -- Khaelyn Steelwing
UPDATE `creature_template` SET `gossip_menu_id`=12237, `minlevel`=85, `maxlevel`=85, `faction_A`=2070, `faction_H`=2070, `npcflag`=8193, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=12636; -- Georgia
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=17069; -- Emissary Whitebeard
UPDATE `creature_template` SET `faction_A`=2167, `faction_H`=2167, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=16134; -- Rimblat Earthshatter
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=17072; -- Emissary Gormok
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=16225; -- Pack Mule
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=16283; -- Packmaster Stonebruiser
UPDATE `creature_template` SET `npcflag`=128, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=12941; -- Jase Farlane
UPDATE `creature_template` SET `npcflag`=66177, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=16256; -- Jessica Chambers
UPDATE `creature_template` SET `faction_A`=2070, `faction_H`=2070, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=11036; -- Leonid Barthalomew the Revered
UPDATE `creature_template` SET `gossip_menu_id`=7215, `minlevel`=80, `maxlevel`=80, `npcflag`=3, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33280, `dynamicflags`=0 WHERE `entry`=16365; -- Master Craftsman Omarion
UPDATE `creature_template` SET `faction_A`=2070, `faction_H`=2070, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=11034; -- Lord Maxwell Tyrosus
UPDATE `creature_template` SET `gossip_menu_id`=12530, `minlevel`=42, `maxlevel`=42, `npcflag`=3, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=2, `unit_flags`=768 WHERE `entry`=49856; -- Lord Raymond George
UPDATE `creature_template` SET `minlevel`=41, `maxlevel`=42, `faction_A`=21, `faction_H`=21, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=45692; -- Noxious Assassin
UPDATE `creature_template` SET `minlevel`=41, `maxlevel`=42, `faction_A`=21, `faction_H`=21, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=2, `unit_flags`=32768 WHERE `entry`=45691; -- Skullmage
UPDATE `creature_template` SET `minlevel`=42, `maxlevel`=43, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `unit_flags`=32768, `dynamicflags`=0 WHERE `entry`=9448; -- Scarlet Praetorian
UPDATE `creature_template` SET `minlevel`=43, `maxlevel`=43, `faction_A`=2230, `faction_H`=2230, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=2, `unit_flags`=537166592, `dynamicflags`=32 WHERE `entry`=46138; -- Argent Centurion
UPDATE `creature_template` SET `speed_walk`=1.289683, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=29202; -- Knight of the Ebon Blade
UPDATE `creature_template` SET `minlevel`=42, `maxlevel`=42, `faction_A`=16, `faction_H`=16, `speed_walk`=1.142857, `speed_run`=1.6, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=64, `dynamicflags`=0 WHERE `entry`=10821; -- Hed'mush the Rotting
UPDATE `creature_template` SET `minlevel`=41, `maxlevel`=42, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=8545; -- Stitched Golem
UPDATE `creature_template` SET `gossip_menu_id`=4463, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=29196; -- Lord Thorval
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=0.777776, `rangeattacktime`=2000, `unit_flags`=32768, `dynamicflags`=0 WHERE `entry`=29212; -- Risen Drudge
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=28489; -- Disciple of Blood
UPDATE `creature_template` SET `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=28488; -- Coldwraith
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=28490; -- Disciple of Frost
UPDATE `creature_template` SET `gossip_menu_id`=4463, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=29194; -- Amal'thazad
UPDATE `creature_template` SET `speed_walk`=1.385714, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=29246; -- Highlord Darion Mograine
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=29205; -- Corpulous
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=28481; -- Runeforge (SE)
UPDATE `creature_template` SET `speed_walk`=1.285714, `speed_run`=2, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=29239; -- Vigilant Gargoyle
UPDATE `creature_template` SET `npcflag`=640, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=29207; -- Gangrenus
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=0.777776, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=29208; -- Fester
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=29203; -- Alchemist Karloff
UPDATE `creature_template` SET `minlevel`=72, `maxlevel`=72, `faction_A`=2050, `faction_H`=2050, `npcflag`=128, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `unit_flags`=32768, `dynamicflags`=0 WHERE `entry`=28512; -- Quartermaster Ozorg
UPDATE `creature_template` SET `rangeattacktime`=2000, `dynamicflags`=4 WHERE `entry`=32546; -- Ebon Knight's Training Dummy
UPDATE `creature_template` SET `baseattacktime`=2000, `rangeattacktime`=2000, `dynamicflags`=4 WHERE `entry`=32545; -- Initiate's Training Dummy
UPDATE `creature_template` SET `minlevel`=88, `maxlevel`=88, `faction_A`=7, `faction_H`=7, `speed_run`=1, `baseattacktime`=2400, `rangeattacktime`=2000, `unit_flags`=131072, `dynamicflags`=4 WHERE `entry`=54344; -- Highlord's Nemesis Trainer
UPDATE `creature_template` SET `rangeattacktime`=2000, `dynamicflags`=4 WHERE `entry`=32542; -- Disciple's Training Dummy
UPDATE `creature_template` SET `rangeattacktime`=2000, `dynamicflags`=4 WHERE `entry`=32543; -- Veteran's Training Dummy
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=23033; -- Invisible Stalker (Floating)
UPDATE `creature_template` SET `speed_walk`=1.385714, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=27928; -- Siouxsie the Banshee
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=0.8, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=28486; -- Squire Edwards
UPDATE `creature_template` SET `speed_walk`=1.289683, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=29587; -- Dread Commander Thalanor
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `speed_walk`=1.142857, `speed_run`=0.777776, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=29480; -- Grimwing
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=29589; -- Teleport - Heart -> Hall (EPL)
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=29588; -- Teleport - Hall -> Heart (EPL)
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=28500; -- Master Siegesmith Corvus
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=28491; -- Disciple of the Unholy
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=0.777776, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=29232; -- Forgotten Servant
UPDATE `creature_template` SET `gossip_menu_id`=10371, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=29195; -- Lady Alistra

DELETE FROM `creature_template_addon` WHERE `entry` IN (8596, 8596, 45417, 45423, 8596, 8596, 8596, 37888, 2110, 8596, 8603, 8596, 8603, 8596, 8603, 8596, 8596, 8596, 8534, 8596, 15475, 15476, 14881, 15476, 15476, 45439, 45439, 14881, 14881, 15476, 14881, 15476, 15476, 15475, 15475, 8555, 2110, 16117, 8557, 45439, 14881, 8556, 15476, 11140, 8555, 8557, 14881, 45439, 14881, 15475, 15476, 15476, 15475, 45439, 14881, 16117, 45439, 15475, 14881, 12384, 8524, 45439, 15475, 14881, 45439, 14881, 45439, 15475, 16117, 45439, 15475, 15476, 14881, 15475, 14881, 8556, 15476, 15476, 15475, 15475, 15476, 8557, 15476, 45439, 14881, 15475, 14881, 45439, 45439, 15475, 8530, 45439, 15476, 45439, 15476, 15476, 45439, 15475, 15476, 15475, 15476, 15476, 15475, 15475, 45439, 15476, 45439, 14881, 14881, 14881, 16117, 45439, 15475, 14881, 14881, 15475, 14881, 45439, 15475, 8557, 8557, 8556, 14881, 14881, 15476, 15476, 14881, 15476, 15475, 15476, 15475, 15476, 45439, 15476, 14881, 15476, 14881, 14881, 15476, 45439, 14881, 14881, 14881, 45439, 15476, 14881, 15475, 45439, 14881, 45439, 16117, 8555, 8555, 8558, 15475, 14881, 15475, 15476, 15475, 45439, 15476, 15476, 15476, 45439, 15475, 15476, 14881, 15475, 15476, 45439, 14881, 14881, 14881, 15476, 15475, 8558, 15475, 15475, 15476, 45439, 15476, 15475, 45439, 45439, 14881, 15475, 15475, 14881, 15476, 45439, 15476, 15475, 45439, 15476, 15475, 15475, 8555, 8557, 15475, 45439, 15475, 14881, 15476, 15475, 15476, 14881, 15476, 15476, 15476, 45439, 45439, 14881, 14881, 45439, 15475, 15476, 15476, 15476, 15476, 14881, 45439, 15475, 15475, 15475, 15476, 14881, 45439, 15476, 14881, 15475, 45439, 45439, 15475, 45439, 14881, 14881, 45439, 45439, 15475, 8558, 15475, 15475, 15475, 14881, 14881, 14881, 45439, 15476, 14881, 15476, 45439, 15476, 15476, 15476, 14881, 15476, 15476, 45439, 14881, 15475, 15476, 45439, 15476, 14881, 15476, 15476, 14881, 45439, 15476, 15475, 15476, 14881, 14881, 15476, 15476, 14881, 15475, 15476, 15475, 15475, 15475, 45439, 15475, 8557, 45439, 14881, 14881, 15476, 14881, 15475, 45439, 15476, 14881, 14881, 14881, 14881, 14881, 14881, 14881, 14881, 14881, 14881, 14881, 14881, 14881, 14881, 14881, 8557, 14881, 14881, 14881, 14881, 14881, 14881, 8555, 8556, 14881, 14881, 14881, 14881, 8558, 8603, 45428, 53649, 8603, 8603, 8603, 8603, 8600, 8603, 8596, 8596, 8596, 8596, 8596, 8596, 8596, 8596, 8596, 8596, 8596, 20725, 8596, 8596, 8596, 8603, 20725, 8596, 8596, 20725, 8596, 8596, 8596, 8596, 20725, 8596, 8596, 41178, 2110, 8524, 16117, 16117, 16117, 8530, 8524, 16117, 16117, 2110, 8524, 8524, 8530, 16117, 16117, 8524, 8530, 2110, 2110, 8524, 8523, 16117, 8523, 8530, 16117, 8524, 16117, 16117, 16117, 8530, 32520, 32520, 32520, 32520, 8530, 20725, 10780, 8598, 8605, 8605, 10780, 8602, 8605, 20725, 8598, 8602, 8605, 8598, 45851, 8598, 8605, 8524, 45828, 47106, 47060, 47060, 44240, 47060, 44233, 47060, 47105, 47060, 47060, 8598, 8605, 10780, 8602, 8602, 45886, 8600, 8603, 8596, 8603, 8596, 8596, 8596, 8596, 8596, 8596, 8596, 8596, 8600, 8603, 20725, 20725, 8596, 8596, 45444, 45443, 45444, 45443, 45443, 45444, 45443, 45443, 45443, 20725, 45443, 45444, 45443, 45443, 45444, 45443, 45444, 45443, 45443, 45444, 45443, 45444, 45443, 45443, 45443, 45444, 45444, 45443, 45443, 45443, 45444, 45443, 45443, 20725, 45443, 20725, 45443, 45443, 45444, 45444, 45443, 45443, 10779, 45429, 20725, 8596, 8596, 8603, 2110, 8596, 8596, 8602, 8598, 8602, 47060, 47104, 47060, 47060, 47060, 47060, 47060, 45851, 8530, 8530, 8524, 8534, 8530, 8534, 8524, 8523, 8553, 8524, 8524, 8530, 8530, 8530, 8523, 45851, 8605, 8535, 45895, 8598, 45893, 8600, 8603, 20725, 2110, 20725, 8600, 8596, 8596, 8534, 8600, 8600, 8603, 20725, 2110, 11290, 8596, 20725, 8596, 45453, 8596, 8596, 8603, 32520, 32520, 32520, 32520, 45893, 45886, 8523, 8524, 8524, 8530, 8534, 8524, 8530, 8523, 8523, 8523, 8524, 8524, 45851, 8547, 45851, 8523, 8524, 8547, 8523, 8523, 45851, 8524, 45895, 20725, 8603, 8596, 8600, 8534, 20725, 8603, 20725, 8596, 8600, 8600, 8596, 2110, 45453, 45453, 2110, 45453, 10779, 45453, 45453, 10780, 11291, 11291, 11290, 2110, 2110, 11291, 11291, 11291, 11290, 11291, 12250, 11291, 12250, 11291, 8596, 20725, 8596, 8603, 8603, 11290, 20725, 20725, 45453, 8596, 8596, 8603, 20725, 45453, 20725, 8603, 8600, 20725, 8600, 8600, 20725, 20725, 8600, 8603, 8596, 45475, 45897, 45897, 45897, 45897, 45897, 45897, 45897, 10779, 45886, 45897, 45897, 45895, 10779, 45897, 45897, 8523, 8530, 8524, 45851, 8530, 8553, 8553, 8524, 8524, 45851, 45867, 8553, 8547, 41178, 8553, 8524, 8553, 45831, 45868, 8523, 8530, 8530, 8523, 45897, 45897, 45897, 45897, 10779, 20725, 45897, 45897, 45897, 45475, 45475, 45475, 8596, 2110, 8596, 8596, 8596, 8534, 8603, 20725, 8596, 8596, 8596, 20725, 8596, 8596, 32520, 32520, 32520, 32520, 8603, 8596, 20725, 8600, 8603, 8603, 2110, 2110, 8534, 8596, 8596, 2110, 16135, 8529, 8534, 45475, 45897, 45897, 45897, 20725, 45897, 45897, 45851, 8530, 45851, 45851, 41200, 45851, 45851, 8523, 45851, 8530, 8523, 8530, 45851, 8524, 8530, 45851, 45897, 45897, 45897, 45475, 2110, 8603, 8600, 8534, 8600, 20725, 8596, 8596, 20725, 8596, 8603, 51986, 51986, 51986, 51986, 2110, 35114, 2110, 8603, 8596, 8600, 8596, 20725, 8596, 8600, 8596, 8600, 8529, 45897, 45897, 45897, 45897, 8523, 8534, 8523, 8523, 45851, 45851, 45851, 45851, 8524, 8523, 8523, 8523, 8534, 8524, 45851, 45851, 45851, 45851, 45897, 45897, 45897, 45897, 45485, 45485, 45485, 45485, 45485, 8550, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45488, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 8529, 8529, 8529, 8529, 8603, 41178, 47064, 2110, 10926, 2110, 2110, 2110, 2110, 8600, 32520, 32520, 32520, 32520, 47064, 51986, 51986, 47064, 47064, 47064, 47064, 47064, 47060, 47060, 47064, 47064, 47064, 47060, 47060, 47060, 47060, 10667, 45500, 44240, 44232, 47060, 2110, 8596, 8596, 8529, 8546, 8546, 8529, 8529, 8550, 8546, 8529, 8550, 8550, 45897, 45897, 45897, 45897, 45851, 8547, 8524, 8530, 45851, 45851, 10819, 45851, 45851, 45851, 8523, 8530, 8550, 8529, 8596, 8600, 47060, 47060, 11063, 47139, 45451, 47064, 47064, 47064, 47064, 47064, 47064, 47064, 47064, 47064, 8600, 8600, 47064, 46016, 46016, 46016, 46016, 10780, 46016, 46016, 20725, 8600, 8600, 8600, 8534, 47064, 47064, 47064, 47064, 8600, 8600, 8596, 2110, 47064, 8603, 8596, 10817, 8603, 8603, 20725, 8596, 8600, 11288, 11288, 11289, 11288, 11289, 11288, 11288, 11288, 11289, 11288, 8546, 8550, 8529, 8529, 8546, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45486, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 8550, 8546, 8529, 8529, 45485, 41178, 8553, 8524, 8530, 8534, 8524, 45851, 8530, 45851, 45851, 45851, 8524, 8523, 8524, 8523, 8524, 8524, 8524, 8530, 10826, 8550, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45487, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 8546, 8546, 8529, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 45485, 11288, 8596, 8603, 20725, 8600, 8600, 32520, 32520, 32520, 32520, 8600, 11621, 8600, 8600, 8600, 8600, 10779, 8600, 46016, 46016, 46016, 46016, 46016, 46016, 46016, 46016, 46016, 46016, 45450, 46016, 46016, 46016, 46016, 46016, 46016, 46016, 46016, 8596, 8600, 10779, 46016, 46016, 10779, 8600, 8600, 10779, 11621, 11621, 11621, 11621, 11620, 11620, 11621, 11620, 11620, 8600, 8600, 8600, 10780, 8600, 8600, 8603, 8600, 10779, 10780, 8534, 8534, 8596, 8596, 8601, 2110, 8601, 8596, 8601, 8602, 8598, 8602, 8598, 8602, 8605, 8535, 8598, 8530, 8598, 8523, 8524, 8524, 8523, 8553, 45851, 8524, 8534, 45851, 8530, 8524, 8598, 10779, 8602, 8602, 8598, 11897, 10780, 8598, 10779, 8602, 16229, 16228, 16228, 16228, 16228, 16228, 16228, 2110, 16229, 16229, 16284, 8603, 20725, 8597, 8597, 8603, 8596, 8600, 8600, 8600, 8600, 8600, 8600, 8600, 8600, 20725, 8600, 8600, 20725, 8600, 8600, 20725, 20725, 20725, 8601, 8603, 10780, 8597, 8601, 8534, 10779, 8603, 8601, 8597, 20725, 2110, 20725, 8602, 8598, 8605, 41178, 10780, 10779, 8605, 8598, 8602, 8602, 8598, 10780, 8598, 10780, 8598, 8602, 8598, 8598, 2110, 2110, 8535, 8598, 8605, 20725, 8522, 8521, 8522, 8597, 8601, 8597, 10779, 8601, 45657, 45657, 45650, 45650, 45650, 45655, 45655, 45657, 45655, 45657, 10779, 32520, 32520, 32520, 32520, 8600, 8600, 20725, 8600, 8600, 8600, 8600, 20725, 8600, 8534, 45664, 8600, 45657, 45655, 45657, 45650, 45650, 45650, 45657, 45655, 2110, 45655, 45650, 45664, 45655, 45655, 45657, 45650, 45657, 47060, 45655, 45650, 45657, 45664, 45650, 45655, 45655, 45650, 45650, 45650, 45655, 45657, 45657, 45657, 45657, 45657, 45650, 45655, 45655, 45650, 45655, 47060, 45664, 45664, 45655, 45650, 45664, 45655, 45650, 45657, 45650, 45657, 45657, 2110, 45650, 8603, 2110, 8601, 8597, 8597, 8597, 8601, 8603, 8601, 10780, 8601, 8603, 8603, 8534, 8522, 20725, 20725, 8521, 8521, 8602, 8598, 8598, 8602, 8598, 8602, 10779, 2110, 8602, 8605, 8598, 10780, 8605, 8602, 10780, 8598, 45816, 41177, 41177, 41177, 41195, 41195, 41195, 41195, 41177, 41177, 41177, 41195, 8564, 8602, 10780, 8563, 20725, 8563, 8564, 8563, 8565, 8565, 8565, 8563, 8565, 8565, 8565, 8565, 8565, 8565, 8565, 8563, 8565, 8565, 20725, 8563, 8565, 8564, 8565, 8565, 8564, 8563, 8563, 8565, 8564, 8565, 45826, 47060, 47060, 47060, 47060, 47060, 47060, 8605, 8602, 8598, 8602, 8598, 8598, 10780, 8598, 8602, 2110, 2110, 8601, 2110, 8601, 8601, 8601, 8597, 8601, 8597, 47060, 47060, 47060, 45657, 45650, 45650, 45650, 45655, 45657, 45655, 45657, 47060, 47060, 45657, 47060, 45655, 45655, 45650, 45650, 45650, 45655, 45655, 45655, 45650, 45657, 45657, 45657, 45650, 45664, 45657, 45655, 45650, 45650, 45655, 45655, 45650, 45650, 45650, 45657, 45657, 8600, 45650, 45650, 45655, 8600, 8600, 8600, 8596, 8596, 8600, 8600, 20725, 20725, 8600, 20725, 8600, 45664, 45655, 45650, 45657, 45655, 45655, 45650, 45657, 45655, 45655, 45657, 45657, 45664, 45664, 45655, 45655, 45657, 45655, 45650, 45655, 45650, 45650, 45664, 45664, 45657, 45655, 45657, 45657, 45655, 45650, 45657, 45664, 45657, 45655, 45655, 45650, 45650, 45655, 45650, 45650, 45655, 45655, 45650, 45655, 45650, 45657, 45655, 45650, 45655, 45657, 45657, 45650, 45650, 45655, 47060, 47060, 8601, 8603, 8601, 20725, 8601, 8601, 8598, 8605, 8598, 8598, 47164, 47166, 10779, 17878, 10780, 17878, 47060, 47165, 47167, 47060, 47060, 47060, 47060, 45482, 44240, 28621, 20725, 8598, 8602, 2110, 20725, 8598, 8598, 8602, 10779, 8597, 10779, 8534, 8597, 47060, 44231, 47060, 44240, 47060, 47060, 20725, 8525, 45657, 45664, 45657, 45655, 45650, 45650, 45655, 45655, 45650, 45664, 45650, 45650, 45655, 45650, 45655, 45650, 45657, 45657, 45657, 45657, 45650, 45650, 45655, 45655, 45655, 45655, 45650, 45650, 45650, 8600, 20725, 8600, 8600, 8603, 20725, 32520, 32520, 32520, 32520, 8596, 20725, 8596, 8520, 2110, 8541, 8541, 8525, 8538, 8541, 8548, 8541, 8543, 2110, 45655, 45655, 45657, 8551, 8541, 8538, 45655, 45650, 45655, 45657, 45650, 45650, 8548, 8541, 8541, 8541, 45655, 45650, 45650, 45655, 45657, 11035, 47153, 45655, 45575, 47060, 47149, 47060, 47060, 47060, 47148, 8603, 10779, 8597, 8597, 8598, 8535, 10779, 10780, 2110, 10780, 10780, 17878, 17878, 17878, 11706, 17878, 17878, 10780, 17878, 17878, 17878, 17878, 17878, 17878, 17878, 8605, 10780, 8605, 8605, 8598, 2110, 8605, 8602, 8602, 8605, 2110, 2110, 8601, 8601, 20725, 20725, 8603, 47060, 47060, 47060, 47060, 41178, 8531, 8551, 8525, 8548, 8541, 8548, 8526, 8526, 8531, 8525, 45657, 8551, 8541, 8541, 8551, 8551, 8551, 8531, 8548, 8526, 2110, 8551, 8541, 8541, 8548, 8548, 8541, 8526, 45650, 8525, 8531, 45650, 1843, 2110, 8534, 8519, 8534, 8520, 8519, 8520, 8519, 8596, 8600, 8603, 20725, 20725, 8534, 8520, 8520, 8520, 8519, 2110, 8519, 8520, 10779, 20725, 8525, 20725, 8525, 8531, 20725, 8525, 8526, 8541, 8548, 8538, 8548, 8543, 8543, 8543, 8551, 8525, 8541, 2110, 8525, 2110, 2110, 8601, 8597, 8597, 8601, 8603, 8602, 2110, 8605, 8602, 8605, 8598, 17878, 17878, 17878, 17878, 20725, 8605, 10780, 8560, 20725, 8561, 2110, 8605, 8598, 8605, 8535, 11896, 8605, 2110, 10780, 8602, 8598, 8602, 8544, 20725, 10779, 8605, 10779, 8602, 8605, 10779, 20725, 10780, 8543, 10780, 20725, 8603, 8596, 8520, 8520, 8519, 8519, 8596, 20725, 20725, 8603, 8600, 44775, 8519, 8519, 8519, 8519, 8600, 32520, 32520, 32520, 32520, 8534, 10780, 8605, 8605, 8605, 8603, 8603, 8603, 8605, 20725, 8603, 8601, 8534, 20725, 8601, 20725, 8601, 8597, 47060, 47060, 47060, 10779, 47060, 47060, 47060, 8602, 8598, 10779, 20725, 8544, 8527, 8527, 8544, 10779, 45744, 8544, 8544, 2110, 8544, 8544, 8544, 45743, 45743, 8527, 2110, 45743, 45743, 8544, 20725, 8598, 8605, 8602, 8598, 20725, 8602, 2110, 8561, 10780, 8561, 8560, 8560, 8561, 8561, 8562, 8560, 8562, 10823, 8561, 8562, 8562, 8535, 8602, 2110, 8602, 8598, 8605, 8605, 8527, 8598, 20725, 8544, 8535, 8527, 10779, 8544, 8598, 20725, 8527, 45743, 45743, 8544, 8527, 2110, 8598, 8527, 8544, 47142, 47144, 44240, 45735, 47060, 47060, 47060, 10780, 8598, 44230, 45736, 8601, 10779, 20725, 8603, 8603, 8597, 8601, 8601, 20725, 8605, 8601, 8603, 8603, 2110, 8603, 8605, 8605, 8603, 10780, 20725, 8605, 20725, 20725, 8603, 8600, 10779, 8548, 8548, 8548, 8551, 8551, 8551, 8548, 8551, 8551, 8548, 8551, 8603, 8596, 20725, 8603, 20725, 10780, 8603, 8603, 8605, 8603, 8603, 8605, 8605, 8603, 8605, 8603, 8597, 8601, 8601, 20725, 8601, 8603, 10780, 8601, 10780, 8598, 8598, 8598, 10779, 8535, 8544, 8598, 10780, 10780, 8540, 8540, 8540, 8560, 8560, 8562, 8562, 8562, 8560, 8561, 8562, 8561, 8561, 8560, 8561, 8562, 8562, 8561, 10822, 8560, 8561, 8560, 8562, 8562, 8561, 8561, 8562, 8562, 8540, 2110, 8537, 8540, 8540, 8521, 10779, 10779, 8605, 8535, 8601, 8603, 8605, 8603, 8600, 8596, 2110, 8603, 8603, 20725, 8603, 8603, 8605, 8603, 8603, 8605, 20725, 32520, 32520, 32520, 32520, 10780, 8603, 20725, 20725, 8598, 10779, 8605, 20725, 8602, 8602, 8521, 8521, 8521, 2110, 8540, 8540, 8540, 8540, 8540, 8537, 8540, 8540, 8540, 8562, 41200, 8561, 8561, 8561, 8561, 8561, 8561, 8561, 8562, 8561, 8561, 8560, 41178, 8540, 8537, 8537, 8540, 8598, 8601, 10779, 10779, 8605, 10780, 8605, 2110, 2110, 2110, 8605, 8603, 8605, 10780, 8605, 10780, 8603, 8603, 8605, 10780, 8605, 8603, 20725, 47060, 47060, 47060, 47060, 47060, 47060, 8597, 8601, 8605, 8605, 20725, 8605, 8540, 8535, 8605, 8602, 2110, 8532, 8532, 20725, 47060, 47060, 20725, 8603, 8603, 8605, 8603, 2110, 45681, 43359, 40728, 40987, 44140, 40728, 40728, 42851, 42851, 42851, 42851, 42851, 42851, 42851, 42851, 42851, 42851, 42851, 42851, 42851, 42851, 42851, 42851, 42851, 42851, 42851, 42851, 42851, 42173, 42173, 42196, 42196, 37490, 42173, 37490, 8603, 8603, 10780, 8603, 8603, 8605, 8603, 8603, 8605, 8605, 20725, 20725, 8528, 8532, 8542, 2110, 45695, 46167, 8532, 8528, 8528, 2110, 8528, 8532, 32520, 32520, 32520, 32520, 45695, 8542, 8528, 8528, 8532, 45695, 16378, 16378, 47288, 16378, 16378, 16378, 16378, 16378, 10779, 47289, 47289, 16378, 16378, 16378, 47286, 11102, 11102, 47289, 47289, 47289, 47289, 47289, 16378, 16378, 2110, 16378, 11038, 16378, 16378, 8534, 8603, 2110, 8605, 8605, 8603, 10780, 10780, 8603, 8603, 8605, 8603, 9447, 9447, 9447, 9449, 9449, 9447, 16115, 16116, 16112, 9447, 9452, 9449, 9447, 9447, 9452, 9447, 9450, 9447, 6547, 9451, 9447, 9447, 6547, 9447, 6547, 9452, 9447, 9447, 9450, 9452, 44775, 9447, 9447, 9447, 9449, 9447, 9447, 9447, 8605, 41178, 2110, 16378, 16212, 16378, 48705, 48708, 11033, 16378, 48704, 16378, 16376, 11536, 11039, 46022, 16378, 12617, 16378, 12636, 47289, 17069, 16134, 17072, 16378, 16284, 16225, 16283, 16378, 16225, 12941, 16378, 16225, 16256, 11036, 44240, 16365, 11034, 16378, 16378, 16378, 16378, 49856, 2110, 2110, 16378, 16378, 16378, 16378, 16378, 45692, 45695, 45695, 45695, 8542, 45695, 45695, 8532, 8532, 8542, 45695, 8532, 8532, 8528, 45691, 45695, 45691, 45691, 45691, 45695, 8532, 8542, 8528, 45692, 45691, 45692, 45691, 45692, 45695, 45692, 45691, 45695, 45695, 45695, 45691, 45691, 45695, 8528, 45692, 8532, 45691, 45695, 45695, 9447, 9447, 9449, 9452, 9449, 9447, 9452, 9447, 9452, 9447, 9447, 9447, 9448, 9448, 9450, 9448, 9448, 46138, 9448, 9452, 9449, 9447, 9448, 9448, 9452, 9449, 9448, 9449, 9449, 9449, 9449, 9449, 9449, 9447, 9447, 9452, 9452, 9449, 9449, 9447, 9452, 9452, 9452, 9449, 9452, 9449, 9452, 9452, 9452, 9452, 9449, 9452, 32520, 32520, 32520, 32520, 29202, 8528, 8532, 45695, 8542, 10821, 8542, 8532, 8532, 45695, 8532, 45695, 45695, 8545, 45695, 8545, 45695, 45695, 8545, 45691, 45691, 8545, 45695, 45692, 8528, 45691, 8528, 45695, 8528, 45695, 45695, 45692, 45691, 8532, 8532, 8542, 45691, 45692, 45695, 8528, 29202, 29202, 29196, 29212, 29202, 29212, 29202, 29202, 28489, 28489, 28489, 28489, 28489, 28489, 28489, 28489, 29202, 29202, 28488, 28488, 28490, 28490, 28490, 28490, 29194, 28490, 28490, 28490, 28490, 28488, 28490, 28488, 29246, 29212, 29212, 29212, 29212, 29212, 29212, 29212, 29212, 29212, 29212, 29212, 29212, 29202, 29202, 29202, 29212, 29205, 29202, 29212, 28481, 29239, 29202, 29202, 9447, 9447, 9452, 9448, 9448, 9450, 9448, 9450, 9451, 9448, 9448, 9448, 9448, 9450, 9451, 9448, 9448, 9451, 9450, 9450, 9451, 9450, 9450, 9450, 9448, 9448, 9448, 9451, 9448, 9448, 9448, 9448, 9450, 9451, 9450, 9450, 9450, 9451, 9448, 29202, 29202, 29202, 28490, 29202, 29207, 29208, 29203, 29212, 28512, 29212, 29212, 29212, 29212, 29202, 32546, 32546, 29212, 29202, 32546, 29239, 32545, 32545, 29239, 29239, 29239, 29202, 29202, 32545, 54344, 32542, 32542, 29202, 32543, 32542, 28481, 29202, 32543, 32543, 29212, 29212, 29212, 29212, 29212, 29212, 29212, 29212, 29212, 29212, 29212, 29212, 29212, 29239, 29212, 29212, 29239, 29202, 29202, 29202, 29202, 29212, 29212, 29212, 29212, 29212, 29202, 29202, 29202, 29212, 29202, 23033, 29202, 27928, 28486, 29587, 29480, 29202, 29202, 29202, 29202, 29202, 29589, 29588, 29202, 29202, 29202, 29239, 2110, 29202, 29202, 29202, 28500, 29212, 29202, 28491, 28491, 28491, 29232, 28491, 28481, 28491, 29232, 28491, 29232, 28491, 29195, 28491, 28491, 28491, 28491, 28491, 32520, 32520, 32520, 32520, 2110, 2110, 2110, 2110, 2110, 2110, 2110, 2110, 2110, 2110, 2110, 41178, 32520, 32520, 32520, 32520);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(10667, 0, 0x0, 0x1, ''), -- Chromie
(10779, 0, 0x0, 0x1, ''), -- Infected Squirrel
(10780, 0, 0x0, 0x1, ''), -- Infected Deer
(10817, 0, 0x0, 0x1, '55664'), -- Duggan Wildhammer - Cosmetic - Drunken Intoxication (Visual Only)
(10819, 0, 0x0, 0x1, ''), -- Baron Bloodbane
(10821, 0, 0x1, 0x1, '16577'), -- Hed'mush the Rotting - Disease Cloud
(10822, 0, 0x0, 0x1, ''), -- Warlord Thresh'jin
(10823, 0, 0x0, 0x1, ''), -- Zul'Brin Warpbranch
(10826, 0, 0x0, 0x1, '79934'), -- Lord Darkscythe - Demon Armor
(10926, 0, 0x0, 0x1, '17327'), -- Pamela Redpath - Spirit Particles
(11033, 0, 0x0, 0x1, ''), -- Smokey LaRue
(11034, 0, 0x0, 0x1, ''), -- Lord Maxwell Tyrosus
(11035, 0, 0x0, 0x1, ''), -- Betina Bigglezink
(11036, 0, 0x0, 0x1, ''), -- Leonid Barthalomew the Revered
(11038, 0, 0x0, 0x1, ''), -- Caretaker Alen
(11039, 0, 0x0, 0x1, ''), -- Duke Nicholas Zverenhoff
(11063, 0, 0x0, 0x1, ''), -- Carlin Redpath
(11102, 28918, 0x0, 0x1, ''), -- Argent Rider
(11140, 0, 0x0, 0x2, ''), -- Egan
(11288, 0, 0x0, 0x1, ''), -- Spectral Betrayer
(11289, 0, 0x0, 0x1, '17327'), -- Spectral Defender - Spirit Particles
(11290, 0, 0x0, 0x1, ''), -- Mossflayer Zombie
(11291, 0, 0x0, 0x1, ''), -- Unliving Mossflayer
(11536, 0, 0x0, 0x1, ''), -- Quartermaster Miranda Breechlock
(11620, 0, 0x0, 0x1, ''), -- Spectral Marauder
(11621, 0, 0x7, 0x1, '17327'), -- Spectral Corpse - Spirit Particles
(11706, 0, 0x0, 0x1, ''), -- Adon
(11896, 0, 0x0, 0x1, '16428'), -- Borelgore - Virulent Poison Proc
(11897, 0, 0x3000000, 0x1, ''), -- Duskwing
(12250, 0, 0x0, 0x1, ''), -- Zaeldarr the Outcast
(12384, 0, 0x0, 0x101, ''), -- Augustus the Touched
(12617, 0, 0x0, 0x100, ''), -- Khaelyn Steelwing
(12636, 0, 0x0, 0x101, ''), -- Georgia
(12941, 0, 0x0, 0x1, ''), -- Jase Farlane
(14881, 0, 0x0, 0x1, ''), -- Spider
(15475, 0, 0x0, 0x1, ''), -- Beetle
(15476, 0, 0x0, 0x1, ''), -- Scorpion
(16112, 0, 0x0, 0x101, ''), -- Korfax, Champion of the Light
(16115, 0, 0x0, 0x101, ''), -- Commander Eligor Dawnbringer
(16116, 0, 0x0, 0x101, ''), -- Archmage Angela Dosantos
(16117, 0, 0x0, 0x1, ''), -- Plagued Swine
(16134, 0, 0x10000, 0x1, '80852'), -- Rimblat Earthshatter - Generic Quest Invisibility 10
(16135, 0, 0x0, 0x101, '58506'), -- Rayne - Stealth
(16212, 2402, 0x0, 0x1, ''), -- Dispatch Commander Metz
(16225, 0, 0x0, 0x1, ''), -- Pack Mule
(16228, 0, 0x0, 0x1, ''), -- Argent Dawn Infantry
(16229, 0, 0x1, 0x1, ''), -- Injured Argent Dawn Infantry
-- (16229, 0, 0x3, 0x1, ''), -- Injured Argent Dawn Infantry
(16256, 0, 0x0, 0x101, ''), -- Jessica Chambers
(16283, 0, 0x0, 0x101, ''), -- Packmaster Stonebruiser
(16284, 0, 0x0, 0x1, ''), -- Argent Medic
(16365, 0, 0x0, 0x1, ''), -- Master Craftsman Omarion
(16376, 0, 0x0, 0x101, ''), -- Craftsman Wilhelm
-- (16378, 0, 0x0, 0x1, '18950'), -- Argent Sentry - Invisibility and Stealth Detection
(16378, 22471, 0x0, 0x1, ''), -- Argent Sentry
(17069, 0, 0x0, 0x1, ''), -- Emissary Whitebeard
(17072, 0, 0x0, 0x1, ''), -- Emissary Gormok
(17878, 0, 0x0, 0x1, ''), -- Scourge Siege Engineer
(1843, 0, 0x1, 0x1, ''), -- Foreman Jerris
(20725, 0, 0x0, 0x1, ''), -- Bat
(2110, 0, 0x0, 0x1, ''), -- Black Rat
(23033, 0, 0x0, 0x1, ''), -- Invisible Stalker (Floating)
(27928, 25280, 0x0, 0x100, ''), -- Siouxsie the Banshee
(28481, 0, 0x0, 0x1, ''), -- Runeforge (SE)
(28486, 0, 0x0, 0x101, ''), -- Squire Edwards
(28488, 0, 0x0, 0x101, ''), -- Coldwraith
(28489, 0, 0x0, 0x101, ''), -- Disciple of Blood
(28490, 0, 0x0, 0x101, ''), -- Disciple of Frost
(28491, 0, 0x0, 0x101, ''), -- Disciple of the Unholy
(28500, 0, 0x0, 0x1, ''), -- Master Siegesmith Corvus
(28512, 0, 0x0, 0x1, ''), -- Quartermaster Ozorg
(28621, 0, 0x0, 0x101, ''), -- Grayson Ironwing
(29194, 0, 0x0, 0x1, ''), -- Amal'thazad
(29195, 0, 0x0, 0x1, ''), -- Lady Alistra
(29196, 0, 0x0, 0x1, ''), -- Lord Thorval
(29202, 0, 0x0, 0x100, ''), -- Knight of the Ebon Blade
-- (29202, 0, 0x8, 0x101, ''), -- Knight of the Ebon Blade
-- (29202, 25280, 0x0, 0x101, ''), -- Knight of the Ebon Blade
-- (29202, 26303, 0x0, 0x101, ''), -- Knight of the Ebon Blade
-- (29202, 26303, 0x3000000, 0x101, ''), -- Knight of the Ebon Blade
(29203, 0, 0x0, 0x101, ''), -- Alchemist Karloff
(29205, 0, 0x0, 0x101, ''), -- Corpulous
(29207, 0, 0x0, 0x101, ''), -- Gangrenus
(29208, 0, 0x0, 0x101, ''), -- Fester
(29212, 0, 0x0, 0x101, ''), -- Risen Drudge
-- (29212, 0, 0x7, 0x101, ''), -- Risen Drudge
(29232, 0, 0x0, 0x1, ''), -- Forgotten Servant
(29239, 0, 0x0, 0x1, ''), -- Vigilant Gargoyle
-- (29239, 0, 0x9, 0x1, ''), -- Vigilant Gargoyle
(29246, 25279, 0x0, 0x1, ''), -- Highlord Darion Mograine
(29480, 0, 0x0, 0x101, ''), -- Grimwing
(29587, 28108, 0x0, 0x1, ''), -- Dread Commander Thalanor
(29588, 0, 0x0, 0x1, '54742'), -- Teleport - Hall -> Heart (EPL) - Teleport to Heart of Acherus
(29589, 0, 0x0, 0x1, '54745'), -- Teleport - Heart -> Hall (EPL) - Teleport to Hall of Command
(32520, 0, 0x0, 0x1, ''), -- Totally Generic Bunny (All Phase)
(32542, 0, 0x0, 0x1, ''), -- Disciple's Training Dummy
(32543, 0, 0x0, 0x1, ''), -- Veteran's Training Dummy
(32545, 0, 0x0, 0x1, ''), -- Initiate's Training Dummy
(32546, 0, 0x0, 0x1, ''), -- Ebon Knight's Training Dummy
(35114, 0, 0x0, 0x1, ''), -- ELM General Purpose Bunny (All Phases)
(37490, 0, 0x0, 0x1, ''), -- ELM General Purpose Bunny Infinite
(37888, 0, 0x0, 0x101, ''), -- Frax Bucketdrop
(40728, 0, 0x0, 0x1, '54913'), -- Whale Shark - Thrash
(40987, 0, 0x0, 0x1, ''), -- Gnash
(41177, 0, 0x7, 0x1, '77131'), -- Stitched Horror (Cosmetic) - Vertex Color Grey
(41178, 0, 0x0, 0x1, '82358'), -- Northwatch Tower Stalker - Generic Quest Invisibility 6
(41195, 0, 0x7, 0x1, '77131'), -- Cannibal Ghoul (Cosmetic) - Vertex Color Grey
(41200, 0, 0x3000000, 0x1, ''), -- Generic Bunny - PRK
(42173, 0, 0x0, 0x1, ''), -- The Undershell Tentacle Flavor
(42196, 0, 0x0, 0x1, '78715'), -- ELM General Purpose Bunny Infinite (scale x2.5) - L'ghorek: Ascendant Light Beam
(42851, 0, 0x0, 0x1, '29266'), -- Revenant of Neptulon - Permanent Feign Death
(43359, 0, 0x0, 0x1, ''), -- ELM General Purpose Bunny Infinite Hide Body
(44140, 0, 0x0, 0x1, ''), -- PetWait Trigger
(44230, 0, 0x0, 0x101, ''), -- Richard Trueflight
(44231, 0, 0x0, 0x101, ''), -- Devon Manning
(44232, 0, 0x0, 0x101, ''), -- Janice Myers
(44233, 0, 0x0, 0x101, ''), -- William Kielar Jr.
(44240, 0, 0x0, 0x1, ''), -- Argent Hippogryph
(44775, 0, 0x3000000, 0x1, ''), -- Generic Bunny - PRK (Large AOI)
(45417, 0, 0x10000, 0x1, '49414'), -- Fiona - Generic Quest Invisibility 1
(45423, 0, 0x10000, 0x1, '49414'), -- Fiona's Caravan - Generic Quest Invisibility 1
(45428, 0, 0x10000, 0x1, '80852'), -- Gidwin Goldbraids - Generic Quest Invisibility 10
(45429, 0, 0x10000, 0x1, '83305 79976 79977 79972'), -- Tarenar Sunstrike - Generic Quest Invisibility 11, Retribution Aura, Blessing of Might, Seal of Truth
(45439, 0, 0x0, 0x1, ''), -- Cockroach
(45443, 0, 0x0, 0x1, ''), -- Death's Step Putrifier
(45444, 0, 0x0, 0x1, ''), -- Death's Step Miscreation
(45450, 0, 0x0, 0x1, '84910 81238'), -- The Lone Hunter - Joseph's Hunting Blade, Cosmetic - State Dead
(45451, 0, 0x0, 0x1, ''), -- Argus Highbeacon
(45453, 0, 0x0, 0x1, '16577'), -- Blighthound - Disease Cloud
(45475, 0, 0x3000000, 0x1, ''), -- Plague Disseminator
(45482, 0, 0x0, 0x2, ''), -- Argent Officer Irizarry
(45485, 0, 0x0, 0x1, ''), -- Necropolis Flowers
(45486, 0, 0x0, 0x1, ''), -- Necropolis Flower Controller SE
(45487, 0, 0x0, 0x1, ''), -- Necropolis Flower Controller NE
(45488, 0, 0x0, 0x1, ''), -- Necropolis Flower Controller W
(45500, 0, 0x0, 0x101, ''), -- Urk Gagbaz
(45575, 0, 0x0, 0x1, ''), -- Frederick Calston
(45650, 0, 0x0, 0x1, ''), -- Plague Puffer
(45655, 0, 0x0, 0x1, ''), -- Infectis Incher
(45657, 0, 0x0, 0x1, ''), -- Infectis Scuttler
(45664, 0, 0x0, 0x1, ''), -- Landlocked Grouper
(45681, 0, 0x0, 0x1, ''), -- Garginox
(45691, 0, 0x0, 0x1, ''), -- Skullmage
-- (45691, 0, 0x0, 0x1, '8734'), -- Skullmage - Blackfathom Channeling
(45692, 0, 0x0, 0x1, ''), -- Noxious Assassin
-- (45692, 0, 0x0, 0x1, '8734'), -- Noxious Assassin - Blackfathom Channeling
(45695, 0, 0x0, 0x1, '29266 73284'), -- Slain Scourge Trooper - Permanent Feign Death, Creature Sparkles
(45735, 0, 0x0, 0x1, ''), -- Gamella Cracklefizz
(45736, 0, 0x0, 0x1, ''), -- Deacon Andaal
(45743, 0, 0x0, 0x1, ''), -- Nerubian Sycophant
(45744, 0, 0x0, 0x1, ''), -- Ix'lar the Underlord
(45816, 0, 0x0, 0x1, ''), -- Corpseburner Tim
(45826, 0, 0x8, 0x1, ''), -- Kirkian Dawnshield
(45828, 0, 0x0, 0x1, ''), -- Argent Apothecary Judkins
(45831, 0, 0x0, 0x1, ''), -- Crusader Kevin Frost
(45851, 0, 0x0, 0x1, ''), -- Overstuffed Golem
-- (45851, 0, 0x0, 0x1, '14775'), -- Overstuffed Golem - Stilled
(45867, 0, 0x0, 0x1, ''), -- Omasum Blighthoof
(45868, 0, 0x0, 0x1, ''), -- Karthis Darkrune
(45886, 0, 0x0, 0x1, '29266'), -- Corpsebeast (Giant) - Permanent Feign Death
(45893, 0, 0x0, 0x1, '29266'), -- Corpsebeast (Dog) - Permanent Feign Death
(45895, 0, 0x0, 0x1, '29266'), -- Corpsebeast (Blob) - Permanent Feign Death
(45897, 0, 0x0, 0x1, ''), -- Plaguewood Reanimator
(46016, 0, 0x0, 0x1, '85779'), -- Spectral Critter - Cosmetic - Alpha State 50% (Allow While Dead)
(46022, 0, 0x10000, 0x1, '84020'), -- Beezil Linkspanner - Generic Quest Invisibility 13
(46138, 0, 0x0, 0x1, '29266'), -- Argent Centurion - Permanent Feign Death
(46167, 0, 0x0, 0x1, ''), -- Stephen Browman
(47060, 0, 0x0, 0x1, '18950'), -- Argent Sentry - Invisibility and Stealth Detection
(47064, 0, 0x0, 0x1, ''), -- Mossflayer Abducter
(47104, 0, 0x0, 0x101, ''), -- Anthony Waler
(47105, 0, 0x0, 0x101, ''), -- Marc Daiton
(47106, 0, 0x0, 0x101, ''), -- Christine Gade
(47139, 0, 0x0, 0x101, ''), -- Gerald Fairbanks
(47142, 0, 0x0, 0x101, ''), -- Rahmalaha
(47144, 0, 0x0, 0x101, ''), -- Patricia Marshall
(47148, 0, 0x0, 0x101, ''), -- Donovan Minewell
(47149, 0, 0x0, 0x101, ''), -- Kathryn Humphries
(47153, 0, 0x0, 0x101, ''), -- Cabe Minewell
(47164, 0, 0x0, 0x101, ''), -- James Litman
(47165, 0, 0x0, 0x101, ''), -- Casey Tipple
(47166, 0, 0x0, 0x101, ''), -- Dorris Manchester
(47167, 0, 0x0, 0x101, ''), -- Brett Nelson
(47286, 0, 0x0, 0x101, ''), -- Vincent Randolph
(47288, 0, 0x0, 0x101, ''), -- Gutcheck
(47289, 0, 0x0, 0x101, ''), -- Argent Crusade Engineer
(48704, 0, 0x10000, 0x1, '87871'), -- Gek Nozzlerocket - Generic Quest Invisibility 21
(48705, 0, 0x10000, 0x1, '87871'), -- Gertrude Nozzlerocket - Generic Quest Invisibility 21
(48708, 0, 0x10000, 0x1, '87871'), -- The Uncrashable - Generic Quest Invisibility 21
(49856, 0, 0x3000000, 0x0, '92835'), -- Lord Raymond George - See Quest Invis 23
(51986, 0, 0x0, 0x1, '18950'), -- Argent Sentry - Invisibility and Stealth Detection
(53649, 0, 0x3010000, 0x1, '99628 80852'), -- Thrall - Thrall's Water Aura, Generic Quest Invisibility 10
(54344, 0, 0x0, 0x1, ''), -- Highlord's Nemesis Trainer
(6547, 0, 0x7, 0x1, ''), -- Suffering Victim
(8519, 0, 0x0, 0x1, ''), -- Blighted Surge
(8520, 0, 0x0, 0x1, '3417'), -- Plague Ravager - Thrash
(8521, 0, 0x0, 0x1, ''), -- Blighted Horror
(8522, 0, 0x0, 0x1, ''), -- Plague Monstrosity
(8523, 0, 0x0, 0x1, ''), -- Scourge Soldier
(8524, 0, 0x0, 0x1, ''), -- Cursed Mage
(8525, 0, 0x0, 0x1, ''), -- Scourge Warder
(8526, 0, 0x0, 0x1, ''), -- Dark Caster
(8527, 0, 0x0, 0x1, ''), -- Scourge Guard
(8528, 0, 0x0, 0x1, ''), -- Dread Weaver
(8529, 0, 0x0, 0x1, ''), -- Scourge Champion
(8530, 0, 0x0, 0x1, ''), -- Cannibal Ghoul
(8531, 0, 0x0, 0x1, ''), -- Gibbering Ghoul
(8532, 0, 0x0, 0x1, '8876 12539'), -- Diseased Flayer - Thrash, Ghoul Rot
(8534, 0, 0x0, 0x1, '16574'), -- Putrid Gargoyle - Putrid Bile
(8535, 0, 0x0, 0x1, '16575'), -- Putrid Shrieker - Putrid Bile
(8537, 0, 0x0, 0x1, '8279'), -- Interloper - Stealth Detection
(8538, 0, 0x0, 0x1, ''), -- Unseen Servant
(8540, 0, 0x0, 0x1, ''), -- Torn Screamer
(8541, 0, 0x0, 0x1, ''), -- Hate Shrieker
(8542, 0, 0x0, 0x1, ''), -- Death Singer
(8543, 0, 0x0, 0x1, ''), -- Stitched Horror
(8544, 0, 0x0, 0x1, ''), -- Gangled Golem
(8545, 0, 0x0, 0x1, '16577'), -- Stitched Golem - Disease Cloud
-- (8546, 0, 0x0, 0x1, '3417 8734'), -- Dark Adept - Thrash, Blackfathom Channeling
(8546, 0, 0x0, 0x1, '3417'), -- Dark Adept - Thrash
(8547, 0, 0x0, 0x1, ''), -- Death Cultist
-- (8547, 0, 0x0, 0x1, '8734'), -- Death Cultist - Blackfathom Channeling
(8548, 0, 0x0, 0x1, ''), -- Vile Tutor
-- (8548, 0, 0x0, 0x1, '16587'), -- Vile Tutor - Dark Whispers
(8550, 0, 0x0, 0x1, '16592'), -- Shadowmage - Shadowform
-- (8550, 0, 0x0, 0x1, '8734'), -- Shadowmage - Blackfathom Channeling
(8551, 0, 0x0, 0x1, ''), -- Dark Summoner
(8553, 0, 0x0, 0x1, ''), -- Necromancer
-- (8553, 0, 0x0, 0x1, '8734'), -- Necromancer - Blackfathom Channeling
(8555, 0, 0x0, 0x1, ''), -- Crypt Stalker
-- (8555, 0, 0x0, 0x1, '29266'), -- Crypt Stalker - Permanent Feign Death
-- (8556, 0, 0x0, 0x1, '3616 29266'), -- Crypt Walker - Poison Proc, Permanent Feign Death
(8556, 0, 0x0, 0x1, '3616'), -- Crypt Walker - Poison Proc
(8557, 0, 0x0, 0x1, ''), -- Crypt Horror
-- (8557, 0, 0x0, 0x1, '29266'), -- Crypt Horror - Permanent Feign Death
(8558, 0, 0x0, 0x1, ''), -- Crypt Slayer
-- (8558, 0, 0x0, 0x1, '29266'), -- Crypt Slayer - Permanent Feign Death
(8560, 0, 0x0, 0x1, ''), -- Mossflayer Scout
(8561, 0, 0x0, 0x1, ''), -- Mossflayer Shadowhunter
-- (8561, 0, 0x0, 0x1, '8734'), -- Mossflayer Shadowhunter - Blackfathom Channeling
-- (8561, 0, 0x1, 0x1, ''), -- Mossflayer Shadowhunter
(8562, 0, 0x0, 0x1, ''), -- Mossflayer Cannibal
(8563, 0, 0x0, 0x1, ''), -- Woodsman
-- (8563, 0, 0x7, 0x1, ''), -- Woodsman
-- (8563, 0, 0x7, 0x1, '96007'), -- Woodsman - Cosmetic - Sleep Zzz Breakable
(8564, 0, 0x0, 0x1, ''), -- Ranger
-- (8564, 0, 0x7, 0x1, '96007'), -- Ranger - Cosmetic - Sleep Zzz Breakable
(8565, 0, 0x0, 0x1, ''), -- Pathstrider
-- (8565, 0, 0x0, 0x1, '96007'), -- Pathstrider - Cosmetic - Sleep Zzz Breakable
-- (8565, 0, 0x7, 0x1, ''), -- Pathstrider
-- (8565, 0, 0x7, 0x1, '96007'), -- Pathstrider - Cosmetic - Sleep Zzz Breakable
(8596, 0, 0x0, 0x1, ''), -- Plaguehound Runt
(8597, 0, 0x0, 0x1, ''), -- Plaguehound
(8598, 0, 0x0, 0x1, ''), -- Frenzied Plaguehound
(8600, 0, 0x0, 0x1, ''), -- Plaguebat
(8601, 0, 0x0, 0x1, '8601'), -- Noxious Plaguebat - Slowing Poison
(8602, 0, 0x0, 0x1, ''), -- Monstrous Plaguebat
(8603, 0, 0x0, 0x1, ''), -- Carrion Grub
(8605, 0, 0x0, 0x1, ''), -- Carrion Devourer
(9447, 0, 0x0, 0x1, ''), -- Scarlet Warder
-- (9447, 0, 0x8, 0x1, ''), -- Scarlet Warder
(9448, 0, 0x0, 0x1, ''), -- Scarlet Praetorian
(9449, 0, 0x0, 0x1, ''), -- Scarlet Cleric
(9450, 0, 0x0, 0x1, ''), -- Scarlet Curate
-- (9451, 0, 0x0, 0x1, ''), -- Scarlet Archmage
(9451, 0, 0x0, 0x1, '18100'), -- Scarlet Archmage - Frost Armor
(9452, 0, 0x0, 0x1, ''); -- Scarlet Enchanter
-- (9452, 0, 0x8, 0x1, ''), -- Scarlet Enchanter

UPDATE `creature_model_info` SET `bounding_radius`=0.214, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=17;
UPDATE `creature_model_info` SET `combat_reach`=3.19 WHERE `modelid`=1693;
UPDATE `creature_model_info` SET `bounding_radius`=0.035, `combat_reach`=0.15 WHERE `modelid`=4732;
UPDATE `creature_model_info` SET `gender`=0 WHERE `modelid`=6380;
UPDATE `creature_model_info` SET `combat_reach`=3.85 WHERE `modelid`=7858;
UPDATE `creature_model_info` SET `combat_reach`=3.19 WHERE `modelid`=7864;
UPDATE `creature_model_info` SET `bounding_radius`=0.21, `combat_reach`=0.9 WHERE `modelid`=7894;
UPDATE `creature_model_info` SET `gender`=0 WHERE `modelid`=10275;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5 WHERE `modelid`=10391;
UPDATE `creature_model_info` SET `bounding_radius`=0.347222 WHERE `modelid`=10434;
UPDATE `creature_model_info` SET `bounding_radius`=0.347222 WHERE `modelid`=10435;
UPDATE `creature_model_info` SET `bounding_radius`=0.347222 WHERE `modelid`=10438;
UPDATE `creature_model_info` SET `bounding_radius`=0.347222 WHERE `modelid`=10441;
UPDATE `creature_model_info` SET `bounding_radius`=0.347222 WHERE `modelid`=10442;
UPDATE `creature_model_info` SET `bounding_radius`=0.347222 WHERE `modelid`=10443;
UPDATE `creature_model_info` SET `bounding_radius`=0.347222 WHERE `modelid`=10444;
UPDATE `creature_model_info` SET `bounding_radius`=0.4166664, `combat_reach`=1.8 WHERE `modelid`=10452;
UPDATE `creature_model_info` SET `combat_reach`=3.52 WHERE `modelid`=10613;
UPDATE `creature_model_info` SET `gender`=0 WHERE `modelid`=10709;
UPDATE `creature_model_info` SET `gender`=1 WHERE `modelid`=10751;
UPDATE `creature_model_info` SET `gender`=0 WHERE `modelid`=10936;
UPDATE `creature_model_info` SET `gender`=0 WHERE `modelid`=10938;
UPDATE `creature_model_info` SET `gender`=0 WHERE `modelid`=12332;
UPDATE `creature_model_info` SET `combat_reach`=3.85 WHERE `modelid`=14701;
UPDATE `creature_model_info` SET `bounding_radius`=0.55, `combat_reach`=1.65 WHERE `modelid`=15927;
UPDATE `creature_model_info` SET `combat_reach`=4.4 WHERE `modelid`=15958;
UPDATE `creature_model_info` SET `bounding_radius`=1 WHERE `modelid`=22471;
UPDATE `creature_model_info` SET `gender`=0 WHERE `modelid`=25468;
UPDATE `creature_model_info` SET `bounding_radius`=0.3817, `combat_reach`=1.65 WHERE `modelid`=25582;
UPDATE `creature_model_info` SET `bounding_radius`=0.375, `combat_reach`=7.5, `gender`=0 WHERE `modelid`=25919;
UPDATE `creature_model_info` SET `combat_reach`=6.75, `gender`=0 WHERE `modelid`=26746;
UPDATE `creature_model_info` SET `gender`=0 WHERE `modelid`=28930;
UPDATE `creature_model_info` SET `bounding_radius`=0.31, `combat_reach`=5, `gender`=0 WHERE `modelid`=31001;
UPDATE `creature_model_info` SET `bounding_radius`=0.347222, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=31342;
UPDATE `creature_model_info` SET `bounding_radius`=0.347222, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=31343;
UPDATE `creature_model_info` SET `bounding_radius`=0.3, `combat_reach`=0.375 WHERE `modelid`=32063;
UPDATE `creature_model_info` SET `bounding_radius`=0.31, `combat_reach`=3 WHERE `modelid`=32265;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=33739;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=33741;
UPDATE `creature_model_info` SET `bounding_radius`=0.208, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=33742;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=33744;
UPDATE `creature_model_info` SET `bounding_radius`=0.397228, `combat_reach`=1.3 WHERE `modelid`=33846;
UPDATE `creature_model_info` SET `bounding_radius`=0.248, `combat_reach`=0.8 WHERE `modelid`=33864;
UPDATE `creature_model_info` SET `bounding_radius`=0.217, `combat_reach`=0.7 WHERE `modelid`=33865;
UPDATE `creature_model_info` SET `bounding_radius`=1.2 WHERE `modelid`=33998;
UPDATE `creature_model_info` SET `bounding_radius`=0.347222, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=34450;
UPDATE `creature_model_info` SET `bounding_radius`=0.8, `combat_reach`=0.8, `gender`=0 WHERE `modelid`=34499;
UPDATE `creature_model_info` SET `bounding_radius`=0.383, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=34500;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=34505;
UPDATE `creature_model_info` SET `bounding_radius`=0.208, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=34506;
UPDATE `creature_model_info` SET `bounding_radius`=1.75, `combat_reach`=2.1875 WHERE `modelid`=34508;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=34509;
UPDATE `creature_model_info` SET `bounding_radius`=0.315, `combat_reach`=1.35, `gender`=1 WHERE `modelid`=34521;
UPDATE `creature_model_info` SET `bounding_radius`=0.372, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=34522;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=34572;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=34574;
UPDATE `creature_model_info` SET `bounding_radius`=0.208, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=34575;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=34578;
UPDATE `creature_model_info` SET `bounding_radius`=0.208, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=34579;
UPDATE `creature_model_info` SET `bounding_radius`=0.9, `combat_reach`=1.5 WHERE `modelid`=34590;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=34621;
UPDATE `creature_model_info` SET `bounding_radius`=0.208, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=34622;
UPDATE `creature_model_info` SET `bounding_radius`=0.208, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=34623;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=34624;
UPDATE `creature_model_info` SET `bounding_radius`=0.612, `combat_reach`=3, `gender`=0 WHERE `modelid`=34629;
UPDATE `creature_model_info` SET `bounding_radius`=0.9747, `combat_reach`=4.05, `gender`=0 WHERE `modelid`=34642;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=34646;
UPDATE `creature_model_info` SET `bounding_radius`=1, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=34647;
UPDATE `creature_model_info` SET `bounding_radius`=0.61112, `combat_reach`=2 WHERE `modelid`=34653;
UPDATE `creature_model_info` SET `bounding_radius`=1.05, `combat_reach`=4.5 WHERE `modelid`=34691;
UPDATE `creature_model_info` SET `bounding_radius`=0.4596, `combat_reach`=1.8, `gender`=0 WHERE `modelid`=34696;
UPDATE `creature_model_info` SET `bounding_radius`=0.383, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=34697;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=34698;
UPDATE `creature_model_info` SET `bounding_radius`=1.46205, `combat_reach`=6.075, `gender`=0 WHERE `modelid`=34726;
UPDATE `creature_model_info` SET `bounding_radius`=0.5835, `combat_reach`=2.25, `gender`=0 WHERE `modelid`=34727;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=34759;
UPDATE `creature_model_info` SET `bounding_radius`=0.208, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=34760;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=34831;
UPDATE `creature_model_info` SET `bounding_radius`=0.383, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=34849;
UPDATE `creature_model_info` SET `bounding_radius`=0.383, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=34850;
UPDATE `creature_model_info` SET `bounding_radius`=0.383, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=34851;
UPDATE `creature_model_info` SET `bounding_radius`=0.383, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=34852;
UPDATE `creature_model_info` SET `bounding_radius`=0.383, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=34853;
UPDATE `creature_model_info` SET `bounding_radius`=0.383, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=34854;
UPDATE `creature_model_info` SET `bounding_radius`=0.383, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=34855;
UPDATE `creature_model_info` SET `bounding_radius`=0.383, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=34856;
UPDATE `creature_model_info` SET `bounding_radius`=0.383, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=34857;
UPDATE `creature_model_info` SET `bounding_radius`=0.383, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=34858;
UPDATE `creature_model_info` SET `bounding_radius`=0.383, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=34859;
UPDATE `creature_model_info` SET `bounding_radius`=0.383, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=34860;
UPDATE `creature_model_info` SET `bounding_radius`=0.383, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=34861;
UPDATE `creature_model_info` SET `bounding_radius`=0.383, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=34862;
UPDATE `creature_model_info` SET `bounding_radius`=0.383, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=34863;
UPDATE `creature_model_info` SET `bounding_radius`=0.383, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=34864;
UPDATE `creature_model_info` SET `bounding_radius`=0.383, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=34865;
UPDATE `creature_model_info` SET `bounding_radius`=0.383, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=34866;
UPDATE `creature_model_info` SET `bounding_radius`=0.383, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=34867;
UPDATE `creature_model_info` SET `bounding_radius`=0.383, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=34868;
UPDATE `creature_model_info` SET `bounding_radius`=0.383, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=34869;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=34919;
UPDATE `creature_model_info` SET `bounding_radius`=0.383, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=34920;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=35419;
UPDATE `creature_model_info` SET `bounding_radius`=0.208, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=35420;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=35421;
UPDATE `creature_model_info` SET `bounding_radius`=0.347, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=35445;
UPDATE `creature_model_info` SET `bounding_radius`=0.347, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=35446;
UPDATE `creature_model_info` SET `bounding_radius`=0.208, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=35447;
UPDATE `creature_model_info` SET `bounding_radius`=0.208, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=35449;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=35450;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=35451;
UPDATE `creature_model_info` SET `bounding_radius`=0.347, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=35452;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=35453;
UPDATE `creature_model_info` SET `bounding_radius`=1, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=35454;
UPDATE `creature_model_info` SET `bounding_radius`=0.208, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=35459;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=35464;
UPDATE `creature_model_info` SET `bounding_radius`=0.208, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=35465;
UPDATE `creature_model_info` SET `bounding_radius`=0.347, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=35466;
UPDATE `creature_model_info` SET `bounding_radius`=0.236, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=35467;
UPDATE `creature_model_info` SET `bounding_radius`=0.3366, `combat_reach`=1.65, `gender`=0 WHERE `modelid`=35476;
UPDATE `creature_model_info` SET `bounding_radius`=0.383, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=35477;
UPDATE `creature_model_info` SET `bounding_radius`=1, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=35478;
UPDATE `creature_model_info` SET `bounding_radius`=0.383, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=35479;
UPDATE `creature_model_info` SET `bounding_radius`=0.372, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=35516;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=35517;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=35522;
UPDATE `creature_model_info` SET `bounding_radius`=0.383, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=35524;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=35526;
UPDATE `creature_model_info` SET `bounding_radius`=0.347, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=35529;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=36238;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=36239;
UPDATE `creature_model_info` SET `bounding_radius`=0.372, `combat_reach`=1.2 WHERE `modelid`=37405;
UPDATE `creature_model_info` SET `bounding_radius`=0.341, `combat_reach`=1.1 WHERE `modelid`=37408;
UPDATE `creature_model_info` SET `bounding_radius`=0.279, `combat_reach`=0.9 WHERE `modelid`=37409;
UPDATE `creature_model_info` SET `bounding_radius`=0.383, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=37598;
UPDATE `creature_model_info` SET `bounding_radius`=43.4, `combat_reach`=70, `gender`=0 WHERE `modelid`=38423;

SET @CGUID := 192476;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+2897;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 8596, 0, 1, 1, 1859.269, -2732.793, 92.91106, 4.478782, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+1, 8596, 0, 1, 1, 1854.671, -2766.897, 89.36701, 4.940797, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+2, 45417, 0, 1, 1, 1916.45, -2651.12, 60.70313, 1.291544, 120, 0, 0), -- Fiona (Area: 0)
(@CGUID+3, 45423, 0, 1, 1, 1915.2, -2641.57, 59.71183, 6.265732, 120, 0, 0), -- Fiona's Caravan (Area: 0)
(@CGUID+4, 8596, 0, 1, 1, 1826.396, -2817.224, 81.49612, 5.564172, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+5, 8596, 0, 1, 1, 1862.029, -2844.841, 81.35942, 2.909161, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+6, 8596, 0, 1, 1, 1883.953, -2823.281, 83.43932, 3.108369, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+7, 37888, 0, 1, 1, 1939.44, -2694.39, 62.14733, 3.01942, 120, 0, 0), -- Frax Bucketdrop (Area: 0)
(@CGUID+8, 2110, 0, 1, 1, 1944.228, -2746.371, 69.71069, 3.335178, 120, 0, 0), -- Black Rat (Area: 0)
(@CGUID+9, 8596, 0, 1, 1, 2021.985, -2682.965, 86.00336, 1.222777, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+10, 8603, 0, 1, 1, 2130.299, -2803.388, 81.05362, 1.195553, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+11, 8596, 0, 1, 1, 2080.432, -2812.469, 84.47261, 1.437264, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+12, 8603, 0, 1, 1, 2107.488, -2721.426, 78.11505, 3.094706, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+13, 8596, 0, 1, 1, 2106.663, -2790.846, 78.84048, 5.595325, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+14, 8603, 0, 1, 1, 2166.707, -2740.395, 77.62781, 2.86061, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+15, 8596, 0, 1, 1, 2150, -2683.334, 74.97575, 3.277732, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+16, 8596, 0, 1, 1, 2120.875, -2663.58, 75.16274, 1.609495, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+17, 8596, 0, 1, 1, 2159.523, -2789.586, 78.11961, 2.989063, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+18, 8534, 0, 1, 1, 2152.088, -2796.739, 77.5366, 0.3522984, 120, 0, 0), -- Putrid Gargoyle (Area: 0)
(@CGUID+19, 8596, 0, 1, 1, 2209.897, -2643.802, 78.12249, 3.125853, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+20, 15475, 0, 1, 1, 2895.52, -2631.325, 90.37438, 2.677144, 120, 0, 0), -- Beetle (Area: Plaguewood)
(@CGUID+21, 15476, 0, 1, 1, 2893.173, -2636.697, 90.417, 0.202536, 120, 0, 0), -- Scorpion (Area: Plaguewood)
(@CGUID+22, 14881, 0, 1, 1, 2846.31, -2612.408, 88.06877, 3.611084, 120, 0, 0), -- Spider (Area: Plaguewood) (possible waypoints or random movement)
(@CGUID+23, 15476, 0, 1, 1, 2841.726, -2604.889, 85.4854, 3.163563, 120, 0, 0), -- Scorpion (Area: Plaguewood)
(@CGUID+24, 15476, 0, 1, 1, 2885.902, -2632.968, 86.4497, 1.082341, 120, 0, 0), -- Scorpion (Area: Plaguewood)
(@CGUID+25, 45439, 0, 1, 1, 2890.843, -2631.604, 89.08681, 0.4757012, 120, 0, 0), -- Cockroach (Area: Plaguewood)
(@CGUID+26, 45439, 0, 1, 1, 2846.001, -2604.653, 85.81065, 4.918448, 120, 0, 0), -- Cockroach (Area: Plaguewood)
(@CGUID+27, 14881, 0, 1, 1, 2844.098, -2603.888, 85.41612, 1.95049, 120, 0, 0), -- Spider (Area: Plaguewood) (possible waypoints or random movement)
(@CGUID+28, 14881, 0, 1, 1, 2840.842, -2604.609, 86.25595, 1.898027, 120, 0, 0), -- Spider (Area: Plaguewood) (possible waypoints or random movement)
(@CGUID+29, 15476, 0, 1, 1, 2856.63, -2596.656, 88.13671, 3.99144, 120, 0, 0), -- Scorpion (Area: Plaguewood)
(@CGUID+30, 14881, 0, 1, 1, 2842.573, -2597.568, 85.52622, 1.621701, 120, 0, 0), -- Spider (Area: Plaguewood) (possible waypoints or random movement)
(@CGUID+31, 15476, 0, 1, 1, 2840.649, -2600.977, 85.54514, 4.844292, 120, 0, 0), -- Scorpion (Area: Plaguewood)
(@CGUID+32, 15476, 0, 1, 1, 2840.721, -2599.601, 85.59088, 3.312636, 120, 0, 0), -- Scorpion (Area: Plaguewood)
(@CGUID+33, 15475, 0, 1, 1, 2853.85, -2597.625, 87.91212, 5.398041, 120, 0, 0), -- Beetle (Area: Plaguewood)
(@CGUID+34, 15475, 0, 1, 1, 2851.29, -2594.282, 87.50657, 1.15018, 120, 0, 0), -- Beetle (Area: Plaguewood)
(@CGUID+35, 8555, 0, 1, 1, 2931.887, -2693.33, 95.63848, 6.178465, 120, 0, 0), -- Crypt Stalker (Area: Terrordale)
(@CGUID+36, 2110, 0, 1, 1, 2927.099, -2734.398, 107.3689, 3.012551, 120, 0, 0), -- Black Rat (Area: Terrordale)
(@CGUID+37, 16117, 0, 1, 1, 2929.233, -2733.807, 107.5442, 1.448966, 120, 0, 0), -- Plagued Swine (Area: Terrordale)
(@CGUID+38, 8557, 0, 1, 1, 2907.544, -2626.45, 91.22645, 1.233162, 120, 0, 0), -- Crypt Horror (Area: Terrordale)
(@CGUID+39, 45439, 0, 1, 1, 2917.203, -2657.293, 94.07056, 0.1940622, 120, 0, 0), -- Cockroach (Area: Terrordale)
(@CGUID+40, 14881, 0, 1, 1, 2923.422, -2665.49, 95.38801, 3.965945, 120, 0, 0), -- Spider (Area: Terrordale) (possible waypoints or random movement)
(@CGUID+41, 8556, 0, 1, 1, 2910.233, -2626.245, 91.75743, 1.999268, 120, 0, 0), -- Crypt Walker (Area: Terrordale)
(@CGUID+42, 15476, 0, 1, 1, 2905.503, -2640.959, 93.37186, 4.257725, 120, 0, 0), -- Scorpion (Area: Terrordale)
(@CGUID+43, 11140, 0, 1, 1, 2929.072, -2744.688, 109.6972, 5.5676, 120, 0, 0), -- Egan (Area: Terrordale)
(@CGUID+44, 8555, 0, 1, 1, 2944.612, -2703.839, 96.39658, 2.308474, 120, 0, 0), -- Crypt Stalker (Area: Terrordale)
(@CGUID+45, 8557, 0, 1, 1, 2905.895, -2623.328, 90.50048, 0.04396625, 120, 0, 0), -- Crypt Horror (Area: Terrordale)
(@CGUID+46, 14881, 0, 1, 1, 2909.988, -2646.623, 92.31508, 4.639067, 120, 0, 0), -- Spider (Area: Terrordale) (possible waypoints or random movement)
(@CGUID+47, 45439, 0, 1, 1, 2920.994, -2657.122, 94.30467, 4.69757, 120, 0, 0), -- Cockroach (Area: Terrordale)
(@CGUID+48, 14881, 0, 1, 1, 2927.627, -2668.085, 94.79142, 5.262786, 120, 0, 0), -- Spider (Area: Terrordale) (possible waypoints or random movement)
(@CGUID+49, 15475, 0, 1, 1, 2917.299, -2651.881, 92.93249, 2.096536, 120, 0, 0), -- Beetle (Area: Terrordale)
(@CGUID+50, 15476, 0, 1, 1, 2926.658, -2661.251, 95.25803, 5.591767, 120, 0, 0), -- Scorpion (Area: Terrordale)
(@CGUID+51, 15476, 0, 1, 1, 2908.896, -2643.513, 91.79224, 3.127639, 120, 0, 0), -- Scorpion (Area: Terrordale)
(@CGUID+52, 15475, 0, 1, 1, 2927.926, -2662.437, 95.4204, 2.654854, 120, 0, 0), -- Beetle (Area: Terrordale)
(@CGUID+53, 45439, 0, 1, 1, 2935.65, -2680.723, 96.54852, 3.845592, 120, 0, 0), -- Cockroach (Area: Terrordale)
(@CGUID+54, 14881, 0, 1, 1, 2910.585, -2640.109, 92.18032, 2.802732, 120, 0, 0), -- Spider (Area: Terrordale) (possible waypoints or random movement)
(@CGUID+55, 16117, 0, 1, 1, 2947.432, -2719.308, 108.5728, 1.506853, 120, 0, 0), -- Plagued Swine (Area: Terrordale)
(@CGUID+56, 45439, 0, 1, 1, 2922.461, -2652.219, 93.61893, 3.887891, 120, 0, 0), -- Cockroach (Area: Terrordale)
(@CGUID+57, 15475, 0, 1, 1, 2933.532, -2670.53, 95.93962, 4.073407, 120, 0, 0), -- Beetle (Area: Terrordale)
(@CGUID+58, 14881, 0, 1, 1, 2934.803, -2671.489, 96.43496, 6.233092, 120, 0, 0), -- Spider (Area: Terrordale) (possible waypoints or random movement)
(@CGUID+59, 12384, 0, 1, 1, 2935.735, -2744.635, 109.6912, 3.543018, 120, 0, 0), -- Augustus the Touched (Area: Terrordale)
(@CGUID+60, 8524, 0, 1, 1, 2961.996, -2736.333, 115.5672, 3.018641, 120, 0, 0), -- Cursed Mage (Area: Terrordale)
(@CGUID+61, 45439, 0, 1, 1, 2934.23, -2667.615, 96.30615, 0.7166045, 120, 0, 0), -- Cockroach (Area: Terrordale)
(@CGUID+62, 15475, 0, 1, 1, 2905.909, -2633.897, 92.12616, 0.6653967, 120, 0, 0), -- Beetle (Area: Terrordale)
(@CGUID+63, 14881, 0, 1, 1, 2934.71, -2667.082, 96.49828, 3.826737, 120, 0, 0), -- Spider (Area: Terrordale) (possible waypoints or random movement)
(@CGUID+64, 45439, 0, 1, 1, 2911.647, -2638.079, 92.42809, 5.017703, 120, 0, 0), -- Cockroach (Area: Terrordale)
(@CGUID+65, 14881, 0, 1, 1, 2937.059, -2682.008, 96.33627, 0.3565146, 120, 0, 0), -- Spider (Area: Terrordale) (possible waypoints or random movement)
(@CGUID+66, 45439, 0, 1, 1, 2938.092, -2687.434, 95.71802, 2.432707, 120, 0, 0), -- Cockroach (Area: Terrordale)
(@CGUID+67, 15475, 0, 1, 1, 2910.542, -2631.789, 92.17151, 3.024628, 120, 0, 0), -- Beetle (Area: Terrordale)
(@CGUID+68, 16117, 0, 1, 1, 2928.829, -2756.699, 108.7046, 2.668766, 120, 0, 0), -- Plagued Swine (Area: Terrordale)
(@CGUID+69, 45439, 0, 1, 1, 2939.717, -2693.07, 95.70455, 5.610078, 120, 0, 0), -- Cockroach (Area: Terrordale)
(@CGUID+70, 15475, 0, 1, 1, 2938.969, -2702.774, 95.77433, 5.855785, 120, 0, 0), -- Beetle (Area: Terrordale)
(@CGUID+71, 15476, 0, 1, 1, 2912.975, -2628.255, 92.61997, 2.186416, 120, 0, 0), -- Scorpion (Area: Terrordale)
(@CGUID+72, 14881, 0, 1, 1, 2908.595, -2626.66, 91.48586, 5.085015, 120, 0, 0), -- Spider (Area: Terrordale)
(@CGUID+73, 15475, 0, 1, 1, 2914.624, -2628.211, 93.08089, 1.681167, 120, 0, 0), -- Beetle (Area: Terrordale)
(@CGUID+74, 14881, 0, 1, 1, 2915.649, -2626.767, 93.43165, 4.775783, 120, 0, 0), -- Spider (Area: Terrordale)
(@CGUID+75, 8556, 0, 1, 1, 2894.834, -2602.148, 89.2144, 2.382759, 120, 0, 0), -- Crypt Walker (Area: Terrordale)
(@CGUID+76, 15476, 0, 1, 1, 2903.832, -2621.13, 89.97598, 5.162415, 120, 0, 0), -- Scorpion (Area: Terrordale)
(@CGUID+77, 15476, 0, 1, 1, 2946.413, -2711.575, 96.50227, 3.237664, 120, 0, 0), -- Scorpion (Area: Terrordale)
(@CGUID+78, 15475, 0, 1, 1, 2910.355, -2620.984, 91.09615, 4.676169, 120, 0, 0), -- Beetle (Area: Terrordale)
(@CGUID+79, 15475, 0, 1, 1, 2906.916, -2618.973, 90.10965, 4.843069, 120, 0, 0), -- Beetle (Area: Terrordale)
(@CGUID+80, 15476, 0, 1, 1, 2911.324, -2619.262, 91.20528, 2.3266, 120, 0, 0), -- Scorpion (Area: Terrordale)
(@CGUID+81, 8557, 0, 1, 1, 2967.305, -2674.476, 99.50095, 5.951573, 120, 0, 0), -- Crypt Horror (Area: Terrordale)
(@CGUID+82, 15476, 0, 1, 1, 2901.588, -2612.34, 89.60045, 1.697046, 120, 0, 0), -- Scorpion (Area: Terrordale)
(@CGUID+83, 45439, 0, 1, 1, 2900.923, -2611.527, 89.53541, 6.236413, 120, 0, 0), -- Cockroach (Area: Terrordale)
(@CGUID+84, 14881, 0, 1, 1, 2906.18, -2614.108, 89.82708, 2.509548, 120, 0, 0), -- Spider (Area: Terrordale)
(@CGUID+85, 15475, 0, 1, 1, 2892.304, -2607.455, 89.17385, 4.133648, 120, 0, 0), -- Beetle (Area: Terrordale)
(@CGUID+86, 14881, 0, 1, 1, 2909.099, -2614.054, 90.19823, 5.286587, 120, 0, 0), -- Spider (Area: Terrordale)
(@CGUID+87, 45439, 0, 1, 1, 2885.409, -2600.477, 89.51884, 4.152198, 120, 0, 0), -- Cockroach (Area: Terrordale)
(@CGUID+88, 45439, 0, 1, 1, 2901.295, -2607.821, 88.85614, 5.300627, 120, 0, 0), -- Cockroach (Area: Terrordale)
(@CGUID+89, 15475, 0, 1, 1, 2956.725, -2717.608, 98.09142, 5.029818, 120, 0, 0), -- Beetle (Area: Terrordale)
(@CGUID+90, 8530, 0, 1, 1, 2969.409, -2752.924, 112.8438, 1.087185, 120, 0, 0), -- Cannibal Ghoul (Area: Terrordale)
(@CGUID+91, 45439, 0, 1, 1, 2876.068, -2596.119, 89.21126, 4.223685, 120, 0, 0), -- Cockroach (Area: Terrordale)
(@CGUID+92, 15476, 0, 1, 1, 2959.65, -2710.198, 97.90076, 5.928353, 120, 0, 0), -- Scorpion (Area: Terrordale)
(@CGUID+93, 45439, 0, 1, 1, 2861.659, -2595.468, 87.9864, 0.9090148, 120, 0, 0), -- Cockroach (Area: Terrordale)
(@CGUID+94, 15476, 0, 1, 1, 2967.508, -2687.404, 101.8856, 0.775031, 120, 0, 0), -- Scorpion (Area: Terrordale)
(@CGUID+95, 15476, 0, 1, 1, 2868.407, -2594.858, 88.40462, 5.194457, 120, 0, 0), -- Scorpion (Area: Terrordale)
(@CGUID+96, 45439, 0, 1, 1, 2862.333, -2594.862, 87.97189, 4.938016, 120, 0, 0), -- Cockroach (Area: Terrordale)
(@CGUID+97, 15475, 0, 1, 1, 2895.151, -2599.852, 89.5387, 1.01079, 120, 0, 0), -- Beetle (Area: Terrordale)
(@CGUID+98, 15476, 0, 1, 1, 2883.407, -2595.654, 89.25117, 1.348958, 120, 0, 0), -- Scorpion (Area: Terrordale)
(@CGUID+99, 15475, 0, 1, 1, 2968.343, -2688.147, 101.7047, 4.172635, 120, 0, 0), -- Beetle (Area: Terrordale)
(@CGUID+100, 15476, 0, 1, 1, 2893.845, -2598.726, 89.49307, 2.233576, 120, 0, 0), -- Scorpion (Area: Terrordale)
(@CGUID+101, 15476, 0, 1, 1, 2895.44, -2599.052, 89.67673, 5.777274, 120, 0, 0), -- Scorpion (Area: Terrordale)
(@CGUID+102, 15475, 0, 1, 1, 2968.696, -2682.06, 101.9399, 4.402735, 120, 0, 0), -- Beetle (Area: Terrordale)
(@CGUID+103, 15475, 0, 1, 1, 2868.049, -2593.323, 88.26467, 2.988285, 120, 0, 0), -- Beetle (Area: Terrordale)
(@CGUID+104, 45439, 0, 1, 1, 2968.418, -2691.367, 100.67, 1.966616, 120, 0, 0), -- Cockroach (Area: Terrordale)
(@CGUID+105, 15476, 0, 1, 1, 2869.002, -2591.76, 88.28112, 4.917395, 120, 0, 0), -- Scorpion (Area: Terrordale)
(@CGUID+106, 45439, 0, 1, 1, 2964.139, -2715.895, 99.18315, 2.602509, 120, 0, 0), -- Cockroach (Area: Terrordale)
(@CGUID+107, 14881, 0, 1, 1, 2886.787, -2592.57, 89.63586, 3.009566, 120, 0, 0), -- Spider (Area: Terrordale) (possible waypoints or random movement)
(@CGUID+108, 14881, 0, 1, 1, 2970.259, -2677.997, 100.7617, 3.806618, 120, 0, 0), -- Spider (Area: Terrordale) (possible waypoints or random movement)
(@CGUID+109, 14881, 0, 1, 1, 2965.974, -2707.56, 98.39596, 2.432252, 120, 0, 0), -- Spider (Area: Terrordale) (possible waypoints or random movement)
(@CGUID+110, 16117, 0, 1, 1, 2947.852, -2769.412, 109.9026, 0.008690958, 120, 0, 0), -- Plagued Swine (Area: Terrordale)
(@CGUID+111, 45439, 0, 1, 1, 2883.456, -2590.873, 89.46459, 4.873437, 120, 0, 0), -- Cockroach (Area: Terrordale)
(@CGUID+112, 15475, 0, 1, 1, 2877.155, -2588.844, 89.33889, 1.281481, 120, 0, 0), -- Beetle (Area: Terrordale)
(@CGUID+113, 14881, 0, 1, 1, 2975.391, -2671.366, 100.693, 2.344533, 120, 0, 0), -- Spider (Area: Terrordale) (possible waypoints or random movement)
(@CGUID+114, 14881, 0, 1, 1, 2973.897, -2709.917, 99.77274, 0.2335536, 120, 0, 0), -- Spider (Area: Terrordale) (possible waypoints or random movement)
(@CGUID+115, 15475, 0, 1, 1, 2978.755, -2683.363, 101.8785, 0.392521, 120, 0, 0), -- Beetle (Area: Terrordale)
(@CGUID+116, 14881, 0, 1, 1, 2975.715, -2711.432, 99.98774, 2.693659, 120, 0, 0), -- Spider (Area: Terrordale) (possible waypoints or random movement)
(@CGUID+117, 45439, 0, 1, 1, 2974.093, -2718.136, 99.87909, 5.528469, 120, 0, 0), -- Cockroach (Area: Terrordale)
(@CGUID+118, 15475, 0, 1, 1, 2974.915, -2718.091, 99.88373, 3.597712, 120, 0, 0), -- Beetle (Area: Terrordale)
(@CGUID+119, 8557, 0, 1, 1, 2996.384, -2694.085, 104.1139, 1.736042, 120, 0, 0), -- Crypt Horror (Area: Terrordale)
(@CGUID+120, 8557, 0, 1, 1, 2996.609, -2695.392, 104.0589, 2.170477, 120, 0, 0), -- Crypt Horror (Area: Terrordale)
(@CGUID+121, 8556, 0, 1, 1, 2981.124, -2741.818, 99.12534, 4.649519, 120, 0, 0), -- Crypt Walker (Area: Terrordale)
(@CGUID+122, 14881, 0, 1, 1, 2986.179, -2685.524, 101.7701, 5.723793, 120, 0, 0), -- Spider (Area: Terrordale) (possible waypoints or random movement)
(@CGUID+123, 14881, 0, 1, 1, 2980.77, -2722.628, 100.0102, 5.197783, 120, 0, 0), -- Spider (Area: Terrordale) (possible waypoints or random movement)
(@CGUID+124, 15476, 0, 1, 1, 2988.46, -2686.73, 102.0888, 2.894161, 120, 0, 0), -- Scorpion (Area: Terrordale)
(@CGUID+125, 15476, 0, 1, 1, 2987.055, -2709.868, 101.8029, 3.580317, 120, 0, 0), -- Scorpion (Area: Terrordale)
(@CGUID+126, 14881, 0, 1, 1, 2978.384, -2732.957, 99.53038, 0.8606961, 120, 0, 0), -- Spider (Area: Terrordale) (possible waypoints or random movement)
(@CGUID+127, 15476, 0, 1, 1, 2978.613, -2733.403, 99.48914, 2.919486, 120, 0, 0), -- Scorpion (Area: Terrordale)
(@CGUID+128, 15475, 0, 1, 1, 2991.17, -2689.784, 102.5181, 3.347241, 120, 0, 0), -- Beetle (Area: Terrordale)
(@CGUID+129, 15476, 0, 1, 1, 2991.979, -2682.575, 102.7812, 0.9948858, 120, 0, 0), -- Scorpion (Area: Terrordale)
(@CGUID+130, 15475, 0, 1, 1, 2984.083, -2726.27, 100.8494, 3.884079, 120, 0, 0), -- Beetle (Area: Terrordale)
(@CGUID+131, 15476, 0, 1, 1, 2991.67, -2705.412, 101.9034, 0.04699823, 120, 0, 0), -- Scorpion (Area: Terrordale)
(@CGUID+132, 45439, 0, 1, 1, 2979.932, -2737.203, 99.14024, 1.096751, 120, 0, 0), -- Cockroach (Area: Terrordale)
(@CGUID+133, 15476, 0, 1, 1, 2992.046, -2705.02, 101.9956, 4.144441, 120, 0, 0), -- Scorpion (Area: Terrordale)
(@CGUID+134, 14881, 0, 1, 1, 2978.502, -2743.6, 98.90063, 1.11912, 120, 0, 0), -- Spider (Area: Terrordale) (possible waypoints or random movement)
(@CGUID+135, 15476, 0, 1, 1, 2983.037, -2740.582, 99.57066, 4.451321, 120, 0, 0), -- Scorpion (Area: Terrordale)
(@CGUID+136, 14881, 0, 1, 1, 2997.362, -2700.153, 103.6479, 1.855755, 120, 0, 0), -- Spider (Area: Terrordale) (possible waypoints or random movement)
(@CGUID+137, 14881, 0, 1, 1, 2997.921, -2700.567, 103.6658, 5.315799, 120, 0, 0), -- Spider (Area: Terrordale) (possible waypoints or random movement)
(@CGUID+138, 15476, 0, 1, 1, 3013.625, -2736.948, 98.50394, 1.319348, 120, 0, 0), -- Scorpion (Area: Terrordale)
(@CGUID+139, 45439, 0, 1, 1, 3013.187, -2759.531, 99.58886, 5.070325, 120, 0, 0), -- Cockroach (Area: Terrordale)
(@CGUID+140, 14881, 0, 1, 1, 3010.823, -2741.923, 99.04565, 4.289396, 120, 0, 0), -- Spider (Area: Terrordale) (possible waypoints or random movement)
(@CGUID+141, 14881, 0, 1, 1, 3012.151, -2755.31, 99.6002, 0.4937302, 120, 0, 0), -- Spider (Area: Terrordale) (possible waypoints or random movement)
(@CGUID+142, 14881, 0, 1, 1, 3029.036, -2769.083, 99.93135, 3.835064, 120, 0, 0), -- Spider (Area: Terrordale) (possible waypoints or random movement)
(@CGUID+143, 45439, 0, 1, 1, 2993.403, -2761.434, 98.25001, 6.009757, 120, 0, 0), -- Cockroach (Area: Terrordale)
(@CGUID+144, 15476, 0, 1, 1, 3021.266, -2765.12, 99.54194, 5.369478, 120, 0, 0), -- Scorpion (Area: Terrordale)
(@CGUID+145, 14881, 0, 1, 1, 2985.725, -2760.526, 98.59032, 2.770418, 120, 0, 0), -- Spider (Area: Terrordale) (possible waypoints or random movement)
(@CGUID+146, 15475, 0, 1, 1, 3019.365, -2762.713, 99.56838, 2.175945, 120, 0, 0), -- Beetle (Area: Terrordale)
(@CGUID+147, 45439, 0, 1, 1, 2983.056, -2754.193, 99.42965, 2.000582, 120, 0, 0), -- Cockroach (Area: Terrordale)
(@CGUID+148, 14881, 0, 1, 1, 3031.486, -2771.619, 100.0594, 0.196198, 120, 0, 0), -- Spider (Area: Terrordale) (possible waypoints or random movement)
(@CGUID+149, 45439, 0, 1, 1, 3005.127, -2754.485, 99.35114, 0.8674224, 120, 0, 0), -- Cockroach (Area: Terrordale)
(@CGUID+150, 16117, 0, 1, 1, 2982.85, -2757.267, 114.4509, 0.5881786, 120, 0, 0), -- Plagued Swine (Area: Terrordale)
(@CGUID+151, 8555, 0, 1, 1, 2994.124, -2764.205, 98.57515, 1.396263, 120, 0, 0), -- Crypt Stalker (Area: Terrordale)
(@CGUID+152, 8555, 0, 1, 1, 3012.56, -2740.497, 98.78979, 4.477967, 120, 0, 0), -- Crypt Stalker (Area: Terrordale)
(@CGUID+153, 8558, 0, 1, 1, 2889.242, -2565.417, 88.38983, 3.577925, 120, 0, 0), -- Crypt Slayer (Area: 0)
(@CGUID+154, 15475, 0, 1, 1, 2883.303, -2579.03, 92.66538, 6.221459, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+155, 14881, 0, 1, 1, 2886.404, -2574.669, 90.08842, 6.128992, 120, 0, 0), -- Spider (Area: 0) (possible waypoints or random movement)
(@CGUID+156, 15475, 0, 1, 1, 2890.491, -2570.557, 89.33001, 0.8283476, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+157, 15476, 0, 1, 1, 2882.453, -2575.116, 90.35074, 0.1479831, 120, 0, 0), -- Scorpion (Area: 0)
(@CGUID+158, 15475, 0, 1, 1, 2891.118, -2565.401, 88.74368, 0.4401532, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+159, 45439, 0, 1, 1, 2889.76, -2564.965, 88.39314, 1.840489, 120, 0, 0), -- Cockroach (Area: 0)
(@CGUID+160, 15476, 0, 1, 1, 2883.764, -2572.036, 88.96932, 3.089258, 120, 0, 0), -- Scorpion (Area: 0)
(@CGUID+161, 15476, 0, 1, 1, 2877.372, -2589.781, 89.21643, 3.85269, 120, 0, 0), -- Scorpion (Area: 0)
(@CGUID+162, 15476, 0, 1, 1, 2874.956, -2588.489, 89.2452, 3.183222, 120, 0, 0), -- Scorpion (Area: 0)
(@CGUID+163, 45439, 0, 1, 1, 2883.493, -2563.91, 87.6575, 5.16957, 120, 0, 0), -- Cockroach (Area: 0)
(@CGUID+164, 15475, 0, 1, 1, 2879.098, -2559.812, 88.37167, 0.03639848, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+165, 15476, 0, 1, 1, 2869.319, -2590.598, 88.23753, 5.146451, 120, 0, 0), -- Scorpion (Area: 0)
(@CGUID+166, 14881, 0, 1, 1, 2877.547, -2559.783, 88.51438, 1.729699, 120, 0, 0), -- Spider (Area: 0) (possible waypoints or random movement)
(@CGUID+167, 15475, 0, 1, 1, 2879.474, -2556.021, 87.97834, 3.912555, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+168, 15476, 0, 1, 1, 2876.691, -2551.928, 87.66719, 2.509595, 120, 0, 0), -- Scorpion (Area: 0)
(@CGUID+169, 45439, 0, 1, 1, 2880.378, -2540.196, 89.74584, 4.965784, 120, 0, 0), -- Cockroach (Area: 0)
(@CGUID+170, 14881, 0, 1, 1, 2876.713, -2547.598, 88.15401, 2.624917, 120, 0, 0), -- Spider (Area: 0) (possible waypoints or random movement)
(@CGUID+171, 14881, 0, 1, 1, 2879.423, -2538.817, 89.44572, 5.833169, 120, 0, 0), -- Spider (Area: 0) (possible waypoints or random movement)
(@CGUID+172, 14881, 0, 1, 1, 2859.415, -2590.556, 87.98573, 4.554582, 120, 0, 0), -- Spider (Area: 0) (possible waypoints or random movement)
(@CGUID+173, 15476, 0, 1, 1, 2872.695, -2545.43, 88.03834, 4.605905, 120, 0, 0), -- Scorpion (Area: 0)
(@CGUID+174, 15475, 0, 1, 1, 2869.19, -2545.616, 87.93266, 6.248301, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+175, 8558, 0, 1, 1, 2861.747, -2534.059, 86.05991, 3.560472, 120, 0, 0), -- Crypt Slayer (Area: 0)
(@CGUID+176, 15475, 0, 1, 1, 2853.136, -2575.315, 87.71962, 1.003604, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+177, 15475, 0, 1, 1, 2854.096, -2569.907, 87.9165, 0.6863698, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+178, 15476, 0, 1, 1, 2854.752, -2564.22, 88.16819, 0.03783936, 120, 0, 0), -- Scorpion (Area: 0)
(@CGUID+179, 45439, 0, 1, 1, 2852.424, -2577.568, 87.43861, 0.729755, 120, 0, 0), -- Cockroach (Area: 0)
(@CGUID+180, 15476, 0, 1, 1, 2854.698, -2560.902, 88.34549, 3.1457, 120, 0, 0), -- Scorpion (Area: 0)
(@CGUID+181, 15475, 0, 1, 1, 2864.404, -2545.26, 87.45207, 5.435444, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+182, 45439, 0, 1, 1, 2853.317, -2562.01, 88.28879, 4.001752, 120, 0, 0), -- Cockroach (Area: 0)
(@CGUID+183, 45439, 0, 1, 1, 2853.892, -2557.577, 88.69234, 5.043891, 120, 0, 0), -- Cockroach (Area: 0)
(@CGUID+184, 14881, 0, 1, 1, 2862.108, -2546.095, 86.80012, 4.698591, 120, 0, 0), -- Spider (Area: 0) (possible waypoints or random movement)
(@CGUID+185, 15475, 0, 1, 1, 2848.276, -2575.978, 86.48666, 3.364879, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+186, 15475, 0, 1, 1, 2848.063, -2599.927, 85.62958, 5.582969, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+187, 14881, 0, 1, 1, 2848.128, -2572.649, 86.68118, 2.933253, 120, 0, 0), -- Spider (Area: 0) (possible waypoints or random movement)
(@CGUID+188, 15476, 0, 1, 1, 2863.757, -2538.953, 86.80437, 1.069871, 120, 0, 0), -- Scorpion (Area: 0)
(@CGUID+189, 45439, 0, 1, 1, 2855.027, -2551.999, 86.96389, 4.854034, 120, 0, 0), -- Cockroach (Area: 0)
(@CGUID+190, 15476, 0, 1, 1, 2846.24, -2584.303, 86.38833, 2.410542, 120, 0, 0), -- Scorpion (Area: 0)
(@CGUID+191, 15475, 0, 1, 1, 2844.206, -2590.597, 86.66999, 4.906518, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+192, 45439, 0, 1, 1, 2843.507, -2582.781, 86.18835, 1.078529, 120, 0, 0), -- Cockroach (Area: 0)
(@CGUID+193, 15476, 0, 1, 1, 2854.371, -2543.016, 85.64294, 1.793949, 120, 0, 0), -- Scorpion (Area: 0)
(@CGUID+194, 15475, 0, 1, 1, 2853.822, -2543.816, 85.61896, 1.348657, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+195, 15475, 0, 1, 1, 2851.723, -2546.659, 85.52012, 1.163422, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+196, 8555, 0, 1, 1, 2838.849, -2580.642, 85.6411, 2.474141, 120, 0, 0), -- Crypt Stalker (Area: 0)
(@CGUID+197, 8557, 0, 1, 1, 2820.907, -2545.843, 81.02042, 4.656917, 120, 0, 0), -- Crypt Horror (Area: 0)
(@CGUID+198, 15475, 0, 1, 1, 2834.579, -2528.51, 85.50656, 0.2643517, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+199, 45439, 0, 1, 1, 2848.644, -2584.008, 86.959, 2.784589, 120, 0, 0), -- Cockroach (Area: 0)
(@CGUID+200, 15475, 0, 1, 1, 2832.356, -2525.918, 84.94229, 2.278763, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+201, 14881, 0, 1, 1, 2830.246, -2526.082, 84.48277, 4.708988, 120, 0, 0), -- Spider (Area: 0) (possible waypoints or random movement)
(@CGUID+202, 15476, 0, 1, 1, 2829.467, -2521.709, 85.30634, 0.3037345, 120, 0, 0), -- Scorpion (Area: 0)
(@CGUID+203, 15475, 0, 1, 1, 2829.324, -2525.369, 84.42611, 1.404521, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+204, 15476, 0, 1, 1, 2839.473, -2581.453, 85.71736, 0.6351042, 120, 0, 0), -- Scorpion (Area: 0)
(@CGUID+205, 14881, 0, 1, 1, 2832.998, -2572.823, 84.68253, 4.898913, 120, 0, 0), -- Spider (Area: 0)
(@CGUID+206, 15476, 0, 1, 1, 2826.971, -2546.854, 82.9496, 4.906974, 120, 0, 0), -- Scorpion (Area: 0)
(@CGUID+207, 15476, 0, 1, 1, 2832.342, -2569.857, 83.96873, 2.000136, 120, 0, 0), -- Scorpion (Area: 0)
(@CGUID+208, 15476, 0, 1, 1, 2833.017, -2574.477, 84.71077, 5.092737, 120, 0, 0), -- Scorpion (Area: 0)
(@CGUID+209, 45439, 0, 1, 1, 2825.855, -2519.848, 85.02464, 0.5157647, 120, 0, 0), -- Cockroach (Area: 0)
(@CGUID+210, 45439, 0, 1, 1, 2835.032, -2579.24, 85.01162, 0.1221474, 120, 0, 0), -- Cockroach (Area: 0)
(@CGUID+211, 14881, 0, 1, 1, 2824.466, -2528.232, 83.96984, 1.195977, 120, 0, 0), -- Spider (Area: 0) (possible waypoints or random movement)
(@CGUID+212, 14881, 0, 1, 1, 2825.737, -2538.163, 82.70814, 1.797636, 120, 0, 0), -- Spider (Area: 0) (possible waypoints or random movement)
(@CGUID+213, 45439, 0, 1, 1, 2825.031, -2534.229, 83.1469, 4.767824, 120, 0, 0), -- Cockroach (Area: 0)
(@CGUID+214, 15475, 0, 1, 1, 2824.792, -2541.317, 82.30345, 0.4882229, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+215, 15476, 0, 1, 1, 2823.214, -2530.092, 83.48071, 3.906612, 120, 0, 0), -- Scorpion (Area: 0)
(@CGUID+216, 15476, 0, 1, 1, 2834.696, -2581.457, 84.96226, 1.292849, 120, 0, 0), -- Scorpion (Area: 0)
(@CGUID+217, 15476, 0, 1, 1, 2837.013, -2586.029, 85.4398, 5.686527, 120, 0, 0), -- Scorpion (Area: 0)
(@CGUID+218, 15476, 0, 1, 1, 2828.883, -2574.026, 84.33974, 5.196158, 120, 0, 0), -- Scorpion (Area: 0)
(@CGUID+219, 14881, 0, 1, 1, 2822.506, -2535.36, 82.83923, 3.925203, 120, 0, 0), -- Spider (Area: 0) (possible waypoints or random movement)
(@CGUID+220, 45439, 0, 1, 1, 2827.266, -2562.866, 82.35052, 5.362191, 120, 0, 0), -- Cockroach (Area: 0)
(@CGUID+221, 15475, 0, 1, 1, 2822.739, -2519.116, 84.18801, 2.240761, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+222, 15475, 0, 1, 1, 2820.487, -2521.933, 84.1989, 2.966128, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+223, 15475, 0, 1, 1, 2823.724, -2559.022, 82.07009, 2.2411, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+224, 15476, 0, 1, 1, 2819.903, -2522.145, 84.1635, 2.551285, 120, 0, 0), -- Scorpion (Area: 0)
(@CGUID+225, 14881, 0, 1, 1, 2825.082, -2571.706, 83.45789, 5.094579, 120, 0, 0), -- Spider (Area: 0)
(@CGUID+226, 45439, 0, 1, 1, 2823.715, -2563.305, 82.06445, 1.679703, 120, 0, 0), -- Cockroach (Area: 0)
(@CGUID+227, 15476, 0, 1, 1, 2823.476, -2562.886, 81.97662, 1.774814, 120, 0, 0), -- Scorpion (Area: 0)
(@CGUID+228, 14881, 0, 1, 1, 2823.159, -2566.068, 82.53202, 2.848811, 120, 0, 0), -- Spider (Area: 0)
(@CGUID+229, 15475, 0, 1, 1, 2823.203, -2567.663, 82.71555, 2.742057, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+230, 45439, 0, 1, 1, 2817.861, -2518.927, 83.72388, 0.8227883, 120, 0, 0), -- Cockroach (Area: 0)
(@CGUID+231, 45439, 0, 1, 1, 2820.844, -2553.716, 80.63908, 3.253515, 120, 0, 0), -- Cockroach (Area: 0)
(@CGUID+232, 15475, 0, 1, 1, 2819.253, -2512.831, 83.82337, 3.618237, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+233, 45439, 0, 1, 1, 2819.341, -2511.552, 84.02057, 2.22756, 120, 0, 0), -- Cockroach (Area: 0)
(@CGUID+234, 14881, 0, 1, 1, 2820.271, -2506.438, 84.78712, 5.882627, 120, 0, 0), -- Spider (Area: 0) (possible waypoints or random movement)
(@CGUID+235, 14881, 0, 1, 1, 2819.026, -2558.664, 81.00797, 1.431778, 120, 0, 0), -- Spider (Area: 0)
(@CGUID+236, 45439, 0, 1, 1, 2817.467, -2510.363, 84.05536, 6.065579, 120, 0, 0), -- Cockroach (Area: 0)
(@CGUID+237, 45439, 0, 1, 1, 2817.659, -2505.652, 84.44744, 5.643684, 120, 0, 0), -- Cockroach (Area: 0)
(@CGUID+238, 15475, 0, 1, 1, 2813.923, -2504.545, 84.28845, 4.878042, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+239, 8558, 0, 1, 1, 2789.167, -2521.538, 82.85779, 3.749892, 120, 0, 0), -- Crypt Slayer (Area: 0)
(@CGUID+240, 15475, 0, 1, 1, 2813.285, -2496.569, 84.77798, 2.384496, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+241, 15475, 0, 1, 1, 2807.292, -2547.634, 78.67721, 2.980958, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+242, 15475, 0, 1, 1, 2811.124, -2497.731, 84.2216, 2.011294, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+243, 14881, 0, 1, 1, 2811.244, -2495.15, 84.51894, 4.473285, 120, 0, 0), -- Spider (Area: 0) (possible waypoints or random movement)
(@CGUID+244, 14881, 0, 1, 1, 2806.905, -2497.106, 84.26923, 1.830807, 120, 0, 0), -- Spider (Area: 0) (possible waypoints or random movement)
(@CGUID+245, 14881, 0, 1, 1, 2809.313, -2492.408, 84.56821, 2.035451, 120, 0, 0), -- Spider (Area: 0) (possible waypoints or random movement)
(@CGUID+246, 45439, 0, 1, 1, 2797.796, -2507.744, 83.92953, 5.872924, 120, 0, 0), -- Cockroach (Area: 0)
(@CGUID+247, 15476, 0, 1, 1, 2806.935, -2489.384, 84.63896, 5.382695, 120, 0, 0), -- Scorpion (Area: 0)
(@CGUID+248, 14881, 0, 1, 1, 2803.426, -2494.375, 83.8978, 0.5104148, 120, 0, 0), -- Spider (Area: 0) (possible waypoints or random movement)
(@CGUID+249, 15476, 0, 1, 1, 2787.753, -2527.923, 84.34478, 6.189559, 120, 0, 0), -- Scorpion (Area: 0)
(@CGUID+250, 45439, 0, 1, 1, 2793.233, -2512.787, 83.36895, 2.957697, 120, 0, 0), -- Cockroach (Area: 0)
(@CGUID+251, 15476, 0, 1, 1, 2802.855, -2492.363, 83.72881, 6.069279, 120, 0, 0), -- Scorpion (Area: 0)
(@CGUID+252, 15476, 0, 1, 1, 2804.753, -2486.607, 85.00381, 0.8699093, 120, 0, 0), -- Scorpion (Area: 0)
(@CGUID+253, 15476, 0, 1, 1, 2792.563, -2510.366, 83.73164, 3.97813, 120, 0, 0), -- Scorpion (Area: 0)
(@CGUID+254, 14881, 0, 1, 1, 2800.979, -2494.059, 83.69936, 4.017636, 120, 0, 0), -- Spider (Area: 0) (possible waypoints or random movement)
(@CGUID+255, 15476, 0, 1, 1, 2791.151, -2509.682, 83.93496, 2.074765, 120, 0, 0), -- Scorpion (Area: 0)
(@CGUID+256, 15476, 0, 1, 1, 2786.67, -2520.017, 82.93607, 5.039415, 120, 0, 0), -- Scorpion (Area: 0)
(@CGUID+257, 45439, 0, 1, 1, 2800.57, -2486.22, 84.423, 5.988914, 120, 0, 0), -- Cockroach (Area: 0)
(@CGUID+258, 14881, 0, 1, 1, 2792.961, -2499.421, 83.61643, 5.222764, 120, 0, 0), -- Spider (Area: 0) (possible waypoints or random movement)
(@CGUID+259, 15475, 0, 1, 1, 2783.885, -2519.737, 82.93357, 3.424301, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+260, 15476, 0, 1, 1, 2783.513, -2519.625, 82.90543, 5.675576, 120, 0, 0), -- Scorpion (Area: 0)
(@CGUID+261, 45439, 0, 1, 1, 2785.51, -2503.758, 82.95535, 3.507721, 120, 0, 0), -- Cockroach (Area: 0)
(@CGUID+262, 15476, 0, 1, 1, 2790.423, -2491.425, 83.00874, 2.487821, 120, 0, 0), -- Scorpion (Area: 0)
(@CGUID+263, 14881, 0, 1, 1, 2791.677, -2488.716, 82.9183, 2.576796, 120, 0, 0), -- Spider (Area: 0) (possible waypoints or random movement)
(@CGUID+264, 15476, 0, 1, 1, 2791.512, -2487.555, 82.83212, 3.000307, 120, 0, 0), -- Scorpion (Area: 0)
(@CGUID+265, 15476, 0, 1, 1, 2785.675, -2496.215, 82.9388, 3.178073, 120, 0, 0), -- Scorpion (Area: 0)
(@CGUID+266, 14881, 0, 1, 1, 2778.263, -2516.511, 82.20736, 0.4349242, 120, 0, 0), -- Spider (Area: 0) (possible waypoints or random movement)
(@CGUID+267, 45439, 0, 1, 1, 2782.783, -2500.579, 82.59983, 2.527373, 120, 0, 0), -- Cockroach (Area: 0)
(@CGUID+268, 15476, 0, 1, 1, 2775.21, -2523.116, 82.3277, 3.485809, 120, 0, 0), -- Scorpion (Area: 0)
(@CGUID+269, 15475, 0, 1, 1, 2783.85, -2495.952, 82.74015, 3.204072, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+270, 15476, 0, 1, 1, 2776.191, -2508.693, 82.91968, 5.857152, 120, 0, 0), -- Scorpion (Area: 0)
(@CGUID+271, 14881, 0, 1, 1, 2771.635, -2518.985, 81.46505, 4.55274, 120, 0, 0), -- Spider (Area: 0) (possible waypoints or random movement)
(@CGUID+272, 14881, 0, 1, 1, 2777.288, -2500.039, 81.81778, 5.628149, 120, 0, 0), -- Spider (Area: 0) (possible waypoints or random movement)
(@CGUID+273, 15476, 0, 1, 1, 2771.317, -2518.475, 81.37778, 0.8537751, 120, 0, 0), -- Scorpion (Area: 0)
(@CGUID+274, 15476, 0, 1, 1, 2776.077, -2496.086, 81.44189, 1.731684, 120, 0, 0), -- Scorpion (Area: 0)
(@CGUID+275, 14881, 0, 1, 1, 2772.435, -2501.696, 80.64928, 5.60055, 120, 0, 0), -- Spider (Area: 0) (possible waypoints or random movement)
(@CGUID+276, 15475, 0, 1, 1, 2764.409, -2512.156, 81.11874, 5.334109, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+277, 15476, 0, 1, 1, 2770.328, -2498.706, 80.06552, 3.797734, 120, 0, 0), -- Scorpion (Area: 0)
(@CGUID+278, 15475, 0, 1, 1, 2767.216, -2504.354, 80.72237, 5.216076, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+279, 15475, 0, 1, 1, 2763.468, -2515.177, 80.04952, 4.040063, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+280, 15475, 0, 1, 1, 2763.482, -2498.845, 79.01406, 5.685001, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+281, 45439, 0, 1, 1, 2764.812, -2491.634, 78.33737, 5.966607, 120, 0, 0), -- Cockroach (Area: 0)
(@CGUID+282, 15475, 0, 1, 1, 2764.393, -2490.709, 78.09389, 0.2059678, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+283, 8557, 0, 1, 1, 2759.394, -2516.708, 78.7182, 2.338741, 120, 0, 0), -- Crypt Horror (Area: 0)
(@CGUID+284, 45439, 0, 1, 1, 2765.348, -2516.574, 80.35303, 5.031754, 120, 0, 0), -- Cockroach (Area: 0)
(@CGUID+285, 14881, 0, 1, 1, 2760.567, -2521.77, 79.16833, 5.986452, 120, 0, 0), -- Spider (Area: 0) (possible waypoints or random movement)
(@CGUID+286, 14881, 0, 1, 1, 2758.502, -2513.216, 79.16947, 1.972326, 120, 0, 0), -- Spider (Area: 0) (possible waypoints or random movement)
(@CGUID+287, 15476, 0, 1, 1, 2757.181, -2511.485, 79.09193, 2.244914, 120, 0, 0), -- Scorpion (Area: 0)
(@CGUID+288, 14881, 0, 1, 1, 2756.037, -2516.033, 77.97429, 3.017852, 120, 0, 0), -- Spider (Area: 0) (possible waypoints or random movement)
(@CGUID+289, 15475, 0, 1, 1, 2753.958, -2518.111, 77.17404, 3.344871, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+290, 45439, 0, 1, 1, 2762.479, -2498.726, 78.90514, 4.486462, 120, 0, 0), -- Cockroach (Area: 0)
(@CGUID+291, 15476, 0, 1, 1, 2760.961, -2493.621, 77.44699, 5.220977, 120, 0, 0), -- Scorpion (Area: 0)
(@CGUID+292, 14881, 0, 1, 1, 2762.257, -2491.902, 77.4708, 5.03823, 120, 0, 0), -- Spider (Area: 0) (possible waypoints or random movement)
(@CGUID+293, 14881, 0, 1, 1, 2760.068, -2484.494, 76.1846, 0.1315644, 120, 0, 0), -- Spider (Area: 0) (possible waypoints or random movement)
(@CGUID+294, 14881, 0, 1, 1, 2758.244, -2483.023, 75.87569, 4.905063, 120, 0, 0), -- Spider (Area: 0) (possible waypoints or random movement)
(@CGUID+295, 14881, 0, 1, 1, 2754.746, -2484.513, 75.56538, 1.34134, 120, 0, 0), -- Spider (Area: 0) (possible waypoints or random movement)
(@CGUID+296, 14881, 0, 1, 1, 2752.25, -2485.721, 75.61448, 3.447261, 120, 0, 0), -- Spider (Area: 0) (possible waypoints or random movement)
(@CGUID+297, 14881, 0, 1, 1, 2753.939, -2477.967, 74.73701, 2.953926, 120, 0, 0), -- Spider (Area: 0) (possible waypoints or random movement)
(@CGUID+298, 14881, 0, 1, 1, 2750.254, -2479.225, 74.78403, 2.644016, 120, 0, 0), -- Spider (Area: 0) (possible waypoints or random movement)
(@CGUID+299, 14881, 0, 1, 1, 2751.964, -2474.748, 74.32607, 0.5607729, 120, 0, 0), -- Spider (Area: 0) (possible waypoints or random movement)
(@CGUID+300, 14881, 0, 1, 1, 2748.98, -2473.919, 74.88038, 0.7464736, 120, 0, 0), -- Spider (Area: 0) (possible waypoints or random movement)
(@CGUID+301, 14881, 0, 1, 1, 2746.064, -2473.829, 75.14886, 3.561301, 120, 0, 0), -- Spider (Area: 0) (possible waypoints or random movement)
(@CGUID+302, 14881, 0, 1, 1, 2741.487, -2472.753, 74.95856, 2.541077, 120, 0, 0), -- Spider (Area: 0) (possible waypoints or random movement)
(@CGUID+303, 14881, 0, 1, 1, 2739.293, -2472.846, 74.97608, 4.751285, 120, 0, 0), -- Spider (Area: 0) (possible waypoints or random movement)
(@CGUID+304, 14881, 0, 1, 1, 2746.486, -2467.442, 74.83736, 1.660634, 120, 0, 0), -- Spider (Area: 0) (possible waypoints or random movement)
(@CGUID+305, 14881, 0, 1, 1, 2745.968, -2467.845, 74.75114, 2.771333, 120, 0, 0), -- Spider (Area: 0) (possible waypoints or random movement)
(@CGUID+306, 14881, 0, 1, 1, 2744.616, -2466.326, 74.40623, 3.917353, 120, 0, 0), -- Spider (Area: 0) (possible waypoints or random movement)
(@CGUID+307, 8557, 0, 1, 1, 2732.12, -2459.68, 70.09344, 0, 120, 0, 0), -- Crypt Horror (Area: 0)
(@CGUID+308, 14881, 0, 1, 1, 2742.662, -2462.275, 73.68254, 1.814484, 120, 0, 0), -- Spider (Area: 0) (possible waypoints or random movement)
(@CGUID+309, 14881, 0, 1, 1, 2735.952, -2466.975, 73.2262, 2.983771, 120, 0, 0), -- Spider (Area: 0) (possible waypoints or random movement)
(@CGUID+310, 14881, 0, 1, 1, 2734.282, -2465.508, 72.58481, 6.261493, 120, 0, 0), -- Spider (Area: 0) (possible waypoints or random movement)
(@CGUID+311, 14881, 0, 1, 1, 2736.979, -2463.021, 72.01352, 3.927928, 120, 0, 0), -- Spider (Area: 0)
(@CGUID+312, 14881, 0, 1, 1, 2738.021, -2461.979, 71.76352, 0.6435761, 120, 0, 0), -- Spider (Area: 0)
(@CGUID+313, 14881, 0, 1, 1, 2734.375, -2463.541, 71.88852, 4.355952, 120, 0, 0), -- Spider (Area: 0) (possible waypoints or random movement)
(@CGUID+314, 8555, 0, 1, 1, 2734.48, -2449.67, 67.12774, 1.780236, 120, 0, 0), -- Crypt Stalker (Area: 0)
(@CGUID+315, 8556, 0, 1, 1, 2728.9, -2452.32, 67.44524, 4.974188, 120, 0, 0), -- Crypt Walker (Area: 0)
(@CGUID+316, 14881, 0, 1, 1, 2731.594, -2459.728, 69.99387, 1.909572, 120, 0, 0), -- Spider (Area: 0) (possible waypoints or random movement)
(@CGUID+317, 14881, 0, 1, 1, 2737.784, -2455.77, 69.38852, 2.230581, 120, 0, 0), -- Spider (Area: 0) (possible waypoints or random movement)
(@CGUID+318, 14881, 0, 1, 1, 2737.873, -2455.563, 69.32846, 4.175922, 120, 0, 0), -- Spider (Area: 0) (possible waypoints or random movement)
(@CGUID+319, 14881, 0, 1, 1, 2735.74, -2455.655, 69.2037, 6.206923, 120, 0, 0), -- Spider (Area: 0) (possible waypoints or random movement)
(@CGUID+320, 8558, 0, 1, 1, 2730.04, -2445.84, 65.63984, 4.886922, 120, 0, 0), -- Crypt Slayer (Area: 0)
(@CGUID+321, 8603, 0, 1, 1, 2710.324, -2447.216, 65.58028, 4.503887, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+322, 45428, 0, 1, 1, 2736.42, -2454.52, 68.78104, 3.176499, 120, 0, 0), -- Gidwin Goldbraids (Area: Thondroril River)
(@CGUID+323, 53649, 0, 1, 1, -5692.49, 5359.476, -1373.791, 2.9147, 120, 0, 0), -- Thrall (Area: Thondroril River)
(@CGUID+324, 8603, 0, 1, 1, 2680.524, -2429.239, 63.83498, 2.697173, 120, 0, 0), -- Carrion Grub (Area: Thondroril River)
(@CGUID+325, 8603, 0, 1, 1, 2506.192, -2465.049, 75.37188, 3.940802, 120, 0, 0), -- Carrion Grub (Area: Thondroril River)
(@CGUID+326, 8603, 0, 1, 1, 2376.967, -2515.043, 73.58698, 1.445472, 120, 0, 0), -- Carrion Grub (Area: Thondroril River)
(@CGUID+327, 8603, 0, 1, 1, 2403.797, -2485.927, 72.96556, 3.581643, 120, 0, 0), -- Carrion Grub (Area: Thondroril River)
(@CGUID+328, 8600, 0, 1, 1, 2311.333, -2575.602, 73.70074, 1.750359, 120, 0, 0), -- Plaguebat (Area: Thondroril River)
(@CGUID+329, 8603, 0, 1, 1, 2112.594, -2881.074, 81.68525, 4.388166, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+330, 8596, 0, 1, 1, 2116.667, -2852.604, 85.90881, 2.67782, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+331, 8596, 0, 1, 1, 2175.704, -2847.002, 88.25993, 2.225241, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+332, 8596, 0, 1, 1, 2146.448, -2876.682, 90.78185, 5.921901, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+333, 8596, 0, 1, 1, 2088.206, -2945.149, 88.20274, 1.739475, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+334, 8596, 0, 1, 1, 1990.222, -2849.881, 86.73856, 5.574559, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+335, 8596, 0, 1, 1, 2116.424, -2917.074, 99.13353, 3.926991, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+336, 8596, 0, 1, 1, 2019.963, -2840.664, 77.10643, 3.096657, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+337, 8596, 0, 1, 1, 2037.537, -2914.384, 80.08231, 2.834754, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+338, 8596, 0, 1, 1, 2004.314, -2878.473, 77.46679, 2.724252, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+339, 8596, 0, 1, 1, 2084.049, -2877.443, 79.09723, 1.102888, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+340, 8596, 0, 1, 1, 1979.162, -2914.586, 79.2351, 2.893063, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+341, 20725, 0, 1, 1, 1815.561, -2855.616, 69.09245, 1.765758, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+342, 8596, 0, 1, 1, 1816.481, -2879.74, 70.90251, 5.792883, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+343, 8596, 0, 1, 1, 1881.013, -2892.327, 85.73874, 0.6621748, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+344, 8596, 0, 1, 1, 1723.496, -2856.824, 86.13324, 2.432966, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+345, 8603, 0, 1, 1, 1772.447, -2829.204, 68.94033, 2.19749, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+346, 20725, 0, 1, 1, 1785.561, -2842.693, 69.95806, 4.247838, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+347, 8596, 0, 1, 1, 1760.232, -2820.225, 68.59408, 3.145499, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+348, 8596, 0, 1, 1, 1766.247, -2872.635, 73.43534, 1.774517, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+349, 20725, 0, 1, 1, 1794.418, -2864.999, 70.33488, 5.156575, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+350, 8596, 0, 1, 1, 1768.185, -2864.688, 71.27747, 2.269785, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+351, 8596, 0, 1, 1, 1792.392, -2726.065, 86.18743, 1.85459, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+352, 8596, 0, 1, 1, 1739.518, -2765.396, 64.89925, 3.771655, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+353, 8596, 0, 1, 1, 1776.141, -2782.509, 69.16335, 4.83218, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+354, 20725, 0, 1, 1, 1745.342, -2782.947, 68.14442, 3.594581, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+355, 8596, 0, 1, 1, 1774.062, -2906.105, 72.66615, 1.037959, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+356, 8596, 0, 1, 1, 1854.434, -2917.42, 82.71717, 4.377052, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+357, 41178, 0, 1, 1, 2918.316, -3010.901, 180.7847, 0.08726646, 120, 0, 0), -- Northwatch Tower Stalker (Area: Plaguewood)
(@CGUID+358, 2110, 0, 1, 1, 2896.534, -2850.228, 102.2627, 3.784313, 120, 0, 0), -- Black Rat (Area: Terrordale)
(@CGUID+359, 8524, 0, 1, 1, 2912.116, -2889.814, 105.6145, 1.436093, 120, 0, 0), -- Cursed Mage (Area: Terrordale)
(@CGUID+360, 16117, 0, 1, 1, 2883.875, -2886.184, 97.50182, 1.908301, 120, 0, 0), -- Plagued Swine (Area: Terrordale)
(@CGUID+361, 16117, 0, 1, 1, 2913.244, -2873.512, 98.86386, 3.975852, 120, 0, 0), -- Plagued Swine (Area: Terrordale)
(@CGUID+362, 16117, 0, 1, 1, 2905.201, -2882.624, 99.35483, 5.676873, 120, 0, 0), -- Plagued Swine (Area: Terrordale)
(@CGUID+363, 8530, 0, 1, 1, 2887.861, -2868.795, 96.74099, 6.158686, 120, 0, 0), -- Cannibal Ghoul (Area: Terrordale)
(@CGUID+364, 8524, 0, 1, 1, 2904.97, -2899.221, 100.8583, 4.861664, 120, 0, 0), -- Cursed Mage (Area: Terrordale)
(@CGUID+365, 16117, 0, 1, 1, 2909.722, -2915.15, 99.90707, 3.964303, 120, 0, 0), -- Plagued Swine (Area: Terrordale)
(@CGUID+366, 16117, 0, 1, 1, 2926.711, -2913.498, 101.659, 1.240859, 120, 0, 0), -- Plagued Swine (Area: Terrordale)
(@CGUID+367, 2110, 0, 1, 1, 2917.376, -2883.671, 99.83212, 4.524469, 120, 0, 0), -- Black Rat (Area: Terrordale)
(@CGUID+368, 8524, 0, 1, 1, 2964.942, -2863.792, 100.1491, 1.40615, 120, 0, 0), -- Cursed Mage (Area: Terrordale)
(@CGUID+369, 8524, 0, 1, 1, 2959.594, -2876.812, 107.6301, 0.7245457, 120, 0, 0), -- Cursed Mage (Area: Terrordale)
(@CGUID+370, 8530, 0, 1, 1, 2961.206, -2863.854, 107.6301, 2.081124, 120, 0, 0), -- Cannibal Ghoul (Area: Terrordale)
(@CGUID+371, 16117, 0, 1, 1, 2947.192, -2885.412, 100.873, 2.380517, 120, 0, 0), -- Plagued Swine (Area: Terrordale)
(@CGUID+372, 16117, 0, 1, 1, 2943.548, -2785.944, 111.4019, 4.137817, 120, 0, 0), -- Plagued Swine (Area: Terrordale)
(@CGUID+373, 8524, 0, 1, 1, 2991.491, -2864.53, 107.6301, 4.624097, 120, 0, 0), -- Cursed Mage (Area: Terrordale)
(@CGUID+374, 8530, 0, 1, 1, 2990.994, -2866.356, 100.7577, 0.6098977, 120, 0, 0), -- Cannibal Ghoul (Area: Terrordale)
(@CGUID+375, 2110, 0, 1, 1, 2979.611, -2803.254, 110.3081, 5.152312, 120, 0, 0), -- Black Rat (Area: Terrordale)
(@CGUID+376, 2110, 0, 1, 1, 2978.453, -2801.001, 110.3344, 5.540638, 120, 0, 0), -- Black Rat (Area: Terrordale)
(@CGUID+377, 8524, 0, 1, 1, 3004.367, -2828.572, 106.174, 4.417714, 120, 0, 0), -- Cursed Mage (Area: Terrordale)
(@CGUID+378, 8523, 0, 1, 1, 2977.751, -2909.352, 103.6977, 2.555543, 120, 0, 0), -- Scourge Soldier (Area: Terrordale)
(@CGUID+379, 16117, 0, 1, 1, 2973.676, -2889.325, 101.5305, 1.487655, 120, 0, 0), -- Plagued Swine (Area: Terrordale)
(@CGUID+380, 8523, 0, 1, 1, 2999.852, -2870.986, 93.60407, 1.166075, 120, 0, 0), -- Scourge Soldier (Area: Terrordale)
(@CGUID+381, 8530, 0, 1, 1, 2939.015, -2937.179, 105.4802, 2.977487, 120, 0, 0), -- Cannibal Ghoul (Area: Terrordale)
(@CGUID+382, 16117, 0, 1, 1, 2995.015, -2851.42, 100.779, 1.346826, 120, 0, 0), -- Plagued Swine (Area: Terrordale)
(@CGUID+383, 8524, 0, 1, 1, 3016.131, -2830.687, 110.9395, 3.691566, 120, 0, 0), -- Cursed Mage (Area: Terrordale)
(@CGUID+384, 16117, 0, 1, 1, 3013.542, -2876.041, 101.9513, 6.176111, 120, 0, 0), -- Plagued Swine (Area: Terrordale)
(@CGUID+385, 16117, 0, 1, 1, 3018.75, -2818.75, 105.2772, 4.573484, 120, 0, 0), -- Plagued Swine (Area: Terrordale)
(@CGUID+386, 16117, 0, 1, 1, 3036.663, -2819.521, 105.8508, 2.289961, 120, 0, 0), -- Plagued Swine (Area: Terrordale)
(@CGUID+387, 8530, 0, 1, 1, 3048.384, -2885.66, 109.93, 4.910375, 120, 0, 0), -- Cannibal Ghoul (Area: Terrordale)
(@CGUID+388, 32520, 0, 1, 1, -6148.39, 5539.97, -1207.787, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Terrordale)
(@CGUID+389, 32520, 0, 1, 1, -5691.65, 5556.92, -1154.687, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Terrordale)
(@CGUID+390, 32520, 0, 1, 1, -6305.162, 5582.533, -1172.063, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Terrordale)
(@CGUID+391, 32520, 0, 1, 1, -6014.71, 5479.63, -1208.007, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Terrordale)
(@CGUID+392, 8530, 0, 1, 1, 3029.159, -2937.825, 109.9925, 1.711476, 120, 0, 0), -- Cannibal Ghoul (Area: Terrordale)
(@CGUID+393, 20725, 0, 1, 1, 3060.376, -2883.908, 113.35, 2.314319, 120, 0, 0), -- Bat (Area: Terrordale)
(@CGUID+394, 10780, 0, 1, 1, 3054.577, -2948.138, 114.163, 3.400308, 120, 0, 0), -- Infected Deer (Area: Terrordale)
(@CGUID+395, 8598, 0, 1, 1, 3122.287, -2938.305, 120.8712, 2.890929, 120, 0, 0), -- Frenzied Plaguehound (Area: Terrordale)
(@CGUID+396, 8605, 0, 1, 1, 3070.673, -2958.466, 117.7234, 2.620266, 120, 0, 0), -- Carrion Devourer (Area: Terrordale)
(@CGUID+397, 8605, 0, 1, 1, 3114.478, -2881.196, 117.7907, 0.1336136, 120, 0, 0), -- Carrion Devourer (Area: Terrordale)
(@CGUID+398, 10780, 0, 1, 1, 3141.621, -2824.042, 131.1724, 5.655865, 120, 0, 0), -- Infected Deer (Area: Terrordale)
(@CGUID+399, 8602, 0, 1, 1, 3090.134, -2928.318, 117.7708, 1.909222, 120, 0, 0), -- Monstrous Plaguebat (Area: Terrordale)
(@CGUID+400, 8605, 0, 1, 1, 3154.497, -2912.717, 122.1543, 1.667552, 120, 0, 0), -- Carrion Devourer (Area: Terrordale)
(@CGUID+401, 20725, 0, 1, 1, 3149.676, -2915.821, 122.4561, 4.718812, 120, 0, 0), -- Bat (Area: Terrordale)
(@CGUID+402, 8598, 0, 1, 1, 3210.91, -2924.585, 129.8135, 3.680226, 120, 0, 0), -- Frenzied Plaguehound (Area: Plaguewood)
(@CGUID+403, 8602, 0, 1, 1, 3216.848, -2979.865, 126.7633, 0.7439854, 120, 0, 0), -- Monstrous Plaguebat (Area: Plaguewood)
(@CGUID+404, 8605, 0, 1, 1, 3279.412, -2980.431, 135.8198, 6.149989, 120, 0, 0), -- Carrion Devourer (Area: Plaguewood)
(@CGUID+405, 8598, 0, 1, 1, 3241.826, -2952.561, 130.3043, 5.706564, 120, 0, 0), -- Frenzied Plaguehound (Area: Plaguewood)
(@CGUID+406, 45851, 0, 1, 1, 3274.278, -3008.517, 131.5489, 2.280648, 120, 0, 0), -- Overstuffed Golem (Area: Plaguewood)
(@CGUID+407, 8598, 0, 1, 1, 3179.267, -2953.589, 125.2695, 0.3866867, 120, 0, 0), -- Frenzied Plaguehound (Area: Plaguewood)
(@CGUID+408, 8605, 0, 1, 1, 3155.084, -2964.303, 125.1438, 4.156066, 120, 0, 0), -- Carrion Devourer (Area: Plaguewood)
(@CGUID+409, 8524, 0, 1, 1, 3053.524, -3020.025, 126.1766, 3.777282, 120, 0, 0), -- Cursed Mage (Area: Plaguewood)
(@CGUID+410, 45828, 0, 1, 1, 2954.96, -3002.88, 127.0369, 5.72468, 120, 0, 0), -- Argent Apothecary Judkins (Area: Terrordale) (possible waypoints or random movement)
(@CGUID+411, 47106, 0, 1, 1, 2948.03, -3006.68, 127.0369, 0, 120, 0, 0), -- Christine Gade (Area: Terrordale) (possible waypoints or random movement)
(@CGUID+412, 47060, 0, 1, 1, 2959.8, -3018.5, 127.0543, 5.654867, 120, 0, 0), -- Argent Sentry (Area: Terrordale)
(@CGUID+413, 47060, 0, 1, 1, 2921.05, -2991.2, 132.6632, 0.2374616, 120, 0, 0), -- Argent Sentry (Area: Terrordale) (possible waypoints or random movement)
(@CGUID+414, 44240, 0, 1, 1, 2966.6, -3027.62, 127.0533, 4.34587, 120, 0, 0), -- Argent Hippogryph (Area: Terrordale)
(@CGUID+415, 47060, 0, 1, 1, 2941.8, -3015.86, 132.7173, 5.654867, 120, 0, 0), -- Argent Sentry (Area: Terrordale)
(@CGUID+416, 44233, 0, 1, 1, 2968.76, -3031.63, 126.9093, 3.857178, 120, 0, 0), -- William Kielar Jr. (Area: Terrordale)
(@CGUID+417, 47060, 0, 1, 1, 2927.21, -3012.84, 167.728, 6.007596, 120, 0, 0), -- Argent Sentry (Area: Terrordale) (possible waypoints or random movement)
(@CGUID+418, 47105, 0, 1, 1, 2922.12, -3011.74, 132.7223, 5.72468, 120, 0, 0), -- Marc Daiton (Area: Terrordale)
(@CGUID+419, 47060, 0, 1, 1, 2937.38, -3026.34, 132.7173, 5.654867, 120, 0, 0), -- Argent Sentry (Area: Terrordale)
(@CGUID+420, 47060, 0, 1, 1, 2914.64, -3011.14, 132.7263, 5.654867, 120, 0, 0), -- Argent Sentry (Area: Terrordale)
(@CGUID+421, 8598, 0, 1, 1, 2877.932, -2984.873, 129.9161, 4.404844, 120, 0, 0), -- Frenzied Plaguehound (Area: Terrordale)
(@CGUID+422, 8605, 0, 1, 1, 2825.913, -2992.717, 99.62643, 5.821721, 120, 0, 0), -- Carrion Devourer (Area: Plaguewood)
(@CGUID+423, 10780, 0, 1, 1, 2838.685, -2969.323, 98.98117, 1.040755, 120, 0, 0), -- Infected Deer (Area: Plaguewood)
(@CGUID+424, 8602, 0, 1, 1, 2848.759, -3002.546, 107.2445, 2.647492, 120, 0, 0), -- Monstrous Plaguebat (Area: Plaguewood)
(@CGUID+425, 8602, 0, 1, 1, 2832.116, -2946.283, 98.9594, 6.13217, 120, 0, 0), -- Monstrous Plaguebat (Area: Plaguewood)
(@CGUID+426, 45886, 0, 1, 1, 2738.18, -3317.7, 95.91454, 4.468043, 120, 0, 0), -- Corpsebeast (Giant) (Area: Plaguewood)
(@CGUID+427, 8600, 0, 1, 1, 2214.307, -3025.315, 100.4475, 0.2106157, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+428, 8603, 0, 1, 1, 2080.558, -2995.383, 84.12706, 2.361719, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+429, 8596, 0, 1, 1, 2112.568, -2978.812, 92.9927, 5.732553, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+430, 8603, 0, 1, 1, 2130.766, -2975.889, 96.36086, 0.08995267, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+431, 8596, 0, 1, 1, 2147.586, -3022.418, 87.97887, 6.074684, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+432, 8596, 0, 1, 1, 1983.647, -2988.424, 75.06262, 5.432872, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+433, 8596, 0, 1, 1, 2058.957, -3030.973, 77.41467, 4.978282, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+434, 8596, 0, 1, 1, 2041.783, -2991.768, 83.42493, 4.275009, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+435, 8596, 0, 1, 1, 2030.004, -3011.387, 76.93058, 3.253113, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+436, 8596, 0, 1, 1, 1937.433, -3015.367, 78.1285, 0.392838, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+437, 8596, 0, 1, 1, 1951.775, -2936.79, 77.14967, 1.350003, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+438, 8596, 0, 1, 1, 1827.272, -2944.039, 79.04613, 1.425863, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+439, 8600, 0, 1, 1, 1722.267, -2992.97, 75.43456, 0.7942197, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+440, 8603, 0, 1, 1, 1774.929, -2982.051, 78.12246, 1.251826, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+441, 20725, 0, 1, 1, 1744.576, -2981.45, 75.98277, 4.01214, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+442, 20725, 0, 1, 1, 1741.685, -2967.294, 77.3045, 1.888391, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+443, 8596, 0, 1, 1, 1754.878, -2948.269, 75.66918, 4.945046, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+444, 8596, 0, 1, 1, 1698.697, -2922.319, 119.8579, 6.02447, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+445, 45444, 0, 1, 1, 1595.16, -2939.39, 84.23454, 5.183628, 120, 0, 0), -- Death's Step Miscreation (Area: 0)
(@CGUID+446, 45443, 0, 1, 1, 1599.36, -2940.16, 85.79083, 2.792527, 120, 0, 0), -- Death's Step Putrifier (Area: 0)
(@CGUID+447, 45444, 0, 1, 1, 1603.75, -2966.24, 83.46313, 4.328416, 120, 0, 0), -- Death's Step Miscreation (Area: 0)
(@CGUID+448, 45443, 0, 1, 1, 1592.61, -2944.26, 83.37383, 1.082104, 120, 0, 0), -- Death's Step Putrifier (Area: Death's Step)
(@CGUID+449, 45443, 0, 1, 1, 1571.02, -2971.41, 85.91753, 3.647738, 120, 0, 0), -- Death's Step Putrifier (Area: Death's Step)
(@CGUID+450, 45444, 0, 1, 1, 1557.09, -2944.79, 93.67064, 5.77704, 120, 0, 0), -- Death's Step Miscreation (Area: Death's Step)
(@CGUID+451, 45443, 0, 1, 1, 1557.09, -2949.48, 92.73953, 1.675516, 120, 0, 0), -- Death's Step Putrifier (Area: Death's Step)
(@CGUID+452, 45443, 0, 1, 1, 1560.95, -2943.37, 92.05594, 3.385939, 120, 0, 0), -- Death's Step Putrifier (Area: Death's Step)
(@CGUID+453, 45443, 0, 1, 1, 1599.07, -2967.13, 81.62674, 0.2268928, 120, 0, 0), -- Death's Step Putrifier (Area: Death's Step)
(@CGUID+454, 20725, 0, 1, 1, 1587.731, -2954.791, 85.3013, 1.260415, 120, 0, 0), -- Bat (Area: Death's Step)
(@CGUID+455, 45443, 0, 1, 1, 1605.49, -2970.72, 84.76643, 1.937315, 120, 0, 0), -- Death's Step Putrifier (Area: Death's Step)
(@CGUID+456, 45444, 0, 1, 1, 1609, -3005.43, 80.78454, 6.038839, 120, 0, 0), -- Death's Step Miscreation (Area: Death's Step) (possible waypoints or random movement)
(@CGUID+457, 45443, 0, 1, 1, 1612.64, -3003.05, 79.92284, 3.647738, 120, 0, 0), -- Death's Step Putrifier (Area: Death's Step) (possible waypoints or random movement)
(@CGUID+458, 45443, 0, 1, 1, 1526.17, -3010.03, 80.88924, 3.647738, 120, 0, 0), -- Death's Step Putrifier (Area: Death's Step)
(@CGUID+459, 45444, 0, 1, 1, 1567.5, -2974.52, 85.30634, 6.038839, 120, 0, 0), -- Death's Step Miscreation (Area: Death's Step)
(@CGUID+460, 45443, 0, 1, 1, 1568.39, -2979.07, 85.23553, 1.937315, 120, 0, 0), -- Death's Step Putrifier (Area: Death's Step)
(@CGUID+461, 45444, 0, 1, 1, 1566.36, -3010.66, 82.59614, 0.05235988, 120, 0, 0), -- Death's Step Miscreation (Area: Death's Step)
(@CGUID+462, 45443, 0, 1, 1, 1568.96, -3014.93, 82.29273, 2.234021, 120, 0, 0), -- Death's Step Putrifier (Area: Death's Step)
(@CGUID+463, 45443, 0, 1, 1, 1569.9, -3005.91, 83.20604, 3.944444, 120, 0, 0), -- Death's Step Putrifier (Area: Death's Step)
(@CGUID+464, 45444, 0, 1, 1, 1483.18, -3050.59, 73.14584, 6.038839, 120, 0, 0), -- Death's Step Miscreation (Area: Death's Step)
(@CGUID+465, 45443, 0, 1, 1, 1487.51, -3047.75, 76.56074, 3.647738, 120, 0, 0), -- Death's Step Putrifier (Area: Death's Step)
(@CGUID+466, 45444, 0, 1, 1, 1522.31, -3012.43, 80.71834, 6.038839, 120, 0, 0), -- Death's Step Miscreation (Area: Death's Step)
(@CGUID+467, 45443, 0, 1, 1, 1523.97, -3017.12, 80.31323, 1.937315, 120, 0, 0), -- Death's Step Putrifier (Area: Death's Step)
(@CGUID+468, 45443, 0, 1, 1, 1569.08, -3047.61, 79.43504, 4.642576, 120, 0, 0), -- Death's Step Putrifier (Area: Death's Step) (possible waypoints or random movement)
(@CGUID+469, 45443, 0, 1, 1, 1525.91, -3048.17, 74.47083, 4.118977, 120, 0, 0), -- Death's Step Putrifier (Area: Death's Step)
(@CGUID+470, 45444, 0, 1, 1, 1569.16, -3052.69, 78.63154, 0.7504916, 120, 0, 0), -- Death's Step Miscreation (Area: Death's Step) (possible waypoints or random movement)
(@CGUID+471, 45444, 0, 1, 1, 1523.93, -3052.31, 71.91144, 0.2268928, 120, 0, 0), -- Death's Step Miscreation (Area: Death's Step)
(@CGUID+472, 45443, 0, 1, 1, 1610.73, -3010.26, 81.25034, 1.937315, 120, 0, 0), -- Death's Step Putrifier (Area: Death's Step) (possible waypoints or random movement)
(@CGUID+473, 45443, 0, 1, 1, 1527.86, -3055.11, 72.99043, 2.408554, 120, 0, 0), -- Death's Step Putrifier (Area: Death's Step)
(@CGUID+474, 45443, 0, 1, 1, 1573.59, -3054.05, 79.44913, 2.932153, 120, 0, 0), -- Death's Step Putrifier (Area: Death's Step) (possible waypoints or random movement)
(@CGUID+475, 45444, 0, 1, 1, 1601.61, -3041.25, 78.63773, 0.1745329, 120, 0, 0), -- Death's Step Miscreation (Area: Death's Step)
(@CGUID+476, 45443, 0, 1, 1, 1604, -3038.24, 77.97664, 4.066617, 120, 0, 0), -- Death's Step Putrifier (Area: Death's Step)
(@CGUID+477, 45443, 0, 1, 1, 1603.73, -3044.79, 78.44144, 2.356194, 120, 0, 0), -- Death's Step Putrifier (Area: Death's Step)
(@CGUID+478, 20725, 0, 1, 1, 1599.487, -3028.656, 78.17519, 2.327716, 120, 0, 0), -- Bat (Area: Death's Step)
(@CGUID+479, 45443, 0, 1, 1, 1484.5, -3054.4, 74.64024, 1.937315, 120, 0, 0), -- Death's Step Putrifier (Area: Death's Step)
(@CGUID+480, 20725, 0, 1, 1, 1619.698, -3021.257, 79.49351, 1.795337, 120, 0, 0), -- Bat (Area: Death's Step)
(@CGUID+481, 45443, 0, 1, 1, 1609.96, -3069.32, 79.34894, 5.934119, 120, 0, 0), -- Death's Step Putrifier (Area: Death's Step)
(@CGUID+482, 45443, 0, 1, 1, 1617.66, -3067.54, 78.08384, 4.223697, 120, 0, 0), -- Death's Step Putrifier (Area: Death's Step)
(@CGUID+483, 45444, 0, 1, 1, 1614.57, -3070.87, 78.87404, 2.042035, 120, 0, 0), -- Death's Step Miscreation (Area: Death's Step)
(@CGUID+484, 45444, 0, 1, 1, 1640.72, -3039.27, 79.90894, 0, 120, 0, 0), -- Death's Step Miscreation (Area: Death's Step)
(@CGUID+485, 45443, 0, 1, 1, 1643.79, -3035.31, 79.88524, 3.892084, 120, 0, 0), -- Death's Step Putrifier (Area: Death's Step)
(@CGUID+486, 45443, 0, 1, 1, 1644.84, -3042.55, 79.34874, 2.111848, 120, 0, 0), -- Death's Step Putrifier (Area: Death's Step)
(@CGUID+487, 10779, 0, 1, 1, 1632.078, -3045.888, 79.61366, 5.389113, 120, 0, 0), -- Infected Squirrel (Area: Death's Step)
(@CGUID+488, 45429, 0, 1, 1, 1692.83, -3027.97, 77.44093, 3.159046, 120, 0, 0), -- Tarenar Sunstrike (Area: Death's Step)
(@CGUID+489, 20725, 0, 1, 1, 1694.443, -3027.171, 78.06559, 6.067454, 120, 0, 0), -- Bat (Area: Death's Step)
(@CGUID+490, 8596, 0, 1, 1, 1727.414, -3046.764, 75.9679, 0.3427611, 120, 0, 0), -- Plaguehound Runt (Area: Death's Step)
(@CGUID+491, 8596, 0, 1, 1, 1769.021, -3039.748, 77.98909, 1.826684, 120, 0, 0), -- Plaguehound Runt (Area: Death's Step)
(@CGUID+492, 8603, 0, 1, 1, 1905.687, -3051.583, 79.15575, 5.01096, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+493, 2110, 0, 1, 1, 2038.488, -3077.949, 73.70247, 0.7503088, 120, 0, 0), -- Black Rat (Area: 0)
(@CGUID+494, 8596, 0, 1, 1, 2109.399, -3057.649, 77.16724, 4.572304, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+495, 8596, 0, 1, 1, 2134.255, -3065.611, 78.57713, 3.043327, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+496, 8602, 0, 1, 1, 2794.675, -3066.782, 110.3658, 0.7858848, 120, 0, 0), -- Monstrous Plaguebat (Area: Plaguewood)
(@CGUID+497, 8598, 0, 1, 1, 2864.108, -3052.412, 105.9693, 2.158799, 120, 0, 0), -- Frenzied Plaguehound (Area: Plaguewood)
(@CGUID+498, 8602, 0, 1, 1, 2823.363, -3056.98, 100.6032, 1.589887, 120, 0, 0), -- Monstrous Plaguebat (Area: Plaguewood)
(@CGUID+499, 47060, 0, 1, 1, 2950.56, -3038.03, 127.0543, 5.654867, 120, 0, 0), -- Argent Sentry (Area: Plaguewood)
(@CGUID+500, 47104, 0, 1, 1, 2935.57, -3051.21, 127.0024, 4.678189, 120, 0, 0), -- Anthony Waler (Area: Plaguewood) (possible waypoints or random movement)
(@CGUID+501, 47060, 0, 1, 1, 2978.39, -3050.24, 123.9763, 5.654867, 120, 0, 0), -- Argent Sentry (Area: Plaguewood)
(@CGUID+502, 47060, 0, 1, 1, 2984.08, -3039.12, 123.5933, 5.654867, 120, 0, 0), -- Argent Sentry (Area: Plaguewood)
(@CGUID+503, 47060, 0, 1, 1, 3001.65, -3059.71, 117.5953, 5.654867, 120, 0, 0), -- Argent Sentry (Area: Plaguewood)
(@CGUID+504, 47060, 0, 1, 1, 3001.34, -3052.64, 118.123, 5.843721, 120, 0, 0), -- Argent Sentry (Area: Plaguewood) (possible waypoints or random movement)
(@CGUID+505, 47060, 0, 1, 1, 3006.46, -3047.81, 117.4783, 5.654867, 120, 0, 0), -- Argent Sentry (Area: Plaguewood)
(@CGUID+506, 45851, 0, 1, 1, 3178.866, -3047.152, 143.0588, 1.927739, 120, 0, 0), -- Overstuffed Golem (Area: Plaguewood)
(@CGUID+507, 8530, 0, 1, 1, 3115.237, -3047.428, 133.9071, 2.022079, 120, 0, 0), -- Cannibal Ghoul (Area: Plaguewood)
(@CGUID+508, 8530, 0, 1, 1, 3254.797, -3048.128, 153.3491, 3.086906, 120, 0, 0), -- Cannibal Ghoul (Area: Plaguewood)
(@CGUID+509, 8524, 0, 1, 1, 3318.01, -3053.9, 153.9363, 4.537856, 120, 0, 0), -- Cursed Mage (Area: Plaguewood)
(@CGUID+510, 8534, 0, 1, 1, 3359.62, -3054.52, 148.097, 0.3664424, 120, 0, 0), -- Putrid Gargoyle (Area: Plaguewood)
(@CGUID+511, 8530, 0, 1, 1, 3280.007, -3077.835, 162.3822, 2.862532, 120, 0, 0), -- Cannibal Ghoul (Area: Plaguewood)
(@CGUID+512, 8534, 0, 1, 1, 3303.4, -3130.56, 157.4225, 0.2778592, 120, 0, 0), -- Putrid Gargoyle (Area: Plaguewood)
(@CGUID+513, 8524, 0, 1, 1, 3346.18, -3080.24, 162.8983, 4.153883, 120, 0, 0), -- Cursed Mage (Area: Plaguewood)
(@CGUID+514, 8523, 0, 1, 1, 3181.127, -3117.355, 154.7624, 2.248282, 120, 0, 0), -- Scourge Soldier (Area: Plaguewood)
(@CGUID+515, 8553, 0, 1, 1, 3234.84, -3095.61, 161.4223, 3.281219, 120, 0, 0), -- Necromancer (Area: Plaguewood)
(@CGUID+516, 8524, 0, 1, 1, 3213.632, -3144.678, 161.0581, 5.071846, 120, 0, 0), -- Cursed Mage (Area: Plaguewood)
(@CGUID+517, 8524, 0, 1, 1, 3287.545, -3137.611, 153.4952, 0.5236847, 120, 0, 0), -- Cursed Mage (Area: Plaguewood)
(@CGUID+518, 8530, 0, 1, 1, 3144.209, -3099.69, 158.3419, 4.521885, 120, 0, 0), -- Cannibal Ghoul (Area: Plaguewood)
(@CGUID+519, 8530, 0, 1, 1, 3086.419, -3083.077, 129.6502, 0.5787913, 120, 0, 0), -- Cannibal Ghoul (Area: Plaguewood)
(@CGUID+520, 8530, 0, 1, 1, 2988.56, -3119.638, 114.4196, 1.153266, 120, 0, 0), -- Cannibal Ghoul (Area: Plaguewood)
(@CGUID+521, 8523, 0, 1, 1, 3019.143, -3145.171, 118.5785, 1.255621, 120, 0, 0), -- Scourge Soldier (Area: Plaguewood)
(@CGUID+522, 45851, 0, 1, 1, 3053.226, -3118.443, 130.4481, 5.276574, 120, 0, 0), -- Overstuffed Golem (Area: Plaguewood)
(@CGUID+523, 8605, 0, 1, 1, 2908.334, -3084.309, 113.0833, 5.845733, 120, 0, 0), -- Carrion Devourer (Area: Plaguewood Tower)
(@CGUID+524, 8535, 0, 1, 1, 2879.286, -3086.126, 105.2148, 2.505904, 120, 0, 0), -- Putrid Shrieker (Area: Plaguewood Tower)
(@CGUID+525, 45895, 0, 1, 1, 2810.92, -3378.34, 95.00513, 0, 120, 0, 0), -- Corpsebeast (Blob) (Area: Plaguewood Tower)
(@CGUID+526, 8598, 0, 1, 1, 2836.254, -3087.257, 101.9686, 0.3434403, 120, 0, 0), -- Frenzied Plaguehound (Area: Plaguewood)
(@CGUID+527, 45893, 0, 1, 1, 2714.18, -3381.9, 97.53893, 4.642576, 120, 0, 0), -- Corpsebeast (Dog) (Area: Plaguewood)
(@CGUID+528, 8600, 0, 1, 1, 2052.227, -3104.976, 77.38139, 2.550825, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+529, 8603, 0, 1, 1, 2111.687, -3110.063, 75.2229, 2.586921, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+530, 20725, 0, 1, 1, 2125.084, -3105.044, 77.66714, 3.550545, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+531, 2110, 0, 1, 1, 2087.43, -3051.383, 78.06553, 5.971623, 120, 0, 0), -- Black Rat (Area: 0)
(@CGUID+532, 20725, 0, 1, 1, 1912.811, -3076.009, 84.7059, 2.46638, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+533, 8600, 0, 1, 1, 1870.304, -3085.023, 87.78973, 3.566361, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+534, 8596, 0, 1, 1, 1736.938, -3085.684, 78.02315, 0.02538517, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+535, 8596, 0, 1, 1, 1419.491, -3140.743, 120.5644, 2.047544, 120, 0, 0), -- Plaguehound Runt (Area: Death's Step)
(@CGUID+536, 8534, 0, 1, 1, 1403.93, -3158.92, 112.1299, 0.2641899, 120, 0, 0), -- Putrid Gargoyle (Area: Death's Step)
(@CGUID+537, 8600, 0, 1, 1, 1506.198, -3177.699, 108.7127, 6.1598, 120, 0, 0), -- Plaguebat (Area: Death's Step)
(@CGUID+538, 8600, 0, 1, 1, 1546.863, -3145.689, 95.99203, 2.078688, 120, 0, 0), -- Plaguebat (Area: Death's Step)
(@CGUID+539, 8603, 0, 1, 1, 1478.468, -3157.746, 110.2067, 4.758131, 120, 0, 0), -- Carrion Grub (Area: Death's Step)
(@CGUID+540, 20725, 0, 1, 1, 1477.501, -3178.209, 115.9674, 5.33395, 120, 0, 0), -- Bat (Area: Death's Step)
(@CGUID+541, 2110, 0, 1, 1, 1592.769, -3209.433, 83.15823, 1.207831, 120, 0, 0), -- Black Rat (Area: Death's Step)
(@CGUID+542, 11290, 0, 1, 1, 1614.491, -3214.674, 84.26048, 0.3709601, 120, 0, 0), -- Mossflayer Zombie (Area: Death's Step) (possible waypoints or random movement)
(@CGUID+543, 8596, 0, 1, 1, 1620.509, -3148.915, 88.421, 2.75056, 120, 0, 0), -- Plaguehound Runt (Area: Death's Step)
(@CGUID+544, 20725, 0, 1, 1, 1615.911, -3144.366, 88.50518, 3.02283, 120, 0, 0), -- Bat (Area: Death's Step)
(@CGUID+545, 8596, 0, 1, 1, 1717.015, -3111.346, 77.6787, 2.276063, 120, 0, 0), -- Plaguehound Runt (Area: Death's Step)
(@CGUID+546, 45453, 0, 1, 1, 1876.56, -3187.19, 128.6293, 2.984513, 120, 0, 0), -- Blighthound (Area: 0)
(@CGUID+547, 8596, 0, 1, 1, 1955.881, -3150.737, 88.48542, 1.326291, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+548, 8596, 0, 1, 1, 2056.753, -3177.376, 79.121, 6.207899, 120, 0, 0), -- Plaguehound Runt (Area: The Marris Stead)
(@CGUID+549, 8603, 0, 1, 1, 2184.226, -3188.547, 104.5522, 0.6803131, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+550, 32520, 0, 1, 1, -6148.39, 5539.97, -1207.787, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: 0)
(@CGUID+551, 32520, 0, 1, 1, -6305.162, 5582.533, -1172.063, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: 0)
(@CGUID+552, 32520, 0, 1, 1, -6014.71, 5479.63, -1208.007, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: 0)
(@CGUID+553, 32520, 0, 1, 1, -5691.65, 5556.92, -1154.687, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: 0)
(@CGUID+554, 45893, 0, 1, 1, 2844.54, -3443.74, 99.95103, 2.373648, 120, 0, 0), -- Corpsebeast (Dog) (Area: Plaguewood)
(@CGUID+555, 45886, 0, 1, 1, 2759.78, -3463.52, 101.0863, 0, 120, 0, 0), -- Corpsebeast (Giant) (Area: Plaguewood)
(@CGUID+556, 8523, 0, 1, 1, 2851.105, -3174.619, 116.1623, 3.469516, 120, 0, 0), -- Scourge Soldier (Area: Plaguewood)
(@CGUID+557, 8524, 0, 1, 1, 2914.355, -3181.024, 118.312, 5.277619, 120, 0, 0), -- Cursed Mage (Area: Plaguewood)
(@CGUID+558, 8524, 0, 1, 1, 2979.2, -3179.526, 124.7772, 5.466699, 120, 0, 0), -- Cursed Mage (Area: Plaguewood)
(@CGUID+559, 8530, 0, 1, 1, 2951.45, -3158.959, 112.869, 5.695183, 120, 0, 0), -- Cannibal Ghoul (Area: Plaguewood)
(@CGUID+560, 8534, 0, 1, 1, 2969.2, -3159.64, 115.1874, 1.087371, 120, 0, 0), -- Putrid Gargoyle (Area: Plaguewood)
(@CGUID+561, 8524, 0, 1, 1, 3012.08, -3203.659, 143.1302, 1.450956, 120, 0, 0), -- Cursed Mage (Area: Plaguewood)
(@CGUID+562, 8530, 0, 1, 1, 3048.39, -3191.378, 146.1468, 5.135866, 120, 0, 0), -- Cannibal Ghoul (Area: Plaguewood)
(@CGUID+563, 8523, 0, 1, 1, 3154.277, -3162.46, 162.4357, 4.925435, 120, 0, 0), -- Scourge Soldier (Area: Plaguewood)
(@CGUID+564, 8523, 0, 1, 1, 3093.75, -3177.084, 141.6561, 6.125278, 120, 0, 0), -- Scourge Soldier (Area: Plaguewood)
(@CGUID+565, 8523, 0, 1, 1, 3183.387, -3212.183, 161.1706, 6.216747, 120, 0, 0), -- Scourge Soldier (Area: Plaguewood)
(@CGUID+566, 8524, 0, 1, 1, 3112.793, -3249.383, 145.2555, 3.039884, 120, 0, 0), -- Cursed Mage (Area: Stratholme)
(@CGUID+567, 8524, 0, 1, 1, 3152.809, -3247.031, 165.4658, 0.4570975, 120, 0, 0), -- Cursed Mage (Area: Stratholme)
(@CGUID+568, 45851, 0, 1, 1, 3179.426, -3271.359, 164.7942, 2.311595, 120, 0, 0), -- Overstuffed Golem (Area: Stratholme)
(@CGUID+569, 8547, 0, 1, 1, 3054.3, -3232.23, 148.6723, 3.246312, 120, 0, 0), -- Death Cultist (Area: Plaguewood)
(@CGUID+570, 45851, 0, 1, 1, 3022.882, -3275.006, 143.033, 3.568145, 120, 0, 0), -- Overstuffed Golem (Area: Plaguewood)
(@CGUID+571, 8523, 0, 1, 1, 2986.101, -3252.576, 132.3375, 2.710276, 120, 0, 0), -- Scourge Soldier (Area: Plaguewood)
(@CGUID+572, 8524, 0, 1, 1, 2948.372, -3220.197, 113.1174, 3.326161, 120, 0, 0), -- Cursed Mage (Area: Plaguewood)
(@CGUID+573, 8547, 0, 1, 1, 2855.31, -3232.34, 134.2693, 6.265732, 120, 0, 0), -- Death Cultist (Area: Plaguewood)
(@CGUID+574, 8523, 0, 1, 1, 2880.271, -3276.924, 125.8441, 1.350434, 120, 0, 0), -- Scourge Soldier (Area: Plaguewood)
(@CGUID+575, 8523, 0, 1, 1, 2908.972, -3249.4, 126.8689, 2.894956, 120, 0, 0), -- Scourge Soldier (Area: Plaguewood)
(@CGUID+576, 45851, 0, 1, 1, 2946.008, -3282.52, 117.2414, 2.801, 120, 0, 0), -- Overstuffed Golem (Area: Plaguewood)
(@CGUID+577, 8524, 0, 1, 1, 2778.952, -3254.35, 99.93314, 3.592875, 120, 0, 0), -- Cursed Mage (Area: Plaguewood)
(@CGUID+578, 45895, 0, 1, 1, 2746.54, -3550.71, 104.8423, 1.22173, 120, 0, 0), -- Corpsebeast (Blob) (Area: Plaguewood)
(@CGUID+579, 20725, 0, 1, 1, 2165.931, -3245.918, 114.5898, 6.03957, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+580, 8603, 0, 1, 1, 2144.148, -3284.52, 125.8883, 3.561998, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+581, 8596, 0, 1, 1, 2156.852, -3221.741, 109.1401, 2.638193, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+582, 8600, 0, 1, 1, 2137.106, -3237.76, 110.8489, 2.574189, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+583, 8534, 0, 1, 1, 2143.366, -3240.474, 112.7361, 3.940269, 120, 0, 0), -- Putrid Gargoyle (Area: 0)
(@CGUID+584, 20725, 0, 1, 1, 2079.113, -3249.191, 96.8241, 3.845591, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+585, 8603, 0, 1, 1, 2079.166, -3288.812, 103.4109, 4.712389, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+586, 20725, 0, 1, 1, 2027.223, -3258.337, 91.19348, 2.324944, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+587, 8596, 0, 1, 1, 2056.575, -3241.702, 85.09368, 2.71985, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+588, 8600, 0, 1, 1, 2010.127, -3220.746, 87.83283, 3.676486, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+589, 8600, 0, 1, 1, 1986.216, -3257.41, 97.42116, 4.954999, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+590, 8596, 0, 1, 1, 2012.554, -3286.569, 102.8278, 4.0134, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+591, 2110, 0, 1, 1, 1852.147, -3224.556, 122.2161, 6.206695, 120, 0, 0), -- Black Rat (Area: 0)
(@CGUID+592, 45453, 0, 1, 1, 1853.693, -3213.773, 124.9277, 0.1233858, 120, 0, 0), -- Blighthound (Area: 0) (possible waypoints or random movement)
(@CGUID+593, 45453, 0, 1, 1, 1848.63, -3243.257, 120.5856, 1.709243, 120, 0, 0), -- Blighthound (Area: 0) (possible waypoints or random movement)
(@CGUID+594, 2110, 0, 1, 1, 1893.344, -3234.143, 119.9191, 1.503384, 120, 0, 0), -- Black Rat (Area: 0)
(@CGUID+595, 45453, 0, 1, 1, 1887.562, -3247.001, 118.7762, 2.106187, 120, 0, 0), -- Blighthound (Area: 0) (possible waypoints or random movement)
(@CGUID+596, 10779, 0, 1, 1, 1798.05, -3296.475, 105.8259, 5.86278, 120, 0, 0), -- Infected Squirrel (Area: The Marris Stead)
(@CGUID+597, 45453, 0, 1, 1, 1846.099, -3287.512, 114.9409, 3.190187, 120, 0, 0), -- Blighthound (Area: The Marris Stead) (possible waypoints or random movement)
(@CGUID+598, 45453, 0, 1, 1, 1879.339, -3286.939, 117.7169, 2.369199, 120, 0, 0), -- Blighthound (Area: The Marris Stead) (possible waypoints or random movement)
(@CGUID+599, 10780, 0, 1, 1, 1681.316, -3287.1, 89.92692, 5.231051, 120, 0, 0), -- Infected Deer (Area: The Marris Stead)
(@CGUID+600, 11291, 0, 1, 1, 1655.317, -3217.699, 82.48074, 0.1364231, 120, 0, 0), -- Unliving Mossflayer (Area: The Marris Stead) (possible waypoints or random movement)
(@CGUID+601, 11291, 0, 1, 1, 1646.57, -3277.994, 87.52889, 2.914389, 120, 0, 0), -- Unliving Mossflayer (Area: The Marris Stead) (possible waypoints or random movement)
(@CGUID+602, 11290, 0, 1, 1, 1543.692, -3281.261, 84.87569, 3.774629, 120, 0, 0), -- Mossflayer Zombie (Area: 0) (possible waypoints or random movement)
(@CGUID+603, 2110, 0, 1, 1, 1560.856, -3273.431, 87.17647, 1.849901, 120, 0, 0), -- Black Rat (Area: 0)
(@CGUID+604, 2110, 0, 1, 1, 1534.779, -3248.411, 80.8098, 2.384114, 120, 0, 0), -- Black Rat (Area: 0)
(@CGUID+605, 11291, 0, 1, 1, 1581.098, -3285.226, 90.77428, 5.157963, 120, 0, 0), -- Unliving Mossflayer (Area: 0) (possible waypoints or random movement)
(@CGUID+606, 11291, 0, 1, 1, 1545.629, -3253.543, 82.36473, 5.277894, 120, 0, 0), -- Unliving Mossflayer (Area: 0) (possible waypoints or random movement)
(@CGUID+607, 11291, 0, 1, 1, 1590.641, -3237.058, 84.65163, 1.286001, 120, 0, 0), -- Unliving Mossflayer (Area: 0) (possible waypoints or random movement)
(@CGUID+608, 11290, 0, 1, 1, 1597.468, -3239.479, 66.82949, 1.069383, 120, 0, 0), -- Mossflayer Zombie (Area: 0)
(@CGUID+609, 11291, 0, 1, 1, 1582.464, -3262.164, 80.93899, 6.116072, 120, 0, 0), -- Unliving Mossflayer (Area: 0)
(@CGUID+610, 12250, 0, 1, 1, 1597.13, -3254.26, 66.82949, 4.977749, 120, 0, 0), -- Zaeldarr the Outcast (Area: 0)
(@CGUID+611, 11291, 0, 1, 1, 1621.178, -3311.96, 97.79419, 0.2280121, 120, 0, 0), -- Unliving Mossflayer (Area: 0) (possible waypoints or random movement)
(@CGUID+612, 12250, 0, 1, 1, 1609.435, -3248.63, 68.05301, 3.159046, 120, 0, 0), -- Zaeldarr the Outcast (Area: 0)
(@CGUID+613, 11291, 0, 1, 1, 1617.715, -3264.006, 87.46988, 5.922439, 120, 0, 0), -- Unliving Mossflayer (Area: 0) (possible waypoints or random movement)
(@CGUID+614, 8596, 0, 1, 1, 1491.156, -3215.88, 115.201, 3.787635, 120, 0, 0), -- Plaguehound Runt (Area: The Undercroft)
(@CGUID+615, 20725, 0, 1, 1, 1479.679, -3204.971, 110.823, 3.988359, 120, 0, 0), -- Bat (Area: The Undercroft)
(@CGUID+616, 8596, 0, 1, 1, 1385.457, -3191.751, 138.6934, 0.6042482, 120, 0, 0), -- Plaguehound Runt (Area: The Undercroft)
(@CGUID+617, 8603, 0, 1, 1, 1347.619, -3157.945, 137.824, 1.607889, 120, 0, 0), -- Carrion Grub (Area: The Undercroft)
(@CGUID+618, 8603, 0, 1, 1, 1589.579, -3386.659, 126.661, 1.841848, 120, 0, 0), -- Carrion Grub (Area: The Undercroft)
(@CGUID+619, 11290, 0, 1, 1, 1597.102, -3264.363, 88.14893, 5.661776, 120, 0, 0), -- Mossflayer Zombie (Area: The Undercroft) (possible waypoints or random movement)
(@CGUID+620, 20725, 0, 1, 1, 1666.021, -3394.237, 131.8398, 5.723781, 120, 0, 0), -- Bat (Area: The Undercroft)
(@CGUID+621, 20725, 0, 1, 1, 1793.702, -3352.989, 114.4118, 5.830637, 120, 0, 0), -- Bat (Area: The Undercroft)
(@CGUID+622, 45453, 0, 1, 1, 1811.869, -3324.734, 107.8598, 0.03712858, 120, 0, 0), -- Blighthound (Area: The Undercroft) (possible waypoints or random movement)
(@CGUID+623, 8596, 0, 1, 1, 1843.079, -3390.337, 114.8918, 1.683286, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+624, 8596, 0, 1, 1, 1907.654, -3382.3, 111.5952, 0.5099431, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+625, 8603, 0, 1, 1, 1935.559, -3344.829, 107.2206, 2.895552, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+626, 20725, 0, 1, 1, 1922.307, -3360.004, 110.049, 4.494466, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+627, 45453, 0, 1, 1, 1924.48, -3325.011, 108.9563, 5.621979, 120, 0, 0), -- Blighthound (Area: 0) (possible waypoints or random movement)
(@CGUID+628, 20725, 0, 1, 1, 1925.228, -3373.667, 111.4453, 2.729142, 120, 0, 0), -- Bat (Area: The Marris Stead)
(@CGUID+629, 8603, 0, 1, 1, 2006.095, -3336.7, 107.7074, 1.939995, 120, 0, 0), -- Carrion Grub (Area: The Marris Stead)
(@CGUID+630, 8600, 0, 1, 1, 2046.911, -3316.567, 107.735, 4.178834, 120, 0, 0), -- Plaguebat (Area: The Marris Stead)
(@CGUID+631, 20725, 0, 1, 1, 2125.551, -3364.514, 129.3361, 0.9670113, 120, 0, 0), -- Bat (Area: The Marris Stead)
(@CGUID+632, 8600, 0, 1, 1, 2107.061, -3361.59, 123.3924, 2.520549, 120, 0, 0), -- Plaguebat (Area: The Marris Stead)
(@CGUID+633, 8600, 0, 1, 1, 2128.259, -3316.657, 123.2066, 1.198434, 120, 0, 0), -- Plaguebat (Area: The Marris Stead)
(@CGUID+634, 20725, 0, 1, 1, 2108.125, -3315.394, 124.388, 3.258028, 120, 0, 0), -- Bat (Area: The Marris Stead)
(@CGUID+635, 20725, 0, 1, 1, 2118.641, -3331.636, 121.6544, 2.582525, 120, 0, 0), -- Bat (Area: The Marris Stead)
(@CGUID+636, 8600, 0, 1, 1, 2225.856, -3348.001, 150.485, 3.649355, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+637, 8603, 0, 1, 1, 2141.766, -3394.058, 134.4938, 4.902894, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+638, 8596, 0, 1, 1, 2180.171, -3330.84, 144.8905, 5.001415, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+639, 45475, 0, 1, 1, 2345.016, -3628.987, 202.3393, 3.974901, 120, 0, 0), -- Plague Disseminator (Area: 0) (possible waypoints or random movement)
(@CGUID+640, 45897, 0, 1, 1, 2697.39, -3368.9, 96.72913, 5.602507, 120, 0, 0), -- Plaguewood Reanimator (Area: 0)
(@CGUID+641, 45897, 0, 1, 1, 2721.58, -3313.73, 102.0673, 5.270895, 120, 0, 0), -- Plaguewood Reanimator (Area: 0)
(@CGUID+642, 45897, 0, 1, 1, 2729.29, -3340.74, 92.48393, 1.169371, 120, 0, 0), -- Plaguewood Reanimator (Area: Plaguewood)
(@CGUID+643, 45897, 0, 1, 1, 2698.88, -3392.88, 98.93194, 0.6457718, 120, 0, 0), -- Plaguewood Reanimator (Area: Plaguewood)
(@CGUID+644, 45897, 0, 1, 1, 2731.8, -3375.3, 94.18864, 3.455752, 120, 0, 0), -- Plaguewood Reanimator (Area: Plaguewood)
(@CGUID+645, 45897, 0, 1, 1, 2755.23, -3330.91, 92.71873, 2.6529, 120, 0, 0), -- Plaguewood Reanimator (Area: Plaguewood)
(@CGUID+646, 45897, 0, 1, 1, 2753.16, -3307.91, 94.60444, 3.839724, 120, 0, 0), -- Plaguewood Reanimator (Area: Plaguewood)
(@CGUID+647, 10779, 0, 1, 1, 2766.056, -3333.154, 94.12754, 5.888169, 120, 0, 0), -- Infected Squirrel (Area: Plaguewood)
(@CGUID+648, 45886, 0, 1, 1, 2826.76, -3614.84, 101.0413, 0, 120, 0, 0), -- Corpsebeast (Giant) (Area: Plaguewood)
(@CGUID+649, 45897, 0, 1, 1, 2793.86, -3373.84, 94.46364, 6.038839, 120, 0, 0), -- Plaguewood Reanimator (Area: Plaguewood)
(@CGUID+650, 45897, 0, 1, 1, 2810.66, -3358.78, 95.11333, 4.869469, 120, 0, 0), -- Plaguewood Reanimator (Area: Plaguewood)
(@CGUID+651, 45895, 0, 1, 1, 2791.53, -3680.93, 103.4823, 0.4537856, 120, 0, 0), -- Corpsebeast (Blob) (Area: Plaguewood)
(@CGUID+652, 10779, 0, 1, 1, 2810.612, -3384.264, 94.9408, 2.022822, 120, 0, 0), -- Infected Squirrel (Area: Plaguewood)
(@CGUID+653, 45897, 0, 1, 1, 2827.26, -3389.04, 96.71433, 2.443461, 120, 0, 0), -- Plaguewood Reanimator (Area: Plaguewood)
(@CGUID+654, 45897, 0, 1, 1, 2833.93, -3366.45, 96.50014, 3.665191, 120, 0, 0), -- Plaguewood Reanimator (Area: Plaguewood)
(@CGUID+655, 8523, 0, 1, 1, 2903.021, -3323.412, 121.4704, 3.954608, 120, 0, 0), -- Scourge Soldier (Area: Plaguewood)
(@CGUID+656, 8530, 0, 1, 1, 2911.986, -3384.598, 118.9868, 3.07119, 120, 0, 0), -- Cannibal Ghoul (Area: Plaguewood)
(@CGUID+657, 8524, 0, 1, 1, 3012.583, -3339.184, 140.0654, 1.491551, 120, 0, 0), -- Cursed Mage (Area: Plaguewood)
(@CGUID+658, 45851, 0, 1, 1, 2943.874, -3354.498, 113.8248, 4.166292, 120, 0, 0), -- Overstuffed Golem (Area: Plaguewood)
(@CGUID+659, 8530, 0, 1, 1, 2988.314, -3315.534, 123.2159, 1.304031, 120, 0, 0), -- Cannibal Ghoul (Area: Plaguewood)
(@CGUID+660, 8553, 0, 1, 1, 3075.49, -3368.79, 154.4423, 0, 120, 0, 0), -- Necromancer (Area: Plaguewood)
(@CGUID+661, 8553, 0, 1, 1, 3083.83, -3368.92, 154.4423, 3.228859, 120, 0, 0), -- Necromancer (Area: Plaguewood)
(@CGUID+662, 8524, 0, 1, 1, 3044.574, -3320.5, 147.8202, 4.630186, 120, 0, 0), -- Cursed Mage (Area: Plaguewood)
(@CGUID+663, 8524, 0, 1, 1, 3122.018, -3317.479, 141.2214, 5.088365, 120, 0, 0), -- Cursed Mage (Area: Plaguewood)
(@CGUID+664, 45851, 0, 1, 1, 3149.196, -3358.571, 158.7819, 2.356194, 120, 0, 0), -- Overstuffed Golem (Area: Plaguewood)
(@CGUID+665, 45867, 0, 1, 1, 3172.33, -3311.66, 165.2433, 2.268928, 120, 0, 0), -- Omasum Blighthoof (Area: Plaguewood)
(@CGUID+666, 8553, 0, 1, 1, 3183.35, -3324.72, 163.5483, 2.443461, 120, 0, 0), -- Necromancer (Area: Plaguewood)
(@CGUID+667, 8547, 0, 1, 1, 3258.43, -3373.41, 144.2743, 4.677482, 120, 0, 0), -- Death Cultist (Area: Plaguewood)
(@CGUID+668, 41178, 0, 1, 1, 1850.524, -3728.49, 211.9617, 0.08726646, 120, 0, 0), -- Northwatch Tower Stalker (Area: 0)
(@CGUID+669, 8553, 0, 1, 1, 3185.53, -3456.81, 165.5293, 4.13643, 120, 0, 0), -- Necromancer (Area: 0)
(@CGUID+670, 8524, 0, 1, 1, 3187.628, -3419.18, 164.1177, 5.499861, 120, 0, 0), -- Cursed Mage (Area: 0)
(@CGUID+671, 8553, 0, 1, 1, 3259.74, -3390.09, 143.5223, 1.710423, 120, 0, 0), -- Necromancer (Area: 0)
(@CGUID+672, 45831, 0, 1, 1, 3143.53, -3402.09, 139.8753, 0, 120, 0, 0), -- Crusader Kevin Frost (Area: Stratholme)
(@CGUID+673, 45868, 0, 1, 1, 3175.74, -3473.3, 167.4783, 4.153883, 120, 0, 0), -- Karthis Darkrune (Area: Stratholme)
(@CGUID+674, 8523, 0, 1, 1, 3086.984, -3456.574, 136.029, 3.265733, 120, 0, 0), -- Scourge Soldier (Area: Stratholme)
(@CGUID+675, 8530, 0, 1, 1, 3114.729, -3485.016, 147.4848, 5.180247, 120, 0, 0), -- Cannibal Ghoul (Area: Plaguewood)
(@CGUID+676, 8530, 0, 1, 1, 2996.037, -3389.964, 149.2977, 3.296469, 120, 0, 0), -- Cannibal Ghoul (Area: Plaguewood)
(@CGUID+677, 8523, 0, 1, 1, 2934.714, -3421.771, 133.0178, 3.134566, 120, 0, 0), -- Scourge Soldier (Area: Plaguewood)
(@CGUID+678, 45897, 0, 1, 1, 2799.14, -3393.44, 94.41614, 6.126106, 120, 0, 0), -- Plaguewood Reanimator (Area: Plaguewood)
(@CGUID+679, 45897, 0, 1, 1, 2861.45, -3441.2, 102.2053, 3.368485, 120, 0, 0), -- Plaguewood Reanimator (Area: Plaguewood)
(@CGUID+680, 45897, 0, 1, 1, 2843.29, -3426.33, 99.68764, 4.852015, 120, 0, 0), -- Plaguewood Reanimator (Area: Plaguewood)
(@CGUID+681, 45897, 0, 1, 1, 2824.05, -3437.27, 99.20624, 5.846853, 120, 0, 0), -- Plaguewood Reanimator (Area: Plaguewood)
(@CGUID+682, 10779, 0, 1, 1, 2672.378, -3398.144, 104.3185, 3.50147, 120, 0, 0), -- Infected Squirrel (Area: Plaguewood)
(@CGUID+683, 20725, 0, 1, 1, 2700.763, -3407.139, 100.8673, 5.519186, 120, 0, 0), -- Bat (Area: Plaguewood)
(@CGUID+684, 45897, 0, 1, 1, 2723.69, -3399.15, 95.94324, 1.972222, 120, 0, 0), -- Plaguewood Reanimator (Area: Plaguewood)
(@CGUID+685, 45897, 0, 1, 1, 2753.21, -3450.66, 98.82784, 5.51524, 120, 0, 0), -- Plaguewood Reanimator (Area: Plaguewood)
(@CGUID+686, 45897, 0, 1, 1, 2779.9, -3447.93, 98.44964, 4.13643, 120, 0, 0), -- Plaguewood Reanimator (Area: Plaguewood)
(@CGUID+687, 45475, 0, 1, 1, 2457.036, -3686.267, 216.4603, 3.613744, 120, 0, 0), -- Plague Disseminator (Area: Plaguewood) (possible waypoints or random movement)
(@CGUID+688, 45475, 0, 1, 1, 2535.483, -3749.849, 206.9333, 4.263677, 120, 0, 0), -- Plague Disseminator (Area: Plaguewood) (possible waypoints or random movement)
(@CGUID+689, 45475, 0, 1, 1, 2432.838, -3721.947, 210.5713, 1.521168, 120, 0, 0), -- Plague Disseminator (Area: Plaguewood) (possible waypoints or random movement)
(@CGUID+690, 8596, 0, 1, 1, 2219.222, -3410.474, 174.8843, 6.175548, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+691, 2110, 0, 1, 1, 2055.57, -3443.681, 111.693, 3.675033, 120, 0, 0), -- Black Rat (Area: 0)
(@CGUID+692, 8596, 0, 1, 1, 1955.956, -3419.998, 101.8756, 4.937823, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+693, 8596, 0, 1, 1, 1913.928, -3452.078, 108.7826, 1.930697, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+694, 8596, 0, 1, 1, 1987.741, -3453.008, 107.7117, 2.42111, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+695, 8534, 0, 1, 1, 1972.227, -3418.972, 103.1642, 1.855437, 120, 0, 0), -- Putrid Gargoyle (Area: 0)
(@CGUID+696, 8603, 0, 1, 1, 1779.783, -3396.316, 124.6316, 2.628927, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+697, 20725, 0, 1, 1, 1818.171, -3400.152, 123.719, 5.999927, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+698, 8596, 0, 1, 1, 1804.107, -3411.229, 123.7608, 6.203044, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+699, 8596, 0, 1, 1, 1841.812, -3441.978, 114.8947, 5.924072, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+700, 8596, 0, 1, 1, 1863.559, -3405.942, 115.3379, 5.615461, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+701, 20725, 0, 1, 1, 1647.682, -3412.237, 134.4106, 2.503431, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+702, 8596, 0, 1, 1, 1658.973, -3436.948, 135.5408, 4.007895, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+703, 8596, 0, 1, 1, 1627.053, -3414.694, 131.0889, 3.876515, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+704, 32520, 0, 1, 1, -6148.39, 5539.97, -1207.787, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Undercroft)
(@CGUID+705, 32520, 0, 1, 1, -6014.71, 5479.63, -1208.007, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Undercroft)
(@CGUID+706, 32520, 0, 1, 1, -6305.162, 5582.533, -1172.063, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Undercroft)
(@CGUID+707, 32520, 0, 1, 1, -5691.65, 5556.92, -1154.687, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Undercroft)
(@CGUID+708, 8603, 0, 1, 1, 1655.973, -3510.753, 128.1894, 1.416885, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+709, 8596, 0, 1, 1, 1678.549, -3490.187, 130.7166, 6.203044, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+710, 20725, 0, 1, 1, 1654.061, -3494.471, 129.5283, 5.842905, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+711, 8600, 0, 1, 1, 1813.808, -3486.301, 120.5546, 3.916574, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+712, 8603, 0, 1, 1, 1882.8, -3487.351, 112.0906, 0.9695154, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+713, 8603, 0, 1, 1, 1940.768, -3472.744, 109.1203, 1.423785, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+714, 2110, 0, 1, 1, 1893.369, -3490.033, 111.2513, 0.6042481, 120, 0, 0), -- Black Rat (Area: 0)
(@CGUID+715, 2110, 0, 1, 1, 1869.101, -3501.683, 110.8456, 3.266917, 120, 0, 0), -- Black Rat (Area: 0)
(@CGUID+716, 8534, 0, 1, 1, 1962.063, -3500.921, 113.0041, 5.764812, 120, 0, 0), -- Putrid Gargoyle (Area: 0)
(@CGUID+717, 8596, 0, 1, 1, 2016.84, -3477.604, 110.8722, 4.267088, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+718, 8596, 0, 1, 1, 2052.91, -3517.125, 120.1984, 5.646404, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+719, 2110, 0, 1, 1, 2078.665, -3516.599, 120.5404, 2.858463, 120, 0, 0), -- Black Rat (Area: 0)
(@CGUID+720, 16135, 0, 1, 1, 2175.57, -3505.86, 126.8413, 0.3665192, 120, 0, 0), -- Rayne (Area: 0)
(@CGUID+721, 8529, 0, 1, 1, 2211.837, -3490.09, 128.7622, 5.674935, 120, 0, 0), -- Scourge Champion (Area: 0)
(@CGUID+722, 8534, 0, 1, 1, 2266.218, -3520.646, 145.1806, 6.230308, 120, 0, 0), -- Putrid Gargoyle (Area: 0)
(@CGUID+723, 45475, 0, 1, 1, 2448.885, -3770.684, 201.7513, 5.909592, 120, 0, 0), -- Plague Disseminator (Area: 0) (possible waypoints or random movement)
(@CGUID+724, 45897, 0, 1, 1, 2749.77, -3471.88, 103.2163, 0.3141593, 120, 0, 0), -- Plaguewood Reanimator (Area: Plaguewood)
(@CGUID+725, 45897, 0, 1, 1, 2765.18, -3489.79, 103.6813, 1.413717, 120, 0, 0), -- Plaguewood Reanimator (Area: Plaguewood)
(@CGUID+726, 45897, 0, 1, 1, 2786.27, -3475.9, 100.7003, 2.600541, 120, 0, 0), -- Plaguewood Reanimator (Area: Plaguewood)
(@CGUID+727, 20725, 0, 1, 1, 2729.355, -3514.376, 106.1119, 0.6932674, 120, 0, 0), -- Bat (Area: Plaguewood)
(@CGUID+728, 45897, 0, 1, 1, 2852.22, -3461.64, 104.0443, 1.919862, 120, 0, 0), -- Plaguewood Reanimator (Area: Plaguewood)
(@CGUID+729, 45897, 0, 1, 1, 2827.91, -3457.7, 103.4093, 0.06981317, 120, 0, 0), -- Plaguewood Reanimator (Area: Plaguewood)
(@CGUID+730, 45851, 0, 1, 1, 2888.635, -3481.367, 117.812, 0.2426101, 120, 0, 0), -- Overstuffed Golem (Area: Plaguewood)
(@CGUID+731, 8530, 0, 1, 1, 2900.917, -3455.326, 110.2022, 3.588094, 120, 0, 0), -- Cannibal Ghoul (Area: Plaguewood)
(@CGUID+732, 45851, 0, 1, 1, 2917.285, -3512.67, 112.1326, 2.338094, 120, 0, 0), -- Overstuffed Golem (Area: Plaguewood)
(@CGUID+733, 45851, 0, 1, 1, 2991.545, -3500.725, 147.3923, 4.568422, 120, 0, 0), -- Overstuffed Golem (Area: Plaguewood)
(@CGUID+734, 41200, 0, 1, 1, 3001.03, -3457.62, 155.6353, 4.485496, 120, 0, 0), -- Generic Bunny - PRK (Area: Plaguewood)
(@CGUID+735, 45851, 0, 1, 1, 3054.702, -3493.355, 131.7022, 4.745359, 120, 0, 0), -- Overstuffed Golem (Area: Plaguewood)
(@CGUID+736, 45851, 0, 1, 1, 3146.727, -3520.677, 156.6813, 4.144687, 120, 0, 0), -- Overstuffed Golem (Area: Plaguewood)
(@CGUID+737, 8523, 0, 1, 1, 3215.004, -3487.67, 158.62, 4.777853, 120, 0, 0), -- Scourge Soldier (Area: Stratholme)
(@CGUID+738, 45851, 0, 1, 1, 3183.459, -3552.33, 152.5281, 5.470368, 120, 0, 0), -- Overstuffed Golem (Area: Stratholme)
(@CGUID+739, 8530, 0, 1, 1, 3215.408, -3585.336, 151.9061, 5.86278, 120, 0, 0), -- Cannibal Ghoul (Area: Stratholme)
(@CGUID+740, 8523, 0, 1, 1, 3147.837, -3587.635, 145.7202, 6.116432, 120, 0, 0), -- Scourge Soldier (Area: Stratholme)
(@CGUID+741, 8530, 0, 1, 1, 3116.096, -3547.211, 149.1316, 2.461361, 120, 0, 0), -- Cannibal Ghoul (Area: Stratholme)
(@CGUID+742, 45851, 0, 1, 1, 3046.667, -3553.205, 126.551, 3.828751, 120, 0, 0), -- Overstuffed Golem (Area: Plaguewood)
(@CGUID+743, 8524, 0, 1, 1, 3091.728, -3581.503, 130.3125, 3.236721, 120, 0, 0), -- Cursed Mage (Area: Plaguewood)
(@CGUID+744, 8530, 0, 1, 1, 2949.087, -3551.088, 127.5262, 6.262675, 120, 0, 0), -- Cannibal Ghoul (Area: Plaguewood)
(@CGUID+745, 45851, 0, 1, 1, 2891.966, -3546.569, 116.6393, 5.544057, 120, 0, 0), -- Overstuffed Golem (Area: Plaguewood)
(@CGUID+746, 45897, 0, 1, 1, 2757.14, -3534.97, 104.9503, 3.752458, 120, 0, 0), -- Plaguewood Reanimator (Area: Plaguewood)
(@CGUID+747, 45897, 0, 1, 1, 2733.62, -3532.9, 107.6173, 5.393067, 120, 0, 0), -- Plaguewood Reanimator (Area: Plaguewood)
(@CGUID+748, 45897, 0, 1, 1, 2765.39, -3557.69, 102.5403, 2.722714, 120, 0, 0), -- Plaguewood Reanimator (Area: Plaguewood)
(@CGUID+749, 45475, 0, 1, 1, 2488.601, -3823.659, 210.0463, 2.83404, 120, 0, 0), -- Plague Disseminator (Area: Plaguewood) (possible waypoints or random movement)
(@CGUID+750, 2110, 0, 1, 1, 2102.375, -3516.119, 120.3106, 4.363451, 120, 0, 0), -- Black Rat (Area: 0)
(@CGUID+751, 8603, 0, 1, 1, 1986.491, -3526.189, 114.3666, 1.423646, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+752, 8600, 0, 1, 1, 1923.877, -3513.396, 113.7574, 4.352018, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+753, 8534, 0, 1, 1, 1686.946, -3512.2, 127.5587, 0.9391076, 120, 0, 0), -- Putrid Gargoyle (Area: 0)
(@CGUID+754, 8600, 0, 1, 1, 1589.013, -3450.893, 134.2542, 0.7833249, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+755, 20725, 0, 1, 1, 1596.379, -3602.713, 106.727, 0.643307, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+756, 8596, 0, 1, 1, 1621.622, -3614.229, 110.6675, 1.790807, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+757, 8596, 0, 1, 1, 1679.453, -3614.074, 117.0309, 4.688618, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+758, 20725, 0, 1, 1, 1611.203, -3620.015, 108.0858, 1.015631, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+759, 8596, 0, 1, 1, 1667.366, -3558.395, 124.0421, 0.2547509, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+760, 8603, 0, 1, 1, 1655.064, -3598.13, 116.6367, 5.040313, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+761, 51986, 0, 1, 1, 1776.45, -3629.24, 122.0363, 3.385939, 120, 0, 0), -- Argent Sentry (Area: 0) (possible waypoints or random movement)
(@CGUID+762, 51986, 0, 1, 1, 1777.26, -3643.85, 120.7469, 3.246312, 120, 0, 0), -- Argent Sentry (Area: 0) (possible waypoints or random movement)
(@CGUID+763, 51986, 0, 1, 1, 1774.13, -3634.38, 121.3831, 3.001966, 120, 0, 0), -- Argent Sentry (Area: 0) (possible waypoints or random movement)
(@CGUID+764, 51986, 0, 1, 1, 1757.59, -3637.66, 120.5878, 3.254229, 120, 0, 0), -- Argent Sentry (Area: 0) (possible waypoints or random movement)
(@CGUID+765, 2110, 0, 1, 1, 1780.729, -3609.896, 124.257, 4.322787, 120, 0, 0), -- Black Rat (Area: 0)
(@CGUID+766, 35114, 0, 1, 1, 1763.69, -3626.57, 120.9363, 0, 120, 0, 0), -- ELM General Purpose Bunny (All Phases) (Area: 0)
(@CGUID+767, 2110, 0, 1, 1, 1847.833, -3572.228, 113.992, 0.2689078, 120, 0, 0), -- Black Rat (Area: 0)
(@CGUID+768, 8603, 0, 1, 1, 1894.304, -3615.493, 118.05, 5.045563, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+769, 8596, 0, 1, 1, 1948.25, -3559.398, 116.451, 4.6479, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+770, 8600, 0, 1, 1, 1926.122, -3567.624, 117.0712, 4.176158, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+771, 8596, 0, 1, 1, 1894.043, -3545.324, 112.5315, 4.13495, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+772, 20725, 0, 1, 1, 1917.326, -3564.395, 117.923, 1.456464, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+773, 8596, 0, 1, 1, 1943.746, -3622.345, 123.0949, 1.328186, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+774, 8600, 0, 1, 1, 1988.114, -3577.321, 118.1191, 0.5993719, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+775, 8596, 0, 1, 1, 2028.137, -3549.34, 115.392, 4.31352, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+776, 8600, 0, 1, 1, 2034.422, -3592.395, 128.5482, 5.428471, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+777, 8529, 0, 1, 1, 2281.744, -3558.833, 153.4667, 0.7695045, 120, 0, 0), -- Scourge Champion (Area: 0)
(@CGUID+778, 45897, 0, 1, 1, 2748.05, -3573.84, 104.1923, 1.570796, 120, 0, 0), -- Plaguewood Reanimator (Area: Plaguewood)
(@CGUID+779, 45897, 0, 1, 1, 2727.94, -3559, 106.0183, 0.4712389, 120, 0, 0), -- Plaguewood Reanimator (Area: Plaguewood)
(@CGUID+780, 45897, 0, 1, 1, 2814.78, -3602.1, 101.1043, 5.51524, 120, 0, 0), -- Plaguewood Reanimator (Area: Plaguewood)
(@CGUID+781, 45897, 0, 1, 1, 2841.46, -3599.37, 102.3103, 4.13643, 120, 0, 0), -- Plaguewood Reanimator (Area: Plaguewood)
(@CGUID+782, 8523, 0, 1, 1, 2882.733, -3604.872, 112.0332, 1.680359, 120, 0, 0), -- Scourge Soldier (Area: Plaguewood)
(@CGUID+783, 8534, 0, 1, 1, 2917.97, -3548.21, 115.1129, 2.313366, 120, 0, 0), -- Putrid Gargoyle (Area: Plaguewood)
(@CGUID+784, 8523, 0, 1, 1, 2938.354, -3588.994, 121.1988, 4.588034, 120, 0, 0), -- Scourge Soldier (Area: Plaguewood)
(@CGUID+785, 8523, 0, 1, 1, 3008.395, -3577.19, 131.3791, 2.927159, 120, 0, 0), -- Scourge Soldier (Area: Plaguewood)
(@CGUID+786, 45851, 0, 1, 1, 3310.935, -3631.459, 150.0727, 3.735005, 120, 0, 0), -- Overstuffed Golem (Area: Stratholme)
(@CGUID+787, 45851, 0, 1, 1, 3280.246, -3624.86, 150.0727, 5.288348, 120, 0, 0), -- Overstuffed Golem (Area: Stratholme)
(@CGUID+788, 45851, 0, 1, 1, 3270.812, -3639.003, 150.0727, 5.969026, 120, 0, 0), -- Overstuffed Golem (Area: Stratholme)
(@CGUID+789, 45851, 0, 1, 1, 3314.21, -3648.013, 150.0727, 3.054326, 120, 0, 0), -- Overstuffed Golem (Area: Stratholme)
(@CGUID+790, 8524, 0, 1, 1, 3244.189, -3635.797, 153.8243, 0.449487, 120, 0, 0), -- Cursed Mage (Area: Stratholme)
(@CGUID+791, 8523, 0, 1, 1, 3122.974, -3621.527, 136.7307, 5.240745, 120, 0, 0), -- Scourge Soldier (Area: Stratholme)
(@CGUID+792, 8523, 0, 1, 1, 3152.533, -3635.585, 138.8779, 1.676491, 120, 0, 0), -- Scourge Soldier (Area: Stratholme)
(@CGUID+793, 8523, 0, 1, 1, 3188.144, -3619.769, 164.4545, 5.366302, 120, 0, 0), -- Scourge Soldier (Area: Stratholme)
(@CGUID+794, 8534, 0, 1, 1, 3121.73, -3602.18, 132.0043, 2.04916, 120, 0, 0), -- Putrid Gargoyle (Area: Stratholme)
(@CGUID+795, 8524, 0, 1, 1, 3220.847, -3655.927, 143.0222, 5.709626, 120, 0, 0), -- Cursed Mage (Area: Stratholme)
(@CGUID+796, 45851, 0, 1, 1, 3036.529, -3612.696, 124.2306, 5.547671, 120, 0, 0), -- Overstuffed Golem (Area: Plaguewood)
(@CGUID+797, 45851, 0, 1, 1, 2944.595, -3615.967, 133.338, 2.478561, 120, 0, 0), -- Overstuffed Golem (Area: Plaguewood)
(@CGUID+798, 45851, 0, 1, 1, 2990.885, -3621.448, 142.8425, 1.936427, 120, 0, 0), -- Overstuffed Golem (Area: Plaguewood)
(@CGUID+799, 45851, 0, 1, 1, 2912.32, -3650.68, 116.697, 4.060142, 120, 0, 0), -- Overstuffed Golem (Area: Plaguewood)
(@CGUID+800, 45897, 0, 1, 1, 2847.83, -3627.34, 106.8943, 2.600541, 120, 0, 0), -- Plaguewood Reanimator (Area: Plaguewood)
(@CGUID+801, 45897, 0, 1, 1, 2787.19, -3661.25, 104.8653, 4.869469, 120, 0, 0), -- Plaguewood Reanimator (Area: Plaguewood)
(@CGUID+802, 45897, 0, 1, 1, 2826.74, -3641.23, 103.0483, 1.413717, 120, 0, 0), -- Plaguewood Reanimator (Area: Plaguewood)
(@CGUID+803, 45897, 0, 1, 1, 2811.34, -3623.32, 101.8873, 0.3141593, 120, 0, 0), -- Plaguewood Reanimator (Area: Plaguewood)
(@CGUID+804, 45485, 0, 1, 1, 2518.88, -3633.54, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+805, 45485, 0, 1, 1, 2519.64, -3634.73, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+806, 45485, 0, 1, 1, 2520.22, -3636.5, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+807, 45485, 0, 1, 1, 2517.39, -3633.58, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+808, 45485, 0, 1, 1, 2518.1, -3634.85, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+809, 8550, 0, 1, 1, 2509.665, -3645.446, 186.6925, 4.468043, 120, 0, 0), -- Shadowmage (Area: Plaguewood)
(@CGUID+810, 45485, 0, 1, 1, 2516.25, -3632.88, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+811, 45485, 0, 1, 1, 2518.73, -3636.17, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+812, 45485, 0, 1, 1, 2519.83, -3638.18, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+813, 45485, 0, 1, 1, 2518.3, -3637.5, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+814, 45485, 0, 1, 1, 2514.73, -3632.93, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+815, 45485, 0, 1, 1, 2519.96, -3639.73, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+816, 45485, 0, 1, 1, 2517.28, -3636.51, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+817, 45485, 0, 1, 1, 2515.38, -3634.25, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+818, 45485, 0, 1, 1, 2516, -3635.33, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+819, 45485, 0, 1, 1, 2513.47, -3632.33, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+820, 45485, 0, 1, 1, 2518.7, -3639.07, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+821, 45485, 0, 1, 1, 2519.75, -3641.08, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+822, 45485, 0, 1, 1, 2517.09, -3638, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+823, 45485, 0, 1, 1, 2520.6, -3642.27, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+824, 45485, 0, 1, 1, 2515.91, -3636.85, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+825, 45485, 0, 1, 1, 2513, -3633.52, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+826, 45485, 0, 1, 1, 2512.19, -3632.49, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+827, 45485, 0, 1, 1, 2514.47, -3635.74, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+828, 45485, 0, 1, 1, 2517.82, -3640.03, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+829, 45485, 0, 1, 1, 2513.63, -3634.79, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+830, 45485, 0, 1, 1, 2511.05, -3631.43, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+831, 45485, 0, 1, 1, 2520.78, -3643.98, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+832, 45485, 0, 1, 1, 2509.97, -3630.8, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+833, 45485, 0, 1, 1, 2514.16, -3637.37, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+834, 45485, 0, 1, 1, 2512.17, -3634.91, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+835, 45485, 0, 1, 1, 2511.06, -3633.51, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+836, 45485, 0, 1, 1, 2510.07, -3632.53, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+837, 45485, 0, 1, 1, 2512.55, -3636.16, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+838, 45485, 0, 1, 1, 2519.97, -3645.44, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+839, 45485, 0, 1, 1, 2508.21, -3630.51, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+840, 45485, 0, 1, 1, 2508.97, -3631.74, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+841, 45485, 0, 1, 1, 2512.82, -3637.85, 183.7843, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+842, 45485, 0, 1, 1, 2510.57, -3634.75, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+843, 45485, 0, 1, 1, 2509.63, -3633.92, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+844, 45485, 0, 1, 1, 2512.96, -3638.85, 183.9673, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+845, 45485, 0, 1, 1, 2510.89, -3636, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+846, 45485, 0, 1, 1, 2508.68, -3632.95, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+847, 45485, 0, 1, 1, 2519.08, -3646.47, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+848, 45485, 0, 1, 1, 2511.32, -3637.45, 183.7963, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+849, 45485, 0, 1, 1, 2507.15, -3631.76, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+850, 45485, 0, 1, 1, 2512.25, -3640.39, 184.6343, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+851, 45485, 0, 1, 1, 2511.72, -3639.31, 184.2403, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+852, 45485, 0, 1, 1, 2509.14, -3635.29, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+853, 45485, 0, 1, 1, 2508.07, -3634.37, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+854, 45485, 0, 1, 1, 2510.66, -3638.36, 184.0183, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+855, 45485, 0, 1, 1, 2519.15, -3648, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+856, 45485, 0, 1, 1, 2511.66, -3641.69, 185.2813, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+857, 45485, 0, 1, 1, 2506.89, -3633.29, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+858, 45485, 0, 1, 1, 2510.94, -3640.25, 184.7523, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+859, 45485, 0, 1, 1, 2505.97, -3632.61, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+860, 45485, 0, 1, 1, 2511.74, -3643.95, 186.3723, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+861, 45485, 0, 1, 1, 2510.53, -3641.12, 185.1843, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+862, 45485, 0, 1, 1, 2506.97, -3634.93, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+863, 45485, 0, 1, 1, 2510.26, -3642.24, 185.7243, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+864, 45485, 0, 1, 1, 2510.52, -3643.45, 186.3093, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+865, 45485, 0, 1, 1, 2511.47, -3645.04, 186.6923, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+866, 45485, 0, 1, 1, 2505.78, -3634.27, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+867, 45485, 0, 1, 1, 2509.39, -3643.4, 186.4613, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+868, 45485, 0, 1, 1, 2510.15, -3644.88, 186.6923, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+869, 45485, 0, 1, 1, 2506.18, -3636.16, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+870, 45485, 0, 1, 1, 2511.1, -3646.32, 186.6923, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+871, 45488, 0, 1, 1, 2509.77, -3645.18, 186.6923, 1.204277, 120, 0, 0), -- Necropolis Flower Controller W (Area: Plaguewood)
(@CGUID+872, 45485, 0, 1, 1, 2504.94, -3635.67, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+873, 45485, 0, 1, 1, 2508.56, -3644.39, 186.6923, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+874, 45485, 0, 1, 1, 2509.72, -3646.54, 186.6923, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+875, 45485, 0, 1, 1, 2508.6, -3645.69, 186.6923, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+876, 45485, 0, 1, 1, 2503.49, -3635.89, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+877, 45485, 0, 1, 1, 2501.59, -3636.3, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+878, 45485, 0, 1, 1, 2501.02, -3637.69, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+879, 45485, 0, 1, 1, 2500.23, -3639.36, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+880, 45485, 0, 1, 1, 2498.82, -3640.14, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+881, 45485, 0, 1, 1, 2498.6, -3641.71, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+882, 45485, 0, 1, 1, 2498.73, -3643.37, 183.6933, 3.804818, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+883, 8529, 0, 1, 1, 2452.726, -3646.424, 178.4471, 5.707097, 120, 0, 0), -- Scourge Champion (Area: The Fungal Vale)
(@CGUID+884, 8529, 0, 1, 1, 2420.824, -3625.694, 178.5886, 3.753902, 120, 0, 0), -- Scourge Champion (Area: The Fungal Vale)
(@CGUID+885, 8529, 0, 1, 1, 2383.505, -3647.229, 177.5638, 0.4467084, 120, 0, 0), -- Scourge Champion (Area: The Fungal Vale)
(@CGUID+886, 8529, 0, 1, 1, 2361.971, -3622.163, 177.4219, 5.98474, 120, 0, 0), -- Scourge Champion (Area: The Fungal Vale)
(@CGUID+887, 8603, 0, 1, 1, 2025.983, -3613.242, 125.8703, 0.3402669, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+888, 41178, 0, 1, 1, 2261.601, -4459.677, 163.8536, 0.08726646, 120, 0, 0), -- Northwatch Tower Stalker (Area: 0)
(@CGUID+889, 47064, 0, 1, 1, 1711.766, -3592.189, 122.4395, 5.759586, 120, 0, 0), -- Mossflayer Abducter (Area: 0) (possible waypoints or random movement)
(@CGUID+890, 2110, 0, 1, 1, 1444.869, -3620.391, 81.70219, 1.375125, 120, 0, 0), -- Black Rat (Area: Darrowshire)
(@CGUID+891, 10926, 0, 1, 1, 1458.168, -3596.744, 86.9664, 5.695086, 120, 0, 0), -- Pamela Redpath (Area: Darrowshire) (possible waypoints or random movement)
(@CGUID+892, 2110, 0, 1, 1, 1406.417, -3702.173, 76.49106, 2.842092, 120, 0, 0), -- Black Rat (Area: Darrowshire)
(@CGUID+893, 2110, 0, 1, 1, 1403.139, -3709.257, 76.95634, 0.7936853, 120, 0, 0), -- Black Rat (Area: Darrowshire)
(@CGUID+894, 2110, 0, 1, 1, 1427.214, -3699.705, 75.84918, 5.005717, 120, 0, 0), -- Black Rat (Area: Darrowshire)
(@CGUID+895, 2110, 0, 1, 1, 1488.57, -3659.305, 82.17485, 1.86104, 120, 0, 0), -- Black Rat (Area: Darrowshire)
(@CGUID+896, 8600, 0, 1, 1, 1653.442, -3712.72, 119.2872, 3.95808, 120, 0, 0), -- Plaguebat (Area: Darrowshire)
(@CGUID+897, 32520, 0, 1, 1, -6014.71, 5479.63, -1208.007, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Darrowshire)
(@CGUID+898, 32520, 0, 1, 1, -6148.39, 5539.97, -1207.787, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Darrowshire)
(@CGUID+899, 32520, 0, 1, 1, -6305.162, 5582.533, -1172.063, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Darrowshire)
(@CGUID+900, 32520, 0, 1, 1, -5691.65, 5556.92, -1154.687, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Darrowshire)
(@CGUID+901, 47064, 0, 1, 1, 1701.549, -3635.75, 118.9957, 6.178465, 120, 0, 0), -- Mossflayer Abducter (Area: Darrowshire) (possible waypoints or random movement)
(@CGUID+902, 51986, 0, 1, 1, 1782.53, -3646.99, 120.6793, 3.390003, 120, 0, 0), -- Argent Sentry (Area: Darrowshire)
(@CGUID+903, 51986, 0, 1, 1, 1760.75, -3655.17, 120.2083, 3.089233, 120, 0, 0), -- Argent Sentry (Area: Darrowshire) (possible waypoints or random movement)
(@CGUID+904, 47064, 0, 1, 1, 1782.155, -3647.874, 120.3992, 1.168325, 120, 0, 0), -- Mossflayer Abducter (Area: Darrowshire) (possible waypoints or random movement)
(@CGUID+905, 47064, 0, 1, 1, 1759.76, -3655.307, 120.1963, 0.1380384, 120, 0, 0), -- Mossflayer Abducter (Area: Darrowshire) (possible waypoints or random movement)
(@CGUID+906, 47064, 0, 1, 1, 1756.66, -3638.027, 120.5651, 0.3762104, 120, 0, 0), -- Mossflayer Abducter (Area: Darrowshire)
(@CGUID+907, 47064, 0, 1, 1, 1711.766, -3592.189, 122.4395, 5.759586, 120, 0, 0), -- Mossflayer Abducter (Area: Darrowshire) (possible waypoints or random movement)
(@CGUID+908, 47064, 0, 1, 1, 1717.872, -3675.064, 122.2024, 0.8203048, 120, 0, 0), -- Mossflayer Abducter (Area: 0) (possible waypoints or random movement)
(@CGUID+909, 47060, 0, 1, 1, 1832.41, -3635.67, 129.7113, 3.01942, 120, 0, 0), -- Argent Sentry (Area: 0)
(@CGUID+910, 47060, 0, 1, 1, 1828.23, -3648.26, 130.8943, 2.600541, 120, 0, 0), -- Argent Sentry (Area: 0)
(@CGUID+911, 47064, 0, 1, 1, 1730.429, -3702.957, 122.1848, 0.8028514, 120, 0, 0), -- Mossflayer Abducter (Area: 0) (possible waypoints or random movement)
(@CGUID+912, 47064, 0, 1, 1, 1714.972, -3661.563, 122.4638, 0.1396263, 120, 0, 0), -- Mossflayer Abducter (Area: 0) (possible waypoints or random movement)
(@CGUID+913, 47064, 0, 1, 1, 1703.438, -3659.128, 116.7514, 0.3665192, 120, 0, 0), -- Mossflayer Abducter (Area: 0) (possible waypoints or random movement)
(@CGUID+914, 47060, 0, 1, 1, 1861.4, -3674.04, 152.9003, 1.780236, 120, 0, 0), -- Argent Sentry (Area: 0)
(@CGUID+915, 47060, 0, 1, 1, 1853.66, -3702.73, 160.6683, 1.361357, 120, 0, 0), -- Argent Sentry (Area: 0)
(@CGUID+916, 47060, 0, 1, 1, 1864.62, -3706.84, 160.6683, 1.413717, 120, 0, 0), -- Argent Sentry (Area: 0)
(@CGUID+917, 47060, 0, 1, 1, 1856.92, -3706.71, 160.5854, 6.213797, 120, 0, 0), -- Argent Sentry (Area: 0) (possible waypoints or random movement)
(@CGUID+918, 10667, 0, 1, 1, 1874.663, -3708.887, 159.475, 5.943356, 120, 0, 0), -- Chromie (Area: 0) (possible waypoints or random movement)
(@CGUID+919, 45500, 0, 1, 1, 1872.73, -3699.23, 159.0503, 2.181662, 120, 0, 0), -- Urk Gagbaz (Area: 0)
(@CGUID+920, 44240, 0, 1, 1, 1883.2, -3692.82, 157.7703, 2.96706, 120, 0, 0), -- Argent Hippogryph (Area: 0)
(@CGUID+921, 44232, 0, 1, 1, 1879.72, -3694.56, 157.7703, 2.687807, 120, 0, 0), -- Janice Myers (Area: 0)
(@CGUID+922, 47060, 0, 1, 1, 1870.64, -3669.62, 152.4113, 2.199115, 120, 0, 0), -- Argent Sentry (Area: 0)
(@CGUID+923, 2110, 0, 1, 1, 1992.343, -3661.058, 122.4972, 6.149989, 120, 0, 0), -- Black Rat (Area: Crown Guard Tower)
(@CGUID+924, 8596, 0, 1, 1, 2045.209, -3644.963, 131.4049, 5.474986, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+925, 8596, 0, 1, 1, 2109.621, -3706.14, 138.8698, 5.095889, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+926, 8529, 0, 1, 1, 2365.168, -3689.777, 180.1357, 3.286667, 120, 0, 0), -- Scourge Champion (Area: 0)
(@CGUID+927, 8546, 0, 1, 1, 2415.153, -3694.292, 179.242, 4.031711, 120, 0, 0), -- Dark Adept (Area: The Fungal Vale) (possible waypoints or random movement)
(@CGUID+928, 8546, 0, 1, 1, 2405.304, -3704.043, 178.6121, 0.8203048, 120, 0, 0), -- Dark Adept (Area: The Fungal Vale)
(@CGUID+929, 8529, 0, 1, 1, 2425.565, -3680.674, 178.8911, 1.438615, 120, 0, 0), -- Scourge Champion (Area: The Fungal Vale)
(@CGUID+930, 8529, 0, 1, 1, 2500.27, -3678.14, 186.6933, 4.380776, 120, 0, 0), -- Scourge Champion (Area: The Fungal Vale)
(@CGUID+931, 8550, 0, 1, 1, 2478.507, -3703.926, 178.0764, 3.647738, 120, 0, 0), -- Shadowmage (Area: The Fungal Vale)
(@CGUID+932, 8546, 0, 1, 1, 2471.103, -3708.018, 177.9649, 0.6108652, 120, 0, 0), -- Dark Adept (Area: The Fungal Vale)
(@CGUID+933, 8529, 0, 1, 1, 2518.616, -3718.467, 180.9694, 1.155803, 120, 0, 0), -- Scourge Champion (Area: The Fungal Vale)
(@CGUID+934, 8550, 0, 1, 1, 2537.944, -3702.786, 179.6674, 6.021386, 120, 0, 0), -- Shadowmage (Area: The Fungal Vale)
(@CGUID+935, 8550, 0, 1, 1, 2544.982, -3705.428, 179.7261, 2.6529, 120, 0, 0), -- Shadowmage (Area: The Fungal Vale)
(@CGUID+936, 45897, 0, 1, 1, 2775.02, -3679.17, 102.6003, 6.195919, 120, 0, 0), -- Plaguewood Reanimator (Area: Plaguewood)
(@CGUID+937, 45897, 0, 1, 1, 2790.67, -3699.94, 105.1843, 1.396263, 120, 0, 0), -- Plaguewood Reanimator (Area: Plaguewood)
(@CGUID+938, 45897, 0, 1, 1, 2807.43, -3668.1, 104.5813, 3.944444, 120, 0, 0), -- Plaguewood Reanimator (Area: Plaguewood)
(@CGUID+939, 45897, 0, 1, 1, 2809.03, -3690.47, 103.5403, 2.722714, 120, 0, 0), -- Plaguewood Reanimator (Area: Plaguewood)
(@CGUID+940, 45851, 0, 1, 1, 2874.149, -3679.701, 115.663, 6.261704, 120, 0, 0), -- Overstuffed Golem (Area: Plaguewood)
(@CGUID+941, 8547, 0, 1, 1, 2917.01, -3708.26, 116.6883, 6.213372, 120, 0, 0), -- Death Cultist (Area: Plaguewood)
(@CGUID+942, 8524, 0, 1, 1, 3113.612, -3678.992, 136.7292, 0.003781495, 120, 0, 0), -- Cursed Mage (Area: Plaguewood)
(@CGUID+943, 8530, 0, 1, 1, 3248.151, -3687.932, 144.612, 5.946925, 120, 0, 0), -- Cannibal Ghoul (Area: Plaguewood)
(@CGUID+944, 45851, 0, 1, 1, 3282.29, -3748.86, 150.4255, 2.136788, 120, 0, 0), -- Overstuffed Golem (Area: Plaguewood)
(@CGUID+945, 45851, 0, 1, 1, 3204.479, -3754.311, 146.9643, 3.603057, 120, 0, 0), -- Overstuffed Golem (Area: Plaguewood)
(@CGUID+946, 10819, 0, 1, 1, 3130.545, -3725.292, 135.3372, 3.159046, 120, 0, 0), -- Baron Bloodbane (Area: Plaguewood)
(@CGUID+947, 45851, 0, 1, 1, 3178.708, -3715.532, 134.5833, 5.078827, 120, 0, 0), -- Overstuffed Golem (Area: Plaguewood)
(@CGUID+948, 45851, 0, 1, 1, 3008.849, -3758.991, 128.4149, 3.613484, 120, 0, 0), -- Overstuffed Golem (Area: Plaguewood)
(@CGUID+949, 45851, 0, 1, 1, 2978.791, -3730.303, 124.5042, 4.391565, 120, 0, 0), -- Overstuffed Golem (Area: Plaguewood)
(@CGUID+950, 8523, 0, 1, 1, 2945.45, -3746.695, 119.0312, 4.845716, 120, 0, 0), -- Scourge Soldier (Area: Plaguewood)
(@CGUID+951, 8530, 0, 1, 1, 2859.344, -3724.888, 113.806, 5.819291, 120, 0, 0), -- Cannibal Ghoul (Area: Plaguewood)
(@CGUID+952, 8550, 0, 1, 1, 2473.866, -3731.262, 183.6114, 5.742133, 120, 0, 0), -- Shadowmage (Area: The Fungal Vale)
(@CGUID+953, 8529, 0, 1, 1, 2455.708, -3717.353, 177.3825, 4.762789, 120, 0, 0), -- Scourge Champion (Area: The Fungal Vale)
(@CGUID+954, 8596, 0, 1, 1, 2040.266, -3724.151, 131.0567, 4.017375, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+955, 8600, 0, 1, 1, 1944.047, -3732.182, 132.4963, 1.72267, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+956, 47060, 0, 1, 1, 1853.02, -3733.58, 160.6773, 1.413717, 120, 0, 0), -- Argent Sentry (Area: Crown Guard Tower)
(@CGUID+957, 47060, 0, 1, 1, 1846.6, -3736.51, 163.6563, 5.382619, 120, 0, 0), -- Argent Sentry (Area: Crown Guard Tower) (possible waypoints or random movement)
(@CGUID+958, 11063, 0, 1, 1, 1852.64, -3721.62, 160.6713, 1.117011, 120, 0, 0), -- Carlin Redpath (Area: Crown Guard Tower)
(@CGUID+959, 47139, 0, 1, 1, 1845.11, -3723.73, 160.6743, 0.1745329, 120, 0, 0), -- Gerald Fairbanks (Area: Crown Guard Tower)
(@CGUID+960, 45451, 0, 1, 1, 1841.74, -3726.59, 195.6799, 3.016105, 120, 0, 0), -- Argus Highbeacon (Area: Crown Guard Tower)
(@CGUID+961, 47064, 0, 1, 1, 1777.188, -3632.807, 121.6198, 1.77477, 120, 0, 0), -- Mossflayer Abducter (Area: Crown Guard Tower)
(@CGUID+962, 47064, 0, 1, 1, 1782.155, -3647.874, 120.3992, 1.168325, 120, 0, 0), -- Mossflayer Abducter (Area: Crown Guard Tower) (possible waypoints or random movement)
(@CGUID+963, 47064, 0, 1, 1, 1775.591, -3628.729, 122.2385, 5.747258, 120, 0, 0), -- Mossflayer Abducter (Area: Crown Guard Tower) (possible waypoints or random movement)
(@CGUID+964, 47064, 0, 1, 1, 1701.549, -3635.75, 118.9957, 6.178465, 120, 0, 0), -- Mossflayer Abducter (Area: Crown Guard Tower) (possible waypoints or random movement)
(@CGUID+965, 47064, 0, 1, 1, 1714.972, -3661.563, 122.4638, 0.1396263, 120, 0, 0), -- Mossflayer Abducter (Area: Crown Guard Tower) (possible waypoints or random movement)
(@CGUID+966, 47064, 0, 1, 1, 1756.66, -3638.027, 120.5651, 0.3761074, 120, 0, 0), -- Mossflayer Abducter (Area: Crown Guard Tower)
(@CGUID+967, 47064, 0, 1, 1, 1717.872, -3675.064, 122.2024, 0.8203048, 120, 0, 0), -- Mossflayer Abducter (Area: 0) (possible waypoints or random movement)
(@CGUID+968, 47064, 0, 1, 1, 1730.429, -3702.957, 122.1848, 0.8028514, 120, 0, 0), -- Mossflayer Abducter (Area: 0) (possible waypoints or random movement)
(@CGUID+969, 47064, 0, 1, 1, 1703.438, -3659.128, 116.7514, 0.3665192, 120, 0, 0), -- Mossflayer Abducter (Area: 0) (possible waypoints or random movement)
(@CGUID+970, 8600, 0, 1, 1, 1692.529, -3740.184, 128.2528, 0.5523266, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+971, 8600, 0, 1, 1, 1721.578, -3730.472, 131.8621, 5.625823, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+972, 47064, 0, 1, 1, 1711.766, -3592.189, 122.4395, 5.759586, 120, 0, 0), -- Mossflayer Abducter (Area: Darrowshire) (possible waypoints or random movement)
(@CGUID+973, 46016, 0, 1, 1, 1399.84, -3781.54, 117.1883, 0, 120, 0, 0), -- Spectral Critter (Area: Darrowshire)
(@CGUID+974, 46016, 0, 1, 1, 1441.177, -3748.354, 87.64323, 4.728013, 120, 0, 0), -- Spectral Critter (Area: Darrowshire)
(@CGUID+975, 46016, 0, 1, 1, 1429.07, -3814.34, 123.9923, 0, 120, 0, 0), -- Spectral Critter (Area: Darrowshire) (possible waypoints or random movement)
(@CGUID+976, 46016, 0, 1, 1, 1445.33, -3768.26, 99.78374, 0, 120, 0, 0), -- Spectral Critter (Area: Darrowshire) (possible waypoints or random movement)
(@CGUID+977, 10780, 0, 1, 1, 1536.021, -3767.444, 109.1943, 1.776431, 120, 0, 0), -- Infected Deer (Area: Darrowshire)
(@CGUID+978, 46016, 0, 1, 1, 1477.319, -3818.719, 106.9026, 4.822214, 120, 0, 0), -- Spectral Critter (Area: Darrowshire) (possible waypoints or random movement)
(@CGUID+979, 46016, 0, 1, 1, 1501.2, -3808.05, 103.0923, 0, 120, 0, 0), -- Spectral Critter (Area: Darrowshire) (possible waypoints or random movement)
(@CGUID+980, 20725, 0, 1, 1, 1544.701, -3802.12, 115.9153, 0.6145425, 120, 0, 0), -- Bat (Area: Darrowshire)
(@CGUID+981, 8600, 0, 1, 1, 1705.629, -3791.23, 127.8775, 0.5307285, 120, 0, 0), -- Plaguebat (Area: Darrowshire)
(@CGUID+982, 8600, 0, 1, 1, 1663.18, -3793.113, 130.6688, 5.770583, 120, 0, 0), -- Plaguebat (Area: Darrowshire)
(@CGUID+983, 8600, 0, 1, 1, 1677.93, -3803.77, 132.348, 2.298818, 120, 0, 0), -- Plaguebat (Area: Darrowshire)
(@CGUID+984, 8534, 0, 1, 1, 1669.133, -3799.819, 131.3566, 1.563217, 120, 0, 0), -- Putrid Gargoyle (Area: Darrowshire)
(@CGUID+985, 47064, 0, 1, 1, 1703.438, -3659.128, 116.7514, 0.3665192, 120, 0, 0), -- Mossflayer Abducter (Area: Darrowshire) (possible waypoints or random movement)
(@CGUID+986, 47064, 0, 1, 1, 1714.972, -3661.563, 122.4638, 0.1396263, 120, 0, 0), -- Mossflayer Abducter (Area: Darrowshire) (possible waypoints or random movement)
(@CGUID+987, 47064, 0, 1, 1, 1782.155, -3647.874, 120.3992, 1.168325, 120, 0, 0), -- Mossflayer Abducter (Area: 0) (possible waypoints or random movement)
(@CGUID+988, 47064, 0, 1, 1, 1776.266, -3643.741, 120.7312, 6.173963, 120, 0, 0), -- Mossflayer Abducter (Area: 0) (possible waypoints or random movement)
(@CGUID+989, 8600, 0, 1, 1, 1791.398, -3791.33, 128.61, 5.825485, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+990, 8600, 0, 1, 1, 1810.204, -3809.055, 130.8764, 2.277851, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+991, 8596, 0, 1, 1, 1913.772, -3774.87, 129.8212, 1.505332, 120, 0, 0), -- Plaguehound Runt (Area: Crown Guard Tower)
(@CGUID+992, 2110, 0, 1, 1, 1974.901, -3655.072, 120.188, 2.441857, 120, 0, 0), -- Black Rat (Area: Crown Guard Tower)
(@CGUID+993, 47064, 0, 1, 1, 1779.553, -3644.85, 120.65, 2.730306, 120, 0, 0), -- Mossflayer Abducter (Area: Crown Guard Tower)
(@CGUID+994, 8603, 0, 1, 1, 1991.2, -3778.877, 125.7906, 0.7929894, 120, 0, 0), -- Carrion Grub (Area: Crown Guard Tower)
(@CGUID+995, 8596, 0, 1, 1, 1948.799, -3803.441, 127.71, 0.9491838, 120, 0, 0), -- Plaguehound Runt (Area: Crown Guard Tower)
(@CGUID+996, 10817, 0, 1, 1, 2037.999, -3740.185, 130.9236, 6.216015, 120, 0, 0), -- Duggan Wildhammer (Area: Crown Guard Tower) (possible waypoints or random movement)
(@CGUID+997, 8603, 0, 1, 1, 2024.749, -3742.457, 128.9376, 2.355257, 120, 0, 0), -- Carrion Grub (Area: Crown Guard Tower)
(@CGUID+998, 8603, 0, 1, 1, 2092.889, -3782.73, 134.2551, 2.80501, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+999, 20725, 0, 1, 1, 2057.607, -3777.021, 135.6657, 5.577973, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+1000, 8596, 0, 1, 1, 2080.614, -3788.33, 133.8156, 2.527529, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+1001, 8600, 0, 1, 1, 2047.352, -3779.593, 134.7003, 3.228706, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+1002, 11288, 0, 1, 1, 2081.91, -3784.428, 133.9226, 4.511741, 120, 0, 0), -- Spectral Betrayer (Area: 0)
(@CGUID+1003, 11288, 0, 1, 1, 2080.98, -3784.76, 133.9203, 5.794493, 120, 0, 0), -- Spectral Betrayer (Area: 0)
(@CGUID+1004, 11289, 0, 1, 1, 2082.55, -3789.43, 133.6703, 1.256637, 120, 0, 0), -- Spectral Defender (Area: 0)
(@CGUID+1005, 11288, 0, 1, 1, 2088.788, -3787.421, 133.7974, 4.523566, 120, 0, 0), -- Spectral Betrayer (Area: 0)
(@CGUID+1006, 11289, 0, 1, 1, 2088.274, -3790.731, 133.7139, 1.027028, 120, 0, 0), -- Spectral Defender (Area: 0)
(@CGUID+1007, 11288, 0, 1, 1, 2090.04, -3787.81, 133.8783, 0.5585054, 120, 0, 0), -- Spectral Betrayer (Area: 0)
(@CGUID+1008, 11288, 0, 1, 1, 2084.874, -3786.598, 133.8389, 4.025126, 120, 0, 0), -- Spectral Betrayer (Area: 0)
(@CGUID+1009, 11288, 0, 1, 1, 2083.457, -3784.621, 133.9968, 4.122027, 120, 0, 0), -- Spectral Betrayer (Area: 0)
(@CGUID+1010, 11289, 0, 1, 1, 2081.399, -3786.939, 133.8818, 1.370037, 120, 0, 0), -- Spectral Defender (Area: 0)
(@CGUID+1011, 11288, 0, 1, 1, 2089.72, -3789.77, 133.7653, 5.323254, 120, 0, 0), -- Spectral Betrayer (Area: 0)
(@CGUID+1012, 8546, 0, 1, 1, 2387.775, -3758.782, 180.5881, 2.042035, 120, 0, 0), -- Dark Adept (Area: The Fungal Vale)
(@CGUID+1013, 8550, 0, 1, 1, 2384.114, -3752.099, 179.9697, 5.113815, 120, 0, 0), -- Shadowmage (Area: The Fungal Vale)
(@CGUID+1014, 8529, 0, 1, 1, 2415.957, -3743.364, 178.3592, 2.882877, 120, 0, 0), -- Scourge Champion (Area: The Fungal Vale)
(@CGUID+1015, 8529, 0, 1, 1, 2434.17, -3781.61, 185.5553, 0.5759587, 120, 0, 0), -- Scourge Champion (Area: The Fungal Vale)
(@CGUID+1016, 8546, 0, 1, 1, 2406.185, -3801.306, 185.5546, 0.6283185, 120, 0, 0), -- Dark Adept (Area: The Fungal Vale) (possible waypoints or random movement)
(@CGUID+1017, 45485, 0, 1, 1, 2401.3, -3792.16, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1018, 45485, 0, 1, 1, 2400.73, -3794.07, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1019, 45485, 0, 1, 1, 2398.75, -3794.62, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1020, 45485, 0, 1, 1, 2397.18, -3795.21, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1021, 45485, 0, 1, 1, 2396.2, -3796.63, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1022, 45485, 0, 1, 1, 2396.09, -3798.09, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1023, 45485, 0, 1, 1, 2395.05, -3798.99, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1024, 45485, 0, 1, 1, 2406.07, -3799.7, 185.5543, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1025, 45485, 0, 1, 1, 2394.14, -3800.24, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1026, 45485, 0, 1, 1, 2395.59, -3800.3, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1027, 45485, 0, 1, 1, 2404.96, -3800.44, 185.5543, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1028, 45485, 0, 1, 1, 2396.88, -3800.14, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1029, 45485, 0, 1, 1, 2404.05, -3801.1, 185.3993, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1030, 45485, 0, 1, 1, 2392.76, -3801.28, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1031, 45485, 0, 1, 1, 2407.26, -3800.43, 185.5543, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1032, 45486, 0, 1, 1, 2406.45, -3801.06, 185.5543, 3.804818, 120, 0, 0), -- Necropolis Flower Controller SE (Area: The Fungal Vale)
(@CGUID+1033, 45485, 0, 1, 1, 2405.86, -3801.42, 185.5543, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1034, 45485, 0, 1, 1, 2394.87, -3801.76, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1035, 45485, 0, 1, 1, 2393.68, -3802.49, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1036, 45485, 0, 1, 1, 2396.11, -3802.15, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1037, 45485, 0, 1, 1, 2404.66, -3802.27, 185.3073, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1038, 45485, 0, 1, 1, 2407.57, -3801.8, 185.5543, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1039, 45485, 0, 1, 1, 2402.64, -3802.87, 184.2693, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1040, 45485, 0, 1, 1, 2395.01, -3803.16, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1041, 45485, 0, 1, 1, 2405.48, -3803.03, 185.4343, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1042, 45485, 0, 1, 1, 2406.75, -3802.83, 185.5543, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1043, 45485, 0, 1, 1, 2404.06, -3803.35, 184.7083, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1044, 45485, 0, 1, 1, 2401.35, -3803.47, 183.6263, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1045, 45485, 0, 1, 1, 2396.27, -3803.8, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1046, 45485, 0, 1, 1, 2403.13, -3804.04, 184.1473, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1047, 45485, 0, 1, 1, 2399.81, -3804.19, 182.8873, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1048, 45485, 0, 1, 1, 2402.26, -3804.44, 183.7173, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1049, 45485, 0, 1, 1, 2397.94, -3804.53, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1050, 45485, 0, 1, 1, 2401.05, -3804.64, 183.2173, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1051, 45485, 0, 1, 1, 2399.27, -3805.03, 182.7053, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1052, 8550, 0, 1, 1, 2494.875, -3768.02, 177.5898, 5.742133, 120, 0, 0), -- Shadowmage (Area: The Fungal Vale)
(@CGUID+1053, 8546, 0, 1, 1, 2502.799, -3770.042, 177.5898, 2.70526, 120, 0, 0), -- Dark Adept (Area: The Fungal Vale)
(@CGUID+1054, 8529, 0, 1, 1, 2555.521, -3758.429, 179.0783, 0.3340956, 120, 0, 0), -- Scourge Champion (Area: The Fungal Vale)
(@CGUID+1055, 8529, 0, 1, 1, 2534.82, -3790.2, 185.1413, 2.391101, 120, 0, 0), -- Scourge Champion (Area: The Fungal Vale)
(@CGUID+1056, 45485, 0, 1, 1, 2568.66, -3800.53, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1057, 41178, 0, 1, 1, 2565.167, -4800.644, 158.6523, 0.08726646, 120, 0, 0), -- Northwatch Tower Stalker (Area: The Fungal Vale)
(@CGUID+1058, 8553, 0, 1, 1, 2814.52, -3757.79, 122.5073, 3.351032, 120, 0, 0), -- Necromancer (Area: Plaguewood)
(@CGUID+1059, 8524, 0, 1, 1, 2915.904, -3781.507, 116.3459, 2.065581, 120, 0, 0), -- Cursed Mage (Area: Plaguewood)
(@CGUID+1060, 8530, 0, 1, 1, 2878.424, -3761.622, 110.198, 4.821218, 120, 0, 0), -- Cannibal Ghoul (Area: Plaguewood)
(@CGUID+1061, 8534, 0, 1, 1, 2921.45, -3762.7, 114.8187, 3.008356, 120, 0, 0), -- Putrid Gargoyle (Area: Plaguewood)
(@CGUID+1062, 8524, 0, 1, 1, 3126.856, -3782.386, 132.0181, 0.3529421, 120, 0, 0), -- Cursed Mage (Area: Plaguewood)
(@CGUID+1063, 45851, 0, 1, 1, 3189.634, -3789.354, 141.8704, 3.711707, 120, 0, 0), -- Overstuffed Golem (Area: Plaguewood)
(@CGUID+1064, 8530, 0, 1, 1, 3251.856, -3777.56, 142.8784, 3.117425, 120, 0, 0), -- Cannibal Ghoul (Area: Plaguewood)
(@CGUID+1065, 45851, 0, 1, 1, 3215.174, -3813.552, 140.9363, 6.010252, 120, 0, 0), -- Overstuffed Golem (Area: Plaguewood)
(@CGUID+1066, 45851, 0, 1, 1, 3143.574, -3814.796, 128.2035, 0.4208042, 120, 0, 0), -- Overstuffed Golem (Area: Plaguewood)
(@CGUID+1067, 45851, 0, 1, 1, 3193.509, -3839.284, 130.3294, 0.5531687, 120, 0, 0), -- Overstuffed Golem (Area: Plaguewood)
(@CGUID+1068, 8524, 0, 1, 1, 3079.702, -3828.127, 129.8834, 4.944095, 120, 0, 0), -- Cursed Mage (Area: Plaguewood)
(@CGUID+1069, 8523, 0, 1, 1, 3067.693, -3857.181, 124.9354, 0.00287769, 120, 0, 0), -- Scourge Soldier (Area: Plaguewood)
(@CGUID+1070, 8524, 0, 1, 1, 2915.657, -3851.984, 119.9731, 2.650553, 120, 0, 0), -- Cursed Mage (Area: Plaguewood)
(@CGUID+1071, 8523, 0, 1, 1, 2881.493, -3820.507, 111.5277, 5.079741, 120, 0, 0), -- Scourge Soldier (Area: Plaguewood)
(@CGUID+1072, 8524, 0, 1, 1, 2946.599, -3818.093, 125.7932, 1.410442, 120, 0, 0), -- Cursed Mage (Area: Plaguewood)
(@CGUID+1073, 8524, 0, 1, 1, 2851.477, -3850.892, 106.0787, 5.714135, 120, 0, 0), -- Cursed Mage (Area: Plaguewood)
(@CGUID+1074, 8524, 0, 1, 1, 2808.851, -3824.279, 104.0486, 0.3322505, 120, 0, 0), -- Cursed Mage (Area: Plaguewood)
(@CGUID+1075, 8530, 0, 1, 1, 2790.047, -3858.698, 100.538, 4.739248, 120, 0, 0), -- Cannibal Ghoul (Area: Plaguewood)
(@CGUID+1076, 10826, 0, 1, 1, 2515.026, -3704.672, 178.8145, 2.459229, 120, 0, 0), -- Lord Darkscythe (Area: Plaguewood) (possible waypoints or random movement)
(@CGUID+1077, 8550, 0, 1, 1, 2562.623, -3810.431, 185.1411, 2.478368, 120, 0, 0), -- Shadowmage (Area: Plaguewood)
(@CGUID+1078, 45485, 0, 1, 1, 2574.01, -3805.97, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1079, 45485, 0, 1, 1, 2571.58, -3801.9, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1080, 45485, 0, 1, 1, 2572.96, -3804.89, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1081, 45485, 0, 1, 1, 2571.75, -3803.5, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1082, 45485, 0, 1, 1, 2570.24, -3801.07, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1083, 45485, 0, 1, 1, 2573.63, -3807.87, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1084, 45485, 0, 1, 1, 2575.66, -3811.45, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1085, 45485, 0, 1, 1, 2575.97, -3812.88, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1086, 45485, 0, 1, 1, 2574.2, -3810.62, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1087, 45485, 0, 1, 1, 2573.25, -3809.3, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1088, 45485, 0, 1, 1, 2576.69, -3814.35, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1089, 45485, 0, 1, 1, 2574.66, -3812.03, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1090, 45485, 0, 1, 1, 2572.31, -3810.23, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1091, 45485, 0, 1, 1, 2573.13, -3811.45, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1092, 45485, 0, 1, 1, 2575.25, -3814.56, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1093, 45485, 0, 1, 1, 2574.26, -3813.8, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1094, 45485, 0, 1, 1, 2573.2, -3812.68, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1095, 45485, 0, 1, 1, 2575.72, -3815.84, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1096, 45485, 0, 1, 1, 2574.09, -3815.26, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1097, 45485, 0, 1, 1, 2573, -3814.29, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1098, 45485, 0, 1, 1, 2574.72, -3816.58, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1099, 45485, 0, 1, 1, 2571.93, -3813.3, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1100, 45485, 0, 1, 1, 2572.81, -3815.77, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1101, 45485, 0, 1, 1, 2571.86, -3814.83, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1102, 45485, 0, 1, 1, 2573.29, -3817.21, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1103, 45485, 0, 1, 1, 2570.59, -3814.62, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1104, 45485, 0, 1, 1, 2563.82, -3809.15, 185.1413, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1105, 45485, 0, 1, 1, 2564.39, -3810.3, 185.0083, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1106, 45485, 0, 1, 1, 2572.92, -3818.45, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1107, 45485, 0, 1, 1, 2571.07, -3816.23, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1108, 45485, 0, 1, 1, 2568.52, -3813.47, 182.5023, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1109, 45485, 0, 1, 1, 2572.02, -3817.55, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1110, 45485, 0, 1, 1, 2562.6, -3808.67, 185.1413, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1111, 45485, 0, 1, 1, 2565.1, -3811.56, 184.2953, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1112, 45485, 0, 1, 1, 2569.09, -3814.43, 182.2883, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1113, 45485, 0, 1, 1, 2566.04, -3812.26, 183.7323, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1114, 45485, 0, 1, 1, 2566.68, -3812.98, 183.3053, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1115, 45485, 0, 1, 1, 2563.9, -3811.31, 184.9013, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1116, 45485, 0, 1, 1, 2569.78, -3816.08, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1117, 45485, 0, 1, 1, 2562.74, -3810.41, 185.1413, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1118, 45487, 0, 1, 1, 2562.52, -3810.19, 185.1413, 5.654867, 120, 0, 0), -- Necropolis Flower Controller NE (Area: Plaguewood)
(@CGUID+1119, 45485, 0, 1, 1, 2567.22, -3814.07, 182.8143, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1120, 45485, 0, 1, 1, 2570.61, -3817.61, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1121, 45485, 0, 1, 1, 2571.87, -3819.36, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1122, 45485, 0, 1, 1, 2565.06, -3813.07, 183.8743, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1123, 45485, 0, 1, 1, 2561.38, -3809.36, 185.1413, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1124, 45485, 0, 1, 1, 2568.11, -3815.65, 182.3023, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1125, 45485, 0, 1, 1, 2566.02, -3814.13, 183.2363, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1126, 45485, 0, 1, 1, 2562.96, -3812.23, 185.0193, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1127, 45485, 0, 1, 1, 2562.06, -3811.56, 185.1413, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1128, 45485, 0, 1, 1, 2567.16, -3815.39, 182.4853, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1129, 45485, 0, 1, 1, 2569.41, -3818.01, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1130, 45485, 0, 1, 1, 2570.41, -3819.43, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1131, 45485, 0, 1, 1, 2561.03, -3810.72, 185.1413, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1132, 45485, 0, 1, 1, 2571.32, -3820.78, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1133, 45485, 0, 1, 1, 2568.03, -3817.08, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1134, 45485, 0, 1, 1, 2569.17, -3819.58, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1135, 45485, 0, 1, 1, 2570.23, -3821.55, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1136, 45485, 0, 1, 1, 2567.81, -3818.88, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1137, 45485, 0, 1, 1, 2568.77, -3821.7, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1138, 45485, 0, 1, 1, 2567.57, -3820.28, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1139, 45485, 0, 1, 1, 2569.67, -3822.94, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1140, 45485, 0, 1, 1, 2566.28, -3819.52, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1141, 45485, 0, 1, 1, 2567.31, -3821.76, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1142, 45485, 0, 1, 1, 2568.28, -3823.15, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1143, 45485, 0, 1, 1, 2566.27, -3820.82, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1144, 45485, 0, 1, 1, 2564.14, -3819.38, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1145, 45485, 0, 1, 1, 2564.66, -3820.56, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1146, 45485, 0, 1, 1, 2566.42, -3822.98, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1147, 45485, 0, 1, 1, 2565.02, -3821.96, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1148, 45485, 0, 1, 1, 2563.57, -3821.47, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1149, 45485, 0, 1, 1, 2562.4, -3820.73, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1150, 45485, 0, 1, 1, 2560.97, -3821.05, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1151, 45485, 0, 1, 1, 2559.33, -3820.52, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1152, 45485, 0, 1, 1, 2558.31, -3819.2, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1153, 45485, 0, 1, 1, 2557.09, -3817.81, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1154, 45485, 0, 1, 1, 2555.58, -3817.45, 182.1423, 1.850049, 120, 0, 0), -- Necropolis Flowers (Area: Plaguewood)
(@CGUID+1155, 8546, 0, 1, 1, 2508.983, -3809.266, 178.2529, 3.193953, 120, 0, 0), -- Dark Adept (Area: Plaguewood)
(@CGUID+1156, 8546, 0, 1, 1, 2501.81, -3809.799, 177.8566, 0.08726646, 120, 0, 0), -- Dark Adept (Area: Plaguewood)
(@CGUID+1157, 8529, 0, 1, 1, 2490.624, -3836.744, 179.3745, 0.6728656, 120, 0, 0), -- Scourge Champion (Area: The Fungal Vale)
(@CGUID+1158, 45485, 0, 1, 1, 2413.58, -3809.96, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1159, 45485, 0, 1, 1, 2412.61, -3811.33, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1160, 45485, 0, 1, 1, 2411.42, -3812.36, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1161, 45485, 0, 1, 1, 2409.84, -3812.06, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1162, 45485, 0, 1, 1, 2408.15, -3812.81, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1163, 45485, 0, 1, 1, 2406.82, -3813.49, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1164, 45485, 0, 1, 1, 2405.11, -3812.58, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1165, 45485, 0, 1, 1, 2403.86, -3811.8, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1166, 45485, 0, 1, 1, 2403.23, -3810.63, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1167, 45485, 0, 1, 1, 2401.25, -3806.05, 182.9253, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1168, 45485, 0, 1, 1, 2402.32, -3812.33, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1169, 45485, 0, 1, 1, 2401.83, -3811.06, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1170, 45485, 0, 1, 1, 2400.16, -3806.32, 182.7033, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1171, 45485, 0, 1, 1, 2400.42, -3809.37, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1172, 45485, 0, 1, 1, 2400.64, -3810.77, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1173, 45485, 0, 1, 1, 2399.54, -3807.7, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1174, 45485, 0, 1, 1, 2400.83, -3812.35, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1175, 45485, 0, 1, 1, 2401.09, -3813.48, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1176, 45485, 0, 1, 1, 2398.39, -3806.5, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1177, 45485, 0, 1, 1, 2398.97, -3808.85, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1178, 45485, 0, 1, 1, 2399.15, -3810.1, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1179, 45485, 0, 1, 1, 2399.25, -3811.46, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1180, 45485, 0, 1, 1, 2397.86, -3807.69, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1181, 45485, 0, 1, 1, 2399.64, -3813.35, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1182, 45485, 0, 1, 1, 2396.64, -3805.58, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1183, 45485, 0, 1, 1, 2397.79, -3809.49, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1184, 45485, 0, 1, 1, 2396.67, -3806.85, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1185, 45485, 0, 1, 1, 2397.91, -3810.87, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1186, 45485, 0, 1, 1, 2398.24, -3812.18, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1187, 45485, 0, 1, 1, 2396.32, -3808.22, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1188, 45485, 0, 1, 1, 2395.21, -3804.9, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1189, 45485, 0, 1, 1, 2398.02, -3813.62, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1190, 45485, 0, 1, 1, 2396.27, -3809.52, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1191, 45485, 0, 1, 1, 2394.99, -3806.13, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1192, 45485, 0, 1, 1, 2396.88, -3812.26, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1193, 45485, 0, 1, 1, 2396.46, -3811.08, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1194, 45485, 0, 1, 1, 2395.2, -3808.82, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1195, 45485, 0, 1, 1, 2394.63, -3807.55, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1196, 45485, 0, 1, 1, 2393.3, -3803.9, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1197, 45485, 0, 1, 1, 2393.44, -3806.6, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1198, 45485, 0, 1, 1, 2393.02, -3805.34, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1199, 45485, 0, 1, 1, 2392.05, -3803, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1200, 45485, 0, 1, 1, 2391.85, -3804.4, 182.5553, 0, 120, 0, 0), -- Necropolis Flowers (Area: The Fungal Vale)
(@CGUID+1201, 11288, 0, 1, 1, 2089.72, -3789.77, 133.7653, 5.323254, 120, 0, 0), -- Spectral Betrayer (Area: 0)
(@CGUID+1202, 8596, 0, 1, 1, 2105.824, -3855.151, 137.4518, 0.3739764, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+1203, 8603, 0, 1, 1, 2052.19, -3843.709, 129.8438, 0.6263078, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+1204, 20725, 0, 1, 1, 2043.121, -3831.803, 133.6957, 4.436788, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+1205, 8600, 0, 1, 1, 2006.717, -3822.691, 123.0449, 4.057944, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+1206, 8600, 0, 1, 1, 1885.231, -3818.95, 136.903, 1.189112, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+1207, 32520, 0, 1, 1, -5691.65, 5556.92, -1154.687, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: 0)
(@CGUID+1208, 32520, 0, 1, 1, -6148.39, 5539.97, -1207.787, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: 0)
(@CGUID+1209, 32520, 0, 1, 1, -6014.71, 5479.63, -1208.007, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: 0)
(@CGUID+1210, 32520, 0, 1, 1, -6305.162, 5582.533, -1172.063, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: 0)
(@CGUID+1211, 8600, 0, 1, 1, 1849.109, -3845.188, 133.0738, 2.681228, 120, 0, 0), -- Plaguebat (Area: Crown Guard Tower)
(@CGUID+1212, 11621, 0, 1, 1, 1762.91, -3874.32, 128.0143, 1.099557, 120, 0, 0), -- Spectral Corpse (Area: Crown Guard Tower)
(@CGUID+1213, 8600, 0, 1, 1, 1779.066, -3835.951, 125.8909, 1.351386, 120, 0, 0), -- Plaguebat (Area: Crown Guard Tower)
(@CGUID+1214, 8600, 0, 1, 1, 1739.522, -3864.432, 124.5949, 0.1792157, 120, 0, 0), -- Plaguebat (Area: Crown Guard Tower)
(@CGUID+1215, 8600, 0, 1, 1, 1624.726, -3822.574, 131.2748, 3.022881, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+1216, 8600, 0, 1, 1, 1655.331, -3850.432, 131.8198, 3.660739, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+1217, 10779, 0, 1, 1, 1519.752, -3815.229, 107.3551, 2.583408, 120, 0, 0), -- Infected Squirrel (Area: Darrowshire)
(@CGUID+1218, 8600, 0, 1, 1, 1582.677, -3846.491, 128.994, 5.647497, 120, 0, 0), -- Plaguebat (Area: Darrowshire)
(@CGUID+1219, 46016, 0, 1, 1, 1501.2, -3808.05, 103.0923, 0, 120, 0, 0), -- Spectral Critter (Area: Darrowshire) (possible waypoints or random movement)
(@CGUID+1220, 46016, 0, 1, 1, 1476.32, -3809.6, 104.8013, 0, 120, 0, 0), -- Spectral Critter (Area: Darrowshire) (possible waypoints or random movement)
(@CGUID+1221, 46016, 0, 1, 1, 1427.046, -3820.871, 126.7237, 3.926991, 120, 0, 0), -- Spectral Critter (Area: Darrowshire Hunting Grounds) (possible waypoints or random movement)
(@CGUID+1222, 46016, 0, 1, 1, 1422.503, -3843.932, 136.4058, 0.6147546, 120, 0, 0), -- Spectral Critter (Area: Darrowshire Hunting Grounds) (possible waypoints or random movement)
(@CGUID+1223, 46016, 0, 1, 1, 1388.202, -3805.384, 124.3248, 4.33007, 120, 0, 0), -- Spectral Critter (Area: Darrowshire Hunting Grounds)
(@CGUID+1224, 46016, 0, 1, 1, 1454.13, -3825.87, 116.7983, 0, 120, 0, 0), -- Spectral Critter (Area: Darrowshire Hunting Grounds) (possible waypoints or random movement)
(@CGUID+1225, 46016, 0, 1, 1, 1446.72, -3748.71, 87.07243, 1.391465, 120, 0, 0), -- Spectral Critter (Area: Darrowshire Hunting Grounds) (possible waypoints or random movement)
(@CGUID+1226, 46016, 0, 1, 1, 1445.381, -3762.466, 95.80302, 5.964715, 120, 0, 0), -- Spectral Critter (Area: Darrowshire Hunting Grounds) (possible waypoints or random movement)
(@CGUID+1227, 46016, 0, 1, 1, 1452.365, -3778.816, 104.4534, 1.360005, 120, 0, 0), -- Spectral Critter (Area: Darrowshire Hunting Grounds) (possible waypoints or random movement)
(@CGUID+1228, 46016, 0, 1, 1, 1388.935, -3829.496, 134.7381, 5.380114, 120, 0, 0), -- Spectral Critter (Area: Darrowshire Hunting Grounds) (possible waypoints or random movement)
(@CGUID+1229, 45450, 0, 1, 1, 1451.53, -3911.31, 137.3653, 1.762783, 120, 0, 0), -- The Lone Hunter (Area: Darrowshire Hunting Grounds)
(@CGUID+1230, 46016, 0, 1, 1, 1457.553, -3895.09, 132.3778, 0.9211512, 120, 0, 0), -- Spectral Critter (Area: Darrowshire Hunting Grounds) (possible waypoints or random movement)
(@CGUID+1231, 46016, 0, 1, 1, 1422.52, -3883.208, 139.6242, 2.579059, 120, 0, 0), -- Spectral Critter (Area: Darrowshire Hunting Grounds) (possible waypoints or random movement)
(@CGUID+1232, 46016, 0, 1, 1, 1478.117, -3875.506, 128.9945, 1.906559, 120, 0, 0), -- Spectral Critter (Area: Darrowshire Hunting Grounds) (possible waypoints or random movement)
(@CGUID+1233, 46016, 0, 1, 1, 1468.093, -3877.583, 124.373, 5.573077, 120, 0, 0), -- Spectral Critter (Area: Darrowshire Hunting Grounds) (possible waypoints or random movement)
(@CGUID+1234, 46016, 0, 1, 1, 1459.958, -3856.735, 118.1401, 0.9582678, 120, 0, 0), -- Spectral Critter (Area: Darrowshire Hunting Grounds) (possible waypoints or random movement)
(@CGUID+1235, 46016, 0, 1, 1, 1463.927, -3915.099, 139.2435, 1.74146, 120, 0, 0), -- Spectral Critter (Area: Darrowshire Hunting Grounds) (possible waypoints or random movement)
(@CGUID+1236, 46016, 0, 1, 1, 1524.959, -3903.467, 150.1999, 3.022202, 120, 0, 0), -- Spectral Critter (Area: Darrowshire Hunting Grounds) (possible waypoints or random movement)
(@CGUID+1237, 46016, 0, 1, 1, 1504.478, -3921.211, 149.9604, 0.2761275, 120, 0, 0), -- Spectral Critter (Area: Darrowshire Hunting Grounds) (possible waypoints or random movement)
(@CGUID+1238, 8596, 0, 1, 1, 1558.364, -3940.405, 170.1246, 0.8538034, 120, 0, 0), -- Plaguehound Runt (Area: Darrowshire Hunting Grounds)
(@CGUID+1239, 8600, 0, 1, 1, 1679.098, -3895.769, 131.017, 3.894935, 120, 0, 0), -- Plaguebat (Area: Darrowshire Hunting Grounds)
(@CGUID+1240, 10779, 0, 1, 1, 1619.687, -3850.319, 128.5551, 5.002557, 120, 0, 0), -- Infected Squirrel (Area: Darrowshire Hunting Grounds)
(@CGUID+1241, 46016, 0, 1, 1, 1523.64, -3906.56, 151.0673, 0, 120, 0, 0), -- Spectral Critter (Area: Darrowshire Hunting Grounds) (possible waypoints or random movement)
(@CGUID+1242, 46016, 0, 1, 1, 1503.13, -3809.002, 103.2864, 5.825119, 120, 0, 0), -- Spectral Critter (Area: Darrowshire Hunting Grounds) (possible waypoints or random movement)
(@CGUID+1243, 10779, 0, 1, 1, 1710.876, -3908.954, 129.97, 5.196157, 120, 0, 0), -- Infected Squirrel (Area: 0)
(@CGUID+1244, 8600, 0, 1, 1, 1684.906, -3947.645, 135.9261, 0.9936892, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+1245, 8600, 0, 1, 1, 1714.76, -3916.608, 129.24, 3.352588, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+1246, 10779, 0, 1, 1, 1723.627, -3970.31, 133.4124, 3.921466, 120, 0, 0), -- Infected Squirrel (Area: 0)
(@CGUID+1247, 11621, 0, 1, 1, 1765.33, -3893.12, 130.1613, 5.323254, 120, 0, 0), -- Spectral Corpse (Area: 0)
(@CGUID+1248, 11621, 0, 1, 1, 1765.32, -3891.06, 130.0453, 1.867502, 120, 0, 0), -- Spectral Corpse (Area: 0)
(@CGUID+1249, 11621, 0, 1, 1, 1762.12, -3899.26, 130.6893, 1.815142, 120, 0, 0), -- Spectral Corpse (Area: 0)
(@CGUID+1250, 11621, 0, 1, 1, 1765.32, -3875.81, 128.5003, 6.178465, 120, 0, 0), -- Spectral Corpse (Area: 0)
(@CGUID+1251, 11620, 0, 1, 1, 1758.584, -3884.883, 129.3542, 4.39558, 120, 0, 0), -- Spectral Marauder (Area: 0) (possible waypoints or random movement)
(@CGUID+1252, 11620, 0, 1, 1, 1761.612, -3879.788, 128.7001, 6.121387, 120, 0, 0), -- Spectral Marauder (Area: 0) (possible waypoints or random movement)
(@CGUID+1253, 11621, 0, 1, 1, 1765.98, -3879.26, 129.0273, 1.064651, 120, 0, 0), -- Spectral Corpse (Area: 0)
(@CGUID+1254, 11620, 0, 1, 1, 1762.934, -3894.433, 130.2516, 2.462221, 120, 0, 0), -- Spectral Marauder (Area: 0) (possible waypoints or random movement)
(@CGUID+1255, 11620, 0, 1, 1, 1768.992, -3890.535, 130.2561, 6.246543, 120, 0, 0), -- Spectral Marauder (Area: 0) (possible waypoints or random movement)
(@CGUID+1256, 8600, 0, 1, 1, 1817.885, -3883.882, 134.1974, 3.804435, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+1257, 8600, 0, 1, 1, 1757.834, -3953.323, 129.7982, 3.037054, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+1258, 8600, 0, 1, 1, 1817.609, -3946.324, 128.1123, 0.4531585, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+1259, 10780, 0, 1, 1, 1745.636, -3969.604, 128.8726, 0.03908078, 120, 0, 0), -- Infected Deer (Area: 0)
(@CGUID+1260, 8600, 0, 1, 1, 1864.434, -3939.774, 122.7851, 5.303913, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+1261, 8600, 0, 1, 1, 1852.889, -3910.424, 132.0835, 0.6249277, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+1262, 8603, 0, 1, 1, 1935.971, -3895.096, 128.8626, 3.278792, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+1263, 8600, 0, 1, 1, 1882.637, -3880.982, 136.0695, 2.868313, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+1264, 10779, 0, 1, 1, 1875.806, -3896.115, 133.3164, 2.006479, 120, 0, 0), -- Infected Squirrel (Area: 0)
(@CGUID+1265, 10780, 0, 1, 1, 1892.431, -3902.434, 134.218, 5.457034, 120, 0, 0), -- Infected Deer (Area: 0)
(@CGUID+1266, 8534, 0, 1, 1, 1904.175, -3904.755, 134.159, 1.687037, 120, 0, 0), -- Putrid Gargoyle (Area: 0)
(@CGUID+1267, 8534, 0, 1, 1, 1890.483, -3867.069, 133.6208, 1.030723, 120, 0, 0), -- Putrid Gargoyle (Area: 0)
(@CGUID+1268, 8596, 0, 1, 1, 1970.038, -3961.997, 129.5489, 5.888112, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+1269, 8596, 0, 1, 1, 2009.316, -3881.472, 121.6387, 0.5645128, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+1270, 8601, 0, 1, 1, 2120.251, -3920.498, 134.8996, 2.902608, 120, 0, 0), -- Noxious Plaguebat (Area: 0)
(@CGUID+1271, 2110, 0, 1, 1, 2087.491, -3965.284, 134.806, 6.244105, 120, 0, 0), -- Black Rat (Area: 0)
(@CGUID+1272, 8601, 0, 1, 1, 2047.881, -3924.325, 125.8116, 3.900045, 120, 0, 0), -- Noxious Plaguebat (Area: 0)
(@CGUID+1273, 8596, 0, 1, 1, 2067.466, -3885.385, 132.2937, 5.444624, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+1274, 8601, 0, 1, 1, 2153.485, -3970.25, 130.5336, 4.866138, 120, 0, 0), -- Noxious Plaguebat (Area: 0)
(@CGUID+1275, 8602, 0, 1, 1, 2689.959, -3875.476, 120.7333, 1.157048, 120, 0, 0), -- Monstrous Plaguebat (Area: The Fungal Vale)
(@CGUID+1276, 8598, 0, 1, 1, 2756.533, -3943.028, 96.50775, 1.303626, 120, 0, 0), -- Frenzied Plaguehound (Area: Plaguewood)
(@CGUID+1277, 8602, 0, 1, 1, 2762.391, -3879.049, 98.99754, 2.355248, 120, 0, 0), -- Monstrous Plaguebat (Area: Plaguewood)
(@CGUID+1278, 8598, 0, 1, 1, 2743.18, -3944.193, 96.18585, 3.080194, 120, 0, 0), -- Frenzied Plaguehound (Area: Plaguewood)
(@CGUID+1279, 8602, 0, 1, 1, 2750.854, -3878.688, 97.45689, 3.166978, 120, 0, 0), -- Monstrous Plaguebat (Area: Plaguewood)
(@CGUID+1280, 8605, 0, 1, 1, 2784.26, -3916.726, 99.93935, 3.476123, 120, 0, 0), -- Carrion Devourer (Area: Plaguewood)
(@CGUID+1281, 8535, 0, 1, 1, 2799.167, -3839.74, 102.6856, 1.745405, 120, 0, 0), -- Putrid Shrieker (Area: Plaguewood)
(@CGUID+1282, 8598, 0, 1, 1, 2842.719, -3925.909, 103.9429, 2.438475, 120, 0, 0), -- Frenzied Plaguehound (Area: Plaguewood)
(@CGUID+1283, 8530, 0, 1, 1, 2877.944, -3887.805, 110.8964, 1.025856, 120, 0, 0), -- Cannibal Ghoul (Area: Plaguewood)
(@CGUID+1284, 8598, 0, 1, 1, 2804.38, -3956.026, 103.574, 4.620129, 120, 0, 0), -- Frenzied Plaguehound (Area: Plaguewood)
(@CGUID+1285, 8523, 0, 1, 1, 2911.659, -3904.143, 115.812, 5.250298, 120, 0, 0), -- Scourge Soldier (Area: Plaguewood)
(@CGUID+1286, 8524, 0, 1, 1, 2951.906, -3890.259, 122.0514, 2.105192, 120, 0, 0), -- Cursed Mage (Area: Plaguewood)
(@CGUID+1287, 8524, 0, 1, 1, 2942.655, -3948.648, 107.4096, 0.452731, 120, 0, 0), -- Cursed Mage (Area: Plaguewood)
(@CGUID+1288, 8523, 0, 1, 1, 3056.769, -3920.773, 114.5736, 0.02343321, 120, 0, 0), -- Scourge Soldier (Area: Plaguewood)
(@CGUID+1289, 8553, 0, 1, 1, 3135.96, -3867.93, 135.4473, 3.333579, 120, 0, 0), -- Necromancer (Area: Plaguewood)
(@CGUID+1290, 45851, 0, 1, 1, 3082.971, -3949.336, 115.4046, 2.138498, 120, 0, 0), -- Overstuffed Golem (Area: Plaguewood)
(@CGUID+1291, 8524, 0, 1, 1, 3113.457, -3914.443, 129.5648, 3.104464, 120, 0, 0), -- Cursed Mage (Area: Plaguewood)
(@CGUID+1292, 8534, 0, 1, 1, 3089.25, -3838.86, 126.193, 6.032016, 120, 0, 0), -- Putrid Gargoyle (Area: Plaguewood)
(@CGUID+1293, 45851, 0, 1, 1, 3166.245, -3940.03, 118.614, 3.294539, 120, 0, 0), -- Overstuffed Golem (Area: Plaguewood)
(@CGUID+1294, 8530, 0, 1, 1, 3187.144, -3929.239, 129.6067, 4.86801, 120, 0, 0), -- Cannibal Ghoul (Area: Plaguewood)
(@CGUID+1295, 8524, 0, 1, 1, 3211.025, -3876.561, 136.3564, 0.880808, 120, 0, 0), -- Cursed Mage (Area: Plaguewood)
(@CGUID+1296, 8598, 0, 1, 1, 3170.212, -4004.727, 109.6406, 4.246431, 120, 0, 0), -- Frenzied Plaguehound (Area: Plaguewood)
(@CGUID+1297, 10779, 0, 1, 1, 3025.71, -4039.179, 104.515, 1.33178, 120, 0, 0), -- Infected Squirrel (Area: Plaguewood)
(@CGUID+1298, 8602, 0, 1, 1, 3043.597, -4029.641, 104.4014, 3.025029, 120, 0, 0), -- Monstrous Plaguebat (Area: Plaguewood)
(@CGUID+1299, 8602, 0, 1, 1, 2859.428, -4019.18, 102.7161, 1.41079, 120, 0, 0), -- Monstrous Plaguebat (Area: Plaguewood)
(@CGUID+1300, 8598, 0, 1, 1, 2828.804, -3988.969, 101.9525, 3.5782, 120, 0, 0), -- Frenzied Plaguehound (Area: Plaguewood)
(@CGUID+1301, 11897, 0, 1, 1, 2808.731, -4062.556, 158.8493, 3.058988, 120, 0, 0), -- Duskwing (Area: Plaguewood)
(@CGUID+1302, 10780, 0, 1, 1, 2791.855, -4007.52, 99.53413, 3.648007, 120, 0, 0), -- Infected Deer (Area: Plaguewood)
(@CGUID+1303, 8598, 0, 1, 1, 2815.714, -4019.084, 103.4214, 5.96467, 120, 0, 0), -- Frenzied Plaguehound (Area: Plaguewood)
(@CGUID+1304, 10779, 0, 1, 1, 2809.214, -4024.343, 101.5937, 0.4839098, 120, 0, 0), -- Infected Squirrel (Area: Plaguewood)
(@CGUID+1305, 8602, 0, 1, 1, 2791.105, -3990.769, 99.90837, 2.78648, 120, 0, 0), -- Monstrous Plaguebat (Area: Plaguewood)
(@CGUID+1306, 16229, 0, 1, 1, 2672.346, -4001.941, 99.69519, 1.745329, 120, 0, 0), -- Injured Argent Dawn Infantry (Area: 0)
(@CGUID+1307, 16228, 0, 1, 1, 2705.146, -4004.695, 92.19432, 1.029744, 120, 0, 0), -- Argent Dawn Infantry (Area: 0)
(@CGUID+1308, 16228, 0, 1, 1, 2708.283, -4004.201, 92.2141, 2.792527, 120, 0, 0), -- Argent Dawn Infantry (Area: 0)
(@CGUID+1309, 16228, 0, 1, 1, 2691.613, -4029.122, 93.02745, 3.036873, 120, 0, 0), -- Argent Dawn Infantry (Area: 0)
(@CGUID+1310, 16228, 0, 1, 1, 2687.017, -4025.649, 92.90928, 4.921828, 120, 0, 0), -- Argent Dawn Infantry (Area: 0)
(@CGUID+1311, 16228, 0, 1, 1, 2756.954, -4028.96, 96.41188, 4.78759, 120, 0, 0), -- Argent Dawn Infantry (Area: 0)
(@CGUID+1312, 16228, 0, 1, 1, 2753.963, -4029.186, 96.20021, 4.787576, 120, 0, 0), -- Argent Dawn Infantry (Area: 0)
(@CGUID+1313, 2110, 0, 1, 1, 2684.577, -4011.663, 95.11019, 2.675762, 120, 0, 0), -- Black Rat (Area: 0)
(@CGUID+1314, 16229, 0, 1, 1, 2680.15, -3995.327, 99.69519, 5.497787, 120, 0, 0), -- Injured Argent Dawn Infantry (Area: 0)
(@CGUID+1315, 16229, 0, 1, 1, 2676.313, -3997.964, 99.68826, 5.654867, 120, 0, 0), -- Injured Argent Dawn Infantry (Area: 0)
(@CGUID+1316, 16284, 0, 1, 1, 2678.156, -3999.291, 99.72637, 2.775074, 120, 0, 0), -- Argent Medic (Area: 0)
(@CGUID+1317, 8603, 0, 1, 1, 2205.414, -4019.179, 100.8039, 0.9291056, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+1318, 20725, 0, 1, 1, 2114.659, -4010.536, 132.084, 5.671406, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+1319, 8597, 0, 1, 1, 2153.149, -4011.572, 116.1874, 1.072228, 120, 0, 0), -- Plaguehound (Area: 0)
(@CGUID+1320, 8597, 0, 1, 1, 2117.016, -3982.654, 132.863, 5.730362, 120, 0, 0), -- Plaguehound (Area: 0)
(@CGUID+1321, 8603, 0, 1, 1, 2078.913, -4019.7, 128.7791, 1.560055, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+1322, 8596, 0, 1, 1, 1982.711, -4027.225, 96.95773, 4.976327, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+1323, 8600, 0, 1, 1, 1989.452, -3973.404, 121.2072, 4.585128, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+1324, 8600, 0, 1, 1, 1897.799, -4011.275, 112.0048, 6.281999, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+1325, 8600, 0, 1, 1, 1752.719, -4010.959, 126.8677, 4.724107, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+1326, 8600, 0, 1, 1, 1719.056, -3979.133, 134.6853, 1.079029, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+1327, 8600, 0, 1, 1, 1787.096, -3996.638, 124.2679, 0.8267248, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+1328, 8600, 0, 1, 1, 1611.126, -4027.836, 143.3982, 1.816248, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+1329, 8600, 0, 1, 1, 1730.78, -4112.795, 100.3835, 0.7318264, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+1330, 8600, 0, 1, 1, 1790.406, -4050.163, 115.0051, 3.69005, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+1331, 20725, 0, 1, 1, 1768.174, -4091.802, 103.7983, 5.009063, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+1332, 8600, 0, 1, 1, 1778.184, -4108.308, 100.2502, 0.03009469, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+1333, 8600, 0, 1, 1, 1827.37, -4078.56, 104.3821, 1.707028, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+1334, 20725, 0, 1, 1, 1810.848, -4120.422, 99.40189, 2.390711, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+1335, 8600, 0, 1, 1, 1852.669, -4043.026, 113.546, 6.046667, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+1336, 8600, 0, 1, 1, 1875.106, -4092.57, 91.95105, 0.7336132, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+1337, 20725, 0, 1, 1, 1974.818, -4054.726, 90.75065, 4.646795, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+1338, 20725, 0, 1, 1, 1990.727, -4088.257, 84.04037, 3.844166, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+1339, 20725, 0, 1, 1, 2019.871, -4062.242, 89.02782, 6.202726, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+1340, 8601, 0, 1, 1, 2055.03, -4046.403, 99.96664, 2.204766, 120, 0, 0), -- Noxious Plaguebat (Area: 0)
(@CGUID+1341, 8603, 0, 1, 1, 2088.634, -4083.177, 91.64739, 2.097642, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+1342, 10780, 0, 1, 1, 2213.365, -4078.337, 81.7834, 0.7860892, 120, 0, 0), -- Infected Deer (Area: 0)
(@CGUID+1343, 8597, 0, 1, 1, 2182.857, -4038.621, 103.0974, 4.310833, 120, 0, 0), -- Plaguehound (Area: 0)
(@CGUID+1344, 8601, 0, 1, 1, 2210.084, -4083.787, 81.43763, 2.465171, 120, 0, 0), -- Noxious Plaguebat (Area: 0)
(@CGUID+1345, 8534, 0, 1, 1, 2179.222, -4089.203, 81.62473, 2.981863, 120, 0, 0), -- Putrid Gargoyle (Area: 0)
(@CGUID+1346, 10779, 0, 1, 1, 2249.91, -4084.32, 77.49667, 0.3751298, 120, 0, 0), -- Infected Squirrel (Area: 0)
(@CGUID+1347, 8603, 0, 1, 1, 2263.695, -4047.061, 82.77138, 0.5012173, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+1348, 8601, 0, 1, 1, 2284.006, -4083.059, 77.06691, 2.372767, 120, 0, 0), -- Noxious Plaguebat (Area: 0)
(@CGUID+1349, 8597, 0, 1, 1, 2356.794, -4080.229, 78.80246, 6.218696, 120, 0, 0), -- Plaguehound (Area: 0)
(@CGUID+1350, 20725, 0, 1, 1, 2350.605, -4094.847, 75.74945, 2.553252, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+1351, 2110, 0, 1, 1, 2674.141, -4074.324, 87.6712, 5.506759, 120, 0, 0), -- Black Rat (Area: Blackwood Lake)
(@CGUID+1352, 20725, 0, 1, 1, 2754.643, -4077.498, 97.3845, 4.232495, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+1353, 8602, 0, 1, 1, 2884.147, -4051.764, 101.6008, 4.191063, 120, 0, 0), -- Monstrous Plaguebat (Area: 0)
(@CGUID+1354, 8598, 0, 1, 1, 2847.073, -4051.873, 102.1987, 0.5167051, 120, 0, 0), -- Frenzied Plaguehound (Area: 0)
(@CGUID+1355, 8605, 0, 1, 1, 2801.838, -4073.633, 101.0398, 6.097803, 120, 0, 0), -- Carrion Devourer (Area: 0)
(@CGUID+1356, 41178, 0, 1, 1, 3175.531, -4373.844, 189.6369, 0.08726646, 120, 0, 0), -- Northwatch Tower Stalker (Area: 0)
(@CGUID+1357, 10780, 0, 1, 1, 3056.943, -4041.331, 101.2448, 0.8151466, 120, 0, 0), -- Infected Deer (Area: Plaguewood)
(@CGUID+1358, 10779, 0, 1, 1, 3103.208, -4061.694, 103.7088, 0.6405714, 120, 0, 0), -- Infected Squirrel (Area: Plaguewood)
(@CGUID+1359, 8605, 0, 1, 1, 3073.217, -4077.405, 101.7071, 3.77796, 120, 0, 0), -- Carrion Devourer (Area: Plaguewood)
(@CGUID+1360, 8598, 0, 1, 1, 3153.883, -4053.96, 103.3202, 3.104478, 120, 0, 0), -- Frenzied Plaguehound (Area: Plaguewood)
(@CGUID+1361, 8602, 0, 1, 1, 3153.101, -4112.465, 97.31537, 4.211726, 120, 0, 0), -- Monstrous Plaguebat (Area: Eastwall Gate)
(@CGUID+1362, 8602, 0, 1, 1, 3117.244, -4108.069, 97.5864, 5.180404, 120, 0, 0), -- Monstrous Plaguebat (Area: Eastwall Gate)
(@CGUID+1363, 8598, 0, 1, 1, 3005.333, -4095.834, 97.02495, 0, 120, 0, 0), -- Frenzied Plaguehound (Area: 0)
(@CGUID+1364, 10780, 0, 1, 1, 2973.981, -4141.885, 95.08261, 4.681149, 120, 0, 0), -- Infected Deer (Area: 0)
(@CGUID+1365, 8598, 0, 1, 1, 2980.249, -4117.551, 97.31866, 6.030975, 120, 0, 0), -- Frenzied Plaguehound (Area: 0)
(@CGUID+1366, 10780, 0, 1, 1, 2977.713, -4122.07, 96.07468, 2.941708, 120, 0, 0), -- Infected Deer (Area: 0)
(@CGUID+1367, 8598, 0, 1, 1, 2724.655, -4139.485, 92.8783, 1.680375, 120, 0, 0), -- Frenzied Plaguehound (Area: 0)
(@CGUID+1368, 8602, 0, 1, 1, 2693.002, -4116.013, 87.0285, 1.066926, 120, 0, 0), -- Monstrous Plaguebat (Area: 0)
(@CGUID+1369, 8598, 0, 1, 1, 2741.85, -4119.75, 94.225, 1.542485, 120, 0, 0), -- Frenzied Plaguehound (Area: 0)
(@CGUID+1370, 8598, 0, 1, 1, 2682.991, -4109.814, 89.09344, 5.709267, 120, 0, 0), -- Frenzied Plaguehound (Area: 0)
(@CGUID+1371, 2110, 0, 1, 1, 2693.879, -4110.898, 86.27578, 6.248912, 120, 0, 0), -- Black Rat (Area: 0)
(@CGUID+1372, 2110, 0, 1, 1, 2691.927, -4125.586, 84.37469, 2.897166, 120, 0, 0), -- Black Rat (Area: 0)
(@CGUID+1373, 8535, 0, 1, 1, 2766.513, -4130.217, 93.8063, 1.169369, 120, 0, 0), -- Putrid Shrieker (Area: 0)
(@CGUID+1374, 8598, 0, 1, 1, 2675.552, -4142.426, 88.33535, 0.9151955, 120, 0, 0), -- Frenzied Plaguehound (Area: Blackwood Lake)
(@CGUID+1375, 8605, 0, 1, 1, 2648.099, -4124.177, 84.81116, 0.151643, 120, 0, 0), -- Carrion Devourer (Area: Blackwood Lake)
(@CGUID+1376, 20725, 0, 1, 1, 2620.337, -4124.204, 83.2155, 2.226502, 120, 0, 0), -- Bat (Area: Blackwood Lake)
(@CGUID+1377, 8522, 0, 1, 1, 2562.948, -4139.462, 64.96819, 5.15789, 120, 0, 0), -- Plague Monstrosity (Area: Blackwood Lake) (possible waypoints or random movement)
(@CGUID+1378, 8521, 0, 1, 1, 2473.061, -4115.51, 70.92343, 3.120102, 120, 0, 0), -- Blighted Horror (Area: Blackwood Lake) (possible waypoints or random movement)
(@CGUID+1379, 8522, 0, 1, 1, 2454.392, -4145.713, 51.63271, 4.27828, 120, 0, 0), -- Plague Monstrosity (Area: Blackwood Lake) (possible waypoints or random movement)
(@CGUID+1380, 8597, 0, 1, 1, 2376.075, -4125.723, 75.32795, 0.4291333, 120, 0, 0), -- Plaguehound (Area: Blackwood Lake)
(@CGUID+1381, 8601, 0, 1, 1, 2242.966, -4114.598, 80.60607, 0.4138636, 120, 0, 0), -- Noxious Plaguebat (Area: 0)
(@CGUID+1382, 8597, 0, 1, 1, 2188.137, -4095.933, 79.20776, 3.919482, 120, 0, 0), -- Plaguehound (Area: 0)
(@CGUID+1383, 10779, 0, 1, 1, 2196.563, -4120.892, 75.98817, 1.473616, 120, 0, 0), -- Infected Squirrel (Area: 0)
(@CGUID+1384, 8601, 0, 1, 1, 2120.432, -4117.068, 81.84698, 2.53863, 120, 0, 0), -- Noxious Plaguebat (Area: 0)
(@CGUID+1385, 45657, 0, 1, 1, 2037.796, -4142.424, 20.32517, 0.9018744, 120, 0, 0), -- Infectis Scuttler (Area: 0) (possible waypoints or random movement)
(@CGUID+1386, 45657, 0, 1, 1, 2029.548, -4139.341, 29.64891, 5.645163, 120, 0, 0), -- Infectis Scuttler (Area: 0) (possible waypoints or random movement)
(@CGUID+1387, 45650, 0, 1, 1, 2018.925, -4138.789, 16.60558, 4.158297, 120, 0, 0), -- Plague Puffer (Area: 0) (possible waypoints or random movement)
(@CGUID+1388, 45650, 0, 1, 1, 2015.394, -4111.94, 33.91229, 0.07468478, 120, 0, 0), -- Plague Puffer (Area: 0) (possible waypoints or random movement)
(@CGUID+1389, 45650, 0, 1, 1, 2023.581, -4121.428, 27.12725, 5.261709, 120, 0, 0), -- Plague Puffer (Area: 0) (possible waypoints or random movement)
(@CGUID+1390, 45655, 0, 1, 1, 2015.163, -4118.058, 25.22967, 2.086814, 120, 0, 0), -- Infectis Incher (Area: 0) (possible waypoints or random movement)
(@CGUID+1391, 45655, 0, 1, 1, 2016.204, -4129.177, 18.20672, 3.120477, 120, 0, 0), -- Infectis Incher (Area: 0) (possible waypoints or random movement)
(@CGUID+1392, 45657, 0, 1, 1, 2020.665, -4125.836, 20.4682, 5.526918, 120, 0, 0), -- Infectis Scuttler (Area: 0) (possible waypoints or random movement)
(@CGUID+1393, 45655, 0, 1, 1, 2012.277, -4123.611, 21.77214, 0.5914879, 120, 0, 0), -- Infectis Incher (Area: 0) (possible waypoints or random movement)
(@CGUID+1394, 45657, 0, 1, 1, 2010.649, -4127.958, 19.53729, 2.422916, 120, 0, 0), -- Infectis Scuttler (Area: 0) (possible waypoints or random movement)
(@CGUID+1395, 10779, 0, 1, 1, 1744.732, -3971.649, 128.4679, 5.536652, 120, 0, 0), -- Infected Squirrel (Area: 0)
(@CGUID+1396, 32520, 0, 1, 1, -6014.71, 5479.63, -1208.007, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: 0)
(@CGUID+1397, 32520, 0, 1, 1, -5691.65, 5556.92, -1154.687, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: 0)
(@CGUID+1398, 32520, 0, 1, 1, -6148.39, 5539.97, -1207.787, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: 0)
(@CGUID+1399, 32520, 0, 1, 1, -6305.162, 5582.533, -1172.063, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: 0)
(@CGUID+1400, 8600, 0, 1, 1, 1756.083, -4214.68, 83.12054, 1.453231, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+1401, 8600, 0, 1, 1, 1747.79, -4154.493, 91.82585, 5.711965, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+1402, 20725, 0, 1, 1, 1795.277, -4232.09, 92.28598, 4.833836, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+1403, 8600, 0, 1, 1, 1812.768, -4202.332, 92.41058, 6.034656, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+1404, 8600, 0, 1, 1, 1798.548, -4188.217, 87.0835, 5.683263, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+1405, 8600, 0, 1, 1, 1794.711, -4242.405, 88.50768, 5.801455, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+1406, 8600, 0, 1, 1, 1819.746, -4152.762, 94.34739, 1.584467, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+1407, 20725, 0, 1, 1, 1797.758, -4235.473, 89.6282, 3.761281, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+1408, 8600, 0, 1, 1, 1863.963, -4190.812, 97.71738, 3.075154, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+1409, 8534, 0, 1, 1, 1801.109, -4147.227, 92.34336, 1.235851, 120, 0, 0), -- Putrid Gargoyle (Area: 0)
(@CGUID+1410, 45664, 0, 1, 1, 1982.459, -4177.249, 15.3409, 1.472266, 120, 0, 0), -- Landlocked Grouper (Area: 0)
(@CGUID+1411, 8600, 0, 1, 1, 1893.729, -4183.216, 99.91496, 1.241318, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+1412, 45657, 0, 1, 1, 1969.999, -4155.398, 25.24965, 4.579395, 120, 0, 0), -- Infectis Scuttler (Area: 0) (possible waypoints or random movement)
(@CGUID+1413, 45655, 0, 1, 1, 1977.49, -4159.089, 24.71498, 2.788807, 120, 0, 0), -- Infectis Incher (Area: 0) (possible waypoints or random movement)
(@CGUID+1414, 45657, 0, 1, 1, 1972.92, -4160.248, 21.33998, 3.459635, 120, 0, 0), -- Infectis Scuttler (Area: 0) (possible waypoints or random movement)
(@CGUID+1415, 45650, 0, 1, 1, 1996.01, -4176.292, 13.71078, 4.39731, 120, 0, 0), -- Plague Puffer (Area: 0) (possible waypoints or random movement)
(@CGUID+1416, 45650, 0, 1, 1, 1963.503, -4172.561, 21.40478, 5.785469, 120, 0, 0), -- Plague Puffer (Area: 0) (possible waypoints or random movement)
(@CGUID+1417, 45650, 0, 1, 1, 1968.845, -4158.759, 21.81105, 1.941193, 120, 0, 0), -- Plague Puffer (Area: 0) (possible waypoints or random movement)
(@CGUID+1418, 45657, 0, 1, 1, 1976.729, -4162.634, 19.4081, 2.220807, 120, 0, 0), -- Infectis Scuttler (Area: 0) (possible waypoints or random movement)
(@CGUID+1419, 45655, 0, 1, 1, 1987.028, -4163.705, 19.43373, 0.5812963, 120, 0, 0), -- Infectis Incher (Area: 0) (possible waypoints or random movement)
(@CGUID+1420, 2110, 0, 1, 1, 1890.194, -4239.54, 87.18604, 4.574222, 120, 0, 0), -- Black Rat (Area: 0)
(@CGUID+1421, 45655, 0, 1, 1, 1962.1, -4173.462, 20.66809, 1.757743, 120, 0, 0), -- Infectis Incher (Area: 0) (possible waypoints or random movement)
(@CGUID+1422, 45650, 0, 1, 1, 1982.851, -4173.276, 15.06845, 5.006965, 120, 0, 0), -- Plague Puffer (Area: 0) (possible waypoints or random movement)
(@CGUID+1423, 45664, 0, 1, 1, 2011.551, -4146.943, 16.64547, 2.67369, 120, 0, 0), -- Landlocked Grouper (Area: The Infectis Scar)
(@CGUID+1424, 45655, 0, 1, 1, 2003.3, -4161.07, 15.71605, 0.6623475, 120, 0, 0), -- Infectis Incher (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1425, 45655, 0, 1, 1, 2007.292, -4144.791, 15.58641, 3.844512, 120, 0, 0), -- Infectis Incher (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1426, 45657, 0, 1, 1, 2007.908, -4156.229, 15.2951, 0.1938902, 120, 0, 0), -- Infectis Scuttler (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1427, 45650, 0, 1, 1, 2008.672, -4161.111, 15.04576, 3.039954, 120, 0, 0), -- Plague Puffer (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1428, 45657, 0, 1, 1, 2003.484, -4171.463, 14.40189, 5.785638, 120, 0, 0), -- Infectis Scuttler (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1429, 47060, 0, 1, 1, 2004.81, -4245.33, 81.22343, 3.054326, 120, 0, 0), -- Argent Sentry (Area: The Infectis Scar)
(@CGUID+1430, 45655, 0, 1, 1, 2011.037, -4159.229, 14.68187, 4.888848, 120, 0, 0), -- Infectis Incher (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1431, 45650, 0, 1, 1, 1984.422, -4187.739, 13.05356, 1.976918, 120, 0, 0), -- Plague Puffer (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1432, 45657, 0, 1, 1, 2013.184, -4157.551, 14.66595, 6.217111, 120, 0, 0), -- Infectis Scuttler (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1433, 45664, 0, 1, 1, 1992.592, -4206.909, 10.21957, 2.854769, 120, 0, 0), -- Landlocked Grouper (Area: The Infectis Scar)
(@CGUID+1434, 45650, 0, 1, 1, 2013.011, -4165.747, 15.27564, 4.917346, 120, 0, 0), -- Plague Puffer (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1435, 45655, 0, 1, 1, 2008.437, -4173.259, 14.5868, 5.094118, 120, 0, 0), -- Infectis Incher (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1436, 45655, 0, 1, 1, 2017.518, -4175.596, 19.40946, 4.730886, 120, 0, 0), -- Infectis Incher (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1437, 45650, 0, 1, 1, 2015.12, -4177.231, 18.3611, 1.816756, 120, 0, 0), -- Plague Puffer (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1438, 45650, 0, 1, 1, 2006.513, -4177.823, 13.9213, 5.815525, 120, 0, 0), -- Plague Puffer (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1439, 45650, 0, 1, 1, 2013.42, -4175.377, 15.78556, 0.06237626, 120, 0, 0), -- Plague Puffer (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1440, 45655, 0, 1, 1, 2011.05, -4179.688, 14.83658, 2.143917, 120, 0, 0), -- Infectis Incher (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1441, 45657, 0, 1, 1, 2004.962, -4183.22, 13.32926, 2.596115, 120, 0, 0), -- Infectis Scuttler (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1442, 45657, 0, 1, 1, 2008.63, -4185.214, 14.9213, 3.067468, 120, 0, 0), -- Infectis Scuttler (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1443, 45657, 0, 1, 1, 2012.958, -4181.38, 15.5463, 1.816263, 120, 0, 0), -- Infectis Scuttler (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1444, 45657, 0, 1, 1, 2022.333, -4162.495, 16.191, 2.266943, 120, 0, 0), -- Infectis Scuttler (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1445, 45657, 0, 1, 1, 2021.541, -4144.498, 15.05907, 1.990744, 120, 0, 0), -- Infectis Scuttler (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1446, 45650, 0, 1, 1, 2001.181, -4188.021, 12.46866, 2.844474, 120, 0, 0), -- Plague Puffer (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1447, 45655, 0, 1, 1, 2024.567, -4159.004, 16.4236, 3.687926, 120, 0, 0), -- Infectis Incher (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1448, 45655, 0, 1, 1, 2031.752, -4156.377, 20.40368, 5.338938, 120, 0, 0), -- Infectis Incher (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1449, 45650, 0, 1, 1, 2022.917, -4147.916, 14.64891, 1.459707, 120, 0, 0), -- Plague Puffer (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1450, 45655, 0, 1, 1, 1988.151, -4205.599, 9.912855, 2.380741, 120, 0, 0), -- Infectis Incher (Area: The Infectis Scar)
(@CGUID+1451, 47060, 0, 1, 1, 2028.01, -4250.43, 84.60094, 3.054326, 120, 0, 0), -- Argent Sentry (Area: The Infectis Scar)
(@CGUID+1452, 45664, 0, 1, 1, 2057.833, -4193.158, 23.8141, 4.982443, 120, 0, 0), -- Landlocked Grouper (Area: The Infectis Scar)
(@CGUID+1453, 45664, 0, 1, 1, 2047.976, -4229.124, 23.30496, 6.004204, 120, 0, 0), -- Landlocked Grouper (Area: The Infectis Scar)
(@CGUID+1454, 45655, 0, 1, 1, 2059.06, -4197.587, 21.05508, 2.008353, 120, 0, 0), -- Infectis Incher (Area: The Infectis Scar)
(@CGUID+1455, 45650, 0, 1, 1, 2056.475, -4205.932, 21.2897, 4.8096, 120, 0, 0), -- Plague Puffer (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1456, 45664, 0, 1, 1, 2063.997, -4220.295, 20.71263, 2.056962, 120, 0, 0), -- Landlocked Grouper (Area: The Infectis Scar)
(@CGUID+1457, 45655, 0, 1, 1, 2053.851, -4219.134, 20.42822, 5.996659, 120, 0, 0), -- Infectis Incher (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1458, 45650, 0, 1, 1, 2051.853, -4230.234, 23.2778, 3.154157, 120, 0, 0), -- Plague Puffer (Area: The Infectis Scar)
(@CGUID+1459, 45657, 0, 1, 1, 2062.202, -4216.9, 20.42822, 5.944885, 120, 0, 0), -- Infectis Scuttler (Area: The Infectis Scar)
(@CGUID+1460, 45650, 0, 1, 1, 2082.813, -4170.313, 20.57381, 1.854966, 120, 0, 0), -- Plague Puffer (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1461, 45657, 0, 1, 1, 2068.867, -4222.918, 20.95728, 4.072496, 120, 0, 0), -- Infectis Scuttler (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1462, 45657, 0, 1, 1, 2013.03, -4149.75, 16.02253, 1.877229, 120, 0, 0), -- Infectis Scuttler (Area: The Infectis Scar)
(@CGUID+1463, 2110, 0, 1, 1, 2114.68, -4158.493, 75.68629, 4.52449, 120, 0, 0), -- Black Rat (Area: The Infectis Scar)
(@CGUID+1464, 45650, 0, 1, 1, 2070.69, -4202.582, 21.3802, 4.789027, 120, 0, 0), -- Plague Puffer (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1465, 8603, 0, 1, 1, 2175.698, -4178.005, 78.2921, 6.112417, 120, 0, 0), -- Carrion Grub (Area: The Infectis Scar)
(@CGUID+1466, 2110, 0, 1, 1, 2166.79, -4210.021, 74.26165, 6.218696, 120, 0, 0), -- Black Rat (Area: The Infectis Scar)
(@CGUID+1467, 8601, 0, 1, 1, 2154.707, -4149.72, 74.59487, 5.527495, 120, 0, 0), -- Noxious Plaguebat (Area: The Infectis Scar)
(@CGUID+1468, 8597, 0, 1, 1, 2212.958, -4150.287, 88.51102, 4.244375, 120, 0, 0), -- Plaguehound (Area: The Infectis Scar)
(@CGUID+1469, 8597, 0, 1, 1, 2231.25, -4168.75, 105.3953, 2.497672, 120, 0, 0), -- Plaguehound (Area: The Infectis Scar)
(@CGUID+1470, 8597, 0, 1, 1, 2202.17, -4246.117, 74.7142, 6.200689, 120, 0, 0), -- Plaguehound (Area: The Infectis Scar)
(@CGUID+1471, 8601, 0, 1, 1, 2204.348, -4211.735, 79.09817, 0.1076374, 120, 0, 0), -- Noxious Plaguebat (Area: The Infectis Scar)
(@CGUID+1472, 8603, 0, 1, 1, 2284.482, -4156.806, 97.39931, 2.971138, 120, 0, 0), -- Carrion Grub (Area: The Infectis Scar)
(@CGUID+1473, 8601, 0, 1, 1, 2353.028, -4214.66, 96.88811, 4.559566, 120, 0, 0), -- Noxious Plaguebat (Area: 0)
(@CGUID+1474, 10780, 0, 1, 1, 2343.004, -4241.183, 95.79553, 0.4995748, 120, 0, 0), -- Infected Deer (Area: 0)
(@CGUID+1475, 8601, 0, 1, 1, 2312.292, -4251.087, 94.7508, 2.888794, 120, 0, 0), -- Noxious Plaguebat (Area: 0)
(@CGUID+1476, 8603, 0, 1, 1, 2335.879, -4150.518, 92.49094, 0.4313162, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+1477, 8603, 0, 1, 1, 2384.609, -4171.059, 74.17262, 0.3906716, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+1478, 8534, 0, 1, 1, 2375.92, -4190.211, 81.20363, 2.489899, 120, 0, 0), -- Putrid Gargoyle (Area: 0)
(@CGUID+1479, 8522, 0, 1, 1, 2481.25, -4197.916, 72.61203, 4.248742, 120, 0, 0), -- Plague Monstrosity (Area: 0) (possible waypoints or random movement)
(@CGUID+1480, 20725, 0, 1, 1, 2407.162, -4197.032, 76.0114, 6.044382, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+1481, 20725, 0, 1, 1, 2404.363, -4205.806, 84.15385, 4.071703, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+1482, 8521, 0, 1, 1, 2518.334, -4148.666, 45.89182, 5.403197, 120, 0, 0), -- Blighted Horror (Area: Blackwood Lake) (possible waypoints or random movement)
(@CGUID+1483, 8521, 0, 1, 1, 2562.465, -4187.194, 57.52926, 5.909177, 120, 0, 0), -- Blighted Horror (Area: Blackwood Lake) (possible waypoints or random movement)
(@CGUID+1484, 8602, 0, 1, 1, 2639.635, -4190.551, 80.53967, 1.93793, 120, 0, 0), -- Monstrous Plaguebat (Area: Blackwood Lake)
(@CGUID+1485, 8598, 0, 1, 1, 2690.174, -4207.668, 86.55579, 4.274053, 120, 0, 0), -- Frenzied Plaguehound (Area: Blackwood Lake)
(@CGUID+1486, 8598, 0, 1, 1, 2746.165, -4232.252, 102.9448, 2.561168, 120, 0, 0), -- Frenzied Plaguehound (Area: Blackwood Lake)
(@CGUID+1487, 8602, 0, 1, 1, 2718.163, -4180.387, 88.27308, 1.03476, 120, 0, 0), -- Monstrous Plaguebat (Area: Blackwood Lake)
(@CGUID+1488, 8598, 0, 1, 1, 2753.298, -4155.913, 91.71194, 1.568384, 120, 0, 0), -- Frenzied Plaguehound (Area: Blackwood Lake)
(@CGUID+1489, 8602, 0, 1, 1, 2707.225, -4195.792, 85.25941, 4.403095, 120, 0, 0), -- Monstrous Plaguebat (Area: Blackwood Lake)
(@CGUID+1490, 10779, 0, 1, 1, 2701.422, -4238.193, 94.00444, 0.2397611, 120, 0, 0), -- Infected Squirrel (Area: Blackwood Lake)
(@CGUID+1491, 2110, 0, 1, 1, 2760.863, -4150.075, 92.75783, 1.658143, 120, 0, 0), -- Black Rat (Area: Blackwood Lake)
(@CGUID+1492, 8602, 0, 1, 1, 2805.785, -4225.736, 89.75978, 3.061253, 120, 0, 0), -- Monstrous Plaguebat (Area: 0)
(@CGUID+1493, 8605, 0, 1, 1, 2821.596, -4146.527, 95.82868, 1.061233, 120, 0, 0), -- Carrion Devourer (Area: 0)
(@CGUID+1494, 8598, 0, 1, 1, 2895.599, -4158.425, 95.08039, 0.01952972, 120, 0, 0), -- Frenzied Plaguehound (Area: 0)
(@CGUID+1495, 10780, 0, 1, 1, 2828.144, -4231.033, 93.11501, 1.174784, 120, 0, 0), -- Infected Deer (Area: 0)
(@CGUID+1496, 8605, 0, 1, 1, 2982.421, -4189.965, 95.85775, 4.160414, 120, 0, 0), -- Carrion Devourer (Area: 0)
(@CGUID+1497, 8602, 0, 1, 1, 3000.928, -4147.916, 98.43407, 3.141593, 120, 0, 0), -- Monstrous Plaguebat (Area: 0)
(@CGUID+1498, 10780, 0, 1, 1, 2958.269, -4224.891, 94.55164, 1.138195, 120, 0, 0), -- Infected Deer (Area: 0)
(@CGUID+1499, 8598, 0, 1, 1, 3058.132, -4202.679, 95.36326, 5.976974, 120, 0, 0), -- Frenzied Plaguehound (Area: 0)
(@CGUID+1500, 45816, 0, 1, 1, 3084.89, -4222.7, 90.63194, 1.27409, 120, 0, 0), -- Corpseburner Tim (Area: 0)
(@CGUID+1501, 41177, 0, 1, 1, 3089.311, -4200.624, 82.82589, 5.969026, 120, 0, 0), -- Stitched Horror (Cosmetic) (Area: 0)
(@CGUID+1502, 41177, 0, 1, 1, 3105.119, -4209.082, 82.64156, 2.9147, 120, 0, 0), -- Stitched Horror (Cosmetic) (Area: 0)
(@CGUID+1503, 41177, 0, 1, 1, 3094.411, -4192.99, 82.36355, 0.8028514, 120, 0, 0), -- Stitched Horror (Cosmetic) (Area: 0)
(@CGUID+1504, 41195, 0, 1, 1, 3103.007, -4212.663, 83.27452, 5.305801, 120, 0, 0), -- Cannibal Ghoul (Cosmetic) (Area: 0)
(@CGUID+1505, 41195, 0, 1, 1, 3091.253, -4194.549, 82.36852, 1.937315, 120, 0, 0), -- Cannibal Ghoul (Cosmetic) (Area: 0)
(@CGUID+1506, 41195, 0, 1, 1, 3090.141, -4205.479, 82.86685, 0.5061455, 120, 0, 0), -- Cannibal Ghoul (Cosmetic) (Area: 0)
(@CGUID+1507, 41195, 0, 1, 1, 3100.022, -4202.377, 82.34879, 0.2443461, 120, 0, 0), -- Cannibal Ghoul (Cosmetic) (Area: 0)
(@CGUID+1508, 41177, 0, 1, 1, 3105.092, -4197.533, 82.39491, 2.75762, 120, 0, 0), -- Stitched Horror (Cosmetic) (Area: 0)
(@CGUID+1509, 41177, 0, 1, 1, 3094.3, -4203.802, 82.33028, 2.042035, 120, 0, 0), -- Stitched Horror (Cosmetic) (Area: 0)
(@CGUID+1510, 41177, 0, 1, 1, 3098.325, -4210.479, 82.41264, 1.58825, 120, 0, 0), -- Stitched Horror (Cosmetic) (Area: 0)
(@CGUID+1511, 41195, 0, 1, 1, 3095.103, -4213.469, 83.75532, 2.75762, 120, 0, 0), -- Cannibal Ghoul (Cosmetic) (Area: 0)
(@CGUID+1512, 8564, 0, 1, 1, 3153.764, -4152.819, 96.46481, 6.159205, 120, 0, 0), -- Ranger (Area: 0)
(@CGUID+1513, 8602, 0, 1, 1, 3093.648, -4143.138, 98.89756, 0.007851373, 120, 0, 0), -- Monstrous Plaguebat (Area: 0)
(@CGUID+1514, 10780, 0, 1, 1, 3085.888, -4150.264, 96.74705, 1.115632, 120, 0, 0), -- Infected Deer (Area: 0)
(@CGUID+1515, 8563, 0, 1, 1, 3178.208, -4193.76, 96.3574, 4.196261, 120, 0, 0), -- Woodsman (Area: 0)
(@CGUID+1516, 20725, 0, 1, 1, 3153.27, -4203.201, 96.5395, 1.000831, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+1517, 8563, 0, 1, 1, 3214.912, -4220.811, 87.98567, 0.1331968, 120, 0, 0), -- Woodsman (Area: Eastwall Gate)
(@CGUID+1518, 8564, 0, 1, 1, 3231.95, -4193.52, 91.17064, 3.351032, 120, 0, 0), -- Ranger (Area: Eastwall Gate)
(@CGUID+1519, 8563, 0, 1, 1, 3280.18, -4160.361, 114.0883, 3.403392, 120, 0, 0), -- Woodsman (Area: Eastwall Gate)
(@CGUID+1520, 8565, 0, 1, 1, 3270.09, -4180.84, 105.6493, 3.368485, 120, 0, 0), -- Pathstrider (Area: Eastwall Gate)
(@CGUID+1521, 8565, 0, 1, 1, 3240.083, -4173.831, 96.38558, 3.403392, 120, 0, 0), -- Pathstrider (Area: Eastwall Gate)
(@CGUID+1522, 8565, 0, 1, 1, 3312.11, -4222.22, 159.0443, 2.199115, 120, 0, 0), -- Pathstrider (Area: Quel'Lithien Lodge)
(@CGUID+1523, 8563, 0, 1, 1, 3267.21, -4210.9, 152.5123, 3.787364, 120, 0, 0), -- Woodsman (Area: Quel'Lithien Lodge)
(@CGUID+1524, 8565, 0, 1, 1, 3310, -4163.15, 123.2763, 3.385939, 120, 0, 0), -- Pathstrider (Area: Quel'Lithien Lodge)
(@CGUID+1525, 8565, 0, 1, 1, 3322.95, -4146.458, 130.352, 3.560472, 120, 0, 0), -- Pathstrider (Area: Quel'Lithien Lodge)
(@CGUID+1526, 8565, 0, 1, 1, 3352.208, -4174.528, 159.2106, 2.740167, 120, 0, 0), -- Pathstrider (Area: Quel'Lithien Lodge)
(@CGUID+1527, 8565, 0, 1, 1, 3369.391, -4142.971, 144.8896, 4.29351, 120, 0, 0), -- Pathstrider (Area: Quel'Lithien Lodge)
(@CGUID+1528, 8565, 0, 1, 1, 3350.16, -4155.33, 139.1663, 2.984513, 120, 0, 0), -- Pathstrider (Area: Quel'Lithien Lodge)
(@CGUID+1529, 8565, 0, 1, 1, 3360.03, -4223.13, 156.3333, 6.213372, 120, 0, 0), -- Pathstrider (Area: Quel'Lithien Lodge)
(@CGUID+1530, 8565, 0, 1, 1, 3386.333, -4175.465, 146.4375, 1.93725, 120, 0, 0), -- Pathstrider (Area: Quel'Lithien Lodge)
(@CGUID+1531, 8563, 0, 1, 1, 3389.81, -4213.72, 153.1313, 2.236792, 120, 0, 0), -- Woodsman (Area: Quel'Lithien Lodge)
(@CGUID+1532, 8565, 0, 1, 1, 3386.665, -4216.191, 154.0172, 2.24311, 120, 0, 0), -- Pathstrider (Area: Quel'Lithien Lodge)
(@CGUID+1533, 8565, 0, 1, 1, 3318.5, -4267.08, 159.1398, 4.71416, 120, 0, 0), -- Pathstrider (Area: Quel'Lithien Lodge)
(@CGUID+1534, 20725, 0, 1, 1, 3410.722, -4280.288, 159.0423, 6.209309, 120, 0, 0), -- Bat (Area: Quel'Lithien Lodge)
(@CGUID+1535, 8563, 0, 1, 1, 3380.372, -4270.271, 159.4191, 1.500983, 120, 0, 0), -- Woodsman (Area: Quel'Lithien Lodge)
(@CGUID+1536, 8565, 0, 1, 1, 3381.91, -4296.56, 159.3043, 1.658063, 120, 0, 0), -- Pathstrider (Area: Quel'Lithien Lodge)
(@CGUID+1537, 8564, 0, 1, 1, 3318.482, -4255.595, 159.1398, 4.713866, 120, 0, 0), -- Ranger (Area: Quel'Lithien Lodge)
(@CGUID+1538, 8565, 0, 1, 1, 3311.06, -4243.47, 159.0633, 3.665191, 120, 0, 0), -- Pathstrider (Area: Quel'Lithien Lodge)
(@CGUID+1539, 8565, 0, 1, 1, 3359.38, -4247.75, 156.3073, 0.08726646, 120, 0, 0), -- Pathstrider (Area: Quel'Lithien Lodge)
(@CGUID+1540, 8564, 0, 1, 1, 3426.931, -4243.754, 161.502, 6.060704, 120, 0, 0), -- Ranger (Area: Quel'Lithien Lodge)
(@CGUID+1541, 8563, 0, 1, 1, 3313.575, -4275.269, 159.2231, 3.071779, 120, 0, 0), -- Woodsman (Area: Quel'Lithien Lodge)
(@CGUID+1542, 8563, 0, 1, 1, 3284.849, -4231.147, 158.3972, 3.246312, 120, 0, 0), -- Woodsman (Area: Quel'Lithien Lodge)
(@CGUID+1543, 8565, 0, 1, 1, 3161.655, -4221.228, 95.86264, 3.65684, 120, 0, 0), -- Pathstrider (Area: Quel'Lithien Lodge)
(@CGUID+1544, 8564, 0, 1, 1, 3191.961, -4242.549, 97.19899, 0.2580214, 120, 0, 0), -- Ranger (Area: Quel'Lithien Lodge)
(@CGUID+1545, 8565, 0, 1, 1, 3212.224, -4266.999, 102.1875, 4.757369, 120, 0, 0), -- Pathstrider (Area: Quel'Lithien Lodge)
(@CGUID+1546, 45826, 0, 1, 1, 3179.52, -4303.53, 128.2983, 1.134464, 120, 0, 0), -- Kirkian Dawnshield (Area: Quel'Lithien Lodge)
(@CGUID+1547, 47060, 0, 1, 1, 3095.77, -4271.1, 102.2323, 2.164208, 120, 0, 0), -- Argent Sentry (Area: Quel'Lithien Lodge)
(@CGUID+1548, 47060, 0, 1, 1, 3134.83, -4294.51, 119.0863, 2.443461, 120, 0, 0), -- Argent Sentry (Area: Quel'Lithien Lodge)
(@CGUID+1549, 47060, 0, 1, 1, 3124.36, -4302.6, 119.0153, 2.164208, 120, 0, 0), -- Argent Sentry (Area: Quel'Lithien Lodge)
(@CGUID+1550, 47060, 0, 1, 1, 3064.59, -4262.49, 97.61234, 3.01942, 120, 0, 0), -- Argent Sentry (Area: Quel'Lithien Lodge)
(@CGUID+1551, 47060, 0, 1, 1, 3063.49, -4249.71, 98.07664, 3.577925, 120, 0, 0), -- Argent Sentry (Area: Quel'Lithien Lodge)
(@CGUID+1552, 47060, 0, 1, 1, 3104.92, -4264.09, 101.1563, 2.408554, 120, 0, 0), -- Argent Sentry (Area: Quel'Lithien Lodge)
(@CGUID+1553, 8605, 0, 1, 1, 3039.691, -4313.892, 100.9486, 5.577948, 120, 0, 0), -- Carrion Devourer (Area: 0)
(@CGUID+1554, 8602, 0, 1, 1, 2946.898, -4284.53, 90.91451, 1.021845, 120, 0, 0), -- Monstrous Plaguebat (Area: 0)
(@CGUID+1555, 8598, 0, 1, 1, 2810.962, -4283.508, 87.95889, 0.5397714, 120, 0, 0), -- Frenzied Plaguehound (Area: 0)
(@CGUID+1556, 8602, 0, 1, 1, 2774.611, -4246.69, 91.07523, 3.125969, 120, 0, 0), -- Monstrous Plaguebat (Area: 0)
(@CGUID+1557, 8598, 0, 1, 1, 2794.869, -4248.126, 88.77223, 1.606913, 120, 0, 0), -- Frenzied Plaguehound (Area: 0)
(@CGUID+1558, 8598, 0, 1, 1, 2837.742, -4261.531, 89.45912, 2.955192, 120, 0, 0), -- Frenzied Plaguehound (Area: 0)
(@CGUID+1559, 10780, 0, 1, 1, 2816.072, -4255.502, 88.36623, 1.193313, 120, 0, 0), -- Infected Deer (Area: 0)
(@CGUID+1560, 8598, 0, 1, 1, 2751.973, -4282.354, 87.70094, 1.958375, 120, 0, 0), -- Frenzied Plaguehound (Area: 0)
(@CGUID+1561, 8602, 0, 1, 1, 2716.643, -4265.713, 101.9871, 4.41583, 120, 0, 0), -- Monstrous Plaguebat (Area: 0)
(@CGUID+1562, 2110, 0, 1, 1, 2525.517, -4290.26, 75.6459, 5.61211, 120, 0, 0), -- Black Rat (Area: Blackwood Lake)
(@CGUID+1563, 2110, 0, 1, 1, 2521.784, -4255.08, 75.45154, 0.1829057, 120, 0, 0), -- Black Rat (Area: Blackwood Lake)
(@CGUID+1564, 8601, 0, 1, 1, 2503.933, -4261.426, 75.61868, 1.739475, 120, 0, 0), -- Noxious Plaguebat (Area: Blackwood Lake)
(@CGUID+1565, 2110, 0, 1, 1, 2484.033, -4274.264, 74.40589, 2.970824, 120, 0, 0), -- Black Rat (Area: Blackwood Lake)
(@CGUID+1566, 8601, 0, 1, 1, 2469.068, -4278.586, 75.68832, 1.340041, 120, 0, 0), -- Noxious Plaguebat (Area: Blackwood Lake)
(@CGUID+1567, 8601, 0, 1, 1, 2450.85, -4266.46, 76.37706, 0.5549791, 120, 0, 0), -- Noxious Plaguebat (Area: Blackwood Lake)
(@CGUID+1568, 8601, 0, 1, 1, 2395.173, -4278.332, 85.43416, 2.391873, 120, 0, 0), -- Noxious Plaguebat (Area: Blackwood Lake)
(@CGUID+1569, 8597, 0, 1, 1, 2277.668, -4280.114, 78.4092, 4.901935, 120, 0, 0), -- Plaguehound (Area: 0)
(@CGUID+1570, 8601, 0, 1, 1, 2250.517, -4252.011, 90.56171, 6.255848, 120, 0, 0), -- Noxious Plaguebat (Area: 0)
(@CGUID+1571, 8597, 0, 1, 1, 2213.979, -4284.051, 77.12305, 5.288418, 120, 0, 0), -- Plaguehound (Area: 0)
(@CGUID+1572, 47060, 0, 1, 1, 2062.04, -4270.18, 81.48923, 6.126106, 120, 0, 0), -- Argent Sentry (Area: The Infectis Scar)
(@CGUID+1573, 47060, 0, 1, 1, 2040.39, -4252.46, 84.62604, 5.916666, 120, 0, 0), -- Argent Sentry (Area: The Infectis Scar)
(@CGUID+1574, 47060, 0, 1, 1, 2064.34, -4257.82, 81.35014, 5.916666, 120, 0, 0), -- Argent Sentry (Area: The Infectis Scar)
(@CGUID+1575, 45657, 0, 1, 1, 2075.84, -4215.524, 20.42822, 1.110589, 120, 0, 0), -- Infectis Scuttler (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1576, 45650, 0, 1, 1, 2077.856, -4223.387, 23.1684, 3.488271, 120, 0, 0), -- Plague Puffer (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1577, 45650, 0, 1, 1, 2063.24, -4218.542, 20.43754, 2.181381, 120, 0, 0), -- Plague Puffer (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1578, 45650, 0, 1, 1, 2053.981, -4229.289, 23.2778, 1.69534, 120, 0, 0), -- Plague Puffer (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1579, 45655, 0, 1, 1, 2064.263, -4202.444, 20.42822, 4.330808, 120, 0, 0), -- Infectis Incher (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1580, 45657, 0, 1, 1, 2043.501, -4213.792, 22.64965, 1.803845, 120, 0, 0), -- Infectis Scuttler (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1581, 45655, 0, 1, 1, 2042.481, -4225.072, 20.42822, 5.113324, 120, 0, 0), -- Infectis Incher (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1582, 45657, 0, 1, 1, 2075.53, -4216.15, 20.38773, 1.354392, 120, 0, 0), -- Infectis Scuttler (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1583, 47060, 0, 1, 1, 2038.09, -4264.82, 84.59054, 6.126106, 120, 0, 0), -- Argent Sentry (Area: The Infectis Scar)
(@CGUID+1584, 47060, 0, 1, 1, 2025.54, -4262.6, 84.61304, 2.827433, 120, 0, 0), -- Argent Sentry (Area: The Infectis Scar)
(@CGUID+1585, 45657, 0, 1, 1, 2027.712, -4227.302, 28.8038, 2.526069, 120, 0, 0), -- Infectis Scuttler (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1586, 47060, 0, 1, 1, 2002.34, -4257.5, 81.02193, 2.827433, 120, 0, 0), -- Argent Sentry (Area: The Infectis Scar)
(@CGUID+1587, 45655, 0, 1, 1, 2013.88, -4214.34, 18.63203, 0, 120, 0, 0), -- Infectis Incher (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1588, 45655, 0, 1, 1, 2007.397, -4193.096, 14.4213, 1.217296, 120, 0, 0), -- Infectis Incher (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1589, 45650, 0, 1, 1, 2038.494, -4291.438, 24.75494, 1.376565, 120, 0, 0), -- Plague Puffer (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1590, 45650, 0, 1, 1, 1994.007, -4214.784, 10.1528, 2.211897, 120, 0, 0), -- Plague Puffer (Area: The Infectis Scar)
(@CGUID+1591, 45650, 0, 1, 1, 2018.005, -4136.318, 15.77391, 0.4181527, 120, 0, 0), -- Plague Puffer (Area: The Infectis Scar)
(@CGUID+1592, 45655, 0, 1, 1, 2007.437, -4144.895, 15.67845, 3.907918, 120, 0, 0), -- Infectis Incher (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1593, 45655, 0, 1, 1, 2020.997, -4292.133, 14.86596, 3.742749, 120, 0, 0), -- Infectis Incher (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1594, 45655, 0, 1, 1, 2024.718, -4297.74, 14.39326, 1.111905, 120, 0, 0), -- Infectis Incher (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1595, 45650, 0, 1, 1, 2005.794, -4285.371, 10.01826, 1.323212, 120, 0, 0), -- Plague Puffer (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1596, 45657, 0, 1, 1, 2026.554, -4304.641, 13.217, 1.920735, 120, 0, 0), -- Infectis Scuttler (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1597, 45657, 0, 1, 1, 1990.459, -4277.126, 14.0346, 6.026487, 120, 0, 0), -- Infectis Scuttler (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1598, 45657, 0, 1, 1, 2007.529, -4289.92, 9.790901, 5.966813, 120, 0, 0), -- Infectis Scuttler (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1599, 45650, 0, 1, 1, 2007.059, -4289.711, 9.78125, 1.946742, 120, 0, 0), -- Plague Puffer (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1600, 45664, 0, 1, 1, 1996.715, -4297.737, 12.1743, 1.942698, 120, 0, 0), -- Landlocked Grouper (Area: The Infectis Scar)
(@CGUID+1601, 45657, 0, 1, 1, 1994.721, -4286.362, 11.49895, 4.417738, 120, 0, 0), -- Infectis Scuttler (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1602, 45655, 0, 1, 1, 1990.005, -4284.695, 13.64739, 1.514901, 120, 0, 0), -- Infectis Incher (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1603, 45650, 0, 1, 1, 1993.941, -4289.797, 11.7708, 0.9761052, 120, 0, 0), -- Plague Puffer (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1604, 45650, 0, 1, 1, 1995.25, -4293.982, 12.1285, 0.9814551, 120, 0, 0), -- Plague Puffer (Area: The Infectis Scar)
(@CGUID+1605, 45655, 0, 1, 1, 1976.362, -4281.235, 19.99895, 3.678103, 120, 0, 0), -- Infectis Incher (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1606, 45655, 0, 1, 1, 1979.964, -4287.88, 18.87395, 1.909949, 120, 0, 0), -- Infectis Incher (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1607, 45650, 0, 1, 1, 1986.486, -4292.542, 14.6762, 3.299547, 120, 0, 0), -- Plague Puffer (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1608, 45650, 0, 1, 1, 1989.01, -4297.241, 14.14268, 3.460344, 120, 0, 0), -- Plague Puffer (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1609, 45650, 0, 1, 1, 1972.127, -4290.464, 19.1006, 2.638208, 120, 0, 0), -- Plague Puffer (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1610, 45657, 0, 1, 1, 1977.934, -4294.223, 17.74895, 3.084628, 120, 0, 0), -- Infectis Scuttler (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1611, 45657, 0, 1, 1, 1973.572, -4294.7, 18.1944, 6.051459, 120, 0, 0), -- Infectis Scuttler (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1612, 8600, 0, 1, 1, 1843.826, -4243.714, 90.87968, 1.897717, 120, 0, 0), -- Plaguebat (Area: The Infectis Scar)
(@CGUID+1613, 45650, 0, 1, 1, 1977.77, -4194.26, 13.14953, 0.7246565, 120, 0, 0), -- Plague Puffer (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1614, 45650, 0, 1, 1, 1991.02, -4170.05, 14.54683, 4.24067, 120, 0, 0), -- Plague Puffer (Area: The Infectis Scar)
(@CGUID+1615, 45655, 0, 1, 1, 1998.99, -4223.37, 13.52773, 3.240281, 120, 0, 0), -- Infectis Incher (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1616, 8600, 0, 1, 1, 1813.048, -4287.563, 85.01203, 4.182645, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+1617, 8600, 0, 1, 1, 1711.832, -4304.075, 87.62315, 3.081918, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+1618, 8600, 0, 1, 1, 1746.771, -4289.972, 90.12572, 1.784497, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+1619, 8596, 0, 1, 1, 1688.265, -4348.858, 77.83776, 2.932958, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+1620, 8596, 0, 1, 1, 1720.89, -4392.819, 74.35799, 4.361617, 120, 0, 0), -- Plaguehound Runt (Area: 0)
(@CGUID+1621, 8600, 0, 1, 1, 1769.113, -4335.029, 80.66036, 0.1446268, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+1622, 8600, 0, 1, 1, 1785.454, -4307.802, 78.8821, 4.582224, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+1623, 20725, 0, 1, 1, 1757.288, -4337.56, 78.18596, 0.5577055, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+1624, 20725, 0, 1, 1, 1763.742, -4355.818, 76.55244, 2.06821, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+1625, 8600, 0, 1, 1, 1837.046, -4315.851, 93.55343, 0.4636476, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+1626, 20725, 0, 1, 1, 1834.732, -4370.674, 100.2777, 4.650168, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+1627, 8600, 0, 1, 1, 1803.084, -4346.854, 96.2342, 0.7086263, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+1628, 45664, 0, 1, 1, 1966.01, -4307.919, 20.54505, 5.262321, 120, 0, 0), -- Landlocked Grouper (Area: 0)
(@CGUID+1629, 45655, 0, 1, 1, 1968.404, -4311.824, 20.22148, 2.204982, 120, 0, 0), -- Infectis Incher (Area: 0) (possible waypoints or random movement)
(@CGUID+1630, 45650, 0, 1, 1, 1978.578, -4304.175, 16.06059, 3.774139, 120, 0, 0), -- Plague Puffer (Area: 0) (possible waypoints or random movement)
(@CGUID+1631, 45657, 0, 1, 1, 1980.74, -4308.47, 15.00383, 1.097861, 120, 0, 0), -- Infectis Scuttler (Area: 0) (possible waypoints or random movement)
(@CGUID+1632, 45655, 0, 1, 1, 1983.359, -4315.046, 19.72396, 3.638766, 120, 0, 0), -- Infectis Incher (Area: 0) (possible waypoints or random movement)
(@CGUID+1633, 45655, 0, 1, 1, 1990.967, -4310.585, 12.70589, 2.210237, 120, 0, 0), -- Infectis Incher (Area: 0) (possible waypoints or random movement)
(@CGUID+1634, 45650, 0, 1, 1, 1993.69, -4321.71, 12.42741, 0.7066544, 120, 0, 0), -- Plague Puffer (Area: 0) (possible waypoints or random movement)
(@CGUID+1635, 45657, 0, 1, 1, 1994.902, -4325.762, 11.95, 5.304435, 120, 0, 0), -- Infectis Scuttler (Area: 0) (possible waypoints or random movement)
(@CGUID+1636, 45655, 0, 1, 1, 1995.952, -4330.352, 12.19988, 1.722466, 120, 0, 0), -- Infectis Incher (Area: 0) (possible waypoints or random movement)
(@CGUID+1637, 45655, 0, 1, 1, 1989.29, -4197.4, 10.95483, 0, 120, 0, 0), -- Infectis Incher (Area: 0) (possible waypoints or random movement)
(@CGUID+1638, 45657, 0, 1, 1, 1996.134, -4202.539, 10.4635, 4.243268, 120, 0, 0), -- Infectis Scuttler (Area: 0) (possible waypoints or random movement)
(@CGUID+1639, 45657, 0, 1, 1, 2008.498, -4326.028, 9.42535, 0.3460793, 120, 0, 0), -- Infectis Scuttler (Area: 0) (possible waypoints or random movement)
(@CGUID+1640, 45664, 0, 1, 1, 2017.676, -4319.345, 12.63451, 1.120289, 120, 0, 0), -- Landlocked Grouper (Area: The Infectis Scar)
(@CGUID+1641, 45664, 0, 1, 1, 2039.247, -4308.661, 17.1296, 5.318102, 120, 0, 0), -- Landlocked Grouper (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1642, 45655, 0, 1, 1, 1997.725, -4318.807, 11.67741, 3.799707, 120, 0, 0), -- Infectis Incher (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1643, 45655, 0, 1, 1, 2010.776, -4314.862, 12.75381, 4.384924, 120, 0, 0), -- Infectis Incher (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1644, 45657, 0, 1, 1, 2021.755, -4310.178, 12.7927, 5.674276, 120, 0, 0), -- Infectis Scuttler (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1645, 45655, 0, 1, 1, 2019.771, -4315.014, 12.75381, 1.695424, 120, 0, 0), -- Infectis Incher (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1646, 45650, 0, 1, 1, 2010.832, -4325.591, 9.253808, 1.149585, 120, 0, 0), -- Plague Puffer (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1647, 45655, 0, 1, 1, 2026.233, -4322.194, 11.70692, 2.978564, 120, 0, 0), -- Infectis Incher (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1648, 45650, 0, 1, 1, 2023.4, -4323.27, 10.81063, 0, 120, 0, 0), -- Plague Puffer (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1649, 45650, 0, 1, 1, 2032.41, -4318.246, 12.62881, 3.310766, 120, 0, 0), -- Plague Puffer (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1650, 45664, 0, 1, 1, 2052.432, -4321.919, 13.00117, 1.227838, 120, 0, 0), -- Landlocked Grouper (Area: The Infectis Scar)
(@CGUID+1651, 45664, 0, 1, 1, 2017.304, -4357.472, 13.70852, 4.842489, 120, 0, 0), -- Landlocked Grouper (Area: The Infectis Scar)
(@CGUID+1652, 45657, 0, 1, 1, 2052.556, -4306.05, 13.22163, 1.758852, 120, 0, 0), -- Infectis Scuttler (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1653, 45655, 0, 1, 1, 2043.811, -4320.42, 12.6944, 5.624132, 120, 0, 0), -- Infectis Incher (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1654, 45657, 0, 1, 1, 2026.65, -4329.218, 7.739892, 5.336128, 120, 0, 0), -- Infectis Scuttler (Area: The Infectis Scar)
(@CGUID+1655, 45657, 0, 1, 1, 2037.369, -4327.325, 11.07978, 2.98329, 120, 0, 0), -- Infectis Scuttler (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1656, 45655, 0, 1, 1, 2046.103, -4324.224, 12.4479, 3.954731, 120, 0, 0), -- Infectis Incher (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1657, 45650, 0, 1, 1, 2053.787, -4318.124, 12.7602, 1.394798, 120, 0, 0), -- Plague Puffer (Area: The Infectis Scar)
(@CGUID+1658, 45657, 0, 1, 1, 2040.71, -4330.474, 10.33485, 1.592487, 120, 0, 0), -- Infectis Scuttler (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1659, 45664, 0, 1, 1, 2049.729, -4340.495, 10.24361, 1.941261, 120, 0, 0), -- Landlocked Grouper (Area: The Infectis Scar)
(@CGUID+1660, 45657, 0, 1, 1, 2043.57, -4330.472, 11.07396, 5.030514, 120, 0, 0), -- Infectis Scuttler (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1661, 45655, 0, 1, 1, 2056.089, -4207.544, 20.67822, 1.3746, 120, 0, 0), -- Infectis Incher (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1662, 45655, 0, 1, 1, 2054.123, -4323.284, 12.69245, 1.795144, 120, 0, 0), -- Infectis Incher (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1663, 45650, 0, 1, 1, 2061.16, -4209.853, 20.42822, 4.414311, 120, 0, 0), -- Plague Puffer (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1664, 45650, 0, 1, 1, 2017.84, -4361.57, 13.73303, 0, 120, 0, 0), -- Plague Puffer (Area: The Infectis Scar)
(@CGUID+1665, 45655, 0, 1, 1, 2063.542, -4321.875, 12.6627, 5.933237, 120, 0, 0), -- Infectis Incher (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1666, 45650, 0, 1, 1, 2048.29, -4336.791, 9.363867, 4.974108, 120, 0, 0), -- Plague Puffer (Area: The Infectis Scar)
(@CGUID+1667, 45650, 0, 1, 1, 2040.658, -4342.682, 8.208199, 5.495867, 120, 0, 0), -- Plague Puffer (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1668, 45655, 0, 1, 1, 2063.728, -4203.98, 20.42822, 4.356503, 120, 0, 0), -- Infectis Incher (Area: The Infectis Scar)
(@CGUID+1669, 45655, 0, 1, 1, 2062.341, -4330.372, 11.3852, 0.05979822, 120, 0, 0), -- Infectis Incher (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1670, 45650, 0, 1, 1, 2078.88, -4320.008, 11.96138, 2.427988, 120, 0, 0), -- Plague Puffer (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1671, 45655, 0, 1, 1, 2072.954, -4338.17, 11.38903, 2.262987, 120, 0, 0), -- Infectis Incher (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1672, 45650, 0, 1, 1, 2078.936, -4336.819, 11.61755, 2.672255, 120, 0, 0), -- Plague Puffer (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1673, 45657, 0, 1, 1, 2079.657, -4344.365, 12.62487, 5.573849, 120, 0, 0), -- Infectis Scuttler (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1674, 45655, 0, 1, 1, 2075.079, -4352.911, 13.60765, 0.5888389, 120, 0, 0), -- Infectis Incher (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1675, 45650, 0, 1, 1, 2084.74, -4342.904, 14.87121, 0.2598382, 120, 0, 0), -- Plague Puffer (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1676, 45655, 0, 1, 1, 2079.766, -4347.811, 12.85839, 2.499632, 120, 0, 0), -- Infectis Incher (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1677, 45657, 0, 1, 1, 2085.82, -4355.4, 13.64416, 1.664718, 120, 0, 0), -- Infectis Scuttler (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1678, 45657, 0, 1, 1, 2089.801, -4360.974, 13.80554, 2.142443, 120, 0, 0), -- Infectis Scuttler (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1679, 45650, 0, 1, 1, 2054.328, -4319.537, 12.7602, 1.990787, 120, 0, 0), -- Plague Puffer (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1680, 45650, 0, 1, 1, 2071.081, -4202.056, 22.52401, 5.076073, 120, 0, 0), -- Plague Puffer (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1681, 45655, 0, 1, 1, 2072.645, -4186.362, 20.91717, 4.476346, 120, 0, 0), -- Infectis Incher (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1682, 47060, 0, 1, 1, 2210.95, -4333.34, 77.74313, 2.356194, 120, 0, 0), -- Argent Sentry (Area: The Infectis Scar)
(@CGUID+1683, 47060, 0, 1, 1, 2218.36, -4326.31, 76.89014, 2.722714, 120, 0, 0), -- Argent Sentry (Area: The Infectis Scar)
(@CGUID+1684, 8601, 0, 1, 1, 2284.486, -4344.222, 78.03587, 0.8654229, 120, 0, 0), -- Noxious Plaguebat (Area: The Infectis Scar)
(@CGUID+1685, 8603, 0, 1, 1, 2310.514, -4316.686, 73.97237, 5.669179, 120, 0, 0), -- Carrion Grub (Area: The Infectis Scar)
(@CGUID+1686, 8601, 0, 1, 1, 2377.147, -4309.451, 77.45338, 4.659915, 120, 0, 0), -- Noxious Plaguebat (Area: 0)
(@CGUID+1687, 20725, 0, 1, 1, 2369.075, -4348.84, 78.67426, 2.925036, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+1688, 8601, 0, 1, 1, 2446.065, -4323.95, 75.19741, 4.264039, 120, 0, 0), -- Noxious Plaguebat (Area: 0)
(@CGUID+1689, 8601, 0, 1, 1, 2484.877, -4347.048, 77.42321, 0.1115197, 120, 0, 0), -- Noxious Plaguebat (Area: Blackwood Lake)
(@CGUID+1690, 8598, 0, 1, 1, 2621.33, -4318.836, 83.85698, 2.42111, 120, 0, 0), -- Frenzied Plaguehound (Area: Blackwood Lake)
(@CGUID+1691, 8605, 0, 1, 1, 2713.466, -4342.005, 130.7453, 3.809842, 120, 0, 0), -- Carrion Devourer (Area: Blackwood Lake)
(@CGUID+1692, 8598, 0, 1, 1, 2981.633, -4328.25, 78.81232, 1.28177, 120, 0, 0), -- Frenzied Plaguehound (Area: 0)
(@CGUID+1693, 8598, 0, 1, 1, 3026.361, -4345.405, 101.14, 1.040764, 120, 0, 0), -- Frenzied Plaguehound (Area: 0)
(@CGUID+1694, 47164, 0, 1, 1, 3175.89, -4341.96, 133.5123, 1.361357, 120, 0, 0), -- James Litman (Area: Northpass Tower)
(@CGUID+1695, 47166, 0, 1, 1, 3181.97, -4339.04, 133.451, 1.888741, 120, 0, 0), -- Dorris Manchester (Area: Northpass Tower) (possible waypoints or random movement)
(@CGUID+1696, 10779, 0, 1, 1, 3292.484, -4415.807, 107.9106, 5.771062, 120, 0, 0), -- Infected Squirrel (Area: Quel'Lithien Lodge)
(@CGUID+1697, 17878, 0, 1, 1, 3288.978, -4416.856, 107.9544, 4.299387, 120, 0, 0), -- Scourge Siege Engineer (Area: Quel'Lithien Lodge)
(@CGUID+1698, 10780, 0, 1, 1, 3259.905, -4390.959, 110.7751, 0.8933107, 120, 0, 0), -- Infected Deer (Area: Quel'Lithien Lodge)
(@CGUID+1699, 17878, 0, 1, 1, 3259.94, -4421.28, 109.5917, 5.5676, 120, 0, 0), -- Scourge Siege Engineer (Area: Quel'Lithien Lodge)
(@CGUID+1700, 47060, 0, 1, 1, 3179.56, -4368.79, 168.1084, 5.849331, 120, 0, 0), -- Argent Sentry (Area: Quel'Lithien Lodge) (possible waypoints or random movement)
(@CGUID+1701, 47165, 0, 1, 1, 3140.48, -4363.6, 133.4993, 2.513274, 120, 0, 0), -- Casey Tipple (Area: Quel'Lithien Lodge)
(@CGUID+1702, 47167, 0, 1, 1, 3171.14, -4371.54, 138.6853, 1.658063, 120, 0, 0), -- Brett Nelson (Area: Quel'Lithien Lodge)
(@CGUID+1703, 47060, 0, 1, 1, 3167.29, -4349.78, 138.6803, 2.443461, 120, 0, 0), -- Argent Sentry (Area: Quel'Lithien Lodge)
(@CGUID+1704, 47060, 0, 1, 1, 3191.04, -4362.19, 138.6089, 1.865674, 120, 0, 0), -- Argent Sentry (Area: Quel'Lithien Lodge) (possible waypoints or random movement)
(@CGUID+1705, 47060, 0, 1, 1, 3178.4, -4374.49, 138.6893, 2.094395, 120, 0, 0), -- Argent Sentry (Area: Quel'Lithien Lodge)
(@CGUID+1706, 47060, 0, 1, 1, 3157.13, -4356.6, 138.6803, 2.164208, 120, 0, 0), -- Argent Sentry (Area: Quel'Lithien Lodge)
(@CGUID+1707, 45482, 0, 1, 1, 3128.56, -4369.08, 133.5793, 1.064651, 120, 0, 0), -- Argent Officer Irizarry (Area: Northpass Tower)
(@CGUID+1708, 44240, 0, 1, 1, 3130.95, -4360.99, 133.5793, 0.9599311, 120, 0, 0), -- Argent Hippogryph (Area: Northpass Tower)
(@CGUID+1709, 28621, 0, 1, 1, 3131.37, -4357.82, 133.5793, 0.6806784, 120, 0, 0), -- Grayson Ironwing (Area: Northpass Tower)
(@CGUID+1710, 20725, 0, 1, 1, 3027.669, -4362.108, 101.16, 3.243868, 120, 0, 0), -- Bat (Area: Northpass Tower)
(@CGUID+1711, 8598, 0, 1, 1, 3038.461, -4400.507, 100.2858, 4.508668, 120, 0, 0), -- Frenzied Plaguehound (Area: Northpass Tower)
(@CGUID+1712, 8602, 0, 1, 1, 2952.493, -4362.003, 88.47248, 4.900017, 120, 0, 0), -- Monstrous Plaguebat (Area: 0)
(@CGUID+1713, 2110, 0, 1, 1, 2966.422, -4355.519, 78.7971, 3.198283, 120, 0, 0), -- Black Rat (Area: 0)
(@CGUID+1714, 20725, 0, 1, 1, 2871.653, -4396.215, 82.9157, 3.811771, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+1715, 8598, 0, 1, 1, 2805.569, -4365.116, 107.3576, 3.50505, 120, 0, 0), -- Frenzied Plaguehound (Area: 0)
(@CGUID+1716, 8598, 0, 1, 1, 2611.732, -4388.168, 79.75481, 3.750719, 120, 0, 0), -- Frenzied Plaguehound (Area: Blackwood Lake)
(@CGUID+1717, 8602, 0, 1, 1, 2578.925, -4405.615, 79.24335, 3.382073, 120, 0, 0), -- Monstrous Plaguebat (Area: Blackwood Lake)
(@CGUID+1718, 10779, 0, 1, 1, 2557.255, -4391.135, 77.8817, 4.38724, 120, 0, 0), -- Infected Squirrel (Area: Blackwood Lake)
(@CGUID+1719, 8597, 0, 1, 1, 2441.848, -4384.646, 74.41261, 2.794824, 120, 0, 0), -- Plaguehound (Area: Blackwood Lake)
(@CGUID+1720, 10779, 0, 1, 1, 2411.935, -4376.703, 73.93793, 6.151395, 120, 0, 0), -- Infected Squirrel (Area: Blackwood Lake)
(@CGUID+1721, 8534, 0, 1, 1, 2422.425, -4411.715, 74.007, 3.172993, 120, 0, 0), -- Putrid Gargoyle (Area: Blackwood Lake)
(@CGUID+1722, 8597, 0, 1, 1, 2380.279, -4389.024, 80.54185, 5.361482, 120, 0, 0), -- Plaguehound (Area: Blackwood Lake)
(@CGUID+1723, 47060, 0, 1, 1, 2243.25, -4402.55, 111.5153, 1.64061, 120, 0, 0), -- Argent Sentry (Area: 0)
(@CGUID+1724, 44231, 0, 1, 1, 2264.55, -4414.64, 111.7813, 2.234021, 120, 0, 0), -- Devon Manning (Area: 0)
(@CGUID+1725, 47060, 0, 1, 1, 2256.82, -4400.38, 111.5573, 1.919862, 120, 0, 0), -- Argent Sentry (Area: 0)
(@CGUID+1726, 44240, 0, 1, 1, 2267.15, -4411.91, 111.7753, 4.13643, 120, 0, 0), -- Argent Hippogryph (Area: 0)
(@CGUID+1727, 47060, 0, 1, 1, 2248.23, -4365.56, 96.71544, 2.373648, 120, 0, 0), -- Argent Sentry (Area: 0)
(@CGUID+1728, 47060, 0, 1, 1, 2235.74, -4371.96, 97.04794, 1.850049, 120, 0, 0), -- Argent Sentry (Area: 0)
(@CGUID+1729, 20725, 0, 1, 1, 2130.155, -4401.863, 75.00574, 5.138456, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+1730, 8525, 0, 1, 1, 2046.22, -4394.647, 74.9105, 4.955712, 120, 0, 0), -- Scourge Warder (Area: The Infectis Scar)
(@CGUID+1731, 45657, 0, 1, 1, 2072.661, -4322.118, 12.39196, 2.373844, 120, 0, 0), -- Infectis Scuttler (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1732, 45664, 0, 1, 1, 2087.069, -4379.457, 11.02795, 0.5588709, 120, 0, 0), -- Landlocked Grouper (Area: The Infectis Scar)
(@CGUID+1733, 45657, 0, 1, 1, 2069.568, -4319.392, 12.89037, 0.3300519, 120, 0, 0), -- Infectis Scuttler (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1734, 45655, 0, 1, 1, 2083.646, -4361.889, 11.88684, 2.309004, 120, 0, 0), -- Infectis Incher (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1735, 45650, 0, 1, 1, 2064.7, -4357.669, 17.3412, 3.006461, 120, 0, 0), -- Plague Puffer (Area: The Infectis Scar)
(@CGUID+1736, 45650, 0, 1, 1, 2088.362, -4373.88, 10.02247, 4.424114, 120, 0, 0), -- Plague Puffer (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1737, 45655, 0, 1, 1, 2090.948, -4377.031, 9.953627, 3.367778, 120, 0, 0), -- Infectis Incher (Area: The Infectis Scar)
(@CGUID+1738, 45655, 0, 1, 1, 2096.687, -4382.214, 10.7552, 2.835809, 120, 0, 0), -- Infectis Incher (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1739, 45650, 0, 1, 1, 2053.792, -4330.563, 11.44062, 2.068798, 120, 0, 0), -- Plague Puffer (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1740, 45664, 0, 1, 1, 2074.126, -4407.998, 19.4159, 4.248742, 120, 0, 0), -- Landlocked Grouper (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1741, 45650, 0, 1, 1, 2076.561, -4390.358, 15.0534, 0.8150505, 120, 0, 0), -- Plague Puffer (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1742, 45650, 0, 1, 1, 2081.401, -4395.061, 15.1508, 1.473532, 120, 0, 0), -- Plague Puffer (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1743, 45655, 0, 1, 1, 2076.305, -4394.686, 15.6476, 1.251281, 120, 0, 0), -- Infectis Incher (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1744, 45650, 0, 1, 1, 2079.15, -4222.92, 23.25173, 0, 120, 0, 0), -- Plague Puffer (Area: The Infectis Scar)
(@CGUID+1745, 45655, 0, 1, 1, 2022.165, -4318.063, 12.4931, 4.639987, 120, 0, 0), -- Infectis Incher (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1746, 45650, 0, 1, 1, 2064.905, -4221.826, 20.60986, 4.64537, 120, 0, 0), -- Plague Puffer (Area: The Infectis Scar)
(@CGUID+1747, 45657, 0, 1, 1, 2012.444, -4310.122, 12.68459, 5.226593, 120, 0, 0), -- Infectis Scuttler (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1748, 45657, 0, 1, 1, 2019.325, -4380.631, 24.37955, 2.130371, 120, 0, 0), -- Infectis Scuttler (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1749, 45657, 0, 1, 1, 2013.52, -4384.399, 31.51678, 2.075006, 120, 0, 0), -- Infectis Scuttler (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1750, 45657, 0, 1, 1, 2008.519, -4305.536, 12.61977, 5.332438, 120, 0, 0), -- Infectis Scuttler (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1751, 45650, 0, 1, 1, 1989.078, -4306.496, 13.6698, 0.4958231, 120, 0, 0), -- Plague Puffer (Area: The Infectis Scar)
(@CGUID+1752, 45650, 0, 1, 1, 1962.2, -4312.01, 19.94443, 0, 120, 0, 0), -- Plague Puffer (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1753, 45655, 0, 1, 1, 1967.626, -4301.044, 17.55241, 3.601355, 120, 0, 0), -- Infectis Incher (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1754, 45655, 0, 1, 1, 1992.846, -4311.908, 12.34844, 1.471173, 120, 0, 0), -- Infectis Incher (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1755, 45655, 0, 1, 1, 2040.555, -4320.652, 12.6944, 4.233866, 120, 0, 0), -- Infectis Incher (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1756, 45655, 0, 1, 1, 2050.296, -4348.244, 11.8785, 2.751301, 120, 0, 0), -- Infectis Incher (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1757, 45650, 0, 1, 1, 2019.905, -4297.511, 12.76826, 0.9808146, 120, 0, 0), -- Plague Puffer (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1758, 45650, 0, 1, 1, 2057.356, -4354.292, 15.2775, 2.541491, 120, 0, 0), -- Plague Puffer (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1759, 45650, 0, 1, 1, 2063.592, -4356.861, 17.70307, 2.303067, 120, 0, 0), -- Plague Puffer (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1760, 8600, 0, 1, 1, 1853.345, -4375.828, 96.80319, 3.658558, 120, 0, 0), -- Plaguebat (Area: The Infectis Scar)
(@CGUID+1761, 20725, 0, 1, 1, 1870.696, -4388.609, 94.0764, 1.321007, 120, 0, 0), -- Bat (Area: The Infectis Scar)
(@CGUID+1762, 8600, 0, 1, 1, 1819.794, -4411.63, 85.4261, 1.858104, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+1763, 8600, 0, 1, 1, 1774.811, -4379.967, 79.65843, 6.210834, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+1764, 8603, 0, 1, 1, 1676.041, -4400.893, 86.88586, 1.570796, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+1765, 20725, 0, 1, 1, 1615.565, -4409.146, 96.6237, 5.351074, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+1766, 32520, 0, 1, 1, -6148.39, 5539.97, -1207.787, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: 0)
(@CGUID+1767, 32520, 0, 1, 1, -6014.71, 5479.63, -1208.007, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: 0)
(@CGUID+1768, 32520, 0, 1, 1, -6305.162, 5582.533, -1172.063, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: 0)
(@CGUID+1769, 32520, 0, 1, 1, -5691.65, 5556.92, -1154.687, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: 0)
(@CGUID+1770, 8596, 0, 1, 1, 1650.963, -4444.868, 87.1377, 0.8352444, 120, 0, 0), -- Plaguehound Runt (Area: Lake Mereldar)
(@CGUID+1771, 20725, 0, 1, 1, 1692.335, -4415.413, 83.2006, 3.440445, 120, 0, 0), -- Bat (Area: Lake Mereldar)
(@CGUID+1772, 8596, 0, 1, 1, 1618.94, -4420.732, 96.44102, 6.169615, 120, 0, 0), -- Plaguehound Runt (Area: Lake Mereldar)
(@CGUID+1773, 8520, 0, 1, 1, 1747.828, -4454.126, 73.92389, 1.921569, 120, 0, 0), -- Plague Ravager (Area: Lake Mereldar)
(@CGUID+1774, 2110, 0, 1, 1, 1857.496, -4454.208, 74.25906, 2.471124, 120, 0, 0), -- Black Rat (Area: 0)
(@CGUID+1775, 8541, 0, 1, 1, 1948.937, -4448.561, 77.05702, 3.250287, 120, 0, 0), -- Hate Shrieker (Area: 0)
(@CGUID+1776, 8541, 0, 1, 1, 1979.132, -4430.135, 73.62957, 3.781424, 120, 0, 0), -- Hate Shrieker (Area: 0)
(@CGUID+1777, 8525, 0, 1, 1, 1917.74, -4446.883, 79.51269, 2.43622, 120, 0, 0), -- Scourge Warder (Area: 0)
(@CGUID+1778, 8538, 0, 1, 1, 1979.278, -4433.18, 73.62957, 2.334437, 120, 0, 0), -- Unseen Servant (Area: 0)
(@CGUID+1779, 8541, 0, 1, 1, 2024.47, -4430.392, 76.47762, 2.775142, 120, 0, 0), -- Hate Shrieker (Area: Corin's Crossing)
(@CGUID+1780, 8548, 0, 1, 1, 2030.937, -4423.88, 76.47762, 1.450498, 120, 0, 0), -- Vile Tutor (Area: Corin's Crossing) (possible waypoints or random movement)
(@CGUID+1781, 8541, 0, 1, 1, 1987.618, -4454.236, 74.00636, 5.181928, 120, 0, 0), -- Hate Shrieker (Area: Corin's Crossing)
(@CGUID+1782, 8543, 0, 1, 1, 2019.443, -4456.308, 75.47877, 4.765732, 120, 0, 0), -- Stitched Horror (Area: Corin's Crossing)
(@CGUID+1783, 2110, 0, 1, 1, 1968.743, -4460.057, 74.81373, 0.3616204, 120, 0, 0), -- Black Rat (Area: Corin's Crossing)
(@CGUID+1784, 45655, 0, 1, 1, 2021.459, -4375.474, 22.02216, 6.246563, 120, 0, 0), -- Infectis Incher (Area: Corin's Crossing) (possible waypoints or random movement)
(@CGUID+1785, 45655, 0, 1, 1, 2004.118, -4339.564, 10.65844, 5.7116, 120, 0, 0), -- Infectis Incher (Area: Corin's Crossing) (possible waypoints or random movement)
(@CGUID+1786, 45657, 0, 1, 1, 1980.36, -4309.374, 15.19235, 4.314259, 120, 0, 0), -- Infectis Scuttler (Area: Corin's Crossing) (possible waypoints or random movement)
(@CGUID+1787, 8551, 0, 1, 1, 2048.682, -4465.131, 74.99675, 2.433493, 120, 0, 0), -- Dark Summoner (Area: Corin's Crossing) (possible waypoints or random movement)
(@CGUID+1788, 8541, 0, 1, 1, 2058.541, -4455.237, 75.89882, 5.848875, 120, 0, 0), -- Hate Shrieker (Area: Corin's Crossing)
(@CGUID+1789, 8538, 0, 1, 1, 2049.128, -4465.327, 74.99675, 3.965269, 120, 0, 0), -- Unseen Servant (Area: Corin's Crossing)
(@CGUID+1790, 45655, 0, 1, 1, 2017.414, -4331.815, 7.003808, 1.576079, 120, 0, 0), -- Infectis Incher (Area: Corin's Crossing) (possible waypoints or random movement)
(@CGUID+1791, 45650, 0, 1, 1, 2006.577, -4312.588, 12.18643, 5.455906, 120, 0, 0), -- Plague Puffer (Area: Corin's Crossing)
(@CGUID+1792, 45655, 0, 1, 1, 2058.981, -4351.959, 13.53278, 3.474165, 120, 0, 0), -- Infectis Incher (Area: Corin's Crossing) (possible waypoints or random movement)
(@CGUID+1793, 45657, 0, 1, 1, 2056.565, -4340.651, 11.6736, 4.323618, 120, 0, 0), -- Infectis Scuttler (Area: Corin's Crossing) (possible waypoints or random movement)
(@CGUID+1794, 45650, 0, 1, 1, 2063.82, -4324.903, 12.36464, 1.841917, 120, 0, 0), -- Plague Puffer (Area: Corin's Crossing) (possible waypoints or random movement)
(@CGUID+1795, 45650, 0, 1, 1, 2106.709, -4394.127, 23.44907, 1.480321, 120, 0, 0), -- Plague Puffer (Area: Corin's Crossing) (possible waypoints or random movement)
(@CGUID+1796, 8548, 0, 1, 1, 2065.487, -4461.526, 75.89883, 2.858078, 120, 0, 0), -- Vile Tutor (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1797, 8541, 0, 1, 1, 2076.861, -4471.59, 77.25797, 2.716818, 120, 0, 0), -- Hate Shrieker (Area: The Infectis Scar)
(@CGUID+1798, 8541, 0, 1, 1, 2056.273, -4476.884, 75.89586, 1.188155, 120, 0, 0), -- Hate Shrieker (Area: The Infectis Scar)
(@CGUID+1799, 8541, 0, 1, 1, 2087.156, -4449.227, 75.4145, 2.854626, 120, 0, 0), -- Hate Shrieker (Area: The Infectis Scar)
(@CGUID+1800, 45655, 0, 1, 1, 2049.93, -4310.92, 12.86163, 0, 120, 0, 0), -- Infectis Incher (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1801, 45650, 0, 1, 1, 2082.51, -4378.45, 11.75113, 0, 120, 0, 0), -- Plague Puffer (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1802, 45650, 0, 1, 1, 2014.57, -4321.11, 11.97953, 1.322368, 120, 0, 0), -- Plague Puffer (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1803, 45655, 0, 1, 1, 2091.82, -4376.83, 9.876563, 3.593114, 120, 0, 0), -- Infectis Incher (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1804, 45657, 0, 1, 1, 2067.54, -4350.4, 16.27953, 0.1760427, 120, 0, 0), -- Infectis Scuttler (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1805, 11035, 0, 1, 1, 2237.27, -4433.15, 111.8143, 2.076942, 120, 0, 0), -- Betina Bigglezink (Area: The Infectis Scar)
(@CGUID+1806, 47153, 0, 1, 1, 2239.855, -4426.458, 111.731, 0.6503574, 120, 0, 0), -- Cabe Minewell (Area: The Infectis Scar) (possible waypoints or random movement)
(@CGUID+1807, 45655, 0, 1, 1, 2102.82, -4390.35, 15.29713, 5.628145, 120, 0, 0), -- Infectis Incher (Area: The Infectis Scar)
(@CGUID+1808, 45575, 0, 1, 1, 2253.12, -4455.84, 149.4683, 2.670354, 120, 0, 0), -- Frederick Calston (Area: Light's Shield Tower)
(@CGUID+1809, 47060, 0, 1, 1, 2223.67, -4456.69, 111.2403, 3.944444, 120, 0, 0), -- Argent Sentry (Area: Light's Shield Tower)
(@CGUID+1810, 47149, 0, 1, 1, 2252.36, -4456.02, 114.3793, 0.2268928, 120, 0, 0), -- Kathryn Humphries (Area: Light's Shield Tower)
(@CGUID+1811, 47060, 0, 1, 1, 2262.69, -4434.35, 114.3733, 1.64061, 120, 0, 0), -- Argent Sentry (Area: Light's Shield Tower)
(@CGUID+1812, 47060, 0, 1, 1, 2251.02, -4436.12, 114.3733, 1.727876, 120, 0, 0), -- Argent Sentry (Area: Light's Shield Tower)
(@CGUID+1813, 47060, 0, 1, 1, 2247.24, -4445.41, 114.2998, 1.210941, 120, 0, 0), -- Argent Sentry (Area: Light's Shield Tower) (possible waypoints or random movement)
(@CGUID+1814, 47148, 0, 1, 1, 2270.68, -4457.17, 114.3793, 2.86234, 120, 0, 0), -- Donovan Minewell (Area: Light's Shield Tower)
(@CGUID+1815, 8603, 0, 1, 1, 2381.239, -4442.681, 77.5086, 4.328259, 120, 0, 0), -- Carrion Grub (Area: Light's Shield Tower)
(@CGUID+1816, 10779, 0, 1, 1, 2435.927, -4432.08, 74.31487, 0.5549791, 120, 0, 0), -- Infected Squirrel (Area: Light's Shield Tower)
(@CGUID+1817, 8597, 0, 1, 1, 2420.555, -4417.927, 73.95434, 4.280935, 120, 0, 0), -- Plaguehound (Area: Light's Shield Tower)
(@CGUID+1818, 8597, 0, 1, 1, 2457.211, -4439.088, 74.5872, 5.75483, 120, 0, 0), -- Plaguehound (Area: 0)
(@CGUID+1819, 8598, 0, 1, 1, 2547.768, -4463.987, 78.20866, 3.16893, 120, 0, 0), -- Frenzied Plaguehound (Area: 0)
(@CGUID+1820, 8535, 0, 1, 1, 2569.553, -4420.847, 78.25754, 1.10243, 120, 0, 0), -- Putrid Shrieker (Area: 0)
(@CGUID+1821, 10779, 0, 1, 1, 2900.874, -4431.919, 91.89252, 0.7722683, 120, 0, 0), -- Infected Squirrel (Area: 0)
(@CGUID+1822, 10780, 0, 1, 1, 2909.128, -4430.282, 92.63046, 1.001834, 120, 0, 0), -- Infected Deer (Area: 0)
(@CGUID+1823, 2110, 0, 1, 1, 2975.295, -4466.159, 80.03532, 4.54371, 120, 0, 0), -- Black Rat (Area: 0)
(@CGUID+1824, 10780, 0, 1, 1, 3046.902, -4457.272, 101.3319, 4.546598, 120, 0, 0), -- Infected Deer (Area: 0)
(@CGUID+1825, 10780, 0, 1, 1, 3225.103, -4457.878, 110.4403, 0.08014141, 120, 0, 0), -- Infected Deer (Area: Northpass Tower)
(@CGUID+1826, 17878, 0, 1, 1, 3241.56, -4445.92, 110.3655, 6.178465, 120, 0, 0), -- Scourge Siege Engineer (Area: Northpass Tower)
(@CGUID+1827, 17878, 0, 1, 1, 3290.69, -4438.93, 107.2723, 3.752458, 120, 0, 0), -- Scourge Siege Engineer (Area: Northpass Tower)
(@CGUID+1828, 17878, 0, 1, 1, 3269.988, -4454.853, 109.2843, 4.37415, 120, 0, 0), -- Scourge Siege Engineer (Area: Northpass Tower)
(@CGUID+1829, 11706, 0, 1, 1, 3362.563, -4446.573, 127.7459, 3.141593, 120, 0, 0), -- Adon (Area: Northpass Tower)
(@CGUID+1830, 17878, 0, 1, 1, 3254.11, -4536.092, 107.6936, 3.298672, 120, 0, 0), -- Scourge Siege Engineer (Area: 0)
(@CGUID+1831, 17878, 0, 1, 1, 3231.095, -4499.488, 111.6402, 2.321288, 120, 0, 0), -- Scourge Siege Engineer (Area: 0)
(@CGUID+1832, 10780, 0, 1, 1, 3268.964, -4521.973, 109.9538, 3.320224, 120, 0, 0), -- Infected Deer (Area: 0)
(@CGUID+1833, 17878, 0, 1, 1, 3265.746, -4515.555, 108.4271, 1.239184, 120, 0, 0), -- Scourge Siege Engineer (Area: 0)
(@CGUID+1834, 17878, 0, 1, 1, 3189.264, -4543.192, 111.8183, 0.8555011, 120, 0, 0), -- Scourge Siege Engineer (Area: Siege Vise)
(@CGUID+1835, 17878, 0, 1, 1, 3247.595, -4540.93, 107.4652, 1.989675, 120, 0, 0), -- Scourge Siege Engineer (Area: Siege Vise)
(@CGUID+1836, 17878, 0, 1, 1, 3236.418, -4562.581, 106.3026, 1.43117, 120, 0, 0), -- Scourge Siege Engineer (Area: Siege Vise)
(@CGUID+1837, 17878, 0, 1, 1, 3208.601, -4561.11, 107.5146, 2.495821, 120, 0, 0), -- Scourge Siege Engineer (Area: Siege Vise)
(@CGUID+1838, 17878, 0, 1, 1, 3190.966, -4522.219, 109.289, 6.143559, 120, 0, 0), -- Scourge Siege Engineer (Area: Siege Vise)
(@CGUID+1839, 17878, 0, 1, 1, 3188.615, -4486.393, 111.989, 1.610769, 120, 0, 0), -- Scourge Siege Engineer (Area: Siege Vise)
(@CGUID+1840, 8605, 0, 1, 1, 3055.812, -4524.404, 118.6923, 2.880738, 120, 0, 0), -- Carrion Devourer (Area: Siege Vise)
(@CGUID+1841, 10780, 0, 1, 1, 3062.251, -4513.496, 117.1996, 2.501605, 120, 0, 0), -- Infected Deer (Area: Siege Vise)
(@CGUID+1842, 8605, 0, 1, 1, 3085.158, -4492.239, 110.087, 5.984436, 120, 0, 0), -- Carrion Devourer (Area: Siege Vise)
(@CGUID+1843, 8605, 0, 1, 1, 3111.083, -4514.138, 134.5496, 2.267866, 120, 0, 0), -- Carrion Devourer (Area: Siege Vise)
(@CGUID+1844, 8598, 0, 1, 1, 2945.683, -4480.326, 91.1321, 3.477633, 120, 0, 0), -- Frenzied Plaguehound (Area: 0)
(@CGUID+1845, 2110, 0, 1, 1, 2977.872, -4490.603, 76.57147, 0.07959713, 120, 0, 0), -- Black Rat (Area: 0)
(@CGUID+1846, 8605, 0, 1, 1, 3013.405, -4504.623, 97.73022, 2.271896, 120, 0, 0), -- Carrion Devourer (Area: 0)
(@CGUID+1847, 8602, 0, 1, 1, 2983.609, -4509.443, 79.19662, 2.754918, 120, 0, 0), -- Monstrous Plaguebat (Area: 0)
(@CGUID+1848, 8602, 0, 1, 1, 2902.781, -4536.044, 94.12946, 4.65222, 120, 0, 0), -- Monstrous Plaguebat (Area: 0)
(@CGUID+1849, 8605, 0, 1, 1, 2586.652, -4507.576, 95.65354, 5.985836, 120, 0, 0), -- Carrion Devourer (Area: 0)
(@CGUID+1850, 2110, 0, 1, 1, 2567.756, -4506.5, 84.44292, 6.267562, 120, 0, 0), -- Black Rat (Area: 0)
(@CGUID+1851, 2110, 0, 1, 1, 2533.216, -4547.902, 76.38515, 5.730734, 120, 0, 0), -- Black Rat (Area: 0)
(@CGUID+1852, 8601, 0, 1, 1, 2356.36, -4491.282, 74.84813, 2.827872, 120, 0, 0), -- Noxious Plaguebat (Area: 0)
(@CGUID+1853, 8601, 0, 1, 1, 2386.385, -4512.5, 76.71384, 0, 120, 0, 0), -- Noxious Plaguebat (Area: 0)
(@CGUID+1854, 20725, 0, 1, 1, 2388.923, -4517.641, 76.89033, 5.391751, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+1855, 20725, 0, 1, 1, 2397.174, -4482.028, 76.59299, 1.149061, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+1856, 8603, 0, 1, 1, 2409.057, -4504.268, 76.9419, 4.252234, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+1857, 47060, 0, 1, 1, 2230.53, -4470.7, 111.0333, 3.054326, 120, 0, 0), -- Argent Sentry (Area: 0)
(@CGUID+1858, 47060, 0, 1, 1, 2211.49, -4480.65, 98.23404, 3.735005, 120, 0, 0), -- Argent Sentry (Area: Light's Shield Tower)
(@CGUID+1859, 47060, 0, 1, 1, 2180.87, -4509.16, 73.92364, 3.944444, 120, 0, 0), -- Argent Sentry (Area: Light's Shield Tower)
(@CGUID+1860, 47060, 0, 1, 1, 2169.96, -4501.63, 73.70514, 4.712389, 120, 0, 0), -- Argent Sentry (Area: Light's Shield Tower)
(@CGUID+1861, 41178, 0, 1, 1, 2918.316, -3010.901, 180.7847, 0.08726646, 120, 0, 0), -- Northwatch Tower Stalker (Area: Light's Shield Tower)
(@CGUID+1862, 8531, 0, 1, 1, 2116.813, -4480.676, 73.73219, 0.3414391, 120, 0, 0), -- Gibbering Ghoul (Area: Light's Shield Tower)
(@CGUID+1863, 8551, 0, 1, 1, 2095.023, -4509.629, 78.41947, 0.1117519, 120, 0, 0), -- Dark Summoner (Area: Light's Shield Tower) (possible waypoints or random movement)
(@CGUID+1864, 8525, 0, 1, 1, 2123.145, -4522.698, 74.18073, 0.7331303, 120, 0, 0), -- Scourge Warder (Area: Light's Shield Tower)
(@CGUID+1865, 8548, 0, 1, 1, 2076.938, -4513.291, 76.79265, 3.616911, 120, 0, 0), -- Vile Tutor (Area: Light's Shield Tower) (possible waypoints or random movement)
(@CGUID+1866, 8541, 0, 1, 1, 2054.43, -4495.707, 74.81908, 6.184559, 120, 0, 0), -- Hate Shrieker (Area: Light's Shield Tower)
(@CGUID+1867, 8548, 0, 1, 1, 2042.712, -4476.091, 74.80687, 6.232923, 120, 0, 0), -- Vile Tutor (Area: Light's Shield Tower) (possible waypoints or random movement)
(@CGUID+1868, 8526, 0, 1, 1, 2089.682, -4539.388, 75.68983, 5.397659, 120, 0, 0), -- Dark Caster (Area: Light's Shield Tower)
(@CGUID+1869, 8526, 0, 1, 1, 2097.951, -4547.103, 76.47048, 0.4798492, 120, 0, 0), -- Dark Caster (Area: Light's Shield Tower)
(@CGUID+1870, 8531, 0, 1, 1, 2037.306, -4512.287, 73.66428, 3.262105, 120, 0, 0), -- Gibbering Ghoul (Area: Light's Shield Tower)
(@CGUID+1871, 8525, 0, 1, 1, 2018.118, -4485.144, 73.66428, 5.568478, 120, 0, 0), -- Scourge Warder (Area: Light's Shield Tower)
(@CGUID+1872, 45657, 0, 1, 1, 2108.013, -4389.937, 15.66401, 3.444222, 120, 0, 0), -- Infectis Scuttler (Area: Light's Shield Tower) (possible waypoints or random movement)
(@CGUID+1873, 8551, 0, 1, 1, 1996.02, -4489.689, 68.36612, 1.257467, 120, 0, 0), -- Dark Summoner (Area: Corin's Crossing) (possible waypoints or random movement)
(@CGUID+1874, 8541, 0, 1, 1, 1984.375, -4492.326, 82.39228, 4.867505, 120, 0, 0), -- Hate Shrieker (Area: Corin's Crossing)
(@CGUID+1875, 8541, 0, 1, 1, 1989.984, -4493.791, 75.51746, 2.867225, 120, 0, 0), -- Hate Shrieker (Area: Corin's Crossing)
(@CGUID+1876, 8551, 0, 1, 1, 2001.204, -4511.387, 76.03928, 1.973442, 120, 0, 0), -- Dark Summoner (Area: Corin's Crossing) (possible waypoints or random movement)
(@CGUID+1877, 8551, 0, 1, 1, 1969.342, -4479.324, 74.2906, 2.22198, 120, 0, 0), -- Dark Summoner (Area: Corin's Crossing) (possible waypoints or random movement)
(@CGUID+1878, 8551, 0, 1, 1, 1981.484, -4501.934, 75.53441, 0.171538, 120, 0, 0), -- Dark Summoner (Area: Corin's Crossing) (possible waypoints or random movement)
(@CGUID+1879, 8531, 0, 1, 1, 2014.606, -4519.248, 74.01668, 3.99409, 120, 0, 0), -- Gibbering Ghoul (Area: Corin's Crossing)
(@CGUID+1880, 8548, 0, 1, 1, 1973.639, -4503.884, 82.39228, 5.678914, 120, 0, 0), -- Vile Tutor (Area: Corin's Crossing) (possible waypoints or random movement)
(@CGUID+1881, 8526, 0, 1, 1, 1972.291, -4511.438, 74.91124, 3.270945, 120, 0, 0), -- Dark Caster (Area: Corin's Crossing)
(@CGUID+1882, 2110, 0, 1, 1, 2001.45, -4514.23, 75.90756, 2.823902, 120, 0, 0), -- Black Rat (Area: Corin's Crossing)
(@CGUID+1883, 8551, 0, 1, 1, 1965.386, -4512.38, 82.39228, 5.924151, 120, 0, 0), -- Dark Summoner (Area: Corin's Crossing) (possible waypoints or random movement)
(@CGUID+1884, 8541, 0, 1, 1, 1971.466, -4524.873, 82.39228, 4.793444, 120, 0, 0), -- Hate Shrieker (Area: Corin's Crossing)
(@CGUID+1885, 8541, 0, 1, 1, 2013.075, -4542.375, 74.29575, 2.387052, 120, 0, 0), -- Hate Shrieker (Area: Corin's Crossing)
(@CGUID+1886, 8548, 0, 1, 1, 1969.853, -4523.19, 75.53791, 4.402485, 120, 0, 0), -- Vile Tutor (Area: Corin's Crossing) (possible waypoints or random movement)
(@CGUID+1887, 8548, 0, 1, 1, 1981.773, -4532.019, 75.09258, 5.412273, 120, 0, 0), -- Vile Tutor (Area: Corin's Crossing) (possible waypoints or random movement)
(@CGUID+1888, 8541, 0, 1, 1, 1983.314, -4548.03, 73.73612, 4.196262, 120, 0, 0), -- Hate Shrieker (Area: Corin's Crossing)
(@CGUID+1889, 8526, 0, 1, 1, 1949.23, -4526.533, 75.12572, 6.150651, 120, 0, 0), -- Dark Caster (Area: Corin's Crossing)
(@CGUID+1890, 45650, 0, 1, 1, 2011.587, -4375.074, 23.30567, 2.6753, 120, 0, 0), -- Plague Puffer (Area: Corin's Crossing) (possible waypoints or random movement)
(@CGUID+1891, 8525, 0, 1, 1, 1909.111, -4479.389, 79.01487, 4.375825, 120, 0, 0), -- Scourge Warder (Area: Corin's Crossing)
(@CGUID+1892, 8531, 0, 1, 1, 1916.521, -4516.993, 81.58791, 3.902778, 120, 0, 0), -- Gibbering Ghoul (Area: Corin's Crossing)
(@CGUID+1893, 45650, 0, 1, 1, 2018.741, -4357.772, 13.68626, 1.337945, 120, 0, 0), -- Plague Puffer (Area: Corin's Crossing) (possible waypoints or random movement)
(@CGUID+1894, 1843, 0, 1, 1, 1859.188, -4515.175, 76.41712, 2.879793, 120, 0, 0), -- Foreman Jerris (Area: Corin's Crossing)
(@CGUID+1895, 2110, 0, 1, 1, 1852.223, -4508.714, 76.19862, 4.235476, 120, 0, 0), -- Black Rat (Area: Corin's Crossing)
(@CGUID+1896, 8534, 0, 1, 1, 1827.506, -4484.028, 71.34148, 4.758616, 120, 0, 0), -- Putrid Gargoyle (Area: Corin's Crossing)
(@CGUID+1897, 8519, 0, 1, 1, 1724.889, -4481.534, 65.75955, 4.60281, 120, 0, 0), -- Blighted Surge (Area: Corin's Crossing)
(@CGUID+1898, 8534, 0, 1, 1, 1725.26, -4404.896, 77.21171, 5.463937, 120, 0, 0), -- Putrid Gargoyle (Area: Corin's Crossing)
(@CGUID+1899, 8520, 0, 1, 1, 1785.876, -4483.9, 63.78065, 2.990577, 120, 0, 0), -- Plague Ravager (Area: Corin's Crossing)
(@CGUID+1900, 8519, 0, 1, 1, 1807.486, -4525.657, 62.5577, 4.632138, 120, 0, 0), -- Blighted Surge (Area: Corin's Crossing)
(@CGUID+1901, 8520, 0, 1, 1, 1758.168, -4515.275, 41.87824, 5.41413, 120, 0, 0), -- Plague Ravager (Area: Corin's Crossing)
(@CGUID+1902, 8519, 0, 1, 1, 1689.778, -4506.109, 67.62341, 0.549159, 120, 0, 0), -- Blighted Surge (Area: Lake Mereldar)
(@CGUID+1903, 8596, 0, 1, 1, 1554.906, -4553.368, 88.2841, 6.083172, 120, 0, 0), -- Plaguehound Runt (Area: Lake Mereldar)
(@CGUID+1904, 8600, 0, 1, 1, 1574.679, -4533.288, 85.18949, 2.197196, 120, 0, 0), -- Plaguebat (Area: Lake Mereldar)
(@CGUID+1905, 8603, 0, 1, 1, 1579.444, -4578.958, 83.91821, 6.162125, 120, 0, 0), -- Carrion Grub (Area: Lake Mereldar)
(@CGUID+1906, 20725, 0, 1, 1, 1581.106, -4582.338, 84.62, 0.3033923, 120, 0, 0), -- Bat (Area: Lake Mereldar)
(@CGUID+1907, 20725, 0, 1, 1, 1597.233, -4569.002, 82.01538, 3.444633, 120, 0, 0), -- Bat (Area: Lake Mereldar)
(@CGUID+1908, 8534, 0, 1, 1, 1565.464, -4586.151, 88.67515, 1.17841, 120, 0, 0), -- Putrid Gargoyle (Area: Lake Mereldar)
(@CGUID+1909, 8520, 0, 1, 1, 1700.403, -4548.355, 66.31036, 6.1084, 120, 0, 0), -- Plague Ravager (Area: Lake Mereldar)
(@CGUID+1910, 8520, 0, 1, 1, 1647.764, -4608.027, 64.10175, 2.034444, 120, 0, 0), -- Plague Ravager (Area: Lake Mereldar)
(@CGUID+1911, 8520, 0, 1, 1, 1678.125, -4586.459, 71.98004, 3.730688, 120, 0, 0), -- Plague Ravager (Area: Lake Mereldar)
(@CGUID+1912, 8519, 0, 1, 1, 1657.309, -4553.834, 51.41493, 1.734916, 120, 0, 0), -- Blighted Surge (Area: Lake Mereldar)
(@CGUID+1913, 2110, 0, 1, 1, 1718.794, -4591.661, 72.71556, 1.063794, 120, 0, 0), -- Black Rat (Area: Lake Mereldar)
(@CGUID+1914, 8519, 0, 1, 1, 1785.143, -4550.89, 62.67421, 5.317193, 120, 0, 0), -- Blighted Surge (Area: Lake Mereldar)
(@CGUID+1915, 8520, 0, 1, 1, 1755.984, -4583.37, 57.75639, 6.121794, 120, 0, 0), -- Plague Ravager (Area: Lake Mereldar)
(@CGUID+1916, 10779, 0, 1, 1, 1839.224, -4595.592, 73.97707, 5.173038, 120, 0, 0), -- Infected Squirrel (Area: Lake Mereldar)
(@CGUID+1917, 20725, 0, 1, 1, 1857.169, -4574.523, 75.34599, 1.195602, 120, 0, 0), -- Bat (Area: Lake Mereldar)
(@CGUID+1918, 8525, 0, 1, 1, 1915.521, -4544.668, 82.89893, 2.769534, 120, 0, 0), -- Scourge Warder (Area: Lake Mereldar)
(@CGUID+1919, 20725, 0, 1, 1, 1904.59, -4558.263, 85.46515, 5.794459, 120, 0, 0), -- Bat (Area: Lake Mereldar)
(@CGUID+1920, 8525, 0, 1, 1, 1952.757, -4559.042, 75.36527, 4.524343, 120, 0, 0), -- Scourge Warder (Area: Corin's Crossing)
(@CGUID+1921, 8531, 0, 1, 1, 1952.949, -4585.979, 75.63734, 2.986602, 120, 0, 0), -- Gibbering Ghoul (Area: Corin's Crossing)
(@CGUID+1922, 20725, 0, 1, 1, 1917.138, -4588.763, 78.60902, 3.341161, 120, 0, 0), -- Bat (Area: Corin's Crossing)
(@CGUID+1923, 8525, 0, 1, 1, 1986.157, -4580.225, 73.73612, 0.3569297, 120, 0, 0), -- Scourge Warder (Area: Corin's Crossing)
(@CGUID+1924, 8526, 0, 1, 1, 2013.14, -4556.366, 79.72534, 1.933998, 120, 0, 0), -- Dark Caster (Area: Corin's Crossing)
(@CGUID+1925, 8541, 0, 1, 1, 2016.2, -4555.583, 74.98876, 5.844909, 120, 0, 0), -- Hate Shrieker (Area: Corin's Crossing)
(@CGUID+1926, 8548, 0, 1, 1, 2019.996, -4562.186, 74.98248, 2.445903, 120, 0, 0), -- Vile Tutor (Area: Corin's Crossing) (possible waypoints or random movement)
(@CGUID+1927, 8538, 0, 1, 1, 2030.719, -4518.043, 73.66428, 3.372526, 120, 0, 0), -- Unseen Servant (Area: Corin's Crossing)
(@CGUID+1928, 8548, 0, 1, 1, 2029.493, -4542.034, 74.43283, 2.722119, 120, 0, 0), -- Vile Tutor (Area: Corin's Crossing) (possible waypoints or random movement)
(@CGUID+1929, 8543, 0, 1, 1, 2047.771, -4552.107, 74.38725, 3.258268, 120, 0, 0), -- Stitched Horror (Area: Corin's Crossing)
(@CGUID+1930, 8543, 0, 1, 1, 2013.937, -4589.071, 75.55465, 0.6740816, 120, 0, 0), -- Stitched Horror (Area: Corin's Crossing)
(@CGUID+1931, 8543, 0, 1, 1, 2080.366, -4555.162, 73.68983, 4.749531, 120, 0, 0), -- Stitched Horror (Area: Corin's Crossing)
(@CGUID+1932, 8551, 0, 1, 1, 2071.611, -4572.313, 75.88599, 2.219283, 120, 0, 0), -- Dark Summoner (Area: Corin's Crossing) (possible waypoints or random movement)
(@CGUID+1933, 8525, 0, 1, 1, 2051.418, -4590.148, 73.91027, 6.075607, 120, 0, 0), -- Scourge Warder (Area: Corin's Crossing)
(@CGUID+1934, 8541, 0, 1, 1, 2118.044, -4551.677, 75.81739, 0.1376876, 120, 0, 0), -- Hate Shrieker (Area: Corin's Crossing)
(@CGUID+1935, 2110, 0, 1, 1, 2122.917, -4560.416, 74.60767, 4.296844, 120, 0, 0), -- Black Rat (Area: Corin's Crossing)
(@CGUID+1936, 8525, 0, 1, 1, 2118.424, -4581.928, 73.74798, 4.599019, 120, 0, 0), -- Scourge Warder (Area: Corin's Crossing)
(@CGUID+1937, 2110, 0, 1, 1, 2203.221, -4563.437, 74.111, 6.07257, 120, 0, 0), -- Black Rat (Area: Corin's Crossing)
(@CGUID+1938, 2110, 0, 1, 1, 2155.007, -4552.611, 73.73612, 0.8520659, 120, 0, 0), -- Black Rat (Area: Corin's Crossing)
(@CGUID+1939, 8601, 0, 1, 1, 2183.392, -4592.1, 73.73613, 3.239366, 120, 0, 0), -- Noxious Plaguebat (Area: Corin's Crossing)
(@CGUID+1940, 8597, 0, 1, 1, 2221.978, -4551.054, 75.77219, 4.321357, 120, 0, 0), -- Plaguehound (Area: Corin's Crossing)
(@CGUID+1941, 8597, 0, 1, 1, 2283.292, -4557.359, 81.27808, 4.098118, 120, 0, 0), -- Plaguehound (Area: Corin's Crossing)
(@CGUID+1942, 8601, 0, 1, 1, 2331.595, -4546.668, 78.48, 2.792988, 120, 0, 0), -- Noxious Plaguebat (Area: Light's Shield Tower)
(@CGUID+1943, 8603, 0, 1, 1, 2404.26, -4550.767, 74.77932, 0.6671981, 120, 0, 0), -- Carrion Grub (Area: Light's Shield Tower)
(@CGUID+1944, 8602, 0, 1, 1, 2518.645, -4584.995, 75.97568, 3.61237, 120, 0, 0), -- Monstrous Plaguebat (Area: 0)
(@CGUID+1945, 2110, 0, 1, 1, 2533.854, -4557.813, 75.1963, 1.809842, 120, 0, 0), -- Black Rat (Area: 0)
(@CGUID+1946, 8605, 0, 1, 1, 2811.287, -4557.176, 92.35336, 0.3217506, 120, 0, 0), -- Carrion Devourer (Area: 0)
(@CGUID+1947, 8602, 0, 1, 1, 2841.945, -4571.617, 103.9363, 2.117585, 120, 0, 0), -- Monstrous Plaguebat (Area: 0)
(@CGUID+1948, 8605, 0, 1, 1, 2924.305, -4589.97, 86.89677, 3.631895, 120, 0, 0), -- Carrion Devourer (Area: 0)
(@CGUID+1949, 8598, 0, 1, 1, 2950.665, -4557.66, 77.46848, 5.320714, 120, 0, 0), -- Frenzied Plaguehound (Area: 0)
(@CGUID+1950, 17878, 0, 1, 1, 3207.864, -4546.585, 107.3156, 2.605897, 120, 0, 0), -- Scourge Siege Engineer (Area: 0)
(@CGUID+1951, 17878, 0, 1, 1, 3194.494, -4581.548, 107.9486, 3.036686, 120, 0, 0), -- Scourge Siege Engineer (Area: 0)
(@CGUID+1952, 17878, 0, 1, 1, 3264.88, -4554.95, 115.2363, 2.303835, 120, 0, 0), -- Scourge Siege Engineer (Area: 0)
(@CGUID+1953, 17878, 0, 1, 1, 3219.517, -4571.792, 109.8534, 1.43117, 120, 0, 0), -- Scourge Siege Engineer (Area: 0)
(@CGUID+1954, 20725, 0, 1, 1, 3138.988, -4618.735, 103.7589, 3.93075, 120, 0, 0), -- Bat (Area: Siege Vise)
(@CGUID+1955, 8605, 0, 1, 1, 3147.348, -4625.661, 104.0449, 0.293328, 120, 0, 0), -- Carrion Devourer (Area: Siege Vise)
(@CGUID+1956, 10780, 0, 1, 1, 3189.459, -4585.348, 109.2084, 5.912772, 120, 0, 0), -- Infected Deer (Area: Siege Vise)
(@CGUID+1957, 8560, 0, 1, 1, 3190.01, -4642.563, 119.9137, 2.292997, 120, 0, 0), -- Mossflayer Scout (Area: Siege Vise) (possible waypoints or random movement)
(@CGUID+1958, 20725, 0, 1, 1, 3171.945, -4588.205, 107.67, 3.344158, 120, 0, 0), -- Bat (Area: Siege Vise)
(@CGUID+1959, 8561, 0, 1, 1, 3142.545, -4682.348, 107.4423, 1.004942, 120, 0, 0), -- Mossflayer Shadowhunter (Area: 0) (possible waypoints or random movement)
(@CGUID+1960, 2110, 0, 1, 1, 3094.955, -4670.421, 98.91557, 2.566406, 120, 0, 0), -- Black Rat (Area: 0)
(@CGUID+1961, 8605, 0, 1, 1, 3071.96, -4680.133, 98.56013, 5.543399, 120, 0, 0), -- Carrion Devourer (Area: 0)
(@CGUID+1962, 8598, 0, 1, 1, 3012.997, -4626.565, 94.36461, 1.835678, 120, 0, 0), -- Frenzied Plaguehound (Area: 0)
(@CGUID+1963, 8605, 0, 1, 1, 3028.855, -4653.323, 101.3124, 0.1076374, 120, 0, 0), -- Carrion Devourer (Area: 0)
(@CGUID+1964, 8535, 0, 1, 1, 3055.13, -4624.293, 115.1842, 0.6846172, 120, 0, 0), -- Putrid Shrieker (Area: 0)
(@CGUID+1965, 11896, 0, 1, 1, 2928.84, -4617.39, 77.08344, 1.066017, 120, 0, 0), -- Borelgore (Area: 0)
(@CGUID+1966, 8605, 0, 1, 1, 2983.069, -4662.496, 93.7988, 3.692736, 120, 0, 0), -- Carrion Devourer (Area: 0)
(@CGUID+1967, 2110, 0, 1, 1, 2946.303, -4604.205, 75.30302, 0.09976581, 120, 0, 0), -- Black Rat (Area: 0)
(@CGUID+1968, 10780, 0, 1, 1, 2873.725, -4618.966, 90.52086, 4.836744, 120, 0, 0), -- Infected Deer (Area: 0)
(@CGUID+1969, 8602, 0, 1, 1, 2838.183, -4651.192, 94.26532, 3.980881, 120, 0, 0), -- Monstrous Plaguebat (Area: 0)
(@CGUID+1970, 8598, 0, 1, 1, 2875, -4641.666, 88.48412, 5.321435, 120, 0, 0), -- Frenzied Plaguehound (Area: 0)
(@CGUID+1971, 8602, 0, 1, 1, 2806.825, -4598.945, 92.25861, 1.752535, 120, 0, 0), -- Monstrous Plaguebat (Area: 0)
(@CGUID+1972, 8544, 0, 1, 1, 2789.994, -4677.735, 97.97827, 3.600875, 120, 0, 0), -- Gangled Golem (Area: 0)
(@CGUID+1973, 20725, 0, 1, 1, 2750.413, -4599.629, 91.02104, 4.432966, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+1974, 10779, 0, 1, 1, 2744.979, -4602.819, 91.69791, 4.401391, 120, 0, 0), -- Infected Squirrel (Area: 0)
(@CGUID+1975, 8605, 0, 1, 1, 2654.298, -4647.99, 83.31512, 1.174502, 120, 0, 0), -- Carrion Devourer (Area: 0)
(@CGUID+1976, 10779, 0, 1, 1, 2682.298, -4648.973, 82.0427, 5.567223, 120, 0, 0), -- Infected Squirrel (Area: 0)
(@CGUID+1977, 8602, 0, 1, 1, 2709.947, -4652.961, 80.00498, 0.0411061, 120, 0, 0), -- Monstrous Plaguebat (Area: 0)
(@CGUID+1978, 8605, 0, 1, 1, 2558.014, -4620.341, 79.16187, 6.228446, 120, 0, 0), -- Carrion Devourer (Area: 0)
(@CGUID+1979, 10779, 0, 1, 1, 2613.886, -4657.509, 82.1547, 6.100242, 120, 0, 0), -- Infected Squirrel (Area: 0)
(@CGUID+1980, 20725, 0, 1, 1, 2356.931, -4629.876, 77.30769, 2.488835, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+1981, 10780, 0, 1, 1, 2296.376, -4663.388, 75.87744, 1.2166, 120, 0, 0), -- Infected Deer (Area: 0)
(@CGUID+1982, 8543, 0, 1, 1, 2079.531, -4607.264, 75.15726, 0.1017087, 120, 0, 0), -- Stitched Horror (Area: Corin's Crossing)
(@CGUID+1983, 10780, 0, 1, 1, 2090.274, -4647.423, 80.25884, 2.60814, 120, 0, 0), -- Infected Deer (Area: Corin's Crossing)
(@CGUID+1984, 20725, 0, 1, 1, 2049.181, -4651.145, 84.62724, 1.46813, 120, 0, 0), -- Bat (Area: Corin's Crossing)
(@CGUID+1985, 8603, 0, 1, 1, 1846.875, -4648.259, 83.14115, 1.941688, 120, 0, 0), -- Carrion Grub (Area: Corin's Crossing)
(@CGUID+1986, 8596, 0, 1, 1, 1888.656, -4635.416, 89.17318, 0, 120, 0, 0), -- Plaguehound Runt (Area: Corin's Crossing)
(@CGUID+1987, 8520, 0, 1, 1, 1719.768, -4617.902, 56.76321, 0.1807437, 120, 0, 0), -- Plague Ravager (Area: Corin's Crossing)
(@CGUID+1988, 8520, 0, 1, 1, 1747.822, -4648.576, 62.82685, 3.409987, 120, 0, 0), -- Plague Ravager (Area: Corin's Crossing)
(@CGUID+1989, 8519, 0, 1, 1, 1786.037, -4608.835, 69.9012, 4.150937, 120, 0, 0), -- Blighted Surge (Area: Corin's Crossing)
(@CGUID+1990, 8519, 0, 1, 1, 1664.583, -4647.916, 58.76818, 2.880161, 120, 0, 0), -- Blighted Surge (Area: Lake Mereldar)
(@CGUID+1991, 8596, 0, 1, 1, 1545.954, -4612.957, 87.61362, 3.330992, 120, 0, 0), -- Plaguehound Runt (Area: Lake Mereldar)
(@CGUID+1992, 20725, 0, 1, 1, 1609.084, -4624.938, 80.55833, 5.356148, 120, 0, 0), -- Bat (Area: Lake Mereldar)
(@CGUID+1993, 20725, 0, 1, 1, 1660.357, -4685.335, 79.47707, 4.102666, 120, 0, 0), -- Bat (Area: Lake Mereldar)
(@CGUID+1994, 8603, 0, 1, 1, 1609.154, -4678.416, 81.85014, 1.715729, 120, 0, 0), -- Carrion Grub (Area: Lake Mereldar)
(@CGUID+1995, 8600, 0, 1, 1, 1579.829, -4662.884, 81.93169, 1.123734, 120, 0, 0), -- Plaguebat (Area: Lake Mereldar)
(@CGUID+1996, 44775, 0, 1, 1, 1648.22, -4807.15, 86.45583, 5.497751, 120, 0, 0), -- Generic Bunny - PRK (Large AOI) (Area: Lake Mereldar)
(@CGUID+1997, 8519, 0, 1, 1, 1712.778, -4743.142, 64.36954, 0.6534467, 120, 0, 0), -- Blighted Surge (Area: Lake Mereldar)
(@CGUID+1998, 8519, 0, 1, 1, 1686.933, -4716.363, 63.16766, 5.357063, 120, 0, 0), -- Blighted Surge (Area: Lake Mereldar)
(@CGUID+1999, 8519, 0, 1, 1, 1717.57, -4685.402, 52.21797, 5.600205, 120, 0, 0), -- Blighted Surge (Area: Lake Mereldar)
(@CGUID+2000, 8519, 0, 1, 1, 1740.812, -4715.339, 67.21564, 2.893063, 120, 0, 0), -- Blighted Surge (Area: Lake Mereldar)
(@CGUID+2001, 8600, 0, 1, 1, 1816.223, -4691.619, 87.52052, 4.981711, 120, 0, 0), -- Plaguebat (Area: Lake Mereldar)
(@CGUID+2002, 32520, 0, 1, 1, -6305.162, 5582.533, -1172.063, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: 0)
(@CGUID+2003, 32520, 0, 1, 1, -6014.71, 5479.63, -1208.007, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: 0)
(@CGUID+2004, 32520, 0, 1, 1, -5691.65, 5556.92, -1154.687, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: 0)
(@CGUID+2005, 32520, 0, 1, 1, -6148.39, 5539.97, -1207.787, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: 0)
(@CGUID+2006, 8534, 0, 1, 1, 1982.786, -4744.378, 97.23486, 0.00390623, 120, 0, 0), -- Putrid Gargoyle (Area: Corin's Crossing)
(@CGUID+2007, 10780, 0, 1, 1, 2032.922, -4690.257, 85.10742, 0.2587154, 120, 0, 0), -- Infected Deer (Area: Corin's Crossing)
(@CGUID+2008, 8605, 0, 1, 1, 2014.044, -4685.79, 93.65942, 5.081327, 120, 0, 0), -- Carrion Devourer (Area: Corin's Crossing)
(@CGUID+2009, 8605, 0, 1, 1, 2051.721, -4718.034, 80.25475, 1.915793, 120, 0, 0), -- Carrion Devourer (Area: Corin's Crossing)
(@CGUID+2010, 8605, 0, 1, 1, 2093.787, -4692.701, 76.95719, 2.079887, 120, 0, 0), -- Carrion Devourer (Area: Corin's Crossing)
(@CGUID+2011, 8603, 0, 1, 1, 2016.93, -4748.688, 93.35523, 0.7639778, 120, 0, 0), -- Carrion Grub (Area: Corin's Crossing)
(@CGUID+2012, 8603, 0, 1, 1, 2008.627, -4714.882, 96.21909, 0.3801437, 120, 0, 0), -- Carrion Grub (Area: Corin's Crossing)
(@CGUID+2013, 8603, 0, 1, 1, 2127.167, -4721.713, 73.73612, 3.222243, 120, 0, 0), -- Carrion Grub (Area: Corin's Crossing)
(@CGUID+2014, 8605, 0, 1, 1, 2134.228, -4679.595, 77.70269, 3.47359, 120, 0, 0), -- Carrion Devourer (Area: Corin's Crossing)
(@CGUID+2015, 20725, 0, 1, 1, 2186.528, -4708.505, 76.28517, 3.814224, 120, 0, 0), -- Bat (Area: Corin's Crossing)
(@CGUID+2016, 8603, 0, 1, 1, 2217.952, -4755.505, 80.14407, 3.40527, 120, 0, 0), -- Carrion Grub (Area: Corin's Crossing)
(@CGUID+2017, 8601, 0, 1, 1, 2221.607, -4676.207, 73.73613, 1.468754, 120, 0, 0), -- Noxious Plaguebat (Area: Corin's Crossing)
(@CGUID+2018, 8534, 0, 1, 1, 2189.932, -4720.934, 73.7601, 6.001646, 120, 0, 0), -- Putrid Gargoyle (Area: Corin's Crossing)
(@CGUID+2019, 20725, 0, 1, 1, 2305.686, -4677.842, 76.71729, 2.994586, 120, 0, 0), -- Bat (Area: Corin's Crossing)
(@CGUID+2020, 8601, 0, 1, 1, 2279.379, -4681.177, 76.31548, 0.9651899, 120, 0, 0), -- Noxious Plaguebat (Area: Corin's Crossing)
(@CGUID+2021, 20725, 0, 1, 1, 2373.616, -4733.186, 77.68041, 1.664749, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+2022, 8601, 0, 1, 1, 2350.136, -4675.959, 76.43296, 0.9987401, 120, 0, 0), -- Noxious Plaguebat (Area: 0)
(@CGUID+2023, 8597, 0, 1, 1, 2278.502, -4742.323, 96.43614, 4.911891, 120, 0, 0), -- Plaguehound (Area: 0)
(@CGUID+2024, 47060, 0, 1, 1, 2498.58, -4673.28, 76.73373, 1.710423, 120, 0, 0), -- Argent Sentry (Area: 0)
(@CGUID+2025, 47060, 0, 1, 1, 2483.28, -4709.84, 84.55473, 1.343904, 120, 0, 0), -- Argent Sentry (Area: 0)
(@CGUID+2026, 47060, 0, 1, 1, 2481.54, -4672.5, 77.15794, 1.500983, 120, 0, 0), -- Argent Sentry (Area: 0)
(@CGUID+2027, 10779, 0, 1, 1, 2439.615, -4700.65, 78.20172, 1.142065, 120, 0, 0), -- Infected Squirrel (Area: 0)
(@CGUID+2028, 47060, 0, 1, 1, 2496.99, -4706.26, 84.89114, 1.850049, 120, 0, 0), -- Argent Sentry (Area: 0)
(@CGUID+2029, 47060, 0, 1, 1, 2509.98, -4750.71, 97.29553, 1.745329, 120, 0, 0), -- Argent Sentry (Area: 0)
(@CGUID+2030, 47060, 0, 1, 1, 2521.61, -4742.58, 96.46814, 2.251475, 120, 0, 0), -- Argent Sentry (Area: 0)
(@CGUID+2031, 8602, 0, 1, 1, 2608.745, -4675.906, 82.81706, 2.65129, 120, 0, 0), -- Monstrous Plaguebat (Area: 0)
(@CGUID+2032, 8598, 0, 1, 1, 2674.762, -4686.386, 79.36344, 2.662212, 120, 0, 0), -- Frenzied Plaguehound (Area: 0)
(@CGUID+2033, 10779, 0, 1, 1, 2724.874, -4683.237, 77.79111, 3.789783, 120, 0, 0), -- Infected Squirrel (Area: 0)
(@CGUID+2034, 20725, 0, 1, 1, 2707.894, -4691.664, 77.72906, 3.643455, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+2035, 8544, 0, 1, 1, 2773.43, -4723.664, 76.21857, 3.418762, 120, 0, 0), -- Gangled Golem (Area: 0)
(@CGUID+2036, 8527, 0, 1, 1, 2753.614, -4688.3, 78.89418, 2.903357, 120, 0, 0), -- Scourge Guard (Area: 0)
(@CGUID+2037, 8527, 0, 1, 1, 2745.99, -4746.697, 76.71335, 2.136535, 120, 0, 0), -- Scourge Guard (Area: 0)
(@CGUID+2038, 8544, 0, 1, 1, 2742.521, -4713.613, 75.42976, 1.889672, 120, 0, 0), -- Gangled Golem (Area: 0)
(@CGUID+2039, 10779, 0, 1, 1, 2682.216, -4760.073, 84.26775, 0.2995045, 120, 0, 0), -- Infected Squirrel (Area: 0)
(@CGUID+2040, 45744, 0, 1, 1, 2749.956, -4704.225, 78.15346, 1.413991, 120, 0, 0), -- Ix'lar the Underlord (Area: 0)
(@CGUID+2041, 8544, 0, 1, 1, 2813.462, -4690.348, 100.049, 5.039779, 120, 0, 0), -- Gangled Golem (Area: Eastwall Tower)
(@CGUID+2042, 8544, 0, 1, 1, 2789.976, -4742.607, 76.8265, 5.975106, 120, 0, 0), -- Gangled Golem (Area: Ix'lar's Domain)
(@CGUID+2043, 2110, 0, 1, 1, 2852.297, -4739.834, 81.8455, 0.6237695, 120, 0, 0), -- Black Rat (Area: Ix'lar's Domain)
(@CGUID+2044, 8544, 0, 1, 1, 2812.225, -4719.852, 78.19047, 0.3622984, 120, 0, 0), -- Gangled Golem (Area: Ix'lar's Domain)
(@CGUID+2045, 8544, 0, 1, 1, 2847.872, -4693.877, 97.72115, 0.9966586, 120, 0, 0), -- Gangled Golem (Area: Ix'lar's Domain)
(@CGUID+2046, 8544, 0, 1, 1, 2852.582, -4730.585, 81.83213, 2.127395, 120, 0, 0), -- Gangled Golem (Area: Ix'lar's Domain)
(@CGUID+2047, 45743, 0, 1, 1, 2823.025, -4735.656, 75.92362, 5.358161, 120, 0, 0), -- Nerubian Sycophant (Area: Ix'lar's Domain)
(@CGUID+2048, 45743, 0, 1, 1, 2826.7, -4739.577, 76.01031, 2.426008, 120, 0, 0), -- Nerubian Sycophant (Area: Ix'lar's Domain)
(@CGUID+2049, 8527, 0, 1, 1, 2869.002, -4740.111, 83.7877, 6.27342, 120, 0, 0), -- Scourge Guard (Area: Ix'lar's Domain)
(@CGUID+2050, 2110, 0, 1, 1, 2827.957, -4761.906, 82.56995, 5.478453, 120, 0, 0), -- Black Rat (Area: Ix'lar's Domain)
(@CGUID+2051, 45743, 0, 1, 1, 2836.469, -4764.765, 83.15306, 0.3141593, 120, 0, 0), -- Nerubian Sycophant (Area: Ix'lar's Domain)
(@CGUID+2052, 45743, 0, 1, 1, 2840.861, -4762.464, 82.62669, 3.735005, 120, 0, 0), -- Nerubian Sycophant (Area: Ix'lar's Domain)
(@CGUID+2053, 8544, 0, 1, 1, 2886.885, -4716.61, 96.41121, 4.198555, 120, 0, 0), -- Gangled Golem (Area: Ix'lar's Domain)
(@CGUID+2054, 20725, 0, 1, 1, 3014.188, -4714.318, 94.53377, 6.030934, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+2055, 8598, 0, 1, 1, 2939.176, -4681.466, 96.7952, 3.074418, 120, 0, 0), -- Frenzied Plaguehound (Area: 0)
(@CGUID+2056, 8605, 0, 1, 1, 2939.434, -4742.454, 91.66493, 5.068088, 120, 0, 0), -- Carrion Devourer (Area: 0)
(@CGUID+2057, 8602, 0, 1, 1, 3036.136, -4690.87, 94.9538, 2.996518, 120, 0, 0), -- Monstrous Plaguebat (Area: 0)
(@CGUID+2058, 8598, 0, 1, 1, 3020.283, -4738.378, 93.93557, 0.7316471, 120, 0, 0), -- Frenzied Plaguehound (Area: 0)
(@CGUID+2059, 20725, 0, 1, 1, 3045.181, -4720.291, 95.77087, 3.564979, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+2060, 8602, 0, 1, 1, 3053.319, -4710.718, 95.49998, 1.171127, 120, 0, 0), -- Monstrous Plaguebat (Area: 0)
(@CGUID+2061, 2110, 0, 1, 1, 3184.067, -4732.752, 116.1141, 4.993371, 120, 0, 0), -- Black Rat (Area: 0)
(@CGUID+2062, 8561, 0, 1, 1, 3179.167, -4737.5, 119.4282, 0.7981945, 120, 0, 0), -- Mossflayer Shadowhunter (Area: 0) (possible waypoints or random movement)
(@CGUID+2063, 10780, 0, 1, 1, 3096.244, -4762.438, 97.81738, 5.494332, 120, 0, 0), -- Infected Deer (Area: 0)
(@CGUID+2064, 8561, 0, 1, 1, 3225.571, -4722.764, 154.7115, 6.213372, 120, 0, 0), -- Mossflayer Shadowhunter (Area: Zul'Mashar)
(@CGUID+2065, 8560, 0, 1, 1, 3280.855, -4835.831, 171.1441, 0.03490658, 120, 0, 0), -- Mossflayer Scout (Area: Zul'Mashar)
(@CGUID+2066, 8560, 0, 1, 1, 3284.997, -4835.999, 170.6486, 3.01942, 120, 0, 0), -- Mossflayer Scout (Area: Zul'Mashar)
(@CGUID+2067, 8561, 0, 1, 1, 3326.463, -4847.07, 167.0214, 0.378282, 120, 0, 0), -- Mossflayer Shadowhunter (Area: Zul'Mashar) (possible waypoints or random movement)
(@CGUID+2068, 8561, 0, 1, 1, 3248.011, -4800.249, 172.0516, 4.966083, 120, 0, 0), -- Mossflayer Shadowhunter (Area: Zul'Mashar) (possible waypoints or random movement)
(@CGUID+2069, 8562, 0, 1, 1, 3401.05, -4863.646, 168.1977, 0, 120, 0, 0), -- Mossflayer Cannibal (Area: Zul'Mashar)
(@CGUID+2070, 8560, 0, 1, 1, 3405.156, -4863.622, 168.1977, 3.159046, 120, 0, 0), -- Mossflayer Scout (Area: Zul'Mashar)
(@CGUID+2071, 8562, 0, 1, 1, 3410.491, -4849.398, 167.7906, 1.697556, 120, 0, 0), -- Mossflayer Cannibal (Area: Zul'Mashar) (possible waypoints or random movement)
(@CGUID+2072, 10823, 0, 1, 1, 3378.617, -4873.068, 159.3349, 3.804818, 120, 0, 0), -- Zul'Brin Warpbranch (Area: Zul'Mashar)
(@CGUID+2073, 8561, 0, 1, 1, 3335.393, -4881.759, 159.3775, 5.94008, 120, 0, 0), -- Mossflayer Shadowhunter (Area: Zul'Mashar) (possible waypoints or random movement)
(@CGUID+2074, 8562, 0, 1, 1, 3373.004, -4848.45, 167.0968, 4.345846, 120, 0, 0), -- Mossflayer Cannibal (Area: Zul'Mashar) (possible waypoints or random movement)
(@CGUID+2075, 8562, 0, 1, 1, 3251.817, -4776.688, 170.0316, 0.6569834, 120, 0, 0), -- Mossflayer Cannibal (Area: Zul'Mashar) (possible waypoints or random movement)
(@CGUID+2076, 8535, 0, 1, 1, 3100.115, -4822.313, 100.4683, 5.42048, 120, 0, 0), -- Putrid Shrieker (Area: Zul'Mashar)
(@CGUID+2077, 8602, 0, 1, 1, 3046.671, -4792.82, 97.13369, 4.463447, 120, 0, 0), -- Monstrous Plaguebat (Area: Zul'Mashar)
(@CGUID+2078, 2110, 0, 1, 1, 3008.239, -4832.48, 99.84279, 1.681346, 120, 0, 0), -- Black Rat (Area: 0)
(@CGUID+2079, 8602, 0, 1, 1, 2966.292, -4773.937, 95.00809, 2.986963, 120, 0, 0), -- Monstrous Plaguebat (Area: 0)
(@CGUID+2080, 8598, 0, 1, 1, 2937.793, -4796.926, 96.48388, 2.566109, 120, 0, 0), -- Frenzied Plaguehound (Area: 0)
(@CGUID+2081, 8605, 0, 1, 1, 2885.375, -4826.038, 100.8821, 5.725518, 120, 0, 0), -- Carrion Devourer (Area: 0)
(@CGUID+2082, 8605, 0, 1, 1, 2924.152, -4846.42, 105.6705, 0.01367102, 120, 0, 0), -- Carrion Devourer (Area: 0)
(@CGUID+2083, 8527, 0, 1, 1, 2880.702, -4785.001, 94.60274, 1.82819, 120, 0, 0), -- Scourge Guard (Area: 0)
(@CGUID+2084, 8598, 0, 1, 1, 2928.163, -4780.265, 97.23607, 0.4789303, 120, 0, 0), -- Frenzied Plaguehound (Area: 0)
(@CGUID+2085, 20725, 0, 1, 1, 2923.196, -4793.675, 97.30321, 0.934067, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+2086, 8544, 0, 1, 1, 2812.737, -4787.722, 96.94975, 3.298023, 120, 0, 0), -- Gangled Golem (Area: Ix'lar's Domain)
(@CGUID+2087, 8535, 0, 1, 1, 2858.171, -4843.256, 97.98617, 3.970598, 120, 0, 0), -- Putrid Shrieker (Area: Ix'lar's Domain)
(@CGUID+2088, 8527, 0, 1, 1, 2814.358, -4815.589, 93.51538, 1.541508, 120, 0, 0), -- Scourge Guard (Area: Ix'lar's Domain)
(@CGUID+2089, 10779, 0, 1, 1, 2844.368, -4838.826, 96.69125, 1.40308, 120, 0, 0), -- Infected Squirrel (Area: Ix'lar's Domain)
(@CGUID+2090, 8544, 0, 1, 1, 2804.767, -4836.922, 96.68937, 0.3704924, 120, 0, 0), -- Gangled Golem (Area: Ix'lar's Domain)
(@CGUID+2091, 8598, 0, 1, 1, 2831.037, -4857.129, 98.98972, 0.3446002, 120, 0, 0), -- Frenzied Plaguehound (Area: Ix'lar's Domain)
(@CGUID+2092, 20725, 0, 1, 1, 2835.641, -4851.726, 100.5158, 5.360979, 120, 0, 0), -- Bat (Area: Ix'lar's Domain)
(@CGUID+2093, 8527, 0, 1, 1, 2776.738, -4785.434, 79.9928, 0.2608667, 120, 0, 0), -- Scourge Guard (Area: Ix'lar's Domain)
(@CGUID+2094, 45743, 0, 1, 1, 2779.049, -4805.745, 80.21523, 4.555309, 120, 0, 0), -- Nerubian Sycophant (Area: Ix'lar's Domain)
(@CGUID+2095, 45743, 0, 1, 1, 2777.458, -4811.479, 79.99988, 1.43117, 120, 0, 0), -- Nerubian Sycophant (Area: Ix'lar's Domain)
(@CGUID+2096, 8544, 0, 1, 1, 2759.524, -4812.818, 77.7467, 4.734221, 120, 0, 0), -- Gangled Golem (Area: Ix'lar's Domain)
(@CGUID+2097, 8527, 0, 1, 1, 2746.884, -4780.274, 76.09071, 5.380101, 120, 0, 0), -- Scourge Guard (Area: Ix'lar's Domain)
(@CGUID+2098, 2110, 0, 1, 1, 2756.223, -4818.252, 78.24672, 2.936233, 120, 0, 0), -- Black Rat (Area: Ix'lar's Domain)
(@CGUID+2099, 8598, 0, 1, 1, 2712.869, -4842.552, 85.06635, 5.398874, 120, 0, 0), -- Frenzied Plaguehound (Area: Ix'lar's Domain)
(@CGUID+2100, 8527, 0, 1, 1, 2742.92, -4857.358, 95.12688, 3.484939, 120, 0, 0), -- Scourge Guard (Area: Ix'lar's Domain)
(@CGUID+2101, 8544, 0, 1, 1, 2752.087, -4835.242, 80.51299, 5.223268, 120, 0, 0), -- Gangled Golem (Area: Ix'lar's Domain)
(@CGUID+2102, 47142, 0, 1, 1, 2555.87, -4803.94, 108.9083, 0.9773844, 120, 0, 0), -- Rahmalaha (Area: Eastwall Tower)
(@CGUID+2103, 47144, 0, 1, 1, 2567.37, -4803.67, 108.9123, 1.902409, 120, 0, 0), -- Patricia Marshall (Area: Eastwall Tower)
(@CGUID+2104, 44240, 0, 1, 1, 2528.22, -4775.45, 104.5493, 1.710423, 120, 0, 0), -- Argent Hippogryph (Area: Eastwall Tower)
(@CGUID+2105, 45735, 0, 1, 1, 2545.14, -4769.8, 105.6803, 2.984513, 120, 0, 0), -- Gamella Cracklefizz (Area: Eastwall Tower)
(@CGUID+2106, 47060, 0, 1, 1, 2553.01, -4778.34, 108.9023, 2.530727, 120, 0, 0), -- Argent Sentry (Area: Eastwall Tower)
(@CGUID+2107, 47060, 0, 1, 1, 2543.79, -4786.8, 108.9023, 1.745329, 120, 0, 0), -- Argent Sentry (Area: Eastwall Tower)
(@CGUID+2108, 47060, 0, 1, 1, 2546.53, -4796.18, 108.8177, 4.557021, 120, 0, 0), -- Argent Sentry (Area: Eastwall Tower) (possible waypoints or random movement)
(@CGUID+2109, 10780, 0, 1, 1, 2484.024, -4841.52, 77.20746, 1.921569, 120, 0, 0), -- Infected Deer (Area: Eastwall Tower)
(@CGUID+2110, 8598, 0, 1, 1, 2466.38, -4806.969, 77.21787, 2.694989, 120, 0, 0), -- Frenzied Plaguehound (Area: Eastwall Tower)
(@CGUID+2111, 44230, 0, 1, 1, 2526.09, -4772.52, 104.3213, 1.884956, 120, 0, 0), -- Richard Trueflight (Area: Eastwall Tower)
(@CGUID+2112, 45736, 0, 1, 1, 2508.46, -4756.73, 99.03164, 1.672558, 120, 0, 0), -- Deacon Andaal (Area: Eastwall Tower) (possible waypoints or random movement)
(@CGUID+2113, 8601, 0, 1, 1, 2344.902, -4832.933, 95.1301, 3.266917, 120, 0, 0), -- Noxious Plaguebat (Area: 0)
(@CGUID+2114, 10779, 0, 1, 1, 2369.784, -4822.045, 81.13313, 4.256553, 120, 0, 0), -- Infected Squirrel (Area: 0)
(@CGUID+2115, 20725, 0, 1, 1, 2343.407, -4809.892, 90.69779, 3.001874, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+2116, 8603, 0, 1, 1, 2338.666, -4762.57, 84.47165, 1.322973, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+2117, 8603, 0, 1, 1, 2217.804, -4807.355, 108.5443, 4.846684, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+2118, 8597, 0, 1, 1, 2289.438, -4831.373, 112.7127, 4.497747, 120, 0, 0), -- Plaguehound (Area: 0)
(@CGUID+2119, 8601, 0, 1, 1, 2254.902, -4786.202, 115.9043, 4.57519, 120, 0, 0), -- Noxious Plaguebat (Area: 0)
(@CGUID+2120, 8601, 0, 1, 1, 2183.035, -4787.491, 101.0069, 4.318649, 120, 0, 0), -- Noxious Plaguebat (Area: 0)
(@CGUID+2121, 20725, 0, 1, 1, 2174.033, -4816.38, 110.108, 4.066257, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+2122, 8605, 0, 1, 1, 2077.372, -4753.64, 74.67876, 4.198162, 120, 0, 0), -- Carrion Devourer (Area: 0)
(@CGUID+2123, 8601, 0, 1, 1, 2152.533, -4761.185, 76.41215, 1.696351, 120, 0, 0), -- Noxious Plaguebat (Area: 0)
(@CGUID+2124, 8603, 0, 1, 1, 2065.217, -4805.176, 74.06706, 2.812399, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+2125, 8603, 0, 1, 1, 2010.691, -4810.309, 81.24617, 0.007268533, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+2126, 2110, 0, 1, 1, 2055.221, -4773.401, 81.27774, 2.046969, 120, 0, 0), -- Black Rat (Area: 0)
(@CGUID+2127, 8603, 0, 1, 1, 2060.764, -4793.652, 77.33295, 2.242794, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+2128, 8605, 0, 1, 1, 1929.001, -4820.631, 106.0188, 1.674099, 120, 0, 0), -- Carrion Devourer (Area: 0)
(@CGUID+2129, 8605, 0, 1, 1, 1961.979, -4815.104, 97.17807, 3.478515, 120, 0, 0), -- Carrion Devourer (Area: 0)
(@CGUID+2130, 8603, 0, 1, 1, 1974.446, -4837.121, 94.77273, 5.20137, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+2131, 10780, 0, 1, 1, 1980.838, -4821.253, 92.75636, 2.55359, 120, 0, 0), -- Infected Deer (Area: 0)
(@CGUID+2132, 20725, 0, 1, 1, 1953.794, -4821.208, 101.1078, 2.570308, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+2133, 8605, 0, 1, 1, 1956.029, -4765.292, 98.34273, 1.246574, 120, 0, 0), -- Carrion Devourer (Area: 0)
(@CGUID+2134, 20725, 0, 1, 1, 1929.871, -4766.43, 98.85076, 0.7988443, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+2135, 20725, 0, 1, 1, 1895.08, -4825.984, 110.132, 0.8173404, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+2136, 8603, 0, 1, 1, 1867.355, -4822.081, 110.7496, 3.365978, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+2137, 8600, 0, 1, 1, 1752.147, -4822.816, 92.77836, 1.086807, 120, 0, 0), -- Plaguebat (Area: 0)
(@CGUID+2138, 10779, 0, 1, 1, 1759.324, -4742.052, 78.38428, 0.2660379, 120, 0, 0), -- Infected Squirrel (Area: 0)
(@CGUID+2139, 8548, 0, 1, 1, 1660.83, -4815.26, 86.49804, 2.617994, 120, 0, 0), -- Vile Tutor (Area: Lake Mereldar)
(@CGUID+2140, 8548, 0, 1, 1, 1660.24, -4801.75, 84.89374, 3.665191, 120, 0, 0), -- Vile Tutor (Area: Lake Mereldar)
(@CGUID+2141, 8548, 0, 1, 1, 1660.61, -4813.16, 86.16863, 2.75762, 120, 0, 0), -- Vile Tutor (Area: Lake Mereldar)
(@CGUID+2142, 8551, 0, 1, 1, 1661.58, -4803.6, 85.08974, 3.508112, 120, 0, 0), -- Dark Summoner (Area: Lake Mereldar)
(@CGUID+2143, 8551, 0, 1, 1, 1654.449, -4822.739, 86.53824, 2.250269, 120, 0, 0), -- Dark Summoner (Area: Lake Mereldar) (possible waypoints or random movement)
(@CGUID+2144, 8551, 0, 1, 1, 1635.69, -4810.33, 85.10313, 0.122173, 120, 0, 0), -- Dark Summoner (Area: Lake Mereldar)
(@CGUID+2145, 8548, 0, 1, 1, 1627.893, -4802.2, 87.78657, 4.63492, 120, 0, 0), -- Vile Tutor (Area: Lake Mereldar) (possible waypoints or random movement)
(@CGUID+2146, 8551, 0, 1, 1, 1645.92, -4797.12, 84.82285, 4.937481, 120, 0, 0), -- Dark Summoner (Area: Lake Mereldar)
(@CGUID+2147, 8551, 0, 1, 1, 1617.04, -4782.71, 89.96254, 1.605703, 120, 0, 0), -- Dark Summoner (Area: Lake Mereldar)
(@CGUID+2148, 8548, 0, 1, 1, 1639.612, -4832.191, 86.30006, 0.01562373, 120, 0, 0), -- Vile Tutor (Area: Death Cultist Base Camp) (possible waypoints or random movement)
(@CGUID+2149, 8551, 0, 1, 1, 1635.41, -4818.77, 85.15314, 0.6457718, 120, 0, 0), -- Dark Summoner (Area: Death Cultist Base Camp)
(@CGUID+2150, 8603, 0, 1, 1, 1646.1, -4910.77, 89.01237, 0.2106157, 120, 0, 0), -- Carrion Grub (Area: Death Cultist Base Camp)
(@CGUID+2151, 8596, 0, 1, 1, 1679.541, -4894.58, 86.59866, 2.258643, 120, 0, 0), -- Plaguehound Runt (Area: Death Cultist Base Camp)
(@CGUID+2152, 20725, 0, 1, 1, 1702.374, -4874.795, 92.48663, 3.421352, 120, 0, 0), -- Bat (Area: Death Cultist Base Camp)
(@CGUID+2153, 8603, 0, 1, 1, 1850.479, -4846.586, 102.2905, 5.213924, 120, 0, 0), -- Carrion Grub (Area: Death Cultist Base Camp)
(@CGUID+2154, 20725, 0, 1, 1, 1760.6, -4915.159, 92.30212, 2.679471, 120, 0, 0), -- Bat (Area: Death Cultist Base Camp)
(@CGUID+2155, 10780, 0, 1, 1, 1858.797, -4865.158, 101.9105, 2.968783, 120, 0, 0), -- Infected Deer (Area: Death Cultist Base Camp)
(@CGUID+2156, 8603, 0, 1, 1, 1853.004, -4901.47, 85.55141, 5.625226, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+2157, 8603, 0, 1, 1, 1917.691, -4841.497, 104.7048, 3.13964, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+2158, 8605, 0, 1, 1, 1947.374, -4868.463, 93.49246, 4.856357, 120, 0, 0), -- Carrion Devourer (Area: 0)
(@CGUID+2159, 8603, 0, 1, 1, 1917.463, -4899.479, 86.01384, 3.141593, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+2160, 8603, 0, 1, 1, 1941.049, -4872.889, 93.21756, 3.21784, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+2161, 8605, 0, 1, 1, 1889.973, -4870.919, 97.42274, 1.026218, 120, 0, 0), -- Carrion Devourer (Area: 0)
(@CGUID+2162, 8605, 0, 1, 1, 1985.453, -4912.57, 76.40794, 1.777387, 120, 0, 0), -- Carrion Devourer (Area: 0)
(@CGUID+2163, 8603, 0, 1, 1, 2045.563, -4845.624, 75.01101, 4.631295, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+2164, 8605, 0, 1, 1, 2012.779, -4887.2, 75.06662, 4.325212, 120, 0, 0), -- Carrion Devourer (Area: 0)
(@CGUID+2165, 8603, 0, 1, 1, 2083.172, -4887.673, 77.76235, 5.756447, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+2166, 8597, 0, 1, 1, 2153.573, -4901.814, 89.80762, 1.557125, 120, 0, 0), -- Plaguehound (Area: 0)
(@CGUID+2167, 8601, 0, 1, 1, 2201.38, -4859.313, 87.59413, 5.861147, 120, 0, 0), -- Noxious Plaguebat (Area: 0)
(@CGUID+2168, 8601, 0, 1, 1, 2195.218, -4891.396, 84.48813, 6.171666, 120, 0, 0), -- Noxious Plaguebat (Area: 0)
(@CGUID+2169, 20725, 0, 1, 1, 2199.678, -4869.227, 85.48595, 5.464372, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+2170, 8601, 0, 1, 1, 2324.552, -4867.175, 88.25323, 4.928939, 120, 0, 0), -- Noxious Plaguebat (Area: 0)
(@CGUID+2171, 8603, 0, 1, 1, 2281.108, -4879.2, 102.3115, 1.686195, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+2172, 10780, 0, 1, 1, 2307.369, -4865.965, 95.13183, 1.541791, 120, 0, 0), -- Infected Deer (Area: 0)
(@CGUID+2173, 8601, 0, 1, 1, 2329.539, -4888.551, 85.44148, 3.276694, 120, 0, 0), -- Noxious Plaguebat (Area: 0)
(@CGUID+2174, 10780, 0, 1, 1, 2481.521, -4889.912, 76.19025, 3.378145, 120, 0, 0), -- Infected Deer (Area: 0)
(@CGUID+2175, 8598, 0, 1, 1, 2479.343, -4882.595, 74.33527, 2.895741, 120, 0, 0), -- Frenzied Plaguehound (Area: 0)
(@CGUID+2176, 8598, 0, 1, 1, 2549.932, -4886.253, 74.4737, 5.530469, 120, 0, 0), -- Frenzied Plaguehound (Area: Eastwall Tower)
(@CGUID+2177, 8598, 0, 1, 1, 2601.607, -4888.012, 76.02795, 3.227654, 120, 0, 0), -- Frenzied Plaguehound (Area: Eastwall Tower)
(@CGUID+2178, 10779, 0, 1, 1, 2710.884, -4857.759, 87.07835, 0.5169653, 120, 0, 0), -- Infected Squirrel (Area: Eastwall Tower)
(@CGUID+2179, 8535, 0, 1, 1, 2681.287, -4776.268, 88.2705, 1.235863, 120, 0, 0), -- Putrid Shrieker (Area: Eastwall Tower)
(@CGUID+2180, 8544, 0, 1, 1, 2771.19, -4869.245, 99.01656, 1.958572, 120, 0, 0), -- Gangled Golem (Area: Eastwall Tower)
(@CGUID+2181, 8598, 0, 1, 1, 2800.894, -4869.675, 100.864, 3.656377, 120, 0, 0), -- Frenzied Plaguehound (Area: Eastwall Tower)
(@CGUID+2182, 10780, 0, 1, 1, 2941.49, -4861.102, 105.9012, 4.749143, 120, 0, 0), -- Infected Deer (Area: Ix'lar's Domain)
(@CGUID+2183, 10780, 0, 1, 1, 2956.769, -4872.82, 106.3294, 2.155531, 120, 0, 0), -- Infected Deer (Area: 0)
(@CGUID+2184, 8540, 0, 1, 1, 3014.266, -4864.045, 101.1458, 4.616855, 120, 0, 0), -- Torn Screamer (Area: 0)
(@CGUID+2185, 8540, 0, 1, 1, 2969.623, -4875.553, 105.9525, 6.044602, 120, 0, 0), -- Torn Screamer (Area: 0)
(@CGUID+2186, 8540, 0, 1, 1, 3056.18, -4883.281, 105.9262, 2.498017, 120, 0, 0), -- Torn Screamer (Area: 0)
(@CGUID+2187, 8560, 0, 1, 1, 3292.357, -4846.529, 169.3994, 0.05581083, 120, 0, 0), -- Mossflayer Scout (Area: Zul'Mashar) (possible waypoints or random movement)
(@CGUID+2188, 8560, 0, 1, 1, 3399.519, -4849.671, 166.5222, 6.054544, 120, 0, 0), -- Mossflayer Scout (Area: Zul'Mashar) (possible waypoints or random movement)
(@CGUID+2189, 8562, 0, 1, 1, 3454.167, -4887.5, 167.9245, 0.5053353, 120, 0, 0), -- Mossflayer Cannibal (Area: Zul'Mashar) (possible waypoints or random movement)
(@CGUID+2190, 8562, 0, 1, 1, 3421.961, -4904.968, 159.3442, 3.176499, 120, 0, 0), -- Mossflayer Cannibal (Area: Zul'Mashar)
(@CGUID+2191, 8562, 0, 1, 1, 3413.789, -4900.17, 159.4951, 5.270895, 120, 0, 0), -- Mossflayer Cannibal (Area: Zul'Mashar)
(@CGUID+2192, 8560, 0, 1, 1, 3461.628, -4914.651, 170.5387, 4.223697, 120, 0, 0), -- Mossflayer Scout (Area: Zul'Mashar)
(@CGUID+2193, 8561, 0, 1, 1, 3460.559, -4919.147, 170.5387, 1.710423, 120, 0, 0), -- Mossflayer Shadowhunter (Area: Zul'Mashar)
(@CGUID+2194, 8562, 0, 1, 1, 3410.662, -4908.063, 159.4148, 0.715585, 120, 0, 0), -- Mossflayer Cannibal (Area: Zul'Mashar)
(@CGUID+2195, 8561, 0, 1, 1, 3459.292, -4934.355, 171.8951, 4.782202, 120, 0, 0), -- Mossflayer Shadowhunter (Area: Zul'Mashar)
(@CGUID+2196, 8561, 0, 1, 1, 3460.188, -4946.898, 182.5894, 4.782202, 120, 0, 0), -- Mossflayer Shadowhunter (Area: Zul'Mashar)
(@CGUID+2197, 8560, 0, 1, 1, 3422.39, -4946.37, 164.1023, 2.391101, 120, 0, 0), -- Mossflayer Scout (Area: Zul'Mashar)
(@CGUID+2198, 8561, 0, 1, 1, 3462.649, -4959.521, 189.9406, 4.747295, 120, 0, 0), -- Mossflayer Shadowhunter (Area: Zul'Mashar)
(@CGUID+2199, 8562, 0, 1, 1, 3377.775, -4912.951, 159.5669, 2.995224, 120, 0, 0), -- Mossflayer Cannibal (Area: Zul'Mashar) (possible waypoints or random movement)
(@CGUID+2200, 8562, 0, 1, 1, 3402.966, -4947.032, 164.0169, 5.420203, 120, 0, 0), -- Mossflayer Cannibal (Area: Zul'Mashar) (possible waypoints or random movement)
(@CGUID+2201, 8561, 0, 1, 1, 3461.955, -4971.201, 197.9484, 4.764749, 120, 0, 0), -- Mossflayer Shadowhunter (Area: Zul'Mashar)
(@CGUID+2202, 10822, 0, 1, 1, 3439.25, -4980.96, 195.8113, 2.321288, 120, 0, 0), -- Warlord Thresh'jin (Area: Zul'Mashar)
(@CGUID+2203, 8560, 0, 1, 1, 3402.42, -4966.38, 164.1763, 2.146755, 120, 0, 0), -- Mossflayer Scout (Area: Zul'Mashar)
(@CGUID+2204, 8561, 0, 1, 1, 3492.421, -4974.963, 184.0252, 3.961897, 120, 0, 0), -- Mossflayer Shadowhunter (Area: Zul'Mashar)
(@CGUID+2205, 8560, 0, 1, 1, 3380.913, -4965.199, 159.5185, 1.310572, 120, 0, 0), -- Mossflayer Scout (Area: Zul'Mashar) (possible waypoints or random movement)
(@CGUID+2206, 8562, 0, 1, 1, 3330.66, -4934.278, 170.7607, 4.607669, 120, 0, 0), -- Mossflayer Cannibal (Area: Zul'Mashar)
(@CGUID+2207, 8562, 0, 1, 1, 3330.301, -4938.93, 170.7607, 1.53589, 120, 0, 0), -- Mossflayer Cannibal (Area: Zul'Mashar)
(@CGUID+2208, 8561, 0, 1, 1, 3361.141, -4952.689, 159.5835, 4.066617, 120, 0, 0), -- Mossflayer Shadowhunter (Area: Zul'Mashar)
(@CGUID+2209, 8561, 0, 1, 1, 3356.993, -4958.692, 159.7383, 0.9948376, 120, 0, 0), -- Mossflayer Shadowhunter (Area: Zul'Mashar)
(@CGUID+2210, 8562, 0, 1, 1, 3316.481, -4952.544, 170.1445, 4.669254, 120, 0, 0), -- Mossflayer Cannibal (Area: Zul'Mashar) (possible waypoints or random movement)
(@CGUID+2211, 8562, 0, 1, 1, 3309.513, -4956.514, 171.1979, 3.477616, 120, 0, 0), -- Mossflayer Cannibal (Area: Zul'Mashar) (possible waypoints or random movement)
(@CGUID+2212, 8540, 0, 1, 1, 3074.129, -4896.831, 100.5851, 5.66856, 120, 0, 0), -- Torn Screamer (Area: Northdale)
(@CGUID+2213, 2110, 0, 1, 1, 3019.172, -4917.201, 100.83, 3.546537, 120, 0, 0), -- Black Rat (Area: Northdale)
(@CGUID+2214, 8537, 0, 1, 1, 3027.076, -4886.303, 101.4505, 0.9116078, 120, 0, 0), -- Interloper (Area: Northdale)
(@CGUID+2215, 8540, 0, 1, 1, 3002.658, -4922.366, 104.5488, 1.426569, 120, 0, 0), -- Torn Screamer (Area: Northdale)
(@CGUID+2216, 8540, 0, 1, 1, 2999.848, -4895.425, 108.4062, 2.263783, 120, 0, 0), -- Torn Screamer (Area: Northdale)
(@CGUID+2217, 8521, 0, 1, 1, 2951.91, -4913.763, 101.6954, 6.240371, 120, 0, 0), -- Blighted Horror (Area: Northdale) (possible waypoints or random movement)
(@CGUID+2218, 10779, 0, 1, 1, 2844.727, -4925.868, 106.8857, 0.3587399, 120, 0, 0), -- Infected Squirrel (Area: 0)
(@CGUID+2219, 10779, 0, 1, 1, 2624.75, -4906.136, 80.50393, 5.476798, 120, 0, 0), -- Infected Squirrel (Area: Eastwall Tower)
(@CGUID+2220, 8605, 0, 1, 1, 2586.916, -4904.247, 76.03855, 1.506307, 120, 0, 0), -- Carrion Devourer (Area: Eastwall Tower)
(@CGUID+2221, 8535, 0, 1, 1, 2515.3, -4889.277, 78.26606, 2.530177, 120, 0, 0), -- Putrid Shrieker (Area: Eastwall Tower)
(@CGUID+2222, 8601, 0, 1, 1, 2379.054, -4920.165, 74.52269, 2.520674, 120, 0, 0), -- Noxious Plaguebat (Area: Eastwall Tower)
(@CGUID+2223, 8603, 0, 1, 1, 2126.359, -4924.899, 76.86816, 5.479122, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+2224, 8605, 0, 1, 1, 2047.487, -4919.693, 76.72215, 3.708472, 120, 0, 0), -- Carrion Devourer (Area: 0)
(@CGUID+2225, 8603, 0, 1, 1, 1729.414, -4919.668, 90.57187, 5.680447, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+2226, 8600, 0, 1, 1, 1652.457, -4978.277, 83.32408, 1.353292, 120, 0, 0), -- Plaguebat (Area: Death Cultist Base Camp)
(@CGUID+2227, 8596, 0, 1, 1, 1678.302, -4957.232, 78.57758, 0.4356829, 120, 0, 0), -- Plaguehound Runt (Area: Death Cultist Base Camp)
(@CGUID+2228, 2110, 0, 1, 1, 1735.054, -4969.125, 78.92551, 3.592566, 120, 0, 0), -- Black Rat (Area: Death Cultist Base Camp)
(@CGUID+2229, 8603, 0, 1, 1, 1827.16, -4947.326, 78.98393, 1.773137, 120, 0, 0), -- Carrion Grub (Area: Death Cultist Base Camp)
(@CGUID+2230, 8603, 0, 1, 1, 1852.224, -4986.314, 88.36337, 1.818619, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+2231, 20725, 0, 1, 1, 1906.928, -4970.079, 78.14982, 4.739377, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+2232, 8603, 0, 1, 1, 1947.472, -4954.421, 74.87193, 3.609602, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+2233, 8603, 0, 1, 1, 1884.124, -4947.545, 75.19623, 1.941688, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+2234, 8605, 0, 1, 1, 1925.844, -4950.146, 76.49245, 5.817354, 120, 0, 0), -- Carrion Devourer (Area: 0)
(@CGUID+2235, 8603, 0, 1, 1, 1919.802, -4985.537, 76.48917, 5.352377, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+2236, 8603, 0, 1, 1, 1984.91, -4997.74, 77.15239, 5.866441, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+2237, 8605, 0, 1, 1, 1988.955, -4947.498, 75.98613, 4.064104, 120, 0, 0), -- Carrion Devourer (Area: 0)
(@CGUID+2238, 20725, 0, 1, 1, 1995.881, -4956.854, 75.603, 5.307592, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+2239, 32520, 0, 1, 1, -6014.71, 5479.63, -1208.007, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: 0)
(@CGUID+2240, 32520, 0, 1, 1, -6148.39, 5539.97, -1207.787, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: 0)
(@CGUID+2241, 32520, 0, 1, 1, -6305.162, 5582.533, -1172.063, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: 0)
(@CGUID+2242, 32520, 0, 1, 1, -5691.65, 5556.92, -1154.687, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: 0)
(@CGUID+2243, 10780, 0, 1, 1, 2345.601, -4984.385, 71.28346, 1.988083, 120, 0, 0), -- Infected Deer (Area: 0)
(@CGUID+2244, 8603, 0, 1, 1, 2382.935, -4995.803, 71.7232, 1.1718, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+2245, 20725, 0, 1, 1, 2403.102, -4963.079, 76.47584, 4.282865, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+2246, 20725, 0, 1, 1, 2472.45, -4925.332, 77.55302, 6.058914, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+2247, 8598, 0, 1, 1, 2653.534, -4937.994, 91.38021, 5.051134, 120, 0, 0), -- Frenzied Plaguehound (Area: Eastwall Tower)
(@CGUID+2248, 10779, 0, 1, 1, 2675.913, -4925.756, 86.01801, 1.202637, 120, 0, 0), -- Infected Squirrel (Area: Eastwall Tower)
(@CGUID+2249, 8605, 0, 1, 1, 2654.851, -4969.954, 110.5096, 4.094298, 120, 0, 0), -- Carrion Devourer (Area: Eastwall Tower)
(@CGUID+2250, 20725, 0, 1, 1, 2728.954, -4948.346, 94.34354, 2.235954, 120, 0, 0), -- Bat (Area: Eastwall Tower)
(@CGUID+2251, 8602, 0, 1, 1, 2744.078, -4988.103, 90.98196, 6.038167, 120, 0, 0), -- Monstrous Plaguebat (Area: 0)
(@CGUID+2252, 8602, 0, 1, 1, 2780.676, -4982.106, 96.6139, 5.742216, 120, 0, 0), -- Monstrous Plaguebat (Area: 0)
(@CGUID+2253, 8521, 0, 1, 1, 2882.813, -4932.813, 99.95712, 4.140799, 120, 0, 0), -- Blighted Horror (Area: 0) (possible waypoints or random movement)
(@CGUID+2254, 8521, 0, 1, 1, 2886.21, -4987.959, 98.62521, 1.805188, 120, 0, 0), -- Blighted Horror (Area: Northdale) (possible waypoints or random movement)
(@CGUID+2255, 8521, 0, 1, 1, 2923.413, -4953.811, 96.93645, 2.652829, 120, 0, 0), -- Blighted Horror (Area: Northdale) (possible waypoints or random movement)
(@CGUID+2256, 2110, 0, 1, 1, 3041.962, -4961.671, 104.086, 5.904446, 120, 0, 0), -- Black Rat (Area: Northdale)
(@CGUID+2257, 8540, 0, 1, 1, 3022.964, -4977.379, 106.6587, 1.251045, 120, 0, 0), -- Torn Screamer (Area: Northdale)
(@CGUID+2258, 8540, 0, 1, 1, 2988.542, -4982.291, 107.8546, 1.259018, 120, 0, 0), -- Torn Screamer (Area: Northdale)
(@CGUID+2259, 8540, 0, 1, 1, 2973.895, -4951.38, 109.0881, 4.230876, 120, 0, 0), -- Torn Screamer (Area: Northdale)
(@CGUID+2260, 8540, 0, 1, 1, 3007.57, -4946.885, 106.1363, 1.837562, 120, 0, 0), -- Torn Screamer (Area: Northdale)
(@CGUID+2261, 8540, 0, 1, 1, 3059.388, -4936.035, 103.7602, 5.171175, 120, 0, 0), -- Torn Screamer (Area: Northdale)
(@CGUID+2262, 8537, 0, 1, 1, 3045.095, -4954.798, 105.0123, 1.56225, 120, 0, 0), -- Interloper (Area: Northdale)
(@CGUID+2263, 8540, 0, 1, 1, 3043.62, -4920.51, 102.9173, 0.7853982, 120, 0, 0), -- Torn Screamer (Area: Northdale)
(@CGUID+2264, 8540, 0, 1, 1, 3050.377, -4983.603, 100.9459, 5.530924, 120, 0, 0), -- Torn Screamer (Area: Northdale)
(@CGUID+2265, 8540, 0, 1, 1, 3087.757, -4955.298, 97.56467, 6.05828, 120, 0, 0), -- Torn Screamer (Area: Northdale)
(@CGUID+2266, 8562, 0, 1, 1, 3320.103, -4986.682, 169.1952, 4.857855, 120, 0, 0), -- Mossflayer Cannibal (Area: Zul'Mashar) (possible waypoints or random movement)
(@CGUID+2267, 41200, 0, 1, 1, 3464.15, -5005.47, 204.3953, 2.391101, 120, 0, 0), -- Generic Bunny - PRK (Area: Zul'Mashar)
(@CGUID+2268, 8561, 0, 1, 1, 3480.657, -4987.979, 198.4034, 3.961897, 120, 0, 0), -- Mossflayer Shadowhunter (Area: Zul'Mashar)
(@CGUID+2269, 8561, 0, 1, 1, 3416.226, -5004.012, 191.0506, 6.248279, 120, 0, 0), -- Mossflayer Shadowhunter (Area: Zul'Mashar)
(@CGUID+2270, 8561, 0, 1, 1, 3427.826, -5005.358, 195.7509, 0, 120, 0, 0), -- Mossflayer Shadowhunter (Area: Zul'Mashar)
(@CGUID+2271, 8561, 0, 1, 1, 3446.645, -5021.233, 197.3737, 0.6283185, 120, 0, 0), -- Mossflayer Shadowhunter (Area: Zul'Mashar)
(@CGUID+2272, 8561, 0, 1, 1, 3403.271, -5004.052, 184.7122, 6.265732, 120, 0, 0), -- Mossflayer Shadowhunter (Area: Zul'Mashar)
(@CGUID+2273, 8561, 0, 1, 1, 3432.527, -5036.128, 183.6022, 0.7504916, 120, 0, 0), -- Mossflayer Shadowhunter (Area: Zul'Mashar)
(@CGUID+2274, 8561, 0, 1, 1, 3389.994, -5003.944, 167.7265, 6.265732, 120, 0, 0), -- Mossflayer Shadowhunter (Area: Zul'Mashar)
(@CGUID+2275, 8562, 0, 1, 1, 3393.818, -5029.983, 170.0142, 3.735005, 120, 0, 0), -- Mossflayer Cannibal (Area: Zul'Mashar)
(@CGUID+2276, 8561, 0, 1, 1, 3389.727, -5032.561, 170.3292, 0.541052, 120, 0, 0), -- Mossflayer Shadowhunter (Area: Zul'Mashar)
(@CGUID+2277, 8561, 0, 1, 1, 3332.995, -5000.863, 168.7957, 0.7330383, 120, 0, 0), -- Mossflayer Shadowhunter (Area: Zul'Mashar)
(@CGUID+2278, 8560, 0, 1, 1, 3336.11, -4999.154, 168.7957, 3.385939, 120, 0, 0), -- Mossflayer Scout (Area: Zul'Mashar)
(@CGUID+2279, 41178, 0, 1, 1, 1850.524, -3728.49, 211.9617, 0.08726646, 120, 0, 0), -- Northwatch Tower Stalker (Area: Zul'Mashar)
(@CGUID+2280, 8540, 0, 1, 1, 3069.358, -5009.125, 96.60947, 4.234979, 120, 0, 0), -- Torn Screamer (Area: Zul'Mashar)
(@CGUID+2281, 8537, 0, 1, 1, 3012.456, -5016.04, 101.278, 1.387305, 120, 0, 0), -- Interloper (Area: Northdale)
(@CGUID+2282, 8537, 0, 1, 1, 2983.942, -5017.565, 104.4298, 4.950371, 120, 0, 0), -- Interloper (Area: Northdale)
(@CGUID+2283, 8540, 0, 1, 1, 2918.151, -5006.902, 107.9717, 3.887961, 120, 0, 0), -- Torn Screamer (Area: Northdale)
(@CGUID+2284, 8598, 0, 1, 1, 2761.294, -5004.948, 92.20139, 0.9749433, 120, 0, 0), -- Frenzied Plaguehound (Area: Northdale)
(@CGUID+2285, 8601, 0, 1, 1, 2350.584, -5014.944, 71.24788, 2.329613, 120, 0, 0), -- Noxious Plaguebat (Area: 0)
(@CGUID+2286, 10779, 0, 1, 1, 2411.961, -5010.604, 75.06881, 5.383623, 120, 0, 0), -- Infected Squirrel (Area: 0)
(@CGUID+2287, 10779, 0, 1, 1, 2306.632, -4999.771, 74.33647, 3.665099, 120, 0, 0), -- Infected Squirrel (Area: 0)
(@CGUID+2288, 8605, 0, 1, 1, 1950.246, -5008.064, 75.28802, 4.25486, 120, 0, 0), -- Carrion Devourer (Area: 0)
(@CGUID+2289, 10780, 0, 1, 1, 1775.02, -5005.574, 82.08977, 1.069001, 120, 0, 0), -- Infected Deer (Area: 0)
(@CGUID+2290, 8605, 0, 1, 1, 1815.636, -5003.009, 86.27164, 2.38314, 120, 0, 0), -- Carrion Devourer (Area: 0)
(@CGUID+2291, 2110, 0, 1, 1, 1663.406, -5016.935, 83.75615, 3.674307, 120, 0, 0), -- Black Rat (Area: Death Cultist Base Camp)
(@CGUID+2292, 2110, 0, 1, 1, 1728.749, -5077.015, 79.07314, 4.362534, 120, 0, 0), -- Black Rat (Area: 0)
(@CGUID+2293, 2110, 0, 1, 1, 1779.695, -5096.513, 88.23714, 5.544057, 120, 0, 0), -- Black Rat (Area: 0)
(@CGUID+2294, 8605, 0, 1, 1, 1810.575, -5075.844, 82.06496, 2.306359, 120, 0, 0), -- Carrion Devourer (Area: 0)
(@CGUID+2295, 8603, 0, 1, 1, 1869.426, -5019.582, 87.50765, 4.354502, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+2296, 8605, 0, 1, 1, 1878.055, -5083.154, 79.47636, 0.4400506, 120, 0, 0), -- Carrion Devourer (Area: 0)
(@CGUID+2297, 10780, 0, 1, 1, 1873.542, -5077.923, 80.35609, 6.210834, 120, 0, 0), -- Infected Deer (Area: 0)
(@CGUID+2298, 8605, 0, 1, 1, 1850.421, -5064.445, 82.77072, 3.557636, 120, 0, 0), -- Carrion Devourer (Area: 0)
(@CGUID+2299, 10780, 0, 1, 1, 1908.925, -5028.866, 87.23942, 6.153988, 120, 0, 0), -- Infected Deer (Area: 0)
(@CGUID+2300, 8603, 0, 1, 1, 1873.599, -5061.404, 83.36345, 4.216645, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+2301, 8603, 0, 1, 1, 1970.683, -5044.287, 79.34226, 1.847878, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+2302, 8605, 0, 1, 1, 1917.449, -5057.56, 79.26839, 2.232268, 120, 0, 0), -- Carrion Devourer (Area: 0)
(@CGUID+2303, 10780, 0, 1, 1, 1950.896, -5050.514, 80.20863, 3.754022, 120, 0, 0), -- Infected Deer (Area: 0)
(@CGUID+2304, 8605, 0, 1, 1, 1955.23, -5079.795, 87.59888, 0.4400506, 120, 0, 0), -- Carrion Devourer (Area: 0)
(@CGUID+2305, 8603, 0, 1, 1, 2035.593, -5068.312, 77.09464, 1.996406, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+2306, 20725, 0, 1, 1, 1988.895, -5046.638, 77.72442, 2.670526, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+2307, 47060, 0, 1, 1, 2169.8, -5049.68, 77.78824, 1.500983, 120, 0, 0), -- Argent Sentry (Area: Pestilent Scar)
(@CGUID+2308, 47060, 0, 1, 1, 2177.04, -5069.62, 80.60313, 1.500983, 120, 0, 0), -- Argent Sentry (Area: Pestilent Scar)
(@CGUID+2309, 47060, 0, 1, 1, 2180.78, -5081.4, 80.59824, 5.183628, 120, 0, 0), -- Argent Sentry (Area: Pestilent Scar)
(@CGUID+2310, 47060, 0, 1, 1, 2193.98, -5076.64, 80.62013, 5.026548, 120, 0, 0), -- Argent Sentry (Area: Pestilent Scar)
(@CGUID+2311, 47060, 0, 1, 1, 2183, -5044.92, 77.66154, 2.076942, 120, 0, 0), -- Argent Sentry (Area: Pestilent Scar)
(@CGUID+2312, 47060, 0, 1, 1, 2190.23, -5064.87, 80.58363, 2.076942, 120, 0, 0), -- Argent Sentry (Area: Pestilent Scar)
(@CGUID+2313, 8597, 0, 1, 1, 2370.953, -5038.393, 74.94057, 2.51294, 120, 0, 0), -- Plaguehound (Area: Pestilent Scar)
(@CGUID+2314, 8601, 0, 1, 1, 2414.25, -5031.351, 79.5315, 0.9651899, 120, 0, 0), -- Noxious Plaguebat (Area: 0)
(@CGUID+2315, 8605, 0, 1, 1, 2779.005, -5035.562, 91.80573, 5.319842, 120, 0, 0), -- Carrion Devourer (Area: 0)
(@CGUID+2316, 8605, 0, 1, 1, 2879.729, -5074.72, 110.8215, 0.6239703, 120, 0, 0), -- Carrion Devourer (Area: Northdale)
(@CGUID+2317, 20725, 0, 1, 1, 2921.1, -5035.39, 107.327, 3.982353, 120, 0, 0), -- Bat (Area: Northdale)
(@CGUID+2318, 8605, 0, 1, 1, 2946.935, -5081.454, 118.7892, 5.625226, 120, 0, 0), -- Carrion Devourer (Area: Northdale)
(@CGUID+2319, 8540, 0, 1, 1, 3048.511, -5029.925, 96.94651, 5.417885, 120, 0, 0), -- Torn Screamer (Area: Northdale)
(@CGUID+2320, 8535, 0, 1, 1, 3072.315, -5056.785, 121.8136, 3.300571, 120, 0, 0), -- Putrid Shrieker (Area: Northdale)
(@CGUID+2321, 8605, 0, 1, 1, 2932.917, -5109.749, 119.6808, 1.789132, 120, 0, 0), -- Carrion Devourer (Area: Northdale)
(@CGUID+2322, 8602, 0, 1, 1, 2989.198, -5114.593, 124.7959, 5.886249, 120, 0, 0), -- Monstrous Plaguebat (Area: Northdale)
(@CGUID+2323, 2110, 0, 1, 1, 2458.127, -5110.477, 76.13862, 3.143575, 120, 0, 0), -- Black Rat (Area: 0)
(@CGUID+2324, 8532, 0, 1, 1, 2488.045, -5113.011, 80.86482, 0.1559091, 120, 0, 0), -- Diseased Flayer (Area: 0)
(@CGUID+2325, 8532, 0, 1, 1, 2503.599, -5113.655, 80.8089, 3.974021, 120, 0, 0), -- Diseased Flayer (Area: 0)
(@CGUID+2326, 20725, 0, 1, 1, 2380.804, -5110.476, 82.03865, 5.870944, 120, 0, 0), -- Bat (Area: 0)
(@CGUID+2327, 47060, 0, 1, 1, 2187.71, -5102, 78.11944, 5.183628, 120, 0, 0), -- Argent Sentry (Area: Pestilent Scar)
(@CGUID+2328, 47060, 0, 1, 1, 2201.14, -5096.77, 78.08944, 5.026548, 120, 0, 0), -- Argent Sentry (Area: Pestilent Scar)
(@CGUID+2329, 20725, 0, 1, 1, 2074.845, -5123.675, 83.60686, 5.647497, 120, 0, 0), -- Bat (Area: Pestilent Scar)
(@CGUID+2330, 8603, 0, 1, 1, 2042.343, -5097.03, 80.36762, 2.35596, 120, 0, 0), -- Carrion Grub (Area: Pestilent Scar)
(@CGUID+2331, 8603, 0, 1, 1, 2029.166, -5083.334, 80.22475, 5.139226, 120, 0, 0), -- Carrion Grub (Area: Pestilent Scar)
(@CGUID+2332, 8605, 0, 1, 1, 1955.178, -5116.882, 79.75643, 5.637731, 120, 0, 0), -- Carrion Devourer (Area: Pestilent Scar)
(@CGUID+2333, 8603, 0, 1, 1, 1905.112, -5114.229, 76.10029, 3.011018, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+2334, 2110, 0, 1, 1, 1640.535, -5126.427, 77.72351, 3.046742, 120, 0, 0), -- Black Rat (Area: 0)
(@CGUID+2335, 45681, 0, 1, 1, 2620.81, -5463.61, 158.3879, 5.951573, 120, 0, 0), -- Garginox (Area: 0) (possible waypoints or random movement)
(@CGUID+2336, 43359, 0, 1, 1, 2298.788, 280.1181, 76.27024, 0, 120, 0, 0), -- ELM General Purpose Bunny Infinite Hide Body (Area: 0)
(@CGUID+2337, 40728, 0, 1, 1, -5250.75, 3081.753, -61.88316, 3.080544, 120, 0, 0), -- Whale Shark (Area: 0) (possible waypoints or random movement)
(@CGUID+2338, 40987, 0, 1, 1, -4847.953, 3599.419, -118.3699, 0.8655584, 120, 0, 0), -- Gnash (Area: 0) (possible waypoints or random movement)
(@CGUID+2339, 44140, 0, 1, 1, -9193.85, -2777.82, 90.63683, 0, 120, 0, 0), -- PetWait Trigger (Area: 0)
(@CGUID+2340, 40728, 0, 1, 1, -6341.9, 3230.391, -260.4893, 6.232139, 120, 0, 0), -- Whale Shark (Area: 0) (possible waypoints or random movement)
(@CGUID+2341, 40728, 0, 1, 1, -5923.372, 4400.368, -176.493, 5.062344, 120, 0, 0), -- Whale Shark (Area: 0) (possible waypoints or random movement)
(@CGUID+2342, 42851, 0, 1, 1, -5616.425, 5177.916, -1226.32, 0, 120, 0, 0), -- Revenant of Neptulon (Area: 0)
(@CGUID+2343, 42851, 0, 1, 1, -5559.231, 5246.39, -1228.137, 5.654867, 120, 0, 0), -- Revenant of Neptulon (Area: 0)
(@CGUID+2344, 42851, 0, 1, 1, -5732.877, 5152.973, -1222.141, 0, 120, 0, 0), -- Revenant of Neptulon (Area: 0)
(@CGUID+2345, 42851, 0, 1, 1, -5507.115, 5337.032, -1227.3, 0, 120, 0, 0), -- Revenant of Neptulon (Area: 0)
(@CGUID+2346, 42851, 0, 1, 1, -5862.793, 5175.958, -1213.582, 0, 120, 0, 0), -- Revenant of Neptulon (Area: 0)
(@CGUID+2347, 42851, 0, 1, 1, -5561.573, 5486.054, -1233.133, 0, 120, 0, 0), -- Revenant of Neptulon (Area: 0)
(@CGUID+2348, 42851, 0, 1, 1, -5972.122, 5222.906, -1208.386, 0, 120, 0, 0), -- Revenant of Neptulon (Area: 0)
(@CGUID+2349, 42851, 0, 1, 1, -5863.936, 5310.616, -1222.713, 0, 120, 0, 0), -- Revenant of Neptulon (Area: 0)
(@CGUID+2350, 42851, 0, 1, 1, -5982.469, 5345.316, -1218.424, 0, 120, 0, 0), -- Revenant of Neptulon (Area: 0)
(@CGUID+2351, 42851, 0, 1, 1, -5717.965, 5538.276, -1237.856, 0, 120, 0, 0), -- Revenant of Neptulon (Area: 0)
(@CGUID+2352, 42851, 0, 1, 1, -5812.905, 5495.367, -1231.447, 0, 120, 0, 0), -- Revenant of Neptulon (Area: 0)
(@CGUID+2353, 42851, 0, 1, 1, -6079.696, 5338.495, -1215.58, 0, 120, 0, 0), -- Revenant of Neptulon (Area: 0)
(@CGUID+2354, 42851, 0, 1, 1, -6043.141, 5439.757, -1219.116, 0, 120, 0, 0), -- Revenant of Neptulon (Area: 0)
(@CGUID+2355, 42851, 0, 1, 1, -5867.2, 5622.304, -1230.413, 0, 120, 0, 0), -- Revenant of Neptulon (Area: 0)
(@CGUID+2356, 42851, 0, 1, 1, -6184.12, 5397.069, -1216.32, 0, 120, 0, 0), -- Revenant of Neptulon (Area: 0)
(@CGUID+2357, 42851, 0, 1, 1, -5966.031, 5563.699, -1218.418, 0, 120, 0, 0), -- Revenant of Neptulon (Area: 0)
(@CGUID+2358, 42851, 0, 1, 1, -6133.175, 5494.254, -1215.137, 0, 120, 0, 0), -- Revenant of Neptulon (Area: 0)
(@CGUID+2359, 42851, 0, 1, 1, -6089.413, 5608.077, -1223.85, 0, 120, 0, 0), -- Revenant of Neptulon (Area: 0)
(@CGUID+2360, 42851, 0, 1, 1, -6005.035, 5671.134, -1219.748, 0, 120, 0, 0), -- Revenant of Neptulon (Area: 0)
(@CGUID+2361, 42851, 0, 1, 1, -6226.069, 5512.124, -1215.753, 0, 120, 0, 0), -- Revenant of Neptulon (Area: 0)
(@CGUID+2362, 42851, 0, 1, 1, -6180.118, 5660.041, -1217.356, 0, 120, 0, 0), -- Revenant of Neptulon (Area: 0)
(@CGUID+2363, 42173, 0, 1, 1, -6230.174, 6798.166, -1075.454, 6.143559, 120, 0, 0), -- The Undershell Tentacle Flavor (Area: 0)
(@CGUID+2364, 42173, 0, 1, 1, -6446.698, 6829.101, -1124.952, 1.27409, 120, 0, 0), -- The Undershell Tentacle Flavor (Area: 0)
(@CGUID+2365, 42196, 0, 1, 1, -6423.21, 6884, -786.6007, 0, 120, 0, 0), -- ELM General Purpose Bunny Infinite (scale x2.5) (Area: 0)
(@CGUID+2366, 42196, 0, 1, 1, -6422.48, 6884.6, -870.8707, 0, 120, 0, 0), -- ELM General Purpose Bunny Infinite (scale x2.5) (Area: 0)
(@CGUID+2367, 37490, 0, 1, 1, -6654.488, 6736.202, -811.036, 0, 120, 0, 0), -- ELM General Purpose Bunny Infinite (Area: 0)
(@CGUID+2368, 42173, 0, 1, 1, -6396.681, 7054.327, -1069.238, 3.071779, 120, 0, 0), -- The Undershell Tentacle Flavor (Area: 0)
(@CGUID+2369, 37490, 0, 1, 1, -6353.474, 7151.508, -807.5332, 0, 120, 0, 0), -- ELM General Purpose Bunny Infinite (Area: 0)
(@CGUID+2370, 8603, 0, 1, 1, 1938.535, -5159.593, 73.77427, 3.643726, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+2371, 8603, 0, 1, 1, 1923.036, -5137.961, 75.60343, 4.53617, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+2372, 10780, 0, 1, 1, 1975.884, -5164.888, 78.34785, 1.781208, 120, 0, 0), -- Infected Deer (Area: 0)
(@CGUID+2373, 8603, 0, 1, 1, 1989.147, -5169.063, 80.24686, 1.333391, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+2374, 8603, 0, 1, 1, 1923.201, -5197.805, 74.57106, 1.780253, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+2375, 8605, 0, 1, 1, 2052.054, -5152.079, 81.16906, 5.304769, 120, 0, 0), -- Carrion Devourer (Area: 0)
(@CGUID+2376, 8603, 0, 1, 1, 2084.031, -5150.796, 83.23848, 5.18534, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+2377, 8603, 0, 1, 1, 2037.962, -5182.195, 79.9671, 0.3075452, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+2378, 8605, 0, 1, 1, 2018.283, -5158.384, 85.29393, 1.278404, 120, 0, 0), -- Carrion Devourer (Area: 0)
(@CGUID+2379, 8605, 0, 1, 1, 2115.403, -5176.138, 78.60291, 2.022233, 120, 0, 0), -- Carrion Devourer (Area: Pestilent Scar)
(@CGUID+2380, 20725, 0, 1, 1, 2096.363, -5174.95, 76.5038, 0.1690649, 120, 0, 0), -- Bat (Area: Pestilent Scar)
(@CGUID+2381, 20725, 0, 1, 1, 2278.542, -5184.231, 79.73164, 0.7999099, 120, 0, 0), -- Bat (Area: Pestilent Scar)
(@CGUID+2382, 8528, 0, 1, 1, 2451.569, -5151.188, 78.90451, 0.5192038, 120, 0, 0), -- Dread Weaver (Area: Pestilent Scar)
(@CGUID+2383, 8532, 0, 1, 1, 2459.743, -5128.643, 77.21928, 1.599109, 120, 0, 0), -- Diseased Flayer (Area: Pestilent Scar)
(@CGUID+2384, 8542, 0, 1, 1, 2410.683, -5184.787, 74.55199, 3.655896, 120, 0, 0), -- Death Singer (Area: Pestilent Scar)
(@CGUID+2385, 2110, 0, 1, 1, 2478.244, -5146.454, 76.98007, 5.6176, 120, 0, 0), -- Black Rat (Area: Pestilent Scar)
(@CGUID+2386, 45695, 0, 1, 1, 2488.66, -5157.71, 77.62763, 3.857178, 120, 0, 0), -- Slain Scourge Trooper (Area: Pestilent Scar)
(@CGUID+2387, 46167, 0, 1, 1, 2484.77, -5184.93, 76.19694, 1.53589, 120, 0, 0), -- Stephen Browman (Area: Pestilent Scar)
(@CGUID+2388, 8532, 0, 1, 1, 2506.527, -5175.395, 77.62618, 5.772279, 120, 0, 0), -- Diseased Flayer (Area: Pestilent Scar)
(@CGUID+2389, 8528, 0, 1, 1, 2490.459, -5150.875, 76.31882, 5.133253, 120, 0, 0), -- Dread Weaver (Area: Pestilent Scar)
(@CGUID+2390, 8528, 0, 1, 1, 2451.154, -5178.782, 74.00236, 2.794469, 120, 0, 0), -- Dread Weaver (Area: Pestilent Scar)
(@CGUID+2391, 2110, 0, 1, 1, 2541.064, -5166.524, 74.24151, 5.157009, 120, 0, 0), -- Black Rat (Area: Pestilent Scar)
(@CGUID+2392, 8528, 0, 1, 1, 2550.898, -5158.876, 74.48613, 1.278693, 120, 0, 0), -- Dread Weaver (Area: Pestilent Scar)
(@CGUID+2393, 8532, 0, 1, 1, 2577.354, -5180.99, 75.0659, 3.694911, 120, 0, 0), -- Diseased Flayer (Area: Browman Mill)
(@CGUID+2394, 32520, 0, 1, 1, -5691.65, 5556.92, -1154.687, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Browman Mill)
(@CGUID+2395, 32520, 0, 1, 1, -6148.39, 5539.97, -1207.787, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Browman Mill)
(@CGUID+2396, 32520, 0, 1, 1, -6305.162, 5582.533, -1172.063, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Browman Mill)
(@CGUID+2397, 32520, 0, 1, 1, -6014.71, 5479.63, -1208.007, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Browman Mill)
(@CGUID+2398, 45695, 0, 1, 1, 2593.79, -5225.59, 95.42014, 3.857178, 120, 0, 0), -- Slain Scourge Trooper (Area: 0)
(@CGUID+2399, 8542, 0, 1, 1, 2659.148, -5277.819, 143.9595, 0.8302885, 120, 0, 0), -- Death Singer (Area: 0)
(@CGUID+2400, 8528, 0, 1, 1, 2642.891, -5255.342, 120.8518, 4.469779, 120, 0, 0), -- Dread Weaver (Area: 0)
(@CGUID+2401, 8528, 0, 1, 1, 2616.408, -5226.009, 97.68231, 2.446104, 120, 0, 0), -- Dread Weaver (Area: 0)
(@CGUID+2402, 8532, 0, 1, 1, 2441.064, -5223.212, 75.20315, 2.68245, 120, 0, 0), -- Diseased Flayer (Area: Browman Mill)
(@CGUID+2403, 45695, 0, 1, 1, 2448.88, -5198.75, 74.03783, 3.857178, 120, 0, 0), -- Slain Scourge Trooper (Area: Browman Mill)
(@CGUID+2404, 16378, 0, 1, 1, 2353.93, -5274.32, 82.35803, 1.58825, 120, 0, 0), -- Argent Sentry (Area: Browman Mill)
(@CGUID+2405, 16378, 0, 1, 1, 2371.11, -5249.21, 78.80544, 0.9250245, 120, 0, 0), -- Argent Sentry (Area: Browman Mill)
(@CGUID+2406, 47288, 0, 1, 1, 2341.62, -5259.75, 81.81203, 5.305801, 120, 0, 0), -- Gutcheck (Area: Browman Mill)
(@CGUID+2407, 16378, 0, 1, 1, 2307.53, -5244.03, 91.412, 1.675516, 120, 0, 0), -- Argent Sentry (Area: Browman Mill) (possible waypoints or random movement)
(@CGUID+2408, 16378, 0, 1, 1, 2338.404, -5242.042, 92.11863, 3.195738, 120, 0, 0), -- Argent Sentry (Area: Browman Mill) (possible waypoints or random movement)
(@CGUID+2409, 16378, 0, 1, 1, 2321.32, -5227.13, 84.58554, 4.413883, 120, 0, 0), -- Argent Sentry (Area: Browman Mill) (possible waypoints or random movement)
(@CGUID+2410, 16378, 0, 1, 1, 2376.9, -5255.19, 78.78944, 0.8901179, 120, 0, 0), -- Argent Sentry (Area: Browman Mill)
(@CGUID+2411, 16378, 0, 1, 1, 2354.504, -5220.866, 83.2053, 0.5132523, 120, 0, 0), -- Argent Sentry (Area: Browman Mill) (possible waypoints or random movement)
(@CGUID+2412, 10779, 0, 1, 1, 2370.019, -5201.599, 76.37556, 4.921846, 120, 0, 0), -- Infected Squirrel (Area: Browman Mill)
(@CGUID+2413, 47289, 0, 1, 1, 2240.95, -5244.47, 76.03123, 2.076942, 120, 0, 0), -- Argent Crusade Engineer (Area: Browman Mill)
(@CGUID+2414, 47289, 0, 1, 1, 2257.11, -5259.58, 94.62273, 0.4537856, 120, 0, 0), -- Argent Crusade Engineer (Area: Browman Mill)
(@CGUID+2415, 16378, 0, 1, 1, 2244.35, -5278.18, 90.00639, 2.373648, 120, 0, 0), -- Argent Sentry (Area: Browman Mill) (possible waypoints or random movement)
(@CGUID+2416, 16378, 0, 1, 1, 2247.13, -5255.38, 77.93484, 1.902409, 120, 0, 0), -- Argent Sentry (Area: Browman Mill)
(@CGUID+2417, 16378, 0, 1, 1, 2259.03, -5246.33, 77.99953, 2.129302, 120, 0, 0), -- Argent Sentry (Area: Browman Mill)
(@CGUID+2418, 47286, 0, 1, 1, 2266.66, -5285.23, 83.0547, 1.43977, 120, 0, 0), -- Vincent Randolph (Area: Browman Mill) (possible waypoints or random movement)
(@CGUID+2419, 11102, 0, 1, 1, 2237.587, -5229.52, 75.10991, 3.583381, 120, 0, 0), -- Argent Rider (Area: Browman Mill) (possible waypoints or random movement)
(@CGUID+2420, 11102, 0, 1, 1, 2242.235, -5227.702, 75.01166, 3.423578, 120, 0, 0), -- Argent Rider (Area: Browman Mill) (possible waypoints or random movement)
(@CGUID+2421, 47289, 0, 1, 1, 2287.755, -5230.551, 83.27286, 0.4104466, 120, 0, 0), -- Argent Crusade Engineer (Area: Browman Mill) (possible waypoints or random movement)
(@CGUID+2422, 47289, 0, 1, 1, 2301.81, -5246.09, 92.32803, 5.358161, 120, 0, 0), -- Argent Crusade Engineer (Area: Browman Mill)
(@CGUID+2423, 47289, 0, 1, 1, 2293.25, -5242.07, 94.44484, 5.358161, 120, 0, 0), -- Argent Crusade Engineer (Area: Browman Mill)
(@CGUID+2424, 47289, 0, 1, 1, 2301.61, -5237.06, 95.75734, 4.380776, 120, 0, 0), -- Argent Crusade Engineer (Area: Browman Mill)
(@CGUID+2425, 47289, 0, 1, 1, 2290.06, -5282.4, 82.24128, 0.1745329, 120, 0, 0), -- Argent Crusade Engineer (Area: Browman Mill) (possible waypoints or random movement)
(@CGUID+2426, 16378, 0, 1, 1, 2284.32, -5248.84, 90.00546, 1.762783, 120, 0, 0), -- Argent Sentry (Area: Browman Mill) (possible waypoints or random movement)
(@CGUID+2427, 16378, 0, 1, 1, 2297.12, -5244.7, 84.25893, 1.745329, 120, 0, 0), -- Argent Sentry (Area: Browman Mill)
(@CGUID+2428, 2110, 0, 1, 1, 2310.594, -5261.75, 82.22703, 3.348184, 120, 0, 0), -- Black Rat (Area: Browman Mill)
(@CGUID+2429, 16378, 0, 1, 1, 2278.294, -5224.525, 80.39819, 3.384203, 120, 0, 0), -- Argent Sentry (Area: Browman Mill) (possible waypoints or random movement)
(@CGUID+2430, 11038, 0, 1, 1, 2153.112, -5267.612, 82.79784, 2.150926, 120, 0, 0), -- Caretaker Alen (Area: Pestilent Scar) (possible waypoints or random movement)
(@CGUID+2431, 16378, 0, 1, 1, 2220.261, -5265.159, 77.52689, 1.00781, 120, 0, 0), -- Argent Sentry (Area: Pestilent Scar) (possible waypoints or random movement)
(@CGUID+2432, 16378, 0, 1, 1, 2195.644, -5289.623, 87.81593, 2.460374, 120, 0, 0), -- Argent Sentry (Area: Pestilent Scar) (possible waypoints or random movement)
(@CGUID+2433, 8534, 0, 1, 1, 2118.469, -5159.15, 77.10111, 2.640375, 120, 0, 0), -- Putrid Gargoyle (Area: Pestilent Scar)
(@CGUID+2434, 8603, 0, 1, 1, 1994.406, -5223.301, 80.35382, 5.264313, 120, 0, 0), -- Carrion Grub (Area: Pestilent Scar)
(@CGUID+2435, 2110, 0, 1, 1, 2096.648, -5280.163, 86.54341, 6.265609, 120, 0, 0), -- Black Rat (Area: Pestilent Scar)
(@CGUID+2436, 8605, 0, 1, 1, 2003.343, -5235.058, 80.67931, 3.535331, 120, 0, 0), -- Carrion Devourer (Area: Pestilent Scar)
(@CGUID+2437, 8605, 0, 1, 1, 2074.374, -5213.916, 81.15718, 0.6286527, 120, 0, 0), -- Carrion Devourer (Area: Pestilent Scar)
(@CGUID+2438, 8603, 0, 1, 1, 2044.076, -5215.789, 83.49516, 4.271455, 120, 0, 0), -- Carrion Grub (Area: Pestilent Scar)
(@CGUID+2439, 10780, 0, 1, 1, 1925.229, -5225.684, 84.4966, 2.558464, 120, 0, 0), -- Infected Deer (Area: 0)
(@CGUID+2440, 10780, 0, 1, 1, 1923.033, -5205.817, 76.87221, 0.8854237, 120, 0, 0), -- Infected Deer (Area: 0)
(@CGUID+2441, 8603, 0, 1, 1, 1976.041, -5243.436, 85.15079, 2.395206, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+2442, 8603, 0, 1, 1, 1953.539, -5211.407, 87.09311, 5.609694, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+2443, 8605, 0, 1, 1, 1964.155, -5280.056, 84.51859, 5.129371, 120, 0, 0), -- Carrion Devourer (Area: 0)
(@CGUID+2444, 8603, 0, 1, 1, 2025.455, -5274.847, 85.99429, 0.3511084, 120, 0, 0), -- Carrion Grub (Area: 0)
(@CGUID+2445, 9447, 0, 1, 1, 1758.836, -5205.04, 108.2819, 1.867502, 120, 0, 0), -- Scarlet Warder (Area: Tyr's Hand)
(@CGUID+2446, 9447, 0, 1, 1, 1804.805, -5214.655, 113.1799, 3.368485, 120, 0, 0), -- Scarlet Warder (Area: Tyr's Hand)
(@CGUID+2447, 9447, 0, 1, 1, 1801.262, -5204.334, 113.1799, 3.490659, 120, 0, 0), -- Scarlet Warder (Area: Tyr's Hand)
(@CGUID+2448, 9449, 0, 1, 1, 1775.656, -5223.317, 103.1322, 3.159372, 120, 0, 0), -- Scarlet Cleric (Area: Tyr's Hand) (possible waypoints or random movement)
(@CGUID+2449, 9449, 0, 1, 1, 1754.741, -5245.871, 89.77396, 1.612829, 120, 0, 0), -- Scarlet Cleric (Area: Tyr's Hand) (possible waypoints or random movement)
(@CGUID+2450, 9447, 0, 1, 1, 1807.711, -5204.857, 113.0965, 4.474089, 120, 0, 0), -- Scarlet Warder (Area: Tyr's Hand) (possible waypoints or random movement)
(@CGUID+2451, 16115, 0, 1, 1, 1690.91, -5211.74, 74.42924, 6.213372, 120, 0, 0), -- Commander Eligor Dawnbringer (Area: Tyr's Hand)
(@CGUID+2452, 16116, 0, 1, 1, 1692.75, -5215.99, 74.04073, 1.48353, 120, 0, 0), -- Archmage Angela Dosantos (Area: Tyr's Hand)
(@CGUID+2453, 16112, 0, 1, 1, 1694.35, -5211.4, 74.47864, 3.176499, 120, 0, 0), -- Korfax, Champion of the Light (Area: Tyr's Hand)
(@CGUID+2454, 9447, 0, 1, 1, 1718.08, -5285.094, 73.16888, 4.733408, 120, 0, 0), -- Scarlet Warder (Area: Tyr's Hand) (possible waypoints or random movement)
(@CGUID+2455, 9452, 0, 1, 1, 1652.27, -5272.367, 83.73464, 1.142069, 120, 0, 0), -- Scarlet Enchanter (Area: Tyr's Hand) (possible waypoints or random movement)
(@CGUID+2456, 9449, 0, 1, 1, 1685.401, -5285.463, 73.80056, 2.266695, 120, 0, 0), -- Scarlet Cleric (Area: Tyr's Hand) (possible waypoints or random movement)
(@CGUID+2457, 9447, 0, 1, 1, 1634.98, -5298.33, 75.97024, 2.513274, 120, 0, 0), -- Scarlet Warder (Area: Tyr's Hand)
(@CGUID+2458, 9447, 0, 1, 1, 1635.65, -5296.92, 75.97024, 2.722714, 120, 0, 0), -- Scarlet Warder (Area: Tyr's Hand)
(@CGUID+2459, 9452, 0, 1, 1, 1662.567, -5308.353, 74.29617, 2.349999, 120, 0, 0), -- Scarlet Enchanter (Area: Tyr's Hand) (possible waypoints or random movement)
(@CGUID+2460, 9447, 0, 1, 1, 1639.83, -5294.07, 93.12031, 1.23556, 120, 0, 0), -- Scarlet Warder (Area: Tyr's Hand) (possible waypoints or random movement)
(@CGUID+2461, 9450, 0, 1, 1, 1620.147, -5315.346, 89.81029, 4.129705, 120, 0, 0), -- Scarlet Curate (Area: Tyr's Hand) (possible waypoints or random movement)
(@CGUID+2462, 9447, 0, 1, 1, 1609.95, -5286.51, 75.97014, 5.846853, 120, 0, 0), -- Scarlet Warder (Area: Tyr's Hand)
(@CGUID+2463, 6547, 0, 1, 1, 1603.86, -5307.04, 70.01214, 4.886922, 120, 0, 0), -- Suffering Victim (Area: Tyr's Hand)
(@CGUID+2464, 9451, 0, 1, 1, 1614.328, -5290.799, 84.70863, 2.54424, 120, 0, 0), -- Scarlet Archmage (Area: Tyr's Hand) (possible waypoints or random movement)
(@CGUID+2465, 9447, 0, 1, 1, 1611.04, -5284.82, 75.97014, 5.846853, 120, 0, 0), -- Scarlet Warder (Area: Tyr's Hand)
(@CGUID+2466, 9447, 0, 1, 1, 1617.98, -5314.31, 74.47124, 5.846853, 120, 0, 0), -- Scarlet Warder (Area: Tyr's Hand)
(@CGUID+2467, 6547, 0, 1, 1, 1598.01, -5315.13, 69.94204, 3.717551, 120, 0, 0), -- Suffering Victim (Area: Tyr's Hand)
(@CGUID+2468, 9447, 0, 1, 1, 1576.13, -5321.84, 88.99854, 5.113815, 120, 0, 0), -- Scarlet Warder (Area: Tyr's Hand)
(@CGUID+2469, 6547, 0, 1, 1, 1594.47, -5313.44, 69.95393, 3.385939, 120, 0, 0), -- Suffering Victim (Area: Tyr's Hand)
(@CGUID+2470, 9452, 0, 1, 1, 1577.41, -5324.44, 88.99863, 2.076942, 120, 0, 0), -- Scarlet Enchanter (Area: Tyr's Hand)
(@CGUID+2471, 9447, 0, 1, 1, 1590.36, -5327.21, 75.97014, 5.846853, 120, 0, 0), -- Scarlet Warder (Area: Tyr's Hand)
(@CGUID+2472, 9447, 0, 1, 1, 1591.25, -5325.29, 75.97014, 5.846853, 120, 0, 0), -- Scarlet Warder (Area: Tyr's Hand)
(@CGUID+2473, 9450, 0, 1, 1, 1596.386, -5323.989, 84.70864, 3.605895, 120, 0, 0), -- Scarlet Curate (Area: Tyr's Hand) (possible waypoints or random movement)
(@CGUID+2474, 9452, 0, 1, 1, 1589.1, -5324.89, 99.92815, 2.685434, 120, 0, 0), -- Scarlet Enchanter (Area: Tyr's Hand) (possible waypoints or random movement)
(@CGUID+2475, 44775, 0, 1, 1, 1570.01, -5414.07, 76.31863, 1.099557, 120, 0, 0), -- Generic Bunny - PRK (Large AOI) (Area: Tyr's Hand)
(@CGUID+2476, 9447, 0, 1, 1, 1616.24, -5337.78, 75.97024, 2.80998, 120, 0, 0), -- Scarlet Warder (Area: Tyr's Hand)
(@CGUID+2477, 9447, 0, 1, 1, 1615.57, -5339, 75.97024, 2.548181, 120, 0, 0), -- Scarlet Warder (Area: Tyr's Hand)
(@CGUID+2478, 9447, 0, 1, 1, 1678.321, -5355.53, 73.73611, 2.228523, 120, 0, 0), -- Scarlet Warder (Area: Tyr's Hand) (possible waypoints or random movement)
(@CGUID+2479, 9449, 0, 1, 1, 1721.666, -5335.452, 74.1769, 1.204277, 120, 0, 0), -- Scarlet Cleric (Area: Tyr's Hand)
(@CGUID+2480, 9447, 0, 1, 1, 1650.76, -5337.11, 74.38444, 5.899213, 120, 0, 0), -- Scarlet Warder (Area: Tyr's Hand)
(@CGUID+2481, 9447, 0, 1, 1, 1723.19, -5331.86, 73.94222, 4.276057, 120, 0, 0), -- Scarlet Warder (Area: Tyr's Hand)
(@CGUID+2482, 9447, 0, 1, 1, 1656.143, -5325.582, 74.48071, 5.864306, 120, 0, 0), -- Scarlet Warder (Area: Tyr's Hand)
(@CGUID+2483, 8605, 0, 1, 1, 1977.441, -5327.636, 98.79154, 4.169121, 120, 0, 0), -- Carrion Devourer (Area: 0)
(@CGUID+2484, 41178, 0, 1, 1, 2261.601, -4459.677, 163.8536, 0.08726646, 120, 0, 0), -- Northwatch Tower Stalker (Area: 0)
(@CGUID+2485, 2110, 0, 1, 1, 2120.585, -5304.169, 84.40835, 4.425235, 120, 0, 0), -- Black Rat (Area: Light's Hope Chapel)
(@CGUID+2486, 16378, 0, 1, 1, 2231.79, -5296.85, 89.53448, 2.565634, 120, 0, 0), -- Argent Sentry (Area: Light's Hope Chapel) (possible waypoints or random movement)
(@CGUID+2487, 16212, 0, 1, 1, 2252.036, -5305.331, 82.18577, 4.261965, 120, 0, 0), -- Dispatch Commander Metz (Area: Light's Hope Chapel)
(@CGUID+2488, 16378, 0, 1, 1, 2230.58, -5344.21, 90.9824, 3.228859, 120, 0, 0), -- Argent Sentry (Area: Light's Hope Chapel) (possible waypoints or random movement)
(@CGUID+2489, 48705, 0, 1, 1, 2273.837, -5259.042, 81.38015, 0.3839724, 120, 0, 0), -- Gertrude Nozzlerocket (Area: Light's Hope Chapel)
(@CGUID+2490, 48708, 0, 1, 1, 2276.458, -5258.253, 81.61099, 3.490659, 120, 0, 0), -- The Uncrashable (Area: Light's Hope Chapel)
(@CGUID+2491, 11033, 0, 1, 1, 2266.39, -5307.59, 82.25004, 3.071779, 120, 0, 0), -- Smokey LaRue (Area: Light's Hope Chapel)
(@CGUID+2492, 16378, 0, 1, 1, 2285.742, -5251.303, 117.211, 3.360548, 120, 0, 0), -- Argent Sentry (Area: Light's Hope Chapel) (possible waypoints or random movement)
(@CGUID+2493, 48704, 0, 1, 1, 2278.151, -5259.874, 81.68733, 4.729842, 120, 0, 0), -- Gek Nozzlerocket (Area: Light's Hope Chapel)
(@CGUID+2494, 16378, 0, 1, 1, 2254.421, -5336.082, 100.9817, 0.4134301, 120, 0, 0), -- Argent Sentry (Area: Light's Hope Chapel) (possible waypoints or random movement)
(@CGUID+2495, 16376, 0, 1, 1, 2261.174, -5321.298, 81.94905, 4.869469, 120, 0, 0), -- Craftsman Wilhelm (Area: Light's Hope Chapel)
(@CGUID+2496, 11536, 0, 1, 1, 2251.54, -5346.33, 87.01974, 1.58825, 120, 0, 0), -- Quartermaster Miranda Breechlock (Area: Light's Hope Chapel)
(@CGUID+2497, 11039, 0, 1, 1, 2257.99, -5341.7, 86.93594, 1.448623, 120, 0, 0), -- Duke Nicholas Zverenhoff (Area: Light's Hope Chapel)
(@CGUID+2498, 46022, 0, 1, 1, 2296.94, -5262.6, 82.29504, 5.410521, 120, 0, 0), -- Beezil Linkspanner (Area: Light's Hope Chapel)
(@CGUID+2499, 16378, 0, 1, 1, 2280.96, -5326.69, 89.35503, 2.303835, 120, 0, 0), -- Argent Sentry (Area: Light's Hope Chapel)
(@CGUID+2500, 12617, 0, 1, 1, 2268.8, -5345.42, 87.02424, 1.762783, 120, 0, 0), -- Khaelyn Steelwing (Area: Light's Hope Chapel)
(@CGUID+2501, 16378, 0, 1, 1, 2287.27, -5320.09, 89.54533, 2.356194, 120, 0, 0), -- Argent Sentry (Area: Light's Hope Chapel)
(@CGUID+2502, 12636, 0, 1, 1, 2272.06, -5343.54, 87.04073, 2.391101, 120, 0, 0), -- Georgia (Area: Light's Hope Chapel)
(@CGUID+2503, 47289, 0, 1, 1, 2296.7, -5300.02, 89.58633, 4.729842, 120, 0, 0), -- Argent Crusade Engineer (Area: Light's Hope Chapel)
(@CGUID+2504, 17069, 0, 1, 1, 2300.83, -5310.17, 90.70524, 0.2792527, 120, 0, 0), -- Emissary Whitebeard (Area: Light's Hope Chapel)
(@CGUID+2505, 16134, 0, 1, 1, 2309.75, -5261.74, 82.30563, 4.328416, 120, 0, 0), -- Rimblat Earthshatter (Area: Light's Hope Chapel)
(@CGUID+2506, 17072, 0, 1, 1, 2304.17, -5308.88, 90.56424, 3.420845, 120, 0, 0), -- Emissary Gormok (Area: Light's Hope Chapel)
(@CGUID+2507, 16378, 0, 1, 1, 2315.57, -5288.44, 82.16302, 0.02594704, 120, 0, 0), -- Argent Sentry (Area: Light's Hope Chapel) (possible waypoints or random movement)
(@CGUID+2508, 16284, 0, 1, 1, 2309.507, -5305.87, 86.79016, 0.122173, 120, 0, 0), -- Argent Medic (Area: Light's Hope Chapel)
(@CGUID+2509, 16225, 0, 1, 1, 2317.5, -5295.24, 82.10513, 1.343904, 120, 0, 0), -- Pack Mule (Area: Light's Hope Chapel)
(@CGUID+2510, 16283, 0, 1, 1, 2322.28, -5295.18, 82.11543, 1.500983, 120, 0, 0), -- Packmaster Stonebruiser (Area: Light's Hope Chapel)
(@CGUID+2511, 16378, 0, 1, 1, 2295.24, -5323.62, 90.89674, 2.426008, 120, 0, 0), -- Argent Sentry (Area: Light's Hope Chapel)
(@CGUID+2512, 16225, 0, 1, 1, 2328.74, -5299.29, 82.35564, 1.623156, 120, 0, 0), -- Pack Mule (Area: Light's Hope Chapel)
(@CGUID+2513, 12941, 0, 1, 1, 2336.52, -5285.49, 82.21284, 2.391101, 120, 0, 0), -- Jase Farlane (Area: Light's Hope Chapel)
(@CGUID+2514, 16378, 0, 1, 1, 2314.88, -5321.03, 90.36194, 2.303835, 120, 0, 0), -- Argent Sentry (Area: Light's Hope Chapel)
(@CGUID+2515, 16225, 0, 1, 1, 2332.35, -5297.69, 82.40844, 2.042035, 120, 0, 0), -- Pack Mule (Area: Light's Hope Chapel)
(@CGUID+2516, 16256, 0, 1, 1, 2295.74, -5336.82, 90.83524, 2.199115, 120, 0, 0), -- Jessica Chambers (Area: Light's Hope Chapel)
(@CGUID+2517, 11036, 0, 1, 1, 2305.76, -5335.47, 90.83524, 4.590216, 120, 0, 0), -- Leonid Barthalomew the Revered (Area: Light's Hope Chapel)
(@CGUID+2518, 44240, 0, 1, 1, 2274.28, -5346.93, 87.02424, 3.106686, 120, 0, 0), -- Argent Hippogryph (Area: Light's Hope Chapel)
(@CGUID+2519, 16365, 0, 1, 1, 2305.37, -5337.64, 90.83524, 1.343904, 120, 0, 0), -- Master Craftsman Omarion (Area: Light's Hope Chapel)
(@CGUID+2520, 11034, 0, 1, 1, 2307.55, -5345.78, 91.52963, 2.356194, 120, 0, 0), -- Lord Maxwell Tyrosus (Area: Light's Hope Chapel)
(@CGUID+2521, 16378, 0, 1, 1, 2311.78, -5344.78, 91.52963, 2.356194, 120, 0, 0), -- Argent Sentry (Area: Light's Hope Chapel)
(@CGUID+2522, 16378, 0, 1, 1, 2306.65, -5349.95, 91.52963, 2.426008, 120, 0, 0), -- Argent Sentry (Area: Light's Hope Chapel)
(@CGUID+2523, 16378, 0, 1, 1, 2357.58, -5293.86, 90.28444, 1.58825, 120, 0, 0), -- Argent Sentry (Area: Light's Hope Chapel)
(@CGUID+2524, 16378, 0, 1, 1, 2366.01, -5308.61, 90.41054, 1.795423, 120, 0, 0), -- Argent Sentry (Area: Light's Hope Chapel) (possible waypoints or random movement)
(@CGUID+2525, 49856, 0, 1, 1, 2335.038, -5357.418, 91.26846, 2.251475, 120, 0, 0), -- Lord Raymond George (Area: Light's Hope Chapel)
(@CGUID+2526, 2110, 0, 1, 1, 2344.26, -5372.225, 94.32119, 1.79254, 120, 0, 0), -- Black Rat (Area: Light's Hope Chapel)
(@CGUID+2527, 2110, 0, 1, 1, 2339.951, -5378.948, 91.54536, 3.014331, 120, 0, 0), -- Black Rat (Area: Light's Hope Chapel)
(@CGUID+2528, 16378, 0, 1, 1, 2343.44, -5391.83, 96.03854, 1.884956, 120, 0, 0), -- Argent Sentry (Area: Light's Hope Chapel)
(@CGUID+2529, 16378, 0, 1, 1, 2255.55, -5389.38, 94.38973, 3.159046, 120, 0, 0), -- Argent Sentry (Area: Light's Hope Chapel)
(@CGUID+2530, 16378, 0, 1, 1, 2236.79, -5390.61, 91.71934, 3.368485, 120, 0, 0), -- Argent Sentry (Area: Light's Hope Chapel)
(@CGUID+2531, 16378, 0, 1, 1, 2233.2, -5366.97, 91.27293, 3.351032, 120, 0, 0), -- Argent Sentry (Area: Light's Hope Chapel)
(@CGUID+2532, 16378, 0, 1, 1, 2196.441, -5380.329, 92.32809, 1.898114, 120, 0, 0), -- Argent Sentry (Area: Light's Hope Chapel) (possible waypoints or random movement)
(@CGUID+2533, 45692, 0, 1, 1, 2597.64, -5356.64, 175.9513, 5.51524, 120, 0, 0), -- Noxious Assassin (Area: Browman Mill)
(@CGUID+2534, 45695, 0, 1, 1, 2590.12, -5347.98, 172.9523, 3.857178, 120, 0, 0), -- Slain Scourge Trooper (Area: Browman Mill)
(@CGUID+2535, 45695, 0, 1, 1, 2659.98, -5367.99, 157.0503, 3.857178, 120, 0, 0), -- Slain Scourge Trooper (Area: Browman Mill)
(@CGUID+2536, 45695, 0, 1, 1, 2644.52, -5359.65, 159.1583, 0, 120, 0, 0), -- Slain Scourge Trooper (Area: Browman Mill)
(@CGUID+2537, 8542, 0, 1, 1, 2675.508, -5350.657, 157.0769, 0.465831, 120, 0, 0), -- Death Singer (Area: Browman Mill)
(@CGUID+2538, 45695, 0, 1, 1, 2704.56, -5357.66, 160.1413, 0, 120, 0, 0), -- Slain Scourge Trooper (Area: Browman Mill)
(@CGUID+2539, 45695, 0, 1, 1, 2672, -5296.26, 151.8103, 3.857178, 120, 0, 0), -- Slain Scourge Trooper (Area: Browman Mill)
(@CGUID+2540, 8532, 0, 1, 1, 2682.282, -5310.14, 154.6326, 0.350283, 120, 0, 0), -- Diseased Flayer (Area: Browman Mill)
(@CGUID+2541, 8532, 0, 1, 1, 2747.444, -5353.308, 159.7646, 4.174727, 120, 0, 0), -- Diseased Flayer (Area: The Noxious Glade)
(@CGUID+2542, 8542, 0, 1, 1, 2717.449, -5354.264, 160.448, 5.08237, 120, 0, 0), -- Death Singer (Area: The Noxious Glade)
(@CGUID+2543, 45695, 0, 1, 1, 2749.03, -5356.49, 161.0683, 3.857178, 120, 0, 0), -- Slain Scourge Trooper (Area: The Noxious Glade)
(@CGUID+2544, 8532, 0, 1, 1, 2797.444, -5380.194, 161.5607, 4.350652, 120, 0, 0), -- Diseased Flayer (Area: The Noxious Glade)
(@CGUID+2545, 8532, 0, 1, 1, 2747.176, -5385.121, 157.2277, 3.740965, 120, 0, 0), -- Diseased Flayer (Area: The Noxious Glade)
(@CGUID+2546, 8528, 0, 1, 1, 2819.284, -5386.142, 164.0066, 4.950485, 120, 0, 0), -- Dread Weaver (Area: The Noxious Glade)
(@CGUID+2547, 45691, 0, 1, 1, 2792.23, -5402.22, 162.5303, 4.24115, 120, 0, 0), -- Skullmage (Area: The Noxious Glade)
(@CGUID+2548, 45695, 0, 1, 1, 2823.69, -5376.32, 165.2103, 5.742133, 120, 0, 0), -- Slain Scourge Trooper (Area: The Noxious Glade)
(@CGUID+2549, 45691, 0, 1, 1, 2789.47, -5407.67, 162.6723, 1.099557, 120, 0, 0), -- Skullmage (Area: The Noxious Glade)
(@CGUID+2550, 45691, 0, 1, 1, 2833.8, -5399.92, 163.9823, 0.2792527, 120, 0, 0), -- Skullmage (Area: The Noxious Glade)
(@CGUID+2551, 45691, 0, 1, 1, 2840.78, -5398.23, 165.4793, 3.351032, 120, 0, 0), -- Skullmage (Area: The Noxious Glade)
(@CGUID+2552, 45695, 0, 1, 1, 2847.26, -5380.52, 169.2353, 3.857178, 120, 0, 0), -- Slain Scourge Trooper (Area: The Noxious Glade)
(@CGUID+2553, 8532, 0, 1, 1, 2814.507, -5414.569, 161.4441, 2.201302, 120, 0, 0), -- Diseased Flayer (Area: The Noxious Glade)
(@CGUID+2554, 8542, 0, 1, 1, 2712.699, -5376.126, 157.6603, 2.909673, 120, 0, 0), -- Death Singer (Area: The Noxious Glade)
(@CGUID+2555, 8528, 0, 1, 1, 2682.047, -5378.31, 157.2071, 5.394066, 120, 0, 0), -- Dread Weaver (Area: The Noxious Glade)
(@CGUID+2556, 45692, 0, 1, 1, 2686.7, -5399.68, 157.2173, 3.717551, 120, 0, 0), -- Noxious Assassin (Area: The Noxious Glade)
(@CGUID+2557, 45691, 0, 1, 1, 2736.27, -5415.5, 159.0413, 3.351032, 120, 0, 0), -- Skullmage (Area: The Noxious Glade)
(@CGUID+2558, 45692, 0, 1, 1, 2729.3, -5417.19, 159.4703, 0.2792527, 120, 0, 0), -- Noxious Assassin (Area: The Noxious Glade)
(@CGUID+2559, 45691, 0, 1, 1, 2714.66, -5421.47, 161.4073, 5.707227, 120, 0, 0), -- Skullmage (Area: The Noxious Glade)
(@CGUID+2560, 45692, 0, 1, 1, 2679.24, -5403.77, 157.1523, 0.4537856, 120, 0, 0), -- Noxious Assassin (Area: The Noxious Glade)
(@CGUID+2561, 45695, 0, 1, 1, 2723.93, -5407.91, 158.6363, 4.34587, 120, 0, 0), -- Slain Scourge Trooper (Area: The Noxious Glade)
(@CGUID+2562, 45692, 0, 1, 1, 2760.79, -5420.71, 157.9853, 0.3141593, 120, 0, 0), -- Noxious Assassin (Area: The Noxious Glade)
(@CGUID+2563, 45691, 0, 1, 1, 2766.32, -5418.98, 158.7363, 3.298672, 120, 0, 0), -- Skullmage (Area: The Noxious Glade)
(@CGUID+2564, 45695, 0, 1, 1, 2678.06, -5392.7, 157.1123, 0, 120, 0, 0), -- Slain Scourge Trooper (Area: The Noxious Glade)
(@CGUID+2565, 45695, 0, 1, 1, 2725, -5431.04, 161.5353, 3.857178, 120, 0, 0), -- Slain Scourge Trooper (Area: The Noxious Glade)
(@CGUID+2566, 45695, 0, 1, 1, 2777.96, -5415.58, 161.1353, 0, 120, 0, 0), -- Slain Scourge Trooper (Area: The Noxious Glade)
(@CGUID+2567, 45691, 0, 1, 1, 2718.47, -5452.13, 159.1903, 3.351032, 120, 0, 0), -- Skullmage (Area: The Noxious Glade)
(@CGUID+2568, 45691, 0, 1, 1, 2711.5, -5453.82, 159.7823, 0.2792527, 120, 0, 0), -- Skullmage (Area: The Noxious Glade)
(@CGUID+2569, 45695, 0, 1, 1, 2715.5, -5444, 159.7143, 0, 120, 0, 0), -- Slain Scourge Trooper (Area: The Noxious Glade)
(@CGUID+2570, 8528, 0, 1, 1, 2616.436, -5421.716, 159.4214, 5.074718, 120, 0, 0), -- Dread Weaver (Area: The Noxious Glade)
(@CGUID+2571, 45692, 0, 1, 1, 2614.1, -5433.64, 161.4293, 3.351032, 120, 0, 0), -- Noxious Assassin (Area: The Noxious Glade)
(@CGUID+2572, 8532, 0, 1, 1, 2650, -5430.759, 157.0512, 4.712389, 120, 0, 0), -- Diseased Flayer (Area: The Noxious Glade)
(@CGUID+2573, 45691, 0, 1, 1, 2607.12, -5435.33, 161.2803, 0.2792527, 120, 0, 0), -- Skullmage (Area: The Noxious Glade)
(@CGUID+2574, 45695, 0, 1, 1, 2648.52, -5424.1, 157.1183, 3.857178, 120, 0, 0), -- Slain Scourge Trooper (Area: The Noxious Glade)
(@CGUID+2575, 45695, 0, 1, 1, 2610.05, -5430.31, 160.6613, 4.817109, 120, 0, 0), -- Slain Scourge Trooper (Area: The Noxious Glade)
(@CGUID+2576, 9447, 0, 1, 1, 1728.188, -5388.362, 81.06277, 2.076942, 120, 0, 0), -- Scarlet Warder (Area: Tyr's Hand)
(@CGUID+2577, 9447, 0, 1, 1, 1779.415, -5379.07, 77.98157, 2.312449, 120, 0, 0), -- Scarlet Warder (Area: Tyr's Hand) (possible waypoints or random movement)
(@CGUID+2578, 9449, 0, 1, 1, 1748.58, -5405.63, 82.39163, 3.752458, 120, 0, 0), -- Scarlet Cleric (Area: Tyr's Hand)
(@CGUID+2579, 9452, 0, 1, 1, 1759.51, -5395.4, 82.39163, 3.036873, 120, 0, 0), -- Scarlet Enchanter (Area: Tyr's Hand)
(@CGUID+2580, 9449, 0, 1, 1, 1757.08, -5395.54, 82.39163, 0.2617994, 120, 0, 0), -- Scarlet Cleric (Area: Tyr's Hand)
(@CGUID+2581, 9447, 0, 1, 1, 1739.429, -5380.873, 81.04136, 2.303835, 120, 0, 0), -- Scarlet Warder (Area: Tyr's Hand)
(@CGUID+2582, 9452, 0, 1, 1, 1681.578, -5381.488, 74.55399, 5.620132, 120, 0, 0), -- Scarlet Enchanter (Area: Tyr's Hand) (possible waypoints or random movement)
(@CGUID+2583, 9447, 0, 1, 1, 1640.397, -5353.792, 74.03087, 6.038471, 120, 0, 0), -- Scarlet Warder (Area: Tyr's Hand) (possible waypoints or random movement)
(@CGUID+2584, 9452, 0, 1, 1, 1656.07, -5375.309, 74.71073, 0.8912182, 120, 0, 0), -- Scarlet Enchanter (Area: Tyr's Hand) (possible waypoints or random movement)
(@CGUID+2585, 9447, 0, 1, 1, 1627.842, -5388.023, 74.02294, 0.715585, 120, 0, 0), -- Scarlet Warder (Area: Tyr's Hand)
(@CGUID+2586, 9447, 0, 1, 1, 1632.194, -5394.348, 73.91244, 0.7853982, 120, 0, 0), -- Scarlet Warder (Area: Tyr's Hand)
(@CGUID+2587, 9447, 0, 1, 1, 1608.782, -5402.47, 75.7878, 4.153883, 120, 0, 0), -- Scarlet Warder (Area: Tyr's Hand)
(@CGUID+2588, 9448, 0, 1, 1, 1546.764, -5481.327, 100.207, 1.083402, 120, 0, 0), -- Scarlet Praetorian (Area: Tyr's Hand) (possible waypoints or random movement)
(@CGUID+2589, 9448, 0, 1, 1, 1572.59, -5485.98, 101.0088, 3.316923, 120, 0, 0), -- Scarlet Praetorian (Area: Tyr's Hand) (possible waypoints or random movement)
(@CGUID+2590, 9450, 0, 1, 1, 1556.423, -5451.646, 97.31561, 4.370549, 120, 0, 0), -- Scarlet Curate (Area: Tyr's Hand) (possible waypoints or random movement)
(@CGUID+2591, 9448, 0, 1, 1, 1568.73, -5434.4, 97.64503, 1.134464, 120, 0, 0), -- Scarlet Praetorian (Area: Tyr's Hand)
(@CGUID+2592, 9448, 0, 1, 1, 1588.488, -5457.275, 103.8138, 5.002998, 120, 0, 0), -- Scarlet Praetorian (Area: Tyr's Hand) (possible waypoints or random movement)
(@CGUID+2593, 46138, 0, 1, 1, 1569.63, -5409.76, 75.22194, 0, 120, 0, 0), -- Argent Centurion (Area: Tyr's Hand)
(@CGUID+2594, 9448, 0, 1, 1, 1613.42, -5442.63, 97.82864, 1.675516, 120, 0, 0), -- Scarlet Praetorian (Area: Tyr's Hand)
(@CGUID+2595, 9452, 0, 1, 1, 1610.847, -5410.216, 75.7878, 3.368485, 120, 0, 0), -- Scarlet Enchanter (Area: Tyr's Hand)
(@CGUID+2596, 9449, 0, 1, 1, 1605.728, -5409.322, 76.48225, 0.6632251, 120, 0, 0), -- Scarlet Cleric (Area: Tyr's Hand)
(@CGUID+2597, 9447, 0, 1, 1, 1680.581, -5414.246, 74.32334, 1.388334, 120, 0, 0), -- Scarlet Warder (Area: Tyr's Hand) (possible waypoints or random movement)
(@CGUID+2598, 9448, 0, 1, 1, 1642.18, -5438.89, 88.24574, 1.186824, 120, 0, 0), -- Scarlet Praetorian (Area: Tyr's Hand)
(@CGUID+2599, 9448, 0, 1, 1, 1655.88, -5444.78, 87.70724, 1.32645, 120, 0, 0), -- Scarlet Praetorian (Area: Tyr's Hand)
(@CGUID+2600, 9452, 0, 1, 1, 1730.58, -5412.21, 82.39153, 0.06981317, 120, 0, 0), -- Scarlet Enchanter (Area: Tyr's Hand)
(@CGUID+2601, 9449, 0, 1, 1, 1733.15, -5412.42, 82.39163, 2.9147, 120, 0, 0), -- Scarlet Cleric (Area: Tyr's Hand)
(@CGUID+2602, 9448, 0, 1, 1, 1672.75, -5473.34, 99.43263, 0.9075712, 120, 0, 0), -- Scarlet Praetorian (Area: Tyr's Hand)
(@CGUID+2603, 9449, 0, 1, 1, 1746.19, -5407.06, 82.39153, 0.4537856, 120, 0, 0), -- Scarlet Cleric (Area: Tyr's Hand)
(@CGUID+2604, 9449, 0, 1, 1, 1743.24, -5434.36, 89.61874, 1.029744, 120, 0, 0), -- Scarlet Cleric (Area: Tyr's Hand)
(@CGUID+2605, 9449, 0, 1, 1, 1744.56, -5432.38, 89.62044, 4.08407, 120, 0, 0), -- Scarlet Cleric (Area: Tyr's Hand)
(@CGUID+2606, 9449, 0, 1, 1, 1751.304, -5413.09, 81.94683, 3.180379, 120, 0, 0), -- Scarlet Cleric (Area: Tyr's Hand) (possible waypoints or random movement)
(@CGUID+2607, 9449, 0, 1, 1, 1758.1, -5428.92, 103.9211, 3.560149, 120, 0, 0), -- Scarlet Cleric (Area: Tyr's Hand) (possible waypoints or random movement)
(@CGUID+2608, 9449, 0, 1, 1, 1736.49, -5459.58, 89.61983, 5.393067, 120, 0, 0), -- Scarlet Cleric (Area: Tyr's Hand)
(@CGUID+2609, 9447, 0, 1, 1, 1782.971, -5479.879, 77.1655, 3.237471, 120, 0, 0), -- Scarlet Warder (Area: Tyr's Hand) (possible waypoints or random movement)
(@CGUID+2610, 9447, 0, 1, 1, 1771.007, -5442.072, 81.01994, 3.769911, 120, 0, 0), -- Scarlet Warder (Area: Tyr's Hand)
(@CGUID+2611, 9452, 0, 1, 1, 1812.249, -5442.298, 79.49048, 2.221385, 120, 0, 0), -- Scarlet Enchanter (Area: Tyr's Hand) (possible waypoints or random movement)
(@CGUID+2612, 9452, 0, 1, 1, 1799.8, -5432.78, 89.76663, 1.029744, 120, 0, 0), -- Scarlet Enchanter (Area: Tyr's Hand)
(@CGUID+2613, 9449, 0, 1, 1, 1749.14, -5463.99, 89.61844, 0.3665192, 120, 0, 0), -- Scarlet Cleric (Area: Tyr's Hand)
(@CGUID+2614, 9449, 0, 1, 1, 1847.323, -5423.043, 87.21655, 1.356154, 120, 0, 0), -- Scarlet Cleric (Area: Tyr's Hand) (possible waypoints or random movement)
(@CGUID+2615, 9447, 0, 1, 1, 1767.698, -5444.961, 81.01994, 0.7679449, 120, 0, 0), -- Scarlet Warder (Area: Tyr's Hand)
(@CGUID+2616, 9452, 0, 1, 1, 1738.15, -5461.6, 89.61844, 2.251475, 120, 0, 0), -- Scarlet Enchanter (Area: Tyr's Hand)
(@CGUID+2617, 9452, 0, 1, 1, 1800.55, -5419.82, 82.39864, 5.078908, 120, 0, 0), -- Scarlet Enchanter (Area: Tyr's Hand)
(@CGUID+2618, 9452, 0, 1, 1, 1751.7, -5462.42, 89.62483, 3.839724, 120, 0, 0), -- Scarlet Enchanter (Area: Tyr's Hand)
(@CGUID+2619, 9449, 0, 1, 1, 1747.88, -5463.74, 82.39284, 0.6981317, 120, 0, 0), -- Scarlet Cleric (Area: Tyr's Hand)
(@CGUID+2620, 9452, 0, 1, 1, 1801.78, -5430.02, 89.76643, 4.031711, 120, 0, 0), -- Scarlet Enchanter (Area: Tyr's Hand)
(@CGUID+2621, 9449, 0, 1, 1, 1803.24, -5422.34, 82.39513, 2.548181, 120, 0, 0), -- Scarlet Cleric (Area: Tyr's Hand)
(@CGUID+2622, 9452, 0, 1, 1, 1800.24, -5424.14, 82.39264, 1.37881, 120, 0, 0), -- Scarlet Enchanter (Area: Tyr's Hand)
(@CGUID+2623, 9452, 0, 1, 1, 1749.51, -5462.5, 82.39274, 4.014257, 120, 0, 0), -- Scarlet Enchanter (Area: Tyr's Hand)
(@CGUID+2624, 9452, 0, 1, 1, 1778.98, -5422.72, 82.39464, 5.305801, 120, 0, 0), -- Scarlet Enchanter (Area: Tyr's Hand)
(@CGUID+2625, 9452, 0, 1, 1, 1780.65, -5425.06, 82.39133, 2.234021, 120, 0, 0), -- Scarlet Enchanter (Area: Tyr's Hand)
(@CGUID+2626, 9449, 0, 1, 1, 1859.692, -5468.402, 122.9667, 4.444539, 120, 0, 0), -- Scarlet Cleric (Area: Tyr's Hand) (possible waypoints or random movement)
(@CGUID+2627, 9452, 0, 1, 1, 1874.333, -5464.939, 120.2424, 3.583828, 120, 0, 0), -- Scarlet Enchanter (Area: Tyr's Hand) (possible waypoints or random movement)
(@CGUID+2628, 32520, 0, 1, 1, -6305.162, 5582.533, -1172.063, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Death's Breach)
(@CGUID+2629, 32520, 0, 1, 1, -6014.71, 5479.63, -1208.007, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Death's Breach)
(@CGUID+2630, 32520, 0, 1, 1, -5691.65, 5556.92, -1154.687, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Death's Breach)
(@CGUID+2631, 32520, 0, 1, 1, -6148.39, 5539.97, -1207.787, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Death's Breach)
(@CGUID+2632, 29202, 0, 1, 1, 2483.646, -5473.944, 444.751, 4.555309, 120, 0, 0), -- Knight of the Ebon Blade (Area: Death's Breach)
(@CGUID+2633, 8528, 0, 1, 1, 2617.523, -5461.259, 159.2155, 4.114207, 120, 0, 0), -- Dread Weaver (Area: Death's Breach)
(@CGUID+2634, 8532, 0, 1, 1, 2647.917, -5468.75, 159.257, 4.837814, 120, 0, 0), -- Diseased Flayer (Area: Death's Breach)
(@CGUID+2635, 45695, 0, 1, 1, 2646.26, -5466.02, 160.3563, 0, 120, 0, 0), -- Slain Scourge Trooper (Area: Death's Breach)
(@CGUID+2636, 8542, 0, 1, 1, 2675.002, -5459.82, 157.2551, 4.469145, 120, 0, 0), -- Death Singer (Area: The Noxious Glade)
(@CGUID+2637, 10821, 0, 1, 1, 2652.894, -5479.031, 158.2838, 4.660029, 120, 0, 0), -- Hed'mush the Rotting (Area: The Noxious Glade)
(@CGUID+2638, 8542, 0, 1, 1, 2712.54, -5474.998, 157.5151, 0.1470068, 120, 0, 0), -- Death Singer (Area: The Noxious Glade)
(@CGUID+2639, 8532, 0, 1, 1, 2759.264, -5455.189, 157.6835, 6.087743, 120, 0, 0), -- Diseased Flayer (Area: The Noxious Glade)
(@CGUID+2640, 8532, 0, 1, 1, 2790.399, -5456.733, 160.8156, 5.311633, 120, 0, 0), -- Diseased Flayer (Area: The Noxious Glade)
(@CGUID+2641, 45695, 0, 1, 1, 2772.12, -5461.43, 158.8693, 4.08407, 120, 0, 0), -- Slain Scourge Trooper (Area: The Noxious Glade)
(@CGUID+2642, 8532, 0, 1, 1, 2815.501, -5452.562, 158.3042, 3.983366, 120, 0, 0), -- Diseased Flayer (Area: The Noxious Glade)
(@CGUID+2643, 45695, 0, 1, 1, 2734.9, -5488.67, 162.1523, 0, 120, 0, 0), -- Slain Scourge Trooper (Area: The Noxious Glade)
(@CGUID+2644, 45695, 0, 1, 1, 2831.52, -5435.08, 159.7003, 3.857178, 120, 0, 0), -- Slain Scourge Trooper (Area: The Noxious Glade)
(@CGUID+2645, 8545, 0, 1, 1, 2783.499, -5516.937, 162.9541, 3.822271, 120, 0, 0), -- Stitched Golem (Area: The Noxious Glade)
(@CGUID+2646, 45695, 0, 1, 1, 2774.2, -5532.81, 161.8193, 0, 120, 0, 0), -- Slain Scourge Trooper (Area: The Noxious Glade)
(@CGUID+2647, 8545, 0, 1, 1, 2789.031, -5532.774, 162.9541, 3.054326, 120, 0, 0), -- Stitched Golem (Area: The Noxious Glade)
(@CGUID+2648, 45695, 0, 1, 1, 2762.76, -5526.42, 161.8193, 0, 120, 0, 0), -- Slain Scourge Trooper (Area: The Noxious Glade)
(@CGUID+2649, 45695, 0, 1, 1, 2763.78, -5537.81, 161.8193, 3.857178, 120, 0, 0), -- Slain Scourge Trooper (Area: The Noxious Glade)
(@CGUID+2650, 8545, 0, 1, 1, 2750.627, -5546.381, 162.9541, 0.7679449, 120, 0, 0), -- Stitched Golem (Area: The Noxious Glade)
(@CGUID+2651, 45691, 0, 1, 1, 2672.47, -5501.75, 162.2123, 3.351032, 120, 0, 0), -- Skullmage (Area: The Noxious Glade)
(@CGUID+2652, 45691, 0, 1, 1, 2665.49, -5503.45, 162.3893, 0.2792527, 120, 0, 0), -- Skullmage (Area: The Noxious Glade)
(@CGUID+2653, 8545, 0, 1, 1, 2765.895, -5553.608, 162.9541, 1.553343, 120, 0, 0), -- Stitched Golem (Area: The Noxious Glade)
(@CGUID+2654, 45695, 0, 1, 1, 2681.21, -5513.25, 160.5843, 0, 120, 0, 0), -- Slain Scourge Trooper (Area: The Noxious Glade)
(@CGUID+2655, 45692, 0, 1, 1, 2710.72, -5556.21, 157.1983, 3.351032, 120, 0, 0), -- Noxious Assassin (Area: The Noxious Glade)
(@CGUID+2656, 8528, 0, 1, 1, 2684.478, -5545.865, 161.3954, 3.665099, 120, 0, 0), -- Dread Weaver (Area: The Noxious Glade)
(@CGUID+2657, 45691, 0, 1, 1, 2703.74, -5557.91, 157.1583, 0.2792527, 120, 0, 0), -- Skullmage (Area: The Noxious Glade)
(@CGUID+2658, 8528, 0, 1, 1, 2649.604, -5511.957, 159.4111, 4.253984, 120, 0, 0), -- Dread Weaver (Area: The Noxious Glade)
(@CGUID+2659, 45695, 0, 1, 1, 2696.99, -5550.35, 157.8563, 0, 120, 0, 0), -- Slain Scourge Trooper (Area: The Noxious Glade)
(@CGUID+2660, 8528, 0, 1, 1, 2621.679, -5501.361, 157.7346, 5.932609, 120, 0, 0), -- Dread Weaver (Area: The Noxious Glade)
(@CGUID+2661, 45695, 0, 1, 1, 2645.24, -5537.54, 159.1513, 4.607669, 120, 0, 0), -- Slain Scourge Trooper (Area: The Noxious Glade)
(@CGUID+2662, 45695, 0, 1, 1, 2622.34, -5494.7, 157.2853, 4.782202, 120, 0, 0), -- Slain Scourge Trooper (Area: The Noxious Glade)
(@CGUID+2663, 45692, 0, 1, 1, 2612.56, -5503.38, 158.1403, 4.45059, 120, 0, 0), -- Noxious Assassin (Area: The Noxious Glade)
(@CGUID+2664, 45691, 0, 1, 1, 2610.83, -5508.66, 158.7663, 1.27409, 120, 0, 0), -- Skullmage (Area: The Noxious Glade)
(@CGUID+2665, 8532, 0, 1, 1, 2610.486, -5532.967, 159.3467, 4.935086, 120, 0, 0), -- Diseased Flayer (Area: The Noxious Glade)
(@CGUID+2666, 8532, 0, 1, 1, 2642.796, -5553.003, 159.6765, 0.06059111, 120, 0, 0), -- Diseased Flayer (Area: The Noxious Glade)
(@CGUID+2667, 8542, 0, 1, 1, 2598.907, -5546.269, 159.3277, 0.08174956, 120, 0, 0), -- Death Singer (Area: The Noxious Glade)
(@CGUID+2668, 45691, 0, 1, 1, 2568.476, -5537.481, 163.2076, 3.351032, 120, 0, 0), -- Skullmage (Area: The Noxious Glade)
(@CGUID+2669, 45692, 0, 1, 1, 2566.03, -5537.8, 163.2383, 0.2792527, 120, 0, 0), -- Noxious Assassin (Area: The Noxious Glade)
(@CGUID+2670, 45695, 0, 1, 1, 2576.07, -5542.46, 162.7953, 0, 120, 0, 0), -- Slain Scourge Trooper (Area: The Noxious Glade)
(@CGUID+2671, 8528, 0, 1, 1, 2587.469, -5570.755, 163.5573, 2.077246, 120, 0, 0), -- Dread Weaver (Area: The Noxious Glade)
(@CGUID+2672, 29202, 0, 1, 1, 2489.257, -5503.901, 444.2185, 4.171337, 120, 0, 0), -- Knight of the Ebon Blade (Area: The Noxious Glade)
(@CGUID+2673, 29202, 0, 1, 1, 2466.962, -5499.018, 444.2094, 5.009095, 120, 0, 0), -- Knight of the Ebon Blade (Area: The Noxious Glade)
(@CGUID+2674, 29196, 0, 1, 1, 2527.734, -5549.208, 377.0356, 3.735005, 120, 0, 0), -- Lord Thorval (Area: The Noxious Glade)
(@CGUID+2675, 29212, 0, 1, 1, 2482.538, -5524.348, 420.6523, 3.816579, 120, 0, 0), -- Risen Drudge (Area: The Noxious Glade) (possible waypoints or random movement)
(@CGUID+2676, 29202, 0, 1, 1, 2480.711, -5522.02, 376.8774, 4.520403, 120, 0, 0), -- Knight of the Ebon Blade (Area: The Noxious Glade)
(@CGUID+2677, 29212, 0, 1, 1, 2482.087, -5531.641, 421.7339, 0.4886922, 120, 0, 0), -- Risen Drudge (Area: The Noxious Glade)
(@CGUID+2678, 29202, 0, 1, 1, 2497.074, -5543.441, 376.8893, 5.656611, 120, 0, 0), -- Knight of the Ebon Blade (Area: The Noxious Glade) (possible waypoints or random movement)
(@CGUID+2679, 29202, 0, 1, 1, 2498.803, -5540.998, 376.8894, 5.66203, 120, 0, 0), -- Knight of the Ebon Blade (Area: The Noxious Glade) (possible waypoints or random movement)
(@CGUID+2680, 28489, 0, 1, 1, 2522.354, -5553.905, 377.1288, 0.7330383, 120, 0, 0), -- Disciple of Blood (Area: The Noxious Glade)
(@CGUID+2681, 28489, 0, 1, 1, 2518.74, -5554.064, 376.999, 0.4886922, 120, 0, 0), -- Disciple of Blood (Area: The Noxious Glade)
(@CGUID+2682, 28489, 0, 1, 1, 2517.605, -5551.747, 377.1176, 0.3665192, 120, 0, 0), -- Disciple of Blood (Area: The Noxious Glade)
(@CGUID+2683, 28489, 0, 1, 1, 2524.185, -5556.05, 377.1371, 0.8203048, 120, 0, 0), -- Disciple of Blood (Area: The Noxious Glade)
(@CGUID+2684, 28489, 0, 1, 1, 2522.062, -5558.467, 377.1423, 1.308997, 120, 0, 0), -- Disciple of Blood (Area: The Noxious Glade)
(@CGUID+2685, 28489, 0, 1, 1, 2521.029, -5552.166, 377.2014, 0.5759587, 120, 0, 0), -- Disciple of Blood (Area: The Noxious Glade)
(@CGUID+2686, 28489, 0, 1, 1, 2520.163, -5556.398, 376.9852, 0.715585, 120, 0, 0), -- Disciple of Blood (Area: The Noxious Glade)
(@CGUID+2687, 28489, 0, 1, 1, 2519.863, -5549.729, 377.1529, 0.1047198, 120, 0, 0), -- Disciple of Blood (Area: The Noxious Glade)
(@CGUID+2688, 29202, 0, 1, 1, 2552.673, -5468.972, 359.3972, 5.758056, 120, 0, 0), -- Knight of the Ebon Blade (Area: The Noxious Glade) (possible waypoints or random movement)
(@CGUID+2689, 29202, 0, 1, 1, 2468.401, -5519.695, 376.8769, 4.590216, 120, 0, 0), -- Knight of the Ebon Blade (Area: Death's Breach)
(@CGUID+2690, 28488, 0, 1, 1, 2435.753, -5525.169, 376.9718, 3.874631, 120, 0, 0), -- Coldwraith (Area: Death's Breach)
(@CGUID+2691, 28488, 0, 1, 1, 2416.655, -5514.503, 377.0274, 5.201081, 120, 0, 0), -- Coldwraith (Area: Death's Breach)
(@CGUID+2692, 28490, 0, 1, 1, 2428.454, -5533.668, 377.1337, 2.460914, 120, 0, 0), -- Disciple of Frost (Area: Death's Breach)
(@CGUID+2693, 28490, 0, 1, 1, 2421.77, -5527.67, 377.0467, 1.773284, 120, 0, 0), -- Disciple of Frost (Area: Death's Breach)
(@CGUID+2694, 28490, 0, 1, 1, 2425.688, -5535.384, 377.1221, 2.321288, 120, 0, 0), -- Disciple of Frost (Area: Death's Breach)
(@CGUID+2695, 28490, 0, 1, 1, 2423.28, -5534.07, 377.0397, 2.181662, 120, 0, 0), -- Disciple of Frost (Area: Death's Breach)
(@CGUID+2696, 29194, 0, 1, 1, 2413.916, -5524.467, 377.1253, 5.253441, 120, 0, 0), -- Amal'thazad (Area: Death's Breach)
(@CGUID+2697, 28490, 0, 1, 1, 2422.854, -5536.903, 377.1628, 2.164208, 120, 0, 0), -- Disciple of Frost (Area: Death's Breach)
(@CGUID+2698, 28490, 0, 1, 1, 2420.65, -5535.74, 377.031, 2.094395, 120, 0, 0), -- Disciple of Frost (Area: Death's Breach) (possible waypoints or random movement)
(@CGUID+2699, 28490, 0, 1, 1, 2420.328, -5538.636, 377.1157, 2.024582, 120, 0, 0), -- Disciple of Frost (Area: Death's Breach)
(@CGUID+2700, 28490, 0, 1, 1, 2418, -5537.15, 377.0227, 1.954769, 120, 0, 0), -- Disciple of Frost (Area: Death's Breach) (possible waypoints or random movement)
(@CGUID+2701, 28488, 0, 1, 1, 2404.684, -5521.942, 377.0011, 5.253441, 120, 0, 0), -- Coldwraith (Area: Death's Breach)
(@CGUID+2702, 28490, 0, 1, 1, 2418.019, -5539.932, 377.1363, 1.902409, 120, 0, 0), -- Disciple of Frost (Area: Death's Breach)
(@CGUID+2703, 28488, 0, 1, 1, 2406.482, -5543.837, 376.8718, 0.3665192, 120, 0, 0), -- Coldwraith (Area: Death's Breach)
(@CGUID+2704, 29246, 0, 1, 1, 2460.329, -5593.721, 367.4763, 3.700098, 120, 0, 0), -- Highlord Darion Mograine (Area: Death's Breach)
(@CGUID+2705, 29212, 0, 1, 1, 2470.56, -5527.152, 420.7336, 3.700098, 120, 0, 0), -- Risen Drudge (Area: Death's Breach)
(@CGUID+2706, 29212, 0, 1, 1, 2464.405, -5525.948, 420.7271, 5.707227, 120, 0, 0), -- Risen Drudge (Area: Death's Breach)
(@CGUID+2707, 29212, 0, 1, 1, 2484.624, -5535.416, 421.5325, 1.745329, 120, 0, 0), -- Risen Drudge (Area: Death's Breach)
(@CGUID+2708, 29212, 0, 1, 1, 2465.993, -5532.943, 420.7317, 1.186824, 120, 0, 0), -- Risen Drudge (Area: Death's Breach)
(@CGUID+2709, 29212, 0, 1, 1, 2485.909, -5540.856, 420.7269, 4.13643, 120, 0, 0), -- Risen Drudge (Area: Death's Breach)
(@CGUID+2710, 29212, 0, 1, 1, 2478.678, -5542.378, 420.727, 2.583087, 120, 0, 0), -- Risen Drudge (Area: Death's Breach)
(@CGUID+2711, 29212, 0, 1, 1, 2467.173, -5539.972, 420.727, 4.223697, 120, 0, 0), -- Risen Drudge (Area: Death's Breach)
(@CGUID+2712, 29212, 0, 1, 1, 2461.296, -5536.881, 421.9283, 3.804818, 120, 0, 0), -- Risen Drudge (Area: Death's Breach)
(@CGUID+2713, 29212, 0, 1, 1, 2484.25, -5545.9, 420.7271, 0.5585054, 120, 0, 0), -- Risen Drudge (Area: Death's Breach)
(@CGUID+2714, 29212, 0, 1, 1, 2456.271, -5538.806, 420.727, 1.012291, 120, 0, 0), -- Risen Drudge (Area: Death's Breach)
(@CGUID+2715, 29212, 0, 1, 1, 2489.538, -5545.515, 421.7964, 4.223697, 120, 0, 0), -- Risen Drudge (Area: Death's Breach)
(@CGUID+2716, 29212, 0, 1, 1, 2450.146, -5536.749, 421.4908, 1.972222, 120, 0, 0), -- Risen Drudge (Area: Death's Breach)
(@CGUID+2717, 29202, 0, 1, 1, 2457.421, -5546.548, 420.6451, 3.142844, 120, 0, 0), -- Knight of the Ebon Blade (Area: Death's Breach) (possible waypoints or random movement)
(@CGUID+2718, 29202, 0, 1, 1, 2457.464, -5549.549, 420.6438, 3.142411, 120, 0, 0), -- Knight of the Ebon Blade (Area: Death's Breach) (possible waypoints or random movement)
(@CGUID+2719, 29202, 0, 1, 1, 2494.948, -5556.854, 420.7271, 3.857178, 120, 0, 0), -- Knight of the Ebon Blade (Area: Death's Breach)
(@CGUID+2720, 29212, 0, 1, 1, 2483.071, -5557.72, 420.6836, 5.894753, 120, 0, 0), -- Risen Drudge (Area: Death's Breach) (possible waypoints or random movement)
(@CGUID+2721, 29205, 0, 1, 1, 2453.393, -5551.946, 420.6351, 3.057629, 120, 0, 0), -- Corpulous (Area: Death's Breach) (possible waypoints or random movement)
(@CGUID+2722, 29202, 0, 1, 1, 2442.04, -5547.075, 420.7271, 5.026548, 120, 0, 0), -- Knight of the Ebon Blade (Area: Death's Breach)
(@CGUID+2723, 29212, 0, 1, 1, 2444.857, -5562.464, 418.8052, 0.8037112, 120, 0, 0), -- Risen Drudge (Area: Death's Breach) (possible waypoints or random movement)
(@CGUID+2724, 28481, 0, 1, 1, 2427.135, -5544.374, 423.5176, 3.281219, 120, 0, 0), -- Runeforge (SE) (Area: Death's Breach)
(@CGUID+2725, 29239, 0, 1, 1, 2462.162, -5519.814, 445.0187, 5.096361, 120, 0, 0), -- Vigilant Gargoyle (Area: Death's Breach)
(@CGUID+2726, 29202, 0, 1, 1, 2424.204, -5558.944, 420.6433, 5.497787, 120, 0, 0), -- Knight of the Ebon Blade (Area: Death's Breach)
(@CGUID+2727, 29202, 0, 1, 1, 2370.312, -5564.293, 444.2101, 5.8294, 120, 0, 0), -- Knight of the Ebon Blade (Area: Death's Breach)
(@CGUID+2728, 9447, 0, 1, 1, 1824.174, -5480.903, 97.79605, 5.991622, 120, 0, 0), -- Scarlet Warder (Area: Tyr's Hand) (possible waypoints or random movement)
(@CGUID+2729, 9447, 0, 1, 1, 1852.414, -5497.64, 105.2756, 4.720358, 120, 0, 0), -- Scarlet Warder (Area: Tyr's Hand) (possible waypoints or random movement)
(@CGUID+2730, 9452, 0, 1, 1, 1715.288, -5485.637, 81.70779, 3.418551, 120, 0, 0), -- Scarlet Enchanter (Area: Tyr's Hand) (possible waypoints or random movement)
(@CGUID+2731, 9448, 0, 1, 1, 1698.21, -5510.18, 99.48174, 1.169371, 120, 0, 0), -- Scarlet Praetorian (Area: Tyr's Hand)
(@CGUID+2732, 9448, 0, 1, 1, 1738.142, -5521.596, 118.1221, 1.627871, 120, 0, 0), -- Scarlet Praetorian (Area: Tyr's Hand) (possible waypoints or random movement)
(@CGUID+2733, 9450, 0, 1, 1, 1584.888, -5486.767, 100.8787, 0.1228151, 120, 0, 0), -- Scarlet Curate (Area: Tyr's Hand) (possible waypoints or random movement)
(@CGUID+2734, 9448, 0, 1, 1, 1647.137, -5488.8, 100.6999, 0.6679431, 120, 0, 0), -- Scarlet Praetorian (Area: Tyr's Hand) (possible waypoints or random movement)
(@CGUID+2735, 9450, 0, 1, 1, 1654.484, -5513.075, 100.9441, 5.95888, 120, 0, 0), -- Scarlet Curate (Area: Tyr's Hand) (possible waypoints or random movement)
(@CGUID+2736, 9451, 0, 1, 1, 1686.684, -5519.566, 97.55334, 0.7853982, 120, 0, 0), -- Scarlet Archmage (Area: Tyr's Hand) (possible waypoints or random movement)
(@CGUID+2737, 9448, 0, 1, 1, 1654.88, -5535.27, 101.0903, 4.869469, 120, 0, 0), -- Scarlet Praetorian (Area: Tyr's Hand)
(@CGUID+2738, 9448, 0, 1, 1, 1654.75, -5539.3, 101.0173, 1.37881, 120, 0, 0), -- Scarlet Praetorian (Area: Tyr's Hand)
(@CGUID+2739, 9448, 0, 1, 1, 1610.27, -5509.77, 106.8153, 1.169371, 120, 0, 0), -- Scarlet Praetorian (Area: Tyr's Hand)
(@CGUID+2740, 9448, 0, 1, 1, 1625.15, -5517.64, 106.8693, 1.239184, 120, 0, 0), -- Scarlet Praetorian (Area: Tyr's Hand)
(@CGUID+2741, 9450, 0, 1, 1, 1612.623, -5488.885, 101.067, 4.788286, 120, 0, 0), -- Scarlet Curate (Area: Tyr's Hand) (possible waypoints or random movement)
(@CGUID+2742, 9451, 0, 1, 1, 1623.02, -5503.76, 103.3491, 1.099163, 120, 0, 0), -- Scarlet Archmage (Area: Tyr's Hand) (possible waypoints or random movement)
(@CGUID+2743, 9448, 0, 1, 1, 1576.84, -5497.92, 100.8733, 3.665191, 120, 0, 0), -- Scarlet Praetorian (Area: Tyr's Hand)
(@CGUID+2744, 9448, 0, 1, 1, 1573.52, -5500.25, 100.8693, 0.7330383, 120, 0, 0), -- Scarlet Praetorian (Area: Tyr's Hand)
(@CGUID+2745, 9451, 0, 1, 1, 1553.829, -5512.988, 101.0007, 1.575836, 120, 0, 0), -- Scarlet Archmage (Area: Tyr's Hand) (possible waypoints or random movement)
(@CGUID+2746, 9450, 0, 1, 1, 1545.98, -5561.83, 100.9123, 4.694936, 120, 0, 0), -- Scarlet Curate (Area: Tyr's Hand)
(@CGUID+2747, 9450, 0, 1, 1, 1586.85, -5611.75, 111.2543, 1.012291, 120, 0, 0), -- Scarlet Curate (Area: Tyr's Hand)
(@CGUID+2748, 9451, 0, 1, 1, 1589.36, -5607.69, 111.2543, 4.171337, 120, 0, 0), -- Scarlet Archmage (Area: Tyr's Hand)
(@CGUID+2749, 9450, 0, 1, 1, 1622.268, -5605.642, 101.0934, 0.3702351, 120, 0, 0), -- Scarlet Curate (Area: Tyr's Hand) (possible waypoints or random movement)
(@CGUID+2750, 9450, 0, 1, 1, 1545.66, -5566.35, 101.1203, 1.27409, 120, 0, 0), -- Scarlet Curate (Area: Tyr's Hand)
(@CGUID+2751, 9450, 0, 1, 1, 1547.64, -5561.78, 100.8843, 4.276057, 120, 0, 0), -- Scarlet Curate (Area: Tyr's Hand)
(@CGUID+2752, 9448, 0, 1, 1, 1569.26, -5569.3, 111.2573, 0.1047198, 120, 0, 0), -- Scarlet Praetorian (Area: Tyr's Hand)
(@CGUID+2753, 9448, 0, 1, 1, 1556.89, -5596.22, 111.2543, 1.553343, 120, 0, 0), -- Scarlet Praetorian (Area: Tyr's Hand)
(@CGUID+2754, 9448, 0, 1, 1, 1557.1, -5592.93, 111.2543, 4.607669, 120, 0, 0), -- Scarlet Praetorian (Area: Tyr's Hand)
(@CGUID+2755, 9451, 0, 1, 1, 1606.6, -5573.69, 111.2543, 3.525565, 120, 0, 0), -- Scarlet Archmage (Area: Tyr's Hand)
(@CGUID+2756, 9448, 0, 1, 1, 1713.987, -5582.949, 106.897, 5.465314, 120, 0, 0), -- Scarlet Praetorian (Area: Tyr's Hand) (possible waypoints or random movement)
(@CGUID+2757, 9448, 0, 1, 1, 1716.146, -5549.479, 106.3122, 3.206664, 120, 0, 0), -- Scarlet Praetorian (Area: Tyr's Hand) (possible waypoints or random movement)
(@CGUID+2758, 9448, 0, 1, 1, 1677.89, -5554.002, 101.3302, 4.583087, 120, 0, 0), -- Scarlet Praetorian (Area: Tyr's Hand) (possible waypoints or random movement)
(@CGUID+2759, 9448, 0, 1, 1, 1703.87, -5550.47, 103.2453, 4.18879, 120, 0, 0), -- Scarlet Praetorian (Area: Tyr's Hand)
(@CGUID+2760, 9450, 0, 1, 1, 1675.48, -5567.38, 101.0973, 6.161012, 120, 0, 0), -- Scarlet Curate (Area: Tyr's Hand)
(@CGUID+2761, 9451, 0, 1, 1, 1663.3, -5589.9, 101.2773, 2.251475, 120, 0, 0), -- Scarlet Archmage (Area: Tyr's Hand)
(@CGUID+2762, 9450, 0, 1, 1, 1662.01, -5588.32, 101.2783, 5.393067, 120, 0, 0), -- Scarlet Curate (Area: Tyr's Hand)
(@CGUID+2763, 9450, 0, 1, 1, 1678.87, -5567.77, 101.1013, 2.9147, 120, 0, 0), -- Scarlet Curate (Area: Tyr's Hand)
(@CGUID+2764, 9450, 0, 1, 1, 1702.3, -5553.33, 103.0553, 1.082104, 120, 0, 0), -- Scarlet Curate (Area: Tyr's Hand)
(@CGUID+2765, 9451, 0, 1, 1, 1677.116, -5594.38, 101.2129, 3.071528, 120, 0, 0), -- Scarlet Archmage (Area: Tyr's Hand) (possible waypoints or random movement)
(@CGUID+2766, 9448, 0, 1, 1, 1740.257, -5560.282, 118.4555, 4.353884, 120, 0, 0), -- Scarlet Praetorian (Area: Tyr's Hand) (possible waypoints or random movement)
(@CGUID+2767, 29202, 0, 1, 1, 2340.862, -5570.329, 444.7504, 6.126106, 120, 0, 0), -- Knight of the Ebon Blade (Area: Death's Breach)
(@CGUID+2768, 29202, 0, 1, 1, 2388.925, -5573.381, 376.8891, 5.986479, 120, 0, 0), -- Knight of the Ebon Blade (Area: Death's Breach)
(@CGUID+2769, 29202, 0, 1, 1, 2386.512, -5585.671, 376.8744, 6.161012, 120, 0, 0), -- Knight of the Ebon Blade (Area: Death's Breach)
(@CGUID+2770, 28490, 0, 1, 1, 2425.601, -5532.44, 377.0477, 2.286381, 120, 0, 0), -- Disciple of Frost (Area: Death's Breach)
(@CGUID+2771, 29202, 0, 1, 1, 2433.547, -5583.139, 366.8189, 4.302092, 120, 0, 0), -- Knight of the Ebon Blade (Area: Death's Breach) (possible waypoints or random movement)
(@CGUID+2772, 29207, 0, 1, 1, 2387.36, -5579.475, 420.7368, 0, 120, 0, 0), -- Gangrenus (Area: Death's Breach)
(@CGUID+2773, 29208, 0, 1, 1, 2404.761, -5564.087, 420.7328, 5.218534, 120, 0, 0), -- Fester (Area: Death's Breach)
(@CGUID+2774, 29203, 0, 1, 1, 2395.994, -5587.665, 420.7331, 1.43117, 120, 0, 0), -- Alchemist Karloff (Area: Death's Breach)
(@CGUID+2775, 29212, 0, 1, 1, 2421.394, -5561.413, 420.727, 0.2268928, 120, 0, 0), -- Risen Drudge (Area: Death's Breach)
(@CGUID+2776, 28512, 0, 1, 1, 2402.979, -5593.026, 420.7296, 0.418879, 120, 0, 0), -- Quartermaster Ozorg (Area: Death's Breach)
(@CGUID+2777, 29212, 0, 1, 1, 2404.609, -5593.247, 420.727, 1.43117, 120, 0, 0), -- Risen Drudge (Area: Death's Breach)
(@CGUID+2778, 29212, 0, 1, 1, 2402.766, -5595.081, 420.727, 5.218534, 120, 0, 0), -- Risen Drudge (Area: Death's Breach)
(@CGUID+2779, 29212, 0, 1, 1, 2408.747, -5593.02, 420.7269, 4.502949, 120, 0, 0), -- Risen Drudge (Area: Death's Breach)
(@CGUID+2780, 29212, 0, 1, 1, 2406.258, -5597.757, 421.7339, 1.22173, 120, 0, 0), -- Risen Drudge (Area: Death's Breach)
(@CGUID+2781, 29202, 0, 1, 1, 2365.639, -5587.085, 444.2076, 0.296706, 120, 0, 0), -- Knight of the Ebon Blade (Area: Death's Breach)
(@CGUID+2782, 32546, 0, 1, 1, 2438.146, -5586.978, 415.7474, 5.951573, 120, 0, 0), -- Ebon Knight's Training Dummy (Area: Death's Breach)
(@CGUID+2783, 32546, 0, 1, 1, 2437.42, -5592.109, 415.7474, 6.178465, 120, 0, 0), -- Ebon Knight's Training Dummy (Area: Death's Breach)
(@CGUID+2784, 29212, 0, 1, 1, 2427.133, -5598.46, 420.3313, 0.02785118, 120, 0, 0), -- Risen Drudge (Area: Death's Breach) (possible waypoints or random movement)
(@CGUID+2785, 29202, 0, 1, 1, 2413.874, -5612.358, 420.6518, 0.3839724, 120, 0, 0), -- Knight of the Ebon Blade (Area: Death's Breach)
(@CGUID+2786, 32546, 0, 1, 1, 2437.42, -5597.992, 415.7474, 0.2443461, 120, 0, 0), -- Ebon Knight's Training Dummy (Area: Death's Breach)
(@CGUID+2787, 29239, 0, 1, 1, 2430.069, -5548.537, 444.9371, 5.235988, 120, 0, 0), -- Vigilant Gargoyle (Area: Death's Breach)
(@CGUID+2788, 32545, 0, 1, 1, 2462.959, -5570.75, 415.7474, 4.799655, 120, 0, 0), -- Initiate's Training Dummy (Area: Death's Breach)
(@CGUID+2789, 32545, 0, 1, 1, 2467.657, -5571.869, 415.7474, 4.39823, 120, 0, 0), -- Initiate's Training Dummy (Area: Death's Breach)
(@CGUID+2790, 29239, 0, 1, 1, 2478.861, -5545.291, 434.8652, 5.418281, 120, 0, 0), -- Vigilant Gargoyle (Area: Death's Breach)
(@CGUID+2791, 29239, 0, 1, 1, 2473.6, -5559.284, 465.3641, 5.874881, 120, 0, 0), -- Vigilant Gargoyle (Area: Death's Breach)
(@CGUID+2792, 29239, 0, 1, 1, 2433.529, -5607.292, 481.0385, 5.256997, 120, 0, 0), -- Vigilant Gargoyle (Area: Death's Breach)
(@CGUID+2793, 29202, 0, 1, 1, 2461.965, -5587.038, 367.4861, 4.537856, 120, 0, 0), -- Knight of the Ebon Blade (Area: Death's Breach)
(@CGUID+2794, 29202, 0, 1, 1, 2466.984, -5594.894, 367.4861, 3.001966, 120, 0, 0), -- Knight of the Ebon Blade (Area: Death's Breach)
(@CGUID+2795, 32545, 0, 1, 1, 2471.238, -5573.336, 415.7474, 4.206244, 120, 0, 0), -- Initiate's Training Dummy (Area: Death's Breach)
(@CGUID+2796, 54344, 0, 1, 1, 2460.324, -5592.964, 414.2053, 2.164208, 120, 0, 0), -- Highlord's Nemesis Trainer (Area: Death's Breach)
(@CGUID+2797, 32542, 0, 1, 1, 2482.505, -5588.266, 415.7474, 3.438299, 120, 0, 0), -- Disciple's Training Dummy (Area: Death's Breach)
(@CGUID+2798, 32542, 0, 1, 1, 2483.278, -5594.866, 415.7474, 3.141593, 120, 0, 0), -- Disciple's Training Dummy (Area: Death's Breach)
(@CGUID+2799, 29202, 0, 1, 1, 2534.365, -5601.833, 376.8704, 2.984513, 120, 0, 0), -- Knight of the Ebon Blade (Area: Death's Breach)
(@CGUID+2800, 32543, 0, 1, 1, 2444.112, -5609.518, 415.7474, 0.7504916, 120, 0, 0), -- Veteran's Training Dummy (Area: Death's Breach)
(@CGUID+2801, 32542, 0, 1, 1, 2482.475, -5599.676, 415.741, 2.670354, 120, 0, 0), -- Disciple's Training Dummy (Area: Death's Breach)
(@CGUID+2802, 28481, 0, 1, 1, 2509.343, -5560.413, 423.6569, 4.24115, 120, 0, 0), -- Runeforge (SE) (Area: Death's Breach)
(@CGUID+2803, 29202, 0, 1, 1, 2506.967, -5574.874, 420.7271, 3.508112, 120, 0, 0), -- Knight of the Ebon Blade (Area: Death's Breach)
(@CGUID+2804, 32543, 0, 1, 1, 2453.109, -5615.049, 415.7474, 1.239184, 120, 0, 0), -- Veteran's Training Dummy (Area: Death's Breach)
(@CGUID+2805, 32543, 0, 1, 1, 2457.97, -5616.42, 415.7474, 1.570796, 120, 0, 0), -- Veteran's Training Dummy (Area: Death's Breach)
(@CGUID+2806, 29212, 0, 1, 1, 2515.32, -5580.125, 420.727, 1.012291, 120, 0, 0), -- Risen Drudge (Area: Death's Breach)
(@CGUID+2807, 29212, 0, 1, 1, 2511.683, -5588.408, 420.7269, 3.211406, 120, 0, 0), -- Risen Drudge (Area: Death's Breach)
(@CGUID+2808, 29212, 0, 1, 1, 2517.07, -5584.58, 421.5742, 3.333579, 120, 0, 0), -- Risen Drudge (Area: Death's Breach)
(@CGUID+2809, 29212, 0, 1, 1, 2518.353, -5588.842, 420.7269, 1.867502, 120, 0, 0), -- Risen Drudge (Area: Death's Breach)
(@CGUID+2810, 29212, 0, 1, 1, 2516.964, -5591.084, 420.727, 2.9147, 120, 0, 0), -- Risen Drudge (Area: Death's Breach)
(@CGUID+2811, 29212, 0, 1, 1, 2521.034, -5588.507, 420.7271, 5.044002, 120, 0, 0), -- Risen Drudge (Area: Death's Breach)
(@CGUID+2812, 29212, 0, 1, 1, 2513.606, -5598.081, 420.7269, 0.5759587, 120, 0, 0), -- Risen Drudge (Area: Death's Breach)
(@CGUID+2813, 29212, 0, 1, 1, 2518.152, -5593.532, 420.7269, 4.310963, 120, 0, 0), -- Risen Drudge (Area: Death's Breach)
(@CGUID+2814, 29212, 0, 1, 1, 2526.528, -5584.294, 420.727, 3.054326, 120, 0, 0), -- Risen Drudge (Area: Death's Breach)
(@CGUID+2815, 29212, 0, 1, 1, 2524.086, -5591.037, 421.4978, 0.6108652, 120, 0, 0), -- Risen Drudge (Area: Death's Breach)
(@CGUID+2816, 29212, 0, 1, 1, 2522.954, -5595.363, 420.7269, 5.393067, 120, 0, 0), -- Risen Drudge (Area: Death's Breach)
(@CGUID+2817, 29212, 0, 1, 1, 2497.741, -5617.6, 420.6429, 4.681061, 120, 0, 0), -- Risen Drudge (Area: Death's Breach) (possible waypoints or random movement)
(@CGUID+2818, 29212, 0, 1, 1, 2522.64, -5598.557, 420.7324, 5.72468, 120, 0, 0), -- Risen Drudge (Area: Death's Breach)
(@CGUID+2819, 29239, 0, 1, 1, 2504.878, -5563.373, 444.8871, 3.769911, 120, 0, 0), -- Vigilant Gargoyle (Area: Death's Breach)
(@CGUID+2820, 29212, 0, 1, 1, 2528.409, -5593.568, 420.7269, 0, 120, 0, 0), -- Risen Drudge (Area: Death's Breach)
(@CGUID+2821, 29212, 0, 1, 1, 2521.712, -5604.536, 420.6478, 2.214407, 120, 0, 0), -- Risen Drudge (Area: Death's Breach) (possible waypoints or random movement)
(@CGUID+2822, 29239, 0, 1, 1, 2496.713, -5606.283, 448.6599, 2.798371, 120, 0, 0), -- Vigilant Gargoyle (Area: Death's Breach)
(@CGUID+2823, 29202, 0, 1, 1, 2554.673, -5599.882, 444.2119, 3.473205, 120, 0, 0), -- Knight of the Ebon Blade (Area: The Noxious Glade)
(@CGUID+2824, 29202, 0, 1, 1, 2580.039, -5616.823, 444.7513, 2.949606, 120, 0, 0), -- Knight of the Ebon Blade (Area: The Noxious Glade)
(@CGUID+2825, 29202, 0, 1, 1, 2532.164, -5613.788, 376.8933, 2.879793, 120, 0, 0), -- Knight of the Ebon Blade (Area: The Noxious Glade)
(@CGUID+2826, 29202, 0, 1, 1, 2549.993, -5622.684, 444.2156, 2.740167, 120, 0, 0), -- Knight of the Ebon Blade (Area: The Noxious Glade)
(@CGUID+2827, 29212, 0, 1, 1, 2527.187, -5613.139, 420.7269, 1.58825, 120, 0, 0), -- Risen Drudge (Area: The Noxious Glade)
(@CGUID+2828, 29212, 0, 1, 1, 2522.849, -5615.047, 420.6499, 2.239358, 120, 0, 0), -- Risen Drudge (Area: The Noxious Glade) (possible waypoints or random movement)
(@CGUID+2829, 29212, 0, 1, 1, 2511.497, -5616.823, 420.727, 4.607669, 120, 0, 0), -- Risen Drudge (Area: The Noxious Glade)
(@CGUID+2830, 29212, 0, 1, 1, 2510.671, -5619.002, 420.6484, 1.396263, 120, 0, 0), -- Risen Drudge (Area: The Noxious Glade)
(@CGUID+2831, 29212, 0, 1, 1, 2509.72, -5624.305, 420.7269, 6.126106, 120, 0, 0), -- Risen Drudge (Area: The Noxious Glade)
(@CGUID+2832, 29202, 0, 1, 1, 2496.693, -5627.605, 420.649, 2.373648, 120, 0, 0), -- Knight of the Ebon Blade (Area: The Noxious Glade)
(@CGUID+2833, 29202, 0, 1, 1, 2386.175, -5626.865, 377.0394, 0.6457718, 120, 0, 0), -- Knight of the Ebon Blade (Area: Death's Breach)
(@CGUID+2834, 29202, 0, 1, 1, 2425.724, -5630.315, 420.6523, 0.8028514, 120, 0, 0), -- Knight of the Ebon Blade (Area: Death's Breach)
(@CGUID+2835, 29212, 0, 1, 1, 2413.968, -5618.592, 420.727, 0, 120, 0, 0), -- Risen Drudge (Area: Death's Breach)
(@CGUID+2836, 29202, 0, 1, 1, 2328.815, -5543.827, 349.2052, 1.33252, 120, 0, 0), -- Knight of the Ebon Blade (Area: Death's Breach) (possible waypoints or random movement)
(@CGUID+2837, 23033, 0, 1, 1, 2333.167, -5680.443, 391.1367, 5.986479, 120, 0, 0), -- Invisible Stalker (Floating) (Area: Death's Breach)
(@CGUID+2838, 29202, 0, 1, 1, 2386.214, -5639.717, 420.884, 0.4537856, 120, 0, 0), -- Knight of the Ebon Blade (Area: Death's Breach)
(@CGUID+2839, 27928, 0, 1, 1, 2379.409, -5648.529, 382.5223, 3.735005, 120, 0, 0), -- Siouxsie the Banshee (Area: Death's Breach)
(@CGUID+2840, 28486, 0, 1, 1, 2383.754, -5649.502, 382.4386, 4.24115, 120, 0, 0), -- Squire Edwards (Area: Death's Breach)
(@CGUID+2841, 29587, 0, 1, 1, 2365.725, -5680.604, 382.3213, 2.548181, 120, 0, 0), -- Dread Commander Thalanor (Area: Death's Breach)
(@CGUID+2842, 29480, 0, 1, 1, 2348.626, -5669.289, 382.3242, 0.6457718, 120, 0, 0), -- Grimwing (Area: Death's Breach)
(@CGUID+2843, 29202, 0, 1, 1, 2346.285, -5691.395, 382.3243, 0.7330383, 120, 0, 0), -- Knight of the Ebon Blade (Area: Death's Breach)
(@CGUID+2844, 29202, 0, 1, 1, 2376.214, -5661.788, 382.4063, 0.9075712, 120, 0, 0), -- Knight of the Ebon Blade (Area: Death's Breach)
(@CGUID+2845, 29202, 0, 1, 1, 2389.445, -5645.32, 420.817, 0.7679449, 120, 0, 0), -- Knight of the Ebon Blade (Area: Death's Breach)
(@CGUID+2846, 29202, 0, 1, 1, 2364.884, -5645.578, 382.4543, 0.3665192, 120, 0, 0), -- Knight of the Ebon Blade (Area: Death's Breach)
(@CGUID+2847, 29202, 0, 1, 1, 2355.414, -5695.448, 382.3242, 1.396263, 120, 0, 0), -- Knight of the Ebon Blade (Area: Death's Breach)
(@CGUID+2848, 29589, 0, 1, 1, 2383.698, -5645.167, 420.8844, 5.637414, 120, 0, 0), -- Teleport - Heart -> Hall (EPL) (Area: Death's Breach)
(@CGUID+2849, 29588, 0, 1, 1, 2390, -5640.977, 377.1957, 3.124139, 120, 0, 0), -- Teleport - Hall -> Heart (EPL) (Area: Death's Breach)
(@CGUID+2850, 29202, 0, 1, 1, 2440.058, -5665.116, 376.8955, 1.43117, 120, 0, 0), -- Knight of the Ebon Blade (Area: Death's Breach)
(@CGUID+2851, 29202, 0, 1, 1, 2430.596, -5683.613, 444.2076, 0.9599311, 120, 0, 0), -- Knight of the Ebon Blade (Area: Death's Breach)
(@CGUID+2852, 29202, 0, 1, 1, 2402.116, -5649.424, 377.1237, 0.6108652, 120, 0, 0), -- Knight of the Ebon Blade (Area: Death's Breach)
(@CGUID+2853, 29239, 0, 1, 1, 2386.532, -5591.94, 445.1513, 0.3839724, 120, 0, 0), -- Vigilant Gargoyle (Area: Death's Breach)
(@CGUID+2854, 2110, 0, 1, 1, 2364.522, -5771.059, 151.6414, 0.03001049, 120, 0, 0), -- Black Rat (Area: Acherus: The Ebon Hold)
(@CGUID+2855, 29202, 0, 1, 1, 2452.518, -5667.423, 376.8802, 1.58825, 120, 0, 0), -- Knight of the Ebon Blade (Area: Acherus: The Ebon Hold)
(@CGUID+2856, 29202, 0, 1, 1, 2454.244, -5687.676, 444.2124, 1.832596, 120, 0, 0), -- Knight of the Ebon Blade (Area: Acherus: The Ebon Hold)
(@CGUID+2857, 29202, 0, 1, 1, 2437.187, -5713.145, 444.7509, 1.37881, 120, 0, 0), -- Knight of the Ebon Blade (Area: Acherus: The Ebon Hold)
(@CGUID+2858, 28500, 0, 1, 1, 2449.89, -5650.833, 420.6461, 2.81886, 120, 0, 0), -- Master Siegesmith Corvus (Area: Acherus: The Ebon Hold) (possible waypoints or random movement)
(@CGUID+2859, 29212, 0, 1, 1, 2451.471, -5625.125, 420.2824, 5.539331, 120, 0, 0), -- Risen Drudge (Area: Acherus: The Ebon Hold) (possible waypoints or random movement)
(@CGUID+2860, 29202, 0, 1, 1, 2478.631, -5640.125, 420.6427, 2.042035, 120, 0, 0), -- Knight of the Ebon Blade (Area: Acherus: The Ebon Hold)
(@CGUID+2861, 28491, 0, 1, 1, 2496.049, -5655.373, 377.0466, 5.899213, 120, 0, 0), -- Disciple of the Unholy (Area: Acherus: The Ebon Hold) (possible waypoints or random movement)
(@CGUID+2862, 28491, 0, 1, 1, 2495.931, -5659.509, 377.0536, 0.2268928, 120, 0, 0), -- Disciple of the Unholy (Area: Acherus: The Ebon Hold) (possible waypoints or random movement)
(@CGUID+2863, 28491, 0, 1, 1, 2499.549, -5652.182, 377.0334, 5.270895, 120, 0, 0), -- Disciple of the Unholy (Area: Acherus: The Ebon Hold) (possible waypoints or random movement)
(@CGUID+2864, 29232, 0, 1, 1, 2499.202, -5658.081, 377.1343, 6.230825, 120, 0, 0), -- Forgotten Servant (Area: Acherus: The Ebon Hold) (possible waypoints or random movement)
(@CGUID+2865, 28491, 0, 1, 1, 2497.962, -5663.596, 377.1453, 0.8552113, 120, 0, 0), -- Disciple of the Unholy (Area: Acherus: The Ebon Hold) (possible waypoints or random movement)
(@CGUID+2866, 28481, 0, 1, 1, 2493.407, -5642.389, 423.7946, 0.296706, 120, 0, 0), -- Runeforge (SE) (Area: Acherus: The Ebon Hold)
(@CGUID+2867, 28491, 0, 1, 1, 2504.285, -5651.252, 377.1074, 4.502949, 120, 0, 0), -- Disciple of the Unholy (Area: Acherus: The Ebon Hold) (possible waypoints or random movement)
(@CGUID+2868, 29232, 0, 1, 1, 2505.026, -5655.124, 377.1099, 4.537856, 120, 0, 0), -- Forgotten Servant (Area: Acherus: The Ebon Hold) (possible waypoints or random movement)
(@CGUID+2869, 28491, 0, 1, 1, 2502.22, -5664.971, 377.1331, 1.48353, 120, 0, 0), -- Disciple of the Unholy (Area: Acherus: The Ebon Hold) (possible waypoints or random movement)
(@CGUID+2870, 29232, 0, 1, 1, 2504.079, -5660.977, 377.1231, 5.445427, 120, 0, 0), -- Forgotten Servant (Area: Acherus: The Ebon Hold) (possible waypoints or random movement)
(@CGUID+2871, 28491, 0, 1, 1, 2508.124, -5652.055, 377.1011, 3.979351, 120, 0, 0), -- Disciple of the Unholy (Area: Acherus: The Ebon Hold) (possible waypoints or random movement)
(@CGUID+2872, 29195, 0, 1, 1, 2506.222, -5663.199, 377.0362, 2.234021, 120, 0, 0), -- Lady Alistra (Area: Acherus: The Ebon Hold) (possible waypoints or random movement)
(@CGUID+2873, 28491, 0, 1, 1, 2510.39, -5656.101, 377.1082, 3.385939, 120, 0, 0), -- Disciple of the Unholy (Area: Acherus: The Ebon Hold) (possible waypoints or random movement)
(@CGUID+2874, 28491, 0, 1, 1, 2510.023, -5660.275, 377.1174, 2.860915, 120, 0, 0), -- Disciple of the Unholy (Area: Acherus: The Ebon Hold) (possible waypoints or random movement)
(@CGUID+2875, 28491, 0, 1, 1, 2460.48, -5602.852, 367.5742, 4.599903, 120, 0, 0), -- Disciple of the Unholy (Area: Acherus: The Ebon Hold) (possible waypoints or random movement)
(@CGUID+2876, 28491, 0, 1, 1, 2465.336, -5597.123, 367.4795, 5.40338, 120, 0, 0), -- Disciple of the Unholy (Area: Acherus: The Ebon Hold) (possible waypoints or random movement)
(@CGUID+2877, 28491, 0, 1, 1, 2463.324, -5599.646, 367.4656, 5.30619, 120, 0, 0), -- Disciple of the Unholy (Area: Acherus: The Ebon Hold) (possible waypoints or random movement)
(@CGUID+2878, 32520, 0, 1, 1, -6305.162, 5582.533, -1172.063, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Acherus: The Ebon Hold)
(@CGUID+2879, 32520, 0, 1, 1, -6148.39, 5539.97, -1207.787, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Acherus: The Ebon Hold)
(@CGUID+2880, 32520, 0, 1, 1, -5691.65, 5556.92, -1154.687, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Acherus: The Ebon Hold)
(@CGUID+2881, 32520, 0, 1, 1, -6014.71, 5479.63, -1208.007, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Acherus: The Ebon Hold)
(@CGUID+2882, 2110, 0, 1, 1, 2346.068, -5770.615, 153.9676, 2.02252, 120, 0, 0), -- Black Rat (Area: Death's Breach)
(@CGUID+2883, 2110, 0, 1, 1, 2200.646, -5800.669, 101.4265, 1.260502, 120, 0, 0), -- Black Rat (Area: Ruins of the Scarlet Enclave)
(@CGUID+2884, 2110, 0, 1, 1, 2200.321, -5797.374, 101.4138, 0.7879004, 120, 0, 0), -- Black Rat (Area: Ruins of the Scarlet Enclave)
(@CGUID+2885, 2110, 0, 1, 1, 1959.23, -5809.299, 101.2323, 2.945085, 120, 0, 0), -- Black Rat (Area: Ruins of the Scarlet Enclave)
(@CGUID+2886, 2110, 0, 1, 1, 2010.604, -5822.156, 100.8722, 5.300428, 120, 0, 0), -- Black Rat (Area: Ruins of the Scarlet Enclave)
(@CGUID+2887, 2110, 0, 1, 1, 2007.521, -5802.403, 100.8134, 6.239795, 120, 0, 0), -- Black Rat (Area: Ruins of the Scarlet Enclave)
(@CGUID+2888, 2110, 0, 1, 1, 1451.348, -5791.023, 131.335, 6.271594, 120, 0, 0), -- Black Rat (Area: Ruins of the Scarlet Enclave)
(@CGUID+2889, 2110, 0, 1, 1, 1449.456, -5784.882, 131.335, 1.487467, 120, 0, 0), -- Black Rat (Area: Ruins of the Scarlet Enclave)
(@CGUID+2890, 2110, 0, 1, 1, 1438.959, -5786.563, 131.335, 5.300536, 120, 0, 0), -- Black Rat (Area: Ruins of the Scarlet Enclave)
(@CGUID+2891, 2110, 0, 1, 1, 1340.772, -5736.459, 136.5338, 0, 120, 0, 0), -- Black Rat (Area: Ruins of the Scarlet Enclave)
(@CGUID+2892, 2110, 0, 1, 1, 1358.081, -5725.417, 136.5011, 3.293232, 120, 0, 0), -- Black Rat (Area: Ruins of the Scarlet Enclave)
(@CGUID+2893, 41178, 0, 1, 1, 3175.531, -4373.844, 189.6369, 0.08726646, 120, 0, 0), -- Northwatch Tower Stalker (Area: Ruins of the Scarlet Enclave)
(@CGUID+2894, 32520, 0, 1, 1, -6014.71, 5479.63, -1208.007, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Ruins of the Scarlet Enclave)
(@CGUID+2895, 32520, 0, 1, 1, -6148.39, 5539.97, -1207.787, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Ruins of the Scarlet Enclave)
(@CGUID+2896, 32520, 0, 1, 1, -5691.65, 5556.92, -1154.687, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Ruins of the Scarlet Enclave)
(@CGUID+2897, 32520, 0, 1, 1, -6305.162, 5582.533, -1172.063, 0, 120, 0, 0); -- Totally Generic Bunny (All Phase) (Area: Ruins of the Scarlet Enclave)

DELETE FROM `npc_vendor` WHERE `entry` IN (47104, 47104, 47104, 47104, 47104, 47104, 47104, 47104, 47104, 47104, 47104, 47104, 47104, 47104, 47104, 47104, 47104, 47104, 45451, 45451, 45451, 45451, 45451, 45451, 45500, 45500, 45500, 45500, 45500, 45500, 45500, 45500, 45500, 45500, 45500, 45500, 45500, 45500, 45500, 45500, 47165, 47165, 47165, 47165, 47165, 47165, 47165, 47165, 47165, 47165, 47165, 47165, 47165, 47165, 47165, 47165, 47165, 47165, 47166, 47166, 47166, 47166, 47166, 47166, 47166, 47166, 47166, 47166, 47164, 47164, 47164, 47164, 47164, 47164, 47164, 47164, 47164, 47164, 47164, 47164, 47164, 47164, 47164, 47164, 47164, 47164, 47164, 47164, 47164, 47164, 47164, 47164, 47164, 47164, 47153, 47153, 47153, 47153, 47153, 47153, 47153, 47153, 47153, 47153, 47153, 47153, 47153, 47153, 47153, 47153, 47153, 47153, 47153, 47153, 47153, 47153, 47153, 47153, 47153, 47153, 47144, 47144, 47144, 47144, 47144, 47144, 47144, 47144, 47144, 47144, 47144, 47144, 47144, 47144, 47142, 47142, 47142, 47142, 47142, 47142, 47142, 47142, 47142, 47142, 47142, 47142, 47142, 47142, 47142, 47142, 47142, 47142, 12941, 12941, 12941, 12941, 12941, 12941, 12941, 12941, 12941, 12941, 12941, 12941, 12941, 12941, 12941, 12941, 12941, 12941, 12941, 12941, 12941, 12941, 12941, 12941, 12941, 12941, 47286, 47286, 47286, 47286, 47286, 47286, 11536, 11536, 11536, 11536, 11536, 11536, 11536, 11536, 11536, 11536, 11536, 11536, 11536, 11536, 16256, 16256, 16256, 16256, 16256, 16256, 16256, 16256, 16256, 16256, 16256, 16256, 29587, 28512, 28512, 28512, 28512, 28512, 28512, 28512, 28512, 28512, 28512, 28512, 28512, 28512, 28512, 28512, 28512, 28512, 28512, 28512, 28512, 28512, 28512, 28512, 28512, 28512, 28512, 28512, 28512, 28512, 28512, 28512, 28512, 28512, 29203, 29203, 29203, 29203, 29203, 29207, 29207, 29207, 29207, 29207, 29207, 29208, 29208, 29208, 29208, 29205, 29205, 29205, 29205, 29205, 29205, 29205, 29205, 29205, 29205, 29205, 29205, 29205, 29205, 29205, 29205, 28500, 28500, 28500, 28500, 28500, 28500, 28500);
INSERT INTO `npc_vendor` (`entry`, `item`, `slot`, `maxcount`, `ExtendedCost`, `Type`) VALUES
-- 47104 (Anthony Waler)
(47104, 2901, 1, 0, 0, 1), -- Mining Pick
(47104, 5956, 2, 0, 0, 1), -- Blacksmith Hammer
(47104, 6217, 3, 0, 0, 1), -- Copper Rod
(47104, 2320, 4, 0, 0, 1), -- Coarse Thread
(47104, 2321, 5, 0, 0, 1), -- Fine Thread
(47104, 4291, 6, 0, 0, 1), -- Silken Thread
(47104, 2678, 7, 0, 0, 1), -- Mild Spices
(47104, 2880, 8, 0, 0, 1), -- Weak Flux
(47104, 3466, 9, 0, 0, 1), -- Strong Flux
(47104, 3857, 10, 0, 0, 1), -- Coal
(47104, 2324, 11, 0, 0, 1), -- Bleach
(47104, 3371, 12, 0, 0, 1), -- Crystal Vial
(47104, 4289, 13, 0, 0, 1), -- Salt
(47104, 4399, 14, 0, 0, 1), -- Wooden Stock
(47104, 4400, 15, 0, 0, 1), -- Heavy Stock
(47104, 6530, 16, 0, 0, 1), -- Nightcrawlers
(47104, 6532, 17, 0, 0, 1), -- Bright Baubles
(47104, 39354, 18, 0, 0, 1), -- Light Parchment
-- 45451 (Argus Highbeacon)
(45451, 2901, 1, 0, 0, 1), -- Mining Pick
(45451, 5956, 2, 0, 0, 1), -- Blacksmith Hammer
(45451, 2880, 3, 0, 0, 1), -- Weak Flux
(45451, 3466, 4, 0, 0, 1), -- Strong Flux
(45451, 18567, 5, 0, 0, 1), -- Elemental Flux
(45451, 3857, 6, 0, 0, 1), -- Coal
-- 45500 (Urk Gagbaz)
(45500, 2423, 1, 0, 0, 1), -- Brigandine Vest
(45500, 2424, 2, 0, 0, 1), -- Brigandine Belt
(45500, 2425, 3, 0, 0, 1), -- Brigandine Leggings
(45500, 2426, 4, 0, 0, 1), -- Brigandine Boots
(45500, 2427, 5, 0, 0, 1), -- Brigandine Bracers
(45500, 2428, 6, 0, 0, 1), -- Brigandine Gloves
(45500, 3894, 7, 0, 0, 1), -- Brigandine Helm
(45500, 8094, 8, 0, 0, 1), -- Platemail Armor
(45500, 8088, 9, 0, 0, 1), -- Platemail Belt
(45500, 8093, 10, 0, 0, 1), -- Platemail Leggings
(45500, 8089, 11, 0, 0, 1), -- Platemail Boots
(45500, 8090, 12, 0, 0, 1), -- Platemail Bracers
(45500, 8091, 13, 0, 0, 1), -- Platemail Gloves
(45500, 8092, 14, 0, 0, 1), -- Platemail Helm
(45500, 17190, 15, 0, 0, 1), -- Ornate Buckler
(45500, 2451, 16, 0, 0, 1), -- Crested Heater Shield
-- 47165 (Casey Tipple)
(47165, 117, 1, 0, 0, 1), -- Tough Jerky
(47165, 2287, 2, 0, 0, 1), -- Haunch of Meat
(47165, 3770, 3, 0, 0, 1), -- Mutton Chop
(47165, 3771, 4, 0, 0, 1), -- Wild Hog Shank
(47165, 4599, 5, 0, 0, 1), -- Cured Ham Steak
(47165, 8952, 6, 0, 0, 1), -- Roasted Quail
(47165, 4536, 7, 0, 0, 1), -- Shiny Red Apple
(47165, 4537, 8, 0, 0, 1), -- Tel'Abim Banana
(47165, 4538, 9, 0, 0, 1), -- Snapvine Watermelon
(47165, 4539, 10, 0, 0, 1), -- Goldenbark Apple
(47165, 4602, 11, 0, 0, 1), -- Moon Harvest Pumpkin
(47165, 8953, 12, 0, 0, 1), -- Deep Fried Plantains
(47165, 159, 13, 0, 0, 1), -- Refreshing Spring Water
(47165, 1179, 14, 0, 0, 1), -- Ice Cold Milk
(47165, 1205, 15, 0, 0, 1), -- Melon Juice
(47165, 1708, 16, 0, 0, 1), -- Sweet Nectar
(47165, 1645, 17, 0, 0, 1), -- Moonberry Juice
(47165, 8766, 18, 0, 0, 1), -- Morning Glory Dew
-- 47166 (Dorris Manchester)
(47166, 3023, 1, 0, 0, 1), -- Large Bore Blunderbuss
(47166, 3024, 2, 0, 0, 1), -- BKP 2700 "Enforcer"
(47166, 3025, 3, 0, 0, 1), -- BKP 42 "Ultra"
(47166, 853, 4, 0, 0, 1), -- Hatchet
(47166, 2029, 5, 0, 0, 1), -- Cleaver
(47166, 927, 6, 0, 0, 1), -- Double Axe
(47166, 1196, 7, 0, 0, 1), -- Tabar
(47166, 2025, 8, 0, 0, 1), -- Bearded Axe
(47166, 926, 9, 0, 0, 1), -- Battle Axe
(47166, 5740, 10, 0, 0, 1), -- Red Fireworks Rocket
-- 47164 (James Litman)
(47164, 7005, 1, 0, 0, 1), -- Skinning Knife
(47164, 6256, 2, 0, 0, 1), -- Fishing Pole
(47164, 2901, 3, 0, 0, 1), -- Mining Pick
(47164, 5956, 4, 0, 0, 1), -- Blacksmith Hammer
(47164, 6217, 5, 0, 0, 1), -- Copper Rod
(47164, 2320, 6, 0, 0, 1), -- Coarse Thread
(47164, 2321, 7, 0, 0, 1), -- Fine Thread
(47164, 4291, 8, 0, 0, 1), -- Silken Thread
(47164, 8343, 9, 0, 0, 1), -- Heavy Silken Thread
(47164, 14341, 10, 0, 0, 1), -- Rune Thread
(47164, 2678, 11, 0, 0, 1), -- Mild Spices
(47164, 2880, 12, 0, 0, 1), -- Weak Flux
(47164, 3466, 13, 0, 0, 1), -- Strong Flux
(47164, 3857, 14, 0, 0, 1), -- Coal
(47164, 2324, 15, 0, 0, 1), -- Bleach
(47164, 2604, 16, 0, 0, 1), -- Red Dye
(47164, 2325, 17, 0, 0, 1), -- Black Dye
(47164, 4341, 18, 0, 0, 1), -- Yellow Dye
(47164, 4342, 19, 0, 0, 1), -- Purple Dye
(47164, 4340, 20, 0, 0, 1), -- Gray Dye
(47164, 3371, 21, 0, 0, 1), -- Crystal Vial
(47164, 4289, 22, 0, 0, 1), -- Salt
(47164, 4399, 23, 0, 0, 1), -- Wooden Stock
(47164, 4400, 24, 0, 0, 1), -- Heavy Stock
(47164, 6530, 25, 0, 0, 1), -- Nightcrawlers
(47164, 6532, 26, 0, 0, 1), -- Bright Baubles
-- 47153 (Cabe Minewell)
(47153, 7005, 1, 0, 0, 1), -- Skinning Knife
(47153, 6256, 2, 0, 0, 1), -- Fishing Pole
(47153, 2901, 3, 0, 0, 1), -- Mining Pick
(47153, 5956, 4, 0, 0, 1), -- Blacksmith Hammer
(47153, 6217, 5, 0, 0, 1), -- Copper Rod
(47153, 2320, 6, 0, 0, 1), -- Coarse Thread
(47153, 2321, 7, 0, 0, 1), -- Fine Thread
(47153, 4291, 8, 0, 0, 1), -- Silken Thread
(47153, 8343, 9, 0, 0, 1), -- Heavy Silken Thread
(47153, 14341, 10, 0, 0, 1), -- Rune Thread
(47153, 2678, 11, 0, 0, 1), -- Mild Spices
(47153, 2880, 12, 0, 0, 1), -- Weak Flux
(47153, 3466, 13, 0, 0, 1), -- Strong Flux
(47153, 3857, 14, 0, 0, 1), -- Coal
(47153, 2324, 15, 0, 0, 1), -- Bleach
(47153, 2604, 16, 0, 0, 1), -- Red Dye
(47153, 2325, 17, 0, 0, 1), -- Black Dye
(47153, 4341, 18, 0, 0, 1), -- Yellow Dye
(47153, 4342, 19, 0, 0, 1), -- Purple Dye
(47153, 4340, 20, 0, 0, 1), -- Gray Dye
(47153, 3371, 21, 0, 0, 1), -- Crystal Vial
(47153, 4289, 22, 0, 0, 1), -- Salt
(47153, 4399, 23, 0, 0, 1), -- Wooden Stock
(47153, 4400, 24, 0, 0, 1), -- Heavy Stock
(47153, 6530, 25, 0, 0, 1), -- Nightcrawlers
(47153, 6532, 26, 0, 0, 1), -- Bright Baubles
-- 47144 (Patricia Marshall)
(47144, 2520, 1, 0, 0, 1), -- Broadsword
(47144, 2528, 2, 0, 0, 1), -- Falchion
(47144, 2526, 3, 0, 0, 1), -- Main Gauche
(47144, 2534, 4, 0, 0, 1), -- Rondel
(47144, 15810, 5, 0, 0, 1), -- Short Spear
(47144, 15811, 6, 0, 0, 1), -- Heavy Spear
(47144, 17188, 7, 0, 0, 1), -- Ringed Buckler
(47144, 17192, 8, 0, 0, 1), -- Reinforced Targe
(47144, 17189, 9, 0, 0, 1), -- Metal Buckler
(47144, 17190, 10, 0, 0, 1), -- Ornate Buckler
(47144, 2445, 11, 0, 0, 1), -- Large Metal Shield
(47144, 2446, 12, 0, 0, 1), -- Kite Shield
(47144, 2448, 13, 0, 0, 1), -- Heavy Pavise
(47144, 2451, 14, 0, 0, 1), -- Crested Heater Shield
-- 47142 (Rahmalaha)
(47142, 4540, 1, 0, 0, 1), -- Tough Hunk of Bread
(47142, 4541, 2, 0, 0, 1), -- Freshly Baked Bread
(47142, 4542, 3, 0, 0, 1), -- Moist Cornbread
(47142, 4544, 4, 0, 0, 1), -- Mulgore Spice Bread
(47142, 4601, 5, 0, 0, 1), -- Soft Banana Bread
(47142, 8950, 6, 0, 0, 1), -- Homemade Cherry Pie
(47142, 4604, 7, 0, 0, 1), -- Forest Mushroom Cap
(47142, 4605, 8, 0, 0, 1), -- Red-Speckled Mushroom
(47142, 4606, 9, 0, 0, 1), -- Spongy Morel
(47142, 4607, 10, 0, 0, 1), -- Delicious Cave Mold
(47142, 4608, 11, 0, 0, 1), -- Raw Black Truffle
(47142, 8948, 12, 0, 0, 1), -- Dried King Bolete
(47142, 159, 13, 0, 0, 1), -- Refreshing Spring Water
(47142, 1179, 14, 0, 0, 1), -- Ice Cold Milk
(47142, 1205, 15, 0, 0, 1), -- Melon Juice
(47142, 1708, 16, 0, 0, 1), -- Sweet Nectar
(47142, 1645, 17, 0, 0, 1), -- Moonberry Juice
(47142, 8766, 18, 0, 0, 1), -- Morning Glory Dew
-- 12941 (Jase Farlane)
(12941, 21954, 314, 1, 0, 1), -- Design: Ring of Bitter Shadows
(12941, 7005, 2, 0, 0, 1), -- Skinning Knife
(12941, 6256, 3, 0, 0, 1), -- Fishing Pole
(12941, 6217, 4, 0, 0, 1), -- Copper Rod
(12941, 5956, 5, 0, 0, 1), -- Blacksmith Hammer
(12941, 2901, 6, 0, 0, 1), -- Mining Pick
(12941, 2320, 7, 0, 0, 1), -- Coarse Thread
(12941, 2321, 8, 0, 0, 1), -- Fine Thread
(12941, 4291, 9, 0, 0, 1), -- Silken Thread
(12941, 8343, 10, 0, 0, 1), -- Heavy Silken Thread
(12941, 14341, 11, 0, 0, 1), -- Rune Thread
(12941, 2678, 12, 0, 0, 1), -- Mild Spices
(12941, 2880, 13, 0, 0, 1), -- Weak Flux
(12941, 3466, 14, 0, 0, 1), -- Strong Flux
(12941, 3857, 15, 0, 0, 1), -- Coal
(12941, 2604, 16, 0, 0, 1), -- Red Dye
(12941, 2325, 17, 0, 0, 1), -- Black Dye
(12941, 4341, 18, 0, 0, 1), -- Yellow Dye
(12941, 4342, 19, 0, 0, 1), -- Purple Dye
(12941, 4340, 20, 0, 0, 1), -- Gray Dye
(12941, 3371, 21, 0, 0, 1), -- Crystal Vial
(12941, 4289, 22, 0, 0, 1), -- Salt
(12941, 4399, 23, 0, 0, 1), -- Wooden Stock
(12941, 4400, 24, 0, 0, 1), -- Heavy Stock
(12941, 6530, 25, 0, 0, 1), -- Nightcrawlers
(12941, 6532, 26, 0, 0, 1), -- Bright Baubles
-- 47286 (Vincent Randolph)
(47286, 2901, 1, 0, 0, 1), -- Mining Pick
(47286, 5956, 2, 0, 0, 1), -- Blacksmith Hammer
(47286, 2880, 3, 0, 0, 1), -- Weak Flux
(47286, 3466, 4, 0, 0, 1), -- Strong Flux
(47286, 18567, 5, 0, 0, 1), -- Elemental Flux
(47286, 3857, 6, 0, 0, 1), -- Coal
-- 11536 (Quartermaster Miranda Breechlock)
(11536, 13724, 1, 0, 0, 1), -- Enriched Manna Biscuit
(11536, 13482, 2, 0, 0, 1), -- Recipe: Transmute Air to Fire
(11536, 19203, 3, 0, 0, 1), -- Plans: Girdle of the Dawn
(11536, 19328, 4, 0, 0, 1), -- Pattern: Dawn Treaders
(11536, 19216, 5, 0, 0, 1), -- Pattern: Argent Boots
(11536, 19442, 6, 0, 0, 1), -- Formula: Powerful Anti-Venom
(11536, 19446, 7, 0, 0, 1), -- Formula: Enchant Bracer - Mana Regeneration
(11536, 22014, 8, 0, 0, 1), -- Hallowed Brazier
(11536, 19205, 123, 0, 0, 1), -- Plans: Gloves of the Dawn
(11536, 19329, 124, 0, 0, 1), -- Pattern: Golden Mantle of the Dawn
(11536, 19217, 125, 0, 0, 1), -- Pattern: Argent Shoulders
(11536, 13810, 126, 0, 0, 1), -- Blessed Sunfruit
(11536, 13813, 127, 0, 0, 1), -- Blessed Sunfruit Juice
(11536, 19447, 128, 0, 0, 1), -- Formula: Enchant Bracer - Healing Power
-- 16256 (Jessica Chambers)
(16256, 4540, 1, 0, 0, 1), -- Tough Hunk of Bread
(16256, 4541, 2, 0, 0, 1), -- Freshly Baked Bread
(16256, 4542, 3, 0, 0, 1), -- Moist Cornbread
(16256, 4544, 4, 0, 0, 1), -- Mulgore Spice Bread
(16256, 4601, 5, 0, 0, 1), -- Soft Banana Bread
(16256, 8950, 6, 0, 0, 1), -- Homemade Cherry Pie
(16256, 159, 7, 0, 0, 1), -- Refreshing Spring Water
(16256, 1179, 8, 0, 0, 1), -- Ice Cold Milk
(16256, 1205, 9, 0, 0, 1), -- Melon Juice
(16256, 1708, 10, 0, 0, 1), -- Sweet Nectar
(16256, 1645, 11, 0, 0, 1), -- Moonberry Juice
(16256, 8766, 12, 0, 0, 1), -- Morning Glory Dew
-- 29587 (Dread Commander Thalanor)
(29587, 40775, 1, 0, 0, 1), -- Winged Steed of the Ebon Blade
-- 28512 (Quartermaster Ozorg)
(28512, 34648, 1, 0, 0, 1), -- Acherus Knight's Greaves
(28512, 34649, 2, 0, 0, 1), -- Acherus Knight's Gauntlets
(28512, 34650, 3, 0, 0, 1), -- Acherus Knight's Tunic
(28512, 34651, 4, 0, 0, 1), -- Acherus Knight's Girdle
(28512, 34652, 5, 0, 0, 1), -- Acherus Knight's Hood
(28512, 34653, 6, 0, 0, 1), -- Acherus Knight's Wristguard
(28512, 34655, 7, 0, 0, 1), -- Acherus Knight's Pauldrons
(28512, 34656, 8, 0, 0, 1), -- Acherus Knight's Legplates
(28512, 34657, 9, 0, 0, 1), -- Choker of Damnation
(28512, 34658, 10, 0, 0, 1), -- Plague Band
(28512, 34659, 11, 0, 0, 1), -- Acherus Knight's Shroud
(28512, 34661, 12, 0, 0, 1), -- Massacre Sword
(28512, 38147, 13, 0, 0, 1), -- Corrupted Band
(28512, 38632, 14, 0, 0, 1), -- Greatsword of the Ebon Blade
(28512, 38633, 15, 0, 0, 1), -- Greataxe of the Ebon Blade
(28512, 38661, 16, 0, 0, 1), -- Greathelm of the Scourge Champion
(28512, 38662, 17, 0, 0, 1), -- Bladed Ebon Amulet
(28512, 38663, 18, 0, 0, 1), -- Blood-Soaked Saronite Plated Spaulders
(28512, 38664, 19, 0, 0, 1), -- Sky Darkener's Shroud of the Unholy
(28512, 39320, 20, 0, 0, 1), -- Sky Darkener's Shroud of Blood
(28512, 39322, 21, 0, 0, 1), -- Shroud of the North Wind
(28512, 38665, 22, 0, 0, 1), -- Saronite War Plate
(28512, 38666, 23, 0, 0, 1), -- Plated Saronite Bracers
(28512, 38667, 24, 0, 0, 1), -- Bloodbane's Gauntlets of Command
(28512, 38668, 25, 0, 0, 1), -- The Plaguebringer's Girdle
(28512, 38669, 26, 0, 0, 1), -- Engraved Saronite Legplates
(28512, 38670, 27, 0, 0, 1), -- Greaves of the Slaughter
(28512, 38671, 28, 0, 0, 1), -- Valanar's Signet Ring
(28512, 38672, 29, 0, 0, 1), -- Keleseth's Signet Ring
(28512, 38674, 30, 0, 0, 1), -- Soul Harvester's Charm
(28512, 38675, 31, 0, 0, 1), -- Signet of the Dark Brotherhood
(28512, 38707, 32, 0, 0, 1), -- Runed Soulblade
(28512, 39208, 33, 0, 0, 1), -- Sigil of the Dark Rider
-- 29203 (Alchemist Karloff)
(29203, 17034, 1, 0, 0, 1), -- Maple Seed
(29203, 17031, 2, 0, 0, 1), -- Rune of Teleportation
(29203, 17032, 3, 0, 0, 1), -- Rune of Portals
(29203, 17020, 4, 0, 0, 1), -- Arcane Powder
(29203, 17030, 5, 0, 0, 1), -- Ankh
-- 29207 (Gangrenus)
(29207, 159, 1, 0, 0, 1), -- Refreshing Spring Water
(29207, 28399, 2, 0, 0, 1), -- Filtered Draenic Water
(29207, 27855, 3, 0, 0, 1), -- Mag'har Grainbread
(29207, 4499, 4, 0, 0, 1), -- Huge Brown Sack
(29207, 30744, 5, 0, 0, 1), -- Draenic Leather Pack
(29207, 4470, 6, 0, 0, 1), -- Simple Wood
-- 29208 (Fester)
(29208, 14341, 1, 0, 0, 1), -- Rune Thread
(29208, 3371, 2, 0, 0, 1), -- Crystal Vial
(29208, 6532, 3, 0, 0, 1), -- Bright Baubles
(29208, 10648, 4, 0, 0, 1), -- Common Parchment
-- 29205 (Corpulous)
(29205, 8952, 1, 0, 0, 1), -- Roasted Quail
(29205, 27854, 2, 0, 0, 1), -- Smoked Talbuk Venison
(29205, 29451, 3, 0, 0, 1), -- Clefthoof Ribs
(29205, 33454, 4, 0, 0, 1), -- Salted Venison
(29205, 35953, 5, 0, 0, 1), -- Mead Basted Caribou
(29205, 8948, 6, 0, 0, 1), -- Dried King Bolete
(29205, 27859, 7, 0, 0, 1), -- Zangar Caps
(29205, 29453, 8, 0, 0, 1), -- Sporeggar Mushroom
(29205, 33452, 9, 0, 0, 1), -- Honey-Spiced Lichen
(29205, 35947, 10, 0, 0, 1), -- Sparkling Frostcap
(29205, 8766, 11, 0, 0, 1), -- Morning Glory Dew
(29205, 28399, 12, 0, 0, 1), -- Filtered Draenic Water
(29205, 27860, 13, 0, 0, 1), -- Purified Draenic Water
(29205, 35954, 14, 0, 0, 1), -- Sweetened Goat's Milk
(29205, 33444, 15, 0, 0, 1), -- Pungent Seal Whey
(29205, 33445, 16, 0, 0, 1), -- Honeymint Tea
-- 28500 (Master Siegesmith Corvus)
(28500, 38645, 1, 0, 0, 1), -- Bone-Plated Armor
(28500, 38646, 2, 0, 0, 1), -- Bone-Plated Belt
(28500, 38647, 3, 0, 0, 1), -- Bone-Plated Boots
(28500, 38648, 4, 0, 0, 1), -- Bone-Plated Bracers
(28500, 38649, 5, 0, 0, 1), -- Bone-Plated Gloves
(28500, 38650, 6, 0, 0, 1), -- Bone-Plated Helm
(28500, 38651, 7, 0, 0, 1); -- Bone-Plated Leggings

DELETE FROM `npc_text` WHERE `ID` IN (16909, 16864, 14125, 16956, 17187, 17611, 8506);
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `lang0`, `prob0`, `em0_0`, `em0_1`, `em0_2`, `em0_3`, `em0_4`, `em0_5`, `text1_0`, `text1_1`, `lang1`, `prob1`, `em1_0`, `em1_1`, `em1_2`, `em1_3`, `em1_4`, `em1_5`, `text2_0`, `text2_1`, `lang2`, `prob2`, `em2_0`, `em2_1`, `em2_2`, `em2_3`, `em2_4`, `em2_5`, `text3_0`, `text3_1`, `lang3`, `prob3`, `em3_0`, `em3_1`, `em3_2`, `em3_3`, `em3_4`, `em3_5`, `text4_0`, `text4_1`, `lang4`, `prob4`, `em4_0`, `em4_1`, `em4_2`, `em4_3`, `em4_4`, `em4_5`, `text5_0`, `text5_1`, `lang5`, `prob5`, `em5_0`, `em5_1`, `em5_2`, `em5_3`, `em5_4`, `em5_5`, `text6_0`, `text6_1`, `lang6`, `prob6`, `em6_0`, `em6_1`, `em6_2`, `em6_3`, `em6_4`, `em6_5`, `text7_0`, `text7_1`, `lang7`, `prob7`, `em7_0`, `em7_1`, `em7_2`, `em7_3`, `em7_4`, `em7_5`, `WDBVerified`) VALUES
(16909, 'Don''t let anybody tell you that the Scourge is defeated.  Look... do they not still roam the Plaguewood?  They cling to their corrupted land like a child''s blanket.$b$bI have no choice but to fight.  Until my last breath, I will fight them.', '', 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- 16909
(16864, 'Yes, traveler?', '', 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- 16864
(14125, 'How may I help you?', 'How may I help you?', 0, 1, 2, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- 14125
(16956, 'Oh, ahh... hello there, good traveler!  What can this fine goblin do for you today?$b$bI''ll assure you that I''m here in Light''s Hope Chapel solely due to my hatred of the Scourge which I share with these Argent Crusaders, and definitely not because I''m running away from any sort of embarassing zeppelin crash!$b$bI''ll stop talking now, before I implicate myself any further!', '', 0, 1, 1, 1, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- 16956
(17187, 'I''m afraid I cannot help you, $r, but I am sure Khaelyn Steelwing can.', 'I''m afraid I cannot help you, $r, but I am sure Khaelyn Steelwing can.', 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- 17187
(17611, 'The sacrifices of my Argent Dawn brothers must never be forgotten. They believed in the Dawn, though none lived to see the return of the Light to these lands.', '', 0, 1, 1, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- 17611
(8506, 'There are those who would say that the Argent Crusade is a thing of the past.  I am one of them, but not because the Scourge have fallen.$b$bNo... it is because of their stubborn ways.  They''ve become too much like the church that they seceded from: too rigid, too governed by honor and order.  This is what I''m trying to tell Barthalomew, anyhow.$b$bSure, it may sound a bit jingoistic, but it makes for a good debate.', '', 0, 1, 1, 1, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 15595); -- 8506

UPDATE `npc_text` SET `WDBVerified`=15595 WHERE `ID`=4979; -- 4979
UPDATE `npc_text` SET `WDBVerified`=15595 WHERE `ID`=4716; -- 4716
UPDATE `npc_text` SET `WDBVerified`=15595 WHERE `ID`=8454; -- 8454
UPDATE `npc_text` SET `text0_1`='The Plaguelands are an excellent place to strike against the Scourge!', `WDBVerified`=15595 WHERE `ID`=4450; -- 4450
UPDATE `npc_text` SET `text0_0`='What is the Brotherhood of the Light?  Well... We are all members of the Argent Crusade at the core - members of the Argent Crusade that aren''t held in check by morals, guilt and useless human emotion.', `em0_0`=1, `em0_2`=1, `em0_3`=0, `em0_5`=0, `WDBVerified`=15595 WHERE `ID`=8353; -- 8353
UPDATE `npc_text` SET `text0_0`='We of the Brotherhood of the Light are not as lenient as our brethren when it comes to meting justice to those that would do this world wrong.', `em0_0`=25, `em0_1`=1, `em0_3`=0, `WDBVerified`=15595 WHERE `ID`=8351; -- 8351
UPDATE `npc_text` SET `em0_0`=1, `em0_3`=0, `WDBVerified`=15595 WHERE `ID`=8357; -- 8357
UPDATE `npc_text` SET `em0_0`=1, `em0_2`=1, `em0_3`=0, `em0_5`=0, `WDBVerified`=15595 WHERE `ID`=8452; -- 8452
UPDATE `npc_text` SET `em0_0`=25, `em0_1`=1, `em0_2`=1, `em0_3`=0, `em0_5`=0, `WDBVerified`=15595 WHERE `ID`=8422; -- 8422
UPDATE `npc_text` SET `em0_0`=1, `em0_1`=0, `WDBVerified`=15595 WHERE `ID`=8366; -- 8366
UPDATE `npc_text` SET `em0_0`=1, `em0_1`=14, `em0_2`=1, `em0_3`=0, `em0_5`=0, `WDBVerified`=15595 WHERE `ID`=8513; -- 8513
UPDATE `npc_text` SET `em0_0`=1, `em0_1`=0, `WDBVerified`=15595 WHERE `ID`=8448; -- 8448
UPDATE `npc_text` SET `em0_0`=1, `em0_1`=0, `WDBVerified`=15595 WHERE `ID`=13173; -- 13173
UPDATE `npc_text` SET `WDBVerified`=15595 WHERE `ID`=14391; -- 14391
UPDATE `npc_text` SET `em0_0`=5, `em0_1`=0, `WDBVerified`=15595 WHERE `ID`=13172; -- 13172
UPDATE `npc_text` SET `em0_0`=396, `em0_1`=0, `WDBVerified`=15595 WHERE `ID`=13174; -- 13174
UPDATE `npc_text` SET `em0_0`=6, `em0_1`=0, `WDBVerified`=15595 WHERE `ID`=13262; -- 13262

DELETE FROM `gossip_menu_option` WHERE (`menu_id`=12034 AND `id`=2) OR (`menu_id`=12033 AND `id`=1) OR (`menu_id`=12236 AND `id`=0) OR (`menu_id`=9794 AND `id`=0) OR (`menu_id`=9794 AND `id`=1) OR (`menu_id`=9794 AND `id`=2) OR (`menu_id`=9793 AND `id`=0) OR (`menu_id`=9793 AND `id`=1) OR (`menu_id`=9793 AND `id`=2) OR (`menu_id`=9792 AND `id`=0) OR (`menu_id`=9792 AND `id`=1) OR (`menu_id`=9792 AND `id`=2) OR (`menu_id`=9706 AND `id`=0);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `box_coded`, `box_money`, `box_text`) VALUES
(12034, 2, 1, 'Could you repair my gear, Argus?', 0, 0, ''), -- Argus Highbeacon
(12033, 1, 1, 'I want to browse your goods.', 0, 0, ''), -- Urk Gagbaz
(12236, 0, 2, 'Show me where I can fly.', 0, 0, ''), -- Khaelyn Steelwing
(9794, 0, 3, 'I seek training, Lord Thorval.', 0, 0, ''), -- Lord Thorval
(9794, 1, 0, 'I wish to unlearn my talents.', 0, 0, ''), -- Lord Thorval
(9794, 2, 0, 'I wish to know about Dual Talent Specialization.', 0, 0, ''), -- Lord Thorval
(9793, 0, 3, 'I seek training, Lady Alistra.', 0, 0, ''), -- Lady Alistra
(9793, 1, 0, 'I wish to unlearn my talents.', 0, 0, ''), -- Lady Alistra
(9793, 2, 0, 'I wish to know about Dual Talent Specialization.', 0, 0, ''), -- Lady Alistra
(9792, 0, 3, 'I seek training, Amal''thazad.', 0, 0, ''), -- Amal'thazad
(9792, 1, 0, 'I wish to unlearn my talents.', 0, 0, ''), -- Amal'thazad
(9792, 2, 0, 'I wish to know about Dual Talent Specialization.', 0, 0, ''), -- Amal'thazad
(9706, 0, 1, 'I require repairs and supplies, Corvus.', 0, 0, ''); -- Master Siegesmith Corvus

UPDATE `gossip_menu_option` SET `box_money`=100000, `box_text`='Are you sure you would like to purchase your second talent specialization?' WHERE `menu_id`=10371 AND `id`=0; -- Lord Thorval

DELETE FROM `creature_equip_template` WHERE `entry` IN (11140, 12384, 8523, 8523, 45828, 47106, 47060, 47060, 47060, 47060, 47105, 47060, 47060, 45443, 45443, 45443, 45443, 45443, 45443, 45443, 45443, 45443, 45443, 45443, 45443, 45443, 45443, 45443, 45443, 45443, 45443, 45443, 45443, 45443, 45443, 45443, 45443, 45443, 45443, 45429, 47060, 47104, 47060, 47060, 47060, 47060, 47060, 8523, 8553, 8523, 8523, 8523, 8523, 8523, 8547, 8523, 8547, 8523, 8523, 45897, 45897, 45897, 45897, 45897, 45897, 45897, 45897, 45897, 45897, 45897, 8523, 8553, 8553, 45867, 8553, 8547, 8553, 8553, 45831, 45868, 8523, 8523, 45897, 45897, 45897, 45897, 45897, 45897, 45897, 8529, 45897, 45897, 45897, 45897, 45897, 8523, 8523, 45897, 45897, 45897, 51986, 51986, 51986, 51986, 8529, 45897, 45897, 45897, 45897, 8523, 8523, 8523, 8523, 8523, 8523, 45897, 45897, 45897, 45897, 8550, 8529, 8529, 8529, 8529, 51986, 51986, 47060, 47060, 47060, 47060, 47060, 47060, 10667, 47060, 8529, 8546, 8546, 8529, 8529, 8550, 8546, 8529, 8550, 8550, 45897, 45897, 45897, 45897, 8547, 10819, 8523, 8550, 8529, 47060, 47060, 11063, 47139, 45451, 10817, 11288, 11288, 11289, 11288, 11289, 11288, 11288, 11288, 11289, 11288, 8546, 8550, 8529, 8529, 8546, 8550, 8546, 8529, 8529, 8553, 8523, 8523, 10826, 8550, 8546, 8546, 8529, 11288, 11621, 11621, 11621, 11621, 11621, 11620, 11620, 11621, 11620, 11620, 8523, 8523, 8553, 16228, 16228, 16228, 16228, 16228, 16228, 47060, 47060, 8564, 8563, 8563, 8564, 8563, 8565, 8565, 8565, 8563, 8565, 8565, 8565, 8565, 8565, 8565, 8565, 8563, 8565, 8565, 8563, 8565, 8564, 8565, 8565, 8564, 8563, 8563, 8565, 8564, 8565, 47060, 47060, 47060, 47060, 47060, 47060, 47060, 47060, 47060, 47060, 47060, 47060, 47060, 47060, 47164, 47166, 47060, 47165, 47167, 47060, 47060, 47060, 47060, 45482, 47060, 47060, 47060, 47060, 8525, 8525, 8548, 8551, 8548, 11035, 47153, 47060, 47149, 47060, 47060, 47060, 47148, 11706, 47060, 47060, 47060, 47060, 8551, 8525, 8548, 8548, 8525, 8551, 8551, 8551, 8551, 8548, 8551, 8548, 8548, 8525, 8525, 8525, 8525, 8548, 8548, 8551, 8525, 8525, 8560, 8561, 47060, 47060, 47060, 47060, 47060, 47060, 8527, 8527, 8527, 8561, 8561, 8560, 8560, 8561, 8561, 8562, 8560, 8562, 10823, 8561, 8562, 8562, 8527, 8527, 8527, 8527, 8527, 47142, 47144, 45735, 47060, 47060, 47060, 8548, 8548, 8548, 8551, 8551, 8551, 8548, 8551, 8551, 8548, 8551, 8560, 8560, 8562, 8562, 8562, 8560, 8561, 8562, 8561, 8561, 8560, 8561, 8562, 8562, 8561, 10822, 8560, 8561, 8560, 8562, 8562, 8561, 8561, 8562, 8562, 8562, 8561, 8561, 8561, 8561, 8561, 8561, 8561, 8562, 8561, 8561, 8560, 47060, 47060, 47060, 47060, 47060, 47060, 47060, 47060, 45681, 16378, 16378, 47288, 16378, 16378, 16378, 16378, 16378, 47289, 47289, 16378, 16378, 16378, 47286, 11102, 11102, 47289, 47289, 47289, 47289, 47289, 16378, 16378, 16378, 11038, 16378, 16378, 9447, 9447, 9447, 9449, 9449, 9447, 16112, 9447, 9452, 9449, 9447, 9447, 9452, 9447, 9450, 9447, 9451, 9447, 9447, 9447, 9452, 9447, 9447, 9450, 9452, 9447, 9447, 9447, 9449, 9447, 9447, 9447, 16378, 16378, 48705, 11033, 16378, 48704, 16378, 16376, 11536, 11039, 46022, 16378, 12617, 16378, 12636, 47289, 16378, 16283, 16378, 12941, 16378, 11036, 11034, 16378, 16378, 16378, 16378, 49856, 16378, 16378, 16378, 16378, 16378, 45692, 45692, 45692, 45692, 45692, 45692, 9447, 9447, 9449, 9452, 9449, 9447, 9452, 9447, 9452, 9447, 9447, 9447, 9448, 9448, 9450, 9448, 9448, 46138, 9448, 9452, 9449, 9447, 9448, 9448, 9452, 9449, 9448, 9449, 9449, 9449, 9449, 9449, 9449, 9447, 9447, 9452, 9452, 9449, 9449, 9447, 9452, 9452, 9452, 9449, 9452, 9449, 9452, 9452, 9452, 9452, 9449, 9452, 29202, 45692, 45692, 45692, 29202, 29202, 29202, 29202, 29202, 29202, 29202, 28490, 29246, 29202, 29202, 29202, 29202, 29202, 29202, 9447, 9447, 9452, 9448, 9448, 9450, 9448, 9450, 9451, 9448, 9448, 9448, 9448, 9450, 9451, 9448, 9448, 9451, 9450, 9450, 9451, 9450, 9450, 9450, 9448, 9448, 9448, 9451, 9448, 9448, 9448, 9448, 9450, 9451, 9450, 9450, 9450, 9451, 9448, 29202, 29202, 29202, 29202, 29203, 29202, 29202, 29202, 29202, 29202, 29202, 29202, 29202, 29202, 29202, 29202, 29202, 29202, 29202, 29202, 27928, 29202, 29202, 29202, 29202, 29202, 29202, 29202, 29202, 29202, 29202, 29202, 28500, 29202);
INSERT INTO `creature_equip_template` (`entry`, `itemEntry1`, `itemEntry2`, `itemEntry3`) VALUES
(11140, 1911, 0, 12523), -- Egan
(12384, 12854, 0, 0), -- Augustus the Touched
(8523, 1899, 0, 0), -- Scourge Soldier
(45828, 52358, 0, 0), -- Argent Apothecary Judkins
(47106, 45123, 42543, 0), -- Christine Gade
(47060, 42544, 42543, 2551), -- Argent Sentry
(47105, 1906, 0, 0), -- Marc Daiton
(45443, 2559, 0, 0), -- Death's Step Putrifier
(45429, 57038, 0, 0), -- Tarenar Sunstrike
(47104, 1910, 0, 0), -- Anthony Waler
(8553, 2559, 0, 0), -- Necromancer
(8547, 6224, 0, 0), -- Death Cultist
(45897, 49801, 0, 0), -- Plaguewood Reanimator
(45867, 41343, 0, 0), -- Omasum Blighthoof
(45831, 41177, 40596, 0), -- Crusader Kevin Frost
(45868, 43532, 0, 0), -- Karthis Darkrune
(8529, 12944, 2179, 0), -- Scourge Champion
(51986, 42544, 42543, 0), -- Argent Sentry
(8550, 2177, 0, 0), -- Shadowmage
(10667, 12591, 0, 0), -- Chromie
(8546, 13061, 0, 0), -- Dark Adept
(10819, 11019, 0, 0), -- Baron Bloodbane
(11063, 1899, 1985, 0), -- Carlin Redpath
(47139, 1906, 0, 0), -- Gerald Fairbanks
(45451, 6224, 0, 0), -- Argus Highbeacon
(10817, 4090, 0, 12523), -- Duggan Wildhammer
(11288, 1899, 1985, 0), -- Spectral Betrayer
(11289, 12890, 1984, 0), -- Spectral Defender
(10826, 12403, 0, 0), -- Lord Darkscythe
(11621, 12890, 1984, 0), -- Spectral Corpse
(11620, 1899, 1985, 0), -- Spectral Marauder
(16228, 22596, 0, 0), -- Argent Dawn Infantry
(8564, 11763, 0, 5259), -- Ranger
(8563, 5286, 0, 0), -- Woodsman
(8565, 12993, 12991, 0), -- Pathstrider
(47164, 1910, 0, 0), -- James Litman
(47166, 45123, 42543, 0), -- Dorris Manchester
(47165, 2197, 0, 0), -- Casey Tipple
(47167, 1906, 0, 0), -- Brett Nelson
(45482, 0, 0, 49761), -- Argent Officer Irizarry
(8525, 1905, 1984, 0), -- Scourge Warder
(8548, 2711, 12865, 0), -- Vile Tutor
(8551, 13078, 0, 0), -- Dark Summoner
(11035, 5287, 0, 0), -- Betina Bigglezink
(47153, 1910, 0, 0), -- Cabe Minewell
(47149, 45123, 42543, 0), -- Kathryn Humphries
(47148, 1906, 0, 0), -- Donovan Minewell
(11706, 3364, 0, 0), -- Adon
(8560, 6680, 0, 0), -- Mossflayer Scout
(8561, 12991, 0, 5261), -- Mossflayer Shadowhunter
(8527, 3361, 1985, 0), -- Scourge Guard
(8562, 10611, 0, 0), -- Mossflayer Cannibal
(10823, 12322, 0, 0), -- Zul'Brin Warpbranch
(47142, 1906, 0, 0), -- Rahmalaha
(47144, 45123, 42543, 0), -- Patricia Marshall
(45735, 49311, 0, 0), -- Gamella Cracklefizz
(10822, 12403, 0, 0), -- Warlord Thresh'jin
(45681, 61298, 0, 0), -- Garginox
(16378, 42544, 42543, 2551), -- Argent Sentry
(47288, 2202, 0, 0), -- Gutcheck
(47289, 1903, 0, 0), -- Argent Crusade Engineer
(47286, 1903, 0, 0), -- Vincent Randolph
(11102, 12403, 0, 62285), -- Argent Rider
-- (47289, 1911, 0, 0), -- Argent Crusade Engineer
(11038, 4993, 2081, 0), -- Caretaker Alen
(9447, 10825, 12995, 0), -- Scarlet Warder
(9449, 11365, 0, 0), -- Scarlet Cleric
(16112, 22199, 0, 0), -- Korfax, Champion of the Light
(9452, 13050, 0, 0), -- Scarlet Enchanter
(9450, 5291, 12863, 0), -- Scarlet Curate
(9451, 13069, 0, 0), -- Scarlet Archmage
(48705, 31824, 0, 0), -- Gertrude Nozzlerocket
(11033, 1906, 2081, 0), -- Smokey LaRue
(48704, 31824, 0, 0), -- Gek Nozzlerocket
(16376, 1903, 13611, 0), -- Craftsman Wilhelm
(11536, 2182, 0, 0), -- Quartermaster Miranda Breechlock
(11039, 2557, 0, 0), -- Duke Nicholas Zverenhoff
(46022, 31824, 0, 0), -- Beezil Linkspanner
(12617, 2182, 0, 0), -- Khaelyn Steelwing
(12636, 5303, 0, 0), -- Georgia
(16283, 1910, 0, 0), -- Packmaster Stonebruiser
(12941, 12850, 0, 0), -- Jase Farlane
(11036, 5289, 0, 0), -- Leonid Barthalomew the Revered
(11034, 13165, 0, 0), -- Lord Maxwell Tyrosus
(49856, 32272, 50216, 0), -- Lord Raymond George
(45692, 22215, 22215, 0), -- Noxious Assassin
(9448, 12944, 12932, 0), -- Scarlet Praetorian
(46138, 2178, 40596, 0), -- Argent Centurion
(29202, 38707, 0, 0), -- Knight of the Ebon Blade
(28490, 13505, 0, 0), -- Disciple of Frost
(29246, 40276, 40276, 0), -- Highlord Darion Mograine
(29203, 0, 12855, 0), -- Alchemist Karloff
(27928, 38099, 0, 0), -- Siouxsie the Banshee
(28500, 30078, 0, 0); -- Master Siegesmith Corvus
