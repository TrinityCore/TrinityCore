-- Drop table if exists
DROP TABLE IF EXISTS `account_ip_history`;

-- Create table
CREATE TABLE IF NOT EXISTS `account_ip_history` (
  `Account` int unsigned NOT NULL DEFAULT 0,
  `RealmID` int unsigned DEFAULT NULL,
  `IP` varchar(15) NOT NULL DEFAULT '',
  `date_recent` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `date_first` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `comment` text(255) COLLATE utf8mb4_unicode_ci NOT NULL COMMENT '',
  PRIMARY KEY (`Account`, `IP`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
