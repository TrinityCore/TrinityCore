-- 
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 2530;

DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 2530;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2530, 0, 0, 1, 8, 0, 100, 0, 3607, 0, 0, 0, 17, 64, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Yenniku - On Spellhit \'Yenniku\'s Release\' - Set Emote State Stun'),
(2530, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 2, 83, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Yenniku - On Spellhit \'Yenniku\'s Release\' - Set Faction Horde'),
(2530, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 67, 0, 60000, 60000, 0, 0, 100, 0, 0, 0, 0, 0, 0, 0, 0, 'Yenniku - On Spellhit \'Yenniku\'s Release\' - Create Timed Event'),
(2530, 0, 3, 4, 59, 0, 100, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Yenniku - On Timed Event 0 Triggered - Evade'),
(2530, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 2, 28, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Yenniku - On Timed Event 0 Triggered - Set Faction Bloodscalp Trolls'),
(2530, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 17, 30, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Yenniku - On Timed Event 0 Triggered - Set Emote State Default');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup` IN (1,7) AND `SourceEntry`=2530 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 2530, 0, 0, 9, 0, 592, 0, 0, 0, 0, 0, '', 'Yenniku SAI event 0 will execute if quest Saving Yenniku has been taken.');
