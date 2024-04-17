-- Dumping structure for table auth.account_ip_history
CREATE TABLE IF NOT EXISTS `account_ip_history` (
  `Account` int unsigned NOT NULL DEFAULT 0,
  `RealmID` int unsigned DEFAULT NULL,
  `IP` varchar(15) NOT NULL DEFAULT '',
  `date_recent` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00',
  `date_first` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00',
  `comment` text COLLATE utf8mb4_unicode_ci NOT NULL COMMENT '',
  PRIMARY KEY (`Account`,`IP`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;