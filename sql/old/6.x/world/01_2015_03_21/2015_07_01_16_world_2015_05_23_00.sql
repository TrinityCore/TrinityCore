--
UPDATE `creature_template` SET `npcflag`=3, `gossip_menu_id`=4047 WHERE `entry`=658;
DELETE FROM `gossip_menu` WHERE `entry`=4047;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (4047, 4937);
