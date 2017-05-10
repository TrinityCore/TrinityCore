UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE  `id`=23311;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid` IN(2331100,2331101,2331102) AND `id`>0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(2331100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 2, 35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Disobedient Dragonmaw Peon - Script 1 - Set Faction'),
(2331100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 89, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Disobedient Dragonmaw Peon - Script 1 - Set Random Movement'),
(2331101, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 2, 35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Disobedient Dragonmaw Peon - Script 2 - Set Faction');
