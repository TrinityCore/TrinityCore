-- Varo'then's Ghost
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6118;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6118 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6118,0,0,0,0,0,100,0,3000,6000,22000,25000,11,21007,0,0,0,0,0,2,0,0,0,0,0,0,0,"Varo'then's Ghost - In Combat - Cast Curse of Weakness");

-- Highborne Apparition
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6116;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6116 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6116,0,0,0,2,0,100,1,0,15,0,0,11,12542,0,0,0,0,0,2,0,0,0,0,0,0,0,"Highborne Apparition - Between 0-15% Health - Cast Fear (No Repeat)");

-- Highborne Lichling
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6117;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6117 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6117,0,0,0,1,0,100,0,1000,1000,1800000,1800000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Highborne Lichling - Out of Combat - Cast Frost Armor"),
(6117,0,1,0,0,0,100,0,0,0,3400,4800,11,20822,64,0,0,0,0,2,0,0,0,0,0,0,0,"Highborne Lichling - In Combat CMC - Cast Frostbolt");

-- Lingering Highborne
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7864;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7864 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7864,0,0,0,0,0,100,0,3000,5000,14000,18000,11,11963,32,0,0,0,0,2,0,0,0,0,0,0,0,"Lingering Highborne - In Combat - Cast Enfeeble");

-- The Evalcharr
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8660;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8660 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8660,0,0,0,0,0,100,0,0,0,6000,9000,11,21549,0,0,0,0,0,2,0,0,0,0,0,0,0,"The Evalcharr - In Combat - Cast Fireball"),
(8660,0,1,0,0,0,100,0,8000,10000,11000,14000,11,15797,0,0,0,0,0,2,0,0,0,0,0,0,0,"The Evalcharr - In Combat - Cast Lightning Breath");

-- Thunderhead Hippogryph
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6375;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6375 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6375,0,0,0,9,0,100,0,0,20,8000,12000,11,12553,0,0,0,0,0,2,0,0,0,0,0,0,0,"Thunderhead Hippogryph - Within 0-20 Range - Cast Shock");

-- Thunderhead Stagwing
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6377;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6377 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6377,0,0,0,9,0,100,0,0,20,8000,12000,11,12553,0,0,0,0,0,2,0,0,0,0,0,0,0,"Thunderhead Stagwing - Within 0-20 Range - Cast Shock"),
(6377,0,1,0,0,0,100,0,7000,10000,12000,17000,11,11019,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thunderhead Stagwing - In Combat - Cast Wing Flap");

-- Thunderhead Skystormer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6378;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6378 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6378,0,0,0,9,0,100,0,0,20,8000,12000,11,12553,0,0,0,0,0,2,0,0,0,0,0,0,0,"Thunderhead Skystormer - Within 0-20 Range - Cast Shock"),
(6378,0,1,0,0,0,100,0,9000,16000,40000,45000,11,6535,0,0,0,0,0,5,0,0,0,0,0,0,0,"Thunderhead Skystormer - In Combat - Cast Lightning Cloud");

-- Thunderhead Patriarch
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6379;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6379 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6379,0,0,0,0,0,100,0,5000,9000,8000,12000,11,12553,0,0,0,0,0,2,0,0,0,0,0,0,0,"Thunderhead Patriarch - In Combat - Cast Shock"),
(6379,0,1,0,4,0,100,0,0,0,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thunderhead Patriarch - On Aggro - Cast Rushing Charge");

-- Thunderhead Consort
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6380;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6380 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6380,0,0,0,9,0,100,0,0,20,8000,12000,11,12553,0,0,0,0,0,2,0,0,0,0,0,0,0,"Thunderhead Consort - Within 0-20 Range - Cast Shock"),
(6380,0,1,0,0,0,100,0,5000,9000,9000,13000,11,36594,0,0,0,0,0,2,0,0,0,0,0,0,0,"Thunderhead Consort - In Combat - Cast Lightning Breath");

-- Antilos
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6648;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6648 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6648,0,0,0,9,0,100,0,0,5,11000,15000,11,40504,0,0,0,0,0,2,0,0,0,0,0,0,0,"Antilos - Within 0-5 Range - Cast Cleave"),
(6648,0,1,0,0,0,100,0,7000,10000,13000,20000,11,13445,0,0,0,0,0,5,0,0,0,0,0,0,0,"Antilos - In Combat - Cast Rend"),
(6648,0,2,0,0,0,100,0,11000,15000,12000,16000,11,5708,0,0,0,0,0,5,0,0,0,0,0,0,0,"Antilos - In Combat - Cast Swoop");

-- Mistwing Rogue
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8763;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8763 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8763,0,0,0,0,0,100,0,0,0,6000,10000,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mistwing Rogue - In Combat - Cast Lightning Bolt");

-- Mistwing Ravager
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8764;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8764 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8764,0,0,0,0,0,100,0,4000,7000,11000,16000,11,21067,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mistwing Ravager - In Combat - Cast Poisoned Bolt");

-- Haldarr Trickster
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6126;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6126 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6126,0,0,0,9,0,100,0,0,10,20000,35000,11,7098,32,0,0,0,0,2,0,0,0,0,0,0,0,"Haldarr Trickster - Within 0-10 Range - Cast Curse of Mending");

-- Haldarr Felsworn
DELETE FROM `smart_scripts` WHERE `entryorguid`=6127 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6127,0,1,0,0,0,100,0,0,0,3400,4800,11,20825,64,0,0,0,0,2,0,0,0,0,0,0,0,"Haldarr Felsworn - In Combat - Cast Shadow Bolt");

-- Warlord Krellian
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8408;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8408 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8408,0,0,0,0,0,100,0,5000,7000,6000,9000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Warlord Krellian - In Combat - Cast Strike"),
(8408,0,1,0,0,0,100,0,7000,10000,12000,17000,11,10968,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warlord Krellian - In Combat - Cast Demoralizing Roar");

-- General Fangferror
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6650;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6650 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6650,0,0,0,0,0,100,0,5000,7000,6000,9000,11,12057,0,0,0,0,0,2,0,0,0,0,0,0,0,"General Fangferror - In Combat - Cast Strike"),
(6650,0,1,0,0,0,100,0,7000,11000,12000,15000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,"General Fangferror - In Combat - Cast Cleave"),
(6650,0,2,0,9,0,100,0,0,5,9000,18000,11,18812,0,0,0,0,0,2,0,0,0,0,0,0,0,"General Fangferror - Within 0-5 Range - Cast Knockdown");

-- Lady Sesspira
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6649;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6649 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6649,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Lady Sesspira - In Combat - Cast Shoot"),
(6649,0,1,0,0,0,100,0,4000,6000,8000,12000,11,15495,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lady Sesspira - In Combat - Cast Explosive Shot"),
(6649,0,2,0,0,0,100,0,11000,15000,9000,16000,11,20299,0,0,0,0,0,5,0,0,0,0,0,0,0,"Lady Sesspira - In Combat - Cast Forked Lightning"),
(6649,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Sesspira - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Timberweb Recluse
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8762;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8762 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8762,0,0,0,9,0,100,0,0,30,9000,14000,11,745,0,0,0,0,0,2,0,0,0,0,0,0,0,"Timberweb Recluse - Within 0-30 Range - Cast Web");

-- Cliff Thunderer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6147;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6147 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6147,0,0,0,0,0,100,0,7000,10000,11000,14000,11,8147,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cliff Thunderer - In Combat - Cast Thunderclap");

-- Cliff Walker
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6148;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6148 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6148,0,0,0,0,0,100,0,7000,10000,13000,17000,11,11876,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cliff Walker - In Combat - Cast War Stomp");

-- Monnos the Elder
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6646;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6646 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6646,0,0,0,0,0,100,0,10000,12000,14000,18000,11,10101,0,0,0,0,0,2,0,0,0,0,0,0,0,"Monnos the Elder - In Combat - Cast Knock Away"),
(6646,0,1,0,0,0,100,0,7000,9000,9000,13000,11,5568,0,0,0,0,0,1,0,0,0,0,0,0,0,"Monnos the Elder - In Combat - Cast Trample"),
(6646,0,2,0,0,0,100,0,14000,17000,15000,21000,11,11876,0,0,0,0,0,1,0,0,0,0,0,0,0,"Monnos the Elder - In Combat - Cast War Stomp");

-- Timbermaw Pathfinder
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6184;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6184 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6184,0,0,0,0,0,100,0,5000,8000,22000,25000,11,16498,0,0,0,0,0,2,0,0,0,0,0,0,0,"Timbermaw Pathfinder - In Combat - Cast Faerie Fire"),
(6184,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Timbermaw Pathfinder - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Timbermaw Warrior
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6185;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6185 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6185,0,0,0,0,0,100,0,5000,7000,6000,9000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Timbermaw Warrior - In Combat - Cast Strike"),
(6185,0,1,0,0,0,100,0,8000,11000,19000,23000,11,11977,0,0,0,0,0,2,0,0,0,0,0,0,0,"Timbermaw Warrior - In Combat - Cast Rend"),
(6185,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Timbermaw Warrior - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Timbermaw Totemic
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6186;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6186 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6186,0,0,0,0,0,100,0,5000,8000,32000,36000,11,8262,0,0,0,0,0,2,0,0,0,0,0,0,0,"Timbermaw Totemic - In Combat - Cast Elemental Protection Totem"),
(6186,0,1,0,2,0,100,0,0,50,30000,34000,11,5605,0,0,0,0,0,2,0,0,0,0,0,0,0,"Timbermaw Totemic - Between 0-50% Health - Cast Healing Ward"),
(6186,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Timbermaw Totemic - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Timbermaw Den Watcher
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6187;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6187 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6187,0,0,0,0,0,100,0,2000,5000,13000,18000,11,9128,0,0,0,0,0,1,0,0,0,0,0,0,0,"Timbermaw Den Watcher - In Combat - Cast Battle Shout"),
(6187,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Timbermaw Den Watcher - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Timbermaw Shaman
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6188;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6188 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6188,0,0,0,0,0,100,0,0,0,3400,4800,11,20295,64,0,0,0,0,2,0,0,0,0,0,0,0,"Timbermaw Shaman - In Combat - Cast Lightning Bolt"),
(6188,0,1,0,0,0,100,0,8000,14000,40000,45000,11,6535,0,0,0,0,0,5,0,0,0,0,0,0,0,"Timbermaw Shaman - In Combat - Cast Lightning Cloud"),
(6188,0,2,0,14,0,100,0,1000,40,15000,18000,11,11986,0,0,0,0,0,7,0,0,0,0,0,0,0,"Timbermaw Shaman - Friendly At 1000 Health - Cast Healing Wave"),
(6188,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Timbermaw Shaman - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Timbermaw Ursa
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6189;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6189 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6189,0,0,0,0,0,100,0,9000,12000,16000,21000,11,8078,0,0,0,0,0,1,0,0,0,0,0,0,0,"Timbermaw Ursa - In Combat - Cast Thunderclap"),
(6189,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Timbermaw Ursa - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Gatekeeper Rageroar
UPDATE `creature_template` SET `AIName`="SmartAI", `faction`=414 WHERE `entry`=6651;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6651 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6651,0,0,0,0,0,100,0,5000,7000,6000,9000,11,13584,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gatekeeper Rageroar - In Combat - Cast Strike"),
(6651,0,1,0,0,0,100,0,4000,6000,14000,18000,11,12747,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gatekeeper Rageroar - In Combat - Cast Entangling Roots");

-- Blood Elf Surveyor
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6198;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6198 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6198,0,0,0,0,0,100,0,6000,9000,10000,16000,11,11969,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blood Elf Surveyor - In Combat - Cast Fire Nova"),
(6198,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blood Elf Surveyor - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Blood Elf Reclaimer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6199;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6199 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6199,0,0,0,0,0,100,0,0,0,3400,4800,11,20823,64,0,0,0,0,2,0,0,0,0,0,0,0,"Blood Elf Reclaimer - In Combat - Cast Fireball"),
(6199,0,1,0,2,0,100,0,0,50,15000,21000,11,11642,1,0,0,0,0,1,0,0,0,0,0,0,0,"Blood Elf Reclaimer - Between 0-50% Health - Cast Heal"),
(6199,0,2,0,14,0,100,0,1200,40,12000,17000,11,11640,0,0,0,0,0,7,0,0,0,0,0,0,0,"Blood Elf Reclaimer - Friendly At 1200 Health - Cast Renew"),
(6199,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blood Elf Reclaimer - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Magister Hawkhelm
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6647;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6647 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6647,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Magister Hawkhelm - In Combat - Cast Shoot"),
(6647,0,1,0,0,0,100,0,4000,6000,9000,13000,11,18651,0,0,0,0,0,2,0,0,0,0,0,0,0,"Magister Hawkhelm - In Combat - Cast Multi-Shot"),
(6647,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magister Hawkhelm - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Legashi Satyr
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6200;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6200 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6200,0,0,0,0,0,100,0,5000,8000,9000,14000,11,11981,0,0,0,0,0,2,0,0,0,0,0,0,0,"Legashi Satyr - In Combat - Cast Mana Burn");

-- Legashi Rogue
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6201;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6201 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6201,0,0,0,67,0,100,0,5000,8000,0,0,11,7159,0,0,0,0,0,2,0,0,0,0,0,0,0,"Legashi Rogue - On Behind Target - Cast Backstab"),
(6201,0,1,0,0,0,100,0,5000,7000,9000,12000,11,12540,0,0,0,0,0,2,0,0,0,0,0,0,0,"Legashi Rogue - In Combat - Cast Gouge");

-- Legashi Hellcaller
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6202;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6202 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6202,0,0,0,0,0,100,0,0,0,3400,4800,11,20823,64,0,0,0,0,2,0,0,0,0,0,0,0,"Legashi Hellcaller - In Combat - Cast Fireball"),
(6202,0,1,0,0,0,100,0,8000,13000,18000,25000,11,11990,0,0,0,0,0,2,0,0,0,0,0,0,0,"Legashi Hellcaller - In Combat - Cast Rain of Fire");

-- Master Feardred
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6652;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6652 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6652,0,0,0,0,0,100,0,6000,8000,9000,14000,11,21073,0,0,0,0,0,1,0,0,0,0,0,0,0,"Master Feardred - In Combat - Cast Arcane Explosion");

-- Forest Ooze
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8766;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8766 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8766,0,0,0,0,0,100,0,6000,8000,12000,16000,11,6907,32,0,0,0,0,2,0,0,0,0,0,0,0,"Forest Ooze - In Combat - Cast Diseased Slime");

-- Makrinni Razorclaw
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6350;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6350 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6350,0,0,0,0,0,100,0,6000,9000,7000,11000,11,13444,0,0,0,0,0,2,0,0,0,0,0,0,0,"Makrinni Razorclaw - In Combat - Cast Sunder Armor");

-- Makrinni Scrabbler
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6370;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6370 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6370,0,0,0,0,0,100,0,5000,7000,9000,12000,11,12548,0,0,0,0,0,2,0,0,0,0,0,0,0,"Makrinni Scrabbler - In Combat - Cast Frost Shock");

-- Makrinni Snapclaw
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6372;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6372 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6372,0,0,0,0,0,100,0,3000,5000,18000,22000,11,3604,0,0,0,0,0,2,0,0,0,0,0,0,0,"Makrinni Snapclaw - In Combat - Cast Tendon Rip");

-- Young Wavethrasher
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6347;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6347 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6347,0,0,0,25,0,100,0,0,0,0,0,11,3417,0,0,0,0,0,1,0,0,0,0,0,0,0,"Young Wavethrasher - On Reset - Cast Thrash");

-- Wavethrasher
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6348;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6348 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6348,0,0,0,25,0,100,0,0,0,0,0,11,3417,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wavethrasher - On Reset - Cast Thrash");

-- Great Wavethrasher
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6349;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6349 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6349,0,0,0,25,0,100,0,0,0,0,0,11,3417,0,0,0,0,0,1,0,0,0,0,0,0,0,"Great Wavethrasher - On Reset - Cast Thrash");

-- Storm Bay Warrior
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6371;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6371 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6371,0,0,0,0,0,100,0,5000,7000,6000,9000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Storm Bay Warrior - In Combat - Cast Strike"),
(6371,0,1,0,0,0,100,0,9000,11000,12000,15000,11,12555,0,0,0,0,0,2,0,0,0,0,0,0,0,"Storm Bay Warrior - In Combat - Cast Pummel"),
(6371,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Storm Bay Warrior - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Storm Bay Oracle
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6351;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6351 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6351,0,0,0,0,0,100,0,0,0,3400,4800,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Storm Bay Oracle - In Combat - Cast Lightning Bolt"),
(6351,0,1,0,14,0,100,0,1400,40,15000,18000,11,11642,0,0,0,0,0,7,0,0,0,0,0,0,0,"Storm Bay Oracle - Friendly At 1400 Health - Cast Heal"),
(6351,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Storm Bay Oracle - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Arkkoran Pincer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6137;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6137 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6137,0,0,0,0,0,100,0,5000,8000,17000,22000,11,13443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Arkkoran Pincer - In Combat - Cast Rend");

-- Arkkoran Oracle
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6138;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6138 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6138,0,0,0,0,0,100,0,4000,7000,6000,9000,11,11824,0,0,0,0,0,2,0,0,0,0,0,0,0,"Arkkoran Oracle - In Combat - Cast Shock"),
(6138,0,1,0,14,0,100,0,1500,40,16000,21000,11,11986,0,0,0,0,0,7,0,0,0,0,0,0,0,"Arkkoran Oracle - Friendly At 1500 Health - Cast Healing Wave"),
(6138,0,2,0,1,0,100,0,500,1000,600000,600000,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arkkoran Oracle - Out of Combat - Cast Lightning Shield"),
(6138,0,3,0,16,0,100,0,12550,1,15000,30000,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arkkoran Oracle - On Friendly Unit Missing Buff Lightning Shield - Cast Lightning Shield");

-- Servant of Arkkoroc
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6143;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6143 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6143,0,0,0,0,0,100,0,5000,7000,9000,13000,11,5568,0,0,0,0,0,1,0,0,0,0,0,0,0,"Servant of Arkkoroc - In Combat - Cast Trample");

-- Son of Arkkoroc
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6144;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6144 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6144,0,0,0,0,0,100,0,8000,10000,12000,16000,11,10101,0,0,0,0,0,2,0,0,0,0,0,0,0,"Son of Arkkoroc - In Combat - Cast Knock Away");

-- Scalebeard
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=13896;
DELETE FROM `smart_scripts` WHERE `entryorguid`=13896 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(13896,0,0,0,12,0,100,0,0,20,10000,14000,11,7938,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scalebeard - Target Between 0-20% Health - Cast Fatal Bite");

-- Draconic Magelord
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6129;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6129 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6129,0,0,0,0,0,100,0,0,0,3400,4800,11,9672,64,0,0,0,0,2,0,0,0,0,0,0,0,"Draconic Magelord - In Combat - Cast Frostbolt"),
(6129,0,1,0,9,0,100,0,0,20,7000,11000,11,12548,0,0,0,0,0,2,0,0,0,0,0,0,0,"Draconic Magelord - Within 0-20 Range - Cast Frost Shock");

-- Draconic Mageweaver
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6131;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6131 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6131,0,0,0,0,0,100,0,0,0,3400,4800,11,9672,64,0,0,0,0,2,0,0,0,0,0,0,0,"Draconic Mageweaver - In Combat - Cast Frostbolt"),
(6131,0,1,0,0,0,100,0,9000,12000,15000,18000,11,12557,0,0,0,0,0,2,0,0,0,0,0,0,0,"Draconic Mageweaver - In Combat - Cast Cone of Cold");

-- Random movement for Antilos
UPDATE `creature` SET `MovementType`=1, `spawndist`=8 WHERE `guid`=51851;
