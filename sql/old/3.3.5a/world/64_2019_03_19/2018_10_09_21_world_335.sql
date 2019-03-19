-- 
DELETE FROM `creature` WHERE `guid` IN (86858,86868,86870);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`) VALUES
(86858, 1129,  0, 1, 1, 0, 0, -4300.36, -1420.53, 391.496, 5.16617, 300, 0, 0, 0, 0, 0),
(86868, 1128,  0, 1, 1, 0, 0, -4298.227, -1420.108, 391.32, 4.435794, 300, 0, 0, 0, 0, 0),
(86870, 1128,  0, 1, 1, 0, 0, -4301.8081, -1422.118, 391.556, 5.795453, 300, 0, 0, 0, 0, 0);

DELETE FROM `creature_template_addon` WHERE `entry` IN (1129);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(1129, 0, 0, 1, 0, 0, '');

DELETE FROM `creature_addon` WHERE `guid` IN (86868,86870);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(86868, 0, 0, 1, 0, 0, ''),
(86870, 0, 0, 1, 0, 0, '');

UPDATE `creature` SET `MovementType`=0 WHERE `guid` IN (6127,6133);
