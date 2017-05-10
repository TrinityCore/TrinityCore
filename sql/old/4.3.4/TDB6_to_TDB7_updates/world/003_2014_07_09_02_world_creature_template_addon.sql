DELETE FROM `creature_addon` WHERE `guid` IN (SELECT guid FROM `creature` WHERE `id` = 684);
DELETE FROM `creature_template_addon` WHERE `entry` IN (21337,636,684);

INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(21337, 0, 0, 131072, 1, 0, '5916 30982'),
(636,   0, 0, 131072, 1, 0, '6408'),
(684,   0, 0, 131072, 1, 0, '22766');
