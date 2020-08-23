-- ----------------------------
-- Table structure for game_config
-- ----------------------------
DROP TABLE IF EXISTS `game_config`;
CREATE TABLE `game_config`  (
  `OptionName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `Type` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT 'Support types - bool, int, float, string',
  `DefaultValue` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `CustomValue` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `Description` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  PRIMARY KEY (`OptionName`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of game_config
-- ----------------------------
INSERT INTO `game_config` VALUES ('TestOption.Bool', 'bool', '1', NULL, 'Test option bool');
INSERT INTO `game_config` VALUES ('TestOption.Float', 'float', '1.5232', NULL, 'Test option float');
INSERT INTO `game_config` VALUES ('TestOption.Int', 'int', '100', NULL, 'Test option int');
INSERT INTO `game_config` VALUES ('TestOption.String', 'string', 'test string', NULL, 'Test option string');
