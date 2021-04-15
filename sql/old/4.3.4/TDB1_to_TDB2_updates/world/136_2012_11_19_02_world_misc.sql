SET @Event = 26; -- game_event.entry - Set by TDB
DELETE FROM `game_event` WHERE `eventEntry`=@Event;
INSERT INTO `game_event` (`eventEntry`,`start_time`,`end_time`,`occurence`,`length`,`holiday`,`description`,`world_event`) VALUES
(@Event,'2012-11-18 01:00:00','2020-12-31 05:00:00',525600,10020,404, 'Pilgrim''s Bounty',0);
-- undo hack, reset to sniffed values
-- UPDATE `gameobject_template` SET `data10`=37639,`data5`=0 WHERE `entry`=184867; Already commented in the other sql
