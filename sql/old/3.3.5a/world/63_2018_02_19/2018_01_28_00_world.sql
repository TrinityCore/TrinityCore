
DELETE FROM `smart_scripts` WHERE `entryorguid`=22127 AND `source_type`=0 AND `id` IN(3,4);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(22127, 0, 3, 4, 62, 0, 100, 0, 8523, 1, 0, 0, 11, 39203, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Wildlord Antelarion - On Gossip Option 1 Selected - Cast \'Create Druid Signal\''),
(22127, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Wildlord Antelarion - On Gossip Option 0 Selected - Close Gossip');

DELETE FROM `gossip_menu_option` WHERE `MenuID`=8523 AND `OptionID`=1;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES 
(8523, 1, 0, 'Wildlord, I seem to have lost my druid signal.', 20299, 1, 1, 0, 0, 0, 0, '', 0, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=8523 AND `SourceEntry`=1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 8523, 1, 0, 0, 2, 0, 31763, 1, 0, 1, 0, 0, '', 'Show gossip only if player doesnt have Druid Signal'),
(15, 8523, 1, 0, 0, 9, 0, 10910, 0, 0, 0, 0, 0, '', 'Show gossip if Deaths Door quest taken'),
(15, 8523, 1, 0, 1, 2, 0, 31763, 1, 0, 1, 0, 0, '', 'Show gossip only if player doesnt have Druid Signal'),
(15, 8523, 1, 0, 1, 8, 0, 10910, 0, 0, 0, 0, 0, '', 'Show gossip if deaths door quest rewarded'),
(15, 8523, 1, 0, 1, 8, 0, 10912, 0, 0, 1, 0, 0, '', 'Hide gossip when The Houndmaster quest rewarded');
