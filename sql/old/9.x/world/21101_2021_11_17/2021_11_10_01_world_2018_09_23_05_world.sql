-- 
DELETE FROM `gossip_menu` WHERE `MenuId`=9014 AND `TextId`=12180;
INSERT INTO `gossip_menu` (`MenuId`, `TextId`) VALUES (9014,12180);
-- UPDATE `gossip_menu_option` SET `ActionMenuID`=9014 WHERE `MenuID`=9015;

DELETE FROM `gossip_menu_option` WHERE `MenuID`=9014;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES
(9014, 0, 0, "Here's a gold, buy yourself something nice.", 23829, 1, 1, 0);

DELETE FROM `gossip_menu_option_box` WHERE `MenuID`=9014;
INSERT INTO `gossip_menu_option_box` (`MenuID`, `OptionIndex`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextId`) VALUES
(9014, 0, 0, 10000, "Do you really want to bribe Olga?", 25743);

UPDATE `smart_scripts` SET `event_param1`=9014 WHERE `entryorguid`=24639 AND `source_type`=0 AND `id`=0;
