--
UPDATE `creature_template` SET `ScriptName` = '' WHERE `entry` = 31247;

DELETE FROM `gossip_menu_option` WHERE `MenuID` = 10210 AND `OptionID` = 1;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(10210,1,1,"I hear you sell motorcycle parts.",33010,3,128,0,0,0,0,'',0,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 10210;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,10210,1,0,0,25,0,60866,0,0,0,0,0,"","Group 0: Show Gossip Option 1 if spell 'Mechano-hog' is learned"),
(15,10210,1,0,1,25,0,60867,0,0,0,0,0,"","Group 1: Show Gossip Option 1 if spell 'Mekgineer's Chopper' is learned");
