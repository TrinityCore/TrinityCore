-- 
DELETE FROM `creature` WHERE `id`  IN (23716) AND `guid` IN (111034);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`) VALUES
(111034, 23716, 530, 0, 0, 1, 1, 0, 1, 6782.92, -7642.17, 127.904, 2.775070, 600, 0, 0, 0, 0, 0);
UPDATE `creature` SET `id`=23716 WHERE `id`=23705 AND `guid`= 111033;

DELETE FROM `creature_template_addon` WHERE `entry`=23716;
INSERT INTO `creature_template_addon` (`entry`, `bytes2`, `auras`) VALUES (23716,1,"29266");
