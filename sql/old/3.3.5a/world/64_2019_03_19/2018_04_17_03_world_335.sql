-- 
-- Remorseful Highborne
DELETE FROM `smart_scripts` WHERE `entryorguid`=10684 AND `source_type`=0 AND `id` IN (1,2);
DELETE FROM `smart_scripts` WHERE `entryorguid`=1068400 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10684,0,1,0,20,0,100,0,5248,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Remorseful Highborne - On Quest 'Tormented by the Past' Finished - Set Active On"),
(10684,0,2,0,20,0,100,0,5248,0,0,0,80,1068400,0,0,0,0,0,1,0,0,0,0,0,0,0,"Remorseful Highborne - On Quest 'Tormented by the Past' Finished - Run Script"),
(1068400,9,0,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,7523,500,0,0,0,0,0,"Remorseful Highborne - On Script - Set Data 1 1"),
(1068400,9,1,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,7524,500,0,0,0,0,0,"Remorseful Highborne - On Script - Set Data 1 1"),
(1068400,9,2,0,0,0,100,0,120000,120000,0,0,45,2,2,0,0,0,0,11,7523,500,0,0,0,0,0,"Remorseful Highborne - On Script - Set Data 2 2"),
(1068400,9,3,0,0,0,100,0,0,0,0,0,45,2,2,0,0,0,0,11,7524,500,0,0,0,0,0,"Remorseful Highborne - On Script - Set Data 2 2"),
(1068400,9,4,0,0,0,100,0,0,0,0,0,48,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Remorseful Highborne - On Script - Set Active Off");

-- Anguished Highborne
DELETE FROM `smart_scripts` WHERE `entryorguid`=7524 AND `source_type`=0 AND `id` IN (2,3);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7524,0,2,0,38,0,100,0,1,1,0,0,2,124,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anguished Highborne - On Data Set 1 1 - Set Faction 124"),
(7524,0,3,0,38,0,100,0,2,2,0,0,2,21,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anguished Highborne - On Data Set 2 2 - Set Faction 21");

-- Suffering Highborne
DELETE FROM `smart_scripts` WHERE `entryorguid`=7523 AND `source_type`=0 AND `id` IN (2,3);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7523,0,2,0,38,0,100,0,1,1,0,0,2,124,0,0,0,0,0,1,0,0,0,0,0,0,0,"Suffering Highborne - On Data Set 1 1 - Set Faction 124"),
(7523,0,3,0,38,0,100,0,2,2,0,0,2,21,0,0,0,0,0,1,0,0,0,0,0,0,0,"Suffering Highborne - On Data Set 2 2 - Set Faction 21");
