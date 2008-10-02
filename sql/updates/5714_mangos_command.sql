DELETE FROM `command` WHERE `name` = "nearobjects";
INSERT INTO `command` VALUES
('nearobjects',3,'Syntax: .nearobjects [#distance]\r\n\r\nOutput gameobjects at distance #distance from player. Output gameobject guids and coordinates sorted by distance from character. If #distance not provided use 10 as default value.');
