-- 
UPDATE `gossip_menu_option` SET `OptionBroadcastTextID`=23837 WHERE `MenuID`=9025 AND `OptionID`=4; 
UPDATE `gossip_menu_option` SET `OptionText`="Justice Quartermasters", `OptionBroadcastTextID`=32704 WHERE `MenuID`=10173 AND `OptionID`=2; 
DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (21249);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (15) AND `SourceGroup` IN (21249);
UPDATE `gossip_menu_option` SET `OptionText`="I have lost my talisman and require a new one, Jin'rokh.", `OptionBroadcastTextID`=10380 WHERE `MenuID` IN (21263,21264) AND `OptionID` IN (3,4,5,6); 
UPDATE `gossip_menu_option` SET `OptionText`="I have lost the talisman and require a new one, Al'tabim.", `OptionBroadcastTextID`=10384 WHERE `MenuID` IN (21265,21266,21267) AND `OptionID` IN (3,4,5,6); 
UPDATE `gossip_menu_option` SET `OptionText`="Maywiki, I've lost my talisman and require a replacement.", `OptionBroadcastTextID`=10427 WHERE `MenuID` IN (21268,21269) AND `OptionID` IN (3,4,5,6); 
UPDATE `gossip_menu_option` SET `OptionText`="I have lost the talisman, Falthir. I require a replacement.", `OptionBroadcastTextID`=10439 WHERE `MenuID` IN (21271,21270) AND `OptionID` IN (3,4,5,6); 
UPDATE `gossip_menu_option` SET `OptionText`="Search the corpse for an insignia.", `OptionBroadcastTextID`=14408, `ActionMenuID`=7485 WHERE `MenuID` IN (7486) AND `OptionID` IN (0); 
DELETE FROM `gossip_menu` WHERE `MenuID`=7485 AND `TextID`=9072;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`) VALUES
(7485, 9072);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(17832) AND `source_type`=0 AND `id`=1;
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid` IN(17832) AND `source_type`=0 AND `id`=0;
