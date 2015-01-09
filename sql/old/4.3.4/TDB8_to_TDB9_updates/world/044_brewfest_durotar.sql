SET @CGUID := 361975;

DELETE FROM `game_event_creature` WHERE `eventEntry`=24 AND `guid` BETWEEN @CGUID+0 AND @CGUID+17;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(24, @CGUID+0), 
(24, @CGUID+1), 
(24, @CGUID+2), 
(24, @CGUID+3), 
(24, @CGUID+4), 
(24, @CGUID+5), 
(24, @CGUID+6), 
(24, @CGUID+7), 
(24, @CGUID+8), 
(24, @CGUID+9), 
(24, @CGUID+10),
(24, @CGUID+11),
(24, @CGUID+12),
(24, @CGUID+13),
(24, @CGUID+14),
(24, @CGUID+15),
(24, @CGUID+16),
(24, @CGUID+17);
