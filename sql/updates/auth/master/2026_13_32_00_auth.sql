-- Character select campsites: warband groups (camps) and member assignments
CREATE TABLE IF NOT EXISTS `battlenet_account_warband_groups` (
  `battlenetAccountId` int unsigned NOT NULL,
  `groupId` bigint unsigned NOT NULL,
  `orderIndex` tinyint unsigned NOT NULL DEFAULT '0',
  `warbandSceneId` int unsigned NOT NULL DEFAULT '0',
  `flags` int unsigned NOT NULL DEFAULT '0',
  `contentSetId` int NOT NULL DEFAULT '0',
  `name` varchar(255) NOT NULL DEFAULT '',
  PRIMARY KEY (`battlenetAccountId`,`groupId`),
  CONSTRAINT `fk_battlenet_account_warband_groups__accountId` FOREIGN KEY (`battlenetAccountId`) REFERENCES `battlenet_accounts` (`id`) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

CREATE TABLE IF NOT EXISTS `battlenet_account_warband_group_members` (
  `battlenetAccountId` int unsigned NOT NULL,
  `groupId` bigint unsigned NOT NULL,
  `characterGuid` bigint unsigned NOT NULL,
  `warbandScenePlacementId` int unsigned NOT NULL DEFAULT '0',
  `type` int NOT NULL DEFAULT '0',
  `contentSetId` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`battlenetAccountId`,`groupId`,`characterGuid`),
  CONSTRAINT `fk_battlenet_account_warband_group_members__accountId` FOREIGN KEY (`battlenetAccountId`) REFERENCES `battlenet_accounts` (`id`) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
