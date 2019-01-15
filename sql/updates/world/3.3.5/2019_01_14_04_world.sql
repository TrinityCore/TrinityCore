-- 
UPDATE `creature_template` SET `gossip_menu_id`=6572 WHERE `entry`=15296;
UPDATE `creature_template` SET `gossip_menu_id`=6571 WHERE `entry`=15297;

DELETE FROM `gossip_menu` WHERE `MenuID`IN (15296,15297, 6571,6572);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(6571, 7786, 0),(6572, 7787, 0);
