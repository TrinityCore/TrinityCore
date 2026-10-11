ALTER TABLE `playerchoice`
  MODIFY `Duration` bigint NULL DEFAULT 0 AFTER `CloseSoundKitId`,
  ADD `InfiniteRange` tinyint(1) UNSIGNED NOT NULL DEFAULT 0 AFTER `Question`,
  MODIFY `HideWarboardHeader` tinyint(1) UNSIGNED NOT NULL DEFAULT 0 AFTER `Question`,
  MODIFY `KeepOpenAfterChoice` tinyint(1) UNSIGNED NOT NULL DEFAULT 0 AFTER `HideWarboardHeader`,
  ADD `ShowChoicesAsList` tinyint(1) UNSIGNED NOT NULL DEFAULT 0 AFTER `KeepOpenAfterChoice`,
  ADD `ForceDontShowChoicesAsList` tinyint(1) UNSIGNED NOT NULL DEFAULT 0 AFTER `ShowChoicesAsList`,
  ADD `MaxResponses` int unsigned DEFAULT NULL AFTER `ForceDontShowChoicesAsList`,
  ADD `ScriptName` varchar(64) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL DEFAULT NULL AFTER `MaxResponses`;

ALTER TABLE `playerchoice_response` DROP `ResponseIdentifier`;
