-- Add some missing go gossip
DELETE FROM `gossip_menu` WHERE `entry` IN (6448,6449,6450,6451);
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(6448,7669),(6449,7670),(6450,7673),(6451,7674);
