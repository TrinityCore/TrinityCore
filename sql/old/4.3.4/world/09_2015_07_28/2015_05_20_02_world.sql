--
UPDATE `gossip_menu_option` SET `action_menu_id`=943 WHERE `menu_id`=942 AND `id`=0;
UPDATE `gossip_menu_option` SET `action_menu_id`=944 WHERE `menu_id`=942 AND `id`=1;
DELETE FROM `gossip_menu` WHERE `entry` IN (944,943);
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (943,1521),(944,1646);
