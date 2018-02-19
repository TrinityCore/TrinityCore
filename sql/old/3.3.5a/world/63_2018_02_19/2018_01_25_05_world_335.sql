-- Primal Torntusk --> Add Gossip Text
UPDATE `creature_template` SET `gossip_menu_id`=6084 WHERE `entry`=14736;

DELETE FROM `gossip_menu` WHERE `MenuID`=6084;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(6084,7238,0);
