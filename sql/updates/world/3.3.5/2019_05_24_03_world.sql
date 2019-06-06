-- 
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|128 WHERE `entry` IN (21862);
DELETE FROM `creature` WHERE `guid` IN (106798);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(106798, 21862, 269, 0, 0, 3, 1, 0, 0, -2025.52, 7119.707, 22.74707, 3.071779, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 0); -- 21862 (Area: 0 - Difficulty: 0) (Auras: 32570 - 32570)
UPDATE `creature` SET `position_x`=-2025.295, `position_y`=7119.58, `position_z`=22.74709, `orientation`=3.001966 WHERE `id`=15608;
UPDATE `creature_template_addon` SET `auras`="31635" WHERE `entry` IN (15608);

DELETE FROM `creature_template_addon` WHERE `entry` IN (21862);
INSERT INTO `creature_template_addon` (`entry`, `auras`, `bytes1`,`bytes2`) VALUES
(21862, "32570", 0, 1);
