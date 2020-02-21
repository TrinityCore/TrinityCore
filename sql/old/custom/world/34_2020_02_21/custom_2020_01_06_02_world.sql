DELETE FROM `gossip_menu_option` WHERE `MenuID`= 12691;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `VerifiedBuild`) VALUES
(12691, 2, 0, 'Press the button labeled \'Ship Parts.\'', 50718, 1, 29981),
(12691, 1, 0, 'Press the button labeled \'Metal and Scraps.\'', 50717, 1, 29981),
(12691, 0, 0, 'Press the button labeled \'Wood and Lumber.\'', 50716, 1, 29981);

-- Gameobject Goblin Teleporter 208002 SAI
SET @ENTRY := 208002;
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 1, 0, 0, 62, 0, 100, 0, 12691, 0, 0, 0, 11, 95770, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On gossip action 0 from menu 12691 selected - Self: Cast spell Teleport to Mast Room (95770) on Action invoker // "),
(@ENTRY, 1, 1, 0, 62, 0, 100, 0, 12691, 1, 0, 0, 11, 95771, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On gossip action 1 from menu 12691 selected - Self: Cast spell Teleport to Foundry (95771) on Action invoker // "),
(@ENTRY, 1, 2, 0, 62, 0, 100, 0, 12691, 2, 0, 0, 11, 95772, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On gossip action 2 from menu 12691 selected - Self: Cast spell Teleport to Ship (95772) on Action invoker // ");

DELETE FROM `spell_target_position` WHERE `ID`= 95772;
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`) VALUES
(95772, 0, 36, -129.708, -789.115, 18.0666, 5.846853);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 15 AND `SourceGroup`= 12691;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTarget`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`) VALUES
(15, 12691, 0, 1, 13, 1, 3, 2),
(15, 12691, 1, 1, 13, 2, 3, 2),
(15, 12691, 2, 1, 13, 3, 3, 2);
