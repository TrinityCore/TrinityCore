-- 
UPDATE `creature_template_addon` SET `mount`=0 WHERE `entry`=24497; 
UPDATE `gossip_menu_option` SET `OptionText`="Do you still need some help shipping kegs from Kharanos?", `OptionBroadcastTextID`=23245, `ActionMenuID`= 8953 WHERE `MenuID`=8934 AND `OptionID`=4;
UPDATE `smart_scripts` SET `event_param1`=8953, `event_param2`=0 WHERE `entryorguid` IN (23558) AND `source_type`=0 AND `id`=6; 
UPDATE `smart_scripts` SET `event_param1`=8973, `event_param2`=0 WHERE `entryorguid` IN (24497) AND `source_type`=0 AND `id`=8; 

UPDATE `gossip_menu_option` SET `OptionText`="Do you still need some help moving kegs from the crash site near Razor Hill?", `OptionBroadcastTextID`=23546, `ActionMenuID`=8973 WHERE `MenuID`=8976 AND `OptionID`=4;
DELETE FROM `gossip_menu` WHERE `MenuID`=8973 AND `TextID`=12113;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`) VALUES
(8973, 12113);

DELETE FROM `gossip_menu_option` WHERE `MenuId`=8973 AND `OptionID`=0;
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionID`, `OptionIcon`, `OptionText`, `OptionType`, `OptionNpcFlag`, `OptionBroadcastTextId`) VALUES
(8973, 0, 0, "I'm ready to work for you today!  Give me that ram!", 1, 1, 23545);
