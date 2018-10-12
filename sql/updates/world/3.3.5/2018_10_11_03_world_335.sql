-- 
UPDATE `creature_template` SET `npcflag`=128 WHERE `entry`=2683;
DELETE FROM `creature` WHERE `guid` IN (87022);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`) VALUES
(87022, 2683, 0, 1, 1, 0, 1, -4923.421, 725.513, 253.102, 0.000000, 300);
