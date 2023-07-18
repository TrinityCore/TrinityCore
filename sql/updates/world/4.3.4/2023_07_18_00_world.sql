DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_gen_dalaran_shop_keeper_greeting_periodic',
'spell_gen_dalaran_shop_keeper_greeting_aoe',
'spell_gen_dalaran_shop_keeper_greeting_ping');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(60913, 'spell_gen_dalaran_shop_keeper_greeting_periodic'),
(60912, 'spell_gen_dalaran_shop_keeper_greeting_aoe'),
(60909, 'spell_gen_dalaran_shop_keeper_greeting_ping');

DELETE FROM `creature_text` WHERE `CreatureID` IN (1286, 1299, 1297, 1295);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
-- Edna Mullby
(1286, 0, 0, 'Welcome. May I help you find something?', 12, 7, 100, 3, 0, 0, 32811, 0, ''),
(1286, 0, 1, 'Greetings.', 12, 7, 100, 3, 0, 0, 32935, 0, ''),
(1286, 0, 2, 'Greetings, $c.', 12, 7, 100, 3, 0, 0, 32808, 0, ''),
(1286, 0, 3, 'Welcome.', 12, 7, 100, 3, 0, 0, 32936, 0, ''),
(1286, 0, 4, 'Welcome!', 12, 7, 100, 3, 0, 0, 32807, 0, ''),
(1286, 0, 5, 'Let me know if you need help finding anything, $c.', 12, 7, 100, 3, 0, 0, 32810, 0, ''),
-- Lina Stover
(1297, 0, 0, 'Welcome. May I help you find something?', 12, 7, 100, 3, 0, 0, 32811, 0, ''),
(1297, 0, 1, 'Greetings.', 12, 7, 100, 3, 0, 0, 32935, 0, ''),
(1297, 0, 2, 'Greetings, $c.', 12, 7, 100, 3, 0, 0, 32808, 0, ''),
(1297, 0, 3, 'Welcome.', 12, 7, 100, 3, 0, 0, 32936, 0, ''),
(1297, 0, 4, 'Welcome!', 12, 7, 100, 3, 0, 0, 32807, 0, ''),
(1297, 0, 5, 'Let me know if you need help finding anything, $c.', 12, 7, 100, 3, 0, 0, 32810, 0, ''),
-- Lara Moore
(1295, 0, 0, 'Welcome. May I help you find something?', 12, 7, 100, 3, 0, 0, 32811, 0, ''),
(1295, 0, 1, 'Greetings.', 12, 7, 100, 3, 0, 0, 32935, 0, ''),
(1295, 0, 2, 'Greetings, $c.', 12, 7, 100, 3, 0, 0, 32808, 0, ''),
(1295, 0, 3, 'Welcome.', 12, 7, 100, 3, 0, 0, 32936, 0, ''),
(1295, 0, 4, 'Welcome!', 12, 7, 100, 3, 0, 0, 32807, 0, ''),
(1295, 0, 5, 'Let me know if you need help finding anything, $c.', 12, 7, 100, 3, 0, 0, 32810, 0, '');

 -- Edna Mullby smart ai
SET @ENTRY := 1286;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 1, 8, 0, 100, 0, 60909, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On spell  Dalaran - Shop Keeper Greeting (60909) hit - Self: Talk Welcome. May I help you find something? (0) to invoker'),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On spell  Dalaran - Shop Keeper Greeting (60909) hit - Self: Look at Caster'),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 67, 1, 5000, 5000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'On spell  Dalaran - Shop Keeper Greeting (60909) hit - Trigger timed event timedEvent[1] in 5000 - 5000 ms // -meta_wait'),
(@ENTRY, 0, 3, 0, 59, 0, 100, 0, 1, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On timed event timedEvent[1] triggered - Self: Set orientation to home position orientation');

 -- Lina Stover smart ai
SET @ENTRY := 1297;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 1, 8, 0, 100, 0, 60909, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On spell  Dalaran - Shop Keeper Greeting (60909) hit - Self: Talk Welcome. May I help you find something? (0) to invoker'),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On spell  Dalaran - Shop Keeper Greeting (60909) hit - Self: Look at Caster'),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 67, 1, 5000, 5000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'On spell  Dalaran - Shop Keeper Greeting (60909) hit - Trigger timed event timedEvent[1] in 5000 - 5000 ms // -meta_wait'),
(@ENTRY, 0, 3, 0, 59, 0, 100, 0, 1, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On timed event timedEvent[1] triggered - Self: Set orientation to home position orientation');
 
 -- Lara Moore smart ai
SET @ENTRY := 1295;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 1, 8, 0, 100, 0, 60909, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On spell  Dalaran - Shop Keeper Greeting (60909) hit - Self: Talk Welcome. May I help you find something? (0) to invoker'),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On spell  Dalaran - Shop Keeper Greeting (60909) hit - Self: Look at Caster'),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 67, 1, 5000, 5000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'On spell  Dalaran - Shop Keeper Greeting (60909) hit - Trigger timed event timedEvent[1] in 5000 - 5000 ms // -meta_wait'),
(@ENTRY, 0, 3, 0, 59, 0, 100, 0, 1, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On timed event timedEvent[1] triggered - Self: Set orientation to home position orientation');


UPDATE `creature_template_addon` SET `auras`= '60913' WHERE `entry` IN (1286, 1299, 1297, 1295);
