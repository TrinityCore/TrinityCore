-- 
DELETE FROM `gossip_menu_option` WHERE `MenuID`=3142 AND `OptionID`=0;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(3142,0,0,"I lost the Flute of the Ancients and require a replacement, Eridan.",25677,1,1,0,0,0,0,"",0,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=3142 AND `SourceEntry`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 3142, 0, 0, 0, 8, 0, 4442, 0, 0, 0, 0, 0, '', 'Requires 4442 quest rewarded'),
(15, 3142, 0, 0, 0, 2, 0, 11445, 1, 0, 1, 0, 0, '', 'Must not having item 11445'),
(15, 3142, 0, 0, 0, 8, 0, 4261, 0, 0, 1, 0, 0, '', 'Requires quest 4261 to not rewarded');

DELETE FROM `smart_scripts` WHERE `entryorguid`=9116 AND `source_type`=0 AND `id` IN(1,2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(9116, 0, 1, 2, 62, 0, 100, 0, 3142, 0, 0, 0, 11, 47043, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Eridan - On Gossip Select - Add item"),
(9116, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Eridan - On Gossip Select - Close Gossip");
