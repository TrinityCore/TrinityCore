-- Add missing gossip for Draconic for Dummies objects
DELETE FROM `gossip_menu` WHERE `entry` IN (6668,6669,6670);
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(6668,7937),(6669,7937),(6670,7937);
