-- Template
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_kings_rest_animated_guardian' WHERE `entry` = 133935;

-- Template Addon
UPDATE `creature_template_addon` SET `auras` = '276032' where `entry` = 133943;

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` = 133935;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(133935, 0, 0, 'THE IMPURE MAY NOT PASS INTO THE HALLS OF THE DEAD.', 12, 0, 100, 0, 0, 0, 153130, 0, 'Animated Guardian to Player'),
(133935, 0, 1, 'NONE SHALL ENTER.', 12, 0, 100, 0, 0, 0, 153128, 0, 'Animated Guardian to Player');

-- SpellScripts
DELETE FROM `spell_script_names` WHERE `spell_id` IN (270002, 269935, 276031);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(270002, 'spell_kings_rest_suppression_slam'),
(269935, 'spell_kings_rest_bound_by_shadow'),
(276031, 'spell_kings_rest_pit_of_despair');

-- Minion of Zul smart ai
SET @ENTRY := 133943;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, '', 63, 0, 100, 0, 0, 0, 0, 0, 85, 269935, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On just created - Self: Cast spell 269935 on self'),
(@ENTRY, 0, 1, 0, '', 4, 0, 100, 0, 0, 0, 0, 0, 85, 269936, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On aggro - Self: Cast spell 269936 on self');
