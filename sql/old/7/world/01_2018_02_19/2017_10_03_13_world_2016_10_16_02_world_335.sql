--
UPDATE `creature_template` SET `gossip_menu_id`=10941 WHERE `entry`=10941;
DELETE FROM `gossip_menu` WHERE `entry`=10941;
INSERT INTO `gossip_menu` (`entry`, `text_id`, `VerifiedBuild`) VALUES
(10941, 10299, 0);
