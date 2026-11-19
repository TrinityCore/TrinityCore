--
-- Table structure for table `creature_quest_currency`
--
DROP TABLE IF EXISTS `creature_quest_currency`;
CREATE TABLE `creature_quest_currency` (
  `CreatureId` int unsigned NOT NULL,
  `CurrencyId` int NOT NULL,
  `VerifiedBuild` int NOT NULL DEFAULT 0,
  PRIMARY KEY (`CreatureId`,`CurrencyId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
