UPDATE `creature_template` SET `gossip_menu_id`=10497,`npcflag`=3 WHERE  `entry`=34320;

DELETE FROM `gossip_menu` WHERE `entry`=10497;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(10497, 14527); -- 34320
