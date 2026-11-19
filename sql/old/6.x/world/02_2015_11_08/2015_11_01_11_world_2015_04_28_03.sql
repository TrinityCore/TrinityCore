UPDATE `creature_template` SET `gossip_menu_id`=5820 WHERE  `entry`=14444;

DELETE FROM `gossip_menu` WHERE `entry`=5820;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES 
(5820, 6993); 
