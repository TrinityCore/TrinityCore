UPDATE `creature_template` SET `ScriptName`='',`AIName`='SmartAI' WHERE `entry` IN (27306,27906,27173,27904);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (27906,27173,27904) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(27906,0,0,0,25,0,100,0,0,0,0,0,0,11,48310,0,0,0,0,0,10,123746,27306,0,0,0,0,0,0,'Warmage Hollister - On Reset - Cast \'Transitus Shield Beam\''),
(27173,0,0,0,25,0,100,0,0,0,0,0,0,11,48310,0,0,0,0,0,10,123745,27306,0,0,0,0,0,0,'Warmage Calandra - On Reset - Cast \'Transitus Shield Beam\''),
(27904,0,0,0,25,0,100,0,0,0,0,0,0,11,48310,0,0,0,0,0,10,123744,27306,0,0,0,0,0,0,'Warmage Watkins - On Reset - Cast \'Transitus Shield Beam\'');
