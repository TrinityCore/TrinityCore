DELETE FROM `creature` WHERE `guid` IN (73430,73431);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(73430, 25098, 593, 0, 0, 1, 1, 0, 0, 12.02558, 10.74244, 6.469477, 3.209558, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), 
(73431, 25096, 593, 0, 0, 1, 1, 0, 0, 18.07795, 0.47081, 12.1682, 3.162424, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365);

DELETE FROM `gameobject` WHERE `guid` IN (1562,1569,1571,1589,1599,1602,1626,1636,1647);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(1562, 164760, 593, 0, 0, 1, 1, 18.34792, 0.59001, 6.063879, 0.2322455, 0, 0, -0.9304171, 0.3665025, 120, 255, 1, 16057), -- 164760 (Area: -1 - Difficulty: 0)
(1569, 164759, 593, 0, 0, 1, 1, 17.01325, -0.629518, 6.063879, 3.295296, 0, 0, 0.3296909, 0.9440889, 120, 255, 1, 16057), -- 164759 (Area: -1 - Difficulty: 0)
(1571, 164762, 593, 0, 0, 1, 1, 12.8419, -1.879445, 6.09668, 3.295296, 0, 0, 0.3296909, 0.9440889, 120, 255, 1, 16057), -- 164762 (Area: -1 - Difficulty: 0)
(1589, 164765, 593, 0, 0, 1, 1, 5.511603, 10.92695, 6.099214, 0.2322455, 0, 0, -0.9304171, 0.3665025, 120, 255, 1, 16057), -- 164765 (Area: -1 - Difficulty: 0)
(1599, 164767, 593, 0, 0, 1, 1, 39.21275, -2.40047, 6.098139, 5.302423, 0, 0, 0.9733791, 0.2292009, 120, 255, 1, 16057), -- 164767 (Area: -1 - Difficulty: 0)
(1602, 164761, 593, 0, 0, 1, 1, 14.22247, -0.64533, 6.09668, 0.2322455, 0, 0, -0.9304171, 0.3665025, 120, 255, 1, 16057), -- 164761 (Area: -1 - Difficulty: 0)
(1626, 164763, 593, 0, 0, 1, 1, 11.21061, 2.858814, 6.096821, 1.113635, 0, 0, -0.6851826, 0.7283714, 120, 255, 1, 16057), -- 164763 (Area: -1 - Difficulty: 0)
(1636, 164766, 593, 0, 0, 1, 1, 4.394278, 9.889936, 6.099214, 3.295296, 0, 0, 0.3296909, 0.9440889, 120, 255, 1, 16057), -- 164766 (Area: -1 - Difficulty: 0)
(1647, 164764, 593, 0, 0, 1, 1, 11.28877, 1.079107, 6.096821, 4.176688, 0, 0, 0.7009096, 0.7132501, 120, 255, 1, 16057); -- 164764 (Area: -1 - Difficulty: 0)

DELETE FROM `creature_template_addon` WHERE `entry` IN (25098);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`) VALUES
(25098, 0, 0, 3, 1);
