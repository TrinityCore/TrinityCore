DELETE FROM `trinity_string` WHERE `entry` IN (11019,11020,11021);
INSERT INTO `trinity_string` (`entry`,`content_default`,`content_loc1`,`content_loc2`,`content_loc3`,`content_loc4`,`content_loc5`,`content_loc6`,`content_loc7`,`content_loc8`) VALUES
(11019, 'You changed %s of %s to %d/%d.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(11020, '%s changed your %s to %d/%d.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(11021, 'Invalid power name.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

DELETE FROM `command` WHERE `name`='modify power' and `permission`= 867;
INSERT INTO `command` (`name`, `permission`, `help`) VALUES
('modify power', 867, 'Syntax: .modify power #powerType #amount \r\n\r\nModify the power of the selected player. If no player is selected, modify your power.');
