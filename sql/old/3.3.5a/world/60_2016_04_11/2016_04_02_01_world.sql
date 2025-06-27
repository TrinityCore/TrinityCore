DELETE FROM `smart_scripts` WHERE `entryorguid` IN(9297,9521,9526,9527) AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(9297, 0, 1, 0, 0, 0, 100, 0, 15000, 15000, 12000, 15000, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Enraged Wyvern - OOC - Despawn'),
(9521, 0, 1, 0, 0, 0, 100, 0, 15000, 15000, 12000, 15000, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Enraged Felbat - OOC - Despawn'),
(9526, 0, 1, 0, 0, 0, 100, 0, 15000, 15000, 15000, 15000, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Enraged Gryphon - OOC - Despawn'),
(9527, 0, 1, 0, 0, 0, 100, 0, 15000, 15000, 12000, 15000, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Enraged Hippogryph - OOC - Despawn');

-- Demon Portal Guardian SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=11937;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11937 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(11937, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 21, 30, 0, 0, 0, 0, 0, 0, 'Demon Portal Guardian - On Just Summoned - Attack'),
(11937, 0, 1, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Demon Portal Guardian - On Agro - Attack'),
(11937, 0, 2, 0, 1, 0, 100, 1, 30000, 30000, 30000, 30000, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Demon Portal Guardian - Out of Combat - Despawn');

-- set correct broadcast_text ID for Vim'gol the Vile's aggro text in creature_text
UPDATE `creature_text` SET `BroadcastTextId`= 20773 WHERE `BroadcastTextId`= 20733 AND `entry`= 22911;
