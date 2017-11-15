/*
-- Gravelsnout Forager
UPDATE `smart_scripts` SET `event_param1`=4000, `event_param2`=9000 WHERE `entryorguid`=4114 AND `source_type`=0 AND `id`=0;

-- Gravelsnout Surveyor
UPDATE `smart_scripts` SET `event_param3`=3400, `event_param4`=4800 WHERE `entryorguid`=4116 AND `source_type`=0 AND `id`=0;

-- Crag Stalker
DELETE FROM `smart_scripts` WHERE `entryorguid`=4126 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4126,0,0,0,25,0,100,0,0,0,0,0,11,30831,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crag Stalker - On Reset - Cast Stealth");

-- Cloud Serpent
UPDATE `smart_scripts` SET `event_param3`=3900, `event_param4`=5300 WHERE `entryorguid`=4117 AND `source_type`=0 AND `id`=0;

-- Elder Cloud Serpent
DELETE FROM `smart_scripts` WHERE `entryorguid`=4119 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4119,0,0,0,0,0,100,0,0,0,3900,5300,11,8246,64,0,0,0,0,2,0,0,0,0,0,0,0,"Elder Cloud Serpent - In Combat CMC - Cast Lightning Bolt"),
(4119,0,1,0,0,0,100,0,4000,8000,7000,11000,11,421,0,0,0,0,0,2,0,0,0,0,0,0,0,"Elder Cloud Serpent - In Combat - Cast Chain Lightning");

-- Pesterhide Snarler
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4249;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4249 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4249,0,0,0,0,0,100,0,7000,10000,16000,22000,11,6576,0,0,0,0,0,2,0,0,0,0,0,0,0,"Pesterhide Snarler - In Combat - Cast Intimidating Growl");

-- Thundering Boulderkin
DELETE FROM `smart_scripts` WHERE `entryorguid`=4120 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4120,0,0,0,0,0,100,0,5000,9000,12000,16000,11,6524,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thundering Boulderkin - In Combat - Cast Ground Tremor");

-- Heartrazor
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5934;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5934 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5934,0,0,0,0,0,100,0,10000,16000,12000,18000,11,8256,32,0,0,0,0,2,0,0,0,0,0,0,0,"Heartrazor - In Combat - Cast Lethal Toxin");

-- Achellios the Banished
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5933;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5933 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5933,0,0,0,4,0,100,0,0,0,0,0,11,9128,0,0,0,0,0,1,0,0,0,0,0,0,0,"Achellios the Banished - On Aggro - Cast Battle Shout");

-- Galak Stormer
UPDATE `smart_scripts` SET `event_param3`=3400, `event_param4`=4800 WHERE `entryorguid`=4097 AND `source_type`=0 AND `id`=0;

-- Galak Mauler
UPDATE `smart_scripts` SET `event_param1`=5000, `event_param2`=8000 WHERE `entryorguid`=4095 AND `source_type`=0 AND `id`=0;

-- Galak Messenger
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10617;
DELETE FROM `smart_scripts` WHERE `entryorguid`=10617 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10617,0,0,0,0,0,100,0,7000,10000,31000,36000,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galak Messenger - In Combat - Cast Demoralizing Shout");

-- Galak Flame Guard
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7404;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7404 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7404,0,0,0,0,0,100,0,6000,9000,24000,27000,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galak Flame Guard - In Combat - Cast Demoralizing Shout");

-- Scalding Elemental
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10756;
DELETE FROM `smart_scripts` WHERE `entryorguid`=10756 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10756,0,0,0,0,0,100,0,6000,14000,16000,24000,11,17276,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scalding Elemental - In Combat - Cast Scald");

-- Boiling Elemental
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10757;
DELETE FROM `smart_scripts` WHERE `entryorguid`=10757 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10757,0,0,0,0,0,100,0,6000,9000,12000,15000,11,11983,0,0,0,0,0,1,0,0,0,0,0,0,0,"Boiling Elemental - In Combat - Cast Steam Jet");

-- Gibblesnik
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=14427;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14427 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14427,0,0,0,0,0,100,0,5000,8000,10000,16000,11,11971,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gibblesnik - In Combat - Cast Sunder Armor");

-- Saltstone Basilisk
DELETE FROM `smart_scripts` WHERE `entryorguid`=4147 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4147,0,0,0,0,0,100,0,7000,11000,21000,29000,11,3636,0,0,0,0,0,5,0,0,0,0,0,0,0,"Saltstone Basilisk - In Combat - Cast Crystalline Slumber");

-- Saltstone Gazer
DELETE FROM `smart_scripts` WHERE `entryorguid`=4150 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4150,0,0,0,0,0,100,0,9000,14000,13000,16000,11,3635,0,0,0,0,0,2,0,0,0,0,0,0,0,"Saltstone Gazer - In Combat - Cast Crystal Gaze");

-- Saltstone Gazer
DELETE FROM `smart_scripts` WHERE `entryorguid`=4151 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4151,0,0,0,0,0,100,0,6000,12000,15000,18000,11,8129,0,0,0,0,0,5,0,0,0,0,0,0,0,"Saltstone Crystalhide - In Combat - Cast Mana Burn");

-- Sparkleshell Snapper
DELETE FROM `smart_scripts` WHERE `entryorguid`=4143 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4143,0,1,0,0,0,100,0,5000,9000,11000,15000,11,6730,0,0,0,0,0,5,0,0,0,0,0,0,0,"Sparkleshell Snapper - In Combat - Cast Head Butt");

-- Sparkleshell Borer
UPDATE `smart_scripts` SET `event_param2`=9000 WHERE `entryorguid`=4144 AND `source_type`=0 AND `id`=1;

-- Salt Flats Scavenger
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4154;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4154 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4154,0,0,0,12,0,100,1,0,20,0,0,11,7160,0,0,0,0,0,2,0,0,0,0,0,0,0,"Salt Flats Scavenger - Target Between 0-20% Health - Cast 'Execute' (No Repeat)");

-- Salt Flats Vulture
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4158;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4158 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4158,0,0,0,12,0,100,1,0,50,0,0,11,7160,0,0,0,0,0,2,0,0,0,0,0,0,0,"Salt Flats Vulture - Target Between 0-50% Health - Cast 'Execute' (No Repeat)");

-- Vile Sting
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5937;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5937 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5937,0,0,0,0,0,100,0,8000,12000,22000,26000,11,8257,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vile Sting - In Combat - Cast Venom Sting");

-- Ironeye the Invincible
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5935;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5935 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5935,0,0,0,0,0,100,0,8000,12000,24000,28000,11,11020,0,0,0,0,0,5,0,0,0,0,0,0,0,"Ironeye the Invincible - In Combat - Cast Petrify");

-- Silithid Invader
DELETE FROM `smart_scripts` WHERE `entryorguid`=4131 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4131,0,0,0,0,0,100,0,4000,7000,22000,25000,11,6016,0,0,0,0,0,2,0,0,0,0,0,0,0,"Silithid Invader - In Combat - Cast Pierce Armor"),
(4131,0,1,0,0,0,100,1,10000,16000,0,0,11,8137,0,0,0,0,0,2,0,0,0,0,0,0,0,"Silithid Invader - In Combat - Cast Silithid Pox (No Repeat)");

-- Silithid Hive Drone
DELETE FROM `smart_scripts` WHERE `entryorguid`=4133 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4133,0,0,0,2,0,100,1,0,20,0,0,39,30,1,0,0,0,0,1,0,0,0,0,0,0,0,"Silithid Hive Drone - Between 0-20% Health - Call For Help (No Repeat)");

-- Grimtotem Stomper
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10759;
DELETE FROM `smart_scripts` WHERE `entryorguid`=10759 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10759,0,0,0,0,0,100,0,5000,8000,12000,16000,11,8046,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grimtotem Stomper - In Combat - Cast Earth Shock"),
(10759,0,1,0,0,0,100,0,9000,12000,30000,35000,11,5605,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Stomper - In Combat - Cast Healing Ward");

-- Grimtotem Geomancer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10760;
DELETE FROM `smart_scripts` WHERE `entryorguid`=10760 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10760,0,0,0,0,0,100,0,0,0,3400,4800,11,20811,64,0,0,0,0,2,0,0,0,0,0,0,0,"Grimtotem Geomancer - In Combat - Cast Fireball"),
(10760,0,1,0,0,0,100,0,8000,12000,10000,14000,11,20794,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grimtotem Geomancer - In Combat - Cast Flamestrike"),
(10760,0,2,0,0,0,100,0,4000,9000,18000,25000,11,11436,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grimtotem Geomancer - In Combat - Cast Slow"),
(10760,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Geomancer - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Grimtotem Bandit
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10758;
DELETE FROM `smart_scripts` WHERE `entryorguid`=10758 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10758,0,0,0,0,0,100,0,6000,9000,15000,18000,11,6713,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grimtotem Bandit - In Combat - Cast Disarm"),
(10758,0,1,0,13,0,100,0,19000,24000,0,0,11,34802,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grimtotem Bandit - Target Casting - Cast Kick");

-- Harb Foulmountain
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=14426;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14426 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14426,0,0,0,0,0,100,0,6000,11000,18000,23000,11,45,0,0,0,0,0,1,0,0,0,0,0,0,0,"Harb Foulmountain - In Combat - Cast War Stomp"),
(14426,0,1,0,0,0,100,0,5000,7000,5000,7000,11,3391,0,0,0,0,0,2,0,0,0,0,0,0,0,"Harb Foulmountain - In Combat - Cast Thrash");

-- Grimtotem Reaver
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10761;
DELETE FROM `smart_scripts` WHERE `entryorguid`=10761 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10761,0,0,0,0,0,100,0,5000,7000,8000,12000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grimtotem Reaver - In Combat - Cast Strike"),
(10761,0,1,0,0,0,100,0,7000,9000,10000,14000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grimtotem Reaver - In Combat - Cast Cleave");

-- Grimtotem Reaver
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10896;
DELETE FROM `smart_scripts` WHERE `entryorguid`=10896 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10896,0,0,0,0,0,100,0,5000,7000,9000,13000,11,10966,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grimtotem Reaver - In Combat - Cast Uppercut"),
(10896,0,1,0,0,0,100,0,6000,8000,17000,21000,11,11977,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grimtotem Reaver - In Combat - Cast Rend");

-- Random movement for some creatures
UPDATE `creature` SET `spawndist`=5, `MovementType`=1 WHERE `guid` IN (51822, 21302);
UPDATE `creature` SET `spawndist`=15, `MovementType`=1 WHERE `guid` IN (51823, 51824, 21546);
*/
