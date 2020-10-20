-- Sand Skitterer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11738;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11738 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11738,0,0,0,0,0,100,0,4000,9000,10000,15000,11,744,32,0,0,0,0,2,0,0,0,0,0,0,0,"Sand Skitterer - In Combat - Cast Poison");

-- Rock Stalker
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11739;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11739 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11739,0,0,0,9,0,100,0,0,30,9000,11000,11,745,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rock Stalker - Within 0-30 Range - Cast Web"),
(11739,0,1,0,0,0,100,0,4000,9000,10000,15000,11,744,32,0,0,0,0,2,0,0,0,0,0,0,0,"Rock Stalker - In Combat - Cast Poison");

-- Gretheer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=14472;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14472 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14472,0,0,0,9,0,100,0,0,5,18000,22000,11,21787,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gretheer - Within 0-5 Range - Cast Deadly Poison"),
(14472,0,1,0,9,0,100,0,0,30,9000,11000,11,745,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gretheer - Within 0-30 Range - Cast Web");

-- Stonelash Scorpid
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11735;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11735 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11735,0,0,0,0,0,100,0,3000,8000,13000,18000,11,5416,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stonelash Scorpid - In Combat - Cast Venom Sting");

-- Stonelash Pincer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11736;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11736 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11736,0,0,0,0,0,100,0,2000,6000,14000,22000,11,3604,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stonelash Pincer - In Combat - Cast Tendon Rip"),
(11736,0,1,0,0,0,100,0,3000,8000,13000,18000,11,5416,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stonelash Pincer - In Combat - Cast Venom Sting");

-- Stonelash Flayer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11737;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11737 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11737,0,0,0,0,0,100,0,3000,8000,13000,18000,11,5416,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stonelash Flayer - In Combat - Cast Venom Sting"),
(11737,0,1,0,0,0,100,0,5000,10000,12000,18000,11,3391,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stonelash Flayer - In Combat - Cast Thrash");

-- Krellack
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=14476;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14476 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14476,0,0,0,9,0,100,0,0,5,17000,21000,11,17170,0,0,0,0,0,2,0,0,0,0,0,0,0,"Krellack - Within 0-5 Range - Cast Fatal Sting");

-- Dredge Crusher
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11741;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11741 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11741,0,0,0,0,0,100,0,6000,9000,13000,19000,11,6607,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dredge Crusher - In Combat - Cast Lash");

-- Grubthor
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=14477;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14477 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14477,0,0,0,9,0,100,0,0,5,12000,18000,11,5568,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grubthor - Within 0-5 Range - Cast Trample");

-- Dust Stormer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11744;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11744 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11744,0,0,0,0,0,100,0,6000,8000,20000,24000,11,19513,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dust Stormer - In Combat - Cast Lightning Cloud"),
(11744,0,1,0,1,0,100,0,500,1000,600000,600000,11,19514,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dust Stormer - Out of Combat - Cast Lightning Shield"),
(11744,0,2,0,16,0,100,0,19514,1,15000,30000,11,19514,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dust Stormer - On Friendly Unit Missing Buff Lightning Shield - Cast Lightning Shield");

-- Cyclone Warrior
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11745;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11745 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11745,0,0,0,0,0,100,0,3000,6000,9000,15000,11,12553,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cyclone Warrior - In Combat - Cast Shock"),
(11745,0,1,0,0,0,100,0,7000,12000,18000,23000,11,15535,0,0,0,0,0,4,0,0,0,0,0,0,0,"Cyclone Warrior - In Combat - Cast Enveloping Winds");

-- Whirling Invader
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=14455;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14455 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14455,0,0,0,0,0,100,0,6000,12000,10000,16000,11,17207,0,0,0,0,0,1,0,0,0,0,0,0,0,"Whirling Invader - In Combat - Cast Whirlwind");

-- Huricanian
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=14478;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14478 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14478,0,0,0,0,0,100,0,4000,5000,12000,14000,11,15659,0,0,0,0,0,4,0,0,0,0,0,0,0,"Huricanian - In Combat - Cast Chain Lightning");

-- Desert Rumbler
DELETE FROM `smart_scripts` WHERE `entryorguid`=11746 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11746,0,0,0,0,0,100,0,5000,8000,18000,24000,11,5568,0,0,0,0,0,1,0,0,0,0,0,0,0,"Desert Rumbler - In Combat - Cast Trample");

-- Desert Rager
DELETE FROM `smart_scripts` WHERE `entryorguid`=11747 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11747,0,0,0,0,0,100,0,3000,5000,12000,16000,11,13728,0,0,0,0,0,2,0,0,0,0,0,0,0,"Desert Rager - In Combat - Cast Earth Shock"),
(11747,0,1,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Desert Rager - Between 0-30% Health - Cast Enrage (No Repeat)");

-- Tortured Druid
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=12178;
DELETE FROM `smart_scripts` WHERE `entryorguid`=12178 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(12178,0,0,0,2,0,100,1,0,25,0,0,11,23381,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tortured Druid - Between 0-25% Health - Cast Healing Touch (No Repeat)"),
(12178,0,1,0,0,0,100,0,5000,8000,5000,8000,11,23380,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tortured Druid - In Combat - Cast Moonfire"),
(12178,0,2,3,6,0,75,0,0,0,0,0,11,21327,2,0,0,0,0,1,0,0,0,0,0,0,0,"Tortured Druid - On Just Died - Cast Summon Hive\'Ashi Drones"),
(12178,0,3,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tortured Druid - On Just Died - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=12178;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(12178,0,0,"%s\'s death wail has stirred the nearby silithid hive!",16,0,100,0,0,0,8619,0,"Tortured Druid");

-- Tortured Sentinel
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=12179;
DELETE FROM `smart_scripts` WHERE `entryorguid`=12179 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(12179,0,0,1,6,0,75,0,0,0,0,0,11,21327,2,0,0,0,0,1,0,0,0,0,0,0,0,"Tortured Sentinel - On Just Died - Cast Summon Hive\'Ashi Drones"),
(12179,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tortured Sentinel - On Just Died - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=12179;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(12179,0,0,"%s\'s death wail has stirred the nearby silithid hive!",16,0,100,0,0,0,8620,0,"Tortured Sentinel");

-- Twilight Overlord
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=15213;
DELETE FROM `smart_scripts` WHERE `entryorguid`=15213 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(15213,0,0,0,0,0,100,0,0,0,3400,4800,11,9672,64,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Overlord - In Combat - Cast Frostbolt"),
(15213,0,1,0,9,0,100,0,0,8,13000,15000,11,11831,1,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Overlord - Within 0-8 Range - Cast Frost Nova"),
(15213,0,2,0,0,0,100,0,8000,9000,24000,25000,11,12058,1,0,0,0,0,4,0,0,0,0,0,0,0,"Twilight Overlord - In Combat - Cast Chain Lightning"),
(15213,0,3,0,0,0,100,0,5000,6000,15000,21000,11,13339,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Overlord - In Combat - Cast Fire Blast");

-- Twilight Master
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11883;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11883 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11883,0,0,0,0,0,100,0,0,0,3400,4800,11,9672,64,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Master - In Combat - Cast Frostbolt"),
(11883,0,1,0,9,0,100,0,0,8,13000,15000,11,11831,1,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Master - Within 0-8 Range - Cast Frost Nova"),
(11883,0,2,0,0,0,100,0,8000,9000,24000,25000,11,12058,1,0,0,0,0,4,0,0,0,0,0,0,0,"Twilight Master - In Combat - Cast Chain Lightning"),
(11883,0,3,0,0,0,100,0,5000,6000,15000,21000,11,13339,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Master - In Combat - Cast Fire Blast");

-- Twilight Avenger
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11880;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11880 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11880,0,0,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Avenger - Between 0-30% Health - Cast Enrage (No Repeat)"),
(11880,0,1,0,74,0,100,1,0,20,0,0,11,8602,0,0,0,0,0,9,0,0,0,0,0,0,0,"Twilight Avenger - On Friendly Between 0-20% Health - Cast Vengeance (No Repeat)");

-- Twilight Flamereaver
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=15201;
DELETE FROM `smart_scripts` WHERE `entryorguid`=15201 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(15201,0,0,0,0,0,100,0,2000,5000,18000,22000,11,15732,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Flamereaver - In Combat - Cast Immolate");

-- Vyral the Vile
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=15202;
DELETE FROM `smart_scripts` WHERE `entryorguid`=15202 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(15202,0,0,0,0,0,100,0,0,40,3400,4700,11,19816,64,0,0,0,0,2,0,0,0,0,0,0,0,"Vyral the Vile - In Combat - Cast Fireball"),
(15202,0,1,0,9,0,100,0,0,20,12000,15000,11,17439,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vyral the Vile - Within 0-20 Range - Cast Shadow Shock");

-- Twilight Marauder Morna
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=15541;
DELETE FROM `smart_scripts` WHERE `entryorguid`=15541 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(15541,0,0,0,0,0,100,0,5000,8000,9000,13000,11,16856,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Marauder Morna - In Combat - Cast Mortal Strike"),
(15541,0,1,0,0,0,100,0,0,5,5000,9000,11,15572,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Marauder Morna - In Combat - Cast Sunder Armor"),
(15541,0,2,0,0,0,100,0,9000,15000,14000,18000,11,23600,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Marauder Morna - In Combat - Cast Piercing Howl");

-- Twilight Marauder
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=15542;
DELETE FROM `smart_scripts` WHERE `entryorguid`=15542 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(15542,0,0,0,4,0,100,0,0,0,0,0,11,22911,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Marauder - On Aggro - Cast Charge"),
(15542,0,1,0,2,0,100,1,0,20,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Marauder - Between 0-20% Health - Cast Enrage (No Repeat)"),
(15542,0,2,0,0,0,100,0,9000,15000,14000,18000,11,23600,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Marauder - In Combat - Cast Piercing Howl");

-- Twilight Geolord
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11881;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11881 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11881,0,0,0,0,0,100,0,0,0,2400,3800,11,9483,64,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Geolord - In Combat - Cast Boulder"),
(11881,0,1,0,9,0,100,0,0,20,12000,15000,11,13728,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Geolord - Within 0-20 Range - Cast Earth Shock");

-- Twilight Stonecaller
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11882;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11882 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11882,0,0,0,0,0,100,0,0,0,3400,4800,11,9053,64,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Stonecaller - In Combat - Cast Fireball"),
(11882,0,1,0,1,0,100,1,1000,2000,0,0,11,19704,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Stonecaller - Out of Combat - Cast Summon Earth Elemental"),
(11882,0,2,0,9,0,100,0,0,5,12000,17000,11,11020,1,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Stonecaller - Within 0-5 Range - Cast Petrify"),
(11882,0,3,0,1,0,100,1,3000,5000,0,0,11,13236,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Stonecaller - Out of Combat - Cast Nature Channeling");

-- Twilight Prophet
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=15308;
DELETE FROM `smart_scripts` WHERE `entryorguid`=15308 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(15308,0,0,0,0,0,100,0,4000,4500,12000,15000,11,15305,0,0,0,0,0,4,0,0,0,0,0,0,0,"Twilight Prophet - In Combat - Cast Chain Lightning"),
(15308,0,1,0,0,0,100,0,8000,9000,25000,28000,11,22884,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Prophet - In Combat - Cast Psychic Scream"),
(15308,0,2,0,9,0,100,0,0,8,16000,19000,11,17366,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Prophet - Within 0-8 Range - Cast Fire Nova"),
(15308,0,3,0,9,0,100,0,0,8,16000,19000,11,15531,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Prophet - Within 0-8 Range - Cast Frost Nova");

-- Twilight Keeper Havunth
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11804;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11804 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11804,0,0,0,9,0,100,0,0,8,10000,15000,11,17366,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Keeper Havunth - Within 0-8 Range - Cast Fire Nova"),
(11804,0,1,0,9,0,100,0,0,20,8000,13000,11,13339,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Keeper Havunth - Within 0-20 Range - Cast Fire Blast");

-- Twilight Keeper Mayna
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=15200;
DELETE FROM `smart_scripts` WHERE `entryorguid`=15200 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(15200,0,0,0,0,0,100,0,7000,8500,12000,14500,11,17165,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Keeper Mayna - In Combat - Cast Mind Flay"),
(15200,0,1,0,0,0,100,0,5000,6000,20000,27000,11,15654,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Keeper Mayna - In Combat - Cast Shadow Word: Pain"),
(15200,0,2,0,0,0,100,0,9000,12000,33000,35000,11,22884,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Keeper Mayna - In Combat - Cast Psychic Scream");

-- Twilight Lord Everun
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=14479;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14479 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14479,0,0,0,0,0,100,0,0,40,3400,4700,11,19816,64,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Lord Everun - In Combat - Cast Fireball"),
(14479,0,1,0,9,0,100,0,0,20,12000,15000,11,17439,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Lord Everun - Within 0-20 Range - Cast Shadow Shock");

-- Twilight Keeper Exeter
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11803;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11803 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11803,0,0,0,9,0,100,0,0,5,9000,12000,11,16856,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Keeper Exeter - Within 0-5 Range - Cast Mortal Strike"),
(11803,0,1,0,0,0,100,0,5000,9000,18000,22000,11,22427,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Keeper Exeter - In Combat - Cast Concussion Blow");

-- Setis
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=14471;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14471 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14471,0,0,0,0,0,100,0,8000,12000,18000,26000,11,16727,0,0,0,0,0,1,0,0,0,0,0,0,0,"Setis - In Combat - Cast War Stomp"),
(14471,0,1,0,0,0,100,0,14000,20000,15000,23000,11,10887,0,0,0,0,0,2,0,0,0,0,0,0,0,"Setis - In Combat - Cast Crowd Pummel");

-- Zora
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=14474;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14474 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14474,0,0,0,9,0,100,0,0,30,12000,18000,11,21067,0,0,0,0,0,2,0,0,0,0,0,0,0,"Zora - Within 0-30 Range - Cast Poison Bolt");

-- Lapress
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=14473;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14473 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14473,0,0,0,9,0,100,0,0,5,20000,27000,11,13445,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lapress - Within 0-5 Range - Cast Rend");

-- Rex Ashil
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=14475;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14475 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14475,0,0,0,9,0,100,0,0,5,18000,22000,11,12097,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rex Ashil - Within 0-5 Range - Cast Pierce Armor");

-- Hive'Ashi Defender
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11722;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11722 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11722,0,0,0,0,0,100,0,3000,4500,12000,15000,11,11443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hive\'Ashi Defender - In Combat - Cast Cripple"),
(11722,0,1,0,0,0,100,0,6000,9000,22000,27000,11,6713,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hive\'Ashi Defender - In Combat - Cast Disarm");

-- Hive'Ashi Sandstalker
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11723;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11723 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11723,0,0,0,25,0,100,0,0,0,0,0,11,22766,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hive\'Ashi Sandstalker - On Reset - Cast Sneak");

-- Hive'Zora Wasp
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11727;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11727 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11727,0,0,0,0,0,100,0,5000,8000,15000,21000,11,19448,32,0,0,0,0,2,0,0,0,0,0,0,0,"Hive'Zora Wasp - In Combat - Cast Poison");

-- Hive'Zora Reaver
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11728;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11728 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11728,0,0,0,0,0,100,0,6000,9000,20000,22000,11,16790,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hive\'Zora Reaver - In Combat - Cast Knockdown"),
(11728,0,1,0,9,0,100,0,0,5,16000,19000,11,40504,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hive\'Zora Reaver - Within 0-5 Range - Cast Cleave");

-- Hive'Zora Hive Sister
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11729;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11729 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11729,0,0,0,0,0,100,0,3000,5000,12000,16000,11,7951,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hive\'Zora Hive Sister - In Combat - Cast Toxic Spit");

-- Hive'Regal Ambusher
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11730;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11730 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11730,0,0,0,25,0,100,0,0,0,0,0,11,22766,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hive\'Regal Ambusher - On Reset - Cast Sneak"),
(11730,0,1,0,9,0,100,0,0,5,15000,24000,11,744,32,0,0,0,0,2,0,0,0,0,0,0,0,"Hive\'Regal Ambusher - Within 0-5 Range - Cast Poison");

-- Hive'Regal Spitfire
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11732;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11732 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11732,0,0,0,0,0,100,0,2000,5000,16000,19000,11,21047,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hive\'Regal Spitfire - In Combat - Cast Corrosive Acid Spit"),
(11732,0,1,0,9,0,100,0,0,5,13000,15000,11,5708,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hive\'Regal Spitfire - Within 0-5 Range - Cast Swoop");

-- Alliance Silithyst Sentinel
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=17765;
DELETE FROM `smart_scripts` WHERE `entryorguid`=17765 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(17765,0,0,0,0,0,100,0,2000,4500,12000,14000,11,19643,0,0,0,0,0,2,0,0,0,0,0,0,0,"Alliance Silithyst Sentinel - In Combat - Cast Mortal Strike"),
(17765,0,1,0,9,0,100,1,0,30,0,0,11,18396,0,0,0,0,0,2,0,0,0,0,0,0,0,"Alliance Silithyst Sentinel - Within 0-30 Range - Cast Dismounting Blast (No Repeat)"),
(17765,0,2,0,0,0,100,0,6000,8000,22000,24000,11,18328,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alliance Silithyst Sentinel - In Combat - Cast Incapacitating Shout"),
(17765,0,3,0,13,0,100,0,20000,30000,0,0,11,11972,0,0,0,0,0,2,0,0,0,0,0,0,0,"Alliance Silithyst Sentinel - On Victim Casting - Cast Shield Bash");

-- Ironforge Brigade Rifleman
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=15441;
UPDATE `creature_template_addon` SET `bytes2`=4098 WHERE `entry`=15441;
DELETE FROM `smart_scripts` WHERE `entryorguid`=15441 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(15441,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ironforge Brigade Rifleman - In Combat - Cast Shoot");

-- Horde Silithyst Sentinel
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=17766;
DELETE FROM `smart_scripts` WHERE `entryorguid`=17766 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(17766,0,0,0,0,0,100,0,2000,4500,12000,14000,11,19643,0,0,0,0,0,2,0,0,0,0,0,0,0,"Horde Silithyst Sentinel - In Combat - Cast Mortal Strike"),
(17766,0,1,0,9,0,100,1,0,30,0,0,11,18396,0,0,0,0,0,2,0,0,0,0,0,0,0,"Horde Silithyst Sentinel - Within 0-30 Range - Cast Dismounting Blast (No Repeat)"),
(17766,0,2,0,0,0,100,0,6000,8000,22000,24000,11,18328,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Silithyst Sentinel - In Combat - Cast Incapacitating Shout"),
(17766,0,3,0,13,0,100,0,20000,30000,0,0,11,11972,0,0,0,0,0,2,0,0,0,0,0,0,0,"Horde Silithyst Sentinel - On Victim Casting - Cast Shield Bash");

-- Orgrimmar Legion Axe Thrower
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=15617;
DELETE FROM `smart_scripts` WHERE `entryorguid`=15617 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(15617,0,0,0,0,0,100,0,0,0,2300,3900,11,10277,64,0,0,0,0,2,0,0,0,0,0,0,0,"Orgrimmar Legion Axe Thrower - In Combat - Cast Throw");

-- Mistress Natalia Mar'alith
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=15215;
DELETE FROM `smart_scripts` WHERE `entryorguid`=15215 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(15215,0,0,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mistress Natalia Mar\'alith - On Aggro - Say Line 0"),
(15215,0,1,0,0,0,100,0,2000,4000,10000,12000,11,44415,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mistress Natalia Mar\'alith - In Combat - Cast Blackout"),
(15215,0,2,0,2,0,100,0,0,60,12000,20000,11,27527,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mistress Natalia Mar\'alith - Between 0-60% Health - Cast Healing Touch"),
(15215,0,3,0,0,0,100,0,5000,7000,16000,24000,11,11639,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mistress Natalia Mar\'alith - In Combat - Cast Shadow Word: Pain"),
(15215,0,4,0,0,0,100,0,12000,15000,12000,17000,11,13704,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mistress Natalia Mar\'alith - In Combat - Cast Psychic Scream"),
(15215,0,5,0,0,0,100,0,8000,9000,16000,17000,11,16568,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mistress Natalia Mar\'alith - In Combat - Cast Mind Flay"),
(15215,0,6,0,6,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mistress Natalia Mar\'alith - On Death - Say Line 1");

DELETE FROM `creature_text` WHERE `CreatureID`=15215;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(15215,0,0,"You will make a fitting sacrifice!",12,0,100,0,0,0,10742,0,"Mistress Natalia Mar\'alith"),
(15215,1,0,"C'Thun will retake this world!",14,0,100,0,0,0,10743,0,"Mistress Natalia Mar\'alith");
