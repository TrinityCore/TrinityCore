-- Witch Doctor Mau'ari
UPDATE `gossip_menu_option` SET `ActionMenuID`=2705 WHERE `MenuID`=2703 AND `OptionID`=2;

DELETE FROM `gossip_menu_option` WHERE `MenuID`=21321;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(21321,0,0,"What is Juju?",5756,1,1,2704,0,0,0,'',0,0);

DELETE FROM `gossip_menu` WHERE `MenuID` IN (2704, 2705);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(2704,3424,0),
(2705,3425,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=2703 AND `SourceEntry` IN (0,1);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,2703,0,0,0,8,0,975,0,0,0,0,0,'',"Witch Doctor Mau\'ri - Show gossip option 0 if quest 975 is rewarded"),
(15,2703,1,0,0,8,0,975,0,0,0,0,0,'',"Witch Doctor Mau\'ri - Show gossip option 1 if quest 975 is rewarded");

DELETE FROM `smart_scripts` WHERE `entryorguid`=10307 AND `source_type`=0 AND `id`=2;
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid`=10307 AND `source_type`=0 AND `id`=1;
