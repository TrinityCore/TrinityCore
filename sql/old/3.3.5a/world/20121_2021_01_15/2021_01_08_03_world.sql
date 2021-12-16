--
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 2147483648 WHERE `entry` IN (29399,27355,27989,33785,28006,29929,32286,33308);
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 262144 WHERE `entry` IN (27989,29929,32286,33308);
UPDATE `creature_template` SET `speed_walk` = 1.2, `speed_run` = 2 WHERE `entry` = 29929;

DELETE FROM `creature_template_addon` WHERE `entry` IN (29399,27989,29929,32286,33308);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(29399, 0, 0, 0, 1, 0, 0, '54434'),
(27989, 0, 0, 0, 1, 0, 0, '28782'),
(29929, 0, 0, 0, 1, 0, 0, '60191 28782'),
(32286, 0, 0, 0, 1, 0, 0, '60190 28782'),
(33308, 0, 0, 0, 1, 0, 0, '28782'); -- Related quest was removed, guessed

-- No idea how both of them are spawned, if one is spawned, second (29929) is not
DELETE FROM `creature` WHERE `guid` = 147173 AND `id` = 32286;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `MovementType`, `VerifiedBuild`) VALUES
(147173, 32286, 571, 1, 1, 0, 0, 5913.654296875, 733.88067626953125, 641.177734375, 0.78539818525314331, 300, 0, 0, 12340);
