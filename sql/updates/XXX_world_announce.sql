CREATE TABLE `autobroadcast` (
`id` int(11) NOT NULL AUTO_INCREMENT,
`text` longtext NOT NULL,
PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DELETE FROM `trinity_string` WHERE `entry` = 11000;
INSERT INTO `trinity_string` (entry, content_default, content_loc1, content_loc2, content_loc3, content_loc4, content_loc5, content_loc6, content_loc7, content_loc8)
VALUES (11000, '|cffffff00[|c00077766Autobroadcast|cffffff00]: |cFFF222FF%s|r', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

-- optional examples
-- insert into `autobroadcast` (`id`, `text`) values('1','All Battlegrounds and Arena's work on this server.');
-- insert into `autobroadcast` (`id`, `text`) values('2','This server has 2 realms, The other realm is a PVP instant level 70 realm. Try it!');
-- insert into `autobroadcast` (`id`, `text`) values('3','The Auction House on this server is always full, because we use an AH Bot.');
