DROP TABLE IF EXISTS `raidgroup`;
CREATE TABLE `raidgroup` (
  `leaderGuid` bigint(20) NOT NULL,
  `lootMethod` int(11) NOT NULL,
  `looterGuid` bigint(20) NOT NULL,
  `icon1` bigint(20) NOT NULL,
  `icon2` bigint(20) NOT NULL,
  `icon3` bigint(20) NOT NULL,
  `icon4` bigint(20) NOT NULL,
  `icon5` bigint(20) NOT NULL,
  `icon6` bigint(20) NOT NULL,
  `icon7` bigint(20) NOT NULL,
  `icon8` bigint(20) NOT NULL,
  PRIMARY KEY  (`leaderGuid`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='RaidGroups';

DROP TABLE IF EXISTS `raidgroup_member`;
CREATE TABLE `raidgroup_member` (
  `leaderGuid` bigint(20) NOT NULL,
  `memberGuid` bigint(20) NOT NULL,
  `assistant` tinyint(1) NOT NULL,
  `subgroup` smallint(6) NOT NULL,
  PRIMARY KEY  (`leaderGuid`,`memberGuid`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='RaidGroups';