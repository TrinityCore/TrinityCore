/*
-- Torwa Pathfinder --> Add gossip option and conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=2188;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,2188,2821,0,0,8,0,4290,0,0,0,0,0,"","Show gossip text 2821 if quest 'The Fare of Lar'korwi' is rewarded"),
(15,2188,0,0,0,8,0,4290,0,0,0,0,0,"","Show gossip option if quest 'The Fare of Lar'korwi' is rewarded");

DELETE FROM `gossip_menu_option` WHERE `MenuID`=2188;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(2188,0,0,"Who is this Lar'korwi you spoke of?",5187,1,1,2201,0,0,0,"",0,0);
*/
