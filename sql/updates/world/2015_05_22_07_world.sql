--
DELETE FROM `gossip_menu` WHERE `entry`=1483 AND `text_id`=2155;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES (1483, 2155);
UPDATE `creature_template` SET `gossip_menu_id`=1483 WHERE `entry`=8767;
