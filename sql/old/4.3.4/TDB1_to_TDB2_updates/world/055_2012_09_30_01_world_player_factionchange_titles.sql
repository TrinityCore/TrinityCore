-- Title converter
DROP TABLE IF EXISTS `player_factionchange_titles`;
CREATE TABLE `player_factionchange_titles` (
 `alliance_id` int(8) NOT NULL,
 `horde_id` int(8) NOT NULL,
 PRIMARY KEY (`alliance_id`,`horde_id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DELETE FROM `player_factionchange_titles` WHERE `alliance_id` IN (1,2,3,4,5,6,7,8,9,10,11,12,13,14,48,75,113,126,146,147,148,149);
INSERT INTO `player_factionchange_titles` (`alliance_id`,`horde_id`) VALUES
(1, 15),
(2, 16),
(3, 17),
(4, 18),
(5, 19),
(6, 20),
(7, 21),
(8, 22),
(9, 23),
(10, 24),
(11, 25),
(12, 26),
(13, 27),
(14, 28),
(48, 47),
(75, 76),
(113, 153),
(126, 127),
(146, 152),
(147, 154),
(148, 151),
(149, 150);
