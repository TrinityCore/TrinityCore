-- Mor'rogal --> Add Gossip Text
UPDATE `creature_template` SET `gossip_menu_id`=4721 WHERE `entry`=11861;

DELETE FROM `gossip_menu` WHERE `MenuID`=4721;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(4721,5773,0);
