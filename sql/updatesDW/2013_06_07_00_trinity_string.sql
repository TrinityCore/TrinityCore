DELETE FROM `trinity_string` WHERE `entry` IN (826,827,832,556,357);
INSERT INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES
(826, '* is poison vendor (%u)', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(827, '* is reagent vendor (%u)', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(832, '* is innkeeper (%u)', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(556, 'Found near creatures (distance %f): %u ', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(357, 'Cheat Command Status:', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
