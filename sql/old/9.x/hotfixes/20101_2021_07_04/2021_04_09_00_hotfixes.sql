ALTER TABLE `chr_customization_element` ADD `ChrCustItemGeoModifyID` int(11) NOT NULL DEFAULT '0' AFTER `ChrCustomizationDisplayInfoID`;

ALTER TABLE `item_bonus_tree_node`
  ADD `ItemBonusListGroupID` int(11) NOT NULL DEFAULT '0' AFTER `ChildItemLevelSelectorID`,
  ADD `ParentItemBonusTreeNodeID` int(11) NOT NULL DEFAULT '0' AFTER `ItemBonusListGroupID`;

ALTER TABLE `rand_prop_points`
  ADD `DamageReplaceStatF` float NOT NULL DEFAULT '0' AFTER `ID`,
  ADD `DamageSecondaryF` float NOT NULL DEFAULT '0' AFTER `DamageReplaceStatF`,
  ADD `EpicF1` float NOT NULL DEFAULT '0' AFTER `DamageSecondary`,
  ADD `EpicF2` float NOT NULL DEFAULT '0' AFTER `EpicF1`,
  ADD `EpicF3` float NOT NULL DEFAULT '0' AFTER `EpicF2`,
  ADD `EpicF4` float NOT NULL DEFAULT '0' AFTER `EpicF3`,
  ADD `EpicF5` float NOT NULL DEFAULT '0' AFTER `EpicF4`,
  ADD `SuperiorF1` float NOT NULL DEFAULT '0' AFTER `Epic5`,
  ADD `SuperiorF2` float NOT NULL DEFAULT '0' AFTER `SuperiorF1`,
  ADD `SuperiorF3` float NOT NULL DEFAULT '0' AFTER `SuperiorF2`,
  ADD `SuperiorF4` float NOT NULL DEFAULT '0' AFTER `SuperiorF3`,
  ADD `SuperiorF5` float NOT NULL DEFAULT '0' AFTER `SuperiorF4`,
  ADD `GoodF1` float NOT NULL DEFAULT '0' AFTER `SuperiorF5`,
  ADD `GoodF2` float NOT NULL DEFAULT '0' AFTER `GoodF1`,
  ADD `GoodF3` float NOT NULL DEFAULT '0' AFTER `GoodF2`,
  ADD `GoodF4` float NOT NULL DEFAULT '0' AFTER `GoodF3`,
  ADD `GoodF5` float NOT NULL DEFAULT '0' AFTER `GoodF4`;
