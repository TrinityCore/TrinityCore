-- 
DELETE FROM `creature` WHERE `id`  IN (21292) AND `guid` IN (111105);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `unit_flags`) VALUES
(111105, 21292, 530, 0, 0, 1, 1, 0, 0, -3795.850098, 2595.90991, 90.12059, 4.782200, 600, 0, 0, 0, 0, 0, 33554432);
DELETE FROM `creature_addon` WHERE `guid`=111105;
INSERT INTO `creature_addon` (`guid`, `bytes2`, `auras`) VALUES (111105,0,"29266 37497");
UPDATE `smart_scripts` SET `target_type`=10, `target_param1`=84607 AND `target_param2`=21292 WHERE `action_type`=11 AND`action_param1` = 36558;
-- DB errors and spawns fix
DELETE FROM `gameobject_addon` WHERE `guid` IN (99874,99873,99872);
UPDATE `gameobject` SET `rotation2`=0.588741, `rotation3`=0.808322 WHERE `id` = 142698;
UPDATE `creature` SET `MovementType`=1, `spawndist`=5 WHERE `id` IN (18867,18866);
UPDATE `creature` SET `position_x`=2172.269531, `position_y`=2317.429688, `position_z`=81.406921 WHERE `guid` IN (67476);
