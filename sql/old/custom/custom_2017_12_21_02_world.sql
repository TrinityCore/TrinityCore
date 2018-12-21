DELETE FROM `gossip_menu_option` WHERE `MenuID`= 12669;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`) VALUES
(12669, 0, "Can you take me to the Great Hall?", 50691, 1, 1),
(12669, 1, "Can you take me to the Chapel?", 50692, 1, 1),
(12669, 2, "Can you take me to the Laboratory?", 50694, 1, 1);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 15 AND `SourceGroup`= 12669;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTarget`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`) VALUES
(15, 12669, 0, 1, 13, 0, 3, 2),
(15, 12669, 1, 1, 13, 2, 3, 2),
(15, 12669, 2, 1, 13, 3, 3, 2);

-- Creature Haunted Stable Hand 51400 SAI
SET @ENTRY := 51400;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 62, 0, 100, 0, 12669, 0, 0, 0, 11, 95300, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On gossip action 0 from menu 12669 selected - Self: Cast spell 95300 on Action invoker // "),
(@ENTRY, 0, 1, 0, 62, 0, 100, 0, 12669, 1, 0, 0, 11, 95303, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On gossip action 1 from menu 12669 selected - Self: Cast spell 95303 on Action invoker // "),
(@ENTRY, 0, 2, 0, 62, 0, 100, 0, 12669, 2, 0, 0, 11, 95305, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On gossip action 2 from menu 12669 selected - Self: Cast spell 95305 on Action invoker // ");
