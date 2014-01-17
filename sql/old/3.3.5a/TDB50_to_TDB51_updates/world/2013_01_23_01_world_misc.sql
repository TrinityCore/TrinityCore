DELETE FROM `trinity_string` WHERE `entry` BETWEEN 1145 AND 1148;
INSERT INTO `trinity_string` (`entry`,`content_default`,`content_loc1`,`content_loc2`,`content_loc3`,`content_loc4`,`content_loc5`,`content_loc6`,`content_loc7`,`content_loc8`) VALUES
(1145,'%s is already in a group!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1146,'%s joined %s''s group.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1147,'%s is not in a group!',NULL, NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1148,'Group is full!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);

DELETE FROM `command` WHERE `name`='group join';
INSERT INTO `command` (`name`,`security`,`help`) VALUES
('group join',3,'Syntax: .group join $AnyCharacterNameFromGroup [$CharacterName] \r\nAdds to group of player $AnyCharacterNameFromGroup player $CharacterName (or selected).');
