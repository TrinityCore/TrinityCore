DELETE FROM `trinity_string` WHERE entry IN (300,550);
INSERT INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES
('300','Your chat has been disabled for %u minutes. By: %s ,Reason: %s.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
('550','Mute time remaining: %s, By: %s, Reason: %s',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
