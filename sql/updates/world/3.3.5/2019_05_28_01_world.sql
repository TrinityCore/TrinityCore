-- 
DELETE FROM `smart_scripts` WHERE `entryorguid`=21719 AND `source_type`=0 AND `id`=15;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21719, 0, 15, 0, 6, 0, 100, 0, 0, 0, 0, 0, 11, 38341, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dragonmaw Drake-Rider - On Death - Cast Summon Enslaved Netherdrake');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (22000);
DELETE FROM `smart_scripts` WHERE `entryorguid`=22000 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(22000, 0, 0, 0, 7, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dragonmaw Nether Drake - On evade - Despawns'),
(22000, 0, 1, 0, 54, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 21, 30, 0, 0, 0, 0, 0, 0, 'Dragonmaw Nether Drake - On just summoned - Start Attack'),
(22000, 0, 2, 0, 0, 0, 100, 0, 5000, 8000, 5000, 8000, 11, 38344, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Dragonmaw Nether Drake - IC - Cast Arcane Blast');
