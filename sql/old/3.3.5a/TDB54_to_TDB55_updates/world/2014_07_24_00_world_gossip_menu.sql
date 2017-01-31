-- Missing Gossip for Strahad Farsan
DELETE FROM `gossip_menu` WHERE `entry`=2385;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (2385,2193);
