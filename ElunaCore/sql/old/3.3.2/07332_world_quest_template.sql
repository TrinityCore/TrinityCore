-- Update quest_template table for 3.3.0
ALTER TABLE `quest_template` ADD `RewXPId` TINYINT(2) UNSIGNED NOT NULL DEFAULT '0' AFTER `NextQuestInChain`;
ALTER TABLE `quest_template` ADD `RewHonorMultiplier` FLOAT NOT NULL DEFAULT '1' AFTER `RewHonorableKills`;
ALTER TABLE `quest_template` ADD `RewardArenaPoints` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `BonusTalents`;
ALTER TABLE `quest_template` ADD `unk0` TINYINT(2) UNSIGNED NOT NULL DEFAULT '0' AFTER `RewHonorMultiplier`;
ALTER TABLE `quest_template` ADD `RewRepValueId1` MEDIUMINT(6) NOT NULL DEFAULT '0' AFTER `RewRepFaction5`;
ALTER TABLE `quest_template` ADD `RewRepValueId2` MEDIUMINT(6) NOT NULL DEFAULT '0' AFTER `RewRepValueId1`;
ALTER TABLE `quest_template` ADD `RewRepValueId3` MEDIUMINT(6) NOT NULL DEFAULT '0' AFTER `RewRepValueId2`;
ALTER TABLE `quest_template` ADD `RewRepValueId4` MEDIUMINT(6) NOT NULL DEFAULT '0' AFTER `RewRepValueId3`;
ALTER TABLE `quest_template` ADD `RewRepValueId5` MEDIUMINT(6) NOT NULL DEFAULT '0' AFTER `RewRepValueId4`;

ALTER TABLE `quest_template` ADD `CompletionText` TEXT NULL DEFAULT NULL AFTER `EndText`;

ALTER TABLE `quest_template` ADD `WDBVerified` SMALLINT(5) SIGNED DEFAULT 0 AFTER `CompleteScript`;
ALTER TABLE `quest_template` CHANGE COLUMN `RewHonorableKills` `RewHonorAddition` int(10) NOT NULL default '0';
