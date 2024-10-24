ALTER TABLE `custom_npc_tele_category` ADD `icon` CHAR(100) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL AFTER `id`;
ALTER TABLE `custom_npc_tele_category` ADD `size` CHAR(100) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL AFTER `icon`;
ALTER TABLE `custom_npc_tele_category` ADD `colour` CHAR(100) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL AFTER `size`;

ALTER TABLE `custom_npc_tele_destination` ADD `icon` CHAR(100) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL AFTER `id`;
ALTER TABLE `custom_npc_tele_destination` ADD `size` CHAR(100) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL AFTER `icon`;
ALTER TABLE `custom_npc_tele_destination` ADD `colour` CHAR(100) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL AFTER `size`;
