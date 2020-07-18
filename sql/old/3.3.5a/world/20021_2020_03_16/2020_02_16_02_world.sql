-- 
DELETE FROM `creature` WHERE `guid` IN (125720, 125763, 125764, 125765, 125912, 125913, 125914, 125915);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `npcflag`, `MovementType`) VALUES
(125720, 18242, 534, 1, 1, 0, 0, 5613.96, -2864.49, 1617.05, 0.488692, 604800, 0, 0, 0, 0, 0, 0),
(125763, 18242, 534, 1, 1, 0, 0, 5536.6, -2813.09, 1607.19, 5.20108, 604800, 0, 0, 0, 0, 0, 0),
(125764, 18242, 534, 1, 1, 0, 0, 5659.94, -2706.53, 1623.12, 6.17846, 604800, 0, 0, 0, 0, 0, 0),
(125765, 18242, 534, 1, 1, 0, 0, 5548.28, -2669.32, 1566.98, 1.69297, 604800, 0, 0, 0, 0, 0, 0),
(125912, 18242, 534, 1, 1, 0, 0, 5511.56, -2613.27, 1571.1, 4.95674, 604800, 0, 0, 0, 0, 0, 0),
(125913, 18242, 534, 1, 1, 0, 0, 5395.46, -2701, 1591.39, 1.3439, 604800, 0, 0, 0, 0, 0, 0),
(125914, 18410, 534, 1, 1, 0, 0, 5051.43, -1820.68, 1331.49, 2.75762, 604800, 0, 0, 0, 0, 0, 0),
(125915, 18410, 534, 1, 1, 0, 0, 5052.48, -1816.86, 1331.29, 3.00197, 604800, 0, 0, 0, 0, 0, 0);

UPDATE `creature_template` SET `flags_extra`=`flags_extra`|128 WHERE `entry`=18410; 
DELETE FROM `creature_template_movement` WHERE `CreatureId`=18242;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`) VALUES
(18242, 0, 0, 1, 0);

UPDATE `creature` SET `position_z`=1495.175 WHERE `guid` IN (53013,53014);
