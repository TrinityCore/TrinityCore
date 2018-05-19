UPDATE `creature_template` SET `gossip_menu_id`='0', `npcflag`='4226' WHERE  `entry`=38978;

DELETE FROM `spell_area` WHERE `spell`=73134;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `teamId`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES 
(73134, 168, 24999, 0, 0, -1, 0, 2, 1, 8, 11);

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry`=38937;
DELETE FROM `smart_scripts` WHERE `entryorguid`=38937;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(38937, 0, 0, 0, 23, 0, 100, 512, 73133, 3, 9999, 9999, '', 37, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vile Fin Tadpole - Tetard - Has Aura x3 - Die'),
(38937, 0, 1, 0, 6, 0, 100, 512, 0, 0, 0, 0, '', 33, 38937, 0, 0, 0, 0, 0, 21, 15, 0, 0, 0, 0, 0, 0, 'Vile Fin Tadpole - Tetard - On Death - KillCredit');

