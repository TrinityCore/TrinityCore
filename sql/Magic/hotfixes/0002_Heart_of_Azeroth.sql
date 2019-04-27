CREATE TABLE `azerite_empowered_item` (
  `ID` int(10) unsigned NOT NULL,
  `ItemID` int(11) DEFAULT NULL,
  `AzeriteTierUnlockSetID` int(11) unsigned DEFAULT NULL,
  `AzeritePowerSetID` int(11) unsigned DEFAULT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

CREATE TABLE `azerite_item` (
  `ID` int(10) unsigned NOT NULL,
  `ItemID` int(11) DEFAULT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

CREATE TABLE `azerite_power` (
  `ID` int(10) unsigned NOT NULL,
  `SpellID` int(11) DEFAULT NULL,
  `ItemBonusListID` int(11) DEFAULT NULL,
  `SpecSet` int(11) DEFAULT NULL,
  `Unk0` int(11) DEFAULT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

CREATE TABLE `azerite_power_set_member` (
  `ID` int(10) unsigned NOT NULL,
  `AzeritePowerID` smallint(5) DEFAULT NULL,
  `Class` tinyint(3) unsigned DEFAULT NULL,
  `Tier` tinyint(3) unsigned DEFAULT NULL,
  `OrderIndex` tinyint(3) unsigned DEFAULT NULL,
  `AzeritePowerSetID` smallint(5) DEFAULT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

CREATE TABLE `azerite_tier_unlock` (
  `ID` int(10) unsigned NOT NULL,
  `ItemCreationContext` tinyint(3) unsigned NOT NULL,
  `Tier` tinyint(3) unsigned NOT NULL,
  `AzeriteLevel` tinyint(3) unsigned NOT NULL,
  `AzeriteTierUnlockSetId` tinyint(3) unsigned NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

