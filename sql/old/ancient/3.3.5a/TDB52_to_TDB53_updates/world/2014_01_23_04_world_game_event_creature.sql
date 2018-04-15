-- Boxi (brewfest)
SET @GUID := '200002';

-- game event creature boxi
DELETE FROM `game_event_creature` WHERE `guid`=@GUID;
INSERT INTO `game_event_creature`(`eventEntry`,`guid`) values (24,@GUID);
