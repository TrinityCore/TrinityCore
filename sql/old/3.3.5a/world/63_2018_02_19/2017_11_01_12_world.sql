-- Coosh'coosh
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 18586;

UPDATE `creature` SET `MovementType` = 1, `spawndist` = 8 WHERE `id` = 18586;

DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 18586;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(18586, 0, 0, 0, 0, 0, 100, 0, 2000, 2000, 3000, 3000, 11, 9532, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Coosh\'coosh - In Combat - Cast \'Lightning Bolt\''),
(18586, 0, 1, 2, 62, 0, 100, 0, 7730, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Coosh\'coosh - On Gossip Option 0 Selected - Close Gossip'),
(18586, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 2, 45, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Coosh\'coosh - On Gossip Option 0 Selected - Set Faction Ogre'),
(18586, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Coosh\'coosh - On Gossip Option 0 Selected - Say Line 0'),
(18586, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Coosh\'coosh - On Gossip Option 0 Selected - Start Attacking'),
(18586, 0, 5, 0, 25, 0, 100, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Coosh\'coosh - On Reset - Set Default Faction'),
(18586, 0, 6, 0, 23, 0, 100, 0, 12550, 0, 2000, 2000, 11, 12550, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Coosh\'coosh - On Missing Buff - Cast Lightning Shield');

DELETE FROM `gossip_menu_option` WHERE `MenuID` = 7730;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(7730, 0, 0, 'I have been sent by Sal\'salabim to collect a debt that you owe. Pay up or I\'m going to have to hurt you.', 15560, 1, 1, 0, 0, 0, 0, '', 0, 0);

DELETE FROM `creature_text` WHERE `CreatureID` = 18586;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextID`, `TextRange`, `comment`) VALUES
(18586, 0, 0, 'F\'woooroonn! Coosh\'coosh pay nothing! Die!', 12, 0, 100, 0, 0, 0, 15565, 0, 'Coosh\'coosh');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 7730;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 7730, 0, 0, 0, 9, 0, 10009, 0, 0, 0, 0, 0, '', 'Show gossip menu 7730 option id 0 if quest Crackin\' Some Skulls has been taken.');
