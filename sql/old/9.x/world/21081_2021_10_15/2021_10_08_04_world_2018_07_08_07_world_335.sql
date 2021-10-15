-- Malyfous's Catalogue
DELETE FROM `gossip_menu` WHERE `MenuID` IN (2986,2987,2988,2989,2990);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(2986,3695,0),
(2987,3696,0),
(2988,3697,0),
(2989,3699,0),
(2990,3698,0);

DELETE FROM `gossip_menu_option` WHERE `MenuID`=2985;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES
(2985,0,0,"Chapter on Frayed Abomination Stitchings.",6145,1,1,0),
(2985,1,0,"Chapter on Enchanted Scarlet Thread.",6146,1,1,0),
(2985,2,0,"Chapter on Frostwhisper's Embalming Fluid.",6147,1,1,0),
(2985,3,0,"Chapter on Arcane Crystals and Arcanite.",6151,1,1,0),
(2985,4,0,"Chapter on Skin of Shadow.",6161,1,1,0);

DELETE FROM `gossip_menu_option_action` WHERE `MenuID`=2985;
INSERT INTO `gossip_menu_option_action` (`MenuID`, `OptionIndex`, `ActionMenuID`, `ActionPoiID`) VALUES
(2985,0,2986,0),
(2985,1,2987,0),
(2985,2,2988,0),
(2985,3,2989,0),
(2985,4,2990,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=2985;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,2985,0,0,0,8,0,5047,0,0,0,0,0,"","Show gossip option if quest 'Finkle Einhorn, At Your Service!' is rewarded"),
(15,2985,1,0,0,8,0,5047,0,0,0,0,0,"","Show gossip option if quest 'Finkle Einhorn, At Your Service!' is rewarded"),
(15,2985,2,0,0,8,0,5047,0,0,0,0,0,"","Show gossip option if quest 'Finkle Einhorn, At Your Service!' is rewarded"),
(15,2985,3,0,0,8,0,5047,0,0,0,0,0,"","Show gossip option if quest 'Finkle Einhorn, At Your Service!' is rewarded"),
(15,2985,4,0,0,8,0,5047,0,0,0,0,0,"","Show gossip option if quest 'Finkle Einhorn, At Your Service!' is rewarded");

DELETE FROM `npc_text` WHERE `ID` IN (3695,3696,3697,3698,3699);
INSERT INTO `npc_text` (`ID`, `BroadcastTextID0`, `Probability0`) VALUES
(3695,6163,1),
(3696,6164,1),
(3697,6165,1),
(3698,6166,1),
(3699,6167,1);
