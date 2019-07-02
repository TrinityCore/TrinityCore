--
-- Eva Sarkhoff
DELETE FROM `gossip_menu` WHERE `MenuID` IN (3301,3302,3303);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(3303,4048,0),
(3302,4049,0),
(3301,4050,0);

UPDATE `gossip_menu_option` SET `OptionText`="How can I help?", `OptionBroadcastTextID`=6664 WHERE `MenuID`=3301 AND `OptionID`=0;
