-- Elder Saltwater Crocolisk
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2635;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2635 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2635,0,0,0,0,0,100,0,3000,8000,13000,24000,11,3604,0,0,0,0,0,2,0,0,0,0,0,0,0,'Elder Saltwater Crocolisk - In Combat - Cast \'Tendon Rip\' (No Repeat)');

-- Bloodscalp Hunter
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=595;
DELETE FROM `smart_scripts` WHERE `entryorguid`=595 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(595,0,0,0,0,0,100,0,0,0,2100,4800,11,10277,64,0,0,0,0,2,0,0,0,0,0,0,0,'Bloodscalp Hunter - In Combat CMC - Cast \'Throw\''),
(595,0,1,0,0,0,100,0,9500,24100,18500,39800,11,6533,0,0,0,0,0,2,0,0,0,0,0,0,0,'Bloodscalp Hunter - In Combat - Cast \'Net\''),
(595,0,2,0,2,0,100,1,0,30,0,0,11,8599,1,0,0,0,0,1,0,0,0,0,0,0,0,'Bloodscalp Hunter - Between 0-30% Health - Cast \'Enrage\' (No Repeat)');

-- Saltscale Oracle
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=873;
DELETE FROM `smart_scripts` WHERE `entryorguid`=873 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(873,0,0,0,0,0,100,0,0,0,3400,4800,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,'Saltscale Oracle - In Combat CMC - Cast \'Lightning Bolt\''),
(873,0,1,0,14,0,100,0,700,40,25000,35000,11,11986,1,0,0,0,0,7,0,0,0,0,0,0,0,'Saltscale Oracle - Friendly At 700 Health - Cast \'Healing Wave\''),
(873,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Saltscale Oracle - Between 0-15% Health - Flee For Assist (No Repeat)');

-- Saltscale Tide Lord
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=875;
DELETE FROM `smart_scripts` WHERE `entryorguid`=875 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(875,0,0,0,0,0,100,0,1000,1000,1800000,1800000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,'Saltscale Tide Lord - Out of Combat - Cast \'Frost Armor\''),
(875,0,1,0,0,0,100,0,0,0,2400,3800,11,9672,64,0,0,0,0,2,0,0,0,0,0,0,0,'Saltscale Tide Lord - In Combat CMC - Cast \'Frostbolt\''),
(875,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Saltscale Tide Lord - Between 0-15% Health - Flee For Assist (No Repeat)');

-- Saltscale Forager
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=877;
DELETE FROM `smart_scripts` WHERE `entryorguid`=877 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(877,0,0,0,9,0,100,0,0,5,20000,30000,11,13443,0,0,0,0,0,2,0,0,0,0,0,0,0,'Saltscale Forager - Within 0-5 Range - Cast \'Rend\''),
(877,0,1,0,0,0,100,0,2000,3000,4000,9000,11,744,32,0,0,0,0,2,0,0,0,0,0,0,0,'Saltscale Forager - In Combat - Cast \'Poison\''),
(877,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'Saltscale Forager - Between 0-15% Health - Flee For Assist (No Repeat)');

-- Saltscale Hunter
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=879;
DELETE FROM `smart_scripts` WHERE `entryorguid`=879 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(879,0,0,0,0,0,100,0,0,0,2600,4800,11,10277,64,0,0,0,0,2,0,0,0,0,0,0,0,'Saltscale Hunter - In Combat CMC - Cast \'Throw\''),
(879,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Saltscale Hunter - Between 0-15% Health - Flee For Assist (No Repeat)');

-- Saltscale Warrior
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=871;
DELETE FROM `smart_scripts` WHERE `entryorguid`=871 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(871,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'Saltscale Warrior - Between 0-15% Health - Flee For Assist (No Repeat)');

-- Kurzen Shadow Hunter
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=979;
DELETE FROM `smart_scripts` WHERE `entryorguid`=979 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(979,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,'Kurzen Shadow Hunter - In Combat CMC - Cast \'Shoot\''),
(979,0,1,0,0,0,100,0,9000,14000,9000,14000,11,8806,32,0,0,0,0,5,0,0,0,0,0,0,0,'Kurzen Shadow Hunter - In Combat - Cast \'Poisoned Shot\''),
(979,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Kurzen Shadow Hunter - Between 0-15% Health - Flee For Assist (No Repeat)');

-- Colonel Kurzen
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=813;
DELETE FROM `smart_scripts` WHERE `entryorguid`=813 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(813,0,0,0,0,0,100,0,8000,12000,18000,25000,11,8817,0,0,0,0,0,1,0,0,0,0,0,0,0,'Colonel Kurzen - In Combat - Cast \'Smoke Bomb\''),
(813,0,1,0,24,0,100,0,8817,0,100,100,11,8818,32,0,0,0,0,2,0,0,0,0,0,0,0,'Colonel Kurzen - On Target Has \'Smoke Bomb\' Aura - Cast \'Garrote\'');

-- Mosh'Ogg Shaman
DELETE FROM `creature_text` WHERE `CreatureID`=679;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(679,0,0,"Raaar!!! Me smash $r!",12,0,100,0,0,0,1927,0,"Mosh\'Ogg Shaman"),
(679,0,1,"Me smash! You die!",12,0,100,0,0,0,1926,0,"Mosh\'Ogg Shaman"),
(679,0,2,"I\'ll crush you!",12,0,100,0,0,0,1925,0,"Mosh\'Ogg Shaman");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=679;
DELETE FROM `smart_scripts` WHERE `entryorguid`=679 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(679,0,0,0,0,0,100,0,6500,10000,9500,12500,11,12058,0,0,0,0,0,2,0,0,0,0,0,0,0,'Mosh\'Ogg Shaman - In Combat - Cast \'Chain Lightning\''),
(679,0,1,0,2,0,100,0,0,30,34000,38000,11,6742,1,0,0,0,0,1,0,0,0,0,0,0,0,'Mosh\'Ogg Shaman - Between 0-30% Health - Cast \'Bloodlust\''),
(679,0,2,0,0,0,100,0,9500,18000,33000,45000,11,11899,0,0,0,0,0,1,0,0,0,0,0,0,0,'Mosh\'Ogg Shaman - In Combat - Cast \'Healing Ward\''),
(679,0,3,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Mosh\'Ogg Shaman - On Aggro - Say Line 0");

-- Verifonix
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=14492;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14492 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14492,0,0,0,9,0,100,0,0,5,23800,28200,11,12097,0,0,0,0,0,2,0,0,0,0,0,0,0,'Verifonix - Within 0-5 Range - Cast \'Pierce Armor\'');

-- Mosh'Ogg Mauler --> Add Texts on Aggro
DELETE FROM `creature_text` WHERE `CreatureID`=678;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(678,0,0,"Raaar!!! Me smash $r!",12,0,100,0,0,0,1927,0,"Mosh\'Ogg Mauler"),
(678,0,1,"Me smash! You die!",12,0,100,0,0,0,1926,0,"Mosh\'Ogg Mauler"),
(678,0,2,"I\'ll crush you!",12,0,100,0,0,0,1925,0,"Mosh\'Ogg Mauler");
DELETE FROM `smart_scripts` WHERE `entryorguid`=678 AND `id`=1 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(678,0,1,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Mosh\'Ogg Mauler - On Aggro - Say Line 0");

-- Mosh'Ogg Lord --> Add Texts on Aggro
DELETE FROM `creature_text` WHERE `CreatureID`=680;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(680,0,0,"Raaar!!! Me smash $r!",12,0,100,0,0,0,1927,0,"Mosh\'Ogg Lord"),
(680,0,1,"Me smash! You die!",12,0,100,0,0,0,1926,0,"Mosh\'Ogg Lord"),
(680,0,2,"I\'ll crush you!",12,0,100,0,0,0,1925,0,"Mosh\'Ogg Lord");
DELETE FROM `smart_scripts` WHERE `entryorguid`=680 AND `id`=1 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(680,0,1,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Mosh\'Ogg Lord - On Aggro - Say Line 0");

-- Mosh'Ogg Warmonger --> Add Texts on Aggro
DELETE FROM `creature_text` WHERE `CreatureID`=709;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(709,0,0,"Raaar!!! Me smash $r!",12,0,100,0,0,0,1927,0,"Mosh\'Ogg Warmonger"),
(709,0,1,"Me smash! You die!",12,0,100,0,0,0,1926,0,"Mosh\'Ogg Warmonger"),
(709,0,2,"I\'ll crush you!",12,0,100,0,0,0,1925,0,"Mosh\'Ogg Warmonger");
DELETE FROM `smart_scripts` WHERE `entryorguid`=709 AND `id`=1 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(709,0,1,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Mosh\'Ogg Warmonger - On Aggro - Say Line 0");

-- Mosh'Ogg Spellcrafter --> Add Texts on Aggro
DELETE FROM `creature_text` WHERE `CreatureID`=710;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(710,0,0,"Raaar!!! Me smash $r!",12,0,100,0,0,0,1927,0,"Mosh\'Ogg Spellcrafter"),
(710,0,1,"Me smash! You die!",12,0,100,0,0,0,1926,0,"Mosh\'Ogg Spellcrafter"),
(710,0,2,"I\'ll crush you!",12,0,100,0,0,0,1925,0,"Mosh\'Ogg Spellcrafter");
DELETE FROM `smart_scripts` WHERE `entryorguid`=710 AND `id`=3 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(710,0,3,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Mosh\'Ogg Spellcrafter - On Aggro - Say Line 0");
