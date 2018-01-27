/*
-- Glassweb Spider
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5856;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5856 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5856,0,0,0,25,0,100,0,0,0,0,0,11,13299,0,0,0,0,0,1,0,0,0,0,0,0,0,"Glassweb Spider - On Reset - Cast Poison Proc"),
(5856,0,1,0,9,0,100,0,0,20,8000,11000,11,745,0,0,0,0,0,2,0,0,0,0,0,0,0,"Glassweb Spider - Within 0-20 Range - Cast Web");

-- Shleipnarr
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8280;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8280 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8280,0,0,0,0,0,100,0,3000,4000,12000,15000,11,13321,0,0,0,0,0,5,0,0,0,0,0,0,0,"Shleipnarr - In Combat - Cast Mana Burn"),
(8280,0,1,0,0,0,100,0,8000,10000,25000,32000,11,7399,0,0,0,0,0,5,0,0,0,0,0,0,0,"Shleipnarr - In Combat - Cast Terrify");

-- Dark Iron Geologist
UPDATE `smart_scripts` SET `event_param3`=3000, `event_param4`=5000 WHERE `entryorguid`=5839 AND `source_type`=0 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5839 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5839,0,1,0,9,0,100,0,5,30,12000,14000,11,8858,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Iron Geologist - Within 5-30 Range - Cast Bomb");

-- Magma Elemental
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5855;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5855 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5855,0,0,0,0,0,100,0,5000,9000,12000,16000,11,11970,2,0,0,0,0,2,0,0,0,0,0,0,0,"Magma Elemental - In Combat - Cast Fire Nova");

-- Heavy War Golem
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5854;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5854 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5854,0,0,0,9,0,100,0,0,5,13000,19000,11,12612,0,0,0,0,0,1,0,0,0,0,0,0,0,"Heavy War Golem - Within 0-5 Range - Cast Stomp"),
(5854,0,1,0,0,0,100,0,5000,8000,11000,17000,11,5568,0,0,0,0,0,1,0,0,0,0,0,0,0,"Heavy War Golem - In Combat - Cast Trample");

-- Inferno Elemental
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5852;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5852 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5852,0,0,0,0,0,100,0,6000,9000,11000,14000,11,10733,0,0,0,0,0,2,0,0,0,0,0,0,0,"Inferno Elemental - In Combat - Cast Flame Spray");

-- Margol the Rager
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5833;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5833 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5833,0,0,0,0,0,100,0,3000,5000,8000,14000,11,15549,0,0,0,0,0,2,0,0,0,0,0,0,0,"Margol the Rager - In Combat - Cast Chained Bolt"),
(5833,0,1,0,0,0,100,0,8000,12000,16000,20000,11,8147,0,0,0,0,0,1,0,0,0,0,0,0,0,"Margol the Rager - In Combat - Cast Thunderclap");

-- Rekk'tilac
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8277;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8277 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8277,0,0,0,0,0,100,0,7000,9000,16000,18000,11,3583,2,0,0,0,0,2,0,0,0,0,0,0,0,"Rekk'tilac - In Combat - Cast Deadly Poison");

-- Scald
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8281;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8281 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8281,0,0,0,0,0,100,0,3000,5000,14000,16000,11,11962,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scald - In Combat - Cast Immolate");

-- Greater Lava Spider
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5858;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5858 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5858,0,0,0,0,0,100,0,1000,5000,7000,13000,11,11985,0,0,0,0,0,2,0,0,0,0,0,0,0,"Greater Lava Spider - In Combat - Cast Fireball");

-- Slave Worker
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5843;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5843 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5843,0,0,0,0,0,100,0,5000,7000,12000,15000,11,11971,0,0,0,0,0,2,0,0,0,0,0,0,0,"Slave Worker - In Combat - Cast Sunder Armor"),
(5843,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Slave Worker - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Smoldar
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8278;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8278 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8278,0,0,0,0,0,100,0,7000,9000,17000,19000,11,5213,0,0,0,0,0,2,0,0,0,0,0,0,0,"Smoldar - In Combat - Cast Molten Metal");

-- Twilight Fire Guard
UPDATE `creature_template` SET `unit_class`=2, `AIName`="SmartAI" WHERE `entry`=5861;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5861 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5861,0,0,0,0,0,100,0,4000,12000,18000,22000,11,11988,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Fire Guard - In Combat - Cast Fireball Volley"),
(5861,0,1,0,4,0,100,0,0,0,0,0,11,18968,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Fire Guard - On Aggro - Cast Fire Shield");

-- Twilight Dark Shaman
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5860;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5860 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5860,0,0,0,0,0,100,0,3000,5000,10000,14000,11,11824,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Dark Shaman - In Combat - Cast Shock"),
(5860,0,1,0,0,0,100,0,7000,9000,15000,25000,11,7289,32,0,0,0,0,5,0,0,0,0,0,0,0,"Twilight Dark Shaman - In Combat - Cast Shrink"),
(5860,0,2,0,14,0,100,0,700,40,16000,20000,11,11986,0,0,0,0,0,7,0,0,0,0,0,0,0,"Twilight Dark Shaman - On Aggro - Cast Healing Wave");

-- Twilight Geomancer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5862;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5862 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5862,0,0,0,0,0,100,0,0,0,3000,5000,11,9053,64,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Geomancer - In Combat - Cast Fireball"),
(5862,0,1,0,0,0,100,0,7000,11000,18000,24000,11,11990,0,0,0,0,0,5,0,0,0,0,0,0,0,"Twilight Geomancer - In Combat - Cast Rain of Fire"),
(5862,0,2,0,0,0,100,0,9000,13000,15000,19000,11,11436,0,0,0,0,0,5,0,0,0,0,0,0,0,"Twilight Geomancer - In Combat - Cast Slow");

-- Twilight Idolater
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8419;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8419 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8419,0,0,0,0,0,100,0,0,0,3000,5000,11,9053,64,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Idolater - In Combat - Cast Fireball"),
(8419,0,1,0,0,0,100,0,6000,9000,18000,22000,11,11962,0,0,0,0,0,5,0,0,0,0,0,0,0,"Twilight Idolater - In Combat - Cast Immolate");

-- Highlord Mastrogonde
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8282;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8282 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8282,0,0,0,0,0,100,0,0,0,3000,5000,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Highlord Mastrogonde - In Combat - Cast Shadow Bolt"),
(8282,0,1,0,0,0,100,0,8000,14000,21000,25000,11,11639,0,0,0,0,0,5,0,0,0,0,0,0,0,"Highlord Mastrogonde - In Combat - Cast Shadow Word: Pain"),
(8282,0,2,0,0,0,100,0,6000,9000,15000,18000,11,13323,0,0,0,0,0,6,0,0,0,0,0,0,0,"Highlord Mastrogonde - In Combat - Cast Polymorph"),
(8282,0,3,0,2,0,100,0,0,50,50000,70000,11,11974,0,0,0,0,0,1,0,0,0,0,0,0,0,"Slave Worker - Between 0-50% Health - Cast Power Word: Shield");

-- Slave Master Blackheart
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8283;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8283 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8283,0,0,0,0,0,100,0,0,0,2000,3000,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Slave Master Blackheart - In Combat - Cast Shoot"),
(8283,0,1,0,9,0,100,0,0,20,8000,9000,11,6533,0,0,0,0,0,2,0,0,0,0,0,0,0,"Slave Master Blackheart - Within 0-20 Range - Cast Net");

-- Incendosaur
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=9318;
DELETE FROM `smart_scripts` WHERE `entryorguid`=9318 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(9318,0,0,0,0,0,100,0,5000,9000,12000,16000,11,11985,0,0,0,0,0,2,0,0,0,0,0,0,0,"Incendosaur - In Combat - Cast Fireball");

-- Overseer Maltorius
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=14621;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14621 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14621,0,0,0,0,0,100,0,0,0,3000,5000,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Overseer Maltorius - In Combat - Cast Shadow Bolt"),
(14621,0,1,0,0,0,100,0,4000,12000,16000,22000,11,11639,0,0,0,0,0,5,0,0,0,0,0,0,0,"Overseer Maltorius - In Combat - Cast Shadow Word: Pain"),
(14621,0,2,0,0,0,100,0,6000,9000,13000,16000,11,13323,0,0,0,0,0,6,0,0,0,0,0,0,0,"Overseer Maltorius - In Combat - Cast Polymorph"),
(14621,0,3,0,2,0,100,0,0,50,40000,60000,11,11974,0,0,0,0,0,1,0,0,0,0,0,0,0,"Overseer Maltorius - Between 0-50% Health - Cast Power Word: Shield");

-- Fix bytes2 for some creatures
UPDATE `creature_addon` SET `bytes2`=2 WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` IN (8283,8566));
*/
