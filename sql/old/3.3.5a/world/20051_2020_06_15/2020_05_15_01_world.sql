--
UPDATE `smart_scripts` SET `action_type` = 69, `action_param1` = 1, `action_param4` = 10, `target_type` = 19, `target_param1` = 15608, `target_param2` = 200, `comment` = "Infinite Assassin - Out of Combat - Move To Closest Creature 'Medivh'" WHERE `entryorguid` = 17835 AND `source_type` = 0 AND `id` = 0;
UPDATE `smart_scripts` SET `action_type` = 69, `action_param1` = 1, `action_param4` = 10, `target_type` = 19, `target_param1` = 15608, `target_param2` = 200, `comment` = "Infinite Chronomancer - Out of Combat - Move To Closest Creature 'Medivh'" WHERE `entryorguid` = 17892 AND `source_type` = 0 AND `id` = 1;
UPDATE `smart_scripts` SET `action_type` = 69, `action_param1` = 1, `action_param4` = 10, `target_type` = 19, `target_param1` = 15608, `target_param2` = 200, `comment` = "Infinite Vanquisher - Out of Combat - Move To Closest Creature 'Medivh'" WHERE `entryorguid` = 18995 AND `source_type` = 0 AND `id` = 1;
UPDATE `smart_scripts` SET `action_type` = 69, `action_param1` = 1, `action_param4` = 10, `target_type` = 19, `target_param1` = 15608, `target_param2` = 200, `comment` = "Infinite Whelp - Out of Combat - Move To Closest Creature 'Medivh'" WHERE `entryorguid` = 21818 AND `source_type` = 0 AND `id` = 0;
UPDATE `smart_scripts` SET `event_type` = 34, `event_param1` = 8, `event_param2` = 1, `comment` = "Infinite Assassin - On Movement Inform - Cast 'Corrupt Medivh'" WHERE `entryorguid` = 17835 AND `source_type` = 0 AND `id` = 13;
UPDATE `smart_scripts` SET `event_type` = 34, `event_param1` = 8, `event_param2` = 1, `comment` = "Infinite Chronomancer - On Movement Inform - Cast 'Corrupt Medivh'" WHERE `entryorguid` = 17892 AND `source_type` = 0 AND `id` = 32;
UPDATE `smart_scripts` SET `event_type` = 34, `event_param1` = 8, `event_param2` = 1, `comment` = "Infinite Vanquisher - On Movement Inform - Cast 'Corrupt Medivh'" WHERE `entryorguid` = 18995 AND `source_type` = 0 AND `id` = 18;
UPDATE `smart_scripts` SET `event_type` = 34, `event_param1` = 8, `event_param2` = 1, `comment` = "Infinite Whelp - On Movement Inform - Cast 'Corrupt Medivh'" WHERE `entryorguid` = 21818 AND `source_type` = 0 AND `id` = 2;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 17835 AND `source_type` = 0 AND `id` = 14;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 17892 AND `source_type` = 0 AND `id` = 33;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 18995 AND `source_type` = 0 AND `id` = 19;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 21818 AND `source_type` = 0 AND `id` = 3;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(17835,0,14,0,34,0,100,7,8,1,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Assassin - On Movement Inform - Set Home Position"),
(17892,0,33,0,34,0,100,7,8,1,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Chronomancer - On Movement Inform - Set Home Position"),
(18995,0,19,0,34,0,100,7,8,1,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Vanquisher - On Movement Inform - Set Home Position"),
(21818,0,3,0,34,0,100,7,8,1,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Whelp - On Movement Inform - Set Home Position");

DELETE FROM `smart_scripts` WHERE `entryorguid`=18994 AND `source_type`=0 AND `id` IN (6,7,8);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(18994, 0, 6, 0, 1, 0, 100, 7, 1000, 1000, 0, 0, 0, 69, 1, 0, 0, 10, 0, 0, 19, 15608, 200, 0, 0, 0, 0, 0, 0, "Infinite Executioner - Out of Combat - Move To Closest Creature 'Medivh'"),
(18994, 0, 7, 0, 34, 0, 100, 7, 8, 1, 0, 0, 0, 11, 31326, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Infinite Executioner - On Movement Inform - Cast 'Corrupt Medivh'"),
(18994, 0, 8, 0, 34, 0, 100, 7, 8, 1, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Infinite Executioner - On Movement Inform - Set Home Position");
