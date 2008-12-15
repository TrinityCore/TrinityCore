DROP TABLE IF EXISTS `creature_formations`;

CREATE TABLE `creature_formations` (
  `leader` int(11) unsigned NOT NULL,
  `follower` int(11) unsigned NOT NULL,
  `dist` float unsigned NOT NULL,
  `angle` float unsigned NOT NULL,
  `groupAI` int(11) unsigned NOT NULL,
  PRIMARY KEY  (`follower`));
