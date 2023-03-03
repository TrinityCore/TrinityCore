ALTER TABLE `creature_template`
  ADD `FadeRegionRadius` float NOT NULL DEFAULT '0' AFTER `movementId`,
  ADD `WidgetSetID` int(11) NOT NULL DEFAULT '0' AFTER `FadeRegionRadius`,
  ADD `WidgetSetUnitConditionID` int(11) NOT NULL DEFAULT '0' AFTER `WidgetSetID`;

ALTER TABLE `playerchoice` ADD `SoundKitId` int(10) unsigned NOT NULL DEFAULT '0' AFTER `UiTextureKitId`;
ALTER TABLE `playerchoice_response`
  ADD `UiTextureAtlasElementID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `WidgetSetID`,
  ADD `SoundKitID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `UiTextureAtlasElementID`,
  ADD `SubHeader` varchar(100) NOT NULL DEFAULT '' AFTER `Header`,
  ADD `ButtonTooltip` varchar(400) NOT NULL DEFAULT '' AFTER `SubHeader`,
  ADD `RewardQuestID` int(10) unsigned DEFAULT NULL AFTER `Confirmation`;

ALTER TABLE `playerchoice_response_locale`
  ADD `SubHeader` varchar(100) NOT NULL DEFAULT '' AFTER `Header`,
  ADD `ButtonTooltip` varchar(400) NOT NULL DEFAULT '' AFTER `SubHeader`;

ALTER TABLE `quest_template` ADD `ManagedWorldStateID` int(11) NOT NULL DEFAULT '0' AFTER `Expansion`;
