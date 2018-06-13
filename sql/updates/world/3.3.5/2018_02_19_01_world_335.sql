-- Jediga --> Add Gossip Text
UPDATE `creature_template` SET `gossip_menu_id`=4722 WHERE `entry`=8587;
DELETE FROM `gossip_menu` WHERE `MenuID`=4722;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(4722,2036,0);
