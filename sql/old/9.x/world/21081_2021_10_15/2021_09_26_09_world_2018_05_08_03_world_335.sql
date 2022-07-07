-- 
-- Ur'dan --> Add Gossip Text
UPDATE `creature_template` SET `gossip_menu_id`=5864 WHERE `entry`=14522;

DELETE FROM `gossip_menu` WHERE `MenuID`=5864;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(5864,7037,0);

DELETE FROM `gossip_menu_option` WHERE `MenuID`=5864;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES
(5864,0,1,"I wish to purchase from you.",9734,3,128,0);
