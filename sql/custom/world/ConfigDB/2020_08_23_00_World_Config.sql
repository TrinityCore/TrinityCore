-- ----------------------------
-- Table structure for world_config
-- ----------------------------
DROP TABLE IF EXISTS `world_config`;
CREATE TABLE `world_config`  (
  `OptionName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `Type` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT 'Support types - bool, int, float, string',
  `IDInTypeGroup` int(10) NOT NULL,
  `DefaultValue` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `CustomValue` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `Description` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
  PRIMARY KEY (`OptionName`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;
