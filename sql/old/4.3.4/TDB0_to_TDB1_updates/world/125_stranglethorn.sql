DELETE FROM `gameobject_template` WHERE `entry` IN (202602, 202600, 202601, 207215, 204398, 207216, 204336);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `data24`, `data25`, `data26`, `data27`, `data28`, `data29`, `data30`, `data31`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `unkInt32`, `WDBVerified`) VALUES
(202602, 19, 9058, 'Mailbox', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- -Unknown-
(202600, 8, 166, 'Anvil', '', '', '', 1, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.23, 0, 0, 0, 0, 0, 0, 0, 15595), -- -Unknown-
(202601, 8, 9371, 'Forge', '', '', '', 3, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.760007, 0, 0, 0, 0, 0, 0, 0, 15595), -- -Unknown-
(207215, 8, 200, 'Bonfire', '', '', '', 4, 10, 2066, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.09, 0, 0, 0, 0, 0, 0, 0, 15595), -- -Unknown-
(204398, 3, 9024, 'Bloodsail Sapphire', '', '', '', 43, 30919, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 59032, 0, 0, 0, 0, 0, 0, 15595), -- -Unknown-
(207216, 8, 192, 'Campfire', '', '', '', 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- -Unknown-
(204336, 3, 4853, 'Naga Icon', '', 'Retrieving', '', 43, 30880, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 23645, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.35, 58877, 0, 0, 0, 0, 0, 0, 15595); -- -Unknown-

UPDATE `gameobject_template` SET `data1`=30796, `questItem1`=58811, `questItem2`=60386, `WDBVerified`=15595 WHERE `entry`=759; -- The Holy Spring

SET @OGUID := 1954;

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+111;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0, 2042, 0, 1, 1, -13020, 348.003, 19.2828, 0, 0, 0, 0, 1, 120, 255, 1), -- Fadeleaf (Area: -Unknown-)
-- (@OGUID+1, 176231, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 120, 255, 1), -- 0 (Area: -Unknown-) - !!! transport !!!
(@OGUID+1, 180683, 0, 1, 1, -13112.9, 493.8316, 0, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Firefin Snapper School (Area: -Unknown-)
(@OGUID+2, 180682, 0, 1, 1, -13146, 477.4514, 0, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Oily Blackmouth School (Area: -Unknown-)
(@OGUID+3, 2045, 0, 1, 1, -13056.31, 522.9828, -21.85723, 2.024579, 0, 0, 0, 1, 120, 255, 1), -- Stranglekelp (Area: -Unknown-)
(@OGUID+4, 2042, 0, 1, 1, -13005.4, 433.458, 20.6232, 0, 0, 0, 0, 1, 120, 255, 1), -- Fadeleaf (Area: -Unknown-)
(@OGUID+5, 2043, 0, 1, 1, -12995.3, 438.156, 20.7182, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: -Unknown-)
-- (@OGUID+6, 175080, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 120, 255, 1), -- 0 (Area: Southern Savage Coast) - !!! transport !!!
-- (@OGUID+6, 176310, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 120, 255, 1), -- 0 (Area: Southern Savage Coast) - !!! transport !!!
-- (@OGUID+6, 181689, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 120, 255, 1), -- 0 (Area: Southern Savage Coast) - !!! transport !!!
-- (@OGUID+6, 164871, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 120, 255, 1), -- 0 (Area: Southern Savage Coast) - !!! transport !!!
(@OGUID+6, 180682, 0, 1, 1, -13194.8, 777.1632, 0, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Oily Blackmouth School (Area: Southern Savage Coast)
(@OGUID+7, 180682, 0, 1, 1, -13182.7, 750.6945, 0, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Oily Blackmouth School (Area: Southern Savage Coast)
(@OGUID+8, 2045, 0, 1, 1, -13168.15, 712.9031, -17.13037, 3.926996, 0, 0, 0, 1, 120, 255, 1), -- Stranglekelp (Area: Southern Savage Coast)
-- (@OGUID+9, 190536, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 120, 255, 1), -- 0 (Area: Southern Savage Coast) - !!! transport !!!
(@OGUID+9, 2043, 0, 1, 1, -13137.4, 129.991, 19.7443, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: Gurubashi Arena)
(@OGUID+10, 1733, 0, 1, 1, -13147.6, -160.394, 15.3815, 0, 0, 0, 0, 1, 120, 255, 1), -- Silver Vein (Area: Cape of Stranglethorn)
(@OGUID+11, 2042, 0, 1, 1, -13190.5, -269.948, 12.482, 0, 0, 0, 0, 1, 120, 255, 1), -- Fadeleaf (Area: Cape of Stranglethorn)
(@OGUID+12, 2043, 0, 1, 1, -13224.9, -241.441, 14.868, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: Cape of Stranglethorn)
(@OGUID+13, 179224, 0, 1, 1, -13179.5, -278.016, 11.946, 0.6108655, 0, 0, 0, 1, 120, 255, 1), -- Crystalvein Mine - Keep Out! (Area: Cape of Stranglethorn)
(@OGUID+14, 1735, 0, 1, 1, -13173, -313.983, 16.8209, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: Cape of Stranglethorn)
(@OGUID+15, 1735, 0, 1, 1, -13244.85, -455.9826, 15.29824, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: Crystalvein Mine)
(@OGUID+16, 1735, 0, 1, 1, -13164.06, -445.4705, 9.413768, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: Crystalvein Mine)
(@OGUID+17, 2043, 0, 1, 1, -13268.7, -387.655, 12.3041, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: Crystalvein Mine)
(@OGUID+18, 1735, 0, 1, 1, -13233.64, -509.0399, 12.98413, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: Crystalvein Mine)
-- (@OGUID+19, 20808, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 120, 255, 1), -- 0 (Area: 0) - !!! transport !!!
(@OGUID+19, 2042, 0, 1, 1, -13299.9, -384.7882, 13.30289, 0, 0, 0, 0, 1, 120, 255, 1), -- Fadeleaf (Area: Crystalvein Mine)
(@OGUID+20, 179144, 0, 1, 1, -13275.8, -167.005, 15.9875, 0.3316126, 0, 0, 0, 1, 120, 255, 1), -- Danger! Crystalvein Mine closed! (Area: Crystalvein Mine)
(@OGUID+21, 2042, 0, 1, 1, -13311.4, -206.267, 13.814, 0, 0, 0, 0, 1, 120, 255, 1), -- Fadeleaf (Area: Crystalvein Mine)
(@OGUID+22, 204361, 0, 1, 1, -13343.4, -32.9097, 22.3791, 3.071766, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Cape of Stranglethorn)
(@OGUID+23, 2043, 0, 1, 1, -13300.4, -4.92535, 20.2367, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: Cape of Stranglethorn)
(@OGUID+24, 3209, 0, 1, 1, -13337.75, 67.47569, 25.64831, 5.436701, 0, 0, 0, 1, 120, 255, 1), -- Grom'Gol (Area: Gurubashi Arena)
(@OGUID+25, 3208, 0, 1, 1, -13338.16, 67.86979, 25.72888, 2.295104, 0, 0, 0, 1, 120, 255, 1), -- Booty Bay (Area: Gurubashi Arena)
(@OGUID+26, 3210, 0, 1, 1, -13337.6, 67.98438, 25.79915, 0.7243094, 0, 0, 0, 1, 120, 255, 1), -- Arena (Area: Gurubashi Arena)
(@OGUID+27, 3211, 0, 1, 1, -13331.6, 62.0174, 23.2462, 3.865906, 0, 0, 0, 1, 120, 255, 1), -- Duskwood (Area: Gurubashi Arena)
(@OGUID+28, 3212, 0, 1, 1, -13332.1, 61.8611, 21.7726, 0.7766714, 0, 0, 0, 1, 120, 255, 1), -- Booty Bay (Area: Gurubashi Arena)
(@OGUID+29, 3213, 0, 1, 1, -13332.6, 62.0451, 22.5802, 5.436701, 0, 0, 0, 1, 120, 255, 1), -- Arena (Area: Gurubashi Arena)
-- (@OGUID+30, 181688, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 120, 255, 1), -- 0 (Area: Gurubashi Arena) - !!! transport !!!
(@OGUID+30, 202602, 0, 1, 1, -13240.08, 717.8299, 3.114258, 2.670348, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Southern Savage Coast)
(@OGUID+31, 2045, 0, 1, 1, -13251.6, 781.0868, -7.844138, 2.757613, 0, 0, 0, 1, 120, 255, 1), -- Stranglekelp (Area: Southern Savage Coast)
(@OGUID+32, 180682, 0, 1, 1, -13258.4, 789.3906, 0, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Oily Blackmouth School (Area: Hardwrench Hideaway)
(@OGUID+33, 180683, 0, 1, 1, -13341.2, 803.2327, 0, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Firefin Snapper School (Area: Southern Savage Coast)
(@OGUID+34, 202600, 0, 1, 1, -13306.48, 717.1875, 3.72815, 3.368496, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Southern Savage Coast)
(@OGUID+35, 202601, 0, 1, 1, -13308.21, 722.6424, 3.452968, 5.829401, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Southern Savage Coast)
(@OGUID+36, 180683, 0, 1, 1, -13287.9, 651.0278, 0, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Firefin Snapper School (Area: Hardwrench Hideaway)
(@OGUID+37, 94190, 0, 1, 1, -13371.54, -4.114909, 21.8435, 3.804818, 0, 0, 0, 1, 120, 255, 1), -- Bonfire (Area: Gurubashi Arena)
(@OGUID+38, 204047, 0, 1, 1, -5520.566, 693.2934, 378.2548, 1.989672, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Gurubashi Arena)
(@OGUID+39, 1733, 0, 1, 1, -13410.7, -294.943, 24.5846, 0, 0, 0, 0, 1, 120, 255, 1), -- Silver Vein (Area: Crystalvein Mine)
(@OGUID+40, 1735, 0, 1, 1, -13428.8, 293.54, 45.3965, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: Gurubashi Arena)
(@OGUID+41, 180682, 0, 1, 1, -13448.9, 780.7153, 0, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Oily Blackmouth School (Area: Southern Savage Coast)
(@OGUID+42, 207215, 0, 1, 1, -13463.6, 663.1719, 9.190022, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Southern Savage Coast)
(@OGUID+43, 204398, 0, 1, 1, -13454.4, 661.332, 10.7615, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Southern Savage Coast)
(@OGUID+44, 204398, 0, 1, 1, -13461.9, 658.556, 9.37328, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Hardwrench Hideaway)
(@OGUID+45, 2043, 0, 1, 1, -13466.8, 348.569, 37.1793, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: Cape of Stranglethorn)
(@OGUID+46, 1981, 0, 1, 1, -13485.51, 182.1406, 42.63822, 1.797686, 0, 0, 0, 1, 120, 255, 1), -- Campfire (Area: Gurubashi Arena)
(@OGUID+47, 204399, 0, 1, 1, -13485.2, 184.092, 42.7789, 4.904376, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Gurubashi Arena)
(@OGUID+48, 204399, 0, 1, 1, -13473.6, 176.674, 42.2142, 2.216565, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Gurubashi Arena)
(@OGUID+49, 1735, 0, 1, 1, -13509.2, 627.009, 34.2838, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: Cape of Stranglethorn)
(@OGUID+50, 180682, 0, 1, 1, -13522.5, 814.9063, 0, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Oily Blackmouth School (Area: Southern Savage Coast)
(@OGUID+51, 2042, 0, 1, 1, -13536.9, 711.406, 4.14967, 0, 0, 0, 0, 1, 120, 255, 1), -- Fadeleaf (Area: Southern Savage Coast)
(@OGUID+52, 180683, 0, 1, 1, -13553.4, -465.0938, 0, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Firefin Snapper School (Area: Cape of Stranglethorn)
(@OGUID+53, 180683, 0, 1, 1, -13646, -452.5677, 0, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Firefin Snapper School (Area: The Crystal Shore)
(@OGUID+54, 1735, 0, 1, 1, -13608.1, -387.809, 11.9903, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: The Crystal Shore)
(@OGUID+55, 1735, 0, 1, 1, -13600.1, -209.153, 28.1834, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: Ruins of Aboraz)
(@OGUID+56, 207216, 0, 1, 1, -13628, -68.05209, 35.2389, 3.071766, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Cape of Stranglethorn)
(@OGUID+57, 2042, 0, 1, 1, -13609.2, 163.486, 24.6858, 0, 0, 0, 0, 1, 120, 255, 1), -- Fadeleaf (Area: Cape of Stranglethorn)
(@OGUID+58, 2042, 0, 1, 1, -13610.4, 320.009, 44.3822, 0, 0, 0, 0, 1, 120, 255, 1), -- Fadeleaf (Area: Cape of Stranglethorn)
(@OGUID+59, 2045, 0, 1, 1, -13599.83, 498.1247, -35.31797, 1.710422, 0, 0, 0, 1, 120, 255, 1), -- Stranglekelp (Area: Southern Savage Coast)
(@OGUID+60, 180682, 0, 1, 1, -13635.1, 607.4739, 0, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Oily Blackmouth School (Area: Hardwrench Hideaway)
(@OGUID+61, 204336, 0, 1, 1, -13684.6, 544.92, 29.997, 3.159062, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Hardwrench Hideaway)
(@OGUID+62, 204336, 0, 1, 1, -13679.6, 464.55, 28.6141, 5.707228, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Southern Savage Coast)
(@OGUID+63, 204336, 0, 1, 1, -13679.6, 463.599, 28.7602, 0.2094394, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Southern Savage Coast)
(@OGUID+64, 204336, 0, 1, 1, -13679.2, 462.595, 28.5557, 1.047198, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Southern Savage Coast)
(@OGUID+65, 1735, 0, 1, 1, -13662.3, 490.047, 43.2538, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: Southern Savage Coast)
(@OGUID+66, 94191, 0, 1, 1, -13664.01, -302.026, 8.175347, 4.930556, 0, 0, 0, 1, 120, 255, 1), -- Bonfire (Area: Ruins of Aboraz)
(@OGUID+67, 2042, 0, 1, 1, -13709.8, -400.021, 1.52973, 0, 0, 0, 0, 1, 120, 255, 1), -- Fadeleaf (Area: The Crystal Shore)
(@OGUID+68, 180682, 0, 1, 1, -13722.8, -318.0243, 0, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Oily Blackmouth School (Area: Ruins of Aboraz)
(@OGUID+69, 2042, 0, 1, 1, -13711.4, 91.6476, 26.5697, 0, 0, 0, 0, 1, 120, 255, 1), -- Fadeleaf (Area: Explorers' League Digsite)
(@OGUID+70, 2043, 0, 1, 1, -13699, 305.33, 46.2098, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: Cape of Stranglethorn)
(@OGUID+71, 2042, 0, 1, 1, -13719.9, 485.616, 54.8308, 0, 0, 0, 0, 1, 120, 255, 1), -- Fadeleaf (Area: Southern Savage Coast)
(@OGUID+72, 1735, 0, 1, 1, -13725, 513.672, 54.5373, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: Southern Savage Coast)
(@OGUID+73, 204336, 0, 1, 1, -13727.4, 599.226, 18.0115, 2.164206, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Southern Savage Coast)
(@OGUID+74, 204336, 0, 1, 1, -13729.1, 564.76, 41.8544, 3.33359, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Southern Savage Coast)
(@OGUID+75, 204336, 0, 1, 1, -13704.6, 598.705, 12.9099, 1.151916, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Southern Savage Coast)
(@OGUID+76, 180682, 0, 1, 1, -13566.1, 607.9583, 0, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Oily Blackmouth School (Area: Southern Savage Coast)
(@OGUID+77, 2045, 0, 1, 1, -13738.23, 843.8273, -39.52089, 1.815142, 0, 0, 0, 1, 120, 255, 1), -- Stranglekelp (Area: Southern Savage Coast)
(@OGUID+78, 2045, 0, 1, 1, -13824.53, 756.1116, -20.90007, 1.361356, 0, 0, 0, 1, 120, 255, 1), -- Stranglekelp (Area: Southern Savage Coast)
(@OGUID+79, 204336, 0, 1, 1, -13757.9, 656.323, 11.228, 1.012289, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Southern Savage Coast)
(@OGUID+80, 204336, 0, 1, 1, -13748.2, 618.408, 15.3744, 5.253442, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Southern Savage Coast)
(@OGUID+81, 204336, 0, 1, 1, -13822.3, 649.627, 13.926, 0.1047193, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Southern Savage Coast)
(@OGUID+82, 204336, 0, 1, 1, -13824.9, 592.307, 45.397, 2.024579, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Southern Savage Coast)
(@OGUID+83, 2042, 0, 1, 1, -13819.25, 576.5261, 46.96907, 0, 0, 0, 0, 1, 120, 255, 1), -- Fadeleaf (Area: Southern Savage Coast)
(@OGUID+84, 204336, 0, 1, 1, -13794.5, 536.781, 46.659, 1.762782, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Southern Savage Coast)
(@OGUID+85, 180684, 0, 1, 1, -13778.8, 404.7552, 84.83516, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Greater Sagefish School (Area: Southern Savage Coast)
(@OGUID+86, 759, 0, 1, 1, -13803.3, 372.8924, 93.6595, 2.164207, 0, 0, 0, 1, 120, 255, 1), -- The Holy Spring (Area: Southern Savage Coast)
(@OGUID+87, 204336, 0, 1, 1, -13799.4, 375.703, 95.6695, 3.089183, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Southern Savage Coast)
(@OGUID+88, 204336, 0, 1, 1, -13807.5, 370.505, 95.6695, 1.151916, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Southern Savage Coast)
(@OGUID+89, 180684, 0, 1, 1, -13814.3, 406.7882, 84.83516, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Greater Sagefish School (Area: Southern Savage Coast)
(@OGUID+90, 1735, 0, 1, 1, -13805.1, 73.7118, 37.7484, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: Cape of Stranglethorn)
(@OGUID+91, 2042, 0, 1, 1, -13794.3, -193.313, 12.4729, 0, 0, 0, 0, 1, 120, 255, 1), -- Fadeleaf (Area: Cape of Stranglethorn)
(@OGUID+92, 180682, 0, 1, 1, -13776.9, -268.5556, 0, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Oily Blackmouth School (Area: Cape of Stranglethorn)
(@OGUID+93, 204406, 0, 1, 1, -13747.6, -353.359, 0.138918, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Ruins of Aboraz)
(@OGUID+94, 180682, 0, 1, 1, -13772.6, -364.9618, 0, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Oily Blackmouth School (Area: Ruins of Aboraz)
(@OGUID+95, 2045, 0, 1, 1, -13733.23, -433.0584, -10.50119, 5.183629, 0, 0, 0, 1, 120, 255, 1), -- Stranglekelp (Area: Ruins of Aboraz)
(@OGUID+96, 2045, 0, 1, 1, -13897.64, 765.0219, -21.7174, 4.34587, 0, 0, 0, 1, 120, 255, 1), -- Stranglekelp (Area: Southern Savage Coast)
(@OGUID+97, 204336, 0, 1, 1, -13870.3, 665.971, 13.8849, 1.605702, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Southern Savage Coast)
(@OGUID+98, 204336, 0, 1, 1, -13869.6, 661.615, 14.8805, 4.66003, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Southern Savage Coast)
(@OGUID+99, 2042, 0, 1, 1, -13912.5, 616.828, 22.478, 0, 0, 0, 0, 1, 120, 255, 1), -- Fadeleaf (Area: Southern Savage Coast)
(@OGUID+100, 204336, 0, 1, 1, -13909.3, 633.401, 7.70802, 1.570796, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Southern Savage Coast)
(@OGUID+101, 204336, 0, 1, 1, -13898.3, 598.922, 35.2354, 5.602507, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Southern Savage Coast)
(@OGUID+102, 2042, 0, 1, 1, -13841.1, 630.319, 23.8501, 0, 0, 0, 0, 1, 120, 255, 1), -- Fadeleaf (Area: Southern Savage Coast)
(@OGUID+103, 2046, 0, 1, 1, -13857.4, 598.733, 51.9818, 0, 0, 0, 0, 1, 120, 255, 1), -- Goldthorn (Area: Southern Savage Coast)
(@OGUID+104, 204336, 0, 1, 1, -13888.2, 498.351, 95.8659, 0.4188786, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Cape of Stranglethorn)
(@OGUID+105, 204336, 0, 1, 1, -13848.7, 503.344, 88.1781, 4.852017, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Cape of Stranglethorn)
(@OGUID+106, 204336, 0, 1, 1, -13891.7, 402.194, 107.959, 2.757613, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Cape of Stranglethorn)
(@OGUID+107, 204336, 0, 1, 1, -13837.58, 431.026, 90.30043, 3.787367, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Cape of Stranglethorn)
(@OGUID+108, 204336, 0, 1, 1, -13843.18, 427.4583, 90.29513, 0.6457717, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Cape of Stranglethorn)
(@OGUID+109, 2042, 0, 1, 1, -13831.3, 94.6736, 22.0092, 0, 0, 0, 0, 1, 120, 255, 1), -- Fadeleaf (Area: Cape of Stranglethorn)
(@OGUID+110, 1735, 0, 1, 1, -13779.1, -147.91, 32.9638, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: Cape of Stranglethorn)
(@OGUID+111, 1735, 0, 1, 1, -13735.3, -184.375, 38.3348, 0, 0, 0, 0, 1, 120, 255, 1); -- Iron Deposit (Area: Cape of Stranglethorn)

UPDATE `creature_template` SET `faction_A`=188, `faction_H`=188, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000 WHERE `entry`=49928; -- Crimson Moth
UPDATE `creature_template` SET `gossip_menu_id`=5921, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=14508; -- Short John Mithril
UPDATE `creature_template` SET `faction_A`=188, `faction_H`=188, `speed_walk`=0.8571429, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=49722; -- Tree Python
UPDATE `creature_template` SET `minlevel`=29, `maxlevel`=30, `speed_walk`=1.428571, `speed_run`=1, `rangeattacktime`=2000, `unit_flags`=67108864, `dynamicflags`=4 WHERE `entry`=772; -- Stranglethorn Tigress
UPDATE `creature_template` SET `minlevel`=29, `maxlevel`=30, `speed_walk`=0.5714286, `speed_run`=0.5, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=1713; -- Elder Shadowmaw Panther
UPDATE `creature_template` SET `minlevel`=29, `maxlevel`=29, `speed_walk`=1.142857, `speed_run`=1.111112, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=690; -- Cold Eye Basilisk
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `faction_A`=2160, `faction_H`=2160, `npcflag`=66177, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=512 WHERE `entry`=44190; -- Innkeeper Draxle
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `faction_A`=2160, `faction_H`=2160, `npcflag`=128, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=512 WHERE `entry`=44192; -- Bobber Spazzspark
UPDATE `creature_template` SET `faction_A`=188, `faction_H`=188, `speed_walk`=0.5714286, `speed_run`=0.4, `baseattacktime`=2000, `rangeattacktime`=2000 WHERE `entry`=50479; -- Lizard Hatchling
UPDATE `creature_template` SET `faction_A`=190, `faction_H`=190, `speed_walk`=0.8571429, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=50487; -- Forest Spiderling
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=9600; -- Parrot
UPDATE `creature_template` SET `minlevel`=34, `maxlevel`=34, `faction_A`=189, `faction_H`=189, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=64, `dynamicflags`=0 WHERE `entry`=14492; -- Verifonix
UPDATE `creature_template` SET `minlevel`=29, `maxlevel`=30, `speed_walk`=1.142857, `speed_run`=1.111112, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=1550; -- Thrashtail Basilisk
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `faction_A`=49, `faction_H`=49, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000 WHERE `entry`=44113; -- Ironjaw Behemoth
UPDATE `creature_template` SET `minlevel`=29, `maxlevel`=30, `speed_walk`=1.142857, `speed_run`=1.111112, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=1551; -- Ironjaw Basilisk
UPDATE `creature_template` SET `minlevel`=28, `maxlevel`=29, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=674; -- Venture Co. Strip Miner
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=31, `faction_A`=16, `faction_H`=16, `speed_walk`=0.2857143, `speed_run`=0.4, `baseattacktime`=2000, `rangeattacktime`=2000 WHERE `entry`=43223; -- Zanzil Mindslave
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=31, `speed_walk`=0.2857143, `speed_run`=0.4, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=1488; -- Zanzil Zombie
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `npcflag`=2, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=43099; -- Stone Guard Towhide
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `faction_A`=2159, `faction_H`=2159, `npcflag`=2, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=43097; -- Mixmaster Jasper
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `faction_A`=1574, `faction_H`=1574, `npcflag`=3, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=43098; -- Chabal
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `faction_A`=2160, `faction_H`=2160, `npcflag`=129, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=512 WHERE `entry`=44191; -- Finzy Watchwoozle
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=2159, `faction_H`=2159, `npcflag`=8192, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=512 WHERE `entry`=43053; -- Hizzle
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `faction_A`=2160, `faction_H`=2160, `npcflag`=128, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=512 WHERE `entry`=44193; -- Marpi Greenwrench
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `faction_A`=2160, `faction_H`=2160, `npcflag`=128, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=512 WHERE `entry`=44194; -- Gruzz Thinxlotz
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `faction_A`=2159, `faction_H`=2159, `npcflag`=3, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=43095; -- Sassy Hardwrench
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `faction_A`=2159, `faction_H`=2159, `npcflag`=3, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=43096; -- Flem Gizzix
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `faction_A`=2160, `faction_H`=2160, `npcflag`=640, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=512 WHERE `entry`=44196; -- Pop Sodaslam
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=31, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=1563; -- Bloodsail Swashbuckler
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `faction_A`=2160, `faction_H`=2160, `npcflag`=4224, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=512 WHERE `entry`=44195; -- Smity Hammerhead
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction_A`=1801, `faction_H`=1801, `speed_walk`=1.428571, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=43219; -- Hardwrench Guard
UPDATE `creature_template` SET `minlevel`=49, `maxlevel`=49, `npcflag`=1, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=43205; -- Captain Bartholomew Softbeard
UPDATE `creature_template` SET `minlevel`=47, `maxlevel`=47, `npcflag`=1, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=43204; -- Orgus
UPDATE `creature_template` SET `minlevel`=41, `maxlevel`=41, `npcflag`=1, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=43203; -- Gmurgl
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=31, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=1564; -- Bloodsail Warlock
UPDATE `creature_template` SET `maxlevel`=47, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=5434; -- Coral Shark
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=31, `faction_A`=119, `faction_H`=119, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=43364; -- Bloodsail Hooch-Hound
UPDATE `creature_template` SET `minlevel`=31, `maxlevel`=32, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=1491; -- Zanzil Naga
UPDATE `creature_template` SET `minlevel`=31, `maxlevel`=32, `speed_walk`=1.142857, `speed_run`=0.777776, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=1489; -- Zanzil Hunter
UPDATE `creature_template` SET `minlevel`=32, `maxlevel`=32, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=1490; -- Zanzil Witch Doctor
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=12, `faction_H`=12, `npcflag`=8192, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=512 WHERE `entry`=43043; -- Colin Swifthammer
UPDATE `creature_template` SET `gossip_menu_id`=11801, `minlevel`=32, `maxlevel`=32, `faction_A`=2155, `faction_H`=2155, `npcflag`=4227, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=2, `unit_flags`=32768 WHERE `entry`=44083; -- Linzi Hewstrike
UPDATE `creature_template` SET `gossip_menu_id`=11802, `minlevel`=60, `maxlevel`=60, `faction_A`=1574, `faction_H`=1574, `npcflag`=3, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32832 WHERE `entry`=44084; -- Maywiki
UPDATE `creature_template` SET `minlevel`=33, `maxlevel`=33, `faction_A`=2155, `faction_H`=2155, `npcflag`=3, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=2, `unit_flags`=32768 WHERE `entry`=44099; -- Dask "The Flask" Gobfizzle
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction_A`=2155, `faction_H`=2155, `npcflag`=2, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=2, `unit_flags`=32768 WHERE `entry`=44082; -- Bronwyn Hewstrike
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction_A`=57, `faction_H`=57, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=44106; -- Hambone
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `faction_A`=2155, `faction_H`=2155, `npcflag`=2, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=44100; -- Goris
UPDATE `creature_template` SET `minlevel`=29, `maxlevel`=30, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=1907; -- Naga Explorer
UPDATE `creature_template` SET `minlevel`=32, `maxlevel`=33, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=1558; -- Silverback Patriarch
UPDATE `creature_template` SET `minlevel`=31, `maxlevel`=32, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=1557; -- Elder Mistvale Gorilla
UPDATE `creature_template` SET `minlevel`=32, `maxlevel`=32, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=1449; -- Witch Doctor Unbagwa
UPDATE `creature_template` SET `minlevel`=32, `maxlevel`=32, `speed_walk`=1.142857, `speed_run`=0.777776, `rangeattacktime`=2000, `unit_class`=4, `unit_flags`=32768, `dynamicflags`=0 WHERE `entry`=2535; -- Maury "Club Foot" Wilkins
UPDATE `creature_template` SET `minlevel`=33, `maxlevel`=34, `faction_A`=14, `faction_H`=14, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=43596; -- Venture Co. Oil Worker
UPDATE `creature_template` SET `minlevel`=33, `maxlevel`=33, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `unit_flags`=16384, `dynamicflags`=4 WHERE `entry`=1493; -- Mok'rash

DELETE FROM `creature_template_addon` WHERE `entry` IN (49928, 15475, 15475, 14508, 49928, 49722, 15475, 772, 6827, 1713, 6827, 690, 6827, 32520, 32520, 32520, 32520, 44190, 44192, 6827, 49928, 6827, 6827, 6827, 49722, 50479, 15475, 50487, 49722, 49722, 9600, 15475, 9600, 9600, 9600, 9600, 14492, 49928, 15475, 9600, 50479, 50479, 1550, 9600, 49722, 9600, 1550, 9600, 44113, 1550, 44113, 4076, 48972, 1551, 50479, 4076, 48972, 4076, 4076, 674, 674, 674, 674, 48972, 1551, 44113, 48972, 1551, 1551, 1551, 48972, 1551, 1551, 48972, 48972, 48972, 4076, 48972, 1551, 1551, 1551, 1551, 1551, 1550, 49722, 49928, 1550, 1550, 50479, 1550, 50487, 1550, 49928, 49722, 1550, 49928, 1550, 1550, 43223, 1488, 43223, 1488, 43223, 1488, 1488, 43223, 43223, 1488, 49928, 50479, 1488, 49928, 43223, 50479, 43099, 50487, 772, 6827, 6827, 43097, 43098, 44191, 43053, 44193, 44194, 43095, 6827, 43096, 44196, 6827, 6827, 6827, 1563, 44195, 43219, 43219, 43219, 43205, 43204, 43203, 6827, 1564, 6827, 50479, 1713, 49928, 15475, 1713, 49928, 1713, 50487, 50479, 1488, 15475, 43223, 50487, 50487, 1488, 9600, 43223, 43223, 1488, 1488, 1488, 1488, 1550, 32520, 32520, 32520, 32520, 1488, 1488, 1488, 49928, 43223, 43223, 43223, 49722, 50479, 1564, 49722, 49928, 5434, 1564, 1564, 1564, 1564, 1564, 43364, 43364, 49928, 50487, 50479, 9600, 49722, 9600, 49928, 43364, 1564, 1564, 1563, 1564, 1563, 15475, 1564, 1564, 6827, 6827, 6827, 6827, 1564, 1564, 6827, 1564, 45681, 15475, 1563, 1564, 49722, 1564, 1564, 1564, 50487, 49722, 50487, 1491, 6827, 32520, 32520, 32520, 32520, 1489, 6827, 1490, 1489, 1491, 1489, 1489, 1489, 1491, 1489, 1489, 1489, 1489, 1489, 1489, 50487, 15475, 1491, 43043, 44083, 44084, 44099, 9600, 9600, 50479, 44082, 44106, 44100, 49928, 15475, 9600, 49722, 50487, 49928, 9600, 6827, 6827, 6827, 9600, 9600, 49722, 50487, 1907, 9600, 50479, 49722, 50479, 1713, 1489, 6827, 41200, 1491, 1489, 6827, 6827, 1491, 1490, 1489, 1558, 1557, 49928, 1557, 1557, 50487, 49928, 50487, 1907, 1907, 1907, 6827, 1907, 6827, 6827, 1907, 1907, 1907, 6827, 6827, 1907, 32520, 32520, 32520, 32520, 50487, 1907, 1907, 49722, 49722, 1907, 1907, 15475, 1907, 9600, 49928, 1557, 49722, 15475, 15475, 1557, 9600, 1449, 50479, 15475, 15475, 50487, 1558, 1491, 6827, 2535, 1491, 6827, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 6827, 1558, 1907, 5434, 1493, 6827, 6827, 1907, 6827, 1907, 6827, 1907, 1907, 49722, 1907, 1907, 1907, 1907, 1907, 15475, 1907, 1907, 1907, 50487, 15475, 1557, 1557, 1558, 49722, 1557, 1558, 1558, 1558, 1558, 1489, 43596, 43596, 43596, 43596);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(1449, 0, 0x0, 0x1, ''), -- Witch Doctor Unbagwa
(14492, 0, 0x1, 0x1, ''), -- Verifonix
(14508, 0, 0x0, 0x1, ''), -- Short John Mithril
(1488, 0, 0x0, 0x1, '83867'), -- Zanzil Zombie - Zanzil's Elixir
(1489, 0, 0x0, 0x1, ''), -- Zanzil Hunter
(1490, 0, 0x0, 0x1, ''), -- Zanzil Witch Doctor
(1491, 0, 0x0, 0x1, ''), -- Zanzil Naga
(1493, 0, 0x0, 0x1, ''), -- Mok'rash
(15475, 0, 0x0, 0x1, ''), -- Beetle
(1550, 0, 0x0, 0x1, ''), -- Thrashtail Basilisk
(1551, 0, 0x0, 0x1, ''), -- Ironjaw Basilisk
(1557, 0, 0x0, 0x1, ''), -- Elder Mistvale Gorilla
(1558, 0, 0x0, 0x1, ''), -- Silverback Patriarch
(1563, 0, 0x0, 0x1, ''), -- Bloodsail Swashbuckler
(1564, 0, 0x0, 0x1, ''), -- Bloodsail Warlock
(1713, 0, 0x0, 0x1, ''), -- Elder Shadowmaw Panther
-- (1713, 0, 0x20000, 0x1, '22766'), -- Elder Shadowmaw Panther - Sneak
(1907, 0, 0x0, 0x1, ''), -- Naga Explorer
(2535, 0, 0x0, 0x1, ''), -- Maury "Club Foot" Wilkins
(32520, 0, 0x0, 0x1, ''), -- Totally Generic Bunny (All Phase)
(4076, 0, 0x0, 0x1, ''), -- Roach
(41200, 0, 0x3000000, 0x1, ''), -- Generic Bunny - PRK
(43043, 0, 0x0, 0x101, ''), -- Colin Swifthammer
(43053, 0, 0x0, 0x101, ''), -- Hizzle
(43095, 0, 0x0, 0x101, ''), -- Sassy Hardwrench
(43096, 0, 0x0, 0x101, ''), -- Flem Gizzix
(43097, 0, 0x0, 0x101, ''), -- Mixmaster Jasper
(43098, 0, 0x0, 0x101, ''), -- Chabal
(43099, 0, 0x0, 0x101, ''), -- Stone Guard Towhide
(43203, 0, 0x0, 0x1, ''), -- Gmurgl
(43204, 0, 0x1, 0x1, ''), -- Orgus
(43205, 0, 0x0, 0x1, ''), -- Captain Bartholomew Softbeard
(43219, 0, 0x0, 0x2, ''), -- Hardwrench Guard
(43223, 0, 0x0, 0x1, '83864'), -- Zanzil Mindslave - Zanzil's Elixir
(43364, 0, 0x0, 0x1, '78677'), -- Bloodsail Hooch-Hound - Cosmetic - Sleep Zzz Breakable
(43596, 0, 0x3000000, 0x1, ''), -- Venture Co. Oil Worker
(44082, 0, 0x0, 0x101, ''), -- Bronwyn Hewstrike
(44083, 0, 0x0, 0x101, ''), -- Linzi Hewstrike
(44084, 0, 0x1, 0x1, ''), -- Maywiki
(44099, 0, 0x0, 0x101, ''), -- Dask "The Flask" Gobfizzle
(44100, 0, 0x0, 0x101, ''), -- Goris
(44106, 0, 0x0, 0x1, ''), -- Hambone
(44113, 0, 0x0, 0x1, ''), -- Ironjaw Behemoth
(44190, 0, 0x0, 0x101, ''), -- Innkeeper Draxle
(44191, 0, 0x0, 0x101, ''), -- Finzy Watchwoozle
(44192, 0, 0x0, 0x101, ''), -- Bobber Spazzspark
(44193, 0, 0x0, 0x101, ''), -- Marpi Greenwrench
(44194, 0, 0x0, 0x101, ''), -- Gruzz Thinxlotz
(44195, 0, 0x0, 0x101, ''), -- Smity Hammerhead
(44196, 0, 0x0, 0x101, ''), -- Pop Sodaslam
(45681, 0, 0x0, 0x1, ''), -- Garginox
(48972, 0, 0x0, 0x1, ''), -- Long-tailed Mole
(49722, 0, 0x0, 0x1, ''), -- Tree Python
(49928, 0, 0x3000000, 0x1, ''), -- Crimson Moth
(50479, 0, 0x0, 0x1, ''), -- Lizard Hatchling
(50487, 0, 0x0, 0x1, ''), -- Forest Spiderling
(5434, 0, 0x0, 0x1, ''), -- Coral Shark
(674, 0, 0x0, 0x1, ''), -- Venture Co. Strip Miner
(6827, 0, 0x0, 0x1, ''), -- Crab
(690, 0, 0x0, 0x1, ''), -- Cold Eye Basilisk
(772, 0, 0x0, 0x1, ''), -- Stranglethorn Tigress
(9600, 0, 0x3000000, 0x1, ''); -- Parrot

UPDATE `creature_model_info` SET `gender`=0 WHERE `modelid`=314;
UPDATE `creature_model_info` SET `gender`=0 WHERE `modelid`=838;
UPDATE `creature_model_info` SET `gender`=0 WHERE `modelid`=844;
UPDATE `creature_model_info` SET `bounding_radius`=1.764, `combat_reach`=1.5 WHERE `modelid`=1167;
UPDATE `creature_model_info` SET `bounding_radius`=0.21, `combat_reach`=0.3 WHERE `modelid`=4343;
UPDATE `creature_model_info` SET `bounding_radius`=0.7, `combat_reach`=0.875 WHERE `modelid`=5560;
UPDATE `creature_model_info` SET `bounding_radius`=0.69, `combat_reach`=1.725 WHERE `modelid`=12192;
UPDATE `creature_model_info` SET `gender`=0 WHERE `modelid`=12812;
UPDATE `creature_model_info` SET `gender`=0 WHERE `modelid`=16228;
UPDATE `creature_model_info` SET `bounding_radius`=5, `combat_reach`=10 WHERE `modelid`=21171;
UPDATE `creature_model_info` SET `bounding_radius`=0.3366, `combat_reach`=1.65, `gender`=0 WHERE `modelid`=33188;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=33206;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=33207;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=33208;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=33209;
UPDATE `creature_model_info` SET `bounding_radius`=0.9747, `combat_reach`=4.05, `gender`=0 WHERE `modelid`=33210;
UPDATE `creature_model_info` SET `bounding_radius`=0.4513886, `combat_reach`=1.95, `gender`=0 WHERE `modelid`=33216;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=33268;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=33271;
UPDATE `creature_model_info` SET `bounding_radius`=0.4164, `combat_reach`=1.8, `gender`=0 WHERE `modelid`=33670;
UPDATE `creature_model_info` SET `bounding_radius`=0.29495, `combat_reach`=1.275, `gender`=1 WHERE `modelid`=33671;
UPDATE `creature_model_info` SET `bounding_radius`=0.3519, `combat_reach`=1.725, `gender`=0 WHERE `modelid`=33674;
UPDATE `creature_model_info` SET `bounding_radius`=0.347, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=33675;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=33708;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=33709;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=33710;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=33711;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=33712;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=33713;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=33714;
UPDATE `creature_model_info` SET `bounding_radius`=0.031, `combat_reach`=0.1 WHERE `modelid`=36599;
UPDATE `creature_model_info` SET `bounding_radius`=0.0875, `combat_reach`=0.25 WHERE `modelid`=36671;
UPDATE `creature_model_info` SET `bounding_radius`=1.6967, `combat_reach`=2.85, `gender`=0 WHERE `modelid`=37203;

SET @CGUID := 15226;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+405;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 49928, 0, 1, 1, -13007.42, 197.6326, 31.65138, 4.210367, 120, 0, 0), -- Crimson Moth (Area: -Unknown-)
(@CGUID+1, 15475, 0, 1, 1, -13013.72, 188.9984, 22.47321, 1.007248, 120, 0, 0), -- Beetle (Area: -Unknown-)
(@CGUID+2, 15475, 0, 1, 1, -13025, 317.6837, 20.14494, 5.88599, 120, 0, 0), -- Beetle (Area: -Unknown-)
(@CGUID+3, 14508, 0, 1, 1, -13184.48, 332.6711, 40.32992, 4.415683, 120, 0, 0), -- Short John Mithril (Area: -Unknown-)
(@CGUID+4, 49928, 0, 1, 1, -13078.88, 361.1179, 57.05969, 2.143483, 120, 0, 0), -- Crimson Moth (Area: -Unknown-)
(@CGUID+5, 49722, 0, 1, 1, -13111.74, 362.9447, 16.22646, 4.517427, 120, 0, 0), -- Tree Python (Area: -Unknown-) (possible waypoints or random movement)
(@CGUID+6, 15475, 0, 1, 1, -13046.14, 383.9904, 19.38317, 6.181377, 120, 0, 0), -- Beetle (Area: -Unknown-)
(@CGUID+7, 772, 0, 1, 1, -13051.36, 382.3053, 19.08081, 2.313151, 120, 0, 0), -- Stranglethorn Tigress (Area: -Unknown-)
(@CGUID+8, 6827, 0, 1, 1, -13156.01, 461.5966, 2.540853, 2.91699, 120, 0, 0), -- Crab (Area: -Unknown-)
(@CGUID+9, 1713, 0, 1, 1, -13076.91, 418.9794, 24.92586, 6.166489, 120, 0, 0), -- Elder Shadowmaw Panther (Area: -Unknown-)
(@CGUID+10, 6827, 0, 1, 1, -13020.85, 479.4423, 9.61664, 0.7550208, 120, 0, 0), -- Crab (Area: -Unknown-)
(@CGUID+11, 690, 0, 1, 1, -12987.5, 458.334, 19.39863, 1.359566, 120, 0, 0), -- Cold Eye Basilisk (Area: -Unknown-)
(@CGUID+12, 6827, 0, 1, 1, -13058.38, 491.6281, 1.894867, 0.7853982, 120, 0, 0), -- Crab (Area: -Unknown-)
(@CGUID+13, 32520, 0, 1, 1, -6305.162, 5582.533, -1172.063, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Southern Savage Coast)
(@CGUID+14, 32520, 0, 1, 1, -6014.71, 5479.63, -1208.007, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Southern Savage Coast)
(@CGUID+15, 32520, 0, 1, 1, -6148.39, 5539.97, -1207.787, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Southern Savage Coast)
(@CGUID+16, 32520, 0, 1, 1, -5691.65, 5556.92, -1154.687, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Southern Savage Coast)
(@CGUID+17, 44190, 0, 1, 1, -13232.24, 724.2483, 3.438883, 2.984513, 120, 0, 0), -- Innkeeper Draxle (Area: Southern Savage Coast)
(@CGUID+18, 44192, 0, 1, 1, -13226, 739.033, 3.235343, 2.478368, 120, 0, 0), -- Bobber Spazzspark (Area: Southern Savage Coast)
(@CGUID+19, 6827, 0, 1, 1, -13196.2, 715.65, 1.663972, 1.257075, 120, 0, 0), -- Crab (Area: Southern Savage Coast)
(@CGUID+20, 49928, 0, 1, 1, -13208.26, 498.7986, 21.68156, 0.9876552, 120, 0, 0), -- Crimson Moth (Area: Southern Savage Coast)
(@CGUID+21, 6827, 0, 1, 1, -13170.73, 470.3004, 6.100735, 5.29357, 120, 0, 0), -- Crab (Area: Southern Savage Coast)
(@CGUID+22, 6827, 0, 1, 1, -13196.19, 508.0364, 1.751871, 1.694182, 120, 0, 0), -- Crab (Area: Southern Savage Coast)
(@CGUID+23, 6827, 0, 1, 1, -13186.23, 500.666, -0.7826185, 5.349731, 120, 0, 0), -- Crab (Area: Southern Savage Coast)
(@CGUID+24, 49722, 0, 1, 1, -13175.29, 425.5715, 15.84972, 4.70653, 120, 0, 0), -- Tree Python (Area: Southern Savage Coast) (possible waypoints or random movement)
(@CGUID+25, 50479, 0, 1, 1, -13047.61, 222.8701, 22.32092, 0.3363146, 120, 0, 0), -- Lizard Hatchling (Area: Gurubashi Arena)
(@CGUID+26, 15475, 0, 1, 1, -13059.61, 199.0069, 22.08718, 2.191673, 120, 0, 0), -- Beetle (Area: Gurubashi Arena)
(@CGUID+27, 50487, 0, 1, 1, -13152.97, 112.9923, 24.55525, 4.965015, 120, 0, 0), -- Forest Spiderling (Area: Gurubashi Arena) (possible waypoints or random movement)
(@CGUID+28, 49722, 0, 1, 1, -13097.54, 97.61447, 27.4901, 4.06211, 120, 0, 0), -- Tree Python (Area: Gurubashi Arena) (possible waypoints or random movement)
(@CGUID+29, 49722, 0, 1, 1, -13236.79, 41.98174, 19.16522, 1.81151, 120, 0, 0), -- Tree Python (Area: Gurubashi Arena) (possible waypoints or random movement)
(@CGUID+30, 9600, 0, 1, 1, -13245.09, 62.74201, 49.37212, 5.532525, 120, 0, 0), -- Parrot (Area: Gurubashi Arena)
(@CGUID+31, 15475, 0, 1, 1, -13221.72, 105.2963, 17.33057, 0.2191402, 120, 0, 0), -- Beetle (Area: Gurubashi Arena)
(@CGUID+32, 9600, 0, 1, 1, -13235.77, 118.8285, 86.98997, 5.143035, 120, 0, 0), -- Parrot (Area: Gurubashi Arena)
(@CGUID+33, 9600, 0, 1, 1, -13230.29, -41.60769, 56.0448, 5.53524, 120, 0, 0), -- Parrot (Area: Cape of Stranglethorn)
(@CGUID+34, 9600, 0, 1, 1, -13247.35, -22.47458, 38.81517, 4.512609, 120, 0, 0), -- Parrot (Area: Cape of Stranglethorn)
(@CGUID+35, 9600, 0, 1, 1, -13244.02, 39.35972, 43.94913, 0.8726059, 120, 0, 0), -- Parrot (Area: Cape of Stranglethorn)
(@CGUID+36, 14492, 0, 1, 1, -13242.73, 10.50694, 18.08746, 3.368485, 120, 0, 0), -- Verifonix (Area: Cape of Stranglethorn)
(@CGUID+37, 49928, 0, 1, 1, -13228.13, -170.4746, 36.2263, 2.283868, 120, 0, 0), -- Crimson Moth (Area: Cape of Stranglethorn)
(@CGUID+38, 15475, 0, 1, 1, -13240.07, -181.4918, 14.88022, 4.989271, 120, 0, 0), -- Beetle (Area: Cape of Stranglethorn)
(@CGUID+39, 9600, 0, 1, 1, -13144.87, -227.067, 38.23662, 3.914152, 120, 0, 0), -- Parrot (Area: Cape of Stranglethorn)
(@CGUID+40, 50479, 0, 1, 1, -13242.94, -301.7481, 15.43045, 5.229354, 120, 0, 0), -- Lizard Hatchling (Area: Cape of Stranglethorn)
(@CGUID+41, 50479, 0, 1, 1, -13243.16, -267.066, 16.68394, 1.26215, 120, 0, 0), -- Lizard Hatchling (Area: Cape of Stranglethorn)
(@CGUID+42, 1550, 0, 1, 1, -13180.57, -280.2523, 12.16535, 3.965533, 120, 0, 0), -- Thrashtail Basilisk (Area: Cape of Stranglethorn)
(@CGUID+43, 9600, 0, 1, 1, -13171.18, -285.1187, 37.00066, 5.462337, 120, 0, 0), -- Parrot (Area: Cape of Stranglethorn)
(@CGUID+44, 49722, 0, 1, 1, -13059.08, -292.0428, 21.3751, 6.076316, 120, 0, 0), -- Tree Python (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+45, 9600, 0, 1, 1, -13053.22, -268.511, 45.5462, 1.474964, 120, 0, 0), -- Parrot (Area: Cape of Stranglethorn)
(@CGUID+46, 1550, 0, 1, 1, -13070.37, -253.2714, 18.46457, 1.008939, 120, 0, 0), -- Thrashtail Basilisk (Area: Cape of Stranglethorn)
(@CGUID+47, 9600, 0, 1, 1, -13057.31, -239.3204, 41.40981, 0.7324123, 120, 0, 0), -- Parrot (Area: Cape of Stranglethorn)
(@CGUID+48, 44113, 0, 1, 1, -13155.61, -461.7604, 7.603277, 3.729273, 120, 0, 0), -- Ironjaw Behemoth (Area: Cape of Stranglethorn)
(@CGUID+49, 1550, 0, 1, 1, -13247.84, -352.2775, 11.94922, 0.4909546, 120, 0, 0), -- Thrashtail Basilisk (Area: Cape of Stranglethorn)
(@CGUID+50, 44113, 0, 1, 1, -13208.64, -500.2751, 4.234866, 3.143188, 120, 0, 0), -- Ironjaw Behemoth (Area: Cape of Stranglethorn)
(@CGUID+51, 4076, 0, 1, 1, -13227.22, -447.8442, 7.385756, 3.656701, 120, 0, 0), -- Roach (Area: Crystalvein Mine)
(@CGUID+52, 48972, 0, 1, 1, -13248.92, -476.0002, 18.16103, 5.140422, 120, 0, 0), -- Long-tailed Mole (Area: Crystalvein Mine)
(@CGUID+53, 1551, 0, 1, 1, -13222.45, -502.5745, 9.508168, 5.283815, 120, 0, 0), -- Ironjaw Basilisk (Area: Crystalvein Mine)
(@CGUID+54, 50479, 0, 1, 1, -13274.68, -404.2256, 12.51955, 0.1371997, 120, 0, 0), -- Lizard Hatchling (Area: Crystalvein Mine)
(@CGUID+55, 4076, 0, 1, 1, -13157.86, -494.9517, 9.495394, 0.7786095, 120, 0, 0), -- Roach (Area: Crystalvein Mine)
(@CGUID+56, 48972, 0, 1, 1, -13132.23, -480.0813, 9.790042, 1.720675, 120, 0, 0), -- Long-tailed Mole (Area: Crystalvein Mine)
(@CGUID+57, 4076, 0, 1, 1, -13157.75, -475.9598, 5.756959, 3.40565, 120, 0, 0), -- Roach (Area: Crystalvein Mine)
(@CGUID+58, 4076, 0, 1, 1, -13184.84, -453.1662, 7.079503, 4.774984, 120, 0, 0), -- Roach (Area: Crystalvein Mine)
(@CGUID+59, 674, 0, 1, 1, -13130.48, -463.0995, 49.70002, 0.9424778, 120, 0, 0), -- Venture Co. Strip Miner (Area: Crystalvein Mine)
(@CGUID+60, 674, 0, 1, 1, -13090.46, -444.3494, 52.50059, 2.9147, 120, 0, 0), -- Venture Co. Strip Miner (Area: Crystalvein Mine)
(@CGUID+61, 674, 0, 1, 1, -13138.5, -460.8553, 51.15911, 2.286381, 120, 0, 0), -- Venture Co. Strip Miner (Area: Crystalvein Mine)
(@CGUID+62, 674, 0, 1, 1, -13135.01, -469.8795, 49.83551, 4.956735, 120, 0, 0), -- Venture Co. Strip Miner (Area: Crystalvein Mine)
(@CGUID+63, 48972, 0, 1, 1, -13128.28, -498.0402, 8.789081, 2.102184, 120, 0, 0), -- Long-tailed Mole (Area: Crystalvein Mine)
(@CGUID+64, 1551, 0, 1, 1, -13138.64, -487.2727, 8.518972, 1.087142, 120, 0, 0), -- Ironjaw Basilisk (Area: Crystalvein Mine)
(@CGUID+65, 44113, 0, 1, 1, -13221.53, -595.0573, 4.642443, 3.614082, 120, 0, 0), -- Ironjaw Behemoth (Area: Crystalvein Mine)
(@CGUID+66, 48972, 0, 1, 1, -13264.52, -563.3714, 16.22334, 3.991302, 120, 0, 0), -- Long-tailed Mole (Area: Crystalvein Mine)
(@CGUID+67, 1551, 0, 1, 1, -13202.5, -575.5721, 12.83333, 0.0222112, 120, 0, 0), -- Ironjaw Basilisk (Area: Crystalvein Mine)
(@CGUID+68, 1551, 0, 1, 1, -13226.1, -558.863, 4.642443, 2.449045, 120, 0, 0), -- Ironjaw Basilisk (Area: Crystalvein Mine)
(@CGUID+69, 1551, 0, 1, 1, -13206.62, -548.8417, 4.642443, 3.465792, 120, 0, 0), -- Ironjaw Basilisk (Area: Crystalvein Mine)
(@CGUID+70, 48972, 0, 1, 1, -13169.71, -548.1603, 8.911263, 2.458853, 120, 0, 0), -- Long-tailed Mole (Area: Crystalvein Mine)
(@CGUID+71, 1551, 0, 1, 1, -13170.03, -552.3108, 9.346971, 4.886922, 120, 0, 0), -- Ironjaw Basilisk (Area: Crystalvein Mine)
(@CGUID+72, 1551, 0, 1, 1, -13156.41, -562.2662, 4.642443, 1.320691, 120, 0, 0), -- Ironjaw Basilisk (Area: Crystalvein Mine)
(@CGUID+73, 48972, 0, 1, 1, -13288.04, -427.3945, 16.11661, 1.395098, 120, 0, 0), -- Long-tailed Mole (Area: Crystalvein Mine)
(@CGUID+74, 48972, 0, 1, 1, -13267.28, -513.5395, 17.93496, 3.455363, 120, 0, 0), -- Long-tailed Mole (Area: Crystalvein Mine)
(@CGUID+75, 48972, 0, 1, 1, -13283, -479.3186, 17.67089, 1.237135, 120, 0, 0), -- Long-tailed Mole (Area: Crystalvein Mine)
(@CGUID+76, 4076, 0, 1, 1, -13271.58, -484.8506, 19.39806, 0.382936, 120, 0, 0), -- Roach (Area: Crystalvein Mine)
(@CGUID+77, 48972, 0, 1, 1, -13272.38, -491.3983, 19.78507, 5.073686, 120, 0, 0), -- Long-tailed Mole (Area: Crystalvein Mine)
(@CGUID+78, 1551, 0, 1, 1, -13260.12, -523.9885, 16.3005, 1.558655, 120, 0, 0), -- Ironjaw Basilisk (Area: Crystalvein Mine)
(@CGUID+79, 1551, 0, 1, 1, -13258.26, -485.8168, 18.95555, 0, 120, 0, 0), -- Ironjaw Basilisk (Area: Crystalvein Mine)
(@CGUID+80, 1551, 0, 1, 1, -13301.36, -444.6371, 15.51744, 5.782215, 120, 0, 0), -- Ironjaw Basilisk (Area: Crystalvein Mine)
(@CGUID+81, 1551, 0, 1, 1, -13258.02, -579.0631, 12.9508, 0.9966342, 120, 0, 0), -- Ironjaw Basilisk (Area: Crystalvein Mine)
(@CGUID+82, 1551, 0, 1, 1, -13193.7, -595.9173, 4.642443, 3.86076, 120, 0, 0), -- Ironjaw Basilisk (Area: Crystalvein Mine)
(@CGUID+83, 1550, 0, 1, 1, -13325.82, -411.9829, 14.8046, 2.401135, 120, 0, 0), -- Thrashtail Basilisk (Area: Crystalvein Mine)
(@CGUID+84, 49722, 0, 1, 1, -13343.35, -396.4732, 15.08416, 5.370348, 120, 0, 0), -- Tree Python (Area: Crystalvein Mine) (possible waypoints or random movement)
(@CGUID+85, 49928, 0, 1, 1, -13323.12, -367.3945, 30.15332, 5.112198, 120, 0, 0), -- Crimson Moth (Area: Crystalvein Mine)
(@CGUID+86, 1550, 0, 1, 1, -13319.76, -355.0257, 13.92659, 0.2348889, 120, 0, 0), -- Thrashtail Basilisk (Area: Crystalvein Mine)
(@CGUID+87, 1550, 0, 1, 1, -13280.17, -395.582, 12.32882, 5.59639, 120, 0, 0), -- Thrashtail Basilisk (Area: Crystalvein Mine)
(@CGUID+88, 50479, 0, 1, 1, -13365.46, -347.7488, 14.45684, 5.902732, 120, 0, 0), -- Lizard Hatchling (Area: Crystalvein Mine)
(@CGUID+89, 1550, 0, 1, 1, -13379.55, -357.4427, 16.7426, 0.4891145, 120, 0, 0), -- Thrashtail Basilisk (Area: Crystalvein Mine)
(@CGUID+90, 50487, 0, 1, 1, -13317.74, -317.2169, 13.24406, 1.99775, 120, 0, 0), -- Forest Spiderling (Area: Crystalvein Mine) (possible waypoints or random movement)
(@CGUID+91, 1550, 0, 1, 1, -13312.78, -278.8179, 14.55079, 0.068179, 120, 0, 0), -- Thrashtail Basilisk (Area: Crystalvein Mine)
(@CGUID+92, 49928, 0, 1, 1, -13334.38, -266.6975, 29.33121, 2.350658, 120, 0, 0), -- Crimson Moth (Area: Crystalvein Mine)
(@CGUID+93, 49722, 0, 1, 1, -13297.15, -238.1721, 14.9211, 5.474389, 120, 0, 0), -- Tree Python (Area: Crystalvein Mine) (possible waypoints or random movement)
(@CGUID+94, 1550, 0, 1, 1, -13273.75, -253.9188, 16.99825, 1.608492, 120, 0, 0), -- Thrashtail Basilisk (Area: Crystalvein Mine)
(@CGUID+95, 49928, 0, 1, 1, -13298.5, -207.9221, 35.45506, 5.788225, 120, 0, 0), -- Crimson Moth (Area: Crystalvein Mine)
(@CGUID+96, 1550, 0, 1, 1, -13318.68, -214.6216, 14.73269, 2.298874, 120, 0, 0), -- Thrashtail Basilisk (Area: Crystalvein Mine)
(@CGUID+97, 1550, 0, 1, 1, -13286.46, -187.5784, 14.91816, 2.076112, 120, 0, 0), -- Thrashtail Basilisk (Area: Crystalvein Mine)
(@CGUID+98, 43223, 0, 1, 1, -13310.62, -35.06236, 20.70578, 1.884855, 120, 0, 0), -- Zanzil Mindslave (Area: Cape of Stranglethorn)
(@CGUID+99, 1488, 0, 1, 1, -13341.5, -16.31597, 35.59959, 1.413717, 120, 0, 0), -- Zanzil Zombie (Area: Cape of Stranglethorn)
(@CGUID+100, 43223, 0, 1, 1, -13318.17, -11.27677, 21.50758, 6.078516, 120, 0, 0), -- Zanzil Mindslave (Area: Cape of Stranglethorn)
(@CGUID+101, 1488, 0, 1, 1, -13280.5, -15.28566, 28.07831, 4.674822, 120, 0, 0), -- Zanzil Zombie (Area: Cape of Stranglethorn)
(@CGUID+102, 43223, 0, 1, 1, -13297.07, -15.25701, 20.64887, 4.718809, 120, 0, 0), -- Zanzil Mindslave (Area: Cape of Stranglethorn)
(@CGUID+103, 1488, 0, 1, 1, -13288.19, -12.48679, 25.59589, 3.360327, 120, 0, 0), -- Zanzil Zombie (Area: Cape of Stranglethorn)
(@CGUID+104, 1488, 0, 1, 1, -13296.51, -1.393636, 20.207, 4.01329, 120, 0, 0), -- Zanzil Zombie (Area: Cape of Stranglethorn)
(@CGUID+105, 43223, 0, 1, 1, -13356.86, 6.440164, 21.11666, 4.146655, 120, 0, 0), -- Zanzil Mindslave (Area: Cape of Stranglethorn)
(@CGUID+106, 43223, 0, 1, 1, -13338.99, 14.65597, 25.95447, 6.057666, 120, 0, 0), -- Zanzil Mindslave (Area: Cape of Stranglethorn)
(@CGUID+107, 1488, 0, 1, 1, -13339.66, 26.31623, 27.58899, 0.1482994, 120, 0, 0), -- Zanzil Zombie (Area: Cape of Stranglethorn)
(@CGUID+108, 49928, 0, 1, 1, -13288.26, 51.79161, 40.76821, 5.944679, 120, 0, 0), -- Crimson Moth (Area: Cape of Stranglethorn)
(@CGUID+109, 50479, 0, 1, 1, -13255.44, 64.31284, 16.70045, 4.938895, 120, 0, 0), -- Lizard Hatchling (Area: Cape of Stranglethorn)
(@CGUID+110, 1488, 0, 1, 1, -13314.8, 7.22569, 36.21043, 0.7504916, 120, 0, 0), -- Zanzil Zombie (Area: Cape of Stranglethorn)
(@CGUID+111, 49928, 0, 1, 1, -13318.25, 126.3031, 54.50682, 0.09534636, 120, 0, 0), -- Crimson Moth (Area: Gurubashi Arena)
(@CGUID+112, 43223, 0, 1, 1, -13328.9, 108.1265, 18.61148, 1.539557, 120, 0, 0), -- Zanzil Mindslave (Area: Gurubashi Arena)
(@CGUID+113, 50479, 0, 1, 1, -13326.37, 119.4985, 18.27509, 2.819842, 120, 0, 0), -- Lizard Hatchling (Area: Gurubashi Arena)
(@CGUID+114, 43099, 0, 1, 1, -13257.36, 284.4375, 33.32587, 6.126106, 120, 0, 0), -- Stone Guard Towhide (Area: Gurubashi Arena)
(@CGUID+115, 50487, 0, 1, 1, -13251.08, 451.4907, 5.282491, 1.079434, 120, 0, 0), -- Forest Spiderling (Area: Gurubashi Arena) (possible waypoints or random movement)
(@CGUID+116, 772, 0, 1, 1, -13231.8, 518.0735, 1.346276, 3.389291, 120, 0, 0), -- Stranglethorn Tigress (Area: Southern Savage Coast)
(@CGUID+117, 6827, 0, 1, 1, -13283.5, 547.1407, 1.384561, 4.44417, 120, 0, 0), -- Crab (Area: Southern Savage Coast)
(@CGUID+118, 6827, 0, 1, 1, -13284.09, 657.5186, -2.213593, 5.143705, 120, 0, 0), -- Crab (Area: Southern Savage Coast)
(@CGUID+119, 43097, 0, 1, 1, -13239.8, 719.979, 3.239773, 3.159046, 120, 0, 0), -- Mixmaster Jasper (Area: Southern Savage Coast)
(@CGUID+120, 43098, 0, 1, 1, -13252, 744.872, 3.516893, 5.462881, 120, 0, 0), -- Chabal (Area: Southern Savage Coast)
(@CGUID+121, 44191, 0, 1, 1, -13236.7, 732.17, 3.435733, 2.391101, 120, 0, 0), -- Finzy Watchwoozle (Area: Southern Savage Coast)
(@CGUID+122, 43053, 0, 1, 1, -13290.03, 721.684, 3.872531, 0, 120, 0, 0), -- Hizzle (Area: Southern Savage Coast)
(@CGUID+123, 44193, 0, 1, 1, -13254.9, 741.057, 3.63745, 0.7794712, 120, 0, 0), -- Marpi Greenwrench (Area: Southern Savage Coast) (possible waypoints or random movement)
(@CGUID+124, 44194, 0, 1, 1, -13252.4, 708.085, 3.263733, 0, 120, 0, 0), -- Gruzz Thinxlotz (Area: Southern Savage Coast)
(@CGUID+125, 43095, 0, 1, 1, -13294, 739.543, 3.186223, 2.897247, 120, 0, 0), -- Sassy Hardwrench (Area: Southern Savage Coast)
(@CGUID+126, 6827, 0, 1, 1, -13268.82, 683.8383, 2.804757, 0.9757516, 120, 0, 0), -- Crab (Area: Southern Savage Coast)
(@CGUID+127, 43096, 0, 1, 1, -13284.4, 780.715, 3.075783, 4.817109, 120, 0, 0), -- Flem Gizzix (Area: Hardwrench Hideaway)
(@CGUID+128, 44196, 0, 1, 1, -13305.71, 780.5364, 3.213595, 4.642576, 120, 0, 0), -- Pop Sodaslam (Area: Southern Savage Coast) (possible waypoints or random movement)
(@CGUID+129, 6827, 0, 1, 1, -13326.08, 777.8772, 3.105918, 5.196111, 120, 0, 0), -- Crab (Area: Southern Savage Coast)
(@CGUID+130, 6827, 0, 1, 1, -13359.49, 743.2693, 4.170659, 4.100543, 120, 0, 0), -- Crab (Area: Southern Savage Coast)
(@CGUID+131, 6827, 0, 1, 1, -13404.16, 779.1416, -0.1736245, 5.666225, 120, 0, 0), -- Crab (Area: Southern Savage Coast)
(@CGUID+132, 1563, 0, 1, 1, -13425.2, 757.9824, 1.600653, 3.215381, 120, 0, 0), -- Bloodsail Swashbuckler (Area: Southern Savage Coast) (possible waypoints or random movement)
(@CGUID+133, 44195, 0, 1, 1, -13305.7, 718.273, 3.884433, 4.258604, 120, 0, 0), -- Smity Hammerhead (Area: Southern Savage Coast)
(@CGUID+134, 43219, 0, 1, 1, -13308.55, 698.6528, 4.002179, 3.874631, 120, 0, 0), -- Hardwrench Guard (Area: Southern Savage Coast)
(@CGUID+135, 43219, 0, 1, 1, -13311.47, 701.1927, 4.086895, 3.787364, 120, 0, 0), -- Hardwrench Guard (Area: Southern Savage Coast)
(@CGUID+136, 43219, 0, 1, 1, -13306.45, 697.2639, 4.095367, 4.153883, 120, 0, 0), -- Hardwrench Guard (Area: Southern Savage Coast)
(@CGUID+137, 43205, 0, 1, 1, -13314.7, 698.424, 4.049393, 0.296706, 120, 0, 0), -- Captain Bartholomew Softbeard (Area: Southern Savage Coast)
(@CGUID+138, 43204, 0, 1, 1, -13314.2, 693.356, 4.066753, 0.7679449, 120, 0, 0), -- Orgus (Area: Southern Savage Coast)
(@CGUID+139, 43203, 0, 1, 1, -13309.32, 693.0573, 4.060645, 1.204277, 120, 0, 0), -- Gmurgl (Area: Southern Savage Coast)
(@CGUID+140, 6827, 0, 1, 1, -13306.1, 674.9484, 2.336538, 4.314143, 120, 0, 0), -- Crab (Area: Southern Savage Coast)
(@CGUID+141, 1564, 0, 1, 1, -13413.81, 669.5193, 8.331832, 1.000369, 120, 0, 0), -- Bloodsail Warlock (Area: Hardwrench Hideaway) (possible waypoints or random movement)
(@CGUID+142, 6827, 0, 1, 1, -13270.41, 598.1176, -0.515862, 5.639669, 120, 0, 0), -- Crab (Area: Hardwrench Hideaway)
(@CGUID+143, 50479, 0, 1, 1, -13271.39, 490.6477, 3.617036, 2.351795, 120, 0, 0), -- Lizard Hatchling (Area: Southern Savage Coast)
(@CGUID+144, 1713, 0, 1, 1, -13280.02, 478.2445, 3.924436, 4.746184, 120, 0, 0), -- Elder Shadowmaw Panther (Area: Southern Savage Coast)
(@CGUID+145, 49928, 0, 1, 1, -13316.69, 434.0699, 35.99097, 1.48452, 120, 0, 0), -- Crimson Moth (Area: Southern Savage Coast)
(@CGUID+146, 15475, 0, 1, 1, -13305.53, 456.8458, 4.721969, 3.061373, 120, 0, 0), -- Beetle (Area: Southern Savage Coast)
(@CGUID+147, 1713, 0, 1, 1, -13317.69, 515.2534, 4.337681, 2.686001, 120, 0, 0), -- Elder Shadowmaw Panther (Area: Southern Savage Coast)
(@CGUID+148, 49928, 0, 1, 1, -13371.28, 424.9211, 54.4158, 2.628688, 120, 0, 0), -- Crimson Moth (Area: Southern Savage Coast)
(@CGUID+149, 1713, 0, 1, 1, -13310.6, 453.6053, 4.522807, 0.3041886, 120, 0, 0), -- Elder Shadowmaw Panther (Area: Cape of Stranglethorn)
(@CGUID+150, 50487, 0, 1, 1, -13360.51, 374.4509, 26.21421, 3.172833, 120, 0, 0), -- Forest Spiderling (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+151, 50479, 0, 1, 1, -13410.61, 320.8152, 36.25667, 5.984021, 120, 0, 0), -- Lizard Hatchling (Area: Gurubashi Arena)
(@CGUID+152, 1488, 0, 1, 1, -13340.25, 124.0447, 18.34067, 2.988886, 120, 0, 0), -- Zanzil Zombie (Area: Gurubashi Arena)
(@CGUID+153, 15475, 0, 1, 1, -13361.71, 192.9176, 19.88902, 1.82524, 120, 0, 0), -- Beetle (Area: Gurubashi Arena)
(@CGUID+154, 43223, 0, 1, 1, -13360.4, 155.3571, 17.29656, 4.931683, 120, 0, 0), -- Zanzil Mindslave (Area: Gurubashi Arena)
(@CGUID+155, 50487, 0, 1, 1, -13409.28, 240.1165, 23.5663, 4.047422, 120, 0, 0), -- Forest Spiderling (Area: Gurubashi Arena) (possible waypoints or random movement)
(@CGUID+156, 50487, 0, 1, 1, -13396.42, 67.29366, 23.62234, 4.014061, 120, 0, 0), -- Forest Spiderling (Area: Gurubashi Arena)
(@CGUID+157, 1488, 0, 1, 1, -13379.7, 39.1892, 20.5145, 4.885308, 120, 0, 0), -- Zanzil Zombie (Area: Gurubashi Arena)
(@CGUID+158, 9600, 0, 1, 1, -13403.94, 108.9059, 47.50293, 3.783694, 120, 0, 0), -- Parrot (Area: Gurubashi Arena)
(@CGUID+159, 43223, 0, 1, 1, -13419.07, 121.5428, 20.18513, 2.494595, 120, 0, 0), -- Zanzil Mindslave (Area: Gurubashi Arena)
(@CGUID+160, 43223, 0, 1, 1, -13376.08, -9.66231, 21.9685, 4.684505, 120, 0, 0), -- Zanzil Mindslave (Area: Gurubashi Arena)
(@CGUID+161, 1488, 0, 1, 1, -13393.64, -17.42187, 22.47368, 3.200234, 120, 0, 0), -- Zanzil Zombie (Area: Gurubashi Arena)
(@CGUID+162, 1488, 0, 1, 1, -13362.22, -34.19279, 22.55663, 2.970081, 120, 0, 0), -- Zanzil Zombie (Area: Gurubashi Arena)
(@CGUID+163, 1488, 0, 1, 1, -13408.44, 46.44987, 33.12548, 0.2303683, 120, 0, 0), -- Zanzil Zombie (Area: Gurubashi Arena)
(@CGUID+164, 1488, 0, 1, 1, -13374.22, 5.05051, 22.00513, 2.565684, 120, 0, 0), -- Zanzil Zombie (Area: Gurubashi Arena)
(@CGUID+165, 1550, 0, 1, 1, -13382.06, -282.0084, 14.30921, 0.7983482, 120, 0, 0), -- Thrashtail Basilisk (Area: Cape of Stranglethorn)
(@CGUID+166, 32520, 0, 1, 1, -6148.39, 5539.97, -1207.787, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+167, 32520, 0, 1, 1, -5691.65, 5556.92, -1154.687, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+168, 32520, 0, 1, 1, -6014.71, 5479.63, -1208.007, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+169, 32520, 0, 1, 1, -6305.162, 5582.533, -1172.063, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+170, 1488, 0, 1, 1, -13434.38, 122.9458, 22.97429, 2.912208, 120, 0, 0), -- Zanzil Zombie (Area: Ruins of Jubuwal)
(@CGUID+171, 1488, 0, 1, 1, -13458.43, 125.7461, 23.56889, 2.334099, 120, 0, 0), -- Zanzil Zombie (Area: Ruins of Jubuwal)
(@CGUID+172, 1488, 0, 1, 1, -13462.05, 117.5142, 24.38591, 5.599281, 120, 0, 0), -- Zanzil Zombie (Area: Ruins of Jubuwal)
(@CGUID+173, 49928, 0, 1, 1, -13434.06, 115.4778, 64.35765, 0.1867109, 120, 0, 0), -- Crimson Moth (Area: Ruins of Jubuwal)
(@CGUID+174, 43223, 0, 1, 1, -13421.4, 170.2072, 22.55604, 0.04809095, 120, 0, 0), -- Zanzil Mindslave (Area: Ruins of Jubuwal)
(@CGUID+175, 43223, 0, 1, 1, -13435.52, 160.238, 22.51273, 4.897257, 120, 0, 0), -- Zanzil Mindslave (Area: Ruins of Jubuwal)
(@CGUID+176, 43223, 0, 1, 1, -13426.27, 143.4655, 19.90326, 1.711907, 120, 0, 0), -- Zanzil Mindslave (Area: Ruins of Jubuwal)
(@CGUID+177, 49722, 0, 1, 1, -13447.97, 139.5203, 23.55582, 0.2475723, 120, 0, 0), -- Tree Python (Area: Ruins of Jubuwal) (possible waypoints or random movement)
(@CGUID+178, 50479, 0, 1, 1, -13438.61, 194.4418, 26.62971, 4.086464, 120, 0, 0), -- Lizard Hatchling (Area: Gurubashi Arena)
(@CGUID+179, 1564, 0, 1, 1, -13461.19, 185.619, 45.2713, 4.593304, 120, 0, 0), -- Bloodsail Warlock (Area: Gurubashi Arena) (possible waypoints or random movement)
(@CGUID+180, 49722, 0, 1, 1, -13413.46, 369.6722, 36.78637, 1.417012, 120, 0, 0), -- Tree Python (Area: Gurubashi Arena) (possible waypoints or random movement)
(@CGUID+181, 49928, 0, 1, 1, -13431.9, 325.2878, 60.39211, 0.3964429, 120, 0, 0), -- Crimson Moth (Area: Gurubashi Arena)
(@CGUID+182, 5434, 0, 1, 1, -13308.58, 1057.428, -67.9716, 0.225304, 120, 0, 0), -- Coral Shark (Area: Southern Savage Coast) (possible waypoints or random movement)
(@CGUID+183, 1564, 0, 1, 1, -13440.66, 762.5174, 0.16875, 2.932607, 120, 0, 0), -- Bloodsail Warlock (Area: Southern Savage Coast) (possible waypoints or random movement)
(@CGUID+184, 1564, 0, 1, 1, -13458.59, 661.1548, 9.647833, 5.643295, 120, 0, 0), -- Bloodsail Warlock (Area: Southern Savage Coast) (possible waypoints or random movement)
(@CGUID+185, 1564, 0, 1, 1, -13444.55, 724.7758, 3.704235, 4.514805, 120, 0, 0), -- Bloodsail Warlock (Area: Southern Savage Coast) (possible waypoints or random movement)
(@CGUID+186, 1564, 0, 1, 1, -13462.09, 767.3784, 0.7619338, 4.491465, 120, 0, 0), -- Bloodsail Warlock (Area: Southern Savage Coast) (possible waypoints or random movement)
(@CGUID+187, 1564, 0, 1, 1, -13461.31, 668.127, 9.986059, 0.7654359, 120, 0, 0), -- Bloodsail Warlock (Area: Southern Savage Coast) (possible waypoints or random movement)
(@CGUID+188, 43364, 0, 1, 1, -13467.8, 654.604, 9.396033, 2.775074, 120, 0, 0), -- Bloodsail Hooch-Hound (Area: Hardwrench Hideaway)
(@CGUID+189, 43364, 0, 1, 1, -13472.3, 654.451, 9.978363, 1.466077, 120, 0, 0), -- Bloodsail Hooch-Hound (Area: Hardwrench Hideaway)
(@CGUID+190, 49928, 0, 1, 1, -13460.26, 297.2577, 56.01873, 2.004326, 120, 0, 0), -- Crimson Moth (Area: Cape of Stranglethorn)
(@CGUID+191, 50487, 0, 1, 1, -13465.63, 292.709, 29.21265, 6.163003, 120, 0, 0), -- Forest Spiderling (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+192, 50479, 0, 1, 1, -13467.6, 217.3116, 33.80669, 3.805037, 120, 0, 0), -- Lizard Hatchling (Area: Cape of Stranglethorn)
(@CGUID+193, 9600, 0, 1, 1, -13462.82, 55.41341, 48.33902, 0.04322021, 120, 0, 0), -- Parrot (Area: Gurubashi Arena)
(@CGUID+194, 49722, 0, 1, 1, -13470.35, -114.4419, 45.36101, 0.2463984, 120, 0, 0), -- Tree Python (Area: Ruins of Jubuwal) (possible waypoints or random movement)
(@CGUID+195, 9600, 0, 1, 1, -13504.22, -65.20506, 66.10752, 3.219559, 120, 0, 0), -- Parrot (Area: Cape of Stranglethorn)
(@CGUID+196, 49928, 0, 1, 1, -13510.63, 107.2917, 54.94632, 0.827274, 120, 0, 0), -- Crimson Moth (Area: Ruins of Jubuwal)
(@CGUID+197, 43364, 0, 1, 1, -13477.2, 176.135, 42.76993, 2.478368, 120, 0, 0), -- Bloodsail Hooch-Hound (Area: Gurubashi Arena)
(@CGUID+198, 1564, 0, 1, 1, -13495.62, 176.2363, 43.81074, 4.179819, 120, 0, 0), -- Bloodsail Warlock (Area: Gurubashi Arena) (possible waypoints or random movement)
(@CGUID+199, 1564, 0, 1, 1, -13484.45, 180.3113, 42.74989, 2.094395, 120, 0, 0), -- Bloodsail Warlock (Area: Gurubashi Arena)
(@CGUID+200, 1563, 0, 1, 1, -13491.72, 192.2253, 43.51924, 1.41001, 120, 0, 0), -- Bloodsail Swashbuckler (Area: Gurubashi Arena) (possible waypoints or random movement)
(@CGUID+201, 1564, 0, 1, 1, -13485.5, 196.6046, 42.28021, 1.400436, 120, 0, 0), -- Bloodsail Warlock (Area: Gurubashi Arena) (possible waypoints or random movement)
(@CGUID+202, 1563, 0, 1, 1, -13474.05, 190.5963, 41.58528, 4.860015, 120, 0, 0), -- Bloodsail Swashbuckler (Area: Gurubashi Arena) (possible waypoints or random movement)
(@CGUID+203, 15475, 0, 1, 1, -13514.46, 315.4026, 42.81277, 3.23083, 120, 0, 0), -- Beetle (Area: Gurubashi Arena)
(@CGUID+204, 1564, 0, 1, 1, -13485.63, 751.1611, 2.118234, 2.412014, 120, 0, 0), -- Bloodsail Warlock (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+205, 1564, 0, 1, 1, -13490.1, 671.2249, 9.626405, 5.44898, 120, 0, 0), -- Bloodsail Warlock (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+206, 6827, 0, 1, 1, -13525.07, 742.4803, 5.952319, 4.934871, 120, 0, 0), -- Crab (Area: Hardwrench Hideaway)
(@CGUID+207, 6827, 0, 1, 1, -13478.38, 784.8067, -0.3233376, 6.073729, 120, 0, 0), -- Crab (Area: Hardwrench Hideaway)
(@CGUID+208, 6827, 0, 1, 1, -13507.25, 799.0496, -1.692324, 0.6943614, 120, 0, 0), -- Crab (Area: Hardwrench Hideaway)
(@CGUID+209, 6827, 0, 1, 1, -13537.6, 662.5807, 5.425425, 0.05415055, 120, 0, 0), -- Crab (Area: Southern Savage Coast)
(@CGUID+210, 1564, 0, 1, 1, -13531.14, 720.1857, 5.155386, 2.943947, 120, 0, 0), -- Bloodsail Warlock (Area: Southern Savage Coast)
(@CGUID+211, 1564, 0, 1, 1, -13545.56, 686.8983, 1.126528, 4.159583, 120, 0, 0), -- Bloodsail Warlock (Area: Southern Savage Coast) (possible waypoints or random movement)
(@CGUID+212, 6827, 0, 1, 1, -13556.69, 688.4238, 1.69936, 6.148214, 120, 0, 0), -- Crab (Area: Southern Savage Coast)
(@CGUID+213, 1564, 0, 1, 1, -13522.95, 678.2873, 6.306708, 0.4057421, 120, 0, 0), -- Bloodsail Warlock (Area: Southern Savage Coast) (possible waypoints or random movement)
(@CGUID+214, 45681, 0, 1, 1, 2823.07, -5387.37, 164.2893, 4.24115, 120, 0, 0), -- Garginox (Area: Hardwrench Hideaway) (possible waypoints or random movement)
(@CGUID+215, 15475, 0, 1, 1, -13528.32, 312.2269, 43.83133, 0.46627, 120, 0, 0), -- Beetle (Area: Southern Savage Coast)
(@CGUID+216, 1563, 0, 1, 1, -13511.02, 181.7074, 44.38464, 6.276294, 120, 0, 0), -- Bloodsail Swashbuckler (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+217, 1564, 0, 1, 1, -13565.65, 130.6542, 41.8138, 3.649416, 120, 0, 0), -- Bloodsail Warlock (Area: Gurubashi Arena) (possible waypoints or random movement)
(@CGUID+218, 49722, 0, 1, 1, -13548.65, 135.9121, 58.27572, 6.17749, 120, 0, 0), -- Tree Python (Area: Gurubashi Arena)
(@CGUID+219, 1564, 0, 1, 1, -13545, 177.297, 42.61553, 2.673892, 120, 0, 0), -- Bloodsail Warlock (Area: Gurubashi Arena) (possible waypoints or random movement)
(@CGUID+220, 1564, 0, 1, 1, -13554.37, 178.9863, 43.5263, 5.339669, 120, 0, 0), -- Bloodsail Warlock (Area: Gurubashi Arena) (possible waypoints or random movement)
(@CGUID+221, 1564, 0, 1, 1, -13573.34, 130.2938, 41.4361, 4.696229, 120, 0, 0), -- Bloodsail Warlock (Area: Gurubashi Arena) (possible waypoints or random movement)
(@CGUID+222, 50487, 0, 1, 1, -13575.32, 78.35155, 27.61539, 5.079844, 120, 0, 0), -- Forest Spiderling (Area: Gurubashi Arena) (possible waypoints or random movement)
(@CGUID+223, 49722, 0, 1, 1, -13516.73, -66.66447, 41.65212, 0.1548762, 120, 0, 0), -- Tree Python (Area: Gurubashi Arena) (possible waypoints or random movement)
(@CGUID+224, 50487, 0, 1, 1, -13564.7, -52.40244, 38.48839, 0.1095789, 120, 0, 0), -- Forest Spiderling (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+225, 1491, 0, 1, 1, -13575.88, -254.6964, 20.8955, 2.29679, 120, 0, 0), -- Zanzil Naga (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+226, 6827, 0, 1, 1, -13572.48, -440.4369, 0.4542606, 1.849166, 120, 0, 0), -- Crab (Area: Cape of Stranglethorn)
(@CGUID+227, 32520, 0, 1, 1, -6148.39, 5539.97, -1207.787, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+228, 32520, 0, 1, 1, -6305.162, 5582.533, -1172.063, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+229, 32520, 0, 1, 1, -6014.71, 5479.63, -1208.007, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+230, 32520, 0, 1, 1, -5691.65, 5556.92, -1154.687, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+231, 1489, 0, 1, 1, -13585.44, -422.1936, 0.7695801, 3.541949, 120, 0, 0), -- Zanzil Hunter (Area: The Crystal Shore)
(@CGUID+232, 6827, 0, 1, 1, -13592.91, -423.5238, 0.7144489, 5.471186, 120, 0, 0), -- Crab (Area: The Crystal Shore)
(@CGUID+233, 1490, 0, 1, 1, -13596.05, -407.1957, 0.7194996, 2.982895, 120, 0, 0), -- Zanzil Witch Doctor (Area: The Crystal Shore) (possible waypoints or random movement)
(@CGUID+234, 1489, 0, 1, 1, -13640.93, -387.9048, 0.8438268, 4.554604, 120, 0, 0), -- Zanzil Hunter (Area: The Crystal Shore)
(@CGUID+235, 1491, 0, 1, 1, -13605.93, -382.8638, 12.13187, 4.625263, 120, 0, 0), -- Zanzil Naga (Area: The Crystal Shore) (possible waypoints or random movement)
(@CGUID+236, 1489, 0, 1, 1, -13646.21, -305.7803, 8.184404, 4.124242, 120, 0, 0), -- Zanzil Hunter (Area: The Crystal Shore)
(@CGUID+237, 1489, 0, 1, 1, -13631.57, -335.5973, 9.063794, 5.894531, 120, 0, 0), -- Zanzil Hunter (Area: The Crystal Shore)
(@CGUID+238, 1489, 0, 1, 1, -13619.08, -313.7228, 10.37304, 2.301125, 120, 0, 0), -- Zanzil Hunter (Area: The Crystal Shore)
(@CGUID+239, 1491, 0, 1, 1, -13642.72, -299.1739, 8.300073, 0.9674245, 120, 0, 0), -- Zanzil Naga (Area: The Crystal Shore) (possible waypoints or random movement)
(@CGUID+240, 1489, 0, 1, 1, -13649.3, -309.953, 8.184404, 2.601812, 120, 0, 0), -- Zanzil Hunter (Area: The Crystal Shore)
(@CGUID+241, 1489, 0, 1, 1, -13614.82, -345.153, 16.38606, 1.102227, 120, 0, 0), -- Zanzil Hunter (Area: The Crystal Shore)
(@CGUID+242, 1489, 0, 1, 1, -13656.4, -331.172, 15.13474, 5.752383, 120, 0, 0), -- Zanzil Hunter (Area: The Crystal Shore)
(@CGUID+243, 1489, 0, 1, 1, -13604.33, -278.8589, 12.96951, 3.390133, 120, 0, 0), -- Zanzil Hunter (Area: The Crystal Shore)
(@CGUID+244, 1489, 0, 1, 1, -13593.34, -330.8048, 13.96525, 5.109421, 120, 0, 0), -- Zanzil Hunter (Area: The Crystal Shore)
(@CGUID+245, 1489, 0, 1, 1, -13649.83, -275.6529, 8.300073, 2.857073, 120, 0, 0), -- Zanzil Hunter (Area: Ruins of Aboraz)
(@CGUID+246, 50487, 0, 1, 1, -13644.07, -200.5655, 25.94882, 3.704127, 120, 0, 0), -- Forest Spiderling (Area: Ruins of Aboraz) (possible waypoints or random movement)
(@CGUID+247, 15475, 0, 1, 1, -13589.65, -240.2835, 21.85347, 1.46679, 120, 0, 0), -- Beetle (Area: Ruins of Aboraz)
(@CGUID+248, 1491, 0, 1, 1, -13582.1, -233.247, 25.27311, 1.119867, 120, 0, 0), -- Zanzil Naga (Area: Ruins of Aboraz) (possible waypoints or random movement)
(@CGUID+249, 43043, 0, 1, 1, -13601.3, -91.0451, 38.76553, 1.605703, 120, 0, 0), -- Colin Swifthammer (Area: Ruins of Aboraz)
(@CGUID+250, 44083, 0, 1, 1, -13626.7, -77.9288, 35.32223, 1.48353, 120, 0, 0), -- Linzi Hewstrike (Area: Ruins of Aboraz)
(@CGUID+251, 44084, 0, 1, 1, -13627.5, -86.5521, 35.32223, 4.276057, 120, 0, 0), -- Maywiki (Area: Ruins of Aboraz)
(@CGUID+252, 44099, 0, 1, 1, -13619.7, -74.0313, 35.36393, 2.513274, 120, 0, 0), -- Dask "The Flask" Gobfizzle (Area: Ruins of Aboraz)
(@CGUID+253, 9600, 0, 1, 1, -13603.72, -106.1998, 64.02818, 4.394958, 120, 0, 0), -- Parrot (Area: Ruins of Aboraz)
(@CGUID+254, 9600, 0, 1, 1, -13624.11, -93.49928, 74.38963, 3.460862, 120, 0, 0), -- Parrot (Area: Ruins of Aboraz)
(@CGUID+255, 50479, 0, 1, 1, -13575.7, -91.0301, 41.96062, 1.639828, 120, 0, 0), -- Lizard Hatchling (Area: Ruins of Aboraz)
(@CGUID+256, 44082, 0, 1, 1, -13634.6, -71.5122, 35.32223, 0.296706, 120, 0, 0), -- Bronwyn Hewstrike (Area: Cape of Stranglethorn)
(@CGUID+257, 44106, 0, 1, 1, -13644.81, -74.21915, 35.36393, 4.108192, 120, 0, 0), -- Hambone (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+258, 44100, 0, 1, 1, -13632.76, -55.05671, 35.36393, 4.590232, 120, 0, 0), -- Goris (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+259, 49928, 0, 1, 1, -13647.92, 163.4834, 52.80767, 1.92515, 120, 0, 0), -- Crimson Moth (Area: Cape of Stranglethorn)
(@CGUID+260, 15475, 0, 1, 1, -13600.84, 284.3398, 44.44242, 4.031304, 120, 0, 0), -- Beetle (Area: Cape of Stranglethorn)
(@CGUID+261, 9600, 0, 1, 1, -13641.75, 277.1801, 90.00954, 1.331535, 120, 0, 0), -- Parrot (Area: Cape of Stranglethorn)
(@CGUID+262, 49722, 0, 1, 1, -13603, 350.8853, 46.28936, 0.2505129, 120, 0, 0), -- Tree Python (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+263, 50487, 0, 1, 1, -13613.43, 329.4962, 44.07836, 4.408647, 120, 0, 0), -- Forest Spiderling (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+264, 49928, 0, 1, 1, -13628.56, 451.1081, 62.39034, 0.2524072, 120, 0, 0), -- Crimson Moth (Area: Southern Savage Coast)
(@CGUID+265, 9600, 0, 1, 1, -13605.65, 430.6438, 47.63997, 0.1817392, 120, 0, 0), -- Parrot (Area: Southern Savage Coast)
(@CGUID+266, 6827, 0, 1, 1, -13645.4, 600.4911, 1.337978, 0.4444192, 120, 0, 0), -- Crab (Area: Hardwrench Hideaway)
(@CGUID+267, 6827, 0, 1, 1, -13661.28, 628.4986, 3.590542, 2.737387, 120, 0, 0), -- Crab (Area: Hardwrench Hideaway)
(@CGUID+268, 6827, 0, 1, 1, -13688.1, 653.2131, 1.044755, 1.463025, 120, 0, 0), -- Crab (Area: Hardwrench Hideaway)
(@CGUID+269, 9600, 0, 1, 1, -13686.75, 571.2521, 50.44864, 3.351987, 120, 0, 0), -- Parrot (Area: Hardwrench Hideaway)
(@CGUID+270, 9600, 0, 1, 1, -13644.68, 384.7575, 62.18222, 3.38754, 120, 0, 0), -- Parrot (Area: Southern Savage Coast)
(@CGUID+271, 49722, 0, 1, 1, -13665.62, 408.334, 36.73988, 4.712389, 120, 0, 0), -- Tree Python (Area: Southern Savage Coast) (possible waypoints or random movement)
(@CGUID+272, 50487, 0, 1, 1, -13685.38, 490.939, 38.50975, 5.992144, 120, 0, 0), -- Forest Spiderling (Area: Southern Savage Coast) (possible waypoints or random movement)
(@CGUID+273, 1907, 0, 1, 1, -13685.87, 503.6869, 34.53865, 2.027696, 120, 0, 0), -- Naga Explorer (Area: Southern Savage Coast) (possible waypoints or random movement)
(@CGUID+274, 9600, 0, 1, 1, -13674.33, 389.5754, 83.1381, 2.345166, 120, 0, 0), -- Parrot (Area: Southern Savage Coast)
(@CGUID+275, 50479, 0, 1, 1, -13664.92, 181.4158, 17.58692, 5.4895, 120, 0, 0), -- Lizard Hatchling (Area: Cape of Stranglethorn)
(@CGUID+276, 49722, 0, 1, 1, -13678.27, 237.5279, 28.67977, 2.1756, 120, 0, 0), -- Tree Python (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+277, 50479, 0, 1, 1, -13659.25, 125.8557, 19.81734, 4.469251, 120, 0, 0), -- Lizard Hatchling (Area: Cape of Stranglethorn)
(@CGUID+278, 1713, 0, 1, 1, -13583.31, -52.80647, 38.4533, 3.350605, 120, 0, 0), -- Elder Shadowmaw Panther (Area: Cape of Stranglethorn)
(@CGUID+279, 1489, 0, 1, 1, -13641.1, -289.214, 19.5254, 1.852611, 120, 0, 0), -- Zanzil Hunter (Area: Ruins of Aboraz)
(@CGUID+280, 6827, 0, 1, 1, -13656.29, -244.4843, 8.278214, 3.733158, 120, 0, 0), -- Crab (Area: Ruins of Aboraz)
(@CGUID+281, 41200, 0, 1, 1, -13663.8, -301.675, 15.08333, 0, 120, 0, 0), -- Generic Bunny - PRK (Area: Ruins of Aboraz)
(@CGUID+282, 1491, 0, 1, 1, -13663.2, -322.1551, 8.184404, 2.830989, 120, 0, 0), -- Zanzil Naga (Area: Ruins of Aboraz) (possible waypoints or random movement)
(@CGUID+283, 1489, 0, 1, 1, -13669.04, -284.4016, 8.271579, 5.282713, 120, 0, 0), -- Zanzil Hunter (Area: Ruins of Aboraz)
(@CGUID+284, 6827, 0, 1, 1, -13676.59, -414.726, 1.136407, 1.349655, 120, 0, 0), -- Crab (Area: Ruins of Aboraz)
(@CGUID+285, 6827, 0, 1, 1, -13680.32, -351.4448, 0.87289, 3.424978, 120, 0, 0), -- Crab (Area: The Crystal Shore)
(@CGUID+286, 1491, 0, 1, 1, -13699.8, -391.1355, 2.433247, 3.920094, 120, 0, 0), -- Zanzil Naga (Area: The Crystal Shore) (possible waypoints or random movement)
(@CGUID+287, 1490, 0, 1, 1, -13682.87, -344.9661, 1.726663, 4.090072, 120, 0, 0), -- Zanzil Witch Doctor (Area: The Crystal Shore) (possible waypoints or random movement)
(@CGUID+288, 1489, 0, 1, 1, -13685.68, -261.5269, 7.335847, 0.3118621, 120, 0, 0), -- Zanzil Hunter (Area: Ruins of Aboraz)
(@CGUID+289, 1558, 0, 1, 1, -13718.68, -201.9102, 21.91954, 5.141929, 120, 0, 0), -- Silverback Patriarch (Area: Ruins of Aboraz)
(@CGUID+290, 1557, 0, 1, 1, -13682.54, 149.4931, 20.49172, 3.885578, 120, 0, 0), -- Elder Mistvale Gorilla (Area: Explorers' League Digsite)
(@CGUID+291, 49928, 0, 1, 1, -13716.04, 164.5327, 41.50937, 1.502274, 120, 0, 0), -- Crimson Moth (Area: Cape of Stranglethorn)
(@CGUID+292, 1557, 0, 1, 1, -13714.92, 176.3791, 18.66429, 4.639992, 120, 0, 0), -- Elder Mistvale Gorilla (Area: Cape of Stranglethorn)
(@CGUID+293, 1557, 0, 1, 1, -13725.88, 250.6674, 28.87038, 3.645739, 120, 0, 0), -- Elder Mistvale Gorilla (Area: Cape of Stranglethorn)
(@CGUID+294, 50487, 0, 1, 1, -13705.5, 333.2911, 48.58393, 5.08419, 120, 0, 0), -- Forest Spiderling (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+295, 49928, 0, 1, 1, -13699.37, 503.2928, 63.34065, 0.6881142, 120, 0, 0), -- Crimson Moth (Area: Southern Savage Coast)
(@CGUID+296, 50487, 0, 1, 1, -13709.87, 595.3425, 15.91121, 4.671396, 120, 0, 0), -- Forest Spiderling (Area: Southern Savage Coast) (possible waypoints or random movement)
(@CGUID+297, 1907, 0, 1, 1, -13702.48, 569.4443, 18.17683, 5.019511, 120, 0, 0), -- Naga Explorer (Area: Southern Savage Coast) (possible waypoints or random movement)
(@CGUID+298, 1907, 0, 1, 1, -13690.4, 618.8262, 10.34949, 4.037908, 120, 0, 0), -- Naga Explorer (Area: Southern Savage Coast) (possible waypoints or random movement)
(@CGUID+299, 1907, 0, 1, 1, -13723.08, 536.2891, 38.73175, 4.22864, 120, 0, 0), -- Naga Explorer (Area: Southern Savage Coast) (possible waypoints or random movement)
(@CGUID+300, 6827, 0, 1, 1, -13711.35, 642.5073, 6.590907, 4.958788, 120, 0, 0), -- Crab (Area: Southern Savage Coast)
(@CGUID+301, 1907, 0, 1, 1, -13707.59, 650.9493, 4.085759, 0.919555, 120, 0, 0), -- Naga Explorer (Area: Southern Savage Coast) (possible waypoints or random movement)
(@CGUID+302, 6827, 0, 1, 1, -13723.72, 668.4558, 0.8584785, 5.858819, 120, 0, 0), -- Crab (Area: Southern Savage Coast)
(@CGUID+303, 6827, 0, 1, 1, -13797.47, 657.6209, 14.89441, 3.655896, 120, 0, 0), -- Crab (Area: Southern Savage Coast)
(@CGUID+304, 1907, 0, 1, 1, -13781.39, 584.2049, 46.1172, 0.8337698, 120, 0, 0), -- Naga Explorer (Area: Southern Savage Coast) (possible waypoints or random movement)
(@CGUID+305, 1907, 0, 1, 1, -13786.91, 647.548, 14.54261, 1.930253, 120, 0, 0), -- Naga Explorer (Area: Southern Savage Coast) (possible waypoints or random movement)
(@CGUID+306, 1907, 0, 1, 1, -13743.99, 622.8596, 15.35855, 1.118183, 120, 0, 0), -- Naga Explorer (Area: Southern Savage Coast) (possible waypoints or random movement)
(@CGUID+307, 6827, 0, 1, 1, -13822.37, 693.9354, 0.2567279, 2.038914, 120, 0, 0), -- Crab (Area: Southern Savage Coast)
(@CGUID+308, 6827, 0, 1, 1, -13772.93, 676.6509, 5.600339, 0.002512557, 120, 0, 0), -- Crab (Area: Southern Savage Coast)
(@CGUID+309, 1907, 0, 1, 1, -13821.78, 688.2487, 2.537246, 2.257162, 120, 0, 0), -- Naga Explorer (Area: Southern Savage Coast) (possible waypoints or random movement)
(@CGUID+310, 32520, 0, 1, 1, -6305.162, 5582.533, -1172.063, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Southern Savage Coast)
(@CGUID+311, 32520, 0, 1, 1, -6148.39, 5539.97, -1207.787, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Southern Savage Coast)
(@CGUID+312, 32520, 0, 1, 1, -6014.71, 5479.63, -1208.007, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Southern Savage Coast)
(@CGUID+313, 32520, 0, 1, 1, -5691.65, 5556.92, -1154.687, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Southern Savage Coast)
(@CGUID+314, 50487, 0, 1, 1, -13775.44, 515.4248, 62.75632, 6.072774, 120, 0, 0), -- Forest Spiderling (Area: Southern Savage Coast) (possible waypoints or random movement)
(@CGUID+315, 1907, 0, 1, 1, -13779.64, 497.0012, 69.56641, 2.681823, 120, 0, 0), -- Naga Explorer (Area: Southern Savage Coast) (possible waypoints or random movement)
(@CGUID+316, 1907, 0, 1, 1, -13736.71, 496.1463, 57.68426, 1.69612, 120, 0, 0), -- Naga Explorer (Area: Southern Savage Coast) (possible waypoints or random movement)
(@CGUID+317, 49722, 0, 1, 1, -13827.77, 560.4193, 46.58662, 3.784944, 120, 0, 0), -- Tree Python (Area: Southern Savage Coast) (possible waypoints or random movement)
(@CGUID+318, 49722, 0, 1, 1, -13809.53, 539.0852, 47.5416, 3.540589, 120, 0, 0), -- Tree Python (Area: Southern Savage Coast) (possible waypoints or random movement)
(@CGUID+319, 1907, 0, 1, 1, -13751.6, 554.2172, 47.50356, 2.011441, 120, 0, 0), -- Naga Explorer (Area: Southern Savage Coast) (possible waypoints or random movement)
(@CGUID+320, 1907, 0, 1, 1, -13820.94, 548.4301, 46.67016, 1.444791, 120, 0, 0), -- Naga Explorer (Area: Southern Savage Coast) (possible waypoints or random movement)
(@CGUID+321, 15475, 0, 1, 1, -13804.46, 444.0915, 91.67652, 0.07033389, 120, 0, 0), -- Beetle (Area: Southern Savage Coast)
(@CGUID+322, 1907, 0, 1, 1, -13787.55, 437.6588, 92.32978, 5.598324, 120, 0, 0), -- Naga Explorer (Area: Southern Savage Coast) (possible waypoints or random movement)
(@CGUID+323, 9600, 0, 1, 1, -13814.45, 409.0988, 118.7221, 5.089261, 120, 0, 0), -- Parrot (Area: Southern Savage Coast)
(@CGUID+324, 49928, 0, 1, 1, -13778.55, 222.8183, 56.6353, 1.64255, 120, 0, 0), -- Crimson Moth (Area: Cape of Stranglethorn)
(@CGUID+325, 1557, 0, 1, 1, -13751.33, 220.1806, 20.24816, 4.732131, 120, 0, 0), -- Elder Mistvale Gorilla (Area: Cape of Stranglethorn)
(@CGUID+326, 49722, 0, 1, 1, -13753.21, 123.9548, 22.70432, 3.723946, 120, 0, 0), -- Tree Python (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+327, 15475, 0, 1, 1, -13774.67, 208.0742, 21.28601, 3.799552, 120, 0, 0), -- Beetle (Area: Cape of Stranglethorn)
(@CGUID+328, 15475, 0, 1, 1, -13815.82, 93.88322, 25.5604, 4.104866, 120, 0, 0), -- Beetle (Area: Cape of Stranglethorn)
(@CGUID+329, 1557, 0, 1, 1, -13776.78, 123.4395, 21.98596, 5.342175, 120, 0, 0), -- Elder Mistvale Gorilla (Area: Cape of Stranglethorn)
(@CGUID+330, 9600, 0, 1, 1, -13795.81, 108.1318, 56.79708, 2.399327, 120, 0, 0), -- Parrot (Area: Cape of Stranglethorn)
(@CGUID+331, 1449, 0, 1, 1, -13738.46, -29.74349, 44.63955, 1.815142, 120, 0, 0), -- Witch Doctor Unbagwa (Area: Cape of Stranglethorn)
(@CGUID+332, 50479, 0, 1, 1, -13809.34, 3.948572, 27.85722, 0.009765315, 120, 0, 0), -- Lizard Hatchling (Area: Cape of Stranglethorn)
(@CGUID+333, 15475, 0, 1, 1, -13800.48, -177.2698, 15.97146, 0.1810895, 120, 0, 0), -- Beetle (Area: Cape of Stranglethorn)
(@CGUID+334, 15475, 0, 1, 1, -13784.52, -188.566, 16.30892, 6.104555, 120, 0, 0), -- Beetle (Area: Cape of Stranglethorn)
(@CGUID+335, 50487, 0, 1, 1, -13801.44, -145.6964, 18.89592, 6.181377, 120, 0, 0), -- Forest Spiderling (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+336, 1558, 0, 1, 1, -13745.48, -185.4486, 34.7619, 1.089683, 120, 0, 0), -- Silverback Patriarch (Area: Cape of Stranglethorn)
(@CGUID+337, 1491, 0, 1, 1, -13751.34, -278.673, 0.4138112, 0.1847477, 120, 0, 0), -- Zanzil Naga (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+338, 6827, 0, 1, 1, -13736.51, -274.2876, 0.6672292, 0.2526487, 120, 0, 0), -- Crab (Area: Cape of Stranglethorn)
(@CGUID+339, 2535, 0, 1, 1, -13810.89, -242.6844, 0.7701635, 5.752975, 120, 0, 0), -- Maury "Club Foot" Wilkins (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+340, 1491, 0, 1, 1, -13742.05, -374.287, 5.584406, 2.345062, 120, 0, 0), -- Zanzil Naga (Area: Ruins of Aboraz) (possible waypoints or random movement)
(@CGUID+341, 6827, 0, 1, 1, -13740.34, -356.5678, 1.261433, 4.606007, 120, 0, 0), -- Crab (Area: Ruins of Aboraz)
(@CGUID+342, 43596, 0, 1, 1, -13909, -359.536, 31.33173, 3.630285, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+343, 43596, 0, 1, 1, -13915.1, -352.036, 37.16523, 3.961897, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+344, 43596, 0, 1, 1, -13917.1, -354.03, 36.64023, 3.839724, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+345, 43596, 0, 1, 1, -13921, -355.889, 40.19423, 3.193953, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+346, 43596, 0, 1, 1, -13919.4, -346.417, 32.42733, 0.6981317, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+347, 43596, 0, 1, 1, -13922.7, -351.745, 33.10163, 4.572762, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+348, 43596, 0, 1, 1, -13923.2, -352.642, 33.12623, 4.747295, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+349, 43596, 0, 1, 1, -13930.9, -377.535, 38.05483, 1.972222, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+350, 43596, 0, 1, 1, -13924.1, -355.635, 39.49293, 4.520403, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+351, 43596, 0, 1, 1, -13931.8, -376.939, 38.19763, 0.9948376, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+352, 43596, 0, 1, 1, -13918.3, -336.559, 27.93043, 4.729842, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+353, 43596, 0, 1, 1, -13925.5, -356.33, 39.43233, 5.201081, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+354, 43596, 0, 1, 1, -13932.5, -375.281, 37.68913, 5.462881, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+355, 43596, 0, 1, 1, -13919.5, -337.363, 27.86253, 5.550147, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+356, 43596, 0, 1, 1, -13926.9, -358.031, 39.33403, 0.4363323, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+357, 43596, 0, 1, 1, -13929.7, -362.582, 37.58533, 0.8901179, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+358, 43596, 0, 1, 1, -13928.6, -353.988, 33.32153, 5.986479, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+359, 43596, 0, 1, 1, -13928.2, -355.344, 37.69553, 5.951573, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+360, 43596, 0, 1, 1, -13931.2, -350.943, 34.34253, 2.513274, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+361, 43596, 0, 1, 1, -13931.9, -353.42, 38.74823, 2.984513, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+362, 43596, 0, 1, 1, -13937.28, -344.4358, 20.55093, 4.276057, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+363, 43596, 0, 1, 1, -13938.9, -344.587, 20.87533, 5.497787, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+364, 43596, 0, 1, 1, -13939.8, -345.464, 21.13933, 6.126106, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+365, 43596, 0, 1, 1, -13942.9, -349.875, 17.93513, 5.235988, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+366, 43596, 0, 1, 1, -13943.7, -351.726, 17.80713, 0.541052, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+367, 6827, 0, 1, 1, -13823.81, -241.1697, 0.3268042, 6.11126, 120, 0, 0), -- Crab (Area: Ruins of Aboraz)
(@CGUID+368, 1558, 0, 1, 1, -13818.23, -115.4312, 17.03753, 2.834047, 120, 0, 0), -- Silverback Patriarch (Area: Ruins of Aboraz)
(@CGUID+369, 1907, 0, 1, 1, -13818.35, 442.326, 90.77467, 5.502962, 120, 0, 0), -- Naga Explorer (Area: Nek'mani Wellspring) (possible waypoints or random movement)
(@CGUID+370, 5434, 0, 1, 1, -13689.19, 945.3102, -81.7506, 0.6085935, 120, 0, 0), -- Coral Shark (Area: Southern Savage Coast) (possible waypoints or random movement)
(@CGUID+371, 1493, 0, 1, 1, -14236.26, 736.5851, 1.641953, 4.018259, 120, 0, 0), -- Mok'rash (Area: Southern Savage Coast)
(@CGUID+372, 6827, 0, 1, 1, -13904.18, 678.3066, 9.834699, 0.1733958, 120, 0, 0), -- Crab (Area: Southern Savage Coast)
(@CGUID+373, 6827, 0, 1, 1, -13880.45, 692.7104, 3.214812, 5.462556, 120, 0, 0), -- Crab (Area: Southern Savage Coast)
(@CGUID+374, 1907, 0, 1, 1, -13879.07, 685.0602, 7.98386, 6.087249, 120, 0, 0), -- Naga Explorer (Area: Southern Savage Coast) (possible waypoints or random movement)
(@CGUID+375, 6827, 0, 1, 1, -13950.07, 649.3655, 2.771731, 3.382306, 120, 0, 0), -- Crab (Area: Southern Savage Coast)
(@CGUID+376, 1907, 0, 1, 1, -13924.48, 652.451, 8.233253, 4.665457, 120, 0, 0), -- Naga Explorer (Area: Southern Savage Coast) (possible waypoints or random movement)
(@CGUID+377, 6827, 0, 1, 1, -13958.18, 651.7027, 1.372019, 2.238521, 120, 0, 0), -- Crab (Area: Southern Savage Coast)
(@CGUID+378, 1907, 0, 1, 1, -13879.41, 619.873, 24.92825, 3.903085, 120, 0, 0), -- Naga Explorer (Area: Southern Savage Coast) (possible waypoints or random movement)
(@CGUID+379, 1907, 0, 1, 1, -13850.15, 587.1965, 47.09817, 6.246093, 120, 0, 0), -- Naga Explorer (Area: Southern Savage Coast) (possible waypoints or random movement)
(@CGUID+380, 49722, 0, 1, 1, -13842.19, 635.8505, 20.48549, 2.840222, 120, 0, 0), -- Tree Python (Area: Southern Savage Coast) (possible waypoints or random movement)
(@CGUID+381, 1907, 0, 1, 1, -13853.01, 645.4163, 12.82679, 1.715944, 120, 0, 0), -- Naga Explorer (Area: Southern Savage Coast) (possible waypoints or random movement)
(@CGUID+382, 1907, 0, 1, 1, -13880.18, 501.5575, 96.06639, 4.208477, 120, 0, 0), -- Naga Explorer (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+383, 1907, 0, 1, 1, -13849.17, 489.7715, 90.69984, 1.008449, 120, 0, 0), -- Naga Explorer (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+384, 1907, 0, 1, 1, -13907.27, 424.0601, 99.71001, 1.274439, 120, 0, 0), -- Naga Explorer (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+385, 1907, 0, 1, 1, -13914, 437.8029, 100.8523, 4.88115, 120, 0, 0), -- Naga Explorer (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+386, 15475, 0, 1, 1, -13832.99, 431.8919, 92.93942, 5.42038, 120, 0, 0), -- Beetle (Area: Cape of Stranglethorn)
(@CGUID+387, 1907, 0, 1, 1, -13842.17, 432.1875, 90.23026, 2.164208, 120, 0, 0), -- Naga Explorer (Area: Cape of Stranglethorn)
(@CGUID+388, 1907, 0, 1, 1, -13865.33, 432.2573, 92.27216, 2.083424, 120, 0, 0), -- Naga Explorer (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+389, 1907, 0, 1, 1, -13844.76, 450.9806, 91.31736, 4.497725, 120, 0, 0), -- Naga Explorer (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+390, 50487, 0, 1, 1, -13829.2, 209.953, 19.32444, 4.340588, 120, 0, 0), -- Forest Spiderling (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+391, 15475, 0, 1, 1, -13870.36, 129.8211, 14.85186, 6.15933, 120, 0, 0), -- Beetle (Area: Cape of Stranglethorn)
(@CGUID+392, 1557, 0, 1, 1, -13827.53, 63.59375, 26.1686, 4.737774, 120, 0, 0), -- Elder Mistvale Gorilla (Area: Cape of Stranglethorn)
(@CGUID+393, 1557, 0, 1, 1, -13864.03, 107.5627, 15.61405, 0.2970642, 120, 0, 0), -- Elder Mistvale Gorilla (Area: Cape of Stranglethorn)
(@CGUID+394, 1558, 0, 1, 1, -13830.01, -34.07888, 65.5036, 4.253329, 120, 0, 0), -- Silverback Patriarch (Area: Cape of Stranglethorn)
(@CGUID+395, 49722, 0, 1, 1, -13849.83, 10.50262, 18.8875, 5.879832, 120, 0, 0), -- Tree Python (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+396, 1557, 0, 1, 1, -13839.58, 26.31791, 23.09087, 1.570796, 120, 0, 0), -- Elder Mistvale Gorilla (Area: Cape of Stranglethorn)
(@CGUID+397, 1558, 0, 1, 1, -13861.98, -18.75, 50.22608, 4.712389, 120, 0, 0), -- Silverback Patriarch (Area: Spirit Den)
(@CGUID+398, 1558, 0, 1, 1, -13843.37, -34.72439, 53.39328, 0.8077267, 120, 0, 0), -- Silverback Patriarch (Area: Spirit Den)
(@CGUID+399, 1558, 0, 1, 1, -13858.06, -43.56951, 40.78098, 3.730522, 120, 0, 0), -- Silverback Patriarch (Area: Spirit Den)
(@CGUID+400, 1558, 0, 1, 1, -13853.34, -83.43011, 17.84823, 2.682312, 120, 0, 0), -- Silverback Patriarch (Area: Spirit Den)
(@CGUID+401, 1489, 0, 1, 1, -13792.1, -240.0546, 1.081017, 0.1846228, 120, 0, 0), -- Zanzil Hunter (Area: Cape of Stranglethorn)
(@CGUID+402, 43596, 0, 1, 1, -13978.2, -276.755, 72.09614, 3.822271, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+403, 43596, 0, 1, 1, -13981.2, -279.465, 72.10354, 3.246312, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+404, 43596, 0, 1, 1, -13981.9, -277.651, 71.11484, 4.677482, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+405, 43596, 0, 1, 1, -13983.6, -279.073, 71.11484, 1.570796, 120, 0, 0); -- Venture Co. Oil Worker (Area: The Crystal Shore)

DELETE FROM `npc_vendor` WHERE `entry` IN (44083, 44083, 44083, 44083, 44083, 44083, 44083, 44083, 44083, 44083, 44083, 44083, 44083, 44083);
INSERT INTO `npc_vendor` (`entry`, `item`, `slot`, `maxcount`, `ExtendedCost`, `Type`) VALUES
-- 44083 (Linzi Hewstrike)
(44083, 2463, 1, 0, 0, 1), -- Studded Doublet
(44083, 2464, 2, 0, 0, 1), -- Studded Belt
(44083, 2465, 3, 0, 0, 1), -- Studded Pants
(44083, 2467, 4, 0, 0, 1), -- Studded Boots
(44083, 2468, 5, 0, 0, 1), -- Studded Bracers
(44083, 2469, 6, 0, 0, 1), -- Studded Gloves
(44083, 3890, 7, 0, 0, 1), -- Studded Hat
(44083, 2470, 8, 0, 0, 1), -- Reinforced Leather Vest
(44083, 2471, 9, 0, 0, 1), -- Reinforced Leather Belt
(44083, 2472, 10, 0, 0, 1), -- Reinforced Leather Pants
(44083, 2473, 11, 0, 0, 1), -- Reinforced Leather Boots
(44083, 2474, 12, 0, 0, 1), -- Reinforced Leather Bracers
(44083, 2475, 13, 0, 0, 1), -- Reinforced Leather Gloves
(44083, 3893, 14, 0, 0, 1); -- Reinforced Leather Cap

DELETE FROM `npc_text` WHERE `ID` IN (16547, 16548);
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `lang0`, `prob0`, `em0_0`, `em0_1`, `em0_2`, `em0_3`, `em0_4`, `em0_5`, `text1_0`, `text1_1`, `lang1`, `prob1`, `em1_0`, `em1_1`, `em1_2`, `em1_3`, `em1_4`, `em1_5`, `text2_0`, `text2_1`, `lang2`, `prob2`, `em2_0`, `em2_1`, `em2_2`, `em2_3`, `em2_4`, `em2_5`, `text3_0`, `text3_1`, `lang3`, `prob3`, `em3_0`, `em3_1`, `em3_2`, `em3_3`, `em3_4`, `em3_5`, `text4_0`, `text4_1`, `lang4`, `prob4`, `em4_0`, `em4_1`, `em4_2`, `em4_3`, `em4_4`, `em4_5`, `text5_0`, `text5_1`, `lang5`, `prob5`, `em5_0`, `em5_1`, `em5_2`, `em5_3`, `em5_4`, `em5_5`, `text6_0`, `text6_1`, `lang6`, `prob6`, `em6_0`, `em6_1`, `em6_2`, `em6_3`, `em6_4`, `em6_5`, `text7_0`, `text7_1`, `lang7`, `prob7`, `em7_0`, `em7_1`, `em7_2`, `em7_3`, `em7_4`, `em7_5`, `WDBVerified`) VALUES
(16547, '', 'Hello, $c.  Care to purchase something?', 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- 16547
(16548, '', 'The Gurubashi are dead, and Hakkar with them.  Most of my fellow Zandalar have returned to their homeland.$b$bIt falls on me, Chabal, and the Darkspears of Bambala to watch over Zul''Gurub now.', 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 15595); -- 16548

UPDATE `npc_text` SET `WDBVerified`=15595 WHERE `ID`=7074; -- 7074

DELETE FROM `gossip_menu_option` WHERE (`menu_id`=11801 AND `id`=0);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `box_coded`, `box_money`, `box_text`) VALUES
(11801, 0, 1, 'I would like to buy from you.', 0, 0, ''); -- Linzi Hewstrike

DELETE FROM `creature_equip_template` WHERE `entry` IN (14508, 44190, 14492, 674, 674, 674, 674, 43099, 43097, 44194, 43096, 1563, 44195, 43219, 43219, 43219, 1564, 1564, 1564, 1564, 1564, 1564, 1564, 43364, 43364, 43364, 1564, 1564, 1563, 1564, 1563, 1564, 1564, 1564, 1564, 1564, 45681, 1563, 1564, 1564, 1564, 1564, 1491, 1489, 1490, 1489, 1491, 1489, 1489, 1489, 1491, 1489, 1489, 1489, 1489, 1489, 1489, 1491, 44084, 44099, 44082, 44100, 1907, 1489, 1491, 1489, 1491, 1490, 1489, 1907, 1907, 1907, 1907, 1907, 1907, 1907, 1907, 1907, 1907, 1907, 1907, 1907, 1449, 1491, 1491, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 1907, 1493, 1907, 1907, 1907, 1907, 1907, 1907, 1907, 1907, 1907, 1907, 1907, 1907, 1489, 43596, 43596, 43596, 43596);
INSERT INTO `creature_equip_template` (`entry`, `itemEntry1`, `itemEntry2`, `itemEntry3`) VALUES
(14508, 2179, 0, 0), -- Short John Mithril
(44190, 2703, 0, 0), -- Innkeeper Draxle
(14492, 1910, 13609, 0), -- Verifonix
(674, 1910, 0, 0), -- Venture Co. Strip Miner
(43099, 0, 0, 47907), -- Stone Guard Towhide
(43097, 52358, 2200, 0), -- Mixmaster Jasper
(44194, 31824, 0, 0), -- Gruzz Thinxlotz
(43096, 11424, 0, 0), -- Flem Gizzix
(1563, 1897, 0, 0), -- Bloodsail Swashbuckler
(44195, 1903, 0, 0), -- Smity Hammerhead
(43219, 3361, 0, 50150), -- Hardwrench Guard
(1564, 1907, 0, 0), -- Bloodsail Warlock
(43364, 12791, 0, 0), -- Bloodsail Hooch-Hound
(45681, 61298, 0, 0), -- Garginox
(1491, 1905, 0, 0), -- Zanzil Naga
(1489, 2023, 0, 5870), -- Zanzil Hunter
(1490, 2810, 0, 0), -- Zanzil Witch Doctor
(44084, 14586, 0, 0), -- Maywiki
(44099, 52358, 3697, 0), -- Dask "The Flask" Gobfizzle
(44082, 17123, 0, 0), -- Bronwyn Hewstrike
(44100, 57027, 0, 0), -- Goris
(1907, 5745, 0, 0), -- Naga Explorer
(1449, 1908, 0, 0), -- Witch Doctor Unbagwa
(43596, 31824, 0, 0), -- Venture Co. Oil Worker
(1493, 5491, 0, 0); -- Mok'rash

DELETE FROM `gameobject_template` WHERE `entry` IN (204909, 208420, 204578, 204454, 204450, 204433, 204422, 204456, 204455);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `data24`, `data25`, `data26`, `data27`, `data28`, `data29`, `data30`, `data31`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `unkInt32`, `WDBVerified`) VALUES
(204909, 8, 192, 'Campfire', '', '', '', 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.76, 0, 0, 0, 0, 0, 0, 0, 15595), -- -Unknown-
(208420, 2, 10313, 'Treasure Chest', '', '', '', 0, 16366, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.7, 0, 0, 0, 0, 0, 0, 0, 15595), -- -Unknown-
(204578, 2, 32, 'Barrel of Doublerum', '', 'Tapping', '', 43, 15458, 0, 11762, 0, 0, 37086, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- -Unknown-
(204454, 2, 9095, 'Grog Barrel', '', '', '', 0, 0, 0, 11750, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- -Unknown-
(204450, 2, 222, 'Captain Stillwater''s Charts', '', '', '', 0, 15456, 0, 11756, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- -Unknown-
(204433, 3, 153, 'Bloodsail Cannonball', '', 'Grabbing', '', 1691, 30934, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 37379, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 59151, 0, 0, 0, 0, 0, 0, 15595), -- -Unknown-
(204422, 22, 9742, 'Swabbie''s Mop', '', '', '', 81358, 1, 0, 0, 0, 10132, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- -Unknown-
(204456, 2, 9651, 'Cannonball Crate', '', '', '', 0, 0, 0, 11753, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 15595), -- -Unknown-
(204455, 2, 9095, 'Gunpowder Barrel', '', '', '', 0, 0, 0, 11751, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 15595); -- -Unknown-

UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=1984; -- Campfire
UPDATE `gameobject_template` SET `data1`=15432, `WDBVerified`=15595 WHERE `entry`=2083; -- Bloodsail Correspondence
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=178204; -- Warsong Axe Shipment
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=56903; -- Good Food
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=59518; -- Nautical Needs
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=56905; -- Swift Flights
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=2574; -- Anvil
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=56897; -- Forge
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=21678; -- Anvil
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=2575; -- Forge
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=91692; -- Boomstick Imports East
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=59847; -- Cuts-N-Bruises Incorporated
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=59845; -- The Old Port Authority
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=59855; -- Stove
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=180391; -- Heart of Hakkar Spell Emitter
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=144126; -- Mailbox
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=56911; -- Stranglethorn Trust Bank
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=59853; -- Stove
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=59860; -- Stove
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=59856; -- Stove
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=59863; -- Stove
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=60440; -- Wooden Chair
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=59854; -- Stove
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=59862; -- Stove
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=60438; -- Wooden Chair
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=59851; -- A Tailor to Cities
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=60439; -- Wooden Chair
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=61918; -- Deep South Tannery
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=175732; -- The Sentinels and the Long Vigil
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=59864; -- Stove
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=56901; -- Tan-Your-Hide Leatherworks
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=59852; -- The Happy Bobber
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=59865; -- Stove
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=59857; -- Stove
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=60395; -- Wooden Chair
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=59846; -- Kalimdor Airlines
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=74091; -- The Salty Sailor Tavern
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=148889; -- Wooden Chair
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=59859; -- Stove
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=148892; -- Wooden Chair
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=148891; -- Wooden Chair
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=56910; -- The Salty Sailor Tavern
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=148900; -- Wooden Chair
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=59858; -- Stove
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=59850; -- Boucher's Cauldron
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=59848; -- Southern Skies Platform
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=59517; -- All Things Flora
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=144127; -- Mailbox
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=148904; -- Wooden Chair
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=148902; -- Wooden Chair
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=148905; -- Wooden Chair
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=148906; -- Wooden Chair
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=148913; -- Wooden Chair
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=148893; -- Wooden Chair
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=148899; -- Wooden Chair
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=148912; -- Wooden Chair
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=148895; -- Wooden Chair
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=148911; -- Wooden Chair
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=148910; -- Wooden Chair
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=148914; -- Wooden Chair
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=148909; -- Wooden Chair
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=148915; -- Wooden Chair
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=148898; -- Wooden Chair
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=148901; -- Wooden Chair
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=148886; -- Wooden Chair
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=59861; -- Stove
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=148884; -- Wooden Chair
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=148888; -- Wooden Chair
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=148885; -- Wooden Chair
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=148903; -- Wooden Chair
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=148894; -- Wooden Chair
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=148887; -- Wooden Chair
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=111149; -- Campfire

SET @OGUID := 9266;

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+320;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
-- (@OGUID+0, 175080, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 120, 255, 1), -- 0 (Area: The Crystal Shore) - !!! transport !!!
-- (@OGUID+0, 176495, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 120, 255, 1), -- 0 (Area: The Crystal Shore) - !!! transport !!!
(@OGUID+0, 143979, 0, 1, 1, -11600.36, -698.984, 30.97299, 0.01745246, 0, 0, 0.008726574, 0.9999619, 120, 255, 1), -- Cage Door (Area: The Crystal Shore)
(@OGUID+1, 204828, 0, 1, 1, -11571.15, -568.7274, 33.68356, 3.211419, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: The Crystal Shore)
(@OGUID+2, 180497, 0, 1, 1, -11505.66, -1609.016, 47.6743, 1.579522, 0, 0, 0.7101853, 0.7040148, 120, 255, 0), -- Forcefield (Area: The Crystal Shore)
(@OGUID+3, 177049, 0, 1, 1, -11226.9, -1734.259, 4.382416, 1.596976, 0, 0, 0.01308961, 0.9999143, 120, 255, 1), -- Doodad_PortcullisActive07 (Area: The Crystal Shore)
(@OGUID+4, 177048, 0, 1, 1, -11226.34, -1755.594, 4.382416, 1.596976, 0, 0, 0.01308961, 0.9999143, 120, 255, 1), -- Doodad_PortcullisActive06 (Area: The Crystal Shore)
(@OGUID+5, 177047, 0, 1, 1, -11206.93, -1733.736, 4.382416, 1.596976, 0, 0, 0.01308961, 0.9999143, 120, 255, 1), -- Doodad_PortcullisActive05 (Area: The Crystal Shore)
(@OGUID+6, 176901, 0, 1, 1, -11206.37, -1755.071, 4.382416, 1.596976, 0, 0, 0.01308961, 0.9999143, 120, 255, 1), -- Doodad_PortcullisActive02 (Area: The Crystal Shore)
(@OGUID+7, 177253, 0, 1, 1, -11097.23, -1506.311, 27.99158, 1.596976, 0, 0, 0.01308961, 0.9999143, 120, 255, 1), -- Doodad_WroughtIronDoor09 (Area: The Crystal Shore)
(@OGUID+8, 177252, 0, 1, 1, -11096.34, -1540.468, 27.99158, 1.596976, 0, 0, 0.01308961, 0.9999143, 120, 255, 1), -- Doodad_WroughtIronDoor08 (Area: The Crystal Shore)
(@OGUID+9, 177254, 0, 1, 1, -11065.52, -1505.48, 27.99158, 1.596976, 0, 0, 0.01308961, 0.9999143, 120, 255, 1), -- Doodad_opendoor_01 (Area: The Crystal Shore)
(@OGUID+10, 177251, 0, 1, 1, -11094.74, -1601.537, 27.99158, 1.596976, 0, 0, 0.01308961, 0.9999143, 120, 255, 1), -- Doodad_WroughtIronDoor07 (Area: The Crystal Shore)
(@OGUID+11, 177250, 0, 1, 1, -11064.62, -1539.476, 27.97834, 1.596976, 0, 0, 0.01308961, 0.9999143, 120, 255, 1), -- Doodad_WroughtIronDoor06 (Area: The Crystal Shore)
(@OGUID+12, 177246, 0, 1, 1, -11093.86, -1635.39, 27.97834, 1.596976, 0, 0, 0.01308961, 0.9999143, 120, 255, 1), -- Doodad_WroughtIronDoor02 (Area: The Crystal Shore)
(@OGUID+13, 177255, 0, 1, 1, -11033.78, -1504.649, 27.99158, 1.596976, 0, 0, 0.01308961, 0.9999143, 120, 255, 1), -- Doodad_opendoor_03 (Area: The Crystal Shore)
(@OGUID+14, 177249, 0, 1, 1, -11063.01, -1600.994, 27.97834, 1.596976, 0, 0, 0.01308961, 0.9999143, 120, 255, 1), -- Doodad_WroughtIronDoor05 (Area: The Crystal Shore)
(@OGUID+15, 177256, 0, 1, 1, -11032.87, -1539.138, 29.45629, 1.596976, 0, 0, 0.01308961, 0.9999143, 120, 255, 1), -- Doodad_opendoor_02 (Area: The Crystal Shore)
(@OGUID+16, 177245, 0, 1, 1, -11062.1, -1635.611, 27.99158, 1.596976, 0, 0, 0.01308961, 0.9999143, 120, 255, 1), -- Doodad_WroughtIronDoor01 (Area: The Crystal Shore)
(@OGUID+17, 177248, 0, 1, 1, -11031.28, -1600.163, 27.97834, 1.596976, 0, 0, 0.01308961, 0.9999143, 120, 255, 1), -- Doodad_WroughtIronDoor04 (Area: The Crystal Shore)
(@OGUID+18, 177247, 0, 1, 1, -11030.4, -1633.728, 27.97834, 1.596976, 0, 0, 0.01308961, 0.9999143, 120, 255, 1), -- Doodad_WroughtIronDoor03 (Area: The Crystal Shore)
(@OGUID+19, 177203, 0, 1, 1, -11067.97, -1824.712, 60.19905, 1.596976, 0, 0, 0.01308961, 0.9999143, 120, 255, 1), -- Gate (Area: The Crystal Shore)
(@OGUID+20, 176633, 0, 1, 1, -11105.65, -1966.78, 90.90231, 3.351047, 0, 0, 0.9006982, 0.4344453, 120, 255, 1), -- Door (Area: The Crystal Shore)
(@OGUID+21, 207208, 0, 1, 1, -11080.01, -1929.494, 90.90231, 1.80453, 0, 0, 0.9006982, 0.4344453, 120, 255, 1), -- -Unknown- (Area: The Crystal Shore)
(@OGUID+22, 184164, 0, 1, 1, -11111.03, -2004.483, 49.3827, 3.813545, 0, 0, 0.9006982, 0.4344453, 120, 255, 1), -- Karazhan Gatehouse Portcullis (Area: The Crystal Shore)
(@OGUID+23, 176578, 0, 1, 1, -11098.14, -1990.838, 49.49687, 3.813545, 0, 0, 0.9006982, 0.4344453, 120, 255, 1), -- Door (Area: The Crystal Shore)
(@OGUID+24, 176579, 0, 1, 1, -11070.7, -2001.422, 114.8234, 4.677484, 0, 0, 0.9006982, 0.4344453, 120, 255, 1), -- Door (Area: The Crystal Shore)
(@OGUID+25, 176577, 0, 1, 1, -11066.05, -1988.069, 231.5188, 2.591811, 0, 0, 0.9006982, 0.4344453, 120, 255, 1), -- Gate (Area: The Crystal Shore)
(@OGUID+26, 176580, 0, 1, 1, -11033.63, -1986.337, 126.0721, 4.223697, 0, 0, 0.9006982, 0.4344453, 120, 255, 1), -- Door (Area: The Crystal Shore)
(@OGUID+27, 176694, 0, 1, 1, -11037.91, -1999.855, 92.9915, 2.242746, 0, 0, 0.9006982, 0.4344453, 120, 255, 1), -- Karazhan Side Entrance (Area: The Crystal Shore)
(@OGUID+28, 37118, 0, 1, 1, -9896.839, -3723.431, 21.91474, 2.286379, 0, 0, 0, 1, 120, 255, 1), -- Galen's Cage (Area: The Crystal Shore)
(@OGUID+29, 201517, 0, 1, 1, -8765.823, 403.1644, 104.1621, 5.384343, 0, 0, 0.944089, -0.3296907, 120, 255, 0), -- -Unknown- (Area: The Crystal Shore)
-- (@OGUID+30, 176310, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 120, 255, 1), -- 0 (Area: The Crystal Shore) - !!! transport !!!
(@OGUID+30, 204582, 0, 1, 1, -9282.32, -3327.47, 112.287, 6.19592, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: The Crystal Shore)
-- (@OGUID+31, 190536, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 120, 255, 1), -- 0 (Area: The Crystal Shore) - !!! transport !!!
(@OGUID+31, 202831, 0, 1, 1, -7427.796, -1169.742, 478.2133, 0.3503397, 0, 0, -0.5730546, 0.8195173, 120, 255, 1), -- -Unknown- (Area: The Crystal Shore)
(@OGUID+32, 149045, 0, 1, 1, -6904.813, -1206.778, 178.5117, 2.984498, 0, 0, 1, -4.371139E-08, 120, 255, 24), -- 0 (Area: The Crystal Shore)
(@OGUID+33, 149046, 0, 1, 1, -6900.42, -1339.326, 239.652, 3.394674, 0, 0, 1, -4.371139E-08, 120, 255, 24), -- 0 (Area: The Crystal Shore)
(@OGUID+34, 161536, 0, 1, 1, -6756.729, -1166.696, 187.0422, 1.317723, 0, 0, 0.9969173, -0.07845917, 120, 255, 1), -- Quarry Gate (Area: The Crystal Shore)
(@OGUID+35, 203402, 0, 1, 1, -7208.941, 3910.72, -2.248372, 4.756022, 1.261169E-43, 0, 0, 0, 120, 255, 1), -- -Unknown- (Area: The Crystal Shore)
(@OGUID+36, 203400, 0, 1, 1, -7259.479, 4101.91, -1.733832, 5.445428, 1.233143E-43, 0, 0, 0, 120, 255, 1), -- -Unknown- (Area: The Crystal Shore)
(@OGUID+37, 203401, 0, 1, 1, -7147.46, 4035.37, -1.931532, 5.096362, 1.247156E-43, 0, 0, 0, 120, 255, 1), -- -Unknown- (Area: The Crystal Shore)
(@OGUID+38, 203399, 0, 1, 1, -6951.91, 4135.649, -2.532064, 0.1832588, 1.21913E-43, 0, 0, 0, 120, 255, 1), -- -Unknown- (Area: The Crystal Shore)
(@OGUID+39, 203397, 0, 1, 1, -7032.8, 4313.391, -2.122287, 0.6195911, 1.008935E-43, 0, 0, 0, 120, 255, 1), -- -Unknown- (Area: The Crystal Shore)
(@OGUID+40, 203398, 0, 1, 1, -6895.021, 4267.181, -2.49859, 0.6195931, 1.205117E-43, 0, 0, 0, 120, 255, 1), -- -Unknown- (Area: The Crystal Shore)
(@OGUID+41, 152614, 0, 1, 1, -5210.476, 499.2994, 401.0719, 0.7679439, 0, 0, 0.3746067, 0.9271838, 120, 255, 24), -- 0 (Area: The Crystal Shore)
(@OGUID+42, 204850, 0, 1, 1, -6612.319, 4228.612, -483.4876, 1.78482, 0, 0, 0.9885786, 0.1507064, 120, 255, 1), -- -Unknown- (Area: The Crystal Shore)
(@OGUID+43, 205079, 0, 1, 1, -5177.976, 673.805, 389.5476, 1.492256, 0, 0, 0.6788008, 0.7343224, 120, 255, 24), -- 0 (Area: The Crystal Shore)
(@OGUID+44, 205080, 0, 1, 1, -5178.21, 671.8933, 402.1269, 1.492256, 0, 0, 0.6788008, 0.7343224, 120, 255, 24), -- 0 (Area: The Crystal Shore)
(@OGUID+45, 204851, 0, 1, 1, -6544.712, 4244.213, -489.2864, 1.325501, 0, 0, 0.9885786, 0.1507064, 120, 255, 1), -- -Unknown- (Area: The Crystal Shore)
(@OGUID+46, 152614, 0, 1, 1, -5067.462, 438.9844, 423.7576, 2.539454, 0, 0, 0.95502, 0.2965415, 120, 255, 24), -- 0 (Area: The Crystal Shore)
(@OGUID+47, 204848, 0, 1, 1, -6327.528, 4167.719, -489.2864, 0.8854322, 0, 0, 0.9885786, 0.1507064, 120, 255, 0), -- -Unknown- (Area: The Crystal Shore)
(@OGUID+48, 205077, 0, 1, 1, -4917.348, 782.4108, 276.2287, 1.492256, 0, 0, 0.6788008, 0.7343224, 120, 255, 1), -- -Unknown- (Area: The Crystal Shore)
(@OGUID+49, 207872, 0, 1, 1, -6247.23, 6529.747, -880.4471, 5.240902, 0, 0, 0.4400505, 0.897973, 120, 255, 0), -- -Unknown- (Area: The Crystal Shore)
(@OGUID+50, 207869, 0, 1, 1, -6188.985, 6559.648, -883.7168, 5.240902, 0, 0, 0.4400505, 0.897973, 120, 255, 0), -- -Unknown- (Area: The Crystal Shore)
(@OGUID+51, 207870, 0, 1, 1, -6047.34, 6742.35, -883.7168, 5.852104, 0, 0, 0.4400505, 0.897973, 120, 255, 0), -- -Unknown- (Area: The Crystal Shore)
(@OGUID+52, 190192, 0, 1, 1, -4903.218, -6629.801, 10.95026, 5.410522, 0, 0, -0.4226183, 0.9063078, 120, 255, 0), -- Gate (Area: The Crystal Shore)
(@OGUID+53, 207871, 0, 1, 1, -6032.426, 6805.216, -877.9181, 6.140289, 0, 0, 0.4400505, 0.897973, 120, 255, 0), -- -Unknown- (Area: The Crystal Shore)
-- (@OGUID+54, 206329, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 120, 255, 1), -- 0 (Area: The Crystal Shore) - !!! transport !!!
-- (@OGUID+54, 206328, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 120, 255, 1), -- 0 (Area: The Crystal Shore) - !!! transport !!!
(@OGUID+54, 195491, 0, 1, 1, -1713.75, 4664.54, -1309.52, 4.14516, 0, 0, 0.8767267, -0.4809888, 120, 255, 1), -- Doodad_ND_WinterOrc_Wall_GateFX_Door01 (Area: The Crystal Shore)
(@OGUID+55, 195437, 0, 1, 1, -1643.74, 4642.156, -1308.775, 1.41361, 0, 0, 0.6494083, 0.7604399, 120, 255, 1), -- Doodad_VR_Portcullis01 (Area: The Crystal Shore)
(@OGUID+56, 195491, 0, 1, 1, -1582.631, 4657.26, -1309.14, 5.358162, 0, 0, -0.4461977, 0.8949344, 120, 255, 1), -- Doodad_ND_WinterOrc_Wall_GateFX_Door01 (Area: The Crystal Shore)
(@OGUID+57, 195437, 0, 1, 1, -1552.63, 4712.904, -1308.775, 2.809871, 0, 0, 0.9862769, 0.1650993, 120, 255, 1), -- Doodad_VR_Portcullis01 (Area: The Crystal Shore)
(@OGUID+58, 195491, 0, 1, 1, -1568.881, 4784.29, -1309.41, 0.4014249, 0, 0, 0.1993681, 0.9799247, 120, 255, 1), -- Doodad_ND_WinterOrc_Wall_GateFX_Door01 (Area: The Crystal Shore)
(@OGUID+59, 195491, 0, 1, 1, -1171.189, 4416.63, -1309.28, 3.097919, 0, 0, 0.9997621, 0.02181499, 120, 255, 1), -- Doodad_ND_WinterOrc_Wall_GateFX_Door01 (Area: The Crystal Shore)
(@OGUID+60, 195437, 0, 1, 1, -1146.486, 4356.482, -1307.615, 0.5845804, 0, 0, 0.2881461, 0.9575865, 120, 255, 1), -- Doodad_VR_Portcullis01 (Area: The Crystal Shore)
(@OGUID+61, 195437, 0, 1, 1, -1147.139, 4471.825, -1307.615, 5.471503, 0, 0, -0.3947921, 0.9187705, 120, 255, 1), -- Doodad_VR_Portcullis01 (Area: The Crystal Shore)
(@OGUID+62, 195491, 0, 1, 1, -1079.949, 4325.91, -1309.27, 4.459317, 0, 0, -0.7906896, 0.6122173, 120, 255, 1), -- Doodad_ND_WinterOrc_Wall_GateFX_Door01 (Area: The Crystal Shore)
(@OGUID+63, 195491, 0, 1, 1, -1086.77, 4513.75, -1309.27, 1.919862, 0, 0, 0.8191521, 0.5735763, 120, 255, 1), -- Doodad_ND_WinterOrc_Wall_GateFX_Door01 (Area: The Crystal Shore)
(@OGUID+64, 174626, 0, 1, 1, 1267.591, -2567.375, 94.11425, 5.192355, 0, 0, 0.9713421, -0.2376859, 120, 255, 1), -- Scholomance Door (Area: The Crystal Shore)
(@OGUID+65, 20657, 0, 1, 1, 1533.878, 240.8255, -32.34733, 3.132858, 0, 0, -0.004363197, 0.9999905, 120, 255, 24), -- 0 (Area: The Crystal Shore)
(@OGUID+66, 20655, 0, 1, 1, 1544.236, 240.7726, -40.78354, 6.274459, 0, 0, -0.004363197, 0.9999905, 120, 255, 24), -- 0 (Area: The Crystal Shore)
(@OGUID+67, 20656, 0, 1, 1, 1553.298, 240.656, 55.39519, 6.274459, 0, 0, -0.004363197, 0.9999905, 120, 255, 24), -- 0 (Area: The Crystal Shore)
(@OGUID+68, 20654, 0, 1, 1, 1595.212, 178.6932, -40.52226, 4.703663, 0, 0, -0.004363197, 0.9999905, 120, 255, 24), -- 0 (Area: The Crystal Shore)
(@OGUID+69, 20652, 0, 1, 1, 1595.261, 188.6444, -40.78354, 1.56207, 0, 0, -0.004363197, 0.9999905, 120, 255, 24), -- 0 (Area: The Crystal Shore)
(@OGUID+70, 20653, 0, 1, 1, 1595.378, 197.7065, 55.39519, 1.56207, 0, 0, -0.004363197, 0.9999905, 120, 255, 24), -- 0 (Area: The Crystal Shore)
(@OGUID+71, 20650, 0, 1, 1, 1596.037, 282.7377, 55.3952, 4.703663, 0, 0, -0.004363197, 0.9999905, 120, 255, 24), -- 0 (Area: The Crystal Shore)
(@OGUID+72, 20649, 0, 1, 1, 1596.154, 291.7997, 14.68224, 4.703663, 0, 0, -0.004363197, 0.9999905, 120, 255, 24), -- 0 (Area: The Crystal Shore)
(@OGUID+73, 20651, 0, 1, 1, 1596.209, 302.4006, -40.66451, 1.56207, 0, 0, -0.004363197, 0.9999905, 120, 255, 24), -- 0 (Area: The Crystal Shore)
-- (@OGUID+74, 181689, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 120, 255, 1), -- 0 (Area: The Crystal Shore) - !!! transport !!!
(@OGUID+74, 176594, 0, 1, 1, 2389.097, 337.9021, 40.01292, 2.242746, 0, 0, 0.9006982, 0.4344453, 120, 255, 1), -- Doors (Area: The Crystal Shore)
(@OGUID+75, 101851, 0, 1, 1, 2886.309, -827.2612, 160.3354, 1.963495, 0, 0, 0.8314698, 0.55557, 120, 255, 1), -- Armory Door (Area: The Crystal Shore)
(@OGUID+76, 101850, 0, 1, 1, 2908.177, -818.2034, 160.3318, 1.963495, 0, 0, 0.8314698, 0.55557, 120, 255, 1), -- Cathedral Door (Area: The Crystal Shore)
(@OGUID+77, 175369, 0, 1, 1, 3185.481, -4039.099, 107.7914, 3.124123, 0, 0, 0.9999619, 0.008726474, 120, 255, 1), -- Elders' Square Service Entrance (Area: The Crystal Shore)
(@OGUID+78, 175370, 0, 1, 1, 3271.517, -4064.309, 108.4344, 3.429581, 0, 0, 0.9999619, 0.008726474, 120, 255, 1), -- Doodad_SmallPortcullis05 (Area: The Crystal Shore)
(@OGUID+79, 194919, 0, 1, 1, 3555.828, -3434.895, 136.3569, 2.312558, 0, 0, 1, -4.371139E-08, 120, 255, 1), -- -Unknown- (Area: The Crystal Shore)
(@OGUID+80, 194918, 0, 1, 1, 3571.571, -3451.686, 136.3569, 2.312558, 0, 0, 1, -4.371139E-08, 120, 255, 1), -- -Unknown- (Area: The Crystal Shore)
(@OGUID+81, 194917, 0, 1, 1, 3603.04, -3335.242, 125.3545, 3.141593, 0, 0, 1, -4.371139E-08, 120, 255, 1), -- -Unknown- (Area: The Crystal Shore)
(@OGUID+82, 194916, 0, 1, 1, 3621.545, -3335.557, 123.5011, 3.141593, 0, 0, 1, -4.371139E-08, 120, 255, 1), -- -Unknown- (Area: The Crystal Shore)
(@OGUID+83, 194934, 0, 1, 1, 3624.908, -3642.165, 138.4453, 3.595379, 0, 0, 1, -4.371139E-08, 120, 255, 1), -- -Unknown- (Area: The Crystal Shore)
(@OGUID+84, 194923, 0, 1, 1, 3727.291, -3599.084, 142.2197, 3.516848, 0, 0, 1, -4.371139E-08, 120, 255, 1), -- -Unknown- (Area: The Crystal Shore)
(@OGUID+85, 194922, 0, 1, 1, 3782.581, -3590.481, 143.9873, 1.946041, 0, 0, 1, -4.371139E-08, 120, 255, 1), -- -Unknown- (Area: The Crystal Shore)
(@OGUID+86, 194925, 0, 1, 1, 3908.783, -3320.208, 120.9042, 4.424412, 0, 0, 1, -4.371139E-08, 120, 255, 1), -- -Unknown- (Area: The Crystal Shore)
(@OGUID+87, 194921, 0, 1, 1, 3908.553, -3545.293, 135.9082, 2.949595, 0, 0, 1, -4.371139E-08, 120, 255, 1), -- -Unknown- (Area: The Crystal Shore)
(@OGUID+88, 194920, 0, 1, 1, 3931.202, -3549.387, 133.9609, 2.949595, 0, 0, 1, -4.371139E-08, 120, 255, 1), -- -Unknown- (Area: The Crystal Shore)
(@OGUID+89, 194924, 0, 1, 1, 3960.596, -3392.892, 119.6622, 3.194002, 0, 0, 1, -4.371139E-08, 120, 255, 1), -- -Unknown- (Area: The Crystal Shore)
(@OGUID+90, 2045, 0, 1, 1, -13910.42, -411.5089, -18.49637, 3.630291, 0, 0, 0, 1, 120, 255, 1), -- Stranglekelp (Area: The Crystal Shore)
(@OGUID+91, 204406, 0, 1, 1, -13950.6, -141.708, 1.59752, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: The Crystal Shore)
(@OGUID+92, 2042, 0, 1, 1, -13794.3, -193.313, 12.4729, 0, 0, 0, 0, 1, 120, 255, 1), -- Fadeleaf (Area: The Crystal Shore)
(@OGUID+93, 1735, 0, 1, 1, -13963.7, 20.2882, 22.5398, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: The Crystal Shore)
(@OGUID+94, 2042, 0, 1, 1, -13831.3, 94.6736, 22.0092, 0, 0, 0, 0, 1, 120, 255, 1), -- Fadeleaf (Area: The Crystal Shore)
(@OGUID+95, 1735, 0, 1, 1, -13805.1, 73.7118, 37.7484, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: The Crystal Shore)
(@OGUID+96, 2042, 0, 1, 1, -13946.5, 227.66, 14.5453, 0, 0, 0, 0, 1, 120, 255, 1), -- Fadeleaf (Area: Mistvale Valley)
(@OGUID+97, 1735, 0, 1, 1, -13962.6, 210.057, 27.0015, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: Cape of Stranglethorn)
-- (@OGUID+98, 20808, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 120, 255, 1), -- 0 (Area: Cape of Stranglethorn) - !!! transport !!!
(@OGUID+98, 1735, 0, 1, 1, -13963.8, 334.776, 31.1572, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: Cape of Stranglethorn)
(@OGUID+99, 204909, 0, 1, 1, -14004.1, 381.333, 30.6362, 3.141355, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Cape of Stranglethorn)
(@OGUID+100, 204336, 0, 1, 1, -13891.7, 402.194, 107.959, 2.757613, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Cape of Stranglethorn)
(@OGUID+101, 204336, 0, 1, 1, -13888.2, 498.351, 95.8659, 0.4188786, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Nek'mani Wellspring)
(@OGUID+102, 1735, 0, 1, 1, -13972.9, 485.132, 50.2089, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: Nek'mani Wellspring)
(@OGUID+103, 1735, 0, 1, 1, -13966.6, 440.938, 69.7226, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: Nek'mani Wellspring)
(@OGUID+104, 204336, 0, 1, 1, -13837.58, 431.026, 90.30043, 3.787367, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Nek'mani Wellspring)
(@OGUID+105, 204336, 0, 1, 1, -13843.18, 427.4583, 90.29513, 0.6457717, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Nek'mani Wellspring)
(@OGUID+106, 204336, 0, 1, 1, -13848.7, 503.344, 88.1781, 4.852017, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Nek'mani Wellspring)
(@OGUID+107, 2042, 0, 1, 1, -13912.5, 616.828, 22.478, 0, 0, 0, 0, 1, 120, 255, 1), -- Fadeleaf (Area: Cape of Stranglethorn)
(@OGUID+108, 204336, 0, 1, 1, -13909.3, 633.401, 7.70802, 1.570796, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Cape of Stranglethorn)
(@OGUID+109, 204336, 0, 1, 1, -13898.3, 598.922, 35.2354, 5.602507, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Cape of Stranglethorn)
(@OGUID+110, 2046, 0, 1, 1, -13857.4, 598.733, 51.9818, 0, 0, 0, 0, 1, 120, 255, 1), -- Goldthorn (Area: Cape of Stranglethorn)
(@OGUID+111, 204336, 0, 1, 1, -13870.3, 665.971, 13.8849, 1.605702, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Cape of Stranglethorn)
(@OGUID+112, 204336, 0, 1, 1, -13869.6, 661.615, 14.8805, 4.66003, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Cape of Stranglethorn)
(@OGUID+113, 204336, 0, 1, 1, -13824.9, 592.307, 45.397, 2.024579, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Cape of Stranglethorn)
(@OGUID+114, 2042, 0, 1, 1, -13841.1, 630.319, 23.8501, 0, 0, 0, 0, 1, 120, 255, 1), -- Fadeleaf (Area: Cape of Stranglethorn)
(@OGUID+115, 204336, 0, 1, 1, -13822.3, 649.627, 13.926, 0.1047193, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Cape of Stranglethorn)
-- (@OGUID+116, 176231, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 120, 255, 1), -- 0 (Area: Cape of Stranglethorn) - !!! transport !!!
-- (@OGUID+116, 164871, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 120, 255, 1), -- 0 (Area: Cape of Stranglethorn) - !!! transport !!!
(@OGUID+116, 2045, 0, 1, 1, -13897.64, 765.0219, -21.7174, 4.34587, 0, 0, 0, 1, 120, 255, 1), -- Stranglekelp (Area: Southern Savage Coast)
(@OGUID+117, 2045, 0, 1, 1, -13824.53, 756.1116, -20.90007, 1.361356, 0, 0, 0, 1, 120, 255, 1), -- Stranglekelp (Area: Southern Savage Coast)
(@OGUID+118, 180683, 0, 1, 1, -14023.2, 593.5521, 0, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Firefin Snapper School (Area: Southern Savage Coast)
(@OGUID+119, 2041, 0, 1, 1, -14033.1, 380.398, 7.51095, 0, 0, 0, 0, 1, 120, 255, 1), -- Liferoot (Area: Southern Savage Coast)
(@OGUID+120, 2042, 0, 1, 1, -14038.2, 174.483, 13.9228, 0, 0, 0, 0, 1, 120, 255, 1), -- Fadeleaf (Area: Cape of Stranglethorn)
(@OGUID+121, 2046, 0, 1, 1, -14000.9, 33.7865, 33.4506, 0, 0, 0, 0, 1, 120, 255, 1), -- Goldthorn (Area: Mistvale Valley)
(@OGUID+122, 2043, 0, 1, 1, -14001.8, 106.592, 11.7421, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: Mistvale Valley)
(@OGUID+123, 1735, 0, 1, 1, -14070.6, 126.967, 23.8911, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: Mistvale Valley)
(@OGUID+124, 180683, 0, 1, 1, -13973.7, -156.3368, 0, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Firefin Snapper School (Area: Mistvale Valley)
(@OGUID+125, 1735, 0, 1, 1, -13984.4, -110.948, 8.08336, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: Mistvale Valley)
(@OGUID+126, 180682, 0, 1, 1, -14049.3, -155.9931, 0, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Oily Blackmouth School (Area: Cape of Stranglethorn)
(@OGUID+127, 2045, 0, 1, 1, -14141.72, -346.2269, -25.17768, 3.979355, 0, 0, 0, 1, 120, 255, 1), -- Stranglekelp (Area: The Crystal Shore)
(@OGUID+128, 180683, 0, 1, 1, -14103.5, -162.3507, 0, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Firefin Snapper School (Area: The Crystal Shore)
(@OGUID+129, 1735, 0, 1, 1, -14093.1, -94.4028, 11.7023, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: The Crystal Shore)
(@OGUID+130, 1735, 0, 1, 1, -14196.2, 145.891, 15.109, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: Mistvale Valley)
(@OGUID+131, 1735, 0, 1, 1, -14133.9, 284.144, 23.6785, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: Mistvale Valley)
(@OGUID+132, 2042, 0, 1, 1, -14087.9, 278.851, 14.2078, 0, 0, 0, 0, 1, 120, 255, 1), -- Fadeleaf (Area: Mistvale Valley)
-- (@OGUID+133, 181688, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 120, 255, 1), -- 0 (Area: Mistvale Valley) - !!! transport !!!
(@OGUID+133, 1735, 0, 1, 1, -14185.2, 400.036, 20.5683, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: Cape of Stranglethorn)
(@OGUID+134, 1984, 0, 1, 1, -14126.94, 467.526, 1.849717, 2.644172, 0, 0, 0, 1, 120, 255, 1), -- Campfire (Area: Cape of Stranglethorn)
(@OGUID+135, 2083, 0, 1, 1, -14126.2, 480.146, 2.43849, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Bloodsail Correspondence (Area: Cape of Stranglethorn)
(@OGUID+136, 208420, 0, 1, 1, -14189.22, 706.9913, 39.20633, 2.199115, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Southern Savage Coast)
(@OGUID+137, 3215, 0, 1, 1, -14253.91, 301.9688, 29.6402, 4.790929, 0, 0, 0, 1, 120, 255, 1), -- Grom'Gol (Area: Cape of Stranglethorn)
(@OGUID+138, 3214, 0, 1, 1, -14253.9, 301.9531, 30.47187, 4.790929, 0, 0, 0, 1, 120, 255, 1), -- Arena (Area: Cape of Stranglethorn)
(@OGUID+139, 3216, 0, 1, 1, -14238.79, 301.408, 27.87196, 3.124123, 0, 0, 0, 1, 120, 255, 1), -- Arena (Area: Cape of Stranglethorn)
(@OGUID+140, 3217, 0, 1, 1, -14238.76, 301.0504, 27.12062, 3.124032, 0, 0, 0, 1, 120, 255, 1), -- Duskwood (Area: Cape of Stranglethorn)
(@OGUID+141, 2046, 0, 1, 1, -14226.1, 312.325, 38.8805, 0, 0, 0, 0, 1, 120, 255, 1), -- Goldthorn (Area: Cape of Stranglethorn)
(@OGUID+142, 204406, 0, 1, 1, -14237.8, -32.5052, 2.49097, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Mistvale Valley)
(@OGUID+143, 1735, 0, 1, 1, -14220, -10.7274, 10.5889, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: Mistvale Valley)
(@OGUID+144, 2046, 0, 1, 1, -14259.2, 67.8229, 20.3691, 0, 0, 0, 0, 1, 120, 255, 1), -- Goldthorn (Area: Cape of Stranglethorn)
(@OGUID+145, 178204, 0, 1, 1, -14287.14, 534.1586, 8.928218, 3.665196, 0, 0, 0, 1, 120, 255, 1), -- Warsong Axe Shipment (Area: Southern Savage Coast)
(@OGUID+146, 164762, 0, 1, 1, -14289.33, 588.7189, 6.09668, 3.491031, 0, 0, 0, 1, 120, 255, 1), -- Wooden Chair (Area: Booty Bay)
(@OGUID+147, 164761, 0, 1, 1, -14291.03, 587.986, 6.09668, 0.4279799, 0, 0, 0, 1, 120, 255, 1), -- Wooden Chair (Area: Booty Bay)
(@OGUID+148, 164764, 0, 1, 1, -14288.79, 585.4207, 6.096821, 4.372422, 0, 0, 0, 1, 120, 255, 1), -- Wooden Chair (Area: Booty Bay)
(@OGUID+149, 164759, 0, 1, 1, -14293.68, 588.8556, 6.063879, 3.491031, 0, 0, 0, 1, 120, 255, 1), -- Wooden Chair (Area: Booty Bay)
(@OGUID+150, 164763, 0, 1, 1, -14289.28, 583.7079, 6.096821, 1.30937, 0, 0, 0, 1, 120, 255, 1), -- Wooden Chair (Area: Booty Bay)
(@OGUID+151, 164760, 0, 1, 1, -14295.33, 588.1219, 6.063879, 0.4279799, 0, 0, 0, 1, 120, 255, 1), -- Wooden Chair (Area: Booty Bay)
(@OGUID+152, 164766, 0, 1, 1, -14285.05, 574.8789, 6.099214, 3.491031, 0, 0, 0, 1, 120, 255, 1), -- Wooden Chair (Area: Booty Bay)
(@OGUID+153, 164765, 0, 1, 1, -14286.44, 574.2495, 6.099214, 0.4279799, 0, 0, 0, 1, 120, 255, 1), -- Wooden Chair (Area: Booty Bay)
(@OGUID+154, 164767, 0, 1, 1, -14314.17, 597.5714, 6.098139, 5.498158, 0, 0, 0, 1, 120, 255, 1), -- Wooden Chair (Area: Booty Bay)
(@OGUID+155, 56903, 0, 1, 1, -14333.67, 418.923, 9.135853, 1.134463, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- Good Food (Area: Booty Bay)
(@OGUID+156, 59518, 0, 1, 1, -14342.25, 425.5752, 9.874699, 5.05273, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- Nautical Needs (Area: Booty Bay)
(@OGUID+157, 56905, 0, 1, 1, -14342.35, 412.6718, 11.08564, 0.3680533, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- Swift Flights (Area: Booty Bay)
(@OGUID+158, 2043, 0, 1, 1, -14313.2, 146.118, 7.99474, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: Cape of Stranglethorn)
(@OGUID+159, 180683, 0, 1, 1, -14306, 14.125, 0, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Firefin Snapper School (Area: Cape of Stranglethorn)
(@OGUID+160, 180682, 0, 1, 1, -14354.3, 50.40625, 0, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Oily Blackmouth School (Area: Wild Shore)
(@OGUID+161, 2045, 0, 1, 1, -14396.71, 14.45453, -9.313372, 2.094393, 0, 0, 0, 1, 120, 255, 1), -- Stranglekelp (Area: Wild Shore)
(@OGUID+162, 56898, 0, 1, 1, -14361.46, 378.5787, 25.0536, 2.11763, 0, 0, 0.503774, 0.8638355, 120, 255, 1), -- Plate-n-Chain (Area: Cape of Stranglethorn)
(@OGUID+163, 2574, 0, 1, 1, -14378.63, 364.3941, 23.94369, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Anvil (Area: Cape of Stranglethorn)
(@OGUID+164, 56897, 0, 1, 1, -14379.79, 369.8622, 23.94535, 1.893682, 0, 0, 0.1607427, 0.9869964, 120, 255, 1), -- Forge (Area: Cape of Stranglethorn)
(@OGUID+165, 21678, 0, 1, 1, -14381.7, 374.0432, 23.9088, 0.122173, 0, 0, 0.1607427, 0.9869964, 120, 255, 1), -- Anvil (Area: Cape of Stranglethorn)
(@OGUID+166, 2575, 0, 1, 1, -14378.81, 379.2639, 23.31351, 4.14516, 0, 0, 0, 1, 120, 255, 1), -- Forge (Area: Cape of Stranglethorn)
(@OGUID+167, 91692, 0, 1, 1, -14373.18, 404.3042, 11.11155, 2.591811, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- Boomstick Imports East (Area: Cape of Stranglethorn)
(@OGUID+168, 59847, 0, 1, 1, -14373.4, 410.8162, 11.0642, 4.852017, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- Cuts-N-Bruises Incorporated (Area: Cape of Stranglethorn)
(@OGUID+169, 59845, 0, 1, 1, -14356.33, 432.0625, 9.793728, 2.251473, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- The Old Port Authority (Area: Cape of Stranglethorn)
(@OGUID+170, 59855, 0, 1, 1, -14398.56, 404.6649, 22.82138, 2.504543, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- Stove (Area: Cape of Stranglethorn)
(@OGUID+171, 180391, 0, 1, 1, -14298.27, 526.5938, 8.761889, 0.8203033, 0, 0, 0, 1, 120, 255, 1), -- Heart of Hakkar Spell Emitter (Area: Booty Bay)
(@OGUID+172, 164767, 0, 1, 1, -14314.17, 597.5714, 6.098139, 5.498158, 0, 0, 0, 1, 120, 255, 1), -- Wooden Chair (Area: Cape of Stranglethorn)
(@OGUID+173, 164760, 0, 1, 1, -14295.33, 588.1219, 6.063879, 0.4279799, 0, 0, 0, 1, 120, 255, 1), -- Wooden Chair (Area: Cape of Stranglethorn)
(@OGUID+174, 164759, 0, 1, 1, -14293.68, 588.8556, 6.063879, 3.491031, 0, 0, 0, 1, 120, 255, 1), -- Wooden Chair (Area: Cape of Stranglethorn)
(@OGUID+175, 164761, 0, 1, 1, -14291.03, 587.986, 6.09668, 0.4279799, 0, 0, 0, 1, 120, 255, 1), -- Wooden Chair (Area: Cape of Stranglethorn)
(@OGUID+176, 164762, 0, 1, 1, -14289.33, 588.7189, 6.09668, 3.491031, 0, 0, 0, 1, 120, 255, 1), -- Wooden Chair (Area: Cape of Stranglethorn)
(@OGUID+177, 164764, 0, 1, 1, -14288.79, 585.4207, 6.096821, 4.372422, 0, 0, 0, 1, 120, 255, 1), -- Wooden Chair (Area: Cape of Stranglethorn)
(@OGUID+178, 164763, 0, 1, 1, -14289.28, 583.7079, 6.096821, 1.30937, 0, 0, 0, 1, 120, 255, 1), -- Wooden Chair (Area: Cape of Stranglethorn)
(@OGUID+179, 164765, 0, 1, 1, -14286.44, 574.2495, 6.099214, 0.4279799, 0, 0, 0, 1, 120, 255, 1), -- Wooden Chair (Area: Cape of Stranglethorn)
(@OGUID+180, 164766, 0, 1, 1, -14285.05, 574.8789, 6.099214, 3.491031, 0, 0, 0, 1, 120, 255, 1), -- Wooden Chair (Area: Cape of Stranglethorn)
(@OGUID+181, 187299, 0, 1, 1, -14415.98, 521.4636, 5.020501, 0.6632232, 0, 0, 0, 1, 120, 255, 1), -- Guild Vault (Area: Booty Bay)
(@OGUID+182, 144126, 0, 1, 1, -14417.38, 517.0344, 5.013168, 2.504543, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- Mailbox (Area: Booty Bay)
(@OGUID+183, 56911, 0, 1, 1, -14421.75, 523.7631, 8.987415, 0.654497, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- Stranglethorn Trust Bank (Area: Booty Bay)
(@OGUID+184, 187299, 0, 1, 1, -14429.08, 521.6094, 4.976888, 3.455756, 0, 0, 0, 1, 120, 255, 1), -- Guild Vault (Area: Booty Bay)
(@OGUID+185, 180391, 0, 1, 1, -14320.2, 443.483, 22.9341, 4.694937, 0, 0, 0, 1, 120, 255, 1), -- Heart of Hakkar Spell Emitter (Area: Booty Bay)
(@OGUID+186, 59853, 0, 1, 1, -14419.35, 415.4035, 22.63001, 5.768314, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- Stove (Area: Booty Bay)
(@OGUID+187, 59860, 0, 1, 1, -14430.34, 425.9763, 3.969189, 3.639014, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- Stove (Area: Booty Bay)
(@OGUID+188, 59856, 0, 1, 1, -14430.79, 382.777, 32.07339, 1.928588, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- Stove (Area: Booty Bay)
(@OGUID+189, 59863, 0, 1, 1, -14435.21, 434.3912, 15.33282, 3.639014, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- Stove (Area: Booty Bay)
-- (@OGUID+190, 35591, 0, 1, 1, -14419.81, 479.5063, 0, 0.5256656, 0, 0, 0, 1, 120, 255, 1), -- Fishing Bobber (Area: Booty Bay) - !!! might be temporary spawn !!!
(@OGUID+190, 60440, 0, 1, 1, -14445.82, 449.2614, 15.5857, 3.036875, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- Wooden Chair (Area: Booty Bay)
(@OGUID+191, 59854, 0, 1, 1, -14446.83, 446.2328, 8.96072, 2.321287, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- Stove (Area: Booty Bay)
(@OGUID+192, 59862, 0, 1, 1, -14448.71, 444.7028, 3.918125, 2.321287, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- Stove (Area: Booty Bay)
(@OGUID+193, 60438, 0, 1, 1, -14447.52, 451.154, 15.60198, 4.310966, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- Wooden Chair (Area: Booty Bay)
(@OGUID+194, 59851, 0, 1, 1, -14439.06, 396.7515, 34.25932, 2.303835, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- A Tailor to Cities (Area: Booty Bay)
(@OGUID+195, 60439, 0, 1, 1, -14448.88, 446.7264, 15.5857, 1.902409, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- Wooden Chair (Area: Booty Bay)
(@OGUID+196, 175756, 0, 1, 1, -14448.96, 456.7639, 4.444387, 4.71239, 0, 0, 0, 1, 120, 255, 1), -- The Scourge of Lordaeron (Area: Booty Bay)
(@OGUID+197, 61918, 0, 1, 1, -14450.36, 416.9065, 26.98841, 0.7417169, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- Deep South Tannery (Area: Booty Bay)
(@OGUID+198, 175732, 0, 1, 1, -14454.06, 442.974, 21.31933, 2.670348, 0, 0, 0, 1, 120, 255, 1), -- The Sentinels and the Long Vigil (Area: Booty Bay)
(@OGUID+199, 59864, 0, 1, 1, -14455.23, 442.5286, 15.37849, 0.7504908, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- Stove (Area: Booty Bay)
(@OGUID+200, 56901, 0, 1, 1, -14458.72, 423.2085, 26.27726, 2.321287, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- Tan-Your-Hide Leatherworks (Area: Booty Bay)
(@OGUID+201, 180391, 0, 1, 1, -14390.22, 415.434, 22.7543, 1.047198, 0, 0, 0, 1, 120, 255, 1), -- Heart of Hakkar Spell Emitter (Area: Booty Bay)
(@OGUID+202, 59852, 0, 1, 1, -14447.13, 462.5204, 4.699703, 2.46964, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- The Happy Bobber (Area: Booty Bay)
(@OGUID+203, 59865, 0, 1, 1, -14456.78, 444.2765, 20.22755, 0.7504908, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- Stove (Area: Booty Bay)
(@OGUID+204, 59857, 0, 1, 1, -14460.87, 411.5446, 25.1386, 5.768314, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- Stove (Area: Booty Bay)
(@OGUID+205, 60395, 0, 1, 1, -14454.17, 454.2455, 15.66049, 5.218538, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- Wooden Chair (Area: Booty Bay)
(@OGUID+206, 175855, 0, 1, 1, -14458.61, 446.9653, 4.442444, 0.8377575, 0, 0, 0, 1, 120, 255, 1), -- Empires' Fall (Area: Booty Bay)
(@OGUID+207, 175854, 0, 1, 1, -14458.98, 447.4149, 5.252445, 0.2967052, 0, 0, 0, 1, 120, 255, 1), -- The Twin Empires (Area: Booty Bay)
(@OGUID+208, 175856, 0, 1, 1, -14458.98, 447.7969, 4.448832, 6.021387, 0, 0, 0, 1, 120, 255, 1), -- Wrath of Soulflayer (Area: Booty Bay)
(@OGUID+209, 59846, 0, 1, 1, -14435.32, 502.0539, 26.87379, 5.549981, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- Kalimdor Airlines (Area: Booty Bay)
(@OGUID+210, 74091, 0, 1, 1, -14459.77, 481.6033, 16.07185, 5.681049, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- The Salty Sailor Tavern (Area: Booty Bay)
(@OGUID+211, 148889, 0, 1, 1, -14456.91, 487.2761, 15.13278, 3.945231, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- Wooden Chair (Area: Booty Bay)
(@OGUID+212, 59859, 0, 1, 1, -14450.95, 496.6017, 14.91235, 3.979355, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- Stove (Area: Booty Bay)
(@OGUID+213, 204578, 0, 1, 1, -14443.44, 505.1146, 21.76689, 3.839725, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Booty Bay)
(@OGUID+214, 148892, 0, 1, 1, -14459.15, 484.8784, 15.11214, 0.934532, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- Wooden Chair (Area: Booty Bay)
(@OGUID+215, 148891, 0, 1, 1, -14458.73, 486.8767, 15.13278, 5.402578, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- Wooden Chair (Area: Booty Bay)
(@OGUID+216, 56910, 0, 1, 1, -14461.03, 479.1171, 28.56253, 5.218536, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- The Salty Sailor Tavern (Area: Booty Bay)
(@OGUID+217, 148900, 0, 1, 1, -14454.73, 491.5961, 26.27115, 0.943258, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- Wooden Chair (Area: Booty Bay)
(@OGUID+218, 2042, 0, 1, 1, -14519.9, -315.847, 5.31456, 0, 0, 0, 0, 1, 120, 255, 1), -- Fadeleaf (Area: The Crystal Shore)
(@OGUID+219, 204406, 0, 1, 1, -14517, 126.283, 0.163271, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Wild Shore)
(@OGUID+220, 59858, 0, 1, 1, -14484.3, 424.2748, 34.42488, 1.954766, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- Stove (Area: Booty Bay)
(@OGUID+221, 59850, 0, 1, 1, -14478.36, 431.7561, 36.19659, 0.8377575, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- Boucher's Cauldron (Area: Booty Bay)
(@OGUID+222, 59848, 0, 1, 1, -14471.06, 456.0584, 33.66286, 6.110018, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- Southern Skies Platform (Area: Booty Bay)
(@OGUID+223, 59517, 0, 1, 1, -14476.75, 456.3606, 31.76223, 1.980947, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- All Things Flora (Area: Booty Bay)
-- (@OGUID+224, 29784, 0, 1, 1, -14464.64, 468.2454, 15.07454, 0, 0, 0, 0, 1, 120, 255, 1), -- Basic Campfire (Area: Booty Bay) - !!! might be temporary spawn !!!
(@OGUID+224, 144127, 0, 1, 1, -14461.98, 480.032, 26.86117, 2.408554, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- Mailbox (Area: Booty Bay)
(@OGUID+225, 148904, 0, 1, 1, -14464.5, 477.3552, 20.38976, 2.155437, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- Wooden Chair (Area: Booty Bay)
(@OGUID+226, 148902, 0, 1, 1, -14466.16, 477.5314, 20.38918, 0.7504908, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- Wooden Chair (Area: Booty Bay)
(@OGUID+227, 148905, 0, 1, 1, -14468.96, 480.2759, 20.38918, 2.15545, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- Wooden Chair (Area: Booty Bay)
(@OGUID+228, 148906, 0, 1, 1, -14470.46, 481.8823, 20.38918, 5.411304, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- Wooden Chair (Area: Booty Bay)
(@OGUID+229, 148913, 0, 1, 1, -14463.94, 484.675, 20.3854, 2.304614, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- Wooden Chair (Area: Booty Bay)
(@OGUID+230, 148893, 0, 1, 1, -14460.57, 486.5493, 15.13278, 2.828211, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- Wooden Chair (Area: Booty Bay)
(@OGUID+231, 148899, 0, 1, 1, -14457.08, 493.4177, 26.27115, 1.170153, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- Wooden Chair (Area: Booty Bay)
(@OGUID+232, 148912, 0, 1, 1, -14467, 487.9465, 20.3854, 2.304614, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- Wooden Chair (Area: Booty Bay)
(@OGUID+233, 148895, 0, 1, 1, -14462.34, 488.4421, 15.13278, 5.402578, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- Wooden Chair (Area: Booty Bay)
(@OGUID+234, 148911, 0, 1, 1, -14468.84, 489.4824, 20.3854, 5.411304, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- Wooden Chair (Area: Booty Bay)
(@OGUID+235, 148910, 0, 1, 1, -14475.23, 487.0068, 20.3854, 1.213786, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- Wooden Chair (Area: Booty Bay)
(@OGUID+236, 148914, 0, 1, 1, -14458.6, 496.1511, 26.27115, 1.397046, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- Wooden Chair (Area: Booty Bay)
(@OGUID+237, 175757, 0, 1, 1, -14475.5, 488.814, 21.2839, 1.326448, 0, 0, 0, 1, 120, 255, 1), -- Sunwell - The Fall of Quel'Thalas (Area: Booty Bay)
(@OGUID+238, 148909, 0, 1, 1, -14476.27, 488.4083, 20.3854, 6.240335, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- Wooden Chair (Area: Booty Bay)
(@OGUID+239, 148915, 0, 1, 1, -14461.01, 497.0928, 26.27115, 0.8210875, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- Wooden Chair (Area: Booty Bay)
(@OGUID+240, 148898, 0, 1, 1, -14464.67, 494.4534, 15.13278, 0.8821743, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- Wooden Chair (Area: Booty Bay)
(@OGUID+241, 148901, 0, 1, 1, -14455.09, 503.5185, 26.27115, 3.927778, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- Wooden Chair (Area: Booty Bay)
(@OGUID+242, 148886, 0, 1, 1, -14456.9, 503.4067, 26.27115, 5.830184, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- Wooden Chair (Area: Booty Bay)
(@OGUID+243, 59861, 0, 1, 1, -14461.7, 504.1445, 26.09947, 5.489062, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- Stove (Area: Booty Bay)
(@OGUID+244, 148884, 0, 1, 1, -14457.17, 505.7437, 26.27115, 2.871843, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- Wooden Chair (Area: Booty Bay)
(@OGUID+245, 148888, 0, 1, 1, -14456.25, 501.5003, 15.13278, 2.828211, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- Wooden Chair (Area: Booty Bay)
(@OGUID+246, 148885, 0, 1, 1, -14459.19, 503.9103, 15.13278, 5.402578, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- Wooden Chair (Area: Booty Bay)
(@OGUID+247, 180391, 0, 1, 1, -14436, 440.76, 15.9439, 4.06662, 0, 0, 0, 1, 120, 255, 1), -- Heart of Hakkar Spell Emitter (Area: Booty Bay)
(@OGUID+248, 148903, 0, 1, 1, -14458.98, 505.8649, 26.27115, 0.8123609, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- Wooden Chair (Area: Booty Bay)
(@OGUID+249, 21582, 0, 1, 1, -14458.58, 506.592, 27.16114, 3.57793, 0, 0, 0, 1, 120, 255, 1), -- Beyond the Dark Portal (Area: Booty Bay)
(@OGUID+250, 148894, 0, 1, 1, -14457.25, 507.6857, 26.27115, 3.927778, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- Wooden Chair (Area: Booty Bay)
(@OGUID+251, 148887, 0, 1, 1, -14460.61, 505.0242, 15.13278, 4.538642, 0, 0, 0.3665013, 0.9304175, 120, 255, 1), -- Wooden Chair (Area: Booty Bay)
(@OGUID+252, 2045, 0, 1, 1, -14515.7, 859.1423, -46.90451, 1.989672, 0, 0, 0, 1, 120, 255, 1), -- Stranglekelp (Area: Southern Savage Coast)
(@OGUID+253, 180391, 0, 1, 1, -14428.02, 521.7396, 4.980221, 3.228859, 0, 0, 0, 1, 120, 255, 1), -- Heart of Hakkar Spell Emitter (Area: Booty Bay)
(@OGUID+254, 180391, 0, 1, 1, -14452.6, 468.903, 15.2266, 4.555311, 0, 0, 0, 1, 120, 255, 1), -- Heart of Hakkar Spell Emitter (Area: Booty Bay)
(@OGUID+255, 180391, 0, 1, 1, -14456.53, 419.375, 25.0717, 3.560473, 0, 0, 0, 1, 120, 255, 1), -- Heart of Hakkar Spell Emitter (Area: Booty Bay)
(@OGUID+256, 180391, 0, 1, 1, -14474.56, 456.0988, 30.45498, 2.617989, 0, 0, 0, 1, 120, 255, 1), -- Heart of Hakkar Spell Emitter (Area: Booty Bay)
(@OGUID+257, 180391, 0, 1, 1, -14358.09, 377.618, 23.42723, 2.530723, 0, 0, 0, 1, 120, 255, 1), -- Heart of Hakkar Spell Emitter (Area: Booty Bay)
(@OGUID+258, 180391, 0, 1, 1, -14445.76, 492.9042, 37.01822, 4.76475, 0, 0, 0, 1, 120, 255, 1), -- Heart of Hakkar Spell Emitter (Area: Booty Bay)
(@OGUID+259, 2043, 0, 1, 1, -14575.4, -302.925, 12.0499, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: Jaguero Isle)
(@OGUID+260, 180683, 0, 1, 1, -14582.6, 140.9861, 0, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Firefin Snapper School (Area: Wild Shore)
(@OGUID+261, 2043, 0, 1, 1, -14530.3, 201.627, 5.59328, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: Wild Shore)
(@OGUID+262, 1985, 0, 1, 1, -14609.68, 328.7795, 2.827802, 2.783796, 0, 0, 0, 1, 120, 255, 1), -- Campfire (Area: Booty Bay)
(@OGUID+263, 204432, 0, 1, 1, -14612.8, 342.009, 2.36385, 1.745327, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Booty Bay)
(@OGUID+264, 1735, 0, 1, 1, -14605.2, 362.441, 7.95805, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: Booty Bay)
(@OGUID+265, 204432, 0, 1, 1, -14614.8, -133.175, 5.50604, 0.2617982, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Wild Shore)
(@OGUID+266, 111149, 0, 1, 1, -14595.57, -235.4718, 24.65219, 0.7417632, 0, 0, 0, 1, 120, 255, 1), -- Campfire (Area: Jaguero Isle)
(@OGUID+267, 1735, 0, 1, 1, -14663.3, -322.064, 12.3438, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: Jaguero Isle)
(@OGUID+268, 1735, 0, 1, 1, -14648.9, -227.332, 14.1092, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: Jaguero Isle)
(@OGUID+269, 204432, 0, 1, 1, -14640.2, -128.609, 4.76812, 0.2617982, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Jaguero Isle)
(@OGUID+270, 204432, 0, 1, 1, -14699.1, -122.91, 3.03774, 0.2617982, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Jaguero Isle)
(@OGUID+271, 204432, 0, 1, 1, -14667.1, 162.72, 3.53897, 0.2617982, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Wild Shore)
(@OGUID+272, 2289, 0, 1, 1, -14656.4, 148, 3.29978, 2.740153, 0, 0, 0, 1, 120, 255, 1), -- Ruined Lifeboat (Area: Wild Shore)
(@OGUID+273, 204406, 0, 1, 1, -14647.9, 194.451, -1.00246, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Wild Shore)
(@OGUID+274, 204432, 0, 1, 1, -14630.3, 292.009, 2.52321, 0.2617982, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Wild Shore)
(@OGUID+275, 204432, 0, 1, 1, -14701.8, 513.974, 1.92098, 3.054327, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Wild Shore)
(@OGUID+276, 204432, 0, 1, 1, -14687.7, 486.781, 2.8373, 0.2617982, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Wild Shore)
(@OGUID+277, 204432, 0, 1, 1, -14700.6, 453.917, 0.56665, 0.5235979, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Wild Shore)
(@OGUID+278, 2087, 0, 1, 1, -14685.42, 486.4723, 4.179824, 0.4886912, 0, 0, 0, 1, 120, 255, 1), -- Bloodsail Orders (Area: Wild Shore)
(@OGUID+279, 2086, 0, 1, 1, -14686.33, 488.5407, 4.288588, 5.619962, 0, 0, 0, 1, 120, 255, 1), -- Bloodsail Charts (Area: Wild Shore)
(@OGUID+280, 180682, 0, 1, 1, -14773.6, 523.9827, 0, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Oily Blackmouth School (Area: Wild Shore)
(@OGUID+281, 180682, 0, 1, 1, -14749.9, 448.0347, 0, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Oily Blackmouth School (Area: Wild Shore)
(@OGUID+282, 204432, 0, 1, 1, -14746.3, -126.122, 5.71654, 0.2617982, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Wild Shore)
(@OGUID+283, 1735, 0, 1, 1, -14732.2, -329.944, 6.11054, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: Jaguero Isle)
(@OGUID+284, 2042, 0, 1, 1, -14752.1, -405.304, 6.461, 0, 0, 0, 0, 1, 120, 255, 1), -- Fadeleaf (Area: The Crystal Shore)
(@OGUID+285, 2043, 0, 1, 1, -14819.1, -374.766, 5.17866, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: The Crystal Shore)
(@OGUID+286, 2045, 0, 1, 1, -14806.1, -17.41819, -9.731571, 4.101525, 0, 0, 0, 1, 120, 255, 1), -- Stranglekelp (Area: Jaguero Isle)
(@OGUID+287, 204432, 0, 1, 1, -14824.9, 31.974, 4.37536, 0.2617982, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Jaguero Isle)
(@OGUID+288, 2045, 0, 1, 1, -14791.5, 340.7865, -19.21865, 4.363324, 0, 0, 0, 1, 120, 255, 1), -- Stranglekelp (Area: Wild Shore)
(@OGUID+289, 204432, 0, 1, 1, -14815.2, 586.257, 2.41333, 5.270896, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Wild Shore)
(@OGUID+290, 204432, 0, 1, 1, -14867.8, 305.913, 0.00711876, 0.2617982, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Wild Shore)
(@OGUID+291, 204432, 0, 1, 1, -14890.9, 381.908, 3.15066, 2.286379, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Wild Shore)
(@OGUID+292, 204432, 0, 1, 1, -14856, 71.7326, 1.0607, 0.2617982, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Wild Shore)
(@OGUID+293, 2042, 0, 1, 1, -14832.5, -305.698, 5.0194, 0, 0, 0, 0, 1, 120, 255, 1), -- Fadeleaf (Area: Jaguero Isle)
(@OGUID+294, 204432, 0, 1, 1, -14900.6, -9.6875, 2.22599, 0.2617982, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Jaguero Isle)
(@OGUID+295, 204454, 0, 1, 1, -14924.77, 113.2014, 0.1997062, 4.869471, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Wild Shore)
(@OGUID+296, 204450, 0, 1, 1, -14923.06, 126.0017, 8.21902, 3.752462, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Wild Shore)
(@OGUID+297, 204433, 0, 1, 1, -14937.8, 141.453, -24.219, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Wild Shore)
(@OGUID+298, 204432, 0, 1, 1, -14888.6, 286.304, 1.3326, 2.059488, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Wild Shore)
(@OGUID+299, 204422, 0, 1, 1, -14946.47, 342.7813, 12.7282, 2.809975, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Wild Shore)
(@OGUID+300, 204422, 0, 1, 1, -14948.01, 347.3924, 12.85086, 4.24115, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Wild Shore)
(@OGUID+301, 204422, 0, 1, 1, -14949.16, 353.7396, 13.15706, 2.897245, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Wild Shore)
(@OGUID+302, 204422, 0, 1, 1, -14950.58, 358.3385, 12.72536, 4.24115, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Wild Shore)
(@OGUID+303, 204456, 0, 1, 1, -14957.49, 346.408, 0.2205853, 4.136433, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Wild Shore)
(@OGUID+304, 2045, 0, 1, 1, -14953.65, 333.5053, -27.69386, 5.410522, 0, 0, 0, 1, 120, 255, 1), -- Stranglekelp (Area: Wild Shore)
(@OGUID+305, 204433, 0, 1, 1, -15049.3, 347.944, -43.3125, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Wild Shore)
(@OGUID+306, 204455, 0, 1, 1, -14983.15, 260.8993, 0.6533542, 0.03490625, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Wild Shore)
(@OGUID+307, 204433, 0, 1, 1, -15043.4, 281.573, -39.3771, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Wild Shore)
(@OGUID+308, 204433, 0, 1, 1, -15015, 230.41, -31.2197, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Wild Shore)
(@OGUID+309, 204433, 0, 1, 1, -14984.1, 158.436, -23.936, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: The Crimson Veil)
(@OGUID+310, 204433, 0, 1, 1, -15062.8, 201.892, -35.9195, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: The Crimson Veil)
(@OGUID+311, 204433, 0, 1, 1, -15023.9, 114.884, -24.446, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Wild Shore)
(@OGUID+312, 204433, 0, 1, 1, -15000.3, 48.3316, -23.936, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Wild Shore)
(@OGUID+313, 204433, 0, 1, 1, -15090.4, 98.4965, -40.0043, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Wild Shore)
(@OGUID+314, 204433, 0, 1, 1, -15106, 190.493, -43.0576, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Wild Shore)
(@OGUID+315, 204433, 0, 1, 1, -15120.6, 297.701, -47.3542, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Wild Shore)
(@OGUID+316, 204433, 0, 1, 1, -15094.7, 389.071, -46.1301, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Wild Shore)
(@OGUID+317, 204433, 0, 1, 1, -15084.1, 457.365, -42.565, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Wild Shore)
(@OGUID+318, 204433, 0, 1, 1, -15208.6, 227.038, -49.3561, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Wild Shore)
(@OGUID+319, 204433, 0, 1, 1, -15207.1, 254.363, -49.4243, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Wild Shore)
(@OGUID+320, 204433, 0, 1, 1, -15214.1, 198.104, -49.3237, 0, 0, 0, 0, 1, 120, 255, 1); -- -Unknown- (Area: Wild Shore)

UPDATE `creature_template` SET `minlevel`=33, `maxlevel`=34, `faction_A`=14, `faction_H`=14, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=43596; -- Venture Co. Oil Worker
UPDATE `creature_template` SET `minlevel`=32, `maxlevel`=32, `speed_walk`=1.142857, `speed_run`=0.777776, `rangeattacktime`=2000, `unit_class`=4, `unit_flags`=32768, `dynamicflags`=0 WHERE `entry`=2535; -- Maury "Club Foot" Wilkins
UPDATE `creature_template` SET `faction_A`=190, `faction_H`=190, `speed_walk`=0.8571429, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=50487; -- Forest Spiderling
UPDATE `creature_template` SET `minlevel`=31, `maxlevel`=31, `speed_walk`=1.142857, `speed_run`=0.777776, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=1489; -- Zanzil Hunter
UPDATE `creature_template` SET `minlevel`=32, `maxlevel`=32, `faction_A`=80, `faction_H`=80, `npcflag`=1, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=2, `unit_flags`=32768 WHERE `entry`=43377; -- Ephram "Midriff" Moonfall
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2544; -- Southern Sand Crawler
UPDATE `creature_template` SET `minlevel`=32, `maxlevel`=33, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=1558; -- Silverback Patriarch
UPDATE `creature_template` SET `minlevel`=31, `maxlevel`=32, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=1557; -- Elder Mistvale Gorilla
UPDATE `creature_template` SET `faction_A`=188, `faction_H`=188, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000 WHERE `entry`=49928; -- Crimson Moth
UPDATE `creature_template` SET `faction_A`=188, `faction_H`=188, `speed_walk`=0.8571429, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=49722; -- Tree Python
UPDATE `creature_template` SET `faction_A`=188, `faction_H`=188, `speed_walk`=0.5714286, `speed_run`=0.4, `baseattacktime`=2000, `rangeattacktime`=2000 WHERE `entry`=50479; -- Lizard Hatchling
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=9600; -- Parrot
UPDATE `creature_template` SET `minlevel`=43, `maxlevel`=43, `npcflag`=3, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=43504; -- Yancey Grillsen
UPDATE `creature_template` SET `minlevel`=29, `maxlevel`=30, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=1907; -- Naga Explorer
UPDATE `creature_template` SET `minlevel`=31, `maxlevel`=32, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=1561; -- Bloodsail Raider
UPDATE `creature_template` SET `minlevel`=33, `maxlevel`=33, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `unit_flags`=16384, `dynamicflags`=0 WHERE `entry`=1493; -- Mok'rash
UPDATE `creature_template` SET `minlevel`=31, `maxlevel`=32, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=1562; -- Bloodsail Mage
UPDATE `creature_template` SET `minlevel`=32, `maxlevel`=32, `faction_A`=2159, `faction_H`=2159, `npcflag`=1, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=43376; -- Freewheelin' Juntz Fitztittle
UPDATE `creature_template` SET `maxlevel`=47, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=5434; -- Coral Shark
UPDATE `creature_template` SET `minlevel`=44, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=16399; -- Bloodsail Traitor
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `faction_A`=119, `faction_H`=119, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=43364; -- Bloodsail Hooch-Hound
UPDATE `creature_template` SET `minlevel`=32, `maxlevel`=32, `faction_A`=119, `faction_H`=119, `npcflag`=2, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=43454; -- "Good-Boy" Bruce
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `speed_walk`=1.428571, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=4624; -- Booty Bay Bruiser
UPDATE `creature_template` SET `minlevel`=33, `maxlevel`=33, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `unit_flags`=16384, `dynamicflags`=0 WHERE `entry`=1492; -- Gorlash
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=25098; -- Bosun Thunderhorn
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=25089; -- Galley Chief Steelbelly
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=25095; -- Crewman Springwidget
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=25111; -- Treasure
UPDATE `creature_template` SET `gossip_menu_id`=0, `dynamicflags`=0 WHERE `entry`=25093; -- First Mate Masker
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=25082; -- Engineer Torquespindle
UPDATE `creature_template` SET `gossip_menu_id`=0, `dynamicflags`=0 WHERE `entry`=25078; -- Captain Krick Wrenchnozzle
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=25096; -- Crewman Gearspinner
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=25097; -- Crewman Hammertink
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=25094; -- Navigator Tah're
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=9559; -- Grizzlowe
UPDATE `creature_template` SET `npcflag`=1, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=4631; -- Wharfmaster Lozgil
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `faction_A`=714, `faction_H`=714, `npcflag`=2, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33536 WHERE `entry`=48797; -- Gim'hila
UPDATE `creature_template` SET `npcflag`=0, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2594; -- Sprogger
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2500; -- Captain Hecklebury Smotts
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2502; -- "Shaky" Phillipe
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `faction_A`=534, `faction_H`=534, `npcflag`=2, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33536 WHERE `entry`=48808; -- Corporal Jeyne
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=56, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `unit_flags`=33587200, `dynamicflags`=0 WHERE `entry`=28180; -- [ph] Goblin Construction Crew
UPDATE `creature_template` SET `minlevel`=36, `maxlevel`=36, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=3945; -- Caravaneer Ruzzgot
UPDATE `creature_template` SET `faction_A`=188, `faction_H`=188, `speed_walk`=0.8571429, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=768 WHERE `entry`=54475; -- Crab
UPDATE `creature_template` SET `speed_walk`=0.8571429, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=7390; -- Cockatiel
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2664; -- Kelsey Yance
UPDATE `creature_template` SET `gossip_menu_id`=11743, `npcflag`=129, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2663; -- Narkk
UPDATE `creature_template` SET `speed_walk`=0.8571429, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=7389; -- Senegal
UPDATE `creature_template` SET `npcflag`=4224, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2839; -- Haren Kanmae
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2845; -- Fargon Mortalak
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2844; -- Hurklor
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2847; -- Jansen Underwood
UPDATE `creature_template` SET `minlevel`=22, `maxlevel`=22, `faction_A`=120, `faction_H`=120, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=1500, `rangeattacktime`=2000, `unit_flags`=512 WHERE `entry`=54308; -- Kirsty Logan
UPDATE `creature_template` SET `npcflag`=0, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=7794; -- McGavan
UPDATE `creature_template` SET `gossip_menu_id`=2784, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2836; -- Brikk Keencraft
UPDATE `creature_template` SET `npcflag`=128, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2685; -- Mazk Snipeshot
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2493; -- Dizzy One-Eye
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2840; -- Kizz Bluntstrike
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2482; -- Zarena Cromwind
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2499; -- Markel Smythe
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=15677; -- Auctioneer Graves
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=15681; -- Auctioneer O'reely
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=8123; -- Rickle Goldgrubber
UPDATE `creature_template` SET `npcflag`=0, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2494; -- Privateer Bloads
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2625; -- Viznik Goldgrubber
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2490; -- First Mate Crazz
UPDATE `creature_template` SET `speed_walk`=1.428571, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=21045; -- Hired Bodyguard
UPDATE `creature_template` SET `gossip_menu_id`=11342, `speed_walk`=1.142857, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=17249; -- Landro Longshot
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2699; -- Rikqiz
UPDATE `creature_template` SET `gossip_menu_id`=11741, `npcflag`=1, `speed_walk`=0.8571429, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=262144 WHERE `entry`=43505; -- Bossy
UPDATE `creature_template` SET `npcflag`=3, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=7406; -- Oglethorpe Obnoticus
UPDATE `creature_template` SET `gossip_menu_id`=12838, `minlevel`=45, `maxlevel`=45, `faction_A`=120, `faction_H`=120, `npcflag`=209, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=512 WHERE `entry`=54232; -- Mrs. Gant
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2838; -- Crazk Sparks
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2486; -- Fin Fizracket
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2622; -- Sly Garrett
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction_A`=875, `faction_H`=875, `npcflag`=2, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33024 WHERE `entry`=44112; -- Airwyn Bantamflax
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2842; -- Wigcik
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=9858; -- Auctioneer Kresky
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2501; -- "Sea Wolf" MacKinley
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2670; -- Xizk Goodstitch
UPDATE `creature_template` SET `npcflag`=17, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2627; -- Grarnik Goodstitch
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction_A`=1604, `faction_H`=1604, `npcflag`=2, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33536 WHERE `entry`=43849; -- Garley Lightrider
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2834; -- Myizz Luckycatch
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2626; -- Old Man Heming
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2496; -- Baron Revilgaz
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2846; -- Blixrez Goodstitch
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2849; -- Qixdi Goodstitch
UPDATE `creature_template` SET `gossip_menu_id`=11744, `faction_A`=390, `faction_H`=390, `npcflag`=3, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2487; -- Fleet Master Seahorn
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=129, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=10060; -- Grimestack
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=85, `maxlevel`=85, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2858; -- Gringer
UPDATE `creature_template` SET `npcflag`=0, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2498; -- Crank Fizzlebub
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2832; -- Nixxrax Fillamug
UPDATE `creature_template` SET `minlevel`=32, `maxlevel`=32, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2521; -- Skymane Gorilla
UPDATE `creature_template` SET `minlevel`=31, `maxlevel`=32, `faction_A`=72, `faction_H`=72, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=43417; -- Skymane Bonobo
UPDATE `creature_template` SET `minlevel`=32, `maxlevel`=33, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=1653; -- Bloodsail Elder Magus
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2848; -- Glyx Brewright
UPDATE `creature_template` SET `npcflag`=17, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2837; -- Jaxin Chong
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `faction_A`=714, `faction_H`=714, `npcflag`=3, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33536 WHERE `entry`=49636; -- Arcanist Arman
UPDATE `creature_template` SET `npcflag`=16, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=908; -- Flora Silverwind
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2859; -- Gyll
UPDATE `creature_template` SET `gossip_menu_id`=12511, `minlevel`=35, `maxlevel`=35, `faction_A`=534, `faction_H`=534, `npcflag`=3, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33536 WHERE `entry`=49635; -- War-Mage Erallier
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2843; -- Jutak
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2542; -- Catelyn the Blade
UPDATE `creature_template` SET `gossip_menu_id`=11727, `npcflag`=1, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2491; -- Whiskey Slim
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=6807; -- Innkeeper Skindle
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2488; -- Deeg
UPDATE `creature_template` SET `npcflag`=1, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=1411; -- Ian Strom
UPDATE `creature_template` SET `npcflag`=1, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=737; -- Kebok
UPDATE `creature_template` SET `speed_walk`=0.8571429, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=25109; -- Rocket Chicken
UPDATE `creature_template` SET `minlevel`=32, `maxlevel`=33, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=1565; -- Bloodsail Sea Dog
UPDATE `creature_template` SET `minlevel`=31, `maxlevel`=32, `speed_walk`=0.5714286, `speed_run`=0.5, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2522; -- Jaguero Stalker
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2634; -- Princess Poobah
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2672; -- Cowardly Crosby
UPDATE `creature_template` SET `minlevel`=33, `maxlevel`=33, `speed_walk`=1.071429, `speed_run`=1.6, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=1559; -- King Mukla
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `faction_A`=119, `faction_H`=119, `npcflag`=1, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=43605; -- Bloodsail Oarsman
UPDATE `creature_template` SET `faction_A`=190, `faction_H`=190, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33587200, `VehicleId`=971 WHERE `entry`=43561; -- Bloodsail Rowboat
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `faction_A`=190, `faction_H`=190, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768, `dynamicflags`=4 WHERE `entry`=43560; -- Smilin' Timmy Sticks
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2551; -- Brutus
UPDATE `creature_template` SET `minlevel`=31, `maxlevel`=32, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=4506; -- Bloodsail Swabby
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `faction_A`=119, `faction_H`=119, `npcflag`=4224, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=44182; -- Gurlgrl
UPDATE `creature_template` SET `minlevel`=32, `maxlevel`=33, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=4505; -- Bloodsail Deckhand
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `faction_A`=119, `faction_H`=119, `npcflag`=1, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2700, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=43659; -- Long John Copper
UPDATE `creature_template` SET `minlevel`=34, `maxlevel`=35, `faction_A`=119, `faction_H`=119, `npcflag`=1, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=43636; -- Bloodsail Corsair
UPDATE `creature_template` SET `minlevel`=32, `maxlevel`=33, `faction_A`=1925, `faction_H`=1925, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=43536; -- Southsea Mako
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `faction_A`=73, `faction_H`=73, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33555200 WHERE `entry`=43853; -- Bloodsail Buzzard
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `faction_A`=119, `faction_H`=119, `npcflag`=128, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=44179; -- Harry No-Hooks
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `npcflag`=2, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2548; -- Captain Keelhaul
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `npcflag`=2, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2549; -- Garr Salthoof
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `faction_A`=119, `faction_H`=119, `npcflag`=4224, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=44178; -- Sweet Gary Guns
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `faction_A`=119, `faction_H`=119, `npcflag`=1, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2700, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=43661; -- Wailing Mary Smitts
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `npcflag`=3, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2545; -- "Pretty Boy" Duncan
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `npcflag`=2, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2547; -- Ironpatch
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `faction_A`=119, `faction_H`=119, `npcflag`=1, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2700, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=43660; -- Enormous Shawn Stooker
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `faction_A`=119, `faction_H`=119, `npcflag`=2, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=43556; -- "Dead-Eye" Drederick McGumm
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2546; -- Fleet Master Firallon
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `VehicleId`=972 WHERE `entry`=43562; -- Ol' Blasty

DELETE FROM `creature_template_addon` WHERE `entry` IN (44140, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 40728, 40728, 40728, 32520, 42851, 32520, 40987, 42851, 42851, 42851, 42851, 32520, 42851, 42851, 42851, 42851, 32520, 42851, 42851, 42851, 32520, 32520, 42851, 42851, 42851, 42851, 42851, 32520, 32520, 32520, 42851, 32520, 42851, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 37490, 42851, 42851, 32520, 42173, 42196, 42196, 42173, 42173, 37490, 43359, 45681, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 6827, 2535, 15475, 50487, 1489, 43377, 2544, 1558, 1558, 1558, 1558, 1558, 1558, 1557, 1558, 1557, 49928, 1557, 1557, 49928, 49722, 1557, 50479, 49928, 50487, 1557, 1557, 15475, 15475, 1557, 1557, 9600, 1557, 49722, 1557, 1557, 49928, 50487, 15475, 49928, 43504, 49928, 1907, 1907, 1907, 49722, 1907, 1907, 1907, 1907, 1907, 6827, 1561, 1907, 6827, 49722, 1907, 1493, 6827, 1907, 6827, 49722, 1907, 1907, 6827, 6827, 6827, 1907, 32520, 32520, 32520, 32520, 1562, 6827, 1561, 1562, 9600, 50479, 15475, 15475, 9600, 50479, 1557, 1557, 1557, 49928, 1557, 1557, 1557, 1557, 1557, 1557, 1557, 43376, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 5434, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 16399, 1557, 9600, 9600, 49928, 1561, 1562, 9600, 1562, 6827, 1561, 43364, 6827, 1562, 43454, 1561, 6827, 6827, 6827, 6827, 4624, 49928, 15475, 1561, 1561, 1492, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 49928, 43596, 43596, 43596, 1561, 15475, 48972, 4624, 4624, 4624, 4076, 4076, 4624, 4624, 6827, 32520, 32520, 32520, 32520, 25098, 25089, 25095, 25111, 25093, 25082, 25078, 25096, 25097, 25094, 15384, 9559, 4624, 4631, 4075, 48797, 2594, 2500, 2502, 48808, 4624, 28180, 9600, 3945, 4624, 4624, 4624, 4624, 48972, 9600, 28180, 54475, 49928, 28180, 28180, 7390, 28180, 28180, 28180, 2664, 2663, 7389, 2839, 1561, 1562, 49928, 50487, 6827, 6827, 2845, 4624, 4624, 2844, 2847, 54308, 7794, 2836, 28180, 4624, 28180, 2685, 47667, 28180, 2493, 2840, 4624, 2482, 4624, 4624, 2499, 48972, 15677, 4624, 28180, 28180, 28180, 25098, 25093, 25096, 25078, 25094, 25111, 25082, 25089, 25095, 25097, 28180, 4624, 4624, 28180, 49928, 4076, 15681, 4624, 8123, 2494, 2625, 4624, 28180, 4624, 2490, 4076, 21045, 21045, 17249, 4624, 9600, 2699, 43505, 7406, 28180, 54232, 4624, 2838, 4076, 4624, 4624, 4076, 2486, 4624, 2622, 48972, 4624, 44112, 4624, 2842, 4624, 4075, 4076, 9858, 4624, 4624, 2501, 4624, 4624, 4624, 2670, 2627, 4624, 43849, 4624, 4624, 4624, 2834, 4624, 4624, 2626, 2496, 2846, 2849, 4624, 2487, 10060, 2858, 4624, 2498, 2832, 4624, 4624, 6827, 6827, 6827, 6827, 2521, 43417, 2521, 6827, 6827, 6827, 6827, 43417, 6827, 6827, 50487, 6827, 6827, 6827, 6827, 1653, 6827, 2544, 49928, 1653, 6827, 50479, 2848, 2837, 4624, 49636, 4624, 4076, 908, 2859, 4624, 4624, 49635, 2843, 47667, 4624, 2542, 48972, 4624, 4624, 2491, 6807, 2488, 4624, 4624, 1493, 1411, 49928, 737, 4624, 32520, 32520, 32520, 32520, 25109, 25078, 25094, 6827, 6827, 2521, 43417, 43417, 2521, 15475, 50479, 2521, 49928, 15475, 6827, 6827, 6827, 6827, 32520, 32520, 32520, 32520, 4076, 49722, 15475, 50479, 1653, 1565, 1565, 49928, 6827, 2522, 2522, 2634, 49928, 43417, 2521, 43417, 6827, 43417, 6827, 2521, 6827, 43417, 50487, 49722, 2522, 2522, 2522, 49928, 6827, 6827, 2522, 6827, 2522, 6827, 2544, 6827, 6827, 2544, 6827, 6827, 1565, 6827, 6827, 6827, 6827, 6827, 2544, 2544, 6827, 1653, 1653, 1565, 6827, 6827, 6827, 6827, 1565, 1653, 2672, 6827, 2544, 1565, 1565, 1653, 1653, 1565, 2544, 6827, 6827, 1565, 1565, 6827, 5434, 6827, 2544, 32520, 32520, 32520, 32520, 2544, 6827, 6827, 2544, 2522, 50487, 15475, 49928, 1559, 2521, 6827, 2521, 6827, 6827, 6827, 2521, 49722, 15475, 9600, 15475, 6827, 9600, 6827, 2522, 2522, 2522, 6827, 9600, 49928, 2544, 6827, 2544, 6827, 2544, 2544, 2544, 6827, 6827, 6827, 2544, 2544, 6827, 2544, 6827, 2544, 6827, 6827, 6827, 6827, 43605, 1565, 1653, 2544, 2544, 6827, 2544, 2544, 43561, 43560, 1653, 1565, 6827, 6827, 2522, 2521, 2521, 6827, 6827, 1559, 6827, 6827, 6827, 6827, 2544, 2544, 2551, 4506, 44182, 4506, 4506, 4506, 4505, 43659, 4505, 43636, 4505, 43636, 4505, 43636, 43636, 43636, 43536, 2544, 43853, 44179, 1653, 2548, 2549, 43853, 43636, 4506, 4505, 4506, 43853, 43636, 43853, 43853, 43853, 4506, 44178, 4506, 43636, 43853, 43636, 43853, 4505, 43636, 43661, 2545, 43536, 4506, 4505, 4506, 43636, 4506, 43636, 4505, 4506, 43636, 2547, 4505, 43660, 43636, 43636, 43556, 4505, 4505, 2546, 4505, 43536, 43562, 43562, 43562, 43536, 43536, 43536, 43536, 43536, 43536, 43536, 43536, 5434, 32520, 32520, 32520, 32520, 43536, 43536, 43536, 43536, 43536, 43536, 43536, 43536, 5434, 5434, 43536, 5434);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(10060, 0, 0x0, 0x1, ''), -- Grimestack
(1411, 0, 0x0, 0x1, ''), -- Ian Strom
(1489, 0, 0x0, 0x1, ''), -- Zanzil Hunter
(1492, 0, 0x0, 0x1, ''), -- Gorlash
(1493, 0, 0x0, 0x1, ''), -- Mok'rash
(15384, 0, 0x0, 0x1, ''), -- OLDWorld Trigger (DO NOT DELETE)
(15475, 0, 0x0, 0x1, ''), -- Beetle
(1557, 0, 0x0, 0x1, ''), -- Elder Mistvale Gorilla
(1558, 0, 0x0, 0x1, ''), -- Silverback Patriarch
(1559, 0, 0x0, 0x1, ''), -- King Mukla
(1561, 0, 0x0, 0x1, ''), -- Bloodsail Raider
-- (1561, 0, 0x1, 0x1, ''), -- Bloodsail Raider
(1562, 0, 0x0, 0x1, ''), -- Bloodsail Mage
(1565, 0, 0x0, 0x1, ''), -- Bloodsail Sea Dog
(15677, 0, 0x0, 0x101, ''), -- Auctioneer Graves
(15681, 0, 0x0, 0x101, ''), -- Auctioneer O'reely
(16399, 0, 0x0, 0x1, ''), -- Bloodsail Traitor
(1653, 0, 0x0, 0x1, ''), -- Bloodsail Elder Magus
(17249, 0, 0x0, 0x1, ''), -- Landro Longshot
(1907, 0, 0x0, 0x1, ''), -- Naga Explorer
(21045, 0, 0x0, 0x0, ''), -- Hired Bodyguard
(2482, 0, 0x0, 0x1, ''), -- Zarena Cromwind
(2486, 0, 0x7, 0x1, ''), -- Fin Fizracket
(2487, 0, 0x0, 0x1, ''), -- Fleet Master Seahorn
(2488, 0, 0x0, 0x1, ''), -- Deeg
(2490, 0, 0x0, 0x1, ''), -- First Mate Crazz
(2491, 0, 0x0, 0x1, ''), -- Whiskey Slim
(2493, 0, 0x0, 0x1, ''), -- Dizzy One-Eye
(2494, 0, 0x0, 0x1, ''), -- Privateer Bloads
(2496, 0, 0x0, 0x1, ''), -- Baron Revilgaz
(2498, 0, 0x0, 0x1, ''), -- Crank Fizzlebub
(2499, 0, 0x0, 0x1, ''), -- Markel Smythe
(2500, 0, 0x0, 0x1, ''), -- Captain Hecklebury Smotts
(2501, 0, 0x0, 0x1, ''), -- "Sea Wolf" MacKinley
(2502, 0, 0x0, 0x1, ''), -- "Shaky" Phillipe
(25078, 0, 0x0, 0x0, ''), -- Captain Krick Wrenchnozzle
-- (25078, 0, 0x0, 0x1, ''), -- Captain Krick Wrenchnozzle
(25082, 0, 0x0, 0x1, ''), -- Engineer Torquespindle
(25089, 0, 0x0, 0x1, ''), -- Galley Chief Steelbelly
(25093, 0, 0x0, 0x0, ''), -- First Mate Masker
(25094, 0, 0x0, 0x1, ''), -- Navigator Tah're
-- (25094, 0, 0x1, 0x1, ''), -- Navigator Tah're
(25095, 0, 0x0, 0x1, ''), -- Crewman Springwidget
(25096, 0, 0x0, 0x1, ''), -- Crewman Gearspinner
(25097, 0, 0x0, 0x1, ''), -- Crewman Hammertink
(25098, 0, 0x3, 0x1, ''), -- Bosun Thunderhorn
(25109, 0, 0x0, 0x1, '45202'), -- Rocket Chicken - Rocket Chicken
(25111, 0, 0x0, 0x1, ''), -- Treasure
(2521, 0, 0x0, 0x1, ''), -- Skymane Gorilla
(2522, 0, 0x0, 0x1, ''), -- Jaguero Stalker
-- (2522, 0, 0x0, 0x1, '22766'), -- Jaguero Stalker - Sneak
-- (2522, 0, 0x20000, 0x1, '22766'), -- Jaguero Stalker - Sneak
(2535, 0, 0x0, 0x1, ''), -- Maury "Club Foot" Wilkins
(2542, 0, 0x0, 0x1, ''), -- Catelyn the Blade
(2544, 0, 0x0, 0x1, ''), -- Southern Sand Crawler
(2545, 0, 0x0, 0x1, ''), -- "Pretty Boy" Duncan
(2546, 0, 0x0, 0x1, '83932'), -- Fleet Master Firallon - Summon Squawky Jr.
(2547, 0, 0x0, 0x1, '3637'), -- Ironpatch - Improved Blocking III
(2548, 0, 0x0, 0x1, ''), -- Captain Keelhaul
(2549, 0, 0x0, 0x1, ''), -- Garr Salthoof
(2551, 0, 0x0, 0x1, ''), -- Brutus
(2594, 0, 0x0, 0x1, ''), -- Sprogger
(2622, 0, 0x0, 0x1, ''), -- Sly Garrett
(2625, 0, 0x0, 0x1, ''), -- Viznik Goldgrubber
(2626, 0, 0x0, 0x1, ''), -- Old Man Heming
(2627, 0, 0x0, 0x1, ''), -- Grarnik Goodstitch
(2634, 0, 0x0, 0x1, ''), -- Princess Poobah
(2663, 0, 0x0, 0x1, ''), -- Narkk
(2664, 0, 0x0, 0x1, ''), -- Kelsey Yance
(2670, 0, 0x0, 0x1, ''), -- Xizk Goodstitch
(2672, 0, 0x0, 0x1, ''), -- Cowardly Crosby
(2685, 0, 0x0, 0x1, ''), -- Mazk Snipeshot
(2699, 0, 0x0, 0x1, ''), -- Rikqiz
(28180, 0, 0x0, 0x1, ''), -- [ph] Goblin Construction Crew
(2832, 0, 0x0, 0x1, ''), -- Nixxrax Fillamug
(2834, 0, 0x0, 0x1, ''), -- Myizz Luckycatch
(2836, 0, 0x0, 0x1, ''), -- Brikk Keencraft
(2837, 0, 0x0, 0x1, ''), -- Jaxin Chong
(2838, 0, 0x0, 0x1, ''), -- Crazk Sparks
(2839, 0, 0x0, 0x2, ''), -- Haren Kanmae
(2840, 0, 0x0, 0x1, ''), -- Kizz Bluntstrike
(2842, 0, 0x0, 0x1, ''), -- Wigcik
(2843, 0, 0x0, 0x1, ''), -- Jutak
(2844, 0, 0x0, 0x1, ''), -- Hurklor
(2845, 0, 0x0, 0x1, ''), -- Fargon Mortalak
(2846, 0, 0x0, 0x1, ''), -- Blixrez Goodstitch
(2847, 0, 0x0, 0x1, ''), -- Jansen Underwood
(2848, 0, 0x0, 0x1, ''), -- Glyx Brewright
(2849, 0, 0x0, 0x1, ''), -- Qixdi Goodstitch
(2858, 0, 0x0, 0x101, ''), -- Gringer
(2859, 0, 0x0, 0x100, ''), -- Gyll
(32520, 0, 0x0, 0x1, ''), -- Totally Generic Bunny (All Phase)
(37490, 0, 0x0, 0x1, ''), -- ELM General Purpose Bunny Infinite
(3945, 0, 0x0, 0x1, ''), -- Caravaneer Ruzzgot
(40728, 0, 0x0, 0x1, '54913'), -- Whale Shark - Thrash
(4075, 0, 0x0, 0x1, ''), -- Rat
(4076, 0, 0x0, 0x1, ''), -- Roach
(40987, 0, 0x0, 0x1, ''), -- Gnash
(42173, 0, 0x0, 0x1, ''), -- The Undershell Tentacle Flavor
(42196, 0, 0x0, 0x1, '78715'), -- ELM General Purpose Bunny Infinite (scale x2.5) - L'ghorek: Ascendant Light Beam
(42851, 0, 0x0, 0x1, '29266'), -- Revenant of Neptulon - Permanent Feign Death
(43359, 0, 0x0, 0x1, ''), -- ELM General Purpose Bunny Infinite Hide Body
(43364, 0, 0x0, 0x1, '78677'), -- Bloodsail Hooch-Hound - Cosmetic - Sleep Zzz Breakable
(43376, 0, 0x0, 0x1, ''), -- Freewheelin' Juntz Fitztittle
(43377, 0, 0x0, 0x1, ''), -- Ephram "Midriff" Moonfall
(43417, 0, 0x0, 0x1, ''), -- Skymane Bonobo
(43454, 0, 0x1, 0x1, ''), -- "Good-Boy" Bruce
(43504, 0, 0x0, 0x1, ''), -- Yancey Grillsen
(43505, 0, 0x0, 0x1, '81312'), -- Bossy - Self Stun Forever
(43536, 0, 0x0, 0x1, ''), -- Southsea Mako
(43556, 0, 0x0, 0x1, ''), -- "Dead-Eye" Drederick McGumm
(43560, 0, 0x0, 0x1, '46598'), -- Smilin' Timmy Sticks - Ride Vehicle Hardcoded
(43561, 0, 0x0, 0x1, ''), -- Bloodsail Rowboat
(43562, 0, 0x0, 0x1, ''), -- Ol' Blasty
(43596, 0, 0x3000000, 0x1, ''), -- Venture Co. Oil Worker
(43605, 0, 0x0, 0x1, ''), -- Bloodsail Oarsman
(43636, 0, 0x0, 0x1, ''), -- Bloodsail Corsair
(43659, 0, 0x0, 0x1, ''), -- Long John Copper
(43660, 0, 0x0, 0x1, ''), -- Enormous Shawn Stooker
(43661, 0, 0x0, 0x1, ''), -- Wailing Mary Smitts
(43849, 0, 0x0, 0x1, ''), -- Garley Lightrider
(43853, 0, 0x3000000, 0x1, ''), -- Bloodsail Buzzard
(44112, 0, 0x1, 0x1, '42871'), -- Airwyn Bantamflax - Cosmetic - Drink Tankard
(44140, 0, 0x0, 0x1, ''), -- PetWait Trigger
(44178, 0, 0x0, 0x1, ''), -- Sweet Gary Guns
(44179, 0, 0x0, 0x1, ''), -- Harry No-Hooks
(44182, 0, 0x0, 0x1, ''), -- Gurlgrl
(4505, 0, 0x0, 0x1, ''), -- Bloodsail Deckhand
-- (4505, 0, 0x0, 0x1, '78677'), -- Bloodsail Deckhand - Cosmetic - Sleep Zzz Breakable
(4506, 0, 0x0, 0x1, ''), -- Bloodsail Swabby
(45681, 0, 0x0, 0x1, ''), -- Garginox
(4624, 0, 0x0, 0x1, ''), -- Booty Bay Bruiser
(4631, 0, 0x0, 0x1, ''), -- Wharfmaster Lozgil
(47667, 0, 0x0, 0x1, ''), -- Wharf Rat
(48797, 0, 0x0, 0x1, '90948'), -- Gim'hila - Ogre Mage Diving Helmet(s)
(48808, 0, 0x0, 0x1, ''), -- Corporal Jeyne
(48972, 0, 0x0, 0x1, ''), -- Long-tailed Mole
(49635, 0, 0x0, 0x1, ''), -- War-Mage Erallier
(49636, 0, 0x0, 0x1, ''), -- Arcanist Arman
(49722, 0, 0x0, 0x1, ''), -- Tree Python
(49928, 0, 0x3000000, 0x1, ''), -- Crimson Moth
(50479, 0, 0x0, 0x1, ''), -- Lizard Hatchling
(50487, 0, 0x0, 0x1, ''), -- Forest Spiderling
(54232, 0, 0x0, 0x101, ''), -- Mrs. Gant
(54308, 0, 0x0, 0x1, ''), -- Kirsty Logan
(5434, 0, 0x0, 0x1, ''), -- Coral Shark
(54475, 0, 0x0, 0x1, ''), -- Crab
(6807, 0, 0x0, 0x1, ''), -- Innkeeper Skindle
(6827, 0, 0x0, 0x1, ''), -- Crab
(737, 0, 0x0, 0x1, ''), -- Kebok
(7389, 0, 0x3000000, 0x1, ''), -- Senegal
(7390, 0, 0x3000000, 0x1, ''), -- Cockatiel
(7406, 0, 0x0, 0x1, ''), -- Oglethorpe Obnoticus
(7794, 0, 0x0, 0x1, ''), -- McGavan
(8123, 0, 0x0, 0x1, ''), -- Rickle Goldgrubber
(908, 0, 0x0, 0x1, ''), -- Flora Silverwind
(9559, 0, 0x0, 0x1, ''), -- Grizzlowe
(9600, 0, 0x3000000, 0x1, ''), -- Parrot
(9858, 0, 0x0, 0x101, ''); -- Auctioneer Kresky

UPDATE `creature_model_info` SET `gender`=0 WHERE `modelid`=792;
UPDATE `creature_model_info` SET `gender`=0 WHERE `modelid`=809;
UPDATE `creature_model_info` SET `gender`=0 WHERE `modelid`=838;
UPDATE `creature_model_info` SET `gender`=0 WHERE `modelid`=844;
UPDATE `creature_model_info` SET `combat_reach`=0.9131355 WHERE `modelid`=1228;
UPDATE `creature_model_info` SET `gender`=0 WHERE `modelid`=2562;
UPDATE `creature_model_info` SET `gender`=0 WHERE `modelid`=2564;
UPDATE `creature_model_info` SET `bounding_radius`=0.21, `combat_reach`=0.3 WHERE `modelid`=4343;
UPDATE `creature_model_info` SET `bounding_radius`=0.7, `combat_reach`=0.875 WHERE `modelid`=5560;
UPDATE `creature_model_info` SET `gender`=0 WHERE `modelid`=6190;
UPDATE `creature_model_info` SET `gender`=0 WHERE `modelid`=6191;
UPDATE `creature_model_info` SET `gender`=0 WHERE `modelid`=10039;
UPDATE `creature_model_info` SET `bounding_radius`=1.6, `combat_reach`=2.4, `gender`=0 WHERE `modelid`=11566;
UPDATE `creature_model_info` SET `bounding_radius`=0.69, `combat_reach`=1.725 WHERE `modelid`=12192;
UPDATE `creature_model_info` SET `gender`=0 WHERE `modelid`=12812;
UPDATE `creature_model_info` SET `bounding_radius`=0.7, `combat_reach`=0.875 WHERE `modelid`=15921;
UPDATE `creature_model_info` SET `combat_reach`=0.75 WHERE `modelid`=22903;
UPDATE `creature_model_info` SET `bounding_radius`=0.347, `combat_reach`=1.5 WHERE `modelid`=25034;
UPDATE `creature_model_info` SET `bounding_radius`=0.305556 WHERE `modelid`=30180;
UPDATE `creature_model_info` SET `bounding_radius`=0.4513886, `combat_reach`=1.95, `gender`=0 WHERE `modelid`=33216;
UPDATE `creature_model_info` SET `bounding_radius`=1, `combat_reach`=7 WHERE `modelid`=33265;
UPDATE `creature_model_info` SET `bounding_radius`=0.389, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=33334;
UPDATE `creature_model_info` SET `bounding_radius`=0.347222, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=33377;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=33391;
UPDATE `creature_model_info` SET `bounding_radius`=0.347, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=33411;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=33458;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=33459;
UPDATE `creature_model_info` SET `bounding_radius`=0.208, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=33460;
UPDATE `creature_model_info` SET `bounding_radius`=0.383, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=33534;
UPDATE `creature_model_info` SET `bounding_radius`=0.3519, `combat_reach`=1.725, `gender`=1 WHERE `modelid`=33676;
UPDATE `creature_model_info` SET `bounding_radius`=0.208, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=36279;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=36571;
UPDATE `creature_model_info` SET `bounding_radius`=0.383, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=36572;
UPDATE `creature_model_info` SET `bounding_radius`=0.031, `combat_reach`=0.1 WHERE `modelid`=36599;
UPDATE `creature_model_info` SET `bounding_radius`=0.0875, `combat_reach`=0.25 WHERE `modelid`=36671;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=37595;
UPDATE `creature_model_info` SET `bounding_radius`=0.208, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=38697;
UPDATE `creature_model_info` SET `bounding_radius`=0.208, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=38745;

SET @CGUID := 19346;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+840;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 44140, 0, 1, 1, -9193.85, -2777.82, 90.63683, 0, 120, 0, 0), -- PetWait Trigger (Area: The Crystal Shore)
(@CGUID+1, 32520, 0, 1, 1, -8680.672, 730.7483, 159.0924, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+2, 32520, 0, 1, 1, -8290.094, 1388.641, 30.00427, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+3, 32520, 0, 1, 1, -8282.045, 1450.892, 0.3571493, 6.265732, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+4, 32520, 0, 1, 1, -7549.146, 2210.674, -0.01231566, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+5, 32520, 0, 1, 1, -7528.516, 2226.144, -0.01220667, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+6, 32520, 0, 1, 1, -7488.368, 2254.41, -0.01226167, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+7, 32520, 0, 1, 1, -7436.108, 2284.655, -0.01220667, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+8, 32520, 0, 1, 1, -7431.354, 2306.233, 0.2182883, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+9, 32520, 0, 1, 1, -7373.118, 2314.969, -0.01226167, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+10, 32520, 0, 1, 1, -7375.434, 2326.503, 0.2182883, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+11, 32520, 0, 1, 1, -7326.561, 2345.738, 0.2182883, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+12, 32520, 0, 1, 1, -7323.299, 2340.835, -0.01226167, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+13, 32520, 0, 1, 1, -7305.255, 2337.531, 0.2182883, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+14, 32520, 0, 1, 1, -7286.641, 2349.813, 0.2182883, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+15, 32520, 0, 1, 1, -7262.632, 2365.733, 0.2182883, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+16, 32520, 0, 1, 1, -7249.769, 2376.906, -0.01226167, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+17, 32520, 0, 1, 1, -7218.764, 2373.132, 0.2182883, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+18, 32520, 0, 1, 1, -7208.29, 2375.983, 0.2182883, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+19, 32520, 0, 1, 1, -7203.332, 2380.043, 0.2182883, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+20, 32520, 0, 1, 1, -7199.389, 2383.023, 0.2182883, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+21, 32520, 0, 1, 1, -7191.5, 2387.116, 0.2182883, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+22, 32520, 0, 1, 1, -7198.851, 2404.536, -0.01220667, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+23, 32520, 0, 1, 1, -7188.139, 2390.936, 0.2182883, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+24, 32520, 0, 1, 1, -7182.01, 2390.734, 0.2182883, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+25, 32520, 0, 1, 1, -7176.62, 2393.826, 0.2182883, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+26, 32520, 0, 1, 1, -7174.474, 2398.345, 0.2182883, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+27, 32520, 0, 1, 1, -7172.613, 2396.337, 0.2182883, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+28, 32520, 0, 1, 1, -7167.887, 2399.689, 0.2182883, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+29, 32520, 0, 1, 1, -7163.313, 2402.516, 0.2182883, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+30, 32520, 0, 1, 1, -7157.736, 2406.872, 0.2182883, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+31, 32520, 0, 1, 1, -7155.571, 2410.693, 0.2182883, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+32, 32520, 0, 1, 1, -7155.319, 2425.731, -0.01220667, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+33, 32520, 0, 1, 1, -7148.408, 2413.837, 0.2182883, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+34, 32520, 0, 1, 1, -7144.577, 2416.571, 0.2182883, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+35, 32520, 0, 1, 1, -7138.686, 2418.826, 0.2182883, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+36, 32520, 0, 1, 1, -7135.222, 2421.837, 0.2182883, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+37, 32520, 0, 1, 1, -7111.288, 2445.353, -0.01226167, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+38, 32520, 0, 1, 1, -7069.127, 2456.75, -0.01226167, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+39, 32520, 0, 1, 1, -7038.147, 2468.995, -0.01226167, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+40, 32520, 0, 1, 1, -7006.415, 2479.377, -0.01220667, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+41, 32520, 0, 1, 1, -6967.941, 2493.597, -0.01231566, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+42, 32520, 0, 1, 1, -6932.59, 2514.827, -0.01226167, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+43, 32520, 0, 1, 1, -6904.563, 2550.189, -0.01225267, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+44, 32520, 0, 1, 1, -6865.792, 2562.302, -0.01225267, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+45, 40728, 0, 1, 1, -7638.945, 5030.951, -180.1269, 1.510604, 120, 0, 0), -- Whale Shark (Area: The Crystal Shore)
(@CGUID+46, 40728, 0, 1, 1, -6190.179, 4111.093, -260.4893, 2.051528, 120, 0, 0), -- Whale Shark (Area: The Crystal Shore)
(@CGUID+47, 40728, 0, 1, 1, -5628.384, 3210.452, -61.88317, 3.049114, 120, 0, 0), -- Whale Shark (Area: The Crystal Shore)
(@CGUID+48, 32520, 0, 1, 1, -5136.05, 3277.62, -118.3217, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+49, 42851, 0, 1, 1, -6184.12, 5397.069, -1216.32, 0, 120, 0, 0), -- Revenant of Neptulon (Area: The Crystal Shore)
(@CGUID+50, 32520, 0, 1, 1, -6305.162, 5582.533, -1172.063, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+51, 40987, 0, 1, 1, -4928.148, 3559.719, -120.2857, 0.3014649, 120, 0, 0), -- Gnash (Area: The Crystal Shore) (possible waypoints or random movement)
(@CGUID+52, 42851, 0, 1, 1, -6226.069, 5512.124, -1215.753, 0, 120, 0, 0), -- Revenant of Neptulon (Area: The Crystal Shore)
(@CGUID+53, 42851, 0, 1, 1, -6079.696, 5338.495, -1215.58, 0, 120, 0, 0), -- Revenant of Neptulon (Area: The Crystal Shore)
(@CGUID+54, 42851, 0, 1, 1, -5972.122, 5222.906, -1208.386, 0, 120, 0, 0), -- Revenant of Neptulon (Area: The Crystal Shore)
(@CGUID+55, 42851, 0, 1, 1, -6133.175, 5494.254, -1215.137, 0, 120, 0, 0), -- Revenant of Neptulon (Area: The Crystal Shore)
(@CGUID+56, 32520, 0, 1, 1, -6148.39, 5539.97, -1207.787, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+57, 42851, 0, 1, 1, -5862.793, 5175.958, -1213.582, 0, 120, 0, 0), -- Revenant of Neptulon (Area: The Crystal Shore)
(@CGUID+58, 42851, 0, 1, 1, -5982.469, 5345.316, -1218.424, 0, 120, 0, 0), -- Revenant of Neptulon (Area: The Crystal Shore)
(@CGUID+59, 42851, 0, 1, 1, -6043.141, 5439.757, -1219.116, 0, 120, 0, 0), -- Revenant of Neptulon (Area: The Crystal Shore)
(@CGUID+60, 42851, 0, 1, 1, -6180.118, 5660.041, -1217.356, 0, 120, 0, 0), -- Revenant of Neptulon (Area: The Crystal Shore)
(@CGUID+61, 32520, 0, 1, 1, -6014.71, 5479.63, -1208.007, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+62, 42851, 0, 1, 1, -5863.936, 5310.616, -1222.713, 0, 120, 0, 0), -- Revenant of Neptulon (Area: The Crystal Shore)
(@CGUID+63, 42851, 0, 1, 1, -6089.413, 5608.077, -1223.85, 0, 120, 0, 0), -- Revenant of Neptulon (Area: The Crystal Shore)
(@CGUID+64, 42851, 0, 1, 1, -5732.877, 5152.973, -1222.141, 0, 120, 0, 0), -- Revenant of Neptulon (Area: The Crystal Shore)
(@CGUID+65, 32520, 0, 1, 1, -5851.79, 5397.15, -1217.167, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+66, 32520, 0, 1, 1, -4660.958, 3559.71, -113.9472, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+67, 42851, 0, 1, 1, -5966.031, 5563.699, -1218.418, 0, 120, 0, 0), -- Revenant of Neptulon (Area: The Crystal Shore)
(@CGUID+68, 42851, 0, 1, 1, -6005.035, 5671.134, -1219.748, 0, 120, 0, 0), -- Revenant of Neptulon (Area: The Crystal Shore)
(@CGUID+69, 42851, 0, 1, 1, -5616.425, 5177.916, -1226.32, 0, 120, 0, 0), -- Revenant of Neptulon (Area: The Crystal Shore)
(@CGUID+70, 42851, 0, 1, 1, -5812.905, 5495.367, -1231.447, 0, 120, 0, 0), -- Revenant of Neptulon (Area: The Crystal Shore)
(@CGUID+71, 42851, 0, 1, 1, -5867.2, 5622.304, -1230.413, 0, 120, 0, 0), -- Revenant of Neptulon (Area: The Crystal Shore)
(@CGUID+72, 32520, 0, 1, 1, -4659.649, 3841.258, -3.712333, 3.159046, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+73, 32520, 0, 1, 1, -4657.863, 3872.089, -4.775842, 3.124139, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+74, 32520, 0, 1, 1, -4621.934, 3811.015, -2.434516, 2.530727, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+75, 42851, 0, 1, 1, -5559.231, 5246.39, -1228.137, 5.654867, 120, 0, 0), -- Revenant of Neptulon (Area: The Crystal Shore)
(@CGUID+76, 32520, 0, 1, 1, -4607.887, 3846.321, -4.775842, 3.124139, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+77, 42851, 0, 1, 1, -5717.965, 5538.276, -1237.856, 0, 120, 0, 0), -- Revenant of Neptulon (Area: The Crystal Shore)
(@CGUID+78, 32520, 0, 1, 1, -4599.307, 3875.44, -3.693974, 3.159046, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+79, 32520, 0, 1, 1, -5691.65, 5556.92, -1154.687, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+80, 32520, 0, 1, 1, -5691.65, 5556.92, -1154.687, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+81, 32520, 0, 1, 1, -4617.3, 3981.36, -70.50646, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+82, 32520, 0, 1, 1, -4616.33, 3983.89, -70.31406, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+83, 32520, 0, 1, 1, -4614.15, 3980.53, -70.68576, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+84, 32520, 0, 1, 1, -4609.82, 3981.23, -70.54346, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+85, 32520, 0, 1, 1, -4607.62, 3984.2, -70.64417, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+86, 32520, 0, 1, 1, -4608.13, 3987.51, -70.37226, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+87, 32520, 0, 1, 1, -4605.043, 3983.192, -70.56809, 3.543018, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+88, 37490, 0, 1, 1, -6654.488, 6736.202, -811.036, 0, 120, 0, 0), -- ELM General Purpose Bunny Infinite (Area: The Crystal Shore)
(@CGUID+89, 42851, 0, 1, 1, -5507.115, 5337.032, -1227.3, 0, 120, 0, 0), -- Revenant of Neptulon (Area: The Crystal Shore)
(@CGUID+90, 42851, 0, 1, 1, -5561.573, 5486.054, -1233.133, 0, 120, 0, 0), -- Revenant of Neptulon (Area: The Crystal Shore)
(@CGUID+91, 32520, 0, 1, 1, -4461.703, 3807.523, -82.83333, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Crystal Shore)
(@CGUID+92, 42173, 0, 1, 1, -6446.698, 6829.101, -1124.952, 1.27409, 120, 0, 0), -- The Undershell Tentacle Flavor (Area: The Crystal Shore)
(@CGUID+93, 42196, 0, 1, 1, -6423.21, 6884, -786.6007, 0, 120, 0, 0), -- ELM General Purpose Bunny Infinite (scale x2.5) (Area: The Crystal Shore)
(@CGUID+94, 42196, 0, 1, 1, -6422.48, 6884.6, -870.8707, 0, 120, 0, 0), -- ELM General Purpose Bunny Infinite (scale x2.5) (Area: The Crystal Shore)
(@CGUID+95, 42173, 0, 1, 1, -6230.174, 6798.166, -1075.454, 6.143559, 120, 0, 0), -- The Undershell Tentacle Flavor (Area: The Crystal Shore)
(@CGUID+96, 42173, 0, 1, 1, -6396.681, 7054.327, -1069.238, 3.071779, 120, 0, 0), -- The Undershell Tentacle Flavor (Area: The Crystal Shore)
(@CGUID+97, 37490, 0, 1, 1, -6353.474, 7151.508, -807.5332, 0, 120, 0, 0), -- ELM General Purpose Bunny Infinite (Area: The Crystal Shore)
(@CGUID+98, 43359, 0, 1, 1, 2298.788, 280.1181, 76.27024, 0, 120, 0, 0), -- ELM General Purpose Bunny Infinite Hide Body (Area: The Crystal Shore)
(@CGUID+99, 45681, 0, 1, 1, 2714.68, -5475.37, 157.6249, 2.617994, 120, 0, 0), -- Garginox (Area: The Crystal Shore) (possible waypoints or random movement)
(@CGUID+100, 43596, 0, 1, 1, -13932.5, -375.281, 37.68913, 5.462881, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+101, 43596, 0, 1, 1, -13931.8, -376.939, 38.19763, 0.9948376, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+102, 43596, 0, 1, 1, -13930.9, -377.535, 38.05483, 1.972222, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+103, 43596, 0, 1, 1, -13909, -359.536, 31.33173, 3.630285, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+104, 43596, 0, 1, 1, -13929.7, -362.582, 37.58533, 0.8901179, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+105, 43596, 0, 1, 1, -13928.2, -355.344, 37.69553, 5.951573, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+106, 43596, 0, 1, 1, -13931.2, -350.943, 34.34253, 2.513274, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+107, 43596, 0, 1, 1, -13915.1, -352.036, 37.16523, 3.961897, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+108, 43596, 0, 1, 1, -13931.9, -353.42, 38.74823, 2.984513, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+109, 43596, 0, 1, 1, -13921, -355.889, 40.19423, 3.193953, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+110, 43596, 0, 1, 1, -13926.9, -358.031, 39.33403, 0.4363323, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+111, 43596, 0, 1, 1, -13917.1, -354.03, 36.64023, 3.839724, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+112, 43596, 0, 1, 1, -13923.2, -352.642, 33.12623, 4.747295, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+113, 43596, 0, 1, 1, -13925.5, -356.33, 39.43233, 5.201081, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+114, 43596, 0, 1, 1, -13928.6, -353.988, 33.32153, 5.986479, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+115, 43596, 0, 1, 1, -13924.1, -355.635, 39.49293, 4.520403, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+116, 43596, 0, 1, 1, -13918.3, -336.559, 27.93043, 4.729842, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+117, 43596, 0, 1, 1, -13919.5, -337.363, 27.86253, 5.550147, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+118, 43596, 0, 1, 1, -13919.4, -346.417, 32.42733, 0.6981317, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+119, 43596, 0, 1, 1, -13922.7, -351.745, 33.10163, 4.572762, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+120, 43596, 0, 1, 1, -13939.8, -345.464, 21.13933, 6.126106, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+121, 43596, 0, 1, 1, -13943.7, -351.726, 17.80713, 0.541052, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+122, 43596, 0, 1, 1, -13938.9, -344.587, 20.87533, 5.497787, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+123, 43596, 0, 1, 1, -13942.9, -349.875, 17.93513, 5.235988, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+124, 43596, 0, 1, 1, -13937.28, -344.4358, 20.55093, 4.276057, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+125, 43596, 0, 1, 1, -13986.8, -276.271, 71.11474, 4.886922, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+126, 43596, 0, 1, 1, -13978.2, -276.755, 72.09614, 3.822271, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+127, 43596, 0, 1, 1, -13981.2, -279.465, 72.10354, 3.246312, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+128, 43596, 0, 1, 1, -13986.2, -280.411, 72.05704, 0.2094395, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+129, 43596, 0, 1, 1, -13983.6, -279.073, 71.11484, 1.570796, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+130, 43596, 0, 1, 1, -13981.9, -277.651, 71.11484, 4.677482, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+131, 43596, 0, 1, 1, -13985.3, -278.378, 71.11484, 2.86234, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+132, 43596, 0, 1, 1, -13985.2, -284.55, 33.66543, 0.8901179, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+133, 43596, 0, 1, 1, -13988.5, -285.417, 33.67193, 2.408554, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+134, 43596, 0, 1, 1, -13986.6, -277.172, 32.70793, 4.642576, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+135, 43596, 0, 1, 1, -13985.9, -279.304, 32.70793, 3.420845, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+136, 43596, 0, 1, 1, -13984.7, -280.674, 32.70793, 6.230825, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+137, 43596, 0, 1, 1, -13988.3, -281.953, 32.70793, 0.9948376, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+138, 43596, 0, 1, 1, -13984.5, -278.144, 32.70793, 0.296706, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+139, 43596, 0, 1, 1, -13986.1, -281.177, 32.70793, 1.954769, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+140, 6827, 0, 1, 1, -13813.04, -242.0336, 0.7232885, 3.27079, 120, 0, 0), -- Crab (Area: The Crystal Shore)
(@CGUID+141, 2535, 0, 1, 1, -13813.16, -240.4983, 0.9547338, 2.156135, 120, 0, 0), -- Maury "Club Foot" Wilkins (Area: The Crystal Shore) (possible waypoints or random movement)
(@CGUID+142, 15475, 0, 1, 1, -13837.63, -187.0944, 19.47429, 2.47009, 120, 0, 0), -- Beetle (Area: The Crystal Shore)
(@CGUID+143, 50487, 0, 1, 1, -13827.03, -176.144, 14.71605, 2.543834, 120, 0, 0), -- Forest Spiderling (Area: The Crystal Shore) (possible waypoints or random movement)
(@CGUID+144, 1489, 0, 1, 1, -13796, -245.7384, 0.5963974, 3.905726, 120, 0, 0), -- Zanzil Hunter (Area: The Crystal Shore)
(@CGUID+145, 43377, 0, 1, 1, -13823.08, -134.8961, 16.90284, 5.10703, 120, 0, 0), -- Ephram "Midriff" Moonfall (Area: The Crystal Shore) (possible waypoints or random movement)
(@CGUID+146, 2544, 0, 1, 1, -13965.1, -142.1882, 1.629806, 6.275373, 120, 0, 0), -- Southern Sand Crawler (Area: The Crystal Shore)
(@CGUID+147, 1558, 0, 1, 1, -13893.56, -101.8385, 13.11133, 1.81151, 120, 0, 0), -- Silverback Patriarch (Area: The Crystal Shore)
(@CGUID+148, 1558, 0, 1, 1, -13872.44, -89.06109, 18.87778, 3.543149, 120, 0, 0), -- Silverback Patriarch (Area: The Crystal Shore)
(@CGUID+149, 1558, 0, 1, 1, -13826.99, -63.81337, 56.73749, 5.610224, 120, 0, 0), -- Silverback Patriarch (Area: The Crystal Shore)
(@CGUID+150, 1558, 0, 1, 1, -13858.52, -44.3738, 40.02944, 3.688382, 120, 0, 0), -- Silverback Patriarch (Area: The Crystal Shore)
(@CGUID+151, 1558, 0, 1, 1, -13857.64, -42.56517, 41.65622, 5.44114, 120, 0, 0), -- Silverback Patriarch (Area: The Crystal Shore)
(@CGUID+152, 1558, 0, 1, 1, -13853.94, -104.1125, 14.85294, 2.836957, 120, 0, 0), -- Silverback Patriarch (Area: The Crystal Shore)
(@CGUID+153, 1557, 0, 1, 1, -13918.44, -10.66016, 31.13289, 4.455563, 120, 0, 0), -- Elder Mistvale Gorilla (Area: The Crystal Shore)
(@CGUID+154, 1558, 0, 1, 1, -13861.98, -18.75, 50.22608, 4.712389, 120, 0, 0), -- Silverback Patriarch (Area: The Crystal Shore)
(@CGUID+155, 1557, 0, 1, 1, -13957.1, 13.54102, 16.50816, 0, 120, 0, 0), -- Elder Mistvale Gorilla (Area: The Crystal Shore)
(@CGUID+156, 49928, 0, 1, 1, -13888.56, 24.08858, 25.1796, 1.141461, 120, 0, 0), -- Crimson Moth (Area: The Crystal Shore)
(@CGUID+157, 1557, 0, 1, 1, -13881.83, 63.96581, 16.57021, 4.592883, 120, 0, 0), -- Elder Mistvale Gorilla (Area: The Crystal Shore)
(@CGUID+158, 1557, 0, 1, 1, -13897.33, 53.80749, 14.68898, 5.720652, 120, 0, 0), -- Elder Mistvale Gorilla (Area: The Crystal Shore)
(@CGUID+159, 49928, 0, 1, 1, -13909.55, 38.94209, 43.97288, 1.109092, 120, 0, 0), -- Crimson Moth (Area: The Crystal Shore)
(@CGUID+160, 49722, 0, 1, 1, -13832.38, 3.055015, 21.25651, 5.880008, 120, 0, 0), -- Tree Python (Area: The Crystal Shore) (possible waypoints or random movement)
(@CGUID+161, 1557, 0, 1, 1, -13842.09, 38.06055, 26.95806, 1.781208, 120, 0, 0), -- Elder Mistvale Gorilla (Area: The Crystal Shore)
(@CGUID+162, 50479, 0, 1, 1, -13797.64, 2.597922, 31.71695, 2.55359, 120, 0, 0), -- Lizard Hatchling (Area: The Crystal Shore)
(@CGUID+163, 49928, 0, 1, 1, -13921.26, 79.77019, 30.43675, 1.001945, 120, 0, 0), -- Crimson Moth (Area: The Crystal Shore)
(@CGUID+164, 50487, 0, 1, 1, -13958.84, 89.45601, 15.6264, 3.899435, 120, 0, 0), -- Forest Spiderling (Area: The Crystal Shore) (possible waypoints or random movement)
(@CGUID+165, 1557, 0, 1, 1, -13924.99, 108.119, 15.17492, 4.698718, 120, 0, 0), -- Elder Mistvale Gorilla (Area: The Crystal Shore)
(@CGUID+166, 1557, 0, 1, 1, -13941.48, 92.59238, 15.50921, 0.5565802, 120, 0, 0), -- Elder Mistvale Gorilla (Area: The Crystal Shore)
(@CGUID+167, 15475, 0, 1, 1, -13870.36, 129.8211, 14.85186, 6.15933, 120, 0, 0), -- Beetle (Area: The Crystal Shore)
(@CGUID+168, 15475, 0, 1, 1, -13831.07, 67.81316, 23.9542, 6.277326, 120, 0, 0), -- Beetle (Area: The Crystal Shore)
(@CGUID+169, 1557, 0, 1, 1, -13815.87, 77.3408, 26.40154, 5.591838, 120, 0, 0), -- Elder Mistvale Gorilla (Area: The Crystal Shore)
(@CGUID+170, 1557, 0, 1, 1, -13850.22, 111.7984, 19.37788, 0.2948045, 120, 0, 0), -- Elder Mistvale Gorilla (Area: The Crystal Shore)
(@CGUID+171, 9600, 0, 1, 1, -13799.12, 115.0778, 56.79708, 1.816529, 120, 0, 0), -- Parrot (Area: The Crystal Shore)
(@CGUID+172, 1557, 0, 1, 1, -13782.01, 128.1217, 22.36554, 4.763802, 120, 0, 0), -- Elder Mistvale Gorilla (Area: Mistvale Valley)
(@CGUID+173, 49722, 0, 1, 1, -13917.53, 247.0026, 14.33747, 5.525404, 120, 0, 0), -- Tree Python (Area: Mistvale Valley) (possible waypoints or random movement)
(@CGUID+174, 1557, 0, 1, 1, -13945.82, 225.8266, 15.18046, 1.152815, 120, 0, 0), -- Elder Mistvale Gorilla (Area: Mistvale Valley)
(@CGUID+175, 1557, 0, 1, 1, -13967.97, 146.7593, 16.32294, 5.683814, 120, 0, 0), -- Elder Mistvale Gorilla (Area: Mistvale Valley)
(@CGUID+176, 49928, 0, 1, 1, -13892.04, 254.9151, 40.70603, 1.497103, 120, 0, 0), -- Crimson Moth (Area: Mistvale Valley)
(@CGUID+177, 50487, 0, 1, 1, -13824.89, 226.3902, 18.92903, 1.325539, 120, 0, 0), -- Forest Spiderling (Area: Mistvale Valley) (possible waypoints or random movement)
(@CGUID+178, 15475, 0, 1, 1, -13958.13, 295.1212, 15.73347, 4.465991, 120, 0, 0), -- Beetle (Area: Cape of Stranglethorn)
(@CGUID+179, 49928, 0, 1, 1, -13975.13, 296.0058, 33.52986, 2.681871, 120, 0, 0), -- Crimson Moth (Area: Cape of Stranglethorn)
(@CGUID+180, 43504, 0, 1, 1, -14004.5, 378.8, 30.94173, 5.986479, 120, 0, 0), -- Yancey Grillsen (Area: Cape of Stranglethorn)
(@CGUID+181, 49928, 0, 1, 1, -13998.18, 344.196, 59.82454, 2.185473, 120, 0, 0), -- Crimson Moth (Area: Cape of Stranglethorn)
(@CGUID+182, 1907, 0, 1, 1, -13908.32, 420.1231, 98.95341, 2.644894, 120, 0, 0), -- Naga Explorer (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+183, 1907, 0, 1, 1, -13914.18, 436.4487, 101.2453, 4.664501, 120, 0, 0), -- Naga Explorer (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+184, 1907, 0, 1, 1, -13879.82, 503.8023, 95.71312, 0.8544949, 120, 0, 0), -- Naga Explorer (Area: Nek'mani Wellspring) (possible waypoints or random movement)
(@CGUID+185, 49722, 0, 1, 1, -13987.17, 488.4124, 40.86675, 3.508975, 120, 0, 0), -- Tree Python (Area: Nek'mani Wellspring) (possible waypoints or random movement)
(@CGUID+186, 1907, 0, 1, 1, -13842.17, 432.1875, 90.23026, 2.164208, 120, 0, 0), -- Naga Explorer (Area: Nek'mani Wellspring)
(@CGUID+187, 1907, 0, 1, 1, -13866.55, 432.1611, 92.30354, 2.705482, 120, 0, 0), -- Naga Explorer (Area: Nek'mani Wellspring) (possible waypoints or random movement)
(@CGUID+188, 1907, 0, 1, 1, -13842.87, 454.4686, 91.95396, 6.230799, 120, 0, 0), -- Naga Explorer (Area: Nek'mani Wellspring) (possible waypoints or random movement)
(@CGUID+189, 1907, 0, 1, 1, -13818.88, 442.4364, 90.77467, 0.786481, 120, 0, 0), -- Naga Explorer (Area: Nek'mani Wellspring) (possible waypoints or random movement)
(@CGUID+190, 1907, 0, 1, 1, -13852.91, 487.2254, 92.82566, 3.463258, 120, 0, 0), -- Naga Explorer (Area: Nek'mani Wellspring) (possible waypoints or random movement)
(@CGUID+191, 6827, 0, 1, 1, -13950.8, 616.6115, 3.383706, 6.096763, 120, 0, 0), -- Crab (Area: Cape of Stranglethorn)
(@CGUID+192, 1561, 0, 1, 1, -13981.34, 581.6852, 6.854999, 2.364482, 120, 0, 0), -- Bloodsail Raider (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+193, 1907, 0, 1, 1, -13877.72, 621.3737, 24.13247, 0.7414317, 120, 0, 0), -- Naga Explorer (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+194, 6827, 0, 1, 1, -13991.67, 575, 6.480487, 4.81529, 120, 0, 0), -- Crab (Area: Cape of Stranglethorn)
(@CGUID+195, 49722, 0, 1, 1, -13842.3, 540.5751, 48.5812, 4.386831, 120, 0, 0), -- Tree Python (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+196, 1907, 0, 1, 1, -13845.39, 587.0242, 47.04202, 6.246878, 120, 0, 0), -- Naga Explorer (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+197, 1493, 0, 1, 1, -14239.91, 735.141, 1.40184, 3.069834, 120, 0, 0), -- Mok'rash (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+198, 6827, 0, 1, 1, -13966.67, 645.7168, 0.4951029, 0.3823199, 120, 0, 0), -- Crab (Area: Cape of Stranglethorn)
(@CGUID+199, 1907, 0, 1, 1, -13923.39, 654.449, 8.559561, 2.968732, 120, 0, 0), -- Naga Explorer (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+200, 6827, 0, 1, 1, -13958.53, 659.1394, 1.055336, 5.7575, 120, 0, 0), -- Crab (Area: Cape of Stranglethorn)
(@CGUID+201, 49722, 0, 1, 1, -13861.54, 636.3004, 14.41517, 3.728907, 120, 0, 0), -- Tree Python (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+202, 1907, 0, 1, 1, -13858.11, 647.1324, 12.933, 0.09986316, 120, 0, 0), -- Naga Explorer (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+203, 1907, 0, 1, 1, -13883.03, 683.0291, 9.210789, 4.699884, 120, 0, 0), -- Naga Explorer (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+204, 6827, 0, 1, 1, -13919.59, 676.8961, 6.070325, 3.127922, 120, 0, 0), -- Crab (Area: Cape of Stranglethorn)
(@CGUID+205, 6827, 0, 1, 1, -13828.99, 686.7783, 4.309707, 1.766443, 120, 0, 0), -- Crab (Area: Cape of Stranglethorn)
(@CGUID+206, 6827, 0, 1, 1, -13861.98, 688.4153, 4.42584, 0.550008, 120, 0, 0), -- Crab (Area: Cape of Stranglethorn)
(@CGUID+207, 1907, 0, 1, 1, -13819.14, 685.1901, 3.703994, 2.170719, 120, 0, 0), -- Naga Explorer (Area: Southern Savage Coast) (possible waypoints or random movement)
(@CGUID+208, 32520, 0, 1, 1, -6014.71, 5479.63, -1208.007, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Southern Savage Coast)
(@CGUID+209, 32520, 0, 1, 1, -6148.39, 5539.97, -1207.787, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Southern Savage Coast)
(@CGUID+210, 32520, 0, 1, 1, -6305.162, 5582.533, -1172.063, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Southern Savage Coast)
(@CGUID+211, 32520, 0, 1, 1, -5691.65, 5556.92, -1154.687, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Southern Savage Coast)
(@CGUID+212, 1562, 0, 1, 1, -14028.76, 556.5814, 6.197622, 3.370001, 120, 0, 0), -- Bloodsail Mage (Area: Southern Savage Coast) (possible waypoints or random movement)
(@CGUID+213, 6827, 0, 1, 1, -14034.14, 550.4035, 6.156918, 4.968409, 120, 0, 0), -- Crab (Area: Southern Savage Coast)
(@CGUID+214, 1561, 0, 1, 1, -14040.94, 510.5838, 2.97009, 1.739016, 120, 0, 0), -- Bloodsail Raider (Area: Southern Savage Coast) (possible waypoints or random movement)
(@CGUID+215, 1562, 0, 1, 1, -14041.2, 517.639, 3.672482, 1.210191, 120, 0, 0), -- Bloodsail Mage (Area: Southern Savage Coast) (possible waypoints or random movement)
(@CGUID+216, 9600, 0, 1, 1, -14048.9, 449.1118, 40.33038, 3.787772, 120, 0, 0), -- Parrot (Area: Southern Savage Coast)
(@CGUID+217, 50479, 0, 1, 1, -14008.96, 236.6517, 13.6458, 4.659601, 120, 0, 0), -- Lizard Hatchling (Area: Cape of Stranglethorn)
(@CGUID+218, 15475, 0, 1, 1, -14055.68, 264.0146, 18.69695, 5.497904, 120, 0, 0), -- Beetle (Area: Cape of Stranglethorn)
(@CGUID+219, 15475, 0, 1, 1, -14009.21, 128.736, 12.76219, 6.062823, 120, 0, 0), -- Beetle (Area: Cape of Stranglethorn)
(@CGUID+220, 9600, 0, 1, 1, -13972.45, 125.984, 28.47753, 3.050838, 120, 0, 0), -- Parrot (Area: Cape of Stranglethorn)
(@CGUID+221, 50479, 0, 1, 1, -14051.05, 226.036, 13.26573, 4.246996, 120, 0, 0), -- Lizard Hatchling (Area: Cape of Stranglethorn)
(@CGUID+222, 1557, 0, 1, 1, -14010.55, 172.3841, 11.29894, 6.075934, 120, 0, 0), -- Elder Mistvale Gorilla (Area: Cape of Stranglethorn)
(@CGUID+223, 1557, 0, 1, 1, -14008.57, 210.5232, 14.15915, 1.283988, 120, 0, 0), -- Elder Mistvale Gorilla (Area: Cape of Stranglethorn)
(@CGUID+224, 1557, 0, 1, 1, -14016.09, 180.6942, 12.34446, 4.724107, 120, 0, 0), -- Elder Mistvale Gorilla (Area: Cape of Stranglethorn)
(@CGUID+225, 49928, 0, 1, 1, -14012.24, 163.4666, 34.56481, 0.6096745, 120, 0, 0), -- Crimson Moth (Area: Cape of Stranglethorn)
(@CGUID+226, 1557, 0, 1, 1, -14014.26, 146.4247, 13.60694, 3.845098, 120, 0, 0), -- Elder Mistvale Gorilla (Area: Cape of Stranglethorn)
(@CGUID+227, 1557, 0, 1, 1, -14036.87, 63.31904, 17.55669, 0.426084, 120, 0, 0), -- Elder Mistvale Gorilla (Area: Mistvale Valley)
(@CGUID+228, 1557, 0, 1, 1, -14022.63, 79.45776, 10.45919, 2.264954, 120, 0, 0), -- Elder Mistvale Gorilla (Area: Mistvale Valley)
(@CGUID+229, 1557, 0, 1, 1, -14029.92, 124.7769, 11.14557, 0.2388147, 120, 0, 0), -- Elder Mistvale Gorilla (Area: Mistvale Valley)
(@CGUID+230, 1557, 0, 1, 1, -14005.92, 25.81322, 31.49429, 1.035405, 120, 0, 0), -- Elder Mistvale Gorilla (Area: Mistvale Valley)
(@CGUID+231, 1557, 0, 1, 1, -13988.71, 95.44839, 13.06428, 2.891082, 120, 0, 0), -- Elder Mistvale Gorilla (Area: Mistvale Valley)
(@CGUID+232, 1557, 0, 1, 1, -13985.74, 48.34706, 17.90078, 3.455314, 120, 0, 0), -- Elder Mistvale Gorilla (Area: Mistvale Valley)
(@CGUID+233, 43376, 0, 1, 1, -13952.5, -126.22, 3.909201, 6.038704, 120, 0, 0), -- Freewheelin' Juntz Fitztittle (Area: Mistvale Valley) (possible waypoints or random movement)
(@CGUID+234, 43596, 0, 1, 1, -14148.5, -248.094, 65.11184, 3.647738, 120, 0, 0), -- Venture Co. Oil Worker (Area: Cape of Stranglethorn)
(@CGUID+235, 43596, 0, 1, 1, -14151, -244.292, 64.16833, 5.497787, 120, 0, 0), -- Venture Co. Oil Worker (Area: Cape of Stranglethorn)
(@CGUID+236, 43596, 0, 1, 1, -14149.7, -247.118, 64.16843, 0.8028514, 120, 0, 0), -- Venture Co. Oil Worker (Area: Cape of Stranglethorn)
(@CGUID+237, 43596, 0, 1, 1, -14150.8, -246.052, 64.16843, 6.126106, 120, 0, 0), -- Venture Co. Oil Worker (Area: Cape of Stranglethorn)
(@CGUID+238, 43596, 0, 1, 1, -14152.1, -248.139, 64.16824, 5.393067, 120, 0, 0), -- Venture Co. Oil Worker (Area: Cape of Stranglethorn)
(@CGUID+239, 43596, 0, 1, 1, -14148, -241.854, 25.94903, 4.206244, 120, 0, 0), -- Venture Co. Oil Worker (Area: Cape of Stranglethorn)
(@CGUID+240, 43596, 0, 1, 1, -14156, -245.061, 64.16843, 2.251475, 120, 0, 0), -- Venture Co. Oil Worker (Area: Cape of Stranglethorn)
(@CGUID+241, 43596, 0, 1, 1, -14147.4, -244.134, 25.94913, 3.176499, 120, 0, 0), -- Venture Co. Oil Worker (Area: Cape of Stranglethorn)
(@CGUID+242, 43596, 0, 1, 1, -14157, -246.58, 64.16824, 3.211406, 120, 0, 0), -- Venture Co. Oil Worker (Area: Cape of Stranglethorn)
(@CGUID+243, 43596, 0, 1, 1, -14155.9, -249.049, 65.13293, 6.126106, 120, 0, 0), -- Venture Co. Oil Worker (Area: Cape of Stranglethorn)
(@CGUID+244, 43596, 0, 1, 1, -14150.4, -244.293, 25.94913, 6.021386, 120, 0, 0), -- Venture Co. Oil Worker (Area: Cape of Stranglethorn)
(@CGUID+245, 43596, 0, 1, 1, -14148.1, -248.313, 26.91283, 3.071779, 120, 0, 0), -- Venture Co. Oil Worker (Area: Cape of Stranglethorn)
(@CGUID+246, 43596, 0, 1, 1, -14149.2, -246.415, 25.94913, 1.937315, 120, 0, 0), -- Venture Co. Oil Worker (Area: Cape of Stranglethorn)
(@CGUID+247, 43596, 0, 1, 1, -14153.3, -245.073, 26.90963, 1.396263, 120, 0, 0), -- Venture Co. Oil Worker (Area: Cape of Stranglethorn)
(@CGUID+248, 43596, 0, 1, 1, -14151.4, -248.049, 26.90543, 6.213372, 120, 0, 0), -- Venture Co. Oil Worker (Area: Cape of Stranglethorn)
(@CGUID+249, 43596, 0, 1, 1, -14138.9, -391.703, 60.92373, 1.867502, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+250, 43596, 0, 1, 1, -14155.6, -369.531, 67.71544, 2.513274, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+251, 43596, 0, 1, 1, -14145.3, -365.304, 65.71074, 5.305801, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+252, 43596, 0, 1, 1, -14156.3, -371.63, 67.48383, 3.735005, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+253, 43596, 0, 1, 1, -14142.9, -371.872, 67.24004, 5.044002, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+254, 43596, 0, 1, 1, -14158.9, -363.773, 63.86843, 5.270895, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+255, 43596, 0, 1, 1, -14157.3, -370.444, 67.86844, 6.126106, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+256, 43596, 0, 1, 1, -14156.7, -369.099, 67.85064, 5.096361, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+257, 43596, 0, 1, 1, -14154.4, -364.076, 62.98323, 4.08407, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+258, 43596, 0, 1, 1, -14148.5, -359.915, 65.98334, 2.181662, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+259, 43596, 0, 1, 1, -14156.5, -363.866, 63.35793, 4.660029, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+260, 43596, 0, 1, 1, -14154, -364.198, 48.12753, 3.612832, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+261, 43596, 0, 1, 1, -14150, -359.415, 48.52633, 1.256637, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+262, 43596, 0, 1, 1, -14131.7, -386.583, 66.93304, 2.548181, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+263, 43596, 0, 1, 1, -14131.4, -378.269, 62.88633, 3.193953, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+264, 43596, 0, 1, 1, -14148.7, -399.46, 60.14393, 0.9948376, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+265, 43596, 0, 1, 1, -14166.2, -376.514, 50.79133, 4.45059, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+266, 43596, 0, 1, 1, -14162.5, -366.783, 64.13194, 6.248279, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+267, 43596, 0, 1, 1, -14160.8, -365.226, 63.96933, 6.143559, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+268, 43596, 0, 1, 1, -14164.1, -373.677, 51.84783, 0.6806784, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+269, 5434, 0, 1, 1, -14027.7, -624.3475, -51.90258, 3.461362, 120, 0, 0), -- Coral Shark (Area: The Crystal Shore) (possible waypoints or random movement)
(@CGUID+270, 43596, 0, 1, 1, -14275.4, -205.872, 38.13513, 2.478368, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+271, 43596, 0, 1, 1, -14280.2, -192.352, 41.70193, 4.34587, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+272, 43596, 0, 1, 1, -14274.8, -199.561, 42.84863, 3.490659, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+273, 43596, 0, 1, 1, -14281, -209.648, 41.61893, 1.850049, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+274, 43596, 0, 1, 1, -14285.4, -181.58, 23.31463, 2.181662, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+275, 43596, 0, 1, 1, -14279.1, -180.12, 24.02443, 0.6632251, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+276, 43596, 0, 1, 1, -14281.4, -180.944, 24.84023, 2.86234, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+277, 43596, 0, 1, 1, -14289.5, -184.023, 42.84713, 4.502949, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+278, 43596, 0, 1, 1, -14281.1, -194.184, 42.46183, 4.607669, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+279, 43596, 0, 1, 1, -14290, -212.793, 36.19043, 0.9773844, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+280, 43596, 0, 1, 1, -14289.3, -178.229, 39.14503, 4.08407, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+281, 16399, 0, 1, 1, -14184.41, 192.7639, 20.69052, 3.735005, 120, 0, 0), -- Bloodsail Traitor (Area: Mistvale Valley)
(@CGUID+282, 1557, 0, 1, 1, -14088.01, 162.5797, 17.10475, 3.418088, 120, 0, 0), -- Elder Mistvale Gorilla (Area: Mistvale Valley)
(@CGUID+283, 9600, 0, 1, 1, -14093.92, 243.434, 56.76852, 5.085008, 120, 0, 0), -- Parrot (Area: Mistvale Valley)
(@CGUID+284, 9600, 0, 1, 1, -14179.46, 257.1772, 33.55443, 2.332923, 120, 0, 0), -- Parrot (Area: Mistvale Valley)
(@CGUID+285, 49928, 0, 1, 1, -14075.87, 273.4548, 45.96209, 4.675503, 120, 0, 0), -- Crimson Moth (Area: Mistvale Valley)
(@CGUID+286, 1561, 0, 1, 1, -14187.97, 378.8091, 19.21259, 2.432081, 120, 0, 0), -- Bloodsail Raider (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+287, 1562, 0, 1, 1, -14176.9, 397.592, 16.52056, 1.073749, 120, 0, 0), -- Bloodsail Mage (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+288, 9600, 0, 1, 1, -14159.55, 406.9773, 51.2598, 5.116117, 120, 0, 0), -- Parrot (Area: Cape of Stranglethorn)
(@CGUID+289, 1562, 0, 1, 1, -14160.86, 429.669, 12.20894, 4.551418, 120, 0, 0), -- Bloodsail Mage (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+290, 6827, 0, 1, 1, -14140.38, 503.6357, 2.207545, 4.261841, 120, 0, 0), -- Crab (Area: Cape of Stranglethorn)
(@CGUID+291, 1561, 0, 1, 1, -14134.65, 480.8806, 2.170372, 0.4164386, 120, 0, 0), -- Bloodsail Raider (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+292, 43364, 0, 1, 1, -14112.7, 477.186, 0.2765873, 0.4363323, 120, 0, 0), -- Bloodsail Hooch-Hound (Area: Cape of Stranglethorn)
(@CGUID+293, 6827, 0, 1, 1, -14109.91, 473.6686, 0.01365256, 0.2731051, 120, 0, 0), -- Crab (Area: Cape of Stranglethorn)
(@CGUID+294, 1562, 0, 1, 1, -14105.89, 452.351, 5.545484, 2.302305, 120, 0, 0), -- Bloodsail Mage (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+295, 43454, 0, 1, 1, -14127.9, 477.335, 1.429653, 5.5676, 120, 0, 0), -- "Good-Boy" Bruce (Area: Cape of Stranglethorn)
(@CGUID+296, 1561, 0, 1, 1, -14128.2, 464.462, 2.203723, 1.186824, 120, 0, 0), -- Bloodsail Raider (Area: Cape of Stranglethorn)
(@CGUID+297, 6827, 0, 1, 1, -14188.91, 670.29, 3.622011, 1.919734, 120, 0, 0), -- Crab (Area: Southern Savage Coast)
(@CGUID+298, 6827, 0, 1, 1, -14165.75, 755.209, -1.094721, 0, 120, 0, 0), -- Crab (Area: Southern Savage Coast)
(@CGUID+299, 6827, 0, 1, 1, -14178.13, 763.542, -0.04098797, 0.1809918, 120, 0, 0), -- Crab (Area: Southern Savage Coast)
(@CGUID+300, 6827, 0, 1, 1, -14227.34, 742.9795, 3.077054, 4.511931, 120, 0, 0), -- Crab (Area: Southern Savage Coast)
(@CGUID+301, 4624, 0, 1, 1, -14242.15, 343.7298, 25.96579, 5.393067, 120, 0, 0), -- Booty Bay Bruiser (Area: Southern Savage Coast) (possible waypoints or random movement)
(@CGUID+302, 49928, 0, 1, 1, -14248.43, 293.2008, 44.82737, 0.3480969, 120, 0, 0), -- Crimson Moth (Area: Cape of Stranglethorn)
(@CGUID+303, 15475, 0, 1, 1, -14223.4, 181.3058, 5.713864, 5.704928, 120, 0, 0), -- Beetle (Area: Cape of Stranglethorn)
(@CGUID+304, 1561, 0, 1, 1, -14219, 155.3698, 6.77686, 2.350397, 120, 0, 0), -- Bloodsail Raider (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+305, 1561, 0, 1, 1, -14214.42, 212.7969, 10.73499, 5.346505, 120, 0, 0), -- Bloodsail Raider (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+306, 1492, 0, 1, 1, -14191.2, -93.8819, -4.01862, 5.680881, 120, 0, 0), -- Gorlash (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+307, 43596, 0, 1, 1, -14291.6, -178.458, 39.28443, 4.660029, 120, 0, 0), -- Venture Co. Oil Worker (Area: Cape of Stranglethorn)
(@CGUID+308, 43596, 0, 1, 1, -14293.8, -178.601, 39.39793, 5.044002, 120, 0, 0), -- Venture Co. Oil Worker (Area: Cape of Stranglethorn)
(@CGUID+309, 43596, 0, 1, 1, -14290.6, -184.104, 43.15503, 4.415683, 120, 0, 0), -- Venture Co. Oil Worker (Area: Cape of Stranglethorn)
(@CGUID+310, 43596, 0, 1, 1, -14291.8, -183.986, 43.10363, 5.358161, 120, 0, 0), -- Venture Co. Oil Worker (Area: Cape of Stranglethorn)
(@CGUID+311, 43596, 0, 1, 1, -14295.3, -180.043, 39.20953, 6.161012, 120, 0, 0), -- Venture Co. Oil Worker (Area: Cape of Stranglethorn)
(@CGUID+312, 43596, 0, 1, 1, -14292, -185.705, 42.85763, 0.5235988, 120, 0, 0), -- Venture Co. Oil Worker (Area: Cape of Stranglethorn)
(@CGUID+313, 43596, 0, 1, 1, -14297, -181.729, 38.89573, 0.1745329, 120, 0, 0), -- Venture Co. Oil Worker (Area: Cape of Stranglethorn)
(@CGUID+314, 43596, 0, 1, 1, -14297, -184.526, 38.42483, 0.8028514, 120, 0, 0), -- Venture Co. Oil Worker (Area: Cape of Stranglethorn)
(@CGUID+315, 43596, 0, 1, 1, -14297.7, -182.889, 27.93753, 1.186824, 120, 0, 0), -- Venture Co. Oil Worker (Area: Cape of Stranglethorn)
(@CGUID+316, 43596, 0, 1, 1, -14299.5, -183.444, 27.12083, 2.338741, 120, 0, 0), -- Venture Co. Oil Worker (Area: Cape of Stranglethorn)
(@CGUID+317, 43596, 0, 1, 1, -14302.2, -184.217, 25.97723, 3.612832, 120, 0, 0), -- Venture Co. Oil Worker (Area: Cape of Stranglethorn)
(@CGUID+318, 43596, 0, 1, 1, -14301.7, -211.625, 35.43953, 5.427974, 120, 0, 0), -- Venture Co. Oil Worker (Area: Wild Shore)
(@CGUID+319, 43596, 0, 1, 1, -14301.6, -213.66, 35.25743, 1.815142, 120, 0, 0), -- Venture Co. Oil Worker (Area: Wild Shore)
(@CGUID+320, 43596, 0, 1, 1, -14362.2, -66.6441, 75.94363, 6.143559, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+321, 43596, 0, 1, 1, -14362.6, -71.3854, 77.07613, 3.787364, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+322, 43596, 0, 1, 1, -14366.5, -74.3125, 77.08494, 0.6283185, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+323, 43596, 0, 1, 1, -14367.6, -72.0399, 75.94373, 3.612832, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+324, 43596, 0, 1, 1, -14366.2, -71.0694, 31.13783, 0.6108652, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+325, 43596, 0, 1, 1, -14365.8, -77.8594, 31.13783, 6.213372, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+326, 43596, 0, 1, 1, -14367.9, -71.7378, 31.13783, 3.944444, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+327, 43596, 0, 1, 1, -14366.5, -73.4913, 31.13783, 3.508112, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+328, 43596, 0, 1, 1, -14366.1, -69.1771, 32.27123, 5.462881, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+329, 43596, 0, 1, 1, -14367.7, -78.8194, 31.13783, 5.445427, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+330, 43596, 0, 1, 1, -14368.7, -75.9288, 31.13783, 1.64061, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+331, 43596, 0, 1, 1, -14370.1, -74.6163, 31.13783, 0.541052, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+332, 43596, 0, 1, 1, -14366.8, -75.2778, 31.13783, 1.919862, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+333, 43596, 0, 1, 1, -14364, -78.2118, 32.27113, 1.291544, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+334, 43596, 0, 1, 1, -14367.3, -72.1615, 31.13783, 3.996804, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+335, 43596, 0, 1, 1, -14365.1, -74.1389, 31.13783, 0.1570796, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+336, 49928, 0, 1, 1, -14257.48, -8.978389, 34.91879, 1.921479, 120, 0, 0), -- Crimson Moth (Area: The Crystal Shore)
(@CGUID+337, 43596, 0, 1, 1, -14362.8, -65.4306, 75.94373, 0.9424778, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+338, 43596, 0, 1, 1, -14364.8, -67.776, 75.94363, 0.541052, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+339, 43596, 0, 1, 1, -14369.8, -70.2917, 75.94373, 5.270895, 120, 0, 0), -- Venture Co. Oil Worker (Area: The Crystal Shore)
(@CGUID+340, 1561, 0, 1, 1, -14279.67, 146.8368, 8.705757, 5.453632, 120, 0, 0), -- Bloodsail Raider (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+341, 15475, 0, 1, 1, -14262.5, 262.5, 17.86067, 1.763915, 120, 0, 0), -- Beetle (Area: Cape of Stranglethorn)
(@CGUID+342, 48972, 0, 1, 1, -14271.97, 368.7204, 33.48765, 2.553827, 120, 0, 0), -- Long-tailed Mole (Area: Cape of Stranglethorn)
(@CGUID+343, 4624, 0, 1, 1, -14277.99, 361.6246, 33.36198, 4.984836, 120, 0, 0), -- Booty Bay Bruiser (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+344, 4624, 0, 1, 1, -14269.22, 351.9075, 32.66994, 2.385599, 120, 0, 0), -- Booty Bay Bruiser (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+345, 4624, 0, 1, 1, -14258.65, 327.0302, 26.3636, 5.550147, 120, 0, 0), -- Booty Bay Bruiser (Area: Cape of Stranglethorn)
(@CGUID+346, 4076, 0, 1, 1, -14273.54, 389.9502, 36.60957, 5.247781, 120, 0, 0), -- Roach (Area: Cape of Stranglethorn)
(@CGUID+347, 4076, 0, 1, 1, -14285.96, 532.6208, 8.927303, 0.3738829, 120, 0, 0), -- Roach (Area: Southern Savage Coast)
(@CGUID+348, 4624, 0, 1, 1, -14278.35, 553.1927, 8.983554, 3.909538, 120, 0, 0), -- Booty Bay Bruiser (Area: Southern Savage Coast)
(@CGUID+349, 4624, 0, 1, 1, -14286.46, 540.7466, 9.004538, 1.972222, 120, 0, 0), -- Booty Bay Bruiser (Area: Southern Savage Coast)
(@CGUID+350, 6827, 0, 1, 1, -14254.48, 731.9489, 1.599213, 1.721812, 120, 0, 0), -- Crab (Area: Southern Savage Coast)
(@CGUID+351, 32520, 0, 1, 1, -6305.162, 5582.533, -1172.063, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Janeiro's Point)
(@CGUID+352, 32520, 0, 1, 1, -6014.71, 5479.63, -1208.007, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Janeiro's Point)
(@CGUID+353, 32520, 0, 1, 1, -5691.65, 5556.92, -1154.687, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Janeiro's Point)
(@CGUID+354, 32520, 0, 1, 1, -6148.39, 5539.97, -1207.787, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Janeiro's Point)
(@CGUID+355, 25098, 0, 1, 1, -14285.4, 596.7632, 6.708141, 3.080878, 120, 0, 0), -- Bosun Thunderhorn (Area: Booty Bay)
(@CGUID+356, 25089, 0, 1, 1, -14292.19, 596.0355, 6.096996, 4.616767, 120, 0, 0), -- Galley Chief Steelbelly (Area: Booty Bay)
(@CGUID+357, 25095, 0, 1, 1, -14288.75, 590.2195, 11.87887, 4.294315, 120, 0, 0), -- Crewman Springwidget (Area: Booty Bay) (possible waypoints or random movement)
(@CGUID+358, 25111, 0, 1, 1, -14283.87, 584.835, 15.13168, 0.1836314, 120, 0, 0), -- Treasure (Area: Booty Bay)
(@CGUID+359, 25093, 0, 1, 1, -14293.17, 590.8409, 12.07599, 1.199984, 120, 0, 0), -- First Mate Masker (Area: Booty Bay) (possible waypoints or random movement)
(@CGUID+360, 25082, 0, 1, 1, -14293.22, 586.8698, 6.180601, 5.402165, 120, 0, 0), -- Engineer Torquespindle (Area: Booty Bay)
(@CGUID+361, 25078, 0, 1, 1, -14301.15, 595.7316, 6.098086, 1.332173, 120, 0, 0), -- Captain Krick Wrenchnozzle (Area: Booty Bay)
(@CGUID+362, 25096, 0, 1, 1, -14253.54, 576.267, 19.44373, 6.205017, 120, 0, 0), -- Crewman Gearspinner (Area: Booty Bay)
(@CGUID+363, 25097, 0, 1, 1, -14268.6, 572.7619, 6.181956, 5.943218, 120, 0, 0), -- Crewman Hammertink (Area: Booty Bay)
(@CGUID+364, 25094, 0, 1, 1, -14313.64, 594.8552, 18.62098, 2.809505, 120, 0, 0), -- Navigator Tah're (Area: Booty Bay)
(@CGUID+365, 15384, 0, 1, 1, -14292.19, 560.2382, 12.32107, 3.944444, 120, 0, 0), -- OLDWorld Trigger (DO NOT DELETE) (Area: Booty Bay)
(@CGUID+366, 9559, 0, 1, 1, -14289.06, 556.6127, 8.971137, 4.555309, 120, 0, 0), -- Grizzlowe (Area: Booty Bay)
(@CGUID+367, 4624, 0, 1, 1, -14293.2, 557.6228, 8.855279, 5.218534, 120, 0, 0), -- Booty Bay Bruiser (Area: Booty Bay)
(@CGUID+368, 4631, 0, 1, 1, -14298.3, 539.635, 8.933833, 0.1570796, 120, 0, 0), -- Wharfmaster Lozgil (Area: Booty Bay)
(@CGUID+369, 4075, 0, 1, 1, -14300.44, 526.449, 8.671729, 4.053085, 120, 0, 0), -- Rat (Area: Booty Bay)
(@CGUID+370, 48797, 0, 1, 1, -14342.29, 541.5157, -6.056916, 2.663402, 120, 0, 0), -- Gim'hila (Area: Booty Bay) (possible waypoints or random movement)
(@CGUID+371, 2594, 0, 1, 1, -14301.66, 519.7864, 8.875498, 4.433136, 120, 0, 0), -- Sprogger (Area: Booty Bay)
(@CGUID+372, 2500, 0, 1, 1, -14300.4, 517.43, 8.967673, 4.171337, 120, 0, 0), -- Captain Hecklebury Smotts (Area: Booty Bay)
(@CGUID+373, 2502, 0, 1, 1, -14297.93, 508.3095, 8.96488, 4.282985, 120, 0, 0), -- "Shaky" Phillipe (Area: Booty Bay) (possible waypoints or random movement)
(@CGUID+374, 48808, 0, 1, 1, -14311.25, 509.2917, 8.697603, 1.570796, 120, 0, 0), -- Corporal Jeyne (Area: Booty Bay)
(@CGUID+375, 4624, 0, 1, 1, -14312.12, 497.6482, 8.644084, 4.314779, 120, 0, 0), -- Booty Bay Bruiser (Area: Booty Bay) (possible waypoints or random movement)
(@CGUID+376, 28180, 0, 1, 1, -14330.79, 424.342, 25.80396, 4.13643, 120, 0, 0), -- [ph] Goblin Construction Crew (Area: Booty Bay)
(@CGUID+377, 9600, 0, 1, 1, -14324.25, 446.0403, 60.56367, 1.102507, 120, 0, 0), -- Parrot (Area: Booty Bay)
(@CGUID+378, 3945, 0, 1, 1, -14320.26, 474.4375, 8.614664, 3.892084, 120, 0, 0), -- Caravaneer Ruzzgot (Area: Booty Bay)
(@CGUID+379, 4624, 0, 1, 1, -14311, 503.8543, 8.642586, 0.8124214, 120, 0, 0), -- Booty Bay Bruiser (Area: Booty Bay) (possible waypoints or random movement)
(@CGUID+380, 4624, 0, 1, 1, -14343.7, 450.156, 7.633924, 5.585053, 120, 0, 0), -- Booty Bay Bruiser (Area: Booty Bay)
(@CGUID+381, 4624, 0, 1, 1, -14303.2, 442.825, 28.34243, 4.363323, 120, 0, 0), -- Booty Bay Bruiser (Area: Booty Bay)
(@CGUID+382, 4624, 0, 1, 1, -14304.99, 433.2847, 29.36503, 1.396263, 120, 0, 0), -- Booty Bay Bruiser (Area: Booty Bay)
(@CGUID+383, 48972, 0, 1, 1, -14345.11, 449.1346, 7.509112, 2.205603, 120, 0, 0), -- Long-tailed Mole (Area: Booty Bay)
(@CGUID+384, 9600, 0, 1, 1, -14293.55, 423.0293, 68.28359, 0.04438001, 120, 0, 0), -- Parrot (Area: Booty Bay)
(@CGUID+385, 28180, 0, 1, 1, -14333.59, 422.9375, 26.72909, 0.05235988, 120, 0, 0), -- [ph] Goblin Construction Crew (Area: Booty Bay) (possible waypoints or random movement)
(@CGUID+386, 54475, 0, 1, 1, -14300.33, 380.0174, 28.08624, 5.5676, 120, 0, 0), -- Crab (Area: Booty Bay)
(@CGUID+387, 49928, 0, 1, 1, -14344.64, 426.7374, 39.28735, 4.995492, 120, 0, 0), -- Crimson Moth (Area: Booty Bay)
(@CGUID+388, 28180, 0, 1, 1, -14340.19, 430.3594, 19.62334, 5.88176, 120, 0, 0), -- [ph] Goblin Construction Crew (Area: Booty Bay)
(@CGUID+389, 28180, 0, 1, 1, -14349.39, 422.8333, 39.51253, 2.96706, 120, 0, 0), -- [ph] Goblin Construction Crew (Area: Booty Bay) (possible waypoints or random movement)
(@CGUID+390, 7390, 0, 1, 1, -14332.37, 425.2588, 6.626348, 1.21464, 120, 0, 0), -- Cockatiel (Area: Booty Bay) (possible waypoints or random movement)
(@CGUID+391, 28180, 0, 1, 1, -14349.87, 421.2708, 35.16753, 3.735005, 120, 0, 0), -- [ph] Goblin Construction Crew (Area: Booty Bay)
(@CGUID+392, 28180, 0, 1, 1, -14349.79, 414.0156, 41.41492, 4.974188, 120, 0, 0), -- [ph] Goblin Construction Crew (Area: Booty Bay)
(@CGUID+393, 28180, 0, 1, 1, -14345.38, 427.5885, 22.80944, 4.991642, 120, 0, 0), -- [ph] Goblin Construction Crew (Area: Booty Bay)
(@CGUID+394, 2664, 0, 1, 1, -14331.23, 419.2986, 6.713277, 2.600541, 120, 0, 0), -- Kelsey Yance (Area: Booty Bay)
(@CGUID+395, 2663, 0, 1, 1, -14334.84, 425.6806, 6.709666, 4.415683, 120, 0, 0), -- Narkk (Area: Booty Bay)
(@CGUID+396, 7389, 0, 1, 1, -14336.41, 427.0307, 6.626345, 5.538592, 120, 0, 0), -- Senegal (Area: Booty Bay) (possible waypoints or random movement)
(@CGUID+397, 2839, 0, 1, 1, -14340.61, 414.6042, 6.713277, 2.199115, 120, 0, 0), -- Haren Kanmae (Area: Booty Bay)
(@CGUID+398, 1561, 0, 1, 1, -14287.66, 86.86794, 6.111643, 2.068592, 120, 0, 0), -- Bloodsail Raider (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+399, 1562, 0, 1, 1, -14317.7, 111.4216, 4.76205, 4.501977, 120, 0, 0), -- Bloodsail Mage (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+400, 49928, 0, 1, 1, -14298.01, 142.4233, 36.23065, 5.401329, 120, 0, 0), -- Crimson Moth (Area: Cape of Stranglethorn)
(@CGUID+401, 50487, 0, 1, 1, -14296.59, 149.3574, 9.455368, 1.802484, 120, 0, 0), -- Forest Spiderling (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+402, 6827, 0, 1, 1, -14322.95, 48.09778, 0.5251591, 5.435051, 120, 0, 0), -- Crab (Area: Cape of Stranglethorn)
(@CGUID+403, 6827, 0, 1, 1, -14380.44, 63.30379, 1.112312, 0.01520731, 120, 0, 0), -- Crab (Area: Wild Shore)
(@CGUID+404, 2845, 0, 1, 1, -14359.1, 367.469, 24.46263, 1.64061, 120, 0, 0), -- Fargon Mortalak (Area: Wild Shore)
(@CGUID+405, 4624, 0, 1, 1, -14352.81, 378.3673, 23.56847, 1.658063, 120, 0, 0), -- Booty Bay Bruiser (Area: Cape of Stranglethorn)
(@CGUID+406, 4624, 0, 1, 1, -14320.41, 400.9634, 24.01454, 4.750482, 120, 0, 0), -- Booty Bay Bruiser (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+407, 2844, 0, 1, 1, -14361.88, 372.2274, 24.44773, 5.846853, 120, 0, 0), -- Hurklor (Area: Cape of Stranglethorn)
(@CGUID+408, 2847, 0, 1, 1, -14379.96, 365.551, 24.03846, 1.151917, 120, 0, 0), -- Jansen Underwood (Area: Cape of Stranglethorn)
(@CGUID+409, 54308, 0, 1, 1, -14381.37, 373.3494, 28.65724, 2.710802, 120, 0, 0), -- Kirsty Logan (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+410, 7794, 0, 1, 1, -14377.3, 379.108, 23.43683, 3.682645, 120, 0, 0), -- McGavan (Area: Cape of Stranglethorn)
(@CGUID+411, 2836, 0, 1, 1, -14383.02, 370.7662, 24.00604, 5.393067, 120, 0, 0), -- Brikk Keencraft (Area: Cape of Stranglethorn)
(@CGUID+412, 28180, 0, 1, 1, -14357.17, 417.3299, 40.79548, 4.974188, 120, 0, 0), -- [ph] Goblin Construction Crew (Area: Cape of Stranglethorn)
(@CGUID+413, 4624, 0, 1, 1, -14376.58, 386.1563, 22.67363, 4.852015, 120, 0, 0), -- Booty Bay Bruiser (Area: Cape of Stranglethorn)
(@CGUID+414, 28180, 0, 1, 1, -14374.14, 407.8438, 25.91001, 4.066617, 120, 0, 0), -- [ph] Goblin Construction Crew (Area: Cape of Stranglethorn)
(@CGUID+415, 2685, 0, 1, 1, -14364.46, 402.0746, 6.713277, 1.623156, 120, 0, 0), -- Mazk Snipeshot (Area: Cape of Stranglethorn)
(@CGUID+416, 47667, 0, 1, 1, -14366.41, 407.7508, 6.626362, 2.406625, 120, 0, 0), -- Wharf Rat (Area: Cape of Stranglethorn)
(@CGUID+417, 28180, 0, 1, 1, -14380.34, 412.0573, 22.53753, 1.186824, 120, 0, 0), -- [ph] Goblin Construction Crew (Area: Cape of Stranglethorn)
(@CGUID+418, 2493, 0, 1, 1, -14397.65, 396.2865, 22.72228, 3.892084, 120, 0, 0), -- Dizzy One-Eye (Area: Cape of Stranglethorn)
(@CGUID+419, 2840, 0, 1, 1, -14368.63, 416.7743, 6.713277, 5.009095, 120, 0, 0), -- Kizz Bluntstrike (Area: Cape of Stranglethorn)
(@CGUID+420, 4624, 0, 1, 1, -14386, 399.288, 6.645936, 2.408554, 120, 0, 0), -- Booty Bay Bruiser (Area: Cape of Stranglethorn)
(@CGUID+421, 2482, 0, 1, 1, -14379.11, 412.6719, 6.820221, 5.707227, 120, 0, 0), -- Zarena Cromwind (Area: Cape of Stranglethorn)
(@CGUID+422, 4624, 0, 1, 1, -14390.88, 414.8611, 22.82784, 2.740167, 120, 0, 0), -- Booty Bay Bruiser (Area: Cape of Stranglethorn)
(@CGUID+423, 4624, 0, 1, 1, -14366.24, 426.8889, 7.443278, 1.780236, 120, 0, 0), -- Booty Bay Bruiser (Area: Cape of Stranglethorn)
(@CGUID+424, 2499, 0, 1, 1, -14355.9, 433.399, 7.553003, 2.356194, 120, 0, 0), -- Markel Smythe (Area: Cape of Stranglethorn)
(@CGUID+425, 48972, 0, 1, 1, -14393, 400.9385, 6.430133, 3.501659, 120, 0, 0), -- Long-tailed Mole (Area: Cape of Stranglethorn)
(@CGUID+426, 15677, 0, 1, 1, -14398.79, 406.3368, 9.477669, 1.082104, 120, 0, 0), -- Auctioneer Graves (Area: Cape of Stranglethorn)
(@CGUID+427, 4624, 0, 1, 1, -14323.27, 470.6319, 8.369968, 4.233211, 120, 0, 0), -- Booty Bay Bruiser (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+428, 28180, 0, 1, 1, -14402.54, 544.8264, 14.49212, 4.153883, 120, 0, 0), -- [ph] Goblin Construction Crew (Area: Booty Bay)
(@CGUID+429, 28180, 0, 1, 1, -14402.85, 544.618, 6.412243, 4.153883, 120, 0, 0), -- [ph] Goblin Construction Crew (Area: Booty Bay)
(@CGUID+430, 28180, 0, 1, 1, -14400.63, 537.6197, 6.492337, 0.7227315, 120, 0, 0), -- [ph] Goblin Construction Crew (Area: Booty Bay) (possible waypoints or random movement)
(@CGUID+431, 25098, 0, 1, 1, -14355.58, 832.1014, 6.708141, 1.939705, 120, 0, 0), -- Bosun Thunderhorn (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+432, 25093, 0, 1, 1, -14366.21, 833.8148, 12.10617, 2.561351, 120, 0, 0), -- First Mate Masker (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+433, 25096, 0, 1, 1, -14360.94, 794.6006, 19.44373, 5.063845, 120, 0, 0), -- Crewman Gearspinner (Area: Cape of Stranglethorn)
(@CGUID+434, 25078, 0, 1, 1, -14372.7, 845.0624, 16.47098, 5.220924, 120, 0, 0), -- Captain Krick Wrenchnozzle (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+435, 25094, 0, 1, 1, -14368.72, 853.2753, 18.36956, 4.749685, 120, 0, 0), -- Navigator Tah're (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+436, 25111, 0, 1, 1, -14365.79, 825.7443, 15.13168, 5.325644, 120, 0, 0), -- Treasure (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+437, 25082, 0, 1, 1, -14367.83, 835.0894, 6.180601, 4.260993, 120, 0, 0), -- Engineer Torquespindle (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+438, 25089, 0, 1, 1, -14359.07, 837.9731, 6.180998, 3.475595, 120, 0, 0), -- Galley Chief Steelbelly (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+439, 25095, 0, 1, 1, -14357.5, 832.2723, 11.83142, 0.7354279, 120, 0, 0), -- Crewman Springwidget (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+440, 25097, 0, 1, 1, -14370.4, 806.8305, 6.181956, 4.802045, 120, 0, 0), -- Crewman Hammertink (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+441, 28180, 0, 1, 1, -14403.95, 536.2518, 6.601237, 3.036873, 120, 0, 0), -- [ph] Goblin Construction Crew (Area: Booty Bay)
(@CGUID+442, 4624, 0, 1, 1, -14409.18, 543.6268, 12.91867, 5.67232, 120, 0, 0), -- Booty Bay Bruiser (Area: Booty Bay)
(@CGUID+443, 4624, 0, 1, 1, -14410.92, 541.7518, 12.91969, 5.67232, 120, 0, 0), -- Booty Bay Bruiser (Area: Booty Bay)
(@CGUID+444, 28180, 0, 1, 1, -14410.05, 532.8264, 8.426721, 2.775074, 120, 0, 0), -- [ph] Goblin Construction Crew (Area: Booty Bay)
(@CGUID+445, 49928, 0, 1, 1, -14408.17, 559.765, 56.36855, 0.8676685, 120, 0, 0), -- Crimson Moth (Area: Booty Bay)
(@CGUID+446, 4076, 0, 1, 1, -14413.32, 519.0328, 5.000031, 0.7274086, 120, 0, 0), -- Roach (Area: Booty Bay)
(@CGUID+447, 15681, 0, 1, 1, -14416.6, 524.6684, 7.666569, 4.468043, 120, 0, 0), -- Auctioneer O'reely (Area: Booty Bay)
(@CGUID+448, 4624, 0, 1, 1, -14415.8, 518.922, 5.104903, 3.176499, 120, 0, 0), -- Booty Bay Bruiser (Area: Booty Bay)
(@CGUID+449, 8123, 0, 1, 1, -14421.95, 528.8976, 5.248834, 5.148721, 120, 0, 0), -- Rickle Goldgrubber (Area: Booty Bay)
(@CGUID+450, 2494, 0, 1, 1, -14418.2, 513.398, 4.961022, 5.218534, 120, 0, 0), -- Privateer Bloads (Area: Booty Bay) (possible waypoints or random movement)
(@CGUID+451, 2625, 0, 1, 1, -14426.18, 527.2535, 5.235501, 5.218534, 120, 0, 0), -- Viznik Goldgrubber (Area: Booty Bay)
(@CGUID+452, 4624, 0, 1, 1, -14426.78, 523.7899, 5.075222, 5.72468, 120, 0, 0), -- Booty Bay Bruiser (Area: Booty Bay)
(@CGUID+453, 28180, 0, 1, 1, -14421.19, 448.1371, 13.50414, 1.780236, 120, 0, 0), -- [ph] Goblin Construction Crew (Area: Booty Bay)
(@CGUID+454, 4624, 0, 1, 1, -14427.25, 456.5104, 15.42189, 4.485496, 120, 0, 0), -- Booty Bay Bruiser (Area: Booty Bay)
(@CGUID+455, 2490, 0, 1, 1, -14411.1, 427.967, 8.957363, 1.012291, 120, 0, 0), -- First Mate Crazz (Area: Booty Bay)
(@CGUID+456, 4076, 0, 1, 1, -14404.89, 416.7276, 23.10794, 0.3797086, 120, 0, 0), -- Roach (Area: Booty Bay)
(@CGUID+457, 21045, 0, 1, 1, -14398.63, 424.8296, 8.058924, 5.445427, 120, 0, 0), -- Hired Bodyguard (Area: Booty Bay)
(@CGUID+458, 21045, 0, 1, 1, -14396.3, 427.302, 7.890773, 5.323254, 120, 0, 0), -- Hired Bodyguard (Area: Booty Bay)
(@CGUID+459, 17249, 0, 1, 1, -14397.4, 425.962, 7.963553, 5.585053, 120, 0, 0), -- Landro Longshot (Area: Booty Bay)
(@CGUID+460, 4624, 0, 1, 1, -14405.37, 410.5955, 27.81997, 0.8901179, 120, 0, 0), -- Booty Bay Bruiser (Area: Booty Bay)
(@CGUID+461, 9600, 0, 1, 1, -14408.21, 417.2656, 45.82038, 2.456764, 120, 0, 0), -- Parrot (Area: Booty Bay)
(@CGUID+462, 2699, 0, 1, 1, -14404.05, 402.8956, 23.14326, 1.396263, 120, 0, 0), -- Rikqiz (Area: Booty Bay)
(@CGUID+463, 43505, 0, 1, 1, -14402.9, 399.231, 27.93369, 2.670354, 120, 0, 0), -- Bossy (Area: Booty Bay)
(@CGUID+464, 7406, 0, 1, 1, -14417, 411.288, 22.78153, 0.4537856, 120, 0, 0), -- Oglethorpe Obnoticus (Area: Booty Bay)
(@CGUID+465, 28180, 0, 1, 1, -14428.53, 443.1597, 5.3558, 1.780236, 120, 0, 0), -- [ph] Goblin Construction Crew (Area: Booty Bay)
(@CGUID+466, 54232, 0, 1, 1, -14429.81, 423.7621, 4.243568, 2.635447, 120, 0, 0), -- Mrs. Gant (Area: Booty Bay)
(@CGUID+467, 4624, 0, 1, 1, -14432.51, 419.61, 23.20734, 0.509828, 120, 0, 0), -- Booty Bay Bruiser (Area: Booty Bay) (possible waypoints or random movement)
(@CGUID+468, 2838, 0, 1, 1, -14430.21, 410.9635, 15.3605, 3.036873, 120, 0, 0), -- Crazk Sparks (Area: Booty Bay)
(@CGUID+469, 4076, 0, 1, 1, -14431.46, 421.4188, 8.848201, 5.208891, 120, 0, 0), -- Roach (Area: Booty Bay)
(@CGUID+470, 4624, 0, 1, 1, -14419.75, 437.1158, 9.759392, 5.3179, 120, 0, 0), -- Booty Bay Bruiser (Area: Booty Bay) (possible waypoints or random movement)
(@CGUID+471, 4624, 0, 1, 1, -14432.24, 429.9492, 15.56208, 2.231728, 120, 0, 0), -- Booty Bay Bruiser (Area: Booty Bay) (possible waypoints or random movement)
(@CGUID+472, 4076, 0, 1, 1, -14433.48, 449.953, 15.45033, 4.227889, 120, 0, 0), -- Roach (Area: Booty Bay)
(@CGUID+473, 2486, 0, 1, 1, -14433.18, 458.9879, 15.53494, 3.892084, 120, 0, 0), -- Fin Fizracket (Area: Booty Bay)
(@CGUID+474, 4624, 0, 1, 1, -14438.98, 436.3958, 20.50878, 3.071779, 120, 0, 0), -- Booty Bay Bruiser (Area: Booty Bay)
(@CGUID+475, 2622, 0, 1, 1, -14437.33, 408.2118, 15.11328, 1.919862, 120, 0, 0), -- Sly Garrett (Area: Booty Bay)
(@CGUID+476, 48972, 0, 1, 1, -14440.48, 443.0431, 3.659465, 4.941656, 120, 0, 0), -- Long-tailed Mole (Area: Booty Bay)
(@CGUID+477, 4624, 0, 1, 1, -14439.9, 453.5494, 3.699984, 2.070519, 120, 0, 0), -- Booty Bay Bruiser (Area: Booty Bay) (possible waypoints or random movement)
(@CGUID+478, 44112, 0, 1, 1, -14442.82, 433.4705, 16.89781, 0.5934119, 120, 0, 0), -- Airwyn Bantamflax (Area: Booty Bay)
(@CGUID+479, 4624, 0, 1, 1, -14437.55, 462.809, 3.976888, 3.560472, 120, 0, 0), -- Booty Bay Bruiser (Area: Booty Bay)
(@CGUID+480, 2842, 0, 1, 1, -14443.98, 433.7639, 4.272444, 6.143559, 120, 0, 0), -- Wigcik (Area: Booty Bay)
(@CGUID+481, 4624, 0, 1, 1, -14442.65, 454.5469, 3.817722, 0.5235988, 120, 0, 0), -- Booty Bay Bruiser (Area: Booty Bay)
(@CGUID+482, 4075, 0, 1, 1, -14438.23, 467.5027, 3.926983, 3.098418, 120, 0, 0), -- Rat (Area: Booty Bay)
(@CGUID+483, 4076, 0, 1, 1, -14443.23, 458.4473, 3.767385, 3.979984, 120, 0, 0), -- Roach (Area: Booty Bay)
(@CGUID+484, 9858, 0, 1, 1, -14446.48, 448.4149, 4.124943, 2.9147, 120, 0, 0), -- Auctioneer Kresky (Area: Booty Bay)
(@CGUID+485, 4624, 0, 1, 1, -14449.02, 436.2082, 3.889718, 1.064651, 120, 0, 0), -- Booty Bay Bruiser (Area: Booty Bay)
(@CGUID+486, 4624, 0, 1, 1, -14448.88, 429.5278, 15.10494, 3.735005, 120, 0, 0), -- Booty Bay Bruiser (Area: Booty Bay)
(@CGUID+487, 2501, 0, 1, 1, -14447.4, 448.002, 15.82833, 2.583087, 120, 0, 0), -- "Sea Wolf" MacKinley (Area: Booty Bay)
(@CGUID+488, 4624, 0, 1, 1, -14450.38, 443.7118, 4.151055, 2.181662, 120, 0, 0), -- Booty Bay Bruiser (Area: Booty Bay)
(@CGUID+489, 4624, 0, 1, 1, -14448.37, 409.7942, 25.1044, 1.570796, 120, 0, 0), -- Booty Bay Bruiser (Area: Booty Bay)
(@CGUID+490, 4624, 0, 1, 1, -14453.09, 432.8811, 15.1785, 5.249797, 120, 0, 0), -- Booty Bay Bruiser (Area: Booty Bay) (possible waypoints or random movement)
(@CGUID+491, 2670, 0, 1, 1, -14439.65, 388.9115, 32.39803, 6.213372, 120, 0, 0), -- Xizk Goodstitch (Area: Booty Bay)
(@CGUID+492, 2627, 0, 1, 1, -14437.77, 384.7656, 32.39803, 1.396263, 120, 0, 0), -- Grarnik Goodstitch (Area: Booty Bay)
(@CGUID+493, 4624, 0, 1, 1, -14444.28, 393.0365, 32.06008, 1.518436, 120, 0, 0), -- Booty Bay Bruiser (Area: Booty Bay)
(@CGUID+494, 43849, 0, 1, 1, -14454.51, 449.3316, 9.168277, 0, 120, 0, 0), -- Garley Lightrider (Area: Booty Bay)
(@CGUID+495, 4624, 0, 1, 1, -14445.87, 413.5194, 25.00292, 5.424911, 120, 0, 0), -- Booty Bay Bruiser (Area: Booty Bay) (possible waypoints or random movement)
(@CGUID+496, 4624, 0, 1, 1, -14451.84, 454.5938, 4.124943, 5.253441, 120, 0, 0), -- Booty Bay Bruiser (Area: Booty Bay)
(@CGUID+497, 4624, 0, 1, 1, -14451.06, 454.7153, 20.54233, 0.7504916, 120, 0, 0), -- Booty Bay Bruiser (Area: Booty Bay)
(@CGUID+498, 2834, 0, 1, 1, -14449.24, 468.4236, 15.35661, 0.08726646, 120, 0, 0), -- Myizz Luckycatch (Area: Booty Bay)
(@CGUID+499, 4624, 0, 1, 1, -14460.22, 451.1978, 4.135251, 5.986479, 120, 0, 0), -- Booty Bay Bruiser (Area: Booty Bay)
(@CGUID+500, 4624, 0, 1, 1, -14441.94, 481.1354, 15.273, 4.572762, 120, 0, 0), -- Booty Bay Bruiser (Area: Booty Bay)
(@CGUID+501, 2626, 0, 1, 1, -14451.28, 471.1632, 4.284943, 5.72468, 120, 0, 0), -- Old Man Heming (Area: Booty Bay)
(@CGUID+502, 2496, 0, 1, 1, -14439, 483.483, 28.92853, 2.61024, 120, 0, 0), -- Baron Revilgaz (Area: Booty Bay)
(@CGUID+503, 2846, 0, 1, 1, -14467.47, 418.3403, 25.48711, 1.186824, 120, 0, 0), -- Blixrez Goodstitch (Area: Booty Bay)
(@CGUID+504, 2849, 0, 1, 1, -14468.3, 424.602, 25.45923, 4.660029, 120, 0, 0), -- Qixdi Goodstitch (Area: Booty Bay)
(@CGUID+505, 4624, 0, 1, 1, -14466.57, 447.9398, 15.58278, 1.500983, 120, 0, 0), -- Booty Bay Bruiser (Area: Booty Bay)
(@CGUID+506, 2487, 0, 1, 1, -14444.63, 486.8202, 28.67336, 0.06981317, 120, 0, 0), -- Fleet Master Seahorn (Area: Booty Bay)
(@CGUID+507, 10060, 0, 1, 1, -14454, 479.108, 15.11793, 5.410521, 120, 0, 0), -- Grimestack (Area: Booty Bay)
(@CGUID+508, 2858, 0, 1, 1, -14448.56, 506.129, 26.35653, 0.7853982, 120, 0, 0), -- Gringer (Area: Booty Bay)
(@CGUID+509, 4624, 0, 1, 1, -14448.22, 493.7305, 27.86733, 5.530022, 120, 0, 0), -- Booty Bay Bruiser (Area: Booty Bay) (possible waypoints or random movement)
(@CGUID+510, 2498, 0, 1, 1, -14453.4, 490.262, 15.21323, 3.176499, 120, 0, 0), -- Crank Fizzlebub (Area: Booty Bay)
(@CGUID+511, 2832, 0, 1, 1, -14451.7, 495.417, 15.19013, 3.700098, 120, 0, 0), -- Nixxrax Fillamug (Area: Booty Bay)
(@CGUID+512, 4624, 0, 1, 1, -14461.74, 478.2934, 26.94364, 3.508112, 120, 0, 0), -- Booty Bay Bruiser (Area: Booty Bay)
(@CGUID+513, 4624, 0, 1, 1, -14458.1, 488.625, 15.20773, 1.937315, 120, 0, 0), -- Booty Bay Bruiser (Area: Booty Bay)
(@CGUID+514, 6827, 0, 1, 1, -14419.99, -320.0343, 0.3958902, 0.03904265, 120, 0, 0), -- Crab (Area: Wild Shore)
(@CGUID+515, 6827, 0, 1, 1, -14425.63, -369.0022, 3.288153, 2.060639, 120, 0, 0), -- Crab (Area: Wild Shore)
(@CGUID+516, 6827, 0, 1, 1, -14477.15, -469.5178, 1.490255, 3.741414, 120, 0, 0), -- Crab (Area: The Crystal Shore)
(@CGUID+517, 6827, 0, 1, 1, -14449.37, -430.8869, 0.3875546, 2.490664, 120, 0, 0), -- Crab (Area: The Crystal Shore)
(@CGUID+518, 2521, 0, 1, 1, -14480.26, -449.4293, 3.128491, 0.7943572, 120, 0, 0), -- Skymane Gorilla (Area: The Crystal Shore)
(@CGUID+519, 43417, 0, 1, 1, -14445.91, -348.2822, 6.620954, 6.191873, 120, 0, 0), -- Skymane Bonobo (Area: The Crystal Shore) (possible waypoints or random movement)
(@CGUID+520, 2521, 0, 1, 1, -14486.7, -382.4738, 3.774275, 2.795819, 120, 0, 0), -- Skymane Gorilla (Area: The Crystal Shore)
(@CGUID+521, 6827, 0, 1, 1, -14446.56, -299.4863, 0.6665225, 2.723368, 120, 0, 0), -- Crab (Area: The Crystal Shore)
(@CGUID+522, 6827, 0, 1, 1, -14498.48, -290.0603, 1.47358, 1.241968, 120, 0, 0), -- Crab (Area: The Crystal Shore)
(@CGUID+523, 6827, 0, 1, 1, -14509.14, -326.1218, 2.056932, 2.970779, 120, 0, 0), -- Crab (Area: The Crystal Shore)
(@CGUID+524, 6827, 0, 1, 1, -14463.52, -254.0295, 2.770111, 4.70527, 120, 0, 0), -- Crab (Area: The Crystal Shore)
(@CGUID+525, 43417, 0, 1, 1, -14519.13, -285.1976, 5.670912, 4.161246, 120, 0, 0), -- Skymane Bonobo (Area: Jaguero Isle) (possible waypoints or random movement)
(@CGUID+526, 6827, 0, 1, 1, -14452.92, -190.9138, 5.561664, 3.655896, 120, 0, 0), -- Crab (Area: Jaguero Isle)
(@CGUID+527, 6827, 0, 1, 1, -14468.95, -227.2011, 7.258262, 0.03514178, 120, 0, 0), -- Crab (Area: Jaguero Isle)
(@CGUID+528, 50487, 0, 1, 1, -14531.37, -184.2542, 11.46036, 4.849589, 120, 0, 0), -- Forest Spiderling (Area: Jaguero Isle) (possible waypoints or random movement)
(@CGUID+529, 6827, 0, 1, 1, -14475.43, -108.3606, 0.2795217, 0.8517824, 120, 0, 0), -- Crab (Area: Jaguero Isle)
(@CGUID+530, 6827, 0, 1, 1, -14455.3, 53.19912, 1.941214, 5.081823, 120, 0, 0), -- Crab (Area: Jaguero Isle)
(@CGUID+531, 6827, 0, 1, 1, -14457.51, 48.04745, 1.569291, 4.317748, 120, 0, 0), -- Crab (Area: Jaguero Isle)
(@CGUID+532, 6827, 0, 1, 1, -14498.96, 107.291, -1.814888, 4.167006, 120, 0, 0), -- Crab (Area: Jaguero Isle)
(@CGUID+533, 1653, 0, 1, 1, -14478.23, 110.5175, 3.471977, 3.408854, 120, 0, 0), -- Bloodsail Elder Magus (Area: Jaguero Isle) (possible waypoints or random movement)
(@CGUID+534, 6827, 0, 1, 1, -14512.75, 119.6925, -0.5760646, 3.48186, 120, 0, 0), -- Crab (Area: Wild Shore)
(@CGUID+535, 2544, 0, 1, 1, -14508.38, 174.2405, 2.733512, 2.221175, 120, 0, 0), -- Southern Sand Crawler (Area: Wild Shore)
(@CGUID+536, 49928, 0, 1, 1, -14516.84, 200.3695, 31.71583, 5.142557, 120, 0, 0), -- Crimson Moth (Area: Wild Shore)
(@CGUID+537, 1653, 0, 1, 1, -14525, 175, 2.636466, 5.931272, 120, 0, 0), -- Bloodsail Elder Magus (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+538, 6827, 0, 1, 1, -14487.85, 151.1977, 3.813812, 2.043477, 120, 0, 0), -- Crab (Area: Wild Shore)
(@CGUID+539, 50479, 0, 1, 1, -14518.96, 356.984, 94.39688, 2.355569, 120, 0, 0), -- Lizard Hatchling (Area: Wild Shore)
(@CGUID+540, 2848, 0, 1, 1, -14491.58, 425.1771, 34.67647, 0.9599311, 120, 0, 0), -- Glyx Brewright (Area: Booty Bay)
(@CGUID+541, 2837, 0, 1, 1, -14486.66, 431.5121, 34.66819, 4.782202, 120, 0, 0), -- Jaxin Chong (Area: Booty Bay)
(@CGUID+542, 4624, 0, 1, 1, -14481.5, 437.248, 34.37223, 6.178465, 120, 0, 0), -- Booty Bay Bruiser (Area: Booty Bay)
(@CGUID+543, 49636, 0, 1, 1, -14467.05, 460.5764, 15.25037, 6.126106, 120, 0, 0), -- Arcanist Arman (Area: Booty Bay)
(@CGUID+544, 4624, 0, 1, 1, -14471.86, 455.4617, 30.48594, 4.393156, 120, 0, 0), -- Booty Bay Bruiser (Area: Booty Bay) (possible waypoints or random movement)
(@CGUID+545, 4076, 0, 1, 1, -14468.55, 457.5136, 30.51397, 4.855299, 120, 0, 0), -- Roach (Area: Booty Bay)
(@CGUID+546, 908, 0, 1, 1, -14481.14, 451.7318, 30.69566, 6.038839, 120, 0, 0), -- Flora Silverwind (Area: Booty Bay)
(@CGUID+547, 2859, 0, 1, 1, -14477.9, 464.101, 36.46563, 6.143559, 120, 0, 0), -- Gyll (Area: Booty Bay)
(@CGUID+548, 4624, 0, 1, 1, -14471.41, 468.4601, 36.53928, 4.29351, 120, 0, 0), -- Booty Bay Bruiser (Area: Booty Bay)
(@CGUID+549, 4624, 0, 1, 1, -14488.48, 460.4375, 30.71514, 0.06981317, 120, 0, 0), -- Booty Bay Bruiser (Area: Booty Bay)
(@CGUID+550, 49635, 0, 1, 1, -14473.36, 471.3958, 30.8786, 5.427974, 120, 0, 0), -- War-Mage Erallier (Area: Booty Bay)
(@CGUID+551, 2843, 0, 1, 1, -14467.77, 468.375, 15.10633, 0.1396263, 120, 0, 0), -- Jutak (Area: Booty Bay)
(@CGUID+552, 47667, 0, 1, 1, -14497.2, 460.4008, 30.76498, 3.998372, 120, 0, 0), -- Wharf Rat (Area: Booty Bay)
(@CGUID+553, 4624, 0, 1, 1, -14465.08, 474.9278, 15.03919, 6.038839, 120, 0, 0), -- Booty Bay Bruiser (Area: Booty Bay)
(@CGUID+554, 2542, 0, 1, 1, -14467, 479.833, 20.46773, 0.8203048, 120, 0, 0), -- Catelyn the Blade (Area: Booty Bay)
(@CGUID+555, 48972, 0, 1, 1, -14460.86, 484.3831, 20.37343, 0.8279857, 120, 0, 0), -- Long-tailed Mole (Area: Booty Bay)
(@CGUID+556, 4624, 0, 1, 1, -14472.04, 483.9948, 20.465, 0.6283185, 120, 0, 0), -- Booty Bay Bruiser (Area: Booty Bay)
(@CGUID+557, 4624, 0, 1, 1, -14457.22, 494.8703, 26.35823, 1.029744, 120, 0, 0), -- Booty Bay Bruiser (Area: Booty Bay)
(@CGUID+558, 2491, 0, 1, 1, -14463.6, 489.274, 15.20493, 1.012291, 120, 0, 0), -- Whiskey Slim (Area: Booty Bay)
(@CGUID+559, 6807, 0, 1, 1, -14457.73, 495.3478, 15.21285, 3.979351, 120, 0, 0), -- Innkeeper Skindle (Area: Booty Bay)
(@CGUID+560, 2488, 0, 1, 1, -14459.2, 503, 26.35923, 4.869469, 120, 0, 0), -- Deeg (Area: Booty Bay)
(@CGUID+561, 4624, 0, 1, 1, -14463.32, 502.349, 26.35558, 5.707227, 120, 0, 0), -- Booty Bay Bruiser (Area: Booty Bay)
(@CGUID+562, 4624, 0, 1, 1, -14460.96, 502.9427, 15.2055, 4.764749, 120, 0, 0), -- Booty Bay Bruiser (Area: Booty Bay)
(@CGUID+563, 1493, 0, 1, 1, -14238.12, 736.8124, 1.417217, 6.130315, 120, 0, 0), -- Mok'rash (Area: Booty Bay) (possible waypoints or random movement)
(@CGUID+564, 1411, 0, 1, 1, -14450.83, 509.6676, 21.85391, 4.066617, 120, 0, 0), -- Ian Strom (Area: Booty Bay)
(@CGUID+565, 49928, 0, 1, 1, -14461.57, 501.4661, 48.66385, 4.942985, 120, 0, 0), -- Crimson Moth (Area: Booty Bay)
(@CGUID+566, 737, 0, 1, 1, -14449.57, 514.0816, 26.59361, 6.178465, 120, 0, 0), -- Kebok (Area: Booty Bay)
(@CGUID+567, 4624, 0, 1, 1, -14445.73, 519.0208, 26.399, 5.340707, 120, 0, 0), -- Booty Bay Bruiser (Area: Booty Bay)
(@CGUID+568, 32520, 0, 1, 1, -5691.65, 5556.92, -1154.687, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Booty Bay)
(@CGUID+569, 32520, 0, 1, 1, -6014.71, 5479.63, -1208.007, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Booty Bay)
(@CGUID+570, 32520, 0, 1, 1, -6305.162, 5582.533, -1172.063, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Booty Bay)
(@CGUID+571, 32520, 0, 1, 1, -6148.39, 5539.97, -1207.787, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Booty Bay)
(@CGUID+572, 25109, 0, 1, 1, -14403.21, 415.1754, 10.42328, 0.5934119, 120, 0, 0), -- Rocket Chicken (Area: Booty Bay) (possible waypoints or random movement)
(@CGUID+573, 25078, 0, 1, 1, -14313.97, 589.9974, 6.092045, 3.699857, 120, 0, 0), -- Captain Krick Wrenchnozzle (Area: Booty Bay)
(@CGUID+574, 25094, 0, 1, 1, -14313.26, 594.5581, 18.62098, 2.813726, 120, 0, 0), -- Navigator Tah're (Area: Booty Bay)
(@CGUID+575, 6827, 0, 1, 1, -14557.4, -477.3368, 2.551184, 4.329351, 120, 0, 0), -- Crab (Area: The Crystal Shore)
(@CGUID+576, 6827, 0, 1, 1, -14546.39, -468.7227, 2.274084, 1.741399, 120, 0, 0), -- Crab (Area: The Crystal Shore)
(@CGUID+577, 2521, 0, 1, 1, -14550.55, -451.8579, 2.597416, 3.619052, 120, 0, 0), -- Skymane Gorilla (Area: The Crystal Shore)
(@CGUID+578, 43417, 0, 1, 1, -14584.85, -347.8137, 10.41148, 4.561374, 120, 0, 0), -- Skymane Bonobo (Area: The Crystal Shore) (possible waypoints or random movement)
(@CGUID+579, 43417, 0, 1, 1, -14553.02, -324.6657, 9.520397, 4.636216, 120, 0, 0), -- Skymane Bonobo (Area: The Crystal Shore) (possible waypoints or random movement)
(@CGUID+580, 2521, 0, 1, 1, -14554.38, -380.5491, 5.819871, 2.848191, 120, 0, 0), -- Skymane Gorilla (Area: The Crystal Shore)
(@CGUID+581, 15475, 0, 1, 1, -14529.75, -370.8674, 4.301223, 1.359824, 120, 0, 0), -- Beetle (Area: The Crystal Shore)
(@CGUID+582, 50479, 0, 1, 1, -14578.59, -289.3908, 12.35537, 3.342051, 120, 0, 0), -- Lizard Hatchling (Area: Jaguero Isle)
(@CGUID+583, 2521, 0, 1, 1, -14587.53, -285.5739, 11.92934, 4.089164, 120, 0, 0), -- Skymane Gorilla (Area: Jaguero Isle)
(@CGUID+584, 49928, 0, 1, 1, -14556.63, -262.8419, 24.0993, 0.5511924, 120, 0, 0), -- Crimson Moth (Area: Jaguero Isle)
(@CGUID+585, 15475, 0, 1, 1, -14577.03, -223.9787, 13.27154, 4.618548, 120, 0, 0), -- Beetle (Area: Jaguero Isle)
(@CGUID+586, 6827, 0, 1, 1, -14525.93, -115.1424, 1.755089, 5.481214, 120, 0, 0), -- Crab (Area: Jaguero Isle)
(@CGUID+587, 6827, 0, 1, 1, -14557.02, 157.9141, 1.322573, 4.430078, 120, 0, 0), -- Crab (Area: Wild Shore)
(@CGUID+588, 6827, 0, 1, 1, -14602.33, 182.1541, 1.389351, 6.149859, 120, 0, 0), -- Crab (Area: Wild Shore)
(@CGUID+589, 6827, 0, 1, 1, -14606.8, 161.5431, 0.941175, 0.4270515, 120, 0, 0), -- Crab (Area: Wild Shore)
(@CGUID+590, 32520, 0, 1, 1, -6014.71, 5479.63, -1208.007, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Booty Bay)
(@CGUID+591, 32520, 0, 1, 1, -5691.65, 5556.92, -1154.687, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Booty Bay)
(@CGUID+592, 32520, 0, 1, 1, -6148.39, 5539.97, -1207.787, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Booty Bay)
(@CGUID+593, 32520, 0, 1, 1, -6305.162, 5582.533, -1172.063, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Booty Bay)
(@CGUID+594, 4076, 0, 1, 1, -14433.63, 449.7101, 15.48495, 0.9385983, 120, 0, 0), -- Roach (Area: Booty Bay)
(@CGUID+595, 49722, 0, 1, 1, -14557.01, 440.9829, 107.9237, 4.775484, 120, 0, 0), -- Tree Python (Area: Booty Bay) (possible waypoints or random movement)
(@CGUID+596, 15475, 0, 1, 1, -14557.57, 427.6373, 107.3205, 4.728227, 120, 0, 0), -- Beetle (Area: Booty Bay)
(@CGUID+597, 50479, 0, 1, 1, -14578.85, 513.0482, 104.6779, 2.98855, 120, 0, 0), -- Lizard Hatchling (Area: Booty Bay)
(@CGUID+598, 1653, 0, 1, 1, -14585.83, 283.271, 4.960762, 3.797657, 120, 0, 0), -- Bloodsail Elder Magus (Area: Booty Bay) (possible waypoints or random movement)
(@CGUID+599, 1565, 0, 1, 1, -14606.5, 328.6544, 2.771346, 3.036873, 120, 0, 0), -- Bloodsail Sea Dog (Area: Booty Bay)
(@CGUID+600, 1565, 0, 1, 1, -14611.83, 330.7428, 2.8415, 5.550147, 120, 0, 0), -- Bloodsail Sea Dog (Area: Booty Bay)
(@CGUID+601, 49928, 0, 1, 1, -14598.92, -141.3417, 33.11886, 5.71358, 120, 0, 0), -- Crimson Moth (Area: Wild Shore)
(@CGUID+602, 6827, 0, 1, 1, -14591.97, -117.5621, 2.525876, 3.926991, 120, 0, 0), -- Crab (Area: Wild Shore)
(@CGUID+603, 2522, 0, 1, 1, -14514.69, -120.0731, 2.071897, 4.86535, 120, 0, 0), -- Jaguero Stalker (Area: Wild Shore)
(@CGUID+604, 2522, 0, 1, 1, -14498.19, -186.9653, 10.51251, 3.627071, 120, 0, 0), -- Jaguero Stalker (Area: Jaguero Isle)
(@CGUID+605, 2634, 0, 1, 1, -14596.72, -237.9673, 24.87579, 1.745329, 120, 0, 0), -- Princess Poobah (Area: Jaguero Isle)
(@CGUID+606, 49928, 0, 1, 1, -14644.05, -339.293, 22.96324, 3.866327, 120, 0, 0), -- Crimson Moth (Area: Jaguero Isle)
(@CGUID+607, 43417, 0, 1, 1, -14631.51, -316.7866, 8.509788, 6.020442, 120, 0, 0), -- Skymane Bonobo (Area: Jaguero Isle) (possible waypoints or random movement)
(@CGUID+608, 2521, 0, 1, 1, -14615.87, -377.8207, 7.791786, 2.054546, 120, 0, 0), -- Skymane Gorilla (Area: Jaguero Isle)
(@CGUID+609, 43417, 0, 1, 1, -14646.39, -347.9503, 7.965473, 5.94909, 120, 0, 0), -- Skymane Bonobo (Area: Jaguero Isle) (possible waypoints or random movement)
(@CGUID+610, 6827, 0, 1, 1, -14592.58, -475.9072, 0.7523727, 4.067186, 120, 0, 0), -- Crab (Area: Jaguero Isle)
(@CGUID+611, 43417, 0, 1, 1, -14615.99, -449.3469, 1.582464, 1.29838, 120, 0, 0), -- Skymane Bonobo (Area: Jaguero Isle) (possible waypoints or random movement)
(@CGUID+612, 6827, 0, 1, 1, -14694.97, -458.703, 1.336576, 6.089117, 120, 0, 0), -- Crab (Area: The Crystal Shore)
(@CGUID+613, 2521, 0, 1, 1, -14685.69, -448.6931, 2.070436, 5.224687, 120, 0, 0), -- Skymane Gorilla (Area: The Crystal Shore)
(@CGUID+614, 6827, 0, 1, 1, -14691.94, -475.5213, 0.1730022, 3.454718, 120, 0, 0), -- Crab (Area: The Crystal Shore)
(@CGUID+615, 43417, 0, 1, 1, -14646.92, -411.0436, 6.075826, 1.709931, 120, 0, 0), -- Skymane Bonobo (Area: The Crystal Shore) (possible waypoints or random movement)
(@CGUID+616, 50487, 0, 1, 1, -14707.34, -351.7177, 7.595786, 5.78898, 120, 0, 0), -- Forest Spiderling (Area: Jaguero Isle) (possible waypoints or random movement)
(@CGUID+617, 49722, 0, 1, 1, -14642.2, -191.0581, 9.570661, 3.852584, 120, 0, 0), -- Tree Python (Area: Jaguero Isle) (possible waypoints or random movement)
(@CGUID+618, 2522, 0, 1, 1, -14616.36, -200.749, 12.27474, 1.510898, 120, 0, 0), -- Jaguero Stalker (Area: Jaguero Isle)
(@CGUID+619, 2522, 0, 1, 1, -14617.86, -219.0352, 16.80237, 2.152746, 120, 0, 0), -- Jaguero Stalker (Area: Jaguero Isle)
(@CGUID+620, 2522, 0, 1, 1, -14585.8, -196.897, 13.53572, 3.529471, 120, 0, 0), -- Jaguero Stalker (Area: Jaguero Isle)
(@CGUID+621, 49928, 0, 1, 1, -14624.88, -130.932, 30.25167, 5.262848, 120, 0, 0), -- Crimson Moth (Area: Jaguero Isle)
(@CGUID+622, 6827, 0, 1, 1, -14627.37, -88.40337, 0.5836697, 3.465535, 120, 0, 0), -- Crab (Area: Jaguero Isle)
(@CGUID+623, 6827, 0, 1, 1, -14648.13, -89.79315, -0.3601933, 3.235693, 120, 0, 0), -- Crab (Area: Jaguero Isle)
(@CGUID+624, 2522, 0, 1, 1, -14549.27, -251.2599, 9.531158, 1.723788, 120, 0, 0), -- Jaguero Stalker (Area: Jaguero Isle)
(@CGUID+625, 6827, 0, 1, 1, -14719.17, -108.9656, 1.049525, 3.112677, 120, 0, 0), -- Crab (Area: Jaguero Isle)
(@CGUID+626, 2522, 0, 1, 1, -14611.79, -111.0563, 1.652592, 3.954608, 120, 0, 0), -- Jaguero Stalker (Area: Jaguero Isle)
(@CGUID+627, 6827, 0, 1, 1, -14676.08, 158.8685, 1.892256, 1.250899, 120, 0, 0), -- Crab (Area: Wild Shore)
(@CGUID+628, 2544, 0, 1, 1, -14682.58, 165.8749, -2.085665, 5.483976, 120, 0, 0), -- Southern Sand Crawler (Area: Wild Shore)
(@CGUID+629, 6827, 0, 1, 1, -14638.88, 145.1638, 1.424809, 5.308044, 120, 0, 0), -- Crab (Area: Wild Shore)
(@CGUID+630, 6827, 0, 1, 1, -14663.82, 178.4799, -0.4339578, 4.636216, 120, 0, 0), -- Crab (Area: Wild Shore)
(@CGUID+631, 2544, 0, 1, 1, -14668.74, 253.8525, 1.107848, 2.512115, 120, 0, 0), -- Southern Sand Crawler (Area: Wild Shore)
(@CGUID+632, 6827, 0, 1, 1, -14640.49, 222.3357, 1.381756, 4.42492, 120, 0, 0), -- Crab (Area: Wild Shore)
(@CGUID+633, 6827, 0, 1, 1, -14655.58, 248.7208, 1.22493, 2.662242, 120, 0, 0), -- Crab (Area: Wild Shore)
(@CGUID+634, 1565, 0, 1, 1, -14620.51, 245.8391, 0.7788817, 3.930064, 120, 0, 0), -- Bloodsail Sea Dog (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+635, 6827, 0, 1, 1, -14702.67, 273.2397, -0.05586147, 2.594555, 120, 0, 0), -- Crab (Area: Wild Shore)
(@CGUID+636, 6827, 0, 1, 1, -14626.77, 274.6518, 1.828451, 0.1254002, 120, 0, 0), -- Crab (Area: Wild Shore)
(@CGUID+637, 6827, 0, 1, 1, -14656.54, 291.0623, 3.568102, 3.395229, 120, 0, 0), -- Crab (Area: Wild Shore)
(@CGUID+638, 6827, 0, 1, 1, -14718.02, 308.2104, 2.114366, 2.948798, 120, 0, 0), -- Crab (Area: Wild Shore)
(@CGUID+639, 6827, 0, 1, 1, -14686.54, 346.0722, 5.80128, 1.678434, 120, 0, 0), -- Crab (Area: Wild Shore)
(@CGUID+640, 2544, 0, 1, 1, -14705.48, 342.6183, 3.509479, 3.581477, 120, 0, 0), -- Southern Sand Crawler (Area: Wild Shore)
(@CGUID+641, 2544, 0, 1, 1, -14677.1, 309.2784, 0.7352014, 2.466852, 120, 0, 0), -- Southern Sand Crawler (Area: Wild Shore)
(@CGUID+642, 6827, 0, 1, 1, -14675.16, 349.3349, 3.02288, 3.120111, 120, 0, 0), -- Crab (Area: Wild Shore)
(@CGUID+643, 1653, 0, 1, 1, -14622.18, 308.6622, 3.262237, 5.354143, 120, 0, 0), -- Bloodsail Elder Magus (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+644, 1653, 0, 1, 1, -14649.6, 321.5546, 3.49435, 5.750373, 120, 0, 0), -- Bloodsail Elder Magus (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+645, 1565, 0, 1, 1, -14627.6, 358.0401, 4.518716, 3.874743, 120, 0, 0), -- Bloodsail Sea Dog (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+646, 6827, 0, 1, 1, -14708.83, 357.6837, 0.3831251, 4.816141, 120, 0, 0), -- Crab (Area: Wild Shore)
(@CGUID+647, 6827, 0, 1, 1, -14700.74, 390.4113, -0.9060593, 1.495215, 120, 0, 0), -- Crab (Area: Wild Shore)
(@CGUID+648, 6827, 0, 1, 1, -14695.66, 450.5513, 1.222956, 4.348584, 120, 0, 0), -- Crab (Area: Wild Shore)
(@CGUID+649, 6827, 0, 1, 1, -14674.84, 429.3122, 2.817021, 1.990117, 120, 0, 0), -- Crab (Area: Wild Shore)
(@CGUID+650, 1565, 0, 1, 1, -14675.18, 413.5158, 3.923711, 4.3299, 120, 0, 0), -- Bloodsail Sea Dog (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+651, 1653, 0, 1, 1, -14681.74, 456.4443, 3.26507, 2.184294, 120, 0, 0), -- Bloodsail Elder Magus (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+652, 2672, 0, 1, 1, -14677.54, 497.8901, 1.760323, 3.01942, 120, 0, 0), -- Cowardly Crosby (Area: Wild Shore)
(@CGUID+653, 6827, 0, 1, 1, -14733.33, 468.6684, 1.80045, 4.09782, 120, 0, 0), -- Crab (Area: Wild Shore)
(@CGUID+654, 2544, 0, 1, 1, -14736.89, 461.6313, -0.03379202, 3.881379, 120, 0, 0), -- Southern Sand Crawler (Area: Wild Shore)
(@CGUID+655, 1565, 0, 1, 1, -14695.08, 521.7481, 1.178477, 2.250524, 120, 0, 0), -- Bloodsail Sea Dog (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+656, 1565, 0, 1, 1, -14689.27, 485.1924, 3.026234, 4.813778, 120, 0, 0), -- Bloodsail Sea Dog (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+657, 1653, 0, 1, 1, -14700.27, 499.9155, 2.64696, 0.05235988, 120, 0, 0), -- Bloodsail Elder Magus (Area: Wild Shore)
(@CGUID+658, 1653, 0, 1, 1, -14682.7, 507.3636, 1.232432, 6.219872, 120, 0, 0), -- Bloodsail Elder Magus (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+659, 1565, 0, 1, 1, -14718.63, 477.971, 3.065295, 3.372432, 120, 0, 0), -- Bloodsail Sea Dog (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+660, 2544, 0, 1, 1, -14755.07, 521.8347, 1.786534, 1.224147, 120, 0, 0), -- Southern Sand Crawler (Area: Wild Shore)
(@CGUID+661, 6827, 0, 1, 1, -14742.6, 528.2051, 3.185948, 6.124453, 120, 0, 0), -- Crab (Area: Wild Shore)
(@CGUID+662, 6827, 0, 1, 1, -14725.08, 529.3771, 3.206688, 1.761301, 120, 0, 0), -- Crab (Area: Wild Shore)
(@CGUID+663, 1565, 0, 1, 1, -14719.17, 526.6913, 2.794457, 3.910729, 120, 0, 0), -- Bloodsail Sea Dog (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+664, 1565, 0, 1, 1, -14745.16, 497.583, 3.078404, 5.004909, 120, 0, 0), -- Bloodsail Sea Dog (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+665, 6827, 0, 1, 1, -14739.31, 508.7415, 3.560948, 2.830569, 120, 0, 0), -- Crab (Area: Wild Shore)
(@CGUID+666, 5434, 0, 1, 1, -14628.42, 968.105, -46.00445, 5.612065, 120, 0, 0), -- Coral Shark (Area: Southern Savage Coast) (possible waypoints or random movement)
(@CGUID+667, 6827, 0, 1, 1, -14795.81, 584.2983, -2.911234, 1.851778, 120, 0, 0), -- Crab (Area: Southern Savage Coast)
(@CGUID+668, 2544, 0, 1, 1, -14794.84, 586.1174, -3.383316, 5.450861, 120, 0, 0), -- Southern Sand Crawler (Area: Southern Savage Coast)
(@CGUID+669, 32520, 0, 1, 1, -6148.39, 5539.97, -1207.787, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Wild Shore)
(@CGUID+670, 32520, 0, 1, 1, -6305.162, 5582.533, -1172.063, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Wild Shore)
(@CGUID+671, 32520, 0, 1, 1, -6014.71, 5479.63, -1208.007, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Wild Shore)
(@CGUID+672, 32520, 0, 1, 1, -5691.65, 5556.92, -1154.687, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Wild Shore)
(@CGUID+673, 2544, 0, 1, 1, -14742.01, 29.87047, 2.578864, 1.807252, 120, 0, 0), -- Southern Sand Crawler (Area: Wild Shore)
(@CGUID+674, 6827, 0, 1, 1, -14738.27, 29.39648, 1.25023, 5.481214, 120, 0, 0), -- Crab (Area: Wild Shore)
(@CGUID+675, 6827, 0, 1, 1, -14748.5, 38.81682, 4.120934, 3.212627, 120, 0, 0), -- Crab (Area: Wild Shore)
(@CGUID+676, 2544, 0, 1, 1, -14752.11, 19.54233, -0.3702326, 3.906691, 120, 0, 0), -- Southern Sand Crawler (Area: Wild Shore)
(@CGUID+677, 2522, 0, 1, 1, -14655.75, -155.2231, 6.190807, 0.007812341, 120, 0, 0), -- Jaguero Stalker (Area: Jaguero Isle)
(@CGUID+678, 50487, 0, 1, 1, -14744.78, -253.4746, 6.462645, 4.507711, 120, 0, 0), -- Forest Spiderling (Area: Jaguero Isle) (possible waypoints or random movement)
(@CGUID+679, 15475, 0, 1, 1, -14739.59, -225.2145, 4.077653, 3.342051, 120, 0, 0), -- Beetle (Area: Jaguero Isle)
(@CGUID+680, 49928, 0, 1, 1, -14736.91, -240.279, 24.09295, 0.009736658, 120, 0, 0), -- Crimson Moth (Area: Jaguero Isle)
(@CGUID+681, 1559, 0, 1, 1, -14718.29, -387.5852, 8.365532, 0.6834695, 120, 0, 0), -- King Mukla (Area: Jaguero Isle) (possible waypoints or random movement)
(@CGUID+682, 2521, 0, 1, 1, -14734.64, -359.7122, 5.870247, 2.45036, 120, 0, 0), -- Skymane Gorilla (Area: Jaguero Isle)
(@CGUID+683, 6827, 0, 1, 1, -14728.06, -477.7033, 1.842819, 5.960767, 120, 0, 0), -- Crab (Area: Jaguero Isle)
(@CGUID+684, 2521, 0, 1, 1, -14746.47, -453.6086, 2.001855, 4.698092, 120, 0, 0), -- Skymane Gorilla (Area: Jaguero Isle)
(@CGUID+685, 6827, 0, 1, 1, -14801.16, -461.2259, -1.689177, 4.180478, 120, 0, 0), -- Crab (Area: The Crystal Shore)
(@CGUID+686, 6827, 0, 1, 1, -14784.34, -473.6126, -1.50156, 3.752072, 120, 0, 0), -- Crab (Area: The Crystal Shore)
(@CGUID+687, 6827, 0, 1, 1, -14773.92, -436.4882, 2.722855, 4.60281, 120, 0, 0), -- Crab (Area: The Crystal Shore)
(@CGUID+688, 2521, 0, 1, 1, -14791.55, -408.5531, 4.955015, 1.719268, 120, 0, 0), -- Skymane Gorilla (Area: The Crystal Shore)
(@CGUID+689, 49722, 0, 1, 1, -14810.11, -341.8384, 5.297628, 1.707996, 120, 0, 0), -- Tree Python (Area: The Crystal Shore) (possible waypoints or random movement)
(@CGUID+690, 15475, 0, 1, 1, -14802.29, -368.9201, 7.751246, 3.074176, 120, 0, 0), -- Beetle (Area: The Crystal Shore)
(@CGUID+691, 9600, 0, 1, 1, -14770.42, -293.461, 25.59236, 0.7622007, 120, 0, 0), -- Parrot (Area: The Crystal Shore)
(@CGUID+692, 15475, 0, 1, 1, -14819.27, -235.9668, 5.536745, 0.4164386, 120, 0, 0), -- Beetle (Area: Jaguero Isle)
(@CGUID+693, 6827, 0, 1, 1, -14823.1, -149.3475, 4.6249, 1.817063, 120, 0, 0), -- Crab (Area: Jaguero Isle)
(@CGUID+694, 9600, 0, 1, 1, -14765.47, -150.3097, 20.48782, 2.349188, 120, 0, 0), -- Parrot (Area: Jaguero Isle)
(@CGUID+695, 6827, 0, 1, 1, -14796.3, -102.7006, 1.453326, 0.0765328, 120, 0, 0), -- Crab (Area: Jaguero Isle)
(@CGUID+696, 2522, 0, 1, 1, -14711.9, -182.8325, 7.297337, 0.9682339, 120, 0, 0), -- Jaguero Stalker (Area: Jaguero Isle)
(@CGUID+697, 2522, 0, 1, 1, -14751.86, -179.6633, 4.713102, 2.59044, 120, 0, 0), -- Jaguero Stalker (Area: Jaguero Isle)
(@CGUID+698, 2522, 0, 1, 1, -14723.33, -105.3331, 1.245122, 6.201408, 120, 0, 0), -- Jaguero Stalker (Area: Jaguero Isle)
(@CGUID+699, 6827, 0, 1, 1, -14820.88, 50.37789, 2.434994, 1.651914, 120, 0, 0), -- Crab (Area: Jaguero Isle)
(@CGUID+700, 9600, 0, 1, 1, -14819.31, 42.54181, 33.93343, 4.259487, 120, 0, 0), -- Parrot (Area: Jaguero Isle)
(@CGUID+701, 49928, 0, 1, 1, -14825.78, 26.60225, 40.37243, 3.620299, 120, 0, 0), -- Crimson Moth (Area: Jaguero Isle)
(@CGUID+702, 2544, 0, 1, 1, -14809.01, 25.95398, 3.307196, 4.99782, 120, 0, 0), -- Southern Sand Crawler (Area: Jaguero Isle)
(@CGUID+703, 6827, 0, 1, 1, -14805.79, 15.4663, 2.645724, 1.801105, 120, 0, 0), -- Crab (Area: Jaguero Isle)
(@CGUID+704, 2544, 0, 1, 1, -14825.99, 262.2277, -13.54158, 5.461891, 120, 0, 0), -- Southern Sand Crawler (Area: Wild Shore)
(@CGUID+705, 6827, 0, 1, 1, -14830.17, 314.127, 0.9217224, 5.144814, 120, 0, 0), -- Crab (Area: Wild Shore)
(@CGUID+706, 2544, 0, 1, 1, -14807.53, 340.5234, -19.27042, 0.1371997, 120, 0, 0), -- Southern Sand Crawler (Area: Wild Shore)
(@CGUID+707, 2544, 0, 1, 1, -14799.94, 468.3516, -1.720072, 4.238271, 120, 0, 0), -- Southern Sand Crawler (Area: Wild Shore)
(@CGUID+708, 2544, 0, 1, 1, -14824.05, 457.7126, 1.366778, 5.866512, 120, 0, 0), -- Southern Sand Crawler (Area: Wild Shore)
(@CGUID+709, 6827, 0, 1, 1, -14819.22, 472.437, 0.9458218, 1.441599, 120, 0, 0), -- Crab (Area: Wild Shore)
(@CGUID+710, 6827, 0, 1, 1, -14834.11, 461.6959, -1.52749, 2.477055, 120, 0, 0), -- Crab (Area: Wild Shore)
(@CGUID+711, 6827, 0, 1, 1, -14835.73, 581.1735, 0.9333, 3.008456, 120, 0, 0), -- Crab (Area: Wild Shore)
(@CGUID+712, 2544, 0, 1, 1, -14834.55, 577.8315, -0.4980965, 2.710894, 120, 0, 0), -- Southern Sand Crawler (Area: Wild Shore)
(@CGUID+713, 2544, 0, 1, 1, -14865.25, 513.9872, -1.286329, 3.010689, 120, 0, 0), -- Southern Sand Crawler (Area: Wild Shore)
(@CGUID+714, 6827, 0, 1, 1, -14858.95, 385.5647, -1.219955, 2.242794, 120, 0, 0), -- Crab (Area: Wild Shore)
(@CGUID+715, 2544, 0, 1, 1, -14897.43, 456.8298, -0.9506474, 3.847475, 120, 0, 0), -- Southern Sand Crawler (Area: Wild Shore)
(@CGUID+716, 6827, 0, 1, 1, -14878.13, 467.709, -0.9006615, 1.576596, 120, 0, 0), -- Crab (Area: Wild Shore)
(@CGUID+717, 2544, 0, 1, 1, -14887.88, 452.5829, 2.860876, 0.2127318, 120, 0, 0), -- Southern Sand Crawler (Area: Wild Shore)
(@CGUID+718, 6827, 0, 1, 1, -14880.52, 344.2, 0.07063603, 6.237943, 120, 0, 0), -- Crab (Area: Wild Shore)
(@CGUID+719, 6827, 0, 1, 1, -14884.06, 288.9377, 1.306731, 6.276377, 120, 0, 0), -- Crab (Area: Wild Shore)
(@CGUID+720, 6827, 0, 1, 1, -14873.83, 372.0887, -3.004992, 2.364482, 120, 0, 0), -- Crab (Area: Wild Shore)
(@CGUID+721, 6827, 0, 1, 1, -14864.21, 327.1312, -2.436597, 0.7881606, 120, 0, 0), -- Crab (Area: Wild Shore)
(@CGUID+722, 43605, 0, 1, 1, -14876, 295.939, 0.5617793, 2.443461, 120, 0, 0), -- Bloodsail Oarsman (Area: Wild Shore)
(@CGUID+723, 1565, 0, 1, 1, -14873.71, 323.7694, 0.902215, 0.156482, 120, 0, 0), -- Bloodsail Sea Dog (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+724, 1653, 0, 1, 1, -14881.8, 306.4843, 2.339715, 0.07535045, 120, 0, 0), -- Bloodsail Elder Magus (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+725, 2544, 0, 1, 1, -14875.6, 325.5781, 1.585809, 0.09986317, 120, 0, 0), -- Southern Sand Crawler (Area: Wild Shore)
(@CGUID+726, 2544, 0, 1, 1, -14890.62, 386.5993, 2.71974, 6.199064, 120, 0, 0), -- Southern Sand Crawler (Area: Wild Shore)
(@CGUID+727, 6827, 0, 1, 1, -14857.49, 211.0577, -0.3307285, 1.030191, 120, 0, 0), -- Crab (Area: Wild Shore)
(@CGUID+728, 2544, 0, 1, 1, -14866.72, 207.3933, 1.310181, 4.023909, 120, 0, 0), -- Southern Sand Crawler (Area: Wild Shore)
(@CGUID+729, 2544, 0, 1, 1, -14842.56, 224.7313, -14.58366, 3.913381, 120, 0, 0), -- Southern Sand Crawler (Area: Wild Shore)
(@CGUID+730, 43561, 0, 1, 1, -14966.86, 184.4127, -0.269037, 1.241449, 120, 0, 0), -- Bloodsail Rowboat (Area: Wild Shore)
(@CGUID+731, 43560, 0, 1, 1, -14966.86, 184.4127, -0.269037, 1.241449, 120, 0, 0), -- Smilin' Timmy Sticks (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+732, 1653, 0, 1, 1, -14848.48, 74.16899, 2.287581, 0.03070787, 120, 0, 0), -- Bloodsail Elder Magus (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+733, 1565, 0, 1, 1, -14840.1, 60.38432, 3.193327, 2.984291, 120, 0, 0), -- Bloodsail Sea Dog (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+734, 6827, 0, 1, 1, -14835.47, -117.0411, -1.024897, 3.422575, 120, 0, 0), -- Crab (Area: Wild Shore)
(@CGUID+735, 6827, 0, 1, 1, -14860.8, -178.6146, 2.135872, 2.729518, 120, 0, 0), -- Crab (Area: Jaguero Isle)
(@CGUID+736, 2522, 0, 1, 1, -14803.82, -116.9317, 2.643178, 1.649438, 120, 0, 0), -- Jaguero Stalker (Area: Jaguero Isle)
(@CGUID+737, 2521, 0, 1, 1, -14869.27, -219.7519, 1.654367, 2.846395, 120, 0, 0), -- Skymane Gorilla (Area: Jaguero Isle)
(@CGUID+738, 2521, 0, 1, 1, -14850.92, -260.0347, 5.319139, 4.433284, 120, 0, 0), -- Skymane Gorilla (Area: Jaguero Isle)
(@CGUID+739, 6827, 0, 1, 1, -14859.21, -346.5513, 3.311169, 0.1568048, 120, 0, 0), -- Crab (Area: Jaguero Isle)
(@CGUID+740, 6827, 0, 1, 1, -14871.13, -369.7738, 1.007944, 1.801661, 120, 0, 0), -- Crab (Area: Jaguero Isle)
(@CGUID+741, 1559, 0, 1, 1, -14720.31, -386.1198, 8.625641, 1.228035, 120, 0, 0), -- King Mukla (Area: Jaguero Isle) (possible waypoints or random movement)
(@CGUID+742, 6827, 0, 1, 1, -14884.83, -343.5664, -0.782362, 3.170881, 120, 0, 0), -- Crab (Area: Wild Shore)
(@CGUID+743, 6827, 0, 1, 1, -14892.28, -302.5484, 1.192271, 5.375833, 120, 0, 0), -- Crab (Area: Wild Shore)
(@CGUID+744, 6827, 0, 1, 1, -14903.38, -202.3342, 0.4113669, 3.534431, 120, 0, 0), -- Crab (Area: Jaguero Isle)
(@CGUID+745, 6827, 0, 1, 1, -14878.24, -209.2124, 2.481216, 5.996032, 120, 0, 0), -- Crab (Area: Jaguero Isle)
(@CGUID+746, 2544, 0, 1, 1, -14913.28, -25.7463, 1.811599, 1.555173, 120, 0, 0), -- Southern Sand Crawler (Area: Jaguero Isle)
(@CGUID+747, 2544, 0, 1, 1, -14912.39, -15.56256, 2.335824, 1.45129, 120, 0, 0), -- Southern Sand Crawler (Area: Jaguero Isle)
(@CGUID+748, 2551, 0, 1, 1, -14923.7, 119.903, 19.79443, 4.974188, 120, 0, 0), -- Brutus (Area: Wild Shore)
(@CGUID+749, 4506, 0, 1, 1, -14923.45, 72.44122, 13.14812, 6.006314, 120, 0, 0), -- Bloodsail Swabby (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+750, 44182, 0, 1, 1, -14929.22, 114.7743, 7.60432, 4.834562, 120, 0, 0), -- Gurlgrl (Area: Wild Shore)
(@CGUID+751, 4506, 0, 1, 1, -14920.41, 89.43784, 12.92555, 0.008623487, 120, 0, 0), -- Bloodsail Swabby (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+752, 4506, 0, 1, 1, -14917.56, 79.56894, 12.996, 3.314254, 120, 0, 0), -- Bloodsail Swabby (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+753, 4506, 0, 1, 1, -14918.87, 107.4866, 17.72301, 2.467008, 120, 0, 0), -- Bloodsail Swabby (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+754, 4505, 0, 1, 1, -14915.9, 77.75, 7.521903, 4.785549, 120, 0, 0), -- Bloodsail Deckhand (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+755, 43659, 0, 1, 1, -14921.05, 85.38889, 7.60815, 4.764749, 120, 0, 0), -- Long John Copper (Area: Wild Shore)
(@CGUID+756, 4505, 0, 1, 1, -14917.6, 100.816, 7.521677, 4.587601, 120, 0, 0), -- Bloodsail Deckhand (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+757, 43636, 0, 1, 1, -14927.46, 86.72798, 0.2107679, 3.507652, 120, 0, 0), -- Bloodsail Corsair (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+758, 4505, 0, 1, 1, -14918.7, 111.359, 7.596754, 3.054326, 120, 0, 0), -- Bloodsail Deckhand (Area: Wild Shore)
(@CGUID+759, 43636, 0, 1, 1, -14922.88, 75.51595, 0.2323795, 5.159056, 120, 0, 0), -- Bloodsail Corsair (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+760, 4505, 0, 1, 1, -14921.08, 115.8125, 7.601703, 5.427974, 120, 0, 0), -- Bloodsail Deckhand (Area: Wild Shore)
(@CGUID+761, 43636, 0, 1, 1, -14918.47, 103.3945, 0.1757008, 4.941171, 120, 0, 0), -- Bloodsail Corsair (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+762, 43636, 0, 1, 1, -14925.8, 107.092, 0.2043794, 3.071699, 120, 0, 0), -- Bloodsail Corsair (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+763, 43636, 0, 1, 1, -14926.88, 98.31715, 0.1997156, 3.184508, 120, 0, 0), -- Bloodsail Corsair (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+764, 43536, 0, 1, 1, -14958.96, 153.8235, -18.85266, 1.209658, 120, 0, 0), -- Southsea Mako (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+765, 2544, 0, 1, 1, -14917.35, 208.7227, 2.58753, 4.883911, 120, 0, 0), -- Southern Sand Crawler (Area: Wild Shore)
(@CGUID+766, 43853, 0, 1, 1, -14949.92, 327.3017, 44.94571, 0.5526468, 120, 0, 0), -- Bloodsail Buzzard (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+767, 44179, 0, 1, 1, -14972.4, 266.6806, 13.83405, 3.193953, 120, 0, 0), -- Harry No-Hooks (Area: Wild Shore)
(@CGUID+768, 1653, 0, 1, 1, -14923.98, 308.8323, 3.851871, 5.338884, 120, 0, 0), -- Bloodsail Elder Magus (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+769, 2548, 0, 1, 1, -14926, 353.0522, 7.539413, 4.351534, 120, 0, 0), -- Captain Keelhaul (Area: Wild Shore)
(@CGUID+770, 2549, 0, 1, 1, -14934.43, 354.4844, 18.74334, 3.420845, 120, 0, 0), -- Garr Salthoof (Area: Wild Shore)
(@CGUID+771, 43853, 0, 1, 1, -14922.57, 353.7053, 59.97171, 5.539897, 120, 0, 0), -- Bloodsail Buzzard (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+772, 43636, 0, 1, 1, -14937.74, 350.1591, 0.2205799, 3.371783, 120, 0, 0), -- Bloodsail Corsair (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+773, 4506, 0, 1, 1, -14941.94, 355.986, 17.78543, 1.044212, 120, 0, 0), -- Bloodsail Swabby (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+774, 4505, 0, 1, 1, -14949.43, 345.8309, 7.542547, 0.2036206, 120, 0, 0), -- Bloodsail Deckhand (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+775, 4506, 0, 1, 1, -14951.83, 348.3874, 12.88041, 0.1358529, 120, 0, 0), -- Bloodsail Swabby (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+776, 43853, 0, 1, 1, -14952.95, 346.4469, 31.50069, 2.517235, 120, 0, 0), -- Bloodsail Buzzard (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+777, 43636, 0, 1, 1, -14945.02, 356.8163, 0.197732, 6.057612, 120, 0, 0), -- Bloodsail Corsair (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+778, 43853, 0, 1, 1, -14942.11, 356.4769, 60.27402, 2.516197, 120, 0, 0), -- Bloodsail Buzzard (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+779, 43853, 0, 1, 1, -14953.68, 357.5319, 23.8296, 2.51698, 120, 0, 0), -- Bloodsail Buzzard (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+780, 43853, 0, 1, 1, -14961.62, 344.6625, 31.15221, 3.766176, 120, 0, 0), -- Bloodsail Buzzard (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+781, 4506, 0, 1, 1, -14962.9, 341.6038, 7.543274, 0.2524829, 120, 0, 0), -- Bloodsail Swabby (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+782, 44178, 0, 1, 1, -14963.39, 346.467, 7.628381, 3.473205, 120, 0, 0), -- Sweet Gary Guns (Area: Wild Shore)
(@CGUID+783, 4506, 0, 1, 1, -14969.79, 342.124, 13.06037, 2.004339, 120, 0, 0), -- Bloodsail Swabby (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+784, 43636, 0, 1, 1, -14962.91, 353.9404, 0.2271792, 3.195309, 120, 0, 0), -- Bloodsail Corsair (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+785, 43853, 0, 1, 1, -14959.9, 358.7961, 40.63663, 3.766168, 120, 0, 0), -- Bloodsail Buzzard (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+786, 43636, 0, 1, 1, -14969.87, 341.8489, 0.225246, 3.307903, 120, 0, 0), -- Bloodsail Corsair (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+787, 43853, 0, 1, 1, -14963.36, 348.5493, 54.46236, 2.517106, 120, 0, 0), -- Bloodsail Buzzard (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+788, 4505, 0, 1, 1, -14971.08, 347.4488, 7.542551, 3.592707, 120, 0, 0), -- Bloodsail Deckhand (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+789, 43636, 0, 1, 1, -14971.7, 347.1474, 0.2554148, 0.5839423, 120, 0, 0), -- Bloodsail Corsair (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+790, 43661, 0, 1, 1, -14970.16, 354.441, 7.625889, 5.113815, 120, 0, 0), -- Wailing Mary Smitts (Area: Wild Shore)
(@CGUID+791, 2545, 0, 1, 1, -14978.7, 349.448, 13.16132, 3.553005, 120, 0, 0), -- "Pretty Boy" Duncan (Area: Wild Shore)
(@CGUID+792, 43536, 0, 1, 1, -15042.45, 400.1503, -31.29537, 1.948445, 120, 0, 0), -- Southsea Mako (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+793, 4506, 0, 1, 1, -14978.2, 344.939, 13.28413, 4.442354, 120, 0, 0), -- Bloodsail Swabby (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+794, 4505, 0, 1, 1, -14982.13, 272.701, 7.921533, 3.174515, 120, 0, 0), -- Bloodsail Deckhand (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+795, 4506, 0, 1, 1, -14989.06, 268.0877, 13.3308, 1.978552, 120, 0, 0), -- Bloodsail Swabby (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+796, 43636, 0, 1, 1, -14986.27, 271.6905, 0.5992714, 6.035472, 120, 0, 0), -- Bloodsail Corsair (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+797, 4506, 0, 1, 1, -15008.81, 269.3118, 18.01736, 0.3911352, 120, 0, 0), -- Bloodsail Swabby (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+798, 43636, 0, 1, 1, -14991.68, 268.6719, 0.6826044, 1.675516, 120, 0, 0), -- Bloodsail Corsair (Area: Wild Shore)
(@CGUID+799, 4505, 0, 1, 1, -14968.15, 264.2204, 4.793194, 1.570114, 120, 0, 0), -- Bloodsail Deckhand (Area: Wild Shore)
(@CGUID+800, 4506, 0, 1, 1, -15013.96, 267.4574, 18.64563, 2.980415, 120, 0, 0), -- Bloodsail Swabby (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+801, 43636, 0, 1, 1, -14979.4, 263.7512, 0.6345223, 0.3201078, 120, 0, 0), -- Bloodsail Corsair (Area: Wild Shore)
(@CGUID+802, 2547, 0, 1, 1, -15016.1, 270.2066, 8.004528, 0, 120, 0, 0), -- Ironpatch (Area: Wild Shore)
(@CGUID+803, 4505, 0, 1, 1, -15003.15, 263.6215, 8.004566, 0.03490658, 120, 0, 0), -- Bloodsail Deckhand (Area: Wild Shore)
(@CGUID+804, 43660, 0, 1, 1, -14995.92, 264.099, 0.6826044, 4.502949, 120, 0, 0), -- Enormous Shawn Stooker (Area: Wild Shore)
(@CGUID+805, 43636, 0, 1, 1, -14990.57, 261.7152, 0.599271, 4.921638, 120, 0, 0), -- Bloodsail Corsair (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+806, 43636, 0, 1, 1, -14999.58, 262.2863, 0.5992737, 5.446148, 120, 0, 0), -- Bloodsail Corsair (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+807, 43556, 0, 1, 1, -15022.64, 263.0063, 19.9276, 3.047329, 120, 0, 0), -- "Dead-Eye" Drederick McGumm (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+808, 4505, 0, 1, 1, -15003.32, 258.1215, 8.00457, 0.03490658, 120, 0, 0), -- Bloodsail Deckhand (Area: Wild Shore)
(@CGUID+809, 4505, 0, 1, 1, -15018.06, 262.0816, 8.004206, 0.03490658, 120, 0, 0), -- Bloodsail Deckhand (Area: Wild Shore)
(@CGUID+810, 2546, 0, 1, 1, -15025.41, 265.6684, 8.002296, 6.108652, 120, 0, 0), -- Fleet Master Firallon (Area: Wild Shore)
(@CGUID+811, 4505, 0, 1, 1, -15017.96, 259.9149, 8.003805, 0.03490658, 120, 0, 0), -- Bloodsail Deckhand (Area: Wild Shore)
(@CGUID+812, 43536, 0, 1, 1, -15043.06, 319.8554, -38.90707, 5.600019, 120, 0, 0), -- Southsea Mako (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+813, 43562, 0, 1, 1, -14982.09, 255.5052, 13.8994, 4.729842, 120, 0, 0), -- Ol' Blasty (Area: Wild Shore)
(@CGUID+814, 43562, 0, 1, 1, -14987.99, 255.9323, 13.66914, 4.694936, 120, 0, 0), -- Ol' Blasty (Area: Wild Shore)
(@CGUID+815, 43562, 0, 1, 1, -14994.45, 256.6788, 13.58666, 4.660029, 120, 0, 0), -- Ol' Blasty (Area: Wild Shore)
(@CGUID+816, 43536, 0, 1, 1, -15038.64, 270.7406, -35.04687, 6.059596, 120, 0, 0), -- Southsea Mako (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+817, 43536, 0, 1, 1, -15006.37, 180.4317, -19.33807, 3.825311, 120, 0, 0), -- Southsea Mako (Area: The Crimson Veil) (possible waypoints or random movement)
(@CGUID+818, 43536, 0, 1, 1, -15035.46, 195.627, -26.5857, 4.206016, 120, 0, 0), -- Southsea Mako (Area: The Crimson Veil) (possible waypoints or random movement)
(@CGUID+819, 43536, 0, 1, 1, -15012.53, 212.6799, -25.01446, 2.324405, 120, 0, 0), -- Southsea Mako (Area: The Crimson Veil) (possible waypoints or random movement)
(@CGUID+820, 43536, 0, 1, 1, -15025.19, 106.5544, -19.79087, 2.190097, 120, 0, 0), -- Southsea Mako (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+821, 43536, 0, 1, 1, -14984.31, 66.95543, -18.85266, 6.076022, 120, 0, 0), -- Southsea Mako (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+822, 43536, 0, 1, 1, -15067.43, 108.6923, -34.55836, 5.394861, 120, 0, 0), -- Southsea Mako (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+823, 43536, 0, 1, 1, -15070.3, 67.1337, -34.36827, 0, 120, 0, 0), -- Southsea Mako (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+824, 5434, 0, 1, 1, -15056.15, -794.8381, -49.29309, 1.175959, 120, 0, 0), -- Coral Shark (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+825, 32520, 0, 1, 1, -5691.65, 5556.92, -1154.687, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Wild Shore)
(@CGUID+826, 32520, 0, 1, 1, -6305.162, 5582.533, -1172.063, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Wild Shore)
(@CGUID+827, 32520, 0, 1, 1, -6148.39, 5539.97, -1207.787, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Wild Shore)
(@CGUID+828, 32520, 0, 1, 1, -6014.71, 5479.63, -1208.007, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Wild Shore)
(@CGUID+829, 43536, 0, 1, 1, -15098.67, 131.9787, -41.24268, 4.27799, 120, 0, 0), -- Southsea Mako (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+830, 43536, 0, 1, 1, -15102.17, 181.4226, -38.18507, 5.655581, 120, 0, 0), -- Southsea Mako (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+831, 43536, 0, 1, 1, -15120.93, 227.1481, -40.13207, 4.091092, 120, 0, 0), -- Southsea Mako (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+832, 43536, 0, 1, 1, -15109.2, 338.8472, -44.22577, 0.9655004, 120, 0, 0), -- Southsea Mako (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+833, 43536, 0, 1, 1, -15106.73, 275.3872, -41.18927, 5.676073, 120, 0, 0), -- Southsea Mako (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+834, 43536, 0, 1, 1, -15160.37, 297.0439, -44.24037, 4.385077, 120, 0, 0), -- Southsea Mako (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+835, 43536, 0, 1, 1, -15070.75, 396.9002, -40.63077, 3.098485, 120, 0, 0), -- Southsea Mako (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+836, 43536, 0, 1, 1, -15091.3, 433.3068, -37.56857, 5.303914, 120, 0, 0), -- Southsea Mako (Area: Wild Shore)
(@CGUID+837, 5434, 0, 1, 1, -15110.88, 698.03, -48.83912, 1.266756, 120, 0, 0), -- Coral Shark (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+838, 5434, 0, 1, 1, -15261.3, 618.1212, -45.95579, 1.673099, 120, 0, 0), -- Coral Shark (Area: Wild Shore) (possible waypoints or random movement)
(@CGUID+839, 43536, 0, 1, 1, -15166.43, 226.6814, -44.23897, 4.245167, 120, 0, 0), -- Southsea Mako (Area: Wild Shore)
(@CGUID+840, 5434, 0, 1, 1, -15167.6, 14.86471, -49.89647, 4.040042, 120, 0, 0); -- Coral Shark (Area: Wild Shore) (possible waypoints or random movement)

DELETE FROM `npc_vendor` WHERE `entry` IN (2664, 2664, 2664, 2664, 2664, 2664, 2664, 2664, 2664, 2664, 2664, 2664, 2663, 2663, 2663, 2839, 2839, 2685, 2685, 2685, 2685, 2685, 2685, 2685, 2685, 2685, 2685, 2685, 2685, 2685, 2685, 2685, 2685, 2482, 2482, 2482, 2482, 2482, 2482, 2482, 2482, 2482, 2482, 54232, 54232, 54232, 54232, 54232, 54232, 2842, 2842, 2842, 2842, 2842, 2842, 2699, 2699, 2699, 2699, 2699, 2699, 2699, 2699, 2699, 2699, 2699, 2699, 2699, 2699, 2699, 2699, 2699, 2699, 2847, 2847, 2847, 2847, 2847, 2847, 2845, 2845, 2845, 2845, 2845, 2845, 2845, 2845, 2845, 2844, 2844, 2844, 2844, 2844, 2844, 2670, 2670, 2670, 2670, 2670, 2670, 2670, 2670, 2670, 2670, 2670, 2670, 2670, 2670, 2670, 2670, 2670, 2846, 2846, 2846, 2846, 2846, 2846, 2846, 2846, 2846, 2846, 2846, 2846, 2846, 2846, 2846, 2846, 2846, 2849, 2849, 2849, 2849, 2849, 2849, 2849, 2849, 2849, 2849, 2849, 2849, 2849, 2849, 2849, 2849, 2849, 2849, 2849, 2849, 2849, 2849, 2849, 2849, 2849, 2849, 2849, 2849, 2849, 2849, 2849, 2849, 2849, 2848, 2848, 2848, 2843, 2843, 2843, 2843, 2843, 2843, 2843, 2843, 2832, 2832, 2832, 2832, 2832, 2832, 2832, 2832, 2832, 2832, 2832, 2832, 2832, 2832, 2832, 2832, 2832, 2832, 2832, 6807, 6807, 6807, 6807, 6807, 6807, 6807, 6807, 6807, 6807, 6807, 6807, 2672, 2672, 2672, 2672, 2672, 2672, 2672, 2672, 2672, 2672, 2672, 2672, 2672, 2672, 2672, 2672);
INSERT INTO `npc_vendor` (`entry`, `item`, `slot`, `maxcount`, `ExtendedCost`, `Type`) VALUES
-- 2664 (Kelsey Yance)
(2664, 159, 2, 0, 0, 1), -- Refreshing Spring Water
(2664, 30817, 3, 0, 0, 1), -- Simple Flour
(2664, 2678, 4, 0, 0, 1), -- Mild Spices
(2664, 21099, 5, 0, 0, 1), -- Recipe: Smoked Sagefish
(2664, 21219, 6, 0, 0, 1), -- Recipe: Sagefish Delight
(2664, 6039, 7, 0, 0, 1), -- Recipe: Giant Clam Scorcho
(2664, 6369, 8, 0, 0, 1), -- Recipe: Rockscale Cod
(2664, 17062, 9, 0, 0, 1), -- Recipe: Mithril Head Trout
(2664, 13948, 10, 0, 0, 1), -- Recipe: Mightfish Steak
(2664, 13940, 11, 0, 0, 1), -- Recipe: Cooked Glossy Mightfish
(2664, 13941, 12, 0, 0, 1), -- Recipe: Filet of Redgill
(2664, 13943, 13, 0, 0, 1), -- Recipe: Hot Smoked Bass
-- 2663 (Narkk)
(2663, 8495, 1, 0, 0, 1), -- Parrot Cage (Senegal)
(2663, 8496, 2, 0, 0, 1), -- Parrot Cage (Cockatiel)
(2663, 10728, 165, 1, 0, 1), -- Pattern: Black Swashbuckler's Shirt
-- 2839 (Haren Kanmae)
(2839, 3026, 1, 0, 0, 1), -- Reinforced Bow
(2839, 3027, 2, 0, 0, 1), -- Heavy Recurve Bow
-- 2840 (Kizz Bluntstrike)
-- 2685 (Mazk Snipeshot)
(2685, 5956, 1626, 0, 0, 1), -- Blacksmith Hammer
(2685, 2901, 1627, 0, 0, 1), -- Mining Pick
(2685, 4399, 1628, 0, 0, 1), -- Wooden Stock
(2685, 4400, 1629, 0, 0, 1), -- Heavy Stock
(2685, 40533, 1630, 0, 0, 1), -- Walnut Stock
(2685, 39684, 1631, 0, 0, 1), -- Hair Trigger
(2685, 2880, 1632, 0, 0, 1), -- Weak Flux
(2685, 3466, 1633, 0, 0, 1), -- Strong Flux
(2685, 10648, 1634, 0, 0, 1), -- Common Parchment
(2685, 10647, 1635, 0, 0, 1), -- Engineer's Ink
(2685, 4404, 1636, 1, 0, 1), -- Silver Contact
(2685, 4382, 1637, 1, 0, 1), -- Bronze Framework
(2685, 13310, 1641, 1, 0, 1), -- Schematic: Accurate Scope
(2685, 4361, 1638, 2, 0, 1), -- Bent Copper Tube
(2685, 4357, 1639, 4, 0, 1), -- Rough Blasting Powder
(2685, 4364, 1640, 4, 0, 1), -- Coarse Blasting Powder
-- 2482 (Zarena Cromwind)
(2482, 2520, 1, 0, 0, 1), -- Broadsword
(2482, 2521, 2, 0, 0, 1), -- Flamberge
(2482, 2522, 3, 0, 0, 1), -- Crescent Axe
(2482, 2523, 4, 0, 0, 1), -- Bullova
(2482, 2524, 5, 0, 0, 1), -- Truncheon
(2482, 2525, 6, 0, 0, 1), -- War Hammer
(2482, 2526, 7, 0, 0, 1), -- Main Gauche
(2482, 2527, 8, 0, 0, 1), -- Battle Staff
(2482, 29009, 9, 0, 0, 1), -- Heavy Throwing Dagger
(2482, 25875, 10, 0, 0, 1), -- Deadly Throwing Axe
-- 54232 (Mrs. Gant)
(54232, 159, 1, 0, 0, 1), -- Refreshing Spring Water
(54232, 30817, 2, 0, 0, 1), -- Simple Flour
(54232, 2678, 3, 0, 0, 1), -- Mild Spices
(54232, 21099, 4, 0, 0, 1), -- Recipe: Smoked Sagefish
(54232, 21219, 5, 0, 0, 1), -- Recipe: Sagefish Delight
(54232, 16767, 381, 1, 0, 1), -- Recipe: Undermine Clam Chowder
-- 2842 (Wigcik)
(2842, 787, 1, 0, 0, 1), -- Slitherskin Mackerel
(2842, 4592, 2, 0, 0, 1), -- Longjaw Mud Snapper
(2842, 4593, 3, 0, 0, 1), -- Bristle Whisker Catfish
(2842, 4594, 4, 0, 0, 1), -- Rockscale Cod
(2842, 21552, 5, 0, 0, 1), -- Striped Yellowtail
(2842, 8957, 6, 0, 0, 1), -- Spinefin Halibut
-- 2699 (Rikqiz)
(2699, 7005, 1, 0, 0, 1), -- Skinning Knife
(2699, 4289, 2, 0, 0, 1), -- Salt
(2699, 2320, 3, 0, 0, 1), -- Coarse Thread
(2699, 2321, 4, 0, 0, 1), -- Fine Thread
(2699, 4291, 5, 0, 0, 1), -- Silken Thread
(2699, 8343, 6, 0, 0, 1), -- Heavy Silken Thread
(2699, 14341, 7, 0, 0, 1), -- Rune Thread
(2699, 38426, 8, 0, 0, 1), -- Eternium Thread
(2699, 2325, 9, 0, 0, 1), -- Black Dye
(2699, 6260, 10, 0, 0, 1), -- Blue Dye
(2699, 2604, 11, 0, 0, 1), -- Red Dye
(2699, 2605, 12, 0, 0, 1), -- Green Dye
(2699, 4340, 13, 0, 0, 1), -- Gray Dye
(2699, 4341, 14, 0, 0, 1), -- Yellow Dye
(2699, 6261, 15, 0, 0, 1), -- Orange Dye
(2699, 4342, 16, 0, 0, 1), -- Purple Dye
(2699, 10290, 17, 0, 0, 1), -- Pink Dye
(2699, 14635, 86, 1, 0, 1), -- Pattern: Gem-Studded Leather Belt
-- 2847 (Jansen Underwood)
(2847, 2901, 1, 0, 0, 1), -- Mining Pick
(2847, 5956, 2, 0, 0, 1), -- Blacksmith Hammer
(2847, 2880, 3, 0, 0, 1), -- Weak Flux
(2847, 3466, 4, 0, 0, 1), -- Strong Flux
(2847, 18567, 5, 0, 0, 1), -- Elemental Flux
(2847, 3857, 6, 0, 0, 1), -- Coal
-- 2845 (Fargon Mortalak)
(2845, 2417, 1, 0, 0, 1), -- Augmented Chain Vest
(2845, 2419, 2, 0, 0, 1), -- Augmented Chain Belt
(2845, 2418, 3, 0, 0, 1), -- Augmented Chain Leggings
(2845, 2420, 4, 0, 0, 1), -- Augmented Chain Boots
(2845, 2421, 5, 0, 0, 1), -- Augmented Chain Bracers
(2845, 2422, 6, 0, 0, 1), -- Augmented Chain Gloves
(2845, 3891, 7, 0, 0, 1), -- Augmented Chain Helm
(2845, 17189, 8, 0, 0, 1), -- Metal Buckler
(2845, 2448, 9, 0, 0, 1), -- Heavy Pavise
-- 2844 (Hurklor)
(2844, 2901, 1, 0, 0, 1), -- Mining Pick
(2844, 5956, 2, 0, 0, 1), -- Blacksmith Hammer
(2844, 2880, 3, 0, 0, 1), -- Weak Flux
(2844, 3466, 4, 0, 0, 1), -- Strong Flux
(2844, 18567, 5, 0, 0, 1), -- Elemental Flux
(2844, 3857, 6, 0, 0, 1), -- Coal
-- 2670 (Xizk Goodstitch)
(2670, 2320, 1, 0, 0, 1), -- Coarse Thread
(2670, 2321, 2, 0, 0, 1), -- Fine Thread
(2670, 4291, 3, 0, 0, 1), -- Silken Thread
(2670, 8343, 4, 0, 0, 1), -- Heavy Silken Thread
(2670, 14341, 5, 0, 0, 1), -- Rune Thread
(2670, 38426, 6, 0, 0, 1), -- Eternium Thread
(2670, 2324, 7, 0, 0, 1), -- Bleach
(2670, 2604, 8, 0, 0, 1), -- Red Dye
(2670, 6260, 9, 0, 0, 1), -- Blue Dye
(2670, 2605, 10, 0, 0, 1), -- Green Dye
(2670, 4341, 11, 0, 0, 1), -- Yellow Dye
(2670, 4340, 12, 0, 0, 1), -- Gray Dye
(2670, 6261, 13, 0, 0, 1), -- Orange Dye
(2670, 2325, 14, 0, 0, 1), -- Black Dye
(2670, 4342, 15, 0, 0, 1), -- Purple Dye
(2670, 10290, 16, 0, 0, 1), -- Pink Dye
(2670, 14630, 168, 1, 0, 1), -- Pattern: Enchanter's Cowl
-- 2846 (Blixrez Goodstitch)
(2846, 7005, 1, 0, 0, 1), -- Skinning Knife
(2846, 4289, 2, 0, 0, 1), -- Salt
(2846, 2320, 3, 0, 0, 1), -- Coarse Thread
(2846, 2321, 4, 0, 0, 1), -- Fine Thread
(2846, 4291, 5, 0, 0, 1), -- Silken Thread
(2846, 8343, 6, 0, 0, 1), -- Heavy Silken Thread
(2846, 14341, 7, 0, 0, 1), -- Rune Thread
(2846, 38426, 8, 0, 0, 1), -- Eternium Thread
(2846, 2325, 9, 0, 0, 1), -- Black Dye
(2846, 6260, 10, 0, 0, 1), -- Blue Dye
(2846, 2604, 11, 0, 0, 1), -- Red Dye
(2846, 2605, 12, 0, 0, 1), -- Green Dye
(2846, 4340, 13, 0, 0, 1), -- Gray Dye
(2846, 4341, 14, 0, 0, 1), -- Yellow Dye
(2846, 6261, 15, 0, 0, 1), -- Orange Dye
(2846, 4342, 16, 0, 0, 1), -- Purple Dye
(2846, 10290, 17, 0, 0, 1), -- Pink Dye
-- 2849 (Qixdi Goodstitch)
(2849, 7338, 1, 0, 0, 1), -- Mood Ring
(2849, 7341, 2, 0, 0, 1), -- Cubic Zirconia Ring
(2849, 7342, 3, 0, 0, 1), -- Silver Piffeny Band
(2849, 7339, 4, 0, 0, 1), -- Miniscule Diamond Ring
(2849, 7340, 5, 0, 0, 1), -- Flawless Diamond Solitaire
(2849, 7337, 6, 0, 0, 1), -- The Rock
(2849, 200, 7, 0, 0, 1), -- Thick Cloth Vest
(2849, 3597, 8, 0, 0, 1), -- Thick Cloth Belt
(2849, 201, 9, 0, 0, 1), -- Thick Cloth Pants
(2849, 202, 10, 0, 0, 1), -- Thick Cloth Shoes
(2849, 3598, 11, 0, 0, 1), -- Thick Cloth Bracers
(2849, 203, 12, 0, 0, 1), -- Thick Cloth Gloves
(2849, 2160, 13, 0, 0, 1), -- Padded Armor
(2849, 3591, 14, 0, 0, 1), -- Padded Belt
(2849, 2159, 15, 0, 0, 1), -- Padded Pants
(2849, 2156, 16, 0, 0, 1), -- Padded Boots
(2849, 3592, 17, 0, 0, 1), -- Padded Bracers
(2849, 2158, 18, 0, 0, 1), -- Padded Gloves
(2849, 2429, 19, 0, 0, 1), -- Russet Vest
(2849, 3593, 20, 0, 0, 1), -- Russet Belt
(2849, 2431, 21, 0, 0, 1), -- Russet Pants
(2849, 2432, 22, 0, 0, 1), -- Russet Boots
(2849, 3594, 23, 0, 0, 1), -- Russet Bracers
(2849, 2434, 24, 0, 0, 1), -- Russet Gloves
(2849, 3889, 25, 0, 0, 1), -- Russet Hat
(2849, 2435, 26, 0, 0, 1), -- Embroidered Armor
(2849, 3587, 27, 0, 0, 1), -- Embroidered Belt
(2849, 2437, 28, 0, 0, 1), -- Embroidered Pants
(2849, 2438, 29, 0, 0, 1), -- Embroidered Boots
(2849, 3588, 30, 0, 0, 1), -- Embroidered Bracers
(2849, 2440, 31, 0, 0, 1), -- Embroidered Gloves
(2849, 3892, 32, 0, 0, 1), -- Embroidered Hat
(2849, 37934, 33, 1, 0, 1), -- Noble's Elementium Signet
-- 2848 (Glyx Brewright)
(2848, 3371, 1, 0, 0, 1), -- Crystal Vial
(2848, 6057, 466, 1, 0, 1), -- Recipe: Nature Protection Potion
(2848, 6056, 467, 1, 0, 1), -- Recipe: Frost Protection Potion
-- 2843 (Jutak)
(2843, 2526, 1, 0, 0, 1), -- Main Gauche
(2843, 2534, 2, 0, 0, 1), -- Rondel
(2843, 2520, 3, 0, 0, 1), -- Broadsword
(2843, 2528, 4, 0, 0, 1), -- Falchion
(2843, 2521, 5, 0, 0, 1), -- Flamberge
(2843, 2529, 6, 0, 0, 1), -- Zweihander
(2843, 29010, 7, 0, 0, 1), -- Wicked Throwing Dagger
(2843, 12162, 218, 1, 0, 1), -- Plans: Hardened Iron Shortsword
-- 2832 (Nixxrax Fillamug)
(2832, 4600, 1, 0, 0, 1), -- Cherry Grog
(2832, 4595, 2, 0, 0, 1), -- Junglevine Wine
(2832, 159, 3, 0, 0, 1), -- Refreshing Spring Water
(2832, 1179, 4, 0, 0, 1), -- Ice Cold Milk
(2832, 1205, 5, 0, 0, 1), -- Melon Juice
(2832, 1708, 6, 0, 0, 1), -- Sweet Nectar
(2832, 1645, 7, 0, 0, 1), -- Moonberry Juice
(2832, 8766, 8, 0, 0, 1), -- Morning Glory Dew
(2832, 2723, 9, 0, 0, 1), -- Bottle of Pinot Noir
(2832, 2593, 10, 0, 0, 1), -- Flask of Port
(2832, 2596, 11, 0, 0, 1), -- Skin of Dwarven Stout
(2832, 2594, 12, 0, 0, 1), -- Flagon of Mead
(2832, 2595, 13, 0, 0, 1), -- Jug of Bourbon
(2832, 4540, 14, 0, 0, 1), -- Tough Hunk of Bread
(2832, 4541, 15, 0, 0, 1), -- Freshly Baked Bread
(2832, 4542, 16, 0, 0, 1), -- Moist Cornbread
(2832, 4544, 17, 0, 0, 1), -- Mulgore Spice Bread
(2832, 4601, 18, 0, 0, 1), -- Soft Banana Bread
(2832, 8950, 19, 0, 0, 1), -- Homemade Cherry Pie
-- 6807 (Innkeeper Skindle)
(6807, 787, 1, 0, 0, 1), -- Slitherskin Mackerel
(6807, 4592, 2, 0, 0, 1), -- Longjaw Mud Snapper
(6807, 4593, 3, 0, 0, 1), -- Bristle Whisker Catfish
(6807, 4594, 4, 0, 0, 1), -- Rockscale Cod
(6807, 21552, 5, 0, 0, 1), -- Striped Yellowtail
(6807, 8957, 6, 0, 0, 1), -- Spinefin Halibut
(6807, 159, 7, 0, 0, 1), -- Refreshing Spring Water
(6807, 1179, 8, 0, 0, 1), -- Ice Cold Milk
(6807, 1205, 9, 0, 0, 1), -- Melon Juice
(6807, 1708, 10, 0, 0, 1), -- Sweet Nectar
(6807, 1645, 11, 0, 0, 1), -- Moonberry Juice
(6807, 8766, 12, 0, 0, 1), -- Morning Glory Dew
-- 2672 (Cowardly Crosby)
(2672, 2320, 1, 0, 0, 1), -- Coarse Thread
(2672, 2321, 2, 0, 0, 1), -- Fine Thread
(2672, 4291, 3, 0, 0, 1), -- Silken Thread
(2672, 8343, 4, 0, 0, 1), -- Heavy Silken Thread
(2672, 14341, 5, 0, 0, 1), -- Rune Thread
(2672, 38426, 6, 0, 0, 1), -- Eternium Thread
(2672, 2324, 7, 0, 0, 1), -- Bleach
(2672, 2604, 8, 0, 0, 1), -- Red Dye
(2672, 6260, 9, 0, 0, 1), -- Blue Dye
(2672, 2605, 10, 0, 0, 1), -- Green Dye
(2672, 4341, 11, 0, 0, 1), -- Yellow Dye
(2672, 4340, 12, 0, 0, 1), -- Gray Dye
(2672, 6261, 13, 0, 0, 1), -- Orange Dye
(2672, 2325, 14, 0, 0, 1), -- Black Dye
(2672, 4342, 15, 0, 0, 1), -- Purple Dye
(2672, 10290, 16, 0, 0, 1); -- Pink Dye

DELETE FROM `npc_text` WHERE `ID` IN (16440, 18046, 16437, 16441, 17598, 16418);
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `lang0`, `prob0`, `em0_0`, `em0_1`, `em0_2`, `em0_3`, `em0_4`, `em0_5`, `text1_0`, `text1_1`, `lang1`, `prob1`, `em1_0`, `em1_1`, `em1_2`, `em1_3`, `em1_4`, `em1_5`, `text2_0`, `text2_1`, `lang2`, `prob2`, `em2_0`, `em2_1`, `em2_2`, `em2_3`, `em2_4`, `em2_5`, `text3_0`, `text3_1`, `lang3`, `prob3`, `em3_0`, `em3_1`, `em3_2`, `em3_3`, `em3_4`, `em3_5`, `text4_0`, `text4_1`, `lang4`, `prob4`, `em4_0`, `em4_1`, `em4_2`, `em4_3`, `em4_4`, `em4_5`, `text5_0`, `text5_1`, `lang5`, `prob5`, `em5_0`, `em5_1`, `em5_2`, `em5_3`, `em5_4`, `em5_5`, `text6_0`, `text6_1`, `lang6`, `prob6`, `em6_0`, `em6_1`, `em6_2`, `em6_3`, `em6_4`, `em6_5`, `text7_0`, `text7_1`, `lang7`, `prob7`, `em7_0`, `em7_1`, `em7_2`, `em7_3`, `em7_4`, `em7_5`, `WDBVerified`) VALUES
(16440, 'Care to purchase some piratey items?', '', 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- 16440
(18046, 'I can teach the art of cooking.

Are you looking to learn?', 'I can teach the art of cooking.

Are you looking to learn?', 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- 18046
(16437, '<Bossy is busy trying to figure out how to get back downstairs.>', '', 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- 16437
(16441, 'Welcome to Booty Bay, $r.', '', 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- 16441
(17598, 'I''ve been sent here by my superiors to investigate some strange occurrences here in Booty Bay.  This goblin town withstood a tidal wave remarkably well, especially given the reputation of goblin engineering.  I''m surprised the place didn''t explode on impact.$b$bI suspect there may be magical forces at play here.  There may be more to Booty Bay than you''d expect, $c...', '', 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- 17598
(16418, 'Here''s to you!  Here''s to me!  May we never disagree.$b$bBut if we do... BLAST YOU!  Here''s to me.', '', 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 15595); -- 16418

UPDATE `npc_text` SET `WDBVerified`=15595 WHERE `ID`=5753; -- 5753
UPDATE `npc_text` SET `WDBVerified`=15595 WHERE `ID`=2641; -- 2641
UPDATE `npc_text` SET `text0_0`='Welcome, $N. I am Landro Longshot - manager of the Black Flame. Perhaps you''ve not heard of the Black Flame until now. That doesn''t surprise me; we work to keep things that way. We prefer to avoid... factional entanglements.$B$BThe Black Flame specializes in providing the finest services and entertainment money can buy, whether they happen to be hard to find items, gladiatorial combat, or lucrative games of chance.$B$BAre you here seeking something specific?', `em0_0`=1, `em0_2`=6, `em0_3`=0, `em0_5`=0, `WDBVerified`=15595 WHERE `ID`=8855; -- 8855
UPDATE `npc_text` SET `em0_0`=1, `em0_1`=0, `WDBVerified`=15595 WHERE `ID`=12495; -- 12495
UPDATE `npc_text` SET `em0_0`=6, `em0_1`=0, `WDBVerified`=15595 WHERE `ID`=12494; -- 12494
UPDATE `npc_text` SET `WDBVerified`=15595 WHERE `ID`=2135; -- 2135
UPDATE `npc_text` SET `WDBVerified`=15595 WHERE `ID`=3488; -- 3488
UPDATE `npc_text` SET `WDBVerified`=15595 WHERE `ID`=5535; -- 5535
UPDATE `npc_text` SET `WDBVerified`=15595 WHERE `ID`=3357; -- 3357
UPDATE `npc_text` SET `em0_0`=3, `em0_1`=1, `em0_3`=0, `WDBVerified`=15595 WHERE `ID`=7965; -- 7965
UPDATE `npc_text` SET `WDBVerified`=15595 WHERE `ID`=5479; -- 5479
UPDATE `npc_text` SET `WDBVerified`=15595 WHERE `ID`=5074; -- 5074
UPDATE `npc_text` SET `WDBVerified`=15595 WHERE `ID`=6164; -- 6164

DELETE FROM `gossip_menu_option` WHERE (`menu_id`=11743 AND `id`=1) OR (`menu_id`=9197 AND `id`=13) OR (`menu_id`=9197 AND `id`=14) OR (`menu_id`=9197 AND `id`=15) OR (`menu_id`=9197 AND `id`=16) OR (`menu_id`=9197 AND `id`=17) OR (`menu_id`=9197 AND `id`=18) OR (`menu_id`=9197 AND `id`=19) OR (`menu_id`=10810 AND `id`=0) OR (`menu_id`=12658 AND `id`=0) OR (`menu_id`=12658 AND `id`=1) OR (`menu_id`=12658 AND `id`=2) OR (`menu_id`=12658 AND `id`=3) OR (`menu_id`=12784 AND `id`=0) OR (`menu_id`=12784 AND `id`=1) OR (`menu_id`=12784 AND `id`=2) OR (`menu_id`=12784 AND `id`=3) OR (`menu_id`=12785 AND `id`=0) OR (`menu_id`=12785 AND `id`=1) OR (`menu_id`=12785 AND `id`=2) OR (`menu_id`=12785 AND `id`=3) OR (`menu_id`=13003 AND `id`=0) OR (`menu_id`=13003 AND `id`=1) OR (`menu_id`=13003 AND `id`=2) OR (`menu_id`=13003 AND `id`=3) OR (`menu_id`=13088 AND `id`=0) OR (`menu_id`=13088 AND `id`=1) OR (`menu_id`=13088 AND `id`=2) OR (`menu_id`=13088 AND `id`=3) OR (`menu_id`=13089 AND `id`=0) OR (`menu_id`=13089 AND `id`=1) OR (`menu_id`=13089 AND `id`=2) OR (`menu_id`=13089 AND `id`=3) OR (`menu_id`=13506 AND `id`=0) OR (`menu_id`=13506 AND `id`=1) OR (`menu_id`=13506 AND `id`=2) OR (`menu_id`=13506 AND `id`=3) OR (`menu_id`=12838 AND `id`=0) OR (`menu_id`=12838 AND `id`=1) OR (`menu_id`=2784 AND `id`=0) OR (`menu_id`=4306 AND `id`=0);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `box_coded`, `box_money`, `box_text`) VALUES
(11743, 1, 1, 'What''ve you got?', 0, 0, ''), -- Narkk
(9197, 13, 0, 'War of the Elements', 0, 0, ''), -- Landro Longshot
(9197, 14, 0, 'Twilight of the Dragons', 0, 0, ''), -- Landro Longshot
(9197, 15, 0, 'Throne of Tides', 0, 0, ''), -- Landro Longshot
(9197, 16, 0, 'Crown of Heaven', 0, 0, ''), -- Landro Longshot
(9197, 17, 0, 'Tomb of the Forgotten', 0, 0, ''), -- Landro Longshot
(9197, 18, 0, 'Timewalkers: War of the Ancients', 0, 0, ''), -- Landro Longshot
(9197, 19, 0, 'Points Redemption', 0, 0, ''), -- Landro Longshot
(10810, 0, 0, 'Mini-Mount', 1, 0, ''), -- Landro Longshot
(12658, 0, 0, 'Grim Campfire', 1, 0, ''), -- Landro Longshot
(12658, 1, 0, 'Landro''s Lil'' XT', 1, 0, ''), -- Landro Longshot
(12658, 2, 0, 'Mottled Drake', 1, 0, ''), -- Landro Longshot
(12658, 3, 0, 'What other promotions do you have?', 0, 0, ''), -- Landro Longshot
(12784, 0, 0, 'Landro''s Lichling', 1, 0, ''), -- Landro Longshot
(12784, 1, 0, 'War Party Hitching Post', 1, 0, ''), -- Landro Longshot
(12784, 2, 0, 'Savage Raptor Mount', 1, 0, ''), -- Landro Longshot
(12784, 3, 0, 'What other promotions do you have?', 0, 0, ''), -- Landro Longshot
(12785, 0, 0, 'Nightsaber Cub', 1, 0, ''), -- Landro Longshot
(12785, 1, 0, 'Fool''s Gold', 1, 0, ''), -- Landro Longshot
(12785, 2, 0, 'Amani Dragonhawk', 1, 0, ''), -- Landro Longshot
(12785, 3, 0, 'What other promotions do you have?', 0, 0, ''), -- Landro Longshot
(13003, 0, 0, 'Purple Puffer Pet', 1, 0, ''), -- Landro Longshot
(13003, 1, 0, 'Throwing Starfish', 1, 0, ''), -- Landro Longshot
(13003, 2, 0, 'Swift Shorestrider', 1, 0, ''), -- Landro Longshot
(13003, 3, 0, 'What other promotions do you have?', 0, 0, ''), -- Landro Longshot
(13088, 0, 0, 'Gregarious Grell Pet', 1, 0, ''), -- Landro Longshot
(13088, 1, 0, 'Ogre Mage Costume', 1, 0, ''), -- Landro Longshot
(13088, 2, 0, 'Corrupted Hippogryph', 1, 0, ''), -- Landro Longshot
(13088, 3, 0, 'What other promotions do you have?', 0, 0, ''), -- Landro Longshot
(13089, 0, 0, 'Sand Scarab Pet', 1, 0, ''), -- Landro Longshot
(13089, 1, 0, 'Spurious Sarcophagus', 1, 0, ''), -- Landro Longshot
(13089, 2, 0, 'White Riding Camel', 1, 0, ''), -- Landro Longshot
(13089, 3, 0, 'What other promotions do you have?', 0, 0, ''), -- Landro Longshot
(13506, 0, 0, 'Eye of the Legion', 1, 0, ''), -- Landro Longshot
(13506, 1, 0, 'Demon Hunter''s Aspect', 1, 0, ''), -- Landro Longshot
(13506, 2, 0, 'Feldrake Mount', 1, 0, ''), -- Landro Longshot
(13506, 3, 0, 'What other promotions do you have?', 0, 0, ''), -- Landro Longshot
(12838, 0, 3, 'Train me.', 0, 0, ''), -- Mrs. Gant
(12838, 1, 1, 'Let me browse your goods.', 0, 0, ''), -- Mrs. Gant
(2784, 0, 3, 'Train me.', 0, 0, ''), -- Brikk Keencraft
(4306, 0, 2, 'Sure! Let''s go for a ride.', 0, 0, ''); -- Gyll

UPDATE `gossip_menu_option` SET `option_text`='Worldbreaker' WHERE `menu_id`=9197 AND `id`=12; -- Landro Longshot
UPDATE `gossip_menu_option` SET `box_coded`=1 WHERE `menu_id`=9194 AND `id`=0; -- Landro Longshot
UPDATE `gossip_menu_option` SET `box_coded`=1 WHERE `menu_id`=9194 AND `id`=1; -- Landro Longshot
UPDATE `gossip_menu_option` SET `box_coded`=1 WHERE `menu_id`=9194 AND `id`=2; -- Landro Longshot
UPDATE `gossip_menu_option` SET `box_coded`=1 WHERE `menu_id`=9195 AND `id`=0; -- Landro Longshot
UPDATE `gossip_menu_option` SET `box_coded`=1 WHERE `menu_id`=9195 AND `id`=1; -- Landro Longshot
UPDATE `gossip_menu_option` SET `box_coded`=1 WHERE `menu_id`=9195 AND `id`=2; -- Landro Longshot
UPDATE `gossip_menu_option` SET `box_coded`=1 WHERE `menu_id`=9196 AND `id`=0; -- Landro Longshot
UPDATE `gossip_menu_option` SET `box_coded`=1 WHERE `menu_id`=9196 AND `id`=1; -- Landro Longshot
UPDATE `gossip_menu_option` SET `box_coded`=1 WHERE `menu_id`=9196 AND `id`=2; -- Landro Longshot
UPDATE `gossip_menu_option` SET `box_coded`=1 WHERE `menu_id`=9191 AND `id`=0; -- Landro Longshot
UPDATE `gossip_menu_option` SET `box_coded`=1 WHERE `menu_id`=9191 AND `id`=1; -- Landro Longshot
UPDATE `gossip_menu_option` SET `box_coded`=1 WHERE `menu_id`=9191 AND `id`=2; -- Landro Longshot
UPDATE `gossip_menu_option` SET `box_coded`=1 WHERE `menu_id`=9629 AND `id`=0; -- Landro Longshot
UPDATE `gossip_menu_option` SET `box_coded`=1 WHERE `menu_id`=9629 AND `id`=1; -- Landro Longshot
UPDATE `gossip_menu_option` SET `box_coded`=1 WHERE `menu_id`=9629 AND `id`=2; -- Landro Longshot
UPDATE `gossip_menu_option` SET `box_coded`=1 WHERE `menu_id`=9682 AND `id`=0; -- Landro Longshot
UPDATE `gossip_menu_option` SET `box_coded`=1 WHERE `menu_id`=9682 AND `id`=1; -- Landro Longshot
UPDATE `gossip_menu_option` SET `box_coded`=1 WHERE `menu_id`=9682 AND `id`=2; -- Landro Longshot
UPDATE `gossip_menu_option` SET `box_coded`=1 WHERE `menu_id`=10330 AND `id`=0; -- Landro Longshot
UPDATE `gossip_menu_option` SET `box_coded`=1 WHERE `menu_id`=10330 AND `id`=1; -- Landro Longshot
UPDATE `gossip_menu_option` SET `box_coded`=1 WHERE `menu_id`=10330 AND `id`=2; -- Landro Longshot
UPDATE `gossip_menu_option` SET `box_coded`=1 WHERE `menu_id`=10533 AND `id`=0; -- Landro Longshot
UPDATE `gossip_menu_option` SET `box_coded`=1 WHERE `menu_id`=10533 AND `id`=1; -- Landro Longshot
UPDATE `gossip_menu_option` SET `box_coded`=1 WHERE `menu_id`=10533 AND `id`=2; -- Landro Longshot
UPDATE `gossip_menu_option` SET `box_coded`=1 WHERE `menu_id`=10810 AND `id`=2; -- Landro Longshot
UPDATE `gossip_menu_option` SET `box_coded`=1 WHERE `menu_id`=10810 AND `id`=3; -- Landro Longshot
UPDATE `gossip_menu_option` SET `box_coded`=1 WHERE `menu_id`=11342 AND `id`=0; -- Landro Longshot
UPDATE `gossip_menu_option` SET `box_coded`=1 WHERE `menu_id`=11342 AND `id`=1; -- Landro Longshot
UPDATE `gossip_menu_option` SET `box_coded`=1 WHERE `menu_id`=11342 AND `id`=2; -- Landro Longshot
UPDATE `gossip_menu_option` SET `box_coded`=1 WHERE `menu_id`=11343 AND `id`=0; -- Landro Longshot
UPDATE `gossip_menu_option` SET `box_coded`=1 WHERE `menu_id`=11343 AND `id`=1; -- Landro Longshot
UPDATE `gossip_menu_option` SET `box_coded`=1 WHERE `menu_id`=11343 AND `id`=2; -- Landro Longshot
UPDATE `gossip_menu_option` SET `box_coded`=1 WHERE `menu_id`=9193 AND `id`=0; -- Landro Longshot
UPDATE `gossip_menu_option` SET `box_coded`=1 WHERE `menu_id`=9193 AND `id`=1; -- Landro Longshot
UPDATE `gossip_menu_option` SET `box_coded`=1 WHERE `menu_id`=9193 AND `id`=2; -- Landro Longshot
UPDATE `gossip_menu_option` SET `box_coded`=1 WHERE `menu_id`=9193 AND `id`=3; -- Landro Longshot
UPDATE `gossip_menu_option` SET `box_coded`=1 WHERE `menu_id`=9193 AND `id`=4; -- Landro Longshot
UPDATE `gossip_menu_option` SET `box_coded`=1 WHERE `menu_id`=9193 AND `id`=5; -- Landro Longshot
UPDATE `gossip_menu_option` SET `box_coded`=1 WHERE `menu_id`=9193 AND `id`=6; -- Landro Longshot
UPDATE `gossip_menu_option` SET `box_coded`=1 WHERE `menu_id`=9193 AND `id`=7; -- Landro Longshot
UPDATE `gossip_menu_option` SET `box_coded`=1 WHERE `menu_id`=9193 AND `id`=8; -- Landro Longshot
UPDATE `gossip_menu_option` SET `box_coded`=1 WHERE `menu_id`=9193 AND `id`=9; -- Landro Longshot

DELETE FROM `creature_equip_template` WHERE `entry` IN (45681, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 1489, 43504, 1907, 1907, 1907, 1907, 1907, 1907, 1907, 1907, 1561, 1907, 1907, 1493, 1907, 1907, 1907, 1907, 1562, 1561, 1562, 43376, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 16399, 1561, 1562, 1562, 1561, 43364, 1562, 43454, 1561, 4624, 1561, 1561, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 43596, 1561, 4624, 4624, 4624, 4624, 4624, 25098, 25089, 25093, 25082, 25078, 9559, 4624, 4631, 2594, 2502, 48808, 4624, 28180, 4624, 4624, 4624, 4624, 28180, 28180, 28180, 28180, 28180, 28180, 2664, 2663, 2839, 1561, 1562, 2845, 4624, 4624, 2847, 2836, 28180, 4624, 28180, 28180, 2840, 4624, 4624, 4624, 2499, 4624, 28180, 28180, 28180, 25098, 25093, 25078, 25082, 25089, 28180, 4624, 4624, 28180, 4624, 4624, 28180, 4624, 2490, 21045, 21045, 17249, 4624, 7406, 28180, 54232, 4624, 2838, 4624, 4624, 2486, 4624, 2622, 4624, 4624, 2842, 4624, 4624, 4624, 4624, 4624, 4624, 4624, 4624, 4624, 4624, 2834, 4624, 4624, 2626, 2496, 4624, 2858, 4624, 4624, 4624, 1653, 1653, 2848, 2837, 4624, 49636, 4624, 908, 2859, 4624, 4624, 49635, 2843, 4624, 4624, 4624, 2491, 2488, 4624, 4624, 1493, 1411, 4624, 25078, 1653, 1565, 1565, 1565, 1653, 1653, 1565, 1565, 1653, 1565, 1565, 1653, 1653, 1565, 1565, 1565, 43605, 1565, 1653, 1653, 1565, 4506, 44182, 4506, 4506, 4506, 4505, 43659, 4505, 43636, 4505, 43636, 4505, 43636, 43636, 43636, 1653, 2548, 2549, 43636, 4506, 4505, 4506, 43636, 4506, 4506, 43636, 43636, 4505, 43636, 43661, 2545, 4506, 4505, 4506, 43636, 4506, 43636, 4505, 4506, 43636, 2547, 4505, 43660, 43636, 43636, 4505, 4505, 2546, 4505);
INSERT INTO `creature_equip_template` (`entry`, `itemEntry1`, `itemEntry2`, `itemEntry3`) VALUES
(45681, 61298, 0, 0), -- Garginox
(43596, 31824, 0, 0), -- Venture Co. Oil Worker
(1489, 2023, 0, 5870), -- Zanzil Hunter
(43504, 12742, 0, 0), -- Yancey Grillsen
(1907, 5745, 0, 0), -- Naga Explorer
(1561, 2184, 2184, 0), -- Bloodsail Raider
(1493, 5491, 0, 0), -- Mok'rash
(1562, 1907, 0, 0), -- Bloodsail Mage
(43376, 1911, 0, 0), -- Freewheelin' Juntz Fitztittle
(16399, 2184, 0, 0), -- Bloodsail Traitor
(43364, 12791, 0, 0), -- Bloodsail Hooch-Hound
(43454, 1897, 0, 0), -- "Good-Boy" Bruce
(4624, 3361, 0, 2552), -- Booty Bay Bruiser
(25098, 2809, 0, 0), -- Bosun Thunderhorn
(25089, 2827, 13406, 0), -- Galley Chief Steelbelly
(25093, 1897, 0, 0), -- First Mate Masker
(25082, 1902, 0, 0), -- Engineer Torquespindle
(25078, 3364, 0, 0), -- Captain Krick Wrenchnozzle
(9559, 2714, 0, 0), -- Grizzlowe
(4631, 2715, 0, 0), -- Wharfmaster Lozgil
(2594, 2202, 0, 0), -- Sprogger
(2502, 3368, 0, 0), -- "Shaky" Phillipe
(48808, 54824, 0, 0), -- Corporal Jeyne
(28180, 1902, 0, 0), -- [ph] Goblin Construction Crew
(2664, 2827, 2827, 0), -- Kelsey Yance
(2663, 1900, 0, 0), -- Narkk
(2839, 0, 0, 5262), -- Haren Kanmae
(2845, 1903, 0, 0), -- Fargon Mortalak
(2847, 1903, 0, 0), -- Jansen Underwood
(2836, 1903, 0, 0), -- Brikk Keencraft
(2840, 2182, 0, 0), -- Kizz Bluntstrike
(2499, 1911, 0, 0), -- Markel Smythe
(2490, 5278, 0, 0), -- First Mate Crazz
(21045, 3361, 0, 2552), -- Hired Bodyguard
(17249, 68626, 0, 0), -- Landro Longshot
(7406, 1911, 0, 0), -- Oglethorpe Obnoticus
(54232, 2827, 19485, 0), -- Mrs. Gant
(2838, 2884, 0, 0), -- Crazk Sparks
(2486, 1897, 0, 0), -- Fin Fizracket
(2622, 2184, 3698, 0), -- Sly Garrett
(2842, 1117, 0, 0), -- Wigcik
(2834, 6225, 0, 0), -- Myizz Luckycatch
(2626, 1117, 0, 0), -- Old Man Heming
(2496, 3364, 5284, 0), -- Baron Revilgaz
(2858, 3433, 0, 0), -- Gringer
-- (4624, 1906, 0, 2552), -- Booty Bay Bruiser
(1653, 1907, 0, 0), -- Bloodsail Elder Magus
(2848, 2200, 0, 0), -- Glyx Brewright
(2837, 2198, 0, 0), -- Jaxin Chong
(49636, 6228, 0, 0), -- Arcanist Arman
(908, 6233, 0, 0), -- Flora Silverwind
(2859, 5491, 0, 0), -- Gyll
(49635, 12751, 0, 0), -- War-Mage Erallier
(2843, 1899, 0, 0), -- Jutak
(2491, 0, 3757, 0), -- Whiskey Slim
(2488, 1897, 0, 0), -- Deeg
(1411, 3364, 0, 0), -- Ian Strom
(1565, 2184, 0, 0), -- Bloodsail Sea Dog
(43605, 54823, 0, 0), -- Bloodsail Oarsman
(4506, 2184, 0, 0), -- Bloodsail Swabby
(44182, 1897, 1897, 0), -- Gurlgrl
(4505, 2184, 0, 0), -- Bloodsail Deckhand
(43659, 54824, 0, 0), -- Long John Copper
(43636, 1897, 0, 0), -- Bloodsail Corsair
(2548, 2179, 0, 2552), -- Captain Keelhaul
(2549, 5288, 0, 0), -- Garr Salthoof
(43661, 54824, 0, 0), -- Wailing Mary Smitts
(2545, 2711, 0, 0), -- "Pretty Boy" Duncan
(2547, 2180, 1984, 0), -- Ironpatch
(43660, 54824, 0, 0), -- Enormous Shawn Stooker
(2546, 2179, 1897, 25277); -- Fleet Master Firallon

DELETE FROM `gameobject_template` WHERE `entry` IN (204001, 204000, 204044, 208350, 208349, 208358, 204821, 204822, 204801, 204802, 204803, 204087);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `data24`, `data25`, `data26`, `data27`, `data28`, `data29`, `data30`, `data31`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `unkInt32`, `WDBVerified`) VALUES
(204001, 5, 9665, 'Destroyed Grom''gol Crate', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- -Unknown-
(204000, 3, 5531, 'Grom''gol Rations Crate', '', 'Collecting', '', 93, 30069, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 58083, 0, 0, 0, 0, 0, 0, 15595), -- -Unknown-
(204044, 5, 293, 'Troll Skull Pile', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- -Unknown-
(208350, 31, 8197, 'Doodad_InstanceNewPortal_Purple_Skull01', '', '', '', 859, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- -Unknown-
(208349, 31, 8196, 'Doodad_InstanceNewPortal_Purple01', '', '', '', 859, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- -Unknown-
(208358, 23, 5491, 'Meeting Stone', '', '', '', 15, 255, 1977, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- -Unknown-
(204821, 8, 216, 'Cauldron', '', '', '', 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- -Unknown-
(204822, 8, 216, 'Cauldron', '', '', '', 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- -Unknown-
(204801, 5, 309, 'Booty Bay', '', '', '', 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- -Unknown-
(204802, 5, 309, 'Bambala', '', '', '', 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- -Unknown-
(204803, 5, 309, 'Duskwood', '', '', '', 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- -Unknown-
(204087, 3, 5743, 'Mosh''Ogg Bounty', '', 'Stealing', '', 93, 30083, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.5, 58205, 0, 0, 0, 0, 0, 0, 15595); -- -Unknown-

UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=94183; -- Bonfire
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=54; -- The Emperor's Tomb
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=94184; -- Bonfire
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=157636; -- Campfire
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=1957; -- Campfire
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=52; -- Fall of Gurubashi
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=1958; -- Campfire
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=1962; -- Campfire
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176549; -- Brazier
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176550; -- Brazier
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=1964; -- Campfire
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176551; -- Brazier
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176552; -- Brazier
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176553; -- Brazier
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176555; -- Brazier
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176556; -- Brazier
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176554; -- Brazier
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=94185; -- Bonfire
UPDATE `gameobject_template` SET `name`='Bloodscalp Lore Tablet', `data1`=31220, `questItem1`=60295, `WDBVerified`=15595 WHERE `entry`=57; -- Moon Over the Vale
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=179700; -- Cauldron
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=180386; -- Gong
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=112879; -- Bonefire
UPDATE `gameobject_template` SET `size`=0.63, `WDBVerified`=15595 WHERE `entry`=111839; -- Bonfire
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=20691; -- Cozzle's Footlocker
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=181636; -- Altar of Naias
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=58; -- Gri'lek the Wanderer
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=142078; -- Forge
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=142077; -- Anvil
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=142079; -- Campfire
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=179426; -- Gri'lek the Wanderer
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=2576; -- Altar of the Tides
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=3206; -- Booty Bay
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=3205; -- Arena
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=3207; -- Duskwood
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=92254; -- Bonfire
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=1970; -- Campfire
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=1971; -- Campfire
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=2891; -- Balia'mah Trophy Skulls
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=1972; -- Campfire
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=164728; -- Campfire
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=2893; -- Zul'Mamwe Trophy Skulls
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=94187; -- Bonfire
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=1975; -- Campfire
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=1973; -- Campfire

SET @OGUID := 43232;

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+404;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0, 1732, 0, 1, 1, -11606.3, 956.458, 11.2147, 4.206246, 0, 0, 0, 1, 120, 255, 1), -- Tin Vein (Area: 0)
(@OGUID+1, 1623, 0, 1, 1, -11631.4, 811.887, 22.343, 0.3141584, 0, 0, 0, 1, 120, 255, 1), -- Wild Steelbloom (Area: 0)
(@OGUID+2, 1623, 0, 1, 1, -11520, 801.528, 57.0048, 0.3141584, 0, 0, 0, 1, 120, 255, 1), -- Wild Steelbloom (Area: 0)
(@OGUID+3, 94183, 0, 1, 1, -11557.2, 592.2073, 50.29065, 1.980947, 0, 0, 0, 1, 120, 255, 1), -- Bonfire (Area: Ruins of Zul'Kunda)
(@OGUID+4, 54, 0, 1, 1, -11548.52, 644.6893, 59.97883, 2.258379, 0, 0, 0, 1, 120, 255, 1), -- The Emperor's Tomb (Area: Ruins of Zul'Kunda)
(@OGUID+5, 1622, 0, 1, 1, -11590.1, 627.196, 50.58, 0, 0, 0, 0, 1, 120, 255, 1), -- Bruiseweed (Area: Ruins of Zul'Kunda)
(@OGUID+6, 94184, 0, 1, 1, -11579.62, 686.2498, 58.99099, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Bonfire (Area: Ruins of Zul'Kunda)
(@OGUID+7, 1622, 0, 1, 1, -11549.4, 670.776, 60.9527, 0, 0, 0, 0, 1, 120, 255, 1), -- Bruiseweed (Area: Ruins of Zul'Kunda)
-- (@OGUID+8, 181688, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 120, 255, 1), -- 0 (Area: Ruins of Zul'Kunda) - !!! transport !!!
-- (@OGUID+8, 175080, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 120, 255, 1), -- 0 (Area: Ruins of Zul'Kunda) - !!! transport !!!
(@OGUID+8, 1732, 0, 1, 1, -11493, 366.53, 60.0778, 4.206246, 0, 0, 0, 1, 120, 255, 1), -- Tin Vein (Area: 0)
(@OGUID+9, 1624, 0, 1, 1, -11506.9, 307.043, 41.331, 5.113817, 0, 0, 0, 1, 120, 255, 1), -- Kingsblood (Area: 0)
(@OGUID+10, 2041, 0, 1, 1, -11440.7, 203.354, 10.4675, 2.91469, 0, 0, 0, 1, 120, 255, 1), -- Liferoot (Area: 0)
(@OGUID+11, 2041, 0, 1, 1, -11459.6, 121.677, 10.3453, 2.91469, 0, 0, 0, 1, 120, 255, 1), -- Liferoot (Area: 0)
(@OGUID+12, 1732, 0, 1, 1, -11455.5, 103.191, 40.348, 4.206246, 0, 0, 0, 1, 120, 255, 1), -- Tin Vein (Area: 0)
(@OGUID+13, 1624, 0, 1, 1, -11615.2, 142.444, 18.8004, 5.113817, 0, 0, 0, 1, 120, 255, 1), -- Kingsblood (Area: 0)
-- (@OGUID+14, 176310, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 120, 255, 1), -- 0 (Area: 0) - !!! transport !!!
(@OGUID+14, 2041, 0, 1, 1, -11353.1, 286.899, 14.3997, 2.91469, 0, 0, 0, 1, 120, 255, 1), -- Liferoot (Area: 0)
-- (@OGUID+15, 181689, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 120, 255, 1), -- 0 (Area: 0) - !!! transport !!!
-- (@OGUID+15, 190536, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 120, 255, 1), -- 0 (Area: 0) - !!! transport !!!
(@OGUID+15, 180684, 0, 1, 1, -11560.6, -90.7691, 10.06987, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Greater Sagefish School (Area: 0)
(@OGUID+16, 180684, 0, 1, 1, -11593.4, -30.03819, 10.06987, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Greater Sagefish School (Area: 0)
(@OGUID+17, 1732, 0, 1, 1, -11526.2, -77.7847, 35.4317, 4.206246, 0, 0, 0, 1, 120, 255, 1), -- Tin Vein (Area: 0)
(@OGUID+18, 2041, 0, 1, 1, -11584, -122.288, 10.1815, 2.91469, 0, 0, 0, 1, 120, 255, 1), -- Liferoot (Area: 0)
(@OGUID+19, 1959, 0, 1, 1, -11312.09, -204.2274, 75.15048, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Campfire (Area: Rebel Camp)
-- (@OGUID+20, 20808, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 120, 255, 1), -- 0 (Area: Rebel Camp) - !!! transport !!!
(@OGUID+20, 1732, 0, 1, 1, -11479.5, -442.344, 60.329, 4.206246, 0, 0, 0, 1, 120, 255, 1), -- Tin Vein (Area: 0)
(@OGUID+21, 1732, 0, 1, 1, -11540.4, -441.9097, 39.31234, 4.206246, 0, 0, 0, 1, 120, 255, 1), -- Tin Vein (Area: 0)
(@OGUID+22, 204826, 0, 1, 1, -11499.63, -608.8715, 41.08212, 6.0912, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+23, 204827, 0, 1, 1, -11497.73, -611.8542, 36.31259, 2.705255, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+24, 204827, 0, 1, 1, -11485.94, -615.6823, 36.15273, 2.775069, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+25, 204827, 0, 1, 1, -11575.53, -577.625, 33.67944, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+26, 22567, 0, 1, 1, -11576.95, -574.4638, 33.88897, 1.858774, 0, 0, 0.01308961, 0.9999143, 120, 255, 1), -- Cozy Fire (Area: 0)
(@OGUID+27, 204827, 0, 1, 1, -11576.1, -570.003, 28.9063, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+28, 22564, 0, 1, 1, -11577.47, -575.2552, 33.88897, 5.951575, 0, 0, 0.01308961, 0.9999143, 120, 255, 1), -- Cozy Fire (Area: 0)
(@OGUID+29, 22565, 0, 1, 1, -11576.94, -574.6798, 28.97212, 1.858774, 0, 0, 0.01308961, 0.9999143, 120, 255, 1), -- Cozy Fire (Area: 0)
(@OGUID+30, 22566, 0, 1, 1, -11577.46, -575.4712, 28.97212, 5.951575, 0, 0, 0.01308961, 0.9999143, 120, 255, 1), -- Cozy Fire (Area: 0)
(@OGUID+31, 22563, 0, 1, 1, -11578.09, -575.1292, 28.97212, 3.150327, 0, 0, 0.01308961, 0.9999143, 120, 255, 1), -- Cozy Fire (Area: 0)
(@OGUID+32, 1623, 0, 1, 1, -11475.6, -638.267, 46.6014, 0.3141584, 0, 0, 0, 1, 120, 255, 1), -- Wild Steelbloom (Area: 0)
(@OGUID+33, 263, 0, 1, 1, -11574.41, -593.4149, 27.93196, 0.2443436, 0, 0, 0, 1, 120, 255, 1), -- Kurzen Supplies (Area: 0)
(@OGUID+34, 204826, 0, 1, 1, -11574.9, -594.094, 29.6858, 1.762782, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+35, 204826, 0, 1, 1, -11519.6, -645.068, 31.0476, 6.0912, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+36, 1622, 0, 1, 1, -11515.3, -647.003, 30.1314, 0, 0, 0, 0, 1, 120, 255, 1), -- Bruiseweed (Area: 0)
(@OGUID+37, 3797, 0, 1, 1, -11517.72, -651.2794, 30.98744, 1.308995, 0, 0, -0.7880107, 0.6156615, 120, 255, 1), -- Cozy Fire (Area: 0)
(@OGUID+38, 204826, 0, 1, 1, -11579.5, -613.127, 28.3615, 6.0912, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+39, 3798, 0, 1, 1, -11518.01, -652.1272, 30.98744, 0.01745246, 0, 0, -0.7880107, 0.6156615, 120, 255, 1), -- Cozy Fire (Area: 0)
(@OGUID+40, 204827, 0, 1, 1, -11529.01, -652.8837, 31.05507, 1.343901, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+41, 264, 0, 1, 1, -11582.34, -618.5, 28.36234, 3.543024, 0, 0, 0, 1, 120, 255, 1), -- Kurzen Supplies (Area: 0)
(@OGUID+42, 1961, 0, 1, 1, -11592.33, -620.1927, 28.35931, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Campfire (Area: 0)
(@OGUID+43, 204826, 0, 1, 1, -11528.65, -706.25, 35.56372, 3.926996, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Kurzen's Compound)
(@OGUID+44, 204826, 0, 1, 1, -11561.8, -690.635, 32.2842, 6.0912, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Kurzen's Compound)
(@OGUID+45, 1732, 0, 1, 1, -11465.6, -719.052, 73.2195, 4.206246, 0, 0, 0, 1, 120, 255, 1), -- Tin Vein (Area: Kurzen's Compound)
(@OGUID+46, 204827, 0, 1, 1, -11600.7, -620.142, 28.8689, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Kurzen's Compound)
(@OGUID+47, 204826, 0, 1, 1, -11592.9, -623.729, 28.8703, 6.0912, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Kurzen's Compound)
(@OGUID+48, 204827, 0, 1, 1, -11589.8, -707.163, 30.973, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Kurzen's Compound)
(@OGUID+49, 1732, 0, 1, 1, -11441.95, -725.6597, 27.7425, 0, 0, 0, 0, 1, 120, 255, 1), -- Tin Vein (Area: Kurzen's Compound)
(@OGUID+50, 1732, 0, 1, 1, -11483.32, -836.5347, 35.10456, 0, 0, 0, 0, 1, 120, 255, 1), -- Tin Vein (Area: The Stockpile)
(@OGUID+51, 157969, 0, 1, 1, -11406.22, -796.0367, 14.952, 0.6195911, 0, 0, 0.9304177, 0.366501, 120, 255, 1), -- Cauldron (Area: The Stockpile)
-- (@OGUID+52, 176231, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 120, 255, 1), -- 0 (Area: The Stockpile) - !!! transport !!!
(@OGUID+52, 1732, 0, 1, 1, -11467.02, -849.1927, 16.11817, 0, 0, 0, 0, 1, 120, 255, 1), -- Tin Vein (Area: The Stockpile)
(@OGUID+53, 207486, 0, 1, 1, -11479.35, -875.6893, 36.26705, 0.9424766, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: The Stockpile)
(@OGUID+54, 1732, 0, 1, 1, -11551.73, -904.434, 25.35081, 0, 0, 0, 0, 1, 120, 255, 1), -- Tin Vein (Area: The Stockpile)
-- (@OGUID+55, 164871, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 120, 255, 1), -- 0 (Area: The Stockpile) - !!! transport !!!
(@OGUID+55, 1732, 0, 1, 1, -11467.32, -945.941, 25.408, 0, 0, 0, 0, 1, 120, 255, 1), -- Tin Vein (Area: The Stockpile)
(@OGUID+56, 1732, 0, 1, 1, -11360.48, -907.2986, 23.944, 0, 0, 0, 0, 1, 120, 255, 1), -- Tin Vein (Area: The Stockpile)
(@OGUID+57, 157636, 0, 1, 1, -11331.55, -962.0104, 30.04337, 2.388791, 0, 0, 0.9304177, 0.366501, 120, 255, 1), -- Campfire (Area: The Stockpile)
(@OGUID+58, 204827, 0, 1, 1, -11643.18, -669.2292, 30.31038, 2.042035, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Kurzen's Compound)
(@OGUID+59, 204826, 0, 1, 1, -11641.43, -629.6719, 31.45697, 6.0912, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Kurzen's Compound)
(@OGUID+60, 204826, 0, 1, 1, -11655.44, -664.4774, 30.3133, 5.113817, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Kurzen's Compound)
(@OGUID+61, 3797, 0, 1, 1, -11656.29, -669.6158, 30.24923, 5.122542, 0, 0, 0.8410391, 0.5409744, 120, 255, 1), -- Cozy Fire (Area: Kurzen's Compound)
(@OGUID+62, 3798, 0, 1, 1, -11656.6, -668.7745, 30.24923, 3.831001, 0, 0, 0.8410391, 0.5409744, 120, 255, 1), -- Cozy Fire (Area: Kurzen's Compound)
(@OGUID+63, 204827, 0, 1, 1, -11663.32, -630.8507, 30.04121, 6.178466, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Kurzen's Compound)
(@OGUID+64, 204826, 0, 1, 1, -11630.5, -571.063, 28.3127, 5.253442, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Kurzen's Compound)
(@OGUID+65, 1623, 0, 1, 1, -11555.1, -385.611, 43.0993, 0.3141584, 0, 0, 0, 1, 120, 255, 1), -- Wild Steelbloom (Area: 0)
(@OGUID+66, 180684, 0, 1, 1, -11644, -238.7587, 10.06987, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Greater Sagefish School (Area: 0)
(@OGUID+67, 2041, 0, 1, 1, -11625.6, -180.969, 10.3828, 2.91469, 0, 0, 0, 1, 120, 255, 1), -- Liferoot (Area: 0)
(@OGUID+68, 1960, 0, 1, 1, -11640.46, -66.71528, 16.23857, 6.178466, 0, 0, 0, 1, 120, 255, 1), -- Campfire (Area: 0)
(@OGUID+69, 2041, 0, 1, 1, -11604.6, 3.5191, 10.1153, 2.91469, 0, 0, 0, 1, 120, 255, 1), -- Liferoot (Area: 0)
(@OGUID+70, 1624, 0, 1, 1, -11616.8, 33.4306, 16.317, 5.113817, 0, 0, 0, 1, 120, 255, 1), -- Kingsblood (Area: 0)
(@OGUID+71, 180682, 0, 1, 1, -11629.2, 1107.7, 0, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Oily Blackmouth School (Area: 0)
(@OGUID+72, 1957, 0, 1, 1, -11683.2, 949.1199, 3.686278, 3.141669, 0, 0, 0, 1, 120, 255, 1), -- Campfire (Area: The Savage Coast)
(@OGUID+73, 1622, 0, 1, 1, -11655.8, 945.639, 4.47222, 0, 0, 0, 0, 1, 120, 255, 1), -- Bruiseweed (Area: The Savage Coast)
(@OGUID+74, 1622, 0, 1, 1, -11694.8, 925.906, 3.73835, 0, 0, 0, 0, 1, 120, 255, 1), -- Bruiseweed (Area: Zuuldaia Ruins)
(@OGUID+75, 52, 0, 1, 1, -11680.04, 756.4688, 50.63323, 4.016832, 0, 0, 0, 1, 120, 255, 1), -- Fall of Gurubashi (Area: Zuuldaia Ruins)
(@OGUID+76, 1622, 0, 1, 1, -11656.1, 686.285, 46.4307, 0, 0, 0, 0, 1, 120, 255, 1), -- Bruiseweed (Area: Ruins of Zul'Kunda)
(@OGUID+77, 1958, 0, 1, 1, -11688.75, 641.6239, 49.08404, 3.976042, 0, 0, 0, 1, 120, 255, 1), -- Campfire (Area: Ruins of Zul'Kunda)
(@OGUID+78, 1622, 0, 1, 1, -11715.3, 669.823, 50.7439, 0, 0, 0, 0, 1, 120, 255, 1), -- Bruiseweed (Area: Ruins of Zul'Kunda)
(@OGUID+79, 1622, 0, 1, 1, -11678.4, 534.795, 50.7617, 0, 0, 0, 0, 1, 120, 255, 1), -- Bruiseweed (Area: Ruins of Zul'Kunda)
(@OGUID+80, 1622, 0, 1, 1, -11715.3, 557.536, 50.214, 0, 0, 0, 0, 1, 120, 255, 1), -- Bruiseweed (Area: Ruins of Zul'Kunda)
(@OGUID+81, 1624, 0, 1, 1, -11717.3, 413.047, 48.0807, 5.113817, 0, 0, 0, 1, 120, 255, 1), -- Kingsblood (Area: Ruins of Zul'Kunda)
(@OGUID+82, 1624, 0, 1, 1, -11645.1, 108.438, 18.3257, 5.113817, 0, 0, 0, 1, 120, 255, 1), -- Kingsblood (Area: 0)
(@OGUID+83, 1624, 0, 1, 1, -11659.6, -365.205, 15.1741, 5.113817, 0, 0, 0, 1, 120, 255, 1), -- Kingsblood (Area: 0)
(@OGUID+84, 204827, 0, 1, 1, -11682.1, -620.707, 31.5369, 1.692969, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Kurzen's Compound)
(@OGUID+85, 1732, 0, 1, 1, -11686.2, -697.769, 48.7798, 4.206246, 0, 0, 0, 1, 120, 255, 1), -- Tin Vein (Area: Kurzen's Compound)
(@OGUID+86, 1623, 0, 1, 1, -11726.5, -643.342, 49.295, 0.3141584, 0, 0, 0, 1, 120, 255, 1), -- Wild Steelbloom (Area: Kurzen's Compound)
(@OGUID+87, 180684, 0, 1, 1, -11704.2, -337.9462, 10.06987, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Greater Sagefish School (Area: 0)
(@OGUID+88, 1732, 0, 1, 1, -11689, 311.585, 42.0069, 4.206246, 0, 0, 0, 1, 120, 255, 1), -- Tin Vein (Area: 0)
(@OGUID+89, 1622, 0, 1, 1, -11755.6, 951.668, 5.42725, 0, 0, 0, 0, 1, 120, 255, 1), -- Bruiseweed (Area: Zuuldaia Ruins)
(@OGUID+90, 1732, 0, 1, 1, -11758.4, 579.628, 60.0704, 4.206246, 0, 0, 0, 1, 120, 255, 1), -- Tin Vein (Area: Ruins of Zul'Kunda)
(@OGUID+91, 1732, 0, 1, 1, -11723.5, 168.95, 27.132, 4.206246, 0, 0, 0, 1, 120, 255, 1), -- Tin Vein (Area: 0)
(@OGUID+92, 1624, 0, 1, 1, -11708.9, 206.707, 40.4489, 5.113817, 0, 0, 0, 1, 120, 255, 1), -- Kingsblood (Area: 0)
(@OGUID+93, 1732, 0, 1, 1, -11583.4, -342.566, 37.88015, 4.206246, 0, 0, 0, 1, 120, 255, 1), -- Tin Vein (Area: 0)
(@OGUID+94, 204827, 0, 1, 1, -11576.1, -570.003, 28.9063, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+95, 204826, 0, 1, 1, -11574.9, -594.094, 29.6858, 1.762782, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+96, 1732, 0, 1, 1, -11550.4, -518.727, 48.172, 4.206246, 0, 0, 0, 1, 120, 255, 1), -- Tin Vein (Area: 0)
(@OGUID+97, 204047, 0, 1, 1, -5520.566, 693.2934, 378.2548, 1.989672, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Kurzen's Compound)
(@OGUID+98, 204826, 0, 1, 1, -11592.9, -623.729, 28.8703, 6.0912, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Kurzen's Compound)
(@OGUID+99, 1732, 0, 1, 1, -11782.8, 512.319, 59.3202, 4.206246, 0, 0, 0, 1, 120, 255, 1), -- Tin Vein (Area: 0)
(@OGUID+100, 180682, 0, 1, 1, -11787.1, 972.4114, 0, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Oily Blackmouth School (Area: Zuuldaia Ruins)
(@OGUID+101, 180682, 0, 1, 1, -11854.1, 1204.46, 0, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Oily Blackmouth School (Area: Yojamba Isle)
(@OGUID+102, 1732, 0, 1, 1, -11842.4, 757.37, 23.756, 4.206246, 0, 0, 0, 1, 120, 255, 1), -- Tin Vein (Area: Ruins of Zul'Kunda)
(@OGUID+103, 1622, 0, 1, 1, -11816.1, 72.49132, 17.07243, 0, 0, 0, 0, 1, 120, 255, 1), -- Bruiseweed (Area: 0)
(@OGUID+104, 1962, 0, 1, 1, -11831.16, 68.67882, 14.35985, 3.185232, 0, 0, 0, 1, 120, 255, 1), -- Campfire (Area: 0)
(@OGUID+105, 209864, 0, 1, 1, -11789.3, -54.55382, 40.89132, 5.305802, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Tkashi Ruins)
(@OGUID+106, 209866, 0, 1, 1, -11788.6, -55.09896, 41.52674, 3.516848, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Tkashi Ruins)
(@OGUID+107, 209865, 0, 1, 1, -11789.8, -55.00695, 40.60405, 0.4974173, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Tkashi Ruins)
(@OGUID+108, 1732, 0, 1, 1, -11757.2, -250.04, 31.9873, 4.206246, 0, 0, 0, 1, 120, 255, 1), -- Tin Vein (Area: 0)
(@OGUID+109, 180684, 0, 1, 1, -11769.4, -369.0104, 10.06987, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Greater Sagefish School (Area: 0)
(@OGUID+110, 2041, 0, 1, 1, -11752.8, -316.965, 10.363, 2.91469, 0, 0, 0, 1, 120, 255, 1), -- Liferoot (Area: 0)
(@OGUID+111, 1732, 0, 1, 1, -11796, -418.648, 26.6982, 4.206246, 0, 0, 0, 1, 120, 255, 1), -- Tin Vein (Area: 0)
(@OGUID+112, 1624, 0, 1, 1, -11776.9, -551.894, 16.0366, 5.113817, 0, 0, 0, 1, 120, 255, 1), -- Kingsblood (Area: 0)
(@OGUID+113, 1732, 0, 1, 1, -11785.3, -607.356, 41.5616, 4.206246, 0, 0, 0, 1, 120, 255, 1), -- Tin Vein (Area: 0)
(@OGUID+114, 1624, 0, 1, 1, -11801, -661.594, 36.7742, 5.113817, 0, 0, 0, 1, 120, 255, 1), -- Kingsblood (Area: 0)
(@OGUID+115, 1623, 0, 1, 1, -11844.4, -908.635, 51.9319, 0.3141584, 0, 0, 0, 1, 120, 255, 1), -- Wild Steelbloom (Area: 0)
(@OGUID+116, 1732, 0, 1, 1, -11800, -899.066, 42.5966, 4.206246, 0, 0, 0, 1, 120, 255, 1), -- Tin Vein (Area: 0)
(@OGUID+117, 1624, 0, 1, 1, -11835.1, -766.599, 34.9251, 5.113817, 0, 0, 0, 1, 120, 255, 1), -- Kingsblood (Area: 0)
(@OGUID+118, 1624, 0, 1, 1, -11864.3, 593.585, 44.7549, 5.113817, 0, 0, 0, 1, 120, 255, 1), -- Kingsblood (Area: Ruins of Zul'Kunda)
(@OGUID+119, 1624, 0, 1, 1, -11868.3, 466.698, 44.5344, 5.113817, 0, 0, 0, 1, 120, 255, 1), -- Kingsblood (Area: Ruins of Zul'Kunda)
(@OGUID+120, 1624, 0, 1, 1, -11857.7, 213.514, 16.585, 5.113817, 0, 0, 0, 1, 120, 255, 1), -- Kingsblood (Area: 0)
(@OGUID+121, 1623, 0, 1, 1, -11816.1, 25.0538, 31.5987, 0.3141584, 0, 0, 0, 1, 120, 255, 1), -- Wild Steelbloom (Area: Tkashi Ruins)
(@OGUID+122, 1732, 0, 1, 1, -11839.6, 24.9132, 31.3091, 4.206246, 0, 0, 0, 1, 120, 255, 1), -- Tin Vein (Area: Tkashi Ruins)
(@OGUID+123, 180684, 0, 1, 1, -11881, -455.3993, 10.06987, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Greater Sagefish School (Area: 0)
(@OGUID+124, 2041, 0, 1, 1, -11869, -465.479, 10.1868, 2.91469, 0, 0, 0, 1, 120, 255, 1), -- Liferoot (Area: 0)
(@OGUID+125, 1624, 0, 1, 1, -11867.8, -546.743, 15.1609, 5.113817, 0, 0, 0, 1, 120, 255, 1), -- Kingsblood (Area: 0)
(@OGUID+126, 1733, 0, 1, 1, -11853.7, -672.533, 38.9212, 4.206246, 0, 0, 0, 1, 120, 255, 1), -- Silver Vein (Area: 0)
(@OGUID+127, 1623, 0, 1, 1, -11848.2, -713.127, 42.4506, 0.3141584, 0, 0, 0, 1, 120, 255, 1), -- Wild Steelbloom (Area: 0)
(@OGUID+128, 176549, 0, 1, 1, -11887.26, -1003.285, 91.27657, 2.905961, 0, 0, 0, 1, 120, 255, 1), -- Brazier (Area: 0)
(@OGUID+129, 176550, 0, 1, 1, -11876.74, -1003.089, 91.38979, 3.176533, 0, 0, 0, 1, 120, 255, 1), -- Brazier (Area: 0)
(@OGUID+130, 1964, 0, 1, 1, -11936.37, -573.0278, 16.87351, 5.139997, 0, 0, 0, 1, 120, 255, 1), -- Campfire (Area: Venture Co. Base Camp)
(@OGUID+131, 2041, 0, 1, 1, -11932.8, -302.073, 10.3453, 2.91469, 0, 0, 0, 1, 120, 255, 1), -- Liferoot (Area: Lake Nazferiti)
(@OGUID+132, 1624, 0, 1, 1, -11892.8, -229.646, 17.0327, 5.113817, 0, 0, 0, 1, 120, 255, 1), -- Kingsblood (Area: Lake Nazferiti)
(@OGUID+133, 1732, 0, 1, 1, -11909.4, 196.889, 30.1917, 4.206246, 0, 0, 0, 1, 120, 255, 1), -- Tin Vein (Area: Tkashi Ruins)
(@OGUID+134, 1623, 0, 1, 1, -11925.6, 620.368, 22.4043, 0.3141584, 0, 0, 0, 1, 120, 255, 1), -- Wild Steelbloom (Area: 0)
(@OGUID+135, 180682, 0, 1, 1, -11923.3, 862.4045, 0, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Oily Blackmouth School (Area: Zuuldaia Ruins)
(@OGUID+136, 1623, 0, 1, 1, -11951.4, 801.696, 8.29784, 0.3141584, 0, 0, 0, 1, 120, 255, 1), -- Wild Steelbloom (Area: The Savage Coast)
(@OGUID+137, 1623, 0, 1, 1, -11950.7, 341.148, 21.1117, 0.3141584, 0, 0, 0, 1, 120, 255, 1), -- Wild Steelbloom (Area: 0)
(@OGUID+138, 176551, 0, 1, 1, -11886.18, -1051.644, 115.9881, 1.317723, 0, 0, 0, 1, 120, 255, 1), -- Brazier (Area: 0)
(@OGUID+139, 176552, 0, 1, 1, -11875.61, -1051.906, 116.0049, 1.483528, 0, 0, 0, 1, 120, 255, 1), -- Brazier (Area: 0)
(@OGUID+140, 176553, 0, 1, 1, -11942.68, -1005.505, 89.04345, 3.298687, 0, 0, 0, 1, 120, 255, 1), -- Brazier (Area: 0)
(@OGUID+141, 176555, 0, 1, 1, -11957.42, -1052.776, 110.9133, 2.818698, 0, 0, 0, 1, 120, 255, 1), -- Brazier (Area: Zul'Gurub)
(@OGUID+142, 176556, 0, 1, 1, -11946.64, -1052.818, 111.0407, 1.596976, 0, 0, 0, 1, 120, 255, 1), -- Brazier (Area: Zul'Gurub)
(@OGUID+143, 176554, 0, 1, 1, -11953.39, -1005.846, 88.86658, 2.923416, 0, 0, 0, 1, 120, 255, 1), -- Brazier (Area: Zul'Gurub)
(@OGUID+144, 1624, 0, 1, 1, -11972, -854.019, 32.8981, 5.113817, 0, 0, 0, 1, 120, 255, 1), -- Kingsblood (Area: 0)
(@OGUID+145, 180684, 0, 1, 1, -11935.8, -317.7882, 10.085, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Greater Sagefish School (Area: Lake Nazferiti)
(@OGUID+146, 1624, 0, 1, 1, -11985.6, -222.231, 19.4342, 5.113817, 0, 0, 0, 1, 120, 255, 1), -- Kingsblood (Area: Lake Nazferiti)
(@OGUID+147, 1623, 0, 1, 1, -11982.8, -141.821, 29.3621, 0.3141584, 0, 0, 0, 1, 120, 255, 1), -- Wild Steelbloom (Area: 0)
(@OGUID+148, 1732, 0, 1, 1, -11969.6, -113.207, 17.2929, 4.206246, 0, 0, 0, 1, 120, 255, 1), -- Tin Vein (Area: 0)
(@OGUID+149, 94185, 0, 1, 1, -11990.8, 318.309, 1.054671, 2.853604, 0, 0, 0, 1, 120, 255, 1), -- Bonfire (Area: 0)
(@OGUID+150, 204001, 0, 1, 1, -11980.59, 337.8663, 2.897748, 4.171338, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+151, 204001, 0, 1, 1, -11986.1, 334.9445, 1.727737, 3.176533, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+152, 204001, 0, 1, 1, -11977.43, 329.8264, 3.098213, 2.565632, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+153, 204001, 0, 1, 1, -11976.87, 332.1094, 3.351961, 3.176533, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+154, 204001, 0, 1, 1, -11976.86, 316.7865, 3.467423, 3.176533, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+155, 204000, 0, 1, 1, -11977.99, 335.7743, 3.244114, 3.717554, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+156, 2045, 0, 1, 1, -11999.76, 926.7278, -17.66391, 3.996807, 0, 0, 0, 1, 120, 255, 1), -- Stranglekelp (Area: The Savage Coast)
(@OGUID+157, 2045, 0, 1, 1, -12013.9, 945.3622, -17.10928, 2.652894, 0, 0, 0, 1, 120, 255, 1), -- Stranglekelp (Area: The Savage Coast)
(@OGUID+158, 180682, 0, 1, 1, -12029.7, 627.9479, 0, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Oily Blackmouth School (Area: The Savage Coast)
(@OGUID+159, 2045, 0, 1, 1, -12049.96, 566.9494, -15.51717, 3.106652, 0, 0, 0, 1, 120, 255, 1), -- Stranglekelp (Area: The Savage Coast)
(@OGUID+160, 57, 0, 1, 1, -12024.4, 363.302, 1.70278, 5.038821, 0, 0, 0, 1, 120, 255, 1), -- Moon Over the Vale (Area: 0)
(@OGUID+161, 204001, 0, 1, 1, -12019.02, 332.2899, 3.347457, 3.176533, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+162, 204001, 0, 1, 1, -12014.62, 325.132, 3.424686, 0.5235979, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+163, 204044, 0, 1, 1, -12033.1, 360.712, 0.969516, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+164, 1623, 0, 1, 1, -11928.3, 4.06597, 32.3406, 0.3141584, 0, 0, 0, 1, 120, 255, 1), -- Wild Steelbloom (Area: 0)
(@OGUID+165, 180684, 0, 1, 1, -11999.4, -378.1788, 10.06987, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Greater Sagefish School (Area: Lake Nazferiti)
(@OGUID+166, 208350, 0, 1, 1, -11915.87, -1220.608, 94.21243, 1.570796, 0, 0, 1, -4.371139E-08, 120, 255, 1), -- -Unknown- (Area: Zul'Gurub)
(@OGUID+167, 208349, 0, 1, 1, -11915.87, -1220.608, 94.21243, 1.570796, 0, 0, 1, -4.371139E-08, 120, 255, 1), -- -Unknown- (Area: Zul'Gurub)
(@OGUID+168, 208358, 0, 1, 1, -11943.1, -1199.986, 85.19459, 3.822273, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Zul'Gurub)
(@OGUID+169, 179700, 0, 1, 1, -11557.28, -1246.012, 77.39412, 2.522002, 0, 0, 0, 1, 120, 255, 1), -- Cauldron (Area: Zul'Gurub)
(@OGUID+170, 180386, 0, 1, 1, -11520.01, -1642.354, 52.63557, 1.666787, 0, 0, 0.7101853, 0.7040148, 120, 255, 1), -- Gong (Area: Zul'Gurub)
(@OGUID+171, 112879, 0, 1, 1, -11985.56, -1702.976, 32.28356, 3.176533, 0, 0, 0, 1, 120, 255, 1), -- Bonefire (Area: Zul'Gurub)
(@OGUID+172, 111839, 0, 1, 1, -12011.83, -1800.528, 57.5653, 4.808384, 0, 0, 0, 1, 120, 255, 1), -- Bonfire (Area: Zul'Gurub)
(@OGUID+173, 1622, 0, 1, 1, -11998.7, -515.547, 11.4551, 0, 0, 0, 0, 1, 120, 255, 1), -- Bruiseweed (Area: Venture Co. Base Camp)
(@OGUID+174, 20691, 0, 1, 1, -12033.51, -544.2742, 14.47195, 3.822273, 0, 0, 0, 1, 120, 255, 1), -- Cozzle's Footlocker (Area: Venture Co. Base Camp)
(@OGUID+175, 180684, 0, 1, 1, -12023.7, -488.1233, 10.06987, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Greater Sagefish School (Area: Venture Co. Operations Center)
(@OGUID+176, 1732, 0, 1, 1, -12018.9, -304.424, 37.1956, 4.206246, 0, 0, 0, 1, 120, 255, 1), -- Tin Vein (Area: Lake Nazferiti)
(@OGUID+177, 1624, 0, 1, 1, -12027.5, 28.6285, 3.87027, 5.113817, 0, 0, 0, 1, 120, 255, 1), -- Kingsblood (Area: 0)
(@OGUID+178, 1732, 0, 1, 1, -12036.9, 137.208, 19.1224, 4.206246, 0, 0, 0, 1, 120, 255, 1), -- Tin Vein (Area: 0)
(@OGUID+179, 1624, 0, 1, 1, -12072.4, 158.186, 15.7298, 5.113817, 0, 0, 0, 1, 120, 255, 1), -- Kingsblood (Area: 0)
(@OGUID+180, 1624, 0, 1, 1, -12023.6, 227.269, 10.9853, 5.113817, 0, 0, 0, 1, 120, 255, 1), -- Kingsblood (Area: 0)
(@OGUID+181, 1623, 0, 1, 1, -12005.7, 276.582, 19.3455, 0.3141584, 0, 0, 0, 1, 120, 255, 1), -- Wild Steelbloom (Area: 0)
(@OGUID+182, 1624, 0, 1, 1, -12066, 278.083, 3.10429, 5.113817, 0, 0, 0, 1, 120, 255, 1), -- Kingsblood (Area: 0)
(@OGUID+183, 1623, 0, 1, 1, -11950.7, 341.148, 21.1117, 0.3141584, 0, 0, 0, 1, 120, 255, 1), -- Wild Steelbloom (Area: 0)
(@OGUID+184, 1622, 0, 1, 1, -12000.8, 344.203, 3.13611, 0, 0, 0, 0, 1, 120, 255, 1), -- Bruiseweed (Area: 0)
(@OGUID+185, 181636, 0, 1, 1, -12130.55, 958.9944, 4.871482, 5.026549, 0, 0, 0, 1, 120, 255, 1), -- Altar of Naias (Area: The Savage Coast)
(@OGUID+186, 58, 0, 1, 1, -12140.87, 640.9339, -70.77702, 0.5647435, 0, 0, 0, 1, 120, 255, 1), -- Gri'lek the Wanderer (Area: The Savage Coast)
(@OGUID+187, 1732, 0, 1, 1, -12122.5, 237.62, 15.9628, 4.206246, 0, 0, 0, 1, 120, 255, 1), -- Tin Vein (Area: Bal'lal Ruins)
(@OGUID+188, 1732, 0, 1, 1, -12109, -26.7344, 17.2353, 4.206246, 0, 0, 0, 1, 120, 255, 1), -- Tin Vein (Area: 0)
(@OGUID+189, 1623, 0, 1, 1, -12093.6, -16.9306, 17.9135, 0.3141584, 0, 0, 0, 1, 120, 255, 1), -- Wild Steelbloom (Area: 0)
(@OGUID+190, 1624, 0, 1, 1, -12094.4, -271.375, 16.8864, 5.113817, 0, 0, 0, 1, 120, 255, 1), -- Kingsblood (Area: 0)
(@OGUID+191, 180684, 0, 1, 1, -12081, -381.1563, 10.06987, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Greater Sagefish School (Area: 0)
(@OGUID+192, 180684, 0, 1, 1, -12059.8, -336.7726, 10.06987, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Greater Sagefish School (Area: 0)
(@OGUID+193, 180684, 0, 1, 1, -12062.2, -471.0243, 10.06987, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Greater Sagefish School (Area: Lake Nazferiti)
(@OGUID+194, 3798, 0, 1, 1, -12040.71, -539.602, 14.40786, 2.513274, 0, 0, 0.3338069, 0.9426414, 120, 255, 1), -- Cozy Fire (Area: Lake Nazferiti)
(@OGUID+195, 3797, 0, 1, 1, -12041.45, -540.1071, 14.40786, 3.804818, 0, 0, 0.3338069, 0.9426414, 120, 255, 1), -- Cozy Fire (Area: Lake Nazferiti)
(@OGUID+196, 1624, 0, 1, 1, -12073.2, -775.352, 16.5019, 5.113817, 0, 0, 0, 1, 120, 255, 1), -- Kingsblood (Area: Venture Co. Base Camp)
(@OGUID+197, 1732, 0, 1, 1, -12046.3, -811.299, 46.0506, 4.206246, 0, 0, 0, 1, 120, 255, 1), -- Tin Vein (Area: Venture Co. Base Camp)
(@OGUID+198, 1623, 0, 1, 1, -12075.7, -795.469, 40.4684, 0.3141584, 0, 0, 0, 1, 120, 255, 1), -- Wild Steelbloom (Area: Venture Co. Base Camp)
(@OGUID+199, 142078, 0, 1, 1, -12040.27, -1005.964, 49.41035, 2.417279, 0, 0, 0, 1, 120, 255, 1), -- Forge (Area: 0)
(@OGUID+200, 142077, 0, 1, 1, -12041.5, -1009.653, 49.39666, 1.946041, 0, 0, 0, 1, 120, 255, 1), -- Anvil (Area: 0)
(@OGUID+201, 142079, 0, 1, 1, -12051.49, -1010.979, 49.13081, 2.347464, 0, 0, 0, 1, 120, 255, 1), -- Campfire (Area: 0)
(@OGUID+202, 180684, 0, 1, 1, -12115.3, -350.4479, 10.06987, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Greater Sagefish School (Area: Lake Nazferiti)
(@OGUID+203, 1622, 0, 1, 1, -12103.9, -173.017, 32.1562, 0, 0, 0, 0, 1, 120, 255, 1), -- Bruiseweed (Area: 0)
(@OGUID+204, 179426, 0, 1, 1, -12148.26, 636.767, -70.05853, 3.68265, 0, 0, 0, 1, 120, 255, 1), -- Gri'lek the Wanderer (Area: The Savage Coast)
(@OGUID+205, 2744, 0, 1, 1, -12166.38, 715.3006, -49.35242, 0.8203033, 0, 0, 0, 1, 120, 255, 1), -- Giant Clam (Area: The Vile Reef)
(@OGUID+206, 1732, 0, 1, 1, -12181.7, 864.186, 19.0586, 4.206246, 0, 0, 0, 1, 120, 255, 1), -- Tin Vein (Area: The Savage Coast)
(@OGUID+207, 180683, 0, 1, 1, -12171.9, 767.9011, 0, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Firefin Snapper School (Area: The Savage Coast)
(@OGUID+208, 180682, 0, 1, 1, -12210.3, 803.8351, 0, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Oily Blackmouth School (Area: The Savage Coast)
(@OGUID+209, 2576, 0, 1, 1, -12171.94, 628.1962, -62.12188, 0.4799661, 0, 0, 0, 1, 120, 255, 1), -- Altar of the Tides (Area: The Vile Reef)
(@OGUID+210, 2744, 0, 1, 1, -12208.86, 571.4238, -36.95314, 3.752462, 0, 0, 0, 1, 120, 255, 1), -- Giant Clam (Area: The Vile Reef)
(@OGUID+211, 2045, 0, 1, 1, -12221.44, 589.087, -54.84886, 4.32842, 0, 0, 0, 1, 120, 255, 1), -- Stranglekelp (Area: The Vile Reef)
(@OGUID+212, 2744, 0, 1, 1, -12210.5, 528.4788, -65.70921, 3.351047, 0, 0, 0, 1, 120, 255, 1), -- Giant Clam (Area: The Vile Reef)
(@OGUID+213, 2744, 0, 1, 1, -12244.26, 581.7045, -74.97887, 6.108654, 0, 0, 0, 1, 120, 255, 1), -- Giant Clam (Area: The Vile Reef)
(@OGUID+214, 2744, 0, 1, 1, -12164.21, 477.8309, -38.88026, 1.396262, 0, 0, 0, 1, 120, 255, 1), -- Giant Clam (Area: The Vile Reef)
(@OGUID+215, 2744, 0, 1, 1, -12142.79, 466.6694, -30.63736, 4.153885, 0, 0, 0, 1, 120, 255, 1), -- Giant Clam (Area: The Vile Reef)
(@OGUID+216, 2744, 0, 1, 1, -12223.89, 441.4467, -88.08801, 5.829401, 0, 0, 0, 1, 120, 255, 1), -- Giant Clam (Area: The Vile Reef)
(@OGUID+217, 180682, 0, 1, 1, -12208, 351.2726, 0, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Oily Blackmouth School (Area: The Vile Reef)
(@OGUID+218, 1624, 0, 1, 1, -12204.4, 295.063, 3.86297, 5.113817, 0, 0, 0, 1, 120, 255, 1), -- Kingsblood (Area: The Savage Coast)
(@OGUID+219, 1732, 0, 1, 1, -12212.5, 12.9132, 24.2134, 4.206246, 0, 0, 0, 1, 120, 255, 1), -- Tin Vein (Area: Kal'ai Ruins)
(@OGUID+220, 2041, 0, 1, 1, -12198.4, -24.82986, -1.56633, 2.91469, 0, 0, 0, 1, 120, 255, 1), -- Liferoot (Area: Kal'ai Ruins)
(@OGUID+221, 3204, 0, 1, 1, -12167.74, -230.0781, 33.28585, 4.267334, 0, 0, 0, 1, 120, 255, 1), -- Booty Bay (Area: 0)
(@OGUID+222, 3203, 0, 1, 1, -12167.74, -230.059, 32.34282, 4.267334, 0, 0, 0, 1, 120, 255, 1), -- Arena (Area: 0)
(@OGUID+223, 3202, 0, 1, 1, -12167.85, -229.592, 33.28014, 2.574359, 0, 0, 0, 1, 120, 255, 1), -- Grom'gol (Area: 0)
(@OGUID+224, 1623, 0, 1, 1, -12179.8, -184.017, 36.1427, 0.3141584, 0, 0, 0, 1, 120, 255, 1), -- Wild Steelbloom (Area: 0)
(@OGUID+225, 1622, 0, 1, 1, -12170.6, -934.227, 49.471, 0, 0, 0, 0, 1, 120, 255, 1), -- Bruiseweed (Area: Bambala)
(@OGUID+226, 204821, 0, 1, 1, -12216.8, -1425.851, 130.542, 3.194013, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Zul'Gurub)
(@OGUID+227, 1623, 0, 1, 1, -12197.5, -580.283, 30.1788, 0.3141584, 0, 0, 0, 1, 120, 255, 1), -- Wild Steelbloom (Area: Venture Co. Base Camp)
(@OGUID+228, 3206, 0, 1, 1, -12205.6, -536.2952, 27.90343, 2.478366, 0, 0, 0, 1, 120, 255, 1), -- Booty Bay (Area: Venture Co. Base Camp)
(@OGUID+229, 3205, 0, 1, 1, -12205.79, -536.6424, 29.19445, 2.478367, 0, 0, 0, 1, 120, 255, 1), -- Arena (Area: Venture Co. Base Camp)
(@OGUID+230, 3207, 0, 1, 1, -12205.74, -535.4496, 29.86271, 5.619961, 0, 0, 0, 1, 120, 255, 1), -- Duskwood (Area: Venture Co. Base Camp)
(@OGUID+231, 1732, 0, 1, 1, -12217.6, -585.488, 32.165, 4.206246, 0, 0, 0, 1, 120, 255, 1), -- Tin Vein (Area: Venture Co. Base Camp)
(@OGUID+232, 2041, 0, 1, 1, -12221.8, -357.215, 10.1137, 2.91469, 0, 0, 0, 1, 120, 255, 1), -- Liferoot (Area: Lake Nazferiti)
(@OGUID+233, 2744, 0, 1, 1, -12276.98, 694.413, -98.29436, 4.206246, 0, 0, 0, 1, 120, 255, 1), -- Giant Clam (Area: The Vile Reef)
(@OGUID+234, 2744, 0, 1, 1, -12314.86, 678.0753, -60.35043, 2.024579, 0, 0, 0, 1, 120, 255, 1), -- Giant Clam (Area: The Vile Reef)
(@OGUID+235, 2744, 0, 1, 1, -12282.72, 538.5933, -84.81149, 4.939284, 0, 0, 0, 1, 120, 255, 1), -- Giant Clam (Area: The Vile Reef)
(@OGUID+236, 2744, 0, 1, 1, -12305.67, 435.5042, -20.53557, 3.926996, 0, 0, 0, 1, 120, 255, 1), -- Giant Clam (Area: The Vile Reef)
(@OGUID+237, 1624, 0, 1, 1, -12223.4, -89.1979, 22.7276, 5.113817, 0, 0, 0, 1, 120, 255, 1), -- Kingsblood (Area: Kal'ai Ruins)
(@OGUID+238, 1624, 0, 1, 1, -12249, -239.201, 16.6285, 5.113817, 0, 0, 0, 1, 120, 255, 1), -- Kingsblood (Area: 0)
(@OGUID+239, 1624, 0, 1, 1, -12240.3, -402.203, 15.6004, 5.113817, 0, 0, 0, 1, 120, 255, 1), -- Kingsblood (Area: 0)
(@OGUID+240, 204822, 0, 1, 1, -12284.9, -1463.931, 130.54, 3.115425, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Zul'Gurub)
(@OGUID+241, 1732, 0, 1, 1, -12291.22, -1097.087, 10.28723, 0, 0, 0, 0, 1, 120, 255, 1), -- Tin Vein (Area: Zul'Gurub)
(@OGUID+242, 1732, 0, 1, 1, -12337.1, -831.141, 37.7046, 4.206246, 0, 0, 0, 1, 120, 255, 1), -- Tin Vein (Area: Mosh'Ogg Ogre Mound)
(@OGUID+243, 1732, 0, 1, 1, -12305.3, -789.743, 32.5098, 4.206246, 0, 0, 0, 1, 120, 255, 1), -- Tin Vein (Area: Mosh'Ogg Ogre Mound)
(@OGUID+244, 1624, 0, 1, 1, -12302.1, -695.34, 16.4305, 5.113817, 0, 0, 0, 1, 120, 255, 1), -- Kingsblood (Area: Venture Co. Base Camp)
(@OGUID+245, 204801, 0, 1, 1, -12272, -569.957, 31.5594, 3.543024, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Venture Co. Base Camp)
(@OGUID+246, 204802, 0, 1, 1, -12271.5, -570.096, 31.5224, 5.270896, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Venture Co. Base Camp)
(@OGUID+247, 204803, 0, 1, 1, -12271.2, -569.76, 31.5487, 0.1919852, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Venture Co. Base Camp)
(@OGUID+248, 180684, 0, 1, 1, -12296.3, -295.5573, 10.06987, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Greater Sagefish School (Area: 0)
(@OGUID+249, 2041, 0, 1, 1, -12279.9, -287.53, 10.2354, 2.91469, 0, 0, 0, 1, 120, 255, 1), -- Liferoot (Area: 0)
(@OGUID+250, 180683, 0, 1, 1, -12310.7, 359.5417, 0, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Firefin Snapper School (Area: The Savage Coast)
(@OGUID+251, 2744, 0, 1, 1, -12328.45, 572.8104, -65.94151, 3.874631, 0, 0, 0, 1, 120, 255, 1), -- Giant Clam (Area: The Vile Reef)
(@OGUID+252, 2744, 0, 1, 1, -12359.63, 665.0458, -37.03369, 3.543024, 0, 0, 0, 1, 120, 255, 1), -- Giant Clam (Area: The Vile Reef)
(@OGUID+253, 2744, 0, 1, 1, -12357.55, 690.5988, -21.51221, 3.595379, 0, 0, 0, 1, 120, 255, 1), -- Giant Clam (Area: The Vile Reef)
(@OGUID+254, 176493, 0, 1, 1, -12317.71, 188.8698, 5.945459, 3.255066, 0, 0, 0, 1, 120, 255, 1), -- Brazier (Area: 0)
(@OGUID+255, 176492, 0, 1, 1, -12314.1, 171.238, 6.68062, 2.443459, 0, 0, 0, 1, 120, 255, 1), -- Brazier (Area: 0)
(@OGUID+256, 176790, 0, 1, 1, -12357.5, 218.701, 4.01822, 3.124123, 0, 0, 0, 1, 120, 255, 1), -- Cooking Table (Area: 0)
(@OGUID+257, 2076, 0, 1, 1, -12342.9, 165.09, 2.8544, 5.393069, 0, 0, 0, 1, 120, 255, 1), -- Bubbling Cauldron (Area: 0)
(@OGUID+258, 51703, 0, 1, 1, -12344.79, 152.7245, 4.776526, 4.406958, 0, 0, 0.9381913, 0.3461172, 120, 255, 1), -- Anvil (Area: 0)
(@OGUID+259, 50983, 0, 1, 1, -12351.7, 149.0391, 2.60294, 2.434729, 0, 0, 0.9381913, 0.3461172, 120, 255, 1), -- Heated Forge (Area: 0)
(@OGUID+260, 51702, 0, 1, 1, -12355.25, 144.0254, 4.507335, 0.3403376, 0, 0, 0.9381913, 0.3461172, 120, 255, 1), -- Anvil (Area: 0)
(@OGUID+261, 1624, 0, 1, 1, -12301, 14.9323, 18.1098, 5.113817, 0, 0, 0, 1, 120, 255, 1), -- Kingsblood (Area: 0)
(@OGUID+262, 1624, 0, 1, 1, -12325, -370.434, 15.6469, 5.113817, 0, 0, 0, 1, 120, 255, 1), -- Kingsblood (Area: 0)
(@OGUID+263, 1732, 0, 1, 1, -12346.9, -558.403, 27.4378, 4.206246, 0, 0, 0, 1, 120, 255, 1), -- Tin Vein (Area: 0)
(@OGUID+264, 92254, 0, 1, 1, -12355.03, -1954.748, 132.3531, 3.281239, 0, 0, 0, 1, 120, 255, 1), -- Bonfire (Area: Zul'Gurub)
(@OGUID+265, 1732, 0, 1, 1, -12383.24, -1071.028, 3.9644, 0, 0, 0, 0, 1, 120, 255, 1), -- Tin Vein (Area: 0)
(@OGUID+266, 1732, 0, 1, 1, -12358.02, -1012.964, 8.341344, 0, 0, 0, 0, 1, 120, 255, 1), -- Tin Vein (Area: 0)
(@OGUID+267, 1732, 0, 1, 1, -12382.7, -1012.63, 66.4167, 4.206246, 0, 0, 0, 1, 120, 255, 1), -- Tin Vein (Area: Mosh'Ogg Ogre Mound)
(@OGUID+268, 1624, 0, 1, 1, -12402.5, -640.09, 15.6528, 5.113817, 0, 0, 0, 1, 120, 255, 1), -- Kingsblood (Area: 0)
(@OGUID+269, 2551, 0, 1, 1, -12343.02, 164.6198, 4.427064, 1.815142, 0, 0, 0, 1, 120, 255, 1), -- Boiled Skull (Area: 0)
(@OGUID+270, 2744, 0, 1, 1, -12415.21, 674.2449, -67.72393, 2.44346, 0, 0, 0, 1, 120, 255, 1), -- Giant Clam (Area: The Vile Reef)
(@OGUID+271, 2045, 0, 1, 1, -12416.86, 749.5942, -35.95424, 1.727875, 0, 0, 0, 1, 120, 255, 1), -- Stranglekelp (Area: The Vile Reef)
(@OGUID+272, 2744, 0, 1, 1, -12407.18, 633.1382, -89.53172, 3.176533, 0, 0, 0, 1, 120, 255, 1), -- Giant Clam (Area: The Vile Reef)
(@OGUID+273, 2744, 0, 1, 1, -12439.67, 455.6772, -47.69663, 0.7504908, 0, 0, 0, 1, 120, 255, 1), -- Giant Clam (Area: The Vile Reef)
(@OGUID+274, 2744, 0, 1, 1, -12406.91, 440.6195, -41.53638, 2.705255, 0, 0, 0, 1, 120, 255, 1), -- Giant Clam (Area: The Vile Reef)
(@OGUID+275, 176488, 0, 1, 1, -12373.4, 246.095, 4.22439, 2.260198, 0, 0, 0, 1, 120, 255, 1), -- Brazier (Area: The Vile Reef)
(@OGUID+276, 208334, 0, 1, 1, -12412.64, 237.25, 0.9884447, 5.192355, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Grom'gol Base Camp)
(@OGUID+277, 208333, 0, 1, 1, -12412.65, 237.2344, 2.558685, 4.747296, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Grom'gol Base Camp)
(@OGUID+278, 176491, 0, 1, 1, -12390.6, 244.266, 2.73307, 2.888509, 0, 0, 0, 1, 120, 255, 1), -- Brazier (Area: Grom'gol Base Camp)
(@OGUID+279, 2551, 0, 1, 1, -12342.66, 165.0896, 4.341924, 1.239183, 0, 0, 0, 1, 120, 255, 1), -- Boiled Skull (Area: Grom'gol Base Camp)
(@OGUID+280, 2551, 0, 1, 1, -12343.02, 164.6198, 4.427064, 1.815142, 0, 0, 0, 1, 120, 255, 1), -- Boiled Skull (Area: Grom'gol Base Camp)
(@OGUID+281, 94186, 0, 1, 1, -12379.4, 180.623, 2.00652, 2.44346, 0, 0, 0, 1, 120, 255, 1), -- Bonfire (Area: Grom'gol Base Camp)
(@OGUID+282, 176496, 0, 1, 1, -12407.5, 205.701, 2.21347, 4.450594, 0, 0, 0, 1, 120, 255, 1), -- Brazier (Area: Grom'gol Base Camp)
(@OGUID+283, 163645, 0, 1, 1, -12387.6, 145.806, 2.51911, 4.677484, 0, 0, 0, 1, 120, 255, 1), -- Mailbox (Area: Grom'gol Base Camp)
(@OGUID+284, 1967, 0, 1, 1, -12416.7, 168.672, 3.27947, 4.642576, 0, 0, 0, 1, 120, 255, 1), -- Firepit (Area: Grom'gol Base Camp)
(@OGUID+285, 176489, 0, 1, 1, -12398.2, 132.182, 3.74312, 3.961903, 0, 0, 0, 1, 120, 255, 1), -- Brazier (Area: Grom'gol Base Camp)
(@OGUID+286, 176490, 0, 1, 1, -12380, 112.825, 5.23442, 4.136433, 0, 0, 0, 1, 120, 255, 1), -- Brazier (Area: Grom'gol Base Camp)
(@OGUID+287, 1732, 0, 1, 1, -12389.9, -50.9792, 19.5004, 4.206246, 0, 0, 0, 1, 120, 255, 1), -- Tin Vein (Area: 0)
(@OGUID+288, 1624, 0, 1, 1, -12392.2, -242.507, 15.7647, 5.113817, 0, 0, 0, 1, 120, 255, 1), -- Kingsblood (Area: 0)
(@OGUID+289, 1624, 0, 1, 1, -12419.7, -752.049, 30.7585, 5.113817, 0, 0, 0, 1, 120, 255, 1), -- Kingsblood (Area: 0)
(@OGUID+290, 1970, 0, 1, 1, -12430.61, -840.5434, 40.45408, 0.4941067, 0, 0, 0, 1, 120, 255, 1), -- Campfire (Area: 0)
(@OGUID+291, 1971, 0, 1, 1, -12467.54, -992.1979, 49.60252, 5.956988, 0, 0, 0, 1, 120, 255, 1), -- Campfire (Area: 0)
(@OGUID+292, 1624, 0, 1, 1, -12467.2, -694.538, 39.6258, 5.113817, 0, 0, 0, 1, 120, 255, 1), -- Kingsblood (Area: Mosh'Ogg Ogre Mound)
(@OGUID+293, 180684, 0, 1, 1, -12455.1, -294.6424, 10.1363, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Greater Sagefish School (Area: 0)
(@OGUID+294, 1624, 0, 1, 1, -12464.3, -87.8403, 17.2422, 5.113817, 0, 0, 0, 1, 120, 255, 1), -- Kingsblood (Area: 0)
(@OGUID+295, 1624, 0, 1, 1, -12428.9, -16.2153, 2.16821, 5.113817, 0, 0, 0, 1, 120, 255, 1), -- Kingsblood (Area: Mizjah Ruins)
(@OGUID+296, 176504, 0, 1, 1, -12418.3, 141.363, 3.4041, 3.988079, 0, 0, 0, 1, 120, 255, 1), -- Campfire (Area: 0)
(@OGUID+297, 195586, 0, 1, 1, -12432.41, 192.8163, 31.20265, 1.230456, 0, 0, 0.5842496, 0.811574, 120, 255, 1), -- Blazing Fire (Area: 0)
(@OGUID+298, 2045, 0, 1, 1, -12503.65, 231.2362, -11.82426, 0.6457717, 0, 0, 0, 1, 120, 255, 1), -- Stranglekelp (Area: Grom'gol Base Camp)
(@OGUID+299, 2744, 0, 1, 1, -12453.52, 519.7273, -72.17752, 5.794494, 0, 0, 0, 1, 120, 255, 1), -- Giant Clam (Area: The Vile Reef)
(@OGUID+300, 2744, 0, 1, 1, -12472.25, 554.9705, -60.84996, 0.06981169, 0, 0, 0, 1, 120, 255, 1), -- Giant Clam (Area: The Vile Reef)
(@OGUID+301, 180683, 0, 1, 1, -12535.9, 129.4913, 0, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Firefin Snapper School (Area: The Vile Reef)
(@OGUID+302, 1733, 0, 1, 1, -12483.6, -62.3854, 18.1909, 4.206246, 0, 0, 0, 1, 120, 255, 1), -- Silver Vein (Area: The Savage Coast)
(@OGUID+303, 1969, 0, 1, 1, -12485.5, -168.415, 12.8579, 3.140793, 0, 0, 0, 1, 120, 255, 1), -- Campfire (Area: 0)
(@OGUID+304, 2041, 0, 1, 1, -12539.3, -124.674, 10.004, 2.91469, 0, 0, 0, 1, 120, 255, 1), -- Liferoot (Area: 0)
(@OGUID+305, 1622, 0, 1, 1, -12496.5, -176.399, 13.0832, 0, 0, 0, 0, 1, 120, 255, 1), -- Bruiseweed (Area: 0)
(@OGUID+306, 2041, 0, 1, 1, -12484.3, -213.057, 9.97695, 2.91469, 0, 0, 0, 1, 120, 255, 1), -- Liferoot (Area: 0)
(@OGUID+307, 180684, 0, 1, 1, -12514.7, -211.5747, 10.06987, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Greater Sagefish School (Area: 0)
(@OGUID+308, 2041, 0, 1, 1, -12506.1, -267.37, 10.1285, 2.91469, 0, 0, 0, 1, 120, 255, 1), -- Liferoot (Area: Mizjah Ruins)
(@OGUID+309, 1624, 0, 1, 1, -12491.7, -345.009, 15.2198, 5.113817, 0, 0, 0, 1, 120, 255, 1), -- Kingsblood (Area: 0)
(@OGUID+310, 1732, 0, 1, 1, -12499.8, -457.398, 31.0871, 4.206246, 0, 0, 0, 1, 120, 255, 1), -- Tin Vein (Area: 0)
(@OGUID+311, 1732, 0, 1, 1, -12519.9, -600.651, 43.5361, 4.206246, 0, 0, 0, 1, 120, 255, 1), -- Tin Vein (Area: 0)
(@OGUID+312, 2891, 0, 1, 1, -12544.02, -723.0625, 40.44319, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Balia'mah Trophy Skulls (Area: 0)
(@OGUID+313, 2371, 0, 1, 1, -12543.84, -722.9777, 41.53819, 2.129301, 0, 0, 0, 1, 120, 255, 1), -- Headhunter Skull (Area: 0)
(@OGUID+314, 1972, 0, 1, 1, -12532.59, -729.1805, 38.64943, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Campfire (Area: 0)
(@OGUID+315, 1624, 0, 1, 1, -12484.9, -872.465, 38.9534, 5.113817, 0, 0, 0, 1, 120, 255, 1), -- Kingsblood (Area: Balia'mah Ruins)
(@OGUID+316, 204087, 0, 1, 1, -12496.87, -1012.028, 56.07911, 1.06465, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Mosh'Ogg Ogre Mound)
(@OGUID+317, 1732, 0, 1, 1, -12571.9, -941.366, 54.6639, 4.206246, 0, 0, 0, 1, 120, 255, 1), -- Tin Vein (Area: Mosh'Ogg Ogre Mound)
(@OGUID+318, 1622, 0, 1, 1, -12557.8, -727.012, 39.5844, 0, 0, 0, 0, 1, 120, 255, 1), -- Bruiseweed (Area: Balia'mah Ruins)
(@OGUID+319, 1624, 0, 1, 1, -12589.9, -492.111, 28.5905, 5.113817, 0, 0, 0, 1, 120, 255, 1), -- Kingsblood (Area: 0)
(@OGUID+320, 180684, 0, 1, 1, -12556.1, -102.0035, 10.06987, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Greater Sagefish School (Area: 0)
(@OGUID+321, 180683, 0, 1, 1, -12661.9, 180.2274, 0, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Firefin Snapper School (Area: The Vile Reef)
(@OGUID+322, 1624, 0, 1, 1, -12609.7, -743.193, 41.391, 5.113817, 0, 0, 0, 1, 120, 255, 1), -- Kingsblood (Area: 0)
(@OGUID+323, 1624, 0, 1, 1, -12632.5, -911.889, 55.7375, 5.113817, 0, 0, 0, 1, 120, 255, 1), -- Kingsblood (Area: Balia'mah Ruins)
(@OGUID+324, 164728, 0, 1, 1, -12686.47, -1019.714, 94.85239, 2.539448, 0, 0, 0, 1, 120, 255, 1), -- Campfire (Area: 0)
(@OGUID+325, 1735, 0, 1, 1, -12663.9, -762.059, 60.9823, 4.206246, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: Balia'mah Ruins)
(@OGUID+326, 1624, 0, 1, 1, -12675.2, -586.885, 36.7552, 5.113817, 0, 0, 0, 1, 120, 255, 1), -- Kingsblood (Area: Balia'mah Ruins)
(@OGUID+327, 1622, 0, 1, 1, -12652.1, -488.189, 30.2595, 0, 0, 0, 0, 1, 120, 255, 1), -- Bruiseweed (Area: Balia'mah Ruins)
(@OGUID+328, 2892, 0, 1, 1, -12705.1, -472.833, 30.2692, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Ziata'jai Trophy Skulls (Area: Ziata'jai Ruins)
(@OGUID+329, 2371, 0, 1, 1, -12705.02, -472.9383, 31.35554, 1.919862, 0, 0, 0, 1, 120, 255, 1), -- Headhunter Skull (Area: Ziata'jai Ruins)
(@OGUID+330, 1735, 0, 1, 1, -12682.5, -430.665, 33.338, 4.206246, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: Ziata'jai Ruins)
(@OGUID+331, 180682, 0, 1, 1, -12670.5, -20.34549, 0, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Oily Blackmouth School (Area: 0)
(@OGUID+332, 180682, 0, 1, 1, -12707.2, -20.44618, 0, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Oily Blackmouth School (Area: 0)
(@OGUID+333, 180683, 0, 1, 1, -12692.5, 106.8802, 0, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Firefin Snapper School (Area: The Savage Coast)
(@OGUID+334, 2042, 0, 1, 1, -12742.4, 238.035, 5.46783, 0, 0, 0, 0, 1, 120, 255, 1), -- Fadeleaf (Area: The Vile Reef)
(@OGUID+335, 180682, 0, 1, 1, -12724.9, 33.87153, 0, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Oily Blackmouth School (Area: Southern Savage Coast)
(@OGUID+336, 2043, 0, 1, 1, -12767.6, 105.67, 8.70348, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: Southern Savage Coast)
(@OGUID+337, 1624, 0, 1, 1, -12735.6, -863.347, 57.0631, 5.113817, 0, 0, 0, 1, 120, 255, 1), -- Kingsblood (Area: Balia'mah Ruins)
(@OGUID+338, 180682, 0, 1, 1, -12774.9, -10.05208, 0, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Oily Blackmouth School (Area: Southern Savage Coast)
(@OGUID+339, 1624, 0, 1, 1, -12768.2, -743.028, 61.8444, 5.113817, 0, 0, 0, 1, 120, 255, 1), -- Kingsblood (Area: 0)
(@OGUID+340, 1624, 0, 1, 1, -12833, -840.708, 57.0463, 5.113817, 0, 0, 0, 1, 120, 255, 1), -- Kingsblood (Area: 0)
(@OGUID+341, 1735, 0, 1, 1, -12837.9, -899.031, 61.7662, 4.206246, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: 0)
(@OGUID+342, 1733, 0, 1, 1, -12797.9, -823.283, 75.7924, 4.206246, 0, 0, 0, 1, 120, 255, 1), -- Silver Vein (Area: 0)
(@OGUID+343, 2893, 0, 1, 1, -12850.77, -819.7361, 54.88242, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Zul'Mamwe Trophy Skulls (Area: 0)
(@OGUID+344, 2371, 0, 1, 1, -12850.76, -819.9128, 56.05809, 0.8552105, 0, 0, 0, 1, 120, 255, 1), -- Headhunter Skull (Area: 0)
(@OGUID+345, 1622, 0, 1, 1, -12871.8, -831.425, 54.5513, 0, 0, 0, 0, 1, 120, 255, 1), -- Bruiseweed (Area: 0)
(@OGUID+346, 94187, 0, 1, 1, -12826.38, -742.3572, 75.86346, 3.892087, 0, 0, 0, 1, 120, 255, 1), -- Bonfire (Area: 0)
(@OGUID+347, 204247, 0, 1, 1, -12824.47, -757.0278, 76.87843, 5.218536, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+348, 204247, 0, 1, 1, -12827.84, -715.2118, 85.05865, 4.66003, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+349, 1735, 0, 1, 1, -12821, -590.781, 78.611, 4.206246, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: 0)
(@OGUID+350, 1735, 0, 1, 1, -12832.2, -568.075, 62.7217, 4.206246, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: 0)
(@OGUID+351, 204247, 0, 1, 1, -12863.34, -615.3837, 55.95394, 5.532695, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+352, 202603, 0, 1, 1, -12853.2, -416.931, 12.9025, 2.347464, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+353, 202604, 0, 1, 1, -12837.2, -427.316, 13.3204, 2.234018, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+354, 202605, 0, 1, 1, -12850, -416.524, 12.9662, 1.230456, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+355, 2043, 0, 1, 1, -12853.1, 377.845, 26.3169, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: Cape of Stranglethorn)
(@OGUID+356, 2045, 0, 1, 1, -12884.97, 524.0783, -9.659289, 3.403396, 0, 0, 0, 1, 120, 255, 1), -- Stranglekelp (Area: Southern Savage Coast)
(@OGUID+357, 1735, 0, 1, 1, -12894, 301.267, 23.8363, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: Southern Savage Coast)
(@OGUID+358, 2042, 0, 1, 1, -12918.6, 182.417, 18.8009, 0, 0, 0, 0, 1, 120, 255, 1), -- Fadeleaf (Area: Cape of Stranglethorn)
(@OGUID+359, 204247, 0, 1, 1, -12871.58, -608.9757, 56.51717, 5.585054, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+360, 204047, 0, 1, 1, -5520.566, 693.2934, 378.2548, 1.989672, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+361, 204247, 0, 1, 1, -12933.83, -625.9948, 53.28633, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+362, 1735, 0, 1, 1, -12920.8, -570.851, 62.0511, 4.206246, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: 0)
(@OGUID+363, 180682, 0, 1, 1, -12966.5, 490.7396, 0, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Oily Blackmouth School (Area: Southern Savage Coast)
(@OGUID+364, 1735, 0, 1, 1, -12946.3, 385.533, 33.0921, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: Southern Savage Coast)
(@OGUID+365, 1735, 0, 1, 1, -12979.1, 110.186, 38.9518, 0, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: Cape of Stranglethorn)
(@OGUID+366, 1975, 0, 1, 1, -12949.66, -618.0779, 52.33992, 3.142467, 0, 0, 0, 1, 120, 255, 1), -- Campfire (Area: 0)
(@OGUID+367, 1622, 0, 1, 1, -12957.4, -597.887, 53.2888, 0, 0, 0, 0, 1, 120, 255, 1), -- Bruiseweed (Area: 0)
(@OGUID+368, 204247, 0, 1, 1, -12955.27, -599.5521, 53.28879, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+369, 204247, 0, 1, 1, -12970.54, -612.7101, 53.29111, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+370, 204247, 0, 1, 1, -12939.44, -644.125, 53.21883, 4.66003, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+371, 204247, 0, 1, 1, -12978.08, -702.3941, 54.57527, 4.66003, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Ruins of Zul'Mamwe)
(@OGUID+372, 1976, 0, 1, 1, -12983.3, -712.7318, 53.76287, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Campfire (Area: Ruins of Zul'Mamwe)
(@OGUID+373, 204247, 0, 1, 1, -12974.72, -810.5018, 71.43587, 0, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Ruins of Zul'Mamwe)
(@OGUID+374, 1622, 0, 1, 1, -12972.4, -820.385, 70.9965, 0, 0, 0, 0, 1, 120, 255, 1), -- Bruiseweed (Area: Ruins of Zul'Mamwe)
(@OGUID+375, 204247, 0, 1, 1, -12976.24, -847.717, 71.45951, 4.66003, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Ruins of Zul'Mamwe)
(@OGUID+376, 204247, 0, 1, 1, -12999.46, -851.5799, 71.44836, 4.66003, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Ruins of Zul'Mamwe)
(@OGUID+377, 1977, 0, 1, 1, -12995.77, -837.9026, 70.15734, 3.143117, 0, 0, 0, 1, 120, 255, 1), -- Campfire (Area: Ruins of Zul'Mamwe)
(@OGUID+378, 204247, 0, 1, 1, -12997.15, -808.592, 71.71121, 4.66003, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Ruins of Zul'Mamwe)
(@OGUID+379, 204247, 0, 1, 1, -13004.34, -693.6042, 54.62734, 4.76475, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Ruins of Zul'Mamwe)
(@OGUID+380, 1735, 0, 1, 1, -13006.1, -404.356, 44.9172, 4.206246, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: 0)
(@OGUID+381, 2042, 0, 1, 1, -12995.9, 213.014, 18.6405, 0, 0, 0, 0, 1, 120, 255, 1), -- Fadeleaf (Area: Cape of Stranglethorn)
(@OGUID+382, 2042, 0, 1, 1, -13020, 348.003, 19.2828, 0, 0, 0, 0, 1, 120, 255, 1), -- Fadeleaf (Area: Cape of Stranglethorn)
(@OGUID+383, 2042, 0, 1, 1, -13005.4, 433.458, 20.6232, 0, 0, 0, 0, 1, 120, 255, 1), -- Fadeleaf (Area: Cape of Stranglethorn)
(@OGUID+384, 2043, 0, 1, 1, -12995.3, 438.156, 20.7182, 0, 0, 0, 0, 1, 120, 255, 1), -- Khadgar's Whisker (Area: Cape of Stranglethorn)
(@OGUID+385, 2045, 0, 1, 1, -13056.31, 522.9828, -21.85723, 2.024579, 0, 0, 0, 1, 120, 255, 1), -- Stranglekelp (Area: Southern Savage Coast)
(@OGUID+386, 1973, 0, 1, 1, -13069.3, -459.056, 44.7542, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Campfire (Area: Cape of Stranglethorn)
(@OGUID+387, 204247, 0, 1, 1, -13014.77, -607.2587, 55.24657, 5.061456, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+388, 94188, 0, 1, 1, -13006.68, -626.5836, 53.48281, 6.274461, 0, 0, 0, 1, 120, 255, 1), -- Bonfire (Area: 0)
(@OGUID+389, 204247, 0, 1, 1, -13073.89, -602.0504, 55.03547, 5.323256, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+390, 207486, 0, 1, 1, -13070.09, -619.6163, 53.37117, 1.099556, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+391, 1622, 0, 1, 1, -13010.3, -716.38, 55.2053, 0, 0, 0, 0, 1, 120, 255, 1), -- Bruiseweed (Area: Ruins of Zul'Mamwe)
(@OGUID+392, 1735, 0, 1, 1, -13059.9, -780.991, 78.4489, 4.206246, 0, 0, 0, 1, 120, 255, 1), -- Iron Deposit (Area: Ruins of Zul'Mamwe)
(@OGUID+393, 204247, 0, 1, 1, -13020.29, -817.0868, 70.27335, 4.136433, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Ruins of Zul'Mamwe)
(@OGUID+394, 204247, 0, 1, 1, -13014.88, -835.7448, 71.26595, 4.66003, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Ruins of Zul'Mamwe)
(@OGUID+395, 204247, 0, 1, 1, -13020.91, -835.309, 71.32056, 4.729844, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Ruins of Zul'Mamwe)
(@OGUID+396, 204247, 0, 1, 1, -13014.64, -846.4132, 71.45951, 4.66003, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Ruins of Zul'Mamwe)
(@OGUID+397, 1979, 0, 1, 1, -13049.9, -822.5098, 70.34951, 3.142013, 0, 0, 0, 1, 120, 255, 1), -- Campfire (Area: Ruins of Zul'Mamwe)
(@OGUID+398, 204247, 0, 1, 1, -13063.5, -799.5399, 71.30369, 4.66003, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Ruins of Zul'Mamwe)
(@OGUID+399, 204247, 0, 1, 1, -13063.27, -825.3976, 71.31988, 4.66003, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Ruins of Zul'Mamwe)
(@OGUID+400, 1622, 0, 1, 1, -13050.1, -852.458, 71.2668, 0, 0, 0, 0, 1, 120, 255, 1), -- Bruiseweed (Area: Ruins of Zul'Mamwe)
(@OGUID+401, 204247, 0, 1, 1, -13058.98, -848.566, 71.26678, 4.66003, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Ruins of Zul'Mamwe)
(@OGUID+402, 1734, 0, 1, 1, -13100.3, -634.418, 83.1338, 4.206246, 0, 0, 0, 1, 120, 255, 1), -- Gold Vein (Area: Ruins of Zul'Mamwe)
(@OGUID+403, 204247, 0, 1, 1, -13084.33, -611.816, 55.1013, 5.201083, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Ruins of Zul'Mamwe)
(@OGUID+404, 1735, 0, 1, 1, -13143.95, -571.9913, 8.249102, 0, 0, 0, 0, 1, 120, 255, 1); -- Iron Deposit (Area: Ruins of Zul'Mamwe)

UPDATE `creature_template` SET `minlevel`=25, `maxlevel`=26, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=671; -- Bloodscalp Headhunter
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33555200 WHERE `entry`=42772; -- Zuuldaian Fetish
UPDATE `creature_template` SET `minlevel`=25, `maxlevel`=26, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=597; -- Bloodscalp Berserker
UPDATE `creature_template` SET `minlevel`=26, `maxlevel`=27, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=699; -- Bloodscalp Beastmaster
UPDATE `creature_template` SET `minlevel`=26, `maxlevel`=27, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=588; -- Bloodscalp Scout
UPDATE `creature_template` SET `minlevel`=26, `maxlevel`=27, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=701; -- Bloodscalp Mystic
UPDATE `creature_template` SET `faction_A`=188, `faction_H`=188, `speed_walk`=0.5714286, `speed_run`=0.4, `baseattacktime`=2000, `rangeattacktime`=2000 WHERE `entry`=50479; -- Lizard Hatchling
UPDATE `creature_template` SET `minlevel`=27, `maxlevel`=27, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=1300, `rangeattacktime`=2000, `unit_flags`=32768, `dynamicflags`=0, `VehicleId`=921 WHERE `entry`=1061; -- Gan'zulah
UPDATE `creature_template` SET `minlevel`=26, `maxlevel`=27, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=595; -- Bloodscalp Hunter
UPDATE `creature_template` SET `minlevel`=27, `maxlevel`=27, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=1062; -- Nezzliok the Dire
UPDATE `creature_template` SET `faction_A`=190, `faction_H`=190, `speed_walk`=0.8571429, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=50487; -- Forest Spiderling
UPDATE `creature_template` SET `minlevel`=28, `maxlevel`=29, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=1094; -- Venture Co. Miner
UPDATE `creature_template` SET `minlevel`=28, `maxlevel`=29, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=1097; -- Venture Co. Mechanic
UPDATE `creature_template` SET `minlevel`=25, `maxlevel`=26, `speed_walk`=1.428571, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=736; -- Panther
UPDATE `creature_template` SET `minlevel`=28, `maxlevel`=29, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=1096; -- Venture Co. Geologist
UPDATE `creature_template` SET `faction_A`=188, `faction_H`=188, `speed_walk`=0.8571429, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=49722; -- Tree Python
UPDATE `creature_template` SET `minlevel`=25, `maxlevel`=26, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=1150; -- River Crocolisk
UPDATE `creature_template` SET `minlevel`=24, `maxlevel`=25, `speed_walk`=1.428571, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=681; -- Young Stranglethorn Tiger
UPDATE `creature_template` SET `minlevel`=25, `maxlevel`=27, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=905; -- Sharptooth Frenzy
UPDATE `creature_template` SET `minlevel`=24 WHERE `entry`=688; -- Stone Maw Basilisk
UPDATE `creature_template` SET `minlevel`=26, `maxlevel`=27, `faction_A`=188, `faction_H`=188, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=43050; -- Vale Howler
UPDATE `creature_template` SET `minlevel`=24, `maxlevel`=25, `speed_walk`=1.428571, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=683; -- Young Panther
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=42616; -- Spanks
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=9600; -- Parrot
UPDATE `creature_template` SET `faction_A`=188, `faction_H`=188, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000 WHERE `entry`=49928; -- Crimson Moth
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=12, `faction_H`=12, `npcflag`=8192, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=512 WHERE `entry`=43045; -- James Stillair
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=1422; -- Corporal Sethman
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=469; -- Lieutenant Doren
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=770; -- Corporal Kaleb
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=739; -- Brother Nimetz
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=733; -- Sergeant Yohwa
UPDATE `creature_template` SET `npcflag`=640, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=734; -- Corporal Bluth
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `speed_walk`=1.428571, `speed_run`=1, `rangeattacktime`=2000, `unit_flags`=32768, `dynamicflags`=0 WHERE `entry`=754; -- Rebel Watchman
UPDATE `creature_template` SET `minlevel`=23, `dynamicflags`=0 WHERE `entry`=212; -- Splinter Fist Warrior
UPDATE `creature_template` SET `maxlevel`=22 WHERE `entry`=889; -- Splinter Fist Ogre
UPDATE `creature_template` SET `minlevel`=24, `maxlevel`=25, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=940; -- Kurzen Medicine Man
UPDATE `creature_template` SET `minlevel`=24, `maxlevel`=25, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=937; -- Kurzen Jungle Fighter
UPDATE `creature_template` SET `minlevel`=24, `maxlevel`=25, `speed_walk`=0.5714286, `speed_run`=0.5, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=938; -- Kurzen Commando
UPDATE `creature_template` SET `minlevel`=24, `maxlevel`=25, `speed_walk`=1.428571, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=4 WHERE `entry`=977; -- Kurzen War Panther
UPDATE `creature_template` SET `minlevel`=24, `maxlevel`=25, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=943; -- Kurzen Wrangler
UPDATE `creature_template` SET `minlevel`=25, `maxlevel`=25, `speed_walk`=1.428571, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=976; -- Kurzen War Tiger
UPDATE `creature_template` SET `minlevel`=25, `maxlevel`=26, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=941; -- Kurzen Headshrinker
UPDATE `creature_template` SET `minlevel`=25, `maxlevel`=26, `speed_walk`=1.142857, `speed_run`=1.111112, `rangeattacktime`=2000, `unit_flags`=32768, `dynamicflags`=0 WHERE `entry`=689; -- Crystal Spine Basilisk
UPDATE `creature_template` SET `minlevel`=25, `maxlevel`=26, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=939; -- Kurzen Elite
UPDATE `creature_template` SET `minlevel`=25, `maxlevel`=26, `speed_walk`=1.428571, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=682; -- Stranglethorn Tiger
UPDATE `creature_template` SET `minlevel`=25, `maxlevel`=25, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=942; -- Kurzen Witch Doctor
UPDATE `creature_template` SET `minlevel`=26, `maxlevel`=26, `faction_A`=46, `faction_H`=46, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000 WHERE `entry`=43911; -- Chief Gaulus
UPDATE `creature_template` SET `minlevel`=26, `maxlevel`=26, `faction_A`=46, `faction_H`=46, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=4 WHERE `entry`=43910; -- Chief Anders
UPDATE `creature_template` SET `minlevel`=25, `maxlevel`=26, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=978; -- Kurzen Subchief
UPDATE `creature_template` SET `minlevel`=25, `maxlevel`=26, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=979; -- Kurzen Shadow Hunter
UPDATE `creature_template` SET `minlevel`=26, `maxlevel`=26, `faction_A`=46, `faction_H`=46, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=2 WHERE `entry`=43913; -- Chief Miranda
UPDATE `creature_template` SET `minlevel`=26, `maxlevel`=26, `faction_A`=46, `faction_H`=46, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000 WHERE `entry`=43912; -- Chief Esquivel
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=2, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=716; -- Barnil Stonepot
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=1806, `faction_H`=1806, `speed_walk`=1.428571, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=43049; -- Nesingwary Hired Gun
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=718; -- Sir S. J. Erlgadin
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=717; -- Ajeck Rouack
UPDATE `creature_template` SET `minlevel`=25, `maxlevel`=26, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=660; -- Bloodscalp Witch Doctor
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33555200 WHERE `entry`=43977; -- Tkashi Fetish
UPDATE `creature_template` SET `minlevel`=25, `maxlevel`=26, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=702; -- Bloodscalp Scavenger
UPDATE `creature_template` SET `npcflag`=3, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=773; -- Krazek
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2483; -- Jaquilina Dramet
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=715; -- Hemet Nesingwary Jr.
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2495; -- Drizzlik
UPDATE `creature_template` SET `minlevel`=24, `maxlevel`=25, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=685; -- Stranglethorn Raptor
UPDATE `creature_template` SET `minlevel`=28, `maxlevel`=28, `faction_A`=189, `faction_H`=189, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=2, `unit_flags`=64 WHERE `entry`=51663; -- Pogeyan
UPDATE `creature_template` SET `minlevel`=26, `maxlevel`=27, `speed_walk`=1.428571, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=1085; -- Elder Stranglethorn Tiger
UPDATE `creature_template` SET `minlevel`=26, `maxlevel`=27, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=1152; -- Snapjaw Crocolisk
UPDATE `creature_template` SET `minlevel`=25, `maxlevel`=26, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=4461; -- Murkgill Warrior
UPDATE `creature_template` SET `minlevel`=28, `maxlevel`=28, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=729; -- Sin'Dall
UPDATE `creature_template` SET `minlevel`=25, `maxlevel`=26, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=697; -- Bloodscalp Shaman
UPDATE `creature_template` SET `minlevel`=25, `maxlevel`=26, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=587; -- Bloodscalp Warrior
UPDATE `creature_template` SET `minlevel`=25, `maxlevel`=26, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=4457; -- Murkgill Forager
UPDATE `creature_template` SET `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=768 WHERE `entry`=43003; -- Venture Co. Sawblade
UPDATE `creature_template` SET `minlevel`=28, `maxlevel`=29, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=921; -- Venture Co. Lumberjack
UPDATE `creature_template` SET `minlevel`=28, `maxlevel`=29, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=4260; -- Venture Co. Shredder
UPDATE `creature_template` SET `minlevel`=28, `maxlevel`=28, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=4723; -- Foreman Cozzle
UPDATE `creature_template` SET `minlevel`=25, `maxlevel`=26, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=686; -- Lashtail Raptor
UPDATE `creature_template` SET `minlevel`=25, `maxlevel`=26, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=4458; -- Murkgill Hunter
UPDATE `creature_template` SET `minlevel`=25, `maxlevel`=26, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=694; -- Bloodscalp Axe Thrower
UPDATE `creature_template` SET `minlevel`=25, `maxlevel`=26, `speed_walk`=1.289683, `speed_run`=1, `rangeattacktime`=2000, `unit_class`=2, `unit_flags`=32768, `dynamicflags`=0 WHERE `entry`=691; -- Lesser Water Elemental
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33555200 WHERE `entry`=42762; -- Mandokir Skull Pile Bunny
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=3300; -- Adder
UPDATE `creature_template` SET `minlevel`=27, `maxlevel`=27, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=11383; -- High Priestess Hai'watna
UPDATE `creature_template` SET `minlevel`=28, `maxlevel`=28, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=1095; -- Venture Co. Workboss
UPDATE `creature_template` SET `minlevel`=25, `maxlevel`=26, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=877; -- Saltscale Forager
UPDATE `creature_template` SET `faction_A`=48, `faction_H`=48, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000 WHERE `entry`=42620; -- Lashtail Egg
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=126, `faction_H`=126, `npcflag`=8193, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=512 WHERE `entry`=43052; -- Raskha
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `faction_A`=126, `faction_H`=126, `npcflag`=640, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=512, `dynamicflags`=4 WHERE `entry`=44183; -- Durango
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `faction_A`=126, `faction_H`=126, `npcflag`=3, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=8, `unit_flags`=512 WHERE `entry`=42812; -- Priestess Hu'rala
UPDATE `creature_template` SET `minlevel`=80, `maxlevel`=80, `faction_A`=126, `faction_H`=126, `npcflag`=3, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=2, `unit_flags`=512 WHERE `entry`=42811; -- Surkhan
UPDATE `creature_template` SET `minlevel`=26, `maxlevel`=27, `speed_walk`=0.5714286, `speed_run`=0.5, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=684; -- Shadowmaw Panther
UPDATE `creature_template` SET `npcflag`=0, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=7802; -- Galvan the Ancient
UPDATE `creature_template` SET `minlevel`=31, `maxlevel`=32, `faction_A`=15, `faction_H`=15, `speed_walk`=0.8571429, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33555200 WHERE `entry`=43351; -- Gurubashi Batling
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `faction_A`=126, `faction_H`=126, `npcflag`=3200, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=512 WHERE `entry`=44187; -- Pechanga
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `faction_A`=126, `faction_H`=126, `npcflag`=128, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=512 WHERE `entry`=44186; -- Morango
UPDATE `creature_template` SET `minlevel`=38, `maxlevel`=38, `faction_A`=126, `faction_H`=126, `npcflag`=3, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=512 WHERE `entry`=42813; -- Kil'karil
UPDATE `creature_template` SET `minlevel`=25, `maxlevel`=25, `faction_A`=2159, `faction_H`=2159, `npcflag`=3, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=512, `dynamicflags`=4 WHERE `entry`=42814; -- Skeezy Whillzap
UPDATE `creature_template` SET `minlevel`=25, `maxlevel`=26, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=879; -- Saltscale Hunter
UPDATE `creature_template` SET `minlevel`=25, `maxlevel`=26, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=871; -- Saltscale Warrior
UPDATE `creature_template` SET `minlevel`=25, `maxlevel`=26, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=873; -- Saltscale Oracle
UPDATE `creature_template` SET `minlevel`=26, `maxlevel`=27, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=4460; -- Murkgill Lord
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2519; -- Kin'weelay
UPDATE `creature_template` SET `minlevel`=27, `maxlevel`=28, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=709; -- Mosh'Ogg Warmonger
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=877, `faction_H`=877, `speed_walk`=1.428571, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768, `dynamicflags`=12 WHERE `entry`=51521; -- Bambala Headhunter
UPDATE `creature_template` SET `minlevel`=26, `maxlevel`=27, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=687; -- Jungle Stalker
UPDATE `creature_template` SET `minlevel`=27, `maxlevel`=28, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2635; -- Elder Saltwater Crocolisk
UPDATE `creature_template` SET `minlevel`=28, `maxlevel`=29, `speed_walk`=1.142857, `speed_run`=1.6, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=680; -- Mosh'Ogg Lord
UPDATE `creature_template` SET `minlevel`=29, `maxlevel`=29, `speed_walk`=1.142857, `speed_run`=1.6, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=818; -- Mai'Zoth
UPDATE `creature_template` SET `minlevel`=28, `maxlevel`=29, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=679; -- Mosh'Ogg Shaman
UPDATE `creature_template` SET `minlevel`=28, `maxlevel`=29, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=678; -- Mosh'Ogg Mauler
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `speed_walk`=1.428571, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=1064; -- Grom'gol Grunt
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=1382; -- Mudduk
UPDATE `creature_template` SET `npcflag`=640, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=1149; -- Uthok
UPDATE `creature_template` SET `npcflag`=16, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2856; -- Angrun
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=1146; -- Vharr
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=1381; -- Krakk
UPDATE `creature_template` SET `minlevel`=29, `maxlevel`=29, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=710; -- Mosh'Ogg Spellcrafter
UPDATE `creature_template` SET `minlevel`=26, `maxlevel`=26, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `unit_flags`=32832, `dynamicflags`=0 WHERE `entry`=14487; -- Gluggle
UPDATE `creature_template` SET `maxlevel`=47, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=5434; -- Coral Shark
UPDATE `creature_template` SET `gossip_menu_id`=12742, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=7853; -- Scooty
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=1, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=1404; -- Kragg
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=1, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=3624; -- Zudd
UPDATE `creature_template` SET `npcflag`=3, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2497; -- Nimboya
UPDATE `creature_template` SET `npcflag`=17, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=1385; -- Brawn
UPDATE `creature_template` SET `maxlevel`=30, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `unit_flags`=0, `dynamicflags`=0 WHERE `entry`=17094; -- Nemeth Hawkeye
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=1147; -- Hragran
UPDATE `creature_template` SET `gossip_menu_id`=0, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `unit_flags`=0, `dynamicflags`=0 WHERE `entry`=12137; -- Squibby Overspeck
UPDATE `creature_template` SET `npcflag`=3, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2464; -- Commander Aggro'gosh
UPDATE `creature_template` SET `npcflag`=3, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2465; -- Far Seer Mok'thardin
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=7485; -- Nargatt
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=1148; -- Nerrist
UPDATE `creature_template` SET `minlevel`=25, `maxlevel`=26, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=1144; -- Mosh'Ogg Witch Doctor
UPDATE `creature_template` SET `minlevel`=25, `maxlevel`=26, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=1142; -- Mosh'Ogg Brute
UPDATE `creature_template` SET `minlevel`=28, `maxlevel`=28, `speed_walk`=1.428571, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=728; -- Bhag'thera
UPDATE `creature_template` SET `minlevel`=26, `maxlevel`=27, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=667; -- Skullsplitter Warrior
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=85, `maxlevel`=85, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=1387; -- Thysta
UPDATE `creature_template` SET `npcflag`=129, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=16094; -- Durik
UPDATE `creature_template` SET `gossip_menu_id`=0, `speed_walk`=1.428571, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=3149; -- Nez'raz
UPDATE `creature_template` SET `gossip_menu_id`=0, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=5814; -- Innkeeper Thulbek
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=85, `faction_H`=85, `speed_walk`=1.428571, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768, `dynamicflags`=12 WHERE `entry`=51917; -- Grom'gol Grunt
UPDATE `creature_template` SET `gossip_menu_id`=0, `dynamicflags`=0 WHERE `entry`=24924; -- Sky-Captain Bomblast
UPDATE `creature_template` SET `gossip_menu_id`=0, `dynamicflags`=0 WHERE `entry`=24930; -- Crewman Gazzlegear
UPDATE `creature_template` SET `gossip_menu_id`=0, `dynamicflags`=0 WHERE `entry`=24929; -- Crewman Crosswire
UPDATE `creature_template` SET `gossip_menu_id`=0, `dynamicflags`=0 WHERE `entry`=24931; -- Crewman Fastwrench
UPDATE `creature_template` SET `gossip_menu_id`=0, `dynamicflags`=0 WHERE `entry`=24926; -- Chief Officer Brassbolt
UPDATE `creature_template` SET `gossip_menu_id`=0, `dynamicflags`=0 WHERE `entry`=25081; -- Grunt Ounda
UPDATE `creature_template` SET `gossip_menu_id`=0, `dynamicflags`=0 WHERE `entry`=24927; -- Navigator Sparksizzle
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=25080; -- Grunt Umgor
UPDATE `creature_template` SET `minlevel`=26, `maxlevel`=27, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=696; -- Skullsplitter Axe Thrower
UPDATE `creature_template` SET `minlevel`=26, `maxlevel`=27, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=780; -- Skullsplitter Mystic
UPDATE `creature_template` SET `minlevel`=28, `maxlevel`=28, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=730; -- Tethis
UPDATE `creature_template` SET `minlevel`=29, `maxlevel`=29, `speed_walk`=1.428571, `speed_run`=1, `rangeattacktime`=2000, `unit_flags`=0, `dynamicflags`=0 WHERE `entry`=731; -- King Bangalash
UPDATE `creature_template` SET `npcflag`=18, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=7871; -- Se'Jib
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=2687; -- Gnaz Blunderflame
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=8679; -- Knaz Blunderflame
UPDATE `creature_template` SET `minlevel`=29, `maxlevel`=30, `speed_walk`=1.142857, `speed_run`=1.111112, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=690; -- Cold Eye Basilisk
UPDATE `creature_template` SET `minlevel`=29, `maxlevel`=30, `speed_walk`=0.5714286, `speed_run`=0.5, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=1713; -- Elder Shadowmaw Panther
UPDATE `creature_template` SET `minlevel`=28, `maxlevel`=29, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=669; -- Skullsplitter Hunter
UPDATE `creature_template` SET `minlevel`=28, `maxlevel`=29, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=782; -- Skullsplitter Scout
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33555200 WHERE `entry`=52908; -- Generic Bunny
UPDATE `creature_template` SET `minlevel`=28, `maxlevel`=29, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=670; -- Skullsplitter Witch Doctor
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `faction_A`=64, `faction_H`=64, `npcflag`=2, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=44043; -- Kinnel
UPDATE `creature_template` SET `gossip_menu_id`=11792, `minlevel`=35, `maxlevel`=35, `faction_A`=2164, `faction_H`=2164, `npcflag`=3, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=8, `unit_flags`=32768 WHERE `entry`=44018; -- Wulfred Harrys
UPDATE `creature_template` SET `gossip_menu_id`=11785, `minlevel`=35, `maxlevel`=35, `faction_A`=1694, `faction_H`=1694, `npcflag`=3, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=8, `unit_flags`=32768 WHERE `entry`=44017; -- Priestess Thaalia
UPDATE `creature_template` SET `gossip_menu_id`=342, `minlevel`=35, `maxlevel`=35, `faction_A`=1078, `faction_H`=1078, `npcflag`=66179, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=8, `unit_flags`=32768 WHERE `entry`=44019; -- Livingston Marshal
UPDATE `creature_template` SET `gossip_menu_id`=11787, `minlevel`=80, `maxlevel`=80, `faction_A`=1574, `faction_H`=1574, `npcflag`=3, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=2, `unit_flags`=512 WHERE `entry`=44021; -- Ghaliri
UPDATE `creature_template` SET `gossip_menu_id`=11791, `minlevel`=85, `maxlevel`=85, `faction_A`=12, `faction_H`=12, `npcflag`=8193, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=512 WHERE `entry`=43042; -- Robert Rhodes
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `faction_A`=12, `faction_H`=12, `npcflag`=128, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=512 WHERE `entry`=44181; -- Daniel Roberts
UPDATE `creature_template` SET `minlevel`=28, `maxlevel`=29, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=674; -- Venture Co. Strip Miner
UPDATE `creature_template` SET `minlevel`=28, `maxlevel`=28, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=677; -- Venture Co. Tinkerer
UPDATE `creature_template` SET `minlevel`=28, `maxlevel`=29, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=784; -- Skullsplitter Beastmaster
UPDATE `creature_template` SET `minlevel`=28, `maxlevel`=29, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=781; -- Skullsplitter Headhunter
UPDATE `creature_template` SET `minlevel`=28, `maxlevel`=29, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=672; -- Skullsplitter Spiritchaser
UPDATE `creature_template` SET `minlevel`=2, `maxlevel`=2, `npcflag`=2, `speed_walk`=1.428571, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=52374; -- Panther Cub
UPDATE `creature_template` SET `minlevel`=28, `maxlevel`=29, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=675; -- Venture Co. Foreman
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `speed_walk`=1.428571, `speed_run`=1, `rangeattacktime`=2000, `unit_flags`=67108864, `dynamicflags`=4 WHERE `entry`=772; -- Stranglethorn Tigress
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `speed_walk`=1.142857, `speed_run`=1.111112, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=1550; -- Thrashtail Basilisk
UPDATE `creature_template` SET `minlevel`=28, `maxlevel`=29, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=676; -- Venture Co. Surveyor
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `faction_A`=49, `faction_H`=49, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000 WHERE `entry`=44113; -- Ironjaw Behemoth
UPDATE `creature_template` SET `minlevel`=28, `maxlevel`=29, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=783; -- Skullsplitter Berserker
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `npcflag`=0, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `unit_flags`=33024, `dynamicflags`=0 WHERE `entry`=2530; -- Yenniku
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=1059; -- Ana'thek the Cruel
UPDATE `creature_template` SET `minlevel`=29, `maxlevel`=29, `faction_A`=30, `faction_H`=30, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=2, `unit_flags`=32768 WHERE `entry`=42858; -- Braddok
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `speed_walk`=1.142857, `speed_run`=1.111112, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=1551; -- Ironjaw Basilisk

DELETE FROM `creature_template_addon` WHERE `entry` IN (671, 42772, 42772, 597, 699, 671, 588, 701, 671, 588, 588, 15475, 50479, 1061, 595, 595, 588, 701, 588, 701, 1062, 595, 588, 699, 701, 588, 50487, 595, 701, 595, 701, 701, 15475, 1094, 50487, 699, 701, 588, 701, 701, 588, 588, 701, 588, 701, 595, 1094, 1097, 736, 15475, 1094, 50487, 1094, 1094, 1094, 1094, 1096, 736, 736, 50487, 1094, 1094, 1094, 49722, 736, 736, 1094, 1096, 736, 736, 50479, 736, 736, 736, 6827, 6827, 6827, 1150, 681, 681, 681, 6827, 1150, 681, 905, 49722, 49722, 736, 905, 681, 681, 688, 6827, 1150, 1150, 1150, 43050, 49722, 6827, 1150, 1150, 688, 688, 683, 688, 688, 1150, 683, 42616, 6827, 6827, 683, 9600, 49928, 50487, 683, 49722, 49722, 9600, 683, 49928, 50487, 43045, 1422, 469, 770, 739, 733, 734, 50479, 754, 45613, 45613, 45613, 300, 212, 889, 940, 49722, 683, 683, 50487, 683, 50487, 940, 940, 937, 940, 940, 940, 937, 937, 940, 937, 50487, 937, 938, 977, 943, 976, 43050, 941, 938, 689, 940, 689, 943, 977, 689, 943, 977, 50487, 49928, 941, 939, 943, 736, 682, 50487, 689, 50479, 940, 940, 50487, 938, 938, 941, 942, 15475, 939, 942, 689, 942, 939, 938, 938, 941, 689, 43911, 939, 942, 689, 938, 43910, 941, 939, 49928, 689, 939, 939, 942, 942, 942, 978, 978, 978, 979, 978, 689, 43913, 689, 32520, 32520, 32520, 32520, 979, 978, 43912, 978, 979, 689, 689, 689, 689, 689, 689, 940, 49928, 689, 689, 689, 50487, 689, 43050, 689, 15475, 689, 940, 937, 940, 940, 937, 15475, 683, 683, 683, 683, 49722, 49928, 683, 683, 1150, 682, 1150, 6827, 6827, 716, 43049, 718, 717, 50487, 50479, 43049, 6827, 6827, 681, 701, 588, 588, 6827, 6827, 6827, 6827, 597, 597, 671, 42772, 42772, 671, 6827, 660, 660, 660, 42772, 6827, 6827, 42772, 597, 671, 660, 597, 660, 671, 597, 671, 42772, 42772, 660, 597, 42772, 6827, 701, 50479, 699, 701, 701, 701, 701, 701, 588, 588, 597, 597, 42772, 701, 595, 701, 588, 588, 701, 595, 588, 588, 701, 701, 595, 701, 595, 595, 701, 701, 50487, 701, 701, 595, 588, 49722, 701, 595, 588, 588, 595, 595, 15475, 595, 588, 699, 595, 588, 699, 50487, 736, 49722, 736, 736, 43977, 43977, 43977, 702, 736, 702, 50487, 50479, 681, 9600, 1150, 50479, 43049, 43049, 773, 2483, 715, 2495, 43049, 43049, 681, 681, 1150, 6827, 49928, 6827, 683, 683, 50487, 683, 683, 683, 683, 50487, 940, 940, 940, 32520, 32520, 32520, 32520, 937, 689, 689, 689, 682, 49722, 937, 937, 940, 937, 940, 940, 683, 50479, 683, 683, 683, 683, 683, 6827, 6827, 1150, 6827, 6827, 1150, 681, 49928, 1150, 681, 49928, 681, 681, 43977, 15475, 50487, 43977, 702, 702, 702, 701, 6827, 6827, 6827, 6827, 6827, 660, 6827, 597, 42772, 701, 671, 42772, 595, 701, 699, 595, 736, 736, 736, 736, 43977, 49722, 43977, 43977, 702, 702, 49928, 43977, 43977, 43977, 43977, 702, 43977, 702, 43977, 43977, 702, 43977, 702, 9600, 681, 43977, 681, 681, 50487, 49722, 681, 681, 681, 683, 683, 15475, 937, 940, 940, 937, 937, 689, 15475, 49928, 43050, 682, 50479, 683, 9600, 1150, 1150, 6827, 681, 681, 43977, 43977, 43977, 736, 50487, 685, 685, 660, 42772, 42772, 660, 597, 42772, 42772, 6827, 42772, 6827, 6827, 6827, 6827, 6827, 6827, 32520, 32520, 32520, 32520, 597, 42772, 6827, 42772, 660, 42772, 660, 6827, 660, 685, 50479, 685, 685, 685, 685, 685, 685, 736, 15475, 736, 736, 51663, 736, 1085, 43977, 43977, 50479, 1085, 702, 43977, 43977, 702, 43977, 15475, 702, 702, 43977, 43977, 702, 43977, 43977, 681, 49928, 50479, 683, 683, 683, 683, 683, 6827, 6827, 1150, 1152, 49722, 6827, 6827, 49928, 1152, 6827, 50479, 682, 682, 683, 682, 937, 937, 682, 1096, 682, 49722, 682, 49722, 940, 49928, 682, 15475, 15475, 50487, 689, 689, 689, 41178, 682, 682, 683, 6827, 6827, 6827, 685, 685, 685, 49722, 43050, 685, 685, 685, 50479, 685, 15475, 736, 736, 49722, 685, 15475, 49722, 736, 49722, 736, 1085, 43050, 43977, 43977, 702, 15475, 43977, 43977, 702, 702, 43977, 43977, 49928, 43977, 43977, 43977, 702, 9600, 50487, 681, 681, 681, 1152, 681, 6827, 6827, 6827, 1152, 6827, 1152, 1096, 50479, 1096, 43050, 682, 15475, 15475, 15475, 689, 49928, 50487, 49928, 682, 682, 682, 682, 1096, 50479, 1096, 50487, 49722, 1096, 1096, 905, 1152, 1152, 6827, 6827, 9600, 681, 1152, 9600, 681, 9600, 43050, 681, 681, 681, 681, 681, 681, 702, 43977, 50479, 43977, 49928, 702, 4461, 702, 1085, 49722, 9600, 729, 1085, 32520, 32520, 32520, 32520, 1085, 49928, 697, 697, 587, 587, 685, 685, 685, 689, 689, 689, 689, 689, 6827, 689, 689, 689, 6827, 6827, 6827, 6827, 689, 689, 49722, 1085, 1085, 4457, 681, 49722, 9600, 1096, 50479, 1096, 50487, 1096, 43003, 43003, 43003, 43003, 1096, 921, 4260, 6827, 4723, 1096, 1096, 1096, 921, 1097, 1096, 905, 1152, 1097, 1096, 1097, 6827, 1152, 49928, 50479, 681, 686, 49928, 681, 1085, 1085, 43050, 1085, 4458, 50479, 4461, 4461, 587, 1085, 587, 694, 697, 587, 50487, 587, 6827, 6827, 6827, 6827, 32520, 32520, 32520, 32520, 6827, 6827, 691, 691, 694, 6827, 6827, 42762, 694, 694, 6827, 50479, 9600, 1085, 1085, 49722, 1085, 4457, 49722, 4457, 50479, 49722, 1096, 1096, 50487, 49722, 49722, 50487, 3300, 3300, 2914, 3300, 4953, 4953, 4953, 50487, 50487, 50487, 3300, 2914, 4953, 50479, 50479, 15475, 15475, 15475, 50479, 50487, 49722, 49722, 49722, 50487, 49722, 49722, 50487, 49722, 49722, 50487, 49722, 50487, 50479, 15475, 15475, 15475, 50479, 50479, 49722, 2914, 4953, 4953, 2914, 4953, 4953, 4953, 50487, 4953, 2914, 4953, 2914, 3300, 2914, 4953, 3300, 4953, 4953, 15475, 3300, 3300, 4953, 4953, 2914, 2914, 2914, 3300, 2914, 2914, 2914, 2914, 2914, 3300, 4953, 32520, 32520, 32520, 32520, 11383, 50479, 1096, 1096, 15475, 1096, 4260, 1096, 1095, 1097, 50487, 686, 686, 4457, 1085, 4461, 15475, 686, 587, 694, 697, 50479, 6827, 6827, 691, 6827, 691, 6827, 691, 6827, 691, 691, 691, 691, 691, 6827, 877, 697, 42620, 686, 9600, 9600, 50479, 15475, 4458, 4461, 4458, 4458, 4458, 4457, 49722, 4461, 4461, 9600, 15475, 49928, 686, 50487, 1152, 905, 1152, 6827, 1152, 1152, 6827, 6827, 1096, 49722, 1096, 1096, 1096, 15475, 1096, 50487, 50479, 50479, 1096, 1096, 1096, 43052, 44183, 42812, 42811, 49722, 49722, 684, 50479, 49722, 43050, 684, 7802, 49722, 50479, 43351, 50479, 50479, 44187, 44186, 42813, 42814, 4260, 50479, 32520, 32520, 32520, 32520, 50487, 1096, 1096, 1152, 6827, 6827, 686, 9600, 4458, 9600, 42620, 42620, 879, 871, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 691, 6827, 6827, 691, 691, 691, 873, 879, 873, 877, 871, 879, 873, 873, 873, 879, 879, 873, 879, 877, 879, 877, 6827, 6827, 6827, 49722, 42620, 42620, 42620, 686, 686, 42620, 42620, 42620, 686, 15475, 42620, 42620, 42620, 42620, 42620, 42620, 42620, 42620, 42620, 42620, 42620, 42620, 42620, 42620, 42620, 42620, 42620, 42620, 42620, 42620, 686, 42620, 42620, 42620, 42620, 42620, 42620, 42620, 15475, 686, 49722, 49722, 686, 686, 686, 49722, 4458, 4460, 4458, 4460, 4460, 4458, 4461, 49722, 4461, 4461, 42173, 49928, 4461, 4458, 49722, 4457, 50479, 15475, 686, 686, 49928, 49928, 6827, 1152, 1096, 49722, 1096, 1096, 1096, 1096, 49928, 1096, 50479, 2519, 49722, 50479, 684, 43351, 15475, 49722, 15475, 50479, 50487, 32520, 32520, 32520, 32520, 50487, 43351, 43351, 43351, 15475, 43351, 43351, 43351, 49722, 15475, 15475, 15475, 15475, 15475, 684, 709, 1096, 51521, 684, 1096, 50487, 15475, 50487, 9600, 42173, 687, 49722, 6827, 49722, 2635, 686, 49722, 686, 49928, 50487, 686, 871, 877, 879, 879, 877, 877, 871, 877, 6827, 15475, 49928, 686, 686, 49722, 43050, 686, 686, 905, 2635, 687, 1152, 6827, 1152, 687, 50487, 50479, 32520, 32520, 32520, 32520, 15475, 50487, 50487, 50479, 50479, 50479, 43351, 43351, 50479, 43351, 4076, 48972, 680, 4076, 818, 679, 678, 4076, 4076, 678, 679, 678, 679, 48972, 48972, 679, 679, 679, 709, 50479, 709, 709, 15475, 709, 43050, 49928, 49928, 687, 687, 43050, 687, 687, 687, 50487, 687, 1152, 686, 15475, 686, 877, 877, 877, 871, 9600, 6827, 1064, 1064, 1064, 1064, 1382, 1149, 2856, 1146, 1381, 9600, 9600, 9600, 49722, 686, 686, 49722, 686, 49928, 6827, 50479, 686, 6827, 6827, 2635, 687, 687, 49722, 50479, 687, 9600, 687, 49928, 15475, 49928, 678, 684, 4076, 4076, 679, 48972, 678, 48972, 48972, 818, 50479, 49722, 49722, 50487, 32520, 32520, 32520, 32520, 4076, 4076, 48972, 710, 709, 709, 50479, 684, 684, 684, 687, 684, 687, 687, 49928, 49722, 687, 687, 43050, 2635, 14487, 1064, 1064, 877, 5434, 871, 877, 879, 871, 871, 879, 879, 871, 877, 6827, 7853, 1404, 1064, 1064, 3624, 1064, 1064, 45423, 41178, 2497, 1385, 17094, 1147, 12137, 1064, 2464, 1064, 2465, 7485, 1064, 1064, 1064, 50487, 1148, 43050, 49928, 50479, 1144, 1142, 1144, 2635, 50487, 1152, 6827, 6827, 687, 15475, 687, 728, 709, 709, 709, 710, 679, 710, 49928, 709, 50479, 32520, 32520, 32520, 32520, 15475, 667, 49928, 2635, 687, 6827, 6827, 15475, 2635, 687, 905, 49722, 6827, 1142, 1142, 1142, 1142, 50479, 1142, 2635, 49928, 1144, 1142, 1144, 1144, 1144, 1144, 1144, 1142, 9600, 15475, 15475, 50479, 49928, 49928, 1387, 16096, 16096, 16094, 16096, 3149, 5814, 6827, 51917, 871, 877, 877, 5434, 24924, 24930, 24929, 24931, 24926, 25081, 24927, 25080, 24934, 25075, 24935, 6827, 6827, 6827, 6827, 6827, 50479, 6827, 49722, 1142, 1144, 1142, 1142, 1144, 1144, 6827, 905, 6827, 6827, 2635, 1152, 6827, 1085, 43050, 687, 9600, 687, 687, 687, 50487, 687, 687, 696, 9600, 50487, 696, 696, 49928, 696, 780, 780, 687, 49928, 709, 709, 49722, 49722, 709, 48972, 15475, 4076, 709, 678, 678, 680, 680, 687, 50479, 730, 9600, 9600, 50487, 780, 696, 49722, 696, 687, 667, 696, 687, 49928, 32520, 32520, 32520, 32520, 50487, 9600, 696, 15475, 667, 49722, 50479, 1085, 2635, 1085, 731, 1085, 6827, 15475, 1152, 6827, 9600, 905, 49928, 24930, 25075, 24924, 24926, 25080, 25081, 24935, 24927, 24931, 24934, 24929, 1085, 7871, 1085, 1085, 780, 49722, 696, 780, 687, 50479, 687, 780, 687, 9600, 687, 50487, 15475, 15475, 2687, 8679, 49928, 9600, 687, 15475, 49722, 687, 687, 49722, 43050, 687, 687, 687, 687, 696, 49928, 687, 15475, 696, 50487, 50479, 696, 696, 696, 780, 50487, 667, 667, 667, 780, 696, 696, 49722, 9600, 1085, 50487, 49928, 1085, 6827, 6827, 9600, 6827, 6827, 6827, 6827, 32520, 32520, 32520, 32520, 690, 690, 690, 49928, 49722, 50479, 684, 9600, 9600, 1085, 684, 49928, 49928, 49722, 50487, 43050, 780, 687, 49722, 687, 687, 50479, 15475, 687, 687, 6827, 690, 6827, 6827, 690, 15475, 1713, 50479, 32520, 32520, 32520, 32520, 1085, 15475, 684, 1085, 669, 687, 782, 669, 687, 49928, 669, 687, 9600, 42173, 52908, 669, 670, 9600, 669, 670, 670, 670, 50487, 9600, 782, 782, 669, 670, 782, 50479, 44043, 44018, 44017, 50479, 44019, 44021, 43042, 44181, 50479, 49928, 49928, 49928, 15475, 50479, 6827, 690, 6827, 690, 50479, 50487, 49722, 9600, 1713, 1713, 1713, 50487, 1713, 1713, 50487, 674, 677, 674, 669, 669, 669, 9600, 782, 782, 49722, 670, 669, 15475, 669, 32520, 32520, 32520, 32520, 670, 730, 782, 49722, 49722, 15475, 669, 6827, 690, 690, 674, 674, 9600, 669, 784, 784, 670, 670, 782, 669, 782, 669, 669, 669, 670, 782, 784, 669, 781, 50487, 782, 672, 670, 15475, 52374, 781, 32520, 32520, 32520, 32520, 669, 782, 782, 669, 669, 669, 669, 50479, 674, 675, 674, 49928, 15475, 1713, 15475, 1713, 1713, 15475, 15475, 6827, 6827, 772, 1713, 1713, 49722, 49928, 1713, 1713, 15475, 50479, 1713, 1713, 49722, 15475, 15475, 49928, 49722, 9600, 1550, 9600, 674, 676, 49928, 674, 675, 676, 675, 674, 44113, 674, 782, 783, 2530, 1059, 672, 782, 15475, 783, 672, 781, 672, 783, 672, 781, 672, 783, 42858, 672, 44113, 48972, 1551, 44113);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(1059, 0, 0x0, 0x1, ''), -- Ana'thek the Cruel
(1061, 0, 0x0, 0x1, ''), -- Gan'zulah
(1062, 0, 0x0, 0x1, '45104'), -- Nezzliok the Dire - Shadow Channelling
(1064, 0, 0x0, 0x101, '5301'), -- Grom'gol Grunt - Defensive State (DND)
(1085, 0, 0x0, 0x1, ''), -- Elder Stranglethorn Tiger
(1094, 0, 0x0, 0x1, ''), -- Venture Co. Miner
(1095, 0, 0x0, 0x1, ''), -- Venture Co. Workboss
(1096, 0, 0x0, 0x1, ''), -- Venture Co. Geologist
(1097, 0, 0x0, 0x1, ''), -- Venture Co. Mechanic
(11383, 0, 0x0, 0x1, '79452'), -- High Priestess Hai'watna - Shadow Channeling w/Bubble
(1142, 0, 0x0, 0x1, ''), -- Mosh'Ogg Brute
(1144, 0, 0x0, 0x1, ''), -- Mosh'Ogg Witch Doctor
(1146, 0, 0x0, 0x101, ''), -- Vharr
(1147, 0, 0x0, 0x101, ''), -- Hragran
(1148, 0, 0x0, 0x101, ''), -- Nerrist
(1149, 0, 0x0, 0x101, ''), -- Uthok
(1150, 0, 0x0, 0x1, ''), -- River Crocolisk
(1152, 0, 0x0, 0x1, ''), -- Snapjaw Crocolisk
(12137, 0, 0x0, 0x101, ''), -- Squibby Overspeck
(1381, 0, 0x0, 0x101, ''), -- Krakk
(1382, 0, 0x0, 0x101, ''), -- Mudduk
(1385, 0, 0x0, 0x101, ''), -- Brawn
(1387, 0, 0x0, 0x101, ''), -- Thysta
(1404, 0, 0x0, 0x102, ''), -- Kragg
(1422, 0, 0x0, 0x101, ''), -- Corporal Sethman
(14487, 0, 0x0, 0x1, ''), -- Gluggle
(15475, 0, 0x0, 0x1, ''), -- Beetle
(1550, 0, 0x0, 0x1, ''), -- Thrashtail Basilisk
(1551, 0, 0x0, 0x1, ''), -- Ironjaw Basilisk
(16094, 0, 0x0, 0x101, ''), -- Durik
(16096, 0, 0x0, 0x101, ''), -- Steamwheedle Bruiser
(17094, 0, 0x0, 0x101, ''), -- Nemeth Hawkeye
(1713, 0, 0x20000, 0x1, '22766'), -- Elder Shadowmaw Panther - Sneak
(212, 0, 0x0, 0x1, ''), -- Splinter Fist Warrior
(2464, 0, 0x0, 0x101, ''), -- Commander Aggro'gosh
(2465, 0, 0x0, 0x101, ''), -- Far Seer Mok'thardin
(2483, 0, 0x0, 0x1, ''), -- Jaquilina Dramet
(24924, 0, 0x0, 0x0, ''), -- Sky-Captain Bomblast
(24926, 0, 0x0, 0x0, ''), -- Chief Officer Brassbolt
(24927, 0, 0x0, 0x1, ''), -- Navigator Sparksizzle
(24929, 0, 0x0, 0x1, ''), -- Crewman Crosswire
(24930, 0, 0x0, 0x1, ''), -- Crewman Gazzlegear
(24931, 0, 0x0, 0x1, ''), -- Crewman Fastwrench
(24934, 0, 0x0, 0x1, ''), -- Snack-O-Matic IV
(24935, 0, 0x0, 0x1, ''), -- Vend-O-Tron D-Luxe
(2495, 0, 0x0, 0x1, ''), -- Drizzlik
(2497, 0, 0x10000, 0x101, '49415'), -- Nimboya - Generic Quest Invisibility 2
(25075, 0, 0x0, 0x1, ''), -- Zeppelin Controls
(25080, 0, 0x0, 0x1, ''), -- Grunt Umgor
(25081, 0, 0x0, 0x1, ''), -- Grunt Ounda
(2519, 0, 0x0, 0x101, ''), -- Kin'weelay
(2530, 0, 0x0, 0x1, ''), -- Yenniku
(2635, 0, 0x0, 0x1, ''), -- Elder Saltwater Crocolisk
(2687, 0, 0x0, 0x1, ''), -- Gnaz Blunderflame
(2856, 0, 0x0, 0x101, ''), -- Angrun
(2914, 0, 0x0, 0x1, ''), -- Snake
(300, 0, 0x0, 0x1, ''), -- Zzarc' Vul
(3149, 0, 0x0, 0x101, ''), -- Nez'raz
(32520, 0, 0x0, 0x1, ''), -- Totally Generic Bunny (All Phase)
(3300, 0, 0x0, 0x1, ''), -- Adder
(3624, 0, 0x0, 0x101, ''), -- Zudd
(4076, 0, 0x0, 0x1, ''), -- Roach
(41178, 0, 0x0, 0x1, '82358 77064'), -- Northwatch Tower Stalker - Generic Quest Invisibility 6, Tower Beam
-- (41178, 0, 0x10000, 0x1, '49415 77064'), -- Northwatch Tower Stalker - Generic Quest Invisibility 2, Tower Beam
(42173, 0, 0x0, 0x1, ''), -- The Undershell Tentacle Flavor
(4260, 0, 0x0, 0x1, ''), -- Venture Co. Shredder
(42616, 0, 0x0, 0x1, ''), -- Spanks
(42620, 0, 0x0, 0x1, ''), -- Lashtail Egg
(42762, 0, 0x0, 0x1, ''), -- Mandokir Skull Pile Bunny
(42772, 0, 0x0, 0x1, ''), -- Zuuldaian Fetish
(42811, 0, 0x0, 0x101, ''), -- Surkhan
(42812, 0, 0x0, 0x101, ''), -- Priestess Hu'rala
(42813, 0, 0x0, 0x101, '80274'), -- Kil'karil - Cosmetic - Troll Talking
(42814, 0, 0x0, 0x101, ''), -- Skeezy Whillzap
(42858, 0, 0x0, 0x1, '79892'), -- Braddok - Water Shield
(43003, 0, 0x0, 0x1, ''), -- Venture Co. Sawblade
(43042, 0, 0x0, 0x101, ''), -- Robert Rhodes
(43045, 0, 0x0, 0x101, ''), -- James Stillair
(43049, 0, 0x0, 0x2, '18950'), -- Nesingwary Hired Gun - Invisibility and Stealth Detection
(43050, 0, 0x0, 0x1, ''), -- Vale Howler
(43052, 0, 0x0, 0x101, ''), -- Raskha
(43351, 0, 0x3000000, 0x1, ''), -- Gurubashi Batling
(43910, 0, 0x0, 0x1, ''), -- Chief Anders
(43911, 0, 0x0, 0x1, ''), -- Chief Gaulus
(43912, 0, 0x0, 0x1, ''), -- Chief Esquivel
(43913, 0, 0x0, 0x1, '13864'), -- Chief Miranda - Power Word: Fortitude
(43977, 0, 0x0, 0x1, ''), -- Tkashi Fetish
(44017, 0, 0x0, 0x101, ''), -- Priestess Thaalia
(44018, 0, 0x0, 0x101, ''), -- Wulfred Harrys
(44019, 0, 0x0, 0x101, ''), -- Livingston Marshal
(44021, 0, 0x1, 0x101, ''), -- Ghaliri
(44043, 0, 0x0, 0x101, ''), -- Kinnel
(44113, 0, 0x0, 0x1, ''), -- Ironjaw Behemoth
(44181, 0, 0x0, 0x101, ''), -- Daniel Roberts
(44183, 0, 0x0, 0x101, ''), -- Durango
(44186, 0, 0x0, 0x101, ''), -- Morango
(44187, 0, 0x0, 0x101, ''), -- Pechanga
(4457, 0, 0x0, 0x1, ''), -- Murkgill Forager
(4458, 0, 0x0, 0x1, ''), -- Murkgill Hunter
-- (4460, 0, 0x0, 0x1, ''), -- Murkgill Lord
(4460, 0, 0x0, 0x1, '12544'), -- Murkgill Lord - Frost Armor
(4461, 0, 0x0, 0x1, ''), -- Murkgill Warrior
(45423, 0, 0x10000, 0x1, '49415'), -- Fiona's Caravan - Generic Quest Invisibility 2
(45613, 0, 0x0, 0x1, '29266'), -- Half-Eaten Coalpelt Bear - Permanent Feign Death
(469, 0, 0x0, 0x101, ''), -- Lieutenant Doren
(4723, 0, 0x0, 0x1, ''), -- Foreman Cozzle
(48972, 0, 0x0, 0x1, ''), -- Long-tailed Mole
(4953, 0, 0x0, 0x1, ''), -- Moccasin
(49722, 0, 0x0, 0x1, ''), -- Tree Python
(49928, 0, 0x3000000, 0x1, ''), -- Crimson Moth
(50479, 0, 0x0, 0x1, ''), -- Lizard Hatchling
(50487, 0, 0x0, 0x1, ''), -- Forest Spiderling
(51521, 0, 0x0, 0x101, ''), -- Bambala Headhunter
(51663, 0, 0x0, 0x1, '77617'), -- Pogeyan - Burning Desire
(51917, 0, 0x0, 0x101, '5301'), -- Grom'gol Grunt - Defensive State (DND)
(52374, 0, 0x10000, 0x1, '98363'), -- Panther Cub - Has Quest Invis 15
(52908, 0, 0x0, 0x1, ''), -- Generic Bunny
(5434, 0, 0x0, 0x1, ''), -- Coral Shark
(5814, 0, 0x0, 0x101, ''), -- Innkeeper Thulbek
(587, 0, 0x0, 0x1, ''), -- Bloodscalp Warrior
(588, 0, 0x0, 0x1, ''), -- Bloodscalp Scout
-- (588, 0, 0x1, 0x1, ''), -- Bloodscalp Scout
(595, 0, 0x0, 0x1, ''), -- Bloodscalp Hunter
-- (595, 0, 0x1, 0x1, ''), -- Bloodscalp Hunter
(597, 0, 0x0, 0x1, ''), -- Bloodscalp Berserker
-- (597, 0, 0x8, 0x1, ''), -- Bloodscalp Berserker
(660, 0, 0x0, 0x1, ''), -- Bloodscalp Witch Doctor
(667, 0, 0x0, 0x1, ''), -- Skullsplitter Warrior
(669, 0, 0x0, 0x1, ''), -- Skullsplitter Hunter
-- (669, 0, 0x0, 0x1, '78677'), -- Skullsplitter Hunter - Cosmetic - Sleep Zzz Breakable
(670, 0, 0x0, 0x1, ''), -- Skullsplitter Witch Doctor
-- (670, 0, 0x0, 0x1, '78677'), -- Skullsplitter Witch Doctor - Cosmetic - Sleep Zzz Breakable
(671, 0, 0x0, 0x1, ''), -- Bloodscalp Headhunter
-- (671, 0, 0x8, 0x1, ''), -- Bloodscalp Headhunter
(672, 0, 0x0, 0x1, ''), -- Skullsplitter Spiritchaser
(674, 0, 0x0, 0x1, ''), -- Venture Co. Strip Miner
(675, 0, 0x0, 0x1, ''), -- Venture Co. Foreman
(676, 0, 0x0, 0x1, ''), -- Venture Co. Surveyor
(677, 0, 0x0, 0x1, ''), -- Venture Co. Tinkerer
(678, 0, 0x0, 0x1, ''), -- Mosh'Ogg Mauler
-- (679, 0, 0x0, 0x1, ''), -- Mosh'Ogg Shaman
-- (679, 0, 0x0, 0x1, '78677'), -- Mosh'Ogg Shaman - Cosmetic - Sleep Zzz Breakable
(680, 0, 0x0, 0x1, ''), -- Mosh'Ogg Lord
-- (680, 0, 0x8, 0x1, ''), -- Mosh'Ogg Lord
(681, 0, 0x0, 0x1, ''), -- Young Stranglethorn Tiger
(682, 0, 0x0, 0x1, ''), -- Stranglethorn Tiger
(6827, 0, 0x0, 0x1, ''), -- Crab
(683, 0, 0x0, 0x1, ''), -- Young Panther
(684, 0, 0x20000, 0x1, '22766'), -- Shadowmaw Panther - Sneak
(685, 0, 0x0, 0x1, ''), -- Stranglethorn Raptor
(686, 0, 0x0, 0x1, ''), -- Lashtail Raptor
(687, 0, 0x0, 0x1, ''), -- Jungle Stalker
(688, 0, 0x0, 0x1, ''), -- Stone Maw Basilisk
(689, 0, 0x0, 0x1, ''), -- Crystal Spine Basilisk
(690, 0, 0x0, 0x1, ''), -- Cold Eye Basilisk
(691, 0, 0x0, 0x1, ''), -- Lesser Water Elemental
(694, 0, 0x0, 0x1, ''), -- Bloodscalp Axe Thrower
(696, 0, 0x0, 0x1, ''), -- Skullsplitter Axe Thrower
(697, 0, 0x0, 0x1, '8788'), -- Bloodscalp Shaman - Lightning Shield
(699, 0, 0x0, 0x1, ''), -- Bloodscalp Beastmaster
(701, 0, 0x0, 0x1, ''), -- Bloodscalp Mystic
-- (701, 0, 0x1, 0x1, ''), -- Bloodscalp Mystic
(702, 0, 0x0, 0x1, ''), -- Bloodscalp Scavenger
-- (709, 0, 0x0, 0x1, ''), -- Mosh'Ogg Warmonger
(710, 0, 0x0, 0x1, '12544'), -- Mosh'Ogg Spellcrafter - Frost Armor
-- (710, 0, 0x0, 0x1, '78677 12544'), -- Mosh'Ogg Spellcrafter - Cosmetic - Sleep Zzz Breakable, Frost Armor
(715, 0, 0x0, 0x2, ''), -- Hemet Nesingwary Jr.
(716, 0, 0x0, 0x1, ''), -- Barnil Stonepot
(717, 0, 0x0, 0x1, ''), -- Ajeck Rouack
(718, 0, 0x0, 0x1, ''), -- Sir S. J. Erlgadin
(728, 0, 0x0, 0x1, ''), -- Bhag'thera
(729, 0, 0x0, 0x1, ''), -- Sin'Dall
(730, 0, 0x0, 0x1, ''), -- Tethis
(731, 0, 0x0, 0x1, ''), -- King Bangalash
(733, 0, 0x0, 0x101, ''), -- Sergeant Yohwa
(734, 0, 0x0, 0x101, ''), -- Corporal Bluth
(736, 0, 0x0, 0x1, ''), -- Panther
(739, 0, 0x0, 0x101, ''), -- Brother Nimetz
(7485, 0, 0x0, 0x101, ''), -- Nargatt
(754, 0, 0x0, 0x101, '18950'), -- Rebel Watchman - Invisibility and Stealth Detection
(770, 0, 0x0, 0x101, ''), -- Corporal Kaleb
(772, 0, 0x0, 0x1, ''), -- Stranglethorn Tigress
(773, 0, 0x0, 0x1, ''), -- Krazek
(780, 0, 0x0, 0x1, ''), -- Skullsplitter Mystic
(7802, 0, 0x0, 0x1, ''), -- Galvan the Ancient
(781, 0, 0x0, 0x1, ''), -- Skullsplitter Headhunter
-- (781, 0, 0x0, 0x1, '78677'), -- Skullsplitter Headhunter - Cosmetic - Sleep Zzz Breakable
(782, 0, 0x0, 0x1, ''), -- Skullsplitter Scout
(783, 0, 0x0, 0x1, ''), -- Skullsplitter Berserker
-- (783, 0, 0x0, 0x1, '78677'), -- Skullsplitter Berserker - Cosmetic - Sleep Zzz Breakable
(784, 0, 0x0, 0x1, ''), -- Skullsplitter Beastmaster
(7853, 0, 0x0, 0x1, ''), -- Scooty
(7871, 0, 0x0, 0x101, ''), -- Se'Jib
(818, 0, 0x0, 0x1, '12544'), -- Mai'Zoth - Frost Armor
(8679, 0, 0x0, 0x1, ''), -- Knaz Blunderflame
(871, 0, 0x0, 0x1, ''), -- Saltscale Warrior
(873, 0, 0x0, 0x1, ''), -- Saltscale Oracle
(877, 0, 0x0, 0x1, ''), -- Saltscale Forager
(879, 0, 0x0, 0x1, ''), -- Saltscale Hunter
(889, 0, 0x0, 0x1, ''), -- Splinter Fist Ogre
(905, 0, 0x0, 0x1, ''), -- Sharptooth Frenzy
(921, 0, 0x0, 0x1, ''), -- Venture Co. Lumberjack
(937, 0, 0x0, 0x1, ''), -- Kurzen Jungle Fighter
(938, 0, 0x0, 0x1, '22766'), -- Kurzen Commando - Sneak
-- (938, 0, 0x20000, 0x1, '22766'), -- Kurzen Commando - Sneak
(939, 0, 0x0, 0x1, ''), -- Kurzen Elite
(940, 0, 0x0, 0x1, ''), -- Kurzen Medicine Man
-- (940, 0, 0x0, 0x1, '12550'), -- Kurzen Medicine Man - Lightning Shield
(941, 0, 0x0, 0x1, ''), -- Kurzen Headshrinker
(942, 0, 0x0, 0x1, ''), -- Kurzen Witch Doctor
(943, 0, 0x0, 0x1, ''), -- Kurzen Wrangler
(9600, 0, 0x3000000, 0x1, ''), -- Parrot
(976, 0, 0x0, 0x1, ''), -- Kurzen War Tiger
(977, 0, 0x0, 0x1, ''), -- Kurzen War Panther
(978, 0, 0x0, 0x1, ''), -- Kurzen Subchief
(979, 0, 0x0, 0x1, ''); -- Kurzen Shadow Hunter

UPDATE `creature_model_info` SET `bounding_radius`=0.6804661, `combat_reach`=1.283898 WHERE `modelid`=598;
UPDATE `creature_model_info` SET `gender`=0 WHERE `modelid`=616;
UPDATE `creature_model_info` SET `combat_reach`=2.125 WHERE `modelid`=833;
UPDATE `creature_model_info` SET `bounding_radius`=0.6858559, `combat_reach`=1.294068 WHERE `modelid`=2437;
UPDATE `creature_model_info` SET `bounding_radius`=0.21, `combat_reach`=0.3 WHERE `modelid`=4343;
UPDATE `creature_model_info` SET `bounding_radius`=0.1822966, `combat_reach`=0.7812712 WHERE `modelid`=4734;
UPDATE `creature_model_info` SET `bounding_radius`=0.7, `combat_reach`=0.875 WHERE `modelid`=5560;
UPDATE `creature_model_info` SET `gender`=0 WHERE `modelid`=6704;
UPDATE `creature_model_info` SET `gender`=0 WHERE `modelid`=11546;
UPDATE `creature_model_info` SET `gender`=0 WHERE `modelid`=11569;
UPDATE `creature_model_info` SET `bounding_radius`=5, `combat_reach`=10 WHERE `modelid`=21171;
UPDATE `creature_model_info` SET `gender`=0 WHERE `modelid`=22530;
UPDATE `creature_model_info` SET `bounding_radius`=0.372, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=32976;
UPDATE `creature_model_info` SET `bounding_radius`=0.372, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=32977;
UPDATE `creature_model_info` SET `bounding_radius`=0.3978, `combat_reach`=1.95, `gender`=0 WHERE `modelid`=33076;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=33077;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=33078;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=33079;
UPDATE `creature_model_info` SET `bounding_radius`=2, `combat_reach`=2 WHERE `modelid`=33170;
UPDATE `creature_model_info` SET `bounding_radius`=0.4875, `combat_reach`=1.625 WHERE `modelid`=33178;
UPDATE `creature_model_info` SET `bounding_radius`=0.4875, `combat_reach`=1.625 WHERE `modelid`=33179;
UPDATE `creature_model_info` SET `bounding_radius`=0.3366, `combat_reach`=1.65, `gender`=0 WHERE `modelid`=33187;
UPDATE `creature_model_info` SET `bounding_radius`=0.3672, `combat_reach`=1.8, `gender`=0 WHERE `modelid`=33554;
UPDATE `creature_model_info` SET `bounding_radius`=0.3672, `combat_reach`=1.8, `gender`=0 WHERE `modelid`=33555;
UPDATE `creature_model_info` SET `bounding_radius`=0.3672, `combat_reach`=1.8, `gender`=0 WHERE `modelid`=33556;
UPDATE `creature_model_info` SET `bounding_radius`=0.208, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=33557;
UPDATE `creature_model_info` SET `bounding_radius`=1, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=33624;
UPDATE `creature_model_info` SET `bounding_radius`=0.347222, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=33625;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=33626;
UPDATE `creature_model_info` SET `bounding_radius`=0.3519, `combat_reach`=1.725, `gender`=0 WHERE `modelid`=33635;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=33703;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=33706;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=33707;
UPDATE `creature_model_info` SET `bounding_radius`=0.031, `combat_reach`=0.1 WHERE `modelid`=36599;
UPDATE `creature_model_info` SET `bounding_radius`=0.0875, `combat_reach`=0.25 WHERE `modelid`=36671;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=37479;
UPDATE `creature_model_info` SET `bounding_radius`=0.9, `combat_reach`=3 WHERE `modelid`=37615;
UPDATE `creature_model_info` SET `bounding_radius`=0.1155, `combat_reach`=0.495, `gender`=0 WHERE `modelid`=37814;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=38741;

SET @CGUID := 216324;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1896;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 671, 0, 1, 1, -11602.67, 859.7221, 0.9239143, 2.879793, 120, 0, 0), -- Bloodscalp Headhunter (Area: 0)
(@CGUID+1, 42772, 0, 1, 1, -11628.51, 956.6302, 1.728555, 0, 120, 0, 0), -- Zuuldaian Fetish (Area: 0)
(@CGUID+2, 42772, 0, 1, 1, -11629.27, 972.316, 3.745356, 0, 120, 0, 0), -- Zuuldaian Fetish (Area: 0)
(@CGUID+3, 597, 0, 1, 1, -11630.01, 960.7283, 1.795656, 3.415417, 120, 0, 0), -- Bloodscalp Berserker (Area: 0) (possible waypoints or random movement)
(@CGUID+4, 699, 0, 1, 1, -11524.86, 781.6334, 41.77489, 2.617994, 120, 0, 0), -- Bloodscalp Beastmaster (Area: 0)
(@CGUID+5, 671, 0, 1, 1, -11535.56, 769.6934, 41.61354, 0, 120, 0, 0), -- Bloodscalp Headhunter (Area: 0)
(@CGUID+6, 588, 0, 1, 1, -11567.68, 762.4396, 39.85727, 5.796578, 120, 0, 0), -- Bloodscalp Scout (Area: 0) (possible waypoints or random movement)
(@CGUID+7, 701, 0, 1, 1, -11595.53, 771.3519, 40.53947, 5.566111, 120, 0, 0), -- Bloodscalp Mystic (Area: 0) (possible waypoints or random movement)
(@CGUID+8, 671, 0, 1, 1, -11606.55, 851.8827, 0.9234163, 2.373648, 120, 0, 0), -- Bloodscalp Headhunter (Area: 0)
(@CGUID+9, 588, 0, 1, 1, -11637.61, 756.7841, 42.36133, 5.759586, 120, 0, 0), -- Bloodscalp Scout (Area: 0)
(@CGUID+10, 588, 0, 1, 1, -11629.25, 729.6035, 39.85727, 5.880171, 120, 0, 0), -- Bloodscalp Scout (Area: 0) (possible waypoints or random movement)
(@CGUID+11, 15475, 0, 1, 1, -11539.05, 723.4808, 59.86422, 4.688262, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+12, 50479, 0, 1, 1, -11566.75, 688.0537, 60.65625, 5.005717, 120, 0, 0), -- Lizard Hatchling (Area: 0)
(@CGUID+13, 1061, 0, 1, 1, -11514.4, 724.968, 61.10433, 3.036873, 120, 0, 0), -- Gan'zulah (Area: 0)
(@CGUID+14, 595, 0, 1, 1, -11559.04, 721.9739, 59.53963, 2.888274, 120, 0, 0), -- Bloodscalp Hunter (Area: 0) (possible waypoints or random movement)
(@CGUID+15, 595, 0, 1, 1, -11540.39, 726.6337, 59.41463, 5.985601, 120, 0, 0), -- Bloodscalp Hunter (Area: 0) (possible waypoints or random movement)
(@CGUID+16, 588, 0, 1, 1, -11567.5, 702.2327, 59.62654, 3.090396, 120, 0, 0), -- Bloodscalp Scout (Area: 0) (possible waypoints or random movement)
(@CGUID+17, 701, 0, 1, 1, -11573.67, 722.7139, 59.41463, 5.411662, 120, 0, 0), -- Bloodscalp Mystic (Area: 0) (possible waypoints or random movement)
(@CGUID+18, 588, 0, 1, 1, -11593, 694.3489, 60.33185, 5.45998, 120, 0, 0), -- Bloodscalp Scout (Area: 0)
(@CGUID+19, 701, 0, 1, 1, -11615.26, 646.3204, 59.70089, 0.3183077, 120, 0, 0), -- Bloodscalp Mystic (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+20, 1062, 0, 1, 1, -11550.4, 646.9739, 59.87382, 5.410521, 120, 0, 0), -- Nezzliok the Dire (Area: Ruins of Zul'Kunda)
(@CGUID+21, 595, 0, 1, 1, -11551.27, 593.9149, 50.57862, 3.438299, 120, 0, 0), -- Bloodscalp Hunter (Area: Ruins of Zul'Kunda)
(@CGUID+22, 588, 0, 1, 1, -11572.07, 622.8707, 50.45079, 4.253144, 120, 0, 0), -- Bloodscalp Scout (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+23, 699, 0, 1, 1, -11553.85, 608.4011, 50.72782, 4.18879, 120, 0, 0), -- Bloodscalp Beastmaster (Area: Ruins of Zul'Kunda)
(@CGUID+24, 701, 0, 1, 1, -11567.83, 643.4797, 59.76847, 5.305302, 120, 0, 0), -- Bloodscalp Mystic (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+25, 588, 0, 1, 1, -11577.76, 596.4119, 50.19259, 2.849241, 120, 0, 0), -- Bloodscalp Scout (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+26, 50487, 0, 1, 1, -11562.86, 601.0839, 50.50365, 3.679736, 120, 0, 0), -- Forest Spiderling (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+27, 595, 0, 1, 1, -11555.28, 655.3802, 59.5542, 3.716096, 120, 0, 0), -- Bloodscalp Hunter (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+28, 701, 0, 1, 1, -11630.78, 708.8342, 41.52448, 1.52391, 120, 0, 0), -- Bloodscalp Mystic (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+29, 595, 0, 1, 1, -11622.69, 706.1389, 42.02267, 1.679177, 120, 0, 0), -- Bloodscalp Hunter (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+30, 701, 0, 1, 1, -11585.34, 686.0035, 59.46642, 0, 120, 0, 0), -- Bloodscalp Mystic (Area: Ruins of Zul'Kunda)
(@CGUID+31, 701, 0, 1, 1, -11581.64, 681.9219, 59.46517, 0.9075712, 120, 0, 0), -- Bloodscalp Mystic (Area: Ruins of Zul'Kunda)
(@CGUID+32, 15475, 0, 1, 1, -11568.03, 675.9907, 59.57257, 2.31754, 120, 0, 0), -- Beetle (Area: Ruins of Zul'Kunda)
(@CGUID+33, 1094, 0, 1, 1, -11507.78, 490.3651, 65.02111, 1.343904, 120, 0, 0), -- Venture Co. Miner (Area: Ruins of Zul'Kunda)
(@CGUID+34, 50487, 0, 1, 1, -11622.41, 587.8435, 49.30033, 4.924548, 120, 0, 0), -- Forest Spiderling (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+35, 699, 0, 1, 1, -11620.41, 619.1915, 50.44647, 4.39823, 120, 0, 0), -- Bloodscalp Beastmaster (Area: Ruins of Zul'Kunda)
(@CGUID+36, 701, 0, 1, 1, -11615.35, 584.0786, 49.1182, 2.277344, 120, 0, 0), -- Bloodscalp Mystic (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+37, 588, 0, 1, 1, -11548.81, 555.0526, 50.64857, 0.991155, 120, 0, 0), -- Bloodscalp Scout (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+38, 701, 0, 1, 1, -11565.43, 552.5097, 50.20375, 3.813893, 120, 0, 0), -- Bloodscalp Mystic (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+39, 701, 0, 1, 1, -11527.53, 567.6489, 49.92492, 2.470657, 120, 0, 0), -- Bloodscalp Mystic (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+40, 588, 0, 1, 1, -11598.32, 553.6576, 50.09653, 4.518959, 120, 0, 0), -- Bloodscalp Scout (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+41, 588, 0, 1, 1, -11556.5, 585.7674, 50.5502, 1.48353, 120, 0, 0), -- Bloodscalp Scout (Area: Ruins of Zul'Kunda)
(@CGUID+42, 701, 0, 1, 1, -11527.4, 554.5139, 49.60728, 2.537022, 120, 0, 0), -- Bloodscalp Mystic (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+43, 588, 0, 1, 1, -11596.15, 579.9208, 50.58273, 2.835728, 120, 0, 0), -- Bloodscalp Scout (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+44, 701, 0, 1, 1, -11591.92, 600.7833, 50.57579, 5.492148, 120, 0, 0), -- Bloodscalp Mystic (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+45, 595, 0, 1, 1, -11549.49, 571.4219, 50.62865, 0.7300758, 120, 0, 0), -- Bloodscalp Hunter (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+46, 1094, 0, 1, 1, -11506.3, 392.2031, 51.17077, 5.88176, 120, 0, 0), -- Venture Co. Miner (Area: Ruins of Zul'Kunda)
(@CGUID+47, 1097, 0, 1, 1, -11517.31, 394.0665, 45.52039, 0, 120, 0, 0), -- Venture Co. Mechanic (Area: Ruins of Zul'Kunda)
(@CGUID+48, 736, 0, 1, 1, -11608.09, 424.5279, 46.36213, 0.7339388, 120, 0, 0), -- Panther (Area: Ruins of Zul'Kunda)
(@CGUID+49, 15475, 0, 1, 1, -11629.11, 485.4522, 43.09161, 3.438238, 120, 0, 0), -- Beetle (Area: Ruins of Zul'Kunda)
(@CGUID+50, 1094, 0, 1, 1, -11498.91, 446.1476, 65.99905, 2.391101, 120, 0, 0), -- Venture Co. Miner (Area: Ruins of Zul'Kunda)
(@CGUID+51, 50487, 0, 1, 1, -11535.72, 448.7115, 48.10001, 1.427795, 120, 0, 0), -- Forest Spiderling (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+52, 1094, 0, 1, 1, -11485.58, 483.841, 71.34506, 5.916666, 120, 0, 0), -- Venture Co. Miner (Area: Ruins of Zul'Kunda)
(@CGUID+53, 1094, 0, 1, 1, -11510.83, 419.911, 58.05862, 5.759586, 120, 0, 0), -- Venture Co. Miner (Area: Ruins of Zul'Kunda)
(@CGUID+54, 1094, 0, 1, 1, -11495.66, 456.9499, 68.92679, 6.038839, 120, 0, 0), -- Venture Co. Miner (Area: Ruins of Zul'Kunda)
(@CGUID+55, 1094, 0, 1, 1, -11530.64, 437.2806, 50.14584, 0.6806784, 120, 0, 0), -- Venture Co. Miner (Area: Ruins of Zul'Kunda)
(@CGUID+56, 1096, 0, 1, 1, -11512.85, 458.6945, 65.0366, 6.248279, 120, 0, 0), -- Venture Co. Geologist (Area: Ruins of Zul'Kunda)
(@CGUID+57, 736, 0, 1, 1, -11579.62, 452.8979, 46.29382, 1.425863, 120, 0, 0), -- Panther (Area: Ruins of Zul'Kunda)
(@CGUID+58, 736, 0, 1, 1, -11553.72, 416.9312, 47.1652, 5.78898, 120, 0, 0), -- Panther (Area: Ruins of Zul'Kunda)
(@CGUID+59, 50487, 0, 1, 1, -11592.16, 415.7157, 47.00907, 3.352005, 120, 0, 0), -- Forest Spiderling (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+60, 1094, 0, 1, 1, -11483.52, 348.7992, 54.37907, 0.5934119, 120, 0, 0), -- Venture Co. Miner (Area: 0)
(@CGUID+61, 1094, 0, 1, 1, -11482.36, 374.0417, 62.00036, 0, 120, 0, 0), -- Venture Co. Miner (Area: 0)
(@CGUID+62, 1094, 0, 1, 1, -11494.08, 375.0428, 57.68612, 1.692969, 120, 0, 0), -- Venture Co. Miner (Area: 0)
(@CGUID+63, 49722, 0, 1, 1, -11563.22, 350.8202, 44.38778, 4.79845, 120, 0, 0), -- Tree Python (Area: 0) (possible waypoints or random movement)
(@CGUID+64, 736, 0, 1, 1, -11544.55, 359.2448, 45.09675, 1.40124, 120, 0, 0), -- Panther (Area: 0)
(@CGUID+65, 736, 0, 1, 1, -11588.12, 387.1769, 47.08119, 2.320196, 120, 0, 0), -- Panther (Area: 0)
(@CGUID+66, 1094, 0, 1, 1, -11460.29, 385.7852, 77.52937, 1.204277, 120, 0, 0), -- Venture Co. Miner (Area: 0)
(@CGUID+67, 1096, 0, 1, 1, -11462.49, 379.4462, 76.22916, 0.6108652, 120, 0, 0), -- Venture Co. Geologist (Area: 0)
(@CGUID+68, 736, 0, 1, 1, -11577.33, 254.7983, 41.01797, 0.8422142, 120, 0, 0), -- Panther (Area: 0)
(@CGUID+69, 736, 0, 1, 1, -11611.76, 346.7894, 46.7875, 5.811838, 120, 0, 0), -- Panther (Area: 0)
(@CGUID+70, 50479, 0, 1, 1, -11564.32, 303.6429, 42.63167, 5.902679, 120, 0, 0), -- Lizard Hatchling (Area: 0)
(@CGUID+71, 736, 0, 1, 1, -11495.3, 319.7517, 41.91449, 6.161655, 120, 0, 0), -- Panther (Area: 0)
(@CGUID+72, 736, 0, 1, 1, -11554.4, 286.9457, 37.84839, 1.632565, 120, 0, 0), -- Panther (Area: 0)
(@CGUID+73, 736, 0, 1, 1, -11588.25, 312.8518, 42.94861, 4.046257, 120, 0, 0), -- Panther (Area: 0)
(@CGUID+74, 6827, 0, 1, 1, -11504.11, 182.4897, 9.818275, 0.6607003, 120, 0, 0), -- Crab (Area: 0)
(@CGUID+75, 6827, 0, 1, 1, -11496.04, 203.2594, 12.41179, 3.209979, 120, 0, 0), -- Crab (Area: 0)
(@CGUID+76, 6827, 0, 1, 1, -11533.74, 152.5105, 10.78011, 2.792655, 120, 0, 0), -- Crab (Area: 0)
(@CGUID+77, 1150, 0, 1, 1, -11489.45, 169.2468, 2.451447, 0.6397349, 120, 0, 0), -- River Crocolisk (Area: 0) (possible waypoints or random movement)
(@CGUID+78, 681, 0, 1, 1, -11548.56, 188.8776, 16.72991, 5.507568, 120, 0, 0), -- Young Stranglethorn Tiger (Area: 0)
(@CGUID+79, 681, 0, 1, 1, -11529.59, 222.7427, 18.17938, 1.755544, 120, 0, 0), -- Young Stranglethorn Tiger (Area: 0)
(@CGUID+80, 681, 0, 1, 1, -11586.86, 183.8523, 18.54315, 1.571628, 120, 0, 0), -- Young Stranglethorn Tiger (Area: 0)
(@CGUID+81, 6827, 0, 1, 1, -11479.37, 245.9319, 15.81092, 1.518202, 120, 0, 0), -- Crab (Area: 0)
(@CGUID+82, 1150, 0, 1, 1, -11548.96, 141.666, 14.09778, 4.712389, 120, 0, 0), -- River Crocolisk (Area: 0) (possible waypoints or random movement)
(@CGUID+83, 681, 0, 1, 1, -11489.62, 256.5922, 18.19507, 1.084249, 120, 0, 0), -- Young Stranglethorn Tiger (Area: 0)
(@CGUID+84, 905, 0, 1, 1, -11467.99, 213.9768, 2.329757, 4.993098, 120, 0, 0), -- Sharptooth Frenzy (Area: 0) (possible waypoints or random movement)
(@CGUID+85, 49722, 0, 1, 1, -11591.09, 206.7873, 16.29782, 2.234494, 120, 0, 0), -- Tree Python (Area: 0) (possible waypoints or random movement)
(@CGUID+86, 49722, 0, 1, 1, -11588.95, 170.5403, 16.83438, 2.114901, 120, 0, 0), -- Tree Python (Area: 0) (possible waypoints or random movement)
(@CGUID+87, 736, 0, 1, 1, -11611.92, 279.7137, 42.8584, 5.54702, 120, 0, 0), -- Panther (Area: 0)
(@CGUID+88, 905, 0, 1, 1, -11543.66, 89.84575, 6.032708, 1.443529, 120, 0, 0), -- Sharptooth Frenzy (Area: 0) (possible waypoints or random movement)
(@CGUID+89, 681, 0, 1, 1, -11586.18, 117.3845, 16.74179, 2.814938, 120, 0, 0), -- Young Stranglethorn Tiger (Area: 0)
(@CGUID+90, 681, 0, 1, 1, -11609.69, 140.7246, 18.2112, 5.717372, 120, 0, 0), -- Young Stranglethorn Tiger (Area: 0)
(@CGUID+91, 688, 0, 1, 1, -11336.31, 262.3123, 31.74685, 5.733232, 120, 0, 0), -- Stone Maw Basilisk (Area: 0)
(@CGUID+92, 6827, 0, 1, 1, -11552.84, 74.92033, 9.571771, 1.278998, 120, 0, 0), -- Crab (Area: 0)
(@CGUID+93, 1150, 0, 1, 1, -11543.76, 52.1782, 7.413713, 2.388633, 120, 0, 0), -- River Crocolisk (Area: 0) (possible waypoints or random movement)
(@CGUID+94, 1150, 0, 1, 1, -11511.95, -54.22854, 14.0021, 0.1274809, 120, 0, 0), -- River Crocolisk (Area: 0) (possible waypoints or random movement)
(@CGUID+95, 1150, 0, 1, 1, -11547.22, -45.59, 3.489298, 0.2896274, 120, 0, 0), -- River Crocolisk (Area: 0) (possible waypoints or random movement)
(@CGUID+96, 43050, 0, 1, 1, -11456.84, -13.36883, 35.87798, 5.205873, 120, 0, 0), -- Vale Howler (Area: 0) (possible waypoints or random movement)
(@CGUID+97, 49722, 0, 1, 1, -11457.55, -14.39748, 36.12428, 6.155358, 120, 0, 0), -- Tree Python (Area: 0) (possible waypoints or random movement)
(@CGUID+98, 6827, 0, 1, 1, -11567.73, 49.0411, 13.75944, 4.930846, 120, 0, 0), -- Crab (Area: 0)
(@CGUID+99, 1150, 0, 1, 1, -11514.85, 17.9375, 12.41371, 2.123602, 120, 0, 0), -- River Crocolisk (Area: 0) (possible waypoints or random movement)
(@CGUID+100, 1150, 0, 1, 1, -11577.14, 47.30235, 15.99503, 4.20505, 120, 0, 0), -- River Crocolisk (Area: 0) (possible waypoints or random movement)
(@CGUID+101, 688, 0, 1, 1, -11453.06, 11.93852, 30.90898, 0.6745067, 120, 0, 0), -- Stone Maw Basilisk (Area: 0)
(@CGUID+102, 688, 0, 1, 1, -11442.24, 66.12042, 39.81523, 4.214837, 120, 0, 0), -- Stone Maw Basilisk (Area: 0)
(@CGUID+103, 683, 0, 1, 1, -11476.87, -90.69453, 33.29296, 5.162937, 120, 0, 0), -- Young Panther (Area: 0)
(@CGUID+104, 688, 0, 1, 1, -11519.86, -112.6109, 32.13092, 1.58497, 120, 0, 0), -- Stone Maw Basilisk (Area: 0)
(@CGUID+105, 688, 0, 1, 1, -11455.75, -59.48993, 43.77291, 0.9905733, 120, 0, 0), -- Stone Maw Basilisk (Area: 0)
(@CGUID+106, 1150, 0, 1, 1, -11581.43, -147.2432, 2.905936, 3.736941, 120, 0, 0), -- River Crocolisk (Area: 0) (possible waypoints or random movement)
(@CGUID+107, 683, 0, 1, 1, -11520.16, -161.7571, 40.97784, 5.306283, 120, 0, 0), -- Young Panther (Area: 0)
(@CGUID+108, 42616, 0, 1, 1, -11559.82, -197.9894, 19.68263, 0.6433511, 120, 0, 0), -- Spanks (Area: 0) (possible waypoints or random movement)
(@CGUID+109, 6827, 0, 1, 1, -11584.59, -89.24535, 13.25794, 0.06838635, 120, 0, 0), -- Crab (Area: 0)
(@CGUID+110, 6827, 0, 1, 1, -11589.29, -104.166, 13.87027, 3.141593, 120, 0, 0), -- Crab (Area: 0)
(@CGUID+111, 683, 0, 1, 1, -11519.83, -295.9036, 39.53231, 3.655103, 120, 0, 0), -- Young Panther (Area: 0)
(@CGUID+112, 9600, 0, 1, 1, -11567.75, -269.9553, 53.38467, 2.463331, 120, 0, 0), -- Parrot (Area: 0)
(@CGUID+113, 49928, 0, 1, 1, -11479.6, -295.6449, 58.27574, 3.15597, 120, 0, 0), -- Crimson Moth (Area: 0)
(@CGUID+114, 50487, 0, 1, 1, -11443.32, -286.0042, 45.26988, 2.567674, 120, 0, 0), -- Forest Spiderling (Area: 0) (possible waypoints or random movement)
(@CGUID+115, 683, 0, 1, 1, -11453.95, -271.9876, 44.53027, 5.486738, 120, 0, 0), -- Young Panther (Area: 0)
(@CGUID+116, 49722, 0, 1, 1, -11460.45, -277.0228, 42.07843, 5.61114, 120, 0, 0), -- Tree Python (Area: 0) (possible waypoints or random movement)
(@CGUID+117, 49722, 0, 1, 1, -11534.7, -236.1237, 28.8212, 6.234301, 120, 0, 0), -- Tree Python (Area: 0) (possible waypoints or random movement)
(@CGUID+118, 9600, 0, 1, 1, -11538.1, -240.1489, 42.92539, 2.630837, 120, 0, 0), -- Parrot (Area: 0)
(@CGUID+119, 683, 0, 1, 1, -11523.69, -354.2069, 37.67531, 1.869922, 120, 0, 0), -- Young Panther (Area: 0)
(@CGUID+120, 49928, 0, 1, 1, -11577.59, -357.7324, 55.32007, 3.871191, 120, 0, 0), -- Crimson Moth (Area: 0)
(@CGUID+121, 50487, 0, 1, 1, -11511.22, -386.5449, 39.44749, 5.961796, 120, 0, 0), -- Forest Spiderling (Area: 0) (possible waypoints or random movement)
(@CGUID+122, 43045, 0, 1, 1, -11340.74, -218.7031, 75.29716, 2.164208, 120, 0, 0), -- James Stillair (Area: Rebel Camp)
(@CGUID+123, 1422, 0, 1, 1, -11312.99, -182.6012, 75.31372, 4.485496, 120, 0, 0), -- Corporal Sethman (Area: Rebel Camp)
(@CGUID+124, 469, 0, 1, 1, -11296.86, -206.6889, 75.98039, 2.775074, 120, 0, 0), -- Lieutenant Doren (Area: Rebel Camp)
(@CGUID+125, 770, 0, 1, 1, -11309.14, -187.4311, 75.64919, 3.787364, 120, 0, 0), -- Corporal Kaleb (Area: Rebel Camp)
(@CGUID+126, 739, 0, 1, 1, -11320.17, -193.3374, 76.22766, 4.991642, 120, 0, 0), -- Brother Nimetz (Area: Rebel Camp)
(@CGUID+127, 733, 0, 1, 1, -11310.41, -205.1148, 75.3625, 2.80998, 120, 0, 0), -- Sergeant Yohwa (Area: Rebel Camp)
(@CGUID+128, 734, 0, 1, 1, -11295.82, -201.3427, 75.78527, 3.630285, 120, 0, 0), -- Corporal Bluth (Area: Rebel Camp)
(@CGUID+129, 50479, 0, 1, 1, -11314.16, -208.959, 75.38038, 2.896173, 120, 0, 0), -- Lizard Hatchling (Area: Rebel Camp)
(@CGUID+130, 754, 0, 1, 1, -11323.98, -213.7835, 76.66516, 5.48404, 120, 0, 0), -- Rebel Watchman (Area: Rebel Camp) (possible waypoints or random movement)
(@CGUID+131, 45613, 0, 1, 1, -11228.77, -182.9635, 4.542427, 1.780236, 120, 0, 0), -- Half-Eaten Coalpelt Bear (Area: Rebel Camp)
(@CGUID+132, 45613, 0, 1, 1, -11238.9, -187.038, 6.173694, 5.550147, 120, 0, 0), -- Half-Eaten Coalpelt Bear (Area: Rebel Camp)
(@CGUID+133, 45613, 0, 1, 1, -11238.2, -171.767, 4.369294, 6.038839, 120, 0, 0), -- Half-Eaten Coalpelt Bear (Area: Rebel Camp)
(@CGUID+134, 300, 0, 1, 1, -11234.87, -189.2639, 5.411788, 1.37881, 120, 0, 0), -- Zzarc' Vul (Area: Rebel Camp)
(@CGUID+135, 212, 0, 1, 1, -11239.15, -160.1469, 7.951818, 6.21564, 120, 0, 0), -- Splinter Fist Warrior (Area: Rebel Camp)
(@CGUID+136, 889, 0, 1, 1, -11216.3, -170.2532, 3.380227, 4.94531, 120, 0, 0), -- Splinter Fist Ogre (Area: Rebel Camp)
(@CGUID+137, 940, 0, 1, 1, -11471.45, -577.9728, 35.92732, 3.021691, 120, 0, 0), -- Kurzen Medicine Man (Area: 0)
(@CGUID+138, 49722, 0, 1, 1, -11506.21, -468.2383, 41.87556, 5.004055, 120, 0, 0), -- Tree Python (Area: 0) (possible waypoints or random movement)
(@CGUID+139, 683, 0, 1, 1, -11585.68, -411.5556, 21.40384, 1.645208, 120, 0, 0), -- Young Panther (Area: 0)
(@CGUID+140, 683, 0, 1, 1, -11519.67, -420.5522, 36.57943, 4.769366, 120, 0, 0), -- Young Panther (Area: 0)
(@CGUID+141, 50487, 0, 1, 1, -11552.46, -571.715, 26.9324, 5.802073, 120, 0, 0), -- Forest Spiderling (Area: 0) (possible waypoints or random movement)
(@CGUID+142, 683, 0, 1, 1, -11583.76, -493.4785, 22.79687, 4.291103, 120, 0, 0), -- Young Panther (Area: 0)
(@CGUID+143, 50487, 0, 1, 1, -11595.4, -445.7845, 14.68493, 4.768774, 120, 0, 0), -- Forest Spiderling (Area: 0) (possible waypoints or random movement)
(@CGUID+144, 940, 0, 1, 1, -11545.45, -576.1585, 27.14032, 5.672951, 120, 0, 0), -- Kurzen Medicine Man (Area: 0)
(@CGUID+145, 940, 0, 1, 1, -11565.8, -587.167, 33.68952, 5.689774, 120, 0, 0), -- Kurzen Medicine Man (Area: 0)
(@CGUID+146, 937, 0, 1, 1, -11575.13, -567.467, 29.58263, 3.141593, 120, 0, 0), -- Kurzen Jungle Fighter (Area: 0)
(@CGUID+147, 940, 0, 1, 1, -11569.25, -584.0886, 29.10099, 3.141593, 120, 0, 0), -- Kurzen Medicine Man (Area: 0)
(@CGUID+148, 940, 0, 1, 1, -11587.13, -545.3199, 31.27658, 2.443352, 120, 0, 0), -- Kurzen Medicine Man (Area: 0)
(@CGUID+149, 940, 0, 1, 1, -11585.34, -579.6632, 29.10099, 3.141593, 120, 0, 0), -- Kurzen Medicine Man (Area: 0)
(@CGUID+150, 937, 0, 1, 1, -11579.45, -594.3708, 28.08289, 5.759913, 120, 0, 0), -- Kurzen Jungle Fighter (Area: 0)
(@CGUID+151, 937, 0, 1, 1, -11535.03, -640.9081, 31.30552, 3.136807, 120, 0, 0), -- Kurzen Jungle Fighter (Area: 0)
(@CGUID+152, 940, 0, 1, 1, -11525.52, -652.1016, 31.05497, 3.206976, 120, 0, 0), -- Kurzen Medicine Man (Area: 0)
(@CGUID+153, 937, 0, 1, 1, -11585.15, -615.8669, 28.41126, 4.06459, 120, 0, 0), -- Kurzen Jungle Fighter (Area: 0)
(@CGUID+154, 50487, 0, 1, 1, -11561.49, -630.1864, 31.81574, 2.735674, 120, 0, 0), -- Forest Spiderling (Area: 0) (possible waypoints or random movement)
(@CGUID+155, 937, 0, 1, 1, -11575.24, -642.2039, 30.85888, 2.231911, 120, 0, 0), -- Kurzen Jungle Fighter (Area: 0)
(@CGUID+156, 938, 0, 1, 1, -11508.19, -610.9551, 36.30719, 0.222184, 120, 0, 0), -- Kurzen Commando (Area: Kurzen's Compound)
(@CGUID+157, 977, 0, 1, 1, -11580.62, -670.1998, 32.83378, 3.974366, 120, 0, 0), -- Kurzen War Panther (Area: Kurzen's Compound)
(@CGUID+158, 943, 0, 1, 1, -11570.34, -703.1966, 31.15481, 2.548181, 120, 0, 0), -- Kurzen Wrangler (Area: Kurzen's Compound)
(@CGUID+159, 976, 0, 1, 1, -11569.99, -698.5981, 31.15481, 4.660029, 120, 0, 0), -- Kurzen War Tiger (Area: Kurzen's Compound)
(@CGUID+160, 43050, 0, 1, 1, -11587.44, -678.8931, 32.62235, 0.3699804, 120, 0, 0), -- Vale Howler (Area: Kurzen's Compound) (possible waypoints or random movement)
(@CGUID+161, 941, 0, 1, 1, -11503.66, -740.1837, 30.01427, 1.779418, 120, 0, 0), -- Kurzen Headshrinker (Area: Kurzen's Compound)
(@CGUID+162, 938, 0, 1, 1, -11525.21, -681.2846, 34.32074, 5.546159, 120, 0, 0), -- Kurzen Commando (Area: Kurzen's Compound)
(@CGUID+163, 689, 0, 1, 1, -11458.38, -694.4479, 62.03806, 3.668538, 120, 0, 0), -- Crystal Spine Basilisk (Area: Kurzen's Compound) (possible waypoints or random movement)
(@CGUID+164, 940, 0, 1, 1, -11600, -624.764, 28.4535, 0.24165, 120, 0, 0), -- Kurzen Medicine Man (Area: Kurzen's Compound)
(@CGUID+165, 689, 0, 1, 1, -11479.86, -743.4507, 69.16376, 0.5861649, 120, 0, 0), -- Crystal Spine Basilisk (Area: Kurzen's Compound) (possible waypoints or random movement)
(@CGUID+166, 943, 0, 1, 1, -11591.37, -704.6274, 31.15634, 2.356194, 120, 0, 0), -- Kurzen Wrangler (Area: Kurzen's Compound)
(@CGUID+167, 977, 0, 1, 1, -11592.85, -707.0453, 31.15634, 1.867502, 120, 0, 0), -- Kurzen War Panther (Area: Kurzen's Compound)
(@CGUID+168, 689, 0, 1, 1, -11568.49, -744.6081, 33.60015, 2.759273, 120, 0, 0), -- Crystal Spine Basilisk (Area: Kurzen's Compound) (possible waypoints or random movement)
(@CGUID+169, 943, 0, 1, 1, -11599.4, -686.7, 31.38293, 0.4363323, 120, 0, 0), -- Kurzen Wrangler (Area: Kurzen's Compound)
(@CGUID+170, 977, 0, 1, 1, -11595.2, -685.45, 32.13023, 3.263766, 120, 0, 0), -- Kurzen War Panther (Area: Kurzen's Compound)
(@CGUID+171, 50487, 0, 1, 1, -11590.13, -722.6853, 33.34232, 6.078507, 120, 0, 0), -- Forest Spiderling (Area: Kurzen's Compound) (possible waypoints or random movement)
(@CGUID+172, 49928, 0, 1, 1, -11498.8, -776.276, 67.37757, 1.77869, 120, 0, 0), -- Crimson Moth (Area: Kurzen's Compound)
(@CGUID+173, 941, 0, 1, 1, -11453.21, -739.8196, 29.13855, 4.021726, 120, 0, 0), -- Kurzen Headshrinker (Area: Kurzen's Compound)
(@CGUID+174, 939, 0, 1, 1, -11449.12, -765.013, 10.77878, 4.282991, 120, 0, 0), -- Kurzen Elite (Area: Kurzen's Compound)
(@CGUID+175, 943, 0, 1, 1, -11610.45, -698.7394, 31.15634, 1.047198, 120, 0, 0), -- Kurzen Wrangler (Area: Kurzen's Compound)
(@CGUID+176, 736, 0, 1, 1, -11607.78, -694.8514, 31.15869, 4.08407, 120, 0, 0), -- Panther (Area: Kurzen's Compound)
(@CGUID+177, 682, 0, 1, 1, -11606.85, -701.3459, 31.15634, 2.75762, 120, 0, 0), -- Stranglethorn Tiger (Area: Kurzen's Compound)
(@CGUID+178, 50487, 0, 1, 1, -11622.34, -719.0604, 32.05885, 4.469779, 120, 0, 0), -- Forest Spiderling (Area: Kurzen's Compound) (possible waypoints or random movement)
(@CGUID+179, 689, 0, 1, 1, -11629.64, -727.2448, 32.89821, 6.12638, 120, 0, 0), -- Crystal Spine Basilisk (Area: Kurzen's Compound) (possible waypoints or random movement)
(@CGUID+180, 50479, 0, 1, 1, -11514.78, -791.2352, 49.58298, 0.2364562, 120, 0, 0), -- Lizard Hatchling (Area: Kurzen's Compound)
(@CGUID+181, 940, 0, 1, 1, -11481.61, -787.7988, 52.80153, 3.549306, 120, 0, 0), -- Kurzen Medicine Man (Area: Kurzen's Compound)
(@CGUID+182, 940, 0, 1, 1, -11617.04, -657.7886, 32.10707, 0.5598445, 120, 0, 0), -- Kurzen Medicine Man (Area: Kurzen's Compound)
(@CGUID+183, 50487, 0, 1, 1, -11611.47, -644.5013, 29.62574, 5.591952, 120, 0, 0), -- Forest Spiderling (Area: Kurzen's Compound) (possible waypoints or random movement)
(@CGUID+184, 938, 0, 1, 1, -11535.72, -710.0327, 36.25966, 6.159283, 120, 0, 0), -- Kurzen Commando (Area: Kurzen's Compound)
(@CGUID+185, 938, 0, 1, 1, -11517.01, -719.5086, 32.43346, 4.309461, 120, 0, 0), -- Kurzen Commando (Area: The Stockpile)
(@CGUID+186, 941, 0, 1, 1, -11496.28, -823.6375, 34.03745, 1.230364, 120, 0, 0), -- Kurzen Headshrinker (Area: The Stockpile)
(@CGUID+187, 942, 0, 1, 1, -11476.78, -838.5921, 13.84043, 4.156815, 120, 0, 0), -- Kurzen Witch Doctor (Area: The Stockpile)
(@CGUID+188, 15475, 0, 1, 1, -11511.49, -815.1832, 56.54857, 5.804437, 120, 0, 0), -- Beetle (Area: The Stockpile)
(@CGUID+189, 939, 0, 1, 1, -11479.83, -839.2713, 13.52394, 3.614417, 120, 0, 0), -- Kurzen Elite (Area: The Stockpile)
(@CGUID+190, 942, 0, 1, 1, -11447.66, -816.6434, 15.70297, 1.232056, 120, 0, 0), -- Kurzen Witch Doctor (Area: The Stockpile)
(@CGUID+191, 689, 0, 1, 1, -11420.39, -757.5625, 78.2193, 0.910096, 120, 0, 0), -- Crystal Spine Basilisk (Area: The Stockpile) (possible waypoints or random movement)
(@CGUID+192, 942, 0, 1, 1, -11417, -771.1678, 14.96441, 5.906834, 120, 0, 0), -- Kurzen Witch Doctor (Area: The Stockpile)
(@CGUID+193, 939, 0, 1, 1, -11453.07, -794.497, 15.07692, 4.049706, 120, 0, 0), -- Kurzen Elite (Area: The Stockpile)
(@CGUID+194, 938, 0, 1, 1, -11485.68, -732.0408, 34.44156, 1.83691, 120, 0, 0), -- Kurzen Commando (Area: The Stockpile)
(@CGUID+195, 938, 0, 1, 1, -11466.07, -759.8378, 31.58591, 3.24389, 120, 0, 0), -- Kurzen Commando (Area: The Stockpile)
(@CGUID+196, 941, 0, 1, 1, -11478.57, -846.0662, 35.87386, 2.80603, 120, 0, 0), -- Kurzen Headshrinker (Area: The Stockpile)
(@CGUID+197, 689, 0, 1, 1, -11417.49, -809.6745, 89.02488, 5.180404, 120, 0, 0), -- Crystal Spine Basilisk (Area: The Stockpile) (possible waypoints or random movement)
(@CGUID+198, 43911, 0, 1, 1, -11401.35, -816.9705, 15.04775, 2.286381, 120, 0, 0), -- Chief Gaulus (Area: The Stockpile)
(@CGUID+199, 939, 0, 1, 1, -11437.78, -835.8332, 14.7872, 2.743138, 120, 0, 0), -- Kurzen Elite (Area: The Stockpile)
(@CGUID+200, 942, 0, 1, 1, -11451.17, -835.628, 14.79054, 5.536398, 120, 0, 0), -- Kurzen Witch Doctor (Area: The Stockpile)
(@CGUID+201, 689, 0, 1, 1, -11396.36, -704.5034, 87.73492, 0.362522, 120, 0, 0), -- Crystal Spine Basilisk (Area: The Stockpile) (possible waypoints or random movement)
(@CGUID+202, 938, 0, 1, 1, -11492.6, -794.3301, 32.20677, 1.619931, 120, 0, 0), -- Kurzen Commando (Area: The Stockpile)
(@CGUID+203, 43910, 0, 1, 1, -11473.96, -869.1649, 36.56422, 1.53589, 120, 0, 0), -- Chief Anders (Area: The Stockpile)
(@CGUID+204, 941, 0, 1, 1, -11527.37, -848.9777, 28.43269, 4.374874, 120, 0, 0), -- Kurzen Headshrinker (Area: The Stockpile)
(@CGUID+205, 939, 0, 1, 1, -11530.74, -867.5033, 25.03779, 1.190703, 120, 0, 0), -- Kurzen Elite (Area: The Stockpile)
(@CGUID+206, 49928, 0, 1, 1, -11564.2, -819.0723, 67.796, 0.8125438, 120, 0, 0), -- Crimson Moth (Area: The Stockpile)
(@CGUID+207, 689, 0, 1, 1, -11456.86, -852.5508, 81.31494, 4.259231, 120, 0, 0), -- Crystal Spine Basilisk (Area: The Stockpile) (possible waypoints or random movement)
(@CGUID+208, 939, 0, 1, 1, -11503.4, -923.4218, 25.64176, 1.940764, 120, 0, 0), -- Kurzen Elite (Area: The Stockpile)
(@CGUID+209, 939, 0, 1, 1, -11530.39, -897.8753, 24.77011, 0.5362512, 120, 0, 0), -- Kurzen Elite (Area: The Stockpile)
(@CGUID+210, 942, 0, 1, 1, -11538.9, -881.5605, 24.26158, 1.347626, 120, 0, 0), -- Kurzen Witch Doctor (Area: The Stockpile)
(@CGUID+211, 942, 0, 1, 1, -11522.65, -939.7976, 29.43715, 2.163429, 120, 0, 0), -- Kurzen Witch Doctor (Area: The Stockpile)
(@CGUID+212, 942, 0, 1, 1, -11477.9, -925.7442, 21.98798, 5.006572, 120, 0, 0), -- Kurzen Witch Doctor (Area: The Stockpile)
(@CGUID+213, 978, 0, 1, 1, -11458.62, -927.2252, 19.98264, 1.35795, 120, 0, 0), -- Kurzen Subchief (Area: The Stockpile)
(@CGUID+214, 978, 0, 1, 1, -11418.1, -899.6285, 18.55586, 5.383784, 120, 0, 0), -- Kurzen Subchief (Area: The Stockpile)
(@CGUID+215, 978, 0, 1, 1, -11439.96, -914.6896, 18.35433, 2.73374, 120, 0, 0), -- Kurzen Subchief (Area: The Stockpile)
(@CGUID+216, 979, 0, 1, 1, -11404.67, -879.3287, 18.27936, 0.0765921, 120, 0, 0), -- Kurzen Shadow Hunter (Area: The Stockpile)
(@CGUID+217, 978, 0, 1, 1, -11414.5, -911.7153, 18.19402, 4.012488, 120, 0, 0), -- Kurzen Subchief (Area: The Stockpile)
(@CGUID+218, 689, 0, 1, 1, -11578.09, -916.6074, 68.08997, 5.734729, 120, 0, 0), -- Crystal Spine Basilisk (Area: The Stockpile) (possible waypoints or random movement)
(@CGUID+219, 43913, 0, 1, 1, -11483.68, -953.5226, 31.17395, 2.513274, 120, 0, 0), -- Chief Miranda (Area: The Stockpile)
(@CGUID+220, 689, 0, 1, 1, -11612.07, -894.3219, 69.30054, 4.356671, 120, 0, 0), -- Crystal Spine Basilisk (Area: The Stockpile) (possible waypoints or random movement)
(@CGUID+221, 32520, 0, 1, 1, -6148.39, 5539.97, -1207.787, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Stockpile)
(@CGUID+222, 32520, 0, 1, 1, -5691.65, 5556.92, -1154.687, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Stockpile)
(@CGUID+223, 32520, 0, 1, 1, -6305.162, 5582.533, -1172.063, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Stockpile)
(@CGUID+224, 32520, 0, 1, 1, -6014.71, 5479.63, -1208.007, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Stockpile)
(@CGUID+225, 979, 0, 1, 1, -11411, -949.7495, 17.82231, 5.718831, 120, 0, 0), -- Kurzen Shadow Hunter (Area: The Stockpile)
(@CGUID+226, 978, 0, 1, 1, -11359.67, -894.5151, 21.79982, 3.211619, 120, 0, 0), -- Kurzen Subchief (Area: The Stockpile)
(@CGUID+227, 43912, 0, 1, 1, -11337.27, -966.1823, 30.02892, 1.780236, 120, 0, 0), -- Chief Esquivel (Area: The Stockpile)
(@CGUID+228, 978, 0, 1, 1, -11344, -931.2006, 32.24931, 3.109796, 120, 0, 0), -- Kurzen Subchief (Area: The Stockpile)
(@CGUID+229, 979, 0, 1, 1, -11322.63, -971.3091, 32.3575, 1.834294, 120, 0, 0), -- Kurzen Shadow Hunter (Area: The Stockpile)
(@CGUID+230, 689, 0, 1, 1, -11594.8, -841.1989, 48.46374, 3.552378, 120, 0, 0), -- Crystal Spine Basilisk (Area: The Stockpile) (possible waypoints or random movement)
(@CGUID+231, 689, 0, 1, 1, -11548, -814.1948, 53.32373, 0.6118463, 120, 0, 0), -- Crystal Spine Basilisk (Area: The Stockpile) (possible waypoints or random movement)
(@CGUID+232, 689, 0, 1, 1, -11623.72, -842.3672, 48.22909, 0.9890128, 120, 0, 0), -- Crystal Spine Basilisk (Area: The Stockpile) (possible waypoints or random movement)
(@CGUID+233, 689, 0, 1, 1, -11518.75, -782.6998, 48.54123, 3.139929, 120, 0, 0), -- Crystal Spine Basilisk (Area: The Stockpile) (possible waypoints or random movement)
(@CGUID+234, 689, 0, 1, 1, -11582.77, -782.8671, 45.05349, 1.073944, 120, 0, 0), -- Crystal Spine Basilisk (Area: The Stockpile) (possible waypoints or random movement)
(@CGUID+235, 689, 0, 1, 1, -11517.74, -850.7398, 68.33216, 5.738791, 120, 0, 0), -- Crystal Spine Basilisk (Area: The Stockpile) (possible waypoints or random movement)
(@CGUID+236, 940, 0, 1, 1, -11624.3, -640.8455, 29.63983, 5.951573, 120, 0, 0), -- Kurzen Medicine Man (Area: Kurzen's Compound)
(@CGUID+237, 49928, 0, 1, 1, -11636.94, -693.3425, 45.58846, 2.315856, 120, 0, 0), -- Crimson Moth (Area: Kurzen's Compound)
(@CGUID+238, 689, 0, 1, 1, -11644.17, -771.9906, 32.22645, 0.3525773, 120, 0, 0), -- Crystal Spine Basilisk (Area: Kurzen's Compound) (possible waypoints or random movement)
(@CGUID+239, 689, 0, 1, 1, -11657.09, -725.748, 34.74924, 0.9219912, 120, 0, 0), -- Crystal Spine Basilisk (Area: Kurzen's Compound) (possible waypoints or random movement)
(@CGUID+240, 689, 0, 1, 1, -11622.27, -768.0586, 37.84638, 4.319053, 120, 0, 0), -- Crystal Spine Basilisk (Area: Kurzen's Compound) (possible waypoints or random movement)
(@CGUID+241, 50487, 0, 1, 1, -11611.2, -790.2985, 42.6352, 0.2449511, 120, 0, 0), -- Forest Spiderling (Area: Kurzen's Compound) (possible waypoints or random movement)
(@CGUID+242, 689, 0, 1, 1, -11622.37, -796.9977, 42.32349, 2.11186, 120, 0, 0), -- Crystal Spine Basilisk (Area: Kurzen's Compound) (possible waypoints or random movement)
(@CGUID+243, 43050, 0, 1, 1, -11620.61, -752.5936, 31.97147, 1.749427, 120, 0, 0), -- Vale Howler (Area: Kurzen's Compound) (possible waypoints or random movement)
(@CGUID+244, 689, 0, 1, 1, -11550.41, -884.9651, 68.90044, 0.8663628, 120, 0, 0), -- Crystal Spine Basilisk (Area: Kurzen's Compound) (possible waypoints or random movement)
(@CGUID+245, 15475, 0, 1, 1, -11664.28, -864.553, 34.10249, 2.226016, 120, 0, 0), -- Beetle (Area: Kurzen's Compound)
(@CGUID+246, 689, 0, 1, 1, -11645.86, -814.9656, 39.0596, 0.8102549, 120, 0, 0), -- Crystal Spine Basilisk (Area: Kurzen's Compound) (possible waypoints or random movement)
(@CGUID+247, 940, 0, 1, 1, -11638.76, -630.0628, 31.46877, 3.583308, 120, 0, 0), -- Kurzen Medicine Man (Area: Kurzen's Compound)
(@CGUID+248, 937, 0, 1, 1, -11649.01, -670.4881, 30.32007, 3.062688, 120, 0, 0), -- Kurzen Jungle Fighter (Area: Kurzen's Compound)
(@CGUID+249, 940, 0, 1, 1, -11618.11, -593.4931, 26.72099, 0.6670829, 120, 0, 0), -- Kurzen Medicine Man (Area: Kurzen's Compound)
(@CGUID+250, 940, 0, 1, 1, -11657.54, -639.1799, 30.04121, 0.7345467, 120, 0, 0), -- Kurzen Medicine Man (Area: Kurzen's Compound)
(@CGUID+251, 937, 0, 1, 1, -11658.23, -622.4955, 30.04121, 4.588046, 120, 0, 0), -- Kurzen Jungle Fighter (Area: Kurzen's Compound)
(@CGUID+252, 15475, 0, 1, 1, -11639.12, -505.564, 19.437, 0.8273214, 120, 0, 0), -- Beetle (Area: Kurzen's Compound)
(@CGUID+253, 683, 0, 1, 1, -11626.34, -511.7008, 19.437, 2.336579, 120, 0, 0), -- Young Panther (Area: Kurzen's Compound)
(@CGUID+254, 683, 0, 1, 1, -11682.76, -434.4122, 15.42403, 1.019526, 120, 0, 0), -- Young Panther (Area: 0)
(@CGUID+255, 683, 0, 1, 1, -11621.94, -464.0468, 15.10308, 0.4695796, 120, 0, 0), -- Young Panther (Area: 0)
(@CGUID+256, 683, 0, 1, 1, -11628.77, -449.596, 13.8458, 5.113744, 120, 0, 0), -- Young Panther (Area: 0)
(@CGUID+257, 49722, 0, 1, 1, -11609.44, -415.1867, 16.39993, 1.932081, 120, 0, 0), -- Tree Python (Area: 0) (possible waypoints or random movement)
(@CGUID+258, 49928, 0, 1, 1, -11603.16, -426.9412, 30.16512, 4.494737, 120, 0, 0), -- Crimson Moth (Area: 0)
(@CGUID+259, 683, 0, 1, 1, -11617.11, -385.2436, 17.00032, 2.63311, 120, 0, 0), -- Young Panther (Area: 0)
(@CGUID+260, 683, 0, 1, 1, -11651.13, -353.587, 15.27107, 2.641394, 120, 0, 0), -- Young Panther (Area: 0)
(@CGUID+261, 1150, 0, 1, 1, -11660.48, -324.9718, 14.54384, 2.785653, 120, 0, 0), -- River Crocolisk (Area: 0) (possible waypoints or random movement)
(@CGUID+262, 682, 0, 1, 1, -11591.84, -341.1172, 33.44156, 1.217516, 120, 0, 0), -- Stranglethorn Tiger (Area: 0)
(@CGUID+263, 1150, 0, 1, 1, -11647.39, -250.0662, 5.522381, 4.483172, 120, 0, 0), -- River Crocolisk (Area: 0) (possible waypoints or random movement)
(@CGUID+264, 6827, 0, 1, 1, -11629.96, -144.8404, 16.60996, 2.002957, 120, 0, 0), -- Crab (Area: 0)
(@CGUID+265, 6827, 0, 1, 1, -11606.04, -152.0432, 10.06846, 4.104083, 120, 0, 0), -- Crab (Area: 0)
(@CGUID+266, 716, 0, 1, 1, -11621.53, -70.29166, 16.3219, 2.443461, 120, 0, 0), -- Barnil Stonepot (Area: 0)
(@CGUID+267, 43049, 0, 1, 1, -11623.64, -85.09202, 16.3219, 5.288348, 120, 0, 0), -- Nesingwary Hired Gun (Area: 0)
(@CGUID+268, 718, 0, 1, 1, -11625.49, -48.63889, 16.30951, 0.4326047, 120, 0, 0), -- Sir S. J. Erlgadin (Area: 0) (possible waypoints or random movement)
(@CGUID+269, 717, 0, 1, 1, -11636.22, -80.82813, 16.3219, 1.937315, 120, 0, 0), -- Ajeck Rouack (Area: 0)
(@CGUID+270, 50487, 0, 1, 1, -11637.74, -83.00213, 16.31938, 0.431994, 120, 0, 0), -- Forest Spiderling (Area: 0)
(@CGUID+271, 50479, 0, 1, 1, -11622.1, -27.59717, 13.46706, 3.082952, 120, 0, 0), -- Lizard Hatchling (Area: 0)
(@CGUID+272, 43049, 0, 1, 1, -11628.2, -67.9872, 16.27883, 0.7318926, 120, 0, 0), -- Nesingwary Hired Gun (Area: 0) (possible waypoints or random movement)
(@CGUID+273, 6827, 0, 1, 1, -11612.4, -14.08942, 10.41508, 2.970277, 120, 0, 0), -- Crab (Area: 0)
(@CGUID+274, 6827, 0, 1, 1, -11611, 6.617188, 11.86539, 4.700671, 120, 0, 0), -- Crab (Area: 0)
(@CGUID+275, 681, 0, 1, 1, -11608.4, 86.2645, 15.38009, 2.121939, 120, 0, 0), -- Young Stranglethorn Tiger (Area: 0)
(@CGUID+276, 701, 0, 1, 1, -11636.49, 460.6056, 43.00445, 4.206244, 120, 0, 0), -- Bloodscalp Mystic (Area: 0)
(@CGUID+277, 588, 0, 1, 1, -11638.35, 569.6217, 50.58598, 2.627319, 120, 0, 0), -- Bloodscalp Scout (Area: 0) (possible waypoints or random movement)
(@CGUID+278, 588, 0, 1, 1, -11611.33, 620.3871, 50.71634, 1.279132, 120, 0, 0), -- Bloodscalp Scout (Area: 0) (possible waypoints or random movement)
(@CGUID+279, 6827, 0, 1, 1, -11562.14, 1269.955, 1.169139, 0.7201372, 120, 0, 0), -- Crab (Area: The Savage Coast)
(@CGUID+280, 6827, 0, 1, 1, -11711.43, 1271.997, 0.43998, 2.412939, 120, 0, 0), -- Crab (Area: The Savage Coast)
(@CGUID+281, 6827, 0, 1, 1, -11656.35, 1077.386, 1.688583, 4.626328, 120, 0, 0), -- Crab (Area: The Savage Coast)
(@CGUID+282, 6827, 0, 1, 1, -11678.01, 1069.482, 1.769801, 2.611551, 120, 0, 0), -- Crab (Area: The Savage Coast)
(@CGUID+283, 597, 0, 1, 1, -11680.99, 1013.119, 0.8454274, 4.08862, 120, 0, 0), -- Bloodscalp Berserker (Area: The Savage Coast) (possible waypoints or random movement)
(@CGUID+284, 597, 0, 1, 1, -11676.62, 973.5771, 6.310598, 5.075849, 120, 0, 0), -- Bloodscalp Berserker (Area: The Savage Coast) (possible waypoints or random movement)
(@CGUID+285, 671, 0, 1, 1, -11647.71, 973.7341, 4.773001, 5.332562, 120, 0, 0), -- Bloodscalp Headhunter (Area: The Savage Coast) (possible waypoints or random movement)
(@CGUID+286, 42772, 0, 1, 1, -11662.37, 952.132, 4.572278, 0, 120, 0, 0), -- Zuuldaian Fetish (Area: The Savage Coast)
(@CGUID+287, 42772, 0, 1, 1, -11651.71, 976.8386, 4.56545, 0, 120, 0, 0), -- Zuuldaian Fetish (Area: The Savage Coast)
(@CGUID+288, 671, 0, 1, 1, -11715.24, 981.2447, 2.833849, 6.089874, 120, 0, 0), -- Bloodscalp Headhunter (Area: The Savage Coast) (possible waypoints or random movement)
(@CGUID+289, 6827, 0, 1, 1, -11708.42, 1015.891, -0.1307528, 1.478899, 120, 0, 0), -- Crab (Area: The Savage Coast)
(@CGUID+290, 660, 0, 1, 1, -11673.37, 951.6531, 3.875346, 1.516331, 120, 0, 0), -- Bloodscalp Witch Doctor (Area: The Savage Coast) (possible waypoints or random movement)
(@CGUID+291, 660, 0, 1, 1, -11664.89, 942.1138, 3.625202, 3.285427, 120, 0, 0), -- Bloodscalp Witch Doctor (Area: The Savage Coast) (possible waypoints or random movement)
(@CGUID+292, 660, 0, 1, 1, -11684.87, 952.8365, 3.873342, 5.096361, 120, 0, 0), -- Bloodscalp Witch Doctor (Area: The Savage Coast)
(@CGUID+293, 42772, 0, 1, 1, -11686.11, 976.4965, 6.192403, 0, 120, 0, 0), -- Zuuldaian Fetish (Area: The Savage Coast)
(@CGUID+294, 6827, 0, 1, 1, -11647.72, 868.056, 2.401163, 3.967742, 120, 0, 0), -- Crab (Area: Zuuldaia Ruins)
(@CGUID+295, 6827, 0, 1, 1, -11715.01, 896.3774, 2.533568, 0.6292863, 120, 0, 0), -- Crab (Area: Zuuldaia Ruins)
(@CGUID+296, 42772, 0, 1, 1, -11654.39, 870.6285, 4.065646, 0, 120, 0, 0), -- Zuuldaian Fetish (Area: Zuuldaia Ruins)
(@CGUID+297, 597, 0, 1, 1, -11719.4, 884.7554, 4.309722, 1.31715, 120, 0, 0), -- Bloodscalp Berserker (Area: Zuuldaia Ruins) (possible waypoints or random movement)
(@CGUID+298, 671, 0, 1, 1, -11719.3, 922.6942, 4.394163, 3.762138, 120, 0, 0), -- Bloodscalp Headhunter (Area: Zuuldaia Ruins) (possible waypoints or random movement)
(@CGUID+299, 660, 0, 1, 1, -11679.9, 890.2695, 5.282022, 1.829512, 120, 0, 0), -- Bloodscalp Witch Doctor (Area: Zuuldaia Ruins) (possible waypoints or random movement)
(@CGUID+300, 597, 0, 1, 1, -11650.46, 858.6076, 1.011704, 4.147056, 120, 0, 0), -- Bloodscalp Berserker (Area: Zuuldaia Ruins) (possible waypoints or random movement)
(@CGUID+301, 660, 0, 1, 1, -11696.22, 857.7969, 1.292772, 3.144615, 120, 0, 0), -- Bloodscalp Witch Doctor (Area: Zuuldaia Ruins) (possible waypoints or random movement)
(@CGUID+302, 671, 0, 1, 1, -11641.14, 889.4089, 2.797037, 2.134179, 120, 0, 0), -- Bloodscalp Headhunter (Area: Zuuldaia Ruins) (possible waypoints or random movement)
(@CGUID+303, 597, 0, 1, 1, -11670.95, 928.6061, 2.960552, 0.3517641, 120, 0, 0), -- Bloodscalp Berserker (Area: Zuuldaia Ruins) (possible waypoints or random movement)
(@CGUID+304, 671, 0, 1, 1, -11687.19, 928.57, 3.112651, 4.772225, 120, 0, 0), -- Bloodscalp Headhunter (Area: Zuuldaia Ruins) (possible waypoints or random movement)
(@CGUID+305, 42772, 0, 1, 1, -11709.91, 968.1024, 3.686104, 0, 120, 0, 0), -- Zuuldaian Fetish (Area: Zuuldaia Ruins)
(@CGUID+306, 42772, 0, 1, 1, -11689.66, 947.2379, 4.005286, 0, 120, 0, 0), -- Zuuldaian Fetish (Area: Zuuldaia Ruins)
(@CGUID+307, 660, 0, 1, 1, -11682.4, 945.5559, 3.975252, 1.727876, 120, 0, 0), -- Bloodscalp Witch Doctor (Area: Zuuldaia Ruins)
(@CGUID+308, 597, 0, 1, 1, -11677.13, 939.4199, 4.250346, 1.019766, 120, 0, 0), -- Bloodscalp Berserker (Area: Zuuldaia Ruins) (possible waypoints or random movement)
(@CGUID+309, 42772, 0, 1, 1, -11675.95, 939.4479, 4.33413, 0, 120, 0, 0), -- Zuuldaian Fetish (Area: Zuuldaia Ruins)
(@CGUID+310, 6827, 0, 1, 1, -11725.3, 973.2299, 3.009768, 2.065465, 120, 0, 0), -- Crab (Area: Zuuldaia Ruins)
(@CGUID+311, 701, 0, 1, 1, -11713.36, 791.4893, 30.75276, 4.924796, 120, 0, 0), -- Bloodscalp Mystic (Area: Zuuldaia Ruins) (possible waypoints or random movement)
(@CGUID+312, 50479, 0, 1, 1, -11643.6, 756.6503, 40.59572, 3.979824, 120, 0, 0), -- Lizard Hatchling (Area: Zuuldaia Ruins)
(@CGUID+313, 699, 0, 1, 1, -11653.84, 762.493, 42.72396, 5.88176, 120, 0, 0), -- Bloodscalp Beastmaster (Area: Zuuldaia Ruins)
(@CGUID+314, 701, 0, 1, 1, -11678.76, 748.3038, 50.585, 3.211406, 120, 0, 0), -- Bloodscalp Mystic (Area: Zuuldaia Ruins)
(@CGUID+315, 701, 0, 1, 1, -11703.13, 750.9442, 49.69749, 0.592388, 120, 0, 0), -- Bloodscalp Mystic (Area: Zuuldaia Ruins) (possible waypoints or random movement)
(@CGUID+316, 701, 0, 1, 1, -11686.8, 730.7886, 50.18011, 3.460372, 120, 0, 0), -- Bloodscalp Mystic (Area: Zuuldaia Ruins) (possible waypoints or random movement)
(@CGUID+317, 701, 0, 1, 1, -11690.9, 746.1323, 49.638, 0.6258088, 120, 0, 0), -- Bloodscalp Mystic (Area: Zuuldaia Ruins) (possible waypoints or random movement)
(@CGUID+318, 701, 0, 1, 1, -11677.38, 773.0689, 50.8321, 4.605717, 120, 0, 0), -- Bloodscalp Mystic (Area: Zuuldaia Ruins) (possible waypoints or random movement)
(@CGUID+319, 588, 0, 1, 1, -11689.21, 757.6736, 50.73539, 4.328416, 120, 0, 0), -- Bloodscalp Scout (Area: Zuuldaia Ruins)
(@CGUID+320, 588, 0, 1, 1, -11668.37, 743.1406, 50.73346, 0.1991438, 120, 0, 0), -- Bloodscalp Scout (Area: Zuuldaia Ruins) (possible waypoints or random movement)
(@CGUID+321, 597, 0, 1, 1, -11714.1, 837.3854, 17.4198, 1.692969, 120, 0, 0), -- Bloodscalp Berserker (Area: Zuuldaia Ruins)
(@CGUID+322, 597, 0, 1, 1, -11732.39, 841.1858, 17.5916, 2.460914, 120, 0, 0), -- Bloodscalp Berserker (Area: Zuuldaia Ruins)
(@CGUID+323, 42772, 0, 1, 1, -11713.73, 856.7934, 1.121728, 0, 120, 0, 0), -- Zuuldaian Fetish (Area: Zuuldaia Ruins)
(@CGUID+324, 701, 0, 1, 1, -11728.9, 804.2382, 30.54833, 2.077117, 120, 0, 0), -- Bloodscalp Mystic (Area: Zuuldaia Ruins) (possible waypoints or random movement)
(@CGUID+325, 595, 0, 1, 1, -11687.47, 665.5499, 49.91267, 1.130746, 120, 0, 0), -- Bloodscalp Hunter (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+326, 701, 0, 1, 1, -11727.67, 744.5222, 50.82249, 0.7787213, 120, 0, 0), -- Bloodscalp Mystic (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+327, 588, 0, 1, 1, -11731.57, 729.4566, 50.76561, 1.540031, 120, 0, 0), -- Bloodscalp Scout (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+328, 588, 0, 1, 1, -11647.34, 678.0962, 47.27711, 6.17672, 120, 0, 0), -- Bloodscalp Scout (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+329, 701, 0, 1, 1, -11704.36, 732.0213, 49.65013, 0.9239653, 120, 0, 0), -- Bloodscalp Mystic (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+330, 595, 0, 1, 1, -11687.73, 693.2063, 50.08733, 0.792711, 120, 0, 0), -- Bloodscalp Hunter (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+331, 588, 0, 1, 1, -11709.05, 663.967, 50.32741, 5.723177, 120, 0, 0), -- Bloodscalp Scout (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+332, 588, 0, 1, 1, -11657.86, 644.7691, 50.90149, 3.286311, 120, 0, 0), -- Bloodscalp Scout (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+333, 701, 0, 1, 1, -11662.48, 652.7217, 50.28196, 2.658658, 120, 0, 0), -- Bloodscalp Mystic (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+334, 701, 0, 1, 1, -11642.1, 614.2698, 50.17922, 3.222879, 120, 0, 0), -- Bloodscalp Mystic (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+335, 595, 0, 1, 1, -11687.03, 638.6077, 49.54946, 2.199115, 120, 0, 0), -- Bloodscalp Hunter (Area: Ruins of Zul'Kunda)
(@CGUID+336, 701, 0, 1, 1, -11692.76, 638.5521, 49.50824, 0.6632251, 120, 0, 0), -- Bloodscalp Mystic (Area: Ruins of Zul'Kunda)
(@CGUID+337, 595, 0, 1, 1, -11707.47, 647.3634, 49.64967, 5.743476, 120, 0, 0), -- Bloodscalp Hunter (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+338, 595, 0, 1, 1, -11707.56, 633.7621, 50.3268, 4.071654, 120, 0, 0), -- Bloodscalp Hunter (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+339, 701, 0, 1, 1, -11689.68, 605.7371, 49.69599, 1.622766, 120, 0, 0), -- Bloodscalp Mystic (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+340, 701, 0, 1, 1, -11700.17, 615.8066, 50.0025, 4.653747, 120, 0, 0), -- Bloodscalp Mystic (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+341, 50487, 0, 1, 1, -11700.73, 644.1422, 50.05558, 5.039437, 120, 0, 0), -- Forest Spiderling (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+342, 701, 0, 1, 1, -11713.38, 606.2435, 50.47341, 0.2475829, 120, 0, 0), -- Bloodscalp Mystic (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+343, 701, 0, 1, 1, -11735.38, 623.9656, 50.7204, 1.390487, 120, 0, 0), -- Bloodscalp Mystic (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+344, 595, 0, 1, 1, -11657.46, 562.1375, 50.65004, 2.909492, 120, 0, 0), -- Bloodscalp Hunter (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+345, 588, 0, 1, 1, -11687.24, 564.9387, 49.92028, 4.415441, 120, 0, 0), -- Bloodscalp Scout (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+346, 49722, 0, 1, 1, -11737.24, 629.4396, 50.68042, 0.8710606, 120, 0, 0), -- Tree Python (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+347, 701, 0, 1, 1, -11730.63, 589.5447, 50.31595, 5.250464, 120, 0, 0), -- Bloodscalp Mystic (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+348, 595, 0, 1, 1, -11707.66, 567.6549, 49.74698, 3.303487, 120, 0, 0), -- Bloodscalp Hunter (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+349, 588, 0, 1, 1, -11699.66, 561.3246, 49.2467, 3.296505, 120, 0, 0), -- Bloodscalp Scout (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+350, 588, 0, 1, 1, -11695.34, 555.6537, 50.45227, 1.346808, 120, 0, 0), -- Bloodscalp Scout (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+351, 595, 0, 1, 1, -11686.13, 544.1885, 49.92639, 2.677945, 120, 0, 0), -- Bloodscalp Hunter (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+352, 595, 0, 1, 1, -11695.96, 544.3334, 49.81506, 1.060471, 120, 0, 0), -- Bloodscalp Hunter (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+353, 15475, 0, 1, 1, -11717.26, 567.1875, 50.54764, 3.141593, 120, 0, 0), -- Beetle (Area: Ruins of Zul'Kunda)
(@CGUID+354, 595, 0, 1, 1, -11664.52, 459.8767, 42.93834, 5.166174, 120, 0, 0), -- Bloodscalp Hunter (Area: Ruins of Zul'Kunda)
(@CGUID+355, 588, 0, 1, 1, -11646.8, 485.6988, 42.88091, 0.4222821, 120, 0, 0), -- Bloodscalp Scout (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+356, 699, 0, 1, 1, -11650.16, 463.5121, 43.09837, 4.799655, 120, 0, 0), -- Bloodscalp Beastmaster (Area: Ruins of Zul'Kunda)
(@CGUID+357, 595, 0, 1, 1, -11708.97, 552.8721, 49.56516, 5.13577, 120, 0, 0), -- Bloodscalp Hunter (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+358, 588, 0, 1, 1, -11732.32, 538.8117, 51.16355, 5.630489, 120, 0, 0), -- Bloodscalp Scout (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+359, 699, 0, 1, 1, -11729.92, 544.3246, 50.64621, 4.580831, 120, 0, 0), -- Bloodscalp Beastmaster (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+360, 50487, 0, 1, 1, -11633.57, 387.6936, 44.93719, 5.815171, 120, 0, 0), -- Forest Spiderling (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+361, 736, 0, 1, 1, -11721.8, 387.125, 47.59371, 3.258986, 120, 0, 0), -- Panther (Area: Ruins of Zul'Kunda)
(@CGUID+362, 49722, 0, 1, 1, -11715.12, 423.2541, 47.77454, 2.12629, 120, 0, 0), -- Tree Python (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+363, 736, 0, 1, 1, -11676.48, 423.8827, 43.90192, 5.200782, 120, 0, 0), -- Panther (Area: Ruins of Zul'Kunda)
(@CGUID+364, 736, 0, 1, 1, -11646.22, 324.683, 42.1095, 2.407937, 120, 0, 0), -- Panther (Area: 0)
(@CGUID+365, 43977, 0, 1, 1, -11667.3, 201.906, 43.29503, 0, 120, 0, 0), -- Tkashi Fetish (Area: 0)
(@CGUID+366, 43977, 0, 1, 1, -11684.9, 222.222, 39.71263, 0, 120, 0, 0), -- Tkashi Fetish (Area: 0)
(@CGUID+367, 43977, 0, 1, 1, -11649, 219.363, 40.21483, 0, 120, 0, 0), -- Tkashi Fetish (Area: 0)
(@CGUID+368, 702, 0, 1, 1, -11656.78, 217.9717, 39.70169, 1.777387, 120, 0, 0), -- Bloodscalp Scavenger (Area: 0) (possible waypoints or random movement)
(@CGUID+369, 736, 0, 1, 1, -11648.03, 249.4757, 37.68562, 0.4924858, 120, 0, 0), -- Panther (Area: 0)
(@CGUID+370, 702, 0, 1, 1, -11681.06, 206.5825, 43.46792, 3.718833, 120, 0, 0), -- Bloodscalp Scavenger (Area: 0) (possible waypoints or random movement)
(@CGUID+371, 50487, 0, 1, 1, -11644.13, 260.6061, 39.02287, 4.634118, 120, 0, 0), -- Forest Spiderling (Area: 0) (possible waypoints or random movement)
(@CGUID+372, 50479, 0, 1, 1, -11640.16, 101.8008, 17.80873, 2.002112, 120, 0, 0), -- Lizard Hatchling (Area: 0)
(@CGUID+373, 681, 0, 1, 1, -11648.24, 114.9949, 17.27184, 4.304953, 120, 0, 0), -- Young Stranglethorn Tiger (Area: 0)
(@CGUID+374, 9600, 0, 1, 1, -11654.38, 134.1456, 33.07541, 4.671398, 120, 0, 0), -- Parrot (Area: 0)
(@CGUID+375, 1150, 0, 1, 1, -11618.02, 14.83386, 15.24084, 3.728662, 120, 0, 0), -- River Crocolisk (Area: 0) (possible waypoints or random movement)
(@CGUID+376, 50479, 0, 1, 1, -11652.95, 18.99683, 17.26464, 4.336237, 120, 0, 0), -- Lizard Hatchling (Area: 0)
(@CGUID+377, 43049, 0, 1, 1, -11648.17, -90.79514, 16.32188, 4.625123, 120, 0, 0), -- Nesingwary Hired Gun (Area: Nesingwary's Expedition)
(@CGUID+378, 43049, 0, 1, 1, -11641.33, -32.2934, 15.34601, 1.64061, 120, 0, 0), -- Nesingwary Hired Gun (Area: Nesingwary's Expedition)
(@CGUID+379, 773, 0, 1, 1, -11649, -43.9358, 16.36213, 5.393067, 120, 0, 0), -- Krazek (Area: Nesingwary's Expedition)
(@CGUID+380, 2483, 0, 1, 1, -11650.59, -47.65972, 16.3219, 1.466077, 120, 0, 0), -- Jaquilina Dramet (Area: Nesingwary's Expedition)
(@CGUID+381, 715, 0, 1, 1, -11653.39, -61.02604, 16.31301, 2.079022, 120, 0, 0), -- Hemet Nesingwary Jr. (Area: Nesingwary's Expedition) (possible waypoints or random movement)
(@CGUID+382, 2495, 0, 1, 1, -11657.76, -46.40444, 16.31301, 5.493481, 120, 0, 0), -- Drizzlik (Area: Nesingwary's Expedition) (possible waypoints or random movement)
(@CGUID+383, 43049, 0, 1, 1, -11667.85, -64.75347, 16.66119, 2.687807, 120, 0, 0), -- Nesingwary Hired Gun (Area: Nesingwary's Expedition)
(@CGUID+384, 43049, 0, 1, 1, -11666.94, -50.94271, 16.40117, 3.420845, 120, 0, 0), -- Nesingwary Hired Gun (Area: Nesingwary's Expedition)
(@CGUID+385, 681, 0, 1, 1, -11651.25, -154.2392, 17.09771, 2.188921, 120, 0, 0), -- Young Stranglethorn Tiger (Area: Nesingwary's Expedition)
(@CGUID+386, 681, 0, 1, 1, -11677.03, -114.6699, 17.591, 0.1851988, 120, 0, 0), -- Young Stranglethorn Tiger (Area: Nesingwary's Expedition)
(@CGUID+387, 1150, 0, 1, 1, -11580.7, -148.0436, 2.777464, 0.9588395, 120, 0, 0), -- River Crocolisk (Area: Nesingwary's Expedition) (possible waypoints or random movement)
(@CGUID+388, 6827, 0, 1, 1, -11664.69, -229.7391, 18.5867, 3.605496, 120, 0, 0), -- Crab (Area: 0)
(@CGUID+389, 49928, 0, 1, 1, -11671.09, -210.9053, 46.64968, 4.041802, 120, 0, 0), -- Crimson Moth (Area: 0)
(@CGUID+390, 6827, 0, 1, 1, -11662.15, -320.6683, 13.16421, 5.768882, 120, 0, 0), -- Crab (Area: 0)
(@CGUID+391, 683, 0, 1, 1, -11522.16, -386.6057, 39.57883, 1.501029, 120, 0, 0), -- Young Panther (Area: 0)
(@CGUID+392, 683, 0, 1, 1, -11614.04, -519.5827, 20.2202, 0.2815128, 120, 0, 0), -- Young Panther (Area: 0)
(@CGUID+393, 50487, 0, 1, 1, -11655.96, -416.4971, 17.14401, 4.592883, 120, 0, 0), -- Forest Spiderling (Area: 0) (possible waypoints or random movement)
(@CGUID+394, 683, 0, 1, 1, -11648.36, -421.3776, 15.72311, 5.764284, 120, 0, 0), -- Young Panther (Area: 0)
(@CGUID+395, 683, 0, 1, 1, -11614.83, -452.4971, 16.30246, 5.287947, 120, 0, 0), -- Young Panther (Area: 0)
(@CGUID+396, 683, 0, 1, 1, -11519.6, -413.88, 36.03191, 0.6325724, 120, 0, 0), -- Young Panther (Area: 0)
(@CGUID+397, 683, 0, 1, 1, -11573.99, -490.6263, 29.31469, 5.993843, 120, 0, 0), -- Young Panther (Area: 0)
(@CGUID+398, 50487, 0, 1, 1, -11644.91, -579.1432, 30.54947, 0.5894435, 120, 0, 0), -- Forest Spiderling (Area: 0) (possible waypoints or random movement)
(@CGUID+399, 940, 0, 1, 1, -11622.65, -591.412, 27.04213, 5.312857, 120, 0, 0), -- Kurzen Medicine Man (Area: 0)
(@CGUID+400, 940, 0, 1, 1, -11653.93, -591.6685, 29.99687, 3.255679, 120, 0, 0), -- Kurzen Medicine Man (Area: 0)
(@CGUID+401, 940, 0, 1, 1, -11685.93, -583.905, 33.63872, 0.9030718, 120, 0, 0), -- Kurzen Medicine Man (Area: Kurzen's Compound)
(@CGUID+402, 32520, 0, 1, 1, -6305.162, 5582.533, -1172.063, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Kurzen's Compound)
(@CGUID+403, 32520, 0, 1, 1, -6148.39, 5539.97, -1207.787, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Kurzen's Compound)
(@CGUID+404, 32520, 0, 1, 1, -5691.65, 5556.92, -1154.687, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Kurzen's Compound)
(@CGUID+405, 32520, 0, 1, 1, -6014.71, 5479.63, -1208.007, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Kurzen's Compound)
(@CGUID+406, 937, 0, 1, 1, -11594, -619.227, 28.54313, 5.742133, 120, 0, 0), -- Kurzen Jungle Fighter (Area: Kurzen's Compound)
(@CGUID+407, 689, 0, 1, 1, -11686.14, -848.1936, 34.25528, 5.711547, 120, 0, 0), -- Crystal Spine Basilisk (Area: Kurzen's Compound) (possible waypoints or random movement)
(@CGUID+408, 689, 0, 1, 1, -11713.77, -872.5974, 32.25443, 0.3727312, 120, 0, 0), -- Crystal Spine Basilisk (Area: Kurzen's Compound) (possible waypoints or random movement)
(@CGUID+409, 689, 0, 1, 1, -11716.61, -821.9746, 35.01967, 1.796667, 120, 0, 0), -- Crystal Spine Basilisk (Area: Kurzen's Compound) (possible waypoints or random movement)
(@CGUID+410, 682, 0, 1, 1, -11715.77, -745.9595, 39.94672, 0.9226059, 120, 0, 0), -- Stranglethorn Tiger (Area: Kurzen's Compound)
(@CGUID+411, 49722, 0, 1, 1, -11723.27, -793.3088, 30.16482, 3.143546, 120, 0, 0), -- Tree Python (Area: Kurzen's Compound) (possible waypoints or random movement)
(@CGUID+412, 937, 0, 1, 1, -11718.98, -706.8348, 52.09266, 2.16313, 120, 0, 0), -- Kurzen Jungle Fighter (Area: Kurzen's Compound)
(@CGUID+413, 937, 0, 1, 1, -11579.58, -593.9979, 28.08289, 1.274647, 120, 0, 0), -- Kurzen Jungle Fighter (Area: Kurzen's Compound)
(@CGUID+414, 940, 0, 1, 1, -11585.34, -579.6632, 29.10099, 3.141593, 120, 0, 0), -- Kurzen Medicine Man (Area: Kurzen's Compound)
(@CGUID+415, 937, 0, 1, 1, -11569.25, -584.0886, 29.10099, 3.141593, 120, 0, 0), -- Kurzen Jungle Fighter (Area: Kurzen's Compound)
(@CGUID+416, 940, 0, 1, 1, -11567.25, -651.4592, 31.73199, 5.612708, 120, 0, 0), -- Kurzen Medicine Man (Area: Kurzen's Compound)
(@CGUID+417, 940, 0, 1, 1, -11585.4, -615.932, 28.54313, 0, 120, 0, 0), -- Kurzen Medicine Man (Area: Kurzen's Compound)
(@CGUID+418, 683, 0, 1, 1, -11686.4, -525.7324, 26.49426, 4.523802, 120, 0, 0), -- Young Panther (Area: Kurzen's Compound)
(@CGUID+419, 50479, 0, 1, 1, -11685.14, -481.352, 16.89917, 1.074061, 120, 0, 0), -- Lizard Hatchling (Area: Kurzen's Compound)
(@CGUID+420, 683, 0, 1, 1, -11715.57, -480.9856, 16.59456, 0.6982409, 120, 0, 0), -- Young Panther (Area: Kurzen's Compound)
(@CGUID+421, 683, 0, 1, 1, -11685.94, -447.1314, 19.32052, 2.487924, 120, 0, 0), -- Young Panther (Area: Kurzen's Compound)
(@CGUID+422, 683, 0, 1, 1, -11648.09, -479.9294, 18.99599, 1.012611, 120, 0, 0), -- Young Panther (Area: Kurzen's Compound)
(@CGUID+423, 683, 0, 1, 1, -11584.03, -412.5299, 20.84822, 2.223278, 120, 0, 0), -- Young Panther (Area: Kurzen's Compound)
(@CGUID+424, 683, 0, 1, 1, -11711.24, -420.1446, 18.94393, 6.193564, 120, 0, 0), -- Young Panther (Area: 0)
(@CGUID+425, 6827, 0, 1, 1, -11700.13, -355.7632, 11.44843, 6.12638, 120, 0, 0), -- Crab (Area: 0)
(@CGUID+426, 6827, 0, 1, 1, -11709.3, -355.041, 10.15052, 2.941134, 120, 0, 0), -- Crab (Area: 0)
(@CGUID+427, 1150, 0, 1, 1, -11692.75, -358.3813, 12.80953, 5.952783, 120, 0, 0), -- River Crocolisk (Area: 0) (possible waypoints or random movement)
(@CGUID+428, 6827, 0, 1, 1, -11684.6, -266.5144, 10.46546, 0.9302056, 120, 0, 0), -- Crab (Area: 0)
(@CGUID+429, 6827, 0, 1, 1, -11682.54, -267.8378, 8.451883, 3.430619, 120, 0, 0), -- Crab (Area: 0)
(@CGUID+430, 1150, 0, 1, 1, -11614.58, -131.4973, 16.02773, 0.2794668, 120, 0, 0), -- River Crocolisk (Area: 0) (possible waypoints or random movement)
(@CGUID+431, 681, 0, 1, 1, -11699.71, -75.38923, 17.12688, 0.6759623, 120, 0, 0), -- Young Stranglethorn Tiger (Area: Nesingwary's Expedition)
(@CGUID+432, 49928, 0, 1, 1, -11705.12, -99.84265, 33.92694, 3.989311, 120, 0, 0), -- Crimson Moth (Area: Nesingwary's Expedition)
(@CGUID+433, 1150, 0, 1, 1, -11546.91, -46.62891, 3.33939, 6.202775, 120, 0, 0), -- River Crocolisk (Area: Nesingwary's Expedition) (possible waypoints or random movement)
(@CGUID+434, 681, 0, 1, 1, -11682.15, 15.33366, 16.18243, 5.15244, 120, 0, 0), -- Young Stranglethorn Tiger (Area: Nesingwary's Expedition)
(@CGUID+435, 49928, 0, 1, 1, -11708.4, 23.04864, 35.01482, 2.983545, 120, 0, 0), -- Crimson Moth (Area: Nesingwary's Expedition)
(@CGUID+436, 681, 0, 1, 1, -11650.67, 48.646, 18.65169, 1.448623, 120, 0, 0), -- Young Stranglethorn Tiger (Area: Nesingwary's Expedition)
(@CGUID+437, 681, 0, 1, 1, -11679.3, 82.36565, 17.43142, 5.129195, 120, 0, 0), -- Young Stranglethorn Tiger (Area: Nesingwary's Expedition)
(@CGUID+438, 43977, 0, 1, 1, -11709.1, 127.189, 15.62453, 0, 120, 0, 0), -- Tkashi Fetish (Area: Nesingwary's Expedition)
(@CGUID+439, 15475, 0, 1, 1, -11688.78, 130.589, 15.88769, 2.005779, 120, 0, 0), -- Beetle (Area: Nesingwary's Expedition)
(@CGUID+440, 50487, 0, 1, 1, -11678.55, 205.0664, 43.00999, 1.568843, 120, 0, 0), -- Forest Spiderling (Area: Nesingwary's Expedition) (possible waypoints or random movement)
(@CGUID+441, 43977, 0, 1, 1, -11693.5, 160.858, 16.01463, 0, 120, 0, 0), -- Tkashi Fetish (Area: Nesingwary's Expedition)
(@CGUID+442, 702, 0, 1, 1, -11684.07, 145.8375, 16.04315, 5.589024, 120, 0, 0), -- Bloodscalp Scavenger (Area: Nesingwary's Expedition) (possible waypoints or random movement)
(@CGUID+443, 702, 0, 1, 1, -11718.9, 137.675, 16.10293, 0, 120, 0, 0), -- Bloodscalp Scavenger (Area: Nesingwary's Expedition)
(@CGUID+444, 702, 0, 1, 1, -11698.37, 230.1526, 40.7716, 4.257475, 120, 0, 0), -- Bloodscalp Scavenger (Area: 0) (possible waypoints or random movement)
(@CGUID+445, 701, 0, 1, 1, -11652.91, 374.3681, 42.73452, 0.813446, 120, 0, 0), -- Bloodscalp Mystic (Area: 0) (possible waypoints or random movement)
(@CGUID+446, 6827, 0, 1, 1, -11759.8, 1281.218, 0.8067211, 4.449648, 120, 0, 0), -- Crab (Area: The Savage Coast)
(@CGUID+447, 6827, 0, 1, 1, -11769.63, 1330.583, 3.298558, 0.1640844, 120, 0, 0), -- Crab (Area: The Savage Coast)
(@CGUID+448, 6827, 0, 1, 1, -11721.9, 1304.039, -0.9983897, 5.99979, 120, 0, 0), -- Crab (Area: The Savage Coast)
(@CGUID+449, 6827, 0, 1, 1, -11755.95, 880.5291, 2.416136, 0.1338813, 120, 0, 0), -- Crab (Area: Zuuldaia Ruins)
(@CGUID+450, 6827, 0, 1, 1, -11762.27, 923.6749, 2.667624, 1.239729, 120, 0, 0), -- Crab (Area: Zuuldaia Ruins)
(@CGUID+451, 660, 0, 1, 1, -11756.25, 891.9964, 2.770167, 2.719148, 120, 0, 0), -- Bloodscalp Witch Doctor (Area: Zuuldaia Ruins) (possible waypoints or random movement)
(@CGUID+452, 6827, 0, 1, 1, -11754.46, 969.6322, 1.60721, 3.272249, 120, 0, 0), -- Crab (Area: Zuuldaia Ruins)
(@CGUID+453, 597, 0, 1, 1, -11753.34, 941.5131, 4.564132, 4.527821, 120, 0, 0), -- Bloodscalp Berserker (Area: Zuuldaia Ruins) (possible waypoints or random movement)
(@CGUID+454, 42772, 0, 1, 1, -11764.43, 951.4114, 3.510855, 0, 120, 0, 0), -- Zuuldaian Fetish (Area: Zuuldaia Ruins)
(@CGUID+455, 701, 0, 1, 1, -11737.76, 782.473, 30.27327, 1.852434, 120, 0, 0), -- Bloodscalp Mystic (Area: Zuuldaia Ruins) (possible waypoints or random movement)
(@CGUID+456, 671, 0, 1, 1, -11762.64, 829.7917, 19.91166, 2.460914, 120, 0, 0), -- Bloodscalp Headhunter (Area: Zuuldaia Ruins)
(@CGUID+457, 42772, 0, 1, 1, -11749.49, 857.0052, 1.91939, 0, 120, 0, 0), -- Zuuldaian Fetish (Area: Zuuldaia Ruins)
(@CGUID+458, 595, 0, 1, 1, -11735.75, 684.2315, 50.5766, 0.5072267, 120, 0, 0), -- Bloodscalp Hunter (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+459, 701, 0, 1, 1, -11739.67, 596.0233, 50.57298, 3.448852, 120, 0, 0), -- Bloodscalp Mystic (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+460, 699, 0, 1, 1, -11755.05, 532.3055, 66.49136, 0.3839724, 120, 0, 0), -- Bloodscalp Beastmaster (Area: Ruins of Zul'Kunda)
(@CGUID+461, 595, 0, 1, 1, -11738.94, 554.6852, 50.80826, 0.2930943, 120, 0, 0), -- Bloodscalp Hunter (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+462, 736, 0, 1, 1, -11755.45, 411.9522, 44.06566, 3.14208, 120, 0, 0), -- Panther (Area: Ruins of Zul'Kunda)
(@CGUID+463, 736, 0, 1, 1, -11748.86, 285.6694, 18.66442, 0.8725554, 120, 0, 0), -- Panther (Area: 0)
(@CGUID+464, 736, 0, 1, 1, -11748.13, 356.2306, 40.38553, 1.011296, 120, 0, 0), -- Panther (Area: 0)
(@CGUID+465, 736, 0, 1, 1, -11712.89, 278.6096, 15.53992, 0.7153608, 120, 0, 0), -- Panther (Area: 0)
(@CGUID+466, 43977, 0, 1, 1, -11751.7, 242.608, 29.77173, 0, 120, 0, 0), -- Tkashi Fetish (Area: 0)
(@CGUID+467, 49722, 0, 1, 1, -11746.17, 196.7759, 17.08365, 5.300392, 120, 0, 0), -- Tree Python (Area: 0) (possible waypoints or random movement)
(@CGUID+468, 43977, 0, 1, 1, -11761.5, 209.158, 17.07823, 0, 120, 0, 0), -- Tkashi Fetish (Area: 0)
(@CGUID+469, 43977, 0, 1, 1, -11754.1, 175.681, 18.01153, 0, 120, 0, 0), -- Tkashi Fetish (Area: 0)
(@CGUID+470, 702, 0, 1, 1, -11748.17, 181.064, 16.66642, 4.34972, 120, 0, 0), -- Bloodscalp Scavenger (Area: 0) (possible waypoints or random movement)
(@CGUID+471, 702, 0, 1, 1, -11779.23, 212.9945, 20.84199, 2.650424, 120, 0, 0), -- Bloodscalp Scavenger (Area: 0) (possible waypoints or random movement)
(@CGUID+472, 49928, 0, 1, 1, -11705.24, 229.4099, 57.69171, 6.022703, 120, 0, 0), -- Crimson Moth (Area: 0)
(@CGUID+473, 43977, 0, 1, 1, -11733, 215.063, 39.71263, 0, 120, 0, 0), -- Tkashi Fetish (Area: 0)
(@CGUID+474, 43977, 0, 1, 1, -11707.7, 215.873, 40.13733, 0, 120, 0, 0), -- Tkashi Fetish (Area: 0)
(@CGUID+475, 43977, 0, 1, 1, -11718.6, 228.566, 40.14623, 0, 120, 0, 0), -- Tkashi Fetish (Area: 0)
(@CGUID+476, 43977, 0, 1, 1, -11718.8, 168.391, 26.94813, 0, 120, 0, 0), -- Tkashi Fetish (Area: 0)
(@CGUID+477, 702, 0, 1, 1, -11714.74, 227.0461, 40.62653, 0.8247088, 120, 0, 0), -- Bloodscalp Scavenger (Area: 0) (possible waypoints or random movement)
(@CGUID+478, 43977, 0, 1, 1, -11757.7, 87.849, 25.86923, 0, 120, 0, 0), -- Tkashi Fetish (Area: 0)
(@CGUID+479, 702, 0, 1, 1, -11754.94, 88.32002, 26.5979, 6.200302, 120, 0, 0), -- Bloodscalp Scavenger (Area: 0) (possible waypoints or random movement)
(@CGUID+480, 43977, 0, 1, 1, -11733.8, 108.144, 30.46383, 0, 120, 0, 0), -- Tkashi Fetish (Area: 0)
(@CGUID+481, 43977, 0, 1, 1, -11773.4, 120.938, 17.71073, 0, 120, 0, 0), -- Tkashi Fetish (Area: 0)
(@CGUID+482, 702, 0, 1, 1, -11752.06, 118.5632, 22.93778, 1.359866, 120, 0, 0), -- Bloodscalp Scavenger (Area: 0) (possible waypoints or random movement)
(@CGUID+483, 43977, 0, 1, 1, -11755.6, 144.198, 17.20073, 0, 120, 0, 0), -- Tkashi Fetish (Area: 0)
(@CGUID+484, 702, 0, 1, 1, -11744, 146.7413, 17.07059, 5.789282, 120, 0, 0), -- Bloodscalp Scavenger (Area: 0) (possible waypoints or random movement)
(@CGUID+485, 9600, 0, 1, 1, -11733.73, 136.1918, 36.84606, 4.09648, 120, 0, 0), -- Parrot (Area: 0)
(@CGUID+486, 681, 0, 1, 1, -11721.67, -21.55617, 17.62039, 0.6399882, 120, 0, 0), -- Young Stranglethorn Tiger (Area: 0)
(@CGUID+487, 43977, 0, 1, 1, -11750.6, 70.3594, 31.11853, 0, 120, 0, 0), -- Tkashi Fetish (Area: 0)
(@CGUID+488, 681, 0, 1, 1, -11753.78, 11.40076, 20.50286, 4.13847, 120, 0, 0), -- Young Stranglethorn Tiger (Area: 0)
(@CGUID+489, 681, 0, 1, 1, -11726.6, 46.76561, 16.00507, 0.1857297, 120, 0, 0), -- Young Stranglethorn Tiger (Area: 0)
(@CGUID+490, 50487, 0, 1, 1, -11708.82, 56.69232, 16.07985, 1.008262, 120, 0, 0), -- Forest Spiderling (Area: 0) (possible waypoints or random movement)
(@CGUID+491, 49722, 0, 1, 1, -11742.32, -70.80292, 15.79172, 3.505398, 120, 0, 0), -- Tree Python (Area: Nesingwary's Expedition) (possible waypoints or random movement)
(@CGUID+492, 681, 0, 1, 1, -11737.59, -54.64428, 16.00488, 3.101519, 120, 0, 0), -- Young Stranglethorn Tiger (Area: Nesingwary's Expedition)
(@CGUID+493, 681, 0, 1, 1, -11724, -84.97763, 7.966587, 4.728013, 120, 0, 0), -- Young Stranglethorn Tiger (Area: Nesingwary's Expedition)
(@CGUID+494, 681, 0, 1, 1, -11718.21, -172.0837, 41.03122, 5.838766, 120, 0, 0), -- Young Stranglethorn Tiger (Area: Nesingwary's Expedition)
(@CGUID+495, 683, 0, 1, 1, -11740.51, -250.3649, 29.04842, 6.029732, 120, 0, 0), -- Young Panther (Area: 0)
(@CGUID+496, 683, 0, 1, 1, -11729.89, -220.1729, 39.99224, 1.749427, 120, 0, 0), -- Young Panther (Area: 0)
(@CGUID+497, 15475, 0, 1, 1, -11731.32, -427.0854, 24.89835, 1.965437, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+498, 937, 0, 1, 1, -11575.13, -567.467, 29.58263, 3.141593, 120, 0, 0), -- Kurzen Jungle Fighter (Area: 0)
(@CGUID+499, 940, 0, 1, 1, -11638.33, -629.7822, 31.47065, 2.698882, 120, 0, 0), -- Kurzen Medicine Man (Area: Kurzen's Compound)
(@CGUID+500, 940, 0, 1, 1, -11624.3, -640.8455, 29.63983, 5.951573, 120, 0, 0), -- Kurzen Medicine Man (Area: Kurzen's Compound)
(@CGUID+501, 937, 0, 1, 1, -11657.74, -639.7991, 30.04121, 0.4482303, 120, 0, 0), -- Kurzen Jungle Fighter (Area: Kurzen's Compound)
(@CGUID+502, 937, 0, 1, 1, -11628.89, -662.5054, 31.32997, 2.372767, 120, 0, 0), -- Kurzen Jungle Fighter (Area: Kurzen's Compound)
(@CGUID+503, 689, 0, 1, 1, -11754.14, -848.079, 31.29552, 1.485354, 120, 0, 0), -- Crystal Spine Basilisk (Area: 0) (possible waypoints or random movement)
(@CGUID+504, 15475, 0, 1, 1, -11703.65, -814.0227, 35.48573, 0.009765316, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+505, 49928, 0, 1, 1, -11756.36, -793.033, 51.08131, 2.142299, 120, 0, 0), -- Crimson Moth (Area: Kurzen's Compound)
(@CGUID+506, 43050, 0, 1, 1, -11756.76, -693.7191, 33.75946, 3.739609, 120, 0, 0), -- Vale Howler (Area: Kurzen's Compound) (possible waypoints or random movement)
(@CGUID+507, 682, 0, 1, 1, -11748.04, -592.6265, 37.2102, 2.161509, 120, 0, 0), -- Stranglethorn Tiger (Area: Kurzen's Compound)
(@CGUID+508, 50479, 0, 1, 1, -11746.23, -509.3178, 17.79637, 4.563306, 120, 0, 0), -- Lizard Hatchling (Area: 0)
(@CGUID+509, 683, 0, 1, 1, -11736.74, -447.4998, 19.55467, 0.5828046, 120, 0, 0), -- Young Panther (Area: 0)
(@CGUID+510, 9600, 0, 1, 1, -11740.99, -418.3662, 36.7124, 6.044095, 120, 0, 0), -- Parrot (Area: 0)
(@CGUID+511, 1150, 0, 1, 1, -11744.33, -352.9901, 5.550776, 0.5603918, 120, 0, 0), -- River Crocolisk (Area: 0) (possible waypoints or random movement)
(@CGUID+512, 1150, 0, 1, 1, -11752.07, -394.3887, 15.80209, 4.27153, 120, 0, 0), -- River Crocolisk (Area: 0) (possible waypoints or random movement)
(@CGUID+513, 6827, 0, 1, 1, -11751.18, -369.6684, 8.742763, 3.704502, 120, 0, 0), -- Crab (Area: 0)
(@CGUID+514, 681, 0, 1, 1, -11763.04, -114.7919, 16.47295, 2.884129, 120, 0, 0), -- Young Stranglethorn Tiger (Area: 0)
(@CGUID+515, 681, 0, 1, 1, -11779.86, -20.26223, 35.39136, 3.919916, 120, 0, 0), -- Young Stranglethorn Tiger (Area: Nesingwary's Expedition)
(@CGUID+516, 43977, 0, 1, 1, -11773.3, 21.8993, 25.97053, 0, 120, 0, 0), -- Tkashi Fetish (Area: Nesingwary's Expedition)
(@CGUID+517, 43977, 0, 1, 1, -11779.1, 58.5295, 26.09813, 0, 120, 0, 0), -- Tkashi Fetish (Area: Nesingwary's Expedition)
(@CGUID+518, 43977, 0, 1, 1, -11787.2, 84.2726, 26.89353, 0, 120, 0, 0), -- Tkashi Fetish (Area: Nesingwary's Expedition)
(@CGUID+519, 736, 0, 1, 1, -11782.02, 388.0489, 44.49107, 6.130962, 120, 0, 0), -- Panther (Area: 0)
(@CGUID+520, 50487, 0, 1, 1, -11785.42, 459.9373, 47.59507, 1.805354, 120, 0, 0), -- Forest Spiderling (Area: 0) (possible waypoints or random movement)
(@CGUID+521, 685, 0, 1, 1, -11777.33, 455.6862, 49.12328, 6.164783, 120, 0, 0), -- Stranglethorn Raptor (Area: 0)
(@CGUID+522, 685, 0, 1, 1, -11772.18, 482.0473, 45.74934, 0.6826845, 120, 0, 0), -- Stranglethorn Raptor (Area: 0)
(@CGUID+523, 660, 0, 1, 1, -11777.34, 915.3131, 4.34586, 4.982813, 120, 0, 0), -- Bloodscalp Witch Doctor (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+524, 42772, 0, 1, 1, -11775.14, 906.8577, 4.305171, 0, 120, 0, 0), -- Zuuldaian Fetish (Area: Ruins of Zul'Kunda)
(@CGUID+525, 42772, 0, 1, 1, -11796.44, 866.3004, 5.013889, 0, 120, 0, 0), -- Zuuldaian Fetish (Area: Ruins of Zul'Kunda)
(@CGUID+526, 660, 0, 1, 1, -11790.79, 847.0417, 1.139133, 1.484735, 120, 0, 0), -- Bloodscalp Witch Doctor (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+527, 597, 0, 1, 1, -11794.7, 924.6927, 4.070226, 2.767065, 120, 0, 0), -- Bloodscalp Berserker (Area: Zuuldaia Ruins) (possible waypoints or random movement)
(@CGUID+528, 42772, 0, 1, 1, -11786.48, 911.4722, 4.487966, 0, 120, 0, 0), -- Zuuldaian Fetish (Area: Zuuldaia Ruins)
(@CGUID+529, 42772, 0, 1, 1, -11780.51, 934.3455, 4.441512, 0, 120, 0, 0), -- Zuuldaian Fetish (Area: Zuuldaia Ruins)
(@CGUID+530, 6827, 0, 1, 1, -11803.21, 926.9271, 3.67991, 4.649611, 120, 0, 0), -- Crab (Area: Zuuldaia Ruins)
(@CGUID+531, 42772, 0, 1, 1, -11801.71, 945.3004, 0.5403703, 0, 120, 0, 0), -- Zuuldaian Fetish (Area: Zuuldaia Ruins)
(@CGUID+532, 6827, 0, 1, 1, -11838.69, 1277.181, 2.264867, 1.666674, 120, 0, 0), -- Crab (Area: Yojamba Isle)
(@CGUID+533, 6827, 0, 1, 1, -11810.31, 1322.126, 1.006644, 1.184122, 120, 0, 0), -- Crab (Area: Yojamba Isle)
(@CGUID+534, 6827, 0, 1, 1, -11842.54, 1287.081, 2.44602, 1.416576, 120, 0, 0), -- Crab (Area: Yojamba Isle)
(@CGUID+535, 6827, 0, 1, 1, -11840.06, 1360.927, -0.8678042, 3.18678, 120, 0, 0), -- Crab (Area: Yojamba Isle)
(@CGUID+536, 6827, 0, 1, 1, -11850.89, 1337.204, -0.669806, 3.46332, 120, 0, 0), -- Crab (Area: Yojamba Isle)
(@CGUID+537, 6827, 0, 1, 1, -11845.32, 1244.807, 1.57928, 5.550365, 120, 0, 0), -- Crab (Area: Yojamba Isle)
(@CGUID+538, 32520, 0, 1, 1, -5691.65, 5556.92, -1154.687, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Yojamba Isle)
(@CGUID+539, 32520, 0, 1, 1, -6305.162, 5582.533, -1172.063, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Yojamba Isle)
(@CGUID+540, 32520, 0, 1, 1, -6148.39, 5539.97, -1207.787, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Yojamba Isle)
(@CGUID+541, 32520, 0, 1, 1, -6014.71, 5479.63, -1208.007, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Yojamba Isle)
(@CGUID+542, 597, 0, 1, 1, -11815.64, 885.3024, 4.826704, 4.100543, 120, 0, 0), -- Bloodscalp Berserker (Area: Zuuldaia Ruins) (possible waypoints or random movement)
(@CGUID+543, 42772, 0, 1, 1, -11841.72, 934.2917, -5.779994, 0, 120, 0, 0), -- Zuuldaian Fetish (Area: Zuuldaia Ruins)
(@CGUID+544, 6827, 0, 1, 1, -11819.59, 896.3188, 4.151226, 5.091792, 120, 0, 0), -- Crab (Area: Zuuldaia Ruins)
(@CGUID+545, 42772, 0, 1, 1, -11826, 889.4045, 3.844015, 0, 120, 0, 0), -- Zuuldaian Fetish (Area: Zuuldaia Ruins)
(@CGUID+546, 660, 0, 1, 1, -11818.37, 865.8759, 5.760101, 5.852757, 120, 0, 0), -- Bloodscalp Witch Doctor (Area: Zuuldaia Ruins) (possible waypoints or random movement)
(@CGUID+547, 42772, 0, 1, 1, -11838.27, 783.0226, 4.998121, 0, 120, 0, 0), -- Zuuldaian Fetish (Area: Zuuldaia Ruins)
(@CGUID+548, 660, 0, 1, 1, -11825.51, 791.2157, 4.585506, 0.5041266, 120, 0, 0), -- Bloodscalp Witch Doctor (Area: Zuuldaia Ruins) (possible waypoints or random movement)
(@CGUID+549, 6827, 0, 1, 1, -11839.09, 857.0438, 3.42944, 5.605005, 120, 0, 0), -- Crab (Area: Zuuldaia Ruins)
(@CGUID+550, 660, 0, 1, 1, -11814.1, 822.419, 1.490114, 2.859011, 120, 0, 0), -- Bloodscalp Witch Doctor (Area: Zuuldaia Ruins) (possible waypoints or random movement)
(@CGUID+551, 685, 0, 1, 1, -11826.18, 707.0494, 44.87294, 5.979755, 120, 0, 0), -- Stranglethorn Raptor (Area: Ruins of Zul'Kunda)
(@CGUID+552, 50479, 0, 1, 1, -11824.14, 691.2081, 45.03128, 1.549315, 120, 0, 0), -- Lizard Hatchling (Area: Ruins of Zul'Kunda)
(@CGUID+553, 685, 0, 1, 1, -11839.58, 662.092, 45.06305, 3.773437, 120, 0, 0), -- Stranglethorn Raptor (Area: Ruins of Zul'Kunda)
(@CGUID+554, 685, 0, 1, 1, -11817.96, 623.1454, 53.7457, 2.62899, 120, 0, 0), -- Stranglethorn Raptor (Area: Ruins of Zul'Kunda)
(@CGUID+555, 685, 0, 1, 1, -11831.98, 546.632, 44.75568, 0.2535563, 120, 0, 0), -- Stranglethorn Raptor (Area: Ruins of Zul'Kunda)
(@CGUID+556, 685, 0, 1, 1, -11816.58, 507.7544, 45.16814, 2.838358, 120, 0, 0), -- Stranglethorn Raptor (Area: Ruins of Zul'Kunda)
(@CGUID+557, 685, 0, 1, 1, -11814.25, 413.0799, 46.85937, 3.805478, 120, 0, 0), -- Stranglethorn Raptor (Area: Ruins of Zul'Kunda)
(@CGUID+558, 685, 0, 1, 1, -11810.08, 475.4671, 47.17557, 1.115882, 120, 0, 0), -- Stranglethorn Raptor (Area: Ruins of Zul'Kunda)
(@CGUID+559, 736, 0, 1, 1, -11812.65, 366.7111, 42.1786, 3.485852, 120, 0, 0), -- Panther (Area: 0)
(@CGUID+560, 15475, 0, 1, 1, -11805.39, 372.2263, 43.86476, 5.576098, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+561, 736, 0, 1, 1, -11808.8, 350.4313, 37.60453, 2.041437, 120, 0, 0), -- Panther (Area: 0)
(@CGUID+562, 736, 0, 1, 1, -11788.28, 242.7273, 16.13796, 6.094599, 120, 0, 0), -- Panther (Area: 0)
(@CGUID+563, 51663, 0, 1, 1, -11810.78, 250.5373, 15.36623, 4.13616, 120, 0, 0), -- Pogeyan (Area: 0) (possible waypoints or random movement)
(@CGUID+564, 736, 0, 1, 1, -11820.59, 284.6926, 17.04226, 5.253813, 120, 0, 0), -- Panther (Area: 0)
(@CGUID+565, 1085, 0, 1, 1, -11787.44, 177.7536, 17.64905, 3.213802, 120, 0, 0), -- Elder Stranglethorn Tiger (Area: 0)
(@CGUID+566, 43977, 0, 1, 1, -11814.2, 190.788, 15.03763, 0, 120, 0, 0), -- Tkashi Fetish (Area: 0)
(@CGUID+567, 43977, 0, 1, 1, -11783, 156.559, 17.07163, 0, 120, 0, 0), -- Tkashi Fetish (Area: 0)
(@CGUID+568, 50479, 0, 1, 1, -11829.22, 221.3667, 20.38015, 4.044718, 120, 0, 0), -- Lizard Hatchling (Area: 0)
(@CGUID+569, 1085, 0, 1, 1, -11820.72, 144.9844, 16.51859, 0.4531585, 120, 0, 0), -- Elder Stranglethorn Tiger (Area: 0)
(@CGUID+570, 702, 0, 1, 1, -11784.56, 115.8778, 18.69196, 5.128221, 120, 0, 0), -- Bloodscalp Scavenger (Area: 0) (possible waypoints or random movement)
(@CGUID+571, 43977, 0, 1, 1, -11817.7, 142.144, 16.13483, 0, 120, 0, 0), -- Tkashi Fetish (Area: 0)
(@CGUID+572, 43977, 0, 1, 1, -11805.1, 103.497, 16.61103, 0, 120, 0, 0), -- Tkashi Fetish (Area: 0)
(@CGUID+573, 702, 0, 1, 1, -11809.98, 79.71706, 17.18561, 4.078433, 120, 0, 0), -- Bloodscalp Scavenger (Area: 0) (possible waypoints or random movement)
(@CGUID+574, 43977, 0, 1, 1, -11826.2, 93.4861, 17.32413, 0, 120, 0, 0), -- Tkashi Fetish (Area: 0)
(@CGUID+575, 15475, 0, 1, 1, -11758.84, 42.46746, 16.32817, 6.247395, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+576, 702, 0, 1, 1, -11788.25, 38.25415, 16.07111, 1.726887, 120, 0, 0), -- Bloodscalp Scavenger (Area: 0) (possible waypoints or random movement)
(@CGUID+577, 702, 0, 1, 1, -11839.93, 87.16464, 17.34613, 2.697334, 120, 0, 0), -- Bloodscalp Scavenger (Area: 0) (possible waypoints or random movement)
(@CGUID+578, 43977, 0, 1, 1, -11823.5, 80.31424, 16.7225, 0, 120, 0, 0), -- Tkashi Fetish (Area: 0)
(@CGUID+579, 43977, 0, 1, 1, -11782.1, 41.5503, 16.32893, 0, 120, 0, 0), -- Tkashi Fetish (Area: 0)
(@CGUID+580, 702, 0, 1, 1, -11820.08, 53.15776, 14.88518, 5.262204, 120, 0, 0), -- Bloodscalp Scavenger (Area: 0) (possible waypoints or random movement)
(@CGUID+581, 43977, 0, 1, 1, -11813.8, 49.5278, 15.91253, 0, 120, 0, 0), -- Tkashi Fetish (Area: 0)
(@CGUID+582, 43977, 0, 1, 1, -11831.1, 65.401, 14.16043, 0, 120, 0, 0), -- Tkashi Fetish (Area: 0)
(@CGUID+583, 681, 0, 1, 1, -11819.35, -22.58948, 41.26008, 2.431567, 120, 0, 0), -- Young Stranglethorn Tiger (Area: Tkashi Ruins)
(@CGUID+584, 49928, 0, 1, 1, -11793.9, -180.7245, 31.10349, 3.924038, 120, 0, 0), -- Crimson Moth (Area: 0)
(@CGUID+585, 50479, 0, 1, 1, -11807.66, -176.9615, 15.17558, 2.196721, 120, 0, 0), -- Lizard Hatchling (Area: 0)
(@CGUID+586, 683, 0, 1, 1, -11781.92, -148.6153, 6.766985, 1.496899, 120, 0, 0), -- Young Panther (Area: 0)
(@CGUID+587, 683, 0, 1, 1, -11790.44, -186.4863, 17.3595, 1.841848, 120, 0, 0), -- Young Panther (Area: 0)
(@CGUID+588, 683, 0, 1, 1, -11819.63, -85.1121, 38.15971, 5.302108, 120, 0, 0), -- Young Panther (Area: 0)
(@CGUID+589, 683, 0, 1, 1, -11786.43, -279.164, 16.76207, 1.736968, 120, 0, 0), -- Young Panther (Area: 0)
(@CGUID+590, 683, 0, 1, 1, -11814.38, -264.8266, 19.60439, 5.062154, 120, 0, 0), -- Young Panther (Area: 0)
(@CGUID+591, 6827, 0, 1, 1, -11807.47, -326.4356, 11.74334, 1.911063, 120, 0, 0), -- Crab (Area: 0)
(@CGUID+592, 6827, 0, 1, 1, -11806.18, -324.0488, 12.10102, 3.877308, 120, 0, 0), -- Crab (Area: 0)
(@CGUID+593, 1150, 0, 1, 1, -11781.83, -324.9263, 12.72806, 3.852782, 120, 0, 0), -- River Crocolisk (Area: 0) (possible waypoints or random movement)
(@CGUID+594, 1152, 0, 1, 1, -11809.58, -367.6677, 4.305157, 0.7014367, 120, 0, 0), -- Snapjaw Crocolisk (Area: 0) (possible waypoints or random movement)
(@CGUID+595, 49722, 0, 1, 1, -11823.89, -261.4004, 17.53042, 2.134981, 120, 0, 0), -- Tree Python (Area: 0) (possible waypoints or random movement)
(@CGUID+596, 6827, 0, 1, 1, -11831.53, -422.241, 11.10212, 3.300634, 120, 0, 0), -- Crab (Area: 0)
(@CGUID+597, 6827, 0, 1, 1, -11828.04, -435.4172, 12.60089, 4.851524, 120, 0, 0), -- Crab (Area: 0)
(@CGUID+598, 49928, 0, 1, 1, -11811.94, -412.7543, 31.98671, 3.915497, 120, 0, 0), -- Crimson Moth (Area: 0)
(@CGUID+599, 1152, 0, 1, 1, -11820.3, -413.6839, 10.89801, 2.395996, 120, 0, 0), -- Snapjaw Crocolisk (Area: 0) (possible waypoints or random movement)
(@CGUID+600, 6827, 0, 1, 1, -11796.31, -387.4636, 12.31002, 4.964943, 120, 0, 0), -- Crab (Area: 0)
(@CGUID+601, 50479, 0, 1, 1, -11799.47, -553.2232, 16.16164, 0.0488847, 120, 0, 0), -- Lizard Hatchling (Area: 0)
(@CGUID+602, 682, 0, 1, 1, -11792.81, -555.4922, 15.61281, 3.893772, 120, 0, 0), -- Stranglethorn Tiger (Area: 0)
(@CGUID+603, 682, 0, 1, 1, -11808.89, -529.8489, 19.5973, 4.826356, 120, 0, 0), -- Stranglethorn Tiger (Area: 0)
(@CGUID+604, 683, 0, 1, 1, -11754.05, -511.1164, 18.74197, 4.445726, 120, 0, 0), -- Young Panther (Area: 0)
(@CGUID+605, 682, 0, 1, 1, -11816.75, -586.7762, 14.79873, 4.406706, 120, 0, 0), -- Stranglethorn Tiger (Area: 0)
(@CGUID+606, 937, 0, 1, 1, -11680.21, -585.1792, 29.78984, 5.42875, 120, 0, 0), -- Kurzen Jungle Fighter (Area: 0)
(@CGUID+607, 937, 0, 1, 1, -11655.21, -585.7894, 29.84513, 0.914699, 120, 0, 0), -- Kurzen Jungle Fighter (Area: 0)
(@CGUID+608, 682, 0, 1, 1, -11787.84, -681.0032, 40.60463, 1.940777, 120, 0, 0), -- Stranglethorn Tiger (Area: 0)
(@CGUID+609, 1096, 0, 1, 1, -11843.75, -634.259, 24.18858, 1.570796, 120, 0, 0), -- Venture Co. Geologist (Area: 0)
(@CGUID+610, 682, 0, 1, 1, -11754.96, -653.9229, 41.71553, 4.410002, 120, 0, 0), -- Stranglethorn Tiger (Area: 0)
(@CGUID+611, 49722, 0, 1, 1, -11807.51, -658.7438, 35.77782, 3.978122, 120, 0, 0), -- Tree Python (Area: 0) (possible waypoints or random movement)
(@CGUID+612, 682, 0, 1, 1, -11818.97, -653.7758, 34.05359, 3.743931, 120, 0, 0), -- Stranglethorn Tiger (Area: 0)
(@CGUID+613, 49722, 0, 1, 1, -11778.42, -703.224, 40.71615, 5.819538, 120, 0, 0), -- Tree Python (Area: 0) (possible waypoints or random movement)
(@CGUID+614, 940, 0, 1, 1, -11640.61, -663.7881, 29.81048, 0.1719903, 120, 0, 0), -- Kurzen Medicine Man (Area: 0)
(@CGUID+615, 49928, 0, 1, 1, -11807.63, -723.2592, 56.63091, 0.4052701, 120, 0, 0), -- Crimson Moth (Area: 0)
(@CGUID+616, 682, 0, 1, 1, -11785.23, -753.3195, 35.99807, 3.925828, 120, 0, 0), -- Stranglethorn Tiger (Area: 0)
(@CGUID+617, 15475, 0, 1, 1, -11844.23, -965.2574, 77.23722, 0.9731274, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+618, 15475, 0, 1, 1, -11834.58, -938.0228, 73.07609, 1.380536, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+619, 50487, 0, 1, 1, -11827.19, -882.3987, 37.50646, 3.927124, 120, 0, 0), -- Forest Spiderling (Area: 0)
(@CGUID+620, 689, 0, 1, 1, -11822.3, -898.7751, 39.00607, 3.03487, 120, 0, 0), -- Crystal Spine Basilisk (Area: 0) (possible waypoints or random movement)
(@CGUID+621, 689, 0, 1, 1, -11818.36, -849.5909, 32.8052, 4.340689, 120, 0, 0), -- Crystal Spine Basilisk (Area: 0) (possible waypoints or random movement)
(@CGUID+622, 689, 0, 1, 1, -11792.76, -862.5007, 31.15741, 2.639218, 120, 0, 0), -- Crystal Spine Basilisk (Area: 0) (possible waypoints or random movement)
(@CGUID+623, 41178, 0, 1, 1, 2918.316, -3010.901, 180.7847, 0.08726646, 120, 0, 0), -- Northwatch Tower Stalker (Area: 0)
(@CGUID+624, 682, 0, 1, 1, -11818.64, -785.4742, 35.17432, 3.590381, 120, 0, 0), -- Stranglethorn Tiger (Area: 0)
(@CGUID+625, 682, 0, 1, 1, -11820.55, -716.2192, 40.00462, 1.523656, 120, 0, 0), -- Stranglethorn Tiger (Area: 0)
(@CGUID+626, 683, 0, 1, 1, -11683.29, -516.9432, 22.42492, 2.342383, 120, 0, 0), -- Young Panther (Area: 0)
(@CGUID+627, 6827, 0, 1, 1, -11895.63, 1281.355, 1.940257, 0.8835968, 120, 0, 0), -- Crab (Area: Yojamba Isle)
(@CGUID+628, 6827, 0, 1, 1, -11857.31, 854.7271, 1.589841, 5.025757, 120, 0, 0), -- Crab (Area: Zuuldaia Ruins)
(@CGUID+629, 6827, 0, 1, 1, -11875.69, 783.2178, 1.58988, 4.82984, 120, 0, 0), -- Crab (Area: Zuuldaia Ruins)
(@CGUID+630, 685, 0, 1, 1, -11859.92, 684.8909, 46.31139, 4.974616, 120, 0, 0), -- Stranglethorn Raptor (Area: 0)
(@CGUID+631, 685, 0, 1, 1, -11846.29, 635.7038, 45.55114, 1.139564, 120, 0, 0), -- Stranglethorn Raptor (Area: Ruins of Zul'Kunda)
(@CGUID+632, 685, 0, 1, 1, -11843.51, 608.6104, 45.13775, 1.388091, 120, 0, 0), -- Stranglethorn Raptor (Area: Ruins of Zul'Kunda)
(@CGUID+633, 49722, 0, 1, 1, -11844.23, 614.5042, 46.34862, 2.393522, 120, 0, 0), -- Tree Python (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+634, 43050, 0, 1, 1, -11847.51, 579.766, 42.68344, 3.653202, 120, 0, 0), -- Vale Howler (Area: Ruins of Zul'Kunda) (possible waypoints or random movement)
(@CGUID+635, 685, 0, 1, 1, -11871.77, 576.8594, 46.03203, 3.669949, 120, 0, 0), -- Stranglethorn Raptor (Area: Ruins of Zul'Kunda)
(@CGUID+636, 685, 0, 1, 1, -11876.64, 506.7802, 45.40528, 1.220024, 120, 0, 0), -- Stranglethorn Raptor (Area: Ruins of Zul'Kunda)
(@CGUID+637, 685, 0, 1, 1, -11868.21, 526.0698, 44.75211, 2.88099, 120, 0, 0), -- Stranglethorn Raptor (Area: Ruins of Zul'Kunda)
(@CGUID+638, 50479, 0, 1, 1, -11847.37, 478.1533, 46.40068, 5.881629, 120, 0, 0), -- Lizard Hatchling (Area: Ruins of Zul'Kunda)
(@CGUID+639, 685, 0, 1, 1, -11853.9, 482.2905, 46.30003, 3.989073, 120, 0, 0), -- Stranglethorn Raptor (Area: Ruins of Zul'Kunda)
(@CGUID+640, 15475, 0, 1, 1, -11865.21, 549.3193, 47.27655, 6.279279, 120, 0, 0), -- Beetle (Area: Ruins of Zul'Kunda)
(@CGUID+641, 736, 0, 1, 1, -11840.23, 381.604, 43.03857, 1.058194, 120, 0, 0), -- Panther (Area: 0)
(@CGUID+642, 736, 0, 1, 1, -11873.05, 420.7751, 43.3385, 3.19243, 120, 0, 0), -- Panther (Area: 0)
(@CGUID+643, 49722, 0, 1, 1, -11880.34, 413.2179, 41.76472, 5.444772, 120, 0, 0), -- Tree Python (Area: 0) (possible waypoints or random movement)
(@CGUID+644, 685, 0, 1, 1, -11843.03, 426.8838, 45.98182, 0.6961015, 120, 0, 0), -- Stranglethorn Raptor (Area: 0)
(@CGUID+645, 15475, 0, 1, 1, -11853.6, 417.3978, 44.68251, 0.4995494, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+646, 49722, 0, 1, 1, -11857.6, 292.0663, 15.7924, 3.237147, 120, 0, 0), -- Tree Python (Area: 0) (possible waypoints or random movement)
(@CGUID+647, 736, 0, 1, 1, -11842.01, 308.0752, 15.56969, 4.372713, 120, 0, 0), -- Panther (Area: 0)
(@CGUID+648, 49722, 0, 1, 1, -11856.78, 306.981, 16.58239, 2.249997, 120, 0, 0), -- Tree Python (Area: 0) (possible waypoints or random movement)
(@CGUID+649, 736, 0, 1, 1, -11846.62, 252.4185, 19.67047, 2.023955, 120, 0, 0), -- Panther (Area: 0)
(@CGUID+650, 1085, 0, 1, 1, -11850.51, 183.4333, 16.10981, 5.025205, 120, 0, 0), -- Elder Stranglethorn Tiger (Area: 0)
(@CGUID+651, 43050, 0, 1, 1, -11860.98, 205.4047, 16.23717, 3.531053, 120, 0, 0), -- Vale Howler (Area: 0) (possible waypoints or random movement)
(@CGUID+652, 43977, 0, 1, 1, -11847.1, 160.634, 17.35613, 0, 120, 0, 0), -- Tkashi Fetish (Area: 0)
(@CGUID+653, 43977, 0, 1, 1, -11843.5, 125.901, 14.25113, 0, 120, 0, 0), -- Tkashi Fetish (Area: 0)
(@CGUID+654, 702, 0, 1, 1, -11842.17, 105.8587, 16.8853, 4.574337, 120, 0, 0), -- Bloodscalp Scavenger (Area: 0) (possible waypoints or random movement)
(@CGUID+655, 15475, 0, 1, 1, -11851.69, 131.1259, 14.22815, 0.7147983, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+656, 43977, 0, 1, 1, -11866.3, 102.913, 19.87193, 0, 120, 0, 0), -- Tkashi Fetish (Area: 0)
(@CGUID+657, 43977, 0, 1, 1, -11846.5, 76.4462, 18.04273, 0, 120, 0, 0), -- Tkashi Fetish (Area: 0)
(@CGUID+658, 702, 0, 1, 1, -11841.32, 64.71137, 14.3394, 0.5431842, 120, 0, 0), -- Bloodscalp Scavenger (Area: Tkashi Ruins) (possible waypoints or random movement)
(@CGUID+659, 702, 0, 1, 1, -11848.27, 53.34722, 14.93743, 0.8661382, 120, 0, 0), -- Bloodscalp Scavenger (Area: Tkashi Ruins) (possible waypoints or random movement)
(@CGUID+660, 43977, 0, 1, 1, -11836.9, 49.6111, 15.53593, 0, 120, 0, 0), -- Tkashi Fetish (Area: Tkashi Ruins)
(@CGUID+661, 43977, 0, 1, 1, -11844.7, 63.9809, 14.50183, 0, 120, 0, 0), -- Tkashi Fetish (Area: Tkashi Ruins)
(@CGUID+662, 49928, 0, 1, 1, -11847.5, 48.46301, 29.1392, 4.166942, 120, 0, 0), -- Crimson Moth (Area: Tkashi Ruins)
(@CGUID+663, 43977, 0, 1, 1, -11842.1, 34.8229, 18.81953, 0, 120, 0, 0), -- Tkashi Fetish (Area: Tkashi Ruins)
(@CGUID+664, 43977, 0, 1, 1, -11853.5, 52.6649, 15.78823, 0, 120, 0, 0), -- Tkashi Fetish (Area: Tkashi Ruins)
(@CGUID+665, 43977, 0, 1, 1, -11837.9, 24.0035, 31.18433, 0, 120, 0, 0), -- Tkashi Fetish (Area: Tkashi Ruins)
(@CGUID+666, 702, 0, 1, 1, -11854.54, 13.09071, 30.01986, 3.273122, 120, 0, 0), -- Bloodscalp Scavenger (Area: Tkashi Ruins) (possible waypoints or random movement)
(@CGUID+667, 9600, 0, 1, 1, -11820.35, -129.5013, 45.0861, 3.006493, 120, 0, 0), -- Parrot (Area: 0)
(@CGUID+668, 50487, 0, 1, 1, -11872.58, -155.7819, 13.74391, 4.563306, 120, 0, 0), -- Forest Spiderling (Area: 0) (possible waypoints or random movement)
(@CGUID+669, 681, 0, 1, 1, -11849.51, -215.9046, 16.51748, 2.243602, 120, 0, 0), -- Young Stranglethorn Tiger (Area: 0)
(@CGUID+670, 681, 0, 1, 1, -11838.02, -146.3948, 17.27639, 1.221383, 120, 0, 0), -- Young Stranglethorn Tiger (Area: 0)
(@CGUID+671, 681, 0, 1, 1, -11872.69, -126.8637, 16.04566, 5.705617, 120, 0, 0), -- Young Stranglethorn Tiger (Area: 0)
(@CGUID+672, 1152, 0, 1, 1, -11847.45, -319.5311, 11.96824, 2.355665, 120, 0, 0), -- Snapjaw Crocolisk (Area: 0) (possible waypoints or random movement)
(@CGUID+673, 681, 0, 1, 1, -11866.15, -286.7155, 17.46399, 4.712389, 120, 0, 0), -- Young Stranglethorn Tiger (Area: 0)
(@CGUID+674, 6827, 0, 1, 1, -11869.48, -312.3681, 11.66653, 4.306256, 120, 0, 0), -- Crab (Area: 0)
(@CGUID+675, 6827, 0, 1, 1, -11852.86, -327.8259, 11.0178, 2.744125, 120, 0, 0), -- Crab (Area: 0)
(@CGUID+676, 6827, 0, 1, 1, -11876.22, -473.1975, 10.85538, 0.8881791, 120, 0, 0), -- Crab (Area: 0)
(@CGUID+677, 1152, 0, 1, 1, -11876.68, -489.4146, 13.44278, 4.487787, 120, 0, 0), -- Snapjaw Crocolisk (Area: 0) (possible waypoints or random movement)
(@CGUID+678, 6827, 0, 1, 1, -11860.15, -454.9777, 11.74574, 1.107149, 120, 0, 0), -- Crab (Area: 0)
(@CGUID+679, 1152, 0, 1, 1, -11845.01, -453.5534, 12.29017, 5.742042, 120, 0, 0), -- Snapjaw Crocolisk (Area: 0) (possible waypoints or random movement)
(@CGUID+680, 1096, 0, 1, 1, -11852.42, -553.4651, 13.39748, 0.7628924, 120, 0, 0), -- Venture Co. Geologist (Area: 0)
(@CGUID+681, 50479, 0, 1, 1, -11843.08, -724.5143, 41.33685, 1.67397, 120, 0, 0), -- Lizard Hatchling (Area: 0)
(@CGUID+682, 1096, 0, 1, 1, -11876.37, -653.3666, 15.82607, 6.226495, 120, 0, 0), -- Venture Co. Geologist (Area: 0)
(@CGUID+683, 43050, 0, 1, 1, -11852.16, -759.8395, 35.13667, 3.106451, 120, 0, 0), -- Vale Howler (Area: 0) (possible waypoints or random movement)
(@CGUID+684, 682, 0, 1, 1, -11845.23, -755.8817, 36.1584, 0.1545074, 120, 0, 0), -- Stranglethorn Tiger (Area: 0)
(@CGUID+685, 15475, 0, 1, 1, -11862.72, -910.0286, 47.60705, 4.483981, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+686, 15475, 0, 1, 1, -11937.87, -860.7744, 32.44169, 2.342383, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+687, 15475, 0, 1, 1, -11941.02, -914.4264, 41.63194, 5.202385, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+688, 689, 0, 1, 1, -11874.71, -869.5237, 33.41408, 1.340488, 120, 0, 0), -- Crystal Spine Basilisk (Area: 0) (possible waypoints or random movement)
(@CGUID+689, 49928, 0, 1, 1, -11894.8, -851.2714, 52.22526, 4.143553, 120, 0, 0), -- Crimson Moth (Area: 0)
(@CGUID+690, 50487, 0, 1, 1, -11908.97, -791.8738, 31.32092, 4.027159, 120, 0, 0), -- Forest Spiderling (Area: 0) (possible waypoints or random movement)
(@CGUID+691, 49928, 0, 1, 1, -11938.82, -777.5966, 47.45782, 2.335064, 120, 0, 0), -- Crimson Moth (Area: 0)
(@CGUID+692, 682, 0, 1, 1, -11943.58, -787.8284, 28.23734, 3.302564, 120, 0, 0), -- Stranglethorn Tiger (Area: 0)
(@CGUID+693, 682, 0, 1, 1, -11913.68, -751.3926, 20.16814, 2.978693, 120, 0, 0), -- Stranglethorn Tiger (Area: 0)
(@CGUID+694, 682, 0, 1, 1, -11879.76, -780.1966, 32.90936, 1.206991, 120, 0, 0), -- Stranglethorn Tiger (Area: 0)
(@CGUID+695, 682, 0, 1, 1, -11887.51, -714.2549, 16.04038, 1.392356, 120, 0, 0), -- Stranglethorn Tiger (Area: 0)
(@CGUID+696, 1096, 0, 1, 1, -11923.82, -676.4913, 16.32476, 5.284556, 120, 0, 0), -- Venture Co. Geologist (Area: Venture Co. Base Camp)
(@CGUID+697, 50479, 0, 1, 1, -11888.15, -653.1257, 18.07745, 6.248044, 120, 0, 0), -- Lizard Hatchling (Area: Venture Co. Base Camp)
(@CGUID+698, 1096, 0, 1, 1, -11922.56, -625.4771, 15.10963, 3.063322, 120, 0, 0), -- Venture Co. Geologist (Area: Venture Co. Base Camp)
(@CGUID+699, 50487, 0, 1, 1, -11880.99, -616.1456, 15.61958, 5.719543, 120, 0, 0), -- Forest Spiderling (Area: Venture Co. Base Camp) (possible waypoints or random movement)
(@CGUID+700, 49722, 0, 1, 1, -11919.39, -579.0939, 17.01213, 6.256688, 120, 0, 0), -- Tree Python (Area: Venture Co. Base Camp) (possible waypoints or random movement)
(@CGUID+701, 1096, 0, 1, 1, -11890.13, -580.7864, 17.60612, 0.3219825, 120, 0, 0), -- Venture Co. Geologist (Area: Venture Co. Base Camp)
(@CGUID+702, 1096, 0, 1, 1, -11912.9, -561.1199, 16.36762, 3.678663, 120, 0, 0), -- Venture Co. Geologist (Area: Venture Co. Base Camp)
(@CGUID+703, 905, 0, 1, 1, -11881.58, -411.0134, -0.461367, 1.813027, 120, 0, 0), -- Sharptooth Frenzy (Area: Venture Co. Base Camp) (possible waypoints or random movement)
(@CGUID+704, 1152, 0, 1, 1, -11911.44, -452.0549, -5.133888, 5.705893, 120, 0, 0), -- Snapjaw Crocolisk (Area: Venture Co. Base Camp) (possible waypoints or random movement)
(@CGUID+705, 1152, 0, 1, 1, -11922.03, -388.5627, -14.06169, 3.469247, 120, 0, 0), -- Snapjaw Crocolisk (Area: Lake Nazferiti) (possible waypoints or random movement)
(@CGUID+706, 6827, 0, 1, 1, -11926.37, -315.5707, 7.061102, 4.853457, 120, 0, 0), -- Crab (Area: Lake Nazferiti)
(@CGUID+707, 6827, 0, 1, 1, -11887, -315.5684, 11.14536, 5.189137, 120, 0, 0), -- Crab (Area: Lake Nazferiti)
(@CGUID+708, 9600, 0, 1, 1, -11910.68, -289.0061, 30.34724, 1.347794, 120, 0, 0), -- Parrot (Area: Lake Nazferiti)
(@CGUID+709, 681, 0, 1, 1, -11927.66, -275.8638, 14.15234, 3.160661, 120, 0, 0), -- Young Stranglethorn Tiger (Area: Lake Nazferiti)
(@CGUID+710, 1152, 0, 1, 1, -11916.91, -318.4389, 7.775997, 3.897474, 120, 0, 0), -- Snapjaw Crocolisk (Area: Lake Nazferiti) (possible waypoints or random movement)
(@CGUID+711, 9600, 0, 1, 1, -11902.03, -240.3596, 34.29198, 1.061365, 120, 0, 0), -- Parrot (Area: Lake Nazferiti)
(@CGUID+712, 681, 0, 1, 1, -11885.54, -253.0658, 16.89792, 0.2171996, 120, 0, 0), -- Young Stranglethorn Tiger (Area: Lake Nazferiti)
(@CGUID+713, 9600, 0, 1, 1, -11930.13, -184.3045, 32.02908, 0.5693961, 120, 0, 0), -- Parrot (Area: 0)
(@CGUID+714, 43050, 0, 1, 1, -11926.48, -196.3819, 13.88052, 5.256494, 120, 0, 0), -- Vale Howler (Area: 0) (possible waypoints or random movement)
(@CGUID+715, 681, 0, 1, 1, -11916.28, -152.5317, 12.21272, 3.066533, 120, 0, 0), -- Young Stranglethorn Tiger (Area: 0)
(@CGUID+716, 681, 0, 1, 1, -11915.64, -214.3227, 16.95585, 2.189683, 120, 0, 0), -- Young Stranglethorn Tiger (Area: 0)
(@CGUID+717, 681, 0, 1, 1, -11884.83, -169.8269, 18.73596, 2.094029, 120, 0, 0), -- Young Stranglethorn Tiger (Area: 0)
(@CGUID+718, 681, 0, 1, 1, -11892.81, -76.00821, 36.79028, 2.604728, 120, 0, 0), -- Young Stranglethorn Tiger (Area: 0)
(@CGUID+719, 681, 0, 1, 1, -11870.33, -20.45989, 39.23717, 5.786593, 120, 0, 0), -- Young Stranglethorn Tiger (Area: 0)
(@CGUID+720, 681, 0, 1, 1, -11916.57, 5.213532, 29.68956, 4.414753, 120, 0, 0), -- Young Stranglethorn Tiger (Area: 0)
(@CGUID+721, 702, 0, 1, 1, -11883.13, 51.70898, 19.72604, 3.300325, 120, 0, 0), -- Bloodscalp Scavenger (Area: 0) (possible waypoints or random movement)
(@CGUID+722, 43977, 0, 1, 1, -11880.1, 41.5313, 23.17423, 0, 120, 0, 0), -- Tkashi Fetish (Area: 0)
(@CGUID+723, 50479, 0, 1, 1, -11920.56, 26.74176, 19.62578, 0.2871537, 120, 0, 0), -- Lizard Hatchling (Area: 0)
(@CGUID+724, 43977, 0, 1, 1, -11864.5, 64.1285, 15.56613, 0, 120, 0, 0), -- Tkashi Fetish (Area: 0)
(@CGUID+725, 49928, 0, 1, 1, -11899.74, 62.33288, 30.59173, 2.736764, 120, 0, 0), -- Crimson Moth (Area: 0)
(@CGUID+726, 702, 0, 1, 1, -11868.76, 94.62019, 21.18254, 4.202685, 120, 0, 0), -- Bloodscalp Scavenger (Area: 0) (possible waypoints or random movement)
(@CGUID+727, 4461, 0, 1, 1, -11944.44, 94.28571, 15.8237, 2.056274, 120, 0, 0), -- Murkgill Warrior (Area: Tkashi Ruins) (possible waypoints or random movement)
(@CGUID+728, 702, 0, 1, 1, -11895.54, 79.78876, 16.72622, 4.161339, 120, 0, 0), -- Bloodscalp Scavenger (Area: Tkashi Ruins) (possible waypoints or random movement)
(@CGUID+729, 1085, 0, 1, 1, -11921.26, 109.6346, 17.62184, 3.064775, 120, 0, 0), -- Elder Stranglethorn Tiger (Area: Tkashi Ruins)
(@CGUID+730, 49722, 0, 1, 1, -11938.39, 101.4689, 17.24393, 0.4015559, 120, 0, 0), -- Tree Python (Area: Tkashi Ruins) (possible waypoints or random movement)
(@CGUID+731, 9600, 0, 1, 1, -11885.39, 232.2944, 38.69111, 2.470594, 120, 0, 0), -- Parrot (Area: Tkashi Ruins)
(@CGUID+732, 729, 0, 1, 1, -11906.8, 165.954, 41.42221, 0.9901873, 120, 0, 0), -- Sin'Dall (Area: Tkashi Ruins)
(@CGUID+733, 1085, 0, 1, 1, -11886.45, 219.335, 16.67147, 2.290253, 120, 0, 0), -- Elder Stranglethorn Tiger (Area: Tkashi Ruins)
(@CGUID+734, 32520, 0, 1, 1, -6014.71, 5479.63, -1208.007, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Tkashi Ruins)
(@CGUID+735, 32520, 0, 1, 1, -5691.65, 5556.92, -1154.687, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Tkashi Ruins)
(@CGUID+736, 32520, 0, 1, 1, -6148.39, 5539.97, -1207.787, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Tkashi Ruins)
(@CGUID+737, 32520, 0, 1, 1, -6305.162, 5582.533, -1172.063, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Tkashi Ruins)
(@CGUID+738, 1085, 0, 1, 1, -11911.97, 245.7737, 19.15852, 1.837562, 120, 0, 0), -- Elder Stranglethorn Tiger (Area: 0)
(@CGUID+739, 49928, 0, 1, 1, -11915.68, 250.7359, 35.50919, 0.1883497, 120, 0, 0), -- Crimson Moth (Area: 0)
(@CGUID+740, 697, 0, 1, 1, -11921.76, 330.0462, 5.223028, 4.744383, 120, 0, 0), -- Bloodscalp Shaman (Area: 0) (possible waypoints or random movement)
(@CGUID+741, 697, 0, 1, 1, -11887.29, 279.8482, 12.42812, 1.539823, 120, 0, 0), -- Bloodscalp Shaman (Area: 0) (possible waypoints or random movement)
(@CGUID+742, 587, 0, 1, 1, -11939, 271.2745, 14.01242, 6.09306, 120, 0, 0), -- Bloodscalp Warrior (Area: 0) (possible waypoints or random movement)
(@CGUID+743, 587, 0, 1, 1, -11942.13, 361.6144, 1.772414, 5.37302, 120, 0, 0), -- Bloodscalp Warrior (Area: 0) (possible waypoints or random movement)
(@CGUID+744, 685, 0, 1, 1, -11885.79, 447.8903, 43.55436, 3.198782, 120, 0, 0), -- Stranglethorn Raptor (Area: 0)
(@CGUID+745, 685, 0, 1, 1, -11912.36, 454.4635, 45.31069, 1.182796, 120, 0, 0), -- Stranglethorn Raptor (Area: 0)
(@CGUID+746, 685, 0, 1, 1, -11920.83, 495.834, 45.07778, 4.655908, 120, 0, 0), -- Stranglethorn Raptor (Area: 0)
(@CGUID+747, 689, 0, 1, 1, -11940.04, 555.743, 24.73139, 1.0891, 120, 0, 0), -- Crystal Spine Basilisk (Area: 0) (possible waypoints or random movement)
(@CGUID+748, 689, 0, 1, 1, -11917.62, 620.5629, 21.89675, 0.028199, 120, 0, 0), -- Crystal Spine Basilisk (Area: 0) (possible waypoints or random movement)
(@CGUID+749, 689, 0, 1, 1, -11885.23, 637.2643, 26.83701, 4.35244, 120, 0, 0), -- Crystal Spine Basilisk (Area: 0) (possible waypoints or random movement)
(@CGUID+750, 689, 0, 1, 1, -11945.11, 651.0017, 1.464396, 4.950929, 120, 0, 0), -- Crystal Spine Basilisk (Area: 0) (possible waypoints or random movement)
(@CGUID+751, 689, 0, 1, 1, -11891.95, 661.0128, 23.87839, 4.745582, 120, 0, 0), -- Crystal Spine Basilisk (Area: 0) (possible waypoints or random movement)
(@CGUID+752, 6827, 0, 1, 1, -11938.13, 679.2745, 2.570445, 3.560265, 120, 0, 0), -- Crab (Area: 0)
(@CGUID+753, 689, 0, 1, 1, -11884.17, 718.0739, 27.50133, 4.296569, 120, 0, 0), -- Crystal Spine Basilisk (Area: 0) (possible waypoints or random movement)
(@CGUID+754, 689, 0, 1, 1, -11915.2, 683.9066, 7.081137, 1.886132, 120, 0, 0), -- Crystal Spine Basilisk (Area: 0) (possible waypoints or random movement)
(@CGUID+755, 689, 0, 1, 1, -11915.15, 745.3882, 1.723431, 4.645951, 120, 0, 0), -- Crystal Spine Basilisk (Area: 0) (possible waypoints or random movement)
(@CGUID+756, 6827, 0, 1, 1, -11947.73, 674.8251, 2.799571, 1.753297, 120, 0, 0), -- Crab (Area: 0)
(@CGUID+757, 6827, 0, 1, 1, -11900.59, 842.4611, 1.327482, 0.1510154, 120, 0, 0), -- Crab (Area: 0)
(@CGUID+758, 6827, 0, 1, 1, -11921.86, 803.0446, 3.595341, 2.731541, 120, 0, 0), -- Crab (Area: 0)
(@CGUID+759, 6827, 0, 1, 1, -11946.99, 835.7401, -0.6159427, 5.64203, 120, 0, 0), -- Crab (Area: The Savage Coast)
(@CGUID+760, 689, 0, 1, 1, -11956.1, 488.332, 24.6235, 3.018207, 120, 0, 0), -- Crystal Spine Basilisk (Area: 0) (possible waypoints or random movement)
(@CGUID+761, 689, 0, 1, 1, -11934.14, 559.8392, 23.86628, 0.7378622, 120, 0, 0), -- Crystal Spine Basilisk (Area: 0) (possible waypoints or random movement)
(@CGUID+762, 49722, 0, 1, 1, -11957.28, 222.502, 14.96056, 4.531837, 120, 0, 0), -- Tree Python (Area: 0) (possible waypoints or random movement)
(@CGUID+763, 1085, 0, 1, 1, -11951.72, 215.1433, 14.97831, 3.93804, 120, 0, 0), -- Elder Stranglethorn Tiger (Area: 0)
(@CGUID+764, 1085, 0, 1, 1, -11953.11, 178.4762, 15.39723, 1.250695, 120, 0, 0), -- Elder Stranglethorn Tiger (Area: 0)
(@CGUID+765, 4457, 0, 1, 1, -11945.26, 44.17392, 16.90373, 4.154204, 120, 0, 0), -- Murkgill Forager (Area: Tkashi Ruins) (possible waypoints or random movement)
(@CGUID+766, 681, 0, 1, 1, -11941, -178.5618, 19.48884, 0.4301272, 120, 0, 0), -- Young Stranglethorn Tiger (Area: 0)
(@CGUID+767, 49722, 0, 1, 1, -11961.98, -973.3695, 71.77117, 3.366195, 120, 0, 0), -- Tree Python (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+768, 9600, 0, 1, 1, -11969.83, -883.5859, 57.32419, 2.026779, 120, 0, 0), -- Parrot (Area: 0)
(@CGUID+769, 1096, 0, 1, 1, -11969.1, -831.5329, 31.52464, 5.263505, 120, 0, 0), -- Venture Co. Geologist (Area: 0)
(@CGUID+770, 50479, 0, 1, 1, -11956.27, -770.0605, 21.85851, 0.6454543, 120, 0, 0), -- Lizard Hatchling (Area: 0)
(@CGUID+771, 1096, 0, 1, 1, -11950.48, -705.433, 17.57495, 4.571321, 120, 0, 0), -- Venture Co. Geologist (Area: 0)
(@CGUID+772, 50487, 0, 1, 1, -11972.94, -598.2369, 14.75289, 5.030086, 120, 0, 0), -- Forest Spiderling (Area: Venture Co. Base Camp) (possible waypoints or random movement)
(@CGUID+773, 1096, 0, 1, 1, -11978.8, -611.8026, 16.50326, 0.8157756, 120, 0, 0), -- Venture Co. Geologist (Area: Venture Co. Base Camp)
(@CGUID+774, 43003, 0, 1, 1, -11988.36, -553.2986, 13.65596, 0, 120, 0, 0), -- Venture Co. Sawblade (Area: Venture Co. Base Camp)
(@CGUID+775, 43003, 0, 1, 1, -11988.26, -541.9305, 13.48378, 0, 120, 0, 0), -- Venture Co. Sawblade (Area: Venture Co. Base Camp)
(@CGUID+776, 43003, 0, 1, 1, -11988.38, -543.3889, 13.47151, 0, 120, 0, 0), -- Venture Co. Sawblade (Area: Venture Co. Base Camp)
(@CGUID+777, 43003, 0, 1, 1, -11988.33, -554.4965, 13.48225, 0, 120, 0, 0), -- Venture Co. Sawblade (Area: Venture Co. Base Camp)
(@CGUID+778, 1096, 0, 1, 1, -11991.46, -547.5585, 13.48055, 0.2268928, 120, 0, 0), -- Venture Co. Geologist (Area: Venture Co. Base Camp)
(@CGUID+779, 921, 0, 1, 1, -11994.02, -551.22, 13.49717, 0.6806784, 120, 0, 0), -- Venture Co. Lumberjack (Area: Venture Co. Base Camp)
(@CGUID+780, 4260, 0, 1, 1, -11971.11, -574.1805, 12.99313, 6.240433, 120, 0, 0), -- Venture Co. Shredder (Area: Venture Co. Base Camp)
(@CGUID+781, 6827, 0, 1, 1, -11962.47, -495.4897, 9.894507, 6.274161, 120, 0, 0), -- Crab (Area: Venture Co. Base Camp)
(@CGUID+782, 4723, 0, 1, 1, -11949.48, -500.3925, 30.70138, 5.061455, 120, 0, 0), -- Foreman Cozzle (Area: Venture Co. Base Camp)
(@CGUID+783, 1096, 0, 1, 1, -11958.18, -483.9653, 17.07956, 0.08630131, 120, 0, 0), -- Venture Co. Geologist (Area: Venture Co. Base Camp)
(@CGUID+784, 1096, 0, 1, 1, -11959.25, -498.7295, 30.48008, 0.8555459, 120, 0, 0), -- Venture Co. Geologist (Area: Venture Co. Base Camp)
(@CGUID+785, 1096, 0, 1, 1, -11948.78, -502.1597, 17.0727, 0.627038, 120, 0, 0), -- Venture Co. Geologist (Area: Venture Co. Base Camp)
(@CGUID+786, 921, 0, 1, 1, -11984.06, -526.2552, 12.05152, 4.712389, 120, 0, 0), -- Venture Co. Lumberjack (Area: Venture Co. Base Camp)
(@CGUID+787, 1097, 0, 1, 1, -11979.13, -525.4636, 12.05267, 4.712389, 120, 0, 0), -- Venture Co. Mechanic (Area: Venture Co. Base Camp)
(@CGUID+788, 1096, 0, 1, 1, -11977.63, -532.5695, 12.05513, 4.712389, 120, 0, 0), -- Venture Co. Geologist (Area: Venture Co. Base Camp)
(@CGUID+789, 905, 0, 1, 1, -11948.05, -482.8573, 5.96775, 2.995127, 120, 0, 0), -- Sharptooth Frenzy (Area: Venture Co. Base Camp) (possible waypoints or random movement)
(@CGUID+790, 1152, 0, 1, 1, -11986.25, -413.2047, -14.13443, 2.7195, 120, 0, 0), -- Snapjaw Crocolisk (Area: Venture Co. Base Camp) (possible waypoints or random movement)
(@CGUID+791, 1097, 0, 1, 1, -11947.34, -462.2284, 17.09153, 3.240558, 120, 0, 0), -- Venture Co. Mechanic (Area: Venture Co. Base Camp)
(@CGUID+792, 1096, 0, 1, 1, -11981.64, -488.766, 24.22995, 3.496606, 120, 0, 0), -- Venture Co. Geologist (Area: Venture Co. Base Camp)
(@CGUID+793, 1097, 0, 1, 1, -11954.51, -463.4667, 30.45793, 5.647071, 120, 0, 0), -- Venture Co. Mechanic (Area: Venture Co. Base Camp)
(@CGUID+794, 6827, 0, 1, 1, -11987.49, -490.0558, 10.21696, 0.2046779, 120, 0, 0), -- Crab (Area: Venture Co. Base Camp)
(@CGUID+795, 1152, 0, 1, 1, -11993.12, -357.2832, 10.40786, 0, 120, 0, 0), -- Snapjaw Crocolisk (Area: Lake Nazferiti) (possible waypoints or random movement)
(@CGUID+796, 49928, 0, 1, 1, -11952.67, -205.1225, 27.19123, 2.208304, 120, 0, 0), -- Crimson Moth (Area: Lake Nazferiti)
(@CGUID+797, 50479, 0, 1, 1, -11958.99, -259.2054, 16.13763, 2.9953, 120, 0, 0), -- Lizard Hatchling (Area: Lake Nazferiti)
(@CGUID+798, 681, 0, 1, 1, -11948.92, -251.4861, 14.74872, 0.5402403, 120, 0, 0), -- Young Stranglethorn Tiger (Area: Lake Nazferiti)
(@CGUID+799, 686, 0, 1, 1, -11980.85, -217.9741, 18.50737, 5.917996, 120, 0, 0), -- Lashtail Raptor (Area: Lake Nazferiti)
(@CGUID+800, 49928, 0, 1, 1, -11962.8, -149.4758, 32.52838, 3.716044, 120, 0, 0), -- Crimson Moth (Area: 0)
(@CGUID+801, 681, 0, 1, 1, -11945.66, -117.909, 8.056755, 3.36429, 120, 0, 0), -- Young Stranglethorn Tiger (Area: 0)
(@CGUID+802, 1085, 0, 1, 1, -11954.01, -45.98535, 15.80527, 5.325753, 120, 0, 0), -- Elder Stranglethorn Tiger (Area: 0)
(@CGUID+803, 1085, 0, 1, 1, -11975.99, -79.76756, 5.828429, 4.179868, 120, 0, 0), -- Elder Stranglethorn Tiger (Area: 0)
(@CGUID+804, 43050, 0, 1, 1, -11973.35, -25.3588, 13.86944, 1.785438, 120, 0, 0), -- Vale Howler (Area: 0) (possible waypoints or random movement)
(@CGUID+805, 1085, 0, 1, 1, -11981.19, -22.97326, 14.29778, 4.775165, 120, 0, 0), -- Elder Stranglethorn Tiger (Area: 0)
(@CGUID+806, 4458, 0, 1, 1, -11976.77, 26.53895, 14.73994, 3.357785, 120, 0, 0), -- Murkgill Hunter (Area: 0) (possible waypoints or random movement)
(@CGUID+807, 50479, 0, 1, 1, -11984.61, 52.0237, 9.620333, 4.709707, 120, 0, 0), -- Lizard Hatchling (Area: 0)
(@CGUID+808, 4461, 0, 1, 1, -11981.8, 77.07219, 9.801026, 2.400365, 120, 0, 0), -- Murkgill Warrior (Area: 0) (possible waypoints or random movement)
(@CGUID+809, 4461, 0, 1, 1, -11976.78, 109.2151, 8.744095, 0.4744133, 120, 0, 0), -- Murkgill Warrior (Area: Tkashi Ruins) (possible waypoints or random movement)
(@CGUID+810, 587, 0, 1, 1, -11989.41, 260.9892, 15.42542, 0.499512, 120, 0, 0), -- Bloodscalp Warrior (Area: 0) (possible waypoints or random movement)
(@CGUID+811, 1085, 0, 1, 1, -11988.79, 177.6214, 13.30107, 2.923845, 120, 0, 0), -- Elder Stranglethorn Tiger (Area: 0)
(@CGUID+812, 587, 0, 1, 1, -11980.5, 313.0907, 3.220866, 4.801672, 120, 0, 0), -- Bloodscalp Warrior (Area: 0)
(@CGUID+813, 694, 0, 1, 1, -11994.98, 337.1276, 2.00929, 1.135295, 120, 0, 0), -- Bloodscalp Axe Thrower (Area: 0) (possible waypoints or random movement)
(@CGUID+814, 697, 0, 1, 1, -11993.74, 323.7261, 2.199382, 5.292131, 120, 0, 0), -- Bloodscalp Shaman (Area: 0) (possible waypoints or random movement)
(@CGUID+815, 587, 0, 1, 1, -11989.01, 389.3294, 1.485246, 2.423864, 120, 0, 0), -- Bloodscalp Warrior (Area: 0) (possible waypoints or random movement)
(@CGUID+816, 50487, 0, 1, 1, -11987.3, 399.373, 1.841027, 1.330083, 120, 0, 0), -- Forest Spiderling (Area: 0) (possible waypoints or random movement)
(@CGUID+817, 587, 0, 1, 1, -11993.79, 365.2446, 3.731458, 4.647281, 120, 0, 0), -- Bloodscalp Warrior (Area: 0) (possible waypoints or random movement)
(@CGUID+818, 6827, 0, 1, 1, -11979.44, 553.5971, 1.343463, 5.103619, 120, 0, 0), -- Crab (Area: 0)
(@CGUID+819, 6827, 0, 1, 1, -12009.36, 601.1556, 3.35545, 1.627463, 120, 0, 0), -- Crab (Area: 0)
(@CGUID+820, 6827, 0, 1, 1, -11988.23, 608.3687, 1.951355, 2.223222, 120, 0, 0), -- Crab (Area: 0)
(@CGUID+821, 6827, 0, 1, 1, -11991.37, 775.2492, 4.628062, 6.135388, 120, 0, 0), -- Crab (Area: The Savage Coast)
(@CGUID+822, 32520, 0, 1, 1, -5691.65, 5556.92, -1154.687, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Savage Coast)
(@CGUID+823, 32520, 0, 1, 1, -6014.71, 5479.63, -1208.007, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Savage Coast)
(@CGUID+824, 32520, 0, 1, 1, -6305.162, 5582.533, -1172.063, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Savage Coast)
(@CGUID+825, 32520, 0, 1, 1, -6148.39, 5539.97, -1207.787, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Savage Coast)
(@CGUID+826, 6827, 0, 1, 1, -12061.47, 971.8796, 3.842204, 1.315404, 120, 0, 0), -- Crab (Area: The Savage Coast)
(@CGUID+827, 6827, 0, 1, 1, -12079.89, 913.0818, 4.004065, 2.750742, 120, 0, 0), -- Crab (Area: The Savage Coast)
(@CGUID+828, 691, 0, 1, 1, -12081.53, 916.9611, 4.344519, 2.930912, 120, 0, 0), -- Lesser Water Elemental (Area: The Savage Coast) (possible waypoints or random movement)
(@CGUID+829, 691, 0, 1, 1, -12084.81, 950.9083, 5.774161, 2.546707, 120, 0, 0), -- Lesser Water Elemental (Area: The Savage Coast) (possible waypoints or random movement)
(@CGUID+830, 694, 0, 1, 1, -12023.33, 385.8773, 1.993985, 1.783144, 120, 0, 0), -- Bloodscalp Axe Thrower (Area: 0) (possible waypoints or random movement)
(@CGUID+831, 6827, 0, 1, 1, -12009.25, 382.946, 1.435353, 5.094846, 120, 0, 0), -- Crab (Area: 0)
(@CGUID+832, 6827, 0, 1, 1, -12046.83, 458.2428, 6.144785, 5.983681, 120, 0, 0), -- Crab (Area: 0)
(@CGUID+833, 42762, 0, 1, 1, -12033.1, 360.712, 1.052849, 0, 120, 0, 0), -- Mandokir Skull Pile Bunny (Area: 0)
(@CGUID+834, 694, 0, 1, 1, -12007.54, 313.3552, 2.46076, 0.6109611, 120, 0, 0), -- Bloodscalp Axe Thrower (Area: 0) (possible waypoints or random movement)
(@CGUID+835, 694, 0, 1, 1, -12022.7, 354.2861, 0.7767994, 0.7244295, 120, 0, 0), -- Bloodscalp Axe Thrower (Area: 0) (possible waypoints or random movement)
(@CGUID+836, 6827, 0, 1, 1, -12050.87, 380.7451, 1.936511, 1.841848, 120, 0, 0), -- Crab (Area: 0)
(@CGUID+837, 50479, 0, 1, 1, -12019.96, 252.6761, 10.87362, 0.2129601, 120, 0, 0), -- Lizard Hatchling (Area: Bal'lal Ruins)
(@CGUID+838, 9600, 0, 1, 1, -12026.29, 186.0422, 35.38894, 5.873255, 120, 0, 0), -- Parrot (Area: 0)
(@CGUID+839, 1085, 0, 1, 1, -12009.81, 211.5023, 17.11451, 6.028366, 120, 0, 0), -- Elder Stranglethorn Tiger (Area: 0)
(@CGUID+840, 1085, 0, 1, 1, -12020.51, 146.503, 18.45408, 3.922899, 120, 0, 0), -- Elder Stranglethorn Tiger (Area: 0)
(@CGUID+841, 49722, 0, 1, 1, -12012.26, 180.0055, 16.14835, 3.382306, 120, 0, 0), -- Tree Python (Area: 0) (possible waypoints or random movement)
(@CGUID+842, 1085, 0, 1, 1, -11953.17, 151.0473, 21.56146, 2.664011, 120, 0, 0), -- Elder Stranglethorn Tiger (Area: 0)
(@CGUID+843, 4457, 0, 1, 1, -12023.67, 105.8798, 4.734845, 5.018072, 120, 0, 0), -- Murkgill Forager (Area: 0) (possible waypoints or random movement)
(@CGUID+844, 49722, 0, 1, 1, -12023.25, 105.7013, 4.722132, 1.91098, 120, 0, 0), -- Tree Python (Area: 0) (possible waypoints or random movement)
(@CGUID+845, 4457, 0, 1, 1, -12020.65, 61.353, 3.083533, 5.149842, 120, 0, 0), -- Murkgill Forager (Area: 0) (possible waypoints or random movement)
(@CGUID+846, 50479, 0, 1, 1, -12011.38, -24.62583, 19.05968, 3.849584, 120, 0, 0), -- Lizard Hatchling (Area: 0)
(@CGUID+847, 49722, 0, 1, 1, -11991.42, -682.2647, 13.05723, 1.591393, 120, 0, 0), -- Tree Python (Area: Venture Co. Base Camp) (possible waypoints or random movement)
(@CGUID+848, 1096, 0, 1, 1, -11982.78, -692.039, 12.5462, 5.172292, 120, 0, 0), -- Venture Co. Geologist (Area: Venture Co. Base Camp)
(@CGUID+849, 1096, 0, 1, 1, -11985.42, -757.3561, 16.33511, 3.897954, 120, 0, 0), -- Venture Co. Geologist (Area: Venture Co. Base Camp)
(@CGUID+850, 50487, 0, 1, 1, -11902.35, -1351.811, 73.62958, 6.153748, 120, 0, 0), -- Forest Spiderling (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+851, 49722, 0, 1, 1, -11840.24, -1314.227, 68.93488, 0.2445052, 120, 0, 0), -- Tree Python (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+852, 49722, 0, 1, 1, -11937.63, -1540.322, 40.76715, 4.60281, 120, 0, 0), -- Tree Python (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+853, 50487, 0, 1, 1, -11819.33, -1506.619, 25.99871, 1.177958, 120, 0, 0), -- Forest Spiderling (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+854, 3300, 0, 1, 1, -11978.5, -1680.912, 32.37836, 5.6065, 120, 0, 0), -- Adder (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+855, 3300, 0, 1, 1, -11984, -1671.37, 32.37836, 1.095398, 120, 0, 0), -- Adder (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+856, 2914, 0, 1, 1, -11980.76, -1640.177, 34.48043, 3.722913, 120, 0, 0), -- Snake (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+857, 3300, 0, 1, 1, -11988.28, -1648.888, 34.1086, 0.088434, 120, 0, 0), -- Adder (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+858, 4953, 0, 1, 1, -11970.88, -1688.797, 32.37836, 5.294942, 120, 0, 0), -- Moccasin (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+859, 4953, 0, 1, 1, -11974.15, -1695.183, 32.37836, 4.706594, 120, 0, 0), -- Moccasin (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+860, 4953, 0, 1, 1, -11976.13, -1689.009, 32.18011, 1.397477, 120, 0, 0), -- Moccasin (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+861, 50487, 0, 1, 1, -11851.78, -1698.539, 18.56732, 3.125969, 120, 0, 0), -- Forest Spiderling (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+862, 50487, 0, 1, 1, -11936.6, -1779.76, 52.14627, 5.463272, 120, 0, 0), -- Forest Spiderling (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+863, 50487, 0, 1, 1, -11867.16, -1838.03, 64.25127, 4.451787, 120, 0, 0), -- Forest Spiderling (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+864, 3300, 0, 1, 1, -11978.43, -1713.105, 32.35986, 1.549895, 120, 0, 0), -- Adder (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+865, 2914, 0, 1, 1, -11974.77, -1704.057, 32.35986, 2.218666, 120, 0, 0), -- Snake (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+866, 4953, 0, 1, 1, -11979.04, -1695.994, 32.37836, 0.9055102, 120, 0, 0), -- Moccasin (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+867, 50479, 0, 1, 1, -11988.1, -1719.721, 32.35986, 1.76267, 120, 0, 0), -- Lizard Hatchling (Area: Zul'Gurub)
(@CGUID+868, 50479, 0, 1, 1, -11874.11, -1922.021, 64.38812, 2.214662, 120, 0, 0), -- Lizard Hatchling (Area: Zul'Gurub)
(@CGUID+869, 15475, 0, 1, 1, -11950.42, -1844.526, 55.87164, 3.612233, 120, 0, 0), -- Beetle (Area: Zul'Gurub)
(@CGUID+870, 15475, 0, 1, 1, -11827.82, -1857.628, 52.71338, 3.850131, 120, 0, 0), -- Beetle (Area: Zul'Gurub)
(@CGUID+871, 15475, 0, 1, 1, -11712.51, -1919.318, 55.8304, 1.556226, 120, 0, 0), -- Beetle (Area: Zul'Gurub)
(@CGUID+872, 50479, 0, 1, 1, -11728.17, -1911.181, 56.7421, 1.767426, 120, 0, 0), -- Lizard Hatchling (Area: Zul'Gurub)
(@CGUID+873, 50487, 0, 1, 1, -11755.96, -1846.487, 40.39143, 0.2395407, 120, 0, 0), -- Forest Spiderling (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+874, 49722, 0, 1, 1, -11726.89, -1698.017, 17.19102, 3.365134, 120, 0, 0), -- Tree Python (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+875, 49722, 0, 1, 1, -11761.69, -1559.209, 18.647, 4.551418, 120, 0, 0), -- Tree Python (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+876, 49722, 0, 1, 1, -11781.56, -1492.195, 36.33501, 0.6020862, 120, 0, 0), -- Tree Python (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+877, 50487, 0, 1, 1, -11628.31, -1407.813, 65.04484, 0, 120, 0, 0), -- Forest Spiderling (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+878, 49722, 0, 1, 1, -11675.65, -1553.527, 36.48451, 1.127216, 120, 0, 0), -- Tree Python (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+879, 49722, 0, 1, 1, -11662.64, -1872.357, 56.21708, 3.150244, 120, 0, 0), -- Tree Python (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+880, 50487, 0, 1, 1, -11629.37, -1768.707, 39.40347, 4.578688, 120, 0, 0), -- Forest Spiderling (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+881, 49722, 0, 1, 1, -11608.51, -1857.41, 44.05565, 6.187401, 120, 0, 0), -- Tree Python (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+882, 49722, 0, 1, 1, -11584.86, -1819.126, 41.5763, 2.05388, 120, 0, 0), -- Tree Python (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+883, 50487, 0, 1, 1, -11575, -1733.796, 38.92381, 4.011822, 120, 0, 0), -- Forest Spiderling (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+884, 49722, 0, 1, 1, -11611.59, -1676.383, 38.89476, 0.8319262, 120, 0, 0), -- Tree Python (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+885, 50487, 0, 1, 1, -11619.98, -1513.575, 42.69781, 1.781208, 120, 0, 0), -- Forest Spiderling (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+886, 50479, 0, 1, 1, -11618.98, -1286.895, 78.21081, 2.694122, 120, 0, 0), -- Lizard Hatchling (Area: Zul'Gurub)
(@CGUID+887, 15475, 0, 1, 1, -11558.49, -1267.475, 78.51804, 2.107867, 120, 0, 0), -- Beetle (Area: Zul'Gurub)
(@CGUID+888, 15475, 0, 1, 1, -11574.34, -1323.274, 77.78674, 0.5928811, 120, 0, 0), -- Beetle (Area: Zul'Gurub)
(@CGUID+889, 15475, 0, 1, 1, -11539.62, -1226.824, 79.09302, 5.03414, 120, 0, 0), -- Beetle (Area: Zul'Gurub)
(@CGUID+890, 50479, 0, 1, 1, -11554.97, -1536.459, 52.25857, 0.435557, 120, 0, 0), -- Lizard Hatchling (Area: Zul'Gurub)
(@CGUID+891, 50479, 0, 1, 1, -11537.95, -1716.399, 39.99762, 5.486738, 120, 0, 0), -- Lizard Hatchling (Area: Zul'Gurub)
(@CGUID+892, 49722, 0, 1, 1, -12004.73, -1487.362, 79.93923, 5.034514, 120, 0, 0), -- Tree Python (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+893, 2914, 0, 1, 1, -11996, -1642.01, 34.31612, 0.6885368, 120, 0, 0), -- Snake (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+894, 4953, 0, 1, 1, -11993.53, -1661.74, 32.51217, 4.415018, 120, 0, 0), -- Moccasin (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+895, 4953, 0, 1, 1, -11993.49, -1671.095, 32.37836, 1.217551, 120, 0, 0), -- Moccasin (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+896, 2914, 0, 1, 1, -11988.14, -1677.54, 32.37836, 1.381606, 120, 0, 0), -- Snake (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+897, 4953, 0, 1, 1, -12010.52, -1665.305, 32.40856, 4.577534, 120, 0, 0), -- Moccasin (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+898, 4953, 0, 1, 1, -11996.31, -1680.071, 32.37836, 3.608571, 120, 0, 0), -- Moccasin (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+899, 4953, 0, 1, 1, -12005.94, -1673.916, 32.40856, 2.611944, 120, 0, 0), -- Moccasin (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+900, 50487, 0, 1, 1, -12038.87, -1640.206, 40.48862, 0.1214466, 120, 0, 0), -- Forest Spiderling (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+901, 4953, 0, 1, 1, -11985.05, -1687.701, 32.37836, 3.646427, 120, 0, 0), -- Moccasin (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+902, 2914, 0, 1, 1, -12012.57, -1669.727, 32.40856, 1.17372, 120, 0, 0), -- Snake (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+903, 4953, 0, 1, 1, -12019.7, -1665.496, 32.4132, 6.235505, 120, 0, 0), -- Moccasin (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+904, 2914, 0, 1, 1, -12003.28, -1681.2, 32.40856, 5.949707, 120, 0, 0), -- Snake (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+905, 3300, 0, 1, 1, -11993.09, -1688.986, 32.37836, 3.44277, 120, 0, 0), -- Adder (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+906, 2914, 0, 1, 1, -11988.97, -1694.015, 32.37836, 4.143471, 120, 0, 0), -- Snake (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+907, 4953, 0, 1, 1, -12011.07, -1680.12, 32.40856, 2.861743, 120, 0, 0), -- Moccasin (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+908, 3300, 0, 1, 1, -11998.53, -1689.358, 32.37836, 3.072824, 120, 0, 0), -- Adder (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+909, 4953, 0, 1, 1, -11993.02, -1693.538, 32.37836, 6.274148, 120, 0, 0), -- Moccasin (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+910, 4953, 0, 1, 1, -12004.84, -1688.983, 32.40856, 3.240674, 120, 0, 0), -- Moccasin (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+911, 15475, 0, 1, 1, -12036.08, -1737.615, 52.67465, 5.81531, 120, 0, 0), -- Beetle (Area: Zul'Gurub)
(@CGUID+912, 3300, 0, 1, 1, -12020.54, -1712.527, 39.40856, 4.821723, 120, 0, 0), -- Adder (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+913, 3300, 0, 1, 1, -12022.33, -1697.913, 39.52617, 2.06793, 120, 0, 0), -- Adder (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+914, 4953, 0, 1, 1, -12026.55, -1706.611, 39.40856, 1.222228, 120, 0, 0), -- Moccasin (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+915, 4953, 0, 1, 1, -12030.21, -1715.59, 39.40856, 3.013877, 120, 0, 0), -- Moccasin (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+916, 2914, 0, 1, 1, -12035.51, -1693.225, 39.37657, 3.742549, 120, 0, 0), -- Snake (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+917, 2914, 0, 1, 1, -12031.74, -1698.748, 39.40856, 4.657448, 120, 0, 0), -- Snake (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+918, 2914, 0, 1, 1, -12018.75, -1722.916, 39.40856, 3.004377, 120, 0, 0), -- Snake (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+919, 3300, 0, 1, 1, -12037.09, -1705.193, 40.28239, 0.4143872, 120, 0, 0), -- Adder (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+920, 2914, 0, 1, 1, -12014.06, -1685.938, 32.40856, 4.421548, 120, 0, 0), -- Snake (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+921, 2914, 0, 1, 1, -12017.37, -1681.741, 32.40856, 5.324732, 120, 0, 0), -- Snake (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+922, 2914, 0, 1, 1, -12002.09, -1702.262, 32.40856, 3.234861, 120, 0, 0), -- Snake (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+923, 2914, 0, 1, 1, -11989.9, -1702.142, 32.35986, 0.7416407, 120, 0, 0), -- Snake (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+924, 2914, 0, 1, 1, -11998.52, -1718.272, 32.35986, 1.728324, 120, 0, 0), -- Snake (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+925, 3300, 0, 1, 1, -11989.8, -1714.302, 32.35986, 3.573631, 120, 0, 0), -- Adder (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+926, 4953, 0, 1, 1, -11997.29, -1712.203, 32.35986, 5.858442, 120, 0, 0), -- Moccasin (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+927, 32520, 0, 1, 1, -6148.39, 5539.97, -1207.787, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Zul'Gurub)
(@CGUID+928, 32520, 0, 1, 1, -6014.71, 5479.63, -1208.007, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Zul'Gurub)
(@CGUID+929, 32520, 0, 1, 1, -5691.65, 5556.92, -1154.687, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Zul'Gurub)
(@CGUID+930, 32520, 0, 1, 1, -6305.162, 5582.533, -1172.063, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Zul'Gurub)
(@CGUID+931, 11383, 0, 1, 1, -11947.71, -1014.418, 89.14083, 1.605703, 120, 0, 0), -- High Priestess Hai'watna (Area: Zul'Gurub)
(@CGUID+932, 50479, 0, 1, 1, -12033.96, -728.6805, 13.23838, 2.162311, 120, 0, 0), -- Lizard Hatchling (Area: 0)
(@CGUID+933, 1096, 0, 1, 1, -12021.15, -777.2335, 15.71623, 3.879622, 120, 0, 0), -- Venture Co. Geologist (Area: 0)
(@CGUID+934, 1096, 0, 1, 1, -12025.21, -703.6533, 15.42986, 5.073779, 120, 0, 0), -- Venture Co. Geologist (Area: 0)
(@CGUID+935, 15475, 0, 1, 1, -12013.55, -790.7303, 16.64104, 2.76226, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+936, 1096, 0, 1, 1, -12028.1, -645.0102, 15.71107, 2.503448, 120, 0, 0), -- Venture Co. Geologist (Area: Venture Co. Base Camp)
(@CGUID+937, 4260, 0, 1, 1, -11951.88, -598.6712, 16.95141, 5.764019, 120, 0, 0), -- Venture Co. Shredder (Area: Venture Co. Base Camp)
(@CGUID+938, 1096, 0, 1, 1, -12022.4, -581.907, 14.30007, 1.645428, 120, 0, 0), -- Venture Co. Geologist (Area: Venture Co. Base Camp)
(@CGUID+939, 1095, 0, 1, 1, -11998.88, -530.1702, 12.05152, 4.712389, 120, 0, 0), -- Venture Co. Workboss (Area: Venture Co. Base Camp)
(@CGUID+940, 1097, 0, 1, 1, -11995.48, -525.4549, 12.05152, 4.712389, 120, 0, 0), -- Venture Co. Mechanic (Area: Venture Co. Base Camp)
(@CGUID+941, 50487, 0, 1, 1, -12028.51, -563.1431, 12.5336, 0.8507181, 120, 0, 0), -- Forest Spiderling (Area: Venture Co. Base Camp) (possible waypoints or random movement)
(@CGUID+942, 686, 0, 1, 1, -12010.46, -236.7108, 20.18165, 2.957076, 120, 0, 0), -- Lashtail Raptor (Area: Lake Nazferiti)
(@CGUID+943, 686, 0, 1, 1, -12014.68, -180.858, 15.00107, 1.047337, 120, 0, 0), -- Lashtail Raptor (Area: 0)
(@CGUID+944, 4457, 0, 1, 1, -12019.1, -78.51801, 28.74455, 4.64004, 120, 0, 0), -- Murkgill Forager (Area: 0) (possible waypoints or random movement)
(@CGUID+945, 1085, 0, 1, 1, -12022.68, -45.09602, 17.06073, 0.5622031, 120, 0, 0), -- Elder Stranglethorn Tiger (Area: 0)
(@CGUID+946, 4461, 0, 1, 1, -12035.31, 14.55859, 7.524577, 4.89486, 120, 0, 0), -- Murkgill Warrior (Area: 0) (possible waypoints or random movement)
(@CGUID+947, 15475, 0, 1, 1, -12079.67, 208.4618, 13.28964, 4.358417, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+948, 686, 0, 1, 1, -12076.03, 151.6145, 16.13751, 1.407896, 120, 0, 0), -- Lashtail Raptor (Area: 0)
(@CGUID+949, 587, 0, 1, 1, -12054.2, 287.2983, 3.83577, 1.702338, 120, 0, 0), -- Bloodscalp Warrior (Area: 0) (possible waypoints or random movement)
(@CGUID+950, 694, 0, 1, 1, -11982.29, 327.9468, 1.881999, 2.259094, 120, 0, 0), -- Bloodscalp Axe Thrower (Area: 0) (possible waypoints or random movement)
(@CGUID+951, 697, 0, 1, 1, -12060.12, 343.9999, 3.910252, 3.456954, 120, 0, 0), -- Bloodscalp Shaman (Area: 0) (possible waypoints or random movement)
(@CGUID+952, 50479, 0, 1, 1, -12073.59, 327.5853, 3.292081, 1.098415, 120, 0, 0), -- Lizard Hatchling (Area: 0)
(@CGUID+953, 6827, 0, 1, 1, -12099.48, 382.3411, 0.2970227, 5.503312, 120, 0, 0), -- Crab (Area: Bal'lal Ruins)
(@CGUID+954, 6827, 0, 1, 1, -12067.73, 418.661, 7.029346, 4.511931, 120, 0, 0), -- Crab (Area: Bal'lal Ruins)
(@CGUID+955, 691, 0, 1, 1, -12113.52, 979.7403, 6.252416, 3.776262, 120, 0, 0), -- Lesser Water Elemental (Area: The Savage Coast) (possible waypoints or random movement)
(@CGUID+956, 6827, 0, 1, 1, -12108.63, 958.5692, 5.57622, 2.78609, 120, 0, 0), -- Crab (Area: The Savage Coast)
(@CGUID+957, 691, 0, 1, 1, -12150.45, 913.7378, 1.34567, 5.164362, 120, 0, 0), -- Lesser Water Elemental (Area: The Savage Coast) (possible waypoints or random movement)
(@CGUID+958, 6827, 0, 1, 1, -12144.56, 922.8306, 1.183194, 1.064515, 120, 0, 0), -- Crab (Area: The Savage Coast)
(@CGUID+959, 691, 0, 1, 1, -12109.82, 850.3168, 10.13609, 0.5895593, 120, 0, 0), -- Lesser Water Elemental (Area: The Savage Coast) (possible waypoints or random movement)
(@CGUID+960, 6827, 0, 1, 1, -12112.67, 927.6721, 2.871246, 1.238546, 120, 0, 0), -- Crab (Area: The Savage Coast)
(@CGUID+961, 691, 0, 1, 1, -12116.15, 883.1641, 7.576281, 0.2575453, 120, 0, 0), -- Lesser Water Elemental (Area: The Savage Coast) (possible waypoints or random movement)
(@CGUID+962, 691, 0, 1, 1, -12140, 941.3427, 3.099046, 2.107867, 120, 0, 0), -- Lesser Water Elemental (Area: The Savage Coast) (possible waypoints or random movement)
(@CGUID+963, 691, 0, 1, 1, -12149.54, 842.0797, 13.35529, 3.180635, 120, 0, 0), -- Lesser Water Elemental (Area: The Savage Coast) (possible waypoints or random movement)
(@CGUID+964, 691, 0, 1, 1, -12146.57, 816.2661, 6.860673, 0.3569429, 120, 0, 0), -- Lesser Water Elemental (Area: The Savage Coast) (possible waypoints or random movement)
(@CGUID+965, 691, 0, 1, 1, -12128.39, 812.987, 3.137513, 4.059907, 120, 0, 0), -- Lesser Water Elemental (Area: The Savage Coast) (possible waypoints or random movement)
(@CGUID+966, 6827, 0, 1, 1, -12121.35, 801.5625, 2.068543, 3.506824, 120, 0, 0), -- Crab (Area: The Savage Coast)
(@CGUID+967, 877, 0, 1, 1, -12128.31, 501.3442, -54.5144, 4.182349, 120, 0, 0), -- Saltscale Forager (Area: The Savage Coast) (possible waypoints or random movement)
(@CGUID+968, 697, 0, 1, 1, -12088.78, 320.2931, 3.888013, 4.344935, 120, 0, 0), -- Bloodscalp Shaman (Area: Bal'lal Ruins) (possible waypoints or random movement)
(@CGUID+969, 42620, 0, 1, 1, -12133.46, 259.6528, 3.929263, 0, 120, 0, 0), -- Lashtail Egg (Area: Bal'lal Ruins)
(@CGUID+970, 686, 0, 1, 1, -12121.39, 186.8805, 14.70386, 3.982396, 120, 0, 0), -- Lashtail Raptor (Area: Bal'lal Ruins)
(@CGUID+971, 9600, 0, 1, 1, -12092.36, 85.25566, 17.61932, 1.01171, 120, 0, 0), -- Parrot (Area: 0)
(@CGUID+972, 9600, 0, 1, 1, -12075.23, 61.81274, 18.08398, 2.112209, 120, 0, 0), -- Parrot (Area: 0)
(@CGUID+973, 50479, 0, 1, 1, -12071.79, 38.04356, -0.7033181, 6.057523, 120, 0, 0), -- Lizard Hatchling (Area: 0)
(@CGUID+974, 15475, 0, 1, 1, -12072.04, 101.0263, 1.314394, 1.443535, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+975, 4458, 0, 1, 1, -12117.67, 85.44003, -0.9441786, 3.608902, 120, 0, 0), -- Murkgill Hunter (Area: 0) (possible waypoints or random movement)
(@CGUID+976, 4461, 0, 1, 1, -12079.9, 57.87481, -5.947215, 1.396011, 120, 0, 0), -- Murkgill Warrior (Area: 0) (possible waypoints or random movement)
(@CGUID+977, 4458, 0, 1, 1, -12041.72, 48.91221, 1.060721, 1.003917, 120, 0, 0), -- Murkgill Hunter (Area: 0) (possible waypoints or random movement)
(@CGUID+978, 4458, 0, 1, 1, -12073.31, 93.09123, -0.04873085, 1.685653, 120, 0, 0), -- Murkgill Hunter (Area: 0) (possible waypoints or random movement)
(@CGUID+979, 4458, 0, 1, 1, -12052.67, 82.40107, -2.964255, 0.56523, 120, 0, 0), -- Murkgill Hunter (Area: 0) (possible waypoints or random movement)
(@CGUID+980, 4457, 0, 1, 1, -12069.43, 70.49374, -5.041477, 0.3322505, 120, 0, 0), -- Murkgill Forager (Area: 0) (possible waypoints or random movement)
(@CGUID+981, 49722, 0, 1, 1, -12087.66, -48.35878, 19.29452, 1.607889, 120, 0, 0), -- Tree Python (Area: 0) (possible waypoints or random movement)
(@CGUID+982, 4461, 0, 1, 1, -12090.26, 34.41508, -3.076315, 2.073749, 120, 0, 0), -- Murkgill Warrior (Area: 0) (possible waypoints or random movement)
(@CGUID+983, 4461, 0, 1, 1, -12114.63, 39.64053, -6.381749, 3.765933, 120, 0, 0), -- Murkgill Warrior (Area: 0) (possible waypoints or random movement)
(@CGUID+984, 9600, 0, 1, 1, -12048.24, -120.0694, 51.97286, 0.1235131, 120, 0, 0), -- Parrot (Area: 0)
(@CGUID+985, 15475, 0, 1, 1, -12092.6, -276.9425, 17.37677, 3.852338, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+986, 49928, 0, 1, 1, -12077.02, -203.6564, 39.65498, 0.7326063, 120, 0, 0), -- Crimson Moth (Area: 0)
(@CGUID+987, 686, 0, 1, 1, -12088.03, -261.3752, 18.48979, 0.03082383, 120, 0, 0), -- Lashtail Raptor (Area: 0)
(@CGUID+988, 50487, 0, 1, 1, -12072.93, -243.5052, 17.36283, 4.373978, 120, 0, 0), -- Forest Spiderling (Area: 0) (possible waypoints or random movement)
(@CGUID+989, 1152, 0, 1, 1, -12048.68, -416.4202, -14.66999, 4.202222, 120, 0, 0), -- Snapjaw Crocolisk (Area: 0) (possible waypoints or random movement)
(@CGUID+990, 905, 0, 1, 1, -12050.55, -385.7945, -5.235247, 4.088896, 120, 0, 0), -- Sharptooth Frenzy (Area: 0) (possible waypoints or random movement)
(@CGUID+991, 1152, 0, 1, 1, -12081.25, -310.416, 10.4716, 5.946413, 120, 0, 0), -- Snapjaw Crocolisk (Area: 0) (possible waypoints or random movement)
(@CGUID+992, 6827, 0, 1, 1, -12091.47, -425.9482, 10.74831, 1.667413, 120, 0, 0), -- Crab (Area: Lake Nazferiti)
(@CGUID+993, 1152, 0, 1, 1, -12071.45, -469.4375, 8.933217, 4.048032, 120, 0, 0), -- Snapjaw Crocolisk (Area: Lake Nazferiti) (possible waypoints or random movement)
(@CGUID+994, 1152, 0, 1, 1, -12090.07, -420.1853, 10.53737, 4.506469, 120, 0, 0), -- Snapjaw Crocolisk (Area: Lake Nazferiti) (possible waypoints or random movement)
(@CGUID+995, 6827, 0, 1, 1, -12101.67, -416.0146, 13.14158, 1.19029, 120, 0, 0), -- Crab (Area: Lake Nazferiti)
(@CGUID+996, 6827, 0, 1, 1, -12098.51, -385.9253, 10.86711, 1.964399, 120, 0, 0), -- Crab (Area: Lake Nazferiti)
(@CGUID+997, 1096, 0, 1, 1, -12098.44, -533.334, 15.52112, 3.070457, 120, 0, 0), -- Venture Co. Geologist (Area: Lake Nazferiti)
(@CGUID+998, 49722, 0, 1, 1, -12095.63, -531.5018, 15.03389, 2.727729, 120, 0, 0), -- Tree Python (Area: Lake Nazferiti) (possible waypoints or random movement)
(@CGUID+999, 1096, 0, 1, 1, -12057.15, -673.6476, 18.49621, 2.215837, 120, 0, 0), -- Venture Co. Geologist (Area: Venture Co. Base Camp)
(@CGUID+1000, 1096, 0, 1, 1, -12044.55, -629.7756, 14.48, 2.5914, 120, 0, 0), -- Venture Co. Geologist (Area: Venture Co. Base Camp)
(@CGUID+1001, 1096, 0, 1, 1, -12098.38, -639.7748, 17.24263, 2.922239, 120, 0, 0), -- Venture Co. Geologist (Area: Venture Co. Base Camp)
(@CGUID+1002, 15475, 0, 1, 1, -12084.11, -643.8484, 18.0207, 3.71985, 120, 0, 0), -- Beetle (Area: Venture Co. Base Camp)
(@CGUID+1003, 1096, 0, 1, 1, -12079.76, -577.0682, 14.60951, 1.707996, 120, 0, 0), -- Venture Co. Geologist (Area: Venture Co. Base Camp)
(@CGUID+1004, 50487, 0, 1, 1, -12086.61, -756.3232, 12.61645, 1.526162, 120, 0, 0), -- Forest Spiderling (Area: Venture Co. Base Camp) (possible waypoints or random movement)
(@CGUID+1005, 50479, 0, 1, 1, -12044.85, -691.5962, 14.62574, 5.887793, 120, 0, 0), -- Lizard Hatchling (Area: Venture Co. Base Camp)
(@CGUID+1006, 50479, 0, 1, 1, -12062.77, -701.0839, 13.32192, 1.323804, 120, 0, 0), -- Lizard Hatchling (Area: Venture Co. Base Camp)
(@CGUID+1007, 1096, 0, 1, 1, -12110.72, -693.4409, 19.81175, 5.409709, 120, 0, 0), -- Venture Co. Geologist (Area: Venture Co. Base Camp)
(@CGUID+1008, 1096, 0, 1, 1, -12049.72, -733.2616, 14.02303, 3.962887, 120, 0, 0), -- Venture Co. Geologist (Area: Venture Co. Base Camp)
(@CGUID+1009, 1096, 0, 1, 1, -12089.07, -721.6187, 16.21577, 1.783161, 120, 0, 0), -- Venture Co. Geologist (Area: Venture Co. Base Camp)
(@CGUID+1010, 43052, 0, 1, 1, -12089.2, -814.675, 42.31933, 3.804818, 120, 0, 0), -- Raskha (Area: Venture Co. Base Camp)
(@CGUID+1011, 44183, 0, 1, 1, -12078.17, -845.6406, 49.10175, 2.670354, 120, 0, 0), -- Durango (Area: Venture Co. Base Camp)
(@CGUID+1012, 42812, 0, 1, 1, -12083.95, -858.3368, 51.32517, 1.239184, 120, 0, 0), -- Priestess Hu'rala (Area: Venture Co. Base Camp)
(@CGUID+1013, 42811, 0, 1, 1, -12076.46, -849.4184, 66.24093, 4.502949, 120, 0, 0), -- Surkhan (Area: Venture Co. Base Camp)
(@CGUID+1014, 49722, 0, 1, 1, -12062.33, -874.663, 47.54472, 2.686678, 120, 0, 0), -- Tree Python (Area: Venture Co. Base Camp) (possible waypoints or random movement)
(@CGUID+1015, 49722, 0, 1, 1, -12051.1, -821.2971, 46.4039, 0.1824713, 120, 0, 0), -- Tree Python (Area: Venture Co. Base Camp) (possible waypoints or random movement)
(@CGUID+1016, 684, 0, 1, 1, -12019.92, -842.0392, 48.89112, 2.466852, 120, 0, 0), -- Shadowmaw Panther (Area: Venture Co. Base Camp)
(@CGUID+1017, 50479, 0, 1, 1, -12078.6, -977.7632, 43.15961, 1.098049, 120, 0, 0), -- Lizard Hatchling (Area: 0)
(@CGUID+1018, 49722, 0, 1, 1, -12108.3, -897.9563, 44.12664, 1.596119, 120, 0, 0), -- Tree Python (Area: 0) (possible waypoints or random movement)
(@CGUID+1019, 43050, 0, 1, 1, -12074.38, -931.0008, 43.88301, 2.94688, 120, 0, 0), -- Vale Howler (Area: 0) (possible waypoints or random movement)
(@CGUID+1020, 684, 0, 1, 1, -12008.82, -926.44, 41.9777, 5.430118, 120, 0, 0), -- Shadowmaw Panther (Area: 0)
(@CGUID+1021, 7802, 0, 1, 1, -12039.9, -1009.148, 49.50485, 3.560472, 120, 0, 0), -- Galvan the Ancient (Area: 0)
(@CGUID+1022, 49722, 0, 1, 1, -12086.68, -1046.483, 67.60898, 4.483193, 120, 0, 0), -- Tree Python (Area: 0) (possible waypoints or random movement)
(@CGUID+1023, 50479, 0, 1, 1, -12032.43, -1510.562, 77.44266, 6.048628, 120, 0, 0), -- Lizard Hatchling (Area: Zul'Gurub)
(@CGUID+1024, 43351, 0, 1, 1, -12056.83, -1457.056, 143.5313, 1.103005, 120, 0, 0), -- Gurubashi Batling (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+1025, 50479, 0, 1, 1, -12052.08, -1651.429, 42.7005, 4.198086, 120, 0, 0), -- Lizard Hatchling (Area: Zul'Gurub)
(@CGUID+1026, 50479, 0, 1, 1, -12106.14, -1449.171, 130.8702, 5.957675, 120, 0, 0), -- Lizard Hatchling (Area: Zul'Gurub)
(@CGUID+1027, 44187, 0, 1, 1, -12118.48, -863.9288, 50.53194, 1.343904, 120, 0, 0), -- Pechanga (Area: 0)
(@CGUID+1028, 44186, 0, 1, 1, -12123.72, -861.1077, 50.53194, 0.6283185, 120, 0, 0), -- Morango (Area: 0)
(@CGUID+1029, 42813, 0, 1, 1, -12105.37, -851.2864, 46.92367, 0.8552113, 120, 0, 0), -- Kil'karil (Area: 0)
(@CGUID+1030, 42814, 0, 1, 1, -12126.93, -843.7612, 45.36088, 0.7184091, 120, 0, 0), -- Skeezy Whillzap (Area: 0) (possible waypoints or random movement)
(@CGUID+1031, 4260, 0, 1, 1, -12076.76, -701.6904, 13.63911, 1.192552, 120, 0, 0), -- Venture Co. Shredder (Area: Venture Co. Base Camp)
(@CGUID+1032, 50479, 0, 1, 1, -12117.46, -668.2611, 16.48965, 5.21797, 120, 0, 0), -- Lizard Hatchling (Area: Venture Co. Base Camp)
(@CGUID+1033, 32520, 0, 1, 1, -6148.39, 5539.97, -1207.787, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Venture Co. Base Camp)
(@CGUID+1034, 32520, 0, 1, 1, -5691.65, 5556.92, -1154.687, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Venture Co. Base Camp)
(@CGUID+1035, 32520, 0, 1, 1, -6305.162, 5582.533, -1172.063, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Venture Co. Base Camp)
(@CGUID+1036, 32520, 0, 1, 1, -6014.71, 5479.63, -1208.007, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Venture Co. Base Camp)
(@CGUID+1037, 50487, 0, 1, 1, -12121.2, -550.8718, 12.09705, 4.794109, 120, 0, 0), -- Forest Spiderling (Area: Venture Co. Base Camp) (possible waypoints or random movement)
(@CGUID+1038, 1096, 0, 1, 1, -12115.86, -548.4238, 12.0409, 2.302723, 120, 0, 0), -- Venture Co. Geologist (Area: Venture Co. Base Camp)
(@CGUID+1039, 1096, 0, 1, 1, -12116.74, -500.2432, 16.35222, 4.531837, 120, 0, 0), -- Venture Co. Geologist (Area: Venture Co. Base Camp)
(@CGUID+1040, 1152, 0, 1, 1, -12113.45, -380.5433, 11.65684, 0.5842924, 120, 0, 0), -- Snapjaw Crocolisk (Area: Lake Nazferiti) (possible waypoints or random movement)
(@CGUID+1041, 6827, 0, 1, 1, -12108.84, -366.0886, 8.73326, 0.4330894, 120, 0, 0), -- Crab (Area: Lake Nazferiti)
(@CGUID+1042, 6827, 0, 1, 1, -12113.21, -305.2286, 11.56938, 1.30403, 120, 0, 0), -- Crab (Area: Lake Nazferiti)
(@CGUID+1043, 686, 0, 1, 1, -12111.79, -280.0921, 15.84001, 0.8207666, 120, 0, 0), -- Lashtail Raptor (Area: Lake Nazferiti)
(@CGUID+1044, 9600, 0, 1, 1, -12113.2, -274.9196, 34.71353, 1.724347, 120, 0, 0), -- Parrot (Area: Lake Nazferiti)
(@CGUID+1045, 4458, 0, 1, 1, -12079.96, -79.21061, 31.46449, 1.460612, 120, 0, 0), -- Murkgill Hunter (Area: 0) (possible waypoints or random movement)
(@CGUID+1046, 9600, 0, 1, 1, -12131.6, 46.09939, 18.24367, 0.6835287, 120, 0, 0), -- Parrot (Area: 0)
(@CGUID+1047, 42620, 0, 1, 1, -12134.01, 260.0052, 3.926544, 0, 120, 0, 0), -- Lashtail Egg (Area: 0)
(@CGUID+1048, 42620, 0, 1, 1, -12134.6, 259.9479, 3.857639, 0, 120, 0, 0), -- Lashtail Egg (Area: 0)
(@CGUID+1049, 879, 0, 1, 1, -12159.31, 627.2502, -67.16384, 3.291173, 120, 0, 0), -- Saltscale Hunter (Area: The Savage Coast) (possible waypoints or random movement)
(@CGUID+1050, 871, 0, 1, 1, -12161.13, 639.1631, -66.62554, 0.3776589, 120, 0, 0), -- Saltscale Warrior (Area: The Savage Coast) (possible waypoints or random movement)
(@CGUID+1051, 691, 0, 1, 1, -12153.5, 781.125, 1.525476, 4.281073, 120, 0, 0), -- Lesser Water Elemental (Area: The Vile Reef) (possible waypoints or random movement)
(@CGUID+1052, 691, 0, 1, 1, -12153.76, 880.1971, 14.84578, 5.61484, 120, 0, 0), -- Lesser Water Elemental (Area: The Savage Coast) (possible waypoints or random movement)
(@CGUID+1053, 691, 0, 1, 1, -12155.21, 948.2161, 2.512864, 4.584343, 120, 0, 0), -- Lesser Water Elemental (Area: The Savage Coast) (possible waypoints or random movement)
(@CGUID+1054, 691, 0, 1, 1, -12160.48, 985.0583, 0.330739, 3.563134, 120, 0, 0), -- Lesser Water Elemental (Area: The Savage Coast) (possible waypoints or random movement)
(@CGUID+1055, 691, 0, 1, 1, -12181.53, 951.6849, -2.138927, 2.156693, 120, 0, 0), -- Lesser Water Elemental (Area: The Savage Coast) (possible waypoints or random movement)
(@CGUID+1056, 691, 0, 1, 1, -12223.21, 924.2804, -6.039786, 2.672958, 120, 0, 0), -- Lesser Water Elemental (Area: The Savage Coast) (possible waypoints or random movement)
(@CGUID+1057, 691, 0, 1, 1, -12188.89, 911.5142, 0.5983331, 3.98458, 120, 0, 0), -- Lesser Water Elemental (Area: The Savage Coast) (possible waypoints or random movement)
(@CGUID+1058, 691, 0, 1, 1, -12180.05, 884.7003, 8.187445, 4.342762, 120, 0, 0), -- Lesser Water Elemental (Area: The Savage Coast) (possible waypoints or random movement)
(@CGUID+1059, 691, 0, 1, 1, -12217.99, 876.3065, -0.8911042, 3.811297, 120, 0, 0), -- Lesser Water Elemental (Area: The Savage Coast) (possible waypoints or random movement)
(@CGUID+1060, 691, 0, 1, 1, -12185.75, 852.5369, 14.63127, 2.368916, 120, 0, 0), -- Lesser Water Elemental (Area: The Savage Coast) (possible waypoints or random movement)
(@CGUID+1061, 691, 0, 1, 1, -12214.23, 948.4925, -13.91922, 3.912755, 120, 0, 0), -- Lesser Water Elemental (Area: The Savage Coast) (possible waypoints or random movement)
(@CGUID+1062, 6827, 0, 1, 1, -12174.89, 791.7217, 2.296688, 3.86707, 120, 0, 0), -- Crab (Area: The Savage Coast)
(@CGUID+1063, 6827, 0, 1, 1, -12238.03, 847.3568, 2.668964, 2.529125, 120, 0, 0), -- Crab (Area: The Savage Coast)
(@CGUID+1064, 691, 0, 1, 1, -12181.27, 815.7938, 2.192718, 5.091337, 120, 0, 0), -- Lesser Water Elemental (Area: The Savage Coast) (possible waypoints or random movement)
(@CGUID+1065, 691, 0, 1, 1, -12220.02, 849.7347, 2.720759, 2.791737, 120, 0, 0), -- Lesser Water Elemental (Area: The Savage Coast) (possible waypoints or random movement)
(@CGUID+1066, 691, 0, 1, 1, -12203.82, 829.506, 2.745748, 4.252577, 120, 0, 0), -- Lesser Water Elemental (Area: The Savage Coast) (possible waypoints or random movement)
(@CGUID+1067, 873, 0, 1, 1, -12186.75, 656.175, -66.68923, 0.2366954, 120, 0, 0), -- Saltscale Oracle (Area: The Savage Coast) (possible waypoints or random movement)
(@CGUID+1068, 879, 0, 1, 1, -12235.42, 739.583, -49.58849, 4.377659, 120, 0, 0), -- Saltscale Hunter (Area: The Savage Coast) (possible waypoints or random movement)
(@CGUID+1069, 873, 0, 1, 1, -12180.38, 674.1978, -69.83686, 1.657272, 120, 0, 0), -- Saltscale Oracle (Area: The Savage Coast) (possible waypoints or random movement)
(@CGUID+1070, 877, 0, 1, 1, -12228.48, 716.9078, -60.90657, 6.009406, 120, 0, 0), -- Saltscale Forager (Area: The Savage Coast) (possible waypoints or random movement)
(@CGUID+1071, 871, 0, 1, 1, -12201.87, 670.232, -69.98207, 4.521017, 120, 0, 0), -- Saltscale Warrior (Area: The Savage Coast) (possible waypoints or random movement)
(@CGUID+1072, 879, 0, 1, 1, -12193.38, 622.4959, -67.61047, 0.299055, 120, 0, 0), -- Saltscale Hunter (Area: The Vile Reef) (possible waypoints or random movement)
(@CGUID+1073, 873, 0, 1, 1, -12181.52, 614.218, -68.11297, 3.70316, 120, 0, 0), -- Saltscale Oracle (Area: The Vile Reef) (possible waypoints or random movement)
(@CGUID+1074, 873, 0, 1, 1, -12199.09, 609.7946, -68.11047, 1.885929, 120, 0, 0), -- Saltscale Oracle (Area: The Vile Reef) (possible waypoints or random movement)
(@CGUID+1075, 873, 0, 1, 1, -12235.42, 656.25, -69, 1.570796, 120, 0, 0), -- Saltscale Oracle (Area: The Vile Reef) (possible waypoints or random movement)
(@CGUID+1076, 879, 0, 1, 1, -12223.59, 631.9645, -69.64574, 1.505086, 120, 0, 0), -- Saltscale Hunter (Area: The Vile Reef) (possible waypoints or random movement)
(@CGUID+1077, 879, 0, 1, 1, -12210.81, 648.1619, -67.21204, 3.008584, 120, 0, 0), -- Saltscale Hunter (Area: The Vile Reef) (possible waypoints or random movement)
(@CGUID+1078, 873, 0, 1, 1, -12222.14, 661.2355, -68.94989, 4.198403, 120, 0, 0), -- Saltscale Oracle (Area: The Vile Reef) (possible waypoints or random movement)
(@CGUID+1079, 879, 0, 1, 1, -12249.02, 617.1339, -76.47489, 5.728214, 120, 0, 0), -- Saltscale Hunter (Area: The Vile Reef) (possible waypoints or random movement)
(@CGUID+1080, 877, 0, 1, 1, -12244.79, 676.041, -70.82324, 1.925885, 120, 0, 0), -- Saltscale Forager (Area: The Vile Reef) (possible waypoints or random movement)
(@CGUID+1081, 879, 0, 1, 1, -12176.82, 501.3844, -69.14317, 0.9983978, 120, 0, 0), -- Saltscale Hunter (Area: The Vile Reef) (possible waypoints or random movement)
(@CGUID+1082, 877, 0, 1, 1, -12154.69, 497.3965, -58.90698, 1.51322, 120, 0, 0), -- Saltscale Forager (Area: The Vile Reef) (possible waypoints or random movement)
(@CGUID+1083, 6827, 0, 1, 1, -12194, 327.0482, 1.075553, 0.1272613, 120, 0, 0), -- Crab (Area: The Vile Reef)
(@CGUID+1084, 6827, 0, 1, 1, -12195.76, 337.8084, 0.366107, 3.344377, 120, 0, 0), -- Crab (Area: The Vile Reef)
(@CGUID+1085, 6827, 0, 1, 1, -12208.87, 316.2967, 2.415083, 2.876711, 120, 0, 0), -- Crab (Area: The Vile Reef)
(@CGUID+1086, 49722, 0, 1, 1, -12173.91, 290.7546, 2.410532, 6.239135, 120, 0, 0), -- Tree Python (Area: The Vile Reef) (possible waypoints or random movement)
(@CGUID+1087, 42620, 0, 1, 1, -12151.46, 276.8663, 3.372352, 0, 120, 0, 0), -- Lashtail Egg (Area: The Savage Coast)
(@CGUID+1088, 42620, 0, 1, 1, -12152.05, 276.809, 3.239583, 0, 120, 0, 0), -- Lashtail Egg (Area: The Savage Coast)
(@CGUID+1089, 42620, 0, 1, 1, -12150.92, 276.5139, 3.463541, 0, 120, 0, 0), -- Lashtail Egg (Area: The Savage Coast)
(@CGUID+1090, 686, 0, 1, 1, -12212.5, 292.393, 3.06636, 5.869322, 120, 0, 0), -- Lashtail Raptor (Area: The Savage Coast)
(@CGUID+1091, 686, 0, 1, 1, -12197.05, 271.6106, 3.556651, 0.5370705, 120, 0, 0), -- Lashtail Raptor (Area: The Savage Coast)
(@CGUID+1092, 42620, 0, 1, 1, -12141.82, 257.8629, 2.975694, 3.525565, 120, 0, 0), -- Lashtail Egg (Area: The Savage Coast)
(@CGUID+1093, 42620, 0, 1, 1, -12140.67, 258.0295, 2.949634, 3.525565, 120, 0, 0), -- Lashtail Egg (Area: The Savage Coast)
(@CGUID+1094, 42620, 0, 1, 1, -12141.19, 257.75, 2.950865, 3.525565, 120, 0, 0), -- Lashtail Egg (Area: The Savage Coast)
(@CGUID+1095, 686, 0, 1, 1, -12158.83, 255.989, 4.272092, 2.69365, 120, 0, 0), -- Lashtail Raptor (Area: The Savage Coast)
(@CGUID+1096, 15475, 0, 1, 1, -12159.64, 266.342, 3.310634, 4.677248, 120, 0, 0), -- Beetle (Area: The Savage Coast)
(@CGUID+1097, 42620, 0, 1, 1, -12179.38, 253.1701, 3.572916, 0, 120, 0, 0), -- Lashtail Egg (Area: The Savage Coast)
(@CGUID+1098, 42620, 0, 1, 1, -12178.84, 252.8177, 3.53993, 0, 120, 0, 0), -- Lashtail Egg (Area: The Savage Coast)
(@CGUID+1099, 42620, 0, 1, 1, -12179.97, 253.1129, 3.6875, 0, 120, 0, 0), -- Lashtail Egg (Area: The Savage Coast)
(@CGUID+1100, 42620, 0, 1, 1, -12206.16, 263.7083, 2.847302, 0, 120, 0, 0), -- Lashtail Egg (Area: The Savage Coast)
(@CGUID+1101, 42620, 0, 1, 1, -12206.71, 264.0608, 2.907555, 0, 120, 0, 0), -- Lashtail Egg (Area: The Savage Coast)
(@CGUID+1102, 42620, 0, 1, 1, -12207.3, 264.0035, 2.965277, 0, 120, 0, 0), -- Lashtail Egg (Area: The Savage Coast)
(@CGUID+1103, 42620, 0, 1, 1, -12165.35, 240.2309, 1.893061, 0, 120, 0, 0), -- Lashtail Egg (Area: The Savage Coast)
(@CGUID+1104, 42620, 0, 1, 1, -12165.94, 240.1736, 1.787035, 0, 120, 0, 0), -- Lashtail Egg (Area: The Savage Coast)
(@CGUID+1105, 42620, 0, 1, 1, -12164.8, 239.8785, 2.017361, 0, 120, 0, 0), -- Lashtail Egg (Area: The Savage Coast)
(@CGUID+1106, 42620, 0, 1, 1, -12237.54, 274.566, 3.594649, 0, 120, 0, 0), -- Lashtail Egg (Area: The Savage Coast)
(@CGUID+1107, 42620, 0, 1, 1, -12238.09, 274.9184, 3.634058, 0, 120, 0, 0), -- Lashtail Egg (Area: The Savage Coast)
(@CGUID+1108, 42620, 0, 1, 1, -12195.24, 241.4115, 2.170139, 0, 120, 0, 0), -- Lashtail Egg (Area: The Savage Coast)
(@CGUID+1109, 42620, 0, 1, 1, -12194.69, 241.059, 2.148042, 0, 120, 0, 0), -- Lashtail Egg (Area: The Savage Coast)
(@CGUID+1110, 42620, 0, 1, 1, -12195.83, 241.3542, 2.184043, 0, 120, 0, 0), -- Lashtail Egg (Area: The Savage Coast)
(@CGUID+1111, 42620, 0, 1, 1, -12238.68, 274.8611, 3.636433, 0, 120, 0, 0), -- Lashtail Egg (Area: The Savage Coast)
(@CGUID+1112, 42620, 0, 1, 1, -12182.25, 231.974, 2.383238, 1.448623, 120, 0, 0), -- Lashtail Egg (Area: The Savage Coast)
(@CGUID+1113, 42620, 0, 1, 1, -12182.65, 231.4618, 2.343787, 1.448623, 120, 0, 0), -- Lashtail Egg (Area: The Savage Coast)
(@CGUID+1114, 42620, 0, 1, 1, -12182.65, 230.8698, 2.352951, 1.448623, 120, 0, 0), -- Lashtail Egg (Area: The Savage Coast)
(@CGUID+1115, 42620, 0, 1, 1, -12221.05, 238.9201, 4.452684, 0, 120, 0, 0), -- Lashtail Egg (Area: The Savage Coast)
(@CGUID+1116, 42620, 0, 1, 1, -12220.88, 238.3698, 4.539368, 0, 120, 0, 0), -- Lashtail Egg (Area: The Savage Coast)
(@CGUID+1117, 686, 0, 1, 1, -12177.41, 219.7966, 3.402554, 0.186668, 120, 0, 0), -- Lashtail Raptor (Area: The Savage Coast)
(@CGUID+1118, 42620, 0, 1, 1, -12221.45, 238.0938, 4.48116, 0, 120, 0, 0), -- Lashtail Egg (Area: The Savage Coast)
(@CGUID+1119, 42620, 0, 1, 1, -12187.09, 216.559, 4.977599, 0, 120, 0, 0), -- Lashtail Egg (Area: The Savage Coast)
(@CGUID+1120, 42620, 0, 1, 1, -12187.68, 216.5035, 5.114583, 0, 120, 0, 0), -- Lashtail Egg (Area: The Savage Coast)
(@CGUID+1121, 42620, 0, 1, 1, -12186.54, 216.2083, 4.848969, 0, 120, 0, 0), -- Lashtail Egg (Area: The Savage Coast)
(@CGUID+1122, 42620, 0, 1, 1, -12191.46, 209.2361, 5.516811, 0, 120, 0, 0), -- Lashtail Egg (Area: The Savage Coast)
(@CGUID+1123, 42620, 0, 1, 1, -12190.91, 208.8837, 5.480914, 0, 120, 0, 0), -- Lashtail Egg (Area: The Savage Coast)
(@CGUID+1124, 42620, 0, 1, 1, -12192.05, 209.1788, 5.50676, 0, 120, 0, 0), -- Lashtail Egg (Area: The Savage Coast)
(@CGUID+1125, 15475, 0, 1, 1, -12203.17, 212.8027, 5.345775, 2.302305, 120, 0, 0), -- Beetle (Area: The Savage Coast)
(@CGUID+1126, 686, 0, 1, 1, -12181.03, 113.562, 14.71467, 0.407713, 120, 0, 0), -- Lashtail Raptor (Area: 0)
(@CGUID+1127, 49722, 0, 1, 1, -12164.04, 183.965, 16.84793, 2.777112, 120, 0, 0), -- Tree Python (Area: 0) (possible waypoints or random movement)
(@CGUID+1128, 49722, 0, 1, 1, -12181.28, 163.9463, 20.72432, 1.085318, 120, 0, 0), -- Tree Python (Area: 0) (possible waypoints or random movement)
(@CGUID+1129, 686, 0, 1, 1, -12212.04, 156.5757, 16.78609, 0.1516546, 120, 0, 0), -- Lashtail Raptor (Area: 0)
(@CGUID+1130, 686, 0, 1, 1, -12171.96, 173.2179, 16.91576, 4.765178, 120, 0, 0), -- Lashtail Raptor (Area: 0)
(@CGUID+1131, 686, 0, 1, 1, -12155.75, 150.6503, 18.64405, 5.637731, 120, 0, 0), -- Lashtail Raptor (Area: 0)
(@CGUID+1132, 49722, 0, 1, 1, -12136.79, 187.0509, 16.22916, 0.2246023, 120, 0, 0), -- Tree Python (Area: 0) (possible waypoints or random movement)
(@CGUID+1133, 4458, 0, 1, 1, -12155.82, 42.67818, 2.048652, 3.787047, 120, 0, 0), -- Murkgill Hunter (Area: 0) (possible waypoints or random movement)
(@CGUID+1134, 4460, 0, 1, 1, -12161.12, -17.51421, -10.81799, 4.399599, 120, 0, 0), -- Murkgill Lord (Area: Kal'ai Ruins) (possible waypoints or random movement)
(@CGUID+1135, 4458, 0, 1, 1, -12153.53, -8.666016, -6.511437, 3.819078, 120, 0, 0), -- Murkgill Hunter (Area: Kal'ai Ruins) (possible waypoints or random movement)
(@CGUID+1136, 4460, 0, 1, 1, -12185.94, -20.3125, -10, 1.789521, 120, 0, 0), -- Murkgill Lord (Area: Kal'ai Ruins) (possible waypoints or random movement)
(@CGUID+1137, 4460, 0, 1, 1, -12157.81, -31.77148, -10, 0.8394263, 120, 0, 0), -- Murkgill Lord (Area: Kal'ai Ruins) (possible waypoints or random movement)
(@CGUID+1138, 4458, 0, 1, 1, -12140.34, -3.418287, -4.040647, 2.550516, 120, 0, 0), -- Murkgill Hunter (Area: Kal'ai Ruins) (possible waypoints or random movement)
(@CGUID+1139, 4461, 0, 1, 1, -12137.52, -39.69256, -1.856076, 2.449777, 120, 0, 0), -- Murkgill Warrior (Area: Kal'ai Ruins) (possible waypoints or random movement)
(@CGUID+1140, 49722, 0, 1, 1, -12209.39, 32.15556, 15.94815, 4.437576, 120, 0, 0), -- Tree Python (Area: Kal'ai Ruins) (possible waypoints or random movement)
(@CGUID+1141, 4461, 0, 1, 1, -12187.11, 6.421875, 0.4129887, 1.965876, 120, 0, 0), -- Murkgill Warrior (Area: Kal'ai Ruins) (possible waypoints or random movement)
(@CGUID+1142, 4461, 0, 1, 1, -12186.88, 24.73877, 6.953029, 5.878037, 120, 0, 0), -- Murkgill Warrior (Area: Kal'ai Ruins) (possible waypoints or random movement)
(@CGUID+1143, 42173, 0, 1, 1, -6446.698, 6829.101, -1124.952, 1.27409, 120, 0, 0), -- The Undershell Tentacle Flavor (Area: Kal'ai Ruins)
(@CGUID+1144, 49928, 0, 1, 1, -12189.91, -62.46948, 28.81198, 3.757163, 120, 0, 0), -- Crimson Moth (Area: Kal'ai Ruins)
(@CGUID+1145, 4461, 0, 1, 1, -12197.78, -48.71569, -0.251585, 1.052134, 120, 0, 0), -- Murkgill Warrior (Area: Kal'ai Ruins) (possible waypoints or random movement)
(@CGUID+1146, 4458, 0, 1, 1, -12161.18, -52.32277, -0.2506075, 3.174156, 120, 0, 0), -- Murkgill Hunter (Area: Kal'ai Ruins) (possible waypoints or random movement)
(@CGUID+1147, 49722, 0, 1, 1, -12152.14, -107.826, 18.89399, 4.184033, 120, 0, 0), -- Tree Python (Area: Kal'ai Ruins) (possible waypoints or random movement)
(@CGUID+1148, 4457, 0, 1, 1, -12174.13, -105.5697, 16.24839, 2.18437, 120, 0, 0), -- Murkgill Forager (Area: Kal'ai Ruins) (possible waypoints or random movement)
(@CGUID+1149, 50479, 0, 1, 1, -12196.15, -139.1035, 17.01401, 3.264979, 120, 0, 0), -- Lizard Hatchling (Area: 0)
(@CGUID+1150, 15475, 0, 1, 1, -12143.21, -177.6399, 32.01142, 0.3989959, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+1151, 686, 0, 1, 1, -12177.49, -145.8262, 16.87436, 2.544932, 120, 0, 0), -- Lashtail Raptor (Area: 0)
(@CGUID+1152, 686, 0, 1, 1, -12162.82, -179.2723, 31.72294, 4.978675, 120, 0, 0), -- Lashtail Raptor (Area: 0)
(@CGUID+1153, 49928, 0, 1, 1, -12170.28, -135.3583, 38.79847, 1.897459, 120, 0, 0), -- Crimson Moth (Area: 0)
(@CGUID+1154, 49928, 0, 1, 1, -12113.27, -170.3587, 45.21181, 4.150405, 120, 0, 0), -- Crimson Moth (Area: 0)
(@CGUID+1155, 6827, 0, 1, 1, -12192.32, -362.5667, 10.84926, 5.989858, 120, 0, 0), -- Crab (Area: 0)
(@CGUID+1156, 1152, 0, 1, 1, -12141.35, -338.8149, -1.360896, 2.4134, 120, 0, 0), -- Snapjaw Crocolisk (Area: 0) (possible waypoints or random movement)
(@CGUID+1157, 1096, 0, 1, 1, -12149.68, -485.0624, 25.2454, 0.2798235, 120, 0, 0), -- Venture Co. Geologist (Area: Lake Nazferiti)
(@CGUID+1158, 49722, 0, 1, 1, -12135.9, -488.3298, 19.70341, 3.98181, 120, 0, 0), -- Tree Python (Area: Lake Nazferiti) (possible waypoints or random movement)
(@CGUID+1159, 1096, 0, 1, 1, -12147.5, -590.8377, 14.39038, 1.892547, 120, 0, 0), -- Venture Co. Geologist (Area: Venture Co. Base Camp)
(@CGUID+1160, 1096, 0, 1, 1, -12173.42, -553.579, 20.73688, 2.918896, 120, 0, 0), -- Venture Co. Geologist (Area: Venture Co. Base Camp)
(@CGUID+1161, 1096, 0, 1, 1, -12141.95, -708.316, 17.6492, 1.392433, 120, 0, 0), -- Venture Co. Geologist (Area: Venture Co. Base Camp)
(@CGUID+1162, 1096, 0, 1, 1, -12164.73, -622.4509, 16.716, 0.2717103, 120, 0, 0), -- Venture Co. Geologist (Area: Venture Co. Base Camp)
(@CGUID+1163, 49928, 0, 1, 1, -12159.6, -603.2367, 33.86782, 0.7788327, 120, 0, 0), -- Crimson Moth (Area: Venture Co. Base Camp)
(@CGUID+1164, 1096, 0, 1, 1, -12154, -640.5432, 13.94357, 3.217935, 120, 0, 0), -- Venture Co. Geologist (Area: Venture Co. Base Camp)
(@CGUID+1165, 50479, 0, 1, 1, -12163.23, -775.56, 15.90779, 2.11657, 120, 0, 0), -- Lizard Hatchling (Area: Venture Co. Base Camp)
(@CGUID+1166, 2519, 0, 1, 1, -12151.46, -842.7136, 47.5275, 1.757424, 120, 0, 0), -- Kin'weelay (Area: Venture Co. Base Camp)
(@CGUID+1167, 49722, 0, 1, 1, -12157.68, -849.2944, 44.43209, 2.257296, 120, 0, 0), -- Tree Python (Area: Venture Co. Base Camp) (possible waypoints or random movement)
(@CGUID+1168, 50479, 0, 1, 1, -12150.65, -859.389, 46.10264, 2.473868, 120, 0, 0), -- Lizard Hatchling (Area: Venture Co. Base Camp)
(@CGUID+1169, 684, 0, 1, 1, -12047.78, -1018.653, 50.14047, 3.026046, 120, 0, 0), -- Shadowmaw Panther (Area: 0)
(@CGUID+1170, 43351, 0, 1, 1, -12111.77, -1461.721, 147.7663, 1.094082, 120, 0, 0), -- Gurubashi Batling (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+1171, 15475, 0, 1, 1, -12140.96, -1685.241, 84.81335, 0.2445052, 120, 0, 0), -- Beetle (Area: Zul'Gurub)
(@CGUID+1172, 49722, 0, 1, 1, -12153.12, -1945.792, 133.3424, 0.7101147, 120, 0, 0), -- Tree Python (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+1173, 15475, 0, 1, 1, -12259.1, -1928.082, 131.1655, 2.761086, 120, 0, 0), -- Beetle (Area: Zul'Gurub)
(@CGUID+1174, 50479, 0, 1, 1, -12229.4, -1952.021, 130.5389, 5.750471, 120, 0, 0), -- Lizard Hatchling (Area: Zul'Gurub)
(@CGUID+1175, 50487, 0, 1, 1, -12211, -1887.519, 137.717, 1.517103, 120, 0, 0), -- Forest Spiderling (Area: Zul'Gurub)
(@CGUID+1176, 32520, 0, 1, 1, -5691.65, 5556.92, -1154.687, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Zul'Gurub)
(@CGUID+1177, 32520, 0, 1, 1, -6148.39, 5539.97, -1207.787, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Zul'Gurub)
(@CGUID+1178, 32520, 0, 1, 1, -6305.162, 5582.533, -1172.063, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Zul'Gurub)
(@CGUID+1179, 32520, 0, 1, 1, -6014.71, 5479.63, -1208.007, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Zul'Gurub)
(@CGUID+1180, 50487, 0, 1, 1, -12205.55, -1680.504, 116.2656, 4.539423, 120, 0, 0), -- Forest Spiderling (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+1181, 43351, 0, 1, 1, -12245.33, -1476.624, 145.3103, 2.046921, 120, 0, 0), -- Gurubashi Batling (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+1182, 43351, 0, 1, 1, -12203.68, -1437.701, 147.3743, 0.3945865, 120, 0, 0), -- Gurubashi Batling (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+1183, 43351, 0, 1, 1, -12221.4, -1416.298, 143.2003, 4.503037, 120, 0, 0), -- Gurubashi Batling (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+1184, 15475, 0, 1, 1, -12171.44, -1460.886, 130.9179, 4.726075, 120, 0, 0), -- Beetle (Area: Zul'Gurub)
(@CGUID+1185, 43351, 0, 1, 1, -12202.93, -1455.086, 143.8183, 4.236159, 120, 0, 0), -- Gurubashi Batling (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+1186, 43351, 0, 1, 1, -12172.17, -1462.974, 143.8513, 1.307671, 120, 0, 0), -- Gurubashi Batling (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+1187, 43351, 0, 1, 1, -12246.74, -1407.524, 144.7823, 5.145658, 120, 0, 0), -- Gurubashi Batling (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+1188, 49722, 0, 1, 1, -12240.75, -1410.023, 130.7252, 3.657201, 120, 0, 0), -- Tree Python (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+1189, 15475, 0, 1, 1, -12255.55, -1424.598, 130.7252, 3.952732, 120, 0, 0), -- Beetle (Area: Zul'Gurub)
(@CGUID+1190, 15475, 0, 1, 1, -12167.21, -982.5372, 39.8146, 0.6719979, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+1191, 15475, 0, 1, 1, -12190.56, -948.1028, 38.94527, 5.800343, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+1192, 15475, 0, 1, 1, -12238.34, -983.9114, 34.36876, 3.763205, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+1193, 15475, 0, 1, 1, -12232.04, -916.2958, 43.00808, 5.559948, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+1194, 684, 0, 1, 1, -12149.2, -975.8729, 41.67937, 4.219903, 120, 0, 0), -- Shadowmaw Panther (Area: 0)
(@CGUID+1195, 709, 0, 1, 1, -12218.38, -787.6501, 16.27486, 3.994661, 120, 0, 0), -- Mosh'Ogg Warmonger (Area: Bambala)
(@CGUID+1196, 1096, 0, 1, 1, -12182.81, -743.2285, 32.22418, 5.566107, 120, 0, 0), -- Venture Co. Geologist (Area: Bambala)
(@CGUID+1197, 51521, 0, 1, 1, -12138.8, -838.191, 44.08225, 0, 120, 0, 0), -- Bambala Headhunter (Area: Bambala)
(@CGUID+1198, 684, 0, 1, 1, -12137.82, -785.3554, 18.74688, 5.924474, 120, 0, 0), -- Shadowmaw Panther (Area: Bambala)
(@CGUID+1199, 1096, 0, 1, 1, -12178.23, -686.0986, 14.90701, 2.531703, 120, 0, 0), -- Venture Co. Geologist (Area: Venture Co. Base Camp)
(@CGUID+1200, 50487, 0, 1, 1, -12192.23, -684.7056, 16.36111, 1.177365, 120, 0, 0), -- Forest Spiderling (Area: Venture Co. Base Camp) (possible waypoints or random movement)
(@CGUID+1201, 15475, 0, 1, 1, -12178.49, -618.7874, 16.27069, 1.654916, 120, 0, 0), -- Beetle (Area: Venture Co. Base Camp)
(@CGUID+1202, 50487, 0, 1, 1, -12191.06, -543.8846, 28.26153, 5.457121, 120, 0, 0), -- Forest Spiderling (Area: Venture Co. Base Camp) (possible waypoints or random movement)
(@CGUID+1203, 9600, 0, 1, 1, -12221.7, -523.9816, 45.23046, 3.205806, 120, 0, 0), -- Parrot (Area: Venture Co. Base Camp)
(@CGUID+1204, 42173, 0, 1, 1, -6230.174, 6798.166, -1075.454, 6.143559, 120, 0, 0), -- The Undershell Tentacle Flavor (Area: Venture Co. Base Camp)
(@CGUID+1205, 687, 0, 1, 1, -12216.98, -458.5521, 28.68472, 5.522644, 120, 0, 0), -- Jungle Stalker (Area: Venture Co. Base Camp)
(@CGUID+1206, 49722, 0, 1, 1, -12209.94, -425.4905, 17.71638, 1.798567, 120, 0, 0), -- Tree Python (Area: Venture Co. Base Camp) (possible waypoints or random movement)
(@CGUID+1207, 6827, 0, 1, 1, -12190.98, -374.0301, 13.87, 5.540574, 120, 0, 0), -- Crab (Area: Venture Co. Base Camp)
(@CGUID+1208, 49722, 0, 1, 1, -12211.02, -390.803, 15.23128, 3.213305, 120, 0, 0), -- Tree Python (Area: Venture Co. Base Camp) (possible waypoints or random movement)
(@CGUID+1209, 2635, 0, 1, 1, -12214.46, -377.4635, 15.29207, 0.4795954, 120, 0, 0), -- Elder Saltwater Crocolisk (Area: Lake Nazferiti) (possible waypoints or random movement)
(@CGUID+1210, 686, 0, 1, 1, -12217.91, -254.5886, 16.46808, 5.707628, 120, 0, 0), -- Lashtail Raptor (Area: 0)
(@CGUID+1211, 49722, 0, 1, 1, -12225.21, -258.7252, 16.04314, 5.472847, 120, 0, 0), -- Tree Python (Area: 0) (possible waypoints or random movement)
(@CGUID+1212, 686, 0, 1, 1, -12221.69, -120.9896, 16.85321, 1.657374, 120, 0, 0), -- Lashtail Raptor (Area: 0)
(@CGUID+1213, 49928, 0, 1, 1, -12225.18, -127.669, 36.67984, 6.125062, 120, 0, 0), -- Crimson Moth (Area: 0)
(@CGUID+1214, 50487, 0, 1, 1, -12228.15, 84.5225, 22.60165, 4.695155, 120, 0, 0), -- Forest Spiderling (Area: Kal'ai Ruins) (possible waypoints or random movement)
(@CGUID+1215, 686, 0, 1, 1, -12228.53, 80.01542, 22.52581, 4.089315, 120, 0, 0), -- Lashtail Raptor (Area: Kal'ai Ruins)
(@CGUID+1216, 871, 0, 1, 1, -12258.3, 729.5739, -65.89024, 2.811406, 120, 0, 0), -- Saltscale Warrior (Area: The Vile Reef) (possible waypoints or random movement)
(@CGUID+1217, 877, 0, 1, 1, -12324.15, 644.6968, -43.01069, 3.900894, 120, 0, 0), -- Saltscale Forager (Area: The Vile Reef) (possible waypoints or random movement)
(@CGUID+1218, 879, 0, 1, 1, -12292.58, 603.2757, -79.34402, 2.983187, 120, 0, 0), -- Saltscale Hunter (Area: The Vile Reef) (possible waypoints or random movement)
(@CGUID+1219, 879, 0, 1, 1, -12277.01, 510.527, -79.20969, 3.483838, 120, 0, 0), -- Saltscale Hunter (Area: The Vile Reef) (possible waypoints or random movement)
(@CGUID+1220, 877, 0, 1, 1, -12303.9, 507.6695, -85.42534, 5.302206, 120, 0, 0), -- Saltscale Forager (Area: The Vile Reef) (possible waypoints or random movement)
(@CGUID+1221, 877, 0, 1, 1, -12323.96, 528.125, -64.94075, 1.570796, 120, 0, 0), -- Saltscale Forager (Area: The Vile Reef) (possible waypoints or random movement)
(@CGUID+1222, 871, 0, 1, 1, -12256.78, 497.0474, -76.01337, 5.93513, 120, 0, 0), -- Saltscale Warrior (Area: The Vile Reef) (possible waypoints or random movement)
(@CGUID+1223, 877, 0, 1, 1, -12284.57, 542.6978, -83.99416, 5.652579, 120, 0, 0), -- Saltscale Forager (Area: The Vile Reef) (possible waypoints or random movement)
(@CGUID+1224, 6827, 0, 1, 1, -12293.91, 313.6947, 1.164161, 0.06968077, 120, 0, 0), -- Crab (Area: The Savage Coast)
(@CGUID+1225, 15475, 0, 1, 1, -12286.08, 217.457, 5.153131, 2.908936, 120, 0, 0), -- Beetle (Area: The Savage Coast)
(@CGUID+1226, 49928, 0, 1, 1, -12281.54, 191.3757, 26.45029, 0.8674263, 120, 0, 0), -- Crimson Moth (Area: 0)
(@CGUID+1227, 686, 0, 1, 1, -12259.61, 44.06753, 20.43289, 4.493754, 120, 0, 0), -- Lashtail Raptor (Area: 0)
(@CGUID+1228, 686, 0, 1, 1, -12272.05, -14.14484, 23.73859, 4.011226, 120, 0, 0), -- Lashtail Raptor (Area: Kal'ai Ruins)
(@CGUID+1229, 49722, 0, 1, 1, -12231.71, -92.7451, 26.30153, 5.695183, 120, 0, 0), -- Tree Python (Area: Kal'ai Ruins) (possible waypoints or random movement)
(@CGUID+1230, 43050, 0, 1, 1, -12245.96, -87.72695, 32.72451, 3.10255, 120, 0, 0), -- Vale Howler (Area: Kal'ai Ruins) (possible waypoints or random movement)
(@CGUID+1231, 686, 0, 1, 1, -12253.43, -82.55351, 30.93521, 3.797667, 120, 0, 0), -- Lashtail Raptor (Area: Kal'ai Ruins)
(@CGUID+1232, 686, 0, 1, 1, -12247.34, -229.0089, 16.2143, 4.734168, 120, 0, 0), -- Lashtail Raptor (Area: 0)
(@CGUID+1233, 905, 0, 1, 1, -12254.25, -320.7826, -2.224945, 5.415821, 120, 0, 0), -- Sharptooth Frenzy (Area: 0) (possible waypoints or random movement)
(@CGUID+1234, 2635, 0, 1, 1, -12230.88, -295.6322, 15.19756, 0.04452214, 120, 0, 0), -- Elder Saltwater Crocolisk (Area: 0) (possible waypoints or random movement)
(@CGUID+1235, 687, 0, 1, 1, -12244.74, -411.0236, 16.73912, 0.07132792, 120, 0, 0), -- Jungle Stalker (Area: 0)
(@CGUID+1236, 1152, 0, 1, 1, -12089.8, -419.2246, 10.47243, 4.528004, 120, 0, 0), -- Snapjaw Crocolisk (Area: 0) (possible waypoints or random movement)
(@CGUID+1237, 6827, 0, 1, 1, -12229.33, -374.3152, 15.2115, 5.410865, 120, 0, 0), -- Crab (Area: 0)
(@CGUID+1238, 1152, 0, 1, 1, -12113.59, -381.1937, 11.73472, 0.3753283, 120, 0, 0), -- Snapjaw Crocolisk (Area: 0) (possible waypoints or random movement)
(@CGUID+1239, 687, 0, 1, 1, -12247.36, -489.0859, 21.16814, 5.435627, 120, 0, 0), -- Jungle Stalker (Area: 0)
(@CGUID+1240, 50487, 0, 1, 1, -12235.6, -604.607, 31.49378, 0.04497943, 120, 0, 0), -- Forest Spiderling (Area: 0) (possible waypoints or random movement)
(@CGUID+1241, 50479, 0, 1, 1, -12252.4, -666.6443, 15.83067, 5.099064, 120, 0, 0), -- Lizard Hatchling (Area: Venture Co. Base Camp)
(@CGUID+1242, 32520, 0, 1, 1, -6305.162, 5582.533, -1172.063, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Zul'Gurub)
(@CGUID+1243, 32520, 0, 1, 1, -6014.71, 5479.63, -1208.007, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Zul'Gurub)
(@CGUID+1244, 32520, 0, 1, 1, -5691.65, 5556.92, -1154.687, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Zul'Gurub)
(@CGUID+1245, 32520, 0, 1, 1, -6148.39, 5539.97, -1207.787, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Zul'Gurub)
(@CGUID+1246, 15475, 0, 1, 1, -12339.06, -1903.646, 131.2247, 1.95521, 120, 0, 0), -- Beetle (Area: Zul'Gurub)
(@CGUID+1247, 50487, 0, 1, 1, -12319.93, -1857.959, 130.3816, 6.116668, 120, 0, 0), -- Forest Spiderling (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+1248, 50487, 0, 1, 1, -12320.2, -1850.836, 130.3816, 4.201772, 120, 0, 0), -- Forest Spiderling (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+1249, 50479, 0, 1, 1, -12326.49, -1658.131, 130.3561, 0.4840146, 120, 0, 0), -- Lizard Hatchling (Area: Zul'Gurub)
(@CGUID+1250, 50479, 0, 1, 1, -12287.48, -1620.981, 130.8449, 5.861027, 120, 0, 0), -- Lizard Hatchling (Area: Zul'Gurub)
(@CGUID+1251, 50479, 0, 1, 1, -12303.04, -1479.803, 131.7374, 5.413383, 120, 0, 0), -- Lizard Hatchling (Area: Zul'Gurub)
(@CGUID+1252, 43351, 0, 1, 1, -12276.04, -1426.327, 143.1993, 0.5495278, 120, 0, 0), -- Gurubashi Batling (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+1253, 43351, 0, 1, 1, -12286.58, -1444.038, 143.2003, 1.252899, 120, 0, 0), -- Gurubashi Batling (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+1254, 50479, 0, 1, 1, -12295.75, -1430.722, 131.277, 5.843135, 120, 0, 0), -- Lizard Hatchling (Area: Zul'Gurub)
(@CGUID+1255, 43351, 0, 1, 1, -12304.33, -1462.969, 143.2003, 4.581681, 120, 0, 0), -- Gurubashi Batling (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+1256, 4076, 0, 1, 1, -12352.1, -1127.673, -0.6925997, 3.68406, 120, 0, 0), -- Roach (Area: Zul'Gurub)
(@CGUID+1257, 48972, 0, 1, 1, -12345.8, -1108.335, 1.550689, 4.591065, 120, 0, 0), -- Long-tailed Mole (Area: Zul'Gurub)
(@CGUID+1258, 680, 0, 1, 1, -12302.69, -1105.112, 5.844067, 1.553343, 120, 0, 0), -- Mosh'Ogg Lord (Area: Zul'Gurub)
(@CGUID+1259, 4076, 0, 1, 1, -12341.64, -1095.074, 2.593894, 3.651251, 120, 0, 0), -- Roach (Area: Zul'Gurub)
(@CGUID+1260, 818, 0, 1, 1, -12341.8, -1157.96, 3.135473, 2.251475, 120, 0, 0), -- Mai'Zoth (Area: Zul'Gurub)
(@CGUID+1261, 679, 0, 1, 1, -12343.71, -1108.635, 1.330078, 5.930999, 120, 0, 0), -- Mosh'Ogg Shaman (Area: Zul'Gurub)
(@CGUID+1262, 678, 0, 1, 1, -12332.95, -1082.981, 4.917634, 4.087097, 120, 0, 0), -- Mosh'Ogg Mauler (Area: Zul'Gurub)
(@CGUID+1263, 4076, 0, 1, 1, -12308.1, -1038.695, 7.171811, 3.690679, 120, 0, 0), -- Roach (Area: Zul'Gurub)
(@CGUID+1264, 4076, 0, 1, 1, -12323.04, -1056.577, 8.64891, 1.751901, 120, 0, 0), -- Roach (Area: Zul'Gurub)
(@CGUID+1265, 678, 0, 1, 1, -12298.64, -1034.698, 7.451162, 1.697272, 120, 0, 0), -- Mosh'Ogg Mauler (Area: Zul'Gurub)
(@CGUID+1266, 679, 0, 1, 1, -12323.08, -1064.152, 6.542744, 2.673946, 120, 0, 0), -- Mosh'Ogg Shaman (Area: Zul'Gurub)
(@CGUID+1267, 678, 0, 1, 1, -12302.96, -1063.746, 12.03145, 4.62708, 120, 0, 0), -- Mosh'Ogg Mauler (Area: Zul'Gurub)
(@CGUID+1268, 679, 0, 1, 1, -12323.4, -1064.074, 6.486145, 0.7805588, 120, 0, 0), -- Mosh'Ogg Shaman (Area: Zul'Gurub)
(@CGUID+1269, 48972, 0, 1, 1, -12322.63, -1026.858, 9.06266, 5.464207, 120, 0, 0), -- Long-tailed Mole (Area: 0)
(@CGUID+1270, 48972, 0, 1, 1, -12335.05, -1025.723, 8.135864, 3.985363, 120, 0, 0), -- Long-tailed Mole (Area: 0)
(@CGUID+1271, 679, 0, 1, 1, -12348.83, -1019.59, 7.924525, 3.461848, 120, 0, 0), -- Mosh'Ogg Shaman (Area: 0)
(@CGUID+1272, 679, 0, 1, 1, -12335.01, -1034.684, 7.894657, 4.886922, 120, 0, 0), -- Mosh'Ogg Shaman (Area: 0)
(@CGUID+1273, 679, 0, 1, 1, -12321.83, -1023.914, 8.896724, 5.604472, 120, 0, 0), -- Mosh'Ogg Shaman (Area: 0)
(@CGUID+1274, 709, 0, 1, 1, -12291.49, -1005.992, 29.77973, 6.034517, 120, 0, 0), -- Mosh'Ogg Warmonger (Area: 0)
(@CGUID+1275, 50479, 0, 1, 1, -12297.51, -904.8845, 9.730742, 3.378049, 120, 0, 0), -- Lizard Hatchling (Area: Mosh'Ogg Ogre Mound)
(@CGUID+1276, 709, 0, 1, 1, -12320.39, -915.1377, 9.122411, 1.368752, 120, 0, 0), -- Mosh'Ogg Warmonger (Area: Mosh'Ogg Ogre Mound)
(@CGUID+1277, 709, 0, 1, 1, -12287.81, -885.9284, 7.722762, 0.8064305, 120, 0, 0), -- Mosh'Ogg Warmonger (Area: Mosh'Ogg Ogre Mound)
(@CGUID+1278, 15475, 0, 1, 1, -12339.66, -832.0935, 37.30443, 1.429728, 120, 0, 0), -- Beetle (Area: Mosh'Ogg Ogre Mound)
(@CGUID+1279, 709, 0, 1, 1, -12250.2, -741.8003, 15.37109, 2.392091, 120, 0, 0), -- Mosh'Ogg Warmonger (Area: Mosh'Ogg Ogre Mound)
(@CGUID+1280, 43050, 0, 1, 1, -12328.14, -712.3156, 17.10636, 6.161739, 120, 0, 0), -- Vale Howler (Area: Venture Co. Base Camp) (possible waypoints or random movement)
(@CGUID+1281, 49928, 0, 1, 1, -12290.63, -710.4906, 33.65037, 0.7895529, 120, 0, 0), -- Crimson Moth (Area: Venture Co. Base Camp)
(@CGUID+1282, 49928, 0, 1, 1, -12259.12, -658.8661, 42.79124, 3.482588, 120, 0, 0), -- Crimson Moth (Area: Venture Co. Base Camp)
(@CGUID+1283, 687, 0, 1, 1, -12287.54, -580.7781, 28.81942, 0.7085033, 120, 0, 0), -- Jungle Stalker (Area: Venture Co. Base Camp)
(@CGUID+1284, 687, 0, 1, 1, -12314.91, -617.6655, 29.86132, 1.849901, 120, 0, 0), -- Jungle Stalker (Area: Venture Co. Base Camp)
(@CGUID+1285, 43050, 0, 1, 1, -12295.92, -479.6017, 15.99298, 1.109766, 120, 0, 0), -- Vale Howler (Area: 0) (possible waypoints or random movement)
(@CGUID+1286, 687, 0, 1, 1, -12274.56, -457.4689, 17.61509, 4.575011, 120, 0, 0), -- Jungle Stalker (Area: 0)
(@CGUID+1287, 687, 0, 1, 1, -12312.3, -491.3699, 14.88663, 4.545251, 120, 0, 0), -- Jungle Stalker (Area: 0)
(@CGUID+1288, 687, 0, 1, 1, -12281.44, -521.6464, 17.22398, 4.648427, 120, 0, 0), -- Jungle Stalker (Area: 0)
(@CGUID+1289, 50487, 0, 1, 1, -12305.15, -475.4152, 15.79987, 1.529804, 120, 0, 0), -- Forest Spiderling (Area: 0) (possible waypoints or random movement)
(@CGUID+1290, 687, 0, 1, 1, -12276.72, -384.5109, 15.21985, 5.374473, 120, 0, 0), -- Jungle Stalker (Area: 0)
(@CGUID+1291, 1152, 0, 1, 1, -12142.71, -341.6077, -0.6431227, 4.251841, 120, 0, 0), -- Snapjaw Crocolisk (Area: 0) (possible waypoints or random movement)
(@CGUID+1292, 686, 0, 1, 1, -12275.37, -245.7563, 16.18373, 0.8641034, 120, 0, 0), -- Lashtail Raptor (Area: 0)
(@CGUID+1293, 15475, 0, 1, 1, -12294.21, -20.4318, 24.55342, 6.1084, 120, 0, 0), -- Beetle (Area: Kal'ai Ruins)
(@CGUID+1294, 686, 0, 1, 1, -12295.93, -45.94408, 31.99685, 2.679275, 120, 0, 0), -- Lashtail Raptor (Area: Kal'ai Ruins)
(@CGUID+1295, 877, 0, 1, 1, -12340.2, 714.0714, -26.24491, 4.045445, 120, 0, 0), -- Saltscale Forager (Area: The Vile Reef) (possible waypoints or random movement)
(@CGUID+1296, 877, 0, 1, 1, -12367.71, 665.625, -36.91029, 3.141652, 120, 0, 0), -- Saltscale Forager (Area: The Vile Reef) (possible waypoints or random movement)
(@CGUID+1297, 877, 0, 1, 1, -12354.94, 705.7102, -20.22137, 2.927411, 120, 0, 0), -- Saltscale Forager (Area: The Vile Reef) (possible waypoints or random movement)
(@CGUID+1298, 871, 0, 1, 1, -12354.93, 692.9257, -20.7563, 3.21797, 120, 0, 0), -- Saltscale Warrior (Area: The Vile Reef) (possible waypoints or random movement)
(@CGUID+1299, 9600, 0, 1, 1, -12352.56, 279.1135, 17.38029, 0.7385934, 120, 0, 0), -- Parrot (Area: The Savage Coast)
(@CGUID+1300, 6827, 0, 1, 1, -12361.33, 286.9218, 0.5475386, 4.590942, 120, 0, 0), -- Crab (Area: The Savage Coast)
(@CGUID+1301, 1064, 0, 1, 1, -12332.65, 190.717, 25.67431, 1.570796, 120, 0, 0), -- Grom'gol Grunt (Area: 0)
(@CGUID+1302, 1064, 0, 1, 1, -12334.47, 176.8272, 3.334138, 6.230825, 120, 0, 0), -- Grom'gol Grunt (Area: 0)
(@CGUID+1303, 1064, 0, 1, 1, -12333.77, 171.2656, 3.80046, 0.06981317, 120, 0, 0), -- Grom'gol Grunt (Area: 0)
(@CGUID+1304, 1064, 0, 1, 1, -12349.72, 194.6567, 4.332952, 3.159046, 120, 0, 0), -- Grom'gol Grunt (Area: 0)
(@CGUID+1305, 1382, 0, 1, 1, -12358.78, 220.8107, 4.141724, 5.009095, 120, 0, 0), -- Mudduk (Area: 0)
(@CGUID+1306, 1149, 0, 1, 1, -12357.98, 207.3547, 4.231615, 3.735005, 120, 0, 0), -- Uthok (Area: 0)
(@CGUID+1307, 2856, 0, 1, 1, -12335.47, 163.1845, 3.065459, 2.70526, 120, 0, 0), -- Angrun (Area: 0)
(@CGUID+1308, 1146, 0, 1, 1, -12357.8, 155.552, 4.328534, 1.291544, 120, 0, 0), -- Vharr (Area: 0)
(@CGUID+1309, 1381, 0, 1, 1, -12357.68, 142.3785, 4.560385, 5.550147, 120, 0, 0), -- Krakk (Area: 0)
(@CGUID+1310, 9600, 0, 1, 1, -12349.65, 66.23747, 24.46266, 4.313941, 120, 0, 0), -- Parrot (Area: 0)
(@CGUID+1311, 9600, 0, 1, 1, -12359.84, 71.02216, 30.18824, 2.84969, 120, 0, 0), -- Parrot (Area: 0)
(@CGUID+1312, 9600, 0, 1, 1, -12370.7, 86.73108, 25.37956, 4.879272, 120, 0, 0), -- Parrot (Area: 0)
(@CGUID+1313, 49722, 0, 1, 1, -12318.69, 54.76954, 11.58381, 5.632257, 120, 0, 0), -- Tree Python (Area: 0) (possible waypoints or random movement)
(@CGUID+1314, 686, 0, 1, 1, -12315.58, -19.57397, 20.39334, 4.127849, 120, 0, 0), -- Lashtail Raptor (Area: 0)
(@CGUID+1315, 686, 0, 1, 1, -12302.46, -85.998, 33.29166, 0.7854375, 120, 0, 0), -- Lashtail Raptor (Area: 0)
(@CGUID+1316, 49722, 0, 1, 1, -12342.46, -179.2893, 18.62992, 1.468988, 120, 0, 0), -- Tree Python (Area: 0) (possible waypoints or random movement)
(@CGUID+1317, 686, 0, 1, 1, -12320.86, -196.2854, 14.62652, 1.508859, 120, 0, 0), -- Lashtail Raptor (Area: 0)
(@CGUID+1318, 49928, 0, 1, 1, -12336.67, -136.9102, 32.67893, 4.419688, 120, 0, 0), -- Crimson Moth (Area: 0)
(@CGUID+1319, 6827, 0, 1, 1, -12324.42, -279.0608, 10.68843, 5.519883, 120, 0, 0), -- Crab (Area: 0)
(@CGUID+1320, 50479, 0, 1, 1, -12326.74, -250.4712, 16.1324, 3.727968, 120, 0, 0), -- Lizard Hatchling (Area: 0)
(@CGUID+1321, 686, 0, 1, 1, -12350.86, -186.1893, 20.00638, 4.642056, 120, 0, 0), -- Lashtail Raptor (Area: 0)
(@CGUID+1322, 6827, 0, 1, 1, -12374.29, -324.4637, 11.49818, 6.277643, 120, 0, 0), -- Crab (Area: 0)
(@CGUID+1323, 6827, 0, 1, 1, -12374.17, -333.3952, 14.75815, 4.788562, 120, 0, 0), -- Crab (Area: 0)
(@CGUID+1324, 2635, 0, 1, 1, -12326.05, -342.3344, 16.3745, 2.01677, 120, 0, 0), -- Elder Saltwater Crocolisk (Area: 0) (possible waypoints or random movement)
(@CGUID+1325, 687, 0, 1, 1, -12350.3, -449.2001, 14.97865, 3.90334, 120, 0, 0), -- Jungle Stalker (Area: 0)
(@CGUID+1326, 687, 0, 1, 1, -12341.57, -392.1098, 17.28633, 5.607173, 120, 0, 0), -- Jungle Stalker (Area: 0)
(@CGUID+1327, 49722, 0, 1, 1, -12343.6, -397.9143, 16.92368, 4.688956, 120, 0, 0), -- Tree Python (Area: 0) (possible waypoints or random movement)
(@CGUID+1328, 50479, 0, 1, 1, -12323.22, -577.8203, 25.43663, 3.008266, 120, 0, 0), -- Lizard Hatchling (Area: 0)
(@CGUID+1329, 687, 0, 1, 1, -12340.66, -527.088, 15.62599, 5.748451, 120, 0, 0), -- Jungle Stalker (Area: 0)
(@CGUID+1330, 9600, 0, 1, 1, -12346.55, -592.7426, 36.94424, 0.2009676, 120, 0, 0), -- Parrot (Area: 0)
(@CGUID+1331, 687, 0, 1, 1, -12354.98, -653.7201, 15.82254, 0.880808, 120, 0, 0), -- Jungle Stalker (Area: 0)
(@CGUID+1332, 49928, 0, 1, 1, -12359.1, -649.1226, 33.85315, 0.09376436, 120, 0, 0), -- Crimson Moth (Area: 0)
(@CGUID+1333, 15475, 0, 1, 1, -12357.92, -655.3325, 17.28812, 2.1266, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+1334, 49928, 0, 1, 1, -12362.1, -776.4222, 49.38492, 0.07489736, 120, 0, 0), -- Crimson Moth (Area: Venture Co. Base Camp)
(@CGUID+1335, 678, 0, 1, 1, -12357.01, -981.5867, 13.81584, 5.716754, 120, 0, 0), -- Mosh'Ogg Mauler (Area: Mosh'Ogg Ogre Mound)
(@CGUID+1336, 684, 0, 1, 1, -12256.36, -956.235, 43.94353, 4.16608, 120, 0, 0), -- Shadowmaw Panther (Area: Mosh'Ogg Ogre Mound)
(@CGUID+1337, 4076, 0, 1, 1, -12355.73, -1080.247, 2.0567, 4.285623, 120, 0, 0), -- Roach (Area: Mosh'Ogg Ogre Mound)
(@CGUID+1338, 4076, 0, 1, 1, -12344.33, -1069.263, 3.435285, 3.040876, 120, 0, 0), -- Roach (Area: Mosh'Ogg Ogre Mound)
(@CGUID+1339, 679, 0, 1, 1, -12353.46, -1082.757, 2.506469, 5.16274, 120, 0, 0), -- Mosh'Ogg Shaman (Area: Mosh'Ogg Ogre Mound)
(@CGUID+1340, 48972, 0, 1, 1, -12357.2, -1039.037, 3.600057, 0.5146419, 120, 0, 0), -- Long-tailed Mole (Area: Mosh'Ogg Ogre Mound)
(@CGUID+1341, 678, 0, 1, 1, -12355.89, -1057.772, 6.595316, 3.396993, 120, 0, 0), -- Mosh'Ogg Mauler (Area: Mosh'Ogg Ogre Mound)
(@CGUID+1342, 48972, 0, 1, 1, -12354.1, -1148.579, 0.8555143, 1.320803, 120, 0, 0), -- Long-tailed Mole (Area: Mosh'Ogg Ogre Mound)
(@CGUID+1343, 48972, 0, 1, 1, -12356.78, -1143.387, 0.4433313, 5.396409, 120, 0, 0), -- Long-tailed Mole (Area: Mosh'Ogg Ogre Mound)
(@CGUID+1344, 818, 0, 1, 1, -12341.8, -1157.96, 3.135473, 2.251475, 120, 0, 0), -- Mai'Zoth (Area: Mosh'Ogg Ogre Mound)
(@CGUID+1345, 50479, 0, 1, 1, -12354.13, -1617.232, 130.6058, 2.172883, 120, 0, 0), -- Lizard Hatchling (Area: Zul'Gurub)
(@CGUID+1346, 49722, 0, 1, 1, -12369.78, -1914.333, 132.8324, 4.681046, 120, 0, 0), -- Tree Python (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+1347, 49722, 0, 1, 1, -12381.5, -1831.947, 131.5168, 2.640151, 120, 0, 0), -- Tree Python (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+1348, 50487, 0, 1, 1, -12360.96, -1837.064, 130.9436, 2.512057, 120, 0, 0), -- Forest Spiderling (Area: Zul'Gurub) (possible waypoints or random movement)
(@CGUID+1349, 32520, 0, 1, 1, -6014.71, 5479.63, -1208.007, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Zul'Gurub)
(@CGUID+1350, 32520, 0, 1, 1, -6305.162, 5582.533, -1172.063, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Zul'Gurub)
(@CGUID+1351, 32520, 0, 1, 1, -5691.65, 5556.92, -1154.687, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Zul'Gurub)
(@CGUID+1352, 32520, 0, 1, 1, -6148.39, 5539.97, -1207.787, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Zul'Gurub)
(@CGUID+1353, 4076, 0, 1, 1, -12366.97, -1128.892, 2.217463, 3.61351, 120, 0, 0), -- Roach (Area: Zul'Gurub)
(@CGUID+1354, 4076, 0, 1, 1, -12382.76, -1068.948, 3.755946, 3.960963, 120, 0, 0), -- Roach (Area: 0)
(@CGUID+1355, 48972, 0, 1, 1, -12367.18, -1062.831, 3.915306, 3.878258, 120, 0, 0), -- Long-tailed Mole (Area: 0)
(@CGUID+1356, 710, 0, 1, 1, -12381.42, -1064.673, 3.688051, 0.3092495, 120, 0, 0), -- Mosh'Ogg Spellcrafter (Area: 0)
(@CGUID+1357, 709, 0, 1, 1, -12410.91, -950.3997, 28.09881, 5.279556, 120, 0, 0), -- Mosh'Ogg Warmonger (Area: Mosh'Ogg Ogre Mound)
(@CGUID+1358, 709, 0, 1, 1, -12386.58, -888.8807, 46.91467, 3.32084, 120, 0, 0), -- Mosh'Ogg Warmonger (Area: Mosh'Ogg Ogre Mound)
(@CGUID+1359, 50479, 0, 1, 1, -12390.32, -877.4902, 45.76864, 5.511599, 120, 0, 0), -- Lizard Hatchling (Area: Mosh'Ogg Ogre Mound)
(@CGUID+1360, 684, 0, 1, 1, -12320.93, -817.4666, 31.66812, 0.01562045, 120, 0, 0), -- Shadowmaw Panther (Area: Mosh'Ogg Ogre Mound)
(@CGUID+1361, 684, 0, 1, 1, -12307.25, -750.7715, 15.44845, 0.2457551, 120, 0, 0), -- Shadowmaw Panther (Area: 0)
(@CGUID+1362, 684, 0, 1, 1, -12286.38, -727.7516, 13.59786, 1.263251, 120, 0, 0), -- Shadowmaw Panther (Area: 0)
(@CGUID+1363, 687, 0, 1, 1, -12386.98, -674.5063, 17.72351, 1.758993, 120, 0, 0), -- Jungle Stalker (Area: 0)
(@CGUID+1364, 684, 0, 1, 1, -12313.86, -687.2971, 16.11596, 3.80285, 120, 0, 0), -- Shadowmaw Panther (Area: 0)
(@CGUID+1365, 687, 0, 1, 1, -12387.87, -555.2936, 11.78309, 3.882091, 120, 0, 0), -- Jungle Stalker (Area: 0)
(@CGUID+1366, 687, 0, 1, 1, -12387.28, -608.7042, 15.4395, 1.852511, 120, 0, 0), -- Jungle Stalker (Area: 0)
(@CGUID+1367, 49928, 0, 1, 1, -12393.41, -590.1572, 26.19656, 0.4993691, 120, 0, 0), -- Crimson Moth (Area: 0)
(@CGUID+1368, 49722, 0, 1, 1, -12393.65, -476.4609, 17.1133, 4.255722, 120, 0, 0), -- Tree Python (Area: 0) (possible waypoints or random movement)
(@CGUID+1369, 687, 0, 1, 1, -12385.08, -415.1663, 15.32188, 1.888257, 120, 0, 0), -- Jungle Stalker (Area: 0)
(@CGUID+1370, 687, 0, 1, 1, -12380.42, -485.8755, 16.72942, 3.444368, 120, 0, 0), -- Jungle Stalker (Area: 0)
(@CGUID+1371, 43050, 0, 1, 1, -12376.98, -427.6054, 15.40342, 2.09959, 120, 0, 0), -- Vale Howler (Area: 0) (possible waypoints or random movement)
(@CGUID+1372, 2635, 0, 1, 1, -12378.19, -344.8378, 19.83212, 4.484047, 120, 0, 0), -- Elder Saltwater Crocolisk (Area: 0) (possible waypoints or random movement)
(@CGUID+1373, 14487, 0, 1, 1, -12184.24, -27.94021, -10.81799, 6.03267, 120, 0, 0), -- Gluggle (Area: 0) (possible waypoints or random movement)
(@CGUID+1374, 1064, 0, 1, 1, -12372.84, 179.3254, 3.288847, 2.897247, 120, 0, 0), -- Grom'gol Grunt (Area: 0)
(@CGUID+1375, 1064, 0, 1, 1, -12373.97, 184.474, 3.340544, 3.787364, 120, 0, 0), -- Grom'gol Grunt (Area: 0)
(@CGUID+1376, 877, 0, 1, 1, -12361.43, 615.6678, -70.69299, 4.603528, 120, 0, 0), -- Saltscale Forager (Area: The Vile Reef) (possible waypoints or random movement)
(@CGUID+1377, 5434, 0, 1, 1, -12449.98, 1518.556, -78.36979, 1.533196, 120, 0, 0), -- Coral Shark (Area: The Savage Coast) (possible waypoints or random movement)
(@CGUID+1378, 871, 0, 1, 1, -12410.68, 720.9006, -28.9287, 4.206544, 120, 0, 0), -- Saltscale Warrior (Area: The Vile Reef) (possible waypoints or random movement)
(@CGUID+1379, 877, 0, 1, 1, -12411.69, 707.4018, -34.09795, 3.094286, 120, 0, 0), -- Saltscale Forager (Area: The Vile Reef) (possible waypoints or random movement)
(@CGUID+1380, 879, 0, 1, 1, -12392.45, 688.3318, -55.11372, 0.1177161, 120, 0, 0), -- Saltscale Hunter (Area: The Vile Reef) (possible waypoints or random movement)
(@CGUID+1381, 871, 0, 1, 1, -12419.72, 613.0453, -101.9446, 0.1927669, 120, 0, 0), -- Saltscale Warrior (Area: The Vile Reef) (possible waypoints or random movement)
(@CGUID+1382, 871, 0, 1, 1, -12446.88, 615.625, -98, 2.687985, 120, 0, 0), -- Saltscale Warrior (Area: The Vile Reef) (possible waypoints or random movement)
(@CGUID+1383, 879, 0, 1, 1, -12417.55, 596.0646, -103.8115, 1.048763, 120, 0, 0), -- Saltscale Hunter (Area: The Vile Reef) (possible waypoints or random movement)
(@CGUID+1384, 879, 0, 1, 1, -12444.37, 601.9436, -99.66219, 5.700136, 120, 0, 0), -- Saltscale Hunter (Area: The Vile Reef) (possible waypoints or random movement)
(@CGUID+1385, 871, 0, 1, 1, -12426.17, 603.3683, -101.9446, 3.099594, 120, 0, 0), -- Saltscale Warrior (Area: The Vile Reef) (possible waypoints or random movement)
(@CGUID+1386, 877, 0, 1, 1, -12397.92, 569.791, -107.5996, 2.177927, 120, 0, 0), -- Saltscale Forager (Area: The Vile Reef) (possible waypoints or random movement)
(@CGUID+1387, 6827, 0, 1, 1, -12376.84, 324.1939, 0.7327812, 1.970591, 120, 0, 0), -- Crab (Area: The Vile Reef)
(@CGUID+1388, 7853, 0, 1, 1, -12409.79, 235.2813, 1.309222, 5.201081, 120, 0, 0), -- Scooty (Area: Grom'gol Base Camp)
(@CGUID+1389, 1404, 0, 1, 1, -12388.9, 227.6955, 2.409306, 4.39823, 120, 0, 0), -- Kragg (Area: Grom'gol Base Camp)
(@CGUID+1390, 1064, 0, 1, 1, -12383.26, 212.1925, 2.228048, 4.725986, 120, 0, 0), -- Grom'gol Grunt (Area: Grom'gol Base Camp)
(@CGUID+1391, 1064, 0, 1, 1, -12366.99, 223.9976, 3.419054, 4.433136, 120, 0, 0), -- Grom'gol Grunt (Area: Grom'gol Base Camp)
(@CGUID+1392, 3624, 0, 1, 1, -12399.79, 235.5108, 2.211162, 4.939282, 120, 0, 0), -- Zudd (Area: Grom'gol Base Camp)
(@CGUID+1393, 1064, 0, 1, 1, -12382.94, 234.0906, 2.960565, 1.291544, 120, 0, 0), -- Grom'gol Grunt (Area: Grom'gol Base Camp)
(@CGUID+1394, 1064, 0, 1, 1, -12375.04, 234.2276, 3.365289, 1.867502, 120, 0, 0), -- Grom'gol Grunt (Area: Grom'gol Base Camp)
(@CGUID+1395, 45423, 0, 1, 1, 1842.351, -3698.601, 158.7689, 6.265732, 120, 0, 0), -- Fiona's Caravan (Area: Grom'gol Base Camp)
(@CGUID+1396, 41178, 0, 1, 1, 1850.524, -3728.49, 211.9617, 0.08726646, 120, 0, 0), -- Northwatch Tower Stalker (Area: Grom'gol Base Camp)
(@CGUID+1397, 2497, 0, 1, 1, -12348.16, 168.5191, 3.173477, 3.193953, 120, 0, 0), -- Nimboya (Area: Grom'gol Base Camp)
(@CGUID+1398, 1385, 0, 1, 1, -12396.7, 194.965, 2.356943, 0.01745329, 120, 0, 0), -- Brawn (Area: Grom'gol Base Camp)
(@CGUID+1399, 17094, 0, 1, 1, -12385.72, 180.8109, 2.704069, 3.543018, 120, 0, 0), -- Nemeth Hawkeye (Area: Grom'gol Base Camp)
(@CGUID+1400, 1147, 0, 1, 1, -12410.24, 203.675, 2.434405, 0.03490658, 120, 0, 0), -- Hragran (Area: Grom'gol Base Camp)
(@CGUID+1401, 12137, 0, 1, 1, -12417.85, 208.3292, 31.32244, 3.193953, 120, 0, 0), -- Squibby Overspeck (Area: Grom'gol Base Camp)
(@CGUID+1402, 1064, 0, 1, 1, -12388.37, 166.8437, 2.748084, 1.036794, 120, 0, 0), -- Grom'gol Grunt (Area: Grom'gol Base Camp)
(@CGUID+1403, 2464, 0, 1, 1, -12396.56, 167.4589, 3.022986, 4.215814, 120, 0, 0), -- Commander Aggro'gosh (Area: Grom'gol Base Camp) (possible waypoints or random movement)
(@CGUID+1404, 1064, 0, 1, 1, -12384.43, 147.2006, 2.589987, 1.570796, 120, 0, 0), -- Grom'gol Grunt (Area: Grom'gol Base Camp)
(@CGUID+1405, 2465, 0, 1, 1, -12412.85, 171.2354, 3.411867, 5.532694, 120, 0, 0), -- Far Seer Mok'thardin (Area: Grom'gol Base Camp)
(@CGUID+1406, 7485, 0, 1, 1, -12414.04, 166.1585, 3.4752, 2.338741, 120, 0, 0), -- Nargatt (Area: Grom'gol Base Camp)
(@CGUID+1407, 1064, 0, 1, 1, -12375.38, 130.8767, 21.17849, 0.06981317, 120, 0, 0), -- Grom'gol Grunt (Area: Grom'gol Base Camp)
(@CGUID+1408, 1064, 0, 1, 1, -12389.18, 131.9667, 3.701475, 4.642576, 120, 0, 0), -- Grom'gol Grunt (Area: Grom'gol Base Camp)
(@CGUID+1409, 1064, 0, 1, 1, -12395.14, 131.9134, 3.74115, 4.607669, 120, 0, 0), -- Grom'gol Grunt (Area: Grom'gol Base Camp)
(@CGUID+1410, 50487, 0, 1, 1, -12382.56, 78.43249, 3.499869, 5.905217, 120, 0, 0), -- Forest Spiderling (Area: Grom'gol Base Camp) (possible waypoints or random movement)
(@CGUID+1411, 1148, 0, 1, 1, -12412.25, 134.007, 3.944858, 1.343904, 120, 0, 0), -- Nerrist (Area: Grom'gol Base Camp)
(@CGUID+1412, 43050, 0, 1, 1, -12379.79, -2.984375, 5.388254, 0.35328, 120, 0, 0), -- Vale Howler (Area: Grom'gol Base Camp) (possible waypoints or random movement)
(@CGUID+1413, 49928, 0, 1, 1, -12388.95, -28.09739, 26.63207, 5.406088, 120, 0, 0), -- Crimson Moth (Area: 0)
(@CGUID+1414, 50479, 0, 1, 1, -12399.67, -94.84377, 14.72269, 6.143156, 120, 0, 0), -- Lizard Hatchling (Area: 0)
(@CGUID+1415, 1144, 0, 1, 1, -12379.46, -130.0934, 17.01419, 4.490705, 120, 0, 0), -- Mosh'Ogg Witch Doctor (Area: 0)
(@CGUID+1416, 1142, 0, 1, 1, -12401.89, -226.8477, 16.64438, 4.776921, 120, 0, 0), -- Mosh'Ogg Brute (Area: 0)
(@CGUID+1417, 1144, 0, 1, 1, -12391.14, -169.6048, 16.79084, 4.590942, 120, 0, 0), -- Mosh'Ogg Witch Doctor (Area: 0)
(@CGUID+1418, 2635, 0, 1, 1, -12377.45, -253.2924, 16.4478, 6.224821, 120, 0, 0), -- Elder Saltwater Crocolisk (Area: 0) (possible waypoints or random movement)
(@CGUID+1419, 50487, 0, 1, 1, -12371.74, -236.3509, 17.17359, 5.219677, 120, 0, 0), -- Forest Spiderling (Area: 0) (possible waypoints or random movement)
(@CGUID+1420, 1152, 0, 1, 1, -12388.73, -304.1319, 7.346221, 4.158119, 120, 0, 0), -- Snapjaw Crocolisk (Area: 0) (possible waypoints or random movement)
(@CGUID+1421, 6827, 0, 1, 1, -12381.69, -284.998, 9.477673, 4.467367, 120, 0, 0), -- Crab (Area: 0)
(@CGUID+1422, 6827, 0, 1, 1, -12383.32, -283.6039, 9.702231, 0.9394135, 120, 0, 0), -- Crab (Area: 0)
(@CGUID+1423, 687, 0, 1, 1, -12413.38, -645.1531, 15.5323, 0.3134785, 120, 0, 0), -- Jungle Stalker (Area: 0)
(@CGUID+1424, 15475, 0, 1, 1, -12403.75, -614.3013, 18.78103, 1.809149, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+1425, 687, 0, 1, 1, -12419.6, -718.6111, 30.93046, 0.680232, 120, 0, 0), -- Jungle Stalker (Area: 0)
(@CGUID+1426, 728, 0, 1, 1, -12423.51, -793.7476, 37.24636, 0.2525543, 120, 0, 0), -- Bhag'thera (Area: 0)
(@CGUID+1427, 709, 0, 1, 1, -12425.81, -839.576, 40.97976, 3.333579, 120, 0, 0), -- Mosh'Ogg Warmonger (Area: 0)
(@CGUID+1428, 709, 0, 1, 1, -12428.46, -836.3364, 40.69954, 4.29351, 120, 0, 0), -- Mosh'Ogg Warmonger (Area: 0)
(@CGUID+1429, 709, 0, 1, 1, -12442.68, -949.7534, 40.71062, 5.826746, 120, 0, 0), -- Mosh'Ogg Warmonger (Area: 0)
(@CGUID+1430, 710, 0, 1, 1, -12462.2, -995.4155, 50.36738, 2.600541, 120, 0, 0), -- Mosh'Ogg Spellcrafter (Area: 0)
(@CGUID+1431, 679, 0, 1, 1, -12468.51, -996.5638, 49.80191, 1.361357, 120, 0, 0), -- Mosh'Ogg Shaman (Area: 0)
(@CGUID+1432, 710, 0, 1, 1, -12464.27, -989.3076, 49.90953, 3.839724, 120, 0, 0), -- Mosh'Ogg Spellcrafter (Area: 0)
(@CGUID+1433, 49928, 0, 1, 1, -12457.65, -881.645, 51.94204, 4.330638, 120, 0, 0), -- Crimson Moth (Area: Mosh'Ogg Ogre Mound)
(@CGUID+1434, 709, 0, 1, 1, -12454.23, -890.6303, 41.00054, 3.644011, 120, 0, 0), -- Mosh'Ogg Warmonger (Area: Mosh'Ogg Ogre Mound)
(@CGUID+1435, 50479, 0, 1, 1, -12442.54, -919.7516, 39.20554, 2.829731, 120, 0, 0), -- Lizard Hatchling (Area: Mosh'Ogg Ogre Mound)
(@CGUID+1436, 32520, 0, 1, 1, -6305.162, 5582.533, -1172.063, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Mosh'Ogg Ogre Mound)
(@CGUID+1437, 32520, 0, 1, 1, -6014.71, 5479.63, -1208.007, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Mosh'Ogg Ogre Mound)
(@CGUID+1438, 32520, 0, 1, 1, -5691.65, 5556.92, -1154.687, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Mosh'Ogg Ogre Mound)
(@CGUID+1439, 32520, 0, 1, 1, -6148.39, 5539.97, -1207.787, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Mosh'Ogg Ogre Mound)
(@CGUID+1440, 15475, 0, 1, 1, -12445.35, -805.6431, 40.86067, 0.2125203, 120, 0, 0), -- Beetle (Area: Mosh'Ogg Ogre Mound)
(@CGUID+1441, 667, 0, 1, 1, -12446.48, -748.4805, 37.00551, 4.349278, 120, 0, 0), -- Skullsplitter Warrior (Area: Mosh'Ogg Ogre Mound) (possible waypoints or random movement)
(@CGUID+1442, 49928, 0, 1, 1, -12459.7, -428.1058, 31.16338, 5.063904, 120, 0, 0), -- Crimson Moth (Area: 0)
(@CGUID+1443, 2635, 0, 1, 1, -12422.47, -341.5937, 16.12002, 2.644326, 120, 0, 0), -- Elder Saltwater Crocolisk (Area: 0) (possible waypoints or random movement)
(@CGUID+1444, 687, 0, 1, 1, -12427.74, -384.8578, 17.00892, 3.59209, 120, 0, 0), -- Jungle Stalker (Area: 0)
(@CGUID+1445, 6827, 0, 1, 1, -12424.83, -323.7031, 12.06447, 0.2725607, 120, 0, 0), -- Crab (Area: 0)
(@CGUID+1446, 6827, 0, 1, 1, -12448.9, -299.0028, 8.745373, 1.229694, 120, 0, 0), -- Crab (Area: 0)
(@CGUID+1447, 15475, 0, 1, 1, -12463.21, -346.5125, 15.46554, 2.016331, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+1448, 2635, 0, 1, 1, -12477.35, -325.9068, 13.5267, 3.696561, 120, 0, 0), -- Elder Saltwater Crocolisk (Area: 0) (possible waypoints or random movement)
(@CGUID+1449, 687, 0, 1, 1, -12455.58, -347.3825, 17.95479, 1.884787, 120, 0, 0), -- Jungle Stalker (Area: 0)
(@CGUID+1450, 905, 0, 1, 1, -12468.56, -268.6362, 7.788953, 6.085983, 120, 0, 0), -- Sharptooth Frenzy (Area: 0) (possible waypoints or random movement)
(@CGUID+1451, 49722, 0, 1, 1, -12454.22, -199.7663, 15.49315, 5.281966, 120, 0, 0), -- Tree Python (Area: 0) (possible waypoints or random movement)
(@CGUID+1452, 6827, 0, 1, 1, -12464.22, -239.8143, 9.955019, 5.597456, 120, 0, 0), -- Crab (Area: 0)
(@CGUID+1453, 1142, 0, 1, 1, -12416.47, -157.9383, 16.43117, 5.796055, 120, 0, 0), -- Mosh'Ogg Brute (Area: 0)
(@CGUID+1454, 1142, 0, 1, 1, -12446.55, -200.6506, 17.74992, 0.9620353, 120, 0, 0), -- Mosh'Ogg Brute (Area: 0)
(@CGUID+1455, 1142, 0, 1, 1, -12418.79, -229.6, 16.42124, 2.738779, 120, 0, 0), -- Mosh'Ogg Brute (Area: 0)
(@CGUID+1456, 1142, 0, 1, 1, -12458.17, -208.9552, 16.05314, 0.1134595, 120, 0, 0), -- Mosh'Ogg Brute (Area: 0)
(@CGUID+1457, 50479, 0, 1, 1, -12410.4, -157.8506, 16.18508, 4.767129, 120, 0, 0), -- Lizard Hatchling (Area: 0)
(@CGUID+1458, 1142, 0, 1, 1, -12410.18, -197.2996, 16.75735, 4.933436, 120, 0, 0), -- Mosh'Ogg Brute (Area: 0)
(@CGUID+1459, 2635, 0, 1, 1, -12444.49, -242.3568, 13.60687, 3.156076, 120, 0, 0), -- Elder Saltwater Crocolisk (Area: 0) (possible waypoints or random movement)
(@CGUID+1460, 49928, 0, 1, 1, -12406.99, -154.1476, 36.44105, 3.6293, 120, 0, 0), -- Crimson Moth (Area: 0)
(@CGUID+1461, 1144, 0, 1, 1, -12355.84, -143.2788, 14.69298, 3.453624, 120, 0, 0), -- Mosh'Ogg Witch Doctor (Area: 0)
(@CGUID+1462, 1142, 0, 1, 1, -12477.83, -151.7939, 13.46837, 3.92695, 120, 0, 0), -- Mosh'Ogg Brute (Area: 0)
(@CGUID+1463, 1144, 0, 1, 1, -12477.67, -133.5462, 13.59972, 4.623438, 120, 0, 0), -- Mosh'Ogg Witch Doctor (Area: 0)
(@CGUID+1464, 1144, 0, 1, 1, -12414.26, -126.1931, 17.62532, 5.989508, 120, 0, 0), -- Mosh'Ogg Witch Doctor (Area: 0)
(@CGUID+1465, 1144, 0, 1, 1, -12454, -79.36961, 16.75333, 2.317301, 120, 0, 0), -- Mosh'Ogg Witch Doctor (Area: 0)
(@CGUID+1466, 1144, 0, 1, 1, -12412.96, -82.6334, 17.03301, 2.912134, 120, 0, 0), -- Mosh'Ogg Witch Doctor (Area: 0)
(@CGUID+1467, 1144, 0, 1, 1, -12485, -46.9873, 5.072187, 0.3294879, 120, 0, 0), -- Mosh'Ogg Witch Doctor (Area: Mizjah Ruins)
(@CGUID+1468, 1142, 0, 1, 1, -12452.52, -36.99585, 4.700688, 2.944496, 120, 0, 0), -- Mosh'Ogg Brute (Area: Mizjah Ruins)
(@CGUID+1469, 9600, 0, 1, 1, -12419.35, -9.86348, 29.65511, 3.949451, 120, 0, 0), -- Parrot (Area: Mizjah Ruins)
(@CGUID+1470, 15475, 0, 1, 1, -12439.15, 32.12077, 5.520516, 2.069364, 120, 0, 0), -- Beetle (Area: Mizjah Ruins)
(@CGUID+1471, 15475, 0, 1, 1, -12421.42, 30.72337, 4.973261, 1.704123, 120, 0, 0), -- Beetle (Area: Mizjah Ruins)
(@CGUID+1472, 50479, 0, 1, 1, -12444.15, 78.02574, 4.845166, 4.961245, 120, 0, 0), -- Lizard Hatchling (Area: 0)
(@CGUID+1473, 49928, 0, 1, 1, -12449.44, 86.09295, 29.8401, 3.318051, 120, 0, 0), -- Crimson Moth (Area: 0)
(@CGUID+1474, 49928, 0, 1, 1, -12425.22, 111.9059, 22.68775, 1.272585, 120, 0, 0), -- Crimson Moth (Area: 0)
(@CGUID+1475, 1387, 0, 1, 1, -12417.52, 144.4744, 3.368809, 0.6108652, 120, 0, 0), -- Thysta (Area: 0)
(@CGUID+1476, 16096, 0, 1, 1, -12420.31, 200.8553, 31.37467, 2.617994, 120, 0, 0), -- Steamwheedle Bruiser (Area: 0)
(@CGUID+1477, 16096, 0, 1, 1, -12434.48, 195.6172, 31.37467, 1.151917, 120, 0, 0), -- Steamwheedle Bruiser (Area: 0)
(@CGUID+1478, 16094, 0, 1, 1, -12423.7, 187.0722, 1.16645, 5.201081, 120, 0, 0), -- Durik (Area: 0)
(@CGUID+1479, 16096, 0, 1, 1, -12435.63, 217.4477, 31.37467, 5.026548, 120, 0, 0), -- Steamwheedle Bruiser (Area: 0)
(@CGUID+1480, 3149, 0, 1, 1, -12441.29, 215.0182, 31.32244, 5.5676, 120, 0, 0), -- Nez'raz (Area: 0)
(@CGUID+1481, 5814, 0, 1, 1, -12434.42, 211.5588, 2.448482, 0.9075712, 120, 0, 0), -- Innkeeper Thulbek (Area: 0)
(@CGUID+1482, 6827, 0, 1, 1, -12471.85, 166.4494, 0.5747423, 1.675759, 120, 0, 0), -- Crab (Area: 0)
(@CGUID+1483, 51917, 0, 1, 1, -12402.5, 202.2364, 2.521055, 3.019413, 120, 0, 0), -- Grom'gol Grunt (Area: Grom'gol Base Camp)
(@CGUID+1484, 871, 0, 1, 1, -12444.02, 591.9369, -100.4885, 2.356194, 120, 0, 0), -- Saltscale Warrior (Area: The Vile Reef) (possible waypoints or random movement)
(@CGUID+1485, 877, 0, 1, 1, -12453.28, 626.0206, -97.87405, 0.7411976, 120, 0, 0), -- Saltscale Forager (Area: The Vile Reef) (possible waypoints or random movement)
(@CGUID+1486, 877, 0, 1, 1, -12484.13, 635.9911, -100.2403, 6.163935, 120, 0, 0), -- Saltscale Forager (Area: The Vile Reef) (possible waypoints or random movement)
(@CGUID+1487, 5434, 0, 1, 1, -12625.05, 1044.061, -54.72869, 0.1657908, 120, 0, 0), -- Coral Shark (Area: The Savage Coast) (possible waypoints or random movement)
(@CGUID+1488, 24924, 0, 1, 1, -12456.32, 227.1504, 25.85951, 1.20563, 120, 0, 0), -- Sky-Captain Bomblast (Area: The Vile Reef)
(@CGUID+1489, 24930, 0, 1, 1, -12458.31, 217.0729, 32.76253, 5.411873, 120, 0, 0), -- Crewman Gazzlegear (Area: The Vile Reef) (possible waypoints or random movement)
(@CGUID+1490, 24929, 0, 1, 1, -12448.36, 239.868, 25.4808, 5.726655, 120, 0, 0), -- Crewman Crosswire (Area: The Vile Reef)
(@CGUID+1491, 24931, 0, 1, 1, -12455.36, 233.2264, 31.62526, 2.646396, 120, 0, 0), -- Crewman Fastwrench (Area: The Vile Reef) (possible waypoints or random movement)
(@CGUID+1492, 24926, 0, 1, 1, -12454.52, 221.9032, 31.77227, 1.333325, 120, 0, 0), -- Chief Officer Brassbolt (Area: The Vile Reef) (possible waypoints or random movement)
(@CGUID+1493, 25081, 0, 1, 1, -12457.44, 223.489, 31.92348, 5.760939, 120, 0, 0), -- Grunt Ounda (Area: The Vile Reef)
(@CGUID+1494, 24927, 0, 1, 1, -12453.02, 242.5365, 25.40545, 2.611338, 120, 0, 0), -- Navigator Sparksizzle (Area: The Vile Reef)
(@CGUID+1495, 25080, 0, 1, 1, -12462.68, 226.5386, 31.91903, 2.654253, 120, 0, 0), -- Grunt Umgor (Area: The Vile Reef)
(@CGUID+1496, 24934, 0, 1, 1, -12456.71, 239.3935, 26.02225, 4.172689, 120, 0, 0), -- Snack-O-Matic IV (Area: The Vile Reef) (possible waypoints or random movement)
(@CGUID+1497, 25075, 0, 1, 1, -12458.89, 226.9011, 25.83767, 1.083457, 120, 0, 0), -- Zeppelin Controls (Area: The Vile Reef) (possible waypoints or random movement)
(@CGUID+1498, 24935, 0, 1, 1, -12449.16, 235.4437, 26.02848, 4.172689, 120, 0, 0), -- Vend-O-Tron D-Luxe (Area: The Vile Reef) (possible waypoints or random movement)
(@CGUID+1499, 6827, 0, 1, 1, -12519.64, 179.7096, 2.793925, 4.523802, 120, 0, 0), -- Crab (Area: The Vile Reef)
(@CGUID+1500, 6827, 0, 1, 1, -12479.63, 136.1978, 1.243621, 4.814197, 120, 0, 0), -- Crab (Area: The Vile Reef)
(@CGUID+1501, 6827, 0, 1, 1, -12505.23, 132.3285, -1.469837, 3.014077, 120, 0, 0), -- Crab (Area: The Vile Reef)
(@CGUID+1502, 6827, 0, 1, 1, -12547.1, 98.61059, 3.535689, 4.253109, 120, 0, 0), -- Crab (Area: Grom'gol Base Camp)
(@CGUID+1503, 6827, 0, 1, 1, -12538.62, 57.18464, 1.135109, 0.06734212, 120, 0, 0), -- Crab (Area: Grom'gol Base Camp)
(@CGUID+1504, 50479, 0, 1, 1, -12514.39, -9.374116, 3.916976, 2.649107, 120, 0, 0), -- Lizard Hatchling (Area: The Savage Coast)
(@CGUID+1505, 6827, 0, 1, 1, -12521.08, 15.2011, 0.9703913, 4.60087, 120, 0, 0), -- Crab (Area: The Savage Coast)
(@CGUID+1506, 49722, 0, 1, 1, -12485.42, -102.084, 15.46685, 1.457618, 120, 0, 0), -- Tree Python (Area: The Savage Coast) (possible waypoints or random movement)
(@CGUID+1507, 1142, 0, 1, 1, -12514.9, -85.41941, 16.0829, 5.505079, 120, 0, 0), -- Mosh'Ogg Brute (Area: The Savage Coast)
(@CGUID+1508, 1144, 0, 1, 1, -12494.39, -145.9664, 13.37169, 1.875784, 120, 0, 0), -- Mosh'Ogg Witch Doctor (Area: 0)
(@CGUID+1509, 1142, 0, 1, 1, -12501.48, -161.2815, 12.66004, 0.6047421, 120, 0, 0), -- Mosh'Ogg Brute (Area: 0)
(@CGUID+1510, 1142, 0, 1, 1, -12482.69, -171.8111, 13.28829, 2.286381, 120, 0, 0), -- Mosh'Ogg Brute (Area: 0)
(@CGUID+1511, 1144, 0, 1, 1, -12489.4, -171.4364, 12.94153, 0.6632251, 120, 0, 0), -- Mosh'Ogg Witch Doctor (Area: 0)
(@CGUID+1512, 1144, 0, 1, 1, -12500.7, -166.4845, 12.19031, 3.788947, 120, 0, 0), -- Mosh'Ogg Witch Doctor (Area: 0)
(@CGUID+1513, 6827, 0, 1, 1, -12539.39, -118.5657, 10.81576, 2.291279, 120, 0, 0), -- Crab (Area: 0)
(@CGUID+1514, 905, 0, 1, 1, -12534.38, -171.875, 8.096908, 4.836651, 120, 0, 0), -- Sharptooth Frenzy (Area: 0) (possible waypoints or random movement)
(@CGUID+1515, 6827, 0, 1, 1, -12541.87, -162.1989, 8.621244, 4.131429, 120, 0, 0), -- Crab (Area: 0)
(@CGUID+1516, 6827, 0, 1, 1, -12547.4, -164.6607, 10.15359, 1.883215, 120, 0, 0), -- Crab (Area: 0)
(@CGUID+1517, 2635, 0, 1, 1, -12524.37, -276.367, 13.75684, 3.328126, 120, 0, 0), -- Elder Saltwater Crocolisk (Area: Mizjah Ruins) (possible waypoints or random movement)
(@CGUID+1518, 1152, 0, 1, 1, -12501.42, -236.8208, 7.39384, 0.2229396, 120, 0, 0), -- Snapjaw Crocolisk (Area: Mizjah Ruins) (possible waypoints or random movement)
(@CGUID+1519, 6827, 0, 1, 1, -12516.19, -256.7734, 9.528433, 3.332097, 120, 0, 0), -- Crab (Area: Mizjah Ruins)
(@CGUID+1520, 1085, 0, 1, 1, -12544.58, -328.6312, 16.73922, 1.463159, 120, 0, 0), -- Elder Stranglethorn Tiger (Area: 0)
(@CGUID+1521, 43050, 0, 1, 1, -12555.52, -447.7211, 28.08388, 4.640108, 120, 0, 0), -- Vale Howler (Area: 0) (possible waypoints or random movement)
(@CGUID+1522, 687, 0, 1, 1, -12545.7, -447.8941, 29.34658, 0.8554658, 120, 0, 0), -- Jungle Stalker (Area: 0)
(@CGUID+1523, 9600, 0, 1, 1, -12494.23, -472.2534, 32.5382, 3.091076, 120, 0, 0), -- Parrot (Area: 0)
(@CGUID+1524, 687, 0, 1, 1, -12486.53, -452.6741, 16.52157, 3.243523, 120, 0, 0), -- Jungle Stalker (Area: 0)
(@CGUID+1525, 687, 0, 1, 1, -12514.8, -480.5537, 22.87089, 1.922677, 120, 0, 0), -- Jungle Stalker (Area: 0)
(@CGUID+1526, 687, 0, 1, 1, -12485.11, -510.5561, 13.74485, 1.179764, 120, 0, 0), -- Jungle Stalker (Area: 0)
(@CGUID+1527, 50487, 0, 1, 1, -12475.14, -589.3538, 15.87792, 1.161561, 120, 0, 0), -- Forest Spiderling (Area: 0) (possible waypoints or random movement)
(@CGUID+1528, 687, 0, 1, 1, -12527.78, -557.5323, 40.28282, 2.158799, 120, 0, 0), -- Jungle Stalker (Area: 0)
(@CGUID+1529, 687, 0, 1, 1, -12484.04, -578.5278, 17.75822, 2.276422, 120, 0, 0), -- Jungle Stalker (Area: 0)
(@CGUID+1530, 696, 0, 1, 1, -12511.35, -683.5546, 38.06015, 5.914144, 120, 0, 0), -- Skullsplitter Axe Thrower (Area: 0) (possible waypoints or random movement)
(@CGUID+1531, 9600, 0, 1, 1, -12490.56, -697.0593, 60.13358, 5.830228, 120, 0, 0), -- Parrot (Area: 0)
(@CGUID+1532, 50487, 0, 1, 1, -12521.15, -662.7852, 38.27681, 3.715512, 120, 0, 0), -- Forest Spiderling (Area: 0) (possible waypoints or random movement)
(@CGUID+1533, 696, 0, 1, 1, -12544.62, -714.8246, 38.89827, 3.583732, 120, 0, 0), -- Skullsplitter Axe Thrower (Area: 0) (possible waypoints or random movement)
(@CGUID+1534, 696, 0, 1, 1, -12548.9, -729.5873, 39.83089, 0.2169892, 120, 0, 0), -- Skullsplitter Axe Thrower (Area: 0) (possible waypoints or random movement)
(@CGUID+1535, 49928, 0, 1, 1, -12536.05, -750.8988, 58.25946, 5.420389, 120, 0, 0), -- Crimson Moth (Area: 0)
(@CGUID+1536, 696, 0, 1, 1, -12484.73, -781.9309, 41.96574, 5.409376, 120, 0, 0), -- Skullsplitter Axe Thrower (Area: 0) (possible waypoints or random movement)
(@CGUID+1537, 780, 0, 1, 1, -12530.56, -717.8979, 39.57027, 3.533734, 120, 0, 0), -- Skullsplitter Mystic (Area: 0) (possible waypoints or random movement)
(@CGUID+1538, 780, 0, 1, 1, -12529.02, -740.921, 39.62666, 6.05773, 120, 0, 0), -- Skullsplitter Mystic (Area: 0) (possible waypoints or random movement)
(@CGUID+1539, 687, 0, 1, 1, -12548.28, -848.5782, 43.65826, 0.8984597, 120, 0, 0), -- Jungle Stalker (Area: Balia'mah Ruins)
(@CGUID+1540, 49928, 0, 1, 1, -12482.23, -900.1074, 56.07381, 1.991848, 120, 0, 0), -- Crimson Moth (Area: Balia'mah Ruins)
(@CGUID+1541, 709, 0, 1, 1, -12478.34, -857.157, 40.89677, 5.575867, 120, 0, 0), -- Mosh'Ogg Warmonger (Area: Balia'mah Ruins)
(@CGUID+1542, 709, 0, 1, 1, -12524.63, -875.1897, 42.21588, 2.372066, 120, 0, 0), -- Mosh'Ogg Warmonger (Area: Balia'mah Ruins)
(@CGUID+1543, 49722, 0, 1, 1, -12477.51, -874.0538, 38.95108, 0.7383133, 120, 0, 0), -- Tree Python (Area: Balia'mah Ruins) (possible waypoints or random movement)
(@CGUID+1544, 49722, 0, 1, 1, -12510.13, -845.1575, 39.71733, 2.107867, 120, 0, 0), -- Tree Python (Area: Balia'mah Ruins) (possible waypoints or random movement)
(@CGUID+1545, 709, 0, 1, 1, -12479.49, -903.3725, 39.54453, 1.645085, 120, 0, 0), -- Mosh'Ogg Warmonger (Area: Balia'mah Ruins)
(@CGUID+1546, 48972, 0, 1, 1, -12498.64, -1006.335, 51.96838, 4.491412, 120, 0, 0), -- Long-tailed Mole (Area: Mosh'Ogg Ogre Mound)
(@CGUID+1547, 15475, 0, 1, 1, -12490.1, -1006.771, 52.22668, 3.055779, 120, 0, 0), -- Beetle (Area: Mosh'Ogg Ogre Mound)
(@CGUID+1548, 4076, 0, 1, 1, -12503.32, -1002.28, 52.09783, 2.201844, 120, 0, 0), -- Roach (Area: Mosh'Ogg Ogre Mound)
(@CGUID+1549, 709, 0, 1, 1, -12495.37, -979.0261, 49.52369, 2.673578, 120, 0, 0), -- Mosh'Ogg Warmonger (Area: Mosh'Ogg Ogre Mound)
(@CGUID+1550, 678, 0, 1, 1, -12472.74, -978.812, 48.27401, 1.969307, 120, 0, 0), -- Mosh'Ogg Mauler (Area: Mosh'Ogg Ogre Mound)
(@CGUID+1551, 678, 0, 1, 1, -12495.33, -1000.088, 50.06897, 4.364892, 120, 0, 0), -- Mosh'Ogg Mauler (Area: Mosh'Ogg Ogre Mound)
(@CGUID+1552, 680, 0, 1, 1, -12499.76, -1007.087, 52.31597, 5.235988, 120, 0, 0), -- Mosh'Ogg Lord (Area: Mosh'Ogg Ogre Mound)
(@CGUID+1553, 680, 0, 1, 1, -12494.35, -1008.122, 52.40799, 4.049164, 120, 0, 0), -- Mosh'Ogg Lord (Area: Mosh'Ogg Ogre Mound)
(@CGUID+1554, 687, 0, 1, 1, -12550.06, -916.636, 43.24958, 5.191144, 120, 0, 0), -- Jungle Stalker (Area: Mosh'Ogg Ogre Mound)
(@CGUID+1555, 50479, 0, 1, 1, -12500.64, -1092.815, 115.0565, 3.237185, 120, 0, 0), -- Lizard Hatchling (Area: Mosh'Ogg Ogre Mound)
(@CGUID+1556, 730, 0, 1, 1, -12602.87, -935.0428, 58.76107, 2.410084, 120, 0, 0), -- Tethis (Area: Mosh'Ogg Ogre Mound)
(@CGUID+1557, 9600, 0, 1, 1, -12572.4, -881.741, 67.13289, 2.980092, 120, 0, 0), -- Parrot (Area: Mosh'Ogg Ogre Mound)
(@CGUID+1558, 9600, 0, 1, 1, -12563.96, -866.989, 65.73589, 4.767628, 120, 0, 0), -- Parrot (Area: Mosh'Ogg Ogre Mound)
(@CGUID+1559, 50487, 0, 1, 1, -12570.16, -924.2018, 48.16544, 6.195178, 120, 0, 0), -- Forest Spiderling (Area: Mosh'Ogg Ogre Mound) (possible waypoints or random movement)
(@CGUID+1560, 780, 0, 1, 1, -12589.31, -817.4005, 53.13213, 3.506952, 120, 0, 0), -- Skullsplitter Mystic (Area: Mosh'Ogg Ogre Mound) (possible waypoints or random movement)
(@CGUID+1561, 696, 0, 1, 1, -12559.32, -833.6286, 45.67443, 0.8281379, 120, 0, 0), -- Skullsplitter Axe Thrower (Area: Mosh'Ogg Ogre Mound) (possible waypoints or random movement)
(@CGUID+1562, 49722, 0, 1, 1, -12565.93, -817.3159, 44.30159, 5.987988, 120, 0, 0), -- Tree Python (Area: Mosh'Ogg Ogre Mound) (possible waypoints or random movement)
(@CGUID+1563, 696, 0, 1, 1, -12550.21, -769.2273, 41.28879, 1.597097, 120, 0, 0), -- Skullsplitter Axe Thrower (Area: Balia'mah Ruins) (possible waypoints or random movement)
(@CGUID+1564, 687, 0, 1, 1, -12582.11, -748.6779, 43.94099, 0.7163069, 120, 0, 0), -- Jungle Stalker (Area: Balia'mah Ruins)
(@CGUID+1565, 667, 0, 1, 1, -12559.25, -735.7547, 39.24934, 0.2112789, 120, 0, 0), -- Skullsplitter Warrior (Area: Balia'mah Ruins) (possible waypoints or random movement)
(@CGUID+1566, 696, 0, 1, 1, -12553.4, -651.6744, 40.02588, 0.7183689, 120, 0, 0), -- Skullsplitter Axe Thrower (Area: Balia'mah Ruins) (possible waypoints or random movement)
(@CGUID+1567, 687, 0, 1, 1, -12579.16, -626.8132, 42.65669, 4.48755, 120, 0, 0), -- Jungle Stalker (Area: Balia'mah Ruins)
(@CGUID+1568, 49928, 0, 1, 1, -12597.23, -664.149, 57.74578, 5.988556, 120, 0, 0), -- Crimson Moth (Area: Balia'mah Ruins)
(@CGUID+1569, 32520, 0, 1, 1, -6305.162, 5582.533, -1172.063, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Balia'mah Ruins)
(@CGUID+1570, 32520, 0, 1, 1, -6148.39, 5539.97, -1207.787, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Balia'mah Ruins)
(@CGUID+1571, 32520, 0, 1, 1, -5691.65, 5556.92, -1154.687, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Balia'mah Ruins)
(@CGUID+1572, 32520, 0, 1, 1, -6014.71, 5479.63, -1208.007, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Balia'mah Ruins)
(@CGUID+1573, 50487, 0, 1, 1, -12584.76, -593.9314, 39.52466, 6.195871, 120, 0, 0), -- Forest Spiderling (Area: Balia'mah Ruins) (possible waypoints or random movement)
(@CGUID+1574, 9600, 0, 1, 1, -12581.85, -568.1985, 53.13597, 5.0761, 120, 0, 0), -- Parrot (Area: Balia'mah Ruins)
(@CGUID+1575, 696, 0, 1, 1, -12577.78, -552.7985, 35.42883, 1.651016, 120, 0, 0), -- Skullsplitter Axe Thrower (Area: Balia'mah Ruins) (possible waypoints or random movement)
(@CGUID+1576, 15475, 0, 1, 1, -12571.4, -521.7554, 34.46226, 0.7715869, 120, 0, 0), -- Beetle (Area: Balia'mah Ruins)
(@CGUID+1577, 667, 0, 1, 1, -12579.75, -488.3998, 31.12539, 2.539506, 120, 0, 0), -- Skullsplitter Warrior (Area: 0) (possible waypoints or random movement)
(@CGUID+1578, 49722, 0, 1, 1, -12562.67, -330.7582, 17.2792, 3.049695, 120, 0, 0), -- Tree Python (Area: 0) (possible waypoints or random movement)
(@CGUID+1579, 50479, 0, 1, 1, -12565.96, -325.7209, 17.9631, 4.041711, 120, 0, 0), -- Lizard Hatchling (Area: 0)
(@CGUID+1580, 1085, 0, 1, 1, -12578.15, -299.3235, 18.61294, 5.110399, 120, 0, 0), -- Elder Stranglethorn Tiger (Area: 0)
(@CGUID+1581, 2635, 0, 1, 1, -12560.36, -197.6369, 17.78221, 3.71658, 120, 0, 0), -- Elder Saltwater Crocolisk (Area: 0) (possible waypoints or random movement)
(@CGUID+1582, 1085, 0, 1, 1, -12556.73, -246.0379, 16.54808, 0.1905044, 120, 0, 0), -- Elder Stranglethorn Tiger (Area: 0)
(@CGUID+1583, 731, 0, 1, 1, -12586.91, -262.3399, 15.67938, 4.543722, 120, 0, 0), -- King Bangalash (Area: 0)
(@CGUID+1584, 1085, 0, 1, 1, -12577.89, -177.9212, 15.28535, 3.159169, 120, 0, 0), -- Elder Stranglethorn Tiger (Area: 0)
(@CGUID+1585, 6827, 0, 1, 1, -12585.07, -147.4075, 14.9792, 3.642643, 120, 0, 0), -- Crab (Area: 0)
(@CGUID+1586, 15475, 0, 1, 1, -12589.46, -111.027, 10.16781, 5.422762, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+1587, 1152, 0, 1, 1, -12560.81, -124.4633, 7.096969, 1.777788, 120, 0, 0), -- Snapjaw Crocolisk (Area: 0) (possible waypoints or random movement)
(@CGUID+1588, 6827, 0, 1, 1, -12604.09, -112.4133, 13.8983, 3.549659, 120, 0, 0), -- Crab (Area: 0)
(@CGUID+1589, 9600, 0, 1, 1, -12596.86, -90.95807, 35.97606, 0.6219702, 120, 0, 0), -- Parrot (Area: Mizjah Ruins)
(@CGUID+1590, 905, 0, 1, 1, -12581.17, -48.18287, 7.035384, 3.268095, 120, 0, 0), -- Sharptooth Frenzy (Area: Mizjah Ruins) (possible waypoints or random movement)
(@CGUID+1591, 49928, 0, 1, 1, -12595.09, -27.47486, 26.23132, 5.842746, 120, 0, 0), -- Crimson Moth (Area: Mizjah Ruins)
(@CGUID+1592, 24930, 0, 1, 1, -12458.31, 217.0729, 32.76253, 5.411873, 120, 0, 0), -- Crewman Gazzlegear (Area: The Savage Coast)
(@CGUID+1593, 25075, 0, 1, 1, -12458.89, 226.9011, 25.83767, 1.083457, 120, 0, 0), -- Zeppelin Controls (Area: The Savage Coast) (possible waypoints or random movement)
(@CGUID+1594, 24924, 0, 1, 1, -12456.32, 227.1504, 25.85951, 1.20563, 120, 0, 0), -- Sky-Captain Bomblast (Area: The Savage Coast)
(@CGUID+1595, 24926, 0, 1, 1, -12452.88, 228.7014, 31.59535, 1.334028, 120, 0, 0), -- Chief Officer Brassbolt (Area: The Savage Coast) (possible waypoints or random movement)
(@CGUID+1596, 25080, 0, 1, 1, -12462.68, 226.5386, 31.91903, 2.654253, 120, 0, 0), -- Grunt Umgor (Area: The Savage Coast)
(@CGUID+1597, 25081, 0, 1, 1, -12457.44, 223.489, 31.92348, 5.760939, 120, 0, 0), -- Grunt Ounda (Area: The Savage Coast)
(@CGUID+1598, 24935, 0, 1, 1, -12449.16, 235.4437, 26.02848, 4.172689, 120, 0, 0), -- Vend-O-Tron D-Luxe (Area: The Savage Coast) (possible waypoints or random movement)
(@CGUID+1599, 24927, 0, 1, 1, -12453.02, 242.5365, 25.40545, 2.611338, 120, 0, 0), -- Navigator Sparksizzle (Area: The Savage Coast)
(@CGUID+1600, 24931, 0, 1, 1, -12456.77, 237.5001, 31.77101, 0.605042, 120, 0, 0), -- Crewman Fastwrench (Area: The Savage Coast) (possible waypoints or random movement)
(@CGUID+1601, 24934, 0, 1, 1, -12456.71, 239.3935, 26.02225, 4.172689, 120, 0, 0), -- Snack-O-Matic IV (Area: The Savage Coast)
(@CGUID+1602, 24929, 0, 1, 1, -12450.7, 241.3213, 25.36512, 1.105231, 120, 0, 0), -- Crewman Crosswire (Area: The Savage Coast) (possible waypoints or random movement)
(@CGUID+1603, 1085, 0, 1, 1, -12623.35, -75.51152, 19.85449, 2.736341, 120, 0, 0), -- Elder Stranglethorn Tiger (Area: The Savage Coast)
(@CGUID+1604, 7871, 0, 1, 1, -12619, -111.229, 18.58323, 3.490659, 120, 0, 0), -- Se'Jib (Area: The Savage Coast)
(@CGUID+1605, 1085, 0, 1, 1, -12624.17, -320.1492, 17.43108, 5.229678, 120, 0, 0), -- Elder Stranglethorn Tiger (Area: 0)
(@CGUID+1606, 1085, 0, 1, 1, -12647.14, -412.2935, 17.34285, 0.5106688, 120, 0, 0), -- Elder Stranglethorn Tiger (Area: 0)
(@CGUID+1607, 780, 0, 1, 1, -12616.16, -515.4185, 31.72686, 5.508837, 120, 0, 0), -- Skullsplitter Mystic (Area: 0) (possible waypoints or random movement)
(@CGUID+1608, 49722, 0, 1, 1, -12613.13, -507.2567, 31.76351, 3.644521, 120, 0, 0), -- Tree Python (Area: 0) (possible waypoints or random movement)
(@CGUID+1609, 696, 0, 1, 1, -12618.32, -648.5752, 42.04419, 3.231627, 120, 0, 0), -- Skullsplitter Axe Thrower (Area: 0) (possible waypoints or random movement)
(@CGUID+1610, 780, 0, 1, 1, -12614.44, -577.0463, 34.20673, 0.973582, 120, 0, 0), -- Skullsplitter Mystic (Area: 0) (possible waypoints or random movement)
(@CGUID+1611, 687, 0, 1, 1, -12623.71, -719.0594, 42.67704, 0.3466556, 120, 0, 0), -- Jungle Stalker (Area: 0)
(@CGUID+1612, 50479, 0, 1, 1, -12615.71, -806.7978, 57.7928, 3.512929, 120, 0, 0), -- Lizard Hatchling (Area: Balia'mah Ruins)
(@CGUID+1613, 687, 0, 1, 1, -12611.63, -850.6041, 52.9556, 0.05759575, 120, 0, 0), -- Jungle Stalker (Area: Balia'mah Ruins)
(@CGUID+1614, 780, 0, 1, 1, -12619.73, -784.8185, 46.09742, 3.432489, 120, 0, 0), -- Skullsplitter Mystic (Area: Balia'mah Ruins) (possible waypoints or random movement)
(@CGUID+1615, 687, 0, 1, 1, -12639.31, -751.9495, 42.4081, 5.28901, 120, 0, 0), -- Jungle Stalker (Area: Balia'mah Ruins)
(@CGUID+1616, 9600, 0, 1, 1, -12599.75, -789.8285, 75.28508, 5.717067, 120, 0, 0), -- Parrot (Area: Balia'mah Ruins)
(@CGUID+1617, 687, 0, 1, 1, -12617.7, -920.8084, 54.73592, 3.390273, 120, 0, 0), -- Jungle Stalker (Area: Balia'mah Ruins)
(@CGUID+1618, 50487, 0, 1, 1, -12635.16, -905.6721, 57.0412, 4.915709, 120, 0, 0), -- Forest Spiderling (Area: Balia'mah Ruins) (possible waypoints or random movement)
(@CGUID+1619, 15475, 0, 1, 1, -12635.52, -1052.325, 97.93942, 0.394641, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+1620, 15475, 0, 1, 1, -12688.68, -1179.013, 144.1831, 2.44935, 120, 0, 0), -- Beetle (Area: Zul'Gurub)
(@CGUID+1621, 2687, 0, 1, 1, -12697.2, -1024.53, 94.8524, 4.425337, 120, 0, 0), -- Gnaz Blunderflame (Area: 0) (possible waypoints or random movement)
(@CGUID+1622, 8679, 0, 1, 1, -12687.6, -1034.15, 94.94484, 3.141593, 120, 0, 0), -- Knaz Blunderflame (Area: 0)
(@CGUID+1623, 49928, 0, 1, 1, -12670.35, -1054.994, 119.2924, 5.564229, 120, 0, 0), -- Crimson Moth (Area: 0)
(@CGUID+1624, 9600, 0, 1, 1, -12693.9, -894.7907, 75.17222, 1.074243, 120, 0, 0), -- Parrot (Area: 0)
(@CGUID+1625, 687, 0, 1, 1, -12680.9, -919.257, 55.51546, 5.647123, 120, 0, 0), -- Jungle Stalker (Area: 0)
(@CGUID+1626, 15475, 0, 1, 1, -12695.13, -814.5778, 61.49844, 1.531754, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+1627, 49722, 0, 1, 1, -12690.85, -874.2087, 54.45797, 2.961041, 120, 0, 0), -- Tree Python (Area: 0) (possible waypoints or random movement)
(@CGUID+1628, 687, 0, 1, 1, -12713.69, -881.6893, 53.7621, 0.7372724, 120, 0, 0), -- Jungle Stalker (Area: 0)
(@CGUID+1629, 687, 0, 1, 1, -12682.64, -852.5997, 55.4142, 5.236383, 120, 0, 0), -- Jungle Stalker (Area: 0)
(@CGUID+1630, 49722, 0, 1, 1, -12662.34, -829.3867, 56.33022, 1.917233, 120, 0, 0), -- Tree Python (Area: 0) (possible waypoints or random movement)
(@CGUID+1631, 43050, 0, 1, 1, -12717.64, -772.7332, 65.63007, 4.802342, 120, 0, 0), -- Vale Howler (Area: Balia'mah Ruins) (possible waypoints or random movement)
(@CGUID+1632, 687, 0, 1, 1, -12687.08, -780.4808, 63.28156, 1.191986, 120, 0, 0), -- Jungle Stalker (Area: Balia'mah Ruins)
(@CGUID+1633, 687, 0, 1, 1, -12718.63, -745.201, 65.59201, 1.459277, 120, 0, 0), -- Jungle Stalker (Area: Balia'mah Ruins)
(@CGUID+1634, 687, 0, 1, 1, -12654.31, -688.1654, 42.49171, 5.173789, 120, 0, 0), -- Jungle Stalker (Area: Balia'mah Ruins)
(@CGUID+1635, 687, 0, 1, 1, -12720.12, -685.522, 58.89453, 4.103263, 120, 0, 0), -- Jungle Stalker (Area: Balia'mah Ruins)
(@CGUID+1636, 696, 0, 1, 1, -12685.8, -591.7462, 37.80522, 2.100989, 120, 0, 0), -- Skullsplitter Axe Thrower (Area: Balia'mah Ruins) (possible waypoints or random movement)
(@CGUID+1637, 49928, 0, 1, 1, -12683.65, -621.6477, 57.21195, 6.125718, 120, 0, 0), -- Crimson Moth (Area: Balia'mah Ruins)
(@CGUID+1638, 687, 0, 1, 1, -12675.94, -655.9799, 39.04049, 1.993383, 120, 0, 0), -- Jungle Stalker (Area: Balia'mah Ruins)
(@CGUID+1639, 15475, 0, 1, 1, -12657.98, -652.8638, 41.8477, 4.672817, 120, 0, 0), -- Beetle (Area: Balia'mah Ruins)
(@CGUID+1640, 696, 0, 1, 1, -12720.71, -547.3887, 32.07823, 3.114962, 120, 0, 0), -- Skullsplitter Axe Thrower (Area: Balia'mah Ruins) (possible waypoints or random movement)
(@CGUID+1641, 50487, 0, 1, 1, -12716.74, -615.0623, 39.49022, 1.968946, 120, 0, 0), -- Forest Spiderling (Area: Balia'mah Ruins) (possible waypoints or random movement)
(@CGUID+1642, 50479, 0, 1, 1, -12714.03, -586.8187, 36.9527, 2.436355, 120, 0, 0), -- Lizard Hatchling (Area: Balia'mah Ruins)
(@CGUID+1643, 696, 0, 1, 1, -12716.44, -556.0269, 32.96807, 1.752311, 120, 0, 0), -- Skullsplitter Axe Thrower (Area: Balia'mah Ruins) (possible waypoints or random movement)
(@CGUID+1644, 696, 0, 1, 1, -12659.62, -553.6194, 34.82482, 3.772976, 120, 0, 0), -- Skullsplitter Axe Thrower (Area: Balia'mah Ruins) (possible waypoints or random movement)
(@CGUID+1645, 696, 0, 1, 1, -12659.06, -486.2565, 29.70319, 0.4453784, 120, 0, 0), -- Skullsplitter Axe Thrower (Area: Balia'mah Ruins) (possible waypoints or random movement)
(@CGUID+1646, 780, 0, 1, 1, -12663.52, -489.7393, 29.61652, 1.546359, 120, 0, 0), -- Skullsplitter Mystic (Area: Balia'mah Ruins) (possible waypoints or random movement)
(@CGUID+1647, 50487, 0, 1, 1, -12711.38, -490.5824, 30.30876, 0.5432968, 120, 0, 0), -- Forest Spiderling (Area: Ziata'jai Ruins) (possible waypoints or random movement)
(@CGUID+1648, 667, 0, 1, 1, -12669.95, -486.6396, 29.73556, 2.781349, 120, 0, 0), -- Skullsplitter Warrior (Area: Ziata'jai Ruins) (possible waypoints or random movement)
(@CGUID+1649, 667, 0, 1, 1, -12712.43, -467.5211, 29.5717, 4.884854, 120, 0, 0), -- Skullsplitter Warrior (Area: Ziata'jai Ruins) (possible waypoints or random movement)
(@CGUID+1650, 667, 0, 1, 1, -12704.33, -478.218, 30.37639, 0.2794294, 120, 0, 0), -- Skullsplitter Warrior (Area: Ziata'jai Ruins) (possible waypoints or random movement)
(@CGUID+1651, 780, 0, 1, 1, -12711.64, -454.4039, 30.53089, 5.543532, 120, 0, 0), -- Skullsplitter Mystic (Area: Ziata'jai Ruins) (possible waypoints or random movement)
(@CGUID+1652, 696, 0, 1, 1, -12690.25, -470.27, 29.73556, 2.160037, 120, 0, 0), -- Skullsplitter Axe Thrower (Area: Ziata'jai Ruins) (possible waypoints or random movement)
(@CGUID+1653, 696, 0, 1, 1, -12698.84, -453.5787, 30.9406, 2.915172, 120, 0, 0), -- Skullsplitter Axe Thrower (Area: Ziata'jai Ruins) (possible waypoints or random movement)
(@CGUID+1654, 49722, 0, 1, 1, -12650.52, -423.3635, 21.64903, 3.666074, 120, 0, 0), -- Tree Python (Area: Ziata'jai Ruins) (possible waypoints or random movement)
(@CGUID+1655, 9600, 0, 1, 1, -12652.19, -457.7418, 46.62471, 1.137775, 120, 0, 0), -- Parrot (Area: Ziata'jai Ruins)
(@CGUID+1656, 1085, 0, 1, 1, -12657.42, -310.378, 16.9835, 3.647499, 120, 0, 0), -- Elder Stranglethorn Tiger (Area: Ziata'jai Ruins)
(@CGUID+1657, 50487, 0, 1, 1, -12702.92, -242.752, 36.29594, 6.009273, 120, 0, 0), -- Forest Spiderling (Area: 0) (possible waypoints or random movement)
(@CGUID+1658, 49928, 0, 1, 1, -12652.83, -205.5402, 47.20705, 5.195162, 120, 0, 0), -- Crimson Moth (Area: 0)
(@CGUID+1659, 1085, 0, 1, 1, -12724.2, -175.4593, 30.08305, 2.251028, 120, 0, 0), -- Elder Stranglethorn Tiger (Area: 0)
(@CGUID+1660, 6827, 0, 1, 1, -12677.99, -23.80078, 0.2200069, 5.967607, 120, 0, 0), -- Crab (Area: 0)
(@CGUID+1661, 6827, 0, 1, 1, -12714.62, 72.53668, 1.37387, 0.5720304, 120, 0, 0), -- Crab (Area: The Savage Coast)
(@CGUID+1662, 9600, 0, 1, 1, -12720.8, 115.8271, 27.59769, 3.960517, 120, 0, 0), -- Parrot (Area: The Savage Coast)
(@CGUID+1663, 6827, 0, 1, 1, -12714.48, 243.8578, -0.2903748, 0.7091601, 120, 0, 0), -- Crab (Area: The Savage Coast)
(@CGUID+1664, 6827, 0, 1, 1, -12707.6, 164.0374, 5.256544, 1.234214, 120, 0, 0), -- Crab (Area: The Savage Coast)
(@CGUID+1665, 6827, 0, 1, 1, -12690.34, 160.1569, 0.5622911, 0.674741, 120, 0, 0), -- Crab (Area: The Savage Coast)
(@CGUID+1666, 6827, 0, 1, 1, -12731.56, 265.0003, 2.873639, 5.583365, 120, 0, 0), -- Crab (Area: The Vile Reef)
(@CGUID+1667, 32520, 0, 1, 1, -5691.65, 5556.92, -1154.687, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Southern Savage Coast)
(@CGUID+1668, 32520, 0, 1, 1, -6014.71, 5479.63, -1208.007, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Southern Savage Coast)
(@CGUID+1669, 32520, 0, 1, 1, -6148.39, 5539.97, -1207.787, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Southern Savage Coast)
(@CGUID+1670, 32520, 0, 1, 1, -6305.162, 5582.533, -1172.063, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Southern Savage Coast)
(@CGUID+1671, 690, 0, 1, 1, -12748.97, 219.2971, 6.00827, 2.053401, 120, 0, 0), -- Cold Eye Basilisk (Area: The Vile Reef)
(@CGUID+1672, 690, 0, 1, 1, -12749.24, 248.5606, 6.790214, 3.453455, 120, 0, 0), -- Cold Eye Basilisk (Area: The Vile Reef)
(@CGUID+1673, 690, 0, 1, 1, -12771.69, 312.4377, 9.402248, 2.986816, 120, 0, 0), -- Cold Eye Basilisk (Area: The Vile Reef)
(@CGUID+1674, 49928, 0, 1, 1, -12758.06, 44.01915, 30.25624, 1.943422, 120, 0, 0), -- Crimson Moth (Area: Southern Savage Coast)
(@CGUID+1675, 49722, 0, 1, 1, -12748.68, 80.93349, 7.630445, 5.246785, 120, 0, 0), -- Tree Python (Area: Southern Savage Coast) (possible waypoints or random movement)
(@CGUID+1676, 50479, 0, 1, 1, -12724.71, -190.5053, 33.08929, 1.64113, 120, 0, 0), -- Lizard Hatchling (Area: The Savage Coast)
(@CGUID+1677, 684, 0, 1, 1, -12652.63, -113.6639, 18.78314, 0.2686485, 120, 0, 0), -- Shadowmaw Panther (Area: The Savage Coast)
(@CGUID+1678, 9600, 0, 1, 1, -12757.44, -192.9345, 38.54412, 1.982006, 120, 0, 0), -- Parrot (Area: 0)
(@CGUID+1679, 9600, 0, 1, 1, -12718.25, -232.3206, 46.79393, 0.9278143, 120, 0, 0), -- Parrot (Area: 0)
(@CGUID+1680, 1085, 0, 1, 1, -12716.62, -233.1994, 36.73452, 3.954608, 120, 0, 0), -- Elder Stranglethorn Tiger (Area: 0)
(@CGUID+1681, 684, 0, 1, 1, -12662.93, -215.528, 8.595478, 2.592872, 120, 0, 0), -- Shadowmaw Panther (Area: 0)
(@CGUID+1682, 49928, 0, 1, 1, -12758.06, -281.1878, 34.75991, 4.901661, 120, 0, 0), -- Crimson Moth (Area: 0)
(@CGUID+1683, 49928, 0, 1, 1, -12724.69, -482.6153, 47.78356, 4.312617, 120, 0, 0), -- Crimson Moth (Area: 0)
(@CGUID+1684, 49722, 0, 1, 1, -12739.03, -513.6966, 30.11997, 0.7922946, 120, 0, 0), -- Tree Python (Area: Ziata'jai Ruins) (possible waypoints or random movement)
(@CGUID+1685, 50487, 0, 1, 1, -12746.59, -594.3992, 40.31282, 0.02295052, 120, 0, 0), -- Forest Spiderling (Area: Ziata'jai Ruins) (possible waypoints or random movement)
(@CGUID+1686, 43050, 0, 1, 1, -12742.41, -604.0794, 42.99286, 4.527641, 120, 0, 0), -- Vale Howler (Area: Ziata'jai Ruins) (possible waypoints or random movement)
(@CGUID+1687, 780, 0, 1, 1, -12744.94, -579.0729, 37.5201, 1.249067, 120, 0, 0), -- Skullsplitter Mystic (Area: Ziata'jai Ruins) (possible waypoints or random movement)
(@CGUID+1688, 687, 0, 1, 1, -12715.92, -612.0608, 39.04757, 2.425336, 120, 0, 0), -- Jungle Stalker (Area: Ziata'jai Ruins)
(@CGUID+1689, 49722, 0, 1, 1, -12712.73, -729.0938, 65.9854, 0.7831125, 120, 0, 0), -- Tree Python (Area: Balia'mah Ruins) (possible waypoints or random movement)
(@CGUID+1690, 687, 0, 1, 1, -12745.14, -720.9395, 66.52198, 6.267562, 120, 0, 0), -- Jungle Stalker (Area: Balia'mah Ruins)
(@CGUID+1691, 687, 0, 1, 1, -12742.64, -853.524, 60.77105, 1.84561, 120, 0, 0), -- Jungle Stalker (Area: Balia'mah Ruins)
(@CGUID+1692, 50479, 0, 1, 1, -12742.43, -789.5129, 62.10415, 0.4942057, 120, 0, 0), -- Lizard Hatchling (Area: Balia'mah Ruins)
(@CGUID+1693, 15475, 0, 1, 1, -12738.09, -893.3745, 56.05928, 0.06643827, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+1694, 687, 0, 1, 1, -12759.63, -918.0001, 53.64156, 2.827298, 120, 0, 0), -- Jungle Stalker (Area: 0)
(@CGUID+1695, 687, 0, 1, 1, -12746.01, -786.8238, 61.7546, 5.431617, 120, 0, 0), -- Jungle Stalker (Area: 0)
(@CGUID+1696, 6827, 0, 1, 1, -12811.04, 418.4438, -0.3354119, 6.163679, 120, 0, 0), -- Crab (Area: Southern Savage Coast)
(@CGUID+1697, 690, 0, 1, 1, -12817.38, 384.1792, 8.184963, 1.967992, 120, 0, 0), -- Cold Eye Basilisk (Area: The Vile Reef)
(@CGUID+1698, 6827, 0, 1, 1, -12814.3, 387.4831, 5.488064, 1.045111, 120, 0, 0), -- Crab (Area: The Vile Reef)
(@CGUID+1699, 6827, 0, 1, 1, -12789.38, 360.1665, 9.22859, 2.962962, 120, 0, 0), -- Crab (Area: The Vile Reef)
(@CGUID+1700, 690, 0, 1, 1, -12784.63, 353.8785, 8.546102, 6.159599, 120, 0, 0), -- Cold Eye Basilisk (Area: The Vile Reef)
(@CGUID+1701, 15475, 0, 1, 1, -12798.66, 130.6633, 18.51114, 5.802073, 120, 0, 0), -- Beetle (Area: Southern Savage Coast)
(@CGUID+1702, 1713, 0, 1, 1, -12731.92, 113.3783, 9.638994, 3.639063, 120, 0, 0), -- Elder Shadowmaw Panther (Area: Southern Savage Coast)
(@CGUID+1703, 50479, 0, 1, 1, -12772.83, -94.82812, 12.82635, 1.427795, 120, 0, 0), -- Lizard Hatchling (Area: The Savage Coast)
(@CGUID+1704, 32520, 0, 1, 1, -6014.71, 5479.63, -1208.007, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: 0)
(@CGUID+1705, 32520, 0, 1, 1, -6305.162, 5582.533, -1172.063, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: 0)
(@CGUID+1706, 32520, 0, 1, 1, -5691.65, 5556.92, -1154.687, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: 0)
(@CGUID+1707, 32520, 0, 1, 1, -6148.39, 5539.97, -1207.787, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: 0)
(@CGUID+1708, 1085, 0, 1, 1, -12778.58, -344.946, 14.93966, 1.871853, 120, 0, 0), -- Elder Stranglethorn Tiger (Area: 0)
(@CGUID+1709, 15475, 0, 1, 1, -12779.88, -353.4041, 13.76314, 2.170203, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+1710, 684, 0, 1, 1, -12716.63, -408.3353, 17.28584, 3.957368, 120, 0, 0), -- Shadowmaw Panther (Area: 0)
(@CGUID+1711, 1085, 0, 1, 1, -12784.68, -491.5805, 21.96135, 3.004349, 120, 0, 0), -- Elder Stranglethorn Tiger (Area: 0)
(@CGUID+1712, 669, 0, 1, 1, -12784.66, -547.7746, 39.31753, 1.843913, 120, 0, 0), -- Skullsplitter Hunter (Area: Ziata'jai Ruins) (possible waypoints or random movement)
(@CGUID+1713, 687, 0, 1, 1, -12777.2, -621.0202, 57.52934, 1.7832, 120, 0, 0), -- Jungle Stalker (Area: Ziata'jai Ruins)
(@CGUID+1714, 782, 0, 1, 1, -12781.97, -710.8917, 63.05213, 6.06704, 120, 0, 0), -- Skullsplitter Scout (Area: Ziata'jai Ruins) (possible waypoints or random movement)
(@CGUID+1715, 669, 0, 1, 1, -12777.41, -654.1033, 64.52789, 4.512582, 120, 0, 0), -- Skullsplitter Hunter (Area: Ziata'jai Ruins) (possible waypoints or random movement)
(@CGUID+1716, 687, 0, 1, 1, -12783.55, -816.1387, 69.95894, 1.883379, 120, 0, 0), -- Jungle Stalker (Area: 0)
(@CGUID+1717, 49928, 0, 1, 1, -12768.72, -753.2063, 83.98857, 3.643895, 120, 0, 0), -- Crimson Moth (Area: 0)
(@CGUID+1718, 669, 0, 1, 1, -12798.21, -782.7723, 62.57784, 0.6462896, 120, 0, 0), -- Skullsplitter Hunter (Area: 0) (possible waypoints or random movement)
(@CGUID+1719, 687, 0, 1, 1, -12775.88, -885.8951, 53.96024, 2.161509, 120, 0, 0), -- Jungle Stalker (Area: 0)
(@CGUID+1720, 9600, 0, 1, 1, -12763.17, -935.7054, 92.05171, 2.665455, 120, 0, 0), -- Parrot (Area: 0)
(@CGUID+1721, 42173, 0, 1, 1, -6396.681, 7054.327, -1069.238, 3.071779, 120, 0, 0), -- The Undershell Tentacle Flavor (Area: 0)
(@CGUID+1722, 52908, 0, 1, 1, -12864.29, -1394.569, 143.6625, 0, 120, 0, 0), -- Generic Bunny (Area: 0)
(@CGUID+1723, 669, 0, 1, 1, -12822.23, -817.0638, 60.08236, 3.444073, 120, 0, 0), -- Skullsplitter Hunter (Area: 0) (possible waypoints or random movement)
(@CGUID+1724, 670, 0, 1, 1, -12852.17, -848.6571, 54.89083, 2.671547, 120, 0, 0), -- Skullsplitter Witch Doctor (Area: 0) (possible waypoints or random movement)
(@CGUID+1725, 9600, 0, 1, 1, -12825.12, -813.3549, 83.79578, 3.681224, 120, 0, 0), -- Parrot (Area: 0)
(@CGUID+1726, 669, 0, 1, 1, -12860.7, -807.5538, 54.88034, 5.759586, 120, 0, 0), -- Skullsplitter Hunter (Area: 0)
(@CGUID+1727, 670, 0, 1, 1, -12836.28, -743.8177, 74.67068, 0.5585054, 120, 0, 0), -- Skullsplitter Witch Doctor (Area: 0)
(@CGUID+1728, 670, 0, 1, 1, -12822.2, -751.5667, 77.05022, 4.272408, 120, 0, 0), -- Skullsplitter Witch Doctor (Area: 0) (possible waypoints or random movement)
(@CGUID+1729, 670, 0, 1, 1, -12859.82, -774.4499, 60.24871, 2.295356, 120, 0, 0), -- Skullsplitter Witch Doctor (Area: 0) (possible waypoints or random movement)
(@CGUID+1730, 50487, 0, 1, 1, -12853.78, -677.6816, 61.36258, 6.02447, 120, 0, 0), -- Forest Spiderling (Area: 0) (possible waypoints or random movement)
(@CGUID+1731, 9600, 0, 1, 1, -12807.74, -640.6646, 86.40136, 2.976817, 120, 0, 0), -- Parrot (Area: 0)
(@CGUID+1732, 782, 0, 1, 1, -12813.51, -664.9718, 70.77808, 1.205404, 120, 0, 0), -- Skullsplitter Scout (Area: 0) (possible waypoints or random movement)
(@CGUID+1733, 782, 0, 1, 1, -12845.32, -572.0134, 61.03753, 3.609293, 120, 0, 0), -- Skullsplitter Scout (Area: 0) (possible waypoints or random movement)
(@CGUID+1734, 669, 0, 1, 1, -12856.96, -605.6563, 56.87199, 0.9948376, 120, 0, 0), -- Skullsplitter Hunter (Area: 0)
(@CGUID+1735, 670, 0, 1, 1, -12847.67, -597.7776, 56.05022, 3.09984, 120, 0, 0), -- Skullsplitter Witch Doctor (Area: 0) (possible waypoints or random movement)
(@CGUID+1736, 782, 0, 1, 1, -12848.88, -549.2219, 50.04341, 3.534945, 120, 0, 0), -- Skullsplitter Scout (Area: 0) (possible waypoints or random movement)
(@CGUID+1737, 50479, 0, 1, 1, -12833.95, -540.1962, 47.90641, 3.926522, 120, 0, 0), -- Lizard Hatchling (Area: 0)
(@CGUID+1738, 44043, 0, 1, 1, -12826.33, -432.6876, 13.07884, 4.540861, 120, 0, 0), -- Kinnel (Area: 0) (possible waypoints or random movement)
(@CGUID+1739, 44018, 0, 1, 1, -12828.8, -444.807, 13.05003, 2.042035, 120, 0, 0), -- Wulfred Harrys (Area: 0)
(@CGUID+1740, 44017, 0, 1, 1, -12841.1, -447.958, 13.04993, 1.727876, 120, 0, 0), -- Priestess Thaalia (Area: 0)
(@CGUID+1741, 50479, 0, 1, 1, -12806.1, -444.6059, 13.07229, 6.162231, 120, 0, 0), -- Lizard Hatchling (Area: 0)
(@CGUID+1742, 44019, 0, 1, 1, -12846.1, -437.988, 13.05003, 0.715585, 120, 0, 0), -- Livingston Marshal (Area: 0)
(@CGUID+1743, 44021, 0, 1, 1, -12843, -415.333, 13.05093, 5.253441, 120, 0, 0), -- Ghaliri (Area: 0)
(@CGUID+1744, 43042, 0, 1, 1, -12823.31, -414.4375, 13.05092, 3.333579, 120, 0, 0), -- Robert Rhodes (Area: 0)
(@CGUID+1745, 44181, 0, 1, 1, -12851.6, -417.425, 13.04943, 0.3141593, 120, 0, 0), -- Daniel Roberts (Area: 0)
(@CGUID+1746, 50479, 0, 1, 1, -12866.56, -400.3193, 13.18628, 5.510826, 120, 0, 0), -- Lizard Hatchling (Area: 0)
(@CGUID+1747, 49928, 0, 1, 1, -12841.19, -326.1023, 38.76487, 3.020227, 120, 0, 0), -- Crimson Moth (Area: 0)
(@CGUID+1748, 49928, 0, 1, 1, -12826.13, -299.8579, 36.28484, 2.063958, 120, 0, 0), -- Crimson Moth (Area: 0)
(@CGUID+1749, 49928, 0, 1, 1, -12862.88, -75.20513, 35.90261, 2.345793, 120, 0, 0), -- Crimson Moth (Area: The Sundering)
(@CGUID+1750, 15475, 0, 1, 1, -12867.86, -46.86036, 18.48555, 4.213821, 120, 0, 0), -- Beetle (Area: The Sundering)
(@CGUID+1751, 50479, 0, 1, 1, -12806.26, 158.7369, 19.8657, 0.3360965, 120, 0, 0), -- Lizard Hatchling (Area: Cape of Stranglethorn)
(@CGUID+1752, 6827, 0, 1, 1, -12842.42, 425.4823, 4.075174, 5.371651, 120, 0, 0), -- Crab (Area: Southern Savage Coast)
(@CGUID+1753, 690, 0, 1, 1, -12855.59, 413.0776, 17.01585, 2.373602, 120, 0, 0), -- Cold Eye Basilisk (Area: Southern Savage Coast)
(@CGUID+1754, 6827, 0, 1, 1, -12891.47, 490.3893, 6.946335, 1.473466, 120, 0, 0), -- Crab (Area: Southern Savage Coast)
(@CGUID+1755, 690, 0, 1, 1, -12909.38, 445.9095, 22.51426, 6.211051, 120, 0, 0), -- Cold Eye Basilisk (Area: Southern Savage Coast)
(@CGUID+1756, 50479, 0, 1, 1, -12931, 425.9565, 24.98966, 3.878619, 120, 0, 0), -- Lizard Hatchling (Area: Southern Savage Coast)
(@CGUID+1757, 50487, 0, 1, 1, -12870.59, 223.8922, 18.28367, 5.457698, 120, 0, 0), -- Forest Spiderling (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+1758, 49722, 0, 1, 1, -12894.69, 260.181, 17.58873, 2.857129, 120, 0, 0), -- Tree Python (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+1759, 9600, 0, 1, 1, -12886.07, 169.2402, 35.91113, 0.7696314, 120, 0, 0), -- Parrot (Area: Cape of Stranglethorn)
(@CGUID+1760, 1713, 0, 1, 1, -12854.98, 191.6955, 18.07266, 4.502151, 120, 0, 0), -- Elder Shadowmaw Panther (Area: Cape of Stranglethorn)
(@CGUID+1761, 1713, 0, 1, 1, -12811.09, 155.4649, 20.52684, 2.802579, 120, 0, 0), -- Elder Shadowmaw Panther (Area: Cape of Stranglethorn)
(@CGUID+1762, 1713, 0, 1, 1, -12844.25, 138.1733, 17.9823, 2.644686, 120, 0, 0), -- Elder Shadowmaw Panther (Area: Cape of Stranglethorn)
(@CGUID+1763, 50487, 0, 1, 1, -12915.32, 111.459, 27.02785, 3.141593, 120, 0, 0), -- Forest Spiderling (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+1764, 1713, 0, 1, 1, -12820.12, 85.1998, 16.7524, 1.79907, 120, 0, 0), -- Elder Shadowmaw Panther (Area: Cape of Stranglethorn)
(@CGUID+1765, 1713, 0, 1, 1, -12844.8, 70.71291, 16.42105, 0.5825914, 120, 0, 0), -- Elder Shadowmaw Panther (Area: Cape of Stranglethorn)
(@CGUID+1766, 50487, 0, 1, 1, -12895.23, -355.3687, 22.75529, 0.05278848, 120, 0, 0), -- Forest Spiderling (Area: 0) (possible waypoints or random movement)
(@CGUID+1767, 674, 0, 1, 1, -12946.78, -466.2917, 55.70167, 2.321288, 120, 0, 0), -- Venture Co. Strip Miner (Area: Fort Livingston)
(@CGUID+1768, 677, 0, 1, 1, -12944.19, -448.4604, 38.45776, 5.575509, 120, 0, 0), -- Venture Co. Tinkerer (Area: Fort Livingston)
(@CGUID+1769, 674, 0, 1, 1, -12930.48, -432.2718, 31.94846, 0.2443461, 120, 0, 0), -- Venture Co. Strip Miner (Area: Fort Livingston)
(@CGUID+1770, 669, 0, 1, 1, -12873.25, -592.7072, 60.65382, 3.790459, 120, 0, 0), -- Skullsplitter Hunter (Area: 0) (possible waypoints or random movement)
(@CGUID+1771, 669, 0, 1, 1, -12877.75, -573.4885, 51.1316, 5.189515, 120, 0, 0), -- Skullsplitter Hunter (Area: 0) (possible waypoints or random movement)
(@CGUID+1772, 669, 0, 1, 1, -12881.35, -650.4427, 54.40588, 4.889472, 120, 0, 0), -- Skullsplitter Hunter (Area: 0) (possible waypoints or random movement)
(@CGUID+1773, 9600, 0, 1, 1, -12876.86, -625.6147, 73.6937, 2.250191, 120, 0, 0), -- Parrot (Area: 0)
(@CGUID+1774, 782, 0, 1, 1, -12857.76, -656.0044, 57.66718, 0.4035203, 120, 0, 0), -- Skullsplitter Scout (Area: 0) (possible waypoints or random movement)
(@CGUID+1775, 782, 0, 1, 1, -12885.06, -716.4804, 53.63786, 5.342089, 120, 0, 0), -- Skullsplitter Scout (Area: 0) (possible waypoints or random movement)
(@CGUID+1776, 49722, 0, 1, 1, -12864.39, -775.6221, 58.24379, 5.926242, 120, 0, 0), -- Tree Python (Area: 0) (possible waypoints or random movement)
(@CGUID+1777, 670, 0, 1, 1, -12889.25, -750.6198, 54.15278, 0.4363323, 120, 0, 0), -- Skullsplitter Witch Doctor (Area: 0)
(@CGUID+1778, 669, 0, 1, 1, -12877.42, -826.4809, 54.82589, 2.548181, 120, 0, 0), -- Skullsplitter Hunter (Area: 0)
(@CGUID+1779, 15475, 0, 1, 1, -12886.21, -859.9453, 62.13873, 2.902116, 120, 0, 0), -- Beetle (Area: Ruins of Zul'Mamwe)
(@CGUID+1780, 669, 0, 1, 1, -12877.38, -885.6189, 54.91834, 5.084113, 120, 0, 0), -- Skullsplitter Hunter (Area: Ruins of Zul'Mamwe) (possible waypoints or random movement)
(@CGUID+1781, 32520, 0, 1, 1, -5691.65, 5556.92, -1154.687, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: 0)
(@CGUID+1782, 32520, 0, 1, 1, -6148.39, 5539.97, -1207.787, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: 0)
(@CGUID+1783, 32520, 0, 1, 1, -6014.71, 5479.63, -1208.007, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: 0)
(@CGUID+1784, 32520, 0, 1, 1, -6305.162, 5582.533, -1172.063, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: 0)
(@CGUID+1785, 670, 0, 1, 1, -12907.64, -875.309, 70.10404, 0, 120, 0, 0), -- Skullsplitter Witch Doctor (Area: 0)
(@CGUID+1786, 730, 0, 1, 1, -12733.5, -847.1278, 58.93308, 1.664638, 120, 0, 0), -- Tethis (Area: 0)
(@CGUID+1787, 782, 0, 1, 1, -12914.85, -817.9904, 57.91438, 2.30652, 120, 0, 0), -- Skullsplitter Scout (Area: Ruins of Zul'Mamwe) (possible waypoints or random movement)
(@CGUID+1788, 49722, 0, 1, 1, -12912.71, -803.7991, 54.2754, 4.950742, 120, 0, 0), -- Tree Python (Area: Ruins of Zul'Mamwe) (possible waypoints or random movement)
(@CGUID+1789, 49722, 0, 1, 1, -12909, -744.5564, 51.31609, 0.1434682, 120, 0, 0), -- Tree Python (Area: Ruins of Zul'Mamwe) (possible waypoints or random movement)
(@CGUID+1790, 15475, 0, 1, 1, -12932.88, -622.507, 54.28681, 4.370892, 120, 0, 0), -- Beetle (Area: 0)
(@CGUID+1791, 669, 0, 1, 1, -12909.13, -618.2786, 53.43668, 3.868122, 120, 0, 0), -- Skullsplitter Hunter (Area: 0) (possible waypoints or random movement)
(@CGUID+1792, 6827, 0, 1, 1, -12955.82, 476.0359, 2.839965, 6.259752, 120, 0, 0), -- Crab (Area: Southern Savage Coast)
(@CGUID+1793, 690, 0, 1, 1, -12978.69, 453.3298, 20.57173, 5.268637, 120, 0, 0), -- Cold Eye Basilisk (Area: Southern Savage Coast)
(@CGUID+1794, 690, 0, 1, 1, -12949.38, 415.5577, 24.51849, 2.389968, 120, 0, 0), -- Cold Eye Basilisk (Area: Southern Savage Coast)
(@CGUID+1795, 674, 0, 1, 1, -12968.64, -435.6509, 44.45884, 4.869469, 120, 0, 0), -- Venture Co. Strip Miner (Area: 0)
(@CGUID+1796, 674, 0, 1, 1, -12937.61, -451.9769, 37.32224, 5.810824, 120, 0, 0), -- Venture Co. Strip Miner (Area: 0)
(@CGUID+1797, 9600, 0, 1, 1, -12964.57, -417.6149, 64.62031, 3.552688, 120, 0, 0), -- Parrot (Area: 0)
(@CGUID+1798, 669, 0, 1, 1, -12942.25, -606.2442, 53.36177, 0.08493859, 120, 0, 0), -- Skullsplitter Hunter (Area: 0) (possible waypoints or random movement)
(@CGUID+1799, 784, 0, 1, 1, -12938.76, -622.1333, 52.71382, 5.362679, 120, 0, 0), -- Skullsplitter Beastmaster (Area: 0) (possible waypoints or random movement)
(@CGUID+1800, 784, 0, 1, 1, -12984.08, -609.7603, 53.7368, 1.249413, 120, 0, 0), -- Skullsplitter Beastmaster (Area: 0) (possible waypoints or random movement)
(@CGUID+1801, 670, 0, 1, 1, -12952.2, -626.9324, 53.29463, 0.5713662, 120, 0, 0), -- Skullsplitter Witch Doctor (Area: 0) (possible waypoints or random movement)
(@CGUID+1802, 670, 0, 1, 1, -12953.45, -616.6163, 52.49906, 5.969026, 120, 0, 0), -- Skullsplitter Witch Doctor (Area: 0) (possible waypoints or random movement)
(@CGUID+1803, 782, 0, 1, 1, -12946.4, -702.3752, 54.27452, 2.732556, 120, 0, 0), -- Skullsplitter Scout (Area: Ruins of Zul'Mamwe) (possible waypoints or random movement)
(@CGUID+1804, 669, 0, 1, 1, -12964.26, -686.4221, 53.44489, 5.720533, 120, 0, 0), -- Skullsplitter Hunter (Area: Ruins of Zul'Mamwe) (possible waypoints or random movement)
(@CGUID+1805, 782, 0, 1, 1, -12945.97, -720.3732, 53.73106, 2.603373, 120, 0, 0), -- Skullsplitter Scout (Area: Ruins of Zul'Mamwe) (possible waypoints or random movement)
(@CGUID+1806, 669, 0, 1, 1, -12969.45, -705.8627, 53.38804, 3.811203, 120, 0, 0), -- Skullsplitter Hunter (Area: Ruins of Zul'Mamwe) (possible waypoints or random movement)
(@CGUID+1807, 669, 0, 1, 1, -12988.41, -688.6129, 54.05345, 2.426067, 120, 0, 0), -- Skullsplitter Hunter (Area: Ruins of Zul'Mamwe) (possible waypoints or random movement)
(@CGUID+1808, 669, 0, 1, 1, -12982.55, -715.4219, 54.2248, 1.815142, 120, 0, 0), -- Skullsplitter Hunter (Area: Ruins of Zul'Mamwe)
(@CGUID+1809, 670, 0, 1, 1, -12985.63, -711.5764, 53.9227, 5.934119, 120, 0, 0), -- Skullsplitter Witch Doctor (Area: Ruins of Zul'Mamwe)
(@CGUID+1810, 782, 0, 1, 1, -12980.75, -727.696, 55.63682, 0.6765128, 120, 0, 0), -- Skullsplitter Scout (Area: Ruins of Zul'Mamwe) (possible waypoints or random movement)
(@CGUID+1811, 784, 0, 1, 1, -12899.18, -789.8127, 52.1615, 2.415091, 120, 0, 0), -- Skullsplitter Beastmaster (Area: Ruins of Zul'Mamwe) (possible waypoints or random movement)
(@CGUID+1812, 669, 0, 1, 1, -12948.43, -782.3354, 58.68945, 4.626747, 120, 0, 0), -- Skullsplitter Hunter (Area: Ruins of Zul'Mamwe) (possible waypoints or random movement)
(@CGUID+1813, 781, 0, 1, 1, -12962.64, -820.5748, 69.63985, 0.3487444, 120, 0, 0), -- Skullsplitter Headhunter (Area: Ruins of Zul'Mamwe) (possible waypoints or random movement)
(@CGUID+1814, 50487, 0, 1, 1, -12912.37, -836.9029, 62.32368, 3.698224, 120, 0, 0), -- Forest Spiderling (Area: Ruins of Zul'Mamwe) (possible waypoints or random movement)
(@CGUID+1815, 782, 0, 1, 1, -12916.16, -859.78, 71.76241, 5.948088, 120, 0, 0), -- Skullsplitter Scout (Area: Ruins of Zul'Mamwe) (possible waypoints or random movement)
(@CGUID+1816, 672, 0, 1, 1, -12981.51, -824.3768, 70.61288, 5.846853, 120, 0, 0), -- Skullsplitter Spiritchaser (Area: Ruins of Zul'Mamwe) (possible waypoints or random movement)
(@CGUID+1817, 670, 0, 1, 1, -12937.58, -871.0191, 70.61124, 1.134464, 120, 0, 0), -- Skullsplitter Witch Doctor (Area: Ruins of Zul'Mamwe)
(@CGUID+1818, 15475, 0, 1, 1, -12943.16, -951.9325, 92.04068, 1.031047, 120, 0, 0), -- Beetle (Area: Ruins of Zul'Mamwe)
(@CGUID+1819, 52374, 0, 1, 1, -12835.81, -1373.406, 142.4564, 4.69127, 120, 0, 0), -- Panther Cub (Area: 0) (possible waypoints or random movement)
(@CGUID+1820, 781, 0, 1, 1, -12996.16, -832.3524, 70.92965, 4.747295, 120, 0, 0), -- Skullsplitter Headhunter (Area: Ruins of Zul'Mamwe)
(@CGUID+1821, 32520, 0, 1, 1, -6305.162, 5582.533, -1172.063, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Ruins of Zul'Mamwe)
(@CGUID+1822, 32520, 0, 1, 1, -6148.39, 5539.97, -1207.787, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Ruins of Zul'Mamwe)
(@CGUID+1823, 32520, 0, 1, 1, -6014.71, 5479.63, -1208.007, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Ruins of Zul'Mamwe)
(@CGUID+1824, 32520, 0, 1, 1, -5691.65, 5556.92, -1154.687, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Ruins of Zul'Mamwe)
(@CGUID+1825, 669, 0, 1, 1, -12943.95, -648.0558, 52.93177, 1.422271, 120, 0, 0), -- Skullsplitter Hunter (Area: Ruins of Zul'Mamwe) (possible waypoints or random movement)
(@CGUID+1826, 782, 0, 1, 1, -13001.25, -713.6942, 54.9279, 0.2390658, 120, 0, 0), -- Skullsplitter Scout (Area: Ruins of Zul'Mamwe) (possible waypoints or random movement)
(@CGUID+1827, 782, 0, 1, 1, -12995.16, -671.8113, 53.32127, 0.6998004, 120, 0, 0), -- Skullsplitter Scout (Area: Ruins of Zul'Mamwe) (possible waypoints or random movement)
(@CGUID+1828, 669, 0, 1, 1, -12982.02, -652.0844, 51.7949, 5.393397, 120, 0, 0), -- Skullsplitter Hunter (Area: Ruins of Zul'Mamwe) (possible waypoints or random movement)
(@CGUID+1829, 669, 0, 1, 1, -12947.98, -621.2309, 52.57101, 2.059489, 120, 0, 0), -- Skullsplitter Hunter (Area: Ruins of Zul'Mamwe)
(@CGUID+1830, 669, 0, 1, 1, -12983.68, -622.6925, 53.43822, 1.634526, 120, 0, 0), -- Skullsplitter Hunter (Area: Ruins of Zul'Mamwe) (possible waypoints or random movement)
(@CGUID+1831, 669, 0, 1, 1, -12963.71, -607.7789, 53.67353, 0.3917423, 120, 0, 0), -- Skullsplitter Hunter (Area: Ruins of Zul'Mamwe) (possible waypoints or random movement)
(@CGUID+1832, 50479, 0, 1, 1, -12988.9, -631.3758, 53.33421, 3.633193, 120, 0, 0), -- Lizard Hatchling (Area: Ruins of Zul'Mamwe)
(@CGUID+1833, 674, 0, 1, 1, -13002.64, -455.4685, 55.47535, 2.181662, 120, 0, 0), -- Venture Co. Strip Miner (Area: 0)
(@CGUID+1834, 675, 0, 1, 1, -12981.28, -451.0624, 53.5731, 5.55867, 120, 0, 0), -- Venture Co. Foreman (Area: 0)
(@CGUID+1835, 674, 0, 1, 1, -12998.29, -409.1326, 43.86582, 1.815142, 120, 0, 0), -- Venture Co. Strip Miner (Area: 0)
(@CGUID+1836, 49928, 0, 1, 1, -13013.42, 206.2233, 31.65138, 3.767482, 120, 0, 0), -- Crimson Moth (Area: Cape of Stranglethorn)
(@CGUID+1837, 15475, 0, 1, 1, -12992.71, 182.291, 20.70106, 4.148393, 120, 0, 0), -- Beetle (Area: Cape of Stranglethorn)
(@CGUID+1838, 1713, 0, 1, 1, -12947.3, 145.8072, 24.93621, 1.126377, 120, 0, 0), -- Elder Shadowmaw Panther (Area: Cape of Stranglethorn)
(@CGUID+1839, 15475, 0, 1, 1, -13017.25, 285.8956, 19.33146, 2.562799, 120, 0, 0), -- Beetle (Area: Cape of Stranglethorn)
(@CGUID+1840, 1713, 0, 1, 1, -12950.65, 231.1085, 17.91396, 3.786077, 120, 0, 0), -- Elder Shadowmaw Panther (Area: Cape of Stranglethorn)
(@CGUID+1841, 1713, 0, 1, 1, -12950.1, 282.5012, 18.11192, 4.991494, 120, 0, 0), -- Elder Shadowmaw Panther (Area: Cape of Stranglethorn)
(@CGUID+1842, 15475, 0, 1, 1, -13014.08, 319.5733, 16.52614, 3.308347, 120, 0, 0), -- Beetle (Area: Cape of Stranglethorn)
(@CGUID+1843, 15475, 0, 1, 1, -13015.08, 378.1419, 20.77228, 6.218696, 120, 0, 0), -- Beetle (Area: Cape of Stranglethorn)
(@CGUID+1844, 6827, 0, 1, 1, -13020.46, 485.4609, 4.798525, 0.8655584, 120, 0, 0), -- Crab (Area: Cape of Stranglethorn)
(@CGUID+1845, 6827, 0, 1, 1, -13062.66, 488.011, 4.76767, 3.837071, 120, 0, 0), -- Crab (Area: Southern Savage Coast)
(@CGUID+1846, 772, 0, 1, 1, -13051.36, 382.3053, 19.08081, 2.313151, 120, 0, 0), -- Stranglethorn Tigress (Area: Southern Savage Coast)
(@CGUID+1847, 1713, 0, 1, 1, -13004.68, 481.8576, 13.61993, 4.315194, 120, 0, 0), -- Elder Shadowmaw Panther (Area: Southern Savage Coast)
(@CGUID+1848, 1713, 0, 1, 1, -13017.79, 420.8105, 22.31144, 2.449103, 120, 0, 0), -- Elder Shadowmaw Panther (Area: Southern Savage Coast)
(@CGUID+1849, 49722, 0, 1, 1, -13104.03, 363.0967, 16.90981, 5.13755, 120, 0, 0), -- Tree Python (Area: Southern Savage Coast) (possible waypoints or random movement)
(@CGUID+1850, 49928, 0, 1, 1, -13075.34, 348.5319, 57.05969, 3.853289, 120, 0, 0), -- Crimson Moth (Area: Southern Savage Coast)
(@CGUID+1851, 1713, 0, 1, 1, -12983.44, 385.1892, 21.89128, 0.7149754, 120, 0, 0), -- Elder Shadowmaw Panther (Area: Southern Savage Coast)
(@CGUID+1852, 1713, 0, 1, 1, -13012.09, 344.3961, 19.77746, 2.70414, 120, 0, 0), -- Elder Shadowmaw Panther (Area: Gurubashi Arena)
(@CGUID+1853, 15475, 0, 1, 1, -13034.81, 236.0136, 22.74036, 0.7070711, 120, 0, 0), -- Beetle (Area: Gurubashi Arena)
(@CGUID+1854, 50479, 0, 1, 1, -13053.01, 236.2993, 23.62354, 6.248044, 120, 0, 0), -- Lizard Hatchling (Area: Gurubashi Arena)
(@CGUID+1855, 1713, 0, 1, 1, -13021.05, 282.618, 19.11732, 3.444746, 120, 0, 0), -- Elder Shadowmaw Panther (Area: Gurubashi Arena)
(@CGUID+1856, 1713, 0, 1, 1, -13011.06, 220.7765, 18.05913, 1.098415, 120, 0, 0), -- Elder Shadowmaw Panther (Area: Gurubashi Arena)
(@CGUID+1857, 49722, 0, 1, 1, -13077.63, 90.36217, 26.14073, 4.265017, 120, 0, 0), -- Tree Python (Area: Gurubashi Arena) (possible waypoints or random movement)
(@CGUID+1858, 15475, 0, 1, 1, -13073.38, 163.541, 22.82675, 3.141593, 120, 0, 0), -- Beetle (Area: Gurubashi Arena)
(@CGUID+1859, 15475, 0, 1, 1, -13058.72, 19.89848, 27.43843, 2.105925, 120, 0, 0), -- Beetle (Area: Gurubashi Arena)
(@CGUID+1860, 49928, 0, 1, 1, -13072.31, -178.5066, 62.45222, 0.819479, 120, 0, 0), -- Crimson Moth (Area: Cape of Stranglethorn)
(@CGUID+1861, 49722, 0, 1, 1, -13061.65, -273.5026, 21.87021, 1.517965, 120, 0, 0), -- Tree Python (Area: Cape of Stranglethorn) (possible waypoints or random movement)
(@CGUID+1862, 9600, 0, 1, 1, -13038.92, -236.3628, 41.44271, 1.338923, 120, 0, 0), -- Parrot (Area: Cape of Stranglethorn)
(@CGUID+1863, 1550, 0, 1, 1, -13062.76, -253.1291, 20.07798, 0.3327341, 120, 0, 0), -- Thrashtail Basilisk (Area: Cape of Stranglethorn)
(@CGUID+1864, 9600, 0, 1, 1, -13050.3, -257.4266, 45.5462, 5.399281, 120, 0, 0), -- Parrot (Area: Cape of Stranglethorn)
(@CGUID+1865, 674, 0, 1, 1, -13024.52, -414.5869, 42.71849, 3.560472, 120, 0, 0), -- Venture Co. Strip Miner (Area: Cape of Stranglethorn)
(@CGUID+1866, 676, 0, 1, 1, -13021.18, -403.2776, 37.10052, 5.107059, 120, 0, 0), -- Venture Co. Surveyor (Area: Cape of Stranglethorn)
(@CGUID+1867, 49928, 0, 1, 1, -13025.48, -371.0317, 54.15776, 5.500018, 120, 0, 0), -- Crimson Moth (Area: Cape of Stranglethorn)
(@CGUID+1868, 674, 0, 1, 1, -13090.46, -444.3494, 52.50059, 2.9147, 120, 0, 0), -- Venture Co. Strip Miner (Area: Cape of Stranglethorn)
(@CGUID+1869, 675, 0, 1, 1, -13080.38, -464.8216, 44.87788, 3.197369, 120, 0, 0), -- Venture Co. Foreman (Area: Cape of Stranglethorn)
(@CGUID+1870, 676, 0, 1, 1, -13074.14, -472.2815, 45.65767, 4.384456, 120, 0, 0), -- Venture Co. Surveyor (Area: Cape of Stranglethorn)
(@CGUID+1871, 675, 0, 1, 1, -13062.52, -446.3048, 45.60884, 0.7450845, 120, 0, 0), -- Venture Co. Foreman (Area: Cape of Stranglethorn)
(@CGUID+1872, 674, 0, 1, 1, -13033.42, -422.9454, 54.27542, 0.9424778, 120, 0, 0), -- Venture Co. Strip Miner (Area: Cape of Stranglethorn)
(@CGUID+1873, 44113, 0, 1, 1, -13154.37, -461.3802, 7.892246, 5.85847, 120, 0, 0), -- Ironjaw Behemoth (Area: Cape of Stranglethorn)
(@CGUID+1874, 674, 0, 1, 1, -13087.15, -478.0323, 51.2409, 4.485496, 120, 0, 0), -- Venture Co. Strip Miner (Area: 0)
(@CGUID+1875, 782, 0, 1, 1, -13023.27, -621.3054, 53.8809, 0.0755533, 120, 0, 0), -- Skullsplitter Scout (Area: 0) (possible waypoints or random movement)
(@CGUID+1876, 783, 0, 1, 1, -13049.38, -624.3073, 55.34595, 5.637414, 120, 0, 0), -- Skullsplitter Berserker (Area: 0)
(@CGUID+1877, 2530, 0, 1, 1, -13076.64, -604.1702, 54.55101, 4.502949, 120, 0, 0), -- Yenniku (Area: 0)
(@CGUID+1878, 1059, 0, 1, 1, -13077.29, -607.8143, 54.30071, 1.343904, 120, 0, 0), -- Ana'thek the Cruel (Area: 0)
(@CGUID+1879, 672, 0, 1, 1, -13055.78, -631.1684, 54.71883, 5.637414, 120, 0, 0), -- Skullsplitter Spiritchaser (Area: 0)
(@CGUID+1880, 782, 0, 1, 1, -13052.38, -649.08, 53.29412, 2.696958, 120, 0, 0), -- Skullsplitter Scout (Area: 0) (possible waypoints or random movement)
(@CGUID+1881, 15475, 0, 1, 1, -13014.34, -710.7127, 56.90996, 3.200924, 120, 0, 0), -- Beetle (Area: Ruins of Zul'Mamwe)
(@CGUID+1882, 783, 0, 1, 1, -13070.23, -722.4362, 83.99643, 2.995432, 120, 0, 0), -- Skullsplitter Berserker (Area: Ruins of Zul'Mamwe) (possible waypoints or random movement)
(@CGUID+1883, 672, 0, 1, 1, -13073.05, -745.872, 87.65163, 2.240999, 120, 0, 0), -- Skullsplitter Spiritchaser (Area: Ruins of Zul'Mamwe) (possible waypoints or random movement)
(@CGUID+1884, 781, 0, 1, 1, -13039.8, -793.6519, 71.97134, 4.369286, 120, 0, 0), -- Skullsplitter Headhunter (Area: Ruins of Zul'Mamwe) (possible waypoints or random movement)
(@CGUID+1885, 672, 0, 1, 1, -13005.75, -821.5157, 70.90391, 1.40315, 120, 0, 0), -- Skullsplitter Spiritchaser (Area: Ruins of Zul'Mamwe) (possible waypoints or random movement)
(@CGUID+1886, 783, 0, 1, 1, -13030.31, -813.7814, 71.04307, 3.028151, 120, 0, 0), -- Skullsplitter Berserker (Area: Ruins of Zul'Mamwe) (possible waypoints or random movement)
(@CGUID+1887, 672, 0, 1, 1, -13008.02, -845.5391, 71.46258, 2.707473, 120, 0, 0), -- Skullsplitter Spiritchaser (Area: Ruins of Zul'Mamwe) (possible waypoints or random movement)
(@CGUID+1888, 781, 0, 1, 1, -13027.46, -834.7601, 71.55486, 4.843737, 120, 0, 0), -- Skullsplitter Headhunter (Area: Ruins of Zul'Mamwe) (possible waypoints or random movement)
(@CGUID+1889, 672, 0, 1, 1, -13054.1, -808.7556, 71.21812, 5.216352, 120, 0, 0), -- Skullsplitter Spiritchaser (Area: Ruins of Zul'Mamwe) (possible waypoints or random movement)
(@CGUID+1890, 783, 0, 1, 1, -13053.74, -820.6458, 70.42679, 5.794493, 120, 0, 0), -- Skullsplitter Berserker (Area: Ruins of Zul'Mamwe)
(@CGUID+1891, 42858, 0, 1, 1, -13054.2, -846.7532, 71.34388, 3.175288, 120, 0, 0), -- Braddok (Area: Ruins of Zul'Mamwe) (possible waypoints or random movement)
(@CGUID+1892, 672, 0, 1, 1, -13085.9, -769.8326, 79.82485, 1.300689, 120, 0, 0), -- Skullsplitter Spiritchaser (Area: Ruins of Zul'Mamwe)
(@CGUID+1893, 44113, 0, 1, 1, -13221.11, -594.5061, 4.642443, 0.5475293, 120, 0, 0), -- Ironjaw Behemoth (Area: Ruins of Zul'Mamwe)
(@CGUID+1894, 48972, 0, 1, 1, -13119.3, -550.8907, 10.09314, 1.801211, 120, 0, 0), -- Long-tailed Mole (Area: Ruins of Zul'Mamwe)
(@CGUID+1895, 1551, 0, 1, 1, -13132.98, -562.9617, 8.449101, 6.278608, 120, 0, 0), -- Ironjaw Basilisk (Area: Ruins of Zul'Mamwe)
(@CGUID+1896, 44113, 0, 1, 1, -13209.22, -500.5413, 4.217281, 3.426952, 120, 0, 0); -- Ironjaw Behemoth (Area: Ruins of Zul'Mamwe)

DELETE FROM `npc_vendor` WHERE `entry` IN (734, 734, 734, 734, 734, 734, 734, 734, 734, 734, 734, 734, 734, 734, 734, 734, 734, 734, 734, 2483, 2483, 2483, 2483, 2483, 8679, 8679, 8679, 8679, 8679, 8679, 8679, 8679, 8679, 8679, 8679, 8679, 8679, 8679, 8679, 8679, 2687, 2687, 2687, 2687, 2687, 2687, 2687, 2687, 2687, 2687, 2687, 2687, 2687, 2687, 44181, 44181, 44181, 44181, 44181, 44181, 44019, 44019, 44019, 44019, 44019, 44019, 44019, 44019, 44019);
INSERT INTO `npc_vendor` (`entry`, `item`, `slot`, `maxcount`, `ExtendedCost`, `Type`) VALUES
-- 734 (Corporal Bluth)
(734, 159, 1, 0, 0, 1), -- Refreshing Spring Water
(734, 1179, 2, 0, 0, 1), -- Ice Cold Milk
(734, 1205, 3, 0, 0, 1), -- Melon Juice
(734, 1708, 4, 0, 0, 1), -- Sweet Nectar
(734, 1645, 5, 0, 0, 1), -- Moonberry Juice
(734, 8766, 6, 0, 0, 1), -- Morning Glory Dew
(734, 4536, 7, 0, 0, 1), -- Shiny Red Apple
(734, 4537, 8, 0, 0, 1), -- Tel'Abim Banana
(734, 4538, 9, 0, 0, 1), -- Snapvine Watermelon
(734, 4539, 10, 0, 0, 1), -- Goldenbark Apple
(734, 4602, 11, 0, 0, 1), -- Moon Harvest Pumpkin
(734, 8953, 12, 0, 0, 1), -- Deep Fried Plantains
(734, 4542, 13, 0, 0, 1), -- Moist Cornbread
(734, 4601, 14, 0, 0, 1), -- Soft Banana Bread
(734, 4497, 15, 0, 0, 1), -- Heavy Brown Bag
(734, 4499, 16, 0, 0, 1), -- Huge Brown Sack
(734, 4470, 17, 0, 0, 1), -- Simple Wood
(734, 12228, 18, 0, 0, 1), -- Recipe: Roast Raptor
(734, 12231, 19, 0, 0, 1), -- Recipe: Jungle Stew
-- 2483 (Jaquilina Dramet)
(2483, 2522, 1, 0, 0, 1), -- Crescent Axe
(2483, 2530, 2, 0, 0, 1), -- Francisca
(2483, 2523, 3, 0, 0, 1), -- Bullova
(2483, 2531, 4, 0, 0, 1), -- Great Axe
(2483, 25876, 5, 0, 0, 1), -- Gleaming Throwing Axe
-- 8679 (Knaz Blunderflame)
(8679, 5956, 1649, 0, 0, 1), -- Blacksmith Hammer
(8679, 2901, 1650, 0, 0, 1), -- Mining Pick
(8679, 4399, 1651, 0, 0, 1), -- Wooden Stock
(8679, 4400, 1652, 0, 0, 1), -- Heavy Stock
(8679, 40533, 1653, 0, 0, 1), -- Walnut Stock
(8679, 39684, 1654, 0, 0, 1), -- Hair Trigger
(8679, 2880, 1655, 0, 0, 1), -- Weak Flux
(8679, 3466, 1656, 0, 0, 1), -- Strong Flux
(8679, 10648, 1657, 0, 0, 1), -- Common Parchment
(8679, 10647, 1658, 0, 0, 1), -- Engineer's Ink
(8679, 4389, 1659, 1, 0, 1), -- Gyrochronatom
(8679, 4361, 1660, 1, 0, 1), -- Bent Copper Tube
(8679, 10602, 1666, 1, 0, 1), -- Schematic: Deadly Scope
(8679, 4371, 1661, 1, 0, 1), -- Bronze Tube
(8679, 4357, 1662, 3, 0, 1), -- Rough Blasting Powder
(8679, 4364, 1663, 2, 0, 1), -- Coarse Blasting Powder
-- 2687 (Gnaz Blunderflame)
(2687, 5956, 1637, 0, 0, 1), -- Blacksmith Hammer
(2687, 2901, 1638, 0, 0, 1), -- Mining Pick
(2687, 4399, 1639, 0, 0, 1), -- Wooden Stock
(2687, 4400, 1640, 0, 0, 1), -- Heavy Stock
(2687, 40533, 1641, 0, 0, 1), -- Walnut Stock
(2687, 39684, 1642, 0, 0, 1), -- Hair Trigger
(2687, 2880, 1643, 0, 0, 1), -- Weak Flux
(2687, 3466, 1644, 0, 0, 1), -- Strong Flux
(2687, 10648, 1645, 0, 0, 1), -- Common Parchment
(2687, 10647, 1646, 0, 0, 1), -- Engineer's Ink
(2687, 4361, 1647, 1, 0, 1), -- Bent Copper Tube
(2687, 4357, 1648, 3, 0, 1), -- Rough Blasting Powder
(2687, 13311, 1650, 1, 0, 1), -- Schematic: Mechanical Dragonling
(2687, 4364, 1649, 3, 0, 1), -- Coarse Blasting Powder
-- 44181 (Daniel Roberts)
(44181, 2901, 1, 0, 0, 1), -- Mining Pick
(44181, 5956, 2, 0, 0, 1), -- Blacksmith Hammer
(44181, 2880, 3, 0, 0, 1), -- Weak Flux
(44181, 3466, 4, 0, 0, 1), -- Strong Flux
(44181, 18567, 5, 0, 0, 1), -- Elemental Flux
(44181, 3857, 6, 0, 0, 1), -- Coal
-- 44019 (Livingston Marshal)
(44019, 159, 1, 0, 0, 1), -- Refreshing Spring Water
(44019, 1205, 2, 0, 0, 1), -- Melon Juice
(44019, 1708, 3, 0, 0, 1), -- Sweet Nectar
(44019, 1645, 4, 0, 0, 1), -- Moonberry Juice
(44019, 4542, 5, 0, 0, 1), -- Moist Cornbread
(44019, 4601, 6, 0, 0, 1), -- Soft Banana Bread
(44019, 4497, 7, 0, 0, 1), -- Heavy Brown Bag
(44019, 4499, 8, 0, 0, 1), -- Huge Brown Sack
(44019, 4470, 9, 0, 0, 1); -- Simple Wood

DELETE FROM `npc_text` WHERE `ID` IN (17881, 16536, 16527, 16304, 16537);
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `lang0`, `prob0`, `em0_0`, `em0_1`, `em0_2`, `em0_3`, `em0_4`, `em0_5`, `text1_0`, `text1_1`, `lang1`, `prob1`, `em1_0`, `em1_1`, `em1_2`, `em1_3`, `em1_4`, `em1_5`, `text2_0`, `text2_1`, `lang2`, `prob2`, `em2_0`, `em2_1`, `em2_2`, `em2_3`, `em2_4`, `em2_5`, `text3_0`, `text3_1`, `lang3`, `prob3`, `em3_0`, `em3_1`, `em3_2`, `em3_3`, `em3_4`, `em3_5`, `text4_0`, `text4_1`, `lang4`, `prob4`, `em4_0`, `em4_1`, `em4_2`, `em4_3`, `em4_4`, `em4_5`, `text5_0`, `text5_1`, `lang5`, `prob5`, `em5_0`, `em5_1`, `em5_2`, `em5_3`, `em5_4`, `em5_5`, `text6_0`, `text6_1`, `lang6`, `prob6`, `em6_0`, `em6_1`, `em6_2`, `em6_3`, `em6_4`, `em6_5`, `text7_0`, `text7_1`, `lang7`, `prob7`, `em7_0`, `em7_1`, `em7_2`, `em7_3`, `em7_4`, `em7_5`, `WDBVerified`) VALUES
(17881, 'This teleporter will transport you to the irradiated ruins of Gnomeregan, deep beneath Dun Morogh.$B$BDon''t worry, there''s another one there that''ll send you back here... well, if it doesn''t turn you inside-out or transmogrify your organs into unstable organic explosives, that is!$B$BWell? What are you waiting for? Hop on in!', '', 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- 17881
(16536, 'Yes, $N?', '', 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- 16536
(16527, 'The great Rastakhan sends his greetings to you, member of the Alliance.', '', 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- 16527
(16304, '', 'Priestess knows much about Zul''Gurub.$b$bPriestess thinks you need her help.', 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- 16304
(16537, 'The Explorers'' League exists to uncover the hidden secrets within this world.  While the cataclysm was devastating for most, for us, it provided access to untold troves of information and wealth.', '', 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 15595); -- 16537

UPDATE `npc_text` SET `em0_0`=1, `em0_1`=0, `WDBVerified`=15595 WHERE `ID`=9218; -- 9218

DELETE FROM `gossip_menu_option` WHERE (`menu_id`=11791 AND `id`=0);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `box_coded`, `box_money`, `box_text`) VALUES
(11791, 0, 2, 'Show me where I can fly.', 0, 0, ''); -- Robert Rhodes

DELETE FROM `creature_equip_template` WHERE `entry` IN (671, 597, 699, 671, 588, 701, 671, 588, 588, 1061, 595, 595, 588, 701, 588, 701, 1062, 595, 588, 699, 701, 588, 595, 701, 595, 701, 701, 1094, 699, 701, 588, 701, 701, 588, 588, 701, 588, 701, 595, 1094, 1097, 1094, 1094, 1094, 1094, 1094, 1096, 1094, 1094, 1094, 1094, 1096, 1422, 469, 739, 733, 754, 300, 212, 889, 940, 940, 940, 937, 940, 940, 940, 937, 937, 940, 937, 937, 938, 943, 941, 938, 940, 943, 943, 941, 939, 943, 940, 940, 938, 938, 941, 942, 939, 942, 942, 939, 938, 938, 941, 43911, 939, 942, 938, 43910, 941, 939, 939, 939, 942, 942, 942, 978, 978, 978, 979, 978, 43913, 979, 978, 43912, 978, 979, 940, 940, 937, 940, 940, 937, 43049, 43049, 701, 588, 588, 597, 597, 671, 671, 660, 660, 660, 597, 671, 660, 597, 660, 671, 597, 671, 660, 597, 701, 699, 701, 701, 701, 701, 701, 588, 588, 597, 597, 701, 595, 701, 588, 588, 701, 595, 588, 588, 701, 701, 595, 701, 595, 595, 701, 701, 701, 701, 595, 588, 701, 595, 588, 588, 595, 595, 595, 588, 699, 595, 588, 699, 702, 702, 43049, 43049, 2483, 715, 43049, 43049, 940, 940, 940, 937, 937, 937, 940, 937, 940, 940, 702, 702, 702, 701, 660, 597, 701, 671, 595, 701, 699, 595, 702, 702, 702, 702, 702, 702, 937, 940, 940, 937, 937, 660, 660, 597, 597, 660, 660, 660, 702, 702, 702, 702, 702, 937, 937, 1096, 940, 702, 702, 702, 702, 1096, 1096, 1096, 1096, 1096, 1096, 702, 702, 4461, 702, 697, 697, 587, 587, 4457, 1096, 1096, 1096, 1096, 921, 4723, 1096, 1096, 1096, 921, 1097, 1096, 1097, 1096, 1097, 4458, 4461, 4461, 587, 587, 694, 697, 587, 587, 694, 694, 694, 4457, 4457, 1096, 1096, 11383, 1096, 1096, 1096, 1096, 1095, 1097, 4457, 4461, 587, 694, 697, 877, 697, 4458, 4461, 4458, 4458, 4458, 4457, 4461, 4461, 1096, 1096, 1096, 1096, 1096, 1096, 1096, 1096, 42812, 42811, 7802, 44187, 44186, 42813, 42814, 1096, 1096, 4458, 879, 871, 873, 879, 873, 877, 871, 879, 873, 873, 873, 879, 879, 873, 879, 877, 879, 877, 4458, 4460, 4458, 4460, 4460, 4458, 4461, 4461, 4461, 4461, 4458, 4457, 1096, 1096, 1096, 1096, 1096, 1096, 2519, 709, 1096, 51521, 1096, 871, 877, 879, 879, 877, 877, 871, 877, 680, 818, 679, 678, 678, 679, 678, 679, 679, 679, 679, 709, 709, 709, 709, 877, 877, 877, 871, 1064, 1064, 1064, 1064, 1382, 1146, 678, 679, 678, 818, 710, 709, 709, 14487, 1064, 1064, 877, 871, 877, 879, 871, 871, 879, 879, 871, 877, 7853, 1404, 1064, 1064, 3624, 1064, 1064, 2497, 17094, 12137, 1064, 2464, 1064, 2465, 7485, 1064, 1064, 1064, 1144, 1142, 1144, 709, 709, 709, 710, 679, 710, 709, 667, 1142, 1142, 1142, 1142, 1142, 1144, 1142, 1144, 1144, 1144, 1144, 1144, 1142, 1387, 16096, 16096, 16094, 16096, 3149, 5814, 51917, 871, 877, 877, 24924, 24930, 24929, 24931, 24926, 25081, 24927, 25080, 1142, 1144, 1142, 1142, 1144, 1144, 696, 696, 696, 696, 780, 780, 709, 709, 709, 709, 678, 678, 680, 680, 780, 696, 696, 667, 696, 696, 667, 24930, 24924, 24926, 25080, 25081, 24927, 24931, 24929, 7871, 780, 696, 780, 780, 2687, 8679, 696, 696, 696, 696, 696, 780, 667, 667, 667, 780, 696, 696, 780, 669, 782, 669, 669, 669, 670, 669, 670, 670, 670, 782, 782, 669, 670, 782, 44018, 44017, 44021, 44181, 674, 677, 674, 669, 669, 669, 782, 782, 670, 669, 669, 670, 782, 669, 674, 674, 669, 784, 784, 670, 670, 782, 669, 782, 669, 669, 669, 670, 782, 784, 669, 781, 782, 672, 670, 781, 669, 782, 782, 669, 669, 669, 669, 674, 675, 674, 674, 676, 674, 675, 676, 675, 674, 674, 782, 783, 2530, 1059, 672, 782, 783, 672, 781, 672, 783, 672, 781, 672, 783, 42858, 672);
INSERT INTO `creature_equip_template` (`entry`, `itemEntry1`, `itemEntry2`, `itemEntry3`) VALUES
(671, 2183, 0, 5870), -- Bloodscalp Headhunter
(597, 5289, 0, 0), -- Bloodscalp Berserker
(699, 1909, 0, 5260), -- Bloodscalp Beastmaster
(588, 2184, 0, 0), -- Bloodscalp Scout
(701, 1908, 0, 0), -- Bloodscalp Mystic
(1061, 2183, 2183, 0), -- Gan'zulah
(595, 2711, 0, 5870), -- Bloodscalp Hunter
(1062, 2176, 0, 0), -- Nezzliok the Dire
(1094, 1910, 0, 0), -- Venture Co. Miner
(1097, 1911, 0, 2552), -- Venture Co. Mechanic
(1096, 2813, 0, 0), -- Venture Co. Geologist
(1422, 3361, 0, 0), -- Corporal Sethman
(469, 2180, 1896, 0), -- Lieutenant Doren
(739, 12742, 0, 0), -- Brother Nimetz
(733, 1899, 1984, 0), -- Sergeant Yohwa
(754, 1906, 1985, 2552), -- Rebel Watchman
(300, 49657, 0, 0), -- Zzarc' Vul
(212, 5286, 0, 0), -- Splinter Fist Warrior
(889, 2695, 0, 0), -- Splinter Fist Ogre
(940, 1908, 0, 0), -- Kurzen Medicine Man
(937, 1899, 2052, 0), -- Kurzen Jungle Fighter
(938, 5281, 0, 0), -- Kurzen Commando
(943, 2023, 0, 0), -- Kurzen Wrangler
(941, 1908, 0, 0), -- Kurzen Headshrinker
(939, 1983, 0, 0), -- Kurzen Elite
(942, 1908, 0, 0), -- Kurzen Witch Doctor
(43911, 12786, 0, 0), -- Chief Gaulus
(43910, 57037, 57037, 0), -- Chief Anders
(978, 1909, 0, 0), -- Kurzen Subchief
(979, 2177, 0, 5259), -- Kurzen Shadow Hunter
(43913, 56565, 0, 0), -- Chief Miranda
(43912, 33172, 0, 0), -- Chief Esquivel
(43049, 3361, 0, 2552), -- Nesingwary Hired Gun
(660, 1908, 0, 0), -- Bloodscalp Witch Doctor
(702, 2184, 0, 0), -- Bloodscalp Scavenger
(2483, 5287, 0, 0), -- Jaquilina Dramet
(715, 0, 0, 2552), -- Hemet Nesingwary Jr.
(4461, 2023, 0, 0), -- Murkgill Warrior
(697, 1908, 0, 0), -- Bloodscalp Shaman
(587, 1901, 1985, 0), -- Bloodscalp Warrior
(4457, 2200, 0, 0), -- Murkgill Forager
(921, 1905, 0, 0), -- Venture Co. Lumberjack
(4723, 3361, 0, 0), -- Foreman Cozzle
(4458, 2023, 0, 5870), -- Murkgill Hunter
(694, 1904, 0, 5856), -- Bloodscalp Axe Thrower
(11383, 13720, 0, 0), -- High Priestess Hai'watna
(1095, 1897, 0, 0), -- Venture Co. Workboss
(877, 2200, 0, 0), -- Saltscale Forager
(42812, 57036, 0, 0), -- Priestess Hu'rala
(42811, 56911, 0, 0), -- Surkhan
(7802, 2182, 0, 0), -- Galvan the Ancient
(44187, 3696, 0, 0), -- Pechanga
(44186, 1906, 0, 0), -- Morango
(42813, 57006, 33789, 0), -- Kil'karil
(42814, 6219, 0, 0), -- Skeezy Whillzap
(879, 2023, 0, 5870), -- Saltscale Hunter
(871, 2023, 0, 37130), -- Saltscale Warrior
(873, 1908, 0, 0), -- Saltscale Oracle
(4460, 2023, 0, 0), -- Murkgill Lord
(2519, 1908, 0, 0), -- Kin'weelay
(709, 1909, 0, 0), -- Mosh'Ogg Warmonger
(51521, 60822, 60822, 34267), -- Bambala Headhunter
(680, 5287, 0, 0), -- Mosh'Ogg Lord
(818, 2177, 0, 0), -- Mai'Zoth
(679, 1908, 0, 0), -- Mosh'Ogg Shaman
(678, 5288, 0, 0), -- Mosh'Ogg Mauler
(1064, 1905, 1984, 2507), -- Grom'gol Grunt
(1382, 3351, 0, 0), -- Mudduk
(1146, 1909, 0, 0), -- Vharr
(710, 1908, 0, 0), -- Mosh'Ogg Spellcrafter
(14487, 12332, 0, 0), -- Gluggle
(7853, 1911, 0, 0), -- Scooty
(1404, 0, 0, 2550), -- Kragg
(3624, 6680, 0, 0), -- Zudd
(2497, 3433, 0, 0), -- Nimboya
(17094, 0, 0, 21550), -- Nemeth Hawkeye
(12137, 4994, 0, 0), -- Squibby Overspeck
(2464, 2183, 1905, 0), -- Commander Aggro'gosh
(2465, 5303, 0, 0), -- Far Seer Mok'thardin
(7485, 2202, 0, 0), -- Nargatt
(1144, 1908, 0, 0), -- Mosh'Ogg Witch Doctor
(1142, 5300, 0, 0), -- Mosh'Ogg Brute
(667, 1901, 1985, 0), -- Skullsplitter Warrior
(1387, 3433, 0, 0), -- Thysta
(16096, 3361, 11586, 2552), -- Steamwheedle Bruiser
(16094, 5491, 0, 0), -- Durik
(3149, 2714, 0, 0), -- Nez'raz
(5814, 2703, 0, 0), -- Innkeeper Thulbek
(51917, 1905, 1984, 2507), -- Grom'gol Grunt
(24924, 3364, 0, 0), -- Sky-Captain Bomblast
(24930, 31824, 0, 0), -- Crewman Gazzlegear
(24929, 31824, 0, 0), -- Crewman Crosswire
(24931, 1911, 0, 0), -- Crewman Fastwrench
(24926, 1897, 0, 0), -- Chief Officer Brassbolt
(25081, 5289, 0, 5258), -- Grunt Ounda
(24927, 2716, 0, 0), -- Navigator Sparksizzle
(25080, 5289, 0, 5258), -- Grunt Umgor
(696, 1905, 0, 5856), -- Skullsplitter Axe Thrower
(780, 1908, 0, 0), -- Skullsplitter Mystic
(7871, 3433, 0, 0), -- Se'Jib
(2687, 4994, 0, 0), -- Gnaz Blunderflame
(8679, 4994, 0, 0), -- Knaz Blunderflame
(669, 2711, 0, 0), -- Skullsplitter Hunter
(782, 2184, 0, 0), -- Skullsplitter Scout
(670, 1908, 0, 0), -- Skullsplitter Witch Doctor
(44018, 2715, 0, 0), -- Wulfred Harrys
(44017, 5291, 0, 0), -- Priestess Thaalia
(44021, 56911, 0, 0), -- Ghaliri
(44181, 1903, 0, 0), -- Daniel Roberts
(674, 1910, 0, 0), -- Venture Co. Strip Miner
(677, 1911, 0, 0), -- Venture Co. Tinkerer
(784, 1909, 0, 5260), -- Skullsplitter Beastmaster
(781, 2183, 0, 5870), -- Skullsplitter Headhunter
(672, 1908, 0, 0), -- Skullsplitter Spiritchaser
(675, 1906, 0, 0), -- Venture Co. Foreman
(676, 2809, 0, 0), -- Venture Co. Surveyor
(783, 5289, 0, 0), -- Skullsplitter Berserker
(2530, 2183, 0, 0), -- Yenniku
(1059, 5301, 0, 0), -- Ana'thek the Cruel
(42858, 35743, 0, 0); -- Braddok

SET @OGUID := 1161;

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+91;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0, 2042, 0, 1, 1, -12995.9, 213.014, 18.6405, 0, 0, 0, 0, 1, 120, 255, 1), -- Fadeleaf (Area: Gurubashi Arena)
-- (@OGUID+1, 176495, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 120, 255, 1), -- 0 (Area: Gurubashi Arena) - !!! transport !!!
-- (@OGUID+1, 20808, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 120, 255, 1), -- 0 (Area: Gurubashi Arena) - !!! transport !!!
(@OGUID+1, 204828, 0, 1, 1, -11571.15, -568.7274, 33.68356, 3.211419, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Gurubashi Arena)
(@OGUID+2, 143979, 0, 1, 1, -11600.36, -698.984, 30.97299, 0.01745246, 0, 0, 0.008726574, 0.9999619, 120, 255, 1), -- Cage Door (Area: Gurubashi Arena)
(@OGUID+3, 180497, 0, 1, 1, -11505.66, -1609.016, 47.6743, 1.579522, 0, 0, 0.7101853, 0.7040148, 120, 255, 0), -- Forcefield (Area: Gurubashi Arena)
(@OGUID+4, 177253, 0, 1, 1, -11097.23, -1506.311, 27.99158, 1.596976, 0, 0, 0.01308961, 0.9999143, 120, 255, 1), -- Doodad_WroughtIronDoor09 (Area: Gurubashi Arena)
(@OGUID+5, 177252, 0, 1, 1, -11096.34, -1540.468, 27.99158, 1.596976, 0, 0, 0.01308961, 0.9999143, 120, 255, 1), -- Doodad_WroughtIronDoor08 (Area: Gurubashi Arena)
(@OGUID+6, 177254, 0, 1, 1, -11065.52, -1505.48, 27.99158, 1.596976, 0, 0, 0.01308961, 0.9999143, 120, 255, 1), -- Doodad_opendoor_01 (Area: Gurubashi Arena)
(@OGUID+7, 177250, 0, 1, 1, -11064.62, -1539.476, 27.97834, 1.596976, 0, 0, 0.01308961, 0.9999143, 120, 255, 1), -- Doodad_WroughtIronDoor06 (Area: Gurubashi Arena)
(@OGUID+8, 177255, 0, 1, 1, -11033.78, -1504.649, 27.99158, 1.596976, 0, 0, 0.01308961, 0.9999143, 120, 255, 1), -- Doodad_opendoor_03 (Area: Gurubashi Arena)
(@OGUID+9, 177049, 0, 1, 1, -11226.9, -1734.259, 4.382416, 1.596976, 0, 0, 0.01308961, 0.9999143, 120, 255, 1), -- Doodad_PortcullisActive07 (Area: Gurubashi Arena)
(@OGUID+10, 177251, 0, 1, 1, -11094.74, -1601.537, 27.99158, 1.596976, 0, 0, 0.01308961, 0.9999143, 120, 255, 1), -- Doodad_WroughtIronDoor07 (Area: Gurubashi Arena)
(@OGUID+11, 177256, 0, 1, 1, -11032.87, -1539.138, 29.45629, 1.596976, 0, 0, 0.01308961, 0.9999143, 120, 255, 1), -- Doodad_opendoor_02 (Area: Gurubashi Arena)
(@OGUID+12, 177047, 0, 1, 1, -11206.93, -1733.736, 4.382416, 1.596976, 0, 0, 0.01308961, 0.9999143, 120, 255, 1), -- Doodad_PortcullisActive05 (Area: Gurubashi Arena)
(@OGUID+13, 177048, 0, 1, 1, -11226.34, -1755.594, 4.382416, 1.596976, 0, 0, 0.01308961, 0.9999143, 120, 255, 1), -- Doodad_PortcullisActive06 (Area: Gurubashi Arena)
(@OGUID+14, 177249, 0, 1, 1, -11063.01, -1600.994, 27.97834, 1.596976, 0, 0, 0.01308961, 0.9999143, 120, 255, 1), -- Doodad_WroughtIronDoor05 (Area: Gurubashi Arena)
(@OGUID+15, 177246, 0, 1, 1, -11093.86, -1635.39, 27.97834, 1.596976, 0, 0, 0.01308961, 0.9999143, 120, 255, 1), -- Doodad_WroughtIronDoor02 (Area: Gurubashi Arena)
(@OGUID+16, 176901, 0, 1, 1, -11206.37, -1755.071, 4.382416, 1.596976, 0, 0, 0.01308961, 0.9999143, 120, 255, 1), -- Doodad_PortcullisActive02 (Area: Gurubashi Arena)
(@OGUID+17, 177248, 0, 1, 1, -11031.28, -1600.163, 27.97834, 1.596976, 0, 0, 0.01308961, 0.9999143, 120, 255, 1), -- Doodad_WroughtIronDoor04 (Area: Gurubashi Arena)
(@OGUID+18, 177245, 0, 1, 1, -11062.1, -1635.611, 27.99158, 1.596976, 0, 0, 0.01308961, 0.9999143, 120, 255, 1), -- Doodad_WroughtIronDoor01 (Area: Gurubashi Arena)
(@OGUID+19, 177247, 0, 1, 1, -11030.4, -1633.728, 27.97834, 1.596976, 0, 0, 0.01308961, 0.9999143, 120, 255, 1), -- Doodad_WroughtIronDoor03 (Area: Gurubashi Arena)
(@OGUID+20, 177203, 0, 1, 1, -11067.97, -1824.712, 60.19905, 1.596976, 0, 0, 0.01308961, 0.9999143, 120, 255, 1), -- Gate (Area: Gurubashi Arena)
(@OGUID+21, 207208, 0, 1, 1, -11080.01, -1929.494, 90.90231, 1.80453, 0, 0, 0.9006982, 0.4344453, 120, 255, 1), -- -Unknown- (Area: Gurubashi Arena)
(@OGUID+22, 176633, 0, 1, 1, -11105.65, -1966.78, 90.90231, 3.351047, 0, 0, 0.9006982, 0.4344453, 120, 255, 1), -- Door (Area: Gurubashi Arena)
(@OGUID+23, 176578, 0, 1, 1, -11098.14, -1990.838, 49.49687, 3.813545, 0, 0, 0.9006982, 0.4344453, 120, 255, 1), -- Door (Area: Gurubashi Arena)
(@OGUID+24, 184164, 0, 1, 1, -11111.03, -2004.483, 49.3827, 3.813545, 0, 0, 0.9006982, 0.4344453, 120, 255, 0), -- Karazhan Gatehouse Portcullis (Area: Gurubashi Arena)
(@OGUID+25, 176577, 0, 1, 1, -11066.05, -1988.069, 231.5188, 2.591811, 0, 0, 0.9006982, 0.4344453, 120, 255, 1), -- Gate (Area: Gurubashi Arena)
(@OGUID+26, 176579, 0, 1, 1, -11070.7, -2001.422, 114.8234, 4.677484, 0, 0, 0.9006982, 0.4344453, 120, 255, 1), -- Door (Area: Gurubashi Arena)
(@OGUID+27, 176580, 0, 1, 1, -11033.63, -1986.337, 126.0721, 4.223697, 0, 0, 0.9006982, 0.4344453, 120, 255, 1), -- Door (Area: Gurubashi Arena)
(@OGUID+28, 176694, 0, 1, 1, -11037.91, -1999.855, 92.9915, 2.242746, 0, 0, 0.9006982, 0.4344453, 120, 255, 1), -- Karazhan Side Entrance (Area: Gurubashi Arena)
(@OGUID+29, 201517, 0, 1, 1, -8765.823, 403.1644, 104.1621, 5.384343, 0, 0, 0.944089, -0.3296907, 120, 255, 0), -- -Unknown- (Area: Gurubashi Arena)
(@OGUID+30, 37118, 0, 1, 1, -9896.839, -3723.431, 21.91474, 2.286379, 0, 0, 0, 1, 120, 255, 1), -- Galen's Cage (Area: Gurubashi Arena)
(@OGUID+31, 204582, 0, 1, 1, -9282.32, -3327.47, 112.287, 6.19592, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Gurubashi Arena)
(@OGUID+32, 202831, 0, 1, 1, -7427.796, -1169.742, 478.2133, 0.3503397, 0, 0, -0.5730546, 0.8195173, 120, 255, 1), -- -Unknown- (Area: Gurubashi Arena)
(@OGUID+33, 149045, 0, 1, 1, -6904.813, -1206.778, 178.5117, 2.984498, 0, 0, 1, -4.371139E-08, 120, 255, 24), -- 0 (Area: Gurubashi Arena)
(@OGUID+34, 149046, 0, 1, 1, -6900.42, -1339.326, 239.652, 3.394674, 0, 0, 1, -4.371139E-08, 120, 255, 24), -- 0 (Area: Gurubashi Arena)
(@OGUID+35, 161536, 0, 1, 1, -6756.729, -1166.696, 187.0422, 1.317723, 0, 0, 0.9969173, -0.07845917, 120, 255, 1), -- Quarry Gate (Area: Gurubashi Arena)
(@OGUID+36, 203402, 0, 1, 1, -7208.941, 3910.72, -2.248372, 4.756022, 1.261169E-43, 0, 0, 0, 120, 255, 1), -- -Unknown- (Area: Gurubashi Arena)
(@OGUID+37, 203400, 0, 1, 1, -7259.479, 4101.91, -1.733832, 5.445428, 1.233143E-43, 0, 0, 0, 120, 255, 1), -- -Unknown- (Area: Gurubashi Arena)
(@OGUID+38, 203401, 0, 1, 1, -7147.46, 4035.37, -1.931532, 5.096362, 1.247156E-43, 0, 0, 0, 120, 255, 1), -- -Unknown- (Area: Gurubashi Arena)
(@OGUID+39, 203399, 0, 1, 1, -6951.91, 4135.649, -2.532064, 0.1832588, 1.21913E-43, 0, 0, 0, 120, 255, 1), -- -Unknown- (Area: Gurubashi Arena)
(@OGUID+40, 203397, 0, 1, 1, -7032.8, 4313.391, -2.122287, 0.6195911, 1.008935E-43, 0, 0, 0, 120, 255, 1), -- -Unknown- (Area: Gurubashi Arena)
(@OGUID+41, 203398, 0, 1, 1, -6895.021, 4267.181, -2.49859, 0.6195931, 1.205117E-43, 0, 0, 0, 120, 255, 1), -- -Unknown- (Area: Gurubashi Arena)
(@OGUID+42, 204850, 0, 1, 1, -6612.319, 4228.612, -483.4876, 1.78482, 0, 0, 0.9885786, 0.1507064, 120, 255, 1), -- -Unknown- (Area: Gurubashi Arena)
(@OGUID+43, 204851, 0, 1, 1, -6544.712, 4244.213, -489.2864, 1.325501, 0, 0, 0.9885786, 0.1507064, 120, 255, 1), -- -Unknown- (Area: Gurubashi Arena)
(@OGUID+44, 204848, 0, 1, 1, -6327.528, 4167.719, -489.2864, 0.8854322, 0, 0, 0.9885786, 0.1507064, 120, 255, 0), -- -Unknown- (Area: Gurubashi Arena)
(@OGUID+45, 152614, 0, 1, 1, -5210.476, 499.2994, 401.0719, 0.7679439, 0, 0, 0.3746067, 0.9271838, 120, 255, 24), -- 0 (Area: Gurubashi Arena)
(@OGUID+46, 205079, 0, 1, 1, -5177.976, 673.805, 389.5476, 1.492256, 0, 0, 0.6788008, 0.7343224, 120, 255, 24), -- 0 (Area: Gurubashi Arena)
(@OGUID+47, 205080, 0, 1, 1, -5178.21, 671.8933, 402.1269, 1.492256, 0, 0, 0.6788008, 0.7343224, 120, 255, 24), -- 0 (Area: Gurubashi Arena)
(@OGUID+48, 152614, 0, 1, 1, -5067.462, 438.9844, 423.7576, 2.539454, 0, 0, 0.95502, 0.2965415, 120, 255, 24), -- 0 (Area: Gurubashi Arena)
(@OGUID+49, 205077, 0, 1, 1, -4917.348, 782.4108, 276.2287, 1.492256, 0, 0, 0.6788008, 0.7343224, 120, 255, 1), -- -Unknown- (Area: Gurubashi Arena)
(@OGUID+50, 207872, 0, 1, 1, -6247.23, 6529.747, -880.4471, 5.240902, 0, 0, 0.4400505, 0.897973, 120, 255, 0), -- -Unknown- (Area: Gurubashi Arena)
(@OGUID+51, 207869, 0, 1, 1, -6188.985, 6559.648, -883.7168, 5.240902, 0, 0, 0.4400505, 0.897973, 120, 255, 0), -- -Unknown- (Area: Gurubashi Arena)
(@OGUID+52, 207870, 0, 1, 1, -6047.34, 6742.35, -883.7168, 5.852104, 0, 0, 0.4400505, 0.897973, 120, 255, 0), -- -Unknown- (Area: Gurubashi Arena)
(@OGUID+53, 207871, 0, 1, 1, -6032.426, 6805.216, -877.9181, 6.140289, 0, 0, 0.4400505, 0.897973, 120, 255, 0), -- -Unknown- (Area: Gurubashi Arena)
(@OGUID+54, 190192, 0, 1, 1, -4903.218, -6629.801, 10.95026, 5.410522, 0, 0, -0.4226183, 0.9063078, 120, 255, 0), -- Gate (Area: Gurubashi Arena)
-- (@OGUID+55, 206329, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 120, 255, 1), -- 0 (Area: Gurubashi Arena) - !!! transport !!!
-- (@OGUID+55, 206328, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 120, 255, 1), -- 0 (Area: Gurubashi Arena) - !!! transport !!!
(@OGUID+55, 195491, 0, 1, 1, -1713.75, 4664.54, -1309.52, 4.14516, 0, 0, 0.8767267, -0.4809888, 120, 255, 1), -- Doodad_ND_WinterOrc_Wall_GateFX_Door01 (Area: Gurubashi Arena)
(@OGUID+56, 195437, 0, 1, 1, -1643.74, 4642.156, -1308.775, 1.41361, 0, 0, 0.6494083, 0.7604399, 120, 255, 1), -- Doodad_VR_Portcullis01 (Area: Gurubashi Arena)
(@OGUID+57, 195491, 0, 1, 1, -1582.631, 4657.26, -1309.14, 5.358162, 0, 0, -0.4461977, 0.8949344, 120, 255, 1), -- Doodad_ND_WinterOrc_Wall_GateFX_Door01 (Area: Gurubashi Arena)
(@OGUID+58, 195437, 0, 1, 1, -1552.63, 4712.904, -1308.775, 2.809871, 0, 0, 0.9862769, 0.1650993, 120, 255, 1), -- Doodad_VR_Portcullis01 (Area: Gurubashi Arena)
(@OGUID+59, 195491, 0, 1, 1, -1568.881, 4784.29, -1309.41, 0.4014249, 0, 0, 0.1993681, 0.9799247, 120, 255, 1), -- Doodad_ND_WinterOrc_Wall_GateFX_Door01 (Area: Gurubashi Arena)
(@OGUID+60, 195491, 0, 1, 1, -1171.189, 4416.63, -1309.28, 3.097919, 0, 0, 0.9997621, 0.02181499, 120, 255, 1), -- Doodad_ND_WinterOrc_Wall_GateFX_Door01 (Area: Gurubashi Arena)
(@OGUID+61, 195437, 0, 1, 1, -1146.486, 4356.482, -1307.615, 0.5845804, 0, 0, 0.2881461, 0.9575865, 120, 255, 1), -- Doodad_VR_Portcullis01 (Area: Gurubashi Arena)
(@OGUID+62, 195437, 0, 1, 1, -1147.139, 4471.825, -1307.615, 5.471503, 0, 0, -0.3947921, 0.9187705, 120, 255, 1), -- Doodad_VR_Portcullis01 (Area: Gurubashi Arena)
(@OGUID+63, 195491, 0, 1, 1, -1079.949, 4325.91, -1309.27, 4.459317, 0, 0, -0.7906896, 0.6122173, 120, 255, 1), -- Doodad_ND_WinterOrc_Wall_GateFX_Door01 (Area: Gurubashi Arena)
(@OGUID+64, 195491, 0, 1, 1, -1086.77, 4513.75, -1309.27, 1.919862, 0, 0, 0.8191521, 0.5735763, 120, 255, 1), -- Doodad_ND_WinterOrc_Wall_GateFX_Door01 (Area: Gurubashi Arena)
(@OGUID+65, 174626, 0, 1, 1, 1267.591, -2567.375, 94.11425, 5.192355, 0, 0, 0.9713421, -0.2376859, 120, 255, 1), -- Scholomance Door (Area: Gurubashi Arena)
(@OGUID+66, 20657, 0, 1, 1, 1533.878, 240.8255, -32.34733, 3.132858, 0, 0, -0.004363197, 0.9999905, 120, 255, 24), -- 0 (Area: Gurubashi Arena)
(@OGUID+67, 20655, 0, 1, 1, 1544.236, 240.7726, -40.78354, 6.274459, 0, 0, -0.004363197, 0.9999905, 120, 255, 24), -- 0 (Area: Gurubashi Arena)
(@OGUID+68, 20656, 0, 1, 1, 1553.298, 240.656, 55.39519, 6.274459, 0, 0, -0.004363197, 0.9999905, 120, 255, 24), -- 0 (Area: Gurubashi Arena)
(@OGUID+69, 20653, 0, 1, 1, 1595.378, 197.7065, 55.39519, 1.56207, 0, 0, -0.004363197, 0.9999905, 120, 255, 24), -- 0 (Area: Gurubashi Arena)
(@OGUID+70, 20654, 0, 1, 1, 1595.212, 178.6932, -40.52226, 4.703663, 0, 0, -0.004363197, 0.9999905, 120, 255, 24), -- 0 (Area: Gurubashi Arena)
(@OGUID+71, 20652, 0, 1, 1, 1595.261, 188.6444, -40.78354, 1.56207, 0, 0, -0.004363197, 0.9999905, 120, 255, 24), -- 0 (Area: Gurubashi Arena)
(@OGUID+72, 20650, 0, 1, 1, 1596.037, 282.7377, 55.3952, 4.703663, 0, 0, -0.004363197, 0.9999905, 120, 255, 24), -- 0 (Area: Gurubashi Arena)
(@OGUID+73, 20649, 0, 1, 1, 1596.154, 291.7997, 14.68224, 4.703663, 0, 0, -0.004363197, 0.9999905, 120, 255, 24), -- 0 (Area: Gurubashi Arena)
(@OGUID+74, 20651, 0, 1, 1, 1596.209, 302.4006, -40.66451, 1.56207, 0, 0, -0.004363197, 0.9999905, 120, 255, 24), -- 0 (Area: Gurubashi Arena)
(@OGUID+75, 176594, 0, 1, 1, 2389.097, 337.9021, 40.01292, 2.242746, 0, 0, 0.9006982, 0.4344453, 120, 255, 1), -- Doors (Area: Gurubashi Arena)
(@OGUID+76, 101851, 0, 1, 1, 2886.309, -827.2612, 160.3354, 1.963495, 0, 0, 0.8314698, 0.55557, 120, 255, 1), -- Armory Door (Area: Gurubashi Arena)
(@OGUID+77, 101850, 0, 1, 1, 2908.177, -818.2034, 160.3318, 1.963495, 0, 0, 0.8314698, 0.55557, 120, 255, 1), -- Cathedral Door (Area: Gurubashi Arena)
(@OGUID+78, 175369, 0, 1, 1, 3185.481, -4039.099, 107.7914, 3.124123, 0, 0, 0.9999619, 0.008726474, 120, 255, 1), -- Elders' Square Service Entrance (Area: Gurubashi Arena)
(@OGUID+79, 175370, 0, 1, 1, 3271.517, -4064.309, 108.4344, 3.429581, 0, 0, 0.9999619, 0.008726474, 120, 255, 1), -- Doodad_SmallPortcullis05 (Area: Gurubashi Arena)
(@OGUID+80, 194919, 0, 1, 1, 3555.828, -3434.895, 136.3569, 2.312558, 0, 0, 1, -4.371139E-08, 120, 255, 1), -- -Unknown- (Area: Gurubashi Arena)
(@OGUID+81, 194918, 0, 1, 1, 3571.571, -3451.686, 136.3569, 2.312558, 0, 0, 1, -4.371139E-08, 120, 255, 1), -- -Unknown- (Area: Gurubashi Arena)
(@OGUID+82, 194917, 0, 1, 1, 3603.04, -3335.242, 125.3545, 3.141593, 0, 0, 1, -4.371139E-08, 120, 255, 1), -- -Unknown- (Area: Gurubashi Arena)
(@OGUID+83, 194916, 0, 1, 1, 3621.545, -3335.557, 123.5011, 3.141593, 0, 0, 1, -4.371139E-08, 120, 255, 1), -- -Unknown- (Area: Gurubashi Arena)
(@OGUID+84, 194934, 0, 1, 1, 3624.908, -3642.165, 138.4453, 3.595379, 0, 0, 1, -4.371139E-08, 120, 255, 1), -- -Unknown- (Area: Gurubashi Arena)
(@OGUID+85, 194923, 0, 1, 1, 3727.291, -3599.084, 142.2197, 3.516848, 0, 0, 1, -4.371139E-08, 120, 255, 1), -- -Unknown- (Area: Gurubashi Arena)
(@OGUID+86, 194922, 0, 1, 1, 3782.581, -3590.481, 143.9873, 1.946041, 0, 0, 1, -4.371139E-08, 120, 255, 1), -- -Unknown- (Area: Gurubashi Arena)
(@OGUID+87, 194925, 0, 1, 1, 3908.783, -3320.208, 120.9042, 4.424412, 0, 0, 1, -4.371139E-08, 120, 255, 1), -- -Unknown- (Area: Gurubashi Arena)
(@OGUID+88, 194921, 0, 1, 1, 3908.553, -3545.293, 135.9082, 2.949595, 0, 0, 1, -4.371139E-08, 120, 255, 1), -- -Unknown- (Area: Gurubashi Arena)
(@OGUID+89, 194924, 0, 1, 1, 3960.596, -3392.892, 119.6622, 3.194002, 0, 0, 1, -4.371139E-08, 120, 255, 1), -- -Unknown- (Area: Gurubashi Arena)
(@OGUID+90, 194920, 0, 1, 1, 3931.202, -3549.387, 133.9609, 2.949595, 0, 0, 1, -4.371139E-08, 120, 255, 1), -- -Unknown- (Area: Gurubashi Arena)
(@OGUID+91, 2043, 0, 1, 1, -13137.4, 129.991, 19.7443, 0, 0, 0, 0, 1, 120, 255, 1); -- Khadgar's Whisker (Area: Gurubashi Arena)

UPDATE `creature_template` SET `faction_A`=188, `faction_H`=188, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000 WHERE `entry`=49928; -- Crimson Moth
UPDATE `creature_template` SET `faction_A`=188, `faction_H`=188, `speed_walk`=0.5714286, `speed_run`=0.4, `baseattacktime`=2000, `rangeattacktime`=2000 WHERE `entry`=50479; -- Lizard Hatchling
UPDATE `creature_template` SET `faction_A`=188, `faction_H`=188, `speed_walk`=0.8571429, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=49722; -- Tree Python

DELETE FROM `creature_template_addon` WHERE `entry` IN (15475, 15475, 49928, 50479, 15475, 49722, 15475, 32520, 44140, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 40728, 40728, 40728, 32520, 42851, 40987, 32520, 42851, 42851, 42851, 42851, 32520, 42851, 42851, 42851, 42851, 32520, 42851, 42851, 42851, 32520, 42851, 42851, 32520, 42851, 42851, 42851, 42851, 32520, 32520, 32520, 42851, 32520, 32520, 32520, 37490, 32520, 42851, 32520, 32520, 32520, 32520, 32520, 32520, 32520, 42851, 32520, 42173, 42196, 42196, 42173, 42173, 37490, 43359, 45681);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(15475, 0, 0x0, 0x1, ''), -- Beetle
(49928, 0, 0x3000000, 0x1, ''), -- Crimson Moth
(50479, 0, 0x0, 0x1, ''), -- Lizard Hatchling
(49722, 0, 0x0, 0x1, ''), -- Tree Python
(32520, 0, 0x0, 0x1, ''), -- Totally Generic Bunny (All Phase)
(44140, 0, 0x0, 0x1, ''), -- PetWait Trigger
(40728, 0, 0x0, 0x1, '54913'), -- Whale Shark - Thrash
(42851, 0, 0x0, 0x1, '29266'), -- Revenant of Neptulon - Permanent Feign Death
(40987, 0, 0x0, 0x1, ''), -- Gnash
(37490, 0, 0x0, 0x1, ''), -- ELM General Purpose Bunny Infinite
(42173, 0, 0x0, 0x1, ''), -- The Undershell Tentacle Flavor
(42196, 0, 0x0, 0x1, '78715'), -- ELM General Purpose Bunny Infinite (scale x2.5) - L'ghorek: Ascendant Light Beam
(43359, 0, 0x0, 0x1, ''), -- ELM General Purpose Bunny Infinite Hide Body
(45681, 0, 0x0, 0x1, ''); -- Garginox

UPDATE `creature_model_info` SET `bounding_radius`=0.0875, `combat_reach`=0.25 WHERE `modelid`=36671;

SET @CGUID := 568;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+106;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 15475, 0, 1, 1, -13004.9, 182.2603, 21.25262, 3.129874, 120, 0, 0), -- Beetle (Area: Gurubashi Arena)
(@CGUID+1, 15475, 0, 1, 1, -13062.86, 181.8854, 22.70876, 1.325542, 120, 0, 0), -- Beetle (Area: Gurubashi Arena)
(@CGUID+2, 49928, 0, 1, 1, -12993.8, 215.0794, 31.65138, 4.236865, 120, 0, 0), -- Crimson Moth (Area: Gurubashi Arena)
(@CGUID+3, 50479, 0, 1, 1, -13049.53, 221.7709, 22.14255, 1.107149, 120, 0, 0), -- Lizard Hatchling (Area: Gurubashi Arena)
(@CGUID+4, 15475, 0, 1, 1, -13061.06, 219.6319, 21.9774, 1.809663, 120, 0, 0), -- Beetle (Area: Gurubashi Arena)
(@CGUID+5, 49722, 0, 1, 1, -13088.08, 111.1961, 26.7373, 5.303102, 120, 0, 0), -- Tree Python (Area: Gurubashi Arena) (possible waypoints or random movement)
(@CGUID+6, 15475, 0, 1, 1, -13023.75, 250.0127, 19.91922, 3.23932, 120, 0, 0), -- Beetle (Area: Gurubashi Arena)
(@CGUID+7, 32520, 0, 1, 1, -8680.672, 730.7483, 159.0924, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+8, 44140, 0, 1, 1, -9193.85, -2777.82, 90.63683, 0, 120, 0, 0), -- PetWait Trigger (Area: Gurubashi Arena)
(@CGUID+9, 32520, 0, 1, 1, -8290.094, 1388.641, 30.00427, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+10, 32520, 0, 1, 1, -8282.045, 1450.892, 0.3571493, 6.265732, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+11, 32520, 0, 1, 1, -7549.146, 2210.674, -0.01231566, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+12, 32520, 0, 1, 1, -7528.516, 2226.144, -0.01220667, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+13, 32520, 0, 1, 1, -7488.368, 2254.41, -0.01226167, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+14, 32520, 0, 1, 1, -7436.108, 2284.655, -0.01220667, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+15, 32520, 0, 1, 1, -7431.354, 2306.233, 0.2182883, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+16, 32520, 0, 1, 1, -7373.118, 2314.969, -0.01226167, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+17, 32520, 0, 1, 1, -7375.434, 2326.503, 0.2182883, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+18, 32520, 0, 1, 1, -7326.561, 2345.738, 0.2182883, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+19, 32520, 0, 1, 1, -7323.299, 2340.835, -0.01226167, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+20, 32520, 0, 1, 1, -7305.255, 2337.531, 0.2182883, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+21, 32520, 0, 1, 1, -7286.641, 2349.813, 0.2182883, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+22, 32520, 0, 1, 1, -7262.632, 2365.733, 0.2182883, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+23, 32520, 0, 1, 1, -7249.769, 2376.906, -0.01226167, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+24, 32520, 0, 1, 1, -7218.764, 2373.132, 0.2182883, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+25, 32520, 0, 1, 1, -7208.29, 2375.983, 0.2182883, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+26, 32520, 0, 1, 1, -7203.332, 2380.043, 0.2182883, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+27, 32520, 0, 1, 1, -7199.389, 2383.023, 0.2182883, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+28, 32520, 0, 1, 1, -7198.851, 2404.536, -0.01220667, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+29, 32520, 0, 1, 1, -7191.5, 2387.116, 0.2182883, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+30, 32520, 0, 1, 1, -7188.139, 2390.936, 0.2182883, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+31, 32520, 0, 1, 1, -7182.01, 2390.734, 0.2182883, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+32, 32520, 0, 1, 1, -7176.62, 2393.826, 0.2182883, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+33, 32520, 0, 1, 1, -7174.474, 2398.345, 0.2182883, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+34, 32520, 0, 1, 1, -7172.613, 2396.337, 0.2182883, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+35, 32520, 0, 1, 1, -7167.887, 2399.689, 0.2182883, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+36, 32520, 0, 1, 1, -7163.313, 2402.516, 0.2182883, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+37, 32520, 0, 1, 1, -7157.736, 2406.872, 0.2182883, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+38, 32520, 0, 1, 1, -7155.571, 2410.693, 0.2182883, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+39, 32520, 0, 1, 1, -7155.319, 2425.731, -0.01220667, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+40, 32520, 0, 1, 1, -7148.408, 2413.837, 0.2182883, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+41, 32520, 0, 1, 1, -7144.577, 2416.571, 0.2182883, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+42, 32520, 0, 1, 1, -7138.686, 2418.826, 0.2182883, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+43, 32520, 0, 1, 1, -7135.222, 2421.837, 0.2182883, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+44, 32520, 0, 1, 1, -7111.288, 2445.353, -0.01226167, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+45, 32520, 0, 1, 1, -7069.127, 2456.75, -0.01226167, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+46, 32520, 0, 1, 1, -7038.147, 2468.995, -0.01226167, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+47, 32520, 0, 1, 1, -7006.415, 2479.377, -0.01220667, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+48, 32520, 0, 1, 1, -6967.941, 2493.597, -0.01231566, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+49, 32520, 0, 1, 1, -6932.59, 2514.827, -0.01226167, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+50, 32520, 0, 1, 1, -6904.563, 2550.189, -0.01225267, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+51, 32520, 0, 1, 1, -6865.792, 2562.302, -0.01225267, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+52, 40728, 0, 1, 1, -7136.362, 3808.928, -260.4893, 4.415598, 120, 0, 0), -- Whale Shark (Area: Gurubashi Arena)
(@CGUID+53, 40728, 0, 1, 1, -6230.263, 3523.805, -177.5556, 3.954979, 120, 0, 0), -- Whale Shark (Area: Gurubashi Arena)
(@CGUID+54, 40728, 0, 1, 1, -5090.75, 3076.055, -61.88317, 3.082705, 120, 0, 0), -- Whale Shark (Area: Gurubashi Arena)
(@CGUID+55, 32520, 0, 1, 1, -5136.05, 3277.62, -118.3217, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+56, 42851, 0, 1, 1, -6184.12, 5397.069, -1216.32, 0, 120, 0, 0), -- Revenant of Neptulon (Area: Gurubashi Arena)
(@CGUID+57, 40987, 0, 1, 1, -4987.908, 3518.65, -124.1968, 3.83507, 120, 0, 0), -- Gnash (Area: Gurubashi Arena) (possible waypoints or random movement)
(@CGUID+58, 32520, 0, 1, 1, -6305.162, 5582.533, -1172.063, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+59, 42851, 0, 1, 1, -6226.069, 5512.124, -1215.753, 0, 120, 0, 0), -- Revenant of Neptulon (Area: Gurubashi Arena)
(@CGUID+60, 42851, 0, 1, 1, -6079.696, 5338.495, -1215.58, 0, 120, 0, 0), -- Revenant of Neptulon (Area: Gurubashi Arena)
(@CGUID+61, 42851, 0, 1, 1, -5972.122, 5222.906, -1208.386, 0, 120, 0, 0), -- Revenant of Neptulon (Area: Gurubashi Arena)
(@CGUID+62, 42851, 0, 1, 1, -6133.175, 5494.254, -1215.137, 0, 120, 0, 0), -- Revenant of Neptulon (Area: Gurubashi Arena)
(@CGUID+63, 32520, 0, 1, 1, -6148.39, 5539.97, -1207.787, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+64, 42851, 0, 1, 1, -5862.793, 5175.958, -1213.582, 0, 120, 0, 0), -- Revenant of Neptulon (Area: Gurubashi Arena)
(@CGUID+65, 42851, 0, 1, 1, -5982.469, 5345.316, -1218.424, 0, 120, 0, 0), -- Revenant of Neptulon (Area: Gurubashi Arena)
(@CGUID+66, 42851, 0, 1, 1, -6043.141, 5439.757, -1219.116, 0, 120, 0, 0), -- Revenant of Neptulon (Area: Gurubashi Arena)
(@CGUID+67, 42851, 0, 1, 1, -6180.118, 5660.041, -1217.356, 0, 120, 0, 0), -- Revenant of Neptulon (Area: Gurubashi Arena)
(@CGUID+68, 32520, 0, 1, 1, -6014.71, 5479.63, -1208.007, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+69, 42851, 0, 1, 1, -6089.413, 5608.077, -1223.85, 0, 120, 0, 0), -- Revenant of Neptulon (Area: Gurubashi Arena)
(@CGUID+70, 42851, 0, 1, 1, -5863.936, 5310.616, -1222.713, 0, 120, 0, 0), -- Revenant of Neptulon (Area: Gurubashi Arena)
(@CGUID+71, 42851, 0, 1, 1, -5732.877, 5152.973, -1222.141, 0, 120, 0, 0), -- Revenant of Neptulon (Area: Gurubashi Arena)
(@CGUID+72, 32520, 0, 1, 1, -5851.79, 5397.15, -1217.167, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+73, 42851, 0, 1, 1, -5966.031, 5563.699, -1218.418, 0, 120, 0, 0), -- Revenant of Neptulon (Area: Gurubashi Arena)
(@CGUID+74, 42851, 0, 1, 1, -6005.035, 5671.134, -1219.748, 0, 120, 0, 0), -- Revenant of Neptulon (Area: Gurubashi Arena)
(@CGUID+75, 32520, 0, 1, 1, -4660.958, 3559.71, -113.9472, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+76, 42851, 0, 1, 1, -5616.425, 5177.916, -1226.32, 0, 120, 0, 0), -- Revenant of Neptulon (Area: Gurubashi Arena)
(@CGUID+77, 42851, 0, 1, 1, -5812.905, 5495.367, -1231.447, 0, 120, 0, 0), -- Revenant of Neptulon (Area: Gurubashi Arena)
(@CGUID+78, 42851, 0, 1, 1, -5867.2, 5622.304, -1230.413, 0, 120, 0, 0), -- Revenant of Neptulon (Area: Gurubashi Arena)
(@CGUID+79, 42851, 0, 1, 1, -5559.231, 5246.39, -1228.137, 5.654867, 120, 0, 0), -- Revenant of Neptulon (Area: Gurubashi Arena)
(@CGUID+80, 32520, 0, 1, 1, -4659.649, 3841.258, -3.712333, 3.159046, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+81, 32520, 0, 1, 1, -4657.863, 3872.089, -4.775842, 3.124139, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+82, 32520, 0, 1, 1, -4621.934, 3811.015, -2.434516, 2.530727, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+83, 42851, 0, 1, 1, -5717.965, 5538.276, -1237.856, 0, 120, 0, 0), -- Revenant of Neptulon (Area: Gurubashi Arena)
(@CGUID+84, 32520, 0, 1, 1, -4607.887, 3846.321, -4.775842, 3.124139, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+85, 32520, 0, 1, 1, -5691.65, 5556.92, -1154.687, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+86, 32520, 0, 1, 1, -5691.65, 5556.92, -1154.687, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+87, 37490, 0, 1, 1, -6654.488, 6736.202, -811.036, 0, 120, 0, 0), -- ELM General Purpose Bunny Infinite (Area: Gurubashi Arena)
(@CGUID+88, 32520, 0, 1, 1, -4599.307, 3875.44, -3.693974, 3.159046, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+89, 42851, 0, 1, 1, -5507.115, 5337.032, -1227.3, 0, 120, 0, 0), -- Revenant of Neptulon (Area: Gurubashi Arena)
(@CGUID+90, 32520, 0, 1, 1, -4617.3, 3981.36, -70.50646, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+91, 32520, 0, 1, 1, -4616.33, 3983.89, -70.31406, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+92, 32520, 0, 1, 1, -4614.15, 3980.53, -70.68576, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+93, 32520, 0, 1, 1, -4609.82, 3981.23, -70.54346, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+94, 32520, 0, 1, 1, -4607.62, 3984.2, -70.64417, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+95, 32520, 0, 1, 1, -4608.13, 3987.51, -70.37226, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+96, 32520, 0, 1, 1, -4605.043, 3983.192, -70.56809, 3.543018, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+97, 42851, 0, 1, 1, -5561.573, 5486.054, -1233.133, 0, 120, 0, 0), -- Revenant of Neptulon (Area: Gurubashi Arena)
(@CGUID+98, 32520, 0, 1, 1, -4461.703, 3807.523, -82.83333, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Gurubashi Arena)
(@CGUID+99, 42173, 0, 1, 1, -6446.698, 6829.101, -1124.952, 1.27409, 120, 0, 0), -- The Undershell Tentacle Flavor (Area: Gurubashi Arena)
(@CGUID+100, 42196, 0, 1, 1, -6423.21, 6884, -786.6007, 0, 120, 0, 0), -- ELM General Purpose Bunny Infinite (scale x2.5) (Area: Gurubashi Arena)
(@CGUID+101, 42196, 0, 1, 1, -6422.48, 6884.6, -870.8707, 0, 120, 0, 0), -- ELM General Purpose Bunny Infinite (scale x2.5) (Area: Gurubashi Arena)
(@CGUID+102, 42173, 0, 1, 1, -6230.174, 6798.166, -1075.454, 6.143559, 120, 0, 0), -- The Undershell Tentacle Flavor (Area: Gurubashi Arena)
(@CGUID+103, 42173, 0, 1, 1, -6396.681, 7054.327, -1069.238, 3.071779, 120, 0, 0), -- The Undershell Tentacle Flavor (Area: Gurubashi Arena)
(@CGUID+104, 37490, 0, 1, 1, -6353.474, 7151.508, -807.5332, 0, 120, 0, 0), -- ELM General Purpose Bunny Infinite (Area: Gurubashi Arena)
(@CGUID+105, 43359, 0, 1, 1, 2298.788, 280.1181, 76.27024, 0, 120, 0, 0), -- ELM General Purpose Bunny Infinite Hide Body (Area: Gurubashi Arena)
(@CGUID+106, 45681, 0, 1, 1, 2809.67, -5452.04, 158.8789, 2.897247, 120, 0, 0); -- Garginox (Area: Gurubashi Arena) (possible waypoints or random movement)

DELETE FROM `creature_equip_template` WHERE `entry`=45681;
INSERT INTO `creature_equip_template` (`entry`, `itemEntry1`, `itemEntry2`, `itemEntry3`) VALUES
(45681, 61298, 0, 0); -- Garginox
