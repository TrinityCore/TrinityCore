-- Implements in-game gm announce when tickets are completed
DELETE FROM `trinity_string` WHERE `entry` = 11002;
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES (11002, '|cff00ff00Completed by|r:|cff00ccff %s|r');
