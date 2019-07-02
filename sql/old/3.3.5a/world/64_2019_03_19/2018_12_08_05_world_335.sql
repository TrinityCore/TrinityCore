-- Tog Rustsprocket
DELETE FROM `gossip_menu` WHERE `MenuID`=268 AND `TextID`=767;
DELETE FROM `gossip_menu` WHERE `MenuID`=269;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(268,767,0),
(269,768,0);

DELETE FROM `gossip_menu_option` WHERE `MenuID`=268;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(268,0,0,"What message?",2753,1,1,269,0,0,0,"",0,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=268;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,268,767,0,0,15,0,256,0,0,0,0,0,"","Show gossip text 767 if player is a Warlock"),
(14,268,767,0,0,27,0,10,3,0,0,0,0,"","Show gossip text 767 if player is level 10 or higher"),
(15,268,0,0,0,15,0,256,0,0,0,0,0,"","Show gossip option if player is a Warlock"),
(15,268,0,0,0,27,0,10,3,0,0,0,0,"","Show gossip option if player is level 10 or higher");
