--
UPDATE `creature_template` SET `npcflag`=129 WHERE `entry` IN (5049,  5188, 5189, 5190, 5191,16610, 16766, 28776, 52278);
UPDATE `gossip_menu_option` SET `OptionType`=1, `OptionNpcFlag`=1, `OptionBroadcastTextID`=33438 WHERE  `MenuID` IN (9832) AND `OptionID` IN (12);
UPDATE `gossip_menu_option` SET `OptionType`=1, `OptionNpcFlag`=1, `OptionBroadcastTextID`=33439 WHERE  `MenuID` IN (9832) AND `OptionID` IN (13);
UPDATE `gossip_menu_option` SET `OptionType`=3, `OptionNpcFlag`=128, `OptionBroadcastTextID`=8097 WHERE  `MenuID` IN (9832) AND `OptionID` IN (0);
UPDATE `gossip_menu_option` SET `OptionType`=3, `OptionNpcFlag`=128 WHERE  `MenuID` IN (10392) AND `OptionID` IN (0);
UPDATE `gossip_menu_option` SET `OptionType`=11, `OptionNpcFlag`=524288, `OptionBroadcastTextID`= 3415 WHERE  `MenuID` IN (10392) AND `OptionID` IN (1);
