DELETE FROM `gossip_menu_option` WHERE `MenuID`=10140;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`) VALUES
(10140, 0, 0, "I have lost my Schools of Arcane Magic - Mastery volume.  Can you provide me with a replacement?", 32525, 1, 1, 0, 0, 0, 0, "");

UPDATE `creature` SET `spawntimesecs`=30 WHERE `id`=16128;
UPDATE `creature_template` SET `AIName`= '' WHERE `entry`=30116;
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid`=16128 AND `source_type`=0 AND `id` IN (4,0,1);
DELETE FROM `smart_scripts` WHERE `entryorguid`=16128 AND `source_type`=0 AND `id` IN (5,6);
DELETE FROM `smart_scripts` WHERE `entryorguid`=30116 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3011600 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(16128, 0, 5, 6, 62, 0, 100, 0, 10140, 0, 0, 0, 85, 59983, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Rhonin - On Gossip Select - Cast The Schools of Arcane Magic - Mastery"),
(16128, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Rhonin - On Gossip Select - Close Gossip");

DELETE FROM conditions WHERE SourceTypeOrReferenceId=15 AND SourceGroup=10140;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 10140, 0, 0, 0, 17, 0, 1956, 0, 0, 0, 0, 0, '', 'Gossip requires Higher Learning achievement'),
(15, 10140, 0, 0, 0, 2, 0, 43824, 1, 1, 1, 0, 0, '', 'Gossip requires Requires not having the item The Schools of Arcane Magic - Mastery');
