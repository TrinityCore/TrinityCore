-- 
-- Niby the Almighty --> Add gossip chatter
DELETE FROM `gossip_menu` WHERE `MenuID` IN (5841,5842,5843,5844);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(5844,7002,0),
(5843,7003,0),
(5842,7004,0),
(5841,7005,0);

DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (5845,5844,5843,5842);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(5845,0,0,"I am in search of a great and powerful Warlock.",9625,1,1,5844,0,0,0,"",0,0),
(5844,0,0,"What task?",9627,1,1,5843,0,0,0,"",0,0),
(5843,0,0,"This is all very interesting but what is it that you want?",9629,1,1,5842,0,0,0,"",0,0),
(5842,0,0,"How do I do that?",9631,1,1,5841,0,0,0,"",0,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=5845;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,5845,0,0,0,15,0,256,0,0,0,0,0,"","Show gossip option if player is a Warlock");
