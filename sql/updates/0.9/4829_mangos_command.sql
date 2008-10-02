DELETE FROM command WHERE name IN ('gozonexy','lookup area');

INSERT INTO `command` VALUES 
('gozonexy',1,'Syntax: .gozonexy #x #y [#zone]\r\n\r\nTeleport player to point with (#x,#y) client coordinates at ground(water) level in zone #zoneid or current zone if #zoneid not provided. You can look up zone using .lookup area $namepart'),
('lookup area',1,'Syntax: .lookup area $namepart\r\n\r\nLooks up an area by $namepart, and returns all matches with their area ID\'s.');
