DELETE FROM `smart_scripts` WHERE `entryorguid`=27292 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(27292, 0, 0, 1, 62, 0, 100, 0, 9512, 0, 0, 0, 11, 48606, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Flamebringer - On gossip select - Cast Summon Flamebringer Cue'),
(27292, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Flamebringer - On gossip select - Close gossip'),
(27292, 0, 2, 3, 54, 0, 100, 0, 0, 0, 0, 0, 83, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Flamebringer - On summon - Remove npcflag'),
(27292, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 11, 48598, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Flamebringer - On Just Summoned -Cast  Ride Flamebringer Cue'),
(27292, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Flamebringer - Linked with previous Event -Set Passive'),
(27292, 0, 5, 6, 27, 0, 100, 0, 0, 0, 0, 0, 11, 48602, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Flamebringer - On passenger Boarded - Cast Flight'),
(27292, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Flamebringer - On passenger Boarded - Enable Combat'),
(27292, 0, 7, 8, 28, 0, 100, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Flamebringer - On passenger removed - Evade'),
(27292, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Flamebringer - On passenger removed - Despawn');

UPDATE `creature_template_addon` SET `auras`='' WHERE  `entry`=27292;
