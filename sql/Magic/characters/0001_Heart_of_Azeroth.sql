CREATE TABLE `project_item_instance_azerite` (
  `itemGuid` bigint(20) unsigned NOT NULL,
  `level` int(10) unsigned NOT NULL DEFAULT '1',
  `xp` bigint(20) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`itemGuid`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

CREATE TABLE `project_item_instance_azerite_empowered` (
  `itemGuid` bigint(20) unsigned NOT NULL,
  `power0` int(10) unsigned NOT NULL DEFAULT '0',
  `power1` int(10) unsigned NOT NULL DEFAULT '0',
  `power2` int(10) unsigned NOT NULL DEFAULT '0',
  `power3` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`itemGuid`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

