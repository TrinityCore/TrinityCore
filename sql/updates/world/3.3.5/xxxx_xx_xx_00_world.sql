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
