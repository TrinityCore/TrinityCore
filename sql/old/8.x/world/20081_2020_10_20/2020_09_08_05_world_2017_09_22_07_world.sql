DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=9253;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 9253, 12566, 0, 0, 8, 0, 11936, 0, 0, 1, 0, 0, "", "Gossip text 12566 requires quest 'Hatching a Plan' NOT rewarded"),
(14, 9253, 12591, 0, 0, 8, 0, 11936, 0, 0, 0, 0, 0, "", "Gossip text 12591 requires quest 'Hatching a Plan' rewarded"),
(14, 9253, 12591, 0, 0, 8, 0, 11931, 0, 0, 1, 0, 0, "", "Gossip text 12591 requires quest 'Cracking the Code' NOT rewarded"),
(14, 9253, 12592, 0, 0, 8, 0, 11931, 0, 0, 0, 0, 0, "", "Gossip text 12592 requires quest 'Cracking the Code' rewarded");

UPDATE `conditions` SET `SourceEntry`=1 WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9253 AND `SourceEntry`=0;

DELETE FROM `gossip_menu_option` WHERE `MenuID`=9253;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES
(9253, 0, 0, "What is the cause of this conflict?", 25371, 1, 1, 0),
(9253, 1, 0, "I seem to have lost the Augmented Arcane Prison. Did I leave it here with you?", 25369, 1, 1, 0);

DELETE FROM `gossip_menu_option_action` WHERE `MenuID`=9253 AND `OptionIndex`=0;
INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuID`, `ActionPoiID`) VALUES
(9253, 0, 9283, 0);
