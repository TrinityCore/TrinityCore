-- 
DELETE FROM `creature` WHERE `id`  IN (23705) AND `guid` IN (111028, 111029, 111030, 111031, 111032, 111033);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`) VALUES
(111028, 23705, 530, 0, 0, 1, 1, 0, 1, 6729.76, -7549.41, 130.142, 2.18166, 600, 0, 0, 0, 0, 0),
(111029, 23705, 530, 0, 0, 1, 1, 0, 1, 6772.59, -7553.14, 127.129, 3.87463, 600, 0, 0, 0, 0, 0),
(111030, 23705, 530, 0, 0, 1, 1, 0, 1, 6745.69, -7636.87, 127.306, 5.84685, 600, 0, 0, 0, 0, 0),
(111031, 23705, 530, 0, 0, 1, 1, 0, 1, 6770.60, -7614.27, 128.680, 5.75959, 600, 0, 0, 0, 0, 0),
(111032, 23705, 530, 0, 0, 1, 1, 0, 1, 6761.84, -7667.97, 126.544, 2.35619, 600, 0, 0, 0, 0, 0),
(111033, 23705, 530, 0, 0, 1, 1, 0, 1, 6736.81, -7576.37, 126.822, 5.55494, 600, 0, 0, 0, 0, 0);

DELETE FROM `creature_template_addon` WHERE `entry`=23705;
INSERT INTO `creature_template_addon` (`entry`, `bytes2`, `auras`) VALUES (23705,1,"29266");
