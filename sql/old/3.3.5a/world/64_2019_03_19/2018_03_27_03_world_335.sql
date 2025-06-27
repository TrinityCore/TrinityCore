-- 
-- Dreka'Sur --> Add Gossip Text
UPDATE `creature_template` SET `gossip_menu_id`=4067 WHERE `entry`=9620;
DELETE FROM `gossip_menu` WHERE `MenuID`=4067;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(4067,4960,0);
