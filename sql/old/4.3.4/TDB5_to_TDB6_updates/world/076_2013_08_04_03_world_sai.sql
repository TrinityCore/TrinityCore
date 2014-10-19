-- Random comment

UPDATE `creature_template` SET AIName='SmartAI' WHERE entry IN (26417*100,26417);
DELETE FROM `smart_scripts` WHERE source_type=0 AND entryorguid = 26417;
DELETE FROM `smart_scripts` WHERE (`entryorguid`= 26417*100 AND `source_type`=9);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(26417, 0, 0, 0, 8, 0, 25, 0, 47604, 0, 10000, 10000, 80, 2641700, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Runed Giant - Start Script for Free At Last'),
(2641700, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 2, 35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Runed Giant - Change Faction'),
(2641700, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Runed Giant - Stop Attack'),
(2641700, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 33, 26783, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Runed Giant - Quest Credit'),
(2641700, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Runed Giant - Say Lines'),
(2641700, 9, 4, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Runed Giant - Despawn'),
(2641700, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Runed Giant - Reset Faction');

DELETE FROM `creature_text` WHERE `entry` =26417;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES 
(26417, 0, 0, 'I thought I was doomed. Thank you for freeing me.', 12, 0, 100, 0, 0, 0, ''),
(26417, 0, 1, 'You have my gratitude.', 12, 0, 100, 0, 0, 0, ''),
(26417, 0, 2, 'I never thought I''d be free from that terrible spell!', 12, 0, 100, 0, 0, 0, ''),
(26417, 0, 3, 'Thank you, small one.', 12, 0, 100, 0, 0, 0, '');
