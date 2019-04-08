-- 
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|33555264  WHERE `entry` IN(13976);
UPDATE `creature_template_addon` SET `bytes1`=7 WHERE `entry` IN(13976);
DELETE FROM `creature` WHERE `guid` IN (61704,61705);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`,`spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`) VALUES
(61704, 13976, 469, 1, 1, 0, 0, -7344.2729, -956.9001, 481.1072, 4.188029, 604800, 0, 0, 7620, 0, 0),
(61705, 13976, 469, 1, 1, 0, 0, -7393.3, -1070.78, 479.793, 3.22886, 604800, 0, 0, 7620, 0, 0);
