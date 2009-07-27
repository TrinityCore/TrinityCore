-- ----------------------------
-- Table structure for channels
-- ----------------------------
DROP TABLE IF EXISTS `channels`;
CREATE TABLE `channels` (
  `m_name` text NOT NULL,
  `m_team` int(10) unsigned NOT NULL,
  `m_ownerGUID` int(11) unsigned NOT NULL default '0',
  `m_announce` tinyint(1) unsigned NOT NULL default '0',
  `m_moderate` tinyint(1) unsigned NOT NULL default '0',
  `m_password` text,
  `BannedList` longtext,
  PRIMARY KEY  (`m_name`(10),`m_team`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Channel System';