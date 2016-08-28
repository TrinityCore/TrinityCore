-- 
DELETE FROM `creature_addon` WHERE `guid` IN (375940, 376034);
DELETE FROM `creature_template_addon` WHERE `entry` IN (48823, 48826, 48827, 48824, 48440);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(48440, 0, 0, 0, 1, 233, ""),
(48823, 0, 0, 0, 1, 233, ""),
(48826, 0, 0, 0, 1, 233, ""),
(48824, 0, 0, 0, 1, 233, ""),
(48827, 0, 0, 0, 1, 233, "");
