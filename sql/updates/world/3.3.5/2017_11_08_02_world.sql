-- Ragged John
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 9563;

-- Create new gossip menu
DELETE FROM `gossip_menu` WHERE MenuID = 2062;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(2062, 3496, 0);

DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (2061, 2062) AND `OptionID` = 0;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(2061, 0, 0, 'Milk me, John.', 5833, 1, 1, 2062, 0, 0, 0, '', 0, 0),
(2062, 0, 0, 'Do it... Do it now.', 5835, 1, 1, 0, 0, 0, 0, '', 0, 0);

-- Smart scripts
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 9563;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(9563, 0, 0, 1, 62, 0, 100, 0, 2062, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ragged John - On Gossip Option 0 Selected - Close Gossip'),
(9563, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 11, 16472, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ragged John - On Gossip Option 0 Selected - Cast \'Wicked Milking\''),
(9563, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 15, 4866, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ragged John - On Gossip Option 0 Selected - Quest Credit \'Mother\'s Milk\'');

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 2061 AND `SourceEntry` = 0 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 2061, 0, 0, 0, 1, 0, 16468, 0, 0, 0, 0, 0, '', 'Show gossip menu 2061 option id 0 if target has aura Mother\'s Milk (effect 0).'),
(15, 2061, 0, 0, 0, 9, 0, 4866, 0, 0, 0, 0, 0, '', 'Show gossip menu 2061 option id 0 if quest Mother\'s Milk has been taken.');
