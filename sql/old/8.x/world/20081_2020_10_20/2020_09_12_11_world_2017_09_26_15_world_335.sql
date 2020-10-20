-- Felpaw Wolf
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8959;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8959 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8959,0,0,0,9,0,100,0,0,5,8000,14000,11,3427,32,0,0,0,0,2,0,0,0,0,0,0,0,"Felpaw Wolf - Within 0-5 Range - Cast Infected Wound");

-- Felpaw Scavenger
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8960;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8960 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8960,0,0,0,9,0,100,0,0,5,8000,14000,11,3427,32,0,0,0,0,2,0,0,0,0,0,0,0,"Felpaw Scavenger - Within 0-5 Range - Cast Infected Wound"),
(8960,0,1,0,9,0,100,0,0,5,20000,25000,11,3604,0,0,0,0,0,2,0,0,0,0,0,0,0,"Felpaw Scavenger - Within 0-5 Range - Cast Tendon Rip");

-- Felpaw Ravager
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8961;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8961 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8961,0,0,0,0,0,100,0,8000,12000,15000,20000,11,3391,0,0,0,0,0,2,0,0,0,0,0,0,0,"Felpaw Ravager - In Combat - Cast Thrash"),
(8961,0,1,0,9,0,100,0,0,5,8000,14000,11,3427,32,0,0,0,0,2,0,0,0,0,0,0,0,"Felpaw Ravager - Within 0-5 Range - Cast Infected Wound");

-- Death Howl
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=14339;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14339 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14339,0,0,0,9,0,100,0,0,5,12000,15000,11,3604,0,0,0,0,0,2,0,0,0,0,0,0,0,"Death Howl - Within 0-5 Range - Cast Tendon Rip"),
(14339,0,1,0,0,0,100,0,7000,11000,35000,39000,11,75355,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death Howl - In Combat - Cast Horrifying Howl"),
(14339,0,2,0,0,0,100,0,4000,6000,8000,14000,11,3427,32,0,0,0,0,2,0,0,0,0,0,0,0,"Death Howl - In Combat - Cast Infected Wound");

-- Ironbeak Owl
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7097;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7097 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7097,0,0,0,9,0,100,0,0,5,8000,11000,11,5708,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ironbeak Owl - Within 0-5 Range - Cast Swoop");

-- Ironbeak Screecher
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7098;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7098 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7098,0,0,0,9,0,100,0,0,10,13000,16000,11,3589,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ironbeak Screecher - Within 0-10 Range - Cast Deafening Screech");

-- Ironbeak Hunter
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7099;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7099 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7099,0,0,0,9,0,100,0,0,5,21000,24000,11,13443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ironbeak Hunter - Within 0-5 Range - Cast Rend");

-- Angerclaw Grizzly
DELETE FROM `smart_scripts` WHERE `entryorguid`=8957 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8957,0,2,0,0,0,100,0,6000,8000,12000,16000,11,8716,0,0,0,0,0,2,0,0,0,0,0,0,0,"Angerclaw Grizzly - In Combat - Cast Low Swipe");

-- Angerclaw Mauler
DELETE FROM `smart_scripts` WHERE `entryorguid`=8958 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8958,0,0,0,9,0,100,0,0,5,5000,8000,11,15793,0,0,0,0,0,2,0,0,0,0,0,0,0,"Angerclaw Mauler - Within 0-5 Range - Cast Maul");

-- Deadwood Warrior
DELETE FROM `smart_scripts` WHERE `entryorguid`=7153 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7153,0,1,0,0,0,100,0,4000,11000,12000,15000,11,13583,32,0,0,0,0,2,0,0,0,0,0,0,0,"Deadwood Warrior - In Combat - Cast Curse of the Deadwood");

-- Deadwood Gardener
DELETE FROM `smart_scripts` WHERE `entryorguid`=7154 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7154,0,0,0,0,0,100,0,4000,11000,12000,15000,11,13583,32,0,0,0,0,2,0,0,0,0,0,0,0,"Deadwood Gardener - In Combat - Cast Curse of the Deadwood");

-- Overlord Ror
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=9464;
DELETE FROM `smart_scripts` WHERE `entryorguid`=9464 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(9464,0,0,0,9,0,100,0,0,5,5000,8000,11,15793,0,0,0,0,0,2,0,0,0,0,0,0,0,"Overlord Ror - Within 0-5 Range - Cast Maul"),
(9464,0,1,0,0,0,100,0,8000,12000,17000,21000,11,14100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Overlord Ror - In Combat - Cast Terrifying Roar"),
(9464,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Overlord Ror - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Ragepaw
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=14342;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14342 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14342,0,0,0,9,0,100,0,0,5,6000,9000,11,13584,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ragepaw - Within 0-5 Range - Cast Strike"),
(14342,0,1,0,0,0,100,0,4000,11000,12000,15000,11,13583,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ragepaw - In Combat - Cast Curse of the Deadwood");

-- Jadefire Satyr
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7105;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7105 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7105,0,0,0,0,0,100,0,6000,9000,16000,19000,11,13578,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jadefire Satyr - In Combat - Cast Jadefire");

-- Jadefire Rogue
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7106;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7106 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7106,0,0,0,0,0,100,0,6000,9000,16000,19000,11,13578,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jadefire Rogue - In Combat - Cast Jadefire"),
(7106,0,1,0,67,0,100,0,6000,11000,0,0,11,7159,0,0,0,0,0,2,0,0,0,0,0,0,0,"Jadefire Rogue - On Behind Target - Cast Backstab"),
(7106,0,2,0,0,0,100,0,4000,7000,9000,12000,11,13579,0,0,0,0,0,2,0,0,0,0,0,0,0,"Jadefire Rogue - In Combat - Cast Gouge");

-- Jadefire Trickster
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7107;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7107 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7107,0,0,0,0,0,100,0,5000,9000,21000,25000,11,13338,0,0,0,0,0,4,0,0,0,0,0,0,0,"Jadefire Trickster - In Combat - Cast Curse of Tongues"),
(7107,0,1,0,9,0,100,0,0,30,120000,125000,11,11980,0,0,0,0,0,2,0,0,0,0,0,0,0,"Jadefire Trickster - Within 0-30 Range - Cast Curse of Weakness"),
(7107,0,2,0,0,0,100,0,9000,14000,15000,18000,11,12888,0,0,0,0,0,5,0,0,0,0,0,0,0,"Jadefire Trickster - In Combat - Cast Cause Insanity"),
(7107,0,3,0,0,0,100,0,6000,9000,16000,19000,11,13578,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jadefire Trickster - In Combat - Cast Jadefire");

-- Jadefire Betrayer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7108;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7108 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7108,0,0,0,9,0,100,0,0,5,7000,11000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Jadefire Betrayer - Within 0-5 Range - Cast Cleave"),
(7108,0,1,0,0,0,100,0,5000,8000,18000,22000,11,13443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Jadefire Betrayer - In Combat - Cast Rend"),
(7108,0,2,0,0,0,100,0,6000,9000,16000,19000,11,13578,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jadefire Betrayer - In Combat - Cast Jadefire");

-- Jadefire Felsworn
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7109;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7109 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7109,0,0,0,0,0,100,0,0,0,3400,4700,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Jadefire Felsworn - In Combat - Cast Shadow Bolt"),
(7109,0,1,0,0,0,100,0,6000,9000,16000,19000,11,13578,2,0,0,0,0,1,0,0,0,0,0,0,0,"Jadefire Felsworn - In Combat - Cast Jadefire"),
(7109,0,2,0,0,0,100,0,7000,11000,21000,24000,11,11443,2,0,0,0,0,4,0,0,0,0,0,0,0,"Jadefire Felsworn - In Combat - Cast Cripple");

-- Jadefire Hellcaller
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7111;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7111 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7111,0,0,0,0,0,100,0,0,0,3400,4800,11,20823,64,0,0,0,0,2,0,0,0,0,0,0,0,"Jadefire Hellcaller - In Combat CMC - Cast Fireball"),
(7111,0,1,0,0,0,100,0,9000,13000,18000,22000,11,11990,1,0,0,0,0,4,0,0,0,0,0,0,0,"Jadefire Hellcaller - In Combat - Cast Rain of Fire"),
(7111,0,2,0,0,0,100,0,6000,9000,16000,19000,11,13578,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jadefire Hellcaller - In Combat - Cast Jadefire");

-- Alshirr Banebreath
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=14340;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14340 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14340,0,0,0,0,0,100,0,0,0,3400,4700,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Alshirr Banebreath - In Combat - Cast Shadow Bolt"),
(14340,0,1,0,0,0,100,0,6000,9000,16000,19000,11,13578,2,0,0,0,0,1,0,0,0,0,0,0,0,"Alshirr Banebreath - In Combat - Cast Jadefire"),
(14340,0,2,0,0,0,100,0,9000,13000,19000,22000,11,11962,2,0,0,0,0,4,0,0,0,0,0,0,0,"Alshirr Banebreath - In Combat - Cast Immolate");

-- Tainted Ooze
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7092;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7092 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7092,0,0,0,9,0,100,0,0,5,180000,180000,11,3335,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tainted Ooze - Within 0-5 Range - Cast Dark Sludge");

-- Vile Ooze
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7093;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7093 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7093,0,0,0,0,0,100,0,0,0,3400,4700,11,21067,64,0,0,0,0,2,0,0,0,0,0,0,0,"Vile Ooze - In Combat - Cast Poison Bolt"),
(7093,0,1,0,9,0,100,0,0,5,11000,14000,11,22595,2,0,0,0,0,2,0,0,0,0,0,0,0,"Vile Ooze - Within 0-5 Range - Cast Poison Shock");

-- The Ongar
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=14345;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14345 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14345,0,0,0,9,0,100,0,0,5,180000,180000,11,3335,0,0,0,0,0,2,0,0,0,0,0,0,0,"The Ongar - Within 0-5 Range - Cast Dark Sludge");

-- Jaedenar Cultist
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7112;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7112 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7112,0,0,0,0,0,100,0,0,0,3400,4700,11,20825,64,0,0,0,0,2,0,0,0,0,0,0,0,"Jaedenar Cultist - In Combat - Cast Shadow Bolt"),
(7112,0,1,0,0,0,100,0,9000,14000,22000,25000,11,11639,2,0,0,0,0,4,0,0,0,0,0,0,0,"Jaedenar Cultist - In Combat - Cast Shadow Word: Pain"),
(7112,0,2,0,0,0,100,0,6000,9000,16000,19000,11,11980,2,0,0,0,0,2,0,0,0,0,0,0,0,"Jaedenar Cultist - In Combat - Cast Curse of Weakness"),
(7112,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jaedenar Cultist - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Jaedenar Adept
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7115;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7115 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7115,0,0,0,0,0,100,0,0,0,3400,4700,11,20823,64,0,0,0,0,2,0,0,0,0,0,0,0,"Jaedenar Adept - In Combat - Cast Fireball"),
(7115,0,1,0,0,0,100,0,11000,15000,12000,16000,11,20832,2,0,0,0,0,2,0,0,0,0,0,0,0,"Jaedenar Adept - In Combat - Cast Fire Blast"),
(7115,0,2,0,9,0,100,0,0,5,16000,21000,11,14514,2,0,0,0,0,1,0,0,0,0,0,0,0,"Jaedenar Adept - Within 0-5 Range - Cast Blink"),
(7115,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jaedenar Adept - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Jaedenar Guardian
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7113;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7113 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7113,0,0,0,9,0,100,0,0,5,9000,13000,11,11972,0,0,0,0,0,2,0,0,0,0,0,0,0,"Jaedenar Guardian - Within 0-5 Range - Cast Shield Bash"),
(7113,0,1,0,0,0,100,0,5000,9000,13000,17000,11,3248,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jaedenar Guardian - In Combat - Cast Improved Blocking");

-- Jaedenar Hound
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7125;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7125 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7125,0,0,0,9,0,100,0,0,30,9000,15000,11,13321,0,0,0,0,0,2,0,0,0,0,0,0,0,"Jaedenar Hound - Within 0-30 Range - Cast Mana Burn");

-- Jaedenar Enforcer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7114;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7114 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7114,0,0,0,9,0,100,0,0,5,17000,21000,11,11977,0,0,0,0,0,2,0,0,0,0,0,0,0,"Jaedenar Enforcer - Within 0-5 Range - Cast Rend");

-- Jaedenar Darkweaver
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7118;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7118 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7118,0,0,0,0,0,100,0,0,0,3400,4700,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Jaedenar Darkweaver - In Combat - Cast Shadow Bolt"),
(7118,0,1,0,0,0,100,0,9000,13000,21000,26000,11,11962,2,0,0,0,0,2,0,0,0,0,0,0,0,"Jaedenar Darkweaver - In Combat - Cast Immolate"),
(7118,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jaedenar Darkweaver - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Jaedenar Legionnaire
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=9862;
DELETE FROM `smart_scripts` WHERE `entryorguid`=9862 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(9862,0,0,0,9,0,100,0,0,8,12000,17000,11,10966,0,0,0,0,0,2,0,0,0,0,0,0,0,"Jaedenar Legionnaire - Within 0-8 Range - Cast Uppercut");

-- Prince Xavalis
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=9877;
DELETE FROM `smart_scripts` WHERE `entryorguid`=9877 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(9877,0,0,0,0,0,100,0,9000,13000,19000,22000,11,11962,0,0,0,0,0,2,0,0,0,0,0,0,0,"Prince Xavalis - In Combat - Cast Immolate"),
(9877,0,1,0,0,0,100,0,6000,9000,16000,19000,11,13578,0,0,0,0,0,2,0,0,0,0,0,0,0,"Prince Xavalis - In Combat - Cast Jadefire");

-- Rakaiah
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=9518;
DELETE FROM `smart_scripts` WHERE `entryorguid`=9518 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(9518,0,0,0,9,0,100,0,0,5,5000,9000,11,15968,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rakaiah - Within 0-5 Range - Cast Lash of Pain"),
(9518,0,1,0,0,0,100,0,5000,8000,14000,19000,11,17227,32,0,0,0,0,2,0,0,0,0,0,0,0,"Rakaiah - In Combat - Cast Curse of Weakness");

-- Shadow Lord Feldan
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=9517;
DELETE FROM `smart_scripts` WHERE `entryorguid`=9517 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(9517,0,0,0,0,0,100,0,0,0,3400,4700,11,20825,64,0,0,0,0,2,0,0,0,0,0,0,0,"Shadow Lord Feldan - In Combat - Cast Shadow Bolt"),
(9517,0,1,0,0,0,100,0,9000,14000,11000,15000,11,9081,2,0,0,0,0,1,0,0,0,0,0,0,0,"Shadow Lord Feldan - In Combat - Cast Shadow Bolt Volley"),
(9517,0,2,0,0,0,100,0,12000,16000,10000,13000,11,16583,2,0,0,0,0,2,0,0,0,0,0,0,0,"Shadow Lord Feldan - In Combat - Cast Shadow Shock");

-- Ur'dan
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=14522;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14522 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14522,0,0,0,1,0,100,1,1000,1000,0,0,11,11939,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ur\'dan - Out of Combat - Cast Summon Imp (No Repeat)"),
(14522,0,1,0,0,0,100,0,0,0,2400,3800,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ur\'dan - In Combat CMC - Cast Shadow Bolt"),
(14522,0,2,0,2,0,100,1,0,30,0,0,11,8699,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ur\'dan - Between 0-30% Health - Cast Unholy Frenzy (No Repeat)"),
(14522,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ur\'dan - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Entropic Beast
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=9878;
DELETE FROM `smart_scripts` WHERE `entryorguid`=9878 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(9878,0,0,0,9,0,100,0,0,30,25000,28000,11,15661,0,0,0,0,0,2,0,0,0,0,0,0,0,"Entropic Beast - Within 0-30 Range - Cast Immolate");

-- Immolatus
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7137;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7137 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7137,0,0,0,9,0,100,0,0,8,10000,14000,11,10101,0,0,0,0,0,2,0,0,0,0,0,0,0,"Immolatus - Within 0-8 Range - Cast Knock Away");

-- Toxic Horror
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7132;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7132 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7132,0,0,0,9,0,100,0,0,5,8000,16000,11,7947,0,0,0,0,0,2,0,0,0,0,0,0,0,"Toxic Horror - Within 0-5 Range - Cast Localized Toxin"),
(7132,0,1,0,0,0,100,0,6000,9000,12000,18000,11,13582,0,0,0,0,0,2,0,0,0,0,0,0,0,"Toxic Horror - In Combat - Cast Deadly Poison");

-- Warpwood Moss Flayer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7100 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7100,0,0,0,9,0,100,0,0,30,21000,25000,11,11922,0,0,0,0,0,4,0,0,0,0,0,0,0,"Warpwood Moss Flayer - Within 0-30 Range - Cast Entangling Roots");

-- Warpwood Shredder
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7101;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7101 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7101,0,0,0,0,0,100,0,8000,12000,15000,20000,11,3391,0,0,0,0,0,2,0,0,0,0,0,0,0,"Warpwood Shredder - In Combat - Cast Thrash"),
(7101,0,1,0,9,0,100,0,0,5,8000,12000,11,13444,0,0,0,0,0,2,0,0,0,0,0,0,0,"Warpwood Shredder - Within 0-5 Range - Cast Sunder Armor");

-- Dessecus
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7104;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7104 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7104,0,0,0,9,0,100,0,0,30,6000,10000,11,12058,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dessecus - Within 0-30 Range - Cast Chain Lightning"),
(7104,0,1,0,0,0,100,0,6000,11000,16000,21000,11,8293,0,0,0,0,0,4,0,0,0,0,0,0,0,"Dessecus - In Combat - Cast Lightning Cloud");

-- Deadwood Den Watcher
DELETE FROM `smart_scripts` WHERE `entryorguid`=7156 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7156,0,0,0,0,0,100,0,4000,11000,12000,15000,11,13583,32,0,0,0,0,2,0,0,0,0,0,0,0,"Deadwood Warrior - In Combat - Cast Curse of the Deadwood");

-- Deadwood Avenger
DELETE FROM `smart_scripts` WHERE `entryorguid`=7157 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7157,0,0,0,0,0,100,0,4000,11000,12000,15000,11,13583,32,0,0,0,0,2,0,0,0,0,0,0,0,"Deadwood Warrior - In Combat - Cast Curse of the Deadwood");

-- Deadwood Shaman
DELETE FROM `smart_scripts` WHERE `entryorguid`=7158 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7158,0,0,0,0,0,100,0,0,0,3400,4700,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Deadwood Shaman - In Combat - Cast Lightning Bolt"),
(7158,0,1,0,0,0,100,0,4000,11000,12000,15000,11,13583,2,0,0,0,0,4,0,0,0,0,0,0,0,"Deadwood Shaman - In Combat - Cast Curse of the Deadwood"),
(7158,0,2,0,0,0,100,0,5500,9500,6500,9500,11,12058,2,0,0,0,0,4,0,0,0,0,0,0,0,"Deadwood Shaman - In Combat - Cast Chain Lightning"),
(7158,0,3,0,1,0,100,0,500,1000,600000,600000,11,13585,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deadwood Shaman - Out of Combat - Cast Lightning Shield"),
(7158,0,4,0,16,0,100,0,13585,1,15000,30000,11,13585,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deadwood Shaman - On Friendly Unit Missing Buff Lightning Shield - Cast Lightning Shield");

-- Winterfall Runner
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10916;
DELETE FROM `smart_scripts` WHERE `entryorguid`=10916 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10916,0,0,0,1,0,100,0,1000,1000,1200000,1200000,11,17205,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterfall Runner - Out of Combat - Cast Winterfall Firewater");
