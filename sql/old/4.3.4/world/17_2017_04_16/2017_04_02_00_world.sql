--
UPDATE `command` SET `help`='Syntax: .gobject turn [guid|link] [oz [oy [ox]]]\r\n\r\nSet the orientation of the gameobject to player\'s orientation or the given orientation.' WHERE  `name`='gobject turn';
UPDATE `trinity_string` SET `content_default`='>> Add Game Object \'%u\' (%s) (GUID: %u) added at \'%f %f %f\'.' WHERE  `entry`=525;
UPDATE `command` SET `name`='event info', `help`='Syntax: .event info #event_id\r\nShow details about event with #event_id.' WHERE  `name`='event';

DELETE FROM `trinity_string` WHERE `entry` IN (84, 85, 86);
INSERT INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES
(84, 'Size: %f', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(85, 'Faction: %u Flags: %u', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(86, 'Model dimensions from center: Max X %f Y %f Z %f Min X %f Y %f Z %f', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

DELETE FROM `command` WHERE `name` = "go";
DELETE FROM `command` WHERE `name` = "go offset";
INSERT INTO `command` (`name`, `permission`, `help`) VALUES ('go offset', 845, 'Syntax: .go offset [x[ y[ z[ o]]]]\nTeleports the player by given offset from his current coordinates.');

UPDATE `command` SET `help`='Syntax: .gobject info [$entry|$link | guid [$guid|$link]\r \r Query Gameobject information for given gameobject entry, guid or link.\rFor example .gobject info 36\ror .gobject info guid 100' WHERE  `name`='gobject info';

ALTER TABLE `waypoint_data` CHANGE COLUMN `wpguid` `wpguid` INT(11) UNSIGNED NOT NULL DEFAULT '0' AFTER `action_chance`;

UPDATE `command` SET `help`='Syntax: .wp show $option\nOptions:\non $pathid (or selected creature with loaded path) - Show path\nfirst $pathid (or selected creature with loaded path) - Show first waypoint in path\nlast $pathid (or selected creature with loaded path) - Show last waypoint in path\noff - Hide all paths\ninfo $selected_waypoint - Show info for selected waypoint.' WHERE  `name`='wp show';
--
