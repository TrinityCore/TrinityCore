-- 
DROP TABLE IF EXISTS `creature_template_gossip`;
CREATE TABLE `creature_template_gossip`  (
  `CreatureID` int UNSIGNED NOT NULL,
  `MenuID` int UNSIGNED NOT NULL,
  `VerifiedBuild` int NOT NULL DEFAULT 0,
  PRIMARY KEY (`CreatureID`, `MenuID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

INSERT INTO `creature_template_gossip` SELECT `entry`, `gossip_menu_id`, `VerifiedBuild` FROM `creature_template` WHERE `gossip_menu_id` <> 0;

ALTER TABLE `creature_template` DROP COLUMN `gossip_menu_id`;
