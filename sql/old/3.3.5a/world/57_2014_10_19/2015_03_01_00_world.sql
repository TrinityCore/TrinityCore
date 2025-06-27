--
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 2586);
DELETE FROM `creature_template_addon` WHERE `entry`=2586;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(2586, 0, 0, 131072, 1, 0, "");

UPDATE `creature_template_addon` SET `bytes1`=131072,  `bytes2`=1 WHERE  `entry` IN ( 6035, 22060, 18116, 16928, 16170, 11792, 6886, 4798, 2522, 25484, 4850, 1040, 579, 4834, 215, 1713, 938, 768, 17949);

DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 11792);
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 4798);

DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 2242);
DELETE FROM `creature_template_addon` WHERE `entry`=2242;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(2242, 0, 0, 131072, 1, 0, "");

DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 2246);
DELETE FROM `creature_template_addon` WHERE `entry`=2246;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(2246, 0, 0, 131072, 1, 0, "");

DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 2926);
DELETE FROM `creature_template_addon` WHERE `entry`=2926;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(2926, 0, 0, 131072, 1, 0, "");

DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 7110);
DELETE FROM `creature_template_addon` WHERE `entry`=7110;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(7110, 0, 0, 131072, 1, 0, "");
