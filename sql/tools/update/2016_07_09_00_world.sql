ALTER TABLE `custom_npc_tele_category` ADD `name_loc1` CHAR(100) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL AFTER `data1`;
ALTER TABLE `custom_npc_tele_category` ADD `name_loc2` CHAR(100) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL AFTER `name_loc1`;
ALTER TABLE `custom_npc_tele_category` ADD `name_loc3` CHAR(100) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL AFTER `name_loc2`;
ALTER TABLE `custom_npc_tele_category` ADD `name_loc4` CHAR(100) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL AFTER `name_loc3`;
ALTER TABLE `custom_npc_tele_category` ADD `name_loc5` CHAR(100) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL AFTER `name_loc4`;
ALTER TABLE `custom_npc_tele_category` ADD `name_loc6` CHAR(100) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL AFTER `name_loc5`;
ALTER TABLE `custom_npc_tele_category` ADD `name_loc7` CHAR(100) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL AFTER `name_loc6`;
ALTER TABLE `custom_npc_tele_category` ADD `name_loc8` CHAR(100) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL AFTER `name_loc7`;

ALTER TABLE `custom_npc_tele_destination` ADD `name_loc1` CHAR(100) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL AFTER `cost`;
ALTER TABLE `custom_npc_tele_destination` ADD `name_loc2` CHAR(100) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL AFTER `name_loc1`;
ALTER TABLE `custom_npc_tele_destination` ADD `name_loc3` CHAR(100) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL AFTER `name_loc2`;
ALTER TABLE `custom_npc_tele_destination` ADD `name_loc4` CHAR(100) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL AFTER `name_loc3`;
ALTER TABLE `custom_npc_tele_destination` ADD `name_loc5` CHAR(100) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL AFTER `name_loc4`;
ALTER TABLE `custom_npc_tele_destination` ADD `name_loc6` CHAR(100) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL AFTER `name_loc5`;
ALTER TABLE `custom_npc_tele_destination` ADD `name_loc7` CHAR(100) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL AFTER `name_loc6`;
ALTER TABLE `custom_npc_tele_destination` ADD `name_loc8` CHAR(100) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL AFTER `name_loc7`;

SET @Id=8000;
DELETE FROM `trinity_string` WHERE `entry` BETWEEN @Id AND @Id+2;
INSERT INTO `trinity_string` (`entry`, `content_default`, `content_loc2`, `content_loc3`) VALUES
(@Id+0, "You do not have the required level. This destination requires level", "", "Ihr habt nicht das erforderliche Level. Dieses Ziel benötigt Level"),
(@Id+1, "You do not have enough money. The price for teleportation is", "", "Ihr habt nicht genug Geld. Der Preis für die Teleportation beträgt"),
(@Id+2, "You are in combat. Come back later", "", "Ihr seid in einem Kampf verwickelt. Kommt später wieder.");
