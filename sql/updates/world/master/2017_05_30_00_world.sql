-- #19750 quest 11548
DELETE FROM `gossip_menu_option` WHERE `menu_id`=9115 AND `id`=0;
INSERT INTO `gossip_menu_option` VALUES (9115,0,0,'',0,0,0,0,0,0,100000,'Completing this quest requires the following amount of gold.Are you sure you want to complete this quest?',0,0);
