DELETE FROM `trinity_string` WHERE `entry` IN (1149,1150);
INSERT INTO `trinity_string` (`entry`,`content_default`,`content_loc1`,`content_loc2`,`content_loc3`,`content_loc4`,`content_loc5`,`content_loc6`,`content_loc7`,`content_loc8`) VALUES
(1149,'Group type: %s',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1150,'Name: %s (%s), GUID: %u, Flags: %s, Roles: %s',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);

DELETE FROM `command` WHERE `name`='group list';
INSERT INTO `command` (`name`,`security`,`help`) VALUES
('group list',3,'Syntax: .group list [$CharacterName] \r\nLists all the members of the group/party the player is in.');
