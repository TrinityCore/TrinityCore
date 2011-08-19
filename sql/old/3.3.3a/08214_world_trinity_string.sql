DELETE FROM `trinity_string` WHERE `entry` IN (817,818);
INSERT INTO `trinity_string` VALUES
(817,'Entry %u not found in creature_template table.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(818,'Entry %u not found in sCreatureStorage. Possible new line in creature_template, but you can not add new creatures without restarting. Only modifing is allowed.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
