DELETE FROM `trinity_string` WHERE `entry` IN (11019,11020,11021,11022,11023,11024);
INSERT INTO `trinity_string` (`entry`,`content_default`,`content_loc1`,`content_loc2`,`content_loc3`,`content_loc4`,`content_loc5`,`content_loc6`,`content_loc7`,`content_loc8`) VALUES 
(11019, 'You changed Insanity of %s to %i/%i.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(11020, '%s changed your Insanity to %i/%i.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(11021, 'You changed Maelstrom of %s to %i/%i.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(11022, '%s changed your Maelstrom to %i/%i.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(11023, 'You changed Focus of %s to %i/%i.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(11024, '%s changed your Focus to %i/%i.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

DELETE FROM `command` WHERE `name`='modify power' and `permission`= 867;
INSERT INTO `command` (`name`, `permission`, `help`) VALUES
('modify power', 867, 'Syntax: .modify power #powercount \r\n\r\nModify the power of the selected player. If no player is selected, modify your power.');
