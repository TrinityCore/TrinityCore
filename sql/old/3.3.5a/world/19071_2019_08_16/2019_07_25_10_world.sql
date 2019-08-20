-- 
UPDATE `creature` SET `equipment_id`=1 WHERE `id`=26546;
DELETE FROM `creature` WHERE `id`=26864 AND `guid` IN (113585,113587,113589); 
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(113585, 26864, 571, 0, 0, 1, 1, 0, 1, 3193.5659, -2243.69506, 115.23049, 3.091544, 300, 0, 0, 0, 0, 2, 0, 0, 0, 0),
(113587, 26864, 571, 0, 0, 1, 1, 0, 1, 3193.5659, -2243.69506, 115.23049, 3.091544, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(113589, 26864, 571, 0, 0, 1, 1, 0, 1, 3193.5659, -2243.69506, 115.23049, 3.091544, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0);
 
DELETE FROM `creature_addon` WHERE `guid` IN (113585);
INSERT INTO `creature_addon` (`guid`, `mount`, `path_id`, `bytes1`, `bytes2`, `auras`) VALUES
(113585,14334,1135850,0,1,"");

DELETE FROM `creature_formations` WHERE `leaderGUID` IN (113585,113587,113589);
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(113585,113585,0,0,515,0,0),
(113585,113587,3,45,515,0,0),
(113585,113589,3,3115,515,0,0);

DELETE FROM `waypoint_data` WHERE `id` IN (1135850);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action_chance`) VALUES
(1135850,1,3193.5659, -2243.69506, 115.23049, 3.091544,0,1,100),
(1135850,2,3176.4318, -2244.91455, 114.90446, 3.208351,0,1,100),
(1135850,3,3154.9943, -2238.41235, 113.17456, 2.607521,0,1,100),
(1135850,4,3133.90405, -2199.5310, 114.14094, 1.940928,0,1,100),
(1135850,5,3122.12719, -2152.38085, 103.1086, 1.507960,0,1,100),
(1135850,6,3135.25537, -2113.80908, 95.43421, 1.005305,0,1,100),
(1135850,7,3167.97851, -2069.15844, 89.31834, 0.860006,0,1,100),
(1135850,8,3190.37988, -2054.44238, 87.65277, 0.549774,0,1,100),
(1135850,9,3218.22094, -2038.52783, 87.20703, 0.534066,0,1,100),
(1135850,10,3252.60205, -2016.48144, 88.81650, 0.687219,0,1,100),
(1135850,11,3279.05346, -1981.64172, 98.30316, 0.969962,0,1,100),
(1135850,12,3304.36694, -1962.43872, 107.0400, 0.357351,0,1,100),
(1135850,13,3341.69287, -1955.26806, 114.9020, 0.058899,0,1,100),
(1135850,14,3379.39624, -1987.67993, 123.4115, 5.454592,0,1,100),
(1135850,15,3398.62744, -2013.75439, 127.7247, 5.383905,0,1,100),
(1135850,16,3395.36596, -2031.97412, 127.7789, 4.358967,0,1,100),
(1135850,17,3379.79663, -2059.60961, 125.0345, 4.201886,0,1,100),
(1135850,18,3372.78027, -2084.25390, 122.2462, 4.704535,0,1,100),
(1135850,19,3384.24731, -2130.96899, 124.3825, 4.967642,0,1,100),
(1135850,20,3390.23730, -2164.63403, 123.5395, 4.861615,0,1,100),
(1135850,21,3380.77368, -2190.37841, 120.8110, 4.296131,0,1,100),
(1135850,22,3349.53613, -2211.78491, 119.5261, 3.683521,0,1,100),
(1135850,23,3310.39794, -2238.13159, 115.1967, 3.836673,0,1,100),
(1135850,24,3286.16918, -2254.05346, 113.7245, 3.400777,0,1,100),
(1135850,25,3258.90063, -2251.61279, 114.2374, 3.019859,0,1,100);

UPDATE creature_template SET AIName = 'SmartAI' WHERE entry = 26864;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 26864 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(26864, 0, 0, 0, 0, 0, 100, 0, 3000, 4000, 3000, 4000, 11, 40505, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Conquest Hold Outrider - IC - Cast Cleave');
