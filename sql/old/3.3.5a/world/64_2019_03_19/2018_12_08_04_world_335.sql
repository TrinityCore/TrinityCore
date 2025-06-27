-- Gann Stonespire
UPDATE `creature_template` SET `gossip_menu_id`=445, `AIName`="SmartAI" WHERE `entry`=3341;

DELETE FROM `gossip_menu` WHERE `MenuID` IN (445,446,21218);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(445,942,0),
(446,943,0);

DELETE FROM `gossip_menu_option` WHERE `MenuID`=445;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(445,0,0,"Can you tell me where Brine is?",3013,1,1,446,0,0,0,"",0,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=445;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,445,0,0,0,15,0,64,0,0,0,0,0,"","Show gossip option if player is a Shaman");
