ALTER TABLE `lfg_dungeons` ADD `PlayerConditionID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `Description`;

ALTER TABLE `map`
  CHANGE `Flags` `Flags1` int(10) unsigned NOT NULL DEFAULT 0 AFTER `Directory`,
  CHANGE `MapType` `Flags2` int(10) unsigned NOT NULL DEFAULT 0 AFTER `Flags1`,
  ADD `WindSettingsID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `CosmeticParentMapID`;

ALTER TABLE `player_condition`
  CHANGE `Unknown700_1` `Unknown7001` int(10) unsigned NOT NULL DEFAULT 0 AFTER `MaxAvgItemLevel`,
  CHANGE `Unknown700_2` `Unknown7002` int(10) unsigned NOT NULL DEFAULT 0 AFTER `Unknown7001`;

ALTER TABLE `world_map_transforms` ADD `AreaID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `MapID`;
