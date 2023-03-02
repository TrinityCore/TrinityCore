CREATE TABLE `research_digsite_data` (
  `digsiteId` int(11) NOT NULL,
  `branchId` tinyint(3) NOT NULL,
  `requiredSkillValue` int(11) NOT NULL DEFAULT '0',
  `requiredLevel` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`digsiteId`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

CREATE TABLE `research_digsite_finds` (
  `guid` int(11) NOT NULL AUTO_INCREMENT COMMENT 'Global Unique Identifier',
  `digsiteId` int(11) NOT NULL,
  `goEntry` int(11) NOT NULL,
  `position_x` float NOT NULL DEFAULT '0',
  `position_y` float NOT NULL DEFAULT '0',
  `position_z` float NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

CREATE TABLE `research_project_requirements` (
  `projectId` int(11) NOT NULL,
  `requiredSkillValue` int(11) NOT NULL DEFAULT '0',
  `chance` float NOT NULL DEFAULT '0',
  PRIMARY KEY (`projectId`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
