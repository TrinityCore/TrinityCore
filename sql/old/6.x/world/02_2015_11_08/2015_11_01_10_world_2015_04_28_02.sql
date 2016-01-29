DELETE FROM `gossip_menu` WHERE `entry`=8563;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES 
(8563, 10732); -- Blood Elf

UPDATE `creature_template` SET `gossip_menu_id`=8563 WHERE  `entry`=22817;
