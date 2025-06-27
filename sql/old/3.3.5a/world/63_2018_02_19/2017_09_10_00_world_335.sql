-- 
-- Cliff Stormer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4008;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4008 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4008,0,0,0,0,0,100,0,3000,5000,6000,8000,11,5401,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cliff Stormer - In Combat - Cast Lizard Bolt");

-- Raging Cliff Stormer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4009;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4009 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4009,0,0,0,4,0,100,0,0,0,0,0,11,6268,0,0,0,0,0,2,0,0,0,0,0,0,0,"Raging Cliff Stormer - On Aggro - Cast Rushing Charge"),
(4009,0,1,0,9,0,100,0,0,8,12000,15000,11,8078,0,0,0,0,0,1,0,0,0,0,0,0,0,"Raging Cliff Stormer - Within 0-8 Range - Cast Thunderclap");

-- Sorrow Wing
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5928;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5928 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5928,0,0,0,9,0,100,0,0,5,6000,12000,11,3388,32,0,0,0,0,2,0,0,0,0,0,0,0,"Sorrow Wing - In Combat - Cast Deadly Leech Poison"),
(5928,0,1,0,0,0,100,0,11000,18000,12000,15000,11,3405,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sorrow Wing - IC - Cast Soul Rend");

-- Deepmoss Webspinner
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4006;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4006 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4006,0,0,0,9,0,100,0,0,30,8000,12000,11,745,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deepmoss Webspinner - In Combat - Cast Web");

-- Deepmoss Venomspitter
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4007;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4007 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4007,0,0,0,0,0,100,0,0,0,2300,3900,11,7951,64,0,0,0,0,2,0,0,0,0,0,0,0,"Deepmoss Venomspitter - In Combat - Cast Toxic Spit");

-- Young Pridewing
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4011;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4011 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4011,0,0,0,0,0,100,0,5000,8000,12000,18000,11,744,32,0,0,0,0,2,0,0,0,0,0,0,0,"Young Pridewing - In Combat - Cast Poison");

-- Pridewing Patriarch
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4015;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4015 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4015,0,0,0,0,0,100,0,5000,8000,12000,18000,11,744,32,0,0,0,0,2,0,0,0,0,0,0,0,"Pridewing Patriarch - In Combat - Cast Poison");

-- Pridewing Wyvern
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4012;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4012 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4012,0,0,0,0,0,100,0,5000,8000,12000,18000,11,744,32,0,0,0,0,2,0,0,0,0,0,0,0,"Pridewing Wyvern - In Combat - Cast Poison");

-- Pridewing Skyhunter
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4013;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4013 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4013,0,0,0,0,0,100,0,3000,5000,12000,18000,11,744,32,0,0,0,0,2,0,0,0,0,0,0,0,"Pridewing Skyhunter - In Combat - Cast Poison"),
(4013,0,1,0,0,0,100,0,5000,8000,9000,12000,11,5708,0,0,0,0,0,2,0,0,0,0,0,0,0,"Pridewing Skyhunter - In Combat - Cast Swoop");

-- Deepmoss Hatchling
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4263;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4263 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4263,0,0,0,2,0,50,1,0,30,0,0,11,6536,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deepmoss Hatchling - At 30% HP - Summon Deepmoss Matriarch");

-- Venture Co. Logger
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3989;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3989 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3989,0,0,0,0,0,100,0,0,0,2300,3900,11,10277,64,0,0,0,0,2,0,0,0,0,0,0,0,"Venture Co. Logger - In Combat CMC - Cast Throw"),
(3989,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Venture Co. Logger - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Venture Co. Operator
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3988;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3988 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3988,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Venture Co. Operator - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Venture Co. Deforester
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3991;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3991 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3991,0,0,0,0,0,100,0,0,0,3400,4800,11,20793,64,0,0,0,0,2,0,0,0,0,0,0,0,"Venture Co. Deforester - In Combat - Cast Fireball"),
(3991,0,1,0,0,0,100,0,9000,16000,18000,24000,11,5740,0,0,0,0,0,2,0,0,0,0,0,0,0,"Venture Co. Deforester - In Combat - Cast Rain of Fire"),
(3991,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Venture Co. Deforester - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Venture Co. Engineer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3992;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3992 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3992,0,0,0,0,0,100,0,0,0,2300,3900,11,7978,64,0,0,0,0,2,0,0,0,0,0,0,0,"Venture Co. Engineer - In Combat CMC - Cast Throw Dynamite"),
(3992,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Venture Co. Engineer - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Venture Co. Machine Smith
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3993;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3993 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3993,0,0,0,0,0,100,0,5000,9000,70000,85000,11,7979,0,0,0,0,0,1,0,0,0,0,0,0,0,"Venture Co. Machine Smith - IC - Cast Compact Harvest Reaper"),
(3993,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Venture Co. Machine Smith - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Venture Co. Builder
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4070;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4070 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4070,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Venture Co. Builder - In Combat CMC - Cast Shoot"),
(4070,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Venture Co. Builder - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Taskmaster Whipfang
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5932;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5932 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5932,0,0,0,9,0,100,0,0,8,15000,19000,11,16508,0,0,0,0,0,2,0,0,0,0,0,0,0,"Taskmaster Whipfang - Within 0-8 Range - Cast Intimidating Roar"),
(5932,0,1,0,2,0,100,1,0,20,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Taskmaster Whipfang - Between 0-20% Health - Flee For Assist (No Repeat)");

-- Foreman Rigger
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5931;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5931 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5931,0,0,0,9,0,100,0,0,20,15500,25300,11,6533,0,0,0,0,0,2,0,0,0,0,0,0,0,"Foreman Rigger - Within 0-20 Range - Cast Net"),
(5931,0,1,0,9,0,100,0,0,5,45000,45000,11,6016,0,0,0,0,0,2,0,0,0,0,0,0,0,"Foreman Rigger - Within 0-5 Range - Cast Pierce Armor");

-- Windshear Tunnel Rat
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4001;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4001 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4001,0,0,0,0,0,100,0,4000,11000,7000,15000,11,8139,32,0,0,0,0,2,0,0,0,0,0,0,0,"Windshear Tunnel Rat - In Combat - Cast Fevered Fatigue");

-- Windshear Stonecutter
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4002;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4002 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4002,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Windshear Stonecutter - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Windshear Geomancer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4003;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4003 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4003,0,0,0,0,0,100,0,0,0,3400,4800,11,20792,64,0,0,0,0,2,0,0,0,0,0,0,0,"Windshear Geomancer - In Combat CMC - Cast Frostbolt"),
(4003,0,1,0,0,0,100,0,4000,11000,7000,15000,11,8139,32,0,0,0,0,2,0,0,0,0,0,0,0,"Windshear Geomancer - In Combat - Cast Fevered Fatigue"),
(4003,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Windshear Geomancer - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Windshear Overlord
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4004;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4004 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4004,0,0,0,0,0,100,0,1000,3000,30000,45000,11,3631,0,0,0,0,0,1,0,0,0,0,0,0,0,"Windshear Overlord - In Combat - Cast Battle Fury"),
(4004,0,1,0,0,0,100,0,4000,11000,7000,15000,11,8139,32,0,0,0,0,2,0,0,0,0,0,0,0,"Windshear Overlord - In Combat - Cast Fevered Fatigue"),
(4004,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Windshear Overlord - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Grimtotem Brute
UPDATE `creature_template` SET `AIname`="SmartAI" WHERE `entry`=11912;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11912 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11912,0,0,0,4,0,100,0,0,0,0,0,11,6268,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grimtotem Brute - On Aggro - Cast RushIng Charge"),
(11912,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Brute - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Grimtotem Sorcerer
UPDATE `creature_template` SET `AIname`="SmartAI" WHERE `entry`=11913;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11913 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11913,0,0,0,0,0,100,0,0,0,3400,4800,11,20802,64,0,0,0,0,2,0,0,0,0,0,0,0,"Grimtotem Sorcerer - In Combat - Cast LightnIng Bolt"),
(11913,0,1,0,2,0,100,0,0,50,18000,21000,11,12160,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Sorcerer - Between 0-50% Health - Cast Rejuvenation"),
(11913,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Sorcerer - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Grimtotem Ruffian
UPDATE `creature_template` SET `AIname`="SmartAI" WHERE `entry`=11910;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11910 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11910,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Ruffian - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Grimtotem Mercenary
UPDATE `creature_template` SET `AIname`="SmartAI" WHERE `entry`=11911;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11911 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11911,0,0,0,0,0,100,0,0,0,2300,3900,11,10277,64,0,0,0,0,2,0,0,0,0,0,0,0,"Grimtotem Mercenary - In Combat - Cast Throw"),
(11911,0,1,0,9,0,100,0,0,5,7000,11000,11,12555,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grimtotem Mercenary - Within 0-5 Range - Cast Pummel"),
(11911,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Mercenary - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Rogue Flame Spirit
UPDATE `creature_template` SET `AIname`="SmartAI" WHERE `entry`=4036;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4036 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4036,0,0,0,9,0,100,0,0,30,120000,125000,11,6205,32,0,0,0,0,2,0,0,0,0,0,0,0,"Rogue Flame Spirit - Within 0-30 Range - Cast Curse of Weakness"),
(4036,0,1,0,0,0,100,0,5000,9000,18000,22000,11,1094,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rogue Flame Spirit - In Combat - Cast Immolate");

-- Charred Ancient
UPDATE `creature_template` SET `AIname`="SmartAI" WHERE `entry`=4028;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4028 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4028,0,0,0,9,0,100,0,0,30,14000,20000,11,12747,0,0,0,0,0,2,0,0,0,0,0,0,0,"Charred Ancient - Within 0-30 Range - Cast Entangling Roots");

-- Burning Ravager
UPDATE `creature_template` SET `AIname`="SmartAI" WHERE `entry`=4037;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4037 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4037,0,0,0,0,0,100,0,1000,3000,60000,65000,11,184,0,0,0,0,0,1,0,0,0,0,0,0,0,"BurnIng Ravager - In Combat - Cast Fire Shield II");

-- Young Chimaera
UPDATE `creature_template` SET `AIname`="SmartAI" WHERE `entry`=4032;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4032 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4032,0,0,0,0,0,100,0,3000,4000,6000,8000,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Young Chimaera - In Combat CMC - Cast Lightning Bolt");

-- Fledgling Chimaera
UPDATE `creature_template` SET `AIname`="SmartAI" WHERE `entry`=4031;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4031 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4031,0,0,0,9,0,100,0,0,30,8000,16000,11,3396,32,0,0,0,0,2,0,0,0,0,0,0,0,"Fledgling Chimaera - Within 0-30 Range - Cast Corrosive Poison");

-- Sap Beast
UPDATE `creature_template` SET `AIname`="SmartAI" WHERE `entry`=4020;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4020 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4020,0,0,0,9,0,100,0,0,5,7000,16000,11,7997,32,0,0,0,0,2,0,0,0,0,0,0,0,"Sap Beast - Within 0-5 Range - Cast Sap Might");

-- Corrosive Sap Beast
UPDATE `creature_template` SET `AIname`="SmartAI" WHERE `entry`=4021;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4021 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4021,0,0,0,9,0,100,0,0,30,5000,11000,11,3396,32,0,0,0,0,2,0,0,0,0,0,0,0,"Corrosive Sap Beast - Within 0-30 Range - Cast Corrosive Poison");

-- Vengeful Ancient
UPDATE `creature_template` SET `AIname`="SmartAI" WHERE `entry`=4030;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4030 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4030,0,0,0,9,0,100,0,0,5,17000,25000,11,6909,32,0,0,0,0,2,0,0,0,0,0,0,0,"Vengeful Ancient - Within 0-5 Range - Cast Curse of Thorns");

-- Burning Destroyer
UPDATE `creature_template` SET `AIname`="SmartAI" WHERE `entry`=4038;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4038 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4038,0,0,0,0,0,100,0,0,0,3400,4800,11,9053,64,0,0,0,0,2,0,0,0,0,0,0,0,"Burning Destroyer - In Combat CMC - Cast Fireball"),
(4038,0,1,0,0,0,100,0,7000,11000,13000,16000,11,8000,0,0,0,0,0,2,0,0,0,0,0,0,0,"Burning Destroyer - In Combat CMC - Cast Area Burn");

-- Sister Riven
UPDATE `creature_template` SET `AIname`="SmartAI" WHERE `entry`=5930;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5930 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5930,0,0,0,4,0,100,1,0,0,0,0,11,184,2,0,0,0,0,1,0,0,0,0,0,0,0,"Sister Riven - On Aggro - Cast Fire Shield"),
(5930,0,1,0,9,0,100,0,0,20,8000,12000,11,3356,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sister Riven - Within 0-20 Range - Cast Flame Lash"),
(5930,0,2,0,0,0,100,0,7000,10000,30000,30000,11,6725,0,0,0,0,0,4,0,0,0,0,0,0,0,"Sister Riven - In Combat - Cast Flame Spike");

-- Fey Dragon
UPDATE `creature_template` SET `AIname`="SmartAI" WHERE `entry`=4016;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4016 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4016,0,0,0,9,0,100,1,0,30,0,0,11,7994,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fey Dragon - Within 0-30 Range - Cast Nullify Mana (No Repeat)");

-- Wily Fey Dragon
UPDATE `creature_template` SET `AIname`="SmartAI" WHERE `entry`=4017;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4017 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4017,0,0,0,9,0,100,0,0,30,8000,11000,11,17630,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wily Fey Dragon - Within 0-30 Range - Cast Mana Burn");

-- Cenarion Botanist
UPDATE `creature_template` SET `AIname`="SmartAI" WHERE `entry`=4051;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4051 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4051,0,0,0,0,0,100,0,0,0,3400,4800,11,9739,64,0,0,0,0,2,0,0,0,0,0,0,0,"Cenarion Botanist - In Combat CMC - Cast Wrath"),
(4051,0,1,0,2,0,100,0,0,50,16100,17400,11,1430,1,0,0,0,0,1,0,0,0,0,0,0,0,"Cenarion Botanist - Between 0-50% Health - Cast Rejuvenation"),
(4051,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Cenarion Botanist - Between 0-15% Health - Flee for Assist (No Repeat)");

-- Cenarion Caretaker
UPDATE `creature_template` SET `AIname`="SmartAI" WHERE `entry`=4050;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4050 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4050,0,0,0,1,0,100,0,0,0,300000,300000,11,7090,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cenarion Caretaker - Out of Combat - Cast Bear Form"),
(4050,0,1,0,4,0,100,1,0,0,0,0,11,782,1,0,0,0,0,1,0,0,0,0,0,0,0,"Cenarion Caretaker - On Aggro - Cast Thorns"),
(4050,0,2,0,9,0,100,0,0,5,7000,10000,11,12161,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cenarion Caretaker - Within 0-5 Range - Cast Maul"),
(4050,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Cenarion Protector - Between 0-15% Health - Flee for Assist (No Repeat)"),
(4050,0,4,0,2,0,100,1,0,15,0,0,28,7090,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cenarion Protector - Between 0-15% Health - Remove Bear Form");

-- Gatekeeper Kordurus
UPDATE `creature_template` SET `AIname`="SmartAI" WHERE `entry`=4409;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4409 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4409,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gatekeeper Kordurus - Between 0-15% Health - Flee for Assist (No Repeat)");

-- Rynthariel the Keymaster
UPDATE `creature_template` SET `AIname`="SmartAI" WHERE `entry`=8518;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8518 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8518,0,0,0,0,0,100,0,0,0,2300,3900,11,10277,64,0,0,0,0,2,0,0,0,0,0,0,0,"Rynthariel the Keymaster - In Combat CMC - Cast Throw"),
(8518,0,1,0,9,0,100,0,0,30,10000,16000,11,7992,32,0,0,0,0,2,0,0,0,0,0,0,0,"Rynthariel the Keymaster - Within 0-30 Range - Cast Slowing Poison"),
(8518,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rynthariel the Keymaster - Between 0-15% Health - Flee for Assist (No Repeat)");

-- Cenarion Druid
UPDATE `creature_template` SET `AIname`="SmartAI" WHERE `entry`=4052;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4052 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4052,0,0,0,4,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cenarion Druid - On Aggro - Set Event Phase 1"),
(4052,0,1,0,0,1,100,0,0,0,3400,4700,11,9739,64,0,0,0,0,2,0,0,0,0,0,0,0,"Cenarion Druid - In Combat (Phase 1) - Cast Wrath"),
(4052,0,2,0,2,0,100,1,0,50,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cenarion Druid - Between 0-50% Health - Set Event Phase 2"),
(4052,0,3,0,0,2,100,1,0,0,0,0,11,5759,1,0,0,0,0,1,0,0,0,0,0,0,0,"Cenarion Druid - In Combat (Phase 2) - Cast Cat Form"),
(4052,0,5,0,0,2,100,1,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cenarion Druid - In Combat (Phase 2) - Enable Combat Movement"),
(4052,0,4,0,0,2,100,0,12000,16000,30000,35000,11,5217,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cenarion Druid - In Combat (Phase 2) - Cast Tiger\'s Fury");

-- Mirkfallon Dryad
UPDATE `creature_template` SET `AIname`="SmartAI" WHERE `entry`=4061;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4061 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4061,0,0,0,0,0,100,0,0,0,2300,3900,11,10277,64,0,0,0,0,2,0,0,0,0,0,0,0,"Mirkfallon Dryad - In Combat CMC - Cast Throw"),
(4061,0,1,0,9,0,100,0,0,30,10000,16000,11,7992,32,0,0,0,0,2,0,0,0,0,0,0,0,"Mirkfallon Dryad - Within 0-30 Range - Cast Slowing Poison"),
(4061,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mirkfallon Dryad - Between 0-15% Health - Flee for Assist (No Repeat)");

-- Brother Ravenoak
UPDATE `creature_template` SET `AIname`="SmartAI" WHERE `entry`=5915;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5915 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5915,0,0,0,4,0,100,1,0,0,0,0,11,7090,0,0,0,0,0,1,0,0,0,0,0,0,0,"Brother Ravenoak - On Aggro - Cast Bear Form"),
(5915,0,1,0,9,0,100,0,0,5,12000,15000,11,12161,0,0,0,0,0,2,0,0,0,0,0,0,0,"Brother Ravenoak - Within 0-5 Range - Cast Maul"),
(5915,0,2,0,9,0,100,0,0,5,17000,22000,11,8716,0,0,0,0,0,2,0,0,0,0,0,0,0,"Brother Ravenoak - Within 0-5 Range - Cast Low Swipe"),
(5915,0,3,0,1,0,100,0,30000,30000,480000,480000,11,7090,0,0,0,0,0,1,0,0,0,0,0,0,0,"Brother Ravenoak - Out of Combat - Cast Bear Form"),
(5915,0,4,0,2,0,100,0,0,75,21000,26000,11,2090,0,0,0,0,0,1,0,0,0,0,0,0,0,"Brother Ravenoak - Between 0-75% Health - Cast Rejuvenation");

-- Mirkfallon Keeper
UPDATE `creature_template` SET `AIname`="SmartAI" WHERE `entry`=4056;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4056 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4056,0,0,0,9,0,100,0,0,30,14000,26000,11,8138,32,0,0,0,0,2,0,0,0,0,0,0,0,"Mirkfallon Keeper - Within 0-5 Range - Cast Mirkfallon Fungus");

-- Nal'taszar
UPDATE `creature_template` SET `AIname`="SmartAI" WHERE `entry`=4066;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4066 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4066,0,0,0,9,0,100,0,0,30,11000,18000,11,8211,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nal\'taszar - Within 0-30 Range - Cast Chain Burn"),
(4066,0,1,0,0,0,100,0,8000,13000,12000,15000,11,15305,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nal\'taszar - In Combat - Cast Chain Lightning");

-- Gogger Rock Keeper
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11915;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11915 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11915,0,0,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gogger Rock Keeper - On Aggro - Say Line 0"),
(11915,0,1,0,9,0,100,0,0,20,9000,15000,11,13281,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gogger Rock Keeper - In Combat - Cast Earth Shock"),
(11915,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gogger Rock Keeper - Between 0-15% Health - Flee For Assist (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID`=11915;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(11915,0,0,"You no take candle!",12,0,100,0,0,0,16658,0,"Gogger Rock Keeper"),
(11915,0,1,"Yiieeeee! Me run!",12,0,100,0,0,0,1864,0,"Gogger Rock Keeper"),
(11915,0,2,"No kill me! No kill me!",12,0,100,0,0,0,1863,0,"Gogger Rock Keeper");

-- Gogger Geomancer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11917;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11917 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11917,0,0,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gogger Geomancer - On Aggro - Say Line 0"),
(11917,0,1,0,0,0,100,0,0,0,3400,4800,11,20793,64,0,0,0,0,2,0,0,0,0,0,0,0,"Gogger Geomancer - In Combat - Cast Fireball"),
(11917,0,2,0,0,0,100,0,11000,17000,12000,18000,11,11990,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gogger Geomancer - In Combat - Cast Rain of Fire");

DELETE FROM `creature_text` WHERE `CreatureID`=11917;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(11917,0,0,"You NO take candle!",12,0,100,0,0,0,16658,0,"Gogger Geomancer"),
(11917,0,1,"Yiieeeee! Me run!",12,0,100,0,0,0,1864,0,"Gogger Geomancer"),
(11917,0,2,"No kill me! No kill me!",12,0,100,0,0,0,1863,0,"Gogger Geomancer");

-- Gogger Stonepounder
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11918;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11918 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11918,0,0,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gogger Stonepounder - On Aggro - Say Line 0"),
(11918,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gogger Stonepounder - Between 0-15% Health - Flee For Assist (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID`=11918;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(11918,0,0,"You NO take candle!",12,0,100,0,0,0,16658,0,"Gogger Stonepounder"),
(11918,0,1,"Yiieeeee! Me run!",12,0,100,0,0,0,1864,0,"Gogger Stonepounder"),
(11918,0,2,"No kill me! No kill me!",12,0,100,0,0,0,1863,0,"Gogger Stonepounder");
