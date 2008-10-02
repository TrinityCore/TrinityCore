DROP TABLE IF EXISTS `creature_onkill_reputation`;
CREATE TABLE `creature_onkill_reputation` (
  `creature_id` int(10) unsigned NOT NULL default '0' COMMENT 'Creature Identifier',
  `RewOnKillRepFaction1` int(10) default '0',
  `RewOnKillRepFaction2` int(10) default '0',
  `MaxStanding1` int(1) default '0',
  `IsTeamAward1` int(1) default '0',
  `RewOnKillRepValue1` int(10) default '0',
  `MaxStanding2` int(1) default '0',
  `IsTeamAward2` int(1) default '0',
  `RewOnKillRepValue2` int(10) default '0',
  PRIMARY KEY (`creature_id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Creature OnKill Reputation gain';
