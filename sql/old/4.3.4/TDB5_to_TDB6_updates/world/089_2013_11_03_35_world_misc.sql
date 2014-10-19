--
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=25791; 

DELETE FROM `smart_scripts` WHERE `entryorguid`=25791;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(25791, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 11, 45948, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Oil-stained Wolf - On Respawn - Cast Oil Coat'),
(25791, 0, 1, 0, 8 ,0, 100, 1, 53326, 0, 0, 0, 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Oil-stained Wolf - On Spellhit - Increment Phase'),
(25791, 0, 2, 3, 1 ,1, 100, 1, 1000, 1000, 0, 0, 2, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Oil-stained Wolf - OOC - Set Faction'),
(25791, 0, 3, 4,61 ,1, 100, 1, 0, 0, 0, 0, 11, 46075, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Oil-stained Wolf - Linked with Previous Event - Cast Summon Wolf Droppings'),
(25791, 0, 4, 5,61 ,1, 100, 1, 0, 0, 0, 0, 89, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Oil-stained Wolf - Linked with Previous Event - Set Random Movement'),
(25791, 0, 5, 0,61 ,1, 100, 1, 0, 0, 0, 0, 41, 15000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Oil-stained Wolf - Linked with Previous Event - Despawn'),
(25791, 0, 6, 7, 0 ,1, 100, 1, 1000, 1000, 0, 0, 2, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Oil-stained Wolf - IC - Set Faction'),
(25791, 0, 7, 8,61 ,1, 100, 1, 0, 0, 0, 0, 11, 46075, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Oil-stained Wolf - Linked with Previous Event - Cast Summon Wolf Droppings'),
(25791, 0, 8, 9,61 ,1, 100, 1, 0, 0, 0, 0, 89, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Oil-stained Wolf - Linked with Previous Event - Set Random Movement'),
(25791, 0, 9,10,61 ,1, 100, 1, 0, 0, 0, 0, 41, 15000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Oil-stained Wolf - Linked with Previous Event - Despawn'),
(25791, 0,10, 0,61 ,1, 100, 1, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Oil-stained Wolf - Linked with Previous Event - Evade');
