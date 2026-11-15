--
-- Table structure for table `battlenet_account_transmog_outfits`
--
DROP TABLE IF EXISTS `battlenet_account_transmog_outfits`;
CREATE TABLE `battlenet_account_transmog_outfits` (
  `battlenetAccountId` int unsigned NOT NULL,
  `transmogOutfitId` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`battlenetAccountId`,`transmogOutfitId`),
  CONSTRAINT `fk_battlenet_account_transmog_outfits` FOREIGN KEY (`battlenetAccountId`) REFERENCES `battlenet_accounts` (`id`) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
