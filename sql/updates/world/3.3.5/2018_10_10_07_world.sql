-- 
DELETE FROM `gossip_menu` WHERE `MenuID` IN (21248);
UPDATE `creature_template` SET `gossip_menu_id`=9190 WHERE `entry`=25841;

DELETE FROM `gossip_menu_option` WHERE `MenuId` IN (21248,9190);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`) VALUES
(9190, 0, 0, "Search the body for the pilot's emergency toolkit.", 25112, 1, 1, 0, 0),
(9190, 1, 0, "Search the body for the pilot's insignia.", 25042, 1, 1, 0, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (21248,9190);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,9190,0,0,9,11887,0,0,0,'',"Only show gossip if player is on quest"),
(15,9190,1,0,9,11795,0,0,0,'',"Only show gossip if player is on quest");

UPDATE `smart_scripts` SET `event_param1`=9190 WHERE `entryorguid`=25841 AND `source_type`=0 AND `id` IN (1,4);

UPDATE `gossip_menu_option` SET `OptionText`='Take their clothing.', `OptionBroadcastTextId`=24733, `VerifiedBuild`=26365 WHERE (`MenuId`=9155 AND `OptionID`=0);
UPDATE `gossip_menu_option` SET `OptionText`='Take their clothing.', `OptionBroadcastTextId`=24733, `VerifiedBuild`=26365 WHERE (`MenuId`=9156 AND `OptionID`=0);
