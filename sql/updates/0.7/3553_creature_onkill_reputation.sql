ALTER TABLE `creature_onkill_reputation` 
  CHANGE COLUMN `MaxStanding1` `MaxStanding1` tinyint(1) default '0',
  CHANGE COLUMN `IsTeamAward1` `IsTeamAward1` tinyint(1) default '0',
  CHANGE COLUMN `MaxStanding2` `MaxStanding2` tinyint(1) default '0',
  CHANGE COLUMN `IsTeamAward2` `IsTeamAward2` tinyint(1) default '0',
  ADD COLUMN `TeamDependent` tinyint(1) unsigned NOT NULL default '0' AFTER `RewOnKillRepValue2`;
