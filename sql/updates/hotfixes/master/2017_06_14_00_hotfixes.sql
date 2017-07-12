DROP TABLE IF EXISTS `area_poi`;
DROP TABLE IF EXISTS `area_poi_state`;
DROP TABLE IF EXISTS `chr_upgrade_bucket`;
DROP TABLE IF EXISTS `chr_upgrade_bucket_spell`;
DROP TABLE IF EXISTS `chr_upgrade_tier`;

ALTER TABLE `conversation_line` CHANGE `Id` `ID` int(10) UNSIGNED NOT NULL DEFAULT '0' FIRST;

ALTER TABLE `currency_types`
  ADD `InventoryIconFileDataID` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `Quality`,
  DROP `InventoryIcon1`,
  DROP `InventoryIcon2`;

ALTER TABLE `emotes` MODIFY `RaceMask` int(11) NOT NULL DEFAULT '0' AFTER `EmoteFlags`;

DROP TABLE IF EXISTS `item_level_selector`;

ALTER TABLE `heirloom`
  ADD `UpgradeItemID3` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `UpgradeItemID2`,
  ADD `ItemBonusListID3` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `ItemBonusListID2`;

ALTER TABLE `holidays`
  ADD `TextureFileDataID1` int(11) NOT NULL DEFAULT '0' AFTER `HolidayDescriptionID`,
  ADD `TextureFileDataID2` int(11) NOT NULL DEFAULT '0' AFTER `TextureFileDataID1`,
  ADD `TextureFileDataID3` int(11) NOT NULL DEFAULT '0' AFTER `TextureFileDataID2`,
  DROP `TextureFilename`;

ALTER TABLE `lfg_dungeons` MODIFY `ID` int(10) UNSIGNED NOT NULL DEFAULT '0' FIRST,
  ADD `TextureFileDataID` int(11) NOT NULL DEFAULT '0' AFTER `MentorCharLevel`,
  ADD `RewardIconFileDataID` int(11) NOT NULL DEFAULT '0' AFTER `TextureFileDataID`,
  ADD `ProposalTextureFileDataID` int(11) NOT NULL DEFAULT '0' AFTER `RewardIconFileDataID`,
  DROP `TextureFilename`;

ALTER TABLE `map_difficulty` ADD `Flags` tinyint(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `LockID`;

DROP TABLE IF EXISTS `spell_effect_group_size`;
