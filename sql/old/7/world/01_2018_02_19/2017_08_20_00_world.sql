--
-- Table structure for table `creature_default_trainer`
--
DROP TABLE IF EXISTS `creature_default_trainer`;
CREATE TABLE `creature_default_trainer` (
  `CreatureId` int(11) UNSIGNED NOT NULL,
  `TrainerId` int(11) UNSIGNED NOT NULL DEFAULT '0',
  PRIMARY KEY (`CreatureId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
