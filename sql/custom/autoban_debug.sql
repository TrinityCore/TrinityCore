SET FOREIGN_KEY_CHECKS=0;
-- ----------------------------
-- Table structure for `autoban_debug`
-- ----------------------------
/*DROP TABLE IF EXISTS `autoban_debug`;
CREATE TABLE `autoban_debug` (
  `id` int(11) NOT NULL,
  `realm` int(11) NOT NULL,
  `bandate` bigint(40) NOT NULL,
  `bannedby` varchar(255) NOT NULL,
  `banreason` varchar(255) NOT NULL,
  `mob_guid` int(10) NOT NULL,
  `mob_x` float DEFAULT NULL,
  `mob_y` float DEFAULT NULL,
  `mob_z` float DEFAULT NULL,
  `mapId` int(10) DEFAULT NULL,
  `x` float DEFAULT NULL,
  `y` float DEFAULT NULL,
  `z` float DEFAULT NULL,
  PRIMARY KEY (`id`,`bandate`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;*/

ALTER TABLE `autoban_debug`
ADD COLUMN `mob_x`  float NOT NULL AFTER `mob_guid`,
ADD COLUMN `mob_y`  float NOT NULL AFTER `mob_x`,
ADD COLUMN `mob_z`  float NOT NULL AFTER `mob_y`;

ALTER TABLE `autoban_debug`
MODIFY COLUMN `mob_x`  float NULL AFTER `mob_guid`,
MODIFY COLUMN `mob_y`  float NULL AFTER `mob_x`,
MODIFY COLUMN `mob_z`  float NULL AFTER `mob_y`,
ADD COLUMN `mapId`  int(10) NULL AFTER `mob_z`,
MODIFY COLUMN `x`  float NULL AFTER `mapId`,
MODIFY COLUMN `y`  float NULL AFTER `x`,
MODIFY COLUMN `z`  float NULL AFTER `y`;
