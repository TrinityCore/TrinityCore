-- Demon Spirit
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11876;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11876 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11876,0,0,0,11,0,100,0,0,0,0,0,11,7741,0,0,0,0,0,1,0,0,0,0,0,0,0,"Demon Spirit - On Respawn - Cast Summoned Demon"),
(11876,0,1,0,11,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,20,0,0,0,0,0,0,"Demon Spirit - On Respawn - Start Attacking");

-- Khan Dez'hepah
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5600;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5600 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5600,0,0,0,4,0,100,0,0,0,0,0,11,7165,0,0,0,0,0,1,0,0,0,0,0,0,0,"Khan Dez'hepah - On Aggro - Cast Battle Stance"),
(5600,0,1,0,0,0,100,0,5000,7000,6000,10000,11,25710,0,0,0,0,0,2,0,0,0,0,0,0,0,"Khan Dez'hepah - In Combat - Cast Heroic Strike"),
(5600,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Khan Dez'hepah - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Khan Hratha
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5402;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5402 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5402,0,0,0,0,0,100,0,1000,5000,12000,18000,11,9128,0,0,0,0,0,1,0,0,0,0,0,0,0,"Khan Hratha - In Combat - Cast Battle Shout"),
(5402,0,1,0,0,0,100,0,5000,7000,7000,11000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Khan Hratha - In Combat - Cast Cleave");

-- Khan Shaka
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5602;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5602 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5602,0,0,0,4,0,100,0,0,0,0,0,11,7165,0,0,0,0,0,1,0,0,0,0,0,0,0,"Khan Shaka - On Aggro - Cast Battle Stance"),
(5602,0,1,0,0,0,100,0,5000,7000,12000,15000,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,"Khan Shaka - In Combat - Cast Hamstring"),
(5602,0,2,0,0,0,100,0,6000,9000,18000,21000,11,11977,0,0,0,0,0,2,0,0,0,0,0,0,0,"Khan Shaka - In Combat - Cast Rend");

-- Kolkar Centaur
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4632;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4632 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4632,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kolkar Centaur - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Kolkar Destroyer
DELETE FROM `smart_scripts` WHERE `entryorguid`=4637 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4637,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kolkar Destroyer - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Kolkar Mauler
DELETE FROM `smart_scripts` WHERE `entryorguid`=4634 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4634,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kolkar Mauler - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Kolkar Scout
DELETE FROM `smart_scripts` WHERE `entryorguid`=4633 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4633,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kolkar Scout - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Kolkar Windchaser
DELETE FROM `smart_scripts` WHERE `entryorguid`=4635 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4635,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kolkar Windchaser - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Kolkar Battle Lord
DELETE FROM `smart_scripts` WHERE `entryorguid`=4636 AND `source_type`=0 AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4636,0,3,0,2,0,100,1,0,20,0,0,39,30,1,0,0,0,0,1,0,0,0,0,0,0,0,"Kolkar Battle Lord - Between 0-20% Health - Call For Help (No Repeat)");

-- Magram Outrunner
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4639;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4639 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4639,0,0,0,2,0,100,1,0,20,0,0,39,30,1,0,0,0,0,1,0,0,0,0,0,0,0,"Magram Outrunner - Between 0-20% Health - Call For Help (No Repeat)");

-- Magram Wrangler
DELETE FROM `smart_scripts` WHERE `entryorguid`=4640 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4640,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magram Wrangler - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Magram Scout
DELETE FROM `smart_scripts` WHERE `entryorguid`=4638 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4638,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magram Scout - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Magram Mauler
DELETE FROM `smart_scripts` WHERE `entryorguid`=4645 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4645,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magram Mauler - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Magram Stormer
DELETE FROM `smart_scripts` WHERE `entryorguid`=4642 AND `source_type`=0 AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4642,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magram Stormer - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Magram Windchaser
DELETE FROM `smart_scripts` WHERE `entryorguid`=4641 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4641,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magram Windchaser - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Magram Marauder
DELETE FROM `smart_scripts` WHERE `entryorguid`=4644 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4644,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magram Marauder - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Gelkis Mauler
DELETE FROM `smart_scripts` WHERE `entryorguid`=4652 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4652,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gelkis Mauler - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Gelkis Earthcaller
DELETE FROM `smart_scripts` WHERE `entryorguid`=4651 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4651,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gelkis Earthcaller - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Gelkis Scout
DELETE FROM `smart_scripts` WHERE `entryorguid`=4647 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4647,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gelkis Scout - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Gelkis Stamper
DELETE FROM `smart_scripts` WHERE `entryorguid`=4648 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4648,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gelkis Stamper - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Gelkis Windchaser
DELETE FROM `smart_scripts` WHERE `entryorguid`=4649 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4649,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gelkis Windchaser - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Gelkis Marauder
DELETE FROM `smart_scripts` WHERE `entryorguid`=4653 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4653,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gelkis Marauder - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Gelkis Outrunner
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4646;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4646 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4646,0,0,0,2,0,100,1,0,20,0,0,39,30,1,0,0,0,0,1,0,0,0,0,0,0,0,"Gelkis Outrunner - Between 0-20% Health - Call For Help (No Repeat)");

-- Slitherblade Naga
DELETE FROM `smart_scripts` WHERE `entryorguid`=4711 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4711,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Slitherblade Naga - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Slitherblade Sorceress
DELETE FROM `smart_scripts` WHERE `entryorguid`=4712 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4712,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Slitherblade Sorceress - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Slitherblade Myrmidon
DELETE FROM `smart_scripts` WHERE `entryorguid`=4714 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4714,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Slitherblade Myrmidon - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Slitherblade Razortail
DELETE FROM `smart_scripts` WHERE `entryorguid`=4715 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4715,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Slitherblade Razortail - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Slitherblade Oracle
DELETE FROM `smart_scripts` WHERE `entryorguid`=4718 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4718,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Slitherblade Oracle - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Slitherblade Sea Witch
DELETE FROM `smart_scripts` WHERE `entryorguid`=4719 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4719,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Slitherblade Sea Witch - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Add equipments to some creatures
DELETE FROM `creature_equip_template` WHERE `CreatureID` IN (4641,4645);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `ItemID2`, `ItemID3`, `VerifiedBuild`) VALUES
(4641,1,5303,0,0,0),
(4645,1,5281,0,0,0);

-- Pathing for Centaur Pariah
UPDATE `creature` SET `position_x`=-2145.71, `position_y`=1966.42, `position_z`=84.4919, `spawndist`=0, `MovementType`=2 WHERE `guid`=29069;

DELETE FROM `creature_addon` WHERE `guid`=29069;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(29069,290690,0,0,1,0,"");

DELETE FROM `waypoint_data` WHERE `id`=290690;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(290690,1,-2145.71,1966.42,84.4919,0,0,0,0,100,0),
(290690,2,-2148.35,1973.16,84.0701,0,0,0,0,100,0),
(290690,3,-2156.93,1972.24,80.9217,0,0,0,0,100,0),
(290690,4,-2158.67,1959.92,78.2252,0,0,0,0,100,0),
(290690,5,-2161.1,1953.68,76.6696,0,0,0,0,100,0),
(290690,6,-2159.54,1948.01,74.4792,0,0,0,0,100,0),
(290690,7,-2166.39,1942.92,69.9358,0,0,0,0,100,0),
(290690,8,-2165.94,1938.13,66.2389,0,0,0,0,100,0),
(290690,9,-2167.71,1935.14,63.539,0,0,0,0,100,0),
(290690,10,-2173.82,1935.16,61.1357,0,0,0,0,100,0),
(290690,11,-2185.89,1953.4,61.0883,0,0,0,0,100,0),
(290690,12,-2181.04,1971.95,63.0648,0,0,0,0,100,0),
(290690,13,-2185.23,1996.62,64.0418,0,0,0,0,100,0),
(290690,14,-2184.85,2019.55,64.0418,0,0,0,0,100,0),
(290690,15,-2182.58,2034.38,64.3299,0,0,0,0,100,0),
(290690,16,-2187.89,2045.21,65.1992,0,0,0,0,100,0),
(290690,17,-2175.83,2065.84,63.6989,0,0,0,0,100,0),
(290690,18,-2165.2,2087.16,64.4523,0,0,0,0,100,0),
(290690,19,-2156.65,2104.11,61.6077,0,0,0,0,100,0),
(290690,20,-2151.67,2118.24,60.7861,0,0,0,0,100,0),
(290690,21,-2148.89,2129.81,63.6364,0,0,0,0,100,0),
(290690,22,-2144.39,2148.28,65.8843,0,0,0,0,100,0),
(290690,23,-2141.23,2166.66,66.9008,0,0,0,0,100,0),
(290690,24,-2139.35,2184.03,66.5107,0,0,0,0,100,0),
(290690,25,-2134.91,2204.03,65.2096,0,0,0,0,100,0),
(290690,26,-2131.41,2219.61,64.1073,0,0,0,0,100,0),
(290690,27,-2128.85,2237.09,64.7163,0,0,0,0,100,0),
(290690,28,-2128.27,2222.75,63.9388,0,0,0,0,100,0),
(290690,29,-2133.74,2204.02,65.2261,0,0,0,0,100,0),
(290690,30,-2137.84,2186.67,66.0619,0,0,0,0,100,0),
(290690,31,-2141.6,2170.8,67.1661,0,0,0,0,100,0),
(290690,32,-2147.93,2144.09,66.0683,0,0,0,0,100,0),
(290690,33,-2152.54,2124.61,62.9209,0,0,0,0,100,0),
(290690,34,-2154.5,2116.3,61.1993,0,0,0,0,100,0),
(290690,35,-2160.27,2091.94,63.4087,0,0,0,0,100,0),
(290690,36,-2171.46,2076.47,64.0607,0,0,0,0,100,0),
(290690,37,-2180,2055.74,63.8618,0,0,0,0,100,0),
(290690,38,-2187.17,2043.48,65.118,0,0,0,0,100,0),
(290690,39,-2182.03,2025.33,64.3237,0,0,0,0,100,0),
(290690,40,-2185.91,2006.41,64.0427,0,0,0,0,100,0),
(290690,41,-2184.03,1990.34,64.0427,0,0,0,0,100,0),
(290690,42,-2182.62,1974.82,63.3536,0,0,0,0,100,0),
(290690,43,-2185.55,1962.21,62.0913,0,0,0,0,100,0),
(290690,44,-2182.01,1945.01,60.5147,0,0,0,0,100,0),
(290690,45,-2174.77,1934.49,61.1065,0,0,0,0,100,0),
(290690,46,-2165.66,1935.02,64.5662,0,0,0,0,100,0),
(290690,47,-2166.1,1945.12,71.6517,0,0,0,0,100,0),
(290690,48,-2159.56,1948.89,74.686,0,0,0,0,100,0),
(290690,49,-2159.53,1958.33,77.9476,0,0,0,0,100,0),
(290690,50,-2156.65,1975.9,81.5158,0,0,0,0,100,0),
(290690,51,-2145.71,1971.54,84.3149,0,0,0,0,100,0),
(290690,52,-2143.66,1964.77,84.0694,0,0,0,0,100,0);
