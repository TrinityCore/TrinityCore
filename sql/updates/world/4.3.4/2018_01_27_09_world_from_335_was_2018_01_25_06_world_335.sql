/*
-- Fallen Hero of the Horde --> Fix gossip texts
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=840;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,840,1451,0,1,9,0,2801,0,0,0,0,0,"","Show gossip text 1451 if player has quest 'A Tale of Sorrow' taken");

DELETE FROM `gossip_menu` WHERE `MenuID` IN (841, 842);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(841,1392,0),
(842,1411,0);

UPDATE `gossip_menu_option` SET `OptionText`="Why are you here?", `OptionBroadcastTextID`=3582, `ActionMenuID`=841 WHERE `MenuID`=840 AND `OptionID`=0;
DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (841, 842);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(841,0,0,"Continue with your story.",3601,1,1,842,0,0,0,"",0,0),
(842,0,0,"Tragic...",3830,1,1,0,0,0,0,"",0,0);

DELETE FROM `smart_scripts` WHERE `entryorguid`=7572 AND `source_type`=0 AND `id` IN (0,1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7572,0,0,2,62,0,100,512,842,0,0,0,26,2784,0,0,0,0,0,7,0,0,0,0,0,0,0,"Fallen Hero of the Horde - On Gossip Option 0 Selected - Quest Credit 'Fall From Grace'"),
(7572,0,1,2,62,0,100,512,881,0,0,0,26,2801,0,0,0,0,0,7,0,0,0,0,0,0,0,"Fallen Hero of the Horde - On Gossip Option 0 Selected - Quest Credit 'A Tale of Sorrow'");
*/
