DELETE FROM `trinity_string` WHERE `entry`=11020;
INSERT INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES 
(11020, '%s changed your fury to %i/%i.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
DELETE FROM `trinity_string` WHERE `entry`=11019;
INSERT INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES 
(11019, 'You changed fury of %s to %i/%i.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

DELETE FROM `command` WHERE `name`='modify fury';
INSERT INTO `command` (`name`, `permission`, `help`) VALUES ('modify fury', 1001, 'Syntax: .modify fury #furycount\r\n\r\nModify the fury of the selected player. If no player is selected, modify your fury.');
-- Pain
DELETE FROM `trinity_string` WHERE `entry`=11022;
INSERT INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES 
(11022, '%s changed your pain to %i/%i.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
DELETE FROM `trinity_string` WHERE `entry`=11021;
INSERT INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES 
(11021, 'You changed pain of %s to %i/%i.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

DELETE FROM `command` WHERE `name`='modify pain';
INSERT INTO `command` (`name`, `permission`, `help`) VALUES ('modify pain', 1002, 'Syntax: .modify pain #paincount\r\n\r\nModify the pain of the selected player. If no player is selected, modify your pain.');
