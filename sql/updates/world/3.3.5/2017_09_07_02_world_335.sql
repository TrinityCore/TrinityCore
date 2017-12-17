-- Moonstalker Matriarch
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2071;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2071;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2071,0,0,0,1,0,100,1,3000,5000,0,0,11,8594,0,0,0,0,0,1,0,0,0,0,0,0,0,'Moonstalker Matriarch - Out of Combat - Cast Summon Moonstalker Runt (No Repeat)');

-- Moonstalker Sire
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2237;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2237;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2237,0,0,0,9,0,100,0,0,5,10000,14000,11,6595,0,0,0,0,0,2,0,0,0,0,0,0,0,'Moonstalker Sire - Within 0-5 Range - Cast Exploit Weakness');

-- Grizzled Thistle Bear
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2165;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2165;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2165,0,0,0,0,0,100,0,3000,5000,7000,10000,11,3242,0,0,0,0,0,2,0,0,0,0,0,0,0,'Grizzled Thistle Bear - In Combat - Cast Ravage');

-- Strider Clutchmother
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2172;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2172;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2172,0,0,0,0,0,100,0,7000,11000,12000,14000,11,7272,0,0,0,0,0,1,0,0,0,0,0,0,0,'Strider Clutchmother - In Combat - Cast Dust Cloud'),
(2172,0,1,0,9,0,100,0,0,5,15000,17000,11,6607,0,0,0,0,0,2,0,0,0,0,0,0,0,'Strider Clutchmother - Within 0-5 Range - Cast Lash'),
(2172,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Strider Clutchmother - Between 0-15% Health - Flee For Assist (No Repeat)');

-- Shadowclaw
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2175;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2175;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2175,0,0,0,9,0,100,0,0,30,12000,15000,11,17227,0,0,0,0,0,2,0,0,0,0,0,0,0,'Shadowclaw - Within 0-30 Range - Cast Curse of Weakness');

-- Moonkin Oracle
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10157;
DELETE FROM `smart_scripts` WHERE `entryorguid`=10157;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10157,0,0,0,0,0,100,0,1000,2000,2000,2000,11,9739,64,0,0,0,0,2,0,0,0,0,0,0,0,'Moonkin Oracle - In Combat - Cast Wrath'),
(10157,0,1,0,0,0,100,0,7000,11000,12000,15000,11,15798,1,0,0,0,0,2,0,0,0,0,0,0,0,'Moonkin Oracle - In Combat - Cast Moonfire'),
(10157,0,2,0,14,0,100,0,200,40,25000,30000,11,16561,1,0,0,0,0,7,0,0,0,0,0,0,0,'Moonkin Oracle - Friendly At 200 Health - Cast Regrowth');

-- Moonkin
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10158;
DELETE FROM `smart_scripts` WHERE `entryorguid`=10158;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10158,0,0,0,4,0,100,0,0,0,0,0,75,12787,0,0,0,0,0,1,0,0,0,0,0,0,0,'Moonkin Cast Thrash on reset');

-- Raging Moonkin
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10160;
DELETE FROM `smart_scripts` WHERE `entryorguid`=10160;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10160,0,0,0,2,0,100,1,0,30,0,0,11,8599,1,0,0,0,0,1,0,0,0,0,0,0,0,'Raging Moonkin - Between 0-30% Health - Cast Enrage (No Repeat)'),
(10160,0,1,0,9,0,100,0,0,5,10000,15000,11,13443,0,0,0,0,0,2,0,0,0,0,0,0,0,'Raging Moonkin - Within 0-5 Range - Cast Rend');

-- Wild Grell
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2190;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2190;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2190,0,0,0,2,0,100,0,0,30,60000,60000,11,5915,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wild Grell - Between 0-30% Health - Cast Crazed');

-- Deth'ryll Satyr
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2212;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2212;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2212,0,0,0,0,0,100,0,1000,2000,3500,4100,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,'Dethryll Satyr - In Combat - Cast Shoot');

-- Licillin
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2191;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2191;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2191,0,0,0,0,0,100,0,1000,2000,3000,3500,11,20793,64,0,0,0,0,2,0,0,0,0,0,0,0,'Licillin - In Combat - Cast Fireball'),
(2191,0,1,0,9,0,100,0,0,30,20000,25000,11,11980,1,0,0,0,0,2,0,0,0,0,0,0,0,'Licillin - Within 0-30 Range - Cast Curse of Weakness');

-- Blackwood Pathfinder
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2167;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2167;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2167,0,0,0,9,0,100,0,0,30,30000,35000,11,6950,0,0,0,0,0,2,0,0,0,0,0,0,0,'Blackwood Pathfinder - Within 0-30 Range - Cast Faerie Fire'),
(2167,0,1,0,4,0,100,0,0,0,0,0,75,54913,0,0,0,0,0,1,0,0,0,0,0,0,0,'Blackwood Pathfinder - Within 0-5 Range - Cast Thrash');

-- Blackwood Warrior
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2168;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2168;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2168,0,0,0,9,0,100,0,0,8,8000,13000,11,8078,0,0,0,0,0,2,0,0,0,0,0,0,0,'Blackwood Warrior - Within 0-8 Range - Cast Thunderclap'),
(2168,0,1,0,4,0,100,0,0,0,0,0,11,7165,0,0,0,0,0,1,0,0,0,0,0,0,0,'Blackwood Warrior - Out of Combat - Cast Battle Stance (No Repeat)');

-- Blackwood Totemic
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2169;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2169;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2169,0,0,0,0,0,100,0,3000,6000,18000,23000,11,5605,0,0,0,0,0,1,0,0,0,0,0,0,0,'Blackwood Totemic - In Combat - Cast Healing Ward');

-- Blackwood Ursa
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2170;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2170;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2170,0,0,0,14,0,100,0,200,40,18000,21000,11,1058,0,0,0,0,0,7,0,0,0,0,0,0,0,'Blackwood Ursa - Friendly At 200 Health - Cast Rejuvenation');

-- Blackwood Shaman
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2171;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2171;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2171,0,0,0,0,0,100,0,1000,2000,3000,3400,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,'Blackwood Shaman - In Combat CMC - Cast Lightning Bolt'),
(2171,0,1,0,0,0,100,0,9000,14000,11000,15000,11,2606,0,0,0,0,0,2,0,0,0,0,0,0,0,'Blackwood Shaman - In Combat - Cast Shock'),
(2171,0,2,0,14,0,100,0,300,40,16000,21000,11,913,0,0,0,0,0,7,0,0,0,0,0,0,0,'Blackwood Shaman - Friendly At 300 Health - Cast Healing Wave');

-- Blackwood Windtalker
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2324;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2324;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2324,0,0,0,0,0,100,0,7000,11000,16000,21000,11,6982,0,0,0,0,0,1,0,0,0,0,0,0,0,'Blackwood Windtalker - In Combat - Cast Gust of Wind');

-- Carnivous the Breaker
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2186;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2186;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2186,0,0,0,25,0,100,0,0,0,0,0,75,8876,0,0,0,0,0,1,0,0,0,0,0,0,0,'Carnivous the Breaker - On Respawn - Cast Thrash (No Repeat)'),
(2186,0,1,0,9,0,100,0,0,0,15000,20000,11,6016,0,0,0,0,0,2,0,0,0,0,0,0,0,'Carnivous the Breaker - Within 0-5 Range - Cast Pierce Armor');

-- Cursed Highborne
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2176;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2176;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2176,0,0,0,0,0,100,0,5000,9000,10000,13000,11,5884,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cursed Highborne - In Combat - Cast Banshee Curse');

-- Writhing Highborne
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2177;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2177;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2177,0,0,0,0,0,100,0,5000,9000,10000,13000,11,5884,0,0,0,0,0,5,0,0,0,0,0,0,0,'Writhing Highborne - In Combat - Cast Banshee Curse');

-- Wailing Highborne
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2178;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2178;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2178,0,0,0,0,0,100,0,5000,9000,10000,13000,11,5884,0,0,0,0,0,5,0,0,0,0,0,0,0,'Wailing Highborne - In Combat - Cast Banshee Curse');

-- Lady Moongazer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2184;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2184;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2184,0,0,0,0,0,100,0,1500,2000,3100,3500,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,'Lady Moongazer - In Combat - Cast Shoot'),
(2184,0,1,0,9,0,100,0,0,20,8000,11000,11,6533,1,0,0,0,0,2,0,0,0,0,0,0,0,'Lady Moongazer - Within 0-20 Range - Cast Net');

-- Stormscale Siren
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2180;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2180;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2180,0,0,0,0,0,100,0,1000,2000,2600,3000,11,9734,64,0,0,0,0,2,0,0,0,0,0,0,0,'Stormscale Siren - In Combat - Cast Holy Smite'),
(2180,0,1,0,2,0,100,0,0,50,18000,25000,11,11642,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stormscale Siren - Between 0-50% Health - Cast Heal'),
(2180, 0, 2, 0, 2, 0, 100, 1, 0, 15, 0, 0, 25, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Flee at 15% HP");

-- Stormscale Wave Rider
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2179;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2179;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2179,0,0,0,0,0,100,0,8000,13000,12000,16000,11,13586,0,0,0,0,0,2,0,0,0,0,0,0,0,'Stormscale Wave Rider - In Combat - Cast Aqua Jet');

-- Stormscale Warrior
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2183;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2183;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2183,0,0,0,0,0,100,0,4000,8000,10000,12000,11,3248,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stormscale Warrior - In Combat - Cast Improved Blocking');

-- Lord Sinslayer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7017;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7017;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7017,0,0,0,9,0,100,0,0,5,5000,10000,11,12057,0,0,0,0,0,2,0,0,0,0,0,0,0,'Lord Sinslayer - Within 0-5 Range - Cast Strike'),
(7017,0,1,0,0,0,100,0,9000,12000,9000,12000,11,13586,0,0,0,0,0,2,0,0,0,0,0,0,0,'Lord Sinslayer - In Combat - Cast Aqua Jet');

-- Encrusted Tide Crawler
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2233;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2233;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2233,0,0,0,0,0,100,0,2000,3000,7000,12000,11,3427,0,0,0,0,0,2,0,0,0,0,0,0,0,'Encrusted Tide Crawler - In Combat - Cast Infected Wound');

-- Greymist Raider
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2201;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2201;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2201,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Greymist Raider - Between 0-15% Health - Flee For Assist');

-- Greymist Coastrunner
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2202;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2202;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2202,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Greymist Coastrunner - Between 0-15% Health - Flee For Assist');

-- Greymist Seer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2203;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2203;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2203,0,0,0,23,0,100,0,324,0,2000,3000,11,324,0,0,0,0,0,1,0,0,0,0,0,0,0,'Greymist Seer - On missing aura - Cast Lightning Shield'),
(2203,0,1,0,16,0,100,0,324,1,9000,29000,11,324,48,0,0,0,0,1,0,0,0,0,0,0,0,'Greymist Seer - On Friendly Unit Missing Buff Lightning Shield - Cast Lightning Shield'),
(2203,0,2,0,74,0,100,0,0,40,14000,18000,11,547,0,0,0,0,0,9,0,0,0,0,0,0,0,'Greymist Seer - On Friendly Between 0-40% Health - Cast Healing Wave'),
(2203,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Greymist Seer - Between 0-15% Health - Flee For Assist (No Repeat)');

-- Greymist Netter
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2204;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2204;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2204,0,0,0,9,0,100,0,0,20,8000,14000,11,12024,0,0,0,0,0,2,0,0,0,0,0,0,0,'Greymist Netter - Within 0-20 Range - Cast Net'),
(2204,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Greymist Netter - Between 0-15% Health - Flee For Assist');

-- Greymist Warrior
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2205;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2205;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2205,0,0,0,4,0,100,0,0,0,0,0,11,5242,0,0,0,0,0,1,0,0,0,0,0,0,0,'Greymist Warrior - In Combat - Cast Battle Shout'),
(2205,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Greymist Warrior - Between 0-15% Health - Flee For Assist');

-- Greymist Hunter
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2206;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2206;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2206,0,0,0,0,0,100,0,1000,2000,2300,3000,11,10277,64,0,0,0,0,2,0,0,0,0,0,0,0,'Greymist Hunter - In Combat CMC - Cast Throw'),
(2206,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Greymist Hunter - Between 0-15% Health - Flee For Assist');

-- Greymist Tidehunter
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2208;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2208;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2208,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Greymist Tidehunter - Between 0-15% Health - Flee For Assist');

-- Flagglemurk the Cruel
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7015;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7015;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7015,0,0,0,9,0,100,0,0,5,7000,10000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,'Flagglemurk the Cruel - Within 0-5 Range - Cast Strike'),
(7015,0,1,0,0,0,100,0,8000,12000,9000,12000,11,11428,0,0,0,0,0,2,0,0,0,0,0,0,0,'Flagglemurk the Cruel - In Combat - Cast Knockdown'),
(7015,0,2,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flagglemurk the Cruel - Between 0-15% Health - Flee For Assist (No Repeat)');

-- Darkshore Thresher
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2185;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2185;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2185,0,0,0,9,0,100,0,0,5,18000,20000,11,6016,0,0,0,0,0,2,0,0,0,0,0,0,0,'Darkshore Thresher - Within 0-5 Range - Cast Pierce Armor');

-- Elder Darkshore Thresher
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2187;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2187;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2187,0,0,0,9,0,100,0,0,5,19000,21000,11,6016,0,0,0,0,0,2,0,0,0,0,0,0,0,'Elder Darkshore Thresher - Within 0-5 Range - Cast Pierce Armor');

-- Firecaller Radison
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2192;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2192;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2192,0,0,0,0,0,100,0,1000,2000,3400,4700,11,20793,64,0,0,0,0,2,0,0,0,0,0,0,0,'Firecaller Radison - In Combat - Cast Fireball'),
(2192,0,1,0,9,0,100,0,0,8,11000,13000,11,11969,2,0,0,0,0,2,0,0,0,0,0,0,0,'Firecaller Radison - Within 0-8 Range - Cast Fire Nova'),
(2192,0,2,0,2,0,100,0,0,30,60000,65000,11,5915,2,0,0,0,0,1,0,0,0,0,0,0,0,'Firecaller Radison - Between 0-30% Health - Cast Crazed');

-- Stone Behemoth
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2157;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2157;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2157,0,0,0,0,0,100,0,5000,11000,13000,16000,11,5810,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stone Behemoth - In Combat - Cast Stone Skin');

-- Lady Vespira
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7016;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7016;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7016,0,0,0,0,0,100,0,1500,3000,3000,3100,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,'Lady Vespira - In Combat - Cast Shoot'),
(7016,0,1,0,9,0,100,0,0,5,9000,14000,11,11428,1,0,0,0,0,2,0,0,0,0,0,0,0,'Lady Vespira - Within 0-5 Range - Cast Knockdown'),
(7016,0,2,0,0,0,100,0,11000,15000,14000,17000,11,12549,1,0,0,0,0,2,0,0,0,0,0,0,0,'Lady Vespira - In Combat - Cast Forked Lightning');

-- Remove Wrong 'Moonstalker Runt' Spawns
DELETE FROM `creature` WHERE `guid` IN (36898, 36904, 36907, 36924, 36938, 36942, 36943, 36944, 36957, 36956, 36958);
DELETE FROM `creature_addon` WHERE `guid` IN (36898, 36904, 36907, 36924, 36938, 36942, 36943, 36944, 36957, 36956, 36958);

UPDATE `creature` SET `position_x`=6594.56, `position_y`=313.645, `position_z`=28.3839 WHERE `guid`=36643;
UPDATE `creature` SET `position_x`=4424.85, `position_y`=422.488, `position_z`=56.4554 WHERE `guid`=36794;
UPDATE `creature` SET `position_x`=7742.69, `position_y`=-1067.14, `position_z`=38.1206 WHERE `guid`=36959;
