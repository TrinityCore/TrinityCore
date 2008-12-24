ALTER TABLE character_db_version CHANGE COLUMN required_2008_12_22_05_characters_account_data required_2008_12_22_06_characters_character_achievement bit;

DROP TABLE IF EXISTS `character_achievement`;
CREATE TABLE `character_achievement` (
      `guid` int(11) NOT NULL,
      `achievement` int(11) NOT NULL,
      `date` int(11) NOT NULL,
      PRIMARY KEY  (`guid`,`achievement`)
    ) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `character_achievement_progress`;
CREATE TABLE `character_achievement_progress` (
      `guid` int(11) NOT NULL,
      `criteria` int(11) NOT NULL,
      `counter` int(11) NOT NULL,
      `date` int(11) NOT NULL,
      PRIMARY KEY  (`guid`,`criteria`)
    ) ENGINE=MyISAM DEFAULT CHARSET=utf8;
