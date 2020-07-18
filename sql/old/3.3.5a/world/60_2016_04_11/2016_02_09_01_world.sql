-- Razorfen Kraul (Update SAI)
-- Razorfen Handler
 
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=4530;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4530;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(4530, 0, 0, 0, 9, 0, 100, 0, 0, 30, 2300, 3900, 11, 6660, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Razorfen Handler - Within 0-30 Range - Cast \'Shoot\'');

-- Razorfen Quilguard

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=4436;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4436 AND `id` IN (1, 2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(4436, 0, 1, 0, 4, 0, 100, 1, 0, 0, 0, 0, 11, 8258, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Razorfen Quilguard - On Aggro - Cast \'Devotion Aura\''),
(4436, 0, 2, 0, 0, 0, 100, 0, 4000, 8000, 12000, 16000, 11, 15548, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Razorfen Quilguard - In Combat - Cast \'Thunderclap\'');

-- Razorfen Geomancer

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=4520;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4520 AND `id` IN (0, 1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(4520, 0, 0, 0, 0, 0, 100, 0, 0, 0, 3400, 4800, 11, 9532, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Razorfen Geomancer - In Combat CMC - Cast \'Lightning Bolt\''),
(4520, 0, 1, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 8270, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Razorfen Geomancer - On Reset - Cast to summon Earth Rumbler');

-- Razorfen Defender

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=4442;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4442 AND `id` IN (0, 1, 2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(4442, 0, 0, 0, 0, 0, 100, 1, 1000, 1000, 180000, 180000, 11, 7164, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Razorfen Defender - In Combat - Cast \'Defensive Stance\''),
(4442, 0, 1, 0, 0, 0, 100, 0, 6000, 11000, 19000, 25000, 11, 11972, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Razorfen Defender - In Combat - Cast \'Shield Bash\''),
(4442, 0, 2, 0, 0, 0, 100, 0, 2000, 5000, 12000, 15000, 11, 3248, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Razorfen Defender - In Combat - Cast \'Improved Blocking\'');

-- Death's Head Adept

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=4516;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4516;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(4516, 0, 0, 0, 0, 0, 100, 2, 0, 0, 2400, 3800, 11, 9672, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Death\'s Head Adept - In Combat CMC - Cast \'Frostbolt\''),
(4516, 0, 1, 0, 0, 0, 100, 2, 3000, 6000, 10000, 15000, 11, 113, 1, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Death\'s Head Adept - In Combat - Cast \'Chains of Ice\' '),
(4516, 0, 2, 0, 2, 0, 100, 3, 0, 15, 0, 0, 25, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Death\'s Head Adept - Between 0-15% Health - Flee For Assist (No Repeat)');

-- Razorfen Groundshaker

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=4523;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4523;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(4523, 0, 0, 0, 0, 0, 100, 0, 7700, 14500, 11000, 26300, 11, 6524, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Razorfen Groundshaker - In Combat - Cast \'Ground Tremor\''),
(4523, 0, 1, 0, 0, 0, 100, 0, 3000, 6000, 10000, 15000, 11, 8046, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Razorfen Groundshaker - In Combat - Cast \'Earth Shock\'');

-- Razorfen Beastmaster

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=4532;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4532;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(4532, 0, 0, 0, 9, 0, 100, 0, 0, 30, 2300, 3900, 11, 6660, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Razorfen Beastmaster - Within 0-30 Range - Cast \'Shoot\''),
(4532, 0, 1, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 8276, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Razorfen Beastmaster - On Reset - Cast to summon Tamed Hyena'),
(4532, 0, 2, 0, 9, 0, 100, 1, 0, 30, 4000, 6000, 11, 8275, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Razorfen Beastmaster - Within 0-30 Range - Cast \'Poisoned Shot\'(No Repeat)');

 -- Razorfen Dustweaver

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=4522;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4522;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(4522, 0, 0, 0, 0, 0, 100, 0, 12000, 12000, 28000, 28000, 11, 6728, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Razorfen Dustweaver - In Combat - Cast \'Enveloping Winds\'');

-- Razorfen Beast Trainer

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=4531;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4531;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(4531, 0, 0, 0, 0, 0, 100, 0, 0, 30, 2300, 3900, 11, 6660, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Razorfen Beast Trainer - Within 0-30 Range - Cast \'Shoot\''),
(4531, 0, 1, 0, 0, 0, 100, 0, 0, 30, 4000, 6000, 11, 6984, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Razorfen Beast Trainer - Within 0-30 Range - Cast \'Frost Shot\'');

-- Aggem Thorncurse <Death's Head Prophet>

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=4424;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4424;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(4424, 0, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 9128, 32, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Aggem Thorncurse - In Combat - Cast \'Battle Shout\''),
(4424, 0, 1, 0, 0, 0, 100, 0, 10000, 10000, 26000, 26000, 11, 8286, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Aggem Thorncurse - In Combat - Cast \'Summon Boar Spirit\'');

-- Razorfen Totemic
 
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=4440;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4440;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(4440, 0, 0, 0, 0, 0, 100, 0, 6000, 6000, 30000, 30000, 11, 4971, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Razorfen Totemic - In Combat - Cast \'Healing Ward\' (No Repeat)'),
(4440, 0, 1, 0, 0, 0, 100, 0, 4000, 4000, 32000, 32000, 11, 8376, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Razorfen Totemic - In Combat - Cast \'Earthgrab Totem\'');

-- Death Speaker Jargba

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=4428;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4428;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(4428, 0, 0, 0, 0, 0, 100, 2, 0, 0, 2400, 3800, 11, 9613, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Death Speaker Jargba - In Combat CMC - Cast \'Shadow Bolt\''),
(4428, 0, 1, 0, 0, 0, 100, 2, 7000, 10000, 10000, 15000, 11, 14515, 1, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 'Death Speaker Jargba - In Combat - Cast \'Dominate Mind\'');

-- Quilguard Champion

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=4623;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4623;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(4623, 0, 0, 0, 4, 0, 100, 1, 0, 0, 0, 0, 11, 8258, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Quilguard Champion - On Aggro - Cast \'Devotion Aura\''),
(4623, 0, 1, 0, 0, 0, 100, 1, 1000, 1000, 180000, 180000, 11, 7164, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Quilguard Champion - In Combat - Cast \'Defensive Stance\''),
(4623, 0, 2, 0, 0, 0, 100, 0, 2000, 10000, 6000, 15000, 11, 15572, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Quilguard Champion - In Combat - Cast \'Sunder Armor\'(No Repeat)');

-- Overlord Ramtusk

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=4420;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4420 AND `id` IN (1, 2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES (4420, 0, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 9128, 32, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overlord Ramtusk - In Combat - Cast \'Battle Shout\''),
(4420, 0, 2, 0, 0, 0, 100, 0, 4000, 8000, 12000, 16000, 11, 15548, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overlord Ramtusk - In Combat - Cast \'Thunderclap\'');

-- Razorfen Earthbreaker

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=4525;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4525;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES (4525, 0, 0, 0, 0, 0, 100, 0, 7700, 14500, 11000, 26300, 11, 8272, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Razorfen Groundshaker - In Combat - Cast \'Mind Tremor\''),
(4525, 0, 1, 0, 0, 0, 100, 0, 3000, 6000, 10000, 15000, 11, 8046, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Razorfen Groundshaker - In Combat - Cast \'Earth Shock\'');

-- Kraul Bat

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=4538;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4538;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(4538, 0, 0, 0, 0, 0, 100, 0, 5000, 8000, 10000, 12000, 11, 12553, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Kraul Bat - In Combat - Cast \'Shock\'');

-- Ward Guardian

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=4427;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4427;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(4427, 0, 0, 0, 14, 0, 100, 0, 500, 40, 10000, 12000, 11, 959, 1, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ward Guardian - Friendly At 500 Health - Cast \'Healing Wave\''),
(4427, 0, 1, 0, 9, 0, 100, 0, 0, 35, 3400, 4800, 11, 8400, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Ward Guardian - Within 0-35 Range - Cast \'Fireball\'');

-- Agathelos the Raging

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=4422;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4422;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(4422, 0, 0, 0, 0, 0, 100, 0, 5000, 8000, 12000, 14000, 11, 8285, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Agathelos the Raging - In Combat - Cast \'Rampage\'');

-- Death's Head Priest

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=4517;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4517;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(4517, 0, 0, 0, 1, 0, 100, 2, 1000, 1000, 1800000, 1800000, 11, 1245, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Death\'s Head Priest - Out of Combat - Cast \'Power Word: Fortitude\''),
(4517, 0, 1, 0, 0, 0, 100, 2, 0, 0, 2400, 3800, 11, 9613, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Death\'s Head Priest - In Combat CMC - Cast \'Shadow Bolt\' (No Repeat)'),
(4517, 0, 2, 0, 2, 0, 100, 2, 0, 40, 14000, 20000, 11, 6063, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Death\'s Head Priest - Between 0-40% Health - Cast \'Heal\' (Normal Dungeon)'),
(4517, 0, 3, 0, 2, 0, 100, 3, 0, 15, 0, 0, 25, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Death\'s Head Priest - Between 0-15% Health - Flee For Assist (No Repeat)');

-- Razorfen Warden

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=4437;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4437;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(4437, 0, 0, 0, 0, 0, 100, 0, 3500, 7500, 20100, 33400, 11, 6533, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Razorfen Warden - In Combat - Cast \'Net\' (No Repeat)');

-- Raging Agam'ar

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=4514;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4514;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(4514, 0, 0, 0, 2, 0, 100, 1, 0, 50, 0, 0, 11, 8269, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Raging Agam\'ar - Between 0-50% Health - Cast \'Frenzy\'');

-- Agam'ar

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=4511;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4511;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(4511, 0, 0, 0, 4, 0, 15, 1, 0, 0, 0, 0, 11, 6268, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Agam\'ar - On Aggro - Cast \'Rushing Charge\' (No Repeat)');

-- Blood of Agamaggan

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=4541;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4541;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(4541, 0, 0, 0, 0, 0, 100, 0, 5000, 9000, 15000, 25000, 11, 8282, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Blood of Agamaggan - In Combat - Cast \'Curse of Blood\'');

-- Roogug

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=6168;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6168;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(6168, 0, 0, 0, 0, 0, 100, 0, 0, 40, 3700, 7500, 11, 9532, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Roogug - In Combat CMC - Cast \'Lightning Bolt\''),
(6168, 0, 1, 0, 0, 0, 100, 0, 0, 30, 6000, 8000, 11, 943, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Roogug - In Combat - Cast \'Lightning Bolt\'');

-- Charlga Razorflank <The Crone> SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=4421;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4421 AND `source_type`=0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(4421, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Charlga Razorflank - On Aggro - Yell Line 0'),
(4421, 0, 1, 0, 5, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Charlga Razorflank - On Killed Unit - Yell Line 1'),
(4421, 0, 2, 0, 2, 0, 100, 1, 0, 75, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Charlga Razorflank - Between 0-75% Health  - Yell Line 2''(No Repeat)'),
(4421, 0, 3, 0, 2, 0, 100, 1, 0, 50, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Charlga Razorflank - Between 0-50% Health  - Yell Line 3''(No Repeat)'),
(4421, 0, 4, 0, 2, 0, 100, 1, 0, 25, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Charlga Razorflank - Between 0-25% Health  - Yell Line 4''(No Repeat)'),
(4421, 0, 5, 0, 0, 0, 100, 0, 0, 0, 78000, 78000, 11, 8361, 32, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Charlga Razorflank - In combat - Cast \'Purity\''),
(4421, 0, 6, 0, 2, 0, 100, 0, 0, 80, 15000, 18000, 11, 6077, 32, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Charlga Razorflank - Between 0-80% Health - Cast \'Renew\''),
(4421, 0, 7, 0, 0, 0, 100, 0, 6000, 6000, 8000, 8000, 11, 8292, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Charlga Razorflank - In Combat - Cast \'Chain Bolt\''),
(4421, 0, 8, 0, 3, 0, 100, 0, 0, 5, 0, 0, 11, 8358, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Charlga Razorflank - Between 0-5% Mana - Cast \'Mana Spike\'');

DELETE FROM `creature_text` WHERE `entry`= 4421 AND `groupid` IN (0, 1, 2, 3, 4);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(4421,0,0,"Troublesome whelps. I'll teach you to interfere!",   14,0,100,0,0,0,6179,3,'Charlga Razorflank - on initial aggro'),
(4421,1,0,"Who's next?",                                        14,0,100,0,0,0,6180,3,'Charlga Razorflank - killing a player'),
(4421,2,0,"You outsiders will pay for encroaching on our land!",14,0,100,0,0,0,6181,3,'Charlga Razorflank - on 75% hp reached'),
(4421,3,0,"Bah! My power rules here!",                          14,0,100,0,0,0,6182,3,'Charlga Razorflank - on 50% hp reached'),
(4421,4,0,"Our new allies will avenge us!",                     14,0,100,0,0,0,6183,3,'Charlga Razorflank - on 25% hp reached');
