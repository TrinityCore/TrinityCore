--
-- Table structure for table `spell_pet_auras`
--

DROP TABLE IF EXISTS `spell_pet_auras`;
CREATE TABLE `spell_pet_auras` (
  `spell` mediumint(8) unsigned NOT NULL COMMENT 'dummy spell id',
  `pet` mediumint(8) unsigned NOT NULL default '0' COMMENT 'pet id; 0 = all',
  `aura` mediumint(8) unsigned NOT NULL COMMENT 'pet aura id',
  PRIMARY KEY  (`spell`,`pet`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `spell_pet_auras`
--

LOCK TABLES `spell_pet_auras` WRITE;
/*!40000 ALTER TABLE `spell_pet_auras` DISABLE KEYS */;
INSERT INTO `spell_pet_auras` VALUES
(19028, 0, 25228),
(19578, 0, 19579),
(20895, 0, 24529),
(28757, 0, 28758),
(35029, 0, 35060),
(35030, 0, 35061),
(35691, 0, 35696),
(35692, 0, 35696),
(35693, 0, 35696),
(23785, 416, 23759),
(23822, 416, 23826),
(23823, 416, 23827),
(23824, 416, 23828),
(23825, 416, 23829),
(23785, 417, 23762),
(23822, 417, 23837),
(23823, 417, 23838),
(23824, 417, 23839),
(23825, 417, 23840),
(23785, 1860, 23760),
(23822, 1860, 23841),
(23823, 1860, 23842),
(23824, 1860, 23843),
(23825, 1860, 23844),
(23785, 1863, 23761),
(23822, 1863, 23833),
(23823, 1863, 23834),
(23824, 1863, 23835),
(23825, 1863, 23836),
(23785, 17252, 35702),
(23822, 17252, 35703),
(23823, 17252, 35704),
(23824, 17252, 35705),
(23825, 17252, 35706);

/*!40000 ALTER TABLE `spell_pet_auras` ENABLE KEYS */;
UNLOCK TABLES;