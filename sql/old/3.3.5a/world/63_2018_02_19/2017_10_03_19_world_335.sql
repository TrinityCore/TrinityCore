--
DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (3183, 3184);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(3183, 0, 0, "How are we doing in the battle to subvert the cauldrons?", 6552, 1, 1, 3241, 0, 0, 0, "", 0, 0),
(3184, 0, 0, "How are we doing in the battle to subvert the cauldrons?", 6552, 1, 1, 3241, 0, 0, 0, "", 0, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (3183, 3184);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 3183, 0, 0, 0, 8, 0, 5230, 0, 0, 0, 0, 0, "", "Gossip option requires quest 'Return to the Bulwark' rewarded"),
(15, 3184, 0, 0, 0, 8, 0, 5217, 0, 0, 0, 0, 0, "", "Gossip option requires quest 'Return to Chillwind Camp' rewarded");
