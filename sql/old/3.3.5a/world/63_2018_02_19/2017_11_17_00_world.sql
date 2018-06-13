-- Maggran Earthbinder --> Add Gossip Text
UPDATE `creature_template` SET `gossip_menu_id`=4271 WHERE `entry`=11860;

DELETE FROM `gossip_menu` WHERE `MenuID`=4271;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(4271,5443,0);
