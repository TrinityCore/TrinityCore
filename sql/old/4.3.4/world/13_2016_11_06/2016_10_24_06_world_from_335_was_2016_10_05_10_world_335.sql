--
/*
UPDATE `creature_template` SET `gossip_menu_id`=3693 WHERE `entry`=3693;
DELETE FROM `gossip_menu` WHERE `entry`=3693;
INSERT INTO `gossip_menu` (`entry`, `text_id`, `VerifiedBuild`) VALUES
(3693, 3334, 0);

UPDATE `creature_template` SET `gossip_menu_id`=3692 WHERE `entry`=3692;
DELETE FROM `gossip_menu` WHERE `entry`=3692;
INSERT INTO `gossip_menu` (`entry`, `text_id`, `VerifiedBuild`) VALUES
(3692, 3213, 0);

UPDATE `creature_template` SET `gossip_menu_id`=2080 WHERE `entry`=2080;
DELETE FROM `gossip_menu` WHERE `entry`=2080;
INSERT INTO `gossip_menu` (`entry`, `text_id`, `VerifiedBuild`) VALUES
(2080, 2080, 0);
DELETE FROM `npc_text` WHERE `ID` = 2080;
INSERT INTO `npc_text` (`ID`, `text0_0`) VALUES
(2080, "The creation of Teldrassil was a great achievement, but now the world must shift to regain its balance.");
*/
