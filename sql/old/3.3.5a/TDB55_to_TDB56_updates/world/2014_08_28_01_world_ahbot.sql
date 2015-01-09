SET @id = 778;

DELETE FROM `command` WHERE `name` LIKE 'ahbot%';
INSERT INTO `command` (`name`, `permission`, `help`) VALUES
('ahbot items',          @id+1,  'Syntax: .ahbot items $GrayItems $WhiteItems $GreenItems $BlueItems $PurpleItems $OrangeItems $YellowItems\r\n\r\nSet amount of each items color be selled on auction.'),
('ahbot items gray',     @id+2,  'Syntax: .ahbot items gray $GrayItems\r\n\r\nSet amount of Gray color items be selled on auction.'),
('ahbot items white',    @id+3,  'Syntax: .ahbot items white $WhiteItems\r\n\r\nSet amount of White color items be selled on auction.'),
('ahbot items green',    @id+4,  'Syntax: .ahbot items green $GreenItems\r\n\r\nSet amount of Green color items be selled on auction.'),
('ahbot items blue',     @id+5,  'Syntax: .ahbot items blue $BlueItems\r\n\r\nSet amount of Blue color items be selled on auction.'),
('ahbot items purple',   @id+6,  'Syntax: .ahbot items purple $PurpleItems\r\n\r\nSet amount of Purple color items be selled on auction.'),
('ahbot items orange',   @id+7,  'Syntax: .ahbot items orange $OrangeItems\r\n\r\nSet amount of Orange color items be selled on auction.'),
('ahbot items yellow',   @id+8,  'Syntax: .ahbot items yellow $YellowItems\r\n\r\nSet amount of Yellow color items be selled on auction.'),
('ahbot ratio',          @id+9,  'Syntax: .ahbot ratio $allianceratio $horderatio $neutralratio\r\n\r\nSet ratio of items in 3 auctions house.'),
('ahbot ratio alliance', @id+10, 'Syntax: .ahbot ratio alliance $allianceratio\r\n\r\nSet ratio of items in alliance auction house.'),
('ahbot ratio horde',    @id+11, 'Syntax: .ahbot ratio horde $horderatio\r\n\r\nSet ratio of items in horde auction house.'),
('ahbot ratio neutral',  @id+12, 'Syntax: .ahbot ratio neutral $neutralratio\r\n\r\nSet ratio of items in $neutral auction house.'),
('ahbot rebuild',        @id+13, 'Syntax: .ahbot rebuild [all]\r\n\r\nExpire all actual auction of ahbot except bided by player. Binded auctions included to expire if "all" option used. Ahbot re-fill auctions base at current settings then.'),
('ahbot reload',         @id+14, 'Syntax: .ahbot reload\r\n\r\nReload AHBot settings from configuration file.'),
('ahbot status',         @id+15, 'Syntax: .ahbot status [all]\r\n\r\nShow current ahbot state data in short form, and with "all" with details.');

DELETE FROM `trinity_string` WHERE `entry` BETWEEN 1157 AND 1176;
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES
(1157, 'All config are reloaded from configuration file.'),
(1158, '=========================================================='),
(1159, '|--------------------------------------------------------|'),
(1160, '|            | Alliance |  Horde   | Neutral  |  Total   |'),
(1161, '          Alliance/Horde/Neutral/Total'),
(1162, '| %-10s | %8u | %8u | %8u | %8u |'),
(1163, '%-10s = %6u / %6u / %6u / %6u'),
(1164, 'Count'),
(1165, 'Item Ratio'),
(1166, '|            | Alliance |   Horde  | Neutral  |  Amount  |'),
(1167, '          Alliance/Horde/Neutral/Amount'),
(1168, 'Gray'),
(1169, 'White'),
(1170, 'Green'),
(1171, 'Blue'),
(1172, 'Purple'),
(1173, 'Orange'),
(1174, 'Yellow'),
(1175, 'Amount of %s items is set to %u.'),
(1176, 'Items ratio for %s is set to %u.');
