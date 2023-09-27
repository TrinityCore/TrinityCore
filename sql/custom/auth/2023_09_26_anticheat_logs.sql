--
-- Table structure for table `anticheat_logs`
--

DROP TABLE IF EXISTS `anticheat_logs`;
CREATE TABLE `anticheat_logs`  (
  `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT,
  `times` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `account` int(9) NOT NULL,
  `player` varchar(96) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `description` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `position` varchar(255) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `realmId` int(9) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE = InnoDB AUTO_INCREMENT = 0 CHARACTER SET = utf8;