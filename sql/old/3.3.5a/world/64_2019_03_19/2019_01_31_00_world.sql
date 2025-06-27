-- 
DELETE FROM `creature` WHERE `guid` IN (97353,97396);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`) VALUES
(97353, 23115, 530, 1, 1, 0, 0, 2336.01, 7298.97, 365.618, 3.55066, 300, 0, 0, 0, 0, 0),
(97396, 23115, 530, 1, 1, 0, 0, 2309.58, 7288.68, 365.617, 0.25198, 300, 0, 0, 0, 0, 0);

UPDATE `creature` SET `position_x`=2341.8366, `position_y`=7240.4658, `position_z`=366.5410, `orientation`=1.481132 WHERE `guid`=78265;
UPDATE `creature` SET `position_x`=2356.8830, `position_y`=7285.9355, `position_z`=365.9563, `orientation`=3.260055 WHERE `guid`=91786; 
UPDATE `creature` SET `position_x`=2338.6767, `position_y`=7337.7290, `position_z`=365.6684, `orientation`=4.467215 WHERE `guid`=91788; 
UPDATE `creature` SET `position_x`=2323.238, `position_y`=7306.7163, `position_z`=365.6184, `orientation`=4.363535 WHERE `guid`=91793;
UPDATE `creature` SET `position_x`=2313.559082, `position_y`=7277.915, `position_z`=369.019073, `orientation`=1.147470 WHERE `guid`=91790;

DELETE FROM `creature_template_movement` WHERE `CreatureId`=23253;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`) VALUES
(23253, 1, 1, 1, 0);
