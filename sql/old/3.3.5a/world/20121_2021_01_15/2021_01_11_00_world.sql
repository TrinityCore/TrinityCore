--
UPDATE `creature_template` SET `unit_flags` = 33536 WHERE `entry` = 35318;
UPDATE `creature_template` SET `unit_flags` = 33536 WHERE `entry` = 35319;
UPDATE `creature` SET `position_x` = 9031.723, `position_y` = 791.594, `position_z` = 4.4536467 WHERE `guid` = 54289 AND `id` = 35318;
UPDATE `creature` SET `position_x` = 8999.594, `position_y` = 786.09595, `position_z` = 3.9880195 WHERE `guid` = 54294 AND `id` = 35318;
UPDATE `creature` SET `position_x` = 9074.286, `position_y` = 1246.373, `position_z` = 4.1484613 WHERE `guid` = 54296 AND `id` = 35319;
UPDATE `creature` SET `position_x` = 9095.156, `position_y` = 1250.3452, `position_z` = 4.407067 WHERE `guid` = 54301 AND `id` = 35319;
DELETE FROM `waypoint_data` WHERE `id` IN (542890,542940,542960,543010);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`) VALUES
(542890,1,9031.723,791.594,4.4536467),
(542890,2,9035.5205,796.7761,4.8959217),
(542890,3,9039.805,802.7295,5.3525624),
(542890,4,9035.5205,796.7761,4.8959217),
(542890,5,9031.723,791.594,4.4536467),
(542890,6,9026.437,785.3284,4.101227),
(542890,7,9021.305,779.43585,3.9721866),
(542890,8,9013.992,772.0473,3.9440575),
(542890,9,9021.2,779.33,3.9915123),
(542890,10,9026.437,785.3284,4.101227),
(542940,1,8999.594,786.09595,3.9880195),
(542940,2,9004.681,791.0902,3.9192505),
(542940,3,9010.243,796.3544,4.0598397),
(542940,4,9015.974,801.1094,4.2398877),
(542940,5,9022.62,806.2537,4.7100782),
(542940,6,9031.089,812.3556,5.435156),
(542940,7,9022.62,806.2537,4.7100782),
(542940,8,9015.974,801.1094,4.2398877),
(542940,9,9010.245,796.3561,4.0691915),
(542940,10,9004.681,791.0902,3.9192505),
(542960,1,9074.286,1246.373,4.1484613),
(542960,2,9080.736,1240.3163,4.3069353),
(542960,3,9088.519,1234.1006,4.9957604),
(542960,4,9094.786,1228.9253,5.54292),
(542960,5,9088.519,1234.1006,4.9957604),
(542960,6,9080.736,1240.3163,4.3069353),
(542960,7,9074.321,1246.3401,4.104896),
(542960,8,9069.005,1251.9115,4.0509315),
(542960,9,9064.637,1257.1733,4.042889),
(542960,10,9068.954,1251.9717,4.050212),
(543010,1,9095.156,1250.3452,4.407067),
(543010,2,9100.435,1241.3265,5.1558127),
(543010,3,9103.74,1236.1891,5.571357),
(543010,4,9100.435,1241.3265,5.1558127),
(543010,5,9095.156,1250.3452,4.407067),
(543010,6,9088.236,1260.0851,4.174607),
(543010,7,9079.912,1270.3301,4.024527),
(543010,8,9088.236,1260.0851,4.174607);

UPDATE `creature_template` SET `unit_flags` = 33536 WHERE `entry` = 34788;
UPDATE `creature_template` SET `minlevel` = 83, `maxlevel` = 83, `unit_flags` = 33554432 WHERE `entry` BETWEEN 16775 AND 16778;
UPDATE `creature_template` SET `unit_flags` = 32768 WHERE `entry` BETWEEN 10080 AND 10082;
UPDATE `creature_template` SET `speed_walk` = 1, `unit_flags` = 33536 WHERE `entry` = 18471;

UPDATE `creature_template` SET `unit_flags` = 768 WHERE `entry` IN (27616,27618,27619,27624);
UPDATE `creature_template` SET `unit_flags` = 33536 WHERE `entry` = 27620;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (27616,27618,27619,27624,27620) AND `source_type` = 0 AND `id` = 0;

UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 2 WHERE `entry` IN (40626,40627,40628,40870,37236,25176,25177,25179,24088,24090);

UPDATE `creature_template` SET `speed_walk` = 2.8, `speed_run` = 1.71428571429, `unit_flags` = 33588032 WHERE `entry` = 22196;

UPDATE `creature_template_addon` SET `bytes1` = 0, `auras` = "31261" WHERE `entry` = 18240;
UPDATE `creature_template` SET `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 33536 WHERE `entry` = 18240;

UPDATE `creature_template` SET `speed_walk` = 1, `RangeAttackTime` = 2000, `unit_flags` = 512 WHERE `entry` = 19644;

UPDATE `creature_template` SET `unit_flags` = 768 WHERE `entry` = 24880;

UPDATE `creature_template` SET `unit_flags` = 33555200 WHERE `entry` IN (24413,24420,24421,24426,24427,24429,24433,24854);

UPDATE `creature_template` SET `unit_flags` = 768 WHERE `entry` = 24515;
UPDATE `creature_template` SET `unit_flags` = 0 WHERE `entry` = 33184;

UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 2 WHERE `entry` = 33291;
DELETE FROM `creature_template_addon` WHERE `entry` = 33291;
INSERT INTO `creature_template_addon` (`entry`,`auras`) VALUES
(33291,"62715");

UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 2 WHERE `entry` IN (33750,33751,33752,33753,29998);
UPDATE `creature_template` SET `unit_flags` = 0 WHERE `entry` IN (34567,34568);
UPDATE `creature_template` SET `unit_flags` = 768 WHERE `entry` = 25349;
UPDATE `creature_template` SET `unit_flags` = 33024 WHERE `entry` = 25835;
UPDATE `creature_template` SET `unit_flags` = 33554944 WHERE `entry` = 23996;
UPDATE `creature_template` SET `unit_flags` = 256, `HoverHeight` = 4 WHERE `entry` IN (24068,31655);
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 2 WHERE `entry` = 24168;

UPDATE `creature_template` SET `unit_flags` = 768 WHERE `entry` = 22900;
UPDATE `creature_template` SET `unit_flags` = 768 WHERE `entry` = 22932;
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 2 WHERE `entry` = 21241;
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 2 WHERE `entry` = 28090;
UPDATE `creature_template` SET `unit_flags` = 768 WHERE `entry` = 17508;
UPDATE `creature_template` SET `unit_flags` = 768 WHERE `entry` = 6912;
