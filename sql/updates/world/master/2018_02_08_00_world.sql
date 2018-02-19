ALTER TABLE `guild_rewards` CHANGE `RaceMask` `RaceMask` bigint(20) unsigned DEFAULT '0';

ALTER TABLE `playerchoice`
  ADD `UiTextureKitId` int(11) NOT NULL DEFAULT '0' AFTER `ChoiceId`,
  ADD `HideWarboardHeader` tinyint(1) NOT NULL DEFAULT '0' AFTER `Question`;

ALTER TABLE `quest_poi` ADD `AlwaysAllowMergingBlobs` tinyint(1) unsigned NOT NULL DEFAULT '0' AFTER `WoDUnk1`;

ALTER TABLE `quest_template`
  ADD `MaxScalingLevel` int(11) NOT NULL DEFAULT '255' AFTER `QuestLevel`,
  CHANGE `AllowableRaces` `AllowableRaces` bigint(20) unsigned NOT NULL DEFAULT 0xFFFFFFFFFFFFFFFF;

RENAME TABLE `race_expansion_requirement` TO `race_unlock_requirement`;
ALTER TABLE `race_unlock_requirement` ADD `achievementId` int(10) unsigned NOT NULL DEFAULT '0';
