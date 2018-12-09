TRUNCATE `character_pvp_talent`;
ALTER TABLE `character_pvp_talent`
  DROP PRIMARY KEY,
  CHANGE `talentId` `talentId0` int(10) unsigned NOT NULL AFTER `guid`,
  ADD `talentId1` int(10) unsigned NOT NULL AFTER `talentId0`,
  ADD `talentId2` int(10) unsigned NOT NULL AFTER `talentId1`,
  ADD `talentId3` int(10) unsigned NOT NULL AFTER `talentId2`,
  ADD PRIMARY KEY(`guid`,`talentGroup`);
