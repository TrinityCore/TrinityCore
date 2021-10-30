-- Elder Shadowmaw Panther
UPDATE `creature_template_addon` SET `auras` = '7939 22766' WHERE `entry` = 1713;

-- Wastewander Rogue
DELETE FROM `smart_scripts` WHERE `entryorguid` = 5615 AND `source_type` = 0 AND `id` = 0;

DELETE FROM `creature_template_addon` WHERE `entry` = 5615;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(5615, 0, 0, 0, 0, 1, 0, 0, '7939 22766');

-- Formation members should not have waypoints assigned
DELETE FROM `waypoint_data` WHERE `id` IN (234660,234670);
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 5615);
UPDATE `creature` SET `MovementType` = 0 WHERE `guid` IN (23466,23467);
