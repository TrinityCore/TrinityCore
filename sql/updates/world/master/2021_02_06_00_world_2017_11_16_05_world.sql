-- 
DELETE FROM `smart_scripts` WHERE `source_type`=1 AND `entryorguid` IN (185937,185938,185936,185932);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(185932, 1, 0, 1, 62, 0, 100, 0, 8685, 0, 0, 0, 85, 41035, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Obsidia\'s Egg - On Gossip Option 0 Selected - Invoker Cast 41035 Four Dragons: Force Cast - Obsidia'),
(185932, 1, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Obsidia\'s Egg - On Gossip Option 0 Selected - Close Gossip'),
(185932, 1, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 70, 300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Obsidia\'s Egg - On Gossip Option 0 Selected - Despawn GO'),
(185936, 1, 0, 1, 62, 0, 100, 0, 8689, 0, 0, 0, 85, 41044, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Rivendark\'s Egg - On Gossip Option 0 Selected - Invoker cast Four Dragons: Force Cast - Rivendark'),
(185936, 1, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Rivendark\'s Egg - On Gossip Option 0 Selected - Close Gossip'),
(185936, 1, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 70, 300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rivendark\'s Egg - On Gossip Option 0 Selected - Despawn GO'),
(185937, 1, 0, 1, 62, 0, 100, 0, 8690, 0, 0, 0, 85, 41050, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Furywing\'s Egg - On Gossip Option 0 Selected - Invoker cast Four Dragons: Force Cast - Furywing'),
(185937, 1, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Furywing\'s Egg - On Gossip Option 0 Selected - Close Gossip'),
(185937, 1, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 70, 300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Furywing\'s Egg - On Gossip Option 0 Selected - Despawn GO'),
(185938, 1, 0, 1, 62, 0, 100, 0, 8691, 0, 0, 0, 85, 41052, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Insidion\'s Egg - On Gossip Option 0 Selected - Invoker cast Four Dragons: Force Cast - Insidion'),
(185938, 1, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Insidion\'s Egg - On Gossip Option 0 Selected - Close Gossip'),
(185938, 1, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 70, 300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Insidion\'s Egg - On Gossip Option 0 Selected - Despawn GO');
