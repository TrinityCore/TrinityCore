-- 
UPDATE `creature_template` SET `gossip_menu_id`=522 WHERE `entry` IN (3402);
DELETE FROM `gossip_menu` WHERE `MenuID` IN (21216,21220,21219) AND `TextID` IN (907,1041,1039);
DELETE FROM `gossip_menu` WHERE `MenuID` IN (522) AND `TextID` IN (1039);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`) VALUES
(522,1039);
