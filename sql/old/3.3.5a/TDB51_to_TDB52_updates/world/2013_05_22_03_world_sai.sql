SET @MYSTIC := 430;
SET @POACHER := 424;
SET @SCOUT  := 578;
DELETE FROM `smart_scripts` WHERE entryorguid IN (@POACHER,@MYSTIC,@SCOUT);
-- Redridge Poacher
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@POACHER, 0, 0, 1, 1, 0, 100, 0, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Redridge Poacher - Out Of Combat - Allow Combat Movement'),
(@POACHER, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Redridge Poacher - Out Of Combat - Start Auto Attack'),
(@POACHER, 0, 2, 0, 4, 0, 10, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Redridge Poacher - On Aggro - Say Line 0'),
(@POACHER, 0, 3, 4, 4, 0, 100, 0, 0, 0, 0, 0, 11, 6660, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Redridge Poacher - On Aggro - Cast Shoot'),
(@POACHER, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Redridge Poacher - On Aggro - Increment Phase'),
(@POACHER, 0, 5, 6, 9, 0, 100, 0, 5, 30, 3400, 3700, 11, 6660, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Redridge Poacher - At 5 - 30 Range - Cast Shoot'),
(@POACHER, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 40, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Redridge Poacher - At 5 - 30 Range - Display ranged weapon'),
(@POACHER, 0, 7, 0, 9, 0, 100, 0, 25, 80, 0, 0, 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Redridge Poacher - At 25 - 80 Range - Allow Combat Movement'),
(@POACHER, 0, 8, 0, 9, 0, 100, 0, 0, 5, 0, 0, 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Redridge Poacher - At 0 - 5 Range - Allow Combat Movement'),
(@POACHER, 0, 9, 10, 9, 0, 100, 0, 0, 0, 0, 0, 40, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Redridge Poacher - At 0 - 5 Range - Display melee weapon'),
(@POACHER, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 20, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Redridge Poacher - At 0 - 5 Range - Start Auto Attack'),
(@POACHER, 0, 11, 0, 9, 0, 100, 0, 5, 15, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Redridge Poacher - At 5 - 15 Range - Allow Combat Movement'),
(@POACHER, 0, 12, 13, 2, 0, 100, 1, 0, 15, 0, 0, 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Redridge Poacher - At 15% HP - Allow Combat Movement'),
(@POACHER, 0, 13, 0, 61, 0, 100, 0, 0, 0, 0, 0, 25, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Redridge Poacher - At 15% HP - Flee For Assist'),
(@POACHER, 0, 14, 0, 7, 0, 100, 0, 0, 0, 0, 0, 40, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Redridge Poacher - On Evade - Display melee weapon');
-- Redridge Mystic
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@MYSTIC, 0, 0, 0, 1, 0, 100, 1, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Redridge Mystic - Out Of Combat - Allow Combat Movement'),
(@MYSTIC, 0, 1, 0, 4, 0, 10, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Redridge Mystic - On Aggro - Say Line 0'),
(@MYSTIC, 0, 2, 3, 4, 0, 100, 0, 0, 0, 0, 0, 11, 20802, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Redridge Mystic - On Aggro - Cast Lightning Bolt'),
(@MYSTIC, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Redridge Mystic - On Aggro - Increment Phase'),
(@MYSTIC, 0, 4, 0, 9, 0, 100, 0, 0, 40, 600, 1800, 11, 20802, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Redridge Mystic - At 0 - 40 Range - Cast Lightning Bolt'),
(@MYSTIC, 0, 5, 6, 3, 0, 100, 0, 0, 15, 0, 0, 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Redridge Mystic - At 15% Mana - Allow Combat Movement'),
(@MYSTIC, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Redridge Mystic - At 15% Mana - Increment Phase'),
(@MYSTIC, 0, 7, 0, 9, 0, 100, 1, 35, 80, 0, 0, 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Redridge Mystic - At 35 - 80 Range - Allow Combat Movement'),
(@MYSTIC, 0, 8, 0, 9, 0, 100, 1, 5, 15, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Redridge Mystic - At 5 - 15 Range - Allow Combat Movement'),
(@MYSTIC, 0, 9, 0, 9, 0, 100, 1, 0, 5, 0, 0, 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Redridge Mystic - At 0 - 5 Range - Allow Combat Movement'),
(@MYSTIC, 0, 10, 0, 3, 0, 100, 0, 30, 100, 100, 100, 23, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Redridge Mystic - At 100% Mana - Increment Phase'),
(@MYSTIC, 0, 11, 12, 14, 0, 100, 0, 0, 30, 35800, 35800, 11, 547, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Redridge Mystic - On Friendly Unit At 0 - 30% Health - Cast Healing Wave'),
(@MYSTIC, 0, 12, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Redridge Mystic - On Friendly Unit At 0 - 30% Health - Say Line 1'),
(@MYSTIC, 0, 13, 14, 2, 0, 100, 1, 0, 15, 0, 0, 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Redridge Mystic - At 15% HP - Allow Combat Movement'),
(@MYSTIC, 0, 14, 0, 61, 0, 100, 0, 0, 0, 0, 0, 25, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Redridge Mystic - At 15% HP - Flee For Assist');
-- Murloc Scout
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@SCOUT, 0, 0, 1, 1, 0, 100, 0, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Murloc Scout - Out Of Combat - Allow Combat Movement'),
(@SCOUT, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Murloc Scout - Out Of Combat - Start Auto Attack'),
(@SCOUT, 0, 2, 3, 4, 0, 100, 0, 0, 0, 0, 0, 11, 6660, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Murloc Scout - On Aggro - Cast Shoot'),
(@SCOUT, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Murloc Scout - On Aggro - Increment Phase'),
(@SCOUT, 0, 4, 5, 9, 0, 100, 0, 5, 30, 2600, 3700, 11, 6660, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Murloc Scout - At 5 - 30 Range - Cast Shoot'),
(@SCOUT, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 40, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Murloc Scout - At 5 - 30 Range - Display ranged weapon'),
(@SCOUT, 0, 6, 0, 9, 0, 100, 0, 25, 80, 0, 0, 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Murloc Scout - At 25 - 80 Range - Allow Combat Movement'),
(@SCOUT, 0, 7, 8, 9, 0, 100, 0, 0, 5, 0, 0, 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Murloc Scout - At 0 - 5 Range - Allow Combat Movement'),
(@SCOUT, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 40, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Murloc Scout - At 0 - 5 Range - Display melee weapon'),
(@SCOUT, 0, 9, 0, 61, 0, 100, 0, 0, 0, 0, 0, 20, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Murloc Scout - At 0 - 5 Range - Start Auto Attack'),
(@SCOUT, 0, 10, 0, 9, 0, 100, 0, 5, 15, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Murloc Scout - At 5 - 15 Range - Allow Combat Movement'),
(@SCOUT, 0, 11, 12, 2, 0, 100, 1, 0, 15, 0, 0, 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Murloc Scout - At 15% HP - Allow Combat Movement'),
(@SCOUT, 0, 12, 0, 61, 0, 100, 0, 0, 0, 0, 0, 25, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Murloc Scout - At 15% HP - Flee For Assist'),
(@SCOUT, 0, 13, 0, 7, 0, 100, 0, 0, 0, 0, 0, 40, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Murloc Scout - On Evade - Display melee weapon');
