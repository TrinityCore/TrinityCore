-- https://youtu.be/1u2-TiUISDY?t=35
UPDATE `creature_template` SET `ScriptName` = "" WHERE `entry` = 12919;

DELETE FROM `gossip_menu` WHERE `MenuID` = 6445 AND `TextID` IN (7639,7640);
DELETE FROM `gossip_menu` WHERE `MenuID` IN (57023,57024);
INSERT INTO `gossip_menu` (`MenuID`,`TextID`) VALUES
(6445,7639),
(57023,7640),
(57024,7645);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 14 AND `SourceGroup` = 6445;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,6445,7638,0,0,8,0,8227,0,0,1,0,0,"","Group 0: Show gossip text 7638 if quest 'Nat's Measuring Tape' is not rewarded"),
(14,6445,7639,0,0,8,0,8227,0,0,0,0,0,"","Group 0: Show gossip text 7639 if quest 'Nat's Measuring Tape' is rewarded");

DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (6445,57023);
INSERT INTO `gossip_menu_option` (`MenuID`,`OptionID`,`OptionIcon`,`OptionText`,`OptionBroadcastTextID`,`OptionType`,`OptionNpcFlag`,`ActionMenuID`,`ActionPoiID`,`BoxCoded`,`BoxMoney`,`BoxText`,`BoxBroadcastTextID`,`VerifiedBuild`) VALUES
(6445,0,0,"I want to catch Gahz'ranka!  Tell me how!",10490,1,1,57023,0,0,0,"",0,0),
(57023,0,1,"Nat, I want to buy your mudskunk lures!",10492,3,128,0,0,0,0,"",0,0),
(57023,1,0,"How do I catch the mudskunks for your lure?",10500,1,1,57024,0,0,0,"",0,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 6445;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,6445,0,0,0,8,0,8227,0,0,0,0,0,"","Group 0: Show Gossip Option 0 if quest 'Nat's Measuring Tape' is rewarded");
