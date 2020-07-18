-- 
UPDATE `creature_template` SET `flags_extra` = `flags_extra` | 128 WHERE `entry` = 18208;
DELETE FROM `creature` WHERE `guid` IN (104113);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`) VALUES 
(104113,18208,530,1,1,0,0,-1627.12, 8516.73, -11.3054, 3.54302, 300,0,0,42,0,0);

DELETE FROM `creature_template_movement` WHERE `CreatureId`= 18208;
INSERT INTO `creature_template_movement` (`CreatureId`,`Ground`,`Swim`,`Flight`,`Rooted`) VALUES
(18208, 0, 0, 1, 0);
