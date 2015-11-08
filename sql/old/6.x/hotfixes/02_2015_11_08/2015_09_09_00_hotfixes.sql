DELETE FROM `battle_pet_species` WHERE `ID` IN (1449,1636); -- already in BattlePetSpecies.db2

--
-- Table structure for table `battle_pet_breed_quality`
--

DROP TABLE IF EXISTS `battle_pet_breed_quality`;
CREATE TABLE `battle_pet_breed_quality` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Quality` int(10) unsigned NOT NULL DEFAULT '0',
  `Modifier` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `battle_pet_breed_state`
--

DROP TABLE IF EXISTS `battle_pet_breed_state`;
CREATE TABLE `battle_pet_breed_state` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `BreedID` int(10) unsigned NOT NULL DEFAULT '0',
  `State` int(10) unsigned NOT NULL DEFAULT '0',
  `Value` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `battle_pet_species_locale`
--

DROP TABLE IF EXISTS `battle_pet_species_locale`;
CREATE TABLE `battle_pet_species_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `SourceText` text,
  `Description` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `battle_pet_species_state`
--

DROP TABLE IF EXISTS `battle_pet_species_state`;
CREATE TABLE `battle_pet_species_state` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `SpeciesID` int(10) unsigned NOT NULL DEFAULT '0',
  `State` int(10) unsigned NOT NULL DEFAULT '0',
  `Value` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `item_to_battle_pet_species`
--

DROP TABLE IF EXISTS `item_to_battle_pet_species`;
CREATE TABLE `item_to_battle_pet_species` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `BattlePetSpeciesID` int(10) unsigned NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
