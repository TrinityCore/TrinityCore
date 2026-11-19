ALTER TABLE `item_upgrade`
  CHANGE `CurrencyCost` `CurrencyCost` int(10) unsigned NOT NULL DEFAULT '0' AFTER `ID`,
  CHANGE `PrevItemUpgradeID` `PrevItemUpgradeID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `CurrencyCost`,
  CHANGE `CurrencyID` `CurrencyID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `PrevItemUpgradeID`,
  CHANGE `ItemUpgradePathID` `ItemUpgradePathID` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `CurrencyID`,
  CHANGE `ItemLevelBonus` `ItemLevelBonus` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `ItemUpgradePathID`;

ALTER TABLE `ruleset_item_upgrade`
  CHANGE `ItemID` `ItemID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `ID`,
  CHANGE `ItemUpgradeID` `ItemUpgradeID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `ItemID`,
  DROP `RulesetID`;

ALTER TABLE `skill_line_ability` CHANGE `AquireMethod` `AcquireMethod` tinyint(3) unsigned NOT NULL DEFAULT '0';
