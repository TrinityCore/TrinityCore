-- Kolkar Scout
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4633;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4633 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4633,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Kolkar Scout - In Combat CMC - Cast Shoot");

-- Kolkar Mauler
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4634;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4634 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4634,0,0,0,0,0,100,0,8000,12000,15000,20000,11,3391,2,0,0,0,0,2,0,0,0,0,0,0,0,"Kolkar Mauler - In Combat - Cast Thrash");

-- Kolkar Windchaser
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4635;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4635 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4635,0,0,0,0,0,100,0,0,0,3400,4800,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Kolkar Windchaser - In Combat CMC - Cast Lightning Bolt"),
(4635,0,1,0,0,0,100,0,7000,11000,15000,18000,11,6728,0,0,0,0,0,5,0,0,0,0,0,0,0,"Kolkar Windchaser - In Combat - Cast Enveloping Winds");

-- Kolkar Battle Lord
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4636;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4636 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4636,0,0,0,0,0,100,0,1000,3000,240000,240000,11,8258,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kolkar Battle Lord - In Combat - Cast Devotion Aura"),
(4636,0,1,0,9,0,100,0,0,5,8000,12000,11,25710,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kolkar Battle Lord - Within 0-5 Range - Cast Heroic Strike"),
(4636,0,2,0,11,0,100,0,0,0,0,0,11,7165,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kolkar Battle Lord - On Respawn - Cast Battle Stance"),
(4636,0,3,0,2,0,100,1,0,20,0,0,39,30,0,0,0,0,0,7,0,0,0,0,0,0,0,"Kolkar Battle Lord - Between 0-20% Health - Call For Help (No Repeat)");

-- Kolkar Destroyer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4637;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4637 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4637,0,0,0,9,0,100,0,0,20,9000,14000,11,11824,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kolkar Destroyer - In Combat - Cast Shock"),
(4637,0,1,0,12,0,100,1,0,20,30000,35000,11,7160,1,0,0,0,0,2,0,0,0,0,0,0,0,"Kolkar Destroyer - Target Between 0-20% Health - Cast Execute");

-- Maraudine Priest
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11685;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11685 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11685,0,0,0,0,0,100,0,7000,12000,21000,25000,11,11639,0,0,0,0,0,5,0,0,0,0,0,0,0,"Maraudine Priest - In Combat - Cast Shadow Word: Pain");

-- Ghostly Marauder
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11687;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11687 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11687,0,0,0,9,0,100,0,0,5,6000,9000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ghostly Marauder - Within 0-5 Range - Cast Strike");

-- Ghostly Raider
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11686;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11686 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11686,0,0,0,0,0,100,0,0,0,2300,3000,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ghostly Raider - In Combat CMC - Cast Shoot"),
(11686,0,1,0,9,0,100,0,5,30,8000,12000,11,17174,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ghostly Raider - Within 5-30 Range - Cast Concussive Shot"),
(11686,0,2,0,9,0,100,0,0,20,5000,9000,11,6533,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ghostly Raider - Within 0-20 Range - Cast Net");

-- Rock Worm
UPDATE `creature_template` SET `AIName`="SmartAI", `unit_class`=2 WHERE `entry`=11788;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11788 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11788,0,0,0,0,0,100,0,0,0,3400,4100,11,9591,64,0,0,0,0,2,0,0,0,0,0,0,0,"Rock Worm - In Combat - Cast Acid Spit");

-- Rock Borer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11787;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11787 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11787,0,0,0,9,0,100,0,0,5,7000,12000,11,14120,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rock Borer - Within 0-5 Range - Cast Tunneler Acid");

-- Lesser Infernal
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4676;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4676 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4676,0,0,0,0,0,100,0,1000,3000,30000,35000,11,2601,1,0,0,0,0,1,0,0,0,0,0,0,0,"Lesser Infernal - In Combat - Cast Fire Shield III");

-- Doomwarder Captain
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4680;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4680 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4680,0,0,0,0,0,100,0,1000,6000,16000,25000,11,6192,2,0,0,0,0,1,0,0,0,0,0,0,0,"Doomwarder Captain - In Combat - Cast Battle Shout"),
(4680,0,1,0,9,0,100,0,0,5,8000,12000,11,3261,32,0,0,0,0,4,0,0,0,0,0,0,0,"Doomwarder Captain - Within 0-5 Range - Cast Ignite");

-- Nether Sister
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4682;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4682 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4682,0,0,0,9,0,100,0,0,5,12000,15000,11,7816,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nether Sister - Within 0-5 Range - Cast Lash of Pain");

-- Nether Sorceress
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4684;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4684 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4684,0,0,0,0,0,100,0,0,0,3400,4700,11,20297,64,0,0,0,0,2,0,0,0,0,0,0,0,"Nether Sorceress - In Combat - Cast Frostbolt"),
(4684,0,1,0,9,0,100,0,0,8,12000,15000,11,11831,1,0,0,0,0,1,0,0,0,0,0,0,0,"Nether Sorceress - Within 0-8 Range - Cast Frost Nova"),
(4684,0,2,0,9,0,100,0,0,5,12000,15000,11,7816,1,0,0,0,0,2,0,0,0,0,0,0,0,"Nether Sorceress - Within 0-5 Range - Cast Lash of Pain");

-- Ley Hunter
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4685;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4685 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4685,0,0,0,9,0,100,0,0,30,9000,15000,11,22189,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ley Hunter - Within 0-30 Range - Cast Mana Burn");

-- Undead Ravager
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11561;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11561 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11561,0,0,0,13,0,100,0,7000,10000,0,0,11,11978,0,0,0,0,0,2,0,0,0,0,0,0,0,"Undead Ravager - Target Casting - Cast Kick");

-- Khan Jehn
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5601;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5601 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5601,0,0,0,4,0,100,1,0,0,0,0,11,7164,0,0,0,0,0,1,0,0,0,0,0,0,0,"Khan Jehn - On Aggro - Cast Defensive Stance"),
(5601,0,1,0,13,0,100,0,13000,18000,0,0,11,11972,0,0,0,0,0,7,0,0,0,0,0,0,0,"Khan Jehn - Target Casting - Cast Shield Bash"),
(5601,0,2,0,9,0,100,0,0,5,5000,9000,11,8380,0,0,0,0,0,2,0,0,0,0,0,0,0,"Khan Jehn - Within 0-5 Range - Cast Sunder Armor");

-- Magram Marauder
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4644;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4644 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4644,0,0,0,9,0,100,0,0,5,8000,12000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Magram Marauder - Within 0-5 Range - Cast Cleave"),
(4644,0,1,0,4,0,100,1,0,0,0,0,11,7366,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magram Marauder - On Aggro - Cast Berserker Stance");

-- Gelkis Scout
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4647;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4647 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4647,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Gelkis Scout - In Combat CMC - Cast Shoot");

-- Gelkis Windchaser
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4649;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4649 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4649,0,0,0,0,0,100,0,0,0,3400,4800,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Gelkis Windchaser - In Combat CMC - Cast Lightning Bolt"),
(4649,0,1,0,14,0,100,0,700,40,17000,21000,11,959,1,0,0,0,0,7,0,0,0,0,0,0,0,"Gelkis Windchaser - Friendly At 700 Health - Cast Healing Wave");

-- Gelkis Mauler
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4652;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4652 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4652,0,0,0,0,0,100,0,8000,12000,15000,20000,11,3391,2,0,0,0,0,2,0,0,0,0,0,0,0,"Gelkis Mauler - In Combat - Cast Thrash");
