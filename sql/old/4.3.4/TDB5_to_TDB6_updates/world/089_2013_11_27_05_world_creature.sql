SET @CGUID := 206;
DELETE FROM `creature` WHERE `id` IN (31804,31805,31807);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
-- Transport_Moa'ki_Unu'pe
(@CGUID+0, 31807, 620, 1, 1, -19.87627, -0.049722, 17.61058, 2.86234, 120, 0, 0),
(@CGUID+1, 31805, 620, 1, 1, 8.109375, -1.96228, 15.83483, 3.224337, 120, 0, 0),

-- Transport_Moa'ki_Kamagua
(@CGUID+2, 31804, 621, 1, 1, 14.08325, 1.959717, 18.8097, 3.735005, 120, 0, 0);


DELETE FROM `creature_template_addon` WHERE `entry` IN (31804,31805,31807);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(31807, 0, 0x0, 0x1, ''),
(31805, 0, 0x0, 0x101, ''),
(31804, 0, 0x0, 0x101, '');
