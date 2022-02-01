-- Crimson Templar (Templar - Fire)
DELETE FROM `smart_scripts` WHERE `entryorguid`=15209 AND `source_type`=0 AND `id` IN (2,3,4,5,6,7,8,9,10,11,12,13);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(15209, 0, 2, 3, 54, 0, 100, 0, 0, 0, 0, 0, 0, 67, 1, 5000, 5000, 0, 0, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Crimson Templar - On Just Summoned - Create Timed Event 1'),
(15209, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 0, 67, 2, 30000, 30000, 0, 0, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Crimson Templar - On Just Summoned - Create Timed Event 2'),
(15209, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 0, 103, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Crimson Templar - On Just Summoned - Set Rooted On'),
(15209, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 144, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Crimson Templar - On Just Summoned - Set Immune to PC On'),
(15209, 0, 6, 7, 59, 0, 100, 0, 1, 0, 0, 0, 0, 144, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Crimson Templar - On Timed Event 1 Triggered - Set Immune to PC Off'),
(15209, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 0, 103, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Crimson Templar - On Timed Event 1 Triggered - Set Rooted Off'),
(15209, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 0, 123, 100, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 0, 'Crimson Templar - On Timed Event 1 Triggered - Add 100.0f Threat - Stored List 1'),
(15209, 0, 9, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 123, 50, 0, 0, 0, 0, 0, 12, 2, 0, 0, 0, 0, 0, 0, 0, 'Crimson Templar - On Timed Event 1 Triggered - Add 50.0f Threat - Stored List 2'),
(15209, 0, 10, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, 63, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Crimson Templar - On Reset - Set Counter 1 +1'),
(15209, 0, 11, 0, 77, 0, 100, 0, 1, 2, 0, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Crimson Templar - On Counter 1 = 2 - Despawn Self In 1000ms'),
(15209, 0, 12, 0, 4, 0, 100, 0, 0, 0, 0, 0, 0, 74, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Crimson Templar - On Aggro - Remove Timed Event 2'),
(15209, 0, 13, 0, 59, 0, 100, 0, 2, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Crimson Templar - On Timed Event 2 Triggered - Despawn Self Instant');

-- Azure Templar (Templar - Water)
DELETE FROM `smart_scripts` WHERE `entryorguid`=15211 AND `source_type`=0 AND `id` IN (2,3,4,5,6,7,8,9,10,11,12,13);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(15211, 0, 2, 3, 54, 0, 100, 0, 0, 0, 0, 0, 0, 67, 1, 5000, 5000, 0, 0, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Azure Templar - On Just Summoned - Create Timed Event 1'),
(15211, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 0, 67, 2, 30000, 30000, 0, 0, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Azure Templar - On Just Summoned - Create Timed Event 2'),
(15211, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 0, 103, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Azure Templar - On Just Summoned - Set Rooted On'),
(15211, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 144, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Azure Templar - On Just Summoned - Set Immune to PC On'),
(15211, 0, 6, 7, 59, 0, 100, 0, 1, 0, 0, 0, 0, 144, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Azure Templar - On Timed Event 1 Triggered - Set Immune to PC Off'),
(15211, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 0, 103, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Azure Templar - On Timed Event 1 Triggered - Set Rooted Off'),
(15211, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 0, 123, 100, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 0, 'Azure Templar - On Timed Event 1 Triggered - Add 100.0f Threat - Stored List 1'),
(15211, 0, 9, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 123, 50, 0, 0, 0, 0, 0, 12, 2, 0, 0, 0, 0, 0, 0, 0, 'Azure Templar - On Timed Event 1 Triggered - Add 50.0f Threat - Stored List 2'),
(15211, 0, 10, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, 63, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Azure Templar - On Reset - Set Counter 1 +1'),
(15211, 0, 11, 0, 77, 0, 100, 0, 1, 2, 0, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Azure Templar - On Counter 1 = 2 - Despawn Self In 1000ms'),
(15211, 0, 12, 0, 4, 0, 100, 0, 0, 0, 0, 0, 0, 74, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Azure Templar - On Aggro - Remove Timed Event 2'),
(15211, 0, 13, 0, 59, 0, 100, 0, 2, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Azure Templar - On Timed Event 2 Triggered - Despawn Self Instant');

-- Earthen Templar (Templar - Earth)
DELETE FROM `smart_scripts` WHERE `entryorguid`=15307 AND `source_type`=0 AND `id` IN (2,3,4,5,6,7,8,9,10,11,12,13);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(15307, 0, 2, 3, 54, 0, 100, 0, 0, 0, 0, 0, 0, 67, 1, 5000, 5000, 0, 0, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Earthen Templar - On Just Summoned - Create Timed Event 1'),
(15307, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 0, 67, 2, 30000, 30000, 0, 0, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Earthen Templar - On Just Summoned - Create Timed Event 2'),
(15307, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 0, 103, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Earthen Templar - On Just Summoned - Set Rooted On'),
(15307, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 144, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Earthen Templar - On Just Summoned - Set Immune to PC On'),
(15307, 0, 6, 7, 59, 0, 100, 0, 1, 0, 0, 0, 0, 144, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Earthen Templar - On Timed Event 1 Triggered - Set Immune to PC Off'),
(15307, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 0, 103, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Earthen Templar - On Timed Event 1 Triggered - Set Rooted Off'),
(15307, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 0, 123, 100, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 0, 'Earthen Templar - On Timed Event 1 Triggered - Add 100.0f Threat - Stored List 1'),
(15307, 0, 9, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 123, 50, 0, 0, 0, 0, 0, 12, 2, 0, 0, 0, 0, 0, 0, 0, 'Earthen Templar - On Timed Event 1 Triggered - Add 50.0f Threat - Stored List 2'),
(15307, 0, 10, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, 63, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Earthen Templar - On Reset - Set Counter 1 +1'),
(15307, 0, 11, 0, 77, 0, 100, 0, 1, 2, 0, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Earthen Templar - On Counter 1 = 2 - Despawn Self In 1000ms'),
(15307, 0, 12, 0, 4, 0, 100, 0, 0, 0, 0, 0, 0, 74, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Earthen Templar - On Aggro - Remove Timed Event 2'),
(15307, 0, 13, 0, 59, 0, 100, 0, 2, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Earthen Templar - On Timed Event 2 Triggered - Despawn Self Instant');

-- Hoary Templar (Templar - Air)
DELETE FROM `smart_scripts` WHERE `entryorguid`=15212 AND `source_type`=0 AND `id` IN (2,3,4,5,6,7,8,9,10,11,12,13);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(15212, 0, 2, 3, 54, 0, 100, 0, 0, 0, 0, 0, 0, 67, 1, 5000, 5000, 0, 0, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Hoary Templar - On Just Summoned - Create Timed Event 1'),
(15212, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 0, 67, 2, 30000, 30000, 0, 0, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Hoary Templar - On Just Summoned - Create Timed Event 2'),
(15212, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 0, 103, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Hoary Templar - On Just Summoned - Set Rooted On'),
(15212, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 144, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Hoary Templar - On Just Summoned - Set Immune to PC On'),
(15212, 0, 6, 7, 59, 0, 100, 0, 1, 0, 0, 0, 0, 144, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Hoary Templar - On Timed Event 1 Triggered - Set Immune to PC Off'),
(15212, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 0, 103, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Hoary Templar - On Timed Event 1 Triggered - Set Rooted Off'),
(15212, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 0, 123, 100, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 0, 'Hoary Templar - On Timed Event 1 Triggered - Add 100.0f Threat - Stored List 1'),
(15212, 0, 9, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 123, 50, 0, 0, 0, 0, 0, 12, 2, 0, 0, 0, 0, 0, 0, 0, 'Hoary Templar - On Timed Event 1 Triggered - Add 50.0f Threat - Stored List 2'),
(15212, 0, 10, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, 63, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Hoary Templar - On Reset - Set Counter 1 +1'),
(15212, 0, 11, 0, 77, 0, 100, 0, 1, 2, 0, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Hoary Templar - On Counter 1 = 2 - Despawn Self In 1000ms'),
(15212, 0, 12, 0, 4, 0, 100, 0, 0, 0, 0, 0, 0, 74, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Hoary Templar - On Aggro - Remove Timed Event 2'),
(15212, 0, 13, 0, 59, 0, 100, 0, 2, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Hoary Templar - On Timed Event 2 Triggered - Despawn Self Instant');

-- The Duke of Cynders (Duke - Fire)
DELETE FROM `smart_scripts` WHERE `entryorguid`=15206 AND `source_type`=0 AND `id` IN (3,4,5,6,7,8,9,10,11,12,13,14);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(15206, 0, 3, 4, 54, 0, 100, 0, 0, 0, 0, 0, 0, 67, 1, 5000, 5000, 0, 0, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'The Duke of Cynders - On Just Summoned - Create Timed Event 1'),
(15206, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 0, 67, 2, 30000, 30000, 0, 0, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'The Duke of Cynders - On Just Summoned - Create Timed Event 2'),
(15206, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 0, 103, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'The Duke of Cynders - On Just Summoned - Set Rooted On'),
(15206, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 144, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'The Duke of Cynders - On Just Summoned - Set Immune to PC On'),
(15206, 0, 7, 8, 59, 0, 100, 0, 1, 0, 0, 0, 0, 144, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'The Duke of Cynders - On Timed Event 1 Triggered - Set Immune to PC Off'),
(15206, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 0, 103, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'The Duke of Cynders - On Timed Event 1 Triggered - Set Rooted Off'),
(15206, 0, 9, 10, 61, 0, 100, 0, 0, 0, 0, 0, 0, 123, 100, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 0, 'The Duke of Cynders - On Timed Event 1 Triggered - Add 100.0f Threat - Stored List 1'),
(15206, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 123, 50, 0, 0, 0, 0, 0, 12, 2, 0, 0, 0, 0, 0, 0, 0, 'The Duke of Cynders - On Timed Event 1 Triggered - Add 50.0f Threat - Stored List 2'),
(15206, 0, 11, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, 63, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'The Duke of Cynders - On Reset - Set Counter 1 +1'),
(15206, 0, 12, 0, 77, 0, 100, 0, 1, 2, 0, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'The Duke of Cynders - On Counter 1 = 2 - Despawn Self In 1000ms'),
(15206, 0, 13, 0, 4, 0, 100, 0, 0, 0, 0, 0, 0, 74, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'The Duke of Cynders - On Aggro - Remove Timed Event 2'),
(15206, 0, 14, 0, 59, 0, 100, 0, 2, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'The Duke of Cynders - On Timed Event 2 Triggered - Despawn Self Instant');

-- The Duke of Fathoms (Duke - Water)
DELETE FROM `smart_scripts` WHERE `entryorguid`=15207 AND `source_type`=0 AND `id` IN (3,4,5,6,7,8,9,10,11,12,13,14);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(15207, 0, 3, 4, 54, 0, 100, 0, 0, 0, 0, 0, 0, 67, 1, 5000, 5000, 0, 0, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'The Duke of Fathoms - On Just Summoned - Create Timed Event 1'),
(15207, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 0, 67, 2, 30000, 30000, 0, 0, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'The Duke of Fathoms - On Just Summoned - Create Timed Event 2'),
(15207, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 0, 103, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'The Duke of Fathoms - On Just Summoned - Set Rooted On'),
(15207, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 144, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'The Duke of Fathoms - On Just Summoned - Set Immune to PC On'),
(15207, 0, 7, 8, 59, 0, 100, 0, 1, 0, 0, 0, 0, 144, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'The Duke of Fathoms - On Timed Event 1 Triggered - Set Immune to PC Off'),
(15207, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 0, 103, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'The Duke of Fathoms - On Timed Event 1 Triggered - Set Rooted Off'),
(15207, 0, 9, 10, 61, 0, 100, 0, 0, 0, 0, 0, 0, 123, 100, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 0, 'The Duke of Fathoms - On Timed Event 1 Triggered - Add 100.0f Threat - Stored List 1'),
(15207, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 123, 50, 0, 0, 0, 0, 0, 12, 2, 0, 0, 0, 0, 0, 0, 0, 'The Duke of Fathoms - On Timed Event 1 Triggered - Add 50.0f Threat - Stored List 2'),
(15207, 0, 11, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, 63, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'The Duke of Fathoms - On Reset - Set Counter 1 +1'),
(15207, 0, 12, 0, 77, 0, 100, 0, 1, 2, 0, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'The Duke of Fathoms - On Counter 1 = 2 - Despawn Self In 1000ms'),
(15207, 0, 13, 0, 4, 0, 100, 0, 0, 0, 0, 0, 0, 74, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'The Duke of Fathoms - On Aggro - Remove Timed Event 2'),
(15207, 0, 14, 0, 59, 0, 100, 0, 2, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'The Duke of Fathoms - On Timed Event 2 Triggered - Despawn Self Instant');

-- The Duke of Shards (Duke - Earth)
DELETE FROM `smart_scripts` WHERE `entryorguid`=15208 AND `source_type`=0 AND `id` IN (3,4,5,6,7,8,9,10,11,12,13,14);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(15208, 0, 3, 4, 54, 0, 100, 0, 0, 0, 0, 0, 0, 67, 1, 5000, 5000, 0, 0, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'The Duke of Shards - On Just Summoned - Create Timed Event 1'),
(15208, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 0, 67, 2, 30000, 30000, 0, 0, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'The Duke of Shards - On Just Summoned - Create Timed Event 2'),
(15208, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 0, 103, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'The Duke of Shards - On Just Summoned - Set Rooted On'),
(15208, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 144, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'The Duke of Shards - On Just Summoned - Set Immune to PC On'),
(15208, 0, 7, 8, 59, 0, 100, 0, 1, 0, 0, 0, 0, 144, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'The Duke of Shards - On Timed Event 1 Triggered - Set Immune to PC Off'),
(15208, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 0, 103, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'The Duke of Shards - On Timed Event 1 Triggered - Set Rooted Off'),
(15208, 0, 9, 10, 61, 0, 100, 0, 0, 0, 0, 0, 0, 123, 100, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 0, 'The Duke of Shards - On Timed Event 1 Triggered - Add 100.0f Threat - Stored List 1'),
(15208, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 123, 50, 0, 0, 0, 0, 0, 12, 2, 0, 0, 0, 0, 0, 0, 0, 'The Duke of Shards - On Timed Event 1 Triggered - Add 50.0f Threat - Stored List 2'),
(15208, 0, 11, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, 63, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'The Duke of Shards - On Reset - Set Counter 1 +1'),
(15208, 0, 12, 0, 77, 0, 100, 0, 1, 2, 0, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'The Duke of Shards - On Counter 1 = 2 - Despawn Self In 1000ms'),
(15208, 0, 13, 0, 4, 0, 100, 0, 0, 0, 0, 0, 0, 74, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'The Duke of Shards - On Aggro - Remove Timed Event 2'),
(15208, 0, 14, 0, 59, 0, 100, 0, 2, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'The Duke of Shards - On Timed Event 2 Triggered - Despawn Self Instant');

-- The Duke of Zephyrs (Duke - Air)
DELETE FROM `smart_scripts` WHERE `entryorguid`=15220 AND `source_type`=0 AND `id` IN (4,5,6,7,8,9,10,11,12,13,14,15);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(15220, 0, 4, 5, 54, 0, 100, 0, 0, 0, 0, 0, 0, 67, 1, 5000, 5000, 0, 0, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'The Duke of Zephyrs - On Just Summoned - Create Timed Event 1'),
(15220, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 0, 67, 2, 30000, 30000, 0, 0, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'The Duke of Zephyrs - On Just Summoned - Create Timed Event 2'),
(15220, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 0, 103, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'The Duke of Zephyrs - On Just Summoned - Set Rooted On'),
(15220, 0, 7, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 144, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'The Duke of Zephyrs - On Just Summoned - Set Immune to PC On'),
(15220, 0, 8, 9, 59, 0, 100, 0, 1, 0, 0, 0, 0, 144, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'The Duke of Zephyrs - On Timed Event 1 Triggered - Set Immune to PC Off'),
(15220, 0, 9, 10, 61, 0, 100, 0, 0, 0, 0, 0, 0, 103, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'The Duke of Zephyrs - On Timed Event 1 Triggered - Set Rooted Off'),
(15220, 0, 10, 11, 61, 0, 100, 0, 0, 0, 0, 0, 0, 123, 100, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 0, 'The Duke of Zephyrs - On Timed Event 1 Triggered - Add 100.0f Threat - Stored List 1'),
(15220, 0, 11, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 123, 50, 0, 0, 0, 0, 0, 12, 2, 0, 0, 0, 0, 0, 0, 0, 'The Duke of Zephyrs - On Timed Event 1 Triggered - Add 50.0f Threat - Stored List 2'),
(15220, 0, 12, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, 63, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'The Duke of Zephyrs - On Reset - Set Counter 1 +1'),
(15220, 0, 13, 0, 77, 0, 100, 0, 1, 2, 0, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'The Duke of Zephyrs - On Counter 1 = 2 - Despawn Self In 1000ms'),
(15220, 0, 14, 0, 4, 0, 100, 0, 0, 0, 0, 0, 0, 74, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'The Duke of Zephyrs - On Aggro - Remove Timed Event 2'),
(15220, 0, 15, 0, 59, 0, 100, 0, 2, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'The Duke of Zephyrs - On Timed Event 2 Triggered - Despawn Self Instant');

-- Prince Skaldrenox (Royal - Fire)
DELETE FROM `smart_scripts` WHERE `entryorguid`=15203 AND `source_type`=0 AND `id` IN (3,4,5,6,7,8,9,10,11,12,13,14);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(15203, 0, 3, 4, 54, 0, 100, 0, 0, 0, 0, 0, 0, 67, 1, 5000, 5000, 0, 0, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Prince Skaldrenox - On Just Summoned - Create Timed Event 1'),
(15203, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 0, 67, 2, 30000, 30000, 0, 0, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Prince Skaldrenox - On Just Summoned - Create Timed Event 2'),
(15203, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 0, 103, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Prince Skaldrenox - On Just Summoned - Set Rooted On'),
(15203, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 144, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Prince Skaldrenox - On Just Summoned - Set Immune to PC On'),
(15203, 0, 7, 8, 59, 0, 100, 0, 1, 0, 0, 0, 0, 144, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Prince Skaldrenox - On Timed Event 1 Triggered - Set Immune to PC Off'),
(15203, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 0, 103, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Prince Skaldrenox - On Timed Event 1 Triggered - Set Rooted Off'),
(15203, 0, 9, 10, 61, 0, 100, 0, 0, 0, 0, 0, 0, 123, 100, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 0, 'Prince Skaldrenox - On Timed Event 1 Triggered - Add 100.0f Threat - Stored List 1'),
(15203, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 123, 50, 0, 0, 0, 0, 0, 12, 2, 0, 0, 0, 0, 0, 0, 0, 'Prince Skaldrenox - On Timed Event 1 Triggered - Add 50.0f Threat - Stored List 2'),
(15203, 0, 11, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, 63, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Prince Skaldrenox - On Reset - Set Counter 1 +1'),
(15203, 0, 12, 0, 77, 0, 100, 0, 1, 2, 0, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Prince Skaldrenox - On Counter 1 = 2 - Despawn Self In 1000ms'),
(15203, 0, 13, 0, 4, 0, 100, 0, 0, 0, 0, 0, 0, 74, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Prince Skaldrenox - On Aggro - Remove Timed Event 2'),
(15203, 0, 14, 0, 59, 0, 100, 0, 2, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Prince Skaldrenox - On Timed Event 2 Triggered - Despawn Self Instant');

-- Lord Skwol (Royal - Water)
DELETE FROM `smart_scripts` WHERE `entryorguid`=15305 AND `source_type`=0 AND `id` IN (3,4,5,6,7,8,9,10,11,12,13,14);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(15305, 0, 3, 4, 54, 0, 100, 0, 0, 0, 0, 0, 0, 67, 1, 5000, 5000, 0, 0, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Lord Skwol - On Just Summoned - Create Timed Event 1'),
(15305, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 0, 67, 2, 30000, 30000, 0, 0, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Lord Skwol - On Just Summoned - Create Timed Event 2'),
(15305, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 0, 103, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Lord Skwol - On Just Summoned - Set Rooted On'),
(15305, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 144, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Lord Skwol - On Just Summoned - Set Immune to PC On'),
(15305, 0, 7, 8, 59, 0, 100, 0, 1, 0, 0, 0, 0, 144, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Lord Skwol - On Timed Event 1 Triggered - Set Immune to PC Off'),
(15305, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 0, 103, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Lord Skwol - On Timed Event 1 Triggered - Set Rooted Off'),
(15305, 0, 9, 10, 61, 0, 100, 0, 0, 0, 0, 0, 0, 123, 100, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 0, 'Lord Skwol - On Timed Event 1 Triggered - Add 100.0f Threat - Stored List 1'),
(15305, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 123, 50, 0, 0, 0, 0, 0, 12, 2, 0, 0, 0, 0, 0, 0, 0, 'Lord Skwol - On Timed Event 1 Triggered - Add 50.0f Threat - Stored List 2'),
(15305, 0, 11, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, 63, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Lord Skwol - On Reset - Set Counter 1 +1'),
(15305, 0, 12, 0, 77, 0, 100, 0, 1, 2, 0, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Lord Skwol - On Counter 1 = 2 - Despawn Self In 1000ms'),
(15305, 0, 13, 0, 4, 0, 100, 0, 0, 0, 0, 0, 0, 74, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Lord Skwol - On Aggro - Remove Timed Event 2'),
(15305, 0, 14, 0, 59, 0, 100, 0, 2, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Lord Skwol - On Timed Event 2 Triggered - Despawn Self Instant');

-- Baron Kazum (Royal - Earth)
DELETE FROM `smart_scripts` WHERE `entryorguid`=15205 AND `source_type`=0 AND `id` IN (3,4,5,6,7,8,9,10,11,12,13,14);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(15205, 0, 3, 4, 54, 0, 100, 0, 0, 0, 0, 0, 0, 67, 1, 5000, 5000, 0, 0, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Baron Kazum - On Just Summoned - Create Timed Event 1'),
(15205, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 0, 67, 2, 30000, 30000, 0, 0, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Baron Kazum - On Just Summoned - Create Timed Event 2'),
(15205, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 0, 103, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Baron Kazum - On Just Summoned - Set Rooted On'),
(15205, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 144, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Baron Kazum - On Just Summoned - Set Immune to PC On'),
(15205, 0, 7, 8, 59, 0, 100, 0, 1, 0, 0, 0, 0, 144, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Baron Kazum - On Timed Event 1 Triggered - Set Immune to PC Off'),
(15205, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 0, 103, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Baron Kazum - On Timed Event 1 Triggered - Set Rooted Off'),
(15205, 0, 9, 10, 61, 0, 100, 0, 0, 0, 0, 0, 0, 123, 100, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 0, 'Baron Kazum - On Timed Event 1 Triggered - Add 100.0f Threat - Stored List 1'),
(15205, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 123, 50, 0, 0, 0, 0, 0, 12, 2, 0, 0, 0, 0, 0, 0, 0, 'Baron Kazum - On Timed Event 1 Triggered - Add 50.0f Threat - Stored List 2'),
(15205, 0, 11, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, 63, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Baron Kazum - On Reset - Set Counter 1 +1'),
(15205, 0, 12, 0, 77, 0, 100, 0, 1, 2, 0, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Baron Kazum - On Counter 1 = 2 - Despawn Self In 1000ms'),
(15205, 0, 13, 0, 4, 0, 100, 0, 0, 0, 0, 0, 0, 74, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Baron Kazum - On Aggro - Remove Timed Event 2'),
(15205, 0, 14, 0, 59, 0, 100, 0, 2, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Baron Kazum - On Timed Event 2 Triggered - Despawn Self Instant');

-- High Marshal Whirlaxis (Royal - Air)
DELETE FROM `smart_scripts` WHERE `entryorguid`=15204 AND `source_type`=0 AND `id` IN (3,4,5,6,7,8,9,10,11,12,13,14);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(15204, 0, 3, 4, 54, 0, 100, 0, 0, 0, 0, 0, 0, 67, 1, 5000, 5000, 0, 0, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'High Marshal Whirlaxis - On Just Summoned - Create Timed Event 1'),
(15204, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 0, 67, 2, 30000, 30000, 0, 0, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'High Marshal Whirlaxis - On Just Summoned - Create Timed Event 2'),
(15204, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 0, 103, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'High Marshal Whirlaxis - On Just Summoned - Set Rooted On'),
(15204, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 144, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'High Marshal Whirlaxis - On Just Summoned - Set Immune to PC On'),
(15204, 0, 7, 8, 59, 0, 100, 0, 1, 0, 0, 0, 0, 144, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'High Marshal Whirlaxis - On Timed Event 1 Triggered - Set Immune to PC Off'),
(15204, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 0, 103, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'High Marshal Whirlaxis - On Timed Event 1 Triggered - Set Rooted Off'),
(15204, 0, 9, 10, 61, 0, 100, 0, 0, 0, 0, 0, 0, 123, 100, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 0, 'High Marshal Whirlaxis - On Timed Event 1 Triggered - Add 100.0f Threat - Stored List 1'),
(15204, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 123, 50, 0, 0, 0, 0, 0, 12, 2, 0, 0, 0, 0, 0, 0, 0, 'High Marshal Whirlaxis - On Timed Event 1 Triggered - Add 50.0f Threat - Stored List 2'),
(15204, 0, 11, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, 63, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'High Marshal Whirlaxis - On Reset - Set Counter 1 +1'),
(15204, 0, 12, 0, 77, 0, 100, 0, 1, 2, 0, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'High Marshal Whirlaxis - On Counter 1 = 2 - Despawn Self In 1000ms'),
(15204, 0, 13, 0, 4, 0, 100, 0, 0, 0, 0, 0, 0, 74, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'High Marshal Whirlaxis - On Aggro - Remove Timed Event 2'),
(15204, 0, 14, 0, 59, 0, 100, 0, 2, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'High Marshal Whirlaxis - On Timed Event 2 Triggered - Despawn Self Instant');
