-- RewardItem(s) and RewardAmount(s) [4x2 fields]
ALTER TABLE `quest_template`
  CHANGE COLUMN `RewardAmount1` `RewardAmount1` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `RewardItem1`,
  CHANGE COLUMN `RewardAmount2` `RewardAmount2` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `RewardItem2`,
  CHANGE COLUMN `RewardAmount3` `RewardAmount3` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `RewardItem3`,
  CHANGE COLUMN `RewardAmount4` `RewardAmount4` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `RewardItem4`;

-- RewardChoiceItemID(s) and RewardChoiceItemQuantity(s) [6x2 fields]
ALTER TABLE `quest_template`
  CHANGE COLUMN `RewardChoiceItemQuantity1` `RewardChoiceItemQuantity1` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `RewardChoiceItemID1`,
  CHANGE COLUMN `RewardChoiceItemQuantity2` `RewardChoiceItemQuantity2` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `RewardChoiceItemID2`,
  CHANGE COLUMN `RewardChoiceItemQuantity3` `RewardChoiceItemQuantity3` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `RewardChoiceItemID3`,
  CHANGE COLUMN `RewardChoiceItemQuantity4` `RewardChoiceItemQuantity4` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `RewardChoiceItemID4`,
  CHANGE COLUMN `RewardChoiceItemQuantity5` `RewardChoiceItemQuantity5` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `RewardChoiceItemID5`,
  CHANGE COLUMN `RewardChoiceItemQuantity6` `RewardChoiceItemQuantity6` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `RewardChoiceItemID6`;

-- RewardFactionID(s), RewardFactionValue(s) and RewardFactionOverride(s) [5x3 fields]
ALTER TABLE `quest_template`
  CHANGE COLUMN `RewardFactionValue1`     `RewardFactionValue1`     MEDIUMINT(8) NOT NULL DEFAULT '0' AFTER `RewardFactionID1`,
  CHANGE COLUMN `RewardFactionOverride1`  `RewardFactionOverride1`  MEDIUMINT(8) NOT NULL DEFAULT '0' AFTER `RewardFactionValue1`,
  CHANGE COLUMN `RewardFactionValue2`     `RewardFactionValue2`     MEDIUMINT(8) NOT NULL DEFAULT '0' AFTER `RewardFactionID2`,
  CHANGE COLUMN `RewardFactionOverride2`  `RewardFactionOverride2`  MEDIUMINT(8) NOT NULL DEFAULT '0' AFTER `RewardFactionValue2`,
  CHANGE COLUMN `RewardFactionValue3`     `RewardFactionValue3`     MEDIUMINT(8) NOT NULL DEFAULT '0' AFTER `RewardFactionID3`,
  CHANGE COLUMN `RewardFactionOverride3`  `RewardFactionOverride3`  MEDIUMINT(8) NOT NULL DEFAULT '0' AFTER `RewardFactionValue3`,
  CHANGE COLUMN `RewardFactionValue4`     `RewardFactionValue4`     MEDIUMINT(8) NOT NULL DEFAULT '0' AFTER `RewardFactionID4`,
  CHANGE COLUMN `RewardFactionOverride4`  `RewardFactionOverride4`  MEDIUMINT(8) NOT NULL DEFAULT '0' AFTER `RewardFactionValue4`,
  CHANGE COLUMN `RewardFactionValue5`     `RewardFactionValue5`     MEDIUMINT(8) NOT NULL DEFAULT '0' AFTER `RewardFactionID5`,
  CHANGE COLUMN `RewardFactionOverride5`  `RewardFactionOverride5`  MEDIUMINT(8) NOT NULL DEFAULT '0' AFTER `RewardFactionValue5`;
