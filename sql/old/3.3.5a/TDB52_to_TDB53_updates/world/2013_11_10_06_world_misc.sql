DELETE FROM `creature_template_addon` WHERE `entry`=21304;
INSERT INTO `creature_template_addon` (`entry`, `bytes2`, `auras`) VALUES (21304,1, '31261');

SET @CGUID := 213212;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+12;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 21304, 552, 3, 1, 197.9555, -86.81332, -10.01739, 5.8294, 7200, 0, 0),
(@CGUID+1, 21304, 552, 3, 1, 206.3423, -98.27836, -10.02623, 2.6529, 7200, 0, 0),
(@CGUID+2, 21304, 552, 3, 1, 270.7674, -66.62302, 22.45336, 5.742133, 7200, 0, 0),
(@CGUID+3, 21304, 552, 3, 1, 226.1842, -162.0961, -10.03523, 0.3490658, 7200, 0, 0),
(@CGUID+4, 21304, 552, 3, 1, 264.271, -191.2798, -10.02188, 5.61996, 7200, 0, 0),
(@CGUID+5, 21304, 552, 3, 1, 293.8853, 70.93681, 22.52617, 1.553343, 7200, 0, 0),
(@CGUID+6, 21304, 552, 3, 1, 291.632, 70.58091, 22.52693, 2.007129, 7200, 0, 0),
(@CGUID+7, 21304, 552, 3, 1, 285.4156, 127.1274, 22.29513, 4.694936, 7200, 0, 0),
(@CGUID+8, 21304, 552, 3, 1, 257.3438, 155.5679, 22.33209, 4.712389, 7200, 0, 0),
(@CGUID+9, 21304, 552, 3, 1, 298.8479, 151.7484, 22.31051, 5.707227, 7200, 0, 0),
(@CGUID+10, 20879, 552, 3, 1, 285.5186, 146.1547, 22.31179, 5.794493, 7200, 0, 0),
(@CGUID+11, 20880, 552, 3, 1, 301.7973, 127.4436, 22.31079, 1.308997, 7200, 0, 0),
(@CGUID+12, 20880, 552, 3, 1, 305.7355, 148.0587, 24.8633, 3.979351, 7200, 0, 0);

DELETE FROM `creature` WHERE `guid` IN (79506,79533,79535,79561,79570,79448);
DELETE FROM `creature_addon` WHERE `guid` IN (79506,79533,79535,79561,79570,79448);

DELETE FROM `creature` WHERE `guid` BETWEEN 86054 AND 86064;
DELETE FROM `creature_addon` WHERE `guid` BETWEEN 86054 AND 86064;
DELETE FROM `waypoint_data` WHERE `id`=860600;

DELETE FROM `creature_template_addon` WHERE `entry`=20869;
INSERT INTO `creature_template_addon` (`entry`, `bytes2`, `auras`) VALUES (20869,1, '31261 36716');

SET @CGUID := 86054; -- 86059 to 86064 free
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+4;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 20869, 552, 3, 1, 264.2865, -61.32112, 22.45335, 5.288348, 7200, 0, 0),
(@CGUID+1, 20869, 552, 3, 1, 336.5143, 27.42666, 48.42604, 3.839724, 7200, 0, 0),
(@CGUID+2, 20869, 552, 3, 1, 253.942, 131.8811, 22.39496, 0.7679449, 7200, 0, 0),
(@CGUID+3, 20869, 552, 3, 1, 255.4978, 158.9143, 22.36194, 5.410521, 7200, 0, 0),
(@CGUID+4, 20869, 552, 3, 1, 395.413, 18.19484, 48.29602, 2.495821, 7200, 0, 0);

-- Pathing for Gargantuan Abyssal Entry: 20898
SET @NPC := 79433;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=444.3863,`position_y`=-151.7787,`position_z`=43.03745 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,444.3863,-151.7787,43.03745,0,0,0,0,100,0),
(@PATH,2,456.1953,-162.0229,43.09797,0,0,0,0,100,0),
(@PATH,3,444.3863,-151.7787,43.03745,0,0,0,0,100,0),
(@PATH,4,437.7717,-136.3138,43.10011,0,0,0,0,100,0),
(@PATH,5,441.6954,-123.0422,43.10011,0,0,0,0,100,0),
(@PATH,6,445.0636,-105.6565,43.10011,0,0,0,0,100,0),
(@PATH,7,446.4647,-89.31697,43.10009,0,0,0,0,100,0),
(@PATH,8,446.4129,-65.38671,48.39542,0,0,0,0,100,0),
(@PATH,9,446.4648,-89.31628,43.10009,0,0,0,0,100,0),
(@PATH,10,445.0636,-105.6565,43.10011,0,0,0,0,100,0),
(@PATH,11,441.6954,-123.0422,43.10011,0,0,0,0,100,0),
(@PATH,12,437.7717,-136.3138,43.10011,0,0,0,0,100,0);

-- Pathing for Soul Devourer Entry: 20866
SET @NPC := 79477;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=207.7079,`position_y`=-129.0737,`position_z`=-10.10952 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,207.7079,-129.0737,-10.10952,0,0,0,0,100,0),
(@PATH,2,245.4314,-128.669,-10.11772,0,0,0,0,100,0),
(@PATH,3,245.1088,-143.0256,-10.11027,0,0,0,0,100,0),
(@PATH,4,256.1706,-143.8266,-10.11091,0,0,0,0,100,0),
(@PATH,5,276.7943,-145.2905,-10.11652,0,0,0,0,100,0),
(@PATH,6,256.1706,-143.8266,-10.11091,0,0,0,0,100,0),
(@PATH,7,245.1088,-143.0256,-10.11027,0,0,0,0,100,0),
(@PATH,8,245.4314,-128.669,-10.11772,0,0,0,0,100,0),
(@PATH,9,207.7079,-129.0737,-10.10952,0,0,0,0,100,0),
(@PATH,10,221.3861,-128.9554,-10.11454,0,0,0,0,100,0);
-- 0xF130518200003BFB .go 207.7079 -129.0737 -10.10952

-- Pathing for Soul Devourer Entry: 20866
SET @NPC := 86053;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `id`=20866,`curhealth`=1,`spawndist`=0,`MovementType`=2,`position_x`=221.8707,`position_y`=-152.5772,`position_z`=-10.11229 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,221.8707,-152.5772,-10.11229,0,0,0,0,100,0),
(@PATH,2,237.1845,-152.618,-10.10515,0,0,0,0,100,0),
(@PATH,3,253.953,-152.8117,-10.1066,0,0,0,0,100,0),
(@PATH,4,253.2783,-175.503,-10.10356,0,0,0,0,100,0),
(@PATH,5,253.953,-152.8117,-10.1066,0,0,0,0,100,0),
(@PATH,6,237.1845,-152.618,-10.10515,0,0,0,0,100,0),
(@PATH,7,221.8707,-152.5772,-10.11229,0,0,0,0,100,0),
(@PATH,8,208.5352,-152.2789,-10.11248,0,0,0,0,100,0);
-- 0xF130518200003BFD .go 221.8707 -152.5772 -10.11229

UPDATE `creature_template` SET `speed_walk`= 1.6, `speed_run`= 1.428571 WHERE `entry`= 20885;
UPDATE `creature_template` SET `speed_walk`= 1, `speed_run`= 0.8571429 WHERE `entry`= 20859;
UPDATE `creature_template` SET `speed_walk`= 1, `speed_run`= 0.8571429 WHERE `entry`= 20857;
UPDATE `creature_template` SET `speed_walk`= 1, `speed_run`= 1.142857 WHERE `entry`= 21186;
UPDATE `creature_template` SET `speed_walk`= 1.6, `speed_run`= 1.428571 WHERE `entry`= 20886;
UPDATE `creature_template` SET `speed_walk`= 1.2, `speed_run`= 1.428571 WHERE `entry`= 20864;
UPDATE `creature_template` SET `speed_walk`= 1.2, `speed_run`= 1.428571 WHERE `entry`= 20865;
UPDATE `creature_template` SET `speed_walk`= 1, `speed_run`= 0.8571429 WHERE `entry`= 21303;
UPDATE `creature_template` SET `speed_walk`= 1, `speed_run`= 0.8571429 WHERE `entry`= 21304;
UPDATE `creature_template` SET `speed_walk`= 1, `speed_run`= 1.428571 WHERE `entry`= 20869;
UPDATE `creature_template` SET `speed_walk`= 1, `speed_run`= 1.428571 WHERE `entry`= 20875;
UPDATE `creature_template` SET `speed_walk`= 1, `speed_run`= 1.428571 WHERE `entry`= 20873;
UPDATE `creature_template` SET `speed_walk`= 1, `speed_run`= 1.428571 WHERE `entry`= 20866;
UPDATE `creature_template` SET `speed_walk`= 1, `speed_run`= 1.428571 WHERE `entry`= 20868;
UPDATE `creature_template` SET `speed_walk`= 1, `speed_run`= 1.428571 WHERE `entry`= 20900;
UPDATE `creature_template` SET `speed_walk`= 0.888888, `speed_run`= 1.428571 WHERE `entry`= 20880;
UPDATE `creature_template` SET `speed_walk`= 0.888888, `speed_run`= 1.428571 WHERE `entry`= 20879;
UPDATE `creature_template` SET `speed_walk`= 1, `speed_run`= 0.8571429 WHERE `entry`= 20977;
UPDATE `creature_template` SET `speed_walk`= 1, `speed_run`= 0.8571429 WHERE `entry`= 20904;
UPDATE `creature_template` SET `speed_walk`= 1.6, `speed_run`= 1.714286 WHERE `entry`= 20898;
UPDATE `creature_template` SET `speed_walk`= 1.6, `speed_run`= 1.714286 WHERE `entry`= 20870;
UPDATE `creature_template` SET `speed_walk`= 1.6, `speed_run`= 1.714286 WHERE `entry`= 20912;
UPDATE `creature_template` SET `speed_walk`= 8, `speed_run`= 2.857143 WHERE `entry`= 20978;
UPDATE `creature_template` SET `speed_walk`= 1, `speed_run`= 1 WHERE `entry`= 21962;
UPDATE `creature_template` SET `speed_walk`= 1, `speed_run`= 1.428571 WHERE `entry`= 20906;
UPDATE `creature_template` SET `speed_walk`= 1, `speed_run`= 1.428571 WHERE `entry`= 20909;
UPDATE `creature_template` SET `speed_walk`= 1, `speed_run`= 1.428571 WHERE `entry`= 20910;
UPDATE `creature_template` SET `speed_walk`= 1, `speed_run`= 1.428571 WHERE `entry`= 22494;
UPDATE `creature_template` SET `speed_walk`= 1, `speed_run`= 1.428571 WHERE `entry`= 20881;
UPDATE `creature_template` SET `speed_walk`= 1, `speed_run`= 1.428571 WHERE `entry`= 20882;
UPDATE `creature_template` SET `speed_walk`= 1, `speed_run`= 1.428571 WHERE `entry`= 20883;
UPDATE `creature_template` SET `speed_walk`= 1, `speed_run`= 1.428571 WHERE `entry`= 20896;
UPDATE `creature_template` SET `speed_walk`= 1, `speed_run`= 1.428571 WHERE `entry`= 21702;
UPDATE `creature_template` SET `speed_walk`= 1, `speed_run`= 1.428571 WHERE `entry`= 20897;
UPDATE `creature_template` SET `speed_walk`= 1, `speed_run`= 1.428571 WHERE `entry`= 20901;
UPDATE `creature_template` SET `speed_walk`= 1, `speed_run`= 1.428571 WHERE `entry`= 20902;
UPDATE `creature_template` SET `speed_walk`= 1, `speed_run`= 1.142857 WHERE `entry`= 15384;
UPDATE `creature_template` SET `speed_walk`= 1, `speed_run`= 1.142857 WHERE `entry`= 21436;
UPDATE `creature_template` SET `speed_walk`= 1, `speed_run`= 1.142857 WHERE `entry`= 21437;
UPDATE `creature_template` SET `speed_walk`= 1, `speed_run`= 1.142857 WHERE `entry`= 21438;
UPDATE `creature_template` SET `speed_walk`= 1, `speed_run`= 1.142857 WHERE `entry`= 21439;
UPDATE `creature_template` SET `speed_walk`= 1, `speed_run`= 1.142857 WHERE `entry`= 21440;
UPDATE `creature_template` SET `speed_walk`= 1, `speed_run`= 1.142857 WHERE `entry`= 20515;
UPDATE `creature_template` SET `speed_walk`= 1, `speed_run`= 1.142857 WHERE `entry`= 22491;
UPDATE `creature_template` SET `speed_walk`= 1, `speed_run`= 1.142857 WHERE `entry`= 22479;
UPDATE `creature_template` SET `speed_walk`= 1, `speed_run`= 1.142857 WHERE `entry`= 18884;
UPDATE `creature_template` SET `speed_walk`= 1, `speed_run`= 1.142857 WHERE `entry`= 20673;
