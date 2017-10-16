/*
-- Scorpashi Snapper
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4696;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4696 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4696,0,0,0,0,0,100,0,3000,7000,14000,17000,11,5416,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scorpashi Snapper - In Combat - Cast Venom Sting");

-- Scorpashi Lasher
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4697;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4697 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4697,0,0,0,0,0,100,0,3000,7000,14000,17000,11,5416,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scorpashi Lasher - In Combat - Cast Venom Sting");

-- Scorpashi Venomlash
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4699;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4699 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4699,0,0,0,0,0,100,0,3000,7000,14000,17000,11,5416,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scorpashi Venomlash - In Combat - Cast Venom Sting");

-- Dread Swoop
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4692;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4692 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4692,0,0,0,9,0,100,0,0,5,9000,12000,11,5708,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dread Swoop - Within 0-5 Range - Cast Swoop");

-- Dread Flyer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4693;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4693 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4693,0,0,0,0,0,100,0,4000,10000,18000,34000,11,6713,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dread Flyer - In Combat - Cast Disarm");

-- Dread Ripper
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4694;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4694 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4694,0,0,0,9,0,100,0,0,5,15000,18000,11,3147,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dread Ripper - Within 0-5 Range - Cast Rend Flesh");

-- Carrion Horror
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4695;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4695 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4695,0,0,0,0,0,100,0,5000,9000,12000,18000,11,3427,32,0,0,0,0,2,0,0,0,0,0,0,0,"Carrion Horror - In Combat - Cast Infected Wound");

-- Whirlwind Stormwalker
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11577;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11577 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11577,0,0,0,9,0,100,0,0,20,7000,12000,11,11824,0,0,0,0,0,2,0,0,0,0,0,0,0,"Whirlwind Stormwalker - Within 0-20 Range - Cast Shock");

-- Whirlwind Shredder
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11578;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11578 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11578,0,0,0,9,0,100,0,0,5,17000,21000,11,13443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Whirlwind Shredder - Within 0-5 Range - Cast Rend");

-- Raging Thunder Lizard
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4726;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4726 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4726,0,0,0,9,0,100,0,0,30,5000,8000,11,15611,0,0,0,0,0,2,0,0,0,0,0,0,0,"Raging Thunder Lizard - Within 0-30 Range - Cast Lizard Bolt"),
(4726,0,1,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Raging Thunder Lizard - Betwenn 0-30% Health - Cast Enrage (No Repeat)");

-- Elder Thunder Lizard
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4727;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4727 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4727,0,0,0,9,0,100,0,0,30,5000,8000,11,15611,0,0,0,0,0,2,0,0,0,0,0,0,0,"Elder Thunder Lizard - In Combat - Cast Lizard Bolt");

-- Rabid Bonepaw
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4690;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4690 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4690,0,0,0,9,0,100,0,0,5,9000,15000,11,3150,32,0,0,0,0,2,0,0,0,0,0,0,0,"Rabid Bonepaw - Within 0-5 Range - Cast Rabies");

-- Slitherblade Naga
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4711;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4711 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4711,0,0,0,9,0,100,0,0,5,11000,15000,11,7947,0,0,0,0,0,2,0,0,0,0,0,0,0,"Slitherblade Naga - Within 0-5 Range - Cast Localized Toxin");

-- Slitherblade Sorceress
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4712;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4712 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4712,0,0,0,0,0,100,0,0,0,3400,4700,11,32011,64,0,0,0,0,2,0,0,0,0,0,0,0,"Slitherblade Sorceress - In Combat - Cast Water Bolt"),
(4712,0,1,0,1,0,100,0,500,1000,600000,600000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Slitherblade Sorceress - Out of Combat - Cast Frost Armor");

-- Slitherblade Warrior
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4713;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4713 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4713,0,0,0,0,0,100,0,5000,9000,16000,21000,11,7947,32,0,0,0,0,2,0,0,0,0,0,0,0,"Slitherblade Warrior - In Combat - Cast Localized Toxin"),
(4713,0,1,0,9,0,100,0,0,5,12000,17000,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,"Slitherblade Warrior - Within 0-5 Range - Cast Hamstring"),
(4713,0,2,0,0,0,100,0,8000,11000,19000,25000,11,11977,0,0,0,0,0,2,0,0,0,0,0,0,0,"Slitherblade Warrior - In Combat - Cast Rend"),
(4713,0,3,0,11,0,100,0,0,0,0,0,11,7165,0,0,0,0,0,1,0,0,0,0,0,0,0,"Slitherblade Warrior - On Respawn - Cast Battle Stance");

-- Slitherblade Myrmidon
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4714;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4714 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4714,0,0,0,9,0,100,0,0,5,11000,15000,11,7947,0,0,0,0,0,2,0,0,0,0,0,0,0,"Slitherblade Myrmidon - Within 0-5 Range - Cast Localized Toxin");

-- Slitherblade Razortail
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4715;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4715 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4715,0,0,0,9,0,100,0,0,5,11000,15000,11,7947,0,0,0,0,0,2,0,0,0,0,0,0,0,"Slitherblade Razortail - Within 0-5 Range - Cast Localized Toxin");

-- Slitherblade Tidehunter
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4716;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4716 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4716,0,0,0,0,0,100,0,0,0,2300,3900,11,10277,64,0,0,0,0,2,0,0,0,0,0,0,0,"Slitherblade Tidehunter - In Combat CMC - Cast Throw"),
(4716,0,1,0,9,0,100,0,0,5,25000,29000,11,865,0,0,0,0,0,1,0,0,0,0,0,0,0,"Slitherblade Tidehunter - Within 0-5 Range - Cast Frost Nova"),
(4716,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Slitherblade Tidehunter - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Slitherblade Oracle
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4718;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4718 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4718,0,0,0,0,0,100,0,7000,12000,30000,40000,11,5605,0,0,0,0,0,1,0,0,0,0,0,0,0,"Slitherblade Oracle - In Combat - Cast Healing Ward"),
(4718,0,1,0,0,0,100,0,4000,7000,13000,16000,11,11436,0,0,0,0,0,2,0,0,0,0,0,0,0,"Slitherblade Oracle - In Combat - Cast Slow");

-- Slitherblade Sea Witch
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4719;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4719 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4719,0,0,0,1,0,100,0,500,1000,600000,600000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Slitherblade Sea Witch - Out of Combat - Cast Frost Armor"),
(4719,0,1,0,0,0,100,0,5000,9000,16000,24000,11,8427,0,0,0,0,0,2,0,0,0,0,0,0,0,"Slitherblade Sea Witch - In Combat - Cast Blizzard");

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

-- Maraudine Scout
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4654;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4654 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4654,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Maraudine Scout - In Combat - Cast Shoot");

-- Maraudine Wrangler
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4655;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4655 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4655,0,0,0,0,0,100,0,4000,10000,18000,34000,11,6533,0,0,0,0,0,2,0,0,0,0,0,0,0,"Maraudine Wrangler - In Combat - Cast Net"),
(4655,0,1,0,9,0,100,0,0,5,12000,16000,11,8379,0,0,0,0,0,2,0,0,0,0,0,0,0,"Maraudine Wrangler - Within 0-5 Range - Cast Disarm");

-- Maraudine Mauler
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4656;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4656 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4656,0,0,0,0,0,100,0,8000,12000,15000,20000,11,3391,2,0,0,0,0,2,0,0,0,0,0,0,0,"Maraudine Mauler - In Combat - Cast Thrash");

-- Maraudine Windchaser
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4657;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4657 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4657,0,0,0,0,0,100,0,0,0,3400,4800,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Maraudine Windchaser - In Combat CMC - Cast Lightning Bolt"),
(4657,0,1,0,0,0,100,0,7000,11000,15000,18000,11,6728,0,0,0,0,0,5,0,0,0,0,0,0,0,"Maraudine Windchaser - In Combat - Cast Enveloping Winds"),
(4657,0,2,0,14,0,100,0,700,40,17000,21000,11,959,1,0,0,0,0,7,0,0,0,0,0,0,0,"Maraudine Windchaser - Friendly At 700 Health - Cast Healing Wave");

-- Maraudine Stormer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4658;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4658 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4658,0,0,0,0,0,100,0,7000,12000,21000,26000,11,8293,0,0,0,0,0,4,0,0,0,0,0,0,0,"Maraudine Stormer - In Combat - Cast Lightning Cloud"),
(4658,0,1,0,1,0,100,0,1000,1000,600000,600000,11,8788,0,0,0,0,0,1,0,0,0,0,0,0,0,"Maraudine Stormer - Out of Combat - Cast Lightning Shield"),
(4658,0,2,0,16,0,100,0,8788,1,15000,30000,11,8788,0,0,0,0,0,1,0,0,0,0,0,0,0,"Maraudine Stormer - On Friendly Unit Missing Buff Lightning Shield - Cast Lightning Shield"),
(4658,0,3,0,0,0,100,0,0,0,11000,15000,11,9654,0,0,0,0,0,4,0,0,0,0,0,0,0,"Maraudine Stormer - In Combat - Cast Jumping Lightning");

-- Maraudine Marauder
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4659;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4659 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4659,0,0,0,9,0,100,0,0,5,8000,12000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Maraudine Marauder  - Within 0-5 Range - Cast Cleave"),
(4659,0,1,0,4,0,100,1,0,0,0,0,11,7366,0,0,0,0,0,1,0,0,0,0,0,0,0,"Maraudine Marauder - On Aggro - Cast Berserker Stance");

-- Maraudine Priest
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11685;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11685 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11685,0,0,0,9,0,100,0,0,20,7000,10000,11,16568,0,0,0,0,0,2,0,0,0,0,0,0,0,"Maraudine Priest - Within 0-20 Range - Cast Mind Flay"),
(11685,0,1,0,0,0,100,0,7000,12000,21000,25000,11,11639,0,0,0,0,0,5,0,0,0,0,0,0,0,"Maraudine Priest - In Combat - Cast Shadow Word: Pain");

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

-- Drysnap Crawler
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11562;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11562 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11562,0,0,0,1,0,100,0,500,1000,600000,600000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drysnap Crawler - Out of Combat - Cast Frost Armor"),
(11562,0,1,0,9,0,100,0,0,20,7000,12000,11,12548,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drysnap Crawler - Within 0-20 Range - Cast Frost Shock");

-- Drysnap Pincer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11563;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11563 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11563,0,0,0,9,0,100,0,0,5,8000,12000,11,13444,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drysnap Pincer - Within 0-5 Range - Cast Sunder Armor"),
(11563,0,1,0,0,0,100,0,5000,9000,18000,22000,11,13443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drysnap Pincer - In Combat - Cast Rend");

-- Lesser Infernal
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4676;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4676 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4676,0,0,0,0,0,100,0,1000,3000,30000,35000,11,2601,1,0,0,0,0,1,0,0,0,0,0,0,0,"Lesser Infernal - In Combat - Cast Fire Shield III");

-- Nether Maiden
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4679;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4679 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4679,0,0,0,9,0,100,0,0,5,12000,15000,11,7816,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nether Maiden - Within 0-5 Range - Cast Lash of Pain");

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

-- Lord Azrethoc
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5760;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5760 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5760,0,0,0,9,0,100,0,0,5,9000,14000,11,13737,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lord Azrethoc - In Combat - Cast Mortal Strike");

-- Undead Ravager
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11561;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11561 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11561,0,0,0,13,0,100,0,7000,10000,0,0,11,11978,0,0,0,0,0,2,0,0,0,0,0,0,0,"Undead Ravager - Target Casting - Cast Kick");

-- Outcast Necromancer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11559;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11559 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11559,0,0,0,0,0,100,0,0,0,3400,4700,11,20298,64,0,0,0,0,2,0,0,0,0,0,0,0,"Outcast Necromancer - In Combat - Cast Shadow Bolt"),
(11559,0,1,0,0,0,100,1,12000,18000,0,0,11,18166,0,0,0,0,0,1,0,0,0,0,0,0,0,"Outcast Necromancer - In Combat - Cast Summon Magram Ravager (No Repeat)");

-- Khan Jehn
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5601;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5601 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5601,0,0,0,4,0,100,1,0,0,0,0,11,7164,0,0,0,0,0,1,0,0,0,0,0,0,0,"Khan Jehn - On Aggro - Cast Defensive Stance"),
(5601,0,1,0,13,0,100,0,13000,18000,0,0,11,11972,0,0,0,0,0,7,0,0,0,0,0,0,0,"Khan Jehn - Target Casting - Cast Shield Bash"),
(5601,0,2,0,9,0,100,0,0,5,5000,9000,11,8380,0,0,0,0,0,2,0,0,0,0,0,0,0,"Khan Jehn - Within 0-5 Range - Cast Sunder Armor");

-- Magram Scout
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4638;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4638 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4638,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Magram Scout - In Combat - Cast Shoot");

-- Magram Wrangler
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4640;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4640 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4640,0,0,0,9,0,100,0,0,20,18000,24000,11,6533,0,0,0,0,0,2,0,0,0,0,0,0,0,"Magram Wrangler - Within 0-20 Range - Cast Net");

-- Magram Windchaser
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4641;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4641 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4641,0,0,0,0,0,100,0,0,0,3400,4800,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Magram Windchaser - In Combat CMC - Cast Lightning Bolt"),
(4641,0,1,0,14,0,100,0,700,40,17000,21000,11,959,1,0,0,0,0,7,0,0,0,0,0,0,0,"Magram Windchaser - Friendly At 700 Health - Cast Healing Wave");

-- Magram Stormer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4642;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4642 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4642,0,0,0,0,0,100,0,2000,4500,22000,27000,11,6535,0,0,0,0,0,4,0,0,0,0,0,0,0,"Magram Stormer - In Combat - Cast Lightning Cloud"),
(4642,0,1,0,1,0,100,0,500,1000,600000,600000,11,8788,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magram Stormer - Out of Combat - Cast Lightning Shield"),
(4642,0,2,0,16,0,100,0,19514,1,15000,30000,11,8788,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magram Stormer - On Friendly Unit Missing Buff Lightning Shield - Cast Lightning Shield");

-- Magram Marauder
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4644;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4644 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4644,0,0,0,9,0,100,0,0,5,8000,12000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Magram Marauder - Within 0-5 Range - Cast Cleave"),
(4644,0,1,0,4,0,100,1,0,0,0,0,11,7366,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magram Marauder - On Aggro - Cast Berserker Stance");

-- Magram Mauler
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4645;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4645 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4645,0,0,0,0,0,100,0,8000,12000,15000,20000,11,3391,2,0,0,0,0,2,0,0,0,0,0,0,0,"Magram Mauler - In Combat - Cast Thrash");

-- Gelkis Scout
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4647;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4647 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4647,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Gelkis Scout - In Combat CMC - Cast Shoot");

-- Gelkis Stamper
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4648;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4648 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4648,0,0,0,9,0,100,0,0,8,6000,9000,11,5568,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gelkis Stamper - Within 0-8 Range - Cast Trample");

-- Gelkis Windchaser
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4649;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4649 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4649,0,0,0,0,0,100,0,0,0,3400,4800,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Gelkis Windchaser - In Combat CMC - Cast Lightning Bolt"),
(4649,0,1,0,14,0,100,0,700,40,17000,21000,11,959,1,0,0,0,0,7,0,0,0,0,0,0,0,"Gelkis Windchaser - Friendly At 700 Health - Cast Healing Wave");

-- Gelkis Earthcaller
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4651;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4651 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4651,0,0,0,0,0,100,0,0,0,3400,4800,11,20815,64,0,0,0,0,2,0,0,0,0,0,0,0,"Gelkis Earthcaller - In Combat CMC - Cast Fireball"),
(4651,0,1,0,1,0,100,1,1000,1000,0,0,11,9653,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gelkis Earthcaller - Out of Combat - Cast Summon Gelkis Rumbler");

-- Gelkis Mauler
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4652;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4652 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4652,0,0,0,0,0,100,0,8000,12000,15000,20000,11,3391,2,0,0,0,0,2,0,0,0,0,0,0,0,"Gelkis Mauler - In Combat - Cast Thrash");

-- Gelkis Marauder
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4653;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4653 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4653,0,0,0,9,0,100,0,0,5,8000,12000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gelkis Marauder - Within 0-5 Range - Cast Cleave"),
(4653,0,1,0,4,0,100,1,0,0,0,0,11,7366,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gelkis Marauder - On Aggro - Cast Berserker Stance");

-- Remove wrong spawns for Gelkis Rumbler
DELETE FROM `creature` WHERE `guid` IN (27587, 27588, 27589, 27590, 27591, 27592, 27593, 27594, 27595, 27596, 27597, 27598, 27599, 27600);
DELETE FROM `creature_addon` WHERE `guid` IN (27587, 27588, 27589, 27590, 27591, 27592, 27593, 27594, 27595, 27596, 27597, 27598, 27599, 27600);

DELETE FROM `creature_equip_template` WHERE `CreatureID` IN (4663, 4664, 4665, 4666);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `ItemID2`, `ItemID3`, `VerifiedBuild`) VALUES
(4665,1,2559,0,0,0),
(4666,1,5285,5281,0,0),
(4663,1,5303,0,0,0),
(4664,1,4991,0,0,0);
*/
