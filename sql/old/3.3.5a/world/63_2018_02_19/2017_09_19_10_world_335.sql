-- Murderous Blisterpaw
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8208;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8208 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8208,0,0,0,0,0,100,0,8000,12000,15000,20000,11,3391,0,0,0,0,0,2,0,0,0,0,0,0,0,"Murderous Blisterpaw - In Combat - Cast Thrash"),
(8208,0,1,0,0,0,100,0,12000,18000,15000,22000,11,13445,0,0,0,0,0,2,0,0,0,0,0,0,0,"Murderous Blisterpaw - In Combat - Cast Rend");

-- Scorpid Hunter
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5422;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5422 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5422,0,0,0,0,0,100,0,6000,12000,9000,15000,11,7992,32,0,0,0,0,2,0,0,0,0,0,0,0,"Scorpid Hunter - In Combat - Cast Slowing Poison");

-- Kregg Keelhaul
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8203;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8203 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8203,0,0,0,9,0,100,0,0,5,9000,14000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kregg Keelhaul - Within 0-5 Range - Cast Strike"),
(8203,0,1,0,0,0,100,0,9000,16000,16000,21000,11,40504,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kregg Keelhaul - In Combat - Cast Cleave");

-- Hazzali Worker
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5452;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5452 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5452,0,0,0,2,0,100,1,0,30,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hazzali Worker - Between 0-30% Health - Flee For Assist (No Repeat)"),
(5452,0,1,0,6,0,100,1,0,0,0,0,11,11023,3,0,0,0,0,1,0,0,0,0,0,0,0,"Hazzali Worker - On Death - Cast Summon Hazzali Parasites");

-- Hazzali Tunneler
UPDATE `smart_scripts` SET `event_chance`=100 WHERE `entryorguid`=5453 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5453 AND `id`=1 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5453,0,1,0,6,0,100,1,0,0,0,0,11,11023,3,0,0,0,0,1,0,0,0,0,0,0,0,"Hazzali Tunneler - On Just Died - Cast Summon Hazzali Parasites");

-- Hazzali Sandreaver
UPDATE `smart_scripts` SET `event_chance`=100 WHERE `entryorguid`=5454 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5454 AND `id`=1 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5454,0,1,0,6,0,100,1,0,0,0,0,11,11023,3,0,0,0,0,1,0,0,0,0,0,0,0,"Hazzali Sandreaver - On Just Died - Cast Summon Hazzali Parasites");

-- Searing Roc
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5430;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5430 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5430,0,0,0,0,0,100,0,6000,8000,18000,20000,11,16843,0,0,0,0,0,2,0,0,0,0,0,0,0,"Searing Roc - In Combat - Cast Crimson Fury");

-- Dune Smasher
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5469;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5469 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5469,0,0,0,0,0,100,0,9000,19000,24000,36000,11,9791,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dune Smasher - In Combat - Cast Head Crack");

-- Jin'Zallah the Sandbringer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8200;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8200 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8200,0,0,0,0,0,100,0,0,0,3400,4800,11,20824,64,0,0,0,0,2,0,0,0,0,0,0,0,"Jin\'Zallah the Sandbringer - In Combat - Cast Lightning Bolt"),
(8200,0,1,0,9,0,100,0,0,8,13600,14500,11,7272,1,0,0,0,0,1,0,0,0,0,0,0,0,"Jin\'Zallah the Sandbringer - Within 0-8 Range - Cast Dust Cloud"),
(8200,0,2,0,2,0,100,1,0,55,0,0,11,10132,1,0,0,0,0,1,0,0,0,0,0,0,0,"Jin\'Zallah the Sandbringer - Between 0-55% Health - Cast Sand Storms (No Repeat)");

-- Sand Storm (7226)
DELETE FROM `creature_template_addon` WHERE `entry`=7226;
INSERT INTO `creature_template_addon` (`entry`,`bytes2`,`auras`) VALUES
(7226, 0, "10092");

UPDATE `creature_template` SET `flags_extra`=128, `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=7226;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7226 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(7226, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 89, 12, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sand Storm - just summoned - random movement');

-- Warleader Krazzilak
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8199;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8199 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8199,0,0,0,0,0,100,0,8000,10000,18000,34000,11,6713,0,0,0,0,0,2,0,0,0,0,0,0,0,"Warleader Krazzilak - In Combat - Cast Disarm"),
(8199,0,1,0,0,0,100,0,13000,15000,17000,26000,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,"Warleader Krazzilak - In Combat - Cast Hamstring"),
(8199,0,2,0,0,0,100,0,14000,18000,12000,26000,11,17230,32,0,0,0,0,5,0,0,0,0,0,0,0,"Warleader Krazzilak - In Combat - Cast Infected Wound"),
(8199,0,3,0,0,0,100,0,12000,20000,12000,25000,11,18103,0,0,0,0,0,5,0,0,0,0,0,0,0,"Warleader Krazzilak - In Combat - Cast Backhand");

-- Haarka the Ravenous
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8205;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8205 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8205,0,0,0,0,0,100,0,8000,12000,15000,20000,11,3391,2,0,0,0,0,2,0,0,0,0,0,0,0,"Haarka the Ravenous - In Combat - Cast Thrash"),
(8205,0,1,0,9,0,100,0,0,5,5000,9000,11,21081,0,0,0,0,0,2,0,0,0,0,0,0,0,"Haarka the Ravenous - Within 0-5 Range - Cast Sunder Armor");

-- Caliph Scorpidsting
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7847;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7847 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7847,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Caliph Scorpidsting - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Tick
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8198;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8198 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8198,0,0,0,0,0,100,0,8000,16000,12000,18000,11,21073,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tick - In Combat - Cast Arcane Explosion"),
(8198,0,1,0,0,0,100,0,12000,16000,14000,18000,11,20717,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tick - In Combat - Cast Sand Breath");

-- Chronalis
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8197;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8197 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8197,0,0,0,9,0,100,0,0,5,9000,16000,11,18144,0,0,0,0,0,2,0,0,0,0,0,0,0,"Chronalis - Within 0-5 Range - Cast Swoop"),
(8197,0,1,0,0,0,100,0,12000,16000,14000,18000,11,20717,0,0,0,0,0,2,0,0,0,0,0,0,0,"Chronalis - In Combat - Cast Sand Breath");

-- Occulus
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8196;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8196 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8196,0,0,0,9,0,100,0,0,5,9000,14000,11,18144,0,0,0,0,0,2,0,0,0,0,0,0,0,"Occulus - Within 0-5 Range - Cast Swoop"),
(8196,0,1,0,0,0,100,0,12000,16000,14000,18000,11,20717,0,0,0,0,0,2,0,0,0,0,0,0,0,"Occulus - In Combat - Cast Sand Breath"),
(8196,0,2,0,0,0,100,0,9000,14000,11000,15000,11,10833,0,0,0,0,0,5,0,0,0,0,0,0,0,"Occulus - In Combat - Cast Arcane Blast");
