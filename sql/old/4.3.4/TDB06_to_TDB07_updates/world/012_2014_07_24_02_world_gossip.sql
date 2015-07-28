-- Missing Gossip for Doc Mixilpixil
UPDATE `creature_template` SET `gossip_menu_id`=5763 WHERE `entry`=7207;
DELETE FROM `gossip_menu` WHERE `entry`=5763;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (5763,6948);
