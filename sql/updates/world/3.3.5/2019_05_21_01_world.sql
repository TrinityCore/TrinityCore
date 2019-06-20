-- 
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|128 WHERE `entry`=19680;
DELETE FROM `creature` WHERE `guid` IN (105221);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(105221, 19680, 530, 0, 0, 1, 1, 0, 0, -1936.83, 5332.03, -12.3448, 0.471239, 300, 0, 0, 4120, 0, 0, 0, 0, 0, 0);
