UPDATE creature_template SET `npcflag` = 0, `gossip_menu_id` = 4108 WHERE entry = 12018;

DELETE FROM creature WHERE id = 54404;

DELETE FROM `gossip_menu` WHERE MenuId = 4108;
INSERT INTO `gossip_menu` VALUES (4108, 5012, 0);
