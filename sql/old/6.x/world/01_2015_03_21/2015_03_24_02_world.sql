UPDATE `creature_template` SET `AIName`='' WHERE  `entry`=21669;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry`=21699;
DELETE FROM `smart_scripts` WHERE `entryorguid` In(21669,21699) and  `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(21669, 0, 0, 0, 1, 0, 100, 0, 0, 300000, 300000, 900000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Maiev Shadowsong - OOC - Say Line 0');
DELETE FROM `conditions` WHERE  `SourceTypeOrReferenceId`=13 and `SourceEntry`=35997;
