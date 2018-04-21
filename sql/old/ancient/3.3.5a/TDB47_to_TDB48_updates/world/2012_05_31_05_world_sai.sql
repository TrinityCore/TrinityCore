-- Ai and Script Update/Addition for Taragaman the Hungerer
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=11520;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11520;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=11520;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11520, 0, 0, 0, 0, 0, 85, 2, 5000, 5000, 15000, 20000, 11, 18072, 1, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Taragaman the Hungerer  - Cast Uppercut'),
(11520, 0, 1, 0, 0, 0, 75, 2, 8000, 8000, 20000, 25000, 11, 11970, 1, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 'Taragaman the Hungerer - Cast Fire Nova');

-- Ai and Script Update/Addition for Jergosh the Invoker
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=11518;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11518;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=11518;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11518, 0, 1, 0, 0, 0, 75, 2, 12000, 12000, 30000, 30000, 11, 20800, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Jergosh the Invoker - Cast Immolat'),
(11518, 0, 0, 0, 0, 0, 85, 2, 30000, 30000, 120000, 120000, 11, 11980, 1, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Jergosh the Invoker - Cast Curse of Weakness');

-- Ai and Script Update/Addition for Bazzalan
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=11519;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11519;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=11519;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11519, 0, 1, 0, 0, 0, 75, 2, 3000, 5000, 12000, 15000, 11, 2818, 1, 32, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Bazzalan - Cast Poison'),
(11519, 0, 0, 0, 0, 0, 85, 2, 8000, 8000, 16000, 17000, 11, 14873, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Bazzalan - Cast Sinister Strike');

-- Ai and Script Update/Addition for Oggleflint
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=11517;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11517;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=11517;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11517, 0, 0, 0, 0, 0, 70, 2, 8000, 8000, 15000, 15000, 11, 40505, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Oggleflint - Cast Cleave');
