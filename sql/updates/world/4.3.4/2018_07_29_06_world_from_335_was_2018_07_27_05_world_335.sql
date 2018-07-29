/*
-- 
-- Ma'ruk Wyrmscale
DELETE FROM `smart_scripts` WHERE `entryorguid`=2090 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2090,0,0,0,4,0,100,0,0,0,0,0,0,11,9128,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ma'ruk Wyrmscale - On Aggro - Cast 'Battle Shout'");

-- Black Slime
DELETE FROM `smart_scripts` WHERE `entryorguid`=1030 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1030,0,0,0,0,0,100,1,5000,9000,0,0,0,11,3335,0,0,0,0,0,1,0,0,0,0,0,0,0,"Black Slime - In Combat - Cast 'Dark Sludge' (No Repeat)");

-- Sludginn
DELETE FROM `smart_scripts` WHERE `entryorguid`=14433 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14433,0,0,0,0,0,100,1,9000,11000,0,0,0,11,3335,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sludginn - In Combat - Cast 'Dark Sludge' (No Repeat)"),
(14433,0,1,0,0,0,100,0,5000,8000,21000,23000,0,11,3358,32,0,0,0,0,2,0,0,0,0,0,0,0,"Sludginn - In Combat - Cast 'Leech Poison'");

-- Mosshide Gnoll
DELETE FROM `smart_scripts` WHERE `entryorguid`=1007 AND `source_type`=0 AND `id` IN (1,2,3);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1007,0,1,0,25,0,100,0,0,0,0,0,0,11,8852,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mosshide Gnoll - On Reset - Cast 'Moss Hide'"),
(1007,0,2,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Mosshide Gnoll - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Mosshide Mongrel
DELETE FROM `smart_scripts` WHERE `entryorguid`=1008 AND `source_type`=0 AND `id` IN (1,2,3,4);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1008,0,1,0,0,0,100,0,6000,13000,17000,24000,0,11,8016,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mosshide Mongrel - In Combat - Cast 'Spirit Decay'"),
(1008,0,2,0,25,0,100,0,0,0,0,0,0,11,8852,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mosshide Mongrel - On Reset - Cast 'Moss Hide'"),
(1008,0,3,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Mosshide Mongrel - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Mosshide Fenrunner
DELETE FROM `smart_scripts` WHERE `entryorguid`=1010 AND `source_type`=0 AND `id` IN (1,2,3);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1010,0,1,0,25,0,100,0,0,0,0,0,0,11,8852,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mosshide Fenrunner - On Reset - Cast 'Moss Hide'"),
(1010,0,2,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Mosshide Fenrunner - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Mosshide Mistweaver
UPDATE `smart_scripts` SET `event_param3`=3000, `event_param4`=5000 WHERE `entryorguid`=1009 AND `source_type`=0 AND `id`=2;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1009 AND `source_type`=0 AND `id` IN (0,3,4,5);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1009,0,0,0,1,0,100,0,1000,1000,1800000,1800000,0,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mosshide Mistweaver - Out of Combat - Cast 'Frost Armor'"),
(1009,0,3,0,25,0,100,0,0,0,0,0,0,11,8852,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mosshide Mistweaver - On Reset - Cast 'Moss Hide'"),
(1009,0,4,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Mosshide Mistweaver - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Mosshide Trapper
DELETE FROM `smart_scripts` WHERE `entryorguid`=1011 AND `source_type`=0 AND `id` IN (1,2,3,4);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1011,0,1,0,0,0,100,0,4000,11000,15000,22000,0,11,6533,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mosshide Trapper - In Combat - Cast 'Net'"),
(1011,0,2,0,25,0,100,0,0,0,0,0,0,11,8852,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mosshide Trapper - On Reset - Cast 'Moss Hide'"),
(1011,0,3,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Mosshide Trapper - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Mosshide Brute
DELETE FROM `smart_scripts` WHERE `entryorguid`=1012 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1012,0,2,0,25,0,100,0,0,0,0,0,0,11,8852,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mosshide Brute - On Reset - Cast 'Moss Hide'");

-- Mosshide Alpha
DELETE FROM `smart_scripts` WHERE `entryorguid`=1014 AND `source_type`=0 AND `id` IN (1,2,3,4);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1014,0,1,0,4,0,100,0,0,0,0,0,0,11,9128,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mosshide Alpha - On Aggro - Cast 'Battle Shout'"),
(1014,0,2,0,25,0,100,0,0,0,0,0,0,11,8852,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mosshide Alpha - On Reset - Cast 'Moss Hide'"),
(1014,0,3,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Mosshide Alpha - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Mosshide Mystic
DELETE FROM `smart_scripts` WHERE `entryorguid`=1013 AND `source_type`=0 AND `id` IN (2,3,4,5,6);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1013,0,2,0,0,0,100,0,8000,14000,18000,24000,0,11,11436,0,0,0,0,0,5,0,0,0,0,0,0,0,"Mosshide Mystic - In Combat - Cast 'Slow'"),
(1013,0,3,0,14,0,100,0,320,40,25000,30000,0,11,11986,0,0,0,0,0,7,0,0,0,0,0,0,0,"Mosshide Mystic - Friendly At 320 Health - Cast 'Healing Wave'"),
(1013,0,4,0,25,0,100,0,0,0,0,0,0,11,8852,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mosshide Mystic - On Reset - Cast 'Moss Hide'"),
(1013,0,5,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Mosshide Mystic - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Leech Stalker
DELETE FROM `smart_scripts` WHERE `entryorguid`=1111 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1111,0,0,0,0,0,100,0,5000,13000,21000,23000,0,11,3358,32,0,0,0,0,2,0,0,0,0,0,0,0,"Leech Stalker - In Combat - Cast 'Leech Poison'");

-- Cave Stalker
DELETE FROM `smart_scripts` WHERE `entryorguid`=4040 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4040,0,0,0,0,0,100,0,5000,13000,21000,23000,0,11,3358,32,0,0,0,0,2,0,0,0,0,0,0,0,"Cave Stalker - In Combat - Cast 'Leech Poison'");

-- Leech Widow
DELETE FROM `smart_scripts` WHERE `entryorguid`=1112 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1112,0,0,0,0,0,100,0,7000,11000,21000,22000,0,11,3388,32,0,0,0,0,2,0,0,0,0,0,0,0,"Leech Widow - In Combat - Cast 'Deadly Leech Poison'");

-- Red Whelp
DELETE FROM `smart_scripts` WHERE `entryorguid`=1042 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1042,0,0,0,0,0,100,0,3000,11000,13000,21000,0,11,3356,0,0,0,0,0,2,0,0,0,0,0,0,0,"Red Whelp - In Combat - Cast 'Flame Lash'");

-- Black Ooze
DELETE FROM `smart_scripts` WHERE `entryorguid`=1032 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1032,0,0,0,25,0,100,0,0,0,0,0,0,11,3235,0,0,0,0,0,1,0,0,0,0,0,0,0,"Black Ooze - On Reset - Cast 'Rancid Blood'");

-- Crimson Ooze
DELETE FROM `smart_scripts` WHERE `entryorguid`=1031 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1031,0,0,0,25,0,100,0,0,0,0,0,0,11,3235,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Ooze - On Reset - Cast 'Rancid Blood'");

-- Monstrous Ooze
DELETE FROM `smart_scripts` WHERE `entryorguid`=1033 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1033,0,0,0,25,0,100,0,0,0,0,0,0,11,3235,0,0,0,0,0,1,0,0,0,0,0,0,0,"Monstrous Ooze - On Reset - Cast 'Rancid Blood'");

-- Rotting Ancestor
DELETE FROM `smart_scripts` WHERE `entryorguid`=1530 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1530,0,0,0,25,0,100,0,0,0,0,0,0,11,3235,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rotting Ancestor - On Reset - Cast 'Rancid Blood'");

-- Bleeding Horror
DELETE FROM `smart_scripts` WHERE `entryorguid`=1529 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1529,0,0,0,25,0,100,0,0,0,0,0,0,11,3235,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Horror - On Reset - Cast 'Rancid Blood'");

-- Highland Lashtail
DELETE FROM `smart_scripts` WHERE `entryorguid`=1016 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1016,0,0,0,0,0,100,0,5000,11000,13000,19000,0,11,6607,2,0,0,0,0,2,0,0,0,0,0,0,0,"Highland Lashtail - In Combat - Cast 'Lash'");
UPDATE `smart_scripts` SET `action_param2`=2 WHERE `action_type`=11 AND `action_param1`=6607;

-- Highland Scytheclaw
DELETE FROM `smart_scripts` WHERE `entryorguid`=1017 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1017,0,0,0,0,0,100,0,4000,9000,12000,17000,0,11,3147,0,0,0,0,0,2,0,0,0,0,0,0,0,"Highland Scytheclaw - In Combat - Cast 'Rend Flesh'");

-- Highland Razormaw
DELETE FROM `smart_scripts` WHERE `entryorguid`=1018 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1018,0,0,0,0,0,100,0,5000,12000,15000,19000,0,11,3427,0,0,0,0,0,2,0,0,0,0,0,0,0,"Highland Razormaw - In Combat - Cast 'Infected Wound'");

-- Elder Razormaw
DELETE FROM `smart_scripts` WHERE `entryorguid`=1019 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1019,0,0,0,0,0,100,0,4000,9000,11000,16000,0,11,3604,0,0,0,0,0,2,0,0,0,0,0,0,0,"Elder Razormaw - In Combat - Cast 'Tendon Rip'");

-- Razormaw Matriarch
DELETE FROM `smart_scripts` WHERE `entryorguid`=1140 AND `source_type`=0 AND `id` IN (2,3);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1140,0,2,0,12,0,100,1,0,20,0,0,0,11,7938,0,0,0,0,0,2,0,0,0,0,0,0,0,"Razormaw Matriarch - In Combat - Target Between 0-20% Health - Cast 'Fatal Bite' (No Repeat)"),
(1140,0,3,0,0,0,100,0,5000,8000,11000,16000,0,11,3147,0,0,0,0,0,2,0,0,0,0,0,0,0,"Razormaw Matriarch - In Combat - Cast 'Rend Flesh'");

-- Dark Iron Dwarf
DELETE FROM `smart_scripts` WHERE `entryorguid`=1051 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1051,0,1,0,0,0,100,0,1000,8000,11000,20000,0,11,7891,2,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Iron Dwarf - In Combat - Cast 'Gift of Ragnaros'");

-- Dark Iron Rifleman
DELETE FROM `smart_scripts` WHERE `entryorguid`=6523 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6523,0,2,0,0,0,100,0,1000,8000,11000,20000,0,11,7891,2,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Iron Rifleman - In Combat - Cast 'Gift of Ragnaros'");

-- Dark Iron Demolitionist
DELETE FROM `smart_scripts` WHERE `entryorguid`=1054 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1054,0,2,0,0,0,100,0,1000,8000,11000,20000,0,11,7891,2,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Iron Demolitionist - In Combat - Cast 'Gift of Ragnaros'");

-- Dark Iron Saboteur
DELETE FROM `smart_scripts` WHERE `entryorguid`=1052 AND `source_type`=0 AND `id` IN (0,4);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1052,0,0,0,0,0,100,0,1000,8000,11000,20000,0,11,7891,2,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Iron Saboteur - In Combat - Cast 'Gift of Ragnaros'"),
(1052,0,4,0,4,0,15,0,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Saboteur - On Aggro - Say Line 2");

DELETE FROM `creature_text` WHERE `CreatureID`=1052 AND `GroupID`=2;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1052,2,0,"Never cross a Dark Iron, $C.",12,0,100,0,0,0,1934,0,"Dark Iron Saboteur"),
(1052,2,1,"Time to die, $C.",12,0,100,0,0,0,1935,0,"Dark Iron Saboteur"),
(1052,2,2,"Feel the power of the Dark Iron Dwarves!",12,0,100,0,0,0,1936,0,"Dark Iron Saboteur");

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=3204;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(3204,8329,0,"Sapper Explode");

-- Dark Iron Tunneler
DELETE FROM `smart_scripts` WHERE `entryorguid`=1053 AND `source_type`=0 AND `id` IN (1,2,3);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1053,0,1,0,4,0,100,0,0,0,0,0,0,11,7164,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Tunneler - In Combat - Cast 'Defensive Stance'"),
(1053,0,2,0,0,0,100,0,1000,8000,11000,20000,0,11,7891,2,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Iron Tunneler - In Combat - Cast 'Gift of Ragnaros'"),
(1053,0,3,0,0,0,100,0,5000,9000,11000,15000,0,11,11971,2,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Iron Tunneler - In Combat - Cast 'Sunder Armor'");

-- Balgaras the Foul
DELETE FROM `smart_scripts` WHERE `entryorguid`=1364 AND `source_type`=0 AND `id` IN (2,3,4);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1364,0,2,0,0,0,100,0,3000,5000,11000,13000,0,11,9081,0,0,0,0,0,1,0,0,0,0,0,0,0,"Balgaras the Foul - In Combat - Cast 'Shadow Bolt Volley'"),
(1364,0,3,0,0,0,100,0,8000,12000,13000,16000,0,11,11831,0,0,0,0,0,1,0,0,0,0,0,0,0,"Balgaras the Foul - In Combat - Cast 'Frost Nova'"),
(1364,0,4,0,0,0,100,0,11000,13000,181000,182000,0,11,3586,0,0,0,0,0,2,0,0,0,0,0,0,0,"Balgaras the Foul - In Combat - Cast 'Volatile Infection'");

-- Fen Creeper
DELETE FROM `smart_scripts` WHERE `entryorguid`=1040 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1040,0,0,0,25,0,100,0,0,0,0,0,0,11,22766,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fen Creeper - On Reset - Cast 'Sneak'");

-- Chimaera Matriarch
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6167;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6167 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(6167,0,0,0,0,0,100,0,3000,5000,7000,12000,0,11,3396,0,0,0,0,0,5,0,0,0,0,0,0,0,"Chimaera Matriarch - In Combat - Cast 'Corrosive Poison'");

-- Condemned Cleric
DELETE FROM `smart_scripts` WHERE `entryorguid`=7070 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7070,0,1,0,14,0,100,0,3000,40,18000,21000,0,11,15586,0,0,0,0,0,7,0,0,0,0,0,0,0,"Condemned Cleric - Friendly At 3000 Health - Cast 'Heal'");

-- Condemned Acolyte
DELETE FROM `smart_scripts` WHERE `entryorguid`=7068 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7068,0,1,0,14,0,100,0,3000,40,18000,25000,0,11,25058,0,0,0,0,0,7,0,0,0,0,0,0,0,"Condemned Acolyte - Friendly At 3000 Health - Cast 'Renew'");

-- Dragonmaw Raider
DELETE FROM `smart_scripts` WHERE `entryorguid`=1034 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1034,0,1,0,0,0,100,0,2000,13000,15000,26000,0,11,6533,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonmaw Raider - In Combat - Cast 'Net'");

-- Dragonmaw Swamprunner
DELETE FROM `smart_scripts` WHERE `entryorguid`=1035 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1035,0,1,0,25,0,100,0,0,0,0,0,0,11,3616,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Swamprunner - On Reset - Cast 'Poison Proc'");

-- Garneg Charskull
DELETE FROM `smart_scripts` WHERE `entryorguid`=2108 AND `source_type`=0 AND `id` IN (1,2,3);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2108,0,1,0,0,0,100,0,1000,2000,4000,6000,0,11,184,32,0,0,0,0,1,0,0,0,0,0,0,0,"Garneg Charskull - In Combat - Cast 'Fire Shield II'"),
(2108,0,2,0,0,0,100,0,4000,6000,8000,12000,0,11,15039,0,0,0,0,0,2,0,0,0,0,0,0,0,"Garneg Charskull - In Combat - Cast 'Flame Shock'"),
(2108,0,3,0,0,0,100,0,9000,12000,18000,21000,0,11,6725,0,0,0,0,0,2,0,0,0,0,0,0,0,"Garneg Charskull - In Combat - Cast 'Flame Spike'");

-- Dragonmaw Bonewarder
DELETE FROM `smart_scripts` WHERE `entryorguid`=1057 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1057,0,0,0,4,0,15,1,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Bonewarder - On Aggro - Say Line 0"),
(1057,0,1,0,1,0,100,1,1000,3000,0,0,0,11,8853,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Bonewarder - Out of Combat - Cast 'Summon Skeleton'"),
(1057,0,2,0,0,0,100,0,3000,6000,14000,19000,0,11,707,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonmaw Bonewarder - In Combat - Cast 'Immolate'"),
(1057,0,3,0,0,0,100,0,8000,14000,8000,14000,0,11,6205,32,0,0,0,0,5,0,0,0,0,0,0,0,"Dragonmaw Bonewarder - In Combat - Cast 'Curse of Weakness'"),
(1057,0,4,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Dragonmaw Bonewarder - Between 0-15% Health - Flee For Assist (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID`=1057;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1057,0,0,"Your bones will break under my boot, $r!",12,1,100,0,0,0,1938,0,"Dragonmaw Bonewarder"),
(1057,0,1,"Long live the Dragonmaw! Die you worthless $r!",12,1,100,0,0,0,1939,0,"Dragonmaw Bonewarder"),
(1057,0,2,"For the Dragonmaw!",12,1,100,0,0,0,1937,0,"Dragonmaw Bonewarder");

-- Dragonmaw Shadowwarder
DELETE FROM `smart_scripts` WHERE `entryorguid`=1038 AND `source_type`=0 AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1038,0,3,0,4,0,15,1,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Shadowwarder - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=1038;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1038,0,0,"Your bones will break under my boot, $r!",12,1,100,0,0,0,1938,0,"Dragonmaw Shadowwarder"),
(1038,0,1,"Long live the Dragonmaw! Die you worthless $r!",12,1,100,0,0,0,1939,0,"Dragonmaw Shadowwarder"),
(1038,0,2,"For the Dragonmaw!",12,1,100,0,0,0,1937,0,"Dragonmaw Shadowwarder");

-- Dragonmaw Centurion
DELETE FROM `smart_scripts` WHERE `entryorguid`=1036 AND `source_type`=0 AND `id` IN (1,2,3,4);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1036,0,1,0,4,0,100,0,0,0,0,0,0,11,643,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Centurion - On Aggro - Cast 'Devotion Aura'"),
(1036,0,2,0,25,0,100,0,0,0,0,0,0,11,7164,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Centurion - On Reset - Cast 'Defensive Stance'"),
(1036,0,3,0,0,0,100,0,5000,7000,11000,13000,0,11,1672,2,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonmaw Centurion - In Combat - Cast 'Shield Bash'"),
(1036,0,4,0,0,0,100,0,5000,13000,21000,29000,0,11,3419,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Centurion - In Combat - Cast 'Improved Blocking'");

-- Dragonmaw Battlemaster
DELETE FROM `smart_scripts` WHERE `entryorguid`=1037 AND `source_type`=0 AND `id` IN (0,2,3);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1037,0,0,0,4,0,100,1,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Battlemaster - On Aggro - Say Line 0"),
(1037,0,2,3,0,0,100,0,9000,14000,19000,28000,0,11,3019,2,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Battlemaster - In Combat - Cast 'Frenzy'"),
(1037,0,3,0,61,0,100,1,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Battlemaster - In Combat - Say Line 1");

DELETE FROM `creature_text` WHERE `CreatureID`=1037;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1037,0,0,"Your bones will break under my boot, $r!",12,1,100,0,0,0,1938,0,"Dragonmaw Shadowwarder"),
(1037,0,1,"Long live the Dragonmaw! Die you worthless $r!",12,1,100,0,0,0,1939,0,"Dragonmaw Shadowwarder"),
(1037,0,2,"For the Dragonmaw!",12,1,100,0,0,0,1937,0,"Dragonmaw Shadowwarder"),
(1037,1,0,"%s goes into a frenzy!",16,0,100,0,0,0,2384,0,"Dragonmaw Shadowwarder");

-- Chieftain Nek'rosh
UPDATE `smart_scripts` SET `action_param2`=2 WHERE `entryorguid`=2091 AND `source_type`=0 AND `id`=1;

-- Mottled Scytheclaw
DELETE FROM `smart_scripts` WHERE `entryorguid`=1022 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1022,0,0,0,0,0,100,0,4000,12000,15000,23000,0,11,3147,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mottled Scytheclaw - In Combat - Cast 'Rend Flesh'");

-- Mottled Razormaw
DELETE FROM `smart_scripts` WHERE `entryorguid`=1023 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1023,0,0,0,0,0,100,0,5000,12000,15000,19000,0,11,3427,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mottled Razormaw - In Combat - Cast 'Infected Wound'");

-- Sarltooth
DELETE FROM `smart_scripts` WHERE `entryorguid`=1353 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1353,0,0,0,25,0,100,0,0,0,0,0,0,11,8876,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sarltooth - On Reset - Cast 'Thrash'"),
(1353,0,1,0,0,0,100,0,5000,9000,12000,16000,0,11,3427,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sarltooth - In Combat - Cast 'Infected Wound'");

-- Bluegill Forager
DELETE FROM `smart_scripts` WHERE `entryorguid`=1026 AND `source_type`=0 AND `id` IN (0,1);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1026,0,0,0,25,0,100,0,0,0,0,0,0,11,3616,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bluegill Forager - On Reset - Cast 'Poison Proc'"),
(1026,0,1,0,0,0,100,0,5000,11000,13000,19000,0,11,14873,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bluegill Forager - In Combat - Cast 'Sinister Strike'");

-- Bluegill Warrior
DELETE FROM `smart_scripts` WHERE `entryorguid`=1027 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1027,0,0,0,4,0,100,0,0,0,0,0,0,11,7165,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bluegill Warrior - On Aggro - Cast 'Battle Stance'");

-- Bluegill Muckdweller
DELETE FROM `smart_scripts` WHERE `entryorguid`=1028 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1028,0,0,0,0,0,100,0,5000,7000,11000,14000,0,11,1777,2,0,0,0,0,2,0,0,0,0,0,0,0,"Bluegill Muckdweller - In Combat - Cast 'Gouge'");

-- Bluegill Oracle
DELETE FROM `smart_scripts` WHERE `entryorguid`=1029 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1029,0,1,0,14,0,100,0,350,40,12000,24000,0,11,939,0,0,0,0,0,7,0,0,0,0,0,0,0,"Bluegill Oracle - Friendly At 350 Health - Cast 'Healing Wave'");

-- Giant Wetlands Crocolisk
DELETE FROM `smart_scripts` WHERE `entryorguid`=2089 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(2089,0,0,0,0,0,100,0,6000,9000,12000,18000,0,11,3604,2,0,0,0,0,2,0,0,0,0,0,0,0,"Giant Wetlands Crocolisk - In Combat - Cast 'Tendon Rip'");

-- Cursed Sailor
DELETE FROM `smart_scripts` WHERE `entryorguid`=1157 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1157,0,1,0,0,0,100,0,4000,15000,25000,32000,0,11,10651,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cursed Sailor - In Combat - Cast 'Curse of the Eye'");

-- Cursed Marine
UPDATE `smart_scripts` SET `event_param1`=4000, `event_param2`=15000, `event_param3`=25000, `event_param4`=32000, `action_param2`=0 WHERE `entryorguid`=1158 AND `source_type`=0 AND `id`=1;

-- First Mate Snellig
UPDATE `smart_scripts` SET `event_param1`=6000, `event_param2`=9000, `event_param3`=11000, `event_param4`=14000 WHERE `entryorguid`=1159 AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_param1`=5000, `event_param2`=11000, `event_param3`=9000, `event_param4`=15000 WHERE `entryorguid`=1159 AND `source_type`=0 AND `id`=2;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1159 AND `source_type`=0 AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1159,0,3,0,4,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"First Mate Snellig - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=1159;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1159,0,0,"Time to join us, $c.",12,0,100,0,0,0,1942,0,"First Mate Snellig"),
(1159,0,1,"Brains...",12,0,100,0,0,0,1940,0,"First Mate Snellig"),
(1159,0,2,"A living $r... soon to be a dead like me.",12,0,100,0,0,0,1941,0,"First Mate Snellig");

-- Mirelow
UPDATE `smart_scripts` SET `event_param1`=6000, `event_param2`=9000, `event_param3`=11000, `event_param4`=17000 WHERE `entryorguid`=14424 AND `source_type`=0 AND `id`=0;

-- Red Wyrmkin
DELETE FROM `smart_scripts` WHERE `entryorguid`=1046 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1046,0,0,0,0,0,100,0,1000,2000,4000,6000,0,11,15242,64,0,0,0,0,2,0,0,0,0,0,0,0,"Red Wyrmkin - In Combat - Cast 'Fireball'"),
(1046,0,1,0,0,0,100,0,8000,16000,21000,26000,0,11,18399,0,0,0,0,0,5,0,0,0,0,0,0,0,"Red Wyrmkin - In Combat - Cast 'Flamestrike'"),
(1046,0,2,0,0,0,100,0,4000,7000,16000,24000,0,11,14145,0,0,0,0,0,5,0,0,0,0,0,0,0,"Red Wyrmkin - In Combat - Cast 'Fire Blast'"),
(1046,0,3,0,0,0,100,0,7000,12000,8000,20000,0,11,15230,0,0,0,0,0,5,0,0,0,0,0,0,0,"Red Wyrmkin - In Combat - Cast 'Arcane Bolt'");

-- Fix bytes2 for some range-attacking creatures
UPDATE `creature_addon` SET `bytes2`=2 WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` IN (2103,6523));
UPDATE `creature_template_addon` SET `bytes2`=2 WHERE `entry` IN (2103,6523);

-- Fix spawn position for one creature
UPDATE `creature` SET `position_z`=40.336 WHERE `guid`=10886;
*/
