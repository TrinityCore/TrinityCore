-- 
DELETE FROM `creature` WHERE `guid` IN (62834, 62835, 98350, 98351, 98352, 98353, 98354, 98355, 98401, 98473, 98492, 98690);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(62834, 16523, 540, 3714, 0, 3, 1, 0, 1, 52.12558, 7.037765, -13.21108, 3.559009, 7200, 0, 0, 0, 0, 2, 0, 0, 0, 14545), -- 16523 (Area: 0 - Difficulty: 0) (Auras: ) (possible waypoints or random movement) -- w
(62835, 16523, 540, 3714, 0, 3, 1, 0, 1, 64.49474, 7.92366, -13.21286, 4.465342, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- 16523 (Area: 0 - Difficulty: 0) (Auras: ) (possible waypoints or random movement) -- w
(98350, 16523, 540, 3714, 0, 3, 1, 0, 1, 60.28706, 14.17206, -13.218425, 3.656394, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- 16523 (Area: 0 - Difficulty: 0) (Auras: ) (possible waypoints or random movement) -- w
(98351, 16523, 540, 3714, 0, 3, 1, 0, 1, 69.60132, 39.09185, -13.2298, 4.928814, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- 16523 (Area: 0 - Difficulty: 0) (Auras: ) (possible waypoints or random movement) 
(98352, 16523, 540, 3714, 0, 3, 1, 0, 1, 83.66965, 57.30761, -13.12304, 2.924044, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- 16523 (Area: 0 - Difficulty: 0) (Auras: ) (possible waypoints or random movement) 
(98353, 16523, 540, 3714, 0, 3, 1, 0, 1, 56.92235, 57.60813, -13.12201, 5.776028, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- 16523 (Area: 0 - Difficulty: 0) (Auras: ) (possible waypoints or random movement) 
(98354, 16523, 540, 3714, 0, 3, 1, 0, 1, 65.6893, 12.66022, -13.21543, 4.465342, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- 16523 (Area: 0 - Difficulty: 0) (Auras: ) (possible waypoints or random movement) -- w
(98355, 16523, 540, 3714, 0, 3, 1, 0, 1, 82.67202, 268.09982, -13.214333, 3.926327, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- 16523 (Area: 0 - Difficulty: 0) (Auras: ) 
(98401, 16523, 540, 3714, 0, 3, 1, 0, 1, 512.338623, 172.70694, 1.94192, 1.51526, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- 16523 (Area: 0 - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(98473, 16523, 540, 3714, 0, 3, 1, 0, 1, 525.183655, 171.85939, 1.94192, 1.51526, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- 16523 (Area: 0 - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(98492, 16523, 540, 3714, 0, 3, 1, 0, 1, 524.7359, 120.8698, 1.99425, 1.51526, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- 16523 (Area: 0 - Difficulty: 0) (Auras:) 
(98690, 16523, 540, 3714, 0, 3, 1, 0, 1, 514.6008, 120.4596, 1.992567, 1.51526, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 14545); -- 16523 (Area: 0 - Difficulty: 0) (Auras: ) 

DELETE FROM `creature_formations` WHERE `leaderGUID` IN (62834,62835,98354,98350) AND `memberGUID` IN(62834,62835,98354,98350);
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(62834, 62834, 0, 0, 515, 2, 0),
(62834, 62835, 4, 90, 515, 2, 0),
(62834, 98354, 4, 270, 515, 2, 0),
(62834, 98350, 4, 0, 515, 2, 0);

DELETE FROM `creature_addon` WHERE `guid`=62834;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`) VALUES
(62834,628340,1);

DELETE FROM `waypoint_data` WHERE `id`=628340;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(628340,1,52.125599, 7.037770, -13.21110,0,1,0,100,0),
(628340,2,39.461937, 3.218714, -13.20408,0,1,0,100,0),
(628340,3,26.630924, 2.785303, -13.19860,0,1,0,100,0),
(628340,4,10.768260, 2.387241, -13.21622,0,1,0,100,0),
(628340,5,-5.274332, 1.868668, -13.19611,60000,1,0,100,0);
