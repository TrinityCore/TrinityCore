-- 
DELETE FROM `creature` WHERE `id`=24925 AND `guid` IN (113147,113151,113208);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(113147, 24925, 530, 0, 0, 1, 1, 22742, 0, -3500.62, 395.197, 32.8023, 3.05433, 25, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(113151, 24925, 530, 0, 0, 1, 1, 22742, 0, -3618.64, 396.125, 33.1356, 0.03491, 25, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(113208, 24925, 530, 0, 0, 1, 1, 22742, 0, -3560.61, 372.614, 32.7836, 1.57081, 25, 0, 0, 0, 0, 0, 0, 0, 0, 0);

UPDATE `creature_template` SET `flags_extra`=`flags_extra`|128 WHERE `entry`=24925;
UPDATE `creature_template_addon` SET `emote`=422 WHERE `entry`=24925;
