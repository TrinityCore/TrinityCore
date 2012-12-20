DELETE FROM command WHERE name IN ('ahbot items amount','ahbot items amount grey',
  'ahbot items amount white','ahbot items amount green','ahbot items amount blue',
  'ahbot items amount purple','ahbot items amount orange','ahbot items amount yellow',
  'ahbot items ratio','ahbot items ratio alliance','ahbot items ratio horde','ahbot items ratio neutral',
  'ahbot rebuild','ahbot reload','ahbot status'
);

INSERT INTO command (name, security, help) VALUES
('ahbot items amount',3,'Syntax: .ahbot items amount $GreyItems $WhiteItems $GreenItems $BlueItems $PurpleItems $OrangeItems $YellowItems\r\n\r\nSet amount of each items color be selled on auction.'),
('ahbot items amount grey',3,'Syntax: .ahbot items amount grey $GreyItems\r\n\r\nSet amount of Grey color items be selled on auction.'),
('ahbot items amount white',3,'Syntax: .ahbot items amount white $WhiteItems\r\n\r\nSet amount of White color items be selled on auction.'),
('ahbot items amount green',3,'Syntax: .ahbot items amount green $GreenItems\r\n\r\nSet amount of Green color items be selled on auction.'),
('ahbot items amount blue',3,'Syntax: .ahbot items amount blue $BlueItems\r\n\r\nSet amount of Blue color items be selled on auction.'),
('ahbot items amount purple',3,'Syntax: .ahbot items amount purple $PurpleItems\r\n\r\nSet amount of Purple color items be selled on auction.'),
('ahbot items amount orange',3,'Syntax: .ahbot items amount orange $OrangeItems\r\n\r\nSet amount of Orange color items be selled on auction.'),
('ahbot items amount yellow',3,'Syntax: .ahbot items amount yellow $YellowItems\r\n\r\nSet amount of Yellow color items be selled on auction.'),
('ahbot items ratio',3,'Syntax: .ahbot items ratio $allianceratio $horderatio $neutralratio\r\n\r\nSet ratio of items in 3 auctions house.'),
('ahbot items ratio alliance',3,'Syntax: .ahbot items ratio alliance $allianceratio\r\n\r\nSet ratio of items in alliance auction house.'),
('ahbot items ratio horde',3,'Syntax: .ahbot items ratio horde $horderatio\r\n\r\nSet ratio of items in horde auction house.'),
('ahbot items ratio neutral',3,'Syntax: .ahbot items ratio neutral $neutralratio\r\n\r\nSet ratio of items in $neutral auction house.'),
('ahbot rebuild',3,'Syntax: .ahbot rebuild [all]\r\n\r\nExpire all actual auction of ahbot except bided by player. Binded auctions included to expire if "all" option used. Ahbot re-fill auctions base at current settings then.'),
('ahbot reload',3,'Syntax: .ahbot reload\r\n\r\nReload AHBot settings from configuration file.'),
('ahbot status',3,'Syntax: .ahbot status [all]\r\n\r\nShow current ahbot state data in short form, and with "all" with details.');

DELETE FROM trinity_string WHERE entry BETWEEN 1151 AND 1170;

INSERT INTO trinity_string VALUES
(1151,'All config are reloaded from configuration file.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1152,'==========================================================',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1153,'|--------------------------------------------------------|',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1154,'|            | Alliance |  Horde   | Neutral  |  Total   |',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1155,'          Alliance/Horde/Neutral/Total',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1156,'| %-10s | %8u | %8u | %8u | %8u |',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1157,'%-10s = %6u / %6u / %6u / %6u',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1158,'Count',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1159,'Item Ratio',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1160,'|            | Alliance |   Horde  | Neutral  |  Amount  |',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1161,'          Alliance/Horde/Neutral/Amount',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1162,'Grey',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1163,'White',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1164,'Green',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1165,'Blue',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1166,'Purple',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1167,'Orange',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1168,'Yellow',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1169,'Amount of %s items is set to %u.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1170,'Items ratio for %s is set to %u.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
