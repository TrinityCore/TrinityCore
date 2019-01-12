-- 
UPDATE `gameobject_template` SET `ScriptName`="go_fel_crystalforge" WHERE `entry` IN (185920);
DELETE FROM `gameobject` WHERE `guid` IN (6691,6692);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(6691, 185924, 530, 1, 1, 1476.589, 7244.074, 374.3083, 4.4855000, 0, 0, -0.7826071, 0.6225160, 300, 255, 1),
(6692, 185923, 530, 1, 1, 2943.139, 7064.306, 370.4980, 3.5342910, 0, 0, -0.9807854, 0.1950899, 300, 255, 1);

UPDATE `gameobject` SET `id`=185920, `position_x`=1476.498, `position_y`=7247.337, `position_z`=374.3120, `orientation`=4.1538850, `rotation0`=0, `rotation1`=0,`rotation2`=-0.8746195, `rotation3`=0.4848101 WHERE `guid`=150113;
UPDATE `gameobject` SET `position_x`=2944.871, `position_y`=7067.285, `position_z`=370.3803, `orientation`=3.5081170, `rotation0`=0, `rotation1`=0,`rotation2`=-0.9832544, `rotation3`=0.1822380 WHERE `guid`=150112;

UPDATE `creature` SET `position_x`=1476.431, `position_y`=7247.260, `position_z`=376.4296, `orientation`=4.15388300 WHERE `guid`=80435;
UPDATE `creature` SET `position_x`=2944.764, `position_y`=7067.285, `position_z`=372.1829, `orientation`=3.45575200 WHERE `guid`=80436;
