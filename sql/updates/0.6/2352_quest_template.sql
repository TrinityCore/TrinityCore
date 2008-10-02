ALTER TABLE `quest_template` 
  CHANGE `ReqKillMobOrGOId1` `ReqCreatureOrGOId1` int(11) NOT NULL default '0',
  CHANGE `ReqKillMobOrGOId2` `ReqCreatureOrGOId2` int(11) NOT NULL default '0',
  CHANGE `ReqKillMobOrGOId3` `ReqCreatureOrGOId3` int(11) NOT NULL default '0',
  CHANGE `ReqKillMobOrGOId4` `ReqCreatureOrGOId4` int(11) NOT NULL default '0',
  CHANGE `ReqKillMobOrGOCount1` `ReqCreatureOrGOCount1` int(11) unsigned NOT NULL default '0',
  CHANGE `ReqKillMobOrGOCount2` `ReqCreatureOrGOCount2` int(11) unsigned NOT NULL default '0',
  CHANGE `ReqKillMobOrGOCount3` `ReqCreatureOrGOCount3` int(11) unsigned NOT NULL default '0',
  CHANGE `ReqKillMobOrGOCount4` `ReqCreatureOrGOCount4` int(11) unsigned NOT NULL default '0',
  ADD COLUMN `ReqSpellCast1` int(11) unsigned NOT NULL default '0' AFTER `ReqCreatureOrGOCount4`,
  ADD COLUMN `ReqSpellCast2` int(11) unsigned NOT NULL default '0' AFTER `ReqSpellCast1`,
  ADD COLUMN `ReqSpellCast3` int(11) unsigned NOT NULL default '0' AFTER `ReqSpellCast2`,
  ADD COLUMN `ReqSpellCast4` int(11) unsigned NOT NULL default '0' AFTER `ReqSpellCast3`;
