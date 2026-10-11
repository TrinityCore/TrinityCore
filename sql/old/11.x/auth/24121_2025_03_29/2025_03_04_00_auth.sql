--
-- Table structure for table `battlenet_account_warband_scenes`
--
DROP TABLE IF EXISTS `battlenet_account_warband_scenes`;
CREATE TABLE `battlenet_account_warband_scenes` (
  `battlenetAccountId` int unsigned NOT NULL,
  `warbandSceneId` int NOT NULL DEFAULT '0',
  `isFavorite` tinyint(1) DEFAULT '0',
  `hasFanfare` tinyint(1) DEFAULT '0',
  PRIMARY KEY (`battlenetAccountId`,`warbandSceneId`),
  CONSTRAINT `fk_battlenet_account_warband_scenes__accountId` FOREIGN KEY (`battlenetAccountId`) REFERENCES `battlenet_accounts` (`id`) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
