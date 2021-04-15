-- [QUEST] War Is Hell
UPDATE `creature` SET `spawntimesecs`=60 WHERE `id` IN (24009,24010);

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (24009,24010);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (24009,24010) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
-- Alliance Corpse
(24009, 0, 0, 1, 8, 0, 100, 1, 42793, 0, 0, 0, 11, 43297, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Alliance Corpse - SMART_EVENT_SPELLHIT - SMART_ACTION_CAST'),
(24009, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 20000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Alliance Corpse - SMART_EVENT_LINK - SMART_ACTION_FORCE_DESPAWN'),
-- Forsaken Corpse
(24010, 0, 0, 1, 8, 0, 100, 1, 42793, 0, 0, 0, 11, 43297, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Forsaken Corpse - SMART_EVENT_SPELLHIT - SMART_ACTION_CAST'),
(24010, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 20000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Forsaken Corpse - SMART_EVENT_LINK - SMART_ACTION_FORCE_DESPAWN');

DELETE FROM `conditions` WHERE `SourceEntry`=42793 AND `SourceTypeOrReferenceId`=17;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 42793, 0, 0, 31, 1, 3, 24009, 0, 0, 0, 0, '', ''),
(17, 0, 42793, 0, 1, 31, 1, 3, 24010, 0, 0, 0, 0, '', '');
