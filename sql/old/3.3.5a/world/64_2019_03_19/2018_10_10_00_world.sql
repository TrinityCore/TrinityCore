-- 
DELETE FROM `gossip_menu_option` WHERE `MenuId` IN (9860,9855);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `ActionMenuId`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`) VALUES
(9860, 0, 0, "I have a few more questions, Gymer.",9852, 30634, 1, 1),
(9855, 0, 0, "I have a few more questions, Gymer.",9852, 30634, 1, 1);
