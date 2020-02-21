DROP TABLE IF EXISTS `guild_challenges`;
CREATE TABLE `guild_challenges`
(  
  `ChallengeType` MEDIUMINT(1) UNSIGNED NOT NULL DEFAULT 0,
  `ChallengeCount` MEDIUMINT(5) UNSIGNED DEFAULT 1,
  `Experience` MEDIUMINT(10) UNSIGNED DEFAULT 0,
  `Gold` MEDIUMINT(10) UNSIGNED DEFAULT 0,
  `GoldMaxLevel` MEDIUMINT(10) UNSIGNED DEFAULT 0,
  PRIMARY KEY (`ChallengeType`)
);

INSERT INTO `guild_challenges` (`ChallengeType`, `ChallengeCount`, `Experience`, `Gold`, `GoldMaxLevel`) VALUES
(0, 0, 0, 0, 0),
(1, 7, 300000, 125, 250),
(2, 1, 3000000, 500, 1000),
(3, 3, 1500000, 250, 500);
