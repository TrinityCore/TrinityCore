CREATE TABLE `scenario_criteria_progress` (
  `instanceId` int(10) unsigned NOT NULL,
  `criteria` smallint(5) unsigned NOT NULL,
  `counter` int(10) unsigned NOT NULL,
  `date` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`instanceId`,`criteria`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;