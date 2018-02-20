DROP TABLE IF EXISTS `hotfix_data`;
CREATE TABLE `hotfix_data` (
  `Id` int(11) NOT NULL,
  `TableHash` int(10) unsigned NOT NULL,
  `RecordId` int(11) NOT NULL,
  `Deleted` tinyint(3) unsigned NULL DEFAULT '0',
  PRIMARY KEY (`Id`, `TableHash`, `RecordId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
