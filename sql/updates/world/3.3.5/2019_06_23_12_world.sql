-- 
DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (10214, 10255);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(10214, 0, 1, "I want to browse your goods", 3370, 3, 128, 0, 0, 0, 0, "", 0, 0),
(10255, 0, 1, "I want to browse your goods", 3370, 3, 128, 0, 0, 0, 0, "", 0, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (10214, 10255);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 10214, 0, 0, 0, 8, 0, 12870, 0, 0, 0, 0, 0, "", "NPC Rork Sharpchin can sell items only if quest 'Ancient Relics' is rewarded"),
(15, 10255, 0, 0, 0, 8, 0, 12882, 0, 0, 0, 0, 0, "", "NPC Olut Alegut can sell items only if quest 'Ancient Relics' is rewarded");
