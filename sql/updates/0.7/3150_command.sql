DELETE FROM `command` WHERE `name` = 'random';
DELETE FROM `command` WHERE `name` = 'setmovetype';
INSERT INTO `command` (`name`,`security`,`help`) VALUES ('setmovetype',2,'Syntax: .setmovetype [#creature_guid] stay/random/way\r\n\r\nSet for creature pointed by #creature_guid (or selected if #creature_guid not provided) movement type and move it to respawn position (if creature alive). Any existed waypoints for creature will be removed from database. If creature is dead then movement type will aplied at creature respawm.');
