CREATE DATABASE roleplay CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci;

USE roleplay;

-- ----------------------------
-- Table structure for creature_extra
-- ----------------------------
DROP TABLE IF EXISTS `creature_extra`;
CREATE TABLE `creature_extra`  (
  `guid` bigint UNSIGNED NOT NULL,
  `scale` float NOT NULL DEFAULT -1,
  `id_creator_bnet` int UNSIGNED NOT NULL DEFAULT 0,
  `id_creator_player` bigint UNSIGNED NOT NULL DEFAULT 0,
  `id_modifier_bnet` int UNSIGNED NOT NULL DEFAULT 0,
  `id_modifier_player` bigint UNSIGNED NOT NULL DEFAULT 0,
  `created` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `modified` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `phaseMask` int UNSIGNED NOT NULL DEFAULT 1,
  `displayLock` tinyint UNSIGNED NOT NULL DEFAULT 0,
  `displayId` int UNSIGNED NOT NULL DEFAULT 0,
  `nativeDisplayId` int UNSIGNED NOT NULL DEFAULT 0,
  `genderLock` tinyint UNSIGNED NOT NULL DEFAULT 0,
  `gender` tinyint UNSIGNED NOT NULL DEFAULT 0,
  `swim` tinyint UNSIGNED NOT NULL DEFAULT 1,
  `gravity` tinyint UNSIGNED NOT NULL DEFAULT 1,
  `fly` tinyint UNSIGNED NOT NULL DEFAULT 0,
  PRIMARY KEY (`guid`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for creature_template_extra
-- ----------------------------
DROP TABLE IF EXISTS `creature_template_extra`;
CREATE TABLE `creature_template_extra`  (
  `id_entry` int UNSIGNED NOT NULL,
  `disabled` tinyint NOT NULL DEFAULT 0,
  PRIMARY KEY (`id_entry`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for custom_npcs
-- ----------------------------
DROP TABLE IF EXISTS `custom_npcs`;
CREATE TABLE `custom_npcs`  (
  `Key` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `Entry` int UNSIGNED NOT NULL,
  PRIMARY KEY (`Key`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for server_settings
-- ----------------------------
DROP TABLE IF EXISTS `server_settings`;
CREATE TABLE `server_settings`  (
    `setting_name` VARCHAR(50) NOT NULL,
    `setting_value` VARCHAR(255) NOT NULL,
    PRIMARY KEY (`setting_name`)
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = Dynamic;
