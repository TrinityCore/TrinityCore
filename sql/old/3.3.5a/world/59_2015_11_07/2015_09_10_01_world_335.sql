ALTER TABLE `quest_template`
  CHANGE COLUMN `RequiredRaces`            `AllowableRaces`    SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `TimeAllowed`,
  CHANGE COLUMN `RequiredSourceItemId1`    `ItemDrop1`         MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0' AFTER `RewardAmount4`,
  CHANGE COLUMN `RequiredSourceItemCount1` `ItemDropQuantity1` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `ItemDrop1`,
  CHANGE COLUMN `RequiredSourceItemId2`    `ItemDrop2`         MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0' AFTER `ItemDropQuantity1`,
  CHANGE COLUMN `RequiredSourceItemCount2` `ItemDropQuantity2` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `ItemDrop2`,
  CHANGE COLUMN `RequiredSourceItemId3`    `ItemDrop3`         MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0' AFTER `ItemDropQuantity2`,
  CHANGE COLUMN `RequiredSourceItemCount3` `ItemDropQuantity3` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `ItemDrop3`,
  CHANGE COLUMN `RequiredSourceItemId4`    `ItemDrop4`         MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0' AFTER `ItemDropQuantity3`,
  CHANGE COLUMN `RequiredSourceItemCount4` `ItemDropQuantity4` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `ItemDrop4`;
