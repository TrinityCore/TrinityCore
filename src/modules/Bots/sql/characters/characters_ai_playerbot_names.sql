DROP TABLE IF EXISTS `ai_playerbot_names`;
CREATE TABLE `ai_playerbot_names` (
  `name_id` mediumint(8) NOT NULL UNIQUE,
  `name` varchar(255) NOT NULL,
  `gender` tinyint(3) unsigned NOT NULL,
PRIMARY KEY (`name_id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='PlayerbotAI RandomBot names';

LOAD DATA LOCAL INFILE './characters_ai_playerbot_names.csv' INTO TABLE ai_playerbot_names FIELDS TERMINATED BY ';';

delete FROM ai_playerbot_names  where length(name) > 12;
alter table ai_playerbot_names modify name varchar(12);
