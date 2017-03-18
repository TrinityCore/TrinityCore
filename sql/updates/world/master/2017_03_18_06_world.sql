-- Add Missing Gossip Menus
DELETE FROM `gossip_menu` WHERE `entry` IN (15727,15730);
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(15727,22587),(15730,22590);
