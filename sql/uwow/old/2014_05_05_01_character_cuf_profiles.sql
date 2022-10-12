CREATE TABLE `character_cuf_profiles` (
  `guid` int(10) unsigned NOT NULL,
  `profileId` tinyint(3) unsigned NOT NULL,
  `profileName` varchar(12) NOT NULL,
  `frameHeight` smallint(5) unsigned NOT NULL DEFAULT '0',
  `frameWidth` smallint(5) unsigned NOT NULL DEFAULT '0',
  `sortBy` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `healthText` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `someOptions` int(10) unsigned NOT NULL DEFAULT '0',
  `unk146` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `unk147` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `unk148` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `unk150` smallint(5) unsigned NOT NULL DEFAULT '0',
  `unk152` smallint(5) unsigned NOT NULL DEFAULT '0',
  `unk154` smallint(5) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`,`profileId`),
  KEY `index` (`profileId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8