/*

-- Winterfall Ursa
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7438;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7438 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7438,0,0,0,1,0,100,0,1000,1000,1200000,1200000,11,17205,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterfall Ursa - Out of Combat - Cast Winterfall Firewater");

-- Winterfall Shaman
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7439;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7439 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7439,0,0,0,0,0,100,0,0,0,3400,4700,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Winterfall Shaman - In Combat - Cast Lightning Bolt"),
(7439,0,1,0,1,0,100,0,1000,1000,1200000,1200000,11,17205,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterfall Shaman - Out of Combat - Cast Winterfall Firewater"),
(7439,0,2,0,1,0,100,0,500,1000,600000,600000,11,13585,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterfall Shaman - Out of Combat - Cast Lightning Shield"),
(7439,0,3,0,16,0,100,0,13585,1,15000,30000,11,13585,1,0,0,0,0,1,0,0,0,0,0,0,0,"Winterfall Shaman - On Friendly Unit Missing Buff Lightning Shield - Cast Lightning Shield"),
(7439,0,4,0,2,0,100,0,0,40,14000,21000,11,11431,1,0,0,0,0,1,0,0,0,0,0,0,0,"Winterfall Shaman - Between 0-40% Health - Cast Healing Touch"),
(7439,0,5,0,14,0,100,0,800,40,15000,18000,11,11431,1,0,0,0,0,7,0,0,0,0,0,0,0,"Winterfall Shaman - Friendly At 800 Health - Cast Healing Touch");

-- Winterfall Den Watcher
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7440;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7440 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7440,0,0,0,1,0,100,0,1000,1000,1200000,1200000,11,17205,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterfall Den Watcher - Out of Combat - Cast Winterfall Firewater");

-- Winterfall Totemic
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7441;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7441 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7441,0,0,0,1,0,100,0,1000,1000,1200000,1200000,11,17205,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterfall Totemic - Out of Combat - Cast Winterfall Firewater"),
(7441,0,1,0,0,0,100,0,6000,9000,45000,50000,11,15786,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterfall Totemic - In Combat - Cast Earthbind Totem"),
(7441,0,2,0,0,0,100,0,6000,9000,22000,25000,11,15787,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterfall Totemic - In Combat - Cast Moonflare Totem");

-- Winterfall Pathfinder
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7442;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7442 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7442,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Winterfall Pathfinder - In Combat - Cast Shoot"),
(7442,0,1,0,1,0,100,0,1000,1000,1200000,1200000,11,17205,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterfall Pathfinder - Out of Combat - Cast Winterfall Firewater"),
(7442,0,2,0,0,0,100,0,6000,8000,22000,25000,11,16498,0,0,0,0,0,2,0,0,0,0,0,0,0,"Winterfall Pathfinder - In Combat - Cast Faerie Fire");

-- High Chief Winterfall
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10738;
DELETE FROM `smart_scripts` WHERE `entryorguid`=10738 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10738,0,0,0,9,0,100,0,0,5,12000,17000,11,15793,0,0,0,0,0,2,0,0,0,0,0,0,0,"High Chief Winterfall - Within 0-5 Range - Cast Maul"),
(10738,0,1,0,9,0,100,0,0,20,15000,25000,11,12548,0,0,0,0,0,2,0,0,0,0,0,0,0,"High Chief Winterfall - Within 0-20 Range - Cast Frost Shock"),
(10738,0,2,0,0,0,100,0,5000,7000,24000,25000,11,8364,0,0,0,0,0,4,0,0,0,0,0,0,0,"High Chief Winterfall - In Combat - Cast Blizzard"),
(10738,0,3,0,1,0,100,0,1000,1000,1200000,1200000,11,17205,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Chief Winterfall - Out of Combat - Cast Winterfall Firewater");

-- Grizzle Snowpaw
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10199;
DELETE FROM `smart_scripts` WHERE `entryorguid`=10199 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10199,0,0,0,9,0,100,0,0,5,12000,17000,11,15793,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grizzle Snowpaw - Within 0-5 Range - Cast Maul"),
(10199,0,1,0,9,0,100,0,0,20,15000,25000,11,12548,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grizzle Snowpaw - Within 0-20 Range - Cast Frost Shock"),
(10199,0,2,0,0,0,100,0,5000,7000,24000,25000,11,8364,0,0,0,0,0,4,0,0,0,0,0,0,0,"Grizzle Snowpaw - In Combat - Cast Blizzard"),
(10199,0,3,0,1,0,100,0,1000,1000,1200000,1200000,11,17205,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grizzle Snowpaw - Out of Combat - Cast Winterfall Firewater");

-- Shardtooth Mauler
DELETE FROM `smart_scripts` WHERE `entryorguid`=7443 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7443,0,0,0,0,0,100,0,4000,6000,8000,10000,11,15793,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shardtooth Mauler - In Combat - Cast Maul");

-- Shardtooth Bear
DELETE FROM `smart_scripts` WHERE `entryorguid`=7444 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7444,0,0,0,0,0,100,0,5000,8000,9000,12000,11,3604,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shardtooth Bear - In Combat - Cast Tendon Rip");

-- Elder Shardtooth
DELETE FROM `smart_scripts` WHERE `entryorguid`=7445 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7445,0,0,0,9,0,100,0,0,5,12000,19000,11,15971,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Shardtooth - Within 0-5 Range - Cast Demoralizing Roar");

-- Rabid Shardtooth
DELETE FROM `smart_scripts` WHERE `entryorguid`=7446 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7446,0,0,0,9,0,100,0,0,5,5000,8000,11,3150,32,0,0,0,0,2,0,0,0,0,0,0,0,"Rabid Shardtooth - Within 0-5 Range - Cast Rabies"),
(7446,0,1,0,0,0,100,0,8000,12000,15000,20000,11,3391,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rabid Shardtooth - In Combat - Cast Thrash");

-- Ursius
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10806;
DELETE FROM `smart_scripts` WHERE `entryorguid`=10806 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10806,0,0,0,9,0,100,0,0,5,12000,17000,11,15793,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ursius - Within 0-5 Range - Cast Maul"),
(10806,0,1,0,0,0,100,0,6000,8000,33000,35000,11,15971,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ursius - In Combat - Cast Demoralizing Roar");

-- Rogue Ice Thistle
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7457;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7457 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7457,0,0,0,9,0,100,0,0,5,3000,6000,11,3604,32,0,0,0,0,2,0,0,0,0,0,0,0,"Rogue Ice Thistle - Within 0-5 Range - Cast Tendon Rip");

-- Ice Thistle Yeti
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7458;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7458 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7458,0,0,0,0,0,100,0,6000,12000,18000,21000,11,15878,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ice Thistle Yeti - In Combat - Cast Ice Blast"),
(7458,0,1,0,0,0,100,0,4000,6000,19000,26000,11,3604,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ice Thistle Yeti - In Combat - Cast Tendon Rip");

-- Ice Thistle Matriarch
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7459;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7459 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7459,0,0,0,0,0,100,0,6000,12000,18000,21000,11,15878,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ice Thistle Matriarch - In Combat - Cast Ice Blast"),
(7459,0,1,0,4,0,100,1,0,0,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ice Thistle Matriarch - On Aggro - Cast Rushing Charge");

-- Ice Thistle Patriarch
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7460;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7460 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7460,0,0,0,0,0,100,0,8000,12000,18000,21000,11,15878,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ice Thistle Patriarch - In Combat - Cast Ice Blast"),
(7460,0,1,0,0,0,100,0,6000,8000,16000,24000,11,3131,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ice Thistle Patriarch - In Combat - Cast Frost Breath");

-- Mezzir the Howler
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10197;
DELETE FROM `smart_scripts` WHERE `entryorguid`=10197 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10197,0,0,0,9,0,100,0,0,5,31000,35000,11,15971,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mezzir the Howler - Within 0-5 Range - Cast Demoralizing Roar"),
(10197,0,1,0,0,0,100,0,7000,10000,14000,18000,11,3131,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mezzir the Howler - In Combat - Cast Frost Breath"),
(10197,0,2,0,2,0,100,0,0,40,18000,24000,11,14100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mezzir the Howler - Between 0-40% Health - Cast Terrifying Roar");

-- Fledgling Chillwind
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7447;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7447 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7447,0,0,0,0,0,100,0,4000,6000,8000,12000,11,16552,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fledgling Chillwind - In Combat - Cast Venom Spit");

-- Chillwind Chimaera
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7448;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7448 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7448,0,0,0,0,0,100,0,6000,8000,14000,18000,11,15797,0,0,0,0,0,2,0,0,0,0,0,0,0,"Chillwind Chimaera - In Combat - Cast Lightning Breath"),
(7448,0,1,0,0,0,100,0,3000,5000,16000,20000,11,15850,0,0,0,0,0,2,0,0,0,0,0,0,0,"Chillwind Chimaera - In Combat - Cast Chilled");

-- Chillwind Ravager
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7449;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7449 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7449,0,0,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chillwind Ravager - Between 0-30% Health - Cast Enrage (No Repeat)");

-- Winterspring Owl
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7455;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7455 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7455,0,0,0,0,0,100,0,7000,9000,12000,16000,11,16576,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterspring Owl - In Combat - Cast Piercing Screech");

-- Winterspring Screecher
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7456;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7456 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7456,0,0,0,9,0,100,0,0,10,13000,16000,11,3589,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterspring Screecher - Within 0-10 Range - Cast Deafening Screech");

-- Suffering Highborne
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7523;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7523 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7523,0,0,0,9,0,100,0,0,30,13000,20000,11,14868,32,0,0,0,0,2,0,0,0,0,0,0,0,"Suffering Highborne - Within 0-30 Range - Cast Curse of Agony");

-- Anguished Highborne
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7524;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7524 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7524,0,0,0,0,0,100,0,0,0,3400,4800,11,13860,64,0,0,0,0,2,0,0,0,0,0,0,0,"Anguished Highborne - In Combat - Cast Mind Blast");

-- Watery Invader
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=14458;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14458 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14458,0,0,0,0,0,100,0,5000,7000,14000,18000,11,15089,0,0,0,0,0,2,0,0,0,0,0,0,0,"Watery Invader - In Combat - Cast Frost Shock"),
(14458,0,1,0,9,0,100,0,0,5,16000,24000,11,15850,2,0,0,0,0,2,0,0,0,0,0,0,0,"Watery Invader - Within 0-5 Range - Cast Chilled");

-- Frostsaber
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7431;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7431 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7431,0,0,0,0,0,100,0,6000,9000,15000,18000,11,24331,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frostsaber - In Combat - Cast Rake");

-- Frostsaber Stalker
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7432;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7432 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7432,0,0,0,25,0,100,1,0,0,0,0,11,30831,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostsaber Stalker - On Reset - Cast Stealth");

-- Frostsaber Huntress
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7433;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7433 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7433,0,0,0,2,0,100,1,0,30,0,0,11,15716,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostsaber Huntress - Between 0-30% Health - Cast Enrage (No Repeat)"),
(7433,0,1,0,0,0,100,0,6000,9000,16000,21000,11,13443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frostsaber Huntress - In Combat - Cast Rend");

-- Frostsaber Pride Watcher
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7434;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7434 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7434,0,0,0,2,0,100,1,0,30,0,0,11,15716,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostsaber Pride Watcher - Between 0-30% Health - Cast Enrage (No Repeat)"),
(7434,0,1,0,0,0,100,0,6000,10000,18000,24000,11,36590,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frostsaber Pride Watcher - In Combat - Cast Rip");

-- Rak'shiri
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10200;
DELETE FROM `smart_scripts` WHERE `entryorguid`=10200 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10200,0,0,0,2,0,100,0,0,60,15000,21000,11,7399,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rak\'shiri - Between 0-60% Health - Cast Terrify"),
(10200,0,1,0,2,0,100,1,0,30,0,0,11,15716,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rak\'shiri - Between 0-30% Health - Cast Enrage");

-- Sian-Rotam
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10741;
DELETE FROM `smart_scripts` WHERE `entryorguid`=10741 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10741,0,0,0,0,0,100,0,8000,11000,12000,18000,11,14100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sian-Rotam - In Combat - Cast Terrifying Roar"),
(10741,0,1,0,9,0,100,0,0,5,15000,20000,11,3604,32,0,0,0,0,2,0,0,0,0,0,0,0,"Sian-Rotam - Within 0-5 Range - Cast Tendon Rip"),
(10741,0,2,0,0,0,100,0,5000,9000,13000,16000,11,13443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sian-Rotam - In Combat - Cast Rend"),
(10741,0,3,0,54,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,100,0,0,0,0,0,0,"Sian-Rotam - Just Summoned - Start Attacking");

-- Shy-Rotam
DELETE FROM `smart_scripts` WHERE `entryorguid`=10737 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10737,0,0,0,0,0,100,0,8000,11000,12000,18000,11,14100,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shy-Rotam - In Combat - Cast Terrifying Roar"),
(10737,0,1,0,0,0,100,0,5000,9000,13000,16000,11,13443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shy-Rotam - In Combat - Cast Rend"),
(10737,0,2,0,9,0,100,0,0,5,15000,20000,11,3604,32,0,0,0,0,2,0,0,0,0,0,0,0,"Shy-Rotam - Within 0-5 Range - Cast Tendon Rip"),
(10737,0,3,0,2,0,100,1,0,50,0,0,12,10741,1,180000,0,0,0,8,0,0,0,8074.84,-3840,690.061,4.6,"Shy-Rotam - Between 0-50% Health - Summon Creature \'Sian-Rotam\'");

-- Ragged Owlbeast
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7450;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7450 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7450,0,0,0,9,0,100,0,0,5,4000,8000,11,15848,32,0,0,0,0,2,0,0,0,0,0,0,0,"Ragged Owlbeast - Within 0-5 Range - Cast Festering Rash");

-- Raging Owlbeast
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7451;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7451 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7451,0,0,0,9,0,100,0,0,5,13000,18000,11,13443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Raging Owlbeast - Within 0-5 Range - Cast Rend");

-- Crazed Owlbeast
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7452;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7452 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7452,0,0,0,2,0,100,1,0,50,0,0,11,15716,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crazed Owlbeast - Between 0-50% Health - Cast Enrage (No Repeat)");

-- Moontouched Owlbeast
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7453;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7453 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7453,0,0,0,2,0,100,0,0,50,18000,21000,11,12160,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moontouched Owlbeast - Between 0-50% Health - Cast Rejuvenation"),
(7453,0,1,0,0,0,100,0,4000,6000,14000,16000,11,15798,0,0,0,0,0,2,0,0,0,0,0,0,0,"Moontouched Owlbeast - In Combat - Cast Moonfire");

-- Berserk Owlbeast
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7454;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7454 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7454,0,0,0,2,0,100,1,0,30,0,0,11,5915,0,0,0,0,0,1,0,0,0,0,0,0,0,"Berserk Owlbeast - Between 0-30% Health - Cast Crazed (No Repeat)");

-- Cobalt Broodling
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10660;
DELETE FROM `smart_scripts` WHERE `entryorguid`=10660 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10660,0,0,0,0,0,100,0,0,0,3400,4800,11,9672,64,0,0,0,0,2,0,0,0,0,0,0,0,"Cobalt Broodling - In Combat - Cast Frostbolt"),
(10660,0,1,0,9,0,100,0,0,10,10000,15000,11,17008,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cobalt Broodling - Within 0-10 Range - Cast Drain Mana"),
(10660,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cobalt Broodling - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Spell Eater
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10661;
DELETE FROM `smart_scripts` WHERE `entryorguid`=10661 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10661,0,0,0,0,0,100,0,6000,8000,14000,20000,11,16340,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spell Eater - In Combat - Cast Frost Breath");

-- Cobalt Whelp
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10659;
DELETE FROM `smart_scripts` WHERE `entryorguid`=10659 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10659,0,0,0,0,0,100,0,4000,6000,12000,16000,11,15089,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cobalt Whelp - In Combat - Cast Frost Shock"),
(10659,0,1,0,0,0,100,0,7000,10000,18000,22000,11,13443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cobalt Whelp - In Combat - Cast Rend");

-- Cobalt Wyrmkin
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7435;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7435 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7435,0,0,0,0,0,100,0,6000,9000,7000,10000,11,15580,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cobalt Wyrmkin - In Combat - Cast Strike"),
(7435,0,1,0,0,0,100,0,4000,6000,14000,18000,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cobalt Wyrmkin - In Combat - Cast Hamstring");

-- Cobalt Scalebane
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7436;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7436 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7436,0,0,0,9,0,100,0,0,5,17000,21000,11,11977,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cobalt Scalebane - Within 0-5 Range - Cast Rend"),
(7436,0,1,0,9,0,100,0,0,5,9000,13000,11,6713,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cobalt Scalebane - Within 0-5 Range - Cast Disarm"),
(7436,0,2,0,13,0,100,1,0,0,0,0,11,15655,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cobalt Scalebane - Target Casting - Cast Shield Slam (No Repeat)");

-- Cobalt Mageweaver
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7437;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7437 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7437,0,0,0,0,0,100,0,0,0,3400,6200,11,15043,64,0,0,0,0,2,0,0,0,0,0,0,0,"Cobalt Mageweaver - In Combat - Cast Frostbolt"),
(7437,0,1,0,1,0,100,0,1000,1000,1800000,1800000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cobalt Mageweaver - Out of Combat - Cast Frost Armor");

-- Spellmaw
DELETE FROM `smart_scripts` WHERE `entryorguid`=10662 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10662,0,0,0,25,0,100,0,0,0,0,0,11,34304,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spellmaw - On Reset - Cast Damage Immunity: Arcane"),
(10662,0,1,0,0,0,100,0,6000,8000,20000,24000,11,16099,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spellmaw - In Combat - Cast Frost Breath"),
(10662,0,2,0,0,0,100,0,8000,10000,18000,21000,11,17012,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spellmaw - In Combat - Cast Devour Magic");

-- General Colbatann
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10196;
DELETE FROM `smart_scripts` WHERE `entryorguid`=10196 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10196,0,0,0,4,0,100,1,0,0,0,0,11,9128,0,0,0,0,0,1,0,0,0,0,0,0,0,"General Colbatann - On Aggro - Cast Battle Shout"),
(10196,0,1,0,0,0,100,0,7000,10000,35000,44000,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,"General Colbatann - In Combat - Cast Demoralizing Shout"),
(10196,0,2,0,9,0,100,0,0,5,15000,19000,11,11971,0,0,0,0,0,2,0,0,0,0,0,0,0,"General Colbatann - Within 0-5 Range - Cast Sunder Armor");

-- Manaclaw
DELETE FROM `smart_scripts` WHERE `entryorguid`=10663 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10663,0,0,0,25,0,100,0,0,0,0,0,11,34304,0,0,0,0,0,1,0,0,0,0,0,0,0,"Manaclaw - On Reset - Cast Damage Immunity: Arcane"),
(10663,0,1,0,0,0,100,0,6000,8000,16000,20000,11,16099,0,0,0,0,0,2,0,0,0,0,0,0,0,"Manaclaw - In Combat - Cast Frost Breath");

-- Scryer
DELETE FROM `smart_scripts` WHERE `entryorguid`=10664 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10664,0,0,0,25,0,100,0,0,0,0,0,11,34304,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scryer - On Reset - Cast Damage Immunity: Arcane"),
(10664,0,1,0,0,0,100,0,6000,8000,20000,24000,11,16099,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scryer - In Combat - Cast Frost Breath"),
(10664,0,2,0,0,0,100,0,3000,6000,15000,20000,11,12738,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scryer - In Combat - Cast Amplify Damage");

-- Azurous
DELETE FROM `smart_scripts` WHERE `entryorguid`=10202 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10202,0,0,0,25,0,100,0,0,0,0,0,11,34304,0,0,0,0,0,1,0,0,0,0,0,0,0,"Manaclaw - On Reset - Cast Damage Immunity: Arcane"),
(10202,0,1,0,0,0,100,0,6000,8000,15000,18000,11,16099,0,0,0,0,0,2,0,0,0,0,0,0,0,"Manaclaw - In Combat - Cast Frost Breath");

-- Brumeran
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10807;
DELETE FROM `smart_scripts` WHERE `entryorguid`=10807 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10807,0,0,0,0,0,100,0,8000,10000,12000,15000,11,15797,0,0,0,0,0,2,0,0,0,0,0,0,0,"Brumeran - In Combat - Cast Lightning Breath"),
(10807,0,1,0,0,0,100,0,3000,6000,12000,15000,11,16552,0,0,0,0,0,2,0,0,0,0,0,0,0,"Brumeran - In Combat - Cast Venom Spit"),
(10807,0,2,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Brumeran - Between 0-30% Health - Cast Enrage (No Repeat)");

-- Frostmaul Giant
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7428;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7428 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7428,0,0,0,0,0,100,0,12000,16000,28000,34000,11,18670,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frostmaul Giant - In Combat - Cast Knock Away"),
(7428,0,1,0,0,0,100,0,4000,6000,14000,18000,11,18368,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frostmaul Giant - In Combat - Cast Strike");

-- Frostmaul Preserver
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7429;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7429 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7429,0,0,0,2,0,100,0,0,40,19000,26000,11,9616,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostmaul Preserver - Between 0-40% Health - Cast Wild Regeneration");

-- Kashoch the Reaver
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10198;
DELETE FROM `smart_scripts` WHERE `entryorguid`=10198 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10198,0,0,0,9,0,100,0,0,5,14000,16000,11,40504,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kashoch the Reaver - Within 0-5 Range - Cast Cleave");

-- Hederine Initiate
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7461;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7461 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7461,0,0,0,0,0,100,0,0,0,3400,4800,11,12739,64,0,0,0,0,2,0,0,0,0,0,0,0,"Hederine Initiate - In Combat - Cast Shadow Bolt");

-- Hederine Slayer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7463;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7463 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7463,0,0,0,0,0,100,0,9000,12000,15000,18000,11,17547,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hederine Slayer - In Combat - Cast Mortal Strike");

-- Lady Hederine
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10201;
DELETE FROM `smart_scripts` WHERE `entryorguid`=10201 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10201,0,0,0,0,0,100,0,5000,7000,18000,24000,11,17146,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lady Hederine - In Combat - Cast Shadow Word: Pain");

-- Random movement for some creatures
UPDATE `creature` SET `spawndist`=8, `MovementType`=1 WHERE `guid`=51891;
UPDATE `creature` SET `spawndist`=15, `MovementType`=1 WHERE `guid`=42304;
*/
