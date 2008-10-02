ALTER TABLE `realmd`.`ip_banned` 
    ADD COLUMN `bandate` INT NOT NULL AFTER `ip`,
    ADD COLUMN `unbandate` INT NOT NULL AFTER `bandate`,
    ADD COLUMN `bannedby` VARCHAR(50) NOT NULL DEFAULT '[Console]' AFTER `unbandate`,
    ADD COLUMN `banreason` VARCHAR(50) NOT NULL DEFAULT 'no reason' AFTER `bannedby`;

ALTER TABLE `realmd`.`account` 
    DROP KEY `idx_banned`,
    DROP COLUMN `banned`;

--
-- Table structure for table `account_banned`
--

DROP TABLE IF EXISTS `realmd`.`account_banned`;
CREATE TABLE `realmd`.`account_banned` (
  `id` int(11) NOT NULL COMMENT   'Account id' default '0',
   `bandate` bigint(40) NOT NULL default '0',
  `unbandate` bigint(40) NOT NULL default '0',
   `bannedby` VARCHAR(50) NOT NULL,
   `banreason` VARCHAR(255) NOT NULL,
   `active` TINYINT NOT NULL DEFAULT 1,
  PRIMARY KEY  (`id`,`bandate`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Ban List';

--
-- Dumping data for table `account_banned`
--

LOCK TABLES `realmd`.`account_banned` WRITE;
/*!40000 ALTER TABLE `realmd`.`account_banned` DISABLE KEYS */;
/*!40000 ALTER TABLE `realmd`.`account_banned` ENABLE KEYS */;
UNLOCK TABLES;
