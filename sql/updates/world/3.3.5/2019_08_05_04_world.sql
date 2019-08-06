-- 
UPDATE `creature_template_addon` SET `bytes1`=50331648, `bytes2`=1, `auras`="29266" WHERE `entry` IN (29545,29571);
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|768 WHERE `entry` IN (29545,29571,29585);
DELETE FROM `creature` WHERE `guid` IN (116133,116134,116135) AND `id` IN (29545,29571,29585);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(116133, 29545, 571, 67, 0, 1, 1, 0, 0, 7199.461, -2373.582, 783.9456, 3.316126, 120, 0, 0, 0, 0, 0, 0, 0, 0, 12340), -- 29545 (Area: 0 - Difficulty: 0) (Auras: 29266 - 29266)
(116134, 29571, 571, 67, 0, 1, 1, 0, 1, 7275.04, -2358.114, 750.2308, 5.934119, 120, 0, 0, 0, 0, 0, 0, 0, 0, 12340), -- 29571 (Area: 0 - Difficulty: 0) (Auras: 29266 - 29266)
(116135, 29585, 571, 67, 0, 1, 1, 0, 0, 7061.15, -2122.69, 755.463, 4.79965, 120, 0, 0, 0, 0, 0, 0, 0, 0, 12340); -- 29585 (Area: 0 - Difficulty: 0) (Auras: 29266 - 29266)

DELETE FROM `creature_template_addon` WHERE `entry` IN (29585);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(29585, 0, 0, 50331648, 0, 0, '29266');
