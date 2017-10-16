/*
-- Young Scavenger
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1508;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1508 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1508,0,0,1,1,0,100,0,30000,600000,120000,600000,4,1018,0,0,0,0,0,1,0,0,0,0,0,0,0,"Young Scavenger - Out of Combat - Play Sound 1018"),
(1508,0,1,0,61,0,100,0,0,0,0,0,5,393,0,0,0,0,0,1,0,0,0,0,0,0,0,"Young Scavenger - Out of Combat - Play Emote 393");

-- Night Web Matriarch
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1688;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1688 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1688,0,0,0,9,0,100,0,0,5,3000,5000,11,744,32,0,0,0,0,2,0,0,0,0,0,0,0,"Night Web Matriarch - Within 0-5 Range - Cast Poison");

-- Scarlet Warrior
DELETE FROM `smart_scripts` WHERE `entryorguid`=1535 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1535,0,0,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Warrior - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=1535;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1535,0,0,"You carry the taint of the Scourge.  Prepare to enter the Twisting Nether.",12,0,100,0,0,0,2625,0,"Scarlet Warrior"),
(1535,0,1,"There is no escape for you.  The Crusade shall destroy all who carry the Scourge\'s taint.",12,0,100,0,0,0,2626,0,"Scarlet Warrior"),
(1535,0,2,"The Light condemns all who harbor evil.  Now you will die!",12,0,100,0,0,0,2627,0,"Scarlet Warrior"),
(1535,0,3,"The Scarlet Crusade shall smite the wicked and drive evil from these lands!",12,0,100,0,0,0,2628,0,"Scarlet Warrior");

-- Tirisfal Farmer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1934;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1934 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1934,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tirisfal Farmer - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Tirisfal Farmhand
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1935;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1935 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1935,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tirisfal Farmhand - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Farmer Solliden
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1936;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1936 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1936,0,0,0,9,0,100,0,0,5,7000,10000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Farmer Solliden - Within 0-5 Range - Cast Strike"),
(1936,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Farmer Solliden - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Greater Duskbat
DELETE FROM `smart_scripts` WHERE `entryorguid`=1553 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1553,0,0,0,0,0,100,0,3000,5000,7000,12000,11,3242,0,0,0,0,0,2,0,0,0,0,0,0,0,"Greater Duskbat - In Combat - Cast Ravage");

-- Vampiric Duskbat
DELETE FROM `smart_scripts` WHERE `entryorguid`=1554 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1554,0,0,0,0,0,100,0,3000,5000,7000,12000,11,3242,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vampiric Duskbat - In Combat - Cast Ravage");

-- Ressan the Needler
DELETE FROM `smart_scripts` WHERE `entryorguid`=10357 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10357,0,0,0,9,0,100,0,0,8,12000,17000,11,8281,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ressan the Needler - In Combat - Cast Sonic Burst");

-- Rotting Dead
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1525;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1525 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1525,0,0,0,0,0,100,0,3000,6000,9000,15000,11,3234,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rotting Dead - In Combat - Cast Disease Touch");

-- Ravaged Corpse
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1526;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1526 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1526,0,0,0,0,0,100,0,3000,6000,9000,15000,11,3234,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ravaged Corpse - In Combat - Cast Disease Touch");

-- Lost Soul
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1531;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1531 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1531,0,0,0,9,0,100,0,0,8,12000,18000,11,7713,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lost Soul - Within 0-8 Range - Cast Wailing Dead");

-- Rot Hide Gnoll
DELETE FROM `smart_scripts` WHERE `entryorguid`=1674  AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1674,0,0,0,0,0,100,0,4000,12000,30000,45000,11,3237,2,0,0,0,0,2,0,0,0,0,0,0,0,"Rot Hide Gnoll - In Combat - Cast Curse of Thule"),
(1674,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Rot Hide Gnoll - Between 0-15% Health - Flee For Assist (No Repeat)"),
(1674,0,2,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rot Hide Gnoll - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=1674;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1674,0,0,"Grrrr... fresh meat!",12,0,100,0,0,0,1870,0,"Rot Hide Gnoll"),
(1674,0,1,"More bones to gnaw on...",12,0,100,0,0,0,1871,0,"Rot Hide Gnoll");

-- Rot Hide Mongrel
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1675;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1675 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1675,0,0,0,0,0,100,0,7000,14000,30000,45000,11,3237,2,0,0,0,0,2,0,0,0,0,0,0,0,"Rot Hide Mongrel - In Combat - Cast Curse of Thule"),
(1675,0,1,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rot Hide Mongrel - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=1675;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1675,0,0,"Grrrr... fresh meat!",12,0,100,0,0,0,1870,0,"Rot Hide Mongrel"),
(1675,0,1,"More bones to gnaw on...",12,0,100,0,0,0,1871,0,"Rot Hide Mongrel");

-- Rot Hide Graverobber
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1941;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1941 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1941,0,0,0,0,0,100,0,2000,18000,30000,45000,11,3237,2,0,0,0,0,2,0,0,0,0,0,0,0,"Rot Hide Graverobber - In Combat - Cast Curse of Thule"),
(1941,0,1,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rot Hide Graverobber - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=1941;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1941,0,0,"Grrrr... fresh meat!",12,0,100,0,0,0,1870,0,"Rot Hide Graverobber"),
(1941,0,1,"More bones to gnaw on...",12,0,100,0,0,0,1871,0,"Rot Hide Graverobber");

-- Maggot Eye
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1753;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1753 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1753,0,0,0,2,0,100,0,0,75,7000,14000,11,3243,0,0,0,0,0,2,0,0,0,0,0,0,0,"Maggot Eye - Between 0-75% Health - Cast Life Harvest"),
(1753,0,1,0,0,0,100,0,4000,9000,30000,45000,11,3237,2,0,0,0,0,2,0,0,0,0,0,0,0,"Maggot Eye - In Combat - Cast Curse of Thule");

-- Wailing Ancestor
DELETE FROM `smart_scripts` WHERE `entryorguid`=1534 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1534,0,0,0,0,0,100,0,6000,10000,12000,20000,11,7713,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wailing Ancestor - In Combat - Cast Wailing Dead");

-- Rotting Ancestor
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1530;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1530 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1530,0,0,0,0,0,100,0,4000,12000,10000,18000,11,3322,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rotting Ancestor - In Combat - Cast Rancid Blood");

-- Darkeye Bonecaster
DELETE FROM `smart_scripts` WHERE `entryorguid`=1522 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1522,0,0,0,0,0,100,0,0,0,3400,4800,11,13322,64,0,0,0,0,2,0,0,0,0,0,0,0,"Darkeye Bonecaster - In Combat CMC - Cast Frostbolt");

-- Cracked Skull Soldier
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1523;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1523 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1523,0,0,0,0,0,100,0,4000,9000,21000,25000,11,589,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cracked Skull Soldier - In Combat - Cast Shadow Word: Pain");

-- Bayne
DELETE FROM `smart_scripts` WHERE `entryorguid`=10356 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10356,0,0,0,0,0,100,0,5000,8000,21000,25000,11,13443,0,0,0,0,0,5,0,0,0,0,0,0,0,"Bayne - In Combat - Cast Rend"),
(10356,0,1,0,9,0,100,0,0,5,20000,24000,11,3604,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bayne - Within 0-5 Range - Cast Tendon Rip");

-- Vile Fin Puddlejumper
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1543;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1543 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1543,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Fin Puddlejumper - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Vile Fin Muckdweller
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1545;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1545 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1545,0,0,0,67,0,100,0,9000,12000,0,0,11,7159,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vile Fin Muckdweller - On Behind Target - Cast Backstab"),
(1545,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Fin Muckdweller - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Vile Fin Minor Oracle
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1544;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1544 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1544,0,0,0,0,0,100,0,0,0,3400,4800,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Vile Fin Minor Oracle - In Combat - Cast Lightning Bolt"),
(1544,0,1,0,0,0,100,0,11000,16000,12000,16000,11,2607,0,0,0,0,0,4,0,0,0,0,0,0,0,"Vile Fin Minor Oracle - In Combat - Cast Shock"),
(1544,0,2,0,1,0,100,0,500,1000,600000,600000,11,324,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Fin Minor Oracle - Out of Combat - Cast Lightning Shield"),
(1544,0,3,0,16,0,100,0,324,1,15000,30000,11,324,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Fin Minor Oracle - On Friendly Unit Missing Buff Lightning Shield - Cast Lightning Shield"),
(1544,0,4,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Fin Minor Oracle - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Muad
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1910;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1910 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1910,0,0,0,14,0,100,0,80,40,12000,16000,11,332,0,0,0,0,0,7,0,0,0,0,0,0,0,"Muad - Friendly At 80 Health - Cast Healing Wave"),
(1910,0,1,0,9,0,100,0,0,20,5000,8000,11,2607,0,0,0,0,0,2,0,0,0,0,0,0,0,"Muad - Within 0-20 Range - Cast Shock");

-- Scarlet Missionary
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1536;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1536 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1536,0,0,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Missionary - On Aggro - Say Line 0"),
(1536,0,1,0,0,0,100,0,0,0,3400,4800,11,9053,64,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Missionary - In Combat - Cast Fireball"),
(1536,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Missionary - Between 0-15% Health - Flee For Assist (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID`=1536;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1536,0,0,"You carry the taint of the Scourge.  Prepare to enter the Twisting Nether.",12,0,100,0,0,0,2625,0,"Scarlet Missionary"),
(1536,0,1,"There is no escape for you.  The Crusade shall destroy all who carry the Scourge\'s taint.",12,0,100,0,0,0,2626,0,"Scarlet Missionary"),
(1536,0,2,"The Light condemns all who harbor evil.  Now you will die!",12,0,100,0,0,0,2627,0,"Scarlet Missionary"),
(1536,0,3,"The Scarlet Crusade shall smite the wicked and drive evil from these lands!",12,0,100,0,0,0,2628,0,"Scarlet Missionary");

-- Scarlet Zealot
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1537;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1537 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1537,0,0,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Zealot - On Aggro - Say Line 0"),
(1537,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Zealot - Between 0-15% Health - Flee For Assist (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID`=1537;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1537,0,0,"You carry the taint of the Scourge.  Prepare to enter the Twisting Nether.",12,0,100,0,0,0,2625,0,"Scarlet Zealot"),
(1537,0,1,"There is no escape for you.  The Crusade shall destroy all who carry the Scourge\'s taint.",12,0,100,0,0,0,2626,0,"Scarlet Zealot"),
(1537,0,2,"The Light condemns all who harbor evil.  Now you will die!",12,0,100,0,0,0,2627,0,"Scarlet Zealot"),
(1537,0,3,"The Scarlet Crusade shall smite the wicked and drive evil from these lands!",12,0,100,0,0,0,2628,0,"Scarlet Zealot");

-- Scarlet Friar
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1538;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1538 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1538,0,0,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Friar - On Aggro - Say Line 0"),
(1538,0,1,0,1,0,100,0,1000,1000,3000000,3000000,11,1243,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Friar - Out of Combat - Cast Power Word: Fortitude"),
(1538,0,2,0,14,0,100,0,55,40,8000,12000,11,2052,0,0,0,0,0,7,0,0,0,0,0,0,0,"Scarlet Friar - Friendly At 55 Health - Cast Lesser Heal"),
(1538,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Friar - Between 0-15% Health - Flee For Assist (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID`=1538;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1538,0,0,"You carry the taint of the Scourge.  Prepare to enter the Twisting Nether.",12,0,100,0,0,0,2625,0,"Scarlet Friar"),
(1538,0,1,"There is no escape for you.  The Crusade shall destroy all who carry the Scourge\'s taint.",12,0,100,0,0,0,2626,0,"Scarlet Friar"),
(1538,0,2,"The Light condemns all who harbor evil.  Now you will die!",12,0,100,0,0,0,2627,0,"Scarlet Friar"),
(1538,0,3,"The Scarlet Crusade shall smite the wicked and drive evil from these lands!",12,0,100,0,0,0,2628,0,"Scarlet Friar");

-- Scarlet Vanguard
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1540;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1540 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1540,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Vanguard - Between 0-15% Health - Flee For Assist (No Repeat)"),
(1540,0,1,0,13,0,100,0,16000,24000,0,0,11,72,0,0,0,0,0,7,0,0,0,0,0,0,0,"Scarlet Vanguard - Target Casting - Cast Shield Bash"),
(1540,0,2,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Vanguard - On Aggro - Say Line 0"),
(1540,0,3,0,0,0,100,1,1000,3000,0,0,11,7164,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Vanguard - In Combat - Cast Defensive Stance (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID`=1540;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1540,0,0,"You carry the taint of the Scourge.  Prepare to enter the Twisting Nether.",12,0,100,0,0,0,2625,0,"Scarlet Vanguard"),
(1540,0,1,"There is no escape for you.  The Crusade shall destroy all who carry the Scourge\'s taint.",12,0,100,0,0,0,2626,0,"Scarlet Vanguard"),
(1540,0,2,"The Light condemns all who harbor evil.  Now you will die!",12,0,100,0,0,0,2627,0,"Scarlet Vanguard"),
(1540,0,3,"The Scarlet Crusade shall smite the wicked and drive evil from these lands!",12,0,100,0,0,0,2628,0,"Scarlet Vanguard");

-- Scarlet Neophyte
DELETE FROM `smart_scripts` WHERE `entryorguid`=1539 AND `source_type`=0 AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1539,0,3,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Neophyte - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=1539;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1539,0,0,"You carry the taint of the Scourge.  Prepare to enter the Twisting Nether.",12,0,100,0,0,0,2625,0,"Scarlet Neophyte"),
(1539,0,1,"There is no escape for you.  The Crusade shall destroy all who carry the Scourge\'s taint.",12,0,100,0,0,0,2626,0,"Scarlet Neophyte"),
(1539,0,2,"The Light condemns all who harbor evil.  Now you will die!",12,0,100,0,0,0,2627,0,"Scarlet Neophyte"),
(1539,0,3,"The Scarlet Crusade shall smite the wicked and drive evil from these lands!",12,0,100,0,0,0,2628,0,"Scarlet Neophyte");

-- Captain Perrine
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1662;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1662 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1662,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Perrine - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Captain Vachon
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1664;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1664 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1664,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Vachon - Between 0-15% Health - Flee For Assist (No Repeat)"),
(1664,0,1,0,13,0,100,0,16000,24000,0,0,11,72,0,0,0,0,0,7,0,0,0,0,0,0,0,"Captain Vachon - Target Casting - Cast Shield Bash"),
(1664,0,2,0,0,0,100,0,8000,14000,18000,30000,11,3248,0,0,0,0,0,2,0,0,0,0,0,0,0,"Captain Vachon - In Combat - Cast Improved Blocking"),
(1664,0,3,0,0,0,100,1,1000,3000,0,0,11,7164,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Vachon - In Combat - Cast Defensive Stance (No Repeat)");

-- Captain Melrache
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1665;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1665 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1665,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Melrache - Between 0-15% Health - Flee For Assist (No Repeat)"),
(1665,0,1,0,9,0,100,0,0,5,7000,11000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Captain Melrache - Within 0-5 Range - Cast Strike"),
(1665,0,2,0,0,0,100,1,1000,3000,0,0,11,8258,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Melrache - In Combat - Cast Devotion Aura (No Repeat)");

-- Scarlet Bodyguard
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1660;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1660 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1660,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Bodyguard - Between 0-15% Health - Flee For Assist (No Repeat)"),
(1660,0,1,0,0,0,100,0,1000,7000,5000,28000,11,12169,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Bodyguard - In Combat - Cast Shield Block");

-- Bleeding Horror
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1529;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1529 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1529,0,0,0,0,0,100,0,4000,12000,10000,18000,11,3322,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bleeding Horror - In Combat - Cast Rancid Blood");

-- Wandering Spirit
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1532;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1532 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1532,0,0,0,0,0,100,0,6000,10000,12000,20000,11,7713,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wandering Spirit - In Combat - Cast Wailing Dead");

-- Fellicent's Shade
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10358;
DELETE FROM `smart_scripts` WHERE `entryorguid`=10358 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10358,0,0,0,0,0,100,0,0,0,3400,4700,11,13901,64,0,0,0,0,2,0,0,0,0,0,0,0,"Fellicent\'s Shade - In Combat - Cast Arcane Bolt"),
(10358,0,1,0,9,0,100,0,0,8,12000,17000,11,11975,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fellicent\'s Shade - Within 0-8 Range - Cast Arcane Explosion"),
(10358,0,2,0,0,0,100,0,5000,9000,22000,26000,11,7068,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fellicent\'s Shade - In Combat - Cast Veil of Shadow");

-- Sri'skulk
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10359;
DELETE FROM `smart_scripts` WHERE `entryorguid`=10359 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10359,0,0,0,9,0,100,0,0,5,17000,20000,11,3583,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sri\'skulk - Within 0-5 Range - Cast Deadly Poison");

-- Scarlet Preserver
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4280;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4280 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4280,0,0,0,0,0,100,0,3000,5000,7000,12000,11,13953,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Preserver - In Combat - Cast Holy Strike"),
(4280,0,1,0,14,0,100,0,500,40,12000,18000,11,13952,0,0,0,0,0,7,0,0,0,0,0,0,0,"Scarlet Preserver - Friendly At 500 Health - Cast Holy Light"),
(4280,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Preserver - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Scarlet Scout
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4281;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4281 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4281,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Scout - In Combat - Cast Shoot"),
(4281,0,1,0,9,0,100,0,5,30,9000,13000,11,6979,2,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Scout - Within 5-30 - Cast Fire Shot"),
(4281,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Scout - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Scarlet Magician
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4282;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4282 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4282,0,0,0,0,0,100,0,0,0,3400,4700,11,9053,64,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Magician - In Combat - Cast Fireball"),
(4282,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Magician - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Scarlet Sentry (4283)
DELETE FROM `creature_text` WHERE `CreatureID`=4283;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(4283, 0, 0, 'You carry the taint of the Scourge. Prepare to enter the Twisting Nether.', 12, 0, 100, 0, 0, 0, 2625, 0, 'Scarlet Sentry'),
(4283, 0, 1, 'There is no escape for you. The Crusade shall destroy all who carry the Scourge''s taint.', 12, 0, 100, 0, 0, 0, 2626, 0, 'Scarlet Sentry'),
(4283, 0, 2, 'The Light condemns all who harbor evil. Now you will die!', 12, 0, 100, 0, 0, 0, 2627, 0, 'Scarlet Sentry'),
(4283, 0, 3, 'The Scarlet Crusade shall smite the wicked and drive evil from these lands!', 12, 0, 100, 0, 0, 0, 2628, 0, 'Scarlet Sentry');
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4283;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4283 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(4283, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 3637, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Scarlet Sentry - On Reset - Cast Improved Blocking III'),
(4283, 0, 1, 0, 4, 0, 20, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Scarlet Sentry - On Aggro - Say Line 0'),
(4283, 0, 2, 0, 2, 0, 100, 1, 0, 15, 0, 0, 25, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Scarlet Sentry - Between 0-15% Health - Flee For Assist');

-- Scarlet Disciple
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4285;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4285 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4285,0,0,0,0,0,100,0,0,0,3400,4700,11,9734,64,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Disciple - In Combat - Cast Holy Smite"),
(4285,0,1,0,14,0,100,0,600,40,11000,15000,11,11642,1,0,0,0,0,7,0,0,0,0,0,0,0,"Scarlet Disciple - Friendly At 600 Health - Cast Heal"),
(4285,0,2,0,2,0,100,1,0,50,0,0,11,11640,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Disciple - Between 0-50% Health - Cast Renew (No Repeat)"),
(4285,0,3,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Disciple - Between 0-15% Health - Flee For Assist (No Repeat)");
*/
