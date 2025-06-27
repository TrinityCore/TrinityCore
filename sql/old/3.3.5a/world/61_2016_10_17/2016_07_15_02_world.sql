--
DELETE FROM `npc_text` WHERE `ID`=50000;
INSERT INTO `npc_text` (`ID`, `text0_0`, `VerifiedBuild`) VALUES
(50000, "The land has been good to our people, $c. We must be thankful for our good fortune.", -1);

DELETE FROM `gossip_menu` WHERE `entry`=50000;
INSERT INTO `gossip_menu` (`entry`, `text_id`, `VerifiedBuild`) VALUES (50000, 50000, -1);

UPDATE `creature_template` SET `gossip_menu_id`=50000 WHERE `entry`=2993;
