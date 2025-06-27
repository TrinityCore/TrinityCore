-- 
DELETE FROM `creature` WHERE `guid` IN (104815, 104817, 104819);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(104815, 18625, 269, 2366, 0, 3, 1, 0, 0, -2033.517, 7110.752, 22.85045, 2.635447, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- 18625 (Area: 0 - Difficulty: 0)
(104817, 18625, 269, 2366, 0, 3, 1, 0, 0, -2024.31, 7127.75, 22.65419, 0.4712389, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- 18625 (Area: 0 - Difficulty: 0)
(104819, 18625, 269, 2366, 0, 3, 1, 0, 0, -2025.422, 7119.652, 22.74706, 6.161012, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595); -- 18625 (Area: 0 - Difficulty: 0)
UPDATE `creature_template` SET `flags_extra` = `flags_extra`|128 WHERE `entry` IN (18625); 
 
DELETE FROM `creature_template_addon` WHERE `entry` IN(18553);
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES (18553, '32563');
