ALTER TABLE `creature_formations` CHANGE `leader` `leaderGUID` int(11) unsigned NOT NULL default '0';
ALTER TABLE `creature_formations` CHANGE `follower` `memberGUID` int(11) unsigned NOT NULL default '0';
