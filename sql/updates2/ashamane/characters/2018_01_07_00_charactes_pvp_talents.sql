DROP TABLE IF EXISTS `character_pvp_talent`;
CREATE TABLE `character_pvp_talent` (
  `guid` bigint(20) unsigned NOT NULL,
  `talentId` mediumint(8) unsigned NOT NULL,
  `talentGroup` tinyint(3) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`,`talentId`,`talentGroup`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

TRUNCATE `character_pvp_talent`;
ALTER TABLE `character_pvp_talent`
  DROP PRIMARY KEY,
  CHANGE `TalentID` `talentId0` int(10) unsigned NOT NULL AFTER `guid`,
  CHANGE `TalentGroup` `talentGroup` tinyint(3) unsigned NOT NULL DEFAULT '0',
  ADD `talentId1` int(10) unsigned NOT NULL AFTER `talentId0`,
  ADD `talentId2` int(10) unsigned NOT NULL AFTER `talentId1`,
  ADD `talentId3` int(10) unsigned NOT NULL AFTER `talentId2`,
  ADD PRIMARY KEY(`guid`,`talentGroup`);
