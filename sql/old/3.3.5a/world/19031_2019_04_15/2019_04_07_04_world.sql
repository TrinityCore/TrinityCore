-- 
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|128 WHERE `entry` IN(14459); 
DELETE FROM `creature` WHERE `guid` IN (61707);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`,`spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`) VALUES
(61707, 14459, 469, 1, 1, 0, 0, -7644.53, -1081.53, 408.574, 5.2709, 10, 0, 0, 42, 0, 0);
