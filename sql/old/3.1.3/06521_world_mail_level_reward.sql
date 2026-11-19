DROP TABLE IF EXISTS `mail_level_reward`;
CREATE TABLE `mail_level_reward` (
  `level` tinyint(3) unsigned NOT NULL default '0',
  `raceMask` mediumint(8) unsigned NOT NULL default '0',
  `mailTemplateId` mediumint(8) unsigned NOT NULL default '0',
  `senderEntry`    mediumint(8) unsigned NOT NULL default '0',
  PRIMARY KEY  (`level`,`raceMask`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Mail System';

INSERT INTO `mail_level_reward` VALUES
(20, 1, 224, 4732),(20, 8, 225, 4753),
(20, 4, 226, 4772),(20, 1024, 227, 20914),
(20, 64, 228, 7954),(20, 32, 229, 3690),
(20, 128, 230, 7953),(20, 2, 231, 4752),
(20, 512, 232, 16280),(20, 16, 233, 4773);