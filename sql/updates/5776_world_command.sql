
DELETE FROM `command` WHERE `name` = 'account addon';
INSERT INTO `command` (`name`, `security`, `help`) VALUES ('account addon', 3, 'Syntax: .account addon #addon\nSet expansion addon level allowed. Addon values: 0 - normal, 1 - tbc, 2 - wotlk.');

DELETE FROM `trinity_string` WHERE `entry`=61;
INSERT INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES
(61, 'Up to %u expansion allowed now.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
