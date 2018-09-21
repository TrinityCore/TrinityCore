--
-- Table structure for table `character_queststatus_objectives_criteria`
--
DROP TABLE IF EXISTS `character_queststatus_objectives_criteria`;
CREATE TABLE `character_queststatus_objectives_criteria` (
  `guid` bigint(20) unsigned NOT NULL,
  `questObjectiveId` int(10) unsigned NOT NULL,
  PRIMARY KEY (`guid`,`questObjectiveId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Table structure for table `character_queststatus_objectives_criteria_progress`
--
DROP TABLE IF EXISTS `character_queststatus_objectives_criteria_progress`;
CREATE TABLE `character_queststatus_objectives_criteria_progress` (
  `guid` bigint(20) unsigned NOT NULL,
  `criteriaId` int(10) unsigned NOT NULL,
  `counter` bigint(20) unsigned NOT NULL,
  `date` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`,`criteriaId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
