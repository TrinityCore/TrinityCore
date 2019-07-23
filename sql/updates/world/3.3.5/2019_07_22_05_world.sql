-- 
DELETE FROM `creature` WHERE `id`  IN (29844,29849) AND `guid` IN (111321, 111322, 111323, 111355, 111356, 111361, 111399, 111415, 111416, 111417, 111418, 111419, 111420, 111421, 111422, 111423, 111424, 111425);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`,  `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(111321, 29844, 571, 1, 1, 0, 7171.79, -1171.77, 937.135, 1.65720, 300, 0, 0),
(111322, 29844, 571, 1, 1, 0, 7143.07, -1218.10, 923.856, 0.63617, 300, 0, 0),
(111323, 29844, 571, 1, 1, 0, 7105.03, -1203.73, 923.406, 4.98964, 300, 0, 0),
(111355, 29844, 571, 1, 1, 0, 7036.46, -1196.88, 928.524, 6.17795, 300, 0, 0),
(111356, 29844, 571, 1, 1, 0, 6985.52, -1239.67, 930.598, 0.94326, 300, 0, 0),
(111361, 29844, 571, 1, 1, 0, 7040.64, -1284.87, 919.913, 3.07562, 300, 0, 0),
(111399, 29844, 571, 1, 1, 0, 7029.68, -1297.60, 939.496, 2.79679, 300, 0, 0),
(111415, 29844, 571, 1, 1, 0, 7080.82, -1282.93, 919.239, 3.52329, 300, 0, 0),
(111416, 29844, 571, 1, 1, 0, 7083.67, -1327.89, 920.353, 1.73505, 300, 0, 0),
(111417, 29844, 571, 1, 1, 0, 7085.77, -1347.81, 916.756, 0.32526, 300, 0, 0),
(111418, 29849, 571, 1, 1, 0, 7118.97, -1331.15, 916.364, 1.47980, 300, 5, 1),
(111419, 29849, 571, 1, 1, 0, 7134.96, -1343.32, 916.364, 5.82698, 300, 5, 1),
(111420, 29849, 571, 1, 1, 0, 7149.91, -1321.87, 916.364, 1.16957, 300, 5, 1),
(111421, 29849, 571, 1, 1, 0, 7128.84, -1299.29, 916.364, 3.41187, 300, 5, 1),
(111422, 29849, 571, 1, 1, 0, 7115.69, -1311.35, 916.364, 5.09655, 300, 5, 1),
(111423, 29849, 571, 1, 1, 0, 7027.13, -1173.88, 932.897, 4.97433, 300, 5, 1),
(111424, 29849, 571, 1, 1, 0, 7013.24, -1182.34, 932.411, 3.69806, 300, 5, 1),
(111425, 29849, 571, 1, 1, 0, 6999.11, -1194.53, 936.442, 1.43219, 300, 5, 1);

DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (29849);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`) VALUES
(29849, 0, 0, 1, 0);

UPDATE `creature` SET `position_x` = 7078.97, `position_y` = -1131.35, `position_z` = 925.048 WHERE `guid` =109886  AND `id`=29844;
UPDATE `creature` SET `position_x` = 7307.64, `position_y` = -1134.12, `position_z` = 939.108 WHERE `guid` =109887  AND `id`=29844;
UPDATE `creature` SET `position_x` = 7276.19, `position_y` = -1107.46, `position_z` = 939.277 WHERE `guid` =109888  AND `id`=29844;
UPDATE `creature` SET `position_x` = 7165.31, `position_y` = -1137.07, `position_z` = 935.830 WHERE `guid` =109892  AND `id`=29844;
UPDATE `creature` SET `position_x` = 7245.94, `position_y` = -1120.80, `position_z` = 941.081 WHERE `guid` =109893  AND `id`=29844;
UPDATE `creature` SET `position_x` = 7225.68, `position_y` = -1067.53, `position_z` = 941.099 WHERE `guid` =109894  AND `id`=29844;
UPDATE `creature` SET `position_x` = 7263.10, `position_y` = -1062.36, `position_z` = 941.915 WHERE `guid` =109895  AND `id`=29844;
UPDATE `creature` SET `position_x` = 7306.59, `position_y` = -1128.36, `position_z` = 938.933 WHERE `guid` =109896  AND `id`=29844;
UPDATE `creature` SET `position_x` = 7265.24, `position_y` = -1071.89, `position_z` = 940.405 WHERE `guid` =109897  AND `id`=29844;
UPDATE `creature` SET `position_x` = 7273.74, `position_y` = -1144.55, `position_z` = 939.401 WHERE `guid` =109898  AND `id`=29844;
UPDATE `creature` SET `position_x` = 7111.39, `position_y` = -1116.59, `position_z` = 923.595 WHERE `guid` =109905  AND `id`=29844;
UPDATE `creature` SET `position_x` = 7115.35, `position_y` = -1141.08, `position_z` = 924.403 WHERE `guid` =109906  AND `id`=29844;
UPDATE `creature` SET `position_x` = 7131.71, `position_y` = -1321.40, `position_z` = 920.302 WHERE `guid` =110318  AND `id`=29849;
UPDATE `creature` SET `position_x` = 7093.36, `position_y` = -1139.74, `position_z` = 922.783 WHERE `guid` =110358  AND `id`=29849;
UPDATE `creature` SET `position_x` = 7279.41, `position_y` = -1092.62, `position_z` = 953.336 WHERE `guid` =110359  AND `id`=29849;
UPDATE `creature` SET `position_x` = 7091.48, `position_y` = -1143.23, `position_z` = 923.195 WHERE `guid` =110360  AND `id`=29849;
UPDATE `creature` SET `position_x` = 7100.66, `position_y` = -1131.79, `position_z` = 925.190 WHERE `guid` =110361  AND `id`=29849;
UPDATE `creature` SET `position_x` = 7303.61, `position_y` = -1112.50, `position_z` = 950.559 WHERE `guid` =110362  AND `id`=29849;
UPDATE `creature` SET `position_x` = 7278.10, `position_y` = -1123.33, `position_z` = 951.022 WHERE `guid` =110363  AND `id`=29849;
UPDATE `creature` SET `position_x` = 7293.52, `position_y` = -1131.73, `position_z` = 950.544 WHERE `guid` =110364  AND `id`=29849;
