-- 
DELETE FROM `creature_template_addon` WHERE `entry`=17687;
INSERT INTO `creature_template_addon` (`entry`,`auras`) VALUES (17687,"30948");
DELETE FROM `creature` WHERE `guid` IN (100352, 100396, 100410, 100441, 100442, 100443, 100444, 100445, 100446, 100447, 100450, 100451, 100452, 100453, 100454, 100484, 100672, 100703, 100706, 100822);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(100352, 17687, 540, 3714, 0, 3, 1, 0, 0, 286.7629, 316.399, 1.965012, 1.169371, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 14545), -- 17687 (Area: 0 - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(100396, 17687, 540, 3714, 0, 3, 1, 0, 0, 317.0244, 314.4579, 2.02975, 5.288348, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 14545), -- 17687 (Area: 0 - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(100410, 17687, 540, 3714, 0, 3, 1, 0, 0, 286.9402, 316.2039, 1.964008, 4.223697, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 14545), -- 17687 (Area: 0 - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(100441, 17687, 540, 3714, 0, 3, 1, 0, 0, 316.8127, 314.814, 2.029337, 3.857178, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 14545), -- 17687 (Area: 0 - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(100442, 17687, 540, 3714, 0, 3, 1, 0, 0, 352.0042, 316.3595, 2.001488, 1.58825, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 14545), -- 17687 (Area: 0 - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(100443, 17687, 540, 3714, 0, 3, 1, 0, 0, 350.8876, 316.5521, 2.001488, 2.879793, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 14545), -- 17687 (Area: 0 - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(100444, 17687, 540, 3714, 0, 3, 1, 0, 0, 386.8104, 317.3243, 2.027923, 3.01942, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 14545), -- 17687 (Area: 0 - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(100445, 17687, 540, 3714, 0, 3, 1, 0, 0, 367.8506, 316.1104, 2.001498, 2.443461, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 14545), -- 17687 (Area: 0 - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(100446, 17687, 540, 3714, 0, 3, 1, 0, 0, 385.6091, 316.0121, 2.031326, 1.448623, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 14545), -- 17687 (Area: 0 - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(100447, 17687, 540, 3714, 0, 3, 1, 0, 0, 368.8506, 317.1104, 2.001498, 0, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 14545), -- 17687 (Area: 0 - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(100450, 17687, 540, 3714, 0, 3, 1, 0, 0, 406.4982, 315.6375, 2.006488, 4.502949, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 14545), -- 17687 (Area: 0 - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(100451, 17687, 540, 3714, 0, 3, 1, 0, 0, 407.4982, 316.6375, 2.006488, 0, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 14545), -- 17687 (Area: 0 - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(100452, 17687, 540, 3714, 0, 3, 1, 0, 0, 423.6727, 315.7244, 2.025257, 3.612832, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 14545), -- 17687 (Area: 0 - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(100453, 17687, 540, 3714, 0, 3, 1, 0, 0, 443.132, 315.5444, 1.984968, 0, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 14545), -- 17687 (Area: 0 - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(100454, 17687, 540, 3714, 0, 3, 1, 0, 0, 423.0712, 315.5741, 2.026794, 4.869469, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 14545), -- 17687 (Area: 0 - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(100484, 17687, 540, 3714, 0, 3, 1, 0, 0, 442.132, 314.5444, 1.984968, 5.77704, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 14545), -- 17687 (Area: 0 - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(100672, 17687, 540, 3714, 0, 3, 1, 0, 0, 456.4272, 318.2144, 2.026136, 4.590216, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 14545), -- 17687 (Area: 0 - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(100703, 17687, 540, 3714, 0, 3, 1, 0, 0, 476.5404, 317.6434, 2.000301, 0, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 14545), -- 17687 (Area: 0 - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(100706, 17687, 540, 3714, 0, 3, 1, 0, 0, 458.1685, 315.3307, 2.031278, 0.9948376, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 14545), -- 17687 (Area: 0 - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(100822, 17687, 540, 3714, 0, 3, 1, 0, 0, 475.5404, 316.6434, 2.000301, 2.513274, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 14545); -- 17687 (Area: 0 - Difficulty: 0) (Auras: ) (possible waypoints or random movement)

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=30952;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,30952,0,31,3,17687,0,0,'','Spell 30952 targets entry 17687');
