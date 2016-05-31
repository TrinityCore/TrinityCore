DELETE FROM `command` WHERE `name` = 'go xyz';
INSERT INTO `command` VALUES
('go xyz',1,'Syntax: .go xyz #x #y [#z [#mapid [#orientation]]]\r\n\r\nTeleport player to point with (#x,#y,#z) coordinates at map #mapid with orientation #orientation. If z is not provided, ground/water level will be used. If mapid is not provided, the current map will be used. If #orientation is not provided, the current orientation will be used.');
