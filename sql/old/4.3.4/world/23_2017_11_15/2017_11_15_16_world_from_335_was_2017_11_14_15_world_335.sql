/*
-- 
-- Longtooth Runner
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5286;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5286 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5286,0,0,1,1,0,100,0,30000,600000,120000,600000,4,1018,0,1,0,0,0,1,0,0,0,0,0,0,0,"Longtooth Runner - Out of Combat - Play Sound 1018"),
(5286,0,1,0,61,0,100,0,0,0,0,0,5,393,0,0,0,0,0,1,0,0,0,0,0,0,0,"Longtooth Runner - Out of Combat - Play Emote 393"),
(5286,0,2,0,0,0,100,0,4000,7000,17000,20000,11,3149,2,0,0,0,0,1,0,0,0,0,0,0,0,"Longtooth Runner - In Combat - Cast Furious Howl");

-- Longtooth Howler
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5287;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5287 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5287,0,0,1,1,0,100,0,30000,600000,120000,600000,4,1018,0,1,0,0,0,1,0,0,0,0,0,0,0,"Longtooth Howler - Out of Combat - Play Sound 1018"),
(5287,0,1,0,61,0,100,0,0,0,0,0,5,393,0,0,0,0,0,1,0,0,0,0,0,0,0,"Longtooth Howler - Out of Combat - Play Emote 393"),
(5287,0,2,1,2,0,100,1,0,20,0,0,39,30,1,0,0,0,0,1,0,0,0,0,0,0,0,"Longtooth Howler - Between 0-20% Health - Call For Help (No Repeat)");

-- Longtooth Runner
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5288;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5288 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5288,0,0,1,1,0,100,0,30000,600000,120000,600000,4,1018,0,1,0,0,0,1,0,0,0,0,0,0,0,"Longtooth Runner - Out of Combat - Play Sound 1018"),
(5288,0,1,0,61,0,100,0,0,0,0,0,5,393,0,0,0,0,0,1,0,0,0,0,0,0,0,"Longtooth Runner - Out of Combat - Play Emote 393"),
(5288,0,2,0,0,0,100,0,5000,9000,30000,35000,11,3150,0,0,0,0,0,2,0,0,0,0,0,0,0,"Longtooth Runner - In Combat - Cast Rabies");

-- Snarler
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5356;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5356 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5356,0,0,0,0,0,100,0,7000,11000,9000,15000,11,5543,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snarler - In Combat - Cast Fade Out");

-- Sprite Dragon
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5276;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5276 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5276,0,0,0,0,0,100,0,3000,5000,9000,15000,11,17630,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sprite Dragon - In Combat - Cast Mana Burn");

-- Sprite Darter
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5278;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5278 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5278,0,0,0,0,0,100,0,3000,5000,9000,15000,11,17630,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sprite Darter - In Combat - Cast Mana Burn");

-- Ironfur Patriarch
DELETE FROM `smart_scripts` WHERE `entryorguid`=5274 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5274,0,0,0,0,0,100,0,6000,9000,12000,21000,11,10968,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ironfur Patriarch - In Combat - Cast Demoralizing Roar");

-- Northspring Harpy
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5362;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5362 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5362,0,0,0,14,0,100,0,1000,40,15000,20000,11,11014,0,0,0,0,0,7,0,0,0,0,0,0,0,"Northspring Harpy - Friendly At 1000 Health - Cast Flow of the Northspring"),
(5362,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Northspring Harpy - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Northspring Roguefeather
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5363;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5363 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5363,0,0,0,25,0,100,0,0,0,0,0,11,8876,0,0,0,0,0,1,0,0,0,0,0,0,0,"Northspring Roguefeather - On Reset - Cast Thrash"),
(5363,0,1,0,0,0,100,0,5000,7000,10000,13000,11,6595,0,0,0,0,0,2,0,0,0,0,0,0,0,"Northspring Roguefeather - In Combat - Cast Exploit Weakness"),
(5363,0,2,0,14,0,100,0,1000,40,15000,20000,11,11014,0,0,0,0,0,7,0,0,0,0,0,0,0,"Northspring Roguefeather - Friendly At 1000 Health - Cast Flow of the Northspring"),
(5363,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Northspring Roguefeather - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Northspring Slayer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5364;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5364 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5364,0,0,0,12,0,100,1,0,20,0,0,11,7160,0,0,0,0,0,2,0,0,0,0,0,0,0,"Northspring Slayer - Target Between 0-20% Health - Cast 'Execute' (No Repeat)"),
(5364,0,1,0,14,0,100,0,1000,40,15000,20000,11,11014,0,0,0,0,0,7,0,0,0,0,0,0,0,"Northspring Slayer - Friendly At 1000 Health - Cast Flow of the Northspring"),
(5364,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Northspring Slayer - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Northspring Windcaller
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5366;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5366 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5366,0,0,0,0,0,100,0,0,0,3400,4800,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Northspring Windcaller - In Combat - Cast Lightning Bolt"),
(5366,0,1,0,0,0,100,0,8000,11000,17000,21000,11,6728,0,0,0,0,0,5,0,0,0,0,0,0,0,"Northspring Windcaller - In Combat - Cast Enveloping Winds"),
(5366,0,2,0,14,0,100,0,1000,40,15000,20000,11,11014,0,0,0,0,0,7,0,0,0,0,0,0,0,"Northspring Windcaller - Friendly At 1000 Health - Cast Flow of the Northspring"),
(5366,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Northspring Windcaller - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Lethlas
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5312;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5312 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5312,0,0,0,0,0,100,0,6000,9000,6000,9000,11,20667,0,0,0,0,0,5,0,0,0,0,0,0,0,"Lethlas - In Combat - Cast Corrosive Acid Breath"),
(5312,0,1,0,0,0,100,0,9000,12000,10000,14000,11,12882,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lethlas - In Combat - Cast Wing Flap");

-- Rage Scar Yeti
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5296;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5296 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5296,0,0,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rage Scar Yeti - Between 0-30% Health - Cast Enrage (No Repeat)"),
(5296,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rage Scar Yeti - Between 0-30% Health - Say Line 0 (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID`=5296;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(5296,0,0,"%s becomes enraged!",16,0,100,0,0,0,10677,0,"Rage Scar Yeti");

-- Ferocious Rage Scar
DELETE FROM `smart_scripts` WHERE `entryorguid`=5299 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5299,0,0,0,0,0,100,0,6000,11000,16000,21000,11,3147,0,0,0,0,0,5,0,0,0,0,0,0,0,"Ferocious Rage Scar - In Combat - Cast Rend Flesh");

-- Wandering Forest Walker
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7584;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7584 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7584,0,0,0,14,0,100,0,1200,40,25000,31000,11,16561,0,0,0,0,0,7,0,0,0,0,0,0,0,"Wandering Forest Walker - Friendly At 1200 Health - Cast Regrowth");

-- Land Walker
DELETE FROM `smart_scripts` WHERE `entryorguid`=5357 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5357,0,1,0,0,0,100,0,0,0,2300,3900,11,23391,64,0,0,0,0,2,0,0,0,0,0,0,0,"Land Walker - In Combat - Cast Boulder");

-- Cliff Giant
DELETE FROM `smart_scripts` WHERE `entryorguid`=5358 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5358,0,1,0,0,0,100,0,6000,8000,9000,13000,11,45,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cliff Giant - In Combat - Cast War Stomp");

-- Vale Screecher
UPDATE `creature_template` SET `unit_class`=2 WHERE `entry`=5307;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5307 AND `source_type`=0 AND `id` IN (1,2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5307,0,1,0,0,0,100,0,3000,5000,7000,11000,11,59220,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vale Screecher - In Combat - Cast Chain Lightning"),
(5307,0,2,0,9,0,100,0,0,8,12000,18000,11,8281,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vale Screecher - Within 0-8 Range - Cast Sonic Burst");

-- Rogue Vale Screecher
DELETE FROM `smart_scripts` WHERE `entryorguid`=5308 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5308,0,1,0,9,0,100,0,0,8,12000,18000,11,8281,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rogue Vale Screecher - Within 0-8 Range - Cast Sonic Burst");

-- Sea Spray
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5462;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5462 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5462,0,0,0,0,0,100,0,0,0,3400,4800,11,11538,64,0,0,0,0,2,0,0,0,0,0,0,0,"Sea Spray - In Combat - Cast Frostbolt"),
(5462,0,1,0,9,0,100,0,0,5,11000,15000,11,10987,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sea Spray - Within 0-5 Range - Cast Geyser");

-- Coast Crawl Deepseer
DELETE FROM `smart_scripts` WHERE `entryorguid`=5328 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5328,0,0,0,1,0,100,0,1000,1000,1800000,1800000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coast Crawl Deepseer - In Combat - Cast Frost Armor"),
(5328,0,1,0,0,0,100,0,0,0,3400,4800,11,9672,64,0,0,0,0,2,0,0,0,0,0,0,0,"Coast Crawl Deepseer - In Combat - Cast Frostbolt"),
(5328,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coast Crawl Deepseer - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Coast Crawl Snapclaw
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5327;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5327 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5327,0,0,0,0,0,100,0,6000,8000,12000,16000,11,49978,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coast Crawl Snapclaw - In Combat - Cast Claw Grasp"),
(5327,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coast Crawl Snapclaw - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Hatecrest Screamer
DELETE FROM `smart_scripts` WHERE `entryorguid`=5335 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5335,0,0,0,0,0,100,0,5000,8000,11000,15000,11,8281,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hatecrest Screamer - In Combat - Cast Sonic Burst"),
(5335,0,1,0,14,0,100,0,800,40,13000,16000,11,6078,0,0,0,0,0,7,0,0,0,0,0,0,0,"Hatecrest Screamer - Friendly At 800 Health - Cast Renew"),
(5335,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hatecrest Screamer - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Hatecrest Warrior
DELETE FROM `smart_scripts` WHERE `entryorguid`=5331 AND `source_type`=0 AND `id` IN (1,2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5331,0,1,0,0,0,100,0,4000,8000,9000,13000,11,6713,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hatecrest Warrior - In Combat - Cast Disarm"),
(5331,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hatecrest Warrior - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Hatecrest Wave Rider
DELETE FROM `smart_scripts` WHERE `entryorguid`=5332 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5332,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hatecrest Wave Rider - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Hatecrest Siren
DELETE FROM `smart_scripts` WHERE `entryorguid`=5337 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5337,0,0,0,0,0,100,0,0,0,3400,4800,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Hatecrest Siren - In Combat - Cast Lightning Bolt"),
(5337,0,1,0,0,0,100,0,8000,14000,19000,24000,11,7645,0,0,0,0,0,6,0,0,0,0,0,0,0,"Hatecrest Siren - In Combat - Cast Dominate Mind"),
(5337,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hatecrest Siren - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Hatecrest Serpent Guard
DELETE FROM `smart_scripts` WHERE `entryorguid`=5333 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5333,0,0,0,0,0,100,0,4000,7000,10000,13000,11,8058,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hatecrest Serpent Guard - In Combat - Cast Frost Shock"),
(5333,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hatecrest Serpent Guard - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Hatecrest Siren
DELETE FROM `smart_scripts` WHERE `entryorguid`=5336 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5336,0,0,0,0,0,100,0,0,0,3400,4800,11,20822,64,0,0,0,0,2,0,0,0,0,0,0,0,"Hatecrest Siren - In Combat - Cast Frostbolt"),
(5336,0,1,0,0,0,100,0,7000,13000,18000,24000,11,10185,0,0,0,0,0,5,0,0,0,0,0,0,0,"Hatecrest Siren - In Combat - Cast Blizzard"),
(5336,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hatecrest Siren - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Hatecrest Myrmidon
DELETE FROM `smart_scripts` WHERE `entryorguid`=5334 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5334,0,0,0,0,0,100,0,3000,6000,8000,11000,11,6533,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hatecrest Myrmidon - In Combat - Cast Net"),
(5334,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hatecrest Myrmidon - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Lord Shalzaru
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8136;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8136 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8136,0,0,0,0,0,100,0,4000,7000,10000,13000,11,8058,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lord Shalzaru - In Combat - Cast Frost Shock");

-- Lord Lakmaeran
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=12803;
DELETE FROM `smart_scripts` WHERE `entryorguid`=12803 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(12803,0,0,0,1,0,100,0,500,1000,600000,600000,11,20545,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Lakmaeran - Out of Combat - Cast Lightning Shield"),
(12803,0,1,0,16,0,100,0,20545,1,15000,30000,11,20545,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Lakmaeran - On Friendly Unit Missing Buff 'Lightning Shield' - Cast Lightning Shield"),
(12803,0,2,0,0,0,100,0,3000,5000,12000,16000,11,20543,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lord Lakmaeran - In Combat - Cast Lightning Breath"),
(12803,0,3,0,0,0,100,0,6000,12000,19000,21000,11,20542,0,0,0,0,0,5,0,0,0,0,0,0,0,"Lord Lakmaeran - In Combat - Cast Static Conduit"),
(12803,0,4,0,2,0,100,1,0,20,0,0,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Lakmaeran - Between 0-20% Health - Cast Frenzy (No Repeat)"),
(12803,0,5,0,2,0,100,1,0,20,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Lakmaeran - Between 0-20% Health - Say Line 0 (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID`=12803;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(12803,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,10645,0,"Lord Lakmaeran");

-- Chimaerok Devourer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=12802;
DELETE FROM `smart_scripts` WHERE `entryorguid`=12802 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(12802,0,0,0,0,0,100,0,7000,12000,11000,15000,11,20539,0,0,0,0,0,2,0,0,0,0,0,0,0,"Chimaerok Devourer - In Combat - Cast Fatal Bite"),
(12802,0,1,0,2,0,100,1,0,20,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chimaerok Devourer - Between 0-20% Health - Cast Enrage (No Repeat)"),
(12802,0,2,0,2,0,100,1,0,20,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chimaerok Devourer - Between 0-20% Health - Say Line 0 (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID`=12802;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(12802,0,0,"%s becomes enraged!",16,0,100,0,0,0,10677,0,"Rage Scar Yeti");

-- Chimaerok
DELETE FROM `smart_scripts` WHERE `entryorguid`=12800 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(12800,0,0,0,0,0,100,0,3000,6000,4000,7000,11,20629,0,0,0,0,0,5,0,0,0,0,0,0,0,"Chimaerok - In Combat - Cast Corrosive Venom Spit");

-- Arcane Chimaerok
DELETE FROM `smart_scripts` WHERE `entryorguid`=12801 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(12801,0,2,0,13,0,100,0,30000,30000,0,0,11,20537,0,0,0,0,0,2,0,0,0,0,0,0,0,"Arcane Chimaerok - Target Casting - Cast Counterspell");

-- Gordok Ogre-Mage
DELETE FROM `smart_scripts` WHERE `entryorguid`=11443 AND `source_type`=0 AND `id` IN (0,1,2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11443,0,0,0,4,0,20,1,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gordok Ogre-Mage - On Aggro - Say Line 0"),
(11443,0,1,0,0,0,100,0,0,0,3400,4800,11,20823,64,0,0,0,0,2,0,0,0,0,0,0,0,"Gordok Ogre-Mage - In Combat - Cast Fireball"),
(11443,0,2,0,0,0,100,0,5000,12000,35000,45000,11,6742,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Ogre-Mage - In Combat - Cast Bloodlust");

-- Gordunni Mauler
DELETE FROM `smart_scripts` WHERE `entryorguid`=5234 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5234,0,0,0,25,0,100,0,0,0,0,0,11,8876,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Mauler - On Reset - Cast Thrash"),
(5234,0,1,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gordunni Mauler - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=5234;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(5234,0,0,"Raaar!!! Me smash $r!",12,0,100,0,0,0,1925,0,"Gordunni Mauler"),
(5234,0,1,"Me smash! You die!",12,0,100,0,0,0,1926,0,"Gordunni Mauler"),
(5234,0,2,"I'll crush you!",12,0,100,0,0,0,1927,0,"Gordunni Mauler");

-- Gordunni Brute
DELETE FROM `smart_scripts` WHERE `entryorguid`=5232 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5232,0,1,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gordunni Brute - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=5232;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(5232,0,0,"Raaar!!! Me smash $r!",12,0,100,0,0,0,1925,0,"Gordunni Brute"),
(5232,0,1,"Me smash! You die!",12,0,100,0,0,0,1926,0,"Gordunni Brute"),
(5232,0,2,"I'll crush you!",12,0,100,0,0,0,1927,0,"Gordunni Brute");

-- Gordunni Warlock
DELETE FROM `smart_scripts` WHERE `entryorguid`=5240 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5240,0,0,0,0,0,100,0,0,0,3400,4800,11,20298,64,0,0,0,0,2,0,0,0,0,0,0,0,"Gordunni Warlock - In Combat - Cast Shadow Bolt"),
(5240,0,1,0,0,0,100,0,6000,11000,14000,21000,11,7289,32,0,0,0,0,5,0,0,0,0,0,0,0,"Gordunni Warlock - In Combat - Cast Shrink"),
(5240,0,2,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gordunni Warlock - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=5240;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(5240,0,0,"Raaar!!! Me smash $r!",12,0,100,0,0,0,1925,0,"Gordunni Warlock"),
(5240,0,1,"Me smash! You die!",12,0,100,0,0,0,1926,0,"Gordunni Warlock"),
(5240,0,2,"I'll crush you!",12,0,100,0,0,0,1927,0,"Gordunni Warlock");

-- Gordunni Warlord
DELETE FROM `smart_scripts` WHERE `entryorguid`=5241 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5241,0,0,0,0,0,100,0,5000,7000,15000,20000,11,10967,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Warlord - In Combat - Cast Echoing Roar"),
(5241,0,1,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gordunni Warlord - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=5241;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(5241,0,0,"Raaar!!! Me smash $r!",12,0,100,0,0,0,1925,0,"Gordunni Warlord"),
(5241,0,1,"Me smash! You die!",12,0,100,0,0,0,1926,0,"Gordunni Warlord"),
(5241,0,2,"I'll crush you!",12,0,100,0,0,0,1927,0,"Gordunni Warlord");

-- Gordunni Battlemaster
DELETE FROM `smart_scripts` WHERE `entryorguid`=5238 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5238,0,0,0,0,0,100,0,5000,7000,12000,17000,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Battlemaster - In Combat - Cast Demoralizing Shout"),
(5238,0,1,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gordunni Battlemaster - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=5238;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(5238,0,0,"Raaar!!! Me smash $r!",12,0,100,0,0,0,1925,0,"Gordunni Battlemaster"),
(5238,0,1,"Me smash! You die!",12,0,100,0,0,0,1926,0,"Gordunni Battlemaster"),
(5238,0,2,"I'll crush you!",12,0,100,0,0,0,1927,0,"Gordunni Battlemaster");

-- Gordunni Mage-Lord
UPDATE `smart_scripts` SET  `event_param3`=3400, `event_param4`=4800 WHERE `entryorguid`=5239 AND `source_type`=0 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5239 AND `source_type`=0 AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5239,0,3,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gordunni Mage-Lord - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=5239;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(5239,0,0,"Raaar!!! Me smash $r!",12,0,100,0,0,0,1925,0,"Gordunni Mage-Lord"),
(5239,0,1,"Me smash! You die!",12,0,100,0,0,0,1926,0,"Gordunni Mage-Lord"),
(5239,0,2,"I'll crush you!",12,0,100,0,0,0,1927,0,"Gordunni Mage-Lord");

-- Gordunni Ogre
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5229;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5229 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5229,0,0,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gordunni Ogre - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=5229;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(5229,0,0,"Raaar!!! Me smash $r!",12,0,100,0,0,0,1925,0,"Gordunni Ogre"),
(5229,0,1,"Me smash! You die!",12,0,100,0,0,0,1926,0,"Gordunni Ogre"),
(5229,0,2,"I'll crush you!",12,0,100,0,0,0,1927,0,"Gordunni Ogre");

-- Gordunni Ogre Mage
UPDATE `smart_scripts` SET  `event_param3`=3400, `event_param4`=4800 WHERE `entryorguid`=5237 AND `source_type`=0 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5237 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5237,0,2,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gordunni Ogre Mage - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=5237;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(5237,0,0,"Raaar!!! Me smash $r!",12,0,100,0,0,0,1925,0,"Gordunni Ogre Mage"),
(5237,0,1,"Me smash! You die!",12,0,100,0,0,0,1926,0,"Gordunni Ogre Mage"),
(5237,0,2,"I'll crush you!",12,0,100,0,0,0,1927,0,"Gordunni Ogre Mage");

-- Enraged Feral Scar
DELETE FROM `smart_scripts` WHERE `entryorguid`=5295 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5295,0,0,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Enraged Feral Scar - Between 0-30% Health - Cast Enrage (No Repeat)"),
(5295,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Enraged Feral Scar - Between 0-30% Health - Say Line 0 (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID`=5295;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(5295,0,0,"%s becomes enraged!",16,0,100,0,0,0,10677,0,"Enraged Feral Scar");

-- Grimtotem Shaman
DELETE FROM `smart_scripts` WHERE `entryorguid`=7727 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7727,0,0,0,0,0,100,0,3000,5000,8000,12000,11,930,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grimtotem Shaman - In Combat - Cast Chain Lightning"),
(7727,0,1,0,2,0,100,1,0,50,0,0,11,11969,2,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Shaman - Between 0-50% Health - Cast Fire Nova (No Repeat)"),
(7727,0,2,0,14,0,100,0,1200,40,14000,17000,11,8005,0,0,0,0,0,7,0,0,0,0,0,0,0,"Grimtotem Shaman - Friendly At 1200 Health - Cast Healing Wave"),
(7727,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Shaman - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Grimtotem Naturalist
DELETE FROM `smart_scripts` WHERE `entryorguid`=7726 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7726,0,0,0,4,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Naturalist - On Aggro - Set Event Phase 1"),
(7726,0,1,0,0,1,100,0,0,0,3400,4700,11,9739,64,0,0,0,0,2,0,0,0,0,0,0,0,"Grimtotem Naturalist - In Combat (Phase 1) - Cast Wrath"),
(7726,0,2,0,2,0,100,1,0,50,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Naturalist - Between 0-50% Health - Set Event Phase 2"),
(7726,0,3,0,0,2,100,1,0,0,0,0,11,19030,1,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Naturalist - In Combat (Phase 2) - Cast Bear Form"),
(7726,0,4,0,0,2,100,0,5000,7000,11000,13000,11,12161,2,0,0,0,0,2,0,0,0,0,0,0,0,"Grimtotem Naturalist - In Combat (Phase 2) - Cast Maul"),
(7726,0,5,0,0,2,100,0,8000,10000,24000,28000,11,15727,2,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Naturalist - In Combat (Phase 2) - Cast Demoralizing Roar"),
(7726,0,6,0,0,2,100,1,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Naturalist - In Combat (Phase 2) - Enable Combat Movement"),
(7726,0,7,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Naturalist - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Grimtotem Raider
DELETE FROM `smart_scripts` WHERE `entryorguid`=7725 AND `source_type`=0 AND `id` IN (1,2,3);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7725,0,1,0,0,0,100,0,3000,5000,9000,11000,11,6533,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grimtotem Raider - In Combat - Cast Net"),
(7725,0,2,0,0,0,100,0,6000,9000,7000,10000,11,845,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grimtotem Raider - In Combat - Cast Cleave"),
(7725,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Raider - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Woodpaw Mongrel
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5249;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5249 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5249,0,0,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Woodpaw Mongrel - On Aggro - Say Line 0"),
(5249,0,1,0,0,0,100,0,5000,9000,14000,18000,11,7102,32,0,0,0,0,2,0,0,0,0,0,0,0,"Woodpaw Mongrel - In Combat - Cast Contagion of Rot"),
(5249,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Woodpaw Mongrel - Between 0-15% Health - Flee For Assist (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID`=5249;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(5249,0,0,"Grrrrr!",12,0,100,0,0,0,1869,0,"Woodpaw Mongrel"),
(5249,0,1,"Grrrr... fresh meat!",12,0,100,0,0,0,1870,0,"Woodpaw Mongrel"),
(5249,0,2,"More bones to gnaw on...",12,0,100,0,0,0,1871,0,"Woodpaw Mongrel");

-- Woodpaw Trapper
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5251;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5251 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5251,0,0,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Woodpaw Trapper - On Aggro - Say Line 0"),
(5251,0,1,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Woodpaw Trapper - In Combat - Cast Shoot"),
(5251,0,2,0,9,0,100,0,0,20,9000,12000,11,6533,0,0,0,0,0,2,0,0,0,0,0,0,0,"Woodpaw Trapper - Within 0-20 Range - Cast Net"),
(5251,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Woodpaw Trapper - Between 0-15% Health - Flee For Assist (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID`=5251;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(5251,0,0,"Grrrrr!",12,0,100,0,0,0,1869,0,"Woodpaw Trapper"),
(5251,0,1,"Grrrr... fresh meat!",12,0,100,0,0,0,1870,0,"Woodpaw Trapper"),
(5251,0,2,"More bones to gnaw on...",12,0,100,0,0,0,1871,0,"Woodpaw Trapper");

-- Woodpaw Brute
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5253;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5253 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5253,0,0,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Woodpaw Brute - On Aggro - Say Line 0"),
(5253,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Woodpaw Brute - Between 0-15% Health - Flee For Assist (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID`=5253;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(5253,0,0,"Grrrrr!",12,0,100,0,0,0,1869,0,"Woodpaw Brute"),
(5253,0,1,"Grrrr... fresh meat!",12,0,100,0,0,0,1870,0,"Woodpaw Brute"),
(5253,0,2,"More bones to gnaw on...",12,0,100,0,0,0,1871,0,"Woodpaw Brute");

-- Woodpaw Mystic
DELETE FROM `smart_scripts` WHERE `entryorguid`=5254 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5254,0,0,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Woodpaw Mystic - On Aggro - Say Line 0"),
(5254,0,1,0,0,0,100,0,0,0,3400,4800,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Woodpaw Mystic - In Combat - Cast Lightning Bolt"),
(5254,0,2,0,14,0,100,0,800,40,16000,21000,11,8005,0,0,0,0,0,7,0,0,0,0,0,0,0,"Woodpaw Mystic - Friendly At 800 Health - Cast Healing Wave"),
(5254,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Woodpaw Mystic - Between 0-15% Health - Flee For Assist (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID`=5254;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(5254,0,0,"Grrrrr!",12,0,100,0,0,0,1869,0,"Woodpaw Mystic"),
(5254,0,1,"Grrrr... fresh meat!",12,0,100,0,0,0,1870,0,"Woodpaw Mystic"),
(5254,0,2,"More bones to gnaw on...",12,0,100,0,0,0,1871,0,"Woodpaw Mystic");

-- Woodpaw Reaver
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5255;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5255 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5255,0,0,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Woodpaw Reaver - On Aggro - Say Line 0"),
(5255,0,1,0,4,0,100,1,0,0,0,0,11,7366,0,0,0,0,0,1,0,0,0,0,0,0,0,"Woodpaw Reaver - On Aggro - Cast Berserker Stance"),
(5255,0,2,0,0,0,100,0,5000,9000,7000,11000,11,7369,0,0,0,0,0,2,0,0,0,0,0,0,0,"Woodpaw Reaver - In Combat - Cast Cleave"),
(5255,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Woodpaw Reaver - Between 0-15% Health - Flee For Assist (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID`=5255;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(5255,0,0,"Grrrrr!",12,0,100,0,0,0,1869,0,"Woodpaw Reaver"),
(5255,0,1,"Grrrr... fresh meat!",12,0,100,0,0,0,1870,0,"Woodpaw Reaver"),
(5255,0,2,"More bones to gnaw on...",12,0,100,0,0,0,1871,0,"Woodpaw Reaver");

-- Woodpaw Alpha
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5258;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5258 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5258,0,0,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Woodpaw Alpha - On Aggro - Say Line 0"),
(5258,0,1,0,2,0,100,1,0,40,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Woodpaw Alpha - Between 0-40% Health - Cast Enrage (No Repeat)"),
(5258,0,2,0,2,0,100,1,0,40,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Woodpaw Alpha - Between 0-40% Health - Say Line 1 (No Repeat)"),
(5258,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Woodpaw Alpha - Between 0-15% Health - Flee For Assist (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID`=5258;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(5258,0,0,"Grrrrr!",12,0,100,0,0,0,1869,0,"Woodpaw Alpha"),
(5258,0,1,"Grrrr... fresh meat!",12,0,100,0,0,0,1870,0,"Woodpaw Alpha"),
(5258,0,2,"More bones to gnaw on...",12,0,100,0,0,0,1871,0,"Woodpaw Alpha"),
(5258,1,0,"%s becomes enraged!",16,0,100,0,0,0,10677,0,"Woodpaw Alpha");

-- Gnarl Leafbrother
DELETE FROM `smart_scripts` WHERE `entryorguid`=5354 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5354,0,0,0,9,0,100,0,0,30,18000,21000,11,11922,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gnarl Leafbrother - Within 0-30 Range - Cast Entangling Roots");

-- Zukk'ash Stinger
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5244;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5244 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5244,0,0,0,0,0,100,0,4000,9000,14000,18000,11,5416,0,0,0,0,0,2,0,0,0,0,0,0,0,"Zukk'ash Stinger - In Combat - Cast Venom Sting");

-- Zukk'ash Wasp
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5245;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5245 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5245,0,0,0,0,0,100,0,4000,12000,8000,16000,11,744,32,0,0,0,0,2,0,0,0,0,0,0,0,"Zukk'ash Wasp - In Combat - Cast Poison");

-- Zukk'ash Worker
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5246;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5246 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5246,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Zukk'ash Worker - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Zukk'ash Tunneler
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5247;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5247 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5247,0,0,0,0,0,100,0,6000,8000,45000,50000,11,6016,0,0,0,0,0,2,0,0,0,0,0,0,0,"Zukk'ash Tunneler - In Combat - Cast Pierce Armor");

-- Qirot
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5350;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5350 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5350,0,0,0,0,0,100,0,3000,6000,6000,11000,11,13298,32,0,0,0,0,2,0,0,0,0,0,0,0,"Qirot - In Combat - Cast Poison");

-- Lady Szallah
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5343;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5343 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5343,0,0,0,0,0,100,0,0,0,3400,4800,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Lady Szallah - In Combat - Cast Lightning Bolt"),
(5343,0,1,0,0,0,100,0,8000,11000,12000,15000,11,8435,0,0,0,0,0,5,0,0,0,0,0,0,0,"Lady Szallah - In Combat - Cast Forked Lightning"),
(5343,0,2,0,0,0,100,0,12000,15000,17000,21000,11,6728,0,0,0,0,0,6,0,0,0,0,0,0,0,"Lady Szallah - In Combat - Cast Enveloping Winds"),
(5343,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Szallah - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Skarr the Unbreakable
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11498;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11498 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11498,0,0,0,0,0,100,0,5000,7000,13000,16000,11,11428,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skarr the Unbreakable - In Combat - Cast Knockdown"),
(11498,0,1,0,9,0,100,0,0,5,7000,10000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skarr the Unbreakable - In Combat - Cast Cleave"),
(11498,0,2,0,0,0,100,0,8000,12000,9000,15000,11,13737,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skarr the Unbreakable - In Combat - Cast Mortal Strike");

-- The Razza
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11497;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11497 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11497,0,0,0,0,0,100,0,2000,4000,5000,9000,11,21067,0,0,0,0,0,2,0,0,0,0,0,0,0,"The Razza - In Combat - Cast Poison Bolt"),
(11497,0,1,0,0,0,100,0,8000,12000,9000,15000,11,12058,0,0,0,0,0,2,0,0,0,0,0,0,0,"The Razza - In Combat - Cast Chain Lightning");

-- Mushgog
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11447;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11447 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11447,0,0,0,0,0,100,0,2000,3000,12000,15000,11,22127,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mushgog - In Combat - Cast Entangling Roots"),
(11447,0,1,0,0,0,100,0,7000,10000,8000,12000,11,21749,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mushgog - In Combat - Cast Thorn Volley"),
(11447,0,2,0,5,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Mushgog - On Killed Unit - Say Line 0"),
(11447,0,3,0,6,0,100,0,0,0,0,0,11,22948,2,0,0,0,0,1,0,0,0,0,0,0,0,"Mushgog - On Just Died - Cast Spore Cloud");

DELETE FROM `creature_text` WHERE `CreatureID`=11447;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(11447,0,0,"That will teach you to lay off the herb, $r.",12,0,100,0,0,0,9500,0,"Mushgog");

-- Random movement for some creatures
UPDATE `creature` SET `spawndist`=5, `MovementType`=1 WHERE `guid` IN (51841, 51844);
UPDATE `creature` SET `spawndist`=10, `MovementType`=1 WHERE `guid` IN (51839, 51683, 51843);

-- Fix spawn position for one creature
UPDATE `creature` SET `position_x`=-5704.74, `position_y`=3379.41, `position_z`=63.0866, `spawndist`=15, `MovementType`=1 WHERE `guid`=49970;

-- Fix model for Grimtotem Naturalists
UPDATE `creature` SET `modelid`=0 WHERE `id`=7726 AND `modelid`=2289;
*/
