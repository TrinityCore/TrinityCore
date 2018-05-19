DELETE FROM `smart_scripts` WHERE `entryorguid`=1535;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(1535, 0, 0, 0, 4, 0, 30, 1, 0, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Scarlet Warrior - On Aggro - Say Text'),
(1535, 0, 1, 0, 0, 0, 100, 0, 3500, 4500, 13000, 17000, '', 11, 57846, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Scarlet Warrior - Cast Heroic Strike'),
(1535, 0, 2, 0, 2, 0, 100, 1, 0, 15, 0, 0, '', 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Scarlet Warrior - Say Text at 15% HP');

DELETE FROM `smart_scripts` WHERE `entryorguid`=1536;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(1536, 0, 0, 0, 4, 0, 30, 1, 0, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Scarlet Missionary - On Aggro - Say Text'),
(1536, 0, 1, 0, 0, 0, 100, 0, 0, 0, 3400, 4700, '', 11, 9053, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Scarlet Missionary - Cast Fireball'),
(1536, 0, 2, 0, 2, 0, 100, 1, 0, 15, 0, 0, '', 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Scarlet Missionary - Say Text at 15% HP');

DELETE FROM `smart_scripts` WHERE `entryorguid`=1537;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(1537, 0, 0, 0, 4, 0, 30, 1, 0, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Scarlet Zealot - On Aggro - Say Text'),
(1537, 0, 1, 0, 0, 0, 100, 0, 4000, 7000, 12000, 15000, '', 11, 84534, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Scarlet Zealot - Cast Zeal'),
(1537, 0, 2, 0, 0, 0, 100, 0, 11000, 12000, 19000, 25000, '', 11, 84535, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Scarlet Zealot - Cast Zealotry'),
(1537, 0, 3, 0, 2, 0, 100, 1, 0, 15, 0, 0, '', 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Scarlet Zealot - Say Text at 15% HP');

DELETE FROM `smart_scripts` WHERE `entryorguid`=1538;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(1538, 0, 0, 0, 4, 0, 30, 1, 0, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Scarlet Friar - On Aggro - Say Text'),
(1538, 0, 1, 0, 0, 0, 100, 0, 1000, 7000, 8000, 28000, '', 11, 64431, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Scarlet Friar - Cast Death Grip'),
(1538, 0, 2, 0, 0, 0, 100, 0, 6000, 9000, 17000, 20000, '', 11, 75967, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Scarlet Friar - Cast Whirlwind'),
(1538, 0, 3, 0, 2, 0, 100, 1, 0, 15, 0, 0, '', 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Scarlet Friar - Say Text at 15% HP');

DELETE FROM `smart_scripts` WHERE `entryorguid`=1539;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(1539, 0, 0, 0, 4, 0, 30, 1, 0, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Scarlet Neophyte - On Aggro - Say Text'),
(1539, 0, 1, 0, 0, 0, 100, 0, 1000, 4000, 10000, 18000, '', 11, 64431, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Scarlet Neophyte - Cast Death Grip'),
(1539, 0, 2, 0, 0, 0, 100, 0, 5000, 5000, 5000, 5000, '', 11, 13322, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Scarlet Neophyte - Cast Frostbolt'),
(1539, 0, 3, 0, 2, 0, 100, 1, 0, 15, 0, 0, '', 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Scarlet Neophyte - Say Text at 15% HP');

DELETE FROM `smart_scripts` WHERE `entryorguid`=1540;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(1540, 0, 0, 0, 4, 0, 30, 1, 0, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Scarlet Vanguard - On Aggro - Say Text'),
(1540, 0, 1, 0, 4, 0, 100, 1, 0, 0, 0, 0, '', 11, 7164, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Scarlet Vanguard - On Aggro - Cast Defensive Stance'),
(1540, 0, 2, 0, 0, 0, 100, 0, 1000, 4000, 10000, 18000, '', 11, 64431, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Scarlet Vanguard - Cast Death Grip'),
(1540, 0, 3, 0, 0, 0, 100, 0, 2000, 4500, 20000, 30000, '', 11, 11972, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Scarlet Vanguard - On Player Spell Cast - Cast Shield Bash'),
(1540, 0, 4, 0, 2, 0, 100, 1, 0, 15, 0, 0, '', 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Scarlet Vanguard - Say Text at 15% HP');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry`=1521;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1521;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(1521, 0, 0, 0, 19, 0, 100, 0, 24988, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gretchen Dedmar - On Quest 24988 Taken - Say Line 0'),
(1521, 0, 1, 0, 20, 0, 100, 0, 24988, 0, 0, 0, '', 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gretchen Dedmar - On Quest 24988 Finished - Say Line 1'),
(1521, 0, 3, 0, 1, 1, 100, 0, 5000, 5000, 50000, 50000, '', 5, 18, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gretchen Dedmar - Play emote'),
(1521, 0, 4, 0, 63, 0, 100, 0, 0, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gretchen Dedmar - Talk');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry`=11057;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11057;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(11057, 0, 0, 0, 20, 0, 100, 0, 25013, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Apothecary Dithers - On Quest Rewarded - Talk');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry`=38933;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (38933,3893300);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(38933, 0, 0, 0, 73, 0, 100, 0, 0, 0, 0, 0, '', 80, 3893300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Briny Sea Cucumber - On Spell Clic - Add Item'),
(3893300, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, '', 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Briny Sea Cucumber - On Spell Clic - Despawn');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry`=50414;
UPDATE `creature` SET `position_x`='1695.631592', `position_y`='1680.963135', `position_z`='134.870605', `orientation`='2.953877' WHERE  `guid`=193848;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (50414,5041400);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(50414, 0, 0, 0, 25, 0, 100, 1, 0, 0, 0, 0, '', 53, 0, 50414, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Recruit - On Reset - Start Waypoint (No Repeat)'),
(50414, 0, 1, 0, 40, 0, 100, 0, 1, 50414, 0, 0, '', 80, 5041400, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Recruit - On Waypoint 1 Reached - Run Script'),
(5041400, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, '', 5, 16, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Recruit - On Script - Play Emote 16'),
(5041400, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, '', 5, 69, 0, 0, 0, 0, 0, 19, 1568, 10, 0, 0, 0, 0, 0, 'Risen Recruit - On Script - Play Emote 69'),
(5041400, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 19, 1568, 10, 0, 0, 0, 0, 0, 'Risen Recruit - On Script - Say Line 0'),
(5041400, 9, 3, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, '', 5, 26, 0, 0, 0, 0, 0, 19, 1568, 10, 0, 0, 0, 0, 0, 'On Script - Play Emote 26'),
(5041400, 9, 4, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, '', 5, 25, 0, 0, 0, 0, 0, 19, 1568, 10, 0, 0, 0, 0, 0, 'On Script - Play Emote 25'),
(5041400, 9, 5, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, '', 1, 1, 0, 0, 0, 0, 0, 19, 1568, 10, 0, 0, 0, 0, 0, 'On Script - Say Line 1'),
(5041400, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, '', 5, 26, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On Script - Play Emote 26'),
(5041400, 9, 7, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On Script - Say Line 0'),
(5041400, 9, 8, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, '', 5, 66, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On Script - Play Emote 66'),
(5041400, 9, 9, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, '', 53, 0, 504140, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On Script - Start Waypoint'),
(5041400, 9, 10, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, '', 41, 2000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On Script - Despawn In 2000 ms');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry`=47405;
DELETE FROM `smart_scripts` WHERE `entryorguid`=47405;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(47405, 0, 0, 0, 1, 0, 100, 0, 120000, 120000, 120000, 120000, '', 53, 0, 47405, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Chef - Out of Combat - Start Waypoint'),
(47405, 0, 1, 2, 40, 0, 100, 0, 2, 47405, 0, 0, '', 54, 11000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Chef - On Waypoint 2 Reached - Pause Waypoint'),
(47405, 0, 2, 0, 61, 0, 100, 0, 2, 47405, 0, 0, '', 17, 233, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Chef - On Waypoint 2 Reached - Set Emote State 233'),
(47405, 0, 3, 4, 40, 0, 100, 0, 3, 47405, 0, 0, '', 54, 10000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Chef - On Waypoint 3 Reached - Pause Waypoint'),
(47405, 0, 4, 0, 61, 0, 100, 0, 3, 47405, 0, 0, '', 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Chef - On Waypoint 3 Reached - Set Emote State 69'),
(47405, 0, 5, 0, 40, 0, 100, 0, 4, 47405, 0, 0, '', 17, 26, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Chef - On Waypoint 4 Reached - Set Emote State 26');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry`=10665;
DELETE FROM `smart_scripts` WHERE `entryorguid`=10665;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(10665, 0, 0, 0, 1, 0, 100, 0, 60000, 60000, 60000, 60000, '', 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Junior Apothecary Holland - Out of Combat - Say Line 0');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry`=5750;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5750;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(5750, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, '', 11, 11939, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gina Lang - On Reset - Cast Summon Imp');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry`=11194;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11194;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(11194, 0, 0, 0, 0, 0, 100, 0, 1000, 1000, 10000, 10000, '', 11, 12024, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Argent Defender - Cast Net'),
(11194, 0, 1, 0, 0, 0, 100, 0, 5000, 5000, 6000, 6000, '', 11, 6660, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Argent Defender - Cast Shoot');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry`=10666;
DELETE FROM `smart_scripts` WHERE `entryorguid`=10666;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(10666, 0, 0, 0, 0, 0, 100, 0, 1000, 1000, 9000, 9000, '', 11, 59395, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Gordo - Cast Abomination Hook');

DELETE FROM `smart_scripts` WHERE `entryorguid`=1657;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(1657, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Devlin Agamand - On Aggro - Talk'),
(1657, 0, 1, 0, 0, 0, 100, 0, 2000, 4000, 3500, 4500, '', 11, 34447, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Devlin Agamand - Cast Arcane Missiles');

