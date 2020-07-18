-- 
DELETE FROM `creature` WHERE `guid` IN (77853,78323,95101,95102,95103,95107);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`) VALUES
(77853, 22255, 530, 1, 1, 0, 0, 4044.39, 4848.37, 267.912, 1.97832, 600, 5, 0, 0, 0, 1),
(78323, 22255, 530, 1, 1, 0, 0, 3962.94, 5013.71, 269.379, 1.85658, 600, 5, 0, 0, 0, 1),
(95101, 22255, 530, 1, 1, 0, 0, 3902.38, 5335.72, 267.349, 5.92102, 600, 5, 0, 0, 0, 1),
(95102, 22255, 530, 1, 1, 0, 0, 3893.24, 5408.77, 267.984, 6.16056, 600, 5, 0, 0, 0, 1),
(95103, 22255, 530, 1, 1, 0, 0, 4125.15, 5514.87, 269.577, 0.59601, 600, 5, 0, 0, 0, 1),
(95107, 22255, 530, 1, 1, 0, 0, 3861.98, 5778.68, 266.847, 4.50730, 600, 5, 0, 0, 0, 1);

DELETE FROM `creature_template_addon` WHERE entry = 22255;
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES
(22255, "32942");
