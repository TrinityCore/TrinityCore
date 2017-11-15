/*
-- Tyrande Whisperwind
UPDATE `creature_template` SET `AIName`="SmartAI", `flags_extra`=0 WHERE `entry`=7999;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7999 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7999,0,0,0,4,0,100,0,0,0,0,0,4,5885,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tyrande Whisperwind - On Aggro - Play Sound 5885"),
(7999,0,1,0,0,0,100,0,9000,12000,17000,22000,11,20690,0,0,0,0,0,5,0,0,0,0,0,0,0,"Tyrande Whisperwind - In Combat - Cast Moonfire"),
(7999,0,2,0,0,0,100,0,5000,7000,6000,8000,11,20691,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tyrande Whisperwind - In Combat - Cast Cleave"),
(7999,0,3,0,0,0,100,0,11000,14000,9000,12000,11,20688,0,0,0,0,0,5,0,0,0,0,0,0,0,"Tyrande Whisperwind - In Combat - Cast Searing Arrow"),
(7999,0,4,0,0,0,100,0,6000,8000,20000,25000,11,20687,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tyrande Whisperwind - In Combat - Cast Starfall");

-- Arch Druid Fandral Staghelm
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3516;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3516 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3516,0,0,0,0,0,100,0,0,0,2000,3000,11,20698,64,0,0,0,0,2,0,0,0,0,0,0,0,"Arch Druid Fandral Staghelm - In Combat - Cast Wrath"),
(3516,0,1,0,0,0,100,0,3000,5000,25000,35000,11,20702,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arch Druid Fandral Staghelm - In Combat - Cast Summon Treant Allies"),
(3516,0,2,0,0,0,100,0,8000,12000,26000,30000,11,20701,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arch Druid Fandral Staghelm - In Combat - Cast Rejuvenation"),
(3516,0,3,0,0,0,100,0,5000,7000,17000,21000,11,20699,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arch Druid Fandral Staghelm - In Combat - Cast Entangling Roots");

-- King Magni Bronzebeard
DELETE FROM `smart_scripts` WHERE `entryorguid`=2784 AND `source_type`=0 AND `id`>0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2784,0,1,0,4,0,100,0,0,0,0,0,4,5896,0,0,0,0,0,1,0,0,0,0,0,0,0,"King Magni Bronzebeard - On Aggro - Play Sound 5896"),
(2784,0,2,0,0,0,100,0,5000,7000,25000,30000,11,19135,0,0,0,0,0,1,0,0,0,0,0,0,0,"King Magni Bronzebeard - In Combat - Cast Avatar"),
(2784,0,3,0,0,0,100,0,8000,10000,20000,30000,11,20686,0,0,0,0,0,2,0,0,0,0,0,0,0,"King Magni Bronzebeard - In Combat - Cast Knock Away"),
(2784,0,4,0,0,0,100,0,12000,15000,15000,20000,11,20685,0,0,0,0,0,5,0,0,0,0,0,0,0,"King Magni Bronzebeard - In Combat - Cast Storm Bolt");

-- High Tinker Mekkatorque
UPDATE `creature_template` SET `AIName`="SmartAI", `unit_flags`=0 WHERE `entry`=7937;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7937 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7937,0,0,0,4,0,100,0,0,0,0,0,4,5897,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Tinker Mekkatorque - On Aggro - Play Sound 5897"),
(7937,0,1,0,5,0,100,0,0,0,0,0,4,7255,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Tinker Mekkatorque - On Killed Unit - Play Sound 7255"),
(7937,0,2,0,0,0,100,0,3000,5000,15000,18000,11,9143,0,0,0,0,0,5,0,0,0,0,0,0,0,"High Tinker Mekkatorque - In Combat - Cast Bomb"),
(7937,0,3,0,0,0,100,0,9000,11000,16000,19000,11,22739,0,0,0,0,0,2,0,0,0,0,0,0,0,"High Tinker Mekkatorque - In Combat - Cast Goblin Dragon Gun"),
(7937,0,4,0,0,0,100,0,6000,8000,20000,25000,11,22742,0,0,0,0,0,5,0,0,0,0,0,0,0,"High Tinker Mekkatorque - In Combat - Cast Super Shrink Ray");

-- Prophet Velen
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=17468;
DELETE FROM `smart_scripts` WHERE `entryorguid`=17468 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(17468,0,0,0,4,0,100,0,0,0,0,0,4,10154,0,0,0,0,0,1,0,0,0,0,0,0,0,"Prophet Velen - On Aggro - Play Sound 10154"),
(17468,0,1,0,0,0,100,0,0,0,3000,4500,11,59703,64,0,0,0,0,2,0,0,0,0,0,0,0,"Prophet Velen - In Combat - Cast Holy Smite"),
(17468,0,2,0,0,0,100,0,8000,9000,12000,18000,11,59700,0,0,0,0,0,2,0,0,0,0,0,0,0,"Prophet Velen - In Combat - Cast Holy Blast"),
(17468,0,3,0,0,0,100,0,11000,12000,20000,25000,11,59701,0,0,0,0,0,2,0,0,0,0,0,0,0,"Prophet Velen - In Combat - Cast Holy Nova"),
(17468,0,4,0,0,0,100,0,5000,7000,6000,8000,11,33542,0,0,0,0,0,2,0,0,0,0,0,0,0,"Prophet Velen - In Combat - Cast Staff Strike"),
(17468,0,5,0,0,0,100,0,14000,16000,24000,28000,11,59698,0,0,0,0,0,1,0,0,0,0,0,0,0,"Prophet Velen - In Combat - Cast Prayer of Healing");

-- King Varian Wrynn
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=29611;
DELETE FROM `smart_scripts` WHERE `entryorguid`=29611 AND `source_type`=0 AND `id`<2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(29611,0,0,0,0,0,100,0,6000,8000,11000,15000,11,41056,0,0,0,0,0,1,0,0,0,0,0,0,0,"King Varian Wrynn - In Combat - Cast Whirlwind"),
(29611,0,1,0,9,0,100,0,8,25,14000,16000,11,59688,0,0,0,0,0,7,0,0,0,0,0,0,0,"King Varian Wrynn - Within 8-25 Range - Cast Heroic Leap");

-- Lor'themar Theron
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=16802;
DELETE FROM `smart_scripts` WHERE `entryorguid`=16802 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(16802,0,0,0,0,0,100,0,5000,7000,5000,9000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lor'themar Theron - In Combat - Cast Cleave"),
(16802,0,1,0,0,0,100,0,5000,7000,5000,9000,11,59715,0,0,0,0,0,5,0,0,0,0,0,0,0,"Lor'themar Theron - In Combat - Cast Arcane Shock"),
(16802,0,2,0,0,0,100,0,8000,11000,10000,13000,11,33385,0,0,0,0,0,5,0,0,0,0,0,0,0,"Lor'themar Theron - In Combat - Cast Mana Burn"),
(16802,0,3,0,0,0,100,0,22000,24000,44000,48000,11,33384,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lor'themar Theron - In Combat - Cast Mass Charm");

-- Halduron Brightwing
UPDATE `creature_template` SET `AIName`="SmartAI", `DamageModifier`=15 WHERE `entry`=16801;
DELETE FROM `smart_scripts` WHERE `entryorguid`=16801 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(16801,0,0,0,0,0,100,0,5000,7000,5000,7000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,"Halduron Brightwing - In Combat - Cast Cleave"),
(16801,0,1,0,0,0,100,0,0,0,2000,3500,11,20463,64,0,0,0,0,2,0,0,0,0,0,0,0,"Halduron Brightwing - In Combat - Cast Shoot"),
(16801,0,2,0,0,0,100,0,5000,5000,8000,12000,11,21390,0,0,0,0,0,2,0,0,0,0,0,0,0,"Halduron Brightwing - In Combat - Cast Multi-Shot");

-- Grand Magister Rommath
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=16800;
DELETE FROM `smart_scripts` WHERE `entryorguid`=16800 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(16800,0,0,0,0,0,100,0,0,0,3000,5000,11,35915,32,0,0,0,0,1,0,0,0,0,0,0,0,"Grand Magister Rommath - In Combat - Cast Molten Armor"),
(16800,0,1,0,0,0,100,0,0,0,3400,4800,11,33417,64,0,0,0,0,2,0,0,0,0,0,0,0,"Grand Magister Rommath - In Combat - Cast Fireball"),
(16800,0,2,0,0,0,100,0,8000,12000,12000,16000,11,33452,0,0,0,0,0,5,0,0,0,0,0,0,0,"Grand Magister Rommath - In Combat - Cast Flamestrike");

-- Vol'jin
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10540;
DELETE FROM `smart_scripts` WHERE `entryorguid`=10540 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10540,0,0,0,4,0,100,0,0,0,0,0,4,5881,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vol'jin - On Aggro - Play Sound 5881"),
(10540,0,1,0,0,0,100,0,0,0,2000,3500,11,20463,64,0,0,0,0,2,0,0,0,0,0,0,0,"Vol'jin - In Combat - Cast Shoot"),
(10540,0,2,0,0,0,100,0,12000,14000,22000,26000,11,17820,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vol'jin - In Combat - Cast Veil of Shadow"),
(10540,0,3,0,0,0,100,0,3000,5000,14000,16000,11,17146,0,0,0,0,0,5,0,0,0,0,0,0,0,"Vol'jin - In Combat - Cast Shadow Word: Pain"),
(10540,0,4,0,0,0,100,0,6000,8000,8000,12000,11,17289,0,0,0,0,0,5,0,0,0,0,0,0,0,"Vol'jin - In Combat - Cast Shadow Shock"),
(10540,0,5,0,0,0,100,0,8000,12000,18000,22000,11,16097,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vol'jin - In Combat - Cast Hex");

-- Archbishop Benedictus
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1284;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1284 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1284,0,0,0,4,0,100,0,0,0,0,0,4,5883,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archbishop Benedictus - On Aggro - Play Sound 5883"),
(1284,0,1,0,0,0,100,0,0,0,2000,3500,11,20695,64,0,0,0,0,2,0,0,0,0,0,0,0,"Archbishop Benedictus - In Combat - Cast Holy Smite"),
(1284,0,2,0,9,0,100,0,0,8,3000,5000,11,20694,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archbishop Benedictus - In Combat - Cast Holy Nova"),
(1284,0,3,0,0,0,100,0,12000,18000,35000,45000,11,20697,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archbishop Benedictus - In Combat - Cast Power Word: Shield");

-- Lady Jaina Proudmoore
DELETE FROM `smart_scripts` WHERE `entryorguid`=4968 AND `source_type`=0 AND `id`>12;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4968,0,13,0,4,0,100,0,0,0,0,0,4,5882,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Jaina Proudmoore - On Aggro - Play Sound 5882"),
(4968,0,14,0,0,0,100,0,0,0,2000,3500,11,20692,64,0,0,0,0,2,0,0,0,0,0,0,0,"Lady Jaina Proudmoore - In Combat - Fireball"),
(4968,0,15,0,0,0,100,0,4000,5000,45000,55000,11,20681,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Jaina Proudmoore - In Combat - Cast Summon Water Elementals"),
(4968,0,16,0,0,0,100,0,5000,9000,15000,17000,11,20679,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lady Jaina Proudmoore - In Combat - Cast Fire Blast"),
(4968,0,17,0,0,0,100,0,8000,12000,25000,28000,11,20680,0,0,0,0,0,4,0,0,0,0,0,0,0,"Lady Jaina Proudmoore - In Combat - Cast Blizzard"),
(4968,0,18,0,2,0,100,0,0,50,14000,21000,11,20682,1,0,0,0,0,2,0,0,0,0,0,0,0,"Lady Jaina Proudmoore - Between 0-50% Health - Cast Teleport");

DELETE FROM `spell_target_position` WHERE `ID`=20682;
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `VerifiedBuild`) VALUES
(20682,0,1,-3891.8,-4609.97,9.50106,0.764318,0);
*/
