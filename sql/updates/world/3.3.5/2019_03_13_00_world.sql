-- 
DELETE FROM `creature` WHERE `id` IN (21142);
DELETE FROM `spawn_group` WHERE `spawnId`=74212 AND `spawnType`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 20748 AND `source_type`=0 AND id IN (2,3);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(20748, 0, 2, 0, 8, 0, 100, 512, 32578, 0, 60000, 60000, 33, 21142, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Thunderlord Dire Wolf - on spell hit - Credit quest"),
(20748, 0, 3, 0, 8, 0, 50, 512, 32578, 0, 60000, 60000, 49, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Thunderlord Dire Wolf - on spell hit - Attack");
