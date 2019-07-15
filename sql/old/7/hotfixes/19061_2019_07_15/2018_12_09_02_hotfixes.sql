--
-- Table structure for table `hotfix_blob`
--
DROP TABLE IF EXISTS `hotfix_blob`;
CREATE TABLE `hotfix_blob` (
  `TableHash` INT(10) UNSIGNED NOT NULL,
  `RecordId` INT(11) NOT NULL,
  `Blob` BLOB,
  PRIMARY KEY (`TableHash`,`RecordId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
