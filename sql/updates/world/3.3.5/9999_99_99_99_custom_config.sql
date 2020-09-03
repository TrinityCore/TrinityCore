-- ----------------------------
-- Table structure for custom_config
-- ----------------------------
DROP TABLE IF EXISTS `custom_config`;
CREATE TABLE `custom_config`  (
  `OptionName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `Type` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT 'Support types - bool, int, float, string',
  `DefaultValue` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `CustomValue` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `Description` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  PRIMARY KEY (`OptionName`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of custom_config
-- ----------------------------
INSERT INTO `custom_config` (`OptionName`, `Type`, `DefaultValue`, `CustomValue`, `Description`) VALUES
('TestOption.Bool', 'bool', '1', NULL, 'Test option bool'),
('TestOption.Float', 'float', '1.5232', NULL, 'Test option float'),
('TestOption.Int', 'int', '100', NULL, 'Test option int'),
('TestOption.String', 'string', 'test string', NULL, 'Test option string');
