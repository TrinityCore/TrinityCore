-- Zorbin Fandazzle --> Add gossip conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=11361;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,11361,7116,0,0,8,0,7003,0,0,0,0,0,"","Show gossip text 5444 if quest 'Zapped Giants' is rewarded"),
(14,11361,7116,0,0,8,0,7721,0,0,0,0,0,"","Show gossip text 5444 if quest 'Fuel for the Zapping' is rewarded"),
(15,11361,0,0,0,8,0,7003,0,0,0,0,0,"","Show gossip option if quest 'Zapped Giants' is rewarded"),
(15,11361,0,0,0,8,0,7721,0,0,0,0,0,"","Show gossip option if quest 'Fuel for the Zapping' is rewarded");

DELETE FROM `gossip_menu_option` WHERE `MenuID`=11361;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(11361,0,1,"Got anything interesting for sale, Zorbin?",9817,3,128,0,0,0,0,"",0,0);
