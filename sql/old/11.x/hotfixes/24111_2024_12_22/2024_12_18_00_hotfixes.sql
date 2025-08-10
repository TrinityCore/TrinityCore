ALTER TABLE `broadcast_text` MODIFY `Flags` smallint UNSIGNED NOT NULL DEFAULT 0 AFTER `EmotesID`;

ALTER TABLE `lfg_dungeons`
  ADD `MaxPremadeCountTank` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `MinCountDamage`,
  ADD `MaxPremadeCountHealer` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `MaxPremadeCountTank`,
  ADD `MaxPremadeCountDamage` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `MaxPremadeCountHealer`;

ALTER TABLE `map_difficulty` MODIFY `ID` int UNSIGNED NOT NULL DEFAULT 0 AFTER `Message`;

ALTER TABLE `player_condition`
  ADD `MinLevel` smallint UNSIGNED NOT NULL DEFAULT 0 AFTER `FailureDescription`,
  ADD `MaxLevel` smallint UNSIGNED NOT NULL DEFAULT 0 AFTER `MinLevel`;

ALTER TABLE `vignette`
  ADD `UiMapPinInfoID` int NOT NULL DEFAULT 0 AFTER `UiWidgetSetID`,
  ADD `ObjectiveType` tinyint NOT NULL DEFAULT 0 AFTER `UiMapPinInfoID`;
