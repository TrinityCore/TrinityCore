-- Intro event
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-11747,-12819) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-11747,0,0,0,63,0,100,0,0,0,0,0,0,53,0,1832300,0,0,0,2,1,0,0,0,0,0,0,0,0,"Sethekk Guard - On Just Created - Start Waypoint"),
(-11747,0,1,0,4,0,15,0,0,0,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Sethekk Guard - On Aggro - Say Line 0"),
(-11747,0,2,0,0,0,100,0,3600,15700,10900,22100,0,11,33967,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sethekk Guard - In Combat - Cast 'Thunderclap'"),
(-11747,0,3,0,40,0,100,0,2,1832300,0,0,0,17,375,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sethekk Guard - On Waypoint 2 Reached - Set Emote State 375"),

(-12819,0,0,0,63,0,100,0,0,0,0,0,0,53,0,1832301,0,0,0,2,1,0,0,0,0,0,0,0,0,"Sethekk Guard - On Just Created - Start Waypoint"),
(-12819,0,1,0,4,0,15,0,0,0,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Sethekk Guard - On Aggro - Say Line 0"),
(-12819,0,2,0,0,0,100,0,3600,15700,10900,22100,0,11,33967,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sethekk Guard - In Combat - Cast 'Thunderclap'"),
(-12819,0,3,0,40,0,100,0,2,1832301,0,0,0,17,375,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sethekk Guard - On Waypoint 2 Reached - Set Emote State 375");

DELETE FROM `waypoints` WHERE `entry` IN (1832300,1832301);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(1832300,1,37.141327,6.529172,0.007993373,"Sethekk Guard"),
(1832300,2,29.686293,5.346887,0.00626639,"Sethekk Guard"),
(1832301,1,38.076687,-5.005721,0.0066042226,"Sethekk Guard"),
(1832301,2,30.366282,-5.023761,0.0054908236,"Sethekk Guard");

UPDATE `creature` SET `position_x` = 37.3654, `position_y` = 17.3190, `position_z` = 0.00754, `orientation` = 4.69161, `VerifiedBuild` = 12340 WHERE `guid` = 11747 AND `id` = 18323;
UPDATE `creature` SET `position_x` = 40.00073, `position_y` = 16.5379, `position_z` = 0.0079, `orientation` = 4.62331, `VerifiedBuild` = 12340 WHERE `guid` = 12819 AND `id` = 18323;
UPDATE `creature` SET `position_x` = 46.9831, `position_y` = 52.3524, `position_z` = 0.09081, `orientation` = 4.34587, `VerifiedBuild` = 12340 WHERE `guid` = 14324 AND `id` = 18323;
UPDATE `creature` SET `position_x` = 40.1055, `position_y` = 52.9475, `position_z` = 0.09082, `orientation` = 4.93928, `VerifiedBuild` = 12340 WHERE `guid` = 14325 AND `id` = 18323;
UPDATE `creature` SET `position_x` = 27.6608, `position_y` = 76.7641, `position_z` = 0.28654, `orientation` = 2.77507, `VerifiedBuild` = 12340 WHERE `guid` = 14551 AND `id` = 18318;
UPDATE `creature` SET `position_x` = 20.4725, `position_y` = 81.6956, `position_z` = 0.04849, `orientation` = 5.51524, `VerifiedBuild` = 12340 WHERE `guid` = 14558 AND `id` = 18318;
UPDATE `creature` SET `position_x` = 55.5350, `position_y` = 78.7887, `position_z` = -0.00838, `orientation` = 1.29154, `VerifiedBuild` = 12340 WHERE `guid` = 34057 AND `id` = 18327;
UPDATE `creature` SET `position_x` = -3.55374, `position_y` = 97.3215, `position_z` = 0.09051, `orientation` = 0.41887, `VerifiedBuild` = 12340 WHERE `guid` = 14326 AND `id` = 18323;
UPDATE `creature` SET `position_x` = 21.7359, `position_y` = 73.6921, `position_z` = 0.59818, `orientation` = 1.08210, `VerifiedBuild` = 12340 WHERE `guid` = 34051 AND `id` = 18327;
UPDATE `creature` SET `position_x` = 58.4920, `position_y` = 83.4049, `position_z` = 0.22743, `orientation` = 4.32841, `VerifiedBuild` = 12340 WHERE `guid` = 14634 AND `id` = 18318;
UPDATE `creature` SET `position_x` = 43.6360, `position_y` = 106.915, `position_z` = 0.23413, `orientation` = 4.76474, `VerifiedBuild` = 12340 WHERE `guid` = 34059 AND `id` = 18327;
UPDATE `creature` SET `position_x` = 50.9244, `position_y` = 98.9922, `position_z` = 0.23413, `orientation` = 3.10668, `VerifiedBuild` = 12340 WHERE `guid` = 14638 AND `id` = 18318;
UPDATE `creature` SET `position_x` = 11.9274, `position_y` = 102.474, `position_z` = 0.50665, `orientation` = 0.95993, `VerifiedBuild` = 12340 WHERE `guid` = 14561 AND `id` = 18318;
UPDATE `creature` SET `position_x` = 36.5258, `position_y` = 99.3303, `position_z` = 0.23413, `orientation` = 6.26573, `VerifiedBuild` = 12340 WHERE `guid` = 34048 AND `id` = 18318;
UPDATE `creature` SET `position_x` = 90.7533, `position_y` = 96.9339, `position_z` = 0.09051, `orientation` = 2.94960, `VerifiedBuild` = 12340 WHERE `guid` = 14328 AND `id` = 18323;
UPDATE `creature` SET `position_x` = 16.9091, `position_y` = 106.144, `position_z` = 0.50665, `orientation` = 4.45058, `VerifiedBuild` = 12340 WHERE `guid` = 34052 AND `id` = 18327;
UPDATE `creature` SET `position_x` = 81.9067, `position_y` = 112.337, `position_z` = 0.41223, `orientation` = 3.21140, `VerifiedBuild` = 12340 WHERE `guid` = 34056 AND `id` = 18327;
UPDATE `creature` SET `position_x` = 90.7193, `position_y` = 104.321, `position_z` = 0.18600, `orientation` = 3.56047, `VerifiedBuild` = 12340 WHERE `guid` = 14329 AND `id` = 18323;
UPDATE `creature` SET `position_x` = -3.69868, `position_y` = 103.477, `position_z` = 0.09051, `orientation` = 6.17846, `VerifiedBuild` = 12340 WHERE `guid` = 14327 AND `id` = 18323;
UPDATE `creature` SET `position_x` = 47.7679, `position_y` = 130.485, `position_z` = 0.17382, `orientation` = 4.83456, `VerifiedBuild` = 12340 WHERE `guid` = 14331 AND `id` = 18323;
UPDATE `creature` SET `position_x` = 41.9870, `position_y` = 130.146, `position_z` = 0.18618, `orientation` = 5.11381, `VerifiedBuild` = 12340 WHERE `guid` = 14330 AND `id` = 18323;
UPDATE `creature` SET `position_x` = 75.8563, `position_y` = 116.046, `position_z` = 0.35000, `orientation` = 5.56760, `VerifiedBuild` = 12340 WHERE `guid` = 14579 AND `id` = 18318;
UPDATE `creature` SET `position_x` = -51.8654, `position_y` = 110.682, `position_z` = 0.09053, `orientation` = 3.78736, `VerifiedBuild` = 12340 WHERE `guid` = 38975 AND `id` = 18328;
UPDATE `creature` SET `position_x` = -58.0165, `position_y` = 107.974, `position_z` = 0.09053, `orientation` = 1.55334, `VerifiedBuild` = 12340, `id` = 18318 WHERE `guid` = 34060 AND `id` = 18327; -- 18318
UPDATE `creature` SET `position_x` = -60.3833, `position_y` = 114.663, `position_z` = 0.09053, `orientation` = 5.68977, `VerifiedBuild` = 12340, `id` = 18327 WHERE `guid` = 39818 AND `id` = 18328; -- 18327
UPDATE `creature` SET `position_x` = -66.4524, `position_y` = 131.135, `position_z` = 0.09054, `orientation` = 4.85201, `VerifiedBuild` = 12340 WHERE `guid` = 14543 AND `id` = 18323;
UPDATE `creature` SET `position_x` = -76.5689, `position_y` = 83.7339, `position_z` = 0.09053, `orientation` = 0.78539, `VerifiedBuild` = 12340 WHERE `guid` = 39819 AND `id` = 18328;
UPDATE `creature` SET `position_x` = -69.1324, `position_y` = 83.7427, `position_z` = 0.09053, `orientation` = 2.82743, `VerifiedBuild` = 12340 WHERE `guid` = 34061 AND `id` = 18327;
UPDATE `creature` SET `position_x` = -76.1874, `position_y` = 89.6284, `position_z` = 0.09053, `orientation` = 5.68977, `VerifiedBuild` = 12340 WHERE `guid` = 39820 AND `id` = 18328;
UPDATE `creature` SET `position_x` = -75.2176, `position_y` = 130.818, `position_z` = 0.09053, `orientation` = 4.92182, `VerifiedBuild` = 12340 WHERE `guid` = 14332 AND `id` = 18323;
UPDATE `creature` SET `position_x` = -86.2175, `position_y` = 107.356, `position_z` = 0.08998, `orientation` = 0.78539, `VerifiedBuild` = 12340 WHERE `guid` = 40191 AND `id` = 18328;
UPDATE `creature` SET `position_x` = -83.8602, `position_y` = 113.572, `position_z` = 0.09052, `orientation` = 5.82939, `VerifiedBuild` = 12340, `id` = 18328 WHERE `guid` = 35868 AND `id` = 18327; -- 18328
UPDATE `creature` SET `position_x` = -80.6658, `position_y` = 105.136, `position_z` = 0.09053, `orientation` = 2.32128, `VerifiedBuild` = 12340, `id` = 18327 WHERE `guid` = 34049 AND `id` = 18318; -- 18327
UPDATE `creature` SET `position_x` = -65.7625, `position_y` = 167.779, `position_z` = 0.09317, `orientation` = 3.40339, `VerifiedBuild` = 12340 WHERE `guid` = 36693 AND `id` = 18327;
UPDATE `creature` SET `position_x` = -75.4351, `position_y` = 173.650, `position_z` = 0.09302, `orientation` = 5.81194, `VerifiedBuild` = 12340 WHERE `guid` = 43422 AND `id` = 18328;
UPDATE `creature` SET `position_x` = -68.5953, `position_y` = 173.012, `position_z` = 0.09284, `orientation` = 4.17133, `VerifiedBuild` = 12340 WHERE `guid` = 43280 AND `id` = 18328;
UPDATE `creature` SET `position_x` = -102.480, `position_y` = 170.060, `position_z` = 0.09323, `orientation` = 0.48869, `VerifiedBuild` = 12340 WHERE `guid` = 14544 AND `id` = 18323;
UPDATE `creature` SET `position_x` = -102.428, `position_y` = 177.586, `position_z` = 0.09321, `orientation` = 6.16101, `VerifiedBuild` = 12340 WHERE `guid` = 14547 AND `id` = 18323;
UPDATE `creature` SET `position_x` = -144.826, `position_y` = 173.557, `position_z` = 1.76864, `orientation` = 0.06981, `VerifiedBuild` = 12340 WHERE `guid` = 83270 AND `id` = 18472;
UPDATE `creature` SET `position_x` = -89.9676, `position_y` = 262.709, `position_z` = 26.9184, `orientation` = 2.11184, `VerifiedBuild` = 12340 WHERE `guid` = 12163 AND `id` = 18325;
UPDATE `creature` SET `position_x` = -84.3041, `position_y` = 266.641, `position_z` = 26.8912, `orientation` = 3.00196, `VerifiedBuild` = 12340, `id` = 18319 WHERE `guid` = 12161 AND `id` = 18325; -- 18319
UPDATE `creature` SET `position_x` = -118.563, `position_y` = 266.142, `position_z` = 27.1712, `orientation` = 2.35619, `VerifiedBuild` = 12340, `id` = 18325 WHERE `guid` = 49348 AND `id` = 18319; -- 18325
UPDATE `creature` SET `position_x` = -114.000, `position_y` = 268.488, `position_z` = 26.8761, `orientation` = 2.47836, `VerifiedBuild` = 12340 WHERE `guid` = 83283 AND `id` = 18320;
UPDATE `creature` SET `position_x` = -205.540, `position_y` = 169.512, `position_z` = 0.09433, `orientation` = 0.15707, `VerifiedBuild` = 12340 WHERE `guid` = 83294 AND `id` = 18322;
UPDATE `creature` SET `position_x` = -205.417, `position_y` = 176.436, `position_z` = 0.09436, `orientation` = 6.07374, `VerifiedBuild` = 12340 WHERE `guid` = 83259 AND `id` = 18322;
UPDATE `creature` SET `position_x` = -123.771, `position_y` = 270.042, `position_z` = 27.3311, `orientation` = 1.02974, `VerifiedBuild` = 12340 WHERE `guid` = 83289 AND `id` = 18325;
UPDATE `creature` SET `position_x` = -241.915, `position_y` = 155.992, `position_z` = 0.14559, `orientation` = 1.78023, `VerifiedBuild` = 12340, `id` = 18319 WHERE `guid` = 38931 AND `id` = 18327; -- 18319
UPDATE `creature` SET `position_x` = -239.392, `position_y` = 211.817, `position_z` = 26.9013, `orientation` = 4.53785, `VerifiedBuild` = 12340 WHERE `guid` = 83298 AND `id` = 18322;
UPDATE `creature` SET `position_x` = -246.218, `position_y` = 159.874, `position_z` = 0.15129, `orientation` = 0.38397, `VerifiedBuild` = 12340, `id` = 18328 WHERE `guid` = 38664 AND `id` = 18327; -- 18328
UPDATE `creature` SET `position_x` = -245.400, `position_y` = 164.806, `position_z` = 0.15277, `orientation` = 0.03490, `VerifiedBuild` = 12340, `id` = 18319 WHERE `guid` = 45074 AND `id` = 18328; -- 18319
UPDATE `creature` SET `position_x` = -246.162, `position_y` = 212.184, `position_z` = 26.8224, `orientation` = 4.76474, `VerifiedBuild` = 12340 WHERE `guid` = 83280 AND `id` = 18322;
UPDATE `creature` SET `position_x` = -266.165, `position_y` = 190.070, `position_z` = 0.11723, `orientation` = 5.68977, `VerifiedBuild` = 12340 WHERE `guid` = 48962 AND `id` = 18319;
UPDATE `creature` SET `position_x` = -259.192, `position_y` = 191.827, `position_z` = 0.11991, `orientation` = 5.41052, `VerifiedBuild` = 12340 WHERE `guid` = 45076 AND `id` = 18328;
UPDATE `creature` SET `position_x` = -268.488, `position_y` = 184.285, `position_z` = 0.11721, `orientation` = 0.61086, `VerifiedBuild` = 12340 WHERE `guid` = 48441 AND `id` = 18319;
UPDATE `creature` SET `position_x` = -185.436, `position_y` = 281.247, `position_z` = 26.6656, `orientation` = 0.99483, `VerifiedBuild` = 12340 WHERE `guid` = 83293 AND `id` = 18325;
UPDATE `creature` SET `position_x` = -178.803, `position_y` = 276.965, `position_z` = 26.7434, `orientation` = 1.81514, `VerifiedBuild` = 12340, `id` = 18326 WHERE `guid` = 83291 AND `id` = 18325; -- 18326
UPDATE `creature` SET `position_x` = -171.080, `position_y` = 282.286, `position_z` = 26.7049, `orientation` = 3.07177, `VerifiedBuild` = 12340 WHERE `guid` = 49161 AND `id` = 18319;
UPDATE `creature` SET `position_x` = -230.616, `position_y` = 330.518, `position_z` = 27.4382, `orientation` = 3.17649, `VerifiedBuild` = 12340 WHERE `guid` = 83295 AND `id` = 18325;
UPDATE `creature` SET `position_x` = -203.842, `position_y` = 336.054, `position_z` = 26.7194, `orientation` = 2.37364, `VerifiedBuild` = 12340 WHERE `guid` = 83292 AND `id` = 18325;
UPDATE `creature` SET `position_x` = -234.595, `position_y` = 335.917, `position_z` = 27.3780, `orientation` = 4.18879, `VerifiedBuild` = 12340, `id` = 18326 WHERE `guid` = 83297 AND `id` = 18325; -- 18326
UPDATE `creature` SET `position_x` = -240.964, `position_y` = 336.163, `position_z` = 27.2411, `orientation` = 5.21853, `VerifiedBuild` = 12340 WHERE `guid` = 49153 AND `id` = 18319;
UPDATE `creature` SET `position_x` = -202.409, `position_y` = 343.724, `position_z` = 26.7194, `orientation` = 3.71755, `VerifiedBuild` = 12340 WHERE `guid` = 12160 AND `id` = 18325;
UPDATE `creature` SET `position_x` = -210.945, `position_y` = 343.907, `position_z` = 26.7194, `orientation` = 5.00909, `VerifiedBuild` = 12340 WHERE `guid` = 49159 AND `id` = 18319;
UPDATE `creature` SET `position_x` = -141.666, `position_y` = 283.046, `position_z` = 26.8141, `orientation` = 2.77507, `VerifiedBuild` = 12340 WHERE `guid` = 83299 AND `id` = 18322;
UPDATE `creature` SET `position_x` = -141.136, `position_y` = 291.284, `position_z` = 26.8141, `orientation` = 3.78736, `VerifiedBuild` = 12340 WHERE `guid` = 83296 AND `id` = 18322;
UPDATE `creature` SET `position_x` = -101.463, `position_y` = 301.913, `position_z` = 26.5678, `orientation` = 2.09439, `VerifiedBuild` = 12340 WHERE `guid` = 83290 AND `id` = 18325;
UPDATE `creature` SET `position_x` = -101.329, `position_y` = 309.882, `position_z` = 26.6085, `orientation` = 5.81194, `VerifiedBuild` = 12340, `id` = 18326 WHERE `guid` = 49353 AND `id` = 18319; -- 18326
UPDATE `creature` SET `position_x` = -93.7429, `position_y` = 315.541, `position_z` = 26.5576, `orientation` = 4.45058, `VerifiedBuild` = 12340 WHERE `guid` = 49354 AND `id` = 18319; -- 18320
UPDATE `creature` SET `position_x` = -82.0579, `position_y` = 273.057, `position_z` = 26.8912, `orientation` = 3.82227, `VerifiedBuild` = 12340 WHERE `guid` = 83278 AND `id` = 18320;
UPDATE `creature` SET `position_x` = -59.5876, `position_y` = 304.910, `position_z` = 26.6239, `orientation` = 3.17649, `VerifiedBuild` = 12340 WHERE `guid` = 83287 AND `id` = 18325;
UPDATE `creature` SET `position_x` = -60.1442, `position_y` = 311.665, `position_z` = 27.2029, `orientation` = 3.87463, `VerifiedBuild` = 12340, `id` = 18319 WHERE `guid` = 83268 AND `id` = 18326; -- 18319
UPDATE `creature` SET `position_x` = -66.5131, `position_y` = 314.623, `position_z` = 27.1160, `orientation` = 4.57276, `VerifiedBuild` = 12340 WHERE `guid` = 83281 AND `id` = 18320;
UPDATE `creature` SET `position_x` = -49.5232, `position_y` = 280.174, `position_z` = 26.9464, `orientation` = 2.63544, `VerifiedBuild` = 12340, `id` = 18319 WHERE `guid` = 83285 AND `id` = 18325; -- 18319
UPDATE `creature` SET `position_x` = -58.9359, `position_y` = 280.053, `position_z` = 26.9993, `orientation` = 1.72787, `VerifiedBuild` = 12340 WHERE `guid` = 83282 AND `id` = 18320;
UPDATE `creature` SET `position_x` = -51.7740, `position_y` = 285.914, `position_z` = 26.9791, `orientation` = 4.31096, `VerifiedBuild` = 12340 WHERE `guid` = 83284 AND `id` = 18325;
UPDATE `creature` SET `position_x` = -10.1304, `position_y` = 292.403, `position_z` = 26.8139, `orientation` = 3.38593, `VerifiedBuild` = 12340 WHERE `guid` = 12162 AND `id` = 18321;
UPDATE `creature` SET `position_x` = -1.86748, `position_y` = 284.605, `position_z` = 26.7796, `orientation` = 3.00196, `VerifiedBuild` = 12340 WHERE `guid` = 83269 AND `id` = 18326;
UPDATE `creature` SET `position_x` = -10.1333, `position_y` = 281.478, `position_z` = 26.8139, `orientation` = 2.79252, `VerifiedBuild` = 12340 WHERE `guid` = 83279 AND `id` = 18320;
UPDATE `creature` SET `position_x` = -1.16488, `position_y` = 289.905, `position_z` = 26.7753, `orientation` = 3.21140, `VerifiedBuild` = 12340 WHERE `guid` = 83286 AND `id` = 18325;
UPDATE `creature` SET `position_x` = 44.7227, `position_y` = 286.959, `position_z` = 25.1521, `orientation` = 3.97935, `VerifiedBuild` = 12340 WHERE `guid` = 83300 AND `id` = 18473;
UPDATE `creature` SET `VerifiedBuild` = 12340 WHERE `id` = 18956;

DELETE FROM `creature_addon` WHERE `guid` IN (86010,34050);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`) VALUES
(86010,860100,0,0,0,0),
(34050,340500,0,0,1,0);

DELETE FROM `creature` WHERE `guid` = 86010 AND `id` = 19429;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `MovementType`) VALUES
(86010, 19429, 556, 3, 1, 0, -65.0119, 92.5564, 0.00720, 5.58499, 10800, 0, 2);

DELETE FROM `creature_formations` WHERE `leaderGUID` = 83248;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(83248,83248,0,0,515,0,0),
(83248,83246,3,270,515,0,0);

UPDATE `creature` SET `position_x` = 58.7418, `position_y` = 87.6379, `position_z` = 0.13519 WHERE `guid` = 83247 AND `id` = 19429;
UPDATE `creature` SET `position_x` = 80.2743, `position_y` = 108.831, `position_z` = 0.23825 WHERE `guid` = 83250 AND `id` = 19429;
UPDATE `creature` SET `position_x` = 19.2082, `position_y` = 102.300, `position_z` = 0.42331 WHERE `guid` = 83249 AND `id` = 19429;
UPDATE `creature` SET `position_x` = -84.3435, `position_y` = 100.637, `position_z` = 0.00719 WHERE `guid` = 83253 AND `id` = 19429;
UPDATE `creature` SET `position_x` = -116.365, `position_y` = 177.982, `position_z` = 0.01076 WHERE `guid` = 83263 AND `id` = 19429;
UPDATE `creature` SET `position_x` = -228.454, `position_y` = 151.974, `position_z` = 0.04820 WHERE `guid` = 83251 AND `id` = 19428;
UPDATE `creature` SET `position_x` = -221.885, `position_y` = 141.751, `position_z` = 26.7643 WHERE `guid` = 83255 AND `id` = 19428;
UPDATE `creature` SET `position_x` = -190.379, `position_y` = 310.375, `position_z` = 26.7304 WHERE `guid` = 83257 AND `id` = 19428;
UPDATE `creature` SET `position_x` = -87.8775, `position_y` = 294.357, `position_z` = 26.4831 WHERE `guid` = 83264 AND `id` = 19428;
UPDATE `creature` SET `position_x` = -239.229, `position_y` = 168.255, `position_z` = -0.08834 WHERE `guid` = 83252 AND `id` = 18318;
UPDATE `creature` SET `position_x` = -258.260, `position_y` = 182.913, `position_z` = 0.03933, `MovementType` = 2 WHERE `guid` = 34050 AND `id` = 18318;
UPDATE `creature` SET `position_x` = 44.9587, `position_y` = 30.4703, `position_z` = 0.00748, `orientation` = 5.07581, `VerifiedBuild` = 12340 WHERE `guid` = 83248 AND `id` = 18318;
UPDATE `creature` SET `position_x` = 47.7743, `position_y` = 31.5427, `position_z` = 0.00747, `orientation` = 5.06279, `VerifiedBuild` = 12340 WHERE `guid` = 83246 AND `id` = 19429;

DELETE FROM `waypoint_data` WHERE `id` IN (832470,832500,832490,832530,832630,832510,832550,832570,832640,860100,832520,340500,832480);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`) VALUES
(832470,1,58.741856,87.63797,0.13519223),
(832470,2,61.541374,86.465836,0.11625819),
(832470,3,61.60423,82.89358,0.11962952),
(832470,4,59.79479,78.14727,0.10969375),
(832470,5,53.405872,74.830986,-0.3410233),
(832470,6,50.29865,78.00863,-0.6153243),
(832470,7,54.01891,84.57008,0.15080427),
(832500,1,80.27435,108.83183,0.23825333),
(832500,2,75.21125,111.69642,0.2993702),
(832500,3,72.856766,115.09385,-0.0014561549),
(832500,4,73.79264,119.72423,0.1015589),
(832500,5,79.69893,120.26302,0.3618002),
(832500,6,83.93823,118.20135,0.3618002),
(832500,7,85.99174,111.83964,0.26977184),
(832490,1,19.20821,102.30094,0.42331755),
(832490,2,20.980625,105.93845,0.39092496),
(832490,3,19.295076,110.83514,0.41467458),
(832490,4,13.302068,114.14034,0.37624317),
(832490,5,7.753703,108.07671,0.2779381),
(832490,6,9.309584,99.447,0.33932894),
(832490,7,16.262775,99.27335,0.39650914),
(832530,1,-84.34352,100.63735,0.007198175),
(832530,2,-78.54362,101.022156,0.0072023305),
(832530,3,-74.85056,105.95508,0.4666742),
(832530,4,-75.15681,110.50211,0.0071987635),
(832530,5,-76.439835,115.81949,0.007886883),
(832530,6,-80.21233,119.24259,0.006932758),
(832530,7,-85.321724,118.76939,0.006174665),
(832530,8,-89.15545,112.78256,0.007203141),
(832530,9,-88.99241,105.29069,0.0070886714),
(832630,1,-116.365585,177.98293,0.01076872),
(832630,2,-109.954,174.63242,-0.0012249516),
(832630,3,-100.3579,174.42007,0.009782679),
(832630,4,-85.897484,176.81961,0.009938575),
(832630,5,-73.72114,166.32028,0.007517383),
(832630,6,-70.667145,154.24731,0.0066392813),
(832630,7,-65.95061,145.78908,0.006454454),
(832630,8,-70.65206,140.3833,0.006873957),
(832630,9,-74.04532,145.97528,0.006497793),
(832630,10,-71.2645,154.09944,0.0066223834),
(832630,11,-74.607475,165.30824,0.0074038883),
(832630,12,-84.76448,171.64992,0.010449618),
(832630,13,-109.90472,173.86609,0.010785582),
(832630,14,-118.04346,168.02657,-0.035944138),
(832630,15,-124.33573,173.15886,0.010768358),
(832510,1,-228.45494,151.97469,0.048201732),
(832510,2,-226.6313,167.8625,-0.19895583),
(832510,3,-239.73395,171.82242,-0.026919188),
(832510,4,-253.77058,180.43588,0.03831912),
(832510,5,-250.03156,189.5389,0.043777704),
(832510,6,-244.20546,198.88652,0.06436035),
(832510,7,-250.03156,189.5389,0.043777704),
(832510,8,-253.77058,180.43588,0.03831912),
(832510,9,-239.73395,171.82242,-0.026919188),
(832510,10,-226.6313,167.8625,-0.19895583),
(832550,1,-221.88576,141.7515,26.764345),
(832550,2,-214.89592,150.32657,26.87621),
(832550,3,-212.5275,168.4632,26.758505),
(832550,4,-214.3615,200.47395,26.72269),
(832550,5,-226.15234,205.7063,27.346067),
(832550,6,-254.78401,204.45663,26.815353),
(832550,7,-277.5177,205.64934,26.722033),
(832550,8,-254.78401,204.45663,26.815353),
(832550,9,-226.15234,205.7063,27.346067),
(832550,10,-214.3615,200.47395,26.72269),
(832550,11,-212.5275,168.4632,26.758505),
(832550,12,-214.89592,150.32657,26.87621),
(832550,13,-221.88576,141.7515,26.764345),
(832550,14,-242.04726,141.69954,26.76713),
(832550,15,-259.61993,141.33737,13.577376),
(832550,16,-269.01578,144.18152,13.579221),
(832550,17,-271.80103,152.93188,13.523027),
(832550,18,-272.65973,170.79295,0.056994315),
(832550,19,-271.80103,152.93188,13.523027),
(832550,20,-269.01578,144.18152,13.579221),
(832550,21,-259.61993,141.33737,13.577376),
(832550,22,-242.04726,141.69954,26.76713),
(832570,1,-190.37943,310.37537,26.730482),
(832570,2,-177.13202,295.49243,26.607801),
(832570,3,-162.5813,290.58685,26.731392),
(832570,4,-141.12387,286.8888,26.732378),
(832570,5,-162.5813,290.58685,26.731392),
(832570,6,-177.13202,295.49243,26.607801),
(832570,7,-190.3777,310.3732,26.730482),
(832570,8,-207.03102,331.1477,26.649204),
(832570,9,-217.97969,333.11343,26.964346),
(832570,10,-232.11073,317.8273,26.773405),
(832570,11,-242.61,300.808,26.731), -- not sniffed
(832570,12,-232.11073,317.8273,26.773405),
(832570,13,-217.97969,333.11343,26.964346),
(832570,14,-207.03102,331.1477,26.649204),
(832640,1,-87.87755,294.3571,26.483166),
(832640,2,-83.39741,292.72406,26.483166),
(832640,3,-80.96503,288.0274,26.483166),
(832640,4,-82.98266,283.50995,26.483166),
(832640,5,-88.02411,281.53787,26.483166),
(832640,6,-91.87087,283.9528,26.483166),
(832640,7,-93.46641,287.88614,26.483166),
(832640,8,-91.99382,291.9729,26.483166),
(860100,1,-65.01194,92.55649,0.0072021014),
(860100,2,-59.58082,96.96696,0.021822702),
(860100,3,-61.12924,104.628075,0.0072018215),
(860100,4,-69.39115,111.7542,0.00720282),
(860100,5,-75.57139,107.86683,0.0072000534),
(860100,6,-79.04226,99.95164,0.007202108),
(860100,7,-77.11786,94.87296,0.0072032358),
(860100,8,-72.23981,90.77932,0.0072050625),
(832520,1,-239.22995,168.25558,-0.088342115),
(832520,2,-245.3342,170.36398,0.04497503),
(832520,3,-239.22995,168.25558,-0.088342115),
(832520,4,-238.53963,160.60075,-0.12405232),
(340500,1,-258.26074,182.91333,0.039339855),
(340500,2,-264.9457,179.76292,0.033908542),
(340500,3,-258.26074,182.91333,0.039339855),
(340500,4,-255.95424,188.71451,0.04281207),
(832480,1,47.015766,25.06157,0.0074763903),
(832480,2,47.217983,9.030255,0.005024758),
(832480,3,39.303646,0.663297,0.0070958724),
(832480,4,36.73842,10.677114,0.008318759),
(832480,5,40.667316,20.894041,0.008027105),
(832480,6,38.962692,30.885172,0.0074734767),
(832480,7,39.64863,40.192886,0.0074779084),
(832480,8,45.314354,37.101177,0.0074783196);

UPDATE `waypoint_data` SET `move_type` = 1 WHERE `id` = 832630;
