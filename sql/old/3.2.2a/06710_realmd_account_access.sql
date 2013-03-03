-- Table structure for `account_access`
DROP TABLE IF EXISTS `account_access`;
CREATE TABLE `account_access` (
  `id` bigint(20) unsigned NOT NULL,
  `gmlevel` tinyint(3) unsigned NOT NULL,
  `RealmID` int(11) NOT NULL,
  PRIMARY KEY (`id`,`RealmID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;
-- export current gm account to the new table
-- RealmID -1 = all realms
INSERT INTO `account_access` (id, gmlevel, RealmID)
SELECT `id`, `gmlevel`, -1 FROM `account` WHERE `gmlevel` > 0;
-- Remove the gmlevel field from account
ALTER TABLE account DROP COLUMN `gmlevel`;
