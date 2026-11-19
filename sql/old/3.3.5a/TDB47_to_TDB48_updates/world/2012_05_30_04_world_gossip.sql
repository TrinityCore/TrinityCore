-- Add missing gossip for Book "Soothsaying for Dummies"
DELETE FROM `gossip_menu` WHERE `entry`=7058;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (7058,8321);
