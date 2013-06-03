ALTER TABLE `channels` CHANGE COLUMN `m_name` `name` varchar(128) NOT NULL,
  CHANGE COLUMN `m_team` `team` int(10) unsigned NOT NULL,
  CHANGE COLUMN `m_announce` `announce` tinyint(3) unsigned NOT NULL DEFAULT '1',
  CHANGE COLUMN `m_ownership` `ownership` tinyint(3) unsigned NOT NULL DEFAULT '1',
  CHANGE COLUMN `m_password` `password` varchar(32) DEFAULT NULL,
  CHANGE COLUMN `BannedList` `bannedList` text,
  CHANGE COLUMN `last_used` `lastUsed` int(10) unsigned NOT NULL;
