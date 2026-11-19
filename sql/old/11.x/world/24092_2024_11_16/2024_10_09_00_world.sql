SET @EENTRY := 86;

DELETE FROM `game_event` WHERE `eventEntry` BETWEEN @EENTRY+0 AND @EENTRY+2;
INSERT INTO `game_event` (`eventEntry`,`start_time`,`end_time`,`occurence`,`length`,`holiday`,`holidayStage`,`description`,`world_event`,`announce`) VALUES
(@EENTRY+0,NULL,NULL,5184000,2592000,0,0,'PvP Season 9 - Vicious (Cataclysm)',0,2),
(@EENTRY+1,NULL,NULL,5184000,2592000,0,0,'PvP Season 10 - Ruthless (Cataclysm)',0,2),
(@EENTRY+2,NULL,NULL,5184000,2592000,0,0,'PvP Season 11 - Cataclysmic (Cataclysm)',0,2);

UPDATE `game_event` SET `description`='PvP Season 3 - Vengeful (TBC)' WHERE `eventEntry`=55;
UPDATE `game_event` SET `description`='PvP Season 4 - Brutal (TBC)' WHERE `eventEntry`=56;
UPDATE `game_event` SET `description`='PvP Season 5 - Deadly (WotLK)' WHERE `eventEntry`=57;
UPDATE `game_event` SET `description`='PvP Season 6 - Furious (WotLK)' WHERE `eventEntry`=58;
UPDATE `game_event` SET `description`='PvP Season 7 - Relentless (WotLK)' WHERE `eventEntry`=59;
UPDATE `game_event` SET `description`='PvP Season 8 - Wrathful (WotLK)' WHERE `eventEntry`=60;

DELETE FROM `game_event_arena_seasons` WHERE `eventEntry` BETWEEN @EENTRY+0 AND @EENTRY+2;
INSERT INTO `game_event_arena_seasons` (`eventEntry`,`season`) VALUES
(@EENTRY+0,9),
(@EENTRY+1,10),
(@EENTRY+2,11);
