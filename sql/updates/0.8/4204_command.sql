DELETE FROM `command`  WHERE `name` = 'setmovetype';

INSERT INTO `command` ( `name` , `security` , `help` ) VALUES 
('setmovetype',2,'Syntax: .setmovetype [#creature_guid] stay/random/way [NODEL]\r\n\r\nSet for creature pointed by #creature_guid (or selected if #creature_guid not provided) movement type and move it to respawn position (if creature alive). Any existing waypoints for creature will be removed from the database if you do not use NODEL. If the creature is dead then movement type will applied at creature respawn.\r\nMake sure you use NODEL, if you want to keep the waypoints.');