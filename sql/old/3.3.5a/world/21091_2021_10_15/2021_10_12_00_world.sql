--
UPDATE `creature` SET `position_x` = 6561.05 WHERE `guid` = 137720 AND `id` = 30407;
UPDATE `creature` SET `position_x` = 6580.62, `position_y` = 599.204, `position_z` = 419.185, `orientation` = 0.523599 WHERE `guid` = 137723 AND `id` = 30407;
UPDATE `creature` SET `position_x` = 6596.29, `position_y` = 636.413, `position_z` = 407.354, `orientation` = 4.50295 WHERE `guid` = 137721 AND `id` = 30407;
UPDATE `creature` SET `position_y` = 654.944 WHERE `guid` = 137722 AND `id` = 30407;

DELETE FROM `creature` WHERE `guid` = 83065 AND `id` = 30407;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(83065,30407,571,0,0,1,2,0,0,6599.8,569.418,401.956,4.43314,300,0,0,1,0,0,0,0,0,'',0);
