CREATE TABLE `character_research_digsites` (
  `guid` int(11) NOT NULL COMMENT 'Global Unique Identifier',
  `digsiteId` int(11) NOT NULL,
  `currentFindGUID` int(11) NOT NULL DEFAULT '0',
  `remainingFindCount` tinyint(3) NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`, `digsiteId`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

CREATE TABLE `character_research_history` (
  `guid` int(11) NOT NULL COMMENT 'Global Unique Identifier',
  `projectId` int(11) NOT NULL,
  `researchCount` int(11) NOT NULL,
  `firstResearchTimestamp` int(11) NOT NULL,
  PRIMARY KEY (`guid`, `projectId`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

CREATE TABLE `character_research_projects` (
  `guid` int(11) NOT NULL COMMENT 'Global Unique Identifier',
  `projectId` int(11) NOT NULL,
  PRIMARY KEY (`guid`, `projectId`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
