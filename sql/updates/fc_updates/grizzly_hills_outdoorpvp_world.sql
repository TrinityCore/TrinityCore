delete from outdoorpvp_template where typeid in (8);
INSERT INTO `outdoorpvp_template` VALUES
(8,'outdoorpvp_gh','Grizzly Hills');

-- update creatures
update creature set spawnMask = 0 where id in (27748, 27708, 29253, 27730, 29251, 27758, 27759, 29252,27760, 29250);

DELETE FROM `trinity_string` WHERE entry BETWEEN 12001 AND 12004;
INSERT INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES
(12001, 'The Horde has taken the Venture Bay Lighthouse!', NULL, '', NULL, NULL, NULL, NULL, NULL, NULL),
(12002, 'The Alliance has taken the Venture Bay Lighthouse!', NULL, '', NULL, NULL, NULL, NULL, NULL, NULL),
(12003, 'The Horde lost the Venture Bay Lighthouse!', NULL, '', NULL, NULL, NULL, NULL, NULL, NULL),
(12004, 'The Alliance lost the Venture Bay Lighthouse!', NULL, '', NULL, NULL, NULL, NULL, NULL, NULL);   
