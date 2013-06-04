SET @Event = 26; -- Pilgrim's Bounty
DELETE FROM `game_event` WHERE `eventEntry`=@Event;
INSERT INTO `game_event` (`eventEntry`,`start_time`,`end_time`,`occurence`,`length`,`holiday`,`description`,`world_event`) VALUES
(@Event,'2012-11-18 01:00:00','2020-12-31 05:00:00',525600,10020,404,'Pilgrim\'s Bounty',0);
