DROP TABLE IF EXISTS `character_pvp_talent`;
CREATE TABLE `character_pvp_talent` (
  `Guid` bigint(20) unsigned NOT NULL,
  `TalentID` mediumint(8) unsigned NOT NULL,
  `TalentGroup` tinyint(3) unsigned NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
