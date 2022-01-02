--
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=3426 WHERE `OptionBroadcastTextID`=7066 AND `OptionText`="Bank";
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=4888 WHERE `OptionBroadcastTextID`=7066 AND `OptionText`="The bank";

UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=2868 WHERE `OptionBroadcastTextID`=2870 AND `OptionText`="Class Trainer";
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=5513 WHERE `OptionBroadcastTextID`=2870 AND `OptionText`="Inn";

UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=4893 WHERE `OptionBroadcastTextID`=7075 AND `OptionText`="The inn";
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=5513 WHERE `OptionBroadcastTextID`=7075 AND `OptionText`="Inn";

UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=4895 WHERE `OptionBroadcastTextID` IN (45381, 5514);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=2869 WHERE `OptionBroadcastTextID`=4895 AND `OptionText`="Profession Trainer";

UPDATE `gossip_menu_option` SET `OptionText`="Zeppelin Master" WHERE `OptionBroadcastTextID`=5518;

UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=15232 WHERE `MenuId`=7777 AND `OptionIndex`=7;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=5518 WHERE `MenuId`=10769 AND `OptionIndex`=10;

UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=2870 WHERE `MenuId`=10769 AND `OptionIndex`=4;
