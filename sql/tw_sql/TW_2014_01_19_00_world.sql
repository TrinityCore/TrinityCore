-- Move custom things to a separate entry value that is likely to be used on TC
-- doing this because the current merge overwrites these custom entries
DELETE FROM `trinity_string` WHERE `entry` IN (364,365);
DELETE FROM `trinity_string` WHERE `entry` IN (11500,11501,11502);
INSERT INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES
(11500, 'Player not online!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(11501, 'Online characters at account %s (Id: %u)', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(11502, '|cff00ff00Completed by|r:|cff00ccff %s|r', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
