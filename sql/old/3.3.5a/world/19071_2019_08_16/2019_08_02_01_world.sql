-- 
UPDATE `creature` SET `MovementType` =0, `spawndist`=0 WHERE `id`=27191;
DELETE FROM `creature` WHERE `id`=27198 AND `guid`=113636; 
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(113636, 27198, 571, 0, 0, 1, 1, 0, 0, 3240.79, -724.326, 174.892, 4.15388, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0);
DELETE FROM `creature_template_addon` WHERE `entry` IN (27198);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `path_id`, `bytes1`, `bytes2`, `auras`) VALUES
(27198,0,0,1,0,"");
