DELETE FROM `smart_scripts` WHERE `entryorguid` IN(25342,25343) AND `source_type`=0 AND `id`>2;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE  `entryorguid` IN(25342,25343) AND `source_type`=0 AND `id`=2 AND `link`=3;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(25342, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 50, 182071, 30, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dead Caravan Guard - On Spellhit \'Ragefist\'s Torch\' - Spawn GO Small Chapel Fire'),
(25343, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 50, 182071, 30, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dead Caravan Worker - On Spellhit \'Ragefist\'s Torch\' - Spawn GO Small Chapel Fire'),
(25342, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 30000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dead Caravan Guard - On Spellhit \'Ragefist\'s Torch\' - Despawn after 30 seconds'),
(25343, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 30000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dead Caravan Worker - On Spellhit \'Ragefist\'s Torch\' - Despawn after 30 seconds');
UPDATE `creature_template_addon` SET `auras`='48602' WHERE  `entry`=27292;
