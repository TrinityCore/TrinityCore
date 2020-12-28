--
-- Table structure for table `vehicle_template`
--
DROP TABLE IF EXISTS `vehicle_template`;
CREATE TABLE `vehicle_template` (
  `creatureId` int(10) unsigned NOT NULL,
  `despawnDelayMs` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`creatureId`)
) ENGINE=MyISAM;
