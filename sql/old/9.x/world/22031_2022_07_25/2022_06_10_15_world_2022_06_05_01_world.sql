--
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` IN (12429,12430));
UPDATE `creature_addon` SET `bytes2` = `bytes2` |256 WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` IN (5484,26044));

UPDATE `creature_template_addon` SET `bytes2` = `bytes2` |256 WHERE `entry` IN (739,927,1182,1444,5661,8140,12423,12427,12428,12429,12430);
DELETE FROM `creature_template_addon` WHERE `entry` IN (1351,5484,5489,12336,26044);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(1351,0,0,0,0,257,0,0,''),
(5484,0,0,0,0,257,0,0,''),
(5489,0,0,0,0,257,0,0,''),
(12336,0,0,0,0,257,0,0,''),
(26044,0,0,0,0,257,0,0,'');
