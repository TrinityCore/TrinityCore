--
SET @ENTRY := 82;
DELETE FROM `game_event` WHERE `eventEntry`=@ENTRY;
INSERT INTO `game_event` (`eventEntry`, `start_time`, `end_time`, `occurence`, `length`, `holiday`, `holidayStage`, `description`, `world_event`, `announce`) VALUES
(@ENTRY, "2010-09-07 01:00:00", "2010-10-10 01:00:00", 9999999, 47520, 0, 0, "Operation: Gnomeregan", 0, 2);

DELETE FROM `game_event_creature` WHERE `eventEntry`=@ENTRY;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(@ENTRY, 207186),
(@ENTRY, 207193),
(@ENTRY, 207174),
(@ENTRY, 207175),
(@ENTRY, 207176),
(@ENTRY, 207177),
(@ENTRY, 207178),
(@ENTRY, 207179),
(@ENTRY, 207180),
(@ENTRY, 207181),
(@ENTRY, 207182),
(@ENTRY, 207183),
(@ENTRY, 207184),
(@ENTRY, 207185),
(@ENTRY, 207190),
(@ENTRY, 207191),
(@ENTRY, 207192),
(@ENTRY, 207194),
(@ENTRY, 207195),
(@ENTRY, 207188),
(@ENTRY, 207187),
(@ENTRY, 207196),
(@ENTRY, 207197),
(@ENTRY, 207198),
(@ENTRY, 207199),
(@ENTRY, 207189);

DELETE FROM `game_event_gameobject` WHERE `eventEntry`=@ENTRY;
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES
(@ENTRY, 151271),
(@ENTRY, 151272),
(@ENTRY, 151273),
(@ENTRY, 151274),
(@ENTRY, 151275),
(@ENTRY, 151276),
(@ENTRY, 151277),
(@ENTRY, 151244),
(@ENTRY, 151245),
(@ENTRY, 151246),
(@ENTRY, 151247),
(@ENTRY, 151248),
(@ENTRY, 151249),
(@ENTRY, 151250),
(@ENTRY, 151251),
(@ENTRY, 151252),
(@ENTRY, 151253),
(@ENTRY, 151254),
(@ENTRY, 151255);
