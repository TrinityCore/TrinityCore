DROP TABLE IF EXISTS `gm_subsurveys`;
CREATE TABLE `gm_subsurveys` (
  `surveyid` int(10) NOT NULL auto_increment,
  `subsurveyid` int(11) UNSIGNED NOT NULL DEFAULT '0',
  `rank` int(11) UNSIGNED NOT NULL DEFAULT '0',
  `comment` longtext NOT NULL,
  PRIMARY KEY (`surveyid`,`subsurveyid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Player System';
